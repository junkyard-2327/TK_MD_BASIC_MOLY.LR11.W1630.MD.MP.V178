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
 * custom_l4_utility.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is used for L4C customization
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "kal_non_specific_general_types.h"


//#include <stdio.h>
//#include <string.h>
//#include "kal_release.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h"       	/* Task message communiction */
//#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
//#include "app_buff_alloc.h"
//#include "stack_timer.h"
//#include "event_shed.h"
//#include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"
#ifdef __MMI_FMI__
//#include "custom_mmi_default_value.h" 
#endif
//#include "l4_defs.h"
//#include "uart_sw.h"

//#include "kbd_table.h"
#if defined(__ATCMD_ONOFF_CHECK__)
#include "rmmi_parser.h"
#endif
#include "kal_general_types.h"
//#include "stack_config.h"
#include "kal_public_api.h"
#include "gmss_public.h"

#if defined(__MTK_TARGET__)
#if !defined (L1_NOT_PRESENT)
#include "l1d_interface_pcore.h"
#endif
#endif

#if defined (__MTK_UL1_FDD__)
#if !defined (UL1_NOT_PRESENT)
#include "ul1d_rf_public.h" //for UL1D_UeCaBandCapability
#endif
#endif
#ifdef __MTK_TARGET__
#ifdef __LTE_RAT__
#include "mrs_eas_capability.h"
#endif
#endif
#include "csmcc_enums.h"
#include "l4_ps_api.h"
#if (!defined(__FLAVOR_BASIC__)) && (!defined(__FLAVOR_BASIC_TL1D__))
# include "mcd_l3_inc_struct.h"
#endif

#define CM_DTMF_P_W_SWITCH_FLAG  KAL_FALSE
//define codec num
#define SUPPORTED_2G_CODEC_NUM 6 
#define CUSTOM_ACM_BOUND      (1000)
#define	CSM_RLC_TIMER_CONFIG  (3)

#ifdef __SIGNAL_REPORT_OPTIMIZATION__
// customer provided time duration for UMTS cell power level indication
#define CUSTOM_UMTS_CELL_POWER_LEVEL_IND_TIMER  (5000)    // 5 seconds
#endif

#ifdef __FWP_NC_LAI_INFO__
#define CELL_LOCK_PREFIX_LEN 4
kal_uint8 CELL_LOCK_PREFIX[CELL_LOCK_PREFIX_LEN] = {0x0d, 0x00, 0x00, 0x01};
#endif /*__FWP_NC_LAI_INFO__*/

/* MAUI_01637672 support CCWE */
#define CUSTOM_ACM_CALL_METER_WARNING_EVENT_SECONDS      (30)

//mtk00924 20051026:  +EIMG and +EMDY download to MS default folder name customization
//at most 25 characters in UCS2 format for folder name, and 0x005C and 0x0000 should be given at the end
kal_wchar CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME[] = {0x0041, 0x0075, 0x0064, 0x0069, 0x006F, 0x005C, 0x0000};  /* default folder = Audio */
kal_wchar CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME[] = {0x0049, 0x006D, 0x0061, 0x0067, 0x0065, 0x0073, 0x005C, 0x0000};  /* default folder = Images */

#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "ps_em_enum.h"

#if (defined(__GEMINI__) || defined(__SGLTE__) || defined(__SIMME_LOCK_RELATIONSHIP__)) && defined(__SIM_ME_LOCK__)
#include "smu_common_enums.h" //link_SML
#endif

#include "custom_l4_utility.h"

#if (!defined(__FLAVOR_BASIC__)) && (!defined(__FLAVOR_BASIC_TL1D__))
# include "l4crac_func.h"
#endif

#include "md_sap.h"
#include "kal_trace.h"  // for tst_sys_trace

extern kal_bool nvram_custom_config_ims_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id);
extern kal_bool nvram_custom_config_ltecsr_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id);
extern kal_bool nvram_custom_config_sdm_ads_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id);
extern kal_bool nvram_custom_config_vdm_ads_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id);

/*input CC_DISCONNECT cause:*/
kal_uint16 CUSTOM_DISC_ERROR_CAUSE[] = {CM_NO_CIRCUIT_CHANNEL_AVAIL,     //34
                                        CM_RESOURCE_UNAVAIL_UNSPECIFIED};//47

/*****************************************************************************
	If customer want to use other character instead of '?' as wild character 
	Please re-define this CUSTOM_WILD_CHAR 
	[Note!!] Wild character definition should be unique and sync with MMI display
	[Note!!] This is used only apply to L4 protocol. 
	         Customer still need to revise the definition in MMI and Phonebook 
*****************************************************************************/
#define CUSTOM_WILD_CHAR '?'

/*****************************************************************************
	If customer want to use other character instead of 'w' as auto dtmf modifier 
	Please re-define this CUSTOM_AUTO_DTMF_MODIFIER 
	[Note 1] Please always use lowercase character e.g. use 't' instead of 'T'
	[Note 2] Auto DTMF modifier definition should be unique and sync with MMI display
	[Note 3] This is used only apply to L4 protocol. 
	         Customer still need to revise the definition in MMI and Phonebook 
*****************************************************************************/
#define CUSTOM_AUTO_DTMF_MODIFIER 'w' 

/*****************************************************************************
* FUNCTION
*  	custom_wild_char()
* DESCRIPTION
*   	This function is used to return wild character definition
*	
* PARAMETERS
*	none
* RETURNS
*	wild character definition
*****************************************************************************/
kal_uint8 custom_wild_char(void)
{
	return CUSTOM_WILD_CHAR;
}


/*****************************************************************************
* FUNCTION
*  	custom_auto_dtmf_modifer()
* DESCRIPTION
*   	This function is used to return auto DTMF modifier definition
*	
* PARAMETERS
*	none
* RETURNS
*	auto dtmf modifier definition
*****************************************************************************/
kal_uint8 custom_auto_dtmf_modifier(void)
{
	return CUSTOM_AUTO_DTMF_MODIFIER;
}

/*****************************************************************************
* FUNCTION
*  	custom_ext_modem_mod_id()
* DESCRIPTION
*   	This function is used to return external modem module id
*	
* PARAMETERS
*	none
* RETURNS
*	External modem module id
*****************************************************************************/
#ifdef __EXT_MODEM__
module_type custom_ext_modem_mod_id(void)
{
	return MOD_EXT_MODEM;
}
#endif

/*****************************************************************************
* FUNCTION
*  	custom_short_string_as_call()
* DESCRIPTION
*   	This function is used to define specific short string (1 or 2 digit dial string)
*		  that should be treat as call instead of USSD. 
*	    In spec 22.030 Figure 3.5.3.2 it define short string except 2 digit starting 
*     with a '1' shall treat as USSD. However,there might be some special operator requirement 
*	    ex: "86" is a operator service call number
* PARAMETERS
*	kal_uint8 c1
*	kal_uint8 c2  
*	kal_uint8 length
* RETURNS
*	KAL_TRUE or KAL_FALSE
* KAL_TRUE is to treat this short string as call
*****************************************************************************/
kal_bool custom_short_string_as_call(kal_uint8 c1, kal_uint8 c2, kal_uint8 length)
{
	kal_bool ret_val = KAL_FALSE;
	
	//Implement specific short string parsing rule here
	#if 0 // Example case :treat "86" as call
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	
	return ret_val;
}


#define custom_is_digit(c) ((c >= '0') && (c <= '9'))

/*****************************************************************************
* FUNCTION
*  	custom_idle_string_as_call()
* DESCRIPTION
*   This function is used to define specific string input in idle screen 
*   that should be treat as call instead of USSD.
*   This check is prior to the spec 22.030 Figure 3.5.3.2 
*
* PARAMETERS
*	kal_uint8 *str  
*	kal_uint8 length
* RETURNS
*	KAL_TRUE or KAL_FALSE
* KAL_TRUE is to treat this string as call
*****************************************************************************/
kal_bool custom_idle_string_as_call(kal_uint8 *str, kal_uint8 length)
{
    kal_bool ret_val = KAL_FALSE;

    //Implement specific string parsing rule here
    if (((length == 1) && (str[0] == '0'))                          // "0 SEND"
        || ((length == 2) && ((kal_mem_cmp(str,"00",length) == 0)   // "00 SEND"
                           || (kal_mem_cmp(str,"*8",length) == 0)   // "*8 SEND"
                           || (kal_mem_cmp(str,"*0",length) == 0)   // "*0 SEND"
                           || (kal_mem_cmp(str,"#0",length) == 0))) // "#0 SEND"
        || ((length == 3) && ((kal_mem_cmp(str,"411",length) == 0)  // "411 SEND"
                           || (kal_mem_cmp(str,"*08",length) == 0)  // "*08 SEND"
                           || ((str[0] == '#') 
                            && (str[1] == '#') 
                            && custom_is_digit(str[2]))))           // "##<1 digit> SEND"
        || ((length == 4) && ((str[0] == '*') || (str[0] == '#'))
                          && custom_is_digit(str[1]) 
                          && custom_is_digit(str[2]) 
                          && custom_is_digit(str[3]))               // "*<3 digits> SEND" or "#<3 digits> SEND"
        || ((length == 5) && (str[0] == '*') 
                          && custom_is_digit(str[1]) 
                          && custom_is_digit(str[2]) 
                          && custom_is_digit(str[3]) 
                          && custom_is_digit(str[4]))               // "*<4 digits> SEND"
        || ((length == 5) && (str[0] == '#') 
                          && custom_is_digit(str[1]) 
                          && custom_is_digit(str[2]) 
                          && custom_is_digit(str[3]) 
                          && custom_is_digit(str[4])
                          && custom_is_digit(str[5]))               // "#<5 digits> SEND"
        || ((length == 9) && (str[0] == '*') && (str[1] == '*')
                          && custom_is_digit(str[2])
                          && custom_is_digit(str[3])
                          && custom_is_digit(str[4])
                          && custom_is_digit(str[5])
                          && custom_is_digit(str[6])
                          && custom_is_digit(str[7])
                          && custom_is_digit(str[8]))               // "**<7 digits> SEND"
       )
    {
        ret_val = KAL_TRUE;
    }
    else
    {
        ret_val = KAL_FALSE;
    }
    
    return ret_val;
}


/*****************************************************************************
* FUNCTION
*    is_idea_vodafone_in_India_same_circle()
* DESCRIPTION
*    the rule is implemented from the mail attachment in ALPS04269333
*
* PARAMETERS
*   kal_uint8* plmn
*   kal_uint8* mcc_mnc
* RETURNS
*   KAL_TRUE or KAL_FALSE
* KAL_TRUE is to consider these plmns in the same circle
*****************************************************************************/
static kal_bool is_idea_vodafone_in_India_same_circle(kal_uint8* plmn, kal_uint8* mcc_mnc)
{
    kal_bool is_same_circle = KAL_FALSE;

    // Andhra Prasesh and Telangana
    if ((kal_mem_cmp(mcc_mnc,"40407",5) == 0) || (kal_mem_cmp(mcc_mnc,"40413",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40407",5) == 0) || (kal_mem_cmp(plmn,"40413",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Assam
    if ((kal_mem_cmp(mcc_mnc,"405845",6) == 0) || (kal_mem_cmp(mcc_mnc,"405751",6) == 0))
    {
        if ((kal_mem_cmp(plmn,"405845",6) == 0) || (kal_mem_cmp(plmn,"405751",6) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Bihar & Jharkhand
    if ((kal_mem_cmp(mcc_mnc,"40570",5) == 0) || (kal_mem_cmp(mcc_mnc,"405752",6) == 0))
    {
        if ((kal_mem_cmp(plmn,"40570",5) == 0) || (kal_mem_cmp(plmn,"405752",6) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Chennai
    if ((kal_mem_cmp(mcc_mnc,"405852",6) == 0) || (kal_mem_cmp(mcc_mnc,"40484",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"405852",6) == 0) || (kal_mem_cmp(plmn,"40484",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Delhi
    if ((kal_mem_cmp(mcc_mnc,"40404",5) == 0) || (kal_mem_cmp(mcc_mnc,"40411",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40404",5) == 0) || (kal_mem_cmp(plmn,"40411",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Gujarat
    if ((kal_mem_cmp(mcc_mnc,"40424",5) == 0) || (kal_mem_cmp(mcc_mnc,"40405",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40424",5) == 0) || (kal_mem_cmp(plmn,"40405",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Haryana
    if ((kal_mem_cmp(mcc_mnc,"40412",5) == 0) || (kal_mem_cmp(mcc_mnc,"40401",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40412",5) == 0) || (kal_mem_cmp(plmn,"40401",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Himachal Pradesh
    if ((kal_mem_cmp(mcc_mnc,"40482",5) == 0) || (kal_mem_cmp(mcc_mnc,"405754",6) == 0))
    {
        if ((kal_mem_cmp(plmn,"40482",5) == 0) || (kal_mem_cmp(plmn,"405754",6) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Jammu & Kashmir
    if ((kal_mem_cmp(mcc_mnc,"405846",6) == 0) || (kal_mem_cmp(mcc_mnc,"405750",6) == 0))
    {
        if ((kal_mem_cmp(plmn,"405846",6) == 0) || (kal_mem_cmp(plmn,"405750",6) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Karnataka
    if ((kal_mem_cmp(mcc_mnc,"40444",5) == 0) || (kal_mem_cmp(mcc_mnc,"40486",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40444",5) == 0) || (kal_mem_cmp(plmn,"40486",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Kerala
    if ((kal_mem_cmp(mcc_mnc,"40419",5) == 0) || (kal_mem_cmp(mcc_mnc,"40446",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40419",5) == 0) || (kal_mem_cmp(plmn,"40446",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Kolkata
    if ((kal_mem_cmp(mcc_mnc,"405848",6) == 0) || (kal_mem_cmp(mcc_mnc,"40430",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"405848",6) == 0) || (kal_mem_cmp(plmn,"40430",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Madhya Pradesh & Chattishgarh
    if ((kal_mem_cmp(mcc_mnc,"40478",5) == 0) || (kal_mem_cmp(mcc_mnc,"405756",6) == 0))
    {
        if ((kal_mem_cmp(plmn,"40478",5) == 0) || (kal_mem_cmp(plmn,"405756",6) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Maharashtra
    if ((kal_mem_cmp(mcc_mnc,"40422",5) == 0) || (kal_mem_cmp(mcc_mnc,"40427",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40422",5) == 0) || (kal_mem_cmp(plmn,"40427",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Mumbai
    if ((kal_mem_cmp(mcc_mnc,"405799",6) == 0) || (kal_mem_cmp(mcc_mnc,"40420",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"405799",6) == 0) || (kal_mem_cmp(plmn,"40420",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // North East
    if ((kal_mem_cmp(mcc_mnc,"405849",6) == 0) || (kal_mem_cmp(mcc_mnc,"405755",6) == 0))
    {
        if ((kal_mem_cmp(plmn,"405849",6) == 0) || (kal_mem_cmp(plmn,"405755",6) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Orissa
    if ((kal_mem_cmp(mcc_mnc,"405850",6) == 0) || (kal_mem_cmp(mcc_mnc,"405753",6) == 0))
    {
        if ((kal_mem_cmp(plmn,"405850",6) == 0) || (kal_mem_cmp(plmn,"405753",6) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Punjab
    if ((kal_mem_cmp(mcc_mnc,"40414",5) == 0) || (kal_mem_cmp(mcc_mnc,"40488",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40414",5) == 0) || (kal_mem_cmp(plmn,"40488",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Rajasthan
    if ((kal_mem_cmp(mcc_mnc,"40487",5) == 0) || (kal_mem_cmp(mcc_mnc,"40460",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40487",5) == 0) || (kal_mem_cmp(plmn,"40460",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Tamil Nadu
    if ((kal_mem_cmp(mcc_mnc,"405852",6) == 0) || (kal_mem_cmp(mcc_mnc,"40443",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"405852",6) == 0) || (kal_mem_cmp(plmn,"40443",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Uttar Pradesh (East)
    if ((kal_mem_cmp(mcc_mnc,"40489",5) == 0) || (kal_mem_cmp(mcc_mnc,"40415",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40489",5) == 0) || (kal_mem_cmp(plmn,"40415",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // Uttar Pradesh (West) and Uttarakhand
    if ((kal_mem_cmp(mcc_mnc,"40456",5) == 0) || (kal_mem_cmp(mcc_mnc,"40566",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"40456",5) == 0) || (kal_mem_cmp(plmn,"40566",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }

    // West Bengal & Andaman and Nicobar ls.
    if ((kal_mem_cmp(mcc_mnc,"405853",6) == 0) || (kal_mem_cmp(mcc_mnc,"40567",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"405853",6) == 0) || (kal_mem_cmp(plmn,"40567",5) == 0))
        {
            is_same_circle = KAL_TRUE;
        }
    }


    return is_same_circle;
}

/*****************************************************************************
* FUNCTION
*  	custom_is_home_plmn()
* DESCRIPTION
*	For AT+CREG and AT+CGREG network registeration report (defined in spec 27.007)
*	+CREG : 1 (registered, home network)
*	+CREG : 5 (registered, roaming)
*	The basic rule for home plmn is to check if the PLMN id equal to mcc+mnc in IMSI
*     However, there might be operators having more than one PLMN id
*     For such case, you can define them in this function
*
* PARAMETERS
*	kal_uint8* plmn
*	kal_uint8* mcc_mnc
*     kal_bool is_on_hplmn, for R7 EHPLMN
* RETURNS
*	KAL_TRUE or KAL_FALSE
* KAL_TRUE is to treat this plmn as a home PLMN
*****************************************************************************/
kal_bool custom_is_home_plmn(kal_uint8* plmn, kal_uint8* mcc_mnc, kal_bool is_on_hplmn)
{
    kal_bool custom_is_on_hplmn = KAL_FALSE;

    //if SIM card MCC+MNC is 46000/46002/46007 , current PLMN is 46000/46002/46007.  Treate as home PLMN. not roaming PLMN
    if ((kal_mem_cmp(mcc_mnc,"46000",5) == 0) || (kal_mem_cmp(mcc_mnc,"46002",5) == 0) || (kal_mem_cmp(mcc_mnc,"46007",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"46000",5) == 0) || (kal_mem_cmp(plmn,"46002",5) == 0) || (kal_mem_cmp(plmn,"46007",5) == 0))
        {
            custom_is_on_hplmn = KAL_TRUE;
        }
    }


    /*  [Operator requirement]
       *   If Idea and Vodafone is in the same circle in India, even though the reigistered PLMN 
       *   is not contained in HPLMN specified by SIM card, UE should still consider it home  */
    if (KAL_TRUE == is_idea_vodafone_in_India_same_circle(plmn, mcc_mnc))
    {
        custom_is_on_hplmn = KAL_TRUE;
    }

    return (custom_is_on_hplmn || is_on_hplmn);
}


/***********************************************************************************************
* FUNCTION
*     custom_disable_query_cfu_status()
* DESCRIPTION
*     In CPHS spec , it define a file to record if Call Forwarding Uncoditional (CFU) is active.
*     If CFU is active , ME show indicate user with CFU icon in MMI.
*     However, not all the SIM card havs this CFU flag file. 
*     So one SIM card might be with CFU activaed in ME A,but fail to display CFU icon when it is inserted in the ME B.
*
*     To dispaly CFU icon correctly,MTK solution might try to query CFU status right after first camping on to NW.
*     However, this might cause user MO SS operation fail due to the collision of ss operation
*
* PARAMETERS
*     none
* RETURNS
*     KAL_FALSE (default) is to query CFU status for the first time camping on to NW
*     KAL_TRUE is to disable the trick 
*************************************************************************************************/
kal_uint8 custom_disable_query_cfu_status(void)
{
#if defined(__TC01__) || defined(__SS_CPHS_QUERY_CFU_DISABLE__)
    return KAL_TRUE;  
#else	
    return KAL_FALSE;  
#endif	
}

/***********************************************************************************************
* FUNCTION
*     custom_cphs_query_cfu_status_always()
* DESCRIPTION
*     In CPHS spec , it define a file to record if Call Forwarding Uncoditional (CFU) is active.
*     If CFU is active , ME show indicate user with CFU icon in MMI.
*     However, not all the SIM card havs this CFU flag file. 
*     So one SIM card might be with CFU activaed in ME A,but fail to display CFU icon when it is inserted in the ME B.
*
*     To dispaly CFU icon correctly,MTK solution might try to query CFU status right after first camping on to NW always.
*     However, this might cause user MO SS operation fail due to the collision of ss operation
*     Available when custom_disable_query_cfu_status is KAL_FALSE.
*
* PARAMETERS
*     none
* RETURNS
*     KAL_FALSE (default) is to query CFU status when camping on to NW at the first time
*     KAL_TRUE is to query CFU status when camping on to NW
*************************************************************************************************/
kal_uint8 custom_cphs_query_cfu_status_always(void)
{
#if defined(__SS_CPHS_QUERY_CFU_ALWAYS__)
    return KAL_TRUE;  
#else	
    return KAL_FALSE;  
#endif	
}

/***********************************************************************************************
* FUNCTION
*     custom_cfu_store_ftn_in_efcfis()
* DESCRIPTION
*     Store CFU Forwarded-To-Number(FTN) to SIM EFcfis
*     It may cause CFU machine test failure because of redundant saving FTN transaction
* PARAMETERS
*     none
* RETURNS
*     KAL_FALSE (default) do not store CFU FTN in SIM
*     KAL_TRUE            do     store CFU FTN in SIM
*************************************************************************************************/
kal_uint8 custom_cfu_store_ftn_in_efcfis(void)
{
#ifdef __CFU_FTN_IN_EFCFIS__
    return KAL_TRUE;  
#else
    return KAL_FALSE;  
#endif
}

/***********************************************************************************************
* FUNCTION
*     custom_allow_at_write_imei()
* DESCRIPTION
*     To en/dis-able IMEI writing via AT command AT+EGMR with <op>=1 and <type>=7 or 10
*
* PARAMETERS
*     none
* RETURNS
*     KAL_FALSE is to prevent AT+EGMR to write IMEI
*     KAL_TRUE (default) is to allow the functionality 
*************************************************************************************************/
kal_uint8 custom_allow_at_write_imei(void)
{
#ifdef __MTK_INTERNAL_ENG_USER__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}

/***********************************************************************************************
* FUNCTION
*     custom_sms_fdn_check_da_only()
* DESCRIPTION
*     According to spec 22.101 A.25 , 
*     For SMS,both SCA(Service Center address) and DA(Destination Address) shall be checked when FDN is enabled
*     There might be special requirement for sms fdn check to check DA only.
*
* PARAMETERS
*     none
* RETURNS
*     KAL_TRUE is to ignore fdn check for sca, only check for da
*     KAL_FALSE (default) is to obey the spec. Do fdn check for both sca and da
************************************************************************************************/
kal_uint8 custom_sms_fdn_check_da_only(void)
{
#ifdef __SMS_FDN_CHECK_DA_ONLY__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}


/*****************************************************************************
* FUNCTION
*  	custom_ath_for_dialup_timer()
* DESCRIPTION
*   	This function is used to define time duration of handling ath for dialup
*	The unit is 0.1 sec , Current default value is 40 sec  (i.e. 400 x 0.1 sec)
* PARAMETERS
*	none
* RETURNS
*	time duration of handling ath for dialup
*****************************************************************************/
kal_uint16 custom_ath_for_dialup_timer(void)
{
    return 0;
}


/*****************************************************************************
* FUNCTION
*   l4_custom_battery_cind_value()
*
* DESCRIPTION
*   This function is used to convert battery_voltage(battery_level_enum)
*   to cind value 0~5 (battery cind range 0~5 is defined in HFP and 27.007 spec)
*   battery cind_value is the response of AT+CIND or +CIEV:<battery_ind>,<cind_value> 
*
* PARAMETERS
*	battery_voltage      IN
*
* RETURNS
*	cind value (according to HFP and 27.007 spec, battery cind value is 0~5)
*****************************************************************************/
kal_uint8 l4_custom_battery_cind_value(kal_uint8 battery_voltage)
{
    kal_uint8 cind_value;

    /* convert battery_voltage(battery_level_enum) to spec defined cind value (0~5) */
    if (battery_voltage > 5)
    {
        cind_value = 5;
    }
    else if (battery_voltage > 0)
    {
        cind_value = battery_voltage - 1;
    }
    else
    {
        cind_value = 0;
    }
	
    return cind_value;	
}

/*****************************************************************************
 * FUNCTION
 *  l4_custom_is_phb_valid_char
 * DESCRIPTION
 *  This function is to check if the chars of the input str are valid or not
 * PARAMETERS
 *  number		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool l4_custom_is_phb_valid_char(kal_uint8 ch)
{
    if ( !((ch >= '0' && ch <= '9') || ch == 'p' || 
        ch == custom_wild_char() || ch == custom_auto_dtmf_modifier() ||
        ch == '+' || ch == '*' || ch == '#') )
    {
            return KAL_FALSE;    
    }

    return KAL_TRUE;
}

/*****************************************************************************
* FUNCTION
*  custom_disable_modem_auto_startup()
* DESCRIPTION
*
* PARAMETERS
*	none
* RETURNS
*   TRUE:  disable modem auto boot up. need AP side trigger
*   FALSE: modem auto boot up/attach network
*       cfun_state=1:  auto boot up in normal mode
*       cfun_state=4:  auto boot up in flight mode
*****************************************************************************/
kal_bool custom_disable_modem_auto_startup(kal_uint8 *cfun_state)
{
    *cfun_state = 1;

    #if defined(__MODEM_CARD__) && defined(IC_MODULE_TEST)
        return KAL_FALSE;
    #endif

    if ((query_ps_conf_test_mode()==PS_CONF_TEST_FACTORY) && (query_ps_conf_test_profile_setting() & FACTORY_MODEM_AUTO_BOOT_AND_AUTO_ANSWER_BIT_FOR_L4C))
    {
        return KAL_FALSE;
    }

    #if defined(__MODEM_AUTO_STARTUP_TO_FLIGHT_MODE__)
        *cfun_state = 4;
        return KAL_FALSE;
    #endif

    #if defined(__DISABLE_MODEM_AUTO_STARTUP__) || defined(__SMART_PHONE_MODEM__)
        return KAL_TRUE;
    #endif

    return KAL_FALSE;
}

/*****************************************************************************
* FUNCTION
*   l4_custom_get_cscs_support_string()
*
* DESCRIPTION
*   This function is used to get the supportted list of the AT+CSCS
*
* PARAMETERS
*	none
*
* RETURNS
*	supported list string of AT+CSCS
*****************************************************************************/
kal_char* l4_custom_get_cscs_support_string(void)
{
    #ifdef __PHB_0x81_SUPPORT__ 
    return "+CSCS: (\"IRA\", \"GSM\", \"HEX\", \"PCCP437\", \"8859-1\", \"UCS2\", \"UCS2_0X81\")";
    #else
    return "+CSCS: (\"IRA\", \"GSM\", \"HEX\", \"PCCP437\", \"8859-1\", \"UCS2\")";
    #endif
}

/*****************************************************************************
* FUNCTION
*   l4_custom_is_supportted_cscs()
*
* DESCRIPTION
*   This function is used to check if the input name of cscs is support or not
*   which let customer decide what cscs should be supportted
*
* PARAMETERS
*	none
*
* RETURNS
*	supported list string of AT+CSCS
*****************************************************************************/
kal_bool l4_custom_is_supportted_cscs(kal_char* string)
{
    return KAL_TRUE;
}


/*****************************************************************************
* FUNCTION
*   custom_disallow_gprs_dialup_when_ms_busy()
*
* DESCRIPTION
*   This function is to configure "if we allow gprs dialup when MS is busy(in call)"
*   in Bluetooth SPP port
*   If return KAL_TRUE, we will response 'BUSY' for ATD*99# when MS busy (in call) 
*   If return KAL_FALSE, we allow ATD*99# to be processed when MS is in call
*
*   For BQB DUN testcase APS/BV/02.
*   It request MS to response 'BUSY' for GPRS dialup(ATD*99#) when MS is in call. 
*
* PARAMETERS
*	none
*
* RETURNS
*	KAL_TRUE or KAL_FASLE
*****************************************************************************/
kal_bool custom_disallow_gprs_dialup_when_ms_busy(void)
{
    return KAL_TRUE;
}


/*****************************************************************************
* FUNCTION
 *  custom_check_keypad_code
 * DESCRIPTION
 *  This function is used to convert the input of AT command (ex. AT+CKPD) 
 *  to the Device Key
 *  Customer can use this function to override the meaning of a key from AT command
 *  If customer didn't handle the key, we will check our default key mapping
 *  
 * PARAMETERS
 *  key         [IN]        input keys from command
 *  keycode   [OUT]     a output device key which is converted from key
 * RETURNS
 *  A pointer to the "key" which is unhandled
 *****************************************************************************/
kal_uint8* custom_check_keypad_code(kal_uint8 *key, kal_uint8 *keycode)
{
    /* EXAMPLE
    if (*key == 'y' || *key=='Y')
    {
        *keycode = 57; // DEVICE_KEY_Y defined in the kbd_table.h
        key++;
    }
    else if(*key == ':')
    {
        if(*(key+1) == 'j' || *(key+1) == 'J' )
        {
            *keycode = 42; // DEVICE_KEY_J defined in the kbd_table.h
            key += 2;
        }
    }
    */

    return key;
}


/*****************************************************************************
* FUNCTION
*   custom_remove_cgsms_constraint()
*
* DESCRIPTION
*   Regarding to AT+CGSMS = <service> to set service parameter to send SMS.
*   We don't allow to set <service> = 0 (PS only).
*   This is to prevent MO SMS fail due to no GPRS service available
*   We only allow to set <service> if TEST SIM is inserted (for FTA test)
*
*   If you want to remove such constraint, please modifty the function to return TRUE
* PARAMETERS
*	none
*
* RETURNS
*	KAL_TRUE or KAL_FASLE
*****************************************************************************/
kal_bool custom_remove_cgsms_constraint(void)
{
#if 0
#if defined(__CGSMS_FULL_SUPPORT__)
/* under construction !*/
#else
/* under construction !*/
#endif
#else
        return KAL_TRUE;
#endif
}

/*****************************************************************************
* FUNCTION
*   custom_get_supported_bands()
*
* DESCRIPTION
*   get the supported bands of the protocol
*
* PARAMETERS
*   gsm_bands   returned gsm bands 
*   umts_bands  returned umts bands 
*
* RETURNS
*   none
*****************************************************************************/
void custom_get_supported_bands(kal_uint32 *gsm_bands, kal_uint32 *umts_bands, kal_uint32 *lte_band)
{
    *gsm_bands = 0
        #if defined(__EGSM900__) 
            | 0x02  //BAND_900  
        #endif
        #if defined(__DCS1800__)  
            | 0x08  //BAND_1800 
        #endif                       
        #if defined(__GSM850__)   
            | 0x80  //BAND_850   
        #endif 
        #if defined(__PCS1900__)  
            | 0x10  //BAND_1900  
        #endif 
        ;

#if defined(__MTK_TARGET__)
#if !defined (L1_NOT_PRESENT)
    kal_char band_dbg_custom_str[100];		
   // *gsm_bands = L1D_GetBandSupport_PCore();
    *gsm_bands = L1D_UeBandCapability();
    kal_sprintf(band_dbg_custom_str, "custom_get_supported_bands(), L1D_GetBandSupport_PCore(): 0x%x\n\r", *gsm_bands);
    tst_sys_trace(band_dbg_custom_str);
#endif
#endif

    if(KAL_TRUE == gmss_is_tdscdma_mode_activated())
    {
        *umts_bands = 0 
            #if defined(__UMTS_TDD128_BAND_A__)
                | 0x00000001    
            #endif  
            #if defined(__UMTS_TDD128_BAND_B__)
                | 0x00000002    
            #endif  
            #if defined(__UMTS_TDD128_BAND_C__)
                | 0x00000004    
            #endif  
            #if defined(__UMTS_TDD128_BAND_D__)
                | 0x00000008    
            #endif  
            #if defined(__UMTS_TDD128_BAND_E__)
                | 0x00000010    
            #endif  
            #if defined(__UMTS_TDD128_BAND_F__)
                | 0x00000020    
            #endif  
            ;

    }
    else
    {
#if defined (__MTK_UL1_FDD__)
#if !defined (UL1_NOT_PRESENT)
#if defined(__MTK_TARGET__)
        {
		    CA_RF_BAND_CAPABILITY_T ue_cap;
		    
		    UL1D_UeCaBandCapability(&ue_cap, 1);
		    *umts_bands = ue_cap.single_band_ca_list;
        }
#endif
#endif
#endif
    }
#ifdef __MTK_TARGET__
#ifdef __LTE_RAT__
	{
#ifdef __BAND_EXTENSION_SUPPORT__
        mrs_eas_max_band_cap_for_user_extended((mrs_lte_band_list_struct*)lte_band);
#else
        mrs_eas_max_band_cap_for_user((kal_uint8*)lte_band);
#endif
	}
#endif
#endif
}

#ifdef __UMTS_RAT__
/*  Gordon 20090604 :For signal strength modification */
/*  when RSCP < -72 and original signal strength > 9, new formula defines three RSCP thresholds for re-calculating a new signal strength */
#define CUSTOM_3G_SIGNAL_LEVEL_MINUS_1_THRESHOLD (-72)
#define CUSTOM_3G_SIGNAL_LEVEL_MINUS_2_THRESHOLD  (-88)
#define CUSTOM_3G_SIGNAL_LEVEL_MINUS_3_THRESHOLD  (-104)
/*  when RSCP < -72 and original signal strength > 9, signal strength values (8,11,14) are mapped to signal level (1,2,3) */
#define CUSTOM_3G_SIGNAL_LEVEL_1_MAX_STRENGTH (8)
#define CUSTOM_3G_SIGNAL_LEVEL_2_MAX_STRENGTH (11)
#define CUSTOM_3G_SIGNAL_LEVEL_3_MAX_STRENGTH (14)

/*  20101028: Adjust TDD RSCP to CSQ mapping */ 
#ifdef __UMTS_TDD128_MODE__
#define CUSTOM_3G_TDD_RSCP_THRESHOLD_1 (-51)
#define CUSTOM_3G_TDD_RSCP_THRESHOLD_2 (-75)
#define CUSTOM_3G_TDD_RSCP_THRESHOLD_3 (-85)
#define CUSTOM_3G_TDD_RSCP_THRESHOLD_4 (-95)
#define CUSTOM_3G_TDD_RSCP_THRESHOLD_5 (-108)

#define CUSTOM_3G_TDD_CSQ_LEVEL_1 (31)
#define CUSTOM_3G_TDD_CSQ_LEVEL_2 (15)
#define CUSTOM_3G_TDD_CSQ_LEVEL_3 (7)
#define CUSTOM_3G_TDD_CSQ_LEVEL_4 (3)
#define CUSTOM_3G_TDD_CSQ_LEVEL_5 (0)
#endif /* __UMTS_TDD128_MODE__ */
#endif /* __UMTS_RAT__ */

/*****************************************************************************
* FUNCTION
*   custom_signal_strength_in_ts27007()
*
* DESCRIPTION
*   convert a dbm value to level value defined in 27.007 +CSQ
*
* PARAMETERS
*    kal_int32 strength_in_dbm, any strength value in dbm (Ex. RSCP, RSSI, EcN0...)
*
* RETURNS
*	level value: ranged from 0 to 31, 99 means invalid/un-available
*****************************************************************************/
kal_uint8 custom_signal_strength_in_ts27007(kal_int32 strength_in_dbm)
{
    kal_uint8 level = 99;
	if (strength_in_dbm <= -113)
	{
	    level = 0;
	}
	else if (strength_in_dbm >= -51)
	{
	    level = 31;
	}
	else
	{						
    	level = (strength_in_dbm + 113) / 2; 
	}	
	return level;
}

/*****************************************************************************
* FUNCTION
*   custom_signal_strength_cesq_level_to_raw()
*
* DESCRIPTION
*   This function is used to convert signal level to raw qdBm according to 3GPP 27.007 +CESQ definnition
*   
* PARAMETERS
*	none
*
* RETURNS
*   
*****************************************************************************/
kal_int32 custom_signal_strength_cesq_level_to_raw(l4_cesq_param_enum type, kal_uint8 signal_level)
{
    kal_int32 raw_in_qdbm=1;

    if (type == L4_GERAN_RXLEVEL)
    {
        if (signal_level >= 0 && signal_level <= 63)
        {
            raw_in_qdbm = (signal_level << 2) - 444;
        }
    }
    else if (type == L4_GERAN_BER)
    {
        // N/A
    }
    else if (type == L4_UTRA_RSCP)
    {
        if (signal_level >= 0 && signal_level <= 96)
        {
            raw_in_qdbm = (signal_level << 2) - 484;
        }
    }
    else if (type == L4_UTRA_ECNO)
    {
        if (signal_level >= 0 && signal_level <= 49)
        {
            raw_in_qdbm = (signal_level - 49) << 1;
        }
    }
    else if (type == L4_EUTRA_RSRQ)
    {
        if (signal_level >= 0 && signal_level <= 34)
        {
            raw_in_qdbm = (signal_level - 40) << 1;
        }
    }
    else if (type == L4_EUTRA_RSRP)
    {
        if (signal_level >= 0 && signal_level <= 97)
        {
            raw_in_qdbm = (signal_level << 2) - 564;
        }
    }

    return raw_in_qdbm;
}

/*****************************************************************************
* FUNCTION
*   custom_signal_strength_raw_to_cesq_level()
*
* DESCRIPTION
*   This function is used to convert qdBm to signal level according to 3GPP 27.007 +CESQ definnition
*   
* PARAMETERS
*	none
*
* RETURNS
*   
*****************************************************************************/
kal_uint8 custom_signal_strength_raw_to_cesq_level(l4_cesq_param_enum type, kal_int32 raw_in_qdbm)
{
    kal_uint8 signal_level = 0;
    //kal_int32 raw_in_dbm = (raw_in_qdbm / 4);

    if (type == L4_GERAN_RXLEVEL)
    {
        if (raw_in_qdbm == 1)
        {
            signal_level = 99;
        }
        else if (raw_in_qdbm < -440)
        {
            signal_level = 0;
        }
        else if (raw_in_qdbm >= -192)
        {
            signal_level = 63;
        }
        else
        {
            signal_level = (raw_in_qdbm + 444) >> 2;
        }
    }
    else if (type == L4_GERAN_BER)
    {
        if (raw_in_qdbm >= 0 && raw_in_qdbm <= 7)
        {
            signal_level = raw_in_qdbm;
        }
        else
        {
            signal_level = 99;
        }
    }
    else if (type == L4_UTRA_RSCP)
    {
        if (raw_in_qdbm == 1)
        {
            signal_level = 255;
        }
        else if (raw_in_qdbm < -480)
        {
            signal_level = 0;
        }
        else if (raw_in_qdbm >= -100)
        {
            signal_level = 96;
        }
        else
        {
            signal_level = (raw_in_qdbm + 484) >> 2;
        }
    }
    else if (type == L4_UTRA_ECNO)
    {
        if (raw_in_qdbm == 1)
        {
            signal_level = 255;
        }
        else if (raw_in_qdbm < -96)
        {
            signal_level = 0;
        }
        else if (raw_in_qdbm >= 0)
        {
            signal_level = 49;
        }
        else
        {
            signal_level = (raw_in_qdbm >> 1) + 49;
        }
    }
    else if (type == L4_EUTRA_RSRQ)
    {
        if (raw_in_qdbm == 1)
        {
            signal_level = 255;
        }
        else if (raw_in_qdbm < -78)
        {
            signal_level = 0;
        }
        else if (raw_in_qdbm >= -12)
        {
            signal_level = 34;
        }
        else
        {
            signal_level = (raw_in_qdbm >> 1) + 40;
        }
    }
    else if (type == L4_EUTRA_RSRP)
    {
        if (raw_in_qdbm == 1)
        {
            signal_level = 255;
        }
        else if (raw_in_qdbm < -560)
        {
            signal_level = 0;
        }
        else if (raw_in_qdbm >= -176)
        {
            signal_level = 97;
        }
        else
        {
            signal_level = (raw_in_qdbm + 564) >> 2;
        }
    }

    return signal_level;
}


/*****************************************************************************
* FUNCTION
*   custom_signal_strength_raw_to_csq_level()
*
* DESCRIPTION
*   convert 2G/3G signal strength raw data to level value defined in 27.007 +CSQ
*
* PARAMETERS
*    kal_uint8 rat            radio access technology (2G/3G)
*	 kal_int32 rssi_in_qdbm   2G/3G raw data   
*    kal_int32 RSCP_in_qdbm   3G raw data
*    kal_int32 EcN0_in_qdbm   3G raw data
*    kal_uint8 ber            2G/3G raw data
*	 kal_uint8 current_band   2G raw data
*
* RETURNS
*	level value: ranged from 0 to 31, 99 means invalid/un-available
*****************************************************************************/
kal_uint8 custom_signal_strength_raw_to_csq_level(
                kal_uint8 rat, 
                kal_int32 rssi_in_qdbm, 
                kal_int32 RSCP_in_qdbm,
                kal_int32 EcN0_in_qdbm,
                kal_uint8 ber,
                kal_uint8 current_band,
                kal_int32 RSRQ_in_qdbm,
                kal_int32 RSRP_in_qdbm)
{
    kal_int32 level = 99;
	if (rat == L4C_RAT_GSM)
	{
	    /* 2G conversion */
		if (rssi_in_qdbm != 1)
		{
		    /* refer to 27.007 AT+CSQ */
			level = custom_signal_strength_in_ts27007(rssi_in_qdbm / 4);
		}
	}
#ifdef __UMTS_RAT__	
    else if (rat == L4C_RAT_UMTS)
    {
    #ifdef __UMTS_TDD128_MODE__ /* 3G TDD conversion */	    
        #if defined(__OP01__) && defined(__MMI_FMI__) //MAUI_02973870, ALPS00056754, mtk02285
	    {
	        kal_int32 RSCP = RSCP_in_qdbm / 4;
			level = 199; //199 means unknown
			if (RSCP <= -116)
			{
			    level = 100;
			}
			else if (RSCP >= -25)
			{
			    level = 191;
			}
			else
			{
				level = RSCP + 216;
			}
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif		
	    }
	    #else /* Not-- defined(__OP01__) && defined(__MMI_FMI__) */ 
		{
		#if 0
/* under construction !*/
/* under construction !*/
        #else
		    kal_int32 RSCP = RSCP_in_qdbm / 4;

			if (RSCP >= CUSTOM_3G_TDD_RSCP_THRESHOLD_1)
			{
			    level = 31;
			}
			else if (RSCP >= CUSTOM_3G_TDD_RSCP_THRESHOLD_2)
			{
			    level = (CUSTOM_3G_TDD_CSQ_LEVEL_2+1) + 
					(CUSTOM_3G_TDD_CSQ_LEVEL_1-CUSTOM_3G_TDD_CSQ_LEVEL_2-1) * (RSCP-CUSTOM_3G_TDD_RSCP_THRESHOLD_2) / 
                    (CUSTOM_3G_TDD_RSCP_THRESHOLD_1-CUSTOM_3G_TDD_RSCP_THRESHOLD_2);
			}
			else if (RSCP >= CUSTOM_3G_TDD_RSCP_THRESHOLD_3)
			{
			    level = (CUSTOM_3G_TDD_CSQ_LEVEL_3+1) + 
					(CUSTOM_3G_TDD_CSQ_LEVEL_2-CUSTOM_3G_TDD_CSQ_LEVEL_3-1) * (RSCP-CUSTOM_3G_TDD_RSCP_THRESHOLD_3) / 
                    (CUSTOM_3G_TDD_RSCP_THRESHOLD_2-CUSTOM_3G_TDD_RSCP_THRESHOLD_3-1);
			}
			else if (RSCP >= CUSTOM_3G_TDD_RSCP_THRESHOLD_4)
			{
			    level = (CUSTOM_3G_TDD_CSQ_LEVEL_4+1) + 
					(CUSTOM_3G_TDD_CSQ_LEVEL_3-CUSTOM_3G_TDD_CSQ_LEVEL_4-1) * (RSCP-CUSTOM_3G_TDD_RSCP_THRESHOLD_4) / 
                    (CUSTOM_3G_TDD_RSCP_THRESHOLD_3-CUSTOM_3G_TDD_RSCP_THRESHOLD_4-1);
			}
			else if (RSCP >= CUSTOM_3G_TDD_RSCP_THRESHOLD_5)
			{
			    level = (CUSTOM_3G_TDD_CSQ_LEVEL_5+1) + 
					(CUSTOM_3G_TDD_CSQ_LEVEL_4-CUSTOM_3G_TDD_CSQ_LEVEL_5-1) * (RSCP-CUSTOM_3G_TDD_RSCP_THRESHOLD_5) / 
                    (CUSTOM_3G_TDD_RSCP_THRESHOLD_4-CUSTOM_3G_TDD_RSCP_THRESHOLD_5-1);
			}
			else
			{
			    level = 0;
			}			
		#endif		
		}
        #endif /* defined(__OP01__) && defined(__MMI_FMI__) */
		
    #else /* 3G FDD conversion */
	    
		/* Alva 20081210: signal strength = (Ec/N0 + 25) + (RSCP + 120) / 8, range: 0 ~ 31 */
		level =
		    ((EcN0_in_qdbm / 4) + 25) + 
		    (((RSCP_in_qdbm / 4) + 120) / 8);

		if (level > 31)
		{
		    level = 31;
		}

		/* Gordon 20090604: To reflect the real network environment more accurately, 
		 *  based on the experiment results, we modify the calculated signal level for MMI display 
		 *  When RSCP < -72 and the original signal strength > 9, 
		 *  a new formula is defined to modify the original signal strength.
		 *  More detailed information are shown in the excel file for the new formula */

		if (level >= (CUSTOM_3G_SIGNAL_LEVEL_1_MAX_STRENGTH+1))
		{
			kal_int32 RSCP_in_dbm = RSCP_in_qdbm / 4;
			if (RSCP_in_dbm < CUSTOM_3G_SIGNAL_LEVEL_MINUS_3_THRESHOLD) 
			{
				level = CUSTOM_3G_SIGNAL_LEVEL_1_MAX_STRENGTH;
			}
			else if (RSCP_in_dbm < CUSTOM_3G_SIGNAL_LEVEL_MINUS_2_THRESHOLD) 
			{
				if ((CUSTOM_3G_SIGNAL_LEVEL_3_MAX_STRENGTH) >= level)
				{
					level=CUSTOM_3G_SIGNAL_LEVEL_1_MAX_STRENGTH;
				}
				else
				{
					level=CUSTOM_3G_SIGNAL_LEVEL_2_MAX_STRENGTH; 
				}
			}
			else if (RSCP_in_dbm < CUSTOM_3G_SIGNAL_LEVEL_MINUS_1_THRESHOLD) 
			{
				if (CUSTOM_3G_SIGNAL_LEVEL_2_MAX_STRENGTH >= level)
				{
					level=CUSTOM_3G_SIGNAL_LEVEL_1_MAX_STRENGTH;
				}
				else if (CUSTOM_3G_SIGNAL_LEVEL_3_MAX_STRENGTH >= level)
				{
					level=CUSTOM_3G_SIGNAL_LEVEL_2_MAX_STRENGTH;
				}
				else
				{
					level=CUSTOM_3G_SIGNAL_LEVEL_3_MAX_STRENGTH;   
				}
			}
		}
    #endif /* __UMTS_TDD128_MODE__ */
    }
#endif /* __UMTS_RAT__ */
#ifdef __LTE_RAT__
    else if (rat == L4C_RAT_LTE)
    {
        if (RSRP_in_qdbm != 1)
        {
            level = custom_signal_strength_raw_to_cesq_level(L4_EUTRA_RSRP, RSRP_in_qdbm) >> 2;
        }
    }
#endif

	return (kal_uint8) level;
}


/*****************************************************************************
* FUNCTION
*   custom_signal_strength_raw_to_ciev_signal_level()
*
* DESCRIPTION
*   convert signal strength raw data to level <val> in +CIEV:<signal>,<val>
*
* PARAMETERS
*    kal_uint8 rat            radio access technology (2G/3G)
*	 kal_int32 rssi_in_qdbm   RSSI raw data
*    kal_int32 RSCP_in_qdbm   3G raw data
*    kal_int32 EcN0_in_qdbm   3G raw data
*    kal_uint8 ber            2G/3G raw data
*	 kal_uint8 current_band   2G raw data
*
* RETURNS
*	level value: ranges from 0 to 5
*****************************************************************************/
kal_uint8 custom_signal_strength_raw_to_ciev_signal_level(
            kal_uint8 rat, 
            kal_int32 rssi_in_qdbm, 
            kal_int32 RSCP_in_qdbm,
            kal_int32 EcN0_in_qdbm,
            kal_uint8 ber,
            kal_uint8 current_band,
            kal_int32 RSRQ_in_qdbm,
            kal_int32 RSRP_in_qdbm)
{
    kal_uint8 rx_level = 0;
    kal_uint8 signal_ind;

#if defined(__OP01__) && defined(__UMTS_TDD128_MODE__) && defined(__MMI_FMI__) //MAUI_02973870, ALPS00056754, mtk02285
    /* CMCC TD requirement */
    if (rat == L4C_RAT_GSM)
    {
        if (rssi_in_qdbm == 1)
        {
		    rx_level = 99;
        }
		else
		{
    		rx_level = custom_signal_strength_in_ts27007(rssi_in_qdbm / 4);
		}        
    }
	else if (rat == L4C_RAT_UMTS)
	{
	    rx_level = custom_signal_strength_in_ts27007(RSCP_in_qdbm / 4);
	}
    else if (rat == L4C_RAT_LTE)
    {
        if (RSRP_in_qdbm != 1)
        {
            rx_level = custom_signal_strength_raw_to_cesq_level(L4_EUTRA_RSRP, RSRP_in_qdbm) >> 2;
        }
    }
#else
    rx_level = custom_signal_strength_raw_to_csq_level(rat, rssi_in_qdbm, RSCP_in_qdbm, EcN0_in_qdbm, ber, current_band, RSRQ_in_qdbm, RSRP_in_qdbm);
#endif /* defined(__OP01__) && defined(__UMTS_TDD128_MODE__) && defined(__MMI_FMI__) */

    if (rx_level == 0 || rx_level == 99)
    {
        signal_ind = 0;
    }
    else if (rx_level < 6)
    {
        signal_ind = 1;
    }
    else if ((rx_level >= 6) && (rx_level < 12))
    {
        signal_ind = 2;
    }
    else if ((rx_level >= 12) && (rx_level < 18))
    {
        signal_ind = 3;
    }
    else if ((rx_level >= 18) && (rx_level < 24))
    {
        signal_ind = 4;
    }
    else if (rx_level >= 24)
    {
        signal_ind = 5;
    }
    else
    {
        signal_ind = 0;
    }

    return signal_ind;
}


/*****************************************************************************
* FUNCTION
*   custom_ciev_signal_variance()
*
* DESCRIPTION
*   This function is used to set the ignorable difference between two consequent
*   +CIEV Signal Strength URC for Bluetoth Hands-Free.
*
* PARAMETERS
*	none
*
* RETURNS
*   A kal_uint8 value 0 ~ 5 indicating the ignorable difference bwtween two <val>
*   in +CIEV:<signal>,<val>. If the return is larger than 0, the <val> different 
*   to the last reported +CIEV Signal Strength <val> which is smaller then the 
*   return would be ignored.
*   If the return value is 0, the +CIEV Signal Strength URC is reported as usual
*****************************************************************************/
kal_uint8 custom_ciev_signal_variance(void)
{
    /* The default return value is 0 which means no filter.
       If return value is 5, the +CIEV:<signal>,<val> is turn off
    */
    return 0;
}


/*****************************************************************************
* FUNCTION
*   custom_disable_gprs_csd_dialup()
*
* DESCRIPTION
*   This function is used to disable GPRS and CSD dial up functionality
*
* PARAMETERS
*	none
*
* RETURNS
*   KAL_TRUE is to disable gprs and csd dialup
*   KAL_FALSE has no effect on these functionality (default)
*****************************************************************************/
kal_bool custom_disable_gprs_csd_dialup(void) //MAUI_02600165
{
    return KAL_FALSE;
}

#if defined(__ATCMD_ONOFF_CHECK__)
/*****************************************************************************
* FUNCTION
*   custom_check_is_atcmd_allowed()
*
* DESCRIPTION
*   check if the command is allowed by custom or not
*
* PARAMETERS
*   cmd_id   [IN]   AT command enum defined in the ps\l4\atci\include\at_cmd.def
*
* RETURNS
*   KAL_TRUE: could be executed, 
*   KAL_FLASE: could not be executed
*****************************************************************************/
kal_bool custom_check_is_atcmd_allowed(rmmi_cmd_id_enum cmd_id)
{    
    /* the following example disallowed executing 
    * the command AT+EADP
    */
    /*if (cmd_id == RMMI_CMD_ATEADP) 
    {
        return KAL_FALSE;
    }*/
    return KAL_TRUE;
}
#endif

#ifdef __MOD_TCM__
/*****************************************************************************
* FUNCTION
*   custom_l4c_gprs_when_needed_timer()
*
* DESCRIPTION
*   This function is used to define GPRS when needed timer value
*   The unit is 100ms. Ex. 20 => 20 * 100ms => 2 seconds
*   Default value = 20 (2 seconds)
*   Maximum value = 255 (Due to kal_uint8 limit, the max is about 25.5 sec)
* PARAMETERS
*	none
*****************************************************************************/
kal_uint8 custom_l4c_gprs_when_needed_timer(void) 
{
    const kal_uint8 GPRS_DETACH_TIMER = 20;
    return GPRS_DETACH_TIMER;
} // MAUI_02598495, custom gprs detach timer

/*****************************************************************************
* FUNCTION
*   custom_l4c_ndis_fdn_enable()
*
* DESCRIPTION
*   This function is used to enable/disable FDN check before NDIS setup
*   0. the FDN check number is "*99#"
*   1. if it returns KAL_TRUE, then L4C checks PHB approve result to decide doing PDP activation or not,
*       - if PHB approve fails, then it does NOT send out PDP activation request
*       - if PHB approve succeeds, then it sends out PDP activation request
*
*   2. if it returns KAL_FALSE, the L4C always SKIPS PHB approve result and always send out PDP activation request
* PARAMETERS
*	none
*****************************************************************************/
kal_bool custom_l4c_ndis_fdn_enable(void)
{
#if 1
    return KAL_TRUE; //check FDN
#else
/* under construction !*/
#endif
}

/*****************************************************************************
* FUNCTION
*   custom_l4c_psbearer_indicate()
*
* DESCRIPTION
*   This function is used to enable/disable +PSBEARER: <x>, <y> indication
*   KAL_TRUE: Yes
*   KAL_FALSE: No
*
* PARAMETERS
*	none
*****************************************************************************/
kal_uint8 custom_l4c_psbearer_indicate(void)
{
    return KAL_FALSE;
}

kal_uint8 custom_tcm_operator_specfic_qci_mapping(tcm_eps_qos_struct *eps_qos)
{
    kal_uint8 mapping_qci;

#define MTK_OPERATOR_SPECIFIC_QCI_MAP_TO_GBR_QCI 4    
#define MTK_OPERATOR_SPECIFIC_QCI_MAP_TO_NON_GBR_QCI 9
    
    
    // GBR 
    if ( eps_qos->max_bitrate_up_lnk != 0
         || eps_qos->max_bitrate_down_lnk != 0
         || eps_qos->guarntd_bit_rate_up_lnk != 0
         || eps_qos->guarntd_bit_rate_down_lnk != 0
         || eps_qos->ext_max_bitrate_up_lnk != 0
         || eps_qos->ext_max_bitrate_down_lnk != 0
         || eps_qos->ext_guarntd_bit_rate_up_lnk != 0
         || eps_qos->ext_guarntd_bit_rate_down_lnk != 0
         || eps_qos->ext2_max_bitrate_up_lnk != 0
         || eps_qos->ext2_max_bitrate_down_lnk != 0
         || eps_qos->ext2_guarntd_bit_rate_up_lnk != 0
         || eps_qos->ext2_guarntd_bit_rate_down_lnk != 0
    ) {
        mapping_qci = MTK_OPERATOR_SPECIFIC_QCI_MAP_TO_GBR_QCI;
    } 
    // non-GBR
    else {
        mapping_qci = MTK_OPERATOR_SPECIFIC_QCI_MAP_TO_NON_GBR_QCI;
    }
    
    return mapping_qci;
}

#endif /* __MOD_TCM__ */

/*****************************************************************************
* FUNCTION
*   custom_l4c_max_poweroff_retry()
*
* DESCRIPTION
*   This function is used to define maximal waitting time for SIM power off while MS is going to shutdown
*   The unit is second. Ex. 2 => 2 seconds
*   Default value = 8 (seconds)
*   Maximum value = 255 (Due to kal_uint8 limit, the max is about 255 sec)
* PARAMETERS
*	none
*****************************************************************************/
kal_uint8 custom_l4c_max_poweroff_retry(void)
{
    return 8;
}


#ifdef __SAT__
/*****************************************************************************
* FUNCTION
*   custom_l4c_sat_ton_npi_transform()
*
* DESCRIPTION
*   This function is used to transform the TON/NPI of SAT send SS/CALL from SIM
*   
* PARAMETERS
*	raw_data    [IN] raw data from SIM
*
* RETURNS
*   the new data transformed from raw_data
*****************************************************************************/
kal_uint8 custom_l4c_sat_ton_npi_transform(kal_uint8 raw_data)
{
    kal_uint8 ret_val = 0x81;

    /* MAUI_02660770: return 0x91 if raw_data is between 0x90 to 0x9f;
     * Otherwise return 0x81
     */
    if ((raw_data >= 0x90) && (raw_data <= 0x9f))
    {
        ret_val = 0x91;
    }
    
    return ret_val;
}
#endif /* __SAT__ */

#ifdef __AMR_WB_WHITE_LIST__
/*****************************************************************************
* FUNCTION
*  custom_check_white_list
* DESCRIPTION
*  This function is for customize PLMN in the wihte list, on which CC support AMR_WB
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void custom_check_white_list(kal_bool * is_gsm_white_list,kal_bool * is_umts_white_list,kal_uint32 plmn_id)
{
#ifdef __AMR_WB_FOR_T_MOBILE__   
    /* *is_gsm_white_list =KAL_TRUE; means that MS support AMR_WB in 2G rat of the selected PLMN*/
    /*check 2G white_list plmn [byte2:mcc1,mcc2; byte1:mcc3,mnc1; byte0:mnc2,mnc3]*/
    switch(plmn_id)
    {
    /*Please add white plmn list as specified below:
        case 0x0046000f:
        case 0x0046002f:
            *is_gsm_white_list =KAL_TRUE;
            break;
    */            
        default:
   	      *is_gsm_white_list =KAL_FALSE;
            break;
    }  	
#else
#ifdef __AMR_GSM_IOT_SUPPORT__
    *is_gsm_white_list =KAL_TRUE;
#else
    *is_gsm_white_list =sbp_query_md_feature(SBP_AMR_WB_GSM);
#endif 
#endif    
#ifdef __OP11__
    /* *is_umts_white_list =KAL_TRUE; means that MS support AMR_WB in 3G rat of the selected PLMN*/   	
    /*check UMTS white_list plmn [byte2:mcc1,mcc2; byte1:mcc3,mnc1; byte0:mnc2,mnc3]*/
    switch(plmn_id)	
    {
    /*Please add white plmn list as specified below:       
        case 0x0046000f:
        case 0x0046002f:
            *is_umts_white_list =KAL_TRUE;
            break;
    */            
        default:
   	      *is_umts_white_list =KAL_FALSE;
   	      break;
    }
#else
    *is_umts_white_list =sbp_query_md_feature(SBP_AMR_WB_UMTS);    
#endif    
    return ;
}
#endif

/*****************************************************************************
* FUNCTION
*  cm_p_w_switch
* DESCRIPTION
*   This function is used to define if "P"(pause) and "W"(wait for user command)
*   of DTMF separator is switched or not
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool cm_dtmf_p_w_switch (void)
{
   return (CM_DTMF_P_W_SWITCH_FLAG);
}

#ifdef __FWP_NC_LAI_INFO__
/*****************************************************************************
* FUNCTION
*  cm_get_cell_lock_string
* DESCRIPTION
*   This function is used to let customer configure cell lock prefix and also
*   change prefix length, CELL_LOCK_PREFIX_LEN
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 cm_get_cell_lock_string (kal_uint8** prefix)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*prefix = &CELL_LOCK_PREFIX[0];
	return CELL_LOCK_PREFIX_LEN;
}
#endif /*__FWP_NC_LAI_INFO__*/

/*****************************************************************************
* FUNCTION
*  customer_define_codec_priority
* DESCRIPTION
*   This function is used to define the priority customer prefered
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
const kal_uint8 customer_define_codec_priority[SUPPORTED_2G_CODEC_NUM]=
{
#ifdef __CUSTOM_CODEC_PRIORITY__
    CSMCC_FR_AMRWB_V5,CSMCC_FR_V3,CSMCC_HR_V3,CSMCC_FR_V2,CSMCC_FR_V1,CSMCC_HR_V1
#else
    CSMCC_FR_AMRWB_V5,CSMCC_FR_V3,CSMCC_FR_V2,CSMCC_FR_V1,CSMCC_HR_V3,CSMCC_HR_V1
#endif
};

/*****************************************************************************
* FUNCTION
*  cc_get_SUPPORTED_2G_CODEC_NUM
* DESCRIPTION
*   This function is used to get the MAX Codec size customer defined 
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 cc_get_SUPPORTED_2G_CODEC_NUM(void)
{
    return(SUPPORTED_2G_CODEC_NUM);
}


#ifdef __CUSTOM_CONFIG_ACM_BOUND__
/*****************************************************************************
* FUNCTION
*  custom_is_acm_exceed_boundary
* DESCRIPTION
*   This function is used to check if acm exceed the boundary.
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool custom_is_acm_exceed_boundary (kal_uint32 acm_value)
{
       return ((kal_bool)(acm_value > CUSTOM_ACM_BOUND));
}
#endif /*__CUSTOM_CONFIG_ACM_BOUND__*/

/* MAUI_01637672 support CCWE */
/*****************************************************************************
* FUNCTION
*  custom_cc_get_acm_bound
* DESCRIPTION
*   This function is used to get the acm custom bound.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 custom_cc_get_acm_bound()
{
   return ((kal_uint32)CUSTOM_ACM_BOUND);
}

/*****************************************************************************
* FUNCTION
*  custom_cc_get_acm_ccwe_time
* DESCRIPTION
*   This function is used to get the acm ccwe time.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 custom_cc_get_acm_ccwe_time()
{
   return ((kal_uint32)CUSTOM_ACM_CALL_METER_WARNING_EVENT_SECONDS);
}

/*****************************************************************************
* FUNCTION
*  custom_config_rlc_timer
* DESCRIPTION
*   This function is used to get customer config rlc timer in seconds.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 custom_config_rlc_timer()
{
       return CSM_RLC_TIMER_CONFIG;
}

/*****************************************************************************
* FUNCTION
*  custom_config_cc_disc_error_cause
* DESCRIPTION
*   This function is used to get customer config CC_DISCONNCT error cause.
*
* PARAMETERS
*
* RETURNS
*  kal_uint16
* 
*****************************************************************************/
kal_uint16 custom_config_cc_disc_error_cause(kal_uint16 **cc_disc_error_cause)
{
    kal_uint8 disc_error_cause_len;
    *cc_disc_error_cause = &CUSTOM_DISC_ERROR_CAUSE[0];
	disc_error_cause_len = sizeof(CUSTOM_DISC_ERROR_CAUSE)/sizeof(CUSTOM_DISC_ERROR_CAUSE[0]);
    return disc_error_cause_len;
}

/*****************************************************************************
 * FUNCTION
 *  custom_get_at_audio_download_folder
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_wchar *custom_get_at_audio_download_folder()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME;
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_at_image_download_folder
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_wchar *custom_get_at_image_download_folder()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME;
}


#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
/* the maximum supported number of timer used in Fast Dormancy , 1 ~ 255 */
#define MAX_SUPPORTED_FD_TIMER_ID 4

/* the time slot of each tick to monitor PS data. uint is 0.1 sec */
#define FD_MONITOR_SLOT 10

/* the inactivity timer table. unit is 0.1 sec */
kal_uint16 fd_timer[MAX_SUPPORTED_FD_TIMER_ID] = 
{
/* timer id(b8~b1) meaning
   b1: screen on/off
   b2: NW R8 FD supported
   b3: cpc supported
*/
   50,   //t0: screen off, NW R8 FD off
   150,  //t1: screen on, NW R8 FD off
   50,   //t2: screen off, NW R8 FD on
   150   //t3: screen on, NW R8 FD on
};

/*****************************************************************************
* FUNCTION
*  	custom_get_fd_monitor_slot()
* DESCRIPTION
* 
* PARAMETERS
*	none
* RETURNS
*	kal_uint8
*****************************************************************************/
kal_uint8 custom_get_fd_monitor_slot(void)
{
   return FD_MONITOR_SLOT;
}


/*****************************************************************************
* FUNCTION
*  	custom_get_fd_timer_id()
* DESCRIPTION
*   	This function is used to return the timer ID according to input 
*   parameters
* PARAMETERS
*	conditions
* RETURNS
*	Timer ID
*****************************************************************************/
kal_uint8 custom_get_fd_timer_id(kal_bool is_screen_on, kal_bool is_r8_fd_support, kal_bool is_cpc_suppot)
{
    kal_uint8 timer_id;
    
    timer_id = (is_r8_fd_support == KAL_TRUE)? 1 : 0;
    timer_id <<= 1;
    timer_id |= (is_screen_on == KAL_TRUE)? 1 : 0;

    return timer_id;
}


/*****************************************************************************
* FUNCTION
*  	custom_set_fd_timer()
* DESCRIPTION
*   	This function is used to define time duration of Fast Dormancy to monitor
*   PS data transfer. The unit is 0.1 sec. 
*   Current default value is 40 sec (i.e. 400 x 0.1 sec)
* PARAMETERS
*	none
* RETURNS
*	time duration of handling ath for dialup
*****************************************************************************/
kal_bool custom_set_fd_timer(kal_uint8 timer_id, kal_uint16 timer_value)
{
    if (timer_id < MAX_SUPPORTED_FD_TIMER_ID)
    {
        fd_timer[timer_id] = timer_value;
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  	custom_get_fd_timer()
* DESCRIPTION
*   	This function is used to return the time duration of Fast Dormancy to monitor
*   PS data transfer. The unit is 0.1 sec.
* PARAMETERS
*	none
* RETURNS
*	time duration of handling ath for dialup
*****************************************************************************/
kal_uint16 custom_get_fd_timer(kal_uint8 timer_id)
{
    if (timer_id < MAX_SUPPORTED_FD_TIMER_ID)
    {
        return fd_timer[timer_id];
    }
    else
    {
        return 0xffff;
    }
}
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */

/*
 *  Table reconfig_mod_info_tbl is used to define the attribute of each module.
 *  It can define the module which want to regist the dynamic reconfigure procedure in 1st column.
 *  It can define the SAP which is used for ILM sending. (In 2nd column)
 *  It can define the refingure mode that the module is interested. (In 3rd column) 
 *     Note it's defined as bit-MAP such that it can define multiple modes.
 *  It can define the gemini module type which will automatically send to MOD_XXX_n, n= 1, 2, 3...
 */
reconfigure_module_info_struct reconfig_mod_info_tbl[] = 
                    {
                        {MOD_TCM,   L4C_ME_SAP,     RECONFIG_SIM_SWITCH,  CFG_GEMINI_MOD, NULL},
                        {MOD_MM,    L4C_ME_SAP,     RECONFIG_SIM_SWITCH,  CFG_GEMINI_MOD, NULL},
                        {MOD_NWSEL, L4C_ME_SAP,     RECONFIG_SIM_SWITCH,  CFG_GEMINI_MOD, NULL},
                        {MOD_SIM, L4C_ME_SAP,     RECONFIG_SIM_SWITCH,  CFG_GEMINI_MOD, NULL},
                        {MOD_RAC,   RAC_L4C_SAP,    (RECONFIG_SIM_SWITCH|RECONFIG_SBP_CHANGE),  CFG_GEMINI_MOD, NULL},
                        {MOD_SMS,   L4C_ME_SAP,     RECONFIG_SBP_CHANGE,  CFG_GEMINI_MOD, NULL},
                        {MOD_SMSAL, SMSAL_L4C_SAP,  RECONFIG_SBP_CHANGE,  CFG_GEMINI_MOD, NULL},
#ifdef __IMS_SUPPORT__
#ifdef __MULTIPLE_IMS_SUPPORT__                        
                        {MOD_IMC,    L4C_ME_SAP,     RECONFIG_SBP_CHANGE | RECONFIG_IMS_CHANGE,  CFG_GEMINI_MOD, nvram_custom_config_ims_profile},
                        {MOD_LTECSR, L4C_ME_SAP,     RECONFIG_SBP_CHANGE | RECONFIG_IMS_CHANGE,  CFG_GEMINI_MOD, nvram_custom_config_ltecsr_profile},
						{MOD_SDM,    L4C_ME_SAP,     RECONFIG_IMS_CHANGE,  CFG_GEMINI_MOD, nvram_custom_config_sdm_ads_profile},
                        {MOD_VDM,    L4C_ME_SAP,     RECONFIG_SBP_CHANGE | RECONFIG_IMS_CHANGE,  CFG_GEMINI_MOD, nvram_custom_config_vdm_ads_profile},
#else /* __MULTIPLE_IMS_SUPPORT__ */
                        {MOD_IMC,    L4C_ME_SAP,     RECONFIG_SBP_CHANGE | RECONFIG_IMS_CHANGE,  CFG_SINGLE_MOD, nvram_custom_config_ims_profile},
                        {MOD_LTECSR, L4C_ME_SAP,     RECONFIG_SBP_CHANGE | RECONFIG_IMS_CHANGE,  CFG_SINGLE_MOD, nvram_custom_config_ltecsr_profile},
                        {MOD_VDM,    L4C_ME_SAP,     RECONFIG_SBP_CHANGE | RECONFIG_IMS_CHANGE,  CFG_SINGLE_MOD, nvram_custom_config_vdm_ads_profile}, /* VDM use Signal Mode */
#endif /* __MULTIPLE_IMS_SUPPORT__ */
#endif
                        {MOD_CC,    L4C_ME_SAP,     RECONFIG_SBP_CHANGE,  CFG_GEMINI_MOD, NULL},
#if !defined(__MAUI_BASIC__)
                        {MOD_EL2TASK, L4C_EL2_SAP,  RECONFIG_SBP_CHANGE,  CFG_SINGLE_MOD, NULL},
#endif /*__MAUI_BASIC__(fix basic load build error)*/
                    };

reconfigure_module_info_struct *custom_get_reconfig_mod()
{
    return reconfig_mod_info_tbl;
}

kal_uint8 custom_get_num_of_reconfig_mod()
{
    return sizeof(reconfig_mod_info_tbl)/sizeof(reconfig_mod_info_tbl[0]);
}

#if (defined(__GEMINI__) || defined(__SGLTE__))&& defined(__SIM_ME_LOCK__)
/*****************************************************************************
* FUNCTION
*   custom_l4c_root_lock_verify()
*
* DESCRIPTION
*   This function is used to customiz link_SML. Each SIM ME Lock can depend
*   on the status of other SIM. Please modify pending_password_tbl and 
*   need_unlock_table according to the updated_sim and updated_type.
*
* PARAMETERS
*	updated_sim             [IN]        the updated SIM
*   updated_type            [IN]        the pending password of the updated SIM
*   pending_password_tbl    [IN/OUT]    the fake pending password table
*   need_unlock_table       [OUT]       the flag of each modified SIM
*
* RETURNS
*   whether the pending password of any SIM is change
*****************************************************************************/
kal_bool custom_l4c_root_lock_verify(kal_uint8 updated_sim, 
                                     smu_pending_password_id_enum updated_type, 
                                     smu_pending_password_id_enum *pending_password_tbl,
                                     kal_uint8 *need_unlock_table)
{
    kal_bool need_unlock = KAL_FALSE;
    
#if defined(__SGLTE__)
    sim_interface_enum SGLTE_ps_nvram_idx;
    sim_interface_enum SGLTE_cs_nvram_idx;
    kal_bool mmdc_mode = KAL_TRUE;
#endif

#if defined(__SGLTE__)
    #if defined(__SGLTE_DSDS__)
    
        if (KAL_TRUE == is_SGLTE_4G_switched())  // 4G switched
        {
            SGLTE_ps_nvram_idx = SIM2;
        }
        else
        {
            SGLTE_ps_nvram_idx = SIM1;
        }

        SGLTE_cs_nvram_idx = SIM3;

    #else

        SGLTE_ps_nvram_idx = SIM1;
    
        SGLTE_cs_nvram_idx = SIM2;

    #endif

    mmdc_mode = is_mmdc_mode(SIM1);  // is_mmdc_mode(protocol 1)

    if (KAL_TRUE == mmdc_mode)
    {
        switch (updated_type)
        {
            case ID_READY:
            {
                if (updated_sim == SGLTE_ps_nvram_idx)
                {
                    /* unlock SIM2 if SIM1 is valid */
                    if ((pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_FSIM_PIN) || 
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_NET_PIN) ||
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_NETSUB_PIN) ||
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_SP_PIN) ||
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_CORP_PIN) ||
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_LINK_NS_SP_PIN) ||
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_LINK_SIM_C_PIN))
                    {
                        pending_password_tbl[SGLTE_cs_nvram_idx] = ID_READY;
                        need_unlock_table[SGLTE_cs_nvram_idx] = 1;
                        need_unlock = KAL_TRUE;

                        tst_sys_trace("Set SGLTE_CS READY because of SGLTE_PS READY!");
                    }
                }

                pending_password_tbl[updated_sim] = ID_READY;  //SIM1, SIM2, or SIM3 ready

                tst_sys_trace("SGLTE SML READY!");

                break;
            }
            case ID_PH_FSIM_PIN:
            case ID_PH_NET_PIN:
            case ID_PH_NETSUB_PIN:
            case ID_PH_SP_PIN:
            case ID_PH_CORP_PIN:
            case ID_PH_LINK_NS_SP_PIN:
            case ID_PH_LINK_SIM_C_PIN:
            {
                /* SIM2 SML locked but SIM1 is valid */
                if (updated_sim == SGLTE_cs_nvram_idx)
                {
                    if (pending_password_tbl[SGLTE_ps_nvram_idx] == ID_READY)
                    {
                        pending_password_tbl[SGLTE_cs_nvram_idx] = ID_READY;
                        need_unlock = KAL_TRUE;
                        need_unlock_table[SGLTE_cs_nvram_idx] = 1;
                        tst_sys_trace("Set SGLTE_CS READY because of SGLTE_PS READY!!");
                    }
                    else if (pending_password_tbl[SGLTE_ps_nvram_idx] == ID_SIM_BUSY)
                    {
                        //don't lock first, wait for sim1 result
                        pending_password_tbl[SGLTE_cs_nvram_idx] = ID_SIM_BUSY;
                        tst_sys_trace("Set SGLTE_CS BUSY because of SGLTE_PS BUSY!");
                    }
                    else
                    {
                        pending_password_tbl[SGLTE_cs_nvram_idx] = updated_type;
                        tst_sys_trace("Set SGLTE_CS LOCKED!");
                    }
                }
                else //SIM1 or SIM3 locked 
                {
                    pending_password_tbl[updated_sim] = updated_type;
                    tst_sys_trace("Set SGLTE LOCKED!");
                }
                break;
            }
            default:
                /* not change */
                pending_password_tbl[updated_sim] = updated_type;
                break;
        }
    }
    else
    {
        pending_password_tbl[updated_sim] = updated_type;
    }

#else  /* __SGLTE__ */
#if defined(__TC01__) || defined(__LINK_SML__) || defined (__SIMME_LOCK_RELATIONSHIP__)
#if defined (__SIMME_LOCK_RELATIONSHIP__)
    if(l4csmu_get_dual_sim_lock_control_one_sim_lock_feature_supported() == KAL_TRUE)
    {
        switch (updated_type)
        {
            case ID_READY:
            {
                if ((updated_sim == SIM1) || (updated_sim == SIM2))
                {
                    kal_uint8 i;

                    /* unlock all SIM if SIM1/SIM2 is valid */
                    for (i=0; i<MAX_SIM_NUM; i++)
                    {
                        if ((pending_password_tbl[i] == ID_PH_FSIM_PIN) || 
                            (pending_password_tbl[i] == ID_PH_NET_PIN) ||
                            (pending_password_tbl[i] == ID_PH_NETSUB_PIN) ||
                            (pending_password_tbl[i] == ID_PH_SP_PIN) ||
                            (pending_password_tbl[i] == ID_PH_CORP_PIN) ||
                            (pending_password_tbl[i] == ID_PH_LINK_NS_SP_PIN) ||
                            (pending_password_tbl[i] == ID_PH_LINK_SIM_C_PIN))
                        {
                            pending_password_tbl[i] = ID_READY;
                            need_unlock_table[i] = 1;
                            need_unlock = KAL_TRUE;
                        }
                    }
                }
                pending_password_tbl[updated_sim] = updated_type;
                break;
            }
            case ID_PH_FSIM_PIN:
            case ID_PH_NET_PIN:
            case ID_PH_NETSUB_PIN:
            case ID_PH_SP_PIN:
            case ID_PH_CORP_PIN:
            case ID_PH_LINK_NS_SP_PIN:
            case ID_PH_LINK_SIM_C_PIN:
            {
                /* SIM2 Locked but SIM1 is valid */
                if (updated_sim == SIM2)
                {
                    if (pending_password_tbl[SIM1] == ID_READY)
                    {
                        pending_password_tbl[updated_sim] = ID_READY;
                        need_unlock = KAL_TRUE;
                        need_unlock_table[updated_sim] = 1;
                    }
                    else
                    {
                        pending_password_tbl[updated_sim] = updated_type;
                    }
                }
                else if (updated_sim == SIM1)
                {
                    if (pending_password_tbl[SIM2] == ID_READY)
                    {
                        pending_password_tbl[updated_sim] = ID_READY;
                        need_unlock = KAL_TRUE;
                        need_unlock_table[updated_sim] = 1;
                    }
                    else
                    {
                        pending_password_tbl[updated_sim] = updated_type;
                    }
                }
                else 
                {
                    pending_password_tbl[updated_sim] = updated_type;
                }
                break;
            }
            default:
                /* not change */
                pending_password_tbl[updated_sim] = updated_type;
                break;
        }
    }
	else if(l4csmu_get_dual_sim_lock_control_slot1_only_feature_supported() == KAL_TRUE)
	{
	    switch (updated_type)
        {
            case ID_READY:
            {
                if (updated_sim == SIM1)
                {
                    kal_uint8 i;

                    /* unlock all SIM if SIM1 is valid */
                    for (i=1; i<MAX_SIM_NUM; i++)
                    {
                        if ((pending_password_tbl[i] == ID_PH_FSIM_PIN) || 
                            (pending_password_tbl[i] == ID_PH_NET_PIN) ||
                            (pending_password_tbl[i] == ID_PH_NETSUB_PIN) ||
                            (pending_password_tbl[i] == ID_PH_SP_PIN) ||
                            (pending_password_tbl[i] == ID_PH_CORP_PIN) ||
                            (pending_password_tbl[i] == ID_PH_LINK_NS_SP_PIN) ||
                            (pending_password_tbl[i] == ID_PH_LINK_SIM_C_PIN) ||
                            (pending_password_tbl[i] == ID_SIM_BUSY))
                        {
                            pending_password_tbl[i] = ID_READY;
                            need_unlock_table[i] = 1;
                            need_unlock = KAL_TRUE;
                        }
                    }
                }
                pending_password_tbl[updated_sim] = updated_type;
                break;
            }
            case ID_PH_FSIM_PIN:
            case ID_PH_NET_PIN:
            case ID_PH_NETSUB_PIN:
            case ID_PH_SP_PIN:
            case ID_PH_CORP_PIN:
            case ID_PH_LINK_NS_SP_PIN:
            case ID_PH_LINK_SIM_C_PIN:
            {
                /* SIM2~SIM3 SML locked but SIM1 is valid */
                if (updated_sim != SIM1)
                {
                    if (pending_password_tbl[SIM1] == ID_READY)
                    {
                        pending_password_tbl[updated_sim] = ID_READY;
                        need_unlock = KAL_TRUE;
                        need_unlock_table[updated_sim] = 1;
                    }
                    else if (pending_password_tbl[SIM1] == ID_SIM_BUSY)
                    {
                        //don't lock first, wait for sim1 result
                        pending_password_tbl[updated_sim] = ID_SIM_BUSY;
                    }
                    else
                    {
                        pending_password_tbl[updated_sim] = updated_type;
                    }
                }
                else //SIM1 locked
                {
                    pending_password_tbl[updated_sim] = updated_type;
					pending_password_tbl[SIM2] = updated_type;       /* Update the same Lock status for SIM2 */
					tst_sys_trace("Slot1 ONLY:: SIM2 Context Pending Password updated as SIM1!");
                }
                break;
            }
            default:
                /* not change */
                pending_password_tbl[updated_sim] = updated_type;
                break;
        }
	}
    else
    {
        pending_password_tbl[updated_sim] = updated_type;
    }
#else  /* __SIMME_LOCK_RELATIONSHIP__ */
    switch (updated_type)
    {
        case ID_READY:
        {
            if (updated_sim == SIM1)
            {
                kal_uint8 i;
                
                /* unlock all SIM if SIM1 is valid */
                for (i=1; i<MAX_SIM_NUM; i++)
                {
                    if ((pending_password_tbl[i] == ID_PH_FSIM_PIN) || 
                        (pending_password_tbl[i] == ID_PH_NET_PIN) ||
                        (pending_password_tbl[i] == ID_PH_NETSUB_PIN) ||
                        (pending_password_tbl[i] == ID_PH_SP_PIN) ||
                        (pending_password_tbl[i] == ID_PH_CORP_PIN) ||
                        (pending_password_tbl[i] == ID_PH_LINK_NS_SP_PIN) ||
                        (pending_password_tbl[i] == ID_PH_LINK_SIM_C_PIN))
                    {
                        pending_password_tbl[i] = ID_READY;
                        need_unlock_table[i] = 1;
                        need_unlock = KAL_TRUE;
                    }
                }
            }
            pending_password_tbl[updated_sim] = updated_type;
            break;
        }
        case ID_PH_FSIM_PIN:
        case ID_PH_NET_PIN:
        case ID_PH_NETSUB_PIN:
        case ID_PH_SP_PIN:
        case ID_PH_CORP_PIN:
        case ID_PH_LINK_NS_SP_PIN:
        case ID_PH_LINK_SIM_C_PIN:
        {
            /* SIM2~SIM3 SML locked but SIM1 is valid */
            if (updated_sim != SIM1)
            {
                if (pending_password_tbl[SIM1] == ID_READY)
                {
                    pending_password_tbl[updated_sim] = ID_READY;
                    need_unlock = KAL_TRUE;
                    need_unlock_table[updated_sim] = 1;
                }
                else if (pending_password_tbl[SIM1] == ID_SIM_BUSY)
                {
                    //don't lock first, wait for sim1 result
                    pending_password_tbl[updated_sim] = ID_SIM_BUSY;
                }
                else
                {
                    pending_password_tbl[updated_sim] = updated_type;
                }
            }
            else //SIM1 locked
            {
                pending_password_tbl[updated_sim] = updated_type;
            }
            break;
        }
        default:
            /* not change */
            pending_password_tbl[updated_sim] = updated_type;
            break;
    }
	#endif /* __SIMME_LOCK_RELATIONSHIP__ */
    #else  /* __TC01__ || __LINK_SML__ || __SIMME_LOCK_RELATIONSHIP__ */
    /* default each SML is independent */
    pending_password_tbl[updated_sim] = updated_type;
    #endif  /* __TC01__ || __LINK_SML__ */

#endif  /* __SGLTE__ */

    return need_unlock;
}
#endif /* defined(__GEMINI__) && defined(__SIM_ME_LOCK__) */

/*****************************************************************************
* FUNCTION
*   custom_l4c_fill_ecc_category()
*
* DESCRIPTION
*   This function is used to turn on/off the ecc service category support
*
* PARAMETERS
*   none
*
* RETURNS
*   TRUE    : L4C will let MOD_PHB to approve the number and fill in the ecc category for ATDE
*   FALSE   : L4C will not let MOD_PHB to approve the number and fill in the ecc category for ATDE
*****************************************************************************/
kal_bool custom_fill_ecc_category(void)
{
    /*default value : KAL_FALSE.
    *   KAL_TRUE    : L4C will let MOD_PHB to approve the number and fill in the ecc category for ATDE
    *   KAL_FALSE   : L4C will not let MOD_PHB to approve the number and fill in the ecc category for ATDE
    */

    return KAL_FALSE;

}

/*****************************************************************************************
* FUNCTION
*   custom_cm_ctrl_by_sim()
*
* DESCRIPTION
*   this function is used to switch on/off call/sms/ss control by sim
*
* PARAMETERS
*   module [IN] could be CC, SS or SMS
* RETURNS
*   KAL_TRUE : support conrtorl by SIM
*   KAL_FALSE: not support control by SIM
******************************************************************************************/
kal_bool custom_cm_ctrl_by_sim(cm_ctrl_by_sim_enum module)
{
    switch (module)
    {
        case SMS_CTRL_BY_SIM:
            return KAL_TRUE;
            
        case CC_CTRL_BY_SIM:
            return KAL_TRUE;
            
        case SS_CTRL_BY_SIM:
            return KAL_TRUE;
            
        default:
            return KAL_FALSE;
    }
}

kal_uint8 ims_guard_timer_period = 64;
/*****************************************************************************
* FUNCTION
* custom_get_ims_reg_timeout_timer()
* DESCRIPTION
*
* PARAMETERS
*	none
* RETURNS
*	kal_uint8
*****************************************************************************/
kal_uint8 custom_get_ims_reg_timeout_timer(void)
{
    //length in Seconds
    return ims_guard_timer_period;
}

/*****************************************************************************
* FUNCTION
*  custom_set_ims_reg_timeout_timer()
* DESCRIPTION
*
* PARAMETERS
*	none
* RETURNS
*	kal_uint8
*****************************************************************************/
void custom_set_ims_reg_timeout_timer(kal_uint8 timeout_period)
{
    //length in Seconds
    ims_guard_timer_period = timeout_period;
}

/*****************************************************************************
* FUNCTION
*    custom_config_ss_asn_1()
* DESCRIPTION
*     to configure the SS Facility Component ASN.1
* PARAMETERS
*    none
* RETURNS
*    0: 24.080(refer to Q.773)
*    1: 34.123-3 annex.H
*****************************************************************************/
kal_uint8 custom_config_ss_asn_1(void)
{
    //0: 24.080(refer to Q.773)
    //1: 34.123-3 annex.H
    return 0;
}

//refer to the usage of AT+EREGCHK, default value is 0
kal_uint8 eregchk_cs = 0;
kal_uint8 eregchk_ps = 0;
/*****************************************************************************
* FUNCTION
*     custom_set_eregchk_method()
* DESCRIPTION
*     for AT+EREGCHK to set the method
* PARAMETERS
*     
* RETURNS
*   
*****************************************************************************/
void custom_set_eregchk_method(kal_uint8 cs_method, kal_uint8 ps_method)
{
    eregchk_cs = cs_method;
    eregchk_ps = ps_method;
    return;
}

/*****************************************************************************
* FUNCTION
*     custom_get_eregchk_method()
* DESCRIPTION
*     get the setting of AT+EREGCHK
* PARAMETERS
*     
* RETURNS
*   
*****************************************************************************/
void custom_get_eregchk_method(kal_uint8 *cs_method, kal_uint8 *ps_method)
{
    *cs_method = eregchk_cs;
    *ps_method = eregchk_ps;
    return;
}

/*****************************************************************************
* FUNCTION
*  custom_cs_reg_state_change_check()
* DESCRIPTION
*     used for +CREG URC report,
*     to check if the CREG state is changed or not according to AT+EREGCHK setting
*
* CREG state refer to 3GPP TS27.007:
* <stat>: integer type; circuit mode registration status
* 0 not registered, MT is not currently searching a new operator to register to
* 1 registered, home network
* 2 not registered, but MT is currently searching a new operator to register to
* 3 registration denied
* 4 unknown (e.g. out of GERAN/UTRAN/E-UTRAN coverage)
* 5 registered, roaming
* 6 registered for "SMS only", home network (applicable only when <AcT> indicates E-UTRAN)
* 7 registered for "SMS only", roaming (applicable only when <AcT> indicates E-UTRAN)
* 8 attached for emergency bearer services only (see NOTE 2) (not applicable)
* 9 registered for "CSFB not preferred", home network (applicable only when <AcT> indicates E-UTRAN)
* 10 registered for "CSFB not preferred", roaming (applicable only when <AcT> indicates E-UTRAN)
*
* PARAMETERS
*     none
* RETURNS
*     KAL_TRUE : CREG state is treated as changed
*     KAL_FALSE : CREG state is treated as not change
*****************************************************************************/
kal_bool custom_cs_reg_state_change_check(kal_uint8 state1, kal_uint8 state2)
{
    kal_bool ret_val;

    if (state1 != state2)
    {
        ret_val = KAL_TRUE;//default setting

        switch (eregchk_cs)
        {
        //customize the checking rule here
            case 1: /*treat state 0 and 2 as the same,
                                   *i.e. not to report +CREG URC while the CREG state is changing between 0 and 2*/
            {
                if ((state1 == 0 || state1 == 2)&&
                    (state2 == 0 || state2 == 2))
                {
                    ret_val = KAL_FALSE;
                }
                break;
            }
            case 2: //only report URC if state changes between different groups: {0|2|3|4} {5|7|10} {1|6|8|9}
            {
                if ((state1 == 0 || state1 == 2 || state1 == 3 || state1 == 4)&&
                    (state2 == 0 || state2 == 2 || state2 == 3 || state2 == 4))
                {
                    ret_val = KAL_FALSE;
                }
                else if ((state1 == 1 || state1 == 6 || state1 == 8 || state1 == 9)&&
                         (state2 == 1 || state2 == 6 || state2 == 8 || state2 == 9))
                {
                    ret_val = KAL_FALSE;
                }
                else if ((state1 == 5 || state1 == 7 || state1 == 10)&&
                         (state2 == 5 || state2 == 7 || state2 == 10))
                {
                    ret_val = KAL_FALSE;
                }
                break;
            }
            case 0:
            default:
                break;
        }
    }
    else
    {
        ret_val = KAL_FALSE;
    }

    return ret_val;
}

/*****************************************************************************
* FUNCTION
*  custom_ps_reg_state_change_check()
* DESCRIPTION
*     used for +CGREG/+CEREG URC report,
*     to check if the CGREG/CEREG state is changed or not according to AT+EREGCHK setting
*
* CGREG/CEREG state refer to 3GPP TS27.007:
* <stat>: integer type; circuit mode registration status
* 0 not registered, MT is not currently searching a new operator to register to
* 1 registered, home network
* 2 not registered, but MT is currently searching a new operator to register to
* 3 registration denied
* 4 unknown (e.g. out of GERAN/UTRAN/E-UTRAN coverage)
* 5 registered, roaming
* 6 registered for "SMS only", home network (not applicable)
* 7 registered for "SMS only", roaming (not applicable)
* 8 attached for emergency bearer services only (see NOTE 2) (applicable only when <AcT> indicates 2,4,5,6)
* 9 registered for "CSFB not preferred", home network (not applicable)
* 10 registered for "CSFB not preferred", roaming (not applicable)
*
* PARAMETERS
*     none
* RETURNS
*     KAL_TRUE : CGREG/CEREG state is treated as changed
*     KAL_FALSE : CGREG/CEREG state is treated as not change
*****************************************************************************/
kal_bool custom_ps_reg_state_change_check(kal_uint8 state1, kal_uint8 state2)
{
    kal_bool ret_val;

    if (state1 != state2)
    {
        ret_val = KAL_TRUE;//default setting

        switch (eregchk_ps)
        {
        //customize the checking rule here
            case 1: /*treat state 0 and 2 as the same,
                                   *i.e. not to report +CGREG URC while the CGREG state is changing between 0 and 2*/
            {
                if ((state1 == 0 || state1 == 2)&&
                    (state2 == 0 || state2 == 2))
                {
                    ret_val = KAL_FALSE;
                }
                break;
            }
            case 2: //only report URC if state changes between different groups: {0|2|3|4} {5|7|10} {1|6|8|9}
            {
                if ((state1 == 0 || state1 == 2 || state1 == 3 || state1 == 4)&&
                    (state2 == 0 || state2 == 2 || state2 == 3 || state2 == 4))
                {
                    ret_val = KAL_FALSE;
                }
                else if ((state1 == 1 || state1 == 6 || state1 == 8 || state1 == 9)&&
                         (state2 == 1 || state2 == 6 || state2 == 8 || state2 == 9))
                {
                    ret_val = KAL_FALSE;
                }
                else if ((state1 == 5 || state1 == 7 || state1 == 10)&&
                         (state2 == 5 || state2 == 7 || state2 == 10))
                {
                    ret_val = KAL_FALSE;
                }
                break;
            }
            case 0:
            default:
                break;
        }
    }
    else
    {
        ret_val = KAL_FALSE;
    }

    return ret_val;
}

/*****************************************************************************
* FUNCTION
*     custom_query_feature_is_supported()
* DESCRIPTION
*     
* PARAMETERS
*     
* RETURNS
*   
*****************************************************************************/
l4c_feature_support_enum custom_query_feature_is_supported(kal_uint8 feature_id)
{
    switch (feature_id)
    {
        case 0: // L4C CME Error Cade (27.007 ch9)
            return L4C_FEATURE_SUPPORT_LR11;            
        case 1: // L4C ipv4v6 cause2 report supported: +CGEV: ME PDN ACT <cid>, <reason> (27.009 ch9)
            return L4C_FEATURE_SUPPORT_LR11;
            
        case 2:
        default:
            return L4C_FEATURE_NOT_SUPPORT;
            break;
    }
    
    return L4C_FEATURE_NOT_SUPPORT;
}

/* record the SBP ID from SIM card*/
static kal_uint16 sim_sbp_id[MAX_SIM_NUM]={0};

/*****************************************************************************
* FUNCTION
*     custom_judge_sbp_id_use_mcc_mnc()
* DESCRIPTION
*     This function is used to judge what operator does the input MCC/MNC belong to
* PARAMETERS
*    mcc    [IN]
*    mnc    [IN]
* RETURNS
*   0: unknown/default
*   others: SBP ID (ex. 17: DOCOMO)
*****************************************************************************/
kal_uint16 custom_judge_sbp_id_use_mcc_mnc(kal_uint16 mcc, kal_uint16 mnc)
{    

    if ( ((mcc == 440) && (mnc == 10)) ||
         ((mcc == 310) && (mnc == 370)) ||
         ((mcc == 310) && (mnc == 470)) )
    {
        return 17;  // DOCOMO 
    }
    else if(((mcc == 405) && ( mnc >= 51 && mnc <= 56 ) ) ||
		     ((mcc == 404) && ( mnc == 2 || mnc == 3 || mnc == 10 || mnc == 16 || mnc == 31 || mnc == 40 || 
		     					mnc == 45 || mnc == 49 ||mnc == 70 || mnc == 90 || (mnc >= 92 && mnc<=98))))
    {
        return 147; // Airtel
    }
    else if (((mcc == 204) && ((mnc == 16) || (mnc == 20))) ||    
             ((mcc == 216) && (mnc == 30)) ||
             ((mcc == 219) && (mnc == 01)) ||             
             ((mcc == 230) && (mnc == 01)) ||
             ((mcc == 231) && ((mnc == 02) || (mnc == 04))) || 
             ((mcc == 232) && ((mnc == 03) || (mnc == 07))) ||
             ((mcc == 234) && (mnc == 30)) ||
             ((mcc == 260) && (mnc == 02)) ||
             ((mcc == 262) && ((mnc == 01) || (mnc == 06))) ||
             ((mcc == 294) && (mnc == 01)) ||
             ((mcc == 297) && ((mnc == 02) || (mnc == 04))))
    {
        return 5;  // TMOEU 
    }
    else if( ((mcc == 310) && ((mnc == 30)||(mnc == 70)||(mnc == 90)||(mnc == 150)||(mnc == 170)|| 
									(mnc == 280)||(mnc == 380)||(mnc == 410)||(mnc == 560)||(mnc == 680)||(mnc == 950)))||
				  ((mcc == 311) && (mnc == 180))||	   
				  ((mcc == 312) && (mnc == 670))||
				  ((mcc == 313) && (mnc == 100))||
				  ((mcc == 334) && ((mnc == 50)|| (mnc == 90))))
	{
		return 7; //AT&T
	}
	else if ((mcc == 310) && ((mnc == 160)||(mnc == 200)||(mnc == 210)||(mnc == 220)||(mnc == 230)||
								   (mnc == 240)||(mnc == 250)||(mnc == 260)||(mnc == 270)||(mnc == 300) ||(mnc == 310)||
								   (mnc == 330)||(mnc == 490)||(mnc == 580)||(mnc == 660)||(mnc == 800)))
    
    {
        return 8;   // TMO-US
    }
    else if ( (mcc == 460) && (mnc == 01)) 
    {
        return 2;  // CU 
    }
    else if ((mcc == 466) && (mnc == 97))
    {
        return 108; // TWM
    }
    else if ( ((mcc == 466) && (mnc == 11)) ||
              ((mcc == 466) && (mnc == 92)) )
    {
        return 109; // CHT
    }
    else if ( (mcc == 302) && ( mnc >= 220 && mnc <= 222 ) )
    {
        return 157; // Telus
    }
    else if ( ((mcc == 466) && (mnc == 89)) ||
              ((mcc == 466) && (mnc == 90)) )
    {
        return 176; // T-star
    }
    else if ( (mcc == 460) && (mnc == 00)) 
    {
        return 1;  // CMCC
    }
	else if ( ((mcc == 310) && (mnc == 120)) ||
			((mcc == 311) && (mnc == 490)) ||
			((mcc == 312) && (mnc == 530)) )
	{
		return 20; // Sprint
	}
    else
    {
        return 0;
    }
}

/*****************************************************************************
* FUNCTION
*     custom_set_imsi_mapping_to_sbp_id()
* DESCRIPTION
*     This function is used to compute the SBP ID according to IMSI
* PARAMETERS
*    imsi    [IN]
*    mnc_length_from_sim    [IN]
* RETURNS
*   void
*****************************************************************************/
void custom_set_imsi_mapping_to_sbp_id(kal_uint8 *imsi, kal_uint8 mnc_length_from_sim, kal_uint8 sim_id)
{
    kal_uint8 out_buff[40];
    kal_uint16 mcc=0, mnc=0;

    if (sim_id >=MAX_SIM_NUM)
    {
        kal_sprintf((kal_char*)out_buff, "SIM_SBP_ID(IMSI): invalid sim_id: %d", sim_id);
        tst_sys_trace((kal_char*)out_buff);
        return;
    }

    mcc = (imsi[0]>>4)*100 + (imsi[1]&0x0f)*10 + (imsi[1]>>4);
    mnc = (imsi[2]&0x0f)*10 + (imsi[2]>>4);
    
    if (mnc_length_from_sim== 3)
    {
        mnc = mnc*10 + (imsi[3]&0x0f);
    }
    else
    {
        // treat the length of mnc is 2 because some SIM card don't have MNC length value in the EF_AD.
    }

    sim_sbp_id[sim_id] = custom_judge_sbp_id_use_mcc_mnc(mcc, mnc);

    kal_sprintf((kal_char*)out_buff, "SIM_SBP_ID(IMSI)(%d): %d", sim_id, sim_sbp_id[sim_id]);
    tst_sys_trace((kal_char*)out_buff);
}

/*****************************************************************************
* FUNCTION
*     custom_get_sim_sbp_id()
* DESCRIPTION
*     This function is used to get the SBP ID according to the IMSI (SIM1)
*     Important notice:
*       - We have open market project with sbp_id set to 0 (default)
*          But, we still need to enable some operator specific feature according to the inserted SIM card.
*          So we provide this function for this kind of project.
*       - Please use this function only when it is needed to enable your operator 
*          specific SBP feature according to the IMSI under open market project (sbp_id = 0)
*       - The returned value is meaningful only when SIM task could get IMSI from the SIM card.
*          If your feature need to be enabled before SIM_READY_IND, please don't use this function.
*       - The returned value will be updated when SIM task get new IMSI
*          ex. SIM A inserted(SBP ID=A)-->SIM Error, ex. plug-out (SBP_ID=A), SIM B inserted (SBP ID=B)
*          If you have concern about race condition, please avoid using this function.
* PARAMETERS
*    imsi    [IN]
* RETURNS
*   0: unknown/default
*   others: SBP ID (ex. 17: DOCOMO)
*****************************************************************************/
kal_uint16 custom_get_sim_sbp_id()
{
    return sim_sbp_id[0];
}

/*****************************************************************************
* FUNCTION
*     custom_get_sim_sbp_id_by_ps()
* DESCRIPTION
*     This function is used to get the SBP ID according to the IMSI in ps_id
* PARAMETERS
*    ps_id    [IN]
* RETURNS
*   0: unknown/default
*   others: SBP ID (ex. 17: DOCOMO)
*****************************************************************************/
kal_uint16 custom_get_sim_sbp_id_by_ps(protocol_id_enum ps_id)
{
 return sim_sbp_id[ps_id];
}


/*****************************************************************************
* FUNCTION
*     custom_cc_tty_support_amr_wb()
* DESCRIPTION
*     TTY call support AMRWB or not
* PARAMETERS
*     
* RETURNS
*     KAL_TRUE : TTY supprot AMRWB
*     KAL_FALSE : TTY doesn't supprot AMRWB
*****************************************************************************/
kal_bool custom_cc_tty_support_amr_wb()
{
    return KAL_TRUE;
}

#if defined(__CC_CUSTOMIZED_TIMER__)
/*****************************************************************************
* FUNCTION
*     custom_cc_timer()
* DESCRIPTION
* 
* PARAMETERS
*     
* RETURNS
*     ret_timer timer value
*****************************************************************************/
kal_uint32 custom_cc_timer(custom_cc_timer_enum t)
{
    kal_uint32 ret_timer = 30 * KAL_TICKS_1_SEC;

    switch (t)
    {
        case CUSTOM_CC_T303:
        case CUSTOM_CC_T305:
        case CUSTOM_CC_T308:
        case CUSTOM_CC_T310:
            ret_timer = 30 * KAL_TICKS_1_SEC;
            break;
		case CUSTOM_CC_T313:
            ret_timer = 30 * KAL_TICKS_1_SEC;
            break;
        default:
            ret_timer = 30 * KAL_TICKS_1_SEC;
            break;
    }

    return ret_timer;
}
#endif

/*****************************************************************************
* FUNCTION
*     custom_get_ca_display_mode()
* DESCRIPTION
*     Show 4G+ when Scell is configured or activated
* PARAMETERS
*     
* RETURNS
*     CA_ICON_BY_CONFIG
*     CA_ICON_BY_ACTIVATION
*****************************************************************************/
ca_icon_display_mode_enum custom_get_ca_display_mode(void)
{
    //CA_ICON_BY_CONFIG
    //CA_ICON_BY_ACTIVATION
    return CA_ICON_BY_CONFIG;
}

#if defined(__RAC_CHANGE_VDP_SRVCC_BY_SIM__)

typedef struct {    
    kal_uint32 mccMnc_range_start;
    kal_uint32 mccMnc_range_end;
    kal_uint8  custom_vdp_setting;  // L4_CS_VOICE_ONLY, (CS_only:1 CS_prefer:2 PS_prefer:3 PS_only:4)
    kal_bool    custom_srvcc;        // Disable:KAL_FALSE(0),, Enable:KAL_TRUE(1)
} vdp_imsi_table;

const static vdp_imsi_table s_custom_vdp_table[] = 
{
    {45403, 45405, 1, KAL_FALSE},         // Hongkong China (H3G)
    {45414, 45414, 1, KAL_FALSE},         // Hongkong China (H3G)
    {23502, 23502, 1, KAL_FALSE},         // United Kingdom (EE)  
    {23430, 23434, 1, KAL_FALSE},         // United Kingdom (EE)
};
/*****************************************************************************
* FUNCTION
*  	custom_config_vdp_srvcc_by_sim()
* DESCRIPTION
*
* PARAMETERS
*	none
* RETURNS
*	void
*****************************************************************************/
void custom_config_vdp_srvcc_by_sim(kal_uint8* imsi, kal_uint8 mnc_length, kal_uint8 *custom_vdp_setting, kal_bool *custom_srvcc)
{
    kal_uint32 mccmnc;
    kal_uint32 i;
    kal_uint32 table_size = sizeof(s_custom_vdp_table) / sizeof(s_custom_vdp_table[0]);

    /* Get mccmnc */
    mccmnc = (imsi[0] >> 4);                        // mcc1
    mccmnc = (mccmnc * 10) + (imsi[1] & 0x0F);      // mcc2
    mccmnc = (mccmnc * 10) + (imsi[1] >> 4);        // mcc3
    mccmnc = (mccmnc * 10) + (imsi[2] & 0x0F);      // mnc1
    mccmnc = (mccmnc * 10) + (imsi[2] >> 4);        // mnc2
    if (mnc_length == 3)
    {
        mccmnc = (mccmnc * 10) + (imsi[3] & 0x0F);  // mnc3
    }


    /* Scan the s_vdp_imsi_table table*/
    for(i = 0; i < table_size; i++)
    {        
        if ((s_custom_vdp_table[i].mccMnc_range_start <= mccmnc) && 
            (s_custom_vdp_table[i].mccMnc_range_end >= mccmnc))
        {
            // Found in the table
            
            *custom_vdp_setting = s_custom_vdp_table[i].custom_vdp_setting;
            *custom_srvcc = s_custom_vdp_table[i].custom_srvcc;

            return;
        }
    }

    /* NOT Found in the table, default vdp by SIM */
    *custom_vdp_setting = 3;                // L4_IMS_PS_VOICE_PREFERRED_CS_VOICE_AS_SECONDARY (CS_only:1 CS_prefer:2 PS_prefer:3 PS_only:4)
    *custom_srvcc = KAL_TRUE;
 
}
#endif

#ifdef __SIGNAL_REPORT_OPTIMIZATION__
/*****************************************************************************
* FUNCTION
*  	custom_get_umts_cell_power_level_ind_timer()
* DESCRIPTION
*   	This function is used to return the time duration for UMTS cell power level indication
* PARAMETERS
*	none
* RETURNS
*	time duration
*****************************************************************************/
kal_uint16 custom_get_umts_cell_power_level_ind_timer(void)
{
    return CUSTOM_UMTS_CELL_POWER_LEVEL_IND_TIMER;
}
#endif

/*****************************************************************************
* FUNCTION
*     custom_check_ecc_change_rat_retry_allowed_for_plmn()
* DESCRIPTION
*     Check if the change RAT retry for ECC reject is not allowed for the particular PLMN
* PARAMETERS
*     
* RETURNS
*     KAL_TRUE - Allow change RAT retry
*     KAL_FALSE - Do not allow change RAT retry
*****************************************************************************/
kal_bool custom_check_ecc_change_rat_retry_allowed_for_plmn(void)
{
#if (!defined(__FLAVOR_BASIC__)) && (!defined(__FLAVOR_BASIC_TL1D__))
	plmn_id_rat_struct plmn_id_ptr;

	l4crac_get_current_plmn(&plmn_id_ptr);

    /* 704.01 is the MCC.MNC for Guatemala*/
	if((plmn_id_ptr.plmn_id.mcc1 == 7) && (plmn_id_ptr.plmn_id.mcc2 == 0) && (plmn_id_ptr.plmn_id.mcc3 == 4) && (plmn_id_ptr.plmn_id.mnc1 == 0) && (plmn_id_ptr.plmn_id.mnc2 == 1))
    {
        return KAL_FALSE;
	}
	else
	{
        return KAL_TRUE;
	}
#else
    return KAL_FALSE;
#endif
}

/*****************************************************************************
* FUNCTION
*  	custom_check_plmn_need_change_rat_retry()
* DESCRIPTION
*	For these camped PLMNs the change RAT retry needs to be done.
*
* PARAMETERS
*	kal_uint8* plmn
* RETURNS
*	KAL_TRUE or KAL_FALSE
* KAL_TRUE is to treat for this plmn, change RAT retry needs to be done
*****************************************************************************/
kal_bool custom_check_plmn_need_change_rat_retry(kal_uint8* camped_plmn)
{
    kal_bool need_retry = KAL_FALSE;

    //Add the list of PLMNs which require the change RAT retry for ecc call, ex:  add check using kal_mem_cmp(plmn,"<plmn>",<length>) == 0.
    if (kal_mem_cmp(camped_plmn,"46001",5) == 0)
    {
		need_retry = KAL_TRUE;
    }

    return need_retry;
}

#ifdef __CARRIER_RESTRICTION__
/*****************************************************************************
* FUNCTION
*     custom_get_crrst_sml_wild_char
* DESCRIPTION
*    Obtain the wild character to be used in SML lock code for Carrier Restriction feature
*
* PARAMETERS
*    none
* RETURNS
*    wild character to be used for SML lock code
* 
*****************************************************************************/
kal_uint8 custom_get_crrst_sml_wild_char(void)
{
    return '?';
}
#endif /* __CARRIER_RESTRICTION__ */