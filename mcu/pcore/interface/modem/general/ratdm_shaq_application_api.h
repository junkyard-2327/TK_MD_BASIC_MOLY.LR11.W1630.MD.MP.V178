/******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   ratdm_shaq_application_api.h
 *
 * Project:
 * --------------------------------------------------------
 *   
 *
 * Description:
 * --------------------------------------------------------
 *   public R8 SHAQ API for application modules (PPP, UPS, TCPIP...etc)
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * 04 28 2016 head.hsu
 * [MOLY00175408] Multiple-PS/Remote-SIM interfaces phase2
 * 	[RATDM] external interface with __MULTIPLE_PS__ check-in
 * 	1. ESM-RATDM interface
 * 	2. SHAQ api interface
 * 	3. UPCM-RATDM interface
 *
 * 05 20 2015 head.hsu
 * [MOLY00089131] [MT6291 Gemini] L+W+W+W code revision check in
 * 	;RATDM/RABM/PDCP/CSR part check-in
 * 
 * 08 22 2012 andrew.wu
 * [MOLY00002319] [MSBB] Remove Invalid Inter-Category Including.
 * modem related option move to modem internal
 *
 * 06 11 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 01 30 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 01 30 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 01 11 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 09 21 2011 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 *
 * 
 ******************************************************************************/

#ifndef _RATDM_SHAQ_APPLICATION_API_H
#define _RATDM_SHAQ_APPLICATION_API_H

#include "kal_general_types.h"
#include "flc2_config.h"

/* fake header for easy conversion */
typedef struct SHAQ_qElmtHeader
{
    PEER_BUFF_HDR
    struct SHAQ_qElmtHeader *next_shaqElmt;
} SHAQ_qElmtHeader;

/* Error codes & Return codes */
typedef enum
{
    SHAQ_OK,
    SHAQ_GENERAL_ABORT,
    SHAQ_CONVENTIONAL_TRACK,
    UPLINK_DATA_GOTO_CONVENTIONAL_TRACK = SHAQ_CONVENTIONAL_TRACK,
    SHAQ_KICK_UL2,
    SHAQ_NOT_INITIATED,
    SHAQ_CANNOT_FIND_Q,
    SHAQ_CANNOT_FIND_NSAPI_FROM_CONTEXT_ID,
    SHAQ_NSAPI_CHECK_FAIL,
    SHAQ_EXCEPTION,
    SHAQ_ABORT,
    SHAQ_NOT_READY,
    SHAQ_CANNOT_FIND_CID_FROM_RBID
} SHAQ_retCode;

typedef enum
{
    SHAQ_ENQUEUE_PRIORITY_QUEUE,
    SHAQ_ENQUEUE_NORMAL_QUEUE,
    SHAQ_ENQUEUE_DECIDED_BY_SHAQ_API,
    SHAQ_NUMBER_OF_ENQUEUE_DECISIONS
} SHAQ_ENQUEUE_WHICH_QUEUE;

#ifndef __RATDM_UL_SHAQ__
typedef struct ratdm_ps_data_req_struct_tag
{
    PEER_BUFF_HDR

    kal_uint8 pool_id;
    kal_uint8 context_id;
    kal_uint8 nsapi;    
    kal_uint16 npdu_num;
    kal_uint16 ori_free_header_space;
    struct ratdm_ps_data_req_struct_tag *next;    
    kal_uint8 padding[12];	// To feet 24 bytes, adding 8bytes header as 32 bytes to fulfill cacheline
}ratdm_ps_data_req_struct;
#else // #ifndef __RATDM_UL_SHAQ__
typedef struct ratdm_ps_data_req_struct_tag
{
    //Dont touch this part
    //M_SHAQ_ELMT_HEADER
    PEER_BUFF_HDR
    struct SHAQ_qElmtHeader *next_shaqElmt;   
    // Hands off please

    kal_uint8 pool_id;
    kal_uint8 context_id;
    kal_uint8 nsapi;
    kal_bool bConfirm;

    kal_uint16 npdu_num;
    kal_uint16 ori_free_header_space;

    kal_uint8 TxRBId;
    kal_uint8 ap_enqueue_decision; // SHAQ_ENQUEUE_WHICH_QUEUE enum
    kal_uint16 bitLength;
    kal_uint32 MUI;
    struct ratdm_ps_data_req_struct_tag *next;
}ratdm_ps_data_req_struct;

#endif // ~ #ifndef __RATDM_UL_SHAQ__

/* MACRO DEFINITION */
#ifndef __MULTIPLE_PS__
#undef RATDM_EXPAND
#define RATDM_EXPAND(x) x
/* ratdm_autogen_sim_idx(), L+W DSDS PS shall always enqueue for PS active SIM */
#define SHAQ_psEnqueueWithPriorityInfo(...) RATDM_EXPAND(_SHAQ_psEnqueueWithPriorityInfo(__VA_ARGS__, ratdm_autogen_sim_idx(1), NULL))
#define _SHAQ_psEnqueueWithPriorityInfo(pPeer, pool_id, cid, taskid, ap_enqueue_decision, sim_interface, ...) SHAQ_psEnqueueWithPriorityInfo(pPeer, pool_id, cid, taskid, ap_enqueue_decision, sim_interface)

#define SHAQ_psEnqueue(...) RATDM_EXPAND(_SHAQ_psEnqueue(__VA_ARGS__, ratdm_autogen_sim_idx(), NULL))
#define _SHAQ_psEnqueue(pPeer, pool_id, cid, taskid, sim_interface, ...) SHAQ_psEnqueueWithPriorityInfo(pPeer, pool_id, cid, taskid, SHAQ_ENQUEUE_DECIDED_BY_SHAQ_API, sim_interface)
#else
#define SHAQ_psEnqueue(pPeer, pool_id, cid, taskid, sim_interface) SHAQ_psEnqueueWithPriorityInfo(pPeer, pool_id, cid, taskid, SHAQ_ENQUEUE_DECIDED_BY_SHAQ_API, sim_interface)
#endif // ~ #ifndef __MULTIPLE_PS__

/* EXPORT FUNCTIONS */
extern SHAQ_retCode SHAQ_psEnqueueWithPriorityInfo(ratdm_ps_data_req_struct *pPeer, flc2_pool_id_enum pool_id, kal_uint8 cid, kal_taskid taskid, SHAQ_ENQUEUE_WHICH_QUEUE ap_enqueue_decision, kal_uint8 sim_interface);
extern kal_uint8 ratdm_autogen_sim_idx();

#endif /* _RATDM_SHAQ_APPLICATION_API_H */
