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
 *   pcore_drv_task_config.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file provides the task index and module index configuration.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef TASK_PRIORITY_MACRO
 /*Put tasks for debug and test purpose only together to save priority*/

#define TASK_PRIORITY_TEST1_1           (KAL_PRIORITY_CLASS9  + 4)

#define TASK_PRIORITY_TEST1_2           (KAL_PRIORITY_CLASS10 + 2)

#define TASK_PRIORITY_SPH_EVS           (KAL_PRIORITY_CLASS18 + 0)

#define TASK_PRIORITY_L1AUDIO           (KAL_PRIORITY_CLASS13 + 9)

#define TASK_PRIORITY_L1AUDIO_SPH_SRV   (KAL_PRIORITY_CLASS14 + 0)

#define TASK_PRIORITY_SDIOCORE          (KAL_PRIORITY_CLASS15 + 4)

#define TASK_PRIORITY_CCISMCORE         (KAL_PRIORITY_CLASS15 + 5)   //CCISMCORE

#define TASK_PRIORITY_CCISMCORE_IT      (KAL_PRIORITY_CLASS20 + 1)   //CCISMCORE_IT

#define TASK_PRIORITY_CMUX              (KAL_PRIORITY_CLASS16 + 3)

#define TASK_PRIORITY_MED               (KAL_PRIORITY_CLASS17 + 5)

#define TASK_PRIORITY_IDLE              (KAL_PRIORITY_CLASS25 + 5)


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
 task_module_map(INDX_DRV_START, MOD_DRV_DUMMY_BEGIN = MOD_ID_DRV_CODE_BEGIN)
 /*task's parameters*/
 task_name("")
 task_queue_name("")
task_priority(KAL_TASK_INITIAL_PRIORITY , KAL_TASK_INITIAL_PRIORITY)
 task_stack_size(0)
 null_task_create_entry(NULL)
 task_stack_internalRAM(KAL_FALSE)
 task_external_queue_size(0)
 task_internal_queue_size(0)
 task_boot_mode(NORMAL_M)
 /*************************Task CFG END******************/
 
/*************************Task CFG Begin****************/
/*For smart phone and modem interaction*/
/*task_indx_type*/
task_index(INDX_CMUX)            /*WAP ps task*/ 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CMUX,MOD_DUMMY_CMUX)
/*module_type and mod_task_g*/
task_module_map(INDX_CMUX, MOD_CMUX)
task_module_map(INDX_CMUX, MOD_CMUXUH)
task_module_map(INDX_CMUX, MOD_UPS_HIGH)

/*task's parameters*/
task_name("CMUX")
task_queue_name("CMUX Q")
task_priority(TASK_PRIORITY_CMUX , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
#if (defined(__CMUX_SUPPORT__) || defined(__USB_TETHERING__) || defined(__MBIM_SUPPORT__)) && !defined(__CMUX_TASK_DISABLE__)
task_create_function(cmux_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(INT_Q_LEN)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

   


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_L1SP) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L1SP,MOD_DUMMY_L1SP)
/*module_type and mod_task_g*/
task_module_map(INDX_L1SP, MOD_L1SP)

/*task's parameters*/
task_name("AUDIO")
task_queue_name("AUDIO Q")
task_priority(TASK_PRIORITY_L1AUDIO , KAL_TASK_INITIAL_PRIORITY )
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
task_create_function(l1sp_create)
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

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_L1AUDIO_SPH_SRV)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L1AUDIO_SPH_SRV,MOD_DUMMY_L1AUDIO_SPH_SRV)
/*module_type and mod_task_g*/
task_module_map(INDX_L1AUDIO_SPH_SRV, MOD_L1AUDIO_SPH_SRV)

/*task's parameters*/
task_name("L1AUDIO_SPH_SRV")
task_queue_name("L1AUDIO_SPH_SRV Q")
task_priority(TASK_PRIORITY_L1AUDIO_SPH_SRV , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
#if defined(L1_NOT_PRESENT) || defined (__UE_SIMULATOR__) || defined(__L1AUDIO_SPH_SRV_TASK_DISABLE__)
null_task_create_entry(NULL)
#else
task_create_function(l1audio_sph_srv_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
task_index(INDX_MED) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_MED,MOD_DUMMY_MED)
/*module_type and mod_task_g*/
task_module_map(INDX_MED, MOD_MED)
compatible_code(MOD_AUD=MOD_MED)    
/* MOD_MED is used by HAL file, please don't delete or modify it */

/*task's parameters*/
task_name("MED")
task_queue_name("MED Q")
task_priority(TASK_PRIORITY_MED , KAL_TASK_INITIAL_PRIORITY )

#ifdef __LOW_COST_SUPPORT_ULC__
task_stack_size(2048)
#elif defined( __CMMB_SUPPORT__ )
task_stack_size(4096)
#else
task_stack_size(3072)
#endif /* __CMMB_SUPPORT__ */
#if defined(__LTE_SM__)||defined(__MED_TASK_DISABLE__)
null_task_create_entry(NULL)
#else /* __LTE_SM__ */
task_create_function(med_create)
#endif /* __LTE_SM__ */
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(50)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
task_index(INDX_IDLE) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_IDLE,MOD_DUMMY_IDLE)
/*module_type and mod_task_g*/
task_module_map(INDX_IDLE, MOD_IDLE)

/*task's parameters*/
task_name("IDLE")
task_queue_name("IDLE Q")
task_priority(TASK_PRIORITY_IDLE , KAL_TASK_INITIAL_PRIORITY )
#if defined(__ESL_COSIM_LTE__) || defined(__EL2_HRT_EVALUATION__)
task_stack_size(4096*2)
#else /* __ESL_COSIM_LTE__ || __EL2_HRT_EVALUATION__*/
task_stack_size(512)
#endif /* __ESL_COSIM_LTE__ */
#if defined(__MTK_TARGET__) && (!defined(__IDLE_TASK_DISABLE__))
task_create_function(idle_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
#if defined(__ESL_COSIM_LTE__)
task_external_queue_size(10)
task_internal_queue_size(10)
#else /* __ESL_COSIM_LTE__ */
task_external_queue_size(0)
task_internal_queue_size(0)
#endif /* __ESL_COSIM_LTE__ */
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_SDIOCORE)

/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SDIOCORE, MOD_DUMMY_SDIOCORE)
/*module_type and mod_task_g*/
task_module_map(INDX_SDIOCORE, MOD_SDIOCORE)

/*task's parameters*/
task_name("SDIOCORE")
task_queue_name("SDIOCORE Q")
task_priority(TASK_PRIORITY_SDIOCORE, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__SDIOCORE_SUPPORT__) && !defined(SDIOCORE_NOT_PRESENT) && !defined(__SDIOCORE_TASK_DISABLE__)
task_create_function(sdioc_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/



/*************************Task CFG Begin****************/
task_index(INDX_TEST_PCORE1)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_multi_core_module_map(INDX_TEST_PCORE1,MOD_DUMMY_TEST1)
/*module_type and mod_task_g*/
task_multi_core_module_map(INDX_TEST_PCORE1, MOD_TEST1n1)
task_multi_core_module_map(INDX_TEST_PCORE1, MOD_TEST1n2)
/*task's parameters*/
task_name("DBP1")
task_queue_name("DBP1 Q")
task_priority(TASK_PRIORITY_TEST1_1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
#if defined(__TEMP_KTEST__) || defined(__TEMP_KTEST_2__) || defined(__TEMP_KTEST_DSM__)
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
task_index(INDX_TEST_PCORE2)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_multi_core_module_map(INDX_TEST_PCORE2,MOD_DUMMY_TEST2)
/*module_type and mod_task_g*/
task_multi_core_module_map(INDX_TEST_PCORE2, MOD_TEST2n1)
task_multi_core_module_map(INDX_TEST_PCORE2, MOD_TEST2n2)
/*task's parameters*/
task_name("DBP2")
task_queue_name("DBP2 Q")
task_priority(TASK_PRIORITY_TEST1_2 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
#if defined(__TEMP_KTEST__) || defined(__TEMP_KTEST_2__) || defined(__TEMP_KTEST_DSM__)
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
/*task_indx_type*/
task_index(INDX_CCISMCORE_IT)

/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCISMCORE_IT, MOD_DUMMY_CCISMCORE_IT)
/*module_type and mod_task_g*/
task_module_map(INDX_CCISMCORE_IT, MOD_CCISMCORE_IT)

/*task's parameters*/
task_name("ITCCISMCORE")
task_queue_name("ITCCISMCORE Q")
task_priority(TASK_PRIORITY_CCISMCORE_IT, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)   //stack size
#if defined(__CCISMCORE_IT__)
task_create_function(ccismcit_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)    //external queue
task_internal_queue_size(0)     //internal queue
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_CCISMCORE)

/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCISMCORE, MOD_DUMMY_CCISMCORE)
/*module_type and mod_task_g*/
task_module_map(INDX_CCISMCORE, MOD_CCISMCORE)

/*task's parameters*/
task_name("CCISMCORE")
task_queue_name("CCISMCORE Q")
task_priority(TASK_PRIORITY_CCISMCORE, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(3072)   //stack size
#if defined(__CCISMCORE_SUPPORT__)
task_create_function(ccismc_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(15)    //external queue
task_internal_queue_size(0)    //internal queue
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
/*
will use a file to record this 

the customer will define task id at this file
*/
/*************************Task CFG END******************/

/* drv*/
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_EINT_HISR)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_UART1_HISR)  
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_UART2_HISR) 
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_UART3_HISR) 
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_RTC_HISR) 
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_MSDC_HISR) 
#if defined(__MEUT__)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_GPTA_HISR1)
#endif

MODULE_ID_FOR_PRINT_TRACE(MOD_DP_ENGINE)
MODULE_ID_FOR_PRINT_TRACE(MOD_PPP_HW)
MODULE_ID_FOR_PRINT_TRACE(MOD_SIM_DRV)
MODULE_ID_FOR_PRINT_TRACE(MOD_PMU)
MODULE_ID_FOR_PRINT_TRACE(MOD_PMIC)
MODULE_ID_FOR_PRINT_TRACE(MOD_LPWR)
MODULE_ID_FOR_PRINT_TRACE(MOD_F32K)
MODULE_ID_FOR_PRINT_TRACE(MOD_PWM)
MODULE_ID_FOR_PRINT_TRACE(MOD_UART)

MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_DRV_DBG)
MODULE_ID_FOR_PRINT_TRACE(MOD_TTY)
MODULE_ID_FOR_PRINT_TRACE(MOD_DSPFM)
MODULE_ID_FOR_PRINT_TRACE(MOD_DEVDRV)
MODULE_ID_FOR_PRINT_TRACE(MOD_EMI)

MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_VISUAL_HISR)
 
MODULE_ID_FOR_PRINT_TRACE(MOD_BMT)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_ECT)

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_SPH_EVS)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SPH_EVS,MOD_DUMMY_SPH_EVS)
/*module_type and mod_task_g*/
task_module_map(INDX_SPH_EVS, MOD_SPH_EVS)

/*task's parameters*/
task_name("SPH_EVS")
task_queue_name("SPH_EVS Q")
task_priority(TASK_PRIORITY_SPH_EVS , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(66000)
#if defined(L1_NOT_PRESENT) || defined (__UE_SIMULATOR__) || defined(__L1AUDIO_SPH_SRV_TASK_DISABLE__) || !defined(__EVS_SUPPORT__)
null_task_create_entry(NULL)
#else
task_create_function(sph_evs_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/


 /**** customer added task or module id is started  *****/


 
 /**** customer added task or module id is ended    *****/

#if defined(ATEST_ENABLE) && defined(ATEST_DRV_ENABLE) && defined(__MTK_TARGET__)
    #include "drvtest_task_config.h"
#endif /* end of __MTK_DRVTEST_ENABLE__ */


 
 /*************************Task CFG Begin****************/
 /*task_indx_type*/
 /* this is a fake task for task id grouping*/
 task_index(TASK_ID_DRV_CODE_TAIL)
 /*module_type and mod_task_g*/
 task_module_map(TASK_ID_DRV_CODE_TAIL, MODULE_TAG_DRV_DUMMY_TAIL)
 
 /*task's parameters*/
 task_name("")
 task_queue_name("")
task_priority(KAL_TASK_INITIAL_PRIORITY , KAL_TASK_INITIAL_PRIORITY)
 task_stack_size(0)
 null_task_create_entry(NULL)
 task_stack_internalRAM(KAL_FALSE)
 task_external_queue_size(0)
 task_internal_queue_size(0)
 task_boot_mode(NORMAL_M)
 /*************************Task CFG END******************/
/********************** Driver End **************************/
 
#endif /*TASK_PRIORITY_MACRO*/
