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
 * custom_gprs_pdp_config.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the FLC2 configuration.
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
 *==============================================================================
 *******************************************************************************/

#ifdef __MOD_TCM__

//#include "kal_release.h"
//#include "kal_non_specific_general_types.h"
//#include "l3_inc_enums.h"
//#include "mmi_l3_enums.h"
//#include "custom_mmi_default_value.h"
//#include "mcd_l3_inc_gprs_struct.h"

//#include "common_nvram_editor_data_item.h"
//#include "custom_data_account.h"

//#include "l4c2abm_struct.h"

//#include "mmi_sm_enums.h"

//#include "ppp_l4_enums.h"

//#include "tcm_common_enums.h"

//#include "tcm_common.h"

//#include "custom_gprs_pdp_default_qos_config.h"
#include "string.h"
#include "custom_gprs_pdp_config.h"
#include "l4_ps_api.h"
#include "nas_common_utility.h"
//#include "tcm_common.h"


#ifdef __APP_SECONDARY_PDP_SUPPORT__

#include "custom_data_account.h"        /* Poying: Should not be removed. */
#include "l4c2abm_struct.h"             /* Poying: Should be added. */
#include "custom_mmi_default_value.h"   /* Poying: Should not be removed. */

//#include "tcm_common.h"                 /* poying: Should be added. */
#include "mmi_l3_enums.h"
#include "l3_inc_enums.h"


//------------------------------ suggest Add ------------------------------    
#include "kal_general_types.h"    
#include "kal_public_api.h"    
#include "kal_trace.h"

#include "tcm_trc.h"
#include "tcm_api.h"


// this enum means that the PDP requested mamimum bit rate == 6 times of guarantee bit rate
#define STREAMING_REQUESTED_MAXIMUM_BITRATE_SCALE_NUMBER 6

/*****************************************************************************
* FUNCTION
*   custom_gprs_pdp_secondary_qos_encode
* DESCRIPTION
*   This function implements the 3GPP spec  26.234 Annex J
*   Call by Applications 
*   This function is owned by Carlson Lin / Howard Yeh
*   The 3GPP spec 26.234 is owned by Howard Yeh
* 
* PARAMETERS
*    IN   
*    IN       
* RETURNS
*   kal_bool,
*        true if found a valid app_type and fill the QoS values
*        fail if cannot found a valid app_type
*
* GLOBALS AFFECTED
*   N/A
*****************************************************************************/
kal_bool custom_gprs_pdp_secondary_qos_encode(custom_app_qos_type_enum app_qos_type, void * param, tcm_ps_qos_profile_struct * qos_info)
{
	/* for streaming application, 
	    the param is used for bandwidth(kal_uint16) described in spec 26.234.
	    The application should pass a kal_uint16 pointer to this function */    
	    
	/* for other QoS parameters, please refer to spec 26.234. Annex J
	     "Mapping of SDP parameters to UMTS QoS parameters" 
	     This function provide the SPEC recommendation QoS value to streaming application */
	    
	if (app_qos_type == CUSTOM_APP_QOS_STREAMING)
	{
		kal_bool    ret;
		kal_uint32 guarantee_downlink_rate;
		kal_uint32 maximum_downlink_rate;
		kal_uint32 guarantee_uplink_rate;
		kal_uint32 maximum_uplink_rate;

		kal_uint32 bandwidth = (*(kal_uint16*)param);;
		
		kal_mem_set(&(qos_info->req_qos), 0, sizeof(nvram_editor_qos_struct));
		kal_mem_set(&(qos_info->min_qos), 0, sizeof(nvram_editor_qos_struct));
		qos_info->req_qos.qos_length = SM_QOS_LEN_20;
		qos_info->min_qos.qos_length = SM_QOS_LEN_20;        
		
		qos_info->req_qos.delivery_of_err_sdu = DELIVERY_OF_ERR_NO; // encode into 24.008 Table 10.5.156 format
		qos_info->req_qos.delivery_order = WITHOUT_DELIVERY_ORDER; // encode into 24.008 Table 10.5.156 format
		qos_info->req_qos.traffic_class = STREAMING_CLASS; // encode into 24.008 Table 10.5.156 format
		qos_info->req_qos.max_sdu_size = 0x8C; //1400 bytes (encode into 24.008 Table 10.5.156 format)

		ret = l4ctcm_encode_bit_rate( 
                                                              #ifndef __REL6__
                                                              (kal_uint16)(bandwidth * 1.025), 
                                                              #else // #ifndef __REL6__
                                                              (kal_uint32)(bandwidth * 1.025), 
                                                              #endif // ~ #ifndef __REL6__
                                                              &guarantee_downlink_rate); // encode the decimal format of downlink rate into 24.008 Table 10.5.156 format
		if (ret == KAL_FALSE)
		{
                        #ifndef __REL6__
			guarantee_downlink_rate = 0xFE; //maximum value 
                        #else // ~ #ifndef __REL6__
			guarantee_downlink_rate = 250<<8; //maximum value 
                        #endif // ~ #ifndef __REL6__
		}

		ret = l4ctcm_encode_bit_rate( 
                                                              #ifndef __REL6__
                                                              (kal_uint16)(bandwidth * 1.025 * STREAMING_REQUESTED_MAXIMUM_BITRATE_SCALE_NUMBER), 
                                                              #else // #ifndef __REL6__
                                                              (kal_uint32)(bandwidth * 1.025 * STREAMING_REQUESTED_MAXIMUM_BITRATE_SCALE_NUMBER), 
                                                              #endif // ~ #ifndef __REL6__
                                                              &maximum_downlink_rate); // encode the decimal format of downlink rate into 24.008 Table 10.5.156 format
		if (ret == KAL_FALSE)
		{
                        #ifndef __REL6__
			maximum_downlink_rate = 0xFE; //maximum value 
                        #else // ~ #ifndef __REL6__
			maximum_downlink_rate = 250<<8; //maximum value 
                        #endif // ~ #ifndef __REL6__
		}

		ret = l4ctcm_encode_bit_rate( 
                                                              #ifndef __REL6__
                                                              (kal_uint16)(bandwidth * 0.025), 
                                                              #else // #ifndef __REL6__
                                                              (kal_uint32)(bandwidth * 0.025), 
                                                              #endif // ~ #ifndef __REL6__
                                                              &guarantee_uplink_rate); // encode the decimal format of uplink rate into 24.008 Table 10.5.156 format
		if (ret == KAL_FALSE)
		{
                        #ifndef __REL6__
			guarantee_uplink_rate = 0xFE; //maximum value 
                        #else // ~ #ifndef __REL6__
			guarantee_uplink_rate = 250<<8; //maximum value 
                        #endif // ~ #ifndef __REL6__
		}		

		ret = l4ctcm_encode_bit_rate( 
                                                              #ifndef __REL6__
                                                              (kal_uint16)(bandwidth * 0.025 * STREAMING_REQUESTED_MAXIMUM_BITRATE_SCALE_NUMBER), 
                                                              #else // #ifndef __REL6__
                                                              (kal_uint32)(bandwidth * 0.025 * STREAMING_REQUESTED_MAXIMUM_BITRATE_SCALE_NUMBER), 
                                                              #endif // ~ #ifndef __REL6__
                                                              &maximum_uplink_rate); // encode the decimal format of uplink rate into 24.008 Table 10.5.156 format
		if (ret == KAL_FALSE)
		{
                        #ifndef __REL6__
			maximum_uplink_rate = 0xFE; //maximum value 
                        #else // ~ #ifndef __REL6__
			maximum_uplink_rate = 250<<8; //maximum value 
                        #endif // ~ #ifndef __REL6__
		}		

		qos_info->req_qos.guarntd_bit_rate_down_lnk = (kal_uint8)guarantee_downlink_rate;
		qos_info->req_qos.guarntd_bit_rate_up_lnk = (kal_uint8)guarantee_uplink_rate;
		qos_info->req_qos.ext_guarntd_bit_rate_down_lnk = (kal_uint8)(guarantee_downlink_rate>>8);
		qos_info->req_qos.ext_guarntd_bit_rate_up_lnk = (kal_uint8)(guarantee_uplink_rate>>8);        
		qos_info->req_qos.ext2_guarntd_bit_rate_down_lnk = (kal_uint8)(guarantee_downlink_rate>>16);
		qos_info->req_qos.ext2_guarntd_bit_rate_up_lnk = (kal_uint8)(guarantee_uplink_rate>>16);        		
		qos_info->req_qos.max_bitrate_down_lnk = (kal_uint8)maximum_downlink_rate; // refer to 24.008 Table 10.5.156
		qos_info->req_qos.max_bitrate_up_lnk 	 = (kal_uint8)maximum_uplink_rate; // refer to 24.008 Table 10.5.156
		qos_info->req_qos.ext_max_bitrate_down_lnk = (kal_uint8)(maximum_downlink_rate>>8); // refer to 24.008 Table 10.5.156
		qos_info->req_qos.ext_max_bitrate_up_lnk 	 = (kal_uint8)(maximum_uplink_rate>>8); // refer to 24.008 Table 10.5.156
		qos_info->req_qos.ext2_max_bitrate_down_lnk = (kal_uint8)(maximum_downlink_rate>>16); // refer to 24.008 Table 10.5.156
		qos_info->req_qos.ext2_max_bitrate_up_lnk 	 = (kal_uint8)(maximum_uplink_rate>>16); // refer to 24.008 Table 10.5.156


		qos_info->req_qos.residual_bit_err_rate = BIT_ERROR_RATE7; //7: 10-5 (refer to 24.008 Table 10.5.156)
		qos_info->req_qos.sdu_err_ratio = SDU_ERR_RATIO4; //4: 10-4 (refer to 24.008 Table 10.5.156)
		qos_info->req_qos.traffic_hndl_priority = SUBSCRIBED_TRAFFIC_HNDL_PRIORITY; // encode into 24.008 Table 10.5.156 format
		qos_info->req_qos.transfer_delay = 0x2A; // 101010 : 2000 ms (refer to 24.008 Table 10.5.156)

                tcm_qos_R99_to_R98((qos_struct *)(&(qos_info->req_qos)), TCM_REQ_QOS); // fill R98 QoS field according to R99 values


             kal_trace(TCM_CONTROL_PLANE_TRACE_GROUP, TCM_STREAMING_REQUEST_SECONDARY_BITRATE_BEFORE_ENCODE);
             #ifndef __REL6__
             kal_trace(TCM_CONTROL_PLANE_TRACE_GROUP, TCM_STREAMING_REQUEST_BITRATE_VALUE_BEFORE_ENCODE, 
                                                     (kal_uint16)(bandwidth * 1.025), 
                                                     (kal_uint16)(bandwidth * 1.025 * STREAMING_REQUESTED_MAXIMUM_BITRATE_SCALE_NUMBER),
                                                     (kal_uint16)(bandwidth * 0.025), 
                                                     (kal_uint16)(bandwidth * 0.025 * STREAMING_REQUESTED_MAXIMUM_BITRATE_SCALE_NUMBER));
             #else // #ifndef __REL6__
             kal_trace(TCM_CONTROL_PLANE_TRACE_GROUP, TCM_STREAMING_REQUEST_BITRATE_VALUE_BEFORE_ENCODE, 
                                                     (kal_uint32)(bandwidth * 1.025), 
                                                     (kal_uint32)(bandwidth * 1.025 * STREAMING_REQUESTED_MAXIMUM_BITRATE_SCALE_NUMBER),
                                                     (kal_uint32)(bandwidth * 0.025), 
                                                     (kal_uint32)(bandwidth * 0.025 * STREAMING_REQUESTED_MAXIMUM_BITRATE_SCALE_NUMBER));
             #endif // ~ #ifndef __REL6__

             kal_trace(TCM_CONTROL_PLANE_TRACE_GROUP, TCM_STREAMING_REQUEST_SECONDARY_BITRATE_AFTER_ENCODE);
             kal_trace(TCM_CONTROL_PLANE_TRACE_GROUP, TCM_STREAMING_GUARANTEE_BIT_RATE_AFTER_ENCODE,(kal_uint8)guarantee_downlink_rate, (kal_uint8)guarantee_uplink_rate);
             kal_trace(TCM_CONTROL_PLANE_TRACE_GROUP, TCM_STREAMING_EXT_GUARANTEE_BIT_RATE_AFTER_ENCODE, (kal_uint8)(guarantee_downlink_rate>>8), (kal_uint8)(guarantee_uplink_rate>>8));
             kal_trace(TCM_CONTROL_PLANE_TRACE_GROUP, TCM_STREAMING_MAX_BIT_RATE_AFTER_ENCODE, (kal_uint8)maximum_downlink_rate, (kal_uint8)maximum_uplink_rate);
             kal_trace(TCM_CONTROL_PLANE_TRACE_GROUP, TCM_STREAMING_EXT_MAX_BIT_RATE_AFTER_ENCODE, (kal_uint8)(maximum_downlink_rate>>8), (kal_uint8)(maximum_uplink_rate>>8));


                return KAL_TRUE;
	}

        return KAL_FALSE;
}
#endif // ~ #ifdef __APP_SECONDARY_PDP_SUPPORT__

const char *CUSTOM_USE_SM_QOS_SUBSCRIBED_FOR_PLMN[] = {"26006F", CUSTOM_PLMN_SET_END};

/****************************************************************************
* The default value of ignore_sbp_ims_pdn_ignore_ipv4v6_fallback_for_specific_causes
* is KAL_TRUE.
* When value is set to KAL_TRUE and PDN request is for IMS PDN, L4 PS will not allow for fallback
* to IPV4 and IPV6 for certain SM Causes.
* When value is set to KAL_FALSE and PDN request is for IMS PDN, L4 PS will take decision for fallback 
* to IPV4 and IPV6 for certain SM Causes based on SBP_IMS_PDN_IGNORE_IPV4V6_FALLBACK_FOR_SPECIFIC_CAUSES
****************************************************************************/
const kal_bool ignore_sbp_ims_pdn_ignore_ipv4v6_fallback_for_specific_causes = KAL_TRUE;


kal_bool custom_need_to_modify_user_configured_qos_delivery_order_value(pdp_addr_type_enum pdp_type, kal_bool is_use_test_sim, kal_uint8 * suggested_value, kal_uint8 sim_interface)
{
    /*
     * According to TS 23.107 v5.13.0 Clause 6.4.3.1
     * Delivery order should be set to "no" for PDP Type = "IPv4" or "IPv6". The SGSN should ensure that the appropriate value is set
     */
    if(KAL_TRUE == sbp_query_md_feature(SBP_USE_SM_QOS_SUBSCRIBED) || custom_use_sm_qos_subscribed_based_on_sim_inserted(sim_interface))
    {
        return KAL_FALSE; // we do not suggest to modify user configured delivery_order
    }
    
    if((PPP_ADDR_TYPE != pdp_type) && (KAL_FALSE == is_use_test_sim ) && 
        (query_ps_conf_test_mode() != PS_CONF_TEST_IOT ) )
    {
        *suggested_value = WITHOUT_DELIVERY_ORDER;        
        return KAL_TRUE; // we suggest to modify user configured delivery_order
    }
    else
    {
        return KAL_FALSE; // we do not suggest to modify user configured delivery_order
    }
}

kal_bool custom_need_to_regard_realtime_qos_as_non_realtime_qos(void) {

#ifndef __SM_REGARD_REALTIME_QOS_AS_NON_REALTIME_QOS__ // need to turn on this option to pass AT&T ADAPT [GSM-BTR-1-5160][GSM-BTR-1-5162][GSM-BTR-1-5154] test case
    if (  ( query_ps_conf_test_mode() == PS_CONF_TEST_OPERATOR ) &&
          ( query_ps_conf_test_profile_setting() & OPERATOR_TEST_ATNT) )  {
        return KAL_TRUE;
    } else {
        return KAL_FALSE;
    }
#else // #ifndef __SM_REGARD_REALTIME_QOS_AS_NON_REALTIME_QOS__
    return KAL_TRUE;
#endif // ~ #ifndef __SM_REGARD_REALTIME_QOS_AS_NON_REALTIME_QOS__

}

kal_uint32 custom_get_pdp_activation_retry_timer_on_release()
{
    return (2 * KAL_TICKS_1_SEC);
}

kal_bool custom_use_sm_qos_subscribed_based_on_sim_inserted(kal_uint8 sim_interface)
{
    kal_uint32 i = 0;
    plmn_id_struct custom_plmn;
    kal_bool ret_val = KAL_FALSE;
    while (strcmp(CUSTOM_USE_SM_QOS_SUBSCRIBED_FOR_PLMN[i], CUSTOM_PLMN_SET_END) != 0)
    {
    	if (nas_convert_plmn_string_to_struct(CUSTOM_USE_SM_QOS_SUBSCRIBED_FOR_PLMN[i], &custom_plmn) == KAL_TRUE)
    	{
    		if (nas_is_hplmn(sim_interface, &custom_plmn) == KAL_TRUE)
    		{
    			ret_val = KAL_TRUE;
				break;
    		}
    	}
    	i++;
    }
    return ret_val;
}

#if 0 /* Move to custom_tcm_bcm_is_testing() */
/* under construction !*/
/* under construction !*/
#ifdef __NRSPCA__
/* under construction !*/
/* under construction !*/
#else // #ifdef __NRSPCA__
    #ifdef __REL7__
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
    #endif // ~ #ifdef __REL7__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // ~ #ifdef __NRSPCA__
/* under construction !*/
/* under construction !*/
#endif 

#if 0 /* Move to custom_tcm_etft_is_testing */
/* under construction !*/
/* under construction !*/
    #if 1//def __REL7__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif // ~ #ifdef __REL7__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

/*****************************************************************************
* FUNCTION
*   custom_gprs_pdp_check_if_ims_pdn_ipv4v6_fallback_for_specific_causes
* DESCRIPTION
*   This function checks whether to allow IPV4V6 fallback or not for the provided cause if it is a IMS PDN"
* 
* PARAMETERS
*    cause - The causes for which fallback to IPv4v6 will be ignored.

* RETURN VALUE
*      KAL_FALSE: IPV4V6 fallback not allowed for the provided cause.
*      KAL_TRUE: IPV4V6 fallback is allowed for the provided cause.
*
* GLOBALS AFFECTED
*   N/A
*****************************************************************************/
kal_bool custom_gprs_pdp_check_if_ims_pdn_ipv4v6_fallback_for_specific_causes(kal_uint16 cause)
{
    kal_bool return_value = KAL_TRUE;
    
    if (ignore_sbp_ims_pdn_ignore_ipv4v6_fallback_for_specific_causes || (KAL_TRUE == sbp_query_md_feature(SBP_IMS_PDN_IGNORE_IPV4V6_FALLBACK_FOR_SPECIFIC_CAUSES))) 
    {
        if ((ESM_UNKNOWN_OR_MISSING_APN == cause) || (ESM_REQUEST_REJECTED_BY_SGW_OR_PDNGW == cause) || (UNKNOWN_APN == cause) || (ACTIVATION_REJ_GGSN == cause))
        {
            return_value = KAL_FALSE;
        }
    } 
	else 
    {
        return_value = KAL_TRUE;
    }
 
    return return_value;  
}


#endif // ~ #ifdef __MOD_TCM__
