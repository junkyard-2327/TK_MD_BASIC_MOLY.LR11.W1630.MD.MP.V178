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
 *   stack_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the task index and module index configuration.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MODEM_4G_MODULE_ID_H
#define MODEM_4G_MODULE_ID_H

#include "module_id_range.h"

/* undef unused macro */
#undef TASK_PRIORITY_MACRO
#undef task_name
#undef task_queue_name
#undef task_priority
#undef task_stack_size
#undef null_task_create_entry
#undef compatible_code
#undef task_create_function
#undef task_stack_internalRAM
#undef task_external_queue_size
#undef task_internal_queue_size
#undef task_boot_mode
#undef MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM
#undef MODULE_ID_FOR_PRINT_TRACE
#undef task_index
#undef task_module_map

/* define all unused macros as empty */
#define task_name(p1)
#define task_queue_name(p1)
#define task_priority(p1,p2)
#define task_stack_size(p1)
#define null_task_create_entry(p1)
#define task_create_function(p1)
#define task_stack_internalRAM(p1)
#define task_external_queue_size(p1)
#define task_internal_queue_size(p1)
#define task_boot_mode(p1)
#define task_index(p1)



/* 1. general macro */
#define task_module_map(task, mod) mod,
#define compatible_code(expr) expr,
#define MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(mod) mod,
#define MODULE_ID_FOR_PRINT_TRACE(mod) mod,


/* 2. pcore MOD ID */
#undef task_multi_core_module_map
#undef task_multi_core_module_map_with_assignment
#undef multi_core_module_remap
#undef MODULE_ID_MULTI_CORE_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM
#undef MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE
#undef multi_core_compatible_code

#if defined(GEN_FOR_PC)
  /* Remove mod##_PCORE in database */
  #define task_multi_core_module_map(task, mod)                        mod,
  #define task_multi_core_module_map_with_assignment(task, mod1, mod2) mod1 = mod2,
  #define multi_core_compatible_code(expr)                             expr,
  #define MODULE_ID_MULTI_CORE_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(mod)  mod,
  #define MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE(mod)                    mod,
  #define multi_core_module_remap(mod)                                 mod
#else /* GEN_FOR_PC */
  #define task_multi_core_module_map(task, mod)                        mod##_PCORE,
  #define task_multi_core_module_map_with_assignment(task, mod1, mod2) mod1##_PCORE = mod2,
  #define multi_core_compatible_code(expr)                             expr##_PCORE,
  #define MODULE_ID_MULTI_CORE_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(mod)  mod##_PCORE,
  #define MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE(mod)                    mod##_PCORE,
  #define multi_core_module_remap(mod)                                 mod##_PCORE
#endif /* GEN_FOR_PC */

MODULE_MOD_BEGIN(MOD_ID_MODEM_4G_CODE_BEGIN)
    #include "pcore_modem_4g_task_config.h"
/* customer add module id at here */
MODULE_MOD_END(MOD_ID_MODEM_4G_CODE_TAIL)




/* 3. l1core MOD ID */
#undef task_multi_core_module_map
#undef task_multi_core_module_map_with_assignment
#undef multi_core_module_remap
#undef MODULE_ID_MULTI_CORE_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM
#undef MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE
#undef multi_core_compatible_code

#define task_multi_core_module_map(task, mod)                        mod##_L1CORE,
#define task_multi_core_module_map_with_assignment(task, mod1, mod2) mod1##_L1CORE = mod2,
#define multi_core_compatible_code(expr)                             expr##_L1CORE,
#define MODULE_ID_MULTI_CORE_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(mod)  mod##_L1CORE,
#define MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE(mod)                    mod##_L1CORE,
#define multi_core_module_remap(mod)                                 mod##_L1CORE

MODULE_MOD_BEGIN(MOD_ID_CO_PROCESSOR_MODEM_4G_CODE_BEGIN)
    #include "l1core_modem_4g_task_config.h"
MODULE_MOD_END(MOD_ID_CO_PROCESSOR_MODEM_4G_CODE_TAIL)


        
        
/* clean unuse defination */
#undef task_module_map
#undef compatible_code
#undef MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM
#undef MODULE_ID_FOR_PRINT_TRACE
        
#define task_module_map(p1,p2)
#define compatible_code(p1)
#define MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(p1)
#define MODULE_ID_FOR_PRINT_TRACE(p1)
        

/* 4. remap MOD ID */
#undef task_multi_core_module_map
#undef task_multi_core_module_map_with_assignment
#undef multi_core_compatible_code
#undef MODULE_ID_MULTI_CORE_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM
#undef MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE

#if !defined(GEN_FOR_PC)
  /* Remove redefined mod in database */
  #if defined(__PCORE__)
    #define task_multi_core_module_map(task, mod)                        mod  = mod##_PCORE,
    #define task_multi_core_module_map_with_assignment(task, mod1, mod2) mod1 = mod1##_PCORE,
    #define multi_core_compatible_code(expr)                             expr = expr##_PCORE,
    #define MODULE_ID_MULTI_CORE_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(mod)  mod  = mod##_PCORE,
    #define MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE(mod)                    mod  = mod##_PCORE,
  #else
    #define task_multi_core_module_map(task, mod)                        mod  = mod##_L1CORE,
    #define task_multi_core_module_map_with_assignment(task, mod1, mod2) mod1 = mod1##_L1CORE,
    #define multi_core_compatible_code(expr)                             expr = expr##_L1CORE,
    #define MODULE_ID_MULTI_CORE_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(mod)  mod  = mod##_L1CORE,
    #define MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE(mod)                    mod  = mod##_L1CORE,
  #endif

        
MODULE_MOD_BEGIN(MOD_ID_MODEM_4G_CODE_REMAP_BEGIN)  
    #include "modem_4g_task_config.h"
MODULE_MOD_END(MOD_ID_MODEM_4G_CODE_REMAP_TAIL)
#endif /* !GEN_FOR_PC */
        

/* 5. undef to to fix warning*/    
#undef task_multi_core_module_map
#undef task_multi_core_module_map_with_assignment
#undef multi_core_compatible_code
#undef MODULE_ID_MULTI_CORE_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM
#undef MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE
#undef multi_core_module_remap


#endif /* MODEM_4G_MODULE_ID_H */
