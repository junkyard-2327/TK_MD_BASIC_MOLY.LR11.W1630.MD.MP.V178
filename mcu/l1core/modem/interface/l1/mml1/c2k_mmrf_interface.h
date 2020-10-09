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
 *   c2k_mmrf_interface.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   C2K interface to Multi-Mode Multi-RAT RF Central Control
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
 *
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _C2K_MMRF_INTERFACE_H_
#define  _C2K_MMRF_INTERFACE_H_

/*===============================================================================*/

#include "kal_general_types.h"

#include "mml1_rf_interface.h"
#include "mml1_rf_cal_interface.h"

#include "c2k_poc_data_struct_orionplus.h"
#include "el1d_mmrf_interface.h"

/*===============================================================================*/

/**********************************************************************************
* define
**********************************************************************************/

#define   IS_C2K_RFC_POC_TXLO_DETCDCOC_SUPPORT       1
#define   IS_C2K_RFC_POC_DET_IQDCDNL_SUPPORT         1
#define   IS_C2K_RFC_POC_TX_LPF_RCF_SUPPORT          1
#define   IS_C2K_RFC_POC_TX_FDIQ_SUPPORT             1 
#define   IS_C2K_RFC_POC_TX_FIIQ_DC_SUPPORT          1
#define   IS_C2K_RFC_POC_TX_GA_SUPPORT               0
#define   IS_C2K_RFC_POC_TX_PGA_CAP_TUNING_SUPPORT   1
#define   IS_C2K_RFC_POC_TX_DNL_SUPPORT              1
#define   IS_C2K_RFC_POC_TX_PGA_GAIN_STEP_SUPPORT    1
#define   IS_C2K_RFC_POC_TX_PGA_PHASE_STEP_SUPPORT   1
#define   IS_C2K_RFC_POC_RX_DC_SUPPORT               1
#define   IS_C2K_RFC_POC_RX_IIP2_SUPPORT             1
#define   IS_C2K_RFC_POC_RX_IQ_SUPPORT               1
#define   IS_C2K_RFC_POC_STX_DCC_SUPPORT             0

#if IS_C2K_RFC_POC_TXLO_DETCDCOC_SUPPORT
#define  C2K_POC_CAL_ORDER_LO_DET_CDCOC     MMRFC_POC_CAL_ORDER_LO_DET_CDCOC
#else
#define  C2K_POC_CAL_ORDER_LO_DET_CDCOC     0
#endif

#if IS_C2K_RFC_POC_DET_IQDCDNL_SUPPORT
#define  C2K_POC_CAL_ORDER_DET_IQDCDNL      MMRFC_POC_CAL_ORDER_DET_IQ_DC_DNL
#else
#define  C2K_POC_CAL_ORDER_DET_IQDCDNL      0
#endif

#if IS_C2K_RFC_POC_TX_LPF_RCF_SUPPORT
#define  C2K_POC_CAL_ORDER_TX_RCCAL         MMRFC_POC_CAL_ORDER_TX_RCCAL
#else
#define  C2K_POC_CAL_ORDER_TX_RCCAL         0
#endif

#if IS_C2K_RFC_POC_TX_FDIQ_SUPPORT
#define  C2K_POC_CAL_ORDER_TX_FD_IQ         MMRFC_POC_CAL_ORDER_TX_FD_IQ
#else
#define  C2K_POC_CAL_ORDER_TX_FD_IQ         0
#endif

#if IS_C2K_RFC_POC_TX_FIIQ_DC_SUPPORT
#define  C2K_POC_CAL_ORDER_TX_FI_IQ_DC      MMRFC_POC_CAL_ORDER_TX_FI_IQ_DC
#else
#define  C2K_POC_CAL_ORDER_TX_FI_IQ_DC      0
#endif

#if IS_C2K_RFC_POC_TX_GA_SUPPORT
#define  C2K_POC_CAL_ORDER_TX_GA            MMRFC_POC_CAL_ORDER_TX_GA
#else
#define  C2K_POC_CAL_ORDER_TX_GA            0
#endif

#if IS_C2K_RFC_POC_TX_PGA_CAP_TUNING_SUPPORT
#define  C2K_POC_CAL_ORDER_TX_CAP_TUNING    MMRFC_POC_CAL_ORDER_TX_CAP_TUNING
#else
#define  C2K_POC_CAL_ORDER_TX_CAP_TUNING    0
#endif

#if IS_C2K_RFC_POC_TX_DNL_SUPPORT
#define  C2K_POC_CAL_ORDER_TX_DNL           MMRFC_POC_CAL_ORDER_TX_DNL
#else
#define  C2K_POC_CAL_ORDER_TX_DNL           0
#endif

#if IS_C2K_RFC_POC_TX_PGA_GAIN_STEP_SUPPORT
#define  C2K_POC_CAL_ORDER_TX_PGA_AB_GAIN   MMRFC_POC_CAL_ORDER_TX_PGA_AB_GAIN
#else
#define  C2K_POC_CAL_ORDER_TX_PGA_AB_GAIN   0
#endif

#if IS_C2K_RFC_POC_TX_PGA_PHASE_STEP_SUPPORT
#define  C2K_POC_CAL_ORDER_TX_PGA_AB_PHASE  MMRFC_POC_CAL_ORDER_TX_PGA_AB_PHASE
#else
#define  C2K_POC_CAL_ORDER_TX_PGA_AB_PHASE  0
#endif

#if IS_C2K_RFC_POC_RX_DC_SUPPORT
#define  C2K_POC_CAL_ORDER_RX_DCOC          MMRFC_POC_CAL_ORDER_RX_DCOC
#else
#define  C2K_POC_CAL_ORDER_RX_DCOC          0
#endif

#if IS_C2K_RFC_POC_RX_IIP2_SUPPORT
#define  C2K_POC_CAL_ORDER_RX_IIP2          MMRFC_POC_CAL_ORDER_RX_IIP2
#else
#define  C2K_POC_CAL_ORDER_RX_IIP2          0
#endif

#if IS_C2K_RFC_POC_RX_IQ_SUPPORT
#define  C2K_POC_CAL_ORDER_RX_IQ            MMRFC_POC_CAL_ORDER_RX_IQ
#else
#define  C2K_POC_CAL_ORDER_RX_IQ            0
#endif

#if IS_C2K_RFC_POC_STX_DCC_SUPPORT
/*TODO: Add STX DCC Bitmap once ready*/
#else
#define  C2K_POC_CAL_ORDER_STX_DCC          0
#endif

#define DET_C2K_CAL_FE_MID_GAIN_IDX   0     //D0 for C2K DET calibration with FE middle gain
#define DET_C2K_CAL_FE_LOW_GAIN_IDX   1     //D1 for C2K DET calibration with FE low gain

/************************************************************************************
* enum
************************************************************************************/


/************************************************************************************
* typedef
************************************************************************************/
/** Structure Prototypes can be seen by other files**/

typedef struct
{
   MMRFC_C2K_BAND_NUM_E c2k_band;
   MMRFC_XL1_BAND_NUM_E xl1_band;
} C2K_XL1_Band;

typedef struct
{
   kal_uint8 c2k_band;
   kal_uint8 c2k_supBandIdx;
} C2KBandInfo;

typedef struct
{
   /* RX IRR */
   MMRFC_C2K_RX_IRR_RESULT_T       rx_irr_hpm[MMRFC_C2K_RX_IRR_COMP_ROUTE_MAX][MMRFC_C2K_ANT_NUM]; /*> 4route */
   MMRFC_C2K_RX_IRR_RESULT_T       rx_irr_lpm[MMRFC_C2K_RX_IRR_COMP_ROUTE_MAX][MMRFC_C2K_ANT_NUM]; /*> 4route */

   /* RX DC */
   MMRFC_C2K_RX_DC_HPM_RESULT_T    rx_dc_hpm[MMRFC_C2K_RX_DC_COMP_ROUTE_MAX][MMRFC_C2K_ANT_NUM]; /*> 4route */
   MMRFC_C2K_RX_DC_RESULT_T        rx_dc_lpm[MMRFC_C2K_RX_DC_COMP_ROUTE_MAX][MMRFC_C2K_ANT_NUM]; /*> 4route */
   MMRFC_C2K_RX_DC_HPM_RESULT_T    dfe_rx_dc_hpm[MMRFC_C2K_RX_DC_COMP_ROUTE_MAX][MMRFC_C2K_ANT_NUM]; /*> 4route */
   MMRFC_C2K_RX_DC_RESULT_T        dfe_rx_dc_lpm[MMRFC_C2K_RX_DC_COMP_ROUTE_MAX][MMRFC_C2K_ANT_NUM]; /*> 4route */

   /* RX IIP2 */
   /* CW473 for Rx path 1, CW482 for Rx path 2 */
   /* i_idx_opt->V_RX1_IIP2_IRESULTS[6:0], q_idx_opt->V_RX1_IIP2_QRESULTS[6:0] */
   MMRFC_C2K_IIP2_RESULT_T         rx_iip2[MMRFC_C2K_RX_IIP2_COMP_ROUTE_MAX];

   /* DET coarse DCOC */
   kal_uint32                  det_coarse_dcoc_cw807; /*> CW807, V_TXCDCOC1[19:0], CW811->CW807 */
   kal_uint32                  det_coarse_dcoc_cw808; /*> CW808, V_TXCDCOC2[19:0], CW812->CW808 */

   /* DET IQ imbalance and FE gain with Tx path forward signal */
   MMRFC_C2K_DET_IQDNL_RESULT_T    det_iqdnl_fwd[MMRFC_C2K_DET_FE_GAIN_STEPS];

   /* DET fine DC with Tx path forward signal */
   MMRFC_C2K_DET_DC_RESULT_T       det_dc_fwd[MMRFC_DET_GAIN_STEPS_DET_CAL]; /*> 17 DET gain step */

   /* DET IQ imbalance and FE gain with Tx path reverse signal */
   MMRFC_C2K_DET_IQDNL_RESULT_T    det_iqdnl_rev[MMRFC_C2K_DET_FE_GAIN_STEPS];

   /* DET fine DC with Tx path reverse signal */
   MMRFC_C2K_DET_DC_RESULT_T       det_dc_rev[MMRFC_DET_GAIN_STEPS_DET_CAL]; /*> 17 DET gain step */

   /* TX LO Cal */
   /*> CW714, {2'b00,V_TXLOCAP[6:0],V_TXLOIND,V_TXLOINBIAS[4:0],V_TXLOINBIAS[4:0]}*/
   kal_uint8                   tx_lo_ind;
   kal_uint8                   tx_lo_capcal_peak_cap; //CW714
   kal_uint8                   tx_lo_in_bias_hpm;     //CW714
   kal_uint8                   tx_lo_in_bias_lpm;     //CW714   

   /* TX RC */
   kal_int16                   tx_rc_lpf; /*> CW787, V_TXLPFCSEL[7:0] */
   kal_int16                   tx_rc_rcf; /*> CW793, V_TXRCFCSEL[6:0] */

   /* TX IQDC */
   /* TXIQ: G0, G9, G10, G12a, G14a, G12b, G14b, G22  */
   /* TXDC: G0, G9, G10, G12a, G14a, G12b, G14b, G22  */
   MMRFC_C2K_TX_IQDC_RESULT_T  tx_iqdc_lin[MMRFC_C2K_TX_PGA_SLICE_NUM+1]; /*>  +1 for PGA-AUX */

   /* TX DNL */
   kal_int16                   tx_dnl_lin_pga_a[MMRFC_C2K_TX_DNL_PGA_A_SEQ_NUM]; /*> 20 gain diff, S7.8 */
   kal_int16                   tx_dnl_lin_pga_b[MMRFC_C2K_TX_DNL_PGA_B_SEQ_NUM]; /*> 16 gain diff, S7.8 */

   /* TX PGA phase step */
   kal_int16                   tx_pga_phase_step; /*> Diff of B-A, S0.14 */

   /* TX PGA Gain Step */
   kal_int16                   pga_gain_step[MMRFC_C2K_TX_PGA_GAIN_STEP_SUBBAND_NUM][MMRFC_C2K_TX_PGA_GAIN_STEP_NUM]; /*> S7.8 */

   /* TX PGA Cap Tuning */
   kal_uint16                  cap_tuning_pga_a; /*> CW795, V_TX_BAL_CAPA_AACT[5:0] */
   kal_uint16                  cap_tuning_pga_b; /*> CW796, V_TX_BAL_CAPB_BACT[5:0] */

}MMRFC_C2K_POC_RESULT_PER_BAND_T;


/*===============================================================================*/
/*                     RF Calibration Result Structure                           */
/*     The structure is grouped from post-processing result. Some redundent      */
/*     items may need to be removed and excluded in shared memory or NVRAM.      */
/*===============================================================================*/


/************************************************************************************
*  Global Variables extern (Interface)
************************************************************************************/

extern HwdRfC2kPocDataBaseT C2K_POWER_ON_CALIBRATION_DATABASE;
extern MMRFC_C2K_RESULT_T C2K_POWER_ON_CALIBRATION_RESULT;
extern kal_uint32 C2K_FREQ_CENTER[2][C2K_BAND_CLASS_MAX];
extern C2K_XL1_Band c2k_xl1_bandMapTbl[C2K_BAND_CLASS_MAX];

/************************************************************************************
* Global Functions Prototype (Interface)
************************************************************************************/

void C2K_RF_UpdateDetResult(kal_uint8 band_idx, kal_uint32 cal_item_list_bitmap,MMRFC_C2K_POC_RESULT_PER_BAND_T* cal_result);
void C2K_RF_UpdateTxResult(MMRFC_XL1_BAND_NUM_E band, kal_uint8 band_idx, kal_uint8 subband_idx,kal_uint32 cal_item_list_bitmap,MMRFC_C2K_POC_RESULT_PER_BAND_T* cal_result);
void C2K_RF_UpdateRxResult(kal_uint8 band_idx, kal_uint32 cal_item_list_bitmap, MMRFC_C2K_POC_RESULT_PER_BAND_T* cal_result);
void C2K_MMRF_PowerOnCalibration( void );
void C2K_RF_GetRxIrrDcConfigTable( MMRFC_XL1_BAND_NUM_E band, MMRFC_RX_CAL_IRR_DC_CFG_T* irr_dc_cfg, kal_uint8 is_irr_cal );
void C2K_RF_GetRxIIP2ConfigTable( MMRFC_XL1_BAND_NUM_E band, MMRFC_RX_CAL_IIP2_CFG_T* iip2_cfg );
void getC2KBandInfoByXL1Band(MMRFC_XL1_BAND_NUM_E xL1band, C2KBandInfo* c2k_band_info);
MMRFC_XL1_BAND_NUM_E getXL1BandByC2KBand(MMRFC_C2K_BAND_NUM_E C2K_band);
void C2K_RF_CAL_Set_TX_CW_Rx_IIP2_CAL(MMRFC_TX_CAL_CFG_T *tx_cfg);

#endif /* End of #ifndef _C2K_MMRF_INTERFACE_H_ */

