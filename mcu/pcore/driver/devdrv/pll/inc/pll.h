/*******************************************************************************
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
 ******************************************************************************/

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
 * ============================================================================
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
 * [MOLY00136396] [MT6755]: PLL driver porting
 * Add pll frequncy meter api for memory dump.
 *
 * 08 10 2015 linson.du
 * [MOLY00136396] [MT6755]: PLL driver porting
 * Pll driver porting for PSMCU DFS.
 *
 * 08 04 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PLL driver porting for Everest.
 *
 * 08 04 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PLL/PDN driver porting for Everest.
 *
 * 07 13 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * 	PLL driver update for golden setting and l1modem dvfs.
 *
 * 06 17 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Fix build error.
 *
 * 06 15 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PLL porting for MT6755.
 *
 * 02 10 2015 linson.du
 * [MOLY00095411] [TK6291]: PLL driver porting
 * 	TK6291 Pcore/L1core pll init for cosim.
 *
 * 04 10 2014 tungchieh.tsai
 * [MOLY00062096] [TK6291][UMOLY] PLL driver porting
 *  	
 * Fix MT6290 build error
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
 ******************************************************************************/

/*******************************************************************************
 * Include header files
 ******************************************************************************/
#include "kal_general_types.h"
#include "reg_base.h"

#if defined(MT6290)
    #include "pll_mt6290.h"
#endif

#if defined(TK6291)
	#include "pll_tk6291.h"
#endif

#if defined(MT6755) || defined(MT6750S)
	#include "pll_mt6755.h"
#endif

#if defined(MT6797) || defined(MT6757)
	#include "pll_mt6797.h"
#endif


/*******************************************************************************
 * Define exported macro
 ******************************************************************************/

/*******************************************************************************
 * Define data structure
 ******************************************************************************/

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

/*******************************************************************************
 * Define exported function prototype
 ******************************************************************************/
extern void INT_SetPLL(pll_init_mode mode);
extern kal_uint32 Set_PSMCU_frequency(kal_uint32 clock);
extern kal_uint32 Get_PSMCU_frequency(void);
extern void Deassert_PSMCU_PLLHP_INT(void);
extern kal_bool Get_PSMCU_PLLHP_INT_status(void);
extern kal_bool Get_PSMCUPLL_SFSTR_PRD_status(void);
extern void PLL_exception_dump(void);


#endif  /* !__PLL_H__ */
