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
 *    error_code.h
 *
 * Project:
 * --------
 *    MT6755(Jade)
 *
 * Description:
 * ------------
 *    error code.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 

#ifndef __MODEML1_DVFS_ERROR_CODE_H__
#define __MODEML1_DVFS_ERROR_CODE_H__

#ifdef DVFS_ENABLE

typedef enum
{
                /* 3G FDD error code */
/* 0x0  =  0 */ FDD_EVENT_OVERLAP = 0,
/* 0x1  =  1 */ FDD_AND_TDD_ACTIVE_WIN_OVERLAP_AND_EVENT_SHOWS,
/* 0x2  =  2 */ FDD_SET_EVENT_BUT_NO_ACTIVE_WIN,                  // NO active window, but FDD set event
/* 0x3  =  3 */ FDD_SET_IMM_EVENT_BUT_NO_ACTIVE_WIN,              // NO active window, but FDD set IMM event
/* 0x4  =  4 */ FDD_SCENARIO_SETTING_ERROR,
/* 0x5  =  5 */ FDD_SET_WRONG_SCH_WIN,                            // FDD set wrong schedule window (not in 0, 1)
/* 0x6  =  6 */ FDD_CURRENT_VOLTAGE_LARGER_THAN_UPB,              // current voltage > upper bound
/* 0x7  =  7 */ FDD_CUR_VOLT_LARGER_THAN_UPB_IMM_EVENT,           // current voltage > upper bound in IMM event
 
                /* 3G TDD error code */
/* 0x8  =  8 */ TDD_EVENT_OVERLAP, 
/* 0x9  =  9 */ TDD_AND_FDD_ACTIVE_WIN_OVERLAP_AND_EVENT_SHOWS, 
/* 0xA  = 10 */ TDD_SET_EVENT_BUT_NO_ACTIVE_WIN,                  // NO active window, but TDD set event
/* 0xB  = 11 */ TDD_SET_IMM_EVENT_BUT_NO_ACTIVE_WIN,              // NO active window, but TDD set IMM event
/* 0xC  = 12 */ TDD_SCENARIO_SETTING_ERROR,
/* 0xD  = 13 */ TDD_SET_WRONG_SCH_WIN,                            // TDD set wrong schedule window (not in 0, 1)
/* 0xE  = 14 */ TDD_CURRENT_VOLTAGE_LARGER_THAN_UPB,              // current voltage > upper bound
/* 0xF  = 15 */ TDD_CUR_VOLT_LARGER_THAN_UPB_IMM_EVENT,           // current voltage > upper bound in IMM event

                /* 4G LTE error code */
/* 0x10 = 16 */ LTE_MIN_SCH_WIN_OVERLAP,
/* 0x11 = 17 */ LTE_IMM_EVENT_SHOWS_ON_PROTECTION_REGION,
/* 0x12 = 18 */ LTE_SET_EVENT_BUT_NO_ACTIVE_WIN,                  // NO active window, but LTE set event
/* 0x13 = 19 */ LTE_SET_IMM_EVENT_BUT_NO_ACTIVE_WIN,              // NO active window, but LTE set IMM event
/* 0x14 = 20 */ LTE_SCENARIO_SETTING_ERROR,
/* 0x15 = 21 */ LTE_MULTIBIN_SETTING_ERROR,
/* 0x16 = 22 */ LTE_SET_WRONG_SCH_WIN,                            // LTE set wrong schedule window (not in 0, 1, 2, 3)
/* 0x17 = 23 */ LTE_CURRENT_VOLTAGE_LARGER_THAN_UPB,              // current voltage > upper bound
/* 0x18 = 24 */ LTE_CUR_VOLT_LARGER_THAN_UPB_IMM_EVENT,           // current voltage > upper bound in IMM event
/* 0x19 = 25 */ LTE_OCIC_NUM_WRONG

}MODEML1_DVFS_ERROE_CODE;

#endif /* ( defined(__DVFS_ENABLE__) && defined(TK6291) ) */

#endif /* __MODEML1_DVFS_ERROR_CODE_H__ */
