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
 *   sdm_imsp_struct.h
 *
 * Project:
 * ------------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file defines the interface messages between SDM and IMS Proxy.
 *
 * Author:
 * -----------
 * -------
 *
 *===========================================================
 * $Log$
 *
 * 07 06 2017 ian-yw.chen
 * [MOLY00261843] [CDMA-less][LR11.MP5] main feature CR (SDM/SMS)
 *  .
 *
 * 07 06 2017 ian-yw.chen
 * [MOLY00261843] [CDMA-less][LR11.MP5] main feature CR (SDM/SMS)
 *  .
 *
 * 02 06 2017 ian-yw.chen
 * [MOLY00225609] [92->91 feature porting] SCM - interface
 *  .
 *
 * 12 29 2016 zhichao.zhao
 * [MOLY00204308] [Áªµ÷][Jade][CT][VoLTE]SDM will not select CS domain for SMS when CS is unregistered in LTE
 * 	
 * 	.
 *
 * 08 11 2016 ian-yw.chen
 * [MOLY00196139] [VzW][phone mode CCP] support 3GPP2 UTK SMS and PP download over IMS
 *  UTK SMS part
 *  interface part (CL 2688667 2688893 2690322 2693165)
 *
 * 05 19 2016 ian-yw.chen
 * [MOLY00180481] [SDM][ATT req.] Report start and end of MO SMS over IMS to AP (SDM/IMSP part)
 *  .
 *
 * 03 16 2016 ian-yw.chen
 * [MOLY00169285] [COPY CR][VzW][MT6735][Pre-LC][AT command][2.51]  case fail at AT+CMSS=1, shows error (common interface part)
 *  .
 *
 * 02 05 2016 ian-yw.chen
 * [MOLY00163894] [SMS][TC01] 3GPP2 SMS over IMS
 *  interfaces
 *
 * 11 16 2015 edwin.liu
 * [MOLY00147454] VZW 3GPP2 SMS over IMS
 * 	
 * 	.
 *
 * 11 16 2015 edwin.liu
 * Merge 3GPP2 SMS.
 *
 * 09 17 2015 chinte.chen
 * [MOLY00142115] [WWFT][Denali-1][MT6735][EU][VDF][VoLTE][Spain][Madrid][Huawei][FT] SMS must be send over SG in VDF Spain
 * .
 *
 * 08 26 2015 ben.chiu
 * [MOLY00138217] [ViLTE] M0 migration ViLTE feature Interface
 * ViLTE interface patch back
 *
 * 07 30 2015 chinte.chen
 * [MOLY00132834] [COPY_CR][TMO][EM] Enable/Disable SMS over SGs through EM for TMO requirement 58071
 * .
 *
 * 07 09 2015 nick.wang
 * [MOLY00127009] WFC Patch back to UMOLY- interface part
 * .moly wfc interface patch
 *
 * 07 09 2015 nick.wang
 * [MOLY00127009] WFC Patch back to UMOLY- interface part
 * 	.jade interface sync
 *
 * 05 08 2015 chinte.chen
 * [MOLY00110919] [SAT] Support STK SMS over IP
 * .
 *
 * 12 01 2014 chinte.chen
 * [MOLY00086104] [SDM][Revise] remove redundant src_id from IMSP/SDM/IMCSMS
 * .
 *
 * 11 22 2013 chinte.chen
 * [MOLY00047460] [MT6582LTE][IMS][VoLTE][Basic IT][IT3-045] Memory status reporting re-enable of SMSoIP
 * .
 *
 * 09 30 2013 chinte.chen
 * [MOLY00038966] [6290E1][VoLTE][IT][BringUp] Unable to complete RAT mode config
 * .
 *
 * 09 23 2013 jeff.wu
 * [MOLY00038672] [6290E1][VoLTE][IT][BringUp] SDM assert when receiving SMS over IP config ind
 * Rename sdm_imsp_sms_over_ip_config_ind_struct to match msg id.
 *
 * 09 16 2013 chinte.chen
 * [MOLY00038029] [6290E1][VoLTE][IT][SMS] fixed SMS related build error
 * .
 *****************************************************************************/

#ifndef SDM_IMSP_STRUCT_H
#define SDM_IMSP_STRUCT_H

#include "ps_public_struct.h"
#include "sdm_imcsms_enums.h"
#include "ims_common_def.h"
#include "sdm_imsp_enums.h"
#include "sim_public_enum.h"
#include "c2k_sms_enums.h"


/*************************************
*
*    IMS domain
*
*************************************/

/* MSG_ID_SDM_IMSP_CMD_SEND_SMS_IND */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_cmd_send_sms_ind_struct;


/* MSG_ID_SDM_IMSP_CMD_SEND_SMS_IND */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_cmd_send_command_ind_struct;


/* MSG_ID_SDM_IMSP_CMD_SEND_SMS_RSP */
typedef struct{
    LOCAL_PARA_HDR
    kal_bool    is_mr_present;
    kal_uint8   mr_value;
    kal_bool    is_err_cause_present;
    kal_uint16  err_cause_value;
} sdm_imsp_cmd_send_sms_rsp_struct;


/* MSG_ID_SDM_IMSP_URC_RCV_SMS_REQ */
typedef struct{
    LOCAL_PARA_HDR
    sms_addr_struct   sc_addr;
} sdm_imsp_urc_rcv_sms_req_struct;


/* MSG_ID_SDM_IMSP_CMD_SEND_DELIVER_REPORT_IND */
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8   n_value;
    kal_uint8   length;     // mtk00938: how to use?
} sdm_imsp_cmd_send_deliver_report_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    wfc_profile_enum wfc_profile;
} sdm_imsp_cmd_wfc_profile_ind_struct, sdm_imsp_cmd_set_wfc_profile_req_struct;

/* MSG_ID_SDM_IMSP_CMD_SEND_MEM_AVL_NOTIF_IND */
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8   smma;       /* 0:abort the smma, 1:send smma */
} sdm_imsp_cmd_send_mem_avl_notif_ind_struct;


/* MSG_ID_SDM_IMSP_CMD_SEND_SMMA_UPDATE_REQ */
typedef struct{
    LOCAL_PARA_HDR
    kal_bool    update_mem;  /* TRUE if SDM rcv +EMEMS=1,1 */
    kal_bool    update_file; /* TRUE if SDM rcv MEM_AVL_NOTIF_CNF */
} sdm_imsp_cmd_send_smma_update_req_struct;


/* MSG_ID_SDM_IMSP_IMS_REG_STATUS_IND */
typedef struct{
    LOCAL_PARA_HDR
    ims_reg_state_enum         ims_reg_state;
    ims_reg_type_enum          ims_reg_type;
    ims_access_rat_enum        rat;
    ims_reg_service_enum       ims_reg_service;
    ims_ecmp_enum              ecmp;
    ims_reg_sip_uri_type_enum  sip_uri_type;
} sdm_imsp_ims_reg_status_ind_struct;


/* MSG_ID_SDM_IMSP_SMS_OVER_IP_CONFIG_IND */
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8   sms_over_ip_nw_ind;
} sdm_imsp_sms_over_ip_config_ind_struct;

/* MSG_ID_SDM_IMSP_NAS_PS_REG_STATUS_IND */
typedef struct {
    LOCAL_PARA_HDR
    sdm_nas_ps_reg_status_enum nas_ps_reg_status;
} sdm_imsp_nas_ps_reg_status_ind_struct;

/* MSG_ID_SDM_IMSP_NAS_CS_REG_STATUS_IND */
typedef struct {
	LOCAL_PARA_HDR
	sdm_nas_cs_reg_status_enum nas_cs_reg_status;
} sdm_imsp_nas_cs_reg_status_ind_struct;

/* MSG_ID_SDM_IMSP_IMSI_GET_REQ */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_imsi_get_req_struct;

/* MSG_ID_SDM_IMSP_IMSI_GET_CNF */
typedef struct{
    LOCAL_PARA_HDR
    sdm_at_cmd_result_enum result;
} sdm_imsp_imsi_get_cnf_struct;

/* MSG_ID_SDM_IMSP_CMD_STK_SMS_IND */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_cmd_stk_sms_ind_struct;

/* MSG_ID_SDM_IMSP_STK_SMS_QUERY_REQ */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_stk_sms_query_req_struct;

/* MSG_ID_SDM_IMSP_STK_SMS_QUERY_CNF */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_stk_sms_query_cnf_struct;

/* MSG_ID_SDM_IMSP_STK_SMS_TR_REQ */
typedef struct{
    LOCAL_PARA_HDR
    sat_terminal_res_enum tr;
    kal_bool addition_info_present;
    kal_uint8 addition_info;
} sdm_imsp_stk_sms_tr_req_struct;


/* MSG_ID_SDM_IMSP_IMS_SMS_SMART_CONGESTION_URC_IND and MSG_ID_SDM_IMSP_IMS_SMS_SMART_CONGESTION_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    sdm_ims_session_indication_enum indication;   // AT+CSCM/+ECSCM=<SMSoIP=2>,<start-end indication>, Start:1, End:2 

} sdm_imsp_ims_sms_smart_congestion_struct;

typedef sdm_imsp_ims_sms_smart_congestion_struct  sdm_imsp_ims_sms_smart_congestion_urc_ind_struct;
typedef sdm_imsp_ims_sms_smart_congestion_struct  sdm_imsp_ims_sms_smart_congestion_req_struct;


/*******************/
/* C2K SMS over IMS */
/*******************/

/* MSG_ID_SDM_IMSP_CMD_SEND_C2K_SMS_IND */
typedef struct{
    LOCAL_PARA_HDR
    kal_bool                 is_da_valid;
    kal_bool                 is_international;
    kal_uint8                da[MAX_C2K_SMS_DA];    
} sdm_imsp_cmd_send_c2k_sms_ind_struct;

/* MSG_ID_SDM_IMSP_CMD_SEND_C2K_SMS_RSP */
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8            error_class;
	kal_uint16           cause_code;
    kal_uint16           msg_id;  
} sdm_imsp_cmd_send_c2k_sms_rsp_struct;


/* MSG_ID_SDM_IMSP_URC_RCV_C2K_SMS_REQ */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_urc_rcv_c2k_sms_req_struct;


/* MSG_ID_SDM_IMSP_SEND_C2K_MSG_URC_IND */
typedef struct{
	LOCAL_PARA_HDR
	kal_uint16 length;
	kal_uint8  pdu[MAX_SMS_PDU_LEN];
} sdm_imsp_send_c2k_msg_urc_ind_struct;


/* MSG_ID_SDM_IMSP_CMD_SEND_C2K_ACKNOWLEDGE_IND */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_cmd_send_c2k_acknowledge_ind_struct;


/*************************************
*
*    CS domain
*
*************************************/

/* MSG_ID_SDM_IMSP_CS_SMS_SUBMIT */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_cs_sms_submit_struct;


/* MSG_ID_SDM_IMSP_CS_SMS_SUBMIT_REPORT_ACK */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_cs_sms_submit_report_ack_struct;


/* MSG_ID_SDM_IMSP_CS_SMS_SUBMIT_REPORT_NACK */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_cs_sms_submit_report_nack_struct;


/* MSG_ID_SDM_IMSP_CS_SMS_COMMAND */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_cs_sms_command_struct;

/* MSG_ID_SDM_IMSP_CS_SMS_SMMA */
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8   smma;   /*0:abort the smma, 1: send smma*/
} sdm_imsp_cs_sms_smma_struct;

/* MSG_ID_SDM_IMSP_SMS_OVER_SGS_CONFIG_IND */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_bool enable;
} sdm_imsp_sms_over_sgs_config_ind_struct;

/* MSG_ID_SDM_IMSP_CS_STK_SMS_REQ */
typedef struct{
    LOCAL_PARA_HDR
} sdm_imsp_cs_stk_sms_req_struct;

/* MSG_ID_SDM_IMSP_CS_STK_SMS_CNF */
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 result;
    sat_terminal_res_enum tr;
    kal_bool addition_info_present;
    kal_uint8 addition_info;
} sdm_imsp_cs_stk_sms_cnf_struct;


/*************************************
*
*    CMSS: Message Send from Storage
*
*************************************/

/* MSG_ID_SDM_IMSP_CMD_SEND_CMSS_IND */
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8           index;
    l4c_number_struct    da;
} sdm_imsp_cmd_send_cmss_ind_struct;

/* MSG_ID_SDM_IMSP_CMD_SEND_CMSS_RSP */
typedef struct{
    LOCAL_PARA_HDR
    kal_bool    is_mr_present;
    kal_uint8   mr_value;
    kal_bool    is_err_cause_present;
    kal_uint16  err_cause_value;
} sdm_imsp_cmd_send_cmss_rsp_struct;

/* MSG_ID_SDM_IMSP_CMSS_IMS_REQ */
typedef struct{
    LOCAL_PARA_HDR
    kal_bool            is_retry;
    kal_uint8           domain;     //Domain = 0 for IMS; Domain = 1 for CS
    kal_uint8           mr;
    kal_uint8           index;
    l4c_number_struct   da;
} sdm_imsp_cmss_ims_req_struct;

typedef  sdm_imsp_cmss_ims_req_struct sdm_imsp_cmss_cs_req_struct;

/* MSG_ID_SDM_IMSP_CMSS_IMS_CNF */
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8           result;     
                    //<result> 0: if unable to get the PDU correctly from the storage
                    //         1: if operation is successful
                    //         2: if sending the SMS over CS domain fails, but PDU is successfully retrieved. 
                    //               (Only Possible if the domain is CS)
    sms_addr_struct     sca;
    kal_uint8           mr;
} sdm_imsp_cmss_ims_cnf_struct;

typedef sdm_imsp_cmss_ims_cnf_struct sdm_imsp_cmss_cs_cnf_struct;

/* MSG_ID_SDM_IMSP_UPDATE_MSG_BOX_REQ */
typedef struct{
    LOCAL_PARA_HDR
    kal_bool            result;
    kal_uint8           mr;
} sdm_imsp_update_msg_box_req_struct;

/* MSG_ID_SDM_IMSP_UPDATE_MSG_BOX_CNF */
typedef struct{
    LOCAL_PARA_HDR
    kal_bool           result;
} sdm_imsp_update_msg_box_cnf_struct;

#endif // SDM_IMSP_STRUCT_H

