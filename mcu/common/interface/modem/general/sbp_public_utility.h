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
 * Filename:
 * ---------
 * sbp_public_utility.h
 *
 * Description:
 * ------------
 *   This file is intends for put the header of SBP public API
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
*****************************************************************************/

#ifndef _SBP_PUBLIC_UTILITY_H
#define _SBP_PUBLIC_UTILITY_H

#include "kal_general_types.h"
#include "sim_exported_enum.h"

#define SBP_ID_INVALID 0xffffffff


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
* DESCRIPTION
*   This enum is defined for Single Binary Platform (SBP) features
*   NVRAM saves one binary value for each feature
*****************************************************************************/
typedef enum
{
//Please add SBP features in sbp_feature.def

#define SBP_FEATURE_ENUM(FEATURE) FEATURE,
#include "sbp_feature.def"
#undef SBP_FEATURE_ENUM

    SBP_MAX_MD_FEATURE
}sbp_md_feature_enum;

/*****************************************************************************
* DESCRIPTION
*   This enum is defined for Single Binary Platform (SBP) features
*   NVRAM saves one byte value for each feature
*****************************************************************************/
typedef enum
{
//Please add SBP data in sbp_data.def

#define SBP_DATA_ENUM(FEATURE) FEATURE,
#include "sbp_data.def"
#undef SBP_DATA_ENUM

    SBP_DATA_MAX_MD_FEATURE
}sbp_md_feature_data_enum;


/** 
 * SBP(Single Binary Platform) modem configuration
 * a bitmap for all modem configurable feature
 **/
typedef struct
{
    kal_uint32 sbp_mode; //reserved for usage
    kal_uint8 modem_sbp_config[(SBP_MAX_MD_FEATURE/8)+1]; //the size depends on SBP_MAX_MD_FEATURE
} nvram_ef_sbp_modem_config_struct;

#define NVRAM_EF_SBP_MODEM_CONFIG_TOTAL (1)
#define NVRAM_EF_SBP_MODEM_CONFIG_SIZE sizeof(nvram_ef_sbp_modem_config_struct)

/** 
 * SBP(Single Binary Platform) modem data configuration
 * a byte for each modem configurable feature
 **/
typedef struct
{   
    kal_uint32 sbp_mode; //reserved for usage
    kal_uint8 modem_sbp_data_config[SBP_DATA_MAX_MD_FEATURE];
} nvram_ef_sbp_modem_data_config_struct;

#define NVRAM_EF_SBP_MODEM_DATA_CONFIG_TOTAL (1)
#define NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE sizeof(nvram_ef_sbp_modem_data_config_struct)

typedef struct 
{
    kal_uint8 mcc_mnc[7];
    kal_uint32 sbp_id;
} mccmnc_to_sbp_id_struct;

typedef enum
{
    SBP_ID_CMCC = 1,
    SBP_ID_CU = 2,
    SBP_ID_ORANGE = 3,
    SBP_ID_TMO_EU = 5,
    SBP_ID_VODAFONE = 6,
    SBP_ID_ATT = 7,
    SBP_ID_TMO_US = 8,
    SBP_ID_CT = 9,
    SBP_ID_TIER_2 = 10,
    SBP_ID_H3G = 11,
    SBP_ID_VERIZON = 12,
    SBP_ID_TELEFONICA = 15,
    SBP_ID_EE = 16,
    SBP_ID_DOCOMO = 17,
    SBP_ID_SPRINT = 20,
    SBP_ID_SOFTBANK = 50,
    SBP_ID_CSL = 100,
    SBP_ID_PCCW = 101,
    SBP_ID_SMT = 102,
    SBP_ID_SINGTEL = 103,
    SBP_ID_STARHUB = 104,
    SBP_ID_AMX = 105,
    SBP_ID_3HK = 106,
    SBP_ID_MTS = 135
}sbp_id_enum;

/* --------------------------
 * End of SBP Configuration
 * --------------------------- */

#if defined(__PCORE__)
DECLARE_SHARED_VAR(nvram_ef_sbp_modem_config_struct, sbp_config_shared)
DECLARE_SHARED_VAR(nvram_ef_sbp_modem_data_config_struct, sbp_data_config_shared)
#elif defined(__L1CORE__)
DECLARE_SHARED_VAR(nvram_ef_sbp_modem_config_struct, sbp_config_shared)
DECLARE_SHARED_VAR(nvram_ef_sbp_modem_data_config_struct, sbp_data_config_shared)
#endif


/*****************************************************************************
* FUNCTION
*   sbp_query_md_feature()
*
* DESCRIPTION
*   This function is used to query modem configuration
*
* PARAMETERS
*   feature [IN]    modem feature
*
* RETURNS
*   KAL_TRUE    : if this feature is turned on
*   KAL_FALSE   : if this feature is turned off
*****************************************************************************/
extern kal_bool sbp_query_md_feature(sbp_md_feature_enum feature);

/*****************************************************************************
* FUNCTION
*   sbp_query_md_feature_no_overwrite()
*
* DESCRIPTION
*   This function is used to query modem configuration without overwrite
*
* PARAMETERS
*   feature [IN]    modem feature
*
* RETURNS
*   KAL_TRUE    : if this feature is turned on
*   KAL_FALSE   : if this feature is turned off
*****************************************************************************/
extern kal_bool sbp_query_md_feature_no_overwrite(sbp_md_feature_enum feature);


/*****************************************************************************
* FUNCTION
*   sbp_set_md_feature()
*
* DESCRIPTION
*   This function is used to set modem configuration
*
* PARAMETERS
*   feature         [IN]    modem feature
*   is_turned_on    [IN]
*   sbp_feature_ptr [IN/OUT]
*
* RETURNS
*   KAL_TRUE if success; otherwise KAL_FALSE
*****************************************************************************/
extern kal_bool sbp_set_md_feature(sbp_md_feature_enum feature, 
                                   kal_bool is_turned_on, 
                                   nvram_ef_sbp_modem_config_struct *sbp_feature_ptr);

/*****************************************************************************
* FUNCTION
*   sbp_query_md_feature_data()
*
* DESCRIPTION
*   This function is used to query modem configuration
*
* PARAMETERS
*   feature [IN]    modem feature
*
* RETURNS
*   The byte value for the input feature
*****************************************************************************/
extern kal_uint8 sbp_query_md_feature_data(sbp_md_feature_data_enum feature);

/*****************************************************************************
* FUNCTION
*   sbp_query_md_feature_data_no_overwrite()
*
* DESCRIPTION
*   This function is used to query modem configuration without overwrite
*
* PARAMETERS
*   feature [IN]    modem feature
*
* RETURNS
*   The byte value for the input feature
*****************************************************************************/
extern kal_uint8 sbp_query_md_feature_data_no_overwrite(sbp_md_feature_data_enum feature);


/*****************************************************************************
* FUNCTION
*   sbp_set_md_feature_data()
*
* DESCRIPTION
*   This function is used to query modem configuration
*
* PARAMETERS
*   feature         [IN]    modem feature
*   data            [IN]
*   sbp_data_ptr    [IN/OUT]
*
* RETURNS
*   KAL_TRUE if success; otherwise KAL_FALSE
*****************************************************************************/
extern kal_bool sbp_set_md_feature_data(sbp_md_feature_data_enum feature, 
                                        kal_uint8 data, 
                                        nvram_ef_sbp_modem_data_config_struct *sbp_data_ptr);

/*****************************************************************************
* FUNCTION
*   sbp_md_feature_overwrite()
*
* DESCRIPTION
*   This function is used to overwrite the configuration for GCF or other test modes
*
* PARAMETERS
*   feature [IN]    modem feature
*   enabled [IN]   feature is turned on or not 
*
* RETURNS
*   KAL_TRUE    : if this feature is turned on
*   KAL_FALSE   : if this feature is turned off
*****************************************************************************/
extern kal_bool sbp_md_feature_overwrite(sbp_md_feature_enum feature, kal_bool enabled);

/*****************************************************************************
* FUNCTION
*   sbp_md_feature_data_overwrite()
*
* DESCRIPTION
*   This function is used to overwrite the configuration for GCF or other test modes
*
* PARAMETERS
*   feature [IN]    modem feature
*   value [IN]       the value of the feature 
*
* RETURNS
*   the overwrited value for the feature
*****************************************************************************/
extern kal_uint8 sbp_md_feature_data_overwrite(sbp_md_feature_data_enum feature, kal_uint8 value);


/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_sbp_id
 * DESCRIPTION
 * Set SBP features and data according to SBP ID.
 * PARAMETERS
 *  sbp_mode  [IN]
 * RETURNS
 *   KAL_TRUE    : Set SBP ID successfully
 *   KAL_FALSE   : Error happens when setting SBP ID
 *****************************************************************************/
extern kal_bool custom_nvram_set_sbp_id(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id);


/*****************************************************************************
* FUNCTION
*   sbp_get_sbp_id_from_mcc_mnc()
*
* DESCRIPTION
*   This function converts MCC/MNC to SBP ID
*
* PARAMETERS
*   mcc_mnc [IN]    MCC/MNC
*
* RETURNS
*   SBP ID
*****************************************************************************/
extern kal_uint32 sbp_get_sbp_id_from_mcc_mnc(kal_uint8 *mcc_mnc);

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_sbp_from_imsi_mcc_mnc
 * DESCRIPTION
 * Set SBP features and data according imsi mcc/mnc in OM load
 * PARAMETERS
 *  imsi  [IN]
 *  simInterface [IN]
 * RETURNS
 *   void
 *****************************************************************************/
extern void custom_nvram_set_sbp_from_imsi_mcc_mnc(kal_uint8 *imsi, kal_uint8 simInterface);


#ifdef __cplusplus
}
#endif

#endif  /* _SBP_PUBLIC_UTILITY_H */

