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
 *   task_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the source code for configuring the
 *   data structures that hold task configuration info.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
	(C) _____ (year of first publication) Sasken communication
	Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

/*************************************************************************
* Include Statements
 *************************************************************************/
#include "kal_public_api.h"
#include "task_config.h"
#include "syscomp_config.h"
//#include "dcl.h"

#if defined(__ESL_COSIM_LTE__)
#include "dhl_trace.h"
#include "drv_hsl.h"
#endif /* __ESL_COSIM_LTE__ */

#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
//#include "fctycomp_config.h"
#endif /* __MULTI_BOOT__ */

#if !defined(KAL_PRIORITY_NODE_BY_CTRL_BUFF) && defined(__MTK_TARGET__)
#include "sys_mem_size.h"
#endif

#include "kal_internal_api.h"
#include "kal_internal_def.h"
#include "cache_sw.h"
#include "cpu.h"

/*************************************************************************
* Definitions Of Exported Globals
 *************************************************************************/
task_info_struct *task_info_g;
kal_uint32  KALTotalTasks;
kal_uint32  KALTotalModules;
typedef struct {
   kal_uint32    global_module;
   kal_uint32    local_module;
} module_remap_struct;
#ifdef SPLIT_SYS
extern const kal_uint8 tst_routing_table[];
/* Tasks created on target side */
kal_uint32 utontarget_task_mask_g[2];
/* Tasks created on PC side */
kal_uint32 utonmnt_task_mask_g[2];
#endif /* SPLIT_SYS */

#if !defined(KAL_PRIORITY_NODE_BY_CTRL_BUFF) && defined(__MTK_TARGET__)
kal_int_prio_list_t prio_node_array[GLOBAL_TOTAL_CREATED_TASK_NUMBER];
kal_uint32 prio_node_array_number = GLOBAL_TOTAL_CREATED_TASK_NUMBER;
#endif

extern const comptask_info_struct sys_comp_config_tbl[];

#if defined(__MTK_TARGET__) && !defined(__PCORE_ONLY__) && !defined(__L1CORE_ONLY__)
DEFINE_NC_SHARED_VAR(kal_uint32*, PCore_mod_task_g);
DEFINE_NC_SHARED_VAR(task_info_struct*, PCore_task_info_g);
DEFINE_NC_SHARED_VAR(kal_uint32*, L1Core_mod_task_g);
DEFINE_NC_SHARED_VAR(task_info_struct*, L1Core_task_info_g);
#endif

/*******************************************************************************
 * Internal Globals
 * these global array is used in kal files
 * they should be defined in config file since config internal macro is used as array size
 *******************************************************************************/
const module_remap_struct module_remap_array[] = 
{
	{0,0},
#if defined(__MD3__)
	#undef MODULE_ID_GLOBAL_MD3
	#define MODULE_ID_GLOBAL_MD3(module) {module##_MD3, module},
		#include "md3_module_config.h"
	#undef MODULE_ID_GLOBAL_MD3
#elif defined(__MD2__)
	#undef MODULE_ID_GLOBAL_MD2
	#define MODULE_ID_GLOBAL_MD2(module) {module##_MD2, module},
		#include "md2_module_config.h"
	#undef MODULE_ID_GLOBAL_MD2
#else
	#undef MODULE_ID_GLOBAL_MD1
	#undef MD1_PCORE_GLOBAL_MODULE_ID_BEGIN
	#undef MD1_L1CORE_GLOBAL_MODULE_ID_BEGIN
	#define MODULE_ID_GLOBAL_MD1(module) {module##_MD1, module},
	#define MD1_PCORE_GLOBAL_MODULE_ID_BEGIN
	#define MD1_L1CORE_GLOBAL_MODULE_ID_BEGIN
			#include "md1_module_config.h"
	#undef MODULE_ID_GLOBAL_MD1
	#undef MD1_PCORE_GLOBAL_MODULE_ID_BEGIN
	#undef MD1_L1CORE_GLOBAL_MODULE_ID_BEGIN
#endif
};

#ifdef __MTK_TARGET__
__attribute__ ((section ("INTSRAM_RW"))) 
#endif /* __MTK_TARGET__ */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
module_type task_active_module_g[ RPS_TOTAL_STACK_TASKS ];
#if defined(__MTK_TARGET__) && defined(__KAL_STACK_SHARING__)
const kal_uint8 Non_sharing_tasks_array_g[] = {
	INDX_BMT,
	INDX_TST_FTRANS,
#if ( !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
	INDX_FMT,		/* for fragment */
#endif	
#ifdef __TST_MODULE__		
	INDX_TST, 		/* waiting event */
#endif
	INDX_IDLER,		/* waiting event */
	INDX_L1SP,		/* waiting event */
#ifdef PLUTO_MMI	
	INDX_GDC		/* waiting event */
#endif
};
#endif
/*************************************************************************
* Declarations Of Imported functions
 *************************************************************************/
extern void remap_mod_task_g(void);

extern void *kal_sys_mem_alloc(kal_uint32 size);

#ifdef __MULTI_BOOT__
extern kal_uint16 INT_BootMode(void);
#endif   /* __MULTI_BOOT__ */

/*************************************************************************
 * FUNCTION:
 *  remap_task_index
 *
 * DESCRIPTION:
 *  adjust index for save RAM, should call this function when refer task_info_g[task_index]
 *
 * PARAMETERS:
 *   module_type
 
 * RETURNS
 *   task indx: the order in task_info_g[]
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
kal_uint32 remap_task_index(kal_uint32 task_indx)
{
	/* should rewrite this function once task id group is rearranged */

	kal_uint32 task_index = task_indx;

	if(task_index > TASK_ID_DRV_CODE_TAIL || task_index > TASK_ID_CODE_MAX)
	{
		return 0;
	}
	
	if(task_indx >= TASK_ID_MODEM_2G3G_CODE_BEGIN)
	{
		/* SRV group */
		task_index = TASK_ID_SRV_CODE_TAIL;
		
		if(task_indx < TASK_ID_MODEM_4G_CODE_BEGIN)
		{
			/* 2G3G MODEM group */
			task_index += (task_indx - TASK_ID_MODEM_2G3G_CODE_BEGIN + 1);
		}
        else if(task_indx < TASK_ID_MW_CODE_BEGIN)
		{
			/* 4G MODEM group */
			task_index += (TASK_ID_MODEM_2G3G_CODE_TAIL - TASK_ID_MODEM_2G3G_CODE_BEGIN + 1);
			task_index += (task_indx - TASK_ID_MODEM_4G_CODE_BEGIN + 1);
		}
		else if(task_indx < TASK_ID_DRV_CODE_BEGIN)
		{
			/* MW group */
			task_index += (TASK_ID_MODEM_2G3G_CODE_TAIL - TASK_ID_MODEM_2G3G_CODE_BEGIN + 1);
			task_index += (TASK_ID_MODEM_4G_CODE_TAIL - TASK_ID_MODEM_4G_CODE_BEGIN + 1);
			task_index += (task_indx - TASK_ID_MW_CODE_BEGIN + 1);
		}
        else
		{
			/* DRV group */
			task_index += (TASK_ID_MODEM_2G3G_CODE_TAIL - TASK_ID_MODEM_2G3G_CODE_BEGIN + 1);
			task_index += (TASK_ID_MODEM_4G_CODE_TAIL - TASK_ID_MODEM_4G_CODE_BEGIN + 1); 
			task_index += (TASK_ID_MW_CODE_TAIL - TASK_ID_MW_CODE_BEGIN + 1);
			task_index += (task_indx - TASK_ID_DRV_CODE_BEGIN + 1);
		}
	}
	
	return task_index;
}


/*************************************************************************
 * FUNCTION:
 *  remap_module_id
 *
 * DESCRIPTION:
 *  adjust index for save RAM, should call this function when refer mod_task_g[module_id]
 *
 * PARAMETERS:
 *   module_type
 
 * RETURNS
 *   moduleid: the order in mod_task_g[]
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
kal_uint32 remap_module_id(kal_uint32 module_id)
{
	/* should  rewrite this function once task id is rearranged */

	kal_uint32 moduleid = 0;

#if defined(__PCORE__)

	do{

		if(module_id <= MOD_ID_SRV_CODE_BEGIN)
		{
			break;
		}
		else if(module_id < MODULE_TAG_SRV_TAIL)
		{
			moduleid = (module_id - MOD_ID_SRV_CODE_BEGIN);
		}
		else if(module_id <= MOD_MODEM_DUMMY_BEGIN)
		{
			break;
		}
		else if(module_id < MODULE_TAG_MODEM_DUMMY_TAIL)
		{
			moduleid = MODULE_TAG_SRV_TAIL - MOD_ID_SRV_CODE_BEGIN;
			moduleid += (module_id - MOD_MODEM_DUMMY_BEGIN + 1);
		}
		else if(module_id <= MOD_MODEM_4G_DUMMY_BEGIN)
		{
			break;
		}
		else if(module_id < MODULE_TAG_MODEM_4G_DUMMY_TAIL)
		{
			moduleid = MODULE_TAG_SRV_TAIL - MOD_ID_SRV_CODE_BEGIN;
			moduleid += (MODULE_TAG_MODEM_DUMMY_TAIL - MOD_MODEM_DUMMY_BEGIN + 1);
			moduleid += (module_id - MOD_MODEM_4G_DUMMY_BEGIN + 1);
		}
		else if(module_id <= MOD_MW_DUMMY_BEGIN)
		{
			break;
		}
		else if(module_id < MODULE_TAG_MW_DUMMY_TAIL)
		{
			moduleid = MODULE_TAG_SRV_TAIL - MOD_ID_SRV_CODE_BEGIN;
			moduleid += (MODULE_TAG_MODEM_DUMMY_TAIL - MOD_MODEM_DUMMY_BEGIN + 1);
			moduleid += (MODULE_TAG_MODEM_4G_DUMMY_TAIL - MOD_MODEM_4G_DUMMY_BEGIN + 1);
			moduleid += (module_id - MOD_MW_DUMMY_BEGIN + 1);
		}
		else if(module_id <= MOD_DRV_DUMMY_BEGIN)
		{
			break;
		}
		else if(module_id < MODULE_TAG_DRV_DUMMY_TAIL)
		{
			moduleid = MODULE_TAG_SRV_TAIL - MOD_ID_SRV_CODE_BEGIN;
			moduleid += (MODULE_TAG_MODEM_DUMMY_TAIL - MOD_MODEM_DUMMY_BEGIN + 1);
			moduleid += (MODULE_TAG_MODEM_4G_DUMMY_TAIL - MOD_MODEM_4G_DUMMY_BEGIN + 1);
			moduleid += (MODULE_TAG_MW_DUMMY_TAIL - MOD_MW_DUMMY_BEGIN + 1);
			moduleid += (module_id - MOD_DRV_DUMMY_BEGIN + 1);
		}
	}while(0);
	

#else

    do{

		if(module_id <= MOD_ID_CO_PROCESSOR_SRV_CODE_BEGIN)
		{
			break;
		}
		else if(module_id < MODULE_TAG_CO_PROCESSOR_SRV_TAIL)
		{
			moduleid = (module_id - MOD_ID_CO_PROCESSOR_SRV_CODE_BEGIN);
		}
		else if(module_id <= MOD_CO_PROCESSOR_MODEM_DUMMY_BEGIN)
		{
			break;
		}
		else if(module_id < MODULE_TAG_CO_PROCESSOR_MODEM_DUMMY_TAIL)
		{
			moduleid = MODULE_TAG_CO_PROCESSOR_SRV_TAIL - MOD_ID_CO_PROCESSOR_SRV_CODE_BEGIN;
			moduleid += (module_id - MOD_CO_PROCESSOR_MODEM_DUMMY_BEGIN + 1);
		}
		else if(module_id <= MOD_CO_PROCESSOR_MODEM_4G_DUMMY_BEGIN)
		{
			break;
		}
		else if(module_id < MODULE_TAG_CO_PROCESSOR_MODEM_4G_DUMMY_TAIL)
		{
			moduleid = MODULE_TAG_CO_PROCESSOR_SRV_TAIL - MOD_ID_CO_PROCESSOR_SRV_CODE_BEGIN;
			moduleid += (MODULE_TAG_CO_PROCESSOR_MODEM_DUMMY_TAIL - MOD_CO_PROCESSOR_MODEM_DUMMY_BEGIN + 1);
			moduleid += (module_id - MOD_CO_PROCESSOR_MODEM_4G_DUMMY_BEGIN + 1);
		}
		else if(module_id <= MOD_CO_PROCESSOR_MW_DUMMY_BEGIN)
		{
			break;
		}
		else if(module_id < MODULE_TAG_CO_PROCESSOR_MW_DUMMY_TAIL)
		{
			moduleid = MODULE_TAG_CO_PROCESSOR_SRV_TAIL - MOD_ID_CO_PROCESSOR_SRV_CODE_BEGIN;
			moduleid += (MODULE_TAG_CO_PROCESSOR_MODEM_DUMMY_TAIL - MOD_CO_PROCESSOR_MODEM_DUMMY_BEGIN + 1);
			moduleid += (MODULE_TAG_CO_PROCESSOR_MODEM_4G_DUMMY_TAIL - MOD_CO_PROCESSOR_MODEM_4G_DUMMY_BEGIN + 1);
			moduleid += (module_id - MOD_CO_PROCESSOR_MW_DUMMY_BEGIN + 1);
		}
		else if(module_id <= MOD_CO_PROCESSOR_DRV_DUMMY_BEGIN)
		{
			break;
		}
		else if(module_id < MODULE_TAG_CO_PROCESSOR_DRV_DUMMY_TAIL)
		{
			moduleid = MODULE_TAG_CO_PROCESSOR_SRV_TAIL - MOD_ID_CO_PROCESSOR_SRV_CODE_BEGIN;
			moduleid += (MODULE_TAG_CO_PROCESSOR_MODEM_DUMMY_TAIL - MOD_CO_PROCESSOR_MODEM_DUMMY_BEGIN + 1);
			moduleid += (MODULE_TAG_CO_PROCESSOR_MODEM_4G_DUMMY_TAIL - MOD_CO_PROCESSOR_MODEM_4G_DUMMY_BEGIN + 1);
			moduleid += (MODULE_TAG_CO_PROCESSOR_MW_DUMMY_TAIL - MOD_CO_PROCESSOR_MW_DUMMY_BEGIN + 1);
			moduleid += (module_id - MOD_CO_PROCESSOR_DRV_DUMMY_BEGIN + 1);
		}
	}while(0);

#endif

	if(moduleid > LAST_MOD_ID)
	    moduleid = 0;
	
	return moduleid;
}

/*************************************************************************
 * FUNCTION:
 *  remap_module_id_from_global_to_local
 *
 * DESCRIPTION:
 *  remap global module id to local module id, 
 *  should call this function when msg send to local module
 *
 * PARAMETERS:
 *   module_type: global module id
 *
 * RETURNS
 *   local module id if success, otherwise return 0.
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
kal_status remap_module_id_from_global_to_local(module_type global_module, module_type * dest_mod)
{
	int k;

	if(global_module >= MOD_ID_GLOBAL_TAIL)
		return KAL_INVALID_ID;
	
	for(k=1; k<(sizeof(module_remap_array)/sizeof(module_remap_struct)); k++)
	{
		if(module_remap_array[k].global_module == global_module)
		{
			//return module_remap_array[k].local_module;
			* dest_mod = (kal_uint16)module_remap_array[k].local_module;
			return KAL_SUCCESS;
		}
	}
	
	return KAL_ERROR;
}

/*************************************************************************
 * FUNCTION:
 *  remap_module_id_from_local_to_global
 *
 * DESCRIPTION:
 *  remap local module id to global module id, 
 *  should call this function to remap source module before sending to cross MD
 *
 * PARAMETERS:
 *   module_type: local module id
 *
 * RETURNS
 *   global module id if success, otherwise return 0.
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
kal_status remap_module_id_from_local_to_global(kal_uint32 local_module, module_type * dest_mod)
{
	int k;
	
	if(local_module <= MOD_ID_GLOBAL_TAIL)	
		return KAL_INVALID_ID; 
	
	for(k=1; k<(sizeof(module_remap_array)/sizeof(module_remap_struct)); k++)
	{
		if(module_remap_array[k].local_module == local_module)
		{
			*dest_mod = module_remap_array[k].global_module;
			return KAL_SUCCESS;
		}
	}
	return KAL_ERROR;
}

/*************************************************************************
 * FUNCTION:
 *  kal_get_task_index_by_mod_task_g
 *
 * DESCRIPTION:
 *   will get  taskindexfrom mod_task_g as mod_task_g is privated
 *
 * PARAMETERS:
 *   module_type: module Id
      beNeedRemap:  need remap if the module id is from module Id defined; 
                              don't remap if loop all module id one by one;      
 * RETURNS
 *   task indx in task_info_g[]
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
kal_uint32 kal_get_task_index_From_mod_task_g(module_type module_id, kal_bool beNeedRemap)
{
	kal_uint32 moduleid = module_id;
	/* should  rewrite this function once task/module id is rearranged */
	if( KAL_TRUE == beNeedRemap )
	{
		moduleid = remap_module_id(module_id);
	}
	return mod_task_g[moduleid];
}

#ifdef __KAL_CROSS_CORE_SUPPORT__

kal_bool kal_is_mod_id_on_current_core(module_type module_id)
{
#ifdef DEBUG_KAL
    if( MOD_ID_SRV_CODE_BEGIN > module_id || MOD_ID_END < module_id )
    {
        kal_fatal_error_handler(KAL_ERROR_MODULE_ID_OUT_OF_RANGE, (kal_uint32)module_id);
        return KAL_FALSE;  // fix build warning
    }
    else
#endif        
    {
        return kal_inline_is_mod_id_on_current_core(module_id);
    }
}
#endif

/*************************************************************************
 * FUNCTION:
 *  kal_query_module_core
 *
 * DESCRIPTION:
 *   will get the core location of a module
 *
 * PARAMETERS:
 *   module_type: module Id
 *
 * RETURNS
 *   kal_module_core: MD1 module, MD2 module, MD3 module, pcore module, 
 *                    l1core module, module not in defined range
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
kal_module_core kal_query_module_core(module_type module_id)
{
    kal_module_core module_core_return = MODULE_OUT_OF_RANGE;
    do{
        if( module_id <= MOD_ID_GLOBAL_NIL_CHECK_TAIL){
            break;
        }
        else if( module_id <= MOD_ID_GLOBAL_MD1_BEGIN){
            break;
        }
        else if( module_id < MODULE_TAG_MOD_ID_GLOBAL_MD1_TAIL){
            module_core_return = MD1_MODULE;
        }
        else if( module_id <= MOD_ID_GLOBAL_MD2_BEGIN){
            break;
        }
        else if( module_id < MODULE_TAG_MOD_ID_GLOBAL_MD2_TAIL){
            module_core_return = MD2_MODULE;
        }
        else if( module_id <= MOD_ID_GLOBAL_MD3_BEGIN){
            break;
        }
        else if( module_id < MODULE_TAG_MOD_ID_GLOBAL_MD3_TAIL){
            module_core_return = MD3_MODULE;
        }
        if(module_id <= MOD_ID_SRV_CODE_BEGIN)
        {
            break;
        }
        else if(module_id < MODULE_TAG_SRV_TAIL)
        {
            module_core_return = PCORE_MODULE;
        }
        else if(module_id <= MOD_MODEM_DUMMY_BEGIN)
        {
            break;
        }
        else if(module_id < MODULE_TAG_MODEM_DUMMY_TAIL)
        {
            module_core_return = PCORE_MODULE;
        }
        else if(module_id <= MOD_MODEM_4G_DUMMY_BEGIN)
        {
            break;
        }
        else if(module_id < MODULE_TAG_MODEM_4G_DUMMY_TAIL)
        {
            module_core_return = PCORE_MODULE;
        }
        else if(module_id <= MOD_MW_DUMMY_BEGIN)
        {
            break;
        }
        else if(module_id < MODULE_TAG_MW_DUMMY_TAIL)
        {
            module_core_return = PCORE_MODULE;
        }
        else if(module_id <= MOD_DRV_DUMMY_BEGIN)
        {
            break;
        }
        else if(module_id < MODULE_TAG_DRV_DUMMY_TAIL)
        {
            module_core_return = PCORE_MODULE;
        }
        else if(module_id <= MOD_ID_HISR_CODE_BEGIN)
        {
            break;
        }
        else if(module_id < MOD_ID_HISR_CODE_TAIL)
        {
            module_core_return = PCORE_MODULE;
        }
        else if(module_id <= MOD_ID_CO_PROCESSOR_SRV_CODE_BEGIN)
        {
            break;
        }
        else if(module_id < MODULE_TAG_CO_PROCESSOR_SRV_TAIL)
        {
            module_core_return = L1CORE_MODULE;
        }
        else if(module_id <= MOD_CO_PROCESSOR_MODEM_DUMMY_BEGIN)
        {
            break;
        }
        else if(module_id < MODULE_TAG_CO_PROCESSOR_MODEM_DUMMY_TAIL)
        {
            module_core_return = L1CORE_MODULE;
        }
        else if(module_id <= MOD_CO_PROCESSOR_MODEM_4G_DUMMY_BEGIN)
        {
            break;
        }
        else if(module_id < MODULE_TAG_CO_PROCESSOR_MODEM_4G_DUMMY_TAIL)
        {
            module_core_return = L1CORE_MODULE;
        }
        else if(module_id <= MOD_CO_PROCESSOR_MW_DUMMY_BEGIN)
        {
            break;
        }
        else if(module_id < MODULE_TAG_CO_PROCESSOR_MW_DUMMY_TAIL)
        {
            module_core_return = L1CORE_MODULE;
        }
        else if(module_id <= MOD_CO_PROCESSOR_DRV_DUMMY_BEGIN)
        {
            break;
        }
        else if(module_id < MODULE_TAG_CO_PROCESSOR_DRV_DUMMY_TAIL)
        {
            module_core_return = L1CORE_MODULE;
        }
        else if(module_id <= MOD_ID_CO_PROCESSOR_HISR_CODE_BEGIN)
        {
            break;
        }
        else if(module_id < MOD_ID_CO_PROCESSOR_HISR_CODE_TAIL)
        {
            module_core_return = L1CORE_MODULE;
        }
    } while(0);
    return module_core_return;
}

static void set_task_active_module_id(kal_uint32 module_id_start, kal_uint32 module_id_end)
{
    kal_uint32 task_indx, module_id;

    for(module_id = module_id_start+1; module_id < module_id_end; module_id++)
    {
        task_indx = mod_task_g[remap_module_id(module_id)];
        if(INDX_NIL == task_indx)
        {
            continue;
        }
        stack_set_active_module_id(remap_task_index(task_indx), module_id);
    }
}


/*************************************************************************
* FUNCTION
*  stack_init_comp_info
*
* DESCRIPTION
*   This function configures the information related with
*   inidividual tasks in an array.
*   The configuration is based on following:
*    1. The task configuration information passed.
*    2. compile time flags.
*
*   The configiration information for tasks not present are set
*   to default values.
*
*
* PARAMETERS
*  Input only: TAsk configuration information.
*
* RETURNS
*  KAL_TRUE on success, else KAL_FALSE.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
stack_init_comp_info(void)
{
   kal_uint32 task_indx, module_id;
   kal_uint8 boot_flag;

   kal_bool result = KAL_TRUE;
   comptask_handler_struct *comp_handler = NULL;
   /*fix compile warning*/
#ifdef SPLIT_SYS
   kal_uint8 mask_offset;
   kal_uint8 mask_pos;
   kal_uint32 i;
#endif /* SPLIT_SYS */
   
   KALTotalTasks = RPS_TOTAL_STACK_TASKS;
   KALTotalModules = RPS_TOTAL_STACK_MODULES;
   
   task_info_g = (task_info_struct *)kal_sys_mem_alloc(sizeof(task_info_struct) * KALTotalTasks);
   EXT_ASSERT(task_info_g != NULL, 0, 0, 0);
   if(NULL == task_info_g)
   {
      return KAL_FALSE;
   }
   
   /* Initialize global task info structure array */

   for (task_indx = 0; task_indx < KALTotalTasks; task_indx++)
   {

      task_info_g[ task_indx ].task_name_ptr   =  RPS_NO_TASK_NAME;
      task_info_g[ task_indx ].task_qname_ptr  =  RPS_QNAME_NIL;
      task_info_g[ task_indx ].task_priority   = RPS_TASK_PRIORITY_NIL;
      task_info_g[ task_indx ].task_stack_size = RPS_STACK_SIZE_NIL;
      task_info_g[ task_indx ].task_id         = KAL_NILTASK_ID;
      task_info_g[ task_indx ].task_ext_qid    = KAL_NILQ_ID;
      task_info_g[ task_indx ].task_int_qid_ptr= NULL;
      task_info_g[ task_indx ].task_entry_func = NULL;
      task_info_g[ task_indx ].task_init_func  = NULL;
      task_info_g[ task_indx ].task_ext_qsize  = RPS_QSIZE_NIL;
   }

   /* assume that the normal mode is the default setting */

#ifdef SPLIT_SYS
   /* Transfer tst routing table module id to task id */
   for (i=MOD_NIL+1; i<LAST_MOD_ID; i++)
   {
      mask_offset = i / 8;
      mask_pos = i % 8;

      if (tst_routing_table[mask_offset] & (0x1 << mask_pos)) {
         /* On MNT PC side */
         mask_offset = mod_task_g[i] / 32;
         mask_pos = mod_task_g[i] % 32;

         utonmnt_task_mask_g[mask_offset] |= (0x1 << mask_pos);
      } else {
         /* On Target side */
         mask_offset = mod_task_g[i] / 32;
         mask_pos = mod_task_g[i] % 32;

         utontarget_task_mask_g[mask_offset] |= (0x1 << mask_pos);
      }
   }

   /* Both MNT, Target side need TST/TST Reader Tasks */
   i = INDX_TST;
   mask_offset = mod_task_g[i] / 32;
   mask_pos = mod_task_g[i] % 32;
   utonmnt_task_mask_g[mask_offset] &= ~(0x1 << mask_pos);
   utontarget_task_mask_g[mask_offset] &= ~(0x1 << mask_pos);

   i = INDX_TST_READER;
   mask_offset = mod_task_g[i] / 32;
   mask_pos = mod_task_g[i] % 32;
   utonmnt_task_mask_g[mask_offset] &= ~(0x1 << mask_pos);
   utontarget_task_mask_g[mask_offset] &= ~(0x1 << mask_pos);

#ifdef __MTK_TARGET__
   redirect_task_mask_g = (kal_uint32*)&utonmnt_task_mask_g;
#else
   redirect_task_mask_g = (kal_uint32*)&utontarget_task_mask_g;
#endif /* __MTK_TARGET__ */

#endif /* SPLIT_SYS */

   /* Initialize global task info structure array according to component info */
   for (task_indx = 0; task_indx < KALTotalTasks; task_indx++)
   {
	   task_info_g[ task_indx ].task_name_ptr   = sys_comp_config_tbl[task_indx].comp_name_ptr;
	   task_info_g[ task_indx ].task_qname_ptr  = sys_comp_config_tbl[task_indx].comp_qname_ptr;
	   task_info_g[ task_indx ].task_priority   = sys_comp_config_tbl[task_indx].comp_priority;
	   task_info_g[ task_indx ].task_stack_size = sys_comp_config_tbl[task_indx].comp_stack_size;
#ifdef __SYS_INTERN_RAM__
	   task_info_g[ task_indx ].task_internal_ram_stack = sys_comp_config_tbl[task_indx].comp_internal_ram_stack;
#endif /* __SYS_INTERN_RAM__ */

       task_info_g[ task_indx].task_ext_qsize = sys_comp_config_tbl[task_indx].comp_ext_qsize;

	   task_info_g[ task_indx ].task_int_qsize = sys_comp_config_tbl[task_indx].comp_int_qsize;

       /*Check whether the task should be created or mis-configured*/
	   if ((sys_comp_config_tbl[task_indx].comp_create_func == (kal_create_func_ptr)TASK_NO_CREATE_PATTERN ) 
#ifdef SPLIT_SYS
			   || (*(redirect_task_mask_g + (task_indx >> 5)) & (0x1 << (task_indx & 31)))
#endif /* SPLIT_SYS */
	      )
	   {
		   continue; 
	   }
	   else if((sys_comp_config_tbl[task_indx].comp_create_func == (kal_create_func_ptr)KAL_FALSE) ||
	       (sys_comp_config_tbl[task_indx].comp_create_func == (kal_create_func_ptr)KAL_TRUE))
	   {
	       /*
	       This is task mis-configured case. This occurs code like 
	       #ifdef xxx
	       task_create_function(yyy)
	       #endif
	       missing the null_task_create_entry as the else branch.
         
	       The assumption is that task_stack_internalRAM(KAL_FALSE or KAL_TRUE)
	       following task create function
	       */
		   kal_RecordSSTOwner(sys_comp_config_tbl[task_indx].comp_name_ptr); 
		   kal_fatal_error_handler(KAL_ERROR_KALINIT_INIT_FAILED, task_indx);
	   }
	   else if( (sys_comp_config_tbl[task_indx].comp_create_func(&comp_handler) != KAL_TRUE) ||
	       (NULL == comp_handler) )
	   {
		   continue;
	   }

#if defined(__ESL_COSIM_LTE__)
           M_HSL_PRINTF("    task[%02d] = %10.*s, priority = 0x%04x_%04x\n",
                        task_indx,
                        10,
                        task_info_g[task_indx].task_name_ptr,
                        (task_info_g[task_indx].task_priority>>16) & 0xFFFF,
                        (task_info_g[task_indx].task_priority) & 0xFFFF);
#endif /* __ESL_COSIM_LTE__ */


	   /* component task entry function */
	   /*Null task_entry_func indicates the task will not create*/
	   task_info_g[ task_indx ].task_entry_func =
		   comp_handler->comp_entry_func;

	   /* component task initialization handler */
	   task_info_g[ task_indx ].task_init_func =
		   comp_handler->comp_init_func;

	   /* component task reset handler */
	   task_info_g[ task_indx ].task_reset_func =
		   comp_handler->comp_reset_func;
	   
	   comp_handler = NULL;

#ifdef __MULTI_BOOT__
	   if (INT_BootMode() == MTK_FACTORY_MODE)
	   {
		      boot_flag = sys_comp_config_tbl[task_indx].comp_boot_mode & FACTORY_M;
		      if(0 == boot_flag)
		      {
			      task_info_g[ task_indx ].task_entry_func = NULL;
			      for(module_id = 0; module_id < KALTotalModules; module_id++)
			      {
			      	kal_uint32 taskindx = kal_get_task_index_From_mod_task_g(module_id, KAL_FALSE);
				    if(task_indx == remap_task_index(taskindx))
				    {
					    mod_task_g[module_id] = INDX_NIL;
				    }
			      }
		      }
	   }
	  else 
#endif /* __MULTI_BOOT__ */
	   {
		   boot_flag = sys_comp_config_tbl[task_indx].comp_boot_mode & NORMAL_M;
		   if(boot_flag == 0)
		   {
			   task_info_g[ task_indx ].task_entry_func = NULL;
			   for(module_id = 0; module_id < KALTotalModules; module_id++)
			   {
				   kal_uint32 taskindx = kal_get_task_index_From_mod_task_g(module_id, KAL_FALSE);
				   if(task_indx == remap_task_index(taskindx))
				   {
					   mod_task_g[module_id] = INDX_NIL;
				   }
			   }
		   }
	   }
	   /* mask_offset = task_indx / 32; fix compile warning*/
	   /* mask_pos = task_indx % 32; fix compile warning*/
   }

   
#if defined(__PCORE__)
    set_task_active_module_id(MOD_DUMMY_NIL,                        MODULE_TAG_SRV_TAIL);
    set_task_active_module_id(MOD_MODEM_DUMMY_BEGIN,                MODULE_TAG_MODEM_DUMMY_TAIL);
    set_task_active_module_id(MOD_MODEM_4G_DUMMY_BEGIN,             MODULE_TAG_MODEM_4G_DUMMY_TAIL);
    set_task_active_module_id(MOD_MW_DUMMY_BEGIN,                   MODULE_TAG_MW_DUMMY_TAIL);
    set_task_active_module_id(MOD_DRV_DUMMY_BEGIN,                  MODULE_TAG_DRV_DUMMY_TAIL);
#else /* L1 CORE */
    set_task_active_module_id(MOD_CO_PROCESSOR_DUMMY_NIL,           MODULE_TAG_CO_PROCESSOR_SRV_TAIL);
    set_task_active_module_id(MOD_CO_PROCESSOR_MODEM_DUMMY_BEGIN,   MODULE_TAG_CO_PROCESSOR_MODEM_DUMMY_TAIL);
    set_task_active_module_id(MOD_CO_PROCESSOR_MODEM_4G_DUMMY_BEGIN,MODULE_TAG_CO_PROCESSOR_MODEM_4G_DUMMY_TAIL);
    set_task_active_module_id(MOD_CO_PROCESSOR_MW_DUMMY_BEGIN,      MODULE_TAG_CO_PROCESSOR_MW_DUMMY_TAIL);
    set_task_active_module_id(MOD_CO_PROCESSOR_DRV_DUMMY_BEGIN,     MODULE_TAG_CO_PROCESSOR_DRV_DUMMY_TAIL);
#endif
	  
   result = stack_init_module_info();

#if defined(__MTK_TARGET__) && !defined(__PCORE_ONLY__) && !defined(__L1CORE_ONLY__)
   //This section prepare owner dispath information in exception flow
#if defined(__PCORE__)
   SHARED_VAR(PCore_mod_task_g) = mod_task_g;
   SHARED_VAR(PCore_task_info_g) = task_info_g;
#elif defined(__L1CORE__)
   SHARED_VAR(L1Core_mod_task_g) = mod_task_g;
   SHARED_VAR(L1Core_task_info_g) = task_info_g;
#endif
   cp15_data_memory_barrier();
   clean_and_invalidate_dcache(CPU_CACHE_LINE_ALIGN_ADDR((kal_int32)mod_task_g), CPU_CACHE_LINE_ALIGN_LEN((kal_int32)mod_task_g, sizeof(kal_uint32) * KALTotalModules));
   clean_and_invalidate_dcache(CPU_CACHE_LINE_ALIGN_ADDR((kal_int32)task_info_g), CPU_CACHE_LINE_ALIGN_LEN((kal_int32)task_info_g, sizeof(task_info_struct) * KALTotalTasks));
#endif

   return result;
}

/*************************************************************************
* FUNCTION
*  stack_init_module_info
*
* DESCRIPTION
*  The function implements component task's modules information including
*  initialization, configuration, reset, termination handler.
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE on success, else KAL_FALSE.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
stack_init_module_info( void )
{
   /* According to feature customization,
      remap mod_task_g to overwrite internal configuration */
   remap_mod_task_g();

   return KAL_TRUE;
}

/*******************************************************************************
 * FUNCTION
 *  kal_get_task_total_number
 * DESCRIPTION
 *  query total task index number.
 * PARAMETERS
 *  NA.
 * RETURNS
 *  Return total task index number. 
 * GLOBALS AFFECTED
 *
 ******************************************************************************/
kal_uint32 kal_get_task_total_number(void)
{
	return KALTotalTasks;
}

/*******************************************************************************
 * FUNCTION
 *  kal_get_send_msg_module_id_total_number
 * DESCRIPTION
 *  query total module id number that can send message.
 * PARAMETERS
 *  NA.
 * RETURNS
 *  Return total module id number that can send message.
 * GLOBALS AFFECTED
 *
 ******************************************************************************/
kal_uint32 kal_get_send_msg_module_id_total_number(void)
{
    return (kal_uint32)RPS_TOTAL_STACK_MODULES;
}

#if defined(__MTK_TARGET__) && defined(__KAL_STACK_SHARING__)

kal_bool kal_is_task_stack_nonshareable(kal_uint32 task_index)
{
	kal_uint8 i=0;
	kal_bool ret_val = KAL_FALSE;
	for(i=0;i< sizeof(Non_sharing_tasks_array_g)/sizeof(kal_uint8);i++)
	{
		if(task_index == remap_task_index(Non_sharing_tasks_array_g[i]))
		{
			ret_val = KAL_TRUE;
			break;
		}
	}
	return ret_val;	
}

#endif
