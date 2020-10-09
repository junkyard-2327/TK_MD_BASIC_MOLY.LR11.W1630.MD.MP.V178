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
 *   lte_meta_tool.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *  LTE test mode specific definitions for synchronizing with HOST tool
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 08 12 2016 mars.chang
 * [MOLY00191085] [6291][LTE BAND EXTENSION] Band 66 support - [RF] TST module
 * MP5 B66 feature
 *
 * 05 09 2016 mars.chang
 * [MOLY00178208] [MT6291][EL1TST] EXTERNAL LNA (eLNA) driver
 * ELNA MP3
 *
 * 04 20 2016 wei-chi.lai
 * [MOLY00174974] [MT6755] Test Mode show error parameters on DLL file when error occurs
 * new structure definition
 * 	.
 *
 * 10 20 2015 yamin.chen
 * [MOLY00146018] [MT6755] Add hrm/filter path in nsft tstm
 * 	.
 *
 * 10 08 2015 mars.chang
 * [MOLY00144646] [MT6755][EL1TST] HRM and Filter mode and LO Spur feature
 * .
 *
 * 08 07 2015 mars.chang
 * [MOLY00135062] [MT6755] EL1TST common feature
 * add FHC timing requirement and add some capability
 *
 * 07 24 2015 samuel.yang
 * [MOLY00131527] [TK6291] Add LTE DPD/CIM3 capability
 * .
 *
 * 07 06 2015 mars.chang
 * [MOLY00123503] [MT6291][E1EVB][EL1_PHYTest][TPC] TDD band 39 PA calibration value is abnormal
 * .
 *
 * 07 03 2015 samuel.yang
 * [MOLY00122885] [TK6291] Modify comment and remove redundant DPD/CIM3 capability from LTE
 * .
 *
 * 06 09 2015 samuel.yang
 * [MOLY00119541] [TK6291] Add META mode handlers for LTE TX bypass mode
 * .
 *
 * 06 01 2015 samuel.yang
 * [MOLY00116993] [TK6291] Fix xl1sim build error
 * .
 *
 * 05 28 2015 samuel.yang
 * [MOLY00116993] [TK6291] Modify codegen file to show xL1TST related PS logs on L1 core
 * .
 *
 * 05 07 2015 samuel.yang
 * [MOLY00111833] [TK6291] Phase in MMRF TST related modifications
 * .
 *
 * 04 28 2015 mars.chang
 * [MOLY00108945] [MT6291] Check in EL1TST common feature
 * .
 *
 * 04 21 2015 samuel.yang
 * [MOLY00108525] [TK6291] Fix UMOLY build error for TK6291_E1EVB(LWTG1_CA7_V2SKU1)
 * .
 *
 * 04 20 2015 samuel.yang
 * [MOLY00108029] [TK6291] META mode related modifications
 * .
 *
 * 04 07 2015 mars.chang
 * [MOLY00106160] [MT6291] Check in el1tst related modification for RSSI measurement
 * .
 *
 * 04 01 2015 mars.chang
 * [MOLY00104150] [MT6291] Check in el1tst related modification
 * modify DFE prototype
 *
 * 03 20 2015 linchih.chu
 * [MOLY00100002] [MT6291][UMOLY] Integrate MML1_RF into UMOLY
 * sync EL1S //UMOLY_CBr/david.tang/UMOLY_EL1S.evb.v2/ (CL 1154143)(MML1_RF+TST)
 *
 * 03 12 2015 mars.chang
 * [MOLY00093908] [MT6291] modify EL1TST file
 * add CONT TX RX CBW feature
 *
 * 03 10 2015 mars.chang
 * [MOLY00093908] [MT6291] modify EL1TST file
 * modify sine Tone TX bug
 *
 * 03 09 2015 mars.chang
 * [MOLY00093908] [MT6291] modify EL1TST file
 * Patch TST bring up related modification
 *
 * 03 04 2015 mars.chang
 * [MOLY00093908] [MT6291] modify EL1TST file
 * modify
 *
 * 02 26 2015 mars.chang
 * [MOLY00093908] [MT6291] modify EL1TST file
 * .
 *
 * 02 24 2015 mars.chang
 * [MOLY00093908] [MT6291] add RF tool related modification
 *
 * 02 15 2015 samuel.yang
 * [MOLY00096236] [TK6291] Modify LTE MS capability
 * .
 *
 * 02 13 2015 mars.chang
 * [MOLY00093908] [MT6291] modify some function name.
 *
 * 02 13 2015 strike.tseng
 * [MOLY00092145] [TK6291][UMOLY] Integrate EL1D into MT6291_DEV.
 * 	[SyncCode] MT6291_DEV/mcu/l1core/modem/el1
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/interface/modem/l1/lte/external/ to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/modem/l1/lte/external/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/interface/modem/l1/mml1/external/mml1_rf_cal_def.h to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/modem/l1/mml1/external/mml1_rf_cal_def.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/modem/el1/el1d/ to //UMOLY/DEV/MT6291_DEV/mcu/common/modem/el1/el1d/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/common/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/common/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/el1d/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/el1d/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/el1d_pub/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/el1d_pub/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/el1d_mmrf_interface.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/el1d_mmrf_interface.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_cal_interface.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_cal_interface.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_action.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_action.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_buffer.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_buffer.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calbbfectrl.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calbbfectrl.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calgor.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calgor.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calmmdfe.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calmmdfe.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocif.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocif.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocseq.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocseq.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calrfctrl.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calrfctrl.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 *
 * 02 13 2015 strike.tseng
 * [MOLY00092145] [TK6291][UMOLY] Integrate EL1D into MT6291_DEV.
 * 	[SyncCode] MT6291_DEV/mcu/l1core/modem/el1
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/interface/modem/l1/lte/external/ to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/modem/l1/lte/external/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/interface/modem/l1/mml1/external/mml1_rf_cal_def.h to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/modem/l1/mml1/external/mml1_rf_cal_def.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/modem/el1/el1d/ to //UMOLY/DEV/MT6291_DEV/mcu/common/modem/el1/el1d/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/common/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/common/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/el1d/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/el1d/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/el1d_pub/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/el1d_pub/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/el1d_mmrf_interface.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/el1d_mmrf_interface.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_cal_interface.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_cal_interface.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_action.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_action.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_buffer.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_buffer.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calbbfectrl.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calbbfectrl.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calgor.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calgor.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calmmdfe.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calmmdfe.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocif.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocif.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocseq.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocseq.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calrfctrl.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calrfctrl.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 *
 * 02 13 2015 strike.tseng
 * [MOLY00092145] [TK6291][UMOLY] Integrate EL1D into MT6291_DEV.
 * 	[SyncCode] MT6291_DEV/mcu/l1core/modem/el1
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/interface/modem/l1/lte/external/ to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/modem/l1/lte/external/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/interface/modem/l1/mml1/external/mml1_rf_cal_def.h to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/modem/l1/mml1/external/mml1_rf_cal_def.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/modem/el1/el1d/ to //UMOLY/DEV/MT6291_DEV/mcu/common/modem/el1/el1d/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/common/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/common/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/el1d/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/el1d/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/el1d_pub/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/el1d_pub/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/el1d_mmrf_interface.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/el1d_mmrf_interface.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_cal_interface.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_cal_interface.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_action.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_action.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_buffer.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_buffer.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calbbfectrl.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calbbfectrl.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calgor.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calgor.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calmmdfe.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calmmdfe.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocif.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocif.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocseq.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocseq.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calrfctrl.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calrfctrl.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 *
 * 02 13 2015 strike.tseng
 * [MOLY00092145] [TK6291][UMOLY] Integrate EL1D into MT6291_DEV.
 * 	[SyncCode] MT6291_DEV/mcu/l1core/modem/el1
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/interface/modem/l1/lte/external/ to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/modem/l1/lte/external/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/interface/modem/l1/mml1/external/mml1_rf_cal_def.h to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/modem/l1/mml1/external/mml1_rf_cal_def.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/modem/el1/el1d/ to //UMOLY/DEV/MT6291_DEV/mcu/common/modem/el1/el1d/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/common/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/common/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/el1d/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/el1d/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/el1d_pub/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/el1d_pub/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/el1d_mmrf_interface.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/el1d_mmrf_interface.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_cal_interface.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_cal_interface.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_action.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_action.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_buffer.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_buffer.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calbbfectrl.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calbbfectrl.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calgor.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calgor.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calmmdfe.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calmmdfe.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocif.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocif.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocseq.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocseq.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calrfctrl.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calrfctrl.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 *
 * 02 13 2015 strike.tseng
 * [MOLY00092145] [TK6291][UMOLY] Integrate EL1D into MT6291_DEV.
 * [SyncCode] MT6291_DEV/mcu/l1core/modem/el1
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/interface/modem/l1/lte/external/ to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/modem/l1/lte/external/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/interface/modem/l1/mml1/external/mml1_rf_cal_def.h to //UMOLY/DEV/MT6291_DEV/mcu/common/interface/modem/l1/mml1/external/mml1_rf_cal_def.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/common/modem/el1/el1d/ to //UMOLY/DEV/MT6291_DEV/mcu/common/modem/el1/el1d/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/common/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/common/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/el1d/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/el1d/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/el1/el1d_pub/ to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/el1/el1d_pub/ with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/el1d_mmrf_interface.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/el1d_mmrf_interface.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_cal_interface.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_cal_interface.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_action.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_action.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_buffer.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/interface/l1/mml1/mml1_rf_calpocseq_buffer.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calbbfectrl.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calbbfectrl.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_caldatabase.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calgor.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calgor.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calmmdfe.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calmmdfe.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocif.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocif.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocseq.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calpocseq.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calrfctrl.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calrfctrl.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.c to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.c with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 * 	Integrate from //xL1SIM/DEV/xL1SIM_MT6291_Dev/umoly/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.h to //UMOLY/DEV/MT6291_DEV/mcu/l1core/modem/mml1/mml1_rf/mml1_rf_calutil.h with label "xL1SIM_MT6291_Dev_lte_upto_CL1075162"
 *
 * 02 10 2014 samuel.yang
 * [MOLY00055620] [MT6290E2] Modify temperature compensation range and add new API for tool to query temperature information
 * .
 *
 * 11 14 2013 wilson.su
 * [MOLY00025368] [MT6290E1][RFDRV]MIPI customization driver
 * [MT6290]MIPI PA control interface by meta.
 *
 * 11 07 2013 wen-chieh.chang
 * [MOLY00045491] [MT6290E1][L1TestMode][Case ID][Module] If RX sync fail at RXNSFT, the system will assert
 * .
 *
 * 11 04 2013 wen-chieh.chang
 * [MOLY00032398] [MT6290E1][L1TestMode]NSFT list mode code merge
 * force pa mode in tx calibration
 *
 * 11 04 2013 ms.lin
 * [MOLY00044962] [MT6290E2][L1TestMode][Factory Calibration][RFC] Power Detector (Coupler) temperature compensation over subband feature
 *    .
 *
 * 10 15 2013 wen-chieh.chang
 * [MOLY00032398] [MT6290E1][L1TestMode]NSFT list mode code merge
 * .
 *
 * 10 03 2013 ms.lin
 * [MOLY00040151] [MT6290E1] Modification about tempersture ADC function and continuous RX function
 *    .
 *
 * 09 04 2013 samuel.yang
 * Add LTE META capability API.
 *
 * 08 27 2013 ms.lin
 * [MOLY00006061] [Design change]LTE EL1 DRV/TSTM/PHS code change
 *    Support RF capability query
 *
 * 08 20 2013 wen-chieh.chang
 * [MOLY00032398] [MT6290E1][L1TestMode]FHC code merge
 * .
 *
 * 06 05 2013 ms.lin
 * [MOLY00006061] [Design change]LTE EL1 DRV/TSTM/PHS code change
 * .
 *
 * 05 15 2013 ms.lin
 * [MOLY00006061] [Design change]LTE EL1 DRV/TSTM/PHS code change
 * .
 *
 ****************************************************************************/

#ifndef LTE_META_TOOL_H
#define LTE_META_TOOL_H

#include "kal_general_types.h"
#ifndef  __LTE_L1SIM__
#include "ft_msg_common.h"
#endif

/*******************define******************/
#define TOOL_NOT_SUPPORT 2
#define TOOL_CNF_OK   1
#define TOOL_CNF_FAIL 0

#define ERF_BAND_MAP_SIZE           2 //support 2*32 bands at maximum, need to align LTE_BIT_MASK_BUFFER_SIZE
#define ERF_BAND_MAPPING_TBL_SIZE   ERF_BAND_MAP_SIZE*32
#define ERF_MAX_BAND_NUM 21

#define MAX_FHC_BAND_NUM 10
#define MAX_FHC_RX_FREQ_NUM 22
#define MAX_FHC_TX_FREQ_NUM 22
#define MAX_PWR_STEP_NUM 27
#define MAX_NSFT_LIST_TX_BAND_NUM 10
#define MAX_NSFT_LIST_TX_FREQ_NUM 13
#define ET_CAL_PATH_DELAY_CAL_BY_SUBBAND

/********************* MT6291 Constant Definitions *********************/

#define MAX_FHC_RX_FREQ_NUM_EX       15
#define MAX_FHC_TX_FREQ_NUM_EX       15

#define MAX_RX_CC_NUM                2  // for gain-by-gin PCC & SCC results

#define MAX_ROUTE_NUM                128
#define MAX_ROUTE_NUM_IN_WORD        (((MAX_ROUTE_NUM-1)>>5)+1)

#define MAX_TEMP_SECTION_NUM         8
#define MAX_RX_LNA_N_MODE_NUM        6  //for LNA normal mode
#define MAX_RX_LNA_L_MODE_NUM        1  //for LNA low power mode
#define MAX_RX_LNA_MODE_NUM         (MAX_RX_LNA_N_MODE_NUM+MAX_RX_LNA_L_MODE_NUM)

#define MAX_TX_DET_MODE_NUM          3
#define MAX_TX_PA_LEVEL_NUM          8
#define MAX_TX_RPT_NUM              (MAX_TX_DET_MODE_NUM+MAX_TX_PA_LEVEL_NUM)

#define RX_TYPE2_START_ROUTE_NUM     96
#define MAX_FHC_RX_TYPE1_ROUTE_NUM   48 //single band + inter-CA + PCC/SCC exchange
#define MAX_FHC_RX_TYPE2_ROUTE_NUM   8  //intra-NCCA
#define MAX_FHC_TX_TYPE1_ROUTE_NUM   21

#define MAX_SCENARIO_BY_BAND_NUM     15 // SCENARIO means CA category


/*********************RF calibration structure*********************/

typedef enum
{
   ERF_TEST_CMD_START_PUSCH_TX             = 0,
   ERF_TEST_CMD_START_PUCCH_TX             = 1,
   ERF_TEST_CMD_START_PRACH_TX             = 2,
   ERF_TEST_CMD_START_SRS_TX               = 3,
   ERF_TEST_CMD_START_MIX_RX               = 4,
   ERF_TEST_CMD_GET_MIX_RX_RPT             = 5,
   ERF_TEST_CMD_RESET_COUNTER              = 6,
   ERF_TEST_CMD_STOP_TEST_MODE             = 7,
   ERF_TEST_CMD_SET_TX_TPC_SETTING         = 8,
   ERF_TEST_CMD_GET_TX_TPC_SETTING         = 9,
   ERF_TEST_CMD_GET_RF_CAPABILITY          = 10,
   ERF_TEST_CMD_START_AFC_SINGLE_TONE_TX   = 11,
   ERF_TEST_CMD_SET_AFC_SETTING            = 12,
   ERF_TEST_CMD_GET_AFC_SETTING            = 13,
   ERF_TEST_CMD_START_TPC_SINGLE_TONE_TX   = 14,
   ERF_TEST_CMD_SET_TPC_PA_GAIN            = 15,
   ERF_TEST_CMD_GET_POWER_DETECTOR_VALUE   = 16,
   ERF_TEST_CMD_START_RSSI                 = 17,
   ERF_TEST_CMD_GET_RSSI_SETTING           = 18,
   ERF_TEST_CMD_SET_RSSI_SETTING           = 19,
   ERF_TEST_CMD_START_FHC                  = 20,
   ERF_TEST_CMD_CHECK_IF_FUNC_EXIST        = 21,  //to check this function supoort,but only use on 2G3G,LTE not use
   ERF_TEST_CMD_GET_RF_TEMP                = 22,
   ERF_TEST_CMD_GET_TADC_SETTING           = 23,
   ERF_TEST_CMD_SET_TADC_SETTING           = 24,
   ERF_TEST_CMD_START_NSFT_LIST            = 25,
   ERF_TEST_CMD_START_CONT_RX              = 26,
   ERF_TEST_CMD_SET_RF_MIPI_CODEWORD       = 27,
   ERF_TEST_CMD_GET_RF_MIPI_CODEWORD       = 28,
   ERF_TEST_CMD_GET_TEMPERATURE_INFO       = 29,
   ERF_TEST_CMD_SET_ET_MODE                = 30,
   ERF_TEST_CMD_SET_FILTER_PATH_FLAG       = 31,
   ERF_TEST_CMD_START_ETCAL                = 32,
   ERF_TEST_CMD_GET_ETCAL_SETTING          = 33,
   ERF_TEST_CMD_SET_ETCAL_SETTING          = 34,
   ERF_TEST_CMD_SET_TOOL_USAGE_TO_L1       = 35,
   ERF_TEST_CMD_QUERY_NVRAM_LID            = 36,
   ERF_TEST_CMD_GET_GPS_CO_CLOCK_DATA      = 37,
   ERF_TEST_CMD_SET_GPS_CO_CLOCK_DATA      = 38,
   ERF_TEST_CMD_CHECK_ET_PATH_DELAY_SEARCH = 39,
   ERF_TEST_CMD_START_ET_PATH_DELAY_SEARCH = 40,
   ERF_TEST_CMD_SET_LNA_SRX                = 41,
   ERF_TEST_CMD_START_RSSI_CA_MODE         = 42,
   ERF_TEST_CMD_START_CONT_RX_CA_MODE      = 43,
   ERF_TEST_CMD_GET_RSSI_SETTING_EX        = 44,  // for both type 1 & type 2 RSSI data
   ERF_TEST_CMD_SET_RSSI_SETTING_EX        = 45,  // for both type 1 & type 2 RSSI data
   ERF_TEST_CMD_START_MIX_RX_CA_Mode       = 46,
   ERF_TEST_CMD_GET_MIX_RX_CA_MODE_RPT     = 47,
   ERF_TEST_CMD_QUERY_CA_CONFIG_TABLE      = 48,
   ERF_TEST_CMD_START_FHC_CA_MODE          = 49,
   ERF_TEST_CMD_SET_HRM_FLAG               = 50,
   ERF_TEST_CMD_SET_FILTER_TX_TPC_SET      = 51,
   ERF_TEST_CMD_GET_FILTER_TX_TPC_SET      = 52,
   ERF_TEST_CMD_SET_HRM_TX_TPC_SET         = 53,
   ERF_TEST_CMD_GET_HRM_TX_TPC_SET         = 54,
   ERF_TEST_CMD_FORCE_TAS                  = 55,
   ERF_TEST_CMD_START_NSFT_HRM_LIST        = 56,
   ERF_TEST_CMD_RX_ANT_PATH_SEL            = 74,

   /* --------------- please add new command prior to this line --------------- */
   ERF_TEST_CMD_GP_TOOL_COMMAND_START,
   ERF_TEST_CMD_END,
   ERF_TEST_CMD_MAX                        = 0x7FFFFFFF
}ERfTestCmdType;

typedef enum
{
   ERF_TEST_RFID_NULL   = 0,
   ERF_TEST_RFID_MT6169 = 1,
   ERF_TEST_RFID_MT6176 = 2,
   ERF_TEST_RFID_END    = 0xFFFF

}ERfTestRfId;

typedef enum
{
   ERF_TEST_PARAMS_TEMP_DAC_SRC_NULL   = 0,
   ERF_TEST_PARAMS_TEMP_DAC_SRC_AUXADC = 1,
   ERF_TEST_PARAMS_TEMP_DAC_SRC_BSI    = 2,
   ERF_TEST_PARAMS_TEMP_DAC_SRC_END    = 0xFFFF

}ERfTestParamsTempDacSrc;

typedef enum
{
   ERF_TEST_AFC_TYPE_NULL   = 0,
   ERF_TEST_AFC_TYPE_TCVCXO = 1,
   ERF_TEST_AFC_TYPE_VCXO   = 2,
   ERF_TEST_AFC_TYPE_END    = 0xFFFF
}ERfTestAfcType;

typedef enum
{
   ERF_TEST_VCO_SRX_SEL_INVALID = 0,
   ERF_TEST_VCO_SRX_SEL_VCO     = 1,
   ERF_TEST_VCO_SRX_SEL_SRX     = 2,
}ERfTestVcoSrxSel;

typedef enum
{
   ERF_TEST_RX_GAIN_MODE_VERNO_INVALID = 0,
   ERF_TEST_RX_GAIN_MODE_VERNO1        = 1,
   ERF_TEST_RX_GAIN_MODE_VERNO2        = 2,
}ERfTestRxGainModeVerno;

typedef enum
{
   ERF_TEST_RX_GBG_EXP_CFG_INVALID = 0,
   ERF_TEST_RX_GBG_EXP_CFG_TYPE1   = 1, // Expand all enabled gain mode
   ERF_TEST_RX_GBG_EXP_CFG_TYPE2   = 2, // Expand all enabled gain mode except LPM
}ERfTestRxGbgExpCfg;

typedef enum
{
   ERF_TEST_DL_2CA_TYPE_NON_CA     = 0,                            // non-CA (single band case)
   ERF_TEST_DL_2CA_TYPE_CCA        = ERF_TEST_DL_2CA_TYPE_NON_CA,  // intra-band CCA
   ERF_TEST_DL_2CA_TYPE_CNDL_NCCA  = ERF_TEST_DL_2CA_TYPE_NON_CA,  // intra-band conditional NCCA
   ERF_TEST_DL_2CA_TYPE_ITB_CA     = 1,                            // inter-band CA
   ERF_TEST_DL_2CA_TYPE_ITB_CA_ALT = 2,                            // inter-band CA (alternative path)
   ERF_TEST_DL_2CA_TYPE_NCCA       = 3,                            // intra-band NCCA
   ERF_TEST_DL_2CA_TYPE_MAX,
   ERF_TEST_DL_2CA_TYPE_INVALID    = 0xFF
}ERfTestDl2CaCategory;

typedef enum
{
   ERF_TEST_RSSI_TABLE_TYPE_INVALID    = 0,
   ERF_TEST_RSSI_TABLE_TYPE_1          = 1,  // for single band or inter-band CA RSSI table
   ERF_TEST_RSSI_TABLE_TYPE_2          = 2,  // for NCCA RSSI table
   ERF_TEST_RSSI_TABLE_TYPE_MAX        = 0xFF
}ERfTestRSSITableType;

typedef enum
{
   ERF_TEST_CA_MODE_UI_VERSION_INVALID = 0,
   ERF_TEST_CA_MODE_UI_VERSION1        = 1,
   ERF_TEST_CA_MODE_UI_VERSION2        = 2,
   ERF_TEST_CA_MODE_UI_VERSION_MAX,
}ERfTestCaModeUiVersion;

typedef enum
{
   ERF_TEST_TEMP_RANGE_M10_65 = 0,
   ERF_TEST_TEMP_RANGE_M10_90 = 1,
   ERF_TEST_TEMP_RANGE_INVALID,
}ERfTestTempRangeVersion;

typedef enum
{
   ERF_TEST_RSSI_SET_STATUS_INVALID = 0,
   ERF_TEST_RSSI_SET_STATUS_OK      = 1,  // set scusses
   ERF_TEST_RSSI_SET_STATUS_ERR1    = 2,  // band mismatch with route
   ERF_TEST_RSSI_SET_STATUS_ERR2    = 3,  // subband frequency out of band region
   ERF_TEST_RSSI_SET_STATUS_MAX,
}ERfTestRSSISetStatus;

typedef enum
{
   ERF_TEST_TPC_SET_STATUS_INVALID = 0,
   ERF_TEST_TPC_SET_STATUS_OK      = 1,  // set scusses
   ERF_TEST_TPC_SET_STATUS_ERR1    = 2,  // Notused, just aligned RX
   ERF_TEST_TPC_SET_STATUS_ERR2    = 3,  // subband frequency out of band region
   ERF_TEST_TPC_SET_STATUS_MAX,
}ERfTestTPCSetStatus;

typedef enum
{
   ERF_TEST_ANT_SEL_0,   ///< Select antenna 0 only.
   ERF_TEST_ANT_SEL_1,   ///< Select antenna 1 only.
   ERF_TEST_ANT_SEL_01   ///< Select antenna 0 & 1.
} ERfTestAntSel;

typedef struct
{
   kal_uint8          vco;
   kal_uint8          srx;
   kal_uint8          lna_port;
   kal_uint8          lna_group;
}ERfTestVcoSrxLnaCfg;

typedef struct
{
   kal_uint8          band;
   kal_uint8          ridx[3];
   ERfTestVcoSrxLnaCfg  cfg[3];
}ERfTestSupportVcoSrxLnaCfg;

typedef struct
{
   kal_uint8          band;
   kal_uint8          route_idx;
   kal_uint8          usg_start_idx;
   kal_uint8          usg_stop_idx;
}ERfTestUsageElm;

typedef struct
{
   ERfTestUsageElm    cat[4];
}ERfTestSupportRxUsageByBand;

typedef struct
{
   kal_uint8          band;
   kal_uint8          bw_class;
}ERfTestCcElm;

typedef struct
{
   kal_uint8          cc_num;
   kal_uint8          usg_band;
   ERfTestCcElm       ca_setting[MAX_RX_CC_NUM];
}ERfTestUsageDes;

typedef struct
{
   kal_uint8          band;
   kal_uint8          index[MAX_SCENARIO_BY_BAND_NUM];
}ERfTestSupportCaCombTblIdx;

typedef struct
{
   kal_uint8          band;
   kal_uint8          bw_class;
   kal_uint8          lna_port;
   kal_uint8          lna_group;
   kal_uint8          vco_cfg;
   kal_uint8          srx_cfg;
   kal_uint8          padding[2];
}ERfTestRouteDes;

typedef struct
{
   ERfTestRouteDes    cfg[MAX_RX_CC_NUM];
}ERfTestScenarioDes;

typedef struct
{
   kal_uint16         tbl_offset;
   kal_uint16         tbl_size;
}ERfTestVarTblInfo;

typedef struct
{
   kal_uint8          band;
   kal_uint8          ca_cat_rx_cal_bitmap;  // [0]: enable bit of "single band"
                                             // [1]: enable bit of "CA band"
                                             // [2]: enable bit of "CA band (alternative)"
                                             // [3]: enable bit of "NCCA band"
                                             // [4:7]: reserved
   kal_uint8          ca_cat_tx_cal_bitmap;  // [0]: enable bit of "single band"
                                             // [1:7]: reserved
   kal_uint8          padding;
}ERfTestSupportCaCalDim;

typedef struct
{
   kal_uint16         gain_mode_ena_mask;    // [0]: enable bit of mode1
                                             // [1]: enable bit of mode2
                                             // [2]: enable bit of mode3
                                             // [3]: enable bit of mode4
                                             // [4]: enable bit of mode5
                                             // [5]: enable bit of mode6
                                             // [6]: enable bit of LPM mode
                                             // [7:15]: reserved
   kal_uint16         gain_by_gain_expn_type;
}ERfTestSupportRxGainModeMask;

typedef struct
{
   kal_int16          gain_mode_setting[MAX_RX_LNA_MODE_NUM][2];
}ERfTestSupportRxGain;

typedef struct
{
   kal_int8          ncca_gbg_bypass_check_table[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM];
}ERfTestNccaGbgBypassCheck;

typedef struct
{
   kal_uint8 band;
   kal_uint8 duplexMode;/* 0:tdd, 1:fdd */
   kal_uint8 tddConfig;
   kal_uint8 tddSfConfig;
   kal_uint16 ulFrequency; /* range: 7280~26900 (100KHz unit) */
   kal_uint16 cellId;
   kal_int16 afcdac;
   kal_uint8 ulBandwidth; /* 0:6, 1:15, 2:25, 3:50, 4:75, 5:100RB */
   kal_uint8 vrbStart;
   kal_uint8 vrbLength;
   kal_uint8 mcsMode;
   kal_uint8 txPwrMode;//0:use txPowerValue, 1: use HW register
   kal_int16 txPowerValue;/*S(8,8)*/
   kal_uint8 networkSelection; /* 0~31 */
   kal_uint8 txCloseLoopDisbl;
   kal_uint8 amprEnbl;
   kal_int16 bbBackoff;/*S(8,8)*/
   kal_uint8 rfGain;
   kal_uint8 paMode; /* 0:high, 1:middle, 2:low */
   kal_uint8 paVcc;
   kal_uint8 vm0;
   kal_uint8 vm1;
   kal_uint8 enableCsr;
   kal_uint16 dlFrequency;
}ERfTestCmdPuschTx;

typedef struct
{
   kal_uint8 band;
   kal_uint8 duplexMode;/*0:tdd, 1:fdd */
   kal_uint8 tddConfig;
   kal_uint8 tddSfConfig;
   kal_uint16 ulFrequency;/* range: 7280~26900 (100KHz unit) */
   kal_uint16 cellId;
   kal_int16 afcdac;
   kal_uint8 ulBandwidth; /*0:6, 1:15, 2:25, 3:50, 4:75, 5:100RB */
   kal_uint8 format; /*0:1, 1:1a, 2:1b, 3:2, 4:2_cpack, 5:2a, 6:2b */
   kal_int16 txPowerValue;/*S(8,8)*/
   kal_uint8 networkSelection; /* 0~31 */
   kal_uint8 txCloseLoopDisbl;
   kal_uint8 amprEnbl;
}ERfTestCmdPucchTx;

typedef struct
{
   kal_uint8 band;
   kal_uint16 ulFrequency;/* range: 7280~26900 (100KHz unit) */
   kal_uint16 cellId;
   kal_int16 afcdac;
   kal_uint8 configIndex; /* 0:fdd time mask, 1:tdd time mask, 2:fdd evm, 3:tdd evm*/
   kal_int16 txPowerValue;/*S(8,8)*/
   kal_uint8 networkSelection; /* 0~31 */
   kal_uint8 txCloseLoopDisbl;
   kal_uint8 amprEnbl;
}ERfTestCmdPrachTx;

typedef struct
{
   kal_uint8 band;
   kal_uint8 duplexMode; /*0:tdd, 1:fdd */
   kal_uint16 ulFrequency;/* range: 7280~26900 (100KHz unit) */
   kal_uint16 cellId;
   kal_int16 afcdac;
   kal_uint8 tddCsSrsBwCfg; /*range: 0, 2, 5, 7*/
   kal_int16 txPowerValue;/*S(8,8)*/
   kal_uint8 networkSelection; /* 0~31 */
   kal_uint8 txCloseLoopDisbl;
   kal_uint8 amprEnbl;
}ERfTestCmdSrsTx;

typedef struct
{
   kal_uint8 mode;//0: DL Rx, 1: Tx-Rx, 2: Pseudo Tx-Rx

   /*Common parameters*/
   kal_uint8 measCnt;//range 0~10
   kal_uint8 measBandwidth;//0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
   kal_int16 afcdac;
   kal_uint16 dlFrequency;//range: 7280~26900 (100KHz unit)
   kal_uint8 band;//range 1~40
   kal_uint8 duplexMode;//0:tdd, 1:fdd
   kal_uint8 tddConfig;//range 0~7
   kal_uint8 tddSfConfig;//range 0~8
   kal_uint8 bandwidth;//(UL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
   kal_uint8 rxPath0Enbl;
   kal_uint8 rxPath1Enbl;

   /*Tx-Rx & Pseudo Tx-Rx only*/
   kal_uint16 ulFrequency;//range: 7280~26900 (100KHz unit)
   kal_int16 txPowerValue;/*S(8,8)*/

   /*Pseudo Tx-Rx only*/
   kal_uint8 vrbStart;
   kal_uint8 vrbLength;
   kal_uint8 mcsMode;

}ERfTestCmdMixRx;

typedef struct
{
   kal_uint8 measRptCnt;//range 0~10
   kal_int16 rssiPath0[10];//final format is TODO
   kal_int16 rssiPath1[10];//final format is TODO
   kal_int16 rsrpPath0[10];//final format is TODO
   kal_int16 rsrpPath1[10];//final format is TODO
   kal_int16 rsrqPath0[10];//final format is TODO
   kal_int16 rsrqPath1[10];//final format is TODO

   kal_uint32 crcOK_cnt;
   kal_uint32 crcNG_cnt;
}ERfTestResultGetMixRxRpt;

typedef ERfTestResultGetMixRxRpt ERfTestCmdGetMixRxRpt;  // for backward compatible

typedef struct
{
   kal_uint8  mode;//0: DL Rx, 1: Tx-Rx, 2: Pseudo Tx-Rx

   /*Common parameters*/
   kal_uint8  measCnt[MAX_RX_CC_NUM];//range 0~10
   kal_uint8  measBandwidth[MAX_RX_CC_NUM];//0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
   kal_int16  afcdac;
   kal_uint16 dlFrequency[MAX_RX_CC_NUM];//range: 7280~26900 (100KHz unit)
   kal_uint8  band[MAX_RX_CC_NUM];//range 1~40
   kal_uint8  duplexMode;//0:tdd, 1:fdd
   kal_uint8  tddConfig[MAX_RX_CC_NUM];//range 0~7
   kal_uint8  tddSfConfig[MAX_RX_CC_NUM];//range 0~8
   kal_uint8  bandwidth;//(UL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
   kal_uint8  rxPath0Enbl;
   kal_uint8  rxPath1Enbl;

   /*Tx-Rx & Pseudo Tx-Rx only*/
   kal_uint16 ulFrequency;//range: 7280~26900 (100KHz unit)
   kal_int16  txPowerValue;/*S(8,8)*/

   /*Pseudo Tx-Rx only*/
   kal_uint8  vrbStart;
   kal_uint8  vrbLength;
   kal_uint8  mcsMode;
}ERfTestCmdMixRx_CaMode;

typedef struct
{
   kal_uint8 measRptCnt[MAX_RX_CC_NUM];//range 0~10
   kal_int16 rssiPath0[MAX_RX_CC_NUM][10];//final format is TODO
   kal_int16 rssiPath1[MAX_RX_CC_NUM][10];//final format is TODO
   kal_int16 rsrpPath0[MAX_RX_CC_NUM][10];//final format is TODO
   kal_int16 rsrpPath1[MAX_RX_CC_NUM][10];//final format is TODO
   kal_int16 rsrqPath0[MAX_RX_CC_NUM][10];//final format is TODO
   kal_int16 rsrqPath1[MAX_RX_CC_NUM][10];//final format is TODO

   kal_uint32 crcOK_cnt[MAX_RX_CC_NUM];
   kal_uint32 crcNG_cnt[MAX_RX_CC_NUM];
}ERfTestResultGetMixRxRpt_CaMode;

typedef ERfTestResultGetMixRxRpt_CaMode ERfTestCmdGetMixRxRpt_CaMode;  // for backward compatible

typedef struct
{
   /* PA Control */
   kal_uint8 paControlLevel; /* 2~8 */
   kal_uint8 calRoomTempIdx;
   kal_int16 hysteresisStart0;
   kal_int16 hysteresisEnd0;
   kal_int16 hysteresisStart1;
   kal_int16 hysteresisEnd1;
   kal_uint8 paMode[8]; /* 0:high, 1:middle, 2:low */
   kal_int16 pRf[8];
   kal_uint16 paGain[8];
   kal_uint8 dc2dcLevel[8]; /* voltage map by chip, TODO */
   kal_uint16 vBiasDac[8];
   kal_uint8 vm0[8];
   kal_uint8 vm1[8];
   /* TX Compensation */
   kal_uint16 ulFrequency[21];//100kHz unit
   kal_int16 paGainHigh[8][21];
   kal_int16 paGainMiddle[8][21];
   kal_int16 paGainLow[8][21];
   kal_int16 couplerLossHigh;
   kal_int16 couplerLossMiddle;
   kal_int16 couplerLossLow;
   kal_int16 powerDetectorHigh[8][21];
   kal_int16 powerDetectorMiddle[8][21];
   kal_int16 powerDetectorLow[8][21];
}ERfTestCmdGetSetTpcSetting;



/* the strict ordering MUST be kept */
typedef struct
{
   /*Struct should be 4 bytes alignment*/
   kal_uint32 supportBandMap[ERF_BAND_MAP_SIZE];            /*eg. Map[1]=0x3, it means we support band33, band34                           */
   kal_uint32 supportMipiBandMap[ERF_BAND_MAP_SIZE];        /*eg. Map[1]=0x3, it means we support MIPI at band33, band34                   */
   kal_uint32 supportCoexistenceBandMap[ERF_BAND_MAP_SIZE]; /*eg. Map[1]=0x3, it means we need to check wifi co-existence at band33, band34*/
   kal_uint32 supportDpdBandMap[ERF_BAND_MAP_SIZE];         /*eg. Map[1]=0x3, it means we support DPD calibration at band33, band34        */
   kal_uint32 supportCim3BandMap[ERF_BAND_MAP_SIZE];        /*eg. Map[1]=0x3, it means we support CIM3 calibration at band33, band34       */
   kal_uint32 supportHRMBandMap[ERF_BAND_MAP_SIZE];         /*eg. Map[1]=0x3, it means we need to check HRM at band33, band34*/
   kal_uint32 supportNCCAOneElnaBandMap[ERF_BAND_MAP_SIZE];     /*eg. Map[1]=0x3, it means we need to check elna individual cal at band33, band34*/
}ErfCapabilityItemSet;

/* DO NOT modify this structure */
typedef struct
{
   kal_uint32 is_capable  : 1;
   kal_uint32 is_mandatory: 1;
   kal_uint32 parameter   :30;

}ErfCalibrationItem;

/* the strict ordering MUST be kept */
typedef struct
{
   /*Struct should be 4 bytes alignment*/
   ErfCalibrationItem tadc_cal;                   /* 0: TADC calibration item                                 */
   ErfCalibrationItem multi_rat_tadc_bitmap;      /* 1: bit map of multi-rat TADC calibration                 */
   ErfCalibrationItem multi_rat_afc_bitmap;       /* 2: bit map of multi-rat AFC calibration                  */
   ErfCalibrationItem pd_temp_comp;               /* 3: Target support PD temperature compensation            */
   ErfCalibrationItem mipi_pa_level_and_cw_num;   /* 4: MIPI PA power level and codeword number for each level*/
   ErfCalibrationItem temperature_info;           /* 5: Temperature info. API                                 */
   ErfCalibrationItem et_module_support;          /* 6: support ET module or not                              */
   ErfCalibrationItem tool_usage_setting_support; /* 7: Support set tool usage or not                         */
   ErfCalibrationItem thermal_sensor_type;        /* 8: Report thermal sensor type (internal or external)     */
   ErfCalibrationItem cap_id_calibration;         /* 9: CAP ID calibration item                               */
   ErfCalibrationItem enable_csr;                 /*10: Enable CSR/MIB in Meta TX PUSCH mode                  */
   ErfCalibrationItem gps_co_tms_support;         /*11: Support GPS CO-TSX interface                          */
   ErfCalibrationItem lte_ca_support;             /*12: support LTE-A CA mode interface or not                */
   ErfCalibrationItem lte_ca_ena;                 /*13: Enable LTE-A CA mode interface or not                 */
   ErfCalibrationItem lte_dpd_support;            /*14: DPD calibration item                                  */
   ErfCalibrationItem lte_cim3_support;           /*15: CIM3 calibration item                                 */
   ErfCalibrationItem lte_Coexistence_support;    /*16: Coexistence calibration item                          */
   ErfCalibrationItem lte_HRM_support;            /*17: HRM         calibration item                          */
   ErfCalibrationItem fhc_sw_time;                /*18: For reporting FHC switch time to META tool            */
   ErfCalibrationItem nsft_extension;             /*19: For reporting NSFT extension supoort to META tool     */
   ErfCalibrationItem lte_tas_support;            /*20: For reporting LTE  TAS supoort (Only in MOLY)         */
   ErfCalibrationItem NCCABypassCheck;            /*21: For reporting NCCA Bypass check rx gain mode          */
   ErfCalibrationItem lte_generation_version;     /*22: For reporting generation version control              */
   ErfCalibrationItem lte_rftool_ui_version;      /*23: For reporting RF tool UI version control              */
   ErfCalibrationItem additional_palevel_support; /*24: For Factory cal PGA 12a 12b feature control           */
   ErfCalibrationItem lte_elna_support;           /*25: For lte elna feature support                          */
   ErfCalibrationItem lte_band2bitmap;            /*26: For lte band to bitmap mapping                        */
}ErfCalibrationItemSet;

/* the strict ordering MUST be kept calibrationItems & capabilityItems are variable part*/
typedef struct
{
   /*Struct should be 4 bytes alignment*/
   kal_uint32 rfId;                      /*Please use enmeration "ERfId"*/
   kal_uint32 capability_item_offset;    /*Erf capability item offset (byte unit) from structure begin */
   kal_uint32 calibration_item_offset;   /*Erf calibration item offset (byte unit) from structure begin*/
   ErfCapabilityItemSet  capabilityItems;
   ErfCalibrationItemSet calibrationItems;

}ERfTestResultRfCapability;

typedef struct
{
   kal_uint8 duplexMode;/* 0:tdd, 1:fdd */
   kal_uint8 band;
   kal_uint16 ulFrequency;/* range: 0~65535 (100KHz unit) */
   kal_uint8 capid;    /* 0 ~ 255 */
   kal_int16 afcdac;  /* 0 ~ 8191 */
   kal_uint8 afcDataType ; /* 0: calibration data, 1: interface */
   kal_int16 txPowerValue;/*S(8,8),  x dB * 256.0 */
}ERfTestCmdAfcSingleToneTx;

typedef struct
{
   kal_uint8     capid;       /* 0 ~ 255 */
   kal_uint16    afcdac;     /* 0 ~ 8191 */
   kal_int32     slopeInv;
}ERfFreqAdjustTable;

typedef struct
{
   kal_uint8 duplexMode;/* 0:tdd, 1:fdd */
   kal_uint8 band;
   kal_uint16 ulFrequency;/* range: 0~65535 (100KHz unit) */
   kal_uint8 bandwidth;//(UL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
   kal_int16 ulFrequencyOffset;/* range: -32768~32767 (unit:15KHz) */
   kal_int16 afcdac;
   kal_uint8 afcDataType ; /* 0: calibration data, 1: interface */
   kal_int16 txPowerValue;/*S(8,8), x dB * 256.0 */
   kal_uint8 txCloseLoopDisbl;
   kal_uint8 paMode; //UI doesn't take this value to low level
}ERfTestCmdTpcSingleToneTx;

typedef struct
{
   kal_uint8   band; /* 1~40 */
   kal_int16   txPaGain[8]; /* resolution 1/32 */
}ERfTestCmdSetTpcPaGain;

typedef struct
{
   kal_uint8   duplexMode;/* 0:tdd, 1:fdd */
   kal_uint8   band; /* 1~40 */
   kal_uint8   num_freq; /* 1~36 */
   kal_uint16  dl_freq[36];
   kal_uint8   temperatureIndex; /* 0~7 */
   kal_int16   gain1; /* resolution 1/32 */
   kal_int16   gain2; /* resolution 1/32 */
}ERfTestCmdRSSI;

typedef struct
{
   kal_uint8  duplexMode;/* 0:tdd, 1:fdd */
   kal_uint8   band; /* 1~40 */
   kal_uint16  dl_freq;
   kal_uint8   bandwidth;//(DL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
   kal_uint16 gain1; /* main path, resolution 1/32 */
   kal_uint16 gain2;  /* diversity path, resolution 1/32 */
} ERfTestCmdContRx;

typedef struct
{
   kal_uint8 duplexMode;/* 0:tdd, 1:fdd */
   kal_uint8 ca_comb_tbl_idx;/* 0~127 */
   kal_uint16 dl_freq[MAX_RX_CC_NUM];
   kal_uint8 bandwidth[MAX_RX_CC_NUM];//(DL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
   kal_uint16 gain1[MAX_RX_CC_NUM]; /* main path, resolution 1/32 */
   kal_uint16 gain2[MAX_RX_CC_NUM]; /* rx diversity path, resolution 1/32 */
} ERfTestCmdContRx_CaMode;

typedef struct
{
   kal_uint8   num_freq;
   kal_int16   dl_freq[36];
   kal_int16   rssi[36]; /* resolution 1/32 */
   kal_uint8   lna_mode[36]; /* 0 ~ 5 */
   kal_int16   rssi_rxd[36]; /* resolution 1/32 */
   kal_uint8   lna_mode_rxd[36]; /* 0 ~ 5 */
}ERfTestResultRSSI;

typedef struct
{
   kal_int16  lna_mode[6]; //loss of mode 0~5; resolution 1/32
}ERfRSSIGainOffsetTable;

typedef struct
{
   ERfRSSIGainOffsetTable gain_of_dl_freq[15];
}ERfRSSITempOffsetTable;

typedef struct
{
   kal_uint16 dlMainFrequency[15];
   kal_uint16 dlDiversityFrequency[15];
   ERfRSSITempOffsetTable  pathlossMainData[8];
   ERfRSSITempOffsetTable  pathlossDiversityData[8];
}ERfRSSIBandGainTable;

/*********************\
|* CA Mode Structure *|
\*********************/
typedef struct
{
   kal_uint8   duplexMode;                 /* 0:tdd, 1:fdd */
   kal_uint8   ca_comb_tbl_idx;            /* 0~127 */
   kal_uint8   num_freq;                   /* 1~36 */
   kal_uint16  dl_freq[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX];
   kal_uint8   temperatureIndex;           /* 0~7 */
   kal_int16   gain1[MAX_RX_CC_NUM];       /* resolution 1/32 */
   kal_int16   gain2[MAX_RX_CC_NUM];       /* resolution 1/32 */
}ERfTestCmdRSSI_CaMode;

typedef struct
{
   kal_uint8   num_freq;
   kal_int16   dl_freq[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX];
   kal_int16   rssi[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX];         /* resolution 1/32 */
   kal_uint8   lna_mode[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX];     /* 0 ~ 5 */
   kal_int16   rssi_rxd[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX];     /* resolution 1/32 */
   kal_uint8   lna_mode_rxd[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX]; /* 0 ~ 5 */
}ERfTestResultRSSI_CaMode;

typedef struct
{
   kal_int16   lna_mode[MAX_RX_LNA_MODE_NUM];  // loss of mode 0~5; resolution 1/32
}ERfRSSIGainOffsetTable_Type1;

typedef struct
{
   kal_int16   lna_mode[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM]; // loss of mode 0~5, PCC & SCC; resolution 1/32
}ERfRSSIGainOffsetTable_Type2;

typedef struct
{
   kal_int16   temp_comp[MAX_TEMP_SECTION_NUM];
}ERfRSSITempOffsetTable_Ex;

typedef struct
{
   kal_uint8   bandIndex;
   kal_uint8   routeIndex;
   kal_uint16  subbandFrequency[MAX_FHC_RX_FREQ_NUM_EX];
   ERfRSSIGainOffsetTable_Type1 pathlossMainData[MAX_FHC_RX_FREQ_NUM_EX];
   ERfRSSIGainOffsetTable_Type1 pathlossDiversityData[MAX_FHC_RX_FREQ_NUM_EX];
   ERfRSSITempOffsetTable_Ex pathlossTempData;
}ERfRSSIBandGainTable_Type1;

typedef struct
{
   kal_uint8   bandIndex;
   kal_uint8   routeIndex;
   kal_uint16  subbandFrequency[MAX_FHC_RX_FREQ_NUM_EX];
   ERfRSSIGainOffsetTable_Type2 pathlossMainData[MAX_FHC_RX_FREQ_NUM_EX];
   ERfRSSIGainOffsetTable_Type2 pathlossDiversityData[MAX_FHC_RX_FREQ_NUM_EX];
   ERfRSSITempOffsetTable_Ex pathlossTempData;
}ERfRSSIBandGainTable_Type2;

typedef union
{
   ERfRSSIBandGainTable_Type1  t1_tbl;
   ERfRSSIBandGainTable_Type2  t2_tbl;
}ERfRSSIBandGainTable_Ex;

typedef struct
{

    kal_uint32      result;    // 1: support 0: not support
    kal_uint32      query_op_code;  // query op code
}ERfCheckIfFuncExist;

typedef struct
{
    kal_uint16 data[8];
} ERfTadcSetting;

typedef struct
{
    kal_uint16 measure_count;
} ERfTestCmdGetRfTemp;

typedef struct
{
    kal_uint16 rf_band_idx;
    kal_uint16 power_level_num;
    kal_uint16 code_word_num;
}ERfTestCmdSetMIPICodeWord;

typedef struct
{
    kal_uint8  mipi_rf_band;
}ERfTestCmdGetMIPICodeWord;

typedef struct
{
   kal_uint16  CmdType;
   kal_uint8   BandIndex;
}ERfNVRAMInfoReq;

typedef struct
{
   kal_uint8   status;     // 0: read ok; others: read failed.
   kal_uint8   lid_count;  // NVRAM information number(s)
}ERfNVRAMInfoCnf;

typedef struct
{
   kal_uint16  LID;        // Logical data item ID of a EF
   kal_uint16  RID;        // Record ID (the first record is 1)
}ERfGetNVRAMInfo;

typedef struct
{
   kal_uint8   band;
   kal_uint8   bandwidth;
   kal_int16   txPower;
   kal_uint16  ulFrequency;
}ERfEtTxSetting;

typedef struct
{
   kal_uint8   output_vpa_voltage;
}ERfFdModeSetting;

typedef struct 
{
   kal_uint16  mode; // ET:0 FD:1 Bypass:2
   kal_int16   outer_gain;
   kal_int16   input_offset_voltage;
   kal_int16   main_sw_output_voltage;
   kal_int16   aux_sw_output_voltage;
}ERfSpModeSetting;

typedef struct
{
   kal_uint16 et_mode; // ET:0 FD:1 SP:2
   ERfEtTxSetting tx_setting;
   ERfFdModeSetting fd_mode_setting;
   ERfSpModeSetting sp_mode_setting;
}ERfTestCmdEtModeSetting;

typedef struct
{
   /* all entries in this struct are "per band" */
   kal_uint16 VinVpaLut[8][33]; /* by subband, by number of Pin */
   kal_int16  VinPmLut [8][33]; /* by subband, by number of Pin */
   kal_int16  VinAmLut [8][33]; /* by subband, by number of Pin */
#ifdef ET_CAL_PATH_DELAY_CAL_BY_SUBBAND
   kal_int16  PathDelay[8][6];  /* by subband, by number of CBWs */
#else
   kal_int16  PathDelay[6];     /* by number of CBWs */
#endif
   kal_int16  Pout_max[8];
   kal_int16  Pout_gain_offset[8];
   kal_uint16 GainComp_0p5_dB;
   kal_uint16 GainComp_0p5_dB_delta;
   kal_int16  PathDelayOffsetByTemp [8][6];
   kal_int16  GrpDlyOfstBySubband   [8][6];
   kal_uint16 VpaTargetStep2;
   kal_uint16 SmpValStep2Sec1;
   kal_int16  PaGainAdjustStep1;
   kal_uint32 PowThrdStep2;
}ERfTestCmdEtCalResult;

typedef struct
{
   kal_uint16 rf_band_idx;       /*this is Band, B1, B2, B5, B7,...*/
}ERfTestCmdEtCalSetting;

typedef struct
{
   kal_int32 C0;
   kal_int32 C1;
   kal_int32 initU;
   kal_int32 lastU;
}ERfGpsCoClockData;

typedef struct
{
   kal_uint8  rf_band;
   kal_uint8  vco_lna_port_cfg_index;
   kal_uint8  is_lna_low_power_mode;  // 0: HPM, 1: LPM
}ERfTestCmdSetRxCommonCfg;

typedef struct
{
   /*Struct should be 4 bytes alignment*/
   kal_uint32                       support_route_map[MAX_ROUTE_NUM_IN_WORD];
   kal_uint32                       ltea_vco_srx_sel;
   ERfTestSupportVcoSrxLnaCfg       support_vco_srx_lna_cfg[ERF_MAX_BAND_NUM];
   ERfTestVarTblInfo                ca_comb_tbl;
   ERfTestSupportCaCombTblIdx       support_ca_cfg_tbl_idx[ERF_MAX_BAND_NUM];
   ERfTestVarTblInfo                rx_usg_tbl;
   ERfTestSupportRxUsageByBand      support_rx_usage_by_band[ERF_MAX_BAND_NUM];
   ERfTestSupportCaCalDim           ca_cal_dim[ERF_MAX_BAND_NUM];
   ERfTestSupportRxGainModeMask     support_rx_gain_mode_mask;
   ERfTestSupportRxGain             support_rx_gain_mode_setting;
   ERfTestNccaGbgBypassCheck        ncca_gbg_bypass_check_setting;
   kal_uint32                       band_mapping_table[ERF_BAND_MAPPING_TBL_SIZE];
}ERfTestCmdCaConfig;

typedef union
{
   ERfTestCmdPuschTx          puschTxParam;          // for ERF_TEST_CMD_START_PUSCH_TX           = 0
   ERfTestCmdPucchTx          pucchTxParam;          // for ERF_TEST_CMD_START_PUCCH_TX           = 1
   ERfTestCmdPrachTx          prachTxParam;          // for ERF_TEST_CMD_START_PRACH_TX           = 2
   ERfTestCmdSrsTx            srsTxParam;            // for ERF_TEST_CMD_START_SRS_TX             = 3
   ERfTestCmdMixRx            mixRxParam;            // for ERF_TEST_CMD_START_MIX_RX             = 4
   ERfTestCmdMixRx_CaMode     mixRxParamCaMode;      // for ERF_TEST_CMD_START_MIX_RX_CA_Mode     = 46
   kal_uint8                  tpcSettingBandIndex;   // for ERF_TEST_CMD_SET_TX_TPC_SETTING       = 8
                                                     // for ERF_TEST_CMD_GET_TX_TPC_SETTING       = 9
   ERfTestCmdRSSI             rssiRxParam;           // for ERF_TEST_CMD_START_RSSI               = 17
   ERfTestCmdRSSI_CaMode      rssiRxParamCaMode;     // for ERF_TEST_CMD_START_RSSI_CA_MODE       = 42
   ERfTestRSSITableType       rssiTableType;         // for ERF_TEST_CMD_SET_RSSI_SETTING_EX      = 45
   ERfTestAntSel              rxAntSel;              // for ERF_TEST_CMD_RX_ANT_Path_SEL          = 74
   ERfTestCmdContRx           contRxParam;           // for ERF_TEST_CMD_START_CONT_RX            = 26
   ERfTestCmdContRx_CaMode    contRxParamCaMode;     // for ERF_TEST_CMD_START_CONT_RX_CA_MODE    = 43
   ERfTestCmdAfcSingleToneTx  afcSingleToneTxParam;  // for ERF_TEST_CMD_START_AFC_SINGLE_TONE_TX = 11
   ERfTestCmdTpcSingleToneTx  tpcSingleToneTxParam;  // for ERF_TEST_CMD_START_TPC_SINGLE_TONE_TX = 14
   ERfTestCmdSetTpcPaGain     tpcPaGainSetting;      // for ERF_TEST_CMD_SET_TPC_PA_GAIN          = 15
   kal_uint8                  rxRSSITableBandIndex;  // for ERF_TEST_CMD_GET_RSSI_SETTING         = 18
                                                     // for ERF_TEST_CMD_SET_RSSI_SETTING         = 19
   kal_uint8                  rxRSSITableRouteIndex; // for ERF_TEST_CMD_GET_RSSI_SETTING_EX      = 44
   ERfTestCmdType             query_op_code;         // for ERF_TEST_CMD_CHECK_IF_FUNC_EXIST      = 21
   ERfTestCmdGetRfTemp        getRfTemp;             // for ERF_TEST_CMD_GET_RF_TEMP              = 22
   ERfTestCmdSetMIPICodeWord  setMipiCodeWord;       // for ERF_TEST_CMD_SET_RF_MIPI_CODEWORD     = 27
   ERfTestCmdGetMIPICodeWord  getMipiCodeWord;       // for ERF_TEST_CMD_GET_RF_MIPI_CODEWORD     = 28
   ERfNVRAMInfoReq            nvramInfoReq;          // for ERF_TEST_CMD_QUERY_NVRAM_LID          = 36
   ERfTestCmdEtModeSetting    EtModeSetting;         // for ERF_TEST_CMD_SET_ET_MODE              = 30
   ERfTestCmdEtCalSetting     etCalSetting;          // for ERF_TEST_CMD_START_ETCAL              = 32
                                                     // for ERF_TEST_CMD_GET_ETCAL_SETTING        = 33
                                                     // for ERF_TEST_CMD_SET_ETCAL_SETTING        = 34
   ERfGpsCoClockData          gpsCoClockData;        // for ERF_TEST_CMD_SET_GPS_CO_CLOCK_DATA    = 38
   kal_uint16                 toolUsage;             // for ERF_TEST_CMD_SET_TOOL_USAGE_TO_L1     = 35
   ERfTestCmdSetRxCommonCfg   setRssiNonCaConfig;    // for ERF_TEST_CMD_SET_LNA_SRX              = 41

   kal_uint8                  isLocalParamBeUsed;    // for ERF_TEST_CMD_GET_MIX_RX_RPT           = 5
                                                     // for ERF_TEST_CMD_RESET_COUNTER            = 6
                                                     // for ERF_TEST_CMD_STOP_TEST_MODE           = 7
                                                     // for ERF_TEST_CMD_GET_RF_CAPABILITY        = 10
                                                     // for ERF_TEST_CMD_SET_AFC_SETTING          = 12
                                                     // for ERF_TEST_CMD_GET_AFC_SETTING          = 13
                                                     // for ERF_TEST_CMD_GET_POWER_DETECTOR_VALUE = 16
                                                     // for ERF_TEST_CMD_START_FHC                = 20
                                                     // for ERF_TEST_CMD_GET_TADC_SETTING         = 23
                                                     // for ERF_TEST_CMD_SET_TADC_SETTING         = 24
                                                     // for ERF_TEST_CMD_START_NSFT_LIST          = 25
                                                     // for ERF_TEST_CMD_GET_TEMPERATURE_INFO     = 29
                                                     // for ERF_TEST_CMD_SET_PATH_FLAG            = 31
                                                     // for ERF_TEST_CMD_GET_GPS_CO_CLOCK_DATA    = 37
                                                     // for ERF_TEST_CMD_GET_MIX_RX_CA_MODE_RPT   = 47
                                                     // for ERF_TEST_CMD_QUERY_CA_CONFIG_TABLE    = 48
                                                     // for ERF_TEST_CMD_START_FHC_CA_MODE        = 49
}ERfTestCmdParam;

typedef struct
{
    kal_bool   ok;
    kal_uint32 sum;
} ERfTestResultRfTemperature;

typedef struct
{
    kal_uint32 result;
    kal_uint8  l1cStatus;
} ERfTestResultGeneralResult;

typedef ERfTestResultGeneralResult ERfTestCmdGeneralResult;  // for backward compatible

typedef struct
{
    kal_uint32 result;
    kal_uint8  l1cStatus;
    kal_uint8  withParam;
} ERfTestResultNsftResult;

typedef ERfTestResultNsftResult ERfTestCmdNsftResult;  // for backward compatible
typedef struct
{
    kal_uint8  status;
    kal_uint16 power_level_num;
    kal_uint16 code_word_num;
}ERfTestResultGetMIPICodeWord;

typedef struct
{
    kal_int16 status;
    kal_int16 tadc_dac;
    kal_int16 temperature;
    kal_int16 temp_idx;
}ERfTestResultRfTemperatureInfo;

typedef enum
{
    ERF_GTI_STATUS_SUCCESS        = 0,
    ERF_GTI_STATUS_INTERPO_FAIL   = 1,
    ERF_GTI_STATUS_TEMP_OVERFLOW  = 2,
    ERF_GTI_STATUS_TEMP_UNDERFLOW = 3
}ERfTestGetTempInfoStatus;

typedef struct
{
   kal_uint32 result;         // command deliver status
   kal_uint32 rssiSetResult;  // data set status
}ERfTestResultSetRssi;

typedef struct
{
   kal_uint32 result;
   kal_uint32 rssiTableType;  // you may use ERfTestRSSITableType to cast it
}ERfTestResultGetRssi;

typedef struct
{
   kal_uint32 result;         // command deliver status
   kal_uint32 tpcSetResult;   // data set status
}ERfTestResultSetTPC;


typedef union
{
   kal_uint32                        result;               // for ERF_TEST_CMD_START_PUSCH_TX           = 0
                                                           // for ERF_TEST_CMD_START_PUCCH_TX           = 1
                                                           // for ERF_TEST_CMD_START_PRACH_TX           = 2
                                                           // for ERF_TEST_CMD_START_SRS_TX             = 3
                                                           // for ERF_TEST_CMD_RESET_COUNTER            = 6
                                                           // for ERF_TEST_CMD_STOP_TEST_MODE           = 7
                                                           // for ERF_TEST_CMD_GET_TX_TPC_SETTING       = 9
                                                           // for ERF_TEST_CMD_START_AFC_SINGLE_TONE_TX = 11
                                                           // for ERF_TEST_CMD_SET_AFC_SETTING          = 12
                                                           // for ERF_TEST_CMD_GET_AFC_SETTING          = 13
                                                           // for ERF_TEST_CMD_START_TPC_SINGLE_TONE_TX = 14
                                                           // for ERF_TEST_CMD_SET_TPC_PA_GAIN          = 15
                                                           // for ERF_TEST_CMD_START_RSSI               = 17
                                                           // for ERF_TEST_CMD_GET_RSSI_SETTING         = 18
                                                           // for ERF_TEST_CMD_SET_RSSI_SETTING         = 19
                                                           // for ERF_TEST_CMD_START_FHC                = 20
                                                           // for ERF_TEST_CMD_GET_TADC_SETTING         = 23
                                                           // for ERF_TEST_CMD_SET_TADC_SETTING         = 24
                                                           // for ERF_TEST_CMD_START_CONT_RX            = 26
                                                           // for ERF_TEST_CMD_SET_RF_MIPI_CODEWORD     = 27
                                                           // for ERF_TEST_CMD_SET_PATH_FLAG            = 31
                                                           // for ERF_TEST_CMD_SET_GPS_CO_CLOCK_DATA    = 38
                                                           // for ERF_TEST_CMD_SET_LNA_SRX              = 41
                                                           // for ERF_TEST_CMD_START_RSSI_CA_MODE       = 42
                                                           // for ERF_TEST_CMD_START_CONT_RX_CA_MODE    = 43
                                                           // for ERF_TEST_CMD_START_FHC_CA_MODE        = 49
   ERfTestResultGeneralResult        generalResult;        // for ERF_TEST_CMD_START_MIX_RX             = 4
   ERfTestResultNsftResult           nsftResult;           // for ERF_TEST_CMD_START_NSFT_LIST          = 25
                                                           // for ERF_TEST_CMD_START_MIX_RX_CA_Mode     = 46
   ERfTestResultGetMixRxRpt          mixRxRpt;             // for ERF_TEST_CMD_GET_MIX_RX_RPT           = 5
   ERfTestResultGetMixRxRpt_CaMode   mixRxRptCaMode;       // for ERF_TEST_CMD_GET_MIX_RX_CA_MODE_RPT   = 47
   ERfTestResultRfTemperature        rfTemperature;        // for ERF_TEST_CMD_GET_RF_TEMP              = 22
   ERfTestResultRfTemperatureInfo    rfTemperatureInfo;    // for ERF_TEST_CMD_GET_TEMPERATURE_INFO     = 29
   kal_int16                         txPowerDetectorValue; // for ERF_TEST_CMD_GET_POWER_DETECTOR_VALUE = 16
   ERfCheckIfFuncExist               CheckIfFuncExist;     // for ERF_TEST_CMD_CHECK_IF_FUNC_EXIST      = 21
   ERfTestResultGetMIPICodeWord      getMipiCodeWord;      // for ERF_TEST_CMD_GET_RF_MIPI_CODEWORD     = 28
   ERfNVRAMInfoCnf                   nvramInfoCnf;         // for ERF_TEST_CMD_QUERY_NVRAM_LID          = 36
   ERfGpsCoClockData                 gpsCoClockData;       // for ERF_TEST_CMD_GET_GPS_CO_CLOCK_DATA    = 37
   ERfTestResultSetRssi              setRssiResult;        // for ERF_TEST_CMD_SET_RSSI_SETTING_EX      = 45
   ERfTestResultGetRssi              getRssiResult;        // for ERF_TEST_CMD_GET_RSSI_SETTING_EX      = 44
   ERfTestResultSetTPC               setTPCResult;         // for ERF_TEST_CMD_SET_TX_TPC_SETTING       = 8

   kal_uint8                         isLocalParamBeUsed;   // for ERF_TEST_CMD_GET_RF_CAPABILITY        = 10
                                                           // for ERF_TEST_CMD_QUERY_CA_CONFIG_TABLE    = 48
}ERfTestResultParam;

#ifndef  __LTE_L1SIM__
typedef struct
{
   FT_HDR
   ERfTestCmdType type;
   ERfTestCmdParam param;
}FT_ERF_TEST_REQ;

typedef struct
{
   FT_HDR
   ERfTestCmdType type;
   ERfTestResultParam param;
}FT_ERF_TEST_CNF;

typedef FT_ERF_TEST_REQ dhl_to_el1tst_struct;
typedef FT_ERF_TEST_CNF el1tst_to_dhl_struct;

typedef FT_ERF_TEST_REQ dhl_to_etstm_struct;
typedef FT_ERF_TEST_CNF etstm_to_dhl_struct;
#endif

typedef struct
{
   kal_uint16 dl_freq;//100kHz unit
   kal_int16   rssi[MAX_PWR_STEP_NUM];
   kal_int16   rssi_rxd[MAX_PWR_STEP_NUM];
   kal_uint8   lna_mode[MAX_PWR_STEP_NUM];
   kal_uint8   lna_mode_rxd[MAX_PWR_STEP_NUM];
   kal_uint8   pwr_step_num;
}FHC_Rx_Freq_Rpt;

typedef struct
{
   kal_uint16 ul_freq;//100kHz unit
   kal_int16 txPowerDetectorValue[MAX_PWR_STEP_NUM];
   kal_uint8 pwr_step_num;
}FHC_Tx_Freq_Rpt;

typedef struct
{
   kal_uint8 band_index;
   kal_uint8   tx_freq_num;
   kal_uint8   rx_freq_num;
   FHC_Tx_Freq_Rpt tx_freq_rpt[MAX_FHC_TX_FREQ_NUM];
   FHC_Rx_Freq_Rpt rx_freq_rpt[MAX_FHC_RX_FREQ_NUM];
}FHC_TRx_Band_Rpt;

typedef struct
{
   kal_uint8 band_num;
   FHC_TRx_Band_Rpt band_rpt[MAX_FHC_BAND_NUM];
}FHC_Rx_Rpt;

typedef struct
{
   kal_uint16 ul_freq;//100kHz unit
   kal_uint8   ul_bw;//0(1.4M)~5(20M)
   kal_uint8   pwr_step_num;
   kal_int16   pwr_step_value[MAX_PWR_STEP_NUM];//S(8, 8)
   kal_int16   pwr_step_pa_gain [MAX_PWR_STEP_NUM];
   kal_uint8   pwr_step_pa_gain_tbl_indx [MAX_PWR_STEP_NUM];
   kal_uint8   pwr_step_pa_mode [MAX_PWR_STEP_NUM];
}FHC_Tx_Freq_Param;

typedef struct
{
   kal_uint16 dl_freq;//100kHz unit
   kal_uint8   temperature_indx;
   kal_uint8   pwr_step_num;
   kal_int16   gain1[MAX_PWR_STEP_NUM];
   kal_int16   gain2[MAX_PWR_STEP_NUM];
}FHC_Rx_Freq_Param;

typedef struct
{
   kal_uint8 band_index;
   kal_uint8   freq_num;
   FHC_Tx_Freq_Param freq_param[MAX_FHC_TX_FREQ_NUM];
}FHC_Tx_Band_Param;

typedef struct
{
   kal_uint8 band_index;
   kal_uint8   freq_num;
   FHC_Rx_Freq_Param freq_param[MAX_FHC_RX_FREQ_NUM];
}FHC_Rx_Band_Param;

typedef struct
{
   kal_uint8 tx_to_rx_time;//ms unit
   kal_uint8 band_num;
   FHC_Rx_Band_Param band_param[MAX_FHC_BAND_NUM];
}FHC_Rx_Cfg;

typedef struct
{
   kal_uint8  tx_step_width;//ms unit
   kal_uint8 band_num;
   FHC_Tx_Band_Param band_param[MAX_FHC_BAND_NUM];
   kal_int16   freq_offst;//range -32768~32767
   kal_int16   afc_dac;
   kal_uint8   afc_data_type;//0: calibration data, 1: from interface value
   kal_uint8   close_loop_disable;
}FHC_Tx_Cfg;

typedef struct
{
    kal_uint8 phy_cell_id;//no used for single tone?
    kal_uint8 fdd_band_start_index;
    kal_uint8 fdd_band_end_index;
    kal_uint8 tdd_band_start_index;
    kal_uint8 tdd_band_end_index;
    kal_uint8 fdd_to_tdd_switch_time;//ms unit
    kal_uint8 tdd_to_fdd_switch_time;//ms unit
    kal_uint8 tdd_tx_rx_switch_time;//ms unit
    kal_uint8 freq_switch_time;//ms unit
    kal_uint8 band_switch_time;//ms unit
    FHC_Tx_Cfg txCmd;
    FHC_Rx_Cfg rxCmd;
}FHC_Cmd;

typedef struct
{
   kal_uint8   pwr_step_num;//0~8;
   kal_int16   pwr_step_tx_power[8];//S(8,8)
   kal_uint8 pwr_step_VRB_strt [8];
   kal_uint8   pwr_step_VRB_len [8];
} NSFT_List_Tx_Specify_Pwr_Param;

typedef struct
{
   kal_int16   start_power; //S(8,8)
   kal_int16   pwr_step_value; //S(8,8)
   kal_uint8   pwr_step_num;

   kal_uint8   pwr_step_VRB_strt_p1; //start VRB for the first period
   kal_uint8   pwr_step_VRB_len_p1;
   kal_uint8   pwr_step_VRB_strt_p2; //start VRB for the second period
   kal_uint8   pwr_step_VRB_len_p2;

   kal_uint8   step_for_change_tx_VRB; //0: Tx VRB will be changed to p2 at step 0

} NSFT_List_Tx_Specify_Step_Param;

typedef struct
{
   kal_uint16 ul_freq;//100kHz unit
   kal_uint8   ul_bw;//0(1.4M)~5(20M)
   kal_uint8   pwr_step_MCS_mode; //0:QPSK, 1:16QAM, 2:64QAM
   kal_bool cmd_type;   //0: NSFT_List_Tx_Specify_Pwr_Param, 1: NSFT_List_Tx_Specify_Step_Param, 0xFF: invalid type
   union
   {
       NSFT_List_Tx_Specify_Pwr_Param specify_tx_pwr_cmd;
       NSFT_List_Tx_Specify_Step_Param specify_pwr_step_cmd;
   }nsft_list_pwr_step_cmd;
} NSFT_List_Tx_Freq_Param;

typedef struct
{
   kal_uint8 band_index;
   kal_uint8   freq_num;
   kal_uint16 dl_sync_freq;
   NSFT_List_Tx_Freq_Param freq_param[MAX_NSFT_LIST_TX_FREQ_NUM];
} NSFT_List_Tx_Band_Param;

typedef struct
{
   kal_uint8 fdd_tx_step_width;//ms unit
   kal_uint8 tdd_tx_step_width;//ms unit
   kal_uint8 band_num;
   NSFT_List_Tx_Band_Param band_param[MAX_NSFT_LIST_TX_BAND_NUM];
   kal_int16   freq_offst;//range -32768~32767
   kal_int16   afc_dac;
   kal_uint8   afc_data_type;//0: calibration data, 1: from interface value
   kal_uint8   close_loop_disable;
}NSFT_List_Tx_Cfg;

typedef struct NSFT_List_Cmd
{
   kal_uint8 phy_cell_id;//no used for single tone?
   kal_uint8 fdd_band_start_index;//0xFF if there is no FDD band.
   kal_uint8 fdd_band_end_index;//0xFF if there is no FDD band.
   kal_uint8 tdd_band_start_index;//0xFF if there is no TDD band.
   kal_uint8 tdd_band_end_index;//0xFF if there is no TDD band.
   kal_uint8 fdd_to_tdd_switch_time;//ms unit
   kal_uint8 fdd_freq_switch_time;//ms unit
   kal_uint8 tdd_freq_switch_time;//ms unit
   kal_uint8 fdd_band_switch_time;//ms unit
   kal_uint8 tdd_band_switch_time;//ms unit
   kal_uint16 fdd_dl_sync_time;//ms unit
   kal_uint16 tdd_dl_sync_time;//ms unit
   NSFT_List_Tx_Cfg txCmd;
}NSFT_List_Cmd;

//nsft hrm/filter switch mode
typedef struct
{
   kal_uint16  ul_freq;//100kHz unit
   kal_uint8   ul_bw;//0(1.4M)~5(20M)
   kal_uint8   pwr_step_MCS_mode; //0:QPSK, 1:16QAM, 2:64QAM
   kal_bool    cmd_type;   //0: NSFT_List_Tx_Specify_Pwr_Param, 1: NSFT_List_Tx_Specify_Step_Param, 0xFF: invalid type
   union
   {
       NSFT_List_Tx_Specify_Pwr_Param  specify_tx_pwr_cmd;
       NSFT_List_Tx_Specify_Step_Param specify_pwr_step_cmd;
   }nsft_list_pwr_step_cmd;
   kal_uint8 single_path;	//0:normal, 1:hrm, 2:filter
} NSFT_List_Tx_Freq_Ex_Param;

typedef struct
{
   kal_uint8   band_index;
   kal_uint8   freq_num;
   kal_uint16  dl_sync_freq;
   NSFT_List_Tx_Freq_Ex_Param freq_param[MAX_NSFT_LIST_TX_FREQ_NUM];
} NSFT_List_Tx_Band_Ex_Param;

typedef struct
{
   kal_uint8   fdd_tx_step_width;//ms unit
   kal_uint8   tdd_tx_step_width;//ms unit
   kal_uint8   band_num;
   NSFT_List_Tx_Band_Ex_Param band_param[MAX_NSFT_LIST_TX_BAND_NUM];
   kal_int16   freq_offst;//range -32768~32767
   kal_int16   afc_dac;
   kal_uint8   afc_data_type;//0: calibration data, 1: from interface value
   kal_uint8   close_loop_disable;
}NSFT_List_Tx_Ex_Cfg;

typedef struct NSFT_List_Ex_Cmd
{
   kal_uint8   phy_cell_id;//no used for single tone?
   kal_uint8   fdd_band_start_index;//0xFF if there is no FDD band.
   kal_uint8   fdd_band_end_index;//0xFF if there is no FDD band.
   kal_uint8   tdd_band_start_index;//0xFF if there is no TDD band.
   kal_uint8   tdd_band_end_index;//0xFF if there is no TDD band.
   kal_uint8   fdd_to_tdd_switch_time;//ms unit
   kal_uint8   fdd_freq_switch_time;//ms unit
   kal_uint8   tdd_freq_switch_time;//ms unit
   kal_uint8   fdd_band_switch_time;//ms unit
   kal_uint8   tdd_band_switch_time;//ms unit
   kal_uint16  fdd_dl_sync_time;//ms unit
   kal_uint16  tdd_dl_sync_time;//ms unit
   NSFT_List_Tx_Ex_Cfg txCmd;
}NSFT_List_Ex_Cmd;

/********************* MT6291 Structure Definitions *********************/

/********************* FHC REPORT *********************/
typedef struct
{
   kal_uint16  dl_freq;//100kHz unit
   kal_int16   rssi_m[MAX_RX_LNA_MODE_NUM];
   kal_int16   rssi_d[MAX_RX_LNA_MODE_NUM];
}FHC_Rx_Type1_Freq_Rpt;

typedef struct
{
   kal_uint16  dl_freq;//100kHz unit
   kal_int16   rssi_m[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM];
   kal_int16   rssi_d[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM];
}FHC_Rx_Type2_Freq_Rpt;

typedef struct
{
   kal_uint8              route_index;
   kal_uint8              band_index;  //real band number,  ex. band_index=LTE_BAND26
   kal_uint8              rx_freq_num;
   FHC_Rx_Type1_Freq_Rpt  rx_freq_rpt[MAX_FHC_RX_FREQ_NUM_EX];
}FHC_Rx_Type1_Route_Rpt;

typedef struct
{
   kal_uint8              route_index;
   kal_uint8              band_index;  //real band number,  ex. band_index=LTE_BAND26
   kal_uint8              rx_freq_num;
   FHC_Rx_Type2_Freq_Rpt  rx_freq_rpt[MAX_FHC_RX_FREQ_NUM_EX];
}FHC_Rx_Type2_Route_Rpt;

typedef struct
{
   kal_uint16  ul_freq;      //100kHz unit
   kal_int16   txPowerDetectorValue[MAX_TX_RPT_NUM];
}FHC_Tx_Type1_Freq_Rpt;

typedef struct
{
   kal_uint8             route_index;  //route_index = X th calibration Band
   kal_uint8             band_index;   //real band number,  ex. band_index=LTE_BAND26
   kal_uint8             tx_freq_num;
   FHC_Tx_Type1_Freq_Rpt tx_freq_rpt[MAX_FHC_TX_FREQ_NUM_EX];
}FHC_Tx_Type1_Route_Rpt;

typedef struct
{
   kal_uint8               rx_type1_route_num;
   kal_uint8               rx_type2_route_num;
   kal_uint8               tx_type1_route_num;
   FHC_Rx_Type1_Route_Rpt  rx_type1_rpt[MAX_FHC_RX_TYPE1_ROUTE_NUM];
   FHC_Rx_Type2_Route_Rpt  rx_type2_rpt[MAX_FHC_RX_TYPE2_ROUTE_NUM];
   FHC_Tx_Type1_Route_Rpt  tx_type1_rpt[MAX_FHC_TX_TYPE1_ROUTE_NUM];
}FHC_CaMode_Rpt;

typedef struct
{
   FHC_CaMode_Rpt *fhc_rpt_mem_addr;
}EL1TST_HISR_REQ_PARAM;

typedef struct
{
#ifdef  __LTE_L1SIM__
   kal_uint8   ref_count;
   kal_uint8   lp_reserved;
   kal_uint16  msg_len;
#else
   LOCAL_PARA_HDR
#endif
   EL1TST_HISR_REQ_PARAM  param;
}EL1TST_HISR_REQ;

typedef EL1TST_HISR_REQ el1task_wakeup_struct;


/********************* FHC COMMAND *********************/

typedef struct
{
   kal_int16   gain_rxm[MAX_RX_LNA_MODE_NUM];
   kal_int16   gain_rxd[MAX_RX_LNA_MODE_NUM];
}FHC_Rx_Type1_Gain_Param;

typedef struct
{
   kal_int16   gain_rxm[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM];
   kal_int16   gain_rxd[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM];
}FHC_Rx_Type2_Gain_Param;

typedef struct
{
   kal_uint8   band_index;
   kal_uint8   ca_category;
   kal_uint8   freq_num;
   kal_uint16  dl_freq[MAX_FHC_RX_FREQ_NUM_EX]; //100kHz unit
}FHC_Rx_Band_Param_CaMode;

typedef struct
{
   kal_uint8                band_num;
   FHC_Rx_Type1_Gain_Param  t1_band[3];
   FHC_Rx_Type2_Gain_Param  t2_band;
   FHC_Rx_Band_Param_CaMode band_param[ERF_MAX_BAND_NUM];
}FHC_Rx_Cfg_CaMode;

typedef struct
{
   kal_uint8   band_index;
   kal_uint8   freq_num;
   kal_uint16  ul_freq[MAX_FHC_TX_FREQ_NUM_EX];
   kal_uint8   pwr_step_pa_mode [MAX_TX_RPT_NUM];
   kal_int16   pwr_step_value[MAX_TX_RPT_NUM]; //target Power (PRF)
   kal_int16   pwr_step_pa_gain[MAX_TX_RPT_NUM];
}FHC_Tx_Band_Param_Ex;

typedef struct
{
   kal_uint8   band_num;
   kal_uint8   pwr_step_num;
   FHC_Tx_Band_Param_Ex    band_param[ERF_MAX_BAND_NUM];
}FHC_Tx_Cfg_Ex;

typedef struct
{
   kal_uint8         fdd_to_tdd_switch_time;//ms unit
   kal_uint8         fdd_tx_rx_switch_time;
   kal_uint8         tdd_tx_rx_switch_time;//ms unit
   kal_uint8         freq_switch_time;//ms unit
   kal_uint8         band_switch_time;//ms unit
   kal_uint8         step_time;
   FHC_Tx_Cfg_Ex     txCmd;
   FHC_Rx_Cfg_CaMode rxCmd;
}FHC_Cmd_CaMode;

#endif



