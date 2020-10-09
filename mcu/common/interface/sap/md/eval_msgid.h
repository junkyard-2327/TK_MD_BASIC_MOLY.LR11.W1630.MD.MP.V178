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
 *   eval_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   LTE NAS EVAL (EVNAS Adaptation Layer) related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 04 19 2018 youru.chen
 * [MOLY00320848] [ES2][FT][KSA][Riyadh][Mobily]: DUT permanently goes to OOS after reset to default APN settings
 * 	
 * 	Recieve APN change info from NWSEL and stop T3402.
 *
 * 11 22 2017 ashwitha.hegde
 * [MOLY00290646] 203604 ??????????1??4G??2??4G????2????????????
 * Porting to LR11 MP5: AT+EMRO
 *
 * 07 11 2017 james-chi-ju.chang
 * [MOLY00261903] [CDMA-less][MP5] 2nd NWSEL interface
 * IF
 *
 * 02 06 2017 tim.huang
 * [MOLY00226876] [92->91 feature porting] SCM - EMM can be partial released
 * 	
 * 	.
 *
 * 12 09 2016 jerry-yh.chang
 * [MOLY00216543] [LG+WG] runtime Duplex Change for CSFB TDS
 * [OA domain] Interface check in
 *
 * 09 06 2016 shih-che.chou
 * [MOLY00193710] [6291][VOLTE enhancement]Enhancement A3 report (B/O/P) extend to more operator
 * .
 *
 * 09 06 2016 bob.chiang
 * [MOLY00200593] Multiple-PS MP5: EMM local release connection for data on peer
 *
 * 08 30 2016 ivy.wang
 * [MOLY00200197] New Feature UL64QAM on 6291
 * .
 *
 * 08 30 2016 allen.hsu
 * [MOLY00200272] New Feature UL64QAM switcher
 * 	
 * 	add UL64QAM switch.
 *
 * 08 05 2016 paul.huang
 * [MOLY00189921] [Olympus][M1][E1][4G][SRLTE][CT 6M C][LTE IOT][FT][HF][NSN][TC-SMFT-02003]UE appear 4-3 reselction slow once.
 *
 * 08 04 2016 shih-che.chou
 * [MOLY00187953] AT+ECMSID=<n> to clear GUTI/P-TMSI
 * .
 *
 * 08 04 2016 melody.tien
 * [MOLY00195214] [interface]#18 send a new message to inform CS domain is not avaliable
 * 	
 * 	. (OA) [msg_id]
 *
 * 05 05 2016 ivan.chung
 * [MOLY00170799] [PH1_VZW][joint-camp][Radio_Protocol][hVoLTE] TC 2.2.9.3 fail: at step13, TAU timeout
 *
 * 04 28 2016 yc.chen
 * [MOLY00175408] Multiple-PS/Remote-SIM interfaces phase2
 * 	
 * 	.
 *
 * 03 16 2016 bart.liang
 * [MOLY00169240] [PH1_VZW][Radio_Protocol][UNSOL] LTE NETWORK INFORMATION
 *
 * 03 03 2016 jerry-yh.chang
 * [EMM] merge MOLY00152757 and MOLY00152764 (non-LTE)
 *
 * 02 19 2016 doug.shih
 * [MOLY00150211] [VzW][VZ_REQ_LTEMMO_38695] LTE Scanning Enhancement
 * ERRC CEL LTE scan in C2K idle and PS active procedure control (OA domain).
 *
 * 02 18 2016 ivy.wang
 * [MOLY00165236] [PH1_VZW][FLD][Radio_Protocol] VZ_REQ_LTEDATA_37821 Autonomous Gaps
 * .
 *
 * 01 25 2016 yc.chen
 * [MOLY00146327] [VzW] hVoLTE implementation (non-LTE)
 *
 * 01 12 2016 ivy.wang
 * [MOLY00155801] [CA] Enable/Disable CA by AT+ECASW (ERRC)
 * .
 *
 * 12 11 2015 james-chi-ju.chang
 * [MOLY00152730] [LAT2][2015][MT6755 TMO-US][Internal Simulation][Anritsu][CA_Protocol][TC_4.1.1.20]
 * <saved by Perforce>
 *
 * 11 23 2015 jerry-yh.chang
 * [MOLY00150096] [Jade-M][Spirent][IR]TC-LTEIRLAB-DCMP-09003 FAIL - ?Éó¤£ª`?LTE
 * Add handling of GLOBAL_MODE_CHANGE_START_REQ
 *
 * 11 17 2015 yc.chen
 * [MOLY00149445] [UMOLY] Sync DoCoMo MOLY CR to related branch (MOLY00123677)
 *
 * 11 04 2015 hong.yu
 * [MOLY00147987] [MT6291]Autonomous DRX
 * [EVAL] patch MOLY00097750 to UMOLY
 *
 * 10 22 2015 kinki.lin
 * [MOLY00144447] Operator Feature/Requirement
 * . (non-secure) verizon: under LWCG mode, delay local detach after C2K get normal service
 *
 * 10 19 2015 yc.chen
 * [MOLY00145708] [Jade-L][SRLTE][CT OM 6M][LTE IOT][FT][SH][ALU][Random]?ºÝ¦b3G¤U¡A¥X?¤£¯à?¦æPS©MCS??
 * 	.
 *
 * 10 13 2015 roland.li
 * [MOLY00133440] [ERRC][RCM]Configurable CA combination
 * 	.
 *
 * 10 12 2015 morton.lin
 * [MOLY00144901] [ERRC] bCSFB feature check-in for TMO-US
 * [ERRC][SPV] bCSFB feature check-in for TMO-US (LR11)
 *
 * 10 12 2015 yingfui.hung
 * [MOLY00141134] [Copy CR][Porting to LR11][TMO][IMS] bCSFB - L4 ERLQ, ERLM changes (without switch)
 * 	.
 *
 * 10 08 2015 allen.hsu
 * [MOLY00133440] [ERRC][RCM]Configurable CA combination
 * add LTE CA band settings feature related interface.
 *
 * 10 07 2015 doug.shih
 * [MOLY00144181] [ERRC][SPV] LR11 build warning scan and fix (also legacy C2K code cleanup)
 * [CEL] phase out early OOS ind for SVLTE (OA domain).
 *
 * 10 02 2015 hong.yu
 * [MOLY00139482] [VzW] [VZ_REQ_LTEDATA_6800] Dynamic UE specific DRX setting
 * [VzW] UE specific DRX
 *
 * 09 25 2015 james-chi-ju.chang
 * [MOLY00143156] [MT6755][E1][GCF][Anite][3G][FDD][CSG][6.3.1.1] Test Fail
 * .
 *
 * 09 10 2015 yc.chen
 * [MOLY00141417] [Jade-L][SRLTE][LTE IOT][FT][SH][ZTE][random]±µ¦¬±m«H¦Z?«Ì EE,0,0,99,/data/core/,1,modem,md1
 * 	.
 *
 * 08 27 2015 bob.chiang
 * [MOLY00138281] [EMM] Sync MOLY CR to 2015/08/20
 * : CONN - MOLY00129803
 *
 * 08 27 2015 bob.chiang
 * [MOLY00139385] [JADE][SRLTE][inHouseIT][Lab Spirent][TC-LTEIRLAB-SCMP-03006] Moible failed to registered in gsm network!
 * : REG/EVAL - inform NWSEL when SIM removal handling is completed
 *
 * 07 20 2015 allen.keh
 * [MOLY00129803] [Denali][ATT][VoLTE][Anritsu CAT] TC LTE-BTR-1-8220 (-8248) On a voice call the Detach procedure after the ISIM refresh should only be started when returned to Idle state
 * .add MSG_ID_EVAL_EMM_CONNECTION_INFO_IND
 *
 * 07 18 2015 cooper.lin
 * [MOLY00090532] [MT6291] Change Feature Check-in
 * Uplink Data Shaping
 *
 * 07 17 2015 shih-che.chou
 * [MOLY00129720] [VzW][Merge to UMOLY] Porting RAC part from MOLY to UMOLY
 * .
 *
 * 07 03 2015 tim.huang
 * [MOLY00125845] [JADE] SRLTE related design
 * .
 *
 * 06 18 2015 jerry-yh.chang
 * [MOLY00122048] [6795] Request new feature to improve registration time of roaming case
 * .
 *
 * 06 18 2015 panu.peisa
 * [MOLY00122487] EMM, ESM & PAM module VzW feature porting from 6290 to 6291
 * 	SWRD part, change have dependency to LTE_SEC parts.
 *
 * 06 16 2015 tim.huang
 * [MOLY00083439] [MUSE] IMS Development for requirment 1-15 - get the information of MO Data Barring and SSAC barring
 * .
 *
 * 06 16 2015 kuan-wei.chen
 * [MOLY00115378] SS code revise
 * merge from MOLY to UMOLY
 *
 * 06 10 2015 teemu.partanen
 * [VZ_REQ_LTEDATARETRY_7733] Throttling timer related new message identifiers, enumerations and structures for EMM - NWSEL communication
 *
 * 05 29 2015 ye.yuan
 * [MOLY00116932] [UMOLY] [NAS]compile option modify
 * .
 *
 * 05 29 2015 shih-che.chou
 * [MOLY00117190] PLMN List in CONNECTED Mode
 * RAC part
 *
 * 05 29 2015 kun-lin.wu
 * [MOLY00117190] PLMN List in CONNECTED Mode
 *
 * 05 29 2015 kun-lin.wu
 * [MOLY00115617] [6291] Dynamic SIM switch without modem reset
 *
 * 05 26 2015 chun-fan.tsai
 * [MOLY00097098] [6291][CONN] Code Sync from MOLY to UMOLY
 * MOLY00097502
 *
 * 05 07 2015 cooper.lin
 * [MOLY00090532] [MT6291] Change Feature Check-in
 * Report CA Info to support 4G Plus Icon
 *
 * 05 06 2015 kuan-wei.chen
 * [MOLY00098019] [VzW][Merge to MOLY] MRU revise / MRU AT command
 * add AT+VZWMRUC, AT+VZWMRUE
 *
 * 04 23 2015 mark.chung
 * [MOLY00095378] Amazon Requirement
 * 	.
 *
 * 04 21 2015 edwin.liu
 * [MOLY00091774] [VzW][Merge to MOLY] Clear GUTI when doing factory reset
 * 	.
 *
 * 04 16 2015 tim.huang
 * [MOLY00107801] NAS 6291 DEV
 * .
 *
 * 04 16 2015 james-chi-ju.chang
 * [MOLY00078264] [UMOLY][R10][R11] NAS check-in from CBr to 6291_DEV
 * 	.
 *
 * 02 23 2015 bob.chiang
 * [MOLY00096607] Sync C2K CR
 * .
 *
 * 02 05 2015 morton.lin
 * [MOLY00084695] [6291] Code merged from MOLY to UMOLY TRUNK
 * [6291][ERRC][SPV] Code sync from MOLY (W15.06)
 *
 * 12 17 2014 james-chi-ju.chang
 * [MOLY00078264] [UMOLY][R10][R11] NAS check-in from CBr to 6291_DEV
 * 	.
 *
 * 11 12 2014 yingwei.huang
 * [MOLY00073932] [MT6291_DEV] EDDA implementation -- interface part.	.
 *
 * 11 12 2014 carlson.lin
 * [MOLY00084165] [UMOLY][R10][R11] NAS check-in from 6291_DEV to UMOLY Trunk
 * (Sync from MT6291_DEV upto CL 869855)
 *
 * 11 10 2014 robert.wu
 * [MOLY00083874] [UMOLY][R10][R11] EMM MTC sync code from 6291_DEV to UMOLY trunk
 *
 * 07 07 2014 benjamin.kuo
 * [MOLY00071459] Add Mobility Management for IMS Voice Termination
 * MMIVT2MOLY
 *
 * 07 02 2014 shaowu.huang
 * [MOLY00070824] [4G Gemini][FT][BJ][CSFB test][case5.1.1][SIM1 CMCC+SIM2 CMCC][4G,3G,2G×¢ï¿½ï¿½Ê±ï¿½Ó¾ï¿½Ï³ï¿½]
 * .
 *
 * 06 13 2014 aaron.liu
 * [MOLY00067559] [MT6592LTE][CSFB][Single USIM][CMCC FT][case5.1.1][4G,3G,2Gï¿½`??ï¿½ï¿½ï¿½ï¿½??]
 * .EVAL interface part.
 *
 * 05 16 2014 lt.chang
 * [MOLY00065658] [sglte dsds]ps detach and attach redesign
 * .check in actvie sim info req interface
 *
 * 04 23 2014 tehuang.liu
 * [MOLY00063538] [6290E2][VoLTE][VDM] Support VoLTE Gemini architecture
 * Check in VoLTE+Gemini related interfaces for VDM, IMSP, L4C, EVAL, and ERRC
 *
 * 04 02 2014 cookie.chen
 * [MOLY00060012] AT+ECBMR to remove modem CB records
 * .
 *
 * 03 28 2014 jinghan.wang
 * [MOLY00060988] [LPP CP] LPP code check-in for A-GNSS and eCID feature
 * Check in LPP CP interfaces & capability for EMM (OA domain)
 *
 * 03 06 2014 aaron.liu
 * [MOLY00056483] [MT6582LTE][SGLTE][CMCC FT][GZ]ï¿½b?ï¿½ï¿½2G3Gï¿½ï¿½??ï¿½ï¿½b3Gï¿½Jï¿½I???
 * Add PLMN SEARCH Abort Interface:
 * 1.MSG_ID_EVAL_ERRC_PLMN_SEARCH_ABORT_REQ
 * 2.MSG_ID_NWSEL_EVAL_PLMN_SEARCH_ABORT_REQ
 *
 * 03 06 2014 joe.chang
 * [MOLY00058412] [MOLY] TFT validate revision
 * [ESM/TFTLIB] Modification fot "TFT validate" and "PS init deactivation"
 *
 * 03 05 2014 benjamin.kuo
 * [MOLY00050602] [SAT] support Network Rejection Event
 * .
 *
 * 02 17 2014 benjamin.kuo
 * [MOLY00055341] [MP1 Post MP Patch][MT6290E2][LTE attach PDN] UE doesn't perform LTE attach due to TCM cmd conflict
 * MOLY
 *
 * 01 22 2014 jinghan.wang
 * [MOLY00054514] [LTE Gemini] Feature check in MOLY trunk for EMM PLMNSEL and related EMM interfaces
 *
 * 01 21 2014 wcpuser_integrator
 * [MOLY00054475] SGLTE option rename
 * .
 *
 * 01 13 2014 allen.keh
 * [MOLY00053328] [MT6290E2][VoLTE] VoLTE development merge back to TRUNK.
 * 	Add message ids & SAP ids
 *
 * 11 13 2013 adeline.chang
 * [MOLY00046027] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * .
 *
 * 10 18 2013 shih-chieh.liao
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * integrate EAS_TO_PEER_INFO_IND.
 *
 * 10 18 2013 hc.chu
 * [MOLY00041414] [MT6290E1][WWFT][HK][3HK] Voice domain preference encode error
 * merge prebuild cbr back to trunk.
 *
 * 08 23 2013 shih-chieh.liao
 * [MOLY00034931] [MMDC] change EAS_STATE_IND to TO_PEER_INFO_IND
 * .
 *
 * 08 30 2013 hc.chu
 * [MOLY00036036] [MMDS_DC] Add EVAL_ESM_PS_SWITCH_COMPLETE_IND related handing
 * [MMDS_DC] Add EVAL_ESM_PS_SWITCH_COMPLETE_IND related handing.
 *
 * 08 23 2013 shih-chieh.liao
 * [MOLY00034931] [MMDC] change EAS_STATE_IND to TO_PEER_INFO_IND
 * .
 *
 * 08 23 2013 hc.chu
 * [MOLY00034663] MMDC RAC code check-in
 * remove unused mmdc rac codes
 *
 * 07 24 2013 benjamin.kuo
 * [MOLY00031020] [MMDS_DC] Merge MMDC interface to MOLY
 * <saved by Perforce>
 *
 * 04 01 2013 benjamin.kuo
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * add __MMDC__ for message/structure.
 *
 * 03 27 2013 benjamin.kuo
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * .
 *
 * 03 15 2013 benjamin.kuo
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * MM IT merge back to MOLY.
 *
 * 03 14 2013 benjamin.kuo
 * [MOLY00011934] LTE MM IT CBr merge to MOLY
 * common file: EVAL part.
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
 *
 * 11 06 2012 yu.huang
 * [MOLY00005322] TATAKA merge to MOLY
 * [EVAL] Add EVAL related interfaces and common strust
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef _EVAL_MSGID_H
#define _EVAL_MSGID_H

MODULE_MSG_BEGIN( MSG_ID_EVAL_CODE_BEGIN )

/****************************************************************************
 *                          Destination: EVAL (L4C to EVAL) 
 ****************************************************************************/
MSG_ID_L4C_EVAL_RAT_CHANGE_REQ              = MSG_ID_EVAL_CODE_BEGIN,
MSG_ID_L4C_EVAL_RAT_CHANGE_RSP,
MSG_ID_L4C_EVAL_ETWS_SETTING_REQ,
MSG_ID_L4C_EVAL_GET_SSAC_PARAM_REQ,

/* defined in l4_msgid.h for maintenance
 * MSG_ID_L4C_EVAL_ADJUST_MEAS_REQ,
 */

MSG_ID_L4C_EVAL_NBR_CELL_INFO_START_REQ,
MSG_ID_L4C_EVAL_NBR_CELL_INFO_STOP_REQ,

MSG_ID_L4C_EVAL_LTE_NEIGHBOR_CELL_INFO_REQ,

MSG_ID_L4C_EVAL_VDM_VOICE_STATUS_REQ,

MSG_ID_L4C_EVAL_ERLM_CONTROL_REQ,

MSG_ID_L4C_EVAL_EDDA_REQ,
MSG_ID_L4C_EVAL_FACTORY_RESET_REQ,
MSG_ID_L4C_EVAL_MRU_UPDATE_REQ,
MSG_ID_L4C_EVAL_LTECA_BAND_SETTING_REQ,
MSG_ID_L4C_EVAL_DRX_UPDATE_REQ,
MSG_ID_L4C_EVAL_LTECA_MODE_SETTING_REQ,
MSG_ID_L4C_EVAL_AUDRX_ENABLE_REQ,
MSG_ID_L4C_EVAL_OMADM_UPDATE_REQ,
MSG_ID_L4C_EVAL_MODULATION_UPDATE_REQ,


#ifdef __REMOTE_SIM__
MSG_ID_L4C_EVAL_RSIM_ABORT_REQ,
#endif
MSG_ID_L4C_EVAL_GUTI_IN_NV_CLEAR_REQ,
MSG_ID_L4C_EVAL_IMS_CALL_STATUS_REQ,
MSG_ID_L4C_EVAL_HQ_SERVICE_STATUS_REQ,

/****************************************************************************
 *                          Destination: EVAL (ERAC to EVAL) 
 ****************************************************************************/
MSG_ID_EMMREG_INIT_REQ,
MSG_ID_EMMREG_SET_RAT_MODE_REQ,
MSG_ID_EMMREG_ATTACH_REQ,
MSG_ID_EMMREG_DETACH_REQ,
MSG_ID_EMMREG_RFOFF_REQ,
MSG_ID_EMMREG_SET_PREFERRED_BAND_REQ,
MSG_ID_EMMREG_EMC_ATTACH_REQ, // for IMS
MSG_ID_EMMREG_EPS_ATTACH_NEEDED_REJ_RSP,
MSG_ID_EMMREG_SET_IMS_VOICE_AVAILABILITY_REQ, // for IMS
MSG_ID_EMMREG_SET_IMS_VOICE_TERMINATION_REQ, // for IMS
#ifdef __MULTIPLE_PS__
MSG_ID_EMMREG_DATA_ALLOW_REQ,
#endif
MSG_ID_EMMREG_IMS_SCM_INFO_REQ, // for REL12 feature SCM

#ifdef __SGLTE__
MSG_ID_EMMREG_PS_SWITCH_REQ,
MSG_ID_EMMREG_PS_SWITCH_SUSPEND_REQ, 
MSG_ID_EMMREG_PS_SWITCH_RESUME_REQ, 
#endif /* __SGLTE__ */

MSG_ID_EMMREG_ACTIVE_SIM_INFO_REQ,
MSG_ID_EMMREG_DUPLEX_MODE_CHANGE_REQ,
MSG_ID_EMMREG_IMS_REG_STATUS_UPDATE_REQ,
MSG_ID_EMMREG_IMS_CALL_REG_INFO_REQ,

/****************************************************************************
 *                          Destination: EVAL (NWSEL to EVAL) 
 ****************************************************************************/
MSG_ID_NWSEL_EVAL_PLMN_SEARCH_REQ,
MSG_ID_NWSEL_EVAL_SEARCH_STATUS_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_PLMN_LIST_STATUS_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_SYS_INFO_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_REGN_STATUS_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_PLMN_LIST_REQ,
MSG_ID_NWSEL_EVAL_PLMN_LIST_STOP_REQ,
MSG_ID_NWSEL_EVAL_CSG_LIST_REQ,
MSG_ID_NWSEL_EVAL_CSG_LIST_STOP_REQ,
MSG_ID_NWSEL_EVAL_EQ_PLMN_LIST_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_HPLMN_INFO_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_DEACTIVATE_REQ,
MSG_ID_NWSEL_EVAL_NAS_CTXT_TRANSFER_REQ,
MSG_ID_NWSEL_EVAL_UEMODE_PARAM_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_PLMN_SEARCH_PREFERENCE_UPDATE_REQ, // for IMS
MSG_ID_NWSEL_EVAL_EMC_FPLMN_LIST_UPDATE_REQ, // for IMS
MSG_ID_NWSEL_EVAL_RESUME_REQ,
MSG_ID_NWSEL_EVAL_EUTRAN_CAP_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_INVALID_SIM_RECOVER_REQ,  // for __REL10__: t3245
MSG_ID_NWSEL_EVAL_L2C_TRANSFER_REQ,  // for C2K
MSG_ID_NWSEL_EVAL_C2L_TRANSFER_REQ,  // for C2K
MSG_ID_NWSEL_EVAL_C2K_IRAT_COMPLETE_REQ,    // for C2K
MSG_ID_NWSEL_EVAL_C2K_NORMAL_SERVICE_REQ,
MSG_ID_NWSEL_EVAL_PLMN_SEARCH_ABORT_REQ,
MSG_ID_NWSEL_EVAL_POWER_ON_PROTECTION_REQ,
MSG_ID_NWSEL_EVAL_CLEAR_T3346_EPLMN_REQ,
MSG_ID_NWSEL_EVAL_SET_MRU_REQ,
MSG_ID_NWSEL_EVAL_CLEAR_MRU_REQ,
MSG_ID_NWSEL_EVAL_EMC_SESSION_START_REQ,
MSG_ID_NWSEL_EVAL_EMC_SESSION_STOP_REQ,
MSG_ID_NWSEL_EVAL_CSG_AUTO_SEARCH_MODE_REQ,
MSG_ID_NWSEL_EVAL_C2K_FORCE_TO_LOCAL_DETACH_REQ, //for C2K when OP12 project
MSG_ID_NWSEL_EVAL_GLOBAL_MODE_CHANGE_START_REQ,
MSG_ID_NWSEL_EVAL_HVOLTE_MODE_CHANGE_REQ,
#ifdef __APN_CHANGE_REGISTRATION_SUPPORT__
MSG_ID_NWSEL_EVAL_IA_APN_CHANGE_REQ,
#endif

/****************************************************************************
 *                          Destination: EVAL (SMS to EVAL) 
 ****************************************************************************/
MSG_ID_SMS_EVAL_EST_REQ,
MSG_ID_SMS_EVAL_UNITDATA_REQ,


/****************************************************************************
 *                          Destination: EVAL (SMSAL to EVAL) 
 ****************************************************************************/
MSG_ID_SMSAL_EVAL_CBCH_REQ,
MSG_ID_SMSAL_EVAL_CB_UPDATE_REQ,
MSG_ID_SMSAL_EVAL_CB_MSG_REMOVAL_REQ,

/****************************************************************************
 *                          Destination: EVAL (ETC to EVAL)
 ****************************************************************************/
MSG_ID_EVAL_ETC_NW_RESET_UE_STORED_POS_INFO_IND, // for LPP

/****************************************************************************
 *                          Destination: EVAL (EMM to EVAL) 
 ****************************************************************************/
MSG_ID_EVAL_EMM_SET_RAT_MODE_CNF,
MSG_ID_EVAL_EMM_ATTACH_CNF,
MSG_ID_EVAL_EMM_DETACH_IND,
MSG_ID_EVAL_EMM_RFOFF_CNF,
MSG_ID_EVAL_EMM_CELL_INFO_UPDATE_IND,
MSG_ID_EVAL_EMM_NW_INFO_IND,
MSG_ID_EVAL_EMM_NW_ECC_IND,
MSG_ID_EVAL_EMM_PLMN_SEARCH_CNF,
MSG_ID_EVAL_EMM_SYS_INFO_IND,
MSG_ID_EVAL_EMM_REGN_RESULT_IND,
MSG_ID_EVAL_EMM_DISABLE_NW_LOSS_OPTIMIZE_IND,
MSG_ID_EVAL_EMM_NO_ACTION_IND,
MSG_ID_EVAL_EMM_PLMN_FOUND_IND,
MSG_ID_EVAL_EMM_PLMN_LIST_CNF,
MSG_ID_EVAL_EMM_PLMN_LIST_STOP_CNF,
MSG_ID_EVAL_EMM_CSG_LIST_CNF,
MSG_ID_EVAL_EMM_CSG_LIST_STOP_CNF,
MSG_ID_EVAL_EMM_OUT_OF_SERVICE_IND,
MSG_ID_EVAL_EMM_OUT_OF_SERVICE_FINISH_IND,
MSG_ID_EVAL_EMM_PLMN_LOSS_IND,
MSG_ID_EVAL_EMM_DEACTIVATE_CNF,
MSG_ID_EVAL_EMM_NAS_CTXT_TRANSFER_CNF,
MSG_ID_EVAL_EMM_SMS_EST_CNF,
MSG_ID_EVAL_EMM_SMS_EST_REJ,
MSG_ID_EVAL_EMM_SMS_UNITDATA_IND,
MSG_ID_EVAL_EMM_SMS_ERR_IND,
MSG_ID_EVAL_EMM_LPP_DATA_CNF, // for LPP
MSG_ID_EVAL_EMM_LPP_DATA_IND, // for LPP
MSG_ID_EVAL_EMM_LCS_DATA_CNF, // for LPP
MSG_ID_EVAL_EMM_LCS_DATA_IND, // for LPP
MSG_ID_EVAL_EMM_SIM_EPSNSC_INFO_IND,
MSG_ID_EVAL_EMM_SIM_EPSLOCI_INFO_IND,
MSG_ID_EVAL_EMM_AUTHENTICATE_IND,
MSG_ID_EVAL_EMM_PLMN_SEARCH_IND,
MSG_ID_EVAL_EMM_SIGNAL_APPEAR_IND,
MSG_ID_EVAL_EMM_EMERGENCY_STATUS_UPDATE_IND, // for IMS
MSG_ID_EVAL_EMM_EMC_ATTACH_CNF, // for IMS
MSG_ID_EVAL_EMM_EMC_DETACH_IND, // for IMS
MSG_ID_EVAL_EMM_NW_FEATURE_SUPPORT_IND, // for IMS
MSG_ID_EVAL_EMM_SRVCC_STATUS_UPDATE_IND, // for IMS
MSG_ID_EVAL_EMM_NW_REJECT_IND,
MSG_ID_EVAL_EMM_T3402_CHANGE_IND, // __REL10__: t3402
MSG_ID_EVAL_EMM_PERSISTENT_EPSB_REL_IND, // __REL10__: persistent EPSB
MSG_ID_EVAL_EMM_L2C_TRANSFER_CNF,  // for C2K
MSG_ID_EVAL_EMM_C2K_IRAT_ATTACH_RESULT_IND, // for C2K
MSG_ID_EVAL_EMM_DUPLEX_MODE_CHANGE_CNF, //for C2K
MSG_ID_EVAL_EMM_REL_IND,
MSG_ID_EVAL_EMM_SMS_UNITDATA_CNF,
MSG_ID_EVAL_EMM_SR_FAILURE_IND,
MSG_ID_EVAL_EMM_SR_REJECT_IND,
MSG_ID_EVAL_EMM_RACH_REJECT_IND,
MSG_ID_EVAL_EMM_CONNECTION_INFO_IND,
MSG_ID_EVAL_EMM_1XCSFB_CNF, //for C2K
MSG_ID_EVAL_EMM_1XCSFB_STOP_CNF, //for C2K
MSG_ID_EVAL_EMM_BARRING_STATUS_IND,
MSG_ID_EVAL_EMM_PLMN_RESTRICTION_CHANGE_IND,
MSG_ID_EVAL_EMM_C2K_CSFB_CNF, //for C2K
MSG_ID_EVAL_EMM_C2K_CSFB_STOP_CNF, //for C2K
MSG_ID_EVAL_EMM_C2K_CSFB_START_IND,
MSG_ID_EVAL_EMM_C2K_CSFB_EST_IND,
MSG_ID_EVAL_EMM_C2K_CSFB_STOP_IND,
MSG_ID_EVAL_EMM_IRAT_C2L_SUCCESS_NOTIFY_IND, //for C2K
MSG_ID_EVAL_EMM_SEARCH_INTERRUPT_EVENT_IND,

MSG_ID_EVAL_EMM_SIM_RESET_COMPLETE_IND,
#ifdef __SGLTE__
MSG_ID_EVAL_EMM_PS_SWITCH_CNF,
MSG_ID_EVAL_EMM_PS_SWITCH_SUSPEND_CNF, 
MSG_ID_EVAL_EMM_PS_SWITCH_IND, 
#endif/* __SGLTE__ */

MSG_ID_EVAL_EMM_CELL_BAND_INFO_UPDATE_IND,  // For VzW (VZ_REQ_e911_30203)
MSG_ID_EVAL_EMM_EMM_MSG_IND,                // For VzW VoWifi TC3.2
#ifdef __REMOTE_SIM__
MSG_ID_EVAL_EMM_RSIM_AUTH_FINISH_IND,
MSG_ID_EVAL_EMM_RSIM_ABORT_CNF,
#endif

MSG_ID_EVAL_EMM_CS_DOMAIN_NOT_AVAILABLE_IND,
#ifdef __GEMINI_WCDMA_WORLD_PHONE__
MSG_ID_EVAL_EMM_NEED_DUPLEX_MODE_CHG_IND,
#endif /*__GEMINI_WCDMA_WORLD_PHONE__*/

/****************************************************************************
 *                          Destination: EVAL (ESM to EVAL) 
 ****************************************************************************/
MSG_ID_EVAL_ESM_EPS_ATTACH_NEEDED_IND,
MSG_ID_EVAL_ESM_RAT_CHANGE_IND,
MSG_ID_EVAL_ESM_RAT_CHANGE_CNF,
MSG_ID_EVAL_ESM_EMC_ATTACH_IND, // for IMS
MSG_ID_EVAL_ESM_SRVCC_STATUS_UPDATE_IND, // for IMS
MSG_ID_EVAL_ESM_C2L_TRANSFER_CNF,  // for C2K


/****************************************************************************
 *                          Destination: EVAL (ERRC to EVAL) 
 ****************************************************************************/
MSG_ID_EVAL_ERRC_CB_RECONFIG_IND,
MSG_ID_EVAL_ERRC_CB_GS_CHANGE_IND,
MSG_ID_EVAL_ERRC_CELL_POWER_LEVEL_IND,
MSG_ID_EVAL_ERRC_ADJUST_MEAS_CNF,
MSG_ID_EVAL_ERRC_PWS_INFORMATION_IND,
MSG_ID_EVAL_ERRC_NBR_CELL_INFO_START_CNF,
MSG_ID_EVAL_ERRC_NBR_CELL_INFO_IND,
MSG_ID_EVAL_ERRC_NBR_CELL_INFO_STOP_CNF,
MSG_ID_EVAL_ERRC_GET_SSAC_PARAM_CNF, // for IMS
MSG_ID_EVAL_ERRC_CONNECTED_DRB_IND,
MSG_ID_EVAL_ERRC_TIME_INFO_IND,
#ifdef __VOLTE_SUPPORT__ 
MSG_ID_EVAL_ERRC_IMS_SYS_INFO_IND, //__TC01__
#endif
MSG_ID_EVAL_ERRC_EDDA_CNF,
MSG_ID_EVAL_ERRC_LTECA_BAND_SETTING_CNF,
MSG_ID_EVAL_ERRC_LTECA_MODE_SETTING_CNF,
MSG_ID_EVAL_ERRC_OMADM_UPDATE_CNF,
MSG_ID_EVAL_ERRC_MODULATION_UPDATE_CNF,  //__UL64QAM__

//#ifdef __VOLTE_SUPPORT__ 
MSG_ID_EVAL_ERRC_SRVCC_STATUS_UPDATE_IND, // for IMS
#ifdef __BCSFB__
MSG_ID_EVAL_ERRC_ERLM_REPORT_IND,
MSG_ID_EVAL_ERRC_ERLQ_REPORT_IND,
#endif
//#endif

#ifdef __SGLTE__
MSG_ID_EVAL_ERRC_TO_PEER_INFO_IND,
MSG_ID_EVAL_ERRC_CAPABILITY_CHANGE_IND,
#endif /* __SGLTE__ */
MSG_ID_EVAL_ERRC_STATE_IND,
MSG_ID_EVAL_ERRC_MRU_UPDATE_CNF,

//#ifdef __LTE_R11__
MSG_ID_EVAL_ERRC_CA_INFO_IND,
//#endif

MSG_ID_EVAL_ERRC_PCELL_INFO_IND,

MSG_ID_EVAL_ERRC_EVDO_PS_CONNECTION_STATUS_IND,
MSG_ID_EVAL_ERRC_1XRTT_PS_CONNECTION_STATUS_IND,

MSG_ID_EVAL_ERRC_OTHER_RAT_START_SNIFF_IND,


/****************************************************************************
 *                          Destination: EVAL (CISS to EVAL) 
 ****************************************************************************/
MSG_ID_CISS_EVAL_DATA_REQ,

/****************************************************************************/
MSG_ID_EVAL_CODE_END,

MODULE_MSG_END( MSG_ID_EVAL_CODE_TAIL )

#endif /* _EVAL_MSGID_H */
