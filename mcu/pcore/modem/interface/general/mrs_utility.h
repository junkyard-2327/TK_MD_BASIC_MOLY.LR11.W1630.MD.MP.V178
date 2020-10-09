/******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*******************************************************************************/

/******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   mrs_utility.h
 *
 * Project:
 * --------------------------------------------------------
 *   Multimode
 *
 * Description:
 * --------------------------------------------------------
 *   Declaration of funcitons of the utilities in MRS.
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * 07 23 2019 tanmoy.chatterjee
 * [MOLY00424144] ?SM03??MODEM???????????????????????????68%
 * .
 *
 * 04 19 2017 rujing.zhao
 * [MOLY00242898] [TDD GAS]RACH fail bar cell feature patch back LR11.MP5(.h file part)
 * .
 *
 * 04 25 2016 vend_mtb_aricent_05
 * [MOLY00167997] [MP2 Excluded][CTC][Anite??][SRLTE????][TC-FDD_SRLTE-03016_IPV4]???????
 * 	
 * 	.
 *
 * 02 25 2016 hannu.huusko
 * [MOLY00165019] [MT6755] Channel lock implementation to Jade MP3 for Nokia
 * [MRS] Channel lock
 *
 * 01 04 2016 titi.wu
 * [MOLY00155505] ??2G??????????follow ANT0,
 * .
 *
 * 12 10 2015 tim.huang
 * [MOLY00150157] VZ_REQ_LTEDATA_38498 (MT6291 Verizon Jun-2015 baseline)
 * .
 *
 * 09 23 2015 titi.wu
 * [MOLY00141786] [MT6755][SRLTE][L+C] Support connectivity of C2K on dual SIM
 * .
 *
 * 09 18 2015 ming.lee
 * [MOLY00140707] [GAS][PLMN search enhancement II] Search info reuse
 * .
 *
 * 07 14 2015 bruce.li
 * [MOLY00128246] [eCSFB]LU Reduction Enhancement
 * Implemented 2 enhancements: 
 * 1. If there is successful call on the black cell, add it to bleach list; 
 *    the priority order is: white list > bleach list > gray list > black list;
 * 2. If the decoded BSIC of white cell or bleach cell does not match the stored,
 *    add it to retry list; the retry list would be tried after white list and 
 *     bleach list have been done.
 *
 * 06 21 2015 alan.peng
 * [MOLY00122048] [6795] Request new feature to improve registration time of roaming case
 * _MRS part.
 *
 * 05 29 2015 shin.chen
 * [MOLY00115617] [6291] Dynamic SIM switch without modem reset
 * 	.
 *
 * 05 14 2015 henry.lai
 * [MOLY00113630] [MT6291] Add IS_TEST_SIM and IS_VSIM for l1core
 * .
 *
 * 04 20 2015 shin.chen
 * [MOLY00087882] [Universal Bin] MRS general developement
 * .Remove tabs
 *
 * 02 16 2015 doug.shih
 * [MOLY00091463] [MT6291] ERRC RCM/MRS development
 * MOLY CR Code Sync to UMOLY (OA domain): 
 * [MOLY00079131] AT&T requirement connection reject
 * [MOLY00083427] [ERRC][MOB] UMTS proximity indication
 * [MOLY00084324] [ROHC] Modem load with configurable compile options: profile support and context number
 * [MOLY00084416] [eCSFB]LU Reduction feature
 * [MOLY00091967] Merge C2K IRAT code (CT specific UE cap SBP setting).
 *
 * 01 20 2015 henry.lai
 * [MOLY00087668] [MT6291][UBIN] Check in ERRC/CEL modifications
 * 	.
 *
 * 12 15 2014 henry.lai
 * [MOLY00087668] [MT6291][UBIN] Check in ERRC/CEL modifications
 * .
 *
 * 11 17 2014 shin.chen
 * [MOLY00081154] [ATT_TMO_DEV] AT&T requirement merge back
 * .
 *
 * 11 14 2014 henry.lai
 * [MOLY00079072] [MT6291] Change EARFCN from kal_uint16 to kal_uint32 for CEL part
 * 	.
 *
 * 11 12 2014 cooper.lin
 * [MOLY00068710] [MT6291_DEV] Sync MOLY to MT6291_DEV
 * Merge MT6291_DEV code to UMOLY trunk.
 *
 * 11 12 2014 henry.lai
 * [MOLY00079071] [MT6291][U4G] Low Power Modification for CEL Paging
 * .
 *
 * 05 23 2014 adeline.chang
 * [MOLY00066214] [SBP] 4G background search
 * .
 *
 * 10 29 2013 adeline.chang
 * [MOLY00042471] [MT6290] CSFB_enhancements inject message extension
 * .
 *
 * 10 21 2013 adeline.chang
 * [MOLY00042471] [MT6290] CSFB_enhancements inject message extension
 * .
 *
 * 10 18 2013 peng.pan
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * MRS support MMDC.
 *
 * 08 30 2013 adeline.chang
 * [MOLY00030187] [MT6290] CSFB Enhancement Implementation for Autonomous Fast Return
 * [MT6290] CSFB Enhancement Implementation for Autonomous Fast Return - add new MRS API.
 *
 * 08 26 2013 adeline.chang
 * [MOLY00030187] [MT6290] CSFB Enhancement Implementation for Autonomous Fast Return
 * [MT6290] CSFB Enhancement Implementation for Autonomous Fast Return - add SIM index.
 *
 * 07 17 2013 adeline.chang
 * [MOLY00030187] [MT6290] CSFB Enhancement Implementation for Autonomous Fast Return
 * .
 *
 * 07 17 2013 adeline.chang
 * [MOLY00030187] [MT6290] CSFB Enhancement Implementation for Autonomous Fast Return
 * .
 *
 * 03 18 2013 justin.li
 * [MOLY00009222] [GAS][Multi-Mode Development] Merge GAS multi-mode development to MOLY
 * .
 *
 * 02 05 2013 yenchih.yang
 * [MOLY00009186] [SIBE/USIME/DBME] Multi-Mode CBr merge to MOLY
 * .
 *
 * 01 22 2013 david.niu
 * [MOLY00009205] [MRS] Code checked-in for MOLY branch
 * .
 *
 *****************************************************************************/

#ifndef _MRS_UTILITY_H
#define _MRS_UTILITY_H

#include "mrs_as_enums.h"
#include "mrs_as_struct.h"
#include "nvram_editor_data_item.h"
#include "kal_general_types.h"
#include "ps_em_enum.h"
#include "sim_common_enums.h"
#include "global_type.h"
#include "bitstream.h"
#ifdef __CHANNEL_LOCK__
#include "mrs_as_inter_core_enum.h"
#include "mrs_as_inter_core_def.h"
#include "mrs_as_inter_core_struct.h"
#endif /* __CHANNEL_LOCK__ */

/* GLOBAL VARIABLE DECLARATIONS *********************************************/
#ifdef UNIT_TEST
extern kal_bool modis_IT_mode;
#endif

/*  Type Definitions */

/* PUBLIC FUNCTION PROTOTYPES ***********************************************/
extern void mrs_send_msg(kal_uint32 dest_mod_id, sap_type sap_id, msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#if defined(__3G_CSG_SUPPORT__) || defined(__LTE_RAT__)
extern void NPSI_newAcsglFromUSIM(MRS_SIM_INDEX sim_index, kal_uint8 acsglRecNum, kal_uint16 acsglSizePerRec
                             , kal_uint8* acsglData, csg_white_list_update_cause update_cause, kal_bool is_valid);

extern void NPSI_newOcsglFromUSIM(MRS_SIM_INDEX sim_index, kal_uint8 ocsglRecNum, kal_uint16 ocsgalSizePerRec
                             , kal_uint8*   ocsglData, csg_white_list_update_cause update_cause, kal_bool is_valid);

extern white_list_update_type NPSI_updateCsgWhiteList(MRS_SIM_INDEX sim_index, 
                                               MRS_RAT_MODE_TYPE    rat, 
                                               csg_update_type_enum csg_update_type, 
                                               mrs_plmn_id*         plmn_id, 
                                               kal_uint32           csg_id);

extern kal_uint8* NPSI_getEncodedAllowedCsgList(MRS_SIM_INDEX   sim_index, 
                                         kal_uint8* recNum, 
                                         kal_uint16 *sizePerRec);

extern void NPSI_deleteCSGList(MRS_SIM_INDEX sim_index);

extern kal_uint8 NPSI_getValidCsgPlmn(MRS_SIM_INDEX     sim_index, 
                               mrs_plmn_id**    plmns);

extern csg_type_enum NPSI_checkCsgType(MRS_SIM_INDEX    sim_index, 
                                mrs_plmn_id *plmn_id, 
                                kal_uint32  csg_id);

kal_bool NPSI_isCsgListEmpty(MRS_SIM_INDEX sim_index);

kal_uint16 NPSI_checkCsgNumberPerPlmn(MRS_SIM_INDEX sim_index, mrs_plmn_id *plmn_id);

extern kal_bool mrs_write_next_csg_record_to_USIM(MRS_SIM_INDEX sim_index);

extern void mrs_write_ue_based_csg_to_nvram(MRS_SIM_INDEX sim_index);


extern kal_bool mrs_write_csg_to_USIM(MRS_SIM_INDEX sim_index);

extern void mrs_read_ue_based_nv(MRS_SIM_INDEX sim_index);

extern void mrs_csg_read_nvram_cnf_handler(kal_uint8* data, kal_uint16 len);


#endif /* #if defined(__CSG_SUPPORT__) || defined(__LTE_RAT__) */

extern kal_bool MRS_occupy_lla(MRS_SIM_INDEX    sim_index, 
                               MRS_RAT_MODE_TYPE    rat, 
                               MRS_OCCUPY_PROCEDURE procedure);

extern void MRS_release_lla(MRS_SIM_INDEX   sim_index, 
                     MRS_RAT_MODE_TYPE  rat);

extern kal_bool MRS_test_occupy_lla(MRS_SIM_INDEX sim_index, 
                                    MRS_OCCUPY_PROCEDURE procedure);

extern MRS_RAT_MODE_TYPE MRS_get_lla_occupy_rat(MRS_SIM_INDEX sim_index);

extern MRS_SIM_INDEX mrs_get_current_sim_index(void);

extern void mrs_afr_reset_afr_list(MRS_SIM_INDEX sim_index);

extern void mrs_afr_insert_freq(MRS_SIM_INDEX sim_index, EARFCN earfcn);

extern void mrs_afr_get_afr_list(MRS_SIM_INDEX sim_index, mrs_afr_main_struct *afr_list_ptr);

void mrs_set_csfb_enhancement_status(MRS_SIM_INDEX sim_index, csfb_enhancement_enum enhancement_item, kal_bool activate);

void mrs_set_csfb_enhancement_status_in_test_mode(MRS_SIM_INDEX sim_index, csfb_enhancement_enum enhancement_item, kal_bool activate);

kal_bool mrs_get_csfb_enhancement_status(MRS_SIM_INDEX sim_index, csfb_enhancement_enum enhancement_item);

extern void mrs_afr_set_csfb_status(MRS_SIM_INDEX sim_index, kal_bool csfb_ongoing);

extern kal_bool mrs_afr_get_csfb_status(MRS_SIM_INDEX sim_index);

extern void mrs_set_background_search_status_in_test_mode(MRS_SIM_INDEX sim_index, background_search_enum background_search_type, kal_bool activate);

extern kal_bool mrs_get_background_search_status(MRS_SIM_INDEX sim_index, background_search_enum background_search_type);

extern void mrs_ecsfb_add_2g_association(MRS_SIM_INDEX sim_index, kal_uint32 eas_cell_id, mrs_gas_cell_inf_struct *p_gas_cell_inf);

extern void mrs_ecsfb_set_2g_association_call_flag(MRS_SIM_INDEX sim_index, kal_uint32 eas_cell_id, mrs_gas_cell_inf_struct *p_gas_cell_inf);

extern kal_uint8 mrs_ecsfb_get_2g_lai(MRS_SIM_INDEX sim_index, kal_uint32 eas_cell_id, mrs_gas_cell_inf_struct *p_gas_cell_inf);

extern kal_uint8 mrs_ecsfb_get_same_lai_2g(MRS_SIM_INDEX sim_index, mrs_lai_struct *lai, kal_uint32 valid_duration, mrs_gas_cell_inf_struct *p_gas_cell);

extern void mrs_ecsfb_reset_association_info(MRS_SIM_INDEX sim_index);

extern void mrs_fast_roaming_set_mcc(MRS_SIM_INDEX sim_index, mrs_nas_mcc_struct *mrs_nas_mcc);

extern void mrs_fast_roaming_get_mcc(MRS_SIM_INDEX sim_index, mrs_as_mcc_struct *mrs_as_mcc_ptr);

/* Fast mode switch. */
extern void mrs_gas_fast_mode_switch_set_status(MRS_SIM_INDEX sim_index, mrs_gas_fast_mode_switch_status_enum status);
extern kal_bool mrs_gas_fast_mode_switch_check_allowed(MRS_SIM_INDEX sim_index, const kal_uint32 num_plmn, plmn_id_struct* plmn_id_ptr);
extern void mrs_gas_fast_mode_switch_set_plmn_id(MRS_SIM_INDEX sim_index, plmn_id_struct* plmn);
extern void mrs_gas_fast_mode_switch_set_arfcn(MRS_SIM_INDEX sim_index, kal_uint16 arfcn);
extern void mrs_gas_fast_mode_switch_set_bsic(MRS_SIM_INDEX sim_index, kal_uint8 bsic);
extern kal_uint16 mrs_gas_fast_mode_switch_get_arfcn(MRS_SIM_INDEX sim_index);
extern kal_uint8 mrs_gas_fast_mode_switch_get_bsic(MRS_SIM_INDEX sim_index);
extern kal_uint8 mrs_gas_fast_mode_switch_get_si_bitmap(MRS_SIM_INDEX sim_index);
extern kal_uint8* mrs_gas_fast_mode_switch_get_si_raw_data(MRS_SIM_INDEX sim_index, kal_uint8 si_type);
extern void mrs_gas_fast_mode_switch_store_essential_si(MRS_SIM_INDEX sim_index, bit_stream* bit_stream_ptr, kal_uint8 si_bitmap_pos);
extern void mrs_gas_fast_mode_switch_clean_stored_essential_si(MRS_SIM_INDEX sim_index, kal_uint8 si_bitmap_pos);
/* Fast mode switch. */

/* Support VzW: VZ_REQ_LTEDATA_38498 (MT6291 Verizon Jun-2015 baseline). */
extern void mrs_nas_set_roaming_status(MRS_SIM_INDEX sim_index, kal_bool is_roaming);
extern kal_bool mrs_nas_get_roaming_status(MRS_SIM_INDEX sim_index);
/* Support VzW: VZ_REQ_LTEDATA_38498 (MT6291 Verizon Jun-2015 baseline). */

//#ifdef __LTE_R11__
void mrs_ltea_son_set_reest_proc_status(MRS_SIM_INDEX sim_index, kal_bool lte_reest_ir_search);
void mrs_ltea_son_set_selected_cell(MRS_SIM_INDEX sim_index, kal_uint32 selected_arfcn, kal_uint16 selected_pci);
void mrs_ltea_son_reset_selected_cell(MRS_SIM_INDEX sim_index);
kal_bool mrs_ltea_son_get_selected_cell(MRS_SIM_INDEX sim_index, kal_uint32 *selected_arfcn_p, kal_uint16 *selected_pci_p);
//#endif

#ifndef __L1_STANDALONE__
void mrs_update_l1core_test_mode(kal_bool is_ps_conf_test_xta_mode, ps_conf_test_mode_enum ps_conf_test_mode, kal_uint32 ps_conf_test_profile_setting);
void mrs_update_l1core_SIM_type(sim_interface_enum which_sim, sim_type_query_enum sim_type);
void mrs_update_l1core_VSIM_info(sim_interface_enum which_sim, kal_bool is_vsim);

void mrs_update_l1core_MD_SIM_CONFIG_mode(kal_uint8 which_sim);
void mrs_reset_l1core_MD_SIM_CONFIG_mode();
void mrs_update_l1core_SIM_insert_status(sim_interface_enum which_sim, kal_bool is_sim_insert);

#ifdef __SGLTE__
void mrs_update_l1core_MMDC_mode(kal_bool isMMDC);
#endif /* __SGLTE__ */
#endif /* __L1_STANDALONE__ */

#ifdef __CHANNEL_LOCK__
/*******************************************************************************
Description:
    This function is used to write channel lock information to MRS.
        
Parameters:
    ch_lock_info: Pointer to channel lock information to be stored
    
Return Value: None    
*******************************************************************************/
void mrs_ch_lock_info_set(const mrs_ch_lock_info_struct* p_ch_lock_info);
#endif /* __CHANNEL_LOCK__ */

#ifdef __CHANNEL_LOCK__
/*******************************************************************************
Description:
    This function is used to read channel lock information from MRS.
        
Parameters:
    ch_lock_info: Pointer to where channel lock information shall be copied
    
Return Value: None    
*******************************************************************************/
void mrs_ch_lock_info_get(mrs_ch_lock_info_struct* p_ch_lock_info);
#endif /* __CHANNEL_LOCK__ */

#ifdef __CHANNEL_LOCK__
/*******************************************************************************
Description:
    This function is used to read channel lock state from MRS.
        
Parameters: None
    
Return Value: Channel lock state    
*******************************************************************************/
MRS_CH_LOCK_STATE mrs_ch_lock_state_get(void);
#endif /* __CHANNEL_LOCK__ */

kal_uint8 mrs_query_ps_c2k_sim_config();

#if defined(__GAS_STORED_SI_FEAT__)
void mrs_gas_update_gsm_storedSI_list(MRS_SIM_INDEX sim_index, rrm_gsm_storedSI_struct *gas_candidate_list);
void mrs_gas_read_gsm_storedSI_list(MRS_SIM_INDEX sim_index, rrm_gsm_storedSI_struct *gas_candidate_list);
#endif 

#endif /* _MRS_UTILITY_H */
