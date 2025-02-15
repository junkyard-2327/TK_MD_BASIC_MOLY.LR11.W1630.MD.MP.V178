/*******************************************************************************
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


/*****************************************************************************
 *
 * Filename:
 * ---------
 *   l1d_shm_data.h
 *
 * Project:
 * --------
 *   TK6291 Project
 *
 * Description:
 * ------------
 *   Define L1D RF custom array/variable in SHM.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*===============================================================================*/
#ifndef _L1D_SHM_DATA_H_
#define _L1D_SHM_DATA_H_

#include "l1d_cid.h"
#include "mmrf_kal.h"
#include "l1cal.h"

#if (IS_2G_TAS_SUPPORT||IS_2G_TAS_FOR_C2K_ONOFF_SUPPORT) || (IS_2G_DAT_SUPPORT)
#include "l1_types_public.h"
#endif

MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sAGCGAINOFFSET*, AGC_PATHLOSS_SHM_TABLE, FrequencyBandCount);
MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sLNAGAINOFFSET*, LNA_PATHLOSS_SHM_TABLE, FrequencyBandCount);
MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sRAMPDATA*, RampData_SHM_TABLE, FrequencyBandCount);

#if IS_EPSK_TX_SUPPORT
MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sRAMPDATA*, RampData_EPSK_SHM_TABLE, FrequencyBandCount);
#endif

#if IS_EPSK_TX_SUPPORT
/*EPSK*/ MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sMIDRAMPDATA**, InterRampData_EPSK_SHM_TABLE, FrequencyBandCount);
#elif   (IS_GPRS || IS_MULTISLOT_TX_SUPPORT)
/*GPRS*/ MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sMIDRAMPDATA*, InterRampData_SHM_TABLE, FrequencyBandCount);
#endif /* __EPSK_TX__  */

#if IS_TX_POWER_CONTROL_SUPPORT
MMRF_CUSTOM_DECLARE_SHARED_VAR(l1cal_txpc_T, GMSK_TXPC_SHM);
   #if IS_EPSK_TX_SUPPORT
MMRF_CUSTOM_DECLARE_SHARED_VAR(l1cal_txpc_T, EPSK_TXPC_SHM);
   #endif
MMRF_CUSTOM_DECLARE_SHARED_VAR(l1cal_temperatureADC_T, TEMPERATURE_ADC_SHM);
#endif /* IS_TX_POWER_CONTROL_SUPPORT  */

#if IS_GPRS
MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sTX_POWER_ROLLBACK*, TX_POWER_ROLLBACK_GMSK_SHM_TABLE, FrequencyBandCount);
#endif

#if IS_EGPRS
MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sTX_POWER_ROLLBACK*, TX_POWER_ROLLBACK_EPSK_SHM_TABLE, FrequencyBandCount);
#endif

#if IS_TX_GAIN_RF_CALIBRATION_SUPPORT
MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sTXGAIN_RFDATA*, GAIN_RF_SHM_TABLE, FrequencyBandCount);
#endif /* IS_TX_GAIN_RF_CALIBRATION_SUPPORT  */

#if IS_2G_MMPOC_SUPPORT
MMRF_CUSTOM_DECLARE_SHARED_VAR(MMRFC_GSM_RESULT_T, MMRFC_GSM_RESULT_SHM);
#endif

MMRF_CUSTOM_DECLARE_SHARED_VAR(l1cal_afcData_T, AFC_DATA_SHM);

MMRF_CUSTOM_DECLARE_SHARED_VAR(l1cal_crystalCapData_T, CAP_DATA_SHM);

MMRF_CUSTOM_DECLARE_SHARED_VAR(sBBTXParameters, TXIQ_SHM);

MMRF_CUSTOM_DECLARE_SHARED_VAR(sRFSpecialCoef, RFSPECIALCOEF_SHM);

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
MMRF_CUSTOM_DECLARE_SHARED_VAR(int, CLOAD_FREQ_OFFSET_SHM);
#endif

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
MMRF_CUSTOM_DECLARE_SHARED_VAR(sL1D_RF_CUSTOM_INPUT_DATA, RF_CUSTOM_INPUT_DATA_SHM);
#endif

#if IS_MIPI_SUPPORT
MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sGGE_MIPI_CTRL_TABLE_BAND*, GGE_MIPI_CTRL_SHM_TABLE, FrequencyBandCount);
#endif

#if (IS_2G_TAS_SUPPORT||IS_2G_TAS_FOR_C2K_ONOFF_SUPPORT)
MMRF_CUSTOM_DECLARE_SHARED_VAR(sL1_TAS_CUSTOM_PARAMS, TAS_CUSTOM_PARAMES_SHM);

MMRF_CUSTOM_DECLARE_SHARED_VAR(sL1_TAS_CUSTOM_PDATA, TAS_CUSTOM_PDATA_SHM);
   #if IS_2G_TAS_ANT_IDX_SET_ON_TEST_SIM
MMRF_CUSTOM_DECLARE_SHARED_VAR(sL1_TAS_INIT_ANT_PARAMS, TAS_INIT_ANT_PARAMS_SHM);
   #endif
#endif

#if IS_2G_DAT_SUPPORT
MMRF_CUSTOM_DECLARE_SHARED_VAR(L1D_CUSTOM_DAT_FE_ROUTE_NVRAM_T, DAT_CUSTOM_FE_ROUTE_NVRAM_SHM);
MMRF_CUSTOM_DECLARE_SHARED_VAR(L1D_CUSTOM_DAT_FE_CAT_A_NVRAM_T, DAT_CUSTOM_FE_CAT_A_NVRAM_SHM);
MMRF_CUSTOM_DECLARE_SHARED_VAR(L1D_CUSTOM_DAT_FE_CAT_B_NVRAM_T, DAT_CUSTOM_FE_CAT_B_NVRAM_SHM);
#endif

#if IS_TX_POWER_OFFSET_SUPPORT || IS_SAR_TX_POWER_BACKOFF_SUPPORT
MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sTX_POWER_OFFSET*, TX_Power_Offset_GMSK_SHM_TABLE, FrequencyBandCount);
   #if IS_EPSK_TX_SUPPORT   
MMRF_CUSTOM_DECLARE_SHARED_ARRAY(sTX_POWER_OFFSET*, TX_Power_Offset_EPSK_SHM_TABLE, FrequencyBandCount);
   #endif  
#endif

MMRF_CUSTOM_DECLARE_SHARED_VAR(sl1CustomBandSupport, CUSTOM_BAND_SUPPORT_SHM);

#if IS_GPS_FREQ_AIDING_SUPPORT
MMRF_CUSTOM_DECLARE_SHARED_VAR(sL1D_MD1_AFC_DATA, MD1_AFC_DAC_SHM);
#endif 

#endif /*_L1D_SHM_DATA_H_*/
