/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *   cmif.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
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
  * $Revision$
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DRV_CMIF_L1CORE_H__
#define __DRV_CMIF_L1CORE_H__

#include "kal_public_api.h"
#include "kal_general_types.h"


/*******************************************************************************
  * Macros 
  *******************************************************************************/
#define CMIF_NULL                     NULL 
#define CMIF_ASSERT(expr)             ASSERT(expr)
#define CMIF_GET_RETURN_ADDRESS(a)    GET_RETURN_ADDRESS(a)

#define CMIF_CLZ(z)         __builtin_clz((z)) 
#define CMIF_GET_LSB(b)     (31 - CMIF_CLZ((b) & -(b)))

/*******************************************************************************
  * Enums 
  *******************************************************************************/
typedef enum CMIF_MD32_CORES_Enum{
    CMIF_MD32_BRP = 0,
    CMIF_MD32_DFE = 1,
    CMIF_MD32_RAKE = 2,
    CMIF_MD32_TOTAL_NUMBER = 3
}CMIF_MD32_Core_t;

#undef  irq_index
#undef  irq_name 
#undef  irq_entry_function 
#undef  irq_auto_eoi

#define irq_name(name)
#define irq_entry_function(fun)
#define irq_index(code)  code,
#define irq_auto_eoi(eoi)

typedef enum CMIF_CODE_C2M_U3G_BRP_Enum{
    #include "cmif_c2m_isr_config_u3g_brp.h"    
    CMIF_C2M_U3G_TOTAL_NUMBER_BRP
}CMIF_CODE_C2M_U3G_BRP;

typedef enum CMIF_CODE_C2M_U3G_DFE_Enum{
    #include "cmif_c2m_isr_config_u3g_dfe.h"    
    CMIF_C2M_U3G_TOTAL_NUMBER_DFE
}CMIF_CODE_C2M_U3G_DFE;

typedef enum CMIF_CODE_C2M_U3G_RAKE_Enum{
    #include "cmif_c2m_isr_config_u3g_rake.h"    
    CMIF_C2M_U3G_TOTAL_NUMBER_RAKE
}CMIF_CODE_C2M_U3G_RAKE;

/* U4G */
typedef enum CMIF_CODE_C2M_U4G_BRP_Enum{
    #include "cmif_c2m_isr_config_u4g_brp.h"    
    CMIF_C2M_U4G_TOTAL_NUMBER_BRP
}CMIF_CODE_C2M_U4G_BRP;

typedef enum CMIF_CODE_C2M_U4G_DFE_Enum{
    #include "cmif_c2m_isr_config_u4g_dfe.h"    
    CMIF_C2M_U4G_TOTAL_NUMBER_DFE
}CMIF_CODE_C2M_U4G_DFE;

typedef enum CMIF_CODE_M2C_U3G_BRP_Enum{
    #include "cmif_m2c_isr_config_u3g_brp.h"    
    CMIF_M2C_U3G_TOTAL_NUMBER_BRP
}CMIF_CODE_M2C_U3G_BRP;

typedef enum CMIF_CODE_M2C_U3G_DFE_Enum{
    #include "cmif_m2c_isr_config_u3g_dfe.h"    
    CMIF_M2C_U3G_TOTAL_NUMBER_DFE
}CMIF_CODE_M2C_U3G_DFE;

typedef enum CMIF_CODE_M2C_U3G_RAKE_Enum{
    #include "cmif_m2c_isr_config_u3g_rake.h"    
    CMIF_M2C_U3G_TOTAL_NUMBER_RAKE
}CMIF_CODE_M2C_U3G_RAKE;

/* U4G */
typedef enum CMIF_CODE_M2C_U4G_BRP_Enum{
    #include "cmif_m2c_isr_config_u4g_brp.h"    
    CMIF_M2C_U4G_TOTAL_NUMBER_BRP
}CMIF_CODE_M2C_U4G_BRP;

typedef enum CMIF_CODE_M2C_U4G_DFE_Enum{
    #include "cmif_m2c_isr_config_u4g_dfe.h"    
    CMIF_M2C_U4G_TOTAL_NUMBER_DFE
}CMIF_CODE_M2C_U4G_DFE;


/*******************************************************************************
 * Function prototypes
 *******************************************************************************/
/**
  *  CMIF Init: Register Interrupt
  *  It would register IRQ for
  *     - M2C BRP U3G  
  *     - M2C RAKE U3G
  *     - M2C DFE U3G
  *     - M2C BRP U4G  
  *     - M2C DFE U4G
  */
void CMIF_Init();


/**
  *  CMIF Interrupt: CR4 trigger MD32 
  *
  *  @param[in]  code  trigger interrupt code. 0 <= code <= 31 
  *  @param[in]  core  MD32 core type
  *  @return no return
  *
  **/
void CMIF_C2M_SWI_SW_U3G(cmif_uint8 code, CMIF_MD32_Core_t core);
void CMIF_C2M_SWI_SW_U4G(cmif_uint8 code, CMIF_MD32_Core_t core);


/**
  *  Get CMIF Status register value
  *  @param[in]    core    MD32 core type
  *  @param[out]   mask    the value of status register(s)
  *
  **/
void CMIF_M2C_STATUS_U3G(CMIF_MD32_Core_t core, CMIF_Mask_t* mask);
void CMIF_M2C_STATUS_U4G(CMIF_MD32_Core_t core, CMIF_Mask_t* mask);
void CMIF_C2M_STATUS_U3G(CMIF_MD32_Core_t core, CMIF_Mask_t* mask);
void CMIF_C2M_STATUS_U4G(CMIF_MD32_Core_t core, CMIF_Mask_t* mask);

cmif_uint32 CMIF_C2M_STATUS_U3G_READ(CMIF_MD32_Core_t core);
cmif_uint32 CMIF_C2M_STATUS_U4G_READ(CMIF_MD32_Core_t core);
cmif_uint32 CMIF_M2C_STATUS_U3G_READ(CMIF_MD32_Core_t core);
cmif_uint32 CMIF_M2C_STATUS_U4G_READ(CMIF_MD32_Core_t core);

cmif_bool CMIF_MD32AllowPowerDown(CMIF_MD32_Core_t core);


/**
  *   When the `irq_auto_eoi()` attribute is `CMIF_FALSE`
  *   Users could call these function to clean the interrupt bit 
  */
void CMIF_M2C_EOI_U3G(cmif_uint8 code, CMIF_MD32_Core_t core);
void CMIF_M2C_EOI_U4G(cmif_uint8 code, CMIF_MD32_Core_t core);

#if defined(__MD32S_CMIF_DRV_TEST__)

#define CMIF_DRV_TET_SYNC_OFFSET 0x30

typedef void (*CMIF_Status_Func_t)(CMIF_MD32_Core_t core, CMIF_Mask_t* mask);
typedef void (*CMIF_SWI_Func_t)(cmif_uint8 code, CMIF_MD32_Core_t core);
typedef void (*CMIF_EOI_Func_t)(cmif_uint8 code, CMIF_MD32_Core_t core);

typedef struct{
    volatile cmif_uint32* send_set;
    volatile cmif_uint32* send_status;
    volatile cmif_uint32* receive_clr;
    volatile cmif_uint32* receive_status;
    volatile cmif_uint32* sync;

    CMIF_SWI_Func_t    send_func;
    CMIF_Status_Func_t send_stats_func;
    CMIF_EOI_Func_t    receive_clr_func;
    CMIF_Status_Func_t receive_stats_func;

    CMIF_MD32_Core_t  md32_core;
}CMIF_Ctrl_t;
#endif /* __MD32S_CMIF_DRV_TEST__ */


/*******************************************************************************
 * MD32 Debug information 
 *******************************************************************************/
#define MD32_MPU_MAX_REGION_SIZE                    4

#define MOS_EX_STACK_SIZE                           4096

#define MOS_EX_CMIF_BEGIN_OFFSET                    0x50
#define MOS_EX_CMIF_MAX_SIZE                        (0x130 - MOS_EX_CMIF_BEGIN_OFFSET)
#define MOS_EX_CMIF_FILL_FINISH_PATTERN             0xFD32FD32
#define MOS_EX_CMIF_FILENAME_SIZE                   32
                                                   
#define MOS_EX_COMMON_SIZE                          8 
#define MOS_EX_COMMON_ADDR_OFFSET_R1                0x0
#define MOS_EX_COMMON_ADDR_OFFSET_R2                0x4

#define MOS_EX_NEST_EXCEPTION_VIC_MASK              0x0001000B 

#define MOS_EX_ASSERT_LINE_TYPE_NUMBER              0x1
#define MOS_EX_ASSERT_EXT_TYPE_NUMBER               0x2
#define MOS_EX_FATAL_ERROR_TYPE_NUMBER              0x3

#define MOS_EX_ABNORMAL_RESET_EXCEPTION_CODE        0x000
#define MOS_EX_INSTRUCTION_ABORT_EXCEPTION_CODE     0x010
#define MOS_EX_DATA_ABORT_EXCEPTION_CODE            0x030
#define MOS_EX_PMU_EXCEPTION_CODE                   0x0E0
#define MOS_EX_CTI_EXCEPTION_CODE                   0x120

#define MOS_EX_REGS_R0_OFFSET                       0x00
#define MOS_EX_REGS_R1_OFFSET                       0x04
#define MOS_EX_REGS_R2_OFFSET                       0x08
#define MOS_EX_REGS_R3_OFFSET                       0x0C
#define MOS_EX_REGS_R4_OFFSET                       0x10
#define MOS_EX_REGS_R5_OFFSET                       0x14
#define MOS_EX_REGS_R6_OFFSET                       0x18
#define MOS_EX_REGS_R7_OFFSET                       0x1C
#define MOS_EX_REGS_R8_OFFSET                       0x20
#define MOS_EX_REGS_R9_OFFSET                       0x24
#define MOS_EX_REGS_R10_OFFSET                      0x28
#define MOS_EX_REGS_R11_OFFSET                      0x2C
#define MOS_EX_REGS_R12_OFFSET                      0x30
#define MOS_EX_REGS_R13_OFFSET                      0x34
#define MOS_EX_REGS_R14_OFFSET                      0x38
#define MOS_EX_REGS_R15_OFFSET                      0x3C
#define MOS_EX_REGS_A0H_OFFSET                      0x40
#define MOS_EX_REGS_A0L_OFFSET                      0x44
#define MOS_EX_REGS_LC0_OFFSET                      0x48
#define MOS_EX_REGS_LC1_OFFSET                      0x4C
#define MOS_EX_REGS_LC2_OFFSET                      0x50
#define MOS_EX_REGS_LS0_OFFSET                      0x54
#define MOS_EX_REGS_LS1_OFFSET                      0x58
#define MOS_EX_REGS_LS2_OFFSET                      0x5C
#define MOS_EX_REGS_LE0_OFFSET                      0x60
#define MOS_EX_REGS_LE1_OFFSET                      0x64
#define MOS_EX_REGS_LE2_OFFSET                      0x68
#define MOS_EX_REGS_LF_OFFSET                       0x6C
#define MOS_EX_REGS_IPC_OFFSET                      0x70
#define MOS_EX_REGS_ISR_OFFSET                      0x74
#define MOS_EX_REGS_SR_OFFSET                       0x78
#define MOS_EX_REGS_SIZE                            0x7C

#define MOS_EX_REGS_R0_INDEX                        0
#define MOS_EX_REGS_R1_INDEX                        1
#define MOS_EX_REGS_R2_INDEX                        2 
#define MOS_EX_REGS_R3_INDEX                        3 
#define MOS_EX_REGS_R4_INDEX                        4 
#define MOS_EX_REGS_R5_INDEX                        5 
#define MOS_EX_REGS_R6_INDEX                        6 
#define MOS_EX_REGS_R7_INDEX                        7 
#define MOS_EX_REGS_R8_INDEX                        8 
#define MOS_EX_REGS_R9_INDEX                        9 
#define MOS_EX_REGS_R10_INDEX                       10 
#define MOS_EX_REGS_R11_INDEX                       11 
#define MOS_EX_REGS_R12_INDEX                       12 
#define MOS_EX_REGS_R13_INDEX                       13 
#define MOS_EX_REGS_R14_INDEX                       14 
#define MOS_EX_REGS_R15_INDEX                       15

/**
  * exception log data structure
  *
  **/
typedef enum{
    MD32_DEBUG_EX_NONE,
    MD32_DEBUG_ASSERT_LINE = MOS_EX_ASSERT_LINE_TYPE_NUMBER,
    MD32_DEBUG_ASSERT_EXT  = MOS_EX_ASSERT_EXT_TYPE_NUMBER,
    MD32_DEBUG_FATAL_ERROR = MOS_EX_FATAL_ERROR_TYPE_NUMBER,
    MD32_DEBUG_EX_END=0xff
}MD32_EX_TYPE;


typedef struct{
    cmif_uint32   r[16];   /* r0 ~ r15 */
            /* r14: stack pointer*/
            /* r15: link registers (caller address)*/
    cmif_uint32   a0h;
    cmif_uint32   a0l;
    cmif_uint32   lc[3];
    cmif_uint32   ls[3];
    cmif_uint32   le[3];
    cmif_uint32   lf;
    cmif_uint32   ipc;
    cmif_uint32   isr;
    cmif_uint32   sr;
}MD32_EX_Regs;


typedef struct{
    cmif_uint32 context_id;
    cmif_uint32 mode;
    cmif_uint32 overflow;
    cmif_uint32 trace_top_index;
    cmif_uint32 trace[64];
}MD32_EX_TraceInfo;


typedef struct{
    cmif_char*    expr;
    cmif_char*    file;
    cmif_uint32   line;
    cmif_uint32   code[3];
}MD32_EX_AssertParam;


typedef struct{
    cmif_uint32 code[2];

    cmif_uint32 ifabtpc;
    cmif_uint32 ifabtcau;

    cmif_uint32 daabtcau;
    cmif_uint32 daabtpc;
    cmif_uint32 daabtad;
    cmif_uint32 daabtsp;
}MD32_EX_FatalErrorParam;


typedef union{
    MD32_EX_AssertParam assert_param;
    MD32_EX_FatalErrorParam fatal_error_param;
}MD32_EX_Params;


typedef struct{
    cmif_uint32 high[MD32_MPU_MAX_REGION_SIZE];
    cmif_uint32 low[MD32_MPU_MAX_REGION_SIZE];
}MD32_EX_MPUConfig;


typedef struct{
    cmif_uint32 mask;
    cmif_uint32 pending;
}MD32_EX_VICInfo;


typedef struct{
    cmif_uint32 bm31_0;
    cmif_uint32 bm63_32;
}MD32_EX_CIRQMask;


typedef struct{
    MD32_EX_CIRQMask mask;
    MD32_EX_CIRQMask pending;
}MD32_EX_CIRQInfo;


typedef struct{
    cmif_uint32 interrupt_count;
    MD32_EX_VICInfo vic;
    MD32_EX_CIRQInfo cirq;
}MD32_EX_IRQInfo;


typedef struct{
    cmif_uint32 ms_high;  // 40 bits micro-second counter
    cmif_uint32 ms_low;
}MD32_EX_Time;


typedef struct{
    cmif_char* release_verno;
    cmif_char* release_hal_verno;
    cmif_char* release_hw_ver;
    cmif_char* build_date_time;
    cmif_char* release_build;
    cmif_char* release_branch;
    cmif_char* release_flavor;
}MD32_EX_Verno; // software version


typedef struct{
    MD32_EX_TYPE      ex_type;           /* offset: +0x0,   length: 4   */ 
    MD32_EX_Regs*     ex_regs;           /* offset: +0x4,   length: 4   */ 
    MD32_EX_TraceInfo ex_trace_buffer;   /* offset: +0x8,   length: 320 */ 
    MD32_EX_Params    ex_params;         /* offset: +0x148, length: 56  */   
    MD32_EX_MPUConfig ex_mpu;            /* offset: +0x180, length: 32  */ 
    MD32_EX_IRQInfo   ex_irq;            /* offset: +0x1A0, length: 28  */
    MD32_EX_Time      ex_time;           /* offset: +0x1BC, length: 8   */
    MD32_EX_Verno     ex_verno;          /* offset: +0x1C4, length: 28  */
}MD32_EX_Log;


typedef struct{
    MD32_EX_TYPE      ex_type;           /* offset: +0x0,   length: 4   */ 
    MD32_EX_Regs*     ex_regs;           /* offset: +0x4,   length: 4   */ 
    MD32_EX_TraceInfo ex_trace_buffer;   /* offset: +0x8,   length: 320 */ 
    MD32_EX_Params    ex_params;         /* offset: +0x148, length: 56  */   
}MD32_EX_NestedLog;


// Use 45 words, max ((0x130 - 0x50) >> 2)) words
typedef struct{
    cmif_uint32 finish_fill;                                 /* 0x50 */
    MD32_EX_TYPE     ex_type;                                /* 0x54 */
    cmif_char   ex_filename[MOS_EX_CMIF_FILENAME_SIZE];      /* 0x58 */
    cmif_uint32 ex_line;                                     /* 0x78 */
    cmif_uint32 ex_code[3];                                  /* 0x7C */
                                                                      
    cmif_uint32 ifabtpc;                                     /* 0x88 */
    cmif_uint32 ifabtcau;                                    /* 0x8C */
                                                                      
    cmif_uint32 daabtcau;                                    /* 0x90 */
    cmif_uint32 daabtpc;                                     /* 0x94 */
    cmif_uint32 daabtad;                                     /* 0x98 */
    cmif_uint32 daabtsp;                                     /* 0x9C */

    cmif_uint32 ex_log_mem_addr;                             /* 0x100 */
}MD32_EX_CMIF_Log;

#endif
