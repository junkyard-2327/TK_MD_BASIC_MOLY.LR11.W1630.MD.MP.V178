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
 *   drvpdn_inline.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   PDN Driver (C Inline Implementation)
 *      - PDN_SET(), PDN_CLR() is for Bus Clock Gating/Ungating
 *      - IPCG_SET(). IPCG_CLR() is for Non-Bus Clock Gating/Ungating
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 11 29 2016 devin.yang
 * [MOLY00215897] [System Service] [PDN] [MT6750S] Update PDN driver compile option for MT6750S.
 * .
 *
 * 03 03 2016 linson.du
 * [MOLY00166240] [Olympus]: driver porting
 * Porting PDN driver for Olympus.
 *
 * 08 04 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PLL/PDN driver porting for Everest.
 *
 * 06 15 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PDN driver porting for MT6755.
 *
 * 09 19 2014 tungchieh.tsai
 * [MOLY00079245] [TK6291][UMOLY][SYSTEM SERVICE][PDN] Rename
 *
 ****************************************************************************/

#ifndef __DRVPDN_INLINE_H__
#define __DRVPDN_INLINE_H__

#if defined(TK6291) || defined(TK6291)
    #include "drvpdn_inline_tk6291.h"
#elif defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
		#include "drvpdn_inline_mt6755.h"
#else
    #error "Unsupported Chip Target in PDN Module"
#endif

#endif /* !__DRVPDN_INLINE_H__ */
