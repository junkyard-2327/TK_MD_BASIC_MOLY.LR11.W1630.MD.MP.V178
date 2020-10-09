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
 *   cc_irq_rpc.c
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This Module defines CC IRQ Remote Procedure Call API(only for MD1<->MD3 RPC).
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

/* This file only support MD3 */
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */ 

#include "cc_irq_adaptation.h"
#include "dhl_trace.h"
#include "cc_irq_trace.h"

#define CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER     4
#define CC_IRQ_RPC_HISR_TIMEOUT    (40000UL)    /* 40ms, equal to TIMER_HISR_EXECUTION_BOUND */
#define CC_IRQ_RPC_TX_MD3_TIMEOUT  (40000UL)    /* 40ms */

/* Note: this value is the max parameter size user could transport by RPC and it may be the local parameter size in user's RPC callback function.
User's RPC callback function runs in HISR, it would use the call stack of HISR. If you enlarge this size, 
you should make sure the call stack size of "CCHISR"(In pcore_hisr_config_internal.h & l1core_hisr_config_internal.h) is big enough.
For IT test, you should also change "ARRAY_NUM" in cc_irq_it.c*/
#define CC_IRQ_RPC_MD1_MD3_BUFFER_SIZE     1024

#define CC_IRQ_RPC_API_RESP_ID          0xFFFF0000

#define CC_IRQ_RPC_REQUEST          0x11111111
#define CC_IRQ_RPC_REPLY            0x22222222
	
/* PScore and L1core only could require/accept RPC from MD3*/
#if defined(__PCORE__)
#define CC_IRQ_RPC_RX_MD3_REQUEST_OP_IS_IN_RANGE(rpc_opid)                 ((rpc_opid) >= CC_IRQ_RPC_MD32P_BASE && (rpc_opid) < CC_IRQ_RPC_MD32P_END) 
#define CC_IRQ_RPC_TX_MD3_REQUEST_OP_IS_IN_RANGE(rpc_opid)                 ((rpc_opid) >= CC_IRQ_RPC_P2MD3_BASE && (rpc_opid) < CC_IRQ_RPC_P2MD3_END)
#define CC_IRQ_RPC_RX_MD3_REPLY_OP_IS_IN_RANGE(rpc_opid)                 ((rpc_opid) >= CC_IRQ_RPC_P2MD3_BASE && (rpc_opid) < CC_IRQ_RPC_P2MD3_END)

#define CC_IRQ_RPC_RX_MD3_NUMBER    (CC_IRQ_RPC_MD32P_END - CC_IRQ_RPC_MD32P_BASE)
#define CC_IRQ_RPC_TX_MD3_NUMBER    (CC_IRQ_RPC_P2MD3_END - CC_IRQ_RPC_P2MD3_BASE)
#define CC_IRQ_RPC_RX_MD3_OPID_OFFSET(rpc_opid)                  ((rpc_opid) - CC_IRQ_RPC_MD32P_BASE)
  
#elif defined(__L1CORE__)	
#define CC_IRQ_RPC_RX_MD3_REQUEST_OP_IS_IN_RANGE(rpc_opid)                 ((rpc_opid) >= CC_IRQ_RPC_MD32L_BASE && (rpc_opid) < CC_IRQ_RPC_MD32L_END) 
#define CC_IRQ_RPC_TX_MD3_REQUEST_OP_IS_IN_RANGE(rpc_opid)                 ((rpc_opid) >= CC_IRQ_RPC_L2MD3_BASE && (rpc_opid) < CC_IRQ_RPC_L2MD3_END)
#define CC_IRQ_RPC_RX_MD3_REPLY_OP_IS_IN_RANGE(rpc_opid)                 ((rpc_opid) >= CC_IRQ_RPC_L2MD3_BASE && (rpc_opid) < CC_IRQ_RPC_L2MD3_END)

#define CC_IRQ_RPC_RX_MD3_NUMBER    (CC_IRQ_RPC_MD32L_END - CC_IRQ_RPC_MD32L_BASE)
#define CC_IRQ_RPC_TX_MD3_NUMBER    (CC_IRQ_RPC_L2MD3_END - CC_IRQ_RPC_L2MD3_BASE)
#define CC_IRQ_RPC_RX_MD3_OPID_OFFSET(rpc_opid)                  ((rpc_opid) - CC_IRQ_RPC_MD32L_BASE)
  
#endif
	
typedef struct {
    kal_uint32    valid; 
    kal_uint32    rpc_opid;       /* CC_IRQ_RPC_OP_ID_T in "global_cc_rpc_op_id.h" */
    kal_int32     rpc_ret_value;
    kal_uint32    rpc_data_length;/* the valid data length(unit: byte) in rpc_para_buffer. For debugging use.*/	
    kal_uint32    rpc_para_buffer[CC_IRQ_RPC_MD1_MD3_BUFFER_SIZE/sizeof(kal_uint32)];/* 1024/4=256, 4 bytes*256= 1024 bytes */                                                           	                                                                                      
} CC_IRQ_RPC_MD1_MD3_BUFFER_T;	

typedef struct {
    kal_uint32    start_time; /* us */
    kal_uint32    end_time;   /* us */                                                      	                                                                                      
} CC_IRQ_RPC_SERVICE_TIME_T;

#define CC_IRQ_RPC_MD1_MD3_SHARE_MEM_SIZE    (sizeof(CC_IRQ_RPC_MD1_MD3_BUFFER_T)*CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER)

kal_mutexid    cc_irq_rpc_tx_md3_buff_mutex;
kal_eventgrpid cc_irq_rpc_rx_md3_event;/* the event we use to wait the RPC response from the other core */
CC_IRQ_RPC_CALLBACK_P cc_irq_rpc_rx_md3_cb[CC_IRQ_RPC_RX_MD3_NUMBER];/* call back function for CC IRQ RPC service for MD3's request(execute in HISR) */
kal_uint32 cc_irq_rpc_rx_md3_cb_execute_time[CC_IRQ_RPC_RX_MD3_NUMBER];/* the executing time of user call back function in HISR */
/* the executing time from receive REQUEST to send REPLY (due to user may handover RPC service to task, we should record the time to avoid user forget REPLY) */
CC_IRQ_RPC_SERVICE_TIME_T cc_irq_rpc_rx_md3_execute_time[CC_IRQ_RPC_RX_MD3_NUMBER];
CC_IRQ_RPC_OP_ID_T CC_IRQ_RPC_OP_ID_T_debugging;/* for debugging use */
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static CC_IRQ_RPC_MD1_MD3_BUFFER_T      *cc_irq_rpc_rx_md3_sharemem_p[CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER];
__attribute__ ((zero_init, section ("INTSRAM_ZI"))) static CC_IRQ_RPC_MD1_MD3_BUFFER_T      *cc_irq_rpc_tx_md3_sharemem_p[CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER];
#if defined(__PCORE__)
kal_uint32 cc_irq_rpc_ps2md3_share_data_addr;
kal_uint32 cc_irq_rpc_md32ps_share_data_addr;
kal_uint32 const cc_irq_rpc_tx_md3_cc_sys_comm = CC_SYS_COMM_P2MD3_RPC;	
kal_uint32 const cc_irq_rpc_rx_md3_cc_sys_comm = CC_SYS_COMM_MD32P_RPC;
#else
kal_uint32 cc_irq_rpc_l12md3_share_data_addr;
kal_uint32 cc_irq_rpc_md32l1_share_data_addr;
kal_uint32 const cc_irq_rpc_tx_md3_cc_sys_comm = CC_SYS_COMM_L2MD3_RPC;	
kal_uint32 const cc_irq_rpc_rx_md3_cc_sys_comm = CC_SYS_COMM_MD32L_RPC;
#endif	

/*****************************************************************************
 * Internal Function                                                         *
 *****************************************************************************/
/*------------------------------------------------------------------------
 * void cc_irq_rpc_hisr
 * Purpose:		The HISR function when receiving a RPC from MD3, 
 *              the ISR flow is cc_irq_lisr(kal_uint32 irqx)-->cc_sys_comm_lisr()-->cc_sys_comm_hisr()-->cc_irq_rpc_hisr()
 * Parameters:
 *    Input:	
 *              kal_uint32 rpc_buffer_index: The index of received RPC buffer in CC_IRQ_RPC_MD1_MD3_BUFFER_T.
 *              kal_uint32 action: CC_IRQ_RPC_REQUEST/CC_IRQ_RPC_REPLY 
 *    Output:	None
 * returns :	None
 * Note    :    This function is running in HISR.
 *------------------------------------------------------------------------
 */
void cc_irq_rpc_hisr(kal_uint32 rpc_buffer_index, kal_uint32 action)
{
    kal_uint32  rpc_opid_offset;
    kal_uint32  rpc_cb_start_time = 0, rpc_cb_end_time = 0, duration = 0;	
	
    EXT_ASSERT(rpc_buffer_index < CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER, rpc_buffer_index, action, 0);

    switch(action)
    {
        case CC_IRQ_RPC_REQUEST:
            EXT_ASSERT(CC_IRQ_RPC_RX_MD3_REQUEST_OP_IS_IN_RANGE(cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid), rpc_buffer_index, 0, 0);
            EXT_ASSERT(cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->valid == 1, rpc_buffer_index, 0, 0);
            rpc_opid_offset = CC_IRQ_RPC_RX_MD3_OPID_OFFSET(cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid);

            EXT_ASSERT(NULL != cc_irq_rpc_rx_md3_cb[rpc_opid_offset], rpc_buffer_index, cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid, rpc_opid_offset);

            rpc_cb_start_time = CC_IRQ_GET_US();

            /* record the start time of RPC service for debugging */			
            cc_irq_rpc_rx_md3_execute_time[rpc_opid_offset].start_time = rpc_cb_start_time;
            cc_irq_rpc_rx_md3_execute_time[rpc_opid_offset].end_time = 0;
			
            cc_irq_rpc_rx_md3_cb[rpc_opid_offset](rpc_buffer_index);/* RPC service function */
            rpc_cb_end_time = CC_IRQ_GET_US();

            /* Due to the call back function is executed in HISR, it could not execute too long. */            			
            CC_IRQ_GET_DURATION_US(rpc_cb_start_time, rpc_cb_end_time, duration);
            cc_irq_rpc_rx_md3_cb_execute_time[rpc_opid_offset] = duration;/* for debug */
            if (duration > CC_IRQ_RPC_HISR_TIMEOUT)
            {/* the executing time of RPC service function is too long *//* CC_IRQ_RPC_CALLBACK_TIMEOUT */
                EXT_ASSERT(0, rpc_opid_offset, cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid, duration);
            }

            /* return but don't notify the RPC caller the "RPC service is done" 
            ==> notify the RPC caller by CC IRQ when user call "cc_irq_rpc_put_output_param". 
            Reason: Some RPC service would use "mutex..", it would handover service to task in their callback function. Then they call "cc_irq_rpc_put_output_param"
            in the task to notify the RPC caller the "RPC service is done". */            
			
            break;
			
        case CC_IRQ_RPC_REPLY: /* note: the return value and output parameters also put in the tx RPC share buffer. */
            EXT_ASSERT(CC_IRQ_RPC_RX_MD3_REPLY_OP_IS_IN_RANGE(cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->rpc_opid & ~CC_IRQ_RPC_API_RESP_ID), rpc_buffer_index, 0, 0);	
            EXT_ASSERT(cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->valid == 1, rpc_buffer_index, 0, 0);			
            kal_set_eg_events(cc_irq_rpc_rx_md3_event,  (1 << (rpc_buffer_index)) , KAL_OR);
            break;	
			
        default:
            EXT_ASSERT(0, action, rpc_buffer_index, 0);
            break;				
    }

}

/*****************************************************************************
 * Public Function                                                           *
 *****************************************************************************/
/*------------------------------------------------------------------------
 * void    cc_irq_rpc_init
 * Purpose:		initialize MD1 MD3 RPC share memory pointer and parameters, register call back function 
 *              
 * Parameters:
 *    Input:	None 
 *    Output:	None
 * returns :	None
 * Note    :    None.
 *------------------------------------------------------------------------
 */
void cc_irq_rpc_init()
{
    kal_int32  i, ret;

#ifdef __PCORE__
    for(i = 0; i < CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER; i++)
    {
        cc_irq_rpc_tx_md3_sharemem_p[i] = (CC_IRQ_RPC_MD1_MD3_BUFFER_T *)cc_irq_rpc_ps2md3_share_data_addr + i;
        cc_irq_rpc_rx_md3_sharemem_p[i] = (CC_IRQ_RPC_MD1_MD3_BUFFER_T *)cc_irq_rpc_md32ps_share_data_addr + i;			
    }
#else
    for(i = 0; i < CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER; i++)
    {
        cc_irq_rpc_tx_md3_sharemem_p[i] = (CC_IRQ_RPC_MD1_MD3_BUFFER_T *)cc_irq_rpc_l12md3_share_data_addr + i;
        cc_irq_rpc_rx_md3_sharemem_p[i] = (CC_IRQ_RPC_MD1_MD3_BUFFER_T *)cc_irq_rpc_md32l1_share_data_addr + i;			
    }
#endif

    /* TX side initialize */
    for(i = 0; i < CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER; i++)
    {
        cc_irq_rpc_tx_md3_sharemem_p[i]->valid = 0;			
    }

    /* register RPC channel */
    ret = cc_sys_comm_channel_init(cc_irq_rpc_rx_md3_cc_sys_comm, cc_irq_rpc_hisr);
    EXT_ASSERT(CC_SYS_COMM_SUCCESS == ret, ret, 0, 0);

    cc_irq_rpc_tx_md3_buff_mutex = kal_create_mutex("CC_RPC");
    cc_irq_rpc_rx_md3_event = kal_create_event_group("CC_RPC");

}

/*------------------------------------------------------------------------
 * kal_int32 cc_irq_rpc_get_input_param
 * Purpose:		Retrieve the RPC caller input parameters from the other core.
 * Parameters:
 *    Input:	kal_uint32 rpc_buffer_index: RPC buffer index.
 *              input_para_struct_len: the length of input parameter structure for RPC.
 *              
 *    Output:	input_para_struct_addr: the data address of input parameter structure for RPC.
 * returns :	CC_IRQ_RPC_SUCCESS
 * Note    :    
 *              User need to check the return value.
 *              If there is no input parameter for the RPC function, don't call this function. 
 *------------------------------------------------------------------------
 */
kal_int32 cc_irq_rpc_get_input_param(kal_uint32 rpc_buffer_index, kal_uint32 input_para_struct_len, void *input_para_struct_addr)
{

    if(input_para_struct_len > CC_IRQ_RPC_MD1_MD3_BUFFER_SIZE)
    {/* the size of input parameter is too big. */
        EXT_ASSERT(0, rpc_buffer_index, input_para_struct_len, cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid);
    }

    if(input_para_struct_len == 0 || input_para_struct_addr == NULL)
    {/* If there is no input parameter for the RPC function, don't call this function. */
        EXT_ASSERT(0 , rpc_buffer_index, input_para_struct_len, (kal_uint32)input_para_struct_addr);
    }
    else if(input_para_struct_len != cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_data_length)
    {/* the size of input parameter buffer is mis-match */
        EXT_ASSERT(0, rpc_buffer_index, input_para_struct_len, cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_data_length);  
    }
	
    /* Start to fill the input paramter */
    kal_mem_cpy(input_para_struct_addr, cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_para_buffer, input_para_struct_len);
   
    return CC_IRQ_RPC_SUCCESS;
	
}

/*------------------------------------------------------------------------
 * kal_int32 cc_irq_rpc_put_output_param
 * Purpose:		Put the RPC server output parameters to RPC share buffer and send CC IRQ REPLY to RPC caller. 
 * Parameters:
 *    Input:	kal_uint32 rpc_buffer_index: RPC buffer index.
 *              kal_uint32 ret_value: the return value from the RPC service function.
 *              output_para_struct_len: the length of output parameter structure for RPC.
 *              output_para_struct_addr: the data address of output parameter structure for RPC.
 *
 *    Output:	None
 * returns :	CC_IRQ_RPC_SUCCESS
 * Note    :    
 *              User need to check the return value.
 *              If there is no output parameter for the RPC function, config "output_para_struct_len" to 0, "output_para_struct_addr" to NULL.  
 *------------------------------------------------------------------------
 */
kal_int32 cc_irq_rpc_put_output_param(kal_uint32 rpc_buffer_index, kal_uint32 ret_value, kal_uint32 output_para_struct_len, void *output_para_struct_addr)
{
    kal_int32 ret = CC_IRQ_RPC_SUCCESS;
    kal_uint32  rpc_opid_offset;
	
    if(output_para_struct_len > CC_IRQ_RPC_MD1_MD3_BUFFER_SIZE)
    {/* the size of output parameter is too big. *//* CC_IRQ_RPC_OUTPUT_PARA_SIZE_OVERFLOW */
        EXT_ASSERT(0, rpc_buffer_index, output_para_struct_len, cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid); 
    }

    if( (cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid & CC_IRQ_RPC_API_RESP_ID) == CC_IRQ_RPC_API_RESP_ID)
    {/* This RPC buffer already contain output value, may be user call this function 2 times ==> EE *//* CC_IRQ_RPC_OUTPUT_BUFFER_OCCUPIED */
        EXT_ASSERT(0, rpc_buffer_index, cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid, 0); 
    }
	
    if(cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->valid != 1)
    {/* rpc_buffer_index may be error */ /* CC_IRQ_RPC_OUTPUT_BUFFER_ILLEGALE*/   
        EXT_ASSERT(0, rpc_buffer_index, cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->valid, cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid);
    }	
	            
    cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_ret_value = ret_value;

    if(output_para_struct_len != 0 && output_para_struct_addr != NULL)
    {/* there are output parameters */
        /* Start to fill the output paramter */
        kal_mem_cpy(cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_para_buffer, output_para_struct_addr, output_para_struct_len);
        cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_data_length = output_para_struct_len;
    }
    else if(output_para_struct_len == 0 && output_para_struct_addr == NULL)
    {/* there is no output parameter */
        cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_data_length = 0;    
    }	
    else
    {/* "output_para_struct_len" is 0 or "output_para_struct_addr" is NULL but the other one is valid */
        //ret = CC_IRQ_RPC_ERR_PARAM;
        EXT_ASSERT(0 , rpc_buffer_index, output_para_struct_len, (kal_uint32)output_para_struct_addr);
    }    

    /* record the end time of RPC service for debugging */
    rpc_opid_offset = CC_IRQ_RPC_RX_MD3_OPID_OFFSET(cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid);
    cc_irq_rpc_rx_md3_execute_time[rpc_opid_offset].end_time = CC_IRQ_GET_US();
	
    /* modify the rpc_opid to notify it contains the output data now */		
    cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid = cc_irq_rpc_rx_md3_sharemem_p[rpc_buffer_index]->rpc_opid | CC_IRQ_RPC_API_RESP_ID;
	
    /* send CC IRQ REPLY to RPC caller */
    ASSERT(cc_sys_comm_tx_polling(cc_irq_rpc_tx_md3_cc_sys_comm, rpc_buffer_index, CC_IRQ_RPC_REPLY)==CC_SYS_COMM_SUCCESS);

    return ret;   

}

/*------------------------------------------------------------------------
 * kal_int32 cc_irq_rpc_call
 * Purpose:		Send an cross core(MD1->MD3) RPC. 
 * Parameters:
 *    Input:	kal_uint32 rpc_opid: Operation ID of CC IRQ RPC, it's the RPC call unique number. "CC_IRQ_RPC_OP_ID_T" in global_cc_rpc_op_id.h
 *              input_para_struct_len: the length of input parameter structure for RPC.
 *              input_para_struct_addr: the data address of input parameter structure for RPC.
 *              output_para_struct_len: the length of output parameter structure for RPC.
 *              
 *    Output:	output_para_struct_addr: the data address of output parameter structure for RPC.
 * returns :	the return value of the RPC call on the other core
 * Note    :    
 *              User need to check the return value.
 *              If there is no input parameter for the RPC function, config "input_para_struct_len" to 0, "input_para_struct_addr" to NULL.
 *              If there is no output parameter for the RPC function, config "output_para_struct_len" to 0, "output_para_struct_addr" to NULL.
 *------------------------------------------------------------------------
 */
kal_int32 cc_irq_rpc_call(kal_uint32 rpc_opid, kal_uint32 input_para_struct_len, void *input_para_struct_addr, kal_uint32 output_para_struct_len, void *output_para_struct_addr)
{
    kal_int32 rpc_buffer_index = CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER;
    kal_int32 	rpc_ret_value;
    kal_status ev_result = KAL_NOT_PRESENT;
    kal_uint32 i, retrieved_events =0;
    kal_uint32    start_time, current_time, dur, tx_cnt = 0;	
    kal_uint32 caller_LR;
	
    GET_RETURN_ADDRESS(caller_LR);	
    if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
    {
        kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
    }

    if(!CC_IRQ_RPC_TX_MD3_REQUEST_OP_IS_IN_RANGE(rpc_opid))
    {/* the "rpc_opid" is invalid */ /* CC_IRQ_RPC_INVALID_RPC_OP_ID */
        EXT_ASSERT(0, rpc_opid, 0, 0);//return CC_IRQ_RPC_ERR_PARAM;
    }

    if (cc_irq_sync_get_cc_irq_tx_md3_status() == KAL_FALSE)/* MD3 already in EPOF, we don't send RPC and just ignore it */
    {
        dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, CC_IRQ_RPC_ASYNC, rpc_opid, input_para_struct_len, CC_IRQ_GET_GLB_TS());
        return 0;
    }

    /* find free rpc buffer */
    start_time = CC_IRQ_GET_US();
    while(1)
    {
        kal_take_mutex(cc_irq_rpc_tx_md3_buff_mutex);
        for (i=0;i<CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER;i++) 
        {/* find a free RPC share buffer */
            if (cc_irq_rpc_tx_md3_sharemem_p[i]->valid == 0)
            {
                rpc_buffer_index = i; /* get a full channel */
                cc_irq_rpc_tx_md3_sharemem_p[i]->valid = 1; /* occupy the channel */
                break;
            }
        }
        kal_give_mutex(cc_irq_rpc_tx_md3_buff_mutex);

        if (rpc_buffer_index < CC_IRQ_RPC_MD1_MD3_BUFFER_NUMBER)
        {/* get a free RPC share buffer*/
            break;
        }
        else/* no free RPC share buffer, wait and try*/
        {
            current_time = CC_IRQ_GET_US();
			
            CC_IRQ_GET_DURATION_US(start_time, current_time, dur);			
            if (dur > CC_IRQ_RPC_TX_MD3_TIMEOUT)
            {/* RPC TX timeout */
                tx_cnt++;
                if (tx_cnt == 10)/* avoid context switch out and timeout, so we try many times to confirm */
                {
                    EXT_ASSERT(0, start_time, current_time, dur);//No free RPC share buffer for a long time
                }                
            }
        }
    }

    /* Pass the parameter to share memory, and send to the other core by CC IRQ. */ 
    cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->rpc_opid = rpc_opid;
    if(input_para_struct_len != 0 && input_para_struct_addr != NULL)
    {/* there are input parameters */
        if(input_para_struct_len > CC_IRQ_RPC_MD1_MD3_BUFFER_SIZE)
        {/* the size of input parameter is too big. */ /*CC_IRQ_RPC_INPUT_PARA_SIZE_OVERFLOW*/
            EXT_ASSERT(0, rpc_opid, input_para_struct_len, 0);
            //return CC_IRQ_RPC_ERR_PARAM;
        }
	
        /* Start to fill the input paramter */
        kal_mem_cpy(cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->rpc_para_buffer, input_para_struct_addr, input_para_struct_len);
        cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->rpc_data_length = input_para_struct_len;
    }
    else if(input_para_struct_len == 0 && input_para_struct_addr == NULL)
    {/* there is no input parameter */
        /* do nothing */
    }	
    else
    {/* "input_para_struct_len" is 0 or "input_para_struct_addr" is NULL but the other one is valid */ /* CC_IRQ_RPC_INVALID_INPUT_PARA_SIZE_OR_ADDR */
        EXT_ASSERT(0 , rpc_opid, input_para_struct_len, (kal_uint32)input_para_struct_addr);
        //return CC_IRQ_RPC_ERR_PARAM;
    }

    ASSERT(cc_sys_comm_tx_polling(cc_irq_rpc_tx_md3_cc_sys_comm, rpc_buffer_index, CC_IRQ_RPC_REQUEST)==CC_SYS_COMM_SUCCESS);

    /* Wait for the RPC is finished */
    ev_result = kal_retrieve_eg_events(cc_irq_rpc_rx_md3_event, 1 << rpc_buffer_index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
    EXT_ASSERT(ev_result==KAL_SUCCESS, ev_result, 0, 0);

    if (cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->rpc_opid != (CC_IRQ_RPC_API_RESP_ID | rpc_opid))
    {/* check the return id value */
       EXT_ASSERT(0, rpc_buffer_index, rpc_opid, cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->rpc_opid);
    }
 
    /* get the return value from buffer */
    rpc_ret_value = cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->rpc_ret_value;

    if(output_para_struct_len != 0 && output_para_struct_addr != NULL)
    {/* there are output parameters */
        if(output_para_struct_len > CC_IRQ_RPC_MD1_MD3_BUFFER_SIZE)
        {/* the size of output parameter is too big. *//* CC_IRQ_RPC_OUTPUT_PARA_SIZE_OVERFLOW */
            EXT_ASSERT(0, rpc_opid, rpc_buffer_index, output_para_struct_len);
            //return CC_IRQ_RPC_ERR_PARAM;
        }
		
        /* The size of output parameter should be the same. */
        if(cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->rpc_data_length != output_para_struct_len)
        {/* CC_IRQ_RPC_OUTPUT_PARA_SIZE_MISMATCH */
            EXT_ASSERT(0, rpc_buffer_index, cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->rpc_data_length, output_para_struct_len);
            //return CC_IRQ_RPC_ERR_PARAM;
        }
	
        /* Start to fill the output paramter */
        kal_mem_cpy(output_para_struct_addr, cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->rpc_para_buffer, output_para_struct_len);
    }
    else if(output_para_struct_len == 0 && output_para_struct_addr == NULL)
    {/* there is no output parameter */
        /* do nothing */
    }	
    else
    {/* "output_para_struct_len" is 0 or "output_para_struct_addr" is NULL but the other one is valid */ /* CC_IRQ_RPC_INVALID_OUTPUT_PARA_SIZE_OR_ADDR */
        EXT_ASSERT(0 , rpc_buffer_index, output_para_struct_len, (kal_uint32)output_para_struct_addr);    
        //return CC_IRQ_RPC_ERR_PARAM;
    }
 
    kal_take_mutex(cc_irq_rpc_tx_md3_buff_mutex);   
    /* release RPC share buffer */
    cc_irq_rpc_tx_md3_sharemem_p[rpc_buffer_index]->valid = 0;
    kal_give_mutex(cc_irq_rpc_tx_md3_buff_mutex);

    return rpc_ret_value;
    
}

/*------------------------------------------------------------------------
 * kal_int32    cc_irq_rpc_register_callback
 * Purpose:	Register RPC Call Back function for specified "rpc_opid" at Server side
 * Parameters:
 *    Input:	kal_uint32 rpc_opid: CC_IRQ_RPC_OP_ID_T in "global_cc_rpc_op_id.h", 
 *              RX operation id of CC IRQ RPC. It's the RPC call unique number.
 *              CC_IRQ_RPC_CALLBACK_P funcp: RPC service callback function when CC IRQ RPC with specified "rpc_opid" is triggered.(would be called in HISR)
 *    Output:	None
 * returns :	CC_IRQ_RPC_SUCCESS/CC_IRQ_RPC_ERR_PARAM
 * Note    :    This function could only register CC IRQ RPC service function for MD3.
 *              User should check the return value.
 *------------------------------------------------------------------------
 */
kal_int32 cc_irq_rpc_register_callback(kal_uint32 rpc_opid, CC_IRQ_RPC_CALLBACK_P funcp)
{
    kal_uint32        rpc_opid_offset;
    kal_uint32        caller_LR;
	
    GET_RETURN_ADDRESS(caller_LR);

    if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
    {
        kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
    }

    if (NULL == funcp || !CC_IRQ_RPC_RX_MD3_REQUEST_OP_IS_IN_RANGE(rpc_opid))
        return CC_IRQ_RPC_ERR_PARAM;

    /* Register for MD3 */
    rpc_opid_offset = CC_IRQ_RPC_RX_MD3_OPID_OFFSET(rpc_opid);
    cc_irq_rpc_rx_md3_cb[rpc_opid_offset] = funcp;    

    return CC_IRQ_RPC_SUCCESS;
}

/*------------------------------------------------------------------------
 * void         cc_irq_rpc_share_mem_config
 * Purpose:		config the CC IRQ RPC share memory address between MD1 and MD3 
 *              
 * Parameters:
 *    Input:	kal_uint32 start_address: the RPC share memory start address of MD1 and MD3
 *    Output:	None
 * returns :	next_start_address
 * Note    :    This function should be called before cc_irq_rpc_init.
 *------------------------------------------------------------------------
 */
kal_uint32 cc_irq_rpc_share_mem_config(kal_uint32 start_address)
{
    kal_uint32 next_start_address;
	
    EXT_ASSERT(start_address%4==0, start_address, 0, 0);
	
#if defined(__PCORE__)
    cc_irq_rpc_ps2md3_share_data_addr = start_address;
    cc_irq_rpc_md32ps_share_data_addr = cc_irq_rpc_ps2md3_share_data_addr + CC_IRQ_RPC_MD1_MD3_SHARE_MEM_SIZE + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(cc_irq_rpc_md32ps_share_data_addr-CC_IRQ_GUARD_PATTERN_LEN);	
    EXT_ASSERT(cc_irq_rpc_md32ps_share_data_addr%4==0, cc_irq_rpc_md32ps_share_data_addr, 0, 0);
    next_start_address = cc_irq_rpc_md32ps_share_data_addr + CC_IRQ_RPC_MD1_MD3_SHARE_MEM_SIZE + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(next_start_address-CC_IRQ_GUARD_PATTERN_LEN);	
#elif defined(__L1CORE__)
    cc_irq_rpc_l12md3_share_data_addr = start_address;
    cc_irq_rpc_md32l1_share_data_addr = cc_irq_rpc_l12md3_share_data_addr + CC_IRQ_RPC_MD1_MD3_SHARE_MEM_SIZE + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(cc_irq_rpc_md32l1_share_data_addr-CC_IRQ_GUARD_PATTERN_LEN);	
    EXT_ASSERT(cc_irq_rpc_md32l1_share_data_addr%4==0, cc_irq_rpc_md32l1_share_data_addr, 0, 0);	
    next_start_address = cc_irq_rpc_md32l1_share_data_addr + CC_IRQ_RPC_MD1_MD3_SHARE_MEM_SIZE + CC_IRQ_GUARD_PATTERN_LEN;
    cc_irq_fill_guard_pattern(next_start_address-CC_IRQ_GUARD_PATTERN_LEN);	
#endif

    return next_start_address;
}

/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
