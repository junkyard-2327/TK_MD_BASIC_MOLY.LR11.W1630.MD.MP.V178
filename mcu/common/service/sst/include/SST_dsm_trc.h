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
 *   SST_dsm_trc.h
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
   TRC_MSG(SST_DSM_COMMON_00, "[DSM] check dsmgr.h/dsmgr.c for dsm_section_id/DSM_ACTION!")
   
   TRC_MSG(SST_DSM_COMMON_01_01, "[DSM] LR=0x%x is located in DSM section!")
   TRC_MSG(SST_DSM_COMMON_01_02, "[DSM] SP=0x%x is located in DSM section!")
   
   TRC_MSG(SST_DSM_COMMON_03_01, "[DSM] print out dsm_id/dsm_tick/dsm_action in dsm_action_record[index]!")
   TRC_MSG(SST_DSM_COMMON_03_02, "[DSM] index =%d, dsm_section_id: %Mdsm_section_id, dsm_tick =0x%x, DSM_ACTION: %MDSM_ACTION")
      
   TRC_MSG(SST_DSM_COMMON_04_01, "[DSM] print out section status!")
   TRC_MSG(SST_DSM_COMMON_04_02, "[DSM] dsm_section_id: %Mdsm_section_id, dsm_section_status: %Mdsm_section_status")
   
   /* -------------------- Phase 1: Exception Message, grouped according to type ------------------------- */
   /* KAL_ERROR_INVALID_DSM_LOAD_ID_OUT_OF_RANGE */
   TRC_MSG(SST_PHASE1_1900_01, "")

   /* KAL_ERROR_INVALID_DSM_ACCESS_WRONG_ADDRESS */
   TRC_MSG(SST_PHASE1_1909_P1, "data abort due to access wrong DSM section, please check DSM related infomation")
   TRC_MSG(SST_PHASE1_1909_P2, "please search trace Message by keyword [DSM]")
   
   /* ------------------- Phase 2: Detailed analysis (N/A) -------------------- */
   
   /* -------------------- Phase 3: Guideline ------------------------- */
   /* KAL_ERROR_AFM_CREATE_FAILED */


