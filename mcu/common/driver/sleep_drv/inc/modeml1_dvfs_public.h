/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2015
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   modeml1_dvfs_public.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This file defines the modem L1 public information including scenario mapping voltage table, init flag, etc. for PCore DVFS
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 24 2015 kevin-kh.liu
 * [MOLY00151009] [MODEM L1 DVFS] MT6750 MODEM L1 DVFS modification
 *
 * 12 07 2015 jw.yu
 * [MOLY00139834] [MT6755] [MODEM L1 DVFS] Modify DVFS Code
 * [MODEM L1 DVFS] 1. Simply OCIC and PBCH flow 2. Fix Lock DVFS side effect.
 *
 * 11 26 2015 jw.yu
 * [MOLY00150566] [DVFS] changes for supporting OCIC multiple gear solution
 * [MODEM L1 DVFS] Modify table and support OCIC multiple gear.
 *
 * 08 04 2015 jeff.lee
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * [MODEM L1 DVFS] Remove PHY test option and add MT6797 option.
 *
 * 08 03 2015 jeff.lee
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * [MODEM L1 DVFS] add MT6797 option and add more debug trace.
 *
 * 07 20 2015 jeff.lee
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * [MODEM L1 DVFS] Update MODEM L1 DVFS gear table and initial setting.
 *
 * 07 06 2015 jeff.lee
 * [MOLY00120320] [TK6291/Jade] DVFS Code Submission
 * [MODEM L1 DVFS] Sync the latest code.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MODEML1_DVFS_PUBLIC_H__
#define __MODEML1_DVFS_PUBLIC_H__

#include "kal_general_types.h"

/******************************************************************************
* Definitions
******************************************************************************/

typedef enum {
    DVFS_CCIRQ_MODEML1_MODULE_SIM1_LTE_OCIC = 0,
    DVFS_CCIRQ_MODEML1_MODULE_SIM1_LTE_MULTIBIN_PBCH,
    DVFS_CCIRQ_MODEML1_MODULE_NUM
} DVFS_CCIRQ_MODEML1_SET_CMD_MODULE_E;

#ifdef DVFS_ENABLE

#if !( defined(L1_SIM)/* xL1SIM */ || defined(L1CORE_DVFS_HVT) )
// static fill in by MODEML1 DVFS and use by PCore DVFS
DECLARE_SHARED_ARRAY(kal_uint32, scenario_mapping_modeml1_voltage, DVFS_TOTAL_SCENARIO_TYPE_NUM) // extern kal_uint32 scenario_mapping_modeml1_voltage[DVFS_TOTAL_SCENARIO_TYPE_NUM];
// dynamic fill in by MODEML1 DVFS and use by PCore DVFS after MODEML1 DVFS inform PCore DVFS by CCIRQ cmd
DECLARE_SHARED_ARRAY(kal_uint32, scenario_mapping_modeml1_voltage_ptp_init, DVFS_TOTAL_SCENARIO_TYPE_NUM) // extern kal_uint32 scenario_mapping_modeml1_voltage_ptp_init[DVFS_TOTAL_SCENARIO_TYPE_NUM];
#endif

#endif /* DVFS_ENABLE */

#endif /* __MODEML1_DVFS_PUBLIC_H__ */
