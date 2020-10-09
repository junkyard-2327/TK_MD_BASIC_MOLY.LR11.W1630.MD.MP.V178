/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * custom_eas_config.c
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the EAS configuration.
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
 * removed!
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
 *==============================================================================
 *******************************************************************************/

#ifndef _CUSTOM_EAS_CONFIG_H
#define _CUSTOM_EAS_CONFIG_H

#include "kal_general_types.h"
#include "kal_public_api.h"

/* Data structure for customized EUTRA Capability table */
#ifdef __BAND_EXTENSION_SUPPORT__
#define MAX_NUM_LTE_BAND_BITMASK  32
#else
#define MAX_NUM_LTE_BAND_BITMASK  8
#endif
#define CUSTOM_EUTRA_CAP_PLMN_CFG_END "FFFFFF"

typedef struct
{
    /* PLMN identity */
    kal_char  *plmnId;
    /* Bitmask indicates which LTE band is required */
    kal_uint8  eightWidthLteBandBitmask[MAX_NUM_LTE_BAND_BITMASK];
} eas_custom_eutra_cap_plmn_config;

extern const eas_custom_eutra_cap_plmn_config CUSTOM_EUTRA_CAP_PLMN_CFG[];
extern const kal_uint32 CUSTOM_EUTRA_CAP_PLMN_CFG_NUM;
extern const kal_bool CUSTOM_IS_BAND_ACTUALLY_DISABLED;

/*************************************************************************
* Function
*************************************************************************/

#define MAX_NUM_CA_COMBINATION_BLACKLIST  6
#define CUSTOM_CA_COMBINATION_BLACKLIST_PLMN_CFG_END "FFFFFF"

typedef struct
{
    /* PLMN identity */
    kal_char  *plmnId;
    kal_uint32  CA_Blacklist[MAX_NUM_CA_COMBINATION_BLACKLIST];
} eas_custom_CA_combination_blacklist_plmn_config;

extern const eas_custom_CA_combination_blacklist_plmn_config CUSTOM_CA_COMBINATION_BLACKLIST_PLMN_CFG[];
extern const kal_uint32 CUSTOM_CA_COMBINATION_BLACKLIST_PLMN_CFG_NUM;
/*************************************************************************
* Function
*************************************************************************/

#define MAX_NUM_ENHANCED_CA_COMBINATION_BLACKLIST  6
#define CUSTOM_ENHANCED_CA_COMBINATION_BLACKLIST_CFG_END "FFFFFF"
#define MAX_NUM_PER_CA_BLACK_MASK 32

typedef struct
{
    kal_uint8 CA_black_mask[MAX_NUM_PER_CA_BLACK_MASK];
} per_CA_black_mask;

typedef struct
{
    /* PLMN identity */
    kal_char  *plmnId;
    per_CA_black_mask  enhanced_CA_Blacklist[MAX_NUM_ENHANCED_CA_COMBINATION_BLACKLIST];
} eas_custom_enhanced_CA_combination_blacklist_config;

extern const eas_custom_enhanced_CA_combination_blacklist_config CUSTOM_ENHANCED_CA_COMBINATION_BLACKLIST_CFG[];
extern const kal_uint32 CUSTOM_ENHANCED_CA_COMBINATION_BLACKLIST_CFG_NUM;

/*************************************************************************
* Function
*************************************************************************/

/* FGI Black List */
#define CUSTOM_FGI_BLACKLIST_PLMN_CFG_END "FFFFFF"

typedef struct
{
    /* PLMN identity */
    kal_char  *plmnId;
    kal_uint32  feature_group_ind_fdd;
    kal_uint32  feature_group_ind_tdd;
    kal_uint32  feature_group_ind_rel9_add_r9_fdd;
    kal_uint32  feature_group_ind_rel9_add_r9_tdd;
    kal_uint32  feature_group_ind_r10_fdd;
    kal_uint32  feature_group_ind_r10_tdd;
} eas_custom_fgi_blacklist_plmn_config;

extern const eas_custom_fgi_blacklist_plmn_config CUSTOM_FGI_BLACKLIST_PLMN_CFG[];
extern const kal_uint32 CUSTOM_FGI_BLACKLIST_PLMN_CFG_NUM;

//#ifdef __HSR_ENHANCE__
/* Data structure for customized High Speed Railway's special PLMN list */
#define CUSTOM_MRS_HSR_PLMN_CFG_END "FFFFFF"

typedef struct
{
    /* PLMN identity */
    kal_char  *plmnId;
} mrs_custom_hsr_plmn_list;

extern const mrs_custom_hsr_plmn_list CUSTOM_MRS_HSR_PLMN_LIST[];
extern const kal_uint32 CUSTOM_MRS_HSR_PLMN_LIST_NUM;
//#endif

#if defined (__AS_SPECIFIC_CHANNEL_SRCH__)|| defined(UNIT_TEST)
/* The number of specific channels */
#define NUM_OF_LTE_SPECIFIC_CHANNELS    4
#define NUM_OF_LTE_SPECIFIC_BANDS      25 /* MIN:1, MAX:64 */

extern kal_bool eas_custom_specific_channel_srch;
extern kal_uint32 specific_earfcn[NUM_OF_LTE_SPECIFIC_BANDS][NUM_OF_LTE_SPECIFIC_CHANNELS];
#endif

/*************************************************************************
* Function
*************************************************************************/
#define CUSTOM_LWA_WHITELIST_PLMN_CFG_END "FFFFFF"

typedef struct
{
    /* PLMN identity */
    kal_char  *hplmnId;
    kal_char  *rplmnId;
} eas_custom_lwa_whitelist_plmn_config;

extern const eas_custom_lwa_whitelist_plmn_config CUSTOM_LWA_WHITELIST_PLMN_CFG[];
extern const kal_uint32 CUSTOM_LWA_WHITELIST_PLMN_CFG_NUM;

/*************************************************************************
* Function
*************************************************************************/

#define NUM_OF_CUSTOM_ROHC_PROFILE  9
#define CUSTOM_ROHC_PLMN_CFG_END "FFFFFF"

typedef struct
{
    kal_char            *plmnId;
    kal_bool            rohc_profiles[NUM_OF_CUSTOM_ROHC_PROFILE];
}custom_eas_lte_rohc_profile_config;

extern const custom_eas_lte_rohc_profile_config CUSTOM_EUTRA_ROHC_PROFILE_CFG[];
extern const kal_uint32 CUSTOM_EUTRA_ROHC_PROFILE_NUM;

/*************************************************************************
* Function
*************************************************************************/

#if defined (__AS_SPECIFIC_CHANNEL_SRCH__)|| defined(UNIT_TEST)
extern void eas_custom_set_specific_channel_srch( kal_bool set_value );
extern kal_bool eas_custom_is_specific_channel_srch(void);
extern kal_uint32 eas_custom_get_specific_earfcn(kal_uint8 band, kal_uint8 earfcn_index);
extern void eas_custom_set_specific_earfcn(kal_uint8 band, kal_uint8 earfcn_index, kal_uint32 earfcn);
extern kal_uint8 eas_custom_get_lte_specific_band_number(void);
extern kal_uint8 eas_custom_get_lte_specific_channel_number(void);
#endif

#if 0
#ifdef __CUSTOM_EAS_DYN_AFR_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*  __CUSTOM_EAS_DYN_AFR_SETTING__ */
#endif
#endif /* _CUSTOM_EAS_CONFIG_H */

