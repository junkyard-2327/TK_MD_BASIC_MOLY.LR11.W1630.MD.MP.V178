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
 *   drv_rstctl.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * Barry Hong
 *
 *
 * ==========================================================================
 * $Log$
 *
 * 11 24 2016 yuke.ren
 * [MOLY00214601] [Rosa] Call-for-check-in
 * .
 *
 * 02 19 2016 da.li
 * [MOLY00165553] [OLYMPUS][UMOLY] Code porting for new project
 * Code porting for MT6757
 *
 * 10 14 2015 owen.ho
 * [MOLY00145198] [MT6755][Jade-L1] [MP1][overnight][Others] MD long time no response
 * Trigger SWDT every 5s after EPON
 *
 * 09 02 2015 owen.ho
 * [MOLY00070771] [6291][FPGA]solve build error
 * Move drv_rstctl_disable_all_WDTs out from ATEST_ENABLE flag
 *
 * 08 19 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * Rename a drvtest function: _rst_disable_all_WDT --> drv_rstctl_dsiable_all_WDTs.
 *
 * 08 11 2015 owen.ho
 * [MOLY00070771] [6291][FPGA]solve build error
 * Update RGU IT framework for JADE and EVEREST
 *
 * 07 24 2015 owen.ho
 * [MOLY00070771] [6291][FPGA]solve build error
 * Modify RGU IT framework for reset with delay cycle case
 *
 * 07 24 2015 owen.ho
 * [MOLY00070771] [6291][FPGA]solve build error
 * Fix IT framework for drvtest environment
 *
 * 07 03 2015 owen.ho
 * [MOLY00070771] [6291][FPGA]solve build error Modify RGU drvtest & devdrv for JADE
 *
 * 06 11 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Add compile option flag to restrict WDT enable without __PRODUCTION_RELEASE__ in abnrset api.
 * 	Add BB_Register dump. 
 * 	Add EMMWriteDebugInfo for track caller info in share memory.
 *
 * 04 28 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Add silent reboot in exception flow and trigger fatal error upon receving L1WDT IRQ.
 *
 * 04 27 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Klocwork correction.
 *
 * 04 09 2015 owen.ho
 * [MOLY00070771] [6291][FPGA]solve build error Update RGU IT framework
 * 	.
 *
 * 03 30 2015 owen.ho
 * [MOLY00070771] [6291][FPGA]solve build error:Update RGU IT framework
 *
 * 01 29 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Correct g_ABNORMAL_RST_REG and g_ABNORMAL_RST_VAL.
 *
 * 01 28 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Solve trunk's build error.
 *
 * 01 06 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Chnage L1 boot slave address for L2copro's requirement that needs more memory space (256MB).
 * 	Cooperate with HVT dummy load built by "make mcore_6291_drvtest_nand_booting".
 *
 * 12 26 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Include system_coverage into  ungate_l1core.
 *
 * 12 26 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Disable WDTRR in UMOLY while in DRVTEST mode.
 * 	Add system_coverage in _rst_set_system_ready_sts for different 3G/4G FPGA configuration.
 *
 * 12 22 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Patch drv_rstctl.c for the condition that target system is not included in the system coverage.
 *
 * 12 16 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Provide interface for USB WDT test.
 *
 * 12 15 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Message layout adjustment.
 *
 * 12 15 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Patch incorrect ARM7WDT WDTRR KEY setting.
 *
 * 12 09 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Add ATEST_ENABLE to solve UMOLY build error.
 *
 * 12 09 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Add ATEST_ENABLE to solve UMOLY build error.
 *
 * 12 09 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	RGU IT Framework
 *
 * 10 23 2014 vmick.lin
 * [MOLY00062072] [MT6291][RGU] Implement
 * 	Change IRQ name from MD_IRQID_MD_WDT to IRQ_MD_WDT_CODE
 *
 * 10 22 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * Modification software reset mechanis of RST_NFI and RST_NFI_AO.
 * They need to be reset at the same time.
 *
 * 10 15 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * Add RST_SOE and RST_BUS_RECORD in drv_rstctl_sw_reset.
 *
 * 09 25 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * synchronization of definitions
 *
 * 08 27 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error.
 * drv_rstctl.h  	add reset enumerators for APSYS IPs
 * rstctl_reg.h	1.add definitions of APRGU control registers
 * 	2.add definitions of software reset for APSYS IPs
 * drv_rstctl.c	1. enhance_RESET_ITEM_REGs to support APSYS/MDSYS IPs
 * 	2. enhacne _rst_resetIP to supoort APSYS/MDSYS IPs
 * 	3. enlarge the reset scope of drv_rstctl_sw_reset (including APSYS IPs. )
 *
 * 07 17 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * .Add drv_rstctl_sw_reset function for UMOLY IP functional test.
 *
 * 07 02 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	.
 *
 * 05 27 2014 vmick.lin
 * [MOLY00062072] [TK6291][RGU] Implement
 * 	.
 * 	Disable Arm7/L1core bypass irq configuration while init
 *
 * 05 20 2014 vmick.lin
 * [MOLY00062072] [TK6291][RGU] Implement
 * 	.
 *
 * 05 20 2014 vmick.lin
 * [MOLY00062072] [TK6291][RGU] Implement
 * 	Because WDTIR default is 0x20000, so need to SW workaround
 *
 * 05 20 2014 vmick.lin
 * [MOLY00062072] [TK6291][RGU] Implement
 * 	.
 *
 * 04 14 2014 vmick.lin
 * [MOLY00062072] [TK6291][RGU] Implement
 * 	Resolve build error
 *
 * 04 10 2014 vmick.lin
 * [MOLY00062072] [TK6291][RGU] Implement
 * 	Fix build error
 *
 * 04 08 2014 vmick.lin
 * [MOLY00062072] [TK6291][RGU] Implement: Fix build error temporarily
 *
 * 02 17 2014 vmick.lin
 * [MOLY00056239] [6595] RGU integration test
 * 	Stop call while system calling wdt reset
 *
 * 02 10 2014 vmick.lin
 * [MOLY00055629] [MT6290][CPE_DONGLE_TYPE]CR4 watchdog reset in dormant mode
 * 	clear wdt status while init
 *
 * 01 13 2014 vend_mick.lin
 * [MOLY00051688] [MT6595 Bring-Up] Verify RGU driver
 * 	Add accessing Top RGU retention data API for test
 *
 * 01 13 2014 vend_mick.lin
 * [MOLY00051688] Verify RGU driver in ROME EVB
 * 	Add whole system reset function to PSD1
 *
 * 12 27 2013 vend_mick.lin
 * [MOLY00051688] Verify RGU driver in ROME EVB
 * Change enum type RST_LTEL2 to original RST_L2COP
 *
 * 12 18 2013 vend_mick.lin
 * [MOLY00050015] Add CLDMA sw reset in RGU driver
 * 	Modify get_duration macro
 *
 * 12 12 2013 vend_mick.lin
 * [MOLY00050015] Add CLDMA sw reset in RGU driver
 * 	.
 *
 * 12 06 2013 vend_mick.lin
 * [MOLY00049273] Add MT6595 RGU driver
 * 	[MT6595] RGU code merge
 *
 * 10 30 2013 vend_mick.lin
 * [MOLY00043729] Change watchdog timeout period for product release
 * 	Change Watch dog timer to 4 sec and enable IRQ mode in phone type
 *
 * 10 04 2013 vend_mick.lin
 * [MOLY00040268] SDIO transfer speed is very low after MOLY boot-up about 10 seconds
 * 	ext_rst_b set low active as phone type request
 *
 * 09 25 2013 vend_mick.lin
 * [MOLY00038948] Add infinite loop in sw watch dog reset function if irq_en not set
 *
 * 09 17 2013 vend_mick.lin
 * [MOLY00038329] Ext_rst setting affects SDIO transmission speed
 * 	change ext_rst polarity as high active as workaround solution
 *
 * 08 30 2013 vend_mick.lin
 * [MOLY00035988] Change polarity of ext_rst signal to low active
 * 	For phone type request
 *
 * 08 29 2013 vend_mick.lin
 * [MOLY00035823] Delete warning message while build code of rstctrl part
 * 	Delete waring message
 *
 * 08 15 2013 vend_mick.lin
 * Fix CR: MOLY00033807 ; Dont reset APCLK after WDT
 *
 * 08 02 2013 barry.hong
 * [MOLY00021294] [MT6290 Bring-up]6290 WDT driver update
 * Fraom wei-de phone project request. set EXT_RST default to high active
 *
 * 07 17 2013 barry.hong
 * [MOLY00021294] [MT6290 Bring-up]6290 WDT driver update
 * .remove APCLK reset when USB call WD reset
 *
 * 05 30 2013 barry.hong
 * [MOLY00013643] [MT6290 Bring-up]Modify Sleep mode driver
 * .*: update for USB suspend IT test
 *
 * 05 29 2013 barry.hong
 * [MOLY00021294] [MT6290 Bring-up]6290 WDT driver update
 * .update 6290 WDT driver
 *
 * 05 09 2013 barry.hong
 * [MOLY00021294] [MT6290 Bring-up]6290 WDT driver update
 * .*:
 * 1.Add drv_rstctl_wd_clrCnt API to clear WD CNT
 * 2.Modify drv_rstctl_wd_rst_set_bitmap for U2 suspend wakeup not reset APCLK request
 *
 * 05 02 2013 barry.hong
 * [MOLY00021294] [MT6290 Bring-up]6290 WDT driver update
 * .change g_ABNORMAL_RST_VAL define to WDT_RSTINTERVAL_VALUE
 *
 * 03 08 2013 barry.hong
 * [MOLY00011608] MT6290 MOLY fake API remove
 * .remove fakeAPI
 *
 * 02 04 2013 barry.hong
 * [MOLY00009902] MT7208 rename
 * MT7208 rename to MT6290.
 *
 * 11 20 2012 barry.hong
 * [MOLY00006416] Update Driver for MT6290 FPGA 20121105_MD_a4_b12_cx
 * .merge TATAKA driver to MOLY
 ****************************************************************************/

#include "drv_features_wdt.h"
#include "drv_comm.h"

#include "rstctl_reg.h"
#include "drv_rstctl.h"
#include "intrCtrl.h"

#include "dcl.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ex_item.h"
#include "ex_public.h"  	/*Include this header file for register BBreg dump*/
#include "kal_internal_api.h"

#if defined(ATEST_ENABLE)
#include "drvtest_sm.h"
#endif 
#if !defined(DRV_RSTCTL_OFF)


#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)

#define UT_DELAY_LOOP(n)                                                          \
do{                                                                               \
	volatile register kal_uint32 _delay_loop;                                     \
	for(_delay_loop = 0; _delay_loop < n; _delay_loop++) { ; }                    \
}while(0)
#if defined(TK6291)
#define _RESET_ITEM_REGs(reg, item_r, waitLoopCnt)   do {    \
					if ((reg & 0xffff0000) == BASE_ADDR_APRSTCTL)\
						{\
						 DRV_WriteReg32(reg, (item_r));\
						 DRV_WriteReg32(REG_APRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);\
						 UT_DELAY_LOOP(waitLoopCnt);\
						 DRV_WriteReg32(reg, 0); \
						 DRV_WriteReg32(REG_APRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);\
						}\
					else\
						{\
						 DRV_WriteReg32(reg, (item_r));\
						 DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);\
						 UT_DELAY_LOOP(waitLoopCnt);\
						 DRV_WriteReg32(reg, 0);\
						 DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);\
						}\
					} while(0)
#else
#define _RESET_ITEM_REGs(reg, item_r, waitLoopCnt)   do {    \
						{\
						 DRV_WriteReg32(reg, (item_r));\
						 DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);\
						 UT_DELAY_LOOP(waitLoopCnt);\
						 DRV_WriteReg32(reg, 0);\
						 DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);\
						}\
					} while(0)
#endif

void _rst_clrSwRstStatus(kal_uint32 reg, kal_uint32 statusMaskToClear)
{
	/* If status Mask == 0 -> clear ALL */
	statusMaskToClear = (statusMaskToClear)?statusMaskToClear:0xffffffff;
    DRV_WriteReg32(reg, statusMaskToClear);
}

void _rst_resetIP(kal_uint32 reg, kal_uint32 item_r, kal_uint32 waitLoopCnt)
{
	kal_uint32 rstStatus;
	kal_uint32 timeout_cnt=0;
	kal_uint32 sta_reg=0;

	/* Reset IP */
	_RESET_ITEM_REGs(reg, item_r,waitLoopCnt);

	/* Check the status and clear it */
	switch (reg)
	{
		//MDRGU
		case REG_MDRSTCTL_SRBER_MDPERI:
			sta_reg = (REG_MDRSTCTL_SRSTR_MDPERI);
			break;
		case REG_MDRSTCTL_SRBER_PSMCU:
			sta_reg = (REG_MDRSTCTL_SRSTR_PSMCU);
			break;
		case REG_MDRSTCTL_SRBER_MDINFRA:
			sta_reg = (REG_MDRSTCTL_SRSTR_MDINFRA);
			break;
		case REG_MDRSTCTL_SRBER_LTEL2:
			sta_reg = (REG_MDRSTCTL_SRSTR_LTEL2);
			break;
		case REG_MDRSTCTL_SRBER_HSPAL2:
			sta_reg = (REG_MDRSTCTL_SRSTR_HSPAL2);
			break;
		case REG_MDRSTCTL_SRBER_ARM7:
			sta_reg = (REG_MDRSTCTL_SRSTR_ARM7);
			break;
		#if defined(TK6291)
		//APRGU
		case REG_APRSTCTL_SRBER_APPERI:
			sta_reg = (REG_APRSTCTL_SRSTR_APPERI);
			break;
		case REG_APRSTCTL_SRBER_MEMSYS:
			sta_reg = (REG_APRSTCTL_SRSTR_MEMSYS);
			break;
		case REG_APRSTCTL_SRBER_TOPAO:
			sta_reg = (REG_APRSTCTL_SRSTR_TOPAO);
			break;
		case REG_APRSTCTL_SRBER_SSUSB:
			sta_reg = (REG_APRSTCTL_SRSTR_SSUSB);
			break;
		case REG_APRSTCTL_SRBER_APINFRA:
			sta_reg = (REG_APRSTCTL_SRSTR_APINFRA);
			break;
		case REG_APRSTCTL_SRBER_APMCU:
			sta_reg = (REG_APRSTCTL_SRSTR_APMCU);
			break;
		case REG_APRSTCTL_SRBER_PAR:
			sta_reg = (REG_APRSTCTL_SRSTR_PAR);
			break;
		#endif	
		default:
			ASSERT(0); /*To prevent undefined status register address returned by default case.*/
			break;
	}

	rstStatus = (DRV_Reg32(sta_reg)&item_r);


	while((item_r != rstStatus) && timeout_cnt<10000)
	{
		rstStatus = DRV_Reg32(sta_reg);
		timeout_cnt++;
	};

	ASSERT(timeout_cnt<10000);
	ASSERT(item_r == rstStatus);

	_rst_clrSwRstStatus(sta_reg, item_r);

}



/**
 *	@brief	Procedure for software triggered reset process
 *	This procedure triggers software watchdog reset and wait for its completeness
 *    Note: It needs less than 1T(32k) (eaxtly 1T-2*bus clock period) to do reset after WDTSR changes
 */
static void _rst_swWdReset(void)
{
	/* Always clear indication bits before reset */
	DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|(RSTCTL_WDTSR_STATUS_MASK << RSTCTL_WDTSR_STATUS_OFFSET));

	//set MDTER bit
	DRV_WriteReg32(REG_MDRSTCTL_WDTER_PSMCU, 	0xFFFFFFFF); /*Enable POR for the workaround to reset psmcu when 26M is off*/
	DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 	0xBFFFFFFF);
	DRV_WriteReg32(REG_MDRSTCTL_WDTER_HSPAL2, 	0xBFFFFFFF);
	DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 	0xBFFFFFFF);
	DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDPERI, 	0xBFFEFFFF);
	DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 	0xBFFFFFFF);

	/* Trigger watchdog reset immediately : We use software reset */
	DRV_WriteReg32(REG_MDRSTCTL_SRCMR_SWDT, RSTCTL_SRCMR_KEY_SWDT);
	DRV_Reg32(REG_MDRSTCTL_SRCMR_SWDT);	/* Read the value of RSTCTL_SRCMR back to make sure the previous write operation is done */
	while ((DRV_Reg32(REG_MDRSTCTL_WDTSR) & (RSTCTL_WDTSR_STATUS_MASK<<RSTCTL_WDTSR_STATUS_OFFSET)) == 0);

	/*If irq_en not set, just while(1) to wait reset happen */
	#if defined(ATEST_ENABLE)
	 	dbg_print("[%s]Emulation of WHILE(1) for IRQEN not set.\r\n", __FUNCTION__); 
	#else
	if(!(DRV_Reg32(REG_MDRSTCTL_WDTCR) & RSTCTL_WDTCR_WDT_IRQEN))
	    while(1);
	#endif
}

static void _rst_restartWDT(void)
{
 #if !defined (ATEST_ENABLE)
	/* Simply reload watchdog counter */
	DRV_WriteReg32(REG_MDRSTCTL_WDTRR, RSTCTL_WDTRR_KEY | RSTCTL_WDTRR_WDT_RESTART);
 #endif
}

/*****************************************************************************
 *						 Global/External Variable                            *
 *****************************************************************************/

const kal_uint32 g_WATCHDOG_RESTART_REG   = REG_MDRSTCTL_WDTRR;   							//Externally referenced somewhere
#if defined (ATEST_ENABLE)
const kal_uint32 g_WATCHDOG_RESTART_VALUE = (RSTCTL_WDTRR_WDT_RESTART);  					//Disable Restart function for DRVTEST. 
#else
const kal_uint32 g_WATCHDOG_RESTART_VALUE = (RSTCTL_WDTRR_KEY | RSTCTL_WDTRR_WDT_RESTART);  //Externally referenced somewhere
#endif 
const kal_uint32 g_ABNORMAL_RST_REG       = REG_MDRSTCTL_WDTIR;				
const kal_uint32 g_ABNORMAL_RST_VAL		    = WDT_RSTINTERVAL_VALUE; 		


/*Global vaialbe for BBreg dump*/
#if defined(__MTK_TARGET__)
	EX_BBREG_DUMP Pcore_RGU_dump;
	const kal_uint32 Pcore_RGU_dump_regions[] = {
	BASE_ADDR_MDRSTCTL, 0x0360, 4, 
	}; 
#endif



/*************************************************************************
* FUNCTION
*  pcore_isr_l1wdt_handler
*
* DESCRIPTION
*  This function is used to handle L1WDT. Called by dcl_wdt_hisr
*  
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/



void pcore_isr_l1wdt_handler(void)
{
 /*Suppose that this function should be triggered once and trigger fatal error.*/
 /*After this ISR is triggered, level enable must be turned off.*/
 DRV_WriteReg32(REG_MDRSTCTL_WDTCFG_L1, 0x25550000); //Dsiable level enable 
 #if defined(ATEST_ENABLE)
    dbg_print("[%s] handling l1wdt irq\r\n", __FUNCTION__);
 #endif
 /*check if */
 if (KAL_FALSE == INT_IsAnyCore_Enter_Exception())
 	{


	 if (RSTCTL_WDTSR_L1_HWDT_STS == (RSTCTL_WDTSR_L1_HWDT_STS & DRV_Reg32(REG_MDRSTCTL_WDTSR_L1)))
	 	{
		 #if defined(ATEST_ENABLE)
			dbg_print("[%s] Clear hardware status. \r\n", __FUNCTION__);
		 #endif 
		 
		 //Clear hardware status
		 DRV_WriteReg32(REG_MDRSTCTL_WDTSR_L1, RSTCTL_WDTSR_L1_KEY | RSTCTL_WDTSR_L1_CLR_L1_HWDT_STS); //Clear  HWWDT STS. 
		 //Trigger fatal error when receiving L1WDT IRQ  (HW). 
		 kal_fatal_error_handler(KAL_ERROR_L1CORE_HW_WDT_TIMEOUT_EXCP, 0);
		 #if defined(ATEST_ENABLE)
			dbg_print("[%s] Issuing fatale error. \r\n", __FUNCTION__);
		 	//drv_rstctl_sw_reset(RST_L1SYS); //for drvtest purpose
		 #endif 	
	 	}
	 else if(RSTCTL_WDTSR_L1_SWDT_STS == (RSTCTL_WDTSR_L1_SWDT_STS & DRV_Reg32(REG_MDRSTCTL_WDTSR_L1)))
	 		{
		 	 
			 #if defined(ATEST_ENABLE)
				dbg_print("[%s] Warning: Software WDT is not triggered by the exception flow.  \r\n", __FUNCTION__);
			 #endif 
			 ASSERT(0);
	 		}
		  else
		  	{
			 #if defined(ATEST_ENABLE)
				 dbg_print("[%s] Unexpected status.  \r\n", __FUNCTION__);
			 #endif 
			 ASSERT(0);

		  	}
 	}
 else
 	{
	 if (RSTCTL_WDTSR_L1_HWDT_STS == (RSTCTL_WDTSR_L1_HWDT_STS & DRV_Reg32(REG_MDRSTCTL_WDTSR_L1)))
	 	{
		 #if defined(ATEST_ENABLE)
		   dbg_print("[%s] Triggered by L1 exception handling. ISR does not handle such flow.\r\n", __FUNCTION__);
		   dbg_print("[%s] Check the level enable configuration, because level enable should be turned off in the previous isr handler call.\r\n", __FUNCTION__);
		   dbg_print("[%s] Upon exception happens, L1WDT is triggered by hardware timeout event at that moment.\r\n", __FUNCTION__);
		   dbg_print("[%s] Or exception flow does not turn off level enable.\r\n", __FUNCTION__);
		 #endif	 	
		 ASSERT(0);
	 	}
	 else if(RSTCTL_WDTSR_L1_SWDT_STS == (RSTCTL_WDTSR_L1_SWDT_STS & DRV_Reg32(REG_MDRSTCTL_WDTSR_L1)))
	 		{
			 #if defined(ATEST_ENABLE)
			    dbg_print("[%s] Software WDT triggered by exception. Do nothing.  \r\n", __FUNCTION__);
			 #endif
	 		}
		  else
		  	{
			 
			 #if defined(ATEST_ENABLE)
				 dbg_print("[%s] Unexpected status.  \r\n", __FUNCTION__);
			 #endif 
			 ASSERT(0);
		  	}

 	}
}


/*************************************************************************
* FUNCTION
*  drv_rstctl_init_l1wdt_status
*
* DESCRIPTION
*  Because L1WDT interval is not long enough, some cases might encounter unexpected 
*  L1WDT IRQ ISR after long loding time. To prevent long loading time that triggers unexptected L1WDt IRQ. 
*  We add this function to clear L1WDT STS and clear This function is only used for dcl_wdt_register_lisr. 
*  NOTE:L1_LV_EN is enabled @ drv_rstctl_wdt_init as well. 
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/

void drv_rstctl_init_l1wdt_status(void)
{
 kal_uint32 current_val;

 //Note: remember to disable WDT make sure system under control.
 //Disable level enable 
 current_val = DRV_Reg32(REG_MDRSTCTL_WDTCFG_L1) & ~RSTCTL_WDTCFG_L1_LV_EN;
 DRV_WriteReg32(REG_MDRSTCTL_WDTCFG_L1, RSTCTL_WDTCFG_L1_KEY| current_val);

 //Clear the status caused by L1 RGU
 DRV_WriteReg32(REG_MDRSTCTL_WDTSR_L1, RSTCTL_WDTSR_L1_KEY | RSTCTL_WDTSR_L1_CLR_L1_SWDT_STS| RSTCTL_WDTSR_L1_CLR_L1_HWDT_STS);


 //Enable level enable to handle L1WDT IRQ. 
 current_val = DRV_Reg32(REG_MDRSTCTL_WDTCFG_L1) | RSTCTL_WDTCFG_L1_LV_EN;
 DRV_WriteReg32(REG_MDRSTCTL_WDTCFG_L1, RSTCTL_WDTCFG_L1_KEY| current_val);

}


/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_abnReset
*
* DESCRIPTION
*  This function is used to do abnormal reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_abnReset(void)
{
	#if !defined(ATEST_ENABLE)
	   SaveAndSetIRQMask();
	#endif
	/*10 seconds delay*/
	#define ABSOLUTE_DELAY_PERIOD	(32*1024*10)
	
	drv_rstctl_wdt_setInterval(ABSOLUTE_DELAY_PERIOD);
	_rst_restartWDT();
	  drv_rstctl_wdt_enable(KAL_TRUE);

	/*Wait for SWDT or HWDT status triggered by L1RGU*/
	#if defined(ATEST_ENABLE) /*DRVTEST */
	  while((0 == ((RSTCTL_WDTSR_L1_HWDT_STS | RSTCTL_WDTSR_L1_SWDT_STS) & DRV_Reg32(REG_MDRSTCTL_WDTSR_L1)))
	  	     && RSTCTL_WDTSR_MD_HWDT != (RSTCTL_WDTSR_MD_HWDT& DRV_Reg32(REG_MDRSTCTL_WDTSR))); 
	  if (RSTCTL_WDTSR_MD_HWDT != (RSTCTL_WDTSR_MD_HWDT& DRV_Reg32(REG_MDRSTCTL_WDTSR))) /*L1RGU HWDT or SWDT is triggered*/
	  	{		 
		 drv_rstctl_wdt_enable(KAL_FALSE);	 
		 _rst_swWdReset(); 
	  	}
	  
	#else /*UMOLY exception flow.*/
	  while(0 == ((RSTCTL_WDTSR_L1_HWDT_STS | RSTCTL_WDTSR_L1_SWDT_STS) & DRV_Reg32(REG_MDRSTCTL_WDTSR_L1))); 	  
	  /*Disable MDRGU WDT and trigger SWDT*/
	    drv_rstctl_wdt_enable(KAL_FALSE);   
	    _rst_swWdReset(); 
	#endif
	
	#if defined(ATEST_ENABLE)
	  /*For drvtest, what we verify is  the flow instead of actual while(1)*/
	  dbg_print("[%s] WHILE(1) loop ...\r\n", __FUNCTION__);
	#else
	  while(1);
	#endif
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableInterrupt
*
* DESCRIPTION
*  This function is used to on/off irq mode
*       reset or trigger interrupt while watchdog timout happening
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_enableInterrupt(kal_bool enable)
{
    if (enable == KAL_TRUE)
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR,(RSTCTL_WDTCR_KEY)|((DRV_Reg32(REG_MDRSTCTL_WDTCR)) | RSTCTL_WDTCR_WDT_IRQEN));
	}
	else
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR,(RSTCTL_WDTCR_KEY)|((DRV_Reg32(REG_MDRSTCTL_WDTCR)) & (~RSTCTL_WDTCR_WDT_IRQEN)));
	}
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_getInterval
*
* DESCRIPTION
*  This function is used to get wd timer interval(uint:T(32k))
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
kal_uint32 drv_rstctl_wd_getInterval(void)
{
	return (kal_uint32)(RSTCTL_WDTIR_INTERVAL_MASK & DRV_Reg32(REG_MDRSTCTL_WDTIR));
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*   cntMaskToClear
*   SW_WDCNT_CLR: clear SW WD Cnt
*   HW_WDCNT_CLR: clear HW WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrCnt(kal_uint32 cntMaskToClear)
{
    /*Not support Counter in TK6291*/
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_setInterval
*
* DESCRIPTION
*  This function is used to set wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
void drv_rstctl_wdt_setInterval(kal_uint32 wdtInterval)
{
    /* Set watchdog interval */
	DRV_WriteReg32(REG_MDRSTCTL_WDTIR,
				   ((RSTCTL_WDTIR_KEY)|
				   ((wdtInterval & RSTCTL_WDTIR_INTERVAL_MASK) << RSTCTL_WDTIR_INTERVAL_OFFSET)));
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_kick
*
* DESCRIPTION
*  This function is used to retart wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_restartWDT(void)
{
    _rst_restartWDT();
}



/*************************************************************************
* FUNCTION
*	drv_rstctl_ext_rst_pin_init
*
* DESCRIPTION
*   	This function is to set ext_rst pin status
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*    None
*
* NOTE
*   In TK6291 phone type product, default is output pin and pull low
*   We need to set it as default high and low active
*************************************************************************/ 
void drv_rstctl_ext_rst_pin_init(void)
{
	#if defined(TK6291)
	kal_uint32 regVal;
    //For APRGU
	//Enable EXTRST, and set active low
	regVal = DRV_Reg32(REG_APRSTCTL_EXTRST)| RSTCTL_EXTRST_OE; //Default: RSTCTL EXTRST is disabled.
	DRV_WriteReg32(REG_APRSTCTL_EXTRST,RSTCTL_EXTRST_KEY | (regVal & ~(RSTCTL_EXTRST_POLARITY_HIGH)));
	//Enable MD1 EXTRST
	regVal = DRV_Reg32(REG_APRSTCTL_EXTRST_MD1) | RSTCTL_EXTRST_MD1_WDT_EN; //Default: MD1 WDT IRQ does not trigger EXTRST.
	DRV_WriteReg32(REG_APRSTCTL_EXTRST_MD1, RSTCTL_EXTRST_MD1_KEY | regVal);

	//For MDRGU
	//Enable L1 bypass
	regVal = DRV_Reg32(REG_MDRSTCTL_WDTCR_L1) | RSTCTL_WDTCR_WDT_L1_IRQ_BYPASS;  //Default: L1 IRQ is bypass.
	DRV_WriteReg32(REG_MDRSTCTL_WDTCR_L1, RSTCTL_WDTCR_WDT_L1_KEY | regVal);
	//Enable ARM7 bypass
	regVal = DRV_Reg32(REG_MDRSTCTL_WDTCR_ARM7) | RSTCTL_WDTCR_WDT_ARM7_IRQ_BYPASS;  //Default: ARM7 IRQ  is bypass.
	DRV_WriteReg32(REG_MDRSTCTL_WDTCR_ARM7, RSTCTL_WDTCR_WDT_ARM7_KEY | regVal);
	#endif
}
 

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_init
*
* DESCRIPTION
*  This function is to initialize the WDT module
*
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_init(void)
{
    /*TODO: Read status bit and PC monitor for debug before clear status*/
#if !defined(ATEST_ENABLE)
   {
	DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|(RSTCTL_WDTSR_STATUS_MASK << RSTCTL_WDTSR_STATUS_OFFSET)); //Clear WDTSR all status.
	DRV_WriteReg32(REG_MDRSTCTL_WDTSR_L1, RSTCTL_WDTSR_L1_KEY | RSTCTL_WDTSR_L1_CLR_L1_SWDT_STS | RSTCTL_WDTSR_L1_CLR_L1_HWDT_STS);  //Clear WDTSR_L1 all status.
	DRV_WriteReg32(REG_MDRSTCTL_WDTSR_ARM7, RSTCTL_WDTSR_ARM7_KEY | RSTCTL_WDTSR_ARM7_CLR_ARM7_CNT | RSTCTL_WDTSR_ARM7_CLR_ARM7_STS); //Clear WDTSR_ARM7 counter and status.
   }
#endif
	drv_rstctl_wdt_setInterval(WDT_RSTINTERVAL_VALUE);

#if defined(DRV_WDT_IRQ_MODE)
	drv_rstctl_wdt_enableInterrupt(KAL_TRUE);
	drv_rstctl_ext_rst_pin_init();
	/*TODO register IRQ and handle ISR*/
	//IRQSensitivity(IRQ_MD_WDT_CODE, KAL_TRUE);
	//IRQUnmask(IRQ_MD_WDT_CODE);
#endif

    /*After UMOLY is brought up, IRQ from  L1 and ARM7 are handled by Pcore*/
    DRV_WriteReg32(REG_MDRSTCTL_WDTCR_L1, RSTCTL_WDTCR_WDT_L1_KEY | (DRV_Reg32(REG_MDRSTCTL_WDTCR_L1) & ~(RSTCTL_WDTCR_WDT_L1_IRQ_BYPASS)));
    DRV_WriteReg32(REG_MDRSTCTL_WDTCR_ARM7, RSTCTL_WDTCR_WDT_ARM7_KEY | (DRV_Reg32(REG_MDRSTCTL_WDTCR_ARM7) & ~(RSTCTL_WDTCR_WDT_ARM7_IRQ_BYPASS)));
    DRV_WriteReg32(REG_MDRSTCTL_WDTCFG_L1, RSTCTL_WDTCFG_L1_KEY | RSTCTL_WDTCFG_L1_LV_EN);

}


/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enable
*
* DESCRIPTION
*  This function is used to on/off wd timer
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
void drv_rstctl_wdt_enable(kal_bool en)
{
    if (en == KAL_TRUE)
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))|RSTCTL_WDTCR_WDT_EN));
		/*Reload wdt interval*/
		DRV_WriteReg32(REG_MDRSTCTL_WDTRR, RSTCTL_WDTRR_KEY | RSTCTL_WDTRR_WDT_RESTART);
	}
	else
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))&(~RSTCTL_WDTCR_WDT_EN)));
	}
}

/*************************************************************************
*              Following is used by system init                          *
*************************************************************************/

/*************************************************************************
* FUNCTION
*  WDT_init
*
* DESCRIPTION
*  This function is to initialize the WDT module
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void WDT_init(void)
{
    static DCL_HANDLE wdt_handle;
	drv_rstctl_wdt_init();
	
	wdt_handle = DclWDT_Open(DCL_WDT, 0);
	if(STATUS_OK !=DclWDT_RegisterCallback(wdt_handle,EVENT_WDT_TIMEOUT, NULL))
		{
 		 ASSERT(0);
		}
	if (STATUS_OK != DclWDT_Close(wdt_handle))
		{
		 ASSERT(0);
		}
	/*Begin : Register BB_Reg DUMP*/
	Pcore_RGU_dump.regions = (kal_uint32*)Pcore_RGU_dump_regions; 
	Pcore_RGU_dump.num = sizeof(Pcore_RGU_dump_regions) / (sizeof(kal_uint32) * 3); 
	Pcore_RGU_dump.bbreg_dump_callback = NULL; 
	EX_REGISTER_BBREG_DUMP(&Pcore_RGU_dump);
	/*End : Register BB_Reg DUMP*/
	
}

/*************************************************************************
* FUNCTION
*  Get_WATCHDOG_BASE
*
* DESCRIPTION
*  This function is to get restart wd timer base address
*
* PARAMETERS
*    none
*
* RETURN VALUES
*    wd timer kick base address
*
*************************************************************************/
kal_uint32 Get_WATCHDOG_BASE()
{
	return (REG_MDRSTCTL_WDTRR);
}

/*************************************************************************
* FUNCTION
*  Get_WATCHDOG_RESTART_CMD
*
* DESCRIPTION
*  This function is to get restart wd timer key
*
* PARAMETERS
*    none
*
* RETURN VALUES
*    wd timer kick command key
*
*************************************************************************/
kal_uint32 Get_WATCHDOG_RESTART_CMD()
{
  #if defined (ATEST_ENABLE)
    return (RSTCTL_WDTRR_WDT_RESTART);  //For drvtest, do not return WDTRR Key to prevent the test. 
  #else
	return (RSTCTL_WDTRR_KEY | RSTCTL_WDTRR_WDT_RESTART);
  #endif
}

/*************************************************************************
* FUNCTION
*  Is_WDT_Init
*
* DESCRIPTION
*  Check WD timer is set to system default value already or not
*
* PARAMETERS
*    none
*
* RETURN VALUES
*     TRUE: already set
*    FALSE: not yet
*
*************************************************************************/
kal_bool Is_WDT_Init()// for ex_item.c
{
	if( drv_rstctl_wd_getInterval() == WDT_RSTINTERVAL_VALUE )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}


void drv_rstctl_sw_reset(rst_target_e targetIP)
{
	#if defined(TK6291)
	kal_uint32 timeout_cnt=0;  //for RST_MEMORY only
	kal_uint32 reg_val; 
	#endif
	switch (targetIP)
	{
		/* Only valid for MDARM */
		case RST_MDGDMA:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDGDMA_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_USIM1:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_USIM1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_USIM2:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_USIM2_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDUART0:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDUART0_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDGPTM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDGPTM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDMISC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDMISC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDCIRQ:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDCIRQ_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_I2C:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_I2C_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDDBGSYS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDDBGSYS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		//case RST_DBGCV:
		//	{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_SRBER_DBGCV_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDDBGSIB:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDDBGSIB_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_GPIOMUX:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_GPIOMUX_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDTOPSM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDTOPSM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDOST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDOST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDCFGCTL:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDCFGCTL_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDECT:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDECT_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDECTDBG:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDECTDBG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDCLKBUS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDCLKBUS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDCLK:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_MDCLK_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_TRACE:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_TRACE_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PSLITE_GPT:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_PSLITE_GPT_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7_PCCIF:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_ARM7_PCCIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_L1SYS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDPERI, RSTCTL_MDSRBER_L1SYS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7_HRST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_MDSRBER_ARM7_HRST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7_SRST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_MDSRBER_ARM7_SRST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7_CIRQ:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_MDSRBER_ARM7_CIRQ_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7SYS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_MDSRBER_ARM7SYS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_L2COP:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_LTEL2, RSTCTL_MDSRBER_LTEL2_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_HSPAL2:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_HSPAL2, RSTCTL_MDSRBER_HSPAL2_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDINFRA_BUSMON:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_MDSRBER_MDINFRA_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDINFRA_BOOTROM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_MDSRBER_MDINFRA_BOOTROM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ABM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_MDSRBER_ABM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDUART1:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_MDSRBER_MDUART1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDUART2:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_MDSRBER_MDUART2_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PSPERI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_MDSRBER_PSPERI_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_BUS_RECORD:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_MDSRBER_BUS_RECORD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SOE:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_MDSRBER_SOE_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CR4_DBG:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_PSMCU, RSTCTL_MDSRBER_CR4_DBG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CR4_NRESET:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_PSMCU, RSTCTL_MDSRBER_CR4_NRESET_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CR4_BUSMON:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_PSMCU, RSTCTL_MDSRBER_CR4_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PF:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_PSMCU, RSTCTL_MDSRBER_PF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PCMON_FIFO:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_PSMCU, RSTCTL_MDSRBER_PCMON_FIFO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PCMON_REG:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_PSMCU, RSTCTL_MDSRBER_PCMON_REG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		#if defined(TK6291)
		//1 APSYS IPs
		case RST_APMISC:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APMISC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APGPTM:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APGPTM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APGPIO:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APGPIO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APUART0:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APUART0_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SDCTL:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_SDCTL_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APTOPSM:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APTOPSM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APOST:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APOST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APDBGSYS:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APDBGSYS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APDBGCV:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APDBGCV_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_NLI_ARB:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_NLI_ARB_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APCFGCTL:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APCFGCTL_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_NFI_AO:  //According to YaoHua's suggestion, RST_NFI and RST_NFI_AO must be reset simultaneously..
				{
				 DRV_WriteReg32(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_NFI_RST);
				 DRV_WriteReg32(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_NFI_AO_RST);
				 DRV_WriteReg32(REG_APRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);
				 UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE);
				 DRV_WriteReg32(REG_APRSTCTL_SRBER_APINFRA, 0);
				 DRV_WriteReg32(REG_APRSTCTL_SRBER_APPERI, 0);
				 DRV_WriteReg32(REG_APRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);

				 while(((RSTCTL_APSRBER_NFI_RST != DRV_Reg32(REG_APRSTCTL_SRSTR_APINFRA))||\
					  (RSTCTL_APSRBER_NFI_AO_RST != DRV_Reg32(REG_APRSTCTL_SRSTR_APPERI))) && timeout_cnt<10000)
					{
					 timeout_cnt++;
					};

				ASSERT((RSTCTL_APSRBER_NFI_RST == DRV_Reg32(REG_APRSTCTL_SRSTR_APINFRA))&&\
					(RSTCTL_APSRBER_NFI_AO_RST == DRV_Reg32(REG_APRSTCTL_SRSTR_APPERI)));

				_rst_clrSwRstStatus(REG_APRSTCTL_SRSTR_APINFRA, RSTCTL_APSRBER_NFI_RST);
				_rst_clrSwRstStatus(REG_APRSTCTL_SRSTR_APPERI, RSTCTL_APSRBER_NFI_AO_RST);
				break;}
		case RST_APECT:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APECT_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APECTDBG:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APECTDBG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CLDMA_AO:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_CLDMA_AO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SEJ:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_SEJ_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APLED:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_APLED_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PMIC:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_PMIC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PMICBUS:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_PMICBUS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PTPOD:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_PTPOD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PTPODBUS:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_PTPODBUS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SDCTL_CISCC:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_SDCTL_CISCC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_EFUSE:
			{_rst_resetIP(REG_APRSTCTL_SRBER_TOPAO, RSTCTL_APSRBER_EFUSE_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SSUSB_DIGPHY:
			{_rst_resetIP(REG_APRSTCTL_SRBER_TOPAO, RSTCTL_APSRBER_SSUSB_DIGPHY_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SSUSB_PHY:
			{_rst_resetIP(REG_APRSTCTL_SRBER_TOPAO, RSTCTL_APSRBER_SSUSB_PHY_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APCLKBUS:
			{_rst_resetIP(REG_APRSTCTL_SRBER_TOPAO, RSTCTL_APSRBER_APCLKBUS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APCLK:
			{_rst_resetIP(REG_APRSTCTL_SRBER_TOPAO, RSTCTL_APSRBER_APCLK_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_AUXADC:
			{_rst_resetIP(REG_APRSTCTL_SRBER_TOPAO, RSTCTL_APSRBER_AUXADC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DRAMC_AO:
			{_rst_resetIP(REG_APRSTCTL_SRBER_TOPAO, RSTCTL_APSRBER_DRAMC_AO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_EMI_AO:
			{_rst_resetIP(REG_APRSTCTL_SRBER_TOPAO, RSTCTL_APSRBER_EMI_AO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MEMMISC_AO:
			{_rst_resetIP(REG_APRSTCTL_SRBER_TOPAO, RSTCTL_APSRBER_MEMMISC_AO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DRAMC:
			{_rst_resetIP(REG_APRSTCTL_SRBER_MEMSYS, RSTCTL_APSRBER_DRAMC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_EMI:
			{_rst_resetIP(REG_APRSTCTL_SRBER_MEMSYS, RSTCTL_APSRBER_EMI_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DDRPHY:
			{_rst_resetIP(REG_APRSTCTL_SRBER_MEMSYS, RSTCTL_APSRBER_DDRPHY_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SRAMROM:
			{_rst_resetIP(REG_APRSTCTL_SRBER_MEMSYS, RSTCTL_APSRBER_SRAMROM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DDRBRIDGE:
			{_rst_resetIP(REG_APRSTCTL_SRBER_MEMSYS, RSTCTL_APSRBER_DDRBRIDGE_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_TRFGEN:
			{_rst_resetIP(REG_APRSTCTL_SRBER_MEMSYS, RSTCTL_APSRBER_TRFGEN_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SSUSB:
			{_rst_resetIP(REG_APRSTCTL_SRBER_SSUSB, RSTCTL_APSRBER_SSUSB_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_NFI: //According to YaoHua's suggestion, RST_NFI and RST_NFI_AO must be reset simultaneously.
				{
				 DRV_WriteReg32(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_NFI_RST);
				 DRV_WriteReg32(REG_APRSTCTL_SRBER_APPERI, RSTCTL_APSRBER_NFI_AO_RST);
				 DRV_WriteReg32(REG_APRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);
				 UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE);
				 DRV_WriteReg32(REG_APRSTCTL_SRBER_APINFRA, 0);
				 DRV_WriteReg32(REG_APRSTCTL_SRBER_APPERI, 0);
				 DRV_WriteReg32(REG_APRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);

				 while(((RSTCTL_APSRBER_NFI_RST != DRV_Reg32(REG_APRSTCTL_SRSTR_APINFRA))||\
					  (RSTCTL_APSRBER_NFI_AO_RST != DRV_Reg32(REG_APRSTCTL_SRSTR_APPERI))) && timeout_cnt<10000)
					{
					 timeout_cnt++;
					};

				ASSERT((RSTCTL_APSRBER_NFI_RST == DRV_Reg32(REG_APRSTCTL_SRSTR_APINFRA))&&\
					(RSTCTL_APSRBER_NFI_AO_RST == DRV_Reg32(REG_APRSTCTL_SRSTR_APPERI)));

				_rst_clrSwRstStatus(REG_APRSTCTL_SRSTR_APINFRA, RSTCTL_APSRBER_NFI_RST);
				_rst_clrSwRstStatus(REG_APRSTCTL_SRSTR_APPERI, RSTCTL_APSRBER_NFI_AO_RST);
				break;}

		case RST_SPI:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_SPI_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_USB:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_USB_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_HIF0:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_HIF0_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PFC:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_PFC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MSDC0P:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_MSDC0P_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APGDMA:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_APGDMA_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APINFRA_BUSMON:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_APINFRA_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APUART1:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_APUART1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APUART2:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_APUART2_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PCCIF0:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_PCCIF0_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PCCIF1:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_PCCIF1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PCCIF2:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_PCCIF2_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PCCIF3:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_PCCIF3_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CLDMA:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_CLDMA_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_RTC:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_RTC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MSDC1P:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_MSDC1P_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MSDC_C2K:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_MSDC_C2K_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_TRNG:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_TRNG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_L12PS_RCCIF:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_L12PS_RCCIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PS2L1_RCCIF:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_PS2L1_RCCIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_L12MD2_RCCIF:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_L12MD2_RCCIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_L12MD3_RCCIF:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_L12MD3_RCCIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MD22L1_RCCIF:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_MD22L1_RCCIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MD32L1_RCCIF:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APINFRA, RSTCTL_APSRBER_MD32L1_RCCIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CA7_DBG:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APMCU, RSTCTL_APSRBER_CA7_DBG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CA7_NRESET:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APMCU, RSTCTL_APSRBER_CA7_NRESET_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CA7_BUSMON:
			{_rst_resetIP(REG_APRSTCTL_SRBER_APMCU, RSTCTL_APSRBER_CA7_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MD1:
			{_rst_resetIP(REG_APRSTCTL_SRBER_PAR, RSTCTL_APSRBER_MD1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_AP_MD1:
			{	
				/*Define the BASE_ADDR_MEMSYSAOREG_MISC for Qmei's branch*/
				#define BASE_ADDR_MEMSYSAOREG_MISC (0x93080000)
				DRV_WriteReg32_NPW(BASE_ADDR_MEMSYSAOREG_MISC+0x3000, 0x24541689); //Unlock MEMSYS password
				reg_val = DRV_Reg32(0xC304200C) | (1 << 21);
				DRV_WriteReg32_NPW(0xC304200C,reg_val);
				_rst_resetIP(REG_APRSTCTL_SRBER_PAR, RSTCTL_APSRBER_AP_MD1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);
				UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE);
				reg_val = DRV_Reg32(0xC304200C) & (~(1 << 21));
				DRV_WriteReg32_NPW(0xC304200C,reg_val);
				DRV_WriteReg32_NPW(BASE_ADDR_MEMSYSAOREG_MISC+0x3000, 0); //Lock MEMSYS password
				break;}
		case RST_MD2:
			{_rst_resetIP(REG_APRSTCTL_SRBER_PAR, RSTCTL_APSRBER_MD2_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_AP_MD2:
			{_rst_resetIP(REG_APRSTCTL_SRBER_PAR, RSTCTL_APSRBER_AP_MD2_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_C2K:
			{_rst_resetIP(REG_APRSTCTL_SRBER_PAR, RSTCTL_APSRBER_C2K_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_AP_C2K:
			{_rst_resetIP(REG_APRSTCTL_SRBER_PAR, RSTCTL_APSRBER_AP_C2K_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_C2K_ARM:
			{_rst_resetIP(REG_APRSTCTL_SRBER_PAR, RSTCTL_APSRBER_C2K_ARM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}


		case RST_MEMSYS: //Note: MEMSYS reset includes DRAMC + EMI+DDRPHY + DRAMC_AO + EMI_AO only. (MEMSYS BUS, which is used for HVT workarond, is not included)
			{
			DRV_WriteReg32(REG_APRSTCTL_SRBER_MEMSYS, (RSTCTL_APSRBER_DRAMC_RST|RSTCTL_APSRBER_EMI_RST|RSTCTL_APSRBER_DDRPHY_RST));
			DRV_WriteReg32(REG_APRSTCTL_SRBER_TOPAO, (RSTCTL_APSRBER_DRAMC_AO_RST|RSTCTL_APSRBER_EMI_AO_RST));
			DRV_WriteReg32(REG_APRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);
			UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE);
			DRV_WriteReg32(REG_APRSTCTL_SRBER_MEMSYS, 0);
			DRV_WriteReg32(REG_APRSTCTL_SRBER_TOPAO, 0);
			DRV_WriteReg32(REG_APRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);

			while((((RSTCTL_APSRBER_DRAMC_RST|RSTCTL_APSRBER_EMI_RST|RSTCTL_APSRBER_DDRPHY_RST) != DRV_Reg32(REG_APRSTCTL_SRSTR_MEMSYS))||\
			        ((RSTCTL_APSRBER_DRAMC_AO_RST|RSTCTL_APSRBER_EMI_AO_RST) != DRV_Reg32(REG_APRSTCTL_SRSTR_TOPAO))) && timeout_cnt<10000)
			{
				timeout_cnt++;
			};

			ASSERT(((RSTCTL_APSRBER_DRAMC_RST|RSTCTL_APSRBER_EMI_RST|RSTCTL_APSRBER_DDRPHY_RST) == DRV_Reg32(REG_APRSTCTL_SRSTR_MEMSYS))&&\
			        ((RSTCTL_APSRBER_DRAMC_AO_RST|RSTCTL_APSRBER_EMI_AO_RST) == DRV_Reg32(REG_APRSTCTL_SRSTR_TOPAO)));

			_rst_clrSwRstStatus(REG_APRSTCTL_SRSTR_MEMSYS, (RSTCTL_APSRBER_DRAMC_RST|RSTCTL_APSRBER_EMI_RST|RSTCTL_APSRBER_DDRPHY_RST));
			_rst_clrSwRstStatus(REG_APRSTCTL_SRSTR_TOPAO, (RSTCTL_APSRBER_DRAMC_AO_RST|RSTCTL_APSRBER_EMI_AO_RST));
			break;}
		#endif

		default:
			ASSERT(0);
	}
}

//Begin: Dennis adds the missing pieces which was removed to pass build error. 10012014.


void _rst_clrWdStatus(kal_uint32 statusMaskToClear)
{
	/* If status Mask == 0 -> clear ALL */
	statusMaskToClear = (statusMaskToClear)?statusMaskToClear:0xffffffff;
    DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|(statusMaskToClear & (RSTCTL_WDTSR_STATUS_MASK<<RSTCTL_WDTSR_STATUS_OFFSET)));
}

void _rst_setWdTarget(kal_uint32 targetMask)
{
//	switch (targetMask)
//	{
//		case RST_SDCTL:
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, DRV_Reg32(REG_MDRSTCTL_WDTER_MDON)|(1<<0));
//			break;
//		default:
//			break:
//	}
}


void _rst_enableWdt(kal_uint32 wdtEnable, kal_uint32 wdtInterval)
{
	if (wdtEnable)
    {
	    /* Set watchdog interval */
		DRV_WriteReg32(REG_MDRSTCTL_WDTIR,
		               ((RSTCTL_WDTIR_KEY)|
		               ((wdtInterval & RSTCTL_WDTIR_INTERVAL_MASK) << RSTCTL_WDTIR_INTERVAL_OFFSET)));

        /* Enable/disable watchdog */
        DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))|RSTCTL_WDTCR_WDT_EN));
	    DRV_WriteReg32(REG_MDRSTCTL_WDTRR,((RSTCTL_WDTRR_KEY)|0x1));

	} else
    {   /* Just simply set WDTCR for WDT disabling operation */
        DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))&(~RSTCTL_WDTCR_WDT_EN)));
    }
}






void drv_rstctl_wd_reset(wdt_irq_e irq_en, rst_target_e wdTarget, kal_uint32 wdtInterval)
{

	/* Disable WD and clear indicators*/
	_rst_clrWdStatus(0);
    DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|0x1F);

	/**< Step 2 : configure WDT register to start counting */
	if (wdTarget == RST_MDALL)
	{
		//set MDTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_PSMCU, 0x800001FF);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x80000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_HSPAL2, 0x80000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x8000007F);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDPERI, 0x81FEFFFF);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x8000000B);
	}
	else
	{
		_rst_setWdTarget(wdTarget);
	}

    if (irq_en == WDT_IRQ_ONLY)
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY)|(0x8));
	else
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY)|(DRV_Reg32(REG_MDRSTCTL_WDTCR)&0x8001));

	if (0 != wdtInterval)
	{
		_rst_enableWdt(1, wdtInterval); /* Maximum interval to watchdog timeout */
		//_rst_restartWDT();	/* Kick watchdog to prevent from timeout */ //already done in _rst_enableWdt
	}
	else
	{
		_rst_swWdReset();	/* To trigger software watchdog reset */
	}

	/* Disable WD and clear indicators*/
	//_wdt_reinitWDT();
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_extrst_setCfg
*
* DESCRIPTION
*  This function is used to config EXT_RST
*
* PARAMETERS
*	rstctl_ext_cfg_t ext_cfg
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_extrst_setCfg(rstctl_ext_cfg_t ext_cfg)
{
/*	//Question: since this part has been moved to APRGU. Therefore, the function is no longer required.
	DRV_WriteReg32(REG_APRSTCTL_EXTRST_MD1, (DRV_Reg32(REG_APRSTCTL_EXTRST_MD1)| RSTCTL_EXTRST_MD1_KEY| (ext_cfg.EXT_RST_EA <<15));  //enable/disable EXT_RST
	DRV_WriteReg32(REG_APRSTCTL_EXTRST_MD1, (DRV_Reg32(REG_APRSTCTL_EXTRST_MD1)| RSTCTL_EXTRST_MD1_KEY| RSTCTL_EXTRST_CLR_EXT_MD1_WDT);  //clear status
	DRV_WriteReg32(REG_APRSTCTL_EXTRST, ((DRV_Reg32(REG_APRSTCTL_EXTRST) & 0xFFFFFFFC)|RSTCTL_EXTRST_KEY|(ext_cfg.MD_POL << 0)|(ext_cfg.PAD_OUT_EA << 1)));	//set Polarity and OE
*/
}



/*************************************************************************
* FUNCTION
*  drv_rstctl_extrst_getSta
*
* DESCRIPTION
*  This function is used to get EXT_RST status
*
* PARAMETERS
*	none
*	 
* RETURN VALUES
*	KAL_TRUE: MD1_WDT_STS is set
*     KAL_FALSE: MD1_WDT_STS is not set or without APRGU in smartphone family (such as JADE)
*************************************************************************/
kal_bool drv_rstctl_extrst_getSta(void)
{
	#if defined(TK6291)
	if (DRV_Reg32(REG_APRSTCTL_EXTRST_MD1) & RSTCTL_EXTRST_MD1_WDT_STS)
	{
		DRV_WriteReg32(REG_APRSTCTL_EXTRST_MD1, (DRV_Reg32(REG_APRSTCTL_EXTRST_MD1)|RSTCTL_EXTRST_MD1_KEY | RSTCTL_EXTRST_CLR_EXT_MD1_WDT));		//clear status
		return KAL_TRUE;
	}
	else
	{
		DRV_WriteReg32(REG_APRSTCTL_EXTRST_MD1, (DRV_Reg32(REG_APRSTCTL_EXTRST_MD1)|RSTCTL_EXTRST_MD1_KEY | RSTCTL_EXTRST_CLR_EXT_MD1_WDT));		//clear status
		return KAL_FALSE;
	}
	#else
		return KAL_FALSE;
	#endif
}

/**
*	@brief	Reset WDT related setting and variables
*/
static void _wdt_reinitWDT(void)
{
	_rst_enableWdt(0,	RSTCTL_WDTIR_INTERVAL_MASK); /* Disable WDT */	/* Let duration being maximum */

	_rst_clrWdStatus(0);				/* Clear ALL indication bits */
}


void drv_rstctl_sw_wd_reset(kal_uint32 wdTarget)
{
	/* Disable WD and clear indicators*/
	_wdt_reinitWDT();

	/**< Step 2 : configure WDT register to start counting */
	_rst_setWdTarget(wdTarget);
	_rst_enableWdt(1, WDT_RSTINTERVAL_VALUE); /* Maximum interval to watchdog timeout */
	_rst_restartWDT();	/* Kick watchdog to prevent from timeout */
	_rst_swWdReset();	/* To trigger software watchdog reset */

	/* Disable WD and clear indicators*/
	_wdt_reinitWDT();
}



/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to clear wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrSta(void)
{
	_rst_clrWdStatus(0);
}



/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_getSta
*
* DESCRIPTION
*  This function is used to get wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*  bit[2]:MD OST timer timout is triggered
*  bit[1]:MD sw WD reset indicator
*  bit[0]:MD hw WD reset indicator
*************************************************************************/
kal_uint32 drv_rstctl_wd_getSta(void)
{
	kal_uint32 wdt_sta;
	wdt_sta = DRV_Reg32(REG_MDRSTCTL_WDTSR);
	//_rst_clrWdStatus(0);
	return wdt_sta;
}


void drv_rstctl_wd_disable(void)
{
	_rst_enableWdt(0,	RSTCTL_WDTIR_INTERVAL_MASK);
}




void drv_rstctl_wd_rst_set_bitmap(kal_uint8 type)
{
	//if (cp15_get_cpu_id() == CPU_CORTEX_R4_ID)
	//originally difference
	// type == 0
	// do not reset ssusb
	// type == 1
	// do not reset usb
	// But for TK6291, all these bit are out of Pcore control.
	// Therefore, there is no difference for these two types.

	if ((type == 0)|| (type == 1))
	{
		//set MDTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_PSMCU,   0x800001FF);		//before 0816 0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2,   0x80000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_HSPAL2,  0x80000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x8000007F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDPERI,  0x81FEFFFF);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7,    0x8000000B);

	}
	else
	{
    }
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableDebugMode
*
* DESCRIPTION
*  This function is used to on/off debug mode
*
* PARAMETERS
*   enable
*   0: disable
*   1: enable
*
* RETURN VALUES
*	none
*************************************************************************/

void drv_rstctl_wdt_enableDebugMode(kal_bool enable)
{
	if (enable==KAL_TRUE)
	{
		IRQUnmask(IRQ_MD_WDT_CODE);
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) | ((DRV_Reg32(REG_MDRSTCTL_WDTCR))| (RSTCTL_WDTCR_WDT_EN | RSTCTL_WDTCR_WDT_IRQEN)));
	}
	else
	{
		IRQMask(IRQ_MD_WDT_CODE);
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) | ((DRV_Reg32(REG_MDRSTCTL_WDTCR)) & ~(RSTCTL_WDTCR_WDT_EN | RSTCTL_WDTCR_WDT_IRQEN)));
	}
}
/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_reset
*
* DESCRIPTION
*  This function is to do wdt reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/

void drv_rstctl_wdt_reset(void)
{
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
	kal_uint16 powerkey_status;

	#if defined(__USB_ENABLE__)

	DCL_BOOL dcl_data = DCL_TRUE;
	DCL_HANDLE	usb_dcl_handle;

	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);

	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_PDN_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_DRV_Close(usb_dcl_handle);

	//	 USB_PDNmode(KAl_TRUE);

	#endif //#if defined(__USB_ENABLE__)

	#ifdef PMIC_PRESENT

	if (BMT.PWRon != CHRPWRON)
	{
		switch(Pwrkey_Position)
		{
			case low_key:
				powerkey_status= DRV_Reg32(KP_LOW_KEY);
				break;
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
			case high_key:
				powerkey_status= DRV_Reg32(KP_HI_KEY);
				break;
			default:
				ASSERT(0);
				break;
		}
		if(WdtPowerKey_Pressed())
		{
			TargetReset = 1;
		}
		else
		{
			/*lint -e(534)*/SaveAndSetIRQMask();

			drv_rstctl_wdt_setInterval(1);
			_rst_restartWDT();
			drv_rstctl_wdt_enable(KAL_TRUE);
			while(1);
		}
	}
	else
	{
		/*lint -e(534)*/SaveAndSetIRQMask();

		drv_rstctl_wdt_setInterval(1);
		_rst_restartWDT();
		drv_rstctl_wdt_enable(KAL_TRUE);
		while(1);
	}
	#else /*PMIC_PRESENT*/
		  /*lint -e(534)*/SaveAndSetIRQMask();

		drv_rstctl_wdt_setInterval(1);
		_rst_restartWDT();
		drv_rstctl_wdt_enable(KAL_TRUE);
		while(1);
	#endif   /*PMIC_PRESENT*/
#else /*!DRV_WDT_RESET_PKEY_RELEASE*/

	kal_uint16 index;
	kal_uint32 FRC_start;
#if defined(DRV_RTC_REG_COMM)
	DCL_HANDLE rtc_handler;
	RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data8;
#endif /*DRV_RTC_REG_COMM*/
	/*lint -e(534)*/SaveAndSetIRQMask();

	for(index=0;index<1000;index++);
#if defined(DRV_RTC_REG_COMM)
	//RTC_Set_PDN_bits(rtc_pdn2 ,DRV_COMM_REG2_NORMAL_RESET);
	rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
	rtc_cmd_data8.PDNIndex = DCL_RTC_PDN2;
	rtc_cmd_data8.fgConfigBit = DRV_COMM_REG2_NORMAL_RESET;
	DclRTC_Control(rtc_handler, RTC_CMD_SET_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data8); // New API with CMD & DATA
#endif   /*DRV_RTC_REG_COMM*/
	#if !defined(DRV_WDT_SWRST)
	drv_rstctl_wdt_setInterval(1);
	_rst_restartWDT();
	drv_rstctl_wdt_enable(KAL_TRUE);
	while(1);
	#else
		#if defined(DRV_MISC_WDT_TURN_OFF_PLL)
	DRV_WriteReg32(0x80000108, 0);
		#endif // #if defined(DRV_MISC_WDT_TURN_OFF_PLL)
	FRC_start = DRV_Reg32(0xf00d0088);
	_rst_swWdReset();	/* To trigger software watchdog reset */
	//workaround for missing WDT IRQ after EPON
	while(1)
	{
		if((DRV_Reg32(0xf00d0088) - FRC_start) > 5000000)
		{
			FRC_start = DRV_Reg32(0xf00d0088);
			_rst_swWdReset();
		}
	}
	#endif
#endif   /*!DRV_WDT_RESET_PKEY_RELEASE*/

}


/*
* FUNCTION
*	drv_rstctl_WdtConfig
*
* DESCRIPTION
*   	This function is to configure WDT only called in drv_rstctl_wdt_init
*
* CALLS
*
* PARAMETERS
*	extpol: KAL_TRUE, polarity = 1
*	        FASLE, polarity = 0
*	exten: KAL_TRUE, generate an external watchdog reset signal when couter=0
*	    KAL_FALSE, not generate an external watchdog reset signal when couter=0
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void drv_rstctl_WdtConfig(IO_level extpol, kal_bool exten)
{
    //	kal_uint32 tmp = DRV_Reg32(REG_MDRSTCTL_WDTCR);
    //	tmp |= (RSTCTL_WDTCR_KEY);
    //	tmp &= ~RSTCTL_WDTCR_WDT_EN;
    //	DRV_WriteReg32(REG_MDRSTCTL_WDTCR, tmp);

    /*
        MD WDTER APON[10] is the mux to choose this ext_rst pin controlled by AP setting (0) or MD setting (1)
        And It also controll the reset signal generating or not
      */
#if defined(TK6291)
    if (exten == KAL_TRUE)
    {
        DRV_WriteReg32(REG_APRSTCTL_EXTRST, RSTCTL_EXTRST_KEY| RSTCTL_EXTRST_OE|(extpol ? RSTCTL_EXTRST_POLARITY_HIGH: RSTCTL_EXTRST_POLARITY_LOW));
        DRV_WriteReg32(REG_APRSTCTL_EXTRST_MD1, RSTCTL_EXTRST_MD1_KEY | RSTCTL_EXTRST_CLR_EXT_MD1_WDT | RSTCTL_EXTRST_MD1_WDT_EN);
    }
    else
    {
        DRV_WriteReg32(REG_APRSTCTL_EXTRST, RSTCTL_EXTRST_KEY);
        DRV_WriteReg32(REG_APRSTCTL_EXTRST_MD1, RSTCTL_EXTRST_MD1_KEY | RSTCTL_EXTRST_CLR_EXT_MD1_WDT);
    }
#endif
}

//Begin: Dennis adds A7 unlock function.


/*************************************************************************
* FUNCTION
*  drv_rstctl_A7_unlock
*
* DESCRIPTION
*  This function is used to unlock ARM7 hrst
*
* PARAMETERS
*	lock:   RST_A7_LOCK:
*            RST_A7_UNLOCK:
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_A7_unlock(rst_a7_lock_e lock)
{
 kal_uint32 regVal;
 kal_uint32 timeout_cnt = 0;
if(lock == RST_A7_UNLOCK)
	{
	 //Set ARM7 reset unlock command.
	 DRV_WriteReg32(REG_MDRSTCTL_RESET_UNLOCK, RSTCTL_ARM7_RESET_UNLOCK_CMD);

	 //Check ARM7 reset unlock status
	 regVal = DRV_Reg32(REG_MDRSTCTL_RESET_UNLOCK) & RSTCTL_ARM7_RESET_UNLOCK_STS;
	 	while((RSTCTL_ARM7_RESET_UNLOCK_STS != regVal) && timeout_cnt<10000)
			{
			regVal = DRV_Reg32(REG_MDRSTCTL_RESET_UNLOCK);
			timeout_cnt++;
			}
		#if defined(ATEST_ENABLE)
		if(timeout_cnt==10000)
			dbg_print("DRV_RSTCTL: Fail to unlock ARM7 reset\r\n");
		#endif
		ASSERT(RSTCTL_ARM7_RESET_UNLOCK_STS == regVal);

	}
else
	{
	#if defined(ATEST_ENABLE)
	 dbg_print("DRV_RSTCTL: 6291 does not support RST_A7_LOCK (line %d in %s)\r\n", __LINE__, __FUNCTION__);
	#endif
	 ASSERT(0);
	}
}

kal_bool _rst_disable_WDT(kal_uint32 reg_addr, kal_uint32 enable_key, kal_uint32 enable_value)
{
 kal_uint32 current_val;
 kal_uint32 timeout_count = 0;
 //Disable WDT
 current_val = DRV_Reg32(reg_addr);
 current_val &= ~enable_value;
 DRV_WriteReg32(reg_addr, enable_key | current_val);

 //Readout the value within  10000 loops
 current_val = DRV_Reg32(reg_addr);
 while ((0 != (current_val & enable_value)) &&(timeout_count < 10000) )
 	{
	 current_val = DRV_Reg32(reg_addr);
	 timeout_count ++;
 	}
 if (timeout_count == 10000)
 	{
	 #if defined(ATEST_ENABLE)
 	 dbg_print("ASSERT (RGU): <line: %d in function:  %s>\r\n", __LINE__, __FUNCTION__);	 	//This case should not happen.
	 #endif
 	 return KAL_FALSE;
 	}
 else
 	return KAL_TRUE;
}


kal_bool drv_rstctl_disable_all_WDTs(void)
{
 #if defined(TK6291)
 //Disable APRGU
 if (KAL_FALSE == _rst_disable_WDT(REG_APRSTCTL_WDTCR, RSTCTL_WDTCR_KEY, RSTCTL_WDTCR_WDT_EN))
 	return KAL_FALSE;
 #endif
 //Disable MDRGU
 if (KAL_FALSE == _rst_disable_WDT(REG_MDRSTCTL_WDTCR, RSTCTL_WDTCR_KEY, RSTCTL_WDTCR_WDT_EN))
 	return KAL_FALSE;
 //Disable L1RGU

 if (KAL_FALSE == _rst_disable_WDT(REG_L1RSTCTL_WDT_MODE, RSTCTL_L1WDT_MODE_KEY, RSTCTL_L1WDT_MODE_WDTEN))
	 return KAL_FALSE;
 //Disable ARM7RGU
 if (KAL_FALSE == _rst_disable_WDT(REG_ARM7RSTCTL_WDTCR, RSTCTL_WDTCR_KEY, RSTCTL_WDTCR_WDT_EN))
	return KAL_FALSE;

 return KAL_TRUE;
}




//End : Dennis adds the missing pieces which was removed to pass build error. 10012014.

#if defined(ATEST_ENABLE)



/************************************************************************************
The following section is the code moved from HVT to UMOLY driver. 
For UMOLY consideration, we only needs to move the PCORE part. 

************************************************************************************/

#if defined(TK6291)
typedef enum
{
 SOFTWARE_RESET = 0,		//Software reset target IP
 WHOLE_SYSTEM_RESET, 		//Trigger source: APRGU
 AUTO_RESET, 				//Trigger source: MDRGU
 //MD_RESET,					//Trigger source: MDRGU  	//After discussing with Mick, this case seems not necessary.
 AP_SOFTWARE_RESET_MD, 		//Trigger source: MDRGU
 PSCORE_RESET_ARM7,			//Trigger source: ARM7 RGU
 PSCORE_RESET_L1, 			//Trigger source: L1 RGU
 RGU_RESET_SCOPE_END		//The last used to distinguish the end of framewor.
}RGU_reset_scope_e;
#else
typedef enum
{
 SOFTWARE_RESET = 0,		//Software reset target IP
 WHOLE_SYSTEM_RESET, 		//Trigger source: APRGU
 //MD_RESET,					//Trigger source: MDRGU  	//After discussing with Mick, this case seems not necessary.
 AP_SOFTWARE_RESET_MD, 		//Trigger source: MDRGU
 PSCORE_RESET_ARM7,			//Trigger source: ARM7 RGU
 PSCORE_RESET_L1, 			//Trigger source: L1 RGU
 RGU_RESET_SCOPE_END		//The last used to distinguish the end of framewor.
}RGU_reset_scope_e;
#endif

#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
#define RGU_RESET_SCOPE_OFFSET 		(29)
#define RGU_RESET_SCOPE_MASK		(0xe0000000)
#define RGU_RESET_UT_RESULT_OFFSET		(28)			//UT result is used to determine if next iteration should proceed.
#define RGU_RESET_UT_RESULT_MASK	(0x10000000)
#define RGU_FRMWRK_PARAMETER_OFFSET 	(25)				//Parameter let the counter-part know what the triger source is.
#define RGU_FRMWRK_PARAMETER_MASK 	(0x0e000000)		//It could be WHOLE_SYSTEM_RESET, AUTO_RESET,  AP_SOFTWARE_RESET_MD,
														//PSCORE_RESET_ARM7, or PSCORE_RESET_L1.
#define RGU_SCOPE_TO_CLEAR_STATE_OFFSET		(22)
#define RGU_SCOPE_TO_CLEAR_STATE_MASK		(0x01c00000)	//For IPs that could not software reset during testing, reset the system to clear corresponding state.
															//This is treated as a flag to distinguish clear state reset or normal reset for UT.
#define RGU_API_CALL_ACCUMULATOR_OFFSET		(0)
#define RGU_API_CALL_ACCUMULATOR_MASK		(0x003fffff)

#else
#define RGU_RESET_SCOPE_OFFSET 		(28)
#define RGU_RESET_SCOPE_MASK		(0xf0000000)
#define RGU_RESET_UT_RESULT_OFFSET		(16)			//UT result is used to determine if next iteration should proceed.
#define RGU_RESET_UT_RESULT_MASK	(0x000f0000)
#define RGU_FRMWRK_PARAMETER_OFFSET 	(0)				//Parameter let the counter-part know what the triger source is.
#define RGU_FRMWRK_PARAMETER_MASK 	(0x000000ff)		//It could be WHOLE_SYSTEM_RESET, AUTO_RESET,  AP_SOFTWARE_RESET_MD,
														//PSCORE_RESET_ARM7, or PSCORE_RESET_L1.
#define RGU_SCOPE_TO_CLEAR_STATE_OFFSET		(8)

#define RGU_SCOPE_TO_CLEAR_STATE_MASK		(0x00000f00)	//For IPs that could not software reset during testing, reset the system to clear corresponding state.
#endif															//This is treated as a flag to distinguish clear state reset or normal reset for UT.
// TODO: Prepare a global variable for Altera that AP might not exist. 
void _rst_set_system_ready_sts(kal_uint32 system, kal_uint32 system_coverage)
{
 kal_uint32 current_val; 
 if ((system & (APSYS | MD1SYS | L1SYS | ARM7SYS))== 0)
 	{
 	 dbg_print("%s: system out of system coverage\n\r", __FUNCTION__);
	 ASSERT(0);
 	}
 /*Add switch case to prevent race condition*/
 switch (system)
 	{
	 case APSYS: //is the first one to enable ready status. 
		//no need to wait.
		dbg_print("Setting MDRGU WDT DUMMY ....\r\n");
		break; 
	 case MD1SYS: //is the second one to enable ready status. 
	 	#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
		if(0 != (APSYS & system_coverage))
		{
	    	dbg_print("Set MDRGU WDT DUMMY write ready for APSYS...\r\n"); 
			current_val = DRV_Reg32(REG_MDRSTCTL_WDT_DUMMY) | APSYS; 
	        DRV_WriteReg32(REG_MDRSTCTL_WDT_DUMMY, current_val);
	 	}
		#endif
	    dbg_print("Wait for (APSYS) MDRGU WDT DUMMY write ready...\r\n"); 
		while((DRV_Reg32(REG_MDRSTCTL_WDT_DUMMY) & (APSYS))!= (APSYS & system_coverage)); 
		break; 
	 case ARM7SYS: //is the third one to enable ready status. 
		dbg_print("Wait for (APSYS,MD1SYS) MDRGU WDT DUMMY write ready...\r\n");
		while((DRV_Reg32(REG_MDRSTCTL_WDT_DUMMY) & (APSYS|MD1SYS))!= ((APSYS|MD1SYS)& system_coverage));
		break; 
	 case L1SYS: //is the last one to enable ready status. 
		dbg_print("Wait for (APSYS,MD1SYS,ARM7SYS) MDRGU WDT DUMMY write ready...\r\n");
		while((DRV_Reg32(REG_MDRSTCTL_WDT_DUMMY) & (APSYS|MD1SYS|ARM7SYS))!= ((APSYS|MD1SYS|ARM7SYS)& system_coverage));
		break;
 	}

 
 current_val = DRV_Reg32(REG_MDRSTCTL_WDT_DUMMY) | system; 
 DRV_WriteReg32(REG_MDRSTCTL_WDT_DUMMY, current_val); 
 dbg_print("After writing ready status, REG_MDRSTCTL_WDT_DUMMY = 0x%08X\r\n", DRV_Reg32(REG_MDRSTCTL_WDT_DUMMY));
}



void _rst_clr_system_ready_sts(kal_uint32 system)
{
 kal_uint32 current_val; 
 if ((system & (APSYS | MD1SYS | L1SYS | ARM7SYS))== 0)
 	{
 	 dbg_print("%s: system out of coverage\n\r", __FUNCTION__);
	 ASSERT(0);
 	}

 current_val = DRV_Reg32(REG_MDRSTCTL_WDT_DUMMY) & ~(system); 
 DRV_WriteReg32(REG_MDRSTCTL_WDT_DUMMY, current_val);
}

kal_uint32 _rst_get_system_ready_sts(void)
{
 return (DRV_Reg32(REG_MDRSTCTL_WDT_DUMMY));
}

kal_uint32 _rst_get_this_reset_scope(void)
{
 kal_uint32 this_reset_scope;
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 this_reset_scope = (DRV_Reg32(TOP_RGU_NONRST_REG2) & RGU_RESET_SCOPE_MASK) >> RGU_RESET_SCOPE_OFFSET;
 #else
 this_reset_scope = (DRV_Reg32(REG_APRSTCTL_DUMMY) & RGU_RESET_SCOPE_MASK) >> RGU_RESET_SCOPE_OFFSET;
 #endif
 return this_reset_scope;
}


void _rst_set_next_reset_scope(kal_uint32 next_reset_scope)
{
 kal_uint32 dummy_content;
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 dummy_content = (DRV_Reg32(TOP_RGU_NONRST_REG2) & (~RGU_RESET_SCOPE_MASK)) | (next_reset_scope << RGU_RESET_SCOPE_OFFSET);
 
 DRV_WriteReg32(TOP_RGU_NONRST_REG2, dummy_content);
 #else
 dummy_content = (DRV_Reg32(REG_APRSTCTL_DUMMY) & (~RGU_RESET_SCOPE_MASK)) | (next_reset_scope << RGU_RESET_SCOPE_OFFSET);

 DRV_WriteReg32(REG_APRSTCTL_DUMMY, dummy_content);
 #endif
}




void _rst_set_rgu_frmwrk_parameter(kal_uint32 content)
{
 kal_uint32 current_val;
 if (((content<< RGU_FRMWRK_PARAMETER_OFFSET) & (~RGU_FRMWRK_PARAMETER_MASK)) > 0) //exceed the parameter range.
 	ASSERT(0);
 else
 	{
 	 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 	 current_val = DRV_Reg32(TOP_RGU_NONRST_REG2) & (~RGU_FRMWRK_PARAMETER_MASK);
 	 current_val |= ((content << RGU_FRMWRK_PARAMETER_OFFSET) & RGU_FRMWRK_PARAMETER_MASK);
 	 DRV_WriteReg32(TOP_RGU_NONRST_REG2, current_val);
 	 #else
 	 current_val = DRV_Reg32(REG_APRSTCTL_DUMMY) & (~RGU_FRMWRK_PARAMETER_MASK);
	 current_val |= (content & RGU_FRMWRK_PARAMETER_MASK);
	 DRV_WriteReg32(REG_APRSTCTL_DUMMY, current_val);
	 #endif
 	}
}


kal_uint32 _rst_get_rgu_frmwrk_parameter(void)
{
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 return ((DRV_Reg32(TOP_RGU_NONRST_REG2) & (RGU_FRMWRK_PARAMETER_MASK)) >> RGU_FRMWRK_PARAMETER_OFFSET);
 #else
 return (DRV_Reg32(REG_APRSTCTL_DUMMY) & (RGU_FRMWRK_PARAMETER_MASK));
 #endif
}


//End:  Dennis  defines the APRGU dummy register to record the current reset scope and corresponding trigger source.

//Begin: Dennis defines the MDRGU dummy register to accumulate the number drv_UT_within_RGU_framework. 09302014.
void _rst_set_rgu_ut_result(kal_uint32 ut_result)  //ut_result  = UT_REPORT_PASS (0) or  UT_REPORT_FAIL(-1).
{
 kal_uint32 current_val;
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 current_val = DRV_Reg32(TOP_RGU_NONRST_REG2) & (~RGU_RESET_UT_RESULT_MASK);
 current_val |= (ut_result & RGU_RESET_UT_RESULT_MASK >> RGU_RESET_UT_RESULT_OFFSET)<<RGU_RESET_UT_RESULT_OFFSET;
 DRV_WriteReg32(TOP_RGU_NONRST_REG2, current_val);
 #else
 current_val = DRV_Reg32(REG_APRSTCTL_DUMMY) & (~RGU_RESET_UT_RESULT_MASK);
 current_val |= (ut_result & RGU_RESET_UT_RESULT_MASK >> RGU_RESET_UT_RESULT_OFFSET)<<RGU_RESET_UT_RESULT_OFFSET;
 DRV_WriteReg32(REG_APRSTCTL_DUMMY, current_val);
 #endif
}


kal_uint32 _rst_get_rgu_ut_result(void)
{
 kal_uint32 current_val; 
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 current_val = (DRV_Reg32(TOP_RGU_NONRST_REG2) & RGU_RESET_UT_RESULT_MASK) >> RGU_RESET_UT_RESULT_OFFSET; 
 #else
 current_val = (DRV_Reg32(REG_APRSTCTL_DUMMY) & RGU_RESET_UT_RESULT_MASK) >> RGU_RESET_UT_RESULT_OFFSET; 
 #endif
 if (UT_REPORT_PASS == current_val)
 	return UT_REPORT_PASS; 
 else
 	return UT_REPORT_FAIL; 
}


void _rst_set_rgu_scope_to_clear_state(kal_uint32 clear_scope)
{
 kal_uint32 current_val;
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 current_val = DRV_Reg32(TOP_RGU_NONRST_REG2) & (~RGU_SCOPE_TO_CLEAR_STATE_MASK) ;
 current_val |= (clear_scope & (RGU_SCOPE_TO_CLEAR_STATE_MASK >> RGU_SCOPE_TO_CLEAR_STATE_OFFSET)) << RGU_SCOPE_TO_CLEAR_STATE_OFFSET;
 DRV_WriteReg32(TOP_RGU_NONRST_REG2, current_val);
 #else
 current_val = DRV_Reg32(REG_APRSTCTL_DUMMY) & (~RGU_SCOPE_TO_CLEAR_STATE_MASK) ;
 current_val |= (clear_scope & (RGU_SCOPE_TO_CLEAR_STATE_MASK >> RGU_SCOPE_TO_CLEAR_STATE_OFFSET)) << RGU_SCOPE_TO_CLEAR_STATE_OFFSET;
 DRV_WriteReg32(REG_APRSTCTL_DUMMY, current_val);
 #endif
}


kal_uint32 _rst_get_rgu_scope_to_clear_state(void)
{
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 return ((DRV_Reg32(TOP_RGU_NONRST_REG2) &  RGU_SCOPE_TO_CLEAR_STATE_MASK) >> RGU_SCOPE_TO_CLEAR_STATE_OFFSET);
 #else
 return ((DRV_Reg32(REG_APRSTCTL_DUMMY) &  RGU_SCOPE_TO_CLEAR_STATE_MASK) >> RGU_SCOPE_TO_CLEAR_STATE_OFFSET);
 #endif
}


void _rst_inc_rgu_api_call_accumulator(void)
{
 kal_uint32 current_val;
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 current_val = (DRV_Reg32(TOP_RGU_NONRST_REG2) & (~RGU_API_CALL_ACCUMULATOR_MASK));
 current_val |= ((DRV_Reg32(TOP_RGU_NONRST_REG2) & RGU_API_CALL_ACCUMULATOR_MASK) + 1);
 DRV_WriteReg32(TOP_RGU_NONRST_REG2, current_val);
 #else
 current_val = DRV_Reg32(REG_MDRSTCTL_DUMMY) + 1;
 DRV_WriteReg32(REG_MDRSTCTL_DUMMY, current_val);
 #endif
}


kal_uint32 _rst_get_rgu_api_call_accumulator(void)
{
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 return (DRV_Reg32(TOP_RGU_NONRST_REG2) & RGU_API_CALL_ACCUMULATOR_MASK);
 #else
 return (DRV_Reg32(REG_MDRSTCTL_DUMMY));
 #endif
}


//Begin: Dennis adds the APIs to set up the trigger path and trigger the corresponding WDT IRQ. 09112014


kal_bool _rst_is_whole_system_reset_triggered()
{
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 if ((WHOLE_SYSTEM_RESET == _rst_get_rgu_frmwrk_parameter()) && (0 == DRV_Reg32(REG_MDRSTCTL_DUMMY)))
 	{
	 dbg_print("Whole system reset is triggered\r\n");
	 return KAL_TRUE;
 	}
 else
   return KAL_FALSE;
 #else
 kal_uint32 current_val;
 //APRGU reset mode.
 //Check WDTSR.
 current_val = DRV_Reg32(REG_APRSTCTL_WDTSR);
 switch(current_val & RSTCTL_WDTSR_STATUS_MASK)
 	{
 	 case RSTCTL_WDTSR_HWDT_STS:
		 dbg_print("Hardware WDT (%d times)\r\n", (current_val>>RSTCTL_WDTSR_HW_WDT_CNT_OFFSET) & RSTCTL_WDTSR_HW_WDT_CNT_MASK);
		 return KAL_TRUE;

	 case RSTCTL_WDTSR_SWDT_STS:
		 dbg_print("Software WDT (%d times)\r\n", (current_val>>RSTCTL_WDTSR_SW_WDT_CNT_OFFSET) & RSTCTL_WDTSR_SW_WDT_CNT_MASK);
		 return KAL_TRUE;

	 case 0:
	 	 dbg_print("INFO (RGU) Whole system reset is not triggered\r\n");
		 return KAL_FALSE;
	 default:
	 	dbg_print("Assert(RGU): Unexpected status case %x <%d line in %s>\r\n",(current_val & RSTCTL_WDTSR_STATUS_MASK), __LINE__, __FUNCTION__ );
		return KAL_FALSE;

 	}
 #endif
}

kal_bool _rst_is_auto_reset_triggered()
{
#if defined(TK6291)
 kal_uint32 current_val;
 current_val = (DRV_Reg32(REG_APRSTCTL_WDTSR_MD1)>>RSTCTL_WDTSR_MD1_SW_WDT_CNT_OFFSET)& RSTCTL_WDTSR_MD1_WDT_CNT_MASK;
 if (current_val > 0)
 	{
	 dbg_print("Auto_reset triggered by MDRGU (%d times)\r\n", current_val);
	 return KAL_TRUE;
 	}
 else
 	return KAL_FALSE;
#else
 return KAL_FALSE;
#endif
}


kal_bool _rst_is_md_reset_triggered()
{
   return KAL_TRUE;
}


kal_bool _rst_is_ap_software_reset_triggered()
{
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 if (0 != DRV_Reg32(TOP_RGU_NONRST_REG))
 	{
	 dbg_print("AP software reset is triggered\r\n");
	 return KAL_TRUE;
 	}
 else
   return KAL_FALSE;
 #else
 //CHECK WDTSR (MD1_WDT_STS)
 kal_uint32 current_val;
 current_val = (DRV_Reg32(REG_APRSTCTL_WDTSR_MD1)>>RSTCTL_WDTSR_MD1_STATUS_OFFSET)& RSTCTL_WDTSR_MD1_STATUS_MASK;

 if ((current_val > 0)&& (AP_SOFTWARE_RESET_MD == _rst_get_rgu_frmwrk_parameter()))
 	{
	 dbg_print("AP software reset MD triggered by MDRGU \r\n");
	 return KAL_TRUE;
 	}
 else
   return KAL_FALSE;
 #endif
}


kal_bool _rst_is_pcore_reset_arm7_triggered()
{

 kal_uint32 current_val;
 current_val = DRV_Reg32(REG_MDRSTCTL_WDTSR_ARM7)& RSTCTL_WDTSR_ARM7_WDT_STS;
 if ((current_val > 0) && (PSCORE_RESET_ARM7 == _rst_get_rgu_frmwrk_parameter()))
 	{
	 dbg_print("P-core reset ARM7 triggered by ARM7 \r\n");
	 return KAL_TRUE;
 	}
 else
   return KAL_FALSE;
}


kal_bool _rst_is_pcore_reset_l1_triggered()
{
 kal_uint32 current_val;
 current_val = DRV_Reg32(REG_MDRSTCTL_WDTSR_L1);
 if (((current_val & RSTCTL_WDTSR_L1_HWDT_STS) > 0)&&(PSCORE_RESET_L1 == _rst_get_rgu_frmwrk_parameter()))
 	{
	 dbg_print("P-core reset L1 triggered by L1_HWDT \r\n");
	 return KAL_TRUE;
 	}
 else if (((current_val & RSTCTL_WDTSR_L1_SWDT_STS) > 0)&&(PSCORE_RESET_L1 == _rst_get_rgu_frmwrk_parameter()))
 		{
		 dbg_print("P-core reset L1 triggered by L1_SWDT \r\n");
		 return KAL_TRUE;
 		}
 	  else
		return KAL_FALSE;
}


kal_bool _rst_clear_whole_system_reset_status(void)
{
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 //DRV_WriteReg32(REG_TOPRGU_MODE,0x22000000);
 _rst_set_rgu_frmwrk_parameter(0);
 #else
 kal_uint32 current_val;
 //Note: remember to disable WDT make sure system under control.
 //Disable the trigger path

 current_val = DRV_Reg32(REG_APRSTCTL_WDTCR);
 current_val &= ~RSTCTL_WDTCR_WDT_EN;
 DRV_WriteReg32(REG_APRSTCTL_WDTCR, RSTCTL_WDTCR_KEY | current_val);
 //Clear the status caused by APRGU reset.
 //Status register: WDTSR (swdt counter, hwdt counter, status)
 DRV_WriteReg32(REG_APRSTCTL_WDTSR, RSTCTL_WDTSR_KEY
 									| RSTCTL_WDTSR_CNT_CLR_MASK << RSTCTL_WDTSR_CNT_CLR_OFFSET
 									| RSTCTL_WDTSR_STS_CLR_MASK << RSTCTL_WDTSR_STS_CLR_OFFSET);
 #endif
 return KAL_FALSE;
}

kal_bool _rst_clear_auto_reset_status(void)
{
 kal_uint32 current_val;
 //Note: remember to disable WDT make sure system under control.

 current_val = DRV_Reg32(REG_MDRSTCTL_WDTCR);
 current_val &= ~RSTCTL_WDTCR_WDT_EN;
 DRV_WriteReg32(REG_MDRSTCTL_WDTCR, RSTCTL_WDTCR_KEY | current_val);
#if defined(TK6291)
 //Disable AUTO RESET
 current_val = DRV_Reg32(REG_APRSTCTL_WDTCR_MD1) & ~RSTCTL_WDTCR_MD1_AP_AUTO_RST;
 DRV_WriteReg32(REG_APRSTCTL_WDTCR_MD1, RSTCTL_WDTCR_MD1_KEY | current_val);

 //Clear the status caused by auto reset
 //Status register: WDTSR_MD1
 DRV_WriteReg32(REG_APRSTCTL_WDTSR_MD1, RSTCTL_WDTSR_MD1_KEY | RSTCTL_WDTSR_MD1_CNT_CLR_MASK << RSTCTL_WDTSR_MD1_CNT_CLR_OFFSET);
 //Clear the counter which is increased upon MD1 IRQ @ AUTO_RST mode.
#endif
 return KAL_TRUE;
}

kal_bool _rst_clear_md_reset_status(void)
{
 //This case is kicked out of the reset scope we applied



 return KAL_TRUE;
}


kal_bool _rst_clear_ap_software_reset_status(void)
{
 kal_uint32 current_val;
 //Note: remember to disable WDT make sure system under control.
 current_val = DRV_Reg32(REG_MDRSTCTL_WDTCR);
 current_val &= ~RSTCTL_WDTCR_WDT_EN;
 DRV_WriteReg32(REG_MDRSTCTL_WDTCR, RSTCTL_WDTCR_KEY | current_val);
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 //clear TOPRGU IRQ counter
 DRV_WriteReg32(TOP_RGU_NONRST_REG, 0);
 DRV_WriteReg32(REG_MDRSTCTL_WDTSR, RSTCTL_WDTSR_KEY | (RSTCTL_WDTSR_STATUS_MASK << RSTCTL_WDTSR_STS_CLR_OFFSET));
 #else
//Disable  the trigger path
 current_val = DRV_Reg32(REG_APRSTCTL_MDWDTCFG_MD1) & ~RSTCTL_MDWDTCFG_MD1_WDT_LV_EN_MD1;
 DRV_WriteReg32(REG_APRSTCTL_MDWDTCFG_MD1, RSTCTL_MDWDTCFG_MD1_KEY | current_val);
//Clear the status caused by MDRGU IRQ
 DRV_WriteReg32(REG_APRSTCTL_WDTSR_MD1, RSTCTL_WDTSR_MD1_KEY | RSTCTL_WDTSR_MD1_STS_CLR_MASK << RSTCTL_WDTSR_MD1_STS_CLR_OFFSET);
 #endif
 //Clear the parameter as well.
 _rst_set_rgu_frmwrk_parameter(0);
 return KAL_TRUE;
}


kal_bool _rst_clear_pcore_reset_arm7_status(void)
{
 kal_uint32 current_val;

 //the trigger path is set from arm7 to pcore and level enable
 current_val = DRV_Reg32(REG_ARM7RSTCTL_WDTCR);
 current_val &= ~RSTCTL_WDTCR_WDT_EN;
 DRV_WriteReg32(REG_ARM7RSTCTL_WDTCR, RSTCTL_WDTCR_KEY | current_val);

 //Note: remember to disable WDT make sure system under control.
 //Disable  the trigger path
 current_val = DRV_Reg32(REG_MDRSTCTL_WDTCFG_ARM7) & ~RSTCTL_WDTCFG_ARM7_LV_EN;
 DRV_WriteReg32(REG_MDRSTCTL_WDTCFG_ARM7, RSTCTL_WDTCFG_ARM7_KEY| current_val);

 //Turn on arm7 bypass to AP(default setting)
 DRV_WriteReg32(REG_MDRSTCTL_WDTCR_ARM7, RSTCTL_WDTCR_WDT_ARM7_KEY | (DRV_Reg32(REG_MDRSTCTL_WDTCR_ARM7) & ~(RSTCTL_WDTCR_WDT_ARM7_IRQ_BYPASS)));

 //Clear the status caused by ARM7 RGU
 DRV_WriteReg32(REG_MDRSTCTL_WDTSR_ARM7, RSTCTL_WDTSR_ARM7_KEY | RSTCTL_WDTSR_ARM7_CLR_ARM7_CNT | RSTCTL_WDTSR_ARM7_CLR_ARM7_STS);
 _rst_set_rgu_frmwrk_parameter(0);
 return KAL_TRUE;
}


kal_bool _rst_clear_pcore_reset_l1_status(void)
{
 kal_uint32 current_val;
 //the trigger path is set from L1 to pcore and level enable

 current_val = DRV_Reg32(REG_L1RSTCTL_WDT_MODE);
 current_val &= ~RSTCTL_L1WDT_MODE_WDTEN;
 DRV_WriteReg32(REG_L1RSTCTL_WDT_MODE, RSTCTL_L1WDT_MODE_KEY | current_val);
 //Note: remember to disable WDT make sure system under control.
 //Disable the trigger path
 current_val = DRV_Reg32(REG_MDRSTCTL_WDTCFG_L1) & ~RSTCTL_WDTCFG_L1_LV_EN;
 DRV_WriteReg32(REG_MDRSTCTL_WDTCFG_L1, RSTCTL_WDTCFG_L1_KEY| current_val);

 //Turn on L1 bypass to AP(default setting)
 DRV_WriteReg32(REG_MDRSTCTL_WDTCR_L1, RSTCTL_WDTCR_WDT_L1_KEY | (DRV_Reg32(REG_MDRSTCTL_WDTCR_L1) | (RSTCTL_WDTCR_WDT_L1_IRQ_BYPASS)));

 //Clear the status caused by L1 RGU
 DRV_WriteReg32(REG_MDRSTCTL_WDTSR_L1, RSTCTL_WDTSR_L1_KEY | RSTCTL_WDTSR_L1_CLR_L1_SWDT_STS| RSTCTL_WDTSR_L1_CLR_L1_HWDT_STS);
 _rst_set_rgu_frmwrk_parameter(0);

 return KAL_TRUE;
}


kal_bool _rst_setup_whole_system_reset_trigger_path(void)
{
 kal_bool ret_status = KAL_TRUE;
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 //set TOPRGU in reset mode
 DRV_WriteReg32(REG_TOPRGU_MODE,0x22000005);
 #else
 kal_uint32 current_val;
 //actually, for whole system reset, it does not need to setup the trigger path.
 //Set APRGU in reset mode.  --> APRGU IRQ disable.
 current_val = DRV_Reg32(REG_APRSTCTL_WDTCR) & ~(RSTCTL_WDTCR_WDT_IRQEN);
 current_val &= ~(RSTCTL_WDTCR_WDT_SPD_UP);
 DRV_WriteReg32(REG_APRSTCTL_WDTCR,RSTCTL_WDTCR_KEY | current_val);
 #endif
 return ret_status;
}

kal_bool _rst_setup_auto_reset_trigger_path(void)
{
 kal_bool ret_status = KAL_TRUE;
 kal_uint32 current_val;
 //Set the path from MDRGU to APRGU. (MDRGU IRQ enable)
 current_val = DRV_Reg32(REG_MDRSTCTL_WDTCR);
 current_val &= ~(RSTCTL_WDTCR_WDT_SPD_UP);
 current_val |= (RSTCTL_WDTCR_WDT_IRQEN);
 DRV_WriteReg32(REG_MDRSTCTL_WDTCR,RSTCTL_WDTCR_KEY | current_val); //1. disable speedup.  2. Enable IRQ_EN
#if defined(TK6291)
 //Set the path to trigger auto reset.
 DRV_WriteReg32(REG_APRSTCTL_WDTCR_MD1, RSTCTL_WDTCR_MD1_KEY | RSTCTL_WDTCR_MD1_AP_AUTO_RST);
#endif
 return ret_status;

}

kal_bool _rst_setup_ap_software_reset_trigger_path(void)
{
 kal_bool ret_status = KAL_TRUE;
 kal_uint32 current_val;
 //Set the path from MDRGU to APRGU. (MDRGU IRQ enable)
 current_val = DRV_Reg32(REG_MDRSTCTL_WDTCR);
 current_val &= ~(RSTCTL_WDTCR_WDT_SPD_UP);
 current_val |= (RSTCTL_WDTCR_WDT_IRQEN);
 DRV_WriteReg32(REG_MDRSTCTL_WDTCR,RSTCTL_WDTCR_KEY | current_val); //1. disable speedup.  2. Enable IRQ_EN
 #if defined(TK6291) 
 //Set the path to trigger CA7 ISR.
 DRV_WriteReg32(REG_APRSTCTL_MDWDTCFG_MD1,RSTCTL_MDWDTCFG_MD1_KEY | RSTCTL_MDWDTCFG_MD1_WDT_LV_EN_MD1); //Dennis stops here!
 #endif
 return ret_status;
}


kal_bool _rst_setup_pcore_reset_arm7_trigger_path(void)
{
 kal_bool ret_status = KAL_TRUE;
 kal_uint32 current_val;
 //set the path from ARM7 to pcore. (ARM7 IRQ enable)
 current_val = DRV_Reg32(REG_ARM7RSTCTL_WDTCR);
 current_val &= ~(RSTCTL_WDTCR_WDT_SPD_UP);
 current_val |= (RSTCTL_WDTCR_WDT_IRQEN);
 DRV_WriteReg32(REG_ARM7RSTCTL_WDTCR,RSTCTL_WDTCR_KEY | current_val); //1. disable speedup.  2. Enable IRQ_EN

 //Disable arm7 IRQ bypass to AP
 DRV_WriteReg32(REG_MDRSTCTL_WDTCR_ARM7, RSTCTL_WDTCR_WDT_ARM7_KEY | (DRV_Reg32(REG_MDRSTCTL_WDTCR_ARM7) & ~(RSTCTL_WDTCR_WDT_ARM7_IRQ_BYPASS)));

 //set the path to trigger Pcore ISR.
 DRV_WriteReg32(REG_MDRSTCTL_WDTCFG_ARM7, RSTCTL_WDTCFG_ARM7_KEY | RSTCTL_WDTCFG_ARM7_LV_EN);

 return ret_status;

}


kal_bool _rst_setup_pcore_reset_l1_trigger_path(void)
{
 kal_bool ret_status = KAL_TRUE;
 //For L1RGU, it supports IRQ mode only.
 // Therefore, we do not need to set the iRQ mode
 
 //Disable L1 IRQ bypass to AP
 DRV_WriteReg32(REG_MDRSTCTL_WDTCR_L1, RSTCTL_WDTCR_WDT_L1_KEY | (DRV_Reg32(REG_MDRSTCTL_WDTCR_L1) & ~(RSTCTL_WDTCR_WDT_L1_IRQ_BYPASS)));

 //Set the path to trigger Pcore ISR.
 DRV_WriteReg32(REG_MDRSTCTL_WDTCFG_L1, RSTCTL_WDTCFG_L1_KEY | RSTCTL_WDTCFG_L1_LV_EN);

 return ret_status;
}


kal_bool _rst_trigger_whole_system_reset(kal_uint32 delay_cycles)
{
 kal_bool ret_status = KAL_TRUE;
 _rst_setup_whole_system_reset_trigger_path();  	  //Set APRGU in reset mode.

 //for this case, we need to trigger reset in APRGU.

 if (0 < delay_cycles)
 	{

 	  //Set WDTIR as delay cycles.
 	  //Restart WDT timer.
	  #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
	  //write frmwk parameter
 	  _rst_set_rgu_frmwrk_parameter(WHOLE_SYSTEM_RESET);
	  //make MDRSTCTL_DUMMY dirty
 	  DRV_WriteReg32(REG_MDRSTCTL_DUMMY,0x22222222);
	  //set toprgu timeout interval
	  DRV_WriteReg32(REG_TOPRGU_LENGTH,0x8|(delay_cycles << 5));  //one delay cycle equals to 15.6ms
	  DRV_WriteReg32(REG_TOPRGU_RESTART,0x1971);
 	  #else
	  kal_uint32 current_val;
	  DRV_WriteReg32(REG_APRSTCTL_WDTIR, RSTCTL_WDTIR_KEY | (delay_cycles & RSTCTL_WDTIR_INTERVAL_MASK));     //one delay cycle equals to 31.25us
	  current_val = DRV_Reg32(REG_APRSTCTL_WDTCR);
	  current_val |= RSTCTL_WDTCR_WDT_EN;
	  DRV_WriteReg32(REG_APRSTCTL_WDTCR,RSTCTL_WDTCR_KEY | current_val);

	  DRV_WriteReg32(REG_APRSTCTL_WDTRR, RSTCTL_WDTRR_KEY | RSTCTL_WDTRR_WDT_RESTART);
	  #endif
 	}
 else //trigger software WDT
 	{
 	 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
	 //write frmwk parameter
 	 _rst_set_rgu_frmwrk_parameter(WHOLE_SYSTEM_RESET);
	 //make MDRSTCTL_DUMMY dirty
	 DRV_WriteReg32(REG_MDRSTCTL_DUMMY,0x22222222);
	 //trigger TOPRGU SWDT reset
	 DRV_WriteReg32(REG_TOPRGU_SWRST,0x00001209);
 	 #else
 	 //Set APRGU in reset mode.
	 //Software triggers APRGU.
	 DRV_WriteReg32(REG_APRSTCTL_SRCMR_SWDT,RSTCTL_SRCMR_KEY_SWDT);
	 #endif
 	}

 return ret_status;
}


/*Package to transform internal function to an offical like API*/
void drv_rstctl_whole_system_reset(kal_uint32 delay_cycles)  
{
 _rst_trigger_whole_system_reset(delay_cycles); 
}


kal_bool _rst_trigger_auto_reset(kal_uint32 delay_cycles)
{
 kal_bool ret_status = KAL_TRUE;
 kal_uint32 current_val;
 _rst_setup_auto_reset_trigger_path(); //Set up the path to  allow auto reset.
 //Note: remember to raise bus protect before actually reset.
 if (0 < delay_cycles)
 	{ //Trigger MDRGU in IRQ mode.
	 DRV_WriteReg32(REG_MDRSTCTL_WDTIR, RSTCTL_WDTIR_KEY | (delay_cycles & RSTCTL_WDTIR_INTERVAL_MASK));
	 current_val = DRV_Reg32(REG_MDRSTCTL_WDTCR);
	 current_val |= RSTCTL_WDTCR_WDT_EN;
	 DRV_WriteReg32(REG_MDRSTCTL_WDTCR,RSTCTL_WDTCR_KEY | current_val);

	 DRV_WriteReg32(REG_MDRSTCTL_WDTRR, RSTCTL_WDTRR_KEY | RSTCTL_WDTRR_WDT_RESTART); //we only needs to wait for MDRGU WDT to down count the delay cycles.
 	}
 else //trigger software WDT
 	{
	 //Disable L1 IRQ BYPASS as a workaround to prevent preloader be interrupted by L1WDT IRQ
	 
	 DRV_WriteReg32(REG_MDRSTCTL_WDTCR_L1, RSTCTL_WDTCR_WDT_L1_KEY | 0);	
	 DRV_WriteReg32(REG_MDRSTCTL_SRCMR_SWDT,RSTCTL_SRCMR_KEY_SWDT);
 	}
 return ret_status;
}

kal_bool _rst_trigger_ap_software_reset(kal_uint32 delay_cycles)
{
 kal_bool ret_status = KAL_TRUE;
 kal_uint32 current_val;
 #if defined(TK6291)
 dbg_print("Before setup ap software reset md path... \r\n"); 
 dbg_print("REG_APRSTCTL_WDTSR_MD1 = 0x%x\r\n", DRV_Reg32(REG_APRSTCTL_WDTSR_MD1)); 
 dbg_print("REG_APRSTCTL_MDWDTCFG_MD1 = 0x%x\r\n", DRV_Reg32(REG_APRSTCTL_MDWDTCFG_MD1)); 
 #endif
 _rst_setup_ap_software_reset_trigger_path();   //Set up the path to allow trigger CA7 ISR.  (MDRGU: enable IRQ, APRGU: enable level )
 #if defined(TK6291)
 dbg_print("After setup ap software reset md path... \r\n");  
 dbg_print("REG_APRSTCTL_WDTSR_MD1 = 0x%x\r\n", DRV_Reg32(REG_APRSTCTL_WDTSR_MD1)); 
 dbg_print("REG_APRSTCTL_MDWDTCFG_MD1 = 0x%x\r\n", DRV_Reg32(REG_APRSTCTL_MDWDTCFG_MD1)); 
 #endif
 if (0 < delay_cycles)
 	{
	 DRV_WriteReg32(REG_MDRSTCTL_WDTIR, RSTCTL_WDTIR_KEY | (delay_cycles & RSTCTL_WDTIR_INTERVAL_MASK));
	 current_val = DRV_Reg32(REG_MDRSTCTL_WDTCR);
	 current_val |= RSTCTL_WDTCR_WDT_EN;
	 DRV_WriteReg32(REG_MDRSTCTL_WDTCR,RSTCTL_WDTCR_KEY | current_val);

	 DRV_WriteReg32(REG_MDRSTCTL_WDTRR, RSTCTL_WDTRR_KEY | RSTCTL_WDTRR_WDT_RESTART); //we only needs to wait for MDRGU WDT to down count the delay cycles.
	 dbg_print("REG_MDRSTCTL_WDTIR = 0x%x\r\n", DRV_Reg32(REG_MDRSTCTL_WDTIR));
	 dbg_print("REG_MDRSTCTL_WDTCR = 0x%x\r\n", DRV_Reg32(REG_MDRSTCTL_WDTCR));
	 dbg_print("REG_MDRSTCTL_WDTSR = 0x%x\r\n", DRV_Reg32(REG_MDRSTCTL_WDTSR)); 
	 dbg_print("\r\n");
	 #if defined(TK6291)
	 dbg_print("REG_APRSTCTL_WDTSR_MD1 = 0x%x\r\n", DRV_Reg32(REG_APRSTCTL_WDTSR_MD1)); 
	 dbg_print("REG_APRSTCTL_MDWDTCFG_MD1 = 0x%x\r\n", DRV_Reg32(REG_APRSTCTL_MDWDTCFG_MD1)); 
	 #endif
	 
 	}
 else //trigger software WDT
 	{
	 DRV_WriteReg32(REG_MDRSTCTL_SRCMR_SWDT,RSTCTL_SRCMR_KEY_SWDT);
 	}


 //Note: remember to raise bus protect before actually reset.

 return ret_status;

}



kal_bool _rst_trigger_pcore_reset_arm7(kal_uint32 delay_cycles)
{
 kal_bool ret_status = KAL_TRUE;
 kal_uint32 current_val;
// dbg_print("Before setup ARM7 triger path, WDTSR_ARM7 = 0x%08x\n\r", DRV_Reg32(REG_MDRSTCTL_WDTSR_ARM7)); 
// dbg_print("Before setup ARM7 triger path, WDTCFG_ARM7= 0x%08x\n\r", DRV_Reg32(REG_MDRSTCTL_WDTCFG_ARM7)); 
 _rst_clear_pcore_reset_arm7_status();		//Clear status before triggering. 
 _rst_setup_pcore_reset_arm7_trigger_path(); //Set up the path to trigger pcore.
// dbg_print("After setup ARM7 triger path, WDTSR_ARM7 = 0x%08x\n\r", DRV_Reg32(REG_MDRSTCTL_WDTSR_ARM7)); 
// dbg_print("After setup ARM7 triger path, WDTCFG_ARM7= 0x%08x\n\r", DRV_Reg32(REG_MDRSTCTL_WDTCFG_ARM7)); 

 if (0 < delay_cycles)
 	{
 	//For drv_UT_within_RGU_framework, the delay_cycles should be 0, because no bus protect between pcore and arm7..
 	//Considering the flexibility, we still implement the case of delay_cycles >  0.
	 DRV_WriteReg32(REG_ARM7RSTCTL_WDTIR, RSTCTL_WDTIR_KEY | (delay_cycles & RSTCTL_WDTIR_INTERVAL_MASK));
	 current_val = DRV_Reg32(REG_ARM7RSTCTL_WDTCR);
	 current_val |= RSTCTL_WDTCR_WDT_EN;
	 DRV_WriteReg32(REG_ARM7RSTCTL_WDTCR, RSTCTL_WDTCR_KEY  | current_val);

	 DRV_WriteReg32(REG_ARM7RSTCTL_WDTRR, RSTCTL_WDTRR_KEY | RSTCTL_WDTRR_WDT_RESTART);
 	}
 else //trigger software WDT
 	{
     //DRV_WriteReg32(REG_ARM7RSTCTL_SRCMR_SWDT, RSTCTL_SRCMR_KEY_SWDT); //ARM SWDT does not trigger interrupt. 10092014
     DRV_WriteReg32(REG_ARM7RSTCTL_WDTIR, RSTCTL_WDTIR_KEY | (1 & RSTCTL_WDTIR_INTERVAL_MASK));
	 current_val = DRV_Reg32(REG_ARM7RSTCTL_WDTCR);
	 current_val |= RSTCTL_WDTCR_WDT_EN;
	 DRV_WriteReg32(REG_ARM7RSTCTL_WDTCR, RSTCTL_WDTCR_KEY  | current_val);
	 DRV_WriteReg32(REG_ARM7RSTCTL_WDTRR, RSTCTL_WDTRR_KEY | RSTCTL_WDTRR_WDT_RESTART);
	 dbg_print("ARM7WDT_WDTIR = %x\r\n", DRV_Reg32(REG_ARM7RSTCTL_WDTIR));
	 dbg_print("RSTCTL_WDTRR_KEY = %x\r\n", RSTCTL_WDTRR_KEY | RSTCTL_WDTRR_WDT_RESTART);
 	}
 return ret_status;

}


kal_bool _rst_trigger_pcore_reset_l1(kal_uint32 delay_cycles)
{
 kal_bool ret_status = KAL_TRUE;
 _rst_clear_pcore_reset_l1_status();//Clear status before triggering. 
 _rst_setup_pcore_reset_l1_trigger_path();  //Set up the path to trigger pcore.
 if (0 < delay_cycles)
 	{
 	//For drv_UT_within_RGU_framework, the delay_cycles should be 0, because no bus protect between pcore and L1.
 	//Considering the flexibility, we still implement the case of delay_cycles > 0.
 	//Note: the delay_cycles is the number of F32K cycles. Therefore we need to convert to l1 time length by dividing 512.
 	 DRV_WriteReg32(REG_L1RSTCTL_WDT_LENGTH, RSTCTL_L1WDT_LENGTH_KEY | (((delay_cycles / 512)<< RSTCTL_L1WDT_LENGTH_OFFSET)& RSTCTL_L1WDT_LENGTH_MASK));
	 DRV_WriteReg32(REG_L1RSTCTL_WDT_MODE, RSTCTL_L1WDT_MODE_KEY | RSTCTL_L1WDT_MODE_WDTEN); //Because this register only has single field, set this register directly.
	 DRV_WriteReg32(REG_L1RSTCTL_WDT_RESTART, RSTCTL_L1WDT_RESTART_KEY);

 	}
 else //trigger software WDT
 	{
	 //DRV_WriteReg32(REG_L1RSTCTL_WDT_SWRST, RSTCTL_L1WDT_SWRST_KEY); 
	 /*Workaround for IRQ not triggered by software WDT*/
	 DRV_WriteReg32(REG_L1RSTCTL_WDT_LENGTH, RSTCTL_L1WDT_LENGTH_KEY | ((1<< RSTCTL_L1WDT_LENGTH_OFFSET)& RSTCTL_L1WDT_LENGTH_MASK));
	 DRV_WriteReg32(REG_L1RSTCTL_WDT_MODE, RSTCTL_L1WDT_MODE_KEY | RSTCTL_L1WDT_MODE_WDTEN); //Because this register only has single field, set this register directly.
 	 DRV_WriteReg32(REG_L1RSTCTL_WDT_RESTART, RSTCTL_L1WDT_RESTART_KEY);
 	}

 return ret_status;

}


//End: Dennis adds the APIs to set up the trigger path and trigger the corresponding WDT IRQ. 09112014

//Begin: Dennis adds the function to execute IP UTs passed into the RGU framework. 09112014.
UT_REPORT_STATUS _rst_check_ip_reset(ut_testcase_struct *testcase_ptr, kal_uint32 test_items) //Only check if reset correctly.
{

 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 if (0 < test_items)  //test_items must equals 1 at least. (test case is mandatorily located at 1st entry. )
 	{
 	 dbg_print("\nCheck IP initial value: %s\n\r", (testcase_ptr)[0].description);
 	 ut_ret_status  = (testcase_ptr)[0]._main_fn(testcase_ptr[0].flags, testcase_ptr[0].para); //  check  initial after reset
 	}
 else
 	{
 	 dbg_print("ASSERT (RGU): <line: %d in function:  %s>\r\n", __LINE__, __FUNCTION__);	 	//This case should not happen.
 	 ut_ret_status = UT_REPORT_FAIL;
 	}
 if (UT_REPORT_PASS == ut_ret_status)
 	dbg_print("\n\n IP initial value check: PASS \n\r");
 else
 	dbg_print("\n\n IP initial value check: FAIL \n\r");
 return ut_ret_status;
}




UT_REPORT_STATUS _rst_run_ip_ut(ut_testcase_struct *testcase_ptr, kal_uint32 test_items)
{
 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 kal_uint32 func_idx;
 if (1 < test_items)
 	{
     for(func_idx = 1; func_idx < test_items; func_idx ++)
     	{
  	  	 dbg_print("\nIP unit test: %s\n\r", (testcase_ptr)[func_idx].description);
		 ut_ret_status	= (testcase_ptr)[func_idx]._main_fn(testcase_ptr[func_idx].flags, testcase_ptr[func_idx].para); //  Other UTs exclude  initial value check.
         if (UT_REPORT_FAIL == ut_ret_status)
		 	return ut_ret_status;
     	}
 	}
 else  //1.  no test case. 2. check IP's initial value only (no other UTs)
 	{
 	 dbg_print("ASSERT (RGU): <line: %d in function:  %s>\r\n", __LINE__, __FUNCTION__);	 	//This case should not happen.
 	 ut_ret_status = UT_REPORT_FAIL;
 	}
 if (UT_REPORT_PASS == ut_ret_status)
 	dbg_print("\n\n IP unit test: PASS \n\r");
 else
 	dbg_print("\n\n IP unit test: FAIL \n\r");

 return ut_ret_status;
}



//End: Dennis adds the function to execute IP UTs passed into the RGU framework. 09112014.


//Begin: Dennis  adds an additional function for control load to identify whether the system is ready. 09172014
kal_bool _rst_is_system_within_converage(subsystem_e target_system, subsystem_e system_converage)
{
 if ((target_system & system_converage) == target_system)
 	return KAL_TRUE;
 else
 	return KAL_FALSE;
}



void UNGATE_ARM7(kal_uint32 system_coverage)
{
	if ((ARM7SYS & system_coverage) == ARM7SYS)
		{
		 dbg_print("0x800d0830 = %x, ([11] ==  1 --> arm7 power on, [21] == 0 --> arm7 power off )\r\n", DRV_Reg32(0x800d0830));
		 if((DRV_Reg32(0x800d0830) & (1 << 21)) == 0)
	 		dbg_print("bit [21] == 0 (power off)\r\n"); 
		 else
			dbg_print("bit [21] == 1 (power on)\r\n"); 
		 dbg_print("ARM7 reset unlock state: %x\r\n", DRV_Reg32(0x800f0168));
	
		 DRV_WriteReg32( 0x80000080 ,0x1e000000 );//Set ARM7 to MD offset address register
		 drv_sm_A7PowerOn();
		}
}

void UNGATE_L1CORE(kal_uint32 system_coverage) //for 1016 release
{    
 if ((L1SYS & system_coverage) == L1SYS)
 	{
     DRV_WriteReg32( 0xF60F0104 ,0x6291F8EE ); //This line is for unlock key
	 DRV_WriteReg32( 0xF60F0100 ,0x10000001 ); /*For L2copro's requirement which needs more  memory  space. Cooperate with HVT dummy load.  */
	 										   /*make mcore_6291_drvtest_nand_booting.*/
	 //DRV_WriteReg32( 0xF60F0100 ,0x08000001 );  /*For Yichih's temporary requirement */
	 DRV_WriteReg32( 0xF60F0104 ,0x1 ); //This line is for update ungate address
     DRV_WriteReg32( 0xF60F0104 ,0x629110C4 ); //This line is for lock key
 	}
	
}



//Begin: Dennis  adds the function to examine IP through different reset scope flow. 09122014.
UT_REPORT_STATUS _rst_examine_ip_through_software_reset(rst_target_e targetIP, ut_testcase_struct *testcase_ptr, kal_uint32 test_items)
{
 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 if (RST_NULL == targetIP) return UT_REPORT_PASS;	//Some IPs (like MEMSYS) do not tolerate software reset.
 dbg_print("\n\n\nINFO (RGU) Software reset stage: \r\n");
 ut_ret_status = _rst_check_ip_reset(testcase_ptr, test_items);  //Only check if power on reset correctly.
 if (UT_REPORT_FAIL == ut_ret_status)
 	 return ut_ret_status;
 else dbg_print("PASS (RGU) check correctness of reset[software reset] @ %s \r\n", __FUNCTION__);

 ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);
 if  (UT_REPORT_FAIL == ut_ret_status)
 	dbg_print("FAIL (RGU) UT check[software reset] @ %s \r\n", __FUNCTION__);
 else
 	dbg_print("PASS (RGU) UT check[software reset] @ %s \r\n", __FUNCTION__);


 //The softwre reset function
 dbg_print("INFO (RGU) Software reset IP @ %s \r\n", __FUNCTION__);
 drv_rstctl_sw_reset(targetIP);
 if(targetIP == RST_L1SYS)
 {
 	kal_uint32 i;
	for(i = 0 ; i < 10 ; i++)    //workaround for l1sys is not up after reset
 		drv_rstctl_sw_reset(RST_L1SYS);
 	UT_DELAY_LOOP(10000 * 10);
 	UNGATE_L1CORE(L1SYS);
 }
 ut_ret_status = _rst_check_ip_reset(testcase_ptr, test_items);  //Only check if reset correctly.
 if (UT_REPORT_FAIL == ut_ret_status)
  	return ut_ret_status;
  else dbg_print("PASS (RGU) check correctness of reset[software reset] @ %s \r\n", __FUNCTION__);

 ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);


 if  (UT_REPORT_FAIL == ut_ret_status)
 	{
 	 dbg_print("FAIL (RGU) UT check[software reset] @ %s \r\n\n\n", __FUNCTION__);
  	 dbg_print("****************************************\r\n");
	 dbg_print("^^  Software reset stage test ::FAIL::&&\r\n");
	 dbg_print("****************************************\r\n");
 	}
 else
 	{
 	 dbg_print("PASS (RGU) UT check[software reset] @ %s \r\n", __FUNCTION__);
  	 dbg_print("****************************************\r\n");
	 dbg_print("^^  Software reset stage test ::PASS::&&\r\n");
	 dbg_print("****************************************\r\n");
 	}
#if !defined(ARM7EJS)
 
 //If the targetIp is MDTOPSM, ARM7 got power off. Futher ARM7 reset could not proceed.
 if (RST_MDTOPSM == targetIP) UNGATE_ARM7(ARM7SYS);  //After resetting ARM7, we should ungate ARM7 for further reset ARM7 test.
#endif
 return ut_ret_status;
}


UT_REPORT_STATUS _rst_examine_ip_through_whole_system_reset(subsystem_e system_converage,ut_testcase_struct *testcase_ptr, kal_uint32 test_items, kal_uint32 delay_cycles)
{
 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 dbg_print("\n\n\nINFO (RGU) Whole system reset stage: \r\n");
 if (KAL_TRUE ==_rst_is_system_within_converage(APSYS, system_converage))
	 {
	 //(1) --> UT --> (2) --> (3) --> reboot --> UT -->(4)

	 //1 (1)
	 if ((0  < delay_cycles)&&(!_rst_is_whole_system_reset_triggered()))
	    {
		 _rst_clr_system_ready_sts(APSYS | MD1SYS | L1SYS | ARM7SYS); 
		 _rst_trigger_whole_system_reset(delay_cycles);
		 dbg_print("INFO (RGU) whole system reseting with delay cycle:%d... @ %s \r\n",delay_cycles, __FUNCTION__);
	 	}
	 ut_ret_status = _rst_check_ip_reset(testcase_ptr, test_items);  //Only check if reset correctly.
	 if (UT_REPORT_FAIL == ut_ret_status)
		 return ut_ret_status;
	 ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);
	 if (UT_REPORT_FAIL == ut_ret_status)
		 return ut_ret_status;
	 dbg_print("PASS (RGU) UT check after bootup @ %s \r\n", __FUNCTION__);
	 if ((0  < delay_cycles)&&(!_rst_is_whole_system_reset_triggered())) //reset should be triggered before UT finished
	 	{
	 	 dbg_print("Delay cycle exceeds the UT runtime,but we still make reset happen.. @ %s \r\n", __FUNCTION__);
		 dbg_print("Wait for reset happen.. @ %s \r\n", __FUNCTION__);
		 while(1);
		 //_rst_clear_whole_system_reset_status();
		 //ASSERT(0);
	 	}
	 //1 (2)
	 if ((0 == delay_cycles)&&(!_rst_is_whole_system_reset_triggered()))
	 	{
 	 	 dbg_print("INFO (RGU) whole system reseting ... @ %s \r\n", __FUNCTION__);
		 _rst_clr_system_ready_sts(APSYS | MD1SYS | L1SYS | ARM7SYS); 
	     _rst_trigger_whole_system_reset(0); //whole system reset.
	     
		 //1 (3)
		 //while(!_rst_is_whole_system_reset_triggered());
		 while(1);
	 	}
	 else
	   dbg_print("INFO (RGU) whole system reset has been triggered @ %s \r\n", __FUNCTION__);
	 
	 while(!_rst_is_whole_system_reset_triggered());
	 //1 (4)
	 _rst_clear_whole_system_reset_status();




	 }
 else //Igrnore whole system reset.
	 {
	  dbg_print("INFO(RGU) APSYS is 'not' included in system converage. Whole system reset test is ignored. \r\n");
	  return UT_REPORT_PASS;
	 }

 if  (UT_REPORT_FAIL == ut_ret_status)
	{
	 dbg_print("********************************************\r\n");
	 dbg_print("^^  Whole system reset stage test ::FAIL::&&\r\n");
	 dbg_print("********************************************\r\n");
	}
 else
	{
	 dbg_print("********************************************\r\n");
	 dbg_print("^^	 Whole system reset stage test ::PASS::&&\r\n");
	 dbg_print("********************************************\r\n");
	}

 return ut_ret_status;


}


UT_REPORT_STATUS _rst_examine_ip_through_auto_reset(subsystem_e system_converage, ut_testcase_struct *testcase_ptr, kal_uint32 test_items, kal_uint32 delay_cycles )
{
 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 dbg_print("\n\n\nINFO (RGU) Auto reset stage: \r\n");
 //Auto reset requires the cooperation of APSYS and MD1SYS.
 if (KAL_TRUE ==_rst_is_system_within_converage(MD1SYS | APSYS, system_converage))
	{
	 //(1) --> UT --> (2) --> (3) --> reboot --> UT--> (4)

	 //1 (1)
	 if ((0  < delay_cycles)&&(!_rst_is_auto_reset_triggered()))
	    {
		 _rst_clr_system_ready_sts(APSYS | MD1SYS | L1SYS | ARM7SYS); 
		 _rst_trigger_auto_reset(delay_cycles);
	 	}
	 ut_ret_status = _rst_check_ip_reset(testcase_ptr, test_items);  //Only check if reset correctly.
	 if (UT_REPORT_FAIL == ut_ret_status)
	   return ut_ret_status;
	 ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);
	 if (UT_REPORT_FAIL == ut_ret_status)
	   return ut_ret_status;
	 dbg_print("PASS (RGU) UT check after bootup @ %s \r\n", __FUNCTION__);
	 if ((0  < delay_cycles)&&(!_rst_is_auto_reset_triggered())) //reset should be triggered before UT finished
	 	{
	 	 dbg_print("Delay cycle exceeds the UT runtime @ %s \r\n", __FUNCTION__);
		 _rst_clear_auto_reset_status();
		 ASSERT(0);
	 	}
	 //1 (2)
	 if ((0 == delay_cycles)&&(!_rst_is_auto_reset_triggered()))
	 	{
	 	dbg_print("INFO (RGU) auto reseting ... @ %s \r\n", __FUNCTION__);
  	    _rst_clr_system_ready_sts(APSYS | MD1SYS | L1SYS | ARM7SYS); 
	    _rst_trigger_auto_reset(0); //ap + pcore got reboot.
	    
		//1 (3)
		while(!_rst_is_auto_reset_triggered()); //Wait for system got reset
	 	}
	 else
	  	dbg_print("INFO (RGU) auto reset has been triggered @ %s \r\n", __FUNCTION__);

	 //1 (4)
	 _rst_clear_auto_reset_status();


 	}
 else
	{
	 dbg_print("INFO(RGU) APSYS or MD1SYS is 'not' included in system converage. AUTO reset test is ignored. \r\n");
	 return UT_REPORT_PASS;
 	}
 if  (UT_REPORT_FAIL == ut_ret_status)
	{
	 dbg_print("************************************\r\n");
	 dbg_print("^^  Auto reset stage test ::FAIL::&&\r\n");
	 dbg_print("************************************\r\n");
	}
 else
	{
	 dbg_print("************************************\r\n");
	 dbg_print("^^  Auto reset stage test ::PASS::&&\r\n");
	 dbg_print("************************************\r\n");
	}

 return ut_ret_status;

}


UT_REPORT_STATUS _rst_examine_ip_through_ap_software_reset(subsystem_e system_converage, ut_testcase_struct *testcase_ptr, kal_uint32 test_items, kal_uint32 delay_cycles,  kal_bool is_core_rebooted)
{
 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 dbg_print("\n\n\nINFO (RGU) AP software reset stage: \r\n");
 //AP software reset MD requires cooperation between APSYS and MD1SYS.
 if (KAL_TRUE ==_rst_is_system_within_converage(MD1SYS | APSYS, system_converage))
	 {
	 //(1) --> UT --> (2) --> (3) --> reboot --> (4)	[is_core_rebooted  == KAL_TRUE]
	 //(1) --> UT --> (2) --> (3) --> (4) --> (5) UT			[is_core_rebooted  == KAL_FALSE] --> Check this IP is effected by resetting other subsystem.

	 //1 (1)
	 if ((0  < delay_cycles)&&(!_rst_is_ap_software_reset_triggered()))
		{
		 _rst_clr_system_ready_sts(MD1SYS | L1SYS | ARM7SYS); 
		 _rst_trigger_ap_software_reset(delay_cycles);
		 dbg_print("INFO (RGU) AP reseting MD with delay cycle:%d... @ %s \r\n",delay_cycles, __FUNCTION__);
	 	}
	 ut_ret_status = _rst_check_ip_reset(testcase_ptr, test_items);  //Only check if reset correctly.
	 if (UT_REPORT_FAIL == ut_ret_status)
		return ut_ret_status;
	 ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);
	 if (UT_REPORT_FAIL == ut_ret_status)
		return ut_ret_status;
	 dbg_print("PASS (RGU) UT check after bootup @ %s \r\n", __FUNCTION__);
	 if ((0  < delay_cycles)&&(!_rst_is_ap_software_reset_triggered())) //reset should be triggered before UT finished
	 	{
	 	 dbg_print("Delay cycle exceeds the UT runtime,but we still make reset happen.. @ %s \r\n", __FUNCTION__);
		 dbg_print("Wait for reset happen.. @ %s \r\n", __FUNCTION__);
		 while(1);
		 //_rst_clear_ap_software_reset_status();
		 //ASSERT(0);
	 	}
	 //1 (2)
	 if ((0 == delay_cycles)&&(!_rst_is_ap_software_reset_triggered()))
	 	{
	 	 dbg_print("INFO (RGU) ap software reseting ... @ %s \r\n", __FUNCTION__);
		 _rst_clr_system_ready_sts(MD1SYS | L1SYS | ARM7SYS); 
		 _rst_trigger_ap_software_reset(0); //only md1sys got reboot.  AP is not effected, therefore APSYS IP UT is necessary.
		 while(1);           //wait for reset happen
	 	}
	 else
	 	dbg_print("INFO (RGU) ap software reset has been triggered @ %s \r\n", __FUNCTION__);
	 //1 (3)
	 while(!_rst_is_ap_software_reset_triggered()){dbg_print(".");}; //Wait for system reset and boot  ready.
	 //1 (4)
	 _rst_clear_ap_software_reset_status();

	 if (KAL_FALSE == is_core_rebooted)
		{
		//1 (5)
		ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);
		}
	 }
 else
	 {
	  dbg_print("INFO(RGU) APSYS or MD1SYS is 'not' included in system converage. AP software reset test is ignored. \r\n");
	  return UT_REPORT_PASS;
	 }
 if  (UT_REPORT_FAIL == ut_ret_status)
	{
	 dbg_print("********************************************\r\n");
	 dbg_print("^^  AP software reset stage test  ::FAIL::&&\r\n");
	 dbg_print("********************************************\r\n");
	}
 else
	{
	 dbg_print("********************************************\r\n");
	 dbg_print("^^  AP software reset stage test  ::PASS::&&\r\n");
	 dbg_print("********************************************\r\n");
	}

 return ut_ret_status;

}


UT_REPORT_STATUS _rst_examine_ip_through_pcore_reset_arm7(subsystem_e system_converage, ut_testcase_struct *testcase_ptr, kal_uint32 test_items, kal_uint32 delay_cycles, kal_bool is_core_rebooted)
{
 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 dbg_print("\n\n\nINFO (RGU) PScore reset ARM7 stage: \r\n");
 //Pcore reset ARM7 requires the cooperation of ARM7SYS and MD1SYS.
 if (KAL_TRUE ==_rst_is_system_within_converage(ARM7SYS | MD1SYS, system_converage))
	 {
	 //(1) --> UT --> (2) --> (3) --> reboot --> UT --> (4) 	[is_core_rebooted  == KAL_TRUE]
	 //(1) --> UT --> (2) --> (3) --> (4) --> (5) UT			[is_core_rebooted  == KAL_FALSE] --> Check this IP is effected by resetting other subsystem.
	 //1 (1)
	 if ((0  < delay_cycles)&&(!_rst_is_pcore_reset_arm7_triggered()))
	    {
		 _rst_clr_system_ready_sts(ARM7SYS); 
		 _rst_trigger_pcore_reset_arm7(delay_cycles);
	 	}
	 ut_ret_status = _rst_check_ip_reset(testcase_ptr, test_items);  //Only check if reset correctly.
	 if (UT_REPORT_FAIL == ut_ret_status)
		 return ut_ret_status;
	 ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);
	 if (UT_REPORT_FAIL == ut_ret_status)
		 return ut_ret_status;
	 dbg_print("PASS (RGU) UT check after bootup @ %s \r\n", __FUNCTION__);
	 if ((0  < delay_cycles)&&(!_rst_is_pcore_reset_arm7_triggered())) //reset should be triggered before UT finished
	 	{
	 	 dbg_print("Delay cycle exceeds the UT runtime,but we still make reset happen.. @ %s \r\n", __FUNCTION__);
		 //_rst_clear_pcore_reset_arm7_status();
		 //ASSERT(0);
	 	}
	 //1 (2)

	 if ((0 == delay_cycles)&&(!_rst_is_pcore_reset_arm7_triggered()))
	 	{
		 dbg_print("INFO (RGU) pcore is reseting ARM7 ... @ %s \r\n", __FUNCTION__);
 		 _rst_clr_system_ready_sts(ARM7SYS); 
		 dbg_print("INFO (RGU) ARM7WDT_WDTCR = %x\r\n", DRV_Reg32(REG_ARM7RSTCTL_WDTCR));  //Check if ARM7 is power off.
		 _rst_trigger_pcore_reset_arm7(0); //only ARM7 got reboot. AP  is not effected, therefore APSYS IP UT is necessary.
	     //call AP_boot_pcore here. Wait Brian's API
	 	}
	 else
	 	dbg_print("INFO (RGU) pcore reset arm7 has been triggered @ %s \r\n", __FUNCTION__);

	 //1 (3)
	 while (!_rst_is_pcore_reset_arm7_triggered());   //Wait for system reset and boot ready.
	 //1 (4)
	 _rst_clear_pcore_reset_arm7_status();
	 if (KAL_FALSE == is_core_rebooted)
		{
	 //1 (5)
		ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);
		}



	 }
 else
	 {
	  dbg_print("INFO(RGU) ARM7SYS is 'not' included in system converage. PSCORE reset ARM7 test is ignored. \r\n");
	  return UT_REPORT_PASS;
	 }
 if  (UT_REPORT_FAIL == ut_ret_status)
	{
	 dbg_print("********************************************\r\n");
	 dbg_print("^^	 PScore reset ARM7 stage test  ::FAIL::&&\r\n");
	 dbg_print("********************************************\r\n");
	}
 else
	{
	 dbg_print("********************************************\r\n");
	 dbg_print("^^  PSCore reset ARM7 stage test  ::PASS::&&\r\n");
	 dbg_print("********************************************\r\n");
	}

 return ut_ret_status;
}


UT_REPORT_STATUS _rst_examine_ip_through_pcore_reset_l1(subsystem_e system_converage, ut_testcase_struct *testcase_ptr, kal_uint32 test_items, kal_uint32 delay_cycles, kal_bool is_core_rebooted)
{
 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 dbg_print("\n\n\nINFO (RGU) PScore reset L1 stage: \r\n");
 //Pcore reset ARM7 requires the cooperation of L1SYS and MD1SYS.
 if (KAL_TRUE ==_rst_is_system_within_converage(L1SYS|MD1SYS, system_converage))
	 {
	 //(1) --> UT --> (2) --> (3) --> reboot --> UT --> (4) 	[is_core_rebooted  == KAL_TRUE]
	 //(1) --> UT --> (2) --> (3) --> (4) --> (5) UT			[is_core_rebooted  == KAL_FALSE] --> Check this IP is effected by resetting other subsystem.
	 //1 (1)

	 if ((0  < delay_cycles)&&(!_rst_is_pcore_reset_l1_triggered()))
	    {
		 _rst_clr_system_ready_sts(L1SYS); 
		 _rst_trigger_pcore_reset_l1(delay_cycles);
	 	}
	 ut_ret_status = _rst_check_ip_reset(testcase_ptr, test_items);  //Only check if reset correctly.
	 if (UT_REPORT_FAIL == ut_ret_status)
		 return ut_ret_status;
	 ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);
	 if (UT_REPORT_FAIL == ut_ret_status)
		 return ut_ret_status;
	  dbg_print("PASS (RGU) UT check after bootup @ %s \r\n", __FUNCTION__);
	  if ((0  < delay_cycles)&&(!_rst_is_pcore_reset_l1_triggered()))  //reset should be triggered before UT finished
	 	{
	   	 dbg_print("Delay cycle exceeds the UT runtime,but we still make reset happen.. @ %s \r\n", __FUNCTION__); 
		 //_rst_clear_pcore_reset_l1_status();
		 //ASSERT(0);
	 	}
	 //1 (2)

	 if ((0 == delay_cycles)&&(!_rst_is_pcore_reset_l1_triggered()))
	 	{
		 dbg_print("INFO (RGU) pcore is reseting L1 ... @ %s \r\n", __FUNCTION__);
 		 _rst_clr_system_ready_sts(L1SYS); 
		 _rst_trigger_pcore_reset_l1(0); //Only L1 got reboot.
 	 	//call AP_boot_pcore here. Wait Brian's API
	 	}
	 else
	 	dbg_print("INFO (RGU) pcore reset l1 has been triggered @ %s \r\n", __FUNCTION__);
	 //1 (3)
	 while (!_rst_is_pcore_reset_l1_triggered());	 //Wait for system reset and boot ready.
	 //1 (4)
	 _rst_clear_pcore_reset_l1_status();
	 if (KAL_FALSE == is_core_rebooted)
		{
		 //1 (5)
		ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);
		}
	 }
 else
	 {
	  dbg_print("INFO(RGU) L1SYS is 'not' included in system converage. PSCORE reset L1 test is ignored. \r\n");
	  return UT_REPORT_PASS;
	 }
 if  (UT_REPORT_FAIL == ut_ret_status)
	{
	 dbg_print("****************************************\r\n");
	 dbg_print("^^ PScore reset L1 stage test ::FAIL::&&\r\n");
	 dbg_print("****************************************\r\n");
	}
 else
	{
	 dbg_print("****************************************\r\n");
	 dbg_print("^^ PScore reset L1 stage test ::PASS::&&\r\n");
	 dbg_print("****************************************\r\n");
	}

 return ut_ret_status;
}

void _rst_enable_permission_from_ap_to_md(void)
{
 //Contact window Wellken
 DRV_WriteReg32(0xF0060090, 0xFFFF);
 DRV_WriteReg32(0xF0060094, 0xFFFF); 
 DRV_WriteReg32(0xF0060098, 0xFFFF);
 DRV_WriteReg32(0xF006009C, 0xFFFF);
 DRV_WriteReg32(0xF00600A0, 0xFFFF);
 DRV_WriteReg32(0xF00600A4, 0xFFFF);
 DRV_WriteReg32(0xF00600A8, 0xFFFF);
 DRV_WriteReg32(0xF00600AC, 0xFFFF);
 //Wellken adds new permission setting from AP to L1; 11/25/2014
 DRV_WriteReg32(0xF00600C4, 0x7);
}



void _rst_workaround_to_reset_unsteady_core(kal_uint32 system_ready_sts, kal_uint32 system_coverage)
{
  #if defined (CORTEXA7)
  kal_uint32 current_val; 
  #endif
  switch (system_ready_sts & system_coverage)
	{
	 
	 case (APSYS|MD1SYS)://if arm7 is not ready exceeding waiting period, force arm7 reset. 
	 				if (0 != (ARM7SYS & system_coverage)) 
	 					{
			 			 dbg_print("Exceeding waiting period, ARM7 is not ready. Reseting ARM7 ...\r\n"); 
						 drv_rstctl_sw_reset(RST_ARM7SYS);
						 UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE * 10);
						 UNGATE_ARM7(system_coverage);
	 					}
					break; 
	 case (APSYS|MD1SYS|ARM7SYS)://if L1core is not ready exceeding waiting period, force L1core reset. 
	 				if (0 != (L1SYS & system_coverage))
	 					{
			 			 dbg_print("Exceeding waiting period, L1core is not ready. Reseting L1core ...\r\n"); 
						 drv_rstctl_sw_reset(RST_L1SYS);
						 UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE * 10);
				 		 UNGATE_L1CORE(system_coverage);
	 					}
					break;
	 case (APSYS|MD1SYS|L1SYS): 
	 				if (0 != (ARM7SYS & system_coverage))
	 					{
	 					 dbg_print("Exceeding waiting period, ARM7 is not ready. Reseting ARM7 ...\r\n"); 
						 drv_rstctl_sw_reset(RST_ARM7SYS);
						 UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE * 10);
						 UNGATE_ARM7(system_coverage);
	 					}
					break; 
	 default: 
					dbg_print("Warning: Incorrect system coverage.");
					ASSERT(0);
					break;
	}
}


/*Workaround mechanism for unsteady core*/
kal_uint32 _rst_scan_and_reset_unsteady_core(kal_uint32 system_coverage, kal_uint32 period_wait_system_ready)
{
 kal_uint32 loop_count = 0; 
 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #else
 if (system_coverage != (_rst_get_system_ready_sts()& system_coverage))
 	{
 	 dbg_print("system ready status: 0x%08x\r\n", _rst_get_system_ready_sts()); 
  	 while(system_coverage != (_rst_get_system_ready_sts()& system_coverage));
 	 dbg_print("system is ready: 0x%08x\r\n", _rst_get_system_ready_sts()); 
 	}
 #endif
 return loop_count; 
}



//Begin: Dennis implements an ISR to handle WDT interrupt. 09092014
void _rst_pcore_wdt_isr_handle_ARM7_WDT(kal_uint32 vector)
{

 dbg_print("PCORE ARM7 WDT ISR handler @ %s\n\r", __FUNCTION__);
 drv_rstctl_sw_reset(RST_ARM7SYS);
 _rst_set_rgu_frmwrk_parameter(PSCORE_RESET_ARM7);
 UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE * 10);
 //UNGATE_ARM7(ARM7SYS);       //Note:no need to ungate arm7 after sw reseting arm7 


 //Note: After ARM7 reset, remember to call  pcore_boot_arm7.

 //Note: After L1 reset, remember to call pcore_boot_l1.
}


void _rst_pcore_wdt_isr_handle_L1_WDT(kal_uint32 vector)
{
 kal_uint32 i;
 dbg_print("PCORE L1 WDT ISR handler @ %s\n\r", __FUNCTION__);
 for(i = 0 ; i < 10 ; i++)    //workaround for l1sys is not up after reset
  drv_rstctl_sw_reset(RST_L1SYS);
 _rst_set_rgu_frmwrk_parameter(PSCORE_RESET_L1);
 UT_DELAY_LOOP(10000 * 10);
 UNGATE_L1CORE(L1SYS);  //L1SYS must exist to trigger L1WDT IRQ.


 //Note: After ARM7 reset, remember to call  pcore_boot_arm7.

 //Note: After L1 reset, remember to call pcore_boot_l1.
}


//End: Dennis implements an ISR to handle WDT interrupt. 09092014


//Begin: Dennis registers an ISR to handle interrupt. 09092014
UT_REPORT_STATUS _rst_register_pcore_ISR(kal_uint32 irq_vector, void (*_wdt_lisr)(kal_uint32), char *isr_desc)
{
 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 IRQ_Register_LISR(irq_vector,_wdt_lisr, isr_desc);
 IRQSensitivity(irq_vector, KAL_TRUE);
 IRQClearInt(irq_vector);
 IRQUnmask(irq_vector);
 dbg_print("PS-core ISR registration [%s] done (@%s).\n\r", isr_desc, __FUNCTION__);
 return ut_ret_status;
}


//End: Dennis registers an ISR to handle interrupt. 09092014





//Begin: Dennis decomposes the md1sys part of RGU framework. 09092014
UT_REPORT_STATUS _rst_md1sys_dominate_reset_scope(kal_bool control_load, rst_target_e targetIP,subsystem_e system_coverage, ut_testcase_struct *testcase_ptr, kal_uint32 test_items, kal_uint32 delay_cycles)
{
 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 kal_uint32 reset_scope_idx;
 kal_uint32 loop_count; 
 #define  	PCORE_PERIOD_WAIT_SYSTEM_READY 	(0x000f0000) 
 _rst_register_pcore_ISR(IRQ_ARM7_WDT_CODE, _rst_pcore_wdt_isr_handle_ARM7_WDT, "ARM7_ISR_Handle");
 _rst_register_pcore_ISR(IRQ_L1_WDT_CODE, _rst_pcore_wdt_isr_handle_L1_WDT, "L1_ISR_Handle");
 _rst_set_system_ready_sts(MD1SYS, system_coverage); //Notify the reset cores that MD1SYS is ready. 

 if (0== test_items)
 	{
 	 dbg_print("Waiting for wall cores are ready....\r\n");    	 
	 //Start the while loop to prevent the dead lock that that ARM7 is not ready.  
	 loop_count = _rst_scan_and_reset_unsteady_core(system_coverage, PCORE_PERIOD_WAIT_SYSTEM_READY); 
	 dbg_print("INFO (RGU) All cores in the system coverage are ready (waiting loop: %x). \r\n", loop_count); 
     dbg_print("Dummy load to react RGU req (%s) @ CORTEX-R4_PSCORE\r\n", __FUNCTION__);
	 while (1) //Just act as a dummy-load
	 	{
		 loop_count = _rst_scan_and_reset_unsteady_core(system_coverage, PCORE_PERIOD_WAIT_SYSTEM_READY); 
		 if (loop_count > 0)
		 	{
			 dbg_print(">>>Pcore dummy load detect unstable cores and reset them.\r\n"); 
		 	}			 	
	 	}
 	}
 else    //Control load or support load
   if (KAL_TRUE != control_load)	//Support load
   	{
	 dbg_print("Waiting for wall cores are ready....\r\n");    	 
	 //Start the while loop to prevent the dead lock that that ARM7 is not ready.  
	 loop_count = _rst_scan_and_reset_unsteady_core(system_coverage, PCORE_PERIOD_WAIT_SYSTEM_READY); 
	 dbg_print("INFO (RGU) All cores in the system coverage are ready (waiting loop: %x). \r\n", loop_count); 
	 dbg_print("Support load to call the UT (%s) @ CORTEX-R4_PSCORE\n\r", __FUNCTION__);
	 while(UT_REPORT_PASS == ut_ret_status)
	 	{
	 	 ut_ret_status = _rst_check_ip_reset(testcase_ptr, test_items);  //Only check if power on reset correctly.
	 	 if (UT_REPORT_PASS ==  ut_ret_status )
	 	 	{
	 	 	 dbg_print("PASS (RGU) [Support load] Initial check pass @%s\r\n", __FUNCTION__);
			 ut_ret_status = _rst_run_ip_ut(testcase_ptr, test_items);
			 if (UT_REPORT_PASS ==  ut_ret_status )
			 	dbg_print("PASS (RGU) [Support load] UT check pass @%s\r\n", __FUNCTION__);
			 else
			 	dbg_print("FAIL (RGU) [Support load] UT check fail @%s\r\n", __FUNCTION__);
	 	 	}
		 else
		 	{
			 dbg_print("FAIL (RGU) [Support load] Initial check fail @%s\r\n", __FUNCTION__);
		 	}
		 	 	{
		 loop_count = _rst_scan_and_reset_unsteady_core(system_coverage, PCORE_PERIOD_WAIT_SYSTEM_READY); 
		 if (loop_count > 0)
		 	{
			 dbg_print(">>>Pcore dummy load detect unstable cores and reset them.\r\n"); 
		 	}
	 	}
	 	}// As long as the ut_ret_status is UT_REPORT_PASS, the support load could run the program infinitely.
	 while(1); //If one of the UT's ut_ret_statuses is UT_REPORT_FAIL, the support load will break the above cycle to act as a dummy load.

   	}
   else		//Control load
 	 dbg_print("Dominate RGU scope (%s) @ CORTEX-R4_PSCORE\r\n", __FUNCTION__);

 //_rst_run_function_by_array(testcase_ptr,0,1);

#if 1
 // TODO: if system state clear flag is set, clear the whole system reset status and system clear flag.
 if (AP_SOFTWARE_RESET_MD == _rst_get_rgu_scope_to_clear_state())
 	{
 	 _rst_clear_ap_software_reset_status();
	 _rst_set_rgu_scope_to_clear_state(0);
 	}
#endif
 
 reset_scope_idx = _rst_get_this_reset_scope();
 while (reset_scope_idx < RGU_RESET_SCOPE_END)
	{
	 dbg_print("INFO (RGU) Waiting for all cores in the system coverage ready...\n\r"); 
	 //Start the while loop to prevent the dead lock that that ARM7 is not ready.  
	 loop_count = _rst_scan_and_reset_unsteady_core(system_coverage, PCORE_PERIOD_WAIT_SYSTEM_READY);
	 dbg_print("INFO (RGU) All cores in the system coverage are ready (waiting loop: %x). \r\n", loop_count); 
	 switch (reset_scope_idx)
	 	{
		 case SOFTWARE_RESET:
			    ut_ret_status = _rst_examine_ip_through_software_reset(targetIP, testcase_ptr, test_items);
			    //ut_ret_status = UT_REPORT_PASS;
				break;
		 case WHOLE_SYSTEM_RESET:
			    ut_ret_status = _rst_examine_ip_through_whole_system_reset(system_coverage, testcase_ptr, test_items, delay_cycles);
				//ut_ret_status = UT_REPORT_PASS;
				break;
		 #if defined(TK6291)
		 case AUTO_RESET:
		 		//Run this case twice: auto_reset not triggered and auto_reset triggered.
		 		ut_ret_status = _rst_examine_ip_through_auto_reset(system_coverage,testcase_ptr, test_items, delay_cycles); //MD1SYS got reset.
				break;
		 #endif
		 case AP_SOFTWARE_RESET_MD:
  			    //Run this case twice: ap_software_reset not triggered and ap_software_reset triggered.
				ut_ret_status = _rst_examine_ip_through_ap_software_reset(system_coverage, testcase_ptr, test_items, delay_cycles, KAL_TRUE);
				break;
		 case PSCORE_RESET_ARM7:
		 	    //Run this case only once: pcore_reset_arm7 not triggered and pcore_reset_arm7 triggered.
		 		ut_ret_status = _rst_examine_ip_through_pcore_reset_arm7(system_coverage, testcase_ptr, test_items, 0, KAL_FALSE);
				//ut_ret_status = UT_REPORT_PASS;
				break;
		 case PSCORE_RESET_L1:
		 		//Run this case twice: pcore_reset_l1 not triggered and pcore_reset_l1 triggered.
				ut_ret_status = _rst_examine_ip_through_pcore_reset_l1(system_coverage, testcase_ptr, test_items, 0, KAL_FALSE);
				//ut_ret_status = UT_REPORT_PASS;
				break;
		 default:
		 	dbg_print("ASSERT (Dennis): <line: %d in function:  %s>\r\n", __LINE__, __FUNCTION__);
			ut_ret_status = UT_REPORT_FAIL;
	 	}
	 if (UT_REPORT_PASS == ut_ret_status)
	 	{
 		 _rst_set_next_reset_scope(reset_scope_idx + 1);
		 reset_scope_idx = _rst_get_this_reset_scope();

		 //To prevent some uncareful UT design that forgets to restore initial valu, this framework software reset the target IP before new scope test.  .
		 dbg_print("INFO (RGU) Restore IP's original value @ %s \r\n", __FUNCTION__);
		 if (RST_NULL != targetIP)
		 	{
		 	 drv_rstctl_sw_reset(targetIP);
			 if(targetIP == RST_L1SYS)
 			 {
 				kal_uint32 i;
				for(i = 0 ; i < 10 ; i++)    //workaround for l1sys is not up after reset
 					drv_rstctl_sw_reset(RST_L1SYS);
 				UT_DELAY_LOOP(10000 * 10);
 				UNGATE_L1CORE(L1SYS);
 			 }
			  //If the targetIp is MDTOPSM, ARM7 got power off. Futher ARM7 reset could not proceed.
			 if (RST_MDTOPSM == targetIP)
			 	{
			 	 #if defined(ARM7_ENABLE)
			 		UNGATE_ARM7();	//After resetting ARM7, we should ungate ARM7 for further reset ARM7 test.
			 	 #endif
			 	}
		 	}
		 else  //Since the IP could not be reset, we need to clear the state for the next reset scope.
		 	{
			 // TODO: Add AP software reset md here to create a clear state for the next reset scope.
			 // TODO: Add the system state clear flag for distinguishment from reset for UT test.
			 _rst_set_rgu_scope_to_clear_state(AP_SOFTWARE_RESET_MD);
			 _rst_clr_system_ready_sts(MD1SYS | L1SYS | ARM7SYS);
			 _rst_trigger_ap_software_reset(0);
			 while(1);
		 	}
	 	}
	 else
	 	{
 	 	 dbg_print("ASSERT (RGU): IP UT check fail.  <line: %d in function:  %s>\r\n", __LINE__, __FUNCTION__);
	 	 return ut_ret_status;
	 	}
 	}

	//loop_count = _rst_scan_and_reset_unsteady_core(system_coverage, PCORE_PERIOD_WAIT_SYSTEM_READY); 

 if (RGU_RESET_SCOPE_END == reset_scope_idx)   //Considering multiple call of this API, we need to reset the scope idx as well..
 	_rst_set_next_reset_scope(SOFTWARE_RESET); //Upon all the reset scopes are tested,  set the reset scope condition back to SOFTWARE_RESET.

 return ut_ret_status;
}





//Begin: Dennis adds the function to return the maximum weighted subsystem. 09122014
subsystem_e _rst_return_dominate_system(subsystem_e target_system)
{
 if (APSYS == (target_system & APSYS))
 	return APSYS;
 if (MD1SYS == (target_system & MD1SYS))
 	return MD1SYS;
 if (L1SYS == (target_system & L1SYS))
 	return L1SYS;
 if (ARM7SYS == (target_system & ARM7SYS))
 	return ARM7SYS;
 return 0;
}


//End: Dennis adds the function to return the maximum weighted subsystem. 09122014


kal_uint32 g_RGU_IT_API_CALL_ACCUMULATOR = 0;

void _rst_prepare_for_next_rgu_it_call(subsystem_e system_coverage, UT_REPORT_STATUS ut_ret_status)
{
 _rst_inc_rgu_api_call_accumulator();   //Increase RGU_API_CALL accumulator to prevent executing allready tested RGU_API.
 _rst_set_rgu_ut_result(ut_ret_status); //Store the ut_ret_status. If the status is UT_REPORT_FAIL, all the reset RGU_APIs will be ignored.
 UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE);  //Wait for effective register write.
 if (APSYS == (system_coverage & APSYS))
 	{
	 dbg_print("Rebooting system through whole system reset....\n\r");
	 dbg_print("ALTERA needs to reload code through CMM again. \n\r");
	 _rst_clr_system_ready_sts(APSYS | MD1SYS | L1SYS | ARM7SYS);
	 _rst_trigger_whole_system_reset(0);	   //At the end of this API call, trigger whole systemr reset to make system ready for next API call.

 	}
 else  //Without AP, system coverage only includes MD1SYS, L1SYS, and/or ARM7SYS. 
 	{
	 dbg_print("Without AP to boot up Pcore, you need to reload code through CMM again. \n\r");
	 while(1);
 	}

}


//Begin: Dennis tries to try his own RGU framework design. 09052014
UT_REPORT_STATUS drv_UT_within_RGU_framework(rst_target_e targetIP, subsystem_e target_system, subsystem_e system_coverage,
													   ut_testcase_struct *testcase_ptr, kal_uint32 test_items, kal_uint32 delay_cycles)
{
 //UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS; //TODO Remember to correct this line after completion
 UT_REPORT_STATUS ut_ret_status = UT_REPORT_PASS;
 UNGATE_ARM7(system_coverage);
 UNGATE_L1CORE(system_coverage);
 #if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif
 if (drv_rstctl_disable_all_WDTs() == KAL_FALSE)
		  {
		   dbg_print("ASSERT (RGU): Disable WDT FAIL <line: %d in function:  %s>\r\n", __LINE__, __FUNCTION__);	  //This case should not happen.
		   return UT_REPORT_FAIL;
		  }
 DRV_WriteReg32(0x800f0104,0x56000000);  //L1_WDT_INT bypass off
 dbg_print("workaround L1 RGU short interval by setting 0x800f0104 = 0x56000000 \r\n");
 #endif
  g_RGU_IT_API_CALL_ACCUMULATOR ++;  //Global variable used to count the number of iterations that APIs are called. 
 //dbg_print("RGU_IT UT result:  %d\r\n", _rst_get_rgu_ut_result());
 if (_rst_get_rgu_ut_result() != UT_REPORT_PASS)  	//The UT result of the previous iteration. If UT fails in earlier iteration, this iteration is ignored.
 	{												/*Note: For the 1st iteration, the default value is 0. And UT_REPORT_PASS is 0 as well.*/
	 dbg_print("Checking (api_call_acc,api_passed_acc) = (%d, %d): %d\r\n", g_RGU_IT_API_CALL_ACCUMULATOR,_rst_get_rgu_api_call_accumulator(), _rst_get_rgu_ut_result());
 	 if (g_RGU_IT_API_CALL_ACCUMULATOR == _rst_get_rgu_api_call_accumulator())
	 	dbg_print("INFO (RGU) RGU_IT UT fail! @ drv_UT_within_RGU_framework (%d)\r\n", g_RGU_IT_API_CALL_ACCUMULATOR);
 	 return UT_REPORT_FAIL;  //If some UT fails one of early RGU_IT_API call,  the reset RGU_IT_APIs are ignored.
 	}


 dbg_print("INFO (RGU)g_RGU_IT_API_CALL_ACCUMULATOR : %d ; _rst_get_rgu_api_call_accumulator:  %d \r\n", g_RGU_IT_API_CALL_ACCUMULATOR, _rst_get_rgu_api_call_accumulator());
 if (g_RGU_IT_API_CALL_ACCUMULATOR <= _rst_get_rgu_api_call_accumulator())
 	return UT_REPORT_PASS;
 /*rgu_api_call_accumulator records the actual number of this API been called.
    But system reset makes g_RGU_IT_API_CALL_ACCUMULATOR starts from 0.
    For example, we have 40 RGUi_IT_API call and the actual rgu_api_call_accumulator is 30.
    Then we will ignore the early 30 API calls and start the 31th RGU_IT_API call.
    Note that  6 reset scopes will be triggered within each API call. */

 dbg_print("\r\n\n\n\nINFO (RGU) API call accumulator: %d; Delay cycles: %d\n\n\r", g_RGU_IT_API_CALL_ACCUMULATOR, delay_cycles);




 //Init part
 //Ask Wellken to offer the API to enable IP regsters are accessible by CA7, ARM7, P-core, and L1-core


if (KAL_FALSE == _rst_is_system_within_converage(target_system, system_coverage))
	{
	 dbg_print("ASSERT (RGU): Target system is not included in the system coverage  <line: %d in function:  %s>\r\n", __LINE__, __FUNCTION__);
	 return UT_REPORT_FAIL;
	}

if (RGU_RESET_SCOPE_END == _rst_get_rgu_scope_to_clear_state())  //If  the last whole  system reset is triggered for a new iternation, the status must be cleared. 
	{
     _rst_clear_whole_system_reset_status();    //Clear the whole system reset status.
     _rst_set_rgu_scope_to_clear_state(0);	//Clear the ditinguishable flag that was marked as RGU_RESET_SCOPE_END. 
	}



  dbg_print("%s @ CORTEX-R4_PSCORE\n\r", __FUNCTION__);
  if (MD1SYS == (target_system & MD1SYS))
  	{
     dbg_print("target system = MD1SYS\n\r");
	 if (MD1SYS == _rst_return_dominate_system(target_system))
	 	{
 	 	 ut_ret_status = _rst_md1sys_dominate_reset_scope(KAL_TRUE, targetIP, system_coverage, testcase_ptr, test_items, delay_cycles); //Dominate the reset scope and tests the UTs.
		 _rst_set_rgu_scope_to_clear_state(RGU_RESET_SCOPE_END); //For the next iteration, it is necessary to offer a clear dependent state. To distinguish framework or new iteration reset, we burry RGU_RESET_SCOPE_END. 
		 _rst_prepare_for_next_rgu_it_call(system_coverage, ut_ret_status); //reset the system to for the next API (drv_UT_within_RGU_framework) call.
	 	}
 	 else
		_rst_md1sys_dominate_reset_scope(KAL_FALSE, targetIP, system_coverage, testcase_ptr, test_items, delay_cycles); //Call the UTs but controlled by other subsystem.
  	}
  else
  	{
     _rst_md1sys_dominate_reset_scope(KAL_FALSE, 0, system_coverage, NULL, 0, 0); //act as md1_dummy load.
  	}

 return ut_ret_status;
}



/*************************************************************************
* FUNCTION
*  drv_rstctl_apwd_clrCnt used in drvtest for USB whole system reset. 
*
* DESCRIPTION
*  This function is used to clear both SW WD Cnt and HW WD Cnt 
*
* PARAMETERS
*	void 
*
* RETURN VALUES
*	none
*************************************************************************/
#if defined(TK6291)
void drv_rstctl_apwd_clrCnt(void)
{
    /*Not support Counter in TK6291*/
	#define		RSTCTL_APWDTSR_KEY_OFFSET 	(24)
	#define 	RSTCTL_APWDTSR_KEY			(0x76  << RSTCTL_APWDTSR_KEY_OFFSET)
    DRV_WriteReg32(REG_APRSTCTL_WDTSR,(RSTCTL_APWDTSR_KEY)|((RSTCTL_WDTSR_CNT_CLR_MASK)<<RSTCTL_WDTSR_CNT_CLR_OFFSET));
}
#endif



#endif


#elif defined(MT6290)


/*****************************************************************************
 *						 SYMBOL Definition                                   *
 *****************************************************************************/


/*****************************************************************************
 *						 Global/External Variable                            *
 *****************************************************************************/
const kal_uint32 g_WATCHDOG_RESTART_REG   = REG_MDRSTCTL_WDTRR;
const kal_uint32 g_WATCHDOG_RESTART_VALUE = RSTCTL_WDTRR_KEY;
const kal_uint32 g_ABNORMAL_RST_REG       = REG_MDRSTCTL_WDTIR;
const kal_uint32 g_ABNORMAL_RST_VAL		  = WDT_RSTINTERVAL_VALUE;


/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/
//function declaration.



/*****************************************************************************
 *						 LISR/HISR/Callback Functions                        *
 *****************************************************************************/



/*****************************************************************************
 *						 Basic Driver Implementation						 *
 *****************************************************************************/

#define UT_DELAY_LOOP(n)                                                          \
do{                                                                               \
	volatile register kal_uint32 _delay_loop;                                     \
	for(_delay_loop = 0; _delay_loop < n; _delay_loop++) { ; }                    \
}while(0)

#define _RESET_ITEM_REGs(reg, item_r, waitLoopCnt)   do {    \
				DRV_WriteReg32(reg, 		   \
							 (item_r));\
				DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);\
				UT_DELAY_LOOP(waitLoopCnt);\
				DRV_WriteReg32(reg, 0);\
				DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);\
					} while(0)


void _rst_clrSwRstStatus(kal_uint32 reg, kal_uint32 statusMaskToClear)
{
	/* If status Mask == 0 -> clear ALL */
	statusMaskToClear = (statusMaskToClear)?statusMaskToClear:0xffffffff;
    DRV_WriteReg32(reg, statusMaskToClear);
}

void _rst_resetIP(kal_uint32 reg, kal_uint32 item_r, kal_uint32 waitLoopCnt)
{
	kal_uint32 rstStatus;
	kal_uint32 timeout_cnt=0;
	kal_uint32 sta_reg=0;

	/* Reset IP */
	_RESET_ITEM_REGs(reg, item_r,waitLoopCnt);

	/* Check the status and clear it */
	switch (reg)
	{
		case REG_MDRSTCTL_SRBER_MDON:
			sta_reg = (REG_MDRSTCTL_SRSTR_MDON);
			break;
		case REG_MDRSTCTL_SRBER_MDMCU:
			sta_reg = (REG_MDRSTCTL_SRSTR_MDMCU);
			break;
		case REG_MDRSTCTL_SRBER_MDINFRA:
			sta_reg = (REG_MDRSTCTL_SRSTR_MDINFRA);
			break;
		case REG_MDRSTCTL_SRBER_LTEL2:
			sta_reg = (REG_MDRSTCTL_SRSTR_LTEL2);
			break;
		case REG_MDRSTCTL_SRBER_MEMSYS:
			sta_reg = (REG_MDRSTCTL_SRSTR_MEMSYS);
			break;
		case REG_MDRSTCTL_SRBER_ARM7:
			sta_reg = (REG_MDRSTCTL_SRSTR_ARM7);
			break;
		case REG_MDRSTCTL_SRBER_APMCU:
			sta_reg = (REG_MDRSTCTL_SRSTR_APMCU);
			break;
		case REG_MDRSTCTL_SRBER_APPERI:
			sta_reg = (REG_MDRSTCTL_SRSTR_APPERI);
			break;
		case REG_MDRSTCTL_SRBER_SSUSB:
			sta_reg = (REG_MDRSTCTL_SRSTR_SSUSB);
			break;
		case REG_MDRSTCTL_SRBER_APON:
			sta_reg = (REG_MDRSTCTL_SRSTR_APON);
			break;
		default:
			break;
	}

	rstStatus = (DRV_Reg32(sta_reg)&item_r);


	while((item_r != rstStatus) && timeout_cnt<10000)
	{
		rstStatus = DRV_Reg32(sta_reg);
		timeout_cnt++;
	};

	ASSERT(timeout_cnt<10000);
	ASSERT(item_r == rstStatus);

	_rst_clrSwRstStatus(sta_reg, item_r);

}


void _rst_enableWdt(kal_uint32 wdtEnable, kal_uint32 wdtInterval)
{
	if (wdtEnable)
    {
	    /* Set watchdog interval */
		DRV_WriteReg32(REG_MDRSTCTL_WDTIR,
		               ((RSTCTL_WDTIR_KEY)|
		               ((wdtInterval & RSTCTL_WDTIR_INTERVAL_MASK) << RSTCTL_WDTIR_INTERVAL_OFFSET)));

        /* Enable/disable watchdog */
        DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))|RSTCTL_WDTCR_WDT_EN));
	    DRV_WriteReg32(REG_MDRSTCTL_WDTRR,((RSTCTL_WDTRR_KEY)|0x1));

	} else
    {   /* Just simply set WDTCR for WDT disabling operation */
        DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))&(~RSTCTL_WDTCR_WDT_EN)));
    }
}

void _rst_clrWdStatus(kal_uint32 statusMaskToClear)
{
	/* If status Mask == 0 -> clear ALL */
	statusMaskToClear = (statusMaskToClear)?statusMaskToClear:0xffffffff;
    DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|(statusMaskToClear & (RSTCTL_WDTSR_STATUS_MASK<<RSTCTL_WDTSR_STATUS_OFFSET)));
}

/**
*	@brief	Reset WDT related setting and variables
*/
static void _wdt_reinitWDT(void)
{
	_rst_enableWdt(0,	RSTCTL_WDTIR_INTERVAL_MASK); /* Disable WDT */	/* Let duration being maximum */

	_rst_clrWdStatus(0);				/* Clear ALL indication bits */
}

void _rst_setWdTarget(kal_uint32 targetMask)
{
//	switch (targetMask)
//	{
//		case RST_SDCTL:
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, DRV_Reg32(REG_MDRSTCTL_WDTER_MDON)|(1<<0));
//			break;
//		default:
//			break:
//	}
}
/**
 *	@brief	Procedure for software triggered reset process
 *	This procedure triggers software watchdog reset and wait for its completeness
 *    Note: It needs less than 1T(32k) (eaxtly 1T-2*bus clock period) to do reset after WDTSR changes
 */
void _rst_swWdReset(void)
{
	/* Always clear indication bits before reset */
	DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|(RSTCTL_WDTSR_STATUS_MASK<<RSTCTL_WDTSR_STATUS_OFFSET));

    //set MDTER bit
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81FFFEFF);    //before 0816  0xBFFFFFFF
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);  //before 0816 0x8000003F
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);   //before 0816 0x800000FF
    //set APTER bit
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, DRV_Reg32(REG_MDRSTCTL_WDTER_APON)|0x003FFBFC);     //before 0816 0x8000000F
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000001);
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFFF);  //for RSTCTL ver70 remove aptzctl
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);

	/* Trigger watchdog reset immediately : We use software reset */
	DRV_WriteReg32(REG_MDRSTCTL_SRCMR_SWDT, RSTCTL_SRCMR_KEY_SWDT);
	DRV_Reg32(REG_MDRSTCTL_SRCMR_SWDT);	/* Read the value of RSTCTL_SRCMR back to make sure the previous write operation is done */
	while ((DRV_Reg32(REG_MDRSTCTL_WDTSR) & (RSTCTL_WDTSR_STATUS_MASK<<RSTCTL_WDTSR_STATUS_OFFSET)) == 0);

    /*If irq_en not set, just while(1) to wait reset happen */
    if(!(DRV_Reg32(REG_MDRSTCTL_WDTCR) & RSTCTL_WDTCR_WDT_IRQEN))
        while(1);
}

void _rst_restartWDT()
{
	/* Simply reload watchdog counter */
	DRV_WriteReg32(REG_MDRSTCTL_WDTRR, (RSTCTL_WDTRR_KEY|0x1));
}

void drv_rstctl_sw_wd_reset(kal_uint32 wdTarget)
{
	/* Disable WD and clear indicators*/
	_wdt_reinitWDT();

	/**< Step 2 : configure WDT register to start counting */
	_rst_setWdTarget(wdTarget);
	_rst_enableWdt(1, WDT_RSTINTERVAL_VALUE); /* Maximum interval to watchdog timeout */
	_rst_restartWDT();	/* Kick watchdog to prevent from timeout */
	_rst_swWdReset();	/* To trigger software watchdog reset */

	/* Disable WD and clear indicators*/
	_wdt_reinitWDT();
}

void drv_rstctl_wd_reset(wdt_irq_e irq_en, rst_target_e wdTarget, kal_uint32 wdtInterval)
{

	/* Disable WD and clear indicators*/
	//_wdt_reinitWDT();
	_rst_clrWdStatus(0);
    DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|0x1F);

	/**< Step 2 : configure WDT register to start counting */
	if (wdTarget == RST_MDALL)
	{
		//set MDTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81FFFEFF);  	//before 0816  0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);  	//before 0816 0x800000FF
		//set APTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, DRV_Reg32(REG_MDRSTCTL_WDTER_APON)|0x003FFBFC);		//before 0816 0x8000000F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000001);
			DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFFF);	//for RSTCTL ver70 remove aptzctl
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);
	}
	if (wdTarget == RST_MDALL_WO_USB)
	{
		//set MDTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81FFFEFF);  	//before 0816  0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);  	//before 0816 0x800000FF
		//set APTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, 0xC3FFBF4);		//before 0816 0x8000000F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFDF);	//for RSTCTL ver70 remove aptzctl
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);
	}
	else if (wdTarget == RST_APALL)
	{
		//set MDTER bit
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81FFFEFF); 		//before 0816 0xBFFFFFFF
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);		//before 0816 0x800000FF

		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81FFFEFF); 		//before 0816 0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x8000000F);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800000DF);		//before 0816 0x800000FF


		//set APTER bit
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, DRV_Reg32(REG_MDRSTCTL_WDTER_APON)|0x003FFBFC);		//before 0816 0x8000000F
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000001);
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFFF);	//for RSTCTL ver70 remove aptzctl
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);

		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, 0x0C3FFFFC); 	//before 0816 0x8000000F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800FFFFF);	//for RSTCTL ver70 remove aptzctl
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);


	}
	else
	{
		_rst_setWdTarget(wdTarget);
	}

    if (irq_en == WDT_IRQ_ONLY)
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY)|(0x8));
	else
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY)|(DRV_Reg32(REG_MDRSTCTL_WDTCR)&0x8001));

	if (0 != wdtInterval)
	{
		_rst_enableWdt(1, wdtInterval); /* Maximum interval to watchdog timeout */
		//_rst_restartWDT();	/* Kick watchdog to prevent from timeout */ //already done in _rst_enableWdt
	}
	else
	{
		_rst_swWdReset();	/* To trigger software watchdog reset */
	}

	/* Disable WD and clear indicators*/
	//_wdt_reinitWDT();
}

void drv_rstctl_wd_rst_set_bitmap(kal_uint8 type)
{
	//if (cp15_get_cpu_id() == CPU_CORTEX_R4_ID)
	if (type == 0) //U3
	{
		//set MDTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81BFFEFF);		//before 0816 0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);		//before 0816 0x800000FF

		//set APTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000000);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, 0xC3FFBF4); 	//don't reset APCLK
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFFF);	//for RSTCTL ver70 remove aptzctl include USB
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);
	}
	else if (type == 1) //U2
    {
		//set MDTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81BFFEFF);		//before 0816 0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);		//before 0816 0x800000FF

		//set APTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, 0xC3FFBF4);     //don't reset APCLK
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFDF);	//for RSTCTL ver70 remove aptzctl
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);
	}
	else
	{
    }
}


void drv_rstctl_sw_reset(rst_target_e targetIP)
{
	kal_uint32 timeout_cnt=0;  //for RST_MEMORY only

	switch (targetIP)
	{
		/* Only valid for MDARM */
		case RST_SDCTL:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_SDCTL_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDGDMA:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDGDMA_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_USIM0:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_USIM0_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_USIM1:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_USIM1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDUART:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDUART_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SUART0:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_SUART0_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SUART1:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_SUART1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDGPTM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDGPTM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDMISC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDMISC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDCIRQ:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDCIRQ_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_LED:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_LED_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_I2C:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_I2C_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SDCTL_CIS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_SDCTL_CIS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DBGSYS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_DBGSYS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DBGCV:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_DBGCV_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DBGSIB:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_DBGSIB_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_GPIOMUX:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_GPIOMUX_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APTOPSM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_APTOPSM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDTOPSM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDTOPSM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APOST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_APOST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDOST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDOST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDCFGCTL:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDCFGCTL_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DRAMC_AO:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_DRAMC_AO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_EMI_AO:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_EMI_AO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7_HRST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_SRBER_ARM7_HRST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7_SRST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_SRBER_ARM7_SRST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CAIF:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_SRBER_CAIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7SYS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_SRBER_ARM7SYS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_L2COP:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_LTEL2, RSTCTL_SRBER_LTEL2_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MEMSYS:
			{
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MEMSYS, (RSTCTL_SRBER_DRAMC_RST|RSTCTL_SRBER_EMI_RST|RSTCTL_SRBER_CPHY_RST|RSTCTL_SRBER_DDRPHY_COMB0_RST));
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, (RSTCTL_SRBER_DRAMC_AO_RST|RSTCTL_SRBER_EMI_AO_RST));
			DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);
			UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MEMSYS, 0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0);
			DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);

			while((((RSTCTL_SRBER_DRAMC_RST|RSTCTL_SRBER_EMI_RST|RSTCTL_SRBER_CPHY_RST|RSTCTL_SRBER_DDRPHY_COMB0_RST) != DRV_Reg32(REG_MDRSTCTL_SRSTR_MEMSYS))||\
			        ((RSTCTL_SRBER_DRAMC_AO_RST|RSTCTL_SRBER_EMI_AO_RST) != DRV_Reg32(REG_MDRSTCTL_SRSTR_MDON))) && timeout_cnt<10000)
			{
				timeout_cnt++;
			};

			ASSERT(((RSTCTL_SRBER_DRAMC_RST|RSTCTL_SRBER_EMI_RST|RSTCTL_SRBER_CPHY_RST|RSTCTL_SRBER_DDRPHY_COMB0_RST) == DRV_Reg32(REG_MDRSTCTL_SRSTR_MEMSYS))&&\
			        ((RSTCTL_SRBER_DRAMC_AO_RST|RSTCTL_SRBER_EMI_AO_RST) == DRV_Reg32(REG_MDRSTCTL_SRSTR_MDON)));

			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MEMSYS, (RSTCTL_SRBER_DRAMC_RST|RSTCTL_SRBER_EMI_RST|RSTCTL_SRBER_CPHY_RST|RSTCTL_SRBER_DDRPHY_COMB0_RST));
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDON, (RSTCTL_SRBER_DRAMC_AO_RST|RSTCTL_SRBER_EMI_AO_RST));

/*
			_rst_resetIP(REG_MDRSTCTL_SRBER_MEMSYS, (RSTCTL_SRBER_DRAMC_RST|RSTCTL_SRBER_EMI_RST|RSTCTL_SRBER_CPHY_RST|\
			  RSTCTL_SRBER_DDRPHY_COMB0_RST), _RST_DURATION_LOOP_DEFAULT_VALUE);
			_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, (RSTCTL_SRBER_DRAMC_AO_RST|RSTCTL_SRBER_EMI_AO_RST), _RST_DURATION_LOOP_DEFAULT_VALUE);
*/
			  break;}
		case RST_MDINFRA_MISC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_SRBER_MDINFRA_MISC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDINFRA_BUSMON:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_SRBER_MDINFRA_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ABM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_SRBER_ABM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CR4:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_CR4_DBG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CR4_NRESET:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_CR4_NRESET_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CR4_BUSMON:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_CR4_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ALC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_ALC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PF:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_PF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PCMON_FIFO:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_PCMON_FIFO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PCMON_REG:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_PCMON_REG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_AP_RSTMD:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AP_RSTMD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDCLK:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MDCLK_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APCLK:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_APCLK_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_EFUSE:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_EFUSE_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, (RSTCTL_SRBER_MML1_RST|RSTCTL_SRBER_MML1OFF_RST), _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1OFF:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MML1OFF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_TDD:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_TDD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_2G3G:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_2G3G_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_2G3G_DSP:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_2G3G_DSP_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_EXT_RST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_EXT_RST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_BSICTL:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_BSICTL, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_RFIC1_BSISPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_RFIC1_BSISPI, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_RFIC2_BSISPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_RFIC2_BSISPI, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PMIC_BSISPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_PMIC_BSISPI, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MIPI0_BSISPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MIPI0_BSISPI, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MIPI1_BSISPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MIPI1_BSISPI, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_IDC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_IDC, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1_BPICTRL:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MML1_BPICTRL, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1_PERISYS_MISC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MML1_PERISYS_MISC, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1_PERI_MBIST_CONFIG:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MML1_PERI_MBIST_CONFIG, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_AUXADC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AUXADC, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1_PERISYS_XRESET:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MML1_PERISYS_XRESET, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MIXEDSYS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MIXEDSYS, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SSUSB:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_SSUSB, RSTCTL_SRBER_SSUSB_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APUART:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_APUART_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APCCIF:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_APCCIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CLDMA:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_CLDMA_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_NFI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_NFI_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_SF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_USB:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_USB_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_IPSEC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_IPSEC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_HIF0:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_HIF0_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PFC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_PFC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_NLI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_NLI_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MSDC0P:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_MSDC0P_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MSDC1P:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_MSDC1P_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APGPTM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_APGPTM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APGDMA:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_APGDMA_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APINFRA_BUSMON:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_AP_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_AP_MISC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_AP_MISC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ETHER_NIC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_ETHER_NIC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_TRACE:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_TRACE_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CA7_DBG:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APMCU, RSTCTL_SRBER_CA7_DBG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CA7_NRESET:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APMCU, RSTCTL_SRBER_CA7_NRESET_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CA7_BUSMON:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APMCU, RSTCTL_SRBER_CA7_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDALL:
			//set MDTER bit
//			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0x003DF69F); //don't reset LED/GPIO/SUART0/SUART1 when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0x0029F69F); //don't reset LED/GPIO/SUART0/SUART1/APTOPSM/APOST when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_ARM7, 0x00000007);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_LTEL2, 0x00000001);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDINFRA, 0x0000000B);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDMCU, 0x000000DF);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_SSUSB, 0x00000001);  //reset U3 when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APPERI, 0x00080130);  //reset trace,PFC,U2 and SPI when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APON, 0x000003E0);  //reset LTEPHY,TDD,2G3G,2G3GDSP when AP reset MD
			_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AP_RSTMD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_ARM7, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_LTEL2, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDINFRA, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDMCU, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_SSUSB, 0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APPERI, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APON, 0x0);
			_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AP_RSTMD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDON, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_ARM7, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_LTEL2, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDINFRA, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDMCU, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_SSUSB, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_APPERI, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_APON, 0);
			break;
		case RST_MDALL_WO_SPI:
			//set MDTER bit
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0x0029F69F);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_ARM7, 0x00000007);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_LTEL2, 0x00000001);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDINFRA, 0x0000000B);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDMCU, 0x000000DF);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_SSUSB, 0x00000001);  //reset U3 when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APPERI, 0x00080120);  //reset trace,PFC and U2 when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APON, 0x000003E0);  //reset LTEPHY,TDD,2G3G,2G3GDSP when AP reset MD
			_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AP_RSTMD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_ARM7, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_LTEL2, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDINFRA, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDMCU, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_SSUSB, 0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APPERI, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APON, 0x0);
			_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AP_RSTMD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDON, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_ARM7, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_LTEL2, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDINFRA, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDMCU, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_SSUSB, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_APPERI, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_APON, 0);
            break;
		default:
			ASSERT(0);
	}
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_getSta
*
* DESCRIPTION
*  This function is used to get wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*  bit[15:12]:AP WDT CNT : AP wd reset increase one. can be reset by disable WDT
*  bit[11:8]:MD WDT CNT : MD wd reset increase one. can be reset by disable WDT
*  bit[4]:AP reset MD indicator
*  bit[3]:AP sw WD reset indicator
*  bit[2]:AP hw WD reset indicator
*  bit[1]:MD sw WD reset indicator
*  bit[0]:MD hw WD reset indicator
*************************************************************************/
void drv_rstctl_wd_disable(void)
{
	_rst_enableWdt(0,	RSTCTL_WDTIR_INTERVAL_MASK);
}

kal_uint32 drv_rstctl_wd_getSta(void)
{
	kal_uint32 wdt_sta;
	wdt_sta = DRV_Reg32(REG_MDRSTCTL_WDTSR);
	//_rst_clrWdStatus(0);
	return wdt_sta;
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrCnt(kal_uint32 cntMaskToClear)
{
	/* If cnt Mask == 0 -> clear ALL */
	cntMaskToClear = (cntMaskToClear)?cntMaskToClear:0x3;
    DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|((cntMaskToClear & RSTCTL_WDTSR_CNT_CLR_MASK)<<RSTCTL_WDTSR_CNT_CLR_OFFSET));
}


/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to clear wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrSta(void)
{
	_rst_clrWdStatus(0);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_extrst_setCfg
*
* DESCRIPTION
*  This function is used to config EXT_RST
*
* PARAMETERS
*	rstctl_ext_cfg_t ext_cfg
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_extrst_setCfg(rstctl_ext_cfg_t ext_cfg)
{
	DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, (DRV_Reg32(REG_MDRSTCTL_WDTER_APON) & 0xFFFFFBFF)|(ext_cfg.EXT_RST_EA <<10)); //enable/disable EXT_RST
	DRV_WriteReg32(REG_MDRSTCTL_EXTRST, (DRV_Reg32(REG_MDRSTCTL_EXTRST)|RSTCTL_EXTRST_KEY)); 								//clear status
	DRV_WriteReg32(REG_MDRSTCTL_EXTRST, ((DRV_Reg32(REG_MDRSTCTL_EXTRST) & 0xFFFFFFFC)|RSTCTL_EXTRST_KEY|(ext_cfg.MD_POL << 0)|(ext_cfg.PAD_OUT_EA << 1)));	//set POL and OE
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_extrst_getSta
*
* DESCRIPTION
*  This function is used to get EXT_RST status
*
* PARAMETERS
*	1: ext rst assert
*	0: ext rst de-assert
* RETURN VALUES
*	none
*************************************************************************/
kal_bool drv_rstctl_extrst_getSta(void)
{
	if (DRV_Reg32(REG_MDRSTCTL_EXTRST) & (1<<15))
	{
		DRV_WriteReg32(REG_MDRSTCTL_EXTRST, (DRV_Reg32(REG_MDRSTCTL_EXTRST)|RSTCTL_EXTRST_KEY));		//clear status
		return KAL_TRUE;
	}
	else
	{
		DRV_WriteReg32(REG_MDRSTCTL_EXTRST, (DRV_Reg32(REG_MDRSTCTL_EXTRST)|RSTCTL_EXTRST_KEY));		//clear status
		return KAL_FALSE;
	}
}


kal_uint16 drv_rstctl_wd_getInterval(void)
{
	return (kal_uint16)(0xFFFF & DRV_Reg32(REG_MDRSTCTL_WDTIR));
}

void drv_rstctl_restartWDT(void)
{
	_rst_restartWDT();
}

void drv_rstctl_wdt_setInterval(kal_uint32 wdtInterval)
{
	/* Set watchdog interval */
	DRV_WriteReg32(REG_MDRSTCTL_WDTIR,
				   ((RSTCTL_WDTIR_KEY)|
				   ((wdtInterval & RSTCTL_WDTIR_INTERVAL_MASK) << RSTCTL_WDTIR_INTERVAL_OFFSET)));
}

void drv_rstctl_wdt_enable(kal_bool en)
{
	if (en == KAL_TRUE)
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))|RSTCTL_WDTCR_WDT_EN));
		/*Reload wdt interval*/
		DRV_WriteReg32(REG_MDRSTCTL_WDTRR,((RSTCTL_WDTRR_KEY)|0x1));
	}
	else
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))&(~RSTCTL_WDTCR_WDT_EN)));
	}
}

void drv_rstctl_wdt_abnReset(void)
{
	SaveAndSetIRQMask();
	drv_rstctl_wdt_setInterval(1);
	_rst_restartWDT();
	drv_rstctl_wdt_enable(KAL_TRUE);
	while(1);
}

void drv_rstctl_wdt_enableInterrupt(kal_bool enable)
{
	if (enable == KAL_TRUE)
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR,(RSTCTL_WDTCR_KEY)|((DRV_Reg32(REG_MDRSTCTL_WDTCR)) | RSTCTL_WDTCR_WDT_IRQEN));
	}
	else
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR,(RSTCTL_WDTCR_KEY)|((DRV_Reg32(REG_MDRSTCTL_WDTCR)) & (~RSTCTL_WDTCR_WDT_IRQEN)));
	}
}


void drv_rstctl_wdt_enableDebugMode(kal_bool enable)
{
	if (enable==KAL_TRUE)
	{
		IRQUnmask(IRQ_MD_WDT_CODE);
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) | ((DRV_Reg32(REG_MDRSTCTL_WDTCR))| (RSTCTL_WDTCR_WDT_EN | RSTCTL_WDTCR_WDT_IRQEN)));
	}
	else
	{
		IRQMask(IRQ_MD_WDT_CODE);
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) | ((DRV_Reg32(REG_MDRSTCTL_WDTCR)) & ~(RSTCTL_WDTCR_WDT_EN | RSTCTL_WDTCR_WDT_IRQEN)));
	}
}

/*
* FUNCTION
*	drv_rstctl_WdtConfig
*
* DESCRIPTION
*   	This function is to configure WDT only called in drv_rstctl_wdt_init
*
* CALLS
*
* PARAMETERS
*	extpol: KAL_TRUE, polarity = 1
*	        FASLE, polarity = 0
*	exten: KAL_TRUE, generate an external watchdog reset signal when couter=0
*	    KAL_FALSE, not generate an external watchdog reset signal when couter=0
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void drv_rstctl_WdtConfig(IO_level extpol, kal_bool exten)
{
    //	kal_uint32 tmp = DRV_Reg32(REG_MDRSTCTL_WDTCR);
    //	tmp |= (RSTCTL_WDTCR_KEY);
    //	tmp &= ~RSTCTL_WDTCR_WDT_EN;
    //	DRV_WriteReg32(REG_MDRSTCTL_WDTCR, tmp);

    /*
        MD WDTER APON[10] is the mux to choose this ext_rst pin controlled by AP setting (0) or MD setting (1)
        And It also controll the reset signal generating or not
      */
    if (exten == KAL_TRUE)
    {
        DRV_WriteReg32(REG_MDRSTCTL_EXTRST, RSTCTL_EXTRST_KEY|EXT_WDT_STS|EXTRST_OE|(extpol << POLARITY_OFFSET));
        DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, DRV_Reg32(REG_MDRSTCTL_WDTER_APON) | (1<<10));
    }
    else
    {
        DRV_WriteReg32(REG_MDRSTCTL_EXTRST, RSTCTL_EXTRST_KEY|EXT_WDT_STS);
        DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, DRV_Reg32(REG_MDRSTCTL_WDTER_APON) & ~(1<<10));
    }
}

/*
* FUNCTION
*	drv_rstctl_ext_rst_pin_init
*
* DESCRIPTION
*   	This function is to set ext_rst pin status
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*    None
*
* NOTE
*   In MT6290 phone type product, default is input pin and pull low
*   Because this pin also affects the sdio_int_pin and  it would always trigger sdio interrupt if in default state
*   so we need to set it as default high and low active
*/
void drv_rstctl_ext_rst_pin_init(void)
{
    drv_rstctl_WdtConfig(io_low, KAL_TRUE);
}

/*
* FUNCTION
*	drv_rstctl_wdt_init
*
* DESCRIPTION
*   	This function is to initialize the WDT module
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   None
*/
void drv_rstctl_wdt_init(void)
{
	//WDT_RST = (DRV_WDT_Reg(WDT_STATUS) & WDT_STATUS_BITMASK)?(KAL_TRUE):(KAL_FALSE);
#if !defined(ATEST_ENABLE)
	drv_rstctl_wd_clrSta();
#endif
	drv_rstctl_wdt_setInterval(WDT_RSTINTERVAL_VALUE);
	drv_rstctl_ext_rst_pin_init();

#if defined(DRV_WDT_IRQ_MODE)
	drv_rstctl_wdt_enableInterrupt(KAL_TRUE);
	//IRQSensitivity(IRQ_MD_WDT_CODE, KAL_TRUE);
	//IRQUnmask(IRQ_MD_WDT_CODE);
#endif
}

/*
* FUNCTION
*	WDT_init
*
* DESCRIPTION
*   	This function is to initialize the WDT module
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   None
*/
void WDT_init(void)
{
	drv_rstctl_wdt_init();
}

kal_uint32 Get_WATCHDOG_BASE()
{
	return REG_MDRSTCTL_WDTRR;
}
kal_uint32 Get_WATCHDOG_RESTART_CMD()
{
	return (RSTCTL_WDTRR_KEY | 0x1);
}

kal_bool Is_WDT_Init()// for ex_item.c
{
	if( DRV_Reg32(REG_MDRSTCTL_WDTIR) == WDT_RSTINTERVAL_VALUE )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}



void drv_rstctl_wdt_reset(void)
{
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
	kal_uint16 powerkey_status;

	#if defined(__USB_ENABLE__)

	DCL_BOOL dcl_data = DCL_TRUE;
	DCL_HANDLE	usb_dcl_handle;

	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);

	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_PDN_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_DRV_Close(usb_dcl_handle);

	//	 USB_PDNmode(KAl_TRUE);

	#endif //#if defined(__USB_ENABLE__)

	#ifdef PMIC_PRESENT

	if (BMT.PWRon != CHRPWRON)
	{
		switch(Pwrkey_Position)
		{
			case low_key:
				powerkey_status= DRV_Reg32(KP_LOW_KEY);
				break;
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
			case high_key:
				powerkey_status= DRV_Reg32(KP_HI_KEY);
				break;
			default:
				ASSERT(0);
				break;
		}
		if(WdtPowerKey_Pressed())
		{
			TargetReset = 1;
		}
		else
		{
			/*lint -e(534)*/SaveAndSetIRQMask();

			drv_rstctl_wdt_setInterval(1);
			_rst_restartWDT();
			drv_rstctl_wdt_enable(KAL_TRUE);
			while(1);
		}
	}
	else
	{
		/*lint -e(534)*/SaveAndSetIRQMask();

		drv_rstctl_wdt_setInterval(1);
		_rst_restartWDT();
		drv_rstctl_wdt_enable(KAL_TRUE);
		while(1);
	}
	#else /*PMIC_PRESENT*/
		  /*lint -e(534)*/SaveAndSetIRQMask();

		drv_rstctl_wdt_setInterval(1);
		_rst_restartWDT();
		drv_rstctl_wdt_enable(KAL_TRUE);
		while(1);
	#endif   /*PMIC_PRESENT*/
#else /*!DRV_WDT_RESET_PKEY_RELEASE*/

	kal_uint16 index;
#if defined(DRV_RTC_REG_COMM)
	DCL_HANDLE rtc_handler;
	RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data8;
#endif /*DRV_RTC_REG_COMM*/
	/*lint -e(534)*/SaveAndSetIRQMask();

	for(index=0;index<1000;index++);
#if defined(DRV_RTC_REG_COMM)
	//RTC_Set_PDN_bits(rtc_pdn2 ,DRV_COMM_REG2_NORMAL_RESET);
	rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
	rtc_cmd_data8.PDNIndex = DCL_RTC_PDN2;
	rtc_cmd_data8.fgConfigBit = DRV_COMM_REG2_NORMAL_RESET;
	DclRTC_Control(rtc_handler, RTC_CMD_SET_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data8); // New API with CMD & DATA
#endif   /*DRV_RTC_REG_COMM*/
	#if !defined(DRV_WDT_SWRST)
	drv_rstctl_wdt_setInterval(1);
	_rst_restartWDT();
	drv_rstctl_wdt_enable(KAL_TRUE);
	while(1);
	#else
		#if defined(DRV_MISC_WDT_TURN_OFF_PLL)
	DRV_WriteReg32(0x80000108, 0);
		#endif // #if defined(DRV_MISC_WDT_TURN_OFF_PLL)
	_rst_swWdReset();	/* To trigger software watchdog reset */
	while(1);
	#endif
#endif   /*!DRV_WDT_RESET_PKEY_RELEASE*/

}

#elif defined(MT6595)

#define RST_USE_US_DELAY
#include "kal_debug.h"

/*****************************************************************************
 *						 SYMBOL Definition                                   *
 *****************************************************************************/

/*32K 1T=30.5us*/
#ifdef RST_USE_US_DELAY
#include "us_timer.h"
#define RSTCTL_DURATION_LOOP_DEFAULT_VALUE (31)
#define MY_UST_GET_DUR(prev, cur) (((cur) >= (prev))? (((cur) - (prev))): ((USCNT_WRAP - (prev) + (cur))))
#define UT_DELAY_LOOP(us)   \
        do {    \
            kal_uint32 t1, t2;         \
            if ((us) == 0) {    \
                break;  \
            }   \
            t1 = ust_get_current_time();    \
            do {    \
                t2 = ust_get_current_time();    \
                if (MY_UST_GET_DUR(t1, t2) >= (us)) { break; } \
            	else { continue; }   \
            } while (1);    \
        } while (0)
#else
#define RSTCTL_DURATION_LOOP_DEFAULT_VALUE (0x100)
#define UT_DELAY_LOOP(n)                                                          \
do{                                                                               \
	volatile register kal_uint32 _delay_loop;                                     \
	for(_delay_loop = 0; _delay_loop < n; _delay_loop++) { ; }                    \
}while(0)
#endif

#define TOP_RGU_MODE_ADDR   (TOPRGU_BASE+0x0)
#define TOP_RGU_SW_WDT_ADDR (TOPRGU_BASE+0x14)
#define TOP_RGU_RETAIN_ADDR (TOPRGU_BASE+0x20)

/*****************************************************************************
 *						 Global/External Variable                            *
 *****************************************************************************/
const kal_uint32 g_WATCHDOG_RESTART_REG   = REG_WDT_MD_RESTART;
const kal_uint32 g_WATCHDOG_RESTART_VALUE = RSTCTL_RESTART_TIMER_KEY;
const kal_uint32 g_ABNORMAL_RST_REG       = REG_WDT_MD_LENGTH;
const kal_uint32 g_ABNORMAL_RST_VAL		  = WDT_RSTINTERVAL_VALUE;


/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/




/*****************************************************************************
 *						 LISR/HISR/Callback Functions                        *
 *****************************************************************************/



/*****************************************************************************
 *						 Basic Driver Implementation						 *
 *****************************************************************************/

/**
 *	@brief	Procedure for software triggered reset process
 *	This procedure triggers software watchdog reset and wait for its completeness
 */
static void _rst_swWdReset(void)
{
	drv_rstctl_sw_reset(RST_MD_SWRST);

	UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/

    /*If irq_en not set, just while(1) to wait reset happen */
    if(!(DRV_Reg32(REG_WDT_MD_MODE) & (0x1 <<RSTCTL_IRQ_MODE_BIT)))
        while(1);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_ws_wdReset
*
* DESCRIPTION
*  This function is used to control top rgu to make whole system reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_ws_wdReset(void)
{
    DRV_WriteReg32(TOP_RGU_MODE_ADDR, 0x22000000);
    DRV_WriteReg32(TOP_RGU_SW_WDT_ADDR, 0x1209);
    while(1);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_top_retn_data
*
* DESCRIPTION
*  This function is used to read/write retention data
*
* PARAMETERS
*	bRead: 1: read data
*           0: write data
*    pData:
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_top_retn_data(kal_bool bRead, kal_uint32 *pData)
{
    if(pData == NULL)
        return;

    if(bRead == KAL_TRUE)
    {
        *pData =  DRV_Reg32(TOP_RGU_RETAIN_ADDR);
    }
    else
    {
        DRV_WriteReg32(TOP_RGU_RETAIN_ADDR, *pData);
    }

}

/*************************************************************************
* FUNCTION
*  drv_rstctl_A7_unlock
*
* DESCRIPTION
*  This function is used to unlock ARM7 hrst
*
* PARAMETERS
*	lock:   RST_A7_LOCK:
*            RST_A7_UNLOCK:
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_A7_unlock(rst_a7_lock_e lock)
{
    kal_uint32 regVal;

#ifdef SW_RST_READ_STATUS_SHITF_8
    regVal = (DRV_Reg32(REG_WDT_SW_GRP0_RST) >> 8);
#else
    regVal = DRV_Reg32(REG_WDT_SW_GRP0_RST);
#endif
    if(lock == RST_A7_UNLOCK)
        regVal = regVal | (0x1 << RSTCTL_A7_RSTUNLOCK_BIT) ;
    else
        regVal = regVal & ~(0x1 << RSTCTL_A7_RSTUNLOCK_BIT);

    DRV_WriteReg32(REG_WDT_SW_GRP0_RST,(RSTCTL_GRP0_RST_KEY | regVal));
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_sw_reset
*
* DESCRIPTION
*  This function is used to do SW ARM7 reset
*
* PARAMETERS
*	assert: 1: set reset assert
*            0: set reset de-assert
*    targetIP: only support RST_A7_CCIF/RST_A7_SRST/RST_A7_HRST/RST_A7_SYS
*
* RETURN VALUES
*	none
*
* NOTE: Please set assert at least one 32K cycle
*************************************************************************/
void drv_rstctl_sw_A7_reset(rst_a7_asrt_e asrt, rst_target_e targetIP)
{
    kal_uint32 rstVal;
    kal_uint32 regVal;

#ifdef SW_RST_READ_STATUS_SHITF_8
    regVal = (DRV_Reg32(REG_WDT_SW_GRP0_RST) >> 8);
#else
    regVal = DRV_Reg32(REG_WDT_SW_GRP0_RST);
#endif

    switch(targetIP)
    {
        case RST_CAIF:
            rstVal = 0x1 << RSTCTL_A7_CCIF_BIT;
            break;
        case RST_ARM7_SRST:
            rstVal = 0x1 << RSTCTL_A7_SRST_BIT;
            break;
        case RST_ARM7_HRST:
            rstVal = (0x1 << RSTCTL_A7_HRST_BIT);
            break;
        case RST_ARM7SYS:
            rstVal = (0x1 << RSTCTL_A7_HRST_BIT) | \
                     (0x1 << RSTCTL_A7_SRST_BIT) | (0x1 << RSTCTL_A7_CCIF_BIT);
            break;
        default:
            //dbg_print("targetIP=%d, Not ARM7!!", targetIP);
            return;
    }

    if(asrt == RST_A7_ASSERT)
        regVal = regVal | rstVal;
    else
        regVal = regVal & ~(rstVal);

    DRV_WriteReg32(REG_WDT_SW_GRP0_RST,(RSTCTL_GRP0_RST_KEY | regVal));
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_sw_reset
*
* DESCRIPTION
*  This function is used to do SW reset
*
* PARAMETERS
*	targetIP: sw module defined in RGU
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_sw_reset(rst_target_e targetIP)
{
    kal_uint32 regAddr;
    kal_uint32 rstKey;
    kal_uint32 rstBit;
    kal_uint32 regVal;
    kal_uint8 bA7Rst = 0;

    if(targetIP == RST_MD_SWRST || targetIP == RST_MDALL)
    {
        DRV_WriteReg32(REG_WDT_MD_SWRST, RSTCTL_MDSYS_SWRST_KEY);
        return;
    }

    switch(targetIP)
    {
        case RST_2GDSP:
            regAddr = REG_WDT_SW_DSP_RSTN;
            rstKey = RSTCTL_DSP_RST_KEY;
            rstBit = RSTCTL_2GDSP_BIT;
            break;
        case RST_CLDMA:
            regAddr = REG_WDT_SW_GRP0_RST;
            rstKey = RSTCTL_GRP0_RST_KEY;
            rstBit = RSTCTL_CLDMA_BIT;
            break;
        case RST_PCMON_REG:
            regAddr = REG_WDT_SW_GRP0_RST;
            rstKey = RSTCTL_GRP0_RST_KEY;
            rstBit = RSTCTL_PCMON_REG_BIT;
            break;
        case RST_PCMON_FIFO:
            regAddr = REG_WDT_SW_GRP0_RST;
            rstKey = RSTCTL_GRP0_RST_KEY;
            rstBit = RSTCTL_PCMON_FIFO_BIT;
            break;
        case RST_L2COP:
            regAddr = REG_WDT_SW_GRP0_RST;
            rstKey = RSTCTL_GRP0_RST_KEY;
            rstBit = RSTCTL_LTEL2_BIT;
            break;
        case RST_CAIF:
        case RST_ARM7_SRST:
        case RST_ARM7_HRST:
        case RST_ARM7SYS:
            regAddr = REG_WDT_SW_GRP0_RST;
            rstKey = RSTCTL_GRP0_RST_KEY;
            bA7Rst = 1;
            break;
        case RST_MML1STS:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MML1STS_BIT;
            break;
        case RST_MML1_PERISYS_XRESET:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_XRESET_BIT;
            break;
        case RST_MML1_PERI_MBIST_CONFIG:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MML1_PERI_MBIST_BIT;
            break;
        case RST_MML1_PERISYS_MISC:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MML1_PERI_MISC_BIT;
            break;
        case RST_MML1_BPICTRL:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MML1_BPICTRL_BIT;
            break;
        case RST_IDC:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_IDC_BIT;
            break;
        case RST_MIPI1_BSISPI:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MIPI1_BSISPI_BIT;
            break;
        case RST_MIPI0_BSISPI:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MIPI0_BSISPI_BIT;
            break;
        case RST_PMIC_BSISPI:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_PMIC_BSISPI_BIT;
            break;
        case RST_RFIC2_BSISPI:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_RFIC2_BSISPI_BIT;
            break;
        case RST_RFIC1_BSISPI:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_RFIC1_BSISPI_BIT;
            break;
        case RST_PF_BSICTRL:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_PF_BSICTRL_BIT;
            break;
        default:
            //dbg_print("targetIP=%d, Out of range!!", targetIP);
            return;
    }
#ifdef SW_RST_READ_STATUS_SHITF_8
    if(regAddr == RSTCTL_GRP1_RST_KEY || regAddr == RSTCTL_GRP0_RST_KEY)
    {
        regVal = (DRV_Reg32(regAddr) >> 8);
    }
    else
    {
        regVal = DRV_Reg32(regAddr);
    }
#else
    regVal = DRV_Reg32(regAddr);
#endif

    if(bA7Rst)
        drv_rstctl_sw_A7_reset(RST_A7_ASSERT, targetIP);
    else
        DRV_WriteReg32(regAddr, (rstKey | (regVal | (0x1 << rstBit))));

    UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/

    if(bA7Rst)
        drv_rstctl_sw_A7_reset(RST_A7_DEASSERT, targetIP);
    else
        DRV_WriteReg32(regAddr, rstKey | (regVal & ~(0x1 << rstBit)));

}


/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_reset
*
* DESCRIPTION
*  This function is used to config wd timer and start
*
* PARAMETERS
*    irq_en: wd reset issued irq istead of reset
*    wdtInterval: watchdog timerout period, unit as 512*T32K=15.6ms
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_reset(wdt_irq_e irq_en, rst_target_e wdTarget, kal_uint32 wdtInterval)
{
    /*1. disable wdt*/
    DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE) & ~(0x1 << RSTCTL_WDT_EN_BIT)) );

    /*2. config timer period*/
    if(wdtInterval > RSTCTL_MAX_PERIOD_NUM)
    {
        //dbg_print("wdtInterval=0x%x, Out of range!! Auto down scale to Max value", wdtInterval);
        wdtInterval = RSTCTL_MAX_PERIOD_NUM;
    }

    if(0 != wdtInterval)
    {
        DRV_WriteReg32(REG_WDT_MD_LENGTH, RSTCTL_MD_LENGTH_KEY | (wdtInterval << RSTCTL_TIMEOUT_BIT));
        /*3. reload period*/

        DRV_WriteReg32(REG_WDT_MD_RESTART, RSTCTL_RESTART_TIMER_KEY);
        UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/
    }

    /*4. set irq mode*/
    if (irq_en == WDT_IRQ_ONLY)
	{
		DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)|((DRV_Reg32(REG_WDT_MD_MODE)) | (0x1 <<RSTCTL_IRQ_MODE_BIT)));
	}
	else
	{
		DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)|((DRV_Reg32(REG_WDT_MD_MODE)) & (~(0x1 <<RSTCTL_IRQ_MODE_BIT))));
	}
    /*5. enable wdt*/
    if(0 != wdtInterval)
    {
        DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE) | (0x1 << RSTCTL_WDT_EN_BIT )) );
    }
    else
    {
        drv_rstctl_sw_reset(RST_MD_SWRST);
    }
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_getSta
*
* DESCRIPTION
*  This function is used to get wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*    wdt_sta_e: no reset, sw reset, wd timer reset, sw and wd timer reset
*
*************************************************************************/
kal_uint32 drv_rstctl_wd_getSta(void)
{
    kal_uint32 sta;

    sta = DRV_Reg32(REG_WDT_MD_STA);

    return sta;
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_kick
*
* DESCRIPTION
*  This function is used to retart wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_kick(void)
{
    DRV_WriteReg32(REG_WDT_MD_RESTART, RSTCTL_RESTART_TIMER_KEY);
    UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to set retention flag
*
* PARAMETERS
*	flag: rst_retn_flag_e
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_retn_flag_set(rst_retn_flag_e flag)
{
    DRV_WriteReg32(REG_WDT_RETN_SET, RSTCTL_RETN_FLAG_SET_KEY | flag);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to get retention flag
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	retetion flag value
*************************************************************************/
kal_uint16 drv_rstctl_retn_flag_get(void)
{
    return DRV_Reg32(REG_WDT_RETN_FLAG);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to clear retention flag
*
* PARAMETERS
*	flag: rst_retn_flag_e
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_retn_flag_clr(rst_retn_flag_e flag)
{
    DRV_WriteReg32(REG_WDT_RETN_CLR, RSTCTL_RETN_FLAG_SET_KEY | flag);
}


/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_data
*
* DESCRIPTION
*  This function is used to read/write retention data
*
* PARAMETERS
*	bRead: 1: read data
*           0: write data
*    pData:
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_retn_data(kal_bool bRead, kal_uint32 *pData)
{
    if(pData == NULL)
        return;

    if(bRead == KAL_TRUE)
    {
        *pData =  DRV_Reg32(REG_WDT_RETN_DAT0);
    }
    else
    {
        DRV_WriteReg32(REG_WDT_RETN_DAT0, *pData);
    }

}

/*************************************************************************
*              Following is used by WDT DCL (Driver Common Layer)        *
*************************************************************************/

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_disable
*
* DESCRIPTION
*  This function is used to disable wd timer
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_disable(void)
{
	DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE) & ~(0x1 << RSTCTL_WDT_EN_BIT)) );
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to clear wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrSta(void)
{
	/*Just write wdt_md_mode register to clear status*/
	DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE))  );
}


/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to get wd timer interval(uint:512*T(32k))
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
kal_uint16 drv_rstctl_wd_getInterval(void)
{
	return (kal_uint16)(DRV_Reg32(REG_WDT_MD_LENGTH) >> RSTCTL_TIMEOUT_BIT);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_kick
*
* DESCRIPTION
*  This function is used to retart wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_restartWDT(void)
{
	drv_rstctl_wd_kick();
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_setInterval
*
* DESCRIPTION
*  This function is used to set wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
void drv_rstctl_wdt_setInterval(kal_uint32 wdtInterval)
{
	/* Set watchdog interval */
	DRV_WriteReg32(REG_WDT_MD_LENGTH, RSTCTL_MD_LENGTH_KEY | (wdtInterval << RSTCTL_TIMEOUT_BIT));
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enable
*
* DESCRIPTION
*  This function is used to on/off wd timer
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
void drv_rstctl_wdt_enable(kal_bool en)
{
	if (en == KAL_TRUE)
	{
		DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE) | (0x1 << RSTCTL_WDT_EN_BIT )) );
		/*Reload wdt interval*/
		drv_rstctl_wd_kick();
	}
	else
	{
		drv_rstctl_wd_disable();
	}
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_abnReset
*
* DESCRIPTION
*  This function is used to do abnormal reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_abnReset(void)
{
	SaveAndSetIRQMask();
	drv_rstctl_wd_reset(WDT_IRQ_ONLY, RST_TARGET_MAX, 1);
	while(1);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableInterrupt
*
* DESCRIPTION
*  This function is used to on/off irq mode
*       reset or trigger interrupt while watchdog timout happening
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_enableInterrupt(kal_bool enable)
{
	if (enable == KAL_TRUE)
	{
		DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)|((DRV_Reg32(REG_WDT_MD_MODE)) | (0x1 <<RSTCTL_IRQ_MODE_BIT)));
	}
	else
	{
		DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)|((DRV_Reg32(REG_WDT_MD_MODE)) & (~(0x1 <<RSTCTL_IRQ_MODE_BIT))));
	}
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_init
*
* DESCRIPTION
*  This function is to initialize the WDT module
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_init(void)
{
	//WDT_RST = (DRV_WDT_Reg(WDT_STATUS) & WDT_STATUS_BITMASK)?(KAL_TRUE):(KAL_FALSE);
	drv_rstctl_wdt_setInterval(WDT_RSTINTERVAL_VALUE);

#if defined(DRV_WDT_IRQ_MODE)
	drv_rstctl_wdt_enableInterrupt(KAL_TRUE);
	//IRQSensitivity(IRQ_MD_WDT_CODE, KAL_TRUE);
	//IRQUnmask(IRQ_MD_WDT_CODE);
#endif
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_reset
*
* DESCRIPTION
*  This function is to do wdt reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_reset(void)
{
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
	kal_uint16 powerkey_status;

	#if defined(__USB_ENABLE__)

	DCL_BOOL dcl_data = DCL_TRUE;
	DCL_HANDLE	usb_dcl_handle;

	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);

	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_PDN_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_DRV_Close(usb_dcl_handle);

	//	 USB_PDNmode(KAl_TRUE);

	#endif //#if defined(__USB_ENABLE__)

	#ifdef PMIC_PRESENT

	if (BMT.PWRon != CHRPWRON)
	{
		switch(Pwrkey_Position)
		{
			case low_key:
				powerkey_status= DRV_Reg32(KP_LOW_KEY);
				break;
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
			case high_key:
				powerkey_status= DRV_Reg32(KP_HI_KEY);
				break;
			default:
				ASSERT(0);
				break;
		}
		if(WdtPowerKey_Pressed())
		{
			TargetReset = 1;
		}
		else
		{
			/*lint -e(534)*/SaveAndSetIRQMask();

			drv_rstctl_wdt_setInterval(1);
			drv_rstctl_wd_kick();
			drv_rstctl_wdt_enable(KAL_TRUE);
			while(1);
		}
	}
	else
	{
		/*lint -e(534)*/SaveAndSetIRQMask();

		drv_rstctl_wdt_setInterval(1);
		drv_rstctl_wd_kick();
		drv_rstctl_wdt_enable(KAL_TRUE);
		while(1);
	}
	#else /*PMIC_PRESENT*/
		  /*lint -e(534)*/SaveAndSetIRQMask();

		drv_rstctl_wdt_setInterval(1);
		drv_rstctl_wd_kick();
		drv_rstctl_wdt_enable(KAL_TRUE);
		while(1);
	#endif   /*PMIC_PRESENT*/
#else /*!DRV_WDT_RESET_PKEY_RELEASE*/

	kal_uint16 index;
#if defined(DRV_RTC_REG_COMM)
	DCL_HANDLE rtc_handler;
	RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data8;
#endif /*DRV_RTC_REG_COMM*/
	/*lint -e(534)*/SaveAndSetIRQMask();

	for(index=0;index<1000;index++);
#if defined(DRV_RTC_REG_COMM)
	//RTC_Set_PDN_bits(rtc_pdn2 ,DRV_COMM_REG2_NORMAL_RESET);
	rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
	rtc_cmd_data8.PDNIndex = DCL_RTC_PDN2;
	rtc_cmd_data8.fgConfigBit = DRV_COMM_REG2_NORMAL_RESET;
	DclRTC_Control(rtc_handler, RTC_CMD_SET_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data8); // New API with CMD & DATA
#endif   /*DRV_RTC_REG_COMM*/
#if !defined(DRV_WDT_SWRST)
	drv_rstctl_wdt_setInterval(1);
	drv_rstctl_wd_kick();
	drv_rstctl_wdt_enable(KAL_TRUE);
	while(1);
#else
	#if defined(DRV_MISC_WDT_TURN_OFF_PLL)
	DRV_WriteReg32(0x80000108, 0);
	#endif // #if defined(DRV_MISC_WDT_TURN_OFF_PLL)
	_rst_swWdReset();	/* To trigger software watchdog reset */
	while(1);
	#endif
#endif   /*!DRV_WDT_RESET_PKEY_RELEASE*/

}

/*Legacy part for DCL*/
/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrCnt(kal_uint32 cntMaskToClear)
{

}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableDebugMode
*
* DESCRIPTION
*  This function is used to on/off debug mode
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wdt_enableDebugMode(kal_bool enable)
{

}



/*************************************************************************
*              Following is used by system init                          *
*************************************************************************/
/*************************************************************************
* FUNCTION
*  WDT_init
*
* DESCRIPTION
*  This function is to initialize the WDT module
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void WDT_init(void)
{
	drv_rstctl_wdt_init();
}

/*************************************************************************
* FUNCTION
*  Get_WATCHDOG_BASE
*
* DESCRIPTION
*  This function is to get restart wd timer base address
*
* PARAMETERS
*    none
*
* RETURN VALUES
*    wd timer kick base address
*
*************************************************************************/
kal_uint32 Get_WATCHDOG_BASE()
{
	return (REG_WDT_MD_RESTART);
}

/*************************************************************************
* FUNCTION
*  Get_WATCHDOG_RESTART_CMD
*
* DESCRIPTION
*  This function is to get restart wd timer key
*
* PARAMETERS
*    none
*
* RETURN VALUES
*    wd timer kick command key
*
*************************************************************************/
kal_uint32 Get_WATCHDOG_RESTART_CMD()
{
	return (RSTCTL_RESTART_TIMER_KEY);
}

/*************************************************************************
* FUNCTION
*  Is_WDT_Init
*
* DESCRIPTION
*  Check WD timer is set to system default value already or not
*
* PARAMETERS
*    none
*
* RETURN VALUES
*     TRUE: already set
*    FALSE: not yet
*
*************************************************************************/
kal_bool Is_WDT_Init()// for ex_item.c
{
	if( drv_rstctl_wd_getInterval() == WDT_RSTINTERVAL_VALUE )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}


//#endif /*Remove for not using*/

#else
#error Not support rstctrl in this chip type
#endif /*TK6291*/


#else /*!defined(DRV_RSTCTL_OFF)*/

#endif /*!defined(DRV_RSTCTL_OFF)*/



