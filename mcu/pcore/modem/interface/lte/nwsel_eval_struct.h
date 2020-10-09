/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   nwsel_eval_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   message and common structure definition between NWSEL and EVAL module
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 05 21 2018 puneet.t
 * [MOLY00326318] [Gen91] TELCEL CC33 MM/NWSEL Interfaces changes
 * 	
 * 	TELCEL in GEN91 MM/NWSEL interface
 *
 * 11 03 2017 tsung-wei.tu
 * [MOLY00284359] [MT6755][TMO-US][N0+MP5][2017Q3][Simulation][Anritsu][IMS][L_IMS_VoLTE_43003_3]Fail at step2.
 * .
 *
 * 10 20 2017 tsung-wei.tu
 * [MOLY00284359] [MT6755][TMO-US][N0+MP5][2017Q3][Simulation][Anritsu][IMS][L_IMS_VoLTE_43003_3]Fail at step2.
 * .
 *
 * 02 24 2017 sherry.kuo
 * [MOLY00230786] [CDMA-less][MP5] Interface
 * .
 *
 * 12 09 2016 ivan.chung
 * [MOLY00216543] [LG+WG] runtime Duplex Change for CSFB TDS
 *
 * 12 09 2016 james-chi-ju.chang
 * [MOLY00216543] [LG+WG] runtime Duplex Change for CSFB TDS
 * .
 *
 * 07 29 2016 harry.chang
 * [MOLY00190308] [PH1 VZW_FIT][DAL][0706] Marginal VoLTE MO Fail
 * [MP5] Marginal VoLTE MO Fail
 *
 * 05 05 2016 james-chi-ju.chang
 * [MOLY00177972] VzW patch back MP3 IF
 * .
 *
 * 03 09 2016 james-chi-ju.chang
 * [MOLY00167983] [MT6755][Jade L6][MP2][CSFB DSDS][HSR][FDD][HSR][4G_Moving][Case Fail][LAT2]PLMN List time is lose to reference phone
 * .
 *
 * 01 07 2016 jerry-yh.chang
 * [MOLY00156360] R11 CSG on shared network
 * EVAL/NWSEL interface
 *
 * 12 31 2015 james-chi-ju.chang
 * [MOLY00155568] [WW FT][MT6797][Everest][M][MP2][France-Paris][Free][FTLA][LAT2] UE shows OOS momentarily after automatic STK SMS sent
 * .
 *
 * 10 28 2015 tim.huang
 * [MOLY00147169] [Rose]The CT card camp on 2G all time after switch data to CT card.
 * .
 *
 * 10 22 2015 james-chi-ju.chang
 * [MOLY00144447] Operator Feature/Requirement
 * .
 *
 * 10 19 2015 james-chi-ju.chang
 * [MOLY00145708] [Jade-L][SRLTE][CT OM 6M][LTE IOT][FT][SH][ALU][Random]?ºÝ¦b3G¤U¡A¥X?¤£¯à?¦æPS©MCS??
 * .
 *
 * 09 10 2015 yc.chen
 * [MOLY00141417] [Jade-L][SRLTE][LTE IOT][FT][SH][ZTE][random]±µ¦¬±m«H¦Z?«Ì EE,0,0,99,/data/core/,1,modem,md1
 * 	.
 *
 * 07 27 2015 kun-lin.wu
 * [MOLY00107136] [Denali-1] force success flag in C2L_TRANSFER_REQ
 *
 * 07 03 2015 tim.huang
 * [MOLY00125845] [JADE] SRLTE related design
 * .
 *
 * 06 18 2015 james-chi-ju.chang
 * [MOLY00122048] [6795] Request new feature to improve registration time of roaming case
 * 	.
 *
 * 05 29 2015 ye.yuan
 * [MOLY00116932] [UMOLY] [NAS]compile option modify
 * .
 *
 * 05 29 2015 kun-lin.wu
 * [MOLY00117190] PLMN List in CONNECTED Mode
 *
 * 04 23 2015 mark.chung
 * [MOLY00095378] Amazon Requirement
 * 	.
 *
 * 04 16 2015 james-chi-ju.chang
 * [MOLY00078264] [UMOLY][R10][R11] NAS check-in from CBr to 6291_DEV
 * 	.
 *
 * 04 16 2015 carlson.lin
 * [MOLY00091967] Merge C2K IRAT code
 * C2K merge (OA, NWSEL EVAL interface)
 *
 * 02 23 2015 bob.chiang
 * [MOLY00096607] Sync C2K CR
 * .
 *
 * 01 09 2015 kun-lin.wu
 * [MOLY00088493] CMCCï¿½ï¿½ï¿½wï¿½Vï¿½ï¿½ï¿½Ñ«Oï¿½@ï¿½uï¿½Æ¤ï¿½ï¿ *
 * 01 06 2015 james-chi-ju.chang
 * [MOLY00078264] [UMOLY][R10][R11] NAS check-in from CBr to 6291_DEV
 * .
 *
 * 12 17 2014 james-chi-ju.chang
 * [MOLY00078264] [UMOLY][R10][R11] NAS check-in from CBr to 6291_DEV
 * 	.
 *
 * 11 10 2014 robert.wu
 * [MOLY00083874] [UMOLY][R10][R11] EMM MTC sync code from 6291_DEV to UMOLY trunk
 *
 * 11 04 2014 james-chi-ju.chang
 * [MOLY00078264] [UMOLY][R10][R11] NAS check-in from CBr to 6291_DEV
 * .
 *
 * 10 07 2014 james-chi-ju.chang
 * [MOLY00077752] 4G3G2Gautoï¿½Ò¦ï¿½ï¿½Uï¿½ï¿½ï¿½ï¿½\ï¿½Ó¤j
 * .
 *
 * 09 19 2014 sherry.kuo
 * [MOLY00077433] [SoMC][K2][LTE] Clear Code #29/#33 feature check in
 * interface rename to is_esm_attempt_max_times.
 *
 * 08 28 2014 sherry.kuo
 * [MOLY00077433] [SoMC][K2][LTE] Clear Code #29/#33 feature check in
 * Clear Code 33
 *
 * 08 14 2014 jinghan.wang
 * [MOLY00075318] [4G Gemini][FT][CMCC Case][TDL FT][BJ][5.4.6][CMCC+CMCC] [K2 Alpha][Regression 1]pingï¿½ï¿½ï¿½qï¿½ï¿½pingï¿½q43.61s,ï¿½ï¿½É¬ï¿½_?ï¿½ï¿½ï¿½ï¿½Ficonï¿½ï¿½pingï¿½q27.92sï¿½Aï¿½ï¿½??ï¿½ï¿½ï¿½ï¿½ [FOCUS ISSUE]
 * 	Change full_band_search to full_band_searched_3g_status & full_band_searched_4g
 *
 * 07 07 2014 benjamin.kuo
 * [MOLY00071459] Add Mobility Management for IMS Voice Termination
 * MMIVT2MOLY
 *
 * 07 02 2014 shaowu.huang
 * [MOLY00070824] [4G Gemini][FT][BJ][CSFB test][case5.1.1][SIM1 CMCC+SIM2 CMCC][4G,3G,2G×¢ï¿½ï¿½Ê±ï¿½Ó¾ï¿½Ï³ï¿½]
 * .
 *
 * 06 19 2014 roy.lin
 * [MOLY00069512] ï¿½iCMCC Official ï¿½Ä¤@?ï¿½J? ï¿½jï¿½iZTE Q507Tï¿½jï¿½iï¿½ï¿½ï¿½nï¿½jï¿½i?1-Criticalï¿½jï¿½iï¿½Dï¿½Î¨Ò¡j??ï¿½ï¿½L-ï¿½Dï¿½Î¨ï¿½-ï¿½ï¿½?ï¿½ï¿½?"APN"?ï¿½Aï¿½I?ï¿½Ý±`
 * Update interface for PS detach without disable EUTRAN.
 *
 * 06 09 2014 tuan-che.chen
 * [MOLY00068767] [MT6290] Recovery to other RAT after 4G OOS speed up
 * add full_band_search
 *
 * 01 21 2014 wcpuser_integrator
 * [MOLY00054475] SGLTE option rename
 * .
 *
 * 01 14 2014 sherry.kuo
 * [MOLY00052313] [Customer requested feature] 4G factory mode arfcn
 * Merging from //MOLY_CBr/maruco.tu/MOLY_CBr.factory/mcu/modem/...
 *
 * 01 13 2014 james-chi-ju.chang
 * [MOLY00037567] [VOLTE] IMS NWSEL IT
 * Merging
 *  	
 * 	//MOLY_CBr/ben.chiu/MOLY_VOLTE.PHASE2.DEV/mcu/...
 *  	
 * 	to //MOLY/TRUNK/MOLY/mcu/...
 *
 * 08 19 2013 sherry.kuo
 * [MOLY00009250] [LTE Multimode] NWSEL check in
 * MT last PDN deactivation.
 *
 * 07 24 2013 benjamin.kuo
 * [MOLY00031020] [MMDS_DC] Merge MMDC interface to MOLY
 * .
 *
 * 07 24 2013 benjamin.kuo
 * [MOLY00031020] [MMDS_DC] Merge MMDC interface to MOLY
 * .
 *
 * 07 10 2013 shaowu.huang
 * NAS REJECT CAUSE interface, MM<->EMM,MM<->NWSEL,MM<->MM
 * 07 15 2013 sherry.kuo
 * [MOLY00029775] [MT6290E1][NAS RTD][MM][FDD] EMM_PLMNSEL_doesn't_report_sys_info
 * add search_type to search_status_update_req_struct
 *
 * 03 27 2013 benjamin.kuo
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * .
 *
 * 03 14 2013 tuan-che.chen
 * [MOLY00009163] LTE Multimode merge back to MOLY
 * merge back to MOLY.
 *
 * 02 04 2013 sherry.kuo
 * [MOLY00009250] [LTE Multimode] NWSEL check in
 * td-fdd lte separate nwsel interface.
 *
 * 01 22 2013 benjamin.kuo
 * [MOLY00009163] LTE Multimode merge back to MOLY
 *
 * 01 22 2013 benjamin.kuo
 * [MOLY00009163] LTE Multimode merge back to MOLY
 *
 * 01 22 2013 benjamin.kuo
 * [MOLY00009163] LTE Multimode merge back to MOLY
 * MOLY_CBr to MOLY.
 ****************************************************************************/


#ifndef  _NWSEL_EVAL_STRUCT_INC
#define  _NWSEL_EVAL_STRUCT_INC


#include "nwsel_eval_enums.h"
#include "l3_inc_local.h"
#include "ps_public_enum.h"
#include "l3_inc_enums.h"
#include "irat_common_enums.h"
#include "ims_common_def.h"
#include "c2k_irat_msg_struct.h"

/***** common structure definition *****/
typedef struct
{
    nas_proc_enum               emm_proc;
    lr_result_enum              lr_result;
    mm_cause_enum               lr_cause;
    esm_cause_enum              esm_cause; 
    kal_uint8                   attempt_counter;
    kal_bool                    is_esm_attempt_max_times;
    additional_update_result_enum   additional_update_result;
    eps_attach_update_result_enum   eps_attach_update_result;
    kal_bool                        is_ims_vops_support;
    lte_duplex_type_enum        lte_type;
//CR1917: REL12 feature, use REL11 temporarily
    /* is_eutran_not_allowed should be checked only when Reject#15. Disable E-UTRAN if #15 and this field is True. */
    kal_bool                    is_eutran_not_allowed; 
    kal_bool                    is_ps_reattach;
    kal_bool                    is_service_request_max_times; 
    kal_bool                    is_t3402_valid;
    kal_uint16                  t3402;
    /* use to identify the TA is change or not when TAU/Combined TAU */
    kal_bool                    is_mobility_tau;
//#ifdef __REL10__ // persistent EPSB
    kal_bool                    is_persistent_EPS_bearer_exist;
//#endif
    kal_bool                    is_emc_bs_support;
} proc_result_only_struct;

typedef struct
{
    kal_bool                        stored_lai_valid;
    kal_bool                        stored_guti_valid;
    gsm_state_enum                  gsm_attach_state;
    eps_state_enum                  lte_attach_state;
    gsm_update_status_enum          gsm_update_status;
    eps_update_status_enum          lte_update_status;
} update_param_struct;

/***** message structure definition *****/
typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   trx_id;
    plmn_search_type_enum       plmn_search_type;
    lte_duplex_type_enum        lte_type;
    kal_uint8                   plmn_id_count;
    plmn_id_struct              plmn_id[MAX_NUM_SEARCH_PLMN];
    kal_bool                    is_manual_sel;        // if search is manual selection
    kal_bool                    force_to_release;
    kal_bool                    is_manual_csg_sel;    // identify if the csg_id below is valid
    kal_uint32                  csg_id;
    kal_bool                    trigger_by_signal_appear;
    kal_bool                    is_higher_plmn_search;
    kal_uint32                  factory_mode_arfcn; //0xFFFFFFFF means invalid arfcn - do normal search. For fast camp on test machine
    kal_bool                    is_power_on; //for CMCC case 5.1.1: is first search after power on
    kal_bool                    is_mpsr_trigger;    //for VzW MPSR expired based improvement
    scan_type_enum              scan_type; 
    search_period_enum          search_period; // only a suggestion value for RAT switch.
    /**< Number of valid items in the KAL/MRU list. */
    kal_uint8                   num_items;
    /**< RAL/MRU list */
    cell_band_info_struct       ral_mru_list_info [SYS_MAX_MRU_LIST_NUM];
} nwsel_eval_plmn_search_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   trx_id;
    plmn_search_result_enum     result;
    kal_bool                    full_band_searched_4g;  // for NWSEL to decide if 2nd round PLMN search is necessary when PLMN is not found
    kal_bool                    is_eas_plmn_list_present;
    as_plmn_list_struct         eas_plmn_list;
    kal_uint8                   multi_plmn_count;
    plmn_id_struct              multi_selected_plmn[MAX_NUM_MULTI_PLMN];
    as_cell_type_enum           multi_selected_cell_type[MAX_NUM_MULTI_PLMN];
    scan_type_enum              scan_type;
    kal_bool                    is_stored_list_exist; // only for stored search not for fullband + fullband and stored
    fullband_result_enum        is_fullband_finished; 
} nwsel_eval_plmn_search_cnf_struct; 

typedef struct 
{ 
    LOCAL_PARA_HDR 
    kal_uint8                   multi_plmn_count; 
    plmn_id_struct              multi_plmn_id[MAX_NUM_MULTI_PLMN]; 
    as_cell_type_enum           multi_cell_type[MAX_NUM_MULTI_PLMN];
    /// source from cell reselection or search 
    found_ind_source_enum source;
} nwsel_eval_plmn_found_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    force_to_release;
    kal_bool                    deactivate_for_irat;
} nwsel_eval_deactivate_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_completed;

} nwsel_eval_deactivate_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_plmn_search_2G3G_ongoing;
    as_cell_type_enum           cell_type;               // 2G/3G camped on cell type
    plmn_search_type_enum       plmn_search_type; /* Only for EMM/PLMNSEL to know if needed to check Forbidden TA list */

} nwsel_eval_search_status_update_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_user_plmn_list_ongoing;
} nwsel_eval_plmn_list_status_update_req_struct;

//#ifdef __VOLTE_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    prefer_ims_emergency;
} nwsel_eval_search_preference_update_req_struct;
//#endif

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                  gibi_tag;
    kal_uint8                   ta_code[2];
    kal_uint8                   multi_plmn_count;
    plmn_id_struct              multi_plmn_id[MAX_NUM_MULTI_PLMN];
    as_cell_type_enum           multi_plmn_cell_type[MAX_NUM_MULTI_PLMN];
    csg_access_mode_enum        csg_access_mode[MAX_NUM_MULTI_PLMN];
    csg_info_struct             csg_info[MAX_NUM_MULTI_PLMN];
    lte_duplex_type_enum        lte_type;
//#if defined( __VOLTE_SUPPORT__) || defined (UNIT_TEST)
    kal_bool                    ims_emergency_support;
//#endif
    kal_bool                    is_c2k_as_irat;
    kal_uint8                   band;
    kal_bool                    is_3G_sib_scheduled;
    kal_bool                    is_2G_sib_scheduled;
    kal_bool                    is_C2K_sib_scheduled;
    enasas_ssac_ac_barringfactor_enum ssac_voice_ac_barring_factor;
} nwsel_eval_sys_info_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                  gibi_tag;
    plmn_id_struct              plmn_id;
    kal_uint8                   ta_code[2];
    as_cell_type_enum           cell_type;
    hplmn_status_enum           hplmn_status;
    fplmn_status_enum           fplmn_status;
    kal_bool                    is_in_eq_plmn_list;
    csg_access_mode_enum        csg_access_mode;
    csg_info_struct             csg_info;
//#if defined( __VOLTE_SUPPORT__) || defined (UNIT_TEST)
    kal_bool                    ims_emergency_support;
//#endif
    kal_uint8                   band;
} nwsel_eval_sys_info_update_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    event_type_enum             event_type_bitmask;
    update_eplmn_struct         eplmn_info;
    proc_result_only_struct     proc_result_only;
    update_param_struct         update_param;
#ifdef __SGLTE__    
    mmdc_peer_lr_result_struct  peer_lr_result;
#endif /* __SGLTE__ */

} nwsel_eval_regn_result_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    regn_proc_status_enum       mm_proc_status;         // indicate if MS is in limited or no service
    plmn_search_status_enum     plmn_search_status;
    plmn_search_type_enum       plmn_search_type;
    // sniff RPLMN 
    // only valid when the conditions hold 
    // plmn_search_status  == PLMN_SEARCH_UNRELATED
    // mm_proc_status == (MS_IN_NO_SERVICE || MS_IN_LIMITED_SERVICE)
    kal_uint8                   plmn_id_count;
    plmn_id_struct              plmn_id[MAX_NUM_SEARCH_PLMN];
} nwsel_eval_regn_status_update_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_manual_list;
    lte_duplex_type_enum        lte_type;
    kal_uint8                   plmn_id_count;
    plmn_id_struct              plmn_id[MAX_NUM_SEARCH_PLMN];
    scan_type_enum              scan_type;
    kal_bool                    is_mpsr_trigger;   //for VzW MPSR expired based improvement
} nwsel_eval_plmn_list_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    as_plmn_list_struct         eas_plmn_list;
    kal_bool                    full_band_searched_4g;
    scan_type_enum              scan_type;    
    plmn_list_result_enum       cause;    
} nwsel_eval_plmn_list_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    lte_duplex_type_enum        lte_type;
    kal_uint8                   plmn_count;
    plmn_id_struct              plmn_id[MAX_NUM_EQ_PLMN];  // include RPLMN

} nwsel_eval_csg_list_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    as_csg_list_struct          eas_csg_list;

} nwsel_eval_csg_list_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    domain_id_enum conn_domain;
} nwsel_eval_out_of_service_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    as_plmn_list_struct         eas_plmn_list;
    full_band_searched_enum     full_band_searched_3g_status;
    kal_bool                    full_band_searched_4g;
    plmn_loss_reason_enum       plmn_loss_reason;
} nwsel_eval_plmn_loss_ind_struct;

//#if defined( __VOLTE_SUPPORT__) || defined (UNIT_TEST)
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   emc_fplmn_count;
    plmn_id_struct              emc_fplmn_list[MAX_NUM_EMC_FPLMN];
    // band 0 => all band disabled, bar this PLMN
    kal_uint8                   emc_fplmn_band[MAX_NUM_EMC_FPLMN];
} nwsel_eval_emc_fplmn_list_update_req_struct;
//#endif

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   eq_plmn_count;
    plmn_id_struct              eq_plmn_id[MAX_NUM_EQ_PLMN];
    
} nwsel_eval_eq_plmn_list_update_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   plmn_id_count;
    plmn_id_struct              plmn_id[MAX_NUM_HPLMN];
    kal_uint8                   home_country_mcc[3];
} nwsel_eval_hplmn_info_update_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    voice_domain_preference_enum    eutran_voice_domain_preference;
    ue_mode_enum                    ue_mode;
    kal_bool                        sms_only;
    voice_domain_preference_enum    utran_voice_domain_preference;
} nwsel_eval_uemode_param_update_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16           t3402_value;   // t3402 value in seconds
} nwsel_eval_t3402_change_ind_struct;  // __REL10__: t3402

//#if defined( __VOLTE_SUPPORT__) || defined (UNIT_TEST)
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool        prefer_ims_emergency;
} nwsel_eval_plmn_search_preference_update_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool        in_ims_emergency;
} nwsel_eval_emergency_status_update_ind_struct;


//#endif // __VOLTE_SUPPORT__
#if defined(__LTE_RAT__) && (defined(__GSM_RAT__) || defined(__UMTS_RAT__))         

typedef errc_sim_protect_req_struct nwsel_eval_power_on_protection_req_struct;

#endif

typedef struct {
    LOCAL_PARA_HDR
    eutran_cap_enum eutran_cap;  //only use "EUTRAN_DISABLED", for EMM to know if need to reset CService and CExtService
} nwsel_eval_eutran_cap_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    plmn_based_timer_enum timer_type;
    timer_status_enum timer_status;
    plmn_id_struct target_plmn;
    plmn_restrict_additional_information_enum event;
} nwsel_eval_plmn_restriction_change_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    //kal_uint8                   req_id; //MD3 can only allow one 1XCSFB session
    c2k_lte_csfb_req_type_enum  csfb_req_type;
} nwsel_eval_c2k_csfb_start_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    //kal_uint8                   req_id; //MD3 can only allow one 1XCSFB session
    c2k_lte_csfb_result_enum    result;
}  nwsel_eval_c2k_csfb_est_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    c2k_lte_csfb_stop_req_type_enum    cause;
} nwsel_eval_c2k_csfb_stop_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool  is_ir_search;
    irat_type_enum irat_type;
} nwsel_eval_l2c_transfer_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    irat_type_enum irat_type; // new added, for AS triggered iRAT, need to forward IRAT_COMPLETE_REQ to EMM, for GMSS triggered iRAT, no need to forward. 
    c2k_irat_attach_result_enum result;
} nwsel_eval_c2k_irat_complete_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    c2k_irat_attach_result_enum  attach_result;
    kal_bool                     is_attach_req_sent;
    emm_cause_enum               emm_cause;
    esm_cause_enum               esm_cause;
} nwsel_eval_c2k_irat_attach_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool force_success;
} nwsel_eval_c2l_transfer_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    irat_result_enum irat_result;      // only IR_RESULT_SUCCESS and IR_RESULT_REJECT are valid
} nwsel_eval_c2l_transfer_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   plmn_id_count;
    plmn_id_struct              plmn_id[MAX_NUM_SEARCH_PLMN];
    gmss_rat_enum               c2k_ps_rat; /* C2K or HRPD */
} nwsel_eval_c2k_normal_service_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    no_action_cause_enum        cause;
} nwsel_eval_no_action_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_attach_needed; 
} nwsel_eval_irat_c2l_success_notify_ind_struct;

#ifdef __GEMINI_WCDMA_WORLD_PHONE__
// should be consistent to nwsel_mm_need_duplex_mode_chg_update_req_struct
typedef struct
{
    LOCAL_PARA_HDR
    rat_type_enum    target_rat;
    kal_uint8        freq_num;
    kal_uint32       redirect_freq[MAX_REDIRECT_FREQ_NUM];
    mt_csfb_type_enum   mt_csfb_type;
} nwsel_eval_need_duplex_mode_chg_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    mode_switch_cause_enum  cause;
} nwsel_eval_global_mode_change_start_req_struct;

#endif

#if 0 /* mark empty primitive message structure */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* mark empty primitive message structure */

typedef struct {
    LOCAL_PARA_HDR
    rat_enum               rat;   
    plmn_id_struct         plmn_id;
    kal_uint16             arfcn;
    kal_uint8              requested_band;
} nwsel_eval_set_mru_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    set_mru_result_enum result;  
} nwsel_eval_set_mru_cnf_struct;

/* VzW requirement for MRU/RAL, only band/channel */
typedef struct {
    LOCAL_PARA_HDR  
    cell_band_info_type_enum    type;
    plmn_id_struct         plmn_id;
    kal_uint8              band; 
} nwsel_eval_cell_band_info_update_ind_struct;


typedef struct {
    LOCAL_PARA_HDR
    emm_nwsel_event_enum event;  
} nwsel_eval_search_interrupt_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool  bEvdoEnterConnection;  /* TRUE, means EVDO has been in PS connection state; else, EVDO has been in idle state. */
} nwsel_eval_evdo_ps_connection_status_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool  b1xRttEnterConnection;  /* TRUE, means 1xRTT has been in PS connection state; else, 1xRTT has been in idle state. */
} nwsel_eval_1xrtt_ps_connection_status_ind_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    hvolte_mode_enum    source_hvolte_mode;            /** indicate original hvolte mode */ // enum defined in ims_common_def.h
    hvolte_mode_enum    target_hvolte_mode;            /** indicate source hvolte mode */ // enum defined in ims_common_def.h
} nwsel_eval_hvolte_mode_change_req_struct;

#endif   /* ----- #ifndef _NWSEL_EVAL_STRUCT_INC ----- */

