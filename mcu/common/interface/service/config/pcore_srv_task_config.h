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
 *   pcore_srv_task_config.h
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef TASK_PRIORITY_MACRO

#define TASK_PRIORITY_SS_RESERVE_0              (KAL_PRIORITY_CLASS0  + 0)
#define TASK_PRIORITY_SS_RESERVE_1              (KAL_PRIORITY_CLASS0  + 1)
#define TASK_PRIORITY_SS_RESERVE_2              (KAL_PRIORITY_CLASS0  + 2)

#define TASK_PRIORITY_DHLDBG                    (KAL_PRIORITY_CLASS0  + 4)
#define TASK_PRIORITY_DHLR_2ND                  (KAL_PRIORITY_CLASS0  + 5)
#define TASK_PRIORITY_DHLRT                     (KAL_PRIORITY_CLASS2  + 9)/* DHLRT priority = TASK_PRIORITY_ERT + 1 */
#define TASK_PRIORITY_DHLHD                     (KAL_PRIORITY_CLASS7  + 4)
/* 
 * need high priority to flush log 
 * prevent high CPU Loading to cause log buffer full.
 */
#define TASK_PRIORITY_QBM                       (KAL_PRIORITY_CLASS4  + 8)

#define TASK_PRIORITY_DHL2                      (KAL_PRIORITY_CLASS13 + 6)

#define TASK_PRIORITY_CCCISRV                   (KAL_PRIORITY_CLASS14 + 8)

#if !defined(KAL_ON_OSCAR)
#define TASK_PRIORITY_DHLR                      (KAL_PRIORITY_CLASS18 + 8)
#endif

#define TASK_PRIORITY_DHLSPR                    (KAL_PRIORITY_CLASS19 + 0)/* DHL SP Logging Reader */

#define TASK_PRIORITY_CCCI_IT_CTRL              (KAL_PRIORITY_CLASS19 + 6)
#define TASK_PRIORITY_CCCI_IT_CTRL_TASK1        (KAL_PRIORITY_CLASS19 + 7)
#define TASK_PRIORITY_CCCI_IT_CTRL_TASK2        (KAL_PRIORITY_CLASS19 + 8)
#define TASK_PRIORITY_CCCI_IT_CTRL_TASK3        (KAL_PRIORITY_CLASS19 + 9)
#define TASK_PRIORITY_CCCI_IT_CTRL_TASK4        (KAL_PRIORITY_CLASS20 + 0)

#define TASK_PRIORITY_NVRAM                     (KAL_PRIORITY_CLASS20 + 4)

#if defined(KAL_ON_OSCAR)
#define TASK_PRIORITY_DHLSIM                    (KAL_PRIORITY_CLASS23 + 1)
#endif

#define TASK_PRIORITY_P_EXCEP_RESERVE_0         (KAL_PRIORITY_CLASS23 + 2)
#define TASK_PRIORITY_P_EXCEP_TEST              (KAL_PRIORITY_CLASS23 + 3)
#define TASK_PRIORITY_P_EXCEP_RESERVE_1         (KAL_PRIORITY_CLASS23 + 4)

/* DHL+1 and DHL-1 is reverve for eutest task @ pcore_modem_4g_task_config.h */
#define TASK_PRIORITY_RESERVE_EUTEST_1          (KAL_PRIORITY_CLASS23 + 5)
#define TASK_PRIORITY_DHL                       (KAL_PRIORITY_CLASS23 + 6)
#define TASK_PRIORITY_RESERVE_EUTEST_2          (KAL_PRIORITY_CLASS23 + 7)

#define TASK_PRIORITY_DHL_MON                   (KAL_PRIORITY_CLASS23 + 8)

#define TASK_PRIORITY_P_MDDBG                   (KAL_PRIORITY_CLASS25 + 0)
#if defined(KAL_ON_OSCAR)
#define TASK_PRIORITY_DHLR                      (KAL_PRIORITY_CLASS25 + 1)
#endif

#else
/*module id are divided into 3 parts.
 * 1: module id that maps to task
 * 2: module id that maps to no task but can be used as src module id
 * to allocate ilm, like HISR's module id
 * 3: module id that is used to print trace only.  * */


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_NIL = TASK_ID_SRV_CODE_BEGIN)
/*module_type and mod_task_g*/
/*task_module_map(INDX_NIL, MOD_NIL=0)*/
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_NIL, MOD_DUMMY_NIL = MOD_ID_SRV_CODE_BEGIN)

/*task's parameters*/
task_name("")
task_queue_name("")
task_priority(KAL_TASK_INITIAL_PRIORITY , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(0)
null_task_create_entry(NULL)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*NVRAM must be the first created task, this is restricted by L1 */
/*task_indx_type*/
task_index(INDX_NVRAM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_NVRAM,MOD_DUMMY_NVRAM)
/*module_type and mod_task_g*/
task_module_map(INDX_NVRAM, MOD_NVRAM)

/*task's parameters*/
task_name("NVRAM")
task_queue_name("NVRAM Q")
task_priority(TASK_PRIORITY_NVRAM , KAL_TASK_INITIAL_PRIORITY )
#if defined(__LOW_COST_SUPPORT_ULC__)
task_stack_size(1988)
#elif defined(LOW_COST_SUPPORT)
task_stack_size(2048)
#else
task_stack_size(2176)
#endif /* LOW_COST_SUPPORT */

#if defined(NVRAM_NOT_PRESENT) || defined(__NVRAM_TASK_DISABLE__)  /*XXX Note: It's best to wrap the whole section with this*/
null_task_create_entry(NULL)
#else
task_create_function(nvram_create)
#endif

task_stack_internalRAM(KAL_FALSE)

task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
#if defined(__DHL_MODULE__) && !defined(L1_SIM) || defined(__UE_SIMULATOR__)
/*task_indx_type*/
task_index(INDX_DHL) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHL,MOD_DUMMY_DHL)
/*module_type and mod_task_g*/

task_module_map(INDX_DHL, MOD_DHL)
#if defined(GEN_FOR_CPARSER)
task_module_map(INDX_DHL, MOD_TST = MOD_DHL)
#endif

//task's parameters
task_name("DHL")
task_queue_name("DHL Q")
task_priority(TASK_PRIORITY_DHL, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1248)
#if !defined(__DHL_TASK_DISABLE__)
task_create_function(dhl_create)
#else
null_task_create_entry(NULL)    
#endif
#if defined(__GSM_RAT__) && defined(__MD2__)
task_stack_internalRAM(KAL_FALSE)
#else
task_stack_internalRAM(KAL_TRUE)
#endif
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)

#if !defined(INDX_TST)
    #define INDX_TST INDX_DHL
#endif /* end of !INDX_TST */

#if !defined(MOD_TST)
	#define MOD_TST MOD_DHL
#endif

#endif /*__TST_MODULE__*/
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
#if defined(__DHL_MODULE__) && defined(__MTK_TARGET__) && !defined(L1_SIM) && defined(__KAL_CROSS_CORE_SUPPORT__)
/*task_indx_type*/
task_index(INDX_DHL2)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHL2,MOD_DUMMY_DHL2)
/*module_type and mod_task_g*/
task_module_map(INDX_DHL2, MOD_DHL2)

//task's parameters
task_name("DHL2")
task_queue_name("DHL2 Q")
task_priority(TASK_PRIORITY_DHL2, KAL_TASK_INITIAL_PRIORITY)
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


/*************************Task CFG Begin******************/
#if defined(__DHL_MODULE__) && !defined(L1_SIM) || defined(__UE_SIMULATOR__)
/*task_indx_type*/
task_index(INDX_DHL_READER) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHL_READER,MOD_DUMMY_DHL_READER)
/*module_type and mod_task_g*/
task_module_map(INDX_DHL_READER, MOD_DHL_READER)
#if defined(GEN_FOR_CPARSER)
task_module_map(INDX_DHL_READER, MOD_TST_READER = MOD_DHL_READER)
#endif
/* fix MOD_TST_READER=3, this is restricted by META tool */

//task's parameters
task_name("DR")
task_queue_name("DR Q")
task_priority(TASK_PRIORITY_DHLR, TASK_PRIORITY_DHLR_2ND)
#if defined(LOW_COST_SUPPORT)
task_stack_size(1024)
#else
task_stack_size(2304)
#endif
#if !defined(__DHLDR_TASK_DISABLE__)
task_create_function(dhl_reader_create)
#else
null_task_create_entry(NULL)    
#endif

task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(50)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)

#if !defined(INDX_TST_READER)
    #define INDX_TST_READER  INDX_DHL_READER
#endif /* end of !INDX_TST_READER */

#if !defined(MOD_TST_READER)
	#define MOD_TST_READER MOD_DHL_READER
#endif

#endif /*__TST_MODULE__*/
/*************************Task CFG END******************/


/*************************Task CFG Begin******************/
#if (defined(__UE_SIMULATOR__) || defined(UNIT_TEST)) && defined (__DHL_MODULE__)
/*task_indx_type*/
task_index(INDX_DHLSIM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHLSIM,MOD_DUMMY_DHLSIM)
/*module_type and mod_task_g*/
task_module_map(INDX_DHLSIM, MOD_DHLSIM)

//task's parameters
task_name("DHLX")
task_queue_name("DHLX Q")
task_priority(TASK_PRIORITY_DHLSIM, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
#ifndef L1_SIM
task_create_function(dhlsim_create)
#else
null_task_create_entry(NULL)
#endif

task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
#endif /*!__MTK_TARGET__ && __DHL_MODULE__*/
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
#if (defined (__UE_SIMULATOR__) || (UNIT_TEST)) && defined (__DHL_MODULE__)
/*task_indx_type*/
task_index(INDX_DHLDBG) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHLDBG,MOD_DUMMY_DHLDBG)
/*module_type and mod_task_g*/
task_module_map(INDX_DHLDBG, MOD_DHLDBG)

//task's parameters
task_name("DHLDBG")
task_queue_name("DHLDBG Q")
task_priority(TASK_PRIORITY_DHLDBG, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
#ifndef L1_SIM
task_create_function(dhl_dbg_create)
#else
null_task_create_entry(NULL)
#endif

task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(10)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
#endif /* __DHL_MODULE__*/
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
#if defined (__DHL_MODULE__) && !defined(L1_SIM) || defined(__UE_SIMULATOR__)
/*task_indx_type*/
task_index(INDX_DHLRT) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHLRT,MOD_DUMMY_DHLRT)
/*module_type and mod_task_g*/
task_module_map(INDX_DHLRT, MOD_DHLRT)

//task's parameters
task_name("DHLRT")
task_queue_name("DHLRT Q")
task_priority(TASK_PRIORITY_DHLRT, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
#if !defined(__DHLRT_TASK_DISABLE__)
task_create_function(dhl_rt_create)
#else
null_task_create_entry(NULL)    
#endif


task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
#endif /* __DHL_MODULE__*/
/*************************Task CFG END******************/

/******!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!****/
/******!!!!DON NOT add new task before this line !!*****/
/******!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!****/


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_CCCISRV)

/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCISRV, MOD_DUMMY_CCCISRV)

/*module_type and mod_task_g*/
task_module_map(INDX_CCCISRV, MOD_CCCISRV)
task_module_map(INDX_CCCISRV, MOD_CCCIFS)
task_module_map(INDX_CCCISRV, MOD_CCCIIPC)
task_module_map(INDX_CCCISRV, MOD_CCCIRPC)
task_module_map(INDX_CCCISRV, MOD_CCCIMSG)
task_module_map(INDX_CCCISRV, MOD_CCCI)

/*task's parameters*/
task_name("SRVCCCI")
task_queue_name("SRVCCCI Q")
task_priority(TASK_PRIORITY_CCCISRV, KAL_TASK_INITIAL_PRIORITY)
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
task_index(INDX_CCCI_IT_CTRL)

/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCI_IT_CTRL, MOD_DUMMY_CCCI_IT_CTRL)
task_module_map(INDX_CCCI_IT_CTRL, MOD_CCCI_IT_CTRL)
	
/*task's parameters*/
task_name("CTRLCCCI")
task_queue_name("CTRLCCCI Q")
task_priority(TASK_PRIORITY_CCCI_IT_CTRL, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__CCCI_IT_CTRL__) && !defined(__CCCI_IT_CTRL_TASK_DISABLE__)
task_create_function(ccci_it_ctrl_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)


/*task_indx_type*/
task_index(INDX_CCCI_IT_CTRL_TASK1)
	
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCI_IT_CTRL_TASK1, MOD_DUMMY_CCCI_IT_CTRL_TASK1)
task_module_map(INDX_CCCI_IT_CTRL_TASK1, MOD_CCCI_IT_CTRL_TASK1)
	
/*task's parameters*/
task_name("1CTRL1CCCI")
task_queue_name("1CTRLCCCI Q")
task_priority(TASK_PRIORITY_CCCI_IT_CTRL_TASK1, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__CCCI_IT_CTRL__) && !defined(__CCCI_IT_CTRL_T1_TASK_DISABLE__)
task_create_function(ccci_it_ctrl_task1_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

/*task_indx_type*/
task_index(INDX_CCCI_IT_CTRL_TASK2)
	
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCI_IT_CTRL_TASK2, MOD_DUMMY_CCCI_IT_CTRL_TASK2)
task_module_map(INDX_CCCI_IT_CTRL_TASK2, MOD_CCCI_IT_CTRL_TASK2)
	
/*task's parameters*/
task_name("2CTRLCCCI")
task_queue_name("2CTRLCCCI Q")
task_priority(TASK_PRIORITY_CCCI_IT_CTRL_TASK2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__CCCI_IT_CTRL__) && !defined(__CCCI_IT_CTRL_T2_TASK_DISABLE__)
task_create_function(ccci_it_ctrl_task2_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

/*task_indx_type*/
task_index(INDX_CCCI_IT_CTRL_TASK3)
	
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCI_IT_CTRL_TASK3, MOD_DUMMY_CCCI_IT_CTRL_TASK3)
task_module_map(INDX_CCCI_IT_CTRL_TASK3, MOD_CCCI_IT_CTRL_TASK3)
	
/*task's parameters*/
task_name("3CTRLCCCI")
task_queue_name("3CTRLCCCI Q")
task_priority(TASK_PRIORITY_CCCI_IT_CTRL_TASK3, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__CCCI_IT_CTRL__) && !defined(__CCCI_IT_CTRL_T3_TASK_DISABLE__)
task_create_function(ccci_it_ctrl_task3_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

/*task_indx_type*/
task_index(INDX_CCCI_IT_CTRL_TASK4)
	
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CCCI_IT_CTRL_TASK4, MOD_DUMMY_CCCI_IT_CTRL_TASK4)
task_module_map(INDX_CCCI_IT_CTRL_TASK4, MOD_CCCI_IT_CTRL_TASK4)
	
/*task's parameters*/
task_name("4CTRLCCCI")
task_queue_name("4CTRLCCCI Q")
task_priority(TASK_PRIORITY_CCCI_IT_CTRL_TASK4, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
#if defined(__CCCI_IT_CTRL__) && !defined(__CCCI_IT_CTRL_T4_TASK_DISABLE__)
task_create_function(ccci_it_ctrl_task4_create)
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
task_index(INDX_QBM)  
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_QBM,MOD_DUMMY_QBM)
task_module_map(INDX_QBM, MOD_QBM)
/*task's parameters*/
task_name("QBM")
task_queue_name("QBM Q")
task_priority(TASK_PRIORITY_QBM , KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1298)
#if defined(__DHL_MODULE__)  && !defined(__ESL_COSIM_LTE__)
task_create_function(qbm_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_MDDBG) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_multi_core_module_map(INDX_MDDBG, MOD_DUMMY_MDDBG)
task_multi_core_module_map(INDX_MDDBG, MOD_MDDBG)
/*task's parameters*/
task_name("P_MDDBG")
task_queue_name("P_MDDBG Q")
task_priority(TASK_PRIORITY_P_MDDBG, KAL_TASK_INITIAL_PRIORITY)
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


/*************************Task CFG Begin******************/
#if defined (__DHL_MODULE__) && defined(__MTK_TARGET__) && defined(__DHL_SP_LOGGING_SUPPORT__)
/*task_indx_type*/
task_index(INDX_DHLSPR) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHLSPR,MOD_DUMMY_DHLSPR)
/*module_type and mod_task_g*/
task_module_map(INDX_DHLSPR, MOD_DHL_SP_READER)

//task's parameters
task_name("DHL_SPR")
task_queue_name("DHL_SPR Q")
task_priority(TASK_PRIORITY_DHLSPR, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(2560)
task_create_function(dhl_sp_reader_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(50)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M|FACTORY_M)
#endif /* __DHL_MODULE__*/
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_EX_TEST) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_multi_core_module_map(INDX_EX_TEST, MOD_DUMMY_EXTEST)
task_multi_core_module_map(INDX_EX_TEST, MOD_EXTEST)
/*task's parameters*/
task_name("P_EX_TEST")
task_queue_name("P_EX_TEST Q")
task_priority(TASK_PRIORITY_P_EXCEP_TEST, KAL_TASK_INITIAL_PRIORITY)
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
#if defined (__DHL_MODULE__) && !defined(L1_SIM) || defined(__UE_SIMULATOR__)
/*task_indx_type*/
task_index(INDX_DHLHD) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHLHD,MOD_DUMMY_DHLHD)
/*module_type and mod_task_g*/
task_module_map(INDX_DHLHD, MOD_DHLHD)

//task's parameters
task_name("DHLHD")
task_queue_name("DHLHD Q")
task_priority(TASK_PRIORITY_DHLHD , KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1248)
#if !defined(__DHLRT_TASK_DISABLE__)
task_create_function(dhl_hd_create)
#else
null_task_create_entry(NULL)    
#endif


task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
#endif /* __DHL_MODULE__*/
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
#if defined(__DHL_MODULE__) && !defined(L1_SIM)
/*task_indx_type*/
task_index(INDX_DHL_MON) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DHL_MON,MOD_DUMMY_DHL_MON)
/*module_type and mod_task_g*/
task_module_map(INDX_DHL_MON, MOD_DHL_MON)

//task's parameters
task_name("DHLMON")
task_queue_name("DHLMON Q")
task_priority(TASK_PRIORITY_DHL_MON, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1248)
#if !defined(__DHL_TASK_DISABLE__) && defined(__MTK_TARGET__)
task_create_function(dhl_mon_create)
#else
null_task_create_entry(NULL)    
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

#ifndef __TST_MODULE__
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_DHL)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_DHL_READER)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_TST)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_TST_READER)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_TST_FTRANS)
#endif
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_TIMER)

MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_SYSTEM)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_EVENT_INFO)

MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_FLC)

MODULE_ID_FOR_PRINT_TRACE(MOD_HMU)

// print trace module id is not in mod_task_g 
MODULE_ID_FOR_PRINT_TRACE(MOD_SST_COMMON)
MODULE_ID_FOR_PRINT_TRACE(MOD_EX_LOG)

MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE(MOD_HLT)

MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_FS)


MODULE_ID_FOR_PRINT_TRACE(MOD_EARLY_LOG)

MODULE_ID_FOR_PRINT_TRACE(MOD_INIT_LOG)
/**** customer added task or module id is started  *****/


/**** customer added task or module id is ended    *****/

/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(TASK_ID_SRV_CODE_TAIL)
/*module_type and mod_task_g*/
task_module_map(TASK_ID_SRV_CODE_TAIL, MODULE_TAG_SRV_TAIL)

/*task's parameters*/
task_name("SRV_TAIL")
task_queue_name("")
task_priority(KAL_TASK_INITIAL_PRIORITY , KAL_TASK_INITIAL_PRIORITY)
task_stack_size(0)
null_task_create_entry(NULL)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

#endif /*TASK_PRIORITY_MACRO*/
