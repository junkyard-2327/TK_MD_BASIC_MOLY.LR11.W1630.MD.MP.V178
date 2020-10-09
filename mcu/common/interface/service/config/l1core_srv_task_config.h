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
 *   l1core_srv_task_config.h
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
#ifdef TASK_PRIORITY_MACRO

#define TASK_PRIORITY_DHLRT                     (KAL_PRIORITY_CLASS3  + 1)
#define TASK_PRIORITY_DHL2_SLAVE                (KAL_PRIORITY_CLASS13 + 7)

#if !defined(KAL_ON_OSCAR)
#define TASK_PRIORITY_TSTR                      (KAL_PRIORITY_CLASS13 + 8)
#endif /* KAL_ON_OSCAR */

#define TASK_PRIORITY_CCCISRV_L1CORE            (KAL_PRIORITY_CLASS14 + 6)

#define TASK_PRIORITY_CCCISRVIT_L1CORE          (KAL_PRIORITY_CLASS19 + 1)
#define TASK_PRIORITY_CCCISRVIT1_L1CORE         (KAL_PRIORITY_CLASS19 + 2)
#define TASK_PRIORITY_CCCISRVIT2_L1CORE         (KAL_PRIORITY_CLASS19 + 3)
#define TASK_PRIORITY_CCCISRVIT3_L1CORE         (KAL_PRIORITY_CLASS19 + 4)
#define TASK_PRIORITY_CCCISRVIT4_L1CORE         (KAL_PRIORITY_CLASS19 + 5)

#define TASK_PRIORITY_L_MDDBG                   (KAL_PRIORITY_CLASS24 + 1)

#define TASK_PRIORITY_L_EXCEP_RESERVE_0         (KAL_PRIORITY_CLASS24 + 2)
#define TASK_PRIORITY_L_EXCEP_TEST              (KAL_PRIORITY_CLASS24 + 3)
#define TASK_PRIORITY_L_EXCEP_RESERVE_1         (KAL_PRIORITY_CLASS24 + 4)

#define TASK_PRIORITY_DHL                       (KAL_PRIORITY_CLASS24 + 5)
#if defined(KAL_ON_OSCAR)
#define TASK_PRIORITY_TSTR                      (KAL_PRIORITY_CLASS24 + 9)
#endif /* KAL_ON_OSCAR */


#else

/*module id are divided into 3 parts. 
 * 1: module id that maps to task
 * 2: module id that maps to no task but can be used as src module id
 * to allocate ilm, like HISR s module id
 * 3: module id that is used to print trace only.  * */


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_NIL = TASK_ID_SRV_CODE_BEGIN)
/*module_type and mod_task_g*/
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_NIL, MOD_CO_PROCESSOR_DUMMY_NIL = MOD_ID_CO_PROCESSOR_SRV_CODE_BEGIN)
/*task's parameters*/
task_name("SRV_BEGIN")
task_queue_name("")
task_priority(0 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(0)
null_task_create_entry(NULL)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/



/*************************Task CFG Begin****************/

/*task_indx_type*/
task_index(INDX_DHLRT)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHLRT,MOD_DUMMY_DHLRT_SLAVE)
/*module_type and mod_task_g*/
task_module_map(INDX_DHLRT, MOD_DHLRT_SLAVE)

//task's parameters
task_name("DRTS")
task_queue_name("DRTS Q")
task_priority(TASK_PRIORITY_DHLRT, KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
#if defined (__DHL_MODULE__) && !defined(L1_SIM)
task_create_function(dhl_rt_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_TRUE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
/*************************Task CFG END******************/


/*************************Task CFG Begin******************/
/*task_indx_type*/
task_index(INDX_DHL)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHL, MOD_DUMMY_DHL_SLAVE)
/*module_type and mod_task_g*/
#if defined(__DHL_MODULE__)
task_module_map(INDX_DHL, MOD_DHL_SLAVE)
#endif
#if defined(GEN_FOR_CPARSER)
task_module_map(INDX_DHL, MOD_TST_SLAVE = MOD_DHL_SLAVE)
#endif

//task's parameters
task_name("DHLS")
task_queue_name("DHLS Q")
task_priority(TASK_PRIORITY_DHL , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
#if defined(__DHL_MODULE__)
task_create_function(dhl_create)
#else
null_task_create_entry(NULL)
#endif /*__DHL_MODULE__*/
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)

#if !defined(INDX_TST)
    #define INDX_TST INDX_DHL
#endif /* end of !INDX_TST */

#if !defined(MOD_TST_SLAVE)
	#define MOD_TST_SLAVE MOD_DHL_SLAVE
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
/*task_indx_type*/
task_index(INDX_DHL_READER)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHL_READER,MOD_DUMMY_DHL_READER_SLAVE)
/*module_type and mod_task_g*/
#if defined(__DHL_MODULE__)
task_module_map(INDX_DHL_READER, MOD_DHL_READER_SLAVE)
#endif
#if defined(GEN_FOR_CPARSER)
task_module_map(INDX_DHL_READER, MOD_TST_READER_SLAVE = MOD_DHL_READER_SLAVE)
#endif
/* fix MOD_TST_READER=3, this is restricted by META tool */

//task's parameters
task_name("DRS")
task_queue_name("DRS Q")
task_priority(TASK_PRIORITY_TSTR , KAL_TASK_INITIAL_PRIORITY)
#if defined(LOW_COST_SUPPORT)
task_stack_size(1024)
#else
task_stack_size(2304)
#endif
#ifdef __DHL_MODULE__
task_create_function(dhl_reader_create)
#else
null_task_create_entry(NULL)
#endif /*__DHL_MODULE__*/
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)

#if !defined(INDX_TST_READER)
    #define INDX_TST_READER  INDX_DHL_READER
#endif /* end of !INDX_TST_READER */

#if !defined(MOD_TST_READER)
	#define MOD_TST_READER_SLAVE MOD_DHL_READER_SLAVE
#endif
/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_CCCISRV_L1CORE)

/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCISRV_L1CORE, MOD_DUMMY_CCCISRV_L1CORE)

/*module_type and mod_task_g*/
task_module_map(INDX_CCCISRV_L1CORE, MOD_CCCISRV_L1CORE)
task_module_map(INDX_CCCISRV_L1CORE, MOD_CCCIIPC_L1CORE)
task_module_map(INDX_CCCISRV_L1CORE, MOD_CCCIRPC_L1CORE)
task_module_map(INDX_CCCISRV_L1CORE, MOD_CCCIMSG_L1CORE)

/*task's parameters*/
task_name("L1SRVCCCI")
task_queue_name("L1SRVCCCI Q")
task_priority(TASK_PRIORITY_CCCISRV_L1CORE, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__CCCIDEV_SUPPORT__) && !defined(CCCIDEV_NOT_PRESENT) && !defined(__CCCISRV_TASK_DISABLE__)
task_create_function(cccisrv_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_CCCISRVIT_L1CORE)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCISRVIT_L1CORE, MOD_DUMMY_CCCISRVIT_L1CORE)
/*module_type and mod_task_g*/
task_module_map(INDX_CCCISRVIT_L1CORE, MOD_CCCISRVIT_L1CORE)
/*task's parameters*/
task_name("CCSRVIT")
task_queue_name("CCSRVIT Q")
task_priority(TASK_PRIORITY_CCCISRVIT_L1CORE, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__L1CORE_CCCI_SRV_IT__)
task_create_function(cccisrvit_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/



/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_CCCISRVIT1_L1CORE)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCISRVIT1_L1CORE, MOD_DUMMY_CCCISRVIT1_L1CORE)
/*module_type and mod_task_g*/
task_module_map(INDX_CCCISRVIT1_L1CORE, MOD_CCCISRVIT1_L1CORE)
/*task's parameters*/
task_name("1CCSRVIT")
task_queue_name("1CCSRVIT Q")
task_priority(TASK_PRIORITY_CCCISRVIT1_L1CORE, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__L1CORE_CCCI_SRV_IT__)
task_create_function(cccisrvit1_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_CCCISRVIT2_L1CORE)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCISRVIT2_L1CORE, MOD_DUMMY_CCCISRVIT2_L1CORE)
/*module_type and mod_task_g*/
task_module_map(INDX_CCCISRVIT2_L1CORE, MOD_CCCISRVIT2_L1CORE)
/*task's parameters*/
task_name("2CCSRVIT")
task_queue_name("2CCSRVIT Q")
task_priority(TASK_PRIORITY_CCCISRVIT2_L1CORE, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__L1CORE_CCCI_SRV_IT__)
task_create_function(cccisrvit2_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_CCCISRVIT3_L1CORE)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCISRVIT3_L1CORE, MOD_DUMMY_CCCISRVIT3_L1CORE)
/*module_type and mod_task_g*/
task_module_map(INDX_CCCISRVIT3_L1CORE, MOD_CCCISRVIT3_L1CORE)
/*task's parameters*/
task_name("3CCSRVIT")
task_queue_name("3CCSRVIT Q")
task_priority(TASK_PRIORITY_CCCISRVIT3_L1CORE, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__L1CORE_CCCI_SRV_IT__)
task_create_function(cccisrvit3_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_CCCISRVIT4_L1CORE)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCISRVIT4_L1CORE, MOD_DUMMY_CCCISRVIT4_L1CORE)
/*module_type and mod_task_g*/
task_module_map(INDX_CCCISRVIT4_L1CORE, MOD_CCCISRVIT4_L1CORE)
/*task's parameters*/
task_name("4CCSRVIT")
task_queue_name("4CCSRVIT Q")
task_priority(TASK_PRIORITY_CCCISRVIT4_L1CORE, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__L1CORE_CCCI_SRV_IT__)
task_create_function(cccisrvit4_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/



/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_MDDBG) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_multi_core_module_map(INDX_MDDBG, MOD_DUMMY_MDDBG)
task_multi_core_module_map(INDX_MDDBG, MOD_MDDBG)
/*task's parameters*/
task_name("L_MDDBG")
task_queue_name("L_MDDBG Q")
task_priority(TASK_PRIORITY_L_MDDBG, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(2048)
#if defined(__MTK_TARGET__) && (defined(DEBUG_BUF2) || (!defined(__MTK_SECURE_PLATFORM__) && !defined(__PRODUCTION_RELEASE__) && defined(__CR4__)))
task_create_function(mddbg_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_EX_TEST) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_multi_core_module_map(INDX_EX_TEST, MOD_DUMMY_EXTEST)
task_multi_core_module_map(INDX_EX_TEST, MOD_EXTEST)
/*task's parameters*/
task_name("L_EX_TEST")
task_queue_name("L_EX_TEST Q")
task_priority(TASK_PRIORITY_L_EXCEP_TEST, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(2048)
#if defined(__MTK_TARGET__) && defined(__EXCEP_TEST__)
task_create_function(excep_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
#if defined(__DHL_MODULE__) && defined(__MTK_TARGET__) && !defined(L1_SIM) && defined(__KAL_CROSS_CORE_SUPPORT__)
/*task_indx_type*/
task_index(INDX_DHL2_SLAVE)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHL2_SLAVE, MOD_DUMMY_DHL2_SLAVE)
/*module_type and mod_task_g*/
task_module_map(INDX_DHL2_SLAVE, MOD_DHL2_SLAVE)

//task's parameters
task_name("DS2")
task_queue_name("DS2 Q")
task_priority(TASK_PRIORITY_DHL2_SLAVE, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
#if !defined(__DHL_TASK_DISABLE__)
task_create_function(dhl2_create)
#else
null_task_create_entry(NULL)
#endif

task_stack_internalRAM(KAL_TRUE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
#endif /*__DHL2_MODULE__*/
/*************************Task CFG END******************/


#ifndef __DHL_MODULE__
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_DHL_SLAVE)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_DHL_READER_SLAVE)
#endif

MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE(MOD_HLT)


/**** customer added task or module id is started  *****/

/**** customer added task or module id is ended    *****/


/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(TASK_ID_SRV_CODE_TAIL)
/*module_type and mod_task_g*/
task_module_map(TASK_ID_SRV_CODE_TAIL, MODULE_TAG_CO_PROCESSOR_SRV_TAIL)

/*task's parameters*/
task_name("SRV_TAIL")
task_queue_name("")
task_priority(0 , KAL_TASK_INITIAL_PRIORITY)
task_stack_size(0)
null_task_create_entry(NULL)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

#endif /*TASK_PRIORITY_MACRO*/
