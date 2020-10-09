/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2015
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
 *   l1d_custom_drdi.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   RF constance definition
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime:  $
 * $Log:      $
 *
 * 11 22 2016 prakash.chaudhary
 * [MOLY00207476] [2GL1D][MT6750]2G TAS  antenna idx setting by band
 * 	
 * 	.
 *
 * 01 05 2016 dou.ju
 * [MOLY00155318] Switching Tx power feature 2G part
 * 	
 * 	.
 *
 * 09 15 2015 dou.ju
 * [MOLY00140126] [Jade][GL1D RF]DRDI code enhancement
 * 	.
 *
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_DRDI_H_
#define  _L1D_CUSTOM_DRDI_H_
#include "l1d_cid.h"

#define L1D_CUSTOM_DYNAMIC_INIT_ENABLE   1

/*m12193.c calibration data*/
#if defined(__TX_POWER_OFFSET_SUPPORT__)
#define  TX_POWER_OFFSET_GMSK_CUSTOM_TABLE(sET)                               \
{                                                                             \
   0,                                                                         \
   (sTX_POWER_OFFSET*)&GSM850_Tx_Power_Offset_GMSK_##sET,                     \
   (sTX_POWER_OFFSET*)&GSM_Tx_Power_Offset_GMSK_##sET,                        \
   (sTX_POWER_OFFSET*)&DCS_Tx_Power_Offset_GMSK_##sET,                        \
   (sTX_POWER_OFFSET*)&PCS_Tx_Power_Offset_GMSK_##sET                         \
},

   #if IS_EPSK_TX_SUPPORT
#define  TX_POWER_OFFSET_EPSK_CUSTOM_TABLE(sET)                               \
{                                                                             \
   0,                                                                         \
   (sTX_POWER_OFFSET*)&GSM850_Tx_Power_Offset_EPSK_##sET,                     \
   (sTX_POWER_OFFSET*)&GSM_Tx_Power_Offset_EPSK_##sET,                        \
   (sTX_POWER_OFFSET*)&DCS_Tx_Power_Offset_EPSK_##sET,                        \
   (sTX_POWER_OFFSET*)&PCS_Tx_Power_Offset_EPSK_##sET                         \
},
   #else
#define TX_POWER_OFFSET_EPSK_CUSTOM_TABLE(sET)
   #endif


#define L1D_CAL_CUSTOM_DATA_TxPowerOffset(sET)             \
{                                                          \
   TX_POWER_OFFSET_GMSK_CUSTOM_TABLE(sET)                  \
   TX_POWER_OFFSET_EPSK_CUSTOM_TABLE(sET)                  \
},
#endif
/*------------------------------------------------------------------------------------*/

/*m12197.c front end parameter*/
   #if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)
#define L1D_RF_CUSTOM_INPUT_DATA(sET)       (sL1D_RF_CUSTOM_INPUT_DATA*)&l1d_rf_custom_input_data_##sET,
   #else
#define L1D_RF_CUSTOM_INPUT_DATA(sET)
   #endif
   #if(defined(__TAS_SUPPORT__)||defined(__TAS_FOR_C2K_ONOFF_SUPPORT__))
#define L1D_TAS_CUSTOM_PARAMS_DATA(sET)     (sL1_TAS_CUSTOM_PARAMS*)&L1_TAS_Custom_Params_##sET,
#define L1D_TAS_CUSTOM_PDATA(sET)           (sL1_TAS_CUSTOM_PDATA*)&L1_TAS_Custom_PData_##sET,
      #if defined(__TAS_ANTENNA_IDX_ON_TEST_SIM__)
#define L1D_TAS_INIT_ANT_PARAMS_DATA(sET)   (sL1_TAS_INIT_ANT_PARAMS*)&L1_TAS_Init_Ant_Params_##sET,
      #else
#define L1D_TAS_INIT_ANT_PARAMS_DATA(sET)
      #endif
   #else
#define L1D_TAS_CUSTOM_PARAMS_DATA(sET)
#define L1D_TAS_CUSTOM_PDATA(sET)
#define L1D_TAS_INIT_ANT_PARAMS_DATA(sET)
   #endif

#define L1D_FRONTEND_CUSTOM_DATA(sET)                     \
{                                                         \
   L1D_RF_CUSTOM_INPUT_DATA(sET)                          \
   L1D_TAS_CUSTOM_PARAMS_DATA(sET)                        \
   L1D_TAS_CUSTOM_PDATA(sET)                              \
   L1D_TAS_INIT_ANT_PARAMS_DATA(sET)                      \
   0                                                      \
},


#if IS_MIPI_SUPPORT
/*l1d_custom_mipi.c  mipi ctrl event and data*/
#define L1D_MIPICTRL_CUSTOM_DATA(sET)                                        \
{                                                                            \
   {                                                                         \
      0,                                                                     \
      (sGGE_MIPI_CTRL_TABLE_BAND*)&GGE_MIPI_CTRL_TABLE_GSM850_##sET,         \
      (sGGE_MIPI_CTRL_TABLE_BAND*)&GGE_MIPI_CTRL_TABLE_GSM900_##sET,         \
      (sGGE_MIPI_CTRL_TABLE_BAND*)&GGE_MIPI_CTRL_TABLE_DCS1800_##sET,        \
      (sGGE_MIPI_CTRL_TABLE_BAND*)&GGE_MIPI_CTRL_TABLE_PCS1900_##sET         \
   }                                                                         \
},
#endif

#define L1D_CUSTOM_BAND_DATA(sET)         &l1d_custom_band_support_##sET,



#define AGC_PATHLOSS_CUSTOM_TABLE(sET)                            \
{                                                                 \
   0,                                                             \
   (sAGCGAINOFFSET*)AGC_PATHLOSS_GSM850_##sET,                    \
   (sAGCGAINOFFSET*)AGC_PATHLOSS_GSM900_##sET,                    \
   (sAGCGAINOFFSET*)AGC_PATHLOSS_DCS1800_##sET,                   \
   (sAGCGAINOFFSET*)AGC_PATHLOSS_PCS1900_##sET                    \
},

#define RAMPDATA_CUSTOM_TABLE(sET)                                \
{                                                                 \
   0,                                                             \
   (sRAMPDATA*)&GSM850_RampData_##sET,                            \
   (sRAMPDATA*)&GSM_RampData_##sET,                               \
   (sRAMPDATA*)&DCS_RampData_##sET,                               \
   (sRAMPDATA*)&PCS_RampData_##sET                                \
},

#if IS_EPSK_TX_SUPPORT
#define RAMPDATA_EPSK_CUSTOM_TABLE(sET)                           \
{                                                                 \
   0,                                                             \
   (sRAMPDATA*)&GSM850_RampData_EPSK_##sET,                       \
   (sRAMPDATA*)&GSM_RampData_EPSK_##sET,                          \
   (sRAMPDATA*)&DCS_RampData_EPSK_##sET,                          \
   (sRAMPDATA*)&PCS_RampData_EPSK_##sET                           \
},
#else
#define RAMPDATA_EPSK_CUSTOM_TABLE(sET)
#endif

#define  TX_APC_VOLTAGE_COMPENSATION_CUSTOM_DATA(sET)   (sTX_POWER_VOLTAGE_COMPENSATION*)&tx_apc_voltage_compensation_##sET, 

#define  INTERRAMPDATA_CUSTOM_TABLE(sET)                           \
{                                                                  \
   0,                                                              \
   (sMIDRAMPDATA*)&GSM850_InterRampData_##sET,                     \
   (sMIDRAMPDATA*)&GSM_InterRampData_##sET,                        \
   (sMIDRAMPDATA*)&DCS_InterRampData_##sET,                        \
   (sMIDRAMPDATA*)&PCS_InterRampData_##sET                         \
}, 

#if IS_EPSK_TX_SUPPORT
#define  INTERRAMPDATA_EPSK_CUSTOM_TABLE(sET)                      \
{                                                                  \
   0,                                                              \
   (sMIDRAMPDATA**)GSM850_EPSK_InterRampData_##sET,                \
   (sMIDRAMPDATA**)GSM_EPSK_InterRampData_##sET,                   \
   (sMIDRAMPDATA**)DCS_EPSK_InterRampData_##sET,                   \
   (sMIDRAMPDATA**)PCS_EPSK_InterRampData_##sET                    \
},
#else
#define  INTERRAMPDATA_EPSK_CUSTOM_TABLE(sET)
#endif

#define AFC_CRYSTAL_CUSTOM_DATA(sET)   (sCrystalParameter*)&afc_crystal_data_##sET,

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
#define CLOAD_FREQOFFSET_CUSTOM_DATA(sET)   (sCloadParameter*)&CLoad_FreqOffset_data_##sET,
#else
#define CLOAD_FREQOFFSET_CUSTOM_DATA(sET)
#endif


#if IS_GPRS
#define TX_POWER_ROLLBACK_GMSK_CUSTOM_TABLE(sET)                         \
{                                                                        \
   0,                                                                    \
   (sTX_POWER_ROLLBACK*)&GSM850_tx_power_rollback_gmsk_##sET,            \
   (sTX_POWER_ROLLBACK*)&GSM_tx_power_rollback_gmsk_##sET,               \
   (sTX_POWER_ROLLBACK*)&DCS_tx_power_rollback_gmsk_##sET,               \
   (sTX_POWER_ROLLBACK*)&PCS_tx_power_rollback_gmsk_##sET                \
},
	#if IS_EGPRS
#define TX_POWER_ROLLBACK_EPSK_CUSTOM_TABLE(sET)                         \
{                                                                        \
   0,                                                                    \
   (sTX_POWER_ROLLBACK*)&GSM850_tx_power_rollback_epsk_##sET,            \
   (sTX_POWER_ROLLBACK*)&GSM_tx_power_rollback_epsk_##sET,               \
   (sTX_POWER_ROLLBACK*)&DCS_tx_power_rollback_epsk_##sET,               \
   (sTX_POWER_ROLLBACK*)&PCS_tx_power_rollback_epsk_##sET                \
},
	#else
#define TX_POWER_ROLLBACK_EPSK_CUSTOM_TABLE(sET)
   #endif
#else
#define TX_POWER_ROLLBACK_GMSK_CUSTOM_TABLE(sET)
#define TX_POWER_ROLLBACK_EPSK_CUSTOM_TABLE(sET)
#endif

#if IS_TX_POWER_CONTROL_SUPPORT
	#if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT 
#define  TXADC_DATA_CUSTOM_TABLE(sET)                  \
{                                                      \
   0,                                                  \
   (sTXPC_ADCDATA*)&GSM850_TXADC_Data_##sET,           \
   (sTXPC_ADCDATA*)&GSM_TXADC_Data_##sET,              \
   (sTXPC_ADCDATA*)&DCS_TXADC_Data_##sET,              \
   (sTXPC_ADCDATA*)&PCS_TXADC_Data_##sET               \
},
#define  TXTEMP_DATA_CUSTOM_TABLE(sET)                 \
{                                                      \
   (sTXPC_TEMPDATA*)&TEMP_DAC_##sET,                   \
   (sTXPC_TEMPDATA*)&GSM850_TXTEMP_Data_##sET,         \
   (sTXPC_TEMPDATA*)&GSM_TXTEMP_Data_##sET,            \
   (sTXPC_TEMPDATA*)&DCS_TXTEMP_Data_##sET,            \
   (sTXPC_TEMPDATA*)&PCS_TXTEMP_Data_##sET             \
},
      #if IS_EPSK_TX_SUPPORT
#define  TXADC_DATA_EPSK_CUSTOM_TABLE(sET)             \
{                                                      \
   0,                                                  \
   (sTXPC_ADCDATA*)&GSM850_TXADC_Data_EPSK_##sET,      \
   (sTXPC_ADCDATA*)&GSM_TXADC_Data_EPSK_##sET,         \
   (sTXPC_ADCDATA*)&DCS_TXADC_Data_EPSK_##sET,         \
   (sTXPC_ADCDATA*)&PCS_TXADC_Data_EPSK_##sET          \
},

#define  TXTEMP_DATA_EPSK_CUSTOM_TABLE(sET)            \
{                                                      \
   0,                                                  \
   (sTXPC_TEMPDATA*)&GSM850_TXTEMP_Data_EPSK_##sET,    \
   (sTXPC_TEMPDATA*)&GSM_TXTEMP_Data_EPSK_##sET,       \
   (sTXPC_TEMPDATA*)&DCS_TXTEMP_Data_EPSK_##sET,       \
   (sTXPC_TEMPDATA*)&PCS_TXTEMP_Data_EPSK_##sET        \
   },
      #else
#define  TXADC_DATA_EPSK_CUSTOM_TABLE(sET)
#define  TXTEMP_DATA_EPSK_CUSTOM_TABLE(sET)
      #endif
   #else
#define  TXADC_DATA_CUSTOM_TABLE(sET)
#define  TXTEMP_DATA_CUSTOM_TABLE(sET)
#define  TXADC_DATA_EPSK_CUSTOM_TABLE(sET)
#define  TXTEMP_DATA_EPSK_CUSTOM_TABLE(sET)
   #endif 
#else
#define  TXADC_DATA_CUSTOM_TABLE(sET)
#define  TXTEMP_DATA_CUSTOM_TABLE(sET)
#define  TXADC_DATA_EPSK_CUSTOM_TABLE(sET)
#define  TXTEMP_DATA_EPSK_CUSTOM_TABLE(sET)
#endif

#define LNA_PATHLOSS_CUSTOM_TABLE(sET)               \
{                                                    \
   0,                                                \
   (sLNAGAINOFFSET*)LNA_PATHLOSS_GSM850_##sET,       \
   (sLNAGAINOFFSET*)LNA_PATHLOSS_GSM900_##sET,       \
   (sLNAGAINOFFSET*)LNA_PATHLOSS_DCS1800_##sET,      \
   (sLNAGAINOFFSET*)LNA_PATHLOSS_PCS1900_##sET       \
},

#define L1D_CAL_CUSTOM_DATA(sET)                     \
{                                                    \
   AGC_PATHLOSS_CUSTOM_TABLE(sET)                    \
   RAMPDATA_CUSTOM_TABLE(sET)                        \
   RAMPDATA_EPSK_CUSTOM_TABLE(sET)                   \
   TX_APC_VOLTAGE_COMPENSATION_CUSTOM_DATA(sET)      \
   INTERRAMPDATA_CUSTOM_TABLE(sET)                   \
   INTERRAMPDATA_EPSK_CUSTOM_TABLE(sET)              \
   AFC_CRYSTAL_CUSTOM_DATA(sET)                      \
   CLOAD_FREQOFFSET_CUSTOM_DATA(sET)                 \
   TX_POWER_ROLLBACK_GMSK_CUSTOM_TABLE(sET)          \
   TX_POWER_ROLLBACK_EPSK_CUSTOM_TABLE(sET)          \
   TXADC_DATA_CUSTOM_TABLE(sET)                      \
   TXTEMP_DATA_CUSTOM_TABLE(sET)                     \
   TXADC_DATA_EPSK_CUSTOM_TABLE(sET)                 \
   TXTEMP_DATA_EPSK_CUSTOM_TABLE(sET)                \
   LNA_PATHLOSS_CUSTOM_TABLE(sET)                    \
},
#endif
