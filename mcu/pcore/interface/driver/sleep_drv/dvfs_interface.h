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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dvfs_interface.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This file is for the public access of DVFS operation
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 05 2016 jim.chou
 * [MOLY00177563] [DVFS] Add EVS codec feature
 * [DVFS] Add EVS codec feature
 *
 * 10 12 2015 yu-hung.huang
 * [MOLY00144627] ELT trace for TPPA+MET
 * [DVFS] Add TPPA related trace for pcore dvfs
 *
 * 09 04 2015 yu-hung.huang
 * [MOLY00131286] [TK6291/Jade] DVFS Code Submission
 * [DVFS] PTP flow coding and AT command refine for PTP and original freq check
 *
 * 08 12 2015 yu-hung.huang
 * [MOLY00131286] [TK6291/Jade] DVFS Code Submission
 * [DVFS] code update:
 * 1. coding for PSMCU PLL INT DVFS flow & API,
 * 2. add PLL timeout check & log, 
 * 3. add PMIC access timeout assert,
 * 4. add AT CMD for PCore/MODEML1 V/F On/OFF, 
 * 5. PMIC access frequency monitor, 
 * 6. fix PMIC settle delay should be on voltage up, 
 * 7. add regular dump trace, 
 * 8. add ASSERT output parameters,
 * 9. and add nested DVFS lock/unlock IRQ
 *
 * 07 20 2015 yu-hung.huang
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * [DVFS] add AT CMD for dump PMIC Info and add PMIC settle time from 20us to 32us
 *
 * 07 10 2015 yu-hung.huang
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * [DVFS] PCore driver merge back to TRUNK (up to UMOLY_CBr.DVFS:CL1447303 from CL1392606)
 *
 * 06 18 2015 yu-hung.huang
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * [DVFS] PCore add Pre/Post Ctrl Set Scenario and add more log with supporting Extract
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DVFS_INTERFACE_H__
#define __DVFS_INTERFACE_H__

#include "kal_public_api.h"

/******************************************************************************
* Definitions provided by DVFS
******************************************************************************/
#include "pcore_dvfs_public.h"
#include "modeml1_dvfs_public.h"

/******************************************************************************
* Functions provided by DVFS
******************************************************************************/

/******************************************************************************
*   Function : DVFS_GetHandle
*   Description : This API will register the caller as a DVFS user
*   Parameter : kal_char* user_name : fill a string of user's name
*   Return    : kal_uint8: user's handle number
*   Note      : 1. User needs to notify DVFS owner to enlarge "Request Table" once using DVFS APIs
*               2. Call once and first in user's init function before using other DVFS APIs
******************************************************************************/
extern kal_uint8 DVFS_GetHandle( kal_char* user_name );

/******************************************************************************
*   Function : DVFS_PreCtrlSetScenario
*   Description : This API will give the desired scenario by the user with its handleNum
*                 on Pre-Ctrl before CPHY_CFG_REQ for setting V/F UP immediately
*   Parameter : 1. kal_uint8 handleNum: user's handle number
*               2. DVFS_SCENARIO_E scenario: user desired scenario
*   Return    : None
*   Note      : 1. Using this API should call DVFS_GetHandle once and first to get handle number
*               2. The real V/F setting will always fit user's desire but may not be equal
******************************************************************************/
extern void DVFS_PreCtrlSetScenario( kal_uint8 handleNum, DVFS_SCENARIO_E scenario );

/******************************************************************************
*   Function : DVFS_PostCtrlSetScenario
*   Description : This API will give the desired scenario by the user with its handleNum
*                 on Post-Ctrl after CPHY_CFG_CNF for setting V/F Down later
*   Parameter : 1. kal_uint8 handleNum: user's handle number
*               2. DVFS_SCENARIO_E scenario: user desired scenario
*   Return    : None
*   Note      : 1. Using this API should call DVFS_GetHandle once and first to get handle number
*               2. The real V/F setting will always fit user's desire but may not be equal
******************************************************************************/
extern void DVFS_PostCtrlSetScenario( kal_uint8 handleNum, DVFS_SCENARIO_E scenario );

/******************************************************************************
*   Function : DVFS_SetScenario
*   Description : This API will set the desired scenario by the user with its handleNum
*   Parameter : 1. kal_uint8 handleNum: user's handle number
*               2. DVFS_SCENARIO_E scenario: user desired scenario
*   Return    : None
*   Note      : 1. Using this API should call DVFS_GetHandle once and first to get handle number
*               2. The real V/F setting will always fit user's desire but may not be equal
*               3. Currently, for VoLTE speech EVS codec user
******************************************************************************/
extern void DVFS_SetScenario( kal_uint8 handleNum, DVFS_SCENARIO_E scenario );

/******************************************************************************
*   Function : DVFS_GetScenarioSettingByHandle
*   Description : This API will give the user's current desired scenario
*   Parameter : kal_uint8 handleNum: user's handle number
*   Return    : DVFS_SCENARIO_E: user's current desired scenario
*   Note      : The returned scenario is setting previously by user but may not be the real V/F setting
******************************************************************************/
extern DVFS_SCENARIO_E DVFS_GetScenarioSettingByHandle( kal_uint8 handleNum );

/******************************************************************************
*   Function : DVFS_CheckDVFSMeetScenarioRequirement
*   Description : This API will check the current V/F in SW&HW meet the scenario's requirement
*   Parameter : 1. kal_uint8 handleNum: user's handle number
*               2. DVFS_SCENARIO_E scenario: to be checked scenario
*   Return    : kal_bool: KAL_TRUE: V/F meet scenario, KAL_FALSE: V/F did not meet requirement
*   Note      : None
******************************************************************************/
extern kal_bool DVFS_CheckDVFSMeetScenarioRequirement( kal_uint8 handleNum, DVFS_SCENARIO_E scenario );

/******************************************************************************
*   Function : DVFS_SetTrace
*   Description : This API will set trace ON/OFF to affect each scenario's requirement
*   Parameter : kal_bool: KAL_TRUE: set TRACE ON, KAL_FALSE: set TRACE OFF
*   Return    : None
*   Note      : After calling DVFS_SetTrace(KAL_TRUE), DHL can check state by DVFS_CheckDVFSTraceState()
******************************************************************************/
extern void DVFS_SetTrace( kal_bool traceOP );

/******************************************************************************
*   Function : DVFS_CheckDVFSTraceState
*   Description : This API will set trace ON/OFF to affect each scenario's requirement
*   Parameter : None
*   Return    : kal_bool: KAL_TRUE: DVFS supporting Trace ON is done, KAL_FALSE: DVFS has not support Trace yet
*   Note      : If you want to open trace, need to call DVFS_SetTrace(KAL_TRUE) first. Or, check this API is KAL_TRUE
******************************************************************************/
extern kal_bool DVFS_CheckDVFSTraceState( void );

/******************************************************************************
*   Function : DVFS_AtCMDControlDVFS
*   Description : This API will modify the control of voltage & frequency on 
*                 both PCore and MODEML1
*   Parameter : kal_uint32 data_len, kal_uint8 *data_str from AT+EGCMD
*               data_len = 4 
*               data_str[] = 0xXXXXXXXX (adjustable? 0x01:0x00, 0xFF=no change)
*               XX                 PCORE_V, PCORE_F, MODEML1_V, MODEML1_F,
*               DVFS    OFF       :   0x00,    0x00,      0x00,      0x00,
*               DVFS    ON        :   0x01,    0x01,      0x01,      0x01,
*               PCORE   DFS  ONLY :   0x00,    0x01,      0x00,      0x00,
*               PCORE   DVFS OFF  :   0x00,    0x00,      0xFF,      0xFF, (=PCORE DFS OFF)
*               PCORE   DFS  ON   :   0xFF,    0x01,      0xFF,      0xFF,
*               PCORE   DVFS ON   :   0x01,    0x01,      0xFF,      0xFF,
*               MODEML1 DFS  ONLY :   0x00,    0x00,      0x00,      0x01,
*               MODEML1 DVFS ONLY :   0x00,    0x00,      0x01,      0x01,
*               MODEML1 DVFS OFF  :   0x00,    0xFF,      0x00,      0x00, (=MODEML1 DFS OFF)
*   Return    : kal_bool: KAL_TRUE
*   Note      : AT commands, 
*               DVFS    OFF       :   AT+EGCMD=60,4,"00000000"
*               DVFS    ON        :   AT+EGCMD=60,4,"01010101"
*               PCORE   DFS  ONLY :   AT+EGCMD=60,4,"00010000" 
*               PCORE   DVFS OFF  :   AT+EGCMD=60,4,"0000FFFF" (=PCORE DFS OFF)
*               PCORE   DFS  ON   :   AT+EGCMD=60,4,"FF01FFFF"
*               PCORE   DVFS ON   :   AT+EGCMD=60,4,"0101FFFF"
*               MODEML1 DFS  ONLY :   AT+EGCMD=60,4,"00000001"
*               MODEML1 DVFS ONLY :   AT+EGCMD=60,4,"00000101"
*               MODEML1 DVFS OFF  :   AT+EGCMD=60,4,"00FF0000" (=MODEML1 DFS OFF)
******************************************************************************/
extern kal_bool DVFS_AtCMDControlDVFS( kal_uint32 data_len, kal_uint8 *data_str );

/******************************************************************************
*   Function : DVFS_AtCMDDumpTraceAll
*   Description : This API will trigger dumping traces
*   Parameter : kal_bool: KAL_TRUE => call by AT CMD, KAL_FALSE => call by DVFS driver
*   Return    : kal_bool: KAL_TRUE
*   Note      : None
******************************************************************************/
extern kal_bool DVFS_AtCMDDumpTraceAll( kal_bool caller );

/******************************************************************************
*   Function : DVFS_AtCMDFrequencyMeterPSMCUPLLCheck
*   Description : This API will trigger frequency meter to measure PSMCU PLL on log
*   Parameter : kal_uint32 data_len, kal_uint8 *data_str from AT+EGCMD
*               data_len = 1 
*               data_str[] = 0xXX (0x00: Check OFF (default), 0x01: Check ON)
*   Return    : kal_bool: KAL_TRUE
*   Note      : AT commands,
*               FrequencyMeterPSMCUPLLCheck OFF : AT+EGCMD=62,1,"00"
*               FrequencyMeterPSMCUPLLCheck ON  : AT+EGCMD=62,1,"01"
******************************************************************************/
extern kal_bool DVFS_AtCMDFrequencyMeterPSMCUPLLCheck( kal_uint32 data_len, kal_uint8 *data_str );

/******************************************************************************
*   Function : DVFS_AtCMDControlPTPwDVFSOn
*   Description : This API can turn OFF/ON PTP while DVFS is ON
*   Parameter : kal_uint32 data_len, kal_uint8 *data_str from AT+EGCMD
*               data_len = 1 
*               data_str[] = 0xXX (0x00: PTP OFF (default), 0x01: PTP ON)
*   Return    : kal_bool: KAL_TRUE
*   Note      : AT commands,
*               PTP OFF while DVFS ON: AT+EGCMD=63,1,"00"
*               PTP ON  while DVFS ON: AT+EGCMD=63,1,"01"
******************************************************************************/
extern kal_bool DVFS_AtCMDControlPTPwDVFSOn( kal_uint32 data_len, kal_uint8 *data_str );

/******************************************************************************
*   Function : DVFS_AtCMDDumpPMICInfo
*   Description : This API will dump all PMIC information
*   Parameter : None
*   Return    : kal_bool: KAL_TRUE
*   Note      : None
******************************************************************************/
extern kal_bool DVFS_AtCMDDumpPMICInfo( void );

/******************************************************************************
*   Function : DVFS_TPPA_Dump_Current_Info
*   Description : This API will dump all DVFS TPPA information
*   Parameter : None
*   Return    : kal_bool: KAL_TRUE
*   Note      : None
******************************************************************************/
extern kal_bool DVFS_TPPA_Dump_Current_Info( void );

#endif /* __DVFS_INTERFACE_H__ */
