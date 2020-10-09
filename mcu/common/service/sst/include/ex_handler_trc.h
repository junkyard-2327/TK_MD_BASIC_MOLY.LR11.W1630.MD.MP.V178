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
 *   ex_handler_trc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines exception debugging trace.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

    TRC_MSG(SST_EXC_WATCHDOG_RESET_ENTER, "[EXC][COMMON] Enter Watchdog reset")
    TRC_MSG(SST_EXC_WATCHDOG_RESET_EXIT, "[EXC][COMMON] Exit Watchdog reset")

    TRC_MSG(SST_EXC_WATCHDOG_RESET_EH_ENTER, "[EXC][COMMON]%s Enter Watchdog reset")
    TRC_MSG(SST_EXC_WATCHDOG_RESET_EH_EXIT, "[EXC][COMMON]%s Exit Watchdog reset")
    
    TRC_MSG(SST_EXC_WATCHDOG_DISABLE_ENTER, "[EXC][COMMON] Enter Watchdog disable")
    TRC_MSG(SST_EXC_WATCHDOG_DISABLE_EXIT, "[EXC][COMMON] Exit Watchdog disable")
 
    TRC_MSG(SST_EXC_FLUSH_LOGGING_PORT_EXIT, "[EXC][COMMON] Exit dhl_flush_logging_port_for_exception()")
    TRC_MSG(SST_EXC_NE_FLUSH_LOGGING_PORT_EXIT, "[EXC][COMMON][Nested] Exit dhl_flush_logging_port_for_exception()")

    TRC_MSG(SST_EXC_CCCI_HANDSHAKING_ENTER, "[EXC][COMMON] Enter ccci_exception_handshake()")
    TRC_MSG(SST_EXC_CCCI_HANDSHAKING_EXIT, "[EXC][COMMON] Exit ccci_exception_handshake()")

    TRC_MSG(SST_EXC_RESET_HARDWARE_ENTER, "[EXC][COMMON] Enter ex_reset_hw()")
    TRC_MSG(SST_EXC_RESET_HARDWARE_EXIT, "[EXC][COMMON] Exit ex_reset_hw()")
    
    TRC_MSG(SST_EXC_TL1_FORCESTALL_ENTER, "[EXC][COMMON] Enter TL1_ForceStall()")
    TRC_MSG(SST_EXC_TL1_FORCESTALL_EXIT, "[EXC][COMMON] Exit TL1_ForceStall()")

    TRC_MSG(SST_EXC_L1D_PAUSEDSP_ENTER, "[EXC][COMMON] Enter L1D_PauseDSP()")
    TRC_MSG(SST_EXC_L1D_PAUSEDSP_EXIT, "[EXC][COMMON] Exit L1D_PauseDSP()")

    TRC_MSG(SST_EXC_L1AUDIO_RESETDEVICE_ENTER, "[EXC][COMMON] Enter L1Audio_ResetDevice()")
    TRC_MSG(SST_EXC_L1AUDIO_RESETDEVICE_EXIT, "[EXC][COMMON] Exit L1Audio_ResetDevice()")

    TRC_MSG(SST_EXC_SLA_EXCEPTIONLOGGING_ENTER, "[EXC][COMMON] Enter SLA_ExceptionLogging()")
    TRC_MSG(SST_EXC_SLA_EXCEPTIONLOGGING_EXIT, "[EXC][COMMON] Exit SLA_ExceptionLogging()")
    
    TRC_MSG(SST_EXC_SLA_GETASMELMINFO_ENTER, "[EXC][COMMON] Enter SLA_RetrieveASMELMInfo()")
    TRC_MSG(SST_EXC_SLA_GETASMELMINFO_EXIT, "[EXC][COMMON] Exit SLA_RetrieveASMELMInfo()")
    
    TRC_MSG(SST_EXC_PLLDUMP_ENTER, "[EXC][COMMON] Enter PLL_exception_dump()")
    TRC_MSG(SST_EXC_PLLDUMP_EXIT, "[EXC][COMMON] Exit PLL_exception_dump()")
    
    TRC_MSG(SST_EXC_DUMP_SLAVE_LOG_ENTER, "[EXC][COMMON] Enter dhl_cc_exception_dump_slave_log()")
    TRC_MSG(SST_EXC_DUMP_SLAVE_LOG_EXIT, "[EXC][COMMON] Exit dhl_cc_exception_dump_slave_log()")
    TRC_MSG(SST_EXC_NE_DUMP_SLAVE_LOG_ENTER, "[EXC][COMMON][Nested] Enter dhl_cc_exception_dump_slave_log()")
    TRC_MSG(SST_EXC_NE_DUMP_SLAVE_LOG_EXIT, "[EXC][COMMON][Nested] Exit dhl_cc_exception_dump_slave_log()")

    TRC_MSG(SST_EXC_HS_ENTER, "[EXC][COMMON] Enter ex_int_cc_handshake(%d)")
    TRC_MSG(SST_EXC_HS_EXIT, "[EXC][COMMON] Exit ex_int_cc_handshake(%d)")

    TRC_MSG(SST_EXC_OUTPUT_CADEFA_ENTER, "[EXC][COMMON] Enter ex_cadefa()")
    TRC_MSG(SST_EXC_OUTPUT_CADEFA_EXIT, "[EXC][COMMON] Exit ex_cadefa()")

    TRC_MSG(SST_EXC_OUTPUT_L1CORE_CADEFA_ENTER, "[EXC][COMMON] Enter ex_l1core_cadefa()")
    TRC_MSG(SST_EXC_OUTPUT_L1CORE_CADEFA_EXIT, "[EXC][COMMON] Exit ex_l1core_cadefa()")
    
    TRC_MSG(SST_EXC_OUTPUT_CS_CADEFA_ENTER, "[EXC][COMMON] Enter ex_sonic_cadefa()")
    TRC_MSG(SST_EXC_OUTPUT_CS_CADEFA_EXIT, "[EXC][COMMON] Exit ex_sonic_cadefa()")
    
    TRC_MSG(SST_EXC_OUTPUT_MD32_CADEFA_ENTER, "[EXC][COMMON] Enter ex_md32_cadefa()")
    TRC_MSG(SST_EXC_OUTPUT_MD32_CADEFA_EXIT, "[EXC][COMMON] Exit ex_md32_cadefa()")

    TRC_MSG(SST_EXC_OUTPUT_SPC_CADEFA_ENTER, "[EXC][COMMON] Enter ex_spc_cadefa()")
    TRC_MSG(SST_EXC_OUTPUT_SPC_CADEFA_EXIT, "[EXC][COMMON] Exit ex_spc_cadefa()")

    TRC_MSG(SST_EXC_INVOKE_SST_ENGINE_ENTER, "[EXC][COMMON] Enter INT_InvokeSSTEngine()")
    TRC_MSG(SST_EXC_INVOKE_SST_ENGINE_EXIT, "[EXC][COMMON] Exit INT_InvokeSSTEngine()")
    
    TRC_MSG(SST_EXC_EMM_WRITE_EX_RECORD_ENTER, "[EXC][COMMON] Enter EMM_Write_ExceptRecord()")
    TRC_MSG(SST_EXC_EMM_WRITE_EX_RECORD_EXIT, "[EXC][COMMON] Exit EMM_Write_ExceptRecord()")
    
    TRC_MSG(SST_EXC_SWLA_PRINT_LOWRAM_ENTER, "[EXC][COMMON] Enter SLA_Print_low_RAM_SWLA()")
    TRC_MSG(SST_EXC_SWLA_PRINT_LOWRAM_EXIT, "[EXC][COMMON] Exit SLA_Print_low_RAM_SWLA()")

    TRC_MSG(SST_EXC_OUTPUT_EXCEPTION_RECORD_ENTER, "[EXC][COMMON] Enter ex_output_log()")
    TRC_MSG(SST_EXC_OUTPUT_EXCEPTION_RECORD_EXIT, "[EXC][COMMON] Exit ex_output_log()")
    
    TRC_MSG(SST_EXC_OUTPUT_CS_EXCEPTION_RECORD_ENTER, "[EXC][COMMON] Enter ex_output_sonic_log()")
    TRC_MSG(SST_EXC_OUTPUT_CS_HS_FAILED, "sonic HS failed [%d]")
    TRC_MSG(SST_EXC_OUTPUT_CS_EXCEPTION_RECORD_EXIT, "[EXC][COMMON] Exit ex_output_sonic_log()")
    
    TRC_MSG(SST_EXC_OUTPUT_MD32_EXCEPTION_RECORD_ENTER, "[EXC][COMMON] Enter ex_output_md32_log()")
    TRC_MSG(SST_EXC_OUTPUT_MD32_HS_FAILED, "md32 HS failed [%d]")
    TRC_MSG(SST_EXC_OUTPUT_MD32_EXCEPTION_RECORD_EXIT, "[EXC][COMMON] Exit ex_output_md32_log()")
    
    TRC_MSG(SST_EXC_OUTPUT_SPC_EXCEPTION_RECORD_ENTER, "[EXC][COMMON] Enter ex_output_spc_log()")
    TRC_MSG(SST_EXC_OUTPUT_SPC_HS_FAILED, "spc HS failed [%d]")
    TRC_MSG(SST_EXC_OUTPUT_SPC_EXCEPTION_RECORD_EXIT, "[EXC][COMMON] Exit ex_output_spc_log()")

    TRC_MSG(SST_EXC_PASS_CCCI_EXCINFO_ENTER, "[EXC][COMMON] Enter ccci_exception_info_passed()")
    TRC_MSG(SST_EXC_PASS_CCCI_EXCINFO_EXIT, "[EXC][COMMON] Exit ccci_exception_info_passed()")

    TRC_MSG(SST_EXC_FLC_DEBUG_INFO_ENTER, "[EXC][COMMON] Enter flc2_debug_assert_callback()")
    TRC_MSG(SST_EXC_FLC_DEBUG_INFO_EXIT, "[EXC][COMMON] Exit flc2_debug_assert_callback()")

    TRC_MSG(SST_EXC_RMPU_DEBUG_INFO_ENTER, "[EXC][COMMON] Enter emimpu_dump_status()")
    TRC_MSG(SST_EXC_RMPU_DEBUG_INFO_EXIT, "[EXC][COMMON] Exit emimpu_dump_status()")

    TRC_MSG(SST_EXC_INIT_FDD_TABLE_ENTER, "[EXC][COMMON] Enter Initialize_FDD_tables()")
    TRC_MSG(SST_EXC_INIT_FDD_TABLE_EXIT, "[EXC][COMMON] Exit Initialize_FDD_tables()")

    TRC_MSG(SST_EXC_SAVE_EXCEPTION_RECORD_ENTER, "[EXC][COMMON] Enter ex_save_log()")
    TRC_MSG(SST_EXC_SAVE_EXCEPTION_RECORD_EXIT, "[EXC][COMMON] Exit ex_save_log()")

    TRC_MSG(SST_EXC_FS_UNLOCK_ALL_ENTER, "[EXC][COMMON] Enter FS_UnlockAll()")
    TRC_MSG(SST_EXC_FS_UNLOCK_ALL_EXIT, "[EXC][COMMON] Exit FS_UnlockAll()")

    TRC_MSG(SST_EXC_FS_SHUTDOWN_ENTER, "[EXC][COMMON] Enter FS_ShutDown()")
    TRC_MSG(SST_EXC_FS_SHUTDOWN_EXIT, "[EXC][COMMON] Exit FS_ShutDown()")

    TRC_MSG(SST_EXC_NVRAM_WRITE_EXC_ENTER, "[EXC][COMMON] Enter nvram_write_exception(%d, 0x%x, 0x%x)")
    TRC_MSG(SST_EXC_NVRAM_WRITE_EXC_EXIT, "[EXC][COMMON] Exit nvram_write_exception()")
    
    TRC_MSG(SST_EXC_EMM_WRITE_ENTER, "[EXC][COMMON] Enter EMM_Write_ExceptRecord()")
    TRC_MSG(SST_EXC_EMM_WRITE_EXIT, "[EXC][COMMON] Exit EMM_Write_ExceptRecord()")
    
    TRC_MSG(SST_EXC_RESET_EXCSP_ENTER, "[EXC][COMMON] Enter INT_ExceptionResetExcSP()")
    TRC_MSG(SST_EXC_RESET_EXCSP_EXIT, "[EXC][COMMON] Exit INT_ExceptionResetExcSP()")
    
    TRC_MSG(SST_EXC_CLEAN_RES_PROT_ENTER, "[EXC][COMMON] Enter ex_clean_res_prot()")
    TRC_MSG(SST_EXC_CLEAN_RES_PROT_EXIT, "[EXC][COMMON] Exit ex_clean_res_prot()")
    
    TRC_MSG(SST_EXC_UNGUARD_STACKSPACE_ENTER, "[EXC][COMMON] Enter kal_unguard_stack_space()")
    TRC_MSG(SST_EXC_UNGUARD_STACKSPACE_EXIT, "[EXC][COMMON] Exit kal_unguard_stack_space()")

    TRC_MSG(SST_EXC_UNGUARD_L1TCM_ENTER, "[EXC][COMMON] Enter ex_unguard_l1core_tcm()")
    TRC_MSG(SST_EXC_UNGUARD_L1TCM_EXIT, "[EXC][COMMON] Exit ex_unguard_l1core_tcm()")

    TRC_MSG(SST_EXC_NESTED_PROCESS_ENTER, "[EXC][COMMON] Enter ex_nested_process()")
    TRC_MSG(SST_EXC_NESTED_PROCESS_EXIT, "[EXC][COMMON] Exit ex_nested_process()")
    
    TRC_MSG(SST_EXC_INIT_DUMP_ENTER, "[EXC][COMMON] Enter ex_init_dump()")
    TRC_MSG(SST_EXC_INIT_DUMP_EXIT, "[EXC][COMMON] Exit ex_init_dump()")

    TRC_MSG(SST_EXC_INIT_BBREG_DUMP_ENTER, "[EXC][COMMON] Enter ex_init_bbreg_dump()")
    TRC_MSG(SST_EXC_INIT_BBREG_DUMP_EXIT, "[EXC][COMMON] Exit ex_init_bbreg_dump()")
    
    TRC_MSG(SST_EXC_INIT_REAPPEAR_LOG_ENTER, "[EXC][COMMON] Enter ex_reappear_log()")
    TRC_MSG(SST_EXC_INIT_REAPPEAR_LOG_EXIT, "[EXC][COMMON] Exit ex_reappear_log()")

    TRC_MSG(SST_EXC_EX_REBOOT4MP_ENTER, "[EXC][COMMON] Enter ex_reboot4mp()")
    TRC_MSG(SST_EXC_EX_REBOOT4MP_EXIT, "[EXC][COMMON] Exit ex_reboot4mp()")

    TRC_MSG(SST_EXC_SYSMEM_TO_BE_DUMPED, "[EXC][COMMON] sys_mem_xxx.bin to be dumped [%d]: (0x%x, 0x%x)")
    TRC_MSG(SST_EXC_SLAVE_SYSMEM_TO_BE_DUMPED, "[EXC][COMMON] slave_sys_mem_0x%08x.bin to be dumped [%d]: (0x%x, 0x%x)")

    TRC_MSG(SST_EXC_HANDOVER2TST, "[EXC][COMMON] Handover to TST exception handler")
    
    TRC_MSG(SST_EXC_READY2REBOOT, "[EXC][COMMON] Ready to silent reboot")
    
    
    TRC_MSG(SST_EXC_BBREG_DUMP_COUNT, "[EXC][COMMON] BB register dump total count: %d")
    TRC_MSG(SST_EXC_PCORE_BBREG_DUMP_COUNT, "[EXC][COMMON][PCORE] BB register dump total count: %d")
    TRC_MSG(SST_EXC_L1CORE_BBREG_DUMP_COUNT, "[EXC][COMMON][L1CORE] BB register dump total count: %d")
    TRC_MSG(SST_EXC_BBREG_DUMP_OWNER, "[EXC][COMMON] BB register dump owner: %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c, count: %d")
    TRC_MSG(SST_EXC_BBREG_DUMP_CALLBACK_FUNC_ENTER, "[EXC][COMMON] Enter BB register dump callback, address: 0x%x")
    TRC_MSG(SST_EXC_BBREG_DUMP_CALLBACK_FUNC_EXIT, "[EXC][COMMON] Exit BB register dump callback, address: 0x%x")
    TRC_MSG(SST_EXC_BBREG_DUMP_SKIP, "[EXC][COMMON] Skip this dump")
    TRC_MSG(SST_EXC_BBREG_DUMP_TO_BE_DUMPED, "[EXC][COMMON] bb_mem_xxx.bin to be dumped [%d]: (0x%x, 0x%x, %d)")
    
    TRC_MSG(SST_EXC_L1CORE_BBREG_DUMP_OWNER, "[EXC][COMMON][L1CORE] BB register dump owner: %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c, count: %d")   
    TRC_MSG(SST_EXC_L1CORE_SKIP_BBREG_DUMP_OWNER, "[EXC][COMMON][L1CORE] Skip: BB register dump owner: %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c (due to l1core exception long time no response)")   
    TRC_MSG(SST_EXC_L1CORE_BBREG_DUMP_TO_BE_DUMPED, "[EXC][COMMON][L1CORE] bb_mem_xxx.bin to be dumped [%d]: (0x%x, 0x%x, %d)")
    
    TRC_MSG(SST_EXC_HANDLE_DUMP_REGION_ENTER, "[EXC][COMMON] Enter SST_HandleDumpRegion(addr=0x%08x, len=0x%x)")
    TRC_MSG(SST_EXC_HANDLE_DUMP_REGION_EXIT, "[EXC][COMMON] Exit SST_HandleDumpRegion(addr=0x%08x, len=0x%x, operation result=%s)")
    TRC_MSG(SST_EXC_HANDLE_DUMP_REGION_OP_CACHED, "[EXC][COMMON][L1CORE] SST_HandleDumpRegion: Do cache operation")
    TRC_MSG(SST_EXC_HANDLE_DUMP_REGION_L1CORE_STEP, "[EXC][COMMON][L1CORE] L1CORE Step Logging: 0x%8x")
    TRC_MSG(SST_EXC_HANDLE_DUMP_REGION_OP_TIMEOUT, "[EXC][COMMON]Timeout(> %dus): Start: %dus, End= %dus, Duration = %dus")
    
    TRC_MSG(SST_EXC_HANDLE_EMIMPU_OUTPUT_ADDR, "[EXC][EMIMPU] MasterID:%x(%s)  ViolationAddr:%x(%s)")
    TRC_MSG(SST_EXC_HANDLE_EMIMPU_OUTPUT_REGION, "[EXC][EMIMPU] Region:%d  Domain:%d   Out-of-Range:%d")

    TRC_MSG(SST_EXC_BBREG_OUTPUT, "[EXC][COMMON][BBREG_OUTPUT] address=0x%08x  value=0%08x, sub_idx=%d, fill_cnt=%d")
    TRC_MSG(SST_EXC_QUERY_BBREG_ENTER, "[EXC][COMMON]ex_query_bbreg_info(buf_ptr=0%08x, start_idx=%d, num=%d)")
    TRC_MSG(SST_EXC_QUERY_BBREG_EXIT, "[EXC][COMMON]ex_query_bbreg_info() return fill_cnt=%d")
    TRC_MSG(SST_EXC_QUERY_BBREG_SKIP, "[EXC][COMMON] skip_cnt(%d)+traverser->num(%d)+prv_fill_cnt(%d) <= start_idx(%d) => skip_cnt=%d")
    TRC_MSG(SST_EXC_COPY_BBREG_START_IDX, "[EXC][COMMON] COPY_BBREG start idx=%d")
    TRC_MSG(SST_EXC_QUERY_BBREG_UPDATE_SKIP, "[EXC][COMMON] prv_fill_cnt: %d, this traverser->num: %d")
    TRC_MSG(SST_EXC_SKIP_BBREG, "[EXC][COMMON] skip traverser->num(%d) - l1core no response")
