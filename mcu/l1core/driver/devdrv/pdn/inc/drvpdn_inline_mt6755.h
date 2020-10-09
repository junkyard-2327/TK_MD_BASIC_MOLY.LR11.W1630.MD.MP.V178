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
 *   drvpdn_inline_mt6755.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   PDN Driver (C Inline Implementation) for MT6755
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 06 16 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Fix PDN build error.
 *
 * 06 16 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PDN_LITE_GPT rename to PDN_LITE_GPTM as owner request.
 *
 * 06 16 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Fix build error.
 *
 * 06 16 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PDN driver update, remove some invalid enum.
 *
 * 04 08 2015 linson.du
 * [MOLY00106281] [UMOLY]: ELM driver porting
 * Roll back pdn driver.
 *
 * 03 18 2015 linson.du
 * [MOLY00095411] [TK6291]: PLL driver porting
 * PDN driver porting.
 *
 * 09 19 2014 tungchieh.tsai
 * [MOLY00079245] [TK6291][UMOLY][SYSTEM SERVICE][PDN] Rename
 *
 ****************************************************************************/

#ifndef __DRVPDN_INLINE_MT6755_H__
#define __DRVPDN_INLINEMT6755_H__

/*******************************************************************************
 * Locally Used Options
 *******************************************************************************/
#define EXTRA_EXPORT            0
#define INTERRUPT_PROTECT       1
#define DISABLE_PDN_FOR_6291M   0 // Temporary for Issue Clarification

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "intrCtrl.h"
#include "pdn_hw_mt6755_series.h"

typedef enum {
    PDN_ATB,
	PDN_UART ,
	PDN_ABM ,
	PDN_GDMA ,
	PDN_FCS ,
	PDN_PCMON ,
	PDN_BUSMON ,
	PDN_ELM,	
	PDN_INFT_CLK,
	PDN_CIRQ,
	PDN_OSTIMER,
	PDN_LITE_GPTM,
	PDN_GPT,
	PDN_FM,
	PDN_PTP_CTRL,
	PDN_LTE_SLP,
	PDN_IDC_CTRL,
	PDN_LTE_TIMER,
	PDN_FDD_TIMER,
	PDN_BSI_TOP,
	PDN_TDMA_SLP,
	PDN_TDD_SLP,
	PDN_BPI_TOP,
	PDN_IRDBG,	
	PDN_MAX_DEV
} PDN_DEVICE;




#define DRVPDN_REG(addr)                            *(volatile kal_uint32 *)(addr)
#define DRVPDN_L1MCU_OFF(module)             DRVPDN_REG(MD_L1MCU_CG_SET) = (CG_ ## module)	
#define DRVPDN_L1MCU_ON(module)              DRVPDN_REG(MD_L1MCU_CG_CLR) = (CG_ ## module)	
#define DRVPDN_L1MCU_STS(module)             DRVPDN_REG(MD_L1MCU_CG_CON) & (CG_ ## module)

#define DRVPDN_MDPLL1_CTL2_OFF(module)            DRVPDN_REG(MD_L1_MDPLL_CTL2) &=~ (CG_ ## module)
#define DRVPDN_MDPLL1_CTL2_ON(module)             DRVPDN_REG(MD_L1_MDPLL_CTL2) |= (CG_ ## module)
#define DRVPDN_MDPLL1_CTL2_STS(module)            DRVPDN_REG(MD_L1_MDPLL_CTL2) & (CG_ ## module)

#define DRVPDN_L1AO_PERI_OFF(module)             DRVPDN_REG(MD_L1AO_PERI_CG_SET) = (CG_ ## module)	
#define DRVPDN_L1AO_PERI_ON(module)              DRVPDN_REG(MD_L1AO_PERI_CG_CRL) = (CG_ ## module)	
#define DRVPDN_L1AO_PERI_STS(module)             DRVPDN_REG(MD_L1AO_PERI_CG_CON) & (CG_ ## module)

#define DRVPDN_MD2GSYS_IRD_OFF(module)             DRVPDN_REG(MD_MD2GSYS_IRDBG_CG_SET) = (CG_ ## module)	
#define DRVPDN_MD2GSYS_IRD_ON(module)              DRVPDN_REG(MD_MD2GSYS_IRDBG_CG_CRL) = (CG_ ## module)	
#define DRVPDN_MD2GSYS_IRD_STS(module)             DRVPDN_REG(MD_MD2GSYS_IRDBG_CG_CON) & (CG_ ## module)



DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void PDN_SET(PDN_DEVICE dev)
{

   #if INTERRUPT_PROTECT
   kal_uint32 mask;
   mask = SaveAndSetIRQMask();
   #endif
   switch (dev)
   {
      case PDN_ATB:
            DRVPDN_L1MCU_OFF(ATB);
            break;
	  case PDN_UART:
            DRVPDN_L1MCU_OFF(UART);
            break;
	  case PDN_ABM:
            DRVPDN_L1MCU_OFF(ABM);
            break;		
	  case PDN_GDMA:
		    DRVPDN_L1MCU_OFF(GDMA);
		    break;
	  case PDN_FCS:
		    DRVPDN_L1MCU_OFF(FCS);
		    break;
	  case PDN_PCMON:
            DRVPDN_L1MCU_OFF(PCMON);
            break;
	  case PDN_BUSMON:
            DRVPDN_L1MCU_OFF(BUSMON);
            break;		
	  case PDN_ELM:
		    DRVPDN_L1MCU_OFF(ELM);
		    break;
      case PDN_INFT_CLK:
		    DRVPDN_L1AO_PERI_OFF(INFT_CLK);
		    break;
	  case PDN_CIRQ:
		    DRVPDN_L1AO_PERI_OFF(CIRQ);
		    break;
	  case PDN_OSTIMER:
		    DRVPDN_L1AO_PERI_OFF(OSTIMER);
		    break;
	  case PDN_LITE_GPTM:
		    DRVPDN_L1AO_PERI_OFF(GPT_LITE);
		    break;
	  case PDN_GPT:
		    DRVPDN_L1AO_PERI_OFF(GPT);
		    break;		
	  case PDN_FM:
		    DRVPDN_L1AO_PERI_OFF(FM);
		    break;
	  case PDN_PTP_CTRL:
		    DRVPDN_L1AO_PERI_OFF(PTP_CTRL);
		    break;
	  case PDN_LTE_SLP:
		    DRVPDN_L1AO_PERI_OFF(LTE_SLP);
		    break;
	  case PDN_IDC_CTRL:
		    DRVPDN_L1AO_PERI_OFF(IDC_CTRL);
		    break;
	  case PDN_LTE_TIMER:
		    DRVPDN_L1AO_PERI_OFF(LTE_TIMER);
		    break;
	  case PDN_FDD_TIMER:
		    DRVPDN_L1AO_PERI_OFF(FDD_TIMER);
		    break;
	  case PDN_BSI_TOP:
		    DRVPDN_L1AO_PERI_OFF(BSI_TOP);
		    break;
	  case PDN_TDMA_SLP:
		    DRVPDN_L1AO_PERI_OFF(TDMA_SLP);
		    break;
	  case PDN_TDD_SLP:
		    DRVPDN_L1AO_PERI_OFF(TDD_SLP);
		    break;
	  case PDN_BPI_TOP:
		    DRVPDN_L1AO_PERI_OFF(BPI_TOP);
		    break;
      case PDN_IRDBG:
		    DRVPDN_MD2GSYS_IRD_OFF(IRDBG);
		    break;		
	  case PDN_MAX_DEV:            
            break;	
   }
   #if INTERRUPT_PROTECT
   RestoreIRQMask(mask);
   #endif
}

DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void PDN_CLR(PDN_DEVICE dev)
{
	#if INTERRUPT_PROTECT
	kal_uint32 mask;
	mask = SaveAndSetIRQMask();
	#endif
	switch (dev)
	{
	   case PDN_ATB:
			 DRVPDN_L1MCU_ON(ATB);
			 break;
	   case PDN_UART:
			 DRVPDN_L1MCU_ON(UART);
			 break;
	   case PDN_ABM:
			 DRVPDN_L1MCU_ON(ABM);
			 break; 	 
	   case PDN_GDMA:
			 DRVPDN_L1MCU_ON(GDMA);
			 break;
	   case PDN_FCS:
			 DRVPDN_L1MCU_ON(FCS);
			 break;
	   case PDN_PCMON:
			 DRVPDN_L1MCU_ON(PCMON);
			 break;
	   case PDN_BUSMON:
			 DRVPDN_L1MCU_ON(BUSMON);
			 break; 	 
	   case PDN_ELM:
			 DRVPDN_L1MCU_ON(ELM);
			 break;
	   case PDN_INFT_CLK:
		     DRVPDN_L1AO_PERI_ON(INFT_CLK);
		     break;
	   case PDN_CIRQ:
		     DRVPDN_L1AO_PERI_ON(CIRQ);
		     break;
	   case PDN_OSTIMER:
		     DRVPDN_L1AO_PERI_ON(OSTIMER);
		     break;
	   case PDN_LITE_GPTM:
		     DRVPDN_L1AO_PERI_ON(GPT_LITE);
		     break;
	   case PDN_GPT:
		     DRVPDN_L1AO_PERI_ON(GPT);
		     break;		
	   case PDN_FM:
		     DRVPDN_L1AO_PERI_ON(FM);
		     break;
	   case PDN_PTP_CTRL:
		     DRVPDN_L1AO_PERI_ON(PTP_CTRL);
		     break;
	   case PDN_LTE_SLP:
		     DRVPDN_L1AO_PERI_ON(LTE_SLP);
		     break;
	   case PDN_IDC_CTRL:
		     DRVPDN_L1AO_PERI_ON(IDC_CTRL);
		     break;
	   case PDN_LTE_TIMER:
		     DRVPDN_L1AO_PERI_ON(LTE_TIMER);
		     break;
	   case PDN_FDD_TIMER:
		     DRVPDN_L1AO_PERI_ON(FDD_TIMER);
		     break;
	   case PDN_BSI_TOP:
		     DRVPDN_L1AO_PERI_ON(BSI_TOP);
		     break;
	   case PDN_TDMA_SLP:
		     DRVPDN_L1AO_PERI_ON(TDMA_SLP);
		     break;
	   case PDN_TDD_SLP:
		     DRVPDN_L1AO_PERI_ON(TDD_SLP);
		     break;
	   case PDN_BPI_TOP:
		     DRVPDN_L1AO_PERI_ON(BPI_TOP);
		     break;	 
	   case PDN_IRDBG:
		    DRVPDN_MD2GSYS_IRD_ON(IRDBG);
		    break;
	   case PDN_MAX_DEV:            
             break;	
	
	}
	#if INTERRUPT_PROTECT
	RestoreIRQMask(mask);
	#endif

}


DRVPDN_INLINE_MODIFIER DRVPDN_INLINE kal_uint32 PDN_STS(PDN_DEVICE dev)
{    
    kal_uint32 ret = 0;
	#if INTERRUPT_PROTECT
	kal_uint32 mask;
	mask = SaveAndSetIRQMask();
	#endif
	
	switch (dev)
	{
	   case PDN_ATB:
			 ret = DRVPDN_L1MCU_STS(ATB);
			 break;
	   case PDN_UART:
			 ret = DRVPDN_L1MCU_STS(UART);
			 break;
	   case PDN_ABM:
			 ret = DRVPDN_L1MCU_STS(ABM);
			 break; 	 
	   case PDN_GDMA:
			 ret = DRVPDN_L1MCU_STS(GDMA);
			 break;
	   case PDN_FCS:
			 ret = DRVPDN_L1MCU_STS(FCS);
			 break;
	   case PDN_PCMON:
			 ret = DRVPDN_L1MCU_STS(PCMON);
			 break;
	   case PDN_BUSMON:
			 ret = DRVPDN_L1MCU_STS(BUSMON);
			 break; 	 
	   case PDN_ELM:
			 ret = DRVPDN_L1MCU_STS(ELM);
			 break;
	   case PDN_INFT_CLK:
		     ret = DRVPDN_L1AO_PERI_STS(INFT_CLK);
		     break;
	   case PDN_CIRQ:
		     ret = DRVPDN_L1AO_PERI_STS(CIRQ);
		     break;
	   case PDN_OSTIMER:
		     ret = DRVPDN_L1AO_PERI_STS(OSTIMER);
		     break;
	   case PDN_LITE_GPTM:
		     ret = DRVPDN_L1AO_PERI_STS(GPT_LITE);
		     break;
	   case PDN_GPT:
		     ret = DRVPDN_L1AO_PERI_STS(GPT);
		     break;		
	   case PDN_FM:
		     ret = DRVPDN_L1AO_PERI_STS(FM);
		     break;
	   case PDN_PTP_CTRL:
		     ret = DRVPDN_L1AO_PERI_STS(PTP_CTRL);
		     break;
	   case PDN_LTE_SLP:
		     ret = DRVPDN_L1AO_PERI_STS(LTE_SLP);
		     break;
	   case PDN_IDC_CTRL:
		     ret = DRVPDN_L1AO_PERI_STS(IDC_CTRL);
		     break;
	   case PDN_LTE_TIMER:
		     ret = DRVPDN_L1AO_PERI_STS(LTE_TIMER);
		     break;
	   case PDN_FDD_TIMER:
		     ret = DRVPDN_L1AO_PERI_STS(FDD_TIMER);
		     break;
	   case PDN_BSI_TOP:
		     ret = DRVPDN_L1AO_PERI_STS(BSI_TOP);
		     break;
	   case PDN_TDMA_SLP:
		     ret = DRVPDN_L1AO_PERI_STS(TDMA_SLP);
		     break;
	   case PDN_TDD_SLP:
		     ret = DRVPDN_L1AO_PERI_STS(TDD_SLP);
		     break;
	   case PDN_BPI_TOP:
		     ret = DRVPDN_L1AO_PERI_STS(BPI_TOP);
		     break;
	   case PDN_IRDBG:
		    ret = DRVPDN_MD2GSYS_IRD_STS(IRDBG);
		    break;
	   case PDN_MAX_DEV:			  
			 break; 
	
	}
	
	#if INTERRUPT_PROTECT
	RestoreIRQMask(mask);
	#endif

    return ret;
}


#endif /* !__DRVPDN_INLINE_MT6755_H__ */
