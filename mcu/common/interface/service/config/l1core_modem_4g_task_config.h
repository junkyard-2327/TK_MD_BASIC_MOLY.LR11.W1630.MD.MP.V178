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
 *   l1core_modem_4g_task_config.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file provides the task configuration.
 *
 * Author:
 * -------
 *   
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

#ifdef TASK_PRIORITY_MACRO

#define TASK_PRIORITY_EL1TST       (KAL_PRIORITY_CLASS3 + 3)
#define TASK_PRIORITY_ETEST        (KAL_PRIORITY_CLASS3 + 5)
/* multi mode LL1*/

#if !defined (__U4G_ADAPTOR__) && !defined(__EL1_IT__)
#define TASK_PRIORITY_MLL1         (KAL_PRIORITY_CLASS4 + 0)
#define TASK_PRIORITY_EL1          (KAL_PRIORITY_CLASS4 + 4)
#endif

#define TASK_PRIORITY_L1ADT        (KAL_PRIORITY_CLASS6  + 2)

#else
/*module id are divided into 3 parts. 
 * 1: module id that maps to task
 * 2: module id that maps to no task but can be used as src module id
 *  to allocate ilm, like HISR's module id
 * 3: module id that is used to print trace only.  * */

/*******************  Modem 4G start  **********************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(INDX_MODEM_4G_START = TASK_ID_MODEM_4G_CODE_BEGIN)
/*module_type and mod_task_g*/
task_module_map(INDX_MODEM_4G_START, MOD_CO_PROCESSOR_MODEM_4G_DUMMY_BEGIN = MOD_ID_CO_PROCESSOR_MODEM_4G_CODE_BEGIN)
/*task's parameters*/
task_name("")
task_queue_name("")
task_priority(0 , KAL_TASK_INITIAL_PRIORITY)
task_stack_size(0)
null_task_create_entry(NULL)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

#if !defined(__U4G_ADAPTOR__) && !defined(__EL1_IT__)
/*************************Task CFG Begin******************/
/*task_indx_type*/
task_index(INDX_EL1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_EL1,MOD_DUMMY_EL1)
/*module_type and mod_task_g*/
task_module_map(INDX_EL1, MOD_EL1)
//task's parameters
#if defined(__DUMMY_EL1C_EXISTS__)
  task_name("D_EL1")
  task_queue_name("D_EL1 Q")
#else
  task_name("EL1")
  task_queue_name("EL1 Q")
#endif
task_priority(TASK_PRIORITY_EL1, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)

#if defined(__LTE_RAT__) && defined(__DUMMY_EL1C_EXISTS__) && !defined(EL1_NOT_PRESENT)
  task_create_function(d_el1_task_create)
#elif defined(__LTE_RAT__) && !defined(__DUMMY_EL1C_EXISTS__) && !defined(EL1_NOT_PRESENT) && !defined(__EL1_TASK_DISABLE__)
  task_create_function(el1_task_create)
#else
  null_task_create_entry(NULL)		    
#endif

task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(75)
task_internal_queue_size(50)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/
#endif /* __U4G_ADAPTOR__ */

/*************************Task CFG Begin******************/
#if defined(__LTE_RAT__)
/*task_indx_type*/
task_index(INDX_ETSTM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_ETSTM,MOD_DUMMY_ETSTM)
/*module_type and mod_task_g*/
task_module_map(INDX_ETSTM, MOD_ETSTM)
//task's parameters
task_name("ETEST_Mode")
task_queue_name("ETEST Mode Q")
task_priority(TASK_PRIORITY_ETEST, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if !defined(__ETSTM_TASK_DISABLE__)
task_create_function(etstm_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(10)
task_boot_mode(FACTORY_M)
#endif/*__LTE_RAT__*/
/*************************Task CFG END******************/

#if !defined(__U4G_ADAPTOR__) && !defined(__EL1_IT__)
/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_MLL1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_multi_core_module_map(INDX_MLL1,MOD_MLL1)
//the order between MOD_MLL1 and MOD_MLL1_2 cannot be modified because of user requirement
#ifdef __GEMINI_WCDMA__
task_multi_core_module_map(INDX_MLL1,MOD_MLL1_2)
#if ( GEMINI_PLUS_WCDMA >= 3 )
task_multi_core_module_map(INDX_MLL1,MOD_MLL1_3)
#endif
#if ( GEMINI_PLUS_WCDMA >= 4 )
task_multi_core_module_map(INDX_MLL1,MOD_MLL1_4)
#endif
#endif /*__GEMINI_WCDMA__*/
//this is for codegen

/*task's parameters*/
task_name("MLL1")
task_queue_name("MLL1 Q")
task_priority(TASK_PRIORITY_MLL1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
#if defined(__LTE_RAT__) || defined(__UMTS_RAT__)
#if !defined(ATEST_DRV_ENVIRON) && !defined(__MLL1_TASK_DISABLE__)
task_create_function(mll1_create)
#else
null_task_create_entry(NULL)
#endif
#else
null_task_create_entry(NULL)
#endif /*__LTE_RAT__ || __UMTS_RAT__*/
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/
#endif /* __U4G_ADAPTOR__ */



/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_EL1TST) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_EL1TST,MOD_DUMMY_EL1TST)
/*module_type and mod_task_g*/
task_module_map(INDX_EL1TST, MOD_EL1TST)

/*task's parameters*/
task_name("EL1TST")
task_queue_name("EL1TST Q")

task_priority(TASK_PRIORITY_EL1TST , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(4096)
#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__) && !defined(__EL1TST_TASK_DISABLE__) && defined(__LTE_RAT__)
task_create_function(el1tst_create)
#else
null_task_create_entry(NULL)
#endif 
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(10)
task_boot_mode(FACTORY_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
/*task_indx_type*/
task_index(INDX_L1ADT) 
/*module_type and mod_task_g*/
task_module_map(INDX_L1ADT, MOD_L1ADT)
//task's parameters

task_name("L1ADT")
task_queue_name("L1ADT Q")

task_priority(TASK_PRIORITY_L1ADT, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)

#if defined(__MML1_ADT_ENABLE__)
  task_create_function(mmadt_create)
#else
  null_task_create_entry(NULL)		    
#endif

task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/


/**** customer added task or module id is started  *****/

/**** customer added task or module id is ended    *****/


/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(TASK_ID_MODEM_4G_CODE_TAIL)
/*module_type and mod_task_g*/
task_module_map(TASK_ID_MODEM_4G_CODE_TAIL, MODULE_TAG_CO_PROCESSOR_MODEM_4G_DUMMY_TAIL)

/*task's parameters*/
task_name("")
task_queue_name("")
task_priority(0 , KAL_TASK_INITIAL_PRIORITY)
task_stack_size(0)
null_task_create_entry(NULL)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/
/**********************   Modem End   ********************/  

#endif /*TASK_PRIORITY_MACRO*/
