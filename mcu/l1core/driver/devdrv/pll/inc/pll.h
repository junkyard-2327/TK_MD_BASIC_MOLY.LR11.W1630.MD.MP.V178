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
 *   pll.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   PLL Related Functions
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 11 21 2016 jun-ying.huang
 * [MOLY00214294] [1630MP][ROSA][FMA][PLL]Add new project macro for ROSA
 * MT6750S call-for-check-in
 *
 * 02 24 2016 linson.du
 * [MOLY00166240] [Olympus]: driver porting
 * Olympus Pll driver porting.
 *
 * 10 26 2015 linson.du
 * [MOLY00146768] [MODEM L1 DVFS] IMCPLL initial setting
 * IMC DVFS init re-org.
 *
 * 08 04 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PLL driver porting for Everest.
 *
 * 08 04 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PLL/PDN driver porting for Everest.
 *
 * 06 18 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Update PLL driver.
 *
 * 02 10 2015 linson.du
 * [MOLY00095411] [TK6291]: PLL driver porting
 * 	TK6291 Pcore/L1core pll init for cosim.
 *
 * 04 09 2014 tungchieh.tsai
 * [MOLY00062096] [TK6291][UMOLY] PLL driver porting
 *  	
 * Clean up MOLY PLL driver, make it dummy now
 *
 ****************************************************************************/

#ifndef __PLL_H__
#define __PLL_H__

/*******************************************************************************
 * Locally Used Options
 *******************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "reg_base.h"

#if defined(TK6291)
	#include "pll_tk6291.h"
#endif

#if defined(MT6755) || defined(MT6750S)
	#include "pll_mt6755.h"
#endif

#if defined(MT6797) || defined(MT6757)
	#include "pll_mt6797.h"
#endif


/*************************************************************************
 * Define exported macro
 *************************************************************************/
#define IMC_RESTORE_MODE_DISABLE 0
#define IMC_RESTORE_MODE_ENABLE  1

#define IMC_TABLE_GEAR01 1
#define IMC_TABLE_GEAR23 2
#define IMC_TABLE_GEAR45 3
#define IMC_TABLE_GEAR67 4

/*************************************************************************
 * Define data structure
 *************************************************************************/

/* FIXME: Dummy type definition to avoid other legacy module code build issue @
 * pcore/custom/driver/common/custom_SFI.c */
typedef enum mcu_clock_enum_t {
        DUMMY
} mcu_clock_enum;

/* PLL initialization mode */
typedef enum {
    PLL_MODE_MAUI,
    PLL_MODE_USB_META
} pll_init_mode;

/*************************************************************************
 * Define exported function prototype
 *************************************************************************/
extern void INT_SetPLL(pll_init_mode mode);
extern kal_uint32 PLL_IMC_DVFSTableSet(kal_uint32 table_number, kal_uint32 freq_0_khz, kal_uint32 freq_1_khz);
extern void PLL_IMC_DVFSControl(kal_uint32 plloff_freq_khz, kal_uint32 restore_mode );

/*************************************************************************
 * Define HW register
 *************************************************************************/

#endif  /* !__PLL_H__ */
