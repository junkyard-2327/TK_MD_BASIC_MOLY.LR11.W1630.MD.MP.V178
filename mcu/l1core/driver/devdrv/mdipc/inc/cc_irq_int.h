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
 *   cc_irq_int.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   Internal definition of CC IRQ.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CC_IRQ_INT_H__
#define __CC_IRQ_INT_H__

#include "cc_irq_public.h"
#include "cc_irq_hw.h"



/*****************************************************************************
 * Option Definition                                                         *
 *****************************************************************************/
//- Must define CC_IRQ_IT for test!!
//#define CC_IRQ_IT
/* Note: if you are test between MD1 & MD3, please add "MD1_MD3_CC_USER_SHARE_MEM_REG(MD32PS_CCIT_SHARE, 256)" in md1_md3_cc_user_share_mem_config.h*/
 

/*****************************************************************************
 * Value Definition                                                          *
 *****************************************************************************/

/* the number of IRQ was used by user */
#define CC_IRQ_MD1_MAX_CHANNEL          ((CC_IRQ_L2P_NUMBER > CC_IRQ_P2L_NUMBER)?CC_IRQ_L2P_NUMBER:CC_IRQ_P2L_NUMBER) 

#if defined(__PCORE__)
#define CC_IRQ_RX_MD1_CHANNEL_NUMBER    CC_IRQ_L2P_NUMBER  /* the most number of IRQ was used by user(the value is the real number +1, EX: 6 means the real user number is 5) */
#define CC_IRQ_TX_MD1_CHANNEL_NUMBER    CC_IRQ_P2L_NUMBER
#elif defined(__L1CORE__)
#define CC_IRQ_RX_MD1_CHANNEL_NUMBER    CC_IRQ_P2L_NUMBER
#define CC_IRQ_TX_MD1_CHANNEL_NUMBER    CC_IRQ_L2P_NUMBER
#endif

/* due to buffer design, the buffer number must not less than 2(the buffer we could use is "num-1") */ 
#define CC_IRQ_NESTED_TRIGGER_MAX    16    
#define CC_IRQ_BUFFER_MODE_BUFF_NUM    16  /* the buffer number in buffer mode */ 

#define CC_IRQ_SHARE_DATA_L12PS_PREFIX     0x314C4343    //- "CCL1"
#define CC_IRQ_SHARE_DATA_L12PS_POSTFIX    0x314C4343    //- "CCL1"
#define CC_IRQ_SHARE_DATA_PS2L1_PREFIX     0x53504343    //- "CCPS"
#define CC_IRQ_SHARE_DATA_PS2L1_POSTFIX    0x53504343    //- "CCPS"


#define CC_IRQ_PARA_NUMBER           3
#define CC_IRQ_BUFF_MAX             60
#define CC_IRQ_HDR_LEN               4

#define CC_IRQ_RX_LOGGING_NUMBER     16
#define CC_IRQ_TX_LOGGING_NUMBER     16

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */		

//----------------
/* for determine the "CC_IRQ_MAX_CHANNEL" number, we find the most channel(IRQ) number between MD1 and MD3 first. Then compare to "CC_IRQ_MD1_MAX_CHANNEL" */
#define CC_IRQ_PS_MD3_MAX_CHANNEL          ((CC_IRQ_MD32P_NUMBER > CC_IRQ_P2MD3_NUMBER)?CC_IRQ_MD32P_NUMBER:CC_IRQ_P2MD3_NUMBER)
  
/* the number of IRQ was used by user */
#define CC_IRQ_L1_MD3_MAX_CHANNEL          ((CC_IRQ_MD32L_NUMBER > CC_IRQ_L2MD3_NUMBER)?CC_IRQ_MD32L_NUMBER:CC_IRQ_L2MD3_NUMBER)
   
/* the number of IRQ was used by user */
#define CC_IRQ_MD3_MAX_CHANNEL          ((CC_IRQ_PS_MD3_MAX_CHANNEL > CC_IRQ_L1_MD3_MAX_CHANNEL)?CC_IRQ_PS_MD3_MAX_CHANNEL:CC_IRQ_L1_MD3_MAX_CHANNEL)
//----------------

#if defined(__PCORE__)
#define CC_IRQ_RX_MD3_CHANNEL_NUMBER    CC_IRQ_MD32P_NUMBER /* the most number of IRQ was used by user(the value is the real number +1, EX: 6 means the real user number is 5) */
#define CC_IRQ_TX_MD3_CHANNEL_NUMBER    CC_IRQ_P2MD3_NUMBER
#elif defined(__L1CORE__)
#define CC_IRQ_RX_MD3_CHANNEL_NUMBER    CC_IRQ_MD32L_NUMBER
#define CC_IRQ_TX_MD3_CHANNEL_NUMBER    CC_IRQ_L2MD3_NUMBER
#endif


#define CC_IRQ_SHARE_DATA_L12MD3_PREFIX     0x3332314C    //- "L123"
#define CC_IRQ_SHARE_DATA_L12MD3_POSTFIX    0x3332314C    //- "L123"
#define CC_IRQ_SHARE_DATA_PS2MD3_PREFIX     0x33325350    //- "PS23"
#define CC_IRQ_SHARE_DATA_PS2MD3_POSTFIX    0x33325350    //- "PS23"


#define CC_IRQ_GUARD_PATTERN_LEN     16 /* 16 bytes for easy debug */
#define CC_IRQ_GUARD_PATTERN_0         0x535F4343 /*CC_S*/
#define CC_IRQ_GUARD_PATTERN_1         0x4D454D48 /*HMEM ==> "CC_SHMEM"*/
		
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */		
    #define CC_IRQ_MAX_CHANNEL          ((CC_IRQ_MD1_MAX_CHANNEL > CC_IRQ_MD3_MAX_CHANNEL)?CC_IRQ_MD1_MAX_CHANNEL:CC_IRQ_MD3_MAX_CHANNEL)
/* up for MD3    -------------------------------------------------- */
#else /* no MD3 */
    #define CC_IRQ_MAX_CHANNEL          CC_IRQ_MD1_MAX_CHANNEL 
#endif/*_MD3_SUPPORT_*/

/*****************************************************************************
 * MACRO Definition                                                          *
 *****************************************************************************/



/*****************************************************************************
 * Data Type Definition                                                      *
 *****************************************************************************/
typedef enum cc_irq_type_e {
    CC_IRQ_HDR_TYPE_PARA = 0,
    CC_IRQ_HDR_TYPE_BUFF,
    CC_IRQ_HDR_TYPE_MAX
} cc_irq_type_t;

typedef struct {
    kal_uint32 cc_irq_type;    /* param mode or buffer mode */
    kal_uint32 param_0; /* if cc_irq_type is CC_IRQ_HDR_TYPE_BUFF, param_0 is the valid data length of cc_irq_tx_buffer, param_1 & param_2 are no use */
    kal_uint32 param_1;
    kal_uint32 param_2; /*this would be comm_id in CC SYS */
}cc_irq_param_t;/* for direct(para) mode use */

typedef struct {
    kal_uint32 buff[CC_IRQ_BUFF_MAX / sizeof(kal_uint32)];/* 60/4=15, 4 bytes*15= 60 bytes */
}cc_irq_buffer_t;

typedef struct {
    kal_uint32    prefix;                                                          /* prefix= 0x53504343("CCPS") or  0x314C4343("CCL1") or 0x3332314C("L123") or  0x33325350("PS23")*/
    cc_irq_param_t cc_irq_tx_param[CC_IRQ_MAX_CHANNEL][CC_IRQ_NESTED_TRIGGER_MAX]; /* tx or rx data, CC_IRQ_MAX_CHANNEL==> irq number, CC_IRQ_NESTED_TRIGGER_MAX==> whitch time */
    cc_irq_buffer_t cc_irq_tx_buffer[CC_IRQ_MAX_CHANNEL][CC_IRQ_BUFFER_MODE_BUFF_NUM]; 	
    kal_uint32     cc_irq_param_read_index[CC_IRQ_MAX_CHANNEL]; /* the index of this IRQ channel the other core or (we) haven't read (0, 1, 2...)*/                          
    kal_uint32     cc_irq_param_write_index[CC_IRQ_MAX_CHANNEL];/* the index of this IRQ channel we or (the other core) haven't write (0, 1, 2...)*/                           
    kal_uint32     cc_irq_buffer_read_index[CC_IRQ_MAX_CHANNEL];/* the index of this IRQ channel the other core or (we) haven't read (0, 1, 2...)*/                            
    kal_uint32     cc_irq_buffer_write_index[CC_IRQ_MAX_CHANNEL]; /* the index of this IRQ channel we or (the other core) haven't write (0, 1, 2...)*/                          	
    kal_uint32    postfix;                                        /* postfix = 0x53504343("CCPS") or  0x314C4343("CCL1") or 0x3332314C("L123") or  0x33325350("PS23") */                    
} CC_IRQ_SHARE_MEM_T; /* a share memory with the other core, (read by us, write by the other core)==>cc_irq_rx_md1_sharemem_p, (read by the other core, write by us)==>cc_irq_tx_md1_sharemem_p */

#define CC_IRQ_MD3_SHARE_MEM_T CC_IRQ_SHARE_MEM_T/* for easy implementation */

typedef struct {
    kal_uint32     global_ts;/* the value is FRC(us)/64 */    
    kal_uint32     cc_irq_type;  	
    kal_uint32     current_param_index;  
} CC_IRQ_TRANS_LOG_T;

typedef struct {
    kal_uint32 start_time;/* us */
    kal_uint32 end_time;/* us */
    kal_uint32 user_call_back;
} CC_SYS_COMM_HISR_LOG_T;

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
typedef struct {
    kal_uint32 size;
    kal_uint32 start_addr;	
} CC_IRQ_MD1_MD3_USER_SHARE_MEM_INFO_T;
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

extern void cc_irq_sys_init();
extern void cc_irq_sync_init();
extern kal_uint32 cc_irq_sync_get_cc_irq_tx_md1_status();

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
extern kal_uint32 cc_irq_msg_share_mem_config(kal_uint32 start_address);
extern kal_uint32 cc_irq_rpc_share_mem_config(kal_uint32 start_address);
extern void cc_irq_fill_guard_pattern(kal_uint32 address);

extern void cc_irq_msg_init();
extern void cc_irq_rpc_init();
extern void cc_irq_sync_process_epof_from_md3();
extern kal_uint32 cc_irq_sync_get_cc_irq_tx_md3_status();
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

#endif  /* __CC_IRQ_INT_H__ */

