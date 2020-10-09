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
 *   drvpdn_inline_tk6291.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   PDN Driver (C Inline Implementation) for TK6291
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
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

#ifndef __DRVPDN_INLINE_TK6291_H__
#define __DRVPDN_INLINE_TK6291_H__

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
#include "pdn_hw_tk6291_series.h"

typedef enum {
    PDN_ATB,
	PDN_UART ,
	PDN_ABM ,
	PDN_GDMA ,
	PDN_FCS ,
	PDN_PCMON ,
	PDN_BUSMON ,
	PDN_ELM,
	PDN_MCCO,
	
	PDN_MAX_DEV
} PDN_DEVICE;


typedef enum {
    //PDN_ABM,
    PDN_LTEL2,
    PDN_TDD,
    PDN_MODEM3G,
    PDN_MODEM2G,
    PDN_MDCAIF,
    PDN_CR4PCMON,
    PDN_MDMCU_BUSMON,
    PDN_MDINFRA_BUSMON,
    PDN_RTC,
    PDN_MDCIRQ,
    PDN_MDGDMA,
    PDN_GPIO,
    PDN_MDGPTM,
    PDN_LED,
    PDN_I2C,
    PDN_SUART1,
    PDN_SUART0,
    PDN_MDUART,
    PDN_USIM2,
    PDN_USIM1,
    PDN_BOOTROM,
    PDN_SDIO,
    PDN_EHPI_SLAVE,
    PDN_APPERI_BUSMON,
    PDN_APMCU_BUSMON,
    PDN_APUART,
    PDN_APGDMA,
    PDN_APGPTM,
    PDN_CLDMA,
    PDN_CCIF,
    PDN_IPSEC,
    PDN_NLI,
    PDN_NFI,
    PDN_PFC,
    PDN_EHPI_MASTER,

    PDN_NIC,
    PDN_SPI,
    PDN_MSDC1,
    PDN_MSDC0,
    PDN_U2,
    PDN_U3,

    //PDN_ATB,
    PDN_BYCACC,
    PDN_AFC3G,
    PDN_WCDMATIMER,
    PDN_BPI3G,
    PDN_BSI3G,

    PDN_GCU,
    //PDN_FCS,
    PDN_DIV,
    PDN_AFC2G_T,
    PDN_BPI2G_T,
    PDN_BSI2G_T,
    PDN_TDMA,

    PDN_AFC2G,
    PDN_BPI2G,
    PDN_BSI2G,

    PDN_AHB2DSPIO,
    PDN_IRDBG,
    PDN_TXBUF,
    PDN_RXBUF,
    PDN_IRDMA,
    PDN_GCC,

    PDN_BFE,
    PDN_VAFE,
    PDN_APC_PRE,

    PDN_APC,

    

} PDN_dummy;


typedef enum {
    IPCG_ARM7,
    IPCG_DBGSYS,
    IPCG_CA7,
    IPCG_TRACE,

    IPCG_NIC,
    IPCG_SPI,
    IPCG_MSDC1,
    IPCG_MSDC0,
    IPCG_U2,
    IPCG_U3,

    IPCG_MAX_DEV

} IPCG_DEVICE;





#define DRVPDN_REG(addr)                            *(volatile kal_uint32 *)(addr)
#define DRVPDN_L1MCU_OFF(module)             DRVPDN_REG(MD_L1MCU_CG_SET) = (CG_ ## module)	
#define DRVPDN_L1MCU_ON(module)              DRVPDN_REG(MD_L1MCU_CG_CLR) = (CG_ ## module)	
#define DRVPDN_L1MCU_STS(module)             DRVPDN_REG(MD_L1MCU_CG_CON) & (CG_ ## module)






#define DRVPDN_REG(addr)                            *(volatile kal_uint32 *)(addr)
#define DRVPDN_MDPLL1_CTL2_OFF(module)            DRVPDN_REG(MD_L1_MDPLL_CTL2) &=~ (CG_ ## module)
#define DRVPDN_MDPLL1_CTL2_ON(module)             DRVPDN_REG(MD_L1_MDPLL_CTL2) |= (CG_ ## module)
#define DRVPDN_MDPLL1_CTL2_STS(module)            DRVPDN_REG(MD_L1_MDPLL_CTL2) & (CG_ ## module)

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
	  case PDN_MCCO:
		    DRVPDN_MDPLL1_CTL2_OFF(MCCO);
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
	   case PDN_MCCO:
			 DRVPDN_MDPLL1_CTL2_ON(MCCO);
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
	   case PDN_MCCO:
			 ret = DRVPDN_MDPLL1_CTL2_STS(MCCO);
			 break;  
	   case PDN_MAX_DEV:			  
			 break; 
	
	}
	
	#if INTERRUPT_PROTECT
	RestoreIRQMask(mask);
	#endif

    return ret;
}


DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void IPCG_SET(IPCG_DEVICE dev)
{
    //TODO: hw & sw not implement yet
}


DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void IPCG_CLR(IPCG_DEVICE dev)
{
    //TODO: hw & sw not implement yet
}


DRVPDN_INLINE_MODIFIER DRVPDN_INLINE kal_uint32 IPCG_STS(IPCG_DEVICE dev)
{
    //TODO: hw & sw not implement yet
    kal_uint32 ret = 0;
    return ret;
}

#endif /* !__DRVPDN_INLINE_TK6291_H__ */
