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
/*******************************************************************************
 * Filename:
 * ---------
 * l4c_c2k_msg.h
 *
 * Project:
 * --------
 *   DENALI
 *
 * Description:
 * ------------
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#ifndef _L4C_C2K_MSG_H
#define _L4C_C2K_MSG_H

#ifdef __CDMA2000_RAT__

#include "l4c_context.h"
#include "kal_public_api.h"
#include "mmi_sm_enums.h"
#include "mmi_l3_enums.h"
#include "ps_public_enum.h"
#include "ppp_l4_enums.h"
#include "l4c_common_enum.h"
#include "tcm_context.h"
#include "c2k_irat_msg_struct.h"
#include "irat_common_enums.h"
#include "l4c_esm_struct.h"
#include "rac2l4c_struct.h"

typedef struct{
    LOCAL_PARA_HDR
    l4c_c2k_irat_context_struct l4c_c2k_context;
}l4c_c2k_ut_check_context_ind_struct;


typedef struct{
    LOCAL_PARA_HDR
    l4c_c2k_lwcg_irat_context_struct l4c_c2k_lwcg_context;
}l4c_c2k_ut_check_lwcg_context_ind_struct;


extern kal_bool l4c_ei3gppirat_hdlr();

extern kal_bool l4c_epdnctrans_hdlr(kal_uint8 enable_pdn_context_transfer_in_lwcg);

extern void l4c_c2k_force_perform_irat_without_wait_ei3gppirat();

void l4c_ei3gppirat_report_rind(ei3gppirat_action_enum action, irat_ps_type_enum src_rat, irat_ps_type_enum target_rat);

extern void l4c_epdnctrans_report_rind(epdnctrans_action_enum action, irat_ps_type_enum src_rat, irat_ps_type_enum target_rat);

extern void l4c_egcontrdp_report_rind(kal_uint8 context_id);

extern void l4c_c2k_lte_rat_change_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_c2k_lte_pdn_context_transfer_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_lte_c2k_pdn_context_transfer_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_lte_c2k_rat_change_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_attach_result_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_c2k_send_rat_change_cnf_to_c2k(irat_result_enum err_code, kal_bool resync, kal_bool is_irat_success);

extern void l4c_c2k_config_pdn_establishing_status(kal_uint8 cid, l4c_c2k_func_action_enum action);

extern void l4c_c2k_config_irat_state(l4c_c2k_irat_state_enum new_state);

extern void l4c_c2k_config_c2k_to_lte_src_rat(irat_ps_type_enum new_rat);

extern kal_bool l4c_c2k_omadm_check(kal_uint8 cid);

extern void l4c_c2k_config_waiting_ei3gppirat(kal_bool is_waiting);

extern kal_bool l4c_c2k_check_no_need_to_wait_ei3gppirat();
extern void l4c_c2k_record_l2c_stage_1_temp_info(l4cesm_rat_change_ind_struct *rat_change_ind_msg);
extern void l4c_c2k_record_c2l_stage_1_temp_info(l4cesm_rat_change_cnf_struct *rat_change_cnf_msg);

extern void l4c_c2k_config_deact_retry(kal_bool deact_retry, kal_uint8 context_num);
extern void l4c_c2k_clear_all_deact_retry();

extern void l4c_c2k_clear_c2l_irat_related_context();

extern kal_bool l4c_c2k_check_is_at_command_lock();
extern void l4c_c2k_rat_select_ind_hdlr(l4crac_rat_select_ind_struct *rat_select_ind);

extern kal_bool l4c_c2k_check_now_rat_mode(rat_enum check_rat);
extern kal_bool l4c_c2k_is_do_lc_mode_interrat_logic();
extern void l4crac_gmss_stop_search_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4c_lte_c2k_ia_pdn_query_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4c_c2k_config_pdn_context_transfer_state(l4c_c2k_lwcg_pdn_context_transfer_state_enum new_state);
extern void l4c_c2k_send_lte_c2k_ia_pdn_query_req();
extern void l4c_c2k_send_lte_c2k_pdn_context_transfer_req();
extern void l4c_c2k_send_c2k_lte_pdn_context_transfer_cnf();
extern kal_bool l4c_c2k_check_if_need_c2l_ip_continuity();
extern void l4c_c2k_pwroff_start_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern kal_bool l4c_c2k_enable_transfer_pdn_context_in_lwcg();
extern kal_bool l4c_c2k_already_fetched_ia();
extern kal_bool l4c_c2k_already_transfer_pdn_to_c2k();

extern void l4c_c2k_l4c_mdstatus_update_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#if defined __L4C_GPRS_UT__
extern void l4c_c2k_test_func(kal_uint8 index);
extern void l4c_ut_set_pdn_info(kal_uint8 case_num);
extern void l4c_ut_reset_pdn_info();
extern void l4c_c2k_print_context();
extern void l4c_c2k_print_lwcg_context();
#endif

extern void l4c_c2k_roaming_setting_sync_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_compose_fail_l4cesm_rat_change_rsp_and_config_ei3gppirat();

extern void l4c_c2k_interrupt_irat_if_ei3gppirat_waiting();
#endif

#endif /* #ifndef _L4C_C2K_MSG_H */

