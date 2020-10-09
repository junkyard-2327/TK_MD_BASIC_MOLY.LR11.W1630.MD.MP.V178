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


/*****************************************************************************
 *
 * Filename:
 * ---------
 *   intrCtrl_MT6757.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Definition for chipset interrupt table
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __INTRCTRL_MT6757_H__
#define __INTRCTRL_MT6757_H__


#include "reg_base.h"
#include "irqid.h"
#include "drv_features_gpt.h"
#include "drv_mdcirq.h"
#include "hisr_config.h"

/*******************************************************************************
 * Define CIRQ Registers 
 *******************************************************************************/


/*
 * CIRQ Interrupt Sources
 */

#define NUM_IRQ_SOURCES          (MAX_ISR_NUM)

#define INVALID_ISR_ID           (0xFF)

#define IRQ_OSTIMER_WAKEUP_CODE              PS_IRQID_OST                              
#define IRQ_ALC1_CODE                        PS_IRQID_FRC                              
#define IRQ_LMAC_RAR_CODE                    PS_IRQID_LMAC_RAR                         
#define IRQ_LMAC_EAR_CODE                    PS_IRQID_LMAC_EAR                         
#define IRQ_MD_WDT_CODE                      PS_IRQID_MDWDT                            
#define IRQ_NFI_CODE                         PS_IRQID_NFI                              
#define IRQ_L2COPRO_CODE                     PS_IRQID_L2COPRO                          
#define IRQ_GPTM1_CODE                       PS_IRQID_GPTM1                            
#define IRQ_GPTM2_CODE                       PS_IRQID_GPTM2                            
#define IRQ_GPTM3_CODE                       PS_IRQID_GPTM3                            
#define IRQ_GPTM4_CODE                       PS_IRQID_GPTM4                            
#define IRQ_GPTM5_CODE                       PS_IRQID_GPTM5                            
#define IRQ_GPTM6_CODE                       PS_IRQID_GPTM6                            
#define IRQ_UART1_CODE                       PS_IRQID_UART_MD                          
#define IRQ_UART2_CODE                       PS_IRQID_UART_SH0                         
#define IRQ_BUSMON_CODE                      PS_IRQID_BUSMON                           
#define IRQ_I2C_CODE                         PS_IRQID_I2C_0                            
#define IRQ_SIM_CODE                         PS_IRQID_USIM0                            
#define IRQ_SIM2_CODE                        PS_IRQID_USIM1                            
#define IRQ_UART3_CODE                       PS_IRQID_UART_SH1                         
#define IRQ_MDGDMA0_CODE                     PS_IRQID_MDGDMA0                          
#define IRQ_MDGDMA1_CODE                     PS_IRQID_MDGDMA1                          
#define IRQ_MDGDMA2_CODE                     PS_IRQID_MDGDMA2                          
#define IRQ_MDGDMA3_CODE                     PS_IRQID_MDGDMA3                          
#define IRQ_EINT0_CODE                       PS_IRQID_EINT0                            
#define IRQ_EINT1_CODE                       PS_IRQID_EINT1                            
#define IRQ_EINT2_CODE                       PS_IRQID_EINT2                            
#define IRQ_EINT3_CODE                       PS_IRQID_EINT3                            
#define IRQ_EINT_SHARE_CODE                  PS_IRQID_EINT_SHARE                       
#define IRQ_BUS_ERR_CODE                     PS_IRQID_BUS_ERR                          
#define IRQ_TOPSM_CODE                       PS_IRQID_TOPSM                            
#define IRQ_DEM_TRIG_CODE                    PS_IRQID_DEM_TRIG_INT                     
#define IRQ_SW_LISR1_CODE                    PS_IRQID_RSV_0                       
#define IRQ_SW_LISR2_CODE                    PS_IRQID_RSV_1                       
#define IRQ_SW_LISR3_CODE                    PS_IRQID_RSV_2                       
#define IRQ_SW_LISR4_CODE                    PS_IRQID_RSV_3                       
#define IRQ_SW_LISR5_CODE                    PS_IRQID_RSV_4                       
#define IRQ_SW_LISR6_CODE                    PS_IRQID_RSV_5                       
#define IRQ_SW_LISR7_CODE                    PS_IRQID_RSV_6                       
#define IRQ_SW_LISR8_CODE                    PS_IRQID_RSV_7                       
#define IRQ_A7WDT_CODE                       PS_IRQID_ARM7_WDT_INT                    
#define IRQ_PERFCNT_CODE                     PS_IRQID_PERFCNT                         
#define IRQ_PMU_CODE                         PS_IRQID_PMU                             
#define IRQ_ECT_CODE                         PS_IRQID_ECT                             
#define IRQ_L1_WDT_CODE                      PS_IRQID_PS_L1_WDT_INT                    
#define IRQ_ARM7_WDT_CODE                    PS_IRQID_PS_ARM7_WDT_INT                  
#define IRQ_CLDMA_CODE                       PS_IRQID_CLDMA                         
#define IRQ_ASM_CODE                         PS_IRQID_ADOE 
#define IRQ_MDLITE_GPTM_CODE			     PS_IRQID_MDLITE_GPTM
#define IRQ_AP_WDT_CODE                      PS_IRQID_APWDT                          
#define IRQ_SPI_ERROR_CODE                   PS_IRQID_SPI                            
#define IRQ_USB2_CODE                        PS_IRQID_USB2_0                         
#define IRQ_USB3_CODE                        PS_IRQID_USB3                           
#define IRQ_SDIO_CODE                        PS_IRQID_SDIO                           
#define IRQ_MSDC0_CODE                       PS_IRQID_MSDC0                          
#define IRQ_EHPI0_CODE                       PS_IRQID_EHPI0                          
#define IRQ_RTC_CODE                         PS_IRQID_RTC                            
#define IRQ_SOE_CODE                         PS_IRQID_SOE                            
#define IRQ_MSDC1_CODE                       PS_IRQID_MSDC1                          
#define IRQ_PFC_CODE                         PS_IRQID_PFC_INT_LV                     
#define IRQ_AUXADC_CODE                      PS_IRQID_AUXACD                         
#define IRQ_LED_CODE                         PS_IRQID_LED 
#define IRQ_BT_CVSD_CODE                     PS_IRQID_BT_CVSD                           
#define IRQ_DSP_L1DMA_CODE                   PS_IRQID_DSP_L1DMA               
#define IRQ_DSP2CPU_CODE                     PS_IRQID_SHARE_D12MINT2          
#define IRQ_LTE_TIMER_PCORE_SF_TICK_CODE     PS_IRQID_LTE_TIMER_EMAC_SF_TICK  
#define IRQ_IRDBG_MCU_CODE                   PS_IRQID_IRDBG_MCU_INT_B
#define IRQ_MODEMSYS_TRACE_CODE              PS_IRQID_MODEMSYS_TRACE 
#define IRQ_L1_ASM_CODE 					 PS_IRQID_L1_ADOE_INT
#define IRQ_HSDPA_BC_CODE					 PS_IRQID_BC_IRQ_B
#define IRQ_F8F9_CODE						 PS_IRQID_IRQID_UEA_UIA_IRQ_B
#define IRQ_L2UPA_CODE						 PS_IRQID_IRQID_UPA_ACC_IRQ_B
#define IRQ_L2DPA_CODE						 PS_IRQID_IRQID_DPA_ACC_IRQ_B
#define IRQ_L2P_CCIRQ_0_CODE                 PS_IRQID_CCIRQ_12P_0    
#define IRQ_L2P_CCIRQ_1_CODE                 PS_IRQID_CCIRQ_12P_1    
#define IRQ_L2P_CCIRQ_2_CODE                 PS_IRQID_CCIRQ_12P_2    
#define IRQ_L2P_CCIRQ_3_CODE                 PS_IRQID_CCIRQ_12P_3    
#define IRQ_L2P_CCIRQ_4_CODE                 PS_IRQID_CCIRQ_12P_4    
#define IRQ_L2P_CCIRQ_5_CODE                 PS_IRQID_CCIRQ_12P_5    
#define IRQ_L2P_CCIRQ_6_CODE                 PS_IRQID_CCIRQ_12P_6    
#define IRQ_L2P_CCIRQ_7_CODE                 PS_IRQID_CCIRQ_12P_7    
#define IRQ_L2P_CCIRQ_8_CODE                 PS_IRQID_CCIRQ_12P_8    
#define IRQ_L2P_CCIRQ_9_CODE                 PS_IRQID_CCIRQ_12P_9    
#define IRQ_L2P_CCIRQ_10_CODE                PS_IRQID_CCIRQ_12P_10   
#define IRQ_L2P_CCIRQ_11_CODE                PS_IRQID_CCIRQ_12P_11   
#define IRQ_L2P_CCIRQ_12_CODE                PS_IRQID_CCIRQ_12P_12   
#define IRQ_L2P_CCIRQ_13_CODE                PS_IRQID_CCIRQ_12P_13   
#define IRQ_L2P_CCIRQ_14_CODE                PS_IRQID_CCIRQ_12P_14   
#define IRQ_L2P_CCIRQ_15_CODE                PS_IRQID_CCIRQ_12P_15   
#define IRQ_PCCIF_AP_CODE                    PS_IRQID_PCCIF_AP_IRQ                
//#define IRQ_PCCIF_MD32_CODE                  PS_IRQID_PCCIF_MD32_IRQ              
#define IRQ_PCCIF_ARM7_CODE                  PS_IRQID_PCCIF_ARM7_IRQ              
//#define IRQ_PCCIF_MD32_0_CODE                PS_IRQID_PCCIF_MD32_PRIORITY_IRQ0    
//#define IRQ_PCCIF_MD32_1_CODE                PS_IRQID_PCCIF_MD32_PRIORITY_IRQ1    
//#define IRQ_PCCIF_MD32_2_CODE                PS_IRQID_PCCIF_MD32_PRIORITY_IRQ2    
//#define IRQ_PCCIF_MD32_3_CODE                PS_IRQID_PCCIF_MD32_PRIORITY_IRQ3

#define IRQ_C2K_PS_CCIRQ_0_CODE              PS_IRQID_C2K_PS_INT0
#define IRQ_C2K_PS_CCIRQ_1_CODE              PS_IRQID_C2K_PS_INT1
#define IRQ_C2K_PS_CCIRQ_2_CODE              PS_IRQID_C2K_PS_INT2
#define IRQ_C2K_PS_CCIRQ_3_CODE              PS_IRQID_C2K_PS_INT3

/*MDGLBCON*/
#define IRQ_SOE_INT_CODE 		     PS_IRQID_SOE_INT
#define IRQ_LDO_INT_CODE		     PS_IRQID_LDO_LV_ADJ
#define IRQ_TRACE_INT_CODE                   PS_IRQID_TRACE_INT
#define IRQ_SPM2MD_DVFS_MDPERISYS_CODE       PS_IRQID_SPM2MD_DVFS_MDPERISYS
#define IRQ_MD2MD_CCIF_MD1_0_CODE            PS_IRQID_MD2MD_CCIF_MD1_0
#define IRQ_MD2MD_CCIF_MD1_1_CODE            PS_IRQID_MD2MD_CCIF_MD1_1
#define IRQ_MD2MD_CCIF_MD1_2_CODE            PS_IRQID_MD2MD_CCIF_MD1_2
#define IRQ_MD2MD_CCIF_MD1_3_CODE            PS_IRQID_MD2MD_CCIF_MD1_3
#define IRQ_PSMCUPLL_FRQ_ADJ_RDY_CODE        PS_IRQID_PSMCUPLL_FRQ_ADJ_RDY
#define IRQ_DCXO_RDY_WO_ACK_CODE 			PS_IRQID_DCXO_RDY_WO_ACK_IRQ
#define IRQ_PLL_REQ_WO_DCXO_CODE 			PS_IRQID_PLL_REQ_WO_DCXO_IRQ
#define IRQ_TOP_PLL_DSNS_CODE 				PS_IRQID_TOP_PLL_DSNS_IRQ


#define IRQ_A7WDT_CODE              PS_IRQID_ARM7_WDT_INT
#define IRQ_PERFCNT_CODE            PS_IRQID_PERFCNT
#define IRQ_PMU_CODE                PS_IRQID_PMU

#define IRQ_SYS_TIMER_CODE          (PS_IRQID_GPTM1 + DRV_GPT_SYSTEM_TIMER - 1)
#define IRQ_SW_CODE_END            IRQ_SW_LISR8_CODE


/*                          
 * Define IRQ selection register assignment
 */                         
#define IRQSel()
//#define INVALID_ISR_ID           (0xFF)

#if defined(__UNIFIED_ISR_LEVEL__)
#error "Unsupport"
#else /* __UNIFIED_ISR_LEVEL__  */

#define INTERRUPT_PRIORITY_LIST \
/*	0 ~  7 */ 34, 63, 63,  6,  4, 63, 63, 63, \
/*	8 ~ 15 */ 63, 63, 63, 63, 63, 63, 63,  3, \
/* 16 ~ 23 */ 63, 63, 63, 63, 63, 63, 63, 63, \
/* 24 ~ 31 */ 63, 63, 63, 63, 63, 63, 63, 63, \
/* 32 ~ 39 */  6, 15, 16, 17,  9, 10, 63, 63, \
/* 40 ~ 47 */ 63, 63, 63,  3, 63, 63, 63, 63, \
/* 48 ~ 55 */ 26, 63,  4, 63, 63, 63, 63, 63, \
/* 56 ~ 63 */ 63, 63, 63, 63, 63, 63, 63, 63, \
/* 64 ~ 71 */ 63, 63, 63, 63, 63, 63, 63, 63, \
/* 72 ~ 79 */ 63, 63, 63, 63, 63, 63, 63, 63, \
/* 80 ~ 87 */ 28, 27, 30, 29, 63, 63, 18,  8, \
/* 88 ~ 95 */ 63, 63, 63,  7,  6,  5, 63, 63, \
/* 96 ~103 */ 63, 63, 63, 63, 63, 63, 63, 63, \
/*104 ~111 */ 63, 63, 63, 63, 63, 63, 63, 63, \
/*112 ~119 */ 63, 63, 63, 63, 63, 63, 63, 63, \
/*120 ~127 */ 63, 63, 63, 63, 63, 63, 63, 63

#endif /* __UNIFIED_ISR_LEVEL__  */


/*******************************************************************************
 * Special for display on SWDBG - MCU profiling
 *******************************************************************************/
#if (MAX_ISR_NUM<=32)
#define __CIRQ_MASK_REG_NR_1_NEW__
#elif (MAX_ISR_NUM<=64)
#define __CIRQ_MASK_REG_NR_2_NEW__
#elif (MAX_ISR_NUM<=96)
#define __CIRQ_MASK_REG_NR_3_NEW__
#elif (MAX_ISR_NUM<=128)
#define __CIRQ_MASK_REG_NR_4_NEW__
#else
    #error "Unsupport mask number"
#endif

#define __ENABLE_SW_TRIGGER_INTERRUPT__

#define EINT_TOTAL_CHANNEL 16

#define IRQ_MASK0              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0000))
#define IRQ_MASK1              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0004))
#define IRQ_MASK2              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0008))
#define IRQ_MASK3              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x000C))


typedef enum
{
   LISR_UART1     = IRQ_UART1_CODE,
   LISR_UART2     = IRQ_UART2_CODE
} LISR_IRQ_NO;

enum Irq_Code_Def_Enum
{
    Enum_CCIRQ_TL12MAC_UPADCHCSR_CODE = IRQ_L2P_CCIRQ_4_CODE, //CC_IRQ_L2P_TDD_0,
    Enum_CCIRQ_TL12MAC_DPA_CODE       = IRQ_L2P_CCIRQ_5_CODE, //CC_IRQ_L2P_TDD_1,  
    Enum_IRQ_Code_End                = MAX_ISR_NUM
};

#endif /* end of __INTRCTRL_MT6757_H__ */

    
