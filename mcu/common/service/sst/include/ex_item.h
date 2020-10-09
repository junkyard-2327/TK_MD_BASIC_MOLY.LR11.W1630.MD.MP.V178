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
 *   ex_item.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *	Header file for exception handling
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _EX_ITEM_H
#define _EX_ITEM_H

#if !defined(__OFFLINE_EX_LOG_PARSER__)
#include "kal_general_types.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "kal_public_defs.h"
#include "ex_public.h"
#else
#include "ex_item_types.h"
#endif /*__OFFLINE_EX_LOG_PARSER__*/


/*******************************************************************************
 * Enum Type Definition
 *******************************************************************************/

typedef enum
{
    /* Fatal Error */
    INVAID_EXCEPTION                =    0,
    UNDEF_EXCEPTION                 =    1,
    SWI_EXCEPTION                   =    2,
    PREFETCH_EXCEPTION              =    3,
    DATAABORT_EXCEPTION             =    4,
    STACKACCESS_EXCEPTION           =    5,   /* stack isolation */
    SYS_FATALERR_EXT_TASK_EXCEPTION =    6,
    SYS_FATALERR_EXT_BUF_EXCEPTION  =    7,
    /* Assertion */
    ASSERT_FAIL_EXCEPTION           = 0x10,
    ASSERT_DUMP_EXTENDED_RECORD     = 0x11,
    ASSERT_FAIL_NATIVE              = 0x12,
    /* cross core triggered */
    CC_INVALID_EXCEPTION            = 0x20,
    CC_PCORE_EXCEPTION              = 0x21,
    CC_L1CORE_EXCEPTION             = 0x22,
    CC_CS_EXCEPTION                 = 0x23,
    CC_MD32_EXCEPTION               = 0x24,
    CC_C2K_EXCEPTION                = 0x25,
    CC_ARM7_EXCEPTION               = 0x26,
    /* HW triggered */
    EMI_MPU_VIOLATION_EXCEPTION     = 0x30,
    
    NUM_EXCEPTION
#if !defined(__OFFLINE_EX_LOG_PARSER__)
} exception_type;
#else
} exception_type_format;
#endif

typedef enum
{
    Healthy = 0,
    InternalSRAMCorrupted = 1,
    SystemStackCorrupted = 2,
    TaskStackCorrupted = 3,
    HISRStackCorrupted = 4,
    VectorTableCorrupted = 5,
    L2SRAMCorrupted = 6,
    SharedInternalSRAMorrupted = 7,
#if !defined(__OFFLINE_EX_LOG_PARSER__)
} EX_DIAGNOSIS_T;
#else
} EX_DIAGNOSIS_T_FORMAT;
#endif

typedef enum
{
    EX_AUTO_STEP                              = 0,
    EX_BEGIN                                  = 1,
    // init stage
    EX_INIT_CORE_BEGIN                        = 0x10,
    EX_INIT_CORE_DONE                         = 0x2F,
    EX_INIT_PCMON_DONE                        = 0x3F,
    EX_INIT_BUS_DONE                          = 0x4F,
    EX_INIT_MPU_DONE                          = 0x5F,
    EX_INIT_DSM_DONE                          = 0x65,
    EX_INIT_SONIC_DONE                        = 0x7F, //l1core
    EX_INIT_SPC_DONE                          = 0x8F, //pcore
    EX_INIT_MD32_DONE                         = 0x9F, //l1core
    // HS1
    EX_CC_INT_HS1                             = 0x100,
    EX_CC_INT_HS1_DONE                        = 0x10F,
    
    EX_POST_INIT_CORE                         = 0x110,
    EX_POST_INIT_CORE_DONE                    = 0x15F,

    EX_DEFINE_MAIN_REASON                     = 0x170,
    EX_DEFINE_MAIN_REASON_DONE                = 0x1CF,
    
    EX_POST_INIT_EXRECORD_DONE                = 0x1E0,

    // HS2
    EX_CC_INT_HS2                             = 0x1EF,
    EX_CC_INT_HS2_DONE                        = 0x1FF,
    
    // preprocess
    EX_PREPROCESS                             = 0x200,

    EX_INIT_CCLOG_DONE                        = 0x210,
    EX_L1CORE_STOP_GDMA_DONE                  = 0x215,
    EX_SYSTEM_PREPROCESS_BEGIN                = 0x220,
    EX_PREPROCESS_DONE                        = 0x23F,
    // external communication
    EX_CC_EXT_COMM                            = 0x240,
    EX_CC_EXT_COMM_OPEN_PORT                  = 0x250,
    EX_CC_EXT_COMM_OPEN_PORT_DONE             = 0x27F,
    EX_CC_EXT_COMM_CCCI_HANDSHAKE             = 0x280,
    EX_CC_EXT_COMM_CCCI_HANDSHAKE_DONE        = 0x2AF,
    EX_CC_EXT_COMM_FLUSH_PORT                 = 0x2B0,
    EX_CC_EXT_COMM_FLUSH_PORT_DSP_FLUSH_MD32     = 0x2C0, 
    EX_CC_EXT_COMM_FLUSH_PORT_DSP_FLUSH_CS       = 0x2C4, 
    EX_CC_EXT_COMM_FLUSH_PORT_DSP_FLUSH_MD32_ACK = 0x2C8, 
    EX_CC_EXT_COMM_FLUSH_PORT_DSP_FLUSH_CS_ACK   = 0x2CC, 
    EX_CC_EXT_COMM_FLUSH_PORT_DSP_FLUSH_DONE     = 0x2D0, 
    EX_CC_EXT_COMM_FLUSH_PORT_DONE            = 0x2DF,
    EX_CC_EXT_COMM_DONE                       = 0x2FF,
    // HS3
    EX_CC_INT_HS3                             = 0x300,
    EX_CC_INT_HS3_DONE                        = 0x30F,
    // l1core process
    EX_L1_PROCESS                             = 0x310,
    EX_L1_PROCESS_DONE                        = 0x3FF,
    // HS4
    EX_CC_INT_HS4                             = 0x400,
    EX_CC_INT_HS4_DONE                        = 0x40F,
    // l1core reboot
    EX_L1_REBOOT                              = 0x410,
    // pcore process
    EX_P_PROCESS                              = 0x800,
    EX_P_PROCESS_DONE                         = 0x8FF,
    // pcore reboot
    EX_EX_REBOOT                              = 0x900,
    EX_EX_REBOOT_ENTER                        = 0x910,
    EX_EX_REBOOT_MP                           = 0xB00,
    EX_CCCI_INFO_PASSED                       = 0xCE0,
    EX_RESET_HANDOVER                         = 0xDEF,
    EX_HANDOVER                               = 0xEFF,
#if !defined(__OFFLINE_EX_LOG_PARSER__)
} exception_flow_index;
#else
} exception_flow_index_format;
#endif 

typedef enum
{
    NE_BEGIN                                  = 0x01,
    NE_EX_INIT_CORE_DONE                      = 0x18,
    NE_EX_INIT_MAINREASON                     = 0x19,
    NE_EX_INIT_MAINREASON_DONE                = 0x20,
    NE_EX_EMM_WRITEEX_DONE                    = 0x21,
    NE_CC_EXT_COMM_OPEN_PORT                  = 0x30,
    NE_CC_EXT_COMM_OPEN_PORT_DONE             = 0x3F,
    NE_CC_EXT_COMM_FLUSH_PORT                 = 0x40,
    NE_CC_EXT_COMM_FLUSH_PORT_DSP_FLUSH_MD32       = 0x50, 
    NE_CC_EXT_COMM_FLUSH_PORT_DSP_FLUSH_CS         = 0x54, 
    NE_CC_EXT_COMM_FLUSH_PORT_DSP_FLUSH_MD32_ACK   = 0x58, 
    NE_CC_EXT_COMM_FLUSH_PORT_DSP_FLUSH_CS_ACK     = 0x5C, 
    NE_CC_EXT_COMM_FLUSH_PORT_DSP_FLUSH_DONE       = 0x60, 
    NE_CC_EXT_COMM_FLUSH_PORT_DONE            = 0x6F,
    NE_NESTED_PROCESS                         = 0x70,
    NE_NESTED_PROCESS_DONE                    = 0x7F,
    NE_NESTED_PROCESS_AFTER_HS4               = 0x80,
    NE_NESTED_PROCESS_AFTER_HS4_DONE          = 0x8F,
    NE_L1_REBOOT                              = 0x90,
    NE_EX_REBOOT                              = 0x95,
    NE_EX_REBOOT_ENTER                        = 0xA0,
    NE_EX_REBOOT_MP                           = 0xD0,
    NE_CCCI_INFO_PASSED                       = 0xE0,
    NE_HANDOVER                               = 0xFF,
#if !defined(__OFFLINE_EX_LOG_PARSER__)
} exception_nested_flow_index;
#else
} exception_nested_flow_index_format;
#endif 

/*******************************************************************************
 * Data Structure Definition - Common
 *******************************************************************************/

#if defined(__PCORE__)
#define EX_CORE_ID  0xAAAAAAAA
#elif defined (__L1CORE__)
#define EX_CORE_ID  0xBBBBBBBB
#else
#define EX_CORE_ID  0xFFFFFFFF
#endif /*__PCORE__*/

#define EX_LOG_SIZE_IN_HS1      (2*1024)
#define EX_STACK_DUMP_LEN 10
#define EX_QUEUE_TRACK 20
#define EX_UNIT_NAME_LEN 8
#define EX_TIMING_CHECK_LEN 5

/* Exception header, used to track the exception type (4Bytes) */
typedef struct ex_exception_record_header_t
{
    kal_uint32 ex_core_id;       /* offset: +0x, length: 1 */ /* used in offlineSST as well*/
    exception_type ex_type;      /* offset: +0x, length: 1 */
    kal_uint8 ex_nvram;          /* offset: +0x, length: 1 */ 
    kal_uint16 ex_serial_num;    /* offset: +0x, length: 2 */
} EX_HEADER_T;

/* Duplicate structure definition to meet different platform requirement */
typedef struct _ex_rtc_struct
{
    kal_uint8 rtc_sec;    /* offset: +0x11, length: 1 */  /* seconds after the minute */
    kal_uint8 rtc_min;    /* offset: +0x12, length: 1 */  /* minutes after the hour */
    kal_uint8 rtc_hour;   /* offset: +0x13, length: 1 */  /* hours after the midnight */
    kal_uint8 rtc_day;    /* offset: +0x14, length: 1 */  /* day of the month */
    kal_uint8 rtc_mon;    /* offset: +0x15, length: 1 */  /* months */
    kal_uint8 rtc_wday;   /* offset: +0x16, length: 1 */  /* days in a week */
    kal_uint8 rtc_year;   /* offset: +0x17, length: 1 */  /* years */
    kal_uint8 rtc_pad;    /* offset: +0x18, length: 1 */  /* Padding */
} ex_rtc_struct;

typedef struct _ex_timestamp_struct
{
    kal_uint32 USCNT;     /* offset: +0x10, length: 4 */  /* us counter saved exception occuring time */
    kal_uint32 GLB_TS;   /* offset: +0x14, length: 4 */  /* global timestamp saved exception occuring time */
} ex_timestamp_struct;


/* Environment information */
typedef struct ex_environment_info_t
{
    ex_timestamp_struct ex_timestamp;              /* offset: +0x10, length: 8 */
    boot_mode_type boot_mode;                      /* offset: +0x18, length: 1 */
    kal_char execution_unit[EX_UNIT_NAME_LEN];     /* offset: +0x19, length: 8 */
    kal_uint8 status;                              /* offset: +0x21, length: 1 */
    kal_uint8 ELM_status;                          /* offset: +0x22, length: 1 */
    kal_uint8 pad;                                 /* offset: +0x23, length: 1 */
    kal_uint32 stack_ptr;                          /* offset: +0x24, length: 4 */
    kal_uint32 stack_dump[EX_STACK_DUMP_LEN];      /* offset: +0x28, length: 40 */
    kal_uint16 ext_queue_pending_cnt;              /* offset: +0x50, length: 2 */
    kal_uint16 interrupt_mask3;                    /* offset: +0x52, length: 2 */
    kal_uint32 ext_queue_pending[EX_QUEUE_TRACK];  /* offset: +0x54, length: 80 */
    kal_uint32 interrupt_mask[2];                  /* offset: +0xA4, length: 8 */
    kal_uint32 processing_lisr;                    /* offset: +0xAC, length: 4 */
    kal_uint32 lr;                                 /* offset: +0xB0, length: 4 */
} EX_ENVINFO_T;

/* Diagnosis information for Healthy Check */
typedef struct ex_diagnosis_info_t
{
    EX_DIAGNOSIS_T diagnosis;                      /* offset: +0xB4, length: 1 */
    kal_char owner[EX_UNIT_NAME_LEN];              /* offset: +0xB5, length: 8 */
    kal_uint8 pad[3];                              /* offset: +0xBD, length: 3 */
    kal_uint32 address;                            /* offset: +0xC0, length: 4 */
    kal_uint32 timing_check[EX_TIMING_CHECK_LEN];  /* offset: +0xC4, length: 20 */
} EX_DIAGNOSISINFO_T;


/*******************************************************************************
 * Constant Definition - Common
 *******************************************************************************/

#define EX_HEADER_SIZE sizeof(EX_HEADER_T)
#define EX_SWLABEL_LEN 32
#define EX_SWPRJ_LEN 32
#define EX_SWFLAVOR_LEN 32
#define EX_SWBUILDTIME_LEN 16
#define EX_SWVER_LEN (EX_SWLABEL_LEN+EX_SWPRJ_LEN+EX_SWFLAVOR_LEN+EX_SWBUILDTIME_LEN)

#define EX_ENVINFO_SIZE sizeof(EX_ENVINFO_T)
#define EX_DIAGINFO_SIZE sizeof(EX_DIAGNOSISINFO_T)
#define EX_GUARD_LEN 4
#define EX_FORCEMEMORYDUMP 0x26409001
#define EX_NATIVE_ASSERT_ID 0x20110410


/*******************************************************************************
 * Data Structure Definition - Fatal Error in general
 *******************************************************************************/

#define EX_FATALERR_ANALYSIS_OWNER_LEN 8
#define EX_FATALERR_ANALYSIS_CORE_LEN  7
#define EX_FATALERR_DESCRIPTION_PARAM_LEN 16
#define EX_FATALERR_ANALYSIS_PARAM_LEN 40
#define EX_FATALERR_GUIDELINE_PARAM_LEN 16

/* Special for Fatal Error only! (100Bytes) */
typedef struct ex_fatalerror_code_t
{
    kal_uint32 code1;
    kal_uint32 code2;
    kal_uint32 code3;
} EX_FATALERR_CODE_T;

typedef struct ex_description_t
{
    kal_uint32 trace;
    kal_uint8 param[EX_FATALERR_DESCRIPTION_PARAM_LEN];
} EX_DESCRIPTION_T;

typedef struct ex_analysis_t
{
    kal_uint32 trace;
    kal_uint8 param[EX_FATALERR_ANALYSIS_PARAM_LEN];
    kal_uint8 owner[EX_FATALERR_ANALYSIS_OWNER_LEN];
    kal_char  core[EX_FATALERR_ANALYSIS_CORE_LEN];
    kal_bool  is_cadefa_supported;
} EX_ANALYSIS_T;

typedef struct ex_guideline_t
{
    kal_uint32 trace;
    kal_uint8 param[EX_FATALERR_GUIDELINE_PARAM_LEN];
} EX_GUIDELINE_T;


/*******************************************************************************
 * Data Structure Definition - Fatal Error extended
 *******************************************************************************/

#define EX_CTRLBUFF_SRCFILE_LEN 32 /* filename */
typedef struct
{
    kal_char ex_his_owner[8];                        /* control buffer task owner */
    kal_char ex_his_source[EX_CTRLBUFF_SRCFILE_LEN]; /* source file */
    kal_uint32 ex_his_line;                          /* line number */
    kal_uint32 ex_his_count;                         /* number of identical entries */
} EX_CTRLBUFF_HISTORY_T;

typedef struct
{
    kal_uint32 ex_buf_RTOS_header1;  /* NUCLEUS overhead 1, 0: allocated, else next pointer */
    kal_uint32 ex_buf_RTOS_header2;  /* NUCLEUS overhead 2, pointer to its control block */
    kal_uint32 ex_buf_KAL_header1; /* KAL overhead 1, header (0xF1F1F1F1) */
    kal_uint32 ex_buf_KAL_header2; /* KAL overhead 2, task ID */
    kal_uint32 ex_buf_KAL_header3; /* KAL overhead 3, pointer to its control block) */
    kal_uint32 ex_buf_poolID;      /* Buffer pointer */
    kal_uint32 ex_buf_KAL_footer1; /* KAL footer: 0xF2F2F2F2 */
    kal_uint32 ex_buf_KAL_footer2; /* KAL footer appended after size requested */
} EX_CTRLBUFF_COMMON_T;

typedef struct
{
    kal_char ex_buf_source[EX_CTRLBUFF_SRCFILE_LEN];  /* Source file name */
    kal_uint32 ex_buf_line;                           /* line number */
} EX_CTRLBUFF_OWNER_T;

typedef union
{
    EX_CTRLBUFF_HISTORY_T history; /* length: 32 */
    EX_CTRLBUFF_COMMON_T common;   /* length: 32 */
} EX_CTRLBUFF_INFO_T;

typedef struct
{
    kal_uint32 ex_ctrlbuf_size;           /* offset: +0x13C, length: 4 */   /* control buffer size per entry */
    kal_uint32 ex_ctrlbuf_num;            /* offset: +0x140, length: 4 */   /* total number of entries */
    EX_CTRLBUFF_INFO_T ex_ctrlbuf_top;    /* offset: +0x144, length: 32 */   /* top occupation history node */
    EX_CTRLBUFF_INFO_T ex_ctrlbuf_second; /* offset: +0x164, length: 32 */   /* second occupation history node */
    EX_CTRLBUFF_INFO_T ex_ctrlbuf_third;  /* offset: +0x184, length: 32 */   /* third occupation history node */
    EX_CTRLBUFF_OWNER_T ex_monitor[3];    /* offset: +0x1A4, length: 48 */
    kal_uint32 ex_reserved[2];            /* offset: +0x1D4, length: 16 */   /* reserved */
} EX_CTRLBUFF_T;

typedef struct
{
    module_type ex_his_module;  /* module ID */
    kal_uint8 ex_his_source[8]; /* timer name */
    kal_uint32 ex_his_hf;       /* es buffer handling function */
    kal_uint32 ex_his_count;    /* number of identical entries */
} EX_ESBUFF_HISTORY_T;

typedef struct
{
    kal_uint32 ex_esbuf_size;              /* offset: +0x13C, length: 4 */   /* event scheduler buffer size per entry */
    kal_uint32 ex_esbuf_num;               /* offset: +0x140, length: 4 */   /* total number of entries */
    EX_ESBUFF_HISTORY_T ex_esbuf_top;      /* offset: +0x144, length: 20 */   /* top occupation history node */
    EX_ESBUFF_HISTORY_T ex_esbuf_second;   /* offset: +0x158, length: 20 */   /* second occupation history node */
    EX_ESBUFF_HISTORY_T ex_esbuf_third;    /* offset: +0x16C, length: 20 */   /* third occupation history node */
} EX_ESBUFF_T;

typedef struct
{
    kal_uint8 ex_q_src_mod;        /* source module ID */
    kal_uint8 ex_q_count;          /* total number of identical message */
    kal_uint16 ex_q_msg_id;         /* message ID */
    kal_uint16 ex_q_cur_mes_no;     /* tatal number of messages left in queue */
    kal_uint16 ex_q_config_entry;   /* total number of entries */
} EX_QUEUE_T;

typedef struct
{
    kal_char ex_task_name[8];       /* task name */
    kal_char ex_task_stack_gp[8];   /* guard pattern:STACK_END */
    kal_uint32 ex_task_cur_status;    /* task current status, eg. RUNNING, READY etc */
    EX_QUEUE_T ex_task_external_q;    /* task external queue */
    EX_QUEUE_T ex_task_internal_q;    /* task internal queue */
    kal_uint32 ex_reserved;           /* reserved */
} EX_TASKINFO_T;

/* extra exception log for arm cp15 register (temp solution) */
typedef struct ex_cp15_log_t
{
    kal_uint32 reg_ifsr;
    kal_uint32 reg_dfsr;
    kal_uint32 reg_far; //dfar
    kal_uint32 reg_ifar;
} EX_CP15_LOG_T;

typedef struct
{
    kal_uint32 cpsr;         /* offset: +0x13C, length: 4 */
    kal_uint32 reg[16];      /* offset: +0x140, length: 64 */
    EX_CP15_LOG_T cp15_reg;  /* offset: +0x180, length: 16 */
} EX_CPU_REG_T;

/*******************************************************************************
 * Constant Definition and Exported Type - Fatal Error
 *******************************************************************************/

#define EX_MAX_TASK_DUMP 4

typedef struct ex_fatalerror_t
{
    EX_FATALERR_CODE_T error_code;                 /* offset: +0xD8, length: 8 */
    EX_DESCRIPTION_T description;                  /* offset: +0xE0, length: 20 */
    EX_ANALYSIS_T analysis;                        /* offset: +0xF4, length: 52 */
    EX_GUIDELINE_T guideline;                      /* offset: +0x128, length: 20 */
    union
    {
        EX_CTRLBUFF_T ctrl_buff;                   /* offset: +0x13C, length: 136 */
        EX_ESBUFF_T es_buff;                       /* offset: +0x13C, length: 68 */
        EX_TASKINFO_T task_info[EX_MAX_TASK_DUMP]; /* offset: +0x13C, length: 160 */
        EX_CPU_REG_T cpu_reg;                      /* offset: +0x13C, length: 84 */
    } info;
} EX_FATALERR_T;

typedef struct ex_nested_fatalerror_t
{
    EX_FATALERR_CODE_T error_code;                 /* offset: +0xD8, length: 8 */
    EX_CPU_REG_T cpu_reg;                          /* offset: +0x13C, length: 84 */
} EX_NE_FATALERR_T;


/*******************************************************************************
 * Constant Definition and Exported Type - Assert Failure
 *******************************************************************************/

#define EX_ASSERTFAIL_FILEPATH_LEN 256
#define EX_ASSERTFAIL_FILENAME_LEN 64
#define EX_ASSERTFAIL_SIZE EX_ASSERTFAIL_FILEPATH_LEN + \
                           EX_ASSERTFAIL_FILENAME_LEN + \
                           sizeof(kal_uint32) * 4 + \
                           EX_GUARD_LEN
#define EX_ASSERTFAIL_DUMP_LEN  (EX_LOG_SIZE - (EX_HEADER_SIZE + EX_SWVER_LEN + \
                                 EX_ENVINFO_SIZE + EX_DIAGINFO_SIZE + EX_ASSERTFAIL_SIZE))

typedef struct ex_assert_fail_t
{
    kal_char filepath[EX_ASSERTFAIL_FILEPATH_LEN];
    kal_char filename[EX_ASSERTFAIL_FILENAME_LEN];  /* offset: +0xD8, length: 64 */
    kal_uint32 linenumber;                          /* offset: +0xF0, length: 4 */
    kal_uint32 parameters[3];                       /* offset: +0xF4, length: 12 */
    kal_uint8 dump[EX_ASSERTFAIL_DUMP_LEN];         /* offset: +0x100, length: 244 */
    kal_uint8 guard[EX_GUARD_LEN];                  /* offset: +0x1FC, length: 4 */
} EX_ASSERTFAIL_T;

typedef struct ex_nested_assert_fail_t
{
    kal_char filename[EX_ASSERTFAIL_FILENAME_LEN];  /* length: 64 */
    kal_uint32 linenumber;                          /* length: 4 */
    kal_uint32 lr;                                  /* length: 4 */
} EX_NE_ASSERTFAIL_T;


/*******************************************************************************
 * Globally Exported Data Structure
 *******************************************************************************/

typedef union
{
    EX_FATALERR_T fatalerr;
    EX_ASSERTFAIL_T assert;
} EX_CONTENT_T;

typedef union
{
    EX_NE_FATALERR_T fatalerr;
    EX_NE_ASSERTFAIL_T assert;
} EX_NE_CONTENT_T;


/* Standard strutcure of an exception log */
/*==========================================*/
/* NOTE: The structure is frozen; offset of content should be FIXED. */
/*==========================================*/
typedef struct ex_exception_log_t
{
    EX_HEADER_T header;                          /* offset: +0x0, length: 4 */
    kal_char sw_version[EX_SWLABEL_LEN];         /* offset: +0x4, length: 32 */
    kal_char sw_project_name[EX_SWPRJ_LEN];   
    kal_char sw_flavor[EX_SWFLAVOR_LEN];
    kal_char sw_buildtime[EX_SWBUILDTIME_LEN];
    EX_ENVINFO_T envinfo;                        /* offset: , length:  */
    EX_DIAGNOSISINFO_T diaginfo;                 /* offset: , length:  */
    EX_CONTENT_T content;                        /* offset: , length:  */
} EX_LOG_T;

typedef struct ex_nested_exception_log_t
{
    exception_type ex_type;
    kal_uint8 nested_times;
    kal_uint16 pad;
    EX_NE_CONTENT_T content;
} EX_NE_LOG_T;


/* backward compatible structure (for CATCHER only) */
typedef struct ex_assertfail_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_SWVER_LEN];
    EX_ENVINFO_T envinfo;
    EX_DIAGNOSISINFO_T diaginfo;
    EX_ASSERTFAIL_T assert;
} ex_assertfail_record;

/* backward compatible structure (for CATCHER only) */
typedef struct ex_assertdumpextended_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_LOG_SIZE - EX_HEADER_SIZE];
} ex_assertdumpextended_record;

/* backward compatible structure (for CATCHER only) */
typedef struct ex_exception_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_SWVER_LEN];
    EX_ENVINFO_T envinfo;
    EX_DIAGNOSISINFO_T diaginfo;
    EX_FATALERR_CODE_T error_code;
    EX_DESCRIPTION_T description;
    EX_ANALYSIS_T analysis;
    EX_GUIDELINE_T guideline;
    EX_TASKINFO_T task_info[EX_MAX_TASK_DUMP];
} ex_exception_record;

/* backward compatible structure (for CATCHER only) */
typedef struct ex_stackfatalerr_task_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_SWVER_LEN];
    EX_ENVINFO_T envinfo;
    EX_DIAGNOSISINFO_T diaginfo;
    EX_FATALERR_CODE_T error_code;
    EX_DESCRIPTION_T description;
    EX_ANALYSIS_T analysis;
    EX_GUIDELINE_T guideline;
    EX_TASKINFO_T task_info[EX_MAX_TASK_DUMP];
} ex_stackfatalerr_task_record;

/* backward compatible structure (for CATCHER only) */
typedef struct ex_stackfatalerr_ctrlbuf_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_SWVER_LEN];
    EX_ENVINFO_T envinfo;
    EX_DIAGNOSISINFO_T diaginfo;
    EX_FATALERR_CODE_T error_code;
    EX_DESCRIPTION_T description;
    EX_ANALYSIS_T analysis;
    EX_GUIDELINE_T guideline;
    EX_CTRLBUFF_T ctrl_buff;
} ex_stackfatalerr_ctrlbuf_record;

/* backward compatible structure (for CATCHER only) */
typedef struct ex_stackfatalerr_abort_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_SWVER_LEN];
    EX_ENVINFO_T envinfo;
    EX_DIAGNOSISINFO_T diaginfo;
    EX_FATALERR_CODE_T error_code;
    EX_DESCRIPTION_T description;
    EX_ANALYSIS_T analysis;
    EX_GUIDELINE_T guideline;
    EX_CPU_REG_T cpu_reg;
} ex_stackfatalerr_abort_record;

/* parameter to ex_init_log */
typedef struct
{
    exception_type type;
    kal_bool ext;
    kal_uint32 *code1;
    kal_uint32 *code2;
    kal_uint32 *code3;
    kal_uint32 e1;
    kal_uint32 e2;
    kal_uint32 e3;
    ASSERT_DUMP_PARAM_T *dump_param;
} EX_INIT_LOG_PARAM_T;


/*******************************************************************************
 * Globally Constant definition
 *******************************************************************************/
#define SYSTEM_STACK_CORRUPT "SYSPOOL"
#define INTSRAM_CODE_CORRUPT "INTSRAM"
#define VECTOR_TABLE_CORRUPT "INTVECT"
#define L2SRAM_CODE_CORRUPT  "L2_SRAM"
#define SHAREDINTSRAM_CODE_CORRUPT "DSM "

/*******************************************************************************
 * Globally Exported macro
 *******************************************************************************/
#define MACRO_PickLeftVal(left,right)   (left)

#ifdef __TST_MODULE__
   #define SET_EX_LOG_DESCRIPTION_TRACE(t) \
        do { \
            if (ex_log_ptr->content.fatalerr.description.trace == 0) \
                ex_log_ptr->content.fatalerr.description.trace =  MACRO_PickLeftVal(t); \
        } while (0)
#else
   #define SET_EX_LOG_DESCRIPTION_TRACE(t)
#endif

#define EX_LOG_DESCRIPTION_PARAM ex_log_ptr->content.fatalerr.description.param

#ifdef __TST_MODULE__
   #define SET_EX_LOG_ANALYSIS_TRACE(t) \
        do { \
            if (ex_log_ptr->content.fatalerr.analysis.trace == 0) \
                ex_log_ptr->content.fatalerr.analysis.trace = MACRO_PickLeftVal(t); \
        } while (0)
#else
   #define SET_EX_LOG_ANALYSIS_TRACE(t)
#endif

#define EX_LOG_ANALYSIS_PARAM ex_log_ptr->content.fatalerr.analysis.param

#define EX_LOG_ANALYSIS_OWNER ex_log_ptr->content.fatalerr.analysis.owner
#define EX_LOG_ANALYSIS_OFFENDING_CORE ex_log_ptr->content.fatalerr.analysis.core
#define EX_LOG_ANALYSIS_CADEFA ex_log_ptr->content.fatalerr.analysis.is_cadefa_supported

#ifdef __TST_MODULE__
   #define SET_EX_LOG_GUIDELINE_TRACE(t) \
        do { \
            if (ex_log_ptr->content.fatalerr.guideline.trace == 0) \
                ex_log_ptr->content.fatalerr.guideline.trace = MACRO_PickLeftVal(t); \
        } while (0)
#else
   #define SET_EX_LOG_GUIDELINE_TRACE(t)
#endif

#define EX_LOG_GUIDELINE_PARAM ex_log_ptr->content.fatalerr.guideline.param

#if defined(__GNUC__)

#if defined(__CR4__)

#define INT_ExceptionSwitchSP_PreProcess() \
        do { \
            extern kal_uint32 ex_unwind_cpsr; \
            extern void _INT_ExceptionSwitchSP_PreProcess(void); \
            asm volatile (" mrs  %0, cpsr" : "=r" (ex_unwind_cpsr) : /* no inputs */  ); \
            _INT_ExceptionSwitchSP_PreProcess(); \
        } while (0)

#else /* __CR4__ */

#define INT_ExceptionSwitchSP_PreProcess() \
        do { \
            extern kal_uint32 ex_unwind_cpsr; \
            extern void _INT_ExceptionSwitchSP_PreProcess(void); \
            asm volatile ( \
                ".align                 \n\t" \
                ".arm                   \n\t" \
                " mrs  %0, cpsr" : "=r" (ex_unwind_cpsr) : /* no inputs */  ); \
            _INT_ExceptionSwitchSP_PreProcess(); \
        } while (0)

#endif /* __CR4__ */

#else /* __GNUC__ */
#define INT_ExceptionSwitchSP_PreProcess() \
        do { \
            extern kal_uint32 ex_unwind_cpsr; \
            extern void _INT_ExceptionSwitchSP_PreProcess(void); \
            __asm \
            { \
                mrs ex_unwind_cpsr,cpsr; \
            } \
            _INT_ExceptionSwitchSP_PreProcess(); \
        } while (0)
#endif /* __GNUC__ */


/*******************************************************************************
 * Globally Exported Function Prorotype
 *******************************************************************************/

extern void ex_init_log(EX_INIT_LOG_PARAM_T *param);
extern void ex_init_nested_log(kal_uint32 ex_category);

extern void ex_define_main_reason();
extern void ex_save_log();
extern void ex_output_log(void);
extern kal_int8 ex_init_ctrl_buff_log(kal_uint32 *target_ptr, kal_uint32 code1, kal_uint32 code2);
extern kal_uint8 ex_init_cc_ctrl_buff_log(kal_uint32 *target_ptr, kal_uint32 code1, kal_uint32 code2);
extern kal_int8 ex_init_es_buff_log(kal_uint32 *target_ptr);
extern void ex_memory_dump_init(void);
extern void ex_output_loadinfo(void);
extern kal_bool ex_isNested(void);
extern kal_bool INT_QueryExceptionStatus(void);
extern kal_bool ex_IsSupport_OnlineSST_For_GAT(kal_int32 code1);

#ifdef __MTK_TARGET__
extern void ex_reset_hw(void);
extern void ex_reboot(void);
extern void INT_ExceptionSwitchSystemSP(void);

extern void ex_init_step_logging(void);
extern void ex_set_step_logging(kal_uint16 start_step);
extern void ex_fire_extern_step_logging(kal_uint32 info);
extern kal_bool INT_IsAnyCore_Enter_Exception();
extern void INT_EnterExceptionForOtherCore();

extern void ex_init_pcmon();
extern void ex_init_l1core_pcmon();
extern void ex_init_nested_pcmon();
extern void ex_init_dsm();
extern void KickWDT();

#if defined(__TST_MODULE__)
extern void ex_output_exc_msg(kal_bool bypass_nested);
extern void ex_reappear_log(void);
extern void ex_cadefa(kal_bool bypass_nested);
extern void ex_cadefa_common(kal_bool bypass_nested, kal_bool bLocalCore, EX_LOG_T * log_ptr);
#endif /* __TST_MODULE__ */

#endif  /* __MTK_TARGET__ */

#ifdef __STACK_ALIGN_MPU__
kal_uint32 ex_stack_overflow_check_by_mpu(void);
#endif

/*******************************************************************************
 * Globally Exported variables
 *******************************************************************************/
extern EX_LOG_T *ex_log_ptr;
extern kal_uint8 INT_Exception_Enter;
#if defined(__MTK_TARGET__)
#if defined(__MAUI_BASIC__)
extern kal_bool Is_AnyCore_Exception_Enter;
extern kal_uint8 L1CORE_Exception_Enter;
#define Is_Exception_Enter (Is_AnyCore_Exception_Enter)
#define Is_L1CORE_Exception_Enter (L1CORE_Exception_Enter)
#else
DECLARE_SHARED_VAR(kal_bool, Is_AnyCore_Exception_Enter)
#define Is_Exception_Enter SHARED_VAR(Is_AnyCore_Exception_Enter)
DECLARE_SHARED_VAR(kal_uint8, L1CORE_Exception_Enter)
#define Is_L1CORE_Exception_Enter SHARED_VAR(L1CORE_Exception_Enter)
#endif /* __MAUI_BASIC__ */
#endif /* __MTK_TARGET__ */
#endif /* _EX_ITEM_H */


