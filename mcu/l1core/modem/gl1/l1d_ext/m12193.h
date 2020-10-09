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
 *   m12193.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   AFC DAC and RX ADC configuration
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.26  $
 * $Modtime:   Jul 29 2005 13:45:52  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/m12193.h-arc  $
 *
 * 07 13 2015 yi-ying.lin
 * [MOLY00127539] [L1D][Modify] Check in the L1D co-TSX modification
 * 	.
 *
 * 02 10 2015 yi-ying.lin
 * [MOLY00095496] [L1D][Modify] TK6291 CC NVRAM and custom data modification L1D part
 * 	.
 *
 * 02 02 2015 ola.lee
 * [MOLY00091988] [L1D] Update MT6176 2G RF Driver
 *
 * 10 02 2013 ola.lee
 * [MOLY00039576] [MT6165] Merget MT6165 to MOLY for Dual Talk
 * 	.
 *
 * 08 14 2013 yi-ying.lin
 * [MOLY00028415] [82LTE.SMT.DEV] 6166/6169 2G calibration feature development
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
 * 11 01 2012 yi-ying.lin
 * [MOLY00005652] [L1D][Modify] Modify MT6280E2 CAPID and slope default value
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
 * 12 01 2011 sean.yang
 * removed!
 * .
 *
 * 11 17 2011 chang-kuan.lin
 * removed!
 * .
 *
 * 10 21 2011 th.yeh
 * removed!
 * .
 *
 * 08 10 2011 sean.yang
 * removed!
 * .
 *
 * 05 06 2011 sean.yang
 * removed!
 * .
 *
 * 12 21 2010 chang-kuan.lin
 * removed!
 * .
 *
 * 12 08 2010 chuwei.lo
 * removed!
 * .
 *
 * 11 24 2010 sean.yang
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
 * [L1D][Modify] Check in AD6546 RF Driver #if IS_RF_AD6546
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
 * Change default AFC slpoe from 3.2 to 7.0
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Change DSP setpoint from 42dBd to 47dBd in MT6223+MT6139E platform
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
 * Add RF driver of IRFS3001
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Modify the EDGE_SETPOINT_GAIN_OFFSET of SKY74137
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
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *    Rev 1.26   Jul 29 2005 14:01:52   mtk00773
 * [L1D][Enhence] Support RF SKY74117
 * Resolution for 12111: [L1D][Enhence] Support RF SKY74117
 *
 *    Rev 1.25   Jul 08 2005 16:53:06   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.24   May 17 2005 00:34:38   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.23   Jan 18 2005 00:38:10   BM
 * append new line in W05.04
 *
 *    Rev 1.22   Jul 30 2004 17:37:06   mtk00240
 * L1D add code to support AERO1Plus RF chip
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.21   Jul 05 2004 15:51:32   mtk00773
 * Add RF POLARIS1 setting
 *
 *    Rev 1.20   May 21 2004 19:01:58   mtk00240
 * Add code to support MT6129D
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.19   Feb 13 2004 23:53:10   mtk00489
 * [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 * Resolution for 3912: [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 *
 *    Rev 1.18   Jan 27 2004 15:33:12   mtk00585
 * [L1D][Add] L1D Add code for MT6129C RF Driver.
 *
 *    Rev 1.17   Jan 12 2004 14:26:20   mtk00489
 * [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 * Resolution for 3714: [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 *
 *    Rev 1.16   Oct 23 2003 14:22:20   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.15   Oct 22 2003 12:43:48   mtk00240
 * Remove redefine SETPOINT_GAIN_OFFSET of Bright4
 * Resolution for 3171: [L1D][Fix Compile Error] Redefine SETPOINT_GAIN_OFFSET of Bright4 in m12193.h
 *
 *    Rev 1.14   Oct 20 2003 10:20:54   mtk00240
 * L1D add setpoints for all RF on mt6218B and change F3's set-pount on mt6218
 * Resolution for 3147: [L1D][Enhance] L1D add setpoints for all RF on mt6218B and change F3's set-pount on mt6218
 *
 *    Rev 1.13   Jul 11 2003 17:41:32   mtk00489
 * [L1D][Enhanced]L1D supports MT6129A
 * Resolution for 2241: [L1D][Enhanced]L1D supports MT6129A
 *
 *    Rev 1.12   Jun 26 2003 15:22:18   mtk00240
 * L1D modify some code to support MT6218
 * Resolution for 2116: [L1D][Enhance] L1D modify some code to support MT6218
 *
 *    Rev 1.11   May 16 2003 13:09:24   mtk00489
 * [L1D][New Feature]L1D supports MT6119C
 * Resolution for 1794: [L1D][New Feature]L1D supports MT6119C
 *
 *    Rev 1.10   Jan 17 2003 16:34:00   mtk00474
 * Update AFC slope value
 * Resolution for 631: Update AFC slope value
 *
 *    Rev 1.9   13 Jan 2003 15:13:20   mtk00361
 * Modify DSP_SETPOINT for MT6119 from 40 to 43
 *
 *    Rev 1.8   Nov 11 2002 18:04:58   mtk00474
 * Update MT6119 and AERO RF parameters
 * Resolution for 557: Update MT6119 and AERO RF parameters
 *
 *    Rev 1.7   Sep 06 2002 17:21:42   mtk00210
 * add new define for dynamic setpoint and remove definition for MT6116
 *
 *    Rev 1.6   24 Aug 2002 16:22:00   mtk00361
 * Define dedicated AFC parameter and DSP set point for each RF module
 *
 *    Rev 1.5   22 Jul 2002 08:43:30   mtk00361
 * Modify complie option for MT6205
 *
 *    Rev 1.4   Jul 05 2002 21:34:50   mtk00210
 * Re-construct the header for customer release
 *
 *
 *******************************************************************************/

#ifndef  _M12193_H_
#define  _M12193_H_

#include "l1d_cid.h"
/* Parameter read from Flash or EEPROM */

/*  Bit width of AFC DAC:                           */
/*                     Default     Option           */
/*  1)MT6208,FPGA      10-bit      13-bit           */
/*  2)MT6205           13-bit        X              */

//#define AFC_13bit     /* used to turn on 13-bit AFC DAC for MT6208 or FPGA */
//#define RX_ADC_14bit
#ifdef __MTK_TARGET__
   #if  (!defined(FPGA))&&(!defined(MT6208))
/*MT6205~*/ #ifndef  AFC_13bit
/*MT6205~*/ #define  AFC_13bit
/*MT6205~*/ #endif
   #endif
#endif

#ifdef AFC_13bit
#define  AFC_DP_MIN           (0)
#define  AFC_DP_MAX           (8191)
#else
#define  AFC_DP_MIN           (0)
#define  AFC_DP_MAX           (1023)
#endif

/* C_PSI_STA is moved to l1d_rf_common.h */
#if IS_RF_MT6176
/*MT6176*/ #define  DSP_SETPOINT  (62)    // Default setpoint for dynamic setpoint
/*MT6176*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6176*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#ifndef GPRS_SETPOINT_GAIN_OFFSET
#define GPRS_SETPOINT_GAIN_OFFSET 0
#endif

#ifndef EDGE_SETPOINT_GAIN_OFFSET
#define EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#endif

