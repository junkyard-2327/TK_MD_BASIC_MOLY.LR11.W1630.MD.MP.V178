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
 *   el2_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * 08 23 2017 chi-pin.yeh
 * [MOLY00268706] [LR11_MP5][CMCC HST MOS] binding VoLTE RB
 * [MP5] add new interface MSG_ID_EPDCP_ERLCDL_VOLTE_RB_IDX_REQ.
 *
 * 05 24 2017 pilin.lin
 * [MOLY00251598] [LR11][MP5] EL2 autonomous poll - interface
 *
 * 05 24 2017 pilin.lin
 * [MOLY00251598] [LR11][MP5] EL2 autonomous poll - interface
 *
 * 03 03 2017 hamilton.liang
 * [MOLY00232741] [MP5][EM][VzW][EM] EMBMS code flow change due to DHL logging API to avoid modem exception if EM was enabled(All of dhl API called by el2 task instead of ert lisr)
 *
 * 10 06 2016 head.hsu
 * [MOLY00206501] [91LWA][MP5][RATDM] rel-13 LWA feature check-in
 *
 * 08 30 2016 head.hsu
 * [MOLY00200197] New Feature UL64QAM on 6291
 * 1. EPDCP UL64QAM feature development (OA domain)
 *
 * 08 15 2016 shihyu.wang
 * [MOLY00196557] [EMAC][EM] VzW MDMI 2.7.2 OA interface
 *
 * 07 26 2016 hamilton.liang
 * [MOLY00193159] [MP5][EM][VzW][EMAC] EMBMS EM code check-in
 * 	
 * 	EMBMS EM code update for VzW requirement
 *
 * 05 13 2016 hamilton.liang
 * [MOLY00178640] Do not reset context after Gemini_Suspend-eMAC part
 *
 * 	.
 *
 * 04 28 2016 mingtsung.sun
 * [MOLY00175408] Multiple-PS/Remote-SIM interfaces phase2
 * [MT6291][MP3][Gemini] ePDCP interfaces for remote SIM: RD domain
 *
 * 03 16 2016 yu-po.wang
 * [MOLY00169038] [LAT2][MT6755][Jade M6][MP3][L+W][In-house FTA][Case Fail][VoLTE] TC_13.4.3.15 FAIL
 * .
 *
 * 12 02 2015 jy.ou
 * [MOLY00151336] [M6755] ERLC EM VzW requirement & enhancement
 *
 * 	.
 *
 * 12 01 2015 sc.tung
 * [MOLY00151000] [MT6755] SRVCC Enhancement
 *
 * 	.
 *
 * 11 04 2015 shengyi.ho
 * [MOLY00147987] [MT6291]Autonomous DRX
 * [audrx] sbp setting
 *
 * 07 16 2015 chen-wei.wang
 * [MOLY00118157] [TK6291]ERLC code maintain
 * ERLC status proh timer modification
 *
 * 07 06 2015 shengyi.ho
 * [MOLY00125586] [TK6291E1][MVTV-D][4G][TDD][TDD_MIMO_7.2]assert fail : el1tx.c 731
 * 1) add EMAC_EL2TASK_LOCK/UNLOCK_POWER_REQ
 *
 * 06 18 2015 mingtsung.sun
 * [MOLY00121332] [TK6291] 4G EAS low power check in
 * add QBM/EL2 power control messages for LogDMA
 *
 * 06 15 2015 sc.tung
 * [MOLY00121440] [TK6291] eL2 development check in CR
 * 	Add MSG_ID_ERRC_C_RNTI_RA_PROBING_REQ for probing req.
 *
 * 06 15 2015 mingtsung.sun
 * [MOLY00121332] [TK6291] 4G EAS low power check in
 * eL2 low power and ePDCP code sync: el2_msgid.h
 *
 * 06 03 2015 mingtsung.sun
 * [MOLY00118161] [MT6291] EPDCP CR Sync - Early reestablishment to prevent certain kind of VoLTE call drop
 * RD domain
 *
 * 03 18 2015 chen-wei.wang
 * [MOLY00099525] [TK6291] EMAC MDT feature check-in
 * interface file check-in
 *
 * 02 13 2015 mingtsung.sun
 * [MOLY00091822] RATDM reorganization
 * .
 *
 * 12 16 2014 yuting.chen
 * [MOLY00084807] [MT6291_DEV] EL2 Low Power Flow
 * .
 *
 * 12 12 2014 yk.liu
 * [MOLY00086350] [MT6291][L234 P2P] Enable EL2 PDU drop, ping no reply after 30min
 * 	.
 *
 * 11 11 2014 yiting.cheng
 * [MOLY00084042] [UMOLY] merge UMOLY_DEV to UMOLY trunk
 * .
 *
 * 10 28 2014 andrew.wu
 * [MOLY00079018] [MT6291_DEV] ePDCP batch I UT related modification
 * Merging
 *
 * 	//UMOLY_CBr/andrew.wu/MT6291_DEV_EPDCPDEVW1427P1/mcu/common/interface/sap/md/errc_msgid.h
 *
 * 	to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/sap/md/errc_msgid.h
 *
 * 09 18 2014 shengyi.ho
 * [MOLY00077592] [TK6291] code sync from CBr to TK6291_DEV - emac
 * .
 *
 * 08 26 2014 sh.yang
 * [MOLY00077290] [TK6291_DEV] ILM/Event scheduler wrapper for LISR2HISR removal
 * .
 *
 * 08 22 2014 jy.ou
 * [MOLY00076104] [TK6291] EMAC & ERLC UT framework and ERLC UT cases
 * .
 *
 * 08 21 2014 mingtsung.sun
 * [MOLY00072902] [TK6291][DEV] LTT unit test framework
 * Merging
 *
 *     //UMOLY_CBr/eric.hsieh/TK6291_DEV_ESL/mcu/common/interface/sap/...
 *
 *     to //UMOLY/DEV/TK6291_DEV/mcu/common/interface/sap/...
 *
 * 08 14 2014 andrew.wu
 * [MOLY00075397] [TK6291_DEV] code sync MOLY00072445 from MOLY to TK6291_DEV
 * Interface check-in for EPDCP_EMAC_LEAVE_DRX
 *
 * 07 30 2014 yiting.cheng
 * [MOLY00073830] [TK6291_DEV] check-in TK6291 modification
 * modify sap
 *
 * 07 29 2014 andrew.wu
 * [MOLY00073873] [TK6291_DEV] EPDCP-ERRC interfaces check-in
 * add ERRC_EPDCP_MTCH_PC_REQ
 *
 * 07 28 2014 nienteh.hsu
 * [MOLY00073836] [TK6291][ERRC][CHM] LTE-A CHM development code check-in
 *     .
 *
 * 01 15 2014 slifer.hsueh
 * [MOLY00053104] [MT6290E2][NAS RTD][MM][FDD] Assert fail: driver/l2copro/cipher/src/cipher_common.c 196 - L2COPRO
 * Merge codes related to L2 copro delay power off back to MOLY TRUNK in OA domain
 *
 * 01 06 2014 mf.jhang
 * [MOLY00051983] [MT6582LTE][WWFT][Germany][Vodafone]Ping RTT is more than benchmark
 * Add HOST_DATA_READY_IND
 *
 * 12 03 2013 lewis.yu
 * [MOLY00048832] power down/on in EL2 task context and refine the flow
 * .
 *
 * 09 26 2013 lewis.yu
 * [MOLY00039195] [MT6290] [Low Power] LTE L2 copro power down in LTE flight mode
 * .
 *
 * 07 12 2013 stanleyhy.chen
 * [MOLY00029602] [New Feature] NBR_CELL_INFO and TA_INFO related interfaces
 * TA_INFO and NBR_CELL_INFO interfaces for LPP feature
 *
 * 05 15 2013 moja.hsu
 * [MOLY00007625] Maintain code
 * add el2 message for ERT task to ERT HISR.
 *
 * 03 20 2013 jeremy.chen
 * [MOLY00007127] [MT7208] EL2 enhancement in MOLY
 * add IDC-related interface
 *
 * 02 26 2013 jeremy.chen
 * [MOLY00007127] [MT7208] EL2 enhancement in MOLY
 * add MSG_ID_ERLCUL_EPDCP_SRB_DATA_CNF.
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef _EL2_MSGID_H
#define _EL2_MSGID_H


MODULE_MSG_BEGIN( MSG_ID_EL2_CODE_BEGIN )

    /*------------------- EL2_MSG_CODE_BEGIN---------------------*/

    //////////////////////////////////////////////
    // Destination: EPDCP                       //
    //////////////////////////////////////////////

    // ERRC --> EPDCP
    MSG_ID_ERRC_EPDCP_CONFIG_REQ = MSG_ID_EL2_CODE_BEGIN,
#ifdef __REMOTE_SIM__
	MSG_ID_ERRC_EPDCP_SWITCH_VIRTUAL_CONNECTED_REQ,
#endif
    MSG_ID_ERRC_EPDCP_DCCH_DATA_REQ,
    MSG_ID_ERRC_EPDCP_DCCH_DATA_RES,
    MSG_ID_ERRC_EPDCP_TEST_REQ,
    MSG_ID_ERRC_EPDCP_CNTINFO_REQ,
    MSG_ID_ERRC_EPDCP_MTCH_PC_REQ,
    MSG_ID_ERRC_EPDCP_DETECTION_TIMER_START_REQ,

    // ERLC-UL --> EPDCP
    MSG_ID_ERLCUL_EPDCP_SRB_DATA_CNF,

    // EPDCP --> EPDCP
    MSG_ID_EPDCP_EPDCP_CTRL_PDU_IND,
    MSG_ID_EPDCP_EPDCP_DL_FLUSH_DONE_IND,

    // EMAC --> EPDCP
    MSG_ID_EMAC_EPDCP_TDM_START_IND,
    MSG_ID_EMAC_EPDCP_TDM_END_IND,
    MSG_ID_EMAC_EPDCP_MAX_UL_TB_IND,

    // EL1 --> EPDCP
    MSG_ID_EL1_EL2_PWR_DOWN_L2COPRO_IND,
    MSG_ID_EL1_EL2_WAKEUP_L2COPRO_IND,

//#ifdef __LWA_SUPPORT__
    // WLAN <--> EPDCP
    MSG_ID_WLAN_EPDCP_CTRL_MSG_IND,
//#endif

    //EMAC --> EL2
    MSG_ID_EMAC_EL2_ENABLE_HBM_TICK,
    MSG_ID_EMAC_EL2_DISABLE_HBM_TICK,

    //////////////////////////////////////////////
    // Destination: ERLC-UL                     //
    //////////////////////////////////////////////

    // ERRC --> ERLC-UL
    MSG_ID_ERRC_ERLCUL_CONFIG_REQ,
#ifdef __REMOTE_SIM__
	MSG_ID_ERRC_ERLCUL_SWITCH_VIRTUAL_CONNECTED_REQ,
#endif
    MSG_ID_ERRC_ERLCUL_SRB1_ACK_REQ,
    MSG_ID_ERRC_ERLCUL_END,

    // ETMR --> ERLC-UL
    MSG_ID_ETMR_ERLCUL_POLL_RETX_EXPRY,

    // EPDCP --> ERLC-UL
    MSG_ID_EPDCP_ERLCUL_DISCARD_REQ,
    MSG_ID_EPDCP_ERLCUL_VIP_DATA_NTF,
    MSG_ID_EPDCP_ERLCUL_AUTO_POLL_REQ,

    // ERLCDL --> ERLC-UL
    MSG_ID_ERLCDL_ERLCUL_STATUS_PDU_RCV,

    // EMAC --> ERLC-UL
    MSG_ID_EMAC_ERLCUL_STATUS_IND,
    MSG_ID_EMAC_ERLCUL_ALL_HARQ_CLOSED_IND,
    MSG_ID_EMAC_ERLCUL_TDM_START_IND,
    MSG_ID_EMAC_ERLCUL_TDM_END_IND,

    // ERT_WPR --> ERLC-UL
    MSG_ID_ERT_WPR_ERLCUL_TIMER_EXPIRY_NTF,

    //////////////////////////////////////////////
    // Destination: ERLC-DL                     //
    //////////////////////////////////////////////

    // ERRC --> ERLC-DL
    MSG_ID_ERRC_ERLCDL_CONFIG_REQ,
#ifdef __REMOTE_SIM__
	MSG_ID_ERRC_ERLCDL_SWITCH_VIRTUAL_CONNECTED_REQ,
#endif

    // ETMR --> ERLC-DL
    MSG_ID_ETMR_ERLCDL_REORDER_EXPRY,

    // EPDCP --> ERLC-DL
    MSG_ID_EPDCP_ERLCDL_REASM_MODE_CHNG,
    MSG_ID_EPDCP_ERLCDL_NEXT_SRB1_REQ,
    MSG_ID_EPDCP_ERLCDL_VOLTE_RB_IDX_REQ,

    // EMAC --> ERLC-DL
    MSG_ID_EMAC_ERLCDL_DATA_IND,

    MSG_ID_ERT_WPR_ERLCDL_TIMER_EXPIRY_NTF,
    MSG_ID_ERLCDL_POLL_EVENT_NTF,
    //////////////////////////////////////////////
    // Destination: EMAC                        //
    //////////////////////////////////////////////

    MSG_ID_ERRC_EMAC_CONFIG_REQ,
    MSG_ID_ERRC_EMAC_CCCH_DATA_REQ,
    MSG_ID_ERRC_EMAC_TA_INFO_REQ,
    MSG_ID_ERRC_EMAC_ESTFAIL_REPORT_REQ,
    MSG_ID_ERRC_EMAC_C_RNTI_RA_PROBING_REQ,
    MSG_ID_ERRC_EMAC_DRX_INC_GAP_REQ,
    MSG_ID_ERRC_EMAC_MEAS_GAP_IND,

    /// EPDCP --> EMAC
    MSG_ID_EPDCP_EMAC_LEAVE_DRX,
    MSG_ID_EPDCP_EMAC_VOLTE_RB_IDX_REQ,
	MSG_ID_EPDCP_EMAC_VOLTE_DATA_REQ,

    /// ERLC --> EMAC
    MSG_ID_ERLCUL_EMAC_DATA_REQ,
    MSG_ID_ERLCUL_EMAC_FORCE_HARQ_CLOSE_REQ,
    MSG_ID_ERLCDL_EMAC_LEAVE_DRX,
    MSG_ID_ERLCUL_EMAC_LEAVE_DRX,

    // EMAC --> EMAC
    MSG_ID_EMAC_EMAC_RAR_INT,
    MSG_ID_EMAC_EMAC_EARLY_INT,

    // EMAC_UT --> EMAC
    MSG_ID_EMAC_UT_EMAC_TEST_CMD,

    // EL1 --> EMAC
    MSG_ID_EMAC_EL1_PHY_INFO_IND,
    MSG_ID_EMAC_EL1_RA_GAP_STOP_CNF,
    MSG_ID_EMAC_EL1_RA_GAP_RESUME_CNF,
    MSG_ID_EMAC_EL1_RNTI_UPDATE_CNF,
    MSG_ID_EMAC_EL1_DRX_CTRL_CNF,
    MSG_ID_EMAC_EL1_SCELL_NOTIFY_CNF,
    MSG_ID_EMAC_EL1_HOST_DATA_CNF,
    MSG_ID_EMAC_EL1_HOST_DATA_READY_IND,
    MSG_ID_EMAC_EL1_RA_RESTART_IND,
    MSG_ID_EMAC_EL1_IDC_TDM_IND,

    //EMAC UT
#ifdef UNIT_TEST
    MSG_ID_EMAC_EL1_SIM_PS_SUBFRAME_IND,
    MSG_ID_EMAC_EL1_SIM_PS_SUBFRAME_RSP,
    MSG_ID_EMAC_EL1_SIM_PHR_IND,
    MSG_ID_EMAC_EL1_SIM_MSG4_IND,
    MSG_ID_EMAC_LMAC_SIM_INTERRUPT_IND,
    MSG_ID_EMAC_LMAC_TRIGGER_UL_LMAC_IND,
#endif

    // EL1TX --> EMAC
    MSG_ID_EMAC_EL1TX_PDCCH_IND,  // Remove in TK6291, change to SUBFRM_IND CCIRQ
    //MSG_ID_EMAC_EL1TX_RETX_INFO_IND,  // Remove in TK6291
    MSG_ID_EMAC_EL1TX_PHR_IND,  // Remove in TK6291, change to PHR_IND CCIRQ
    MSG_ID_EMAC_EL1TX_SR_TX_ABORT_IND,  // Remove in TK6291, change to SUBFRM_IND CCIRQ

    // HISR --> EMAC
    MSG_ID_EMAC_DL_CTRL_DATA_IND,
    MSG_ID_EMAC_DL_CCCH_DATA_IND,

    // ERT_WPR --> EMAC
    MSG_ID_ERT_WPR_EMAC_TIMER_EXPIRY_NTF,

    //////////////////////////////////////////////
    // Destination: ERT_WPR                     //
    //////////////////////////////////////////////

    //ERT_WPR --> ERT_WPR
    MSG_ID_ERT_WPR_ERT_WPR_ES_INSTR_PROC_NTF,
    MSG_ID_ERT_ERLCDL_WPR_ES_INSTR_PROC_NTF,
    //////////////////////////////////////////////
    // Destination: EL2                         //
    //////////////////////////////////////////////

    // EMAC --> EL2TASK
    MSG_ID_EMAC_EL2TASK_LOCK_POWER_REQ,
    MSG_ID_EMAC_EL2TASK_UNLOCK_POWER_REQ,
    MSG_ID_EMAC_EL2TASK_DL_TB_REPORT_IND,
    MSG_ID_EMAC_EL2TASK_EMBMS_EM_REPORT_IND,


    // EL2TASK --> EMAC
    MSG_ID_EL2TASK_EMAC_GEMINI_SUSPEND_REQ,
    MSG_ID_EL2TASK_EMAC_EMBMS_EM_REQ,

    // EVAL --> EMAC
    MSG_ID_EMAC_AUDRX_ENABLE_REQ,

    // ERLCUL --> EL2TASK
    MSG_ID_ERLCUL_EL2_HWB_REL_END_IND,

    // ERLC --> EL2TASK
    MSG_ID_ERLC_EL2TASK_EM_ON_REQ,
    MSG_ID_ERLC_EL2TASK_EM_OFF_REQ,

    // ERRC --> EL2TASK
    MSG_ID_ERRC_EL2TASK_CFG_POWER_ON_REQ,
    MSG_ID_ERRC_EL2TASK_CFG_POWER_OFF_REQ,

    // EMM --> EL2TASK
    MSG_ID_EMM_EL2TASK_CFG_POWER_ON_REQ,
    MSG_ID_EMM_EL2TASK_CFG_POWER_OFF_REQ,

    // QBM --> EL2TASK
    MSG_ID_QBM_EL2TASK_CFG_POWER_ON_REQ,
    MSG_ID_QBM_EL2TASK_CFG_POWER_OFF_REQ,
    /*------------------- EL2_MSG_CODE_END-----------------------*/

MODULE_MSG_END( MSG_ID_EL2_CODE_TAIL )

#endif /* _EL2_MSGID_H */
