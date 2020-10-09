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
 *   init_trc_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains definitions for trace on target.
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/************************************************************
 * NOTE: prefix of trace id:
 *          TSID_:  can be found in mcu\service\sys_svc\profile\inc\maui_time_stamp_id.h
 *          SST_:   can be found in mcu\driver\sys_drv\init\inc\system_trc.h
 *          BOOT_:  can be found in mcu\driver\sys_drv\init\inc\init_trc_id.h
 ************************************************************/

#ifndef _INIT_TRC_API_H
#define _INIT_TRC_API_H

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"
#include "mcu_pmu_montr.h"
#include "init_trc_id.h"
#include "ex_mem_manager_public.h"
#include "bootarm.h"
#if defined(__SP_BOOTTRC_ENABLE__)
#include "ccci.h"
#endif
extern void INT_backupBootLogs(void);

// Temp solution for bootup trace
#define EMM_BOOT_TS(trc_id)
//#define TASK_Trace(task_index)
#define TASK_Trace_Magic(magic1, magic2)

#define TASK_MAGIC  0x4B534154
#define TASK_MAGIC1 0x546B5374 // TkSt
#define TASK_MAGIC2 0x546B4564 // TkEd

/* Boot up trace for RTL CoSim MDM logging */
#if defined(__PCORE__)
#define MDM_BASE            (0xF0390000)
#elif defined(__L1CORE__)
#define MDM_BASE            (0xF6020000)
#endif


#define MDM_INT32_BASE      (MDM_BASE+0x0F0C)
#define MDM_TM_MEMDUMPSTR   (MDM_BASE+0x0F60)
#define MDM_TM_MEMDUMPSTOP  (MDM_BASE+0x0F64)
#define MDM_TM_ENDFAIL      (MDM_BASE+0x0F40)
#define MDM_END_SUCC        (MDM_BASE+0x0F44)
#define MDM_INT32_BASE      (MDM_BASE+0x0F0C)
#define MDM_TM_HEXFMT_32B   (MDM_BASE+0x0F54)
#define MDM_TM_STR0         (MDM_BASE+0x0FC8)
#define MDM_TM_STR_CLEAR    (MDM_BASE+0x0FC0)
#define MDM_TM_STR_DISPLAY  (MDM_BASE+0x0FC4)


#if !defined(__COSIM_BYPASS_DRV__)
#define MDM_INT32_WRITE(int32_log)
#define MDM_TMMEMDUMP_STR_WRITE(int32_log)
#define MDM_TMMEMDUMP_STOP_WRITE(int32_log)
#define MDM_TM_END_FAIL_WRITE
#define MDM_TM_END_SUCC_WRITE
#define MDM_STR0_WRITE(char_write)
#define MDM_TM_STR_CLEAR_WRITE(clear_buffer_num)
#define MDM_TM_STR_DISPLAY_WRITE(display_buffer_num)

#else
extern void MDM_ASSERT(kal_uint32 e1, kal_uint32 e2, kal_uint32 e3);
extern void MDM_kal_fatal_error_handler(kal_uint32 code1, kal_uint32 code2);

#define MDM_INT32_WRITE(int32_log) (*((volatile kal_uint32*) MDM_TM_HEXFMT_32B)=(kal_uint32)(int32_log));
#define MDM_TMMEMDUMP_STR_WRITE(int32_log) (*((volatile kal_uint32*) MDM_TM_MEMDUMPSTR)=(kal_uint32)(int32_log));
#define MDM_TMMEMDUMP_STOP_WRITE(int32_log) (*((volatile kal_uint32*) MDM_TM_MEMDUMPSTOP)=(kal_uint32)(int32_log));
#define MDM_TM_END_FAIL_WRITE (*((volatile kal_uint32*) MDM_TM_ENDFAIL)=(kal_uint32)(0x1));
#define MDM_TM_END_SUCC_WRITE (*((volatile kal_uint32*) MDM_END_SUCC)=(kal_uint32)(0x1));
#define MDM_STR0_WRITE(char_write) (*((volatile kal_uint32*) MDM_TM_STR0)=char_write);
#define MDM_TM_STR_CLEAR_WRITE(clear_buffer_num) (*((volatile kal_uint32*) MDM_TM_STR_CLEAR)=(kal_uint32)clear_buffer_num);
#define MDM_TM_STR_DISPLAY_WRITE(display_buffer_num) (*((volatile kal_uint32*) MDM_TM_STR_DISPLAY)=(kal_uint32)display_buffer_num);
#endif


#if !defined(__COSIM_BYPASS_DRV__)
/*
 * Macro: INT_Trace_Enter(trc_id, , is_tst_duration)
 *      trc_id: trace id, for TSID and SST
 *      is_tst_duration: record duration or not
 */
#define INT_Trace_Enter(trc_id, is_tst_duration) \
    do {  \
        if(is_tst_duration) { \
            print_bootup_trace_enter(SST_##trc_id); \
        } else { \
            print_bootup_trace(SST_##trc_id##_ENTER); \
        } \
        CCCI_BOOT_TS(trc_id); \
    } while(0)

/*
 * Macro: INT_Trace_Exit(trc_id, is_ts, is_tst_duration)
 *      trc_id: trace id, for TSID and SST
 *      is_ts: if TS_BEGIN and TS_END invoked
 *      is_tst_duration: record duration or not
 */
#define INT_Trace_Exit(trc_id, is_tst_duration) \
    do {  \
        if(is_tst_duration) { \
            print_bootup_trace_exit(SST_##trc_id); \
        } else { \
            print_bootup_trace(SST_##trc_id##_EXIT); \
        } \
    } while (0)

extern const kal_uint32 g_EMM_BOOTTRC_MAGIC_ADDR;
extern const kal_uint32 g_EMM_BOOTTRC_INDEX_ADDR;

#define INT_TRC_C(index) \
    do {  \
        *((kal_uint32 *)g_EMM_BOOTTRC_MAGIC_ADDR)= INIT_MAGIC; \
        *((kal_uint32 *)g_EMM_BOOTTRC_INDEX_ADDR)= index; \
    } while (0)

#else
/* For RTL CoSim, output trace log by MDM */
#define MDM_APP_INIT_MAGIC 0x50504100
#define INT_Trace_Enter(trc_id, is_tst_duration) \
    do {  \
        MDM_INT32_WRITE(MDM_APP_INIT_MAGIC+BOOT_##trc_id); \
    } while (0)

#define INT_Trace_Exit(trc_id, is_tst_duration)

#endif
/*************************************************************************
  * Bootup trace to CCCI share memory
  *************************************************************************/
extern kal_uint32 INC_Init_Step;

#if defined(__CR4__) && defined(__SP_BOOTTRC_ENABLE__)
#define CCCI_BOOT_TS(trc_id) \
        EMM_WriteBootupTrace((kal_uint32)BOOT_##trc_id, MCU_PMU_ReadCounter(PMU_CYCLE_COUNTER)); \
        INC_Init_Step = (kal_uint32)(((*(volatile kal_uint16 *)g_EMM_BOOTTRC_INDEX_ADDR)<<16)+(kal_uint16)BOOT_##trc_id); \
        EMM_WriteDbgInfo(EMM_BOOTUP_STEP, &INC_Init_Step);

#define TASK_Trace(task_index) \
        EMM_WriteBootupTrace((kal_uint32)task_index, MCU_PMU_ReadCounter(PMU_CYCLE_COUNTER));
#else
#define CCCI_BOOT_TS(trc_id)
#define TASK_Trace(task_index)
#endif


/*************************************************************************
  * Bootup trace to Catcher
  *************************************************************************/
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)

/*
 * NoteXXX:
 *          (1) Use print_trace(_with_info)() instead of print_bootup_trace(_with_info)()
 *          after TST task init
 *          (2) xxx_enter() and xxx_exit() should be used in a pair
 *          (3) xxx_enter() and xxx_exit() are invalid before TDMA timer is init
 */

#define print_bootup_trace(i) \
        do {  \
            kal_bootup_trace(TRACE_INFO, i); \
        } while (0)

#define print_bootup_trace_enter(i) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_current_time(); \
            kal_bootup_trace(TRACE_INFO, i##_ENTER); \
        } while (0)

#define print_bootup_trace_exit(i) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_duration_ms(init_duration); \
            kal_bootup_trace(TRACE_INFO, i##_EXIT, init_duration); \
        } while (0)

#define print_trace(i) \
        do {  \
            kal_trace(TRACE_INFO, i); \
        } while (0)

#define print_bootup_trace_with_info_enter(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_current_time(); \
            kal_bootup_trace(TRACE_INFO, i##_ENTER, info); \
        } while (0)

#define print_bootup_trace_with_info_exit(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_duration_ms(init_duration); \
            kal_bootup_trace(TRACE_INFO, i##_EXIT, info, init_duration); \
        } while (0)

#define print_trace_with_info_enter(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_current_time(); \
            kal_trace(TRACE_INFO, i##_ENTER, info); \
        } while (0)

#define print_trace_with_info_exit(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_duration_ms(init_duration); \
            kal_trace(TRACE_INFO, i##_EXIT, info, init_duration); \
        } while (0)

#define print_boot_mode(m) \
        do {  \
            extern void INT_printBootMode(void); \
            INT_printBootMode(); \
        } while (0)
#else /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */
#define print_bootup_trace(i)
#define print_bootup_trace_enter(i)
#define print_bootup_trace_exit(i)
#define print_trace(i)
#define print_bootup_trace_with_info_enter(i, info)
#define print_bootup_trace_with_info_exit(i, info)
#define print_trace_with_info_enter(i, info)
#define print_trace_with_info_exit(i, info)
#define print_boot_mode(m)
#endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

#endif	/* _INIT_TRC_API_H */

