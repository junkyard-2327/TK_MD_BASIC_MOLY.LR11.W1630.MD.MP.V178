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
 *   tl1d_mmrf_interface.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   TL1D interface to Multi-Mode Multi-RAT RF Central Control
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _TL1D_MMRF_INTERFACE_H_
#define  _TL1D_MMRF_INTERFACE_H_

/*===============================================================================*/
#include "kal_general_types.h"
#include "mml1_rf_interface.h"
#include "mml1_rf_cal_interface.h"

/*===============================================================================*/


/*===============================================================================*/
/*                     RF Calibration Result Structure                           */
/*     The structure is grouped from post-processing result. Some redundent      */
/*     items may need to be removed and excluded in shared memory or NVRAM.      */
/*===============================================================================*/

typedef enum
{
   TTG_1ST,
   TTG_2ND,
   TTG_3RD,
   TTG_4TH,
   TTG_NUM,
} TDDTXDFE_TTG_INDEX_E;


typedef enum
{
   TDS_COS_ONLY,
   TDS_SIN_ONLY,
   TDS_COS_N_P_SIN,
   TDS_COS_N_N_SIN,
   TDS_TTG_MODE_NUM,
} TDDTXDFE_TTG_MODE_E;

typedef enum
{
   TDS_DPD_MODE=0,   
   TDS_LINEAR_MODE1=2,
   TDS_LINEAR_MODE1_ET=3,
   TDS_LINEAR_MODE2=4,
   TDS_LINEAR_MODE2_ET=5,
} TDDTXDFE_SW_MODE_E;

typedef enum
{
   TDS_PGA_SETA_SLICE1,
   TDS_PGA_SETA_SLICE2,    
   TDS_PGA_SETA_SLICE4,
   TDS_PGA_SETA_SLICE7,
   TDS_PGA_SETA_SLICE8,
   TDS_PGA_SETB_SLICE1,
   TDS_PGA_SETB_SLICE2,
   TDS_PGA_SETAUX,
} TDDTXDFE_SW_GAIN_INFO_E;

typedef enum
{
   TDS_LTE_1P4M,
   TDS_LTE_3M,    
   TDS_LTE_5M,
   TDS_LTE_10M,
   TDS_LTE_15M,
   TDS_LTE_20M,
   TDS_LTE_PRACH_FMT0,  // 4'd6~9: LTE-PRACH FMT 0~3
   TDS_LTE_PRACH_FMT1,
   TDS_LTE_PRACH_FMT2,
   TDS_LTE_PRACH_FMT3,
   TDS_LTE_PRACH_FMT4,
   TDS_W_FDD_SC,
   TDS_W_FDD_DC,
   TDS_W_TDD,
} TDDTXDFE_SW_RAT_E;

typedef struct
{
    kal_uint32 rxdfe_filter_parameter[9];
}TDDRXDFE_FDPM_PARA_T;


typedef struct
{
   /** TTG phase*/
   kal_int32 phi;

   /** TTG gain*/
   kal_uint32 gain;

   /** TTG phase0 mode*/
   TDDTXDFE_TTG_MODE_E p0_mode;

   /** TTG phase1 mode*/
   TDDTXDFE_TTG_MODE_E p1_mode;

   /** 1st TTG tone DC value: i part*/
   kal_int32  dc_i;

   /** 1st TTG tone DC value: q part*/
   kal_int32  dc_q;

} TDDTXDFE_TTG_CTRL_T;

typedef struct
{
   /** CON0 SW mode */
   TDDTXDFE_SW_MODE_E mode;

   /** CON0 SW gain information */
   TDDTXDFE_SW_GAIN_INFO_E gain;

   /** CON0 SW theta_at */
   kal_int16 theta_at;

   /** CON1 SW RAT selection*/
   TDDTXDFE_SW_RAT_E rat_sel;

   /** CON1 FEC gain norm pout for TxDFE*/
   kal_int16 gain_pout;

   /** CON1 FEC detrough linear for ET*/
   kal_int16 dtr_lin;
   
} TDDTXDFE_SW_MODE_CFG_T;

typedef struct
{
    /**CON0, fdiq comp bit num*/
    kal_uint16 fpid_comp_en;
	
    /**CON1, mode tap seletion mode012*/
    kal_uint16 tap_num_mode012;
	
    /**CON1, mode tap seletion mode34*/
    kal_uint16 tap_num_mode34;	
	
}TDD_TXDFE_FDIQ_CON_T;



typedef struct
{
   /* RX IRR */
   MMRFC_RX_IRR_RESULT_T       rx_irr_hpm[MMRFC_ANT_NUM]; //3 
   MMRFC_RX_IRR_RESULT_T       rx_irr_lpm[MMRFC_ANT_NUM]; //3 

   /* RX DC */
   MMRFC_RX_DC_RESULT_T        rx_dc_hpm[MMRFC_RXDC_TIA_GAIN_STEPS][MMRFC_RXDC_PGA_GAIN_STEPS]; //3 
   MMRFC_RX_DC_RESULT_T        rx_dc_lpm[MMRFC_RXDC_TIA_GAIN_STEPS][MMRFC_RXDC_PGA_GAIN_STEPS]; //3 

   /* DET */
   /* Only FDIQ is dependent with sample rates, other redundent items need to be removed in NVRAM/share memory structure */
   MMRFC_DET_IQDNL_RESULT_T    det_iqdnl[MMRFC_DET_FE_GAIN_STEPS]; //2 
   MMRFC_DET_DC_RESULT_T       det_dc[MMRFC_DET_GAIN_STEPS+2]; //15 DET gain step

   kal_uint32                  det_coarse_dcoc_cw807; //CW807, V_TXCDCOC1[19:0]
   kal_uint32                  det_coarse_dcoc_cw808; //CW808, V_TXCDCOC2[19:0]

   kal_uint32                  tx_lo;            //CW714, {2'b00,V_TXLOCAP[6:0],V_TXLOIND,V_TXLOINBIAS[4:0],V_TXLOINBIAS[4:0]}
   kal_uint8                   tx_lo_ind;
   kal_uint8                   tx_lo_capcal_peak_cap; //CW714
   kal_uint8                   tx_lo_in_bias_hpm;     //CW714
   kal_uint8                   tx_lo_in_bias_lpm;     //CW714  

   /* TX RC */
   kal_int16                   tx_rc_lpf;
   kal_int16                   tx_rc_rcf;

   /* TX IQDC */
   /* TXIQ: G0, G9, G10, G12a, G14a, G12b, G14b       */
   /* TXDC: G0, G9, G10, G12a, G14a, G12b, G14b, G21  */
   /* freq_dep_phase_tx is temp output for FDIQ cal   */
   MMRFC_TX_IQDC_RESULT_T      tx_iqdc_lin[MMRFC_TX_PGA_SLICE_NUM+1]; //+1 only for DC with PGA-AUX
   MMRFC_TX_IQDC_RESULT_T      tx_iqdc_dpd[MMRFC_TX_PGA_SLICE_NUM+1]; //+1 only for DC with PGA-AUX
   MMRFC_TX_FD_FILT_RESULT_T   tx_fdiq[MMRFC_TX_PGA_SLICE_NUM+1];

   /* TX DNL */
   kal_int16                   tx_dnl_lin_pga_a[MMRFC_TX_DNL_PGA_A_SEQ_NUM]; //20 gain diff
   kal_int16                   tx_dnl_lin_pga_b[MMRFC_TX_DNL_PGA_B_SEQ_NUM]; //15 gain diff
   kal_int16                   tx_dnl_dpd_pga_a[MMRFC_TX_DNL_PGA_A_SEQ_NUM]; //20 gain diff
   kal_int16                   tx_dnl_dpd_pga_b[MMRFC_TX_DNL_PGA_B_SEQ_NUM]; //15 gain diff

   /* TX PGA Gain Step */
   kal_int16                   pga_gain_step[MMRFC_TX_PGA_GAIN_STEP_NUM];

   /* TX PGA Cap Tuning */
   kal_int16                   cap_tuning_pga_a;
   kal_int16                   cap_tuning_pga_b;
   
} MMRFC_3GTDD_RESULT_PER_BAND_T;

typedef struct
{
   MMRFC_3GTDD_RESULT_PER_BAND_T tds_result[2];
} MMRFC_3GTDD_RESULT_T;


void TL1D_MMRF_PowerOnCalibration(void);

extern kal_uint32*          tdsrfcalPocBufferTable              [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern kal_uint32           tdsrfcalPocBufferSizeTable          [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern MML1_RF_BSIMM_PORT_T tdsrfcalPocBufferDataPortSelTable   [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern MML1_MIPI_REG_RW_T   tdsrfcalPocBufferDataMipiCwTypeTable[/*MMPOC_BUFFER_TYPE_NUM_OF*/];

extern MMRFC_3GTDD_RESULT_T tdsResult;

extern void TL1D_MMRF_L1coreSHMUpdate2Local(void);
extern void TL1D_MMRF_L1CoreSHMDataInit(void);
extern void TL1D_RF_CUSTOM_Table_Update(void);
extern void TL1D_MMRF_L1coreSHMDataCacheFlush(void);
extern void TL1D_MMRF_RXK_FC_Config(void);
extern void TL1D_MMRF_RXIQ_Meas_Config(void);
extern void TL1D_MMRF_RXDC_Meas_Config(void);
extern void TL1D_MMRF_RXDFE_On_Config(kal_uint32 first_open);
extern void TL1D_MMRF_RXDFE_Off_Config(void);
extern void TL1D_MMRF_RXFDIQ_Comp_Config(kal_uint32 CtrlMode,kal_int32 tap_q,kal_int32 tap_i,MMRFC_XL1_BAND_NUM_E bandinfo);
extern void TL1D_MMRF_RXFIIQ_Comp_Config(kal_uint32 CtrlMode, kal_int32 phase, kal_int32 gain, MMRFC_XL1_BAND_NUM_E bandinfo);
extern void TL1D_MMRF_RXDC_Comp_Config(kal_uint32 CtrlMode, kal_uint32 dc_sel, kal_int32 dc_q, kal_int32 dc_i, MMRFC_XL1_BAND_NUM_E bandinfo);
extern void TL1D_MMRF_RXIQK_Strobe_Config(void);
extern void TL1D_RFCW_DUMP(void);
extern void TL1D_MMMRF_SRXCFG(MMRFC_XL1_BAND_NUM_E band);
extern void TL1D_MMRF_TXDFE_Set_Ttg_Config(TDDTXDFE_TTG_INDEX_E tone_idx, const TDDTXDFE_TTG_CTRL_T *p);
extern void TL1D_MMRF_TXDFE_Set_Sw_Mode_Config(const TDDTXDFE_SW_MODE_CFG_T *p );
extern void TL1D_MMRF_TXDAC_Rate_Config(kal_uint32 dac_rate);
extern void TL1D_MMRF_TXFDIQ_Comp_Config(TDD_TXDFE_FDIQ_CON_T *p, MMRFC_XL1_BAND_NUM_E bandinfo);
extern void TL1D_MMRF_TXFIIQ_Comp_Config(kal_uint32 coef_num, kal_int32 dccompvlaue, kal_int32 iqcompvlaue );
extern void TL1D_MMRF_TXCIM3_Ctrl_Config(kal_uint32 ctrlbit );
//extern void TL1D_MMRF_TXDFESWConfig(void);
extern void TL1D_MMRF_TX_Backoff_Config(kal_uint32 GainAdjValue, kal_uint32 GainAdjMode);
extern void TL1D_MMRF_TX_Anti_droop_Config(void);
extern void TL1D_MMRF_TX_Anti_droop_On_Off(kal_uint16 ctrl);
extern void TL1D_MMRF_RXDFE_Fdpm_Config(kal_uint16 fdpm_q_tap, kal_uint16 fdpm_i_tap, TDDRXDFE_FDPM_PARA_T* fdpm_coef);
extern kal_uint32 TL1D_MMRF_UpdateRuntimeHandler( kal_uint32 nvram_lid, kal_uint8 *data, kal_uint16 nvram_size );
extern void TL1D_RfSelfCalInvoke( void );
extern kal_uint16 TL1D_GetRfSelfCalTotalLidNum( void );
extern kal_uint16 TL1D_GetRfSelfCalResultSize( kal_uint16 lid_index);
extern kal_uint16 TL1D_GetRfSelfCalResult( kal_uint16 lid_index, kal_uint16 lid_size, kal_uint8 *dst);
extern kal_uint16 TL1D_SetRfSelfCalResult( kal_uint16 lid_index, kal_uint16 lid_size, kal_uint8 *src);
extern kal_uint16 TL1D_GetRfSelfCalString( kal_uint16 lid_index, kal_char *string_dst);

/** API for TAS*/
#ifdef __TAS_SUPPORT__
extern kal_bool TL1D_RF_TAS_Support(void);
extern void TL1D_RF_Force_TAS(kal_bool force_tas_enable, kal_uint8 tas_idx);
#else
#define TL1D_RF_TAS_Support      NULL
#define TL1D_RF_Force_TAS        NULL
#endif

#endif /* End of #ifndef _TL1D_MMRF_INTERFACE_H_ */

