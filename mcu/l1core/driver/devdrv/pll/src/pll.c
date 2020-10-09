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
 * 02 24 2016 linson.du
 * [MOLY00166240] [Olympus]: driver porting
 * Olympus Pll driver porting.
 *
 * 10 26 2015 linson.du
 * [MOLY00146768] [MODEM L1 DVFS] IMCPLL initial setting
 * IMC DVFS init re-org.
 *
 * 08 04 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PLL/PDN driver porting for Everest.
 *
 * 06 25 2015 linson.du
 * [MOLY00122918] [MT6755][BRINGUP_FIRSTCALL][SS]
 * Update PLL driver for Jade SB bring up.
 *
 * 06 18 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Update PLL driver.
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

	// modify PSMCU2EMI bus divider from 3 to 4.
	*R_PSMCU_AO_CLK_CTL = *R_PSMCU_AO_CLK_CTL | 0x83;
		
	*R_L1MCU_PWR_AWARE |=	(1<<16); //lock dcm bus
	*R_L1AO_PWR_AWARE |=	(1<<16); //lock dcm bus
	*R_BUSL2DCM_CON3 = 0x0001FDE7; //busL2 DCM div 8/normal div 1/ clkslow_en/clock from PLL /debounce enable/ debounce time 7T 
	*R_L1MCU_DCM_CON = 0x0000FDEF; // DCM div 16/normal div 1/clkslow_en/ clock from PLL / dcm enable /debounce enable /debounce time 15T
	*R_L1MCU_DCM_CON2 = 0x0; //DCM config toggle = 0
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
	  *R_CLKSEL_CTL |=0x3fe00;

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
		
	  /*PSMCU DCM*/
	  *R_PSMCU_DCM_CTL0 |= 0x00F1F006;		  // Bit 26-20: DBC_CNT
							  //Bit 16-12: IDLE_FSEL
							  //Bit 2: DBC_EN
							  //Bit 1: DCM_EN
	  *R_PSMCU_DCM_CTL1 |= 0x26;		  // Bit  5: APB_LOAD_TOG
							  // Bit  4-0: APB_SEL
	
	  /*ARM7 DCM*/
	  *R_ARM7_DCM_CTL0 |= 0x00F1F006;		// Bit 26-20: DBC_CNT
							  //Bit 16-12: IDLE_FSEL
							  //Bit 2: DBC_EN
							  //Bit 1: DCM_EN
	  *R_ARM7_DCM_CTL1 |= 0x26; 			// Bit	5: APB_LOAD_TOG
							// Bit	4-0: APB_SEL
	
	  *R_DCM_SHR_SET_CTL = 0x00014110;		  // Bit  16: BUS_PLL_SWITCH
							  // Bit  15: BUS_QUARTER_FREQ_SEL
							  // Bit  14: BUS_SLOW_FREQ
							  // Bit 12-8: HFBUS_SFSEL
							  // Bit   4-0: HFBUS_FSEL
	// /*BUS DCM*/
	// *R_BUS_DCM_CTL0 |= 0x2;			// Bit	  1: DCM_EN
	// *R_BUS_DCM_CTL1 |= 0x3F; 		// Bit	4-0: APB_SEL
	//									// Bit	  5: APB_LOAD_TOG
	//
	// /*L1MCU DCM*/
	// *R_L1MCU_DCM_CTL0 |= 0x2;		// Bit	  1: DCM_EN
	// *R_L1MCU_DCM_CTL1 |= 0x3F;		// Bit	4-0: APB_SEL
	//									// Bit	  5: APB_LOAD_TOG
	
	  /*LTEL2 BUS DCM*/
	  *R_LTEL2_BUS_DCM_CTL |= 0x1;			// Bit	0: DCM_EN
	
	  /*MDDMA BUS DCM*/
	  *R_MDDMA_BUS_DCM_CTL |= 0x1;			  // Bit  0: DCM_EN
	
	  /*MDREG BUS DCM*/
	  *R_MDREG_BUS_DCM_CTL |= 0x1;			  // Bit  0: DCM_EN
	
	  /*MODULE BUS2X DCM*/
	  *R_MODULE_BUS2X_DCM_CTL |= 0x1;		// Bit	0: DCM_EN
	
	  /*MODULE BUS1X DCM*/
	  *R_MODULE_BUS1X_DCM_CTL |= 0x1;			// Bit	0: DCM_EN
	
	  /*MD perisys AHB master/slave DCM enable*/
	  *R_MDINFRA_CKEN |= 0xC000001F;		// Bit	31: PSPERI_MAS_DCM_EN
							  // Bit  30: PSPERI_SLV_DCM_EN
							  // Bit  4: SOE_CKEN
							  // Bit  3: BUSREC_CKEN
							  // Bit  2: BUSMON_CKEN
							  // Bit  1: MDUART2_CKEN
							  // Bit  0: MDUART1_CKEN
	
	  /*MD debugsys DCM enable*/
	  *R_MDPERI_CKEN |= 0x8003FFFF; 		// Bit	31: MDDBGSYS_DCM_EN
							  // Bit  21: USB0_LINK_CK_SEL
							  // Bit  20: USB1_LINK_CK_SEL
							  // Bit  17: TRACE_CKEN
							  // Bit  16: MDPERI_MISCREG_CKEN
							  // Bit  15: PCCIF_CKEN
							  // Bit  14: MDEINT_CKEN
							  // Bit  13: MDCFGCTL_CKEN
							  // Bit  12: MDRGU_CKEN
							  // Bit  11: A7OST_CKEN
							  // Bit  10: MDOST_CKEN
							  // Bit  9: MDTOPSM_CKEN
							  // Bit  8: MDCIRQ_CKEN
							  // Bit  7: MDECT_CKEN
							  // Bit  6: USIM2_CKEN
							  // Bit  5: USIM1_CKEN
							  // Bit  4: GPTMLITE_CKEN
							  // Bit  3: MDGPTM_CKEN
							  // Bit  2: I2C_CKEN
							  // Bit  1: MDGDMA_CKEN
							  // Bit  0: MDUART0_CKEN
	
	  /*SET MDRGU, MDTOPSM, MDOSTIMER, MDTOPSM DCM MASK*/
	  *R_MDPERI_DCM_MASK |= 0x00001E00; 	  // Bit  12: MDRGU_DCM_MASK
							  // Bit  11: A7OST_DCM_MASK
							  // Bit  10: MDOST_DCM_MASK
							  // Bit  9: MDTOPSM_DCM_MASK
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
#endif //#if defined(MT6755)
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
#if defined(__L1CORE_ONLY__)

#if defined(TK6291)	
    INT_SetPLL_TK6291();  
#elif defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
    if( MD_PLL_MAGIC_NUM == *MD_GLOBAL_CON_DUMMY )
    {
		// AP have been init MD PLL setting.  
		*R_L1_PMS &=~ 0x6; //Clear PMS which AP has set
    }
	else
	{
		INT_SetPLL_JADE();
	}	
#endif
#endif //defined(__L1CORE_ONLY__)
}

#define PLL_OK 0
#define IMC_INVALID_TABLE_NUMBER 0xFFFF0001
#define IMC_INVALID_PARAMETER_0  0xFFFF0002
#define IMC_INVALID_PARAMETER_1  0xFFFF0003

#define IMC_SIGNOFF_FREQUENCY 370000

#define IMC_PLL_16bit(khz)   (((khz)*512*8/26000)&0xFFFF)
#define IMC_PLL_21bit(mhz)   (((mhz)*16384*8/26)&0x1FFFFF)

/*************************************************************************
 * FUNCTION
 *  PLL_IMC_DVFSTableSet
 *
 * DESCRIPTION
 *  This function is to set DVFS table for IMCPLL.
 *
 * PARAMETERS
 *  table_number: index of table
 *  freq_0_khz: unit is KHz
 *  freq_1_khz: unit is KHz
 *
 * RETURNS
 *  0 means OK, not 0 means error code.
 *************************************************************************/
kal_uint32 PLL_IMC_DVFSTableSet(kal_uint32 table_number, kal_uint32 freq_0_khz, kal_uint32 freq_1_khz)
{
#if !defined(TK6291)

	kal_uint32 left=0, right=0;
	if((table_number==0)||(table_number > 4))
		return IMC_INVALID_TABLE_NUMBER;

	if(freq_0_khz > IMC_SIGNOFF_FREQUENCY)
		return IMC_INVALID_PARAMETER_0;
	
	if(freq_1_khz > IMC_SIGNOFF_FREQUENCY)
		return IMC_INVALID_PARAMETER_0;

	right = IMC_PLL_16bit(freq_0_khz);
	left = IMC_PLL_16bit(freq_1_khz);

	switch(table_number)
	{
		case IMC_TABLE_GEAR01:
			*R_IMCPLL_FHCTL2 = (left<<16)|right;
			break;
		case IMC_TABLE_GEAR23:
			*R_IMCPLL_FHCTL3 = (left<<16)|right;
			break;
		case IMC_TABLE_GEAR45:
			*R_IMCPLL_FHCTL4 = (left<<16)|right;
			break;
		case IMC_TABLE_GEAR67:
			*R_IMCPLL_FHCTL5 = (left<<16)|right;
			break;
		default:
			break;
	}
#endif //#if !defined(TK6291)		
	return PLL_OK;	
}

/*************************************************************************
 * FUNCTION
 *  PLL_IMC_DVFSControl
 *
 * DESCRIPTION
 *  This function is to set IMC DVFS control register.
 *
 * PARAMETERS
 *  plloff_freq_mhz: unit is MHz
 *  restore_mode: 0 means disable, not 0 means enable
 *
 * RETURNS
 *************************************************************************/

void PLL_IMC_DVFSControl(kal_uint32 plloff_freq_mhz, kal_uint32 restore_mode )
{
#if !defined(TK6291)
	*R_IMCPLL_FHCTL0  = 0x006D3381; //set imcpll to hw dvfs mode
	
	if(plloff_freq_mhz)
	{
		*R_IMCPLL_CTL0	= (IMC_PLL_21bit(plloff_freq_mhz))|0x80000000;
	}

	if(restore_mode)
	{
		*R_IMCPLL_FHCTL0  = (*R_IMCPLL_FHCTL0)|(1<<21); //restore mode enable
	}
	else
	{
		*R_IMCPLL_FHCTL0  = (*R_IMCPLL_FHCTL0)& (~(1<<21)); //restore mode disable
	}
	
	*R_PLL_FH_CTL     = 0x80000000; //reload gear hopping setting
#endif //#if !defined(TK6291)	
}



#endif /* should NOT be compiled on MODIS */
