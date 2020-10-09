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
 *   ul1d_mmrf_interface.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   UL1D interface to Multi-Mode Multi-RAT RF Central Control
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
 *
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _UL1D_MMRF_INTERFACE_H_
#define  _UL1D_MMRF_INTERFACE_H_

/*===============================================================================*/

#include "kal_general_types.h"
#include "mml1_rf_cal_def.h"
#include "ul1d_rf_public.h"
#include "mml1_rf_cal_interface.h"
#include "mml1_rf_interface.h"
//#include "ul1d_rf_internal.h"
#include "el1d_mmrf_interface.h"

/**********************************************************************************
* define
**********************************************************************************/
/* TX MIPI PA */
#define UMTS_MAX_MIPI_PAON_CW_NUMBER_PER_BAND (48) //amount of 14 is used for ASM(2)/TPC(4+1) as default
#define UMTS_MAX_MIPI_PAOFF_CW_NUMBER_PER_BAND (20) // amount of 8 is used for TPC(4) as default

/* RXPOC */
#define UL1D_RX_IRR_DC_ROUTE_NUM_MAX      4
#define UL1D_RX_IIP2_ROUTE_NUM_MAX        10

/************************************************************************************
* enum
************************************************************************************/

typedef enum
{
   BB_NO_ADJ,
   BB_NEG_3,
   BB_ADJ_VALUE,
}  TX_BB_GAIN_ADJ_TYPE_T;

typedef enum
{
   FREQ_DEP_3TAPS,
   FREQ_DEP_5TAPS,
   FREQ_DEP_7TAPS,
   FREQ_DEP_NA,
}  TX_FREQ_DEP_TAPS_T;

typedef enum
{
   ASYMM_3TAPS,
   ASYMM_5TAPS,
   ASYMM_7TAPS,
   ASYMM_NA,
}  TX_ASYMM_TAPS_T;

typedef enum
{
   DAC_RAT_104M,
   DAC_RAT_208M,
   DAC_RAT_416M,
}  TX_DAC_RATE_T;

typedef enum
{
   COS,
   JSIN,
   COS_PLUS_JSIN,
   COS_MINUS_JSIN,
}  TX_TTG_TONE_PHASE_T;

typedef enum
{
   PATH0,
   PATH1,
}  RX_PATH_T;

typedef enum
{
   FEC,
   CR4,
}  RX_SRC_SEL_T;

typedef enum
{
   ANT0,
   ANT1,
}  RX_ANT_T;

typedef enum
{
   FREQ_COMPLEX_BYPASS,
   RFEQ_COMPLEX_3TAPS,
   RFEQ_COMPLEX_5TAPS,
   RFEQ_COMPLEX_8TAPS,
}  RX_RFEQ_COMPLEX_TAPS_T;

typedef enum
{
   FDPM_0TAPS,
   FDPM_2TAPS,
   FDPM_3TAPS,
   FDPM_4TAPS,
   FDPM_5TAPS,
   FDPM_6TAPS,
   FDPM_7TAPS,
   FDPM_8TAPS,
   FDPM_DELAY_1TAPS,
   FDPM_DELAY_2TAPS,
   FDPM_DELAY_3TAPS,
}  RX_FDPM_TAPS_T;

typedef enum
{
   RX_PATH_NONE,
   RX_PATH_MAIN,
   RX_PATH_DIVERSITY,
   RX_PATH_BOTH,
} RF_RX_PATH_T;

typedef enum
{
   C0,
   C1,
   C2,
}  RX_CARRIER_T;

typedef enum
{
   DCK,
   IQK,
   IIP2K,
   IIP2K_NM,
}  RX_CAL_MODE_T;

typedef enum
{
   BWT_SC,
   BWT_DC,
   BWT_3C,
}  RX_PATH_BANDWIDTH_T;

typedef struct
{
   kal_uint16 mipi_data_start;
   kal_uint16 mipi_data_number;
}UL1D_RF_CAL_MIPI_DATA_T;
/*===============================================================================*/
/*===============================================================================*/
/*                     RF Calibration Result Structure                           */
/*     The structure is grouped from post-processing result. Some redundent      */
/*     items may need to be removed and excluded in shared memory or NVRAM.      */
/*===============================================================================*/
typedef struct
{
  MMRFC_RX_DC_RESULT_T rx_dc[MMRFC_RXDC_TIA_GAIN_STEPS][MMRFC_RXDC_PGA_GAIN_WCDMA_STEPS];
} UMTS_RX_DC_HPM_RESULT_T;

typedef struct
{
   /* RX IRR */
   MMRFC_RX_IRR_RESULT_T       rx_irr_hpm[MMRFC_RX_IRR_COMP_ROUTE_MAX][MMRFC_UMTS_RX_CBW_NUM][MMRFC_ANT_NUM]; //4 route, 9CBW, 2ANT
   MMRFC_RX_IRR_RESULT_T       rx_irr_lpm[MMRFC_RX_IRR_COMP_ROUTE_MAX][MMRFC_UMTS_RX_CBW_NUM][MMRFC_ANT_NUM]; //4 route, 9CBW, 2ANT

   /* RX DC */
   UMTS_RX_DC_HPM_RESULT_T     rx_dc_hpm[MMRFC_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM]; //4 route, 2ANT
   UMTS_RX_DC_HPM_RESULT_T     rx_dig_dc_hpm[MMRFC_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM]; //4 route, 2ANT   Digital DC
   MMRFC_RX_DC_RESULT_T        rx_dc_lpm[MMRFC_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM]; //4 route, 2ANT
   MMRFC_RX_DC_RESULT_T        rx_dig_dc_lpm[MMRFC_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM]; //4 route, 2ANT   Digital DC

   /* RX IIP2 */
   MMRFC_IIP2_RESULT_T         rx_iip2[MMRFC_RX_IIP2_COMP_ROUTE_MAX]; //TODO: Need to check inter-band CA case

   /* DET */
   /* Only FDIQ is dependent with sample rates, other redundent items need to be removed in NVRAM/share memory structure */
   kal_uint32                  det_coarse_dcoc_cw807; //CW807, V_TXCDCOC1[19:0]
   kal_uint32                  det_coarse_dcoc_cw808; //CW808, V_TXCDCOC2[19:0]
   MMRFC_DET_IQDNL_RESULT_T    det_iqdnl_fwd[MMRFC_DET_FE_GAIN_STEPS][MMRFC_UMTS_TX_CBW_NUM];
   MMRFC_DET_DC_RESULT_T       det_dc_fwd[MMRFC_DET_GAIN_STEPS_DET_CAL]; //17 DET gain step

   MMRFC_DET_IQDNL_RESULT_T    det_iqdnl_rev[MMRFC_DET_FE_GAIN_STEPS][MMRFC_UMTS_TX_CBW_NUM];
   MMRFC_DET_DC_RESULT_T       det_dc_rev[MMRFC_DET_GAIN_STEPS_DET_CAL]; //17 DET gain step

   /* TX LO Cal */
   kal_uint32                  tx_lo;            //CW714, {2'b00,V_TXLOCAP[6:0],V_TXLOIND,V_TXLOINBIAS[4:0],V_TXLOINBIAS[4:0]}
   kal_uint8                   tx_lo_ind;
   kal_uint8                   tx_lo_capcal_peak_cap; //CW714
   kal_uint8                   tx_lo_in_bias_hpm;     //CW714
   kal_uint8                   tx_lo_in_bias_lpm;     //CW714   
   kal_uint32                  stx_dcc_delta_nc; //CW568, V_DCC_DELTA_NC[10:0]

   /* TX RC */
   kal_int16                   tx_rc_lpf[MMRFC_UMTS_TX_CBW_NUM];
   kal_int16                   tx_rc_rcf;

   /* TX IQDC */
   /* TXIQ: G0, G9, G10, G12a, G14a, G12b, G14b, G21  */
   /* TXDC: G0, G9, G10, G12a, G14a, G12b, G14b, G21  */
   /* freq_dep_phase_tx is temp output for FDIQ cal   */
   MMRFC_TX_IQDC_RESULT_T      tx_iqdc_lin[MMRFC_TX_PGA_SLICE_NUM+1];
   MMRFC_TX_IQDC_RESULT_T      tx_iqdc_dpd[MMRFC_TX_PGA_SLICE_NUM+1];
   MMRFC_TX_FD_FILT_RESULT_T   tx_fdiq[MMRFC_UMTS_TX_CBW_NUM][MMRFC_TX_PGA_SLICE_NUM+1];

   /* TX DNL */
   kal_int16                   tx_dnl_lin_pga_a[MMRFC_TX_DNL_PGA_A_SEQ_NUM]; //20 gain diff
   kal_int16                   tx_dnl_lin_pga_b[MMRFC_TX_DNL_PGA_B_SEQ_NUM]; //15 gain diff
   kal_int16                   tx_dnl_dpd_pga_a[MMRFC_TX_DNL_PGA_A_SEQ_NUM]; //20 gain diff
   kal_int16                   tx_dnl_dpd_pga_b[MMRFC_TX_DNL_PGA_B_SEQ_NUM]; //15 gain diff

   /* TX GA */
   MMRFC_TX_GA_RESULT_T        tx_ga_w_ET[MMRFC_TX_PGA_TYPE_NUM][MMRFC_UMTS_TX_CBW_NUM];  //3 PGA type, 6CBW
   MMRFC_TX_GA_RESULT_T        tx_ga_wo_ET[MMRFC_TX_PGA_TYPE_NUM][MMRFC_UMTS_TX_CBW_NUM]; //3 PGA type, 6CBW

   /* TX PGA Phase Step */
   kal_int16                   pga_phase_step;

   /* TX PGA Gain Step */
   kal_int16                   pga_gain_step[MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM][MMRFC_TX_PGA_GAIN_STEP_NUM];

   /* TX PGA Cap Tuning */
   kal_int16                   cap_tuning_pga_a;
   kal_int16                   cap_tuning_pga_b;
   

} MMRFC_UMTS_RESULT_PER_BAND_T;

typedef struct
{
   MMRFC_UMTS_RESULT_PER_BAND_T umts_result[MAX_SUPPORTED_BAND_INDEX];
} MMRFC_UMTS_RESULT_T;


/* RX POC index and CFG table */
typedef struct
{
   UMTSBand   band;
   kal_uint8  route_num;
   UMTS_Route route_idx[UL1D_RX_IRR_DC_ROUTE_NUM_MAX];
}UL1D_RX_IRR_DC_CFG_INDEX_TBL_T;

typedef struct
{
   UMTSBand   band;
   kal_uint8  route_num;
   UMTS_Route rx_route_idx[UL1D_RX_IIP2_ROUTE_NUM_MAX];
   UMTS_Route tx_route_idx[UL1D_RX_IIP2_ROUTE_NUM_MAX];
}UL1D_RX_IIP2_CFG_INDEX_TBL_T;

void UL1D_MMRF_PowerOnCalibration(void);
void UL1D_MMRF_L1CoreSHMDataInit(void);
void UL1D_MMRF_L1coreSHMUpdate2Local(void);
void UL1D_MMRF_PCoreSHMDataCacheFlush(void);
void UL1D_RF_UpdateRxResultToSHM(kal_uint8 band_idx, kal_uint32 cal_item_list_bitmap, MMRFC_UMTS_RESULT_PER_BAND_T* cal_result);
void UL1D_RF_UpdatePocResultToSHM(MMRFC_XL1_BAND_NUM_E band, kal_uint8  band_idx, kal_uint8  subband_idx, kal_uint8  cal_type, kal_uint32 cal_item_list_bitmap, MMRFC_UMTS_RESULT_PER_BAND_T* cal_result);

/** Update Run-Time APIs */
kal_uint32 UL1D_MMRF_UpdateRuntimeHandler( kal_uint32 nvram_lid, kal_uint8 *data, kal_uint16 nvram_size );

kal_uint16 UL1D_RF_Cal_Poc_NVRAM_Lid_Total_Num_InUse(void );
kal_uint16 UL1D_RF_Get_Rf_Self_Cal_Result_Size(kal_uint16 lid_index);
kal_uint16 UL1D_RF_Get_Rf_Self_Cal_Result(kal_uint16 lid_index, kal_uint16 lid_size, kal_uint8 *dst);
kal_uint16 UL1D_RF_Set_Rf_Self_Cal_Result(kal_uint16 lid_index, kal_uint16 lid_size, kal_uint8 *src);
kal_uint16 UL1D_RF_Get_Rf_Self_Cal_String( kal_uint16 lid_index, kal_char *string_dst );


//For POC TX API
//xxx_en_bit :: bit0:DPD, bit1:line mode1 without ET, bit2:line mode1 with ET,bit3:line mode2 without ET, bit4:line mode2 with ET
void UL1D_TXDFE_FIXED_COEF_CON(kal_uint8 sc_dc,UMTSBand band);//for setting ANTI DROOP
void UL1D_TXDFE_CIM3_CANCEL_PARAM_BASIC_CON(kal_int16 a1, kal_int16 a2, kal_int8 gain_dim, kal_uint8 set_bitmask);
void UL1D_TXDFE_DPD_AM_LUT_BASIC_CON(kal_uint16 entry_value, kal_uint8 entry, kal_uint8 gain_dim);
void UL1D_TXDFE_DPD_PM_LUT_BASIC(kal_int16 entry_value, kal_uint8 entry, kal_uint8 gain_dim);
void UL1D_TXDFE_ET_PM_LUT_BASIC_CON(kal_int16 entry_value, kal_uint8 entry);
void UL1D_TXDFE_DC_COMP_CON(kal_int16 dc_i, kal_int16 dc_q, kal_uint8 mode, kal_uint8 gain_dim);
void UL1D_TXDFE_IQ_COMP_CON(kal_int16 gain, kal_int16 phase, kal_uint8 mode, kal_uint8 gain_dim);
void UL1D_TXDFE_BB_GAIN_ADJ_CON_SP(kal_uint8 enable);
void UL1D_TXDFE_DPD_CON(kal_uint8 pm_en_bit, kal_uint8 am_en_bit);
void UL1D_TXDFE_CIM3_CANCEL_CON(kal_uint8 cim3_en_bit);
void UL1D_TXDFE_FREQ_DEP_COMP_CON(kal_uint8 freq_dep_en_bit, TX_FREQ_DEP_TAPS_T m0_taps,TX_FREQ_DEP_TAPS_T m1_taps);
void UL1D_TXDFE_ASYMM_COMP_CON(kal_uint8 asymm_en_bit, TX_ASYMM_TAPS_T m0_taps,TX_ASYMM_TAPS_T m1_taps, TX_ASYMM_TAPS_T m2_taps,TX_ASYMM_TAPS_T m3_taps);
void UL1D_TXDFE_ANTI_DROOP_CON_SP(kal_uint8 anti_droop_en_bit);
void UL1D_TXDFE_DAC_CON(TX_DAC_RATE_T dac_rate);
void UL1D_TXDFE_TTG_1ST_CON(kal_int32 phi, kal_uint8 gain, TX_TTG_TONE_PHASE_T p0, TX_TTG_TONE_PHASE_T p1);
void UL1D_TXDFE_TTG_1ST_DC_CON(kal_int16 dc_i, kal_int16 dc_q);
void UL1D_TXDFE_TTG_2ND_CON(kal_int32 phi, kal_uint8 gain, TX_TTG_TONE_PHASE_T p0, TX_TTG_TONE_PHASE_T p1);
void UL1D_TXDFE_TTG_3RD_CON(kal_int32 phi, kal_uint8 gain, TX_TTG_TONE_PHASE_T p0, TX_TTG_TONE_PHASE_T p1);
void UL1D_TXDFE_TTG_4TH_CON(kal_int32 phi, kal_uint8 gain, TX_TTG_TONE_PHASE_T p0, TX_TTG_TONE_PHASE_T p1);
void UL1D_TXDFE_ASYMM_COMP_PARAM_BASIC_CON(kal_int16 *pComp_q, kal_int16 *pComp_i, kal_int8 mode, kal_int8 set);
void UL1D_TXDFE_FREQ_DEP_COMP_PARAM_BASIC_CON(kal_int16 *pComp, kal_int8 mode, kal_int8 gain);

//For POC RX API
void UL1D_RXDFE_DCO_SEL_CON_SP(RX_PATH_T path_sel, RX_CAL_MODE_T cal_mode, RX_SRC_SEL_T src_sel);
void UL1D_RXDFE_DCO_VALUE_SET_SP(RX_PATH_T path_sel, RX_CAL_MODE_T cal_mode, kal_uint16 dc_i, kal_uint16 dc_q, RX_ANT_T ant);
void UL1D_RXDFE_FDPM_COEF_SET_SP(RX_PATH_T path_sel, RX_CAL_MODE_T cal_mode, kal_uint8 cnum);
void UL1D_RXDFE_IQC_SET_SP(RX_PATH_T path_sel, RX_CAL_MODE_T cal_mode, kal_uint8 iq_gain, kal_uint8 iq_phase, kal_uint8 iq_gain_d, kal_uint8 iq_phase_d);
void UL1D_RXDFE_RFEQ_CON_SP(RX_PATH_T path_sel, RX_CAL_MODE_T cal_mode, kal_int8 rnd_bit, RX_RFEQ_COMPLEX_TAPS_T taps, kal_int8 rnd_bit_d, RX_RFEQ_COMPLEX_TAPS_T taps_d);
void UL1D_RXDFE_RFEQ_COMPLEX_COEF_SET_SP(RX_PATH_T path_sel, RX_CAL_MODE_T cal_mode);
void UL1D_RXDFE_RFEQ_LEGACY_COEF_SET_SP(RX_PATH_T path_sel, RX_CAL_MODE_T cal_mode, kal_uint8 cnum);
void UL1D_RXDFE_FC_ON_OFF_PATH_CON_SP(RX_PATH_T path_sel, RX_CAL_MODE_T cal_mode, kal_uint8 wb_en, RX_FDPM_TAPS_T i_tap, RX_FDPM_TAPS_T q_tap, kal_uint8 iqc_en, kal_uint8 rfeq_en);
void UL1D_RXDFE_CAL_PATH_ON(RF_RX_PATH_T antpath, RX_PATH_T path, kal_uint8 cmask, RX_CAL_MODE_T cal_mode, kal_uint8 iqkmask, kal_uint8 rxkmask, kal_uint8 is_imm, kal_uint8 gnum,kal_uint16 ontime);
void UL1D_RXDFE_CAL_PATH_OFF(RF_RX_PATH_T antpath, RX_PATH_T path, kal_uint8 cmask, kal_uint8 is_imm, kal_uint8 gnum,kal_uint16 offtime);
void UL1D_RXDFE_CAL_IMM_STROBE_CON(RF_RX_PATH_T antpath, RX_PATH_T path, kal_uint8 cmask, kal_uint8 rxk_mask, kal_uint8 iqk_mask);
//void UL1D_RXDFE_FREQOFF_IMM_SET(RF_RX_PATH_T antpath, kal_int32 freq_error/*Hz*/, RX_CARRIER_T carrier_sel, kal_bool is_3c);
void UL1D_RXDFE_CAL_FC_CON(RX_CAL_MODE_T cal_mode, RX_PATH_T path, RX_PATH_BANDWIDTH_T BWT, kal_uint8 cmask);

/** RF Route Table */
void UL1D_RF_ConstructRxIrrConfigTable(void);
void UL1D_RF_ConstructRxDcConfigTable(void);
void UL1D_RF_ConstructRxIip2ConfigTable(void);
void UL1D_RF_GetRxIrrDcConfigTable( UMTSBand band, MMRFC_RX_CAL_IRR_DC_CFG_T* irr_dc_cfg, kal_uint8 is_irr_cal );
void UL1D_RF_GetRxIip2ConfigTable( UMTSBand band, MMRFC_RX_CAL_IIP2_CFG_T* iip2_cfg );
void UL1D_RF_CAL_Set_TX_CW_Rx_IIP2_CAL(MMRFC_TX_CAL_CFG_T *tx_cfg);

/** API to get TX DET ANT*/
void UL1D_RF_GET_TX_DET_ANT(MMRFC_XL1_BAND_NUM_E band);

/** API for TAS*/
kal_bool UL1D_RF_TAS_Support(void);
void UL1D_RF_Force_TAS(kal_bool force_tas_enable, kal_uint8 tas_idx);

#if IS_3G_DAT_RFD_CTRL_EN
void UL1D_RF_Force_DAT(kal_bool dat_feature_enable, kal_int16 scenario);
kal_bool URFD_AP_Sensor_Relative_Feature_IS_Need_L1C_GAP(MMRF_AP_SENSOR_RELATIVE_OP_CODE_E OP_code, kal_int16 new_scenario);
#endif

/** API for BSI_W Init for MML1 normal power on flow */
void UL1D_RF_INIT_BSI_POWER_ON(void);
/************************************************************************************
*  Global Variables extern (Interface)
************************************************************************************/
extern kal_uint32*          wrfcalPocBufferTable              [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern kal_uint32           wrfcalPocBufferSizeTable          [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern MML1_RF_BSIMM_PORT_T wrfcalPocBufferDataPortSelTable   [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern MML1_MIPI_REG_RW_T   wrfcalPocBufferDataMipiCwTypeTable[/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern UL1D_RF_CAL_MIPI_DATA_T UMTS_MIPI_PA_ON_DATA           [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern UL1D_RF_CAL_MIPI_DATA_T UMTS_MIPI_PA_OFF_DATA          [/*MMPOC_BUFFER_TYPE_NUM_OF*/];


//for set TX anti-droop by calling UL1D_TXDFE_FIXED_COEF_CON()
extern kal_int16 TXDFE_ANTI_DROOP[2][2][26][2];
//for set RX FDPM COEF
extern kal_uint16 RXDFE_FDPM_COEF_I[2][2][9];
extern kal_uint16 RXDFE_FDPM_COEF_Q[2][2][9];
//for set RX RFEQ COMPLEX
extern kal_uint16 RXDFE_RFEQ_COMPLEX_COEF_I[2][7];
extern kal_uint16 RXDFE_RFEQ_COMPLEX_COEF_Q[2][7];
//for set RX RFEQ LEGACY
extern kal_uint16 RXDFE_RFEQ_LEAGCY_COEF[3][12];


#endif /* End of #ifndef _UL1D_MMRF_INTERFACE_H_ */

