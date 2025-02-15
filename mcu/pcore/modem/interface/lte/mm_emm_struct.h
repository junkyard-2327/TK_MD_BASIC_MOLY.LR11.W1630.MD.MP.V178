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
 *   mm_emm_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   message and common structure definition between MM and EMM module
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 05 22 2019 jerry-yh.chang
 * [MOLY00407787] [Interface][MM/EMM][CTS][CANADA][TELUS][VoLTE] Device is sending Extended Service Request while performing VoLTE Emergency call without IMS Registration SIM in VoLTE TAC. - 911 failed
 * .
 *
 * 07 07 2017 ivan.chung
 * [MOLY00262660] [VzW CDMA-less][Pre-IT] 2.3.26.2 EMM 10 Error string: ## BASE ## Ping resulted in failure, still continue the scenario.. !!
 *  - interface
 *
 * 12 31 2015 ivan.chung
 * [MOLY00155565] [MT6755][VzW] Replace __SS_TIME_READY__ to __SUPPORT_CLIB_TIME__
 *
 * 08 25 2015 kinki.lin
 * . (non-secure domain) merge MOLY00119733
 *
 * 11 10 2014 robert.wu
 * [MOLY00083874] [UMOLY][R10][R11] EMM MTC sync code from 6291_DEV to UMOLY trunk
 *
 * 07 07 2014 lt.chang
 * [MOLY00071459] Add Mobility Management for IMS Voice Termination
 * . emm interface & mm to emm struct
 *
 * 04 21 2014 raymond.chen
 * [MOLY00062966] [SGLTE] Modify the usage of mm_emm_peer_lr_result_ind message to avoid possible R+E PLMN list unsync between MD1 and MD2
 * Fix the build error due to typo
 *
 * 04 21 2014 raymond.chen
 * [MOLY00062966] [SGLTE] Modify the usage of mm_emm_peer_lr_result_ind message to avoid possible R+E PLMN list unsync between MD1 and MD2
 * Separate the eplmn update usage of mm_emm_peer_lr_result_ind_struct (From EMM to 2G) from procedure update.
 *
 * 10 18 2013 raymond.chen
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * Correct type of peer_lr_result and ref_count/msg_len for mm_emm_peer_lr_result_req/ind_struct.
 *
 * 09 04 2013 loter.chang
 * [MOLY00035044] [EMM] RATCHG, SEC, CMNPROC Enhancement and Trace Modification
 * - Add tin value into initial NAS context transfer
 *
 * 07 24 2013 shaowu.huang
 * [MOLY00031020] [MMDS_DC] Merge MMDC interface to MOLY
 * NAS REJECT CAUSE interface, MM<->EMM,MM<->NWSEL,MM<->MM.
 *
 * 05 22 2013 loter.chang
 * [MOLY00021705] [EMM][Design Change] Revision and Enhancement
 * add UE mode to EMM/MM interface
 *
 * 03 25 2013 loter.chang
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * add TMSI to mm_emm_init_nas_ctxt_rsp_struct
 *
 ****************************************************************************/


#ifndef  MM_EMM_STRUCT_INC
#define  MM_EMM_STRUCT_INC

#include "l3_inc_local.h"
#include "l3_inc_enums.h"
#include "irat_common_struct.h"

/***** message structure definition *****/
// MSG_ID_MM_EMM_INIT_NAS_CTXT_IND
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_mapped_ptmsi_present;
    kal_uint8                   mapped_ptmsi[PTMSI_LEN];
    kal_bool                    is_mapped_ptmsi_sig_present;
    kal_uint8                   mapped_ptmsi_sig[PTMSI_SIG_LEN];
    kal_bool                    is_mapped_rai_present;
    rai_struct                  mapped_rai;
    tin_enum                    tin;
}mm_emm_init_nas_ctxt_ind_struct;

// MSG_ID_MM_EMM_INIT_NAS_CTXT_RSP
typedef struct
{
    LOCAL_PARA_HDR
    mm_emm_tmsi_status_enum     is_tmsi_valid;
    kal_uint8                   tmsi[TMSI_LEN];
    kal_bool                    is_ptmsi_valid;
    kal_uint8                   ptmsi[PTMSI_LEN];
    kal_bool                    is_ptmsi_sig_valid;
    kal_uint8                   ptmsi_sig[PTMSI_SIG_LEN];
    kal_bool                    is_rai_valid;
    rai_struct                  rai;
    kal_bool                    is_mm_update_status_valid;
    gsm_update_status_enum      mm_update_status;
    kal_bool                    is_lai_valid;
    lai_struct                  lai;
}mm_emm_init_nas_ctxt_rsp_struct;

// MSG_ID_MM_EMM_ISR_UPDATE_REQ
typedef struct
{
    LOCAL_PARA_HDR
    mm_emm_isr_event_enum   event_trigger;
    kal_bool                tin_present;
    tin_enum                tin;
}mm_emm_isr_update_req_struct;

// MSG_ID_MM_EMM_ISR_UPDATE_IND
typedef struct
{
    LOCAL_PARA_HDR
    mm_emm_isr_event_enum   event_trigger;
    kal_bool                tin_present;
    tin_enum                tin;
}mm_emm_isr_update_ind_struct;

// MSG_ID_MM_EMM_GMM_UPDATE_REGISTRATION_REQ
typedef struct
{
    LOCAL_PARA_HDR
    gmm_msg_type_enum       gmm_msg_type;
    kal_bool                is_gmm_attach_type_present;
    gmm_attach_type_enum    gmm_attach_type;
    kal_bool                is_gmm_update_type_present;
    gmm_update_type_enum    gmm_update_type;
    kal_bool                is_gmm_attach_result_present;
    gmm_attach_result_enum  gmm_attach_result;
    kal_bool                is_gmm_update_result_present;
    gmm_update_result_enum  gmm_update_result;
    kal_bool                is_gmm_cause_present;
    gmm_cause_enum          gmm_cause;
    kal_bool                is_gmm_attempt_cnt_present;
    kal_uint8               gmm_attempt_cnt;
    kal_bool                is_rai_changed;
    kal_bool                is_gu1_updated;
    kal_bool                is_lai_changed;
    kal_bool                is_u1_updated;
    kal_bool                is_ims_voice_over_ps_ind_present;
    ug_ims_ind_enum         ims_voice_over_ps_ind;
}mm_emm_gmm_update_registration_req_struct;

// MSG_ID_MM_EMM_GMM_UPDATE_DEREGISTRATION_REQ
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                is_gmm_msg_type_present;
    gmm_msg_type_enum       gmm_msg_type;
    kal_bool                is_gmm_proc_direction_present;
    gmm_proc_direction_enum gmm_proc_direction;
    kal_bool                is_gmm_attach_type_present;
    gmm_attach_type_enum    gmm_attach_type;
    kal_bool                is_gmm_update_type_present;
    gmm_update_type_enum    gmm_update_type;
    kal_bool                is_gmm_detach_type_present;
    gmm_detach_type_enum    gmm_detach_type;    
    kal_bool                is_gmm_attach_result_present;
    gmm_attach_result_enum  gmm_attach_result;
    kal_bool                is_gmm_cause_present;
    gmm_cause_enum          gmm_cause;
    kal_bool                is_gmm_mt_cause_present;
    mm_emm_mt_cause_enum    gmm_mt_cause;
    kal_bool                is_gmm_attempt_cnt_present;
    kal_uint8               gmm_attempt_cnt;
    kal_bool                is_rai_changed;
    kal_bool                is_gu1_updated;
    kal_bool                is_lai_changed;
    kal_bool                is_u1_updated;
    kal_bool                is_ps_detach_pending;
}mm_emm_gmm_update_deregistration_req_struct;


// MSG_ID_MM_EMM_MM_UPDATE_REGISTRATION_REQ
typedef struct
{
    LOCAL_PARA_HDR
    mm_msg_type_enum    mm_msg_type;

}mm_emm_mm_update_registration_req_struct;

// MSG_ID_MM_EMM_MM_UPDATE_DEREGISTRATION_REQ
typedef struct
{
    LOCAL_PARA_HDR
    mm_msg_type_enum    mm_msg_type;
    kal_bool            is_mm_rej_cause_present;
    mm_rej_cause_enum   mm_rej_cause;
    kal_bool            is_mm_attempt_cnt_present;
    kal_uint8           mm_attempt_cnt;
    kal_bool            is_lai_changed;
    kal_bool            is_u1_updated;
}mm_emm_mm_update_deregistration_req_struct;

// MSG_ID_MM_EMM_EMM_UPDATE_REGISTRATION_IND
typedef struct
{
    LOCAL_PARA_HDR
    emm_msg_type_enum       emm_msg_type;
    kal_bool                is_emm_attach_type_present;
    emm_attach_type_enum    emm_attach_type;
    kal_bool                is_emm_update_type_present;
    emm_update_type_enum    emm_update_type;
    kal_bool                is_emm_attach_result_present;
    emm_attach_result_enum  emm_attach_result;
    kal_bool                is_emm_update_result_present;
    emm_update_result_enum  emm_update_result;
    kal_bool                is_emm_cause_present;
    emm_cause_enum          emm_cause;
    kal_bool                is_emm_attempt_cnt_present;
    kal_uint8               emm_attempt_cnt;
    kal_bool                is_emm_sr_type_present;
    emm_sr_type_enum        emm_sr_type;
    kal_bool                is_tai_changed;
    kal_bool                is_eu1_updated;
    kal_bool                is_lai_valid;
    lai_struct              lai;
    kal_bool                is_ms_id_valid;
    kal_uint8               ms_id_len;
    kal_uint8               ms_id[MS_ID_LEN];
    ue_mode_enum            ue_mode;
    kal_bool                is_ims_voice_over_ps_ind_present;
    ims_ind_enum            ims_voice_over_ps_ind;
}mm_emm_emm_update_registration_ind_struct;

// MSG_ID_MM_EMM_EMM_UPDATE_DEREGISTRATION_IND
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                is_emm_msg_type_present;
    emm_msg_type_enum       emm_msg_type;
    kal_bool                is_emm_proc_dir_present;
    gmm_proc_direction_enum emm_proc_dir;
    kal_bool                is_emm_attach_type_present;
    emm_attach_type_enum    emm_attach_type;
    kal_bool                is_emm_update_type_present;
    emm_update_type_enum    emm_update_type;
    kal_bool                is_emm_detach_type_present;
    emm_detach_type_enum    emm_detach_type;
    kal_bool                is_emm_attach_result_present;
    emm_attach_result_enum  emm_attach_result;
    kal_bool                is_emm_cause_present;
    emm_cause_enum          emm_cause;
    kal_bool                is_emm_mt_cause_present;
    mm_emm_mt_cause_enum    emm_mt_cause;    
    kal_bool                is_emm_attempt_cnt_present;
    kal_uint8               emm_attempt_cnt;
    kal_bool                is_emm_sr_type_present;
    emm_sr_type_enum        emm_sr_type;
    kal_bool                is_tai_changed;
    kal_bool                is_eu1_updated;
    ue_mode_enum            ue_mode;    
    kal_bool                is_ps_detach_pending;
}mm_emm_emm_update_deregistration_ind_struct;

// MSG_ID_MM_EMM_CSFB_REQ
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   req_id;
    mm_emm_csfb_req_type_enum   csfb_req_type;
}mm_emm_csfb_req_struct;

// MSG_ID_MM_EMM_CSFB_CNF
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   req_id;
}mm_emm_csfb_stop_req_struct;

// MSG_ID_MM_EMM_CSFB_STOP_REQ
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   req_id;
    mm_emm_csfb_result_enum     result;
    kal_bool                    is_skip_force23G;
}mm_emm_csfb_cnf_struct;

// MSG_ID_MM_EMM_CSFB_PAGE_IND
typedef struct {
    LOCAL_PARA_HDR
    mm_emm_csfb_paging_id_enum  csfb_paging_id;         //Paging identity used in CS SERVICE NOTIFICATION
    kal_bool                    is_cli_present;         //Whether CLI (Calling Line Identification) IE exists or not
    kal_uint8                   cli_len;                //Length of CLI
    kal_uint8                   cli[12];                //CLI value Refer to TS 24.008 subclause 10.5.4.9  Calling party BCD number for decoding.
    kal_bool                    is_ss_code_present;     //Whether SS code IE exists or not
    kal_uint8                   ss_code;                //SS code value Refer to TS 29.002 subclause 17.7.5 for decoding.
    kal_bool                    is_lcs_ind_present;     //Whether LCS indicator IE exists or not
    kal_uint8                   lcs_indicatior;         //LCS indicator value; 0x01: MT-LR, Other values: Normal, unspecified in this version of the protocol
    kal_bool                    is_lcs_client_id_present;   //Whether LCS client identity IE exists or not
    kal_uint8                   lcs_client_id_len;      //Length of LCS client identity
    kal_uint8                   lcs_client_id[255];     //LCS client identity value, Refer to TS 29.002 subclause 17.7.13 for decoding.
}mm_emm_csfb_page_ind_struct;

// MSG_ID_MM_EMM_CSFB_PAGE_RSP
typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_accept_paging;   //Whether upper layer decides to answer the mobile terminating CS service
}mm_emm_csfb_page_rsp_struct;


//MSG_ID_MM_EMM_TIMER_STATUS_IND
typedef struct {
    LOCAL_PARA_HDR
    mm_emm_common_timer_id_enum mm_emm_common_timer_id;
    kal_bool status;  // 0:stop, 1:start
    plmn_id_struct backoff_timer_plmn;
    kal_bool is_backoff_timer_plmn_in_eq_plmn_list;
#ifdef __SUPPORT_CLIB_TIME__
    kal_int64 expire_time;
#else
    kal_uint16 remaining_time;
#endif
}mm_emm_timer_status_ind_struct;  // __REL10__: t3346

//MSG_ID_MM_EMM_TIMER_STATUS_REQ
typedef struct {
    LOCAL_PARA_HDR
    mm_emm_common_timer_id_enum mm_emm_common_timer_id;
    kal_bool status;  // 0:stop, 1:start
    plmn_id_struct backoff_timer_plmn;
    kal_bool is_backoff_timer_plmn_in_eq_plmn_list;
#ifdef __SUPPORT_CLIB_TIME__
    kal_int64 expire_time;
#else
    kal_uint16 remaining_time;
#endif
}mm_emm_timer_status_req_struct;  // __REL10__: t3346

#if defined (__SGLTE__)
/*EMM->MM*/
typedef struct {
    LOCAL_PARA_HDR
    lr_result_enum peer_lr_result;
    nas_proc_enum peer_lr_procedure;
    emm_cause_enum  emm_peer_reject_cause;
    plmn_id_struct emm_peer_plmn_id;
    kal_bool is_update_eq_plmn_only; /* If set TRUE, only R+E PLMN info are valid. */
    kal_uint8 eq_plmn_byte_count;
    kal_uint8 eq_plmn_id[MAX_NUM_EQ_PLMN*3];	
}mm_emm_peer_lr_result_ind_struct;

/*MM->EMM*/
typedef struct {
    LOCAL_PARA_HDR 
    lr_result_enum peer_lr_result;
    nas_proc_enum peer_lr_procedure;
    mm_cause_enum mm_peer_reject_cause;
    plmn_id_struct mm_peer_plmn_id;
    kal_bool is_update_eq_plmn_needed;
    kal_uint8 eq_plmn_byte_count;
    kal_uint8 eq_plmn_id[MAX_NUM_EQ_PLMN*3];
}mm_emm_peer_lr_result_req_struct;

#endif

#endif   /* ----- #ifndef MM_EMM_STRUCT_INC ----- */
