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
 *
 * Filename:
 * ---------
 * libParserDbModem.c
 *
 * Project:
 * --------
 * MOLY
 *
 * Description:
 * ------------
 * This file collects primitve IDs and struct definition from the Modem
 * application part for pre-processing.
 *
 * Author:
 * -------
 * -------
 *
 * =============================================================================
 * $Log$
 *
 * 10 14 2019 amit.singh
 * [MOLY00446495] [Gen91] keep-alive check-in for CTS test support
 * 	
 * 	KPALV check-in.
 *
 * 09 22 2017 roland.li
 * [MOLY00278776] LPPe feature development [LPPe] LPP_EXT part.
 *
 * 02 24 2017 tc.chang
 * [MOLY00231731] [PAM][VzW] CDMA-less related.
 *
 * 10 06 2016 tc.chang
 * [MOLY00206332] [91LWA][MP5][WAAL] rel-13 LWA feature check-in.
 *
 * 08 19 2016 wynne.chu
 * [MOLY00179141] [PH1_VZW] Request to check about TOOL that can check SUPL/CP status
 * 	
 * 	.
 *
 * 06 20 2016 sungshen.wu
 * [MOLY00185559] BT dump check in
 * 	
 * 	.check in bt audio dump
 *
 * 05 05 2016 tsung-wei.tu
 * [MOLY00168704] [MT6291][VzW]  RRC release version for MDMI
 * .
 *
 * 04 22 2016 wynne.chu
 * [MOLY00170121] [LBS] Report position infomation to ELT
 * 	
 * 	.
 *
 * 01 25 2016 roland.li
 * [MOLY00159914] [LBS]Fine time feature
 * 	
 * 	.
 *
 * 01 25 2016 roland.li
 * [MOLY00159914] [LBS]Fine time feature
 * 	
 * 	.
 *
 * 01 07 2016 kuan-ting.lee
 * [MOLY00074164] 6291 IDC Development
 * removed el1_ipc_structure.h in pcore.
 *
 * 01 06 2016 kuan-ting.lee
 * [MOLY00074164] 6291 IDC Development
 * showing ilm msg in pcpre and l1 core.
 *
 * 10 28 2015 woody.kuo
 * [MOLY00146631] [System Service][MOLY Kernel Internal Request] redmine Task #3013 [LR11] PDCA Improvements From JADE 1st line
 * .
 *
 * 10 22 2015 lexel.yu
 * [MOLY00146327] [VzW] hVoLTE implementation
 * 	[hVoLTE] VDM
 *
 * 10 15 2015 tee-yuen.chun
 * [MOLY00143617] CR for code submitting of MDDBG and MD Debugger API
 * [MDDBG] 
 * 1.took off hard coding debug sys clock force on.
 * 2. Correction of compile option in header file and took off compile option determination in .c files.
 * 3. added DB for enum table in libParseDbModem.c for pcore(l1core had been existed)
 *
 * 10 12 2015 guo-huei.chang
 * [MOLY00144627] ELT trace for TPPA+MET
 * 	TPPA Trace for Pcore Sleep
 *
 * 09 23 2015 kuan-wei.chen
 * [MOLY00115378] SS code revise
 * ciss agps ut
 *
 * 09 10 2015 cynthia.sun
 * [MOLY00141032] Display core name instead enum for EMI buffer log
 * .
 *
 * 09 09 2015 chuangde.zhang
 * [MOLY00141120] Add Lapdm frame type to database
 * .
 *
 * 09 01 2015 roland.li
 * [MOLY00092193] [UMOLY][LPP]LPP R10R11 feature checkin
 * 	.
 * 	#include "lpp_msgid.h" in libParseDbModem.c.
 *
 * 08 24 2015 peter.hsu
 * [MOLY00138390] UL Data Throttling v2
 * [TMC][IPCORE] UL Data Throttling v2
 * - Add new module TMC (Thermal Management Controller)
 * - Add IMS Blocking mode
 *
 * 08 06 2015 kuan-wei.chen
 * [MOLY00115378] SS code revise
 * ciss ut
 *
 * 07 15 2015 tc.chang
 * [MOLY00125159] [MT6291][L234 NW-UE SIM][4G][eMBMS][17.1.2] Failed at step 10: "MBMS Counter value not greater than 0"
 * Set search_time as 15 sec.
 *
 * 06 12 2015 roland.li
 * [MOLY00109917] [6291][LBS]MDT check in to UMOLY TRUNK
 * .[LPP][UMOLY] Add EMI BW contril API.
 *
 * 06 11 2015 yu-hung.huang
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * [UMOLY][DVFS] PCore DVFS Driver First Version
 *
 * 06 02 2015 eason.lai
 * [MOLY00117932] [TK6291][DHL] enable L2_BOXSTER trace
 * move L1/L2 boxster typedef to L1trc.h
 *
 * 05 25 2015 cen.chen
 * [MOLY00109047] [UMOLY][new feature] Pich false alarm Optimization.
 * Modify for Modis.
 *
 * 05 20 2015 poying.chuang
 * [MOLY00109756] [MT6291][R11][NAS] SIC: SM IE Configuration check in
 * 	- TCM:SIC: Interfaces .
 *
 * 04 20 2015 yh.sung
 * [MOLY00108029] [TK6291] META mode related modifications
 * 	[New Feature]
 * 	1. MMRF runtime update
 * 	2. META MMRF commands
 *
 * 04 16 2015 george.chang
 * [MOLY00107870] [6291] LAS UBIN phase 2 check in to UMOLY TRUNK
 * .
 *
 * 04 16 2015 justin.li
 * [MOLY00098830] [MT6291][LTE-C2K] SRLTE RSVA feature
 * .
 *
 * 04 16 2015 norman.chang
 * [MOLY00107801] NAS 6291 DEV
 * .
 *
 * 04 09 2015 eason.lai
 * [MOLY00105513] [TK6291][DHL] introduce GPD/SPD wrapper
 * 	     GPD/SPD wrapper and L2copro log dma
 *
 * 03 16 2015 mingtsung.sun
 * [MOLY00097603] [MT6291][UMOLY] Universal Testing Task Framework
 * UTT RD 2
 *
 * 02 13 2015 yungfu.chen
 * [MOLY00091822] RATDM reorganization
 *
 * 02 10 2015 yi-ying.lin
 * [MOLY00095496] [L1D][Modify] TK6291 CC NVRAM and custom data modification L1D part
 * 	.
 *
 * 01 28 2015 cs.huang
 * [MOLY00093773] [HLT] Add HIF Latency Trace module
 * [HLT] Add HIF Latency Trace Module
 *
 * 01 21 2015 roland.li
 * [MOLY00092193] [UMOLY][LPP]LPP R10R11 feature checkin
 * 	[LPP][AGNSS]libParserDbModem modify for AGNSS and LPP.
 *
 * 01 08 2015 kuan-wei.chen
 * [MOLY00091655] remove mcd_l4_common.h
 * remove mcd_l4_common.h
 *
 * 01 06 2015 nancy.chang
 * [MOLY00087510] [Universal Bin] FDD DBME & LDBME development
 * .
 *
 * 01 06 2015 peng-an.chen
 * [MOLY00089125] [UMOLY] Universal Bin SW integration
 * .
 *
 * 12 31 2014 peng-an.chen
 * [MOLY00089125] [UMOLY] Universal Bin SW integration
 * Fix TDD file missing problem
 *
 * 12 18 2014 jack.chu
 * [MOLY00088075] [RRCE] Universal Bin Modification
 * 	Add __CGEN_UMTS_FDD_MODE__ to build rrce_pdcp_struct.h in FDD only
 *
 * 12 15 2014 charlescm.wu
 * [MOLY00087679] [UMOLY][FDD][UAS COMMON][UL2 COMMON/URLC/BMC/SEQ]U-Bin CBr to UMOLY TRUNCK.
 *
 * 11 25 2014 peter.hsu
 * [MOLY00084258] [MT6795][Modem][Feature]Please support Garbage filter from network
 * [PFM] [IPCORE] Packet Filter Manager & Garbage Filter Implementation
 *
 * 11 19 2014 nicky.chou
 * [MOLY00084935] [SCSI][LCSCE] sync to UMOLY from MT6291_DEV
 * .
 *
 * 11 14 2014 yenchih.yang
 * [MOLY00084256] [MEME] sync MT6291 to UMOLY
 * URR/MEME.
 *
 * 11 12 2014 tsung-wei.tu
 * [MOLY00080211] [MT6291_DEV][MT6291_UESIM_DEV] Check in low power to MT6291_DEV, MT6291_UESIM_DEV
 * Merging GISE low power to UMOLY trunk
 *
 * 09 10 2014 poying.chuang
 * [MOLY00078264] [UMOLY][R10][R11] NAS check-in from CBr to 6291_DEV
 * 	Interfaces .
 *
 * 09 09 2014 hong.yu
 * [MOLY00077839] [L4/ATCI] code revise after review
 * UT revise
 *
 * 08 25 2014 hong.yu
 * [MOLY00077150] [L4] UT utility for ATCI and SBP
 * 	[L4] ATCI and SBP UT utility
 *
 * 08 08 2014 yr.chiang
 * [MOLY00072292] TK6291 EL1C Development
 * sync MOLY to UMOLY
 *
 * 08 04 2014 ian.cheng
 * [MOLY00074458] UMOLY CCCI service
 * 	[UMOLY_DEV CCCI PCore Service]
 *
 * 08 01 2014 kuan-wei.chen
 * [MOLY00063617] [CCCI] Show CCCI IPC ILM's local parameter in ELT tool
 * 	CCCI IPC msgid rename - L4
 *
 * 08 01 2014 cs.huang
 * [MOLY00063617] [CCCI] Show CCCI IPC ILM's local parameter in ELT tool
 * 	[CCCI] Show CCCI IPC ILM's local parameter in ELT tool
 *
 * 07 31 2014 eason.lai
 * [MOLY00073290] [TK6291][DHL] basic logging support for V7FPGA L1S_L1DISABLE
 * 	should set USB HIF SUPPROT to true
 *
 * 06 25 2014 cw.wang
 * [MOLY00069324] MD USB power saving enhancement
 * [USBCLASS] Merge MOLY cdcecm to UMOLY
 *
 * 06 25 2014 cw.wang
 * [MOLY00069324] MD USB power saving enhancement
 * [USBCLASS] cdcecm power saving enhancement
 *
 * 06 12 2014 ryan.ou
 * [MOLY00059395] [GAS] Adaptive paging period in RLC unack mode
 * .
 *
 * 06 04 2014 max.mo
 * [MOLY00067752] [SM] Sync latest SM code to TK6291_DEV
 * . NewSM to latest version
 *
 * 03 16 2014 yr.chiang
 * [MOLY00059647] [MT6290E2] SAR feature support for 4G LTE
 * el1 related code
 *
 * 03 12 2014 yr.chiang
 * [MOLY00058505] [check in]B3B39 co-existence code
 * .
 *
 * 01 22 2014 peter.chien
 * [MOLY00051406] [LTE Gemini] RSVAE modification check-in
 * .Gemini RSVAE check-in
 *
 * 01 22 2014 kevin.lu
 * [MOLY00051292] Remove old LL1 related files from MOLY
 * .
 *
 * 01 22 2014 terence.chen
 * [MOLY00054324] [4G Gemini][Merge] MOLY.MM.GEMINI.DEV Merge back to MOLY.
 *
 * 01 22 2014 william.lin
 * [MOLY00051292] Remove old LL1 related files from MOLY.
 *
 * 01 21 2014 wcpuser_integrator
 * [MOLY00054475] SGLTE option rename
 * .
 *
 * 01 14 2014 stanleyhy.chen
 * [MOLY00053071] EM type access level control. Add em_info_access_level_map
 * Add a new table msg_id_access_level_map and a new file em_mapping_for_tool.h
 *
 * 01 13 2014 ben.chiu
 * [MOLY00053410] [VoLTE][IMC] merge IMC to MOLY TRUNK
 * Common and IMC config files
 *
 * 11 21 2013 yenchih.yang
 * [MOLY00045854] [PS1267 HG+WG] Check-in Gemini HG+WG modification.
 * [DBME] H/G+W/G.
 *
 * 10 18 2013 wenxiu.zhao
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * .
 *
 * 10 18 2013 wenxiu.zhao
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * .
 *
 * 10 18 2013 bo.wu
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * .
 *
 * 10 18 2013 danny.kuo
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * Integration change.
 *
 * 10 15 2013 wynne.chu
 * [MOLY00041075] [MOLY] UT merge
 * 	.
 *
 * 09 13 2013 benjamin.kuo
 * [MOLY00037712] add gv file of RAC for UT
 * MOLY
 *
 * 07 31 2013 moja.hsu
 * [MOLY00030336] IP Header raw data log for wireshark
 * Log UL/DL Ip header content
 *
 * 07 18 2013 aj.tsai
 * [MOLY00029691] check-in AOMGR related code
 * Integrate AOMgr Related code
 * add  aomgr trace log.
 * refine aomgr code.
 *
 * 07 16 2013 tj.chang
 * [MOLY00029850] Refine ETHERCORE/DHCP4C/NDPC ILM structure definitions for ELT logging
 *
 * 07 05 2013 danny.kuo
 * [MOLY00028800] [MMDC] PS Domain Switch Manager (PSDM) development
 * Interface Check-in
 *
 * 06 25 2013 yilun.chen
 * [MOLY00027414] Refine IPCORE ILM structure definitions for ELT logging
 * [IPCORE] Add ipcore related header files into DHL Database.
 *
 * 06 20 2013 mojo.lai
 * [MOLY00026719] Support read memory in word access and half word access
 * .
 *
 * 06 05 2013 benjamin.kuo
 * [MOLY00025172] Add EM feature for L4 RAC
 *
 * 06 03 2013 ken.liu
 * [MOLY00024730] DHL multimode engineering mode and air message logging support
 * add msg id to em_info_enum mapping table.
 *
 * 05 29 2013 moja.hsu
 * [MOLY00024129] Add EM Registration path to L4c
 * add EM Related message ID, EM Info Type.
 *
 * 05 29 2013 joe.chang
 * [MOLY00023789] [MT6290][TFTLIB] New architecture & EM support
 * Remove TFTLIB compile options
 *
 * 05 22 2013 byron.tsai
 * [MOLY00023372] [MT6290][NW-UE SIM] UESIM MOLY Migration - UESIM related changes submission
 * .
 *
 * 05 16 2013 moja.hsu
 * [MOLY00007625] Maintain code
 * Back out changelist 156018
 * patch for QMU_BM/UPCM/RATADP/TFT_PF trace
 *
 * 05 15 2013 moja.hsu
 * [MOLY00007625] Maintain code
 * add tft_pf/qmu_bm/upcm/ratadp trace
 *
 * 05 13 2013 ben.chiu
 * [MOLY00022258] ETCM EM mode implementation
 * EM parameter modification
 *
 * 04 11 2013 evelyn.wang
 * [MOLY00013948] [MT6290 PO admit] Check in AST3002 & protocol code for 6290 MULTI_MODE_TDS project
 * .
 *
 * 04 03 2013 mojo.lai
 * [MOLY00009210] TATAKA merge to MOLY
 * SWTR merge
 *
 * 03 28 2013 danny.kuo
 * [MOLY00012928] [MMDC]  add a new module PSDM for MMDC
 * add MOD_PSDM into required files
 *
 * 03 14 2013 ye.yuan
 * [MOLY00011961] [3G TDD][Multi-mode]merge code from jeff.wu\MOLY_PS.L1.MM.IT to MOLY
 * .
 *
 * 01 29 2013 ken.liu
 * [MOLY00009212] LTE Multimode merge back to MOLY
 * add log header.
 *
 *******************************************************************************/

#ifdef _MODIS_ON_VC9_
#define __w64
#endif
typedef int cgen_use_spare_msg_id;
typedef int cgen_use_spare_sap_id;
typedef int cgen_use_spare_module_id;
typedef unsigned short msg_type;
typedef unsigned short sap_type;
typedef unsigned short module_type;

#ifdef __GNUC__
  typedef struct __va_list { void *__ap; } __builtin_va_list;
  #define INLINE __inline
  #define inline __inline
#endif

#define __declspec(s)
//"ps\\tools\\asn1lib\\include\\act-ttbuffmgr.h"
#undef STDC_HEADERS //it will include stdio.h

#ifdef __RVCT__
#ifndef __int64
   typedef  long long __int64;
#endif


#define _ARMABI

#endif

#ifdef __UE_SIMULATOR__
#ifndef __int64
	typedef  long long __int64;
#endif
//#include "TrcMod.h"
#endif
#include "L1Trc.h"

#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "sap_info.h"
#include "msg_id_to_em_info_map.h"
#include "em_mapping_for_tool.h"

#include "kal_trace.h"
/* #include "stack_ltlcom.h" Reduce 2 service global include path*/

#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "stack_timer.h"
#include "event_shed.h"

#include "intrCtrl.h"

#if !defined(DISABLE_MDDBG_FUNCTION)
#include "mddbg.h"
#include "mddbg_public.h"
#endif

#include "SST_sla.h"

#include "ebc_drv.h"
#ifdef __CDMA2000_RAT__
#include "c2k_irat_msg_struct.h"
#endif

/* DVFS */
#ifdef DVFS_ENABLE
#include "dvfs_internal.h"
#endif

/* For ostd & TOPSM */
#include "RM_public.h"
#include "sleepdrv_interface.h"

/* l1 */
#include "mph_types.h"
#include "mph_cs_def.h"
#include "mph_cs_msg.h"
#ifdef __PS_SERVICE__
#include "mph_ps_def.h"
#include "mph_ps_msg.h"
#endif
#if ( defined(__GSM_RAT__) || defined(__UMTS_RAT__) )
/* For Dual Mode L1 */
#include "mph_dm_def.h"
#include "mph_dm_msg.h"
/* For Dual Mode L1 */
#endif /* __GSM_RAT__ && __UMTS_RAT__ */

#include "GV.h"
#include "dhl_def.h"
#include "dhl_internal_def.h"
#ifdef UNIT_TEST
#include "dhlsim_def.h"
#endif

#ifdef __MINI_LOG_SUPPORT__
#include "tst_mini_log.h"
#endif /* __MINI_LOG_SUPPORT__ */

#if defined(GEN_FOR_PC)
#include "tst_Catcher_version.h"
#include "tst_catcher_diagonsis_info.h"
#endif  //#if defined(GEN_FOR_PC)

#ifndef NWSEL_NOT_PRESENT
#include "nwsel_msgid.h"
#include "nwsel_mm_struct.h"
#include "nwsel_ratcm_struct.h"
#include "nwsel_context.h" 
#include "nwsel_def.h"
#include "nwsel_eval_struct.h"
#endif

#ifndef GMSS_NOT_PRESENT
#include "gmss_msgid.h"
#include "gmss_nwsel_struct.h"
#include "gmss_common.h"
#include "gmss_context.h"
#include "gmss_css_recv.h"
#include "gmss_css_send.h"
#include "gmss_def.h"
#include "gmss_main.h"
#include "gmss_nwsel_recv.h"
#include "gmss_nwsel_send.h"
#include "gmss_rat_ctrl.h"
#include "gmss_sim_access.h"
#include "gmss_state.h"
#include "gmss_timer.h"
#include "gmss_trc.h"
#include "gmss_utility.h"
#include "gmss_ut.h"
#endif

#ifdef DUMMY_PROTOCOL
#ifdef __GSM_RAT__
#include "dps_testTool.h"
#include "dps_rlc_sap.h"
#endif //__GSM_RAT__
#endif

/* other module */

#ifndef __L1_STANDALONE__
/*For Protol modules*/

#ifdef __PS_SERVICE__
//#include "asn-incl.h"
#endif

#include "l4c_common_enum.h"
#include "l4_defs.h"
#include "irat_common_struct.h"

/* MBMSAL */
#include "mbmsal_defs.h"

/* FLC */
#if defined(__FLC2__) && defined(__FLC_SUPPORT__)
#include "flc2_config.h"
#endif

#ifdef __MOD_CC__
#include "mcd_ss_parameters.h"
#include "mcd_ss_tcapmessages.h"
#include "mcd_cc_peer.h"
#include "ps2sat_struct.h" /* Ripple SATCE */
#include "l4c_common_enum.h"
#include "csmcc_enums.h"
#include "csmcc_common_enums.h"
#include "ps2sat_struct.h"
#include "l4c2csm_cc_struct.h"
#include "mncc_struct.h"
#include "mm2cm_struct.h"
#include "cm2mm_struct.h"
#include "cm2csce_struct.h"


#include "stacklib.h"
#include "event_shed.h"
#include "stack_timer.h"
#include "cc_defs.h"
#include "cc_std_defs.h"
#include "cc_ss_defs.h"
#include "cc_types.h"
#endif


#ifdef __MOD_CSM__
#include "mcd_ss_parameters.h"
#include "mcd_ss_tcapmessages.h"
#include "ps2sat_struct.h" /*  Ripple SATCE */
#include "l4c_aux_struct.h"
#include "l4c_common_enum.h"
#include "csmcc_enums.h"
#include "csmcc_common_enums.h"
#include "ps2sat_struct.h"
#include "l4c2csm_cc_struct.h"
#include "mncc_struct.h"

#include "stack_timer.h"
#include "l4_defs.h"
#include "csmcc_defs.h"
#include "csmcc_bc_defs.h"
#include "csmcc_bc_types.h"
#include "csmcc_common_enums.h"
#include "csmcc_enums.h"
#include "csmcc_types.h"
#include "csmcc_atfunc.h"

#include "l4c2csm_ss_struct.h"

#ifdef __AGPS_CONTROL_PLANE__
/* SSAGPS */
#ifdef GEN_FOR_PC
    #ifndef __RVCT__
			#define __int64
    #endif	//#if !defined(__RVCT__)
#define __cdecl
#endif //#ifndef __L1_STANDALONE__

//#include "applib_asn_ber_common.h" /* SSAGPS */
#include "applib2_asn_common.h" /* SSAGPS */
#include "applib2_mtkasn_global.h" /* SSAGPS */
#include "ss_asn.h" /* SSAGPS */
#include "l4c2csm_ss_lcs_struct.h" /* SSAGPS */
#endif
#include "l4c_lbs_struct.h" /* SSAGPS */
#include "mnss_struct.h"
#include "csmss_common_enums.h"
#endif /*__MOD_CSM__*/

#ifdef __MOD_SIM__
#include "stack_timer.h"
#include "sim_common_enums.h"

#include "phb_utils.h"
#include "ps2sat_struct.h" /* Ripple SATCE */
#include "l4c2csm_cc_struct.h" /* ripple */
#include "l4c_common_enum.h"
#include "csmcc_enums.h"
#include "csmcc_common_enums.h"
#include "ps2sat_struct.h"
#include "l4c2csm_cc_struct.h"
 /* ripple */
#include "cc2sat_struct.h" /* ripple */
#include "sat_def.h"
#include "ps2sim_struct.h"


#endif /*__MOD_SIM__*/

#ifdef __MOD_SMU__

#if defined(__MMI_FMI__)
#endif
#include "l4c2smu_struct.h"
#include "ps2sim_struct.h"
#include "ps2sat_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#include "smu_def.h"
#endif /*__MOD_SMU__*/

#ifdef __MOD_PHB__
#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"
#endif /*__MOD_PHB__*/

#ifdef __MOD_UEM__
#include "device.h"
#include "uart_sw.h"
#include "mcd_uem_peer.h"
#endif /*__MOD_UEM__*/

#ifdef __MOD_SMSAL__
#include "smsal_l4c_defs.h"
#include "smsal_l4c_enum.h"

/* for context */
#include "l3_inc_enums.h"
#include "smsal_timer.h"
#include "smsal_enums.h"
#include "smsal_defs.h"
#include "l4c2smsal_struct.h"
#include "smsal_peer_struct.h"

#include "mnsms_struct.h"
#include "smsal_structs.h"
#include "smsal_context.h"
#endif /*__MOD_SMSAL__*/

#ifdef __MOD_SMS__

/* SMS <--> SMSAL */
//#include "stack_timer.h"
#include "mnsms_struct.h"
#include "sms_enum.h"
//#include "lcd_cqueue.h"
#include "event_shed.h"
#include "sms_timer.h"

/* SMS Context */
#include "sms_defs.h"
#include "sms_tl.h"
#include "sms_rl.h"
#include "sms_cm.h"
#include "sms_context.h"

/* SMS <--> MM */
#include "mcd_sms_gen_peer.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "cm2mm_struct.h"
#include "mm2cm_struct.h"
#include "sms2mm_struct.h"
#include "mm2sms_struct.h"
#endif

#ifndef PPP_NOT_PRESENT
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "tcm2sm_struct.h"
#include "l4c2ppp_struct.h"
#include "ppp2l4c_struct.h"
#include "tcm2ppp_struct.h"
#include "ppp2tcm_struct.h"
#include "ppp_l4_enums.h"
/* PPP for CSD usage */
#include "tcpip2ppp_struct.h"
//#include "ppp2tcpip_struct.h"
#include "ppp2csd_struct.h"
 #ifdef __PPP_UT__
  #include "ppp_types.h"
  #include "ppp_buff_mgr.h"
  #include "ppp_fsm.h"
  #include "ppp_crc.h"
  #include "ppp_lcp.h"
  #include "ppp_ipcp.h"
  #include "ppp_main.h"
  #include "ext_modem_ppp_struct.h"
 #endif // ~ #ifdef __PPP_UT__
#endif /*  ~PPP_NOT_PRESENT */

#ifdef __MOD_CISS__
#include "mcd_ss_parameters.h"
#include "mcd_ss_tcapmessages.h"
#include "mnss_struct.h"
#include "mm2cm_struct.h"
#include "cm2mm_struct.h"
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "mcd_ciss_peer.h"
#include "ciss_enum.h"
#include "ciss_eval_struct.h"
#endif /* __MOD_CISS__ */

//#ifdef __PS_SERVICE__
#ifdef __MOD_TCM__
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "tcm2sm_struct.h"
#include "sm2tcm_struct.h"
#include "rat_tcm_context.h"
#if defined(__MMI_FMI__)
#endif
#include "l4c2abm_struct.h"
/* mtk00938 2008-02-20: for streaming and secondary PDP context */
#include "mmi_sm_enums.h"
/* End of Jeff Wu */
#include "abm2l4c_struct.h"
#include "l4c2tcm_struct.h"
//#include "tcm_common_enums.h"
//#include "tcm_common.h"
#include "l4c2tcm_func.h"
#include "tcm2l4c_struct.h"
#include "ppp2tcm_struct.h"
#include "tcm2ppp_struct.h"
#include "snd2tcm_struct.h"
#include "tcm2snd_struct.h"
//#include "tcm_timer.h"
#include "tcm_rattcm_struct.h"
#include "tcm_context.h"

#include "tcm_assert.h"
#include "tcm_at_handler.h"
#include "tcm_gprs_statistic.h"
#include "tcm_init.h"
#include "tcm_main.h"
#include "tcm_pco_api.h"
#include "tcm_qos_api.h"
#include "tcm_reset.h"
#include "tcm_send_msg.h"

#include "tcm_sic_context.h"

#ifdef __TURN_ON_GENERAL_SECONDARY_PDP__
#include "tcm_tft_api.h"
#endif /* __TURN_ON_GENERAL_SECONDARY_PDP__ */

#ifdef __ACL_SUPPORT__
#include "tcm_acl_support.h"
#endif /* __ACL_SUPPORT__ */

#ifdef __UGTCM__
#include "tcm_ugtcm_check.h"
#include "tcm_ugtcm_fsm.h"
#include "tcm_ugtcm_send_msg.h"
#include "tcm_ugtcm_timer.h"
#endif /* __UGTCM__ */

#endif /* __MOD_TCM__ */
//#endif /* __PS_SERVICE__ */

#include "nwsel_def.h"
#include "nwsel_context.h"
#include "nwsel_mm_struct.h"
#include "nwsel_ratcm_struct.h"

#ifndef RR_NOT_PRESENT
#ifdef __UMTS_RAT__
#include "as_common.h"
#endif

/* For Poring CSN.1*/

#include "rr_common_headers.h"
#include "rr_common_def.h"
#include "rr_context.h"


#include "rr_mpal_interface.h"
#include "rmc_lapdm_interface.h"

#include "security_keys_enums.h"
#include "security_keys_struct.h"
#include "as2nas_struct.h"
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "l3_inc_enums.h"

#ifdef __UMTS_RAT__
/* John 2006/06/10*/
#include "mcd_l3_inc_struct.h"
#include "l3_inc_enums.h"
#include "l3_inc_local.h"
#include "csi_asn.h"
#ifdef __GSM_RAT__
#include "csi_gsm_asn.h"    // Defines e.g., `CsiGsmBaRangeList'
#endif
#ifdef __UMTS_RAT__
#include "csi_umts_asn.h"   // Defines e.g., `CsiFddUmtsCellList'
#endif

#include "uas_gas_enums.h"
#include "uas_gas_struct.h"
#include "mrs_utility.h"

#ifdef __LTE_RAT__
#include "uas_eas_struct.h"
#include "gas_eas_struct.h"
#include "mtk_uper_asn.h"
#endif
#include "mrs_as_struct.h"
#include "rac_mrs_struct.h"

#if defined(__SGLTE__)
#include "gas_el1_struct.h"
#endif
#if defined(__LTE_RAT__)
#include "l4c_el1_struct.h"
#endif

#ifdef __GEMINI__
#include "uas_gas_gemini_struct.h"
#endif /* __GEMINI__ */

/* For generating 3G LBM TRACE_PEER enum */
#include "ratcm_loop_mode.h"

#endif /* __UMTS_RAT__ */

#if defined(__GEMINI__)
#include "rsvas_enum.h"
#include "rsvas_struct.h"
#if defined(__UMTS_RAT__)
#include "rsvak_enum.h"
#include "rsvak_struct.h"
#include "urr_rsvau_struct.h"
#ifdef __GSM_RAT__
#include "gas_rsva_struct.h"
#endif /* __GSM_RAT__ */
#endif /* __UMTS_RAT__ */
#ifdef __LTE_RAT__
#include "eas_rsva_struct.h"
#include "rsvae_fsm.h"
#endif /* __LTE_RAT__ */
#ifdef __CDMA2000_RAT__
#include "c2k_rsva_struct.h"
#include "rsvac_fsm.h"
#endif /* __CDMA2000_RAT__ */
#endif /* __GEMINI__ */

#ifdef __GEMINI__
#include "as_access_sem_context.h"
#include "as_access_sem_funcs.h"
#endif /* __GEMINI__ */

#include "rr2lapdm_struct.h"
#include "rr2mpal_struct.h"
#include "mpal2rr_struct.h"
#include "rrm2rmpc_struct.h"
#include "lapdm2rr_struct.h"
#ifdef __GEMINI_GSM__
#include "rr2prr_struct.h"
#endif
#include "mph_cs_msg.h"
#include "sim_common_enums.h"

/* CSN codec*/
#include "mtk_csn.h"

#ifdef __PS_SERVICE__
#include "gprs_rlcmac_ul.h"
/* Evelyn 20090415: Merge R6 */
#if defined(__MTBF__) || defined(__PS_HO__)
#include "gprs_mtbf.h"
#endif
#ifdef __PS_HO__
#include "ps_ho.h"
#endif
#endif

#include "rrm_context.h"
#include "lapdm_common.h"
#include "psi_si_common.h"
#include "si.h"
#include "si_context.h"
#include "rr_sendmsgs_to_mpal.h"
#include "si_update_funcs.h"
#include "si_msg_decode.h"
#include "rmc_enums.h"
#include "rmc_peer_msg_enums.h"

#ifdef __PS_SERVICE__
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "l3_inc_enums.h"

/* peer message */
#include "si_peer.h"
#include "rmc_peer_dl.h"
#include "nstd_alloc_bitmap.h"
#include "nstd_mobile_alloc_peer.h"
#include "nstd_pmo.h"
#include "gprs_rlcmac_dl.h"
#include "nstd_pkt_meas_report.h"
#include "gprs_rlcmac_ul.h"
#include "rmc_peer.h"
#include "gprs_rlcmac_peer.h"
#include "meascell.h"
#include "gprs_rlcmac_common.h"

#include "llcrlc_enums.h"
#include "rlc_mac_enums.h"
#include "rmpc_rlc_enums.h"
#include "llc2rlc_struct.h"
#include "rlc2mac_struct.h"
#include "rlcmac_struct.h"
#include "mac2rlc_struct.h"
#include "mac2rmpc_struct.h"
#ifdef __ADAPTIVE_PAGING_PERIOD_IN_UNACK_MODE__
#include "rlc2rmpc_struct.h"
#endif
#include "rmpc2rlc_struct.h"
#include "rmpc2mac_struct.h"
#include "rlc2reasm_struct.h"
#include "reasm2rlc_struct.h"
#include "rr_data_ind.h"
#include "psi_si_common.h"
#include "psi.h"
#include "mac_context.h"
#include "rlc_context.h"
#include "reasm_context.h"
#ifndef __MTK_TARGET__
#include "gprs_rlcmac_common_struct.h"
#endif

/* for RMP */
#include "rmp_pktacc.h"
#include "rmp_context.h"
#endif /* end of __PS_SERVICE__ */

#ifdef __UMTS_RAT__
#include "uas_gas_enums.h"

#ifdef __GEMINI__
#include "uas_gas_gemini_struct.h"
#endif /* __GEMINI__ */
#endif /* __UMTS_RAT__ */

#include "meas_context.h"
#include "rmc_context.h"

#include "rcs_context.h"

#include "lapdm_context.h"
#include "lapdm_enums.h"
#include "rmc_common_access.h"
#include "rmc_cell_resel.h"
#include "rmpc_common_func.h"
#include "rmc_meas.h"
#include "rr_utils.h"
#include "rr_peh.h"
#include "rmc_dedicated_proc.h"
#include "csrr_utils.h"
#include "csrr_recv_lapdm_mesgs.h"
#include "csrr_recv_mpal_mesgs.h"
#include "csrr_ded_access.h"
#include "csrr_ded_proc.h"
#include "rmc_dedicated_meas.h"
#include "rmpc_nbr_cell.h"

// Evelyn 20080902: For MAC UT
// Rachel 20101114: For MPAL UT
#include "mpal_context.h"



#include "mll1_msgid.h"
#include "mll1_eutran.h"
#include "mll1_gsm.h"
#include "mll1_umts_fdd.h"
#include "mll1_umts_tdd.h"


#ifdef __AGPS_CONTROL_PLANE__
#include "csrr_agps_context.h"
#endif

#endif /* RR_NOT_PRESENT */

#ifndef MM_NOT_PRESENT
#include "l3_inc_enums.h"
#include "mm_mmi_enums.h"
#include "mmcm_enums.h"
#include "mmas_enums.h"
#include "mm_ratcm_enums.h"
#include "mm_ratcm_struct.h"
#include "security_keys_enums.h"

#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "mcd_mm_common_gen_struct.h"
#include "mcd_mm_cs_peer_struct.h"

#include "security_keys_struct.h"
#include "mm2cm_struct.h"
#include "mm2mmi_struct.h"
#include "cm2mm_struct.h"
#include "mmi2mm_struct.h"
#include "mm_common.h"
#include "mm_cs_defs.h"

#include "mm_mmi_enums.h"
#include "l4crac_enums.h"
#include "l3_inc_enums.h"
#include "nvram_enums.h"
#include "mm2sms_enums.h"

#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "mmi2mm_struct.h"
#include "mm2mmi_struct.h"
#include "l4c2rac_struct.h"
#include "rac2l4c_struct.h"
#include "nvram_struct.h"
#include "as2mmi_struct.h"

#ifdef __PS_SERVICE__
#include "mcd_mm_ps_peer_struct.h"
#include "mm_ps_defs.h"
#include "mm_ps_context.h"
#endif

#include "mm_cs_context.h"
#include "mm_common_context.h"

#endif /* #ifndef MM_NOT_PRESENT */


#ifdef __MOD_L4A__
#include "l4a.h"
#endif

#ifdef WISDOM_MMI
#include "ws_msg_struct.h"
#endif

/**************************************************************************
 * GPRS NAS DATA PATH BEGINS
 **************************************************************************/
#ifdef __PS_SERVICE__

#include "sm2l4c_struct.h"
#include "l4c2sm_struct.h"
#include "sm_esm_struct.h"

#ifndef SNDCP_NOT_PRESENT
/* other needed struct and enums */
#include "snd_defines.h"
#include "sndllc_enums.h"
#include "data_plane_sm_enums.h"
#include "mcd_snd_peer.h"
/* sndcp peer struct */
/* sm local struct */
#include "snd2tcm_struct.h"
#include "tcm2snd_struct.h"
#include "snd2llc_struct.h"
#include "llc2snd_struct.h"
#include "llc2l3_struct.h"
#include "ratdm_sndcp_struct.h"
#include "snd_enums.h"
#include "snd_comp_interface.h"
#include "snd_flc.h"

#include "snd_xid.h"
#include "snd_rfc1144.h"
#include "snd_context.h"

#endif /* SNDCP_NOT_PRESENT */

#ifndef SM_NOT_PRESENT
/* other needed struct and enums */

#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "l3_inc_enums.h"
#include "mmi_sm_enums.h"
#include "data_plane_sm_enums.h"
#include "smmm_enums.h"
#include "sm_common_enums.h"

/* sm peer struct */
#include "mcd_sm_gen_peer.h"
/* sm local struct */
#include "sm2mm_struct.h"
#include "mm2sm_struct.h"
#include "data_plane2sm_struct.h"
#include "sm2data_plane_struct.h"
#include "tcm2sm_struct.h"
#include "sm2tcm_struct.h"
#include "sm_defines.h" /* Carlson SM UT GV */
#include "sm_context.h" /* Carlson SM UT GV */
#include "sm_tcm_responser.h"

/* sm conn sturct */
#include "sm_core_conn_enum.h"
#include "sm_core_conn_interface.h"
#include "sm_conn_timer.h"
#include "sm_conn_private_def.h"


#endif /* SM_NOT_PRESENT */



#ifndef LLC_NOT_PRESENT

/* other needed struct and enums */
#include "gmmllc_enums.h"
#include "mmllc_enums.h"
#include "l3llc_enums.h"
#include "sndllc_enums.h"
#include "llccipher_enums.h"
#include "llcrlc_enums.h"
#include "security_keys_enums.h"
/* In interface/include */
#include "llc_peer_interface.h"

/* llc local struct */
#include "security_keys_struct.h"
#include "cipher2llc_struct.h"
#include "l32llc_struct.h"
#include "llc2l3_struct.h"
#include "llc2rlc_struct.h"
#include "rlc2llc_struct.h"
#include "snd2llc_struct.h"
#include "llc2snd_struct.h"
#include "llc_flowctrl.h"

#include "ratcm_llc_struct.h"

/* llc asn peer struct (Order shall be kept) */
#include "mcd_llc_peer_struct.h"

/* other needed struct and enums */
#include "stacklib.h"
// #include "lcd_dll.h" // remove lcd_dll, replaced by ./mcd/kal/mlib/mlib_dll
#include "stack_timer.h"
#include "event_shed.h"
#include "llc_lcdiplqueue.h"

#include "llc_defs.h"
#include "llc_context.h"
#include "llc_specific_defines.h"

#endif /* LLC_NOT_PRESENT */

#endif /* __PS_SERVICE__ */

#endif /*__L1_STANDALONE__*/

/**************************************************************************
 * GPRS NAS DATA PATH ENDS
 **************************************************************************/

#ifndef DATA_NOT_PRESENT

#if defined(__CSD_T__) || defined(__CSD_NT__) || defined(__CSD_FAX__)
#include "ratcm_csd_interface.h"

#include "data_uart_simu.h"
#include "csm_data_enums.h"
#include "data_context.h"
#include "ppp2csd_struct.h"
#endif

#ifdef __CSD_NT__
#include "l2r2rlp_enums.h"
#include "l2r_defs.h"
#include "rlp_defs.h"
#include "l2r_enum.h"
#include "rlp_enums.h"
#include "rlp_common.h"
#include "l2r_context.h"
#include "data_xid_struct.h"
#include "csm2l2r_struct.h"
#include "l2r2rlp_struct.h"
#include "rlp_timer.h"
#include "rlp_context.h"
#endif /* __CSD_NT__ */


#ifdef __CSD_T__
#include "csm2tdt_struct.h"
#include "tdt_context.h"
#endif /* __CSD_T__ */

#ifdef __CSD_FAX__
#include "l4c2t30_enums.h"
#include "l4c2t30_struct.h"
#include "csm2t30_struct.h"
#include "t302fa_struct.h"
#include "fa_defs.h"
#include "fa_enums.h"
#include "fa_context.h"

#include "t30_defs.h"
#include "t30_enums.h"
#include "t30_params.h"
#include "t30_context.h"
#endif /* __CSD_FAX__ */
#endif /* DATA_NOT_PRESENT */

#include "m12190_pcore.h"
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#include "ul1cal.h"
#endif

#ifdef __AST_TL1_TDD__
#include "tl1cal_ast.h"
#endif

#include "l1cal.h"


//#ifdef __MCD__
//#include "mcd_channel_rel.h"
//#include "mcd_rmc_peer_dl.h"
//#include "mcd_rmc_peer.h"
//#include "mcd_si_peer.h"
//#include "mcd_measurement_report.h"

//#endif

#include    "uart_sw.h"

#ifdef __IRDA_SUPPORT__
#ifndef OBEX_NOT_PRESENT
#include "irda_enums.h"
#include "irda_struct.h"
#include "obex_app_enums.h"
#include "obex2app_struct.h"
#include "app2obex_struct.h"
#endif

#ifndef IRCOMM_NOT_PRESENT
#include "irda_enums.h"
#include "irda_struct.h"
#include "ircomm_app_enums.h"
#include "app2ircomm_struct.h"
#include "ircomm2app_struct.h"
#endif
#endif /* __IRDA_SUPPORT__ */

#if defined(__MOD_SMSAL__) && !defined(SOC_NOT_PRESENT) //kevin 05/23
#include "smsal2soc_struct.h"
#endif /*__MOD_SMSAL__*/

#ifndef __L1_STANDALONE__
#include "smsal_as_struct.h"
#endif

#ifdef __LTE_RAT__
#include "mll1_msgid.h"
#include "mll1_eutran.h"
#include "mll1_gsm.h"
#include "mll1_umts_fdd.h"
#include "mll1_umts_tdd.h"
#endif /*__LTE_RAT__*/

#if defined(__MOD_RAC__)
#include "l4c2rac_struct.h"
#include "rac2l4c_struct.h"
#ifdef __LTE_RAT__
#include "rac_eval_struct.h"
#endif /* __LTE_RAT__ */
#include "mmi2mm_struct.h"
#include "mm2mmi_struct.h"
#include "rac_defs.h"
#include "rac_mrs_struct.h"
#include "rac_em_struct.h"
#include "rac_context.h"
#include "rac_gmss_struct.h"
#endif /* __MOD_RAC__ */

#ifndef L4_NOT_PRESENT
#include "rmmi_context.h"
#include "drvsignals.h"
#include "l4_ipc_msg_struct.h"
#endif

/* for BMT */
#include "drvsignals.h"
/* for BMT */

#include "audio_enum.h"

#ifdef __WIFI_SUPPORT__
#include "wndrv_cnst.h"
#include "wndrv_cal.h"
#include "wndrv_ft_types.h"
#include "wndrv_ft_msg.h"
#include "wndrv_supc_types.h"
#include "wndrv_supc_msg.h"
#include "wndrv_tool_types.h"
#include "wndrv_tool_msg.h"
#include "supc_abm_msgs.h"
#include "mmi2abm_struct.h"
#include "wndrv_abm_msg.h"
#ifdef WIFI_BB_MT5921
#include "wndrv_trace_enum.h"
#endif
#endif

#ifndef __L1_STANDALONE__
#ifdef GEN_FOR_PC
#include "sasken_msg.h"
#include "smsal_peer.h"
#include "mpal2rr_unpack_struct.h"
#include "rr2mpal_unpack_struct.h"
#ifdef __UMTS_FDD_MODE__
#include "nas_msg.h"
#endif

#ifdef __UMTS_RAT__
#include "ub_msg.h"
#endif /* #ifdef __UMTS_RAT__ */
#ifdef __PS_SERVICE__
#include "rlc2mac_unpack_struct.h"
#endif /*__PS_SERVICE__*/
#endif /*GEN_FOR_PC*/
#endif /*__L1_STANDALONE__*/

#ifdef __DT_SUPPORT__
#include "dt_common_enum.h"
#endif /*__DT_SUPPORT__*/
#include"l4c2dt_struct.h"

#ifdef __EXT_MODEM__
#include "ext_modem_ppp_struct.h"
#include "ext_modem_l4c_struct.h"
#endif

#ifdef __PS_SERVICE__
#include "ps_ratdm_struct.h"
#endif

#ifndef __MTK_TARGET__
#include "uart_sim_struct.h"
#endif


#ifdef __IPERF__
#include "soc_api.h"
#endif /* __IPERF__ */

#ifdef __DRM_SUPPORT__
#endif /* __DRM_SUPPORT__ */

#ifdef GIS_SUPPORT
#include "gis_struct.h"
#endif

#ifdef __CMUX_SUPPORT__
#include "cmux_struct.h"
#include "cmux_def.h"
#endif /* __CMUX_SUPPORT__ */

#ifdef __UPS_SUPPORT__
#include "ups_struct.h"
#ifdef __USB_TETHERING__
#include "ps_public_ups_enum.h"
#include "ps_public_ups_struct.h"
#include "rndis_def.h"
#endif /* __USB_TETHERING__ */
#endif /* __UPS_SUPPORT__ */

#ifdef __IPCORE_SUPPORT__
#include "ipc_struct.h"
#include "ipc_enums.h"
#endif /* __IPCORE_SUPPORT__ */

#ifdef __TMC_SUPPORT__
#include "tmc_struct.h"
#include "tmc_enums.h"
#endif /* __TMC_SUPPORT__ */

#ifdef __HIF_AOMGR_SUPPORT__
#include "aomgr_struct.h"
#include "aomgr_enums.h"
#endif /* __HIF_AOMGR_SUPPORT__ */

#ifdef __ETHERCORE_SUPPORT__
#include "ethercore_struct.h"
#endif /* __ETHERCORE_SUPPORT__ */

#ifdef __NMU_ENABLE__
#include "dhcp4c_struct.h"
#include "ndpc_struct.h"
#endif

#ifdef __USB_ECM_SUPPORT__
#include "cdcecm_struct.h"
#endif

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
#include "gps_struct.h"
#endif

#ifndef __L1_STANDALONE__

/* for NAS/RATCM inerface */
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "l3_inc_enums.h"

#include "ratcm_ratdm_struct.h"
#include "ratcm_context.h"
#include "smsal_ratcm_struct.h"
#include "nwsel_ratdm_struct.h"

#ifdef __PS_SERVICE__
#include "mm_ratdm_struct.h"
#include "sm_ratdm_struct.h"
#include "esm_ratdm_struct.h"

#ifndef UART_SW_H
#include "uart_sw.h"
#endif // ~ #ifndef UART_SW_H
#ifndef _PS_RATDM_STRUCT_H
#include "ps_ratdm_struct.h"
#endif // ~ #ifndef _PS_RATDM_STRUCT_H
#include "tcm_ratdm_struct.h"
#ifdef __CGEN_UMTS_FDD_MODE__ /* __UMTS_FDD_MODE__ */
#include "ndis_ratdm_struct.h"
#endif
/* L4C -> RATDM */
//#ifndef _L4C_RATDM_STRUCT_H
#ifdef __CGEN_UMTS_FDD_MODE__ /* __UMTS_FDD_MODE__ */
#include "l4c_ratdm_struct.h"
#endif
//#endif

/* For RATDM/RABM UT */
#include "dlist.h"
#include "ratdm_context.h"
#endif

#ifdef __GSM_RAT__
/* for RATCM/GAS interface */
#include "ratcm_gas_enums.h"
#include "ratcm_gas_struct.h"
#endif

#endif /* ! __L1_STANDALONE__ */

#if defined(__SGLTE__)
#include "psdm2l4c_enum.h"
#include "psdm2l4c_struct.h"
#include "psdm_enums.h"
#endif

/* mtk04121 */
#if defined(__MOD_TCM__)
#include "l3_inc_local.h"
#include "tcm2sm_struct.h"
#include "sm2tcm_struct.h"
#include "rat_tcm_context.h"
#include "flc2_config.h"
#include "mmi_sm_enums.h"
#include "l4c2tcm_struct.h"
#include "l4c2tcm_func.h"
#include "tcm_api.h"
#include "tcm2l4c_struct.h"
#include "tcm_rattcm_struct.h"
/* PPP Dial-up */
#include "ppp2tcm_struct.h"
#include "tcm2ppp_struct.h"
#include "snd2tcm_struct.h"
#include "tcm2snd_struct.h"
#include "tcm_rattcm_struct.h"
#include "tcm_context.h"
#include "tcm_assert.h"
#include "tcm_at_handler.h"
#include "tcm_gprs_statistic.h"
#include "tcm_init.h"
#include "tcm_main.h"
#include "tcm_pco_api.h"
#include "tcm_qos_api.h"
#include "tcm_reset.h"
#include "tcm_send_msg.h"

#ifdef __TURN_ON_GENERAL_SECONDARY_PDP__
#include "tcm_tft_api.h"
#endif /* __TURN_ON_GENERAL_SECONDARY_PDP__ */

#ifdef __ACL_SUPPORT__
#include "tcm_acl_support.h"
#endif /* __ACL_SUPPORT__ */

#ifdef __UGTCM__
#include "tcm_ugtcm_check.h"
#include "tcm_ugtcm_fsm.h"
#include "tcm_ugtcm_send_msg.h"
#include "tcm_ugtcm_timer.h"
#endif /* __UGTCM__ */

#if defined(__ETCM__)
#include "eval_msgid.h"
#include "upcm_msgid.h"
#include "tcm_eval_enums.h"
#include "tcm_eval_struct.h"
#include "tcm_upcm_struct.h"
#include "tcm_etcm_utility.h"
#endif
#endif

/**************************************************************************
 * WCDMA INTERFACE BEGINS
 **************************************************************************/
#ifdef __UMTS_RAT__
#ifdef __CGEN_UMTS_FDD_MODE__ /* __UMTS_FDD_MODE__ */
#include "ul1_cnst.h"
#include "ul1_def.h"
#include "ul1_struct.h"
#include "ul1hisr_struct.h"
#endif
#include "kal_public_api.h"

#ifdef __CGEN_UMTS_FDD_MODE__ /* __UMTS_FDD_MODE__ */
#include "mll1_umts_fdd.h"
#endif /*__UMTS_FDD_MODE__*/

#ifdef __CGEN_UMTS_FDD_MODE__ /* __UMTS_FDD_MODE__ */
#include "hal_ul1_def.h"
#include "hal_ul1_struct.h"
#endif /*__UMTS_FDD_MODE__*/

#ifdef __UL1_ON_MNT__
/* for UL1 MoDIS */
#include "ul1_types.h"
//#include "ul1c_struct.h"
#endif

#ifdef DUMMY_PROTOCOL
/* 3G DPS */
#include "udps_testTool.h"
#endif


/* for MAL1 interface */
#ifdef __MA_L1__
#include "mal1_def.h"
#include "cti_msg.h"
#include "dual_msg.h"
#include "mal1_struct.h"
#endif

#ifndef __L1_STANDALONE__

#include "as_common.h"

/* for UAS common structure and enums */
#include "uas_common_enums.h"
#include "uas_common_struct.h"

/* for inter-core common structure and enum */
#include "gas_gise_def.h"
#include "gas_gise_enum.h"
#include "gas_gise_struct.h"
#include "as_inter_core_enum.h"
#include "as_inter_core_struct.h"
#include "uas_gas_inter_core_enum.h"
#include "uas_gas_inter_core_struct.h"
#include "gas_eas_inter_core_enum.h"
#include "gas_eas_inter_core_struct.h"
#include "gise_str.h"

#ifdef GEN_FOR_PC
#include "mcd_rrc_asn.h"
//John 960724
#include "asn_aper_common.h"
#include "mcd_h245_asn.h"
#endif

#include "rrc_asn.h"
#include "urr_common.h"
//#ifdef __UMTS_FDD_MODE__
#include "urr_enums.h"
#include "urr_struct.h"
//#endif

/* for UAS internal interface */
/* for URR/UL2D interface */
#include "cbmc_enums.h"
#include "cbmc_struct.h"
#include "bmc_common.h"
#include "cpdcp_enums.h"
#include "cpdcp_struct.h"
#include "ccsr_struct.h"
#include "crabm_struct.h"
#include "meme_umac_enums.h"
#include "meme_umac_struct.h"
#include "meme_drlc_struct.h"
#include "rrce_urlc_enums.h"
#include "rrce_urlc_struct.h"
#ifdef __CGEN_UMTS_FDD_MODE__
#include "rrce_pdcp_struct.h"
#endif
#include "rrce_umac_struct.h"
#include "rrce_bmc_struct.h"
#include "rrce_drlc_struct.h"


/* for URR/UL2 interface */
#include "ul2_common_def.h"
#include "crlc_enums.h"
#include "crlc_struct.h"
#include "cmac_enums.h"
#include "capability.h"      /* for cmac_struct.h */
#ifdef __UMTS_TDD128_MODE__
#include "tl1_cnst.h"
#include "tl1_def.h"
#include "tl1_struct.h"
#endif
#include "cmac_struct.h"
#include "umac_common_enums.h"  /* for UMAC trace */
#include "umac_context.h"  /* for UMAC UT */

/* for UL2/UL2D interface */
#ifdef __CGEN_UMTS_FDD_MODE__ /* __UMTS_FDD_MODE__ */
#include "rlc_cid.h" /* Roger 100310 : for compile option depend on ECO/IC version */
#endif
#include "csr_umac_enums.h"
#include "csr_umac_struct.h"
#include "csr_drlc_struct.h"
#include "pdcp_drlc_struct.h"
#include "rabm_pdcp_struct.h"
#include "drlc_urlc_struct.h"
#include "urlc_umac_enums.h"
#include "urlc_umac_struct.h"
#include "drlc_umac_struct.h"
#include "pdcp_urlc_struct.h"  /* Jeff Wu 2006-02-13: For RLC Reset and Reestablish */
#include "rlc_common.h"
#include "l2l_comm.h"
#include "ul2_common.h"
#include "ciphering_common.h"
#include "retransmission_buffer.h" /* frost: for MCD to parse urlc control pdu. */
#ifdef __CGEN_UMTS_FDD_MODE__ /* __UMTS_FDD_MODE__ */
#include "rlc_cid.h" /* Roger 100310 : for compile option depend on ECO/IC version */
#include "urlc_drv_enums.h"  /* Kathie: for rlc_hsupa_cmd_struct */
#include "urlc_drv_struct.h"   /* Kathie: for rlc_hsupa_cmd_struct */
#include "seq_common.h"
#include "rlc_drv_common.h" /* Peng-An: for rlc_cmd_struct using in urlc_seq_struct.h */
#include "rlc_drv_rx.h" /* Peng-An: for rlc_cmd_struct using in urlc_seq_struct.h */
#include "urlc_seq_struct.h"
#include "umac_seq_struct.h"
#include "cseq_struct.h"
#endif
/* for URR internal interface */
#include "urr_acknowledge.h"
#include "urr_slce_enums.h"
#include "urr_slce_struct.h"
#include "rrce_csce_enums.h"
#include "rrce_csce_struct.h"
#include "rrce_meme_enums.h"
#include "rrce_meme_struct.h"
#include "rrce_sibe_enums.h"
#include "rrce_sibe_struct.h"
#include "rrce_slce_enums.h"
#include "rrce_slce_struct.h"
#include "rrce_usime_struct.h"
#include "csce_usime_struct.h"
#include "seq_enums.h"
#include "seq_struct.h"
#include "csce_cse_enums.h"
#include "cse_racache.h"        // For showing cache content to Catcher...>#I
#include "csce_cse_struct.h"
#include "csce_meme_enums.h"
#include "csce_meme_struct.h"
#include "csce_sibe_enums.h"
#include "csce_sibe_struct.h"
#include "cse_slce_struct.h"
#include "csce_slce_struct.h"
#include "cse_meme_struct.h"
#include "cse_sibe_enums.h"
#include "cse_sibe_struct.h"
#include "sibe_slce_enums.h"
#include "sibe_slce_struct.h"
#include "adr_drlc_enums.h"
#include "adr_drlc_struct.h"
#include "bmc_drlc_struct.h"
#include "meme_sibe_enums.h"
#include "meme_sibe_struct.h"
#include "meme_slce_enums.h"
#include "meme_slce_struct.h"
#include "dbme_struct.h"
#include "urr_signal_in.h"
#include "nvram_data_items.h"
#include "ex_item.h"
#include "dsmgr.h"
#include "sim_public_enum.h"
//#ifdef __UMTS_FDD_MODE__
#include "sibe_enums.h"
#include "sibe_struct.h"
#include "usime_struct.h"
//#endif

/* discuss with SIM owner, UAS add sim header file when requirement.*/
#if ((defined(UNIT_TEST) && defined(__UMTS_TDD128_MODE__)) || defined(__SGLTE__))
#include "sim_private_struct.h"
#endif

/* for RATCM/UAS interface */
#include "ratcm_uas_enums.h"
#include "ratcm_slce_enums.h"
#include "ratcm_rrce_enums.h"
#include "usim_data.h"       /* for ratcm_rrce_struct.h */
#include "ratcm_uas_struct.h"
#include "ratcm_rrce_struct.h"
#include "ratcm_csce_enums.h"
#include "ratcm_csce_struct.h"
#include "ratcm_slce_struct.h"
#include "ratcm_cse_enums.h"
#include "ratcm_cse_struct.h"
#include "cs_types.h"
#include "ratcm_bmc_struct.h"
#include "ratcm_csr_struct.h"
#include "ratdm_rabm_struct.h"   /* should be after crabm_struct.h */
#include "ratcm_urlc_struct.h"
#include "ratdm_urlc_struct.h"
#include "ratcm_usime_struct.h"

/* for EAS interface */
#include "ratdm_el2_struct.h"

/* for UAS/GAS interface */
#include "uas_gas_enums.h"
#include "uas_gas_struct.h"

#include "nas_as_inter_core_struct.h"

#ifdef __GEMINI__
/* for GAS/UL2 interface */
#include "l3_inc_enums.h" /* for as_suspend_mode_reason_enum */
#include "gas_ul2_gemini_struct.h"
#include "gas_ul2d_gemini_struct.h"
#endif /* __GEMINI__ */

/*Vito: for CSR UT */
#include "rab.h"
#include "csr_fsm.h"

/* Jeff Wu 2006-02-13: For RABM/PDCP UT */
#include "as_common.h"
#include "flc2_config.h"
#include "cpdcp.h"
#include "pdcp.h"
#include "ps_data.h"
#include "bigend.h"
#include "pdcp_context.h"
#include "rabm_fsm.h"
#include "rabm_context.h"
#include "rabm_timer.h"

/* Evan Chen 2007-08-13: For MM UT */
#include "mm_common_context.h"
#include "mm_cs_context.h"
#include "mm_ps_context.h"
#include "mm_cs_defs.h"
#include "l3_inc_enums.h"
#include "mm_ratcm_enums.h"
#include "mm_common.h"
#include "mm_ps_defs.h"
#include "l3_inc_local.h"


/* Gibran Chang 2006/03/23: For CSCE */
#include "csce_fsm.h"
#include "csce_context.h"

/* Nicky Chou 2014/08/25: For LCSCE */
#include "lcsce_context.h"
#include "lcsce.h"
#include "lcsce_struct.h"
#include "lcsce_enum.h"
#include "csce_lcsce_struct.h"
#include "csce_lcsce_enum.h"
#include "csce_meme_inter_core_struct.h"
#include "csce_meme_inter_core_enum.h"
#include "urr_inter_core_enum.h"
#include "as_inter_core_enum.h"

/* For LMEME */
#include "lmeme.h"
#include "lmeme_context.h"
#include "lmeme_struct.h"
#include "lmeme_enum.h"
#include "meme_lmeme_struct.h"
#include "meme_lmeme_enum.h"

/*For LRRCE*/
#if defined(__CGEN_UMTS_TDD128_MODE__)
#include "lrrce.h"
#include "lrrce_lurlc_struct.h"
#include "rrce_lrrce_enum.h"
#include "rrce_lrrce_struct.h"
#endif

/* Dennis Weng 2010/08/09: For SIBE */
#include "sibe_fsm.h"
/* YenChih Yang 2012/04/18: For USIME */
#include "usime_context.h"

/* For MEME */
/* For TDD please modify the code wrapped by __UMTS_TDD128_MODE__ */
/* For TDD please modify the code wrapped by __UMTS_FDD_MODE__ */
#ifdef __GEMINI__
#include "uas_gas_gemini_enums.h"
#endif

#if defined(__CGEN_UMTS_TDD128_MODE__)
#include "meme_fsm.h"
#include "memetypes.h"
#include "em_struct.h"
#include "meme_def.h"
#include "rrc_meme_utilities.h"
#include "rrc_meme_timing.h"
#include "meme_context.h"
#include "rrc_protocol_timing.h"
#endif

#if defined(__CGEN_UMTS_FDD_MODE__) /* defined(__UMTS_FDD_MODE__) */
#include "meme_fsm.h"
#include "meme_def.h"
#include "rrc_meme_utilities.h"
#include "meme_context.h"
#include "rrc_meme_phys_layer.h"
#endif

/* MH Change 2006/04/18: For RRCE */
#include "rrci_fsm.h"
#include "rrcn_fsm.h"
#include "rrce_context.h"
#include "rrc_fsm_tmr_utils.h"
#include "rrce_fsm.h"

/* John Tang 2005/11/08: For DB Unit-test tool */
#ifdef GEN_FOR_PC

#define __int64
#define __cdecl
//#include "ub_msg.h"
#include "db_schema.h"
#include "db_io.h"
#include "./fdd/db_dump_api_fdd.h"
#include "./tdd/db_dump_api_tdd.h"

#endif //#ifndef __L1_STANDALONE__


#include "rrc_db_all_struct.h"


/* Alfie: 2006-0422 For SLCE Trace Info Start */
#ifndef __size_t
#define __size_t 1
typedef unsigned int size_t;  /* used for dbme.h */
#endif

#include "uas_common_enums.h"
#include "dbme.h"
#include "db_access.h"
#ifdef __CGEN_UMTS_FDD_MODE__ /* __UMTS_FDD_MODE__ */
#include "dbme_context.h"
#endif
#include "crlc_enums.h"
#include "crlc_struct.h"
#include "rrce_slce_enums.h"
#include "seq_enums.h"
#include "seq_struct.h"
#include "slce_context.h"
#include "slce_fsm.h"
/* Alfie: 2006-0422 For SLCE Trace Info End */


/*Christine 2006/05/02*/
#include "transaction.h"
#include "rrcc_fsm.h"

#endif
//Matt 2007/11/30 for VT feature
/*
#ifdef __VIDEO_CALL_SUPPORT__
#include "vt_med_enum.h"
#include "vt_med_struct.h"
#include "vt_mmi_struct.h"
#include "..\..\..\3g324m\interface\inc\vt_tst_enum.h"
#include "..\..\..\3g324m\appl\inc\vt_ut_struct.h"
#include "csm2vt_struct.h"
#endif
*/

#endif /* __UMTS_RAT__ */
#ifdef __L1_STANDALONE__
#ifdef __MOD_NVRAM__
#include "nvram_data_items.h"
#include "ex_item.h"

#if defined(__MMI_FMI__)
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#endif

#include "nvram_editor_data_item.h"
#endif /*__MOD_NVRAM__*/
#endif
/**************************************************************************
 * WCDMA INTERFACE ENDS
 **************************************************************************/

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
#include "gps_struct.h"
#ifdef __AGPS_SUPPORT__
#include "gps2lcsp_enum.h"
#include "gps2lcsp_struct.h"
#endif /* __AGPS_SUPPORT__ */
#endif

#include "lbs_dhl_struct.h"

#ifdef __RRLP_SUPPORT__
#include "rr2rrlp_struct.h"
#include "rrlp_common_headers.h"
#include "rrlp_enum.h"
#endif /* __RRLP_SUPPORT__ */

#ifdef __AGPS_SUPPORT__

#if defined(__UAGPS_CP_SUPPORT__)
#include "uagps_cp_csce_struct.h"
#include "uagps_cp_sibe_struct.h"
#include "uagps_cp_meme_struct.h"
#include "l4c_uagps_cp_struct.h"
#include "uagps_cp_gps_struct.h"
#endif /* __UAGPS_CP_SUPPORT__ */

#include "lbs_common_enum.h"
#endif /* __AGPS_SUPPORT__ */

#if defined(__AGNSS_SUPPORT__)
#include "gnss2lcsp_struct.h"
#include "gnss2lcsp_enum.h"
#endif /* #if defined(__AGNSS_SUPPORT__) */

/* for LPP*/
#if defined(__LTE_RAT__) && defined(__LPP_SUPPORT__)
#include "lpp_msg_struct.h"
#include "lpp_msg_enum.h"
#include "lpp_lbs_msg_struct.h"
#include "lpp_context.h"
#include "lpp_mcd_struct_id.h"
#include "Hal_el1_def.h"
#include "Hal_el1_struct.h"
/* LPPe */
#if defined(__LPP_EXT_SUPPORT__)
#include "lpp_lppe_struct.h"
#include "lpp_ext_context.h"
#endif /* __LPP_EXT_SUPPORT__ */
#endif
#include "as2l4c_struct.h"

#ifdef __ACMT_SUPPORT__
#include "nas2l4c_struct.h"
#endif

/*For UL1A*/
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#include "ul1a_enum.h"
#endif

#if defined (__WMT_SUPPORT__) || defined(__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
#include "wmt_struct.h"
#endif /* __WMT_SUPPORT__*/

#ifdef __GADGET_SUPPORT__
#include "widget_adp_struct.h"
#endif /* __GADGET_SUPPORT__ */

#if defined(__RMMI_UT__)
#include "l3_inc_struct.h"
//#include "mmi_sm_enums.h"
//#include "ppp_l4_enums.h"
#include "tcm_common_enums.h"
#include "tcm_common.h"
#include "tcm_timer.h"
//#include "l3_inc_local.h"
//#include "l4crac_enums.h"
//#include "rac2l4c_struct.h"
//#include "mmi2mm_struct.h"
//#include "rac_defs.h"
#include "tcm_context.h"
#endif

#include "sim_public_struct.h"
#include "sim_private_struct.h"
#include "sim_public_enum.h"

#ifndef __MTK_TARGET__
#include "l4c_context.h"
#include "ciss_context.h"//for CISS UT
#include "l4c_c2k_msg.h"
#endif

#if defined(__L4C_GPRS_UT__)
#include "rmmi_context.h"
#endif

#ifndef __L1_STANDALONE__
#include "rmmi_common_enum.h"
#include "rmmi_struct.h"
#endif
#ifdef __VIDEO_ARCHI_V2__
#endif /* __VIDEO_ARCHI_V2__ */

/* mpl & source*/
//#include "mpl_common.h"
//#include "mpl_player.h"

#if defined(__L1_GPS_REF_TIME_SUPPORT__) || defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__)
#include "hal_l1_struct.h"
#endif /*(__L1_GPS_REF_TIME_SUPPORT__) || (__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__)*/

#if defined (__MOD_NVRAM__)
#include "nvram_editor_data_item.h"
#endif
/* mtk04121 */

/* SIM CODEGEN begin */
#ifndef SIM_NOT_PRESENT
#include "sim_ps_struct.h"
#include "sim_public_struct.h"
#endif
/* SIM CODEGEN end */

/* EVAL CODEGEN begin */
#ifdef __EVAL_ENABLE__
#include "eval_msgid.h"
#include "l4c_eval_struct.h"
#include "nwsel_eval_struct.h"
#include "rac_eval_struct.h"
#include "tcm_eval_struct.h"
#include "sms_eval_struct.h"
#include "smsal_eval_struct.h"
#endif
/* EVAL CODEGEN end */

//etc interface
#include "etc_upcm_struct.h"
#include "etc_msgid.h"

/* TFTLIB CODEGEN */
#include "tftlib_common_struct.h"
#include "tftlib_msgid.h"
#include "tftlib_msg_struct.h"

/* mtk00938: Multimode interfaces */
#ifdef __LTE_RAT__
#include "mm_emm_struct.h"
#include "sm_esm_struct.h"
#endif

/* mtk00938: This file is necessary even without LTE */
#include "irat_common_struct.h"

/* MOD_PAM */
#ifdef __PS_SERVICE__
#include "pam_msg_struct.h"
#include "nwsel_pam_struct.h"
#include "pam_context.h"
#include "pam_sm_proc.h"
#include "pam_vzw_util.h"
#include "pam_send_msg.h"
#include "pam_assert.h"
#include "pam_main.h"
#include "pam2tcm_struct.h"
#include "usm_context.h"
#endif /* __PS_SERVICE__ */

/* UTT/LTT/GTEST */
#ifdef __LTT_ENABLE__
#include "ltt_msgid.h"
#include "utt_msg_struct.h"
#include "utt_main_cfg_includes.h"
#endif /* __LTT_ENABLE__ */

/* global enum */
/***************************************************************
*  if add _msgid.h or _sap.h file, should include the _msgid.h or _sap.h in :                *
*    kal_debug_msg_sap_defs.h & libParseDbModem.c & srcParseDbModem.c          *
****************************************************************/
#include "module_msg_range.h"
#include "sysservice_msgid.h"	
#include "cc_msgid.h"	
#include "ciss_msgid.h"	
#include "mm_msgid.h"	
#include "sms_msgid.h"	
#include "sim_public_msgid.h"	    
#include "sim_ps_msgid.h"
#include "ps_public_l4_msgid.h"	
#include "l4_msgid.h" 
#include "psdm_msgid.h"
#include "rr_msgid.h"
#include "llc_msgid.h"    
#include "p2p_msgid.h"     
#include "sndcp_msgid.h"   
#include "sm_msgid.h"    
#include "pam_msgid.h"
#include "data_msgid.h"
#include "ps_public_vt_msgid.h"    
#include "VT_msgid.h"    
#include "nvram_msgid.h"      
#include "l1_msgid.h"    
#include "hal_l1_msgid.h"    
#include "l1hisr_msgid.h"     
#include "ft_msgid.h"   
#include "tst_msgid.h"    
#include "audio_msgid.h"    
#include "cldmacore_msgid.h"
#include "ratcm_msgid.h"    
#include "ratdm_msgid.h"    
#include "urr_msgid.h"    
#include "ul2_msgid.h" 
#include "ul2d_msgid.h"  
#include "uas_gas_msgid.h"     
#include "mrs_msgid.h"
#include "uas_gas_gemini_msgid.h"	
#include "ul1_msgid.h"    
#include "ul1data_msgid.h"     
#include "ul1hisr_msgid.h"   
#include "ul1c_msgid.h"    
#include "ll1_msgid.h"     
#include "ul1tst_msgid.h"     
#include "ulcs_msgid.h"    
#include "tl1_msgid.h"    
#include "lpp_msgid.h"
#include "tl1data_ast_msgid.h"      
// #include "tl1hisr_ast_msgid.h" File Removed (Tafang)     
#include "tl1fta_ast_msgid.h"   
#include "rsva_msgid.h"
#include "ndis_msgid.h"     
#include "ps_public_ups_msgid.h"    
#include "ups_msgid.h"     
#include "ps_public_supl_msgid.h"      
#include "supl_msgid.h"     
#include "cmux_msgid.h"     
#include "ppp_msgid.h"	
#include "ext_modem_msgid.h"	
#include "wmt_msgid.h"
#include "em_msgid.h"    
#include "fs_msgid.h"         
#include "med_msgid.h"    
#include "dps_msgid.h"   
#include "udps_msgid.h"
#include "drv_msgid.h"    
#include "meut_msgid.h"	
#include "l1_ext_msgid.h"	
#include "haplus_msgid.h"
#include "hif_mw_msgid.h"
#include "hif_svc_msgid.h"
#include "el1_msgid.h"    

#include "sap_range.h"
#include "svc_sap.h"	
#include "md_sap.h"	
#include "md_svc_sap.h"	
#include "md_drv_sap.h"	
#include "md_mmi_sap.h"	
#include "md_mw_sap.h"	
#include "mw_sap.h"	
#include "drv_sap.h"

#include "global_modid.h"
#include "srv_modid.h"
#include "modem_2g3g_modid.h"
#include "modem_4g_modid.h"
#include "middleware_modid.h"
#include "drv_modid.h"
#include "hisr_modid.h"
#if defined(__GSM_RAT__) || defined(__UMTS_RAT__) // BJM
#include "l1_core_private.h"
#include "l1_rtb.h"
#ifdef __MTK_UL1_FDD__	
#include "ul1c_trc.h"
#include "ul1c_core_private.h"
#include "ul1_public.h"
#endif /* __MTK_UL1_FDD__ */
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */

#include "waal_msgid.h"
#include "waal_errc_struct.h"
#include "waal_ipc_msg_struct.h"
#include "waal_defs.h"

//mtk04121
#if defined(__ETCM__)
#include "tcm_eval_struct.h"
#include "tcm_eval_enums.h"
#include "tcm_upcm_struct.h"

#include "eval_msgid.h"
#include "upcm_msgid.h"

#endif

#include "qmu_bm_enum.h"
#include "upcm_enum.h"
#include "tft_pf_enum.h"

#ifdef __KPALV_SUPPORT__
#include "kpalv_msgid.h"
#include "kpalv_struct.h"
#endif

#include "qbm_stats.h"
#include "upcm_em_struct.h"
#include "uas_data_common.h"

/* for RAC/GAS interface */
#include "rac_gas_enums.h"
#include "rac_gas_struct.h"

#if defined(__IMS_SUPPORT__)
/* VDM */
#include "vdm_imsp_struct.h"
#include "vdm_imc_struct.h"
#include "vdm_ctrl_trk_msg.h"
#include "vdm_ctrl_ads_msg.h"
#include "vdm_ctrl_vcc_msg.h"
#include "vdm_trk_ads_msg.h"
#include "vdm_trk_vcc_msg.h"
#include "vdm_ads_vcc_msg.h"
#include "vdm_ut.h"
#include "vdm_trk_ut.h"
#include "vdm_ads_ut.h"
#include "vdm_vcc_ut.h"
#include "vdm_val_struct.h"

/* SDM */
#include "sdm_imsp_struct.h"
#include "sdm_imcsms_enums.h"
#include "sdm_imcsms_struct.h"
#include "sdm_trc.h"
#include "sdm_msgid.h"
#include "sdm_context.h"

/* IMSP */
#include "proxy_atci_struct.h"
#include "imsp_msgid.h"
#include "imsp_imcsms_struct.h"

/* IMC */
#include "dhl_ims_sap_collect.h"

/* IMCSMS */
#include "imcsms_msgid.h"
#include "imcsms_imc_struct.h"
#include "imcsms_enums.h"
#include "imcsms_defs.h"
#include "imcsms_rl.h"
#include "imcsms_context.h"
#include "imcsms_timer.h"

#endif /* defined(__IMS_SUPPORT__) */

/* CCCI IPC */
#if defined(__CCCIDEV_SUPPORT__)
#include "ccci_ipc_msgid.h"
#include "cccisrv_struct.h"
#endif /*defined(__CCCIDEV_SUPPORT__)*/

#include "ps_public_struct.h"

#ifdef __IPCORE_SUPPORT__
#include "pfm_struct.h"
#include "pfm_enums.h"
#endif /* __IPCORE_SUPPORT__ */

#if defined(__HLT_SUPPORT__)
#include "hlt_if.h" 
#endif
#include "mmrf_msgid.h"
#include "mmrf_msg_interface.h"
#include "mml1_meta_if.h"
#include "ft_msg.h"
#include "ftc_msg.h"
#include "l1tst_msgid.h"
#include "el1tst_msgid.h"
#include "audio_struct.h"
