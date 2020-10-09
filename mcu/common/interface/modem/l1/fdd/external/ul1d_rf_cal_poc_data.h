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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
/* Doxygen Group Header ****************************************************//**
 * @addtogroup UL1D_RF_CUSTOM_DATA
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @file       ul1d_rf_cal_poc_data.h
 * @author     Neil Chung(MTK08266)
 * @date       2015.01.26
 * @brief      UL1D RF POC SHM data header file
 * @details    Provide RF POC data structure for PCORE and L1CORE (SHM)
 ******************************************************************************/

#ifndef __UL1D_RF_CAL_POC_DATA_H__
#define __UL1D_RF_CAL_POC_DATA_H__

/*******************************************************************************
 * #include
 ******************************************************************************/
#include "kal_general_types.h"
#include "mml1_rf_cal_def.h"

/*******************************************************************************
 * #define
 ******************************************************************************/


/*******************************************************************************
 * Enum
 ******************************************************************************/
typedef enum{    
    UMTS_DET_CBW_COMP_INDEX_0, /* 5MHz */
    UMTS_DET_CBW_COMP_INDEX_1, /* 10MHz */
    UMTS_DET_CBW_COMP_INDEX_2, /* 15MHz */
} UMTS_DET_CBW_COMP_INDEX_E;



/*******************************************************************************
 * Typedef
 ******************************************************************************/
/** Structure Prototypes can be seen by other files */

typedef struct
{
   kal_uint32 emptydata;
}UL1D_RF_CAL_POC_RESULT_T;

/******************************
* Rx POC Part
*******************************/
typedef struct{    
    kal_int8            gain_est_hw;
    kal_int8            phase_est_hw;
    kal_int16           freq_dep_filt[MMRFC_FILT_TAPS_NUM];
} UMTS_RF_POC_RX_IRR_COMP_T;


typedef struct
{
   kal_int16 dc_i;
   kal_int16 dc_q;
} UMTS_RF_POC_RX_DC_COMP_T;

typedef struct
{
  UMTS_RF_POC_RX_DC_COMP_T    rx_dc[MMRFC_RXDC_TIA_GAIN_STEPS][MMRFC_RXDC_PGA_GAIN_WCDMA_STEPS];
} UMTS_RF_POC_RX_DC_HPM_COMP_T;

typedef struct
{
   kal_int8             gate_bias_i;
   kal_int8             gate_bias_q;
} UMTS_RF_POC_RX_IIP2_COMP_T;

typedef struct
{
   /* RX IRR */
   UMTS_RF_POC_RX_IRR_COMP_T    rx_irr_hpm[MMRFC_RX_IRR_COMP_ROUTE_MAX][MMRFC_UMTS_RX_CBW_NUM][MMRFC_ANT_NUM];
   UMTS_RF_POC_RX_IRR_COMP_T    rx_irr_lpm[MMRFC_RX_IRR_COMP_ROUTE_MAX][MMRFC_UMTS_RX_CBW_NUM][MMRFC_ANT_NUM];

   /* RX DC */
   UMTS_RF_POC_RX_DC_HPM_COMP_T rx_rf_dc_hpm[MMRFC_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM];
   UMTS_RF_POC_RX_DC_COMP_T     rx_rf_dc_lpm[MMRFC_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM];
   UMTS_RF_POC_RX_DC_HPM_COMP_T rx_dig_dc_hpm[MMRFC_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM];
   UMTS_RF_POC_RX_DC_COMP_T     rx_dig_dc_lpm[MMRFC_RX_DC_COMP_ROUTE_MAX][MMRFC_ANT_NUM];

   /* RX IIP2 */
   UMTS_RF_POC_RX_IIP2_COMP_T   rx_iip2[MMRFC_RX_IIP2_COMP_ROUTE_MAX];
   
} UMTS_RF_POC_RX_COMP_DATA_T;

/******************************
* Tx DET POC Part
*******************************/
typedef struct{    
    kal_int8            gain_est_hw;
    kal_int8            phase_est_hw;
    kal_int16           freq_dep_filt[MMRFC_FILT_TAPS_NUM];
} UMTS_RF_POC_DET_IQ_COMP_T;

typedef struct
{
   kal_int16            dc_i;
   kal_int16            dc_q;
} UMTS_RF_POC_DET_DC_COMP_T;

typedef struct
{
   /* DET Coarse DCOC */
   kal_uint32                  det_coarse_dcoc_cw807;
   kal_uint32                  det_coarse_dcoc_cw808;

   /* DET IQ/DC/DNL Forward */
   UMTS_RF_POC_DET_IQ_COMP_T    det_iq_fwd[MMRFC_DET_FE_GAIN_STEPS][MMRFC_UMTS_TX_CBW_NUM];
   UMTS_RF_POC_DET_DC_COMP_T    det_dc_fwd[MMRFC_DET_GAIN_STEPS];
   kal_int16                    det_dnl_fwd[MMRFC_DET_GAIN_STEPS];

   /* DET IQ/DC/DNL Reverse */
   UMTS_RF_POC_DET_IQ_COMP_T    det_iq_rev[MMRFC_DET_FE_GAIN_STEPS][MMRFC_UMTS_TX_CBW_NUM];
   UMTS_RF_POC_DET_DC_COMP_T    det_dc_rev[MMRFC_DET_GAIN_STEPS];
   kal_int16                    det_dnl_rev[MMRFC_DET_GAIN_STEPS];
} UMTS_RF_POC_DET_COMP_DATA_T;

/******************************
* Tx FOWRAD POC Part
*******************************/
typedef struct{    
    kal_int8            gain_est;
    kal_int8            phase_est;
} UMTS_RF_POC_TX_IQ_COMP_T;

typedef struct
{
   kal_int16            dc_i;
   kal_int16            dc_q;
} UMTS_RF_POC_TX_DC_COMP_T;

typedef struct{    
    kal_int16           freq_dep_filt[MMRFC_FILT_TAPS_NUM];
} UMTS_TX_FD_FILT_COMP_T;

typedef struct{    
    kal_int16           re;    
    kal_int16           im;
} UMTS_COMPLEX_16_T;

typedef struct
{
   UMTS_COMPLEX_16_T    tx_ga_filt_lin_1[MMRFC_FILT_TAPS_NUM];
   UMTS_COMPLEX_16_T    tx_ga_filt_lin_2[MMRFC_FILT_TAPS_NUM];
} UMTS_RF_POC_TX_GA_FILT_COMP_T;

typedef struct
{
   kal_int16            slope[MMRFC_TXGA_MAX_TONES-1];
   kal_int16            mag_inv_norm[MMRFC_TXGA_MAX_TONES];
} UMTS_RF_POC_TX_GA_TPC_COMP_T;

typedef struct{    
   UMTS_RF_POC_TX_GA_FILT_COMP_T  tx_ga_filt_comp; 
   UMTS_RF_POC_TX_GA_TPC_COMP_T   tx_ga_tpc_comp;
} UMTS_RF_POC_TX_GA_COMP_T;

typedef struct
{
   /* TX LO Cal */
   kal_uint32                   tx_lo;
   kal_uint8                    tx_lo_ind;
   kal_uint8                    tx_lo_capcal_peak_cap;
   kal_uint8                    tx_lo_in_bias_hpm;
   kal_uint8                    tx_lo_in_bias_lpm;
   kal_uint32                   stx_dcc_delta_nc;
   
   /* TX RC */
   kal_int16                     tx_rc_lpf[MMRFC_UMTS_TX_CBW_NUM];
   kal_int16                     tx_rc_rcf;

   /* TX FIIQ/DC/DNL Linear Mode */
   UMTS_RF_POC_TX_IQ_COMP_T     tx_iq_lin[MMRFC_TX_PGA_SLICE_NUM+1];
   UMTS_RF_POC_TX_DC_COMP_T     tx_dc_lin[MMRFC_TX_PGA_SLICE_NUM+1];

#ifndef TK6291_E1EVB //Only available for chip later than TK6291 because TK6291 calibration file has no these items
   UMTS_RF_POC_TX_IQ_COMP_T     tx_iq_dpd[MMRFC_TX_PGA_SLICE_NUM+1];
   UMTS_RF_POC_TX_DC_COMP_T     tx_dc_dpd[MMRFC_TX_PGA_SLICE_NUM+1];
#endif

   kal_int16                    tx_dnl_lin_pga_a[MMRFC_TX_DNL_PGA_A_GAIN_STEPS];
   kal_int16                    tx_dnl_lin_pga_b[MMRFC_TX_DNL_PGA_B_GAIN_STEPS+MMRFC_TX_DNL_PGA_AUX_GAIN_STEPS];

   /* TX FDIQ Linear Mode 1 */
   UMTS_TX_FD_FILT_COMP_T       tx_fdiq_lin_1[MMRFC_UMTS_TX_CBW_NUM][MMRFC_TX_PGA_SLICE_NUM+1];
   /* TX FDIQ Linear Mode 2 */
   UMTS_TX_FD_FILT_COMP_T       tx_fdiq_lin_2[MMRFC_UMTS_TX_CBW_NUM][MMRFC_TX_PGA_SLICE_NUM+1];
   
   /* TX GA */
   UMTS_RF_POC_TX_GA_COMP_T     tx_ga_w_ET[MMRFC_TX_PGA_TYPE_NUM][MMRFC_UMTS_TX_CBW_NUM];
   UMTS_RF_POC_TX_GA_COMP_T     tx_ga_wo_ET[MMRFC_TX_PGA_TYPE_NUM][MMRFC_UMTS_TX_CBW_NUM];

   /* TX PGA Phase Step */
   kal_int16                    pga_phase_step;

   /* TX PGA Gain Step */
   kal_int16                    pga_gain_step[MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM][MMRFC_TX_PGA_GAIN_STEP_NUM];

   /* TX PGA Cap Tuning */
   kal_int8                     cap_tuning_pga_a;
   kal_int8                     cap_tuning_pga_b;
} UMTS_RF_POC_TX_COMP_DATA_T;


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
