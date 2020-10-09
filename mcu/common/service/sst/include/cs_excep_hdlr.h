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
 *   dsp_excep_hdlr.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This file provides typedefs and definiton for PS index trace.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __CS_EXCEP_HDLR_H__
#define __CS_EXCEP_HDLR_H__

#include "kal_general_types.h"
#include "csdebug_pctrace_api.h"
#include "cs_ex_hdr_public.h"
#include "cs_excep_hdlr_format.h"

// ----------------- macro definition ---------------
#define CS_PC_TRACE_SIZE  (64*2)

#define CS_EXCEPTION_SYNC_TIME (0x100000)    // 100 subframes
/* sync. information with DSP core */
#define CS_EXCEPTION_EVENT_CTI (0x1) // !!CAUTION!! MUST sync. with DSP side CTI event bit definition

#define CS_EXCEPTION_PC_TRACE  (0x52544350)

#define CS_EXCEPTION_INFO_STR_LEN  (128)

/* MEMORY DUMP INFO */
#define CS_EXCEPTION_ADDR_MAP_ICC     (0x20636369)

#define CS_EXCEPTION_ADDR_MAP_IMC     (0x20636D69)

#define CS_EXCEPTION_ADDR_MAP_MPC     (0x2063706D)

#define CS_EXCEPTION_ADDR_MAP_ICM     (0x204D4349)

#define CS_EXCEPTION_ADDR_MAP_PM      (0x20204D50)

#define CS_EXCEPTION_ADDR_MAP_CRF     (0x20465243)

#define CS_EXCEPTION_ADDR_MAP_CSIF    (0x46495343)
	
#define CS_EXCEPTION_ADDR_MAP_SSIF0   (0x30305353)

#define CS_EXCEPTION_ADDR_MAP_SSIF1   (0x31305353)

#define CS_EXCEPTION_ADDR_MAP_SSIF2   (0x32305353)

#define CS_EXCEPTION_ADDR_MAP_HEADER  (0x594D454D)

#define CS_EXCEPTION_ADDR_MAP_END     (0x20444E45)

#define CS_EXCEPTION_MEMY_DUMP_SIZE   (14) // except PM

#define CS_EXCEPTION_CTI_ERROR_CODE   (0x0)

// ----------------- Sync step logging Definition -------------------
#define CS_SYNC_BEGIN    (0xABCD0001)

#define CS_SYNC_ICC      (0xABCD00AA)
#define CS_SYNC_IMC      (0xABCD00BB)
#define CS_SYNC_MPC      (0xABCD00CC)

#define CS_SYNC_END      (0xABCDABCD)

// ------------------ bus status dump --------------------------------
#define DBG_MMUBUS_STATUS_CONFIG    (8)
#define DBG_MMUBUS_SEL_OFFSET       (0x20)
#define DBG_MMUBUS_STAT_OFFSET      (0x90)

#define DBG_SMI_DUMP_CNT            (3)
#define DBG_SMI_DUMP_SIZE           (16)
#define DBG_SMI_DUMP_START_OFFSET   (0x400)

#define L1_BASE_MADDR_MMUSYS_BASE   (0xFE712000)
#define L1_BASE_MADDR_MMUSMI_BASE   (0xFE716000)

#define DSPBTDMA_NAME               (0x20414D44)
#define DBG_MMUBUS_NAME             (0x20554D4D)
#define DBG_SMI_NAME                (0x20494D53)


// ----------------- data type Definition -------------------
typedef struct {
    unsigned long dump_header;
    //unsigned long pctrace_dump_data[CS_CORE_NUMBER][CS_PC_TRACE_SIZE];
    PCTRACE_BUFFER  pctrace_dump_data;
} DSP_ASSERT_PC_TRACE_DUMP_T;

typedef enum
{
	CoreSonic_ICC_FAIL_BIT_MASK = (1<<0),
	CoreSonic_IMC_FAIL_BIT_MASK  = (1<<1),
	CoreSonic_MPC_FAIL_BIT_MASK  = (1<<2)
} CoreSonic_EX_CORE_BIT_MASK_TYPE;


typedef struct {
    unsigned long core_name;
    unsigned long addr_name;
    unsigned long addr_base;
    unsigned long addr_size;
} DSP_MEMORY_ADDR_SET_T;

typedef struct {
	unsigned long mem_header;
	DSP_MEMORY_ADDR_SET_T mem_addr_set[CS_EXCEPTION_MEMY_DUMP_SIZE];
    DSP_MEMORY_ADDR_SET_T mem_pm_addr_set[CS_CORE_NUMBER];
	unsigned long mem_end;
	
} DSP_MEMORY_ADDR_DUMP_T;

typedef struct {
    
    unsigned long dspdma_name;
    unsigned long icc_name;
    unsigned long icc_dspdma_reg[2];
    
    unsigned long imc_name;
    unsigned long imc_dspdma_reg[2];
    
    unsigned long mpc_name;
    unsigned long mpc_dspdma_reg[2];
    
    unsigned long dbg_mmubus_name;
    unsigned long dbg_mmubus_status_rdata[DBG_MMUBUS_STATUS_CONFIG];
    
    unsigned long dbg_smi_name;
    unsigned long dbg_smi_register_status[DBG_SMI_DUMP_CNT][DBG_SMI_DUMP_SIZE];
    
} DSP_DBG_BUS_STATUS_T;

// ----------------- function declaration -------------------
extern void INT_GetSonicBBMemoryInfo(void);

extern void INT_GetSonicDumpMemoryInfo(kal_uint32 **info, kal_uint32 *count);

extern kal_bool INT_SyncSonicExceptionInfo(void);

extern void INT_GetSonicExceptionRecord(CORESONIC_EXCEPTION_RECORD_T *record);

extern kal_bool INT_EnableSonicMemoryDump(void);

extern void INT_GetSonicBBMemoryInfo(void);

extern kal_uint32 INT_GetSonicFailCore(void);

extern kal_bool Sonic_IsSyncFinished(void);

extern kal_bool Sonic_RequestEMIFlush(void);

extern kal_bool Sonic_AckEMIFlushFinish(void);

#if defined(__L1CORE__)
extern void Exception_Bring_Up_Init_ICC(void);

extern void Exception_Bring_Up_Init_IMC(void);

extern void Exception_Bring_Up_Init_MPC(void);
#endif

#endif /* __CS_EXCEP_HDLR_H__ */
