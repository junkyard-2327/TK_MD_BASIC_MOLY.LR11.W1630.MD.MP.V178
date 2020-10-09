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
 *   cc_irq_trace.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   Defines CC_IRQ debug message.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CCIRQ_TRACE_H__
#define __CCIRQ_TRACE_H__

#if defined(__MTK_TARGET__)

#ifndef GEN_FOR_PC
 #include "kal_public_defs.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "cc_irq_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

#if defined(__PCORE__)
BEGIN_TRACE_MAP(MOD_P_CC_SYS_HISR)
#else
BEGIN_TRACE_MAP(MOD_L1_CC_SYS_HISR)
#endif   
    TRC_MSG(CC_IRQ_SYS_STATE_TRANS, "[CC_IRQ] State transition: %MCC_IRQ_SYS_STATE_T to %MCC_IRQ_SYS_STATE_T")
    TRC_MSG(CC_IRQ_SYS_STATE_RX_MD3_INIT_HS1, "[CC_IRQ] Receive MD3 Init Handshake 1 Packet, MD1's glb_ts:%d MD3's glb_ts=%d")
    TRC_MSG(CC_IRQ_SYS_STATE_RX_MD3_INIT_HS2, "[CC_IRQ] Receive MD3 Init Handshake 2 Packet, MD1's glb_ts:%d MD3's glb_ts=%d")
//    TRC_MSG(CC_IRQ_SYS_STATE_RX_EXCEP_HS, "[CC_IRQ] Receive Exception Handshake Packet")
    TRC_MSG(CC_IRQ_SYS_STATE_MD3_HANG, "[CC_IRQ] MD3 has no response, MD1's glb_ts:%d")
    TRC_MSG(CC_IRQ_SYS_PING_TX_MD3, "[CC_IRQ] Send Status Ping To MD3, MD1's glb_ts=%d")
    TRC_MSG(CC_IRQ_SYS_ACK_RX_MD3, "[CC_IRQ] Receive Status ACK From MD3, MD1's glb_ts:%d MD3's glb_ts=%d")    
    TRC_MSG(CC_IRQ_SYS_STATE_RX_PScore_INIT_HS1, "[CC_IRQ] Receive PScore Init Handshake 1 Packet, L1core's glb_ts:%d PScore's glb_ts=%d") 
    TRC_MSG(CC_IRQ_SYS_STATE_RX_L1core_INIT_HS1, "[CC_IRQ] Receive L1core Init Handshake 1 Packet, PScore's glb_ts:%d L1core's glb_ts=%d")   
    TRC_MSG(CC_IRQ_SYS_STATE_PScore_HANG, "[CC_IRQ] PScore has no response, L1core's glb_ts:%d")
    TRC_MSG(CC_IRQ_SYS_STATE_PScore_PROCESS_EPOF, "[CC_IRQ] PScore has no response due to it already receive EPOF from AP")    
    TRC_MSG(CC_IRQ_SYS_STATE_PScore_STOP_POLL_L1core, "[CC_IRQ] PScore stop polling L1core due to it already receive EPOF from AP, PScore's glb_ts:%d")     
    TRC_MSG(CC_IRQ_SYS_STATE_L1core_HANG, "[CC_IRQ] L1core has no response, PScore's glb_ts:%d")    
    TRC_MSG(CC_IRQ_SYS_PING_TX_L1core, "[CC_IRQ] Send Status Ping To L1core, PScore's glb_ts=%d")
    TRC_MSG(CC_IRQ_SYS_ACK_RX_L1core, "[CC_IRQ] Receive Status ACK From L1core, PScore's glb_ts:%d L1core's glb_ts=%d")  
    TRC_MSG(CC_IRQ_SYS_ACK_TX_PScore, "[CC_IRQ] Send Status ACK To PScore, L1core's glb_ts=%d")    
//    TRC_MSG(CC_IRQ_SYS_USER_CB, "[CC_IRQ] User CB")
//    TRC_MSG(CC_IRQ_SYS_HISR, "[CC_IRQ] HISR - %d")
    TRC_MSG(CC_IRQ_SYS_EPOF_SYNC, "[CC_IRQ] Receive EPOF Sync Packet From MD3, MD1's glb_ts:%d") 
    TRC_MSG(CC_IRQ_SYS_ASYNC_MD1, "[CC_IRQ] CC SYS IRQ to MD1 fail due to MD1 entering EPOF, comm_id=%d para0=%d para1=%d, MD1's glb_ts:%d")    
    TRC_MSG(CC_IRQ_SYS_ASYNC_MD3, "[CC_IRQ] CC SYS IRQ to MD3 fail due to MD3 entering EPOF, comm_id=%d para0=%d para1=%d, MD1's glb_ts:%d")       
    TRC_MSG(CC_IRQ_MSG_ASYNC, "[CC_IRQ] CC MSG send to MD3 fail due to MD3 entering EPOF, src_mod_id=%d dest_mod_id=%d msg_id=%d, MD1's glb_ts:%d")
    TRC_MSG(CC_IRQ_RPC_ASYNC, "[CC_IRQ] CC RPC send to MD3 fail due to MD3 entering EPOF, rpc_opid=%d input_para_struct_len=%d, MD1's glb_ts:%d") 
    // below use for KAL layer, use in KAL CC event group(cc_itc.c) and CC ILM(kal_msg_passing.c)
    TRC_MSG(CC_IRQ_IPC_ASYNC_L1, "[CC_IRQ] CC ILM send to MD1 L1core fail due to MD1 L1core entering EPOF, src_mod_id=%d dest_mod_id=%d msg_id=%d, MD1 Pcore's glb_ts:%d")
    TRC_MSG(CC_IRQ_EVG_ASYNC_L1_1, "[CC_IRQ] CC EVG send to MD1 L1core fail due to MD1 L1core entering EPOF, EVG name: %c%c%c%c%c%c%c%c, current event=%d, MD1 Pcore's glb_ts:%d")    
    TRC_MSG(CC_IRQ_EVG_ASYNC_L1_2, "[CC_IRQ] Task may always suspend in taking CC EVG MUTEX due to MD1 L1core entering EPOF, EVG name: %c%c%c%c%c%c%c%c, current event=%d, MD1 Pcore's glb_ts:%d")    
    TRC_MSG(CC_IRQ_EVG_ASYNC_L1_3, "[CC_IRQ] Tasks waiting for CC EVG MUTEX may fail to be resumed due to MD1 L1core entering EPOF, EVG name: %c%c%c%c%c%c%c%c, current event=%d, MD1 Pcore's glb_ts:%d")  
    // up use for KAL layer, use in KAL CC event group(cc_itc.c) and CC ILM(kal_msg_passing.c)   
#if defined(__PCORE__)
END_TRACE_MAP(MOD_P_CC_SYS_HISR)
#else
END_TRACE_MAP(MOD_L1_CC_SYS_HISR)
#endif	


#endif

#endif    /* __CC_IRQ_TRACE_H__ */
