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
 *   el1_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   LTE Layer 1 and Protocol Stack related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 07 26 2017 jasneetkaur.bhullar
 * [MOLY00266260] [CCI57_64_SM11_N] [DMS11162677] [NAM_US] UE does not receive CMAS alert messages broadcasted in WCDMA
 * New msg Id for CSR timer.
 *
 * 08 03 2016 david.tang
 * [MOLY00195295] [Jade Minus N0][TK][MP5]External (EE),0,0,99,/data/core/,1,modem,md1:(MCU_PCORE)  [ASSERT] file:pcore/driver/sleep_drv/internal/src/ostd.c line:2436  p1:0x00000000  p2:0x00000000  p3:0x00000000  ELM r/wlat:PASS
 * .[irt] interface - msgid
 *
 * 08 02 2016 sl.hsu
 * [MOLY00169041] [MT6755][EL1] implement VzW SRV measurement command and report
 * [VzW][Ant Test] EL1C part (OA domain)
 *
 * 04 18 2016 cp.chiang
 * [MOLY00172964] [MT6291]Add Android M LCE feature support in LTE part1 - interface
 * DL throughput estimation for LCE
 *
 * 04 11 2016 carol.lin
 * [MOLY00172045] Multiple-PS/Remote-SIM interfaces
 *
 * 02 04 2016 david.tang
 * [MOLY00164304] [MT6755][EL1CH] deliver intra NeighCellConfig to L1D
 * .el1-errc interface for intra NeighCellConfig
 *
 * 02 03 2016 ali.su
 * [MOLY00164031] [VzW]LTE SIB8/16 for AGPS fine time aiding
 * (LR11_MP3) SIB for AGPS (el1 message).
 *
 * 01 11 2016 hyper.wang
 * [MOLY00159602] [6291 IDC] Remove redundant code
 * 	
 * 	.
 *
 * 01 04 2016 david.tang
 * [MOLY00154368] [MT6755][L+W][Overnight][FDD][MTBF][L1CORE] Assert fail: errc_conn_main.c 849 0x22 0x0 0x0 ?ERRC
 * .[el1ch] change ho abort interface - oa part
 *
 * 10 29 2015 carol.lin
 * [MOLY00147437] [MT6291][LR11] EL1 force gap mode modifications and Scell update info API
 *
 * 10 29 2015 carol.lin
 * [MOLY00139263] [TMO][DCR] specific cell delete - EL1 part
 *
 * 09 22 2015 ali.su
 * [MOLY00142830] [JADE][EL1] AGNSS time sync feature
 * (LR11) AGNSS time sync feature (OA).
 *
 * 09 17 2015 ali.su
 * [MOLY00134637] [Jade][TK6291][New Feature][ADT] Check in ADT new feature into LR11
 * (LR11) add EL1_L1ADT_SET_RAT_IND interface.
 *
 * 09 02 2015 yenchih.yang
 * [MOLY00099648] [VoLTE] Voice quality patch - ERRC
 * .
 *
 * 08 17 2015 shao-kai.hsu
 * [MOLY00137575] [MT6291] EL1C LPP OS timer usage modification
 * .
 *
 * 08 05 2015 yr.chiang
 * [MOLY00087893] [MT6291] Merge EL1C/EL1D from xL1SIM to MT6291_DEV
 * update ADT header files
 *
 * 08 03 2015 carol.lin
 * [MOLY00134637] [Jade][TK6291][New Feature][ADT] Check in ADT new feature into LR11
 * ADT.
 *
 * 08 01 2015 yr.chiang
 * [MOLY00087893] [MT6291] Merge EL1C/EL1D from xL1SIM to MT6291_DEV
 * 91 L1S TPC info acquisition
 *
 * 05 28 2015 hyper.wang
 * [MOLY00074164] 6291 IDC Development
 * 	.
 *
 * 04 28 2015 shihyao.wang
 * [MOLY00109540] [EL1IT] 91 MoDIS IT code
 * 91 MoDIS integration.
 *
 * 03 02 2015 ms.lin
 * [MOLY00070265] MT6291 code change: add new sap id
 * 	.
 *
 * 10 27 2014 daron.lu
 * [MOLY00081763] [MT6291] Merge EL1C/EL1D to UMOLY
 * 	.
 *
 * 08 07 2014 yr.chiang
 * [MOLY00072292] 6291 EL1C Development
 * sync MOLY to UMOLY
 *
 * 08 04 2014 lewis.yu
 * [MOLY00073990] [LPP CP] LPP code check-in for OTDOA feature
 * .
 *
 * 07 15 2014 kuan-ting.lee
 * [MOLY00055217] EL1 IDC development
 * IDC msg : pin type lte con, and lte con timer
 *
 * 06 23 2014 popcafa.shih
 * [MOLY00069383] [VoLTE][Low power improvement]
 * move recal to task.
 *
 * 06 13 2014 popcafa.shih
 * [MOLY00069383] [VoLTE][Low power improvement]
 * add new sap.
 *
 * 05 21 2014 dennis.weng
 * [MOLY00066251] ICS may camp on a cell not having largest RSRP in TDD mode
 * specific measurement el1 sap
 *
 * 04 28 2014 lewis.yu
 * [MOLY00063876] [MT6595] MT6595 DVFS support
 * .
 *
 * 02 20 2014 lewis.yu
 * [MOLY00056695] [LTE R9] disallow sleep (prevent power down L2 copro) during evaluation phase of HO/CCR/IRCR/redirection from LTE
 * .
 *
 * 02 11 2014 yr.chiang
 * [MOLY00055707] [MOLY00054538] [MT6290E2][EL1] EL1 Trace update for EM Customer Release (phase 2)
 * .
 *
 * 01 29 2014 carol.lin
 * [MOLY00054688] [MT6290E2][TDD] inter-cell HO took too much time
 *
 * 01 22 2014 c-h.huang
 * [MOLY00054324] [4G Gemini][Merge] MOLY.MM.GEMINI.DEV Merge back to MOLY
 * .
 *
 * 12 03 2013 lewis.yu
 * [MOLY00048832] power down/on in EL2 task context and refine the flow
 * .
 *
 * 11 25 2013 vend_david.tang
 * [MOLY00047275] [MT6290E2][EL1 CH] CPHY_CFG_REQ/CNF guard timer.
 * Add a 1s guard timer for cphy_cfg_req/cnf.
 *
 * 11 13 2013 ty.shen
 * [MOLY00046027] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * .
 *
 * 11 06 2013 yr.chiang
 * [MOLY00045089] [MT6290E1][IOT][Huawei][LTE][Uu_ANR_001] Assert: l2lmac_drv.c 234 -L2COPRO
 * add csi_srs_admission_2nd_ntf for EMAC
 *
 * 11 01 2013 vend_hyper.wang
 * [MOLY00014152] EL1 IDC development
 * 	(Revise IPC messages).
 *
 * 10 30 2013 vend_hyper.wang
 * [MOLY00014152] EL1 IDC development
 * Add new SW message ID
 *
 * 10 29 2013 ms.lin
 * [MOLY00041363] [MT6290E1][Design Change] Neighbor BCCH flow change
 *  .
 *
 * 10 11 2013 lewis.yu
 * [MOLY00040824] [MT6290][EL1] PHS suspend IRT gap for MAC_DRX_TRACK
 * .
 *
 * 10 11 2013 ms.lin
 * [MOLY00040824] [MT6290][EL1] PHS suspend IRT gap for MAC_DRX_TRACK
 *  .
 *
 * 08 26 2013 carol.lin
 * [MOLY00034285] [MT6290E1][EL2 RTD] Assert fail: modem/lte_sec/el1/meas/src/el1_meas_ctrl.c 5783 after attach and pinging
 * HOST_DATA_REQ is rcv by CH
 *
 * 08 16 2013 c-h.huang
 * [MOLY00033989] [MT6290][EL1] MSG ID naming typo error fix
 * .
 *
 * 08 15 2013 daron.lu
 * [MOLY00031340] [MT6290E1][GCF][RRM][36521-3][TC 9.1.1/9.1.3]config long DRX, UE can't measure intra/inter freq cell
 * .
 *
 * 08 15 2013 daron.lu
 * [MOLY00031340] [MT6290E1][GCF][RRM][36521-3][TC 9.1.1/9.1.3]config long DRX, UE can't measure intra/inter freq cell
 * .
 *
 * 07 04 2013 vend_hyper.wang
 * [MOLY00026065] EL1 IDC unit test case development
 * (add new msgid).
 *
 * 05 22 2013 vend_david.tang
 * [MOLY00007804] [EL1 CH]
 * add timer expiry msg for sch.
 *
 * 05 07 2013 vend_hyper.wang
 * [MOLY00006577] EL1 MEAS development (update MODIS AUTO EL1 IT).
 *
 * 03 30 2013 jerry.ho
 * [MOLY00010951] LTE L1S relative files merge to MOLY
 *
 * 03 05 2013 elly.wei
 * [MOLY00007073] [MT7208][EL1] Sleep mode support
 * <saved by Perforce>
 * Re-arrange the MSG ID for sleep mode related messages.
 *
 * 03 04 2013 ms.lin
 * [MOLY00006061] [Design change]LTE EL1 DRV/TSTM/PHS code change
 * .
 *
 * 01 28 2013 ms.lin
 * [MOLY00006061] [Design change]LTE EL1 DRV/TSTM/PHS code change
 * .
 *
 * 11 08 2012 ms.lin
 * [MOLY00005322] TATAKA merge to MOLY
 * .
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef _EL1_MSGID_H
#define _EL1_MSGID_H

MODULE_MSG_BEGIN( MSG_ID_EL1_CODE_BEGIN )

/****************************************************************************
 *                          Destination: CH
 ****************************************************************************/
MSG_ID_ERRC_EL1_CPHY_CFG_REQ            = MSG_ID_EL1_CODE_BEGIN,
MSG_ID_EL1_CH_MSG_START                 = MSG_ID_ERRC_EL1_CPHY_CFG_REQ,
MSG_ID_ERRC_EL1_RL_MONITOR_REQ,
MSG_ID_ERRC_EL1_SPECIFIC_CELL_SEARCH_REQ,
MSG_ID_ERRC_EL1_SPECIFIC_CELL_DELETE_NTF,
MSG_ID_ERRC_EL1_ABORT_HO_REQ,
#if defined (__MULTIPLE_PS__)
MSG_ID_ERRC_EL1_VIRTUAL_MODE_REQ,
#endif
MSG_ID_ERRC_EL1_L1S_TEST_PARA_REQ,
MSG_ID_ERRC_EL1_L1S_TEST_PARA_CNF,
MSG_ID_EMAC_EL1_RA_GAP_STOP_REQ,
MSG_ID_EMAC_EL1_RA_GAP_RESUME_REQ,
MSG_ID_EMAC_EL1_DRX_CTRL_REQ,
MSG_ID_EMAC_EL1_HOST_DATA_REQ,
MSG_ID_EMAC_EL1_MSI_NOTIFY,
MSG_ID_ETMR_EL1_DRX_SLEEP_TMR_EXPIRY,
MSG_ID_ETMR_EL1_CPHY_CFG_TMR_EXPIRY,
MSG_ID_GAS_EL1_ENABLE_B39_REQ,
MSG_ID_GAS_EL1_DISABLE_B39_REQ,
MSG_ID_LAS_EL1_PCH_RCV_NTF,
MSG_ID_HAL_EL1_GPS_TIME_SYNC_REQ,
MSG_ID_HAL_EL1_GPS_TIME_SYNC_IND,
/* Internal message */
MSG_ID_EL1_IRT_CH_PARAM_CHG_CNF,
MSG_ID_EL1_IRT_CH_GAP_SUSP_CNF,
MSG_ID_EL1_IRT_CH_BCCH_CNF,
MSG_ID_EL1_IRT_CH_AUTO_GAP_STOP_REQ,
MSG_ID_EL1_IRT_CH_AUTO_GAP_AVAIL_IND,
MSG_ID_EL1_PHS_CH_DL_BC_ASSIGN_RLT,
//MSG_ID_EL1_PHS_CH_CTRL_CNF,
//MSG_ID_EL1_PHS_CH_CONFLICT_IND,
//MSG_ID_EL1_PHS_CH_REL_ALL_IND,
MSG_ID_EL1_MEAS_CH_MEAS_MODE_CHNG_CNF,
MSG_ID_EL1_LPP_CH_PRS_INFO_UPDT_NTF,
MSG_ID_ERRC_EL1_RX_POLL_DATA_IND,
MSG_ID_ERRC_EL1_SIB_FRAME_SYNC_REQ, //[20151209 Ali] SIB for AGPS
MSG_ID_ERRC_EL1_NEIGHBOR_CELL_CONFIG_NTF,

/****************************************************************************
 *                          Destination: PHS
 ****************************************************************************/
/* Internal message */
MSG_ID_ERRC_EL1_CHANNEL_PROTECT_START_REQ,
MSG_ID_EL1_PHS_MSG_START                = MSG_ID_ERRC_EL1_CHANNEL_PROTECT_START_REQ,
MSG_ID_ERRC_EL1_CHANNEL_PROTECT_STOP_REQ,
MSG_ID_ERRC_EL1_DATA_SERVICE_IND,
MSG_ID_AP_MD_LTE_AUTO_GAP_REQ,

/* Internal message */
//MSG_ID_EL1_IRT_PHS_RAT_CHG_REQ,
//MSG_ID_EL1_CH_PHS_CTRL_REQ,
//MSG_ID_EL1_CH_PHS_DRX_CTRL_REQ,
//MSG_ID_EL1_CH_PHS_DRX_CYCLE_IND,
//MSG_ID_EL1_CSR_PHS_CTRL_REQ,
//MSG_ID_EL1_MEAS_PHS_CTRL_REQ,
//MSG_ID_EL1_MEAS_PHS_PRS_CTRL_REQ,
//MSG_ID_EL1_PHS_PHS_ABORT_IND,
//MSG_ID_EL1_PHS_PHS_CTRL_RSP,
//MSG_ID_EL1_IRT_PHS_MEAS_GAP_REQ,
//MSG_ID_EL1_IRT_PHS_GAP_CANCEL_CNF,
//MSG_ID_EL1_IRT_PHS_GAP_CTRL_REQ,
//MSG_ID_EL1_IRT_PHS_GAP_CANCEL_REQ,
//MSG_ID_EL1_IRT_PHS_GAP_RESUME_IND,
//MSG_ID_EL1_IRT_PHS_AUTO_GAP_IND,
//MSG_ID_EL1_IRT_PHS_AUTO_GAP_END_IND,
//MSG_ID_EL1_IRT_PHS_GAP_SUSPEND_CNF,
//MSG_ID_EL1_MEAS_PHS_IRT_CTRL_REQ,

/****************************************************************************
 *                          Destination: IRT
 ****************************************************************************/
MSG_ID_ERRC_EL1_SET_RAT_REQ,
MSG_ID_EL1_IRT_MSG_START                = MSG_ID_ERRC_EL1_SET_RAT_REQ,
MSG_ID_ERRC_EL1_AUTO_GAP_ON_REQ,
MSG_ID_ERRC_EL1_AUTO_GAP_OFF_REQ,
MSG_ID_ERRC_EL1_LOCK_SLEEP_NTF,

/* Internal message */
MSG_ID_EL1_CSR_IRT_GAP_REQ,
//MSG_ID_EL1_PHS_IRT_RAT_CHG_CNF,
MSG_ID_EL1_CH_IRT_PARAM_CHG_REQ,
MSG_ID_EL1_CH_IRT_RECONFIG_DONE_IND,
MSG_ID_EL1_CH_IRT_GAP_SUSP_REQ,
MSG_ID_EL1_CH_IRT_GAP_RESUME_IND,
MSG_ID_EL1_CH_IRT_BCCH_REQ,
MSG_ID_EL1_CH_IRT_AUTO_GAP_STOP_CNF,
MSG_ID_EL1_MEAS_IRT_MEASURE_REQ,
MSG_ID_EL1_MEAS_IRT_MEASURE_DONE_IND,
MSG_ID_EL1_MEAS_IRT_GAP_SUSP_REQ,
MSG_ID_EL1_MEAS_IRT_GAP_RESUME_IND,
//MSG_ID_EL1_PHS_IRT_DRX_TICK_IND,
//MSG_ID_EL1_PHS_IRT_GAP_PERIOD_IND,
//MSG_ID_EL1_PHS_IRT_GAP_CANCEL_REQ,
//MSG_ID_EL1_PHS_IRT_GAP_CTRL_CNF,
//MSG_ID_EL1_PHS_IRT_GAP_CANCEL_CNF,
//MSG_ID_EL1_PHS_IRT_AUTO_GAP_RES,
//MSG_ID_EL1_PHS_IRT_GAP_SUSPEND_REQ,
//MSG_ID_EL1_PHS_IRT_GAP_RESUME_IND,

/****************************************************************************
 *                          Destination: MEAS
 ****************************************************************************/
MSG_ID_ERRC_EL1_RADIO_MEASURE_REQ,
MSG_ID_EL1_MEAS_MSG_START               = MSG_ID_ERRC_EL1_RADIO_MEASURE_REQ,
MSG_ID_ERRC_EL1_SPECIFIC_MEASURE_REQ,
MSG_ID_ERRC_EL1_HPS_QUALIFY_CELL_NTF,
MSG_ID_ERRC_EL1_MEASURE_EVENT_NTF,
MSG_ID_ERRC_EL1_OOS_TRIG_SEARCH_NTF,
MSG_ID_ETMR_EL1_SRV_TMR_EXPIRY,
MSG_ID_ETMR_EL1_LIFE_TMR_EXPIRY,
MSG_ID_ETMR_EL1_VZW_TMR_EXPIRY,

/* Internal message */
MSG_ID_EL1_IRT_MEAS_GAP_CFG_IND,
MSG_ID_EL1_IRT_MEAS_MEAS_GAP_REQ,
MSG_ID_EL1_IRT_MEAS_BASE_TIME_IND,
MSG_ID_EL1_IRT_MEAS_MODE_CHNG_NTF,
MSG_ID_EL1_IRT_MEAS_GAP_SUSP_CNF,
MSG_ID_EL1_IRT_MEAS_RAT_STATUS_IND,

//MSG_ID_EL1_PHS_MEAS_SCHDL_IND,
//MSG_ID_EL1_PHS_MEAS_CTRL_CNF,
//MSG_ID_EL1_PHS_MEAS_CONFLICT_IND,
MSG_ID_EL1_CH_MEAS_RL_PROBLEM_NTF,
MSG_ID_EL1_CH_MEAS_RL_RECOVER_NTF,
MSG_ID_EL1_CH_MEAS_MEAS_MODE_CHNG_REQ,

/****************************************************************************
 *                          Destination: LPP
 ****************************************************************************/
MSG_ID_LPP_EL1_OTDOA_ASSIST_DATA_REQ,
MSG_ID_EL1_LPP_MSG_START               = MSG_ID_LPP_EL1_OTDOA_ASSIST_DATA_REQ,
MSG_ID_LPP_EL1_OTDOA_ASSIST_DATA_CLEAR_NTF,
MSG_ID_LPP_EL1_OTDOA_MEAS_REQ,
MSG_ID_LPP_EL1_OTDOA_MEAS_ABORT_REQ,
MSG_ID_ETMR_EL1_OTDOA_TMR_EXPIRY,

/* Internal message */

/****************************************************************************
 *                          Destination: CSR
 ****************************************************************************/
MSG_ID_ERRC_EL1_CARRIER_SEARCH_REQ,
MSG_ID_EL1_CSR_MSG_START                = MSG_ID_ERRC_EL1_CARRIER_SEARCH_REQ,
MSG_ID_ERRC_EL1_RSSI_SNIFFER_REQ,
MSG_ID_ETMR_EL1_CSR_TMR_EXPIRY,

/* Internal message */
//MSG_ID_EL1_PHS_CSR_CTRL_CNF,
//MSG_ID_EL1_PHS_CSR_CONFLICT_IND,

/****************************************************************************
 *                          Destination: IDC
 ****************************************************************************/
MSG_ID_ETMR_EL1_TDM_TMR_EXPIRY,
MSG_ID_EL1_IDC_MSG_START                = MSG_ID_ETMR_EL1_TDM_TMR_EXPIRY,
MSG_ID_ETMR_EL1_IDC_IND_TMR_EXPIRY,
MSG_ID_ETMR_EL1_IDC_SWMSG_RESEND_TMR_EXPIRY,
MSG_ID_ETMR_EL1_IDC_SWMSG_DELAY_TMR_EXPIRY,
MSG_ID_EL1_IDC_MSG_END,

/****************************************************************************
 *                          Destination: SM
 ****************************************************************************/
MSG_ID_EL1_EL2_WAKEUP_L2COPRO_RES,
MSG_ID_EL1_SM_MSG_START                 = MSG_ID_EL1_EL2_WAKEUP_L2COPRO_RES,
MSG_ID_EL1_MSG_END,                     //END of EL1 Messages

/****************************************************************************
 *                          Destination: TX
 ****************************************************************************/
MSG_ID_EL1_TX_TX_CFG_IND,
MSG_ID_EL1_TX_MSG_START                 = MSG_ID_EL1_TX_TX_CFG_IND,

/****************************************************************************
 *                          EMAC -> EL1-TX
 ****************************************************************************/


/****************************************************************************
 *                          Destination: EL1_IT
 ****************************************************************************/
MSG_ID_ETMR_XL1_GAP_TMR,
MSG_ID_EL1_TX_IT_CC_INTERRUPT_IND,
MSG_ID_TC_AUTO_TIMER_EXPIRY_IND,

/****************************************************************************
 *                          Tool <-> EL1-DRV
 ****************************************************************************/


/****************************************************************************/

/****************************************************************************
 *                          EL1D <-> EL1C
 ****************************************************************************/
MSG_ID_EL1_EL1_TASK_WAKE_IND,
MSG_ID_EL1_L1ADT_ENTER_CONNECTED_REQ,
MSG_ID_EL1_L1ADT_ENTER_CONNECTED_CNF,
MSG_ID_EL1_L1ADT_LEAVE_CONNECTED_REQ,
MSG_ID_EL1_L1ADT_LEAVE_CONNECTED_CNF,
MSG_ID_EL1_L1ADT_SET_RAT_IND,

/****************************************************************************
 *                          EL4C <-> EL1C
 ****************************************************************************/
MSG_ID_L4C_EL1_LCE_REPORT_START_REQ,
MSG_ID_L4C_EL1_LCE_REPORT_STOP_REQ,
MSG_ID_L4C_EL1_LCE_REPORT_PULLDATA_REQ,
MSG_ID_L4C_EL1_LCE_REPORT_CNF,
MSG_ID_L4C_EL1_LCE_REPORT_IND,

MODULE_MSG_END( MSG_ID_EL1_CODE_TAIL )

#endif /* _EL1_MSGID_H */

