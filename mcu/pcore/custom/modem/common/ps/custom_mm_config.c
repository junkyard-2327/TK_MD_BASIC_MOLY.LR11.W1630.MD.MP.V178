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
 * custom_mm_config.c
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the MM configuration.
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
 * removed!
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "custom_mm_config.h"
#include "ps_public_enum.h"
#include "gmss_public.h"


/*************************************************************************
 * This custom array can be used by our customers to enhance lazy mode operation and 
 *  choose a custom IRAT_TAU_TYPE
 * 
 *   Ex: CUSTOM_IRAT_TAU_TYPE_FOR_LAZY_GMM[] = 
 *           {"46697F","46689F",INVALID_CUSTOM_PLMN}         
 *************************************************************************/

const char *CUSTOM_IRAT_TAU_TYPE_FOR_LAZY_GMM[] = {"46697F","42902F","45008F",INVALID_CUSTOM_PLMN};
const kal_uint32 CUSTOM_IRAT_TAU_TYPE_FOR_LAZY_GMM_NUM = sizeof(CUSTOM_IRAT_TAU_TYPE_FOR_LAZY_GMM)/sizeof(char *);

/*****************************************************************************
* FUNCTION
*  mm_custom_stay_on_la_of_regional_provisional_service
* DESCRIPTION
*  This function is for customize MM behavior when entering forbidden LA of #12
*
* PARAMETERS
*
* RETURNS
*  MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_SERVICE
*      follow spec (enter limited service and stay on forbidden LA of #12)
*  MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_ONLY_IF_TEST_SIM_TEST_MODE
*      follow spec (enter limited service and stay on forbidden LA of #12) 
*      only when test sim is inserted or test mode(CTA/FTA/Operator) is enabled
*  MM_NOT_STAY_ON_LA_OF_REGINOAL_PROVISIONAL_SERVICE
*      allow MS directly retry other PLMN/RAT for normal service
* GLOBALS AFFECTED
*   None
*****************************************************************************/
mm_rej_12_handle_enum mm_custom_stay_on_la_of_regional_provisional_service(void)
{
    //suggest to use default setting [MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_SERVICE]
    //change this setting might affect the result of FTA or IOT.
    //may only be changed on production version of software after pass all lab test
    if (sbp_query_md_feature(SBP_MM_NOT_STAY_ON_FBLA_FOR_REG_PROV) == KAL_TRUE)
    {
        return MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_ONLY_IF_TEST_SIM_TEST_MODE;
    }
    else
    {
        return MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_SERVICE;
    }
}

/*****************************************************************************
* FUNCTION
*  mm_custom_registration_related_setting
* DESCRIPTION
*  This function is used to query registration related setting.
*
* PARAMETERS
*  Which setting
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_registration_related_setting(mm_setting_enum setting)
{

  switch(setting)
  { 
   
   case MM_ENABLE_LR_REJ111_RETRY:
      {
#ifndef __DISABLE_LR_REJ111_RETRY__   
			  return KAL_TRUE;
#else
			  return KAL_FALSE;
#endif
        break;
      } 
   case MM_ENABLE_HPPLMN_SEARCH_FORCE_RELEASE_PCH_CONNECTION:
	  {	 
#ifndef __DISABLE_HPPLMN_SEARCH_FORCE_RELEASE_PCH_CONNECTION__
			  return KAL_TRUE;
#else
			  return KAL_FALSE;
#endif  
		break;
	  } 
 
   default:
   		break;
  }
  
  return KAL_FALSE;
} 

/* MAUI_03014009 Russia Operator BeeLine request to use ECC with IMEI */
/*****************************************************************************
* FUNCTION
*  mm_custom_force_ecc_with_imei
* DESCRIPTION
*  This function configures emergency call force to use IMEI during phone lock period.
*  default: KAL_FALSE (using TMSI->IMSI->IMEI)
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_force_ecc_with_imei(void)
{
    return KAL_FALSE;
}

/* ALPS01451877 UK should be allowed to make emergency calls with expired SIM cards */
const kal_uint32 ECC_IMSI_MCC_LIST[] = {234, 235};
const kal_uint32 ECC_IMSI_MCC_NUM = sizeof(ECC_IMSI_MCC_LIST)/sizeof(kal_uint32);
/*****************************************************************************
* FUNCTION
*   mm_custom_is_try_abnormal_lai_once_more
* DESCRIPTION
*   If abnormal LU 4 times happen, MS will try to search other available and allowable PLMNs. If no other PLMN is found,
*   MS will go back to the abnormal-4-times PLMN and do registration with another 4 attempts.
*
* PARAMETERS
*   none
* RETURNS
*   kal_bool - indicate if "try abnormal lai once more" is enabled.
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mm_custom_is_try_abnormal_lai_once_more(void)
{
    return sbp_query_md_feature(SBP_MM_TRY_ABNORMAL_LAI_ONCE_MORE);
}

/*****************************************************************************
* FUNCTION
*  mm_custom_start_timer_for_mt_mm_conn
* DESCRIPTION
*  This function is used to configure whether start T3240 for page.
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_start_timer_for_mt_mm_conn(void)
{
    /*work around CMCC 3G network issue
    1. PS signaling exist, receive page for CS domain
    2. send page response, enter MM_WAIT_FOR_NETWORK_COMMAND
    3. handover to another LA, then no MM or CM message from network
    4. can not process CM request until cs signaling or RRC release
    */
    return KAL_TRUE;
}

/*For Customer Default test plmn. Follows TS34.123 Table 6.2  */
const char *CUSTOM_TEST_PLMN[] = 
    {"00101", "00211", "00321", "00431", "00541", "00651",
     "00761", "00871", "00902", "01012", "01122", "01232" , CUSTOM_TEST_PLMN_SET_END};

const kal_uint32 CUSTOM_TEST_PLMN_NUM = sizeof(CUSTOM_TEST_PLMN)/sizeof(char *);

/*****************************************************************************
* FUNCTION
*  mm_custom_get_erase_forbidden_la_list_timer_period
* DESCRIPTION
*  This function is used to get ERASE_FORBIDDEN_LA_LIST timer period.
*
* PARAMETERS
*  None
*
* RETURNS
*  kal_uint32
*
* GLOBALS AFFECTED
*  None
*
*****************************************************************************/
kal_uint32 mm_custom_get_erase_forbidden_la_list_timer_period(void)
{
    // TS24.008 specifies this timer should be 12~24hr.
    // Default 12hr.
    // Set 0 to disable this timer
    return 12*60*KAL_TICKS_1_MIN;
}

/*************************************************************************
 * In Japan, UE can not perform MO emergency call if UE has not completed registration procedure 
 * (so, MSC does not know MSISDN of mobile originating user), because transferring MSISDN of
 * mobile originating user to emergency authority is mandatory
 *
 * Example:
 * 1.
 * const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {440}; // Only in Japan does UE need perform LR before ECC
 * 2.
 * const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {NO_MCC_ALLOWED}; // UE shall perform ECC before LR regardless of MCC
 * 3.
 * const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {ALL_MCC_ALLOWED}; // UE shall perform LR before ECC regardless of MCC
 *
 *************************************************************************/
#if defined(__MM_PERFORM_LU_BEFORE_ECC__)
const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {ALL_MCC_ALLOWED};
#elif defined(__DOCOMO_IOT_LR_BEFORE_ECC__)
const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {440};
#else
const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {NO_MCC_ALLOWED};
#endif
const kal_uint32 LR_BEFORE_ECC_MCC_NUM = sizeof(LR_BEFORE_ECC_MCC_LIST)/sizeof(kal_uint32);



/***************************************************************************************************
 * For below MCC list, UE shall re-attach after NW inititated DETACH with detach type "re-attach 
 *  not required" for cause other than  #2/#3/#6/#7/#8/#11/#12/#13/#14/#15/#25
 *
 * Example:
 * 1.
 * const kal_uint32 GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE_MCC_LIST[] = {440}; 
 * 2.
 * const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {NO_MCC_ALLOWED}; 
 *
 ***************************************************************************************************/

#if defined(__GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE_CUSTOM_MCC__)
const kal_uint32 GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE_MCC_LIST[] = {466};
#else
const kal_uint32 GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE_MCC_LIST[] = {NO_MCC_ALLOWED};
#endif
const kal_uint32 GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE_MCC_NUM = sizeof(GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE_MCC_LIST)/sizeof(kal_uint32);


#ifndef __MM_DISABLE_PERFORM_LU_BEFORE_CSFB_ECC__
const char *LR_BEFORE_CSFB_ECC_PLMN_LIST[] = {"23420" ,"23594" , LR_BEFORE_CSFB_ECC_PLMN_SET_END};
#else
const char *LR_BEFORE_CSFB_ECC_PLMN_LIST[] = {LR_BEFORE_CSFB_ECC_PLMN_SET_END};
#endif
const kal_uint32 LR_BEFORE_CSFB_ECC_PLMN_NUM = sizeof(LR_BEFORE_CSFB_ECC_PLMN_LIST)/sizeof(char *);

/*****************************************************************************
* FUNCTION
*  mm_custom_enable_early_oos_ind
* DESCRIPTION
*  If enabled, AP will display OOS when lost coverage and AS start cell reselection
*  If disabled, AP will display OOS after lost coverage and cell reselection failure
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_enable_early_oos_ind(void)
{
    return sbp_query_md_feature(SBP_OOS_EARLY_IND);
}


/*****************************************************************************
* FUNCTION
*  mm_custom_reattach_for_mt_gprs_detach_other_cause
*
* DESCRIPTION
*  If the UE receives network initiated GPRS detach request of type "re-attach not required",
*  and the reject cause is not defined in SPEC (not one of #2/#3/#6/#7/#8/#11/#12/#13/#14/#15/#25),
*  according to the SPEC, further actions of MS are implementation dependent.
*
* PARAMETERS
*
* RETURNS
*   KAL_TRUE:
*    - The UE will re-attach immediatedly after performing GPRS detach 
*   KAL_FALSE:
*    - The UE will not re-attach immediately after performing GPRS detach
*    - The UE will re-attach when user starts a new data transmission
*
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_reattach_for_mt_gprs_detach_other_cause(void)
{
  if (sbp_query_md_feature(SBP_GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE) == KAL_TRUE)
  {
	  return KAL_TRUE;
  }	 
  else
  {
	  return KAL_FALSE;
  }
}

/*****************************************************************************
* FUNCTION
* mm_custom_mcc_allowed_reattach_for_mt_gprs_detach_other_cause
*
* DESCRIPTION
* This custom function check camped PLMN mcc is present in re-attach for NW 
* initiated detach other cause customer MCC list or not.
*
* PARAMETERS
*      camped_plmn_mcc
* RETURNS
*   KAL_TRUE:
*    - The UE shall perform re-attach
*   KAL_FALSE:
*    - The UE shall not perform re-attach
*
* GLOBALS AFFECTED
*  None
*****************************************************************************/

kal_bool mm_custom_mcc_allowed_reattach_for_mt_gprs_detach_other_cause(kal_uint32 camped_plmn_mcc)
{
    kal_uint32 i;
    for (i = 0; i<GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE_MCC_NUM; i++)
	{
		if (GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE_MCC_LIST[i] == NO_MCC_ALLOWED)
		{
		    return KAL_FALSE;
		}
		else if (GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE_MCC_LIST[i] == ALL_MCC_ALLOWED ||
				 GMM_REATTACH_FOR_NW_DETACH_OTHER_CAUSE_MCC_LIST[i] == camped_plmn_mcc)
		{
			 return KAL_TRUE;
		}
	}
    return KAL_FALSE;
}



/*****************************************************************************
* FUNCTION
*  mm_custom_imsi_detach_when_mm_conn_active
* DESCRIPTION
*  If enabled, AP will display OOS when lost coverage and AS start cell reselection
*  If disabled, AP will display OOS after lost coverage and cell reselection failure
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_imsi_detach_when_mm_conn_active(void)
{
    if (sbp_query_md_feature(SBP_MM_IMSI_DETACH_WHEN_MM_CONN_ACTIVE) == KAL_TRUE)
    {
        return KAL_TRUE;
    }    
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
* FUNCTION
*  mm_custom_enable_dynamic_set_modem2_imei
* DESCRIPTION
*  CMCC requires: Two Modems of TDD GEMINI UE shall use the same IMEI in CMCC Network.
*  And by FT experience, Core Network may reject UE if two modems use the same IMEi.
*  The feature implement: 
*      In China network, two modems use the same IMEI.
*      In other network, two modems use different IMEI.
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: The feature is enabled.
    KAL_FALSE: The feature is disabled. In all networks, two modems use the SAME IMEI.
*  None
*****************************************************************************/
kal_bool mm_custom_enable_dynamic_set_modem2_imei(void)
{
    #ifdef __TDD_2G_OP01__
    kal_bool tdd_2g_op01 = KAL_TRUE;
    #else
    kal_bool tdd_2g_op01 = KAL_FALSE;
    #endif
    
    if(tdd_2g_op01 == KAL_TRUE || gmss_is_tdscdma_mode_activated() == KAL_TRUE)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
* FUNCTION
*  mm_custom_report_reg_when_csfb_ecc_lu_needed
* DESCRIPTION
*  For 4G23 CSFB ECC and LU needed, UE may delay LU until ECC end.
*  During ECC, no registration result will report to AP due to LU is pending.
*  AP will keep displaying 4G icon.
*  To solve this problem, we provide this function for RAT icon display when registration status is unknown.
* PARAMETERS
*   current_plmn_type  PLMN type of current camp on cell.
* RETURNS
*   KAL_TRUE:  Display registered on 2/3G.
*   KAL_FALSE: Display network lost.
*  None
*****************************************************************************/
kal_bool mm_custom_report_reg_when_csfb_ecc_lu_delayed(mm_custom_plmn_type current_plmn_type)
{
    switch (current_plmn_type)
    {
        case MM_CUSTOM_HPLMN:
        case MM_CUSTOM_R_E_PLMN:
            return KAL_TRUE;
        case MM_CUSTOM_UNKNOWN_PLMN_TYPE:
        default:
            return KAL_FALSE;
    }
}

/*************************************************************************
 * Ignore Reject cause 7, GPRS serive not allowed, in ATTACH REJECT or 
 * in ROUTING AREA UPDATING REJECT message when roaming. Reject Cause 
 * 14, GPRS serive not allowed in this PLMN, insteads of.
 * 
 * - IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR
 *     - If PLMN is defined in the list, UE take action as receiving reject
 *        cause 14 when UE receive ATTACH REJECT or ROUTING AREA UPDATING
 *        REJECT message with cause 7 and roaming.
 * 
 *************************************************************************/
#ifdef __GMM_CELCOM_IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING__
const char *IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR[] = {"50219F", IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR_SET_END};
#else
const char *IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR[] = {IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR_SET_END};
#endif

const kal_uint32 IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR_NUM = sizeof(IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR)/sizeof(char *);

/*************************************************************************
 * Convert Attach  Reject cause #14, GPRS serive not allowed in PLMN in 
 * ATTACH REJECT or to cause #111,Protocol error
 *
 ************************************************************************/
const char *CONVERT_GPRS_NOT_ALLOWED_IN_PLMN_TO_PROTOCOL_ERROR[] = {"46000F", "46001F", CONVERT_GPRS_NOT_ALLOWED_IN_PLMN_TO_PROTOCOL_ERROR_SET_END};
const kal_uint32 CONVERT_GPRS_NOT_ALLOWED_IN_PLMN_TO_PROTOCOL_ERROR_NUM = sizeof(CONVERT_GPRS_NOT_ALLOWED_IN_PLMN_TO_PROTOCOL_ERROR)/sizeof(char *);


/*************************************************************************
 * Some operators cannot decode IEs for SRVCC correctly brought in attach/RAU request
 * (i.e. MS Classmark2/MS Classmark3/Supported Codecs)
 *
 * - DISABLE_SRVCC_IE_PLMN
 *   - Do not bring new IEs for SRVCC in Attach/RAU request while trying registration on PLMNs specified in this array
 * 
 *************************************************************************/
const char *DISABLE_SRVCC_IE_PLMN[] = {"40468F", DISABLE_SRVCC_IE_PLMN_SET_END};
const kal_uint32 DISABLE_SRVCC_IE_PLMN_NUM = sizeof(DISABLE_SRVCC_IE_PLMN)/sizeof(char *);

/*****************************************************************************
* FUNCTION
*  mm_custom_get_t3x11_period
* DESCRIPTION
*  This function is used to get t3x11 timer period for enhance SoR, only rejected by network failure start t3211 would call this function
*  Not applicable for GCF test
* PARAMETERS
*  None
*
* RETURNS
*  kal_uint32
*
* GLOBALS AFFECTED
*  None
*
*****************************************************************************/
kal_uint32 mm_custom_get_t3x11_period(void)
{
    if (sbp_query_md_feature(SBP_ENHANCED_SOR) == KAL_TRUE)
    {
        return (5  * KAL_TICKS_1_SEC );
    }

    return (15  * KAL_TICKS_1_SEC );
}


/*****************************************************************************
* In some network, the CSMT flag cannot be set in paging response during MT CSFB calls.
* 
* - DISABLE_PAGING_CSMT_FLAG_PLMN_END
*   - If PLMN is listed in the array, the CSMT flag shall never be set
*
*****************************************************************************/
const char *DISABLE_PAGING_CSMT_FLAG_PLMN[] = {"40410", "22201", "46601", "23415", "23410", "51011", "45406", "21401", "46001", "310260", "50501", "20801", DISABLE_PAGING_CSMT_FLAG_PLMN_END};
const kal_uint32 DISABLE_PAGING_CSMT_FLAG_PLMN_NUM = sizeof(DISABLE_PAGING_CSMT_FLAG_PLMN)/sizeof(char *);

const char *CUSTOM_CAUSE_PLMN[] = {CUSTOM_CAUSE_PLMN_SET_ANY};

const kal_uint32 CUSTOM_CAUSE_PLMN_NUM = sizeof(CUSTOM_CAUSE_PLMN)/sizeof(char *);

/*****************************************************************************
* Enable CSMT flag in paging response
* 
* - DISABLE_PAGING_CSMT_FLAG_PLMN_END
*   - If PLMN is listed in the array, the CSMT flag shall never be set
*
*****************************************************************************/
const char *ENABLE_PAGING_CSMT_FLAG_PLMN[] = {"310410", "46000", ENABLE_PAGING_CSMT_FLAG_PLMN_END};
const kal_uint32 ENABLE_PAGING_CSMT_FLAG_PLMN_NUM = sizeof(ENABLE_PAGING_CSMT_FLAG_PLMN)/sizeof(char *);

/*****************************************************************************
* Trigger detach when user set rat G->L
*
*   - If PLMN is listed in the array, then UE will trigger detach when user set rat from G to L
*
*****************************************************************************/
const char *CONFIGURE_USER_SET_RAT_DETACH_G2L_PLMN[] = {"26003F", CONFIGURE_USER_SET_RAT_DETACH_G2L_PLMN_END};
const kal_uint32 CONFIGURE_USER_SET_RAT_DETACH_G2L_PLMN_NUM = sizeof(CONFIGURE_USER_SET_RAT_DETACH_G2L_PLMN)/sizeof(char *);

/*****************************************************************************
* Enable SKIP_LU_AFTER_CSFB_FOR_EAFR Feature
*
*   - If PLMN is listed in the array, then behave as SKIP_LU_AFTER_CSFB_FOR_EAFR Enabled
*
*****************************************************************************/
const char *CONFIGURE_SKIP_LU_AFTER_CSFB_FOR_EAFR_PLMN[] = {"25002F","71006F","71010F","71017F","722310","40492F","40410F", CONFIGURE_SKIP_LU_AFTER_CSFB_FOR_EAFR_PLMN_END};
const kal_uint32 CONFIGURE_SKIP_LU_AFTER_CSFB_FOR_EAFR_PLMN_NUM = sizeof(CONFIGURE_SKIP_LU_AFTER_CSFB_FOR_EAFR_PLMN)/sizeof(char *);

/*****************************************************************************
* Trigger detach when user set rat G->W
*
*   - If PLMN is listed in the array, then UE will trigger detach when user set rat from G to W
*
*****************************************************************************/
const char *CONFIGURE_USER_SET_RAT_DETACH_G2W_PLMN[] = {"40403F", CONFIGURE_USER_SET_RAT_DETACH_G2W_PLMN_END};
const kal_uint32 CONFIGURE_USER_SET_RAT_DETACH_G2W_PLMN_NUM = sizeof(CONFIGURE_USER_SET_RAT_DETACH_G2W_PLMN)/sizeof(char *);


/*****************************************************************************
* FUNCTION
*  mm_custom_get_cause_converter
* DESCRIPTION
*  This function is used to get customizable reject cause mapping.
*  CUSTOM_CAUSE_PLMN might restrict applying network
* CUSTOM_CAUSE_PLMN_SET_ANY : all network
* "00101f" : only applying on 00101 reject cause
*
* PARAMETERS
*  None
*
* RETURNS
*  kal_uint32
*
* GLOBALS AFFECTED
*  None
*
*****************************************************************************/
kal_uint8 mm_custom_get_customize_cause(kal_uint8 cause, mm_custom_proc_type proc, kal_bool is_on_hplmn, kal_bool is_test, kal_bool is_aka_sim)
{
    if (is_on_hplmn || is_test)
    {
      if ((is_aka_sim == KAL_TRUE) && (is_on_hplmn) && (cause == 0x7) && (proc == MM_CUSTOM_GMM))
       {

	       if(sbp_query_md_feature(SBP_CONVERT_REJ_CAUSE7_TO_14_ON_HPLMN_FOR_AKASIM) == KAL_TRUE)
	       {
	       	    return 0xe; /*GPRS_NOT_ALLOWED_IN_PLMN */
	       }
           else
           {
               /* MTK Default behavior is to return the same cause (i.e. 0x7) for HPLMN if SBP is not enable & current stack is AKA. 
                              Customer could change to any other reject cause based on the need basis at their own risk.
                               Ex. If customer likes to convert from cause #7 to #14. please change the value to 0x0e */
                return cause;  
           }
       }
        return cause;
    }
    
    if (proc == MM_CUSTOM_MM)
    {
        switch (cause)
        {
            case 0x02:/* IMSI_UNKNOWN_IN_HLR */
            case 0x03:/* ILLEGAL_MS */
            case 0x06:/* ILLEGAL_ME */
                if (sbp_query_md_feature(SBP_ENHANCED_SOR) == KAL_TRUE)
                {
                    return 0xd; /* ROAMING_AREA_NOT_ALLOWED */
                }
                break;
            case 0x0d: /* ROAMING_AREA_NOT_ALLOWED */
                if (sbp_query_md_feature(SBP_ROAMING_NOT_ALLOW_AS_NO_SUITABLE) == KAL_TRUE)
                {
                    return 0xf; /* NO_SUITABLE_CELLS_IN_LA */
                }
        default:
            break;
        }
    }

    if (proc == MM_CUSTOM_GMM)
    {
        switch (cause)
        {            
            case 0x03:/* ILLEGAL_MS */
            case 0x06:/* ILLEGAL_ME */
            case 0x07:/* GPRS_NOT_ALLOWED */
            case 0x08:/* GPRS_NON_GPRS_NOT_ALLOWED */
                if (sbp_query_md_feature(SBP_ENHANCED_SOR) == KAL_TRUE)
                {
                    return 0xd; /* ROAMING_AREA_NOT_ALLOWED */
                }
                break;
            case 0x0d: /* ROAMING_AREA_NOT_ALLOWED */
                if (sbp_query_md_feature(SBP_ROAMING_NOT_ALLOW_AS_NO_SUITABLE) == KAL_TRUE)
                {
                    return 0xf; /* NO_SUITABLE_CELLS_IN_LA */
                }
            default:
            break;
        }
    }
    return cause;
}

#ifdef __TC7__CS__SUPPORT__

/*****************************************************************************

* FUNCTION

*  mm_custom_fake_lu_needed

* DESCRIPTION

*  IronMan requirement

*

* PARAMETERS

*

* RETURNS

*  KAL_TRUE: The feature is enabled.

    KAL_FALSE: The feature is disabled.

*  None

*****************************************************************************/

kal_bool mm_custom_fake_lu_needed(void)

{

#if defined(__TC7_CS_OPT1__)

    return KAL_TRUE;

#else

    return KAL_FALSE;

#endif

}

#endif


