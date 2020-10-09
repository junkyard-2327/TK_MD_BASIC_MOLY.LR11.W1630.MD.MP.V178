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
 * 06 17 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Fix build error.
 *
 * 06 15 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PDN driver porting for MT6755.
 *
 * 09 19 2014 tungchieh.tsai
 * [MOLY00079245] [TK6291][UMOLY][SYSTEM SERVICE][PDN] Rename
 *
 * 04 09 2014 tungchieh.tsai
 * [MOLY00061872] [UMOLY][TK6291][SYYSTEN SERVICE] TK6291 PDN driver porting (dummy version)
 *  	
 * Update header
 *
 * 04 07 2014 tungchieh.tsai
 * [MOLY00061872] [UMOLY][TK6291][SYYSTEN SERVICE] TK6291 PDN driver porting (dummy version)
 *
 * Fix build error, add dummy implementation
 *
 * 12 10 2013 gh.huang
 * [MOLY00046715] Separate Different Target and Add Initial 6595 Support
 *
 * 08 27 2013 gh.huang
 * [MOLY00034371] Temporarily Disable PDN for Phone Product (Re-Enable PDN Since Issue Clarified)
 *
 * 08 20 2013 gh.huang
 * [MOLY00034371] Temporarily Disable PDN for Phone Product
 *
 * 08 12 2013 gh.huang
 * [MOLY00033409] Fix PDN Module Build Warning
 *
 * 08 01 2013 gh.huang
 * [MOLY00031956] Add IPCG APIs for Non-Bus CG Support
 *
 * 07 15 2013 gh.huang
 * [MOLY00029891] Update PDN internal BUS CG implementation settings
 *
 * 07 05 2013 gh.huang
 * [MOLY00028795] Update PDN module to add more IP support and remove non-BUS clock settings
 *
 * 06 26 2013 gh.huang
 * [MOLY00027628] Fix PDN Module Error for IRDBG
 *
 * 06 05 2013 gh.huang
 * [MOLY00025140] Update PDN module and add IRDBG support
 *
 * 04 03 2013 gh.huang
 * [MOLY00013413] Update PDN module and add GCU support
 *
 * 03 31 2013 gh.huang
 * [MOLY00012450] Replace sys_drv/pdn with devdrv/pdn
 *
 ****************************************************************************/

#ifndef __DRVPDN_INLINE_H__
#define __DRVPDN_INLINE_H__

#if defined(MT6290)
    #include "drvpdn_inline_mt6290.h"
#elif defined(TK6291) || defined(TK6291)
    #include "drvpdn_inline_tk6291.h"
#elif defined(MT6595)
    #include "drvpdn_inline_mt6595.h"
#elif defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
    #include "drvpdn_inline_MT6755.h"	
#else
    #error "Unsupported Chip Target in PDN Module"
#endif

#endif /* !__DRVPDN_INLINE_H__ */
