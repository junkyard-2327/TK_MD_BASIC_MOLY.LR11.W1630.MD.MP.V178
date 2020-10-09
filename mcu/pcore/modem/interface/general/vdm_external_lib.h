/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *   vdm_external_lib.h
 *
 * Project:
 * ------------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file defines functions for external module usage.
 *
 * Author:
 * -----------
 * -------
 *
 *===========================================================
 * $Log$
 *
 * 05 15 2019 chen-wei.lan
 * [MOLY00406462] [CTS][CANADA][TELUS][VoLTE] Device is sending Extended Service Request while performing VoLTE Emergency call without IMS Registration SIM in VoLTE TAC. - 911 failed
 * 	
 * 	[CTS][CANADA][TELUS][VoLTE] Device is sending Extended Service Request while performing VoLTE Emergency call without IMS Registration SIM in VoLTE TAC. - 911 failed
 *
 * 07 21 2017 shih-che.chou
 * [MOLY00260969] [VDM][LR11.MP5] 提前?生SRVCC的?理，volte?音 和 vilte?? 是否可以分?配置？
 * .
 *
 * 11 16 2016 shih-che.chou
 * [MOLY00213518] [TCL_TF][VzW][E911][2.17] 911 call not connected
 * .
 *
 * 10 18 2016 kuan-wei.chen
 * [MOLY00204150] TK vzw hVoLTE/E911 implementation
 * TK hVoLTE: L4/IMSP/VDM
 *
 * 10 18 2016 kuan-wei.chen
 * [MOLY00191944] multiple IMS : VDM part
 * MIMS : add new arg : ps_id  in vdm external functions
 *
 * 10 07 2016 kuan-wei.chen
 * [MOLY00183611] [VZW_LC_IOT][PH1_VZW][Radio_Protocol][NDET_Lab] hVoLTE 2.2.40_Option-A fail
 * ADD AT+EICE=3 handling
 *
 * 10 22 2015 lexel.yu
 * [MOLY00146327] [VzW] hVoLTE implementation
 * 	.
 *
 * 09 14 2015 lexel.yu
 * [MOLY00141573] [UMOLY][LR11][TMO][IMS] bCSFB
 * 	.
 *
 * 03 12 2015 lexel.yu
 * [MOLY00085703] [VDM][MT6291] Sync MOLY to UMOLY
 * 	[MOLY00085856] [CMCC VoLTE] Provide an interface for EMM to query IMS call status
 *
 * 12 05 2014 lexel.yu
 * [MOLY00085703] [VDM][MT6291] Sync MOLY to UMOLY
 * 	[MOLY00085856] [CMCC VoLTE] Provide an interface for EMM to query IMS call status
 *****************************************************************************/

#ifndef _VDM_EXTERNAL_LIB_H_
#define _VDM_EXTERNAL_LIB_H_

#include "kal_general_types.h"
#include "l3_inc_enums.h"
#include "ims_nvram_def.h"

/******************************************************************************
 *                                Function
 *****************************************************************************/
/******************************************************************************
 * @brief Get current RAT
 *        
 * @param[in] void
 *
 * @return rat_enum
 *
 *****************************************************************************/
rat_enum vdm_external_get_current_rat(protocol_id_enum ps_id);

/******************************************************************************
 * @brief Check if any CS voice call is ongoing
 *        
 * @param[in] void
 *
 * @return kal_bool: TRUE or FALSE
 *
 *****************************************************************************/
kal_bool vdm_external_is_cs_voice_call_ongoing(protocol_id_enum ps_id);

/******************************************************************************
 * @brief Check if any IMS voice call is ongoing
 *        
 * @param[in] void
 *
 * @return kal_bool: TRUE or FALSE
 *
 *****************************************************************************/
kal_bool vdm_external_is_ims_voice_call_ongoing(protocol_id_enum ps_id);

/******************************************************************************
 * @brief Check if any VoLTE call exists
 *        
 * @param[in] void
 *
 * @return kal_bool: TRUE or FALSE
 *
 *****************************************************************************/
kal_bool vdm_external_is_volte_call_exist(protocol_id_enum ps_id);

/******************************************************************************
 * @brief Check if any ViLTE call exists
 *        
 * @param[in] void
 *
 * @return kal_bool: TRUE or FALSE
 *
 *****************************************************************************/
kal_bool vdm_external_is_vilte_call_exist(protocol_id_enum ps_id);

/******************************************************************************
 * @brief Check if IMS call failed before domain selection end
 *        
 * @param[in] void
 *
 * @return kal_bool: TRUE or FALSE
 *
 *****************************************************************************/
kal_bool vdm_external_check_history_ims_failed(protocol_id_enum ps_id);

/******************************************************************************
 * @brief Check if any C2K CS voice call is ongoing
 *        
 * @param[in] void
 *
 * @return kal_bool: TRUE or FALSE
 *
 *****************************************************************************/
kal_bool vdm_external_is_c2k_cs_voice_call_ongoing(protocol_id_enum ps_id);


/******************************************************************************
 * @brief Check if C2K CS service registered 
 *        
 * @param[in] void
 *
 * @return kal_bool: TRUE or FALSE
 *
 *****************************************************************************/
kal_bool vdm_external_is_c2k_cs_registered(protocol_id_enum ps_id);

/******************************************************************************
 * @brief Check if C2K PS service registered 
 *        
 * @param[in] void
 *
 * @return kal_bool: TRUE or FALSE
 *
 *****************************************************************************/
kal_bool vdm_external_is_c2k_ps_registered(protocol_id_enum ps_id);

/******************************************************************************
 * @brief Check if need to delay SRLTE mode switch (only used for OP12 hVoLTE feature)
 *        
 * @param[in] void
 *
 * @return kal_bool: TRUE or FALSE
 *
 *****************************************************************************/
kal_bool vdm_external_is_delay_SRLTE_switch_needed(protocol_id_enum ps_id);

/******************************************************************************
 * @brief let VDM to write nvram parameters
 *           this function should be called only for test purpose
 *        
 * @param[in] 
 *
 * @return 
 *
 *****************************************************************************/
void vdm_external_write_nvram(nvram_lid_ims_enum vdm_lid, kal_uint8* pdu_ptr, kal_uint32 vdm_nvram_size, protocol_id_enum ps_id);

/******************************************************************************
 * @brief let VDM to read nvram parameters
 *           this function should be called only for test purpose
 *        
 * @param[in] 
 *
 * @return 
 *
 *****************************************************************************/
void vdm_external_read_nvram(nvram_lid_ims_enum vdm_lid, kal_uint8* pdu_ptr, kal_uint32 vdm_nvram_size, protocol_id_enum ps_id);

/******************************************************************************
 * @To check whether wcf is turned-on or off. This info comes from AT+EIMSWFC
 *        
 * @param[in] 
 *
 * @return 
 *
 *****************************************************************************/
kal_bool vdm_external_wfc_switch(protocol_id_enum ps_id);

/******************************************************************************
 * @brief Check if CS ECC attempt in TELUS need to force select 23G
 *        
 * @param[in] ps_id
 *
 * @return kal_bool: TRUE or FALSE
 *
 *****************************************************************************/
kal_bool vdm_external_is_force_select_23G_need_in_telus(protocol_id_enum ps_id);

#endif // _VDM_EXTERNAL_LIB_H_
