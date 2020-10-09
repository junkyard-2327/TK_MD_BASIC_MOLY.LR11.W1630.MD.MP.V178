/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   emi_mt6290.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file for MT6290 EMI.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(__EMI_MT6290_H__)
/* ==================== */
/*	CONFIGURATIONS		*/
/* ==================== */
/* ==================== */
/*	INCLUDES			*/
/* ==================== */
#include "reg_base.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "sync_data.h"

/* ==================== */
/*	DEFINITIONS			*/
/* ==================== */
#define REG_EMIARB_PD_CODA_VER			(BASE_ADDR_EMIARB + 0x1000)
#define REG_EMIARB_BMEN					(BASE_ADDR_EMIARB + 0x2000)
#define REG_EMIARB_BMEN1				(BASE_ADDR_EMIARB + 0x2008)
#define REG_EMIARB_BMEN2				(BASE_ADDR_EMIARB + 0x2010)
#define REG_EMIARB_BCNT					(BASE_ADDR_EMIARB + 0x2018)
#define REG_EMIARB_TACT					(BASE_ADDR_EMIARB + 0x2020)
#define REG_EMIARB_WACT					(BASE_ADDR_EMIARB + 0x2028)
#define REG_EMIARB_BACT					(BASE_ADDR_EMIARB + 0x2030)
#define REG_EMIARB_BSCT					(BASE_ADDR_EMIARB + 0x2038)
#define REG_EMIARB_MSEL(x)				(BASE_ADDR_EMIARB + 0x2040 + (((x) - 1) << 3))
#define REG_EMIARB_BMID(x)				(BASE_ADDR_EMIARB + 0x20A0 + ((x) << 3))
#define REG_EMIARB_WSCT(x)				(BASE_ADDR_EMIARB + 0x20D0 + (((x) - 1) << 3))
#define REG_EMIARB_TSCT(x)				(BASE_ADDR_EMIARB + 0x20F0 + (((x) - 1) << 3))
#define REG_EMIARB_TTYPE(x)				(BASE_ADDR_EMIARB + 0x2108 + (((x) - 1) << 3))
#define REG_EMIARB_RMPUS				(BASE_ADDR_EMIARB + 0x21B0)
#define REG_EMIARB_RMPUS_1				(BASE_ADDR_EMIARB + 0x21B8)
#define REG_EMIARB_RMPUT				(BASE_ADDR_EMIARB + 0x21C0)
#define REG_EMIARB_MISC					(BASE_ADDR_EMIARB + 0x21C8)
#define REG_EMIARB_PD_DUMMY				(BASE_ADDR_EMIARB + 0x2200)
#define REG_EMIARB_NPD_CODA_VER			(BASE_ADDR_EMIARB + 0x3000)
#define REG_EMIARB_CONA					(BASE_ADDR_EMIARB + 0x3004)
#define REG_EMIARB_CONB					(BASE_ADDR_EMIARB + 0x3008)
#define REG_EMIARB_CONC					(BASE_ADDR_EMIARB + 0x3010)
#define REG_EMIARB_COND					(BASE_ADDR_EMIARB + 0x3018)
#define REG_EMIARB_CONE					(BASE_ADDR_EMIARB + 0x3020)
#define REG_EMIARB_CONM					(BASE_ADDR_EMIARB + 0x3060)
#define REG_EMIARB_TESTC				(BASE_ADDR_EMIARB + 0x30F0)
#define REG_EMIARB_TESTC_1				(BASE_ADDR_EMIARB + 0x30F4)
#define REG_EMIARB_TESTD				(BASE_ADDR_EMIARB + 0x30F8)
#define REG_EMIARB_TESTD_1				(BASE_ADDR_EMIARB + 0x30FC)
#define REG_EMIARB_ARBA					(BASE_ADDR_EMIARB + 0x3100)
#define REG_EMIARB_ARBB					(BASE_ADDR_EMIARB + 0x3108)
#define REG_EMIARB_ARBC					(BASE_ADDR_EMIARB + 0x3110)
#define REG_EMIARB_ARBD					(BASE_ADDR_EMIARB + 0x3118)
#define REG_EMIARB_ARBE					(BASE_ADDR_EMIARB + 0x3120)
#define REG_EMIARB_ARBF					(BASE_ADDR_EMIARB + 0x3128)
#define REG_EMIARB_ARBI					(BASE_ADDR_EMIARB + 0x3140)
#define REG_EMIARB_ARBI_1				(BASE_ADDR_EMIARB + 0x3144)
#define REG_EMIARB_ARBJ					(BASE_ADDR_EMIARB + 0x3148)
#define REG_EMIARB_ARBK					(BASE_ADDR_EMIARB + 0x3150)
#define REG_EMIARB_SLCT					(BASE_ADDR_EMIARB + 0x3158)
#define REG_EMIARB_SLCT2				(BASE_ADDR_EMIARB + 0x315C)
#define REG_EMIARB_ARBL					(BASE_ADDR_EMIARB + 0x3160)
#define REG_EMIARB_ARBM					(BASE_ADDR_EMIARB + 0x3168)
#define REG_EMIARB_ARBN					(BASE_ADDR_EMIARB + 0x3170)
#define REG_EMIARB_ARBO					(BASE_ADDR_EMIARB + 0x3178)
#define REG_EMIARB_ARBP					(BASE_ADDR_EMIARB + 0x3180)
#define REG_EMIARB_ARBQ					(BASE_ADDR_EMIARB + 0x3188)
#define REG_EMIARB_ARBR					(BASE_ADDR_EMIARB + 0x3190)
#define REG_EMIARB_ARBS					(BASE_ADDR_EMIARB + 0x3198)
#define REG_EMIARB_ARBT					(BASE_ADDR_EMIARB + 0x3200)
#define REG_EMIARB_ARBU					(BASE_ADDR_EMIARB + 0x3208)
#define REG_EMIARB_ARBV					(BASE_ADDR_EMIARB + 0x3210)
#define REG_EMIARB_ARBW					(BASE_ADDR_EMIARB + 0x3218)
#define REG_EMIARB_ARBX					(BASE_ADDR_EMIARB + 0x3220)
#define REG_EMIARB_RMPU1				(BASE_ADDR_EMIARB + 0x3228)
#define REG_EMIARB_RMPU2				(BASE_ADDR_EMIARB + 0x3230)
#define REG_EMIARB_RMPU3				(BASE_ADDR_EMIARB + 0x3238)
#define REG_EMIARB_RMPU4				(BASE_ADDR_EMIARB + 0x3240)
#define REG_EMIARB_RMPUA				(BASE_ADDR_EMIARB + 0x4000)
#define REG_EMIARB_RMPUA_1				(BASE_ADDR_EMIARB + 0x4008)
#define REG_EMIARB_RMPUB				(BASE_ADDR_EMIARB + 0x4010)
#define REG_EMIARB_RMPUB_1				(BASE_ADDR_EMIARB + 0x4018)
#define REG_EMIARB_RMPUC				(BASE_ADDR_EMIARB + 0x4020)
#define REG_EMIARB_RMPUC_1				(BASE_ADDR_EMIARB + 0x4028)
#define REG_EMIARB_RMPUD				(BASE_ADDR_EMIARB + 0x4030)
#define REG_EMIARB_RMPUD_1				(BASE_ADDR_EMIARB + 0x4038)
#define REG_EMIARB_RMPUE				(BASE_ADDR_EMIARB + 0x4040)
#define REG_EMIARB_RMPUE_1				(BASE_ADDR_EMIARB + 0x4048)
#define REG_EMIARB_RMPUF				(BASE_ADDR_EMIARB + 0x4050)
#define REG_EMIARB_RMPUF_1				(BASE_ADDR_EMIARB + 0x4058)
#define REG_EMIARB_RMPUG				(BASE_ADDR_EMIARB + 0x4060)
#define REG_EMIARB_RMPUG_1				(BASE_ADDR_EMIARB + 0x4068)
#define REG_EMIARB_RMPUH				(BASE_ADDR_EMIARB + 0x4070)
#define REG_EMIARB_RMPUH_1				(BASE_ADDR_EMIARB + 0x4078)
#define REG_EMIARB_RMPUI				(BASE_ADDR_EMIARB + 0x4100)
#define REG_EMIARB_RMPUI_1				(BASE_ADDR_EMIARB + 0x4108)
#define REG_EMIARB_RMPUJ				(BASE_ADDR_EMIARB + 0x4110)
#define REG_EMIARB_RMPUJ_1				(BASE_ADDR_EMIARB + 0x4118)
#define REG_EMIARB_RMPUK				(BASE_ADDR_EMIARB + 0x4120)
#define REG_EMIARB_RMPUK_1				(BASE_ADDR_EMIARB + 0x4128)
#define REG_EMIARB_RMPUL				(BASE_ADDR_EMIARB + 0x4130)
#define REG_EMIARB_RMPUL_1				(BASE_ADDR_EMIARB + 0x4138)
#define REG_EMIARB_RMPUM				(BASE_ADDR_EMIARB + 0x4200)
#define REG_EMIARB_RMPUM_1				(BASE_ADDR_EMIARB + 0x4208)
#define REG_EMIARB_RMPUN				(BASE_ADDR_EMIARB + 0x4210)
#define REG_EMIARB_RMPUN_1				(BASE_ADDR_EMIARB + 0x4218)
#define REG_EMIARB_RMPUO				(BASE_ADDR_EMIARB + 0x4220)
#define REG_EMIARB_RMPUO_1				(BASE_ADDR_EMIARB + 0x4228)
#define REG_EMIARB_RMPUP				(BASE_ADDR_EMIARB + 0x4230)
#define REG_EMIARB_RMPUP_1				(BASE_ADDR_EMIARB + 0x4238)
#define REG_EMIARB_RMPUU				(BASE_ADDR_EMIARB + 0x4318)
#define REG_EMIARB_RMPUV				(BASE_ADDR_EMIARB + 0x4320)
#define REG_EMIARB_RMPUW				(BASE_ADDR_EMIARB + 0x4328)
#define REG_EMIARB_NPD_DUMMY			(BASE_ADDR_EMIARB + 0x5000)

#define REG_EMIARB_BWL_CTL(lyr)			(REG_EMIARB_ARBA + ((lyr) << 3))

// Register protection
#define EMIRMPU_PWD						(0x72081DA8)
#define UNLOCK_EMI_REG()				DRV_WriteReg32_NPW(REG_EMIARB_RMPUW, EMIRMPU_PWD)
#define LOCK_EMI_REG()					DRV_WriteReg32_NPW(REG_EMIARB_RMPUW, 0)

/*
 * EMI FINE CLK OFF
 */
#define EMI_WR_ALWAYS_ON_REG32(addr, val) \
	do {\
		kal_uint32 rmpuw = 0;\
		rmpuw = DRV_Reg32(REG_EMIARB_RMPUW);	\
		UNLOCK_EMI_REG();\
		DRV_WriteReg32_NPW(addr, val);\
		if (EMIRMPU_PWD != rmpuw) {\
			LOCK_EMI_REG();	\
		}\
		Data_Mem_Barrier();\
	} while(0)

#if defined(MT6290_S01)
#define EMI_FINE_CLK_OFF_EN() \
	do {\
		EMI_WR_ALWAYS_ON_REG32(REG_EMIARB_TESTC_1, DRV_Reg32(REG_EMIARB_TESTC_1) | 0x80000000);\
	}while(0)

#define EMI_FINE_CLK_OFF_DIS() \
	do {\
		EMI_WR_ALWAYS_ON_REG32(REG_EMIARB_TESTC_1, DRV_Reg32(REG_EMIARB_TESTC_1) & 0x7FFFFFFF);\
	}while(0)
// ACCESS EMI PD REG
#define EMI_PD_REG_ACCESS_EN() \
	do {\
		EMI_WR_ALWAYS_ON_REG32(REG_EMIARB_TESTC_1, DRV_Reg32(REG_EMIARB_TESTC_1) | 0x40000000);\
	}while(0)
#define EMI_PD_REG_ACCESS_DIS() \
	do {\
		EMI_WR_ALWAYS_ON_REG32(REG_EMIARB_TESTC_1, DRV_Reg32(REG_EMIARB_TESTC_1) & 0xBFFFFFFF);\
	}while(0)
#else
#define EMI_FINE_CLK_OFF_EN()
#define EMI_FINE_CLK_OFF_DIS()
#define EMI_PD_REG_ACCESS_EN()
#define EMI_PD_REG_ACCESS_DIS()
#endif	

// Layer Definitions
#define EMIARB_LYR_MDMCU		0
#define EMIARB_LYR_MDPERI		1
#define EMIARB_LYR_APMCU		2
#define EMIARB_LYR_APPERI		3
#define EMIARB_LYR_MODEM		4
#define EMIARB_LYR_HARQ			5
#define EMIARB_LYR_ARM7			6
#define EMIARB_LYR_L1DMA		7

#define EMIARB_MAX_BST_LEN		128

// RMPU
#define EMIARB_RMPUS_CLR		(1 << 31)
#define EMIARB_RMPUS_W_VIO 		(1 << 28)
#define EMIARB_RMPUS_OOR_VIO		(1 << 26)
#define EMIARB_RMPUS_REGION_OFFSET 	(16)
#define EMIARB_RMPUS_REGION_MASK	(0xFF << EMIARB_RMPUS_REGION_OFFSET)
#define EMIARB_RMPUS_DOMAIN_ID_OFFSET	(12)
#define EMIARB_RMPUS_DOMAIN_ID_MASK	(0x7 << EMIARB_RMPUS_DOMAIN_ID_OFFSET)
#define EMIARB_RMPUS_MASTER_ID_OFFSET	(0)
#define EMIARB_RMPUS_MASTER_ID_MASK	(0x7FF << EMIARB_RMPUS_MASTER_ID_OFFSET)
#define EMIARB_RMPUS_1_BS_OFFSET	(20)
#define EMIARB_RMPUS_1_BS_MASK 		(0x7 << EMIARB_RMPUS_1_BS_OFFSET)
#define EMIARB_RMPUS_1_BL_OFFSET	(16)
#define EMIARB_RMPUS_1_BL_MASK 		(0xF << EMIARB_RMPUS_1_BL_OFFSET)
#define EMIARB_RMPUS_1_BT_OFFSET	(8)
#define EMIARB_RMPUS_1_BT_MASK 		(0x3 << EMIARB_RMPUS_1_BT_OFFSET)
#define EMIARB_RMPUS_1_SECURE		(1 << 0)

// MISC
#define EMIARB_AGE_SPEED_MASK		(3U<<8)
#define EMIARB_EN					(1U<<10)

// Address Decoding Definitions
#define EMIARB_MAX_CHN_LOG		1
#define EMIARB_MIN_CHN_LOG		0
#define EMIARB_MAX_RANK_LOG		1
#define EMIARB_MIN_RANK_LOG		0
#define EMIARB_MAX_BANK_LOG		3
#define EMIARB_MIN_BANK_LOG		2
#define EMIARB_MAX_ROW_LOG		15
#define EMIARB_MIN_ROW_LOG		12
#define EMIARB_MAX_COL_LOG		11
#define EMIARB_MIN_COL_LOG		8
#define EMIARB_MAX_BUSW_LOG		2
#define EMIARB_MIN_BUSW_LOG		1

#define EMIARB_ENABLE(_en)		\
	do {		\
		UNLOCK_EMI_REG();	\
		if ((_en)) {	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_MDMCU)) = 0x0;	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_MDPERI)) = 0x0;	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_APMCU)) = 0x0;	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_APPERI)) = 0x0;	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_MODEM)) = 0x0;	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_HARQ)) = 0x0;	\
		} else {	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_MDMCU)) = 0x4800;	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_MDPERI)) = 0x4800;	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_APMCU)) = 0x4800;	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_APPERI)) = 0x4800;	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_MODEM)) = 0x4800;	\
			DRV_Reg32(REG_EMIARB_BWL_CTL(EMIARB_LYR_HARQ)) = 0x4800;	\
		}	\
		LOCK_EMI_REG();	\
	} while(0)

/* ==================== */
/*	EBM CONTROL API		*/
/* ==================== */
enum {
	EMI_LYRBMP_MDMCU = (0x01 << EMIARB_LYR_MDMCU),
	EMI_LYRBMP_MDPERI = (0x01 << EMIARB_LYR_MDPERI),
	EMI_LYRBMP_APMCU = (0x01 << EMIARB_LYR_APMCU),
	EMI_LYRBMP_APPERI = (0x01 << EMIARB_LYR_APPERI),
	EMI_LYRBMP_MODEM = (0x01 << EMIARB_LYR_MODEM),
	EMI_LYRBMP_HARQ = (0x01 << EMIARB_LYR_HARQ),
	EMI_LYRBMP_ARM7 = (0x01 << EMIARB_LYR_ARM7),
	EMI_LYRBMP_L1DMA = (0x01 << EMIARB_LYR_L1DMA)
};	

enum {
	// Naming: Beat Number + Bus Width
	WR1_1B = 0x00, WR2_1B = 0x01, WR3_1B = 0x02, WR4_1B = 0x03,
	WR5_1B = 0x04, WR6_1B = 0x05, WR7_1B = 0x06, WR8_1B = 0x07,
	WR9_1B = 0x08, WR10_1B = 0x09, WR11_1B = 0x0A, WR12_1B = 0x0B,
	WR13_1B = 0x0C, WR14_1B = 0x0D, WR15_1B = 0x0E, WR16_1B = 0x0F,

	WR1_2B = 0x10, WR2_2B = 0x11, WR3_2B = 0x12, WR4_2B = 0x13,
	WR5_2B = 0x14, WR6_2B = 0x15, WR7_2B = 0x16, WR8_2B = 0x17,
	WR9_2B = 0x18, WR10_2B = 0x19, WR11_2B = 0x1A, WR12_2B = 0x1B,
	WR13_2B = 0x1C, WR14_2B = 0x1D, WR15_2B = 0x1E, WR16_2B = 0x1F,

	WR1_4B = 0x20, WR2_4B = 0x21, WR3_4B = 0x22, WR4_4B = 0x23,
	WR5_4B = 0x24, WR6_4B = 0x25, WR7_4B = 0x26, WR8_4B = 0x27,
	WR9_4B = 0x28, WR10_4B = 0x29, WR11_4B = 0x2A, WR12_4B = 0x2B,
	WR13_4B = 0x2C, WR14_4B = 0x2D, WR15_4B = 0x2E, WR16_4B = 0x2F,

	WR1_8B = 0x30, WR2_8B = 0x31, WR3_8B = 0x32, WR4_8B = 0x33,
	WR5_8B = 0x34, WR6_8B = 0x35, WR7_8B = 0x36, WR8_8B = 0x37,
	WR9_8B = 0x38, WR10_8B = 0x39, WR11_8B = 0x3A, WR12_8B = 0x3B,
	WR13_8B = 0x3C, WR14_8B = 0x3D, WR15_8B = 0x3E, WR16_8B = 0x3F,

	INC1_1B = 0x80, INC2_1B = 0x81, INC3_1B = 0x82, INC4_1B = 0x83,
	INC5_1B = 0x84, INC6_1B = 0x85, INC7_1B = 0x86, INC8_1B = 0x87,
	INC9_1B = 0x88, INC10_1B = 0x89, INC11_1B = 0x8A, INC12_1B = 0x8B,
	INC13_1B = 0x8C, INC14_1B = 0x8D, INC15_1B = 0x8E, INC16_1B = 0x8F,

	INC1_2B = 0x90, INC2_2B = 0x91, INC3_2B = 0x92, INC4_2B = 0x93,
	INC5_2B = 0x94, INC6_2B = 0x95, INC7_2B = 0x96, INC8_2B = 0x97,
	INC9_2B = 0x98, INC10_2B = 0x99, INC11_2B = 0x9A, INC12_2B = 0x9B,
	INC13_2B = 0x9C, INC14_2B = 0x9D, INC15_2B = 0x9E, INC16_2B = 0x9F,

	INC1_4B = 0xA0, INC2_4B = 0xA1, INC3_4B = 0xA2, INC4_4B = 0xA3,
	INC5_4B = 0xA4, INC6_4B = 0xA5, INC7_4B = 0xA6, INC8_4B = 0xA7,
	INC9_4B = 0xA8, INC10_4B = 0xA9, INC11_4B = 0xAA, INC12_4B = 0xAB,
	INC13_4B = 0xAC, INC14_4B = 0xAD, INC15_4B = 0xAE, INC16_4B = 0xAF,

	INC1_8B = 0xB0, INC2_8B = 0xB1, INC3_8B = 0xB2, INC4_8B = 0xB3,
	INC5_8B = 0xB4, INC6_8B = 0xB5, INC7_8B = 0xB6, INC8_8B = 0xB7,
	INC9_8B = 0xB8, INC10_8B = 0xB9, INC11_8B = 0xBA, INC12_8B = 0xBB,
	INC13_8B = 0xBC, INC14_8B = 0xBD, INC15_8B = 0xBE, INC16_8B = 0xBF
};

/*
 *	Return the transaction symbol
 *	incr		0: WRAP / 1: INCR
 *	width_ln	0: 1B / 1: 2B / 2: 4B / 3: 8B
 *	length		1 ~ 16
 */
#define GET_TRANS_SYMB(incr, width_ln, beats)	((((incr)?1:0) << 7) | ((width_ln) << 4) | (beats - 1))

/*
 *	Set EBM Type Counter Definition
 *	c: Type Counter Index (0 ~ 20)
 *	m: AXI port bitmap
 *	u: ultra flag
 *	t: Transaction Type
 */
#define EBM_MSEL_SET(c, m, t, u)    \
        do {\
			EMI_PD_REG_ACCESS_EN();\
			if (((kal_uint32)(c) > 20)) {\
				ASSERT(0);\
			}\
			if (((kal_uint32)(c) & 0x01)) {\
                DRV_WriteReg32(REG_EMIARB_MSEL(((kal_uint32)(c) >> 1) + 1), (DRV_Reg32(REG_EMIARB_MSEL(((kal_uint32)(c) >> 1) + 1)) & 0x0000FFFF) | (((kal_uint32)(m)) << 16) | ((kal_uint32)(t) << 24)); \
			}\
			else {\
                DRV_WriteReg32(REG_EMIARB_MSEL(((kal_uint32)(c) >> 1) + 1), (DRV_Reg32(REG_EMIARB_MSEL(((kal_uint32)(c) >> 1) + 1)) & 0xFFFF0000) | ((kal_uint32)(m)) | ((kal_uint32)(t) << 8)); \
			}\
			DRV_WriteReg32(REG_EMIARB_BMEN1, DRV_Reg32(REG_EMIARB_BMEN1) & 0xFFE00000);\
			DRV_WriteReg32(REG_EMIARB_BMEN1, DRV_Reg32(REG_EMIARB_BMEN1) | ((u) << (c)));\
			EMI_PD_REG_ACCESS_DIS();\
        } while(0)

/*
 *	Set EBM Type Counter AXI ID
 *	c: Type Counter Index (0 ~ 20)
 *	id: AXI ID
 *	The AXI ID (8 bits) contains the Master's AXI ID & Fabric appended ID.
 *	The Port ID added by EMI need to be defined in the type counter's AXI port bitmap
 */
#define EBM_SET_AXI_ID(c, id) \
		do {\
			EMI_PD_REG_ACCESS_EN();\
			if (((kal_uint32)(c) > 20)) {\
				ASSERT(0);\
			}\
			DRV_WriteReg32(REG_EMIARB_BMID(((c)) >> 2), DRV_Reg32(REG_EMIARB_BMID((c) >> 2)) & (~(0xFF << ((c) << 3))));\
			DRV_WriteReg32(REG_EMIARB_BMID(((c)) >> 2), DRV_Reg32(REG_EMIARB_BMID((c) >> 2)) | ((id) << ((c) << 3)));\
			DRV_WriteReg32(REG_EMIARB_BMEN2, DRV_Reg32(REG_EMIARB_BMEN2) | (1 << (c)));\
			EMI_PD_REG_ACCESS_DIS();\
        } while(0)

/*
 *	Clear EBM Type Counter AXI ID
 *	c: Type Counter Index (0 ~ 20)
 *	Clear the AXI ID setting which means the target Type Counter will not filter transaction by AXI ID
 */
#define EBM_CLR_AXI_ID(c) \
		do {\
			EMI_PD_REG_ACCESS_EN();\
			if (((kal_uint32)(c) > 20)) {\
				ASSERT(0);\
			}\
			DRV_WriteReg32(REG_EMIARB_BMID((c) >> 2), DRV_Reg32(REG_EMIARB_BMID((c) >> 2)) & (~(0xFF << ((c) << 3))));\
			DRV_WriteReg32(REG_EMIARB_BMEN2, DRV_Reg32(REG_EMIARB_BMEN2) & (~(1 << (c))));\
			EMI_PD_REG_ACCESS_DIS();\
        } while(0)


/*
 *	Set EBM R/W direction
 *	v: Read Write Direction
 *	This setting doesn't take effect on
 *	1. Bus Cycle Counter
 *	2. Total Transcation Counter
 *	3. Total DWORD Counter
 *	4. Bandwidth Counter
 *	5. Overhead DWORD Counter
 *	6. Bank Counter
 *	7. Collector Usage Counter
 *	8. Pre-Arb Winner Counter
 *	9. OT Counter
 */
enum {
	EBM_NONE = 0x0,
	EBM_READ_ONLY = 0x1,
	EBM_WRITE_ONLY = 0x2,
	EBM_READ_WRITE = 0x3
};
#define EBM_SET_RW_REQ(v) \
		do {\
			EMI_PD_REG_ACCESS_EN();\
			DRV_WriteReg32(REG_EMIARB_BMEN, (DRV_Reg32(REG_EMIARB_BMEN) & 0xFFFFFFCF) | ((kal_uint32)(v) << 4));\
			EMI_PD_REG_ACCESS_DIS();\
		} while(0);

/*
 *	Set EBM Function
 *	f: function
 *	The function must be set before EBM_START()
 *	EBM Write Latency can't be set after EBM has ever been started
 */
enum {
	EBM_FUNC_NORMAL = 0,
	EBM_FUNC_BANK = 1,
	EBM_FUNC_COLLECTOR = 2,
	EBM_FUNC_LATENCY = 3,
	EBM_FUNC_PRE_WIN = 4,
	EBM_FUNC_OT_CNT = 5
};

#define EBM_SET_FUNC(f) \
		do { \
			EMI_PD_REG_ACCESS_EN(); \
			DRV_WriteReg32(REG_EMIARB_BMEN2, DRV_Reg32(REG_EMIARB_BMEN2) & 0xFEFFFFFF);\
			DRV_WriteReg32(REG_EMIARB_MISC, 0x00000000);\
			switch (f) {\
				case EBM_FUNC_NORMAL:\
					break;\
				case EBM_FUNC_BANK:\
					DRV_WriteReg32(REG_EMIARB_BMEN2, DRV_Reg32(REG_EMIARB_BMEN2) | 0x01000000);\
					break;\
				case EBM_FUNC_COLLECTOR:\
					DRV_WriteReg32(REG_EMIARB_MISC, DRV_Reg32(REG_EMIARB_MISC) | 0x00000001);\
					break;\
				case EBM_FUNC_LATENCY:\
					DRV_WriteReg32(REG_EMIARB_MISC, DRV_Reg32(REG_EMIARB_MISC) | 0x00000002);\
					break;\
				case EBM_FUNC_PRE_WIN:\
					DRV_WriteReg32(REG_EMIARB_MISC, DRV_Reg32(REG_EMIARB_MISC) | 0x00000004);\
					break;\
				case EBM_FUNC_OT_CNT:\
					DRV_WriteReg32(REG_EMIARB_MISC, DRV_Reg32(REG_EMIARB_MISC) | 0x00000008);\
					break;\
				default:\
					ASSERT(0);\
			}\
			EMI_PD_REG_ACCESS_DIS();\
		} while(0)

#define EBM_GET_FUNC(p_func)\
	do {\
		EMI_PD_REG_ACCESS_EN();\
		if (DRV_Reg32(REG_EMIARB_BMEN2) & 0x01000000) {\
			*p_func = EBM_FUNC_BANK;\
		}\
		else if (DRV_Reg32(REG_EMIARB_MISC) & 0x00000001) {\
			*p_func = EBM_FUNC_COLLECTOR;\
		}\
		else if (DRV_Reg32(REG_EMIARB_MISC) & 0x00000002) {\
			*p_func = EBM_FUNC_LATENCY;\
		}\
		else if (DRV_Reg32(REG_EMIARB_MISC) & 0x00000004) {\
			*p_func = EBM_FUNC_PRE_WIN;\
		}\
		else if (DRV_Reg32(REG_EMIARB_MISC) & 0x00000008) {\
			*p_func = EBM_FUNC_OT_CNT;\
		}\
		else {\
			*p_func = EBM_FUNC_NORMAL;\
		}\
		EMI_PD_REG_ACCESS_DIS();\
	} while(0)

/*
 *	Clear EBM Counters
 *	The will stop & clear EBM counters
 */
#define EBM_CLR()	\
		do {\
			EMI_PD_REG_ACCESS_EN();\
			DRV_WriteReg32_NPW(REG_EMIARB_BMEN, DRV_Reg32(REG_EMIARB_BMEN) & 0xFFFFFFFC);\
			EMI_PD_REG_ACCESS_DIS();\
		} while(0)

/*
 *	Check if EBM is overrun
 *	The will stop & clear EBM counters
 */
#define EBM_IS_OVERRUN() \
	do {\
		EMI_PD_REG_ACCESS_EN();\
		((DRV_Reg32(REG_EMIARB_BMEN) & 0x00000100)?1:0)\
		EMI_PD_REG_ACCESS_DIS();\
	}while(0)


/*
 *	Start EBM counters
 */
#define EBM_START() \
		do {\
			EMI_PD_REG_ACCESS_EN();\
			if (DRV_Reg32(REG_EMIARB_MISC)) {\
				DRV_WriteReg32(REG_EMIARB_BMEN, DRV_Reg32(REG_EMIARB_BMEN) | 0x00000001);\
				DRV_WriteReg32(REG_EMIARB_BMEN, DRV_Reg32(REG_EMIARB_BMEN) & 0xFFFFFFFC);\
				DRV_WriteReg32_NPW(REG_EMIARB_BMEN, DRV_Reg32(REG_EMIARB_BMEN) | 0x00000001);\
			}\
			else {\
				DRV_WriteReg32_NPW(REG_EMIARB_BMEN, DRV_Reg32(REG_EMIARB_BMEN) | 0x00000001);\
			}\
			EMI_PD_REG_ACCESS_DIS();\
		} while(0)

/*
 *	Pause EBM counters
 */
#define EBM_PAUSE() \
		do {\
			EMI_PD_REG_ACCESS_EN();\
			DRV_WriteReg32_NPW(REG_EMIARB_BMEN, DRV_Reg32(REG_EMIARB_BMEN) | 0x00000002);\
			EMI_PD_REG_ACCESS_DIS();\
		} while(0)

/*
 *	Get EBM counters
 */
typedef struct __ebm_norm_t__ {
	kal_uint32 trans_cnt[3];
	kal_uint32 ttype_cnt[21];
} ebm_norm_t;

typedef struct __ebm_bank_t__ {
	kal_uint32 trans_cnt[3];
	kal_uint32 resv0[9];
	kal_uint32 bank_cnt[8];
	kal_uint32 resv1[4];
} ebm_bank_t;

typedef struct __ebm_collector_t__ {
	kal_uint32 trans_cnt[3];
	kal_uint32 max_m0_r_collector;
	kal_uint32 min_m0_r_collector;
	kal_uint32 accu_m0_r_collector;
	kal_uint32 max_m0_w_collector;
	kal_uint32 min_m0_w_collector;
	kal_uint32 accu_m0_w_collector;
	kal_uint32 max_shr_r_collector;
	kal_uint32 min_shr_r_collector;
	kal_uint32 accu_shr_r_collector;
	kal_uint32 max_shr_w_collector;
	kal_uint32 min_shr_w_collector;
	kal_uint32 accu_shr_w_collector;
	kal_uint32 max_m5_r_collector;
	kal_uint32 min_m5_r_collector;
	kal_uint32 accu_m5_r_collector;
	kal_uint32 max_m5_w_collector;
	kal_uint32 min_m5_w_collector;
	kal_uint32 accu_m5_w_collector;
	kal_uint32 resv0[3];
} ebm_collector_t;

typedef struct __ebm_lat_t__ {

	kal_uint32 min_m5_lat_cnt;
	kal_uint32 accu_m5_lat_cnt;
	kal_uint32 accu_m5_trans_cnt;

	kal_uint32 max_m0_lat_cnt;
	kal_uint32 min_m0_lat_cnt;
	kal_uint32 accu_m0_lat_cnt;
	kal_uint32 accu_m0_trans_cnt;

	kal_uint32 max_m1_lat_cnt;
	kal_uint32 min_m1_lat_cnt;
	kal_uint32 accu_m1_lat_cnt;
	kal_uint32 accu_m1_trans_cnt;

	kal_uint32 max_m2_lat_cnt;
	kal_uint32 min_m2_lat_cnt;
	kal_uint32 accu_m2_lat_cnt;
	kal_uint32 accu_m2_trans_cnt;

	kal_uint32 max_m3_lat_cnt;
	kal_uint32 min_m3_lat_cnt;
	kal_uint32 accu_m3_lat_cnt;
	kal_uint32 accu_m3_trans_cnt;

	kal_uint32 max_m4_lat_cnt;
	kal_uint32 min_m4_lat_cnt;
	kal_uint32 accu_m4_lat_cnt;
	kal_uint32 accu_m4_trans_cnt;

	kal_uint32 max_m5_lat_cnt;
} ebm_lat_t;

typedef struct __ebm_prewin_t__ {
	kal_uint32 trans_cnt[3];
	kal_uint32 m0_r_prewin_win_cnt;
	kal_uint32 resv0;
	kal_uint32 m1_r_prewin_win_cnt;
	kal_uint32 m1_w_prewin_win_cnt;
	kal_uint32 m2_r_prewin_win_cnt;
	kal_uint32 m2_w_prewin_win_cnt;
	kal_uint32 m3_r_prewin_win_cnt;
	kal_uint32 m3_w_prewin_win_cnt;
	kal_uint32 m4_r_prewin_win_cnt;
	kal_uint32 m4_w_prewin_win_cnt;
	kal_uint32 resv1[11];

} ebm_prewin_t;

typedef struct __ebm_ot_t__ {
	kal_uint32 trans_cnt[3];
	kal_uint32 ot_cnt;
	kal_uint32 resv[20];

} ebm_ot_t;

typedef struct __ebm_cnt_t__ {

	/* EMI Bus Cycle Counter (based on EMI clock) */
	kal_uint32 emi_bus_cyc;

	/* Total Transcation Counter (All Layers) */
	kal_uint32 total_trans_cnt;

	/* Total DWORD (8 bytes) Counter (All Layers) */
	kal_uint32 total_dword_cnt;

	/* Banwidth DDWORD (16 bytes) counter */
	/* This is only for the layers selected by type counter 0*/
	kal_uint32 bw_ddword_cnt;

	/* Overhead DWORD Counter */
	kal_uint32 overhead_dword_cnt;

	/* DWORD Counter (8 bytes) counter */
	/* This is only for the layers selected by corresponding type counter */
	kal_uint32 dword_cnt[4];

	/* Different Counter definitions */
	/* User must choose correct structure to explain the counters */
	union {
		ebm_norm_t norm;
		ebm_bank_t bank;
		ebm_collector_t collector;
		ebm_lat_t lat;
		ebm_prewin_t prewin;
		ebm_ot_t ot;
	};
} ebm_cnt_t;

/*
 * Get EBM Counters
 * p: pointer to ebm_cnt_t to store the counter values
 */
#define EBM_GET_CNTS(p)\
	do {\
		EMI_PD_REG_ACCESS_EN();\
		(p)->emi_bus_cyc = DRV_Reg32(REG_EMIARB_BCNT);\
		(p)->total_trans_cnt = DRV_Reg32(REG_EMIARB_TACT);\
		(p)->total_dword_cnt = DRV_Reg32(REG_EMIARB_WACT);\
		(p)->bw_ddword_cnt = DRV_Reg32(REG_EMIARB_BACT);\
		(p)->overhead_dword_cnt = DRV_Reg32(REG_EMIARB_BSCT);\
		(p)->dword_cnt[0] = DRV_Reg32(REG_EMIARB_WSCT(1));\
		(p)->dword_cnt[1] = DRV_Reg32(REG_EMIARB_WSCT(2));\
		(p)->dword_cnt[2] = DRV_Reg32(REG_EMIARB_WSCT(3));\
		(p)->dword_cnt[3] = DRV_Reg32(REG_EMIARB_WSCT(4));\
		(p)->norm.trans_cnt[0] = DRV_Reg32(REG_EMIARB_TSCT(1));\
		(p)->norm.trans_cnt[1] = DRV_Reg32(REG_EMIARB_TSCT(2));\
		(p)->norm.trans_cnt[2] = DRV_Reg32(REG_EMIARB_TSCT(3));\
		(p)->norm.ttype_cnt[0] = DRV_Reg32(REG_EMIARB_TTYPE(1));\
		(p)->norm.ttype_cnt[1] = DRV_Reg32(REG_EMIARB_TTYPE(2));\
		(p)->norm.ttype_cnt[2] = DRV_Reg32(REG_EMIARB_TTYPE(3));\
		(p)->norm.ttype_cnt[3] = DRV_Reg32(REG_EMIARB_TTYPE(4));\
		(p)->norm.ttype_cnt[4] = DRV_Reg32(REG_EMIARB_TTYPE(5));\
		(p)->norm.ttype_cnt[5] = DRV_Reg32(REG_EMIARB_TTYPE(6));\
		(p)->norm.ttype_cnt[6] = DRV_Reg32(REG_EMIARB_TTYPE(7));\
		(p)->norm.ttype_cnt[7] = DRV_Reg32(REG_EMIARB_TTYPE(8));\
		(p)->norm.ttype_cnt[8] = DRV_Reg32(REG_EMIARB_TTYPE(9));\
		(p)->norm.ttype_cnt[9] = DRV_Reg32(REG_EMIARB_TTYPE(10));\
		(p)->norm.ttype_cnt[10] = DRV_Reg32(REG_EMIARB_TTYPE(11));\
		(p)->norm.ttype_cnt[11] = DRV_Reg32(REG_EMIARB_TTYPE(12));\
		(p)->norm.ttype_cnt[12] = DRV_Reg32(REG_EMIARB_TTYPE(13));\
		(p)->norm.ttype_cnt[13] = DRV_Reg32(REG_EMIARB_TTYPE(14));\
		(p)->norm.ttype_cnt[14] = DRV_Reg32(REG_EMIARB_TTYPE(15));\
		(p)->norm.ttype_cnt[15] = DRV_Reg32(REG_EMIARB_TTYPE(16));\
		(p)->norm.ttype_cnt[16] = DRV_Reg32(REG_EMIARB_TTYPE(17));\
		(p)->norm.ttype_cnt[17] = DRV_Reg32(REG_EMIARB_TTYPE(18));\
		(p)->norm.ttype_cnt[18] = DRV_Reg32(REG_EMIARB_TTYPE(19));\
		(p)->norm.ttype_cnt[19] = DRV_Reg32(REG_EMIARB_TTYPE(20));\
		(p)->norm.ttype_cnt[20] = DRV_Reg32(REG_EMIARB_TTYPE(21));\
		EMI_PD_REG_ACCESS_DIS();\
	} while(0)

/*
 * EBM Init (Empty)
 */
#define EBM_INIT()	/* Do nothing */

/*
 * EBM Get MCU Instruction Bus Log (Empty)
 */
#define EBM_GET_MCU_IBUS_LOG(l) /* Do nothing */

/*
 * EBM Get MCU Data Bus Log (Empty)
 */
#define EBM_GET_MCU_DBUS_LOG()

/*
 * EBM Resume (Equal to EBM_START())
 */
#define EBM_RESUME()	EBM_START()

/*
 * EBM Stop (Equal to EBM_CLR())
 */
#define EBM_STOP()		EBM_CLR()

/* ==================== */
/*	ELM CONTROL API		*/
/* ==================== */
#define REG_ELM_CTRL					(BASE_ADDR_MDMCUMISC + 0x0098)
#define REG_ELM_STAT					(BASE_ADDR_MDMCUMISC + 0x009C)

// ELM Set Mode (HW/SW Mode)
enum {
	ELM_SW_MODE = 0,
	ELM_HW_MODE = 1
};
#define ELM_SET_MODE(m) \
	do {\
		DRV_WriteReg32(REG_ELM_CTRL, DRV_Reg32(REG_ELM_CTRL) & 0xFFFFFFFB);	\
		DRV_WriteReg32(REG_ELM_CTRL, DRV_Reg32(REG_ELM_CTRL) | ((kal_uint32)(m) << 2));\
	} while(0)

// ELM HW Mode Period
#define ELM_SET_HW_PERIOD(t) \
	do {\
		if (t > (1 << 20)) {\
			ASSERT(0);\
		}\
		DRV_WriteReg32(REG_ELM_CTRL, DRV_Reg32(REG_ELM_CTRL) & 0xFF800007);	\
		DRV_WriteReg32(REG_ELM_CTRL, DRV_Reg32(REG_ELM_CTRL) | ((kal_uint32)(t) << 3));\
	} while(0)

// ELM Clear
#define ELM_CLR()	\
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CTRL, DRV_Reg32(REG_ELM_CTRL) & 0xFFFFFFFC);\
		} while(0)

// ELM Start
#define ELM_START() \
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CTRL, DRV_Reg32(REG_ELM_CTRL) | 0x00000001);\
		} while(0)

// ELM Pause
#define ELM_PAUSE() \
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CTRL, DRV_Reg32(REG_ELM_CTRL) | 0x00000002);\
		} while(0);

// ELM Counter Selection
enum {
	ELM_WR = 0,
	ELM_RD = 1
};

enum {
	ELM_TYPE_TRANS = 0,
	ELM_TYPE_LATENCY = 1
};
#define ELM_GET_CNT(rw, type, idx, p_cnt) \
	do {\
		DRV_WriteReg32(REG_ELM_CTRL, (DRV_Reg32(REG_ELM_CTRL) & 0xF07FFFFF) | (type << 23) | (rw << 24) | (idx << 25));\
		*p_cnt = DRV_Reg32(REG_ELM_STAT);\
	} while(0)

// ELM Summary (Current HW_idx, Overrun indication)
#define ELM_GET_SUMMARY(p_hw_idx, p_overrun) \
	do {\
		DRV_WriteReg32(REG_ELM_CTRL, (DRV_Reg32(REG_ELM_CTRL) & 0xF07FFFFF) | 0x08000000);\
		*p_hw_idx = (DRV_Reg32(REG_ELM_STAT) >> 8) & 0x00000003;\
		*p_overrun = DRV_Reg32(REG_ELM_STAT) & 0x000000FF;\
	} while(0)

// Temporary Dummy API
kal_uint32 emi_get_dram_refresh_rate(void);
void EMI_reg_dump_init(void);

#endif  /* !__EMI_MT6290_H__ */
