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
 *   l4c_eval_struct.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   message and common structure definition between L4C and EVAL module
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 11 22 2017 ashwitha.hegde
 * [MOLY00290646] 203604 ??????????1??4G??2??4G????2????????????
 * Porting to LR11 MP5: AT+EMRO
 *
 * 02 06 2017 chih-chien.lin
 * [MOLY00225609] [92->91 feature porting] SCM - interface
 * [SCM][ERRC CEL] add is_acb_skip_for_mmtel_voice in l4c_eval_ims_sys_info_ind_struct
 *
 * 12 13 2016 allen.hsu
 * [MOLY00217939] New Feature add AT+EPCASE version 2
 * 	
 * 	add +EPCASE ver2.
 *
 * 12 07 2016 yingfui.hung
 * [MOLY00215274] [VDM][ATT] ACB enable, select CS domain to dial up call. L4C part
 *
 * 11 15 2016 chih-chien.lin
 * [MOLY00213224] [Copr CR] [Porting to LR11] [K7] Request interfaces for implementation of skip-ACB. ERRC Interface
 * add barring for mo data
 *
 * 09 06 2016 shih-che.chou
 * [MOLY00193710] [6291][VOLTE enhancement]Enhancement A3 report (B/O/P) extend to more operator
 * .
 *
 * 08 30 2016 allen.hsu
 * [MOLY00200272] New Feature UL64QAM switcher
 * 	
 * 	add UL64QAM switch.
 *
 * 08 12 2016 mayur.vj
 * MOLY00191099 - B66 merging to MP5
 *
 * 05 09 2016 shih-che.chou
 * [MOLY00178266] [RAC header][PH1_VZW][joint-camp][Radio_Protocol][E911] TC2.19 RIL_UNSOL_VOLTE_EMERGENCY_CALL_FAIL_CAUSE
 * .
 *
 * 05 05 2016 kuan-wei.chen
 * [MOLY00177571] for MUSE patch back to LR11.MP3 - l4 header files
 * vzw patchback MP3 - .h
 *
 * 03 16 2016 bart.liang
 * [MOLY00169240] [PH1_VZW][Radio_Protocol][UNSOL] LTE NETWORK INFORMATION
 *
 * 03 08 2016 allen.hsu
 * [MOLY00167138] MT6755 max RSRP/SNR report to AP
 * 	
 * 	add the MAX RSRP/RSRQ/RS_SNR support for OPPO.
 *
 * 02 18 2016 allen.hsu
 * [MOLY00165236] [PH1_VZW][FLD][Radio_Protocol] VZ_REQ_LTEDATA_37821 Autonomous Gaps
 * add EGDM with AUTONOMOUS_GAP support
 *
 * 01 25 2016 yc.chen
 * [MOLY00146327] [VzW] hVoLTE implementation (non-LTE)
 *
 * 01 12 2016 allen.hsu
 * [MOLY00156079] [CA] Enable/Disable CA by AT+ECASW (L4)
 * 	
 * 	add LTE CA swtich support (AT+ECASW).
 *
 * 11 17 2015 yc.chen
 * [MOLY00149445] [UMOLY] Sync DoCoMo MOLY CR to related branch (MOLY00123677)
 *
 * 11 04 2015 hong.yu
 * [MOLY00147987] [MT6291]Autonomous DRX
 * [EVAL] patch MOLY00097750 to UMOLY
 *
 * 10 26 2015 allen.hsu
 * [MOLY00133440] [ERRC][RCM]Configurable CA combination
 * add LTE CA band settings support (+EPCASE).
 *
 * 10 12 2015 yingfui.hung
 * [MOLY00141134] [Copy CR][Porting to LR11][TMO][IMS] bCSFB - L4 ERLQ, ERLM changes (without switch)
 * 	.
 *
 * 10 08 2015 allen.hsu
 * [MOLY00133440] [ERRC][RCM]Configurable CA combination
 * add LTE CA band settings feature related interface.
 *
 * 10 02 2015 hong.yu
 * [MOLY00139482] [VzW] [VZ_REQ_LTEDATA_6800] Dynamic UE specific DRX setting
 * [VzW] UE specific DRX
 *
 * 07 16 2015 bart.liang
 * [MOLY00128924] [MT6291] [Low Power] Uplink Data Shaping MOLY code sync to UMOLY
 *
 * 07 06 2015 ralf.chen
 * [MOLY00125845] [JADE] SRLTE related design
 * 	Fix build error
 *
 * 07 03 2015 tim.huang
 * [MOLY00125845] [JADE] SRLTE related design
 * .
 *
 * 06 18 2015 panu.peisa
 * [MOLY00122487] EMM, ESM & PAM module VzW feature porting from 6290 to 6291
 * 	SWRD part, change have dependency to LTE_SEC parts.
 *
 * 06 16 2015 kuan-wei.chen
 * [MOLY00115378] SS code revise
 * merge from MOLY to UMOLY
 *
 * 06 16 2015 tim.huang
 * [MOLY00083439] [MUSE] IMS Development for requirment 1-15 - get the information of MO Data Barring and SSAC barring
 * .
 *
 * 06 15 2015 edwin.liu
 * [MOLY00091999] [VzW][Merge to MOLY] RSSNR and SIB16 local time
 * 	.
 *
 * 06 01 2015 henry.lai
 * [MOLY00092508] [MT6291][LTE-C2K] AS Inter RAT feature
 * .
 *
 * 05 06 2015 kuan-wei.chen
 * [MOLY00098019] [VzW][Merge to MOLY] MRU revise / MRU AT command
 * add AT+VZWMRUC, AT+VZWMRUE
 *
 * 04 16 2015 bart.liang
 * [MOLY00091967] Merge C2K IRAT code
 *
 * 04 13 2015 jaakko.sitomaniemi
 * L4 parts of operator specific requirement VZ_REQ_LTEDATA_6763.
 * 	Serving LTE Band  is now passed from AS to AP in a new URC +ESLBAND.
 * 	This is part 2/2 of the required L4 changes.
 *
 * 03 30 2015 jaakko.sitomaniemi
 * L4 & SBP parts of operator specific requirement VZ_REQ_LTEDATA_6763.
 * 	RS_SNR info is now passed from AS to AP for calculating signal strength indicator.
 * 	This is part 1/x of the required L4 changes.
 *
 * 01 23 2015 bart.liang
 * [MOLY00093004] [Y50] PS detach(cgatt=0) happens when performing manual network search.
 *
 * 11 28 2014 cooper.lin
 * [MOLY00068710] [MT6291_DEV] Sync MOLY to MT6291_DEV
 * Patch eDDA related interface
 *
 * 11 12 2014 carlson.lin
 * [MOLY00084165] [UMOLY][R10][R11] NAS check-in from 6291_DEV to UMOLY Trunk
 * (Sync from MT6291_DEV upto CL 869855)
 *
 * 04 29 2014 shih-chieh.liao
 * [MOLY00063952] [SGLTE] New reselection/OOS/background search mechanism using network Sys/Cell Informations from EAS/TAS/GAS
 * Merging
 *  	
 * 	//MOLY_CBr/danny.kuo/MOLY_LR9W1414B.MP4.W14.16.p1/mcu/modem/interface/lte/l4c_eval_struct.h
 *  	
 * 	to //MOLY/TRUNK/MOLY/mcu/modem/interface/lte/l4c_eval_struct.h
 *
 * 04 25 2014 tehuang.liu
 * [MOLY00063538] [6290E2][VoLTE][VDM] Support VoLTE Gemini architecture
 * not use compile options for VoLTE Gemini interface structures definition
 *
 * 04 23 2014 tehuang.liu
 * [MOLY00063538] [6290E2][VoLTE][VDM] Support VoLTE Gemini architecture
 * Check in VoLTE+Gemini related interfaces for VDM, IMSP, L4C, EVAL, and ERRC
 *
 * 01 21 2014 wcpuser_integrator
 * [MOLY00054475] SGLTE option rename
 * .
 *
 * 01 13 2014 benjamin.kuo
 * [MOLY00053421] Merge VoLTE Phase 2 back to MOLY trunk
 * VoLTE to MOLY
 *
 * 11 13 2013 xuejing.chen
 * [MOLY00046027] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * B39 capability change indication.
 *
 * 10 18 2013 shih-chieh.liao
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * integrate EAS_TO_PEER_INFO_IND.
 *
 * 08 23 2013 shih-chieh.liao
 * [MOLY00034931] [MMDC] change EAS_STATE_IND to TO_PEER_INFO_IND
 * .
 *
 * 08 02 2013 loter.chang
 * [MOLY00032186] [MMDS_DC] EMM MMDS_DC Feature Development and Enhancement
 * - modify L4C_EVAL_PS_SWITCH_CONTEXT_IND/REQ interface
 *
 * 07 24 2013 benjamin.kuo
 * [MOLY00031020] [MMDS_DC] Merge MMDC interface to MOLY
 * .
 *
 * 05 30 2013 carlson.lin
 * [MOLY00024438] [L4C][SM] add comments to rat_change interface
 * .
 *
 * 04 23 2013 stanleyhy.chen
 * [MOLY00010443] Code optimization
 * Send POWER_LEVEL_IND every 2.5s in connected mode
 *
 * 03 28 2013 stanleyhy.chen
 * [MOLY00010443] Code optimization
 * Implementation of EVAL_ERRC_CELL_POWER_LEVEL_IND
 *
 * 03 27 2013 benjamin.kuo
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * .
 *
 * 03 19 2013 benjamin.kuo
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * <saved by Perforce>
 *
 * 03 15 2013 benjamin.kuo
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * Temp solution.
 *
 * 03 15 2013 benjamin.kuo
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * MM IT merge back to MOLY.
 *
 * 03 14 2013 benjamin.kuo
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * common file: EVAL part.
 *
 * 02 05 2013 loter.chang
 * [MOLY00009163] LTE Multimode merge back to MOLY
 * revert interface
 *
 * 02 04 2013 loter.chang
 * [MOLY00009163] LTE Multimode merge back to MOLY
 * RATCHG Interface - duplex mode update
 *
 * 01 22 2013 roy.lin
 * [MOLY00009163] LTE Multimode merge back to MOLY
 * Multimode interface re-architecture.
 *
 * 11 07 2012 roy.lin
 * [MOLY00005322] TATAKA merge to MOLY
 * Add ESM related interface(msgid, struct, enum).
 ****************************************************************************/


#ifndef  L4C_EVAL_STRUCT_INC
#define  L4C_EVAL_STRUCT_INC

#include "l3_inc_local.h"
#include "irat_common_struct.h"
#include "nbr_public_struct.h"
#include "as2l4c_struct.h"
#include "l3_inc_enums.h"
#include "l4c_common_enum.h"

#ifdef __CDMA2000_RAT__
#include "c2k_irat_msg_struct.h"
#endif

//#ifdef __VOLTE_SUPPORT__
#include "ims_common_def.h"
//#endif /* __VOLTE_SUPPORT__ */

#include "ps_public_def.h"

/***** message structure definition *****/
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_etws_needed;
    kal_bool                    is_etws_testing_on;

} l4c_eval_etws_setting_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                  warning_type;
    kal_uint16                  message_id;
    kal_uint16                  serial_number;

} l4c_eval_etws_information_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    em_errc_state_enum  errc_state;
} l4c_eval_errc_state_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int16                  rsrp_in_qdbm;
    kal_int16                  rsrq_in_qdbm;
    kal_int16                  rs_snr_in_qdb;
    kal_uint16                 serv_lte_band;

    kal_int16                  rsrp_in_qdbm_opt;
    kal_int16                  rsrq_in_qdbm_opt;
    kal_int16                  rs_snr_in_qdb_opt;

#ifdef __SGLTE__ 
    target_module_enum         target_module;
    kal_uint32                 serv_EARFCN;
#endif /* __SGLTE__  */        

} l4c_eval_cell_power_level_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                        is_rest_command_present;
    rest_command_struct             rest_command;
    kal_bool                        is_monitor_mode_command_present;
    monitor_mode_command_struct     monitor_mode_command;
} l4c_eval_adjust_meas_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   result;
} l4c_eval_adjust_meas_cnf_struct;

typedef l4c_nbr_cell_info_reg_cnf_struct    l4c_eval_nbr_cell_info_start_cnf_struct;
typedef l4c_nbr_cell_info_ind_struct        l4c_eval_nbr_cell_info_ind_struct;

typedef struct 
{
    LOCAL_PARA_HDR    
    rat_type_enum               rat;
    kal_uint8                   num_earfcn;
#ifdef __BAND_EXTENSION_SUPPORT__
    EARFCN                  earfcn[MAX_NUMBER_OF_EARFCN];
#else
    kal_uint16                  earfcn[MAX_NUMBER_OF_EARFCN];
#endif
} l4c_eval_lte_neighbor_cell_info_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR    
    kal_bool                    is_drb_existent;
} l4c_eval_connected_drb_ind_struct;

//#ifdef __LTE_R11__
typedef enum {
    PPI_INVALID=0,
    PPI_NORMAL,
    PPI_LOWPOWER,
} ppi_status_enum;

// MSG_ID_L4C_EVAL_EDDA_REQ
typedef struct 
{
    LOCAL_PARA_HDR
    ppi_status_enum                 ppi_request;
} l4c_eval_edda_req_struct;
//#endif

#ifdef __SGLTE__ 
typedef l4cas_to_peer_info_ind_struct       l4c_eval_to_peer_info_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_band_39_supported;
}l4c_eval_capability_change_ind_struct;
#endif /* __SGLTE__  */

//#ifdef __VOLTE_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   barring_factor_voice;/*0~16*/
    kal_uint8                   barring_factor_video;/*0~16*/
    kal_uint8                   barring_time_voice;  /*0~8*/
    kal_uint8                   barring_time_video;  /*0~8*/    
} l4c_eval_get_ssac_param_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    srvcc_status_enum       status;
} l4c_eval_srvcc_status_update_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    vdm_voice_status_enum   vdm_voice_status;
} l4c_eval_vdm_voice_status_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 control_mode;
} l4c_eval_erlm_control_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool  is_mo_data_barred;
} l4c_eval_barring_status_ind_struct;

//#endif /* __VOLTE_SUPPORT__ */

typedef struct
{
    LOCAL_PARA_HDR
    sr_failure_cause_enum  failure_cause;
} l4c_eval_sr_failure_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    emm_cause_enum  reject_cause;
    kal_uint32  wait_time;
} l4c_eval_sr_reject_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8  reject_cause;
    kal_uint32  wait_time;
} l4c_eval_rach_reject_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    mru_cmd_type_enum cmd;
    kal_uint32 entry_index; //used only cmd=EDIT
    kal_uint8 band;         //used only cmd=EDIT
    plmn_id_struct plmn_id; //used only cmd=EDIT
} l4c_eval_mru_update_req_struct;

typedef struct
{
    kal_uint8 band;
    plmn_id_struct plmn_id;
} mru_update_result_struct;

#define MRU_UPDATE_RESULT_NUM_MAX 10

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 flag;
} l4c_eval_audrx_enable_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    mru_cmd_type_enum cmd;
    kal_bool result;                                           //TRUE=>pass, FALSE=>error
    kal_uint32 entry_num;                                      //used only when cmd=QUERY
    mru_update_result_struct entry[MRU_UPDATE_RESULT_NUM_MAX]; //used only when cmd=QUERY
} l4c_eval_mru_update_cnf_struct;

// for getting/setting LTE CA band
typedef struct
{
    //ver2
    kal_uint8       ver;
    kal_uint8       enable;                          // 0: disable; 1: enable
    kal_uint8       num_band;                        // refer to how many valid element in the inter_band array
    kal_uint8       band_index[LTECA_INTER_BAND_NUM_MAX];   // 0: inter band 1~32; 1: inter band 33~64; 2:inter band: 65~96
    kal_uint8       dl_bw_class[LTECA_INTER_BAND_NUM_MAX];
    kal_uint8       ul_bw_class[LTECA_INTER_BAND_NUM_MAX];
    kal_uint8       bw_combination_set;
    //ver1
    kal_uint8       num_inter_band;                         // refer to how many valid element in the inter_band array
    kal_uint32      inter_band[LTECA_INTER_BAND_NUM_MAX];   // 0: inter band 1~32; 1: inter band 33~64; 2:inter band: 65~96
    kal_uint32      intra_ncca_band;
    kal_uint32      intra_band_1_32;
    kal_uint32      intra_band_33_64;
} lteca_band_setting_struct;

typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    lteca_band_cmd_type_enum cmd;
    lteca_band_setting_struct lteca_band_setting;
} l4c_eval_lteca_band_setting_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    lteca_band_cmd_type_enum cmd;
    lteca_band_setting_struct lteca_band_setting;
    kal_bool result;
} l4c_eval_lteca_band_setting_cnf_struct;

// for getting/setting LTE CA mode
typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    lteca_mode_cmd_type_enum cmd;
    lteca_mode_enum lteca_mode_setting;
} l4c_eval_lteca_mode_setting_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    lteca_mode_cmd_type_enum cmd;
    lteca_mode_enum lteca_mode_setting;
    kal_bool result;
} l4c_eval_lteca_mode_setting_cnf_struct;

// To notify AS whether there is high quality service ongoing, usually used for game optimization, e.g. cancel background search (DRX)
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_hq_service_ongoing;
} l4c_eval_hq_service_status_req_struct;

// __TC01__
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_valid;                           
    kal_bool is_emc_attach_supported;
    kal_bool is_emc_call_barred;
    kal_uint32 cell_id;
    kal_uint8 ta_code[2];     
    kal_uint8 barring_factor_voice;/*0~16*/
    kal_uint8 barring_factor_video;/*0~16*/
    kal_uint8 barring_time_voice;  /*0~8*/
    kal_uint8 barring_time_video;  /*0~8*/    
    plmn_id_struct plmn_id;
    kal_uint8 band;
    kal_uint8 barring_factor_mo_data;/*0~16,16 means factor=1*/
    kal_uint8 barring_time_mo_data;  /*0~8, 0  means time=0*/
    kal_uint8 acbar_special_ac_mo_data;/*LSB 5 Bits =>AC11~AC15*/
    /*                bit8    bit7    bit6    bit5    bit4    bit3    bit2    bit1
    acbar special ac    0      0       0      AC11    AC12    AC13    AC14    AC15  
    */
    kal_uint8 barring_factor_mo_signalling;
    kal_bool is_acb_skip_for_mmtel_voice;
} l4c_eval_ims_sys_info_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event;
	kal_uint32 band;

} l4c_eval_erlm_report_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event;
	kal_uint32 band;

} l4c_eval_erlq_report_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32    rcv_tick;                        /* The time tick when SIB16 is received */
    kal_uint64    timeinfo_utc;                    /* 0~549755813887 */
    kal_bool      is_day_light_saving_time_valid;
    kal_uint8     day_light_saving_time;           /* 2 bits */
    kal_bool      is_leap_seconds_valid;
    kal_int16     leap_seconds;                    /* -127~128 */
    kal_bool      is_localtime_offset_valid;
    kal_int8      localtime_offset;                /* -63~64 */
} l4c_eval_time_info_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    omadm_cmd_type_enum cmd;
    omadm_node_type_enum node_type;     // OMADM node
    kal_uint32 node_value;
} l4c_eval_omadm_update_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    omadm_cmd_type_enum cmd;
    kal_bool result;                    // TRUE=>pass, FALSE=>error
    omadm_node_type_enum node_type;     // OMADM node
    kal_uint32 node_value;
} l4c_eval_omadm_update_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    lte_modulation_cmd_type_enum cmd;
    lte_modulation_mode_enum mode;
    signal_modulation_enum modulation;
    link_direction_enum link_direction;
} l4c_eval_modulation_update_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    lte_modulation_cmd_type_enum cmd;
    kal_bool result;
    lte_modulation_mode_enum mode;
    signal_modulation_enum modulation;
    link_direction_enum link_direction;
} l4c_eval_modulation_update_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16   ue_specific_drx_value;
} l4c_eval_drx_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool   is_drx_req_ok;
} l4c_eval_drx_update_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16   ue_specific_drx_value;
} l4c_eval_drx_update_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 pcell_earfcn;
    kal_uint16 pcell_band;
    kal_uint16 pcell_pci;
    kal_uint8  pcell_bw;
} l4c_eval_pcell_info_ind_struct;

#ifdef __CDMA2000_RAT__
typedef c2k_lte_csfb_req_struct l4c_eval_c2k_csfb_req_struct;
typedef c2k_lte_csfb_cnf_struct l4c_eval_c2k_csfb_cnf_struct;
typedef c2k_lte_csfb_stop_req_struct l4c_eval_c2k_csfb_stop_req_struct;
#endif

typedef struct 
{
    LOCAL_PARA_HDR
    emm_msg_type_enum       type;
    kal_bool                is_emergency;
} l4c_eval_emm_msg_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_voice_over_ims_ongoing;
} l4c_eval_ims_call_status_req_struct;

#endif   /* ----- #ifndef L4C_EVAL_STRUCT_INC ----- */

