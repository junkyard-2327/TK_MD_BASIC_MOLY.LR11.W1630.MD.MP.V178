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
 *   pll.c
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
 * ==========================================================================
 * $Log$
 *
 * 11 21 2016 jun-ying.huang
 * [MOLY00214294] [1630MP][ROSA][FMA][PLL]Add new project macro for ROSA
 * MT6750S call-for-check-in
 *
 * 05 06 2016 alan-tl.lin
 * [MOLY00178032] [PLL] Update PSMCUPLL set/get API for Olympus
 * PSMCUPLL posdiv is 4
 *
 * 02 24 2016 linson.du
 * [MOLY00166240] [Olympus]: driver porting
 * Olympus Pll driver porting.
 *
 * 10 26 2015 linson.du
 * [MOLY00146768] [MODEM L1 DVFS] IMCPLL initial setting
 * IMC DVFS init re-org.
 *
 * 09 23 2015 linson.du
 * [MOLY00143013] [MT6797] [MODEM L1 DVFS] Enable DVFS and PTP
 * Update IMC dvfs table for everest by JW Yu request.
 *
 * 09 18 2015 linson.du
 * [MOLY00136396] [MT6755]: PLL driver porting
 * Disable DVFS init in everest.
 *
 * 09 09 2015 linson.du
 * [MOLY00136396] [MT6755]: PLL driver porting
 * IMC dvfs initial setting modification.
 *
 * 08 10 2015 linson.du
 * [MOLY00136396] [MT6755]: PLL driver porting
 * Driver porting to disable PSMCUPLL restore mode.
 *
 * 08 10 2015 linson.du
 * [MOLY00136396] [MT6755]: PLL driver porting
 * Pll driver porting for PSMCU DFS.
 *
 * 08 04 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PLL/PDN driver porting for Everest.
 *
 * 07 21 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * update for golden setting.
 *
 * 07 17 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * 1. refine DVFS init sequence as DE suggest.
 * 2. force to switch ARM7 and DBG from 26Mhz to PLL.
 *
 * 07 13 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * 	PLL driver update for golden setting and l1modem dvfs.
 *
 * 06 25 2015 linson.du
 * [MOLY00122918] [MT6755][BRINGUP_FIRSTCALL][SS]
 * Update PLL driver for Jade SB bring up.
 *
 * 06 18 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Update PLL driver.
 *
 * 06 15 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PLL porting for MT6755.
 *
 * 06 12 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Add PSMCU frequency modification api.
 *
 * 02 10 2015 linson.du
 * [MOLY00095411] [TK6291]: PLL driver porting
 * 	TK6291 Pcore/L1core pll init for cosim.
 *
 * 04 09 2014 tungchieh.tsai
 * [MOLY00062096] [TK6291][UMOLY] PLL driver porting
 *  	
 * Clean up MOLY PLL driver, make it dummy now
 *
 ****************************************************************************/

#ifdef __MTK_TARGET__ /* should NOT be compiled on MODIS */

/*******************************************************************************
 * Locally Used Options
 *******************************************************************************/
#if defined(TK6291)
#define PLL_PSMCU_CLOCK_MAX 775
#define PLL_PSMCU_CLOCK_MIN 500
#else
#define PLL_PSMCU_CLOCK_MAX 800
#define PLL_PSMCU_CLOCK_MIN 500
#endif

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "pll.h"

#if defined(TK6291)
void INT_SetPLL_TK6291(void)
{

	// version will be 0x0 in FPGA.
	if(*REG_MDTOP_CLKSW_CLKSEL_VER < 0x20140000)
	{
	  // there is no pll design in FPGA
		return;
	}
	
	//*************************should be covered in ap_bring_ps**************************
	*REG_MDTOP_CLKSW_FLEXCKGEN_SEL0 |= (0x3<<12); //configure ARM7 to select DFEPLL
	*REG_MDTOP_PLLMIXED_PSMCUPLL_CTL0 = 0x800EE762; //configure PSMCUPLL PCW to output 775Mhz
	while((*REG_MDTOP_PLLMIXED_PSMCUPLL_STS>>9)&0x1) //Polling until PSMCUPLL complete frequency adjustment
	{
		/*do something dummy*/
	}

	while((*REG_MDTOP_CLKSW_FLEXCKGEN_STS0 & 0x80) != 0x80) //wait MD bus clock ready
	{
		/*do something dummy*/
	}

	*REG_MDTOP_CLKSW_CLKSEL_CTL |= 0x3; //switch PSMCU & MD BUS clcok to PLL frequency
	//******************************************************************************

	*REG_MDTOP_PLLMIXED_L1MCUPLL_CTL0 = 0x8015EC4F; //configure L1MCUPLL PCW to output 570Mhz
	while((*REG_MDTOP_PLLMIXED_L1MCUPLL_STS >> 9)&0x1) //Polling until L1MCUPLL complete frequency adjustment
	{
		/*do something dummy*/
	}

	*REG_MDTOP_CLKSW_CLKSEL_CTL |= 0x3FF0C; //switch ARM7 & MD DBG & L1MCU & MODEM clock to PLL freqeuncy
}	
#endif


#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
void INT_SetPLL_JADE()
{
#if defined(PSMCU_COMPILE) || defined(MDMCU_LITE_COMPILE)
	#ifndef MDMCU_LITE_COMPILE
	
		#ifndef CACHE_OFF
	/* I-Cache and D-Cache Enable */
	apmcu_invalidate_icache();
	apmcu_invalidate_dcache();
	init_icache();

			#ifdef DCACHE_ON
		init_dcache();
			#endif

		#endif
	
	// /* Modem power on sequence */
	// *MODEM_TOPSM_RM_PWR_CON1   |=0x44;	  // Bit  6:HSPA1 PWR_REQ_EN,
	//							  // Bit  2:HSPA1 PWN_ON
	// *MODEM_TOPSM_RM_PWR_CON2   |=0x44;	  // Bit  6:HSPA2 PWR_REQ_EN,
	//							  // Bit  2:HSPA2 PWN_ON
	// *MODEM_TOPSM_RM_PWR_CON3   |=0x44;	  // Bit  6:HSPA3 PWR_REQ_EN,
	//							  // Bit  2:HSPA3 PWN_ON
	// *MODEM_TOPSM_RM_PWR_CON4   |=0x44;	  // Bit  6:HSPA4 PWR_REQ_EN,
	//							  // Bit  2:HSPA4 PWN_ON
	// *MODEM_LITE_TOPSM_RM_PWR_CON0  |=0x44;	  // Bit  6:MD2G PWR_REQ_EN,
								  // Bit  2:MD2G PWN_ON
	
	*R_L1_PMS |= 0x7;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
#endif	


	// modify PSMCU2EMI bus divider from 3 to 4.
	*R_PSMCU_AO_CLK_CTL = *R_PSMCU_AO_CLK_CTL | 0x83;
		
	*R_L1MCU_PWR_AWARE |=	(1<<16); //lock dcm bus
	*R_L1AO_PWR_AWARE |=	(1<<16); //lock dcm bus
	//busL2 DCM div 8/normal div 1/ clkslow_en/clock from PLL /debounce enable/ debounce time 7T 
	*R_BUSL2DCM_CON3 = 0x0001FDE7; //L2DCM L1BUS div 16
	*R_BUSL2DCM_CON3 = 0x1001FDE7; //toggle setting
	*R_L1MCU_DCM_CON = 0x0003FDE7; //L2DCM L1MCU div 8
	*R_L1MCU_DCM_CON2 = 0x0; //DCM config toggle = 0
	//*R_L1MCU_DCM_CON2 = 0x90000000; //DCM config toggle  = 1 / 
	*R_L1MCU_DCM_CON2 = 0x80000000; //DCM config toggle  = 1 / 
	//*R_L1MCU_PWR_AWARE &=	(1<<16); //un-lock dcm bus
	//*R_L1AO_PWR_AWARE &=	(1<<16); //un-lock dcm bus
	
	#ifndef SIM_26M
      /*Wait PSMCU PLL ready*/
	  while ((*R_PLL_STS & 0x1) !=0x1); 		  // Bit  0: PSMCUPLL_RDY
	  /*Switch clock, 0: 26MHz, 1: PLL*/
	  *R_CLKSEL_CTL |=0x2;					// Bit	17: RF1_CKSEL
								// Bit	16: INTF_CKSEL
								// Bit	15: MD2G_CKSEL
								// Bit	14: DFE_CKSEL
								// Bit	13: CMP_CKSEL
								// Bit	12: ICC_CKSEL
								// Bit	11: IMC_CKSEL
								// Bit	10: EQ_CKSEL
								// Bit	9: BRP_CKSEL
								// Bit	8: L1MCU_CKSEL
								// Bit	6-5: ATB_SRC_CKSEL
								// Bit	4: ATB_CKSEL
								// Bit	3: DBG_CKSEL
								// Bit	2: ARM7_CKSEL
								// Bit	1: PSMCU_CKSEL
								// Bit	0: BUS_CKSEL

	  /*Wait L1MCU PLL ready*/
	  while ((*R_PLL_STS & 0x2) != 0x2);		  // Bit  1: L1MCUPLL_RDY
	  *R_CLKSEL_CTL |= 0x100;				// Bit	8: L1MCU_CK = L1MCUPLL
	  
	  
	  /*DFE/CMP/ICC/IMC clock src select*/
	  *R_FLEXCKGEN_SEL1 = 0x30302020;          // Bit 29-28 DFE_CLK src = DFEPLL
	  										   // Bit 21-20 CMP_CLK src = DFEPLL
	  										   // Bit 13-12 ICC_CLK src = IMCPLL
	  										   // Bit 5-4    IMC_CLK src = IMCPLL


	  /*IMC/MD2G clock src select */
      *R_FLEXCKGEN_SEL2 = 0x00002030;          // Bit 13-12 INTF_CLK src = IMCPLL
      										   // Bit 5-4  MD2G_CLK src = DFEPLL

	  /*Wait DFE/IMC PLL ready*/
	  while ((*R_PLL_STS & 0x90) !=0x90); 		  // Bit  7: DFEPLL_RDY
	                                              // Bit  4: IMCPLL_RDY
	  /*Wait L1SYS clock ready*/
	  while ((*R_FLEXCKGEN_STS0 & 0x80800000) != 0x80800000);	  // Bit  31: EQ_CK_RDY
	                                                              // Bit  23: BRP_CK_RDY
      while ((*R_FLEXCKGEN_STS1 & 0x80808080) != 0x80808080);	  // Bit  31: DFE_CK_RDY
	                                                              // Bit  23: CMP_CK_RDY	                                                              
	                                                              // Bit  15: ICC_CK_RDY	
	                                                              // Bit  7:  IMC_CK_RDY	

  	  while ((*R_FLEXCKGEN_STS2 & 0x8080) != 0x8080);	          // Bit  15: INTF_CK_RDY
	                                                              // Bit  23: MD2G_CK_RDY

	  /*Switch L1SYS clock to PLL clock*/
	  *R_CLKSEL_CTL |=0x3fe08;

	  /*MD BUS/ARM7 clock src select */
      *R_FLEXCKGEN_SEL0 = 0x30203031;                             // Bit  29-28: EQ_CLK src = EQPLL
	                                                              // Bit  26-24: EQ+DIVSEL, divided-by bit[2:0]+1
	                                                              // Bit  21-20: BRP_CLK src = IMCPLL
	                                                              // Bit  13-12: ARM7_CLK src = DFEPLL
	                                                              // Bit  5-4: BUS_CLK src = EQPLL
	                                                              // Bit  2-0: BUS_DIVSEL, divided-by bit[2:0]+1

	  *MD_GLOBAL_CON_DUMMY = MD_PLL_MAGIC_NUM;
																  
	  
		
	#ifdef ARM7_ON
	  while ((*R_FLEXCKGEN_STS0 & 0x8000) != 0x8000);	// Bit	15: ARM7_CK_RDY
	  *R_CLKSEL_CTL |= 0x4; 							// Bit	 2: ARM7_CLK = L1MCUPLL / 2 = 300MHz
	
	// *R_ARM7_ADDR_OFFSET = 0x20000;
	// /* Turn on ARM7 */
	// *R_RM_PWR1_CON = (*R_RM_PWR1_CON & 0xFFFFFFFC) | 0x3;
	// *R_RM_PWR1_CON = 0x21e5;
	// *R_RESET_UNLOCK = 0x1;
	#endif
	
	//#ifdef L1MCU_ON
	  
	  /*Switch L1SYS clock to PLL clock*/
	  //*R_CLKSEL_CTL |= 0x3fe00;
	  /* Trig L1 bootslave*/
	  //FOR_LOOP_DELAY(loop_var,200);
	//#endif //ifdef MDL1_ON
	
	#endif // ifndef SIM_26M
	
	//#ifdef L1MCU_ON
	  //*MDL1AO_BTVEC_UPDATE = 0x1;
	//#endif // ifdef MDL1_ON
	
	//#ifndef PWB_OFF
	  /* Post Write Buffer Enable */
	//#endif
	
	#ifndef BYPASS_MDCIRQ_INI
	  /* MDCIRQ minimum priority level */
	  *R_MDCIRQ_MIN_PRLV = 0x3f;
	  /* MDCPU vector interrupt mode */
		#ifdef VECTOR_INTR_ON
	  cp15_vector_interrupt_enable();
		#else
	  *R_MDCIRQ_CTRL_REG = 0x0000;
		#endif
	  /* MDCIRQ vector address */
	  *R_MDCIRQ_VEC_ADDR_BASE = 0xb4;
	  *R_MDCIRQ_VEC_ADDR_OFF  = 0x4;
	  *R_MDCIRQ_VEC_ADDR_DEFAULT = 0xb4;
	#endif
	
	#ifndef DCM_OFF
	
  		#ifndef LEVEL2_DCM_OFF
	  /* MD Level-2 DCM Enable */
	  // TDB
  		#endif
		
#if 0 // DCM config should not be pll init
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif							  
	  *REG_DCM_PLLCK_SEL |= (1<<7); 	  // Bit  7: 0: clock do not from PLL, 1: clock from PLL							  
	#endif // ifndef DCM_OFF

	// wait DCM config done, then switch BUS clock src to PLL
	while ((*R_FLEXCKGEN_STS0 & 0x80) !=0x80); 		  // Bit  7: BUS_CK_RDY	  													  
	*R_CLKSEL_CTL |=0x1;                                // Bit  1: BUS_CLK = EQPLL/2
	
	
	// *MD_TOP_MDDSP_DCM_CON0 = *MD_TOP_MDDSP_DCM_CON0 | (1<<27); // md_apsrc_ack protect
	
	 /* PFH enable must need cache enable first */
	#ifndef CACHE_OFF
  		#ifndef PFB_OFF
	  /* Pre-fetch Buffer Enable */
	  *R_CR4_PREFETCH_CONTROL |= 0x1D;		  // Bit  7-4: PFH_ARID
							  // Bit  3: PFH_LEN_SEL
							  // Bit  2: PFH_LENGTH_EQ4
							  // Bit  0: PFH_EN
  		#endif
	#endif
	
	
	#else //ifndef MDMCU_LITE_COMPILE
		#ifndef BYPASS_A7CIRQ_INI
	  ReEnableIRQ();
	  ReEnableFIQ();
		#endif
	#endif // ifndef MDMCU_LITE_COMPILE
	
#elif defined(L1MCU_COMPILE)
	  *REG_M_L1_MDL1_CONF_MDL1AO_CG_CLR = 0xFFFF;

	  *REG_M_L1_MDL1_CONF_MDL1AO_BTVEC_UPDATE = 0x6291F8EE;
	  *REG_M_L1_MDL1_CONF_MDL1AO_BTVEC_UPDATE = 0x0;
	  *REG_M_L1_MDL1_CONF_MDL1AO_BTVEC_UPDATE = 0x629110C4;	
  #ifndef CACHE_OFF
	  {
		/*enable icache/dcache */
	  apmcu_invalidate_icache();
	  apmcu_invalidate_dcache();
	  init_icache();
	  init_dcache();
	  }
  #endif
	  /*turn modem power ON*/
	  {
		UINT32 i = 0;
	  /*MDL1_TOPSM_SM_PWR_CON0~19*/
	  for(i=0; i<20; i++){
		*(UINT32P)(0xF6070000 + 4*i) = 0xB2002582;
	  }
	  /*read power status*/
	  while((*REG_M_L1_TOPSM_SM_PWR_RDY & 0xFFFF) != 0xFFFF);
	  }
	#ifndef BYPASS_MDCIRQ_INI
	  cp15_vector_interrupt_enable();
	  /*initial L1CIRQ*/
	  *REG_M_L1_L1CIRQ_VEC_ADDR_BASE = 0x08000d0;
	  *REG_M_L1_L1CIRQ_MIN_PRLV = 0x3f;
	#endif
	
#else
	#ifdef APMCU_ENABLE
	 	apmcu_common();
		//------------------------------------------------------------------------
		// Set APMCU ITCM
		//------------------------------------------------------------------------
		#if APMCU_ITCM_ON == 1
		apmcu_enable_itcm(0x50000000);
		#endif

		//------------------------------------------------------------------------
		// Set APMCU DTCM
		//------------------------------------------------------------------------
		#if APMCU_DTCM_ON == 1
		apmcu_enable_dtcm(0x50040000);
		#endif

		//------------------------------------------------------------------------
		// Set APMCU ICACHE
		//------------------------------------------------------------------------
		#if APMCU_ICACHE_ON == 1
		apmcu_enable_icache();
		#endif


		//------------------------------------------------------------------------
		// Set APMCU DCACHE
		//------------------------------------------------------------------------
		#if APMCU_DCACHE_ON == 1
		apmcu_enable_dcache();
		#endif

		#ifdef ENTER_SUSPEND_BF_CMAIN
		//----------------------
		// Enter Suspend Mode
		//----------------------
		ENTER_SUSPEND();
		#endif
	#endif //APMCU_ENABLE
#endif

}

void INT_SetPLL_JADE_L1DVFS(void)
{
  *R_PLL_DLY_CTL0 = 0x2004200D; //set abb settle time from 100us to 20us
  *R_PLL_DLY_CTL2 = 0x00000001; //remove additional settle time(20us)
  *R_IMCPLL_CTL1  = 0x13; //set imcpll posdiv = div8

  // swtich DBG and ARM7 to PLL
  *R_CLKSEL_CTL |= 0xC;
  *R_MDPERI_CKEN &= ~(1<<17); //disable TRACE clock
  *R_PSMCUPLL_FHCTL0 &= ~(1<<21); //PLL off restore mode disable
}
#endif //#if defined(MT6755)


/*************************************************************************
 * FUNCTION
 *  Set_PSMCU_frequency
 *
 * DESCRIPTION
 *  This function modify PSMCU frequency.
 *
 * PARAMETERS
 *  clock rate input
 *
 * RETURNS 
 * 1: out of range, 0: success
 *
 *************************************************************************/
kal_uint32 Set_PSMCU_frequency(kal_uint32 clock)
{
    kal_uint32 ret = 0;
#if defined(MT6757)
    kal_uint32 posdiv = 4;
#else
    kal_uint32 posdiv = 2;
#endif

    //psmcu should be 500<=clock<=800
    if((clock > PLL_PSMCU_CLOCK_MAX )||(clock < PLL_PSMCU_CLOCK_MIN))
    {
        ret = 1; //out of range
        return ret;
    }
    *REG_MDTOP_PLLMIXED_PSMCUPLL_CTL0 = (posdiv*clock*(1<<14)/26)|0x80000000;
    return ret;
}

/*************************************************************************
 * FUNCTION
 *  Get_PSMCU_frequency_setting
 *
 * DESCRIPTION
 *  This function return the previous PSMCU frequency setting from register.
 *
 * PARAMETERS
 *  None
 *
 * RETURNS 
 *  kal_uint32: PSMCU frequency setting
 *
 *************************************************************************/
kal_uint32 Get_PSMCU_frequency(void)
{
#if defined(MT6757)
    kal_uint32 posdiv = 4;
#else
    kal_uint32 posdiv = 2;
#endif

    return (((*REG_MDTOP_PLLMIXED_PSMCUPLL_CTL0)*26)/(1<<14)/posdiv);
}

/*************************************************************************
 * FUNCTION
 *  Deassert_PSMCU_PLLHP_INT
 *
 * DESCRIPTION
 *  This function de-assert the PSMCU PLL HP interrupt.
 *
 * PARAMETERS
 *  None
 *
 * RETURNS 
 *  None
 *
 *************************************************************************/
void Deassert_PSMCU_PLLHP_INT(void)
{
#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
	*R_PLL_HP_RDY_IRQ = (1<<1);
#endif
}

/*************************************************************************
 * FUNCTION
 *  Get_PSMCU_PLLHP_INT_status
 *
 * DESCRIPTION
 *  This function return the PSMCU PLL HP interrupt status.
 *
 * PARAMETERS
 *  None
 *
 * RETURNS 
 *  0: no INT assert, 1: INT assert
 *
 *************************************************************************/
kal_bool Get_PSMCU_PLLHP_INT_status(void)
{
#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)	
	return (kal_bool)(((*R_PLL_HP_RDY_IRQ)>>1)&0x1);
#else
	return 0;	
#endif	
}

/*************************************************************************
 * FUNCTION
 *  Get_PSMCUPLL_SFSTR_PRD_status
 *
 * DESCRIPTION
 *  This function return the PSMCU PLL in soft-start period status.
 *
 * PARAMETERS
 *  None
 *
 * RETURNS 
 *  0: not in soft-start period, 1: in soft-start period
 *
 *************************************************************************/
kal_bool Get_PSMCUPLL_SFSTR_PRD_status(void)
{
#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
	return (kal_bool)(((*R_PSMCUPLL_STS)>>9)&0x1);
#else
	return 0;
#endif
}

/*************************************************************************
 * FUNCTION
 *  INT_SetPLL
 *
 * DESCRIPTION
 *  This function dedicates for PLL setting.
 *
 * PARAMETERS
 *  Init mode of PLL
 *
 * RETURNS
 *************************************************************************/
void INT_SetPLL(pll_init_mode mode)
{
#if defined(TK6291)
    INT_SetPLL_TK6291();
#endif

#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
    if( MD_PLL_MAGIC_NUM != *MD_GLOBAL_CON_DUMMY )
    {
		INT_SetPLL_JADE();
    }
	else
	{
		// AP have been init MD PLL setting.  
		*R_L1_PMS &=~ 0x6; //Clear PMS which AP has set		
	}
	INT_SetPLL_JADE_L1DVFS();
#endif

}

#define PLL_FM_WIMDOW 0x1FF

//frequency meter index list
#define PLL_FM_L1SYS_INTF_CLOCK 1
#define PLL_FM_L1SYS_MD2G_CLOCK 2
#define PLL_FM_L1SYS_DFE_CLOCK  3
#define PLL_FM_L1SYS_CMP_CLOCK  4
#define PLL_FM_L1SYS_ICC_CLOCK  5
#define PLL_FM_L1SYS_IMC_CLOCK  6
#define PLL_FM_L1SYS_EQ_CLOCK   7
#define PLL_FM_L1SYS_BRP_CLOCK  8
#define PLL_FM_L1MCU_CLOCK  	9
#define PLL_FM_AMR7_CLOCK  		10
#define PLL_FM_PSMCU_CLOCK  	11
#define PLL_FM_BUS_CLOCK  		17
#define PLL_FM_IMC_PLL  		26
#define PLL_FM_L1MCU_PLL  		29
#define PLL_FM_PSMCU_PLL  		30

kal_uint32 PLL_FrequencyMeter_GetFreq(kal_uint32 index)
{
	kal_uint32 count = 2000, output = 0;
	*REG_MDTOP_CLKSW_FREQ_METER_CTL = 0; //reset frequency meter
	*REG_MDTOP_CLKSW_CKMON_CTL = 0x300 | index; //divided by 8 and select source
	*REG_MDTOP_CLKSW_FREQ_METER_XTAL_CNT = PLL_FM_WIMDOW;
	*REG_MDTOP_CLKSW_FREQ_METER_CTL = 1; //enable frequency meter

	//wait measure done or timeout
	while(((*REG_MDTOP_CLKSW_FREQ_METER_CTL)&(1<<1))==0)
	{
		count--;
		if(count == 0)
			break;
	}

	if(count == 0)
		return 0;

	output = *REG_MDTOP_CLKSW_FREQ_METER_CKMON_CNT * 26 * 8 / PLL_FM_WIMDOW;

	return output;
}


kal_uint32 g_clock_intf;
kal_uint32 g_clock_md2g;
kal_uint32 g_clock_dfe;
kal_uint32 g_clock_cmp;
kal_uint32 g_clock_icc;
kal_uint32 g_clock_imc;
kal_uint32 g_clock_eq;
kal_uint32 g_clock_brp;
kal_uint32 g_clock_psmcu;
kal_uint32 g_clock_l1mcu;
kal_uint32 g_clock_arm7;
kal_uint32 g_clock_bus;

kal_uint32 g_pll_imc;
kal_uint32 g_pll_psmcu;
kal_uint32 g_pll_l1mcu;

void PLL_exception_dump(void)
{
	g_clock_intf = PLL_FrequencyMeter_GetFreq(PLL_FM_L1SYS_INTF_CLOCK);
	g_clock_md2g = PLL_FrequencyMeter_GetFreq(PLL_FM_L1SYS_MD2G_CLOCK);
	g_clock_dfe = PLL_FrequencyMeter_GetFreq(PLL_FM_L1SYS_DFE_CLOCK);
	g_clock_cmp = PLL_FrequencyMeter_GetFreq(PLL_FM_L1SYS_CMP_CLOCK);
	g_clock_icc = PLL_FrequencyMeter_GetFreq(PLL_FM_L1SYS_ICC_CLOCK);
	g_clock_imc = PLL_FrequencyMeter_GetFreq(PLL_FM_L1SYS_IMC_CLOCK);
	g_clock_eq = PLL_FrequencyMeter_GetFreq(PLL_FM_L1SYS_EQ_CLOCK);
	g_clock_brp = PLL_FrequencyMeter_GetFreq(PLL_FM_L1SYS_BRP_CLOCK);
	g_clock_psmcu = PLL_FrequencyMeter_GetFreq(PLL_FM_PSMCU_CLOCK);
	g_clock_l1mcu = PLL_FrequencyMeter_GetFreq(PLL_FM_L1MCU_CLOCK);
	g_clock_arm7 = PLL_FrequencyMeter_GetFreq(PLL_FM_AMR7_CLOCK);
	g_clock_bus = PLL_FrequencyMeter_GetFreq(PLL_FM_BUS_CLOCK);
	g_pll_imc = PLL_FrequencyMeter_GetFreq(PLL_FM_IMC_PLL);
	g_pll_psmcu = PLL_FrequencyMeter_GetFreq(PLL_FM_PSMCU_PLL);
	g_pll_l1mcu = PLL_FrequencyMeter_GetFreq(PLL_FM_L1MCU_PLL);
}

#endif /* should NOT be compiled on MODIS */
