/*****************************************************************************
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
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   gas_eas_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log:$
 *
 * 09 06 2017 abhinav.agarwal
 * [MOLY00271094] [CODE SYNC] [LR11 MP3][GAS] [Interface]New feature requirement: SRVCC fail????
 * .
 *
 * 08 12 2016 nalin.chovatia
 * [MOLY00190743] [6291][LTE BAND EXTENSION] Band 66 support - [PS] GAS-UAS/EAS interface
 * .
 *
 * 08 12 2016 mark.ng
 * [MOLY00190739] [6291][LTE BAND EXTENSION] Band 66 support - [PS] EAS-UAS/GAS interface
 * b66 support
 *
 * 02 26 2016 srihari.maddipati
 * [MOLY00162461] �bAndroid???Modem??Log���ݨD
 * .
 *
 * 02 23 2016 mark.ng
 * [MOLY00165947] [6291 HSR] Protocol Enhancement (Header/Interface)
 * [CEL] HSR AS interface
 *
 * 06 01 2015 henry.lai
 * [MOLY00092508] [MT6291][LTE-C2K] AS Inter RAT feature
 * .
 *
 * 05 26 2015 chun-fan.tsai
 * [MOLY00097098] [6291][CONN] Code Sync from MOLY to UMOLY
 * Sync MOLY00097502 to UMOLY (GAS-EAS interface)
 *
 * 05 15 2015 songsong.jia
 * [MOLY00084416] [eCSFB]LU Reduction feature
 * 	.
 *
 * 12 12 2014 yuhhwang.yu
 * [MOLY00087211] [CISE] add CSG fingerprint compile option and bug fix
 * . CISE codes
 *
 * 11 14 2014 henry.lai
 * [MOLY00079072] [MT6291] Change EARFCN from kal_uint16 to kal_uint32 for CEL part
 * 	.
 *
 * 11 11 2014 shin.chen
 * [MOLY00080357] [GAS] Extend earfcn to U32 for GAS
 * .
 *
 * 06 09 2014 aaron.liu
 * [MOLY00068770] [HZ]5.4.1 solution
 * EAS part:Add interface
 *
 * 06 05 2014 xiaochi.zhao
 * [MOLY00067770] [New SBP feature request] 4G background search - remove compile option __4G_BACKGROUND_SEARCH__
 * 	.
 *
 * 05 05 2014 xiaochi.zhao
 * [MOLY00064429] [MT6290LTE][CSFB][ERRC]New Feature : 2G4 Background Search
 * 	.
 *
 * 01 21 2014 wcpuser_integrator
 * [MOLY00054475] SGLTE option rename
 * .
 *
 * 12 31 2013 stanleyhy.chen
 * [MOLY00048478] [MT6290E1][LTG][GCF][CMW500][MM][Pre-Test][case 9.2.3.3.4][Band 38] Fail
 * Add a flag prohibit_apply_n_layer
 *
 * 11 13 2013 vend_simon.huang
 * [MOLY00046027] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * CEL OA part
 *
 * 07 24 2013 rujing.zhao
 * [MOLY00031020] [MMDS_DC] Merge MMDC interface to MOLY
 * .2->34G NBR transfer
 *
 * 07 23 2013 henry.lai
 * [MOLY00023935] [MT6290E1][W/G][Target IT] Meas result is received so frequently when priority measurement and drx measurement are on-going
 * .
 *
 * 03 14 2013 morton.lin
 * [MOLY00011957] [MT6290] Multimode IT CBr merge back to MOLY
 * Multimode IT CBr merge back to MOLY - stage 1
 *
 * 01 23 2013 henry.lai
 * [MOLY00009222] [GAS][Multi-Mode Development] Merge GAS multi-mode development to MOLY
 * .
 *
 * 01 11 2013 henry.lai
 * [Henry][Multi-Mode Development] GAS Development and R8 CR Sync
 *
 * Add copyright header.
 ****************************************************************************/

#ifndef _GAS_EAS_STRUCT_H
#define _GAS_EAS_STRUCT_H

#include "uas_gas_enums.h"
#include "gas_eas_enums.h"  
#include "kal_general_types.h"
#include "csi_umts_asn.h"     
#include "l3_inc_enums.h"     
#include "mcd_l3_inc_struct.h"
#include "csi_gsm_asn.h"      
#include "irat_common_struct.h"
#include "irat_common_enums.h"
#include "global_type.h"
#include "mrs_as_struct.h"
#include "gas_eas_inter_core_struct.h"


typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_change_trigger ir_cell_change_trigger;
  plmn_search_type_enum plmn_search_type;
  GSM_TargetCellInfo target_gcell_info;
}eas_gas_evaluate_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_reselection_status ir_cell_eval_status;
  ts_eval_activate_fail_handle eval_activate_fail_handle;
}eas_gas_evaluate_gcell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
}eas_gas_evaluate_gcell_stop_req_struct;

typedef struct {
  LOCAL_PARA_HDR
}eas_gas_evaluate_gcell_stop_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_change_trigger ir_cell_change_trigger;
  plmn_search_type_enum plmn_search_type;  
  GSM_TargetCell_Info_union target_gcell_info;
  GSM_TargetCell_SI_Info_union target_gcell_si_info;
  kal_uint32 cell_change_activation_time; /* milli-seconds, */   
  kal_uint32 cell_change_timeout; /* value in milli-seconds or zero when not required */
  kal_uint32  wait_time; /* milli-Seconds: 0~15000ms, GAS should not reselect back to UMTS/LTE within "wait_time" period */  
  kal_bool nc_mode_present; /* if TRUE nc_mode is present */
  kal_uint8  nc_mode; /* Optional, present if nc_mode_present is TRUE */
  ir_lte_scell_struct lte_scell_inf; /* cell info of the source LTE cell */
}eas_gas_activate_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_reselection_status ir_cell_activation_status; 
  ts_eval_activate_fail_handle eval_activate_fail_handle;
  te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason;  
}eas_gas_activate_gcell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_change_complete_status ir_cell_change_complete_status; 
  te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason;  
}eas_gas_gcell_change_complete_ind_struct;

typedef struct {
  LOCAL_PARA_HDR
  ts_ciphering_info ciphering_info;
  plmn_search_type_enum plmn_search_type;
  te_gsm_band_indicator band_indicator;
  kal_uint16         message_length;
}eas_gas_handover_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_handover_status ir_handover_to_gsm_status;
  te_ir_handover_cipher_algo ir_handover_to_gsm_cipher_algo;
  ho_from_lte_type_enum lte_ho_type;
#ifdef __SRVCC_CELL_INFO__
  kal_uint16 bcch_arfcn;
#endif
}eas_gas_handover_gcell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 t3212_timer_val;
  kal_bool att_flag;
  kal_uint32 wait_time;
  /* __ALPS02506878_SUPPORT__ */
  te_ir_call_type call_type;  
}eas_gas_ho_activate_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_handover_status ir_handover_to_gsm_status;
}eas_gas_ho_activate_gcell_cnf_struct;


typedef struct {
   LOCAL_PARA_HDR
   eas_target_cell_info   target_cell;
   plmn_search_type_enum  plmn_search_type;
/* __4G_BACKGROUND_SEARCH__ begin */
   /*2G4 background search parameter*/
   kal_bool is_background_search_trigger;
   gas_cell_info serving_cell_info;
/* __4G_BACKGROUND_SEARCH__ end */

} gas_eas_evaluate_ecell_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   te_ir_cell_reselection_status  eval_status;
   ts_eval_activate_fail_handle   eval_activate_fail_handle;
} gas_eas_evaluate_ecell_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
   te_ir_cell_change_trigger  trigger;
   kal_uint32             remain_wait_time;
   eas_target_cell_info   target_cell;
   kal_uint32             cell_change_timeout;   
   plmn_search_type_enum  plmn_search_type;
   kal_uint8              redirect_freq_num;
   lte_redirect_info      redirect_freq_info [MAX_GAS_EAS_REDIRECT_FREQ_NUM];
   kal_bool	is_gas_cell_inf_valid;
   mrs_gas_cell_inf_struct gas_cell_inf;
} gas_eas_activate_ecell_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   te_ir_cell_reselection_status  active_status;
   ts_eval_activate_fail_handle   eval_activate_fail_handle;
   te_ir_cell_change_fail_reason_enum  ir_cell_change_failed_reason;
} gas_eas_activate_ecell_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} gas_eas_evaluate_ecell_stop_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} gas_eas_evaluate_ecell_stop_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_change_complete_status cell_change_complete_status;
  te_ir_cell_change_fail_reason_enum cell_change_failed_reason;
}gas_eas_ecell_change_complete_ind_struct;


typedef struct{
    LOCAL_PARA_HDR
    plmn_search_type_enum plmn_search_type;
    auto_search_cmd_enum  auto_search_cmd;
    kal_uint8             num_freq;
    EARFCN                freq_list[MAX_NUM_CSG_FREQ];
} gas_eas_search_csg_ecell_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    search_status_enum search_status;    
    kal_uint8         num_csg_freq_search_result;
    csg_freq_search_result_struct csg_freq_search_result_list[MAX_NUM_CSG_FREQ];
} gas_eas_search_csg_ecell_cnf_struct;


typedef struct{
    LOCAL_PARA_HDR
    plmn_search_type_enum plmn_search_type;
    auto_search_cmd_enum  auto_search_cmd;   
    kal_uint8             num_freq;
    EARFCN                freq_list[MAX_NUM_CSG_FREQ];
} gas_eas_evaluate_csg_ecell_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    search_status_enum search_status;        
    kal_uint8         num_csg_freq_search_result;
    csg_freq_search_result_struct csg_freq_search_result_list[MAX_NUM_CSG_FREQ];
} gas_eas_evaluate_csg_ecell_cnf_struct;

/*4G2 CSG FINGERPRINT */
typedef struct {
    LOCAL_PARA_HDR
    plmn_id_struct    csg_plmn;
    kal_uint32        csg_id;
    kal_uint32        csg_cell_id;
    EARFCN            csg_frequency;
    kal_uint16        csg_physical_cell_id;
} eas_gas_build_fingerprint_req_struct;

typedef struct {
    LOCAL_PARA_HDR
} eas_gas_build_fingerprint_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
} eas_gas_abort_fingerprint_ind_struct;

/* LTE to GAS IR Measurement */
typedef struct
{
   LOCAL_PARA_HDR
} eas_gas_config_gcell_prio_meas_cnf_struct;

typedef struct
{
   LOCAL_PARA_HDR
} eas_gas_config_gcell_meas_cnf_struct;

/* GAS to LTE IR Measurement */
typedef struct
{
  LOCAL_PARA_HDR
  kal_uint8 tid;
  kal_bool hps_flag;
  kal_uint8 prio_meas_period;
  kal_uint8 freq_num;
  eas_meas_freq_info_struct freq[MAX_MEAS_IRAT_FREQ];
} gas_eas_lte_measurement_req_struct;

typedef struct {
  LOCAL_PARA_HDR
} gas_eas_lte_measurement_cnf_struct;

typedef struct
{
  LOCAL_PARA_HDR
  kal_uint8 freq_num;
  eas_hps_qualify_struct freq[MAX_MEAS_IRAT_FREQ];
  /* This flag is used to indicate whether measurement period should be reset
   * immediately. (TRUE:  meas is performed in the first DRX. 
   *               FALSE: meas is performed in the first T-meas occasion) 
   * In current design, the following rules should be followed.
   * (1)If freq_num != 0, this flag will be set as FALSE only if tmeasure measurement 
   *                      is triggered when priority measurement is on-going (i.e., at
   *                      least one of LTE cells hits priority reselection criteria for 
   *                      priority based measurement reselection). If any improvement is 
   *                      needed, the usage limitation for this flag should be confirmed 
   *                      with EL1's colleague.
   * (2) If freq_num == 0, this flag will alwyas be set as FALSE;
   */
  kal_bool is_meas_period_reset;
} gas_eas_lte_hps_qualify_cell_ind_struct;

typedef struct
{
  LOCAL_PARA_HDR
  kal_uint8 tid;
  kal_uint8 freq_num;
  eas_meas_freq_rslt_struct freq[MAX_MEAS_IRAT_FREQ];
#ifdef UNIT_TEST
  kal_uint32 meas_ind_ms_diff;
#endif /* UNIT_TEST */
} gas_eas_lte_measurement_ind_struct;

/* LTE to GAS CGI Collection */
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 tid;
  report_cgi_req_type_enum report_cgi_req_type;
  te_gsm_band_indicator gsm_band_indicator;
  kal_uint16 arfcn;
  kal_uint8 bsic;
} eas_gas_report_cgi_req_struct;

typedef struct {
    kal_bool is_rac_valid;
    kal_uint8 rac;
} gcell_cgi_info_optional_struct;

typedef struct {
    cgi_info_status_enum cgi_info_status;
    kal_uint16 arfcn;
    kal_uint8 bsic;
    kal_int16 rssi_in_quarter_dbm;
    kal_uint16 cell_id;
    plmn_id_struct plmn_id;
    kal_uint16 lac;
    gcell_cgi_info_optional_struct optional_field;
} gcell_cgi_info_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 tid;
  gcell_cgi_info_struct gcell_cgi_info;
} eas_gas_report_cgi_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  /* KAL_TRUE : ready timer timeout during 2G4 IR CCO procedure.
   * KAL_FALSE : 2G4 IR CCO procedure is rejected by NAS and
   *             ready timer timeout is not required to handle by
   *             EAS.
   */
  kal_bool is_handling_needed;
} gas_eas_ready_timer_status_ind_struct;

#ifdef __SGLTE__

#define MAX_NUM_OF_EARFCN    8

typedef struct {
    EARFCN earfcn;
    kal_uint8 bandwidth;
} eas_earfcn_info_struct;
	
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 earfcn_num;
    eas_earfcn_info_struct earfcn[MAX_NUM_OF_EARFCN];
} gas_eas_earfcn_list_update_req_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_band_39_coverage;
} eas_gas_coverage_update_ind_struct;

#endif /* __SGLTE__ */

/* __4G_BACKGROUND_SEARCH__ begin */
/*2G4 background search*/
typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} gas_eas_background_search_start_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} gas_eas_background_search_stop_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* LTE detected cell info */
   EARFCN             earfcn;
   kal_uint16         pci;   
} eas_gas_background_search_found_ind_struct;
/* __4G_BACKGROUND_SEARCH__ end */

/* HSR_SNIFF_SEARCH */
typedef struct {
   LOCAL_PARA_HDR
   /* LTE detected cell info */
   EARFCN             earfcn;
   kal_uint16         pci;   
} eas_gas_hsr_cell_found_ind_struct;
#endif /* _GAS_EAS_STRUCT_H */


