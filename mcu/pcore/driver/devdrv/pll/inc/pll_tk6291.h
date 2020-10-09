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
 *
 ****************************************************************************/

#ifndef __PLL_TK6291_H__
#define __PLL_TK6291_H__

/*******************************************************************************
 * Locally Used Options
 ******************************************************************************/
// To avoid timing issue in switching bus clock, we take strongly order for PLL init.
#define PLL_REG32(addr)   *(volatile kal_uint32 *)(addr)
#define PLL_TYPE	(volatile kal_uint32 *)
#define MD_CLKSW_BASE              (0xF0150000)
#define REG_MDTOP_CLKSW_CLKSEL_VER		(PLL_TYPE(MD_CLKSW_BASE+0x0000))
#define REG_MDTOP_CLKSW_CLKSEL_CTL		(PLL_TYPE(MD_CLKSW_BASE+0x0024))
#define REG_MDTOP_CLKSW_FLEXCKGEN_SEL0	(PLL_TYPE(MD_CLKSW_BASE+0x0028))
#define REG_MDTOP_CLKSW_FLEXCKGEN_STS0	(PLL_TYPE(MD_CLKSW_BASE+0x0030))
#define BASE_ADDR_MDTOP_PLLMIXED	(0xF0140000) //Mirror 0xF0140000
#define REG_MDTOP_PLLMIXED_PSMCUPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x004C))
#define REG_MDTOP_PLLMIXED_L1MCUPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0054))
#define REG_MDTOP_PLLMIXED_PSMCUPLL_STS		(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0600))
#define REG_MDTOP_PLLMIXED_L1MCUPLL_STS		(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0604))


/*******************************************************************************
 * Include header files
 ******************************************************************************/
extern void INT_SetPLL_TK6291(void);

#endif  /* !__PLL_H__ */

