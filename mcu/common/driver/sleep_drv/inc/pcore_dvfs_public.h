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
 *   pcore_dvfs_public.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This file defines the scenario table for DVFS 
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
 * 12 09 2016 jim.chou
 * [MOLY00204552] [DVFS][KIBO+] Modification on 6355 PMIC formula and PTP flow
 * Update MT6355 vsram LDO sw record value
 *
 * 11 28 2016 jim.chou
 * [MOLY00214892] [91 DVFS] ROSA porting
 * 1. ROSA DVFS porting
 * 	2. KIBO+ 3G HSPA freq modification from 777MHz to 612MHz
 *
 * 11 23 2016 jim.chou
 * [MOLY00214540] [91LWA][MP5][DVFS] 1.Add LWA scenario
 * [91LWA][MP5][DVFS] Add LWA scenario
 *
 * 09 22 2016 jim.chou
 * [MOLY00204552] [DVFS][KIBO+] Modification on 6355 PMIC formula and PTP flow
 * [DVFS] Modification on PMIC 6355 vsram_md formula for flow only log and PTP flow
 *
 * 07 21 2016 jim.chou
 * [MOLY00191748] [DVFS] Porting for MT6757P Kibo plus
 * [91 DVFS] KIBO+ porting
 *
 * 05 05 2016 jim.chou
 * [MOLY00177563] [DVFS] Add EVS codec feature
 * [DVFS] Add EVS codec feature
 *
 * 03 04 2016 jim.chou
 * [MOLY00167613] [DVFS] Porting for MT6757 Olympus
 * [DVFS] Porting for MT6757 Olympus
 *
 * 11 30 2015 yu-hung.huang
 * [MOLY00150981] [DVFS] Porting for MT6750 Jade Minus
 * [DVFS] porting DFS only for Jade Minus Project
 * 	1. define MT6750
 * 	2. divide bit_cell - logic_cell lower bound between VMODEM and VMD1
 * 	3. define MT6750 scenario_mapping_pcore_voltage_freq table
 * 	4. remove using DVFS_MODEML1_VOLTAGE_DEFAULT_PMIC_E
 * 	5. change to use scenario_mapping_modeml1_voltage[DVFS_SCENARIO_DEFAULT] as system default value
 *
 * 11 26 2015 yu-hung.huang
 * [MOLY00150566] [DVFS] changes for supporting OCIC multiple gear solution
 * [DVFS] change for supporting OCIC multiple gear solution
 *
 * 11 06 2015 yu-hung.huang
 * [MOLY00145236] [MT6797 Everest] DVFS Code Submission
 * [DVFS] update BIT_CELL-LOGIC_CELL value from 0.25V to 0.3V from Janet
 *
 * 09 04 2015 yu-hung.huang
 * [MOLY00131286] [TK6291/Jade] DVFS Code Submission
 * [DVFS] PTP flow coding and AT command refine for PTP and original freq check
 *
 * 08 24 2015 yu-hung.huang
 * [MOLY00138729] [MT6755] Modify DVFS scenario and new upper bound setting rule
 * [DVFS] update scenario: remove LTE X5 series scenario to fit with MODEML1 DSP scenario and add CA30 with OCIC scenarios
 *
 * 08 18 2015 yu-hung.huang
 * [MOLY00137929] [MD AutoTest][TTLIA]Externel (EE),0,0,99,/data/core/,1,modem,md1:(MCU_PCORE)[ASSERT] file:pcore/driver/sleep_drv/internal/src/dvfs_internal.c line:543
 * [DVFS] enlarge PMIC API latency assertion time
 *
 * 08 16 2015 yu-hung.huang
 * [MOLY00131286] [TK6291/Jade] DVFS Code Submission
 * [DVFS] Update:
 * 1. Open PCore V for DVFS all
 * 2. fix PMIC pending time assert condition, 
 * 3. update PMIC HW/SW pending time SPEC define for assertion, 
 * 4. enlarge regular trace time to reduce trace,
 * 5. update lock/restore IRQ API&flow,
 * 6. break critical path of lock IRQ in gear up flow for avoiding over 60 Qbit, 
 * 7. and move some trace out of lock IRQ situation
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
 * 08 04 2015 yu-hung.huang
 * [MOLY00131286] [TK6291/Jade] DVFS Code Submission
 * [DVFS] add at command for DVFS on/off and force on API for exception (define part)
 *
 * 08 03 2015 yu-hung.huang
 * [MOLY00133506] [MT6797] sleep drivder update
 * [DVFS] add EVEREST MT6797 compile option define
 *
 * 07 23 2015 yu-hung.huang
 * [MOLY00131286] [TK6291/Jade] DVFS Code Submission
 * [DVFS] avoid 60Q bit assert, refine profiling flow, re-place TRC, remove unnecessary IRQ lock, and temp mark PMIC read & atcmd lock IRQ
 *
 * 07 10 2015 yu-hung.huang
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * [DVFS] PCore driver merge back to TRUNK (up to UMOLY_CBr.DVFS:CL1447303 from CL1392606)
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SCENARIO_TABLE_H__
#define __SCENARIO_TABLE_H__

#include "kal_general_types.h"

/******************************************************************************
* Definitions
******************************************************************************/
#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)

// Constraints
#if defined(MT6757P)
#define DVFS_SRAM_MINIMUM_VOLTAGE_CONSTRAINT            800  // unit: mv
#define DVFS_SRAM_MINIMUM_VOLTAGE_CONSTRAINT_PMIC_E     0x2D // 0x2D*0.00625+0.51875=0.8V
#elif defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
#define DVFS_SRAM_MINIMUM_VOLTAGE_CONSTRAINT            900  // unit: mv, (0.85V -> 0.9V from KL Tong)
#define DVFS_SRAM_MINIMUM_VOLTAGE_CONSTRAINT_PMIC_E     0x30 // 0x28*0.00625+0.6=0.85V -> 0x30*0.00625+0.6=0.9V from KL Tong
#else
#error "Need to check SRAM minimum constraint."
#endif

#if defined(MT6750) || defined(MT6750S)
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_UPPER_BOUND        0    // Jade Minus/ROSA: VCORE2 = V_MODEM = V_SRAM_MD, Jade Minus: define both MT6755 and MT6750, ROSA: define MT6750S
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_UPPER_BOUND_PMIC_E 0x0  // Jade Minus/ROSA: VCORE2 = V_MODEM = V_SRAM_MD, Jade Minus: define both MT6755 and MT6750, ROSA: define MT6750S
#elif defined(TK6291) || defined(MT6755)
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_UPPER_BOUND        250  // unit: mv, (0.25V)
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_UPPER_BOUND_PMIC_E 0x28 // 0.05*5=0.25 == 0x08*5=0x28
#elif defined(MT6797) || defined(MT6757)
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_UPPER_BOUND        300  // unit: mv, (0.3V)
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_UPPER_BOUND_PMIC_E 0x30 // 0.05*6=0.3 == 0x08*6=0x30
#else
#error "Need to check BIT_CELL-LOGIC_CELL upper bound value with designer on current chip."
#endif

#if defined(MT6750) || defined(MT6750S)
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_LOWER_BOUND        0    // Jade Minus/ROSA: VCORE2 = V_MODEM = V_SRAM_MD, Jade Minus: define both MT6755 and MT6750, ROSA: define MT6750S
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_LOWER_BOUND_PMIC_E 0x0  // Jade Minus/ROSA: VCORE2 = V_MODEM = V_SRAM_MD, Jade Minus: define both MT6755 and MT6750, ROSA: define MT6750S
#elif defined(MT6757P)
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_LOWER_BOUND        131  // unit: mv, (0.13125V)
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_LOWER_BOUND_PMIC_E 0x15 // 21(0x15)*0.00625 = 0.13125
#elif defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757)
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_LOWER_BOUND        100  // unit: mv, (0.1V)
#define DVFS_SRAM_VMODEM_LOGIC_VOLTAGE_DIFF_LOWER_BOUND_PMIC_E 0x10 // 0.05*2=0.1  == 0x08*2=0x10
#else
#error "Need to check BIT_CELL-LOGIC_CELL lower bound value with designer on current chip."
#endif

#define DVFS_SRAM_VMD1_LOGIC_VOLTAGE_DIFF_LOWER_BOUND          100  // unit: mv, (0.1V)
#define DVFS_SRAM_VMD1_LOGIC_VOLTAGE_DIFF_LOWER_BOUND_PMIC_E   0x10 // 0.05*2=0.1  == 0x08*2=0x10

#if defined(MT6757P)
#define DVFS_VDD_MD1_VOLTAGE                            700  // unit: mv, (0.7V) => VDD_MD1 + DVFS_SRAM_LOGIC_VOLTAGE_DIFF_LOWER_BOUND <= VDD_SRAM_MODEM 
#define DVFS_VDD_MD1_VOLTAGE_PMIC_E                     0x30 // PMIC expression: 0x30(48) * 0.00625 + 0.4 = 0.7V
#elif defined(MT6757)
#define DVFS_VDD_MD1_VOLTAGE                            700  // unit: mv, (0.7V) => VDD_MD1 + DVFS_SRAM_LOGIC_VOLTAGE_DIFF_LOWER_BOUND <= VDD_SRAM_MODEM 
#define DVFS_VDD_MD1_VOLTAGE_PMIC_E                     0x10 // PMIC expression: 0x10(16) * 0.00625 + 0.6 = 0.7V
#elif defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6750S)
#define DVFS_VDD_MD1_VOLTAGE                            900  // unit: mv, (0.9V) => VDD_MD1 + DVFS_SRAM_LOGIC_VOLTAGE_DIFF_LOWER_BOUND <= VDD_SRAM_MODEM 
#define DVFS_VDD_MD1_VOLTAGE_PMIC_E                     0x30 // PMIC expression: 0x30(48) * 0.00625 + 0.6 = 0.9V
#else
#error "Need to define VDD_MD1 voltage."
#endif

#define DVFS_PMIC_100MV_UP_SETTLE_TIME                  8    // unit: us
#define DVFS_PMIC_150MV_UP_SETTLE_TIME                  12   // unit: us
#define DVFS_PMIC_100MV_DOWN_SETTLE_TIME                32   // unit: us
#define DVFS_PMIC_SETTLE_TIME                           DVFS_PMIC_150MV_UP_SETTLE_TIME  // Only up matter and concern PTP so use this number
#define DVFS_PMIC_WRAPPER_MD_SW_WACS1_PENDING_TIME      45   // unit: us, our SPEC to PMIC wrapper channel MD_SW_WACS1 is 20us, we add 25us for inaccuracy tolerance and PMIC SW time
#define DVFS_PMIC_WRAPPER_PENDING_TIME                  DVFS_PMIC_WRAPPER_MD_SW_WACS1_PENDING_TIME

#define DVFS_PMIC_WRAPPER_FREQ_DURATION                 10000   // unit: us, the frequency SPEC is once per 10ms
#define DVFS_PMIC_WRAPPER_FREQ_MEAR_DURATION            100000  // unit: us, the duration of measuring PMIC frequency is 100ms

// defines for PCore V & F table for PTP init
#define DVFS_PCORE_VOLTAGE_VALUE_NUM      2
#define DVFS_PCORE_VOLTAGE_VALUE_0        1000 // unit: mv, (1.0V)
#define DVFS_PCORE_VOLTAGE_VALUE_1        900  // unit: mv, (0.9V)

#if defined(MT6757P)
#define DVFS_PCORE_MAX_VOLTAGE_PMIC_E     0x42 // PMIC expression: 0x42(66) * 0.00625 + 0.51875 = 0.93125V
#define DVFS_PCORE_VOLTAGE_VALUE_0_PMIC_E 0x42 // PMIC expression: 0x42(66) * 0.00625 + 0.51875 = 0.93125V
#define DVFS_PCORE_VOLTAGE_VALUE_1_PMIC_E 0x42 // PMIC expression: 0x42(66) * 0.00625 + 0.51875 = 0.93125V
#elif defined(MT6757)
#define DVFS_PCORE_MAX_VOLTAGE_PMIC_E     0x30 // PMIC expression: 0x30(48) * 0.00625 + 0.6 = 0.9V
#define DVFS_PCORE_VOLTAGE_VALUE_0_PMIC_E 0x30 // PMIC expression: 0x30(48) * 0.00625 + 0.6 = 0.9V
#define DVFS_PCORE_VOLTAGE_VALUE_1_PMIC_E 0x30 // PMIC expression: 0x30(48) * 0.00625 + 0.6 = 0.9V
#elif defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6750S)
#define DVFS_PCORE_MAX_VOLTAGE_PMIC_E     0x50 // PMIC expression: 0x50(80) * 0.00625 + 0.6 = 1.1V
#define DVFS_PCORE_VOLTAGE_VALUE_0_PMIC_E 0x40 // PMIC expression: 0x40(64) * 0.00625 + 0.6 = 1.0V
#define DVFS_PCORE_VOLTAGE_VALUE_1_PMIC_E 0x30 // PMIC expression: 0x30(48) * 0.00625 + 0.6 = 0.9V
#else
#error "Need to define PCORE voltage."
#endif

#define DVFS_PCORE_FREQ_VALUE_NUM         7
#define DVFS_PCORE_FREQ_VALUE_0           777  // unit: MHz, 777MHz
#define DVFS_PCORE_FREQ_VALUE_1           768  // unit: MHz, 768MHz
#define DVFS_PCORE_FREQ_VALUE_2           612  // unit: MHz, 612MHz
#define DVFS_PCORE_FREQ_VALUE_3           601  // unit: MHz, 601MHz
#define DVFS_PCORE_FREQ_VALUE_4           596  // unit: MHz, 596MHz
#define DVFS_PCORE_FREQ_VALUE_5           567  // unit: MHz, 567MHz
#define DVFS_PCORE_FREQ_VALUE_6           560  // unit: MHz, 560MHz
#define DVFS_PCORE_MAX_FREQ_PLL_E         800  // unit: MHz, 800MHz
#define DVFS_PCORE_FREQ_VALUE_0_PLL_E     DVFS_PCORE_FREQ_VALUE_0  // unit: MHz, 777MHz
#define DVFS_PCORE_FREQ_VALUE_1_PLL_E     DVFS_PCORE_FREQ_VALUE_1  // unit: MHz, 768MHz
#define DVFS_PCORE_FREQ_VALUE_2_PLL_E     DVFS_PCORE_FREQ_VALUE_2  // unit: MHz, 612MHz
#define DVFS_PCORE_FREQ_VALUE_3_PLL_E     DVFS_PCORE_FREQ_VALUE_3  // unit: MHz, 601MHz
#define DVFS_PCORE_FREQ_VALUE_4_PLL_E     DVFS_PCORE_FREQ_VALUE_4  // unit: MHz, 596MHz
#define DVFS_PCORE_FREQ_VALUE_5_PLL_E     DVFS_PCORE_FREQ_VALUE_5  // unit: MHz, 567MHz
#define DVFS_PCORE_FREQ_VALUE_6_PLL_E     DVFS_PCORE_FREQ_VALUE_6  // unit: MHz, 560MHz

#define DVFS_PCORE_PLL_TIMEOUT_TIME       60   // unit: us, designer give 40~60us or 50us, we use worst 60us as timeout time

#define DVFS_PCORE_GEAR_NUM 7

#if defined(MT6757P)
    /*
     * Due to the difference of the PMIC formula base between vsram LDO and vmodem/vmd1
     * buck, vsram lower bound recorded in voltage request table needs to be corrected
     * through the macro TO_VSRAM_BASE. On the other hand, vmodem lower bound needs to
     * be corrected through the macro TO_VMODEM_BASE.
     */
    #define TO_VSRAM_BASE(vsram_lowerb) ((vsram_lowerb) - 0x13)
    #define TO_VMODEM_BASE(vmodem_upperb) ((vmodem_upperb) + 0x13)
#else
    #define TO_VSRAM_BASE(vsram_lowerb) (vsram_lowerb)
    #define TO_VMODEM_BASE(vmodem_upperb) (vmodem_upperb)
#endif

// Attention: Add or remove scenario should sync with MODEML1 owner too.
typedef enum
{
    // Scenarios:
    // Inactive
    DVFS_SCENARIO_DEFAULT = 0,            // RRC Scenario-Based Usage
    // 4G Inactive (every 4G RRC used scenarios need to extend OCIC scenarios for OCIC changing request voltage while bandwidth changing)
    DVFS_SCENARIO_DEFAULT_1_OCIC,         // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_DEFAULT_2_OCIC,         // For Matching MODEML1 Scenario Enum Only
    // 3G FDD
    DVFS_SCENARIO_3GFDD_CHANNEL_EMPTY,    // RRC Scenario-Based Usage
    DVFS_SCENARIO_3GFDD_CHANNEL_NON_HSPA, // RRC Scenario-Based Usage
    DVFS_SCENARIO_3GFDD_CHANNEL_HSPA,     // RRC Scenario-Based Usage
    DVFS_SCENARIO_3GFDD_CHANNEL_HSPA_3C,  // For Matching MODEML1 Scenario Enum Only (maybe future use)
    // 3G TDD
    DVFS_SCENARIO_3GTDD_CHANNEL_EMPTY,    // RRC Scenario-Based Usage
    DVFS_SCENARIO_3GTDD_CHANNEL_NON_HSPA, // RRC Scenario-Based Usage
    DVFS_SCENARIO_3GTDD_CHANNEL_HSPA,     // RRC Scenario-Based Usage
    // 4G (every 4G RRC used scenarios need to extend OCIC scenarios for OCIC changing request voltage while bandwidth changing)
    DVFS_SCENARIO_LTE_NO_RX,              // For Matching MODEML1 Scenario Enum Only     
    DVFS_SCENARIO_LTE_NONCA10,            // RRC Scenario-Based Usage
    DVFS_SCENARIO_LTE_NONCA10_1_OCIC,     // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_LTE_NONCA10_2_OCIC,     // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_LTE_NONCA20,            // RRC Scenario-Based Usage
    DVFS_SCENARIO_LTE_NONCA20_1_OCIC,     // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_LTE_NONCA20_2_OCIC,     // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_LTE_CA20,               // RRC Scenario-Based Usage
    DVFS_SCENARIO_LTE_CA20_1_OCIC,        // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_LTE_CA20_2_OCIC,        // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_LTE_CA30,               // RRC Scenario-Based Usage
    DVFS_SCENARIO_LTE_CA30_1_OCIC,        // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_LTE_CA30_2_OCIC,        // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_LTE_CA40,               // RRC Scenario-Based Usage
    DVFS_SCENARIO_LTE_CA40_1_OCIC,        // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_LTE_CA40_2_OCIC,        // For Matching MODEML1 Scenario Enum Only
    // LTE Multibin PBCH
    DVFS_SCENARIO_LTE_NO_MULTIBIN_PBCCH,  // For Matching MODEML1 Scenario Enum Only
    DVFS_SCENARIO_LTE_MULTIBIN_PBCCH,     // For Matching MODEML1 Scenario Enum Only
    // LWA
    DVFS_SCENARIO_LWA_OFF,                // LTE WIFI Aggregation Usage
    DVFS_SCENARIO_LWA_ON,                 // LTE WIFI Aggregation Usage
    // Speech and EVS
    DVFS_SCENARIO_EVS_CODEC_OFF,          // VoLTE EVS Speech Codec Usage
    DVFS_SCENARIO_EVS_CODEC_ON,           // VoLTE EVS Speech Codec Usage
    // Others
    DVFS_SCENARIO_MAX,                    // For Initialization And Debug Only
    DVFS_SCENARIO_NUM,                    // For Matching MODEML1 Scenario Enum Only

    DVFS_TOTAL_SCENARIO_TYPE_NUM
} DVFS_SCENARIO_E;

typedef enum
{
    // Modem 4G OCIC
    DVFS_SCENARIO_MODEML1_LTE_OCIC,
    DVFS_SCENARIO_MODEML1_LTE_MULTIBIN_PBCH,
} DVFS_MODEML1_SCENARIO_E;

typedef enum
{
    // Trace
    DVFS_SCEVARIO_TRACE_ON,
    DVFS_SCENARIO_TRACE_OFF,
} DVFS_TRACE_SCENARIO_E;

// removing the current scenario api (not neccessary => but add check meet requirement api)

/***************************************************************************
 * PTP for Jade: 
 *          V_MODEM   (MODEML1) => INIT & MONITOR mode
 *          V_MD1     (MD1)     => INIT mode
 *          V_SRAM_MD (PCore)   => INIT mode
 ***************************************************************************/
typedef enum {
    DVFS_CCIRQ_PTP_CTRL_ERROR = 0,
    // for V_MD1 using INIT mode
    DVFS_CCIRQ_PTP_CTRL_MD1_PTP_DONE,         // L1Core PTP notify PCore DVFS (L2P) that MD1 set to INIT mode is done which is voltage down, and then PCore's V_MD1 table can apply MD1's INIT value

    // for "PCore to MODEML1's upper bound" using MODEML1's INIT mode value (default)
    DVFS_CCIRQ_PTP_CTRL_MODEML1_PTP_DONE,     // MODEML1 DVFS notify PCore DVFS (L2P) that MODEML1 set to INIT/MONITOR mode is done which is voltage down after L1Core PTP notify MODEML1 DVFS
                                              // also implied that PCore's PTP INIT mode is done, and then PCore can begin to use PTP INIT mode after MODEML1 PTP applied
    DVFS_CCIRQ_PTP_CTRL_MODEML1_PTP_DONE_CNF, // PCore DVFS notify MODEML1 DVFS (P2L) that MODEML1 can change upper bound with second variable and no need to ACK Pcore
    // for "PCore to MODEML1's upper bound" using MODEML1's MONITOR mode value
    // PTP down
    DVFS_CCIRQ_PTP_CTRL_MODEML1_PTP_DOWN,     // MODEML1 DVFS notify PCore DVFS (L2P) that MODEML1 has used new PTP down value and PCore can take the value as MODEML1's upper bound
    DVFS_CCIRQ_PTP_CTRL_MODEML1_PTP_DOWN_CNF, // PCore DVFS notify MODEML1 DVFS (P2L) that MODEML1 can change upper bound with second variable and no need to ACK Pcore
    // PTP up
    DVFS_CCIRQ_PTP_CTRL_MODEML1_PTP_UP_REQ,   // MODEML1 DVFS notify PCore DVFS first (L2P) that MODEML1's upper bound need to up, ex: back to INIT mode before MODEML1 sleep, or MONITOR up
    DVFS_CCIRQ_PTP_CTRL_PCORE_PTP_UP_CNF,     // PCore DVFS notify MODEML1 DVFS (P2L) that PCore has handled MODEML1 PTP UP request with setting proper voltage, and then let MODEML1 do voltage up with upper bound in second variable and no need to ACK Pcore

    // for PCore using MONITOR mode (option)
    DVFS_CCIRQ_PTP_CTRL_PCORE_PTP_MONITOR_EN, // L1Core PTP notify PCore DVFS (L2P) to begin using PCore PTP MONITOR mode

    // for AT command 
    DVFS_CCIRQ_PTP_CTRL_OFF,                  // PCore PTP OFF first then notify MODEML1 OFF
    DVFS_CCIRQ_PTP_CTRL_ON,                   // PCore notify MODEML1 ON first then MODEML1 using DVFS_CCIRQ_PTP_CTRL_MODEML1_PTP_DONE to give confirmation
    DVFS_CCIRQ_PTP_CTRL_MD1_OFF,              // PCore notify L1Core PTP should be OFF
    DVFS_CCIRQ_PTP_CTRL_MD1_ON                // PCore notify L1Core PTP should be ON
} DVFS_CCIRQ_PTP_CTRL_CMD_E;

typedef enum {
    // PCore to MODEML1
    DVFS_CCIRQ_DVFS_CTRL_ERROR = 0,
    DVFS_CCIRQ_DVFS_CTRL_OFF = 1, // to avoid wrong sending 0 case
    DVFS_CCIRQ_DVFS_CTRL_ON,
    DVFS_CCIRQ_DVFS_CTRL_PCORE_DFS_ONLY,
    DVFS_CCIRQ_DVFS_CTRL_PCORE_DVFS_OFF,
    DVFS_CCIRQ_DVFS_CTRL_PCORE_DFS_ON,
    DVFS_CCIRQ_DVFS_CTRL_PCORE_DVFS_ON,
    DVFS_CCIRQ_DVFS_CTRL_MODEML1_DFS_ONLY,
    DVFS_CCIRQ_DVFS_CTRL_MODEML1_DVFS_ONLY,
    DVFS_CCIRQ_DVFS_CTRL_MODEML1_DVFS_OFF,
    // MODEML1 ACK to PCore
    DVFS_CCIRQ_DVFS_CTRL_ON_MODEML1_CNF,
    DVFS_CCIRQ_DVFS_CTRL_PCORE_DFS_ONLY_MODEML1_CNF
} DVFS_CCIRQ_DVFS_CTRL_CMD_E;

typedef struct dvfs_pcore_gear_element_s {
    kal_uint32 gear_voltage;
    kal_uint32 gear_freq;
} dvfs_pcore_gear_element_t;

typedef struct dvfs_global_define_s {
    kal_bool pcore_voltage_hw_adjustable;
    kal_bool pcore_frequency_hw_adjustable;
    kal_bool modeml1_voltage_hw_adjustable;
    kal_bool modeml1_frequency_hw_adjustable;
} dvfs_global_define_t;

#ifdef DVFS_ENABLE

// static fill in by PCore DVFS and read by PTP in L1Core
DECLARE_SHARED_ARRAY(dvfs_pcore_gear_element_t, dvfs_pcore_gear_table, DVFS_PCORE_GEAR_NUM) // extern dvfs_pcore_gear_element_t dvfs_pcore_gear_table[DVFS_PCORE_GEAR_NUM]
// dynamic fill in by PTP in L1Core and read by PCORE DVFS
DECLARE_SHARED_ARRAY(dvfs_pcore_gear_element_t, dvfs_pcore_gear_table_ptp_init, DVFS_PCORE_GEAR_NUM) // extern dvfs_pcore_gear_element_t dvfs_pcore_gear_table_ptp_init[DVFS_PCORE_GEAR_NUM]

extern dvfs_global_define_t dvfs_global;

#endif /* DVFS_ENABLE */

#else /* end of "defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757)" */
  #ifdef DVFS_ENABLE
    #error "DVFS_ENABLE but without project's scenario table definition. Please check it."
  #endif /* DVFS_ENABLE */
#endif /* end of else of "defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757)" */


#endif /* __SCENARIO_TABLE_H__ */
