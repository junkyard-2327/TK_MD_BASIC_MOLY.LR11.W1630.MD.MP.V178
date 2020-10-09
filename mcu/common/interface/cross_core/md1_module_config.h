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
 *   md1_module_config.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file provides the task index and module index configuration.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//MODULE_ID_GLOBAL_MD1(MOD_XXX)
//MOD_XXX must be defined in local module if using this MARCO
//this MARCO will be used to create a mapping array {MOD_XXX, MOD_XXX_MD1}
//where MOD_XXX_MD1 is visible to all MDs with same value.

/*please dont use compile option in this file to avoid mismatching option among MDs */

//for Pcore global module, please define in below
MD1_PCORE_GLOBAL_MODULE_ID_BEGIN
MODULE_ID_GLOBAL_MD1(MOD_GMSS)
MODULE_ID_GLOBAL_MD1(MOD_SIM)
MODULE_ID_GLOBAL_MD1(MOD_SIM_2)
MODULE_ID_GLOBAL_MD1(MOD_L4C)
MODULE_ID_GLOBAL_MD1(MOD_RAC)
MODULE_ID_GLOBAL_MD1(MOD_ERRC)
MODULE_ID_GLOBAL_MD1(MOD_RSVAC)
MODULE_ID_GLOBAL_MD1(MOD_RSVAS)
MODULE_ID_GLOBAL_MD1(MOD_MRS)
MODULE_ID_GLOBAL_MD1(MOD_EVAL)
MODULE_ID_GLOBAL_MD1(MOD_SDM)
MODULE_ID_GLOBAL_MD1(MOD_VDM)
MODULE_ID_GLOBAL_MD1(MOD_IMCSMS)
MODULE_ID_GLOBAL_MD1(MOD_SMU)
MODULE_ID_GLOBAL_MD1(MOD_SMU_2)
MODULE_ID_GLOBAL_MD1(MOD_CSM)
MODULE_ID_GLOBAL_MD1(MOD_CSM_2)
MODULE_ID_GLOBAL_MD1(MOD_GMSS_2)
MODULE_ID_GLOBAL_MD1(MOD_DHL_READER)
//for Pcore global module, please define in above
MD1_L1CORE_GLOBAL_MODULE_ID_BEGIN
//for L1core global module, please define in below
MODULE_ID_GLOBAL_MD1(MOD_LMOB)
MODULE_ID_GLOBAL_MD1(MOD_EL1)
MODULE_ID_GLOBAL_MD1(MOD_MLL1)
MODULE_ID_GLOBAL_MD1(MOD_MMRF)


