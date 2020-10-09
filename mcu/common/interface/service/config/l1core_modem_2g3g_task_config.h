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
 *   l1core_modem_2g3g_task_config.h
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


#define TASK_PRIORITY_TL1DATA      (KAL_PRIORITY_CLASS0  + 7)
#define TASK_PRIORITY_MMRF         (KAL_PRIORITY_CLASS0  + 9)

#define TASK_PRIORITY_L1           (KAL_PRIORITY_CLASS1  + 6)
#define TASK_PRIORITY_L1_2         (KAL_PRIORITY_CLASS1  + 7)
#define TASK_PRIORITY_L1_3         (KAL_PRIORITY_CLASS1  + 8)
#define TASK_PRIORITY_L1_4         (KAL_PRIORITY_CLASS1  + 9)

#define TASK_PRIORITY_GL1TST       (KAL_PRIORITY_CLASS4  + 2)
#define TASK_PRIORITY_UL1C         (KAL_PRIORITY_CLASS4  + 6)

#define TASK_PRIORITY_UL1          (KAL_PRIORITY_CLASS5  + 5)
#define TASK_PRIORITY_UL1TST       (KAL_PRIORITY_CLASS5  + 9)

#define TASK_PRIORITY_TL1          (KAL_PRIORITY_CLASS6  + 1)

#define TASK_PRIORITY_LAS          (KAL_PRIORITY_CLASS8  + 2)

#define TASK_PRIORITY_FTA          (KAL_PRIORITY_CLASS16 + 9)


#else
/*module id are divided into 3 parts. 
 * 1: module id that maps to task
 * 2: module id that maps to no task but can be used as src module id
 *  to allocate ilm, like HISR's module id
 * 3: module id that is used to print trace only.  * */

/*******************  Modem 2G3G start  **********************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(INDX_MODEM_START = TASK_ID_MODEM_2G3G_CODE_BEGIN)
/*module_type and mod_task_g*/
task_module_map(INDX_MODEM_START, MOD_CO_PROCESSOR_MODEM_DUMMY_BEGIN = MOD_ID_CO_PROCESSOR_MODEM_2G3G_CODE_BEGIN)
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


#if !defined(__U4G_ADAPTOR__)
/*************************Task CFG Begin****************/
#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
/*task_indx_type*/
task_index(INDX_UL1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_UL1,MOD_DUMMY_UL1)
/*module_type and mod_task_g*/

#if !defined(__EL1_IT__)
task_module_map(INDX_UL1, MOD_UL1)
#endif
#ifdef __GEMINI_WCDMA__
task_module_map(INDX_UL1, MOD_UL1_2)
#endif /* __GEMINI_WCDMA__ */

#if (GEMINI_PLUS_WCDMA >= 3)
task_module_map(INDX_UL1, MOD_UL1_3)
#if (GEMINI_PLUS_WCDMA >= 4)
task_module_map(INDX_UL1, MOD_UL1_4)
#endif
#endif

#if !defined(__MTK_TARGET__)
task_module_map(INDX_UL1, MOD_UL1D)
#endif

/*task's parameters*/
#if !defined(DUMMYL1)
task_name("UL1")
task_queue_name("UL1 Q")
#else
task_name("DUMMYUL1")
task_queue_name("DUMMYUL1 Q")
#endif
task_priority(TASK_PRIORITY_UL1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2800)
#if defined(UL1_NOT_PRESENT) || defined(__UL1_TASK_DISABLE__)
null_task_create_entry(NULL)
#else
task_create_function(ul1_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(10)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/
#endif

/*************************Task CFG Begin****************/
#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__) \
&& !defined(__MTK_TARGET__) && !defined(__UE_SIMULATOR__)
/*task_indx_type*/
task_index(INDX_UL1C) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_UL1C,MOD_DUMMY_UL1C)
/*module_type and mod_task_g*/
task_module_map(INDX_UL1C, MOD_UL1C)

/*task's parameters*/
task_name("UL1C")
task_queue_name("UL1C Q")
task_priority(TASK_PRIORITY_UL1C , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(25*1024)
#if (defined(DUMMYL1) && !defined(__UL1_ON_MNT__)) ||  defined(__UL1C_TASK_DISABLE__)
null_task_create_entry(NULL)
#else
task_create_function(ul1c_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task index here*/
task_index(INDX_GL1TST)
/* dummy module is specified to get task id by module id using mod_task_g, 
   please reserve a module id named MOD_DUMMY_taskname for every task. */
task_module_map(INDX_GL1TST, MOD_DUMMY_GL1TST)
/*task index to task module id mapping.  A task index can map to [1, N] module id*/
task_module_map(INDX_GL1TST, MOD_GL1TST)
task_name("GL1TST")
task_queue_name("GL1TST Q")
/* please set the second parameter with KAL_TASK_INITIAL_PRIORITY */
task_priority(TASK_PRIORITY_GL1TST,KAL_TASK_INITIAL_PRIORITY)
task_stack_size(3072)
   #if defined(__MTK_TARGET__)  && !defined(__MAUI_BASIC__) && !defined(__GL1TST_TASK_DISABLE__) && defined(__MTK_GL1_GSM__)
task_create_function(gl1tst_create)
   #else
null_task_create_entry(NULL)
   #endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(FACTORY_M)
/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_L1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L1,MOD_DUMMY_L1)
/*module_type and mod_task_g*/
#ifdef __GEMINI_GSM__
//this is for codegen
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L1_2,MOD_DUMMY_L1_2)
#if (GEMINI_PLUS_GSM >= 3)
task_module_map(INDX_L1_2,MOD_DUMMY_L1_3)
#endif
#if (GEMINI_PLUS_GSM >= 4)
task_module_map(INDX_L1_2,MOD_DUMMY_L1_4)
#endif
#endif

#if !defined(__EL1_IT__)
#ifdef DUMMYL1
task_module_map(INDX_DUMMYL1, MOD_L1)
#else
task_module_map(INDX_L1, MOD_L1)
#endif
#endif /* __EL1_IT__ */
#ifdef L1A_SIM
task_module_map(INDX_L1, MOD_L1C)
#endif
/*task's parameters*/
task_name("L1")
task_queue_name("L1 Q")
task_priority(TASK_PRIORITY_L1 , KAL_TASK_INITIAL_PRIORITY )
#if defined(__UMTS_RAT__)
task_stack_size(1536)
#else   /* __UMTS_RAT__ */
task_stack_size(1024)
#endif   /* __UMTS_RAT__ */
#if defined(L1_NOT_PRESENT) || defined(__L1_TASK_DISABLE__) || defined(DUMMYL1)
null_task_create_entry(NULL)
#else
task_create_function(l1_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
#ifdef __GEMINI_GSM__
 /*task_indx_type*/
task_index(INDX_L1_2) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_L1_2,MOD_DUMMY_L1_2)
/*module_type and mod_task_g*/
#ifdef DUMMYL1
task_module_map(INDX_DUMMYL1_2, MOD_L1_2)
#else
task_module_map(INDX_L1_2, MOD_L1_2)
#endif
#ifdef L1A_SIM
task_module_map(INDX_L1_2, MOD_L1C_2)
#endif
/*task's parameters*/
task_name("L1_2")
task_queue_name("L1_2 Q")
task_priority(TASK_PRIORITY_L1_2 , KAL_TASK_INITIAL_PRIORITY )
#if defined(__UMTS_RAT__)
task_stack_size(1536)
#else   /* __UMTS_RAT__ */
task_stack_size(1024)
#endif   /* __UMTS_RAT__ */
#if defined(L1_NOT_PRESENT) || defined(__L1_2_TASK_DISABLE__) || defined(DUMMYL1)
null_task_create_entry(NULL)
#else
task_create_function(l1_create_2)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef __GEMINI_GSM__
#if (GEMINI_PLUS_GSM >= 3)
/*task_indx_type*/
task_index(INDX_L1_3) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_L1_3,MOD_DUMMY_L1_3)
/*module_type and mod_task_g*/
#ifdef DUMMYL1
task_module_map(INDX_DUMMYL1_3, MOD_L1_3)
#else
task_module_map(INDX_L1_3, MOD_L1_3)
#endif

#ifdef L1A_SIM
task_module_map(INDX_L1_3, MOD_L1C_3)
#endif
/*task's parameters*/
task_name("L1_3")
task_queue_name("L1_3 Q")
task_priority(TASK_PRIORITY_L1_3 , KAL_TASK_INITIAL_PRIORITY )
#if defined(__UMTS_RAT__)
task_stack_size(1536)
#else   /* __UMTS_RAT__ */
task_stack_size(1024)
#endif   /* __UMTS_RAT__ */
#if defined(L1_NOT_PRESENT) || defined(__L1_3_TASK_DISABLE__) || defined(DUMMYL1)
null_task_create_entry(NULL)
#else
task_create_function(l1_create_3)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
#endif
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
#ifdef __GEMINI_GSM__
#if (GEMINI_PLUS_GSM >= 4)
/*task_indx_type*/
task_index(INDX_L1_4) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_L1_4,MOD_DUMMY_L1_4)
/*module_type and mod_task_g*/
#ifdef DUMMYL1
task_module_map(INDX_DUMMYL1_4, MOD_L1_4)
#else
task_module_map(INDX_L1_4, MOD_L1_4)
#endif
#ifdef L1A_SIM
task_module_map(INDX_L1_4, MOD_L1C_4)
#endif
/*task's parameters*/
task_name("L1_4")
task_queue_name("L1_4 Q")
task_priority(TASK_PRIORITY_L1_4 , KAL_TASK_INITIAL_PRIORITY )
#if defined(__UMTS_RAT__)
task_stack_size(1536)
#else   /* __UMTS_RAT__ */
task_stack_size(1024)
#endif   /* __UMTS_RAT__ */
#if defined(L1_NOT_PRESENT) || defined(__L1_4_TASK_DISABLE__) || defined(DUMMYL1)
null_task_create_entry(NULL)
#else
task_create_function(l1_create_4)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
#endif
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_UL1TST) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_UL1TST,MOD_DUMMY_UL1TST)
/*module_type and mod_task_g*/
task_module_map(INDX_UL1TST, MOD_UL1TST)

/*task's parameters*/
task_name("UL1TST")
task_queue_name("UL1TST Q")

task_priority(TASK_PRIORITY_UL1TST , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(3072)
#if defined(__MTK_UL1_FDD__) && defined(__MTK_TARGET__) && !defined(__UL1TST_TASK_DISABLE__)
task_create_function(ul1tst_create)
#else
null_task_create_entry(NULL)
#endif 
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(FACTORY_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/


#if defined(__MTK_TARGET__)
/* for Target */

/*task_indx_type*/
task_index(INDX_LAS) 

task_module_map(INDX_LAS,MOD_LAS)
task_module_map(INDX_LAS,MOD_LMOB)
task_module_map(INDX_LAS,MOD_LMOB_VIR)
task_module_map(INDX_LAS,MOD_LCEL)
task_module_map(INDX_LAS,MOD_LURR_FDD)
#ifdef __GEMINI_WCDMA__
task_module_map(INDX_LAS, MOD_LURR_FDD_2)
#if (GEMINI_PLUS_WCDMA >= 3)
task_module_map(INDX_LAS, MOD_LURR_FDD_3)
#if (GEMINI_PLUS_WCDMA >= 4)
task_module_map(INDX_LAS, MOD_LURR_FDD_4)
#endif /* GEMINI_PLUS_WCDMA >= 4 */
#endif /* GEMINI_PLUS_WCDMA >= 3 */
#endif /* __GEMINI_WCDMA__ */
task_module_map(INDX_LAS,MOD_LURR_TDD)

task_module_map(INDX_LAS,MOD_LMEME_FDD)
#ifdef __GEMINI_WCDMA__
task_module_map(INDX_LAS, MOD_LMEME_FDD_2)
#if (GEMINI_PLUS_WCDMA >= 3)
task_module_map(INDX_LAS, MOD_LMEME_FDD_3)
#if (GEMINI_PLUS_WCDMA >= 4)
task_module_map(INDX_LAS, MOD_LMEME_FDD_4)
#endif /* GEMINI_PLUS_WCDMA >= 4 */
#endif /* GEMINI_PLUS_WCDMA >= 3 */
#endif /* __GEMINI_WCDMA__ */
task_module_map(INDX_LAS,MOD_LMEME_TDD)

task_module_map(INDX_LAS,MOD_LCSCE_FDD)
#ifdef __GEMINI_WCDMA__
task_module_map(INDX_LAS, MOD_LCSCE_FDD_2)
#if (GEMINI_PLUS_WCDMA >= 3)
task_module_map(INDX_LAS, MOD_LCSCE_FDD_3)
#if (GEMINI_PLUS_WCDMA >= 4)
task_module_map(INDX_LAS, MOD_LCSCE_FDD_4)
#endif /* GEMINI_PLUS_WCDMA >= 4 */
#endif /* GEMINI_PLUS_WCDMA >= 3 */
#endif /* __GEMINI_WCDMA__ */

task_module_map(INDX_LAS,MOD_LCSCE_TDD)

task_module_map(INDX_LAS, MOD_GISE_FDD)
#if ((defined(GEMINI_PLUS_GSM) && (GEMINI_PLUS_GSM >= 2)) || defined(__GEMINI_GSM__) || defined(__SGLTE__))
task_module_map(INDX_LAS, MOD_GISE_FDD_2)
#if (defined(GEMINI_PLUS_GSM) && (GEMINI_PLUS_GSM >= 3))
task_module_map(INDX_LAS, MOD_GISE_FDD_3)
#if (defined(GEMINI_PLUS_GSM) && (GEMINI_PLUS_GSM >= 4))
task_module_map(INDX_LAS, MOD_GISE_FDD_4)
#endif /* (defined(GEMINI_PLUS_GSM) && (GEMINI_PLUS_GSM >= 4)) */
#endif /* (defined(GEMINI_PLUS_GSM) && (GEMINI_PLUS_GSM >= 3)) */
#endif /* ((defined(GEMINI_PLUS_GSM) && (GEMINI_PLUS_GSM >= 2)) || defined(__GEMINI_GSM__) || defined(__SGLTE__)) */

task_module_map(INDX_LAS, MOD_GISE_TDD)
#if ((defined(GEMINI_PLUS_GSM) && (GEMINI_PLUS_GSM >= 2)) || defined(__GEMINI_GSM__) || defined(__SGLTE__))
task_module_map(INDX_LAS, MOD_GISE_TDD_2)
#if (defined(GEMINI_PLUS_GSM) && (GEMINI_PLUS_GSM >= 3))
task_module_map(INDX_LAS, MOD_GISE_TDD_3)
#endif /* (defined(GEMINI_PLUS_GSM) && (GEMINI_PLUS_GSM >= 3)) */
#endif /* ((defined(GEMINI_PLUS_GSM) && (GEMINI_PLUS_GSM >= 2)) || defined(__GEMINI_GSM__) || defined(__SGLTE__)) */

task_module_map(INDX_LAS, MOD_LUMAC_TDD)
task_module_map(INDX_LAS, MOD_LURLC_TDD)
task_module_map(INDX_LAS, MOD_LRRCE_TDD)

/*task's parameters*/
task_name("LAS_PCORE")
task_queue_name("LAS Q")

task_priority(TASK_PRIORITY_LAS , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
#if defined(__LAS_TASK_DISABLE__)
null_task_create_entry(NULL)
#else
task_create_function(las_create)
#endif 
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(80)
task_internal_queue_size(80)
task_boot_mode(NORMAL_M | FACTORY_M)

#endif /*__MTK_TARGET__*/
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_MMRF) 
/*module_type and mod_task_g*/
task_module_map(INDX_MMRF, MOD_DUMMY_MMRF)
task_module_map(INDX_MMRF, MOD_MMRF)

/*task's parameters*/
task_name("MRF")
task_queue_name("MMRF Q")
task_priority(TASK_PRIORITY_MMRF, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4*1024)
#if !defined(__MAUI_BASIC__) && !defined(__MMRF_TASK_DISABLE__)
task_create_function(mmrf_create)
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
task_index(INDX_TL1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_TL1,MOD_DUMMY_TL1)
/*module_type and mod_task_g*/
task_module_map(INDX_TL1, MOD_TL1)

/*task's parameters*/
task_name("TL1")
task_queue_name("TL1 Q")
task_priority(TASK_PRIORITY_TL1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2500)
#if defined(__TL1_TASK_DISABLE__) || !defined(__UMTS_RAT__) || !defined(__UMTS_TDD128_MODE__)
null_task_create_entry(NULL)
#elif defined(__DUMMY_TL1__)
task_create_function(dummytl1_create)
#else
task_create_function(tl1_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_TL1DATA) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_TL1DATA,MOD_DUMMY_TL1DATA)
/*module_type and mod_task_g*/
task_module_map(INDX_TL1DATA, MOD_TL1DATA)

/*task's parameters*/
task_name("TL1DATA")
task_queue_name("TL1DATA Q")
task_priority(TASK_PRIORITY_TL1DATA , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2500)
#if defined(__TL1DATA_TASK_DISABLE__) || !defined(__UMTS_RAT__) || !defined(__UMTS_TDD128_MODE__)
null_task_create_entry(NULL)
#elif defined(__DUMMY_TL1__)
task_create_function(dummytl1data_create)
#else
task_create_function(tl1data_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_FTA)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_FTA,MOD_DUMMY_FTA)
/*module_type and mod_task_g*/
task_module_map(INDX_FTA, MOD_FTA)
/*task's parameters*/
task_name("FTA")
task_queue_name("FTA Q")
task_priority(TASK_PRIORITY_FTA , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(3072)
#if defined(__MTK_TARGET__) && !defined(__FTA_TASK_DISABLE__) && defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
task_create_function(fta_create)
#else
null_task_create_entry(NULL)
#endif 
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(40)
task_internal_queue_size(0)
task_boot_mode(FACTORY_M)
/*************************Task CFG END******************/



/**** customer added task or module id is started  *****/


/**** customer added task or module id is ended    *****/


/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(TASK_ID_MODEM_2G3G_CODE_TAIL)
/*module_type and mod_task_g*/
task_module_map(TASK_ID_MODEM_2G3G_CODE_TAIL, MODULE_TAG_CO_PROCESSOR_MODEM_DUMMY_TAIL)

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
