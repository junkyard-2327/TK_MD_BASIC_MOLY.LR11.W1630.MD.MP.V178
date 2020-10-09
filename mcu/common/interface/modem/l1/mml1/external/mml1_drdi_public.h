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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   mml1_drdi_public.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   The structure definition of MML1 MIPI data
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MML1_DRDI_PUBLIC_H
#define MML1_DRDI_PUBLIC_H

#include "mmrf_cc_global.h"

#define MML1_DRDI_MAX_SUPPORT_SET_NUMS 128

#define MML1_RF_CUSTOM_INPUT_DATA_M(sET)                       \
{                                                              \
   {                                                           \
      0x12345678,                                              \
      1,                                                       \
      MMRF_TYPE,                                               \
      1,                                                       \
      {                                                        \
         MML1_CLK1_EN_##sET,                                   \
         MML1_CLK2_EN_##sET,                                   \
         MML1_CLK3_EN_##sET,                                   \
         MML1_CLK4_EN_##sET                                    \
      },                                                       \
      {                                                        \
         MML1_CLK1_DRIVING_##sET,                              \
         MML1_CLK2_DRIVING_##sET,                              \
         MML1_CLK3_DRIVING_##sET,                              \
         MML1_CLK4_DRIVING_##sET                               \
      },                                                       \
      {                                                        \
         {  PRX1_IQ_SWAP_EN_##sET, PRX2_IQ_SWAP_EN_##sET  },   \
         {  DRX1_IQ_SWAP_EN_##sET, DRX2_IQ_SWAP_EN_##sET  },   \
      },                                                       \
      {                                                        \
         {  PRX1_I_INV_EN_##sET, PRX2_I_INV_EN_##sET  },       \
         {  PRX1_Q_INV_EN_##sET, PRX2_Q_INV_EN_##sET  },       \
         {  DRX1_I_INV_EN_##sET, DRX2_I_INV_EN_##sET  },       \
         {  DRX1_Q_INV_EN_##sET, DRX2_Q_INV_EN_##sET  },       \
      },                                                       \
      0x87654321,                                              \
   }                                                           \
}

#define MML1_RF_CUSTOM_SAR_DATA_M(sET)                         \
{                                                              \
   MML1_MANUAL_EN_##sET,                                       \
   {                                                           \
      GSM_TABLE_IDX_##sET,                                     \
      WCDMA_TABLE_IDX_##sET,                                   \
      TDSCDMA_TABLE_IDX_##sET,                                 \
      LTE_TABLE_IDX_##sET,                                     \
      C2K_TABLE_IDX_##sET                                      \
   },                                                          \
   MML1_SWTP_EN_##sET,                                         \
   MML1_SWTP_TABLE_SWAP                                        \
}

#endif
