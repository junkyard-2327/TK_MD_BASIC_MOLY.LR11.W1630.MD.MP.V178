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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef HISR_MODULE_ID_H
#define HISR_MODULE_ID_H
#include "module_hisrid_range.h"
#include "module_id_range.h"


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
#undef task_multi_core_module_map
#undef task_multi_core_module_map_with_assignment
#undef multi_core_module_remap
#undef MODULE_ID_MULTI_CORE_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM
#undef MODULE_ID_MULTI_CORE_FOR_PRINT_TRACE
#if defined(__UNIFIED_ISR_LEVEL__)
#undef X_HISR_CONST_WITH_INTID
#undef X_HISR_INTID
#endif



/*II. MOD ID MAP to HISR*/


/* 1. general macro */
#define X_HISR_CONST(a,b,c,d,e,f,g) 
#define X_HISR_MOD(a,h) h,
#define MODULE_ID_FOR_PRINT_TRACE(mod) mod,
#if defined(__UNIFIED_ISR_LEVEL__)
#define X_HISR_CONST_WITH_INTID(a,b,c,d,e,f,g,i)
#define X_HISR_INTID(a,j)
#endif




/* 2. pcore MOD ID */
#undef X_MULTI_CORE_HISR_MOD
#if defined(GEN_FOR_PC)
  /* Remove mod##_PCORE in database */
  #define X_MULTI_CORE_HISR_MOD(a,h) h,
#else /* GEN_FOR_PC */
  #define X_MULTI_CORE_HISR_MOD(a,h) h##_PCORE,
#endif /* GEN_FOR_PC */

MODULE_MOD_BEGIN(MOD_ID_HISR_CODE_BEGIN)
    #include "pcore_hisr_config_internal.h"
MODULE_MOD_END( MOD_ID_HISR_CODE_TAIL )



    
/* 3. l1core MOD ID */
#undef X_MULTI_CORE_HISR_MOD
#define X_MULTI_CORE_HISR_MOD(a,h) h##_L1CORE,

MODULE_MOD_BEGIN(MOD_ID_CO_PROCESSOR_HISR_CODE_BEGIN)
    #include "l1core_hisr_config_internal.h"
MODULE_MOD_END(MOD_ID_CO_PROCESSOR_HISR_CODE_TAIL)




/* clean unuse defination */
#undef X_HISR_CONST
#undef X_HISR_MOD
#undef X_MULTI_CORE_HISR_MOD


/* 4. remap MOD ID */
#define X_HISR_CONST(a,b,c,d,e,f,g) 
#define X_HISR_MOD(a,h)

#if !defined(GEN_FOR_PC)
  /* Remove redefined mod in database */
  #if defined(__PCORE__)
    #define X_MULTI_CORE_HISR_MOD(a,h)   h = h##_PCORE,
  #else
    #define X_MULTI_CORE_HISR_MOD(a,h)   h=  h##_L1CORE,
  #endif

MODULE_MOD_BEGIN(MOD_ID_HISR_CODE_REMAP_BEGIN)
#include "hisr_config_internal.h"
MODULE_MOD_END(MOD_ID_HISR_CODE_REMAP_TAIL)
#endif /* !GEN_FOR_PC */

    
#undef X_HISR_CONST
#undef X_HISR_MOD
#undef X_MULTI_CORE_HISR_MOD
#if defined(__UNIFIED_ISR_LEVEL__)
#undef X_HISR_CONST_WITH_INTID
#undef X_HISR_INTID
#endif
#undef MODULE_ID_FOR_PRINT_TRACE




#endif /* HISR_MODULE_ID_H */


