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
 *   l1d_rf_l1core.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   RF constance defintion
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.65  $
 * $Modtime:   Jul 29 2005 13:42:20  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/l1d_rf.h-arc  $
 *
 * 12 09 2015 wiley.li
 * [MOLY00152446] [L1D][Modify] Raise VS1 voltage for JADE- PMIC6353 (Enable by compile option __INCREASE_VS1_VOLTAGE_SUPPORT__)
 * 	
 * 	.
 *
 * 07 13 2015 yi-ying.lin
 * [MOLY00127539] [L1D][Modify] Check in the L1D co-TSX modification
 * 	.
 *
 * 06 18 2015 prakash.chaudhary
 * [MOLY00122406] [L1D][modify]Check in BB driver for Jade BB porting
 * 	.
 *
 * 04 15 2015 ola.lee
 * [MOLY00091988] [L1D] Update MT6176 2G RF Driver
 * Fix G->8 EDGE TX PVT.
 *
 * 03 09 2015 ola.lee
 * [MOLY00091988] [L1D] Update MT6176 2G RF Driver
 * 	.
 *
 * 03 04 2015 yi-ying.lin
 * [MOLY00097724] [L1D][Modify] Fix CC nvram and custom data error.
 *
 * 02 17 2015 th.yeh
 * [MOLY00096471] [L1D][Modify] TK6291 BB driver refined
 * .
 *
 * 02 16 2015 ola.lee
 * [MOLY00091988] [L1D] Update MT6176 2G RF Driver
 * 	.
 *
 * 02 02 2015 ola.lee
 * [MOLY00091988] [L1D] Update MT6176 2G RF Driver
 *
 * 01 28 2015 th.yeh
 * [MOLY00085815] [L1D][Modify] TK6291 BB driver porting
 * .
 *
 * 11 06 2014 hosen.chen
 * [MOLY00080383] [L1D][Modify] Check in 2G modem sim related file
 * 	.
 *
 * 06 17 2014 yi-ying.lin
 * [MOLY00068792] [L1D][Modify] Modify DT-coexistence and provide 2G RX status to LTE feature option
 * 	.
 *
 * 06 10 2014 yi-ying.lin
 * [MOLY00068792] [L1D][Modify] Modify DT-coexistence and provide 2G RX status to LTE feature option
 * Rollback //MOLY/TRUNK/MOLY/mcu/interface/modem/l1/gsm/external/l1cal.h to revision 17
 *
 * 05 29 2014 yi-ying.lin
 * [MOLY00067365] [L1D][Modify] MT6752 L1D driver developement.
 *
 * 05 15 2014 ola.lee
 * [MOLY00065703] [L1D] Add MT6752(K2) Chip option to avoid build error
 * 	.
 *
 * 03 13 2014 yi-ying.lin
 * [MOLY00059400] [L1D][Modify] DT-coexistence L1D control patch back
 * 	.
 *
 * 01 22 2014 ola.lee
 * [MOLY00054402] [MT6290E2][MML1 RF] Add clock gating before BSISPI init setting
 * 	.
 *
 * 12 16 2013 hosen.chen
 * [MOLY00046159] [L1D][Modify] Check in code of MT6595 2G modem driver modification
 * 	.
 *
 * 10 03 2013 ola.lee
 * [MOLY00040175] [MT6290E1][W/G][sanityfail] can't camp on 2G network
 * 	.
 *
 * 10 02 2013 ola.lee
 * [MOLY00039576] [MT6165] Merget MT6165 to MOLY for Dual Talk
 * 	.
 *
 * 09 27 2013 chunyen.wu
 * [MOLY00039325] [L1D][Modify] Modify MT6169 E1 Tx CW & Gainbb0 setting
 * 	.
 *
 * 08 14 2013 yi-ying.lin
 * [MOLY00028415] [82LTE.SMT.DEV] 6166/6169 2G calibration feature development
 * .
 *
 * 07 29 2013 hosen.chen
 * [MOLY00028415] [82LTE.SMT.DEV] 6166/6169 2G calibration feature development
 * .
 *
 * 06 04 2013 sean.yang
 * [MOLY00024860] [L1D][Modify] DCS TDB39 co-existence support
 * .
 *
 * 05 28 2013 yuyang.hsiao
 * [MOLY00023994] [MT6290 PO admit] Update TX propagation delay
 * <saved by Perforce>
 *
 * 04 15 2013 yuyang.hsiao
 * [MOLY00016402] [L1D][Modify] Update MT6169 RF final parameter
 * .
 *
 * 04 10 2013 yuyang.hsiao
 * [MOLY00013647] [L1D][Modify] MT6169 RF Driver update - TDD part and rename compile option
 * .
 *
 * 03 28 2013 yuyang.hsiao
 * [MOLY00012979] [L1D][Modify] Add MT6169 RF Driver
 * .
 *
 * 03 28 2013 hosen.chen
 * [MOLY00012945] [L1D][Modify] Check in code of MT6290
 * .
 *
 * 12 27 2012 yi-ying.lin
 * [MOLY00007941] [MT6280][check-in request] Set STX_DEM_Chunk[6:0] to 1111_1110 prevent overflow during settling
 * .
 *
 * 11 02 2012 yi-ying.lin
 * [MOLY00005700] [L1D][Modify] MT6280 E2 RF driver development
 * .
 * 
 * 09 22 2012 yi-ying.lin
 * [MOLY00003788] [L1D][Modify] MT6280 E2 RF driver development
 * .
 * 
 * 09 20 2012 yi-ying.lin
 * [MOLY00003788] [L1D][Modify] MT6280 E2 RF driver development
 * .
 * 
 * 09 06 2012 yuyang.hsiao
 * [MOLY00003161] [L1D][Modify] Change the DCXO CLK_SETTLE_DEFAULT value
 * .
 * 
 * 08 27 2012 yuyang.hsiao
 * [MOLY00002684] [L1D][Modify] MT6280 E2 RF driver development
 * .
 *
 * 07 02 2012 samuel.yang
 * [MOLY00000210] [L1D][Modify] Remove the include path of "m12197.h include l1_rf.h" for MSBB2 modification
 * .
 *
 * 06 22 2012 samuel.yang
 * removed!
 * .
 *
 * 06 19 2012 yi-ying.lin
 * removed!
 * .
 *
 * 06 19 2012 yuyang.hsiao
 * removed!
 * .
 *
 * 06 14 2012 samuel.yang
 * removed!
 * .
 *
 * 05 14 2012 weining.chien
 * removed!
 * .
 *
 * 05 11 2012 chang-kuan.lin
 * removed!
 * .
 *
 * 05 10 2012 yuyang.hsiao
 * removed!
 * .
 *
 * 03 29 2012 samuel.yang
 * removed!
 * .
 *
 * 03 15 2012 yuyang.hsiao
 * removed!
 * .
 *
 * 12 09 2011 weining.chien
 * removed!
 * .
 *
 * 11 17 2011 chang-kuan.lin
 * removed!
 * .
 *
 * 11 08 2011 jason.lai
 * removed!
 * .
 *
 * 10 21 2011 th.yeh
 * removed!
 * .
 *
 * 09 22 2011 th.yeh
 * removed!
 * .
 *
 * 08 18 2011 chang-kuan.lin
 * removed!
 * .
 *
 * 08 10 2011 sean.yang
 * removed!
 * .
 *
 * 08 02 2011 samuel.yang
 * removed!
 * .
 *
 * 07 08 2011 weining.chien
 * removed!
 * .
 *
 * 06 18 2011 victo.chen
 * removed!
 * .
 *
 * 05 10 2011 sean.yang
 * removed!
 * .
 *
 * 04 20 2011 cs.wu
 * removed!
 * .
 *
 * 04 15 2011 weining.chien
 * removed!
 * .
 *
 * 04 15 2011 victo.chen
 * removed!
 * .
 *
 * 04 14 2011 sean.yang
 * removed!
 * .
 *
 * 03 28 2011 sean.yang
 * removed!
 * .
 *
 * 03 22 2011 jason.lai
 * removed!
 * .
 *
 * 03 16 2011 sean.yang
 * removed!
 * .
 *
 * 03 11 2011 sean.yang
 * removed!
 * .
 *
 * 03 08 2011 jason.lai
 * removed!
 * Check in PLL reset.
 *
 * 01 26 2011 sean.yang
 * removed!
 * .
 *
 * 01 19 2011 chuwei.lo
 * removed!
 * .
 *
 * 01 16 2011 chuwei.lo
 * removed!
 * .
 *
 * 01 05 2011 chuwei.lo
 * removed!
 * .
 *
 * 01 04 2011 sean.yang
 * removed!
 * .
 *
 * 01 04 2011 sean.yang
 * removed!
 * .
 *
 * 12 14 2010 jason.lai
 * removed!
 * .
 *
 * 12 08 2010 chuwei.lo
 * removed!
 * .
 *
 * 12 03 2010 sean.yang
 * removed!
 * .
 *
 * 12 01 2010 yr.chiang
 * removed!
 * .
 *
 * 11 24 2010 sean.yang
 * removed!
 * .
 *
 * 11 19 2010 yr.chiang
 * removed!
 * .
 *
 * 11 10 2010 yr.chiang
 * removed!
 * .
 *
 * 11 09 2010 max.weng
 * removed!
 * .
 *
 * 11 03 2010 samuel.yang
 * removed!
 * .
 *
 * 10 22 2010 jason.lai
 * removed!
 * .
 *
 * 09 21 2010 yr.chiang
 * removed!
 * .
 *
 * 09 15 2010 chang-kuan.lin
 * removed!
 * .
 *
 * 09 09 2010 samuel.yang
 * removed!
 * .
 *
 * 08 21 2010 yr.chiang
 * removed!
 * .
 *
 * 08 20 2010 samuel.yang
 * removed!
 * .
 *
 * 08 10 2010 jason.lai
 * removed!
 * .
 *
 * 08 07 2010 samuel.yang
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
 *
 *
 * removed!
 * removed!
 * Merge MT6251 DVT branch back to MAUI
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
 * Revise code
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
 * Modify for AD6546 RF Driver
 *
 * removed!
 * removed!
 * Sync l1_dm & l1 code for non-WCDMA part
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
 * PR2M will automatically copy the last BPI event (PR2 or PR2B) before RX window if it is not defined
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
 * BSI clock setting:
 *
 * The external clock is changed from 52MHz to 26MHz.
 * Add new compile option BSI_CLK_SPD to configure BSI_CON"
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
 * Add RF driver of IRFS3001
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
 * Add the compile option for MT6230
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
 * deliver MAUI_00174200 on 2006/2/27 ¤U¤È 05:12:46.
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
 *    Rev 1.65   Jul 29 2005 14:00:34   mtk00773
 * [L1D][Enhence] Support RF SKY74117
 * Resolution for 12111: [L1D][Enhence] Support RF SKY74117
 *
 *    Rev 1.64   Jul 08 2005 16:53:02   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.63   May 17 2005 00:34:20   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.62   May 16 2005 11:46:24   mtk00240
 * Support 22 BPI setting & current sense PA
 * Resolution for 11091: [L1D][New Feature] Support 22 BPI setting & current sense PA
 *
 *    Rev 1.61   Jan 18 2005 00:37:58   BM
 * append new line in W05.04
 *
 *    Rev 1.60   Oct 29 2004 12:44:56   mtk00240
 * Open interface to get battery voltage & temperature in m12190
 * Resolution for 7034: [L1D][Add feature] Open PCL & PathLoss compensation function for customer.
 *
 *    Rev 1.59   Jul 30 2004 17:37:06   mtk00240
 * L1D add code to support AERO1Plus RF chip
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.58   Jul 05 2004 15:48:20   mtk00773
 * Add RF POLARIS1 setting
 *
 *    Rev 1.57   May 31 2004 11:52:12   mtk00585
 * [L1D][Modify] Add TX Swing Auto Calibration.
 * Resolution for 5743: [L1D][Modify] Add TX Swing Auto Calibration.
 *
 *    Rev 1.56   May 21 2004 19:01:58   mtk00240
 * Add code to support MT6129D
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.55   May 21 2004 14:53:30   mtk00240
 * Support mt6218B_FN & mt6129_BV chip (Also remove BFE seting from customer config)
 * Resolution for 5550: [L1D][Enahnce] Support mt6218B_FN & mt6129_BV chip (Also remove BFE seting from customer config)
 *
 *    Rev 1.54   Feb 13 2004 23:53:10   mtk00489
 * [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 * Resolution for 3912: [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 *
 *    Rev 1.53   Jan 27 2004 15:33:12   mtk00585
 * [L1D][Add] L1D Add code for MT6129C RF Driver.
 *
 *    Rev 1.52   Jan 12 2004 17:31:56   mtk00585
 * [L1D][Modify] In order of solving MT6119 synthesizer out of lock problem, we send Warm Up command before Set PLL command.
 * Resolution for 3724: [L1D][Modify] In order of solving MT6119 synthesizer out of lock problem, we send Warm Up command before Set PLL command.
 *
 *    Rev 1.51   Oct 23 2003 14:20:54   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.50   Jul 11 2003 17:41:30   mtk00489
 * [L1D][Enhanced]L1D supports MT6129A
 * Resolution for 2241: [L1D][Enhanced]L1D supports MT6129A
 *
 *    Rev 1.49   Jun 06 2003 18:42:46   mtk00489
 * [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files include l1d_rf.h should also include l1d_custom_rf.h 6.change l1d_cid.h
 * Resolution for 1961: [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files
 *
 *    Rev 1.48   May 16 2003 13:09:22   mtk00489
 * [L1D][New Feature]L1D supports MT6119C
 * Resolution for 1794: [L1D][New Feature]L1D supports MT6119C
 *
 *    Rev 1.47   May 13 2003 11:26:46   mtk00489
 * [L1D][Enhanced]L1D shorten BRIGHT4's QB_PT1 timing to 149 (from 233) because QB_PT1 should not before QB_ST1 in l1 simulation.
 * Resolution for 1785: [L1D][Enhanced]L1D shorten BRIGHT4's QB_PT1 timing to 149 (from 233) because QB_PT1 should not before QB_ST1 in l1 simulation.
 *
 *    Rev 1.46   May 08 2003 10:21:10   mtk00489
 * [L1D][FixBug]After setting gain(SR2), MT6119 needs RF input for gain settling. For GSM/DCS band, there always exist RF input. But for PCS band, we have to pull PCS_RCTL before or the same as SR2, to let RF signal in. Otherwise, I/Q will ring when higher gain. So QB_PR2(100) set the same value as QB_SR2(100).
 * Resolution for 1734: [L1D][FixBug]After setting gain(SR2), MT6119 needs RF input for gain settling. For GSM/DCS band, there always exist RF input. But for PCS band, we have to pull PCS_RCTL before or the same as SR2, to let RF signal in. Otherwise, I/Q will r
 *
 *    Rev 1.45   Apr 30 2003 20:41:08   mtk00489
 * [L1D][Enhanced]L1D fills chip specific registers to support MT6205B - a.RX_CON / AFC_CALIBIAS b.RXADC_NoiseFlow c.BBTX_GAIN
 * Resolution for 1693: [L1D][Enhanced]L1D fills chip specific registers to support MT6205B.
 *
 *    Rev 1.44   Apr 11 2003 16:44:42   mtk00489
 * [L1D][FixBug] L1D adjust SR2(from 40 to 100) for MT6119 by SA's request. In order to lower the ring of I/Q when channel filter switching
 * Resolution for 1522: [L1D][FixBug] L1D adjust SR2(from 40 to 100) for MT6119 by SA's request. In order to lower the ring of I/Q when channel filter switching
 *
 *    Rev 1.43   Mar 05 2003 09:09:46   mtk00474
 * modify the ST1(400->450) and the PDATA of PT2 for MT6119
 * Resolution for 660: modify the ST1 and the PDATA of PT2 for MT6119
 *
 *    Rev 1.42   Feb 10 2003 12:19:04   mtk00474
 * change ST1 266 to 400 for MT6119
 * Resolution for 638: change ST1 266 to 400 for MT6119
 *
 *    Rev 1.41   Jan 17 2003 16:31:50   mtk00474
 * Update SR1 and SR3 for MT6119,
 * min time duration between two consecutive bsi events: 6*N + 4 (in quarter bit unit)
 * N: the number of bsi data words will be sent by the earlier bsi event.
 * Resolution for 630: Update SR1 and SR3 for MT6119
 *
 *    Rev 1.40   Dec 27 2002 21:15:50   mtk00489
 * L1D change QB_RX_FENA_2_FSYNC back to 33(4N+1) ONLY in Loopback mode
 * Resolution for 603: L1D change QB_RX_FENA_2_FSYNC back to 33(4N+1) ONLY in Loopback mode
 *
 *    Rev 1.39   Dec 20 2002 20:23:20   mtk00474
 * Modify PT2 data
 * Resolution for 599: Modify MT6119 PT2
 *
 *    Rev 1.38   17 Dec 2002 09:19:52   mtk00240
 * L1D change the defintion of QB_APC_DCOFFSET_2_RAMPUP to QB_APCDACON
 * Resolution for 594: L1D change the defintion of QB_APC_DCOFFSET_2_RAMPUP to QB_APCDACON
 *
 *    Rev 1.37   10 Dec 2002 08:12:24   mtk00240
 * modify some code to support MT6218 simulation
 * Resolution for 581: L1D add code to support MT6218
 *
 *    Rev 1.36   Dec 05 2002 22:22:04   mtk00474
 * Modify MT6119 QB_SR2/QB_PR2
 * Resolution for 582: Modify MT6119 QB_SR2/QB_PR2
 *
 *    Rev 1.35   05 Dec 2002 10:50:28   mtk00240
 * L1D add code to support MT6218
 * Resolution for 581: L1D add code to support MT6218
 *
 *    Rev 1.34   02 Dec 2002 13:36:08   mtk00240
 * L1D add  2QB to RX frame sync to frame enable to avoid receiving bad quality of slot2
 * Resolution for 576: L1D add  2QB to RX frame sync to frame enable to avoid receiving bad quality of slot2
 *
 *    Rev 1.33   Nov 29 2002 15:42:08   mtk00474
 * Add ST1 event data for MT6119. So that the BSI will send two data when ST1 happens to improve the side band suppression
 * Resolution for 575: Add ST1 event data for MT6119
 *
 *    Rev 1.32   22 Nov 2002 17:32:48   mtk00240
 * CLK_SETTLE_DEFAULT of all RF modules are 100
 * Resolution for 605: Adjust CLK_Settle time to around 3ms
 *
 *    Rev 1.31   12 Nov 2002 12:28:36   mtk00240
 * L1D add APC enable register setting for MT6218
 * Resolution for 558: L1D add APC enable register setting for MT6218
 *
 *    Rev 1.30   Nov 11 2002 18:04:58   mtk00474
 * Update MT6119 and AERO RF parameters
 * Resolution for 557: Update MT6119 and AERO RF parameters
 *
 *    Rev 1.29   07 Nov 2002 14:28:34   mtk00240
 * L1D modify the timing of setting gain during multi-RX slots
 * Resolution for 555: L1D modify the timing of setting gain during multi-RX slots
 *
 *    Rev 1.28   06 Nov 2002 10:30:42   mtk00240
 * (1) Remove SM clk defintion from l1d_data.h to l1d_rf.h
 * (2) CLK_SETTLE_DEFAULT is 200 except Bright4+MT6206 is 100
 * Resolution for 599: CLK_Settle time setting
 *
 *    Rev 1.27   01 Nov 2002 11:11:24   mtk00240
 * L1D modify TX PLL evaulation for new MT6119 chip
 * Resolution for 547: L1D modify TX PLL evaulation for new MT6119 chip
 *
 *    Rev 1.26   28 Oct 2002 09:19:42   mtk00240
 * Add Tx CALRCSEL CALBIAS setting for SA
 * Resolution for 524: L1D add TX_I/Q_OFFSET definition for SA
 *
 *    Rev 1.25   22 Oct 2002 08:18:00   mtk00240
 * L1D modified some control data of mt6119
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.24   08 Oct 2002 17:24:12   mtk00240
 * L1D add TX_I/Q_OFFSET definition for SA
 * Resolution for 524: L1D add TX_I/Q_OFFSET definition for SA
 *
 *    Rev 1.23   01 Oct 2002 09:40:38   mtk00240
 * L1D add TX_TRIM_I/Q definition for SA
 * Resolution for 514: L1D add TX_TRIM_I/Q definition for SA
 *
 *    Rev 1.22   11 Sep 2002 12:08:00   mtk00240
 * (1) All NB RX window is 156 bit
 * (2) All NB TX window is 148 bit
 * (3) change all slot boundary to 157/156/156/156
 * Resolution for 457: L1D change slot length to 157bit,156bit,156bit,156bit
 *
 *    Rev 1.21   03 Sep 2002 21:34:36   mtk00240
 * Add BSI Long/Short Enable Positive/Negative Enable
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.20   02 Sep 2002 17:10:14   mtk00240
 * Add BSI device CS polarity selection
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.19   24 Aug 2002 14:10:46   mtk00240
 *  L1D add code to support AERO RF Module
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.18   02 Aug 2002 08:40:48   mtk00240
 * Change the timing definition
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.17   23 Jul 2002 15:49:10   mtk00240
 * L1D add code to support MT6119 RF Module
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.16   18 Jul 2002 16:36:24   mtk00240
 * L1D modified code for MT6205
 * (1) change BPI setting (l1d_rf.h)
 * (2) Fix APC Scale factor (m12170.c)
 * (3) disable IDN_SEL and GPIO mode setting (m12190.c)
 * Resolution for 437: L1D modified code for MT6205
 *
 *    Rev 1.15   04 Jul 2002 12:05:20   mtk00240
 * add new definition
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.14   04 Jul 2002 12:00:02   mtk00240
 * rename some aliases and add reference table
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.13   03 Jul 2002 21:43:46   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.12   28 May 2002 23:40:08   mtk00240
 * Set TX_CMV value for Bright4
 * Resolution for 356: L1D add some code to operate Bright4 RF propertly
 *
 *    Rev 1.11   21 May 2002 13:26:16   mtk00240
 * Let Bright4 lock the frequency at the right time
 * Resolution for 356: L1D add some code to operate Bright4 RF propertly
 *
 *    Rev 1.10   16 May 2002 15:03:44   mtk00240
 * Modified some calibration data for Broght4
 * Resolution for 356: L1D add some code to operate Bright4 RF propertly
 *
 *    Rev 1.9   01 May 2002 22:45:54   mtk00240
 * Extract GSM code from L1D
 * Resolution for 384: Extract GSM code from L1D
 *
 *    Rev 1.8   23 Apr 2002 14:38:42   mtk00240
 * Changed R/TXSWAP form (0/1) to (1/0) and modified M flag in IF registers
 * Resolution for 356: L1D add some code to operate Bright4 RF propertly
 *
 *    Rev 1.7   12 Apr 2002 21:27:10   mtk00240
 * L1D add new initialized value for RF
 * Resolution for 359: L1D add new initialized value for RF
 *
 *    Rev 1.6   03 Apr 2002 19:30:30   mtk00240
 * Fix some code to support Bright4 properly
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 *
 *    Rev 1.5   30 Mar 2002 13:04:10   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.4   11 Mar 2002 13:35:40   mtk00240
 * instead TAB characters of Space characters in L1D code .
 * Resolution for 318: Shine change TAB character to Space charter
 *
 *    Rev 1.3   03 Mar 2002 23:06:30   mtk00240
 * L1D add code to setup APC DC offset
 * Resolution for 305: L1D add code to setup APC DC offset
 *
 *    Rev 1.2   08 Jan 2002 17:10:54   mtk00240
 * Change TQ_BULON, TQ_BULOFF, TQ_BDLON.
 * Let IQ Swap can be change on running time.
 * Resolution for 203: Modify some RF parameters in L1D
 *
 *    Rev 1.1   03 Jan 2002 12:19:46   mtk00240
 * Merge B.L1.20011225 to Main V1.XX
 *
 *    Rev 1.0   Dec 25 2001 14:40:22   admin
 * Initial revision.
 *
 *******************************************************************************/

#ifndef  _L1D_RF_L1CORE_H_
#define  _L1D_RF_L1CORE_H_

#include "l1d_rf_common.h"

/* ------------------------------------------------------------------------- */
/*==========================*/  /*========================*/
/* BBRX_GAIN_DOUBLE         */  /* BBTX_CALBIAS           */
/*--------------------------*/  /*------------------------*/
/* 0: mapping range = 2.24V */  /* N= 0..+15 : 1.038^N    */
/* 1: mapping range = 1.12V */  /* N=-1..-16 : 0.918^(-N) */
/*==========================*/  /*========================*/
/*==========================*/  /*========================*/
/* BBTX_COMMON_MODE_VOLTAGE */  /* BBTX_CALRCSEL          */
/*--------------------------*/  /*------------------------*/
/* Set | Volt || Set | Volt */  /* Set | BW  || Set | BW  */
/*-----+------||-----+------*/  /*-----+-----||-----+-----*/
/*  3  | 1.75 || -1  | 1.29 */  /*  3  | 213 || -1  | 394 */
/*  2  | 1.62 || -2  | 1.18 */  /*  2  | 245 || -2  | 450 */
/*  1  | 1.51 || -3  | 1.06 */  /*  1  | 289 || -3  | 520 */
/*  0  | 1.40 || -4  | 0.95 */  /*  0  | 350 || -4  | 620 */
/*==========================*/  /*========================*/
/*==========================*/  /*========================*/
/* BBTX_TRIM_I              */  /* BBTX_OFFSET_I          */
/* BBTX_TRIM_Q              */  /* BBTX_OFFSET_Q          */
/*--------------------------*/  /*------------------------*/
/* N= -8...+7 : 0.16N dB    */  /* N=-32...+31: 2.737N mV */
/*==========================*/  /*========================*/
/*========================================================*/
/* BBTX_GAIN                                              */
/* --+---------+---------------+------------+-------------*/
/* S | FPGA    |               |            |             */
/* e | MT6208  | MT6205B       | MT6218B_EN | MT6218B_FN~ */
/* t | MT6205A | MT6218B_AN~DN | MT6219AV   | MT6219_BV   */
/*   | MT6218A |               |            |             */
/*---+---------+---------------+------------+-------------*/
/* 3 |  2.52V  |     1.48V     |   0.93V    |   1.50V     */
/* 2 |  2.01V  |     1.37V     |   0.87V    |   1.42V     */
/* 1 |  1.62V  |     1.29V     |   0.81V    |   1.36V     */
/* 0 |  1.26V  |     1.15V     |   0.76V    |   1.19V     */
/*-1 |  1.00V  |     1.06V     |   0.71V    |   1.12V     */
/*-2 |  0.81V  |     1.00V     |   0.66V    |   1.05V     */
/*-3 |  0.64V  |     0.92V     |   0.62V    |   1.00V     */
/*-4 |  0.50V  |     0.87V     |   0.58V    |   0.93V     */
/*========================================================*/
/* ------------------------------------------------------------------------- */
#define  CLK32K_MICRO_SECOND(n)       ((int)(n*32.0/1000))
/* ------------------------------------------------------------------------- */

#if IS_RF_MT6280RF
/*MT6280RF*/
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/ #define  SX0_DATA_COUNT               0
/*MT6280RF*/ #define  SX1_DATA_COUNT              11
/*MT6280RF*/ #define  SX2_DATA_COUNT               4
/*MT6280RF*/ #define  SX3_DATA_COUNT               3
/*MT6280RF*/ #define  ST2B_ST2M_DATA_COUNT         4
/*MT6280RF*/ #else
/*MT6280RF*/ #define  SX0_DATA_COUNT               0
/*MT6280RF*/ #define  SX1_DATA_COUNT              11
/*MT6280RF*/ #define  SX2_DATA_COUNT               4
/*MT6280RF*/ #define  SX3_DATA_COUNT               3
/*MT6280RF*/ #define  ST2B_ST2M_DATA_COUNT         4
/*MT6280RF*/ #endif
/*MT6280RF*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SDATA_IDLE                   BSI_CW(0x01, 0x00200)
/*MT6280RF*/
/*MT6280RF*/ /* polarity:  0: long  enable positive pulse */
/*MT6280RF*/ /*            1: short enable positive pulse */
/*MT6280RF*/ /*            2: long  enable negative pulse */
/*MT6280RF*/ /*            3: short enable negative pulse */
/*MT6280RF*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6280RF*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6280RF*/
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ /*   Sleep Mode Setting                                   */
/*MT6280RF*/ /*-------------------------------------------------------*/
/*MT6280RF*/
/*MT6280RF*/ #define  FM_DURATION_DEFAULT          8191
/*MT6280RF*/ #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
/*MT6280RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(2000)
/*MT6280RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6280RF*/ #else
/*MT6280RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*MT6280RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ /*   BFE Setting                                          */
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ #define  BBRX_IQ_SWAP                 0
/*MT6280RF*/
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ /*   Define the CapID range                               */
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6280RF*/
/*MT6280RF*/ /*----------------------------------------------*/
/*MT6280RF*/ /*   Define Q-path on/off                       */
/*MT6280RF*/ /*----------------------------------------------*/
/*MT6280RF*/ #ifndef IS_Q_PATH_ON
/*MT6280RF*/ #define IS_Q_PATH_ON                    0
/*MT6280RF*/ #endif
#endif

/*============================================================================== */

#if IS_RF_MT6169
/*MT6169*/
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/
/*MT6169*/ #define  SX0_DATA_COUNT               0
/*MT6169*/ #define  SX1_DATA_COUNT               14
/*MT6169*/ #define  SX2_DATA_COUNT               5
/*MT6169*/ #define  SX3_DATA_COUNT               4
/*MT6169*/ #define  ST2B_ST2M_DATA_COUNT         5
/*MT6169*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,30)
/*MT6169*/ #define  SDATA_IDLE                   BSI_CW(0x01, 0x00040) //Should keep DYN_EN = 1
/*MT6169*/
/*MT6169*/ /* polarity:  0: long  enable positive pulse */
/*MT6169*/ /*            1: short enable positive pulse */
/*MT6169*/ /*            2: long  enable negative pulse */
/*MT6169*/ /*            3: short enable negative pulse */
/*MT6169*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6169*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6169*/
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ /*   Sleep Mode Setting                                   */
/*MT6169*/ /*-------------------------------------------------------*/
/*MT6169*/
/*MT6169*/ #define  FM_DURATION_DEFAULT          8191
/*MT6169*/ #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
/*MT6169*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(2063)//2ms
/*MT6169*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6169*/ #else
/*MT6169*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(3094)//3ms
/*MT6169*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6169*/ #endif
/*MT6169*/
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ /*   BFE Setting                                          */
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ #define  BBRX_IQ_SWAP                 0
/*MT6169*/ #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT_V2
/*MT6169*/ #define  TQ_EPSK_TX_DELAY             1
/*MT6169*/ #endif
/*MT6169*/
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ /*   Define the CapID range                               */
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6169*/
#endif

/*============================================================================== */

#if IS_RF_MT6166
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/
/*MT6166*/ #define  SX0_DATA_COUNT               0
/*MT6166*/ #define  SX1_DATA_COUNT               9
/*MT6166*/ #define  SX2_DATA_COUNT               4
/*MT6166*/ #define  SX3_DATA_COUNT               1
/*MT6166*/ #define  ST2B_ST2M_DATA_COUNT         4
/*MT6166*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,30)
/*MT6166*/ #define  SDATA_IDLE                   BSI_CW(0xC9, 0x00200)
/*MT6166*/
/*MT6166*/ /* polarity:  0: long  enable positive pulse */
/*MT6166*/ /*            1: short enable positive pulse */
/*MT6166*/ /*            2: long  enable negative pulse */
/*MT6166*/ /*            3: short enable negative pulse */
/*MT6166*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6166*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   Sleep Mode Setting                                   */
/*MT6166*/ /*-------------------------------------------------------*/
/*MT6166*/
/*MT6166*/ #define  FM_DURATION_DEFAULT          8191
/*MT6166*/ #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
/*MT6166*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(2063)//2ms
/*MT6166*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6166*/ #else
/*MT6166*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(3094)//3ms
/*MT6166*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   BFE Setting                                          */
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ #define  BBRX_IQ_SWAP                 0
/*MT6166*/ #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT_V2
/*MT6166*/ #define  TQ_EPSK_TX_DELAY             1
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   Define the CapID range                               */
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6166*/
#endif

/*============================================================================== */

#if IS_RF_MT6165
/*MT6165*/
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/
/*MT6165*/ #define  SX0_DATA_COUNT               0
/*MT6165*/ #define  SX1_DATA_COUNT               13
/*MT6165*/ #define  SX2_DATA_COUNT               3
/*MT6165*/ #define  SX3_DATA_COUNT               1
/*MT6165*/ #define  ST2B_ST2M_DATA_COUNT         3
/*MT6165*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,30)
/*MT6165*/ #define  SDATA_IDLE                   BSI_CW(0x01, 0x04000)
/*MT6165*/
/*MT6165*/ /* polarity:  0: long  enable positive pulse */
/*MT6165*/ /*            1: short enable positive pulse */
/*MT6165*/ /*            2: long  enable negative pulse */
/*MT6165*/ /*            3: short enable negative pulse */
/*MT6165*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6165*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6165*/
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ /*   Sleep Mode Setting                                   */
/*MT6165*/ /*-------------------------------------------------------*/
/*MT6165*/
/*MT6165*/ #define  FM_DURATION_DEFAULT          8191
/*MT6165*/ #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
/*MT6165*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(2063)//2ms
/*MT6165*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6165*/ #else
/*MT6165*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(3094)//3ms
/*MT6165*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ /*   BFE Setting                                          */
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ #define  BBRX_IQ_SWAP                 0
/*MT6165*/ #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT_V2
/*MT6165*/ #define  TQ_EPSK_TX_DELAY             1
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ /*   Define the CapID range                               */
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6165*/
#endif

/*============================================================================== */

#if IS_RF_MT6176
/*MT6176*/
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/
/*MT6176*/ #define  SX0_DATA_COUNT               0
/*MT6176*/ #define  SX1_DATA_COUNT               27
/*MT6176*/ #define  SX2_DATA_COUNT               5
/*MT6176*/ #define  SX3_DATA_COUNT               5
/*MT6176*/ #define  ST2B_ST2M_DATA_COUNT         5
/*MT6176*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,0) //BSI Length should be 32bits for MT6176, and length setting move to TOPBSI, so set 0 here.
/*MT6176*/ #define  SDATA_IDLE                   BSI_CW(0x001, 0x10220 ) //Mode[3:0]=1 for sleep mode
/*MT6176*/
/*MT6176*/ /* polarity:  0: long  enable positive pulse */
/*MT6176*/ /*            1: short enable positive pulse */
/*MT6176*/ /*            2: long  enable negative pulse */
/*MT6176*/ /*            3: short enable negative pulse */
/*MT6176*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6176*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6176*/
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ /*   BFE Setting                                          */
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ #define  BBRX_IQ_SWAP                 1
/*MT6176*/
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ /*   Define the CapID range                               */
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6176*/
#endif

/*============================================================================== */

#ifdef L1_SIM
#undef   CLK_SETTLE_DEFAULT
#undef   PLL_RESET_DEFAULT
#define  CLK_SETTLE_DEFAULT            CLK32K_MICRO_SECOND(3125)
#define  PLL_RESET_DEFAULT             CLK32K_MICRO_SECOND(3000)
#endif

#if defined(FPGA) || defined(MT6208) || defined(MT6205) || defined(MT6205B)
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -83.25
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -77.25
   #endif
#elif defined(MT6218)
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -99.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -93.75
   #endif
#elif IS_CHIP_MT6229_FPGA2
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -97.25
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -91.25
   #endif
#elif IS_BBTXRX_CHIP_DESIGN_VER_2
#define  DSP_MAGIC_VALUE               -94.25
#elif IS_BBTXRX_CHIP_DESIGN_VER_3
#define  DSP_MAGIC_VALUE               -114.75
#elif IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6280
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -118.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -118.75
   #endif
#elif IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2 || IS_CHIP_TK6291 || IS_CHIP_MT6755
#define  DSP_MAGIC_VALUE               -120.79
#elif IS_CHIP_MT6583_MD1
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -120.79
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -120.79
   #endif
#elif IS_CHIP_MT6251
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -118.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -118.75
   #endif
#elif IS_CHIP_MT6250
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -117.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -117.75
   #endif
#elif IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -97.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -91.75
   #endif
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION || IS_CHIP_MT6225_AND_LATTER_VERSION
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -99.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -93.75
   #endif
#else
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -97.25
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -91.25
   #endif
#endif


#ifndef  SX0_DATA_COUNT
#define  SX0_DATA_COUNT                0
#endif
#ifndef  ST2B_ST2M_DATA_COUNT
   #if IS_BSI_V2_SUPPORT
#define  ST2B_ST2M_DATA_COUNT          SX2_DATA_COUNT
   #else
#define  ST2B_ST2M_DATA_COUNT          0
   #endif
#endif

#ifndef  IS_BSI_DATA_TABLE_Y_SHIFT
#define  IS_BSI_DATA_TABLE_Y_SHIFT     0
#endif


#ifndef  IS_BT_COCLOCK_SUPPORT
#define  IS_BT_COCLOCK_SUPPORT         0
#endif

#ifndef  IS_HW_DISABLE_EPSK_TX_SUPPORT
#define  IS_HW_DISABLE_EPSK_TX_SUPPORT 0
#endif

#ifndef  IS_AUXADC_CLOSED_LOOP_TXPC_ON
#define  IS_AUXADC_CLOSED_LOOP_TXPC_ON 0
#endif

#ifndef  IS_BSI_CLOSED_LOOP_TXPC_ON
#define  IS_BSI_CLOSED_LOOP_TXPC_ON    0
#endif

#ifndef  CRYSTAL_CAPID_RANGE
#define  CRYSTAL_CAPID_RANGE           63
#endif

#if IS_CHIP_MT6583_MD2
/* for MT6168 VRF28 Setting */
   #ifndef VRF28_SOURCE
#define VRF28_SOURCE                   1    /* VRF28_SOURCE: 0(VRF28_1) or 1(VRF28_2) */
   #endif
#endif

/* for the DCS-TD co-existence support */
#ifndef  IS_DCS_NB_WB_SWITCH_ON
#define  IS_DCS_NB_WB_SWITCH_ON        0
#endif

#ifndef  DCS_NB_PATH_SEL
#define  DCS_NB_PATH_SEL               DCS_PATH_SEL
#endif

#ifndef  PDATA_DCS_NB_PR1
#define  PDATA_DCS_NB_PR1              PDATA_DCS_PR1
#endif

#ifndef  PDATA_DCS_NB_PR2
#define  PDATA_DCS_NB_PR2              PDATA_DCS_PR2
#endif

#ifndef  PDATA_DCS_NB_PR3
#define  PDATA_DCS_NB_PR3              PDATA_DCS_PR3
#endif

#ifndef  PDATA_DCS_NB_PR3A
#define  PDATA_DCS_NB_PR3A             PDATA_DCS_NB_PR3
#endif

#ifndef  PDATA_DCS_NB_PR2B
#define  PDATA_DCS_NB_PR2B             PDATA_DCS_NB_PR2
#endif

#ifndef  PDATA_DCS_NB_PR2M1
   #if defined(QB_PR2B) && QB_PR2B<QB_PR2
#define  PDATA_DCS_NB_PR2M1            PDATA_DCS_NB_PR2B
   #else
#define  PDATA_DCS_NB_PR2M1            PDATA_DCS_NB_PR2
   #endif
#endif

#ifndef  PDATA_DCS_NB_PR2M2
#define  PDATA_DCS_NB_PR2M2            PDATA_DCS_NB_PR2M1
#endif

#ifndef  PDATA_DCS_NB_PR2M3
#define  PDATA_DCS_NB_PR2M3            PDATA_DCS_NB_PR2M2
#endif

#if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
   #ifndef  PDATA_DCS_NOTCH_PT1
#define  PDATA_DCS_NOTCH_PT1           PDATA_DCS_PT1
   #endif

   #ifndef  PDATA_DCS_NOTCH_PT2
#define  PDATA_DCS_NOTCH_PT2           PDATA_DCS_PT2
   #endif

   #ifndef  PDATA_DCS_NOTCH_PT3
#define  PDATA_DCS_NOTCH_PT3           PDATA_DCS_PT3
   #endif

   #ifndef  PDATA_DCS_NOTCH_PT3A
#define  PDATA_DCS_NOTCH_PT3A          PDATA_DCS_PT3
   #endif

   #ifndef  PDATA_DCS_NOTCH_PT2B
#define  PDATA_DCS_NOTCH_PT2B          PDATA_DCS_PT2
   #endif

   #ifndef  PDATA_DCS_NOTCH_PT2M1_8G
      #if defined(QB_PT2B) && QB_PT2B<QB_PT2
#define  PDATA_DCS_NOTCH_PT2M1_8G      PDATA_DCS_PT2B
      #else
#define  PDATA_DCS_NOTCH_PT2M1_8G      PDATA_DCS_PT2
      #endif
   #endif
   #ifndef  PDATA_DCS_PT2M1_G8
      #if defined(QB_PT2B) && QB_PT2B<QB_PT2
#define  PDATA_DCS_NOTCH_PT2M1_G8      PDATA_DCS_PT2B
      #else
#define  PDATA_DCS_NOTCH_PT2M1_G8      PDATA_DCS_PT2
      #endif
   #endif
   #ifndef  PDATA_DCS_NOTCH_PT2M2_8G
#define  PDATA_DCS_NOTCH_PT2M2_8G      PDATA_DCS_PT2M1_8G
   #endif
   #ifndef  PDATA_DCS_NOTCH_PT2M2_G8
#define  PDATA_DCS_NOTCH_PT2M2_G8      PDATA_DCS_PT2M1_G8
   #endif
   #ifndef  PDATA_DCS_NOTCH_PT2M3_8G
#define  PDATA_DCS_NOTCH_PT2M3_8G      PDATA_DCS_PT2M2_8G
   #endif
   #ifndef  PDATA_DCS_NOTCH_PT2M3_G8
#define  PDATA_DCS_NOTCH_PT2M3_G8      PDATA_DCS_PT2M2_G8
   #endif
#endif
/*============================================================================== */

#if IS_CC_NVRAM_CUSTOM_DATA_SUPPORT
/* the following define moved to L1D_RF_Custom_Timing_Table_Update  for tk6291 cross-core modification */
#else
#define  TQ_SR0                        0//(QB_SR0-QB_RON_2_FSYNC)
#define  TQ_SR1                        0//(QB_SR1-QB_RON_2_FSYNC)
#define  TQ_SR2                        0//(QB_SR2-QB_RON_2_FSYNC)
#define  TQ_SR2M                       0//(QB_SR2M-QB_RON_2_FSYNC)
#define  TQ_SR3                        0//(QB_SR3-QB_FSYNC_2_ROFF)
#define  TQ_PR1                        0//(QB_PR1-QB_RON_2_FSYNC)
#define  TQ_PR2                        0//(QB_PR2-QB_RON_2_FSYNC)
#define  TQ_PR2M1                      0//(QB_PR2M1-QB_RON_2_FSYNC)
#define  TQ_PR2M2                      0//(QB_PR2M2-QB_RON_2_FSYNC)
#define  TQ_PR3                        0//(QB_PR3-QB_FSYNC_2_ROFF)
#define  TQ_PR3A                       0//(QB_PR3A-QB_FSYNC_2_ROFF)

#define  TQ_ST0                        0//(QB_ST0-QB_TON_2_FSYNC)
#define  TQ_ST1                        0//(QB_ST1-QB_TON_2_FSYNC)
#define  TQ_ST2                        0//(QB_ST2-QB_TON_2_FSYNC)
#define  TQ_ST3                        0//(QB_ST3-QB_FSYNC_2_TOFF)
#define  TQ_PT1                        0//(QB_PT1-QB_TON_2_FSYNC)
#define  TQ_PT2                        0//(QB_PT2-QB_TON_2_FSYNC)
#define  TQ_PT2B                       0//(QB_PT2B-QB_TON_2_FSYNC)
#define  TQ_PT3                        0//(QB_PT3-QB_FSYNC_2_TOFF)
#define  TQ_PT3A                       0//(QB_PT3A-QB_FSYNC_2_TOFF)
#define  TQ_APCON                      0//(QB_APCON-QB_TON_2_FSYNC)
#define  TQ_APCMID                     0//(QB_APCMID-QB_TON_2_FSYNC)
#define  TQ_APCOFF                     0//(QB_APCOFF-QB_FSYNC_2_TOFF)
#define  TQ_BDLON                      0//(QB_RX_FENA_2_FSYNC-QB_RON_2_FSYNC+QB_RX_ADEN_2_FENA)
#define  TQ_BDLOFF                     0//(-QB_FSYNC_2_ROFF)
#define  TQ_BULON                      0//(QB_TX_FENA_2_FSYNC-QB_TON_2_FSYNC+QB_TX_DAEN_2_FENA)
#define  TQ_BULOFF                     0//(-QB_FSYNC_2_TOFF)
#define  TQ_AFC2_2_BOFF                0//(TQ_BULOFF+QB_TX_FSYNC_2_FENA)

#define  TQ_PR2B                       0//(QB_PR2B-QB_RON_2_FSYNC)
#define  TQ_PT2M1_G8                   0//(QB_PT2M1_G8-QB_TON_2_FSYNC)
#define  TQ_PT2M2_G8                   0//(QB_PT2M2_G8-QB_TON_2_FSYNC)
#define  TQ_PT2M3_G8                   0//(QB_PT2M3_G8-QB_TON_2_FSYNC)
#define  TQ_PT2M1_8G                   0//(QB_PT2M1_8G-QB_TON_2_FSYNC)
#define  TQ_PT2M2_8G                   0//(QB_PT2M2_8G-QB_TON_2_FSYNC)
#define  TQ_PT2M3_8G                   0//(QB_PT2M3_8G-QB_TON_2_FSYNC)
#define  TQ_ST2B                       0//(QB_ST2B-QB_TON_2_FSYNC)
#define  TQ_ST2M_G8                    0//(QB_ST2M_G8-QB_TON_2_FSYNC)
#define  TQ_ST2M_8G                    0//(QB_ST2M_8G-QB_TON_2_FSYNC)
#endif
/*--------------------------------------------------------*/
/*   define BDL/BUL data (shall be modified by real case) */
/*--------------------------------------------------------*/

#if IS_TDMA_AD_DA_WINDOW_SUPPORT
#define  BDLCON_DATA                   ( ((QB_RX_ADEN_2_FENA+QB_RX_FENA_2_FSYNC-1)<<8) | ((QB_RX_FSYNC_2_FENA+QB_RX_FENA_2_ADEN)<<0) )
#define  BDLCON2_DATA                  ( ((QB_RX_ADEN_2_FENA                   -1)<<8) | ((QB_RX_FSYNC_2_FENA                  )<<0) )
#define  BULCON1_DATA                  ( ((QB_TX_DAEN_2_FENA+QB_TX_FENA_2_FSYNC-1)<<8) | ((QB_TX_FSYNC_2_FENA+QB_TX_FENA_2_DAEN)<<0) )
   #if IS_CC_NVRAM_CUSTOM_DATA_SUPPORT
/* the following define moved to L1D_RF_Custom_Timing_Table_Update bulcon2_data for tk6291 cross-core modification */
   #else
      #if IS_BBTXRX_CHIP_DESIGN_VER_3
/* BFE_TXCOMP_HYS[15:8] in BULCON2 is moved to TX_CNT_TGT[7:0] in TX_CON1 */
#define  BULCON2_DATA                  (                                                 ((QB_TX_DAEN_2_FENA+QB_TX_FENA_2_FSYNC-QB_APCDACON)&0x0FF) )
      #else
#define  BULCON2_DATA                  ( ((QB_BFE_TXCOMP_HYS                     )<<8) | ((QB_TX_DAEN_2_FENA+QB_TX_FENA_2_FSYNC-QB_APCDACON)&0x0FF) )
      #endif
   #endif
#define  BULCON3_DATA                  ( ((QB_TX_DAEN_2_FENA                   -1)<<8) | ((QB_TX_FSYNC_2_FENA                  )<<0) )
#else
#define  BDLCON_DATA                   ( ((                  QB_RX_FENA_2_FSYNC-1)<<8) | ((QB_RX_FSYNC_2_FENA                  )<<0) )
#define  BULCON1_DATA                  ( ((                  QB_TX_FENA_2_FSYNC-1)<<8) | ((QB_TX_FSYNC_2_FENA                  )<<0) )
   #if IS_CC_NVRAM_CUSTOM_DATA_SUPPORT
/* the following define moved to L1D_RF_Custom_Timing_Table_Update bulcon2_data for tk6291 cross-core modification */
   #else
#define  BULCON2_DATA                  ( ((QB_BFE_TXCOMP_HYS                     )<<8) | ((QB_TX_FENA_2_FSYNC-QB_APCDACON)&0x0FF) )
   #endif
#endif

/*---------------------------------------------------------------------------*/
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2 || IS_CHIP_TK6291 || IS_CHIP_MT6755
      #if IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165 || IS_RF_MT6176 || IS_COSIM_ON_L1SIM_SUPPORT
#define BSI_CLK_SPD                    0
      #else
#error
      #endif
   #elif IS_CHIP_MT6572
   /*  0 -->61.44/ 1=61.44  MHz   */
   /*  1 -->61.44/ 2=30.72  MHz   */
   /*  2 -->61.44/ 3=20.48  MHz   */
   /*  3 -->61.44/ 4=15.36  MHz   */
   /*  4 -->61.44/ 6=10.24  MHz   */
   /*  5 -->61.44/ 8= 7.68  MHz   */
   /*  6 -->61.44/12= 5.12  MHz   */
   /*  7 -->61.44/16= 3.84  MHz   */
      #if IS_RF_MT6166 || IS_COSIM_ON_L1SIM_SUPPORT
#define BSI_CLK_SPD                    0
      #else
#error
      #endif
   #elif IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
   /*  0 -->122.88/ 2=61.44  MHz   */
   /*  1 -->122.88/ 4=30.72  MHz   */
   /*  2 -->122.88/ 6=20.48  MHz   */
   /*  3 -->122.88/ 8=15.36  MHz   */
   /*  4 -->122.88/12=10.24  MHz   */
   /*  5 -->122.88/16= 7.68  MHz   */
   /*  6 -->122.88/24= 5.12  MHz   */
   /*  7 -->122.88/32= 3.84  MHz   */
      #if IS_RF_MT6167
#define BSI_CLK_SPD                    0
      #elif IS_RF_MT6163
#define BSI_CLK_SPD                    0
      #elif IS_COSIM_ON_L1SIM_SUPPORT
#define BSI_CLK_SPD                    0
      #else
#error
      #endif
   #elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6280
      #if IS_CHIP_MT6268T_DMAC
   /*  0 --> 30.72/ 2=15.36  MHz   */
   /*  1 --> 30.72/ 4= 7.68  MHz   */
   /*  2 --> 30.72/ 6= 5.12  MHz   */
   /*  3 --> 30.72/ 8= 3.84  MHz   */
   /*  4 --> 30.72/12= 2.56  MHz   */
   /*  5 --> 30.72/16= 1.92  MHz   */
   /*  6 --> 30.72/24= 1.28  MHz   */
   /*  7 --> 30.72/32= 0.96  MHz   */
#define BSI_CLK_SPD                    1
      #else
   /*  0 -->122.88/ 2=61.44  MHz   */
   /*  1 -->122.88/ 4=30.72  MHz   */
   /*  2 -->122.88/ 6=20.48  MHz   */
   /*  3 -->122.88/ 8=15.36  MHz   */
   /*  4 -->122.88/12=10.24  MHz   */
   /*  5 -->122.88/16= 7.68  MHz   */
   /*  6 -->122.88/24= 5.12  MHz   */
   /*  7 -->122.88/32= 3.84  MHz   */
         #if IS_RF_MT6162 || IS_RF_MT6163 || IS_RF_MT6280RF
#define BSI_CLK_SPD                    0
         #else
#define BSI_CLK_SPD                    5
         #endif
      #endif
   #elif IS_CHIP_MT6268
      #if IS_CHIP_MT6268A// MT6268A DCM hardware bug, raise the BSI clock
   /*  0 --> 30.72/2 =15.36  MHz   */
   /*  1 --> 30.72/4 = 7.68  MHz   */
   /*  2 --> 30.72/6 = 5.12  MHz   */
   /*  3 --> 30.72/8 = 3.84  MHz   */
#define BSI_CLK_SPD                    0
      #else
   /*  0 --> 30.72/2 =15.36  MHz   */
   /*  1 --> 30.72/4 = 7.68  MHz   */
   /*  2 --> 30.72/6 = 5.12  MHz   */
   /*  3 --> 30.72/8 = 3.84  MHz   */
#define BSI_CLK_SPD                    1
      #endif
   #elif IS_CHIP_MT6268T
   /*  0 --> 30.72/2 =15.36  MHz   */
   /*  1 --> 30.72/4 = 7.68  MHz   */
   /*  2 --> 30.72/6 = 5.12  MHz   */
   /*  3 --> 30.72/8 = 3.84  MHz   */
#define BSI_CLK_SPD                    1
   #elif IS_CHIP_MT6256 || IS_CHIP_MT6255
   /*  0 --> 52/2    =26     MHz   */
   /*  1 --> 52/4    =13     MHz   */
   /*  2 --> 52/6    = 8.67  MHz   */
   /*  3 --> 52/8    = 6.5   MHz   */
#define BSI_CLK_SPD                    0
   #elif IS_CHIP_MT6250
   /*  0 --> 130/ 2  =65     MHz   */
   /*  1 --> 130/ 4  =32.5   MHz   */
   /*  2 --> 130/ 6  =21.67  MHz   */
   /*  3 --> 130/ 8  =16.25  MHz   */
   /*  4 --> 130/12  =10.83  MHz   */
   /*  5 --> 130/16  = 8.13  MHz   */
   /*  6 --> 130/24  = 5.42  MHz   */
   /*  7 --> 130/32  = 4.06  MHz   */
#define BSI_CLK_SPD                    0
   #elif IS_CHIP_MT6251
   /*  0 --> 52/2    =26     MHz   */
   /*  1 --> 52/4    =13     MHz   */
   /*  2 --> 52/6    = 8.67  MHz   */
   /*  3 --> 52/8    = 6.5   MHz   */
#define BSI_CLK_SPD                    1
   #elif IS_CHIP_MT6252_S00
   /*  0 --> 52/2    =26     MHz   */
   /*  1 --> 52/4    =13     MHz   */
   /*  2 --> 52/6    = 8.67  MHz   */
   /*  3 --> 52/8    = 6.5   MHz   */
#define BSI_CLK_SPD                    3
   #elif IS_CHIP_MT6252
   /*  0 --> 52/2    =26     MHz   */
   /*  1 --> 52/4    =13     MHz   */
   /*  2 --> 52/6    = 8.67  MHz   */
   /*  3 --> 52/8    = 6.5   MHz   */
#define BSI_CLK_SPD                    0
   #elif IS_CHIP_MT6229_S01 || IS_CHIP_MT6229_S00 || IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
   /*  0 --> 52/2    =26     MHz   */
   /*  1 --> 52/4    =13     MHz   */
   /*  2 --> 52/6    = 8.67  MHz   */
   /*  3 --> 52/8    = 6.5   MHz   */
#define BSI_CLK_SPD                    3
   #else
   /*  0 --> 26/2    =13     MHz   */
   /*  1 --> 26/4    = 6.5   MHz   */
   /*  2 --> 26/6    = 4.33  MHz   */
   /*  3 --> 26/8    = 3.25  MHz   */
#define BSI_CLK_SPD                    1
   #endif
#else
   /*  0 --> 13/2    = 6.5   MHz   */
   /*  1 --> 13/4    = 3.25  MHz   */
   /*  2 --> 13/6    = 2.167 MHz   */
   /*  3 --> 13/8    = 1.625 MHz   */
#define BSI_CLK_SPD                    0
#endif

#if IS_CHIP_MT6250
#define  BSI_ENA_LEN       0
#define  BSI_ENA_POL       0
#define  SCTRL_IMOD_MAIN   (0x0001| ((BSI_CLK_SPD&0x7)<<2)|(BSI_ENA_LEN<<16)|(BSI_ENA_POL<<18)) /* SRCB main control:SRCB TSU event trigger */
#define  SCTRL_IMOD_SEND   (0x0401| ((BSI_CLK_SPD&0x7)<<2)|(BSI_ENA_LEN<<16)|(BSI_ENA_POL<<18)) /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        SCTRL_IMOD_MAIN
#elif IS_CHIP_MT6583_MD2
/* only one port is in MT6583 MD2 */
#define  BSI_PORTA_SELECT  (BSI_PORT_SELECT==0)
#define  BSI_CS0_SELECT    (BSI_CS_SELECT  ==0)
#define  BSI_CS1_SELECT    (BSI_CS_SELECT  ==1)
#define  BSI_DEVICE_A_0_CS (((BSI_PORTA_SELECT&BSI_CS0_SELECT)<<3)|((BSI_DEVICE_0_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_0_CS_POLARITY&0x1))
#define  BSI_DEVICE_A_1_CS (((BSI_PORTA_SELECT&BSI_CS1_SELECT)<<3)|((BSI_DEVICE_1_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_1_CS_POLARITY&0x1))
#define  SCTRL_IMOD_MAIN   ((BSI_CLK_POL)|((BSI_CLK_SPD&0x7)<<2)|(0x0<<10)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20))               /* SRCB main control:SRCB TSU event trigger */
#define  SCTRL_IMOD_SEND   ((BSI_CLK_POL)|((BSI_CLK_SPD&0x7)<<2)|(0x1<<10)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20))               /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        SCTRL_IMOD_MAIN
#elif IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2 || IS_CHIP_TK6291 || IS_CHIP_MT6755
#define  SCTRL_IMOD_MAIN   (0x0<<10)
#define  SCTRL_IMOD_SEND   (0x1<<10)
#define  SCTRL_MAIN        SCTRL_IMOD_MAIN
#define  BSI_DEVICE_A_0_CS (BSI_DEVICE_0_CS_POLARITY&0x7)
#define  BSI_A_IDLE_CNT    IDLE_CNT
#define  BSI_A_WLEN        29
#define  SCTRL_MAIN_A_SPI  ((BSI_CLK_POL)|((BSI_CLK_SPD&0x7)<<2)|(BSI_DEVICE_A_0_CS<<5)|((BSI_A_IDLE_CNT&0x1F)<<16)|((BSI_A_WLEN&0x1F)<<24))
#elif IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6572
#define  BSI_PORTA_SELECT  (BSI_PORT_SELECT==0)
#define  BSI_PORTB_SELECT  (BSI_PORT_SELECT==1)
#define  BSI_PORTC_SELECT  (BSI_PORT_SELECT==2)
#define  BSI_CS0_SELECT    (BSI_CS_SELECT  ==0)
#define  BSI_CS1_SELECT    (BSI_CS_SELECT  ==1)
#define  BSI_DEVICE_A_0_CS (((BSI_PORTA_SELECT&BSI_CS0_SELECT)<<3)|(BSI_DEVICE_0_CS_POLARITY&0x7))
#define  BSI_DEVICE_A_1_CS (((BSI_PORTA_SELECT&BSI_CS1_SELECT)<<3)|(BSI_DEVICE_1_CS_POLARITY&0x7))
#define  BSI_DEVICE_B_0_CS (((BSI_PORTB_SELECT&BSI_CS0_SELECT)<<3)|(BSI_DEVICE_0_CS_POLARITY&0x7))
#define  BSI_DEVICE_B_1_CS (((BSI_PORTB_SELECT&BSI_CS1_SELECT)<<3)|(BSI_DEVICE_1_CS_POLARITY&0x7))
#define  SCTRL_IMOD_MAIN   ((BSI_CLK_POL)|((BSI_CLK_SPD&0x7)<<2)|(0x0<<10)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20)|(BSI_DEVICE_B_0_CS<<24)|(BSI_DEVICE_B_1_CS<<28))               /* SRCB main control:SRCB TSU event trigger */
#define  SCTRL_IMOD_SEND   ((BSI_CLK_POL)|((BSI_CLK_SPD&0x7)<<2)|(0x1<<10)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20)|(BSI_DEVICE_B_0_CS<<24)|(BSI_DEVICE_B_1_CS<<28))               /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        SCTRL_IMOD_MAIN
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H
#define  BSI_PORTA_SELECT  ((~BSI_PORT_SELECT&0x1))
#define  BSI_PORTB_SELECT  (( BSI_PORT_SELECT&0x1))
#define  BSI_DEVICE_A_0_CS ((0x8*BSI_PORTA_SELECT)|((BSI_DEVICE_0_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_0_CS_POLARITY&0x1))
#define  BSI_DEVICE_A_1_CS ((0x0*BSI_PORTA_SELECT)|((BSI_DEVICE_1_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_1_CS_POLARITY&0x1))
#define  BSI_DEVICE_B_0_CS ((0x8*BSI_PORTB_SELECT)|((BSI_DEVICE_0_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_0_CS_POLARITY&0x1))
#define  BSI_DEVICE_B_1_CS ((0x0*BSI_PORTB_SELECT)|((BSI_DEVICE_1_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_1_CS_POLARITY&0x1))
#define  SCTRL_IMOD_MAIN   (0x0001| ((BSI_CLK_SPD&0x7)<<2)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20)|(BSI_DEVICE_B_0_CS<<24)|(BSI_DEVICE_B_1_CS<<28))                                /* SRCB main control:SRCB TSU event trigger */
#define  SCTRL_IMOD_SEND   (0x0401| ((BSI_CLK_SPD&0x7)<<2)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20)|(BSI_DEVICE_B_0_CS<<24)|(BSI_DEVICE_B_1_CS<<28))                                /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        SCTRL_IMOD_MAIN
#elif IS_CHIP_MT6268T || IS_CHIP_MT6268
#define  SCTRL_IMOD_MAIN   (0x0101| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6) |(BSI_DEVICE_0_CS_POLARITY<<12)|(BSI_DEVICE_1_CS_POLARITY<<14))    /* Wirte SDATA to active buffer for IMODE   */
#define  SCTRL_IMOD_SEND   (0x0009| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6) |(BSI_DEVICE_0_CS_POLARITY<<12)|(BSI_DEVICE_1_CS_POLARITY<<14))    /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        (0x0001| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6) |(BSI_DEVICE_0_CS_POLARITY<<12)|(BSI_DEVICE_1_CS_POLARITY<<14))    /* SRCB main control:SRCB TSU event trigger */
#else
#define  SCTRL_IMOD_MAIN   (0x0101| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6))    /* Wirte SDATA to active buffer for IMODE   */
#define  SCTRL_IMOD_SEND   (0x0009| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6))    /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        (0x0001| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6))    /* SRCB main control:SRCB TSU event trigger */
#endif

#if IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
   #if IS_CHIP_TK6291 || IS_CHIP_MT6755
#define  SCTRL_RESERVED                0x007A // the number of event is 120   
   #elif IS_CHIP_MT6256_S00
#define  SCTRL_RESERVED                0x0024
   #elif IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6250
#define  SCTRL_RESERVED                0x0015
   #elif IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define  SCTRL_RESERVED                0x0067 // the number of event is 103
   #elif IS_CHIP_MT6572
#define  SCTRL_RESERVED                0x0036 // the number of event is 54
   #elif IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
#define  SCTRL_RESERVED                0x002A // MT6270A E2, MT6276E2 is 42
   #else
#define  SCTRL_RESERVED                0x0024
   #endif
#elif IS_CHIP_MT6268H || IS_CHIP_MT6268T_DMAC
#define  SCTRL_RESERVED                0x0024
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
   #if IS_CHIP_MT6270A_E1 || IS_CHIP_MT6276_S00 || IS_CHIP_MT6573
#define  SCTRL_RESERVED                0x0024 // MT6270A E1, MT6276E1, MT6573E1 and MT6573E2 is 36
   #else
#define  SCTRL_RESERVED                0x002A // MT6270A E2, MT6276E2 is 42
   #endif
#elif IS_CHIP_MT6252
#define  SCTRL_RESERVED                0x0015
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  SCTRL_RESERVED                0x0014
#else
#define  SCTRL_RESERVED                0x0010
#endif

#if IS_CHIP_MT6252_S00
#define  IMM_BSI_WAIT_TIME_QB          16
#elif IS_CHIP_MT6280 || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165 || IS_RF_MT6176
#define  IMM_BSI_WAIT_TIME_QB          2
#elif IS_CHIP_MT6256 || IS_CHIP_MT6251 || IS_CHIP_MT6252 || IS_RF_MT6162 || IS_CHIP_MT6255 || IS_RF_MT6163 || IS_CHIP_MT6250
#define  IMM_BSI_WAIT_TIME_QB          6
#else
/*Maximum Safe Time: eg. 1 QB = 13/12, BSI_CLK = 13/6 => 1 QB = 2 BSI bit, 16 QB = 32 BSI bit */
#define  IMM_BSI_WAIT_TIME_QB          16
#endif

#if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2 || IS_CHIP_TK6291 || IS_CHIP_MT6755
#define  BSI_ACTUPT_ALL                0xC1FF
#elif IS_CHIP_MT6572
#define  BSI_ACTUPT_ALL                0xC0FF
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
#define  BSI_ACTUPT_ALL                0xC07F
#elif IS_CHIP_MT6250
#define  BSI_ACTUPT_ALL                0xC03F
#endif

/*---------------------------------------------------------------------------*/

#if !IS_RTX_5CWIN_SUPPORT // IS_GSM
/*GSM*/  #define  CWIN_COUNT           4
/*GSM*/  #define  RIDX_COUNT           5 // X0~3 for RX, X4 for TX
/*GSM*/  #define  YIDX_COUNT           0
#endif

#if IS_RTX_5CWIN_SUPPORT // IS_GPRS
/*GPRS*/ #define  CWIN_COUNT           5
   #if IS_BSI_V2_SUPPORT
/*GPRS*/ #define  RIDX_COUNT           6
/*GPRS*/ #define  YIDX_COUNT           0
   #else
/*GPRS*/ #define  RIDX_COUNT           6
/*GPRS*/ #define  YIDX_COUNT           4
   #endif

   #if IS_BSI_V2_ST2_SUPPORT
/*GPRS*/ #undef   RIDX_COUNT
/*GPRS*/ #define  RIDX_COUNT           7
   #endif
#endif

#if IS_BSI_SX0_SUPPORT
#define  CWIN_BSI_EVENT_COUNT          3
#define  SR1_EVENT_OFFSET              1
#else
#define  CWIN_BSI_EVENT_COUNT          2
#define  SR1_EVENT_OFFSET              0
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  ST2B_ST2M_EV0                 (CWIN_BSI_EVENT_COUNT*CWIN_COUNT+RIDX_COUNT)
#define  ST2B_2M_EV(n)                 (ST2B_ST2M_EV0+(n))
#endif

#if IS_BSI_V2_SUPPORT
#define  BSI_DATA_OFFSET               (SX2_DATA_COUNT*RIDX_COUNT)
#elif IS_BSI_DATA_TABLE_Y_SHIFT
#define  BSI_DATA_OFFSET               (ST2B_ST2M_DATA_COUNT*YIDX_COUNT)
#else
#define  BSI_DATA_OFFSET               0
#endif

#if IS_BSI_V2_SUPPORT
#define  AGCDT0                        0
#else
#define  AGCDT0                        ((SX0_DATA_COUNT+SX1_DATA_COUNT+SX3_DATA_COUNT)*CWIN_COUNT+BSI_DATA_OFFSET)
#endif
#define  AGCDTIDX(n)                   (AGCDT0+(n)*SX2_DATA_COUNT)

#if IS_BSI_DATA_TABLE_Y_SHIFT || IS_BSI_V2_SUPPORT
#define  ST2B_ST2M_0                   0
#else
#define  ST2B_ST2M_0                   (AGCDT0+SX2_DATA_COUNT*RIDX_COUNT)
#endif
#define  ST2B_ST2M_IDX(n)              (ST2B_ST2M_0+(n)*ST2B_ST2M_DATA_COUNT)

#if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2 || IS_CHIP_TK6291 || IS_CHIP_MT6755
//#define  BSI_PORT_SELECT_MASK        0x3  /* Support three ports            */
   #if IS_RF_MT6176
#define  BSI_PORT_SELECT               0  /* Device 0 is selected. (RFIC) */
#define  BSI_PORT_SELECT_PMIC          1  /* Device 1 is selected. (PMIC) */
   #elif IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165 || IS_COSIM_ON_L1SIM_SUPPORT
#define  BSI_PORT_SELECT               0  /* MT6169 and MT6166 uses port A             */
//#define  BSI_CS_SELECT                 0  /* MT6169 and MT6166 uses CS0                */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0

//Clock Gating SPI Setting
#define BSISPI_RFIC1_CG_OFFSET           0
#define BSISPI_RFIC2_CG_OFFSET           1
#define BSISPI_PMIC_CG_OFFSET            2
#define BSISPI_MIPI0_CG_OFFSET           3
#define BSISPI_MIPI1_CG_OFFSET           4
      #if IS_DUAL_TALK_SUPPORT
         #if IS_RF_MT6166 || IS_RF_MT6165      
#define BSISPI_CGON_PARAM                ((1<<BSISPI_MIPI1_CG_OFFSET)|(1<<BSISPI_MIPI0_CG_OFFSET)|(1<<BSISPI_PMIC_CG_OFFSET)|(0<<BSISPI_RFIC2_CG_OFFSET)|(1<<BSISPI_RFIC1_CG_OFFSET))
#define BSISPI_CGOFF_PARAM               ((1<<BSISPI_MIPI1_CG_OFFSET)|(1<<BSISPI_MIPI0_CG_OFFSET)|(1<<BSISPI_PMIC_CG_OFFSET)|(1<<BSISPI_RFIC2_CG_OFFSET)|(1<<BSISPI_RFIC1_CG_OFFSET))
         #endif
      #else
         #if IS_RF_MT6169
#define BSISPI_CGON_PARAM                ((0<<BSISPI_MIPI1_CG_OFFSET)|(0<<BSISPI_MIPI0_CG_OFFSET)|(1<<BSISPI_PMIC_CG_OFFSET)|(1<<BSISPI_RFIC2_CG_OFFSET)|(0<<BSISPI_RFIC1_CG_OFFSET))
#define BSISPI_CGOFF_PARAM               ((1<<BSISPI_MIPI1_CG_OFFSET)|(1<<BSISPI_MIPI0_CG_OFFSET)|(1<<BSISPI_PMIC_CG_OFFSET)|(1<<BSISPI_RFIC2_CG_OFFSET)|(1<<BSISPI_RFIC1_CG_OFFSET))
         #endif
      #endif
   #else
#error
   #endif
#elif IS_CHIP_MT6572
#define  BSI_PORT_SELECT_MASK        0x3  /* Support three ports            */
   #if IS_RF_MT6166 || IS_COSIM_ON_L1SIM_SUPPORT
#define  BSI_PORT_SELECT               0  /* MT6166 uses port A             */
#define  BSI_CS_SELECT                 0  /* MT6166 uses CS0                */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0
   #else
#error
   #endif
#elif IS_CHIP_MT6583_MD2
#define  BSI_PORT_SELECT_MASK        0x1  /* Support one port               */
   #if IS_RF_MT6163 || IS_COSIM_ON_L1SIM_SUPPORT
#define  BSI_PORT_SELECT               0  /* OT RF uses port A on MT6583    */
#define  BSI_CS_SELECT                 0  /* OT RF uses CS0                 */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0
   #else
#error
   #endif
#elif IS_CHIP_MT6583_MD1
#define  BSI_PORT_SELECT_MASK        0x3  /* Support three ports            */
   #if IS_RF_MT6167 || IS_COSIM_ON_L1SIM_SUPPORT
#define  BSI_PORT_SELECT               0  /* MT6167 uses port A             */
#define  BSI_CS_SELECT                 0  /* MT6167 uses CS0                */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0
   #else
#error
   #endif
#elif IS_CHIP_MT6280
#define  BSI_PORT_SELECT_MASK        0x3  /* Support three ports            */
#define  BSI_PORT_SELECT               0  /* MT6280 RF uses port A          */
#define  BSI_CS_SELECT                 0  /* MT6280 RF uses CS0             */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0
#elif IS_CHIP_MT6250
#define  IDLE_CNT                      0
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H
#define  BSI_PORT_SELECT_MASK        0x1  /* Support two ports              */
   #if IS_RF_MT6162 || IS_RF_MT6163
#define  BSI_PORT_SELECT               1  /* OH RF uses port B              */
#define  IDLE_CNT                      0
   #else
#define  BSI_PORT_SELECT               0  /* OE RF uses port A              */
#define  IDLE_CNT                      2
   #endif
#endif


#if IS_RF_MT6280RF
#define  AFC_SHIFT_PART                7
#define  AFC_MASK_PART                 (0x1FFF<<AFC_SHIFT_PART)
      #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
#define  AFC_VALUE_PART                0x0F70003C // CW247
      #else
#define  AFC_VALUE_PART                0x0FE00008 // CW254
      #endif
#define  AFC_CON_PART                  ((BSI_CS_SELECT<<15)|((29-1)<<8)|(BSI_PORT_SELECT<<6)|(BSI_CLK_SPD<<3)|(BSI_CLK_POL<<1)|(1))
#elif IS_RF_MT6169 || IS_RF_MT6166
#define  AFC_SHIFT_PART                7
#define  AFC_MASK_PART                 (0x1FFF<<AFC_SHIFT_PART)
      #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
#define  AFC_VALUE_PART                (POR_CW247 & 0x0F70007F) // CW247
      #else
#define  AFC_VALUE_PART                0x0FE00000 // CW254
      #endif
#elif IS_RF_MT6165
#define  AFC_SHIFT_PART                7
#define  AFC_MASK_PART                 (0x1FFF<<AFC_SHIFT_PART)
      #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
#define  AFC_VALUE_PART                (POR_CW247 & 0x0F70007F) // CW247
      #else
#error "MT6165 doesn't support AFC_VCXO_TYPE = VCTCXO"
      #endif
#define  AFC_CON_PART                  ((BSI_CS_SELECT<<15)|((30-1)<<8)|(BSI_PORT_SELECT<<6)|(BSI_CLK_SPD<<3)|(BSI_CLK_POL<<1)|(1)) //BSI Data for MT6167 is 30bit
#elif IS_RF_MT6176
#define  AFC_SHIFT_PART                7
#define  AFC_MASK_PART                 (0x1FFF<<AFC_SHIFT_PART)

//#define  AFC_VALUE_PART                0x0220007F // CW34
#define  AFC_VALUE_PART_VCXO           0x0220007F // CW34
#define  AFC_VALUE_PART_VCTCXO         0x02A00008 // CW42
#elif IS_RF_MT6162
#define  AFC_SHIFT_PART                0x0
#define  AFC_MASK_PART                 0x1FFF
#define  AFC_VALUE_PART                0xE100000
#define  AFC_CON_PART                  ((0<<15)|((30-1)<<8)|(BSI_PORT_SELECT<<7)|(BSI_CLK_SPD<<3)|(1<<1)|(1))
#endif

#if IS_GSM_BPI_MASK_NEEDED
   #if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define  BPI_MASK_VALUE                (1<<31) // bit[31] should be masked for 3G
   #elif IS_CHIP_MT6572
#define  BPI_MASK_VALUE                (1<<19) // bit[19] should be masked for 3G
   #else
#error "please check the mask bit for the other RAT!"
   #endif
#endif

/*---------------------------------------------------------------------------*/
#endif

