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
 *   cc_ex_item.h
 *
 * Description:
 * ------------
 *	Header file for cross core exception handling
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CC_EX_ITEM_H
#define _CC_EX_ITEM_H

#if !defined(__OFFLINE_EX_LOG_PARSER__)
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_internal_def.h"
#endif /* __OFFLINE_EX_LOG_PARSER__ */
#include "ex_item.h"
#include "ex_public.h"
#include "cs_excep_hdlr_format.h"
#include "md32_excep_hdlr.h"
#include "spc_excep_hdlr_format.h"

/*******************************************************************************
 * Compiler Option Definition
 *******************************************************************************/
#if defined(__PCORE_ONLY__) || defined(__L1CORE_ONLY__)
#define __P_OR_L1CORE_ONLY__
#endif


/*******************************************************************************
 * Constant Definition -  ex record overview
 *******************************************************************************/
/*  total: EX_CC_LOG_SIZE  */
/***************************  
*      overview            *  =EX_CC_OVERVIEW_SIZE

****************************  pcore total: EX_CORE_SIZE
*      pcore exlog         *  =EX_CORE_SIZE
*      pcore nested exlog  *  =EX_NESTED_LOG_SIZE
*      pcore pcmon         *  =EX_PCMON_SIZE
*      pcore nested pcmon  *  =EX_NESTED_PCMON_SIZE
*      pcore bus err       *  =EX_BUS_ERR_SIZE
*      pcore emi status    *  =EX_EMI_STATUS_SIZE
*      pcore step logging  *  =EX_STEP_LOG_SIZE
*      pcore hs status     *  =EX_HS_STATUS_SIZE

****************************  l1core total: EX_CORE_SIZE
*      l1core exlog        *  =EX_CORE_SIZE
*      l1core nested exlog *  =EX_NESTED_LOG_SIZE
*      l1core pcmon        *  =EX_PCMON_SIZE
*      l1core nested pcmon *  =EX_NESTED_PCMON_SIZE
*      l1core bus err      *  =EX_BUS_ERR_SIZE
*      l1core emi status   *  =EX_EMI_STATUS_SIZE
*      l1core step logging *  =EX_STEP_LOG_SIZE
*      l1core hs status    *  =EX_HS_STATUS_SIZE

****************************  cs total: EX_CS_CORE_SIZE
*      cs hs status        *  =EX_CS_HS_STATUS_SIZE     
*      cs exlog            *  =EX_CS_LOG_SIZE

****************************  md32 total: EX_MD32_CORE_SIZE
*      md32 hs status      *  =EX_MD32_HS_STATUS_SIZE
*      md32 exlog          *  =EX_MD32_CORE_SIZE
****************************/
//      EX_CC_LOG_SIZE          (6*1024)  //defined in ex_public.h
#define EX_CC_OVERVIEW_SIZE     256
//      EX_LOG_SIZE             1024      //defined in ex_public.h
#define EX_NESTED_LOG_SIZE      256
#define EX_PCMON_SIZE           512
#define EX_NESTED_PCMON_SIZE    256
#define EX_BUS_ERR_SIZE         32
#define EX_EMI_STATUS_SIZE      8
#define EX_STEP_LOG_SIZE        32
#define EX_HS_STATUS_SIZE       128
#define EX_DSM_SIZE             16
#define EX_CORE_USED_SIZE   (EX_LOG_SIZE + EX_NESTED_LOG_SIZE + EX_PCMON_SIZE\
                           + EX_NESTED_PCMON_SIZE + EX_BUS_ERR_SIZE + EX_EMI_STATUS_SIZE\
                           + EX_STEP_LOG_SIZE + EX_HS_STATUS_SIZE + EX_DSM_SIZE)

#define EX_CS_CORE_SIZE         400
#define EX_CS_CORE_USED_SIZE    sizeof(CORESONIC_EXCEPTION_RECORD_T)
#define EX_MD32_CORE_SIZE       400
#define EX_MD32_CORE_USED_SIZE  sizeof(MD32_ExceptionLog_T)
#define EX_SPC_CORE_SIZE        128
#define EX_SPC_CORE_USED_SIZE   sizeof(SPC_EXCEPTION_RECORD_T)

#define EX_CS_HS_STATUS_SIZE    sizeof(kal_uint32)
#define EX_MD32_HS_STATUS_SIZE  sizeof(kal_uint32)
#define EX_SPC_HS_STATUS_SIZE   sizeof(kal_uint32)
#define EX_CS_LOG_SIZE          (EX_CS_CORE_SIZE-EX_CS_HS_STATUS_SIZE)
#define EX_MD32_LOG_SIZE        (EX_MD32_CORE_SIZE-EX_MD32_HS_STATUS_SIZE)
#define EX_SPC_LOG_SIZE         (EX_SPC_CORE_SIZE-EX_SPC_HS_STATUS_SIZE)

#define EX_CORE_SIZE        ((EX_CC_LOG_SIZE - EX_CC_OVERVIEW_SIZE - EX_CS_CORE_SIZE - EX_MD32_CORE_SIZE - EX_SPC_CORE_SIZE)/2)

/*************************  * SYNC TIME ***************************************/
#define EX_INT_SYNC_TIME (5000000) //5s
#define EX_OP_SYNC_TIME  (1000000) //1s

/*******************************************************************************
 * Enum Type Definition
 *******************************************************************************/

typedef enum ex_core_t
{
    EX_PCORE             = 0,
    EX_L1CORE,
    EX_CS1,
    EX_CS2,
    EX_CS3,
    EX_MD32_1,
    EX_MD32_2,
    EX_MD32_3,
    EX_SPC,
} EX_CORE_T;
#if !defined(__OFFLINE_EX_LOG_PARSER__)
typedef enum ex_sync
{
    NEVER_SYNCED         = 0,
    SYNC_SUCCESS         = 1,
    SYNC_FAIL            = 2,
    NO_NEED_TO_SYNC      = 3,
    NESTED_SYNC          = 4,
} EX_SYNC;

typedef enum ex_sync_stage
{
    SYNCSTAGE_INIT_LOG           = 1,
    SYNCSTAGE_POST_INIT_LOG      = 2,
    SYNCSTAGE_EXT_CC_COMM        = 3,
    SYNCSTAGE_L1_PROCESS         = 4,
    SYNCSTAGE_NESTED_EXCEP       = 5,
} EX_SYNC_STAGE;
#else
#include "ex_item_types.h"
#endif /*__OFFLINE_EX_LOG_PARSER__*/

/*******************************************************************************
 * Data Structure Definition
 *******************************************************************************/
#define EX_HS_STEP_COUNT  6

PRAGMA_BEGIN_PACK_STRUCT

#define EX_CORE_NUM            9  //pcore+l1core+sonic*3+md32*3+spc
#define EX_CORE_NAME_MAX_SIZE  11
typedef struct ex_main_reason_t
{
    kal_uint32  core_offset;
    kal_bool    is_offender;
    kal_char    core_name[EX_CORE_NAME_MAX_SIZE];
} EX_MAIN_REASON_T;

typedef struct ex_overview_t
{
    kal_uint32          core_num;
    EX_MAIN_REASON_T    main_reason[EX_CORE_NUM];
    kal_uint32          ect_status;
    kal_uint32          cs_status;
    kal_uint32          md32_status;
    kal_uint32          pad[(EX_CC_OVERVIEW_SIZE - 4*sizeof(kal_uint32) - (sizeof(EX_MAIN_REASON_T)*EX_CORE_NUM))/ sizeof(kal_uint32)];
} EX_OVERVIEW_T;


typedef struct ex_dump_comm_t
{
    volatile kal_uint32 addr;
    volatile kal_uint32 len;
    volatile kal_uint32 op;
} EX_DUMP_COMM_T;

typedef struct ex_corelog_t
{
    kal_uint32              ex_log[EX_LOG_SIZE                   / sizeof(kal_uint32)];
    kal_uint32              ex_nested_log[EX_NESTED_LOG_SIZE     / sizeof(kal_uint32)];
    kal_uint32              ex_pcmon[EX_PCMON_SIZE               / sizeof(kal_uint32)];
    kal_uint32              ex_nested_pcmon[EX_NESTED_PCMON_SIZE / sizeof(kal_uint32)];
    kal_uint32              ex_buserr[EX_BUS_ERR_SIZE            / sizeof(kal_uint32)];
    kal_uint32              ex_emi_status[EX_EMI_STATUS_SIZE     / sizeof(kal_uint32)];
    volatile kal_uint32     ex_steplog[EX_STEP_LOG_SIZE          / sizeof(kal_uint32)];
    volatile kal_uint32     ex_hs[EX_HS_STATUS_SIZE              / sizeof(kal_uint32)];
    kal_uint32              ex_dsm_status[EX_DSM_SIZE            / sizeof(kal_uint32)];
    kal_uint32              pad[(EX_CORE_SIZE -EX_CORE_USED_SIZE)/ sizeof(kal_uint32)];
} EX_CORELOG_T;

typedef struct ex_soniclog_t
{
    volatile kal_uint32                 ex_hs;
    CORESONIC_EXCEPTION_RECORD_T        ex_log;
    kal_uint32                          pad[(EX_CS_LOG_SIZE -EX_CS_CORE_USED_SIZE)/ sizeof(kal_uint32)];
} EX_SONICLOG_T;

typedef struct ex_md32log_t
{
    volatile kal_uint32                 ex_hs;
    MD32_ExceptionLog_T                 ex_log;
    kal_uint32                          pad[(EX_MD32_LOG_SIZE -EX_MD32_CORE_USED_SIZE)/ sizeof(kal_uint32)];
} EX_MD32LOG_T;

typedef struct ex_spclog_t
{
    volatile kal_uint32                 ex_hs;
    SPC_EXCEPTION_RECORD_T              ex_log;
    kal_uint32                          pad[(EX_SPC_LOG_SIZE -EX_SPC_CORE_USED_SIZE)/ sizeof(kal_uint32)];
} EX_SPCLOG_T;

typedef struct ex_fulllog_t
{
    EX_OVERVIEW_T  overview;
    EX_CORELOG_T   pcore;
    EX_CORELOG_T   l1core;
    EX_SONICLOG_T  sonic;
    EX_MD32LOG_T   md32;
    EX_SPCLOG_T    spc;
} EX_FULLLOG_T;

/***************************** +Debug Structure+ *******************************/

typedef struct ex_core_handshake_t
{
    kal_uint32 hs_step;
    EX_SYNC hs_status[EX_HS_STEP_COUNT];
    kal_uint32 hs_in_timestamp[EX_HS_STEP_COUNT];
    kal_uint32 hs_out_timestamp[EX_HS_STEP_COUNT];
} EX_HS_T;

typedef struct pcmon_pair_s
{
	kal_uint32 src_pc;
	kal_uint32 dst_pc;
}EX_PCMON_PC_PAIR_T;

typedef struct pcmon_data_pair_s
{
	kal_uint32 pc;
	kal_uint32 data_address;
}EX_PCMON_DATA_PAIR_T;

typedef struct pcmon_t_s
{
	EX_PCMON_PC_PAIR_T PC_PAIR[32];
	EX_PCMON_DATA_PAIR_T PC_DATA_PAIR[32];
}PCMON_T;

typedef struct pcmon_data_t_s
{
	EX_PCMON_PC_PAIR_T PC_PAIR[32];
}PCMON_DATA_T;

typedef struct ex_dsm_status_t_s
{
    kal_uint32 DSM_load_label;
    kal_uint32 DSM_init_label;
    kal_uint32 DSM_loading_label;
    kal_uint32 DSM_unloading_label;
}EX_DSM_T;

typedef struct EMI_MPU_VIO_INFO_t_s
{
	kal_uint32    address;          /* Magic pattern to check if this dump data is valid */    
	kal_uint32    status; /* Setting for each region */
} EMI_MPU_VIO_INFO_T;

typedef struct ex_corelog_ptr_t
{
    EX_LOG_T             *ex_log;
    EX_NE_LOG_T          *ex_nested_log;
    PCMON_T              *ex_pcmon;
    PCMON_DATA_T         *ex_nested_pcmon;
    kal_uint32           *ex_buserr;
    EMI_MPU_VIO_INFO_T   *ex_emi_status;
    kal_uint32           *ex_steplog;
    EX_HS_T              *ex_hs;
    EX_DSM_T             *ex_dsm_status;
} EX_CORELOG_PTR_T;

typedef struct ex_fulllog_ptr_t
{
    EX_OVERVIEW_T      *overview;
    EX_CORELOG_PTR_T   pcore;
    EX_CORELOG_PTR_T   l1core;
    EX_SONICLOG_T      *sonic;
    EX_MD32LOG_T       *md32;
    EX_SPCLOG_T        *spc;
} EX_FULLLOG_PTR_T;
/***************************** -Debug Structure- *******************************/
PRAGMA_END_PACK_STRUCT
/*******************************************************************************
 * Global Definition
 *******************************************************************************/
DECLARE_SHARED_VAR(EX_FULLLOG_T, ex_cc_log)
#define ex_cc_log_ptr SHARED_pVAR(ex_cc_log)
DECLARE_SHARED_VAR(volatile EX_BBREG_DUMP_T*, l1core_bb_reg_region_head)
#define l1core_bbreg_region_head SHARED_VAR(l1core_bb_reg_region_head)
DECLARE_SHARED_VAR(volatile kal_uint32, l1core_bb_reg_dump_count_g)
#define l1core_bbreg_dump_count_g SHARED_VAR(l1core_bb_reg_dump_count_g)
DECLARE_SHARED_VAR(EX_FULLLOG_PTR_T, ex_fulllog_ptr)
#define _ex_fulllog_ptr SHARED_pVAR(ex_fulllog_ptr)
DECLARE_SHARED_VAR(volatile kal_bool, b_init_l1core_bbreg_g)
#define is_init_l1core_bbreg SHARED_VAR(b_init_l1core_bbreg_g)

#if defined(__PCORE__)
#define ex_core               (ex_cc_log_ptr->pcore)
#elif defined(__L1CORE__)       
#define ex_core               (ex_cc_log_ptr->l1core)
#endif /* PCORE, L1CORE */

#define l1core_ex_log_ptr     (&(ex_cc_log_ptr->l1core))
#define cs_ex_log_ptr         (&(ex_cc_log_ptr->sonic.ex_log))
#define md32_ex_log_ptr       (&(ex_cc_log_ptr->md32.ex_log))
#define spc_ex_log_ptr        (&(ex_cc_log_ptr->spc.ex_log))
//PCMON
#define ex_pcmon_ptr          ((kal_uint32*)(ex_core.ex_pcmon))
#define ex_pcore_pcmon_ptr    ((kal_uint32*)(ex_cc_log_ptr->pcore.ex_pcmon))
#define ex_l1core_pcmon_ptr   ((kal_uint32*)(ex_cc_log_ptr->l1core.ex_pcmon))
#define ex_nested_pcmon_ptr   ((kal_uint32*)(ex_core.ex_nested_pcmon))
//BUS ERR
#define ex_buserr_ptr         ((kal_uint32*)(ex_core.ex_buserr))
//EMI STATUS
#define ex_emi_status_ptr     ((kal_uint32*)(ex_core.ex_emi_status))
//STEP LOG
#define ex_core_steplog_ptr   ((kal_uint32*)(ex_core.ex_steplog))
#define ex_pcore_steplog_ptr  ((kal_uint32*)(ex_cc_log_ptr->pcore.ex_steplog))
#define ex_l1core_steplog_ptr ((kal_uint32*)(ex_cc_log_ptr->l1core.ex_steplog))
//HS
#define ex_core_hs_ptr        ((EX_HS_T*)(ex_core.ex_hs))
#define ex_pcore_hs_ptr       ((EX_HS_T*)(ex_cc_log_ptr->pcore.ex_hs))
#define ex_l1core_hs_ptr      ((EX_HS_T*)(ex_cc_log_ptr->l1core.ex_hs))
#define ex_cs_hs_ptr          ((kal_uint32*)&(ex_cc_log_ptr->sonic.ex_hs))
#define ex_md32_hs_ptr        ((kal_uint32*)&(ex_cc_log_ptr->md32.ex_hs))
#define ex_spc_hs_ptr        ((kal_uint32*)&(ex_cc_log_ptr->spc.ex_hs))
//DSM
#define ex_dsm_ptr            ((EX_DSM_T*)(ex_core.ex_dsm_status))

#define SET_HS(core, status)          ex_set_value((kal_uint32*)ex_##core##_hs_ptr, status)
#define GET_HS(core)                  ex_get_value((kal_uint32*)ex_##core##_hs_ptr)
#define SET_CORE_HS_IN(step, status)  ex_set_hs_info((EX_HS_T*)ex_core_hs_ptr, step, status, KAL_TRUE)
#define SET_CORE_HS_OUT(step, status) ex_set_hs_info((EX_HS_T*)ex_core_hs_ptr, step, status, KAL_FALSE)
#define GET_CORE_CURRENT_HS_STEP(core) ex_get_current_hs_step((EX_HS_T*)ex_##core##_hs_ptr)
#define GET_CORE_HS_STATUS(core, step) ex_get_hs_status((EX_HS_T*)ex_##core##_hs_ptr, step)
#define GET_STEP(core)                ex_get_step_logging(ex_##core##_steplog_ptr, KAL_FALSE)
#define GET_NE_STEP(core)             ex_get_step_logging(ex_##core##_steplog_ptr, KAL_TRUE)
#define SET_EX_STEP(step)             do { if(INT_Exception_Enter <  2){ ex_set_step_logging(step); } } while (0)
#define SET_NE_STEP(step)             do { if(INT_Exception_Enter == 2){ ex_set_step_logging(step); } } while (0)
/*******************************************************************************
 * Globally Exported variables
 *******************************************************************************/
extern EX_LOG_T      *ex_log_ptr;  // for OfflineSST
extern EX_NE_LOG_T   *ex_nested_log_ptr;
/*******************************************************************************
 * Globally Exported functions
 *******************************************************************************/
extern kal_bool INT_IsL1COREProcessDone();
extern kal_bool INT_IsEXT_CC_COMMDone();
extern EX_CORE_T INT_GetCurrentCORE();
extern kal_bool SST_HandleDumpRegion(kal_uint32 **address, kal_uint32* length, kal_uint32* option);
extern kal_uint32 ex_get_step_logging(kal_uint32 *step_ptr, kal_bool bNested);
extern void ex_l1core_reboot();
extern void ex_pcore_reboot();
extern void ex_unguard_l1core_tcm();
extern void ex_set_hs_info(EX_HS_T* hs_ptr, kal_uint32 step, kal_uint32 status, kal_bool bIn);
extern EX_SYNC ex_get_hs_status(EX_HS_T* hs_ptr, kal_uint32 step);
extern kal_uint32 ex_get_current_hs_step(EX_HS_T* hs_ptr);
extern kal_uint32 ex_get_value(kal_uint32* _ptr);
extern void init_ex_struct();
extern kal_uint32 ex_GetECTStatus();
extern void ex_output_sonic_log();
extern void ex_output_md32_log();
extern void ex_output_spc_log();
extern void ex_sonic_cadefa();
extern void ex_md32_cadefa();
extern void ex_spc_cadefa();
extern void ex_detect_dsp_version_mismatched();
extern void ex_query_cc_ex_reason(kal_uint32 ect_status, kal_char** reason);
extern kal_bool INT_QueryL1COREExceptionStatus(void);
extern void ex_post_init_log();
extern void ex_backup_l1core_cadefa();
extern void ex_init_sonic();
extern void ex_init_md32();
extern void ex_init_spc();
#if defined(__PCORE__)
extern void ex_l1core_cadefa();
extern void ex_define_main_reason();
extern void ex_copy_ELM_status_from_L1CORE();
#endif /* __PCORE__ */

#endif /* _CC_EX_ITEM_H */


