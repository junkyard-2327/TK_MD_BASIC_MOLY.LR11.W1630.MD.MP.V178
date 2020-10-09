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
 *   cc_irq_sys_comm.c
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This Module defines CC SYS IRQ API(for MD1<->MD3 and PScore<->L1core).
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
#include "cc_sys_comm_int.h"
#include "cc_irq_trace.h" 

#define CC_SYS_COMM_USED_BUFF(read_index, write_index)                 (((write_index) >= (read_index)) ? ((write_index) - (read_index)) : (CC_SYS_COMM_BUFF_MAX - (read_index) + (write_index)))
#define CC_SYS_COMM_IS_USED_BUFF_OVER_THRE(read_index, write_index)    (CC_SYS_COMM_USED_BUFF((read_index), (write_index)) >= CC_SYS_COMM_RX_THRESHOLD)
#define CC_SYS_COMM_IS_BUFF_FULL(read_index, write_index)              (((write_index) + 1) % CC_SYS_COMM_BUFF_MAX == (read_index))
#define CC_SYS_COMM_IS_BUFF_EMPTY(read_index, write_index)             ((read_index) == (write_index))
#define CC_SYS_COMM_CB_LISR()                                      KAL_FALSE 



#if defined(__PCORE_ONLY__) || defined(__L1CORE_ONLY__)

void cc_sys_comm_hisr() {};
kal_int32 cc_sys_comm_tx(kal_uint32 comm_id, kal_uint32 para0, kal_uint32 para1) {return 0;}
kal_int32 cc_sys_comm_tx_polling(kal_uint32 comm_id, kal_uint32 para0, kal_uint32 para1) {return 0;}
void cc_sys_comm_init() {}
kal_int32 cc_sys_comm_channel_init(kal_uint32 comm_id, CC_IRQ_SYS_CALLBACK_P funcp) {return 0;}
kal_int32 cc_sys_comm_channel_deinit(kal_uint32 comm_id) {return 0;}

#else

kal_hisrid            cc_sys_comm_hisrid;
cc_sys_comm_buff_t    cc_sys_comm_rx_md1_buff[CC_SYS_COMM_BUFF_MAX]; /* CC SYS LISR would put data in this buffer, and retrieve in HISR*/
CC_IRQ_SYS_CALLBACK_P cc_sys_comm_rx_md1_cb[CC_SYS_COMM_RX_MD1_NUMBER]; /* call back function for different CC SYS user(comm_id)*/
volatile kal_uint32   cc_sys_comm_rx_md1_buff_read_index, cc_sys_comm_rx_md1_buff_write_index;
                                                                    
#if defined(__PCORE__)
kal_uint32 const cc_sys_comm_tx_md1_cc_index = CC_IRQ_P2L_SYS;
kal_uint32 const cc_sys_comm_rx_md1_cc_index = CC_IRQ_L2P_SYS;
#else
kal_uint32 const cc_sys_comm_tx_md1_cc_index = CC_IRQ_L2P_SYS;
kal_uint32 const cc_sys_comm_rx_md1_cc_index = CC_IRQ_P2L_SYS;
#endif

CC_SYS_COMM_HISR_LOG_T cc_sys_comm_rx_md1_hisr_log[CC_SYS_COMM_LOG_MAX];
kal_uint32 cc_sys_comm_rx_md1_hisr_log_index = 0;
cc_sys_comm_shared_buff_ctrl_t *cc_sys_comm_tx_md1_ctrl_p, *cc_sys_comm_rx_md1_ctrl_p; /* point to cc_sys_comm_p2l and cc_sys_comm_l2p, for flow ctrl*/
CC_SYS_COMM_ID_MASTER_T CC_SYS_COMM_ID_MASTER_T_debugging;/* for debugging use */

DEFINE_NC_SHARED_VAR(cc_sys_comm_shared_buff_ctrl_t, cc_sys_comm_p2l)
DEFINE_NC_SHARED_VAR(cc_sys_comm_shared_buff_ctrl_t, cc_sys_comm_l2p)

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
//kal_hisrid            cc_sys_comm_md3_hisrid;
cc_sys_comm_buff_t    cc_sys_comm_rx_md3_buff[CC_SYS_COMM_BUFF_MAX];/* CC SYS LISR would put data in this buffer, and retrieve in HISR*/
CC_IRQ_SYS_CALLBACK_P cc_sys_comm_rx_md3_cb[CC_SYS_COMM_RX_MD3_NUMBER];/* call back function for different CC SYS user(comm_id)*/
volatile kal_uint32   cc_sys_comm_rx_md3_buff_read_index, cc_sys_comm_rx_md3_buff_write_index;
                                                                    
#if defined(__PCORE__)
kal_uint32 const cc_sys_comm_tx_md3_cc_index = CC_IRQ_P2MD3_SYS;
kal_uint32 const cc_sys_comm_rx_md3_cc_index = CC_IRQ_MD32P_SYS;
#else
kal_uint32 const cc_sys_comm_tx_md3_cc_index = CC_IRQ_L2MD3_SYS;
kal_uint32 const cc_sys_comm_rx_md3_cc_index = CC_IRQ_MD32L_SYS;
#endif

CC_SYS_COMM_HISR_LOG_T cc_sys_comm_rx_md3_hisr_log[CC_SYS_COMM_LOG_MAX];
kal_uint32 cc_sys_comm_rx_md3_hisr_log_index = 0;
cc_sys_comm_shared_buff_ctrl_t *cc_sys_comm_tx_md3_ctrl_p, *cc_sys_comm_rx_md3_ctrl_p;/* point to cc_sys_comm_x2md3 and cc_sys_comm_md32x, for flow ctrl*/
	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

//- called at TX side
static kal_uint32 cc_sys_comm_is_rx_busy(kal_uint32 cc_index)
{/* when TX, check we could send or not (maybe the other core is buffer full)*/
    if (cc_irq_param_channel_full(cc_index))
    {
        return KAL_TRUE;
    }

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */		
    if(CC_IRQ_TX_TO_MD3(cc_index))
    {/* TX to MD3 */
        if (cc_sys_comm_tx_md3_ctrl_p->flow_ctrl_enable)
        {
            return KAL_TRUE;
        }     
    }   
    else	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* TX to MD1 */
        if (cc_sys_comm_tx_md1_ctrl_p->flow_ctrl_enable)
        {
            return KAL_TRUE;
        }    
    } 
    
    return KAL_FALSE;
}

static kal_uint32 cc_sys_comm_id_to_cc_index(kal_uint32 comm_id)
{/* When TX, convert comm_id to MD1/MD3 CC SYS cc_index */

    /* the range of comm_id should be check before calling this function */

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */		
    if(CC_SYS_COMM_TX_TO_MD3(comm_id))
    {/* TX to MD3 */
        return cc_sys_comm_tx_md3_cc_index;    
    }   
    else	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* TX to MD1 */
        return cc_sys_comm_tx_md1_cc_index;   
    } 
}

static kal_uint32 cc_sys_comm_id_to_error_code_1(kal_uint32 comm_id)
{/* convert comm_id to MD1/MD3 error code 1 */

    /* the range of comm_id should be check before calling this function */

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */		
    if(CC_SYS_COMM_TX_TO_MD3(comm_id))
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

static kal_int32 cc_sys_comm_do_tx(kal_uint32 comm_id, kal_uint32 para0, kal_uint32 para1, kal_uint32 polling_time)
{
    kal_uint32        savedMask;
    kal_uint32        start_time, current_time, dur, error_code_1;
    kal_uint32        tx_cnt = 0;
    kal_uint32        cc_index;
    kal_int32         ret;

extern kal_uint32 const cc_irq_sync_tx_md1_cc_sys_comm;
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */		
extern kal_uint32 const cc_irq_sync_tx_md3_cc_sys_comm;
    /* we limit the CC SYS IRQ only could be use after systemInit except CC SYNC comm_id. */    
    if (comm_id != cc_irq_sync_tx_md3_cc_sys_comm && comm_id != cc_irq_sync_tx_md1_cc_sys_comm && kal_query_systemInit() == KAL_TRUE )
        return CC_SYS_COMM_TX_CALLED_DURING_INIT;
/* up for MD3    -------------------------------------------------- */
#else /* there is no MD3 */	
    /* we limit the CC SYS IRQ only could be use after systemInit except CC SYNC comm_id. */    
    if (comm_id != cc_irq_sync_tx_md1_cc_sys_comm && kal_query_systemInit() == KAL_TRUE  )
        return CC_SYS_COMM_TX_CALLED_DURING_INIT;
#endif/*_MD3_SUPPORT_*/

    if (!CC_SYS_COMM_TX_IS_IN_RANGE(comm_id))
        EXT_ASSERT(0, comm_id, para0, para1);

    /* dispatch CC SYS to MD1/MD3*/
    cc_index = cc_sys_comm_id_to_cc_index(comm_id);

    start_time = CC_IRQ_GET_US();
    while(1)
    {
        savedMask = SaveAndSetIRQMask();

        if (cc_sys_comm_is_rx_busy(cc_index) == KAL_FALSE)
        {/* we could send */
      
            ret = cc_irq_trigger_interrupt(cc_index, para0, para1, comm_id);

            RestoreIRQMask(savedMask);
			
            if(ret == CC_IRQ_ERR_PEER_ASYNC)
            {/* print log and ignore*/
            /* Platform-dependent */
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */		
                if(CC_SYS_COMM_TX_TO_MD3(comm_id))
                {/* TX to MD3 */
                    dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_ASYNC_MD3, comm_id, para0, para1, CC_IRQ_GET_GLB_TS());    
                }   
                else	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
                {/* TX to MD1 */
                    dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_SYS_ASYNC_MD1, comm_id, para0, para1, CC_IRQ_GET_GLB_TS());   
                }    
            }
            else
            {
                EXT_ASSERT(ret == CC_IRQ_SUCCESS, cc_index, comm_id, ret);            
            }
			
            break;
        }
        else
        {/* we could not send, the other core is buffer full. polling or assert directly */
            current_time = CC_IRQ_GET_US();
            RestoreIRQMask(savedMask);
            
            /* TX channel is not available */
            if (polling_time == CC_IRQ_SYS_TX_POLLING_DISABLE)
            {
                error_code_1 = cc_sys_comm_id_to_error_code_1(comm_id);
                kal_fatal_error_handler(error_code_1, CC_IRQ_PEER_NO_RESPONSE_TX);/* channel full */            
            }

            /* TX timeout */
            CC_IRQ_GET_DURATION_US(start_time, current_time, dur);
            if (dur > polling_time)
            {
                tx_cnt++;
                if (tx_cnt == 10)/* avoid context switch out and timeout, so we try many times to confirm */
                {
                    error_code_1 = cc_sys_comm_id_to_error_code_1(comm_id);                
                    kal_fatal_error_handler(error_code_1, CC_IRQ_PEER_NO_RESPONSE_TX);/* channel full */
                }
            }
        }
    }

    return CC_SYS_COMM_SUCCESS;
}

/*------------------------------------------------------------------------
 * void         cc_sys_comm_lisr
 * Purpose:	The call back function when receive CC SYS IRQ, this function would be call in LISR
 *              CC SYS IRQ ==> cc_irq_lisr(kal_uint32 irqx) ==> cc_sys_comm_lisr(kal_uint32 p0, kal_uint32 p1, kal_uint32 comm_id)==> cc_sys_comm_hisr()
 * Parameters:
 *    Input:	kal_uint32 para0~para1: Parameters to another core.
 *              kal_uint32 comm_id: CC_SYS_COMM_ID_MASTER_T in "global_cc_sys_comm_id.h", 
 *              use to determine the user call back function for CC SYS IRQ this time.
 *    Output:	None
 * returns :	None
 * Note    :    This function could receive CC SYS IRQ service from MD1 and MD3
 *------------------------------------------------------------------------
 */
static void cc_sys_comm_lisr(kal_uint32 p0, kal_uint32 p1, kal_uint32 comm_id)
{
    kal_uint32 current_write, comm_id_offset;
    //kal_uint32   cc_index;
    volatile kal_uint32   *cc_sys_comm_buff_read_index_ptr, *cc_sys_comm_buff_write_index_ptr;	
    cc_sys_comm_shared_buff_ctrl_t *cc_sys_comm_rx_ctrl_p_ptr;
    cc_sys_comm_buff_t    *cc_sys_comm_buff_ptr;	

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/	
    if (!CC_SYS_COMM_RX_FROM_MD1(comm_id)&&!CC_SYS_COMM_RX_FROM_MD3(comm_id))
        EXT_ASSERT(0, comm_id, 0, 0);
#else /* only MD1 */
    if (!CC_SYS_COMM_RX_FROM_MD1(comm_id))
        EXT_ASSERT(0, comm_id, 0, 0);
#endif

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */		
    if(CC_SYS_COMM_RX_FROM_MD3(comm_id))
    {/* RX from MD3 */
        comm_id_offset = CC_SYS_COMM_RX_MD3_OFFSET(comm_id);
        cc_sys_comm_buff_read_index_ptr = &cc_sys_comm_rx_md3_buff_read_index;
        cc_sys_comm_buff_write_index_ptr = &cc_sys_comm_rx_md3_buff_write_index;
        //cc_index = cc_sys_comm_rx_md3_cc_index;
        cc_sys_comm_rx_ctrl_p_ptr = cc_sys_comm_rx_md3_ctrl_p;
        cc_sys_comm_buff_ptr = cc_sys_comm_rx_md3_buff;		
    }   
    else	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* RX from MD1 */
        comm_id_offset = CC_SYS_COMM_RX_MD1_OFFSET(comm_id);  
        cc_sys_comm_buff_read_index_ptr = &cc_sys_comm_rx_md1_buff_read_index;
        cc_sys_comm_buff_write_index_ptr = &cc_sys_comm_rx_md1_buff_write_index;		
        //cc_index = cc_sys_comm_rx_md1_cc_index; 
        cc_sys_comm_rx_ctrl_p_ptr = cc_sys_comm_rx_md1_ctrl_p;
        cc_sys_comm_buff_ptr = cc_sys_comm_rx_md1_buff;		
    }

    /* callback is handled in LISR */
    if (CC_SYS_COMM_CB_LISR() == KAL_TRUE)
    {/* not enter here */
        if (cc_sys_comm_rx_md1_cb[comm_id_offset] == NULL)
            EXT_ASSERT(0, comm_id, comm_id_offset, 0);
        
        cc_sys_comm_rx_md1_cb[comm_id_offset](p0, p1);
    }
    /* callback is handled in HISR now */
    else
    {/* the user call back function would be called in HISR */
        /* check whether buff is full */
        if (CC_SYS_COMM_IS_BUFF_FULL(*cc_sys_comm_buff_read_index_ptr, *cc_sys_comm_buff_write_index_ptr))
        {/* local buffer full==> assert */
            EXT_ASSERT(0, comm_id, *cc_sys_comm_buff_read_index_ptr, *cc_sys_comm_buff_write_index_ptr);
        }
        else
        {/* local buffer is not full==> flow control check */
            /* if free buffer is overthreshold, mask it until HISR process the pended buffer */
            if(CC_SYS_COMM_IS_USED_BUFF_OVER_THRE(*cc_sys_comm_buff_read_index_ptr, *cc_sys_comm_buff_write_index_ptr))
            {           
                //cc_irq_mask(cc_index); /* now is in LISR and use flow_ctrl_enable to stop TX */
                cc_sys_comm_rx_ctrl_p_ptr->flow_ctrl_enable = 1;
                CC_IRQ_DMB();				
            }
            /* put received data to local buffer */
            current_write = *cc_sys_comm_buff_write_index_ptr;
            cc_sys_comm_buff_ptr[current_write].comm_id = comm_id;
            cc_sys_comm_buff_ptr[current_write].data[0] = p0;
            cc_sys_comm_buff_ptr[current_write].data[1] = p1;
            cc_sys_comm_buff_ptr[current_write].dbg_rx_global_ts = CC_IRQ_GET_GLB_TS();

            *cc_sys_comm_buff_write_index_ptr = (current_write + 1) % CC_SYS_COMM_BUFF_MAX;
        }           

#if defined(__CC_IRQ_DRV_HISR__)
        drv_active_hisr(DRV_CC_IRQ_SYS_HISR_ID);
#else
        kal_activate_hisr(cc_sys_comm_hisrid);/* would execue here */
#endif

    }
}

/* HISR, would be activate in cc_sys_comm_lisr(),this function would read data from local buffer, then call user callback function */
/*------------------------------------------------------------------------
 * void         cc_sys_comm_hisr
 * Purpose:	The HISR function which is activate in "cc_sys_comm_lisr".
 *              CC SYS IRQ ==> cc_irq_lisr(kal_uint32 irqx) ==> cc_sys_comm_lisr(kal_uint32 p0, kal_uint32 p1, kal_uint32 comm_id)==> cc_sys_comm_hisr()
 * Parameters:
 *    Input:	None
 *    Output:	None
 * returns :	None
 * Note    :    This function could receive CC SYS IRQ service from MD1 and MD3
 *------------------------------------------------------------------------
 */
void cc_sys_comm_hisr()
{
    cc_sys_comm_buff_t *buff;
    kal_uint32        current_read, comm_id_offset;

//    cc_irq_mask(cc_sys_comm_rx_md1_cc_index);

    /* for MD1's data */                             
    while(!CC_SYS_COMM_IS_BUFF_EMPTY(cc_sys_comm_rx_md1_buff_read_index, cc_sys_comm_rx_md1_buff_write_index))
    {
        current_read = cc_sys_comm_rx_md1_buff_read_index;
        buff = &cc_sys_comm_rx_md1_buff[current_read];

        if (!CC_SYS_COMM_RX_FROM_MD1(buff->comm_id))
            EXT_ASSERT(0, buff->comm_id, 0, 0);

        comm_id_offset = CC_SYS_COMM_RX_MD1_OFFSET(buff->comm_id);

        if (NULL == cc_sys_comm_rx_md1_cb[comm_id_offset])
            EXT_ASSERT(0, buff->comm_id, comm_id_offset, 0);

        cc_sys_comm_rx_md1_hisr_log[cc_sys_comm_rx_md1_hisr_log_index].user_call_back = (kal_uint32)cc_sys_comm_rx_md1_cb[comm_id_offset];        
        cc_sys_comm_rx_md1_hisr_log[cc_sys_comm_rx_md1_hisr_log_index].start_time = CC_IRQ_GET_US();
        cc_sys_comm_rx_md1_cb[comm_id_offset](buff->data[0], buff->data[1]);/* call related user call back function */
        cc_sys_comm_rx_md1_hisr_log[cc_sys_comm_rx_md1_hisr_log_index].end_time = CC_IRQ_GET_US();
        cc_sys_comm_rx_md1_hisr_log_index = (cc_sys_comm_rx_md1_hisr_log_index + 1) % CC_SYS_COMM_LOG_MAX;

        cc_sys_comm_rx_md1_buff_read_index = (current_read + 1) % CC_SYS_COMM_BUFF_MAX;
    }
    cc_irq_mask(cc_sys_comm_rx_md1_cc_index); /* avoid race condition from LISR */
    cc_sys_comm_rx_md1_ctrl_p->flow_ctrl_enable = 0;
    CC_IRQ_DMB(); /* avoid race condition */
    cc_irq_unmask(cc_sys_comm_rx_md1_cc_index);

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
    if(CC_IRQ_MD3_IS_EXIST())/* only process MD3 parameters when MD3 exist */
    {
        /* for MD3's data */ 
        while(!CC_SYS_COMM_IS_BUFF_EMPTY(cc_sys_comm_rx_md3_buff_read_index, cc_sys_comm_rx_md3_buff_write_index))
        {
            current_read = cc_sys_comm_rx_md3_buff_read_index;
            buff = &cc_sys_comm_rx_md3_buff[current_read];
    
            if (!CC_SYS_COMM_RX_FROM_MD3(buff->comm_id))
                EXT_ASSERT(0, buff->comm_id, 0, 0);
    
            comm_id_offset = CC_SYS_COMM_RX_MD3_OFFSET(buff->comm_id);
    
            if (NULL == cc_sys_comm_rx_md3_cb[comm_id_offset])
                EXT_ASSERT(0, buff->comm_id, comm_id_offset, 0);

            cc_sys_comm_rx_md3_hisr_log[cc_sys_comm_rx_md3_hisr_log_index].user_call_back = (kal_uint32)cc_sys_comm_rx_md3_cb[comm_id_offset];             
            cc_sys_comm_rx_md3_hisr_log[cc_sys_comm_rx_md3_hisr_log_index].start_time = CC_IRQ_GET_US();

            /* Process EPOF Notification from MD3 */
            if(CC_SYS_COMM_RX_MD3_EPOF_NOTIFICATION(buff->comm_id))
            {
                cc_irq_sync_process_epof_from_md3();
            }
			
            cc_sys_comm_rx_md3_cb[comm_id_offset](buff->data[0], buff->data[1]);/* call related user call back function */
            cc_sys_comm_rx_md3_hisr_log[cc_sys_comm_rx_md3_hisr_log_index].end_time = CC_IRQ_GET_US();
            cc_sys_comm_rx_md3_hisr_log_index = (cc_sys_comm_rx_md3_hisr_log_index + 1) % CC_SYS_COMM_LOG_MAX;
    
            cc_sys_comm_rx_md3_buff_read_index = (current_read + 1) % CC_SYS_COMM_BUFF_MAX;
        }
        cc_irq_mask(cc_sys_comm_rx_md3_cc_index); /* avoid race condition from LISR */
        cc_sys_comm_rx_md3_ctrl_p->flow_ctrl_enable = 0;
        CC_IRQ_DMB();/* avoid race condition */
        cc_irq_unmask(cc_sys_comm_rx_md3_cc_index);
    }	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
	
}

/*------------------------------------------------------------------------
 * kal_int32    cc_sys_comm_tx
 * Purpose:	Trigger CC SYS interrupt and send parameter to the specify call back function on receiver core. If send fail, assert immediately.
  * Parameters:
 *    Input:	kal_uint32 comm_id: CC_SYS_COMM_ID_MASTER_T in "global_cc_sys_comm_id.h", 
 *              determine the comm_id trigger to whom by CC SYS IRQ and its shift index.
 *              kal_uint32 para0~para1: Parameters to another core.
 *    Output:	None
 * returns :	CC_SYS_COMM_SUCCESS/CC_SYS_COMM_TX_CALLED_DURING_INIT
 * Note    :    This function could trigger CC SYS IRQ service with specified comm_id to MD1 or MD3.
 *              User should check the return value.
 *------------------------------------------------------------------------
 */
kal_int32 cc_sys_comm_tx(kal_uint32 comm_id, kal_uint32 para0, kal_uint32 para1)
{
    return cc_sys_comm_do_tx(comm_id, para0, para1, CC_IRQ_SYS_TX_POLLING_DISABLE);
}

/*------------------------------------------------------------------------
 * kal_int32    cc_sys_comm_tx_polling
 * Purpose:	Trigger CC SYS interrupt and send parameter to the specify call back function on receiver core. If send fail, polling in 100 us and assert.
  * Parameters:
 *    Input:	kal_uint32 comm_id: CC_SYS_COMM_ID_MASTER_T in "global_cc_sys_comm_id.h", 
 *              determine the comm_id trigger to whom by CC SYS IRQ and its shift index.
 *              kal_uint32 para0~para1: Parameters to another core.
 *    Output:	None
 * returns :	CC_SYS_COMM_SUCCESS/CC_SYS_COMM_TX_CALLED_DURING_INIT
 * Note    :    This function could trigger CC SYS IRQ service with specified comm_id to MD1 or MD3.
 *              User should check the return value.
 *------------------------------------------------------------------------
 */
kal_int32 cc_sys_comm_tx_polling(kal_uint32 comm_id, kal_uint32 para0, kal_uint32 para1)
{
    return cc_sys_comm_do_tx(comm_id, para0, para1, CC_IRQ_SYS_TX_TIMEOUT);
}

/*------------------------------------------------------------------------
 * kal_int32    cc_sys_comm_init
 * Purpose:		initialize MD1 MD3 cc sys communication pointer and parameters, register call back function 
 *              
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	None
 * Note    :    None.
 *------------------------------------------------------------------------
 */
void cc_sys_comm_init()
{
    /* IRQ configuratin */
    cc_irq_register_callback(cc_sys_comm_rx_md1_cc_index, cc_sys_comm_lisr);
    cc_irq_unmask(cc_sys_comm_rx_md1_cc_index);

    cc_sys_comm_rx_md1_buff_read_index  = 0;
    cc_sys_comm_rx_md1_buff_write_index = 0;

#if defined(__PCORE__)
    SHARED_VAR(cc_sys_comm_l2p).flow_ctrl_enable = 0;    
    cc_sys_comm_tx_md1_ctrl_p = SHARED_pVAR(cc_sys_comm_p2l);
    cc_sys_comm_rx_md1_ctrl_p = SHARED_pVAR(cc_sys_comm_l2p);
#else
    SHARED_VAR(cc_sys_comm_p2l).flow_ctrl_enable = 0;    
    cc_sys_comm_tx_md1_ctrl_p = SHARED_pVAR(cc_sys_comm_l2p);
    cc_sys_comm_rx_md1_ctrl_p = SHARED_pVAR(cc_sys_comm_p2l);
#endif

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    if(CC_IRQ_MD3_IS_EXIST())/* only init MD3 parameters when MD3 exist */
    {
        /* IRQ configuratin */
        cc_irq_register_callback(cc_sys_comm_rx_md3_cc_index, cc_sys_comm_lisr);
        cc_irq_unmask(cc_sys_comm_rx_md3_cc_index);
    
        cc_sys_comm_rx_md3_buff_read_index  = 0;
        cc_sys_comm_rx_md3_buff_write_index = 0;
    
    #if defined(__PCORE__)
        cc_sys_comm_tx_md3_ctrl_p = (cc_sys_comm_shared_buff_ctrl_t *)cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_PS2MD3_CCSYS_FLOW_CTRL, sizeof(cc_sys_comm_shared_buff_ctrl_t)); /* cc_sys_comm_tx_md3_ctrl_p means tx to md3 ==> cc_sys_comm_p2md3 */
        cc_sys_comm_rx_md3_ctrl_p = (cc_sys_comm_shared_buff_ctrl_t *)cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_MD32PS_CCSYS_FLOW_CTRL, sizeof(cc_sys_comm_shared_buff_ctrl_t)); /* cc_sys_comm_rx_md3_ctrl_p means rx from md3 ==> cc_sys_comm_md32p */	
        cc_sys_comm_tx_md3_ctrl_p->flow_ctrl_enable = 0;/* due to the other core may boot up later, we init it to 0 to let us can send HS1 */
    #else
        cc_sys_comm_tx_md3_ctrl_p = (cc_sys_comm_shared_buff_ctrl_t *)cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_L12MD3_CCSYS_FLOW_CTRL, sizeof(cc_sys_comm_shared_buff_ctrl_t)); /* cc_sys_comm_tx_md3_ctrl_p means tx to md3 ==> cc_sys_comm_l2md3 */
        cc_sys_comm_rx_md3_ctrl_p = (cc_sys_comm_shared_buff_ctrl_t *)cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_MD32L1_CCSYS_FLOW_CTRL, sizeof(cc_sys_comm_shared_buff_ctrl_t)); /* cc_sys_comm_rx_md3_ctrl_p means rx from md3 ==> cc_sys_comm_md32l */	
        cc_sys_comm_tx_md3_ctrl_p->flow_ctrl_enable = 0;/* due to the other core may boot up later, we init it to 0 to let us can send HS1 */
    #endif
    
        /* CC ILM between MD1/MD3 */
        cc_irq_msg_init();
    
        /* CC RPC between MD1/MD3 */
    	cc_irq_rpc_init();
    
    }	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

    /* CC SYS SYNC between PScore/L1core and MD1/MD3 */
    cc_irq_sync_init();

#if defined(__CC_IRQ_DRV_HISR__)
    DRV_Register_HISR(DRV_CC_IRQ_SYS_HISR_ID, cc_sys_comm_hisr);
#else
    cc_sys_comm_hisrid = kal_init_hisr(CC_SYS_HISR);/* would execue here */
#endif

}

/*------------------------------------------------------------------------
 * kal_int32    cc_sys_comm_channel_init
 * Purpose:	Register callback function when CC SYS IRQ is triggered with specified comm_id. 
 * Parameters:
 *    Input:	kal_uint32 comm_id: CC_SYS_COMM_ID_MASTER_T in "global_cc_sys_comm_id.h", 
 *              determine the comm_id receive from whom by CC SYS IRQ and its shift index.
 *              CC_IRQ_SYS_CALLBACK_P funcp: callback function when specified comm_id of CC SYS IRQ is triggered.(would be called in HISR)
 *    Output:	None
 * returns :	CC_SYS_COMM_SUCCESS/CC_SYS_COMM_ERR_PARAM
 * Note    :    This function could register call back function for specified comm_id of CC SYS IRQ for MD1 or MD3.
 *              User should check the return value.
 *------------------------------------------------------------------------
 */
kal_int32 cc_sys_comm_channel_init(kal_uint32 comm_id, CC_IRQ_SYS_CALLBACK_P funcp)
{
    kal_uint32        comm_id_offset;

    if (NULL == funcp || !CC_SYS_COMM_RX_IS_IN_RANGE(comm_id))
        return CC_SYS_COMM_ERR_PARAM;

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    kal_uint32 caller_LR;

    GET_RETURN_ADDRESS(caller_LR);
    if(CC_SYS_COMM_RX_FROM_MD3(comm_id))
    {/* Register for MD3 */
        if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
        {
            kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
        }                                                                    
        comm_id_offset = CC_SYS_COMM_RX_MD3_OFFSET(comm_id);
        cc_sys_comm_rx_md3_cb[comm_id_offset] = funcp;    
    }   
    else	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* Register for MD1 */
        comm_id_offset = CC_SYS_COMM_RX_MD1_OFFSET(comm_id);    
        cc_sys_comm_rx_md1_cb[comm_id_offset] = funcp;    
    }

    return CC_SYS_COMM_SUCCESS;
}

/*------------------------------------------------------------------------
 * kal_int32    cc_sys_comm_channel_deinit
 * Purpose:	Cancel callback function when CC SYS IRQ is triggered with specified comm_id. 
 * Parameters:
 *    Input:	kal_uint32 comm_id: CC_SYS_COMM_ID_MASTER_T in "global_cc_sys_comm_id.h", 
 *              determine the comm_id receive from whom by CC SYS IRQ and its shift index.
 *              
 *    Output:	None
 * returns :	CC_SYS_COMM_SUCCESS/CC_SYS_COMM_ERR_PARAM
 * Note    :    This function could cancel call back function for specified comm_id of CC SYS IRQ for MD1 or MD3
 *              User should check the return value.
 *------------------------------------------------------------------------
 */
kal_int32 cc_sys_comm_channel_deinit(kal_uint32 comm_id)
{
    kal_uint32        comm_id_offset;
	
    if (!CC_SYS_COMM_RX_IS_IN_RANGE(comm_id))
        return CC_SYS_COMM_ERR_PARAM;

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */	
    kal_uint32        caller_LR;

    GET_RETURN_ADDRESS(caller_LR);
    if(CC_SYS_COMM_RX_FROM_MD3(comm_id))
    {/* Register for MD3 */
        if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
        {
            kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
        }    
        comm_id_offset = CC_SYS_COMM_RX_MD3_OFFSET(comm_id);
        cc_sys_comm_rx_md3_cb[comm_id_offset] = NULL;    
    }   
    else	
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
    {/* Register for MD1 */
        comm_id_offset = CC_SYS_COMM_RX_MD1_OFFSET(comm_id);    
        cc_sys_comm_rx_md1_cb[comm_id_offset] = NULL;    
    }	

    return CC_SYS_COMM_SUCCESS;
}

#endif    /* defined(__PCORE_ONLY__) || defined(__L1CORE_ONLY__) */
