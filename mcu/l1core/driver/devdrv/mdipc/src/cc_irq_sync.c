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
 *   cc_irq_sync.c
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This Module defines CC SYNC API(only for MD1<->MD3).
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
#include "ex_mem_manager_public.h"
#if defined(ATEST_ENABLE) && defined(ATEST_DRV_ENABLE) && defined(__MTK_TARGET__)
    /* there is no OSTD driver when driver test, we also disable PCORE<->L1CORE polling function by default */
    #define OSTD_Infinite_Sleep_Query()    KAL_TRUE
#else
    #include "ostd_public.h"
#endif


#define CC_IRQ_SYNC_LOG_MAX    16
#define CC_IRQ_SYNC_USER_CB_TIMEOUT    (10000UL)    /* 10ms */ 

#if defined(__PCORE_ONLY__) || defined(__L1CORE_ONLY__)
void cc_irq_sync_init_HS1(){}
void cc_irq_sync_disable_cc_irq_tx_md1(){}

#else //defined(__PCORE_ONLY__) || defined(__L1CORE_ONLY__)

#if defined(__PCORE__)	

  kal_uint32 const cc_irq_sync_tx_md1_cc_sys_comm = CC_SYS_COMM_P2L_SYNC;	
  kal_uint32 const cc_irq_sync_rx_md1_cc_sys_comm = CC_SYS_COMM_L2P_SYNC;

  /* ping and ack timer: PScore ping L1CORE every 10 sec(cc_irq_sync_ping_md1_timer_id), and L1CORE must reply in 5 sec to clear timer(cc_irq_sync_ping_md1_ack_timer_id) */
  kal_timerid cc_irq_sync_ping_md1_timer_id;
  kal_timerid cc_irq_sync_ping_md1_ack_timer_id;

  //- Declare status sync log.
  kal_uint32 cc_irq_sync_tx_md1_time[CC_IRQ_SYNC_LOG_MAX];/* the timestamp PScore ping L1CORE */
  kal_uint32 cc_irq_sync_rx_md1_time[CC_IRQ_SYNC_LOG_MAX];/* the timestamp PScore receive ack from L1CORE*/
  kal_uint32 cc_irq_sync_tx_md1_time_index = 0;
  kal_uint32 cc_irq_sync_rx_md1_time_index = 0;

  #if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
  /* below for MD3 -------------------------------------------------- */
  kal_uint32 const cc_irq_sync_tx_md3_cc_sys_comm = CC_SYS_COMM_P2MD3_SYNC;	
  kal_uint32 const cc_irq_sync_rx_md3_cc_sys_comm = CC_SYS_COMM_MD32P_SYNC;	

  /* ping and ack timer: PScore ping MD3 every 10 sec(cc_irq_sync_ping_md3_timer_id), and MD3 must reply in 5 sec to clear timer(cc_irq_sync_ping_md3_ack_timer_id) */
  kal_timerid cc_irq_sync_ping_md3_timer_id;
  kal_timerid cc_irq_sync_ping_md3_ack_timer_id;

  //- Declare status sync log.
  kal_uint32 cc_irq_sync_tx_md3_time[CC_IRQ_SYNC_LOG_MAX];/* the timestamp PScore ping MD3 */
  kal_uint32 cc_irq_sync_rx_md3_time[CC_IRQ_SYNC_LOG_MAX];/* the timestamp PScore receive ack from MD3*/
  kal_uint32 cc_irq_sync_tx_md3_time_index = 0;
  kal_uint32 cc_irq_sync_rx_md3_time_index = 0;
  
  /* up for MD3    -------------------------------------------------- */
  #endif/*_MD3_SUPPORT_*/

#else/* L1CORE */

  kal_uint32 const cc_irq_sync_tx_md1_cc_sys_comm = CC_SYS_COMM_L2P_SYNC;	 
  kal_uint32 const cc_irq_sync_rx_md1_cc_sys_comm = CC_SYS_COMM_P2L_SYNC;

  /* L1CORE wait PSCORE's ping timer: L1CORE must receive PSCORE's ping in 15 sec to clear timer(cc_irq_sync_rx_md1_ping_timer_id) */
  kal_timerid cc_irq_sync_rx_md1_ping_timer_id;

  //- Declare status sync log.
  kal_uint32 cc_irq_sync_rx_md1_time[CC_IRQ_SYNC_LOG_MAX];/* the timestamp L1CORE receive ping pkt from PScore*/
  kal_uint32 cc_irq_sync_rx_md1_time_index = 0;

  #if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
  /* below for MD3 -------------------------------------------------- */
  kal_uint32 const cc_irq_sync_tx_md3_cc_sys_comm = CC_SYS_COMM_L2MD3_SYNC;	 /* L1core only receive state change pkt from MD3 but doesn't send to MD3 */
  kal_uint32 const cc_irq_sync_rx_md3_cc_sys_comm = CC_SYS_COMM_MD32L_SYNC;	
  /* up for MD3    -------------------------------------------------- */
  #endif/*_MD3_SUPPORT_*/

#endif

/* TRUE: whether user could send CC IRQ to MD1(PSCORE/L1CORE) or not. Default is TRUE, only when the other core starting EPOF, it would change to FALSE */                     
__attribute__ ((section ("INTSRAM_RW"))) kal_uint32 cc_irq_sync_cc_irq_tx_md1_status = KAL_TRUE;

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
                                                                   
#if defined(__PCORE__)
#define CC_IRQ_SYNC_TX_MD3_USER_CB_NUMBER    (CC_IRQ_SYNC_P2MD3_END - CC_IRQ_SYNC_P2MD3_BASE)
#define CC_IRQ_SYNC_RX_MD3_USER_CB_NUMBER    (CC_IRQ_SYNC_MD32P_END - CC_IRQ_SYNC_MD32P_START)

/* for function registered by user to execute before/after sync packet to/from MD3. */
#define CC_IRQ_SYNC_TX_FUNC_ID_IS_IN_RANGE(func_id)       ((func_id) >= CC_IRQ_SYNC_P2MD3_BASE && (func_id) < CC_IRQ_SYNC_P2MD3_END)
#define CC_IRQ_SYNC_RX_FUNC_ID_IS_IN_RANGE(func_id)       ((func_id) >= CC_IRQ_SYNC_MD32P_START && (func_id) < CC_IRQ_SYNC_MD32P_END)
#define CC_IRQ_SYNC_TX_MD3_FUNC_ID_OFFSET(func_id)                 ((func_id) - CC_IRQ_SYNC_P2MD3_BASE)
#define CC_IRQ_SYNC_RX_MD3_FUNC_ID_OFFSET(func_id)                 ((func_id) - CC_IRQ_SYNC_MD32P_START)

/* for function registered by user to execute before/after sync packet to/from MD3. */
CC_IRQ_SYNC_USER_CALLBACK_P cc_irq_sync_tx_md3_user_cb[CC_IRQ_SYNC_TX_MD3_USER_CB_NUMBER];
CC_IRQ_SYNC_USER_CALLBACK_P cc_irq_sync_rx_md3_user_cb[CC_IRQ_SYNC_RX_MD3_USER_CB_NUMBER];

kal_uint32 cc_irq_sync_tx_md3_user_cb_execute_time[CC_IRQ_SYNC_TX_MD3_USER_CB_NUMBER];
kal_uint32 cc_irq_sync_rx_md3_user_cb_execute_time[CC_IRQ_SYNC_RX_MD3_USER_CB_NUMBER];

#else /* L1core */
/* not support */
#endif

kal_uint32        cc_irq_sync_md3_current_state = CC_IRQ_SYS_STATE_INIT;    

/* MD3 is alive or not ==> If MD3 is alive, we should wait his EPOF notification when we receive EPOF */
kal_uint32 cc_irq_sync_md3_status = KAL_FALSE;

/* TRUE: whether user could send CC IRQ to MD3 or not. Default is TRUE, only when receive MD3's EPOF notification, it would change to FALSE */                     
volatile kal_uint32          cc_irq_sync_cc_irq_tx_md3_status = KAL_TRUE;

/* these time only for MD3 */
kal_uint32 cc_irq_sync_trans_to_running_time = 0;/* MD1's glb_ts when receive */
kal_uint32 cc_irq_sync_receive_HS2_time = 0;/* MD1's glb_ts when receive */
kal_uint32 cc_irq_sync_trans_to_async_time = 0;/* MD1's glb_ts when receive */

/*****************************************************************************
 * Internal Function                                                         *
 *****************************************************************************/
 /*
void cc_irq_sync_enable_cc_irq_tx_md3()
{
    cc_irq_sync_cc_irq_tx_md3_status = KAL_TRUE;
}
*/
static void cc_irq_sync_disable_cc_irq_tx_md3()
{
    cc_irq_sync_cc_irq_tx_md3_status = KAL_FALSE;
}

static kal_int32 cc_irq_sync_state_trans(kal_uint32 current_state, kal_uint32 next_state)
{
    cc_irq_sync_md3_current_state = next_state;
    return 0;
}

static void cc_irq_sync_state_trans_running()
{
    ASSERT(cc_irq_sync_state_trans(cc_irq_sync_md3_current_state, CC_IRQ_SYS_STATE_RUNNING) == 0);
    cc_irq_sync_trans_to_running_time = CC_IRQ_GET_GLB_TS();

    cc_irq_sync_md3_status = KAL_TRUE;	
    /* Platform-dependent */
    dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_TRANS, cc_irq_sync_md3_current_state, CC_IRQ_SYS_STATE_RUNNING);
}

static void cc_irq_sync_state_trans_async()
{
    ASSERT(cc_irq_sync_state_trans(cc_irq_sync_md3_current_state, CC_IRQ_SYS_STATE_ASYNC) == 0);
    cc_irq_sync_trans_to_async_time = CC_IRQ_GET_GLB_TS();

    /* Platform-dependent */
    dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_TRANS, cc_irq_sync_md3_current_state, CC_IRQ_SYS_STATE_ASYNC);

    cc_irq_sync_disable_cc_irq_tx_md3();
}

/* default callback function which would be execute when MD1 ping MD3 or MD3 ack MD1 */
void cc_irq_sync_default_user_cb()
{
    /* do nothing */
}

/* fake callback function which would be execute when L1core receive EPOF notification from MD3 */
void cc_irq_sync_epof_user_cb(kal_uint32 para1, kal_uint32 para2)
{
    /* do nothing */
}

#if defined(__PCORE__)
static void cc_irq_sync_ping_md3_ack_timer_cb()
{   
    /* Platform-dependent */
    dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_MD3_HANG, CC_IRQ_GET_GLB_TS());
    
    kal_fatal_error_handler(KAL_ERROR_C2K_LONG_TIME_NO_RESPONSE, CC_IRQ_PEER_NO_RESPONSE_SYNC);/* (0x3001, 0x102)=(12289, 258), MD3 long time no response */
}

static void cc_irq_sync_ping_md3_timer_cb()
{
    kal_uint32  glb_time_stamp, i;
    kal_uint32  cc_irq_sync_ping_cb_start_time, cc_irq_sync_ping_cb_end_time, duration;	


    /* execute all function registered by user before send ping packet */
    for(i=0; i<CC_IRQ_SYNC_TX_MD3_USER_CB_NUMBER; i++)
    {
        EXT_ASSERT(cc_irq_sync_tx_md3_user_cb[i] != NULL, i, 0, 0);
		
        cc_irq_sync_ping_cb_start_time = CC_IRQ_GET_US();		
        cc_irq_sync_tx_md3_user_cb[i]();
        cc_irq_sync_ping_cb_end_time = CC_IRQ_GET_US();
		
        /* Due to the call back function is executed in timer HISR, it could not execute too long. */            			
        CC_IRQ_GET_DURATION_US(cc_irq_sync_ping_cb_start_time, cc_irq_sync_ping_cb_end_time, duration);
        cc_irq_sync_tx_md3_user_cb_execute_time[i] = duration;/* for debug */
		
        if (duration > CC_IRQ_SYNC_USER_CB_TIMEOUT)
        {
            EXT_ASSERT(0, i, duration, (kal_uint32)cc_irq_sync_tx_md3_user_cb[i]);
        }        
    }
		
    glb_time_stamp = CC_IRQ_GET_GLB_TS();
    
    /* start timer and polling for ack, MD3 should reply in 5 seconds to clear this timer */
    kal_set_timer(cc_irq_sync_ping_md3_ack_timer_id, cc_irq_sync_ping_md3_ack_timer_cb, NULL, KAL_TICKS_5_SEC, 0);    
    ASSERT(cc_sys_comm_tx_polling(cc_irq_sync_tx_md3_cc_sys_comm, CC_IRQ_SYNC_PKT_TYPE_PING, glb_time_stamp)==CC_SYS_COMM_SUCCESS);
    
    /* log */
    dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_PING_TX_MD3, glb_time_stamp);
    cc_irq_sync_tx_md3_time[cc_irq_sync_tx_md3_time_index] = CC_IRQ_GET_GLB_TS();
    cc_irq_sync_tx_md3_time_index = (cc_irq_sync_tx_md3_time_index + 1) % CC_IRQ_SYNC_LOG_MAX;
}
#endif

/*------------------------------------------------------------------------
 * void cc_irq_sync_hisr_rx_md3
 * Purpose:		The HISR function when receiving a CC SYS SYNC pkt from MD3, 
 *              the ISR flow is cc_irq_lisr(kal_uint32 irqx)-->cc_sys_comm_lisr()-->cc_sys_comm_hisr()-->cc_irq_sync_hisr_rx_md3()
 * Parameters:
 *    Input:	
 *              kal_uint32 pkt_type: The packet type in CC_SYS_SYNC_PKT_TYPE_T.
 *              kal_uint32 glb_time_stamp: global time stamp. 
 *    Output:	None
 * returns :	None
 * Note    :    This function is running in HISR.
 *------------------------------------------------------------------------
 */
void cc_irq_sync_hisr_rx_md3(kal_uint32 pkt_type, kal_uint32 glb_time_stamp)
{
    kal_uint32  cur_glb_ts = CC_IRQ_GET_GLB_TS();

    
    switch (cc_irq_sync_md3_current_state)
    {
        case CC_IRQ_SYS_STATE_INIT:
            if (pkt_type == CC_IRQ_SYNC_PKT_TYPE_INIT_HS1)
            {/* start polling, send HS2 and change to RUNNING state */

                /* Platform-dependent */
                dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_RX_MD3_INIT_HS1, cur_glb_ts, glb_time_stamp);

#if defined(__PCORE__)/* polling MD3 */	
                ASSERT(cc_irq_sync_ping_md3_timer_id);
                ASSERT(cc_irq_sync_ping_md3_ack_timer_id);
                /* polling MD3 every 10 seconds */
                kal_set_timer(cc_irq_sync_ping_md3_timer_id, cc_irq_sync_ping_md3_timer_cb, NULL, KAL_TICKS_5_SEC * 2, KAL_TICKS_5_SEC * 2);	
				
                /* send HS2 */
                ASSERT(cc_sys_comm_tx_polling(cc_irq_sync_tx_md3_cc_sys_comm, CC_IRQ_SYNC_PKT_TYPE_INIT_HS2, CC_IRQ_GET_GLB_TS())==CC_SYS_COMM_SUCCESS);				
#endif

                cc_irq_sync_state_trans_running(); 

            }
            /* Undefined combination */
            else
            {
                EXT_ASSERT(0, cc_irq_sync_md3_current_state, pkt_type, 0);
            }
          break;

        case CC_IRQ_SYS_STATE_RUNNING:
            if (pkt_type == CC_IRQ_SYNC_PKT_TYPE_INIT_HS2)
            {	            
                /* record the time of the other core enter scheduler */            
                cc_irq_sync_receive_HS2_time = glb_time_stamp;
				
                dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_RX_MD3_INIT_HS2, cur_glb_ts, glb_time_stamp);				
            }			
#if defined(__PCORE__)		  
            else if (pkt_type == CC_IRQ_SYNC_PKT_TYPE_PING_ACK)
            {/* receive ack packet from MD3 */
                /* cancel timer for ack timeout */
                kal_cancel_timer(cc_irq_sync_ping_md3_ack_timer_id);
            	
                /* log */
                dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_ACK_RX_MD3, cur_glb_ts , glb_time_stamp);
                cc_irq_sync_rx_md3_time[cc_irq_sync_rx_md3_time_index] = cur_glb_ts;
                cc_irq_sync_rx_md3_time_index = (cc_irq_sync_rx_md3_time_index + 1) % CC_IRQ_SYNC_LOG_MAX;

                kal_uint32 i;
                kal_uint32  cc_irq_sync_ack_cb_start_time, cc_irq_sync_ack_cb_end_time, duration;				
                /* execute all function registered by user after receive ack packet */
                for(i=0; i<CC_IRQ_SYNC_RX_MD3_USER_CB_NUMBER; i++)
                {
                    EXT_ASSERT(cc_irq_sync_rx_md3_user_cb[i] != NULL, i, 0, 0);
					
                    cc_irq_sync_ack_cb_start_time = CC_IRQ_GET_US();					
                    cc_irq_sync_rx_md3_user_cb[i]();
                    cc_irq_sync_ack_cb_end_time = CC_IRQ_GET_US();

                    /* Due to the call back function is executed in timer HISR, it could not execute too long. */            			
                    CC_IRQ_GET_DURATION_US(cc_irq_sync_ack_cb_start_time, cc_irq_sync_ack_cb_end_time, duration);
                    cc_irq_sync_rx_md3_user_cb_execute_time[i] = duration;/* for debug */
		
                    if (duration > CC_IRQ_SYNC_USER_CB_TIMEOUT)
                    {
                        EXT_ASSERT(0, i, duration, (kal_uint32)cc_irq_sync_rx_md3_user_cb[i]);
                    }  					
                }				
            }
#endif			
            /* Undefined combination */
            else
            {
                EXT_ASSERT(0, cc_irq_sync_md3_current_state, pkt_type, 0);
            }
          break;	

        case CC_IRQ_SYS_STATE_ASYNC:
            if (pkt_type == CC_IRQ_SYNC_PKT_TYPE_INIT_HS1)
            {/* the other core reset independently */
                EXT_ASSERT(0, cc_irq_sync_md3_current_state, pkt_type, 0);
            }
            /* Undefined combination */
            else
            {
                /* do nothing */
            }
          break;

        default:
          EXT_ASSERT(0, cc_irq_sync_md3_current_state, pkt_type, 0);
          break;		  
    }
}

/*****************************************************************************
 * Public Function for MD3                                                   *
 *****************************************************************************/
/*------------------------------------------------------------------------
 * kal_uint32 cc_irq_sync_get_cc_irq_tx_md3_status()
 * Purpose:		Get the CC IRQ status about tx to MD3. The status about tx to MD3 is enable default, it would change to disable when 
 *              receive EPOF notification from MD3.
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	KAL_TRUE/KAL_FALSE
 * Note    :    None
 *------------------------------------------------------------------------
 */
kal_uint32 cc_irq_sync_get_cc_irq_tx_md3_status()
{
    return cc_irq_sync_cc_irq_tx_md3_status;
}

/*------------------------------------------------------------------------
 * kal_uint32 cc_irq_sync_process_epof_from_md3()
 * Purpose:		When receive EPOF notification from MD3, CC IRQ should cancel polling timer and change status to ASYNC.
 *              
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	None
 * Note    :    None
 *------------------------------------------------------------------------
 */
void cc_irq_sync_process_epof_from_md3()
{

#if defined(__PCORE__)	            
    /* cancel both timer for polling */            
    kal_cancel_timer(cc_irq_sync_ping_md3_timer_id);            
    kal_cancel_timer(cc_irq_sync_ping_md3_ack_timer_id);
#endif

    /* log */
    dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_EPOF_SYNC, CC_IRQ_GET_GLB_TS());
				
    /* EMM log */
    kal_uint32 usc = CC_IRQ_GET_US();
    EMM_WriteDbgInfo(EMM_CC_IRQ_MD3_PWR_OFF_IND, &usc);
				
    cc_irq_sync_state_trans_async();	

}

/* MD3 is alive or not ==> If MD3 is alive, we should wait his EPOF notification when we receive EPOF */
kal_uint32 cc_irq_sync_get_md3_status()
{
#if 0
/* under construction !*/
#else
    return  CC_IRQ_MD3_IS_EXIST();/* Try!! If MD3 exist, we always wait his EPOF notification when we receive EPOF*/
#endif
}

#if defined(__PCORE__)/* for CC SYS SYNC user callback function, only PScore support now */
/*------------------------------------------------------------------------
 * kal_int32 cc_irq_sync_register_tx_cb(kal_uint32 func_id, CC_SYS_SYNC_CALLBACK_P funcp)
 * Purpose:	    register a callback function which would be execute when MD1 ping MD3 
 *              
 * Parameters:
 *    Input:	func_id: CC_SYS_SYNC_FUNC_ID_T in "global_cc_sys_sync_id.h"
                CC_IRQ_SYNC_USER_CALLBACK_P funcp: user call back function(would be call in HISR)
 *    Output:	None
 * returns :	CC_SYS_COMM_SUCCESS/CC_SYS_COMM_ERR_PARAM
 * Note    :    User should check the return value
 *------------------------------------------------------------------------
 */
kal_int32 cc_irq_sync_register_tx_cb(kal_uint32 func_id, CC_IRQ_SYNC_USER_CALLBACK_P funcp)
{
    kal_int32 func_id_offset;
    kal_uint32 caller_LR;
	
    GET_RETURN_ADDRESS(caller_LR);
	
    if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
    {
        kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
    }
	
    if (!CC_IRQ_SYNC_TX_FUNC_ID_IS_IN_RANGE(func_id) || funcp == NULL)
    {
        return CC_SYS_COMM_ERR_PARAM;
    }

    func_id_offset = CC_IRQ_SYNC_TX_MD3_FUNC_ID_OFFSET(func_id);

    cc_irq_sync_tx_md3_user_cb[func_id_offset] = funcp;
    
    return CC_SYS_COMM_SUCCESS;
}

/*------------------------------------------------------------------------
 * kal_int32 cc_irq_sync_register_rx_cb(kal_uint32 func_id, CC_SYS_SYNC_CALLBACK_P funcp)
 * Purpose:	    register a callback function which would be execute when MD3 ack MD1 
 *              
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	CC_SYS_COMM_SUCCESS/CC_SYS_COMM_ERR_PARAM
 * Note    :    User should check the return value
 *------------------------------------------------------------------------
 */
kal_int32 cc_irq_sync_register_rx_cb(kal_uint32 func_id, CC_IRQ_SYNC_USER_CALLBACK_P funcp)
{
    kal_int32 func_id_offset;
    kal_uint32 caller_LR;

    GET_RETURN_ADDRESS(caller_LR);
	
    if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
    {
        kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
    }
	
    if (!CC_IRQ_SYNC_RX_FUNC_ID_IS_IN_RANGE(func_id) || funcp == NULL)
    {
        return CC_SYS_COMM_ERR_PARAM;
    }

    func_id_offset = CC_IRQ_SYNC_RX_MD3_FUNC_ID_OFFSET(func_id);

    cc_irq_sync_rx_md3_user_cb[func_id_offset] = funcp;
    
    return CC_SYS_COMM_SUCCESS;
}
#endif
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/


static void cc_irq_sync_ping_md1_ack_timer_cb()
{   
#if defined(__PCORE__)
    /* Platform-dependent */
    dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_L1core_HANG, CC_IRQ_GET_GLB_TS());
    /* L1CORE didn't reply in 5 seconds */
    kal_fatal_error_handler(KAL_ERROR_INTERCORE_LONG_TIME_NO_RESPONSE, CC_IRQ_PEER_NO_RESPONSE_SYNC);/* (0x3106, 0x102)=(12550, 258), MD1 long time no response */
#else/* L1core */

    /* In MD1's EPOF flow, PScore would wait L1core power down first(AP send EPOF to PScore, and PScore send EPOF to L1core).
       After PScore receive EPOF from AP, PScore would disable CC IRQ polling function to L1core.
       (After PScore receive EPOF from AP, it would also send EPOF to L1core by CC IRQ right away.)
       So if L1core didn't receive PScore's polling and L1core already receive EPOF from PScore, L1core shouldn't EE.
	*/
    if(OSTD_Infinite_Sleep_Query() == KAL_TRUE) 
    {
        kal_cancel_timer(cc_irq_sync_rx_md1_ping_timer_id);/* cancel timer due to PScore would never polling L1core due to EPOF */	
        dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_PScore_PROCESS_EPOF);
    }  
    else 
    {
        /* PSCORE didn't polling in 15 seconds */
        dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_PScore_HANG, CC_IRQ_GET_GLB_TS());		
        kal_fatal_error_handler(KAL_ERROR_INTERCORE_LONG_TIME_NO_RESPONSE, CC_IRQ_PEER_NO_RESPONSE_SYNC);/* (0x3106, 0x102)=(12550, 258), MD1 long time no response */
    } 
#endif 

}

#if defined(__PCORE__)
static void cc_irq_sync_ping_md1_timer_cb()
{
    kal_uint32  glb_time_stamp;
		
    glb_time_stamp = CC_IRQ_GET_GLB_TS();

    if(OSTD_Infinite_Sleep_Query() == KAL_TRUE) 
    {/* PScore receive EPOF from AP, stop polling L1core */
        kal_cancel_timer(cc_irq_sync_ping_md1_timer_id);/* cancel timer due to PScore would never polling L1core due to EPOF */

        /* log */
        dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_PScore_STOP_POLL_L1core, glb_time_stamp);
    }  
    else 
    {
        /* start timer and polling for ack, MD1(L1CORE) should reply in 5 seconds to clear this timer */  
        kal_set_timer(cc_irq_sync_ping_md1_ack_timer_id, cc_irq_sync_ping_md1_ack_timer_cb, NULL, KAL_TICKS_5_SEC, 0);	
        ASSERT(cc_sys_comm_tx_polling(cc_irq_sync_tx_md1_cc_sys_comm, CC_IRQ_SYNC_PKT_TYPE_PING, glb_time_stamp)==CC_SYS_COMM_SUCCESS);
    
        /* log */
        dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_PING_TX_L1core, glb_time_stamp);
        cc_irq_sync_tx_md1_time[cc_irq_sync_tx_md1_time_index] = CC_IRQ_GET_GLB_TS();
        cc_irq_sync_tx_md1_time_index = (cc_irq_sync_tx_md1_time_index + 1) % CC_IRQ_SYNC_LOG_MAX;
    }

}
#endif

/*------------------------------------------------------------------------
 * void cc_irq_sync_hisr_rx_md1
 * Purpose:	    The HISR function when receiving a CC SYS SYNC pkt from MD1, 
 *              the ISR flow is cc_irq_lisr(kal_uint32 irqx)-->cc_sys_comm_lisr()-->cc_sys_comm_hisr()-->cc_irq_sync_hisr_rx_md1()
 * Parameters:
 *    Input:	
 *              kal_uint32 pkt_type: The packet type in CC_SYS_SYNC_PKT_TYPE_T.
 *              kal_uint32 glb_time_stamp: global time stamp. 
 *    Output:	None
 * returns :	None
 * Note    :    This function is running in HISR.Due to there are no state between PSCORE and L1CORE, 
 *              this function is seperated from "cc_irq_sync_hisr_rx_md3".
 *------------------------------------------------------------------------
 */
void cc_irq_sync_hisr_rx_md1(kal_uint32 pkt_type, kal_uint32 glb_time_stamp)
{
    kal_uint32  cur_glb_ts = CC_IRQ_GET_GLB_TS();

    switch (pkt_type)
    {
        case CC_IRQ_SYNC_PKT_TYPE_INIT_HS1:
        /* start polling */   
    #if defined(__PCORE__)/* polling L1CORE */	
            dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_RX_L1core_INIT_HS1, cur_glb_ts, glb_time_stamp);		
            ASSERT(cc_irq_sync_ping_md1_timer_id);
            ASSERT(cc_irq_sync_ping_md1_ack_timer_id);
            /* polling L1CORE every 10 seconds */
            kal_set_timer(cc_irq_sync_ping_md1_timer_id, cc_irq_sync_ping_md1_timer_cb, NULL, KAL_TICKS_5_SEC * 2, KAL_TICKS_5_SEC * 2);					
    #else/* L1CORE*//* receive PScore's polling in 15 sec */
            dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_STATE_RX_PScore_INIT_HS1, cur_glb_ts, glb_time_stamp);	
            ASSERT(cc_irq_sync_rx_md1_ping_timer_id);
            kal_set_timer(cc_irq_sync_rx_md1_ping_timer_id, cc_irq_sync_ping_md1_ack_timer_cb, NULL, KAL_TICKS_5_SEC * 3, 0);  
    #endif 
          break; 
	
#if defined(__PCORE__)/* PScore receive ping ack from L1CORE */
        case CC_IRQ_SYNC_PKT_TYPE_PING_ACK:
            /* cancel timer for ack timeout */
            kal_cancel_timer(cc_irq_sync_ping_md1_ack_timer_id);
            	
            /* log */
            dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_ACK_RX_L1core, cur_glb_ts , glb_time_stamp);
            cc_irq_sync_rx_md1_time[cc_irq_sync_rx_md1_time_index] = cur_glb_ts;
            cc_irq_sync_rx_md1_time_index = (cc_irq_sync_rx_md1_time_index + 1) % CC_IRQ_SYNC_LOG_MAX;	
          break; 
#else/* L1CORE receive ping pkt from PSCORE*/
        case CC_IRQ_SYNC_PKT_TYPE_PING:
            /* receive ping from PScore, reset timeout timer and reply */
            cc_irq_sync_rx_md1_time[cc_irq_sync_rx_md1_time_index] = cur_glb_ts;
            cc_irq_sync_rx_md1_time_index = (cc_irq_sync_rx_md1_time_index + 1) % CC_IRQ_SYNC_LOG_MAX;
			
            /* restart timer for rx ping timeout */
            kal_cancel_timer(cc_irq_sync_rx_md1_ping_timer_id);
            kal_set_timer(cc_irq_sync_rx_md1_ping_timer_id, cc_irq_sync_ping_md1_ack_timer_cb, NULL, KAL_TICKS_5_SEC * 3, 0);

            /* reply */
            ASSERT(cc_sys_comm_tx_polling(cc_irq_sync_tx_md1_cc_sys_comm, CC_IRQ_SYNC_PKT_TYPE_PING_ACK, CC_IRQ_GET_GLB_TS())==CC_SYS_COMM_SUCCESS);				

            /* log */
            dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_ACK_TX_PScore, cur_glb_ts);
	
          break;
#endif
        default:/* There is no CC_IRQ_SYNC_PKT_TYPE_INIT_HS2 between PScore and L1core due to they would enter scheduler together. */
          EXT_ASSERT(0, pkt_type, 0, 0);
          break;	        
    }		
    
}

/*------------------------------------------------------------------------
 * void    cc_irq_sync_init
 * Purpose:	    create MD1 and MD3 synchronous function timers and register call back function 
 *              
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	None
 * Note    :    None.
 *------------------------------------------------------------------------
 */
void cc_irq_sync_init()
{
    kal_int32  ret;

    /* register CC SYS SYNC channel */
    ret = cc_sys_comm_channel_init(cc_irq_sync_rx_md1_cc_sys_comm, cc_irq_sync_hisr_rx_md1);
    ASSERT(CC_SYS_COMM_SUCCESS == ret);

#if defined(__PCORE__)    
    /* init timer id */    
    cc_irq_sync_ping_md1_timer_id    = kal_create_timer("CC_PING_MD1_TIMER");
    cc_irq_sync_ping_md1_ack_timer_id = kal_create_timer("CC_MD1_ACK_TIMER");

#else /* L1core */	
    cc_irq_sync_rx_md1_ping_timer_id = kal_create_timer("CC_RX_MD1_PING_TIMER");
#endif

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
    if(CC_IRQ_MD3_IS_EXIST())/* only init MD3 parameters when MD3 exist */
    {
        /* register CC SYS SYNC channel */
        ret = cc_sys_comm_channel_init(cc_irq_sync_rx_md3_cc_sys_comm, cc_irq_sync_hisr_rx_md3);
        ASSERT(CC_SYS_COMM_SUCCESS == ret);
    
  #if defined(__PCORE__)    
        /* init timer id */    
        cc_irq_sync_ping_md3_timer_id    = kal_create_timer("CC_PING_MD3_TIMER");
        cc_irq_sync_ping_md3_ack_timer_id = kal_create_timer("CC_MD3_ACK_TIMER");
    
        kal_uint32 i;
        for(i=0; i<CC_IRQ_SYNC_TX_MD3_USER_CB_NUMBER; i++)
        {
            if(cc_irq_sync_tx_md3_user_cb[i] == NULL )    
            {cc_irq_sync_tx_md3_user_cb[i] = cc_irq_sync_default_user_cb;}
        }
    
        for(i=0; i<CC_IRQ_SYNC_RX_MD3_USER_CB_NUMBER; i++)
        {
            if(cc_irq_sync_rx_md3_user_cb[i] == NULL )    
            {cc_irq_sync_rx_md3_user_cb[i] = cc_irq_sync_default_user_cb;}
        }
  #else /* L1core */	
        /* Due to there is no L4 on L1core, we should register a fake call back function to avoid error when receive EPOF from MD3. */
        cc_sys_comm_channel_init(CC_SYS_COMM_MD32L_EPOF_NOTIFICATION, cc_irq_sync_epof_user_cb);
  #endif
    
    }
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

}

/*------------------------------------------------------------------------
 * kal_uint32 cc_irq_sync_get_cc_irq_tx_md1_status()
 * Purpose:	    Get the CC IRQ status about tx to MD1(PScore/L1CORE). The status about tx to MD1(PScore/L1CORE) is enable default, it would change to disable when 
 *              the other core starting EPOF flow.
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	KAL_TRUE/KAL_FALSE
 * Note    :    None
 *------------------------------------------------------------------------
 */
__attribute__ ((section ("INTSRAM_ROCODE")))
kal_uint32 cc_irq_sync_get_cc_irq_tx_md1_status()
{
    /* When we are PSCORE, return the TX state to L1CORE. 
       When we are L1CORE, return the TX state to PSCORE. */	
    return cc_irq_sync_cc_irq_tx_md1_status;
}

/*****************************************************************************
 * Public Function for MD1                                                   *
 *****************************************************************************/
/*------------------------------------------------------------------------
 * void    cc_irq_sync_init_HS1()
 * Purpose:	    PScore: Send HS1 packet to MD3 and L1core
 *              L1core: Send HS1 packet to PScore
 *              
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	None
 * Note    :    
 *------------------------------------------------------------------------
 */
void cc_irq_sync_init_HS1()
{
  kal_uint32  glb_time_stamp;

  glb_time_stamp = CC_IRQ_GET_GLB_TS();
	
#if defined(__PCORE__)
  #if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
  /* below for MD3 -------------------------------------------------- */

    if(!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, return directly */
       return;
		
    ASSERT(cc_sys_comm_tx_polling(cc_irq_sync_tx_md3_cc_sys_comm, CC_IRQ_SYNC_PKT_TYPE_INIT_HS1, glb_time_stamp)==CC_SYS_COMM_SUCCESS);
  /* up for MD3    -------------------------------------------------- */
  #endif/*_MD3_SUPPORT_*/

  /* PScore send HS1 to L1core */
  ASSERT(cc_sys_comm_tx_polling(cc_irq_sync_tx_md1_cc_sys_comm, CC_IRQ_SYNC_PKT_TYPE_INIT_HS1, glb_time_stamp)==CC_SYS_COMM_SUCCESS);

#else/*L1core*/

  /* L1core send HS1 to PScore */
  ASSERT(cc_sys_comm_tx_polling(cc_irq_sync_tx_md1_cc_sys_comm, CC_IRQ_SYNC_PKT_TYPE_INIT_HS1, glb_time_stamp)==CC_SYS_COMM_SUCCESS);

#endif
}

/*------------------------------------------------------------------------
 * void cc_irq_sync_disable_cc_irq_tx_md1()
 * Purpose:     If we are PSCORE, we wolud call this function to disable tx CC IRQ to L1CORE. 
 *              If we are L1CORE, we wolud call this function to disable tx CC IRQ to PSCORE.
 *              
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	None
 * Note    :    None 
 *------------------------------------------------------------------------
 */
void cc_irq_sync_disable_cc_irq_tx_md1()
{

    /* CC IRQ don't need to stop polling timer here since we already use "OSTD_Infinite_Sleep_Query()" to check the CC SYS polling function should work or not. */
    cc_irq_sync_cc_irq_tx_md1_status = KAL_FALSE;

}

#endif //defined(__PCORE_ONLY__) || defined(__L1CORE_ONLY__)
