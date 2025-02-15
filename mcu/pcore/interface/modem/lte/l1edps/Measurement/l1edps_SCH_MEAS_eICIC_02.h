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
 *  l1edps_SCH_MEAS_eICIC_02.h
 *
 * Project:
 * --------
 *   UMOLY
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
 ****************************************************************************/



#ifndef _L1SS_SCH_MEAS_eICIC_02_H
#define _L1SS_SCH_MEAS_eICIC_02_H

#include "l1edps_common_parameters.h"

/*BTS1*/
#undef DL_EARFCN_BTS1
#undef MIB_DL_BANDWIDTH_BTS1
#undef SIB1_SUBFRAME_ASSIGNMENT_BTS1
#undef SIB1_SPECIAL_SUBFRAME_PATTERN_BTS1
#undef SIB2_UL_BANDWIDTH_BTS1 
#undef PHYS_CELL_ID_BTS1
#undef PWR1
#undef RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_PCELL_R10_BTS1 
#undef RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_PCELL_R10_PATTERN_BTS1
#undef RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_PCELL_R10_PATTERN_TDD_BTS1
#undef RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_BTS1
#undef RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_PATTERN_BTS1
#undef RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_PATTERN_TDD_BTS1
#undef RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_CELL_1_PCI_START_BTS1
#undef RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_CELL_1_PCI_RANGE_BTS1

/*BTS2*/
#undef DL_EARFCN_BTS2
#undef MIB_DL_BANDWIDTH_BTS2
#undef SIB1_SUBFRAME_ASSIGNMENT_BTS2
#undef SIB1_SPECIAL_SUBFRAME_PATTERN_BTS2
#undef SIB2_UL_BANDWIDTH_BTS2 
#undef PHYS_CELL_ID_BTS2
#undef PWR2


/*BTS1*/
#define DL_EARFCN_BTS1 38450
#define MIB_DL_BANDWIDTH_BTS1 BW_50_RB
#define SIB1_SUBFRAME_ASSIGNMENT_BTS1 SUBFRAME_ASSIGNMENT_sa1
#define SIB1_SPECIAL_SUBFRAME_PATTERN_BTS1 SPECIAL_SUBFRAME_PATTERN_ssp6
#define SIB2_UL_BANDWIDTH_BTS1 BW_50_RB
#define PHYS_CELL_ID_BTS1 1
#define PWR1 -83
#define RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_PCELL_R10_BTS1 L1S_SETUP
//1000000000 1000000000
#define RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_PCELL_R10_PATTERN_TDD_BTS1 { \
                                                                        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* SFN % 2 = 0, Subframe0..9 */ \
                                                                        1, 0, 0, 0, 0, 0, 0, 0, 0, 0 /* SFN % 2 = 1, Subframe0..9 */ \
                                                                      }
#define RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_PCELL_R10_PATTERN_BTS1 RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_PCELL_R10_PATTERN_TDD_BTS1


#define RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_BTS1 L1S_SETUP
//0000000001 0000000001
#define RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_PATTERN_TDD_BTS1 {\
                                                                                0, 0, 0, 0, 0, 0, 0, 0, 0, 1, /* SFN % 2 = 0, Subframe0..9 */ \
                                                                                0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /* SFN % 2 = 1, Subframe0..9 */ \
                                                                             }
#define RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_PATTERN_BTS1 RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_PATTERN_TDD_BTS1

#define RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_CELL_1_PCI_START_BTS1 2
#define RRC_RECONFIG_MEAS_SUBFRAME_PATTERN_CONFIG_NEIGH_R10_CELL_1_PCI_RANGE_BTS1 PCI_RANGE_n4 /*n4, n8, n12, n16, n24, n32, n48, n64, n84, n96, n128, n168, n252, n504*/

/*BTS2*/
#define DL_EARFCN_BTS2 38450
#define MIB_DL_BANDWIDTH_BTS2 BW_50_RB
#define SIB1_SUBFRAME_ASSIGNMENT_BTS2 SUBFRAME_ASSIGNMENT_sa1
#define SIB1_SPECIAL_SUBFRAME_PATTERN_BTS2 SPECIAL_SUBFRAME_PATTERN_ssp6
#define SIB2_UL_BANDWIDTH_BTS2 BW_50_RB
#define PHYS_CELL_ID_BTS2 2
#define PWR2 -80

#endif


