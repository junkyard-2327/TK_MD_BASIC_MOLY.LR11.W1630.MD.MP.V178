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
 *   mml1_rf_global.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   Multi-Mode RF Central Global Define
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
 *
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
 *
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
 *
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

#ifndef  _MML1_RF_GLOBAL_H_
#define  _MML1_RF_GLOBAL_H_

/*===============================================================================*/
/* Since other RATs DRDI still stay in L1CORE, temp for build pass, todo later, Paul*/
#define MMRF_TK6291_DRDI_MOVE_TO_PCORE_TEMP4BUILDPASS 1


#include "kal_general_types.h"

#include "mmrf_cc_global.h"

#if MMRF_TK6291_DRDI_MOVE_TO_PCORE_TEMP4BUILDPASS
#include "mml1_mipi_public.h"
#endif
/*===============================================================================*/
#define MMRF_TK6291_TEMP4BUILDPASS                 1
/*===============================================================================*/

#if MMRF_TK6291_TEMP4BUILDPASS
/*===============================================================================*/
/* POC RFC related code should be removed in l1-core                             */
/* MMRF related struct should be move to modem/interface folder                  */
/*===============================================================================*/
#define LTE_RFD_MT6169RF_E1                      0x1
#define LTE_RFD_MT6169RF_E2                      0x2
#define LTE_RFD_MT6169RF_E3                      0xF //[Neil] Define 0xF to avoid the same value 0x3 used in MT6169_E3 to mislead MT6176_E3 chip ID readback into MT6169_E3 settings.

#define LTE_TARGET_SUPPORT_BAND_NUM             (21)
#define LTE_TARGET_MAX_SUPPORT_BAND_NUM         (21)

#define LTE_RFC_TXGA_NUM_CBW_CASE               (12)
#define LTE_RFC_TXGA_NUM_BANDWIDTH_CASE          (3)
#define LTE_RFC_TXGA_NUM_COMP_FILTER_TAP         (7)
#define LTE_RFC_TXGA_NUM_TEST_TONE               (6)
#define LTE_RFC_TXGA_NUM_SLOPE_RESULT           (LTE_RFC_TXGA_NUM_TEST_TONE - 1)

#define LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE     (16)
#define LTE_RFC_TXIQDCDNL_TXGAIN_TAB_SIZE       (30)
#define LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND   (LTE_TARGET_MAX_SUPPORT_BAND_NUM)
#define LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BANDWIDTH   (6)
#define LTE_RFC_CURRENT_NUM_OF_SUPPORTED_OTHER_RAT_BAND (6)

#define LTE_RFC_RXIQ_NUM_COMP_FILTER_TAP         (7)
#define LTE_RFC_RXIQ_NUM_TIA_CB_GAIN_STEPS       (4)
#define LTE_RFC_RXIQ_NUM_PGA_GAIN_STEPS          (6)

// Factory Mode Capability Multi-RAT Bitmap
#define MML1_NULL      0x00000000
#define MML1_GSM       0x00000001
#define MML1_WCDMA     0x00000002
#define MML1_TDSCDMA   0x00000004
#define MML1_FDDLTE    0x00000008
#define MML1_TDDLTE    0x00000010
#define MML1_CDMA2K    0x00000020

typedef struct
{
   kal_uint16 CBW;

   /* For frequency-domain compensation - only for LTE */
   kal_int16 txga_slope_result[LTE_RFC_TXGA_NUM_BANDWIDTH_CASE][LTE_RFC_TXGA_NUM_SLOPE_RESULT];

   /* Time-domain compensation filter tap */
   kal_int16  txga_comp_filter_tap[LTE_RFC_TXGA_NUM_CBW_CASE][LTE_RFC_TXGA_NUM_COMP_FILTER_TAP];
   kal_uint16 data_valid;

   /* For frequency-domain compensation - only for LTE */
   kal_int16 txga_tone_pwr[LTE_RFC_TXGA_NUM_BANDWIDTH_CASE][LTE_RFC_TXGA_NUM_TEST_TONE]; // in dB unit
   kal_uint16 txga_cal_freq[LTE_RFC_TXGA_NUM_BANDWIDTH_CASE][LTE_RFC_TXGA_NUM_TEST_TONE]; // in RB uint
   kal_uint16 rsv; // padding byets for 4-byte alignment
}RFC_TXGA_COMP_T;

typedef struct
{
	kal_int16 rxiq_gain_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BANDWIDTH];
	kal_int16 rxiq_phase_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BANDWIDTH];
	kal_int16 rxiq_filter_coef[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BANDWIDTH][LTE_RFC_RXIQ_NUM_COMP_FILTER_TAP]; /*Lagrange filter*/
}RFC_RXIQ_COMP_T;

typedef struct
{
	kal_int16 txiq_gain_mismatch_comp;
	kal_int16 txiq_phase_mismatch_comp;
	kal_int16 txiq_real_dc_comp;
	kal_int16 txiq_image_dc_comp;
}RFC_TXIQ_COMP_T;

typedef struct
{
   kal_uint32  poc_data_status;

   /* Band number storage of calibration data band index */
   kal_uint32 band_idx_to_band_num_table[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];

   /*RX IQ Gain, phase mismatch for each band*/
   RFC_RXIQ_COMP_T rx1iq_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];
   RFC_RXIQ_COMP_T rx2iq_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];

   /*RX DCOC for each band*/
   kal_int16  rx1iq_re_dc[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_RXIQ_NUM_TIA_CB_GAIN_STEPS][LTE_RFC_RXIQ_NUM_PGA_GAIN_STEPS];
   kal_int16  rx1iq_im_dc[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_RXIQ_NUM_TIA_CB_GAIN_STEPS][LTE_RFC_RXIQ_NUM_PGA_GAIN_STEPS];
   kal_int16  rx2iq_re_dc[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_RXIQ_NUM_TIA_CB_GAIN_STEPS][LTE_RFC_RXIQ_NUM_PGA_GAIN_STEPS];
   kal_int16  rx2iq_im_dc[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_RXIQ_NUM_TIA_CB_GAIN_STEPS][LTE_RFC_RXIQ_NUM_PGA_GAIN_STEPS];

   /*DET IQ Gain,phase mismatch & DC for each band*/
   kal_int16  detiq_gain_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE];
   kal_int16  detiq_phase_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE];
   kal_int16  detiq_real_dc_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE];
   kal_int16  detiq_image_dc_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE];

   /* DET DNL (FE + PGA gain) for each band */
   kal_int16   det_gain_table[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE];

   /* tx_rcf_csel[0]: C_SEL for C value = b11, tx_rcf_csel[0]: C_SEL for C value = b00 */
   kal_int16 tx_rcf_csel[2];

   /*TX IQ Gain, phase mismatch & DC for each band*/
   RFC_TXIQ_COMP_T txiq_gain_phase_dc_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_TXIQDCDNL_TXGAIN_TAB_SIZE];

   /* TX DNL for each band */
   kal_int16 tx_gain_table[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_TXIQDCDNL_TXGAIN_TAB_SIZE];

   /* TX GA compensation data for each band */
   RFC_TXGA_COMP_T tx_ga_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];

   /* det_coarse_dcoc[0]: RF CW data for TXDET_CDCOC_I1_M, TXDET_CDCOC_Q1_M, TXDET_CDCOC_I2_M, TXDET_CDCOC_Q2_M */
   /* det_coarse_dcoc[1]: RF CW data for TXDET_CDCOC_I3_M, TXDET_CDCOC_Q3_M, TXDET_CDCOC_I4_M, TXDET_CDCOC_Q4_M */
   /* CW address is included in the data */
   kal_uint32 det_coarse_dcoc[2];

   /* DET FE DNL for each band
    * det_fe_gain_table[][0]: DET FE Middle gain mode, det_fe_gain_table[][0]: DET FE Low gain mode
    */
   kal_uint32  det_fe_gain_table[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];

   /* Only for 3G - 5th gain step of Tx IQ imbalance calibration result for each band */
   kal_int32 txiq_gain_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];
   kal_int32 txiq_phase_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];

}RFC_DATABASE_T;

#define MML1_CUSTOM_GPIO_MAX_SET_NUMS             (1024)    /* Maximum 64 set for GPIO 6 Pins */  

/* data structure to save custom parameters of MML1 custom folder (DO NOT MODIFY) */
typedef struct
{
   kal_uint8  mml1_custom_debug_enable;                   //= MML1_CUSTOM_DEBUG_ENABLE;
   kal_uint8  mml1_custom_gpio_set_nums;                  //= MML1_CUSTOM_GPIO_SET_NUMS;            
   kal_uint8  mml1_custom_adc_set_nums;                   //= MML1_CUSTOM_ADC_SET_NUMS;             
   kal_uint8  mml1_custom_nvram_barcode_set_nums;         //= MML1_CUSTOM_BARCODE_SET_NUMS;   
   kal_uint8  mml1_custom_gpio_nums_in_calc;              //= MML1_CUSTOM_GPIO_NUMS_IN_CALC;
   kal_uint8  mml1_custom_ADC_nums_in_calc;               //= MML1_CUSTOM_ADC_NUMS_IN_CALC;
   kal_uint8  mml1_custom_barcode_nums_in_calc;           //= MML1_CUSTOM_BARCODE_NUMS_IN_CALC;
   kal_uint8  mml1_custom_first_index;                    //= MML1_CUSTOM_FIRST_INDEX;
   kal_uint8  mml1_custom_second_index;                   //= MML1_CUSTOM_SECOND_INDEX;
   kal_uint8  mml1_custom_third_index;                    //= MML1_CUSTOM_THIRD_INDEX;
   kal_uint8  mml1_custom_first_index_base;               //= MML1_CUSTOM_FIRST_INDEX_BASE;
   kal_uint8  mml1_custom_gpio_num_of_detect_pins_in_use; //= MML1_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE;
   kal_uint8  mml1_custom_adc_level_total;                //= MML1_CUSTOM_ADC_LEVEL_TOTAL;
   kal_uint8  mml1_custom_barcode_read_digit_num;         //= MML1_CUSTOM_BARCODE_READ_DIGIT_NUM;
   kal_uint8  mml1_custom_barcode_digit_value_1;          //= MML1_CUSTOM_BARCODE_DIGIT_VALUE_1;
   kal_uint8  mml1_custom_barcode_digit_value_2;          //= MML1_CUSTOM_BARCODE_DIGIT_VALUE_2;
   kal_uint8  mml1_custom_barcode_digit_value_3;          //= MML1_CUSTOM_BARCODE_DIGIT_VALUE_3;
   kal_uint8  mml1_custom_adc_calibrate_enable;           //= MML1_CUSTOM_ADC_CALIBRATE_ENABLE;
   kal_uint8  mml1_custom_adc_bits;                       //= MML1_CUSTOM_ADC_BITS;
   kal_uint16 mml1_custom_adc_meas_count_2_order;         //= MML1_CUSTOM_ADC_MEAS_COUNT_2_ORDER;
   kal_uint16 mml1_custom_total_set_nums;                 //= MML1_CUSTOM_TOTAL_SET_NUMS;
   kal_uint32 mml1_custom_adc_max_input_voltage;          //= MML1_CUSTOM_ADC_MAX_INPUT_VOLTAGE;
}Mml1RfDrdiCustomParam;

#endif /* End of MMRF_TK6291_TEMP4BUILDPASS */


#if MMRF_TK6291_DRDI_MOVE_TO_PCORE_TEMP4BUILDPASS
typedef struct
{
   const MML1_MIPI_INITIAL_CW_T          *initTable_p;
   const MML1_MIPI_USID_CHANGE_T         *changeUsidTable_p;
   MML1_MIPI_CHECK_HW_T            *checkHwTable_p;
}Mml1CustomDynamicInitMipiData;

typedef struct
{
   const MML1_MIPI_INITIAL_CW_T          *initTable_p;
}Mml1CustomDynamicInitEtMipiData;

typedef struct
{
   sMML1_RF_CUSTOM_INPUT_DATA   rfInputData;
}Mml1CustomDynamicInitRFData;

#endif

typedef enum
{
   MML1_RF_MT6169  = 0x0001,
   MML1_RF_MT6166  = 0x0002,
   MML1_RF_MT6165  = 0x0003,
   MML1_RF_MT6176  = 0x0004,
   MML1_RF_MAX     = 0xFFFE,
}MML1_RF_CHIP_T;

#if defined(__SAR_TX_POWER_BACKOFF_SUPPORT__)
typedef struct
{
   const MML1_SENSOR_INFO_T              *sarSensorInfo_p;
}Mml1CustomDynamicSarSensorData;
#endif

#if defined(__TX_POWER_OFFSET_SUPPORT__) || defined(__SAR_TX_POWER_BACKOFF_SUPPORT__)
typedef struct
{
   const MML1_RF_TX_PWR_OFFSET_T          sarDataInfo;
}Mml1CustomDynamicSarData;
#endif

/*===============================================================================*/

// Multi-rat share bit information
kal_uint32 MML1_RF_GetMultiRatRfSharingBitmap( MML1_RF_CHIP_T mml1_rfid );

#endif /* End of #ifndef _MML1_RF_PUBLIC_H_ */

