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
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
/* Doxygen Group Header ****************************************************//**
 * @addtogroup EL1D_RF_CUSTOM_DATA
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @file       lrfcustomdata.h
 * @author     LY Chen (MTK04356)
 * @date       2014.12.16
 * @brief      EL1D SHM data header file
 * @details
 ******************************************************************************/

#ifndef  __LRFCUSTOMDATA_H__
#define  __LRFCUSTOMDATA_H__

/*******************************************************************************
 * #include
 ******************************************************************************/
#include "el1d_rf_custom_data.h"  //RF custom data structure definition
#include "el1d_rf_common.h"
#include "lte_custom_drdi.h"

/*******************************************************************************
 * #define
 ******************************************************************************/
#define LTE_Band_PDATA_PR1(b,s)      PDATA_##b##_PR1_##s
#define LTE_PDATA_PR1(b,s)           LTE_Band_PDATA_PR1(b,s)

#define LTE_Band_PDATA_PR2(b,s)      PDATA_##b##_PR2_##s
#define LTE_PDATA_PR2(b,s)           LTE_Band_PDATA_PR2(b,s)

#define LTE_Band_PDATA_PR3(b,s)      PDATA_##b##_PR3_##s
#define LTE_PDATA_PR3(b,s)           LTE_Band_PDATA_PR3(b,s)

#define LTE_Band_PDATA_PT1(b,s)      PDATA_##b##_PT1_##s
#define LTE_PDATA_PT1(b,s)           LTE_Band_PDATA_PT1(b,s)

#define LTE_Band_PDATA_PT2(b,s)      PDATA_##b##_PT2_##s
#define LTE_PDATA_PT2(b,s)           LTE_Band_PDATA_PT2(b,s)

#define LTE_Band_PDATA_PT3(b,s)      PDATA_##b##_PT3_##s
#define LTE_PDATA_PT3(b,s)           LTE_Band_PDATA_PT3(b,s)

#define LTE_Band_RX_IO(b,s)          b##_RX_IO_SEL_##s
#define LTE_RX_IO(b,s)               LTE_Band_RX_IO(b,s)

#define LTE_Band_RXD_IO(b,s)         b##_RXD_IO_SEL_##s
#define LTE_RXD_IO(b,s)              LTE_Band_RXD_IO(b,s)

#define LTE_Band_TX_IO(b,s)          b##_TX_IO_SEL_##s
#define LTE_TX_IO(b,s)               LTE_Band_TX_IO(b,s)

#define LTE_Band_TX_DET_IO(b,s)      b##_TX_DET_IO_SEL_##s
#define LTE_TX_DET_IO(b,s)           LTE_Band_TX_DET_IO(b,s)

#define LTE_Band_MPR_QPSK1(b,s)      b##_MPR_QPSK1_##s
#define LTE_MPR_QPSK1(b,s)           LTE_Band_MPR_QPSK1(b,s)

#define LTE_Band_MPR_16QAM0(b,s)     b##_MPR_16QAM0_##s
#define LTE_MPR_16QAM0(b,s)          LTE_Band_MPR_16QAM0(b,s)

#define LTE_Band_MPR_16QAM1(b,s)     b##_MPR_16QAM1_##s
#define LTE_MPR_16QAM1(b,s)          LTE_Band_MPR_16QAM1(b,s)

#if IS_MPR_64QAM_SUPPORT
#define LTE_Band_MPR_64QAM0(b,s)     b##_MPR_64QAM0_##s
#define LTE_MPR_64QAM0(b,s)          LTE_Band_MPR_64QAM0(b,s)

#define LTE_Band_MPR_64QAM1(b,s)     b##_MPR_64QAM1_##s
#define LTE_MPR_64QAM1(b,s)          LTE_Band_MPR_64QAM1(b,s)
#endif  // End of IS_MPR_64QAM_SUPPORT

#define LTE_Band_DELTA_TC0(b,s)      b##_DELTA_TC0_##s
#define LTE_DELTA_TC0(b,s)           LTE_Band_DELTA_TC0(b,s)

#define LTE_Band_DELTA_TC1(b,s)      b##_DELTA_TC1_##s
#define LTE_DELTA_TC1(b,s)           LTE_Band_DELTA_TC1(b,s)

#define LTE_Band_AMPR_NS(b)          b##_AMPR_NS
#define LTE_AMPR_NS(b)               LTE_Band_AMPR_NS(b)
#define LTE_RF_AMPR_ADJUST(b)        LTE_Band_AMPR_NS(b)


/*============================================================================*/

#define LTE_RF_RX_PDATABASE(b,s)                                               \
{  b,                                                                          \
   {  {0x00000000, PDATA_LTE_BANDX_PR0 },                                      \
      {0x00000000, LTE_PDATA_PR1(b,s)},                                        \
      {0x00000000, LTE_PDATA_PR2(b,s)},                                        \
      {0x00000000, LTE_PDATA_PR3(b,s)},                                        \
      {0x00000000, PDATA_LTE_BANDX_PR3B},                                      \
      {0x00000000, PDATA_LTE_BANDX_PR3C}                                       \
   }                                                                           \
}

#define LTE_RF_TX_PDATABASE(b,s)                                               \
{  b,                                                                          \
   {  {0x00000000, PDATA_LTE_BANDX_PT0},                                       \
      {0x00000000, LTE_PDATA_PT1(b,s)},                                        \
      {0x00000000, LTE_PDATA_PT2(b,s)},                                        \
      {0x00000000, LTE_PDATA_PT3(b,s)}                                         \
   }                                                                           \
}

#define LTE_RF_RXIOBASE(b,s)                                                   \
{ b, {LTE_RX_IO(b,s), LTE_RXD_IO(b,s)}                                         \
}

#define LTE_RF_TXIOBASE(b,s)                                                   \
{ b, {LTE_TX_IO(b,s), LTE_TX_DET_IO(b,s)}                                      \
}

#define LTE_RF_MPR_ADJUST(b,s)                                                 \
{ b,  LTE_MPR_QPSK1(b,s), LTE_MPR_16QAM0(b,s), LTE_MPR_16QAM1(b,s),            \
      LTE_DELTA_TC0(b,s), LTE_DELTA_TC1(b,s)                                   \
}

#if IS_MPR_64QAM_SUPPORT
#define LTE_RF_MPR_ADJUST_64QAM(b,s)                                           \
{ b,  LTE_MPR_64QAM0(b,s), LTE_MPR_64QAM1(b,s),                                \
}
#endif  // End of IS_MPR_64QAM_SUPPORT

/*******************************************************************************
 * Typedef
 ******************************************************************************/

/*******************************************************************************
 * Constant
 ******************************************************************************/

// QPSK Param
#define LTE_SPBF_QPSK_DEFAULT                 0      // 0 ~ 7*32 (unit: 1/32dB, unsigned integer, default: 0)
#define LTE_BandNone_SPBF_QPSK                LTE_SPBF_QPSK_DEFAULT
#define LTE_Band1_SPBF_QPSK                   LTE_SPBF_QPSK_DEFAULT
#define LTE_Band2_SPBF_QPSK                   LTE_SPBF_QPSK_DEFAULT
#define LTE_Band3_SPBF_QPSK                   LTE_SPBF_QPSK_DEFAULT
#define LTE_Band4_SPBF_QPSK                   LTE_SPBF_QPSK_DEFAULT
#define LTE_Band5_SPBF_QPSK                   LTE_SPBF_QPSK_DEFAULT
#define LTE_Band6_SPBF_QPSK                   LTE_SPBF_QPSK_DEFAULT
#define LTE_Band7_SPBF_QPSK                   LTE_SPBF_QPSK_DEFAULT
#define LTE_Band8_SPBF_QPSK                   LTE_SPBF_QPSK_DEFAULT
#define LTE_Band9_SPBF_QPSK                   LTE_SPBF_QPSK_DEFAULT
#define LTE_Band10_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band11_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band12_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band13_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band14_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band17_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band18_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band19_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band20_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band21_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band23_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band24_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band25_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band26_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band27_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band28_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band29_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band30_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band32_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band33_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band34_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band35_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band36_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band37_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band38_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band39_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band40_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band41_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band44_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT
#define LTE_Band66_SPBF_QPSK                  LTE_SPBF_QPSK_DEFAULT

// 16QAM Param
#define LTE_SPBF_16QAM_DEFAULT                0      // 0 ~ 7*32 (unit: 1/32dB, unsigned integer, default: 0)
#define LTE_BandNone_SPBF_16QAM               LTE_SPBF_16QAM_DEFAULT
#define LTE_Band1_SPBF_16QAM                  LTE_SPBF_16QAM_DEFAULT
#define LTE_Band2_SPBF_16QAM                  LTE_SPBF_16QAM_DEFAULT
#define LTE_Band3_SPBF_16QAM                  LTE_SPBF_16QAM_DEFAULT
#define LTE_Band4_SPBF_16QAM                  LTE_SPBF_16QAM_DEFAULT
#define LTE_Band5_SPBF_16QAM                  LTE_SPBF_16QAM_DEFAULT
#define LTE_Band6_SPBF_16QAM                  LTE_SPBF_16QAM_DEFAULT
#define LTE_Band7_SPBF_16QAM                  LTE_SPBF_16QAM_DEFAULT
#define LTE_Band8_SPBF_16QAM                  LTE_SPBF_16QAM_DEFAULT
#define LTE_Band9_SPBF_16QAM                  LTE_SPBF_16QAM_DEFAULT
#define LTE_Band10_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band11_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band12_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band13_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band14_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band17_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band18_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band19_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band20_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band21_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band23_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band24_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band25_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band26_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band27_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band28_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band29_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band30_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band32_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band33_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band34_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band35_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band36_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band37_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band38_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band39_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band40_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band41_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band44_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT
#define LTE_Band66_SPBF_16QAM                 LTE_SPBF_16QAM_DEFAULT

// PUSCH Param
#define LTE_SPBF_PUSCH_RB_THRES_DEFAULT       2      // 1 ~ 8 (RB, unsigned integer, default: 2)
#define LTE_BandNone_SPBF_PUSCH_RB_THRES      LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band1_SPBF_PUSCH_RB_THRES         LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band2_SPBF_PUSCH_RB_THRES         LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band3_SPBF_PUSCH_RB_THRES         LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band4_SPBF_PUSCH_RB_THRES         LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band5_SPBF_PUSCH_RB_THRES         LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band6_SPBF_PUSCH_RB_THRES         LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band7_SPBF_PUSCH_RB_THRES         LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band8_SPBF_PUSCH_RB_THRES         LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band9_SPBF_PUSCH_RB_THRES         LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band10_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band11_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band12_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band13_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band14_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band17_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band18_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band19_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band20_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band21_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band23_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band24_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band25_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band26_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band27_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band28_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band29_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band30_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band32_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band33_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band34_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band35_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band36_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band37_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band38_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band39_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band40_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band41_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band44_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT
#define LTE_Band66_SPBF_PUSCH_RB_THRES        LTE_SPBF_PUSCH_RB_THRES_DEFAULT

#define LTE_SPBF_PUSCH_DEFAULT                0      // 0 ~ 15*32 (unit: 1/32dB, unsigned integer, default: 0)
#define LTE_BandNone_SPBF_PUSCH               LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band1_SPBF_PUSCH                  128
#define LTE_Band2_SPBF_PUSCH                  LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band3_SPBF_PUSCH                  LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band4_SPBF_PUSCH                  LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band5_SPBF_PUSCH                  LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band6_SPBF_PUSCH                  LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band7_SPBF_PUSCH                  96
#define LTE_Band8_SPBF_PUSCH                  LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band9_SPBF_PUSCH                  LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band10_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band11_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band12_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band13_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band14_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band17_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band18_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band19_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band20_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band21_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band23_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band24_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band25_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band26_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band27_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band28_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band29_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band30_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band32_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band33_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band34_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band35_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band36_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band37_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band38_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band39_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band40_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band41_SPBF_PUSCH                 96
#define LTE_Band44_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT
#define LTE_Band66_SPBF_PUSCH                 LTE_SPBF_PUSCH_DEFAULT

#if IS_4G_ELNA_SUPPORT
/* ------------- LTE_ELNA_BANDX_SetNotSupport Start ----------------*/
#define  ELNA_LTE_BandNone_SetNotSupport          LTE_ELNA_OFF
#define  ELNA_LTE_Band1_SetNotSupport             LTE_ELNA_OFF
#define  ELNA_LTE_Band2_SetNotSupport             LTE_ELNA_OFF
#define  ELNA_LTE_Band3_SetNotSupport             LTE_ELNA_OFF
#define  ELNA_LTE_Band4_SetNotSupport             LTE_ELNA_OFF
#define  ELNA_LTE_Band5_SetNotSupport             LTE_ELNA_OFF
#define  ELNA_LTE_Band6_SetNotSupport             LTE_ELNA_OFF
#define  ELNA_LTE_Band7_SetNotSupport             LTE_ELNA_OFF
#define  ELNA_LTE_Band8_SetNotSupport             LTE_ELNA_OFF
#define  ELNA_LTE_Band9_SetNotSupport             LTE_ELNA_OFF
#define  ELNA_LTE_Band10_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band11_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band12_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band13_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band14_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band15_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band16_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band17_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band18_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band19_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band20_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band21_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band22_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band23_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band24_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band25_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band26_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band27_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band28_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band29_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band30_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band31_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band32_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band33_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band34_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band35_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band36_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band37_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band38_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band39_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band40_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band41_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band42_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band43_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band44_SetNotSupport            LTE_ELNA_OFF
#define  ELNA_LTE_Band66_SetNotSupport            LTE_ELNA_OFF
/* -------------- LTE_ELNA_BANDX_SetNotSupport End -----------------*/
#endif

/*******************************************************************************
 * Global variables (Extern)
 ******************************************************************************/

/** RF custom data (raw data from .h) */
extern           ERF_FRONT_END_USAGE_T       ERF_RF_FRONT_END_USAGE_TBL[LTE_MAX_SUPPORT_FE_ROUTE_NUM];

extern const     ERF_RX_PDATABASE_T          ERF_RX_PDATABASE_BandNone;
extern const     ERF_TX_PDATABASE_T          ERF_TX_PDATABASE_BandNone;
extern const     ERF_RXIOBASE_T              ERF_RF_RXIOBASE_BandNone;
extern const     ERF_TXIOBASE_T              ERF_RF_TXIOBASE_BandNone;

extern /*const*/ LTE_EVT_TIME_OFST_TABLE_T   ERF_EVT_TIME_OFST_TABLE;
extern /*const*/ LTE_FE_ROUTE_DATABASE_T     LTE_FRONT_END_ROUTE_DATABASE;
extern /*const*/ LTE_ANT_ROUTE_DATABASE_T    LTE_ANT_ROUTE_DATABASE;
extern           LTE_VPA_SOURCE_DATABASE_T   LTE_VPA_SOURCE_CONFIG_DATABASE;
extern const     LTE_CA_CFG_E                LTE_CA_CFG_IND_RELEASE[LTE_TARGET_MAX_SUPPORT_CA_BAND_NUM];
extern           ERF_PARTIAL_BAND_IND_T      ERF_RF_PARTIAL_BAND_IND[LTE_PARTIAL_BAND_SUPPORT_NUM];
#if IS_4G_ELNA_SUPPORT
// eLNA parameters
extern           LTE_FE_ELNA_DATABASE_T      LTE_ELNA_TABLE;
#endif

#if IS_4G_HPUE_FEATURE_SUPPORT
extern /*const*/ LTE_RF_HPUE_PARAMETER_T     ERF_HPUE_PARAMETER;
extern LTE_AMPR_NS04_HPUE_T ERF_AMPR_NS04_HPUE_PARAMETER;
#endif

//Transmint Antenna Selection Feature
extern /*const*/ LTE_RF_TAS_PARAMETER      ERF_TAS_PARAMETER;
#if IS_4G_TAS_INIT_SUPPORT
extern           kal_uint32                ERF_TAS_INIT_IND[LTE_ERF_TAS_BAND_NUM];
#endif


#if defined(__LTE_NCCA_CHECK_SUPPORT__)
extern const LTE_EARFCN_FREQ_SET_PCORE_T LTE_EUTRA_EARFCN_FREQ_DL_UL_PCORE_TABLE[LTE_BandCount];
#endif

/******************************************************************************
 * Dynamic Radio-setting Dedicated Image
 *
 * Description: extern global variables for EPHY calculation
 ******************************************************************************/
extern LTE_DRDI_DEBUG_INFO_T LTE_DRDI_DEBUG_INFO;
extern kal_bool              el1_custom_dynamic_init_enable;
extern kal_uint16            el1_custom_total_set_nums;
extern kal_uint16            el1_custom_total_real_set_nums;
/*------------- Dynamic Radio-setting Dedicated Image -------------*/



/*******************************************************************************
 * Global Functions Prototype (Interface)
 ******************************************************************************/



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
#endif

#endif //__LRFCUSTOMDATA_H__

/* Doxygen Group End ***************************************************//**@}*/
