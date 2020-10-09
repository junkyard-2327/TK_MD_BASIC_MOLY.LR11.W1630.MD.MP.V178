/*****************************************************************************
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   SST_ccitc_trc.h 
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains definitions for trace on target.
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
  
	/* Phase 1: Exception Message, grouped according to type */
	TRC_MSG(SST_PHASE1_2400_3, "In kalcc_set_eg_events ( ), event group operation is undefined. It is neither KAL_AND nor KAL_OR.")
	TRC_MSG(SST_PHASE1_2400_4, "In kalcc_set_eg_events ( ), caller context in HISR or in system init stage.")
	TRC_MSG(SST_PHASE1_2400_NULL, "In kalcc_set_eg_events ( ), the pointer to cross-core event group is NULL pointer.")
	TRC_MSG(SST_PHASE1_2400_ptr, "In kalcc_set_eg_events ( ), control block of event group may be corrupted.")
	TRC_MSG(SST_PHASE1_2401_3_1, "In kalcc_retrieve_eg_events ( ), event group operation is undefined, which is neither KAL_AND")
    TRC_MSG(SST_PHASE1_2401_3_2, "nor KAL_OR, or the suspend option is undefined, which is neither KAL_NO_SUSPEND nor KAL_SUSPEND.")
	TRC_MSG(SST_PHASE1_2401_4, "In kalcc_retrieve_eg_events ( ), caller context in HISR or in system init stage.")
	TRC_MSG(SST_PHASE1_2401_5, "In kalcc_retrieve_eg_events ( ), the pointer to the event wanted to retrieve is NULL.")
	TRC_MSG(SST_PHASE1_2401_NULL, "In kalcc_retrieve_eg_events ( ), the pointer to cross-core event group is NULL pointer.")
	TRC_MSG(SST_PHASE1_2401_ptr, "In kalcc_retrieve_eg_events ( ), control block of event group may be corrupted.")
	TRC_MSG(SST_PHASE1_2402_NULL, "In kalcc_create_event_group ( ), NULL pointer is provided for creating cross-core event group.")
	TRC_MSG(SST_PHASE1_2402_NotShared, "In kalcc_create_event_group ( ), the cross-core event group memory is not located in share region.")
	TRC_MSG(SST_PHASE1_2403_LongTimeNoRes, "In kalcc_set_eg_events ( ), polling the ack from the other core timeout.")
	
	/* Phase 2: Detailed analysis */
	
	/* Dump data structure */
	/* Event group */
	TRC_MSG(SST_CC_EV_GCB, "Content of cross-core event group control block as below:")
	TRC_MSG(SST_CC_EV_GCB_ID, "   ev_id : 0x%X")
	TRC_MSG(SST_CC_EV_GCB_NAME, "   ev_name : %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_CC_EV_GCB_CUR_EVENTS, "   ev_current_events : %d")
	TRC_MSG(SST_CC_EV_GCB_WAIT_TASK_HEAD, "   ev_waiting_task_head : 0x%X")	
	TRC_MSG(SST_CC_EV_GCB_WAIT_TASK_TAIL, "   ev_waiting_task_tail : 0x%X")	

