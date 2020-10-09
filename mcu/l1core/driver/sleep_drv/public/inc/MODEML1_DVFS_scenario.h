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
 *    MODEML1_DVFS_scenario.h
 *
 * Project:
 * --------
 *    MT6291
 *
 * Description:
 * ------------
 *    L1core DVFS configuration.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 

#ifndef __MODEML1_DVFS_SCENARIO_H__
#define __MODEML1_DVFS_SCENARIO_H__

#ifdef DVFS_ENABLE
/* 
   Attention: If you modify the scenario number of this table, you also should modify following tables:
   1. MODEML1_DVFS_SCENARIO_E in 
      l1core/driver/sleep_drv/public/inc/MODEML1_DVFS_scenario.h
   2. MODEML1_DVFS_Scenario_Freq_Mapping_Table in
      l1core/driver/sleep_drv/internal/inc/MODEML1_DVFS_table.h
   3. MODEML1_DVFS_Str_Scenario in 
      l1core/driver/sleep_drv/common/MODEML1_DVFS_Trace1.tmd 
   4. DEFINE_NC_SHARED_ARRAY_ASSIGN in
      common/driver/sleep_drv/src/modeml1_dvfs_public.c
   5. Sync. with Pcore DVFS owner
*/
typedef enum
{
MODEML1_DVFS_SCENARIO_INVALID = 0,
MODEML1_DVFS_SCENARIO_INVALID_1_OCIC ,
MODEML1_DVFS_SCENARIO_INVALID_2_OCIC ,
/* 3G FDD Scenario */
MODEML1_DVFS_SCENARIO_3G_FDD_NO_DSP ,
MODEML1_DVFS_SCENARIO_3G_FDD_WCDMA  ,
MODEML1_DVFS_SCENARIO_3G_FDD_HSPA   ,
MODEML1_DVFS_SCENARIO_3G_FDD_HSPA_3C,
/* 3G TDD Scenario */
MODEML1_DVFS_SCENARIO_3G_TDD_SLEEP , /* for TDD does not use INR3F/tdinrys and RxBRP in sleep state */
MODEML1_DVFS_SCENARIO_3G_TDD_NORMAL, /* Paging+Talking (including td ICS/Meas and all R4 channel) */
MODEML1_DVFS_SCENARIO_3G_TDD_HSPA  , /* HSDPA+HSUPA (>=R5+R7 channel) */
/* 4G LTE Scenario */
MODEML1_DVFS_SCENARIO_LTE_NO_RX               ,
MODEML1_DVFS_SCENARIO_LTE_NO_CA_BW_10M_NO_OCIC,
MODEML1_DVFS_SCENARIO_LTE_NO_CA_BW_10M_1_OCIC ,
MODEML1_DVFS_SCENARIO_LTE_NO_CA_BW_10M_2_OCIC ,
MODEML1_DVFS_SCENARIO_LTE_NO_CA_BW_20M_NO_OCIC,
MODEML1_DVFS_SCENARIO_LTE_NO_CA_BW_20M_1_OCIC ,
MODEML1_DVFS_SCENARIO_LTE_NO_CA_BW_20M_2_OCIC ,
MODEML1_DVFS_SCENARIO_LTE_CA_BW_20M_NO_OCIC   ,
MODEML1_DVFS_SCENARIO_LTE_CA_BW_20M_1_OCIC    ,
MODEML1_DVFS_SCENARIO_LTE_CA_BW_20M_2_OCIC    ,
MODEML1_DVFS_SCENARIO_LTE_CA_BW_30M_NO_OCIC   ,
MODEML1_DVFS_SCENARIO_LTE_CA_BW_30M_1_OCIC    ,
MODEML1_DVFS_SCENARIO_LTE_CA_BW_30M_2_OCIC    ,
MODEML1_DVFS_SCENARIO_LTE_CA_BW_40M_NO_OCIC   ,
MODEML1_DVFS_SCENARIO_LTE_CA_BW_40M_1_OCIC    ,
MODEML1_DVFS_SCENARIO_LTE_CA_BW_40M_2_OCIC    ,
/* LTE Multibin PBCH */
MODEML1_DVFS_SCENARIO_LTE_NO_MULTIBIN_PBCCH,
MODEML1_DVFS_SCENARIO_LTE_MULTIBIN_PBCCH   ,
/* LTE LWA Scenario */
MODEML1_DVFS_SCENARIO_LTE_LWA_OFF,
MODEML1_DVFS_SCENARIO_LTE_LWA_ON ,
/* Speech and EVS */
MODEML1_DVFS_SCENARIO_EVS_CODEC_OFF,
MODEML1_DVFS_SCENARIO_EVS_CODEC_ON ,
/* Scenario Number */
MODEML1_DVFS_SCENARIO_SCENARIO_MAX,
MODEML1_DVFS_SCENARIO_NUM
}MODEML1_DVFS_SCENARIO_E;
/* 
   Attention: If you modify the scenario number of this table, you also should modify following tables:
   1. MODEML1_DVFS_SCENARIO_E in 
      l1core/driver/sleep_drv/public/inc/MODEML1_DVFS_scenario.h
   2. MODEML1_DVFS_Scenario_Freq_Mapping_Table in
      l1core/driver/sleep_drv/internal/inc/MODEML1_DVFS_table.h
   3. MODEML1_DVFS_Str_Scenario in 
      l1core/driver/sleep_drv/common/MODEML1_DVFS_Trace1.tmd 
   4. DEFINE_NC_SHARED_ARRAY_ASSIGN in
      common/driver/sleep_drv/src/modeml1_dvfs_public.c
   5. Sync. with Pcore DVFS owner
*/
#endif /* ( defined(__DVFS_ENABLE__) && defined(TK6291) ) */

kal_uint32 MODEML1_DVFS_FddScenarioToDvfsGearConverter( kal_uint32 scenario );
kal_uint32 MODEML1_DVFS_TddScenarioToDvfsGearConverter( kal_uint32 scenario );
kal_uint32 MODEML1_DVFS_LteScenarioToDvfsGearConverter( kal_uint32 IsCA_RxBW_IsOCIC, kal_uint32 IsMultibin );

void MODEML1_DVFS_LteOcicStatusChange( kal_uint8 id_number, kal_uint8 ocic_number );
void MODEML1_DVFS_LteOcicStatusConfirmation( kal_uint8 *id_number, kal_uint8 *ocic_number );
void MODEML1_DVFS_LteMultibinPbchStatusChange( kal_uint8 id_number, kal_uint8 Multibin_number );
void MODEML1_DVFS_LteMultibinPbchStatusConfirmation( kal_uint8 *id_number, kal_uint8 *Multibin_number );

void MODEML1_DVFS_FddSetGearSchWin( kal_uint8 SchWinNum, kal_uint32 dvfs_gear );
void MODEML1_DVFS_TddSetGearSchWin( kal_uint8 SchWinNum, kal_uint32 dvfs_gear );
void MODEML1_DVFS_LteSetGearSchWin( kal_uint8 SchWinNum, kal_uint32 dvfs_gear );

void MODEML1_DVFS_FddSetGearImmEvent( kal_uint32 dvfs_gear );
void MODEML1_DVFS_TddSetGearImmEvent( kal_uint32 dvfs_gear );
void MODEML1_DVFS_LteSetGearImmEvent( kal_uint32 dvfs_gear );
void MODEML1_DVFS_LteSetInitGearImmEvent( kal_uint32 dvfs_gear );

void MODEML1_DVFS_FddActive( kal_bool IsFDDActive );
void MODEML1_DVFS_TddActive( kal_bool IsTDDActive );
void MODEML1_DVFS_LteActive( kal_bool IsLTEActive );

void MODEML1_DVFS_CheckGearTick( void );

void MODEML1_DVFS_PTP_NewPmicVolt_InitMode( void );
void MODEML1_DVFS_PTP_NewPmicVolt_MonitorMode( void );
#endif /* __MODEML1_DVFS_SCENARIO_H__ */
