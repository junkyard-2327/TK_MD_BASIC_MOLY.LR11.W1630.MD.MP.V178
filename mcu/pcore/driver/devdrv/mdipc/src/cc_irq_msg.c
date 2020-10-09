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
 *   cc_irq_msg.c
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This Module defines CC IRQ Message-Passing API(only for MD1<->MD3 ILM passing).
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

#include "cc_irq_adaptation.h"
#include "dhl_trace.h"
#include "cc_irq_trace.h"

/* This file only support MD3 */
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	

#define CC_IRQ_MSG_TX_MD3_TIMEOUT  (10000UL)    /* 10ms */
#define CC_IRQ_MSG_MD1_MD3_BUFFER_NUMBER     16
#define CC_IRQ_MSG_MD1_MD3_ILM_PARA_SIZE     4096
	
typedef struct {
    kal_uint32     valid;                             
    ilm_struct     ilm;                                                          	
    kal_uint32     local_para_buffer[CC_IRQ_MSG_MD1_MD3_ILM_PARA_SIZE/sizeof(kal_uint32)];/* 4096/4=1024, 4 bytes*1024= 4096 bytes */                                                          	                                                                                      
} CC_IRQ_MSG_MD1_MD3_BUFFER_T;		

#define CC_IRQ_MSG_MD1_MD3_SHARE_MEM_SIZE    (sizeof(CC_IRQ_MSG_MD1_MD3_BUFFER_T)*CC_IRQ_MSG_MD1_MD3_BUFFER_NUMBER)

/* for MD3 */
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static CC_IRQ_MSG_MD1_MD3_BUFFER_T      *cc_irq_msg_rx_md3_sharemem_p[CC_IRQ_MSG_MD1_MD3_BUFFER_NUMBER];
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static CC_IRQ_MSG_MD1_MD3_BUFFER_T      *cc_irq_msg_tx_md3_sharemem_p[CC_IRQ_MSG_MD1_MD3_BUFFER_NUMBER];
#if defined(__PCORE__)
kal_uint32 cc_irq_msg_ps2md3_share_data_addr;
kal_uint32 cc_irq_msg_md32ps_share_data_addr;
kal_uint32 const cc_irq_msg_tx_md3_cc_sys_comm = CC_SYS_COMM_P2MD3_MSG;	
kal_uint32 const cc_irq_msg_rx_md3_cc_sys_comm = CC_SYS_COMM_MD32P_MSG;
#else
kal_uint32 cc_irq_msg_l12md3_share_data_addr;
kal_uint32 cc_irq_msg_md32l1_share_data_addr;
kal_uint32 const cc_irq_msg_tx_md3_cc_sys_comm = CC_SYS_COMM_L2MD3_MSG;	
kal_uint32 const cc_irq_msg_rx_md3_cc_sys_comm = CC_SYS_COMM_MD32L_MSG;
#endif


/*****************************************************************************
 * Internal Function                                                         *
 *****************************************************************************/
/*------------------------------------------------------------------------
 * void cc_irq_msg_hisr
 * Purpose:		The HISR function when receiving a ILM from MD3, 
 *              the ISR flow is cc_irq_lisr(kal_uint32 irqx)-->cc_sys_comm_lisr()-->cc_sys_comm_hisr()-->cc_irq_msg_hisr()
 * Parameters:
 *    Input:	
 *              kal_uint32 ilm_buffer_index: The index of received ILM in CC_IRQ_MSG_MD1_MD3_BUFFER_T.
 *              kal_uint32 msg_len: The data length of ILM. It would be 0 if there is no local parameter. 
 *    Output:	None
 * returns :	None
 * Note    :    This function is running in HISR.
 *------------------------------------------------------------------------
 */
void cc_irq_msg_hisr(kal_uint32 cc_irq_msg_buffer_index, kal_uint32 msg_len)
{
    //kal_uint32  savedMask;
	ilm_struct  rx_ilm;

    EXT_ASSERT(cc_irq_msg_buffer_index < CC_IRQ_MSG_MD1_MD3_BUFFER_NUMBER, cc_irq_msg_buffer_index, msg_len, 0);
    EXT_ASSERT(cc_irq_msg_rx_md3_sharemem_p[cc_irq_msg_buffer_index]->valid == 1, cc_irq_msg_buffer_index, msg_len, 0);	

    /* these parameters should be NULL due to they are meaningless from the other core */ 
    EXT_ASSERT(cc_irq_msg_rx_md3_sharemem_p[cc_irq_msg_buffer_index]->ilm.local_para_ptr == NULL, cc_irq_msg_buffer_index, msg_len, 0);
    EXT_ASSERT(cc_irq_msg_rx_md3_sharemem_p[cc_irq_msg_buffer_index]->ilm.peer_buff_ptr == NULL, cc_irq_msg_buffer_index, msg_len, 0);	
	
    rx_ilm = cc_irq_msg_rx_md3_sharemem_p[cc_irq_msg_buffer_index]->ilm;
    if(msg_len > 0)
    {
        rx_ilm.local_para_ptr = (local_para_struct *)construct_local_para(msg_len, TD_RESET);
        kal_mem_cpy((void*)(rx_ilm.local_para_ptr), (void*)cc_irq_msg_rx_md3_sharemem_p[cc_irq_msg_buffer_index]->local_para_buffer, msg_len);
    }

    /* free msg buffer *//* no need to disable IRQ due to HISR wouldn't preempt itself and it only modify its own index */
    //CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);
    cc_irq_msg_rx_md3_sharemem_p[cc_irq_msg_buffer_index]->valid = 0;
    //CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
	
#if !defined(CC_IRQ_IT)
    /* send to internal module(a ilm KAL function to CC IRQ) */
    /* Platform-dependent */
    extern kal_bool kal_cc_irq_msg_send(ilm_struct *ilm_ptr);
    kal_cc_irq_msg_send(&rx_ilm);/* local_para_ptr may be NULL if no msg data */
#else/* for CC_IRQ_IT, test */
    extern void cc_irq_ut_msg_isr(ilm_struct *ilm_ptr);
    cc_irq_ut_msg_isr(&rx_ilm); 
	
    if (rx_ilm.local_para_ptr)
    {		
        free_local_para(rx_ilm.local_para_ptr);
    }
#endif            

}

/*****************************************************************************
 * Public Function                                                           *
 *****************************************************************************/
 /*------------------------------------------------------------------------
 * void    cc_irq_msg_init
 * Purpose:		initialize MD1 and MD3 ILM share memory pointer and parameters, register call back function 
 *              
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	None
 * Note    :    None.
 *------------------------------------------------------------------------
 */
void cc_irq_msg_init()
{
    kal_int32  i, ret;

#ifdef __PCORE__
    for(i = 0; i < CC_IRQ_MSG_MD1_MD3_BUFFER_NUMBER; i++)
    {
        cc_irq_msg_tx_md3_sharemem_p[i] = (CC_IRQ_MSG_MD1_MD3_BUFFER_T *)cc_irq_msg_ps2md3_share_data_addr + i;
        cc_irq_msg_rx_md3_sharemem_p[i] = (CC_IRQ_MSG_MD1_MD3_BUFFER_T *)cc_irq_msg_md32ps_share_data_addr + i;			
    }
#else
    for(i = 0; i < CC_IRQ_MSG_MD1_MD3_BUFFER_NUMBER; i++)
    {
        cc_irq_msg_tx_md3_sharemem_p[i] = (CC_IRQ_MSG_MD1_MD3_BUFFER_T *)cc_irq_msg_l12md3_share_data_addr + i;
        cc_irq_msg_rx_md3_sharemem_p[i] = (CC_IRQ_MSG_MD1_MD3_BUFFER_T *)cc_irq_msg_md32l1_share_data_addr + i;			
    }
#endif

    /* TX side initialize */
    for(i = 0; i < CC_IRQ_MSG_MD1_MD3_BUFFER_NUMBER; i++)
    {
        cc_irq_msg_tx_md3_sharemem_p[i]->valid = 0;			
    }

    /* register ILM channel */
    ret = cc_sys_comm_channel_init(cc_irq_msg_rx_md3_cc_sys_comm, cc_irq_msg_hisr);
    EXT_ASSERT(CC_SYS_COMM_SUCCESS == ret, ret, 0, 0);

}

/*------------------------------------------------------------------------
 * void         cc_irq_msg_share_mem_config
 * Purpose:		config the CC IRQ ILM share memory address between MD1 and MD3 
 *              
 * Parameters:
 *    Input:	kal_uint32 start_address: the ILM share memory start address of MD1 and MD3
 *    Output:	None
 * returns :	next_start_address
 * Note    :    This function should be called before cc_irq_msg_init.
 *------------------------------------------------------------------------
 */
kal_uint32 cc_irq_msg_share_mem_config(kal_uint32 start_address)
{
    kal_uint32 next_start_address;
	
    EXT_ASSERT(start_address%4==0, start_address, 0, 0);
	
#if defined(__PCORE__)
    cc_irq_msg_ps2md3_share_data_addr = start_address;/*  */
    cc_irq_msg_md32ps_share_data_addr = cc_irq_msg_ps2md3_share_data_addr + CC_IRQ_MSG_MD1_MD3_SHARE_MEM_SIZE + CC_IRQ_GUARD_PATTERN_LEN;/*  */
    cc_irq_fill_guard_pattern(cc_irq_msg_md32ps_share_data_addr-CC_IRQ_GUARD_PATTERN_LEN);	
    EXT_ASSERT(cc_irq_msg_md32ps_share_data_addr%4==0, cc_irq_msg_md32ps_share_data_addr, 0, 0);
    next_start_address = cc_irq_msg_md32ps_share_data_addr + CC_IRQ_MSG_MD1_MD3_SHARE_MEM_SIZE + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(next_start_address-CC_IRQ_GUARD_PATTERN_LEN);	
#elif defined(__L1CORE__)
    cc_irq_msg_l12md3_share_data_addr = start_address;
    cc_irq_msg_md32l1_share_data_addr = cc_irq_msg_l12md3_share_data_addr + CC_IRQ_MSG_MD1_MD3_SHARE_MEM_SIZE + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(cc_irq_msg_md32l1_share_data_addr-CC_IRQ_GUARD_PATTERN_LEN);	
    EXT_ASSERT(cc_irq_msg_md32l1_share_data_addr%4==0, cc_irq_msg_md32l1_share_data_addr, 0, 0);	
    next_start_address = cc_irq_msg_md32l1_share_data_addr + CC_IRQ_MSG_MD1_MD3_SHARE_MEM_SIZE + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(next_start_address-CC_IRQ_GUARD_PATTERN_LEN);	
#endif

    return next_start_address;
}

/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

/*------------------------------------------------------------------------
 * kal_int32 cc_irq_msg_send
 * Purpose:		Send an cross core(MD1->MD3) ILM. 
 * Parameters:
 *    Input:	ilm_struct* ilm_ptr
 *    Output:	None
 * returns :	CC_SYS_COMM_SUCCESS
 * Note    :    The while ILM would be put in the share memory of MD1 and MD3 in one time. 
 *              No matter send fail or success, caller must free control buffer(local_para_struct *_local_para_ptr) by themselves.
 *              _local_para_ptr should be NULL if there is no local parameter.
 *              User no need to check return value(always return success, all fail would trigger fatal error or assert in this function).
 *------------------------------------------------------------------------
 */
kal_int32 cc_irq_msg_send(ilm_struct* ilm_ptr)
{
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
    kal_uint32    cc_irq_msg_buffer_index, savedMask;
    kal_uint32    start_time, current_time, dur, msg_len = 0, tx_cnt = 0;

    if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
    {
        /* due to LR here is no use(the caller of this function is only KAL), we record src_mod_id and dest_mod_id*/
        kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT_ILM, (ilm_ptr->src_mod_id<<16|ilm_ptr->dest_mod_id));
    }

    if (cc_irq_sync_get_cc_irq_tx_md3_status() == KAL_FALSE)/* MD3 already in EPOF, we don't send ILM and just ignore it */
    {
        dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_MSG_ASYNC, ilm_ptr->src_mod_id, ilm_ptr->dest_mod_id, ilm_ptr->msg_id, CC_IRQ_GET_GLB_TS());
        return CC_SYS_COMM_SUCCESS;
    }

    /* find free msg buffer */
    start_time = CC_IRQ_GET_US();
    while(1)
    {
        CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);
        for(cc_irq_msg_buffer_index=0; cc_irq_msg_buffer_index < CC_IRQ_MSG_MD1_MD3_BUFFER_NUMBER; cc_irq_msg_buffer_index++)
        {
            if(cc_irq_msg_tx_md3_sharemem_p[cc_irq_msg_buffer_index]->valid == 0)
            {
                cc_irq_msg_tx_md3_sharemem_p[cc_irq_msg_buffer_index]->valid = 1;/* get a free msg buffer*/
                break;
            }
        }
        CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);

        if (cc_irq_msg_buffer_index < CC_IRQ_MSG_MD1_MD3_BUFFER_NUMBER)
        {/* get a free msg buffer*/
            break;
        }
        else/* no free msg buffer, wait and try*/
        {
            current_time = CC_IRQ_GET_US();
			
            CC_IRQ_GET_DURATION_US(start_time, current_time, dur);			
            if (dur > CC_IRQ_MSG_TX_MD3_TIMEOUT)
            {/* MSG TX timeout */
                tx_cnt++;
                if (tx_cnt == 10)/* avoid context switch out and timeout, so we try many times to confirm */
                {
                    EXT_ASSERT(0, start_time, current_time, dur);//No free msg buffer for a long time
                }
            }
        }
    }

    /* fill in ILM information */ 
    kal_mem_cpy((void*)&(cc_irq_msg_tx_md3_sharemem_p[cc_irq_msg_buffer_index]->ilm), (void*)ilm_ptr, sizeof(ilm_struct));	

    if(ilm_ptr->local_para_ptr != NULL)
    {
        if(ilm_ptr->local_para_ptr->msg_len > CC_IRQ_MSG_MD1_MD3_ILM_PARA_SIZE)
        {
            EXT_ASSERT(0, ilm_ptr->dest_mod_id, ilm_ptr->src_mod_id, ilm_ptr->local_para_ptr->msg_len);
        }
	
        /* copy in ILM data */	
        kal_mem_cpy((void*)cc_irq_msg_tx_md3_sharemem_p[cc_irq_msg_buffer_index]->local_para_buffer, (void*)ilm_ptr->local_para_ptr, ilm_ptr->local_para_ptr->msg_len);
        msg_len = ilm_ptr->local_para_ptr->msg_len;

        /* the "local_para_ptr" in ilm structure is no use for the other core, we should clean it. */
        cc_irq_msg_tx_md3_sharemem_p[cc_irq_msg_buffer_index]->ilm.local_para_ptr = NULL;		
    }

    ASSERT(cc_sys_comm_tx_polling(cc_irq_msg_tx_md3_cc_sys_comm, cc_irq_msg_buffer_index, msg_len)==CC_SYS_COMM_SUCCESS);
 /* up for MD3    -------------------------------------------------- */
#else/* There is no MD3 ==> fatal error */
    kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT_ILM, (ilm_ptr->src_mod_id<<16|ilm_ptr->dest_mod_id));
#endif/*_MD3_SUPPORT_*/

    return CC_SYS_COMM_SUCCESS;
}

