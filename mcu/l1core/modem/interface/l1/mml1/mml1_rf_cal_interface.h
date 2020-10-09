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
 *   mml1_rf_cal_interface.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   Multi-Mode Multi-RAT Layer1 RF Calibration interface to each RAT
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *
 * removed!
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
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _MML1_RF_CAL_INTERFACE_H_
#define  _MML1_RF_CAL_INTERFACE_H_

/*===============================================================================*/
#include "kal_general_types.h"
#include "mml1_rf_cal_def.h"
#include "mmrf_cc_global.h"
#include "mml1_rf_cid.h"
#include "mml1_rf_transceiver.h"
#include "mml1_rf_global.h"

/*===============================================================================*/
/*        Define for Multi-Mode RF Calibration                                   */
/*===============================================================================*/

/*Feature Compile Option*/
#define MMRFC_G14B_WORKAROUND                (1)
#define IS_MMRFC_TX_FDIQ_LS_ALGOR            (1)
#define IS_MMRFC_RESULT_CHECK_SUPPORT        (1)
#define IS_MMRFC_RESULT_ASSERT_CHECK         (0)
#define IS_TXK_MEAS_AFIFO_WORKAROUND         (1) ///<[WHQA0026052] SW workaround to keep AFIFO(between DETADC and CIC) enable during two TXFDIQ/TXIQ test tones

#ifdef TK6291_E1EVB
#define IS_DPD_4DB_ABB_GAIN_MODE_CAL_SUPPORT (0)
#else
#define IS_DPD_4DB_ABB_GAIN_MODE_CAL_SUPPORT (1)
#endif

#if IS_MML1_RF_XL1SIM
	#define IS_MMRFC_RESULT_TRACE_CHECK_SUPPORT  (0)
#else
	#define IS_MMRFC_RESULT_TRACE_CHECK_SUPPORT  (1)
#endif

#define IS_MMRFC_IRR_CRITERION_RELAXATION_ENABLE (1)

#if IS_DPD_4DB_ABB_GAIN_MODE_CAL_SUPPORT
#define MMRFC_TX_LPF_NOMINAL_VALUE           168
#define MMRFC_TX_ABB_GAIN_MODE_NUM             2  ///< ABB 0dB/4dB mode
#else
#define MMRFC_TX_LPF_NOMINAL_VALUE            80
#define MMRFC_TX_ABB_GAIN_MODE_NUM             1  ///< ABB 0dB mode only
#endif
#define MMRFC_TX_RCF_NOMINAL_VALUE            22

#define MMRFC_IIP2_ACC_LEN_POC                12  ///<IIP2 accumulation length=2^12 for POC
#define MMRFC_IIP2_NOISE_MEAS_ACC_LEN_POC     13  ///<IIP2 Noise meas accumulation length=2^13 for POC
#define MMRFC_IIP2_ACC_LEN_PBC                 8  ///<IIP2 accumulation length=2^8 for pre-burst cal
#define MMRFC_RXDC_ACC_LEN_POC                15  ///<RX DC accumulation length=2^15 for POC
#define MMRFC_RXDC_SCALE_FACTOR            180*8  ///<RX DC scale factor, u10.0
#define MMRFC_PLK_ACC_LEN_TST                 15  ///<PathLoss Cal accumulation length=2^15

#define MMRFC_MAX_TONE_PAIRS         5                                 ///<maximum numbers of tone pairs for TX calibration
#define MMRFC_MAX_TONE_PAIRS_PADDED  3                                 ///<maximum numbers of padded tone pairs for TX calibration
#define MMRFC_MAX_TONES              2 * MMRFC_MAX_TONE_PAIRS          ///<maximum numbers of tones for TX calibration
#define MMRFC_MAX_TONES_PADDED       2 * MMRFC_MAX_TONE_PAIRS_PADDED   ///<maximum numbers of padded tones for TX calibration

#define MMRFC_NCO_PHI_NUM            4
#define MMRFC_DET_DC_COMP_SET        2
#define MMRFC_DET_FIIQ_COMP_SET      2
#define MMRFC_DET_FDIQ_COMP_SET      1

#define MMRFC_RXMS_IQK_MEM_NUM       3  ///< IQK measurement engine output
#define MMRFC_RXMS_RXK_MEM_NUM       4  ///< RXK measurement engine output

/** Bitmap for nco_phi_bmp to indicate which NCO PHI should be updated*/
#define MMRFC_NCO_PHI_NONE           0x0000
#define MMRFC_NCO_PHI_0              0x0001
#define MMRFC_NCO_PHI_1              0x0002
#define MMRFC_NCO_PHI_2              0x0004
#define MMRFC_NCO_PHI_3              0x0008

/** Bitmap to indicate which compensation set should be applied on DET DFE */
/**   0: DET_DC_I_0/DET_DC_Q_0/DET_FIIQ_GAIN_0/DET_FIIQ_PHASE_0            */
/**   1: DET_DC_I_1/DET_DC_Q_1/DET_FIIQ_GAIN_1/DET_FIIQ_PHASE_1            */
#define MMRFC_DET_COMP_SEL_MEAS01_SET0  0x0000 //for measurement sel 0/1
#define MMRFC_DET_COMP_SEL_MEAS01_SET1  0x0001 //for measurement sel 0/1
#define MMRFC_DET_COMP_SEL_MEAS23_SET0  0x0000 //for measurement sel 2/3
#define MMRFC_DET_COMP_SEL_MEAS23_SET1  0x0002 //for measurement sel 2/3
#define MMRFC_DET_COMP_SEL_MEAS45_SET0  0x0000 //for measurement sel 4/5
#define MMRFC_DET_COMP_SEL_MEAS45_SET1  0x0004 //for measurement sel 4/5
#define MMRFC_DET_COMP_SEL_MEAS67_SET0  0x0000 //for measurement sel 6/7
#define MMRFC_DET_COMP_SEL_MEAS67_SET1  0x0008 //for measurement sel 6/7

/** Maximum support band number among RATs,
  * should be dominated by LTE band support nunber */
#define MMRFC_XL1_MAX_SUPPORT_BAND_NUM       (LTE_TARGET_MAX_SUPPORT_BAND_NUM)

/** Define calibration item list bitmap according to order */
#define MMRFC_POC_CAL_ORDER_LO_DET_CDCOC      (0x00001)
#define MMRFC_POC_CAL_ORDER_DET_FD_IQ         (0x00002)
#define MMRFC_POC_CAL_ORDER_DET_FI_IQ         (0x00002)
#define MMRFC_POC_CAL_ORDER_DET_FINE_DC_FWD   (0x00002)
#define MMRFC_POC_CAL_ORDER_DET_FINE_DC_REV   (0x00002)
#define MMRFC_POC_CAL_ORDER_DET_IQ_DC_DNL     (0x00002)
#define MMRFC_POC_CAL_ORDER_DET_DNL           (0x00002)
#define MMRFC_POC_CAL_ORDER_TX_RCCAL          (0x00004)
#define MMRFC_POC_CAL_ORDER_TX_PRE_CAP_TUNING (0x00008)
#define MMRFC_POC_CAL_ORDER_TX_FD_IQ          (0x00010)
#define MMRFC_POC_CAL_ORDER_TX_FI_IQ_DC       (0x00020)
#define MMRFC_POC_CAL_ORDER_TX_CAP_TUNING     (0x00040)
#define MMRFC_POC_CAL_ORDER_TX_DNL            (0x00080)
#define MMRFC_POC_CAL_ORDER_TX_GA             (0x00100)
#define MMRFC_POC_CAL_ORDER_TX_PGA_AB_GAIN    (0x00200)
#define MMRFC_POC_CAL_ORDER_TX_PGA_AB_PHASE   (0x00400)
//All RX CAL item must be After TX CAL item
#define MMRFC_POC_CAL_ORDER_RX_DCOC           (0x00800)
#define MMRFC_POC_CAL_ORDER_RX_IQ             (0x04000)
#define MMRFC_POC_CAL_ORDER_RX_IIP2           (0x08000)
//STX DCC Cal
#define MMRFC_POC_CAL_ORDER_STX_DCC           (0x10000)

#define MMRFC_POC_CAL_ORDER_TX_ITEMS_ALL     (MMRFC_POC_CAL_ORDER_LO_DET_CDCOC | MMRFC_POC_CAL_ORDER_DET_IQ_DC_DNL  | MMRFC_POC_CAL_ORDER_TX_RCCAL | MMRFC_POC_CAL_ORDER_TX_PRE_CAP_TUNING | MMRFC_POC_CAL_ORDER_TX_FD_IQ | MMRFC_POC_CAL_ORDER_TX_FI_IQ_DC | MMRFC_POC_CAL_ORDER_TX_GA |MMRFC_POC_CAL_ORDER_TX_CAP_TUNING |MMRFC_POC_CAL_ORDER_TX_DNL |MMRFC_POC_CAL_ORDER_TX_PGA_AB_GAIN |MMRFC_POC_CAL_ORDER_TX_PGA_AB_PHASE )


//TODO: create CW1 table, need not run-time determine 
/** CW1 RF Mode bit field definition */
#define RF_MODE_SLEEP       0x1  ///< 0b 0001: Sleep mode
#define RF_MODE_CAL         0x2  ///< 0b 0010: Calibration mode
#define RF_MODE_WARMUP      0x4  ///< 0b 0100: Warm-up mode
#define RF_MODE_BURST       0x8  ///< 0b 1000: Burst mode

#define RF_MODE_RAT_2G      0x0  ///< 0b 0000: 2G
#define RF_MODE_RAT_FDD     0x1  ///< 0b 0001: FDD
#define RF_MODE_RAT_TDD     0x2  ///< 0b 0010: TDD
#define RF_MODE_RAT_C2K     0x3  ///< 0b 0011: CDMA2000 (C2K)

#define RF_MODE_TRX_RX      0x1  ///< 0b  001: RX
#define RF_MODE_TRX_TX      0x2  ///< 0b  010: TX
#define RF_MODE_TRX_TRX     0x3  ///< 0b  011: TRX

///< STD[0] 0: 2G TX GMSK, 1: TX EDGE 
///< STD[1] 0: 3G mode, 1: 4G mode
///< STD[2] x: reserved
#define RF_MODE_STD_2G_TX_GMSK    0x0
#define RF_MODE_STD_2G_TX_EDGE    0x1
#define RF_MODE_STD_3G            0x0
#define RF_MODE_STD_4G            0x2


#define RF_MODE_SRXON_SRX1  0x2  ///< 0b  10: SRX1 ON
#define RF_MODE_SRXON_SRX2  0x1  ///< 0b  01: SRX2 ON
#define RF_MODE_SRXON_NONE  0x0  ///< 0b  00: For FDD Tx usage

#define RF_MODE_PCCEN_SRX1  0x2  ///< 0b  10: SRX1 is PCC
#define RF_MODE_PCCEN_SRX2  0x1  ///< 0b  01: SRX2 is PCC
#define RF_MODE_PCCEN_NONE  0x0  ///< 0b  00: Not PCC


#define POC_DCOC_I_0 (-32)  //for CW335 setting ,6bit = 6'b100000 ,set -32 for calculation use
#define POC_DCOC_Q_0 (-32)  //for CW335 setting ,6bit = 6'b100000 ,set -32 for calculation use


/** RF BSI CW POR */
#define CW1_POR                                        M_RF_CW_PACK(1, 0x00000)

/** CW1: TOP Mode Control */
#define CW1_MODE_BIT                                   (16)                                       //MODE[3:0]: 0001: Sleep
#define CW1_MODE_LEN                                   ( 4)                                       //           0010: Calibration
#define CW1_MODE_MASK                                  M_RF_CW_MASK(CW1_MODE_LEN, CW1_MODE_BIT)   //           0100: Warm-up;     1000: Burst
#define CW1_RAT_BIT                                    (12)                                       //RAT[3:0]:  0000: 2G
#define CW1_RAT_LEN                                    ( 4)                                       //           0001: FDD; 0010: TDD
#define CW1_RAT_MASK                                   M_RF_CW_MASK(CW1_RAT_LEN, CW1_RAT_BIT)     //           0011: CDMA
#define CW1_TRX_BIT                                    ( 9)                                       //TRX[2:0]:  001: RX
#define CW1_TRX_LEN                                    ( 3)                                       //           010: TX
#define CW1_TRX_MASK                                   M_RF_CW_MASK(CW1_TRX_LEN, CW1_TRX_BIT)     //           011: TRX
#define CW1_STD_BIT                                    ( 6)                                       //STD[2:0]:  STD[0]: 0: 2G TX GMSK;       1: 2G TX EDGE
#define CW1_STD_LEN                                    ( 3)                                       //           STD[1]: 0: 3G mode (for SX); 1: 4G mode (for SX)
#define CW1_STD_MASK                                   M_RF_CW_MASK(CW1_STD_LEN, CW1_STD_BIT)     //           STD[2]: X: Reserved
#define CW1_SRXON_BIT                                  ( 4)                                       //[0]: SRX2_ON
#define CW1_SRXON_LEN                                  ( 2)                                       //[1]: SRX1_ON
#define CW1_SRXON_MASK                                 M_RF_CW_MASK(CW1_SRXON_LEN, CW1_SRXON_BIT)
#define CW1_PCCEN_BIT                                  ( 2)                                       //[0]: SRX2_PCC_EN
#define CW1_PCCEN_LEN                                  ( 2)                                       //[1]: SRX1_PCC_EN
#define CW1_PCCEN_MASK                                 M_RF_CW_MASK(CW1_PCCEN_LEN, CW1_PCCEN_BIT)

#define M_RF_CW1(mODE, tRX, sRXON, pCCEN, rAT, sTD)      \
                 (     M_RF_CW_FIELD(CW1_RAT,   rAT  ) | \
                       M_RF_CW_FIELD(CW1_MODE,  mODE ) | \
                       M_RF_CW_FIELD(CW1_TRX,   tRX  ) | \
                       M_RF_CW_FIELD(CW1_STD,   sTD  ) | \
                       M_RF_CW_FIELD(CW1_SRXON, sRXON) | \
                       M_RF_CW_FIELD(CW1_PCCEN, pCCEN) )
#define M_RF_CW_FIELD(fIELD, vALUE)                    ((vALUE << fIELD##_BIT) & (fIELD##_MASK))
#define M_RF_CW_MASK(lEN, bIT)                         (((1<<lEN)-1) << bIT)

//RF SRX access
#define   RF_SRX_NUM                           2          ///< nubmer of RF SRX control (as 3G subblock)
#define   RF_SRX_IDX_SRX1                      0
#define   RF_SRX_IDX_SRX2                      1
#define   RF_SRX_IDX_NULL                      0xFFFFFFFF

//RF CC operation
#define   RF_MAX_CC_NUM                        LTE_MAX_CC_NUM
#define   RF_CC_IDX_PCC                        0
#define   RF_CC_IDX_SCC                        1
#define   RF_CC_IDX_CC0                        0
#define   RF_CC_IDX_CC1                        1
#define   RF_CC_IDX_NULL                       0xFF

#define   PLK_CC_NUM                           2 

/*************modify for POC************************/

/** RF BSI CW495/499: RX LO table size */
#define RX_LO1_DIV_NUM                          6
#define RX_LO2_DIV_NUM                          5 // DIV10 is reserved

/** RF SRX bit operation */
#define RF_SRX_F_REF_26_MHZ                     260 //unit: 100kHz
#define RF_SRX_F_REF_52_MHZ                     520 //unit: 100kHz
#define RF_SRX_N_FRAC_MSB_OFFSET                12
#define RF_SRX_N_FRAC_MSB_MASK                 (0x7FF << RF_SRX_N_FRAC_MSB_OFFSET)
#if IS_MML1_LTE_BAND_EXTENSION_SUPPORT
#define MML1_GROUP_A_SUPPORT_BAND_NUM           MMPOC_XL1_BAND_NUM_BAND_44
#define MML1_GROUP_B_SUPPORT_BAND_NUM           1 //for new support band use
#define MML1_MAX_SUPPORT_BAND_NUM_SPECIAL_USE   MMPOC_XL1_BAND_NUM_BAND_66
/*
   MML1_MAX_SUPPORT_BAND_NUM_SPECIAL_USE is used only for "FREQ_RANGE" and "FREQ_CENTER".
   This is because we don't want to add so many B66 special handling in code. Moreover,
   since these two tables are relatively small, the price paid of wasting code size
   (i.e., assign zeros in these two tables) is tolerable.
*/
#else
#define MML1_MAX_SUPPORT_BAND_NUM               MMPOC_XL1_BAND_NUM_BAND_44
#endif


// for RXDFE strobe idx use
#define RX_POC_IQK_TRIG_IDX_PATH0 0
#define RX_POC_IQK_TRIG_IDX_PATH1 1
#define RX_POC_RXK_TRIG_IDX_PATH0 0
#define RX_POC_RXK_TRIG_IDX_PATH1 4
#define RX_POC_PLK_TRIG_IDX_PATH0 0
#define RX_POC_PLK_TRIG_IDX_PATH1 1

#define MMPOC_IIP2CAL_SAMPLE_PERIOD   (8)


/* Temp disable/enable some DFE API calling to avoid unsync during bring up*/
#define IS_MMRFC_DFE_DRV_ENABLE (1)

#define DET_PATH_SEL_NUM      (2)

#define MMRFC_DET_GAIN_STEPS_DET_CAL                 17//15


#define IS_MMRFC_HRM_CAL_SUPPORT  (1)


/* For Calibration Error Handling*/
#if IS_MMRFC_RESULT_CHECK_SUPPORT
#define RFC_POC_ITER_PWR         (2) // iterations = 2^RFC_POC_ITER_PWR
#else
#define RFC_POC_ITER_PWR         (0)
#endif
#define RFC_POC_ITER_NUM         (1<<RFC_POC_ITER_PWR)
#define RFC_POC_ITER_MASK        (RFC_POC_ITER_NUM-1)
#define RFC_POC_CHK_FAIL         (0x7FFF)

/*===============================================================================*/
/*        Structures for Multi-Mode RF Calibration                               */
/*===============================================================================*/
typedef enum{
    /* The following configurations are for both TX and RX */
    MMRFC_LTE_1P4MHZ,            // 0
    MMRFC_LTE_3MHZ,              // 1
    MMRFC_LTE_5MHZ,              // 2
    MMRFC_LTE_10MHZ,             // 3
    MMRFC_LTE_15MHZ,             // 4
    MMRFC_LTE_20MHZ,             // 5
    MMRFC_WCDMA_SC,              // 6
    MMRFC_WCDMA_DC,              // 7
    MMRFC_TDSCDMA,               // 8
    MMRFC_RAT_CBW_CFG_MAX,       // 9 

    /* The following configurations are for RX only (CA) */
    MMRFC_LTE_30MHZ = MMRFC_RAT_CBW_CFG_MAX,
    MMRFC_LTE_35MHZ,             // 10
    MMRFC_LTE_40MHZ,             // 11
    MMRFC_WCDMA_3C,              // 12
    MMRFC_TDSCDMA_DC,            // 13
    MMRFC_RAT_CBW_CFG_RX_MAX,    // 14
} MMRFC_RAT_CBW_CFG_E;

typedef enum
{
   MMRFC_RAT_2G,
   MMRFC_RAT_3G_FDD,
   MMRFC_RAT_3G_TDD,
   MMRFC_RAT_LTE,
   MMRFC_RAT_C2K,
   MMRFC_RAT_CNT,
} MMRFC_RAT_E;

typedef enum
{
   MMRFC_TXK_ADDA_DISABLE        = 0x0000,
   MMRFC_TXK_ADDA_DETADC_EN      = 0x0001,
   MMRFC_TXK_ADDA_TXDAC_EN       = 0x0002,
   MMRFC_TXK_ADDA_ENABLE         = 0x0003,
   MMRFC_TXK_ADDA_INVALID        = 0x0004,
} MMRFC_TXK_ADDA_BITMAP_E;

typedef enum
{
   MMRFC_ANT_NONE                = 0x0000,
   MMRFC_ANT_0                   = 0x0001,
   MMRFC_ANT_1                   = 0x0002,
   MMRFC_ANT_01                  = 0x0003,
   MMRFC_ANT_INVALID             = 0x0004,
} MMRFC_ANT_BITMAP_E;

typedef enum
{
   MMRFC_PATH_NONE                = 0x0000,
   MMRFC_PATH_1                   = 0x0001,
   MMRFC_PATH_2                   = 0x0002,
   MMRFC_PATH_12                  = 0x0003,
   MMRFC_PATH_INVALID             = 0x0004,
} MMRFC_PATH_BITMAP_E;

/* Noted : RX_HPM should be 0 and RX_LPM should be 1 , RX IRR CAL use this as loop seq. */
typedef enum
{
   MMRFC_RX_HPM = 0x0000,
   MMRFC_RX_LPM = 0x0001,   
} MMRFC_POWER_MODE_E;

/* ReUse MMRFC_POWER_MODE_E for RX IRR CAL loop */
typedef enum
{
   MMRFC_RXIRR_CAL_HPM = MMRFC_RX_HPM,
   MMRFC_RXIRR_CAL_LPM = MMRFC_RX_LPM,
   MMRFC_RXIRR_CAL_LIF = 0x0002,
} MMRFC_RXIRR_CAL_MODE_E;

typedef enum
{
   MMRFC_RXK_PHASE,
   MMRFC_RXK_GAIN,
   MMRFC_RXK_DC,
   MMRFC_DETK_PHASE,
   MMRFC_DETK_GAIN,
   MMRFC_DETK_DC,
   MMRFC_TXK_PHASE,
   MMRFC_TXK_GAIN,
   MMRFC_TXK_DC,
   MMRFC_POC_ITEM_MAX
} MMRFC_POC_ITEM_E;


typedef enum
{
   MMRFC_IMM_DETK_TRG,     ///< DET IQDCDNL
   MMRFC_IMM_TXK_TRG,      ///< TX FIIQ
   MMRFC_IMM_TXFDIQK_TRG,  ///< TX FDIQ
   MMRFC_IMM_TXASYMK_TRG,  ///< TX GA
   MMRFC_IMM_TXRCK_TRG,    ///< Tone Power Measurement (TX RC, TX DNL, PGA Cap Tuning, PGA Gain Step)
   MMRFC_IMM_TXPDK_TRG,    ///< PGA Phase Step
   MMRFC_IMM_ETDMA_TRG,
   MMRFC_IMM_TDE_FAT_TRG,
   MMRFC_IMM_DPD_FAT_TRG,
   MMRFC_IMM_CIM3_FAT_TRG,
} MMRFC_TXK_ITEM_IMM_E; //POC

typedef enum
{
   MMRFC_PBC_DETK,
   MMRFC_PBC_TXIQK,
   MMRFC_PBC_IIP2K,
} MMRFC_TXK_ITEM_PBC_E; //Pre-Burst Cal

typedef enum
{
   MMRFC_SW_TXK_TRG,     ///< TX FIIQ
   MMRFC_SW_TXFDIQK_TRG, ///< TX FDIQ
   MMRFC_SW_TXASYMK_TRG, ///< TX GA
   MMRFC_SW_TXRCK_TRG,   ///< Tone Power Measurement (TX RC, TX DNL, PGA Cap Tuning, PGA Gain Step)
   MMRFC_SW_TXPDK_TRG,   ///< PGA Phase Step
} MMRFC_TXK_ITEM_SW_MODE_E; //SW Mode

typedef enum
{
   MMRFC_TXK_FIIQ_IQ,    ///< TXK FIIQ IQ
   MMRFC_TXK_FIIQ_DC,    ///< TXK FIIQ DC
   MMRFC_TXK_FIIQ_NUM,   ///< TXK FIIQ NUM
} MMRFC_TXK_FIIQ_ITEM_E;

typedef enum
{
   MMPOC_SUB_BAND_SWITCH,    
   MMPOC_CENTRAL_BAND_SWITCH,    
} MMRFC_BAND_SWITCH_SEL_E;

typedef enum
{
   MMPOC_XL1_LOW_BAND,    
   MMPOC_XL1_MID_BAND,    
   MMPOC_XL1_HIGH_BAND,
   MMPOC_XL1_NOT_DEFINE_BAND,
} MMRFC_XL1_BAND_DEF_E;


typedef enum
{
                               /* MEM0  MEM1  MEM2 */
   MMRFC_RXMS_IQK_MUL_MASK_0,  /*  I^2     I    IQ */
   MMRFC_RXMS_IQK_MUL_MASK_1,  /*  I^2    IQ     I */
   MMRFC_RXMS_IQK_MUL_MASK_2,  /*   IQ   I^2     I */
   MMRFC_RXMS_IQK_MUL_MASK_3,  /*    I   I^2    IQ */
   MMRFC_RXMS_IQK_MUL_MASK_4,  /*   IQ     I   I^2 */
   MMRFC_RXMS_IQK_MUL_MASK_5,  /*    I    IQ   I^2 */
   MMRFC_RXMS_IQK_MUL_MASK_NUM
} MMRFC_RXMS_IQK_MUL_MASK_E;

/** Enumeration of band number for each RAT to report its band support capability */
typedef enum
{
   MMPOC_XL1_BAND_NUM_BAND_NONE,

   MMPOC_XL1_BAND_NUM_BAND_1,
   MMPOC_XL1_BAND_NUM_BAND_2,
   MMPOC_XL1_BAND_NUM_BAND_3,
   MMPOC_XL1_BAND_NUM_BAND_4,
   MMPOC_XL1_BAND_NUM_BAND_5,
   MMPOC_XL1_BAND_NUM_BAND_6,
   MMPOC_XL1_BAND_NUM_BAND_7,
   MMPOC_XL1_BAND_NUM_BAND_8,
   MMPOC_XL1_BAND_NUM_BAND_9,
   MMPOC_XL1_BAND_NUM_BAND_10,
   MMPOC_XL1_BAND_NUM_BAND_11,
   MMPOC_XL1_BAND_NUM_BAND_12,
   MMPOC_XL1_BAND_NUM_BAND_13,
   MMPOC_XL1_BAND_NUM_BAND_14,
   MMPOC_XL1_BAND_NUM_BAND_15,
   MMPOC_XL1_BAND_NUM_BAND_16,
   MMPOC_XL1_BAND_NUM_BAND_17,
   MMPOC_XL1_BAND_NUM_BAND_18,
   MMPOC_XL1_BAND_NUM_BAND_19,
   MMPOC_XL1_BAND_NUM_BAND_20,
   MMPOC_XL1_BAND_NUM_BAND_21,
   MMPOC_XL1_BAND_NUM_BAND_22,
   MMPOC_XL1_BAND_NUM_BAND_23,
   MMPOC_XL1_BAND_NUM_BAND_24,
   MMPOC_XL1_BAND_NUM_BAND_25,
   MMPOC_XL1_BAND_NUM_BAND_26,
   MMPOC_XL1_BAND_NUM_BAND_27,
   MMPOC_XL1_BAND_NUM_BAND_28,
   MMPOC_XL1_BAND_NUM_BAND_29,
   MMPOC_XL1_BAND_NUM_BAND_30,
   MMPOC_XL1_BAND_NUM_BAND_31,
   MMPOC_XL1_BAND_NUM_BAND_32,
   MMPOC_XL1_BAND_NUM_BAND_33,
   MMPOC_XL1_BAND_NUM_BAND_34,
   MMPOC_XL1_BAND_NUM_BAND_35,
   MMPOC_XL1_BAND_NUM_BAND_36,
   MMPOC_XL1_BAND_NUM_BAND_37,
   MMPOC_XL1_BAND_NUM_BAND_38,
   MMPOC_XL1_BAND_NUM_BAND_39,
   MMPOC_XL1_BAND_NUM_BAND_40,
   MMPOC_XL1_BAND_NUM_BAND_41,
   MMPOC_XL1_BAND_NUM_BAND_42,
   MMPOC_XL1_BAND_NUM_BAND_43,
   MMPOC_XL1_BAND_NUM_BAND_44,
#if IS_MML1_LTE_BAND_EXTENSION_SUPPORT
   MMPOC_XL1_BAND_NUM_BAND_66 = 66,
#endif

}MMRFC_XL1_BAND_NUM_E;

typedef enum
{
  CASE_RX_DCOC,
  CASE_RX_RC,
  CASE_RX_IRR ,
  CASE_RX_IIP2 ,
  CASE_RX_PL,
  CASE_RX_IIP2_NOISE_MEAS,
  CASE_RX_IRR_ReCal,
}MMRFC_RX_CAL_TYPE_E;

typedef enum
{
   TTG_COS_ONLY,
   TTG_SIN_ONLY,
   TTG_COS_N_P_SIN,
   TTG_COS_N_N_SIN,
} MMRFC_TXDFE_TTG_MODE_E;

typedef enum
{
   TTG_TONE_1ST,
   TTG_TONE_2ND,
   TTG_TONE_3RD,
   TTG_TONE_4TH,
   TTG_TONE_NUM,

} MMRFC_TXDFE_TTG_INDEX_E;

typedef struct{    
    kal_int16            re;    
    kal_int16            im;
} MMRFC_COMPLEX_16_T;

typedef struct{    
    kal_int32            re;    
    kal_int32            im;
} MMRFC_COMPLEX_32_T;

typedef struct{    
    kal_uint32           acc_i_sqr;
    kal_int32            acc_i;
    kal_int32            acc_iq;
    kal_int32            acc_q;
    kal_uint32           acc_q_sqr;
} MMRFC_IQK_MEAS_T;

typedef struct{    
    kal_int32            i_sin;
    kal_int32            q_sin;
    kal_int32            i_cos;
    kal_int32            q_cos;
} MMRFC_RXK_MEAS_T; ///< for RX IIP2 cal

typedef struct{    
    kal_int32            real;  ///< i_cos-q_sin
    kal_int32            image; ///< i_sin+q_cos
} MMRFC_RXK_PL_MEAS_T; ///< for RX path loss cal

typedef struct{
    kal_int32            im2_i;
    kal_int32            im2_q;
} MMRFC_IM2_SIGNAL_T;

typedef struct{    
    kal_int32            acc_i_cos;  ///< nco_acc_i_p
    kal_int32            acc_q_sin;  ///< nco_acc_q_n
    kal_int32            acc_q_cos;  ///< nco_acc_q_p
    kal_int32            acc_i_sin;  ///< nco_acc_i_n
    kal_int32            acc_i;
    kal_int32            acc_q;
} MMRFC_TXK_MEAS_T;

typedef struct{    
    kal_int32            gain_est_hw;
    kal_int32            phase_est_hw;
    kal_int16            freq_dep_filt[MMRFC_FILT_TAPS_NUM]; ///< Valid for 2-point meas.
    kal_int16            freq_dep_phase_est;                 ///< Valid for 2-point meas. for error handling
} MMRFC_RX_IRR_RESULT_T;

typedef struct
{
   kal_int16 dc_i;
   kal_int16 dc_q;
} MMRFC_RX_DC_RESULT_T;

typedef struct{    
    kal_int32            gain_est_hw;
    kal_int32            phase_est_hw;
    kal_int16            freq_dep_filt[MMRFC_FILT_TAPS_NUM]; ///< Valid for 2-point meas.
    kal_int32            dnl; 
    kal_int16            freq_dep_phase_est;                 ///< Valid for 2-point meas. for error handling
} MMRFC_DET_IQDNL_RESULT_T;

typedef struct{    
    kal_int32            dc_est_i;
    kal_int32            dc_est_q;
} MMRFC_DET_DC_RESULT_T;

typedef struct{
    kal_uint32           i_idx_opt; //optimum gate bias on I channel 
    kal_uint32           q_idx_opt; //optimum gate bias on Q channel 
} MMRFC_IIP2_RESULT_T;

typedef struct{    
    kal_int32            gain_est;
    kal_int32            phase_est;
    kal_int32            dc_est_i;
    kal_int32            dc_est_q;
    kal_int16            freq_dep_phase_tx; ///< temp output for TX FDIQ
    MMRFC_COMPLEX_16_T   freq_resp;
} MMRFC_TX_IQDC_RESULT_T;

typedef struct{    
    kal_int16            freq_dep_filt_mode1[MMRFC_FILT_TAPS_NUM]; ///< for linear mode 1
    kal_int16            freq_dep_filt_mode2[MMRFC_FILT_TAPS_NUM]; ///< for linear mode 2
    kal_int16            freq_dep_phase_est[MMRFC_MAX_TONE_PAIRS]; ///< for error handling
} MMRFC_TX_FD_FILT_RESULT_T;

typedef struct{    
    MMRFC_COMPLEX_16_T   tx_asym_filt_mode1[MMRFC_FILT_TAPS_NUM]; //for linear mode 1
    MMRFC_COMPLEX_16_T   tx_asym_filt_mode2[MMRFC_FILT_TAPS_NUM]; //for linear mode 2
    kal_int16            slope[MMRFC_TXGA_MAX_TONES-1];
    kal_int16            mag_inv_norm[MMRFC_TXGA_MAX_TONES];
} MMRFC_TX_GA_RESULT_T;

typedef struct
{
   MMRFC_TXK_ITEM_IMM_E cal_item;
   kal_uint32 tone_length;
   kal_uint32 meas_offset;
} MMRFC_TXK_IMM_CFG_T;

typedef struct
{
   MMRFC_TXK_ITEM_PBC_E cal_item;    ///< 0: DETK, 1: TXIQK, 2: IIP2K
   kal_uint32 tone_length;           ///< 0~524287, 0~2520us (uint=1/104MHz)
   kal_uint32 meas_offset;           ///< 0~32767, 0~315us (uint=1/104MHz)
   kal_uint32 time_chip;             ///< 0~2559 chip
   kal_uint32 time_slot;             ///< 0~14 slot
   kal_uint32 sel_cnt;               ///< test tone and meas. select index
   kal_uint16 is_cnt_rst;            ///< Reset for debug counter
} MMRFC_TXK_W_PBC_CFG_T;

typedef struct
{
   MMRFC_TXK_ITEM_PBC_E cal_item;    ///< 0: DETK, 1: TXIQK, 2: IIP2K
   kal_uint32 tone_length;           ///< 0~524287, 0~2520us (uint=1/104MHz)
   kal_uint32 meas_offset;           ///< 0~32767, 0~315us (uint=1/104MHz)
   kal_uint32 time_ts;               ///< 0~307199 ts
   kal_uint32 sel_cnt;               ///< test tone and meas. select index
   kal_uint16 is_cnt_rst;            ///< Reset for debug counter
} MMRFC_TXK_L_PBC_CFG_T;

typedef struct
{
   MMRFC_TXK_ITEM_PBC_E cal_item;    ///< 0: DETK, 1: TXIQK
   kal_uint32 tone_length;           ///< 0~524287, 0~2520us (uint=1/104MHz)
   kal_uint32 meas_offset;           ///< 0~32767, 0~315us (uint=1/104MHz)
   kal_uint32 time_chip;             ///< 0~8191 chip
   kal_uint32 sel_cnt;               ///< test tone and meas. select index
   kal_uint16 is_cnt_rst;            ///< Reset for debug counter
} MMRFC_TXK_T_PBC_CFG_T;

typedef struct
{
   kal_uint16 tone_sel_en;               
   kal_uint32 tone_sel;
   kal_uint16 meas_sel_en;
   kal_uint32 meas_sel;         
   kal_uint32 ddpc_sel;             
} MMRFC_TXK_SW_MODE_CFG_T;

typedef struct
{
   kal_int16 dc_i;
   kal_int16 dc_q;

} MMRFC_DET_DC_COMP_T;

typedef struct
{
   kal_int16 gain;
   kal_int16 phase;

} MMRFC_DET_FIIQ_COMP_T;

typedef struct
{
   kal_int16 coef[MMRFC_FILT_TAPS_NUM];
   kal_uint16 tap_sel;
   kal_uint16 fdiq_bypass;

} MMRFC_DET_FDIQ_COMP_T;

/* Please use the following bitmap definition for nco_phi_bmp */
/* MMRFC_NCO_PHI_NONE */
/* MMRFC_NCO_PHI_0    */
/* MMRFC_NCO_PHI_1    */
/* MMRFC_NCO_PHI_2    */
/* MMRFC_NCO_PHI_3    */
typedef struct
{
   kal_uint16 nco_phi_bmp;
   kal_int32 nco_phi[MMRFC_NCO_PHI_NUM];
} MMRFC_NCO_PHI_T;

/* Please use the following bitmap definition and combine them for det_comp_sel_bmp */
/* MMRFC_DET_COMP_SEL_MEAS01_SET0  0x0000 */
/* MMRFC_DET_COMP_SEL_MEAS01_SET1  0x0001 */
/* MMRFC_DET_COMP_SEL_MEAS23_SET0  0x0000 */
/* MMRFC_DET_COMP_SEL_MEAS23_SET1  0x0002 */
/* MMRFC_DET_COMP_SEL_MEAS45_SET0  0x0000 */
/* MMRFC_DET_COMP_SEL_MEAS45_SET1  0x0004 */
/* MMRFC_DET_COMP_SEL_MEAS67_SET0  0x0000 */
/* MMRFC_DET_COMP_SEL_MEAS67_SET1  0x0008 */
typedef struct
{
   MMRFC_RAT_CBW_CFG_E rat_cbw;       ///< RAT/CBW configuration
   kal_uint16 dpd_anti_en;            ///< DPD/RFK anti-droop enable   
   MMRFC_NCO_PHI_T nco_phi;           ///< DET NCO phi for TX related cal.
   kal_uint32 det_comp_sel_bmp;       ///< DET comp. set selection (2 sets with DC/FIIQ comp.)
   kal_uint16 is_det_cal;             ///< 0: TXK, 1: DETK
   kal_uint16 lpbk_path_sel;          ///< Loopback path selection for EQLPF Taps - 0: Default EQLPF Taps, 1: TXRCK/TXFDIQK, 2: Other Calibration
   
} MMRFC_DET_DFE_CFG_T;

typedef struct
{
   kal_uint32 acc_len[MMRFC_ANT_NUM][MMRFC_RXMS_IQK_MEM_NUM];

} MMRFC_RXMS_IQK_ACC_LEN_T;

typedef struct
{
   kal_uint16 sample_mask[MMRFC_ANT_NUM][MMRFC_RXMS_IQK_MEM_NUM];
   kal_uint16 tck[MMRFC_ANT_NUM][MMRFC_RXMS_IQK_MEM_NUM];
   kal_uint16 clp_len[MMRFC_ANT_NUM][MMRFC_RXMS_IQK_MEM_NUM];
   kal_uint16 rnd_len[MMRFC_ANT_NUM][MMRFC_RXMS_IQK_MEM_NUM];

} MMRFC_RXMS_IQK_RATE_CLP_RND_T;

typedef struct
{
   MMRFC_RAT_E rat;                            ///< RAT configuration, valid for WCDMA/LTE
   MMRFC_RXMS_IQK_ACC_LEN_T acc_len;           ///< accumulation length
   MMRFC_RXMS_IQK_RATE_CLP_RND_T rate_clp_rnd; ///< sample rate mask, measurement tick, clpping length, and round length
   MMRFC_RXMS_IQK_MUL_MASK_E mul_mask;         ///< multiply mask
   
} MMRFC_RXMS_IQK_CFG_T;

typedef struct
{
   kal_int32 iqk_i[MMRFC_ANT_NUM][MMRFC_RXMS_IQK_MEM_NUM]; ///< I^2/I/IQ (if MMRFC_RXMS_IQK_MUL_MASK_0 is selected) on ANT0 and ANT1
   kal_int32 iqk_q[MMRFC_ANT_NUM][MMRFC_RXMS_IQK_MEM_NUM]; ///< Q^2/Q/IQ (if MMRFC_RXMS_IQK_MUL_MASK_0 is selected) on ANT0 and ANT1

} MMRFC_RXMS_IQK_RESULT_T;

typedef struct
{
   kal_uint32 acc_len[MMRFC_ANT_NUM][MMRFC_RXMS_RXK_MEM_NUM]; ///< accumulation length (decimal value, ex. set 1024 for 2^10 samples)

} MMRFC_RXMS_RXK_ACC_LEN_T;

typedef struct
{
   kal_uint16 sample_mask[MMRFC_ANT_NUM][MMRFC_RXMS_RXK_MEM_NUM];
   kal_uint16 tck[MMRFC_ANT_NUM][MMRFC_RXMS_RXK_MEM_NUM];

} MMRFC_RXMS_RXK_RATE_T;

typedef struct
{
   MMRFC_RAT_E rat;                   ///< RAT configuration, valid for WCDMA/LTE
   MMRFC_RXMS_RXK_ACC_LEN_T acc_len;  ///< accumulation length (decimal value, ex. set 1024 for 2^10 samples)
   MMRFC_RXMS_RXK_RATE_T rate;        ///< sample rate mask and measurement tick
   
} MMRFC_RXMS_RXK_CFG_T;

typedef struct
{
   /* i_cos/i_sin/q_cos/q_sin for IIP2 cal */
   /* i_cos-q_sin(Path1)/j(i_sin+q_cos)(Path1)/i_cos-q_sin(Path2)/j(i_sin+q_cos)(Path2) for path loss cal */
   kal_int32 rxk[MMRFC_ANT_NUM][MMRFC_RXMS_RXK_MEM_NUM];

} MMRFC_RXMS_RXK_RESULT_T;

typedef struct
{
   MML1_RF_RAT_T        rat;
   kal_uint8            numOfBandSupport;
   MMRFC_XL1_BAND_NUM_E supportedBand[MMRFC_XL1_MAX_SUPPORT_BAND_NUM];
   kal_bool             is_hrm_enable;
   kal_uint8            split_subband_idx;
   kal_bool             is_pre_cap_tuning; //for IOTX off setting
}MMRFC_XL1_BAND_SUPPORT_CAPABILITY_T;


/** MMRFC RF Rx VCO-Divider set element template */
typedef struct
{
   kal_uint8 vco;          ///< VCO index: 1: VCO1; 2: VCO2; 3: VCO31 or VCO32, and NULL (0xFF)
   kal_uint8 div;          ///< Divider: 2, 4, 6, 8, 10, 3, and NULL (0xFF)
} MMRFC_RF_VCO_DIV_SEL_T;


typedef enum
{
   SLEEP_MODE       = 0x1,
   CALIBRATION_MODE = 0x2,
   WARMUP_MODE      = 0x4,
   BURST_MODE       = 0x8,	
}MML1_RF_POC_MODE_E;

typedef enum
{
  RXIF_GAIN_0dB  = 0,
  RXIF_GAIN_3dB   ,
  RXIF_GAIN_6dB   ,
  RXIF_GAIN_9dB   ,
  RXIF_GAIN_12dB  ,
  RXIF_GAIN_15dB  ,
  RXIF_GAIN_18dB  ,
  RXIF_GAIN_NUMBER,
} RXIF_GAIN_E;

typedef enum
{
  RX_TIA_GAIN_51p5dB  = 0,
  RX_TIA_GAIN_57p5dB  ,
  RX_TIA_GAIN_63p5dB  ,
  RX_TIA_GAIN_67p5dB  ,
  RX_TIA_GAIN_NUMBER  ,
} RX_TIA_GAIN_E;


typedef enum
{
  RX_LNA_GAIN_m48dB  = 0,
  RX_LNA_GAIN_m42dB  ,
  RX_LNA_GAIN_m36dB  ,
  RX_LNA_GAIN_m30dB  ,
  RX_LNA_GAIN_m24dB  ,
  RX_LNA_GAIN_m18dB  ,
  RX_LNA_GAIN_NUMBER ,
} RX_LNA_GAIN_E;


typedef struct
{
   RF_CW_T topCw1;

}MMPOC_RF_TX_STATE_CONFIG_BUFFER_T;


typedef struct
{
   RF_CW_T rxCw326_333[9];//RX+RXD_PATH1

}MMPOC_RF_RX_BW_CONFIG_BUFFER_T;


typedef struct
{
	RF_CW_T rxPwrModeCw413; //RX  Path 1 
	RF_CW_T rxPwrModeCw414; //RXD path 1 
	RF_CW_T rxPwrModeCw415; //RX  Path 2
	RF_CW_T rxPwrModeCw416; //RXD Path 2
}MML1_RX_POWER_MODE_BUFFER_T;

typedef struct
{
	RF_CW_T rxCw467_476; //trigger timer for FDD CAL mode 
	RF_CW_T rxCw468_477; //trigger timer for FDD Warmup mode/TTGBUF_TON 
	RF_CW_T rxCw469_478; //trigger timer for FDD TPD DCOC/CW469 RX1_DUTYC_TON 
}MML1_RX_FDD_MODE_TIMER_BUFFER_T;

typedef struct
{
	RF_CW_T rxCw470_479; //trigger timer for TDD CAL mode 
	RF_CW_T rxCw471_480; //trigger timer for TDD Warmup mode/TTGBUF_TON 
	RF_CW_T rxCw472_481; //trigger timer for TDD TPD DCOC 
}MML1_RX_TDD_MODE_TIMER_BUFFER_T;

typedef struct
{
	RF_CW_T rxGainCw334; //RX  path1
	RF_CW_T rxGainCw336; //RXD path1 
	RF_CW_T rxGainCw340; //RX  Path2
	RF_CW_T rxGainCw342; //RXD Path2
}MML1_RX_GAIN_CW_BUFFER_T;

typedef struct
{
   RF_CW_T rxPathCtrlCw320_327; //RX  Path 1 or 2
   RF_CW_T rxPathCtrlCw321_328; //RXD path 1 or 2
   RF_CW_T rxPathCtrlCw322_329; //RX  Path 1 or 2
   RF_CW_T rxPathCtrlCw324_331; //RXD Path 1 or 2

}MML1_RF_CAL_RF_RX_PATH_CTRL_BUFFER_T;

typedef struct
{
   RF_CW_T rxLoCw495_499; //LO1 or LO2

}MML1_RF_CAL_RF_RX_LO_CTRL_BUFFER_T;

typedef struct
{
   RF_CW_T rxSrxCw128_129; //SRX1/SRX2 Band inform
   RF_CW_T rxSrxCw130_132; //SRX1/SRX2 Channel setting 1
   RF_CW_T rxSrxCw131_133; //SRX1/SRX2 Channel setting 2
   RF_CW_T rxSrxCw179_279; //SRX1/SRX2 Run-Time RC (FDD)
   RF_CW_T rxSrxCw181_281; //SRX1/SRX2 Run-Time RC (TDD)
   RF_CW_T rxSrxCw183_283; //SRX1/SRX2 Run-Time RC (C2K)
   
}MML1_RF_CAL_RF_SRX_CONFIG_BUFFER_T;

typedef struct
{
   RF_CW_T rxCw335;//RX_PATH1
   RF_CW_T rxCw337;//RXD_PATH1
   RF_CW_T rxCw341;//RX_PATH2
   RF_CW_T rxCw343;//RXD_PATH2
}MML1_RF_RX_DCOC_COMP_CONFIG_BUFFER_T;

typedef struct
{
   RF_CW_T iip2Cw473_482; //path1 or path2
   
} MML1_RF_RX_RG_BIAS_IIP2C_CONFIG_BUFFER_T;

typedef struct
{
  RF_CW_T power_mode_cw[5]; // CW413,414(PATH1); CW415,416(PATH2)

} MML1_RX_POWER_MODE_CONFIG_BUFFER_T;

typedef struct
{
 kal_uint32 gate_bias_i;
 kal_uint32 gate_bias_q;
} MML1_RX_IIP2C_GATE_BIAS_T;


typedef struct
{
   RF_CW_T ttgCw50;
   RF_CW_T ttgCw51;

}MMPOC_RF_TX_TTG_FREQ_CONFIG_BUFFER_T;

/** buffer type for TTG  */

/** RF CW table type for the action to set TTG NMMD  */
typedef struct
{
   RF_CW_T ttgCw51;
   RF_CW_T ttgCw52;

}MMPOC_RF_RX_TTG_FREQ_CONFIG_BUFFER_T;

/** RF CW table type for the action to trigger TTG ON/OFF  */
typedef struct
{
   RF_CW_T ttgCw45; // ON/OFF

}MMPOC_RF_TTG_TRIG_CONFIG_BUFFER_T;


/** buffer type for TX  */

/** RF CW table type for the action to set TX forward gain table */
typedef struct
{
   RF_CW_T txGainCw706[MMRFC_TX_DNL_PGA_A_GAIN_STEPS+MMRFC_TX_DNL_PGA_B_GAIN_STEPS+MMRFC_TX_DNL_PGA_AUX_GAIN_STEPS+1];//+1 for G21AUX

}MMPOC_RF_TX_GAIN_TABLE_BUFFER_T;

/** RF CW table type for the action to set DET forward gain table */
typedef struct
{
   RF_CW_T detGainCw705[MMRFC_DET_GAIN_STEPS_DET_CAL];

}MMPOC_RF_DET_GAIN_TABLE_BUFFER_T;

typedef struct
{
   RF_CW_T txCw711[12];
	  
}MMPOC_RF_LPBK_CONFIG_BUFFER_T;

/** RF CW table type for the action to set LPF BW */
typedef struct
{
   RF_CW_T txCw710;//LPF_RSEL
   RF_CW_T txCw787;//LPF_CSEL
   
}EL1D_RF_TX_LPF_BW_CONFIG_BUFFER_T;

/** RF CW table type for the action to set RCF BW */
typedef struct
{
   RF_CW_T txCw793;//RCF_RSEL&RCF_CSEL
   
}EL1D_RF_TX_RCF_BW_CONFIG_BUFFER_T;

typedef struct
{
   RF_CW_T txCw821;//LPF_SLICE_EN
   RF_CW_T txCw822;//RCF_SLICE_EN   

}EL1D_RF_TX_LPF_RCF_SLICE_BUFFER_T;


/** buffer type for auto K trigger (e.g LO/CDCOC)  */

typedef struct
{
   /*CDCOC+LO   , LO_only    ,CDCOC_only  ,default     */
   RF_CW_T txCw728[4];
   RF_CW_T txCw732[4];
   RF_CW_T txCw725[4];
   RF_CW_T txCw727[4];
}MMPOC_RF_LO_CDCOC_TRIGGER_TIMER_CONFIG_BUFFER_T;

typedef struct
{
   kal_uint32 start_time;         
   kal_uint32 duration;         
   kal_uint32 delay;           
} MMRFC_FAC_K_Timing_PARAM_T;

typedef struct
{
   MMRFC_XL1_BAND_NUM_E pcc_band ;         
   MMRFC_XL1_BAND_NUM_E scc_band ;         
} MMRFC_FAC_K_Rx_Setting_T;

typedef struct
{
   kal_int16 rxm_gain;
   kal_int16 rxd_gain;
 } MMRFC_FAC_K_LNA_Gain_CFG_T;

typedef struct
{
   kal_int16 rxm[PLK_CC_NUM];
   kal_int16 rxd[PLK_CC_NUM];
} MMRFC_FAC_K_Rx_Result_T;


/** TXDFE */
typedef struct
{
   /** TTG phase*/
   kal_int32 phi;

   /** TTG gain*/
   kal_uint32 gain;

   /** TTG phase0 mode*/
   MMRFC_TXDFE_TTG_MODE_E p0_mode;

   /** TTG phase1 mode*/
   MMRFC_TXDFE_TTG_MODE_E p1_mode;

   /** 1st TTG tone DC value: i part*/
   kal_int32  dc_i;

   /** 1st TTG tone DC value: q part*/
   kal_int32  dc_q;

} MMRFC_TXDFE_TTG_CTRL_T;

typedef struct
{
   kal_uint16  rxio;
   kal_uint16  rxdio;
   kal_uint8   vco;
   kal_uint8   div;
   kal_uint8   is_intra_ncca;
   kal_uint8   dc_comp_idx;
}MMRFC_RX_CAL_CFG_T;

typedef struct
{
   MMRFC_XL1_BAND_NUM_E  band;
   kal_uint16            txio;
   kal_uint8             dco;
   kal_uint8             div;
}MMRFC_TX_CAL_CFG_T;


/*Tx DET path selection */
typedef enum
{
   DET_IO_DET1 = 0,
   DET_IO_DET2 = 1,

   DET_IO_NON_USED = 0xFFFF,
}MMRF_DET_IO_E;


/*===============================================================================*/
/*        Structures for Multi-Mode DPD and CIM3 Factory Calibration             */
/*===============================================================================*/

/* Match the definition of TXK Meas register DPD_RAMP_CON */
typedef enum
{
   MMRFC_DPD_FAC_RAMP_REP_2_POW_4  = 0,
   MMRFC_DPD_FAC_RAMP_REP_2_POW_5  = 1,
   MMRFC_DPD_FAC_RAMP_REP_2_POW_6  = 2,
   MMRFC_DPD_FAC_RAMP_REP_2_POW_7  = 3,
   MMRFC_DPD_FAC_RAMP_REP_2_POW_8  = 4,
   MMRFC_DPD_FAC_RAMP_REP_2_POW_9  = 5,
   MMRFC_DPD_FAC_RAMP_REP_2_POW_10 = 6,
   MMRFC_DPD_FAC_RAMP_REP_2_POW_11 = 7
   
} MMRFC_DPD_FAC_RAMP_REP_E;


typedef enum
{
   MMRFC_CIM3_FAC_MEAS_SAMPLE_2_POW_8  = 0,
   MMRFC_CIM3_FAC_MEAS_SAMPLE_2_POW_9  = 1,
   MMRFC_CIM3_FAC_MEAS_SAMPLE_2_POW_10 = 2,
   MMRFC_CIM3_FAC_MEAS_SAMPLE_2_POW_11 = 3,
   MMRFC_CIM3_FAC_MEAS_SAMPLE_2_POW_12 = 4,
   MMRFC_CIM3_FAC_MEAS_SAMPLE_2_POW_13 = 5,
   MMRFC_CIM3_FAC_MEAS_SAMPLE_2_POW_14 = 6,
   MMRFC_CIM3_FAC_MEAS_SAMPLE_2_POW_15 = 7
   
} MMRFC_CIM3_FAC_MEAS_SAMPLE_E;

typedef enum
{
   MMRFC_CIM3_FAC_WAIT_SAMPLE_2_POW_0 = 0,
   MMRFC_CIM3_FAC_WAIT_SAMPLE_2_POW_1 = 1,
   MMRFC_CIM3_FAC_WAIT_SAMPLE_2_POW_2 = 2,
   MMRFC_CIM3_FAC_WAIT_SAMPLE_2_POW_3 = 3,
   MMRFC_CIM3_FAC_WAIT_SAMPLE_2_POW_4 = 4,
   MMRFC_CIM3_FAC_WAIT_SAMPLE_2_POW_5 = 5,
   MMRFC_CIM3_FAC_WAIT_SAMPLE_2_POW_6 = 6,
   MMRFC_CIM3_FAC_WAIT_SAMPLE_2_POW_7 = 7,
   MMRFC_CIM3_FAC_WAIT_SAMPLE_2_POW_8 = 8
   
} MMRFC_CIM3_FAC_WAIT_SAMPLE_E;

typedef struct
{
   kal_int32 buff_i;
   kal_int32 buff_q;
   
}MMRFC_DPD_FAC_AVG_BUF_RESULT_T;

typedef struct
{
   kal_int32 i_sin;
   kal_int32 i_cos;
   kal_int32 q_sin;
   kal_int32 q_cos;   
   
}MMRFC_CIM3_FAC_AVG_BUF_RESULT_T;

typedef struct {
   kal_int32 DC;
   kal_int32 DC_inv;
}TXFIIQDC_TTG_DC_artificial;


/*===============================================================================*/
/*        Global Functions declaration (interface)                               */
/*===============================================================================*/
//MMRFC Algorithm
void MML1_RF_CAL_ALGO_Rx_Irr(const MMRFC_IQK_MEAS_T* iqk_meas, MMRFC_RAT_CBW_CFG_E rat, kal_uint16 is_freq_dep, MMRFC_RX_IRR_RESULT_T* result);
void MML1_RF_CAL_ALGO_Rx_Dc(const MMRFC_IQK_MEAS_T* iqk_meas, kal_int16 acc_len, MML1_RF_RAT_T rat, MMRFC_RX_DC_RESULT_T* rf_dc, MMRFC_RX_DC_RESULT_T* dig_dc);
void MML1_RF_CAL_ALGO_Rx_Dc_Dig_Only(const MMRFC_IQK_MEAS_T* iqk_meas, kal_int16 acc_len, MML1_RF_RAT_T rat, MMRFC_RX_DC_RESULT_T* dig_dc);
void MML1_RF_CAL_ALGO_Rx_PathLoss(const MMRFC_RXK_PL_MEAS_T* rxk_meas, kal_int16 acc_len, kal_int16* result);
void MML1_RF_CAL_ALGO_Det_IqDnl(const MMRFC_IQK_MEAS_T* iqk_meas, MMRFC_RAT_CBW_CFG_E rat, kal_uint16 is_freq_dep, MMRFC_DET_IQDNL_RESULT_T* result);
void MML1_RF_CAL_ALGO_Det_Dc(const MMRFC_IQK_MEAS_T* iqk_meas, MMRFC_RAT_CBW_CFG_E cfg, kal_uint16 is_freq_dep, MMRFC_DET_DC_RESULT_T* result);
void MML1_RF_CAL_ALGO_Rx_Iip2_NoiseMeas(const MMRFC_IQK_MEAS_T* iqk_meas, kal_uint16 acc_len, kal_uint32* result);
void MML1_RF_CAL_ALGO_Rx_Iip2_Algo1(const MMRFC_RXK_MEAS_T* rxk_meas, kal_uint16 acc_len, MMRFC_IIP2_RESULT_T* result);
void MML1_RF_CAL_ALGO_Rx_Iip2_Algo2(const MMRFC_RXK_MEAS_T* rxk_meas, kal_uint16 acc_len, MMRFC_IIP2_RESULT_T* result);
kal_uint8 MML1_RF_CAL_ALGO_Rx_Iip2_Code_Compare(const MMRFC_RXK_MEAS_T* rxk_meas, kal_uint16 acc_len, kal_uint8 compare_num);
kal_int16 MML1_RF_CAL_ALGO_Tx_Rc(const MMRFC_TXK_MEAS_T* txk_meas, MMRFC_RAT_CBW_CFG_E cfg, kal_uint16 sel_lpf_rc_cal);
void MML1_RF_CAL_ALGO_Tx_IqDc(const MMRFC_TXK_MEAS_T* txk_meas, MMRFC_RAT_CBW_CFG_E cfg, kal_uint16 is_freq_dep, kal_uint16 en_tx_dc_cal, TXFIIQDC_TTG_DC_artificial* MML1_RF_PwronK_TXFIIQDC_DC_i_cfg_p,
                              kal_uint8 pga_gain_idx,MMRFC_TX_IQDC_RESULT_T* result);
void MML1_RF_CAL_ALGO_Tx_Fd_Filt(const MMRFC_TXK_MEAS_T* txk_meas, MMRFC_RAT_CBW_CFG_E cfg, MMRFC_TX_FD_FILT_RESULT_T* result, kal_int8 algor);
void MML1_RF_CAL_ALGO_Tx_Tone_Pwr(const MMRFC_TXK_MEAS_T* txk_meas, MMRFC_RAT_CBW_CFG_E cfg, kal_int16* pwr_db);
void MML1_RF_CAL_ALGO_Tx_Ga(const MMRFC_TXK_MEAS_T* txk_meas, MMRFC_RAT_CBW_CFG_E cfg, MMRFC_TX_GA_RESULT_T* result);
void MML1_RF_CAL_ALGO_Pga_Phase_Step(const MMRFC_TXK_MEAS_T* txk_meas, kal_int32* result);
kal_int32 MML1_RF_CAL_ALGO_STX_DCC_DELTA_NC(kal_int32 delta_duty_cycle, kal_uint32 nmmd);
kal_int32 MML1_RF_CAL_ALGO_STX_Delta_Duty_Cycle(kal_uint32 tdc_ratio, kal_int32 dcc_delta_tdc_out);
void MML1_RF_CAL_ALGO_Rx_PathLoss_DBG(const MMRFC_IQK_MEAS_T* iqk_meas, kal_int16 acc_len, kal_int16* result);

kal_uint16 MML1_RF_Cal_log10_2_lin (kal_int32 in_dB10, kal_int16 in_wl, kal_int16 in_frac, kal_int16 out_wl);

kal_int16 MML1_RF_CAL_translate_rxdc_code(kal_int16 dc_decimal);

//MMRFC DFE Control
void MML1_RF_CAL_TXK_ADDA_Ctrl(MMRFC_TXK_ADDA_BITMAP_E adda_bmp);
void MML1_RF_CAL_TXK_MEAS_AFIFO_Workaround(kal_bool en);
void MML1_RF_CAL_TXK_IMM_Ctrl(const MMRFC_TXK_IMM_CFG_T* p);
void MML1_RF_CAL_TXK_W_PBC_Ctrl(const MMRFC_TXK_W_PBC_CFG_T* p, kal_uint16 glo_idx);
void MML1_RF_CAL_TXK_L_PBC_Ctrl(const MMRFC_TXK_L_PBC_CFG_T* p, kal_uint16 glo_idx);
void MML1_RF_CAL_TXK_T_PBC_Ctrl(const MMRFC_TXK_T_PBC_CFG_T* p);
void MML1_RF_CAL_TXK_SWmode_Ctrl(const MMRFC_TXK_SW_MODE_CFG_T* p);
void MML1_RF_CAL_TXK_SWmode_MeasTrigger(MMRFC_TXK_ITEM_SW_MODE_E cal_item);
kal_uint32 MML1_RF_CAL_TXK_Get_Dbg_Counter(MMRFC_RAT_E rat, kal_uint16 glo_idx);
void MML1_RF_CAL_TXK_Update_Det_Dfe_DC_Comp(MMRFC_DET_DC_COMP_T* p);
void MML1_RF_CAL_TXK_Update_Det_Dfe_Fiiq_Comp(MMRFC_DET_FIIQ_COMP_T* p);
void MML1_RF_CAL_TXK_Update_Det_Dfe_Fdiq_Comp(MMRFC_DET_FDIQ_COMP_T* p);
void MML1_RF_CAL_TXK_Det_Dfe_Ctrl(const MMRFC_DET_DFE_CFG_T* p);
kal_bool MML1_RF_CAL_TXK_Get_Status(kal_uint16 meas_sel);
void MML1_RF_CAL_TXK_Get_Det_Result(MMRFC_IQK_MEAS_T* result, kal_uint16 meas_sel);
void MML1_RF_CAL_TXK_Get_Tx_Result(MMRFC_TXK_MEAS_T* result, kal_uint16 meas_sel);
void MML1_RF_CAL_RxMeas_IQK_Ctrl(const MMRFC_RXMS_IQK_CFG_T* cfg, kal_uint16 trig_idx, MMRFC_ANT_BITMAP_E ant_bmp, kal_bool tds_normal_en);
kal_bool MML1_RF_CAL_RxMeas_IQK_Check_Rdy_Bit(kal_uint16 trig_idx, MMRFC_ANT_BITMAP_E ant_bmp);
void MML1_RF_CAL_RxMeas_IQK_Get_Result(MMRFC_RXMS_IQK_RESULT_T* result, kal_uint16 trig_idx, MMRFC_ANT_BITMAP_E ant_bmp);
void MML1_RF_CAL_RxMeas_IQK_Set_Read_Bit(kal_uint16 trig_idx, MMRFC_ANT_BITMAP_E ant_bmp, MMRFC_RAT_E rat);
void MML1_RF_CAL_RxMeas_RXK_Ctrl(const MMRFC_RXMS_RXK_CFG_T* cfg, MMRFC_ANT_BITMAP_E ant_bmp, kal_uint16 is_iip2_cal);
kal_bool MML1_RF_CAL_RxMeas_RXK_Check_Rdy_Bit(kal_uint16 trig_idx, MMRFC_ANT_BITMAP_E ant_bmp);
void MML1_RF_CAL_RxMeas_RXK_Get_Result(MMRFC_RXMS_RXK_RESULT_T* result, kal_uint16 trig_idx, MMRFC_ANT_BITMAP_E ant_bmp);
void MML1_RF_CAL_RxMeas_RXK_Set_Read_Bit(kal_uint16 trig_idx, MMRFC_ANT_BITMAP_E ant_bmp, MMRFC_RAT_E rat);
void MML1_RF_CAL_RxMeas_RXK_result_reassign(MMRFC_RXMS_RXK_RESULT_T* rxk_meas_result_ptr,const kal_uint16 result_num, MMRFC_RXK_MEAS_T* rxk_meas_ptr);
kal_bool MML1_DPD_Fac_Get_HW_AVG_BUF_Status( void );
void MML1_DPD_Fac_Get_HW_AVG_BUF_Result( MMRFC_DPD_FAC_AVG_BUF_RESULT_T *result, kal_uint8 pow_idx );
void MML1_DPD_Fac_Txk_Meas_Ramp_Con( MMRFC_DPD_FAC_RAMP_REP_E ramp_rep, kal_uint32 wait_sample );
kal_bool MML1_CIM3_Fac_Get_HW_AVG_BUF_Status( void );
void MML1_CIM3_Fac_Get_HW_AVG_BUF_Result( MMRFC_CIM3_FAC_AVG_BUF_RESULT_T *result );
void MML1_CIM3_Fac_Txk_Meas_Con0_1( kal_int32 nco_phi, MMRFC_CIM3_FAC_MEAS_SAMPLE_E meas_sample, MMRFC_CIM3_FAC_WAIT_SAMPLE_E wait_sample );

//MMRFC POC main function
void MML1_RF_MMPOCDoCal(MML1_RF_RAT_T                       rat,
                        MMRFC_XL1_BAND_SUPPORT_CAPABILITY_T band_cap,
                        kal_uint32                          cal_item_list_bitmap,
                        void*                               returnResult);

//MMRFC RF CW Control
kal_uint8 MML1_RF_BandToHLB(MMRFC_XL1_BAND_NUM_E rf_band);
kal_uint8 MML1_RF_TTG_BUF_LB_EN(MMRFC_XL1_BAND_NUM_E rf_band);

void MML1_RF_POC_SET_TX_GAIN(kal_uint8 DPD_M, kal_uint8 PGA_AB, kal_uint8 Gain_idx, kal_uint8 TX_Gain_port_sel, kal_uint8 HMLB_SELECT);
void MML1_RF_POC_SET_RF_CAPCODE(kal_uint8 PGA_AB, kal_uint8 Cap, kal_uint8 Tx_cap_port_sel );
void MML1_RF_POC_SET_DET_GAIN( kal_uint8 Gain_idx, kal_uint8 TX_DET_Gain_port_sel  );
void MML1_RF_POC_SET_LO_CDCOC_TrigTime(kal_uint8 TRIG_CFG, kal_uint8 TX_LO_DCOC_K_port );
void MML1_RF_POC_SET_TX_LBPK(kal_uint8 LBPK_idx, MMRFC_XL1_BAND_NUM_E curr_band, kal_uint8 TX_Gain_idx, kal_uint8 TX_LBPK_port, kal_bool is_PA_ON );
void MML1_RF_POC_SET_TX_LBPK_GSM(kal_uint8 LBPK_idx, MMRFC_XL1_BAND_NUM_E curr_band, kal_uint8 TX_Gain_idx, kal_uint8 TX_LBPK_port, kal_bool is_PA_ON );
void MML1_RF_POC_CDCOC_result_WB( kal_uint8 TX_WB_port, kal_uint32* det_coarse_dcoc_cw807, kal_uint32* det_coarse_dcoc_cw808 );
void MML1_RF_POC_LO_result_WB( kal_uint8 TX_WB_port, MMRFC_XL1_BAND_NUM_E curr_band, kal_uint8* lo_ind_sw, kal_uint8* capcal_peak_cap, kal_uint8* in_bias_lpm, kal_uint8* in_bias_hpm, kal_uint8 split_subband_idx);
kal_uint32 MML1_RF_POC_SET_RF_CW_TX_RCCAL1(const MMRFC_XL1_BAND_NUM_E band, kal_uint32 rccal_csel );
kal_uint32 MML1_RF_POC_SET_RF_CW_TX_RCF(const MMRFC_XL1_BAND_NUM_E band, kal_uint32 rcf_csel, kal_uint32 rcf_rsel);
kal_uint32 MML1_RF_POC_SET_RF_CW_TX_LPF(const MMRFC_XL1_BAND_NUM_E band, kal_uint32 lpf_rsel, kal_bool is_lpf_cal, kal_bool is_rcf_cal);
MMRFC_RAT_CBW_CFG_E MML1_RF_MAX_CBW_Select(MMRFC_XL1_BAND_NUM_E rf_band);
kal_uint8 MML1_RF_POC_TX_BandToHMLB(MMRFC_XL1_BAND_NUM_E rf_band);
kal_uint32 MML1_RF_SET_CW714( MMRFC_XL1_BAND_NUM_E band, kal_uint16 freq/*MHz*/, 
                        const kal_uint8 *tx_lo_ind, const kal_uint8 *tx_lo_capcal_peak_cap, const kal_uint8 *tx_lo_in_bias_hpm, const kal_uint8 *tx_lo_in_bias_lpm, kal_bool is_hrm_enable, kal_uint32 subband_idx);

//MMRFC Factory Calibration Tx Control 
void MML1_RF_CAL_TST_TX_Tone_Enable(MMRFC_FAC_K_Timing_PARAM_T* tone_param, MMRFC_XL1_BAND_NUM_E band, kal_uint8 idx);
void MML1_RF_CAL_TST_TX_TTG_CON(kal_uint16 ttg_mode, kal_uint16 adj_value /*U7.5*/, kal_int32 freq_offset/*unit:KHz*/, kal_uint8 idx);
void MML1_RF_CAL_TST_TX_IMM_Off();
void MML1_RF_CAL_TST_CONTI_TX_CON(kal_bool tone_en, kal_uint16 adj_value /*U7.5*/, kal_int32 freq_offset/*unit:KHz*/, MMRFC_XL1_BAND_NUM_E band, MMRFC_RAT_CBW_CFG_E cbw );
//void MML1_RF_CAL_TST_RX_Meas_Enable(const kal_bool is_ncca, MMRFC_FAC_K_Timing_PARAM_T* meas_param, MMRFC_XL1_BAND_NUM_E band, MMRFC_ANT_BITMAP_E ant_bmp);
//void MML1_RF_CAL_TST_RX_Meas_Get_Result(MMRFC_RAT_E rat, const kal_bool is_pcc, MMRFC_ANT_BITMAP_E ant_bmp, MMRFC_FAC_K_LNA_Gain_CFG_T* lna_gain /*dB*/, kal_int16* result);
void MML1_RF_CAL_TST_RX_Meas_Enable(kal_bool is_pcc,MMRFC_FAC_K_Timing_PARAM_T* meas_param, MMRFC_FAC_K_Rx_Setting_T* rx_setting, MMRFC_ANT_BITMAP_E ant_bmp);
void MML1_RF_CAL_TST_RX_Meas_Get_Result(kal_bool is_pcc,MMRFC_RAT_E rat,MMRFC_FAC_K_Rx_Setting_T* rx_setting, MMRFC_ANT_BITMAP_E ant_bmp, MMRFC_FAC_K_LNA_Gain_CFG_T* lna_gain /*dB*/, MMRFC_FAC_K_Rx_Result_T* result);
kal_uint32 MML1_RF_CAL_BSI_get_port_sel(kal_uint32 port_sel);

void MML1_RF_POC_SET_DET_PATH_SEL(kal_uint8 det_path_sel, kal_uint8 DET_Path_sel_port );

void MML1_RF_CAL_TST_RX_RESET_FC(const kal_bool IsFreqBand_Change);

#endif /* End of #ifndef _MML1_RF_CAL_INTERFACE_H_ */

