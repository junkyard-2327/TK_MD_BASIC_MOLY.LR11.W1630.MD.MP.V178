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
 *   sdm_msgid.h
 *
 * Project:
 * ------------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file defines the identities of the messages received by SDM.
 * 
 *
 * Author:
 * -----------
 * -------
 *
 *===========================================================
 * $Log$
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
 * 03 16 2016 ian-yw.chen
 * [MOLY00169285] [COPY CR][VzW][MT6735][Pre-LC][AT command][2.51]  case fail at AT+CMSS=1, shows error (common interface part)
 *  .
 *
 * 02 05 2016 ian-yw.chen
 * [MOLY00163894] [SMS][TC01] 3GPP2 SMS over IMS
 *  interfaces
 *
 * 11 16 2015 ian-yw.chen
 * [MOLY00147454] VZW 3GPP2 SMS over IMS
 * 	IMCSMS part
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
 * 11 22 2013 chinte.chen
 * [MOLY00047460] [MT6582LTE][IMS][VoLTE][Basic IT][IT3-045] Memory status reporting re-enable of SMSoIP
 * .
 *
 * 09 30 2013 chinte.chen
 * [MOLY00038966] [6290E1][VoLTE][IT][BringUp] Unable to complete RAT mode config
 * .
 *****************************************************************************/

#ifndef SDM_MSGID_H
#define SDM_MSGID_H

#include "module_msg_range.h"


MODULE_MSG_BEGIN( MSG_ID_SDM_CODE_BEGIN )

/****************************************************************************
 *                          IMSP -> SDM
 ****************************************************************************/
MSG_ID_SDM_IMSP_CMD_SEND_SMS_IND                    = MSG_ID_SDM_CODE_BEGIN,
MSG_ID_SDM_IMSP_CMD_SEND_DELIVER_REPORT_IND,
MSG_ID_SDM_IMSP_CMD_SEND_MEM_AVL_NOTIF_IND,
MSG_ID_SDM_IMSP_CMD_WFC_PROFILE_IND,
MSG_ID_SDM_IMSP_CS_SMS_SUBMIT_REPORT_ACK,
MSG_ID_SDM_IMSP_CS_SMS_SUBMIT_REPORT_NACK,
MSG_ID_SDM_IMSP_CMD_STK_SMS_IND,
MSG_ID_SDM_IMSP_STK_SMS_QUERY_CNF,
MSG_ID_SDM_IMSP_CS_STK_SMS_CNF,
MSG_ID_SDM_IMSP_IMSI_GET_CNF,

MSG_ID_SDM_IMSP_CMD_SEND_COMMAND_IND,
MSG_ID_SDM_IMSP_SMS_OVER_IP_CONFIG_IND,
MSG_ID_SDM_IMSP_IMS_REG_STATUS_IND,
MSG_ID_SDM_IMSP_SMS_OVER_SGS_CONFIG_IND,
MSG_ID_SDM_IMSP_NAS_PS_REG_STATUS_IND,
MSG_ID_SDM_IMSP_NAS_CS_REG_STATUS_IND,
MSG_ID_SDM_IMSP_CMD_SEND_C2K_SMS_IND,
MSG_ID_SDM_IMSP_CMD_SEND_C2K_ACKNOWLEDGE_IND,
MSG_ID_SDM_IMSP_CMD_SEND_CMSS_IND,
MSG_ID_SDM_IMSP_CMSS_IMS_CNF,
MSG_ID_SDM_IMSP_CMSS_CS_CNF,
MSG_ID_SDM_IMSP_UPDATE_MSG_BOX_CNF,

/****************************************************************************
 *                          IMCSMS -> SDM
 ****************************************************************************/
MSG_ID_SDM_IMCSMS_SUBMIT_REPORT_ACK,
MSG_ID_SDM_IMCSMS_SUBMIT_REPORT_NACK,
MSG_ID_SDM_IMCSMS_STK_SUBMIT_REPORT_ACK,
MSG_ID_SDM_IMCSMS_STK_SUBMIT_REPORT_NACK,
MSG_ID_SDM_IMCSMS_DELIVER,
MSG_ID_SDM_IMCSMS_C2K_SUBMIT_REPORT_ACK,
MSG_ID_SDM_IMCSMS_C2K_SUBMIT_REPORT_NACK,
MSG_ID_SDM_IMCSMS_CDMA_SUBMIT_REPORT_ACK,
MSG_ID_SDM_IMCSMS_CDMA_SUBMIT_REPORT_NACK,
MSG_ID_SDM_IMCSMS_C2K_DELIVER,
MSG_ID_SDM_IMCSMS_STATUS_REPORT,
MSG_ID_SDM_IMCSMS_CMSS_SUBMIT_REPORT_ACK,
MSG_ID_SDM_IMCSMS_CMSS_SUBMIT_REPORT_NACK,
MSG_ID_SDM_IMCSMS_MEM_AVL_NOTIF_CNF,
MSG_ID_SDM_IMCSMS_RCV_MSG_IND,


MODULE_MSG_END( MSG_ID_SDM_CODE_TAIL )


#endif // SDM_MSGID_H

