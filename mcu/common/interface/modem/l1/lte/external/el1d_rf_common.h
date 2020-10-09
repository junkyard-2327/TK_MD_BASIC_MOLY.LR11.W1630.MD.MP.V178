/******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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

/*==============================================================================
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
/* Doxygen Group Header ****************************************************//**
 * @addtogroup EL1D_RF_COMMON
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @file       el1d_rf_common.h
 * @author     LY Chen (MTK04356)
 * @date       2014.12.16
 * @brief      EL1D RF Common
 * @details    serves as default value of undefined macro constants
 *             in lte_custom_rf.h
 ******************************************************************************/

#ifndef __EL1D_RF_COMMON_H__
#define __EL1D_RF_COMMON_H__

/*******************************************************************************
 * #include
 ******************************************************************************/

/*******************************************************************************/
/*                              Common RF Setting                              */
/*******************************************************************************/
/* This part serves as default value of undefined macro constants in lte_custom_rf.h */
/* Aim to accommodate to those difference between RF chips */

//The following definitions are moved to lte_custom_rf.h
//PDATA_LTE_BandNone_XXX
//LTE_BandNone_XXX_IO_SEL

//RF conflict check
#define LTE_RF_CFLT_PIN                 (31)
#define PDATA_LTE_RF_CONFLICT           ((0x1 << LTE_RF_CFLT_PIN) | 0x0000000000000000)

#if LTE_RF_CFLT_PIN < 32
#define PDATA_LTE_RF_CFLT_L             (0x1 << LTE_RF_CFLT_PIN)
#define PDATA_LTE_RF_CFLT_H             (0x00000000)
#elif LTE_RF_CFLT_PIN < 48
#define PDATA_LTE_RF_CFLT_L             (0x00000000)
#define PDATA_LTE_RF_CFLT_H             (0x1 << (LTE_RF_CFLT_PIN - 32))
#else
   #error "invalid LTE_RF_CLFT_PIN, shoulde < 48 for TK6291"
#endif


//PR0 & PT0 is used for RF conflict check
#define PDATA_LTE_BANDX_PR0              0x00000000
#define PDATA_LTE_BANDX_PR0_H            0x00000000
#define PDATA_LTE_BANDX_PT0              0x00000000
#define PDATA_LTE_BANDX_PT0_H            0x00000000

//PR3B is used for special scenario of TDD special subframe
#define PDATA_LTE_BANDX_PR3B             0x00000000
#define PDATA_LTE_BANDX_PR3B_H           0x00000000

//PR3C is used for set RF conflict off
#define PDATA_LTE_BANDX_PR3C             0x00000000
#define PDATA_LTE_BANDX_PR3C_H           0x00000000

//Common PR1~3_H, PT1~3_H, CA setting
//PS: it should be replaced by CA defined BPI_H
#define PDATA_LTE_BANDX_PR1_H            LTE_PDATA_OFF
#define PDATA_LTE_BANDX_PR2_H            LTE_PDATA_OFF
#define PDATA_LTE_BANDX_PR3_H            LTE_PDATA_OFF
#define PDATA_LTE_BANDX_PT1_H            LTE_PDATA_OFF
#define PDATA_LTE_BANDX_PT2_H            LTE_PDATA_OFF
#define PDATA_LTE_BANDX_PT3_H            LTE_PDATA_OFF

//MPR default value
//The following definitions are moved to lte_custom_rf.h
//LTE_BandNone_MPR_XXX
//LTE_BandNone_DELTA_XXX

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if IS_4G_BAND32_SUPPORT
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*******************************************************************************/

/** Define BPI_H [48:32], in general, should be 0x00000000 */
#ifndef    PDATA_LTE_BandNone_PR1_H
   #define PDATA_LTE_BandNone_PR1_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_BandNone_PR2_H
   #define PDATA_LTE_BandNone_PR2_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_BandNone_PR3_H
   #define PDATA_LTE_BandNone_PR3_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_BandNone_PT1_H
   #define PDATA_LTE_BandNone_PT1_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_BandNone_PT2_H
   #define PDATA_LTE_BandNone_PT2_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_BandNone_PT3_H
   #define PDATA_LTE_BandNone_PT3_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_BandNone_PRANT_H
   #define PDATA_LTE_BandNone_PRANT_H    LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_BandNone_PTANT_H
   #define PDATA_LTE_BandNone_PTANT_H    LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band1_PR1_H
   #define PDATA_LTE_Band1_PR1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band1_PR2_H
   #define PDATA_LTE_Band1_PR2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band1_PR3_H
   #define PDATA_LTE_Band1_PR3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band1_PT1_H
   #define PDATA_LTE_Band1_PT1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band1_PT2_H
   #define PDATA_LTE_Band1_PT2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band1_PT3_H
   #define PDATA_LTE_Band1_PT3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band1_PRANT_H
   #define PDATA_LTE_Band1_PRANT_H       LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band1_PTANT_H
   #define PDATA_LTE_Band1_PTANT_H       LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band2_PR1_H
   #define PDATA_LTE_Band2_PR1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band2_PR2_H
   #define PDATA_LTE_Band2_PR2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band2_PR3_H
   #define PDATA_LTE_Band2_PR3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band2_PT1_H
   #define PDATA_LTE_Band2_PT1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band2_PT2_H
   #define PDATA_LTE_Band2_PT2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band2_PT3_H
   #define PDATA_LTE_Band2_PT3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band2_PRANT_H
   #define PDATA_LTE_Band2_PRANT_H       LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band2_PTANT_H
   #define PDATA_LTE_Band2_PTANT_H       LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band3_PR1_H
   #define PDATA_LTE_Band3_PR1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band3_PR2_H
   #define PDATA_LTE_Band3_PR2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band3_PR3_H
   #define PDATA_LTE_Band3_PR3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band3_PT1_H
   #define PDATA_LTE_Band3_PT1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band3_PT2_H
   #define PDATA_LTE_Band3_PT2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band3_PT3_H
   #define PDATA_LTE_Band3_PT3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band3_PRANT_H
   #define PDATA_LTE_Band3_PRANT_H       LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band3_PTANT_H
   #define PDATA_LTE_Band3_PTANT_H       LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band4_PR1_H
   #define PDATA_LTE_Band4_PR1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band4_PR2_H
   #define PDATA_LTE_Band4_PR2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band4_PR3_H
   #define PDATA_LTE_Band4_PR3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band4_PT1_H
   #define PDATA_LTE_Band4_PT1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band4_PT2_H
   #define PDATA_LTE_Band4_PT2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band4_PT3_H
   #define PDATA_LTE_Band4_PT3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band4_PRANT_H
   #define PDATA_LTE_Band4_PRANT_H       LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band4_PTANT_H
   #define PDATA_LTE_Band4_PTANT_H       LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band5_PR1_H
   #define PDATA_LTE_Band5_PR1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band5_PR2_H
   #define PDATA_LTE_Band5_PR2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band5_PR3_H
   #define PDATA_LTE_Band5_PR3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band5_PT1_H
   #define PDATA_LTE_Band5_PT1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band5_PT2_H
   #define PDATA_LTE_Band5_PT2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band5_PT3_H
   #define PDATA_LTE_Band5_PT3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band5_PRANT_H
   #define PDATA_LTE_Band5_PRANT_H       LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band5_PTANT_H
   #define PDATA_LTE_Band5_PTANT_H       LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band6_PR1_H
   #define PDATA_LTE_Band6_PR1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band6_PR2_H
   #define PDATA_LTE_Band6_PR2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band6_PR3_H
   #define PDATA_LTE_Band6_PR3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band6_PT1_H
   #define PDATA_LTE_Band6_PT1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band6_PT2_H
   #define PDATA_LTE_Band6_PT2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band6_PT3_H
   #define PDATA_LTE_Band6_PT3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band6_PRANT_H
   #define PDATA_LTE_Band6_PRANT_H       LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band6_PTANT_H
   #define PDATA_LTE_Band6_PTANT_H       LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band7_PR1_H
   #define PDATA_LTE_Band7_PR1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band7_PR2_H
   #define PDATA_LTE_Band7_PR2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band7_PR3_H
   #define PDATA_LTE_Band7_PR3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band7_PT1_H
   #define PDATA_LTE_Band7_PT1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band7_PT2_H
   #define PDATA_LTE_Band7_PT2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band7_PT3_H
   #define PDATA_LTE_Band7_PT3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band7_PRANT_H
   #define PDATA_LTE_Band7_PRANT_H       LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band7_PTANT_H
   #define PDATA_LTE_Band7_PTANT_H       LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band8_PR1_H
   #define PDATA_LTE_Band8_PR1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band8_PR2_H
   #define PDATA_LTE_Band8_PR2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band8_PR3_H
   #define PDATA_LTE_Band8_PR3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band8_PT1_H
   #define PDATA_LTE_Band8_PT1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band8_PT2_H
   #define PDATA_LTE_Band8_PT2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band8_PT3_H
   #define PDATA_LTE_Band8_PT3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band8_PRANT_H
   #define PDATA_LTE_Band8_PRANT_H       LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band8_PTANT_H
   #define PDATA_LTE_Band8_PTANT_H       LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band9_PR1_H
   #define PDATA_LTE_Band9_PR1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band9_PR2_H
   #define PDATA_LTE_Band9_PR2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band9_PR3_H
   #define PDATA_LTE_Band9_PR3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band9_PT1_H
   #define PDATA_LTE_Band9_PT1_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band9_PT2_H
   #define PDATA_LTE_Band9_PT2_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band9_PT3_H
   #define PDATA_LTE_Band9_PT3_H         LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band9_PRANT_H
   #define PDATA_LTE_Band9_PRANT_H       LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band9_PTANT_H
   #define PDATA_LTE_Band9_PTANT_H       LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band10_PR1_H
   #define PDATA_LTE_Band10_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band10_PR2_H
   #define PDATA_LTE_Band10_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band10_PR3_H
   #define PDATA_LTE_Band10_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band10_PT1_H
   #define PDATA_LTE_Band10_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band10_PT2_H
   #define PDATA_LTE_Band10_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band10_PT3_H
   #define PDATA_LTE_Band10_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band10_PRANT_H
   #define PDATA_LTE_Band10_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band10_PTANT_H
   #define PDATA_LTE_Band10_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band11_PR1_H
   #define PDATA_LTE_Band11_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band11_PR2_H
   #define PDATA_LTE_Band11_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band11_PR3_H
   #define PDATA_LTE_Band11_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band11_PT1_H
   #define PDATA_LTE_Band11_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band11_PT2_H
   #define PDATA_LTE_Band11_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band11_PT3_H
   #define PDATA_LTE_Band11_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band11_PRANT_H
   #define PDATA_LTE_Band11_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band11_PTANT_H
   #define PDATA_LTE_Band11_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band12_PR1_H
   #define PDATA_LTE_Band12_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band12_PR2_H
   #define PDATA_LTE_Band12_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band12_PR3_H
   #define PDATA_LTE_Band12_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band12_PT1_H
   #define PDATA_LTE_Band12_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band12_PT2_H
   #define PDATA_LTE_Band12_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band12_PT3_H
   #define PDATA_LTE_Band12_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band12_PRANT_H
   #define PDATA_LTE_Band12_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band12_PTANT_H
   #define PDATA_LTE_Band12_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band13_PR1_H
   #define PDATA_LTE_Band13_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band13_PR2_H
   #define PDATA_LTE_Band13_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band13_PR3_H
   #define PDATA_LTE_Band13_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band13_PT1_H
   #define PDATA_LTE_Band13_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band13_PT2_H
   #define PDATA_LTE_Band13_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band13_PT3_H
   #define PDATA_LTE_Band13_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band13_PRANT_H
   #define PDATA_LTE_Band13_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band13_PTANT_H
   #define PDATA_LTE_Band13_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band14_PR1_H
   #define PDATA_LTE_Band14_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band14_PR2_H
   #define PDATA_LTE_Band14_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band14_PR3_H
   #define PDATA_LTE_Band14_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band14_PT1_H
   #define PDATA_LTE_Band14_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band14_PT2_H
   #define PDATA_LTE_Band14_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band14_PT3_H
   #define PDATA_LTE_Band14_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band14_PRANT_H
   #define PDATA_LTE_Band14_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band14_PTANT_H
   #define PDATA_LTE_Band14_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band15_PR1_H
   #define PDATA_LTE_Band15_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band15_PR2_H
   #define PDATA_LTE_Band15_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band15_PR3_H
   #define PDATA_LTE_Band15_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band15_PT1_H
   #define PDATA_LTE_Band15_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band15_PT2_H
   #define PDATA_LTE_Band15_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band15_PT3_H
   #define PDATA_LTE_Band15_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band15_PRANT_H
   #define PDATA_LTE_Band15_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band15_PTANT_H
   #define PDATA_LTE_Band15_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band16_PR1_H
   #define PDATA_LTE_Band16_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band16_PR2_H
   #define PDATA_LTE_Band16_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band16_PR3_H
   #define PDATA_LTE_Band16_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band16_PT1_H
   #define PDATA_LTE_Band16_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band16_PT2_H
   #define PDATA_LTE_Band16_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band16_PT3_H
   #define PDATA_LTE_Band16_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band16_PRANT_H
   #define PDATA_LTE_Band16_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band16_PTANT_H
   #define PDATA_LTE_Band16_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band17_PR1_H
   #define PDATA_LTE_Band17_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band17_PR2_H
   #define PDATA_LTE_Band17_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band17_PR3_H
   #define PDATA_LTE_Band17_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band17_PT1_H
   #define PDATA_LTE_Band17_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band17_PT2_H
   #define PDATA_LTE_Band17_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band17_PT3_H
   #define PDATA_LTE_Band17_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band17_PRANT_H
   #define PDATA_LTE_Band17_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band17_PTANT_H
   #define PDATA_LTE_Band17_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band18_PR1_H
   #define PDATA_LTE_Band18_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band18_PR2_H
   #define PDATA_LTE_Band18_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band18_PR3_H
   #define PDATA_LTE_Band18_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band18_PT1_H
   #define PDATA_LTE_Band18_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band18_PT2_H
   #define PDATA_LTE_Band18_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band18_PT3_H
   #define PDATA_LTE_Band18_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band18_PRANT_H
   #define PDATA_LTE_Band18_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band18_PTANT_H
   #define PDATA_LTE_Band18_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band19_PR1_H
   #define PDATA_LTE_Band19_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band19_PR2_H
   #define PDATA_LTE_Band19_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band19_PR3_H
   #define PDATA_LTE_Band19_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band19_PT1_H
   #define PDATA_LTE_Band19_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band19_PT2_H
   #define PDATA_LTE_Band19_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band19_PT3_H
   #define PDATA_LTE_Band19_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band19_PRANT_H
   #define PDATA_LTE_Band19_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band19_PTANT_H
   #define PDATA_LTE_Band19_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band20_PR1_H
   #define PDATA_LTE_Band20_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band20_PR2_H
   #define PDATA_LTE_Band20_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band20_PR3_H
   #define PDATA_LTE_Band20_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band20_PT1_H
   #define PDATA_LTE_Band20_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band20_PT2_H
   #define PDATA_LTE_Band20_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band20_PT3_H
   #define PDATA_LTE_Band20_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band20_PRANT_H
   #define PDATA_LTE_Band20_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band20_PTANT_H
   #define PDATA_LTE_Band20_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band21_PR1_H
   #define PDATA_LTE_Band21_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band21_PR2_H
   #define PDATA_LTE_Band21_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band21_PR3_H
   #define PDATA_LTE_Band21_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band21_PT1_H
   #define PDATA_LTE_Band21_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band21_PT2_H
   #define PDATA_LTE_Band21_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band21_PT3_H
   #define PDATA_LTE_Band21_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band21_PRANT_H
   #define PDATA_LTE_Band21_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band21_PTANT_H
   #define PDATA_LTE_Band21_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band22_PR1_H
   #define PDATA_LTE_Band22_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band22_PR2_H
   #define PDATA_LTE_Band22_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band22_PR3_H
   #define PDATA_LTE_Band22_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band22_PT1_H
   #define PDATA_LTE_Band22_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band22_PT2_H
   #define PDATA_LTE_Band22_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band22_PT3_H
   #define PDATA_LTE_Band22_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band22_PRANT_H
   #define PDATA_LTE_Band22_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band22_PTANT_H
   #define PDATA_LTE_Band22_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band23_PR1_H
   #define PDATA_LTE_Band23_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band23_PR2_H
   #define PDATA_LTE_Band23_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band23_PR3_H
   #define PDATA_LTE_Band23_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band23_PT1_H
   #define PDATA_LTE_Band23_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band23_PT2_H
   #define PDATA_LTE_Band23_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band23_PT3_H
   #define PDATA_LTE_Band23_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band23_PRANT_H
   #define PDATA_LTE_Band23_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band23_PTANT_H
   #define PDATA_LTE_Band23_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band24_PR1_H
   #define PDATA_LTE_Band24_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band24_PR2_H
   #define PDATA_LTE_Band24_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band24_PR3_H
   #define PDATA_LTE_Band24_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band24_PT1_H
   #define PDATA_LTE_Band24_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band24_PT2_H
   #define PDATA_LTE_Band24_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band24_PT3_H
   #define PDATA_LTE_Band24_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band24_PRANT_H
   #define PDATA_LTE_Band24_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band24_PTANT_H
   #define PDATA_LTE_Band24_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band25_PR1_H
   #define PDATA_LTE_Band25_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band25_PR2_H
   #define PDATA_LTE_Band25_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band25_PR3_H
   #define PDATA_LTE_Band25_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band25_PT1_H
   #define PDATA_LTE_Band25_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band25_PT2_H
   #define PDATA_LTE_Band25_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band25_PT3_H
   #define PDATA_LTE_Band25_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band25_PRANT_H
   #define PDATA_LTE_Band25_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band25_PTANT_H
   #define PDATA_LTE_Band25_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band26_PR1_H
   #define PDATA_LTE_Band26_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band26_PR2_H
   #define PDATA_LTE_Band26_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band26_PR3_H
   #define PDATA_LTE_Band26_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band26_PT1_H
   #define PDATA_LTE_Band26_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band26_PT2_H
   #define PDATA_LTE_Band26_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band26_PT3_H
   #define PDATA_LTE_Band26_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band26_PRANT_H
   #define PDATA_LTE_Band26_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band26_PTANT_H
   #define PDATA_LTE_Band26_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band27_PR1_H
   #define PDATA_LTE_Band27_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band27_PR2_H
   #define PDATA_LTE_Band27_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band27_PR3_H
   #define PDATA_LTE_Band27_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band27_PT1_H
   #define PDATA_LTE_Band27_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band27_PT2_H
   #define PDATA_LTE_Band27_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band27_PT3_H
   #define PDATA_LTE_Band27_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band27_PRANT_H
   #define PDATA_LTE_Band27_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band27_PTANT_H
   #define PDATA_LTE_Band27_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band28_PR1_H
   #define PDATA_LTE_Band28_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band28_PR2_H
   #define PDATA_LTE_Band28_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band28_PR3_H
   #define PDATA_LTE_Band28_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band28_PT1_H
   #define PDATA_LTE_Band28_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band28_PT2_H
   #define PDATA_LTE_Band28_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band28_PT3_H
   #define PDATA_LTE_Band28_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band28_PRANT_H
   #define PDATA_LTE_Band28_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band28_PTANT_H
   #define PDATA_LTE_Band28_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band29_PR1_H
   #define PDATA_LTE_Band29_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band29_PR2_H
   #define PDATA_LTE_Band29_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band29_PR3_H
   #define PDATA_LTE_Band29_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band29_PT1_H
   #define PDATA_LTE_Band29_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band29_PT2_H
   #define PDATA_LTE_Band29_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band29_PT3_H
   #define PDATA_LTE_Band29_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band29_PRANT_H
   #define PDATA_LTE_Band29_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band29_PTANT_H
   #define PDATA_LTE_Band29_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band30_PR1_H
   #define PDATA_LTE_Band30_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band30_PR2_H
   #define PDATA_LTE_Band30_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band30_PR3_H
   #define PDATA_LTE_Band30_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band30_PT1_H
   #define PDATA_LTE_Band30_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band30_PT2_H
   #define PDATA_LTE_Band30_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band30_PT3_H
   #define PDATA_LTE_Band30_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band30_PRANT_H
   #define PDATA_LTE_Band30_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band30_PTANT_H
   #define PDATA_LTE_Band30_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band31_PR1_H
   #define PDATA_LTE_Band31_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band31_PR2_H
   #define PDATA_LTE_Band31_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band31_PR3_H
   #define PDATA_LTE_Band31_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band31_PT1_H
   #define PDATA_LTE_Band31_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band31_PT2_H
   #define PDATA_LTE_Band31_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band31_PT3_H
   #define PDATA_LTE_Band31_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band31_PRANT_H
   #define PDATA_LTE_Band31_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band31_PTANT_H
   #define PDATA_LTE_Band31_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band32_PR1_H
   #define PDATA_LTE_Band32_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band32_PR2_H
   #define PDATA_LTE_Band32_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band32_PR3_H
   #define PDATA_LTE_Band32_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band32_PT1_H
   #define PDATA_LTE_Band32_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band32_PT2_H
   #define PDATA_LTE_Band32_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band32_PT3_H
   #define PDATA_LTE_Band32_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band32_PRANT_H
   #define PDATA_LTE_Band32_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band32_PTANT_H
   #define PDATA_LTE_Band32_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band33_PR1_H
   #define PDATA_LTE_Band33_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band33_PR2_H
   #define PDATA_LTE_Band33_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band33_PR3_H
   #define PDATA_LTE_Band33_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band33_PT1_H
   #define PDATA_LTE_Band33_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band33_PT2_H
   #define PDATA_LTE_Band33_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band33_PT3_H
   #define PDATA_LTE_Band33_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band33_PRANT_H
   #define PDATA_LTE_Band33_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band33_PTANT_H
   #define PDATA_LTE_Band33_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band34_PR1_H
   #define PDATA_LTE_Band34_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band34_PR2_H
   #define PDATA_LTE_Band34_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band34_PR3_H
   #define PDATA_LTE_Band34_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band34_PT1_H
   #define PDATA_LTE_Band34_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band34_PT2_H
   #define PDATA_LTE_Band34_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band34_PT3_H
   #define PDATA_LTE_Band34_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band34_PRANT_H
   #define PDATA_LTE_Band34_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band34_PTANT_H
   #define PDATA_LTE_Band34_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band35_PR1_H
   #define PDATA_LTE_Band35_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band35_PR2_H
   #define PDATA_LTE_Band35_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band35_PR3_H
   #define PDATA_LTE_Band35_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band35_PT1_H
   #define PDATA_LTE_Band35_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band35_PT2_H
   #define PDATA_LTE_Band35_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band35_PT3_H
   #define PDATA_LTE_Band35_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band35_PRANT_H
   #define PDATA_LTE_Band35_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band35_PTANT_H
   #define PDATA_LTE_Band35_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band36_PR1_H
   #define PDATA_LTE_Band36_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band36_PR2_H
   #define PDATA_LTE_Band36_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band36_PR3_H
   #define PDATA_LTE_Band36_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band36_PT1_H
   #define PDATA_LTE_Band36_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band36_PT2_H
   #define PDATA_LTE_Band36_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band36_PT3_H
   #define PDATA_LTE_Band36_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band36_PRANT_H
   #define PDATA_LTE_Band36_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band36_PTANT_H
   #define PDATA_LTE_Band36_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band37_PR1_H
   #define PDATA_LTE_Band37_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band37_PR2_H
   #define PDATA_LTE_Band37_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band37_PR3_H
   #define PDATA_LTE_Band37_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band37_PT1_H
   #define PDATA_LTE_Band37_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band37_PT2_H
   #define PDATA_LTE_Band37_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band37_PT3_H
   #define PDATA_LTE_Band37_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band37_PRANT_H
   #define PDATA_LTE_Band37_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band37_PTANT_H
   #define PDATA_LTE_Band37_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band38_PR1_H
   #define PDATA_LTE_Band38_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band38_PR2_H
   #define PDATA_LTE_Band38_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band38_PR3_H
   #define PDATA_LTE_Band38_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band38_PT1_H
   #define PDATA_LTE_Band38_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band38_PT2_H
   #define PDATA_LTE_Band38_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band38_PT3_H
   #define PDATA_LTE_Band38_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band38_PRANT_H
   #define PDATA_LTE_Band38_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band38_PTANT_H
   #define PDATA_LTE_Band38_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band39_PR1_H
   #define PDATA_LTE_Band39_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band39_PR2_H
   #define PDATA_LTE_Band39_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band39_PR3_H
   #define PDATA_LTE_Band39_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band39_PT1_H
   #define PDATA_LTE_Band39_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band39_PT2_H
   #define PDATA_LTE_Band39_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band39_PT3_H
   #define PDATA_LTE_Band39_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band39_PRANT_H
   #define PDATA_LTE_Band39_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band39_PTANT_H
   #define PDATA_LTE_Band39_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band40_PR1_H
   #define PDATA_LTE_Band40_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band40_PR2_H
   #define PDATA_LTE_Band40_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band40_PR3_H
   #define PDATA_LTE_Band40_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band40_PT1_H
   #define PDATA_LTE_Band40_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band40_PT2_H
   #define PDATA_LTE_Band40_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band40_PT3_H
   #define PDATA_LTE_Band40_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band40_PRANT_H
   #define PDATA_LTE_Band40_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band40_PTANT_H
   #define PDATA_LTE_Band40_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band41_PR1_H
   #define PDATA_LTE_Band41_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band41_PR2_H
   #define PDATA_LTE_Band41_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band41_PR3_H
   #define PDATA_LTE_Band41_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band41_PT1_H
   #define PDATA_LTE_Band41_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band41_PT2_H
   #define PDATA_LTE_Band41_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band41_PT3_H
   #define PDATA_LTE_Band41_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band41_PRANT_H
   #define PDATA_LTE_Band41_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band41_PTANT_H
   #define PDATA_LTE_Band41_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band42_PR1_H
   #define PDATA_LTE_Band42_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band42_PR2_H
   #define PDATA_LTE_Band42_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band42_PR3_H
   #define PDATA_LTE_Band42_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band42_PT1_H
   #define PDATA_LTE_Band42_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band42_PT2_H
   #define PDATA_LTE_Band42_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band42_PT3_H
   #define PDATA_LTE_Band42_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band42_PRANT_H
   #define PDATA_LTE_Band42_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band42_PTANT_H
   #define PDATA_LTE_Band42_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band43_PR1_H
   #define PDATA_LTE_Band43_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band43_PR2_H
   #define PDATA_LTE_Band43_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band43_PR3_H
   #define PDATA_LTE_Band43_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band43_PT1_H
   #define PDATA_LTE_Band43_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band43_PT2_H
   #define PDATA_LTE_Band43_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band43_PT3_H
   #define PDATA_LTE_Band43_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band43_PRANT_H
   #define PDATA_LTE_Band43_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band43_PTANT_H
   #define PDATA_LTE_Band43_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band44_PR1_H
   #define PDATA_LTE_Band44_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band44_PR2_H
   #define PDATA_LTE_Band44_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band44_PR3_H
   #define PDATA_LTE_Band44_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band44_PT1_H
   #define PDATA_LTE_Band44_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band44_PT2_H
   #define PDATA_LTE_Band44_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band44_PT3_H
   #define PDATA_LTE_Band44_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band44_PRANT_H
   #define PDATA_LTE_Band44_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band44_PTANT_H
   #define PDATA_LTE_Band44_PTANT_H      LTE_PDATA_OFF
#endif

#ifndef    PDATA_LTE_Band66_PR1_H
   #define PDATA_LTE_Band66_PR1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band66_PR2_H
   #define PDATA_LTE_Band66_PR2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band66_PR3_H
   #define PDATA_LTE_Band66_PR3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band66_PT1_H
   #define PDATA_LTE_Band66_PT1_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band66_PT2_H
   #define PDATA_LTE_Band66_PT2_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band66_PT3_H
   #define PDATA_LTE_Band66_PT3_H        LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band66_PRANT_H
   #define PDATA_LTE_Band66_PRANT_H      LTE_PDATA_OFF
#endif
#ifndef    PDATA_LTE_Band66_PTANT_H
   #define PDATA_LTE_Band66_PTANT_H      LTE_PDATA_OFF
#endif



/** IO Port Setting */

#define IO_NON_USED(tp,sb)          tp##_IO_##sb##1

/* Define BANDx_RX_IO_SEL */
#ifndef BAND1_RX_IO_SEL
   #define BAND1_RX_IO_SEL          IO_NON_USED(RX,MB)
#endif
#ifndef BAND2_RX_IO_SEL
   #define BAND2_RX_IO_SEL          IO_NON_USED(RX,MB)
#endif
#ifndef BAND3_RX_IO_SEL
   #define BAND3_RX_IO_SEL          IO_NON_USED(RX,MB)
#endif
#ifndef BAND4_RX_IO_SEL
   #define BAND4_RX_IO_SEL          IO_NON_USED(RX,MB)
#endif
#ifndef BAND5_RX_IO_SEL
   #define BAND5_RX_IO_SEL          IO_NON_USED(RX,LB)
#endif
#ifndef BAND6_RX_IO_SEL
   #define BAND6_RX_IO_SEL          IO_NON_USED(RX,LB)
#endif
#ifndef BAND7_RX_IO_SEL
   #define BAND7_RX_IO_SEL          IO_NON_USED(RX,HB)
#endif
#ifndef BAND8_RX_IO_SEL
   #define BAND8_RX_IO_SEL          IO_NON_USED(RX,LB)
#endif
#ifndef BAND9_RX_IO_SEL
   #define BAND9_RX_IO_SEL          IO_NON_USED(RX,MB)
#endif
#ifndef BAND11_RX_IO_SEL
   #define BAND11_RX_IO_SEL         IO_NON_USED(RX,MB)
#endif
#ifndef BAND12_RX_IO_SEL
   #define BAND12_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND13_RX_IO_SEL
   #define BAND13_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND14_RX_IO_SEL
   #define BAND14_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND17_RX_IO_SEL
   #define BAND17_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND18_RX_IO_SEL
   #define BAND18_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND19_RX_IO_SEL
   #define BAND19_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND20_RX_IO_SEL
   #define BAND20_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND21_RX_IO_SEL
   #define BAND21_RX_IO_SEL         IO_NON_USED(RX,MB)
#endif
#ifndef BAND25_RX_IO_SEL
   #define BAND25_RX_IO_SEL         IO_NON_USED(RX,MB)
#endif
#ifndef BAND26_RX_IO_SEL
   #define BAND26_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND28_RX_IO_SEL
   #define BAND28_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND34_RX_IO_SEL
   #define BAND34_RX_IO_SEL         IO_NON_USED(RX,MB)
#endif
#ifndef BAND38_RX_IO_SEL
   #define BAND38_RX_IO_SEL         IO_NON_USED(RX,HB)
#endif
#ifndef BAND39_RX_IO_SEL
   #define BAND39_RX_IO_SEL         IO_NON_USED(RX,MB)
#endif
#ifndef BAND40_RX_IO_SEL
   #define BAND40_RX_IO_SEL         IO_NON_USED(RX,HB)
#endif
#ifndef BAND41_RX_IO_SEL
   #define BAND41_RX_IO_SEL         IO_NON_USED(RX,HB)
#endif
#ifndef BAND66_RX_IO_SEL
   #define BAND66_RX_IO_SEL         IO_NON_USED(RX,HB)
#endif

/* Define BANDx_RXD_IO_SEL */
#ifndef BAND1_RXD_IO_SEL
   #define BAND1_RXD_IO_SEL         IO_NON_USED(RXD,MB)
#endif
#ifndef BAND2_RXD_IO_SEL
   #define BAND2_RXD_IO_SEL         IO_NON_USED(RXD,MB)
#endif
#ifndef BAND3_RXD_IO_SEL
   #define BAND3_RXD_IO_SEL         IO_NON_USED(RXD,MB)
#endif
#ifndef BAND4_RXD_IO_SEL
   #define BAND4_RXD_IO_SEL         IO_NON_USED(RXD,MB)
#endif
#ifndef BAND5_RXD_IO_SEL
   #define BAND5_RXD_IO_SEL         IO_NON_USED(RXD,LB)
#endif
#ifndef BAND6_RXD_IO_SEL
   #define BAND6_RXD_IO_SEL         IO_NON_USED(RXD,LB)
#endif
#ifndef BAND7_RXD_IO_SEL
   #define BAND7_RXD_IO_SEL         IO_NON_USED(RXD,HB)
#endif
#ifndef BAND8_RXD_IO_SEL
   #define BAND8_RXD_IO_SEL         IO_NON_USED(RXD,LB)
#endif
#ifndef BAND9_RXD_IO_SEL
   #define BAND9_RXD_IO_SEL         IO_NON_USED(RXD,MB)
#endif
#ifndef BAND11_RXD_IO_SEL
   #define BAND11_RXD_IO_SEL        IO_NON_USED(RXD,MB)
#endif
#ifndef BAND12_RXD_IO_SEL
   #define BAND12_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND13_RXD_IO_SEL
   #define BAND13_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND14_RXD_IO_SEL
   #define BAND14_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND17_RXD_IO_SEL
   #define BAND17_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND18_RXD_IO_SEL
   #define BAND18_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND19_RXD_IO_SEL
   #define BAND19_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND20_RXD_IO_SEL
   #define BAND20_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND21_RXD_IO_SEL
   #define BAND21_RXD_IO_SEL        IO_NON_USED(RXD,MB)
#endif
#ifndef BAND25_RXD_IO_SEL
   #define BAND25_RXD_IO_SEL        IO_NON_USED(RXD,MB)
#endif
#ifndef BAND26_RXD_IO_SEL
   #define BAND26_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND28_RXD_IO_SEL
   #define BAND28_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND34_RXD_IO_SEL
   #define BAND34_RXD_IO_SEL        IO_NON_USED(RXD,MB)
#endif
#ifndef BAND38_RXD_IO_SEL
   #define BAND38_RXD_IO_SEL        IO_NON_USED(RXD,HB)
#endif
#ifndef BAND39_RXD_IO_SEL
   #define BAND39_RXD_IO_SEL        IO_NON_USED(RXD,MB)
#endif
#ifndef BAND40_RXD_IO_SEL
   #define BAND40_RXD_IO_SEL        IO_NON_USED(RXD,HB)
#endif
#ifndef BAND41_RXD_IO_SEL
   #define BAND41_RXD_IO_SEL        IO_NON_USED(RXD,HB)
#endif
#ifndef BAND66_RXD_IO_SEL
   #define BAND66_RXD_IO_SEL        IO_NON_USED(RXD,HB)
#endif

/* Define BANDx_TX_IO_SEL */
#ifndef BAND1_TX_IO_SEL
   #define BAND1_TX_IO_SEL          IO_NON_USED(TX,MB)
#endif
#ifndef BAND2_TX_IO_SEL
   #define BAND2_TX_IO_SEL          IO_NON_USED(TX,MB)
#endif
#ifndef BAND3_TX_IO_SEL
   #define BAND3_TX_IO_SEL          IO_NON_USED(TX,MB)
#endif
#ifndef BAND4_TX_IO_SEL
   #define BAND4_TX_IO_SEL          IO_NON_USED(TX,MB)
#endif
#ifndef BAND5_TX_IO_SEL
   #define BAND5_TX_IO_SEL          IO_NON_USED(TX,LB)
#endif
#ifndef BAND6_TX_IO_SEL
   #define BAND6_TX_IO_SEL          IO_NON_USED(TX,LB)
#endif
#ifndef BAND7_TX_IO_SEL
   #define BAND7_TX_IO_SEL          IO_NON_USED(TX,HB)
#endif
#ifndef BAND8_TX_IO_SEL
   #define BAND8_TX_IO_SEL          IO_NON_USED(TX,LB)
#endif
#ifndef BAND9_TX_IO_SEL
   #define BAND9_TX_IO_SEL          IO_NON_USED(TX,MB)
#endif
#ifndef BAND11_TX_IO_SEL
   #define BAND11_TX_IO_SEL         IO_NON_USED(TX,MB)
#endif
#ifndef BAND12_TX_IO_SEL
   #define BAND12_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND13_TX_IO_SEL
   #define BAND13_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND14_TX_IO_SEL
   #define BAND14_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND17_TX_IO_SEL
   #define BAND17_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND18_TX_IO_SEL
   #define BAND18_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND19_TX_IO_SEL
   #define BAND19_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND20_TX_IO_SEL
   #define BAND20_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND21_TX_IO_SEL
   #define BAND21_TX_IO_SEL         IO_NON_USED(TX,MB)
#endif
#ifndef BAND25_TX_IO_SEL
   #define BAND25_TX_IO_SEL         IO_NON_USED(TX,MB)
#endif
#ifndef BAND26_TX_IO_SEL
   #define BAND26_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND28_TX_IO_SEL
   #define BAND28_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND34_TX_IO_SEL
   #define BAND34_TX_IO_SEL         IO_NON_USED(TX,MB)
#endif
#ifndef BAND38_TX_IO_SEL
   #define BAND38_TX_IO_SEL         IO_NON_USED(TX,HB)
#endif
#ifndef BAND39_TX_IO_SEL
   #define BAND39_TX_IO_SEL         IO_NON_USED(TX,MB)
#endif
#ifndef BAND40_TX_IO_SEL
   #define BAND40_TX_IO_SEL         IO_NON_USED(TX,HB)
#endif
#ifndef BAND41_TX_IO_SEL
   #define BAND41_TX_IO_SEL         IO_NON_USED(TX,HB)
#endif
#ifndef BAND66_TX_IO_SEL
   #define BAND66_TX_IO_SEL         IO_NON_USED(TX,HB)
#endif

/* Define LTE_Bandx_RX_IO_SEL */
#ifndef LTE_Band1_RX_IO_SEL
   #define LTE_Band1_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band2_RX_IO_SEL
   #define LTE_Band2_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band3_RX_IO_SEL
   #define LTE_Band3_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band4_RX_IO_SEL
   #define LTE_Band4_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band5_RX_IO_SEL
   #define LTE_Band5_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band6_RX_IO_SEL
   #define LTE_Band6_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band7_RX_IO_SEL
   #define LTE_Band7_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band8_RX_IO_SEL
   #define LTE_Band8_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band9_RX_IO_SEL
   #define LTE_Band9_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band11_RX_IO_SEL
   #define LTE_Band11_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band12_RX_IO_SEL
   #define LTE_Band12_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band13_RX_IO_SEL
   #define LTE_Band13_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band14_RX_IO_SEL
   #define LTE_Band14_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band17_RX_IO_SEL
   #define LTE_Band17_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band18_RX_IO_SEL
   #define LTE_Band18_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band19_RX_IO_SEL
   #define LTE_Band19_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band20_RX_IO_SEL
   #define LTE_Band20_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band21_RX_IO_SEL
   #define LTE_Band21_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band25_RX_IO_SEL
   #define LTE_Band25_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band26_RX_IO_SEL
   #define LTE_Band26_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band28_RX_IO_SEL
   #define LTE_Band28_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band34_RX_IO_SEL
   #define LTE_Band34_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band38_RX_IO_SEL
   #define LTE_Band38_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band39_RX_IO_SEL
   #define LTE_Band39_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band40_RX_IO_SEL
   #define LTE_Band40_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band41_RX_IO_SEL
   #define LTE_Band41_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band66_RX_IO_SEL
   #define LTE_Band66_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif

/* Define LTE_Bandx_RXD_IO_SEL */
#ifndef LTE_Band1_RXD_IO_SEL
   #define LTE_Band1_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band2_RXD_IO_SEL
   #define LTE_Band2_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band3_RXD_IO_SEL
   #define LTE_Band3_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band4_RXD_IO_SEL
   #define LTE_Band4_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band5_RXD_IO_SEL
   #define LTE_Band5_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band6_RXD_IO_SEL
   #define LTE_Band6_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band7_RXD_IO_SEL
   #define LTE_Band7_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band8_RXD_IO_SEL
   #define LTE_Band8_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band9_RXD_IO_SEL
   #define LTE_Band9_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band11_RXD_IO_SEL
   #define LTE_Band11_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band12_RXD_IO_SEL
   #define LTE_Band12_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band13_RXD_IO_SEL
   #define LTE_Band13_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band14_RXD_IO_SEL
   #define LTE_Band14_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band17_RXD_IO_SEL
   #define LTE_Band17_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band18_RXD_IO_SEL
   #define LTE_Band18_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band19_RXD_IO_SEL
   #define LTE_Band19_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band20_RXD_IO_SEL
   #define LTE_Band20_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band21_RXD_IO_SEL
   #define LTE_Band21_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band25_RXD_IO_SEL
   #define LTE_Band25_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band26_RXD_IO_SEL
   #define LTE_Band26_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band28_RXD_IO_SEL
   #define LTE_Band28_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band34_RXD_IO_SEL
   #define LTE_Band34_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band38_RXD_IO_SEL
   #define LTE_Band38_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band39_RXD_IO_SEL
   #define LTE_Band39_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band40_RXD_IO_SEL
   #define LTE_Band40_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band41_RXD_IO_SEL
   #define LTE_Band41_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band66_RXD_IO_SEL
   #define LTE_Band66_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif

/* Define LTE_Bandx_TX_IO_SEL */
#ifndef LTE_Band1_TX_IO_SEL
   #define LTE_Band1_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band2_TX_IO_SEL
   #define LTE_Band2_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band3_TX_IO_SEL
   #define LTE_Band3_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band4_TX_IO_SEL
   #define LTE_Band4_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band5_TX_IO_SEL
   #define LTE_Band5_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band6_TX_IO_SEL
   #define LTE_Band6_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band7_TX_IO_SEL
   #define LTE_Band7_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band8_TX_IO_SEL
   #define LTE_Band8_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band9_TX_IO_SEL
   #define LTE_Band9_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band11_TX_IO_SEL
   #define LTE_Band11_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band12_TX_IO_SEL
   #define LTE_Band12_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band13_TX_IO_SEL
   #define LTE_Band13_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band14_TX_IO_SEL
   #define LTE_Band14_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band17_TX_IO_SEL
   #define LTE_Band17_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band18_TX_IO_SEL
   #define LTE_Band18_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band19_TX_IO_SEL
   #define LTE_Band19_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band20_TX_IO_SEL
   #define LTE_Band20_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band21_TX_IO_SEL
   #define LTE_Band21_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band25_TX_IO_SEL
   #define LTE_Band25_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band26_TX_IO_SEL
   #define LTE_Band26_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band28_TX_IO_SEL
   #define LTE_Band28_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band29_TX_IO_SEL
   #define LTE_Band29_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band30_TX_IO_SEL
   #define LTE_Band30_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band32_TX_IO_SEL
   #define LTE_Band32_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band34_TX_IO_SEL
   #define LTE_Band34_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band38_TX_IO_SEL
   #define LTE_Band38_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band39_TX_IO_SEL
   #define LTE_Band39_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band40_TX_IO_SEL
   #define LTE_Band40_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band41_TX_IO_SEL
   #define LTE_Band41_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band66_TX_IO_SEL
   #define LTE_Band66_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif

/* Define LTE_Bandx_TX_DET_IO_SEL */
#ifndef LTE_Band1_TX_DET_IO_SEL
   #define LTE_Band1_TX_DET_IO_SEL    LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band2_TX_DET_IO_SEL
   #define LTE_Band2_TX_DET_IO_SEL    LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band3_TX_DET_IO_SEL
   #define LTE_Band3_TX_DET_IO_SEL    LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band4_TX_DET_IO_SEL
   #define LTE_Band4_TX_DET_IO_SEL    LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band5_TX_DET_IO_SEL
   #define LTE_Band5_TX_DET_IO_SEL    LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band6_TX_DET_IO_SEL
   #define LTE_Band6_TX_DET_IO_SEL    LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band7_TX_DET_IO_SEL
   #define LTE_Band7_TX_DET_IO_SEL    LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band8_TX_DET_IO_SEL
   #define LTE_Band8_TX_DET_IO_SEL    LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band9_TX_DET_IO_SEL
   #define LTE_Band9_TX_DET_IO_SEL    LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band11_TX_DET_IO_SEL
   #define LTE_Band11_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band12_TX_DET_IO_SEL
   #define LTE_Band12_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band13_TX_DET_IO_SEL
   #define LTE_Band13_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band14_TX_DET_IO_SEL
   #define LTE_Band14_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band17_TX_DET_IO_SEL
   #define LTE_Band17_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band18_TX_DET_IO_SEL
   #define LTE_Band18_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band19_TX_DET_IO_SEL
   #define LTE_Band19_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band20_TX_DET_IO_SEL
   #define LTE_Band20_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band21_TX_DET_IO_SEL
   #define LTE_Band21_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band25_TX_DET_IO_SEL
   #define LTE_Band25_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band26_TX_DET_IO_SEL
   #define LTE_Band26_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band28_TX_DET_IO_SEL
   #define LTE_Band28_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band29_TX_DET_IO_SEL
   #define LTE_Band29_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band30_TX_DET_IO_SEL
   #define LTE_Band30_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band32_TX_DET_IO_SEL
   #define LTE_Band32_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band34_TX_DET_IO_SEL
   #define LTE_Band34_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band38_TX_DET_IO_SEL
   #define LTE_Band38_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band39_TX_DET_IO_SEL
   #define LTE_Band39_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band40_TX_DET_IO_SEL
   #define LTE_Band40_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band41_TX_DET_IO_SEL
   #define LTE_Band41_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif
#ifndef LTE_Band66_TX_DET_IO_SEL
   #define LTE_Band66_TX_DET_IO_SEL   LTE_BandNone_TX_DET_IO_SEL
#endif


/* Define LTE_Bandx_MPR_QPSK1 */
#ifndef LTE_Band1_MPR_QPSK1
   #define LTE_Band1_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band2_MPR_QPSK1
   #define LTE_Band2_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band3_MPR_QPSK1
   #define LTE_Band3_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band4_MPR_QPSK1
   #define LTE_Band4_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band5_MPR_QPSK1
   #define LTE_Band5_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band6_MPR_QPSK1
   #define LTE_Band6_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band7_MPR_QPSK1
   #define LTE_Band7_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band8_MPR_QPSK1
   #define LTE_Band8_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band9_MPR_QPSK1
   #define LTE_Band9_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band11_MPR_QPSK1
   #define LTE_Band11_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band12_MPR_QPSK1
   #define LTE_Band12_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band13_MPR_QPSK1
   #define LTE_Band13_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band14_MPR_QPSK1
   #define LTE_Band14_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band17_MPR_QPSK1
   #define LTE_Band17_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band18_MPR_QPSK1
   #define LTE_Band18_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band19_MPR_QPSK1
   #define LTE_Band19_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band20_MPR_QPSK1
   #define LTE_Band20_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band21_MPR_QPSK1
   #define LTE_Band21_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band25_MPR_QPSK1
   #define LTE_Band25_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band26_MPR_QPSK1
   #define LTE_Band26_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band28_MPR_QPSK1
   #define LTE_Band28_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band34_MPR_QPSK1
   #define LTE_Band34_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band38_MPR_QPSK1
   #define LTE_Band38_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band39_MPR_QPSK1
   #define LTE_Band39_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band40_MPR_QPSK1
   #define LTE_Band40_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band41_MPR_QPSK1
   #define LTE_Band41_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band66_MPR_QPSK1
   #define LTE_Band66_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif

/* Define LTE_Bandx_MPR_16QAM0 */
#ifndef LTE_Band1_MPR_16QAM0
   #define LTE_Band1_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band2_MPR_16QAM0
   #define LTE_Band2_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band3_MPR_16QAM0
   #define LTE_Band3_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band4_MPR_16QAM0
   #define LTE_Band4_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band5_MPR_16QAM0
   #define LTE_Band5_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band6_MPR_16QAM0
   #define LTE_Band6_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band7_MPR_16QAM0
   #define LTE_Band7_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band8_MPR_16QAM0
   #define LTE_Band8_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band9_MPR_16QAM0
   #define LTE_Band9_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band11_MPR_16QAM0
   #define LTE_Band11_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band12_MPR_16QAM0
   #define LTE_Band12_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band13_MPR_16QAM0
   #define LTE_Band13_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band14_MPR_16QAM0
   #define LTE_Band14_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band17_MPR_16QAM0
   #define LTE_Band17_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band18_MPR_16QAM0
   #define LTE_Band18_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band19_MPR_16QAM0
   #define LTE_Band19_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band20_MPR_16QAM0
   #define LTE_Band20_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band21_MPR_16QAM0
   #define LTE_Band21_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band25_MPR_16QAM0
   #define LTE_Band25_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band26_MPR_16QAM0
   #define LTE_Band26_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band28_MPR_16QAM0
   #define LTE_Band28_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band34_MPR_16QAM0
   #define LTE_Band34_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band38_MPR_16QAM0
   #define LTE_Band38_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band39_MPR_16QAM0
   #define LTE_Band39_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band40_MPR_16QAM0
   #define LTE_Band40_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band41_MPR_16QAM0
   #define LTE_Band41_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band66_MPR_16QAM0
   #define LTE_Band66_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif

/* Define LTE_Bandx_MPR_16QAM1 */
#ifndef LTE_Band1_MPR_16QAM1
   #define LTE_Band1_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band2_MPR_16QAM1
   #define LTE_Band2_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band3_MPR_16QAM1
   #define LTE_Band3_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band4_MPR_16QAM1
   #define LTE_Band4_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band5_MPR_16QAM1
   #define LTE_Band5_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band6_MPR_16QAM1
   #define LTE_Band6_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band7_MPR_16QAM1
   #define LTE_Band7_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band8_MPR_16QAM1
   #define LTE_Band8_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band9_MPR_16QAM1
   #define LTE_Band9_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band11_MPR_16QAM1
   #define LTE_Band11_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band12_MPR_16QAM1
   #define LTE_Band12_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band13_MPR_16QAM1
   #define LTE_Band13_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band14_MPR_16QAM1
   #define LTE_Band14_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band17_MPR_16QAM1
   #define LTE_Band17_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band18_MPR_16QAM1
   #define LTE_Band18_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band19_MPR_16QAM1
   #define LTE_Band19_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band20_MPR_16QAM1
   #define LTE_Band20_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band21_MPR_16QAM1
   #define LTE_Band21_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band25_MPR_16QAM1
   #define LTE_Band25_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band26_MPR_16QAM1
   #define LTE_Band26_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band28_MPR_16QAM1
   #define LTE_Band28_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band34_MPR_16QAM1
   #define LTE_Band34_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band38_MPR_16QAM1
   #define LTE_Band38_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band39_MPR_16QAM1
   #define LTE_Band39_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band40_MPR_16QAM1
   #define LTE_Band40_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band41_MPR_16QAM1
   #define LTE_Band41_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band66_MPR_16QAM1
   #define LTE_Band66_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif

/* Define LTE_Bandx_MPR_64QAM0 */
#ifndef LTE_Band1_MPR_64QAM0
   #define LTE_Band1_MPR_64QAM0     LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band2_MPR_64QAM0
   #define LTE_Band2_MPR_64QAM0     LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band3_MPR_64QAM0
   #define LTE_Band3_MPR_64QAM0     LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band4_MPR_64QAM0
   #define LTE_Band4_MPR_64QAM0     LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band5_MPR_64QAM0
   #define LTE_Band5_MPR_64QAM0     LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band6_MPR_64QAM0
   #define LTE_Band6_MPR_64QAM0     LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band7_MPR_64QAM0
   #define LTE_Band7_MPR_64QAM0     LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band8_MPR_64QAM0
   #define LTE_Band8_MPR_64QAM0     LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band9_MPR_64QAM0
   #define LTE_Band9_MPR_64QAM0     LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band11_MPR_64QAM0
   #define LTE_Band11_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band12_MPR_64QAM0
   #define LTE_Band12_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band13_MPR_64QAM0
   #define LTE_Band13_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band14_MPR_64QAM0
   #define LTE_Band14_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band17_MPR_64QAM0
   #define LTE_Band17_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band18_MPR_64QAM0
   #define LTE_Band18_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band19_MPR_64QAM0
   #define LTE_Band19_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band20_MPR_64QAM0
   #define LTE_Band20_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band21_MPR_64QAM0
   #define LTE_Band21_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band25_MPR_64QAM0
   #define LTE_Band25_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band26_MPR_64QAM0
   #define LTE_Band26_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band28_MPR_64QAM0
   #define LTE_Band28_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band34_MPR_64QAM0
   #define LTE_Band34_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band38_MPR_64QAM0
   #define LTE_Band38_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band39_MPR_64QAM0
   #define LTE_Band39_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band40_MPR_64QAM0
   #define LTE_Band40_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band41_MPR_64QAM0
   #define LTE_Band41_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif
#ifndef LTE_Band66_MPR_64QAM0
   #define LTE_Band66_MPR_64QAM0    LTE_BandNone_MPR_64QAM0
#endif

/* Define LTE_Bandx_MPR_64QAM1 */
#ifndef LTE_Band1_MPR_64QAM1
   #define LTE_Band1_MPR_64QAM1     LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band2_MPR_64QAM1
   #define LTE_Band2_MPR_64QAM1     LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band3_MPR_64QAM1
   #define LTE_Band3_MPR_64QAM1     LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band4_MPR_64QAM1
   #define LTE_Band4_MPR_64QAM1     LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band5_MPR_64QAM1
   #define LTE_Band5_MPR_64QAM1     LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band6_MPR_64QAM1
   #define LTE_Band6_MPR_64QAM1     LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band7_MPR_64QAM1
   #define LTE_Band7_MPR_64QAM1     LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band8_MPR_64QAM1
   #define LTE_Band8_MPR_64QAM1     LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band9_MPR_64QAM1
   #define LTE_Band9_MPR_64QAM1     LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band11_MPR_64QAM1
   #define LTE_Band11_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band12_MPR_64QAM1
   #define LTE_Band12_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band13_MPR_64QAM1
   #define LTE_Band13_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band14_MPR_64QAM1
   #define LTE_Band14_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band17_MPR_64QAM1
   #define LTE_Band17_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band18_MPR_64QAM1
   #define LTE_Band18_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band19_MPR_64QAM1
   #define LTE_Band19_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band20_MPR_64QAM1
   #define LTE_Band20_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band21_MPR_64QAM1
   #define LTE_Band21_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band25_MPR_64QAM1
   #define LTE_Band25_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band26_MPR_64QAM1
   #define LTE_Band26_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band28_MPR_64QAM1
   #define LTE_Band28_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band34_MPR_64QAM1
   #define LTE_Band34_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band38_MPR_64QAM1
   #define LTE_Band38_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band39_MPR_64QAM1
   #define LTE_Band39_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band40_MPR_64QAM1
   #define LTE_Band40_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band41_MPR_64QAM1
   #define LTE_Band41_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif
#ifndef LTE_Band66_MPR_64QAM1
   #define LTE_Band66_MPR_64QAM1    LTE_BandNone_MPR_64QAM1
#endif

/* Define LTE_Bandx_DELTA_TC0 */
#ifndef LTE_Band1_DELTA_TC0
   #define LTE_Band1_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band2_DELTA_TC0
   #define LTE_Band2_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band3_DELTA_TC0
   #define LTE_Band3_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band4_DELTA_TC0
   #define LTE_Band4_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band5_DELTA_TC0
   #define LTE_Band5_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band6_DELTA_TC0
   #define LTE_Band6_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band7_DELTA_TC0
   #define LTE_Band7_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band8_DELTA_TC0
   #define LTE_Band8_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band9_DELTA_TC0
   #define LTE_Band9_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band11_DELTA_TC0
   #define LTE_Band11_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band12_DELTA_TC0
   #define LTE_Band12_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band13_DELTA_TC0
   #define LTE_Band13_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band14_DELTA_TC0
   #define LTE_Band14_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band17_DELTA_TC0
   #define LTE_Band17_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band18_DELTA_TC0
   #define LTE_Band18_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band19_DELTA_TC0
   #define LTE_Band19_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band20_DELTA_TC0
   #define LTE_Band20_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band21_DELTA_TC0
   #define LTE_Band21_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band25_DELTA_TC0
   #define LTE_Band25_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band26_DELTA_TC0
   #define LTE_Band26_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band28_DELTA_TC0
   #define LTE_Band28_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band34_DELTA_TC0
   #define LTE_Band34_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band38_DELTA_TC0
   #define LTE_Band38_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band39_DELTA_TC0
   #define LTE_Band39_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band40_DELTA_TC0
   #define LTE_Band40_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band41_DELTA_TC0
   #define LTE_Band41_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band66_DELTA_TC0
   #define LTE_Band66_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif

/* Define LTE_Bandx_DELTA_TC1 */
#ifndef LTE_Band1_DELTA_TC1
   #define LTE_Band1_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band2_DELTA_TC1
   #define LTE_Band2_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band3_DELTA_TC1
   #define LTE_Band3_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band4_DELTA_TC1
   #define LTE_Band4_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band5_DELTA_TC1
   #define LTE_Band5_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band6_DELTA_TC1
   #define LTE_Band6_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band7_DELTA_TC1
   #define LTE_Band7_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band8_DELTA_TC1
   #define LTE_Band8_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band9_DELTA_TC1
   #define LTE_Band9_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band11_DELTA_TC1
   #define LTE_Band11_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band12_DELTA_TC1
   #define LTE_Band12_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band13_DELTA_TC1
   #define LTE_Band13_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band14_DELTA_TC1
   #define LTE_Band14_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band17_DELTA_TC1
   #define LTE_Band17_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band18_DELTA_TC1
   #define LTE_Band18_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band19_DELTA_TC1
   #define LTE_Band19_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band20_DELTA_TC1
   #define LTE_Band20_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band21_DELTA_TC1
   #define LTE_Band21_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band25_DELTA_TC1
   #define LTE_Band25_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band26_DELTA_TC1
   #define LTE_Band26_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band28_DELTA_TC1
   #define LTE_Band28_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band34_DELTA_TC1
   #define LTE_Band34_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band38_DELTA_TC1
   #define LTE_Band38_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band39_DELTA_TC1
   #define LTE_Band39_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band40_DELTA_TC1
   #define LTE_Band40_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band41_DELTA_TC1
   #define LTE_Band41_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band66_DELTA_TC1
   #define LTE_Band66_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif

/* Define LTE_AMPR */
#define LTE_AMPR_NS1                1
#define LTE_AMPR_NS2                2
#define LTE_AMPR_NS3                3
#define LTE_AMPR_NS4                4
#define LTE_AMPR_NS5                5
#define LTE_AMPR_NS6                6
#define LTE_AMPR_NS7                7
#define LTE_AMPR_NS8                8
#define LTE_AMPR_NS9                9
#define LTE_AMPR_NS10               10
#define LTE_AMPR_NS11               11
#define LTE_AMPR_NS121314           12
#define LTE_AMPR_NS15               15
#define LTE_AMPR_NS16               16
#define LTE_AMPR_NS17               17
#define LTE_AMPR_NS18               18
#define LTE_AMPR_NS19               19
#define LTE_AMPR_NS20               20
#define LTE_AMPR_NS21               21

#define LTE_BandX_AMPR_NS1          // null row
#define LTE_BandX_AMPR_NS6          // null row
#define LTE_BandX_AMPR_NS17         // null row
#ifndef LTE_Band1_NS5_SetDefault
#define LTE_Band1_AMPR_NS5          LTE_BandX_AMPR_NS1
#else
#define LTE_Band1_AMPR_NS5          { LTE_Band1 ,  LTE_AMPR_NS5      , { LTE_Band1_NS5_SetDefault      }  },
#define LTE_Band1_AMPR_NS_DEF       1
#endif
#ifndef LTE_Band2_NS3_SetDefault
#define LTE_Band2_AMPR_NS3          LTE_BandX_AMPR_NS1
#else
#define LTE_Band2_AMPR_NS3          { LTE_Band2 ,  LTE_AMPR_NS3      , { LTE_Band2_NS3_SetDefault      }  },
#define LTE_Band2_AMPR_NS_DEF       1
#endif
#ifndef LTE_Band4_NS3_SetDefault
#define LTE_Band4_AMPR_NS3          LTE_BandX_AMPR_NS1
#else
#define LTE_Band4_AMPR_NS3          { LTE_Band4 ,  LTE_AMPR_NS3      , { LTE_Band4_NS3_SetDefault      }  },
#define LTE_Band4_AMPR_NS_DEF       1
#endif
#ifndef LTE_Band10_NS3_SetDefault
#define LTE_Band10_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band10_AMPR_NS3         { LTE_Band10,  LTE_AMPR_NS3      , { LTE_Band10_NS3_SetDefault     }  },
#define LTE_Band10_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band13_NS7_SetDefault
#define LTE_Band13_AMPR_NS7         LTE_BandX_AMPR_NS1
#else
#define LTE_Band13_AMPR_NS7         { LTE_Band13,  LTE_AMPR_NS7      , { LTE_Band13_NS7_SetDefault     }  },
#define LTE_Band13_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band19_NS8_SetDefault
#define LTE_Band19_AMPR_NS8         LTE_BandX_AMPR_NS1
#else
#define LTE_Band19_AMPR_NS8         { LTE_Band19,  LTE_AMPR_NS8      , { LTE_Band19_NS8_SetDefault     }  },
#define LTE_Band19_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band20_NS10_SetDefault
#define LTE_Band20_AMPR_NS10        LTE_BandX_AMPR_NS1
#else
#define LTE_Band20_AMPR_NS10        { LTE_Band20,  LTE_AMPR_NS10     , { LTE_Band20_NS10_SetDefault    }  },
#define LTE_Band20_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band21_NS9_SetDefault
#define LTE_Band21_AMPR_NS9         LTE_BandX_AMPR_NS1
#else
#define LTE_Band21_AMPR_NS9         { LTE_Band21,  LTE_AMPR_NS9      , { LTE_Band21_NS9_SetDefault     }  },
#define LTE_Band21_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band23_NS3_SetDefault
#define LTE_Band23_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band23_AMPR_NS3         { LTE_Band23,  LTE_AMPR_NS3      , { LTE_Band23_NS3_SetDefault     }  },
#define LTE_Band23_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band23_NS11_SetDefault
#define LTE_Band23_AMPR_NS11        LTE_BandX_AMPR_NS1
#else
#define LTE_Band23_AMPR_NS11        { LTE_Band23,  LTE_AMPR_NS11     , { LTE_Band23_NS11_SetDefault    }  },
#define LTE_Band23_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band23_NS20_SetDefault
#define LTE_Band23_AMPR_NS20        LTE_BandX_AMPR_NS1
#else
#define LTE_Band23_AMPR_NS20        { LTE_Band23,  LTE_AMPR_NS20     , { LTE_Band23_NS20_SetDefault    }  },
#define LTE_Band23_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band25_NS3_SetDefault
#define LTE_Band25_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band25_AMPR_NS3         { LTE_Band25,  LTE_AMPR_NS3      , { LTE_Band25_NS3_SetDefault     }  },
#define LTE_Band25_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band26_NS121314_SetDefault
#define LTE_Band26_AMPR_NS121314    LTE_BandX_AMPR_NS1
#else
#define LTE_Band26_AMPR_NS121314    { LTE_Band26,  LTE_AMPR_NS121314 , { LTE_Band26_NS121314_SetDefault}  },
#define LTE_Band26_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band26_NS15_SetDefault
#define LTE_Band26_AMPR_NS15        LTE_BandX_AMPR_NS1
#else
#define LTE_Band26_AMPR_NS15        { LTE_Band26,  LTE_AMPR_NS15     , { LTE_Band26_NS15_SetDefault    }  },
#define LTE_Band26_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band27_NS16_SetDefault
#define LTE_Band27_AMPR_NS16        LTE_BandX_AMPR_NS1
#else
#define LTE_Band27_AMPR_NS16        { LTE_Band27,  LTE_AMPR_NS16     , { LTE_Band27_NS16_SetDefault    }  },
#define LTE_Band27_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band28_NS18_SetDefault
#define LTE_Band28_AMPR_NS18        LTE_BandX_AMPR_NS1
#else
#define LTE_Band28_AMPR_NS18        { LTE_Band28,  LTE_AMPR_NS18     , { LTE_Band28_NS18_SetDefault    }  },
#define LTE_Band28_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band30_NS21_SetDefault
#define LTE_Band30_AMPR_NS21        LTE_BandX_AMPR_NS1
#else
#define LTE_Band30_AMPR_NS21        { LTE_Band30,  LTE_AMPR_NS21     , { LTE_Band30_NS21_SetDefault    }  },
#define LTE_Band30_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band35_NS3_SetDefault
#define LTE_Band35_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band35_AMPR_NS3         { LTE_Band35,  LTE_AMPR_NS3      , { LTE_Band35_NS3_SetDefault     }  },
#define LTE_Band35_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band36_NS3_SetDefault
#define LTE_Band36_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band36_AMPR_NS3         { LTE_Band36,  LTE_AMPR_NS3      , { LTE_Band36_NS3_SetDefault     }  },
#define LTE_Band36_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band41_NS4_SetDefault
#define LTE_Band41_AMPR_NS4         LTE_BandX_AMPR_NS1
#else
#define LTE_Band41_AMPR_NS4         { LTE_Band41,  LTE_AMPR_NS4      , { LTE_Band41_NS4_SetDefault     }  },
#define LTE_Band41_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band44_NS19_SetDefault
#define LTE_Band44_AMPR_NS19        LTE_BandX_AMPR_NS1
#else
#define LTE_Band44_AMPR_NS19        { LTE_Band44,  LTE_AMPR_NS19     , { LTE_Band44_NS19_SetDefault    }  },
#define LTE_Band44_AMPR_NS_DEF      1
#endif

#if defined (__BAND_EXTENSION_SUPPORT__)
#ifndef LTE_Band66_NS3_SetDefault
#define LTE_Band66_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band66_AMPR_NS3         { LTE_Band66 ,  LTE_AMPR_NS3      , { LTE_Band66_NS3_SetDefault      }  },
#define LTE_Band66_AMPR_NS_DEF      1
#endif  //end of ifndef LTE_Band66_NS3_SetDefault
#endif  //end of defined (__BAND_EXTENSION_SUPPORT__)

//AMPR band -> NS configuration
//[Note] Please re-define LTE_AMPR_TABLE_ALL_SIZE and LTE_AMPR_TABLE_SIZE if number of the following AMPR_NS is changed
#define LTE_BandNone_AMPR_NS        LTE_BandX_AMPR_NS1
#define LTE_Band1_AMPR_NS           LTE_Band1_AMPR_NS5
#define LTE_Band2_AMPR_NS           LTE_Band2_AMPR_NS3
#define LTE_Band3_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band4_AMPR_NS           LTE_Band4_AMPR_NS3
#define LTE_Band5_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band6_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band7_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band8_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band9_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band10_AMPR_NS          LTE_Band10_AMPR_NS3
#define LTE_Band11_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band12_AMPR_NS          LTE_BandX_AMPR_NS6
#define LTE_Band13_AMPR_NS          LTE_Band13_AMPR_NS7
#define LTE_Band14_AMPR_NS          LTE_BandX_AMPR_NS6
#define LTE_Band15_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band16_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band17_AMPR_NS          LTE_BandX_AMPR_NS6
#define LTE_Band18_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band19_AMPR_NS          LTE_Band19_AMPR_NS8
#define LTE_Band20_AMPR_NS          LTE_Band20_AMPR_NS10
#define LTE_Band21_AMPR_NS          LTE_Band21_AMPR_NS9
#define LTE_Band22_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band23_AMPR_NS          LTE_Band23_AMPR_NS3      \
                                    LTE_Band23_AMPR_NS11     \
                                    LTE_Band23_AMPR_NS20
#define LTE_Band24_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band25_AMPR_NS          LTE_Band25_AMPR_NS3
#define LTE_Band26_AMPR_NS          LTE_Band26_AMPR_NS121314 \
                                    LTE_Band26_AMPR_NS15
#define LTE_Band27_AMPR_NS          LTE_Band27_AMPR_NS16
#define LTE_Band28_AMPR_NS          LTE_Band28_AMPR_NS18
#define LTE_Band29_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band30_AMPR_NS          LTE_Band30_AMPR_NS21
#define LTE_Band31_AMPR_NS          LTE_BandX_AMPR_NS1

#if IS_4G_BAND32_SUPPORT
#define LTE_Band32_AMPR_NS          LTE_BandX_AMPR_NS1
#endif
#define LTE_Band33_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band34_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band35_AMPR_NS          LTE_Band35_AMPR_NS3
#define LTE_Band36_AMPR_NS          LTE_Band36_AMPR_NS3
#define LTE_Band37_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band38_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band39_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band40_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band41_AMPR_NS          LTE_Band41_AMPR_NS4
#define LTE_Band42_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band43_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band44_AMPR_NS          LTE_Band44_AMPR_NS19
#if defined (__BAND_EXTENSION_SUPPORT__)
#define LTE_Band66_AMPR_NS          LTE_Band66_AMPR_NS3
#endif

#define LTE_AMPR_NS_DEFAULT         { LTE_BandNone, 0, {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }} }

//DRDI use, in the end of LTE_AMPRAdjustTbl_All
#define LTE_BandMax_AMPR_NS         { LTE_BandMax, 0, {{0}} },

#ifndef IS_AMPR_VZW_SUPPORT_SetDefault
#define IS_AMPR_VZW_SUPPORT_SetDefault    IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set0
#define IS_AMPR_VZW_SUPPORT_Set0          IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set1
#define IS_AMPR_VZW_SUPPORT_Set1          IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set2
#define IS_AMPR_VZW_SUPPORT_Set2          IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set3
#define IS_AMPR_VZW_SUPPORT_Set3          IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set4
#define IS_AMPR_VZW_SUPPORT_Set4          IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set5
#define IS_AMPR_VZW_SUPPORT_Set5          IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set6
#define IS_AMPR_VZW_SUPPORT_Set6          IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set7
#define IS_AMPR_VZW_SUPPORT_Set7          IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set8
#define IS_AMPR_VZW_SUPPORT_Set8          IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set9
#define IS_AMPR_VZW_SUPPORT_Set9          IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set10
#define IS_AMPR_VZW_SUPPORT_Set10         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set11
#define IS_AMPR_VZW_SUPPORT_Set11         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set12
#define IS_AMPR_VZW_SUPPORT_Set12         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set13
#define IS_AMPR_VZW_SUPPORT_Set13         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set14
#define IS_AMPR_VZW_SUPPORT_Set14         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set15
#define IS_AMPR_VZW_SUPPORT_Set15         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set16
#define IS_AMPR_VZW_SUPPORT_Set16         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set17
#define IS_AMPR_VZW_SUPPORT_Set17         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set18
#define IS_AMPR_VZW_SUPPORT_Set18         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set19
#define IS_AMPR_VZW_SUPPORT_Set19         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set20
#define IS_AMPR_VZW_SUPPORT_Set20         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set21
#define IS_AMPR_VZW_SUPPORT_Set21         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set22
#define IS_AMPR_VZW_SUPPORT_Set22         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set23
#define IS_AMPR_VZW_SUPPORT_Set23         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set24
#define IS_AMPR_VZW_SUPPORT_Set24         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set25
#define IS_AMPR_VZW_SUPPORT_Set25         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set26
#define IS_AMPR_VZW_SUPPORT_Set26         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set27
#define IS_AMPR_VZW_SUPPORT_Set27         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set28
#define IS_AMPR_VZW_SUPPORT_Set28         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set29
#define IS_AMPR_VZW_SUPPORT_Set29         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set30
#define IS_AMPR_VZW_SUPPORT_Set30         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set31
#define IS_AMPR_VZW_SUPPORT_Set31         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set32
#define IS_AMPR_VZW_SUPPORT_Set32         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set33
#define IS_AMPR_VZW_SUPPORT_Set33         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set34
#define IS_AMPR_VZW_SUPPORT_Set34         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set35
#define IS_AMPR_VZW_SUPPORT_Set35         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set36
#define IS_AMPR_VZW_SUPPORT_Set36         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set37
#define IS_AMPR_VZW_SUPPORT_Set37         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set38
#define IS_AMPR_VZW_SUPPORT_Set38         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set39
#define IS_AMPR_VZW_SUPPORT_Set39         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set40
#define IS_AMPR_VZW_SUPPORT_Set40         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set41
#define IS_AMPR_VZW_SUPPORT_Set41         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set42
#define IS_AMPR_VZW_SUPPORT_Set42         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set43
#define IS_AMPR_VZW_SUPPORT_Set43         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set44
#define IS_AMPR_VZW_SUPPORT_Set44         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set45
#define IS_AMPR_VZW_SUPPORT_Set45         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set46
#define IS_AMPR_VZW_SUPPORT_Set46         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set47
#define IS_AMPR_VZW_SUPPORT_Set47         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set48
#define IS_AMPR_VZW_SUPPORT_Set48         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set49
#define IS_AMPR_VZW_SUPPORT_Set49         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set50
#define IS_AMPR_VZW_SUPPORT_Set50         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set51
#define IS_AMPR_VZW_SUPPORT_Set51         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set52
#define IS_AMPR_VZW_SUPPORT_Set52         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set53
#define IS_AMPR_VZW_SUPPORT_Set53         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set54
#define IS_AMPR_VZW_SUPPORT_Set54         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set55
#define IS_AMPR_VZW_SUPPORT_Set55         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set56
#define IS_AMPR_VZW_SUPPORT_Set56         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set57
#define IS_AMPR_VZW_SUPPORT_Set57         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set58
#define IS_AMPR_VZW_SUPPORT_Set58         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set59
#define IS_AMPR_VZW_SUPPORT_Set59         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set60
#define IS_AMPR_VZW_SUPPORT_Set60         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set61
#define IS_AMPR_VZW_SUPPORT_Set61         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set62
#define IS_AMPR_VZW_SUPPORT_Set62         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set63
#define IS_AMPR_VZW_SUPPORT_Set63         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set64
#define IS_AMPR_VZW_SUPPORT_Set64         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set65
#define IS_AMPR_VZW_SUPPORT_Set65         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set66
#define IS_AMPR_VZW_SUPPORT_Set66         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set67
#define IS_AMPR_VZW_SUPPORT_Set67         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set68
#define IS_AMPR_VZW_SUPPORT_Set68         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set69
#define IS_AMPR_VZW_SUPPORT_Set69         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set70
#define IS_AMPR_VZW_SUPPORT_Set70         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set71
#define IS_AMPR_VZW_SUPPORT_Set71         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set72
#define IS_AMPR_VZW_SUPPORT_Set72         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set73
#define IS_AMPR_VZW_SUPPORT_Set73         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set74
#define IS_AMPR_VZW_SUPPORT_Set74         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set75
#define IS_AMPR_VZW_SUPPORT_Set75         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set76
#define IS_AMPR_VZW_SUPPORT_Set76         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set77
#define IS_AMPR_VZW_SUPPORT_Set77         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set78
#define IS_AMPR_VZW_SUPPORT_Set78         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set79
#define IS_AMPR_VZW_SUPPORT_Set79         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set80
#define IS_AMPR_VZW_SUPPORT_Set80         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set81
#define IS_AMPR_VZW_SUPPORT_Set81         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set82
#define IS_AMPR_VZW_SUPPORT_Set82         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set83
#define IS_AMPR_VZW_SUPPORT_Set83         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set84
#define IS_AMPR_VZW_SUPPORT_Set84         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set85
#define IS_AMPR_VZW_SUPPORT_Set85         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set86
#define IS_AMPR_VZW_SUPPORT_Set86         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set87
#define IS_AMPR_VZW_SUPPORT_Set87         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set88
#define IS_AMPR_VZW_SUPPORT_Set88         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set89
#define IS_AMPR_VZW_SUPPORT_Set89         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set90
#define IS_AMPR_VZW_SUPPORT_Set90         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set91
#define IS_AMPR_VZW_SUPPORT_Set91         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set92
#define IS_AMPR_VZW_SUPPORT_Set92         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set93
#define IS_AMPR_VZW_SUPPORT_Set93         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set94
#define IS_AMPR_VZW_SUPPORT_Set94         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set95
#define IS_AMPR_VZW_SUPPORT_Set95         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set96
#define IS_AMPR_VZW_SUPPORT_Set96         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set97
#define IS_AMPR_VZW_SUPPORT_Set97         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set98
#define IS_AMPR_VZW_SUPPORT_Set98         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set99
#define IS_AMPR_VZW_SUPPORT_Set99         IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set100
#define IS_AMPR_VZW_SUPPORT_Set100        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set101
#define IS_AMPR_VZW_SUPPORT_Set101        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set102
#define IS_AMPR_VZW_SUPPORT_Set102        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set103
#define IS_AMPR_VZW_SUPPORT_Set103        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set104
#define IS_AMPR_VZW_SUPPORT_Set104        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set105
#define IS_AMPR_VZW_SUPPORT_Set105        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set106
#define IS_AMPR_VZW_SUPPORT_Set106        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set107
#define IS_AMPR_VZW_SUPPORT_Set107        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set108
#define IS_AMPR_VZW_SUPPORT_Set108        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set109
#define IS_AMPR_VZW_SUPPORT_Set109        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set110
#define IS_AMPR_VZW_SUPPORT_Set110        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set111
#define IS_AMPR_VZW_SUPPORT_Set111        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set112
#define IS_AMPR_VZW_SUPPORT_Set112        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set113
#define IS_AMPR_VZW_SUPPORT_Set113        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set114
#define IS_AMPR_VZW_SUPPORT_Set114        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set115
#define IS_AMPR_VZW_SUPPORT_Set115        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set116
#define IS_AMPR_VZW_SUPPORT_Set116        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set117
#define IS_AMPR_VZW_SUPPORT_Set117        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set118
#define IS_AMPR_VZW_SUPPORT_Set118        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set119
#define IS_AMPR_VZW_SUPPORT_Set119        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set120
#define IS_AMPR_VZW_SUPPORT_Set120        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set121
#define IS_AMPR_VZW_SUPPORT_Set121        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set122
#define IS_AMPR_VZW_SUPPORT_Set122        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set123
#define IS_AMPR_VZW_SUPPORT_Set123        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set124
#define IS_AMPR_VZW_SUPPORT_Set124        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set125
#define IS_AMPR_VZW_SUPPORT_Set125        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set126
#define IS_AMPR_VZW_SUPPORT_Set126        IS_AMPR_VZW_NOT_SUPPORT
#endif
#ifndef IS_AMPR_VZW_SUPPORT_Set127
#define IS_AMPR_VZW_SUPPORT_Set127        IS_AMPR_VZW_NOT_SUPPORT
#endif

/*******************************************************************************
 * #define
 ******************************************************************************/


/*******************************************************************************
 * Typedef
 ******************************************************************************/

/*******************************************************************************
 * Constant
 ******************************************************************************/

/*******************************************************************************
 * Global variables (Extern)
 ******************************************************************************/




/*******************************************************************************
 * Global Functions Prototype (Interface)
 ******************************************************************************/


#endif /*__EL1D_RF_COMMON_H__*/

/* Doxygen Group End ***************************************************//**@}*/
