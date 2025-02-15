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
 *  l1edps_SCH_TPC_01.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *  Parameters define value between SS and UE
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 06 09 2015 david.tang
 * [MOLY00112427] [MT6291][E1EVB][EL1S] Update l1edps files from CBr4
 * .[l1edps] update l1edps from cbr
 *
 * 05 04 2015 david.tang
 * [MOLY00109013] [MT6291][E1EVB][EL1S] Update l1edps files from CBr
 * .[l1edps] update l1edps from cbr - evb.v3
 *
 * 08 16 2013 vend_david.tang
 * [MOLY00032458] [MT6290E1][EL1S][L1EDPS COMMON] Refine L1S test procedure - 3
 * Update L1S from DEV branch.
 *
 * 08 12 2013 vend_cp.chiang
 * [MOLY00032458] [MT6290E1][EL1S][L1EDPS COMMON] Refine L1S test procedure - 3
 * l1edps common parameter define change and TPC releated header define change for init power
 *
 * 07 04 2013 vend_cp.chiang
 * [MOLY00028593] [MT6290E1][EL1S][FDD][SCH_TPC_01] can't receive TPC 3/3A
 * .
 *
 * 07 04 2013 vend_cp.chiang
 * [MOLY00028593] [MT6290E1][EL1S][FDD][SCH_TPC_01] can't receive TPC 3/3A
 * Rollback //MOLY/TRUNK/MOLY/mcu/interface/modem/lte/l1edps/SCH/l1edps_SCH_TPC_01.h to revision 2
 *
 * 06 20 2013 vend_cp.chiang
 * [MOLY00025272] [MT6290E1][L1EDPS][TC COMMON] L1S test script common modification
 * sch_tpc_01 change to band 2 , EARFCN=900
 *
 * 11 05 2012 jerry.ho
 * [MOLY00005322] TATAKA merge to MOLY
 * add LTE l1edps common header files
 ****************************************************************************/



#ifndef _L1EDPS_SCH_TPC_01_H
#define _L1EDPS_SCH_TPC_01_H

#include "l1edps_common_parameters.h"

#undef DL_EARFCN_BTS1
#undef MIB_DL_BANDWIDTH_BTS1
#undef SIB2_UL_BANDWIDTH_BTS1 
#undef SIB2_REFERENCE_SIGNAL_POWER_BTS1
#undef RRC_RECONFIG_REFERENCE_SIGNAL_POWER_BTS1
#undef SIB2_P0_NOMINAL_PUSCH_BTS1
#undef RRC_RECONFIG_P0_NOMINAL_PUSCH_BTS1
#undef SIB2_P0_NOMINAL_PUCCH_BTS1
#undef RRC_RECONFIG_P0_NOMINAL_PUCCH

#define DL_EARFCN_BTS1 300
#define MIB_DL_BANDWIDTH_BTS1 BW_100_RB
#define SIB2_UL_BANDWIDTH_BTS1 BW_100_RB

#define SIB2_REFERENCE_SIGNAL_POWER_BTS1 20                    /*-60..50*/
#define RRC_RECONFIG_REFERENCE_SIGNAL_POWER_BTS1 20 				/*-60..50*/

#define SIB2_P0_NOMINAL_PUSCH_BTS1 -105 					   /*-126..24*/
#define RRC_RECONFIG_P0_NOMINAL_PUSCH_BTS1 -110						/*-126..24*/

#define SIB2_P0_NOMINAL_PUCCH_BTS1 -127						/*-127..-96*/
#define RRC_RECONFIG_P0_NOMINAL_PUCCH -127						/*-127..-96*/

#undef  RRC_SETUP_TPC_PDCCH_CONFIG_PUCCH_SETUP_BTS1
#define RRC_SETUP_TPC_PDCCH_CONFIG_PUCCH_SETUP_BTS1 L1S_SETUP

#undef  RRC_SETUP_TPC_PDCCH_CONFIG_PUSCH_SETUP_BTS1
#define RRC_SETUP_TPC_PDCCH_CONFIG_PUSCH_SETUP_BTS1 L1S_SETUP

#undef  RRC_RECONFIG_TPC_PDCCH_CONFIG_PUCCH_SETUP_BTS1
#define RRC_RECONFIG_TPC_PDCCH_CONFIG_PUCCH_SETUP_BTS1 L1S_SETUP

#undef  RRC_RECONFIG_TPC_PDCCH_CONFIG_PUSCH_SETUP_BTS1
#define RRC_RECONFIG_TPC_PDCCH_CONFIG_PUSCH_SETUP_BTS1 L1S_SETUP

#undef  SIB2_ALPHA_BTS1
#define SIB2_ALPHA_BTS1 ALPHA_al07

#undef  RRC_RECONFIG_ALPHA_BTS1
#define RRC_RECONFIG_ALPHA_BTS1 ALPHA_al07

/*default value of SIB2_PREAMBLE_INITIAL_RECEIVED_TARGET_POWER_BTS1 is applied*/

#endif

