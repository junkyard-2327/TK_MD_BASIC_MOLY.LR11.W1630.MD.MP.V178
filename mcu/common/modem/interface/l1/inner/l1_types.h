/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


 /*******************************************************************************
 * Filename:
 * ---------
 *   l1_types.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Layer1 global types
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.21  $
 * $Modtime:   Aug 05 2005 10:12:46  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/common/l1_types.h-arc  $
 *
 * 12 01 2015 terence.chen
 * [MOLY00151131] [SRVCC] Check in GL1 code for SRVCC
 * Use auto gap to decode bsic for SRVCC acceleration
 *
 * 10 08 2015 sy.yeh
 * [MOLY00143141] [RRM][Anritsu][2.21.02][EE]:Assert?file:l1core/modem/gl1/l1c/m11501.c line:1758.
 *
 * 09 23 2015 sy.yeh
 * [MOLY00142997] [L+W][LR11]  GL1 integration.
 *
 * 09 16 2015 sy.yeh
 * [MOLY00142108] [LWCG] GL1 development for LWCG mode.
 *
 * 09 11 2015 arkadeep.sett
 * [MOLY00141549] GL1 CR for submitting the feature Quick MCC Search
 *
 * 09 07 2015 mohamed.idhrees
 * [MOLY00140236] modem warning removal in LR11
 *
 * 09 01 2015 deepti.varadarajan
 * [MOLY00140055] Compilation error fixes for L+W build
 *
 * 09 01 2015 deepti.varadarajan
 * [MOLY00140055] [LR11] Compilation error resolution
 * 	Compilation error fixes for L+W build
 *
 * 07 06 2015 arkadeep.sett
 * [MOLY00118688] Cancel GAP since extra TD margin is no longer avilable after TS reconfig
 *
 * 06 12 2015 arkadeep.sett
 * [MOLY00121091] Fix build error in UMOLY "PowerScanPurpose is not defined"
 * Fix build error - Define the enum PowerScanPurpose
 *
 * 06 12 2015 arkadeep.sett
 * Fix build error in LWModis build
 *
 * 05 29 2015 rick.wu
 * [MOLY00111246] L+W MM Gemini+ xL1SIM Changes to UMOLY trunk
 * .
 *
 * 05 29 2015 rick.wu
 * [MOLY00116464] [UMOLY] 2G L1 TAS Check in
 * .
 *
 * 03 17 2015 rick.wu
 * [MOLY00093175] [Denali-1][MT6735][Stage-1][CSFB DSDS][Local FT][India-Delhi][AWSP][Assert] file:m11101.c line:1047
 * .
 *
 * 03 04 2015 terence.chen
 * [MOLY00097635] [UBIN] Phase 2 check in
 * 	Check-in GL1C part of UBIN phase 2.
 *
 * 12 03 2014 terence.chen
 * [MOLY00083240] [UMOLY] Check-in MOLY and universal bin into UMOLY
 * Fix build error.
 *
 * 11 30 2014 yungshian.lai
 * [MOLY00052308] [L1D][Modify] FT/L1D dual-core modem interface development
 * - include nsft list mode[MOLY00080536].
 *
 * 11 30 2014 yungshian.lai
 * [MOLY00052308] [L1D][Modify] FT/L1D dual-core modem interface development
 * - include nsft list mode[MOLY00080536].
 *
 * 11 30 2014 yungshian.lai
 * [MOLY00052308] [L1D][Modify] FT/L1D dual-core modem interface development
 * - include nsft list mode[MOLY00080536].
 *
 * 11 11 2014 sy.yeh
 * [MOLY00069896] ??UM???????????.
 *
 * 11 04 2014 terence.chen
 * [MOLY00083240] [UMOLY] Check-in MOLY and universal bin into UMOLY
 * Check-in L1C part of universal bin.
 *
 * 04 08 2014 william.lin
 * [MOLY00052426] [GL1AC] U3G merge check-in.
 *
 * 01 27 2014 sy.yeh
 * [MOLY00054623] Delay BSIC decoding if not all ARFCN measured.(1) use all gaps for rssi if no bsic in queue (2) inform GAS if all arfcn in balist are measured
 *
 * 01 22 2014 rick.wu
 * [MOLY00054324] [4G Gemini][Merge] MOLY.MM.GEMINI.DEV Merge back to MOLY
 * .
 *
 * 07 12 2013 hsin-chun.chen
 * [MOLY00009928] 3G Gemini2.0+ Check-in Remove debug traces
 * .
 *
 * 04 11 2013 sy.yeh
 * [MOLY00013948] [MT6290 PO admit] Check in AST3002 & protocol code for 6290 MULTI_MODE_TDS project. [GL1] update MultiMode code.
 *
 * 03 20 2013 sy.yeh
 * [MOLY00005322] TATAKA merge to MOLY
 * [GL1] fix build errors.
 *
 * 03 08 2013 hsin-chun.chen
 * [MOLY00011276] [L1C] Merge code from WR8+PLUS to MOLY
 *
 * 03 08 2013 hsin-chun.chen
 * Merge WR8+PLUS to MOLY.
 *
 * 03 04 2013 rick.wu
 * Merge WR8 into Moly
 *
 * 02 20 2013 hsin-chun.chen
 * [MOLY00009928] 3G Gemini2.0+ Check-in
 * Disable debug trace in TDD.
 *
 * 02 06 2013 hsin-chun.chen
 * [MOLY00009928] 3G Gemini2.0+ Check-in
 * .
 *
 * 01 21 2013 hsin-chun.chen
 * [MOLY00007943] TX Power Control by Voltage Compensation Feature
 * .
 * 
 * 10 12 2012 sy.yeh
 * [MOLY00004749] [SLIM] wrap CBCh related code by __CB__
 * .
 * 
 * 10 08 2012 rick.wu
 * [MOLY00003141] [Additional SB] New additional SB check in and modify
 * TDD doesn't support additional SB temporarily
 * 
 * 09 27 2012 rick.wu
 * [MOLY00004249] [WR8.TDD][MT6517+3001][Sanity]Assert fail: l1_rtb_tdd.c 522 0x0 0x0 0x0 - (LISR)L1SM handler
 * Turn off additional SB on TD projects
 * 
 * 09 13 2012 rick.wu
 * [MOLY00003141] [Additional SB] New additional SB check in and modify
 * Turn on new additional SB on 3G Gemini
 * 
 * 09 05 2012 rick.wu
 * [MOLY00003141] [Additional SB] New additional SB check in and modify
 * 
 * .
 *
 * 07 04 2012 terence.chen
 * [MOLY00000249] [3G Gemini Improvement] SE2 check in improvement code.
 * .
 *
 * 06 20 2012 rick.wu
 * removed!
 * .
 *
 * 05 21 2012 samuel.yang
 * removed!
 * .
 *
 * 05 07 2012 terence.chen
 * removed!
 * .
 *
 * 05 07 2012 cs.wu
 * removed!
 * .
 *
 * 01 11 2012 sy.yeh
 * removed!
 * .
 *
 * 01 06 2012 sy.yeh
 * removed!
 * .
 *
 * 12 19 2011 terence.chen
 * removed!
 * .
 *
 * 12 06 2011 terence.chen
 * removed!
 * .
 *
 * 12 05 2011 terence.chen
 * removed!
 * .
 *
 * 12 02 2011 nick.tsao
 * removed!
 * .
 *
 * 11 21 2011 jp.lien
 * removed!
 * .
 *
 * 11 14 2011 lewis.yu
 * removed!
 * .
 *
 * 11 09 2011 terence.chen
 * removed!
 * .
 *
 * 08 26 2011 cy.huang
 * removed!
 * In 3G gemini 2.0 3G transfer case, RTB do not suspend PM according to pm reservedlength.
 *
 * 08 26 2011 cy.huang
 * removed!
 * In 3G gemini 2.0 3G transfer case, RTB do not suspend PM according to pm reservedlength.
 *
 * 06 17 2011 jeff.lee
 * removed!
 * .
 *
 * 06 08 2011 samuel.yang
 * removed!
 * .
 *
 * 06 08 2011 jp.lien
 * removed!
 * .
 *
 * 05 11 2011 samuel.yang
 * removed!
 * .
 *
 * 01 26 2011 sean.yang
 * removed!
 * .
 *
 * 01 19 2011 sy.yeh
 * removed!
 * roll back.
 *
 * 12 15 2010 jp.lien
 * removed!
 * .
 *
 * 12 14 2010 sy.yeh
 * removed!
 * .
 *
 * 12 01 2010 lewis.yu
 * removed!
 * .
 *
 * 11 24 2010 lewis.yu
 * removed!
 * .
 *
 * 09 23 2010 nick.tsao
 * removed!
 * .
 *
 * 09 22 2010 sy.yeh
 * removed!
 * .
 *
 * 08 31 2010 samuel.yang
 * removed!
 * .
 *
 * 08 02 2010 nick.tsao
 * removed!
 * .
 *
 * 08 01 2010 nick.tsao
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * For CSMM, we don't need create sm Global structure in l1_type.h, too.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Merge new TBF architecture
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Remove dummy fcb_ok in AfcParams
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * sync l1 folder
 *
 * removed!
 * removed!
 * sync l1 folder
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 1. Replace __MA_L1__ with !(__NEW_OS_TICK) for mcu\l1_dm
 * 2. Replace !(MT6268T) with !(__NEW_OS_TICK) for isrenty.c
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * First Check-in 2G/3G Dual Mode Sleep Mode
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Fixed the compile error for 2G sleep mode global variable un-defined and re-defined issue.
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Recover 8/7 version.
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * change _DEBUG to L1C_DEBUG
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * create a new TimerTickL2 to send new ReportTickLapdm to L1A one frame ahead.
 *
 * removed!
 * removed!
 *
 *
 *    Rev 1.21   Aug 05 2005 10:16:46   mtk00474
 * Reason:
 *  Support the RF on/off issue
 *
 * Solution:
 *  1:Just stop the all channel service of L1C in L1A_reset
 *  2:Give up the all report from L1C after RF off happens
 *  3:Give the deactivate_cnf until receiving the ReportReset
 *
 * How to verify this SCR:
 *  PS1/Diamond helps to verify this
 * Resolution for 12202: Support the RF on/off issue
 *
 *    Rev 1.20   Jul 08 2005 16:52:12   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.19   May 17 2005 00:33:12   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.18   Feb 04 2005 22:41:34   mtk00674
 * fix RVCT compile warning
 * Resolution for 9774: [L1][update] fix RVCT compile warning
 *
 *    Rev 1.17   Jan 26 2005 17:50:10   mtk00248
 * Add TChAMRConfig and AMRQICompensationData.
 *
 *    Rev 1.16   Jan 18 2005 00:37:14   BM
 * append new line in W05.04
 *
 *    Rev 1.15   Oct 21 2004 18:29:00   mtk00248
 * Change __CS_SERVICE__ to __PS_SERVICE__.
 * Resolution for 8194: [L1C][Update] Reduce L1C RAM size
 *
 *    Rev 1.14   Oct 12 2004 17:44:28   mtk00248
 * Modify RxData, RxSlotData and SurroundCellData.
 * Resolution for 8194: [L1C][Update] Reduce L1C RAM size
 *
 *    Rev 1.13   May 02 2004 21:24:40   mtk00240
 * Add comment to remind programmers updating  synchronously the type copy in m12194.c
 * Resolution for 5221: [L1D] Copy type definition in m12194.c to avoid including L1 private header files
 *
 *    Rev 1.12   Mar 12 2004 13:33:34   mtk00274
 * Modify adjacent interference checking: SC check Rxlev from BA list and pass a flag to NBCCh handler.
 * Resolution for 3847: [L1/SC]Modify SC to confirm C0 for XO
 *
 *    Rev 1.11   Mar 12 2004 11:58:48   mtk00489
 * [L1D][Enhanced]L1D add APC voltage/temperature compensation and add BBTXParameter for META
 * Resolution for 4233: [L1D][Enhanced]L1D add APC voltage/temperature compensation and add BBTXParameter for META
 *
 *    Rev 1.10   Mar 08 2004 13:23:32   mtk00248
 * Change data type of usf in RxSlotData from uint8 to USF.
 * Resolution for 2498: [L1C][Update]Add a USF parameter in L1A/C and L1C/D interface to denote whether PBCCH and PCCCH is in the same PDCH.
 *
 *    Rev 1.9   Feb 16 2004 10:44:52   mtk00276
 * Use TID for the race condition of L1A/C interface on DCh/TBF start and stop
 * Resolution for 3924: Use TID for the race condition of L1A/C interface on DCh/TBF start and stop
 *
 *    Rev 1.8   Dec 01 2003 16:43:52   mtk00248
 * Add sMTMAXTIME for measurement of L1 execution time.
 * Resolution for 3451: [L1C/L1D][Add feature] Turn on L1 execution time measurement
 *
 *    Rev 1.7   Oct 23 2003 09:54:48   mtk00248
 * Add enum PBCChPriority.
 * Resolution for 3174: Let the priory of monitor PBCCH is lower than motitor PAGCH's during Packet Random Access
 *
 *    Rev 1.6   Jul 07 2003 10:53:20   mtk00248
 * Add one more element, int16 snrSum, in RxSlotData.
 * Resolution for 2171: [L1CD][Update] Reduce and optimize L1 trace.
 *
 *    Rev 1.5   Jun 16 2003 09:06:08   mtk00274
 * Add L1C,L1D code to support Crystal Oscillator.
 * Resolution for 2011: [L1D][Add feature] Support Crytal Oscillator
 *
 *    Rev 1.4   21 Mar 2003 15:49:26   mtk00274
 * If SB timer conflicts with DCh timer, L1 should comsume this SB report.
 * Resolution for 1325: Disable the FB_SB_retry action while RR does bsic_decode in DEDI-STATE
 *
 *    Rev 1.3   11 Feb 2003 14:15:54   mtk00274
 * Add retry_FB_SB flag
 * Resolution for 889: Add a low power control for retry_FB_SB to L1 in idle state
 *
 *    Rev 1.2   Feb 10 2003 22:12:28   mtk00489
 * add AMR_ENABLE to support AMR
 * Resolution for 642: add AMR_ENABLE to support AMR
 *
 *    Rev 1.1   Feb 10 2003 18:26:26   mtk00489
 * L1D supports AMR and L1D_LP2 supports MT6218 cosim
 * Resolution for 639: L1D supports AMR and L1D_LP2 supports MT6218 cosim
 *
 *    Rev 1.0   Nov 30 2002 19:50:14   admin
 * Initial revision.
 *
 *    Rev 1.27   26 Nov 2002 12:04:58   mtk00274
 * Add extBsic flag to indicate if Extended measurement BSIC
 *
 *    Rev 1.26   31 Oct 2002 17:42:00   mtk00274
 * fix warning
 *
 *    Rev 1.25   29 Oct 2002 17:49:26   mtk00243
 * move "typedef kal_int8   USF;" from l1_types.h to mph_types.h
 *
 *    Rev 1.24   29 Oct 2002 12:08:14   mtk00274
 * change Rxqual type to uint8
 *
 *    Rev 1.23   24 Oct 2002 10:16:28   mtk00248
 * Add HoppingSequence* hs in HoppingSequenceSetData.
 *
 *    Rev 1.22   23 Oct 2002 17:40:42   mtk00248
 * Add burstLength in PacketTimingAdvance.
 *
 *    Rev 1.21   22 Oct 2002 21:16:44   mtk00248
 * Add blockNo in RxData.
 *
 *    Rev 1.20   17 Oct 2002 17:05:10   mtk00274
 * move typedef of "LogChannel" to mph_types.h
 *
 *    Rev 1.19   14 Oct 2002 09:29:56   mtk00274
 * change BER to RxQual
 *
 *    Rev 1.18   12 Oct 2002 12:17:46   mtk00248
 * Remove ReportPDTChTx in enum ReportType.
 *
 *    Rev 1.17   08 Oct 2002 14:05:30   mtk00248
 * 1. Remove BlockData*, CodingScheme and TimeSlot in PacketBlockSpec.
 * 2. Remove UplinkAccessMode in PacketUplinkSpec.
 *
 *    Rev 1.16   07 Oct 2002 13:54:36   mtk00274
 * Remove ReportExtReportingPeriod report type
 *
 *    Rev 1.15   02 Oct 2002 14:07:12   mtk00274
 * Sync to latest condat L1C codes
 *
 *    Rev 1.14   30 Sep 2002 16:40:04   mtk00248
 * Add a new element, TBFData, in ReportData.
 *
 *    Rev 1.13   27 Sep 2002 10:11:46   mtk00248
 * Change bitmap size in MACFixedUplinkParams from 17 to 36.
 *
 *    Rev 1.12   23 Sep 2002 09:06:06   mtk00274
 * add ReportNBCChSC report type
 *
 *    Rev 1.11   19 Sep 2002 11:48:26   mtk00248
 * Add one report type, ReportHoppingSequenceFree.
 *
 *    Rev 1.10   Sep 18 2002 17:43:04   mtk00247
 * 1. move typedef of "LoopMode" to mph_types.h
 *
 *    Rev 1.9   18 Sep 2002 13:33:20   mtk00274
 * Add SCBsicStopInfo and SCBcchStopInfo
 *
 *    Rev 1.7   17 Sep 2002 17:55:00   mtk00248
 * Add syncTimeSlot in RxData.
 *
 *    Rev 1.6   17 Sep 2002 16:03:04   mtk00248
 * 1. Add ReportRepeatAllocation in ReportType.
 * 2. Add assign_ref in TBFParams.
 * 3. Add assign_ref in DChData.
 * 4. Add assign_ref in InterferenceData.
 *
 *    Rev 1.5   13 Sep 2002 16:25:30   mtk00248
 * Remove DChParams and TBFParams in DChData.
 * Add startTimeSlotFBSB in DChData.
 *
 *    Rev 1.4   13 Sep 2002 13:53:30   mtk00248
 * Add typedef kal_bool  bool;
 * Remove compile option used to enclose the following code.
 * enum { false, true };
 *
 *    Rev 1.3   12 Sep 2002 15:47:00   mtk00274
 * Remove PowerSum,PowerControlLevel and BlockData
 *
 *    Rev 1.2   11 Sep 2002 16:02:08   mtk00274
 * Merge Albert's code.
 *
 *    Rev 1.1   09 Sep 2002 10:33:22   mtk00248
 * Merge JC Huang's code.
 *
 *    Rev 1.0   Sep 06 2002 11:19:00   admin
 * Initial revision.
 *
 *    Rev 1.20   03 Sep 2002 10:52:04   mtk00248
 * Add an extra field, codingScheme, in RxSlotData.
 *
 *    Rev 1.19   22 Aug 2002 11:23:38   mtk00248
 * 1. Add bufferIndex in PacketBlockSpec.
 * 2. Add PrePacketBlockSpec and PrePacketUplinkSpec.
 *
 *    Rev 1.18   05 Jul 2002 21:13:50   mtk00274
 * Remove the interface L1T_SpeechOn and L1T_DChSetDaiMode
 * Resolution for 426: L1C should remove the interface L1T_SpeechOn and L1T_DChSetChannelMode
 *
 *    Rev 1.17   Jul 04 2002 23:31:04   mtk00210
 * Simplify K factor calculation and reduce memory consumption
 *
 *    Rev 1.16   04 Jul 2002 10:16:16   mtk00248
 * Add power meas report structure used in l1 test mode.
 *
 *    Rev 1.15   03 Jul 2002 20:44:50   mtk00274
 * change array size from tsd[4] to tsd[8]
 * Resolution for 417: The size of array of timeslot data for DTX AGC algorithm should be 8 rather than 4
 *
 *    Rev 1.14   May 08 2002 23:46:22   mtk00210
 * Extract code for GSM only release
 *
 *    Rev 1.13   11 Apr 2002 11:17:00   mtk00274
 * set max tx power for the DCH and redefination hopping sequence from L1A
 * Resolution for 353: L1A must set max tx power for hopping sequence in each band
 *
 *    Rev 1.12   18 Feb 2002 21:45:08   mtk00248
 * Add a new field baListId in the ScanList structure.
 *
 *    Rev 1.11   Feb 16 2002 20:41:02   mtk00274
 * add a parameter powerdBm into DChParams to avoid txPower to be replaced by converting power
 *
 *    Rev 1.10   Jan 24 2002 09:52:26   mtk00210
 * Add new report type - ReportDChStopped
 *
 *    Rev 1.9   Jan 19 2002 00:18:46   mtk00210
 * In order to fix the numerical bug in RXLEV accumulation, so add new datatype "PowerSum32", and change teh datatype of powerSum in the strcture "MonitorResultItem"
 *
 *    Rev 1.8   Jan 17 2002 17:45:50   mtk00210
 * Add the goodsnr in the structure of AGCTimeSlotData
 *
 *    Rev 1.7   Jan 10 2002 17:30:54   mtk00210
 * Support EFS
 *
 *    Rev 1.6   Jan 10 2002 14:51:40   mtk00210
 * add typedef DaiMode
 *
 *    Rev 1.5   Jan 05 2002 19:07:28   mtk00245
 * Check in to reflect new header file structure
 * Resolution for 177: Software integration check-in
 *
 *    Rev 1.3   Jan 03 2002 11:52:26   mtk00210
 * merge the branch B.L1.20011225
 *
 *    Rev 1.2.1.1   Dec 27 2001 10:48:46   mtk00210
 * Add isCSD flag in  RxData
 *
 *    Rev 1.2.1.0   Dec 25 2001 16:40:20   mtk00210
 * revise L1 for RSSI, multiband AFC, new L1D/L1C interface,
 * and new CBCH handler
 *
 *    Rev 1.2   Dec 21 2001 14:12:54   mtk00210
 * Change the arrangement of RXdata
 * Resolution for 136: Logged BCCH block is different from TI platform, one byte shift
 *
 *    Rev 1.1   Dec 21 2001 12:17:42   admin
 * add copyright
 *
 *
 *******************************************************************************/

/******************************************************************************
 *
 *  File:            /MTKteam/source/gprsmtk/l1/generic/SCCS/s.l1_types.h
 *  -----
 *
 *  SCCS Version:    2.22
 *  -------------
 *
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of Communications Consultants Worldwide Limited (C) 2001
 *
 *  Project:
 *  --------
 *
 *  Software Unit:  Layer1 global types.
 *  --------------
 *
 *  Description:
 *  ------------
 *
 *
 *  Modification History:
 *  ---------------------
 *  Date       Vers  Auth  Details
 *  ----       ----  ----  -------
 *  28-Mar-01  2.1   VKL   Initial version.
 *  17-Apr-01  2.2   VKL   added L1SCModeScan and L1SCModeAccess
 *  27-Apr-01  2.3   VKL   Changed timing advance from int8 to uint8 for GSM400
 *                         Extended RxData (member of Report) structure so
 *                         it can contain up to 4 blocks with a size suitable
 *                         for GPRS.
 *                         Added frequency error fields to RxData.
 *                         Remove usedTxPower firld from ReportPeriodData
 *                         (member of report)
 *  01-May-01  2.4   VKL   Add TimeSlotMask
 *                         Add report type for PDTCh
 *                         Add data structures for TBF
 *  21-May-01  2.5   VKL   added new report types
 *                         added type Measurements for power measurement manager
 *                         added usf to RxSlotData
 *                         removed scan list from ReportPeriodData
 *                         removed measurementCount from PowerScanData
 *                         added SurroundMeasurmentData and InterferenceData
 *                          to ReportData
 *  15-Jul-01  2.6   VKL   Changed comments
 *                         Added TSC and PowerControlLevel types
 *                         Added ReportPeriodLock type
 *                         Add FrequencyBand enum
 *                         Removed PChMode enum
 *                         Changed TChMode params for half rate and 14400 data
 *                         Added new report types
 *                         Changed RxSlotData to save memory
 *                         Changed monitoring values in RxData
 *                         Added layer1 internal fields some report data
 *                         Added TxData structure
 *                         Renamed some fields
 *                         Changed data structures dealing with TBF and MAC
 *  08-Aug-01  2.7   VKL   RxData structure changed so power of bursts is
 *                         reported separately for each burst
 *                         RxData structure field errorSumCount replaces
 *                         frequencyErrorCount and ebitTimingErrorCount
 *                         RxData structure field quality moved to RxSlotData
 *                         RxData structure got new layer1 internal fields
 *                         Added MeasurementMapping structure to
 *                         MACDownlinkParams
 *                         Added field txPower to PacketBlockSpec
 *                         Added field mode to PacketUplinkSpec
 *  16-Aug-01  2.7   SGB   Add fcb_ok to SCH struct
 *  02-Sep-01  2.8   VKL   Remove ReportPowerMeasurement, add new report types
 *                         move CodingScheme enumeration, add powerCount field,
 *                         frameNumber and arfcn field to RxData structure
 *                         Add blockCount, blockData and codingScheme fields
 *                         to TxData structure, add DChData structure
 *                         add dtxUsed field, dch field to ReportData structure
 *                         add frameOffset and ebitOffset fields to DChParams
 *                         remove expectedRxPower field from SurroundBS structure
 *                         change size of bitmap in MACFixedUplinkParams structure
 *                         add timingAdvance field to PacketUplinkSpec structure
 * 03-Sep-01   2.09  SGB   Fix merge errors
 * 04-Sep-01   2.10  APB   Fix merge errors
 * 12-Sep-01   2.11  VKL   Add ReportHoppingSequenceSet, add useCount field to
 *                         HoppingSequence structure, rearrange field in Report
 *                         structure so data field is at the end
 * 13-Sep-01   2.12  VKL   Add ReportNPBCCh
 * 26-Sep-01   2.13  APB   Predict volker's additions of L1SCModePacketIdle,
 *                         and L1SCModePacketTransfer definitions
 * 26-Sep-01   2.14  VKL   Add ReportPollResp
 *                         Remove count field from PowerScanResults
 *                         Remove nextSession field from MeasurementStruct
 *                         Add channelMode field to RxData
 *                         Add hs field to ReportData
 *                         Add debug field needToCallMonitorReport to Report
 * 01-Oct-01   2.15  VKL   Replace 'quality' field in RxSlotData by 'bitCount'
 *                         and 'bitErrorCount'
 * 04-Oct-01   2.16  VKL   Add bsTimingOffset to SChData
 * 09-Oct-01   2.17  VKL   Add new fields used by AGC
 * 10-Oct-01   2.18  VKL   Add per cell AFC support
 * 18-Oct-01   2.20  APB   Add DChDataMode type, in anticipation of VK vhange
 * 26-Oct-01   2.21  VKL   Add types for surround cell engine.
 *                         Add SurroundReportBestSix and associated data structure
 * 01-Nov-01   2.22  VKL   Add pbcchExists field to TBFParams.
 * 06-Nov-01   2.23  VKL   Add new types and enums for NC and ext measurements
 * 08-Nov-01   2.24  VKL   Add structure for extended measurement report
 *                         Fixed typos
 *  09-Oct-01  2.25  VKL   Use L1_SURROUND_MAX_CELLS for arrays dealing with
 *                          BA lists
 *                         Change report periods in SuroundNCMeasParams to
 *                          use encoded value
 *                         Remove BTSPowerControlModePCCCh
 *                         Add hardwareUnavailable flag to SChData
 *  17-Nov-01  2.22  VKL   Define new data structures and extend report for AGC
 *  21-Nov-01  2.23  VKL   Remove frequencyErrorSum from RxData
 *                         Add layer1 internal fields to report
 *  28-Nov-01  2.24  SY    Add TimeStamp from l1_core_Private.h and revise AFCParams
 *  04-Dec-01  2.27  VKL   Add arfcn to L1I_AllocRxReport()
 *                         Add L1I_AllocMultislotRxReport()
 *                         L1I_PDTChStop() now always fully stops PDTCh and
 *                          add L1I_PDTChRestart() instead.
 *                         Add L1T_CalcBlockPower()
 *                         Change monitoring interface
 *
 *****************************************************************************/

#ifndef l1_generic_l1_types_h
#define l1_generic_l1_types_h

#include "kal_public_defs.h"

/*
@doc BBREF COREREF
*/
#include "l1d_cid.h"

#include "kal_public_api.h"
#include "mph_types.h"

#include "kal_general_types.h"
#include "l1_const.h"
#include "mph_cnst.h"
#include "l1_types_public.h"
#include "gl1_option.h"


#ifdef __NEW_TBF_ARCH__
   #ifdef __MTBF__
      #if defined(L1D_TEST)
#define MULTIPLE_TBF (8)
#define NUM_TBF 8
      #else
#define MULTIPLE_TBF (5)
#define NUM_TBF 5
	  #endif
   #else  /*__MTBF__*/
#define MULTIPLE_TBF (1)
#define NUM_TBF 1
   #endif /*__MTBF__*/
#endif  /*__NEW_TBF_ARCH__*/

// [MAUI_02940398] Increased DATA_SECTOR_SIZE for offload outer
//#if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
#define TAIL_SIZE          16 // HW write extra 4 bytes (CRC) at the end
//#else
//#define TAIL_SIZE           0
//#endif

typedef enum
{
   FCB_GAP_ONLY_IN_VIDLE,
   FCB_GAP_IN_VIRTUAL_MODE,
   NO_FCB_GAP
}FCB_INJECT_MESSAGE;

extern FCB_INJECT_MESSAGE FB_INJECT_MESSAGE;

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_GSM
      #ifdef CSD_SUPPORT
#define DATA_SECTOR_SIZE   (40 +TAIL_SIZE) 
      #else
#define DATA_SECTOR_SIZE   (24 +TAIL_SIZE)
      #endif
   #else
      #if IS_FANR_EDGE_SUPPORT
#define DATA_SECTOR_SIZE   (164+TAIL_SIZE)   // 8+76+76+4
      #else
#define DATA_SECTOR_SIZE   (160+TAIL_SIZE)   // 8+76+76
      #endif
   #endif
#endif

#define TD_DM_MAX_GAP_IN_A_FRAME  3 /* the number of max gap counts within a TD subframe */
#define GL1_MAX_GAP_NUM_IN_ONE_FRAME TD_DM_MAX_GAP_IN_A_FRAME

#ifdef __GL1_MULTI_MODE__
#define L1C_MAX_GAP_IN_A_FRAME  TD_DM_MAX_GAP_IN_A_FRAME
#endif /*__GL1_MULTI_MODE__*/


/* --- GSM primitive types ------------------------------------------------- */

typedef int32  PowerSum32;
typedef int8   TID;
typedef int16  GainSum; /* in dBm, used to do calculations */

/* --- enumerated types ---------------------------------------------------- */

#ifdef __GL1_MULTI_MODE__

typedef enum
{
    UMTS_CMCS_ONLY = 0
   ,UMTS_GAP_ALL
#ifdef  __GERAN_R8__    
   ,UMTS_CMCS_ONLY_RANK
   ,UMTS_GAP_ALL_RANK
   ,UMTS_CMCS_ONLY_PRIO
   ,UMTS_GAP_ALL_PRIO   
#endif  /* __GERAN_R8__ */  
}Gap_service_3G_enum;

typedef enum
{
   REG_RESEL_STANDBY,
#ifdef  __GERAN_R8__   	
   PRIO_RESEL_STANDBY,
#endif  /* __GERAN_R8__ */   
   NUM_RESEL_MODE_STANDBY
} l1c_resel_mode_standby_enum;

typedef enum
{
   GL1_RAT_NULL,
   GL1_RAT_UTRAN_FDD,
   GL1_RAT_UTRAN_TDD,
   GL1_RAT_C2K,
   GL1_RAT_EUTRAN,
   GL1_RAT_ACTIVE_RAT_NUM
} gl1_active_rat_enum;


typedef enum
{
   gl1_normalGAPStart,
   gl1_normalGAPStop,
   gl1_autoGAPStart,
   gl1_autoGAPStop
} gl1_gap_status_enum;


/*
typedef enum
{
   STANDBY_STATE,
   FLIGHT_STATE,
   NULL_STATE,
   PCH_STATE,
   FACH_STATE,
   DCH_STATE,
   HSPA_STATE
} l1dm_umts_mode_enum;  */

#ifdef L1_SIM  
//only used for L1Sim
typedef enum
{
   UMTS_FDD,
   GSM_RSSI,
   GSM_INIT_BSIC,
   GSM_RECONF_BSIC,
   GAP_PURPOSE_UNDEFINED,
   GAP_PURPOSE_NUM
} Gap_purpose_enum;
#endif

#endif

typedef enum
{
   PBCChPriorityLow,
   PBCChPriorityMid,
   PBCChPriorityHigh
} PBCChPriority;

typedef enum
{
   NBCChPriorityNull,
   NBCChPriorityLow,
#ifdef __GL1_GEMINI__
   NBCChPriorityHigh,
#endif
   NBCChPriorityTop
#ifdef __GL1_GEMINI__
   ,NBCChPriorityVirtualNULL
   ,NBCChPriorityTopNoFindTimer
#endif   
} NBCChPriority;

#ifdef __GL1_GEMINI__
typedef enum
{
   FCChPriorityLow,
   FCChPriorityHigh,
   FCChPriorityTop
} FCChPriority;

typedef enum
{
   SChPriorityLow,
   SChPriorityHigh
} SChPriority;
#endif /*__GEMINI_MONITOR_PAGE_DURING_TRANSFER__*/


/* Report type definition for multiple SIM.*/
#define   REPORT_SIM_SIZE   (  0x80 )
/*bit[8:7] = { 2b'00->SIM1, 2b'01->SIM2, 2b'10->SIM3, 2b'11->SIM4 } */
#define   REPORT_SIM_MASK   ( 0x180 ) 
/*bit[6:0]: report type*/
#define   REPORT_TYPE_MASK  ( 0x07F ) 

/*
@enum ReportType | Type of a report.
*/
typedef enum
{
   ReportSIM1Base,
   ReportNone = ReportSIM1Base, /* @emem No valid report. */
   ReportReportPeriodDone, /* @emem End of report period. */
   ReportPowerScanDone,    /* @emem Power scan results. */
   ReportFCCh,             /* @emem FCCh result. */
   ReportSCh,              /* @emem SCh result. */
   ReportServingSChAdditional, /* @emem Serving Cell SCh result. */
   ReportServingSChThermal,  /* @emem Serving Cell SCh result, it start receive when thermal change a lot */
   ReportServingSChPeek,	   /* @For serving SCh report from old peek timer mechanism */
   ReportPCh,              /* @emem PCh block received. */
   ReportBCCh,             /* @emem BCCh block received. */
   ReportNBCCh,            /* @emem BCCh block on neighbour base station received. */
   ReportNBCChSC,          /* @emem BCCh block on neighbour base station received, L1C/SC internal */
   ReportAGCh,             /* @emem AGCh block received. */
   ReportRACh,
   ReportSDCCh,            /* @emem SDCCh block received. */
   ReportSACChC,           /* @emem SACCh/C block received */
   ReportTCh,              /* @emem TCh or FACCh block received */
   ReportSACChT,           /* @emem SACCh/T block received */
   ReportCBCh,             /* @emem CBCh block received */
   ReportPPCh,
   ReportPAGCh,            /* @emem PAGCh block received. */
   ReportPBCCh,
   ReportNPBCCh,
   ReportPDTCh,
   ReportPTCCh,
   ReportPRACh,
   ReportDChStarted,
   ReportDChStopped,
   ReportInterference,
   ReportSurroundMeasurement,
   ReportExtendedMeasurement,
   ReportSACChTx,
   ReportCChTx,
   ReportHoppingSequenceSet,
   ReportPollResp,
   ReportSurroundRLA,
   ReportNCReportingPeriod,
   ReportSingleDL,
   ReportSingleULWithoutTBF,
   ReportSingleULTwoPhase,
   ReportPACCh,
   ReportPDTChConflict,
   ReportTBFStarted,
   ReportTBFStopped,
   ReportRepeatAllocation,
   ReportHoppingSequenceFree,
   ReportDChAfc,
   ReportReset,
   ReportTickLapdm,
#ifndef __ADDITIONAL_SERVING_SB_INTEGRATION__
   ReportPeek, //SM_WAKEUP_COMPENSATION
#endif
   ReportNCReport,
#if defined(__GL1_GEMINI__) && defined(__GL1_MULTI_MODE__)
   ReportTickVirtualPowerScan,
#endif
#if ( defined( __L1_GPS_AUTO_TIMING_SYNC_SUPPORT__  ) || defined( __L1_GPS_REF_TIME_SUPPORT__  ) )
   ReportGpsSync,
#endif
   ReportAllChannelStop,
#if defined(__GL1_MULTI_MODE__)
   Report480msTick,
   ReportGAPPattern,
   ReportGSMRSSI,   /* Re-use ReportSurroundRLA. */
   ReportGSMBSIC,
   ReportGAPStop,
   ReportStandbyDone,
   ReportActiveDone,
   ReportSyncTime,
   ReportGAPCancel,
   ReportNextBCCh,  /* L1C/SC internal use in standby mode. */
   ReportNextBSIC,  /* L1C/SC internal use in standby mode. */
   ReportBSICSC,    /* L1C/SC internal use in standby mode. */
   ReportGAPSuspend,  /* used to replace ReportFAChGAPLock and ReportFMOStop */
   ReportGAPEnd,
//   ReportGapService,  /* gapservice will be decided by L1A */
   ReportPMDone, 
   ReportAutoGAPStart,
   ReportGSMAutoGAPStart,
   ReportGSMAutoGAPEnd,
   ReportGSMAutoGAPStop,
   ReportGSMAutoGAPReReq,  /* used by l1c to ask l1a to trigger cgi related request again. For ag too short, confirm too late, nbcch */
   ReportPowerScanDoneCGI,
   ReportFCChCGI,
   ReportNBCChCGI,
#endif
#ifdef __GL1_GEMINI__
   ReportSuspend,
   ReportPChSharing,   
   ReportBCChSharing,
   ReportPChConflict,
   ReportBCChConflict,
   ReportNBCChConflict,
#endif /* __GL1_GEMINI__ */
#if IS_FHC_SUPPORT
   ReportDTS,
   ReportUTS,
#endif
#if IS_NSFT_SUPPORT
   ReportNSFT,
#endif
#if IS_NSFT_LIST_MODE_SUPPORT
   ReportNSFTLM,
#endif
#ifdef __2G_TX_VOLTAGE_COMPENSATION_SUPPORT__
   ReportTxComp,
#endif
   ReportModeChangeCNF,
   ReportFCChSRVCC,
#ifdef __GL1_GEMINI__
   ReportSIM2Base              = REPORT_SIM_SIZE,
#endif
#if (GL1_GEMINI_NUM >= 3)
   ReportSIM3Base              = 2 * REPORT_SIM_SIZE,
#endif
#if (GL1_GEMINI_NUM >= 4)
   ReportSIM4Base              = 3 * REPORT_SIM_SIZE,
#endif
   ReportEnd               /* @emem No valid report. Marks end of <t ReportType> enumeration */
} ReportType;

/*
@enum AMRFrameType | AMR Frame Type.
*/
typedef enum
{
/* AMR Frame Type used by L1D. */

   AMRFrame_FACCH,      /* @emem FACCH      */
   AMRFrame_RATSCCH,    /* @emem RATSCCH    */
   AMRFrame_SID_FIRST,  /* @emem SID FIRST  */
   AMRFrame_SID_UPDATE, /* @emem SID UPDATE */
   AMRFrame_ONSET,      /* @emem ONSET      */
   AMRFrame_NO_DATA,    /* @emem No Data    */

   AMRFrame_AFS1220,    /* @emem AMR Full rate speech 12.2k */
   AMRFrame_AFS1020,    /* @emem AMR Full rate speech 10.2k */
   AMRFrame_AFS795,     /* @emem AMR Full rate speech 7.95k */
   AMRFrame_AFS740,     /* @emem AMR Full rate speech 7.4k  */
   AMRFrame_AFS670,     /* @emem AMR Full rate speech 6.7k  */
   AMRFrame_AFS590,     /* @emem AMR Full rate speech 5.9k  */
   AMRFrame_AFS515,     /* @emem AMR Full rate speech 5.15k */
   AMRFrame_AFS475,     /* @emem AMR Full rate speech 4.75k */

   AMRFrame_AHS795,     /* @emem AMR Half rate speech 7.95k */
   AMRFrame_AHS740,     /* @emem AMR Half rate speech 7.4k  */
   AMRFrame_AHS670,     /* @emem AMR Half rate speech 6.7k  */
   AMRFrame_AHS590,     /* @emem AMR Half rate speech 5.9k  */
   AMRFrame_AHS515,     /* @emem AMR Half rate speech 5.15k */
   AMRFrame_AHS475,     /* @emem AMR Half rate speech 4.75k */
   AMRFrame_WFS1265,    /* @emem AMR Half rate speech 12.65k*/
   AMRFrame_WFS885,     /* @emem AMR Half rate speech 8.85k */
   AMRFrame_WFS660      /* @emem AMR Half rate speech 6.6k  */

} AMRFrameType;

/* R99, TBF_EST */
typedef enum
{
   SingleBlockTypeSingle, /* send 1 block  and monitor PACCh */
   SingleBlockTypeMulti,  /* send 2 blocks and monitor PACCh */
   SingleBlockTypeNone    /* just monitor PACCh */
} SingleBlockType;

typedef enum
{
   None,
   NonSyncHandover,
   SyncHandover
} HandoverState;

typedef enum
{  NoResetVQIR,
   ResetVQIR,
   ResetIR,
   RestoreVQ
} IRControl;

#ifdef __PS_HO__
typedef enum
{
   NonHandover,
   Handover_Stage1,
   Handover_Stage2
} PSHandoverState;
#endif

/* For Gemini*/
typedef enum
{
    SIM_SET_FROM_REPORT,
    SIM_SET_FROM_TIMER,
    SIM_SET_FROM_QUEUED,
    SIM_SET_FROM_TASK,
    SIM_RESTORE_FROM_LISR_TO_TASK,
    SIM_RESTORE_FROM_HISR_TO_TASK,
    SIM_RESTORE_FROM_LISR_TO_HISR,    
    SIM_SET_FROM_PCHSHARING,
    SIM_SET_FROM_BCCHSHARING,
    SIM_SET_FROM_IRAT_SYNCSHARING,
    SIM_SET_TO_TRIGGER_SERVING_SB,
    SIM_SET_TO_CHANNEL_UNLOCK
} sim_mode_from_enum;


/* --- structure types ----------------------------------------------------- */

typedef struct
{
   int32       k_factor; /* K factor * 2^12 */
   int32       phi_factor[1];
   TimeStamp   lastFn;
   int16       DacValue; /* TCVCXO quantisation step */
// bool        fcb_ok;   /* not used */
   int8        tid;
   int8        fcstep;

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   /* Variable for the TX outer loop */
   int16       Tx_DacValue;   /* TX TCVCXO quantisation step    */
   int16       Tx_acc_err;    /* Tx Accumulated frequency error */
   int16       Tx_Rx_Freqerr; /* Freq error between Rx/Tx       */
   bool        TX_Loop_Enable;/* Dual loop enable switch        */
#endif

#ifdef __GL1_GEMINI__
   uint8       simIndex;
#endif

#ifdef   AFC_TC
/*XO*/ int32   lastCompensatePhi;
#endif

} AfcParams;

#ifdef __GL1_MULTI_MODE__

typedef struct
{
   intx   start_ebit;
   intx   len_ebit;
   bool   is_pm;  //used for TDD
} sGAP;

typedef struct
{
   Time        start_time;
   intx        len;   /* in unit of ebit */
   kal_int32   purpose_bitmap;  //copy from ll1 expanded gaps
} Gap_Pattern;


typedef enum
{
   MM_NONE       = 0,
   MM_GSM_IDLE   = 1,
   MM_GSM_DCH    = 2,
   MM_SIMX_VIDLE = 3,
   MM_UMTS_IDLE   = 4,
   MM_UMTS_FACH   = 5,
   MM_UMTS_DCH    = 6,
} L1D_MM_STATE;



#if IS_TDD_DUAL_MODE_SUPPORT

typedef struct
{
   uint8  gap_num;
   Gap_Pattern gap[TD_DM_MAX_GAP_IN_A_FRAME];
   bool  is_fb_search; /* whether the gap is for continous FB search */
} Gap_Session;

/* start_ebit : the start ebit position of this effective gap.
     len_ebit : the gap length in the unit of ebit.
     is_pm : purpose indicator for this gap.

    Gap for PM purpose:
    L1C shall set is_pm = 1 and start_ebit >= 0;

    Gap for FB/SB purpose:
    L1C shall set is_pm = 0 and start_ebit >= 0;

    Gap for no purpose:
    L1C shall set is_pm = 0 and start_ebit = -1; */



#endif

#endif /*__GL1_MULTI_MODE__*/

/*
@struct HoppingSequence | Hopping sequence definition.
*/
typedef struct
{
   intx  hsn;         /* @field Hopping sequence number. */
   intx  maio;        /* @field Mobile allocation index offset. */
   intx  arfcnCount;  /* @field Number of frequencies in <e HoppingSequence.arfcn>. */
   ARFCN arfcn[ 64 ]; /* @field List of frequencies. */

   int8  useCount;    /* layer1 core internal use */
   Power maxTxPwr;    /* L1A set max Tx power for each band */
#ifdef __EPSK_TX__
   Power maxTxPwrEPSK;
#endif
#ifdef __GL1_GEMINI__
   uint8 simIndex;
#endif
} HoppingSequence;

/*Notice: Please do not add compile option for SurroundMode for correct trace in catcher */
typedef enum
{
   L1SCModeReset,
   L1SCModeNull,
   L1SCModeScan = L1SCModeNull, /* identical behaviour */
   L1SCModeIdle,
   L1SCModeAccess,
   L1SCModeDediSDCCh,
   L1SCModeDediTCh,
   /* For __PS_SERVICE__ */
   L1SCModePacketIdle,
   L1SCModePacketAccess,
   L1SCModePacketTransfer,
   /* For __GL1_MULTI_MODE__ */
   L1SCModeStandby,
   /* For __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
   L1SCModeVirtual = 0x10,
   L1SCModeVirtualIdle = L1SCModeVirtual + L1SCModeIdle,
   L1SCModeVirtualPacketIdle = L1SCModeVirtual + L1SCModePacketIdle
} SurroundMode;

typedef struct
{
   intx           baListId;
   uint8          arfcnCount;
#ifdef __GL1_MULTI_MODE__
#ifdef  __GERAN_R8__   
   kal_bool       is_higher_priority;
#endif  /* __GERAN_R8__ */
   intx           arfcn_start_index;
#endif
   ARFCN          arfcn[L1_SURROUND_MAX_CELLS];
} SurroundBAList;

typedef struct
{
   ARFCN          arfcn;
   bool           bsicKnown;
   FrameNumber    frameOffset;
   intx           ebitOffset;
   bool           needRetry;
   bool           retry_FB_SB;
#if 1 //__NORMAL_NW_SEARCH__
   bool           FreqCorrect;
#endif


#ifdef __GL1_MULTI_MODE__
  TimeStamp       timeStamp; 
  bool            is_enhanced_bsic;
#endif 
} ScCellBsicInfo;


typedef struct
{
   ScCellBsicInfo cell[L1_SURROUND_MAX_CELLS];
   uint8          cellCount;
   uint8          tid;    /* add this for upper layer to distinguish from different req */
#ifdef __GL1_MULTI_MODE__    
   bool           is_cgi;
#endif 
#ifdef  __GL1_GEMINI_WCDMA__
   bool           is_PLMNList;
#endif
} SCBsicInfo;

typedef struct
{
   
   bool           manual;

   ARFCN          cell[L1_SURROUND_MAX_CELLS];
   uint8          cellCount;
#ifdef __GL1_MULTI_MODE__    
   bool           is_cgi;  /* for reportCGI */
#endif   
#ifdef  __GL1_GEMINI_WCDMA__
   bool           is_PLMNList;
#endif
} SCBsicStopInfo;

typedef struct
{
   ARFCN          arfcn;
   bool           bsicKnown;
   FrameNumber    frameOffset;
   intx           ebitOffset;
   BSIC           bsic;
   uint16         bcchMask;
   bool           needRetry;
   bool           is_prior_to_acquire;
   bool           use_priority_index_order;
#ifdef __GL1_GEMINI__
    uint16        priority_index;
#else
    uint8         priority_index;
#endif
} ScCellBcchInfo;

typedef struct
{
   ScCellBcchInfo cell[ 6 ];
   uint8          cellCount;
#ifdef __GL1_MULTI_MODE__    
   bool           is_cgi;  /* for reportCGI */
#endif
#ifdef  __GL1_GEMINI_WCDMA__
   bool           is_PLMNList;
#endif
} SCBcchInfo;

typedef struct
{
#if 1 //__NORMAL_NW_SEARCH__
    bool          manual;
#endif
    ARFCN         cell[ 6 ];
    uint8         cellCount;
#ifdef __GL1_MULTI_MODE__
   bool           is_cgi;  /* for reportCGI */
#endif    
#ifdef  __GL1_GEMINI_WCDMA__
   bool           is_PLMNList;
#endif
} SCBcchStopInfo;


typedef struct
{
   intx           reportingPeriodI; /* 0: 0.48 sec, 1: 0.96 sec, ..., 7 = 61.44 sec */
   intx           reportingPeriodT; /* 0: 0.48 sec, 1: 0.96 sec, ..., 7 = 61.44 sec */
} SuroundNCMeasParams;


typedef struct
{
   uint8          arfcnCount;
   ARFCN          arfcn[L1_SURROUND_MAX_CELLS];
} SuroundExtMeasParams;

/*
 * Example for lag in SurroundBS
 *
 * neighbour BS
 * . . | . . . 7 . . . | . . . 8 . . . | . . . 9 . . . |
 * current BS
 * | . . . 8 . . . | . . . 9 . . . | . . . 10. . . | . .
 *
 * lag.frame   = 1
 * lag.ebits = 2500
 */
/* --- calculation of RLA_C ------------------------------------------------- */

typedef struct
{
   PowerSum32  sum;
   uint8       sumCount;
   Power       last5[5];
   uint8       last5Next;
   bool        last5Full;
   bool        last1;
#ifdef __GL1_MULTI_MODE__
   kal_uint8   min_sample; /* 3->3G active in DCH/FACH, 4->3G active in idle, 5->Single GSM mode. */
#endif
} PowerAverager;

typedef struct
{
   ARFCN       arfcn;
   AfcParams   afc;
   Power       rxPower;    /* last averaged power level */
   Power       ncPower;    /* last averaged power level for NC measurements */
   uint8       ncCount;
   /* used to calculate the average power for the cell */
   PowerAverager avg;

   bool        inNewBAList;
#if 1 //__NORMAL_NW_SEARCH__
   bool        keep;
#endif
   bool        newCell;
} SurroundBS;

typedef struct
{
   BTSPowerControlMode mode;
   bool                prModeA;
   intx                p0;
} BTSPowerControl;

/*
@struct PowerScanResults | Results of full power scan.
*/
typedef struct
{
   PowerSum power[ ARFCN_COUNT ]; /* @field Sum of power measurements for each arfcn */
} PowerScanResults;

/*
@struct MonitorResultItem | Partial results of current channel monitoring.
*/

typedef struct
{
   PowerSum32  powerSum;   /* @field Sum of power measurements in dBm */
   intx        powerCount; /* @field Number of measurements added. */
   intx        errorSum;   /* @field Number of bit errors. */
   intx        errorCount; /* @field Number of bits. */
   uint8       RxQual;
} MonitorResultItem;

#ifdef   __R99__  /* __R99__ */
typedef struct
{
   /* reported to upper layer */
   int8     meanBep;       /* mean BEP of a rp to report to upper layer, 5 bits */
   int8     cvBep;         /* CV BEP of a rp to report to upper layer, 3 bits */
   int8     nbrRcvdBlocks; /* for NBR_RCVD_BLOCKS */
   PowerSum32 powerSumVal; /* Sum of power measurements  to calculate RXLEV_VAL */

   /*  Below this line, L1C internal use */
   int16    meanBepCount;  /* count of meanBEP(block) */
   int16    cvBepCount;    /* count of cvBEP(block),
                              different from meanBepCount because CV_BEP(block) from SACCh
                              are excluded in enhanced meas report (05.02, 8.4.8.2) */
   intx     meanBepSum;    /* sum of meanBEP(block) */
   intx     cvBepSum;      /* sum of cvBEP(block) */
   intx     powerCountVal; /* number of measurements added, to calculate RXLEV_VAL, including SACCh */
} MonitorResultItemEnhanced;
#endif
/*
@struct MonitorResult | Results of current channel monitoring.
*/
typedef struct
{
   MonitorResultItem full; /* @field Results for all blocks. */
   MonitorResultItem sub;  /* @field Results for sub channel blocks. */
   TChMode           chMode;
   kal_int8          amrBadBlockCount; /* layer1 internal use */
#ifdef   __R99__ /* __R99__ */
   MonitorResultItemEnhanced enhanced; /* for enhanced measurement*/
#endif
} MonitorResult;

/*
@struct ScanItem | Per frequency information in <t ScanList>.
*/
typedef struct
{
   ARFCN      arfcn; /* @field The frequency. */
   PowerSum32 power; /* @field Sum of all power measurements (in dBm) for above frequency */
} ScanItem;

/*
@struct ScanList | List of neighbour ARFCNs and measurement results.
*/
typedef struct
{
#if defined( __GL1_MULTI_MODE__ ) && defined( __GERAN_R8__ )  
   kal_bool    is_higher_priority;  /* indicate higher priority reselection list (2G standby) */
#endif /* __GL1_MULTI_MODE__ && __GERAN_R8__ */
   intx     baListId;                     /* @field BA list Id */
   intx     itemCount;                    /* @field Number of frequencies used. */
   intx     measurementCount;             /* @field Total number of measurements performed */
   ScanItem items[L1_SURROUND_MAX_CELLS]; /* @field Per frequency information */
} ScanList;

typedef struct
{
   bool  AMRConfigValid; /* 1 bits, to indicate whether the following
                            AMR parameters are valid.Filled by L1A. */
   bool  ICMValid;       /* 1 bits, Initial Codec Mode Indicator.
                            Filled by L1A. */
   uint8 ICM;            /* 2 bits, the initial codec mode is coded
                            as in GSM05.09 sec 3.4.1. Filled by L1A. */
   uint8 ACS;            /* 8 bits, set of adaptive codec modes.
                            Filled by L1A. */
   uint8 CMIP;           /* 1 bits. Codec mode indication phase.
                            Filled by L1C.

                            3GPP 05.09 / sec 3.2.1.3, at call set-up, after
                            successful handover and after a channel mode
                            modify with consistent MUltirate IE, the default
                            phase (odd) shall be used in downlink direction.

                            CMIP        even phase  odd phase
                            ==========  ==========  =========
                             0             CMI         CMC
                             1(default)    CMC         CMI     */
   uint8 THRESH1;        /* 6 bits. Filled by L1A. */
   uint8 HYST1;          /* 4 bits. Filled by L1A. */
   uint8 THRESH2;        /* 6 bits. Filled by L1A. */
   uint8 HYST2;          /* 4 bits. Filled by L1A. */
   uint8 THRESH3;        /* 6 bits. Filled by L1A. */
   uint8 HYST3;          /* 4 bits. Filled by L1A. */
   uint8 ConfigMask;     /* 1 bits. Filled by L1C. */
   uint8 THRESH_Valid;   /* 1 bits. Filled by L1A/L1C. */
} TChAMRConfig;

#define AMRConfigMask_DL_CMIP     0x01
#define AMRConfigMask_DL_THRESH   0x02   /* For both downlink THRESH and HYST. */
#define AMRConfigMask_DL_ACS      0x04   /* For both downlink ACS and ICM. */
#define AMRConfigMask_UL_ACS      0x08   /* For both uplink ACS and ICM. */
#define AMRConfigMask_ALL        (AMRConfigMask_DL_CMIP | AMRConfigMask_UL_ACS | AMRConfigMask_DL_ACS | AMRConfigMask_DL_THRESH)
#define AMRConfigMask_None        0x00   /* This means that the amrConfig is not valid.
                                            It shall be only set by L1I. */

typedef struct
{
   bool          amrEnabled;       /* True if in AMR mode, false otherwise.
                                      Set in L1C L1I_TimerTch.
                                      Used in L1D module. */
   TChMode       channelMode;      /* Downlink TChMode (Useful for AMR).
                                      Set by L1C. */
   AMRFrameType  FrameFormat;      /* Downlink FrameFormat (Useful for AMR).
                                      Set by L1D.
                                      Used in L1D QI module.*/
   bool          isDTX;            /* Assigned by AGC module in afterBlock each RxBlock.
                                      Used in L1D QI module. */
   bool          mon_sub;          /* Reset by L1C and set by L1D.
                                      True if monitored to sub, false if monitored to full. */
//   uint8         fnMod13;          /* Filled by L1C. */ 
   uint8         block24;          /* Filled by L1C, record the tch block24 */

#if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
   bool          burst_IsSaicOn[4];     /* Used in L1D QI module.*/
   int32         burst_EQSoftSum[4];    /* Used in L1D QI module.*/
   int32         burst_C_Value[4];      /* Used in L1D QI module.*/
#else
   int16         burst_CI[4];      /* Used in L1D QI module.*/
   int16         burst_RNV[4];     /* Used in L1D QI module.*/
#endif

} AMRQICompensationData;

/*
@struct DChParams | Parameters for a DCh
*/
typedef struct
{
   int32             frameOffset;        /* @field Synchronisation frame offset */
   intx              ebitOffset;         /* @field Synchronisation eighth bit offset */
   LogChannel        log;                /* @field Type of DCh */
   ARFCN             arfcn;              /* @field C0 ARFCN BSIC of the base station */
   BSIC              bsic;               /* @field BSIC of the base station */
   TSC               tsc;                /* @field The training sequence code */
#ifdef __VAMOS_1__
   uint8             tscSet;             /* @field TSC set, 0 or 1 */
#endif /* __VAMOS_1__ */
   HoppingSequence*  hs;                 /* @field The hopping sequence */
   TChMode           channelMode;        /* @field The main TCh channel mode */
   TChAMRConfig      amrConfig;          /* downlink AMR channel mode */  /*AMR_ENABLE*/
   SubChannel        subChannel;         /* @field The main channels sub channel number */
   bool              dtxAllowed;         /* @field DTX allowed flag
                                               @flag false | DTX not allowed.
                                               @flag true | DTX allowed. */
   TimeSlot          timeSlot;           /* @field The DCh timeslot */
   PowerControlLevel txPower;            /* @field The initial transmit power level as defined in 05.05/4.1.1 */
   TimingAdvance     timingAdvance;      /* @field Initial timing advance in bits */
   Power             powerdBm;           /* @field power in dBm */
   bool              powerControl;       /* @field Initial power control flag
                                               @flag false | base station does not use power
                                                     control during first reporting period.
                                               @flag true | base station uses power control
                                                     during first reporting period. */
   RAChData          rachData;           /* @field Data for RACh bursts during handover */
   intx              handoverRAChCount;  /* @field Number of RACh burst to be transmitted initially.
                                               @flag 0 | No handover.
                                               @flag 4 | Synchronous handover.
                                               @flag 32767 | Asynchronous handover. */
   bool              cipherEnable;       /* @field Ciphering enable flag
                                               @flag false | Ciphering disabled.
                                               @flag true | Ciphering enabled. */
   int8              cipherAlgorithm;    /* @field Cipher algorithm. Valid only if ciphering is enabled. */
   uint8             cipherKey[ 8 ];     /* @field Cipher key . Valid only if ciphering is enabled. */
} DChParams;

typedef enum
{
   UplinkAccessNone,
   UplinkAccessFixed,
   UplinkAccessDynamic,
   UplinkAccessExtendedDynamic
} UplinkAccessMode;

#ifdef __NEW_TBF_ARCH__

#if defined(__EGPRS_MODE__) && defined(__GERAN_RTTI__)
typedef enum
{
   NULL_PDTCH,
   BTTI_PDTCH,
   RTTI_PDTCH
} PdtchConfigMode;

typedef enum
{
   NULL_USF_MODE,
   BTTI_USF_MODE,
   RTTI_USF_MODE,
   MAX_USF_MODE
} UsfMode;

typedef struct
{
   uint8      rxSlot;
   uint8      txSlot;
   bool       valid;     // this pdtch pair is valid or not
}PdtchPair;

typedef struct
{
   PdtchPair         pdtchPair[4]; //class12, max 4 pdtch pairs
   PdtchConfigMode   pdtchCfgMode;
   UsfMode           usfMode;
}PdtchInfo;

extern PdtchInfo pdtchInfo[NUM_TBF];

typedef struct
{
   uint8            pdtchDlSlot[4];   // TS of each pdtch (pair)
   PdtchConfigMode  pdtchCfgMode;     // pdtch (pair) TTI (BTTI/RTTI) 
   UsfMode          usfTtiMode;       // PDTCh related USF mode (UsfMode)
}PdtchRxSet;

typedef enum
{
   PDTCH_NULL_DIR = 0,
   PDTCH_DL_DIR,
   PDTCH_UL_DIR
}PdtchDirection;

#endif /* end of  __GERAN_RTTI__ */

#if defined(__EGPRS_MODE__) && defined(__GERAN_FANR__)
typedef struct
{
   uint8       isDlFANRAct; // bitmap of DL FANR activated,  MSB:TBF7, LSB:TBF0
   uint8       isUlFANRAct; // bitmap of UL FANR activated,  MSB:TBF7, LSB:TBF0
   uint8       isUlSSNBase; // bitmap of UL SSN base(1)/time base(0) if related TBF FANR is activated
}FANRParams;
#endif /* end of __EGPRS_MODE__ && __GERAN_FANR__ */

#ifdef __EGPRS_MODE__
typedef struct
{
   int16              windowSize;
   bool               rlcMode;       // = 1 if ACK mode, =0 if UNACK mode
   uint8              resetIR;       // = 1 if RLC wants to reset IR memory             
   TimeSlotMask       timeSlots;     // need to sync. to sync. slot
#ifdef __GERAN_RTTI__
   TimeSlotMask       txTimeSlots;   // tx timeslot, need to align "RX sync. slot" // should be removed, duplicate of that in UpSpecParams
   PdtchConfigMode    pdtchCfgMode;  // pdtch BTTI/RTTI mode
   UsfMode            usfTtiMode;    // PDTCH related USF mode (UsfMode) // should be removed, duplicate of that in UpSpecParams
#endif  /* end of  __GERAN_RTTI__ */
#ifdef __GERAN_FANR__
   FANRParams         fanr;          // RX FANR info for each TBF // should be removed, duplicate of that in UpSpecParams
#endif  /* end of __GERAN_FANR__ */
}IRParams;

#if (defined(__GERAN_RTTI__) || defined(__GERAN_FANR__))
typedef struct
{
   TimeSlotMask       monitorUsfSlots; // Monitor Slots for USF and TX
#ifdef __GERAN_RTTI__   
   TimeSlotMask       txTimeSlots;     // tx timeslot, need to align "RX sync. slot"
   PdtchConfigMode    pdtchCfgMode;    // pdtch BTTI/RTTI mode
   UsfMode            usfTtiMode;      // PDTCH related USF mode (UsfMode)
#endif  /* end of  __GERAN_RTTI__ */
#ifdef __GERAN_FANR__
   TFI                ulTfi;           // UL TFI for FANR
   FANRParams         fanr;
#endif  /* end of __GERAN_FANR__ */
}UpSpecParams;
#endif /* end of __GERAN_RTTI__ || __GERAN_FANR__ */
#endif

typedef struct
{
#if defined(__EGPRS_MODE__) && defined(__GERAN_FANR__)
   bool               fanrActive;        /* Indicate if FANR Parameters */               
#endif /* end of __EGPRS_MODE__ && __GERAN_FANR__ */
   TimeSlotMask       timeSlots;
   TFI                tfi;

#ifdef __EGPRS_MODE__
   IRParams           ir;
#endif
} MACDownlinkParams;

#ifndef __REMOVE_FA__
typedef struct
{
   TimeSlot           downlinkControlTimeSlot;
   uint8              bitmap[36]; /* one extra byte at the end allows for padding with zeros if
                                     bitmapSize is no multiple of the number of timeslots and
                                     blockPeriods == false */
   intx               bitmapSize;
   bool               blockPeriods;
} MACFixedUplinkParams;

typedef struct
{
   intx dummy;
} MACSingleUplinkParams;
#endif /* __REMOVE_FA__ */

typedef struct
{
   bool usfGranularity;
   USF  usf[8];
} MACDynamicUplinkParams;

typedef struct
{
   UplinkAccessMode          mode;
   TimeSlotMask              timeSlots;
   TFI                       tfi;

#ifdef __EGPRS_MODE__
#if (defined(__GERAN_RTTI__) || defined(__GERAN_FANR__))

#ifdef __GERAN_FANR__
   bool               fanrActive;     /* Indicate if FANR Parameters                */
   bool               isFanrSSNBased; /* KAL_TRUE: SSN based, KAL_FLASE: time based */  
#endif /* end of __GERAN_FANR__ */

   TimeSlotMask       monitorUsfSlots; // Monitor Slots for USF and TX
   
#ifdef __GERAN_RTTI__
   UsfMode            usfMode;
#endif /* end of __GERAN_RTTI__ */

#endif /* end of __GERAN_RTTI__ || __GERAN_FANR__ */
#endif /* end of __EGPRS_MODE__ */ 
   
   union
   {
   #ifndef __REMOVE_FA__
      MACFixedUplinkParams   fixed;
      MACDynamicUplinkParams dynamic;
      MACSingleUplinkParams  single;
   #else /* __REMOVE_FA__ */
      MACDynamicUplinkParams dynamic;
   #endif /* __REMOVE_FA__ */
   }                         data;
} MACUplinkParams;

#else /* __NEW_TBF_ARCH__ */
typedef struct
{
   TimeSlotMask       timeSlots;
   TFI                tfi;

#ifdef __EGPRS_MODE__
   int16              windowSize;
   bool               rlcMode;       // = 1 if ACK mode, =0 if UNACK mode
#endif
} MACDownlinkParams;

typedef struct
{
   TimeSlot           downlinkControlTimeSlot;
   uint8              bitmap[36]; /* one extra byte at the end allows for padding with zeros if
                                     bitmapSize is no multiple of the number of timeslots and
                                     blockPeriods == false */
   intx               bitmapSize;
   bool               blockPeriods;
} MACFixedUplinkParams;

typedef struct
{
   bool usfGranularity;
   USF  usf[8];
} MACDynamicUplinkParams;

typedef struct
{
   intx dummy;
} MACSingleUplinkParams;

typedef struct
{
   UplinkAccessMode          mode;
   TimeSlotMask              timeSlots;
   TFI                       tfi;
   union
   {
      MACFixedUplinkParams   fixed;
      MACDynamicUplinkParams dynamic;
      MACSingleUplinkParams  single;
   }                         data;
} MACUplinkParams;
#endif /* __NEW_TBF_ARCH__ */

typedef struct
{
   TimingAdvance     ta;          /* can be TimingAdvance_INVALID */
   int8              index;       /* can be -1 */
#if defined(__EGPRS_MODE__) && defined(__GERAN_RTTI__)
   TimeSlot          ulTimeSlot;  /* timeslot for UL in RTTI mode*/
   TimeSlot          dlTimeSlot;  /* timeslot for DL in RTTI mode */
#else 
   TimeSlot          timeSlot;    /* valid if timingAdvanceIndex != -1 */
#endif /* end of __EGPRS_MODE__ && __GERAN_RTTI__ */
   int8              burstLength; /* Length of PTCCh/U access burst. Either 8 or 11 */
} PacketTimingAdvance;

typedef struct
{
   bool              valid;
   uint8             alpha;
   uint8             gamma[8];
} PowerControl;

#ifdef __NEW_TBF_ARCH__
typedef struct TBFCommonParams TBFCommonParams;
struct TBFCommonParams
{
   TimeSlot            syncTimeSlot; /* The time slot to synchronise to. This should be chosen so it is equal to smallest timeslot number of all active PDTChs when the TBF is started. */
#if defined(__EGPRS_MODE__) && defined(__GERAN_RTTI__)
   TimeSlot            minTxTimeSlot;/* for RTTI, we should know the min. tx slot */
#endif /* end of __EGPRS_MODE__ && __GERAN_RTTI__ */
   HoppingSequence*    hoppingSequence;
   BSIC                bsic;         /* BSIC of the base station */
   TSC                 tsc;          /* training sequence code */
#ifdef __PS_HO__
   int32               frameOffset;      
   intx                ebitOffset;         
   ARFCN               arfcn;
   //bool              needtoTXAB;
   bool                interRATHO;
   bool                isPending;    /* pending TBF assignment for cell reconnection */
#endif
   PowerControl        powerControl;
   PacketTimingAdvance timingAdvance;
   BTSPowerControl     btsPowerControl;
   bool                pbcchExists;
   bool                tbfMode;                // =0 if in GPRS mode, =1 if in EGPRS mode 
#ifdef __EGPRS_MODE__ 
   IRControl           resetAllVQIR;
#endif
   uint8               useCount;
   TBFCommonParams*    next;
};

typedef struct TBFSpecificParams TBFSpecificParams;
struct TBFSpecificParams
{
   FrameNumber         startingTime; /* Frame number when to start the TBF. Relative to current BS. -1 means immediately. */
   bool                valid;
   uint8               assign_ref;   /* reference id used by L1A */

#if defined(__EGPRS_MODE__) && defined(__GERAN_RTTI__)
   PdtchConfigMode     pdtchCfgMode;
#endif /* end of __EGPRS_MODE__ && __GERAN_RTTI__ */

   TBFSpecificParams*  next;

   union
   {
      MACDownlinkParams down;
      MACUplinkParams   up;
   }macParams;
};

typedef struct
{
   TBFCommonParams*     common;
   TBFSpecificParams*   down[NUM_TBF];
   TBFSpecificParams*   up[NUM_TBF];
} TBFParams;

#else /* __NEW_TBF_ARCH__ */
typedef struct
{
   FrameNumber         startingTime; /* Frame number when to start the TBF. Relative to current BS. -1 means immediately. */
   TimeSlot            syncTimeSlot; /* The time slot to synchronise to. This should be chosen so it is equal to smallest timeslot number of all active PDTChs when the TBF is started. */
   HoppingSequence*    hoppingSequence;
   BSIC                bsic;         /* BSIC of the base station */
   TSC                 tsc;          /* training sequence code */
   PowerControl        powerControl;
   PacketTimingAdvance timingAdvance;

   BTSPowerControl     btsPowerControl;

   bool                downValid;
   MACDownlinkParams   down;

   bool                upValid;
   MACUplinkParams     up;

   bool                pbcchExists;
   uint8               assign_ref;   /* reference id used by L1A */

#ifdef __EGPRS_MODE__
   bool                tbfMode;      // =0 if in GPRS mode, =1 if in EGPRS mode
   bool                resetIR;      // =1 if RLC wants to reset IR memory
#endif

} TBFParams;
#endif /* __NEW_TBF_ARCH__ */

typedef struct
{
   Power        txPower;
#ifdef __EPSK_TX__
   Power        txPowerEPSK;
#endif
   uint8        bufferIndex;
#ifdef __NEW_TBF_ARCH__
   uint8        tbfIndex;
#endif /* __NEW_TBF_ARCH__ */
} PacketBlockSpec;

typedef struct
{
   TimeSlotMask     timeSlots;
   TimingAdvance    timingAdvance;
   PacketBlockSpec  blocks[4];
} PacketUplinkSpec;

typedef struct
{
   TimeSlotMask timeSlots;
#if defined(__EGPRS_MODE__) && defined(__GERAN_RTTI__)
   PdtchRxSet       pdtchRxSet[NUM_TBF];
   uint8            pdtchDlSlot[4];   // TS of each pdtch (pair)
   PdtchConfigMode  pdtchCfgMode[4];  // pdtch (pair) TTI (BTTI/RTTI) 
   UsfMode          usfTtiMode[4];    // PDTCh related USF mode (UsfMode)
#endif /* end of __EGPRS_MODE__ && __GERAN_RTTI__ */
} PacketDownlinkSpec;

typedef struct
{
   PacketUplinkSpec   up;
   PacketDownlinkSpec down;
} PacketTransferSpec;

typedef enum
{
   DChDataModeTrans,
   DChDataModeFax1,
   DChDataModeFax2,
   DChDataModeNonTrans
} DChDataMode;

/*
@union l1c_d_intf_params | Report data for received block reporting.
*/
typedef union
{
   uint8 sim_idx;
} l1c_d_intf_params;


/*
(A) set by L1I_AllocRxReport()
(B) set by L1I_ReportRxBurstData()
(C) initialised by L1I_AllocRxReport(), updated by L1I_ReportRxBurstData()
(D) set by channel handler
(E) set by hardware driver
*/
/*
@struct RxSlotData | Report data for received block reporting.
*/

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
typedef struct
{
   BlockData*     data;

   bool           ok;            /* for GSM, GPRS, EGPRS header part, use this field */
   bool           data1Ok;       /* for EGPRS data part, use this field
                                    when GSM, or type is CS1~4, this field has no meaning */
   bool           data2Ok;       /* for EGPRS data part of 2nd RLC blk, use this field
                                    when MCS type is not 7~9, this field has no meaning */
#if defined(__EGPRS_MODE__) && defined(__GERAN_FANR__)
   bool           panOK;
#endif /* end of __GERAN_FANR__ */

   USF            usf;           /* @field (E) Received USF */
   TimeSlot       timeSlot;      /* @field (E) Time slot number */
   CodingScheme   codingScheme;  /* @field (E) Coding scheme. */
   uint8          modScheme;     /* for results of blind detection, L1 internal use */
   int16          snrSum;        /* @field (C) Sum of SNR of all bursts */
   uint16         irDecision;      /* DSP DSP IR Decision */
   Power          power[4];      /* @field (B) Power for bursts in dBm */
   intx           powerCount;    /* @field (C) Number of burst in power[] */
   intx           bitErrorCount; /* @field (E) Sum of bit errors. */
   intx           bitCount;      /* @field (E) Sum of bits. */
   bool           discardPrevBitError; /* @field (E) Flag of discard previous bit error information */
   intx           timingErrorSum;      /* @field (C) Sum of timing errors of all bursts in good blocks in ebits
                                          for GMSK only, L1 internal use */
   intx           timingErrorCnt;      /* @field (C) Number of values added in timingErrorSum
                                          for GMSK only, L1 internal use*/
   intx           epskTimingErrorSum;  /* @field (C) Sum of timing errors of all bursts in good blocks in ebits
                                          for 8PSK only, L1 internal use */
   intx           epskTimingErrorCnt;  /* @field (C) Number of values added in timingErrorSum
                                          for 8PSK only, L1 internal use */

   intx           meanBep;             /* Mean_BEP(block), L1 internal use if not in EGPRS mode*/
   intx           cvBep;               /* CV_BEP(block), L1 internal use if not in EGPRS mode */

} RxSlotData;
#else /*IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION*/
typedef struct
{
#ifdef __PS_SERVICE__
   BlockData data[ 54 ];    /* @field (E) Received block data. Invalid for speech block */
                            /* at beginning of this structure, make it pointer as even address,
                               help L1D to move data in word */
#else /*__PS_SERVICE__*/
   BlockData data[ 38 ];    /* @field (E) Received block data. Invalid for speech block */
                            /* at beginning of this structure, make it pointer as even address,
                               help L1D to move data in word */

#endif   /*__PS_SERVICE__*/
   bool      ok;                  /* @field (E) Block status for the timeslot.
                                      @flag false | Block was bad. Data is invalid.
                                      @flag true | Block was OK. Data is valid. */
   USF       usf;                 /* @field (E) Received USF */

   Power     power[4];            /* @field (B) Power for bursts in dBm */
   intx      powerCount;          /* @field (C) Number of burst in power[] */
   intx      bitErrorCount;       /* @field (E) Sum of bit errors. */
   intx      bitCount;            /* @field (E) Sum of bits. */
   bool      discardPrevBitError; /* @field (E) Flag of discard previous bit error information */
   TimeSlot  timeSlot;            /* @field (E) Time slot number */
   CodingScheme codingScheme;     /* @field (E) Coding scheme. */
   int16     snrSum;              /* @field (C) Sum of SNR of all bursts */

   intx      timingErrorSum;      /* @field (C) Sum of timing errors of all bursts in good blocks in ebits */
   intx      timingErrorCnt;      /* @field (C) Number of values added in timingErrorSum */

   intx      meanBep;             /* Mean_BEP(block), L1 internal use if not in EGPRS mode*/
   intx      cvBep;               /* CV_BEP(block), L1 internal use if not in EGPRS mode */
} RxSlotData;
#endif   /*IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION*/

/* Report forward declaration */
typedef struct Report Report;

/*
@struct RxData | Report data for received block reporting.
*/
typedef struct
{
   FrameNumber frameNumber;    /* @field (A) Frame number of the first burst of
                                             the block.                       */
   ARFCN       arfcn;          /* @field (A) BCCh carrier of base station
                                             sending this block.              */
   bool        isBCChBurst[4]; /* @field (B) true for each burst received on
                                             the BCCh carrier                 */
   int8        slotCount;      /* @field (A) Number of slots used. Always 1
                                             except for PDTCh                 */
#ifdef __PS_SERVICE__
   RxSlotData  slot[4];        /* @field     Data for receive timeslots       */
#else
   RxSlotData  slot[1];        /* @field     Data for receive timeslots       */
#endif
#if IS_REPEATED_ACCH_SUPPORT  
   bool        isCombinedACCh; /* Valid only for Repeat ACCh */
#endif
   bool        isSID;          /* determined by L1D based on the decision of DSP */
   bool        isDTX;          /* determined in AGC*/

   bool        isFACCh;        /* @field (D) Valid only for ReportTCh. true if
                                             block is a FACCh block           */
   /*AMR_ENABLE*/
   bool        isRATSCCh;      /* @field (D) Valid only for ReportTCh. true if
                                             block is a AMR RATSCCh block           */
   bool        isCSD;          /* @field (D) Valid only for ReportTCh. true if
                                             block is a CSD block           */
   int8        tc;             /* @field (D) Valid only for ReportBCCh,
                                             ReportNBCCh, ReportCBCh. Value of
                                             TC of the received block
                                             ((FN/51)%8)                      */
   bool        extended;       /* @field (D) Valid only for ReportBCCh,
                                             ReportNBCCh, ReportCBCh, ReportPCh,
                                             ReportPPCh. true if the block has
                                             been received on the extended
                                             channel                          */

   /* flag for ignoring timing error of this report after timing adjust */

   int8        timingTag;      /* (A) layer1 internal use */

   int8        blockNo;        /* (A) layer1 internal use. 0..2 */

   /* points to report for reporting period if this report is monitored */

   Report*     monitorReport;  /* (A) layer1 internal use */

   /* used to handle the TCh  */

   uint8       flags;          /* (A) layer1 internal use */

   /* used to determine if bursts receive on BCCh should be used for power averaging */

   bool        powerControl;   /* (A) layer1 internal use */

   bool        allocationExhausted; /* @field (D) Valid only for ReportPDTCh and
                                                  ReportPDTChConflict. It is only
                                                  applicable to fixed allocation and
                                                  not applicable to (ext-)dynamic
                                                  allocation.                        */
   TimeSlot    syncTimeSlot;   /* (A) layer1 internal use */

   AMRQICompensationData amr;  /*QI Compensation*/

#ifdef __NEW_TBF_ARCH__
   uint8       dlTBFtid[NUM_TBF];
#else /* __NEW_TBF_ARCH__ */
   bool        isBeforeStartingTime;   // =1 in the last block of old TBF when DL TBF+DL TBF and resetIR=1
   uint16      newTBFtid;

   uint8       dlTBFtid;
#endif /* __NEW_TBF_ARCH__ */
      
  ReportPDTChType   reportPDTChType;
      
#ifdef __EGPRS_MODE__
   bool        outOfMem;   // outOfMem=1 if MS is out of memory, =0 otherwise
   bool        isEdge;     // to change setpoint in EDGE mode PDTCh, only valid in ReportPDTCh
   #ifdef __NEW_TBF_ARCH__
   uint16      dspVQ[NUM_TBF];      // DSP reports its V(Q)
   #else
   uint16      dspVQ;               // DSP reports its V(Q)
   #endif
   uint16      availableIRBlocks;   // DSP reports available blocks in IR memory
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   int8        allocatedSlotCount;  // for L1I_AllocMultislotRxReport, alloc/free data sector pointer
#endif
#ifdef __GL1_MULTI_MODE__
   intx        ppch_fn;
#endif

#if IS_SINGLE_END_BER_SUPPORT
   uint8       pre_snr[4]; // for NSFT Single-End BER feature
#endif

#ifdef __SMART_PAGING_IN_IDLE__
   Power serving_power_in_quarter_dBm;
#endif /*__SMART_PAGING_IN_IDLE__*/

#if IS_2G_TAS_SUPPORT
   intx              snrSumTAS;   /*@field (C) Sum of SNR of one block for TAS */
   uint8             snrCountTAS;  /*@field (C) Count of SNR of one block for TAS */
   TransmitAntenna   antenna;  /*@field (C) Antenna status for TAS */
#endif /*IS_2G_TAS_SUPPORT*/

} RxData;

typedef struct
{
   FrameNumber  frameNumber;
   intx         blockCount;
   BlockData*   blockData[4];
   CodingScheme codingScheme[4]; /* only valid for PDTCh */
   TimeSlotMask pollTimeSlots;   /* only valid for PDTCh, timeslots where poll responses have been sent */
   bool         ok;
   Power        rach_tx_power_dbm;  //SYY: to report the tx power used on rach
} TxData;

typedef struct
{
   FrameNumber   frameNumber;   /* first frame of new DCh */
   TimingAdvance timingAdvance; /* last used timing advance on old DCh */
   intx          sacchPosition; /* position of the SACCh. 0=>12, 1=>25, 2=>38 ... */
   AfcParams     afc;
   ARFCN         arfcn;
} DChData;

#ifdef __NEW_TBF_ARCH__
typedef struct
{
   FrameNumber      frameNumber;       /* first frame of new TBF */
   TimeSlot         startTimeSlotFBSB; /* layer1 internal use. Start timeslot to search FB or SB */
   TimeSlot         syncTimeSlot;
   HoppingSequence* hs;

   uint8            downValid;
   uint8            assign_ref_dl[NUM_TBF];        /* reference id used by L1A */   
   TimeSlotMask     downTimeSlots;
   
   uint8            upValid;
   uint8            assign_ref_ul[NUM_TBF];        /* reference id used by L1A */   
   TimeSlotMask     upTimeSlots;
   
   uint8            stopTid;
   
   TID              upTid[NUM_TBF];
   TID              downTid[NUM_TBF];       

   TID              upTBFStartTid[NUM_TBF];      /* To prevent L1A and L1C unsync after moving TBFStart&Stop to queuedFunc */
   TID              downTBFStartTid[NUM_TBF];       

#ifdef __PS_HO__
   bool             needToSetSync;                      /* For PS handover, inform L1A to call SurroundSetSync. */
#endif          
   bool             CancelGAPDueToTSReconfig;   /* Cancel GAP since extra Margin for TD is no 
                                                 * more available after TS reconfig */
} TBFData;

#else /* __NEW_TBF_ARCH__ */
typedef struct
{
   FrameNumber      frameNumber;       /* first frame of new TBF */
   TimeSlot         startTimeSlotFBSB; /* layer1 internal use. Start timeslot to search FB or SB */
   uint8            assign_ref;        /* reference id used by L1A */
   TimeSlot         syncTimeSlot;
   bool             downValid;
   TimeSlotMask     downTimeSlots;
   bool             upValid;
   TimeSlotMask     upTimeSlots;
   HoppingSequence* hs;
   uint8            stopTid;
   TID              uptid;
   TID              downtid;
   uint8            newtbfdir;         /* TBF direction: 1->downlink only, 2->uplink only, 3->both direction. */
} TBFData;
#endif /* __NEW_TBF_ARCH__ */

typedef struct
{
   bool             onCurrentDCh; /* true if the DCh where the hopping sequence
                                     has been set is the active one */
   HoppingSequence* hs;           /* valid only when onCurrentDCh equals true */
} HoppingSequenceSetData;

/*
@struct AMRData | Information about current used AMR parameter.
*/

typedef struct
{
   kal_uint8  amr_valid;         /* AMR enable or not */
   bool       dl_dtx;
   kal_uint8  CMR_CMC_CMIu_CMId; /* CMR, CMC, CMI */
   kal_uint8  C_I;               /* C/I */
   kal_uint16 ICM;               /* initial codec mode */
   kal_uint16 ACS;               /* active codec mode */
} AMRData;

/*
@struct ReportPeriodData | Information about last reporting period.
*/
typedef struct
{
   bool          dtxUsed;  /* set by hardware driver */

   MonitorResult monitor;  /* set by layer1 core */
   intx          useCount; /* layer1 internal use */
   AMRData       amr;      /* @field send AMR parameter to engineer mode*/
   Power ReportCurrentTxPwr;   /* Jeff Lee 20100423: Report current Tx power in dBm, for ZTENJ AT&T requirement*/
} ReportPeriodData;

/*
@struct PowerScanData | Results of power scan.
*/
typedef struct
{
   PowerScanResults* results; /* @field <t PowerScanResults> structure passed to <f L1T_PowerScanStart> */
   Measurements      meas;    /* layer1 internal use */
} PowerScanData;

typedef struct
{
   ScanList*    list; /* layer1 internal use */
   Measurements meas; /* layer1 internal use */
   Report*      lock; /* layer1 internal use */
} MeasurementData;

typedef struct
{
   Power        power[8];
   TimeSlotMask timeSlots;
   uint8        assign_ref;
} InterferenceData;

typedef struct
{
   intx             baListId;
   uint8            count;
 /*ARFCN            arfcn[L1_SURROUND_MAX_CELLS];*/
 /*Power            power[L1_SURROUND_MAX_CELLS];*/
   ARFCN           *arfcn;
   Power           *power;
#ifdef __GL1_MULTI_MODE__
   //kal_uint16       drx_len;  /* 80, 160, 320, 640, 1280, 2560, 5120. (msec) */
   //kal_uint8        Tmeas_drx_num;
   kal_uint16       bsic_reconfirm_para;
   bool             gapfor3g;
   kal_bool         is_not_all_arfcn_measured;
#ifdef  __GERAN_R8__   
   kal_bool           is_higher_priority;
#endif  /* __GERAN_R8__ */   
#endif
} SurroundCellData;

#if defined(__GL1_MULTI_MODE__) || IS_TDD_DUAL_MODE_SUPPORT
typedef struct
{
   Time           sync_time;
   kal_uint32     gsm_ustime; //uscounter time
} SyncTimeData;
#endif

#ifdef __GL1_MULTI_MODE__

typedef struct
{
   Time           starting_time;
   kal_uint32     len;
   kal_uint8      repeat_count;
   kal_bool       is_drx_tick;  /* after multimode, only need to inform drx_tick */
   kal_uint8      tid;  //remove
   kal_uint8      gap_service_tid; //used for gap_notify, from mll1
} GapPatternData;

typedef struct
{
   kal_uint16 afc_dac;
} AfcData;

typedef struct
{
   kal_uint16 drx_len;
} DRXTick;

typedef struct
{
   kal_uint8 pmTid;
#ifdef  __GERAN_R8__   
   kal_bool  is_higher_priority;
#endif  /* __GERAN_R8__ */   
} PmDoneData;

#ifdef __GL1_MULTI_MODE__ 
typedef struct
{
   Time           starting_time;
   kal_uint32     length;   
} AutoGapData;
#endif

#endif
typedef struct
{
   int16  iOffset;
   int16  qOffset;
   Power  power;
} PMResult;

#if ( defined( __L1_GPS_AUTO_TIMING_SYNC_SUPPORT__  ) || defined( __L1_GPS_REF_TIME_SUPPORT__  ) )
typedef enum _l1_agps_frame_sync_app_E
{
   L1_FINE_TIME_ASSISTANCE_APP = 0,
   L1_REFERENCE_TIME_UNCERTAINTY_APP,
   L1_FRAME_TIME_AIDING_APP,
   L1_FRAME_SYNC_APP_END
} l1_agps_frame_sync_app_E;

typedef enum _l1_agps_frame_sync_fail_reason_E
{
   L1_NO_FAILURE = 0,            // OK
   L1_CELL_NOT_FOUND,            // No service 
   L1_L1_NOT_ACTIVE,             // 2G NOT ACTIVE
   L1_TIMING_ERROR_CHECK_FAIL,   // TYPE 2, no usage in 2G
   L1_TIMING_CALC_IN_OTHER_RAT,  // gemini W+G, timing is calcuated by 3G RAT
   L1_NOT_SERVING_CELL,          // bad ARFCN or BSIC of serving cell
   L1_FRAME_SYNC_FAIL_REASON_END
} l1_agps_frame_sync_fail_reason_E;

typedef struct
{
   l1_agps_frame_sync_app_E                   type;         // timing sync. type from GPS task
   l1_agps_frame_sync_fail_reason_E           fail_reason;  // Reason for GPS task
   ARFCN                                      servingArfcn; // GPS type II timing sync. result from l1c
   BSIC                                       servingBisc;  // GPS type II timing sync. result from l1c
   kal_bool                                   result_valid; // All types, result from l1d
   Time                                       l1_time;      // All types, result from l1d
   kal_uint64                                 local_time;   // All types, result from l1d
} L1GpsTimeSync_T;
#endif /* End of ( defined( __L1_GPS_AUTO_TIMING_SYNC_SUPPORT__  ) || defined( __L1_GPS_REF_TIME_SUPPORT__  ) )*/

/*
@union ReportData | Contains report information
*/
typedef union
{
   RxData                  rx;           /* @field Results of normal receives */
   TxData                  tx;
   DChData                 dch;
   TBFData                 tbf;
   HoppingSequenceSetData  hsSet;
   SChData                 sch;          /* @field Results of FCB and SB search */
   ReportPeriodData        rp;           /* @field End of report period information */
   PowerScanData           powerScan;    /* @field Power scan results */
   MeasurementData         meas;         /* @field Surround power measurement results */
   InterferenceData        interference; /* @field Interference measurement results */
   SurroundCellData        sc;           /* @field surround cell and NC results */
   PM_TST_Data             pm_tst;       /* @field power meas results in test mode */
   HoppingSequence*        hs;           /* layer1 internal use */
#if defined(__GL1_MULTI_MODE__) || IS_TDD_DUAL_MODE_SUPPORT
   SyncTimeData            sync;
#endif
#ifdef __GL1_MULTI_MODE__
   GapPatternData          gap;
   DRXTick                 drxTick; 
//   Gap_service_2G_enum     gapService;  /* gapservice will be decided by L1A */
   PmDoneData              pmDone;

#ifdef __GL1_MULTI_MODE__    
   AutoGapData             autoGap;
#endif
#endif
#if IS_FHC_SUPPORT
   ResultDTS              *dts_result;
#endif
#if ( defined( __L1_GPS_AUTO_TIMING_SYNC_SUPPORT__  ) || defined( __L1_GPS_REF_TIME_SUPPORT__  ) )
   L1GpsTimeSync_T   gps_time_sync;
#endif
} ReportData;

typedef struct     /* !!important: please update the copy in m12194.c */
{
   Power defaultPower;
   Power bestPower;
   Power underflowPower;
   Power overflowPower;
   Gain  underflowReportPower;
   Gain  overflowReportPower;
} AGCParams;

typedef struct AGCDataStruct AGCData;

typedef struct
{
   Power ( *predict )( AGCData* p, ARFCN arfcn, TimeSlot timeSlot );
   void  ( *update )( AGCData* p, ARFCN arfcn, TimeSlot timeSlot, Power antennaPower, intx rangeError );
   void  ( *beforeBlock )( AGCData* p, TimeSlotMask timeSlots );
   void  ( *afterBlock )( AGCData* p, TimeSlotMask timeSlots );
} AGCAlgorithm;

typedef struct
{
   ARFCN bcchARFCN;        /* ARFCN of BCCh carrier */
   Power powerReductionPb; /* power reduction of PBCCh relative to BCCh */
   Power* bcchPower;       /* location to store power */
} AGCCellData;

typedef struct
{
   Power averagePower;
   uint8 overflows;
   uint8 underflows;
   uint8 good;
   uint8 total;
   uint8 goodsnr;
} AGCTimeSlotData;

typedef struct
{
   Power input_power;
   Gain  gain;   
} AGCGainTableData;

typedef struct
{
   AGCTimeSlotData tsd[8];
} AGCDataDTX;

#ifdef __NEW_TBF_ARCH__
typedef struct
{
   Power*          timeSlotPowerOffset;
   BTSPowerControl btsPowerControl;
   TFI             downlinkTFI[NUM_TBF];
   TFI             uplinkTFI[NUM_TBF];
   const USF*      usf[NUM_TBF];
} AGCDataPDTCh;

#else /* __NEW_TBF_ARCH__ */
typedef struct
{
   Power*          timeSlotPowerOffset;
   BTSPowerControl btsPowerControl;
   TFI             downlinkTFI;
   TFI             uplinkTFI;
   const USF*      usf;
} AGCDataPDTCh;
#endif /* __NEW_TBF_ARCH__ */

typedef struct
{
   AGCCellData      servingCell;
   const AGCParams* servingBandParams;
#ifdef __PS_SERVICE__
   bool             servingPBCChExists;
   Power            interferencePower;
#endif
   AGCDataDTX       dtx[2];
   intx             nextDTX;
   Power            gainoffset;

   Power            timeSlotPower[8];
   TimeStamp        timeSlotTimeStamp[8];
   TimeStamp        servingBCChTimeStamp;

} AGCServingDB;


struct AGCDataStruct
{
   const AGCAlgorithm* algorithm;  /* channel specific algorithm */
   const AGCParams*    bandParams; /* band specific AGC limits */
   AGCCellData*        cell;       /* cell specific data */
   AGCDataDTX*         dtx;
   AGCDataPDTCh*       pdtch;      /* PDTCh algorithm specific data */
   TimeSlot            syncTimeSlot;
   TimeSlotMask        timeSlots;  /* rx time slots filled by L1D */
   AGCServingDB*       servingInfo;/* Serving cell AGC parameters   */
};


/* It is used in m11303.C and m11303_2.c */
typedef struct
{
   Power      bcchPower[ARFCN_COUNT];

} AGCPowerDB;

#ifdef __GL1_GEMINI__
typedef enum
{
   ConflictWithNONE = 0,
   ConflictWithGSM_NBCCh  = 5, /*Original 4. Modify for BCCH sharing feature*/
   ConflictWithGSM_PCh    = 6,   
   ConflictWithGSM_BCCh   = 7,
   ConflictWithGSM_Others = 8,
   ConflictWithCDMA2000     = 9,
   ConflictWithUMTS_SIB_HIGH = 10,
   ConflictWithUMTS_PICH     = 11,
   ConflictWithUMTS_SIB_LOW  = 12,
   ConflictWithUMTS_Others   = 13,
   ConflictWithLTE_BCCh       = 14,
   ConflictWithLTE_NBCCh_HIGH = 15,
   ConflictWithLTE_NBCCh_MID  = 16,
   ConflictWithLTE_NBCCh_LOW  = 17,
   ConflictWithLTE_PCh        = 18,
   ConflictWithLTE_Others     = 19
} ConflictType;
#endif

/*
tid (transaction id) is used to handle race conditions when dealing with reports.
tid is the value of the transaction id when the report was generated.
If PH stops a channel, it increments the channels transaction identifier.
The report is then invalid because (report->tid != 'channel'.tid)
*/
/*
@struct Report | Results of operations.
*/
struct Report
{
   ReportType     type; /* @field Type of report */
   void        ( *callback )( Report* ); /* layer1 internal use */
   TID            tid;                   /* layer1 internal use */
   bool           real_received;
   ReportData     data; /* @field Contains information dependent on the <e Report.type> field */

   void*          chan; /* layer1 internal use. Channel specific data */
   AGCData        agc;

#ifdef L1C_DEBUG
   bool           needToCallMonitorReport;
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   bool           isRxReport;
#endif

#ifdef __GL1_GEMINI__
   bool           unadjustedTimer;
   bool           Aligned;
   uint8         shareBitmap;
   kal_uint16     priorityIndex;
   TID            tid_sharing[L1C_SIM_NUM];
   ConflictType   conflictTimer;
#endif

#ifdef __PS_HO__
   TID            celltid;   /* layer1 internal use for PS handover */
#endif
};

/*
@struct sMTMAXTIME | To measure the maximum execution time.
*/
typedef  struct
{
   int16       tq_start;
   int16       max_start;
   int16       max_end;
   int16       max_diff;

}  sMTMAXTIME;


/*
@struct SBATMEASARG | To periodically measure the battery voltage & temperature
*/
typedef  struct
{  int  period;    /* peiod of updating the measurement result  */
   int  count;     /* sample count to average in one period */
}  SADCMEASARG;

typedef   struct
{  SADCMEASARG  voltage;
   SADCMEASARG  temperature;
   SADCMEASARG  rf_temperature;
}  SBATMEASARG;

/* We don't need Dula/Single OS Tick and Wake-up INT feature for Venus_3G project */
/* For CSMM, we don't need create sm Global structure in l1_type.h, too. */
#if !defined(__NEW_OS_TICK__) && !defined(__CENTRALIZED_SLEEP_MANAGER__)
typedef struct
{
   uint32   sleepDisable;
   volatile uint32   fmResult;
   bool     calbrating;
   uint8    handleCount;
   /* Modified by Anthony Chin for SM 04/17/2002. */
   uint8    handle;
   uint8    gprs_im_sleep_handle; //SM_WAKEUP_COMPENSATION
   bool     rf_sleep;
   uint32   multiplyConstant;
   uint32*  hanlde_ptr;
   bool     sm_init; /* record if SM has been init. */
} SM_Globals;
#endif


#ifdef __BLIND_HANDOVER__

typedef enum
{
   BlindHOPhase0,
   BlindHOPhase1,
   BlindHOPhase2

} BlindHO_Phase;

#endif

#ifdef L1A_SIM
/* elly, for L1 simulation use */
typedef struct _l1c_l1a_report_struct
{
   LOCAL_PARA_HDR
   Report      report;
} l1c_l1a_report_struct;
#endif

//#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
typedef enum
{
   PowerScanStop,
   NotVirtualPowerScan,  /* power scan in normal mode or not IN_SCAN */  
   VirtualPowerScan,
   VirtualPowerScanRestarted,
} VirtualPowerScanState;
//#endif

typedef enum
{
   SameAsBefore,
   ForPLMNList,
   NotForPLMNList
}PowerScanPurpose;

/*
@struct PowerScanParamStruct | Configurarble parameter for full-power scan & stored list power scan (m11410).
*/
typedef struct
{
   int8   sampleNo;                 /* @field: Measurement sample number. 
                                       Assigned by L1A in Gemini2.0. Valid range: 2~5. Default: 5*/	
//#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
   VirtualPowerScanState   virtual_powerscan_state;
#ifdef __GL1_MULTI_MODE__
   bool is_first_session;        /* @field: Is this the first timerScan in this round, checked by L1C*/				   	
#endif
//#endif /*__GEMINI_MONITOR_PAGE_DURING_TRANSFER__*/
   intx   pm_count_in_one_session;  /* @field: How many PM will do in one seesion. Calcualted by L1C*/
   uint32 sessionDelayEbits;        /* @field: PM session duration (ebit). Clculated by L1C*/	
#if IS_GL1_NEW_GEMINI
   uint16 accuPMCount;     /*@filed: Accumualted sample number in 2G Gemini null mode */
   uint32 accuSessionDelayEbits;  /*@filed: Accumualted session delay in 2G Gemini null mode */
   uint32 expectedSessionDelayEbits;  /*@filed: Expected session delay in 2G Gemini null mode */
#endif /* IS_GL1_NEW_GEMINI */
#ifdef __GL1_QUICK_MCC_SEARCH__
   bool is_quick_mcc_search;
#endif
#ifdef __GL1_GEMINI_WCDMA__
   PowerScanPurpose purpose;
#endif
#ifdef __PLMN_LIST_IN_VIRTUAL_MODE__
   uint32 scanPeriod;
   uint32 scanLength;
#endif
} PowerScanParamStruct;

#ifdef __GL1_GEMINI__
/*
@struct ProtectionParamStruct
*/
typedef struct
{
   uintx chan_hdlr_bitmap;
} ProtectionParamStruct;
#endif /*__GEMINI_MONITOR_PAGE_DURING_TRANSFER__*/

typedef enum
{
   MODE_NORMAL,
   MODE_META,
} L1dOperationMode;

#if IS_DUAL_CORE_GL1AC_MODEM_SUPPORT
typedef struct
{
   /* L1C register this callback function when L1D query for TX data,                     */
   /* L1D will call this callback function right after L1D get TX data from shared buffer */
   void (*l1i_gettxdatadone)(void *data_ptr, l1c_sim_mode_enum sim_num, void *shared_buff_ptr, kal_bool tx_data_ready);
   /* the pointer for the struct of callback function arguments */
   void *data_ptr;
   /* SIM info */
   l1c_sim_mode_enum sim_num;
} QueryTxDataCallback;
#endif /* IS_DUAL_CORE_GL1AC_MODEM_SUPPORT */
#endif /*End of File*/

