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
 *   l1d_rf_pcore.h
 *
 * Project:
 * --------
 *   TK6291
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
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime:  $
 * $Log:      $
 *
 * 07 29 2015 dou.ju
 * [MOLY00133157] [Jade] DRDI code modification [GL1D RF] 2G DRDI part
 * .
 *
 * 06 18 2015 prakash.chaudhary
 * [MOLY00122406] [L1D][modify]Check in BB driver for Jade BB porting
 * 	.
 *
 * 05 29 2015 sherman.chung
 * [MOLY00116464] [UMOLY] 2G L1 TAS Check in
 * .
 *
 * 04 24 2015 ola.lee
 * [MOLY00091988] [L1D] Update MT6176 2G RF Driver
 * 	.
 *
 * 04 24 2015 ola.lee
 * [MOLY00091988] [L1D] Update MT6176 2G RF Driver-Update TX Propagation Dely.
 *
 * 04 24 2015 ola.lee
 * [MOLY00091988] [L1D] Update MT6176 2G RF Driver
 * 	Update TQ_EPSK_TX_DELAY for MT6176.
 *
 * 04 15 2015 ola.lee
 * [MOLY00091988] [L1D] Update MT6176 2G RF Driver
 * Fix G->8 EDGE TX PVT.
 *
 * 02 12 2015 yi-ying.lin
 * [MOLY00095975] [L1D][Modify] TK6291 CC NVRAM and custom data modification L1D mipi part
 * 	.
 *
 *
 *******************************************************************************/

#ifndef  _L1D_RF_PCORE_H_
#define  _L1D_RF_PCORE_H_
/* ------------------------------------------------------------------------- */

#if IS_RF_MT6176
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ /*   BFE Setting                                          */
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT
/*MT6176*/ #define  TQ_EPSK_TX_DELAY             8
/*MT6176*/ #endif
/*MT6176*/
#endif


#ifndef  QB_TX_SAMPLE_OFFSET_GMSK
#define  QB_TX_SAMPLE_OFFSET_GMSK      0
#endif

#ifndef  QB_TX_SAMPLE_OFFSET_EPSK
#define  QB_TX_SAMPLE_OFFSET_EPSK      0
#endif


#ifndef  IS_EGSM900_DISABLE
#define  IS_EGSM900_DISABLE            0
#endif

#endif

