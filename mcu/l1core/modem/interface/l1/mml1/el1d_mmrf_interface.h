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
 *   el1d_mmrf_interface.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   EL1D interface to Multi-Mode Multi-RAT RF Central Control
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _EL1D_MMRF_INTERFACE_H_
#define  _EL1D_MMRF_INTERFACE_H_

/*===============================================================================*/

#include "kal_general_types.h"
#include "el1d_rf_public.h"
#include "mml1_rf_interface.h"
#include "mml1_rf_cal_interface.h"
#include "el1d_rf_cal_poc_data.h"
#include "mml1_rf_local.h"

/*===============================================================================*/

/**********************************************************************************
* define
**********************************************************************************/
/** TXDFE filter coefficient and compensation data dimension*/
#define TX_DC_COMP_FC_MODE_NUM            2
#define TX_DC_COMP_PGA_SLICE_SET_NUM      8
#define TX_DC_COMP_DATA_NUM               1
#define TX_DC_COMP_DATA_REG_NUM           1

#define TX_IQ_COMP_FC_MODE_NUM            2
#define TX_IQ_COMP_PGA_SLICE_SET_NUM      8
#define TX_IQ_COMP_DATA_NUM               1
#define TX_IQ_COMP_DATA_REG_NUM           1

#define FREQ_DEP_COMP_FC_MODE_NUM         2
#define FREQ_DEP_COMP_PGA_SLICE_SET_NUM   8
#define FREQ_DEP_COMP_GROUP_REG_NUM      (FREQ_DEP_COMP_FC_MODE_NUM*FREQ_DEP_COMP_PGA_SLICE_SET_NUM)
#define FREQ_DEP_COMP_COEFF_NUM           7
#define FREQ_DEP_COMP_COEFF_REG_NUM       3

#define ASYMM_COMP_FC_MODE_NUM            4
#define ASYMM_COMP_PGA_SLICE_SET_NUM      3
#define ASYMM_COMP_GROUP_REG_NUM         (ASYMM_COMP_FC_MODE_NUM*ASYMM_COMP_PGA_SLICE_SET_NUM)
#define ASYMM_COMP_COEFF_NUM              7
#define ASYMM_COMP_COEFF_REG_NUM          7

/** RF Route Table */
#define EL1D_RX_IRR_DC_ROUTE_NUM_MAX      LTE_RX_IRR_COMP_ROUTE_MAX  //Set the same maximum number for RXIRR and RXDC
#define EL1D_RX_IIP2_ROUTE_NUM_MAX        MMRFC_RX_IIP2_COMP_ROUTE_MAX

/** MIPI CW **/
#define MAX_MIPI_PAON_CW_NUMBER_PER_BAND  (48)//12*2->24*2
#define MAX_MIPI_PAOFF_CW_NUMBER_PER_BAND (8)//2*2->4*2


/************************************************************************************
* enum
************************************************************************************/
/** TXDFE */
typedef enum
{
   TAPS_3,
   TAPS_5,
   TAPS_7,
   TAPS_UNDEF,

} ETXDFE_FLT_TAP_E;

typedef enum
{
   TONE_1ST,
   TONE_2ND,
   TONE_3RD,
   TONE_4TH,
   TONE_NUM,

} ETXDFE_TTG_INDEX_E;

typedef enum
{
   COS_ONLY,
   SIN_ONLY,
   COS_N_P_SIN,
   COS_N_N_SIN,
   TTG_MODE_NUM,

} ETXDFE_TTG_MODE_E;

// Add by ChiaCheng
typedef enum
{
   DPD_MODE=0,   
   LINEAR_MODE1=2,
   LINEAR_MODE1_ET=3,
   LINEAR_MODE2=4,
   LINEAR_MODE2_ET=5,
} TXDFE_SW_MODE_E;

// Add by ChiaCheng
typedef enum
{
   PGA_SETA_SLICE1,
   PGA_SETA_SLICE2,    
   PGA_SETA_SLICE4,
   PGA_SETA_SLICE7,
   PGA_SETA_SLICE8,
   PGA_SETB_SLICE1,
   PGA_SETB_SLICE2,
   PGA_SETAUX,
} TXDFE_SW_GAIN_INFO_E;

// Add by ChiaCheng
typedef enum
{
   LTE_1P4M,
   LTE_3M,    
   LTE_5M,
   LTE_10M,
   LTE_15M,
   LTE_20M,
   LTE_PRACH_FMT0,  // 4'd6~9: LTE-PRACH FMT 0~3
   LTE_PRACH_FMT1,
   LTE_PRACH_FMT2,
   LTE_PRACH_FMT3,
   LTE_PRACH_FMT4,
   W_FDD_SC,
   W_FDD_DC,
   W_TDD,
} TXDFE_SW_RAT_E;

// Add by ChiaCheng
typedef enum
{
   TONE_1ST_P0,
   TONE_1ST_P1,    
   TONE_2ND_P0,
   TONE_2ND_P1,
   TONE_3RD_P0,
   TONE_3RD_P1,
   TONE_4TH_P0,
   TONE_4TH_P1,
   DPD_RAMP,
}TXDFE_SW_TTG_SETTING_SEL_E;

// Add by ChiaCheng
typedef enum
{
   SCALE_1_OVER_128,
   SCALE_1_OVER_64,    
   SCALE_1_OVER_32,
   SCALE_1_OVER_16,
   SCALE_1_OVER_8,
   SCALE_1_OVER_4,
   SCALE_1_OVER_2,
   FULL_SCALE,
}TXDFE_SW_SINE_AMP_E;

// Add by ChiaCheng
typedef enum
{
   CIM3_CANCEL_ON,
   CIM3_CANCEL_OFF,
}TXDFE_CIM3_CANCEL_EN_E;

// Add by ChiaCheng
typedef enum
{
   TX_ASYMM_COMP_ON,
   TX_ASYMM_COMP_OFF,
}TXDFE_ASYMM_COMP_EN_E;

// Add by ChiaCheng
typedef enum
{
   TX_FREQ_DEP_COMP_ON,
   TX_FREQ_DEP_COMP_OFF,
}TXDFE_FREQ_DEP_COMP_EN_E;

// Add by ChiaCheng
typedef enum
{
   ANTI_DROOP_ON,
   ANTI_DROOP_OFF,
}TXDFE_ANTI_DROOP_EN_E;

// Add by ChiaCheng
typedef enum
{
   NO_ADJ,        // no adjust
   THREE_DB,      // -3dB
   VALUE_ADJ,     // BB gain adjust value
}TXDFE_BB_GAIN_ADJ_MODE_E;

// Add by ChiaCheng
typedef enum
{
   DAC_104M,
   DAC_208M,
   DAC_416M,
   DAC_NUM,

} ETXDFE_DAC_RATE_E;

typedef enum
{
   BB_GAIN_ADJ_ON  = 0x1,
   BB_GAIN_ADJ_OFF = 0x0,
   
} ETXDFE_BB_GAIN_ADJ_MODE_CON_EN_E;

/************************************************************************************
* typedef
************************************************************************************/
/** Structure Prototypes can be seen by other files**/
/** TXDFE */
typedef struct
{
   /** TTG phase*/
   kal_int32 phi;

   /** TTG gain*/
   kal_uint32 gain;

   /** TTG phase0 mode*/
   ETXDFE_TTG_MODE_E p0_mode;

   /** TTG phase1 mode*/
   ETXDFE_TTG_MODE_E p1_mode;

   /** 1st TTG tone DC value: i part*/
   kal_int32  dc_i;

   /** 1st TTG tone DC value: q part*/
   kal_int32  dc_q;

} ETXDFE_TTG_CTRL_T;

// Add by ChiaCheng
typedef struct
{
   /** CON0 SW mode */
   TXDFE_SW_MODE_E mode;

   /** CON0 SW gain information */
   TXDFE_SW_GAIN_INFO_E gain;

   /** CON0 SW theta_at */
   kal_int16 theta_at;

   /** CON1 SW RAT selection*/
   TXDFE_SW_RAT_E rat_sel;

   /** CON1 FEC gain norm pout for TxDFE*/
   kal_int16 gain_pout;

   /** CON1 FEC detrough linear for ET*/
   kal_int16 dtr_lin;
   
} ETXDFE_SW_MODE_CFG_T;

typedef struct
{
   /** CON5 sine tone frequency = sampling rate / 64 * TXDFE_SW_SINE_FREQ_SEL*/ 
   kal_uint8 sine_freq_sel; 

   /** CON5 sine tone amplitude selection*/
   TXDFE_SW_SINE_AMP_E sine_amp;

   /** CON5 SW SINE GEN mode enable*/
   kal_uint8 sine_gen_en;
} ETXDFE_SW_MODE_SIN_GEN_T;

typedef struct
{
   kal_int16 i_part;
   kal_int16 q_part;

} ETXDFE_TX_DC_COMP_T;

typedef struct
{
   ETXDFE_TX_DC_COMP_T comp_tab[TX_DC_COMP_FC_MODE_NUM][TX_DC_COMP_PGA_SLICE_SET_NUM];

} ETXDFE_TX_DC_COMP_TAB_T;

// Added by ChiaCheng
typedef struct
{
   kal_uint32 comp_tab[TX_DC_COMP_FC_MODE_NUM][TX_DC_COMP_PGA_SLICE_SET_NUM];

} ETXDFE_TX_DC_COMP_TAB_IO_T;

typedef struct
{
   kal_int16 gain;
   kal_int16 phase;

} ETXDFE_TX_IQ_COMP_T;

typedef struct
{
   ETXDFE_TX_IQ_COMP_T comp_tab[TX_IQ_COMP_FC_MODE_NUM][TX_IQ_COMP_PGA_SLICE_SET_NUM];

} ETXDFE_TX_IQ_COMP_TAB_T;

// Added by ChiaCheng
typedef struct
{
   kal_uint32 comp_tab[TX_IQ_COMP_FC_MODE_NUM][TX_IQ_COMP_PGA_SLICE_SET_NUM];

} ETXDFE_TX_IQ_COMP_TAB_IO_T;

typedef struct
{
   kal_int16 cof[FREQ_DEP_COMP_COEFF_NUM+2];

} ETXDFE_FREQ_DEP_COMP_COEFF_T;

typedef struct
{
   ETXDFE_FREQ_DEP_COMP_COEFF_T coeff_tab[FREQ_DEP_COMP_FC_MODE_NUM][FREQ_DEP_COMP_PGA_SLICE_SET_NUM];

} ETXDFE_FREQ_DEP_COMP_COEFF_TAB_T;


// Add by ChiaCheng
typedef struct
{
   kal_uint32 cof[FREQ_DEP_COMP_COEFF_REG_NUM];

} ETXDFE_FREQ_DEP_COMP_COEFF_OUT_T;

// Add by ChiaCheng
typedef struct
{
   ETXDFE_FREQ_DEP_COMP_COEFF_OUT_T coeff_tab[FREQ_DEP_COMP_FC_MODE_NUM][FREQ_DEP_COMP_PGA_SLICE_SET_NUM];

} ETXDFE_FREQ_DEP_COMP_COEFF_TAB_IO_T;

typedef struct
{
   kal_int16 i_part;
   kal_int16 q_part;

} ETXDFE_ASYMM_COMP_COEFF_UNIT_T;

typedef struct
{
   ETXDFE_ASYMM_COMP_COEFF_UNIT_T cof[ASYMM_COMP_COEFF_NUM];

} ETXDFE_ASYMM_COMP_COEFF_T;

typedef struct
{
   ETXDFE_ASYMM_COMP_COEFF_T coeff_tab[ASYMM_COMP_FC_MODE_NUM][ASYMM_COMP_PGA_SLICE_SET_NUM];

} ETXDFE_ASYMM_COMP_COEFF_TAB_T;

// Add by ChiaCheng
typedef struct
{
   kal_uint32 cof[ASYMM_COMP_COEFF_REG_NUM];

} ETXDFE_ASYMM_COMP_COEFF_OUT_T;

// Add by ChiaCheng
typedef struct
{
   ETXDFE_ASYMM_COMP_COEFF_OUT_T coeff_tab[ASYMM_COMP_FC_MODE_NUM][ASYMM_COMP_PGA_SLICE_SET_NUM];

} ETXDFE_ASYMM_COMP_COEFF_TAB_IO_T;

// Add by ChiaCheng
typedef struct
{
   TXDFE_BB_GAIN_ADJ_MODE_E mode;
   kal_int16 value;
}TXDFE_BB_GAIN_ADJ_CON_T;

typedef struct TXDFE_BB_GAIN_ADJ_MODE_CON
{
   ETXDFE_BB_GAIN_ADJ_MODE_CON_EN_E is_On;
   kal_uint32 adj_value_m0; //DPD
   kal_uint32 adj_value_m1; //LinearMode1, no ET
   kal_uint32 adj_value_m2; //LM1 + ET
   kal_uint32 adj_value_m3; //LM2, no ET
   kal_uint32 adj_value_m4; //LM2 + ET

} ETXDFE_BB_GAIN_ADJ_MODE_CON_T;

/*===============================================================================*/
/*                     RF Calibration Result Structure                           */
/*     The structure is grouped from post-processing result. Some redundent      */
/*     items may need to be removed and excluded in shared memory or NVRAM.      */
/*===============================================================================*/
typedef struct
{
  MMRFC_RX_DC_RESULT_T rx_dc[MMRFC_RXDC_TIA_GAIN_STEPS][MMRFC_RXDC_PGA_GAIN_STEPS];
} MMRFC_RX_DC_HPM_RESULT_T;

typedef struct
{
   /* RX IRR */
   MMRFC_RX_IRR_RESULT_T       rx_irr_hpm[LTE_RX_IRR_COMP_ROUTE_MAX][MMRFC_LTE_RX_CBW_NUM][MMRFC_ANT_NUM]; //RX IRR for HPM
   MMRFC_RX_IRR_RESULT_T       rx_irr_lpm[LTE_RX_IRR_COMP_ROUTE_MAX][MMRFC_LTE_RX_CBW_NUM][MMRFC_ANT_NUM]; //RX IRR for LPM
   MMRFC_RX_IRR_RESULT_T       rx_irr_hpm_lif[LTE_RX_IRR_COMP_ROUTE_MAX][MMRFC_LTE_RX_CBW_NUM][MMRFC_ANT_NUM]; //RX IRR for HPM LIF , HPM max gain

   /* RX DC */
   MMRFC_RX_DC_HPM_RESULT_T    rx_dc_hpm[LTE_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM];     //RF DC for HPM
   MMRFC_RX_DC_HPM_RESULT_T    rx_dig_dc_hpm[LTE_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM]; //Digital DC for HPM
   MMRFC_RX_DC_RESULT_T        rx_dc_lpm[LTE_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM];     //RF DC for LPM
   MMRFC_RX_DC_RESULT_T        rx_dig_dc_lpm[LTE_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM]; //Digital DC for LPM

   /* RX IIP2 */
   //CW473 for path 1, CW482 for path 2
   //i_idx_opt->V_RX1_IIP2_IRESULTS[6:0], q_idx_opt->V_RX1_IIP2_QRESULTS[6:0]
   MMRFC_IIP2_RESULT_T         rx_iip2[MMRFC_RX_IIP2_COMP_ROUTE_MAX];

   /* DET */
   /* Only FDIQ is dependent with CBW, other redundent items need to be removed in NVRAM/share memory structure */
   kal_uint32                  det_coarse_dcoc_cw807; //CW807, V_TXCDCOC1[19:0]
   kal_uint32                  det_coarse_dcoc_cw808; //CW808, V_TXCDCOC2[19:0]

   /* Please refer to DET_TIA_COMP_INDEX_LUT/DET_CBW_COMP_INDEX_LUT for mapping from DET gain index/CBW to comp. structure */
   MMRFC_DET_IQDNL_RESULT_T    det_iqdnl_fwd[MMRFC_DET_FE_GAIN_STEPS][MMRFC_LTE_TX_CBW_NUM]; //1.4MHz and 3MHz share the same config -> restore result per CBW(20150206)
   MMRFC_DET_DC_RESULT_T       det_dc_fwd[MMRFC_DET_GAIN_STEPS_DET_CAL]; //17 DET gain step

   /* Please refer to DET_TIA_COMP_INDEX_LUT/DET_CBW_COMP_INDEX_LUT for mapping from DET gain index/CBW to comp. structure */
   MMRFC_DET_IQDNL_RESULT_T    det_iqdnl_rev[MMRFC_DET_FE_GAIN_STEPS][MMRFC_LTE_TX_CBW_NUM]; //1.4MHz and 3MHz share the same config -> restore result per CBW(20150206)
   MMRFC_DET_DC_RESULT_T       det_dc_rev[MMRFC_DET_GAIN_STEPS_DET_CAL]; //17 DET gain step
   

   /* TX LO Cal */
   kal_uint32                  tx_lo;                 //CW714, {2'b00,V_TXLOCAP[6:0],V_TXLOIND,V_TXLOINBIAS[4:0],V_TXLOINBIAS[4:0]}
   kal_uint8                   tx_lo_ind;             //CW714[10]
   kal_uint8                   tx_lo_capcal_peak_cap; //CW714[17:11]
   kal_uint8                   tx_lo_in_bias_hpm;     //CW714[4:0]
   kal_uint8                   tx_lo_in_bias_lpm;     //CW714[9:5]   
   kal_int32                   stx_delta_duty_cycle;  //for calculating CW568 V_DCC_DELTA_NC[10:0] with different Nmmd
   
   /* TX RC */
   kal_int16                   tx_rc_lpf[MMRFC_LTE_TX_CBW_NUM]; //CW787, V_TXLPFCSEL[7:0], only 5 CBW for LPF but it will map to 6 LTE RF CBW for easy access
   kal_int16                   tx_rc_rcf;                       //CW793, V_TXRCFCSEL[6:0]

   /* TX IQDC */
   /* TXIQ: G0, G9, G10, G12a, G14a, G12b, G14b, G22  */
   /* TXDC: G0, G9, G10, G12a, G14a, G12b, G14b, G22  */
   /* freq_dep_phase_tx is temp output for FDIQ cal   */
   /* Please refer to TX_COMP_INDEX_PGA_A_LUT/TX_COMP_INDEX_PGA_B_LUT for mapping from TX gain index to comp. structure */
   MMRFC_TX_IQDC_RESULT_T      tx_iqdc_lin[MMRFC_TX_PGA_SLICE_NUM+1];                   //+1 for PGA-AUX
   MMRFC_TX_IQDC_RESULT_T      tx_iqdc_dpd[MMRFC_TX_PGA_SLICE_NUM+1];                   //+1 for PGA-AUX
   MMRFC_TX_FD_FILT_RESULT_T   tx_fdiq[MMRFC_LTE_TX_CBW_NUM][MMRFC_TX_PGA_SLICE_NUM+1]; //+1 for PGA-AUX

   /* TX DNL */
   kal_int16                   tx_dnl_lin_pga_a[MMRFC_TX_DNL_PGA_A_SEQ_NUM]; //20 gain diff
   kal_int16                   tx_dnl_lin_pga_b[MMRFC_TX_DNL_PGA_B_SEQ_NUM]; //15 gain diff

   /* TX GA */
   MMRFC_TX_GA_RESULT_T        tx_ga_w_ET[MMRFC_TX_PGA_TYPE_NUM][MMRFC_LTE_TX_CBW_NUM];  //3 PGA type, 6CBW
   MMRFC_TX_GA_RESULT_T        tx_ga_wo_ET[MMRFC_TX_PGA_TYPE_NUM][MMRFC_LTE_TX_CBW_NUM]; //3 PGA type, 6CBW


   /* TX PGA Gain Step */
   kal_int16                   pga_gain_step[MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM][MMRFC_TX_PGA_GAIN_STEP_NUM];

   /* TX PGA Cap Tuning */
   kal_uint16                  cap_tuning_pga_a; //CW795, V_TX_BAL_CAPA_AACT[5:0]
   kal_uint16                  cap_tuning_pga_b; //CW796, V_TX_BAL_CAPB_BACT[5:0]
   

} MMRFC_LTE_RESULT_PER_BAND_T;

typedef struct
{
   MMRFC_LTE_RESULT_PER_BAND_T lte_result[MMRFC_XL1_MAX_SUPPORT_BAND_NUM];

   //TODO: May split RX/DET/TX calibration results for saving memory size
   MMRFC_LTE_RESULT_PER_BAND_T lte_result_b40[MMRFC_TX_PGA_CAP_TUNING_SUBBAND_NUM];
   MMRFC_LTE_RESULT_PER_BAND_T lte_result_b41[MMRFC_TX_PGA_CAP_TUNING_SUBBAND_NUM];
   
} MMRFC_LTE_RESULT_T;

/** RF Route Table */
typedef struct
{
   LTE_Band   band;
   kal_uint8  route_num;
   LTE_Route  route_idx[EL1D_RX_IRR_DC_ROUTE_NUM_MAX];
   kal_uint8  intra_ncca_scc_idx;
}EL1D_RX_IRR_DC_CFG_INDEX_TBL_T;

typedef struct
{
   LTE_Band   band;
   kal_uint8  route_num;
   LTE_Route  rx_route_idx[EL1D_RX_IIP2_ROUTE_NUM_MAX];
   LTE_Route  tx_route_idx[EL1D_RX_IIP2_ROUTE_NUM_MAX];
   kal_uint8  intra_ncca_scc_idx;
}EL1D_RX_IIP2_CFG_INDEX_TBL_T;

typedef struct
{
   kal_uint8          route_num;
   MMRFC_RX_CAL_CFG_T cfg[EL1D_RX_IRR_DC_ROUTE_NUM_MAX];
   
}MMRFC_RX_CAL_IRR_DC_CFG_T;

typedef struct
{
   kal_uint8          route_num;
   MMRFC_RX_CAL_CFG_T rx_cfg[EL1D_RX_IIP2_ROUTE_NUM_MAX];
   MMRFC_TX_CAL_CFG_T tx_cfg[EL1D_RX_IIP2_ROUTE_NUM_MAX];
}MMRFC_RX_CAL_IIP2_CFG_T;

/********MIPI struct***********/

typedef struct
{
   kal_uint16  mipi_data_start;
   kal_uint16  mipi_data_number; 
}EL1D_RF_CAL_MIPI_DATA_T;

/** Load MIPI Data CW&CFG from SHM for POC*/
typedef struct
{
   kal_uint32 MIPI_RX_CW_CFG_Table[LTE_MIPI_RX_DATA_NUM*2];
   kal_uint32 Data_CFG_count;

} EL1D_RF_MIPI_RX_CW_CFG_T;

/************************************************************************************
*  Global Variables extern (Interface)
************************************************************************************/
extern kal_uint32*          lrfcalPocBufferTable              [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern kal_uint32           lrfcalPocBufferSizeTable          [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern MML1_RF_BSIMM_PORT_T lrfcalPocBufferDataPortSelTable   [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern MML1_MIPI_REG_RW_T   lrfcalPocBufferDataMipiCwTypeTable[/*MMPOC_BUFFER_TYPE_NUM_OF*/];
//extern kal_uint8            LTE_MIPI_PA_ON_DATA_SIZE          [LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern EL1D_RF_CAL_MIPI_DATA_T LTE_MIPI_PA_ON_DATA            [LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern EL1D_RF_CAL_MIPI_DATA_T LTE_MIPI_PA_OFF_DATA           [LTE_TARGET_MAX_SUPPORT_BAND_NUM];
//hrm mode 
extern kal_uint32*          lrfcalPocBufferTable_hrm              [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern kal_uint32           lrfcalPocBufferSizeTable_hrm          [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern MML1_RF_BSIMM_PORT_T lrfcalPocBufferDataPortSelTable_hrm   [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern MML1_MIPI_REG_RW_T   lrfcalPocBufferDataMipiCwTypeTable_hrm[/*MMPOC_BUFFER_TYPE_NUM_OF*/];


/** RF Route Table */
extern kal_uint16 EL1D_RX_IRR_DC_CONFIG_TBL_SIZE;
extern kal_uint16 EL1D_RX_IIP2_CONFIG_TBL_SIZE;
extern EL1D_RX_IRR_DC_CFG_INDEX_TBL_T  EL1D_RX_IRR_CONFIG_TBL[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern EL1D_RX_IRR_DC_CFG_INDEX_TBL_T  EL1D_RX_DC_CONFIG_TBL[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern EL1D_RX_IIP2_CFG_INDEX_TBL_T    EL1D_RX_IIP2_CONFIG_TBL[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern kal_uint32*          lrfcalband40PocBufferTable[2];
extern kal_uint32*          lrfcalband41PocBufferTable[2];


/************************************************************************************
* Global Functions Prototype (Interface)
************************************************************************************/
/** TXDFE */
void EL1D_TXDFE_Set_Ttg_Config( ETXDFE_TTG_INDEX_E tone_idx, const ETXDFE_TTG_CTRL_T *p );
void EL1D_TXDFE_Update_Anti_Droop_Comp_Coeff( kal_uint8 gid, kal_uint32 ad_flt_bw, kal_uint16 txband , kal_bool is_hrm);
void EL1D_TXDFE_Update_Freq_Dep_Coeff( ETXDFE_FLT_TAP_E freq_dep_tap, ETXDFE_FREQ_DEP_COMP_COEFF_TAB_IO_T *p_freq_dep );
void EL1D_TXDFE_Update_Asymm_Comp_Coeff( ETXDFE_FLT_TAP_E asymm_comp_tap, ETXDFE_ASYMM_COMP_COEFF_TAB_IO_T *p_asymm_comp );
void EL1D_TXDFE_Update_Tx_Dc_Comp( ETXDFE_TX_DC_COMP_TAB_IO_T *p_dc );
void EL1D_TXDFE_Update_Tx_Iq_Comp( ETXDFE_TX_IQ_COMP_TAB_IO_T *p_iq );

ETXDFE_TX_IQ_COMP_TAB_T* EL1D_RF_Cal_Get_Tx_IQ_Table_Addr(MMRFC_XL1_BAND_NUM_E band, kal_bool is_hrm);
ETXDFE_TX_DC_COMP_TAB_T* EL1D_RF_Cal_Get_Tx_DC_Table_Addr(MMRFC_XL1_BAND_NUM_E band, kal_bool is_hrm);
ETXDFE_FREQ_DEP_COMP_COEFF_TAB_T* EL1D_RF_Cal_Get_Tx_FREQ_DEP_Table_Addr(MMRFC_XL1_BAND_NUM_E band, TXDFE_SW_RAT_E cbw, kal_bool is_hrm);
ETXDFE_ASYMM_COMP_COEFF_TAB_T* EL1D_RF_Cal_Get_Tx_ASYM_Table_Addr(MMRFC_XL1_BAND_NUM_E band, TXDFE_SW_RAT_E cbw, kal_bool is_hrm, kal_uint16 creq);

LTE_RF_POC_DET_IQ_COMP_T* EL1D_RF_Cal_Get_Det_IQ_Fwd_Table_Addr(MMRFC_XL1_BAND_NUM_E band, kal_bool is_hrm_enable);
LTE_RF_POC_DET_IQ_COMP_T* EL1D_RF_Cal_Get_Det_IQ_Rev_Table_Addr(MMRFC_XL1_BAND_NUM_E band, kal_bool is_hrm_enable);
LTE_RF_POC_DET_DC_COMP_T* EL1D_RF_Cal_Get_Det_DC_Fwd_Table_Addr(MMRFC_XL1_BAND_NUM_E band, kal_bool is_hrm_enable);
LTE_RF_POC_DET_DC_COMP_T* EL1D_RF_Cal_Get_Det_DC_Rev_Table_Addr(MMRFC_XL1_BAND_NUM_E band, kal_bool is_hrm_enable);
kal_int16* EL1D_RF_Cal_Get_Det_DNL_Fwd_Table_Addr(MMRFC_XL1_BAND_NUM_E band, kal_bool is_hrm_enable);
kal_int16* EL1D_RF_Cal_Get_Det_DNL_Rev_Table_Addr(MMRFC_XL1_BAND_NUM_E band, kal_bool is_hrm_enable);

void EL1D_TXDFE_Change_Tx_Iq_Comp_Format( ETXDFE_TX_IQ_COMP_TAB_T *p_in, ETXDFE_TX_IQ_COMP_TAB_IO_T *p_out );
void EL1D_TXDFE_Change_Tx_Dc_Comp_Format( ETXDFE_TX_DC_COMP_TAB_T *p_in, ETXDFE_TX_DC_COMP_TAB_IO_T *p_out );
void EL1D_TXDFE_Change_Asymm_Comp_Format( ETXDFE_ASYMM_COMP_COEFF_TAB_T *p_in, ETXDFE_ASYMM_COMP_COEFF_TAB_IO_T *p_out );
void EL1D_TXDFE_Change_Freq_Dep_Format( ETXDFE_FREQ_DEP_COMP_COEFF_TAB_T *p_in, ETXDFE_FREQ_DEP_COMP_COEFF_TAB_IO_T *p_out );
void EL1D_TXDFE_Sw_Mode_Win_On( TXDFE_SW_TTG_SETTING_SEL_E ttg_setting_sel );
void EL1D_TXDFE_Sw_Mode_Win_Off( void );
void EL1D_TXDFE_Sw_Mode_Config_On( ETXDFE_SW_MODE_CFG_T *p_sw_mode );
void EL1D_TXDFE_Sw_Mode_Config_Off( void );
void EL1D_TXDFE_Sw_Txdfe_Win_On_Off( kal_uint8 sw_txdfe_win );
void EL1D_TXDFE_Sw_Txdac_Win_On_Off( kal_uint8 sw_txdac_win );
void EL1D_TXDFE_Set_BB_Gain_Adj( TXDFE_BB_GAIN_ADJ_CON_T *p_bb_gain);
void EL1D_TXDFE_CIM3_Cancel_On_Off( TXDFE_CIM3_CANCEL_EN_E en);
void EL1D_TXDFE_Freq_Dep_Comp_On_Off( TXDFE_FREQ_DEP_COMP_EN_E en);
void EL1D_TXDFE_Asymm_Comp_On_Off( TXDFE_ASYMM_COMP_EN_E en);
void EL1D_TXDFE_Anti_Droop_Comp_On_Off( TXDFE_ANTI_DROOP_EN_E en);
void EL1D_TXDFE_Set_DAC_Rate( ETXDFE_DAC_RATE_E rate);
void EL1D_TXDFE_Clear_Ready_Bit_Meta_Single_Tone( void );
void EL1D_TXDFE_Set_Ready_Bit_Meta_Single_Tone( void );

void EL1D_TXDFE_Set_BB_Gain_Adj_Mode_Con( ETXDFE_BB_GAIN_ADJ_MODE_CON_T *p );
void EL1D_TXDFE_Sw_FEC_Trigger();

void EL1D_TXDFE_Set_Txdfe_Delay(kal_uint16 LM1_value, kal_uint16 LM2_value);

/** EL1D RF database update @ lrfdatabase.c */
void EL1D_MMRF_L1CoreSHMDataInit(void);
void EL1D_MMRF_L1coreSHMUpdate2Local(void);
void EL1D_MIPI_Init(void);

/** EL1D RF Calibration @ lrfcal.c */
void EL1D_MMRF_PowerOnCalibration(void);         //Triggered only by META
void EL1D_MMRF_Power_On_Init_Calibration(void);  //Triggered every time during EL1D_Main_Init
kal_uint16 EL1D_RF_Cal_Poc_NVRAM_Lid_Total_Num_InUse(void );
kal_uint16 EL1D_RF_Get_Rf_Self_Cal_Result_Size(kal_uint16 lid_index);
kal_uint16 EL1D_RF_Get_Rf_Self_Cal_Result(kal_uint16 lid_index, kal_uint16 lid_size, kal_uint8 *dst);
kal_uint16 EL1D_RF_Set_Rf_Self_Cal_Result(kal_uint16 lid_index, kal_uint16 lid_size, kal_uint8 *src);
kal_uint16 EL1D_RF_Get_Rf_Self_Cal_String( kal_uint16 lid_index, kal_char *string_dst );

/** MMRF */
void EL1D_MMRF_RXDFE_Win_Ctrl_Main(MMRFC_RX_CAL_TYPE_E rx_cal_type, MMRFC_PATH_BITMAP_E path_sel, kal_uint8 strobe_setting_only, kal_uint32 fc_set_bmp);
void EL1D_MMRF_RXDFE_Win_Ctrl_Main_Normal(MMRFC_RX_CAL_TYPE_E rx_cal_type, MMRFC_PATH_BITMAP_E path_sel, kal_uint8 trig_idx, kal_uint8 strobe_setting_only , kal_uint32 fc_set_bmp, kal_int32 on_time, kal_int32 off_time);
void EL1D_MMRF_RXDFE_Fc_Ctrl_Main(MMRFC_RX_CAL_TYPE_E rx_cal_type, MMRFC_PATH_BITMAP_E path_sel, MMRFC_XL1_BAND_NUM_E poc_band, kal_uint16 agg_bw, kal_uint32 fc_set_bmp, MMRFC_ANT_BITMAP_E ant_bmp);
void EL1D_MMRF_RXDFE_Win_Off(MMRFC_RX_CAL_TYPE_E rx_cal_type, MMRFC_PATH_BITMAP_E path_sel, kal_uint8 is_adc_off, kal_uint32 fc_set_bmp);
kal_uint32 EL1D_MMRF_RXDFE_Imm_Mode_Fc_Set_Bmp_Get(void);
kal_uint32 EL1D_MMRF_RXDFE_Sch_Mode_Fc_Set_Bmp_Get(void);
kal_uint32 EL1D_MMRF_UpdateRuntimeHandler( kal_uint32 nvram_lid, kal_uint8 *data, kal_uint16 nvram_size );
kal_uint32 EL1D_MMRF_Tx_HRM_BandInd_By_Band_Query(LTE_Band band);

/** RF Route Table */
void EL1D_RF_ConstructRxIrrConfigTable(void);
void EL1D_RF_ConstructRxDcConfigTable(void);
void EL1D_RF_ConstructRxIip2ConfigTable(void);
void EL1D_RF_GetRxIrrDcConfigTable(LTE_Band band, MMRFC_RX_CAL_IRR_DC_CFG_T* irr_dc_cfg, kal_uint8 is_irr_cal);
void EL1D_RF_GetRxIip2ConfigTable(LTE_Band band, MMRFC_RX_CAL_IIP2_CFG_T* iip2_cfg);

/** API for updating POC results to share memory*/
void EL1D_RF_UpdateRxResultToSHM(kal_uint8 band_idx, kal_uint32 cal_item_list_bitmap, MMRFC_LTE_RESULT_PER_BAND_T* cal_result);
void EL1D_RF_UpdateDetResultToSHM(kal_uint8 band_idx, kal_uint32 cal_item_list_bitmap, kal_bool is_hrm_enable, MMRFC_LTE_RESULT_PER_BAND_T* cal_result);
void EL1D_RF_UpdateTxResultToSHM(MMRFC_XL1_BAND_NUM_E band, kal_uint8 band_idx, kal_uint8 subband_idx, kal_uint32 cal_item_list_bitmap, kal_bool is_hrm_enable, MMRFC_LTE_RESULT_PER_BAND_T* cal_result);
void EL1D_RF_UpdatePocResultToSHM(MMRFC_XL1_BAND_NUM_E band, kal_uint8 band_idx, kal_uint8 subband_idx, kal_uint8 cal_type, kal_uint32 cal_item_list_bitmap, kal_bool is_hrm_enable, MMRFC_LTE_RESULT_PER_BAND_T* cal_result);

/** API for getting POC results for POC*/
void EL1D_RF_GetRxDcResult(kal_uint8 band_idx, kal_uint8 dc_comp_idx, kal_uint8 tia_gain_idx, kal_uint8 if_gain_idx, MMRFC_POWER_MODE_E power_mode, MMRFC_RX_DC_RESULT_T* cal_result);
void EL1D_RF_GetTxDcResult(MMRFC_XL1_BAND_NUM_E band, kal_uint8 band_idx, ETXDFE_TX_DC_COMP_TAB_T* cal_result);
void EL1D_RF_GetTxFiiqResult(MMRFC_XL1_BAND_NUM_E band, kal_uint8 band_idx, ETXDFE_TX_IQ_COMP_TAB_T* cal_result);
void EL1D_RF_GetTxFdiqResult(MMRFC_XL1_BAND_NUM_E band, kal_uint8 band_idx, kal_uint8 cbw_idx, ETXDFE_FREQ_DEP_COMP_COEFF_TAB_T* cal_result);
void EL1D_RF_GetTxGaResult(MMRFC_XL1_BAND_NUM_E band, kal_uint8 band_idx, kal_uint8 subband_idx, kal_uint8 pga_type, kal_uint8 cbw_idx, ETXDFE_ASYMM_COMP_COEFF_TAB_T* cal_result);
void EL1D_RF_GetTxLoResult(MMRFC_XL1_BAND_NUM_E band, kal_uint8 band_idx, kal_uint8 *tx_lo_ind, kal_uint8 *tx_lo_capcal_peak_cap, kal_uint8 *tx_lo_in_bias_hpm, kal_uint8 *tx_lo_in_bias_lpm);

/** API for configuring STX DCC Cal CW */
void EL1D_MMRF_RFCAL_STX_DCC_DELTA_NC_CONFIG(kal_int32 dcc_delta_nc, kal_uint8 dcc_est_en, kal_uint32* bsiData);
void EL1D_MMRF_RFCAL_STX_DCC_CONFIG(kal_uint8 curr_band_idx, MMRFC_XL1_BAND_SUPPORT_CAPABILITY_T band_cap, kal_int32 dcc_delta_nc, kal_uint8 dcc_est_en, kal_uint32* nmmd, kal_uint32* bsiData);
void EL1D_MMRF_RFCAL_GET_TDC_RATIO(kal_uint32 bsiDataRD, kal_uint32* tdc_ratio);
void EL1D_MMRF_RFCAL_GET_DCC_DELTA_TDC_OUT(kal_uint32 bsiDataRD, kal_int32* dcc_delta_tdc_out);

/** API for Rx path from RFD*/
void EL1D_MMRF_Rx_Path_Setting_Query(MMRFC_XL1_BAND_NUM_E pccBand, MMRFC_XL1_BAND_NUM_E sccBand, MMRFC_PATH_BITMAP_E* pcc_path, MMRFC_PATH_BITMAP_E* scc_path);

/** API to set TX CWs from SLEEP to BURST MODE for RX IIP2 CAL*/
void EL1D_RF_CAL_Set_TX_CW_Rx_IIP2_CAL(MMRFC_TX_CAL_CFG_T *tx_cfg);

/** API to get TX DET ANT*/
void EL1D_RF_GET_TX_DET_ANT(MMRFC_XL1_BAND_NUM_E band, kal_bool is_fwd_path);
kal_bool EL1D_RF_DET_Path_Query(MMRFC_XL1_BAND_NUM_E band, MMRF_DET_IO_E tx_det_io);

/** API for BSI CW repeated check @lrfgeneral.c */
void EL1D_MMRF_BSICW_Repeat(const kal_uint32 cw);

/** API for MIPI CW abnormal check @lrfgeneral.c */
void EL1D_MMRF_MIPICW_Abnormal(void);

/** API for BSI init @lrfgeneral.c */
void EL1D_RF_BSI_STOP_ASSERTDUMP_Init(void);

/* API for DAT feature @lrfgeneral.c*/
#if __IS_LTE_RF_DAT_SUPPORT__
kal_bool EL1D_RF_AP_Sensor_Relative_Feature_IS_Need_L1C_GAP(MMRF_AP_SENSOR_RELATIVE_OP_CODE_E OP_code, kal_int16 scenario);
#endif
/** API for CDDC*/
void EL1D_4G_Calibration_Data_File_Check_Valid(kal_uint16 *tablePtr);

/** API for META*/
void EL1D_RF_CAL_TST_TX_Tone_Enable(MMRFC_FAC_K_Timing_PARAM_T* tone_param, MMRFC_XL1_BAND_NUM_E band, kal_uint8 idx);
void EL1D_RF_CAL_TST_TX_TTG_CON(kal_uint16 ttg_mode, kal_uint16 adj_value /*U0.11*/, kal_int32 freq_offset/*unit:KHz*/, kal_uint8 idx);
void EL1D_RF_CAL_TST_TX_IMM_Off();
void EL1D_RF_CAL_TST_CONTI_TX_CON(kal_bool tone_en, kal_uint16 adj_value /*U7.5*/, kal_int32 freq_offset/*unit:KHz*/, MMRFC_XL1_BAND_NUM_E band, TXDFE_SW_RAT_E cbw );
/** API for TAS*/
kal_bool EL1D_RF_TAS_Support(void);
kal_bool EL1D_RF_ET_Get_ET_Feature_Enable_Flag( void );
void EL1C_RF_Force_TAS(kal_bool force_tas_enable, kal_uint8 tas_idx);

/** API for MIPI CW and CFG*/
void EL1D_MMRF_DB_RX_OFF_MIPI_CW_FROM_SHM(kal_uint8 Band_idx, EL1D_RF_MIPI_RX_CW_CFG_T *MIPI_RX_CW_CFG_Count);

#if IS_4G_BAND_EXTENSION_SUPPORT
/** API for TDD/FDD band distiguishing @ lrfcal.c*/
kal_bool EL1D_MMRF_IS_TDD_BAND(MMRFC_XL1_BAND_NUM_E band);
#endif

#endif /* End of #ifndef _EL1D_MMRF_INTERFACE_H_ */
