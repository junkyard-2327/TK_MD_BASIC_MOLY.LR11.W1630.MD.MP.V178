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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   l1_rtb.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Real Time Base for 3G Gemini project
 *
 * Author:
 * -------
 * -------
 *
 * $Log$
 *
 * 07 16 2015 terence.chen
 * [MOLY00124313] Change the path of l1_rtb.h and check-in the code of SRLTE
 * Add l1_rtb_common for MD3 and l1_rtb.h is only for MD1.
 *
 * 07 09 2015 terence.chen
 * [MOLY00124313] Change the path of l1_rtb.h and check-in the code of SRLTE
 * Modify the l1_rtb.h for MD1.
 *
 * 06 17 2015 mohamed.idhrees
 * [MOLY00114877] [TK6291E1][L1C] EL1C_RTIMER_NUM value needs to be increased
 * EL1C_RTIMER_NUM increased to 22
 *
 * 05 20 2015 mohamed.idhrees
 * [MOLY00114877] [TK6291E1][L1C] EL1C_RTIMER_NUM value to be increased from 10 to 16
 * EL1C_RTIMER_NUM value increased from 10 to 16
 *
 * 05 20 2015 mohamed.idhrees
 * [MOLY00112586] [TK6291E1][GCF][ANITE][3G][FDD][8.3.7.1a CS] Test Fail
 * .
 *
 * 05 05 2015 arkadeep.sett
 * [MOLY00111246] L+W MM Gemini+ xL1SIM Changes to UMOLY trunk
 * 	Propagating L1C and RTB changes for LW_GEMINI from chi-chung.lin Gemini sanity branch to UMOLY trunk
 *
 * 03 04 2015 rick.wu
 * [MOLY00083549] [MT6291] Merge GL1 codes from MT6291_DEV to UMOLY
 * Fix cross header build error in Gemini project
 *
 * 03 03 2015 rick.wu
 * [MOLY00083549] [MT6291] Merge GL1 codes from MT6291_DEV to UMOLY
 * Fix UMOLY Gemini build error
 *
 * 12 15 2014 terence.chen
 * [MOLY00083240] [UMOLY] Check-in MOLY and universal bin into UMOLY.
 * 	Correct the header file.
 *
 * 02 11 2014 terence.chen
 * [MOLY00055725] [4G Gemini][WG][CS Performance][Moving] fatal : (0xb13, 0x30884b) ¡V SWL1H
 * Modify the definition of FRC_WRAP_COMPENSATION.
 *
 * 01 22 2014 terence.chen
 * [MOLY00054324] [4G Gemini][Merge] MOLY.MM.GEMINI.DEV Merge back to MOLY.
 *
 *
 ****************************************************************************/

#ifndef L1_RTB_MD1
#define L1_RTB_MD1

// l1_rtb.h is included by MD1.
#include "kal_general_types.h"

// l1_rtb_common.h is included by MD3.
#include "l1_rtb_common.h"

#endif
