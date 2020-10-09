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
 *   l1core_drv_task_config.h
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
/*Put tasks for debug and test purpose only together to save priority*/


#define TASK_PRIORITY_TEST2_1           (KAL_PRIORITY_CLASS9  + 3)

#define TASK_PRIORITY_TEST2_2           (KAL_PRIORITY_CLASS10 + 1)

#define TASK_PRIORITY_L1AUDIOL1         (KAL_PRIORITY_CLASS14 + 2)

#define TASK_PRIORITY_L1IDLE            (KAL_PRIORITY_CLASS25 + 4)



#if defined(ATEST_ENABLE) && defined(ATEST_DRV_ENABLE) && defined(__MTK_TARGET__)
    #include "drvtest_task_config.h"
#endif /* end of __MTK_DRVTEST_ENABLE__ */ 

#else
/*module id are divided into 3 parts.
 * 1: module id that maps to task
 * 2: module id that maps to no task but can be used as src module id
 *  to allocate ilm, like HISR's module id
 * 3: module id that is used to print trace only.  * */

/********************* Driver Start  ************************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(INDX_DRV_START = TASK_ID_DRV_CODE_BEGIN)
/*module_type and mod_task_g*/
task_module_map(INDX_DRV_START, MOD_CO_PROCESSOR_DRV_DUMMY_BEGIN = MOD_ID_CO_PROCESSOR_DRV_CODE_BEGIN)
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

/*************************Task CFG Begin****************/
task_index(INDX_TEST1)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_multi_core_module_map(INDX_TEST1,MOD_DUMMY_TEST1)
/*module_type and mod_task_g*/
task_multi_core_module_map(INDX_TEST1, MOD_TEST1n1)
task_multi_core_module_map(INDX_TEST1, MOD_TEST1n2)
/*task's parameters*/
task_name("DBL1")
task_queue_name("DBL1 Q")
task_priority(TASK_PRIORITY_TEST2_1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
#if defined(__MTK_TARGET__) && defined(__TEMP_KTEST__)
task_create_function(test_task1_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(5)
task_boot_mode(NORMAL_M | USB_M)
/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
task_index(INDX_TEST2)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_multi_core_module_map(INDX_TEST2,MOD_DUMMY_TEST2)
/*module_type and mod_task_g*/
task_multi_core_module_map(INDX_TEST2, MOD_TEST2n1)
task_multi_core_module_map(INDX_TEST2, MOD_TEST2n2)
/*task's parameters*/
task_name("DBL2")
task_queue_name("DBL2 Q")
task_priority(TASK_PRIORITY_TEST2_2 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
#if defined(__MTK_TARGET__) && defined(__TEMP_KTEST__)
task_create_function(test_task2_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(5)
task_boot_mode(NORMAL_M | USB_M)
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
task_index(INDX_L1IDLE) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L1IDLE,MOD_DUMMY_L1IDLE)
/*module_type and mod_task_g*/
task_module_map(INDX_L1IDLE, MOD_L2IDLE)

/*task's parameters*/
task_name("L1IDLE")
task_queue_name("L1IDLE Q")
task_priority(TASK_PRIORITY_L1IDLE , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(512)
#if defined(__MTK_TARGET__) && (!defined(__L1IDLE_TASK_DISABLE__))
task_create_function(idle_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_L1SPL1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L1SPL1,MOD_DUMMY_L1SPL1)
/*module_type and mod_task_g*/
task_module_map(INDX_L1SPL1, MOD_L1SPL1)

/*task's parameters*/
task_name("AUDL")
task_queue_name("AUDL Q")
task_priority(TASK_PRIORITY_L1AUDIOL1 , KAL_TASK_INITIAL_PRIORITY )
#if defined(__DRM_SUPPORT__) && defined(MIDFILE_PLAY_SUPPORT)
task_stack_size(3072)
#else
#if defined(__DRM_SUPPORT__) && defined(__DRM_V02__)
task_stack_size(2176)
#else  /* __DRM_SUPPORT__ && __DRM_V02__ */
#if defined(__LOW_COST_SUPPORT_ULC__)
task_stack_size(1024)
#else /* __LOW_COST_SUPPORT_ULC__ */
task_stack_size(2048)
#endif /* __LOW_COST_SUPPORT_ULC__ */
#endif /* __DRM_SUPPORT__ && __DRM_V02__ */
#endif /*__DRM_SUPPORT__ && MIDFILE_PLAY_SUPPORT*/                                   
#if defined (L1_NOT_PRESENT) || defined (__UE_SIMULATOR__) || defined(__L1SP_TASK_DISABLE__)
null_task_create_entry(NULL)
#else
task_create_function(l1spl1_create)
#endif
task_stack_internalRAM(KAL_FALSE)
#ifdef __SMART_PHONE_MODEM__
task_external_queue_size(10)
#else
task_external_queue_size(0)
#endif
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/

MODULE_ID_FOR_PRINT_TRACE(MOD_IDC)

#if defined(ATEST_ENABLE) && defined(ATEST_DRV_ENABLE) && defined(__MTK_TARGET__)
    #include "drvtest_task_config.h"
#endif /* end of __MTK_DRVTEST_ENABLE__ */ 


/**** customer added task or module id is started  *****/

/**** customer added task or module id is ended    *****/





/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(TASK_ID_DRV_CODE_TAIL)
/*module_type and mod_task_g*/
task_module_map(TASK_ID_DRV_CODE_TAIL, MODULE_TAG_CO_PROCESSOR_DRV_DUMMY_TAIL)

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

#endif /*TASK_PRIORITY_MACRO*/
