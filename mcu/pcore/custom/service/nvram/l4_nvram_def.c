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
 * umts_nvram_def.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef NVRAM_NOT_PRESENT

#include "kal_general_types.h"
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "nvram_enums.h"
#include "nvram_defs.h"
#include "l4_nvram_def.h" 
#include "l4_nvram_editor.h"
#include "custom_nvram_sec.h"
#include "custom_nvram_restore.h"



#ifdef __CPHS__
    extern kal_uint8 COMMON_NVRAM_EF_ALS_LINE_ID_DEFAULT[];
#endif
extern kal_uint8 COMMON_NVRAM_EF_MSCAP_DEFAULT[];
#if !defined(EXTERNAL_MMI)
    extern kal_uint8 COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[];
#endif
extern kal_uint8 COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_MS_SECURITY_DEFAULT[];    
#ifdef __MOBILE_BROADBAND_PROVISION_CONTEXT__
    extern nvram_ef_mobile_broadband_provision_context_struct COMMON_NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_DEFAULT[];
#endif
#ifdef __MEDIATEK_SMART_QOS__
    extern nvram_ef_msq_list_struct NVRAM_EF_MSQ_LIST_DEFAULT[] ;
#endif
extern const kal_uint32 NVRAM_EF_CUST_HW_LEVEL_TBL_DEFAULT[NVRAM_EF_CUST_HW_LEVEL_TBL_SIZE];
extern kal_uint8 COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT[];







#if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)
#define TCM_CONTEXT_ID_DEFAULT_VALUE (0xFF)
#define TCM_NAS_PRIORITY_CONFIG_NOT_SPECIFIED (0x00)
#define TCM_EAB_OVERRIDE_CONFIG_NOT_SPECIFIED (0x00)

static nvram_ef_tcm_PDP_profile_record_struct const NVRAM_EF_TCM_CID_0_PROFILE_DEFAULT[] = {
                  /* context_id, pdp_addr_type, pdp_addr_len. */
                  TCM_CONTEXT_ID_DEFAULT_VALUE, 0x21, 0x01,

                  /* addr_val[16]. */                  
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  /* apn_len. */
                  0x00,

                  /* apn[100]. */
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  /* pcomp_algo, dcomp_algo, context_type(0:PRIMARY_CONTEXT), primary_context_id . */
                  0x02, 0x02, 0x00, TCM_CONTEXT_ID_DEFAULT_VALUE,

                  /* req_n201u. */
                  0x0000,

                  /* AT_definition. */
                  0x01, /* 0000 0001. Only TCM_CGDCONT_DEFINED is set. Others are not. */

                  /* p_cscf_discovery, im_cn_signalling_flag, request_type. */
                  0x00, 0x00, 0x01, 


                  /* nas_priority, eab_override */
                  TCM_NAS_PRIORITY_CONFIG_NOT_SPECIFIED, TCM_EAB_OVERRIDE_CONFIG_NOT_SPECIFIED,

                  /* initial_attach. */
                  0x01
};

static nvram_ef_tcm_PDP_profile_record_struct const NVRAM_EF_TCM_PDP_PROFILE_DEFAULT[] = {
                  /* context_id, pdp_addr_type, pdp_addr_len. */
                  TCM_CONTEXT_ID_DEFAULT_VALUE, 0x21, 0x01,

                  /* addr_val[16]. */                  
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  /* apn_len. */
                  0x08,

                  /* apn[100]. */
                  0x69, 0x6E, 0x74, 0x65, 0x72, 0x6E, 0x65, 0x74, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  /* pcomp_algo, dcomp_algo, context_type(0:PRIMARY_CONTEXT), primary_context_id . */
                  0x02, 0x02, 0x00, TCM_CONTEXT_ID_DEFAULT_VALUE,

                  /* req_n201u. */
                  0x0000,

                  /* AT_definition. */
                  0x01, /* 0000 0001. Only TCM_CGDCONT_DEFINED is set. Others are not. */
                  
                  /* p_cscf_discovery, im_cn_signalling_flag, request_type. */
                  0x00, 0x00, 0x01, 
    
                  /* nas_priority, eab_override */
                  TCM_NAS_PRIORITY_CONFIG_NOT_SPECIFIED, TCM_EAB_OVERRIDE_CONFIG_NOT_SPECIFIED,

                  /* initial_attach. */
                  0x00
                  
};

static nvram_ef_sic_list_struct NVRAM_EF_SIC_LIST_DEFAULT[] = {

    /* is_tst_config_valid */ 
    KAL_FALSE, 

    /* Field: <sim-plmn-id>,<rat>,<qos>,<pdnReqType>,<v4AddrAlloc>,
     *         <v4dns>,<v4mtu>,<bcm>,<etft>. 
     */
    /* tst_config */ 
    {"000000", 0, {SIC_CHECK_NONE, SIC_RESULT_QOS_R6}, {SIC_CHECK_NONE, SIC_RESULT_PDNREQTYPE_NOT_CARRY}, {SIC_CHECK_NONE, SIC_RESULT_V4ADDRALLOC_NONE}, 
                  {SIC_CHECK_NONE, SIC_RESULT_V4REQ_NONE}, {SIC_CHECK_NONE, SIC_RESULT_V4REQ_NONE}, 
                  {SIC_CHECK_NONE, SIC_RESULT_BCMETFT_NONE}, {SIC_CHECK_NONE, SIC_RESULT_BCMETFT_NONE}}, 

    /* default_config */
    {"000000", 0, {SIC_CHECK_NONE, SIC_RESULT_QOS_R6}, {SIC_CHECK_NONE, SIC_RESULT_PDNREQTYPE_CAN_CARRY}, {SIC_CHECK_NONE, SIC_RESULT_V4ADDRALLOC_VIA_NASSIG}, 
                  {SIC_CHECK_NONE, SIC_RESULT_V4REQ_DNSV4}, {SIC_CHECK_NONE, SIC_RESULT_V4REQ_MTUV4}, 
                  {SIC_CHECK_NONE, SIC_RESULT_BCMETFT_BCM}, {SIC_CHECK_NONE, SIC_RESULT_BCMETFT_ETFT}},
    
    /* emergency_config */
    {"000000", 0, {SIC_CHECK_NONE, SIC_RESULT_QOS_R6}, {SIC_CHECK_NONE, SIC_RESULT_PDNREQTYPE_CAN_CARRY}, {SIC_CHECK_NONE, SIC_RESULT_V4ADDRALLOC_NONE}, 
                  {SIC_CHECK_NONE, SIC_RESULT_V4REQ_NONE}, {SIC_CHECK_NONE, SIC_RESULT_V4REQ_NONE}, 
                  {SIC_CHECK_NONE, SIC_RESULT_BCMETFT_NONE}, {SIC_CHECK_NONE, SIC_RESULT_BCMETFT_NONE}}, 

    /* entry[SIC_MAX_ENTRY_COUNT] - Need to increment NVRAM_EF_SIC_LIST_LID_VERNO */
    {
        {"46001", NVRAM_EF_RAT_GSM_UMTS, 
                  {SIC_CHECK_NONE, SIC_RESULT_QOS_R6}, {SIC_CHECK_NONE, SIC_RESULT_PDNREQTYPE_NOT_CARRY}, {SIC_CHECK_NONE, SIC_RESULT_V4ADDRALLOC_NONE}, 
                  {SIC_CHECK_NONE, SIC_RESULT_V4REQ_DNSV4}, {SIC_CHECK_SIM_OR_NW, SIC_RESULT_V4REQ_NONE}, 
                  {SIC_CHECK_NONE, SIC_RESULT_BCMETFT_BCM}, {SIC_CHECK_SIM_OR_NW, SIC_RESULT_BCMETFT_NONE}}, 

        // 0 - 9: 
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
       
        {"000000", 0, {SIC_CHECK_NONE, SIC_RESULT_QOS_R6}, {SIC_CHECK_NONE, SIC_RESULT_PDNREQTYPE_NOT_CARRY}, {SIC_CHECK_NONE, SIC_RESULT_V4ADDRALLOC_NONE}, 
                      {SIC_CHECK_NONE, SIC_RESULT_V4REQ_NONE}, {SIC_CHECK_NONE, SIC_RESULT_V4REQ_NONE}, 
                      {SIC_CHECK_NONE, SIC_RESULT_BCMETFT_NONE}, {SIC_CHECK_NONE, SIC_RESULT_BCMETFT_NONE}},                      
    }
} ;
#endif /* #if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__) */

static kal_uint8 const NVRAM_EF_CFU_FLAG_DEFAULT[] = {
                  0x55, 0x55
};

/* MT6291_DEV_Raphael NVRAM Re-structure Start (/) */
static nvram_ef_mm_data_struct const NVRAM_EF_MM_DATA_DEFAULT[] = {
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, //nvram_locigprs
    /* MT6291_DEV_Raphael 24.008 CR# 1791 RTC Start (/) */
    {
    0x00, //is plmn in eq plmn
    0x0f, 0x0f, 0x0f, 0x0f,	0x0f, 0x0f, //t3246 plmn
    0x00  //size of time_t, max is 8, check 
    }
    /* MT6291_DEV_Raphael 24.008 CR# 1791 RTC End (/) */
};
/* MT6291_DEV_Raphael NVRAM Re-structure End (/) */

#if defined(__ATCMD_ONOFF_CHECK__)
const nvram_atcmd_check_context_struct NVRAM_EF_ATCMD_ONOFF_CHECK_DEFAULT =
{
        {ATCMD_CHECK_ENABLE, 0x26598088, ATCMD_CHECK_ENABLE, 0X26598088},
        ATCMD_CHECK_ENABLE,  /* enable */
        {0x26598088, ATCMD_CHECK_ENABLE, 0x26598088}
};
#endif

#if !defined(__SMS_STORAGE_BY_MMI__) && (SMS_PHONE_ENTRY > 0)
static kal_uint8 const NVRAM_EF_SMSAL_SMS_DEFAULT[] = {
    0xfe,                            /* status */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF
};
#endif

/* Cell Broadcast Setting. */
/* The channels set will shown in MMI */
/* This setting may be changed by customer. DON'T remove it. */
static kal_uint8 const COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT[] =
{
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_mask, default all cbmir turn on */ 
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_me_mask, default all cbmir turn on */
    0xFF, 0xFF, 0xFF, 0xFF, /* dcs_mask, default all dcs turn on */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[0] ~ dcs[4] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[5] ~ dcs[9] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[10] ~ dcs[14] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[15] ~ dcs[19] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[20] ~ dcs[24] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[25] ~ dcs[29] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,/* cbmi_me_mask, default all ME cbmi turn on */ 
    0xFF, 0xFF, 0xFF, /* cbmi_sim_mask, default all SIM cbmi turn on */
#ifndef __CMAS__
    0xFF, 0xFF, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0xFF, 0xFF, /* CH 2  */
    0xFF, 0xFF, /* CH 3  */
    0xFF, 0xFF, /* CH 4  */
    0xFF, 0xFF, /* CH 5  */
    0xFF, 0xFF, /* CH 6  */
    0xFF, 0xFF, /* CH 7  */
    0xFF, 0xFF, /* CH 8  */
    0xFF, 0xFF, /* CH 9  */
    0xFF, 0xFF, /* CH 10 */
    0xFF, 0xFF, /* CH 11 */
    0xFF, 0xFF, /* CH 12 */
    0xFF, 0xFF, /* CH 13 */
#else
    0x11, 0x12, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0x11, 0x13, /* CH 2  */
    0x11, 0x14, /* CH 3  */
    0x11, 0x15, /* CH 4  */
    0x11, 0x16, /* CH 5  */
    0x11, 0x17, /* CH 6  */
    0x11, 0x18, /* CH 7  */
    0x11, 0x19, /* CH 8  */
    0x11, 0x1A, /* CH 9  */
    0x11, 0x1B, /* CH 10 */
    0x11, 0x1C, /* CH 11 */
    0x11, 0x1D, /* CH 12 */
    0x11, 0x1E, /* CH 13 */
#endif
    0xFF, 0xFF, /* CH 14 */
    0xFF, 0xFF, /* CH 15 */
    0xFF, 0xFF, /* CH 16 */
    0xFF, 0xFF, /* CH 17 */
    0xFF, 0xFF, /* CH 18 */
    0xFF, 0xFF, /* CH 19 */
    0xFF, 0xFF, /* CH 20 */
    0xFF, 0xFF, /* CH 21 */
    0xFF, 0xFF, /* CH 22 */
    0xFF, 0xFF, /* CH 23 */
    0xFF, 0xFF, /* CH 24 */
    0xFF, 0xFF, /* CH 25 */
    0xFF, 0xFF, /* CH 26 */
    0xFF, 0xFF, /* CH 27 */
    0xFF, 0xFF, /* CH 28 */
    0xFF, 0xFF, /* CH 29 */
    0xFF, 0xFF, /* CH 30 */
    0xFF, 0xFF, /* CH 31 */
    0xFF, 0xFF, /* CH 32 */
    0xFF, 0xFF, /* CH 33 */
    0xFF, 0xFF, /* CH 34 */
    0xFF, 0xFF, /* CH 35 */
    0xFF, 0xFF, /* CH 36 */
    0xFF, 0xFF, /* CH 37 */
    0xFF, 0xFF, /* CH 38 */
    0xFF, 0xFF, /* CH 39 */
    0xFF, 0xFF, /* CH 40 */
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 1*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 2*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 3*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 4*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 5*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 6*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 7*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 8*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 9*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 10*/
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 11*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 12*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 13*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 14*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 15*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 16*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 17*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 18*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 19*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 20*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 21*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 22*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 23*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 24*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 25*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 26*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 27*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 28*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 29*/ 
    0xFF, 0xFF, 0xFF, 0xFF  /*Range 30*/ 
};

#if defined(__IC_SLT__)
static kal_uint8 const NVRAM_EF_IMEI_DEFAULT[] = {0x53, 0x93,  0x91, 0x20, 0x65, 0x08, 0x31, 0x70, 0x00, 0x00};
#endif

static kal_uint8 const NVRAM_EF_PS_CONFORMANCE_TESTMODE_DEFAULT[] ={
    /* High 8 bit stores Test mode. Eg. CTA/FTA/IOT...   
         * And the value follow the rule like this:
         * 0x00  ==> Real NW
         * 0x01  ==> CTA
         * 0x02  ==> FTA
         * 0x03  ==> IOT
         * 0x04  ==> OPERATOR
         * ...
         */
    0x00,   
    /* Low 24 bit store the Special setting according to each MODE
         */
    0x00,0x00,
#ifdef __UE_SIMULATOR__
    0x02
#else
    0x00
#endif
};

#if defined(__ETWS_SUPPORT__)
const nvram_ef_etws_setting_struct NVRAM_EF_ETWS_SETTING_DEFAULT =
{
#ifdef __UE_SIMULATOR__
        0x01  /* always ON */
#else
        0x00
#endif        
};
#endif


static kal_uint8 const NVRAM_EF_CLASSMARK_RACAP_DEFAULT[] = {
       /*---BYTE 1 to BYTE 6 : From MS CLASSMARK3 -------------------------*/

    /*Evelyn 071127 add compile option for EDGE CARD: different power class*/
#if defined ( __EDGE_CARD_CLASS_12__ )

#if defined( __EGSM900__) && defined( __DCS1800__)
#if defined ( __DISABLE_EGSM__ )
                  0x50,  /* MS supports P-GSM and DCS band */
#else
                  0x60,  /* MS supports E-GSM and DCS band */
#endif                  
                  0x25,  /* E-GSM power class 5, DCS power class 2 */
#elif defined( __PGSM900__) && defined( __DCS1800__)
                  0x50,  /* MS supports P-GSM and DCS band */
                  0x25,  /* P-GSM power class 5, DCS power class 2 */
#elif defined( __EGSM900__)
                  0x60,  /* MS supports E-GSM band only */
                  0x05,  /* E-GSM power class 5 */
#elif defined (__PGSM900__)
                  0x60,  /* MS supports P-GSM band only */
                  0x05,  /* P-GSM power class 5 */
#elif defined ( __DCS1800__ )
                  0x40,  /* MS supports DCS band only */
                  0x02,  /* DCS power class 2 */
#else
                  0x00,  /* None of GSM900 and DCS1800 are supported */
                  0x00,
#endif

#else /*__EDGE_CARD_CALSS_12__  */
       /* Claire 030922 change : Support multiband compile option */
#if defined( __EGSM900__) && defined( __DCS1800__)
#if defined ( __DISABLE_EGSM__ )
                  0x50,  /* MS supports P-GSM and DCS band */
#else
                  0x60,  /* MS supports E-GSM and DCS band */
#endif                  
                  0x14,  /* E-GSM power class 4, DCS power class 1 */
#elif defined( __PGSM900__) && defined( __DCS1800__)
                  0x50,  /* MS supports P-GSM and DCS band */
                  0x14,  /* P-GSM power class 4, DCS power class 1 */
#elif defined( __EGSM900__)
                  0x60,  /* MS supports E-GSM band only */
                  0x04,  /* E-GSM power class 4 */
#elif defined (__PGSM900__)
                  0x60,  /* MS supports P-GSM band only */
                  0x04,  /* P-GSM power class 4 */
#elif defined ( __DCS1800__ )
                  0x40,  /* MS supports DCS band only */
                  0x01,  /* DCS power class 1 */
#else
                  0x00,  /* None of GSM900 and DCS1800 are supported */
                  0x00,
#endif

#endif /* __EDGE_CARD_CALSS_12__  */
                  0x01,  /* HSCSD multislot cap not present, UCS2 =1 */
                  /* Claire 030922 change : Support multiband compile option */

                  0x80 + /* Extended Measurement cap=1(1 bit), AGPS support(6 bit), GSM400/480(1 bit) */
#ifdef __AGPS_CONTROL_PLANE__
                  0x4e +
#endif /* __AGPS_CONTROL_PLANE__ */
#if defined( __GSM450__) || defined( __GSM480__)
                  0x01 +
#endif /* defined( __GSM450__) || defined( __GSM480__) */
                  0x00,
#if 0
#if defined( __GSM450__) || defined( __GSM480__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif /* __AGPS_CONTROL_PLANE__ */
#else
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif /* __AGPS_CONTROL_PLANE__ */
#endif
#endif

#if !defined( __GSM450__) && !defined( __GSM480__) && !defined( __GSM850__)
                  0x00,  /* GSM 400 and GSM 850 are not suported */
#elif defined( __GSM450__) && !defined( __GSM480__) && !defined( __GSM850__)
                 0x90,  /* GSM 450 is supported with power class 4*/
#elif !defined( __GSM450__) && defined( __GSM480__) && !defined( __GSM850__)
                 0x50,  /* GSM 480 is supported with power class 4*/
#elif !defined( __GSM450__) && !defined( __GSM480__) && defined( __GSM850__)
                 0x02,  /* GSM 850 is supported*/
#elif defined( __GSM450__) && defined( __GSM480__) && !defined( __GSM850__)
                 0xd0,  /* GSM 450 and 480 are supported with power class 4*/
#elif defined( __GSM450__) && !defined( __GSM480__) && defined( __GSM850__)
                 0x92,  /* GSM 450 with power class 4 and GSM 850 are supported*/
#elif !defined( __GSM450__) && defined( __GSM480__) && defined( __GSM850__)
                 0x52,  /* GSM 450 with power class 4 and GSM 850 are supported*/
#else
                 0xd2,   /* GSM 450, 480 with power class 4 and 850 are supported*/
#endif

/*Evelyn 071127 add compile option for EDGE CARD: different power class*/
#if defined( __EDGE_CARD_CLASS_12__ )

#if defined( __GSM850__) && defined( __PCS1900__)
                  0xb2,  /* GSM 850 is power class 5 ,PCS 1900 is suportedwith power class 2*/
#elif  defined( __PCS1900__)
                  0x12,  /* PCS 1900 is suported , power class 2 */
#elif  defined( __GSM850__)
                  0xa0,  /* GSM 850 is power class 5 */
#else
                  0x00,  /* Both GSM 850 and DCS 1900 are not supported */
#endif

#else /* __EDGE_CARD_CALSS_12__  */

#if defined( __GSM850__) && defined( __PCS1900__)
                  0x91,  /* GSM 850 is power class 4 ,PCS 1900 is suportedwith power class 1*/
#elif  defined( __PCS1900__)
                  0x11,  /* PCS 1900 is suported , power class 1 */
#elif  defined( __GSM850__)
                  0x80,  /* GSM 850 is power class 4 */
#else
                  0x00,  /* Both GSM 850 and DCS 1900 are not supported */
#endif

#endif /* __EDGE_CARD_CALSS_12__  */


       /*---BYTE 7 to BYTE 9 : From MS CLASSMARK2 -----------  */
                  0x30,  /* CM2 Byte1: ES_IND =1, Revision level =01, A51 algo supported---*/
                  0x58,  /* CM2 Byte2: PS cap =1, SS sreen indicator =01, SM cap =1 */

                  0x80 + /* CM2 Byte3: CM3 is supported */
#ifdef __AGPS_CONTROL_PLANE__
                  0x20 +
#endif /* __AGPS_CONTROL_PLANE__ */
/* bit 2 RESERVED for further usage */
                  0x02 +
#ifndef __DISABLE_A5_2__
                  0x01 +
#endif /* __DISABLE_A5_2__ */
#ifdef __CCBS_SUPPORT__
                  0x04 +
#endif /* __CCBS_SUPPORT__ */
                  0x00,

#if 0
/* under construction !*/
#if defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#elif defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#elif defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#elif defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#else //!defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#endif
#endif
       /*---BYTE 10 to BYTE 12 : From MS RA capability and MS network capability --*/

                           /* BYTE 10:
                            * bit 8: multislot capability present,
                            * bit 7 ~ 3: mutlislot capability,
                            * bit 2: GPRS extended Dynamic Allocation cap =1
                            * bit 1 : RL indicator = 0 => R98 MS, 1 => R99 MS */
#ifdef __R99__
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__GPRS_MULTISLOT_CLASS_10__)
                  0xab,   /* Default GPRS multislot class 10, ext DA support, R99 */
   #else
                  0xb3,  /* Default GPRS multislot class 12, ext DA support, R99 */
   #endif
#else /* __R99__*/
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__GPRS_MULTISLOT_CLASS_10__)
                  0xaa,   /* Default GPRS multislot class 10, ext DA support, R98 */
   #else
                  0xb2,  /* Default GPRS multislot class 12, ext DA support, R98 */
   #endif
#endif /* __R99__ */

                           /* BYTE 11:
                            * bit 8 : GEA1
                            * bit 7 : GEA2
                            * bit 6 : GEA3
                            * bit 5 : GEA4
                            * bit 4 : GEA5
                            * bit 3 : GEA6
                            * bit 2 : GEA7
                            * bit 1 : SM cap in GPRS =1 */
/* Peter 080520: change complie option */
#ifdef __NO_SUPPORT_A5_3__
                  0xc1, /* GEA1, 2 and SM cap support */
#else // The chip support A5/3(GEA/3)
    0xe1, /* GEA1, 2, 3 and SM cap support */
#endif

                           /* BYTE 12: Lanslo 20060215: for selecting GPRS or EGPRS capability
                             * bit 8: PFC mode = 0b
                             * bit 7: EDGE multislot class present / EDGE support = 1b
                             * bit 6 ~ 2: EDGE multislot capability = 01100b
                             * bit 1: EDGE extended dynamic allocation capability = 1b
                             * Old value 0x80, new 0xd9(PFC on), 0x59 (PFC off) */

/* Evelyn 20090511: open the PFC support bit */
#ifdef __EGPRS_MODE__
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__EDGE_MULTISLOT_CLASS_10__)
                  0xD5,   /* PFC on, EGPRS multislot class 10, Ext DA support */
   #else
                  0xD9,   /* PFC on, EGPRS multislot class 12, Ext DA support */
   #endif
#else /* __EGPRS_MODE__ */
   #ifdef __R99__
                  0x80,   /* PFC on */
   #else
                  0x00,   /* PFC off */
   #endif
#endif /* __EGPRS_MODE__ */

// Jelly 20090602 Use __EPSK_TX__
#if (defined(__EGPRS_MODE__) && defined(__EPSK_TX__))
                  0xAA,   /* BYTE 13: Evelyn 20090422: set 8PSK power class in NVRAM
                            * bit8~7 : 8psk radio cap 2 = E2 *
                            * bit6~5 : 8psk radio cap 1 = E2 *
                            * bit4~3 : 8psk 850 Band    = E2 *
                            * bit2~1 : 8psk 1900 Band   = E2 */
#else /* __EGPRS_MODE__ */
                  0x00,   /* No 8PSK power class */
#endif /* __EGPRS_MODE__ */

/* Modify for High multislot class */
#if defined (__MULTISLOT_CLASS_34__) || defined (__MULTISLOT_CLASS_45__)
#if defined(__EPSK_TX__) && !defined(__EPSK_TX_SW_SWITCH_OFF__)
                  0xEc    /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           *  bit 7   : high multislot class present or not
                           *  bit 6~1 : binany coding for high multislot value
                           *  For example, high multislot class 44 = 0x6c
                           */
#else
                  0x6c    /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           *  bit 7   : high multislot class present or not
                           *  bit 6~1 : binany coding for high multislot value
                           *  For example, high multislot class 44 = 0x6c
                           */
#endif
#else
#if defined(__EPSK_TX__) && !defined(__EPSK_TX_SW_SWITCH_OFF__)
                  0x80   /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           */
#else
                  0x00   /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           */
#endif
#endif

/* Byte 15: Rel4 Capabiility: GSM 750 cap(1 bit), TDD cap(1 bit), GERAN FP1(1 bit), Extended DTM(1 bit), 4 bits are spared */
                 ,0x00 +
#ifdef __UMTS_TDD128_MODE__
                  0x40 +
#endif /* __UMTS_TDD128_MODE__ */
#ifdef __GERAN_R4__
                  0x20 +
#endif /* __GERAN_R4__ */
                  0x00

/* Byte 16: Rel5 Capabiility: High Multislot(1 bit), GERAN lu Mode(1 bit), GERAN FP2(1 bit), GMSK Multislot(2 bit), 8PSK Multislot(2 bit), 1 bit is spared */
                 ,0x00

/* Byte 17: Rel6 Capabiility: T-GSM 400 cap(1 bit), T-GSM 900 cap(1 bit), SAIC(2 bit), DTM enhancements(1 bit), DTM GPRS High Multislot(1 bit), Repeated ACCH(1 bit), 1 bit is spared */
                 ,0x00 +
#ifdef __SAIC__
                  0x10 +
#endif /* __SAIC__ */
#ifdef __REPEATED_ACCH__
                  0x02 +
#endif /* __REPEATED_ACCH__ */
                  0x00

/* Byte 18: Rel7 Capabiility: GSM 710 cap(1 bit), T-GSM 810 cap(1 bit), Ciphering Mode Setting(1 bit), Additional Positioning cap(1 bit), 4 bits are spared */
                 ,0x00 +
#ifdef __POS_CAP_TRANSFER_PROCEDURE_SUPPORT__
                  0x10 +
#endif /* __POS_CAP_TRANSFER_PROCEDURE_SUPPORT__ */
                  0x00

/* Byte 19: Rel8 Capabiility: E-UTRA FDD(1 bit), E-UTRA TDD(1 bit), E-UTRA Measurement(1 bit), APBCR(1 bit), 4 bits are spared */
                 ,0x00 +
#ifdef __LTE_RAT__
                  0xe0 +
#endif /* __LTE_RAT__ */
#if defined(__23G_PRI_RESEL_SUPPORT__) || defined(__LTE_RAT__)
                  0x10 +
#endif /* defined(__23G_PRI_RESEL_SUPPORT__) || defined(__LTE_RAT__) */
                  0x00

/* Byte 20: Rel9 Capabiility: CSG reporting cap(1 bit), 7 bits are spared (VAMOS controlled via SBP)*/
                 ,0x00 +
#if defined(__VAMOS_2__) && defined(__CUSTOMIZE_VAMOS__)
                  0x40 +
#elif defined(__VAMOS_1__) && defined(__CUSTOMIZE_VAMOS__)
                  0x20 +
#else
                  0x00 +
#endif /* VAMOS */
                  0x00

/* Byte 21: Rel10 Capabiility: TIGHTER Cap(2 bit), Selective Ciphering of Downlink SACCH(1 bit), 5 bits are spared */
                 ,0x00

/* Byte 22: Rel11 Capabiility: CS to PS SRVCC from GERAN to UTRA(2 bit), CS to PS SRVCC from GERAN to E-UTRA(2 bit) */
/* Byte 22: Rel11 Capabiility: GERAN Network Sharing support(1 bit), E-UTRA Wideband RSRQ measurements support(1 bit), 2 bits are spared*/
                 ,0x04

/* Byte 23: Rel12 Capabiility: ER Band Support(1 bit), UTRA Multiple Frequency Band Indicators support(1 bit) */
/* Byte 23: Rel12 Capabiility: E-UTRA Multiple Frequency Band Indicators support(1 bit), Extended TSC Set Capability support(1 bit), */
/* Byte 23: Rel12 Capabiility: Extended EARFCN value range(1 bit), 3 bits are spared */ 
                 ,0x00 +
#if defined(__GERAN_R11__) && defined(__BAND_EXTENSION_SUPPORT__)
#ifdef __LTE_RAT__
                  0x08 + /*Extended EARFCN value range = 1*/
#endif /* __LTE_RAT__ */
#endif /* defined(__GERAN_R11__) && defined(__BAND_EXTENSION_SUPPORT__) */
                  0x00

};



/* UEM*/
static kal_uint8 const NVRAM_EF_UEM_MANUFACTURE_DATA_DEFAULT[] = {
                   'M',  'T',  'K',  '1', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#ifdef __DM_MO_SUPPORT__
                   'M',  'T',  'K',  '3', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#else
                   'M',  'T',  'K',  '2', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#endif
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '3', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '4', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '5', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                   'M',  'T',  'K',  '6', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '7', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                  };

#ifdef __TC02_SECURITY_REQUIREMENT__
static kal_uint8 const NVRAM_EF_MM_IMSI_LOCI_GLOCI_DEFAULT[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //EF_IMSI
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //EF_LOCI
    0xff, 0xff, 0xff, 0xff,	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff //EF_GLOCI
};
#endif /* __TC02_SECURITY_REQUIREMENT__ */

#ifdef __CARRIER_RESTRICTION__

/* Carrier Restriction */
const nvram_smu_carrier_match_context_struct NVRAM_EF_L4_CARRIER_RESTRICTION_DEFAULT =
{
    /* magic head */
    SML_CARRIER_RESTRICTION_MAGIC_HEAD_VALUE,
    /* key */
#ifdef __DISABLE_CRRST_LOCK__
    {SMU_CRRST_KEY_STATE_UNLOCKED,{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}},
#else
    {SMU_CRRST_KEY_STATE_LOCKED,{0x21,0x43,0x65,0x87,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}},
#endif
    /* black list */
    /* num of valid sets */
    {{{0}, {0}, {0}, {0}, {0}},
    /* category N code */
    {0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF},
    /* category SPN code */
    {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
    /* category IMSI prefix */
     {0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF},
    /* category GID1 code */
     {0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF},
    /* category GID2 code */
     {0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF}},
    /* white list */
    /* num of valid sets */
    {{{0}, {0}, {0}, {0}, {0}},
    /* category N code */
    {0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF},
    /* category SPN code */
    {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
    /* category IMSI prefix */
     {0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF,
      0xFF,0xFF,0xFF,0xFF},
    /* category GID1 code */
     {0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF},
    /* category GID2 code */
     {0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF,
     0xFF,0xFF,0xFF,0xFF}},
    /* allow_all */
     0x01,
    /* carrier rest state */
     SMU_CARRIER_RESTRICTION_ENABLED,
    /* allowed_carriers_prioritized */
     0x00,
    /* multi_sim_policy */
     0x00,
    /* magic tail */
     SML_CARRIER_RESTRICTION_MAGIC_TAIL_VALUE
};

#endif /* __CARRIER_RESTRICTION__ */


ltable_entry_struct logical_data_item_table_l4[] =
{
#if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)
	    {
	        NVRAM_EF_TCM_CID_0_PROFILE_LID,
	        NVRAM_EF_TCM_CID_0_PROFILE_TOTAL,
	        NVRAM_EF_TCM_CID_0_PROFILE_SIZE,
	        NVRAM_NORMAL(NVRAM_EF_TCM_CID_0_PROFILE_DEFAULT),
	        NVRAM_CATEGORY_USER,
	        NVRAM_ATTR_AVERAGE,
	        "MT47",
	        VER(NVRAM_EF_TCM_CID_0_PROFILE_LID)
	    },

	    {
	        NVRAM_EF_TCM_PDP_PROFILE_LID,
	        NVRAM_EF_TCM_PDP_PROFILE_TOTAL,
	        NVRAM_EF_TCM_PDP_PROFILE_SIZE,
	        NVRAM_NORMAL(NVRAM_EF_TCM_PDP_PROFILE_DEFAULT),
	        NVRAM_CATEGORY_USER,
	        NVRAM_ATTR_AVERAGE,
	        "MT48",
	        VER(NVRAM_EF_TCM_PDP_PROFILE_LID)
	    },
	    
	    {
	        NVRAM_EF_SIC_LIST_LID, 
	        NVRAM_EF_SIC_LIST_TOTAL, 
	        NVRAM_EF_SIC_LIST_SIZE, 
	        NVRAM_NORMAL(NVRAM_EF_SIC_LIST_DEFAULT), 
	        NVRAM_CATEGORY_USER, 
	        NVRAM_ATTR_AVERAGE, 
	        "MT7G", 
	        VER(NVRAM_EF_SIC_LIST_LID)
	    },
#endif // ~ #if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)

#ifdef __PS_SERVICE__
		{
			NVRAM_EF_PAM_PIB_PROFILE_LID, 
			NVRAM_EF_PAM_PIB_PROFILE_TOTAL, 
			NVRAM_EF_PAM_PIB_PROFILE_SIZE, 
			NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
			NVRAM_CATEGORY_USER, 
			NVRAM_ATTR_AVERAGE, 
			"MT4G",
			VER(NVRAM_EF_PAM_PIB_PROFILE_LID)
		},
#endif /* __PS_SERVICE__ */

		{
			NVRAM_EF_CFU_FLAG_LID,
			NVRAM_EF_CFU_FLAG_TOTAL,
			NVRAM_EF_CFU_FLAG_SIZE,
			NVRAM_NORMAL(NVRAM_EF_CFU_FLAG_DEFAULT),
			NVRAM_CATEGORY_USER,
			NVRAM_ATTR_AVERAGE,
			"MT49",
			VER(NVRAM_EF_CFU_FLAG_LID)
		},

		{
			/* MT6291_DEV_Raphael NVRAM Re-structure Start (/) */
				NVRAM_EF_MM_DATA_LID,
				NVRAM_EF_MM_DATA_TOTAL,
				NVRAM_EF_MM_DATA_SIZE,
				NVRAM_NORMAL(NVRAM_EF_MM_DATA_DEFAULT),
			/* MT6291_DEV_Raphael NVRAM Re-structure End (/) */
				NVRAM_CATEGORY_USER,
				NVRAM_ATTR_AVERAGE,
#ifdef __UMTS_FDD_MODE__          
				"MT4A",
#else
				"MT4E",
#endif
				/* MT6291_DEV_Raphael NVRAM Re-structure Start (/) */
				VER(NVRAM_EF_MM_DATA_LID)
				/* MT6291_DEV_Raphael NVRAM Re-structure End (/) */
		},

#if defined (__CPHS__) || defined (__CCM_NO_RESET__)
	    {
	        NVRAM_EF_ALS_LINE_ID_LID,
	        NVRAM_EF_ALS_LINE_ID_TOTAL,
	        NVRAM_EF_ALS_LINE_ID_SIZE,
	        NVRAM_CUSTPACK(COMMON_NVRAM_EF_ALS_LINE_ID_DEFAULT),
	        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
	        NVRAM_ATTR_AVERAGE,
	        "MT4C",
	        VER(NVRAM_EF_ALS_LINE_ID_LID)
	    },
#endif/* (__CPHS__) || (__CCM_NO_RESET__)*/

		{
			NVRAM_EF_MSCAP_LID,
			NVRAM_EF_MSCAP_TOTAL,
			NVRAM_EF_MSCAP_SIZE,
			NVRAM_CUSTPACK(COMMON_NVRAM_EF_MSCAP_DEFAULT),
			NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
			NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE, 
			"MT4D",
			VER(NVRAM_EF_MSCAP_LID)
		},

#if defined(__ATCMD_ONOFF_CHECK__)
		{
			NVRAM_EF_ATCMD_ON_OFF_CHECK_LID,
			NVRAM_EF_ATCMD_ON_OFF_CHECK_TOTAL,
			NVRAM_EF_ATCMD_ON_OFF_CHECK_SIZE,
			NVRAM_NORMAL(&NVRAM_EF_ATCMD_ONOFF_CHECK_DEFAULT),
			NVRAM_CATEGORY_USER,
			NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
			"MT30",
			VER(NVRAM_EF_ATCMD_ON_OFF_CHECK_LID)
		},
#endif

#if !defined(__SMS_STORAGE_BY_MMI__) && (SMS_PHONE_ENTRY > 0)
	    {
	        NVRAM_EF_SMSAL_SMS_LID,
	        NVRAM_EF_SMSAL_SMS_TOTAL,
	        NVRAM_EF_SMSAL_SMS_SIZE,
	        NVRAM_NORMAL(NVRAM_EF_SMSAL_SMS_DEFAULT),
	        NVRAM_CATEGORY_USER,
	        NVRAM_ATTR_MULTIREC_READ,
	        "MT40",
	        VER(NVRAM_EF_SMSAL_SMS_LID)
	    },
#endif

#if !defined(EXTERNAL_MMI)
	    {
	        NVRAM_EF_SMSAL_MAILBOX_ADDR_LID,
	        NVRAM_EF_SMSAL_MAILBOX_ADDR_TOTAL,
	        NVRAM_EF_SMSAL_MAILBOX_ADDR_SIZE,
	        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT),
	        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
	        NVRAM_ATTR_AVERAGE,
	        "MT41",
	        VER(NVRAM_EF_SMSAL_MAILBOX_ADDR_LID)
	    },
#endif

		{
			NVRAM_EF_SMSAL_COMMON_PARAM_LID,
			NVRAM_EF_SMSAL_COMMON_PARAM_TOTAL,
			NVRAM_EF_SMSAL_COMMON_PARAM_SIZE,
			NVRAM_CUSTPACK(COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT),
			NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
			NVRAM_ATTR_FACTORY_RESET,
			"MT42",
			VER(NVRAM_EF_SMSAL_COMMON_PARAM_LID)
		},

	    {
	        NVRAM_EF_SMSAL_SMSP_LID,
	        NVRAM_EF_SMSAL_SMSP_TOTAL,
	        NVRAM_EF_SMSAL_SMSP_SIZE,
	        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
	        NVRAM_CATEGORY_USER,
	        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
	        "MT43",
	        VER(NVRAM_EF_SMSAL_SMSP_LID)
	    },

		{
			NVRAM_EF_SMSAL_MWIS_LID,
			NVRAM_EF_SMSAL_MWIS_TOTAL,
			NVRAM_EF_SMSAL_MWIS_SIZE,
			NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
			NVRAM_CATEGORY_USER,
			NVRAM_ATTR_AVERAGE,
			"MT44",
			VER(NVRAM_EF_SMSAL_MWIS_LID)
		},

		{
			NVRAM_EF_CB_DEFAULT_CH_LID,
			NVRAM_EF_CB_DEFAULT_CH_TOTAL,
			NVRAM_EF_CB_DEFAULT_CH_SIZE,
			NVRAM_CUSTPACK(COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT),
			NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
			NVRAM_ATTR_FACTORY_RESET,
			"MT45",
			VER(NVRAM_EF_CB_DEFAULT_CH_LID)
		},
			
		{
			NVRAM_EF_CB_CH_INFO_LID,
			NVRAM_EF_CB_CH_INFO_TOTAL,
			NVRAM_EF_CB_CH_INFO_SIZE,
			NVRAM_NORMAL(COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT),
			NVRAM_CATEGORY_USER,
			NVRAM_ATTR_FACTORY_RESET,
			"MT46",
			VER(NVRAM_EF_CB_CH_INFO_LID)
		},
				
		{
			NVRAM_EF_IMEI_IMEISV_LID,
			NVRAM_EF_IMEI_IMEISV_TOTAL,
			NVRAM_EF_IMEI_IMEISV_SIZE,
#if defined(__IC_SLT__)
		NVRAM_NORMAL(NVRAM_EF_IMEI_DEFAULT),
#else
		NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
#endif
	
#ifdef __NVRAM_OTP__
			NVRAM_CATEGORY_OTP | NVRAM_CATEGORY_IMPORTANT,
#elif defined(__NVRAM_CUSTOM_DISK__)
			NVRAM_CATEGORY_CUSTOM_DISK,
#else
			NVRAM_CATEGORY_IMPORTANT,
#endif
	
#if defined(__NVRAM_OTP__) || defined(__NVRAM_CUSTOM_DISK__)
			NVRAM_ATTR_AVERAGE,
#else
			NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL,
#endif
			"MP0B",
			VER(NVRAM_EF_IMEI_IMEISV_LID)
		},
	
		{
			NVRAM_EF_SML_LID,
			NVRAM_EF_SML_TOTAL,
			NVRAM_EF_SML_SIZE,
			NVRAM_SECUPACK(&NVRAM_EF_SML_DEFAULT),
#ifdef __SMART_PHONE_MODEM__
			NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT_L4,
#elif defined(__CUSTOMER_TC01_DISK__) && !defined(WISDOM_MMI)
			NVRAM_CATEGORY_SECUPACK,
#else
			NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT,
#endif
			NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
			"MP33",
			VER(NVRAM_EF_SML_LID)
		},
					
#ifdef __SMART_PHONE_MODEM__
	{
		NVRAM_EF_SIM_LOCK_LID,
		NVRAM_EF_SIM_LOCK_TOTAL,
		NVRAM_EF_SIM_LOCK_SIZE,
		NVRAM_SECUPACK(&NVRAM_EF_SML_TMO_DEFAULT),
		NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT_L4,
		NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
		"MP6T",
		VER(NVRAM_EF_SIM_LOCK_LID)
	},
#endif

{
	NVRAM_EF_MS_SECURITY_LID,
	NVRAM_EF_MS_SECURITY_TOTAL,
	NVRAM_EF_MS_SECURITY_SIZE,
	NVRAM_CUSTPACK(COMMON_NVRAM_EF_MS_SECURITY_DEFAULT),
	NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
#ifdef __TC01__
	NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_FACTORY_RESET,
#else
	NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL,
#endif
	"MT6G",
	VER(NVRAM_EF_MS_SECURITY_LID)
},

#if !defined(L4_NOT_PRESENT)
#ifndef __PHB_STORAGE_BY_MMI__
	{
		NVRAM_EF_PHB_LID,
		NVRAM_EF_PHB_TOTAL,
		NVRAM_EF_PHB_SIZE,
		NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_MULTIREC_READ,
		"MT6V",
		VER(NVRAM_EF_PHB_LID)
	},
#endif
#endif

#if !defined(__PHB_NO_CALL_LOG__) & !defined(__L1_STANDALONE__)
    {
          NVRAM_EF_PHB_LN_ENTRY_LID,
          NVRAM_EF_PHB_LN_ENTRY_TOTAL,
          NVRAM_EF_PHB_LN_ENTRY_SIZE,
          NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE,
          "MT6H",
          VER(NVRAM_EF_PHB_LN_ENTRY_LID)
    },

    {
          NVRAM_EF_PHB_LN_TYPE_SEQ_LID,
          NVRAM_EF_PHB_LN_TYPE_SEQ_TOTAL,
          NVRAM_EF_PHB_LN_TYPE_SEQ_SIZE,
          NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE,
          "MT6I",
          VER(NVRAM_EF_PHB_LN_TYPE_SEQ_LID)
    },

#endif /* !defined(__PHB_NO_CALL_LOG__) & !defined(__L1_STANDALONE__) */

    {
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_TOTAL,
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE,
#ifdef __UE_SIMULATOR__
        NVRAM_NORMAL(NVRAM_EF_PS_CONFORMANCE_TESTMODE_DEFAULT),
#else
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
#endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6U",
        VER(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID)
    },

#if defined(__ETWS_SUPPORT__)
    {
            NVRAM_EF_ETWS_SETTING_LID,
            NVRAM_EF_ETWS_SETTING_TOTAL,
            NVRAM_EF_ETWS_SETTING_SIZE,
            NVRAM_NORMAL(&NVRAM_EF_ETWS_SETTING_DEFAULT),
            NVRAM_CATEGORY_USER,
            NVRAM_ATTR_AVERAGE,
            "MT32",
            VER(NVRAM_EF_ETWS_SETTING_LID)
    },
#endif

//__MOBILE_BROADBAND_PROVISION_CONTEXT__
#ifdef __MOBILE_BROADBAND_PROVISION_CONTEXT__
    {
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_LID,
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_TOTAL,
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT70",
        VER(NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_LID)
        //"MB PROVISION CONTEXT",
        //NVRAM_APP_RESERVED
    },        
#endif /* __MOBILE_BROADBAND_PROVISION_CONTEXT__ */

//__MEDIATEK_SMART_QOS__
#ifdef __MEDIATEK_SMART_QOS__
    {
        NVRAM_EF_MSQ_LIST_LID,
        NVRAM_EF_MSQ_LIST_TOTAL,
        NVRAM_EF_MSQ_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MSQ_LIST_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT74",
        VER(NVRAM_EF_MSQ_LIST_LID)
    },
#endif /* __MEDIATEK_SMART_QOS__ */

{
		NVRAM_EF_CSM_ESSP_LID,
		NVRAM_EF_CSM_ESSP_TOTAL,
		NVRAM_EF_CSM_ESSP_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"MT35",
		VER(NVRAM_EF_CSM_ESSP_LID)
},

	{
		NVRAM_EF_CLASSMARK_RACAP_LID,
		NVRAM_EF_CLASSMARK_RACAP_TOTAL,
		NVRAM_EF_CLASSMARK_RACAP_SIZE,
		NVRAM_NORMAL(NVRAM_EF_CLASSMARK_RACAP_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
#ifdef __UMTS_TDD128_MODE__
		"MT16",
#else
		"MT17",
#endif
		VER(NVRAM_EF_CLASSMARK_RACAP_LID)
	},
	
	{
		NVRAM_EF_CUST_HW_LEVEL_TBL_LID,
		NVRAM_EF_CUST_HW_LEVEL_TBL_TOTAL,
		NVRAM_EF_CUST_HW_LEVEL_TBL_SIZE,
#if defined(__MMI_FMI__)		
		NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_CUST_HW_LEVEL_TBL_DEFAULT),
#else
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
#endif
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_SW_VERNO_RESET | NVRAM_ATTR_ZIP_DEFAULT,
		"MT67",
		VER(NVRAM_EF_CUST_HW_LEVEL_TBL_LID)
	},

{
	NVRAM_EF_UEM_MANUFACTURE_DATA_LID,
	NVRAM_EF_UEM_MANUFACTURE_DATA_TOTAL,
	NVRAM_EF_UEM_MANUFACTURE_DATA_SIZE,
	NVRAM_NORMAL(NVRAM_EF_UEM_MANUFACTURE_DATA_DEFAULT),
	NVRAM_CATEGORY_USER,
	NVRAM_ATTR_ZIP_DEFAULT,
	"MT68",
	VER(NVRAM_EF_UEM_MANUFACTURE_DATA_LID)
},

    {
        NVRAM_EF_UEM_RMI_DATA_LID,
        NVRAM_EF_UEM_RMI_DATA_TOTAL,
        NVRAM_EF_UEM_RMI_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_ZIP_DEFAULT,
        "MT69",
        VER(NVRAM_EF_UEM_RMI_DATA_LID)
    },

		{
			NVRAM_EF_RAC_PREFERENCE_LID,
			NVRAM_EF_RAC_PREFERENCE_TOTAL,
			NVRAM_EF_RAC_PREFERENCE_SIZE,
			NVRAM_CUSTPACK(COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT),
			NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
			NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
			"MT6S",
			VER(NVRAM_EF_RAC_PREFERENCE_LID)
		},
		
#ifdef __TC02_SECURITY_REQUIREMENT__
		{																	
			NVRAM_EF_MM_IMSI_LOCI_GLOCI_LID,
			NVRAM_EF_MM_IMSI_LOCI_GLOCI_TOTAL,
			NVRAM_EF_MM_IMSI_LOCI_GLOCI_SIZE,
			NVRAM_SECUPACK(NVRAM_EF_MM_IMSI_LOCI_GLOCI_DEFAULT),
			NVRAM_CATEGORY_SECUPACK,
			NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
			"MT6T", 
			VER(NVRAM_EF_MM_IMSI_LOCI_GLOCI_LID)
		},
#endif  /* __TC02_SECURITY_REQUIREMENT__ */    

#ifdef __SYSSEL_SUPPORT__
    {
        NVRAM_EF_SYSSEL_SETTING_LID,
        NVRAM_EF_SYSSEL_SETTING_TOTAL,
        NVRAM_EF_SYSSEL_SETTING_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT73",
        VER(NVRAM_EF_SYSSEL_SETTING_LID),
    },
#endif /* __SYSSEL_SUPPORT__ */

{
	NVRAM_EF_REGIONAL_PHONE_MODE_LID,
	NVRAM_EF_REGIONAL_PHONE_MODE_TOTAL,
	NVRAM_EF_REGIONAL_PHONE_MODE_SIZE,
#ifdef __REGIONAL_PHONE__
	NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
#else
	NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
#endif
	NVRAM_CATEGORY_USER,
	NVRAM_ATTR_FACTORY_RESET,
	"MT78",
	VER(NVRAM_EF_REGIONAL_PHONE_MODE_LID),
},

{
	NVRAM_EF_SYS_CACHE_OCTET_LID,
	NVRAM_EF_SYS_CACHE_OCTET_TOTAL,
	NVRAM_EF_SYS_CACHE_OCTET_SIZE,
	NVRAM_NORMAL_NOT_GEN(NVRAM_EF_SYS_CACHE_OCTET_DEFAULT),
	NVRAM_CATEGORY_USER,
	NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_NOT_ZIP_DEFAULT,
	"MT6K",
	VER(NVRAM_EF_SYS_CACHE_OCTET_LID)
},

#ifdef __CARRIER_RESTRICTION__
    {
        NVRAM_EF_L4_CARRIER_RESTRICTION_LID,
        NVRAM_EF_L4_CARRIER_RESTRICTION_TOTAL,
        NVRAM_EF_L4_CARRIER_RESTRICTION_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_L4_CARRIER_RESTRICTION_DEFAULT),
        NVRAM_CATEGORY_IMPORTANT_L4,
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_COMMITTED,
        "LDCR",
        VER(NVRAM_EF_L4_CARRIER_RESTRICTION_LID)
    },
#endif /* __CARRIER_RESTRICTION__ */

	NVRAM_LTABLE_END
};

#endif
