/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*******************************************************************************
 * Filename:
 * -----------
 *   drv_mdap_interface.h
 *
 * Project:
 * -----------
 *   UMOLY
 *
 * Description:
 * ------------
 *   MD/AP interface driver related code
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 
#ifndef __DRV_MDAP_INTERFACE__
#define __DRV_MDAP_INTERFACE__

#include "kal_general_types.h"


#define MDAPI_BIT0    0x00000001
#define MDAPI_BIT1    0x00000002
#define MDAPI_BIT2    0x00000004
#define MDAPI_BIT3    0x00000008
#define MDAPI_BIT4    0x00000010
#define MDAPI_BIT5    0x00000020
#define MDAPI_BIT6    0x00000040
#define MDAPI_BIT7    0x00000080
#define MDAPI_BIT8    0x00000100
#define MDAPI_BIT9    0x00000200
#define MDAPI_BIT10   0x00000400
#define MDAPI_BIT11   0x00000800
#define MDAPI_BIT12   0x00001000
#define MDAPI_BIT13   0x00002000
#define MDAPI_BIT14   0x00004000
#define MDAPI_BIT15   0x00008000

#define AP2MD_BIT0    0
#define AP2MD_BIT1    1
#define AP2MD_BIT2    2
#define AP2MD_BIT3    3
#define AP2MD_BIT4    4
#define AP2MD_BIT5    5
#define AP2MD_BIT6    6
#define AP2MD_BIT7    7
#define AP2MD_BIT8    8
#define AP2MD_BIT9    9
#define AP2MD_BIT10   10
#define AP2MD_BIT11   11
#define AP2MD_BIT12   12
#define AP2MD_BIT13   13
#define AP2MD_BIT14   14
#define AP2MD_BIT15   15


#if defined(MT6797)	//from everest, SPM2MD has callback function user
typedef enum {
	//bit[15:0] => MD to SPM+CM4
	MD2AP_CAT6CA_DATAL 		= MDAPI_BIT0,
	MD2AP_CAT6NONCA_DATAL 	= MDAPI_BIT1,
	MD2AP_PAGING			= MDAPI_BIT2,
	MD2AP_POSITION			= MDAPI_BIT3,
	MD2AP_CELL_SEARCH 		= MDAPI_BIT4,
	MD2AP_CELL_MGT 			= MDAPI_BIT5,
	MD2AP_2G_TALKING		= MDAPI_BIT6,
	MD2AP_2G_DATAL			= MDAPI_BIT7,
	MD2AP_3G_TALKING		= MDAPI_BIT8,
	MD2AP_3G_DATAL 			= MDAPI_BIT9,

	MD2AP_AUDIO_FEATURE		= MDAPI_BIT14,
	MD2AP_END				= MDAPI_BIT15,
} MD2AP_SCENARIO;

typedef enum {
	//bit[7:0] => 8 interrpt to pscore
	//bit[15:8] => 1 interrput to l1core

	//bit[15:0] => SPM or CM4 to MD,
	//default [15][7] => CM4 to MD, [14:8][6:0] => SPM to MD
	AP2MD_PCORE_START				= AP2MD_BIT0,
	AP2MD_LIMIT_HARQON_PCORE 		= AP2MD_BIT0,
	AP2MD_LIMIT_HARQOFF_PCORE 		= AP2MD_BIT1,
	AP2MD_AUDIO_ACK_PCORE			= AP2MD_BIT4,
	AP2MD_AUDIO_NORMALFUN_PCORE		= AP2MD_BIT5,
	AP2MD_GEOFENCE_NORMALFUN_PCORE	= AP2MD_BIT7,
	AP2MD_PCORE_END					= AP2MD_BIT7,
	
	AP2MD_L1CORE_START				= AP2MD_BIT8,
	AP2MD_LIMIT_HARQON_L1CORE		= AP2MD_BIT8,
	AP2MD_LIMIT_HARQOFF_L1CORE		= AP2MD_BIT9,
	AP2MD_L1CORE_END				= AP2MD_BIT15,
} AP2MD_SCENARIO;

#elif defined(SHASTA)
typedef enum {
	//bit[15:0] => MD to SPM+CM4
	MD2AP_CAT6CA_DATAL 		= MDAPI_BIT0,
	MD2AP_CAT6NONCA_DATAL 	= MDAPI_BIT1,
	MD2AP_PAGING			= MDAPI_BIT2,
	MD2AP_POSITION			= MDAPI_BIT3,
	MD2AP_CELL_SEARCH 		= MDAPI_BIT4,
	MD2AP_CELL_MGT 			= MDAPI_BIT5,
	MD2AP_2G_TALKING		= MDAPI_BIT6,
	MD2AP_2G_DATAL			= MDAPI_BIT7,
	MD2AP_3G_TALKING		= MDAPI_BIT8,
	MD2AP_3G_DATAL 			= MDAPI_BIT9,

	MD2AP_DYNAMIC_SHAREMEM	= MDAPI_BIT13,
	MD2AP_AUDIO_FEATURE		= MDAPI_BIT14,
	MD2AP_VSRAM_LOWPOWER	= MDAPI_BIT15,	
	MD2AP_END				= MDAPI_BIT15,
} MD2AP_SCENARIO;

typedef enum {
	//bit[7:0] => 8 interrpt to pscore
	//bit[15:8] => 1 interrput to l1core

	//bit[15:0] => SPM or CM4 to MD,
	//default [15][7] => CM4 to MD, [14:8][6:0] => SPM to MD
	AP2MD_PCORE_START				= AP2MD_BIT0,
	AP2MD_LIMIT_HARQON_PCORE 		= AP2MD_BIT0,
	AP2MD_LIMIT_HARQOFF_PCORE 		= AP2MD_BIT1,
	AP2MD_DYNAMIC_SHAREMEM_PCORE	= AP2MD_BIT2,
	AP2MD_AUDIO_ACK_PCORE			= AP2MD_BIT4,
	AP2MD_AUDIO_NORMALFUN_PCORE		= AP2MD_BIT5,
	AP2MD_GEOFENCE_NORMALFUN_PCORE	= AP2MD_BIT7,
	AP2MD_PCORE_END					= AP2MD_BIT7,
	
	AP2MD_L1CORE_START				= AP2MD_BIT8,
	AP2MD_LIMIT_HARQON_L1CORE		= AP2MD_BIT8,
	AP2MD_LIMIT_HARQOFF_L1CORE		= AP2MD_BIT9,
	AP2MD_DYNAMIC_SHAREMEM_PCORE	= AP2MD_BIT10,
	AP2MD_L1CORE_END				= AP2MD_BIT15,

} AP2MD_SCENARIO;

#else //jade, including default

typedef enum {
	//bit[15:0] => MD to SPM+CM4
	MD2AP_CAT6CA_DATAL 		= MDAPI_BIT0,
	MD2AP_CAT6NONCA_DATAL 	= MDAPI_BIT1,
	MD2AP_PAGING			= MDAPI_BIT2,
	MD2AP_POSITION			= MDAPI_BIT3,
	MD2AP_CELL_SEARCH 		= MDAPI_BIT4,
	MD2AP_CELL_MGT 			= MDAPI_BIT5,
	MD2AP_2G_TALKING		= MDAPI_BIT6,
	MD2AP_2G_DATAL			= MDAPI_BIT7,
	MD2AP_3G_TALKING		= MDAPI_BIT8,
	MD2AP_3G_DATAL 			= MDAPI_BIT9,

	MD2AP_END				= MDAPI_BIT15,
} MD2AP_SCENARIO;

typedef enum {
	//bit[7:0] => 8 interrpt to pscore
	//bit[15:8] => 1 interrput to l1core

	//bit[15:0] => SPM or CM4 to MD,
	//default [15][7] => CM4 to MD, [14:8][6:0] => SPM to MD
	AP2MD_PCORE_START				= AP2MD_BIT0,
	AP2MD_LIMIT_HARQON_PCORE 		= AP2MD_BIT0,
	AP2MD_LIMIT_HARQOFF_PCORE 		= AP2MD_BIT1,
	AP2MD_PCORE_END					= AP2MD_BIT7,
	
	AP2MD_L1CORE_START				= AP2MD_BIT8,
	AP2MD_LIMIT_HARQON_L1CORE		= AP2MD_BIT8,
	AP2MD_LIMIT_HARQOFF_L1CORE		= AP2MD_BIT9,
	AP2MD_L1CORE_END				= AP2MD_BIT15,
} AP2MD_SCENARIO;

#endif


typedef void (*DRV_AP2MD_HISRCALLBACK)(kal_uint32 param);

kal_bool _Drv_MD2AP_SetScenario(MD2AP_SCENARIO value);
kal_bool _Drv_MD2AP_ClearScenario(MD2AP_SCENARIO value);

kal_bool _Drv_MDAPInterface_Dump(void);
kal_bool _Drv_MDAPInterface_Init(void);

kal_bool _Drv_MDAPInterface_RegisterCallback(AP2MD_SCENARIO funID, DRV_AP2MD_HISRCALLBACK funp);



#if !defined(__MTK_TARGET__)
#define Drv_MD2AP_SetScenario(value)
#define Drv_MD2AP_ClearScenario(value)
#define Drv_MDAPInterface_Init()
#define Drv_MDAPInterface_Dump()
#define Drv_MDAPInterface_RegisterCallback()

#else
#define Drv_MD2AP_SetScenario(value)					_Drv_MD2AP_SetScenario(value)
#define Drv_MD2AP_ClearScenario(value)					_Drv_MD2AP_ClearScenario(value)
#define Drv_MDAPInterface_Init()						_Drv_MDAPInterface_Init()
#define Drv_MDAPInterface_Dump()						_Drv_MDAPInterface_Dump()
#define Drv_MDAPInterface_RegisterCallback(id, funp)	_Drv_MDAPInterface_RegisterCallback(id, funp)

#endif



#endif  /* !__DRV_MDAP_INTERFACE__ */

