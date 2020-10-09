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


/*****************************************************************************
 *
 * Filename:
 * ---------
 *   intrCtrl_TK6291_SW_Handle.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   This file define software interrupt handler.
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 09 23 2015 i-chun.liu
 * [MOLY00142963] Add SW trigger interrupts configuration
 * update SW trigger interrupts (add MDDBG).
 *
 * 07 29 2014 linson.du
 * [MOLY00070793] [TK6291]: CIRQ driver update
 * irq id and prority update.
 *
 * 04 24 2014 da.wang
 * [MOLY00062016] Fix build error of porting for TK6291
 * Update internal PMU & SW LISR naming.
 *
 * 07 03 2013 chin-chieh.hung
 * [MOLY00027330] [ARM7toMOLY] ARM7 Build/SYSGEN/Functions Update to TRUNK
 * .
 *
 * 06 04 2013 mogens.christiansen
 * [MOLY00024323] [MT7208][NW-UE SIM][MOLY Regression][TC 6.2.3.31] Assert fail: m14999.c line 1022
 * Fixed SW interrupt mapping in UESIM project
 *
 * 05 24 2013 chin-chieh.hung
 * [MOLY00023372] [MT6290][NW-UE SIM] UESIM MOLY Migration - UESIM related changes submission
 * fix UESIM config error in target build
 *
 * 05 23 2013 chin-chieh.hung
 * [MOLY00023372] [MT6290][NW-UE SIM] UESIM MOLY Migration - UESIM related changes submission
 * UESIM, cirq support
 *
 * 03 25 2013 chin-chieh.hung
 * [MOLY00011352] [Driver] Update for common devdrv driver
 * add sw trigger interrupts
 *
 * 02 04 2013 chin-chieh.hung
 * [MOLY00009725] MT7208 rename to MT6290 - basic platform module
 * chip rename:MT7208 to MT6290
 ****************************************************************************/


/* Add SW handler mapping: 
      1st parameter: The name of software handler
      2nd parameter: The software handler number
      3th parameter: The mapping of software handler to hardware interrupt code 
   __CR4__ User:
      SW_TRIGGER_CODE1 = SH Yang
      SW_TRIGGER_CODE2 = Weimin Zeng
      SW_TRIGGER_CODE3 = Weimin Zeng
      SW_TRIGGER_CODE4 = Weimin Zeng
      SW_TRIGGER_CODE5 = Max Weng
      SW_TRIGGER_CODE6 = Max Weng 
      SW_TRIGGER_CODE7 = MDDBG (Tee-Yuen Chun)
      SW_TRIGGER_CODE8 = (Qmei Yang)
 
*/
#if defined(__CR4__)
    X_SW_HANDLE_CONST(SW_TRIGGER_CODE1, IRQ_SW_LISR1_CODE, IRQ_SW_LISR1_CODE)
    X_SW_HANDLE_CONST(SW_TRIGGER_CODE2, IRQ_SW_LISR2_CODE, IRQ_SW_LISR2_CODE)
    X_SW_HANDLE_CONST(SW_TRIGGER_CODE3, IRQ_SW_LISR3_CODE, IRQ_SW_LISR3_CODE)
    X_SW_HANDLE_CONST(SW_TRIGGER_CODE4, IRQ_SW_LISR4_CODE, IRQ_SW_LISR4_CODE)
    X_SW_HANDLE_CONST(SW_TRIGGER_CODE5, IRQ_SW_LISR5_CODE, IRQ_SW_LISR5_CODE)
    X_SW_HANDLE_CONST(SW_TRIGGER_CODE6, IRQ_SW_LISR6_CODE, IRQ_SW_LISR6_CODE)
    X_SW_HANDLE_CONST(SW_TRIGGER_CODE7, IRQ_SW_LISR7_CODE, IRQ_SW_LISR7_CODE)
    X_SW_HANDLE_CONST(SW_TRIGGER_CODE8, IRQ_SW_LISR8_CODE, IRQ_SW_LISR8_CODE)
#else
    #error "No CPU version select. Need to specify CPU version in project 6291 for MDSYS."
#endif

