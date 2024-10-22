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
 *   sleepdrv_common.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is a common include file for l1core & pcore dual-core
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
 * 11 23 2016 che-wei.chang
 * [MOLY00214591] add compiler option MT6750S for TOPSM/OST driver
 *
 * 08 11 2016 che-wei.chang
 * [MOLY00196533] [IRONMAN] implement sleep log function
 *
 * 02 18 2016 kevin-kh.liu
 * [MOLY00165387] [Olympus][MP3] Sleep Mode Modifications
 * 	
 * 	Add chip Olympus option - common & l1core md_sm interface part
 *
 * 09 04 2015 che-wei.chang
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * update sleep ccirq cmd enum for DVFS
 *
 * 08 19 2015 hsiao-hsien.chen
 * [MOLY00131673] [Jade] Sleep mode code modification.
 * Enable l1core memory sleep in WFI feature.
 *
 * 08 07 2015 che-wei.chang
 * [MOLY00127376] [MT6755][UMOLY]
 * add "SleepDrv_CCIRQ_CMD_DEM_PEER_WAKEUP" CCIRQ cmd enum
 *
 * 08 04 2015 che-wei.chang
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * update ccirq cmd enum
 *
 * 08 03 2015 guo-huei.chang
 * [MOLY00133506] [MT6797] sleep drivder update
 * 	Update TOSPM and OSTD driver for Everest
 *
 * 07 29 2015 ethan.hsieh
 * [MOLY00131103] Sleep Mode Debug Shared Memory Mechanism Improvement
 *
 * 07 10 2015 che-wei.chang
 * [MOLY00127376] [MT6755][UMOLY]update md 26m settle time to 4ms
 *
 * 07 10 2015 che-wei.chang
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission,add ccirq enum for DVFS
 *
 * 07 07 2015 che-wei.chang
 * [MOLY00089700] [TK6291][UMOLY]
 * sync low power Cbr
 * 	1.add stress test AT CMD (ps side)
 * 	2.add at_sleepcount AT CMD (ps side)
 * 	3.update setting for JADE
 *
 * 06 18 2015 hsiao-hsien.chen
 * [MOLY00072109] [MT6291] Sleep mode code modification.
 * Fix build error. Add CCIRQ enum for pcore stress test.
 *
 * 06 11 2015 che-wei.chang
 * [MOLY00089700] [TK6291][UMOLY]
 * update SleepDrv_CCIRQ_CMD_E for DVFS
 *
 * 05 28 2015 ethan.hsieh
 * [MOLY00085137] [TK6291] Sleep Mode Modifications - Move infinite sleep compile option to sleepdrv_common.h for both Pcore and L1core
 *
 * 05 14 2015 ethan.hsieh
 * [MOLY00085137] [TK6291] Sleep Mode Modifications - Infinite Sleep for Jade
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __SLEEPDRV_COMMON_H__
#define __SLEEPDRV_COMMON_H__

typedef enum
{
   SleepDrv_CCIRQ_CMD_INVALID = 0,
   SleepDrv_CCIRQ_CMD_EL2_POWER_CONTROL,
   SleepDrv_CCIRQ_CMD_LP_LOCK_SLEEP,
   SleepDrv_CCIRQ_CMD_LP_SYNC_32K_CALIBRATION,
   SleepDrv_CCIRQ_CMD_INFINITE_SLEEP,
   SleepDrv_CCIRQ_CMD_DVFS_INIT_CMD,
   SleepDrv_CCIRQ_CMD_DVFS_CHANGE_RANGE_CMD,
   SleepDrv_CCIRQ_CMD_DVFS_SET_TABLE_CMD,
   SleepDrv_CCIRQ_CMD_DVFS_ACK_CMD,
   SleepDrv_CCIRQ_CMD_DVFS_MDL1_REQUEST,
   SleepDrv_CCIRQ_CMD_DVFS_MDL1_REQUEST_CNF,
   SleepDrv_CCIRQ_CMD_DVFS_ERROR_CMD,
   SleepDrv_CCIRQ_CMD_DVFS_FORCE_MAX_CMD,
   SleepDrv_CCIRQ_CMD_DVFS_CTRL_CMD,
   SleepDrv_CCIRQ_CMD_DVFS_PTP_CMD,
   SleepDrv_CCIRQ_CMD_DVFS_MD1_PTP_CMD,
   SleepDrv_CCIRQ_CMD_OST_STRESS_TEST,
   SleepDrv_CCIRQ_CMD_SLEEP_COUNT,
   SleepDrv_CCIRQ_CMD_DBG_SHM_INFO,
   SleepDrv_CCIRQ_CMD_DEM_PEER_WAKEUP,
   SleepDrv_CCIRQ_CMD_END,
}SleepDrv_CCIRQ_CMD_E;

#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
#define IS_MD_INFINITE_SLEEP_SUPPORT 1
#else
#define IS_MD_INFINITE_SLEEP_SUPPORT 0
#endif

// sys clk define for both core
#if defined(TK6291)
#define RM_SYS_CLK_SETTLE     0x66
#elif defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
#define RM_SYS_CLK_SETTLE     0x86
#endif

typedef enum {
    SLP_DBG_SHM_FIX_REG_PS_ISR_SM_SLV_REQ_STA,
    SLP_DBG_SHM_FIX_REG_PS_NON_F32K_WKUP_STA,
    SLP_DBG_SHM_FIX_REG_PS_F32K_WKUP_STA,
    SLP_DBG_SHM_FIX_REG_PS_F32K2_WKUP_STA,
    SLP_DBG_SHM_FIX_REG_PS_PRE_TIMESTAMP,
    SLP_DBG_SHM_FIX_REG_PS_AFT_TIMESTAMP,
    SLP_DBG_SHM_FIX_REG_PS_SW_LOCK,
    SLP_DBG_SHM_FIX_REG_PS_RM_PWR_STA,
    SLP_DBG_SHM_FIX_REG_PS_SW_PWR_CLK_FORCE_ON,
    SLP_DBG_SHM_FIX_REG_PS_PWRPLL_OFF_REC,
    SLP_DBG_SHM_FIX_REG_PS_MD_SYSCLK_GATING_STA,
    SLP_DBG_SHM_FIX_REG_PS_RESERVED1,
    SLP_DBG_SHM_FIX_REG_PS_END = SLP_DBG_SHM_FIX_REG_PS_RESERVED1,
    SLP_DBG_SHM_FIX_REG_L1_ISR_SM_SLV_REQ_STA,
    SLP_DBG_SHM_FIX_REG_L1_NON_F32K_WKUP_STA,
    SLP_DBG_SHM_FIX_REG_L1_F32K_WKUP_STA,
    SLP_DBG_SHM_FIX_REG_L1_PRE_TIMESTAMP,
    SLP_DBG_SHM_FIX_REG_L1_AFT_TIMESTAMP,
    SLP_DBG_SHM_FIX_REG_L1_SW_LOCK,
    SLP_DBG_SHM_FIX_REG_L1_SM_PWR_RDY,
    SLP_DBG_SHM_FIX_REG_L1_SM_PLL_STA,
    SLP_DBG_SHM_FIX_REG_L1_SM_DBG_REQ_STA,
    SLP_DBG_SHM_FIX_REG_L1_SM_MAS_REQ_STA,
    SLP_DBG_SHM_FIX_REG_L1_SM_PWR_ON_SW_CTRL0,
    SLP_DBG_SHM_FIX_REG_L1_SW_PLL_FORCE_ON,
    SLP_DBG_SHM_FIX_REG_L1_END = SLP_DBG_SHM_FIX_REG_L1_SW_PLL_FORCE_ON,
    SLP_DBG_SHM_FIX_REG_END
} SLP_DBG_SHM_FIX_REG_INDEX;

typedef struct {
    kal_uint32 guard_pat;
    // fix pattern of buffer selection for pscore
    kal_uint32 buf_sel_ps;
    // fix pattern of buffer selection for l1core
    kal_uint32 buf_sel_l1;
    kal_uint32 revision;
    // double size for fix pattern
    kal_uint32 fix_reg[SLP_DBG_SHM_FIX_REG_END<<1];
} slp_dbg_shm_fix_pat_t;

typedef enum {
    //SLP_DBG_SHM_LockSleep = 0x1,
    //SLP_DBG_SHM_UnLockSleep,
    SLP_DBG_SHM_2G_Sleep = 0x1,
    SLP_DBG_SHM_2G_Wakeup,
    SLP_DBG_SHM_3G_Sleep,
    SLP_DBG_SHM_3G_Wakeup,
    SLP_DBG_SHM_4G_Sleep,
    SLP_DBG_SHM_4G_Wakeup,
    SLP_DBG_SHM_RAT_InfiniteSleep_Done,
} SLP_DBG_SHM_RING_BUFFER_INDEX;

typedef struct {
    // index is for recording enumrate SLP_DBG_SHM_RING_BUFFER_INDEX
    kal_uint32 index:4;
    // Bi[0] = 1 if 2G RM_TMR_SSTA is not in pause state
    // Bi[1] = 1 if 3G RM_TMR_SSTA is not in pause state
    // Bi[2] = 1 if SM_SLV_REQ_STA shows TD is slave ready
    // Bi[3] = 1 if 4G RM_TMR_SSTA is not in pause state
    kal_uint32 status:4;
    // record for FMA global timestamp, and unit is 256 us.
    kal_uint32 timestamp:24;
    // additional debug information for user.
    kal_uint32 dbg_info;
} slp_dbg_shm_ring_buf_t;

// Now, AP only dumps 512 bytes although shared memory size is 1K bytes
#define SLP_DBG_SHM_AP_DUMP_SIZE    512
typedef struct {
    kal_uint32 guard_pat1;
    kal_uint32 guard_pat2;
    kal_uint32 guard_pat3;
    kal_uint32 revision;
    slp_dbg_shm_ring_buf_t info[(SLP_DBG_SHM_AP_DUMP_SIZE-sizeof(slp_dbg_shm_fix_pat_t)-sizeof(kal_uint32)*4)/sizeof(slp_dbg_shm_ring_buf_t)];
} slp_dbg_shm_ring_pat_t;

typedef struct {
    slp_dbg_shm_fix_pat_t fix_pat;
    slp_dbg_shm_ring_pat_t ring_pat;
} slp_dbg_shm_t;

//for l1 latest sleep time (HTC sleep dbg cnt)
#define PCORE_OST_SPARE_REG9       ((volatile kal_uint32*)(0xF00E0000+0x224))
//share memory structure (HTC sleep dbg cnt)
typedef struct {
    kal_uint32 cnt;                //the counter for record how many times modem goes to sleep
    kal_uint32 latest_time;        //latest modem sleep time
    kal_uint32 acc_time;           //the accumulation of the modem sleep time
    kal_uint32 reserved;
} slp_cnt_t;

typedef enum
{
   MEM_TYPE_TCM,
   MEM_TYPE_L2TCM,
}MEM_TYPE_E;

#endif
