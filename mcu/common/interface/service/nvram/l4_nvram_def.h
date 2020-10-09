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
#ifndef __L4_NVRAM_DEF_H__
#define __L4_NVRAM_DEF_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "ps_public_enum.h"
#ifdef __MULTI_LEVEL_BACKLIGHT_SUPPORT__
#include "custom_hw_default.h"
#endif

#include "device.h"

typedef enum
{
        NVRAM_EF_L4_START                   = NVRAM_LID_GRP_L4(0),
        NVRAM_EF_TCM_CID_0_PROFILE_LID      = NVRAM_EF_L4_START,
        NVRAM_EF_TCM_PDP_PROFILE_LID,
        NVRAM_EF_PAM_PIB_PROFILE_LID,
        NVRAM_EF_CFU_FLAG_LID,
        /* MM NVRAM Re-structure Start */
        NVRAM_EF_MM_DATA_LID,
        /* MM NVRAM Re-structure End */
        NVRAM_EF_CTM_DEFAULT_SETTINGS_LID,
        NVRAM_EF_ALS_LINE_ID_LID,
        NVRAM_EF_MSCAP_LID,
        NVRAM_EF_ATCMD_ON_OFF_CHECK_LID,
        NVRAM_EF_SMSAL_SMS_LID,
        NVRAM_EF_SMSAL_MAILBOX_ADDR_LID,
        NVRAM_EF_SMSAL_COMMON_PARAM_LID,
        NVRAM_EF_SMSAL_SMSP_LID,
        NVRAM_EF_SMSAL_MWIS_LID,
        NVRAM_EF_CB_DEFAULT_CH_LID,
        NVRAM_EF_CB_CH_INFO_LID,
        NVRAM_EF_IMEI_IMEISV_LID,
        NVRAM_EF_SML_LID,                   /* SIM-ME Lock */
        NVRAM_EF_SIM_LOCK_LID, /* __SMART_PHONE_MODEM__ */
        NVRAM_EF_MS_SECURITY_LID,
 //   #ifndef __PHB_STORAGE_BY_MMI__
        NVRAM_EF_PHB_LID,
 //   #endif
        NVRAM_EF_PHB_LN_ENTRY_LID,      //__PHB_NO_CALL_LOG__
        NVRAM_EF_PHB_LN_TYPE_SEQ_LID,   //__PHB_NO_CALL_LOG__
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,   /* 2010.11.4   Add for EM menu for TestMode */
        NVRAM_EF_ETWS_SETTING_LID,
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_LID, //__MOBILE_BROADBAND_PROVISION_CONTEXT__
        NVRAM_EF_MSQ_LIST_LID,    //__MEDIATEK_SMART_QOS__ (MSQ)
        NVRAM_EF_SIC_LIST_LID, 
        NVRAM_EF_CSM_ESSP_LID,
 
        NVRAM_EF_CLASSMARK_RACAP_LID,           
        NVRAM_EF_CUST_HW_LEVEL_TBL_LID,
        NVRAM_EF_UEM_MANUFACTURE_DATA_LID,
        NVRAM_EF_UEM_RMI_DATA_LID,
        NVRAM_EF_RAC_PREFERENCE_LID,
        NVRAM_EF_MM_IMSI_LOCI_GLOCI_LID,  //for man-in-middle-attach prevention
        NVRAM_EF_SYSSEL_SETTING_LID, /* for +SYSSEL*/ 
        NVRAM_EF_REGIONAL_PHONE_MODE_LID,
        NVRAM_EF_SYS_CACHE_OCTET_LID,
        NVRAM_EF_L4_CARRIER_RESTRICTION_LID,

		/*Add LID before NVRAM_EF_L4_LAST_LID*/
        NVRAM_EF_L4_LAST_LID        = NVRAM_LID_GRP_L4(255)
}nvram_lid_l4_enum;

/**
 * RAC preference
 */
typedef struct
{
    kal_uint8 arg1;
    kal_uint8 rat_mode;
    kal_uint8 preferred_rat;
    kal_uint8 preference;
    kal_uint8 roaming_setting;
    kal_uint8 mm_ivt;
    kal_uint8 utran_vdp;
    kal_uint8 reported_rat;
    kal_uint8  c2k_preferred_rat;
#ifdef __GEMINI_WCDMA_WORLD_PHONE__
    kal_uint8 user_rat_mode;
#endif
} nvram_ef_rac_preference_struct;


/* How many log data in one NVRAM record, never change it */
#define NVRAM_EF_PHB_LN_SIZE                    (10)


/* call name buffer size */
#if defined(__L4_MAX_NAME_60__)
#define PHB_LN_NAME_SIZE                        (62)
#elif defined(__L4_MAX_NAME_20__)
#define PHB_LN_NAME_SIZE                        (22)
#else /* defined(__L4_MAX_NAME_30__) */
#define PHB_LN_NAME_SIZE                        (32)
#endif /* defined(__L4_MAX_NAME_60__) */

/* Call number buffer size */
#if defined __VOIP__  /* It's ok to do this as VoIP is turned off on naptune */
#define PHB_LN_NUM_SIZE                         ((41 >= (VOIP_URI_LEN)) ? 41 : (VOIP_URI_LEN))
#else
#define PHB_LN_NUM_SIZE                         (41)
#endif



/* MM NVRAM Re-structure Start */
#define NVRAM_EF_MM_DATA_SIZE sizeof(nvram_ef_mm_data_struct) //plmn 6 bytes, is_plmn 1 byte, time_t byte, max 8
#define NVRAM_EF_MM_LOCI_GPRS_SIZE 14 


#if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)
/**
 * TCM cid_0 profile 
 */
#define NVRAM_EF_TCM_CID_0_PROFILE_SIZE (sizeof(nvram_ef_tcm_PDP_profile_record_struct))
#define NVRAM_EF_TCM_CID_0_PROFILE_TOTAL (1 * (NVRAM_DUAL_RECORD))

/**
 * TCM PDP profile
 */
#define NVRAM_EF_TCM_PDP_PROFILE_SIZE (sizeof(nvram_ef_tcm_PDP_profile_record_struct)) //erica 20070112
#define NVRAM_EF_TCM_PDP_PROFILE_TOTAL ((MAX_EXT_PDP_CONTEXT) * (NVRAM_DUAL_RECORD)) // Carlson 20100125: modify nvram record to reduce ROM (do not use fix value, instead, use compile option to determine the total record)

/**
 * SIC list
 */
#define NVRAM_EF_SIC_LIST_SIZE  sizeof(nvram_ef_sic_list_struct) 
#define NVRAM_EF_SIC_LIST_TOTAL 1 /* All SIM cards share the same config. */
#endif // ~ #if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)

#ifdef __PS_SERVICE__
/**
 * PAM PIB profile
 */
#define NVRAM_EF_PAM_PIB_PROFILE_SIZE (sizeof(nvram_ef_pam_pib_profile_struct))
#define NVRAM_EF_PAM_PIB_PROFILE_TOTAL (1 * NVRAM_DUAL_RECORD)
#endif /* __PS_SERVICE__ */

#define NVRAM_EF_CFU_FLAG_SIZE             1
#define NVRAM_EF_CFU_FLAG_TOTAL            (1 * NVRAM_DUAL_RECORD)

#if defined(__SGLTE_DSDS__) || defined(__DUAL_SIM_PROJECT_SUPPORT_SGLTE_WORLD_PHONE_NVRAM__)
#define NVRAM_EF_MM_DATA_TOTAL 4
#else
#define NVRAM_EF_MM_DATA_TOTAL (1 * NVRAM_DUAL_RECORD)
#endif

#if defined(__CCM_NO_RESET__)
/**
 * Add last call cost
 */
#define NVRAM_EF_ALS_LINE_ID_SIZE             6
#define NVRAM_EF_ALS_LINE_ID_TOTAL            (1 * NVRAM_DUAL_RECORD)
#elif defined (__CPHS__)
/**
 * Line id
 */
#define NVRAM_EF_ALS_LINE_ID_SIZE             2
#define NVRAM_EF_ALS_LINE_ID_TOTAL            (1 * NVRAM_DUAL_RECORD)
#endif

/**
 * MSCAP
 */
//[MAUI_00740014]: __REL4__ supported speech codec
//0528_AMRWB
#define NVRAM_EF_MSCAP_SIZE              12

#define NVRAM_EF_MSCAP_TOTAL             1

#define NVRAM_EF_ATCMD_ON_OFF_CHECK_SIZE        (sizeof(nvram_atcmd_check_context_struct))
#define NVRAM_EF_ATCMD_ON_OFF_CHECK_TOTAL     1

#define NVRAM_EF_SMSAL_SMS_TOTAL    (SMS_PHONE_ENTRY * NVRAM_DUAL_RECORD)
#define NVRAM_EF_SMSAL_SMS_SIZE              184

/**
 * SMSAL mailbox addresses
 */
#ifdef __MAX_MAILBOX_NAME_UPDATA_TO_30__
#define NVRAM_EF_SMSAL_MAILBOX_ADDR_SIZE           54
#else
#define NVRAM_EF_SMSAL_MAILBOX_ADDR_SIZE           34
#endif
#ifdef __SMS_MSP_UP_TO_4__
#define NVRAM_EF_SMSAL_MAILBOX_ADDR_TOTAL          (4 * NVRAM_DUAL_RECORD)
#else
#define NVRAM_EF_SMSAL_MAILBOX_ADDR_TOTAL          (2 * NVRAM_DUAL_RECORD)
#endif

/**
 * SMSAL common parameters
 */
#define NVRAM_EF_SMSAL_COMMON_PARAM_SIZE           16
#define NVRAM_EF_SMSAL_COMMON_PARAM_TOTAL          (1 * NVRAM_DUAL_RECORD)

/**
 * SMSAL short message service parameters
 */
#define NVRAM_EF_SMSAL_SMSP_SIZE           40   /* 28(SMSAL_SMSP_LEN)+10 */
#define NVRAM_EF_SMSAL_SMSP_TOTAL          (2 * NVRAM_DUAL_RECORD)

/**
 * SMSAL message waiting indication status
 */
#define NVRAM_EF_SMSAL_MWIS_SIZE           6
/* Due to let __REL4__ can put into modem internal, we default announce 5 (4 MSP + Line2)*/
#define NVRAM_EF_SMSAL_MWIS_TOTAL          (5 * NVRAM_DUAL_RECORD)

/**
 * CB Default Channel Setting
 */
#define NVRAM_EF_CB_DEFAULT_CH_SIZE          20
#define NVRAM_EF_CB_DEFAULT_CH_TOTAL         (1 * NVRAM_DUAL_RECORD)

/**
 * CB Mask
 */
#define NVRAM_EF_CB_CH_INFO_SIZE              sizeof(nvram_ef_cb_ch_info_struct)
#define NVRAM_EF_CB_CH_INFO_TOTAL             (1 * NVRAM_DUAL_RECORD)

/**
 * IMEI/IMEISV
 */
#ifdef __SMART_PHONE_MODEM__
#define NVRAM_EF_IMEI_IMEI_SIZE           8
#define NVRAM_EF_IMEI_IMEISV_SIZE         10
#define NVRAM_EF_IMEI_IMEISV_TOTAL        10
#else
#define NVRAM_EF_IMEI_IMEI_SIZE           8
#define NVRAM_EF_IMEI_IMEISV_SIZE         10
#define NVRAM_EF_IMEI_IMEISV_TOTAL        (1 * NVRAM_DUAL_RECORD)
#endif

/*
 * SIM-ME Lock
 */
#ifdef __SMART_PHONE_MODEM__
#define NVRAM_EF_SML_SIZE   sizeof(nvram_sml_context_struct)
#define NVRAM_EF_SML_TOTAL  10
#else
#define NVRAM_EF_SML_SIZE   sizeof(nvram_sml_context_struct)
#define NVRAM_EF_SML_TOTAL  (1 * NVRAM_DUAL_RECORD)
#endif

#ifdef __CARRIER_RESTRICTION__
#define NVRAM_EF_L4_CARRIER_RESTRICTION_SIZE sizeof(nvram_smu_carrier_match_context_struct)
#define NVRAM_EF_L4_CARRIER_RESTRICTION_TOTAL 1
#endif /* __CARRIER_RESTRICTION__ */

//#ifdef  __SMART_PHONE_MODEM__
#define NVRAM_EF_SIM_LOCK_SIZE sizeof(nvram_sml_tmo_context_struct)
#define NVRAM_EF_SIM_LOCK_TOTAL (1 * NVRAM_DUAL_RECORD)
//#endif

/*
 * MS Security
 */
#define NVRAM_EF_MS_SECURITY_SIZE         (38)
#define NVRAM_EF_MS_SECURITY_TOTAL        (1 * NVRAM_DUAL_RECORD)

#if !defined(L4_NOT_PRESENT)
#ifndef __PHB_STORAGE_BY_MMI__
#define NVRAM_EF_PHB_SIZE                  sizeof(nvram_ef_phb_struct)
#define NVRAM_EF_PHB_TOTAL                 MAX_PHB_PHONE_ENTRY
#endif
#endif

/* Record size */
#define NVRAM_EF_PHB_LN_ENTRY_SIZE              (sizeof(nvram_ef_phb_ln_struct))

/* Record total number */
#if (MAX_PHB_LN_ENTRY > 20)
#define NVRAM_EF_PHB_LN_ENTRY_TOTAL             ((((MAX_PHB_LN_ENTRY + NVRAM_EF_PHB_LN_SIZE - 1) / NVRAM_EF_PHB_LN_SIZE) * 3) * (NVRAM_DUAL_RECORD))
#else /* If define __L4_MAX_NAME_60__, the total LN is fixed to 15 * 3 = 45, please check it in phb_defs.h */
#define NVRAM_EF_PHB_LN_ENTRY_TOTAL             (6 * NVRAM_DUAL_RECORD)
#endif

/* Record size and total number */
#define NVRAM_EF_PHB_LN_TYPE_SEQ_SIZE           (NVRAM_EF_PHB_LN_ENTRY_TOTAL * NVRAM_EF_PHB_LN_SIZE / NVRAM_DUAL_RECORD)
#define NVRAM_EF_PHB_LN_TYPE_SEQ_TOTAL          (1 * NVRAM_DUAL_RECORD)

/**
 * PS TestMode Read/Write by L4C
 */
#define  NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE      4
#define  NVRAM_EF_PS_CONFORMANCE_TESTMODE_TOTAL     1

#define NVRAM_EF_ETWS_SETTING_SIZE        (sizeof(nvram_ef_etws_setting_struct))
#define NVRAM_EF_ETWS_SETTING_TOTAL     1

/*
 * __MOBILE_BROADBAND_PROVISION_CONTEXT__: Read/Write by L4C
 */
#define  NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_SIZE      sizeof(nvram_ef_mobile_broadband_provision_context_struct)
#define  NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_TOTAL     10

/**
 * __MEDIATEK_SMART_QOS__
 */
#ifdef __MEDIATEK_SMART_QOS__
#define  NVRAM_EF_MSQ_LIST_SIZE       sizeof(nvram_ef_msq_list_struct)
#define  NVRAM_EF_MSQ_LIST_TOTAL      1   /* All SIM cards share the same list. */
#endif /* __MEDIATEK_SMART_QOS__ */

/**
 * CFU FLAG
 */

#define NVRAM_EF_CSM_ESSP_SIZE             1
#define NVRAM_EF_CSM_ESSP_TOTAL            1

/* For R11, NVRAM_EF_CLASSMARK_RACAP_DEFAULT[] will occupy 23 bytes.  */
#define NVRAM_EF_CLASSMARK_RACAP_SIZE          23
#define NVRAM_EF_CLASSMARK_RACAP_TOTAL         1

/* UEM*/
#if 0//__BK_LIGHT_20LEVEL_SUPPORT__
/* under construction !*/
#elif defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)
#define NVRAM_EF_CUST_HW_LEVEL_TBL_SIZE     (440+8*PWM_MAX_BACKLIGHT_LEVEL)
#else
#define NVRAM_EF_CUST_HW_LEVEL_TBL_SIZE     440
#endif
#define NVRAM_EF_CUST_HW_LEVEL_TBL_TOTAL   1

/**
 * UEM Manufacturer data
 */
#ifndef __L1_STANDALONE__
#define NVRAM_EF_UEM_MANUFACTURE_DATA_SIZE         MAX_ME_ID_NUM * MAX_ME_ID_LEN
#else
#define NVRAM_EF_UEM_MANUFACTURE_DATA_SIZE         240
#endif
#define NVRAM_EF_UEM_MANUFACTURE_DATA_TOTAL        1

/**
 * UEM RMI data
 */
#define NVRAM_EF_UEM_RMI_DATA_SIZE                 216  /* 182 */
#define NVRAM_EF_UEM_RMI_DATA_TOTAL                1

#define NVRAM_EF_RAC_PREFERENCE_SIZE         sizeof(nvram_ef_rac_preference_struct) 
#if defined(__SGLTE_DSDS__) || defined(__DUAL_SIM_PROJECT_SUPPORT_SGLTE_WORLD_PHONE_NVRAM__)
#define NVRAM_EF_RAC_PREFERENCE_TOTAL        4
#else
#define NVRAM_EF_RAC_PREFERENCE_TOTAL        (1 * NVRAM_DUAL_RECORD)
#endif

/* MM NVRAM Re-structure End */

#define NVRAM_EF_MM_IMSI_LOCI_GLOCI_SIZE (9+11+14)
#define NVRAM_EF_MM_IMSI_LOCI_GLOCI_TOTAL (1 * NVRAM_DUAL_RECORD)

#ifdef __SYSSEL_SUPPORT__
#define NVRAM_EF_SYSSEL_SETTING_SIZE 1
#define NVRAM_EF_SYSSEL_SETTING_TOTAL (1 * NVRAM_DUAL_RECORD)
#endif

#define NVRAM_EF_REGIONAL_PHONE_MODE_SIZE (1)
#define NVRAM_EF_REGIONAL_PHONE_MODE_TOTAL (1)

/**
 * System Cache OCTET : This is a special NVRAM data item used for storage purpose.
 *                                   Please note that the default value is ALWAYS 0x00
 */
#define NVRAM_EF_SYS_CACHE_OCTET_SIZE        8
#define NVRAM_EF_SYS_CACHE_OCTET_TOTAL     20






#ifdef __cplusplus
}
#endif 

#endif
