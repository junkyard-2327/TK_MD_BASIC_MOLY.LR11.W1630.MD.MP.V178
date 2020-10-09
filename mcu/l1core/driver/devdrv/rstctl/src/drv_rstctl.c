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
 *   UMOLY
 *
 * Description:
 * ------------
 *   This is for L1Core RGU driver
 *
 * Author:
 * Vmick Lin
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
 * 08 04 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * Add MT6797 compile flag.
 *
 * 06 18 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * Solve JADE build error after removing MADDR_APRGU.
 *
 * 06 18 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * Modify MACRO for JADE because of lacking MADDR_APRGU.
 *
 * 06 18 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Solve Jade build error because of removing MADDR_APRGU.
 *
 * 06 11 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Add compile option flag to restrict WDT enable without __PRODUCTION_RELEASE__ in abnrset api.
 * 	Add BB_Register dump. 
 * 	Add EMMWriteDebugInfo for track caller info in share memory.
 *
 * 04 30 2015 dennis.chueh
 * [MOLY00110144] [TK6291E1][L1S][UMOLY][4G][Blocking] Fatal Error (0x3107, 0x0) - WDT_HIS
 * 	[MOLY00070771] [6291][FPGA]solve build error
 * 	Disable L1 watchdog for L1S project and update corresponding drvtest cases.
 *
 * 04 28 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Add silent reboot in exception flow and trigger fatal error upon receving L1WDT IRQ.
 *
 * 04 27 2015 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Klocwork correction.
 *
 * 12 31 2014 dennis.chueh
 * [MOLY00070771] [6291][FPGA]solve build error
 * 	Test mode code check in.
 *
 * 05 23 2014 vmick.lin
 * [MOLY00062072] [TK6291][RGU] Implement
 * 	.
 *
 ****************************************************************************/

#include "drv_features_wdt.h"
#include "drv_comm.h"

#include "rstctl_reg.h"
#include "drv_rstctl.h"
#include "intrCtrl.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ex_public.h"	/*Include this header file for register BBreg dump*/

#if !defined(DRV_RSTCTL_OFF)

#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)

/*****************************************************************************
 *						 Global/External Variable                            *
 *****************************************************************************/
const kal_uint32 g_WATCHDOG_RESTART_REG   = REG_L1RSTCTL_WDT_RESTART;
const kal_uint32 g_WATCHDOG_RESTART_VALUE = RSTCTL_L1WDT_RESTART_KEY;
const kal_uint32 g_ABNORMAL_RST_REG       = REG_L1RSTCTL_WDT_LENGTH;
const kal_uint32 g_ABNORMAL_RST_VAL		  = WDT_RSTINTERVAL_VALUE;

/*Global vaialbe for BBreg dump*/
#if defined(__MTK_TARGET__)
	EX_BBREG_DUMP L1core_RGU_dump;
	const kal_uint32 L1core_RGU_dump_regions[] = {
	L1_BASE_ADDR_L1RGU, 0x0020, 4, 
	}; 
#endif



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



/*************************************************************************
* FUNCTION
*  drv_rstctl_sw_reset
*
* DESCRIPTION
*  This function is to do software reset 
*
* PARAMETERS
*    targetIP: the target IP that is defined in drv_rstctl.h will be software reset
*
* RETURN VALUES
*	none
*
*************************************************************************/

void drv_rstctl_sw_reset(rst_target_e targetIP)
{
#if defined(TK6291)
	kal_uint32 timeout_cnt=0;  //for RST_MEMORY only
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
			{_rst_resetIP(REG_APRSTCTL_SRBER_PAR, RSTCTL_APSRBER_AP_MD1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
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
 /*For TK6291, Designer inherits the L1RGU design from 90. Therefore, we could not trigger  SWDT after HWDT is triggered. */
 /*Since SWDT and HWDT are exclusive, we only trigger HWDT for abnormal Reset. */
 DRV_WriteReg32(REG_L1RSTCTL_WDT_LENGTH, 0x28);  /*Minimum length unit: 512T 32K*/
 DRV_WriteReg32(REG_L1RSTCTL_WDT_RESTART, RSTCTL_L1WDT_RESTART_KEY); 
 #ifdef __PRODUCTION_RELEASE__	/*Only enable WDT for production_release. */ 
 	DRV_WriteReg32(REG_L1RSTCTL_WDT_MODE, RSTCTL_L1WDT_MODE_KEY | RSTCTL_L1WDT_MODE_WDTEN);  
 #endif
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
kal_uint16 drv_rstctl_wd_getInterval(void)
{
	return (kal_uint16)(DRV_Reg32(REG_WDT_MD_LENGTH) >> RSTCTL_TIMEOUT_BIT);
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
    DRV_WriteReg32(REG_WDT_MD_RESTART, RSTCTL_RESTART_TIMER_KEY);
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
	drv_rstctl_wdt_setInterval(WDT_RSTINTERVAL_VALUE);
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
		DRV_WriteReg32(REG_WDT_MD_RESTART, RSTCTL_RESTART_TIMER_KEY);
	}
	else
	{
		DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE) & ~(0x1 << RSTCTL_WDT_EN_BIT)) );
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
    drv_rstctl_wdt_init();


	/*Begin : Register BB_Reg DUMP*/
	L1core_RGU_dump.regions = (kal_uint32*)L1core_RGU_dump_regions; 
	L1core_RGU_dump.num = sizeof(L1core_RGU_dump_regions) / (sizeof(kal_uint32) * 3); 
	L1core_RGU_dump.bbreg_dump_callback = NULL; 
	EX_REGISTER_BBREG_DUMP(&L1core_RGU_dump);
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
	return (REG_L1RSTCTL_WDT_RESTART);
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
	return (RSTCTL_L1WDT_RESTART_KEY);
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

#else
#error Not support rstctrl in this chip type
#endif /*TK6291*/


#else /*!defined(DRV_RSTCTL_OFF)*/

#endif /*!defined(DRV_RSTCTL_OFF)*/



