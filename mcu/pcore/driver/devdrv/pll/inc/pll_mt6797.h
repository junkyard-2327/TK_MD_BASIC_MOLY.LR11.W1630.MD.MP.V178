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
 *   pll_mt6755.h
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
 * .
 *
 * 07 30 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Add PSMCU STS define.
 *
 * 07 13 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * 	PLL driver update for golden setting and l1modem dvfs.
 *
 * 06 28 2015 linson.du
 * [MOLY00122918] [MT6755][BRINGUP_FIRSTCALL][SS]
 * 	PLL update.
 *
 * 06 25 2015 linson.du
 * [MOLY00122918] [MT6755][BRINGUP_FIRSTCALL][SS]
 * Update PLL driver for Jade SB bring up.
 *
 * 06 22 2015 linson.du
 * [MOLY00122918] [MT6755][BRINGUP_FIRSTCALL][SS]
 * Update PLL driver for Jade bring up.
 *
 * 06 18 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Update PLL driver.
 *
 ******************************************************************************/

#ifndef __PLL_MT6755__
#define __PLL_MT6755__

/*******************************************************************************
 * Locally Used Options
 ******************************************************************************/

/*******************************************************************************
 * Include header files
 ******************************************************************************/

#if !defined(MT6797) && !defined(MT6757)
    #error "This header should only be included in MT6797 or MT6757 Project"
#endif

#include "kal_general_types.h"
#include "reg_base.h"

/*******************************************************************************
 * Define exported macro
 ******************************************************************************/


/*******************************************************************************
 * Define data structure
 ******************************************************************************/


//#if defined(PSCORE) && defined(MT6755)
#define PSMCU_COMPILE 	// for Pscore only
//#endif

//#if defined(L1CORE)	&& defined(MT6755)
#define L1MCU_COMPILE // for L1core
//#endif

#if defined(ARM7_ENABLE)
#define MDMCU_LITE_COMPILE // for ARM7
#endif

#define CACHE_OFF	// depends on cache config
//#define DCACHE_ON	// depends on cache config
//#define SIM_26M		// for only 26Mhz sim
//#define LTE_OFF		//no func.
#define ARM7_ON 		// for L1MCUPLL status (div2)
//#define L1MCU_ON 	//for L1MCUPLL status
#define L1MCU_ON		//?
//#define PWB_OFF		//no func.
#define BYPASS_MDCIRQ_INI	//CIRQ?
//#define VECTOR_INTR_ON	//VECTOR intr
//#define DCM_OFF		// depends on dcm config.
//#define LEVEL2_DCM_OFF // no func.
//#define APMCU_ENABLE
#define modeml1_hwdvfs_mode


#define PLL_TYPE	(volatile kal_uint32 *)
#define UINT32	kal_uint32

#define MD_CLKSW_BASE              (0x80150000)
#define BASE_ADDR_MDTOP_PLLMIXED	(0xF0140000) //Mirror 0xF0140000

#define R_CLKON_CTL	                (PLL_TYPE(MD_CLKSW_BASE+0x0020))
#define R_CLKSEL_CTL	            (PLL_TYPE(MD_CLKSW_BASE+0x0024))
#define R_FLEXCKGEN_SEL0	      (PLL_TYPE(MD_CLKSW_BASE+0x0028))
#define R_FLEXCKGEN_SEL1	      (PLL_TYPE(MD_CLKSW_BASE+0x002C))
#define R_FLEXCKGEN_SEL2	      (PLL_TYPE(MD_CLKSW_BASE+0x0044))

#define REG_MDTOP_PLLMIXED_PSMCUPLL_CTL1	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0050))

#define REG_MDTOP_PLLMIXED_L1MCUPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0054))
#define REG_MDTOP_PLLMIXED_BRPPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x005C))
#define REG_MDTOP_PLLMIXED_EQPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0064))
#define REG_MDTOP_PLLMIXED_IMCPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x006C))
#define REG_MDTOP_PLLMIXED_ICCPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0074))
#define REG_MDTOP_PLLMIXED_CMPPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x007C))
#define REG_MDTOP_PLLMIXED_DFEPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0084))
#define REG_MDTOP_PLLMIXED_MD2GPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x008C))
#define REG_MDTOP_PLLMIXED_INTFPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0094))

#define R_PLL_DLY_CTL0          (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0020))
#define R_PLL_DLY_CTL1          (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0024))
#define R_PLL_DLY_CTL2          (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0028))
#define R_IMCPLL_CTL0           (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x006C))
#define R_IMCPLL_CTL1           (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0070))
#define R_PLL_FH_CTL            (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0200))
#define R_PSMCUPLL_FHCTL0       (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0400))
#define R_IMCPLL_FHCTL0         (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0480))
#define R_IMCPLL_FHCTL1         (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0484))
#define R_IMCPLL_FHCTL2         (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0488))
#define R_IMCPLL_FHCTL3         (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x048C))
#define R_IMCPLL_FHCTL4         (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0490))
#define R_IMCPLL_FHCTL5         (PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0494))

#define R_PLL_STS	            	(PLL_TYPE(MD_CLKSW_BASE+0x0040))

#define R_FLEXCKGEN_STS0	      (PLL_TYPE(MD_CLKSW_BASE+0x0030))
#define R_FLEXCKGEN_STS1	      (PLL_TYPE(MD_CLKSW_BASE+0x0034))
#define R_FLEXCKGEN_STS2	      (PLL_TYPE(MD_CLKSW_BASE+0x0048))






#define MD_GLOBAL_CON_DCM_BASE (0x80130000)

//#define MD_RGU_BASE	(0xF00F0000)
/*PSMCU DCM*/
#define R_PSMCU_DCM_CTL0		(PLL_TYPE(MD_GLOBAL_CON_DCM_BASE+0x0010))
#define R_PSMCU_DCM_CTL1		(PLL_TYPE(MD_GLOBAL_CON_DCM_BASE+0x0014))

#define R_ARM7_DCM_CTL0			(PLL_TYPE(MD_GLOBAL_CON_DCM_BASE+0x0020))
#define R_ARM7_DCM_CTL1			(PLL_TYPE(MD_GLOBAL_CON_DCM_BASE+0x0024))
#define MD_GLOBAL_CON_DUMMY		(PLL_TYPE(MD_GLOBAL_CON_DCM_BASE+0x1000))
#define MD_PLL_MAGIC_NUM 		0x67550000
#define R_DCM_SHR_SET_CTL		(PLL_TYPE(0x80120000+0x0004))
#define R_LTEL2_BUS_DCM_CTL		(PLL_TYPE(0x80120000+0x0010))
#define R_MDDMA_BUS_DCM_CTL		(PLL_TYPE(0x80120000+0x0014))
#define R_MDREG_BUS_DCM_CTL		(PLL_TYPE(0x80120000+0x0018))
#define R_MODULE_BUS2X_DCM_CTL	(PLL_TYPE(0x80120000+0x001C))
#define R_MODULE_BUS1X_DCM_CTL	(PLL_TYPE(0x80120000+0x0020))
#define R_MDINFRA_CKEN			(PLL_TYPE(0x80120000+0x0044))		
#define R_MDPERI_CKEN			(PLL_TYPE(0x80120000+0x0048))
#define R_MDPERI_DCM_MASK		(PLL_TYPE(0x80120000+0x0064))

#define PSMCU_MISC_BASE			(0x80200000)

#define R_CR4_PREFETCH_CONTROL	(PLL_TYPE(PSMCU_MISC_BASE+0x000C))

#define MD_PERI_MISC_BASE		(0x80060000)
#define R_PSMCU_AO_CLK_CTL 		(PLL_TYPE(0x80120000+0x00C0))

	
#define R_MDSYS_AP_PMS			(PLL_TYPE(MD_PERI_MISC_BASE+0x0090))
#define R_MDPERISYS1_AP_PMS		(PLL_TYPE(MD_PERI_MISC_BASE+0x0094))
#define R_MDPERISYS2_AP_PMS		(PLL_TYPE(MD_PERI_MISC_BASE+0x0098))
#define R_PSMCUAPB_AP_PMS		(PLL_TYPE(MD_PERI_MISC_BASE+0x009C))
#define R_MDSYS_TZ_PMS			(PLL_TYPE(MD_PERI_MISC_BASE+0x00A0))
#define R_MDPERISYS1_TZ_PMS		(PLL_TYPE(MD_PERI_MISC_BASE+0x00A4))
#define R_MDPERISYS2_TZ_PMS		(PLL_TYPE(MD_PERI_MISC_BASE+0x00A8))
#define R_PSMCUAPB_TZ_PMS		(PLL_TYPE(MD_PERI_MISC_BASE+0x00AC))
#define R_MDSYS_L1_PMS			(PLL_TYPE(MD_PERI_MISC_BASE+0x00B0))
#define R_MDPERISYS1_L1_PMS		(PLL_TYPE(MD_PERI_MISC_BASE+0x00B4))
#define R_MDPERISYS2_L1_PMS		(PLL_TYPE(MD_PERI_MISC_BASE+0x00B8))
#define R_PSMCUAPB_L1_PMS		(PLL_TYPE(MD_PERI_MISC_BASE+0x00BC))
#define R_MDSYS_REMAP			(PLL_TYPE(MD_PERI_MISC_BASE+0x00C0))
#define REG_M_L1_MDL1_CONF_MDL1AO_CG_CLR (PLL_TYPE(L1_BASE_MADDR_MDL1_CONF+0x0008))
#define REG_M_L1_MDL1_CONF_MDL1AO_BTVEC_UPDATE (PLL_TYPE(L1_BASE_MADDR_MDL1_CONF+0x0104))

#define R_L1_PMS				(PLL_TYPE(MD_PERI_MISC_BASE+0x00C4))

#define REG_MDTOP_PLLMIXED_PSMCUPLL_CTL0	(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x004C))

#define REG_M_L1_TOPSM_SM_PWR_RDY		(PLL_TYPE(L1_BASE_MADDR_TOPSM+0x00D4))
#define REG_M_L1_L1CIRQ_VEC_ADDR_BASE	(PLL_TYPE(L1_BASE_MADDR_L1CIRQ+0x0290))
#define REG_M_L1_L1CIRQ_MIN_PRLV		(PLL_TYPE(L1_BASE_MADDR_L1CIRQ+0x008C))

#define MDL1A0_BASE (0xF60F0000)

#define MDL1AO_BTVEC_UPDATE				(PLL_TYPE(MDL1A0_BASE+0x0104))
#define REG_DCM_PLLCK_SEL				(PLL_TYPE(MDL1A0_BASE+0x0188))

#define R_L1MCU_PWR_AWARE				(PLL_TYPE(MDL1A0_BASE+0x0190))
#define R_L1AO_PWR_AWARE				(PLL_TYPE(MDL1A0_BASE+0x0194))
#define R_BUSL2DCM_CON3					(PLL_TYPE(MDL1A0_BASE+0x0198))
#define R_L1MCU_DCM_CON2				(PLL_TYPE(MDL1A0_BASE+0x0184))
#define R_L1MCU_DCM_CON					(PLL_TYPE(MDL1A0_BASE+0x0180))

#define R_PLL_HP_RDY_IRQ				(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x030C))
#define R_PSMCUPLL_STS    				(PLL_TYPE(BASE_ADDR_MDTOP_PLLMIXED+0x0600))


#define REG_MDTOP_CLKSW_CKMON_CTL				(PLL_TYPE(MD_CLKSW_BASE+0x100))
#define REG_MDTOP_CLKSW_FREQ_METER_CTL			(PLL_TYPE(MD_CLKSW_BASE+0x104))
#define REG_MDTOP_CLKSW_FREQ_METER_XTAL_CNT		(PLL_TYPE(MD_CLKSW_BASE+0x108))
#define REG_MDTOP_CLKSW_FREQ_METER_CKMON_CNT	(PLL_TYPE(MD_CLKSW_BASE+0x10C))
#define REG_MDTOP_CLKSW_FREQ_METER_H			(PLL_TYPE(MD_CLKSW_BASE+0x110))
#define REG_MDTOP_CLKSW_FREQ_METER_L			(PLL_TYPE(MD_CLKSW_BASE+0x114))


#endif  /* !__PLL_MT6755__ */
