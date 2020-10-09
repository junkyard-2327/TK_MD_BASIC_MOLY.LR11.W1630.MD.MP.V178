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

/*******************************************************************************
 * Filename:
 * ---------
 *   el1_custom_nvram_editor.h
 *
 * Project:
 * --------
 *   MT6291
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#ifndef __EL1_CUSTOM_NVRAM_EDTIOR_H__
#define __EL1_CUSTOM_NVRAM_EDTIOR_H__

#ifndef NVRAM_NOT_PRESENT
/*****************************************************************************
* Include
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*
 *   Include Headers
 */
 
/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"

/*
 *   User Headers
 */
#include "el1_custom_nvram_def.h"


#ifdef GEN_FOR_PC
BEGIN_NVRAM_DATA 
 
 //bit level description
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_0THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_1STBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_2NDBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_3RDBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_4THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_5THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_6THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_7THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_8THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_9THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_10THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_11THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_12THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_13THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_14THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_15THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_16THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_17THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_18THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_19THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_EVENT_20THBAND_LID)
     nvram_el1_mipi_antrx_event_struct *NVRAM_EF_EL1_MIPI_ANTRX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_0THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_1STBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_2NDBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_3RDBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_4THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_5THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_6THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_7THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_8THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_9THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_10THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_11THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_12THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_13THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_14THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_15THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_16THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_17THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_18THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_19THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_EVENT_20THBAND_LID)
     nvram_el1_mipi_anttx_event_struct *NVRAM_EF_EL1_MIPI_ANTTX_EVENT_TOTAL
     {

     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_0THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_1STBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_2NDBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_3RDBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_4THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_5THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_6THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_7THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_8THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_9THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_10THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_11THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_12THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_13THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_14THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_15THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_16THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_17THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_18THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_19THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTRX_DATA_20THBAND_LID)
     nvram_el1_mipi_antrx_data_struct *NVRAM_EF_EL1_MIPI_ANTRX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_0THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_1STBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_2NDBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_3RDBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_4THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_5THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_6THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_7THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_8THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_9THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_10THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_11THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_12THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_13THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_14THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_15THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_16THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_17THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_18THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_19THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_EL1_MIPI_ANTTX_DATA_20THBAND_LID)
     nvram_el1_mipi_anttx_data_struct *NVRAM_EF_EL1_MIPI_ANTTX_DATA_TOTAL
     {

     };


END_NVRAM_DATA
#endif /* GEN_FOR_PC */
#endif /* NVRAM_NOT_PRESENT */
#endif /* NVRAM_EDTIOR_DATA_ITEM_SYSTEM_H */

