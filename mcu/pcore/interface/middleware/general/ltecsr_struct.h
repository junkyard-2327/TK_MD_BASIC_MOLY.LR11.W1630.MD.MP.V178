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
 *   ltecsr_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *	define the message struct parameters
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
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
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _LTECSR_STRUCT_H
#define _LTECSR_STRUCT_H

#include "kal_general_types.h"
#include "kal_public_defs.h"


#include "codec_def.h"
#include "ims_interface_md.h"

/* value define for common_para2 */
typedef enum e_ltecsr_feature_option {
	LTECSR_FEATURE_NONE                     = (0),
	LTECSR_FEATURE_DTMF_MUTE                = (1<<0),
	LTECSR_FEATURE_HOLDCALL_DL_CHECK        = (1<<1),
	LTECSR_FEATURE_ALWAYS_ONE_SHOT_DTMF     = (1<<2),
	LTECSR_FEATURE_DTMF_END_SEP_ENABLE      = (1<<3),
	LTECSR_FEATURE_DYNAMIC_QOS       = (1<<4),
	LTECSR_FEATURE_FIX_RTCP_INTERVAL_ACTIVE   = (1<<5),	
	LTECSR_FEATURE_FIX_RTCP_INTERVAL_HOLD   = (1<<6),
	LTECSR_FEATURE_PING_PCSCF_ENABLE        = (1<<7),
	LTECSR_FEATURE_RTCP_MAX_INTERVAL_ENABLE = (1<<8),
	LTECSR_FEATURE_IGNORE_BEARER_LOST       = (1<<9),
} ltecsr_feature_option_e;

/* value define for nvram stat_feature_option */
typedef enum e_ltecsr_stat_feature_option {
	LTECSR_STAT_NONE        = (0),
	LTECSR_STAT_MDMI        = (1<<0),
	LTECSR_STAT_CIQ         = (1<<1),
	LTECSR_STAT_ECHO        = (1<<2),
} ltecsr_stat_feature_option_e;

typedef enum e_func_class {
	FC_RTP          = IMCB_IMC_FC_RTP,
	FC_XMIT         = IMCB_IMC_FC_XMIT,
	FC_VOICE        = IMCB_IMC_FC_VOICE,
	FC_VIDEO        = IMCB_IMC_FC_VIDEO,
	FC_DTMF         = IMCB_IMC_FC_DTMF,
	FC_CODEC        = IMCB_IMC_FC_CODEC,
	FC_HANDOVER     = IMCB_IMC_FC_HANDOVER,
	FC_TTY          = IMCB_IMC_FC_TTY,
} func_class_e;

typedef enum e_xmit_mode {
	XMIT_MODE_NONE=0,
	XMIT_MODE_INACTIVE,
	XMIT_MODE_SENDONLY,
	XMIT_MODE_RECVONLY,
	XMIT_MODE_SENDRECV,
	XMIT_MODE_ACTIVE,
} xmit_mode_e;

typedef enum e_ecfg{
    LTECSR_ECFG_NONE                        = 0,
    LTECSR_ECFG_DTX_ENABLE                  = 1,
    LTECSR_ECFG_SILENCE_DROPCALL_THRESHOLD  = 2,
    LTECSR_ECFG_JBM_LOAD_PARAMS_ENABLE      = 3,
    LTECSR_ECFG_JBM_PREBUF_LEN              = 4,
    LTECSR_ECFG_JBM_JITTER_MAX_DEPTH        = 5,
    LTECSR_ECFG_JBM_JITTER_FULL_OFFSET      = 6,
    LTECSR_ECFG_LTECSR_COMMON_PARA0         = 7,
    LTECSR_ECFG_LTECSR_COMMON_PARA1         = 8,
    LTECSR_ECFG_LTECSR_COMMON_PARA2         = 9,
    LTECSR_ECFG_LTECSR_COMMON_PARA3         = 10,
    LTECSR_ECFG_LTECSR_COMMON_PARA4         = 11,
    LTECSR_ECFG_RTCP_XR_INTERVAL            = 12,
    LTECSR_ECFG_RTCP_XR_COMPOUND_RTCP       = 13,
    LTECSR_ECFG_RTCP_XR_GMIN                = 14,
    LTECSR_ECFG_TTY_SYNC_BUF_TIME           = 15,
    LTECSR_ECFG_TTY_WAIT_TIME               = 16,
    LTECSR_ECFG_TTY_SEN_DIFF                = 17,
    LTECSR_ECFG_SILENCE_PING_PCSCF_THRESHOLD = 18,
} ecfg_e;


enum VoLTE_Event_RTP_DIRECTION_e {
    VoLTE_Event_RTP_DIRECTION_INACTIVE = 0,     ///< RTP session suspends. Inactive also is default value.
    VoLTE_Event_RTP_DIRECTION_SENDONLY,         ///< Send only
    VoLTE_Event_RTP_DIRECTION_RECVONLY,         ///< Receive only
    VoLTE_Event_RTP_DIRECTION_SENDRECV,         ///< Send and Receive
    /*add here*/    
    VoLTE_Event_RTP_DIRECTION_Max,
};

enum VoLTE_Event_IP_Version_e {
    VoLTE_Event_IPv4 = 0, 
    VoLTE_Event_IPv6,
    /*add here*/    
    VoLTE_Event_IPv_Max,
};

typedef enum e_dtmf_mode {
	DTMF_IN_BAND=0,
	DTMF_OUT_BAND=1,
	DTMF_INOUT_BAND=2,
} dtmf_mode_e;

typedef enum e_dtmf_duration {
	DTMF_PLAY_INFINITE=-1,
	DTMF_STOP=0,
	DTMF_PLAY_ONESHOT=40, 
	/* others value: for unit(ms) */
} dtmf_duration_e;

typedef struct s_xxx2ltecsr_dtmf_param {
	kal_int32 cid;
//	kal_int32 sid;
	kal_uint8 digit;
//	kal_int8 mode;
	kal_int8 duration;
} xxx2ltecsr_dtmf_param_t;

typedef enum e_dtmf_event_state {
	DTMF_KEY_RELEASE =0,
	DTMF_KEY_PUSH_STR=1,
	DTMF_KEY_PUSH_ING=2,
	DTMF_KEY_PUSH_RE1=3,
	DTMF_KEY_PUSH_RE2=4,
	DTMF_KEY_PUSH_RE3=5,
} dtmf_event_state_e;

/**
 * IMC External
 */
typedef struct s_ltecsr_dtmf_req {
	LOCAL_PARA_HDR
	xxx2ltecsr_dtmf_param_t param;
} ltecsr_dtmf_req_struct;

typedef struct s_ltecsr_media_incoming_dlpkt_struct {
	LOCAL_PARA_HDR
	kal_int32 cid;
} ltecsr_media_incoming_dlpkt_struct;

/* WFC */
typedef struct s_ltecsr_ims_init_req {
	LOCAL_PARA_HDR
    kal_int32 seq_no;
    kal_bool  wfc_support;
} ltecsr_ims_init_req_struct;

typedef struct s_ltecsr_ims_init_cnf {
	LOCAL_PARA_HDR
    kal_int32 seq_no;
} ltecsr_ims_init_cnf_struct;

/* from LTECSR to ERRC */
typedef enum e_ltecsr_errc_volte_status {
	LTECSR_ERRC_VOLTE_CALL_START        = 0,
	LTECSR_ERRC_VOLTE_CALL_END          = 1,
} ltecsr_errc_volte_status_e;

typedef struct s_ltecsr_errc_volte_status_ntf_struct {
	LOCAL_PARA_HDR
	ltecsr_errc_volte_status_e volte_status;
} ltecsr_errc_volte_status_ntf_struct;

/* HANDOVER with ebi */
typedef struct s_ltecsr_handover_begin_struct{
    imcf_uint8  source_rat_type;
    imcf_uint8  target_rat_type;
    imcf_uint8  default_ebi;
    imcf_uint8  pad;
    imcf_uint32 network_id;
} ltecsr_handover_begin_struct;

typedef struct s_ltecsr_handover_end_struct{
    imcf_uint8  source_rat_type;
    imcf_uint8  target_rat_type;
    imcf_uint8  is_success;
    imcf_uint8  default_ebi;
    imcf_uint32 network_id;
} ltecsr_handover_end_struct;

/**
 * L1SP External
 */
typedef struct s_ltecsr_voice_ul_data_notify {
	LOCAL_PARA_HDR
} ltecsr_voice_ul_data_notify_struct;

/**
 * LTECSR Internal
 */
typedef struct s_ltecsr_media_init {
	LOCAL_PARA_HDR
	xxx2ltecsr_param_t param;
} ltecsr_media_init_struct;

typedef struct s_ltecsr_media_start {
	LOCAL_PARA_HDR
	kal_int32 cid;
	kal_int32 sid;
} ltecsr_media_start_struct;

typedef struct s_ltecsr_media_stop {
	LOCAL_PARA_HDR
	kal_int32 cid;
	kal_int32 sid;
} ltecsr_media_stop_struct;

typedef struct s_ltecsr_media_xmit_mode_set {
	LOCAL_PARA_HDR
	kal_int32 cid;
	kal_int32 sid;
	kal_int8 xmit_mode; /* xmit_mode_e */
} ltecsr_media_xmit_mode_set_struct;

typedef struct s_ltecsr_dtmf_play {
	LOCAL_PARA_HDR
	xxx2ltecsr_dtmf_param_t param;
} ltecsr_dtmf_play_struct;

typedef struct s_ltecsr_dtmf_stop {
	LOCAL_PARA_HDR
	kal_int32 cid;
} ltecsr_dtmf_stop_struct;

typedef struct s_ltecsr_media_pt_set {
	LOCAL_PARA_HDR
	kal_int32 cid;
	kal_int32 codec;
	kal_int32 pt;
} ltecsr_media_pt_set_struct;

typedef struct s_ltecsr_rtcp_send_interval_set {
	LOCAL_PARA_HDR
	kal_int32 cid;
	kal_int32 sid;
	kal_int32 rtcp_send_interval;
} ltecsr_rtcp_send_interval_set_struct;

typedef struct s_ltecsr_ecfg_req {
		LOCAL_PARA_HDR
    kal_bool    op_code;    // 0:get, 1:set
    ecfg_e      config_type;
    kal_uint32  value;      // only set op_code will use it (for LTECSR)
} ltecsr_ecfg_req_struct;

typedef struct s_ltecsr_ecfg_cnf {
		LOCAL_PARA_HDR
    kal_bool    result;     // KAL_TRUE or KAL_FALSE
    kal_bool    op_code;    // 0:get, 1:set
    ecfg_e      config_type;
    kal_uint32  value;      // only get op_code will use it (for IMC)
} ltecsr_ecfg_cnf_struct;

typedef struct s_ltecsr_epdg_ho_ind {
		LOCAL_PARA_HDR
    kal_int32  stage;      // stage: 0->Handover Start, 1->Handover End
    kal_int32  rat;        // rat: 0->LTE, 1->WiFi
    kal_int32  network_id; // network_id
    kal_int32  pdn_id;     // if (stage==1 && rat==0), pdn_id must be non-zero 
} ltecsr_epdg_ho_ind_struct;

/* interface to IMSP */
typedef enum e_ltecsr_event_type {
	LTECSR_EVENT_NONE = 0,
	LTECSR_EVENT_ONE_WAY = 1,
	LTECSR_EVENT_NEED_CNF = 2,
	LTECSR_EVENT_CNF = 3,
	LTECSR_EVENT_MAX = 0xff,
} ltecsr_event_type_e;

typedef enum e_ltecsr_imsp_event {
	LTECSR_IMSP_NONE = 0,
	LTECSR_IMSP_RTP_SESSION_TIMEOUT = 1,
	LTECSR_IMSP_PKT_INFO_URC = 2,
	LTECSR_IMSP_MAX = 0xff,
} ltecsr_imsp_event_e;

typedef enum e_ltecsr_action_ind {
	LTECSR_IND_NONE = 0,
	LTECSR_IND_EPDG = 1,
	LTECSR_IND_PCSCF = 2,
	LTECSR_IND_MAX = 0xff,
} ltecsr_action_ind_e;

typedef struct s_ltecsr_imsp_req_struct {
	LOCAL_PARA_HDR
	kal_uint32 index;
	ltecsr_event_type_e type;
	ltecsr_imsp_event_e msg;
} ltecsr_imsp_req_struct;

typedef struct s_ltecsr_rtp_sample_time_ind_struct {
	LOCAL_PARA_HDR
	kal_uint8 pdn_id;
	kal_uint32 network_id;
	kal_uint32 timer; 
} ltecsr_rtp_sample_time_ind_struct;


/* msg struct used between (RDS) IMSP <-> LTECSR */
/*************************************************************/
typedef enum e_ltecsr_rtp_config_case_id {
    LTECSR_RDS_SET_JITTER_THR   = 0,
} ltecsr_rtp_config_case_id_e;

typedef enum e_ltecsr_rtp_config_ran {
    LTECSR_RDS_MOBILE_3GPP     = 1,
    LTECSR_RDS_WIFI            = 2,
    LTECSR_RDS_MOBILE_3GPP2    = 3,
} ltecsr_rtp_config_ran_e;

typedef enum e_ltecsr_rtp_notify_jitter_reason {
    LTECSR_RDS_INTERVAL_DL_RTCP_THR    = 1,
    LTECSR_RDS_INTERVAL_UL_RTCP_THR    = 2,
    LTECSR_RDS_NEVER_DL_RTCP           = 3,
    LTECSR_RDS_INTERVAL_DL_RTCP_LOST   = 4,
} ltecsr_rtp_notify_jitter_reason_e;


typedef struct s_ltecsr_rtp_config_local_ind_struct {
    LOCAL_PARA_HDR
    kal_uint8 sim_id;
    kal_uint8 pdn_id;
    kal_uint8 case_id;
} ltecsr_rtp_config_local_ind_struct;

typedef struct s_ltecsr_rtp_config_peer_jitter_ind_struct {
    kal_uint32 jitter_thr;      // ms
    kal_uint32 interval_stat;   // s
} ltecsr_rtp_config_peer_jitter_ind_struct;

typedef struct s_ltecsr_rtp_config_local_cnf_struct {
    LOCAL_PARA_HDR
    kal_uint8 sim_id;
    kal_uint8 pdn_id;
    kal_uint8 case_id;
} ltecsr_rtp_config_local_cnf_struct;

typedef struct s_ltecsr_rtp_notify_local_urc_struct {
    LOCAL_PARA_HDR
    kal_uint8 sim_id;
    kal_uint8 pdn_id;
    kal_uint8 case_id;
} ltecsr_rtp_notify_local_urc_struct;

typedef struct s_ltecsr_rtp_notify_peer_jitter_urc_struct {
    kal_uint8 cur_ran;
    kal_uint8 is_ho;
    kal_uint32 latest_jitter;    // ms
    kal_uint8 reason_id;
} ltecsr_rtp_notify_peer_jitter_urc_struct;
/**************************************************************/

typedef struct s_ltecsr_rtp_session_expire_ind {
	kal_uint32 id;
	kal_uint32 pdn_id;
	kal_uint32 network_id;
	kal_uint32 timer;
	kal_uint32 timeout;
	kal_uint32 action;
} ltecsr_rtp_session_expire_ind_struct;

typedef struct s_ltecsr_pkt_info_urc_struct {
	kal_uint32 id;
	kal_uint32 pdn_id;
	kal_uint32 network_id;
	kal_uint32 timer;
	kal_uint32 ul_lost;
	kal_uint32 dl_lost;
} ltecsr_pkt_info_urc_struct;

typedef struct _ltecsr_ims_notify_msg_t{
	kal_uint32 call_id;    //unique call id
	kal_uint8 msg_id;      //enum value should be maintain in shared point
	kal_uint8 ver;         //structure version number start from 0
	kal_uint16 rsv;        //reserve bit must fill 0 (for 4 byte alignment)
	kal_uint8 ext[64];     //reserve for future other usage
} ltecsr_ims_notify_msg_t;

typedef struct s_ltecsr_ims_notify_ind_struct {
	LOCAL_PARA_HDR
	ltecsr_ims_notify_msg_t msg;
} ltecsr_ims_notify_ind_struct;

typedef struct s_ltecsr_ims_notify_req_struct {
	LOCAL_PARA_HDR
	ltecsr_ims_notify_msg_t msg;
} ltecsr_ims_notify_req_struct;

typedef enum e_ltecsr_ims_notify{
	LTECSR_IMS_NOTIFY_NONE = 0,
	LTECSR_IMS_RTP_TIMER_EXPIRE = 1,
	LTECSR_IMS_RTCP_TIMER_EXPIRE = 2,
	LTECSR_IMS_RTP_WARNING_TIMER_EXPIRE = 3,
	LTECSR_IMS_NOTIFY_MAX = 0xff,
} ltecsr_ims_notify_e;

/**
 * L1C to LTECSR
 */
typedef struct s_ltecsr_l1c_latency_test_detection_ind {
	LOCAL_PARA_HDR
	kal_bool latency_test_flag; // 1: detected, 0: not detected
} ltecsr_l1c_latency_test_detection_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16  op_id;
    kal_uint8   mnc_len;
    kal_uint8   imsi[IMC_MAX_IMSI_LEN];
} ltecsr_mcc_sbp_req_struct;

#endif

