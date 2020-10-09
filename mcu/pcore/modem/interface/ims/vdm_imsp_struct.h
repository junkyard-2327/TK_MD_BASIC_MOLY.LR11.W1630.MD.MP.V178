/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 * ------------
 *   vdm_imsp_struct.h
 *
 * Project:
 * ------------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file defines the interface messages between VDM and IMS Proxy.
 *
 * Author:
 * -----------
 * -------
 *
 *===========================================================
 * $Log$
 *
 * 10 04 2018 kuan-wei.chen
 * [MOLY00356578] [VDM][Operator][C2][DTAG][Czech][FT][CO2-5631]VoWiFi DUT is not able to setup a voice call to the number that triggers an IMS 380 Alternative Service response (e.g. CZ Police Number 158) in FlightMode (VoWiFi registered).
 * [LR11.MP5][VDM] TMEU 380 redial
 *
 * 12 26 2017 kuan-wei.chen
 * [MOLY00297685] [LR11.MP5][IMSP][TMO-US][RTT] Redial voice only VoLTE EMC when RTT VoLTE EMC fail (VDM part)
 * [LR11.MP5] TMO RTT feature: IMSP-VDM part
 *
 * 12 26 2017 kuan-wei.chen
 * [MOLY00297685] [LR11.MP5][IMSP][TMO-US][RTT] Redial voice only VoLTE EMC when RTT VoLTE EMC fail (VDM part)
 * [LR11.MP5] TMO RTT feature: IMSP-VDM part
 *
 * 07 11 2017 kuan-wei.chen
 * [MOLY00261932] [CDMA-less][MP5] main feature : VDM part
 * LR11.MP5 : CDMA-LESS patch back. VDM part
 *
 * 06 07 2017 kuan-wei.chen
 * [MOLY00255649] [6755][E66_DUGL][ITS#1174]Without SIM and make Emergency call:911, DUT will met call drop
 * GT4G issue : select CS if LTE plmn id =46605 in limited service
 *
 * 06 02 2017 kuan-wei.chen
 * [MOLY00254610] [VzW] addl call_domain_cause - IMSP/VDM/IMC part
 * add cause in set_hvolte_call_domain: vdm/imsp
 *
 * 05 19 2017 kuan-wei.chen
 * [MOLY00250915] [TCL][MICKEY6T TMO] [IMS/VoLTE] - L_IMS_VoLTE_50944_1 - for VDM/IMSP check-in
 * 50944-1, VDM/IMSP part
 *
 * 04 27 2017 kuan-wei.chen
 * [MOLY00245523] [MT6755][VzW][TK][PhaseAReg][PreLC][InHouse][hVoLTE][2.2.14] no ESR when MO call
 * hvolte : VDM send AT+EHVOLTE=0,3 to L4 for silent redial triggerring event
 *
 * 02 06 2017 yingfui.hung
 * [MOLY00225609] [92->91 feature porting] SCM - interface
 *
 * 12 07 2016 yingfui.hung
 * [MOLY00215268] [VDM][ATT] ACB enable, select CS domain to dial up call. VDM part
 * 	
 * 	.
 *
 * 11 29 2016 shih-che.chou
 * [MOLY00214981] [VDM.h][TCL_TF][VzW][E911][2.18] MO IMS fail
 * .h
 *
 * 11 17 2016 yingfui.hung
 * [MOLY00213637] [MT6755][ATT-US][N0+MP5][FT][F4L][Seattle][CP][LAT2] jade#199 on CH4 mo call fail at 13:40
 * 	
 * 	.
 *
 * 10 18 2016 shih-che.chou
 * [MOLY00204150] TK vzw hVoLTE/E911 implementation
 * . IMSP part
 *
 * 10 18 2016 kuan-wei.chen
 * [MOLY00204150] TK vzw hVoLTE/E911 implementation
 * TK hVoLTE: L4/IMSP/VDM
 *
 * 10 17 2016 timo.korpela
 * [MOLY00206906] [FT][NL][VoLTE]he hidden caller ID does not work when make call to alphanumeric SIP-URI.
 * Implemented handling for CLIR parameter received in AT+CDU command.
 *
 * 10 07 2016 kuan-wei.chen
 * [MOLY00183611] [VZW_LC_IOT][PH1_VZW][Radio_Protocol][NDET_Lab] hVoLTE 2.2.40_Option-A fail
 * ADD AT+EICE=3 handling
 *
 * 10 04 2016 shih-che.chou
 * [MOLY00206357] [VzW] Call Pull & VICE Feature
 * .
 *
 * 08 11 2016 kuan-wei.chen
 * [MOLY00196499] [Jade N0][TK]Waiting call screen show "Unknown" when receive a waiting call from hiden number - vdm/imsp source file
 * 	
 * 	.
 *
 * 05 05 2016 yingfui.hung
 * [MOLY00171513] [PH1_VZW][joint-camp][GPS][Privacy Test] When Device's Location Setting is 'Location OFF', GPS work.
 * 	
 * 	.
 *
 * 03 11 2016 yingfui.hung
 * [MOLY00168587] [MT6755][Jade M6][MP3][L+W][In-house FTA][Case Fail][VoLTE] TC_11.2.2 FAIL
 *
 * 	.
 *
 * 12 17 2015 xinwei.cui
 * [MOLY00153299] [VILTE][Anite][v37][E40][12.21]FAIL
 * .
 *
 * 12 15 2015 kuan-wei.chen
 * [MOLY00153140] [D1][WFC][M0] WFC preference if wifi only, disable WFC, prompt "server unreachable" when make a call. - VDM part
 * wifi only mode is active only when AT+EIMSWFC=1
 *
 * 12 14 2015 kuan-wei.chen
 * [MOLY00150109] [IMS Feature] Non-UE detectable emergency call R12 feature
 * .
 *
 * 12 01 2015 kuan-wei.chen
 * [MOLY00133272] [NTT DOCOMO][VoLTE][IO030143] UE sends SM__ACTIVATE_PDP_CONTEXT_REQUEST unexpectedly
 * DCM, 1504929
 *
 * 11 26 2015 yingfui.hung
 * [MOLY00116938] [VOLTE][NTT DOCOMO] requirement 5A.7.1.1 Service category
 * 	
 * 	.
 *
 * 11 16 2015 lexel.yu
 * [MOLY00146327] [VzW] hVoLTE implementation
 * 	
 * 	.
 *
 * 11 13 2015 lexel.yu
 * [MOLY00149112] [VDM] NAS should keep search network when IMS call over WiFi ongoing
 * 	
 * 	.
 *
 * 10 22 2015 lexel.yu
 * [MOLY00146327] [VzW] hVoLTE implementation
 * 	.
 *
 * 09 14 2015 lexel.yu
 * [MOLY00141573] [UMOLY][LR11][TMO][IMS] bCSFB
 * 	.
 *
 * 08 26 2015 ben.chiu
 * [MOLY00138217] [ViLTE] M0 migration ViLTE feature Interface
 * ViLTE interface patch back
 *
 * 07 09 2015 nick.wang
 * [MOLY00127009] WFC Patch back to UMOLY- interface part
 * .moly wfc interface patch
 *
 * 07 09 2015 nick.wang
 * [MOLY00127009] WFC Patch back to UMOLY- interface part
 * 	.jade interface sync
 *
 * 06 11 2015 lexel.yu
 * [MOLY00085703] [VDM][MT6291] Sync MOLY to UMOLY
 * 	[MOLY00114718] [VDM][Volunteer Patch] Patch back for MOLY trunk
 * 	ATDC for conference call
 *
 * 06 10 2015 edwin.liu
 * [MOLY00120219] Merge MOLY IMSP changes to UMOLY
 * 	.
 *
 * 06 05 2015 edwin.liu
 * IMSP to UMOLY.
 *
 * 04 09 2015 lexel.yu
 * [MOLY00106459] [MT6291][IMS] VoLTE call event download
 * 	IMS Call Event Download
 *
 * 03 16 2015 lexel.yu
 * [MOLY00085703] [VDM][MT6291] Sync MOLY to UMOLY
 * 	[MOLY00080860] fix typo: replace vdm_imsp_snd_ads_staus_req_struct by vdm_imsp_snd_ads_status_req_struct
 * 	[MOLY00093643] [K2][CMCC][VoLTE][NS-IOT][R&S][TC 5.2.9.2][B3-E38]UE GSM??????^LTE?????????`? fail
 *
 * 02 24 2015 lexel.yu
 * [MOLY00085703] [VDM][MT6291] Sync MOLY to UMOLY
 * 	[MOLY00095972] [CMCC VoLTE][VDM] Add "4 to 23G" and "23G to 4" for IRAT event.
 *
 * 12 05 2014 lexel.yu
 * [MOLY00085703] [VDM][MT6291] Sync MOLY to UMOLY
 * 	[MOLY00085717] [VoLTE] Android L release VoLTE refactory for VDM and IMSP
 *
 * 11 26 2014 lexel.yu
 * [MOLY00085703] [VDM][MT6291] Sync MOLY to UMOLY
 * 	[MOLY00083542] [L4]add a new internal URC to notify VDM STK call number (+ESTKCNUM)
 * 	VDM part
 *
 * 11 05 2014 lexel.yu
 * [MOLY00083035] [VDM] IMS call information
 * 	.
 *
 * 09 02 2014 allan.ke
 * [MOLY00075245] Change the algorithm of ADS SSAC timer control and include IMSVoPS as the conditions for domain selection when dialing emergency call
 *
 * 04 25 2014 tehuang.liu
 * [MOLY00063538] [6290E2][VoLTE][VDM] Support VoLTE Gemini architecture
 * not use compile options for VoLTE Gemini interface structures definition
 *
 * 04 23 2014 tehuang.liu
 * [MOLY00063538] [6290E2][VoLTE][VDM] Support VoLTE Gemini architecture
 * Check in VoLTE+Gemini related interfaces for VDM, IMSP, L4C, EVAL, and ERRC
 *
 * 04 11 2014 tehuang.liu
 * [MOLY00062327] [6290E2][VoLTE][VDM] Support STKCALL in CS domain
 * .
 *
 * 04 09 2014 jinghan.wang
 * [MOLY00062091] [IMS][VoLTE] Check in STKCALL part for VDM TRK
 * .
 *
 * 02 20 2014 benjamin.kuo
 * [MOLY00056441] Use string instead enum for call type in CRING
 * .
 *
 * 02 17 2014 benjamin.kuo
 * [MOLY00056253] Merge SRVCC implementation from personal CBr to MOLY trunk
 * SRVCC
 *
 * 02 14 2014 benjamin.kuo
 * [MOLY00055885] [6290E2][VoLTE][MWC] incorrect URC oder of VDM and IMSP
 * +CRING
 *
 * 12 10 2013 vend_edwin.liu
 * IMSP.
 *****************************************************************************/

#ifndef _VDM_IMSP_STRUCT_H_
#define _VDM_IMSP_STRUCT_H_

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "ims_common_def.h"
#include "vdm_imc_struct.h"
#include "vdm_imsp_enums.h"
#include "ps_public_enum.h"
#include "l3_inc_enums.h"
#include "sim_public_enum.h"
#include "mcd_l3_inc_struct.h"
#include "c2k_irat_msg_struct.h"

typedef enum 
{
    VDM_IRAT_STATUS_IDLE = 0,
    VDM_IRAT_STATUS_FROM_4_TO_2,
    VDM_IRAT_STATUS_FROM_4_TO_3,
    VDM_IRAT_STATUS_FROM_2_TO_4,
    VDM_IRAT_STATUS_FROM_3_TO_4,
    // below two items may be used when IRAT request is triggered by NWSEL with rat GAS_UAS_TBD
    VDM_IRAT_STATUS_FROM_4_TO_23,
    VDM_IRAT_STATUS_FROM_23_TO_4,
} vdm_irat_status_enum;


typedef enum
{
    ADS_PROGRESS_ATTEMPT = 0,
    ADS_PROGRESS_SUCCESS
} ads_indication_progress_enum;


typedef enum
{
    ADS_DOMAIN_CS = 0,
    ADS_DOMAIN_IMS
} ads_indication_domain_enum;


// mirror from rmmi_reg_state_enum
typedef enum 
{
   NAS_REG_STATUS_NOT_REGISTERED = 0,
   NAS_REG_STATUS_REGISTERED_HOME,
   NAS_REG_STATUS_NOT_REGISTERED_SEARCHING,
   NAS_REG_STATUS_REG_DENIED,   
   NAS_REG_STATUS_OUT_OF_COVERAGE,
   NAS_REG_STATUS_REGISTERED_ROAMING,
   NAS_REG_STATUS_SMS_ONLY_HOME,
   NAS_REG_STATUS_SMS_ONLY_ROAMING,
   NAS_REG_STATUS_EMERGENCY_ONLY,
   NAS_REG_STATUS_CSFB_NOT_PREFERRED_HOME,
   NAS_REG_STATUS_CSFB_NOT_PREFERRED_ROAMING
} nas_reg_status_enum;


/******************************************************************************
 * Common AT command structure
 *****************************************************************************/

/*
 *  temp. for UT by MSC
 */
typedef struct
{
    kal_uint8                       at_cmd_string[128];
    
} at_cmd_buf_struct;


typedef struct 
{  
    LOCAL_PARA_HDR 
    ims_result_code_enum            result;
    ims_err_id_enum                 err_id;
} vdm_imsp_common_at_rsp_struct;


typedef vdm_imsp_common_at_rsp_struct vdm_imsp_common_at_cnf_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8               call_id;
    kal_uint8               ecpi_type;
    ims_ecpi_info_struct    ecpi_info;
} vdm_imsp_common_cs_cc_epci_ind_struct;


/******************************************************************************
 * ATD<num> or ATD<num>;
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8               dial_num[MAX_CC_ATD_NUM_LEN];
    kal_bool                is_video_call;
} vdm_imsp_cmd_dial_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_dial_rsp_struct;

typedef vdm_imsp_cmd_dial_ind_struct vdm_imsp_cs_cc_mo_call_req_struct;
typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_mo_call_cnf_struct;
/******************************************************************************
 * AT+CDU=1,<uri>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8               dial_uri[MAX_CC_CDU_URI_LEN];
    kal_bool                video_call;
    kal_uint8               clir;
} vdm_imsp_cmd_dial_uri_ind_struct;


typedef struct 
{  
    LOCAL_PARA_HDR 
    ims_result_code_enum            result;
    ims_err_id_enum                 err_id;
    kal_uint8                       call_id;
} vdm_imsp_cmd_dial_uri_rsp_struct;


/******************************************************************************
 * AT+STKCALL=0 
 * NOTE: This AT command is forwarded from IMSP to VDM.
 * NOTE: For AT_STKCALL=x where x!=0, this AT command is not forwarded to VDM.
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_stk_call_rsp_struct;
typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_stk_call_cnf_struct;


/******************************************************************************
 * AT+STKCALL=x 
 * NOTE: VDM can ask IMSP to send AT+STKCALL=x to CS domain for sending a TR.
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    sat_terminal_res_enum tr;
} vdm_imsp_snd_stk_call_tr_req_struct;


/******************************************************************************
 * AT+EVADSMOD=<mode>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    vdm_ads_mode_enum    ads_mode;
} vdm_imsp_cmd_ads_mode_ind_struct;


/******************************************************************************
 * AT+EVADSREP=<mode>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    vdm_ads_result_report_mode_enum   ads_result_report_mode;
} vdm_imsp_cmd_ads_result_report_ind_struct;




/******************************************************************************
 * ATDE<num>;
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8               dial_num[MAX_CC_ATD_NUM_LEN];
} vdm_imsp_cmd_dial_emerg_ind_struct;

/******************************************************************************
 * ATDER=<num>,<call_id>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8               dial_num[MAX_CC_ATD_NUM_LEN];
    kal_uint8               call_id;
} vdm_imsp_cmd_dial_emerg_retry_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_dial_emerg_rsp_struct;

typedef vdm_imsp_cmd_dial_emerg_ind_struct vdm_imsp_cs_cc_emerg_call_req_struct;
typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_emerg_call_cnf_struct;


/******************************************************************************
 * AT+EWFCP=<profile>;
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    wfc_profile_enum wfc_profile;
} vdm_imsp_cmd_wfc_profile_ind_struct;


/******************************************************************************
 * AT+EIMSWFC=<wfc_switch>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool wfc_switch;
} vdm_imsp_cmd_wfc_switch_ind_struct;


/******************************************************************************
 * +ECPI:<call_id>,<msg_type=130>,<is_ibt>,<is_tch>,<dir>,
 *       <call_mode>,[<number>,<type>],"<pau">,[<disc_cause>]
 *****************************************************************************/
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8               call_id;
    ims_ecpi_info_struct    ecpi_info;
} vdm_imsp_snd_ecpi_mo_call_id_alloc_req_struct;


typedef vdm_imsp_common_cs_cc_epci_ind_struct vdm_imsp_cs_cc_mo_call_id_ind_struct;


/******************************************************************************
 * +ECPI:<call_id>,<msg_type=0>,<is_ibt>,<is_tch>,<dir>,
 *       <call_mode>,[<number>,<type>],"<pau>",[<disc_cause>]
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8               call_id;
    ims_ecpi_info_struct    ecpi_info;
} vdm_imsp_snd_ecpi_mt_call_setup_req_struct;

typedef vdm_imsp_common_cs_cc_epci_ind_struct vdm_imsp_cs_cc_mt_call_setup_ind_struct;

/******************************************************************************
 * +ECPI:<call_id>,<msg_type=133>,<is_ibt>,<is_tch>,<dir>,
 *       <call_mode>,[<number>,<type>],"<pau>",[<disc_cause>]
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8                   call_id;
    ims_ecpi_info_struct        ecpi_info;
    kal_bool                    is_far_end;
} vdm_imsp_snd_ecpi_call_release_req_struct;

/******************************************************************************
 * +ECPI:<call_id>,<msg_type=137>,<is_ibt>,<is_tch>,<dir>,
 *       <call_mode>,[<number>,<type>],"<pau>",[<disc_cause>]
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8                   call_id;
    ims_ecpi_info_struct        ecpi_info;
} vdm_imsp_snd_ecpi_rtt_redial_req_struct;

typedef vdm_imsp_common_cs_cc_epci_ind_struct vdm_imsp_cs_cc_call_disconnect_ind_struct;

/******************************************************************************
 * +ECPI:<call_id>,<msg_type!=0,130,133>,<is_ibt>,<is_tch>,<dir>,
 *       <call_mode>,[<number>,<type>],"<pau>",[<disc_cause>]
 *****************************************************************************/
typedef vdm_imsp_common_cs_cc_epci_ind_struct vdm_imsp_cs_cc_ecpi_translate_ind_struct;

typedef vdm_imsp_cs_cc_ecpi_translate_ind_struct vdm_imsp_cs_cc_ecpi_translate_rsp_struct;


/******************************************************************************
 * AT+CHLD=[<n>]
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8                       call_id;
    ims_call_related_ss_type_enum   opcode;
} vdm_imsp_cmd_call_related_ss_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_call_related_ss_rsp_struct;

typedef vdm_imsp_cmd_call_related_ss_ind_struct vdm_imsp_cs_cc_call_related_ss_req_struct;

typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_call_related_ss_cnf_struct;

/******************************************************************************
 * ATH
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
} vdm_imsp_cmd_hangup_all_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_hangup_all_rsp_struct;

typedef vdm_imsp_cmd_hangup_all_ind_struct vdm_imsp_cs_cc_hangup_all_req_struct;

typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_hangup_all_cnf_struct;

/******************************************************************************
 * AT+ECHUP=<call_id>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8 call_id;
} vdm_imsp_cmd_force_hangup_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_force_hangup_rsp_struct;

typedef vdm_imsp_cmd_force_hangup_ind_struct vdm_imsp_cs_cc_force_hangup_req_struct;
typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_force_hangup_cnf_struct;


/******************************************************************************
 * +EAIC: <call_id>,<number>,<type>,<call_mode>,<seq_no>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8                       call_id;
    ims_cc_eaic_info_struct         eaic_info;
    kal_uint8                       seq_no;    
} vdm_imsp_snd_mt_call_approve_req_struct;

typedef vdm_imsp_snd_mt_call_approve_req_struct vdm_imsp_cs_cc_mt_call_present_ind_struct;


/******************************************************************************
 * AT+EAIC=<mode>,<call_id>,<seq_no>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8                       call_id;
    kal_uint8                       seq_no;
    ims_cc_eaic_result_enum         eaic_result;
} vdm_imsp_cmd_mt_call_approve_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_mt_call_approve_rsp_struct;

typedef vdm_imsp_cmd_mt_call_approve_ind_struct vdm_imsp_cs_cc_mt_call_present_rsp_struct;

/******************************************************************************
 * ATA
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
} vdm_imsp_cmd_mt_call_accept_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_mt_call_accept_rsp_struct;

typedef vdm_imsp_cmd_mt_call_accept_ind_struct vdm_imsp_cs_cc_mt_call_accept_req_struct;
typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_mt_call_accept_cnf_struct;

/******************************************************************************
 * VTS=<dtmf>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8   digit;
} vdm_imsp_cmd_dtmf_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_dtmf_rsp_struct;

typedef vdm_imsp_cmd_dtmf_ind_struct vdm_imsp_cs_cc_send_digit_req_struct;
typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_send_digit_cnf_struct;

/******************************************************************************
 * AT+EVTS=<action>,<digit>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    ims_dtmf_action_enum            action;
    kal_uint8                       digit;
} vdm_imsp_cmd_ext_dtmf_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_ext_dtmf_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                       digit;
} vdm_imsp_cs_cc_start_send_digit_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} vdm_imsp_cs_cc_stop_send_digit_req_struct;


typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_start_send_digit_cnf_struct;
typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_stop_send_digit_cnf_struct;

/******************************************************************************
 * AT+CEER
 * +CEER:<cause>,<report>
 * NOTE: IMSP maps <ceer_cause> (int) to <report> (char string)
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
} vdm_imsp_cmd_ext_error_report_ind_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    ims_ext_error_report_enum       ceer_cause;
    ims_result_code_enum            result;
    ims_err_id_enum                 err_id;
    kal_uint16                      ecc_category;
} vdm_imsp_cmd_ext_error_report_rsp_struct;

typedef vdm_imsp_cmd_ext_error_report_ind_struct vdm_imsp_cs_cc_ext_error_report_req_struct;

typedef vdm_imsp_cmd_ext_error_report_rsp_struct vdm_imsp_cs_cc_ext_error_report_cnf_struct;

/******************************************************************************
 * AT+CSTA:<type>
 * NOTE: IMSP multicasts this command to VDM (without rsp) and ATCI 
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8       type;
} vdm_imsp_cmd_select_type_of_addr_ind_struct;


/******************************************************************************
 * AT+CLCC
 * +CLCC:<idx>,<dir>,<stat>,<mode>,<mpty>,[<number>,<type>[,<alpha>[,<priority>[,<CLI_validity>]]]]... 
 *****************************************************************************/
typedef vdm_imc_ims_cc_list_current_calls_req_struct 
        vdm_imsp_cmd_list_current_calls_ind_struct;

//avoid modifying ims_interface_md.h, declare new structure for CS CLCC
typedef struct {
    kal_uint8               call_id;
    ims_call_dir_enum       dir;
    ims_call_state_enum     call_state;
    ims_call_mode_enum      call_mode;
    kal_bool                mpty;  // FALSE: is NOT conference call, TRUE: is conference call
    ims_call_type_enum      call_type;
    kal_uint8               number[MAX_CC_ATD_NUM_LEN];
    kal_uint8               cli_validity;
} vdm_imsp_call_list_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   total_call;
    vdm_imsp_call_list_struct   call_list[IMS_MAX_CALL_NUM];
} vdm_imsp_cmd_list_current_calls_rsp_struct;


/******************************************************************************
 * AT+EAPPROVE:<dial_string>
 * +EAPPROVE:<is_allowed>,<is_emergency>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8                       dial_num[MAX_CC_ATD_NUM_LEN];
} vdm_imsp_fdn_ecc_check_req_struct;

typedef struct 
{  
    LOCAL_PARA_HDR
    kal_bool                        is_allowed;
    kal_bool                        is_emergency;
    kal_uint16                      emergency_service_category;
} vdm_imsp_fdn_ecc_check_cnf_struct;


/******************************************************************************
 * +CIREPI: <nwimsvops>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                        is_imsvops_support;
} vdm_imsp_ims_vops_supp_ind_struct;


/******************************************************************************
 * +CIREPH: <srvcch>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    srvcc_status_enum               status;
} vdm_imsp_srvcc_status_update_ind_struct;


/******************************************************************************
 * +CNEMS1: <emb_S1_supp>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                        is_emb_s1_support;
} vdm_imsp_emb_s1_supp_ind_struct;


/******************************************************************************
 * +ECVMOD: <voice_mode>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    voice_mode_enum                 voice_mode;
} vdm_imsp_voice_mode_ind_struct;


/******************************************************************************
 * +ECEVDP: <eutran_vdp>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    l4_voice_domain_preference_enum eutran_vdp;
} vdm_imsp_eutran_vdp_ind_struct;


/******************************************************************************
 * +ECEMODE: <ue_mode>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    ue_mode_enum                    ue_mode;
} vdm_imsp_ue_mode_ind_struct;


/******************************************************************************
 * AT+ENWSEL=<search_type>,<rat>
 * +ENWSEL: <rat>,<emc_support>
 *  OK/ERROR
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    vdm_nw_selection_type_enum      search_type;
    rat_enum                        rat;
} vdm_imsp_nw_select_req_struct;

typedef struct 
{  
    LOCAL_PARA_HDR 
    rat_enum                        rat;
    kal_bool                        is_limited_service_emc_support;
    ims_result_code_enum            result;
    ims_err_id_enum                 err_id;
    plmn_id_struct                  plmn_id;
}vdm_imsp_nw_select_cnf_struct;

#ifdef __OP12_CDMA_LESS__
/******************************************************************************
 * AT+ENWSEL=2,<abort_cause>
 *  OK/ERROR
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    enwsel_search_abort_cause_enum cause;
} vdm_imsp_abort_nw_select_req_struct;
#endif

typedef vdm_imsp_common_at_cnf_struct vdm_imsp_abort_nw_select_cnf_struct;


/******************************************************************************
 * +ERAT: <rat>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    rat_enum                        rat;
} vdm_imsp_rat_mode_ind_struct;


/******************************************************************************
 * +EIRAT: <rat>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    vdm_irat_status_enum             irat_status;
    kal_bool                         irat_is_successful;
} vdm_imsp_inter_rat_status_ind_struct;


/******************************************************************************
 * +ENW: <is_searching>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                        is_searching;
} vdm_imsp_nw_search_status_ind_struct;


/******************************************************************************
 * +ECAMPON: <service_type>
 *****************************************************************************/
#if 1
typedef struct 
{  
    LOCAL_PARA_HDR 
} vdm_imsp_oos_start_ind_struct;

typedef struct 
{  
    LOCAL_PARA_HDR 
} vdm_imsp_oos_end_ind_struct;
#endif


/******************************************************************************
 * +EADS: <progress>,<domain>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    ads_indication_progress_enum    progress;
    ads_indication_domain_enum      domain;
} vdm_imsp_snd_ads_status_req_struct;

/******************************************************************************
 * +CREG/+CGREG/+CEREG: <stat>
 * (1) +CREG => is_for_ps_domain = KAL_FALSE
 * (2) +CGREG/+CEREG => is_for_ps_domain = KAL_TRUE 
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    nas_reg_status_enum             nas_reg_status; 
    kal_bool                        is_for_ps_domain;
    mm_cause_enum                   nas_reg_cause;
} vdm_imsp_nas_reg_status_ind_struct;


/******************************************************************************
 * +EIMSINFO: <rat>,<cell_id>,<cell_service>, <plmn_id>,<plmn_type>,
 *            <lac>,<tac>,<support_emc>,<lte_underly_cs_plmn_id>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    rat_enum                        rat;
    cell_service_enum               cell_service;
    kal_bool                        is_limited_service_emc_support;
    kal_uint32                      cell_id;
    plmn_id_struct                  plmn_id;
    domain_id_enum                  domain_id;
    plmn_id_struct                  lte_cs_plmn_id;//LTE underlying CS PLMN ID, only available for LTE combined attach UE
} vdm_imsp_cell_info_update_ind_struct;


/******************************************************************************
 * IMS Registration relayed by IMSP (source: IMC)
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    ims_reg_state_enum              reg_state;
    ims_reg_type_enum               reg_type;
    ims_access_rat_enum rat;
    ims_ecmp_enum ecmp;
    ims_reg_service_enum            reg_service;
#ifdef __OP12_CDMA_LESS__
    ims_reg_event_enum              reg_event;
    imcb_imc_sip_cause_enum         sip_cause;
#endif
} vdm_imsp_ims_reg_status_ind_struct;


/******************************************************************************
 * TODO
 *****************************************************************************/

typedef vdm_imc_ims_cc_list_current_calls_req_struct 
        vdm_imsp_cs_cc_list_current_calls_req_struct;


typedef vdm_imsp_cmd_list_current_calls_rsp_struct
        vdm_imsp_cs_cc_list_current_calls_cnf_struct;


/******************************************************************************
 * AT+CSSAC
 * +CSSAC:<bfvoice>,<bfvideo>,<btvoice>,<btvideo>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR
    kal_uint8 bfvoice;
    kal_uint8 bfvideo;
    kal_uint8 btvoice;
    kal_uint8 btvideo;
} vdm_imsp_get_ssac_param_cnf_struct;


/******************************************************************************
 * AT+ESRVCCTFR: <call_no>[,<call1_id>,<call1_mode>,<call1_direction>,<call1_state>,<call1_ecc_category>,
 * <call1_number type>,<call1_number>,<call1_alpha>,<call1_CLI validity>[,<call2_id>,<call2_mode>,<call2_direction>,
 * <call2_state>,<call2_ecc_category>,<call2_number type>,<call2_number>,<call2_alpha>,<call_2CLI validity> [,¡K]]] 
 *****************************************************************************/
 typedef struct
{
    kal_uint8                           call_id;      /* call_id_ims = call_id_ap */
    ims_srvcc_call_mode_enum            call_mode;
    ims_srvcc_call_direction_enum       call_direction;
    ims_srvcc_call_state_enum           call_state;
    ims_srvcc_call_ecc_category_enum    call_ecc_category;
    ims_srvcc_call_number_format_enum   call_number_format;
    kal_uint8                           call_number[MAX_CC_ATD_NUM_LEN];
} ims_srvcc_call_ctxt_to_cs_struct;

typedef struct
{    
    LOCAL_PARA_HDR    
    kal_uint32                          num_call;    
    ims_srvcc_call_ctxt_to_cs_struct	srvcc_call_ctxt_to_cs_domain[IMS_MAX_CALL_NUM];
} vdm_imsp_srvcc_context_transfer_req_struct;

/******************************************************************************
 * +ESRVCCTFR: <call_no>[,<call1_id>[,<call2_id>[,...]]]
 *****************************************************************************/
typedef struct 
{      
    LOCAL_PARA_HDR     
    kal_uint32                   num_of_call_instances;    
    kal_uint32                   call_id_table[IMS_MAX_CALL_NUM];
} vdm_imsp_srvcc_context_transfer_cnf_struct;

typedef struct 
{  
    LOCAL_PARA_HDR 
    // TODO 
} vdm_imsp_snd_ads_attempt_notification_req_struct;

typedef struct 
{  
    LOCAL_PARA_HDR 
    // TODO 
} vdm_imsp_snd_ads_end_notification_req_struct;


/******************************************************************************
 * +CRING: <type>
 * NOTE: <type> is string type but without ""
 *****************************************************************************/
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
#endif

/******************************************************************************
 * +ECONFSRVCC: <call_no>,<call1_id>[,<call2_id>[,<call3_id>[,...]]]
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32                   num_of_conf_parts;
    kal_uint32                   call_id_table[IMS_MAX_CALL_NUM];
} vdm_imsp_snd_srvcc_conf_call_id_req_struct;


/******************************************************************************
 * +EVADSREP: <domain>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    vdm_ads_result_enum     ads_result;
} vdm_imsp_snd_ads_result_report_req_struct;



/******************************************************************************
 * AT+EVVS=<vdm_voice_status>
 * This command is used to perform Gemini CS semaphore operations
 *****************************************************************************/
typedef struct 
{
    LOCAL_PARA_HDR
    vdm_voice_status_enum vdm_voice_status;
} vdm_imsp_vdm_voice_status_req_struct;

/******************************************************************************
 * IMS Handover (WIFI/LTE) status relayed by IMSP (source: IMC)
 *****************************************************************************/
typedef struct 
{ 
    LOCAL_PARA_HDR 
    ims_access_rat_enum             source_rat;
    ims_access_rat_enum             target_rat;
} vdm_imsp_ims_handover_start_ind_struct;

typedef struct 
{ 
    LOCAL_PARA_HDR 
    ims_access_rat_enum             source_rat;
    ims_access_rat_enum             target_rat;
    kal_bool                        result;
} vdm_imsp_ims_handover_end_ind_struct;
/******************************************************************************
 * AT+EIMSCI=<vdm_voice_over_ims_ongoing>,<is_emergency>
 * This command is used to update IMS information
 *****************************************************************************/
typedef struct 
{
    LOCAL_PARA_HDR
    kal_bool voice_over_ims_ongoing;
    kal_bool is_emergency;
    ims_access_rat_enum ims_access_rat;
} vdm_imsp_ims_call_info_req_struct;


/******************************************************************************
 * +ESTKCNUM: <call_number>, <call_type>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                    stk_call_num[MAX_CC_ATD_NUM_LEN];
    ims_call_type_enum           stk_call_type;
} vdm_imsp_stk_call_num_ind_struct;


/******************************************************************************
 * +EICE: <ims_call_exist>,<is_emergency>,<ims_access_rat>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32                  is_ims_call_exist;
    kal_bool                    is_emergency;
    ims_access_rat_enum         ims_access_rat;
} vdm_imsp_cmd_ims_call_exist_ind_struct;

/******************************************************************************
 * AT+EDCONF
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8               conf_call_participants;
    kal_uint8               conf_call_number_list[IMS_MAX_CALL_NUM_IN_CONF][MAX_CC_ATD_NUM_LEN];
    kal_bool                is_video_call;
} vdm_imsp_cmd_dial_conf_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_dial_conf_rsp_struct;

/******************************************************************************
 * +ECONFCHECK:<num_of_conf_call_members>,<is_allowed>[,<is_allowed>...
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                    conf_call_participants;
    kal_bool                     is_allowed[IMS_MAX_CALL_NUM_IN_CONF];
} vdm_imsp_snd_conf_check_result_req_struct;

/******************************************************************************
 * EVTA
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8                   call_id;
    ims_cc_evta_mode_enum       mode;
} vdm_imsp_cmd_mt_vt_special_accept_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_mt_vt_special_accept_rsp_struct;

/******************************************************************************
 * AT+EIMSCCP=<op> / AT+ECCP=<op>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    vdm_video_capability_enum   video_capability;
    kal_bool                    on_off;
} vdm_imsp_cmd_video_capability_ind_struct;

/******************************************************************************
 * +ERLQ:<Event>, <Band>
 * Event: 4G radio link monitor event type
 *   0 ¡V LTE weak signal
 *   1 ¡V LTE OOS searching
 * Band: current 4G band 
 *   0 ¡V Invalid band value (used for LTE OOS search)
 *   1-256: possible LTE band value range
 * only care about Event
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event_type;
} vdm_imsp_radio_link_quality_ind_struct;


/******************************************************************************
 * +ESVC:<emergency_service_category>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                   emergency_service_category;
} vdm_imsp_cmd_emerg_serv_cat_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_emerg_serv_cat_rsp_struct;

typedef vdm_imsp_cmd_emerg_serv_cat_ind_struct vdm_imsp_cs_cc_emerg_serv_cat_req_struct;
typedef vdm_imsp_common_at_cnf_struct vdm_imsp_cs_cc_emerg_serv_cat_cnf_struct;

/******************************************************************************
 * +ERPRAT: 9,<new_reported_rat>,<is_home>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    rat_enum               new_reported_rat;
    kal_bool               is_home;
} vdm_imsp_reported_rat_change_ind_struct;

/******************************************************************************
 * +EC2KREG: <domain>,<state>,<service>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    domain_id_enum               domain;
    kal_bool                     state;
    irat_ps_type_enum            service;
} vdm_imsp_c2k_service_state_ind_struct;

/******************************************************************************
 * +EC2KCI: <is_cs_conn_ongoing>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_cs_conn_ongoing;
} vdm_imsp_c2k_1x_conn_status_ind_struct;

/******************************************************************************
 * +EXXX: <reported_rat>
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                    reported_rat;
} vdm_imsp_reported_rat_ind_struct;

/******************************************************************************
 * AT+EHVOLTE=<mode>,<is_for_silent_redial>
 * This command is used to set hvolte mode
 *****************************************************************************/
typedef struct 
{
    LOCAL_PARA_HDR
    hvolte_mode_enum mode;
    kal_uint8 is_silent_redial;
} vdm_imsp_gmss_set_hvolte_mode_req_struct;

typedef vdm_imsp_common_at_cnf_struct vdm_imsp_gmss_set_hvolte_mode_cnf_struct;

/******************************************************************************
 * AT+EMCS=<mode>
 * This command is used to set emergency call session start and end
 *****************************************************************************/
typedef struct 
{
    LOCAL_PARA_HDR
} vdm_imsp_emc_session_start_ind_struct;

typedef struct 
{
    LOCAL_PARA_HDR
} vdm_imsp_emc_session_stop_ind_struct;

/******************************************************************************
 * AT+EMCB=<mode>
 * This command is used to set emergency callback mode
 *****************************************************************************/
typedef struct 
{
    LOCAL_PARA_HDR
} vdm_imsp_emcb_mode_start_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR
} vdm_imsp_emcb_mode_stop_req_struct;

/******************************************************************************
 * AT+VMEMEXIT
 * This command is used to exit emergency callback mode
 *****************************************************************************/
typedef struct 
{
    LOCAL_PARA_HDR
} vdm_imsp_cmd_exit_emcb_ind_struct;

/******************************************************************************
 * AT+ECCSCAN
 * This command is used to scan emergency service
 *****************************************************************************/
typedef struct 
{
    LOCAL_PARA_HDR
} vdm_imsp_emc_service_scan_req_struct;

typedef vdm_imsp_common_at_cnf_struct vdm_imsp_emc_service_scan_cnf_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    rat_enum        avaliable_rat;
    kal_uint8       cause;
} vdm_imsp_emc_service_ind_struct;

/******************************************************************************
 * AT+ECALLPULL
 * This command is used to dial with call pull
 *****************************************************************************/
 
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8               dial_uri[MAX_CC_CDU_URI_LEN];
    kal_bool                video_call;
} vdm_imsp_cmd_dial_call_pull_ind_struct;

typedef struct 
{  
    LOCAL_PARA_HDR 
    ims_result_code_enum            result;
    ims_err_id_enum                 err_id;
    kal_uint8                       call_id;
} vdm_imsp_cmd_dial_call_pull_rsp_struct;

/******************************************************************************
 * +EIMSPS: rat,type[,cause]
 * indication for silent redial event from AP to MD
 *****************************************************************************/
typedef struct 
{
    LOCAL_PARA_HDR
    rat_enum        rat;
    kal_uint8       type;// bitmask, 0x01 for Voice , 0x02 for SMS
    hvolte_mode_change_cause_enum cause;
} vdm_imsp_ims_domain_preference_ind_struct;


/******************************************************************************
 * +EACB:
 * indication for access barring information
 *****************************************************************************/
typedef struct 
{
    LOCAL_PARA_HDR
    /**/
    kal_uint8 bf_mo_data;
    kal_uint8 bt_mo_data;
    kal_uint8 special_ac_mo_data;
    kal_uint8 bf_mo_signalling;
    kal_bool is_acb_skip_for_mmtel_voice;
} vdm_imsp_access_barring_ind_struct;


/******************************************************************************
 * AT+EHVOLTE=0,1
 * indication for silent redial event from AP to MD
 *****************************************************************************/
typedef struct 
{
    LOCAL_PARA_HDR
} vdm_imsp_hvolte_silent_redial_ind_struct;

/******************************************************************************
 * AT+ECBM
 * This command is used to enter/exit emergency callback mode
 *****************************************************************************/
 
typedef struct
{
    LOCAL_PARA_HDR
    rat_enum                ecbm_rat_mode;
} vdm_imsp_ecbm_mode_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    rat_enum                ecbm_rat_mode;
} vdm_imsp_ecbm_mode_stop_req_struct;

/******************************************************************************
 * AT+CSCM=<application>,<start-end indication>
 * This command is used to start and stop for smart congestion mitigation
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    ims_scm_info_type_enum      application;
    ims_scm_info_action_enum    indication;

} vdm_imsp_ims_call_scm_req_struct;

/******************************************************************************
 * AT+EIMSRTT=<op>
 * Set rtt_capability through this AT command
 *****************************************************************************/
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8           operation;      
} vdm_imsp_cmd_rtt_capability_ind_struct;

typedef vdm_imsp_common_at_rsp_struct vdm_imsp_cmd_rtt_capability_rsp_struct;

/******************************************************************************
 * +ERDECCIND:<call_id>
 *****************************************************************************/
typedef struct 
{  
    LOCAL_PARA_HDR 
    kal_uint8               call_id;
} vdm_imsp_snd_ads_switch_to_emergency_req_struct;

#endif // _VDM_IMSP_STRUCT_H_

