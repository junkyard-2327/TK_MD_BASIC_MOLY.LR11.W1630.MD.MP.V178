/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2015
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
 *   md1_md3_cc_user_share_mem_config.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file provides the user index configuration of MD1/MD3 user share memory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*
MD1_MD3_CC_USER_SHARE_MEM_REG(YYY_XXX, size)
YYY_XXX:
  YYY must be "PS2MD3" or "L12MD3" or "MD32L1" or "MD32PS", it means the writer and the reader of this user share memory, 
  For example, "PS2MD3" means PScore write and MD3 read.
  XXX is user define.
size: 
  unit: byte, suggest the size to be 4 bytes align.
  
Ex: MD1_MD3_CC_USER_SHARE_MEM_REG(PS2MD3_L4, 2048)

"CC_SHARE_MEM_YYY_XXX" is the user index when using "cc_irq_get_md1_md3_user_shared_memory()" to get user share memory address, ex: CC_SHARE_MEM_PS2MD3_L4
The same CC_SHARE_MEM_YYY_XXX would get the same user share memory address.
*/

MD1_MD3_CC_USER_SHARE_MEM_REG(PS2MD3_CCSYS_FLOW_CTRL, 4)
MD1_MD3_CC_USER_SHARE_MEM_REG(MD32PS_CCSYS_FLOW_CTRL, 4)
MD1_MD3_CC_USER_SHARE_MEM_REG(L12MD3_CCSYS_FLOW_CTRL, 4)
MD1_MD3_CC_USER_SHARE_MEM_REG(MD32L1_CCSYS_FLOW_CTRL, 4)
MD1_MD3_CC_USER_SHARE_MEM_REG(L12MD3_AFC_INFO, 224)
MD1_MD3_CC_USER_SHARE_MEM_REG(PS2MD3_LPM_CNT, 4)
MD1_MD3_CC_USER_SHARE_MEM_REG(L12MD3_CLOAD_INFO, 8)
MD1_MD3_CC_USER_SHARE_MEM_REG(PS2MD3_SPINLOCK, 64)
MD1_MD3_CC_USER_SHARE_MEM_REG(PS2MD3_SPINLOCK_LOG, 16)
MD1_MD3_CC_USER_SHARE_MEM_REG(L12MD3_32K_SPINLOCK, 64)
MD1_MD3_CC_USER_SHARE_MEM_REG(L12MD3_32K_SPINLOCK_LOG, 16)
MD1_MD3_CC_USER_SHARE_MEM_REG(L12MD3_32KLESS_MUTUAL_ACCESS, 12)
MD1_MD3_CC_USER_SHARE_MEM_REG(L12MD3_32K_IS_UPDATING, 4)
MD1_MD3_CC_USER_SHARE_MEM_REG(L12MD3_MMRF_FEATURE, 128)
//MD1_MD3_CC_USER_SHARE_MEM_REG(MD32PS_CCIT_SHARE, 256)/* for CC_IRQ_IT */
//MD1_MD3_CC_USER_SHARE_MEM_REG(MD32PS_CC_CRITICAL_SHARE, 4)/* for CC_IRQ_IT */
MD1_MD3_CC_USER_SHARE_MEM_REG(END, 0)/* please add user up this line */
