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

#ifndef MODULE_ID_RANGE_H
#define MODULE_ID_RANGE_H

#include "global_modid_range.h"

typedef enum {
    MOD_ID_SRV_CODE_BEGIN = MOD_ID_GLOBAL_END, MOD_ID_SRV_CODE_TAIL = MOD_ID_SRV_CODE_BEGIN + 55,
	
    MOD_ID_MODEM_2G3G_CODE_BEGIN, MOD_ID_MODEM_2G3G_CODE_TAIL = MOD_ID_MODEM_2G3G_CODE_BEGIN + 410,

    MOD_ID_MODEM_4G_CODE_BEGIN, MOD_ID_MODEM_4G_CODE_TAIL = MOD_ID_MODEM_4G_CODE_BEGIN + 110,	
	
    MOD_ID_MIDDLEWARE_CODE_BEGIN, MOD_ID_MIDDLEWARE_CODE_TAIL = MOD_ID_MIDDLEWARE_CODE_BEGIN + 90,
	
    MOD_ID_DRV_CODE_BEGIN, MOD_ID_DRV_CODE_TAIL = MOD_ID_DRV_CODE_BEGIN + 70,  //tmp for add null task & print 40 + 50 

    MOD_ID_HISR_CODE_BEGIN, 
#if defined(__UNIFIED_ISR_LEVEL__)
    MOD_ID_HISR_CODE_TAIL = MOD_ID_HISR_CODE_BEGIN + 168 +1,
#else
    MOD_ID_HISR_CODE_TAIL = MOD_ID_HISR_CODE_BEGIN + 70 +1,  //follow MOD_APP_BEGIN = (MOD_HISR_BEGIN + KAL_MAX_NUM_HISRS + 1)
#endif	
		

    /* use to identify the moduld is belong to master or coprocessor */	
    MOD_ID_CO_PROCESSOR_BASE = MOD_ID_HISR_CODE_TAIL+1,


    MOD_ID_CO_PROCESSOR_SRV_CODE_BEGIN = MOD_ID_CO_PROCESSOR_BASE,
    MOD_ID_CO_PROCESSOR_SRV_CODE_TAIL = MOD_ID_CO_PROCESSOR_SRV_CODE_BEGIN + 40,
    	
    MOD_ID_CO_PROCESSOR_MODEM_2G3G_CODE_BEGIN, 
    MOD_ID_CO_PROCESSOR_MODEM_2G3G_CODE_TAIL = MOD_ID_CO_PROCESSOR_MODEM_2G3G_CODE_BEGIN + 80,
       	
    MOD_ID_CO_PROCESSOR_MODEM_4G_CODE_BEGIN, 
    MOD_ID_CO_PROCESSOR_MODEM_4G_CODE_TAIL = MOD_ID_CO_PROCESSOR_MODEM_4G_CODE_BEGIN + 30,
 	
    MOD_ID_CO_PROCESSOR_MIDDLEWARE_CODE_BEGIN, 
    MOD_ID_CO_PROCESSOR_MIDDLEWARE_CODE_TAIL = MOD_ID_CO_PROCESSOR_MIDDLEWARE_CODE_BEGIN + 20,

    MOD_ID_CO_PROCESSOR_DRV_CODE_BEGIN, 
    MOD_ID_CO_PROCESSOR_DRV_CODE_TAIL = MOD_ID_CO_PROCESSOR_DRV_CODE_BEGIN + 30,

    MOD_ID_CO_PROCESSOR_HISR_CODE_BEGIN, 
#if defined(__UNIFIED_ISR_LEVEL__)
    MOD_ID_CO_PROCESSOR_HISR_CODE_TAIL = MOD_ID_CO_PROCESSOR_HISR_CODE_BEGIN + 168 +1,
#else
    MOD_ID_CO_PROCESSOR_HISR_CODE_TAIL = MOD_ID_CO_PROCESSOR_HISR_CODE_BEGIN + 70 +1,
#endif


    MOD_ID_CODE_END,  
    MOD_ID_END = MOD_ID_CODE_END,
    //To enlarge END_OF_MOD_ID_BEGIN, please discuss with DHL owner if there is enough space in NVRAM.
    END_OF_MOD_ID_BEGIN = 1500, END_OF_MOD_ID_TAIL,

	

  	
    MOD_ID_SRV_CODE_REMAP_BEGIN, MOD_ID_SRV_CODE_REMAP_TAIL,
    
    MOD_ID_MODEM_2G3G_CODE_REMAP_BEGIN, MOD_ID_MODEM_2G3G_CODE_REMAP_TAIL,
	
    MOD_ID_MODEM_4G_CODE_REMAP_BEGIN, MOD_ID_MODEM_4G_CODE_REMAP_TAIL,

    MOD_ID_MIDDLEWARE_CODE_REMAP_BEGIN, MOD_ID_MIDDLEWARE_CODE_REMAP_TAIL,
    
    MOD_ID_DRV_CODE_REMAP_BEGIN, MOD_ID_DRV_CODE_REMAP_TAIL,
	
    MOD_ID_HISR_CODE_REMAP_BEGIN, MOD_ID_HISR_CODE_REMAP_TAIL, 
	
}MODULE_ID_TYPE;

typedef unsigned int module_id_boundary_check1[END_OF_MOD_ID_BEGIN - MOD_ID_CODE_END];

MODULE_MOD_BEGIN(END_OF_MOD_ID_BEGIN)
	END_OF_MOD_ID,
MODULE_MOD_END(END_OF_MOD_ID_TAIL)


#endif /* MODULE_ID_RANGE_H */