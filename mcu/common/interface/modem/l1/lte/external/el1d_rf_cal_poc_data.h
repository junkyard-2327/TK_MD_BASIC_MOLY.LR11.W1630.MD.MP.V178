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
 * @addtogroup EL1D_RF_CUSTOM_DATA
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @file       el1d_rf_cal_poc_data.h
 * @author     ChunChieh Liao (MTK05759)
 * @date       2015.01.26
 * @brief      EL1D RF POC SHM data header file
 * @details    Provide RF POC data structure for PCORE and L1CORE (SHM)
 ******************************************************************************/

#ifndef __EL1D_RF_CAL_POC_DATA_H__
#define __EL1D_RF_CAL_POC_DATA_H__

/*******************************************************************************
 * #include
 ******************************************************************************/
#include "kal_general_types.h"
#include "mml1_rf_cal_def.h"
#include "el1d_rf_def.h"
#include "el1d_rf_public.h"

/*******************************************************************************
 * #define
 ******************************************************************************/

/* DO NOT MODIFY !!! , Internal use */
#define LTE_POC_NVRAM_VERNO_1  (1)
#define LTE_POC_NVRAM_VERNO_0  (0)
#define LTE_POC_NVRAM_LATEST_VERNO  (LTE_POC_NVRAM_VERNO_1)

#define LTE_RX_IRR_COMP_ROUTE_MAX_VERNO_0   (5)
#define LTE_RX_DC_COMP_ROUTE_MAX_VERNO_0    LTE_RX_IRR_COMP_ROUTE_MAX_VERNO_0
        
/*******************************************************************************
 * Enum
 ******************************************************************************/
typedef enum{    
    LTE_DET_CBW_COMP_INDEX_0, /* 1.4MHz, 3MHz */
    LTE_DET_CBW_COMP_INDEX_1, /* 5MHz */
    LTE_DET_CBW_COMP_INDEX_2, /* 10MHz */
    LTE_DET_CBW_COMP_INDEX_3, /* 15MHz */
    LTE_DET_CBW_COMP_INDEX_4, /* 20MHz */
} LTE_DET_CBW_COMP_INDEX_E;

/*******************************************************************************
 * Typedef
 ******************************************************************************/

typedef struct{    
    kal_int8            gain_est_hw;
    kal_int8            phase_est_hw;
    kal_int16           freq_dep_filt[MMRFC_FILT_TAPS_NUM]; ///< Valid for 2-point meas.
} LTE_RF_POC_RX_IRR_COMP_T;

typedef struct
{
  LTE_RF_POC_RX_IRR_COMP_T  rx_irr_hpm[MMRFC_ANT_NUM];
  LTE_RF_POC_RX_IRR_COMP_T  rx_irr_lpm[MMRFC_ANT_NUM];
  
#ifdef TK6291_E1EVB
#else 
  LTE_RF_POC_RX_IRR_COMP_T  rx_irr_hpm_lif[MMRFC_ANT_NUM];
#endif  

} LTE_RF_POC_RX_IRR_COMP_PER_ROUTE_T;

typedef struct
{
   kal_int16            dc_i;
   kal_int16            dc_q;
} LTE_RF_POC_RX_DC_COMP_T;

typedef struct
{
   LTE_RF_POC_RX_DC_COMP_T     rx_dc[MMRFC_RXDC_TIA_GAIN_STEPS][MMRFC_RXDC_PGA_GAIN_STEPS]; 
} LTE_RF_POC_RX_DC_HPM_COMP_T;

typedef struct
{
  LTE_RF_POC_RX_DC_HPM_COMP_T  rx_rf_dc_hpm[MMRFC_ANT_NUM]; 
  LTE_RF_POC_RX_DC_COMP_T      rx_rf_dc_lpm[MMRFC_ANT_NUM];
  LTE_RF_POC_RX_DC_HPM_COMP_T  rx_dig_dc_hpm[MMRFC_ANT_NUM];
  LTE_RF_POC_RX_DC_COMP_T      rx_dig_dc_lpm[MMRFC_ANT_NUM];
} LTE_RF_POC_RX_DC_COMP_PER_ROUTE_T;
   
typedef struct
{
   kal_int8             gate_bias_i;
   kal_int8             gate_bias_q;
} LTE_RF_POC_RX_IIP2_COMP_T;

typedef struct{    
    kal_int8            gain_est_hw;
    kal_int8            phase_est_hw;
    kal_int16           freq_dep_filt[MMRFC_FILT_TAPS_NUM]; ///< Valid for 2-point meas.
} LTE_RF_POC_DET_IQ_COMP_T;

typedef struct
{
   kal_int16            dc_i;
   kal_int16            dc_q;
} LTE_RF_POC_DET_DC_COMP_T;

typedef struct{    
    kal_int8            gain_est;
    kal_int8            phase_est;
} LTE_RF_POC_TX_IQ_COMP_T;

typedef struct
{
   kal_int16            dc_i;
   kal_int16            dc_q;
} LTE_RF_POC_TX_DC_COMP_T;

typedef struct{    
    kal_int16            freq_dep_filt[MMRFC_FILT_TAPS_NUM];
} LTE_TX_FD_FILT_COMP_T;

typedef struct{    
    kal_int16           re;    
    kal_int16           im;
} LTE_COMPLEX_16_T;

typedef struct
{
   LTE_COMPLEX_16_T    tx_ga_filt_lin_1[MMRFC_FILT_TAPS_NUM];
   LTE_COMPLEX_16_T    tx_ga_filt_lin_2[MMRFC_FILT_TAPS_NUM];
} LTE_RF_POC_TX_GA_FILT_COMP_T;

typedef struct
{
   kal_int16            slope[MMRFC_TXGA_MAX_TONES-1];
   kal_int16            mag_inv_norm[MMRFC_TXGA_MAX_TONES];
} LTE_RF_POC_TX_GA_TPC_COMP_T;

typedef struct{    
   LTE_RF_POC_TX_GA_FILT_COMP_T  tx_ga_filt_comp; 
   LTE_RF_POC_TX_GA_TPC_COMP_T   tx_ga_tpc_comp;
} LTE_RF_POC_TX_GA_COMP_T;

typedef struct
{
   /* RX IRR */
   LTE_RF_POC_RX_IRR_COMP_PER_ROUTE_T  rx_irr[LTE_RX_IRR_COMP_ROUTE_MAX][MMRFC_LTE_RX_CBW_NUM];

   /* RX DC */
   LTE_RF_POC_RX_DC_COMP_PER_ROUTE_T   rx_dc[LTE_RX_DC_COMP_ROUTE_MAX];

   /* RX IIP2 */
   LTE_RF_POC_RX_IIP2_COMP_T   rx_iip2[MMRFC_RX_IIP2_COMP_ROUTE_MAX];
   
} LTE_RF_POC_RX_COMP_DATA_T;

typedef struct
{
   /* DET Coarse DCOC */
   kal_uint32                  det_coarse_dcoc_cw807;
   kal_uint32                  det_coarse_dcoc_cw808;
   
   /* DET IQ/DC/DNL Forward */
   LTE_RF_POC_DET_IQ_COMP_T    det_iq_fwd[MMRFC_DET_FE_GAIN_STEPS][MMRFC_LTE_TX_CBW_NUM];
   LTE_RF_POC_DET_DC_COMP_T    det_dc_fwd[MMRFC_DET_GAIN_STEPS];
   kal_int16                   det_dnl_fwd[MMRFC_DET_GAIN_STEPS];

   /* DET IQ/DC/DNL Reverse */
   LTE_RF_POC_DET_IQ_COMP_T    det_iq_rev[MMRFC_DET_FE_GAIN_STEPS][MMRFC_LTE_TX_CBW_NUM];
   LTE_RF_POC_DET_DC_COMP_T    det_dc_rev[MMRFC_DET_GAIN_STEPS];
   kal_int16                   det_dnl_rev[MMRFC_DET_GAIN_STEPS];

} LTE_RF_POC_DET_COMP_DATA_T;

typedef struct
{
   /* TX LO Cal */
   kal_uint8                   tx_lo_ind;
   kal_uint8                   tx_lo_capcal_peak_cap;
   kal_uint8                   tx_lo_in_bias_hpm;
   kal_uint8                   tx_lo_in_bias_lpm;  
   kal_int32                   stx_delta_duty_cycle;
   
   /* TX RC */
   kal_int16                   tx_rc_lpf[MMRFC_LTE_TX_CBW_NUM];
   kal_int16                   tx_rc_rcf;

   /* TX FIIQ/DC/DNL */
   LTE_RF_POC_TX_IQ_COMP_T     tx_iq_lin[MMRFC_TX_PGA_SLICE_NUM+1];
   LTE_RF_POC_TX_DC_COMP_T     tx_dc_lin[MMRFC_TX_PGA_SLICE_NUM+1];
   
#ifdef TK6291_E1EVB
#else
   LTE_RF_POC_TX_IQ_COMP_T     tx_iq_dpd[MMRFC_TX_PGA_SLICE_NUM+1];
   LTE_RF_POC_TX_DC_COMP_T     tx_dc_dpd[MMRFC_TX_PGA_SLICE_NUM+1];
#endif

   kal_int16                   tx_dnl_lin_pga_a[MMRFC_TX_DNL_PGA_A_GAIN_STEPS];
   kal_int16                   tx_dnl_lin_pga_b[MMRFC_TX_DNL_PGA_B_GAIN_STEPS+MMRFC_TX_DNL_PGA_AUX_GAIN_STEPS];

   /* TX FDIQ */
   LTE_TX_FD_FILT_COMP_T       tx_fdiq_lin_1[MMRFC_LTE_TX_CBW_NUM][MMRFC_TX_PGA_SLICE_NUM+1];
   LTE_TX_FD_FILT_COMP_T       tx_fdiq_lin_2[MMRFC_LTE_TX_CBW_NUM][MMRFC_TX_PGA_SLICE_NUM+1];
   
   /* TX GA */
   LTE_RF_POC_TX_GA_COMP_T     tx_ga_w_ET[MMRFC_TX_PGA_TYPE_NUM][MMRFC_LTE_TX_CBW_NUM];
   LTE_RF_POC_TX_GA_COMP_T     tx_ga_wo_ET[MMRFC_TX_PGA_TYPE_NUM][MMRFC_LTE_TX_CBW_NUM];

   /* TX PGA Gain Step */
   kal_int16                   pga_gain_step[MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM][MMRFC_TX_PGA_GAIN_STEP_NUM];

   /* TX PGA Cap Tuning */
   kal_uint8                   cap_tuning_pga_a;
   kal_uint8                   cap_tuning_pga_b;
} LTE_RF_POC_TX_COMP_DATA_T;


typedef struct
{
   LTE_RF_POC_RX_COMP_DATA_T  lte_rx_comp[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
   LTE_RF_POC_DET_COMP_DATA_T lte_det_comp[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
   LTE_RF_POC_TX_COMP_DATA_T  lte_tx_comp[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
   LTE_RF_POC_DET_COMP_DATA_T lte_det_comp_hrm[LTE_TX_HRM_MAX_SUPPORT_BAND_NUM];
   LTE_RF_POC_TX_COMP_DATA_T  lte_tx_comp_hrm[LTE_TX_HRM_MAX_SUPPORT_BAND_NUM];

   LTE_RF_POC_TX_COMP_DATA_T  lte_tx_comp_b40[MMRFC_TX_PGA_CAP_TUNING_SUBBAND_NUM];
   LTE_RF_POC_TX_COMP_DATA_T  lte_tx_comp_b41[MMRFC_TX_PGA_CAP_TUNING_SUBBAND_NUM];
   
} LTE_RF_POWER_ON_CAL_DATA_T;


/** LTE POC result struct for Nvram */
/** Note: If change struct, need to take care nvram/EMI exchange function */
typedef struct
{   
#ifdef TK6291_E1EVB
#else
   kal_uint32 verno;
#endif
   LTE_Band band;
   LTE_RF_POC_RX_COMP_DATA_T  lte_rx_comp;
   LTE_RF_POC_DET_COMP_DATA_T lte_det_comp;
   LTE_RF_POC_TX_COMP_DATA_T  lte_tx_comp;

} LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T;

/** LTE HRM POC result struct for Nvram */
/** Note: If change struct, need to take care nvram/EMI exchange function */
typedef struct
{   
   kal_uint32 verno;
   LTE_Band band;
   LTE_RF_POC_DET_COMP_DATA_T lte_det_comp;
   LTE_RF_POC_TX_COMP_DATA_T  lte_tx_comp;

} LTE_RF_2ND_POWER_ON_CAL_DATA_PER_BAND_T;

/** Noted : lte_tx_comp_subband_3 should follow lte_tx_comp_subband_2 and can't be seperated by other struct member*/
typedef struct
{
#ifdef TK6291_E1EVB
#else
   kal_uint32 verno;
#endif
   LTE_Band band;
   LTE_RF_POC_TX_COMP_DATA_T  lte_tx_comp_subband_2; //For B40,B41 TX SUBBAND 2
   LTE_RF_POC_TX_COMP_DATA_T  lte_tx_comp_subband_3; //For B40,B41 TX SUBBAND 3
} LTE_RF_POWER_ON_CAL_DATA_TX_SUBBAND_T;



/*****************************************************************/
/*   DO NOT MODIFY !!!                                           */
/*   MT6755 POC VER_0 NVRAM struct                               */
/*   NVRAM VER 0 Struct same as MMRFC_RX_IRR_COMP_ROUTE_MAX(5)   */
/*   & MMRFC_RX_DC_COMP_ROUTE_MAX(5)  as Max route num           */
/*   Noted: TK6291 STRUCT DON'T CARE , no need to handle         */
/*****************************************************************/
typedef struct
{
   /* RX IRR */
   LTE_RF_POC_RX_IRR_COMP_PER_ROUTE_T  rx_irr[LTE_RX_IRR_COMP_ROUTE_MAX_VERNO_0][MMRFC_LTE_RX_CBW_NUM];

   /* RX DC */
   LTE_RF_POC_RX_DC_COMP_PER_ROUTE_T   rx_dc[LTE_RX_DC_COMP_ROUTE_MAX_VERNO_0];

   /* RX IIP2 */
   LTE_RF_POC_RX_IIP2_COMP_T           rx_iip2[MMRFC_RX_IIP2_COMP_ROUTE_MAX];
   
} LTE_RF_POC_RX_COMP_DATA_VERNO_0_T;


typedef struct
{   
#ifdef TK6291_E1EVB
#else
   kal_uint32 verno;
#endif
   LTE_Band band;
   LTE_RF_POC_RX_COMP_DATA_VERNO_0_T  lte_rx_comp;
   LTE_RF_POC_DET_COMP_DATA_T         lte_det_comp;
   LTE_RF_POC_TX_COMP_DATA_T          lte_tx_comp;

} LTE_RF_POWER_ON_CAL_DATA_PER_BAND_VERNO_0_T;



/*****************************************************************/
/*   LTE debug Recal Structure                                   */
/*   DO NOT MODIFY !!!                                           */
/*                                                               */
/*****************************************************************/

//Here refer to MMRFC result structure which was from post-processing

/* sync MMRFC_RX_IRR_RESULT_T */
typedef struct
{    
    kal_int32            gain_est_hw;
    kal_int32            phase_est_hw;
    kal_int16            freq_dep_filt[MMRFC_FILT_TAPS_NUM]; ///< Valid for 2-point meas.
    kal_int16            freq_dep_phase_est;                 ///< Valid for 2-point meas.
} MMRFC_RX_IRR_RESULT_DBG_T;

typedef struct
{    
    kal_int32            gain_est_hw;
    kal_int32            phase_est_hw;
    kal_int16            freq_dep_filt[MMRFC_FILT_TAPS_NUM]; ///< Valid for 2-point meas.
} MMRFC_DET_IQ_RESULT_DBG_T;

typedef struct
{    
    kal_int32            dc_est_i;
    kal_int32            dc_est_q;
} MMRFC_DET_DC_RESULT_DBG_T;

typedef struct
{    
    kal_int32            gain_est;
    kal_int32            phase_est;
    kal_int32            dc_est_i;
    kal_int32            dc_est_q;
    kal_int16            freq_dep_phase_tx; ///< temp output for TX FDIQ
} MMRFC_TX_IQDC_RESULT_DBG_T;

typedef struct
{    
    kal_int16            freq_dep_filt_mode1[MMRFC_FILT_TAPS_NUM];
    kal_int16            freq_dep_filt_mode2[MMRFC_FILT_TAPS_NUM];
} MMRFC_TX_FD_FILT_RESULT_DBG_T;

typedef struct
{
   kal_int16 dc_i;
   kal_int16 dc_q;
} MMRFC_RX_DC_RESULT_DBG_T;

typedef struct
{
  MMRFC_RX_DC_RESULT_DBG_T rx_dc[MMRFC_RXDC_TIA_GAIN_STEPS][MMRFC_RXDC_PGA_GAIN_STEPS];
} MMRFC_RX_DC_HPM_RESULT_DBG_T;


typedef struct
{
   /* RX IRR */
   MMRFC_RX_IRR_RESULT_DBG_T       rx_irr_hpm[LTE_RX_IRR_COMP_ROUTE_MAX][MMRFC_LTE_RX_CBW_NUM][MMRFC_ANT_NUM];
   MMRFC_RX_IRR_RESULT_DBG_T       rx_irr_lpm[LTE_RX_IRR_COMP_ROUTE_MAX][MMRFC_LTE_RX_CBW_NUM][MMRFC_ANT_NUM];
   MMRFC_RX_IRR_RESULT_DBG_T       rx_irr_hpm_lif[LTE_RX_IRR_COMP_ROUTE_MAX][MMRFC_LTE_RX_CBW_NUM][MMRFC_ANT_NUM];

   /* DET */
   kal_uint32                      det_coarse_dcoc_cw807;
   kal_uint32                      det_coarse_dcoc_cw808; 
   MMRFC_DET_IQ_RESULT_DBG_T       det_iqdnl_fwd[MMRFC_DET_FE_GAIN_STEPS][MMRFC_LTE_TX_CBW_NUM]; //1.4MHz and 3MHz share the same config -> restore result per CBW(20150206)
   MMRFC_DET_DC_RESULT_DBG_T       det_dc_fwd[MMRFC_DET_GAIN_STEPS];

   MMRFC_DET_IQ_RESULT_DBG_T       det_iqdnl_rev[MMRFC_DET_FE_GAIN_STEPS][MMRFC_LTE_TX_CBW_NUM]; //1.4MHz and 3MHz share the same config -> restore result per CBW(20150206)
   MMRFC_DET_DC_RESULT_DBG_T       det_dc_rev[MMRFC_DET_GAIN_STEPS];            
   
   /* TX */
   MMRFC_TX_IQDC_RESULT_DBG_T      tx_iqdc_lin[MMRFC_TX_PGA_SLICE_NUM+1];
   MMRFC_TX_FD_FILT_RESULT_DBG_T   tx_fdiq[MMRFC_LTE_TX_CBW_NUM][MMRFC_TX_PGA_SLICE_NUM+1];     
}  MMRFC_LTE_RESULT_DBG_PER_BAND_T;


typedef struct
{
   MMRFC_LTE_RESULT_DBG_PER_BAND_T lte_result_rek[LTE_TARGET_MAX_SUPPORT_BAND_NUM];

   MMRFC_LTE_RESULT_DBG_PER_BAND_T lte_result_b40_rek[MMRFC_TX_PGA_CAP_TUNING_SUBBAND_NUM];
   MMRFC_LTE_RESULT_DBG_PER_BAND_T lte_result_b41_rek[MMRFC_TX_PGA_CAP_TUNING_SUBBAND_NUM];
   
} MMRFC_LTE_RESULT_DBG_T;


typedef struct
{
   /* RX DC */
   MMRFC_RX_DC_HPM_RESULT_DBG_T    rx_dc_hpm_rek[LTE_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM];
   MMRFC_RX_DC_RESULT_DBG_T        rx_dc_lpm_rek[LTE_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM];
   MMRFC_RX_DC_HPM_RESULT_DBG_T    rx_dc_hpm_rek_final[LTE_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM];
   MMRFC_RX_DC_RESULT_DBG_T        rx_dc_lpm_rek_final[LTE_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM];
} MMRFC_LTE_RXDCOC_RESULT_DBG_PER_BAND_T;


typedef struct
{
   MMRFC_LTE_RXDCOC_RESULT_DBG_PER_BAND_T lte_rxdcoc_result_rek[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
   
} MMRFC_RXDCOC_LTE_RESULT_DBG_T;


/*******************************************************************************
 * Global variables (Extern)
 ******************************************************************************/



/*******************************************************************************
** Global data for RF customization and META Factory Calibration
*******************************************************************************/




/*******************************************************************************
 * Global Functions Prototype (Interface)
 ******************************************************************************/

#endif /*__EL1D_RF_CAL_POC_DATA_H__*/

/* Doxygen Group End ***************************************************//**@}*/
