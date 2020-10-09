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
 * 
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * 
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
 *
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __TD_NVRAM_DEF_H__
#define __TD_NVRAM_DEF_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "ps_public_enum.h"
#ifdef __AST_TL1_TDD__
#include "tl1cal_ast.h"
#include "tl1d_custom_drdi.h"
#include "tl1d_rf_cal_poc_data.h"
#endif



typedef enum
{
        NVRAM_EF_AST_TL1_START                = NVRAM_LID_GRP_TD(0),    
		NVRAM_EF_AST_TL1_TEMP_DAC_LID = NVRAM_EF_AST_TL1_START,
		NVRAM_EF_AST_TL1_AFC_DATA_LID,						   
		NVRAM_EF_AST_TL1_PATHLOSS_BAND33_35_37_39_LID,		   
		NVRAM_EF_AST_TL1_PATHLOSS_BAND34_LID,				   
		NVRAM_EF_AST_TL1_PATHLOSS_BAND36_LID,				   
		NVRAM_EF_AST_TL1_PATHLOSS_BAND38_LID,				   
		NVRAM_EF_AST_TL1_PATHLOSS_BAND40_LID,				   
		NVRAM_EF_AST_TL1_TXDAC_BAND33_35_37_39_LID, 		   
		NVRAM_EF_AST_TL1_TXDAC_BAND34_LID,					   
		NVRAM_EF_AST_TL1_TXDAC_BAND36_LID,					   
		NVRAM_EF_AST_TL1_TXDAC_BAND38_LID,					   
		NVRAM_EF_AST_TL1_TXDAC_BAND40_LID,					   
		NVRAM_EF_AST_TL1_ABB_CAL_LID,						   
		NVRAM_EF_AST_TL1_TXCLPC_BAND33_35_37_39_LID,		   
		NVRAM_EF_AST_TL1_TXCLPC_BAND34_LID, 				   
		NVRAM_EF_AST_TL1_TXCLPC_BAND36_LID, 				 
		NVRAM_EF_AST_TL1_TXCLPC_BAND38_LID, 				
		NVRAM_EF_AST_TL1_TXCLPC_BAND40_LID, 				   
		NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_LID,				
		NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_DEBUG_LID, 		 
		NVRAM_EF_AST_TL1_RF_PARAM_LID,						
		NVRAM_EF_AST_TL1_RFFE_PARAM_LID,					
		NVRAM_EF_AST_TL1_POC_PARAM_LID,
		NVRAM_EF_AST_TL1_RF_TIMESEQ_LID,  
		/* AST 3001 DCXO support */
		NVRAM_EF_AST_TL1_CAP_DATA_LID,
		NVRAM_EF_AST_TL1_DAT_PARAM_LID,
		NVRAM_EF_AST_TL1_END = NVRAM_EF_AST_TL1_DAT_PARAM_LID,

		
        /*Add LID must before NVRAM_EF_TD_LAST_LID*/
        NVRAM_EF_TD_LAST_LID                          = NVRAM_LID_GRP_TD(255)
}nvram_lid_td_enum;



#define NVRAM_EF_AST_TL1_TEMP_DAC_SIZE    sizeof(ast_tl1cal_tempdacData_T)
#define NVRAM_EF_AST_TL1_TEMP_DAC_TOTAL   1

#define NVRAM_EF_AST_TL1_AFC_DATA_SIZE    sizeof(ast_tl1cal_afcData_T)
#define NVRAM_EF_AST_TL1_AFC_DATA_TOTAL   1

#define NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE    sizeof(ast_tl1cal_pathlossData_T)
#define NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL   1

#define NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE    sizeof(ast_tl1cal_txdacData_T)
#define NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL   1

#define NVRAM_EF_AST_TL1_ABB_CAL_SIZE    sizeof(ast_tl1cal_abbData_T)
#define NVRAM_EF_AST_TL1_ABB_CAL_TOTAL   1

#define NVRAM_EF_AST_TL1_CAP_DATA_SIZE    sizeof(ast_tl1cal_capData_T)
#define NVRAM_EF_AST_TL1_CAP_DATA_TOTAL   1
#define NVRAM_EF_AST_TL1_TXCLPC_BAND_SIZE    sizeof(ast_tl1cal_txPdData_T)
#define NVRAM_EF_AST_TL1_TXCLPC_BAND_TOTAL   1
#define NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_SIZE    sizeof(kal_uint16)
#define NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_TOTAL    1
#define NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_DEBUG_SIZE    sizeof(Tl1CustomDynamicInitDebug)
#define NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_DEBUG_TOTAL    1
#define NVRAM_EF_AST_TL1_RF_TIMESEQ_SIZE    sizeof(T_RF_PROG_SEQ_STRUCT)
#define NVRAM_EF_AST_TL1_RF_TIMESEQ_TOTAL   1
#define NVRAM_EF_AST_TL1_RF_PARAM_SIZE    sizeof(T_TD_CUSTOMIZATION_STRUCT)
#define NVRAM_EF_AST_TL1_RF_PARAM_TOTAL   1
#define NVRAM_EF_AST_TL1_RFFE_PARAM_SIZE    sizeof(T_MIPI_CUSTOMIZATION_STRUCT)
#define NVRAM_EF_AST_TL1_RFFE_PARAM_TOTAL   1

#define NVRAM_EF_AST_TL1_POC_PARAM_SIZE    sizeof(TDS_RF_POC_COMP_T)
#define NVRAM_EF_AST_TL1_POC_PARAM_TOTAL   1

#if defined(__DYNAMIC_ANTENNA_TUNING__)
#define NVRAM_EF_AST_TL1_DAT_PARAM_SIZE    sizeof(T_TD_CUSTOMIZATION_DAT_STRUCT)
#define NVRAM_EF_AST_TL1_DAT_PARAM_TOTAL   1
#endif

#ifdef __cplusplus
}
#endif 

#endif
