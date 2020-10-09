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
 * Filename:
 * -----------
 *   spv_api.h
 *
 * Project:
 * -----------
 *   UMOLY
 *
 * Description:
 * ------------
 *   SPV Related API Code
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 08 07 2015 wellken.chen
 * [MOLY00136064] [Jade][SPV][System Service] Refine and merge Jade SPV code
 *
 * 07 14 2015 wellken.chen
 * [MOLY00128710] [Jade][SPV] Refine SPV API realted code
 *
 *
 *
 *
 *
 ****************************************************************************/


#ifndef __SPV_UTILITY_H_
#define __SPV_UTILITY_H_

#include "reg_base.h"
#include "kal_general_types.h"

#if defined(TK6291)			//use MD dongle EMI
#define EMI_PASSWD_ADDR				(volatile kal_uint32 *)(0x93083000)
#define EMI_PASSWD_VALUE			0x24541689

#define SPV_MADDR_MEMAPB			(0xC3000000)


#define EMI_MDCT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x78)
#define EMI_ARBD					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x118)
#define EMI_ARBH					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x138)

#define EMI_SLCT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x158)
#define EMI_CONM					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x60)
#define EMI_TESTB					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0xE8)

#define EMI_BMEN					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x400)
#define EMI_BCNT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x408)

#define EMI_BMEN2					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x4E8)
#define EMI_TSCT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x418)
#define EMI_TSCT2					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x448)
#define EMI_WSCT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x428)
#define EMI_BACT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x430)
#define EMI_BSCT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x438)

#define EMI_WSCT2					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x458)
#define EMI_MSEL					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x440)


#define EMI_TTYPE1					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x500)
#define EMI_TTYPE2					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x508)
#define EMI_TTYPE3					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x510)
#define EMI_TTYPE4					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x518)
#define EMI_TTYPE5					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x520)
#define EMI_TTYPE6					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x528)
#define EMI_TTYPE7					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x53C)


//psmcu ultra
#define SPV_PSMCU_QOS_CTL				(volatile kal_uint32 *)(BASE_MADDR_MDPERIMISC + 0xF0)

//l1mcu ultra
#define SPV_MDL1AO_L1MCUSYS_BUS_CON1	(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_CONF + 0x204)


#define EMI_FORCE_LATENCY_PSCORE(r, w) \
    do {\
        while (*SPV_PSMCU_QOS_CTL & 0x11) {*SPV_PSMCU_QOS_CTL &= ~(0x11);}\
		*EMI_PASSWD_ADDR = EMI_PASSWD_VALUE;\
        *EMI_MDCT = 0x00110000;\
        *EMI_ARBD = 0x00003000 | (r<<16) | (w<<24);\
        *EMI_SLCT = 0x18000000;\
        *EMI_CONM = 0xff000500;\
    } while (0)


#define EMI_FORCE_LATENCY_L1CORE(r, w) \
	do {\
		while (*SPV_MDL1AO_L1MCUSYS_BUS_CON1 & 0x30) {*SPV_MDL1AO_L1MCUSYS_BUS_CON1 &= ~(0x30);}\
		*EMI_PASSWD_ADDR = EMI_PASSWD_VALUE;\
		*EMI_MDCT = 0x00110000;\
		*EMI_ARBD = 0x00003000 | (r<<16) | (w<<24);\
		*EMI_SLCT = 0x18000000;\
		*EMI_CONM = 0xff000500;\
	} while (0)

#define EMI_FORCE_DISABLE_DRAMC_WRITE_EARLY_RESPONSE() \
	do {\
		*EMI_PASSWD_ADDR = EMI_PASSWD_VALUE;\
		*EMI_TESTB |= (1<<11);\
	} while(0)


#elif defined(MT6755)		//use AP EMI

#define MD2EMI_ULTRA_HIGH_STATUS0 	((volatile kal_uint32 *)(0x80000400))
#define MD2EMI_ULTRA_HIGH_CLR0    	((volatile kal_uint32 *)(0x80000408))

#define SPV_MADDR_MEMAPB			(0xC0203000)


#define EMI_DRCT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x78)
#define EMI_ARBD					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x118)
#define EMI_SLCT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x158)
#define EMI_CONM					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x60)
#define EMI_TESTB					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0xE8)

#define EMI_BMEN					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x400)
#define EMI_BCNT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x408)

#define EMI_TSCT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x418)
#define EMI_WSCT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x428)
#define EMI_BACT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x430)
#define EMI_BSCT					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x438)
#define EMI_MSEL					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x440)
#define EMI_TSCT2					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x448)
#define EMI_WSCT2					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x458)
#define EMI_BMEN2					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x4E8)


#define EMI_TTYPE1					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x500)
#define EMI_TTYPE2					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x508)
#define EMI_TTYPE3					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x510)
#define EMI_TTYPE4					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x518)
#define EMI_TTYPE5					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x520)
#define EMI_TTYPE6					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x528)
#define EMI_TTYPE7					(volatile kal_uint32 *)(SPV_MADDR_MEMAPB + 0x53C)

//psmcu ultra
#define SPV_PSMCU_QOS_CTL				((volatile kal_uint32 *)(BASE_MADDR_MDPERIMISC + 0xF0))

//l1mcu ultra
#define SPV_MDL1AO_L1MCUSYS_BUS_CON1	((volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_CONF + 0x204))


#define EMI_FORCE_LATENCY_PSCORE(r, w) \
    do {\
        while (*SPV_PSMCU_QOS_CTL & 0x11) {*SPV_PSMCU_QOS_CTL &= ~(0x11);}\
        *EMI_DRCT = 0x23110000;\
        *EMI_ARBD = 0x00003000 | (r<<16) | (w<<24);\
        *EMI_SLCT = 0x1F011700;\
        *EMI_CONM = 0xff000500;\
    } while (0)


#define EMI_FORCE_LATENCY_L1CORE(r, w) \
	do {\
		while (*SPV_MDL1AO_L1MCUSYS_BUS_CON1 & 0x30) {*SPV_MDL1AO_L1MCUSYS_BUS_CON1 &= ~(0x30);}\
		*EMI_DRCT = 0x23110000;\
		*EMI_ARBD = 0x00003000 | (r<<16) | (w<<24);\
		*EMI_SLCT = 0x1F011700;\
		*EMI_CONM = 0xff000500;\
	} while (0)

#define EMI_FORCE_DISABLE_DRAMC_WRITE_EARLY_RESPONSE() \
	do {\
		*EMI_TESTB |= (1<<11);\
	} while(0)


#endif	//defined(TK6291)
#endif	//__SPV_UTILITY_H_


