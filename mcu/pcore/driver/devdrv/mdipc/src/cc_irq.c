/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cc_irq.c
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This Module defines CC IRQ API(for MD1<->MD3 and PScore<->L1core).
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "kal_general_types.h"
#include "cc_irq_adaptation.h"
#include "ccci_if.h"

#if defined(__PCORE_ONLY__) || defined(__L1CORE_ONLY__)

kal_uint32 cc_irq_param_channel_full(kal_uint32 cc_index) {return 0;}
kal_uint32 cc_irq_buffer_channel_full(kal_uint32 cc_index) {return 0;}
void cc_irq_init() {}
kal_int32 cc_irq_register_callback(kal_uint32 cc_index, CC_IRQ_CALLBACK_P funcp) {return 0;}
kal_int32 cc_irq_trigger_interrupt(kal_uint32 cc_index, kal_uint32 para0, kal_uint32 para1, kal_uint32 para2) {return 0;}
kal_int32 cc_irq_trigger_interrupt_with_buff(kal_uint32 cc_index, void *addr, kal_uint32 data_length) {return 0;}
kal_int32 cc_irq_unmask(kal_uint32 cc_index) {return 0;}
kal_int32 cc_irq_mask(kal_uint32 cc_index) {return 0;}

void cc_irq_md1_md3_shared_mem_config(){}
kal_uint32 cc_irq_get_md1_wakeup_status(){return 0;}

#else

/*****************************************************************************
 * Data Declaration                                                          *
 *****************************************************************************/
DEFINE_NC_SHARED_VAR(CC_IRQ_SHARE_MEM_T, cc_irq_l12ps_share_data) /* Writer: L1core, Reader:PScore */
DEFINE_NC_SHARED_VAR(CC_IRQ_SHARE_MEM_T, cc_irq_ps2l1_share_data) /* Writer: PScore, Reader: L1core*/
/* for debugging */
static CC_IRQ_TRANS_LOG_T    cc_irq_tx_md1_logging[CC_IRQ_TX_MD1_CHANNEL_NUMBER][CC_IRQ_TX_LOGGING_NUMBER];
static CC_IRQ_TRANS_LOG_T    cc_irq_rx_md1_logging[CC_IRQ_RX_MD1_CHANNEL_NUMBER][CC_IRQ_RX_LOGGING_NUMBER];
static kal_uint32            cc_irq_tx_md1_logging_index[CC_IRQ_TX_MD1_CHANNEL_NUMBER];
static kal_uint32            cc_irq_rx_md1_logging_index[CC_IRQ_RX_MD1_CHANNEL_NUMBER];                

static kal_uint32            cc_irq_tx_md1_last_cc_index_offset;
static kal_uint32            cc_irq_rx_md1_last_cc_index_offset;
static kal_uint32            cc_irq_int_done;  

CC_IRQ_ID_T CC_IRQ_ID_T_debugging;/* for debugging use */
MD1_MD3_SHARE_MEMORY_USER MD1_MD3_SHARE_MEMORY_USER_debugging;/* for debugging use */
	
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static CC_IRQ_SHARE_MEM_T      *cc_irq_tx_md1_sharemem_p;/* point to a share memory with another core(write by us, read by the other core), init in cc_irq_init()*/
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static CC_IRQ_SHARE_MEM_T      *cc_irq_rx_md1_sharemem_p;/* point to a share memory with another core(read by us, write by the other core), init in cc_irq_init()*/
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static CC_IRQ_CALLBACK_P       cc_irq_rx_md1_user_callbak[CC_IRQ_RX_MD1_CHANNEL_NUMBER];/* IRQ number --> callback func(called in LISR), CC SYS is cc_sys_comm_lisr() */
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static kal_uint32              cc_irq_rx_md1_index_mapping[CC_IRQ_RX_MD1_CHANNEL_NUMBER];/* input shifted IRQ number(from 0) to get real IRQ ID */

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
#if defined(__PCORE__)/* the share memory address get from AP */
kal_uint32 cc_irq_ps2md3_share_data_addr;/* Writer: PScore, Reader: MD3*/
kal_uint32 cc_irq_md32ps_share_data_addr;/* Writer: MD3, Reader: PScore*/
#elif defined(__L1CORE__)
kal_uint32 cc_irq_l12md3_share_data_addr;/* Writer: L1core, Reader:MD3 */
kal_uint32 cc_irq_md32l1_share_data_addr;/* Writer: MD3, Reader:L1core */
#endif

/* for debugging*/
static CC_IRQ_TRANS_LOG_T    cc_irq_tx_md3_logging[CC_IRQ_TX_MD3_CHANNEL_NUMBER][CC_IRQ_TX_LOGGING_NUMBER];
static CC_IRQ_TRANS_LOG_T    cc_irq_rx_md3_logging[CC_IRQ_RX_MD3_CHANNEL_NUMBER][CC_IRQ_RX_LOGGING_NUMBER];
static kal_uint32            cc_irq_tx_md3_logging_index[CC_IRQ_TX_MD3_CHANNEL_NUMBER];
static kal_uint32            cc_irq_rx_md3_logging_index[CC_IRQ_RX_MD3_CHANNEL_NUMBER];                
         
static kal_uint32 cc_irq_tx_md3_last_cc_index_offset;
static kal_uint32 cc_irq_rx_md3_last_cc_index_offset;

__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static CC_IRQ_MD3_SHARE_MEM_T      *cc_irq_tx_md3_sharemem_p;/* point to a share memory with MD3(write by us, read by MD3), init in cc_irq_init()*/
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static CC_IRQ_MD3_SHARE_MEM_T      *cc_irq_rx_md3_sharemem_p;/* point to a share memory with MD3(read by us, write by MD3), init in cc_irq_init()*/
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static CC_IRQ_CALLBACK_P       cc_irq_rx_md3_user_callbak[CC_IRQ_RX_MD3_CHANNEL_NUMBER];/* IRQ number --> callback func(called in LISR), CC SYS is cc_sys_comm_lisr() */
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static kal_uint32              cc_irq_rx_md3_index_mapping[CC_IRQ_RX_MD3_CHANNEL_NUMBER];/* input shifted IRQ number(from 0) to get real IRQ ID */

#if defined(CC_IRQ_IT)
#define CC_IRQ_MD1_MD3_SHARE_MEM_SIZE_IT 1024*1024*2/* 2M Bytes*/
#define CC_IRQ_MD1_MD3_SHARE_MEM_BASE_IT 0x40000000
#endif

kal_uint32 cc_irq_md1_md3_share_mem_size;/* unit: bytes*/
void * cc_irq_md1_md3_share_mem_base;/* the start address of share memory between MD1 & MD3 */

kal_uint32 cc_irq_md1_md3_user_share_mem_base;/* the start address of "user" share memory between MD1 & MD3 */
CC_IRQ_MD1_MD3_USER_SHARE_MEM_INFO_T cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_END+1];/* the table to manage the MD1/MD3 user share memory */ 

/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/	

#if defined(__PCORE__) && defined(__MTK_TARGET__)
/* Only PScore need to do all the CC IRQ bb Reg dump. In TRACE32, both Pcore & L1core could see the memory dump. */
#include "ex_public.h"
EX_BBREG_DUMP cc_irq_dump;
const kal_uint32 cc_irq_dump_regions[] = {
   L1_BASE_MADDR_L12PS_CCIRQ,   0x1D0, 4,    
   L1_BASE_MADDR_PS2L1_CCIRQ,   0x1D0, 4,
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */   
   BASE_MADDR_PS_C2K_CCIRQ,   0x1D0, 4,    
   BASE_MADDR_C2K_PS_CCIRQ,   0x1D0, 4, 
   BASE_MADDR_L1_C2K_CCIRQ,   0x1D0, 4,    
   BASE_MADDR_C2K_L1_CCIRQ,   0x1D0, 4  
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/	   
};
#endif

/*****************************************************************************
 * Internal Function                                                         *
 *****************************************************************************/
static kal_uint32 cc_irq_get_error_code_1(kal_uint32 cc_index)
{/* convert cc_index to MD1/MD3 error code 1 */

    /* the range of cc_index should be check before calling this function */

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */		
    if(CC_IRQ_TX_TO_MD3(cc_index))
    {/* TX to MD3 */
        return KAL_ERROR_C2K_LONG_TIME_NO_RESPONSE;    
    }   
    else	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* TX to MD1 */
        return KAL_ERROR_INTERCORE_LONG_TIME_NO_RESPONSE;   
    } 
}
 
__attribute__ ((section ("INTSRAM_ROCODE")))
static void cc_irq_enqueue_parameter(kal_uint32 cc_index, kal_uint32 para0, kal_uint32 para1, kal_uint32 para2)
{
    kal_uint32 next_write_index, current_write_index, cc_index_offset, error_code_1;
    CC_IRQ_SHARE_MEM_T *cc_irq_tx_sharemem_ptr;
    register kal_uint32 cc_irq_type __asm__("r7");	

    /* do not check range of cc_index because this should be checked in caller */

    if (cc_irq_param_channel_full(cc_index))
    {
        error_code_1 = cc_irq_get_error_code_1(cc_index);
        kal_fatal_error_handler(error_code_1, CC_IRQ_PEER_NO_RESPONSE_TX);//EXT_ASSERT(0, cc_index, 0, 0);
    }

    cc_irq_type = CC_IRQ_HDR_TYPE_PARA;
    /* para mode only carry 3 parameters and no data in buffer */
	
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    if(CC_IRQ_TX_TO_MD3(cc_index))
    {/* TX to MD3 */
        cc_index_offset = CC_IRQ_TX_MD3_INDEX_OFFSET(cc_index);    
        cc_irq_tx_sharemem_ptr = cc_irq_tx_md3_sharemem_p;	

        /* for debugging */
        cc_irq_tx_md3_last_cc_index_offset = cc_index_offset;
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* TX to MD1 */
        cc_index_offset = CC_IRQ_TX_MD1_INDEX_OFFSET(cc_index);    
        cc_irq_tx_sharemem_ptr = cc_irq_tx_md1_sharemem_p;   

        /* for debugging */
        cc_irq_tx_md1_last_cc_index_offset = cc_index_offset;				
    }

    current_write_index = cc_irq_tx_sharemem_ptr->cc_irq_param_write_index[cc_index_offset];
    next_write_index = (current_write_index + 1) % CC_IRQ_NESTED_TRIGGER_MAX; 

#if 1 /* use STM to reduce EMI transaction count */
    /* we force assign the parameter and Reg to do STM. If we don't assign parameter and Reg, 
    the para0 would be copy to R9, para1 to R8, para2 to R11 by gcc and STM fail!! */
    
    register kal_uint32 reg_para0 __asm__("r8");
    register kal_uint32 reg_para1 __asm__("r9");
    register kal_uint32 reg_para2 __asm__("r10");

    reg_para0 = para0;
    reg_para1 = para1;
    reg_para2 = para2;
	
    /* Write shared parameter */
    __asm__ __volatile__(
        "stmia    %[o], {%[i1], %[i2], %[i3], %[i4]}"
        : \
        : [o]"r" (&(cc_irq_tx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][current_write_index].cc_irq_type)), [i1]"r" (cc_irq_type), [i2]"r" (reg_para0), [i3]"r" (reg_para1), [i4]"r" (reg_para2) 
    );

    /* for debugging*//*
    ASSERT(cc_irq_tx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][current_write_index].cc_irq_type == cc_irq_type);
    ASSERT(cc_irq_tx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][current_write_index].param_0 == para0);
    ASSERT(cc_irq_tx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][current_write_index].param_1 == para1);
    ASSERT(cc_irq_tx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][current_write_index].param_2 == para2);*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
 
    /* ensure write transaction for shared data completes before write transaction for write pointer, or the reader may read invalid data */
    CC_IRQ_DMB();
	
    cc_irq_tx_sharemem_ptr->cc_irq_param_write_index[cc_index_offset] = next_write_index;
	
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    if(CC_IRQ_TX_TO_MD3(cc_index))
    {/* TX to MD3 *//* debugging message */
        cc_irq_tx_md3_logging[cc_index_offset][cc_irq_tx_md3_logging_index[cc_index_offset]].global_ts = CC_IRQ_GET_GLB_TS();
        cc_irq_tx_md3_logging[cc_index_offset][cc_irq_tx_md3_logging_index[cc_index_offset]].cc_irq_type = cc_irq_type;	
        cc_irq_tx_md3_logging[cc_index_offset][cc_irq_tx_md3_logging_index[cc_index_offset]].current_param_index = current_write_index;
        cc_irq_tx_md3_logging_index[cc_index_offset] = (cc_irq_tx_md3_logging_index[cc_index_offset] + 1) % CC_IRQ_TX_LOGGING_NUMBER;	
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* TX to MD1 *//* debugging message */
        cc_irq_tx_md1_logging[cc_index_offset][cc_irq_tx_md1_logging_index[cc_index_offset]].global_ts = CC_IRQ_GET_GLB_TS();
        cc_irq_tx_md1_logging[cc_index_offset][cc_irq_tx_md1_logging_index[cc_index_offset]].cc_irq_type = cc_irq_type;	
        cc_irq_tx_md1_logging[cc_index_offset][cc_irq_tx_md1_logging_index[cc_index_offset]].current_param_index = current_write_index;
        cc_irq_tx_md1_logging_index[cc_index_offset] = (cc_irq_tx_md1_logging_index[cc_index_offset] + 1) % CC_IRQ_TX_LOGGING_NUMBER;
    }		

}

//__attribute__ ((section ("INTSRAM_ROCODE"))) we only put parameter mode in TCM
static void cc_irq_enqueue_buffer(kal_uint32 cc_index, void *addr, kal_uint32 data_length)
{
    kal_uint32 next_write_index, current_write_index, error_code_1;
    register kal_uint32 cc_irq_type __asm__("r7");
    kal_uint32 next_buffer_write_index, current_buffer_write_index, cc_index_offset;	
    CC_IRQ_SHARE_MEM_T *cc_irq_tx_sharemem_ptr;
	
    /* do not check size of data_length and cc_index because these should be checked in caller */

    if (cc_irq_buffer_channel_full(cc_index)||cc_irq_param_channel_full(cc_index))
    {// buffer full
        error_code_1 = cc_irq_get_error_code_1(cc_index);
        kal_fatal_error_handler(error_code_1, CC_IRQ_PEER_NO_RESPONSE_TX);//EXT_ASSERT(0, cc_index, 0, 0);    
    }
	
    cc_irq_type = CC_IRQ_HDR_TYPE_BUFF;
    /* if cc_irq_type is CC_IRQ_HDR_TYPE_BUFF, param_0 is the valid data length of cc_irq_tx_buffer, param_1 & param_2 are no use */

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    if(CC_IRQ_TX_TO_MD3(cc_index))
    {/* TX to MD3 */
        cc_index_offset = CC_IRQ_TX_MD3_INDEX_OFFSET(cc_index);    
        cc_irq_tx_sharemem_ptr = cc_irq_tx_md3_sharemem_p;

        /* for debugging */
        cc_irq_tx_md3_last_cc_index_offset = cc_index_offset;				
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* TX to MD1 */
        cc_index_offset = CC_IRQ_TX_MD1_INDEX_OFFSET(cc_index);    
        cc_irq_tx_sharemem_ptr = cc_irq_tx_md1_sharemem_p;

        /* for debugging */
        cc_irq_tx_md1_last_cc_index_offset = cc_index_offset;			
    }

    /* param index */
    current_write_index = cc_irq_tx_sharemem_ptr->cc_irq_param_write_index[cc_index_offset];
    next_write_index = (current_write_index + 1) % CC_IRQ_NESTED_TRIGGER_MAX;

    /* buffer index */	
    current_buffer_write_index = cc_irq_tx_sharemem_ptr->cc_irq_buffer_write_index[cc_index_offset];
    next_buffer_write_index = (current_buffer_write_index + 1) % CC_IRQ_BUFFER_MODE_BUFF_NUM;

#if 1 /* use STM to reduce EMI transaction count */
    /* We force assign the parameter and Reg to do STM to avoid gcc putting them to error order.*/
    
    register kal_uint32 reg_para0 __asm__("r8");
    reg_para0 = data_length;

    /* Write shared parameter */
	/* if cc_irq_type is CC_IRQ_HDR_TYPE_BUFF, param_0 is the valid data length of cc_irq_tx_buffer, param_1 & param_2 are no use */	
    __asm__ __volatile__(
        "stmia    %[o], {%[i1], %[i2]}"
        : \
        : [o]"r" (&(cc_irq_tx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][current_write_index].cc_irq_type)), [i1]"r" (cc_irq_type), [i2]"r" (reg_para0) 
    );
    /* for debugging*//*
    ASSERT(tx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][current_write_index].cc_irq_type == cc_irq_type);
    ASSERT(tx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][current_write_index].param_0 == data_length);*/

#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
    
    /* copy data to buffer */
    kal_mem_cpy(cc_irq_tx_sharemem_ptr->cc_irq_tx_buffer[cc_index_offset][current_buffer_write_index].buff, addr, data_length);
  
    /* ensure write transaction for shared data completes before write transaction for write pointer, or the reader may read invalid data */
    CC_IRQ_DMB();

    /* update param & buffer index */
    cc_irq_tx_sharemem_ptr->cc_irq_param_write_index[cc_index_offset] = next_write_index;
    cc_irq_tx_sharemem_ptr->cc_irq_buffer_write_index[cc_index_offset] = next_buffer_write_index;

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    if(CC_IRQ_TX_TO_MD3(cc_index))
    {/* TX to MD3 *//* debugging message */
        cc_irq_tx_md3_logging[cc_index_offset][cc_irq_tx_md3_logging_index[cc_index_offset]].global_ts = CC_IRQ_GET_GLB_TS();
        cc_irq_tx_md3_logging[cc_index_offset][cc_irq_tx_md3_logging_index[cc_index_offset]].cc_irq_type = cc_irq_type;	
        cc_irq_tx_md3_logging[cc_index_offset][cc_irq_tx_md3_logging_index[cc_index_offset]].current_param_index = current_write_index;
        cc_irq_tx_md3_logging_index[cc_index_offset] = (cc_irq_tx_md3_logging_index[cc_index_offset] + 1) % CC_IRQ_TX_LOGGING_NUMBER;	
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* TX to MD1 *//* debugging message */
        cc_irq_tx_md1_logging[cc_index_offset][cc_irq_tx_md1_logging_index[cc_index_offset]].global_ts = CC_IRQ_GET_GLB_TS();
        cc_irq_tx_md1_logging[cc_index_offset][cc_irq_tx_md1_logging_index[cc_index_offset]].cc_irq_type = cc_irq_type;	
        cc_irq_tx_md1_logging[cc_index_offset][cc_irq_tx_md1_logging_index[cc_index_offset]].current_param_index = current_write_index;
        cc_irq_tx_md1_logging_index[cc_index_offset] = (cc_irq_tx_md1_logging_index[cc_index_offset] + 1) % CC_IRQ_TX_LOGGING_NUMBER;
    }
}

static void cc_irq_share_para_initialization(CC_IRQ_SHARE_MEM_T *cc_irq_share_mem_str)
{
    kal_uint32 i;
	
    for(i = 0; i < CC_IRQ_MAX_CHANNEL; i++)
    {
        cc_irq_share_mem_str->cc_irq_param_read_index[i] = 0;
        cc_irq_share_mem_str->cc_irq_param_write_index[i] = 0;
        cc_irq_share_mem_str->cc_irq_buffer_read_index[i] = 0;
        cc_irq_share_mem_str->cc_irq_buffer_write_index[i] = 0;			
    }
    
    CC_IRQ_DMB();
}

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
static void cc_irq_init_md1_md3_user_shared_memory_table(kal_uint32 base_addr)
{
    cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_BEGIN].start_addr = base_addr;

    #undef MD1_MD3_CC_USER_SHARE_MEM_REG
    #define MD1_MD3_CC_USER_SHARE_MEM_REG(UserID, Size) cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_##UserID].size = Size;\
    cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_##UserID].start_addr = cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_##UserID-1].start_addr + cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_##UserID-1].size + CC_IRQ_GUARD_PATTERN_LEN;\
    /* we force each user share memory start from 16 bytes aligned address for easy debug */\
    cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_##UserID].start_addr = ((cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_##UserID].start_addr+15)>>4) << 4;\
    cc_irq_fill_guard_pattern(cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_##UserID].start_addr-CC_IRQ_GUARD_PATTERN_LEN);	   
    #include "md1_md3_cc_user_share_mem_config.h" 
    #undef MD1_MD3_CC_USER_SHARE_MEM_REG
#if defined(__PCORE__)/* Only check by PScore due to L1core can't get the cc_irq_md1_md3_share_mem_size.*/
    /* check the total size is over or not */	
    EXT_ASSERT((cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_END].start_addr) <= cc_irq_hw_get_ps2md3_dummy(0) + cc_irq_md1_md3_share_mem_size, cc_irq_md1_md3_user_share_mem_info[CC_SHARE_MEM_END].start_addr, cc_irq_hw_get_ps2md3_dummy(0), cc_irq_md1_md3_share_mem_size);
#endif
}
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

static void cc_irq_default_callback(kal_uint32 para0, kal_uint32 para1, kal_uint32 para2)
{
    ASSERT(0);
    para0 = 0;    
    para1 = 0;
    para2 = 0;
}

#if defined(__PCORE__) && defined(__MTK_TARGET__)
/* Only PScore need to do all the CC IRQ bb Reg dump. In TRACE32, both Pcore & L1core could see the memory dump. */
static void cc_irq_dump_BB_Reg()
{
   /* register bb reg dump */
   cc_irq_dump.regions = (kal_uint32*)cc_irq_dump_regions;
   cc_irq_dump.num = sizeof(cc_irq_dump_regions) / (sizeof(kal_uint32) * 3);
   cc_irq_dump.bbreg_dump_callback = NULL;
   EX_REGISTER_BBREG_DUMP(&cc_irq_dump);
}
#endif 

/*------------------------------------------------------------------------
 * void         cc_irq_lisr
 * Purpose:	The LISR function when receive any CC IRQ interrupt.
 *              "cc_irq_rx_md1_user_callbak" and "cc_irq_rx_md3_user_callbak" which register by user would be called in this function
 *              
 *              
 * Parameters:
 *    Input:	irqx : real IRQ ID
 *    Output:	None
 * returns :	None
 * Note    :    None.
 *------------------------------------------------------------------------
 */
__attribute__ ((section ("INTSRAM_ROCODE")))
void cc_irq_lisr(kal_uint32 irqx)
{
    kal_uint32 cc_index_offset, i, data_cnt = 0, data_length;	
    kal_uint32 param_read_index, param_write_index;
    kal_uint32 buffer_read_index;	
    CC_IRQ_SHARE_MEM_T *cc_irq_rx_sharemem_ptr;
    CC_IRQ_CALLBACK_P  *callback;	
    kal_uint32 buff[CC_IRQ_BUFF_MAX / sizeof(kal_uint32)];/* 60/4=15, 4 bytes*15= 60 bytes */		

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    kal_uint32 rx_from_md3 = 0;
    if(irqx >= CC_IRQ_MD3_IRQ_START_INDEX && irqx < (CC_IRQ_MD3_IRQ_START_INDEX + CC_IRQ_RX_MD3_CHANNEL_NUMBER))
    {/* RX from MD3 */
        /* assume that IRQ ID of CC IRQ aligns CC IRQ index */
        cc_index_offset = (irqx - CC_IRQ_MD3_IRQ_START_INDEX);	
        ASSERT(cc_index_offset < CC_IRQ_RX_MD3_CHANNEL_NUMBER);	

        data_cnt = cc_irq_hw_get_md3_trigger_cnt(cc_index_offset);
		
        cc_irq_rx_sharemem_ptr = cc_irq_rx_md3_sharemem_p;	
        callback = cc_irq_rx_md3_user_callbak;
        rx_from_md3 = 1;

        /* for debugging */
        cc_irq_rx_md3_last_cc_index_offset = cc_index_offset;	
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* RX from MD1 */
        /* assume that IRQ ID of CC IRQ aligns CC IRQ index */
        cc_index_offset = (irqx - CC_IRQ_MD1_IRQ_START_INDEX);	
        ASSERT(cc_index_offset < CC_IRQ_RX_MD1_CHANNEL_NUMBER);	

        data_cnt = cc_irq_hw_get_md1_trigger_cnt(cc_index_offset);
		
        cc_irq_rx_sharemem_ptr = cc_irq_rx_md1_sharemem_p;
        callback = cc_irq_rx_md1_user_callbak;	

        /* for debugging */
        cc_irq_rx_md1_last_cc_index_offset = cc_index_offset;				
    }

    param_read_index = cc_irq_rx_sharemem_ptr->cc_irq_param_read_index[cc_index_offset];/* the index of this IRQ channel we haven't read */  
    param_write_index = cc_irq_rx_sharemem_ptr->cc_irq_param_write_index[cc_index_offset];/* the index of this IRQ channel the other core haven't write */

    EXT_ASSERT(data_cnt !=0, irqx, param_read_index, param_write_index);

    /* get un-processed param cnt */
#if 0 /* this may race condition due to sender update index and then trigger interrupt. We use "data_cnt = *CC_IRQ_CNT_IRQ(cc_index_offset)"*/	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    EXT_ASSERT(param_read_index != param_write_index, irqx, param_read_index, param_write_index);
       
    for(i = 0; i < data_cnt; i++)
    {/* process all data */

       /* get param data (cc_irq_type, para0, para1, para2) */
#if 1 /* use LDM to reduce EMI transaction count */
            register kal_uint32 cc_irq_type __asm__("r1");
            register kal_uint32 para0 __asm__("r2");
            register kal_uint32 para1 __asm__("r3");
            register kal_uint32 para2 __asm__("r4");

            __asm__ __volatile__(
            "ldmia    %[o], {%[i1], %[i2], %[i3], %[i4]}"
            : \
            : [o]"r" (&(cc_irq_rx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][param_read_index].cc_irq_type)), [i1]"r" (cc_irq_type), [i2]"r" (para0), [i3]"r" (para1), [i4]"r" (para2) 
            );
            /* for debugging*//*
            ASSERT(cc_irq_type == rx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][param_read_index].cc_irq_type);            
            ASSERT(para0 == rx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][param_read_index].param_0);
            ASSERT(para1 == rx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][param_read_index].param_1);
            ASSERT(para2 == rx_sharemem_ptr->cc_irq_tx_param[cc_index_offset][param_read_index].param_2);
            */
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
        if(rx_from_md3)
        {/* RX from MD3 *//* debugging message */	
            cc_irq_rx_md3_logging[cc_index_offset][cc_irq_rx_md3_logging_index[cc_index_offset]].global_ts = CC_IRQ_GET_GLB_TS();
            cc_irq_rx_md3_logging[cc_index_offset][cc_irq_rx_md3_logging_index[cc_index_offset]].cc_irq_type = cc_irq_type;	
            cc_irq_rx_md3_logging[cc_index_offset][cc_irq_rx_md3_logging_index[cc_index_offset]].current_param_index = param_read_index;
            cc_irq_rx_md3_logging_index[cc_index_offset] = (cc_irq_rx_md3_logging_index[cc_index_offset] + 1) % CC_IRQ_RX_LOGGING_NUMBER;
        }
        else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
        {/* RX from MD1 *//* debugging message */
            cc_irq_rx_md1_logging[cc_index_offset][cc_irq_rx_md1_logging_index[cc_index_offset]].global_ts = CC_IRQ_GET_GLB_TS();
            cc_irq_rx_md1_logging[cc_index_offset][cc_irq_rx_md1_logging_index[cc_index_offset]].cc_irq_type = cc_irq_type;	
            cc_irq_rx_md1_logging[cc_index_offset][cc_irq_rx_md1_logging_index[cc_index_offset]].current_param_index = param_read_index;
            cc_irq_rx_md1_logging_index[cc_index_offset] = (cc_irq_rx_md1_logging_index[cc_index_offset] + 1) % CC_IRQ_RX_LOGGING_NUMBER;		
        }

        if(cc_irq_type == CC_IRQ_HDR_TYPE_PARA) 
        {
            param_read_index = (param_read_index + 1) % CC_IRQ_NESTED_TRIGGER_MAX;

            /* call user call back func */
            (callback)[cc_index_offset](para0, para1, para2);
        }
        else if(cc_irq_type == CC_IRQ_HDR_TYPE_BUFF) 
        {
            /* if cc_irq_type is CC_IRQ_HDR_TYPE_BUFF, param_0 is the valid data length of cc_irq_tx_buffer, param_1 & param_2 are no use */
            data_length = para0;
            buffer_read_index = cc_irq_rx_sharemem_ptr->cc_irq_buffer_read_index[cc_index_offset]; /* the index of this IRQ channel we haven't read */	
			
            /* copy buffer */
            kal_mem_cpy((void*)buff, cc_irq_rx_sharemem_ptr->cc_irq_tx_buffer[cc_index_offset][buffer_read_index].buff, data_length);
						
            param_read_index = (param_read_index + 1) % CC_IRQ_NESTED_TRIGGER_MAX;
            cc_irq_rx_sharemem_ptr->cc_irq_buffer_read_index[cc_index_offset] = (buffer_read_index + 1) % CC_IRQ_BUFFER_MODE_BUFF_NUM;

            /* call user call back func */			
            (callback)[cc_index_offset]((kal_uint32)buff, data_length, 0);
        } 
        else  
        {
            EXT_ASSERT(0, cc_irq_type, 0, 0);
        }
		
    }
    cc_irq_rx_sharemem_ptr->cc_irq_param_read_index[cc_index_offset] = param_read_index;

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
        if(rx_from_md3)
        {/* RX from MD3 *//* ack */
            cc_irq_hw_ack_md3_irq(cc_index_offset, data_cnt);/* ack the IRQ */       
        }
        else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
        {/* RX from MD1 *//* ack */
            cc_irq_hw_ack_md1_irq(cc_index_offset, data_cnt);/* ack the IRQ */
        }

}

/*****************************************************************************
 * Public Function                                                           *
 *****************************************************************************/
 /*------------------------------------------------------------------------
 * kal_int32    cc_irq_param_channel_full
 * Purpose:	Check the parameter channel of specified CC IRQ index is full or not.
 * Parameters:
 *    Input:	kal_uint32 cc_index: CC_IRQ_ID_XX2XX_T in "global_cc_irq_id.h", TX index of CC IRQ.
 *              
 *    Output:	None
 * returns :	KAL_TRUE/KAL_FALSE
 * Note    :    This function could use for MD1 or MD3.
 *              User should check the return value. 
 *------------------------------------------------------------------------
 */
__attribute__ ((section ("INTSRAM_ROCODE"))) 
kal_uint32 cc_irq_param_channel_full(kal_uint32 cc_index)
{

    kal_uint32 cc_index_offset;
    CC_IRQ_SHARE_MEM_T *cc_irq_tx_sharemem_ptr;
	
    if (!CC_IRQ_TX_INDEX_IS_IN_RANGE(cc_index))
    {
        ASSERT(0);    
        //return CC_IRQ_ERR_PARAM;
    }

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    if(CC_IRQ_TX_TO_MD3(cc_index))
    {/* TX to MD3 */
        cc_index_offset = CC_IRQ_TX_MD3_INDEX_OFFSET(cc_index);	
        cc_irq_tx_sharemem_ptr = cc_irq_tx_md3_sharemem_p; 		
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/	
    {/* check the channel for the other core in MD1*/
        cc_index_offset = CC_IRQ_TX_MD1_INDEX_OFFSET(cc_index);
        cc_irq_tx_sharemem_ptr = cc_irq_tx_md1_sharemem_p;    
    }

	/* for simple buffer design, there is always a free buffer */ 	
    if ((cc_irq_tx_sharemem_ptr->cc_irq_param_write_index[cc_index_offset] + 1) % CC_IRQ_NESTED_TRIGGER_MAX == cc_irq_tx_sharemem_ptr->cc_irq_param_read_index[cc_index_offset])
        return KAL_TRUE;
    else
        return KAL_FALSE;    

}

 /*------------------------------------------------------------------------
 * kal_int32    cc_irq_buffer_channel_full
 * Purpose:	Check the buffer channel of specified CC IRQ index is full or not.
 * Parameters:
 *    Input:	kal_uint32 cc_index: CC_IRQ_ID_XX2XX_T in "global_cc_irq_id.h", TX index of CC IRQ.
 *              
 *    Output:	None
 * returns :	KAL_TRUE/KAL_FALSE
 * Note    :    This function could use for MD1 or MD3.
 *              User should check the return value. 
 *------------------------------------------------------------------------
 */
//__attribute__ ((section ("INTSRAM_ROCODE"))) we only put parameter mode in TCM
kal_uint32 cc_irq_buffer_channel_full(kal_uint32 cc_index)
{

    kal_uint32 cc_index_offset;
    CC_IRQ_SHARE_MEM_T *cc_irq_tx_sharemem_ptr;
	
    if (!CC_IRQ_TX_INDEX_IS_IN_RANGE(cc_index))
    {
        EXT_ASSERT(0 , cc_index, 0, 0);    
        //return CC_IRQ_ERR_PARAM;
    }

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    if(CC_IRQ_TX_TO_MD3(cc_index))
    {/* TX to MD3 */
        cc_index_offset = CC_IRQ_TX_MD3_INDEX_OFFSET(cc_index);	
        cc_irq_tx_sharemem_ptr = cc_irq_tx_md3_sharemem_p; 		
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/	
    {/* check the channel for the other core in MD1*/
        cc_index_offset = CC_IRQ_TX_MD1_INDEX_OFFSET(cc_index);
        cc_irq_tx_sharemem_ptr = cc_irq_tx_md1_sharemem_p;    
    }
	
    if ((cc_irq_tx_sharemem_ptr->cc_irq_buffer_write_index[cc_index_offset] + 1) % CC_IRQ_BUFFER_MODE_BUFF_NUM == cc_irq_tx_sharemem_ptr->cc_irq_buffer_read_index[cc_index_offset])
        return KAL_TRUE;
    else
        return KAL_FALSE;    

}

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	

void cc_irq_fill_guard_pattern(kal_uint32 address)
{
    *(kal_uint32 *)address = CC_IRQ_GUARD_PATTERN_0;/* fill in guard pattern */
    *((kal_uint32 *)address+1) = CC_IRQ_GUARD_PATTERN_1;/* fill in guard pattern */	
    *((kal_uint32 *)address+2) = CC_IRQ_GUARD_PATTERN_0;/* fill in guard pattern */	
    *((kal_uint32 *)address+3) = CC_IRQ_GUARD_PATTERN_1;/* fill in guard pattern */		
}

/*------------------------------------------------------------------------
 * kal_int32    cc_irq_get_md1_md3_user_shared_memory
 * Purpose:	Get a share memory address between MD1 and MD3(for user use).
 * Parameters:
 *    Input:	kal_uint32 user_id- the user index of share memory, the ID(owner) in MD1 & MD3 must be the same.
 *                                   MD1/MD3 use the same ID to get the same address. 
 *              kal_uint32 size- The share memory size user want(used for checking). (unit: bytes, suggest the size to be 4 bytes align.) 
 *
 *    Output:	None
 * returns :	Success: The share memory address user get.
 *              Fail: NULL
 * Note    :    If user want to get user share memory between MD1 and MD3, User should propose the share memory request(the size) to SS team, 
 *              SS team would add a user ID(EX: CC_SHARE_MEM_YYY_XXX) in "md1_md3_cc_user_share_mem_config.h" for user.
 *------------------------------------------------------------------------
 */
kal_uint32 *cc_irq_get_md1_md3_user_shared_memory(kal_uint32 user_id, kal_uint32 size)
{
    kal_uint32 caller_LR;
	
    GET_RETURN_ADDRESS(caller_LR);

    if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
    {    
        kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
    }
	
    if(user_id <= CC_SHARE_MEM_BEGIN || user_id >= CC_SHARE_MEM_END)
    {/* the user ID is not registered */
        EXT_ASSERT(0, user_id, size, 0);
    }

    if(size > cc_irq_md1_md3_user_share_mem_info[user_id].size)
    {/* force user to know the size they can use. The size is too big than registered */
        EXT_ASSERT(0, user_id, size, cc_irq_md1_md3_user_share_mem_info[user_id].size);
    }

    return (kal_uint32 *) cc_irq_md1_md3_user_share_mem_info[user_id].start_addr;
}

/*------------------------------------------------------------------------
 * void         cc_irq_get_md3_wakeup_status
 * Purpose:     Get the CC IRQ wakeup event trigger from MD3  
 *              
 * Parameters:
 *    Input:	None
 *    Output:	None  
 * returns :	the bit mask of CC IRQ wakeup event, one bit per-channel, EX: 0x00000001 means wakeup event from cc_index_offset 0.
 * Note    :    This function only support on JADE(MT6755) and later platform, don't support TK6291.
 *------------------------------------------------------------------------
 */
kal_uint32 cc_irq_get_md3_wakeup_status()
{
    kal_uint32 caller_LR;
    GET_RETURN_ADDRESS(caller_LR);

    if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
    {			
        kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
    } 

#if defined(TK6291)
    return CC_IRQ_INVALID_VALUE;/* means not support */
#else/* only support on JADE(MT6755) and later platform */
    return cc_irq_hw_get_md3_wakeup_status();
#endif	
	
}

/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

/*------------------------------------------------------------------------
 * void         cc_irq_md1_md3_shared_mem_config
 * Purpose:     config the CC IRQ share memory address between MD1 and MD3( dispatch to CC IRQ, CC ILM, CC RPC, user share memory) 
 *              
 * Parameters:
 *    Input:	kal_uint32 start_address: the share memory start address of MD1 and MD3
 *    Output:	None
 * returns :	next_start_address
 * Note    :    This function should be called before cc_irq_init.
 *------------------------------------------------------------------------
 */
void cc_irq_md1_md3_shared_mem_config()
{
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
    kal_uint32 next_start_address;

#if defined(CC_IRQ_IT)
    extern void mpu_set_region_primitive(kal_uint32 index, kal_uint32 addr, kal_uint32 region_size, kal_uint32 attribute, kal_uint32 enable);
    mpu_set_region_primitive( 9, CC_IRQ_MD1_MD3_SHARE_MEM_BASE_IT, 19,  (0x00000300|0x00000001),  1  );	
#endif
	
    if(!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, return directly */
       return;
	
#if defined(__PCORE__)/* the share memory address get from AP */
    kal_uint32 start_address = 0;

#if defined(__HIF_CCCI_SUPPORT__)
    ccci_get_md1md3_shm_info(&cc_irq_md1_md3_share_mem_base, &cc_irq_md1_md3_share_mem_size);/* call CCCI function to get start address and size of share memory between MD1 and MD3 */
    start_address = (kal_uint32) cc_irq_md1_md3_share_mem_base;
#else
    /* If CCCI isn't exist, cc_irq_md1_md3_share_mem_size and start_address would be 0. */
#endif

#if defined(CC_IRQ_IT)
    start_address = CC_IRQ_MD1_MD3_SHARE_MEM_BASE_IT;
    cc_irq_md1_md3_share_mem_size = CC_IRQ_MD1_MD3_SHARE_MEM_SIZE_IT;
#endif

    /* the address get from AP side must be 4 byte aligned and address!=0 and size !=0 */
    EXT_ASSERT((start_address%4==0)&&(start_address!=0)&&(cc_irq_md1_md3_share_mem_size>0), start_address, cc_irq_md1_md3_share_mem_size, 0);

    start_address = start_address + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(start_address-CC_IRQ_GUARD_PATTERN_LEN);
    cc_irq_ps2md3_share_data_addr = start_address;
    cc_irq_md32ps_share_data_addr = cc_irq_ps2md3_share_data_addr + sizeof(CC_IRQ_MD3_SHARE_MEM_T) + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(cc_irq_md32ps_share_data_addr-CC_IRQ_GUARD_PATTERN_LEN);	
    EXT_ASSERT(cc_irq_md32ps_share_data_addr%4==0, cc_irq_md32ps_share_data_addr, 0, 0);

    next_start_address = cc_irq_md32ps_share_data_addr + sizeof(CC_IRQ_MD3_SHARE_MEM_T) + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(next_start_address-CC_IRQ_GUARD_PATTERN_LEN);	

    /* config ILM share memory */	
    next_start_address = cc_irq_msg_share_mem_config(next_start_address);
    /* config RPC share memory */
    next_start_address = cc_irq_rpc_share_mem_config(next_start_address);
	
    /* The "CC_IRQ_MAX_CHANNEL" between MD1 and MD3 are the same, so the size is also the same. */
    cc_irq_md1_md3_user_share_mem_base = start_address + (next_start_address - start_address)*2;

    /* we force each user share memory start from 16 bytes aligned address for easy debug */
    cc_irq_md1_md3_user_share_mem_base = ((cc_irq_md1_md3_user_share_mem_base+15)>>4) << 4;

    /* write to dummy register for delivering to L1core and debugging */	
    cc_irq_hw_write_ps2md3_dummy(0, cc_irq_ps2md3_share_data_addr);
    cc_irq_hw_write_ps2md3_dummy(1, next_start_address);
    cc_irq_hw_write_ps2md3_dummy(2, cc_irq_md1_md3_user_share_mem_base);	

#elif defined(__L1CORE__)/* the share memory address get from PScore */    
    cc_irq_l12md3_share_data_addr = cc_irq_hw_get_ps2md3_dummy(1);
    cc_irq_md32l1_share_data_addr = cc_irq_l12md3_share_data_addr + sizeof(CC_IRQ_MD3_SHARE_MEM_T) + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(cc_irq_md32l1_share_data_addr-CC_IRQ_GUARD_PATTERN_LEN);	
    EXT_ASSERT(cc_irq_md32l1_share_data_addr%4==0, cc_irq_md32l1_share_data_addr, 0, 0);	
	
    next_start_address = cc_irq_md32l1_share_data_addr + sizeof(CC_IRQ_MD3_SHARE_MEM_T) + CC_IRQ_GUARD_PATTERN_LEN;	
    cc_irq_fill_guard_pattern(next_start_address-CC_IRQ_GUARD_PATTERN_LEN);	

    /* config ILM share memory */	
    next_start_address = cc_irq_msg_share_mem_config(next_start_address);
    /* config RPC share memory */
    next_start_address = cc_irq_rpc_share_mem_config(next_start_address);
	
    /* we force each user share memory start from 16 bytes aligned address for easy debug */
    cc_irq_md1_md3_user_share_mem_base = ((next_start_address+15)>>4) << 4;
	
    EXT_ASSERT(cc_irq_md1_md3_user_share_mem_base == cc_irq_hw_get_ps2md3_dummy(2), cc_irq_md1_md3_user_share_mem_base, cc_irq_hw_get_ps2md3_dummy(2), 0);
#endif

    cc_irq_init_md1_md3_user_shared_memory_table(cc_irq_md1_md3_user_share_mem_base);
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
}

/*------------------------------------------------------------------------
 * void         cc_irq_init
 * Purpose:     1. initialize Pcore<->L1core and MD1<->MD3 CC IRQ share memory pointer and parameters( include cc_index and IRQ ID mapping), 
 *              2. register user call back function(would be called in LISR) to default
 *              3. init CC SYS
 *              
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	None
 * Note    :    Called in HWDInitialization.
 *------------------------------------------------------------------------
 */   
void cc_irq_init()
{
    kal_uint32 i;

    //- TX side init the share buffer
#ifdef __PCORE__
    SHARED_VAR(cc_irq_ps2l1_share_data).prefix = CC_IRQ_SHARE_DATA_PS2L1_PREFIX;
    SHARED_VAR(cc_irq_ps2l1_share_data).postfix = CC_IRQ_SHARE_DATA_PS2L1_POSTFIX;
    cc_irq_share_para_initialization(SHARED_pVAR(cc_irq_ps2l1_share_data));
    cc_irq_rx_md1_sharemem_p = SHARED_pVAR(cc_irq_l12ps_share_data);
    cc_irq_tx_md1_sharemem_p = SHARED_pVAR(cc_irq_ps2l1_share_data);
#else
    SHARED_VAR(cc_irq_l12ps_share_data).prefix = CC_IRQ_SHARE_DATA_L12PS_PREFIX;
    SHARED_VAR(cc_irq_l12ps_share_data).postfix = CC_IRQ_SHARE_DATA_L12PS_POSTFIX;
    cc_irq_share_para_initialization(SHARED_pVAR(cc_irq_l12ps_share_data));
    cc_irq_rx_md1_sharemem_p = SHARED_pVAR(cc_irq_ps2l1_share_data);
    cc_irq_tx_md1_sharemem_p = SHARED_pVAR(cc_irq_l12ps_share_data);
#endif

    //- initialize user callback
    for(i = 0; i < CC_IRQ_RX_MD1_CHANNEL_NUMBER; i++)
    {/* register user call back function(would be called in LISR) to default and channel number mapping to real IRQ ID */
        cc_irq_rx_md1_user_callbak[i] = cc_irq_default_callback;
        cc_irq_rx_md1_index_mapping[i] = CC_IRQ_MD1_IRQ_START_INDEX + i;
    }

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
    if(CC_IRQ_MD3_IS_EXIST())/* only init MD3 parameters when MD3 exist */
    {
        //- TX side init the share buffer
    #if defined(__PCORE__)
        cc_irq_rx_md3_sharemem_p = (CC_IRQ_MD3_SHARE_MEM_T *)cc_irq_md32ps_share_data_addr;
        cc_irq_tx_md3_sharemem_p = (CC_IRQ_MD3_SHARE_MEM_T *)cc_irq_ps2md3_share_data_addr;

        /* AP should clear the MD1 and MD3 share memory to 0, we check it before we write guard pattern. */
        EXT_ASSERT(cc_irq_tx_md3_sharemem_p->prefix == 0, cc_irq_tx_md3_sharemem_p->prefix, 0, 0); 
        EXT_ASSERT(cc_irq_tx_md3_sharemem_p->postfix == 0, cc_irq_tx_md3_sharemem_p->postfix, 0, 0); 		
		
        cc_irq_tx_md3_sharemem_p->prefix = CC_IRQ_SHARE_DATA_PS2MD3_PREFIX;
        cc_irq_tx_md3_sharemem_p->postfix = CC_IRQ_SHARE_DATA_PS2MD3_POSTFIX;
        cc_irq_share_para_initialization(cc_irq_tx_md3_sharemem_p);
    
    #elif defined(__L1CORE__)	
        cc_irq_rx_md3_sharemem_p = (CC_IRQ_MD3_SHARE_MEM_T *)cc_irq_md32l1_share_data_addr;
        cc_irq_tx_md3_sharemem_p = (CC_IRQ_MD3_SHARE_MEM_T *)cc_irq_l12md3_share_data_addr;

        /* AP should clear the MD1 and MD3 share memory to 0, we check it before we write guard pattern. */
        EXT_ASSERT(cc_irq_tx_md3_sharemem_p->prefix == 0, cc_irq_tx_md3_sharemem_p->prefix, 0, 0); 
        EXT_ASSERT(cc_irq_tx_md3_sharemem_p->postfix == 0, cc_irq_tx_md3_sharemem_p->postfix, 0, 0); 
    
        cc_irq_tx_md3_sharemem_p->prefix = CC_IRQ_SHARE_DATA_L12MD3_PREFIX;
        cc_irq_tx_md3_sharemem_p->postfix = CC_IRQ_SHARE_DATA_L12MD3_POSTFIX;
        cc_irq_share_para_initialization(cc_irq_tx_md3_sharemem_p);
    #endif
    
        //- initialize user callback
        for(i = 0; i < CC_IRQ_RX_MD3_CHANNEL_NUMBER; i++)
        {
            cc_irq_rx_md3_user_callbak[i] = cc_irq_default_callback;
            cc_irq_rx_md3_index_mapping[i] = CC_IRQ_MD3_IRQ_START_INDEX + i;
        }
    }	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/	

    cc_irq_int_done = KAL_TRUE;

#if defined(__PCORE__) && defined(__MTK_TARGET__)
/* Only PScore need to do all the CC IRQ bb Reg dump. In TRACE32, both Pcore & L1core could see the memory dump. */
    cc_irq_dump_BB_Reg();
#endif

    cc_sys_comm_init();
}

/*------------------------------------------------------------------------
 * kal_int32    cc_irq_register_callback
 * Purpose:	Register callback function when specified CC IRQ is triggered. 
 * Parameters:
 *    Input:	kal_uint32 cc_index: CC_IRQ_ID_XX2XX_T in "global_cc_irq_id.h", RX index of CC IRQ.
 *              CC_IRQ_CALLBACK_P funcp: callback function when specified CC IRQ index is triggered.(would be called in LISR)
 *    Output:	None
 * returns :	CC_IRQ_SUCCESS/CC_IRQ_ERR_PARAM
 * Note    :    This function could register CC IRQ call back function for MD1 or MD3.
 *              Multiple registration to the same index is allowed. The callback function will be the last registered one.
 *              User should check the return value.
 *              This function could register call back function for specified comm_id of CC SYS IRQ for MD1 or MD3. 
 *------------------------------------------------------------------------
 */
kal_int32 cc_irq_register_callback(kal_uint32 cc_index, CC_IRQ_CALLBACK_P funcp)
{

    kal_uint32 cc_index_offset;
	
    if (NULL == funcp || !CC_IRQ_RX_INDEX_IS_IN_RANGE(cc_index))
        return CC_IRQ_ERR_PARAM;

    if (cc_irq_int_done == KAL_FALSE)
        EXT_ASSERT(0, cc_index, (kal_uint32)funcp, 0);

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    kal_uint32 caller_LR;

    GET_RETURN_ADDRESS(caller_LR);

    if(CC_IRQ_RX_FROM_MD3(cc_index))
    {/* RX from MD3 */
        if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
        {       
            kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
        }
	
        cc_index_offset = CC_IRQ_RX_MD3_INDEX_OFFSET(cc_index);
        //- 1st registration. Set IRQ Configuration.		
        if(cc_irq_rx_md3_user_callbak[cc_index_offset] == cc_irq_default_callback)
        {/* come here when first register */
            IRQ_Register_LISR(cc_irq_rx_md3_index_mapping[cc_index_offset], cc_irq_lisr, "CC_IRQ");
            CC_IRQ_SET_SENSITIVITY_LEVEL(cc_irq_rx_md3_index_mapping[cc_index_offset]);/* level trigger */ 
        }
		
        cc_irq_rx_md3_user_callbak[cc_index_offset] = funcp;  	
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    { /* RX from MD1*/
        cc_index_offset = CC_IRQ_RX_MD1_INDEX_OFFSET(cc_index);
        //- 1st registration. Set IRQ Configuration.
        if(cc_irq_rx_md1_user_callbak[cc_index_offset] == cc_irq_default_callback)
        {/* come here when first register */
            IRQ_Register_LISR(cc_irq_rx_md1_index_mapping[cc_index_offset], cc_irq_lisr, "CC_IRQ");
            CC_IRQ_SET_SENSITIVITY_LEVEL(cc_irq_rx_md1_index_mapping[cc_index_offset]);/* level trigger */ 
        }

        cc_irq_rx_md1_user_callbak[cc_index_offset] = funcp;    
    }
        
    return CC_IRQ_SUCCESS;
}

/*------------------------------------------------------------------------
 * kal_int32    cc_irq_trigger_interrupt
 * Purpose:	Trigger CC IRQ interrupt to MD1 or MD3 and send 3 parameter to the receiver core.
 * Parameters:
 *    Input:	kal_uint32 cc_index: CC_IRQ_ID_XX2XX_T in "global_cc_irq_id.h", TX index of CC IRQ.
 *              kal_uint32 para0~para2: Parameters to another core.
 *    Output:	None
 * returns :	CC_IRQ_SUCCESS
 *              CC_IRQ_ERR_PEER_ASYNC: PEER is not synchronized. It means MD1/MD3 is in EPOF, CC IRQ could not service, user must handle following action by themselves.
 * Note    :    This function could trigger interrupt to MD1 or MD3
 *              User should check the return value.
 *------------------------------------------------------------------------
 */
__attribute__ ((section ("INTSRAM_ROCODE")))
kal_int32 cc_irq_trigger_interrupt(kal_uint32 cc_index, kal_uint32 para0, kal_uint32 para1, kal_uint32 para2)
{
    kal_uint32 savedMask, cc_index_offset;

    if (cc_irq_int_done == KAL_FALSE)
        EXT_ASSERT(0, cc_index, para0, para1);

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
    kal_uint32 caller_LR;
    GET_RETURN_ADDRESS(caller_LR);
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

    if (!CC_IRQ_TX_INDEX_IS_IN_RANGE(cc_index))
    {
        EXT_ASSERT(0, cc_index, para0, para1);    
        //return CC_IRQ_ERR_PARAM;    
    }
    
    /* avoid race condition that two thread updata data for one channel */
    CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
    if(CC_IRQ_TX_TO_MD3(cc_index))
    {/* TX to MD3 */ 
        if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
        {
            CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
            kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
        }    
	
        if (cc_irq_sync_get_cc_irq_tx_md3_status() != KAL_TRUE)/* we should check MD3's status before TX */
        {
            CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
            return CC_IRQ_ERR_PEER_ASYNC;
        }

        cc_irq_enqueue_parameter(cc_index, para0, para1, para2);

        cc_index_offset = CC_IRQ_TX_MD3_INDEX_OFFSET(cc_index);		
        cc_irq_hw_trigger_md3_irq(cc_index_offset);	
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    { /* TX to MD1*/  
    
        /* we should check MD1's status before TX */
        if (cc_irq_sync_get_cc_irq_tx_md1_status() != KAL_TRUE)
        {
            CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
    #if 1
            return CC_IRQ_ERR_PEER_ASYNC;
    #else
/* under construction !*/
/* under construction !*/
    #endif
        }

        cc_irq_enqueue_parameter(cc_index, para0, para1, para2);

        cc_index_offset = CC_IRQ_TX_MD1_INDEX_OFFSET(cc_index);		
		
        cc_irq_hw_trigger_md1_irq(cc_index_offset);

    } 
    
    CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);

    return CC_IRQ_SUCCESS;
}

/*------------------------------------------------------------------------
 * kal_int32    cc_irq_trigger_interrupt_with_buff
 * Purpose:	Trigger CC IRQ interrupt to MD1 or MD3 and copy buffer to the receiver core.
 * Parameters:
 *    Input:	kal_uint32 cc_index: CC_IRQ_ID_XX2XX_T in "global_cc_irq_id.h", TX index of CC IRQ.
 *              void *addr: Starting address of buffer data.
 *              kal_uint32 data_length: data length. 
 *    Output:	None
 * returns :	CC_IRQ_SUCCESS
 *              CC_IRQ_ERR_PEER_ASYNC: PEER is not synchronized. It means MD1/MD3 is in EPOF, CC IRQ could not service, user must handle following action by themselves. 
 * Note    :    This function could trigger interrupt to MD1 or MD3 and copy buffer to the receiver core.
 *              User should check the return value. 
 *              The data length is limited by "CC_IRQ_BUFF_MAX". 
 *------------------------------------------------------------------------
 */
//__attribute__ ((section ("INTSRAM_ROCODE")))  we only put parameter mode in TCM
kal_int32 cc_irq_trigger_interrupt_with_buff(kal_uint32 cc_index, void *addr, kal_uint32 data_length)
{
    kal_uint32 savedMask, cc_index_offset;

    if (cc_irq_int_done == KAL_FALSE)
        EXT_ASSERT(0, cc_index, data_length, 0);

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    kal_uint32 caller_LR;
    GET_RETURN_ADDRESS(caller_LR);
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

    if (!CC_IRQ_TX_INDEX_IS_IN_RANGE(cc_index) || data_length > CC_IRQ_BUFF_MAX)
    {
        EXT_ASSERT(0, cc_index, data_length, 0);    
        //return CC_IRQ_ERR_PARAM;    
    }
	
    /* avoid race condition that two thread updata data for one channel */
    CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);
	
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    if(CC_IRQ_TX_TO_MD3(cc_index))
    {/* TX to MD3 */
        if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
        {
            CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);			
            kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
        } 
	
        if (cc_irq_sync_get_cc_irq_tx_md3_status() != KAL_TRUE)/* we should check MD3's status before TX */
        {
            CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
            return CC_IRQ_ERR_PEER_ASYNC;
        }

        cc_irq_enqueue_buffer(cc_index, addr, data_length);	
		
        cc_index_offset = CC_IRQ_TX_MD3_INDEX_OFFSET(cc_index);
        cc_irq_hw_trigger_md3_irq(cc_index_offset);	
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    { /* TX to MD1*/    

        /* we should check MD1's status before TX */
        if (cc_irq_sync_get_cc_irq_tx_md1_status() != KAL_TRUE)
        {
            CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
    #if 1
            return CC_IRQ_ERR_PEER_ASYNC;	
    #else	
/* under construction !*/
/* under construction !*/
    #endif	
        }

        cc_irq_enqueue_buffer(cc_index, addr, data_length);	
		
        cc_index_offset = CC_IRQ_TX_MD1_INDEX_OFFSET(cc_index);		
        cc_irq_hw_trigger_md1_irq(cc_index_offset);		
    }     
    
    CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
    
    return CC_IRQ_SUCCESS;
}

/*------------------------------------------------------------------------
 * kal_int32    cc_irq_unmask
 * Purpose:	Unmask CC IRQ.
 * Parameters:
 *    Input:	kal_uint32 cc_index: CC_IRQ_ID_XX2XX_T in "global_cc_irq_id.h", RX index of CC IRQ.
 *
 *    Output:	None
 * returns :	CC_IRQ_SUCCESS
 * Note    :    User should check the return value.
 *              This function could unmask CC IRQ from MD1 or MD3.
 *------------------------------------------------------------------------
 */
kal_int32 cc_irq_unmask(kal_uint32 cc_index)
{
    kal_uint32 cc_index_offset;

    if (!CC_IRQ_RX_INDEX_IS_IN_RANGE(cc_index))
    {
        EXT_ASSERT(0 , cc_index, 0, 0);    
        //return CC_IRQ_ERR_PARAM;
    }		

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    if(CC_IRQ_RX_FROM_MD3(cc_index))
    {/* unmask MD3 IRQ */
        cc_index_offset = CC_IRQ_RX_MD3_INDEX_OFFSET(cc_index);
        CC_IRQ_DRV_UNMASK(cc_irq_rx_md3_index_mapping[cc_index_offset]);		
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    { /* unmask MD1 IRQ*/ 
        cc_index_offset = CC_IRQ_RX_MD1_INDEX_OFFSET(cc_index);    
        CC_IRQ_DRV_UNMASK(cc_irq_rx_md1_index_mapping[cc_index_offset]);
    }  

    return CC_IRQ_SUCCESS;
}

/*------------------------------------------------------------------------
 * kal_int32    cc_irq_mask
 * Purpose:	mask CC IRQ.
 * Parameters:
 *    Input:	kal_uint32 cc_index: CC_IRQ_ID_XX2XX_T in "global_cc_irq_id.h", RX index of CC IRQ.
 *
 *    Output:	None
 * returns :	CC_IRQ_SUCCESS
 * Note    :    User should check the return value.
 *              This function could mask CC IRQ from MD1 or MD3. 
 *------------------------------------------------------------------------
 */
kal_int32 cc_irq_mask(kal_uint32 cc_index)
{
    kal_uint32 cc_index_offset;
	
    if (!CC_IRQ_RX_INDEX_IS_IN_RANGE(cc_index))
    {
        EXT_ASSERT(0 , cc_index, 0, 0);    
        //return CC_IRQ_ERR_PARAM;
    }

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    if(CC_IRQ_RX_FROM_MD3(cc_index))
    {/* mask MD3 IRQ */
        cc_index_offset = CC_IRQ_RX_MD3_INDEX_OFFSET(cc_index);
        CC_IRQ_DRV_MASK(cc_irq_rx_md3_index_mapping[cc_index_offset]);		
    }
    else
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    { /* mask MD1 IRQ*/
        cc_index_offset = CC_IRQ_RX_MD1_INDEX_OFFSET(cc_index);    
        CC_IRQ_DRV_MASK(cc_irq_rx_md1_index_mapping[cc_index_offset]);
    }

    return CC_IRQ_SUCCESS;
}

/*------------------------------------------------------------------------
 * void         cc_irq_get_md1_wakeup_status
 * Purpose:     Get the CC IRQ wakeup event trigger from MD1  
 *              
 * Parameters:
 *    Input:	None
 *    Output:	None  
 * returns :	the bit mask of CC IRQ wakeup event, one bit per-channel, EX: 0x00000001 means wakeup event from cc_index_offset 0.
 * Note    :    This function only support on JADE(MT6755) and later platform, don't support TK6291.
 *------------------------------------------------------------------------
 */
kal_uint32 cc_irq_get_md1_wakeup_status()
{
#if defined(TK6291)
    return CC_IRQ_INVALID_VALUE;/* means not support */
#else/* only support on JADE(MT6755) and later platform */
    return cc_irq_hw_get_md1_wakeup_status();
#endif  
}

#endif /* defined(__PCORE_ONLY__) || defined(__L1CORE_ONLY__) */
