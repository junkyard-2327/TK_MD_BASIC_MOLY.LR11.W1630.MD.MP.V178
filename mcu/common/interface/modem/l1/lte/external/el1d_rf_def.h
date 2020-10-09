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
 * @addtogroup EL1D_RF_DEF
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @file       el1d_rf_def.h
 * @author     LY Chen (MTK04356)
 * @date       2014.12.16
 * @brief      EL1D RF Definition
 * @details    Definition/Constant for RF capability
 ******************************************************************************/

#ifndef __EL1D_RF_DEF_H__
#define __EL1D_RF_DEF_H__

/*******************************************************************************
 * #include
 ******************************************************************************/
#if defined (__TX_POWER_OFFSET_SUPPORT__) || defined (__SAR_TX_POWER_BACKOFF_SUPPORT__)
#include "mmrf_cc_global.h"            // for TPO_MML1_TABLE_NUM
#endif

//#if define(__BAND_EXTENSION_SUPPORT__)
#include "el1d_rf_cid.h"               // for Band extension
//#endif

/*******************************************************************************
 * #define
 ******************************************************************************/
/** LTE Common definition */
#if IS_4G_BAND_EXTENSION_SUPPORT
#define LTE_BIT_MASK_BUFFER_SIZE                       (96/32) // support band1 ~ 44 + band66, need 3 set buffer
#else
#define LTE_BIT_MASK_BUFFER_SIZE                       (64/32) // support 64 band at max
#endif

#define LTE_SPEC_SUPPORT_BAND_NUM                      (25)
#define LTE_TARGET_MAX_SUPPORT_BAND_NUM                (21)

#if IS_4G_BAND_EXTENSION_SUPPORT
#define LTE_SUPPORT_BAND_GROUP_A_NUM                   (44 + 1) // BandNone + Band1 ~ 44
#define LTE_SUPPORT_BAND_GROUP_B_NUM                   (1)      // new support band will be added in the group B: Band66
#define LTE_MAX_SUPPORT_BAND_NUM                       (LTE_SUPPORT_BAND_GROUP_A_NUM + LTE_SUPPORT_BAND_GROUP_B_NUM) // total support band number
#else
#define LTE_MAX_SUPPORT_BAND_NUM                       (44 + 1) // LTEBandNone
#endif

#define LTE_TARGET_MAX_SUPPORT_CA_BAND_NUM             (38)
#define LTE_MAX_SUPPORT_FE_ROUTE_NUM                   (LTE_TARGET_MAX_SUPPORT_BAND_NUM + LTE_TARGET_MAX_SUPPORT_CA_BAND_NUM)

#define LTE_MAX_RX_TYPE1_COMP_ROUTE_NUM                (64)
#define LTE_MAX_RX_TYPE2_COMP_ROUTE_NUM                (8)
#define LTE_MAX_TX_COMP_ROUTE_NUM                      (LTE_TARGET_MAX_SUPPORT_BAND_NUM)

/** LTE CA Configuration */
#define LTE_CA_CFG_NUM_MAX                             (128)
#define LTE_CA_SIMUL_BAND_MAX                          (2) ///< max simultaneous bands, for TK6291, is 2
#define LTE_CA_MAX_CC_NUM                              (2)
#define LTE_CA_MAX_DL_CC_NUM                           (2)
#define LTE_CA_MAX_UL_CC_NUM                           (1)

/** RF related definition */
#define LNA_MODE_NUM                                   (6)  // move to ?
#define LNA_MODE_LPM_NUM                               (1)
#define LTE_PA_HIGH_MODE                               (0)
#define LTE_PA_MID_MODE                                (1)
#define LTE_PA_LOW_MODE                                (2)
#define LTE_MAX_NUM_PA_CONTROL_LEVEL                   (8)
#define LTE_PRF_THR_SIGNED_BIT_SHIFT                   (14)
#define LTE_PRF_THR_INTEGER_BIT_SHIFT                  (8)
#define LTE_POWER_CLASS                                (3)
#define LTE_FREQ_IN_RB_INTEGER_BIT_SHIFT               (5)
#define LTE_PA_SECTION_MAX_THRESHOLD                   (6)
#define RESOURCE_BLOCK_SPAN_IN_HZ                      (180000)
#define LTE_PA_SECTION_ADDITIONAL_CNTRL_NUM            (7)
#define LTE_PA_CPL_GAIN_SLOPE_RESOLUTION_FACTOR        (1024)
#define TEMP_COMPENSATE_STEP                           (4) // i.e. 0.125 dB = 4/32 dB

/** LTE RF MIPI related definition */
#define LTE_MIPI_RX_EVENT_NUM                          (25)
#define LTE_MIPI_RX_DATA_NUM                           (50)

#define LTE_MIPI_TX_EVENT_NUM                          (25)
#define LTE_MIPI_TX_DATA_NUM                           (60)

#define LTE_MIPI_TPC_EVENT_NUM                         (6)
#define LTE_MIPI_TPC_DATA_NUM                          (6)

#define LTE_MIPI_SUBBAND_NUM                           (10)
#define LTE_MIPI_SUBBAND_NUM_PER_DATA                  (5)

#define LTE_MIPI_TPC_SECTION_DATA_NUM                  (5)
#define LTE_MIPI_TPC_SECTION_NUM                       (8 + 1)

/** LTE RF MIPI ANT tuner related definition */
#define LTE_MIPI_ANT_EVENT_NUM                         (25)
#define LTE_MIPI_ANT_DATA_NUM                          (50)

/* MIPI interface for DAT feature definition*/
#define LTE_MIPI_DAT_EVENT_NUM                         (10)
#define LTE_MIPI_DAT_DATA_NUM                          (20)

/** RF Calibration related definition */
#define CAL_TEMP_SECTION_LTE                           (8)
#define CAL_EARFCN_SECTION_LTE                         (15)
#define CAL_DL_EARFCN_SECTION_LTE                      (15)

#define LTE_RFC_NUM_OF_CAL_CODE_FOR_POC                (6)
#define LTE_RFC_NUM_OF_CAL_CODE_FOR_RUNTIME_CAL        (3)
#define LTE_RFC_MAX_NUM_OF_CAL_CODE                    (8)

#define LTE_RFC_RXIQ_CAL_CODE                          (0)
#define LTE_RFC_RXDCOC_CAL_CODE                        (1)
#define LTE_RFC_DETIQDC_DNL_CAL_CODE                   (2)
#define LTE_RFC_TXRC_CAL_CODE                          (3)
#define LTE_RFC_TXGA_CAL_CODE                          (4)
#define LTE_RFC_TXIQDC_DNL_CAL_CODE                    (5)
#define LTE_RFC_CAL_CODE_NONE                          (0)

#if (LTE_RFC_NUM_OF_CAL_CODE_FOR_POC > LTE_RFC_MAX_NUM_OF_CAL_CODE)  || (LTE_RFC_NUM_OF_CAL_CODE_FOR_RUNTIME_CAL > LTE_RFC_MAX_NUM_OF_CAL_CODE)
#error "Number of cal. code exceeds its maximum value"
#endif

#define LTE_RFC_RXDCOC_BAND_DIMENSION                  (3)
#define LTE_RFC_RXDCOC_PATH_NUM                        (2)
#define LTE_RFC_RXDCOC_BW_NUM                          (6)
#define LTE_RFC_RXDCOC_LNA_NUM                         (7)
#define LTE_RFC_RXDCOC_GAIN_STEPS_NUM                  (32)



/** RF FE Feature related definition */
// Spilt band Feature
#define LTE_ERF_SPLIT_BAND                              5 //How many bands need to split? Band28/Band41/Reserved
#define LTE_ERF_MAX_SPLIT_PART                          3 //Split to at most 3 parts
                                                          //The 1st data are stored in ERF_RX_(P/S)DATABASE and ERF_TX_(P/S)DATABASE
                                                          //The 2nd and 3rd data are stored in ERF_SPLIT_RFDATABASE
#define LTE_ERF_SPLIT_PART_NUM                         (LTE_ERF_MAX_SPLIT_PART - 1) //Split to at most 3 parts, but database uses 3-1=2 parts
// Partial Band Feature
#define LTE_PARTIAL_BAND_SUPPORT_NUM                   (5)
// Bypass Mode Feature
#define LTE_BYPASS_MAX_SUPPORT_BAND_NUM                 5

// HRM Mode Feature
#define LTE_TX_HRM_MAX_SUPPORT_BAND_NUM                 5


// Transmit Antenna Selection Feature
#define LTE_ERF_TAS_SET_NUM                             15 //How many selection sets for each band
#define LTE_ERF_TAS_BAND_NUM                           (LTE_TARGET_MAX_SUPPORT_BAND_NUM)
#define LTE_ERF_TAS_TOTAL_NUM                          (LTE_ERF_TAS_BAND_NUM*LTE_ERF_TAS_SET_NUM)

#define LTE_EL1_ENB_SM                                  1    //          Enable of antenna-switch metric function
#define LTE_EL1_TAS_N_MS_J_HYS                          4    //MS,       Hysteresis duration control for leaving normal state
#define LTE_EL1_TAS_N_MS_SM_FADEOUT                     1600 //MS,       The timer duration for antenna-switching metric fadeout protection
#define LTE_EL1_TAS_PHI_BOUND                           8    //dB,       Up/low bound for applying antenna-switching metric as threshold
#define LTE_EL1_TAS_PHI_01_DEFAULT                      0    //dB,       Antenna-switching metric default value from ant. 0 to ant. 1
#define LTE_EL1_TAS_PHI_10_DEFAULT                      0    //dB,       Antenna-switching metric default value from ant. 1 to ant. 0
#define LTE_EL1_ENB_DB                                  1    //          Enable of dynamic barrier control function
#define LTE_EL1_TAS_DELTA_DB_FAIL_STEP_RSRP             4    //dB,       The increased amount for RSRP barrier for a fail pre-switch
#define LTE_EL1_TAS_DELTA_DB_FAIL_STEP_TXP              2    //dB,       The increased amount for TX power barrier for a fail pre-switch
#define LTE_EL1_TAS_N_MS_DB_RELAX                       128  //MS,       The timer duration to relax the dynamic barrier
#define LTE_EL1_TAS_DELTA_DB_TO_STEP                    1    //dB,       RSRP/TXP: The decreased barrier when per timer is reached
#define LTE_EL1_TAS_DELTA_DB_BOUND_RSRP                 9    //dB,       The upper bound of the extra-threshold Delta_RSRP_DB
#define LTE_EL1_TAS_DELTA_DB_BOUND_TXP                  6    //dB,       The upper bound of the extra-threshold Delta_TXP_DB
#define LTE_EL1_TAS_RSRP_DIFF_THD                       4    //dB,       RSRP difference threshold to trigger TAS, defined as the RSRP value difference from diversity to main antennas
#define LTE_EL1_TAS_RSRP_DIFF_THD_TXP                   4
#define LTE_EL1_TAS_RSRP_DIFF_THD_CB                    0
#define LTE_EL1_RSRP_THD_CONNECT_EN                     1    //          RSRP_diff_thd_xxx are connected or not
#define LTE_EL1_TAS_RSRP_CB_DROP_THD                    -6   //dB,       RSRP drop threshold to trigger TAS when check back, defined as the RSRP value difference from current value to its previous one
#define LTE_EL1_TAS_TXP_CB_INC_THD                      8    //dB,       Transmit power (TXP) increase threshold to trigger TAS when check back, defined as the TXP value difference from current value to its previous one
#define LTE_EL1_TAS_N_MS_CB                             16   //MS,       The look/check back period (for RSRP and TXP change monitoring), using measurement slot (MS) as the unit
#define LTE_EL1_TAS_HTP_LEVEL                           -3   //dB,       The high transmit power (HTP) level, defined as the ratio (in dB) to UE's maximum transmit power
#define LTE_EL1_TAS_HTP_RATIO_THD                       50   //%,        A HTP is recognized when the percentage using TXP (within a measurement slot) greater than HTP_level is higher than the ratio threshold
#define LTE_EL1_TAS_TXP_INC_THD_SB                      4    //dB,       TXP increase threshold when switch to the diversity antenna, for which exceeding the threshold would be recognized as a fail antenna switch
#define LTE_EL1_TAS_N_MS_SB                             16   //MS,       The monitoring duration for switch-back check, using measurement slot (MS) as the unit

//HPUE feature
#define LTE_HPUE_BAND_NUM                              (3)

// Tx Power Offset feature
#if defined (__TX_POWER_OFFSET_SUPPORT__) || defined (__SAR_TX_POWER_BACKOFF_SUPPORT__)
#define TPO_4G_TABLE_NUM                                TPO_MML1_TABLE_NUM    // number of Tx power offset data table
#endif

/* APCDAC Calculation */
#define LTE_APCDAC_MAX_VOLTAGE                          28    //2.8V for APC maximum voltage
#define LTE_APCDAC_TOTAL_STEPS                          1023  //APCDAC values: 0~1023

/* AMPR */
#define LTE_AMPR_TABLE_ALL_SIZE                        (LTE_MAX_SUPPORT_BAND_NUM+4)        //Additional 2 settings for Band23, additional 1 setting for band26, and additional 1 for LTE_AMPR_NS_DEFAULT, so add 4 here
#define LTE_AMPR_TABLE_SIZE                            (LTE_TARGET_MAX_SUPPORT_BAND_NUM+4) //Additional 2 settings for Band23, additional 1 setting for band26, and additional 1 for LTE_AMPR_NS_DEFAULT, so add 4 here

/* ET feature */
#define LTE_ET_TX_MAX_EVENT_NUM                  6
#define LTE_ET_TX_MAX_DATA_NUM                   15
	
#define LTE_ET_TPC_MAX_EVENT_NUM                 5
#define LTE_ET_TPC_MAX_DATA_NUM                  15

#define LTE_ET_LOOKUP_VPA_MAX_DATA_NUM           10

#define LTE_ET_BW_SWITCH_MAX_DATA_NUM            5

#define LTE_ET_MODE_SETTING_MAX_DATA_NUM         5

// LTE supported band maximum number including bypass and HRM
#define LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM              ( LTE_TARGET_MAX_SUPPORT_BAND_NUM + LTE_BYPASS_MAX_SUPPORT_BAND_NUM + LTE_TX_HRM_MAX_SUPPORT_BAND_NUM )


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


#endif /*__EL1D_RF_DEF_H__*/

/* Doxygen Group End ***************************************************//**@}*/
