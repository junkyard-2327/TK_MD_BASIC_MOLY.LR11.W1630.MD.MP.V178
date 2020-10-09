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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   l1d_public.h
 *
 * Project:
 * --------
 *   TK6291 Project
 *
 * Description:
 * ------------
 *   The structure definition of L1 calibration data
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef L1D_PUBLIC_H
#define L1D_PUBLIC_H

#include "l1d_cid.h"
#include "l1cal.h"
#include "l1d_rf_common.h"
#include "l1_types_public.h"


/* ------------------------------------------------------------------------- */

/* moved from l1d_data_l1core.h */
#if IS_AST_B2S_SUPPORT
#define  TQ_AFC_READY                        245
#define  TQ_AFC_READY_RX                     213
#else
#define  TQ_AFC_READY                        256
#define  TQ_AFC_READY_RX                     TQ_AFC_READY
#endif

#if L1D_PM_ENHANCE
#define  TQ_PM_WIN_OFF_MARGIN                8
#endif

/* ------------------------------------------------------------------------- */
/* moved from l1d_custom_rf.h */
#define    SECONDS2FRAME(n)                     ((int)((n)*1000/4.615))
#define    VOLT2UVOLT(n)                        ((int)((n)*1000000))
#define    TEMP2MTEMP(n)                        ((int)((n)*1000))

/* ------------------------------------------------------------------------- */
   /* !!important: please align the setting in L1_const.h */
#define RSSI_RESOLUTION_BITS              3 /* 0.125 dB resolution */
#define RSSI_FACTOR              (1<<RSSI_RESOLUTION_BITS)

// moved from m12190_l1core.h
#ifndef _L1D_DATA_L1CORE_H_
#define  PWRRES_BIT                          RSSI_RESOLUTION_BITS
#define  PWRRES                              RSSI_FACTOR
#endif

#define  GAINLOSS( n )           ((signed char)((n)*PWRRES))
#define  WEIGHT(n)               ((unsigned short)((n)*(1<<14)))
#define  TABLE_END               -1
/* ------------------------------------------------------------------------- */
/*  moved from m12197_l1core.h */
#define RFDEF       0xABCD
#define RFDEF_short 0xAB

/* ------------------------------------------------------------------------- */

#if defined(__PCORE__)
const extern intx  afc_inv_slope;
const extern int16 afc_dac_default;
#elif defined(__L1CORE__)
extern intx  afc_inv_slope;
extern int16 afc_dac_default;
#endif
extern const int16 afc_dac_initial;

#if defined(__PCORE__)
const extern long  XO_CapID;
#elif defined(__L1CORE__)
extern long	XO_CapID;
#endif

#if defined(__PCORE__)
extern sAGCGAINOFFSET* AGC_PATHLOSS_TABLE[FrequencyBandCount];
#elif defined(__L1CORE__)
extern sAGCGAINOFFSET* AGC_PATHLOSS_TABLE[FrequencyBandCount];
#endif

#if defined(__PCORE__)
extern sLNAGAINOFFSET* LNA_PATHLOSS_TABLE[FrequencyBandCount];
#elif defined(__L1CORE__)
extern sLNAGAINOFFSET* LNA_PATHLOSS_TABLE[FrequencyBandCount];
#endif

#if defined(__PCORE__)
extern sRAMPDATA* RampData[FrequencyBandCount];
#elif defined(__L1CORE__)
extern sRAMPDATA* RampData[FrequencyBandCount];
#endif

#if IS_EPSK_TX_SUPPORT
   #if defined(__PCORE__)
extern sRAMPDATA* RampData_EPSK[FrequencyBandCount];
   #elif defined(__L1CORE__)
extern sRAMPDATA* RampData_EPSK[FrequencyBandCount];
   #endif
#endif

#if defined(__PCORE__)
extern sMIDRAMPDATA*  InterRampData[FrequencyBandCount];
#elif defined(__L1CORE__)
extern sMIDRAMPDATA*  InterRampData[FrequencyBandCount];
#endif

#if IS_EPSK_TX_SUPPORT
   #if defined(__PCORE__)
extern sMIDRAMPDATA** EPSK_InterRampData[5];
   #elif defined(__L1CORE__)
extern sMIDRAMPDATA** EPSK_InterRampData[5];
   #endif
#endif

#if defined(__PCORE__)
extern sBBTXParameters BBTXParameters;
#elif defined(__L1CORE__)
extern sBBTXParameters BBTXParameters;
#endif

#if IS_GPRS
   #if defined(__PCORE__)
extern sTX_POWER_ROLLBACK* tx_power_rollback_gmsk[FrequencyBandCount];
   #elif defined(__L1CORE__)
extern sTX_POWER_ROLLBACK* tx_power_rollback_gmsk[FrequencyBandCount];
   #endif
   #if IS_EGPRS
      #if defined(__PCORE__)
extern sTX_POWER_ROLLBACK* tx_power_rollback_epsk[FrequencyBandCount];
      #elif defined(__L1CORE__)
extern sTX_POWER_ROLLBACK* tx_power_rollback_epsk[FrequencyBandCount];
      #endif
   #endif
#endif

#if IS_TX_POWER_CONTROL_SUPPORT
   #if defined(__PCORE__)
const extern       char       is_txpc_calibrated;
      #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
extern sTXPC_ADCDATA*   TXADC_Data[FrequencyBandCount];
extern sTXPC_TEMPDATA*  TXTEMP_Data[FrequencyBandCount];
         #if IS_EPSK_TX_SUPPORT
extern sTXPC_ADCDATA*   TXADC_Data_EPSK[FrequencyBandCount];
extern sTXPC_TEMPDATA*  TXTEMP_Data_EPSK[FrequencyBandCount];
         #endif
      #endif   /* IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT */
      #if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
const extern short            ref_temperature;
      #endif
   #elif defined(__L1CORE__)
extern		char	   is_txpc_calibrated;
      #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
extern sTXPC_ADCDATA*   TXADC_Data[FrequencyBandCount];
extern sTXPC_TEMPDATA*  TXTEMP_Data[FrequencyBandCount];
         #if IS_EPSK_TX_SUPPORT
extern sTXPC_ADCDATA*   TXADC_Data_EPSK[FrequencyBandCount];
extern sTXPC_TEMPDATA*  TXTEMP_Data_EPSK[FrequencyBandCount];
         #endif
      #endif   /* IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT */
      #if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
extern short 		   ref_temperature;
      #endif
   #endif
#endif      /* IS_TX_POWER_CONTROL_SUPPORT */

#if defined(__PCORE__)
extern const sTXPC_TEMPDATA TEMP_DAC_SetDefault;
#elif defined(__L1CORE__)
extern sTXPC_TEMPDATA TEMP_DAC;
#endif

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
   #if defined(__PCORE__)
extern sL1D_RF_CUSTOM_INPUT_DATA l1d_rf_custom_input_data;
   #elif defined(__L1CORE__)
extern sL1D_RF_CUSTOM_INPUT_DATA l1d_rf_custom_input_data;
   #endif
#endif

#if defined(__PCORE__)
const extern sTXGAIN_RFDATA* GAIN_RF_TABLE[FrequencyBandCount];
#elif defined(__L1CORE__)
extern sTXGAIN_RFDATA* GAIN_RF_TABLE[FrequencyBandCount];
#endif

#if IS_MIPI_SUPPORT
   #if defined(__PCORE__)
extern sGGE_MIPI_CTRL_TABLE_BAND*          GGE_MIPI_CTRL_TABLE[FrequencyBandCount]; 
   #elif defined(__L1CORE__)
      #if IS_2G_DAT_SUPPORT
extern sGGE_DAT_MIPI_RTXCTRL_TABLE*        GGE_DAT_MIPI_CTRL_TABLE[FrequencyBandCount][L1D_DAT_STATE_NUM];
      #endif 
extern sGGE_MIPI_CTRL_TABLE_BAND*          GGE_MIPI_CTRL_TABLE[FrequencyBandCount];
extern sGGE_MIPIEVENT*                     GGE_MIPI_CTRL_TABLE_RX_EVENT[FrequencyBandCount];
extern sGGE_MIPIEVENT*                     GGE_MIPI_CTRL_TABLE_TX_EVENT[FrequencyBandCount];
extern sGGE_MIPIEVENT*                     GGE_MIPI_CTRL_TABLE_TXMID_EVENT[FrequencyBandCount];
extern sGGE_MIPIDATA_SUBBAND*              GGE_MIPI_CTRL_TABLE_RX_DATA[FrequencyBandCount];
extern sGGE_MIPIDATA_SUBBAND*              GGE_MIPI_CTRL_TABLE_TX_DATA[FrequencyBandCount];
extern sGGE_MIPIPADATA*                    GGE_MIPI_CTRL_TABLE_PA_DATA[FrequencyBandCount];
extern sGGE_MIPIDATA_SUBBAND*              GGE_MIPI_CTRL_TABLE_TXMID_DATA[FrequencyBandCount];
   #endif
#endif

#if IS_TX_POWER_OFFSET_SUPPORT || IS_SAR_TX_POWER_BACKOFF_SUPPORT
   #if defined(__PCORE__)
extern sTX_POWER_OFFSET*  Tx_Power_Offset_GMSK[FrequencyBandCount];
extern sTX_POWER_OFFSET*  Tx_Power_Offset_EPSK[FrequencyBandCount];
   #elif defined(__L1CORE__)
extern sTX_POWER_OFFSET*  Tx_Power_Offset_GMSK[FrequencyBandCount];
extern sTX_POWER_OFFSET*  Tx_Power_Offset_EPSK[FrequencyBandCount];
   #endif
#endif

#if (IS_2G_TAS_SUPPORT||IS_2G_TAS_FOR_C2K_ONOFF_SUPPORT)
#define L1D_TAS_PIN_NULL                  -1                 // Do not modify this define
   #if defined(__PCORE__)
extern sL1_TAS_CUSTOM_PARAMS  L1_TAS_Custom_Params;
extern sL1_TAS_CUSTOM_PDATA   L1_TAS_Custom_PData;
      #if  defined(__TAS_ANTENNA_IDX_ON_TEST_SIM__)
extern sL1_TAS_INIT_ANT_PARAMS L1_TAS_Init_Ant_Params;
      #endif
   #elif defined(__L1CORE__)
extern sL1_TAS_CUSTOM_PARAMS  L1_TAS_Custom_Params;
extern sL1_TAS_CUSTOM_PDATA   L1_TAS_Custom_PData;
extern sL1_TAS_LIB_PARAMS L1_TAS_Lib_Params;
      #if  defined(__TAS_ANTENNA_IDX_ON_TEST_SIM__)
extern sL1_TAS_INIT_ANT_PARAMS L1_TAS_Init_Ant_Params;
      #endif
   #endif
#endif  
                                                 
#if IS_2G_DAT_SUPPORT
extern L1D_CUSTOM_DAT_FE_ROUTE_NVRAM_T  L1_DAT_Custom_FE_ROUTE_NVRAM;
extern L1D_CUSTOM_DAT_FE_CAT_A_NVRAM_T  L1_DAT_Custom_FE_CAT_A_NVRAM;
extern L1D_CUSTOM_DAT_FE_CAT_B_NVRAM_T  L1_DAT_Custom_FE_CAT_B_NVRAM;
#endif

   #if defined(__PCORE__)
extern sl1CustomBandSupport  l1d_custom_band_support;
   #elif defined(__L1CORE__)
extern sl1CustomBandSupport  l1d_custom_band_support;
   #endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif /* End of L1D_PUBLIC_H */
