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
 * 06 17 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * Fixed build error.
 *
 * 06 16 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PDN_LITE_GPT rename to PDN_LITE_GPTM as owner request.
 *
 * 06 16 2015 linson.du
 * [MOLY00120753] [Jade/91]: MDPLL implement
 * PDN driver update, remove some invalid enum.
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
#define __DRVPDN_INLINE_MT6755_H__

/*******************************************************************************
 * Locally Used Options
 *******************************************************************************/
#define INTERRUPT_PROTECT       1

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "intrCtrl.h"
#include "pdn_hw_MT6755_series.h"

typedef enum {
   
   PDN_SOE,
   PDN_BUS_REC,
   PDN_MDINFRA_BUSMON,
   PDN_UART2,
   PDN_UART1,
   PDN_TRACE,
   PDN_MDPERI_MISCREG,
   PDN_PCCIF,
   PDN_MDEINT,
   PDN_CFGCTL,
   PDN_RGU,
   PDN_A7OSTIMER,
   PDN_OSTIMER,
   PDN_TOPSM,
   PDN_MDCIRQ,
   PDN_ECT,
   PDN_USIM2,
   PDN_USIM1,
   PDN_LITE_GPTM,
   PDN_GPT,
   PDN_I2C,
   PDN_GDMA,
   PDN_UART0,
   PDN_MAX_DEV

} PDN_DEVICE;

#define DRVPDN_REG(addr)                            *(volatile kal_uint32 *)(addr)
#define DRVPDN_MDINFRA_OFF(module)             DRVPDN_REG(MD_INFRA_CKEN) &=~ (CG_ ## module)
#define DRVPDN_MDPERI_OFF(module)             DRVPDN_REG(MD_PERI_CKEN) &=~ (CG_ ## module)

#define DRVPDN_MDINFRA_ON(module)             DRVPDN_REG(MD_INFRA_CKEN) |= (CG_ ## module)
#define DRVPDN_MDPERI_ON(module)             DRVPDN_REG(MD_PERI_CKEN) |= (CG_ ## module)

#define DRVPDN_MDINFRA_STS(module)             DRVPDN_REG(MD_INFRA_CKEN) & (CG_ ## module)
#define DRVPDN_MDPERI_STS(module)             DRVPDN_REG(MD_PERI_CKEN) & (CG_ ## module)

DRVPDN_INLINE_MODIFIER DRVPDN_INLINE void PDN_SET(PDN_DEVICE dev)
{
   #if INTERRUPT_PROTECT
   kal_uint32 mask;
   mask = SaveAndSetIRQMask();
   #endif
    
    switch (dev)
    {
      case PDN_SOE:
            DRVPDN_MDINFRA_OFF(SOE);
            break;
      case PDN_BUS_REC:
            DRVPDN_MDINFRA_OFF(BUS_REC);
            break;
      case PDN_MDINFRA_BUSMON:
            DRVPDN_MDINFRA_OFF(MDINFRA_BUSMON);
            break;
      case PDN_UART2:
            DRVPDN_MDINFRA_OFF(UART2);
            break;
      case PDN_UART1:
            DRVPDN_MDINFRA_OFF(UART1);
            break;
      case PDN_TRACE:
            DRVPDN_MDPERI_OFF(TRACE);
            break;
      case PDN_MDPERI_MISCREG:
            DRVPDN_MDPERI_OFF(MDPERI_MISCREG);
            break;
      case PDN_PCCIF:
            DRVPDN_MDPERI_OFF(PCCIF);
            break; 
      case PDN_MDEINT:
            DRVPDN_MDPERI_OFF(MDEINT);
            break;
      case PDN_CFGCTL:
            DRVPDN_MDPERI_OFF(CFGCTL);
            break;
      case PDN_RGU:
            DRVPDN_MDPERI_OFF(RGU);
            break;
      case PDN_A7OSTIMER:
            DRVPDN_MDPERI_OFF(A7OSTIMER);
            break;
      case PDN_OSTIMER:
            DRVPDN_MDPERI_OFF(OSTIMER);
            break;
      case PDN_TOPSM:
            DRVPDN_MDPERI_OFF(TOPSM);
            break;
      case PDN_MDCIRQ:
            DRVPDN_MDPERI_OFF(MDCIRQ);
            break;
      case PDN_ECT:
            DRVPDN_MDPERI_OFF(ECT);
            break;
      case PDN_USIM2:
            DRVPDN_MDPERI_OFF(USIM2);
            break;
      case PDN_USIM1:
            DRVPDN_MDPERI_OFF(USIM1);
            break;
      case PDN_LITE_GPTM:
            DRVPDN_MDPERI_OFF(LITE_GPT);
            break; 
      case PDN_GPT:
            DRVPDN_MDPERI_OFF(GPT);
            break;
      case PDN_I2C:
            DRVPDN_MDPERI_OFF(I2C);
            break;
      case PDN_GDMA:
            DRVPDN_MDPERI_OFF(GDMA);
            break;
      case PDN_UART0:
            DRVPDN_MDPERI_OFF(UART0);
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
      case PDN_SOE:
            DRVPDN_MDINFRA_ON(SOE);
            break;
      case PDN_BUS_REC:
            DRVPDN_MDINFRA_ON(BUS_REC);
            break;
      case PDN_MDINFRA_BUSMON:
            DRVPDN_MDINFRA_ON(MDINFRA_BUSMON);
            break;
      case PDN_UART2:
            DRVPDN_MDINFRA_ON(UART2);
            break;
      case PDN_UART1:
            DRVPDN_MDINFRA_ON(UART1);
            break;
      case PDN_TRACE:
            DRVPDN_MDPERI_ON(TRACE);
            break;
      case PDN_MDPERI_MISCREG:
            DRVPDN_MDPERI_ON(MDPERI_MISCREG);
            break;
      case PDN_PCCIF:
            DRVPDN_MDPERI_ON(PCCIF);
            break; 
      case PDN_MDEINT:
            DRVPDN_MDPERI_ON(MDEINT);
            break;
      case PDN_CFGCTL:
            DRVPDN_MDPERI_ON(CFGCTL);
            break;
      case PDN_RGU:
            DRVPDN_MDPERI_ON(RGU);
            break;
      case PDN_A7OSTIMER:
            DRVPDN_MDPERI_ON(A7OSTIMER);
            break;
      case PDN_OSTIMER:
            DRVPDN_MDPERI_ON(OSTIMER);
            break;
      case PDN_TOPSM:
            DRVPDN_MDPERI_ON(TOPSM);
            break;
      case PDN_MDCIRQ:
            DRVPDN_MDPERI_ON(MDCIRQ);
            break;
      case PDN_ECT:
            DRVPDN_MDPERI_ON(ECT);
            break;
      case PDN_USIM2:
            DRVPDN_MDPERI_ON(USIM2);
            break;
      case PDN_USIM1:
            DRVPDN_MDPERI_ON(USIM1);
            break;
      case PDN_LITE_GPTM:
            DRVPDN_MDPERI_ON(LITE_GPT);
            break; 
      case PDN_GPT:
            DRVPDN_MDPERI_ON(GPT);
            break;
      case PDN_I2C:
            DRVPDN_MDPERI_ON(I2C);
            break;
      case PDN_GDMA:
            DRVPDN_MDPERI_ON(GDMA);
            break;
      case PDN_UART0:
            DRVPDN_MDPERI_ON(UART0);
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
      case PDN_SOE:
            ret = DRVPDN_MDINFRA_STS(SOE);
            break;
      case PDN_BUS_REC:
            ret = DRVPDN_MDINFRA_STS(BUS_REC);
            break;
      case PDN_MDINFRA_BUSMON:
            ret = DRVPDN_MDINFRA_STS(MDINFRA_BUSMON);
            break;
      case PDN_UART2:
            ret = DRVPDN_MDINFRA_STS(UART2);
            break;
      case PDN_UART1:
            ret = DRVPDN_MDINFRA_STS(UART1);
            break;
      case PDN_TRACE:
            ret = DRVPDN_MDPERI_STS(TRACE);
            break;
      case PDN_MDPERI_MISCREG:
            ret = DRVPDN_MDPERI_STS(MDPERI_MISCREG);
            break;
      case PDN_PCCIF:
            ret = DRVPDN_MDPERI_STS(PCCIF);
            break; 
      case PDN_MDEINT:
            ret = DRVPDN_MDPERI_STS(MDEINT);
            break;
      case PDN_CFGCTL:
            ret = DRVPDN_MDPERI_STS(CFGCTL);
            break;
      case PDN_RGU:
            ret = DRVPDN_MDPERI_STS(RGU);
            break;
      case PDN_A7OSTIMER:
            ret = DRVPDN_MDPERI_STS(A7OSTIMER);
            break;
      case PDN_OSTIMER:
            ret = DRVPDN_MDPERI_STS(OSTIMER);
            break;
      case PDN_TOPSM:
            ret = DRVPDN_MDPERI_STS(TOPSM);
            break;
      case PDN_MDCIRQ:
            ret = DRVPDN_MDPERI_STS(MDCIRQ);
            break;
      case PDN_ECT:
            ret = DRVPDN_MDPERI_STS(ECT);
            break;
      case PDN_USIM2:
            ret = DRVPDN_MDPERI_STS(USIM2);
            break;
      case PDN_USIM1:
            ret = DRVPDN_MDPERI_STS(USIM1);
            break;
      case PDN_LITE_GPTM:
            ret = DRVPDN_MDPERI_STS(LITE_GPT);
            break; 
      case PDN_GPT:
            ret = DRVPDN_MDPERI_STS(GPT);
            break;
      case PDN_I2C:
            ret = DRVPDN_MDPERI_STS(I2C);
            break;
      case PDN_GDMA:
            ret = DRVPDN_MDPERI_STS(GDMA);
            break;
      case PDN_UART0:
            ret = DRVPDN_MDPERI_STS(UART0);
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
