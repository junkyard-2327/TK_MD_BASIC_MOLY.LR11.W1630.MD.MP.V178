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
 * custom_nvram_extra.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is the implementation of the methods to manuplate the file object defined 
 *    in NVRAM data items.
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "custom_nvram_extra.h"
#include "custom_nvram_sec.h"
//#include "common_nvram_editor_data_item.h"
#include "kal_general_types.h"
//#include "kal_internal_api.h"
#include "kal_public_api.h"
//#include "nvram_editor_data_item.h"
#include "nvram_data_items.h"
#include "kal_trace.h"
#include "sim_public_enum.h"
#include "global_def.h"
#include "smu_trc.h"
#include "smu_def.h"
#include "ps_public_utility.h"
#include "gmss_public.h" //for gmss_is_tdscdma_mode_activated()
#include "sim_ps_struct.h"
#include "cust_chl_interface.h"
#include "nvram_interface.h"

#if defined(__SAT_ADDITIONAL_LOCK__) || defined(__CMCC_V4__) || defined(__YUENAN_V4__)
#include "che_api.h"
#include "sim_trc.h"
#endif

#if !defined(__MAUI_BASIC__)
#include "l4c_utility.h"

/*****************************************************************************
* Define of SMU
*****************************************************************************/
/* 
 *   BEGIN:PH add for smu_security_info_struct (NVRAM_EF_MS_SECURITY_LID)
 * typedef struct
 * {
 *     kal_uint8                reg_ps_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                security_indication;
 *     kal_uint8                auto_lock_item;
 *     kal_uint8                np_code[NVRAM_EDITOR_NUM_OF_BYTE_NP * NVRAM_EDITOR_NUM_NP];
 *     kal_uint8                np_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                nsp_code[NVRAM_EDITOR_NUM_OF_BYTE_NSP * NVRAM_EDITOR_NUM_NSP];
 *     kal_uint8                nsp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                np_of_sp[NVRAM_EDITOR_NUM_OF_BYTE_NP];
 *     kal_uint8                np_of_cp[NVRAM_EDITOR_NUM_OF_BYTE_NP];
 *     kal_uint8                gid1[NVRAM_EDITOR_NUM_GID];
 *     kal_uint8                gid2[NVRAM_EDITOR_NUM_GID];
 *     kal_uint8                sp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                cp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                imsi_code[NVRAM_EDITOR_NUM_OF_BYTE_IMSI];
 *     kal_uint8                imsi_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                phone_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                last_imsi[NVRAM_EDITOR_NUM_OF_BYTE_IMSI];
 *     kal_uint8                pin1[NVRAM_EDITOR_NUM_PIN1];
 *     kal_uint8                pin1_valid;
 *     kal_uint8                phone_lock_verified;
 *  }smu_security_info_struct;
 *
 */

/* Load a new data object */
static kal_bool smu_load(void *, kal_uint8);   /* pobjFromlid */
/* Update a the data object */
static kal_bool smu_update(void *, kal_uint8); /* pobjTolid */
/* Release the data object */
static kal_bool smu_destory(kal_uint8);
/* Query the value of the item in kal_uint8 */
static kal_uint8 smu_query_u8(smu_item_enum, kal_uint8);   /* eItem */
/* Query the value of the item in kal_uint8[] */
static void smu_query_a(
                /* eItem */ smu_item_enum,
                /* pstrTo */ kal_uint8 *,
                /* chlen */ kal_uint8, kal_uint8);
/* Assign the value of the item in kal_uint8 */
static void smu_assign_u8(
                /* eItem */ smu_item_enum,
                /* chValue */ kal_uint8, kal_uint8);
/* Assign the value of the item in string with length */
static void smu_assign_a(
                /* eItem */ smu_item_enum,
                /* pstrValue */ kal_uint8 *,
                /* chlen */ kal_uint8, kal_uint8);
/* Compare the string with the data item */
static kal_bool smu_match(
                    /* eItem */ smu_item_enum,
                    /* pstrValue */ kal_uint8 *,
                    /* chlen */ kal_uint8, kal_uint8);

extern kal_bool custom_smu_is_write_protect2(nvram_lid_enum file_idx);
extern void smu_nvram_write(nvram_lid_enum file_idx, kal_uint8 access_id, kal_bool is_write_protect2);

 /***************************************************************************** 
* Typedef of SMU
*****************************************************************************/

/***************************************************************************** 
* Local Variable of SMU
*****************************************************************************/
static nvram_ef_ms_security_struct nvram_ef_ms_security_obj_g[MAX_SIM_NUM];

/***************************************************************************** 
* Local Variable of SMU object
*****************************************************************************/
static smu_security_info_struct smu_security_info_obj[MAX_SIM_NUM];

/***************************************************************************** 
* Global Variable of SMU
*****************************************************************************/

nvram_ef_ms_security_struct *pSmuSecurityInfog = &nvram_ef_ms_security_obj_g[0];

/***************************************************************************** 
* Global Function of SMU
*****************************************************************************/
void smu_init_ms_security_obj(kal_uint8 source)
{
    nvram_ef_ms_security_struct ms_security_obj = {
        NULL,
        smu_load,
        smu_update,
        smu_destory,
        smu_query_u8,
        smu_query_a,
        smu_assign_u8,
        smu_assign_a,
        smu_match        
    };
    
    smu_destory(source);
    kal_mem_cpy(&nvram_ef_ms_security_obj_g[source], &ms_security_obj, sizeof(nvram_ef_ms_security_struct));
}

kal_uint8 sim_terminal_profile_length(void)
{
    return MAX_SIM_PROFILE_LEN;

    /* support old SIM card, please return this value. 
       NOTE: the value shall be less than MAX_SIM_PROFILE_LEN */
    // return 9;
}

/* Virtual SIM File content 
   meta data (32 bytes) = FCP data length(1 byte) + FCP data (31 bytes)
   FCP data is the response data of selecting this file. 
   Please refer to SIM spec , to check the format of response data of "SELECT" command */
#ifdef __VSIM__ 
/*35+256 = 291*/
kal_uint8 DF_GSM_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x16, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x20, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0a, 0x93, 0x00, 
0x1c, 0x04, 0x00, 0x83, 0x8a, 0x83, 0x8a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
/* File content data : end*/
};

kal_uint8 EF_ICCID_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x0A, 0x2F, 0xE2, 0x04, 0x00, 0x04, 0x00, 0x44, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x98, 0x88, 0x96, 0x07, 0x02, 0X05, 0x27, 0x01, 0x01, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

kal_uint8 EF_LP_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x04, 0x6F, 0x05, 0x04, 0x00, 0x01, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x11, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

kal_uint8 EF_SST_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x0A, 0x6F, 0x38, 0x04, 0x00, 0x15, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0xFF, 0x3F, 0xFF, 0xFF, 0x00, 0x00, 0xFC, 0x33, 0x00, 0x0C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

kal_uint8 EF_PHASE_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x01, 0x6F, 0xAE, 0x04, 0x00, 0x05, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

/*
* Note: IMSI will store in NVRAM, the NVRAM FILE SIZE is NVRAM_VSIM_EF_DEFUALT_SIZE (128bytes)
*/
kal_uint8 EF_IMSI_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x09, 0x6F, 0x07, 0x04, 0x00, 0x15, 0x00, 0x15, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x08, 0x09, 0x10, 0x10, 0x10, 0x32, 0x54, 0x06, 0x36, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

kal_uint8 EF_AD_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x03, 0x6F, 0xAD, 0x04, 0x00, 0x05, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

kal_uint8 EF_ACC_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x02, 0x6F, 0x78, 0x04, 0x00, 0x15, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x00, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

kal_uint8 EF_KC_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x09, 0x6F, 0x20, 0x04, 0x00, 0x11, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0xCD, 0xB4, 0x71, 0xF9, 0x09, 0x2F, 0x6C, 0x00, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

kal_uint8 EF_LOCI_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x0B, 0x6F, 0x7E, 0x04, 0x00, 0x11, 0x00, 0x15, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x5B, 0x22, 0x8E, 0x1B, 0x64, 0xF6, 0x79, 0x2C, 0x27, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

kal_uint8 EF_HPPLMN_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x01, 0x6F, 0x31, 0x04, 0x00, 0x15, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x05, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

/*MoDIS doesn't have this file!*/
kal_uint8 EF_BCCH_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x10, 0x6F, 0x74, 0x04, 0x00, 0x11, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

kal_uint8 EF_FPLMN_data[EF_META_SIZE+EF_DATA_SIZE] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x0C, 0x6F, 0x7B, 0x04, 0x00, 0x11, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x64, 0xF6, 0x10, 0x64, 0xF6, 0x29, 0x64, 0xF6, 0x88, 0x44, 0xF0, 0x01, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};
#ifndef __MDVSIM__
const kal_uint8 ADF_USIM_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data:start*/
0x3F, 0x62, 0x42, 0x82, 0x02, 0x78, 0x21, 0x84, 0x10, 0xA0, 0x00, 0x00, 0x00, 0x87, 0x10, 0x02,
0xFF, 0x33, 0xFF, 0xFF, 0x89, 0x01, 0x01, 0x01, 0x00, 0xA5, 0x11, 0x80, 0x01, 0x71, 0x81, 0x03,
0x01, 0x0A, 0x32, 0x82, 0x01, 0x0A, 0x83, 0x04, 0x00, 0x00, 0xF2, 0xD5, 0x8A, 0x01, 0x05, 0x8B, 
0x03, 0x2F, 0x06, 0x02, 0xC6, 0x09, 0x90, 0x01, 0x40, 0x83, 0x01, 0x01, 0x83, 0x01, 0x81, 0x00,

/* File content data: start */
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

const kal_uint8 EF_U_ELP_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 byes is meta data: start */
0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0x05, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x06, 0x81,
0x02, 0x00, 0x14, 0x88, 0x01, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data: start */
0x98, 0x88, 0x96, 0x07, 0x02, 0X05, 0x27, 0x01, 0x01, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data:end */
};

const kal_uint8 EF_U_ICCID_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data:start */
0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0xE2, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0A, 0x81,
0x02, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data:start */
0x98, 0x88, 0x96, 0x02, 0x55, 0X06, 0x00, 0x48, 0x53, 0x05, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data:end*/
};

const kal_uint8 EF_U_PSLOCI_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data:start */
0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x73, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0E, 0x81,
0x02, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data:start */
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF1, 0x10, 0xFF, 0xFE, 0xFF, 0x02, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data:end*/
};

const kal_uint8 EF_U_ACC_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data:start */
0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0x78, 0xA5, 0x03, 0x80, 0x01, 0x71,
0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x07, 0x80, 0x02, 0x00, 0x02, 0x88, 0x01, 0x30, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data: start */
0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data: end*/
};

const kal_uint8 EF_U_LOCI_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data: start */
0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x7E, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0B, 0x81,
0x02, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data: start */
0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF1, 0x10, 0xFF, 0xFE, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data: end */
};

const kal_uint8 EF_U_AD_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data:start */
0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0xAD, 0xA5, 0x03, 0x80, 0x01, 0x71,
0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x0A, 0x80, 0x02, 0x00, 0x04, 0x88, 0x01, 0x18, 0x00,
0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data : start*/
0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/     
};

const kal_uint8 EF_U_IMSI_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data:start */
0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x07, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x09, 0x81,
0x02, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data: start */
0x08, 0x09, 0x10, 0x10, 0x32, 0x54, 0x76, 0x98, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data: end*/
};

const kal_uint8 EF_U_HPPLMN_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data:start */
0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x31, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x01, 0x81,
0x02, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/*File content data:start */
0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_U_UST_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data:start */
0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x38, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0B, 0x81,
0x02, 0x00, 0x15, 0x88, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data : start*/
0x2E, 0xFA, 0x9B, 0x9D, 0x67, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/ 
};

const kal_uint8 EF_U_EST_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/*the first 64 bytes is meta data:start */
0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x56, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x02, 0x81,
0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data : start*/
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/    
};

const kal_uint8 EF_U_PLMNWACT_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data:start */
0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x60, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x05, 0x80, 0x02, 0x00, 0x0F, 0x81,
0x02, 0x00, 0x1D, 0x88, 0x01, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data : start*/
0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/    
};

const kal_uint8 EF_U_OPLMNWACT_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data:start */
0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x61, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0F, 0x81,
0x02, 0x00, 0x1D, 0x88, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data : start*/
0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/  
};

const kal_uint8 EF_U_HPLMNWACT_data[EF_U_META_SIZE + EF_U_DATA_SIZE] =
{
/* the first 64 bytes is meta data: start */
0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x62, 0xA5, 0x06, 0x80, 0x01, 0x71,
0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0A, 0x81,
0x02, 0x00, 0x18, 0x88, 0x01, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

/* File content data : start*/
0x64, 0xF6, 0x10, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/ 
};

kal_uint8 EF_AUTH_data[258] =
{
0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF
};

#else
/* 
 * File id: 7FFF 
 */
kal_uint8 ADF_USIM_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{
    {
        /* 1st: The first 96 is meta data : start*/
        0x44, 0x62, 0x42, 0x82, 0x02, 0x78, 0x21, 0x84, 0x10, 0xA0, 0x00, 0x00, 0x00, 0x87, 0x10, 0x02,
        0xFF, 0x33, 0xFF, 0xFF, 0x89, 0x01, 0x01, 0x01, 0x00, 0xA5, 0x11, 0x80, 0x01, 0x71, 0x81, 0x03,
        0x01, 0x0A, 0x32, 0x82, 0x01, 0x0A, 0x83, 0x04, 0x00, 0x00, 0xF2, 0xD5, 0x8A, 0x01, 0x05, 0x8B, 
        0x03, 0x2F, 0x06, 0x02, 0xC6, 0x09, 0x90, 0x01, 0x40, 0x83, 0x01, 0x01, 0x83, 0x01, 0x81, 0x81,
        0x04, 0x00, 0x00, 0x0E, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },    
    {
        /* 2nd: The first 96 is meta data : start*/
        0x44, 0x62, 0x42, 0x82, 0x02, 0x78, 0x21, 0x84, 0x10, 0xA0, 0x00, 0x00, 0x00, 0x87, 0x10, 0x02,
        0xFF, 0x33, 0xFF, 0xFF, 0x89, 0x01, 0x01, 0x01, 0x00, 0xA5, 0x11, 0x80, 0x01, 0x71, 0x81, 0x03,
        0x01, 0x0A, 0x32, 0x82, 0x01, 0x0A, 0x83, 0x04, 0x00, 0x00, 0xF2, 0xD5, 0x8A, 0x01, 0x05, 0x8B, 
        0x03, 0x2F, 0x06, 0x02, 0xC6, 0x09, 0x90, 0x01, 0x40, 0x83, 0x01, 0x01, 0x83, 0x01, 0x81, 0x81,
        0x04, 0x00, 0x00, 0x0E, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x44, 0x62, 0x42, 0x82, 0x02, 0x78, 0x21, 0x84, 0x10, 0xA0, 0x00, 0x00, 0x00, 0x87, 0x10, 0x02,
        0xFF, 0x33, 0xFF, 0xFF, 0x89, 0x01, 0x01, 0x01, 0x00, 0xA5, 0x11, 0x80, 0x01, 0x71, 0x81, 0x03,
        0x01, 0x0A, 0x32, 0x82, 0x01, 0x0A, 0x83, 0x04, 0x00, 0x00, 0xF2, 0xD5, 0x8A, 0x01, 0x05, 0x8B, 
        0x03, 0x2F, 0x06, 0x02, 0xC6, 0x09, 0x90, 0x01, 0x40, 0x83, 0x01, 0x01, 0x83, 0x01, 0x81, 0x81,
        0x04, 0x00, 0x00, 0x0E, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x44, 0x62, 0x42, 0x82, 0x02, 0x78, 0x21, 0x84, 0x10, 0xA0, 0x00, 0x00, 0x00, 0x87, 0x10, 0x02,
        0xFF, 0x33, 0xFF, 0xFF, 0x89, 0x01, 0x01, 0x01, 0x00, 0xA5, 0x11, 0x80, 0x01, 0x71, 0x81, 0x03,
        0x01, 0x0A, 0x32, 0x82, 0x01, 0x0A, 0x83, 0x04, 0x00, 0x00, 0xF2, 0xD5, 0x8A, 0x01, 0x05, 0x8B, 
        0x03, 0x2F, 0x06, 0x02, 0xC6, 0x09, 0x90, 0x01, 0x40, 0x83, 0x01, 0x01, 0x83, 0x01, 0x81, 0x81,
        0x04, 0x00, 0x00, 0x0E, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x44, 0x62, 0x42, 0x82, 0x02, 0x78, 0x21, 0x84, 0x10, 0xA0, 0x00, 0x00, 0x00, 0x87, 0x10, 0x02,
        0xFF, 0x33, 0xFF, 0xFF, 0x89, 0x01, 0x01, 0x01, 0x00, 0xA5, 0x11, 0x80, 0x01, 0x71, 0x81, 0x03,
        0x01, 0x0A, 0x32, 0x82, 0x01, 0x0A, 0x83, 0x04, 0x00, 0x00, 0xF2, 0xD5, 0x8A, 0x01, 0x05, 0x8B, 
        0x03, 0x2F, 0x06, 0x02, 0xC6, 0x09, 0x90, 0x01, 0x40, 0x83, 0x01, 0x01, 0x83, 0x01, 0x81, 0x81,
        0x04, 0x00, 0x00, 0x0E, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
        
};

/* 
 * File id: 2F05
 */
kal_uint8 EF_U_ELP_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{
    {
        /* The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0x05, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x06, 0x81,
        0x02, 0x00, 0x14, 0x88, 0x01, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x98, 0x88, 0x96, 0x07, 0x02, 0X05, 0x27, 0x01, 0x01, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0x05, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x06, 0x81,
        0x02, 0x00, 0x14, 0x88, 0x01, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x98, 0x88, 0x96, 0x07, 0x02, 0X05, 0x27, 0x01, 0x01, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0x05, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x06, 0x81,
        0x02, 0x00, 0x14, 0x88, 0x01, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x98, 0x88, 0x96, 0x07, 0x02, 0X05, 0x27, 0x01, 0x01, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0x05, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x06, 0x81,
        0x02, 0x00, 0x14, 0x88, 0x01, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x98, 0x88, 0x96, 0x07, 0x02, 0X05, 0x27, 0x01, 0x01, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0x05, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x06, 0x81,
        0x02, 0x00, 0x14, 0x88, 0x01, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x98, 0x88, 0x96, 0x07, 0x02, 0X05, 0x27, 0x01, 0x01, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
    
};

/* 
  * File id: 2FE2
  */
kal_uint8 EF_U_ICCID_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{
    {
        /* The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0xE2, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0A, 0x81,
        0x02, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x98, 0x88, 0x96, 0x02, 0x55, 0X06, 0x00, 0x48, 0x53, 0x05, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0xE2, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0A, 0x81,
        0x02, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x98, 0x88, 0x96, 0x02, 0x55, 0X06, 0x00, 0x48, 0x53, 0x05, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0xE2, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0A, 0x81,
        0x02, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x98, 0x88, 0x96, 0x02, 0x55, 0X06, 0x00, 0x48, 0x53, 0x05, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0xE2, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0A, 0x81,
        0x02, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x98, 0x88, 0x96, 0x02, 0x55, 0X06, 0x00, 0x48, 0x53, 0x05, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x2F, 0xE2, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0A, 0x81,
        0x02, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x98, 0x88, 0x96, 0x02, 0x55, 0X06, 0x00, 0x48, 0x53, 0x05, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
    
};

/* 
  * File id: 6F73
  */
kal_uint8 EF_U_PSLOCI_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{
    {
        /* The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x73, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0E, 0x81,
        0x02, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0xEA, 0x25, 0xF3, 0x03, 0x92, 0x75, 0xF6, 0x64, 0xF6, 0x10, 0x24, 0xC2, 0x01, 0x00, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x73, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0E, 0x81,
        0x02, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0xEA, 0x25, 0xF3, 0x03, 0x92, 0x75, 0xF6, 0x64, 0xF6, 0x10, 0x24, 0xC2, 0x01, 0x00, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x73, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0E, 0x81,
        0x02, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0xEA, 0x25, 0xF3, 0x03, 0x92, 0x75, 0xF6, 0x64, 0xF6, 0x10, 0x24, 0xC2, 0x01, 0x00, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x73, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0E, 0x81,
        0x02, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0xEA, 0x25, 0xF3, 0x03, 0x92, 0x75, 0xF6, 0x64, 0xF6, 0x10, 0x24, 0xC2, 0x01, 0x00, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x73, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0E, 0x81,
        0x02, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0xEA, 0x25, 0xF3, 0x03, 0x92, 0x75, 0xF6, 0x64, 0xF6, 0x10, 0x24, 0xC2, 0x01, 0x00, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
    
};

/* 
  * File id: 6F78
  */
kal_uint8 EF_U_ACC_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{  
    {
        /* The first 96 is meta data : start*/
        0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0x78, 0xA5, 0x03, 0x80, 0x01, 0x71,
        0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x07, 0x80, 0x02, 0x00, 0x02, 0x88, 0x01, 0x30, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0x78, 0xA5, 0x03, 0x80, 0x01, 0x71,
        0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x07, 0x80, 0x02, 0x00, 0x02, 0x88, 0x01, 0x30, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0x78, 0xA5, 0x03, 0x80, 0x01, 0x71,
        0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x07, 0x80, 0x02, 0x00, 0x02, 0x88, 0x01, 0x30, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0x78, 0xA5, 0x03, 0x80, 0x01, 0x71,
        0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x07, 0x80, 0x02, 0x00, 0x02, 0x88, 0x01, 0x30, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0x78, 0xA5, 0x03, 0x80, 0x01, 0x71,
        0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x07, 0x80, 0x02, 0x00, 0x02, 0x88, 0x01, 0x30, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
    
};

/* 
  * File id: 6F7E
  */
kal_uint8 EF_U_LOCI_data[VSIM_PROFILE_ENTRY][128] = 
{
    {
        /* The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x7E, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0B, 0x81,
        0x02, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x8E, 0x00, 0x2D, 0xD4, 0x64, 0xF6, 0x10, 0x24, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x7E, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0B, 0x81,
        0x02, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x8E, 0x00, 0x2D, 0xD4, 0x64, 0xF6, 0x10, 0x24, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x7E, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0B, 0x81,
        0x02, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x8E, 0x00, 0x2D, 0xD4, 0x64, 0xF6, 0x10, 0x24, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x7E, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0B, 0x81,
        0x02, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x8E, 0x00, 0x2D, 0xD4, 0x64, 0xF6, 0x10, 0x24, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x7E, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x0B, 0x81,
        0x02, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x8E, 0x00, 0x2D, 0xD4, 0x64, 0xF6, 0x10, 0x24, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
    
};

/* 
  * File id: 6FAD
  */
kal_uint8 EF_U_AD_data[VSIM_PROFILE_ENTRY][EF_META_SIZE+EF_DATA_SIZE] = 
{   
    {
        /* The first 96 is meta data : start*/
        0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0xAD, 0xA5, 0x03, 0x80, 0x01, 0x71,
        0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x0A, 0x80, 0x02, 0x00, 0x04, 0x88, 0x01, 0x18, 0x00,
        0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x2E, 0xFA, 0x9B, 0x9D, 0x7F, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0xAD, 0xA5, 0x03, 0x80, 0x01, 0x71,
        0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x0A, 0x80, 0x02, 0x00, 0x04, 0x88, 0x01, 0x18, 0x00,
        0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x2E, 0xFA, 0x9B, 0x9D, 0x7F, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0xAD, 0xA5, 0x03, 0x80, 0x01, 0x71,
        0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x0A, 0x80, 0x02, 0x00, 0x04, 0x88, 0x01, 0x18, 0x00,
        0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x2E, 0xFA, 0x9B, 0x9D, 0x7F, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0xAD, 0xA5, 0x03, 0x80, 0x01, 0x71,
        0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x0A, 0x80, 0x02, 0x00, 0x04, 0x88, 0x01, 0x18, 0x00,
        0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x2E, 0xFA, 0x9B, 0x9D, 0x7F, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x1E, 0x62, 0x1C, 0x82, 0x02, 0x41, 0x21, 0x83, 0x02, 0x6F, 0xAD, 0xA5, 0x03, 0x80, 0x01, 0x71,
        0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x0A, 0x80, 0x02, 0x00, 0x04, 0x88, 0x01, 0x18, 0x00,
        0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x2E, 0xFA, 0x9B, 0x9D, 0x7F, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    }
};

/* 
  * File id: 6F07
  * Note: IMSI will store in NVRAM, the NVRAM FILE SIZE is NVRAM_VSIM_EF_U_DEFUALT_SIZE (128bytes)
  */
kal_uint8 EF_U_IMSI_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{
    {
        /* The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x07, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x09, 0x81,
        0x02, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x08, 0x09, 0x10, 0x10, 0x10, 0x32, 0x54, 0x06, 0x36, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x07, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x09, 0x81,
        0x02, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x08, 0x09, 0x10, 0x10, 0x10, 0x32, 0x54, 0x06, 0x36, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x07, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x09, 0x81,
        0x02, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x08, 0x09, 0x10, 0x10, 0x10, 0x32, 0x54, 0x06, 0x36, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x07, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x09, 0x81,
        0x02, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x08, 0x09, 0x10, 0x10, 0x10, 0x32, 0x54, 0x06, 0x36, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x07, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x09, 0x81,
        0x02, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x08, 0x09, 0x10, 0x10, 0x10, 0x32, 0x54, 0x06, 0x36, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
};
/* 
  * File id: 6F31
  */
kal_uint8 EF_U_HPPLMN_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{
    {
        /* The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x31, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x01, 0x81,
        0x02, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x31, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x01, 0x81,
        0x02, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x31, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x01, 0x81,
        0x02, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x31, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x01, 0x81,
        0x02, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x31, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x01, 0x81,
        0x02, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
    
};

/* 
  * File id: 6F38
  */
kal_uint8 EF_U_UST_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{
    {
        /* The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x38, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0B, 0x81,
        0x02, 0x00, 0x15, 0x88, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x2E, 0xFA, 0x9B, 0x9D, 0x67, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x38, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0B, 0x81,
        0x02, 0x00, 0x15, 0x88, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x2E, 0xFA, 0x9B, 0x9D, 0x67, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x38, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0B, 0x81,
        0x02, 0x00, 0x15, 0x88, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x2E, 0xFA, 0x9B, 0x9D, 0x67, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x38, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0B, 0x81,
        0x02, 0x00, 0x15, 0x88, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x2E, 0xFA, 0x9B, 0x9D, 0x67, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x38, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0B, 0x81,
        0x02, 0x00, 0x15, 0x88, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x2E, 0xFA, 0x9B, 0x9D, 0x67, 0xC6, 0x03, 0x00, 0x00, 0x00, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
    
};

/* 
  * File id: 6F56
  */
kal_uint8 EF_U_EST_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{
    {
        /* The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x56, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x02, 0x81,
        0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x56, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x02, 0x81,
        0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x56, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x02, 0x81,
        0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x56, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x02, 0x81,
        0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x22, 0x62, 0x20, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x56, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x2F, 0x06, 0x06, 0x80, 0x02, 0x00, 0x02, 0x81,
        0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
    
};

/* 
  * File id: 6F60
  */
kal_uint8 EF_U_PLMNWACT_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{
    {
        /* The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x60, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x05, 0x80, 0x02, 0x00, 0x0F, 0x81,
        0x02, 0x00, 0x1D, 0x88, 0x01, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x60, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x05, 0x80, 0x02, 0x00, 0x0F, 0x81,
        0x02, 0x00, 0x1D, 0x88, 0x01, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x60, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x05, 0x80, 0x02, 0x00, 0x0F, 0x81,
        0x02, 0x00, 0x1D, 0x88, 0x01, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x60, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x05, 0x80, 0x02, 0x00, 0x0F, 0x81,
        0x02, 0x00, 0x1D, 0x88, 0x01, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x60, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x05, 0x80, 0x02, 0x00, 0x0F, 0x81,
        0x02, 0x00, 0x1D, 0x88, 0x01, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }
    
};

/* 
  * File id: 6F61
  */
kal_uint8 EF_U_OPLMNWACT_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{


    {
        /* The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x61, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0F, 0x81,
        0x02, 0x00, 0x1D, 0x88, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x61, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0F, 0x81,
        0x02, 0x00, 0x1D, 0x88, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x61, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0F, 0x81,
        0x02, 0x00, 0x1D, 0x88, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x61, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0F, 0x81,
        0x02, 0x00, 0x1D, 0x88, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x61, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0F, 0x81,
        0x02, 0x00, 0x1D, 0x88, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0x64, 0xF6, 0x88, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }

};

/* 
  * File id: 6F62
  */
kal_uint8 EF_U_HPLMNWACT_data[VSIM_PROFILE_ENTRY][EF_U_META_SIZE+EF_U_DATA_SIZE] = 
{
    {
        /* The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x62, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0A, 0x81,
        0x02, 0x00, 0x18, 0x88, 0x01, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/    
    },
    {
        /* 2nd: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x62, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0A, 0x81,
        0x02, 0x00, 0x18, 0x88, 0x01, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/        
    },
    {
        /* 3rd: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x62, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0A, 0x81,
        0x02, 0x00, 0x18, 0x88, 0x01, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 4th: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x62, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0A, 0x81,
        0x02, 0x00, 0x18, 0x88, 0x01, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    },
    {
        /* 5th: The first 96 is meta data : start*/
        0x25, 0x62, 0x23, 0x82, 0x02, 0x01, 0x21, 0x83, 0x02, 0x6F, 0x62, 0xA5, 0x06, 0x80, 0x01, 0x71,
        0xC0, 0x01, 0x00, 0x8A, 0x01, 0x05, 0x8B, 0x03, 0x6F, 0x06, 0x03, 0x80, 0x02, 0x00, 0x0A, 0x81,
        0x02, 0x00, 0x18, 0x88, 0x01, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        /* The first 96 is meta data : end*/
        /* File content data : start*/
        0x64, 0xF6, 0x10, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        /* File content data : end*/
    }

};
#endif /* __MDVSIM__ */
#endif /* __VSIM__ */


/* This is SAT terminal profile content.
 * NOTE: Please do NOT MODIFY it by yourself !!!                                               
 * If you want to customize SAT terminal profile content, please consult with MTK first. */
#ifdef __SAT_ADDITIONAL_LOCK__
kal_uint8 sim_profile[MAX_SIM_PROFILE_LEN + SAT_ADDITIONAL_TER_PROFILE] =
#else 
kal_uint8 sim_profile[MAX_SIM_PROFILE_LEN] =
#endif 
{           /* develope value */
    0xF7    /* 1st */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x08      /*MENU SELECTION*/
    #endif
    , 
        
    0x17    /* 2nd */
    #ifndef __DISABLE_SMS_CONTROLLED_BY_SIM__
    | 0x08    //MO short message control support
    #endif
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0xE0
    #endif
    ,

    0xC8       /* 3rd */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x37
    #endif
    ,
    0x8E       /* 4th */
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x40      // 0x40: PROVIDE LOCAL INFORMATION (MCC, MNC, LAV, Cell ID, IMEI)
    #endif
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x21
    #ifndef __DISABLE_CSCALL__
    | 0x10  // 0x10: Proactive SIM: SET UP CALL
    #endif
    #endif
    ,

    0x01    /*5th*/  //Proactive UICC: SET UP EVENT LIST
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    #ifndef __SAT_LOWCOST_UI_DISABLE__
    | 0x60  // 0x20: Event: User activity
               // 0x40: Event: Idle screen available
    #endif
    #endif
    #ifndef __SAT_LOWCOST_NW_DISABLE__
    | 0x1E   // 0x02: Event: MT call
                // 0x04: Event: Call connected
                // 0x08: Event: Call disconnected
                // 0x10: Event: Location status
    #endif
    ,

    0x90    /* 6th */  //0x10:  Event: Access Technology Change
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    #if !defined(__SAT_LOWCOST_UI_DISABLE__)
    | 0x01  // Event: Language selection
    #endif
    #endif
    #if defined(__SATCC__)
    | 0x02  // Event: Browser Termination
    #endif
    #if defined(__SATCE__)
    | 0x0C  // 0x04: Event: Data available
               // 0x08: Event: Channel status
    #endif
    ,

    0x00,   /* 7th */
    0x87 /* 8th */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x58
    #endif
    #ifdef __SATCB__
    | 0x20      // RUN AT COMMAND (i.e. class "b" is supported)
    #endif
    ,

    0x06        /* 9th */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x01      // 0x01: Sustained DISPLAY TEXT 
    #if !defined(__SAT_LOWCOST_UI_DISABLE__)
    | 0x20      // 0x20: LANGUAGE NOTIFICATION
    #endif
    #endif
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x08      // 0x08: PROVIDE LOCAL INFORMATION (language)
    #endif
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x10      // 0x10: PROVIDE LOCAL INFORMATION (Timing Advance)
    #endif
    #if defined(__SATCC__)
    | 0x40     // 0x40: LAUNCH BROWSER
    #endif
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x80      // 0x80: PROVIDE LOCAL INFORMATION (Access Technology)
    #endif    
    ,

    0x00,   /* 10th *//* No other Softkeys supported */
    0x00,   /* 11th */
    
    0x00    /* 12th */
    #ifdef __SATCE__
    | 0x1F
    #endif
    ,
    
    0x00    /* 13th */
    #ifdef __SATCE__
    | 0xE2
    #if defined(CSD_SUPPORT)
    | 0x01   //0x01: CSD
    #endif
    #endif
    ,

    0x00    /* 14th */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x08
    #else
    | 0x60
    #endif
    ,

    0x00    /* 15th */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x11
    #endif
    ,
    
    0x00   /* 16th */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x06
    #endif
    ,

    0x80    /* 17th */
    #ifdef __LTE_RAT__
    | 0x40          //0x40: E-UTRAN (i.e. if class "e" is supported)
    #endif
    #ifdef __SATCE__    
    | 0x07
    #endif
    ,

    0xC0    /* 18th */ /* MAUI_02883701 GET INKEY HELP */

#if defined(__REL7__) || defined(__SATCL__) || defined(__SATCM__) || defined(__SATCR__)
        ,
    0x00,   /* 19th */
    0x00,   /* 20th */
    0x00,   /* 21th */
    0x00,   /* 22th */
    0x40,   /* 23th */
    0x00,   /* 24th */
    0x00    /* 25th */
    | 0x01          // 0x01: Event browsing status    
    | 0x10          // 0x10: Event Network Rejection 
#ifdef __LTE_RAT__
    | 0x40          // 0x40: Event: E-UTRAN support in Event Network Rejection
#endif
#if defined(__SATCM__)    
    | 0x20          // 0x20: HCI connectivity event (if class "m" is supported)
#endif 
    ,

    0x00    /* 26th */
#if defined(__SATCR__) 
    | 0x02 /* Event: Contactless state request */
#endif 
    ,

    0x00,   /* 27th */    
    0x00,   /* 28th */
    0x00,   /* 29th */
   
    0x00    /* 30th */
#if defined(__REL7__) 
    | 0x08 /* Steering of Roaming" REFRESH support */
#endif
#if defined(__SATCL__)
    | 0x10 /* Proactive UICC: ACTIVATE (i.e class "l" is supported) */
#endif    
    ,

    0x00     /* 31th */
#if defined(__SATCR__)
    | 0x01  /* Proactive UICC: Contactless State Changed */
#endif
#if defined(__IMS_SUPPORT__)
//  | 0x20  /* Incoming IMS Data event */
//  | 0x40  /* IMS Registration event */
#endif
    ,
    0x00    /* 32th */
#if defined(__IMS_SUPPORT__)
//  | 0x01  /* IMS support*/
#endif
#ifdef __TC01__
    ,

    0x00    /* 33th */
    | 0x01  /* Support of DNS server address request for OPEN CHANNEL related to packet data service bearer */
    | 0x02  /* Support of Network Access Name reuse indication for CLOSE CHANNEL related to packet data service bearer */
//  | 0x04  /* Event: Poll Interval Negotiation */
//  | 0x08  /* ProSe usage information reporting */
//  | 0x10  /* ProSe usage information reporting */
//  | 0x20  /* ProSe usage information reporting */
//  | 0x40  /* ProSe usage information reporting */
//  | 0x80  /* ProSe usage information reporting */
//  ,
#endif
#endif
#ifdef __SAT_ADDITIONAL_LOCK__
        ,
    0x00,   /* 31th: 1 */
    0x00,   /* 32th: 2 */
    0x00,   /* 33th: 3 */
    0x00,   /* 34th: 4 */
    0x00,   /* 35th: 5 */
    0x00,   /* 36th: 6 */
    0x00,   /* 37th: 7 */
    0x00,   /* 38th: 8 */
    0x00    /* 39th: 9 */
#endif /* __SAT_ADDITIONAL_LOCK__ */ 
};

#ifdef __EXTERNAL_CDMA_SUPPORT__

/* CSIM profile is from MD3's suggestion */
kal_uint8 csim_profile[MAX_SIM_PROFILE_LEN]={

    0x00    /* 1st (Download) */
    | 0x01  /* Profile download */
    | 0x02  /* SMS-PP data download */
    | 0x04  /* Cell Broadcast data download */
    | 0x08  /* Menu selection */
    | 0x10  /* SMS-PP data download */
    | 0x20  /* Timer expiration */
    | 0x40  /* USSD string data object support in Call Control by USIM */
    | 0x80  /* Call Control by NAA */
    ,

    0x00    /* 2nd (Other) */
    | 0x01  /* Command result */
    | 0x02  /* Call Control by NAA */
    | 0x04  /* Call Control by NAA */
    | 0x08  /* MO short message control support */
    | 0x10  /* Call Control by NAA */
    | 0x20  /* UCS2 Entry supported */
    | 0x40  /* UCS2 Display supported */
    | 0x80  /* Display Text */
    ,

    0x00    /* 3rd (Proactive UICC) */
    | 0x01  /* Proactive UICC: DISPLAY TEXT */
    | 0x02  /* Proactive UICC: GET INKEY */
    | 0x04  /* Proactive UICC: GET INPUT */
    | 0x08  /* Proactive UICC: MORE TIME */
    | 0x10  /* Proactive UICC: PLAY TONE */
    | 0x20  /* Proactive UICC: POLL INTERVAL */
    | 0x40  /* Proactive UICC: POLLING OFF */
    | 0x80  /* Proactive UICC: REFRESH */
    ,

    0x00    /* 4th (Proactive UICC) */
    | 0x01  /* Proactive UICC: SELECT ITEM */
    | 0x02  /* Proactive UICC: SEND SHORT MESSAGE with 3GPP-SMS-TPDU */
    | 0x04  /* Proactive UICC: SEND SS */
    | 0x08  /* Proactive UICC: SEND USSD */
    | 0x10  /* Proactive UICC: SET UP CALL */
    | 0x20  /* Proactive UICC: SET UP MENU */
    | 0x40  /* Proactive UICC: PROVIDE LOCAL INFORMATION (MCC, MNC, LAC, Cell ID & IMEI) */
    | 0x80  /* Proactive UICC: PROVIDE LOCAL INFORMATION (NMR) */
    ,

    0x00    /*5th (Event driven information) */
    | 0x01  /* Proactive UICC: SET UP EVENT LIST */
    | 0x02  /* Event: MT call */
    | 0x04  /* Event: Call connected */
    | 0x08  /* Event: Call disconnected */
    | 0x10  /* Event: Location status */
    | 0x20  /* Event: User activity */
    | 0x40  /* Event: Idle screen available */
//  | 0x80  /* Event: Card reader status */
    ,

    0x00    /* 6th (Event driven information extensions) */
    | 0x01  /* Event: Language selection */
    | 0x02  /* Event: Browser Termination */
    | 0x04  /* Event: Data available */
    | 0x08  /* Event: Channel status */
    | 0x10  /* Event: Access Technology Change */
//  | 0x20  /* Event: Display parameters changed */
//  | 0x40  /* Event: Local Connection */
    | 0x80  /* Event: Network Search Mode Change */
    ,

    0x00    /* 7th (Multiple card proactive commands) for class "a" */
//  | 0x01  /* Proactive UICC: POWER ON CARD */
//  | 0x02  /* Proactive UICC: POWER OFF CARD */
//  | 0x04  /* Proactive UICC: PERFORM CARD APDU */
//  | 0x08  /* Proactive UICC: GET READER STATUS (Card reader status) */
//  | 0x10  /* Proactive UICC: GET READER STATUS (Card reader identifier) */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 8th (Proactive UICC) */
    | 0x01  /* Proactive UICC: TIMER MANAGEMENT (start, stop) */
    | 0x02  /* Proactive UICC: TIMER MANAGEMENT (get current value) */
    | 0x04  /* Proactive UICC: PROVIDE LOCAL INFORMATION (date, time and time zone) */
    | 0x08  /* GET INKEY */
    | 0x10  /* SET UP IDLE MODE TEXT */
//  | 0x20  /* RUN AT COMMAND */
    | 0x40  /* SETUP CALL */
    | 0x80  /* Call Control by NAA */
    ,

    0x00    /* 9th */
    | 0x01  /* DISPLAY TEXT */
    | 0x02  /* SEND DTMF command */
    | 0x04  /* Proactive UICC: PROVIDE LOCAL INFORMATION (NMR) */
    | 0x08  /* Proactive UICC: PROVIDE LOCAL INFORMATION (language) */
//  | 0x10  /* Proactive UICC: PROVIDE LOCAL INFORMATION, Timing Advance */
    | 0x20  /* Proactive UICC: LANGUAGE NOTIFICATION */
    | 0x40  /* Proactive UICC: LAUNCH BROWSER */
    | 0x80  /* Proactive UICC: PROVIDE LOCAL INFORMATION (Access Technology) */
    ,

    0x00    /* 10th (Soft keys support) for class "d" */
//  | 0x01  /* Soft keys support for SELECT ITEM */
//  | 0x02  /* Soft Keys support for SET UP MENU */
//  | 0x04  /* RFU, bit = 0 */
//  | 0x08  /* RFU, bit = 0 */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 11th (Soft keys information) */
//  | 0x01  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x02  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x04  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x08  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x10  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x20  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x40  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x80  /* Maximum number of soft keys available 'FF' value is reserved for future use */
    ,

    0x00    /* 12th (Bearer Independent protocol proactive commands, class "e") */
    | 0x01  /* Proactive UICC: OPEN CHANNEL */
    | 0x02  /* Proactive UICC: CLOSE CHANNEL */
    | 0x04  /* Proactive UICC: RECEIVE DATA */
    | 0x08  /* Proactive UICC: SEND DATA */
    | 0x10  /* Proactive UICC: GET CHANNEL STATUS */
//  | 0x20  /* Proactive UICC: SERVICE SEARCH */
//  | 0x40  /* Proactive UICC: GET SERVICE INFORMATION */
//  | 0x80  /* Proactive UICC: DECLARE SERVICE */
    ,

    0x00    /* 13th (Bearer Independent protocol supported bearers, class "e") */
//  | 0x01  /* CSD */
//  | 0x02  /* GPRS */
//  | 0x04  /* Bluetooth */
//  | 0x08  /* IrDA */
//  | 0x10  /* RS232 */
//  | 0x20  /* Number of channels supported by terminal */
//  | 0x40  /* Number of channels supported by terminal */
//  | 0x80  /* Number of channels supported by terminal */
    ,

    0x00    /* 14th (Screen height) */
    | 0x01  /* Number of characters supported down the terminal display */
//  | 0x02  /* Number of characters supported down the terminal display */
    | 0x04  /* Number of characters supported down the terminal display */
//  | 0x08  /* Number of characters supported down the terminal display */
//  | 0x10  /* Number of characters supported down the terminal display */
//  | 0x20  /* No display capability */
//  | 0x40  /* No keypad available */
//  | 0x80  /* Screen Sizing Parameters supported */
    ,

    0x00    /* 15th (Screen width) */
    | 0x01  /* Number of characters supported across the terminal display */
    | 0x02  /* Number of characters supported across the terminal display */
    | 0x04  /* Number of characters supported across the terminal display */
//  | 0x08  /* Number of characters supported across the terminal display */
//  | 0x10  /* Number of characters supported across the terminal display */
//  | 0x20  /* Number of characters supported across the terminal display */
//  | 0x40  /* Number of characters supported across the terminal display */
//  | 0x80  /* Variable size fonts */
    ,

    0x00    /* 16th (Screen effects) */
//  | 0x01  /* Display can be resized */
//  | 0x02  /* Text Wrapping supported */
    | 0x04  /* Text Scrolling supported */
//  | 0x08  /* Text Attributes supported*/
//  | 0x10  /* RFU, bit = 0 */
    | 0x20  /* Width reduction when in a menu */
    | 0x40  /* Width reduction when in a menu */
    | 0x80  /* Width reduction when in a menu */
    ,

    0x00    /* 17th (Bearer independent protocol supported transport interface/bearers, class "e") */
    | 0x01  /* TCP, UICC in client mode, remote connection */
    | 0x02  /* UDP, UICC in client mode, remote connection */
    | 0x04  /* TCP, UICC in server mode */
//  | 0x08  /* TCP, UICC in client mode, local connection*/
//  | 0x10  /* UDP, UICC in client mode, local connection*/
//  | 0x20  /* Direct communication channel */
//  | 0x40  /* E-UTRAN */
//  | 0x80  /* HSDPA */
    ,

    0x00    /* 18th */
//  | 0x01  /* Proactive UICC: DISPLAY TEXT (Variable Time out) */
//  | 0x02  /* Proactive UICC: GET INKEY (help is supported while waiting for immediate response or variable timeout) */
//  | 0x04  /* USB (Bearer Independent protocol supported bearers,class "e") */
//  | 0x08  /* Proactive UICC: GET INKEY (Variable Timeout) */
    | 0x10  /* Proactive UICC: PROVIDE LOCAL INFORMATION (ESN) */
//  | 0x20  /* Call control on GPRS */
    | 0x40  /* Proactive UICC: PROVIDE LOCAL INFORMATION (IMEISV) */
    | 0x80  /* Proactive UICC: PROVIDE LOCAL INFORMATION (Search Mode change) */
    ,

    0x00   /* 19th reserved for TIA/EIA-136-C facilities */
//  | 0x01  /* Reserved by TIA/EIA-136, bit = 0 */
//  | 0x02  /* Reserved by TIA/EIA-136, bit = 0 */
//  | 0x04  /* Reserved by TIA/EIA-136, bit = 0 */
//  | 0x08  /* Reserved by TIA/EIA-136, bit = 0 */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 20th (reserved for 3GPP2 C.S0035-B CCAT) */
    | 0x01  /* send cdma sms*/
    | 0x02  /* cdma sms-pp data download */
    | 0x04  /* BROADCAST SMS data download */
//  | 0x08  /* Reserved by TIA/EIA/IS-820, bit = 0 */
//  | 0x10  /* Reserved by TIA/EIA/IS-820, bit = 0 */
//  | 0x20  /* Reserved by TIA/EIA/IS-820, bit = 0 */
//  | 0x40  /* Reserved by TIA/EIA/IS-820, bit = 0 */
//  | 0x80  /* Reserved by TIA/EIA/IS-820, bit = 0 */
    ,

    0x00    /* 21th (Extended Launch Browser Capability) for class "ac" */
//  | 0x01  /* WML */
//  | 0x02  /* XHTML */
//  | 0x04  /* HTML */
//  | 0x08  /* CHTML */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 22th */
//  | 0x01  /* Support of UTRAN PS with extended parameters */
//  | 0x02  /* Proactive UICC: PROVIDE LOCAL INFORMATION(battery state) */
//  | 0x04  /* Proactive UICC: PLAY TONE (Melody tones and Themed tones supported) */
//  | 0x08  /* Multi-media Calls in SET UP CALL */
//  | 0x10  /* Toolkit-initiated GBA */
//  | 0x20  /* Proactive UICC: RETRIEVE MULTIMEDIA MESSAGE */
//  | 0x40  /* Proactive UICC: SUBMIT MULTIMEDIA MESSAGE */
//  | 0x80  /* Proactive UICC: DISPLAY MULTIMEDIA MESSAGE */
    ,

    0x00   /* 23th */
//  | 0x01  /* Proactive UICC: SET FRAMES */
//  | 0x02  /* Proactive UICC: GET FRAMES STATUS */
//  | 0x04  /* MMS notification download */
//  | 0x08  /* Alpha Identifier in REFRESH command supported by terminal */
//  | 0x10  /* Geographical Location Reporting*/
    | 0x20  /* Proactive UICC: PROVIDE LOCAL INFORMATION (MEID) */
    | 0x40  /* Proactive UICC: PROVIDE LOCAL INFORMATION (NMR(UTRAN/E-UTRAN)) */
//  | 0x80  /* USSD Data download and application mode */
    ,

    0x00    /* 24th for class "i" */
//  | 0x01  /* Maximum number of frames supported (including frames created in existing frames) */
//  | 0x02  /* Maximum number of frames supported (including frames created in existing frames) */
//  | 0x04  /* Maximum number of frames supported (including frames created in existing frames) */
//  | 0x08  /* Maximum number of frames supported (including frames created in existing frames) */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 25th (Event driven information extensions) */
//  | 0x01  /* Event browsing status */
//  | 0x02  /* Event: MMS Transfer status */
//  | 0x04  /* Event: Frame Information changed */
//  | 0x08  /* Event: I-WLAN Access status*/
    | 0x10  /* Event Network Rejection */ 
//  | 0x20  /* Event: HCI connectivity event (if class "m" is supported) */
    | 0x40  /* E-UTRAN support in Event Network Rejection */
//  | 0x80  /* Multiple access technologies supported in Event Access Technology Change and PROVIDE LOCAL INFORMATION */
    ,

    0x00    /* 26th (Event driven information extensions) */
//  | 0x01  /* Event : CSG Cell Selection */
//  | 0x02  /* Event: Contactless state request */
//  | 0x04  /* RFU, bit = 0 */
//  | 0x08  /* RFU, bit = 0 */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 27th (Event driven information extensions) */
//  | 0x01  /* RFU, bit = 0 */
//  | 0x02  /* RFU, bit = 0 */
//  | 0x04  /* RFU, bit = 0 */
//  | 0x08  /* RFU, bit = 0 */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 28th (Text attributes) */
//  | 0x01  /* Alignment left supported by Terminal */
//  | 0x02  /* Alignment centre supported by Terminal */
//  | 0x04  /* Alignment right supported by Terminal */
//  | 0x08  /* Font size normal supported by Terminal */
//  | 0x10  /* Font size large supported by Terminal */
//  | 0x20  /* Font size small supported by Terminal */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 29th (Text attributes) */
//  | 0x01  /* Style normal supported by Terminal */
//  | 0x02  /* Style bold supported by Terminal */
//  | 0x04  /* Style italic supported by Terminal */
//  | 0x08  /* Style underlined supported by Terminal */
//  | 0x10  /* Style strikethrough supported by Terminal */
//  | 0x20  /* Style text foreground colour supported by Terminal */
//  | 0x40  /* Style text background colour supported by Terminal */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 30th */
//  | 0x01  /* I-WLAN bearer support */
//  | 0x02  /* Proactive UICC: PROVIDE LOCAL INFORMATION (WSID of the current I-WLAN connection) */
//  | 0x04  /* TERMINAL APPLICATIONS */
    | 0x08  /* Steering of Roaming" REFRESH support */
//  | 0x10  /* Proactive UICC: ACTIVATE (i.e class "l" is supported) */
    | 0x20  /* Proactive UICC: GEOGRAPHICAL LOCATION REQUEST */
//  | 0x40  /* Proactive UICC: PROVIDE LOCAL INFORMATION(Broadcast Network Information) */
    | 0x80  /* Steering of Roaming for I-WLAN REFRESH support */
    ,

    0x00    /* 31th */
//  | 0x01  /* Proactive UICC: Contactless State Changed */
    | 0x02  /* Support of CSG cell discovery */
    | 0x04  /* Confirmation parameters supported for OPEN CHANNEL in Terminal Server Mode */
//  | 0x08  /* Communication Control for IMS */
//  | 0x10  /* Support of CAT over the modem interface */
//  | 0x20  /* Support for Incoming IMS Data event */
//  | 0x40  /* Support for IMS Registration event */
//  | 0x80  /* Proactive UICC: Profile Container, Envelope Container, COMMAND CONTAINER and ENCAPSULATED SESSION CONTROL */
    ,

    0x00    /* 32th */
//  | 0x01  /* Support of IMS as a bearer for BIP */
//  | 0x02  /* Support of PROVIDE LOCATION INFORMATION, H(e)NB IP address */
//  | 0x04  /* Support of PROVIDE LOCATION INFORMATION, H(e)NB surrounding macrocells */
//  | 0x08  /* Launch parameters supported for OPEN CHANNEL in Terminal Server Mode */
//  | 0x10  /* Direct communication channel supported for OPEN CHANNEL in Terminal Server Mode */
//  | 0x20  /* Proactive UICC: Security for Profile Container, Envelope Container, COMMAND CONTAINER and ENCAPSULATED SESSION CONTROL */
//  | 0x40  /* CAT service list for eCAT client */
//  | 0x80  /* Support of refresh enforcement policy */
#ifdef __TC01__
    ,

    0x00    /* 33th */
//  | 0x01  /* Support of DNS server address request for OPEN CHANNEL related to packet data service bearer */
//  | 0x02  /* Support of Network Access Name reuse indication for CLOSE CHANNEL related to packet data service bearer */
//  | 0x04  /* Event: Poll Interval Negotiation */
//  | 0x08  /* ProSe usage information reporting */
//  | 0x10  /* ProSe usage information reporting */
//  | 0x20  /* ProSe usage information reporting */
//  | 0x40  /* ProSe usage information reporting */
//  | 0x80  /* ProSe usage information reporting */
//  ,
#endif
};


#endif /* __EXTERNAL_CDMA_SUPPORT__ */
/* This is USAT terminal profile content.
 * NOTE: Please do NOT MODIFY it by yourself !!!
 * If you want to customize USAT terminal profile content, please consult with MTK first. */
kal_uint8 usim_te_profile[MAX_SIM_PROFILE_LEN] = {0};
kal_uint8 usim_mt_profile[MAX_SIM_PROFILE_LEN] = {0};
kal_uint8 usim_conflict_profile[MAX_SIM_PROFILE_LEN] = {0};
kal_uint8 usim_mt_only_profile[MAX_SIM_PROFILE_LEN] = 
{
    0xc0,   /* 1st */
            // b7: Call Control by NAA (USSD string data object support in Call Control by USIM)
            // b8: Call Control by NAA (Envelope call control always sent to the SIM during automatic redial mode)

    0x16,   /* 2nd */
            // b2: Call Control by NAA
            // b3: Call Control by NAA (Cell identity included in call control)
            // b5: Call Control by NAA (Handling of alpha ID according to spec 11.14)

    0x60,   /* 3rd */
            // b6: POLL INTERVAL
            // b7: POLLING OFF

    0xc0,   /* 4th */
            // b7: PROVIDE LOCAL INFORMATION (MCC, MNC, LAC, Cell ID & IMEI)
            // b8: PROVIDE LOCAL INFORMATION (NMR)

    0x1e,   /* 5th */
            // b2: Event: MT call
            // b3: Event: Call connected
            // b4: Event: Call disconnected
            // b5: Event: Location status

    0x90,   /* 6th */
            // b5: Event: Access Technology Change
            // b8: Event: Network Search Mode Change

    0x00,   /* 7th */
    0x80,   /* 8th */
            // b8: Call Control by NAA (2nd capability configuration parameter)

    0x00,   /* 9th */
    0x00,   /* 10th */
    0x00,   /* 11th */
    0x00,   /* 12th */
    0x00,   /* 13th */
    0x00,   /* 14th */
    0x00,   /* 15th */
    0x00,   /* 16th */
    0x00,   /* 17th */
    0xf0,   /* 18th */
            // b5: PROVIDE LOCAL INFORMATION (ESN)
            // b6: Call Control by NAA (Call control on GPRS)
            // b7: PROVIDE LOCAL INFORMATION (IMEISV)
            // b8: PROVIDE LOCAL INFORMATION (Search Mode Change)

#if defined(__REL7__) || defined(__SATCL__) || defined(__SATCM__) || defined(__SATCR__)
    0x00,   /* 19th */
    0x00,   /* 20th */
    0x00,   /* 21th */
    0x40,   /* 22th */
            // b7: PROVIDE LOCAL INFORMATION (NMR(UTRAN/E-UTRAN))

    0x00,   /* 23th */
    0x00,   /* 24th */
    0x00,   /* 25th */
    0x00,   /* 26th */
    0x00,   /* 27th */
    0x00,   /* 28th */
    0x00,   /* 29th */
    0x80,   /* 30th */
            // b8: Steering of Roaming for I-WLAN REFRESH support
    0x00,   /* 31th */
    0x00    /* 32th */
#ifdef __TC01__
    ,
    0x00    /* 33th */
//  | 0x01  /* Support of DNS server address request for OPEN CHANNEL related to packet data service bearer */
//  | 0x02  /* Support of Network Access Name reuse indication for CLOSE CHANNEL related to packet data service bearer */
//  | 0x04  /* Event: Poll Interval Negotiation */
//  | 0x08  /* ProSe usage information reporting */
//  | 0x10  /* ProSe usage information reporting */
//  | 0x20  /* ProSe usage information reporting */
//  | 0x40  /* ProSe usage information reporting */
//  | 0x80  /* ProSe usage information reporting */
//  ,
#endif
#endif
};
kal_uint8 usim_mt_default_profile[MAX_SIM_PROFILE_LEN] =
{
    0x00    /* 1st (Download) */
    | 0x01  /* Profile download */
    | 0x02  /* SMS-PP data download */
    | 0x04  /* Cell Broadcast data download */
//  | 0x08  /* Menu selection */
    | 0x10  /* SMS-PP data download */
    | 0x20  /* Timer expiration */
    | 0x40  /* USSD string data object support in Call Control by USIM */
    | 0x80  /* Call Control by NAA */
    ,

    0x00    /* 2nd (Other) */
    | 0x01  /* Command result */
    | 0x02  /* Call Control by NAA */
    | 0x04  /* Call Control by NAA */
    #ifndef __DISABLE_SMS_CONTROLLED_BY_SIM__
    | 0x08  /* MO short message control support */
    #endif
    | 0x10  /* Call Control by NAA */
//  | 0x20  /* UCS2 Entry supported */
//  | 0x40  /* UCS2 Display supported */
//  | 0x80  /* Display Text */
    ,

    0x00    /* 3rd (Proactive UICC) */
//  | 0x01  /* Proactive UICC: DISPLAY TEXT */
//  | 0x02  /* Proactive UICC: GET INKEY */
//  | 0x04  /* Proactive UICC: GET INPUT */
    | 0x08  /* Proactive UICC: MORE TIME */
//  | 0x10  /* Proactive UICC: PLAY TONE */
//  | 0x20  /* Proactive UICC: POLL INTERVAL */
    | 0x40  /* Proactive UICC: POLLING OFF */
    | 0x80  /* Proactive UICC: REFRESH */
    ,

    0x00    /* 4th (Proactive UICC) */
//  | 0x01  /* Proactive UICC: SELECT ITEM */
    | 0x02  /* Proactive UICC: SEND SHORT MESSAGE with 3GPP-SMS-TPDU */
    | 0x04  /* Proactive UICC: SEND SS */
    | 0x08  /* Proactive UICC: SEND USSD */
//  | 0x10  /* Proactive UICC: SET UP CALL */
//  | 0x20  /* Proactive UICC: SET UP MENU */
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x40  /* Proactive UICC: PROVIDE LOCAL INFORMATION (MCC, MNC, LAC, Cell ID & IMEI) */
    #endif
    | 0x80  /* Proactive UICC: PROVIDE LOCAL INFORMATION (NMR) */
    ,

    0x00    /*5th (Event driven information) */
    | 0x01  /* Proactive UICC: SET UP EVENT LIST */
    #ifndef __SAT_LOWCOST_NW_DISABLE__
    | 0x02  /* Event: MT call */
    | 0x04  /* Event: Call connected */
    | 0x08  /* Event: Call disconnected */
    | 0x10  /* Event: Location status */
    #endif
//  | 0x20  /* Event: User activity */
//  | 0x40  /* Event: Idle screen available */
//  | 0x80  /* Event: Card reader status */
    ,

    0x00    /* 6th (Event driven information extensions) */
//  | 0x01  /* Event: Language selection */
    #if defined(__SATCC__)
    | 0x02  /* Event: Browser Termination */
    #endif
    #if defined(__SATCE__)
    | 0x04  /* Event: Data available */
    | 0x08  /* Event: Channel status */
    #endif
    | 0x10  /* Event: Access Technology Change */
//  | 0x20  /* Event: Display parameters changed */
//  | 0x40  /* Event: Local Connection */
    | 0x80  /* Event: Network Search Mode Change */
    ,

    0x00    /* 7th (Multiple card proactive commands) for class "a" */
//  | 0x01  /* Proactive UICC: POWER ON CARD */
//  | 0x02  /* Proactive UICC: POWER OFF CARD */
//  | 0x04  /* Proactive UICC: PERFORM CARD APDU */
//  | 0x08  /* Proactive UICC: GET READER STATUS (Card reader status) */
//  | 0x10  /* Proactive UICC: GET READER STATUS (Card reader identifier) */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 8th (Proactive UICC) */
    | 0x01  /* Proactive UICC: TIMER MANAGEMENT (start, stop) */
    | 0x02  /* Proactive UICC: TIMER MANAGEMENT (get current value) */
    | 0x04  /* Proactive UICC: PROVIDE LOCAL INFORMATION (date, time and time zone) */
//  | 0x08  /* GET INKEY */
//  | 0x10  /* SET UP IDLE MODE TEXT */
    #ifdef __SATCB__
    | 0x20  /* RUN AT COMMAND */
    #endif
//  | 0x40  /* SETUP CALL */
    | 0x80  /* Call Control by NAA */
    ,

    0x00    /* 9th */
//  | 0x01  /* DISPLAY TEXT */
    | 0x02  /* SEND DTMF command */
    | 0x04  /* Proactive UICC: PROVIDE LOCAL INFORMATION (NMR) */
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x08  /* Proactive UICC: PROVIDE LOCAL INFORMATION (language) */
    #endif
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x10  /* Proactive UICC: PROVIDE LOCAL INFORMATION, Timing Advance */
    #endif
//  | 0x20  /* Proactive UICC: LANGUAGE NOTIFICATION */
    #if defined(__SATCC__)
    | 0x40  /* Proactive UICC: LAUNCH BROWSER */
    #endif
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x80  /* Proactive UICC: PROVIDE LOCAL INFORMATION (Access Technology) */
    #endif
    ,

    0x00    /* 10th (Soft keys support) for class "d" */
//  | 0x01  /* Soft keys support for SELECT ITEM */
//  | 0x02  /* Soft Keys support for SET UP MENU */
//  | 0x04  /* RFU, bit = 0 */
//  | 0x08  /* RFU, bit = 0 */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 11th (Soft keys information) */
//  | 0x01  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x02  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x04  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x08  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x10  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x20  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x40  /* Maximum number of soft keys available 'FF' value is reserved for future use */
//  | 0x80  /* Maximum number of soft keys available 'FF' value is reserved for future use */
    ,

    0x00    /* 12th (Bearer Independent protocol proactive commands, class "e") */
    #ifdef __SATCE__
    | 0x01  /* Proactive UICC: OPEN CHANNEL */
    | 0x02  /* Proactive UICC: CLOSE CHANNEL */
    | 0x04  /* Proactive UICC: RECEIVE DATA */
    | 0x08  /* Proactive UICC: SEND DATA */
    | 0x10  /* Proactive UICC: GET CHANNEL STATUS */
    #endif
//  | 0x20  /* Proactive UICC: SERVICE SEARCH */
//  | 0x40  /* Proactive UICC: GET SERVICE INFORMATION */
//  | 0x80  /* Proactive UICC: DECLARE SERVICE */
    ,

    0x00    /* 13th (Bearer Independent protocol supported bearers, class "e") */
    #ifdef __SATCE__
    #if defined(CSD_SUPPORT)
    | 0x01  /* CSD */
    #endif
    | 0x02  /* GPRS */
    #endif
//  | 0x04  /* Bluetooth */
//  | 0x08  /* IrDA */
//  | 0x10  /* RS232 */
    #ifdef __SATCE__
    | 0x20  /* Number of channels supported by terminal */
    | 0x40  /* Number of channels supported by terminal */
    | 0x80  /* Number of channels supported by terminal */
    #endif
    ,

    0x00    /* 14th (Screen height) */
//  | 0x01  /* Number of characters supported down the terminal display */
//  | 0x02  /* Number of characters supported down the terminal display */
//  | 0x04  /* Number of characters supported down the terminal display */
//  | 0x08  /* Number of characters supported down the terminal display */
//  | 0x10  /* Number of characters supported down the terminal display */
    | 0x20  /* No display capability */
    | 0x40  /* No keypad available */
//  | 0x80  /* Screen Sizing Parameters supported */
    ,

    0x00    /* 15th (Screen width) */
//  | 0x01  /* Number of characters supported across the terminal display */
//  | 0x02  /* Number of characters supported across the terminal display */
//  | 0x04  /* Number of characters supported across the terminal display */
//  | 0x08  /* Number of characters supported across the terminal display */
//  | 0x10  /* Number of characters supported across the terminal display */
//  | 0x20  /* Number of characters supported across the terminal display */
//  | 0x40  /* Number of characters supported across the terminal display */
//  | 0x80  /* Variable size fonts */
    ,

    0x00    /* 16th (Screen effects) */
//  | 0x01  /* Display can be resized */
//  | 0x02  /* Text Wrapping supported */
//  | 0x04  /* Text Scrolling supported */
//  | 0x08  /* Text Attributes supported*/
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* Width reduction when in a menu */
//  | 0x40  /* Width reduction when in a menu */
//  | 0x80  /* Width reduction when in a menu */
    ,

    0x00    /* 17th (Bearer independent protocol supported transport interface/bearers, class "e") */
    #ifdef __SATCE__
    | 0x01  /* TCP, UICC in client mode, remote connection */
    | 0x02  /* UDP, UICC in client mode, remote connection */
    | 0x04  /* TCP, UICC in server mode */
    #endif
//  | 0x08  /* TCP, UICC in client mode, local connection*/
//  | 0x10  /* UDP, UICC in client mode, local connection*/
//  | 0x20  /* Direct communication channel */
    #ifdef __LTE_RAT__
    | 0x40  /* E-UTRAN */
    #endif
    | 0x80  /* HSDPA */
    ,

    0x00    /* 18th */ /* MAUI_02883701 GET INKEY HELP */
//  | 0x01  /* Proactive UICC: DISPLAY TEXT (Variable Time out) */
//  | 0x02  /* Proactive UICC: GET INKEY (help is supported while waiting for immediate response or variable timeout) */
//  | 0x04  /* USB (Bearer Independent protocol supported bearers,class "e") */
//  | 0x08  /* Proactive UICC: GET INKEY (Variable Timeout) */
//  | 0x10  /* Proactive UICC: PROVIDE LOCAL INFORMATION (ESN) */
//  | 0x20  /* Call control on GPRS */
    | 0x40  /* Proactive UICC: PROVIDE LOCAL INFORMATION (IMEISV) */
    | 0x80  /* Proactive UICC: PROVIDE LOCAL INFORMATION (Search Mode change) */
#if defined(__REL7__) || defined(__SATCL__) || defined(__SATCM__) || defined(__SATCR__)
    ,

    0x00   /* 19th reserved for TIA/EIA-136-C facilities */
//  | 0x01  /* Reserved by TIA/EIA-136, bit = 0 */
//  | 0x02  /* Reserved by TIA/EIA-136, bit = 0 */
//  | 0x04  /* Reserved by TIA/EIA-136, bit = 0 */
//  | 0x08  /* Reserved by TIA/EIA-136, bit = 0 */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 20th (reserved for 3GPP2 C.S0035-B CCAT) */
//  | 0x01  /* Reserved by CCAT, bit = 0 */
//  | 0x02  /* Reserved by CCAT, bit = 0 */
//  | 0x04  /* Reserved by CCAT, bit = 0 */
//  | 0x08  /* Reserved by CCAT, bit = 0 */
//  | 0x10  /* Reserved by CCAT, bit = 0 */
//  | 0x20  /* Reserved by CCAT, bit = 0 */
//  | 0x40  /* Reserved by CCAT, bit = 0 */
//  | 0x80  /* Reserved by CCAT, bit = 0 */
    ,

    0x00    /* 21th (Extended Launch Browser Capability) for class "ac" */
//  | 0x01  /* WML */
//  | 0x02  /* XHTML */
//  | 0x04  /* HTML */
//  | 0x08  /* CHTML */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 22th */
//  | 0x01  /* Support of UTRAN PS with extended parameters */
//  | 0x02  /* Proactive UICC: PROVIDE LOCAL INFORMATION(battery state) */
//  | 0x04  /* Proactive UICC: PLAY TONE (Melody tones and Themed tones supported) */
//  | 0x08  /* Multi-media Calls in SET UP CALL */
//  | 0x10  /* Toolkit-initiated GBA */
//  | 0x20  /* Proactive UICC: RETRIEVE MULTIMEDIA MESSAGE */
//  | 0x40  /* Proactive UICC: SUBMIT MULTIMEDIA MESSAGE */
//  | 0x80  /* Proactive UICC: DISPLAY MULTIMEDIA MESSAGE */
    ,

    0x00   /* 23th */
//  | 0x01  /* Proactive UICC: SET FRAMES */
//  | 0x02  /* Proactive UICC: GET FRAMES STATUS */
//  | 0x04  /* MMS notification download */
//  | 0x08  /* Alpha Identifier in REFRESH command supported by terminal */
//  | 0x10  /* Geographical Location Reporting*/
//  | 0x20  /* Proactive UICC: PROVIDE LOCAL INFORMATION (MEID) */
    | 0x40  /* Proactive UICC: PROVIDE LOCAL INFORMATION (NMR(UTRAN/E-UTRAN)) */
//  | 0x80  /* USSD Data download and application mode */
    ,

    0x00    /* 24th for class "i" */
//  | 0x01  /* Maximum number of frames supported (including frames created in existing frames) */
//  | 0x02  /* Maximum number of frames supported (including frames created in existing frames) */
//  | 0x04  /* Maximum number of frames supported (including frames created in existing frames) */
//  | 0x08  /* Maximum number of frames supported (including frames created in existing frames) */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 25th (Event driven information extensions) */
    | 0x01  /* Event browsing status */
//  | 0x02  /* Event: MMS Transfer status */
//  | 0x04  /* Event: Frame Information changed */
//  | 0x08  /* Event: I-WLAN Access status*/
    | 0x10  /* Event Network Rejection */ 
#if defined(__SATCM__)
    | 0x20  /* Event: HCI connectivity event (if class "m" is supported) */
#endif
#ifdef __LTE_RAT__
    | 0x40  /* E-UTRAN support in Event Network Rejection */
#endif
//  | 0x80  /* Multiple access technologies supported in Event Access Technology Change and PROVIDE LOCAL INFORMATION */
    ,

    0x00    /* 26th (Event driven information extensions) */
//  | 0x01  /* Event : CSG Cell Selection */
#if defined(__SATCR__)
    | 0x02 /* Event: Contactless state request */
#endif
//  | 0x04  /* RFU, bit = 0 */
//  | 0x08  /* RFU, bit = 0 */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 27th (Event driven information extensions) */
//  | 0x01  /* RFU, bit = 0 */
//  | 0x02  /* RFU, bit = 0 */
//  | 0x04  /* RFU, bit = 0 */
//  | 0x08  /* RFU, bit = 0 */
//  | 0x10  /* RFU, bit = 0 */
//  | 0x20  /* RFU, bit = 0 */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 28th (Text attributes) */
//  | 0x01  /* Alignment left supported by Terminal */
//  | 0x02  /* Alignment centre supported by Terminal */
//  | 0x04  /* Alignment right supported by Terminal */
//  | 0x08  /* Font size normal supported by Terminal */
//  | 0x10  /* Font size large supported by Terminal */
//  | 0x20  /* Font size small supported by Terminal */
//  | 0x40  /* RFU, bit = 0 */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 29th (Text attributes) */
//  | 0x01  /* Style normal supported by Terminal */
//  | 0x02  /* Style bold supported by Terminal */
//  | 0x04  /* Style italic supported by Terminal */
//  | 0x08  /* Style underlined supported by Terminal */
//  | 0x10  /* Style strikethrough supported by Terminal */
//  | 0x20  /* Style text foreground colour supported by Terminal */
//  | 0x40  /* Style text background colour supported by Terminal */
//  | 0x80  /* RFU, bit = 0 */
    ,

    0x00    /* 30th */
//  | 0x01  /* I-WLAN bearer support */
//  | 0x02  /* Proactive UICC: PROVIDE LOCAL INFORMATION (WSID of the current I-WLAN connection) */
//  | 0x04  /* TERMINAL APPLICATIONS */
#if defined(__REL7__)
    | 0x08  /* Steering of Roaming" REFRESH support */
#endif
#if defined(__SATCL__)
    | 0x10  /* Proactive UICC: ACTIVATE (i.e class "l" is supported) */
#endif
//  | 0x20  /* Proactive UICC: GEOGRAPHICAL LOCATION REQUEST */
//  | 0x40  /* Proactive UICC: PROVIDE LOCAL INFORMATION(Broadcast Network Information) */
//  | 0x80  /* Steering of Roaming for I-WLAN REFRESH support */
    ,

    0x00    /* 31th */
#if defined(__SATCR__)
    | 0x01  /* Proactive UICC: Contactless State Changed */
#endif
//  | 0x02  /* Support of CSG cell discovery */
//  | 0x04  /* Confirmation parameters supported for OPEN CHANNEL in Terminal Server Mode */
//  | 0x08  /* Communication Control for IMS */
//  | 0x10  /* Support of CAT over the modem interface */
//  | 0x20  /* Support for Incoming IMS Data event */
//  | 0x40  /* Support for IMS Registration event */
//  | 0x80  /* Proactive UICC: Profile Container, Envelope Container, COMMAND CONTAINER and ENCAPSULATED SESSION CONTROL */
    ,

    0x00    /* 32th */
//  | 0x01  /* Support of IMS as a bearer for BIP */
//  | 0x02  /* Support of PROVIDE LOCATION INFORMATION, H(e)NB IP address */
//  | 0x04  /* Support of PROVIDE LOCATION INFORMATION, H(e)NB surrounding macrocells */
//  | 0x08  /* Launch parameters supported for OPEN CHANNEL in Terminal Server Mode */
//  | 0x10  /* Direct communication channel supported for OPEN CHANNEL in Terminal Server Mode */
//  | 0x20  /* Proactive UICC: Security for Profile Container, Envelope Container, COMMAND CONTAINER and ENCAPSULATED SESSION CONTROL */
//  | 0x40  /* CAT service list for eCAT client */
//  | 0x80  /* Support of refresh enforcement policy */
#endif
#ifdef __TC01__
    ,
    
    0x00    /* 33th */
//  | 0x01  /* Support of DNS server address request for OPEN CHANNEL related to packet data service bearer */
//  | 0x02  /* Support of Network Access Name reuse indication for CLOSE CHANNEL related to packet data service bearer */
//  | 0x04  /* Event: Poll Interval Negotiation */
//  | 0x08  /* ProSe usage information reporting */
//  | 0x10  /* ProSe usage information reporting */
//  | 0x20  /* ProSe usage information reporting */
//  | 0x40  /* ProSe usage information reporting */
//  | 0x80  /* ProSe usage information reporting */
//  ,
#endif
};

/* AT&T V5.6 [MAUI_02356244] make EF_Terminal_support_table customized */
 const kal_uint8 terminal_support_table[9] = 
{
    0x01, /* Byte1: scan control application */

    0x01, /* Byte2: network selection menu control application */

    0x01, /* Byte3: acting HPLMN feature */

#ifdef __UMTS_RAT__
    0x01, /* Byte4: 3G Access */
#else
    0x00, 
#endif

    0x00, /* Byte5: RAT Balancing is Not supported. set as 0x00 */
    
    0x00, /* Byte6: According to the AT&T spec. V5.6, we should always set this byte to 0 even if we support BIP*/

#ifdef __LTE_RAT__
    #if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
        #ifdef __VOLTE_SUPPORT__
            0x03, /* Byte7: If LTE Data and Voice using IMS and CSFB then set 0x03 */
        #else
            0x02, /* If LTE Data and Voice using CSFB only then set 0x02 */
        #endif
    #else
        0x01,     /* If LTE Data only then set value 0x01 */
    #endif
#else
    0x00,
#endif

#ifdef __CSG_SUPPORT__
#if defined(__LTE_RAT__)
    0x01, /* Byte8: 3G CSG functionality */
    0x01  /* Byte9: 4G CSG functionality */
#else
    0x01, /* Byte8: 3G CSG functionality */  
    0x00  /* Byte9: 4G CSG functionality */
#endif
#else
    0x00, /* Byte8: 3G CSG functionality */ 
    0x00  /* Byte9: 4G CSG functionality */
#endif
};

static kal_uint8 sat_startup_config = 0;  // Default setting (SAT auto start)

#if defined (__SAT_ADDITIONAL_LOCK__) || defined(__CMCC_V4__) || defined(__YUENAN_V4__)
STCHE che_str_mh;
extern void che_init(STCHE *che_context, kal_uint32 type);
extern void che_deinit(STCHE *che_context);
#endif
 
#if defined(__CMCC_V4__) || defined(__YUENAN_V4__) || defined(__SAT_ADDITIONAL_LOCK__)
 /*Che encrypt process*/
void custom_sat_me_encrypt(kal_uint8 *rand, kal_uint8 rand_len, kal_uint8 *key, kal_uint8 key_len, kal_uint8 *code)
{
     kal_bool che_result = KAL_FALSE;
     kal_uint8 i;

     che_init(&che_str_mh, CHE_3DES);
     che_key_action(&che_str_mh, CHE_SET_KEY, key, key_len);
     che_result = che_process(&che_str_mh, CHE_3DES, CHE_ECB, CHE_ENC, rand, code, rand_len, KAL_TRUE);
     che_deinit(&che_str_mh);

     kal_prompt_trace(MOD_SIM, "che_result = %d,rand_len = %d", che_result,rand_len);
     
     for (i = 0; i < rand_len/16; i++)
     {
         kal_trace(TRACE_INFO,
                   INFO_SIM_ENCYPTED_CODE,
                   i,
                   code[i * 16 + 0],code[i * 16 + 1],code[i * 16 + 2],code[i * 16 + 3],
                   code[i * 16 + 4],code[i * 16 + 5],code[i * 16 + 6],code[i * 16 + 7],
                   code[i * 16 + 8],code[i * 16 + 9],code[i * 16 + 10],code[i * 16 + 11],
                   code[i * 16 + 12],code[i * 16 + 13],code[i * 16 + 14],code[i * 16 + 15]);
     }

}
#endif
#if defined(__CMCC_V4__) || defined(__YUENAN_V4__) 
 /*Decentralization process*/
void custom_sat_v4_decen_process(kal_uint8 *X, kal_uint8 *Km, kal_uint8 *Kc)
{
    kal_uint8 i;
    kal_uint8 Kcl[16];  //8+8 for che_process
    kal_uint8 Kcr[16];  //8+8 for che_process

    kal_prompt_trace(MOD_SIM, "[V4]V4DecenProcess");

    kal_trace(TRACE_INFO,INFO_V4_SIM_X8, X[0],X[1],X[2],X[3],X[4],X[5],X[6],X[7]);
     
    custom_sat_me_encrypt(X, 8, Km, 24, Kcl);

    kal_mem_set(Kc, 0x00, 24);
    kal_mem_cpy(Kc, Kcl, 8);
    kal_mem_cpy(Kc+16, Kcl, 8);

    for(i = 0; i < 8; i++)
    {
        X[i] = ~X[i];
    }

    kal_trace(TRACE_INFO,INFO_V4_SIM_X8, X[0],X[1],X[2],X[3],X[4],X[5],X[6],X[7]);

    custom_sat_me_encrypt(X, 8, Km, 24, Kcr);

    kal_mem_cpy(Kc + 8, Kcr, 8);

    kal_trace(TRACE_INFO,
               INFO_V4_SIM_KC,
               Kc[0], Kc[1],Kc[2], Kc[3],
               Kc[4], Kc[5],Kc[6], Kc[7],
               Kc[8], Kc[9], Kc[10], Kc[11],
               Kc[12], Kc[13], Kc[14], Kc[15],
               Kc[16], Kc[17], Kc[18], Kc[19],
               Kc[20], Kc[21], Kc[22], Kc[23]);


}
#endif
 
#ifdef __SAT_ADDITIONAL_LOCK__
kal_uint8 Factory_CODE = 0x04;

kal_uint8 me_RND[8] = {0};
kal_uint8 sim_RND[8] = {0};
kal_uint8 sim_CODE1[8] = {0};
kal_uint8 me_CODE[8] = {0};
kal_uint8 me_key_group[16][16] = {0};

kal_uint8 update_terminal_profile(void)
{
 
    kal_uint8 i ;

    for (i = 0; i < 8; i ++)
    {
        me_RND[i]=rand();
    }
    sim_profile[MAX_SIM_PROFILE_LEN] = Factory_CODE;
    kal_mem_cpy(&sim_profile[MAX_SIM_PROFILE_LEN+1],&me_RND[0],SAT_ADDITIONAL_TER_PROFILE);
}
void custom_sat_get_key_from_rand(kal_uint8 *rand, kal_uint8 *key)
{
    kal_uint8 i;
    kal_uint8 keyIndex;
    keyIndex = (rand[0]&0xF0) >> 4;
    kal_prompt_trace(MOD_SIM, "[JS]keyIndex=%d, rand[0]= %x", keyIndex, rand[0]);

    memcpy(key, me_key_group[keyIndex], 8);
    memcpy(key + 8, me_key_group[keyIndex]+8, 8);
    memcpy(key + 16, me_key_group[keyIndex], 8);

    kal_trace(TRACE_INFO,
           INFO_JS_SIM_KEY,
           key[0], key[1], key[2], key[3],
           key[4], key[5], key[6], key[7],
           key[8], key[9], key[10], key[11],
           key[12], key[13], key[14], key[15],
       key[16], key[17], key[18], key[19],
       key[20], key[21], key[22], key[23]);      


}
 
kal_bool custom_sat_me_verify_process( )
{
    kal_uint8 me_Key[24];
    kal_uint8 me_Code1[8+8];    //According to che_process, the length of dest should be 8 bytes bigger than sourc_length

    kal_uint8 sim_Key[24];
    kal_uint8 me_Code2[8+8];
    kal_uint8 i;

    memset(me_Key, 0x00, 24);
    memset(me_Code1, 0x00, 16);
    memset(sim_Key, 0x00, 24);
    memset(me_Code2, 0x00, 16);

    custom_sat_get_key_from_rand(me_RND, me_Key);       
    custom_sat_me_encrypt(me_RND, 8, me_Key, 24, me_Code1);

    if (!kal_mem_cmp(me_Code1, sim_CODE1, 8))
    {
         kal_prompt_trace(MOD_SIM, "[JS]Forward_veri_success");
         custom_sat_get_key_from_rand(sim_RND, sim_Key);
         custom_sat_me_encrypt(sim_RND, 8, sim_Key, 24, me_Code2);
         kal_mem_cpy(me_CODE,me_Code2,8);
         
         return KAL_TRUE;
    }
    else
    {
         kal_prompt_trace(MOD_SIM, "[JS]Foward_vefi_fail");

         return KAL_FALSE;
    }
}
kal_bool  custom_sat_additional_lock_switch()
{
    return KAL_TRUE;
}
#endif
#ifdef __CMCC_V4__
  /*You should change vendor_code, key_ver and des_key_group to the right one related with your encryption card*/
kal_uint8 sim_RND[20] = {0};
kal_uint8 cm[24] = {0};
const kal_uint8 vendor_code = 0x02;
const kal_uint8 key_ver = 0x01;
const kal_uint8 des_key_group[5][16]=
{
    {0xC9,0x4E,0x13,0x6B,0xAB,0xE9,0xD0,0xEF,0x2F,0x6C,0x27,0xB1,0x22,0x96,0x37,0x76},
    {0xEC,0x06,0x52,0x7E,0x58,0x8B,0xC4,0xB0,0x59,0xD0,0x83,0xDF,0x4C,0x47,0x1C,0xFD},
    {0x59,0x4F,0xBC,0x28,0xCB,0xA8,0xB8,0x02,0x24,0xA3,0x08,0xE3,0x24,0x16,0x91,0xDA},
    {0x8F,0x7F,0xB1,0x34,0xF7,0x61,0xB7,0xEA,0xFD,0x7E,0x37,0xBB,0x8E,0x00,0xC3,0x3F},
    {0xEA,0x0D,0x04,0x8C,0xB5,0xA2,0xD9,0xBD,0x10,0xB7,0xD0,0xF2,0x5F,0x37,0xC7,0x8F}
};
kal_bool  custom_sat_cmcc_v4_lock_switch()
{
    return KAL_TRUE;
}
 
 /*Get Km form RND1*/
void custom_sat_v4_get_km_from_rand(kal_uint8 *rand, kal_uint8 *Km)
{
    kal_uint8 i;
    kal_uint8 key_index;

    key_index = (rand[3] & 0X07) % 5;
    kal_prompt_trace(MOD_SIM, "[CMCCV4]key_index=%d", key_index);   

    kal_mem_set(Km, 0x00, 24);
    kal_mem_cpy(Km, des_key_group[key_index], 16);
    kal_mem_cpy(Km+16, des_key_group[key_index], 8);    //for 3DES algthm, we should transform key to ABA style

    kal_trace(TRACE_INFO,
           INFO_V4_SIM_KM,
           Km[0], Km[1], Km[2], Km[3],
           Km[4], Km[5], Km[6], Km[7],
           Km[8], Km[9], Km[10], Km[11],
           Km[12], Km[13], Km[14], Km[15],
           Km[16], Km[17], Km[18], Km[19],
           Km[20], Km[21], Km[22], Km[23]);

}
 /*Main encode flow*/
void custom_sat_cmcc_v4_key_encode(kal_uint8 *sim_iccid )
{
    kal_uint8 RND1[4];
    kal_uint8 RND2[16];
    kal_uint8 Km[24];
    kal_uint8 Kc[24];
    kal_uint8 Kc_temp[24];
    kal_uint8 X[8];
    kal_uint8 i;

    kal_prompt_trace(MOD_SIM, "[CMCCV4]V4KeyEncode");

    kal_mem_set(RND1, 0x00, sizeof(RND1));
    kal_mem_cpy(RND1, &sim_RND[0], 4);

    kal_mem_set(RND2, 0x00, sizeof(RND2));
    kal_mem_cpy(RND2, &sim_RND[4], 16);
     
    /*Get Km with RND1 through spec*/
    custom_sat_v4_get_km_from_rand(RND1, Km);

    /*level-1 decentralization*/
    kal_mem_set(X, 0x20, 8);            //Through spec, if the length of X is less than 8 byte, we should pad with 0x20
    kal_mem_cpy(X, &sim_iccid[2], 8);
    kal_mem_set(Kc_temp,0x00,24);
    custom_sat_v4_decen_process(X, Km, Kc_temp);

    /*level-2 decentralization*/
    kal_mem_set(X, 0x20, 8);
    kal_mem_cpy(X, &RND1[0], 4);
    custom_sat_v4_decen_process(X, Kc_temp, Kc);

    kal_mem_set(cm, 0x00, 24); 
    custom_sat_me_encrypt(RND2, 16, Kc, 24, cm);

}
 
 /*Terminal response to sim after encoding*/
 
#endif

#ifdef __YUENAN_V4__
kal_uint8 sim_RND[16] = {0};
kal_uint8 cm[24] = {0};
const kal_uint8 vendor_code = 0x09;
const kal_uint8 key_ver = 0x01;
const kal_uint8 des_key_group[16]=
{
   0x52,0x09,0x1F,0x76,0x2E,0x65,0x22,0xDF,   
   0xD3,0xFE,0xE6,0x3D,0x6A,0xBA,0x2C,0x88,
};
 
const kal_uint8 defaultText[24]=        //UCS2 "VNPHONE RAND"
{0x00,0x56,0x00,0x4e,0x00,0x50,0x00,0x48,
 0x00,0x4f,0x00,0x4e,0x00,0x45,0x00,0x20,
 0x00,0x52,0x00,0x41,0x00,0x4e,0x00,0x44
};
kal_bool custom_sat_yuenan_v4_lock_switch()
{
    return KAL_FALSE;
}
 
void custom_sat_yuenan_v4_key_encode(kal_uint8 *sim_iccid)
{
    kal_uint8 Km[24];
    kal_uint8 X[8];
    kal_uint8 Kc[24];

    kal_mem_set(Km, 0x00, 24);
    kal_mem_cpy(Km, des_key_group, 16);
    kal_mem_cpy(Km+16, des_key_group, 8);    //for 3DES algthm, we should transform key to ABA style

    kal_mem_set(X, 0x20, 8);         //Through spec, if the length of X is less than 8 byte, we should pad with 0x20
    kal_mem_cpy(X, sim_iccid+2, 8);

    custom_sat_v4_decen_process(X, Km, Kc);

    kal_mem_set(cm, 0x00, 24); 
    custom_sat_me_encrypt(sim_RND, 16, Kc, 24, cm);
}
#endif
 /*****************************************************************************
 * FUNCTION
 *  sim_ens_terminal_support_flag
 * DESCRIPTION
 *  make EF_Terminal_support_table customized
 * PARAMETERS
 *  pProfile        [?]     
 * RETURNS
 *  void
 * GLOBALS AFFECTED
 *  void
 *****************************************************************************/
void sim_ens_terminal_support_flag(kal_uint8 *table_ptr, kal_uint8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    if (NULL != table_ptr)
    {    
        if(len > sizeof(terminal_support_table))
        {
            kal_sys_trace("Exceed terminal_support_table size");
            len = sizeof(terminal_support_table);
        }
        
        kal_mem_cpy(table_ptr, terminal_support_table, len);
    }

    if (sbp_query_md_feature(SBP_ENS_RAT_BALANCING) == KAL_TRUE)
    {
        table_ptr[3] = 0x01;
        table_ptr[4] = 0x01;
    }

}


 /*****************************************************************************
 * FUNCTION
 *  custom_sim_reset_method
 * DESCRIPTION
 *  Determine the SIM card reset method to detch the card is USIM or SIM.
 *      SIM_RESET_SMART_DETECTION : judge the card is USIM or SIM according to the spec.
 *      SIM_RESET_USIM_PREFER : always try USIM first. Try SIM if trying USIM failed.
 *      SIM_RESET_SIM_PREFER : always try SIM first. Try USIM if trying SIM failed.
 * PARAMETERS
 *  none
 * RETURNS
 *  sim_reset_method_enum
 *****************************************************************************/
sim_reset_method_enum custom_sim_reset_method(void) //mtk02514_reset
{
	if(KAL_TRUE == gmss_is_tdscdma_mode_activated())
	{
		return SIM_RESET_USIM_PREFER;
	}
	else
	{
		return SIM_RESET_SMART_DETECTION;
	}   
}

 /*****************************************************************************
 * FUNCTION
 *  custom_sat_provide_cell_in_sim
 * DESCRIPTION
 *  Let PROVIDE LOCAL INFORMATION - location stauts
 *   return cell ID instead of E-Cell ID when using SIM
 * PARAMETERS
 *  none
 * RETURNS
 *  KAL_FALSE or KAL_TRUE
 * NOTE:
 *      Based on SAT spec 102.221 or 51.014, we should NOT provide eCell ID in SIM.
 *      Only USAT should carry eCell ID in LOCATION INFO field in USIM
 *****************************************************************************/
kal_bool custom_sat_provide_cell_in_sim(void)
{
#if 1
    return KAL_TRUE;
#else
    #ifdef __SAT_PROVIDE_CELL_IN_SIM__
/* under construction !*/
    #else
/* under construction !*/
    #endif
#endif    
}

void custom_sat_set_startup_config(kal_uint8 setting)
{
    sat_startup_config = setting;
}

/*****************************************************************************
* FUNCTION
*  custom_sat_startup_config
* DESCRIPTION
*  If USAT is halt due to at+cusatd=1, this function can control the USAT start timing.
*  USAT can either start normally and sends BUSY for TE commands while TE is still not ready,
*                      or start after TE notify it's ready by AT+CUSATA=1.
*   
* PARAMETERS
*  none
* RETURNS
*  KAL_FALSE or KAL_TRUE
*****************************************************************************/
kal_uint8 custom_sat_startup_config(void)
{
    /*
        *   0: default setting (SAT auto startup)
        *   1: enable SAT only triggered by AT+STKPCI
        *   2: default setting but enable SAT by AT+CUSATA=1 while in AT+CUSATD=1
        */
    return sat_startup_config;
}


/***************************************************************************** 
* The determination of Test SIM has two ways:
* CondA is MCC/MNC = 001/01,  CondB is EF_AD's ms_operation 0x80, 0x81, 0x02, 0x04
*       
*      If (CondA || CondB), then return 0
*      If (CondA && CondB), then return 1
* 
*      The default value returns 0
 *****************************************************************************/
kal_uint8 test_SIM_relation(void)
{
    /* [MAUI_03181345] mtk81143: set test sim relation default OR for TD project*/

    kal_sys_trace("TestSIM_OR");
    return 0;

/*
    kal_sys_trace("TestSIM_AND");
    return 1;
*/
}

#ifdef __SIM_RECOVERY_ENHANCEMENT__
/***************************************************************************
* This function configs how many times fast sim recovery trial could be performed
* before MMI notify user that SIM card is lost.
***************************************************************************/
kal_uint8 custom_num_fast_recovery(void)
{
    return 3;
}

/***************************************************************************
* After user is notifed SIM lost, ME will try to recover the SIM card at frequent intervals.
* This function configs the time interval for each recovery trial.
***************************************************************************/
kal_uint8 custom_recovery_time_interval(void)
{
    return 30;
    // The time unit is second.
    // 30: the time interval for a SIM recovery trial is 30 seconds.
}

/***************************************************************************
* After user is notifed SIM lost, ME will try to recover the SIM card at frequent intervals.
* This function configs the maximum count of recovery trial.
***************************************************************************/
kal_uint16 custom_max_recovery_count(void)
{
    return 0xFFFF;
    // 0: no recovery trial after MMI is notified SIM lost.
    // 100: there will be at most 100 recovery tial after MMI is notified SIM lost.
    // 0xFFFF: there is no limit of SIM recovery trial.
}

/***************************************************************************
* After user is notifed SIM ACCESS ERROR(card existed but detect fail), 
* ME will try to recover the SIM card at frequent intervals.
* This function configs the function is enabled or disalbed.
***************************************************************************/
kal_uint8 custom_retry_sim_when_card_detect_fail()
{
#ifdef __RETRY_SIM_WHEN_CARD_DETECT_FAIL__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}

#if defined(__RETRY_SIM_WHEN_CARD_DETECT_FAIL__) && defined(__RETRY_SIM_DETECT_CUSTOM_SUPPORT__)
/* ************************************************************************* 
*ME will try to recover the card in frequent intervals as given by the function
***************************************************************************/
kal_uint16 custom_max_retry_detect_card_count(void)
{
    return 0xFFFF;
}

/**************************************************************************
*This function configures the time interval for each card retry detect trial
**************************************************************************/
kal_uint8 custom_retry_detect_card_time_interval(void)
{
    return 30;
}
#endif

/**************************************************************************
*This function configs the maximum count of recovery trial when sim is not detected during bootup
**************************************************************************/
kal_uint8 custom_max_recovery_count_when_no_sim(void)
{
    #ifdef __SIM_RETRY_WHEN_CARD_DETECT_FAIL_DURING_BOOTUP__
        return 20;
	#else
	    return custom_max_recovery_count();
	#endif
}
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __UMTS_TDD128_MODE__ /*based on [ALPS00383584]*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  custom_select_aid_by_default()
 * DESCRIPTION
 *  Determine to set p2 value when select aid in +CCHO
 *      KAL_TRUE: (default) set p2 to 0x0C then 0x00 
 *      KAL_FALSE : set p2 to 0x00 then 0x0c
 * PARAMETERS
 *  none
 * RETURNS
 *  KAL_FALSE or KAL_TRUE
 *****************************************************************************/
kal_bool custom_select_aid_by_default(void)
{
#ifdef __SELECT_AID_CUSTOMIZE__
    return KAL_FALSE;
#else
    return KAL_TRUE;
#endif /* __SELECT_AID_CUSTOMIZE__ */
}


/*  UICC driver need to know the 'le' field in APDU before processing the APDU command. 
  *  For proprietary UICC command, please parse the 'le' value in this function.
  *  If le is present : value shall be 0~256 at most                                                             
  *  if le is not present : rx_data_size set to 0                                                                   */
/*MOLY00003203 AT+CGLA extension support for customized INS for NFC, by mtk81143*/
kal_bool custom_apdu_cmd_le( kal_uint8 *tx_data,kal_uint16 *tx_data_size, kal_uint32 *rx_data_size)
{
	kal_bool  result = KAL_TRUE;
	*rx_data_size = 0;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
    return result;
}

#ifdef __SIM_HOT_SWAP_POLL_TIMER__
kal_uint8 custom_hot_swap_poll_time_interval(void)
{
    return 2;
    // The time unit is second.
    // 2: the time interval for a SIM hotswap to temporarily change the polling time to 2 seconds.
}
#endif

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_terminal_capability_power_supply
 * DESCRIPTION
 *  This function is used to indicate that terminal needs more power
 *  than the minmum power supply.
 * PARAMETERS
 *  actual_voltage_class        [IN]
 *  power_data                    [OUT]
 *      power_data[0] :  Actual used Supply voltage class
 *      power_data[1] :  Maximum available power supply of the terminal
 *      power_data[2] :  Actual used clock frequency
 * RETURNS
 *  KAL_FALSE or KAL_TRUE : need this TLV or not
 *****************************************************************************/
kal_bool custom_sim_terminal_capability_power_supply(kal_uint8 *power_supply_data)
{

    power_supply_data[1] = 0x0A;
    power_supply_data[2] = 0x0A;

    /*
    * Please don't switch this return to KAL_TRUE, 
    * if you have requirement about this item, please contact with SIM owner
    */

    return KAL_FALSE;
}

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_extended_logical_channel_support
 * DESCRIPTION
 *  This function is used to indicate that terminal support extended logical channel or not
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE : need this TLV or not
 *****************************************************************************/
kal_bool custom_sim_extended_logical_channel_support(void)
{
    return KAL_TRUE;
}

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_addition_interfaces_support
 * DESCRIPTION
 *  This function is used to indicate that terminal support additional interfaces
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE : need this TLV or not
 *****************************************************************************/
kal_bool custom_sim_addition_interfaces_support(kal_uint8 *interfaces)
{
    interfaces[0] = 0x00;   // UICC-CLF supportted
        
    return KAL_TRUE;
}




/***************************************************************************** 
* Some SIM cards do not follow the rule to invalidate IMSI, and LOCI when FDN/BDN is 
* enabled, to compatible with these type of SIM cards, function shall return KAL_TRUE to 
* bypass invalid check.Tthe default value shall return KAL_TRUE
 *****************************************************************************/
kal_bool bypass_invalid_check(void)
{
    return KAL_TRUE;
}


kal_uint8 custom_sat_additional_lock_switch(void)
{
    return 1; /*
               * 1: turn on
               * 0: turn off
               */
                  
}


kal_bool custom_sat_manual_pin_verify_in_refresh_reset(void)
{
    /*
     * KAL_TURE: User have to do PIN verify while in REFRESH reset.
     * KAL_FALSE: Modem will auto verify the PIN while in REFRESH reset
     */
    return KAL_FALSE;
}

kal_bool custom_sat_clear_loci_rplmn_on_sat_refresh(void)
{
    /*
     * KAL_TURE: clear RPLMN while clearing LOCI files.
     * KAL_FALSE: dont clear RPLMN while clearing LOCI files
     */
    return KAL_FALSE;
}

kal_bool custom_sat_clear_loci_on_sat_refresh(sat_refresh_type_enum refresh_type)
{
    /*
     * KAL_TURE: Clear temporary mobile identities in SIM (EF_LOCI/EF_PSLOCI/EF_EPSLOCI)
     * KAL_FALSE: No effect
     */
    kal_bool result = KAL_FALSE;

    switch (refresh_type)
    {
        case TYPE_NAA_INIT_AND_FULL_FILE_CHANGE:
            result = KAL_FALSE;
            break;

        case TYPE_NAA_INIT:
        case TYPE_NAA_APPLICATION_RESET:
        case TYPE_NAA_SESSION_RESET:
            result = KAL_FALSE;
            break;
            
        case TYPE_NAA_INIT_AND_FILE_CHANGE:
            /* if TRUE, it will bypass IMSI check in file list to clear LOCI
                          SBP_CLEAR_LOCI_WHEN_REFRESH_INIT_FCN should be disabled to bypass IMSI check*/
            result = KAL_FALSE;
            break;

        case TYPE_SIM_RESET:
            /* No Impact, controlled by SBP SBP_CLEAR_LOCI_WHEN_UICC_RESET */
            result = KAL_FALSE;
            break;                            
                                                
        case TYPE_STEERING_OF_ROAMING:
            /* clear loci not supported for this type */
            result = KAL_FALSE;
            break;

        default:
            break;
    }

    return result;
}

kal_bool custom_sat_send_tr_success_for_delayed_refresh_file_change(void)
{
	 /*
	* KAL_TRUE: send TR successful for refresh type: SIM init and File Change
	* KAL_FALSE: send TR fail for refresh type: SIM init and File change
	*/
	 return KAL_FALSE;
}

/*****************************************************************************
* FUNCTION
*  custom_sat_allow_call_ctrl_by_sim
* DESCRIPTION
*  This function is used to allow call control by SIM when SIM error is responsed
*   KAL_TRUE: allow call control by SIM when SIM error
*   KAL_FALSE: not allow
* PARAMETERS
*  N/A
* RETURNS
*  KAL_FALSE or KAL_TRUE
*****************************************************************************/
kal_bool custom_sat_allow_call_ctrl_by_sim(void)
{
    return KAL_TRUE;
}

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_get_first_aid
 * DESCRIPTION
 *  This function is used to make sure the first USIM AID is seleceted
 *   KAL_TRUE: select first USIM AID
 *   KAL_FALSE: select last USIM AID
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE
 *****************************************************************************/
kal_bool custom_sim_get_first_aid(void)
{
    return KAL_TRUE;
}

  /*****************************************************************************
 * FUNCTION
 *  custom_sim_deactive_UICC_presence_detection
 * DESCRIPTION
 *  This function is used to skip the UICC presence detection
 *   KAL_TRUE: skip UICC presence detection
 *   KAL_FALSE: maintain UICC presence detection
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE
 *****************************************************************************/
kal_bool custom_sim_deactive_UICC_presence_detection(void)
{
    return KAL_FALSE;  //should be set to KAL_FALSE in CTA test
}

/*****************************************************************************
 * FUNCTION
 *  custom_sim_retry_read_record
 * DESCRIPTION
 *  This function is used to retry reading record if the sw=0x6984/0x6F00
 *   KAL_TRUE: retry
 *   KAL_FALSE: not retry
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE
 *****************************************************************************/
kal_bool custom_sim_retry_read_record(void)
{	 
#ifdef __RETRY_READ_RECORD_WHEN_ABNORMAL_STATUS__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}

/***************************************************************************** 
*  
*****************************************************************************/
kal_uint8 is_HW_VERIFICATION_enabled(void)
{
    return 0;
    // 0 - disable HW verification
    // 1 - enable for SIM1 only
    // 2 - enable for SIM2 only
}


/***************************************************************************** 
 * According to spec ,when processing SAT PALY TONE proactive command
 * "If no duration is specified, the ME shall default to a duration determined by the ME manufacturer."
 * Customer can define default duration for PLAY TONE command in this function
 * For FTA testcase 27.22.4.5 PLAY TONE SEQ 1.1 Step61, it might need to enlarge the default duration
 * time unit : 1ms
 *****************************************************************************/
kal_uint32 sat_PLAY_TONE_default_duration(void)
{
    return 5000; // 5 sec 
}

/*****************************************************************************
*FUNCTION
* custom_en_auto_TR_handle
*DESCRIPTION
* This function is for customer to handle automatic TR while also sending STKPCI to AP.
* AP should ignore such STKPCI when this function is enabled.
*PARAMETERS
* void
*RETURN 
* TRUE:handle stksms and  auto TR while sending STKPCI to modem.
* FALSE:handle stksms after receiving AT+STKSMS.
*****************************************************************************/
kal_bool custom_en_auto_TR_handle(void)
{
    return KAL_FALSE;
}

#if defined(__SAT_CUSTOM_POLL_TIMER__) //MAUI_02931261
/***************************************************************************** 
 * The feature proposes is to change the status poll interval to a value greater then the one
 * requested by the SIM card, in the case that it is shorter then a pre-defined customized value. 
 * Therefore, if the poll interval time requested by SIM card is less than the customized time value, 
 * then the latter shall be used as the poll interval. 
 * If, instead, the requested poll interval is greater than the flex value, then
 * the time provided in the request command shall be used as the poll interval.
 * The default value return 0 is to disable the feature
 * time unit : TICKS (Please use KAL_TICKS_xxx marco)
 *****************************************************************************/
kal_uint32 sat_custom_poll_timer(void)
{
    //return (KAL_TICKS_30_SEC-KAL_TICKS_1_SEC*3-KAL_TICKS_500_MSEC); //current MTK default value is within 30 seconds (about 26.5 seconds)
    return  (KAL_TICKS_30_SEC + KAL_TICKS_5_SEC +KAL_TICKS_1_SEC); //36 seconds
    //return (KAL_TICKS_1_MIN + KAL_TICKS_3_SEC); // 1 minute and 3 seconds
    //return 0;  //to disable this feature
}
#endif 

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_trigger_refresh_reset
 * DESCRIPTION
 *  This function is used to indicate if fake refresh reset should be triggered after sms pp download
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE : need this feature or not
 *****************************************************************************/
kal_bool custom_sim_trigger_refresh_reset(void)
{
    return KAL_FALSE;
}

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_verify_adm_support
 * DESCRIPTION
 *  This function is used to indicate that terminal support verify ADM or not
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE : need this feature or not
 *****************************************************************************/
kal_bool custom_sim_verify_adm_support(void)
{
    return KAL_FALSE;
}
 
  /*****************************************************************************
  * FUNCTION
  *  custom_sim_block_error_ef
  * DESCRIPTION
  *  This function is used to indicate if ef epsloci read should be blocked for invalid card
  * PARAMETERS
  *  N/A
  * RETURNS
  *  boolean
  *****************************************************************************/
 
 kal_bool custom_sim_block_error_ef(void)
 {
 
     return KAL_FALSE;   
 }

/***************************************************************************** 
 * FUNCTION
 *  custom_acc_class_value
 * DESCRIPTION
 *  This function is used to return custom acc class value
 * PARAMETERS
 *  N/A
 * RETURNS
 *  custom defined acc class value
 *MAINTAIN BY
 *  NAS, AS
 *****************************************************************************/
kal_uint16 custom_acc_class_value(void)
{
    kal_sys_trace("Invalid Acc Class file,and Custom value is Class0");
    return 0x0001;
}
 /*****************************************************************************
 * FUNCTION
 *  custom_sim_default_imsi_length
 * DESCRIPTION
 *  This function is used to indicate whether to take the default length of imsi which is 8 bytes
 * PARAMETERS
 *  N/A
 * RETURNS
 *  boolean
 *****************************************************************************/

kal_bool custom_sim_default_imsi_length(void)
{

		return KAL_FALSE;	
}

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_default_mnc_length
 * DESCRIPTION
 *  This function is used to indicate that default length of MNC (2 or 3)
 * PARAMETERS
 *  N/A
 * RETURNS
 *  2 or 3 : Default MNC Length
 *****************************************************************************/
#define MNC_IDX 3
kal_uint8 custom_sim_default_mnc_length(const kal_char *sim_mcc, const kal_char *sim_mnc)
{

    const kal_char *op_list[] = {/* Countries with 3 digit MNC */
                                 "365FFF", "344FFF", "722FFF", "364FFF", "342FFF", "348FFF", "346FFF",
                                 "732FFF", "366FFF", "750FFF", "352FFF", "708FFF", "338FFF", "334FFF",
                                 "330FFF", "356FFF", "358FFF", "360FFF", "376FFF",
                                 /* Countries with mix(2/3) digit MNC, below list comprises 3 digit MNC PLMNs */
                                 "257501", "338050", "262901", "250811", "50215F",
                                 /* India */
                                 "40502F", "40503F", "40504F", "40575F", "405799", "40580F", "40581F",
                                 "40582F", "405834", "40584F", "40585F", "40586F", "40587F", "40588F",
                                 "40590F", "40591F", "40592F"
                                };

 
    kal_uint8 op_list_count = sizeof(op_list)/sizeof(op_list[0]);
    kal_uint8 index = 0;

    for (index = 0; index < op_list_count; index++)
    {
        if (0 == (strncmp(op_list[index], sim_mcc, 3)))
        {
            if (0 == (strncmp(&op_list[index][MNC_IDX], sim_mnc , 3)))
            {
                return 3;
            }
            else if (0 == (strncmp(&op_list[index][MNC_IDX], "FFF", 3)))
            {
                return 3;
            }
            else if ((0 == (strncmp(&op_list[index][MNC_IDX], sim_mnc, 2)))
                    && (op_list[index][MNC_IDX + 2] == 'F'))
            {
                return 3;
            }
            else if ((0 == (strncmp(&op_list[index][MNC_IDX], sim_mnc, 1)))
                    && (op_list[index][MNC_IDX + 2] == 'F')
                    && (op_list[index][MNC_IDX + 1] == 'F'))
            {
                return 3;
            }
        }
    }

    return 2;
}
 /*****************************************************************************
 * FUNCTION
 *  custom_sim_hardcode_mnc_length
 * DESCRIPTION
 *  This function is used to hardcode mnc length for differnet operators based on mcc-mnc(in case of wrong EF AD value)
 * PARAMETERS
 *  N/A
 * RETURNS
 *  2 or 3 : Default MNC Length
 *****************************************************************************/
 kal_uint8 custom_sim_hardcode_mnc_length(const kal_char *sim_mcc, const kal_char *sim_mnc)
{

    const kal_char *op_list[] = {/* Indian operators with 3 digit MNC */
                                  "405863", "405840", "405861", "405848"
                                };

 
    kal_uint8 op_list_count = sizeof(op_list)/sizeof(op_list[0]);
    kal_uint8 index = 0;

    for (index = 0; index < op_list_count; index++)
    {
        if (0 == (strncmp(op_list[index], sim_mcc, 3)))
        {
            if (0 == (strncmp(&op_list[index][MNC_IDX], sim_mnc , 3)))
            {
                return 3;
            }
            else if (0 == (strncmp(&op_list[index][MNC_IDX], "FFF", 3)))
            {
                return 3;
            }
            else if ((0 == (strncmp(&op_list[index][MNC_IDX], sim_mnc, 2)))
                    && (op_list[index][MNC_IDX + 2] == 'F'))
            {
                return 3;
            }
            else if ((0 == (strncmp(&op_list[index][MNC_IDX], sim_mnc, 1)))
                    && (op_list[index][MNC_IDX + 2] == 'F')
                    && (op_list[index][MNC_IDX + 1] == 'F'))
            {
                return 3;
            }
        }
    }

    return 2;
}

/***************************************************************************** 
* FUNCTION
*  custom_bypass_pin2_puk2_check
*DESCRIPTION
*  This function is used for specific cards which returns error status words on PIN2 status enquiry
*  KAL_TRUE: Bypass PIN2/PUK2 check and continue with SIM init
*  KAL_FALSE: Halt SIM init if erroneous 
*PARAMETERS
* N/A
*RETURNS
* KAL_TRUE or KAL_FALSE
*****************************************************************************/
kal_bool custom_bypass_pin2_puk2_check(kal_uint16 status_words)
{
#ifdef __BYPASS_PIN2_PUK2_CHECK_ISIM_INIT__
    if (0x6B00 == status_words)
    {
        return KAL_TRUE;
    }
    else
#endif
#ifdef __BYPASS_PIN2_PUK2_CHECK__
    if (0x63F0 == (status_words & 0xFFF0))
    {
    	return KAL_TRUE;
    }
    else
#endif
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
* FUNCTION
*  custom_sat_ussd_not_inform_user_when_alpha_id_present
* DESCRIPTION
*  This function is used to turn on/off the feature to display MMI popup when aplha identifier is not
*  provided by the UICC in SEND USSD proactive command.
*  Few SIM cards does not issue DISPLAY TEXT on receiving Terminal response of SEND USSD
*  proactive command and hence user can not know result of USSD operation.
*
*  KAL_TRUE: turn on the feature
*  KAL_FALSE: turn off the faeture
* PARAMETERS
*  N/A
* RETURNS
*  KAL_FALSE or KAL_TRUE
*****************************************************************************/
kal_bool custom_sat_ussd_not_inform_user_when_alpha_id_present(const kal_char *mcc_mnc_str)
{
	if (sbp_query_md_feature(SBP_SAT_USSD_NOT_INFORM_USER) == KAL_TRUE)//always report +CUSD:3
	{
		return KAL_TRUE;
	}
	else
	{
		const kal_char *op_list[] = {
									 "63086","63001","63002","63090","63010","64110","64101","62401",
								     "62402","62404","62001","62002","62003","62007","61205","61203","42402"
									};

	 
		kal_uint8 op_list_count = sizeof(op_list)/sizeof(op_list[0]);
		kal_uint8 index = 0;

		for (index = 0; index < op_list_count; index++)
		{
			if (0 == (strncmp(op_list[index], mcc_mnc_str, 6)))
			{
				return KAL_TRUE;
			}
		}
	}
	
	return KAL_FALSE;
}

/***************************************************************************** 
* Local Function of SMU
*****************************************************************************/

/* Load a new data object */


/*****************************************************************************
 * FUNCTION
 *  smu_load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pobjFromlid     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool smu_load(void *pobjFromlid, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (smu_destory(source))
    {
        kal_sys_trace("SMU: previous obj not free!");
    }

//    nvram_ef_ms_security_obj_g[source].smu_security_info_ptr = get_ctrl_buffer(sizeof(smu_security_info_struct));
//    kal_mem_set((kal_uint8*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr, 0xFF, sizeof(smu_security_info_struct));
    nvram_ef_ms_security_obj_g[source].smu_security_info_ptr = &(smu_security_info_obj[source]);

    kal_mem_cpy(
        (kal_uint8*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr,
        (kal_uint8*) pobjFromlid,
        sizeof(smu_security_info_struct));
    return KAL_TRUE;
}

/* Update a the data object */


/*****************************************************************************
 * FUNCTION
 *  smu_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pobjTolid       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool smu_update(void *pobjTolid, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(nvram_ef_ms_security_obj_g[source].smu_security_info_ptr != NULL);
    kal_mem_cpy(
        (kal_uint8*) pobjTolid,
        (kal_uint8*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr,
        sizeof(smu_security_info_struct));
    return KAL_TRUE;
}

/* Release the data object */


/*****************************************************************************
 * FUNCTION
 *  smu_destory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool smu_destory(kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    return KAL_FALSE;
}

/* Query the value of the item in kal_uint8 */


/*****************************************************************************
 * FUNCTION
 *  smu_query_u8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint8 smu_query_u8(smu_item_enum eItem, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
            return info_ptr->security_indication;
            break;
/*			
        case SMU_AUTO_LOCK_ITEM_U8:
            return info_ptr->auto_lock_item;
            break;
*/
        case SMU_PIN1_VALID_U8:
            return info_ptr->pin1_valid;
            break;
        case SMU_PHONE_LOCK_VERIFIED_U8:
            return info_ptr->phone_lock_verified;
            break;
/*			
        case SMU_REG_PS_KEY_A:
        case SMU_NP_CODE_A:
        case SMU_NP_KEY_A:
        case SMU_NSP_CODE_A:
        case SMU_NSP_KEY_A:
        case SMU_NP_OF_SP_A:
        case SMU_NP_OF_CP_A:
        case SMU_GID1_A:
        case SMU_GID2_A:
        case SMU_SP_KEY_A:
        case SMU_CP_KEY_A:
        case SMU_IMSI_CODE_A:
        case SMU_IMSI_KEY_A:
*/
        case SMU_PHONE_KEY_A:
        case SMU_LAST_IMSI_A:
        case SMU_PIN1_A:
        default:
            //ASSERT(0);  /* drop through! Wrong items */
            break;
    }
    return 0;
}

/* Query the value of the item in kal_uint8[] */


/*****************************************************************************
 * FUNCTION
 *  smu_query_a
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem       [IN]        
 *  pstrTo      [?]         
 *  chlen       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void smu_query_a(smu_item_enum eItem, kal_uint8 *pstrTo, kal_uint8 chlen, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
/*			
        case SMU_AUTO_LOCK_ITEM_U8:
*/        
        case SMU_PIN1_VALID_U8:
        case SMU_PHONE_LOCK_VERIFIED_U8:
            //ASSERT(0);
            break;
/*			
        case SMU_REG_PS_KEY_A:
        case SMU_NP_CODE_A:
        case SMU_NP_KEY_A:
        case SMU_NSP_CODE_A:
        case SMU_NSP_KEY_A:
        case SMU_NP_OF_SP_A:
        case SMU_NP_OF_CP_A:
        case SMU_GID1_A:
        case SMU_GID2_A:
        case SMU_SP_KEY_A:
        case SMU_CP_KEY_A:
        case SMU_IMSI_CODE_A:
        case SMU_IMSI_KEY_A:
*/
        case SMU_PHONE_KEY_A:
            break;
        case SMU_LAST_IMSI_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            kal_mem_cpy(pstrTo, info_ptr->last_imsi, NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            break;
        case SMU_PIN1_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_PIN1);
            kal_mem_cpy(pstrTo, info_ptr->pin1, NVRAM_EDITOR_NUM_PIN1);
            break;
	 case SMU_ICCID_A:
	     kal_mem_cpy(pstrTo, info_ptr->iccid, NVRAM_EDITOR_NUM_OF_BYTE_ICCID);
	     break;
        default:
            //ASSERT(0);  /* drop through! Wrong items */
            break;
    }
}

/* Assign the value of the item in kal_uint8 */


/*****************************************************************************
 * FUNCTION
 *  smu_assign_u8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem       [IN]        
 *  chValue     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void smu_assign_u8(smu_item_enum eItem, kal_uint8 chValue, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
            info_ptr->security_indication = chValue;
            break;
/*			
        case SMU_AUTO_LOCK_ITEM_U8:
            info_ptr->auto_lock_item = chValue;
            break;
*/            
        case SMU_PIN1_VALID_U8:
            info_ptr->pin1_valid = chValue;
            break;
        case SMU_PHONE_LOCK_VERIFIED_U8:
            info_ptr->phone_lock_verified = chValue;
            break;
/*			
        case SMU_REG_PS_KEY_A:
        case SMU_NP_CODE_A:
        case SMU_NP_KEY_A:
        case SMU_NSP_CODE_A:
        case SMU_NSP_KEY_A:
        case SMU_NP_OF_SP_A:
        case SMU_NP_OF_CP_A:
        case SMU_GID1_A:
        case SMU_GID2_A:
        case SMU_SP_KEY_A:
        case SMU_CP_KEY_A:
        case SMU_IMSI_CODE_A:
        case SMU_IMSI_KEY_A:
*/
        case SMU_PHONE_KEY_A:
        case SMU_LAST_IMSI_A:
        case SMU_PIN1_A:
        default:
            //ASSERT(0);  /* drop through! Wrong items */
            break;
    }
}

/* Assign the value of the item in string with length */


/*****************************************************************************
 * FUNCTION
 *  smu_assign_a
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem           [IN]        
 *  pstrValue       [?]         
 *  chlen           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void smu_assign_a(smu_item_enum eItem, kal_uint8 *pstrValue, kal_uint8 chlen, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
/*			
        case SMU_AUTO_LOCK_ITEM_U8:
*/
        case SMU_PIN1_VALID_U8:
        case SMU_PHONE_LOCK_VERIFIED_U8:
            //ASSERT(0);
            break;
/*			
        case SMU_REG_PS_KEY_A:
            break;
        case SMU_NP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            kal_mem_cpy(info_ptr->np_code, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NP);
            break;
        case SMU_NP_KEY_A:
            break;
        case SMU_NSP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NSP);
            kal_mem_cpy(info_ptr->nsp_code, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NSP);
        case SMU_NSP_KEY_A:
            break;
        case SMU_NP_OF_SP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            kal_mem_cpy(info_ptr->np_of_sp, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NP);
            break;
        case SMU_NP_OF_CP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            kal_mem_cpy(info_ptr->np_of_cp, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NP);
            break;
        case SMU_GID1_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            kal_mem_cpy(info_ptr->gid1, pstrValue, chlen);
            break;
        case SMU_GID2_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            kal_mem_cpy(info_ptr->gid2, pstrValue, chlen);
            break;
        case SMU_SP_KEY_A:
            break;
        case SMU_CP_KEY_A:
            break;
        case SMU_IMSI_CODE_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            kal_mem_cpy(info_ptr->imsi_code, pstrValue, chlen);
            break;
        case SMU_IMSI_KEY_A:
            break;
*/            
        case SMU_PHONE_KEY_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            kal_mem_cpy(info_ptr->phone_key, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            break;
        case SMU_LAST_IMSI_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            kal_mem_cpy(info_ptr->last_imsi, pstrValue, chlen);
            break;
        case SMU_PIN1_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_PIN1);
            kal_mem_cpy(info_ptr->pin1, pstrValue, NVRAM_EDITOR_NUM_PIN1);
            break;
	 case SMU_ICCID_A:
	     kal_mem_cpy(info_ptr->iccid, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_ICCID);
	     break;
        default:
            //ASSERT(0);
            break;
    }
}

/* Compare the string with the data item */

/*****************************************************************************
 * FUNCTION
 *  smu_match
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem           [IN]        
 *  pstrValue       [?]         
 *  chlen           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool smu_match(smu_item_enum eItem, kal_uint8 *pstrValue, kal_uint8 chlen, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

//    kal_uint8 idx = 0;

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->security_indication == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
/*			
        case SMU_AUTO_LOCK_ITEM_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->auto_lock_item == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
*/            
        case SMU_PIN1_VALID_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->pin1_valid == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_PHONE_LOCK_VERIFIED_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->phone_lock_verified == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
/*			
        case SMU_REG_PS_KEY_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->reg_ps_key, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_KEY) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            for (idx = 0; idx < NVRAM_EDITOR_NUM_NP; idx++)
            {
                if (kal_mem_cmp(
                        pstrValue,
                        (kal_uint8*) & (info_ptr->np_code[idx * NVRAM_EDITOR_NUM_OF_BYTE_NP]),
                        NVRAM_EDITOR_NUM_OF_BYTE_NP) == 0)
                {
                    return KAL_TRUE;    // Find one! 
                }
            }
            return KAL_FALSE;
            break;
        case SMU_NP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->np_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NSP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NSP);
            for (idx = 0; idx < NVRAM_EDITOR_NUM_NSP; idx++)
            {
                if (kal_mem_cmp(
                        pstrValue,
                        (kal_uint8*) & (info_ptr->nsp_code[idx * NVRAM_EDITOR_NUM_OF_BYTE_NSP]),
                        NVRAM_EDITOR_NUM_OF_BYTE_NSP) == 0)
                {
                    return KAL_TRUE;    // Find one! 
                }
            }
            return KAL_FALSE;
            break;
        case SMU_NSP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->nsp_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NP_OF_SP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            if (kal_mem_cmp(pstrValue, info_ptr->np_of_sp, NVRAM_EDITOR_NUM_OF_BYTE_NP) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NP_OF_CP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            if (kal_mem_cmp(pstrValue, info_ptr->np_of_cp, NVRAM_EDITOR_NUM_OF_BYTE_NP) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_GID1_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            if (kal_mem_cmp(info_ptr->gid1, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_GID2_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            if (kal_mem_cmp(info_ptr->gid2, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_SP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->sp_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_CP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->cp_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_IMSI_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            if (kal_mem_cmp(info_ptr->imsi_code, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_IMSI) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_IMSI_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->imsi_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
*/            
        case SMU_PHONE_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->phone_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_LAST_IMSI_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            if (kal_mem_cmp(info_ptr->last_imsi, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_IMSI) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_PIN1_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_PIN1);
            if (kal_mem_cmp(info_ptr->pin1, pstrValue, NVRAM_EDITOR_NUM_PIN1) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;

	 case SMU_ICCID_A:
	     if(kal_mem_cmp(info_ptr->iccid,
			           pstrValue,
			           NVRAM_EDITOR_NUM_OF_BYTE_ICCID) == 0)
		    return KAL_TRUE;
	     else
		    return KAL_FALSE;
		break;

        default:
            //ASSERT(0);
            break;
    }
    return KAL_FALSE;
}

/* END: PH smu_security_info_struct (NVRAM_EF_MS_SECURITY_LID)  */

/*******************************************************************************
 * FUNCTION  
 *  sml_Nvram_get_size
 * DESCRIPTION
 *  This function is used to query the status of the category
 * PARAMETERS
 *  IN          file_idx
 * RETURN
 *  kal_uint16 file size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_Nvram_get_lid_size(kal_uint16 file_idx)
{

    switch(file_idx)
    {
        case NVRAM_EF_MS_SECURITY_LID:
            
            return sizeof(smu_security_info_struct);

            break;

        case NVRAM_EF_SML_LID:

            return sizeof(sml_context_struct);

            break;

        case NVRAM_EF_SML_TMO_LID:

            return sizeof(sml_tmo_context_struct);

            break;
            
#ifdef __CARRIER_RESTRICTION__
        case NVRAM_EF_L4_CARRIER_RESTRICTION_LID:

            return sizeof(smu_carrier_match_context_struct);

            break;
#endif

        default:

            return 0;

            break;

    }

}

#ifdef __SIM_ME_LOCK__

/* Define your GID1 code here!! */
/***************************************************************************** 
 * The maximum length supported of GID1 is 20 bytes, represented as sim_gid1[20]
 * Modify gid1[20] array to support multiple sets of GID1 code
 * For example,
 *     With GID1 length 5 bytes, if there are 2 sets of GID1 code, 
 *       1st GID1:  0x11, 0x22, 0x33, 0x44, 0x55
 *      2nd GID1:  0x66, 0x77, 0x88, 0x99, 0xAA
 *       You should set gid1_length = 5, gid1_set = 2, and assign gid1[20] as followed:
 *       gid1[20] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 
 *                        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
 * Important: Use '0xFF' as the rest element of gid1 array
 * 
 * You may extend the size of gid1[] array to support plenty sets of GID1 code as you want
 *****************************************************************************/
kal_bool is_gid1_matched(kal_uint8 *sim_gid1)
{
    /* Open GID1_SECURITY_CHECK */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif       


    /* Close GID1_SECURITY_CHECK, return KAL_TRUE */
//#if 0
      	return KAL_TRUE;
//#endif
    
}

/*[MAUI_01634719] mtk01612*/
/***************************************************************************** 
*
 *****************************************************************************/
kal_bool is_mcc_mnc_matched(kal_uint8 *sim_code, kal_uint8 len)
{
    /* Open MCC/MNC check for N category */
/*[MAUI_01634719] mtk01612: test*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* Close MCC/MNC check for N category, return KAL_TRUE */
//#if 0
      	return KAL_TRUE;
//#endif
    
}

/* Define your Block list here!! */
/***************************************************************************** 
 * For example 2 digits MNC case: MCC\MNC 466 97 => 0x46 0x69 0x7F 
 *             3 digits MNC case: MCC\MNC 466 285 => 0x46 0x62 0x85
 * !!!IMPORTANT: USE three 0xFF at the end of array to terminate !!! 
 *****************************************************************************/
static const kal_uint8 smlVISA[] = {
/* Insert your items here */

//0x46, 0x61, 0x1F,   // Item 1
//0x46, 0x69, 0x2F,   // Item 2

/* Do not modify the 0xFF 0xFF 0xFF below */
0xFF, 0xFF, 0xFF }; // Do not modify this line!



/* BEGIN: PH sml_context_struct (NVRAM_EF_SML_LID) */
/******************************************************************************
 * New SML Architecture
 *****************************************************************************/
/******************************************************************************
 *    typedef struct {
 *        kal_uint32  magic_head;
 *        sml_category_meta_struct    cat[SML_CAT_SIZE];
 *        sml_control_key_struct      key[SML_CAT_SIZE];
 *        kal_uint8   code_cat_n[SML_CFG_CAT_N_SIZE];
 *        kal_uint8   code_cat_ns[SML_CFG_CAT_NS_SIZE];
 *        kal_uint8   code_cat_sp[SML_CFG_CAT_SP_SIZE];
 *        kal_uint8   code_cat_c[SML_CFG_CAT_C_SIZE];
 *        kal_uint8   code_cat_sim[SML_CFG_CAT_SIM_SIZE];
 *        kal_uint8   code_cat_ns_sp[SML_CFG_CAT_NS_SP_SIZE];
 *        kal_uint8   code_cat_sim_c[SML_CFG_CAT_SIM_C_SIZE];
 *        kal_uint8   range_cat_ns[SML_CAT_NS_RANGE_SIZE]
 *        kal_uint32 magic_tail;         
 *    } sml_context_struct;
 *****************************************************************************/ 

/***************************************************************************** 
 * Typedef of SML
 *****************************************************************************/
static void sml_give( void * pLidToObj, kal_uint8 source );
static void sml_take( void * pObjToLid, kal_uint8 source );
static void sml_destory( kal_uint8 source );
static void * sml_getItem( sml_cat_enum cat, 
                           sml_ctx_enum item, 
                           kal_uint16 * plength,
                           kal_uint8 source
                         );
static void sml_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void * pItem, 
                         kal_uint16 * plength,
                         kal_uint8 source
                       );

/* TMO SML */
static void sml_tmo_give( void * pLidToObj, kal_uint8 source );
static void sml_tmo_take( void * pObjToLid, kal_uint8 source );
static void sml_tmo_destory( kal_uint8 source );
static void * sml_tmo_getItem( sml_cat_enum cat, 
                           sml_ctx_enum item, 
                           kal_uint16 * plength,
                           kal_uint8 source
                         );
static void sml_tmo_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void * pItem, 
                         kal_uint16 * plength,
                         kal_uint8 source
                       );

#ifdef __CARRIER_RESTRICTION__
static void sml_crrst_give( void * pLidToObj, kal_uint8 source );
static void sml_crrst_take( void * pObjToLid, kal_uint8 source );
static void sml_crrst_destory( kal_uint8 source );
static void * sml_crrst_getItem( smu_crrst_cat_enum cat, 
                           sml_ctx_enum item, 
                           kal_uint16 * plength,
                           kal_uint8 source
                         );
static void sml_crrst_putItem( smu_crrst_cat_enum cat, 
                         sml_ctx_enum item, 
                         void * pItem, 
                         kal_uint16 * plength,
                         kal_uint8 source
                       );
static void * sml_crrst_getList (sml_ctx_enum list,
                           kal_uint16 *plength,
                           kal_uint8 source);
#endif /* __CARRIER_RESTRICTION__ */

/* define the Local variable of SML */
static nvram_ef_sml_obj_struct SMLOBJ[MAX_SIM_NUM];

/* define the Local variable of SML object */
static sml_context_struct sml_cntxt_obj[MAX_SIM_NUM];

/* define the Local variable of SML TMO object */
static sml_tmo_context_struct sml_tmo_cntxt_obj[MAX_SIM_NUM];

#ifdef __CARRIER_RESTRICTION__
/* define the Local variable of SMU carrier restriction object */
static smu_carrier_match_context_struct smu_crrst_cntxt_obj[MAX_SIM_NUM];
static nvram_ef_smu_crrst_obj_struct CRRSTOBJ[MAX_SIM_NUM];

/* define the Global access pointer of SMU Carrier Restrcition object */
nvram_ef_smu_crrst_obj_struct * pCRRSTg = &CRRSTOBJ[0];
#endif

/* define the Global access pointer of SML object */
nvram_ef_sml_obj_struct * pSMLg = &SMLOBJ[0];


/*******************************************************************************
 * Define the method of the object
 *******************************************************************************/
void sml_init_sml_obj(kal_uint8 source)
{
    nvram_ef_sml_obj_struct sml_obj = {
        NULL,    
        sml_give,
        sml_take,
        sml_destory,
        sml_getItem,
        sml_putItem    
    };

    nvram_ef_sml_obj_struct sml_tmo_obj = {
        NULL,    
        sml_tmo_give,
        sml_tmo_take,
        sml_tmo_destory,
        sml_tmo_getItem,
        sml_tmo_putItem
    };

    if (sbp_query_md_feature(SBP_TMO_REMOTE_SIM_LOCK) == KAL_TRUE)
    {
        sml_tmo_destory(source);
        kal_mem_cpy(&pSMLg[source], &sml_tmo_obj, sizeof(nvram_ef_sml_obj_struct));
    }
    else
    {
        sml_destory(source);
        kal_mem_cpy(&pSMLg[source], &sml_obj, sizeof(nvram_ef_sml_obj_struct));
    }
}

#ifdef __CARRIER_RESTRICTION__
void sml_init_crrst_obj(kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct sml_crrst_obj = {
        NULL,
        sml_crrst_give,
        sml_crrst_take,
        sml_crrst_destory,
        sml_crrst_getItem,
        sml_crrst_putItem,
        sml_crrst_getList
    };

    sml_crrst_destory(source);
    kal_mem_cpy(&pCRRSTg[source], &sml_crrst_obj, sizeof(nvram_ef_smu_crrst_obj_struct));
}
#endif

// TMO SML

/* time to temporary unlock expiry in seconds */
kal_uint32 sml_tmo_seconds_to_expire = 0;
extern kal_bool smu_sml_tmo_timer_expiry_callback(void *param);

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_printkey
 * DESCRIPTION
 *  This method print the key for debugging
 * PARAMETERS
 *  IN          * key
 * RETURN
 *  void
*******************************************************************************/
void sml_tmo_printkey(t_cust_chl_sym_key *key)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_give
 * DESCRIPTION
 *  This method copys the LID files read from NVRAM to the SML obj
 * PARAMETERS
 *  IN          * pLidToObj
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
*******************************************************************************/
static void sml_tmo_give( void *pLidToObj, kal_uint8 source )
{
    sml_tmo_context_struct * pObj = NULL;
  
    if(NULL != pSMLg[source].pObj)
    {
    
        kal_sys_trace("SML: object is exist!");
    
        pSMLg[source].pObj = NULL;
    
    }
       
    pObj = &(sml_tmo_cntxt_obj[source]);
    
    kal_mem_cpy(pObj,
                pLidToObj,
                sizeof(sml_tmo_context_struct)
                ); 
   
    pSMLg[source].pObj = pObj;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_take
 * DESCRIPTION
 *  This method copys the contex of the SML object to the provided NVRAM LID.
 * PARAMETERS
 *  OUT         * pObjToLid
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
static void sml_tmo_take( void *pObjToLid, kal_uint8 source )
{
    sml_tmo_context_struct * pObj = (sml_tmo_context_struct *) pSMLg[source].pObj;

    kal_mem_cpy(pObjToLid,
                pObj,
                sizeof(sml_tmo_context_struct)
                );
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_destory
 * DESCRIPTION
 *  This method free the SML object in memory if it is not used.
 * PARAMETERS
 *  void
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/    
static void sml_tmo_destory(kal_uint8 source)
{
    pSMLg[source].pObj = NULL;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_getItem
 * DESCRIPTION
 *  This method returns the structure pointer and length of the structure
 *  of the desired SML object items.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  OUT         *length
 * RETURN
 *  void *
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
static void * sml_tmo_getItem( sml_cat_enum category, 
                           sml_ctx_enum item, 
                           kal_uint16 *plength,
                           kal_uint8 source)
{
    sml_tmo_context_struct *pObj = (sml_tmo_context_struct *) pSMLg[source].pObj;
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {
        case SML_TMO_CAT_VERSION:
            *plength = SML_TMO_SIZE_OF_VERSION;
            return (kal_uint32 *) &(pObj->version[0]);
        
        case SML_TMO_CAT_PERTECTION_SCHEME:
            *plength = sizeof(kal_uint8);
            return (kal_uint32 *) &(pObj->protection_scheme);
        
        case SML_TMO_CAT_STATE:
            *plength = sizeof(kal_uint8);
             return (kal_uint8 *) &(pObj->state);
        
        case SML_TMO_CAT_LENGTH:
            *plength = SML_TMO_SIZE_OF_LENGTH;
            return (kal_uint16 *) &(pObj->length[0]);

        case SML_TMO_CAT_NUM_PLMN:
            *plength = SML_TMO_SIZE_OF_NUM_PLMN;
            return (kal_uint16 *) &(pObj->num_of_plmn[0]);

        case SML_TMO_CAT_PLMN_LIST:
            *plength = SML_TMO_SIZE_OF_PLMN_LIST;
            return (kal_uint8 *) &(pObj->plmn_list[0]);

        case SML_TMO_CAT_NUM_GID:
            *plength = SML_TMO_SIZE_OF_NUM_GID;
            return (kal_uint16 *) &(pObj->num_of_gid[0]);

        case SML_TMO_CAT_GID_LIST:
            *plength = SML_TMO_SIZE_OF_GID_LIST;
            return (kal_uint8 *) &(pObj->gid_list[0]);

        case SML_TMO_CAT_START_TIME:
            *plength = SML_TMO_SIZE_OF_START_TIME;
            return (kal_uint32 *) &(pObj->start_time[0]);
            
        case SML_TMO_CAT_END_TIME:
            *plength = SML_TMO_SIZE_OF_END_TIME;
            return (kal_uint32 *) &(pObj->end_time[0]);

        case SML_TMO_CAT_IMEI:
            *plength = SML_TMO_SIZE_OF_IMEI;
            return (kal_uint8 *) &(pObj->imei[0]);

        case SML_TMO_CAT_VERIFICATION_CODE:
            *plength = SML_TMO_SIZE_OF_VERIFICATION_CODE;
            return (kal_uint8 *) &(pObj->verification_code[0]);

        case SML_TMO_CAT_UNLOCK_TIME_COUNTER:
            *plength = SML_TMO_SIZE_OF_UNLOCK_TIME;
            return (kal_uint32 *) &(pObj->unlock_time[0]);

        default:
            break;   
    }

    return NULL;
    
}


/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_putItem
 * DESCRIPTION
 *  This method set the desired items of the SML object.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  IN          *pItem
 *  IN          *plength
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
static void sml_tmo_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void *pItem, 
                         kal_uint16 *plength,
                         kal_uint8 source)
{
    sml_tmo_context_struct *pObj = (sml_tmo_context_struct *) pSMLg[source].pObj;
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {
        case SML_TMO_CAT_UNLOCK_TIME_COUNTER:
                  
            kal_mem_cpy(&(pObj->unlock_time[0]),
                        pItem,
                        4
                        );        
            break;
                
        default:
            break;
    }
}


/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_checkValidity
 * DESCRIPTION
 *  This method is to check the validity of the SML object
 * PARAMETERS
 *  IN          pObj    SML object
 * RETURN
 *  TRUE        Pass the validity check
 *  FALSE       Fail the validity check
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_tmo_checkValidity(void *pObj, kal_uint8 source)
{
    sml_tmo_context_struct *pSmlObj = (sml_tmo_context_struct *) pObj;
    kal_uint8 *pData = NULL;
    kal_bool result = KAL_FALSE;
    kal_uint32 data_len;
    kal_uint8 imei_bcd[8+1];
    kal_uint8 imei_ascii[SML_TMO_SIZE_OF_IMEI];

#ifdef UNIT_TEST    //Integrity check doesn't work on modis. Modify for UT.
    return KAL_TRUE;
#else

    if (nvram_get_imei_value(8, imei_bcd, (1 + source)) == KAL_TRUE)
    {
        // ch2-ch1, last digit is 0
        imei_bcd[7] = imei_bcd[7] & 0x0f;
        imei_bcd[8] = 0xff;
        convert_to_digit((kal_uint8 *)imei_bcd, imei_ascii);
        kal_prompt_trace(MOD_SMU, "UE IMEI:   %s", imei_ascii);
        kal_prompt_trace(MOD_SMU, "BLOB IMEI: %s", &(pSmlObj->imei[0]));
        if (kal_mem_cmp(&(pSmlObj->imei[0]), imei_ascii, SML_TMO_SIZE_OF_IMEI) == 0)
        {
            result = KAL_TRUE;
        }
    }

    if (result == KAL_FALSE)
    {
        //IMEI mismatch
        SML_TRACE(TRACE_WARNING, WARNING_SML_CHECK_IMEI_FAILED);
        return KAL_FALSE;
    }

    if (pSmlObj == NULL)
    {
        return KAL_FALSE;
    }

    pData = sml_ReconstructBlob(pSmlObj, &data_len);

    if (pData == NULL)
    {
        return KAL_FALSE;
    }

    if (pSmlObj->protection_scheme == SML_PROTECTION_SCHEME_HMAC_SHA256)
    {
        t_cust_chl_sym_key key = {0};
        kal_uint32 ret;

        ret = CustCHL_Get_Sym_Key(CUST_TM_SHARED_KEY2, &key);
        if (ret == CUST_CHL_ERROR_NONE)
        {
            sml_tmo_printkey(&key);
            sml_Dump("verify mac", &(pSmlObj->verification_code[0]), SML_TMO_SIZE_OF_MAC);
            ret = CustCHL_Verify_MAC(CUST_CHL_ALG_MAC_SHA256, pData, data_len,
                                     &pSmlObj->verification_code[0], &key.m_key[0], key.m_key_len);
        }
        result = (ret == CUST_CHL_ERROR_NONE) ? KAL_TRUE : KAL_FALSE;

    }
    else if (pSmlObj->protection_scheme == SML_PROTECTION_SCHEME_RSA2048)
    {
        t_cust_chl_asym_key key;
        kal_uint32 ret;

        ret = CustCHL_Get_Asym_Key(CUST_TM_PUB_KEY1, &key);
        if (ret == CUST_CHL_ERROR_NONE)
        {
            ret = CustCHL_Verify_PSS_Signature(CUST_CHL_ALG_RSA_PSS_SHA256, pData, data_len, 
                                               &pSmlObj->verification_code[0], &key);
        }
        result = (ret == CUST_CHL_ERROR_NONE) ? KAL_TRUE : KAL_FALSE;
    }
    else
    {
        result = KAL_FALSE;
    }

    free_ctrl_buffer(pData);

    return result;
#endif
}

#ifndef ATEST_ENABLE

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_nwTimeToSeconds
 * DESCRIPTION
 *  This method is to convert network time to seconds that have elapsed since 1970/1/1,00:00:00
 * PARAMETERS
 *  IN          nw_time_zone
 *  IN          nw_time
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint32 sml_tmo_nwTimeToSeconds(kal_uint8 nw_time_zone, nw_time_zone_time_struct *nw_time)
{
    kal_uint32 seconds = 0;
    kal_uint8 year_diff = 0, month_diff = 0, hour_diff = 0, min_diff = 0, sec_diff = 0;
    kal_uint16 day_diff = 0;
    kal_uint8 leap_years = 0;
    //kal_uint8 time_diff = 0;
    kal_uint8 month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    kal_uint8 i;
    //kal_uint8 timezone = nw_time->time_zone;

    /* base time: 1970/1/1,00:00:00 */
    year_diff = 2000 + (nw_time->year & 0x0F)*10 + (nw_time->year >> 4) - 1970;
    if (year_diff >= 100)
    {
        year_diff -= 100;
    }
    /* there is a leap year every four years */
    leap_years = (year_diff+2)/4;

    month_diff = (nw_time->month & 0x0F)*10 + (nw_time->month >> 4) - 1;
    day_diff = (nw_time->day & 0x0F)*10 + (nw_time->day >> 4) - 1;
    hour_diff = (nw_time->hour & 0x0F)*10 + (nw_time->hour >> 4);
    min_diff = (nw_time->min & 0x0F)*10 + (nw_time->min >> 4);
    sec_diff = (nw_time->sec & 0x0F)*10 + (nw_time->sec >> 4);

    day_diff += leap_years;
    for (i = 0; i < month_diff; i++)
    {
        day_diff += month_days[i];
    }

    seconds = 365*24*60*60*year_diff + 24*60*60*day_diff + 60*60*hour_diff + 60*min_diff + sec_diff;

    // start_time in TMO SLB is UTC (GMT+0) time, thus no need adjust timezone
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    //kal_prompt_trace(MOD_SMU,"year_diff:%d",year_diff);
    //kal_prompt_trace(MOD_SMU,"leap_years:%d month_diff:%d day_diff:%d",leap_years,month_diff,day_diff);
    //kal_prompt_trace(MOD_SMU,"hour_diff:%d",hour_diff);
    //kal_prompt_trace(MOD_SMU,"min_diff:%d",min_diff);
    //kal_prompt_trace(MOD_SMU,"sec_diff:%d",sec_diff);
    //kal_prompt_trace(MOD_SMU,"timezone_diff:%d",time_diff);
    //kal_prompt_trace(MOD_SMU,"[Total seconds]= %x",(kal_uint32)seconds);

    return seconds;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_UpdateNwTimeAndCheckTempLock
 * DESCRIPTION
 *  This method is to update newtork time and check if temporary lock expires
 * PARAMETERS
 *  IN          source
 *  IN          nw_time_zone
 *  IN          nw_time
 * RETURN
 *  TRUE        Temporary unlock expires
 *  FALSE       Temporary unlock does not expire
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_tmo_UpdateNwTimeAndCheckTempLock(kal_uint8 source, kal_uint8 nw_time_zone, nw_time_zone_time_struct *nw_time)
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    kal_uint8 *start_time, *end_time;
    kal_uint8 *state = NULL;
    kal_uint16 length;
    kal_uint32 current_seconds = 0;
    kal_uint64 start_seconds = 0;
    kal_uint32 start_seconds_u32 = 0;
    kal_uint32 duration_seconds = 0;
    kal_uint8 i;

    state = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_STATE, &length, source);
    start_time = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_START_TIME, &length, source);
    end_time = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_END_TIME, &length, source);

    if (*state != SML_TMO_STATE_TEMPORARY_UNLOCK)
    {
        return KAL_FALSE;
    }

    /* calculate start time and duration in seconds */
    start_seconds = 0;
    for (i = 0; i < SML_TMO_SIZE_OF_START_TIME-1; i++)
    {
        start_seconds += start_time[i];
        start_seconds = (start_seconds << 8);
    }
    start_seconds += start_time[SML_TMO_SIZE_OF_START_TIME-1];
    start_seconds /= 1000;  /* from milliseconds to seconds */

    start_seconds_u32 = (kal_uint32)start_seconds;

    duration_seconds = 0;
    for (i = 0; i < SML_TMO_SIZE_OF_END_TIME-1; i++)
    {
        duration_seconds += end_time[i];
        duration_seconds = (duration_seconds << 8);
    }
    duration_seconds += end_time[SML_TMO_SIZE_OF_END_TIME-1];

    /* calculate current time in seconds */
    current_seconds = sml_tmo_nwTimeToSeconds(nw_time_zone, nw_time);

    SML_TRACE(TRACE_INFO, INFO_SML_TEMP_UNLOCK_TIME, start_seconds_u32, duration_seconds, current_seconds);

    //kal_prompt_trace(MOD_SMU,"start_seconds_u32= %x", start_seconds_u32);
    //kal_prompt_trace(MOD_SMU,"duration_seconds= %x", (kal_uint32)duration_seconds);
    //kal_prompt_trace(MOD_SMU,"current_seconds= %x", (kal_uint32)current_seconds);

    if (current_seconds >= (start_seconds_u32+duration_seconds))
    {
        SML_TRACE(TRACE_INFO, INFO_SML_NW_TIME_EXPIRED);
        /* expired */
        //*state = SML_STATE_PERMANENT_LOCK;
        //sml_tmo_seconds_to_expire = 0;       
        return KAL_TRUE;
    }
    else
    {
        /* update unlock time for power off accuracy: start ---> unlock time ---> NITZ ---> power off/on ---> end */
        sml_tmo_seconds_to_expire = current_seconds - start_seconds_u32;
        (*p->putItem)(SML_CAT_C, SML_TMO_CAT_UNLOCK_TIME_COUNTER, &sml_tmo_seconds_to_expire, &length, source);
        smu_nvram_write(NVRAM_EF_SML_TMO_LID, SML_TMO_NVRAM_ACCESS_ID_UNLOCK_EXPIRE, KAL_FALSE);

        return KAL_FALSE;
    }
}
#endif
/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_CheckTempUnlock
 * DESCRIPTION
 *  This method is to check if temporary unlock expires
 * PARAMETERS
 *  IN          source
 * RETURN
 *  TRUE        Temporary unlock expires
 *  FALSE       Temporary unlock does not expire
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_tmo_CheckTempUnlock(kal_uint8 source)
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];    
    kal_uint8 *state, *end_time;
    kal_uint16 length;
    kal_uint32 duration_seconds = 0;
    kal_uint8 i;

    state = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_STATE, &length, source);
    end_time = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_END_TIME, &length, source);

    for (i = 0; i < SML_TMO_SIZE_OF_END_TIME-1; i++)
    {
        duration_seconds += end_time[i];
        duration_seconds = (duration_seconds << 8);
    }
    duration_seconds += end_time[SML_TMO_SIZE_OF_END_TIME-1];

    SML_TRACE(TRACE_INFO, INFO_SML_CHECK_TEMP_UNLOCK, sml_tmo_seconds_to_expire, duration_seconds);

    //kal_prompt_trace(MOD_SMU, "counter: %d duration_seconds:%d", 
    //    sml_tmo_seconds_to_expire + (SML_TMO_TIMEOUT_PERIODIC_CHECK/KAL_TICKS_1_SEC),duration_seconds);

    if ((sml_tmo_seconds_to_expire + (SML_TMO_TIMEOUT_PERIODIC_CHECK/KAL_TICKS_1_SEC)) >= duration_seconds)
    {
        *state = SML_TMO_STATE_PERMANENT_LOCK;
        // Should reset SLB/NVRAM in following action
        return KAL_TRUE;
    }
    else
    {
        sml_tmo_seconds_to_expire += (SML_TMO_TIMEOUT_PERIODIC_CHECK/KAL_TICKS_1_SEC);
        (*p->putItem)(SML_CAT_C, SML_TMO_CAT_UNLOCK_TIME_COUNTER, &sml_tmo_seconds_to_expire, &length, source);
        // Should write back to NVRAM in following action
        return KAL_FALSE;
    }
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_FirstLoad
 * DESCRIPTION
 *  This function check if it is the first loads of SML obj from NVRAM LID. If so,
 *  calculate the verification code and store it
 * PARAMETERS
 *  IN          pLid
 * RETURN
 *  kal_bool    TRUE: first load
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_tmo_FirstLoad( void *pLid, kal_uint8 source )
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    kal_uint32 i;
    sml_tmo_context_struct * pObj = NULL;
    kal_uint8 *pData = NULL;
    kal_uint32 data_len;
    kal_bool isFirstLoad = KAL_TRUE;
    kal_uint8 imei_bcd[8+1];
    kal_uint8 imei_ascii[SML_TMO_SIZE_OF_IMEI];

    pObj = (sml_tmo_context_struct *) pLid;

    /* the verification code will be all zero if it is the first time to load */
    for (i = 0; i < SML_TMO_SIZE_OF_VERIFICATION_CODE; i++)
    {
        if (pObj->verification_code[i] != 0)
        {
            isFirstLoad = KAL_FALSE;
            break;
        }
    }

    if (isFirstLoad == KAL_TRUE)
    {
        kal_uint32 ret = CUST_CHL_ERROR_NONE;

        if (nvram_get_imei_value(8, imei_bcd, (1 + source)) == KAL_TRUE)
        {
            // ch2-ch1, last digit is 0
            imei_bcd[7] = imei_bcd[7] & 0x0f;
            imei_bcd[8] = 0xff;
            convert_to_digit((kal_uint8 *)imei_bcd, imei_ascii);
            kal_mem_cpy(&(pObj->imei[0]), imei_ascii, SML_TMO_SIZE_OF_IMEI);
        }

        pData = sml_ReconstructBlob(pObj, &data_len);

        if (pData == NULL)
        {
            // This error will be traced in sml_tmo_Load
            return KAL_FALSE;
        }

        if (pObj->protection_scheme == SML_PROTECTION_SCHEME_HMAC_SHA256)
        {
            t_cust_chl_sym_key key = {0};
            
            ret = CustCHL_Get_Sym_Key(CUST_TM_SHARED_KEY2, &key);
            if (ret == CUST_CHL_ERROR_NONE)
            {
                t_cust_chl_mac_u mac;

                sml_tmo_printkey(&key);
                ret = CustCHL_Calculate_MAC(CUST_CHL_ALG_MAC_SHA256, pData, data_len, 
                                            &key.m_key[0], key.m_key_len, &mac);
                sml_Dump("calculate mac", &(mac.m_u8[0]), mac.m_len);
                if (ret == CUST_CHL_ERROR_NONE)
                {
                    kal_mem_cpy(&pObj->verification_code[0], &mac.m_u8[0], mac.m_len);

                    // Test validation
                    if (sml_tmo_checkValidity((void*)pObj, source) == KAL_FALSE)
                    {
                        SML_TRACE(TRACE_WARNING, WARNING_SML_LOAD_CHECK_VALIDITY_FAILED);
                    }
                }
            }
        }
        else
        {
            /* To-Do for signature */
        }

        free_ctrl_buffer(pData);

        if (ret == CUST_CHL_ERROR_NONE)
        {
            /* Clean the old ones */
            (*p->destory)(source);

            /* Load the new one */
            (*p->give)((void *)pObj, source);
        }
    }

    return isFirstLoad;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_ReconstructBlob
 * DESCRIPTION
 *  This function re-construct BLOB of variable length (mcc-mnc-gid)
 * PARAMETERS
 *  IN          *pObj
 *  OUT       pLen
 * RETURN
 *  kal_uint8 * re-construct data for mac-signature
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
kal_uint8 *sml_ReconstructBlob( sml_tmo_context_struct *pObj, kal_uint32 *pLen )
{
    kal_uint8 *pData = NULL;
    kal_uint32 blob_len, data_len;
    kal_uint32 sizeN, sizeM;
    kal_uint32 idx, len;

    blob_len = sml_GetCount(&(pObj->length[0]));
    sizeN = sml_GetCount(&(pObj->num_of_plmn[0])) * SML_TMO_SIZE_OF_MCC_MNC;
    sizeM = sml_GetCount(&(pObj->num_of_gid[0])) * SML_TMO_SIZE_OF_GID;

    if (pObj->protection_scheme == SML_PROTECTION_SCHEME_HMAC_SHA256)
    {
        data_len = blob_len - SML_TMO_SIZE_OF_MAC;
    }
    else if (pObj->protection_scheme == SML_PROTECTION_SCHEME_RSA2048)
    {
        data_len = blob_len - SML_TMO_SIZE_OF_SIGNATURE;
    }
    else
    {
        data_len = 0;
    }

    *pLen = data_len;

    if (data_len == 0)
    {
        return pData;
    }

    pData = (kal_uint8 *)get_ctrl_buffer(data_len);

    // version + protection scheme + state + num of plmn + plmn list size
    len = SML_TMO_SIZE_OF_VERSION + 1 + 1 + SML_TMO_SIZE_OF_LENGTH + SML_TMO_SIZE_OF_NUM_PLMN + sizeN;
    kal_mem_cpy(pData, (kal_uint8 *)pObj, len);

    // num of gid + gid list size
    idx = len;
    len = SML_TMO_SIZE_OF_NUM_GID + sizeM;
    kal_mem_cpy((pData + idx), (kal_uint8 *)&(pObj->num_of_gid[0]), len);

    // from reserved to imei
    idx = idx + len;
    len = data_len - idx;
    kal_mem_cpy((pData + idx), (kal_uint8 *)&(pObj->reserved[0]), len);

    sml_Dump("re-construct blob", pData, data_len);

    return pData;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_ConstructBlob
 * DESCRIPTION
 *  This function construct full size Bolb from a variant length Blob
 * PARAMETERS
 *  IN          *pObj
 *  OUT       pLen
 * RETURN
 *  kal_uint8 * construct data 
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
extern kal_uint8 *sml_ConstructBlob( kal_uint8 *pObj, kal_uint16 slb_len)
{
    kal_uint16 sizeN, sizeM;
    kal_uint16 length = 0;
    kal_uint16 idx;
    sml_tmo_context_struct *pBlob;

    idx = SML_TMO_SIZE_OF_VERSION + 1 + 1 + SML_TMO_SIZE_OF_LENGTH;    // version, protection scheme, state, length
    sizeN = sml_GetCount(&(pObj[idx])) * SML_TMO_SIZE_OF_MCC_MNC;

    idx = idx + SML_TMO_SIZE_OF_NUM_PLMN + sizeN;                  // num of mcc-mnc, N
    sizeM = sml_GetCount(&(pObj[idx])) * SML_TMO_SIZE_OF_GID;

    if ((sizeN > (SML_TMO_MAX_PLMN_NUMBER*SML_TMO_SIZE_OF_MCC_MNC)) || (sizeM > (SML_TMO_MAX_GID_NUMBER*SML_TMO_SIZE_OF_GID)))
    {
        return NULL;
    }

    pBlob = (sml_tmo_context_struct *)get_ctrl_buffer(SML_TMO_MAX_SLB_SIZE);
    kal_mem_set(pBlob, 0, SML_TMO_MAX_SLB_SIZE);

    length = SML_TMO_SIZE_OF_VERSION + 1 + 1 + SML_TMO_SIZE_OF_LENGTH + SML_TMO_SIZE_OF_NUM_PLMN + sizeN;
    kal_mem_cpy(pBlob, &(pObj[0]), length);

    length = SML_TMO_SIZE_OF_NUM_GID + sizeM;
    kal_mem_cpy(&(pBlob->num_of_gid[0]), &(pObj[idx]), length);

    idx = idx + length;
    length = slb_len - idx;
    kal_mem_cpy(&(pBlob->reserved[0]), &(pObj[idx]), length);

    sml_Dump("update slb", (kal_uint8 *)pBlob, SML_TMO_MAX_SLB_SIZE);

    return (kal_uint8 *)pBlob;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_GetCount
 * DESCRIPTION
 *  This function convert 2 bytes of hex into int (ex: 0x00 0x04 -> 4)
 * PARAMETERS
 *  IN          *pData
 * RETURN
 *  kal_uint16   integer of pData
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
kal_uint16 sml_GetCount( kal_uint8 *pData )
{
    kal_uint16 num = (((kal_uint16)pData[0]) << 8) + pData[1];

    SML_TRACE(TRACE_INFO, INFO_SMU_GET_COUNT, pData[0], pData[1], num);

    return num;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Dump
 * DESCRIPTION
 *  This function print pData for debugging
 * PARAMETERS
 *  IN          *pData
 *  IN          len
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
void sml_Dump(kal_char *title, kal_uint8 *pData, kal_uint16 len)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_Load
 * DESCRIPTION
 *  This function loads the SML obj from NVRAM LID (NVRAM_READ_CNF)
 * PARAMETERS
 *  IN          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_tmo_Load( void *pLid, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    kal_uint16 length = sizeof(sml_tmo_context_struct);

    if (sml_tmo_checkValidity(pLid, source) == KAL_FALSE)
    {
        SML_TRACE(TRACE_WARNING, WARNING_SML_LOAD_CHECK_VALIDITY_FAILED);
        length = SML_TMO_INVALID_CONTEXT_OBJ_LENGTH;
    }

    /* Clean the old ones */
    (*p->destory)(source);

    /* Load the new one */
    (*p->give)(pLid, source);

    return length;

}


/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_Save
 * DESCRIPTION
 *  This function saves the SML obj to NVRAM LID (NVRAM_WRITE_REQ)
 * PARAMETERS
 *  OUT          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_tmo_Save( void *pLid, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    kal_uint16 length = sizeof(sml_tmo_context_struct);

    (*p->take)(pLid, source);

    return length;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_Check
 * DESCRIPTION
 *  This function is used to check if the code is in the Pass list
 * PARAMETERS
 *  IN          cat
 *  IN          *code
 *  IN          len
 *  OUT          *remain
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
kal_bool sml_tmo_Check( sml_cat_enum cat, 
                    kal_uint8 *imsi, 
                    kal_uint8 *gid1,
                    kal_uint8 *gid2,
                    kal_uint8 sim_mnc_len,
                    kal_uint8 *remain,
                    kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    kal_uint8 *pState = NULL;
    kal_uint8 *pData_plmn = NULL;
    kal_uint8 *pData_gid = NULL;
    kal_uint16 length = 0;
    kal_uint8 code[SML_TMO_SIZE_OF_MCC_MNC_GID] = {0};
    kal_uint8 code_len = 0;
    kal_uint8 compare_length = 0;
    kal_uint16 num_plmn = 0;
    kal_uint16 num_gid = 0;
    kal_uint16 i, j;
    kal_uint8 custom_exception[3][SML_TMO_SIZE_OF_MCC_MNC] = {{0x31, 0x03, 0x10, 0x00}, 
                                                          {0x31, 0x03, 0x00, 0x00}, 
                                                          {0x00, 0x10, 0x10, 0x00}};

    /* Check the integration of SIM Lock blob first */
    if ((p == NULL) || (p != NULL && sml_tmo_checkValidity(p->pObj, source) == KAL_FALSE))
    {
        SML_TRACE(TRACE_WARNING, WARNING_SML_CHECK_VALIDITY_FAILED);
        return KAL_FALSE;
    }

    pState = (kal_uint8 *)(*p->getItem)(cat, SML_TMO_CAT_STATE, &length, source);

    *remain = 0xFF;    /* TMO SIM lock doesn't need retry counter */

    if (*pState == SML_TMO_STATE_TEMPORARY_UNLOCK)
    {
        kal_uint8 *counter = NULL;
        kal_uint32 time_in_sec = 0;
        kal_uint8 i;

        counter = (kal_uint8 *)(*p->getItem)(cat, SML_TMO_CAT_UNLOCK_TIME_COUNTER, &length, source);
        
        for (i = 0; i < (SML_TMO_SIZE_OF_UNLOCK_TIME - 1); i++)
        {
            time_in_sec += counter[(SML_TMO_SIZE_OF_UNLOCK_TIME-1-i)];
            time_in_sec = (time_in_sec << 8);
        }
        time_in_sec += counter[0];

        sml_tmo_seconds_to_expire += *counter;

        if (smu_sml_tmo_timer_expiry_callback(NULL) == KAL_TRUE)
        {
            // Time expired -> back to LOCK , reset counter
            *pState = SML_TMO_STATE_PERMANENT_LOCK;
            //return KAL_FALSE;
        }
        else
        {
            return KAL_TRUE;
        }
    }

    if (*pState == SML_TMO_STATE_PERMANENT_UNLOCK)
    {
        /* always pass if it is not locked! */
        return KAL_TRUE;
    }

    if (*pState == SML_TMO_STATE_PERMANENT_LOCK)
    {
        code_len = sml_tmo_GetCode(cat, imsi, gid1, gid2, sim_mnc_len, NULL, code);
        compare_length = SML_TMO_SIZE_OF_MCC_MNC + SML_TMO_SIZE_OF_GID;
        
        num_gid = sml_GetCount(((*p->getItem)(cat, SML_TMO_CAT_NUM_GID, &length, source)));
        pData_gid = (kal_uint8 *)(*p->getItem)(cat, SML_TMO_CAT_GID_LIST, &length, source);
    }
    else /* SML_STATE_PARTIAL_UNLOCK */
    {
        /* GID is not necessary in partial unlock */
        code_len = sml_tmo_GetCode(cat, imsi, NULL, NULL, sim_mnc_len, NULL, code);
        compare_length = SML_TMO_SIZE_OF_MCC_MNC;       
    }

    //kal_prompt_trace(MOD_SMU,"code : %02x %02x %02x %02x %02x %02x", code[0], code[1], code[2], code[3], code[4], code[5]);
    //kal_prompt_trace(MOD_SMU,"pData: %02x %02x %02x %02x %02x %02x", pData[0], pData[1], pData[2], pData[3], pData[4], pData[5]);
    //kal_prompt_trace(MOD_SMU,"code_len:%d compare_length:%d",code_len,compare_length);

    /* if found match in mcc-mnc, then compare gid if permanent lock */
    num_plmn = sml_GetCount(((*p->getItem)(cat, SML_TMO_CAT_NUM_PLMN, &length, source)));
    pData_plmn = (kal_uint8 *)(*p->getItem)(cat, SML_TMO_CAT_PLMN_LIST, &length, source);    

    SML_TRACE(TRACE_INFO, INFO_SMU_CHECK_LENGTH, code_len, compare_length, sim_mnc_len);

    sml_Dump("code", code, SML_TMO_SIZE_OF_MCC_MNC_GID);
    sml_Dump("plmn list", pData_plmn, (SML_TMO_SIZE_OF_MCC_MNC*num_plmn));
    sml_Dump("gid1 list", pData_gid, (SML_TMO_SIZE_OF_GID*num_gid));
    sml_Dump("ignore list", *custom_exception, (3*SML_TMO_SIZE_OF_MCC_MNC));

    for (i = 0; i < num_plmn; i++)
    {        
        if (kal_mem_cmp(code, (pData_plmn + (i*SML_TMO_SIZE_OF_MCC_MNC)), SML_TMO_SIZE_OF_MCC_MNC) == 0)
        {
            if (compare_length == SML_TMO_SIZE_OF_MCC_MNC)   // partial
            {
                return KAL_TRUE;
            }
            else
            {
                // permanent but ignore gid1
                for (j = 0; j < 3; j++)
                {
                    if (kal_mem_cmp(code, &custom_exception[j], SML_TMO_SIZE_OF_MCC_MNC) == 0)
                    {
                        SML_TRACE(TRACE_INFO, INFO_SMU_CHECK_IGNORE_PID1,
                                        custom_exception[j][0], custom_exception[j][1],
                                        custom_exception[j][2], custom_exception[j][3]);
                        return KAL_TRUE;
                    }
                }

                // no gid should be checked
                if (num_gid == 0)
                {
                    SML_TRACE(TRACE_INFO, INFO_SML_NO_GID);
                    return KAL_TRUE;
                }

                for (j = 0; j < num_gid; j++)
                {
                    if (kal_mem_cmp(&code[SML_TMO_SIZE_OF_MCC_MNC], (pData_gid + (j*SML_TMO_SIZE_OF_GID)), SML_TMO_SIZE_OF_GID) == 0)
                    {
                        return KAL_TRUE;
                    }
                }
            }
        }
    }

    return KAL_FALSE;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_Catcode
 * DESCRIPTION
 *  This function is used to compose the code of each category
 * PARAMETERS
 *  IN          cat
 *  IN          *imsi
 *  IN          *gid1
 *  IN          *gid2
 *  IN          mnc_len
 *  OUT          *code
 * RETURN
 *  kal_uint8   code length
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_uint8 sml_tmo_Catcode( sml_cat_enum cat,
                       kal_uint8 *imsi,
                       kal_uint8 *gid1,
                       kal_uint8 *gid2,
                       kal_uint8 mnc_len,
                       kal_uint8 *code )
{
    kal_uint8 code_len = 0;

    if (imsi == NULL)
    {
        return 0;
    }

    if(mnc_len == 3)
    {
        /* MCC/MNC */
        code[0] = (imsi[1]&0xF0) | (imsi[2]&0x0F);
        code[1] = (imsi[2]&0xF0) | (imsi[3]&0x0F);
        code[2] = (imsi[3]&0xF0) | (imsi[4]&0x0F);
        code[3] = 0;

    }
    else
    {
        /* MCC/MNC */
        code[0] = (imsi[1]&0xF0) | (imsi[2]&0x0F);
        code[1] = (imsi[2]&0xF0) | (imsi[3]&0x0F);
        code[2] = (imsi[3]&0xF0);
        code[3] = 0;
    }

    // TMO use 2 byte GID1
    // if (gid1 != NULL && gid2 != NULL)
    if (gid1 != NULL)
    {
        /* GID */
        code[4] = gid1[0];
        code[5] = gid1[1];
        //code[5] = gid2[0];
        code_len = SML_TMO_SIZE_OF_MCC_MNC_GID;
    }
    else
    {
        code_len = SML_TMO_SIZE_OF_MCC_MNC;
    }

    return code_len;
    
}

/*******************************************************************************
 * FUNCTION
 *  sml_tmo_GetCode
 * DESCRIPTION
 *  This function is used to compose the code of each category  whether 
 *  mnc length is 2 or 3
 * PARAMETERS
 *  cat         [IN]    category of the SIM-ME-Lock
 *  imsi        [IN]    imsi of the code source 
 *  gid1        [IN]    gid1 of the code source
 *  gid2        [IN]    gid2 of the code source
 *  sim_mnc_len [IN]    the mnc length decided by SIM
 *  pdata       [IN]    the saved code for comparing
 *  code        [OUT]   the composed code according to all input parameters
 *
 * RETURN
 *  kal_uint16 file size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/

kal_uint8 sml_tmo_GetCode( sml_cat_enum cat, 
                       kal_uint8 * imsi, 
                       kal_uint8 * gid1, 
                       kal_uint8 * gid2, 
                       kal_uint8 sim_mnc_len, 
                       kal_uint8 * pdata,
                       kal_uint8 * code)
{
    kal_uint8 mnc_len=0;

    if (SML_MNC_LENGTH_NEST == 1)
    {
        mnc_len = sim_mnc_len;
    }
    else
    {
        ASSERT(0); /* It is not possible to tell the MNC lengh in TMO SIM lock blob */
    }

    return sml_tmo_Catcode(cat, imsi, gid1, gid2, mnc_len, code);
}


/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_GetVersion
 * DESCRIPTION
 *  This method is used to get SLB version
 * PARAMETERS
 *  OUT         SLB version
 *  IN          source
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  none
 *******************************************************************************/ 
void sml_tmo_GetVersion(kal_uint8 *version, kal_uint8 source)
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    kal_uint16 length;
    kal_uint8 *slb_ver;

    slb_ver = (kal_uint8 *) (*p->getItem)(SML_CAT_C, SML_TMO_CAT_VERSION, &length, source);

    kal_mem_cpy(version, slb_ver, SML_TMO_SIZE_OF_VERSION);
}

#ifdef __CARRIER_RESTRICTION__
/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_Load
 * DESCRIPTION
 *  This function loads the SML carrier restriction obj from NVRAM LID (NVRAM_READ_CNF)
 * PARAMETERS
 *  IN          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
kal_uint16 sml_crrst_Load( void *pLid, kal_uint8 source )
{
    nvram_ef_smu_crrst_obj_struct *p = &pCRRSTg[source];

    kal_uint16 length = sizeof(smu_carrier_match_context_struct);

    /* Clean the old ones */
    (*p->destory)(source);

    /* Load the new one */
    (*p->give)(pLid, source);

    return length;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_give
 * DESCRIPTION
 *  This method copies the LID files read from NVRAM to the SML Carrier Resriction obj
 * PARAMETERS
 *  IN          * pLidToObj
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
*******************************************************************************/
static void sml_crrst_give( void *pLidToObj, kal_uint8 source )
{
    smu_carrier_match_context_struct * pObj = NULL;

    if(NULL != pCRRSTg[source].pObj)
    {
        pCRRSTg[source].pObj = NULL;
    }

    pObj = &(smu_crrst_cntxt_obj[0]);

    kal_mem_cpy(pObj,
                pLidToObj,
                sizeof(smu_carrier_match_context_struct)
                );

    pCRRSTg[source].pObj = pObj;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_take
 * DESCRIPTION
 *  This method copies the context of the SML Carrier Resriction object to the provided NVRAM LID.
 * PARAMETERS
 *  OUT         * pObjToLid
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/
static void sml_crrst_take( void *pObjToLid, kal_uint8 source )
{
    smu_carrier_match_context_struct * pObj = (smu_carrier_match_context_struct *) pCRRSTg[source].pObj;

    kal_mem_cpy(pObjToLid,
                pObj,
                sizeof(smu_carrier_match_context_struct)
                );
}

/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_destory
 * DESCRIPTION
 *  This method free the SML Carrier Resriction object in memory if it is not used.
 * PARAMETERS
 *  void
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/    
static void sml_crrst_destory(kal_uint8 source)
{
    pCRRSTg[source].pObj = NULL;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_getItem
 * DESCRIPTION
 *  This method returns the structure pointer and length of the structure
 *  of the desired SML Carrier Resriction object items.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  OUT         *length
 * RETURN
 *  void *
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/
static void * sml_crrst_getItem (smu_crrst_cat_enum category,
                           sml_ctx_enum item,
                           kal_uint16 *plength,
                           kal_uint8 source)
{
    smu_carrier_match_context_struct *pObj = (smu_carrier_match_context_struct *) pCRRSTg[source].pObj;
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {

#ifndef __DISABLE_CRRST_LOCK__
        case SMU_CRRST_KEY:

            *plength = sizeof(smu_carrier_match_control_key_struct);

            return (smu_carrier_match_control_key_struct *) &(pObj->key);
#endif

        case SMU_CRRST_BLACK_LIST_META:

            *plength = sizeof(smu_carrier_match_category_meta_struct);

            return (smu_carrier_match_category_meta_struct *) &(pObj->black_list.cat[category]);

        case SMU_CRRST_WHITE_LIST_META:

            *plength = sizeof(smu_carrier_match_category_meta_struct);

            return (smu_carrier_match_category_meta_struct *) &(pObj->white_list.cat[category]);

        case SMU_CRRST_ALLOW_ALL:

            *plength = sizeof(kal_uint8);

            return (kal_uint8 *) &(pObj->allow_all);

        case SMU_CRRST_STATE:

            *plength = sizeof(smu_carrier_restriction_state_enum);

            return (smu_carrier_restriction_state_enum *) &(pObj->carrier_rest_state);

        case SMU_CRRST_MULTI_SIM_POLICY:

            *plength = sizeof(kal_uint8);

            return (kal_uint8 *) &(pObj->multi_sim_policy);

        case SMU_CRRST_ALLOWED_CARRIERS_PRIORITIZED:

            *plength = sizeof(kal_uint8);

            return (kal_uint8 *) &(pObj->allowed_carriers_prioritized);

        default:
            break;
    }

    switch (category)
    {
        case SMU_CRRST_CAT_N:

            *plength = SMU_CARRIER_MATCH_CFG_CAT_N_SIZE;

            if (item == SMU_CRRST_BLACK_LIST)
            {
                return (kal_uint8 *) &(pObj->black_list.code_cat_n[0]);
            }
            else
            {
                return (kal_uint8 *) &(pObj->white_list.code_cat_n[0]);
            }

        case SMU_CRRST_CAT_SPN:

            *plength = SMU_CARRIER_MATCH_CFG_CAT_SPN_SIZE;

            if (item == SMU_CRRST_BLACK_LIST)
            {
                return (kal_uint8 *) &(pObj->black_list.code_cat_spn[0]);
            }
            else
            {
                return (kal_uint8 *) &(pObj->white_list.code_cat_spn[0]);
            }

        case SMU_CRRST_CAT_IMSI_PREFIX:

            *plength = SMU_CARRIER_MATCH_CFG_CAT_IMSI_PREFIX_SIZE;

            if (item == SMU_CRRST_BLACK_LIST)
            {
                return (kal_uint8 *) &(pObj->black_list.code_cat_imsi_prefix[0]);
            }
            else
            {
                return (kal_uint8 *) &(pObj->white_list.code_cat_imsi_prefix[0]);
            }

        case SMU_CRRST_CAT_GID1:

            *plength = SMU_CARRIER_MATCH_CFG_CAT_GID1_SIZE;

            if (item == SMU_CRRST_BLACK_LIST)
            {
                return (kal_uint8 *) &(pObj->black_list.code_cat_gid1[0]);
            }
            else
            {
                return (kal_uint8 *) &(pObj->white_list.code_cat_gid1[0]);
            }

        case SMU_CRRST_CAT_GID2:

            *plength = SMU_CARRIER_MATCH_CFG_CAT_GID2_SIZE;

            if (item == SMU_CRRST_BLACK_LIST)
            {
                return (kal_uint8 *) &(pObj->black_list.code_cat_gid2[0]);
            }
            else
            {
                return (kal_uint8 *) &(pObj->white_list.code_cat_gid2[0]);
            }

        default:
            /* do nothing */
            break;
    }

    return NULL;
}


/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_putItem
 * DESCRIPTION
 *  This method sets the desired items of the SML Carrier Restriction object.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  IN          *pItem
 *  IN          *plength
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
static void sml_crrst_putItem( smu_crrst_cat_enum category,
                         sml_ctx_enum item, 
                         void *pItem, 
                         kal_uint16 *plength,
                         kal_uint8 source)
{
    smu_carrier_match_context_struct *pObj = (smu_carrier_match_context_struct *) pCRRSTg[source].pObj;

    ASSERT(NULL != pObj);

    switch(item)
    {
        case SMU_CRRST_BLACK_LIST_META:
            kal_mem_cpy(&(pObj->black_list.cat[category]),
                        pItem,
                        *plength
                        );
        return;

        case SMU_CRRST_WHITE_LIST_META:
            kal_mem_cpy(&(pObj->white_list.cat[category]),
                        pItem,
                        *plength
                        );
        return;

        case SMU_CRRST_KEY:
            kal_mem_cpy(&(pObj->key),
                        pItem,
                        *plength
                        );
        return;

        case SMU_CRRST_ALLOW_ALL:
            kal_mem_cpy(&(pObj->allow_all),
                         pItem,
                         *plength
                         );
        return;

        case SMU_CRRST_MULTI_SIM_POLICY:
            kal_mem_cpy(&(pObj->multi_sim_policy),
                         pItem,
                         *plength
                         );
        return;

        case SMU_CRRST_ALLOWED_CARRIERS_PRIORITIZED:
            kal_mem_cpy(&(pObj->allowed_carriers_prioritized),
                         pItem,
                         *plength
                         );
        return;

        default:
            break;
    }

    switch (category)
    {
        case SMU_CRRST_CAT_N:
            if (item == SMU_CRRST_BLACK_LIST)
            {
                kal_mem_cpy(&(pObj->black_list.code_cat_n[0]),
                            pItem,
                            *plength
                            );
            }
            else
            {
                kal_mem_cpy(&(pObj->white_list.code_cat_n[0]),
                            pItem,
                            *plength
                            );
            }
            return;

        case SMU_CRRST_CAT_SPN:
            if (item == SMU_CRRST_BLACK_LIST)
            {
                kal_mem_cpy(&(pObj->black_list.code_cat_spn[0]),
                            pItem,
                            *plength
                            );
            }
            else
            {
                kal_mem_cpy(&(pObj->white_list.code_cat_spn[0]),
                            pItem,
                            *plength
                            );
            }
            return;

        case SMU_CRRST_CAT_IMSI_PREFIX:
            if (item == SMU_CRRST_BLACK_LIST)
            {
                kal_mem_cpy(&(pObj->black_list.code_cat_imsi_prefix[0]),
                            pItem,
                            *plength
                            );
            }
            else
            {
                kal_mem_cpy(&(pObj->white_list.code_cat_imsi_prefix[0]),
                            pItem,
                            *plength
                            );
            }
            return;

        case SMU_CRRST_CAT_GID1:
            if (item == SMU_CRRST_BLACK_LIST)
            {
                kal_mem_cpy(&(pObj->black_list.code_cat_gid1[0]),
                            pItem,
                            *plength
                            );
            }
            else
            {
                kal_mem_cpy(&(pObj->white_list.code_cat_gid1[0]),
                            pItem,
                            *plength
                            );
            }
            return;

        case SMU_CRRST_CAT_GID2:
            if (item == SMU_CRRST_BLACK_LIST)
            {
                kal_mem_cpy(&(pObj->black_list.code_cat_gid2[0]),
                            pItem,
                            *plength
                            );
            }
            else
            {
                kal_mem_cpy(&(pObj->white_list.code_cat_gid2[0]),
                            pItem,
                            *plength
                            );
            }
        return;

        default:
            break;
    }

}

/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_Catcode
 * DESCRIPTION
 *  This function is used to compose the code of each category
 * PARAMETERS
 *  IN          cat
 *  IN          *imsi
 *  IN          *gid1
 *  IN          *gid2
 *  IN          mnc_len
 *  OUT          *code
 * RETURN
 *  kal_uint8   code length
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_uint8 sml_crrst_Catcode( smu_crrst_cat_enum cat,
                       kal_uint8 *imsi,
                       kal_uint8 *gid1,
                       kal_uint8 *gid2,
                       kal_uint8 *spn,
                       kal_uint8 mnc_len,
                       kal_uint8 *code )
{
    kal_uint8 i,j=0;

    if(mnc_len == 3)
    {
        code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);
        code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);
        code[2] = (imsi[3] & 0xF0) | (imsi[4] & 0x0F);
        code[3] = (imsi[4] & 0xF0) | (imsi[5] & 0x0F);
    }
    else
    {
        code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);
        code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);
        code[2] = (imsi[3] & 0xF0) | 0x0F;
        code[3] = ((imsi[4] & 0x0F) << 4) | ((imsi[4] & 0xF0) >> 4);
    }

    switch(cat)
    {
        case SMU_CRRST_CAT_N:
            return SMU_CARRIER_MATCH_SIZE_OF_CAT_N;
        break;

        case SMU_CRRST_CAT_SPN:
            if (spn)
            {
                i=0;
                j=3;
                while (spn[i] != 0xff)
                {
                    code[j++] = spn[i++];
                }
                return SMU_CARRIER_MATCH_SIZE_OF_CAT_SPN;
            }
        break;

        case SMU_CRRST_CAT_IMSI_PREFIX:
            return SMU_CARRIER_MATCH_SIZE_OF_CAT_IMSI_PREFIX;
        break;

        case SMU_CRRST_CAT_GID1:
            if (gid1)
            {
                code[3] = gid1[0];
                return SMU_CARRIER_MATCH_SIZE_OF_CAT_GID1;
            }
        break;

        case SMU_CRRST_CAT_GID2:
            if (gid2)
            {
                code[3] = gid2[0];
                return SMU_CARRIER_MATCH_SIZE_OF_CAT_GID2;
            }
        break;

        default:
        break;
    }

    return 0;
}

/*******************************************************************************
 * FUNCTION
 *  sml_crrst_GetCode
 * DESCRIPTION
 *  This function is used to compose the code of each category  whether 
 *  mnc length is 2 or 3
 * PARAMETERS
 *  cat         [IN]    category of the Carrier Restriction lock
 *  imsi        [IN]    imsi of the code source 
 *  gid1        [IN]    gid1 of the code source
 *  gid2        [IN]    gid2 of the code source
 *  sim_mnc_len [IN]    the mnc length decided by SIM
 *  pdata       [IN]    the saved code for comparing
 *  code        [OUT]   the composed code according to all input parameters
 *
 * RETURN
 *  kal_uint16 file size
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/
kal_uint8 sml_crrst_GetCode( smu_crrst_cat_enum cat, 
                       kal_uint8 * imsi, 
                       kal_uint8 * gid1, 
                       kal_uint8 * gid2, 
                       kal_uint8 * spn,
                       kal_uint8 sim_mnc_len, 
                       kal_uint8 * pdata,
                       kal_uint8 * code)
{
    kal_uint8 mnc_len=0;

    if (SML_MNC_LENGTH_NEST == 1)
    {
        mnc_len = sim_mnc_len;
    }
    else
    {
        if(((*(pdata+2)) & 0x0F) == 0x0F)
        {
            mnc_len = 2;
        }
        else
        {
            mnc_len = 3;
        }
    }
    return sml_crrst_Catcode(cat, imsi, gid1, gid2, spn, mnc_len, code);
}


/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_getList
 * DESCRIPTION
 *  This method returns the requested list
 * PARAMETERS
 *  IN          list
 *  OUT         *length
 * RETURN
 *  void *
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/
static void * sml_crrst_getList (sml_ctx_enum list,
                           kal_uint16 *plength,
                           kal_uint8 source)
{
    smu_carrier_match_context_struct *pObj = (smu_carrier_match_context_struct *) pCRRSTg[source].pObj;
    
    ASSERT(NULL != pObj);
    
    switch(list)
    {
        case SMU_CRRST_BLACK_LIST:

            *plength = sizeof(smu_carrier_restriction_list_struct);

            return (smu_carrier_restriction_list_struct *) &(pObj->black_list);

        case SMU_CRRST_WHITE_LIST:

            *plength = sizeof(smu_carrier_restriction_list_struct);

            return (smu_carrier_restriction_list_struct *) &(pObj->white_list);

        default:
            break;
    }

    return NULL;
}

/*******************************************************************************
 * FUNCTION  
 *  smu_crrst_Check
 * DESCRIPTION
 *  This function is used to check if the code is in the carrier restriction list
 * PARAMETERS
 *  IN          cat
 *  IN          *imsi
 *  IN          *gid1
 *  IN          *gid2
 *  IN          sim_mnc_len
 *  IN          source
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
kal_bool sml_crrst_Check(sml_ctx_enum list,   // blacklist or whitelist
                    smu_crrst_cat_enum cat,       // category
                    kal_uint8 *imsi,        // 9 bytes array, read from SIM, mandatory file
                    kal_uint8 *gid1,        // 20 bytes array, read from SIM, NULL means gid1 invalid(file not exist)
                    kal_uint8 *gid2,        // 20 bytes array, read from SIM, NULL means gid2 invalid(file not exist)
                    kal_uint8 *spn,         // 17 bytes array, read from SIM, NULL means spn invalid(file not exist)
                    kal_uint8 sim_mnc_len,  // MNC length, read from SIM
                    kal_uint8 source)       // 0:SIM1, 1:SIM2
{
    nvram_ef_smu_crrst_obj_struct *p = &pCRRSTg[source];
    smu_carrier_match_category_meta_struct *meta = NULL;
    kal_uint8 *pdata = NULL;
    kal_uint8 idx = 0;
    kal_uint16 length = 0, offset = 0; 
    kal_bool result = KAL_FALSE;
    kal_uint8 code_len = 0;
    kal_uint8 code[23] = {0};
    kal_uint8 size_of_cat = 0;
    sml_ctx_enum meta_list;

    meta_list = (list == SMU_CRRST_BLACK_LIST ? SMU_CRRST_BLACK_LIST_META : SMU_CRRST_WHITE_LIST_META);
    meta = (smu_carrier_match_category_meta_struct *) (*p->getItem)(cat, meta_list, &length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat, list, &length, source);
    kal_mem_set(code, 0xFF, 23);

    switch(cat)
    {
        case SMU_CRRST_CAT_N:
        {
            size_of_cat = SMU_CARRIER_MATCH_SIZE_OF_CAT_N;
            break;
        }
        case SMU_CRRST_CAT_SPN:
        {
            size_of_cat = SMU_CARRIER_MATCH_SIZE_OF_CAT_SPN;
            break;
        }
        case SMU_CRRST_CAT_IMSI_PREFIX:
        {
            size_of_cat = SMU_CARRIER_MATCH_SIZE_OF_CAT_IMSI_PREFIX;
            break;
        }
        case SMU_CRRST_CAT_GID1:
        {
            size_of_cat = SMU_CARRIER_MATCH_SIZE_OF_CAT_GID1;
            break;
        }
        case SMU_CRRST_CAT_GID2:
        {
            size_of_cat = SMU_CARRIER_MATCH_SIZE_OF_CAT_GID2;
            break;
        }
        default:
            break;
    }

    for (idx = 0; idx < meta->num; idx++)
    {
        offset = idx * size_of_cat;
        code_len = sml_crrst_GetCode(cat,
                               imsi,
                               gid1,
                               gid2,
                               spn,
                               sim_mnc_len, 
                               (pdata+offset),
                               code);
        
        if (size_of_cat == code_len)
        {
            /* MCC/MNC/HLR can have wildcard character - f */
            kal_uint8 *pdata_ptr = NULL;
            kal_uint8 i = 0;
            kal_uint8 len = 0;

            pdata_ptr = (kal_uint8 *)(pdata+offset);
            if (cat == SMU_CRRST_CAT_IMSI_PREFIX)
            {
                len = SMU_CARRIER_MATCH_SIZE_OF_CAT_IMSI_PREFIX; /* MCC/MNC + HLR */
            }
            else
            {
                len = SMU_CARRIER_MATCH_SIZE_OF_CAT_N; /* MCC/MNC common for all categories */
            }

            for (i=0; i<len; i++)
            {
                if ((pdata_ptr[i] & 0xF0) == 0xF0)
                {
                    code[i] |= 0xF0;
                }

                if ((pdata_ptr[i] & 0x0F) == 0x0F)
                {
                    code[i] |= 0x0F;
                }
            }

            if (kal_mem_cmp(code, (pdata+offset), code_len)==0)
            {
                result = KAL_TRUE;
                break;
            }
        }
    }
    
    return result;
}

#ifndef __DISABLE_CRRST_LOCK__
/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_Unlock
 * DESCRIPTION
 *  This function unlock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 *  IN          source
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
kal_bool sml_crrst_Unlock(kal_uint8 *key, 
                     kal_uint8 key_len,
                     kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct *p = &pCRRSTg[source];
    smu_carrier_match_control_key_struct *crrst_key = NULL;
    kal_uint16 length = 0;
    kal_bool result = KAL_FALSE;

    crrst_key = (smu_carrier_match_control_key_struct *) (*p->getItem)(0, SMU_CRRST_KEY,&length, source);

    if (crrst_key->state == SMU_CRRST_KEY_STATE_LOCKED)
    {
        if(kal_mem_cmp(crrst_key->key,key,key_len) == 0)
        {
            result = KAL_TRUE;
            crrst_key->state = SMU_CRRST_KEY_STATE_UNLOCKED;
        }
    }

    return result;
}
#endif /* __DISABLE_CRRST_LOCK__ */

/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_Lock
 * DESCRIPTION
 *  This function Lock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
kal_bool sml_crrst_Lock(kal_uint8 *key, 
                   kal_uint8 key_len,
                   kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct *p = &pCRRSTg[source];
    smu_carrier_match_control_key_struct *crrst_key = NULL;
    kal_uint16 length = 0;

    crrst_key = (smu_carrier_match_control_key_struct *) (*p->getItem)(0, SMU_CRRST_KEY,&length, source); 

    if (crrst_key->state == SMU_CRRST_KEY_STATE_LOCKED)
    {
        return KAL_FALSE;
    }

    kal_mem_cpy(crrst_key->key, key, key_len);
    crrst_key->state = SMU_CRRST_KEY_STATE_LOCKED;

    return KAL_TRUE;
}

 /*******************************************************************************
  * FUNCTION  
  *  sml_crrst_Add
  * DESCRIPTION
  *  This function is used to add code into the desired category
  * PARAMETERS
  *  IN 		 cat
  *  IN 		 * code
  *  IN 		 len
  *  OUT		 * remain
  * RETURN
  *  kal_bool
  * GLOBALS AFFECTED
  *  SMU_CRRST_OBJ
  *******************************************************************************/ 
kal_bool sml_crrst_Add( smu_crrst_cat_enum cat, 
                   kal_uint8 list,
                   kal_uint8 *code, 
                   kal_uint8 len,
                   kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct *p = &pCRRSTg[source];
    smu_carrier_match_category_meta_struct *meta = NULL;
    kal_uint8 *pdata = NULL;
    kal_uint8 remain = 0;
    kal_uint16 length = 0, offset = 0;
    kal_bool result = KAL_FALSE;
    sml_ctx_enum crrst_list, meta_list;

#ifndef __DISABLE_CRRST_LOCK__
    smu_carrier_match_control_key_struct *crrst_key = NULL;

    crrst_key = (smu_carrier_match_control_key_struct *) (*p->getItem)(cat,SMU_CRRST_KEY,&length, source);
    if (crrst_key->state == SMU_CRRST_KEY_STATE_LOCKED)
    {
        return KAL_FALSE;
    }
#endif

    crrst_list = (list == 0 ? SMU_CRRST_WHITE_LIST : SMU_CRRST_BLACK_LIST);
    meta_list = (crrst_list == SMU_CRRST_WHITE_LIST ? SMU_CRRST_WHITE_LIST_META : SMU_CRRST_BLACK_LIST_META);

    meta = (smu_carrier_match_category_meta_struct *) (*p->getItem)(cat,meta_list,&length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat,crrst_list,&length, source);

    switch(cat)
    {
        case SMU_CRRST_CAT_N:
            offset = (meta->num) * SMU_CARRIER_MATCH_SIZE_OF_CAT_N;
            remain = (length - offset) / SMU_CARRIER_MATCH_SIZE_OF_CAT_N;
        break;

        case SMU_CRRST_CAT_SPN:
            offset = (meta->num) * SMU_CARRIER_MATCH_SIZE_OF_CAT_SPN;
            remain = (length - offset) / SMU_CARRIER_MATCH_SIZE_OF_CAT_SPN;
        break;

        case SMU_CRRST_CAT_IMSI_PREFIX:
            offset = (meta->num) * SMU_CARRIER_MATCH_SIZE_OF_CAT_IMSI_PREFIX; 	   
            remain = (length - offset) / SMU_CARRIER_MATCH_SIZE_OF_CAT_IMSI_PREFIX;
        break;
 
        case SMU_CRRST_CAT_GID1:
            offset = (meta->num) * SMU_CARRIER_MATCH_SIZE_OF_CAT_GID1;
            remain = (length - offset) / SMU_CARRIER_MATCH_SIZE_OF_CAT_GID1;
        break;
 
        case SMU_CRRST_CAT_GID2:
            offset = (meta->num) * SMU_CARRIER_MATCH_SIZE_OF_CAT_GID2;
            remain = (length - offset) / SMU_CARRIER_MATCH_SIZE_OF_CAT_GID2;
        break;

        default:
        break;
    }

    if (remain > 0)
    {
        kal_mem_cpy((kal_uint8 *)(pdata+offset), code, len);
        meta->num ++;
        result = KAL_TRUE;
    }
    else
    {
        result = KAL_FALSE;
    }

    return result;
}
  
/*******************************************************************************
* FUNCTION	
*  sml_crrst_Remove
* DESCRIPTION
*  This function is used to remove code from the desired category
* PARAMETERS
*  IN   cat
*  IN   * code
*  IN   len
*  OUT   * remain
* RETURN
*  kal_bool
* GLOBALS AFFECTED
*  SMU_CRRST_OBJ
*******************************************************************************/ 
kal_bool sml_crrst_Remove( smu_crrst_cat_enum cat, 
                                kal_uint8 list,
                                kal_uint8 *code, 
                                kal_uint8 len,
                                kal_uint8 source)
{
    /* Currently AP does not use this interface of removing specific BlackList data. Reserved for future use */

    return KAL_FALSE;
}


/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_Disable
 * DESCRIPTION
 *  This function is used to disable the carrier restriction facility
 * PARAMETERS
 *  IN          cat
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
kal_bool sml_crrst_Disable(kal_uint8 *key,kal_uint8 key_len,kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct *p = &pCRRSTg[source];
    kal_uint16 length = 0; 
    smu_carrier_restriction_state_enum *state = NULL;

#ifndef __DISABLE_CRRST_LOCK__
    smu_carrier_match_control_key_struct *crrst_key = NULL;

    crrst_key = (smu_carrier_match_control_key_struct *) (*p->getItem)(0,SMU_CRRST_KEY,&length, source);

    ASSERT( key_len <= SML_MAX_SUPPORT_KEY_LEN );

    if (SMU_CRRST_KEY_STATE_LOCKED == crrst_key->state)
    {
        if (0 != kal_mem_cmp(crrst_key->key,key,key_len))
        {
            return KAL_FALSE;
        }
    }
#endif

    state = (smu_carrier_restriction_state_enum *) (*p->getItem)(0,SMU_CRRST_STATE,&length, source);
    *state = SMU_CARRIER_RESTRICTION_DISABLED;

    return KAL_TRUE;
}
 
/*******************************************************************************
* FUNCTION  
*  sml_crrst_Enable
* DESCRIPTION
*  This function is used to enable the carrier restriction facility
* PARAMETERS
*  IN 		 cat
* RETURN
*  kal_bool
* GLOBALS AFFECTED
*  SMU_CRRST_OBJ
*******************************************************************************/ 
kal_bool sml_crrst_Enable(kal_uint8 *key,kal_uint8 key_len,kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct *p = &pCRRSTg[source];
    kal_uint16 length = 0; 
    smu_carrier_restriction_state_enum *state = NULL;

#ifndef __DISABLE_CRRST_LOCK__
    smu_carrier_match_control_key_struct *crrst_key = NULL;

    crrst_key = (smu_carrier_match_control_key_struct *) (*p->getItem)(0,SMU_CRRST_KEY,&length, source);

    ASSERT( key_len <= SML_MAX_SUPPORT_KEY_LEN );

    if (SMU_CRRST_KEY_STATE_LOCKED == crrst_key->state)
    {
        if (0 != kal_mem_cmp(crrst_key->key,key,key_len))
        {
            return KAL_FALSE;
        }
    }
#endif

    state = (smu_carrier_restriction_state_enum *) (*p->getItem)(0,SMU_CRRST_STATE,&length, source);
    *state = SMU_CARRIER_RESTRICTION_ENABLED;

    return KAL_TRUE;
}


/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_Remove_All
 * DESCRIPTION
 *  This function is used to remove all the carrier restriction data
 * PARAMETERS
 *  IN          cat
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
kal_bool sml_crrst_Remove_All(kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct * p = &pCRRSTg[source];
    smu_carrier_match_category_meta_struct * meta = NULL;
    kal_uint8 * pdata = NULL;
    kal_uint16 length = 0;
    kal_uint8 i = 0;

#ifndef __DISABLE_CRRST_LOCK__
    smu_carrier_match_control_key_struct *crrst_key = NULL;

    crrst_key = (smu_carrier_match_control_key_struct *) (*p->getItem)(0,SMU_CRRST_KEY,&length, source);
    if (crrst_key->state == SMU_CRRST_KEY_STATE_LOCKED)
    {
        return KAL_FALSE;
    }
#endif

    for (i=SMU_CRRST_CAT_N; i<SMU_CRRST_CAT_SIZE; i++)
    {
        meta = (smu_carrier_match_category_meta_struct *) (*p->getItem)(i,SMU_CRRST_BLACK_LIST_META,&length, source);
        pdata = (kal_uint8 *) (*p->getItem)(i,SMU_CRRST_BLACK_LIST,&length, source);
        kal_mem_set(pdata,0xFF,length);
        meta->num = 0;

        meta = (smu_carrier_match_category_meta_struct *) (*p->getItem)(i,SMU_CRRST_WHITE_LIST_META,&length, source);
        pdata = (kal_uint8 *) (*p->getItem)(i,SMU_CRRST_WHITE_LIST,&length, source);
        kal_mem_set(pdata,0xFF,length);
        meta->num = 0;
    }

    return KAL_TRUE;
}


/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_Remove_WhiteList
 * DESCRIPTION
 *  This function is used to remove all white list carrier restriction data
 * PARAMETERS
 *  IN          cat
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
kal_bool sml_crrst_Remove_WhiteList(kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct * p = &pCRRSTg[source];
    smu_carrier_match_category_meta_struct * meta = NULL;
    kal_uint8 * pdata = NULL;
    kal_uint16 length = 0;
    kal_uint8 i = 0;

#ifndef __DISABLE_CRRST_LOCK__
    smu_carrier_match_control_key_struct *crrst_key = NULL;

    crrst_key = (smu_carrier_match_control_key_struct *) (*p->getItem)(0,SMU_CRRST_KEY,&length, source);
    if (crrst_key->state == SMU_CRRST_KEY_STATE_LOCKED)
    {
        return KAL_FALSE;
    }
#endif

    for (i=SMU_CRRST_CAT_N; i<SMU_CRRST_CAT_SIZE; i++)
    {
        meta = (smu_carrier_match_category_meta_struct *) (*p->getItem)(i,SMU_CRRST_WHITE_LIST_META,&length, source);
        pdata = (kal_uint8 *) (*p->getItem)(i,SMU_CRRST_WHITE_LIST,&length, source);
        kal_mem_set(pdata,0xFF,length);
        meta->num = 0;
    }

    return KAL_TRUE;
}


/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_Remove_BlackList
 * DESCRIPTION
 *  This function is used to remove all black list carrier restriction data
 * PARAMETERS
 *  IN          cat
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
kal_bool sml_crrst_Remove_BlackList(kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct * p = &pCRRSTg[source];
    smu_carrier_match_category_meta_struct * meta = NULL;
    kal_uint8 * pdata = NULL;
    kal_uint16 length = 0;
    kal_uint8 i = 0;

#ifndef __DISABLE_CRRST_LOCK__
    smu_carrier_match_control_key_struct *crrst_key = NULL;

    crrst_key = (smu_carrier_match_control_key_struct *) (*p->getItem)(0,SMU_CRRST_KEY,&length, source);
    if (crrst_key->state == SMU_CRRST_KEY_STATE_LOCKED)
    {
        return KAL_FALSE;
    }
#endif

    for (i=SMU_CRRST_CAT_N; i<SMU_CRRST_CAT_SIZE; i++)
    {
        meta = (smu_carrier_match_category_meta_struct *) (*p->getItem)(i,SMU_CRRST_BLACK_LIST_META,&length, source);
        pdata = (kal_uint8 *) (*p->getItem)(i,SMU_CRRST_BLACK_LIST,&length, source);
        kal_mem_set(pdata,0xFF,length);
        meta->num = 0;
    }

    return KAL_TRUE;
}


/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_Save
 * DESCRIPTION
 *  This function saves the SMU_CRRST_OBJ to NVRAM LID (NVRAM_WRITE_REQ)
 * PARAMETERS
 *  OUT          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
kal_uint16 sml_crrst_Save( void *pLid, kal_uint8 source )
{
    nvram_ef_smu_crrst_obj_struct *p = &pCRRSTg[source];
    kal_uint16 length = sizeof(smu_carrier_match_context_struct);

    (*p->take)(pLid, source);

    return length;
}


 /*******************************************************************************
  * FUNCTION  
  *  sml_crrst_Status
  * DESCRIPTION
  *  This function is used to retrieve the carrier restriction data
  * PARAMETERS
  *  IN 		 cat
  *  IN 		 * code
  *  IN 		 len
  *  OUT		 * remain
  * RETURN
  *  kal_bool
  * GLOBALS AFFECTED
  *  SMU_CRRST_OBJ
  *******************************************************************************/ 
kal_bool sml_crrst_Status(smu_crrst_state_enum *state,
                   kal_uint8 *multi_sim_policy,
                   kal_uint8 *allowed_carriers_prioritized,
                   smu_carrier_restriction_list_struct *white_list,
                   smu_carrier_restriction_list_struct *black_list,
                   kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct *p = &pCRRSTg[source];
    kal_uint16 length = 0;
    smu_carrier_match_control_key_struct *crrst_key = NULL;
    smu_carrier_restriction_state_enum *crrst_state = NULL;
    smu_carrier_restriction_list_struct *list = NULL;
    kal_uint8 *mcp = NULL;
    kal_uint8 *acp = NULL;

    crrst_state = (smu_carrier_restriction_state_enum *) (*p->getItem)(0, SMU_CRRST_STATE, &length, source);
    if (*crrst_state == SMU_CARRIER_RESTRICTION_ENABLED)
    {
        crrst_key = (smu_carrier_match_control_key_struct *) (*p->getItem)(0,SMU_CRRST_KEY,&length, source);
        if (crrst_key->state == SMU_CRRST_KEY_STATE_LOCKED)
        {
            *state = SMU_CRRST_STATE_LOCKED;
        }
        else
        {
            *state = SMU_CRRST_STATE_UNLOCKED;
        }
    }
    else
    {
        *state = SMU_CRRST_STATE_DISABLED;
        return KAL_TRUE;
    }

    mcp = (kal_uint8 *) (*p->getItem)(0,SMU_CRRST_MULTI_SIM_POLICY,&length, source);
    *multi_sim_policy = *mcp;
    acp = (kal_uint8 *)(*p->getItem)(0, SMU_CRRST_ALLOWED_CARRIERS_PRIORITIZED, &length, source);
    *allowed_carriers_prioritized = *acp;

    list = (smu_carrier_restriction_list_struct *)(*p->getList)(SMU_CRRST_WHITE_LIST, &length, source);
    kal_mem_cpy(white_list, list, length);

    list = (smu_carrier_restriction_list_struct *)(*p->getList)(SMU_CRRST_BLACK_LIST, &length, source);
    kal_mem_cpy(black_list, list, length);

    return KAL_TRUE;
}


/*******************************************************************************
 * FUNCTION  
 *  sml_crrst_Update_MSP_ACP
 * DESCRIPTION
 *  This function is used to update multi SIM policy and allowed carriers prioritized data
 * PARAMETERS
 *  IN          source
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMU_CRRST_OBJ
 *******************************************************************************/ 
kal_bool sml_crrst_Update_MSP_ACP(kal_uint8 *key,
                                           kal_uint8 key_len,
                                           kal_uint8 multi_sim_policy,
                                           kal_uint8 allowed_carriers_prioritized,
                                           kal_uint8 source)
{
    nvram_ef_smu_crrst_obj_struct * p = &pCRRSTg[source];
#ifndef __DISABLE_CRRST_LOCK__
    kal_uint16 length = 0;
#endif
    kal_uint16 plength = 0;

#ifndef __DISABLE_CRRST_LOCK__
    smu_carrier_match_control_key_struct *crrst_key = NULL;

    crrst_key = (smu_carrier_match_control_key_struct *) (*p->getItem)(0,SMU_CRRST_KEY,&length, source);

    ASSERT( key_len <= SML_MAX_SUPPORT_KEY_LEN );

    if (SMU_CRRST_KEY_STATE_LOCKED == crrst_key->state)
    {
        if (0 != kal_mem_cmp(crrst_key->key,key,key_len))
        {
            return KAL_FALSE;
        }
    }
#endif

    plength = sizeof(multi_sim_policy);
    (*p->putItem)(0, SMU_CRRST_MULTI_SIM_POLICY, &multi_sim_policy, &plength, source);

    plength = sizeof(allowed_carriers_prioritized);
    (*p->putItem)(0, SMU_CRRST_ALLOWED_CARRIERS_PRIORITIZED, &allowed_carriers_prioritized, &plength, source);

    return KAL_TRUE;
}

#endif /* __CARRIER_RESTRICTION__ */

/*******************************************************************************
 * FUNCTION  
 *  sml_GetLockState
 * DESCRIPTION
 *  This method is used to get SLB lock state
 * PARAMETERS
 *  OUT       lock state
 *  IN          source
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  none
 *******************************************************************************/ 
void sml_GetLockState(kal_uint8 *lock_state, kal_uint8 source)
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    kal_uint16 length;
    kal_uint8 *slb_state;

    slb_state = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_STATE, &length, source);  // First param is not used in TMO 

    kal_mem_cpy(lock_state, slb_state, 1);
}


/*******************************************************************************
 * FUNCTION  
 *  sml_GetUnlockTimeLeft
 * DESCRIPTION
 *  This method is used to get SLB unlock time left in seconds
 * PARAMETERS
 *  IN          source
 * RETURN
 *  unlock time left
 * GLOBALS AFFECTED
 *  none
 *******************************************************************************/ 
kal_uint32 sml_GetUnlockTimeLeft(kal_uint8 source)
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    kal_uint16 length;
    kal_uint8 *slb_end_time;
    kal_uint32 duration_seconds = 0;
    kal_uint8 i;

    slb_end_time = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_END_TIME, &length, source); // First param is not used in TMO

    for (i = 0; i < (SML_TMO_SIZE_OF_END_TIME - 1); i++)
    {
        duration_seconds += slb_end_time[i];
        duration_seconds = (duration_seconds << 8);
    }
    duration_seconds += slb_end_time[SML_TMO_SIZE_OF_END_TIME-1];

    SML_TRACE(TRACE_INFO, INFO_SMU_GET_UNLOCK_TIME_LEFT, duration_seconds, sml_tmo_seconds_to_expire);

    if (sml_tmo_seconds_to_expire >= duration_seconds)
    {
        return 0;
    }
    else
    {
        return (duration_seconds - sml_tmo_seconds_to_expire);
    }
}


// TMO SML --- end


/*******************************************************************************
 * FUNCTION  
 *  sml_give
 * DESCRIPTION
 *  This method copys the LID files read from NVRAM to the SML obj
 * PARAMETERS
 *  IN          * pLidToObj
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
static void sml_give( void *pLidToObj, kal_uint8 source )
{
    
    kal_uint32 magic_head = 0;
    
    kal_uint32 magic_tail = 0;
    
    sml_context_struct * pObj = NULL;
  
    if(NULL != pSMLg[source].pObj)
    {
    
        kal_sys_trace("SML: object is exist!");
    
//        free_ctrl_buffer(pSMLg[source].pObj);
        
        pSMLg[source].pObj = NULL;
    
    }
       
//  pObj = (sml_context_struct *) get_ctrl_buffer(sizeof(sml_context_struct));
    pObj = &(sml_cntxt_obj[source]);
    
    kal_mem_cpy(pObj,
                pLidToObj,
                sizeof(sml_context_struct)
                ); 
    
    /* Check magic head and tail */
    magic_head = pObj->magic_head;
    
    magic_tail = pObj->magic_tail;

#ifdef __MTK_TARGET__
//  Mark for temporary solution of SIM-ME-Lock
    ASSERT((magic_head == sizeof(sml_context_struct))
           && (magic_tail == SML_MAGIC_TAIL_VALUE));
#endif
    pSMLg[source].pObj = pObj;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_take
 * DESCRIPTION
 *  This method copys the contex of the SML object to the provided NVRAM LID.
 * PARAMETERS
 *  OUT         * pObjToLid
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
static void sml_take( void *pObjToLid, kal_uint8 source )
{
    
//    kal_uint32 magic_head = 0;
    
//    kal_uint32 magic_tail = 0;
   
    sml_context_struct * pObj = (sml_context_struct *) pSMLg[source].pObj;
     
    /* Check magic head and tail */
//    magic_head = pObj->magic_head;
    
//    magic_tail = pObj->magic_tail;

//  Mark for temporary solution of SIM-ME-Lock
//    ASSERT((magic_head == SML_MAGIC_HEAD_VALUE)
//           && (magic_tail == SML_MAGIC_TAIL_VALUE));
           
    kal_mem_cpy(pObjToLid,
                pObj,
                sizeof(sml_context_struct)
                );

} 

/*******************************************************************************
 * FUNCTION  
 *  sml_destory
 * DESCRIPTION
 *  This method free the SML object in memory if it is not used.
 * PARAMETERS
 *  void
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/    
static void sml_destory(kal_uint8 source)
{
#if 0
/* under construction !*/
/* under construction !*/
#endif

    pSMLg[source].pObj = NULL;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_getItem
 * DESCRIPTION
 *  This method returns the structure pointer and length of the structure
 *  of the desired SML object items.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  OUT         *length
 * RETURN
 *  void *
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
static void * sml_getItem( sml_cat_enum category, 
                           sml_ctx_enum item, 
                           kal_uint16 *plength,
                           kal_uint8 source)
{
    sml_context_struct *pObj = (sml_context_struct *) pSMLg[source].pObj;
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {
        
        case SML_MAGIC_HEAD:
        
        case SML_MAGIC_TAIL:
        
            //ASSERT(0);
        
            break;
        
        case SML_CAT_META:
        
            *plength = sizeof(sml_category_meta_struct);
        
            return (sml_category_meta_struct *) &(pObj->cat[category]);
        
            break;
        
        case SML_CAT_KEY:
        
            *plength = sizeof(sml_control_key_struct);
        
            return (sml_control_key_struct *) &(pObj->key[category]);
        
            break;
        
        case SML_CAT_CODE:
        
            switch(category)
            {
        
                case SML_CAT_N:
        
                    *plength = SML_CFG_CAT_N_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_n[0]);
        
                    break;
        
                case SML_CAT_NS:
        
                    *plength = SML_CFG_CAT_NS_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_ns[0]);
        
                    break;
        
                case SML_CAT_SP:
        
                    *plength = SML_CFG_CAT_SP_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_sp[0]);
        
                    break;
        
                case SML_CAT_C:
        
                    *plength = SML_CFG_CAT_C_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_c[0]);
        
                    break;
        
                case SML_CAT_SIM:
        
                    *plength = SML_CFG_CAT_SIM_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_sim[0]);
        
                    break;
        
                case SML_CAT_NS_SP:
        
                    *plength = SML_CFG_CAT_NS_SP_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_ns_sp[0]);
        
                    break;
        
                case SML_CAT_SIM_C:
        
                    *plength = SML_CFG_CAT_SIM_C_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_sim_c[0]);
        
                    break;

                default:
                    /* do nothing */
                    break;
            }
        
            break;
        
        case SML_CAT_RANGE:
        
            switch(category)
            {

                case SML_CAT_N:
                    
                    *plength = 0;
                    
                    return NULL;
                    
                    break;

                case SML_CAT_NS:
                    
                    *plength = SML_CAT_NS_RANGE_SIZE;
                    
                    return (kal_uint8 *) &(pObj->range_cat_ns[0]);

                    break;

                case SML_CAT_SP:

                    *plength = 0;
                    
                    return NULL;
                    
                    break;

                case SML_CAT_C:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                case SML_CAT_SIM:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                case SML_CAT_NS_SP:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                case SML_CAT_SIM_C:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                default:
                    /* do nothing */
                    break;

            }            

            break;
#ifdef __SIMME_LOCK_RELATIONSHIP__
		case SML_CTX_DUAL_SIM_LOCK_CONTROL:

				*plength = sizeof(pObj->dual_sim_lock_control);

				return (kal_uint8 *) &(pObj->dual_sim_lock_control);

			break;
#endif

        default:
                
            break;   

    }

    return NULL;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_putItem
 * DESCRIPTION
 *  This method set the desired items of the SML object.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  IN          *pItem
 *  IN          *plength
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
static void sml_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void *pItem, 
                         kal_uint16 *plength,
                         kal_uint8 source)
{
    sml_context_struct *pObj = (sml_context_struct *) pSMLg[source].pObj;
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {
        
        case SML_MAGIC_HEAD:
        
        case SML_MAGIC_TAIL:
        
            //ASSERT(0);
        
            break;
        
        case SML_CAT_META:
        
            //ASSERT(*plength == sizeof(sml_category_meta_struct));
            
            kal_mem_cpy(&(pObj->cat[cat]),
                        pItem,
                        *plength
                        );
        
            break;
        
        case SML_CAT_KEY:
        
            //ASSERT(*plength == sizeof(sml_control_key_struct));
        
            kal_mem_cpy(&(pObj->key[cat]),
                        pItem,
                        *plength
                        );
        
            break;
        
        case SML_CAT_CODE:
        
            switch(cat)
            {
        
                case SML_CAT_N:
        
                    //ASSERT(*plength <= SML_CFG_CAT_N_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_n[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_NS:
        
                    //ASSERT(*plength <= SML_CFG_CAT_NS_SIZE);
                    
                    kal_mem_cpy(&(pObj->code_cat_ns[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_SP:
        
                    //ASSERT(*plength <= SML_CFG_CAT_SP_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_sp[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_C:
        
                    //ASSERT(*plength <= SML_CFG_CAT_C_SIZE);
                            
                    kal_mem_cpy(&(pObj->code_cat_c[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_SIM:
        
                    //ASSERT(*plength <= SML_CFG_CAT_SIM_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_sim[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_NS_SP:
        
                    //ASSERT(*plength <= SML_CFG_CAT_NS_SP_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_ns_sp[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_SIM_C:
        
                    //ASSERT(*plength <= SML_CFG_CAT_SIM_C_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_sim_c[0]),
                                pItem,
                                *plength
                                );
        
                    break;

                default:
                    /* do nothing */
                    break;
            }
        
            break;
        
        case SML_CAT_RANGE:
        
            switch(cat)
            {

                case SML_CAT_N:

                    break;

                case SML_CAT_NS:

                    //ASSERT(*plength <= SML_CAT_NS_RANGE_SIZE);
                    
                    kal_mem_cpy(&(pObj->range_cat_ns[0]),
                                pItem,
                                *plength
                                );

                    break;

                case SML_CAT_SP:

                    break;

                case SML_CAT_C:

                    break;

                case SML_CAT_SIM:

                    break;

                case SML_CAT_NS_SP:

                    break;

                case SML_CAT_SIM_C:

                    break;

                default:
                    /* do nothing */
                    break;

            }            

            break;

        default:

            break;   

    }
    
}

/* Define the Global handler of SML */
/*******************************************************************************
 * FUNCTION  
 *  sml_Load
 * DESCRIPTION
 *  This function loads the SML obj from NVRAM LID (NVRAM_READ_CNF)
 * PARAMETERS
 *  IN          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_Load( void *pLid, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    kal_uint16 length = sizeof(sml_context_struct);

    /* Clean the old ones */
    (*p->destory)(source);

    /* Load the new one */
    (*p->give)(pLid, source);

    return length;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Save
 * DESCRIPTION
 *  This function saves the SML obj to NVRAM LID (NVRAM_WRITE_REQ)
 * PARAMETERS
 *  OUT          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_Save( void *pLid, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    kal_uint16 length = sizeof(sml_context_struct);

    (*p->take)(pLid, source);

    return length;
    
}


/*******************************************************************************
 * FUNCTION  
 *  sml_Unlock
 * DESCRIPTION
 *  This function unlock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 *  IN          source
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Unlock( sml_cat_enum cat,      // category
                     kal_uint8 *key, 
                     kal_uint8 key_len,
                     kal_uint8 source)      // 0:SIM1, 1:SIM2
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
 
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source);
    
    if((meta->state == SML_STATE_LOCK)&&(meta->retry_count > 0))
    {
        
        if(kal_mem_cmp(&(catkey->key[0]),key,key_len))
        {
            
            meta->retry_count--;
            
            /* Fail! Passwd not match! return KAL_FALSE; */
            
        }
        else
        {
            
            /* Success! return KAL_TRUE; */

            result = KAL_TRUE;

            meta->state = SML_STATE_UNLOCK;

            switch(cat)
            {
                
                case SML_CAT_N:
                
                    meta->retry_count = SML_RETRY_COUNT_N_CAT;
                    
                break;
                case SML_CAT_NS:
 
                    meta->retry_count = SML_RETRY_COUNT_NS_CAT;                    
                    
                break;
                case SML_CAT_SP:
                    
                    meta->retry_count = SML_RETRY_COUNT_SP_CAT;
                    
                break;
                case SML_CAT_C:
                    
                    meta->retry_count = SML_RETRY_COUNT_C_CAT;                    
                    
                break;
                case SML_CAT_SIM:
                   
                    meta->retry_count = SML_RETRY_COUNT_SIM_CAT;     
                    
                break;
                case SML_CAT_NS_SP:
                    
                    meta->retry_count = SML_RETRY_COUNT_NS_CAT;
                    
                break;
                case SML_CAT_SIM_C:
                    
                    meta->retry_count = SML_RETRY_COUNT_SIM_CAT;
                    
                break;    
                default:
                break;
                
            }           
                      
        }
        
    }

    return result;
}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Lock
 * DESCRIPTION
 *  This function Lock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Lock( sml_cat_enum cat, 
                   kal_uint8 *key, 
                   kal_uint8 key_len,
                   kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
 
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 

    /* 
     * Perform Key state check. If the key is default SET, it must be equal 
     * to the key provided by the user. If it is not, the key will be set as 
     * the key provided by the user.
     */

    ASSERT( key_len <= SML_MAX_SUPPORT_KEY_LEN );
    
    if( SML_KEY_SET == catkey->state )
    {
    
        if( 0 == kal_mem_cmp(catkey->key,key,key_len) ) 
            result = KAL_TRUE;

    }
    else
    {
    
        result = KAL_TRUE;

    }

    /* Change the SML state if the category is not empty */
    
    if( (SML_STATE_UNLOCK == meta->state) 
        &&(KAL_TRUE == result) )
    {
    
        if( meta->num > 0 )
        {
        
            if( SML_KEY_EMPTY == catkey->state )
            {
            
                kal_mem_cpy(catkey->key,key,key_len);

            }

            meta->state = SML_STATE_LOCK;

        }
        else
        {
        
            kal_sys_trace("SML: The category is empty!");

            result = KAL_FALSE;

        }

    }
    else
    {

        result = KAL_FALSE;
    
    }
 
    return result;
    
}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Add
 * DESCRIPTION
 *  This function is used to add code into the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * code
 *  IN          len
 *  IN          * key
 *  IN          key_len
 *  OUT         * remain
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Add( sml_cat_enum cat, 
                  kal_uint8 *code, 
                  kal_uint8 len,
                  kal_uint8 *key,
                  kal_uint8 key_len,
                  kal_uint8 *remain,
                  kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint8 *pdata = NULL;

    kal_uint16 length = 0, offset = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);

    switch(cat)
    {
        
        case SML_CAT_N:

            //ASSERT(SML_SIZE_OF_CAT_N == len);

            offset = (meta->num) * SML_SIZE_OF_CAT_N;
            
            *remain = (length - offset) / SML_SIZE_OF_CAT_N;
                    
        break;
        
        case SML_CAT_NS:

            //ASSERT(SML_SIZE_OF_CAT_NS == len);

            offset = (meta->num) * SML_SIZE_OF_CAT_NS;        

            *remain = (length - offset) / SML_SIZE_OF_CAT_NS;        
            
        break;
        
        case SML_CAT_SP:
            
            //ASSERT(SML_SIZE_OF_CAT_SP == len);

            offset = (meta->num) * SML_SIZE_OF_CAT_SP;        

            *remain = (length - offset) / SML_SIZE_OF_CAT_SP;        
            
        break;

        case SML_CAT_C:

            //ASSERT(SML_SIZE_OF_CAT_C == len);
                        
            offset = (meta->num) * SML_SIZE_OF_CAT_C;   

            *remain = (length - offset) / SML_SIZE_OF_CAT_C;                
            
        break;
        
        case SML_CAT_SIM:

           //ASSERT(SML_SIZE_OF_CAT_SIM == len);
           
           offset = (meta->num) * SML_SIZE_OF_CAT_SIM;  

            *remain = (length - offset) / SML_SIZE_OF_CAT_SIM;               
            
        break;
        
        case SML_CAT_NS_SP:

            //ASSERT(SML_SIZE_OF_LINK_NS_SP == len);

            offset = (meta->num) * SML_SIZE_OF_LINK_NS_SP;   

            *remain = (length - offset) / SML_SIZE_OF_LINK_NS_SP;                    
            
        break;
        
        case SML_CAT_SIM_C:
            
            //ASSERT(SML_SIZE_OF_LINK_SIM_C == len);
            
            offset = (meta->num) * SML_SIZE_OF_LINK_SIM_C;   

            *remain = (length - offset) / SML_SIZE_OF_LINK_SIM_C;                
            
        break;    
        
        default:
            
        break;
        
    }           

    /* 
     * Perform Key state check. If the key is default SET, it must be equal 
     * to the key provided by the user. If it is not, the key will be set as 
     * the key provided by the user.
     */

    //ASSERT( key_len <= SML_MAX_SUPPORT_KEY_LEN );
    
    if( SML_KEY_SET == catkey->state )
    {
    
        if( 0 == kal_mem_cmp(catkey->key,key,key_len) ) 
            result = KAL_TRUE;

    }
    else
    {
    
        result = KAL_TRUE;

    }    
    
    /* Check if the space is available */
    if( (*remain > 0)
        && (SML_STATE_UNLOCK == meta->state)
        && (KAL_TRUE == result) )
    {

        if(SML_KEY_EMPTY == catkey->state)
        {
        
            kal_mem_cpy(catkey->key,key,key_len);
            
        }

        kal_mem_cpy((kal_uint8 *)(pdata+offset),
                    code,
                    len
                    );
        
        meta->num ++;

        (*remain)--;

        meta->state = SML_STATE_LOCK;
        
    }
    else
    {

        kal_sys_trace("SML: Add fail!");
    
        result = KAL_FALSE;

    }
    
    return result;

}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Remove
 * DESCRIPTION
 *  This function is used to remove the desired category
 * PARAMETERS
 *  IN          cat
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Remove( sml_cat_enum cat, kal_uint8 source )
{

    nvram_ef_sml_obj_struct * p = &pSMLg[source];

    sml_category_meta_struct * meta = NULL;

    sml_control_key_struct * catkey = NULL;

    kal_uint8 * pdata = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);

    if( SML_STATE_UNLOCK == meta->state )
    {

        kal_mem_set(pdata,0xFF,length);

        if( SML_KEY_EMPTY == catkey->state )
        {

            kal_mem_set(catkey->key,0xFF,SML_MAX_SUPPORT_KEY_LEN);
            
        }

        meta->num = 0;

        result = KAL_TRUE;

    }
    
    return result;
    
}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Disable
 * DESCRIPTION
 *  This function is used to disable the desired category
 * PARAMETERS
 *  IN          cat
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Disable( sml_cat_enum cat, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
 
    if( SML_STATE_UNLOCK == meta->state )
    {
    
        meta->state = SML_STATE_DISABLE;

        result = KAL_TRUE;
        
    }
    
    return result;

}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Reset
 * DESCRIPTION
 *  This function is used to reset the retry counter
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Reset( sml_cat_enum cat, 
                    kal_uint8 *key, 
                    kal_uint8 key_len,
                    kal_uint8 source)
{
    kal_bool result = KAL_FALSE;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return result;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Status
 * DESCRIPTION
 *  This function is used to query the status of the category
 * PARAMETERS
 *  IN          cat
 *  OUT         *state 
 *  OUT         *retry_count
 *  OUT         *num_of_sets
 *  OUT         *space_of_sets
 *  OUT         *key_state
 *  OUT         *auto_lock_count
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
void sml_Status( sml_cat_enum cat, 
                 sml_state_enum *state,
                 kal_uint8 *retry_count,
                 kal_uint8 *num_of_sets,
                 kal_uint8 *space_of_sets,
                 sml_key_state_enum *key_state,
                 kal_uint8 *auto_lock_count,
                 kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

//    kal_uint8 *pdata = NULL;

    kal_uint16 length = 0, offset = 0; 
   
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 
    (*p->getItem)(cat,SML_CAT_CODE,&length, source); //to get the code length for later use

    if(state)
        *state = meta->state;
    
    if(retry_count)
        *retry_count = meta->retry_count;
    
    if(num_of_sets)
        *num_of_sets = meta->num;
    
    if(key_state)
        *key_state = catkey->state;

    if(auto_lock_count)
        *auto_lock_count = meta->autolock_count;

    if(space_of_sets)
    {
        switch(cat)
        {
        
            case SML_CAT_N:

            offset = (meta->num) * SML_SIZE_OF_CAT_N;
            
            *space_of_sets = (length - offset) / SML_SIZE_OF_CAT_N;
                    
            break;
        
            case SML_CAT_NS:

            offset = (meta->num) * SML_SIZE_OF_CAT_NS;        

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_NS;        
            
            break;
        
            case SML_CAT_SP:
            
            offset = (meta->num) * SML_SIZE_OF_CAT_SP;        

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_SP;        
            
            break;

            case SML_CAT_C:
                        
            offset = (meta->num) * SML_SIZE_OF_CAT_C;   

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_C;                
            
            break;
        
            case SML_CAT_SIM:
           
            offset = (meta->num) * SML_SIZE_OF_CAT_SIM;  

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_SIM;               
            
            break;
        
            case SML_CAT_NS_SP:

            offset = (meta->num) * SML_SIZE_OF_LINK_NS_SP;   

            *space_of_sets  = (length - offset) / SML_SIZE_OF_LINK_NS_SP;                    
            
            break;
        
            case SML_CAT_SIM_C:
                        
            offset = (meta->num) * SML_SIZE_OF_LINK_SIM_C;   

            *space_of_sets  = (length - offset) / SML_SIZE_OF_LINK_SIM_C;                
            
            break;    
        
            default:
            
            break; 
            
        }         
    }

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Autolock
 * DESCRIPTION
 *  This function is used to autolock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          *code
 *  IN          len
 *  OUT          *remain
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Autolock( sml_cat_enum cat, 
                       kal_uint8 *code,
                       kal_uint8 len,
                       kal_uint8 *remain,
                       kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    kal_uint8 *pdata = NULL;

    kal_uint16 length = 0, offset = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);

    if((meta->state != SML_STATE_AUTOLOCK)||
       (meta->autolock_count == 0))
    {
    
        *remain = 0;

        return KAL_FALSE;

    }
    
    switch(cat)
    {
        
        case SML_CAT_N:

            if(SML_SIZE_OF_CAT_N == len)
            {
            
                offset = (meta->num) * SML_SIZE_OF_CAT_N;
            
                *remain = (length - offset) / SML_SIZE_OF_CAT_N;

                result = KAL_TRUE;

            }
                    
        break;
        
        case SML_CAT_NS:

            if(SML_SIZE_OF_CAT_NS == len)
            {
                
                offset = (meta->num) * SML_SIZE_OF_CAT_NS;        

                *remain = (length - offset) / SML_SIZE_OF_CAT_NS;    

                result = KAL_TRUE;

            }
            
        break;
        
        case SML_CAT_SP:
            
            if(SML_SIZE_OF_CAT_SP == len)
            {

                offset = (meta->num) * SML_SIZE_OF_CAT_SP;        

                *remain = (length - offset) / SML_SIZE_OF_CAT_SP;        
            
                result = KAL_TRUE;

            }

        break;

        case SML_CAT_C:

            if(SML_SIZE_OF_CAT_C == len)
            {
            
                offset = (meta->num) * SML_SIZE_OF_CAT_C;   

                *remain = (length - offset) / SML_SIZE_OF_CAT_C;                

                result = KAL_TRUE;

            }

        break;
        
        case SML_CAT_SIM:

           if(SML_SIZE_OF_CAT_SIM == len)
           {

                offset = (meta->num) * SML_SIZE_OF_CAT_SIM;  

                *remain = (length - offset) / SML_SIZE_OF_CAT_SIM; 
                
                result = KAL_TRUE;
           }            

        break;
        
        case SML_CAT_NS_SP:

            if(SML_SIZE_OF_LINK_NS_SP == len)
            {

                offset = (meta->num) * SML_SIZE_OF_LINK_NS_SP;   

                *remain = (length - offset) / SML_SIZE_OF_LINK_NS_SP; 

                result = KAL_TRUE;
                
            }
            
        break;
        
        case SML_CAT_SIM_C:
            
            if(SML_SIZE_OF_LINK_SIM_C == len)
            {

                offset = (meta->num) * SML_SIZE_OF_LINK_SIM_C;   

                *remain = (length - offset) / SML_SIZE_OF_LINK_SIM_C;  
                
                result = KAL_TRUE;

            }
            
        break;    
        
        default:
            
        break;
        
    }           

    if(result == KAL_FALSE)
    {

        *remain = meta->autolock_count;
        
        return KAL_FALSE;
        
    }
    
    /* Check if the space is available */
    if(*remain > 0)
    {

        kal_mem_cpy((kal_uint8 *)(pdata+offset),
                    code,
                    len
                    );
        
        meta->num ++;

        meta->autolock_count--;

        if(meta->autolock_count == 0)
        {

            meta->state = SML_STATE_LOCK;

            kal_sys_trace("SML: Autolock finished!");

        }

        *remain = meta->autolock_count;

        result = KAL_TRUE;
        
    }
    else
    {

        kal_sys_trace("SML: Autolock fail! Clean remain count!");

        meta->autolock_count = 0;
        
        meta->state = SML_STATE_LOCK;

        result = KAL_TRUE;
        
    }
    
    return result;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Check
 * DESCRIPTION
 *  This function is used to check if the code is in the Pass list
 * PARAMETERS
 *  IN          cat
 *  IN          *imsi
 *  IN          *gid1
 *  IN          *gid2
 *  IN          num_cnl
 *  IN          *cnl
 *  IN          *dck
 *  IN          sim_mnc_len
 *  IN          *remain
 *  IN          source
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Check( sml_cat_enum cat,       // category
                    kal_uint8 *imsi,        // 9 bytes array, read from SIM, mandatory file
                    kal_uint8 *gid1,        // 20 bytes array, read from SIM, NULL means gid1 invalid(file not exist)
                    kal_uint8 *gid2,        // 20 bytes array, read from SIM, NULL means gid2 invalid(file not exist)
                    kal_uint16 num_cnl,     // How many bytes of cnl, read from SIM, 0 means cnl invalid(file not exist)
                    kal_uint8 *cnl,         // 240 bytes array, length is depend on num_cnl, read from SIM
                    kal_uint8 *dck,         // 4 bytes array, read from SIM, NULL means dck invalid(file not exist)
                    kal_uint8 sim_mnc_len,  // MNC length, read from SIM
                    kal_uint8 *remain,      // remain retry count
                    kal_uint8 source)       // 0:SIM1, 1:SIM2
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    sml_category_meta_struct *meta = NULL;
    kal_uint8 *pdata = NULL;
    kal_uint8 idx = 0;
    kal_uint16 length = 0, offset = 0; 
    kal_bool result = KAL_FALSE;
    kal_uint8 code_len = 0;
    kal_uint8 code[10] = {0xFF};
    kal_uint8 size_of_cat = 0;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat, SML_CAT_META, &length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat, SML_CAT_CODE, &length, source);

    *remain = meta->retry_count;

    if (SML_STATE_LOCK != meta->state)
    {
        /* ALWAYS PASSED if the category is not locked! */
        return KAL_TRUE;
    }
    
    switch(cat)
    {
        case SML_CAT_N:
        {
            size_of_cat = SML_SIZE_OF_CAT_N;
            break;
        }
        case SML_CAT_NS:
        {
            size_of_cat = SML_SIZE_OF_CAT_NS;
            break;
        }
        case SML_CAT_SP:
        {
            size_of_cat = SML_SIZE_OF_CAT_SP;
            break;
        }
        case SML_CAT_C:
        {
            size_of_cat = SML_SIZE_OF_CAT_C;
            break;
        }
        case SML_CAT_SIM:
        {
            size_of_cat = SML_SIZE_OF_CAT_SIM;
            break;
        }
        case SML_CAT_NS_SP:
        {
            size_of_cat = SML_SIZE_OF_LINK_NS_SP;
            break;
        }
        case SML_CAT_SIM_C:
        {
            size_of_cat = SML_SIZE_OF_LINK_SIM_C;
            break;
        }
        default:
            break;
    }           

    for (idx = 0; idx < meta->num; idx++)
    {
        offset = idx * size_of_cat;
        code_len = sml_GetCode(cat,
                               imsi,
                               gid1,
                               gid2,
                               sim_mnc_len, 
                               (pdata+offset),
                               code);
        
        if (size_of_cat == code_len)
        {
            if (kal_mem_cmp(code, (pdata+offset), code_len)==0)
            {
                result = KAL_TRUE;
                break;
            }
        }
    }
    
    return result;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Catcode
 * DESCRIPTION
 *  This function is used to compose the code of each category
 * PARAMETERS
 *  IN          cat
 *  IN          *imsi
 *  IN          *gid1
 *  IN          *gid2
 *  IN          mnc_len
 *  OUT          *code
 * RETURN
 *  kal_uint8   code length
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_uint8 sml_Catcode( sml_cat_enum cat,
                       kal_uint8 *imsi,
                       kal_uint8 *gid1,
                       kal_uint8 *gid2,
                       kal_uint8 mnc_len,
                       kal_uint8 *code )
{

    if(mnc_len == 3)
    {
        code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);
        code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);
        code[2] = (imsi[3] & 0xF0) | (imsi[4] & 0x0F);
        code[3] = (imsi[4] & 0xF0) | (imsi[5] & 0x0F);
    }
    else
    {
        code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);
        code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);
        code[2] = (imsi[3] & 0xF0) | 0x0F;
        code[3] = ((imsi[4] & 0x0F) << 4) | ((imsi[4] & 0xF0) >> 4);
    }

    switch(cat)
    {
        
        case SML_CAT_N:

            return SML_SIZE_OF_CAT_N;
                    
        break;
        
        case SML_CAT_NS:

            return SML_SIZE_OF_CAT_NS;
            
        break;
        
        case SML_CAT_SP:

            if(gid1)
            {
                code[3] = gid1[0];
                
                return SML_SIZE_OF_CAT_SP;

            }

        break;

        case SML_CAT_C:
            
            if (gid1 && gid2 )
            {
                code[3] = gid1[0];
                code[4] = gid2[0];

                return SML_SIZE_OF_CAT_C;
            }
                               
        break;
        
        case SML_CAT_SIM:

            kal_mem_cpy(code,&(imsi[1]),8);
            
            return SML_SIZE_OF_CAT_SIM;          
            
        break;
        
        case SML_CAT_NS_SP:

            if(gid1)
            {            

                code[4] = gid1[0];

                return SML_SIZE_OF_LINK_NS_SP;

            }  

        break;
        
        case SML_CAT_SIM_C:

            kal_mem_cpy(code,&(imsi[1]),8);

            if(gid1 && gid2)
            {

                code[8] = gid1[0];

                code[9] = gid2[0];
                
                return SML_SIZE_OF_LINK_SIM_C;

            }
                  
        break;    
        
        default:
            
        break;
        
    }           

    return 0;
    
}


/*******************************************************************************
 * FUNCTION
 *  sml_GetCode
 * DESCRIPTION
 *  This function is used to compose the code of each category  whether 
 *  mnc length is 2 or 3
 * PARAMETERS
 *  cat         [IN]    category of the SIM-ME-Lock
 *  imsi        [IN]    imsi of the code source 
 *  gid1        [IN]    gid1 of the code source
 *  gid2        [IN]    gid2 of the code source
 *  sim_mnc_len [IN]    the mnc length decided by SIM
 *  pdata       [IN]    the saved code for comparing
 *  code        [OUT]   the composed code according to all input parameters
 *
 * RETURN
 *  kal_uint16 file size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
kal_uint8 sml_GetCode( sml_cat_enum cat, 
                       kal_uint8 * imsi, 
                       kal_uint8 * gid1, 
                       kal_uint8 * gid2, 
                       kal_uint8 sim_mnc_len, 
                       kal_uint8 * pdata,
                       kal_uint8 * code)
{
    kal_uint8 mnc_len=0;

    if (SML_MNC_LENGTH_NEST == 1)
    {
        mnc_len = sim_mnc_len;
    }
    else
    {
        if(((*(pdata+2)) & 0x0F) == 0x0F)
        {
            mnc_len = 2;
        }
        else
        {
            mnc_len = 3;
        }
    }
    return sml_Catcode(cat, imsi, gid1, gid2, mnc_len, code);
}


/*******************************************************************************
 * FUNCTION  
 *  sml_Process_autolock
 * DESCRIPTION
 *  This function is used process autolock function
 * PARAMETERS
 *  IN          cat
 *  OUT         *state 
 *  OUT         *retry_count
 *  OUT         *num_of_sets
 *  OUT         *space_of_sets
 *  OUT         *key_state
 *  OUT         *auto_lock_count
 * RETURN
 *  kal_bool    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Process_autolock( kal_uint8 * imsi,
                               kal_uint8 * gid1,
                               kal_uint8 * gid2,
                               kal_uint8 num_mnc,
                               kal_uint8 * remain_count,
                               kal_uint8 source)
{

    kal_bool result = KAL_FALSE;

    sml_cat_enum cat = SML_CAT_N;

    kal_uint8 code[10] = {0xFF}, len = 0, count = 0;

    kal_mem_set( (kal_uint8 *) &(code[0]), 
                  0xFF, 
                  10 
                  );
    
    *remain_count = 0;

    for(cat = SML_CAT_N; cat < SML_CAT_SIZE; cat++)
    {
        /* Because this is ADD operation, there is no code in NVRAM for sml_GetCode to refer mnc length.
           This function just uses num_mnc from SIM to construct the code
        */
        len = sml_Catcode( cat,
                           imsi,
                           gid1, 
                           gid2, 
                           num_mnc, 
                           code );

        if(KAL_TRUE == sml_Autolock( cat, 
                                     code, 
                                     len, 
                                     &count,
                                     source
                                     ))
        {

            result = KAL_TRUE;

        }

        if(count > *remain_count)
        {
        
            *remain_count = count; 

        }
            
    }

    return result;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Is_autolock
 * DESCRIPTION
 *  This function is used to query if there is autolock shall be processed
 * PARAMETERS
 *  void
 * RETURN
 *  kal_uint8    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint8 sml_Is_autolock(kal_uint8 *imsi, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    sml_cat_enum cat = SML_CAT_N;

    kal_uint16 length = 0;

    kal_uint8 result = 0;

    for(cat = SML_CAT_N; cat < SML_CAT_SIZE; cat++)
    {
        meta = (sml_category_meta_struct *) (*p->getItem)(cat,
                                                          SML_CAT_META,
                                                          &length,
                                                          source);

        if(meta->state == SML_STATE_AUTOLOCK)
        {
            result++;
        }
    }

    return result;    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Verify
 * DESCRIPTION
 *  This function is used to verify the SML lock keys
 * PARAMETERS
 *  void
 * RETURN
 *  kal_bool    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Verify( sml_cat_enum cat,
                      kal_uint8 * key,
                      kal_uint8 len,
                      kal_uint8 * retry_count,
                      kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    
    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_bool result = KAL_FALSE;

    kal_uint16 length = 0;

    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 

    if(kal_mem_cmp(catkey->key,key,len)==0)
    {

        result = KAL_TRUE;
        
        switch(cat)
        {
            
            case SML_CAT_N:
            
                meta->retry_count = SML_RETRY_COUNT_N_CAT;
                
            break;
            case SML_CAT_NS:
        
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;                    
                
            break;
            case SML_CAT_SP:
                
                meta->retry_count = SML_RETRY_COUNT_SP_CAT;
                
            break;
            case SML_CAT_C:
                
                meta->retry_count = SML_RETRY_COUNT_C_CAT;                    
                
            break;
            case SML_CAT_SIM:
               
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;     
                
            break;
            case SML_CAT_NS_SP:
                
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;
                
            break;
            case SML_CAT_SIM_C:
                
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;
                
            break;    
            default:
            break;
            
        }           

    }
    else
    {

        meta->retry_count--;

        result = KAL_FALSE;
        
    }

    *retry_count = meta->retry_count;
    
    return result;
    
}

/* END: PH sml_context_struct (NVRAM_EF_SML_LID) */

/*******************************************************************************
 * FUNCTION  
 *  sml_Testsim_op_mode
 * DESCRIPTION
 *  This function is used to query the testsim handling rule
 * PARAMETERS
 *  void
 * RETURN
 *  SML_TESTSIM_ALW_REJECT  0
 *  SML_TESTSIM_ALW_ALLOW   1
 *  SML_TESTSIM_INI_ALLOW   2
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_uint8 sml_Testsim_op_mode(void)
{

    return SML_TESTSIM_OP_MODE;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_is_Masterkey_enable
 * DESCRIPTION
 *  This function is used to query the Masterkey handling rule
 * PARAMETERS
 *  void
 * RETURN
 * kal_bool
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 

kal_bool sml_is_Masterkey_enable(void)
{

    return SML_MASTER_KEY_ENABLE;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Verify_OTA
 * DESCRIPTION
 *  This function is used to process OTA
 * PARAMETERS
 *  void
 * RETURN
 *  kal_bool    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Verify_OTA( sml_cat_enum cat,
                          kal_uint8 * key,
                          kal_uint8 len,
                          kal_uint8 source)
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    
    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_bool result = KAL_FALSE;

    kal_uint16 length = 0;

    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 

    if(kal_mem_cmp(catkey->key,key,len)==0)
    {

        result = KAL_TRUE;

        if(SML_STATE_LOCK == meta->state)
            meta->state = SML_STATE_UNLOCK;
        
        switch(cat)
        {
            
            case SML_CAT_N:
            
                meta->retry_count = SML_RETRY_COUNT_N_CAT;
                
            break;
            case SML_CAT_NS:
        
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;                    
                
            break;
            case SML_CAT_SP:
                
                meta->retry_count = SML_RETRY_COUNT_SP_CAT;
                
            break;
            case SML_CAT_C:
                
                meta->retry_count = SML_RETRY_COUNT_C_CAT;                    
                
            break;
            case SML_CAT_SIM:
               
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;     
                
            break;
            case SML_CAT_NS_SP:
                
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;
                
            break;
            case SML_CAT_SIM_C:
                
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;
                
            break;    
            default:
            break;
            
        }           

    }
    else
    {

        result = KAL_FALSE;
        
    }
    
    return result;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_CheckVisa
 * DESCRIPTION
 *  This function is used to handle special Block SIM cards 
 * PARAMETERS
 *  IN          *imsi
 *  IN          mnc_len
 * RETURN
 *  kal_bool  
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_bool sml_CheckVisa(const kal_uint8 * imsi, kal_uint8 mnc_len)
{

    const kal_uint8 *  code_ptr = &(smlVISA[0]);

    kal_uint8 code[3] = {0};
    

    code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);

    code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);

    if(3 == mnc_len)
    {

        code[2] = (imsi[3] & 0xF0) | (imsi[4] & 0x0F);

    }
    else
    {
    
        code[2] = (imsi[3] & 0xF0) | 0x0F;

    }

    while(0xFF != *code_ptr) /* Break if first byte is 0xFF */
    {

        if(0==kal_mem_cmp(code_ptr,code,3))
        {
            
            return KAL_TRUE;
            
        }

        code_ptr += 3;

    }

    return KAL_FALSE;


}


/*[MAUI_01634719] mtk01612: common API to query state*/
kal_uint8 sml_query_state( sml_cat_enum cat, kal_uint8 source)
{
    nvram_ef_sml_obj_struct *p = pSMLg;
	
    sml_category_meta_struct *meta = NULL;

//    sml_control_key_struct *catkey = NULL;

    kal_uint16 length = 0;	

    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
//    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 

    return meta->state;
}

#ifdef __CHANGE_SML_KEY__
extern kal_bool sml_ChangePW(sml_cat_enum cat,
                              kal_uint8 * lock_count,
	                    kal_uint8 *key1,
	                    kal_uint8 *key2,
	                    kal_uint8 len,
	                    kal_uint8 source)
{
        nvram_ef_sml_obj_struct *p = &pSMLg[source];
        sml_category_meta_struct * meta = NULL;
        sml_control_key_struct * catkey = NULL;
        kal_uint8 * pdata = NULL;
        kal_uint16 length = 0;
        kal_bool result = KAL_FALSE;

        meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
        catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source);

       if(meta->retry_count>0 && SML_KEY_SET==catkey->state && SML_STATE_UNLOCK ==meta->state)
       {
             if(kal_mem_cmp(&(catkey->key[0]),key1,len))
        {

            meta->retry_count--;
        }
        else
        {
            result = KAL_TRUE;
	   kal_mem_cpy(catkey->key,key2,len);//change key

            switch(cat)
            {

                case SML_CAT_N:

                    meta->retry_count = SML_RETRY_COUNT_N_CAT;

                break;
                case SML_CAT_NS:

                    meta->retry_count = SML_RETRY_COUNT_NS_CAT;

                break;
                case SML_CAT_SP:

                    meta->retry_count = SML_RETRY_COUNT_SP_CAT;

                break;
                case SML_CAT_C:

                    meta->retry_count = SML_RETRY_COUNT_C_CAT;

                break;
                case SML_CAT_SIM:

                    meta->retry_count = SML_RETRY_COUNT_SIM_CAT;

                break;
                case SML_CAT_NS_SP:

                    meta->retry_count = SML_RETRY_COUNT_NS_CAT;

                break;
                case SML_CAT_SIM_C:

                    meta->retry_count = SML_RETRY_COUNT_SIM_CAT;

                break;
                default:
                break;
            }
         	 }
        }
	
        *lock_count  = meta->retry_count;
        return result;
}
#endif

extern kal_uint16 sml_tmo_getSize()
{
    return SML_TMO_MAX_SLB_SIZE;
}
/*******************************************************************************
 * FUNCTION  
 *  smu_is_write_protect2
 * DESCRIPTION
 *  This is a callback function for NVRAM to check whether write protect2 or not
 *  The custom_smu_is_write_protect2 retrun true only for files owned by SMU module
 * PARAMETERS
 *  nvram_lid_enum file_idx
 * RETURN
 *  kal_bool  
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_bool smu_is_write_protect2(nvram_lid_enum file_idx)
{
    //Add more condition here
    return custom_smu_is_write_protect2(file_idx);
}

#endif /* __SIM_ME_LOCK__ */ 

#ifdef __MDVSIM__
extern kal_bool nvram_external_write_data(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size); // from nvram_interface.c

extern kal_bool nvram_external_read_data(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size);  // from nvram_interface.c

/*
 * profile_id: 0-based index
 */
kal_bool custom_vsim_read_nvram_file(kal_uint8 profile_id, uicc_card_type_enum vsim_type, nvram_vsim_ef_file_struct *vsim_ef_buf)
{
    kal_bool ret_val = KAL_FALSE;

    
    if (UICC_USIM_INSIDE == vsim_type)
    {
        /* Update USIM EF_U_IMSI ... */
        ret_val = nvram_external_read_data(NVRAM_EF_VSIM_U_IMSI_LID, profile_id+1, (kal_uint8*)vsim_ef_buf, NVRAM_VSIM_EF_U_DEFUALT_SIZE);
        kal_mem_cpy(EF_U_IMSI_data[profile_id], vsim_ef_buf->meta, EF_U_META_SIZE);
        kal_mem_cpy(EF_U_IMSI_data[profile_id]+EF_U_META_SIZE, vsim_ef_buf->data, EF_U_DATA_SIZE);
        
        /* Update other USIM files ... */
    }
    else if(SIM_CARD_INSIDE == vsim_type)
    {
        /* Update SIM EF_IMSI ... */
        ret_val = nvram_external_read_data(NVRAM_EF_VSIM_SIM_IMSI_LID, 1, (kal_uint8*)vsim_ef_buf, NVRAM_VSIM_EF_DEFUALT_SIZE);
        kal_mem_cpy(EF_IMSI_data, vsim_ef_buf->meta, EF_META_SIZE);
        kal_mem_cpy(EF_IMSI_data+EF_META_SIZE, vsim_ef_buf->data, EF_DATA_SIZE);

        /* Update other SIM files ... */
    }

    return ret_val;
}

/*
 * profile_id: 0-based index
 */
kal_bool custom_vsim_write_nvram_file(kal_uint8 profile_id, kal_uint16 file_id, uicc_card_type_enum vsim_type, nvram_vsim_ef_file_struct *vsim_ef_buf)
{
    kal_bool ret_val = KAL_FALSE;


    if (UICC_USIM_INSIDE == vsim_type)
    {
        switch(file_id)
        {
            case 0x6f07:    //EF_IMSI_ID
                kal_mem_cpy(vsim_ef_buf->meta, EF_U_IMSI_data[profile_id], EF_U_META_SIZE);
                kal_mem_cpy(vsim_ef_buf->data, EF_U_IMSI_data[profile_id]+EF_U_META_SIZE, EF_U_DATA_SIZE);
                    
                ret_val = nvram_external_write_data(NVRAM_EF_VSIM_U_IMSI_LID, profile_id+1, (kal_uint8*)vsim_ef_buf, NVRAM_VSIM_EF_U_DEFUALT_SIZE);
                break;
            default:
                break;
        }
        
    }
    else if (SIM_CARD_INSIDE == vsim_type)
    {
        switch (file_id)
        {
            case 0x6f07:    //EF_IMSI_ID
                kal_mem_cpy(vsim_ef_buf->meta, EF_IMSI_data, EF_META_SIZE);
                kal_mem_cpy(vsim_ef_buf->data, EF_IMSI_data+EF_META_SIZE, EF_DATA_SIZE);

                ret_val = nvram_external_write_data(NVRAM_EF_VSIM_SIM_IMSI_LID, 1, (kal_uint8*)vsim_ef_buf, NVRAM_VSIM_EF_DEFUALT_SIZE);
                break;
            default:
                break;
        }
    }

    return ret_val;
}

static kal_bool custom_vsim_usim_file_instance(kal_uint8 profile_id, kal_uint8 *file_id, kal_uint8** file_ptr)
{
    kal_bool result = KAL_FALSE;
    kal_uint8 *fptr = NULL;

    switch (file_id[0])
    {
        case 0x7f:  // 7FFF (default ADF_USIM)
            switch (file_id[1])
            {
                case 0xff:
                    fptr = &ADF_USIM_data[profile_id][0];
                    result = KAL_TRUE;
                    break;
                
                default:
                    break;
            }
            
            break;
        case 0x5f:
            break;
        case 0x3f:
            break;

        case 0x6f:  // 7FFF - 6Fxx
            switch (file_id[1])
            {
                case 0x07:
                    fptr = &EF_U_IMSI_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0x31:
                    fptr = &EF_U_HPPLMN_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0x38:
                    fptr = &EF_U_UST_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0x56:
                    fptr = &EF_U_EST_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0x60:
                    fptr = &EF_U_PLMNWACT_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0x61:
                    fptr = &EF_U_OPLMNWACT_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0x62:
                    fptr = &EF_U_HPLMNWACT_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0x73:
                    fptr = &EF_U_PSLOCI_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0x78:
                    fptr = &EF_U_ACC_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0x7E:
                    fptr = &EF_U_LOCI_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0xAD:
                    fptr = &EF_U_AD_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                default:
                    break;
            }
            break;
        case 0x4f:
            break;

        case 0x2f:  // 3F00 - 2Fxx
            switch (file_id[1])
            {
                case 0x05:
                    fptr = &EF_U_ELP_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                case 0xE2:
                    fptr = &EF_U_ICCID_data[profile_id][0];
                    result = KAL_TRUE;
                    break;

                default:
                    break;
            }
            break;
        default:
            break;
    }


    *file_ptr = fptr;

    return result;
}

static kal_bool custom_vsim_sim_file_instance(kal_uint8 profile_id, kal_uint8 *file_id, kal_uint8** file_ptr)
{
    kal_bool result = KAL_FALSE;
    kal_uint8 *fptr = NULL;

    switch (file_id[0])
    {
        /* DF level */
        case 0x7f:  // 7F20 (DF_GSM)
            switch (file_id[1])
            {
                case 0x20:
                    fptr = &DF_GSM_data[0];
                    result = KAL_TRUE;
                 break;
             default:
                 break;
            }
         case 0x5f:
             break;

         case 0x3f:
             break;

        /* EF level */
         case 0x6f: // 7F20 - 6Fxx
            switch (file_id[1])
            {
                case 0x05:
                    fptr = &EF_LP_data[0];
                    result = KAL_TRUE;
                    break;

                case 0x07:
                    fptr = &EF_IMSI_data[0];
                    result = KAL_TRUE;
                    break;

                case 0x20:
                   fptr = &EF_KC_data[0];
                   result = KAL_TRUE;
                   break;

                case 0x31:
                   fptr = &EF_HPPLMN_data[0];
                   result = KAL_TRUE;
                   break;

                case 0x38:
                    fptr = &EF_SST_data[0];
                    result = KAL_TRUE;
                    break;

                 case 0x74:
                    fptr = &EF_BCCH_data[0];
                    result = KAL_TRUE;
                    break;

                 case 0x78:
                    fptr = &EF_ACC_data[0];
                    result = KAL_TRUE;
                    break;

                 case 0x7B:
                    fptr = &EF_FPLMN_data[0];
                    result = KAL_TRUE;
                    break;

                case 0x7E:
                   fptr = &EF_LOCI_data[0];
                   result = KAL_TRUE;
                   break;

                case 0xAE:
                    fptr = &EF_PHASE_data[0];
                    result = KAL_TRUE;
                    break;

                case 0xAD:
                    fptr = &EF_AD_data[0];
                    result = KAL_TRUE;
                    break;

                 default:
                     break;
            }
            break;

         case 0x4f:
            break;

         case 0x2f:
            switch (file_id[1])
            {
                case 0xE2:
                    fptr = &EF_ICCID_data[0];
                    result = KAL_TRUE;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    *file_ptr = fptr;

    return result;

}

kal_bool custom_vsim_file_instance(kal_uint8 profile_id, kal_uint8 vsim_type, kal_uint8 *file_id, kal_uint8** file_ptr)
{
    kal_bool result = KAL_FALSE;

    if (vsim_type == 1)
    {
        //SIM_CARD_INSIDE
        result = custom_vsim_sim_file_instance(profile_id, file_id, file_ptr);
    }
    else if(vsim_type == 2)
    {
        //UICC_USIM_INSIDE
        result = custom_vsim_usim_file_instance(profile_id, file_id, file_ptr);
    }
    else
    {
        // do nothing
    }

    return result;
}

/*
 * return 0 if success
 * return -1 if SIM_AUTH_ERROR_WRONG_MAC
 */
kal_int8 custom_vsim_get_gsm_auth(kal_uint8 sim_auth_algo, kal_uint8 *ki, kal_uint8 *rand, kal_uint8 *sres, kal_uint8 *kc)
{
    /* Please porting your GSM authentication here to output to sres and kc */
    return 0;
}

/*
 * return 0 if success
 * return -1 if SIM_AUTH_ERROR_WRONG_MAC
 * return -2 if AUTH_3G_SYNC_FAILURE_T
 */
kal_int8 custom_vsim_get_usim_auth(kal_uint8 usim_auth_algo, kal_uint8 *opc, kal_uint8 *ki, 
                                          kal_uint8 *rand, kal_uint8 *autn, 
                                          kal_uint8 *ik, kal_uint8 *ck, 
                                          kal_uint8 *res, kal_uint32 *res_len, kal_uint8 *auts)
{
    /* Please porting your USIM authentication here */    
    return 0;
}

#endif /* __MDVSIM__ */

#endif /* !defined(__MAUI_BASIC__) */ 