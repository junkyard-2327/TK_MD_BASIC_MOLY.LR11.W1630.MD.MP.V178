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
 *   l1d_data_pcore.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   Definition of global data & tables used in L1D
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
 * 08 29 2017 xuqian.yan
 * [MOLY00273719] ?GIONEEBJ??MT6757?[MOLY00273719] ?GIONEEBJ??MT6757?[MOLY00273719] ?GIONEEBJ??MT6757?[MOLY00273719] DAT&SAR 2G L1D Part.
 *
 * 08 29 2017 xuqian.yan
 * [MOLY00273719] ?GIONEEBJ??MT6757?[MOLY00273719] ?GIONEEBJ??MT6757?[MOLY00273719] DAT&SAR 2G L1D Part.
 *
 * 08 29 2017 xuqian.yan
 * [MOLY00273719] ?GIONEEBJ??MT6757?[MOLY00273719] DAT&SAR 2G L1D Part.
 *
 * 01 21 2016 siyu.li
 * [MOLY00159775] 2G TAS  antenna idx setting by band
 * .
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
 * 08 06 2015 dou.ju
 * [MOLY00133157] [Jade] DRDI code modification[GL1D RF]Fix xL1Sim build error, and modify 2G DRDI code.
 *
 *
 *******************************************************************************/

#ifndef  _L1D_DATA_PCORE_H_
#define  _L1D_DATA_PCORE_H_
/*---------------------------------------------------------------------------*/
#include "l1d_cid.h"
#if IS_2G_DRDI_SUPPORT
#include "mml1_custom_drdi.h"
#include "l1d_custom_drdi.h"
#endif


#if IS_2G_DRDI_SUPPORT
   #if L1D_CUSTOM_DYNAMIC_INIT_ENABLE
#define L1D_CUSTOM_DYNAMIC_SUPPORT    IS_MML1_DRDI_ENABLE
#define L1D_CUSTOM_TOTAL_SET_NUMS     MML1_DRDI_REMAP_GGE_REAL_SET_NUMS
   #else
#define L1D_CUSTOM_DYNAMIC_SUPPORT    0
#define L1D_CUSTOM_TOTAL_SET_NUMS     1
   #endif   
#else
#define L1D_CUSTOM_DYNAMIC_SUPPORT    0
#define L1D_CUSTOM_TOTAL_SET_NUMS     1
#endif

#if defined(__TX_POWER_OFFSET_SUPPORT__) || defined(__SAR_TX_POWER_BACKOFF_SUPPORT__)
extern const sL1D_TX_POWER_OFFSET_DATA       L1D_TX_Power_Offset_Data[L1D_CUSTOM_TOTAL_SET_NUMS];
#endif /*__TX_POWER_OFFSET_SUPPORT__*/


extern const sL1D_FRONT_END_DATA             l1d_front_end_data[L1D_CUSTOM_TOTAL_SET_NUMS];


#if defined(__2G_MIPI_SUPPORT__)
extern const sGGE_DRDI_MIPI_CTRL_TABLE       l1d_mipi_ctrl_data[L1D_CUSTOM_TOTAL_SET_NUMS];
#endif

extern sCrystalParameter afc_crystal_data;

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
extern sCloadParameter CLoad_FreqOffset_data;
#endif

extern sTX_POWER_VOLTAGE_COMPENSATION tx_apc_voltage_compensation;
extern unsigned char  l1_2g_drdi_done;


extern const sl1CustomBandSupport* L1D_Custom_Band_Support_Data_Array[L1D_CUSTOM_TOTAL_SET_NUMS];
extern sl1CustomBandSupport  l1d_custom_band_support;

extern const sL1D_CAL_DATA  L1D_Cal_Data[L1D_CUSTOM_TOTAL_SET_NUMS];

/* 
   extern SetDefault symbols for L1D_PcoreUpdate2SHM_ByDefaultCustom() to use, 
   When IS_MML1_RF_PCORE_XL1SIM || IS_PCORE_BRINGUP_PHONECALL_TEMPLOAD_ENABLE 
 */
extern const sAGCGAINOFFSET*  AGC_PATHLOSS_TABLE_SetDefault[];
extern const sRAMPDATA*  RampData_SetDefault[];
#if defined(__EPSK_TX__)
extern const sRAMPDATA*  RampData_EPSK_SetDefault[];
#endif
#if defined(__EPSK_TX__)
extern const sMIDRAMPDATA** EPSK_InterRampData_SetDefault[];
#endif
extern const sMIDRAMPDATA*  InterRampData_SetDefault[];

#if IS_GPRS
extern const sTX_POWER_ROLLBACK* tx_power_rollback_gmsk_SetDefault[];
#endif

#if IS_EGPRS
extern const sTX_POWER_ROLLBACK* tx_power_rollback_epsk_SetDefault[];
#endif
#if IS_TX_POWER_CONTROL_SUPPORT
extern const sTXPC_TEMPDATA TEMP_DAC_SetDefault;
extern const sTXPC_TEMPDATA* TXTEMP_Data_SetDefault[];
   #if defined(__EPSK_TX__)
extern const sTXPC_TEMPDATA* TXTEMP_Data_EPSK_SetDefault[];
   #endif /* __EPSK_TX__ */
   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
extern const sTXPC_ADCDATA* TXADC_Data_SetDefault[];  
      #if defined(__EPSK_TX__)
extern const sTXPC_ADCDATA* TXADC_Data_EPSK_SetDefault[];
      #endif
   #endif
#endif

extern const sLNAGAINOFFSET*  LNA_PATHLOSS_TABLE_SetDefault[];

#if IS_TX_POWER_OFFSET_SUPPORT || IS_SAR_TX_POWER_BACKOFF_SUPPORT
extern const sTX_POWER_OFFSET*  Tx_Power_Offset_GMSK_SetDefault[];
   #if defined(__EPSK_TX__)
extern const sTX_POWER_OFFSET*  Tx_Power_Offset_EPSK_SetDefault[];
   #endif
#endif

extern const sCrystalParameter            afc_crystal_data_SetDefault;

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
extern const sL1D_RF_CUSTOM_INPUT_DATA    l1d_rf_custom_input_data_SetDefault;
#endif

#if IS_MIPI_SUPPORT
extern const sGGE_MIPI_CTRL_TABLE_BAND*   GGE_MIPI_CTRL_TABLE_SetDefault[];
#endif

extern const sl1CustomBandSupport         l1d_custom_band_support_SetDefault;


#if (IS_2G_TAS_SUPPORT||IS_2G_TAS_FOR_C2K_ONOFF_SUPPORT)
extern const sL1_TAS_CUSTOM_PARAMS        L1_TAS_Custom_Params_SetDefault;
extern const sL1_TAS_CUSTOM_PDATA         L1_TAS_Custom_PData_SetDefault;
   #if IS_2G_TAS_ANT_IDX_SET_ON_TEST_SIM
extern const sL1_TAS_INIT_ANT_PARAMS      L1_TAS_Init_Ant_Params_SetDefault;
   #endif
#endif

#if IS_2G_DAT_SUPPORT
extern L1D_CUSTOM_DAT_FE_ROUTE_NVRAM_T    L1_DAT_Custom_FE_ROUTE_NVRAM_SetDefault;
extern L1D_CUSTOM_DAT_FE_CAT_A_NVRAM_T    L1_DAT_Custom_FE_CAT_A_NVRAM_SetDefault;
extern L1D_CUSTOM_DAT_FE_CAT_B_NVRAM_T    L1_DAT_Custom_FE_CAT_B_NVRAM_SetDefault;
#endif

#if IS_2G_INI_PARAMETERS_INTO_DRDI_SUPPORT
extern l1cal_afcData_T        afc_crystal_data_dac_slop;
extern w_coef                 w_coef_data[ WCTABLE_SIZE ];
extern orionRFtx_pa_vbias     pa_data;   
#endif

#endif /* End of _L1D_DATA_PCORE_H_ */
