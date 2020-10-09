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
 * ---------
 *   imc_upcm_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *   
 *
 * ==========================================================================
 * $Log$
 *
 * 09 28 2017 sean.jheng
 * [MOLY00280498] [UPCM] Increase enum range for ims_ebi_filter_type_enum
 * 	
 * 	.
 *
 * 09 20 2017 savvas.chou
 * [MOLY00278697] [MT6755][TMO-US][N0+MP5][2017Q3][Simulation][R&S][IMS][L_IMS_VOLTE_6814][ASSERT] file:pcore/modem/imc/sub_imc/imc_mngr/src/imc_mngr_msghdlr.c line:4339
 * add text type in ebi filter
 *
 * 09 20 2017 savvas.chou
 * [MOLY00278697] [MT6755][TMO-US][N0+MP5][2017Q3][Simulation][R&S][IMS][L_IMS_VOLTE_6814][ASSERT] file:pcore/modem/imc/sub_imc/imc_mngr/src/imc_mngr_msghdlr.c line:4339
 * add text type in ebi filter
 *
 * 04 08 2016 andrew.wu
 * [MOLY00173139] [K7][UPlus] Upload Data Throughput Test FAIL whole devices at LGU+ real networks
 * .
 *
 ****************************************************************************/
/*
 * =====================================================================================
 *
 *       Filename:  imc_upcm_struct.h
 *
 *    Description:  Shared structure between IMC and UPCM
 *
 *        Created:  2015/3/4 W15.10
 *        Author:  mtk04141 (ben)
 * =====================================================================================
 */

#ifndef  IMC_UPCM_STRUCT_INC
#define  IMC_UPCM_STRUCT_INC

#include "kal_public_api.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "ims_common_def.h"

typedef enum
{
    IMS_SIP_TYPE = 0,
    IMS_NON_SIP_TYPE,
    IMS_VOICE_TYPE,
    IMS_VIDEO_TYPE,
    IMS_TEXT_TYPE,
    IMS_FILTER_TYPE_NUM
} ims_ebi_filter_type_enum;

typedef enum
{
    IMS_EXT_TYPE_IMS = IMS_FILTER_TYPE_NUM+1
} ims_ebi_filter_ext_type_enum;

typedef struct 
{
    LOCAL_PARA_HDR
    ims_ebi_filter_type_enum    type;
    kal_uint8                   ebi;
} imc_upcm_start_ebi_filter_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    ims_ebi_filter_type_enum    type;
    kal_uint8                   ebi;
} imc_upcm_stop_ebi_filter_req_struct;

#endif   /* ----- #ifndef IMC_UPCM_STRUCT_INC  ----- */
