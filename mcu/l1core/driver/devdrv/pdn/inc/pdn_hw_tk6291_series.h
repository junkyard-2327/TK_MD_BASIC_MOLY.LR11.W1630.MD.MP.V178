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
 *   pdn_hw_tk6291_series.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   PDN Driver Related HW Registers
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 03 18 2015 linson.du
 * [MOLY00095411] [TK6291]: PLL driver porting
 * PDN driver porting.
 *
 * 09 19 2014 tungchieh.tsai
 * [MOLY00079245] [TK6291][UMOLY][SYSTEM SERVICE][PDN] Rename
 *
 ****************************************************************************/

#ifndef __PDN_HW_TK6291_SERIES_H__
#define __PDN_HW_TK6291_SERIES_H__

#include "reg_base.h"

#define MD_L1MCU_CG_CON                       ((L1_BASE_MADDR_L1MCU_CONF+0x00))
#define MD_L1MCU_CG_SET                       ((L1_BASE_MADDR_L1MCU_CONF+0x04))
#define MD_L1MCU_CG_CLR                       ((L1_BASE_MADDR_L1MCU_CONF+0x08))
    #define CG_ATB                            (1 << 7)
    #define CG_UART                           (1 << 6)
    #define CG_ABM                            (1 << 5)
    #define CG_GDMA                           (1 << 4)
    #define CG_FCS                            (1 << 3)
    #define CG_PCMON                          (1 << 2)
    #define CG_BUSMON                         (1 << 1)
    #define CG_ELM                            (1 << 0)

#define MD_L1_PLL_BASE 0xF0140000
	
#define MD_L1_MDPLL_CTL2                       ((MD_L1_PLL_BASE+0x48))
#define CG_MCCO                      (1 << 22)


#endif  /* !__PDN_HW_TK6291_SERIES_H__ */
