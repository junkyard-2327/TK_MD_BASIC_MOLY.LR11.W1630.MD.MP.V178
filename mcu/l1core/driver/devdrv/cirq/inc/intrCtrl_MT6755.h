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
 *   intrCtrl_MT6755.h
 *
 * Project:
 * --------
 *   MT6755
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

#ifndef __INTRCTRL_MT6755_H__
#define __INTRCTRL_MT6755_H__


#include "reg_base.h"
#include "irqid.h"
//#include "drv_features_gpt.h"
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
////////////////////////////////////////////////////////////////////
//#define                                         L1_BSI_TOP_IRQ_B
#define IRQ_EL1_EVENT_T_CODE                    L1_EL1_SW_EVENT_T                          
#define IRQ_EL1_EVENT_3_CODE                    L1_EL1_SW_EVENT_3                            
#define IRQ_EL1_EVENT_2_CODE                    L1_EL1_SW_EVENT_2                            
#define IRQ_EL1_EVENT_1_CODE                    L1_EL1_SW_EVENT_1                            
#define IRQ_EL1_EVENT_0_CODE                    L1_EL1_SW_EVENT_0                            
#define IRQ_WTIMER_WAKEUP_CODE                  L1_WTIMER_IRQ_B 
#define IRQ_RTR_SLT_CODE                        L1_RTR_SLT_IRQ_B 
#define IRQ_RTR_FRAME_CODE                      L1_RTR_FRAME_IRQ_B
#define IRQ_TDMA_WAKEUP_CODE                    L1_TDMA_WAKEUP_IRQ_B
#define IRQ_TDD_WAKEUP_CODE                     L1_TDD_WAKEUP_IRQ_B 
#define IRQ_TOPSM_CODE                          L1_MDL1_TOPSM_IRQ_B 
#define IRQ_FREQM_CODE                          L1_FREQM_IRQ_B 
#define IRQ_DEM_TRIG_CODE                       L1_DEM_TRIG_L1_INT_LE_B 
#define IRQ_CSIF_MPC_CODE                       L1_MPC_DSP_IRQ_B_0                           
#define IRQ_CSIF_MPC_ERR_CODE                   L1_MPC_DSP_IRQ_B_1                           
#define IRQ_IMC_MMU_1_CODE                      L1_IMC_MMU_IRQ_B_1                           
#define IRQ_IMC_MMU_0_CODE                      L1_IMC_MMU_IRQ_B_0                           
#define IRQ_CSIF_IMC_ERR_CODE                   L1_IMC_DSP_IRQ_B_1                           
#define IRQ_CSIF_IMC_CODE                       L1_IMC_DSP_IRQ_B_0                           
#define IRQ_CSIF_ICC_CODE                       L1_ICC_DSP_IRQ_B_0                           
#define IRQ_CSIF_ICC_ERR_CODE                   L1_ICC_DSP_IRQ_B_1                           
#define IRQ_OSTIMER_WAKEUP_CODE					L1_OST_INT_LV 
#define IRQ_MPC_SRAM_CTRL_CODE                  L1_MPC_SRAM_CTRL_IRQ_B 
#define IRQ_DFE_M2C_0_CODE                      L1_L1M_DFE_CMIF_M2C_IRQ_B_0 
#define IRQ_DFE_M2C_1_CODE                      L1_L1M_DFE_CMIF_M2C_IRQ_B_1 
#define IRQ_DFE_M2C_2_CODE                      L1_L1M_DFE_CMIF_M2C_IRQ_B_2 
#define IRQ_TDD_TCU2_CODE                       L1_TCU_SW_INT2 
#define IRQ_TDD_TCU1_CODE                       L1_TCU_SW_INT1 
#define IRQ_CTIRQ3_CODE                         L1_TDMA_CTIRQ3_B
#define IRQ_CTIRQ2_CODE                         L1_TDMA_CTIRQ2_B
#define IRQ_CTIRQ1_CODE                         L1_TDMA_CTIRQ1_B
#define IRQ_DSP2CPU_CODE                        L1_SHARE_D12MINT1_B
#define IRQ_INR_M2C_0_CODE                      L1_INR_RAKE_CMIF_M2C_IRQ_B_0
#define IRQ_INR_M2C_1_CODE                      L1_INR_RAKE_CMIF_M2C_IRQ_B_1
#define IRQ_TDD_BRPDMA2_CODE                    L1_INR_TD2_BRP_DMA_IRQ_B
#define IRQ_TDD_PP2_CODE                        L1_INR_TD2_PP_IRQ_B
#define IRQ_TDD_JDA2_CODE                       L1_INR_TD2_JDA_IRQ_B
#define IRQ_TDD_CSCE2_CODE                      L1_INR_TD2_CSCE_IRQ_B
#define IRQ_TDD_DFEBRIDGE2_CODE                 L1_INR_TD2_DFE_BRG_IRQ_B
#define IRQ_TDD_BRPDMA1_CODE                    L1_INR_TD1_BRP_DMA_IRQ_B
#define IRQ_TDD_PP1_CODE                        L1_INR_TD1_PP_IRQ_B 
#define IRQ_TDD_JDA1_CODE                       L1_INR_TD1_JDA_IRQ_B 
#define IRQ_TDD_CSCE1_CODE                      L1_INR_TD1_CSCE_IRQ_B 
#define IRQ_TDD_DFEBRIDGE1_CODE                 L1_INR_TD1_DFE_BRG_IRQ_B 
#define IRQ_RXBRP_M2C_0_CODE                    L1_BRP_BRP_CMIF_M2C_IRQ_B_0 
#define IRQ_RXBRP_M2C_1_CODE                    L1_BRP_BRP_CMIF_M2C_IRQ_B_1 
#define IRQ_RXBRP_M2C_2_CODE                    L1_BRP_BRP_CMIF_M2C_IRQ_B_2 
#define IRQ_CS_CODE                             L1_LTEL1_CS_IRQ_B 
#define IRQ_MMU_SRAM_CTRL_CODE                  L1_MMU_SRAM_CTRL_IRQ_B 
#define IRQ_RXTBD_CODE                          L1_IMC_RXTDB_IRQ_B 
#define IRQ_RXDMP_CODE                          L1_IMC_RXDMP_IRQ_B 
#define IRQ_IMC_SRAM_CTRL_CODE                  L1_IMC_SRAM_CTRL_IRQ_B 
#define IRQ_ICC_SRAM_CTRL_CODE                  L1_ICC_SRAM_CTRL_IRQ_B 
#define IRQ_MDGDMA0_CODE                        L1_GDMA_IRQ_B 
#define IRQ_PMU_CODE                            L1_NPMUIRQ 
#define IRQ_TDD_ICS_CODE                        L1_CSTXB_TDD_CS_IRQ_B 
#define IRQ_SEARCHER_CODE                       L1_CSTXB_FDD_CS_IRQ_B 
#define IRQ_LTXB_TXENC_ERROR_CODE               L1_LTXB_TXENC_ERROR_IRQ_B 
#define IRQ_LTXB_BSI_L_AB_CODE                  L1_LTXB_BSI_L_AB_IRQ_B
#define IRQ_LTXB_BSI_L_C_CODE                   L1_LTXB_BSI_L_C_IRQ_B 
#define IRQ_LTXB_BSI_L_D_CODE                   L1_LTXB_BSI_L_D_IRQ_B 
#define IRQ_ECT_CODE                            L1_L1MCU_ECT_IRQ_B 
#define IRQ_RXDFEIF_AFIFO_CODE                  L1_RXDFEIF_L_IRQ_B 
#define IRQ_BUSMON_CODE                         L1_BUSMON_MATCH_INT_B
#define IRQ_CS_SRAM_CTRL_CODE                   L1_CS_SRAM_CTRL_IRQ_B 
#define IRQ_GPT_CODE                            L1_MDL1_GPT_IRQ_B 
#define IRQ_BUS_ERR_CODE                        L1_L1_BUS_DEC_ERR_IRQ_B 
#define IRQ_SLPCTL_CODE                         L1_SLPCTL_EVENT_B 
#define IRQ_PTP_FSM_CODE                        L1_PTP_FSM_INT_B 
#define IRQ_PTP_THERM_CODE                      L1_PTP_THERM_INT_B 
#define IRQ_LTE_WAKEUP_CODE                     L1_L1_LTE_WAKEUP_IRQ_B 
#define IRQ_BUS_2X_DEC_ERR_CODE                 L1_BUS_2X_DEC_ERR_LEVEL 
#define IRQ_ASM_CODE                            L1_ADOE_INT_B 
#define IRQ_GPTM1_CODE                          L1_GPTM1_IRQ_PS_B 
#define IRQ_GPTM2_CODE                          L1_GPTM2_IRQ_PS_B 
#define IRQ_GPTM3_CODE                          L1_GPTM3_IRQ_PS_B 
#define IRQ_GPTM4_CODE                          L1_GPTM4_IRQ_PS_B 
#define IRQ_GPTM5_CODE                          L1_GPTM5_IRQ_PS_B 
#define IRQ_GPTM6_CODE                          L1_GPTM6_IRQ_PS_B 
#define IRQ_P2L_CCIRQ_0_CODE                    L1_PS2L1_RCCIF_INT_B_0 
#define IRQ_P2L_CCIRQ_1_CODE                    L1_PS2L1_RCCIF_INT_B_1 
#define IRQ_P2L_CCIRQ_2_CODE                    L1_PS2L1_RCCIF_INT_B_2 
#define IRQ_P2L_CCIRQ_3_CODE                    L1_PS2L1_RCCIF_INT_B_3 
#define IRQ_P2L_CCIRQ_4_CODE                    L1_PS2L1_RCCIF_INT_B_4 
#define IRQ_P2L_CCIRQ_5_CODE                    L1_PS2L1_RCCIF_INT_B_5 
#define IRQ_P2L_CCIRQ_6_CODE                    L1_PS2L1_RCCIF_INT_B_6 
#define IRQ_P2L_CCIRQ_7_CODE                    L1_PS2L1_RCCIF_INT_B_7 
#define IRQ_P2L_CCIRQ_8_CODE                    L1_PS2L1_RCCIF_INT_B_8 
#define IRQ_P2L_CCIRQ_9_CODE                    L1_PS2L1_RCCIF_INT_B_9 
#define IRQ_P2L_CCIRQ_10_CODE                   L1_PS2L1_RCCIF_INT_B_10
#define IRQ_P2L_CCIRQ_11_CODE                   L1_PS2L1_RCCIF_INT_B_11
#define IRQ_P2L_CCIRQ_12_CODE                   L1_PS2L1_RCCIF_INT_B_12
#define IRQ_P2L_CCIRQ_13_CODE                   L1_PS2L1_RCCIF_INT_B_13
#define IRQ_P2L_CCIRQ_14_CODE                   L1_PS2L1_RCCIF_INT_B_14
#define IRQ_P2L_CCIRQ_15_CODE                   L1_PS2L1_RCCIF_INT_B_15

#define IRQ_C2K_L1_CCIRQ_0_CODE                 L1_C2K2L1_RCCIF_INT_B_0 
#define IRQ_C2K_L1_CCIRQ_1_CODE                 L1_C2K2L1_RCCIF_INT_B_1 
#define IRQ_C2K_L1_CCIRQ_2_CODE                 L1_C2K2L1_RCCIF_INT_B_2 
#define IRQ_C2K_L1_CCIRQ_3_CODE                 L1_C2K2L1_RCCIF_INT_B_3 
#define IRQ_C2K_L1_CCIRQ_4_CODE                 L1_C2K2L1_RCCIF_INT_B_4 
#define IRQ_C2K_L1_CCIRQ_5_CODE                 L1_C2K2L1_RCCIF_INT_B_5 
#define IRQ_C2K_L1_CCIRQ_6_CODE                 L1_C2K2L1_RCCIF_INT_B_6 
#define IRQ_C2K_L1_CCIRQ_7_CODE                 L1_C2K2L1_RCCIF_INT_B_7 


//104
#define IRQ_SW_LISR1_CODE                       L1_SW_IRQID_104 
#define IRQ_SW_LISR2_CODE                       L1_SW_IRQID_105 
#define IRQ_SW_LISR3_CODE                       L1_SW_IRQID_106 
#define IRQ_SW_LISR4_CODE                       L1_SW_IRQID_107

//112
#define IRQ_MODEML1_DVFS_CODE                   L1_MODEML1_DVFS_EVENT_IRQ
#define IRQ_MD2L1_DVFS_CODE                     L1_MD2L1_DVFS_EVENT_IRQ
#define IRQ_BT_CVSD_CODE                        L1_BT_CVSD_INT_B
#define IRQ_MODEML1_DVFS_HEARHP_RDY_CODE        L1_MODEML1_DVFS_HEARHP_RDY_IRQ_B
#define IRQ_L1MCUPLL_GEARHP_RDY_CODE            L1_L1MCUPLL_GEARHP_RDY_IRQ_B
#define IRQ_PLL_REQ_DBNORM_CODE                 L1_PLL_REQ_DBNORM_IRQ_B

//118
#define IRQ_SW_LISR8_CODE                       L1_SW_RSV_IRQIQ_118
#define IRQ_SW_LISR9_CODE                       L1_SW_RSV_IRQIQ_119

//120
#define IRQ_SW_LISR5_CODE                       L1_SW_IRQID_120 
#define IRQ_SW_LISR6_CODE                       L1_SW_IRQID_121 
#define IRQ_SW_LISR7_CODE                       L1_SW_IRQID_122 

//123
#define IRQ_PPC_CODE 							L1_PPC_CIRQ
#define IRQ_BUS_DEC_ERR_CODE 					L1_CORE_BUS_DEC_ERR_LEVEL
#define IRQ_DFE_PCC_FULL_CODE 					L1_DFE_PCC_FULL_IRQ_B
#define IRQ_IDC_PM_CODE 						L1_IDC_PM_INT
#define IRQ_IDC_UART_CODE 						L1_IDC_UART_IRQ_B



#ifdef __L1CORE_PRETEND_PCORE__
#define IRQ_USB3_CODE L1_PS_SSUSB_DEV_INT_LV
#define IRQ_UART1_CODE L1_PS_MDUART0_IRQ
#define IRQ_UART2_CODE L1_PS_MDUART1_IRQ
#define IRQ_MODEMSYS_TRACE_CODE L1_PS_MODEMSYS_TRACE_IRQ_B
//dummy GDMA IRQ ID
#define IRQ_MDGDMA0_CODE L1_MDH2L1_RCCIF_INT_B_0
#define IRQ_MDGDMA1_CODE L1_MDH2L1_RCCIF_INT_B_0
#define IRQ_MDGDMA2_CODE L1_MDH2L1_RCCIF_INT_B_0
#define IRQ_MDGDMA3_CODE L1_MDH2L1_RCCIF_INT_B_0
#endif





///////////////////////////////////////////////////////////////////

#define IRQ_SW_CODE_END            IRQ_SW_LISR6_CODE
#define IRQ_SYS_TIMER_CODE          (IRQ_GPT_CODE)


/*                          
 * Define IRQ selection register assignment
 */                         
#define IRQSel()
//#define INVALID_ISR_ID           (0xFF)

#if defined(__UNIFIED_ISR_LEVEL__)
#error "Unsupport"
#else /* __UNIFIED_ISR_LEVEL__  */

#define INTERRUPT_PRIORITY_LIST \
/*	0 ~  7 */ 53, 15,  7, 23, 26, 26,  4,  9, \
/*	8 ~ 15 */ 51, 39,  5, 47, 48, 63, 20, 19, \
/* 16 ~ 23 */ 63, 63, 13, 14, 18, 17, 49, 63, \
/* 24 ~ 31 */ 27, 38, 38, 11, 11, 41, 43, 42, \
/* 32 ~ 39 */ 50, 27, 12, 21, 31, 22, 12, 16, \
/* 40 ~ 47 */ 21, 31, 22, 12, 16, 27, 30,  7, \
/* 48 ~ 55 */ 29, 63, 32, 28, 63, 63, 63, 63, \
/* 56 ~ 63 */ 10, 16, 33, 53, 53, 53,  3, 32, \
/* 64 ~ 71 */  3, 63, 63, 63, 63, 63, 63,  6, \
/* 72 ~ 79 */ 63, 63, 62, 62,  3, 63, 63, 63, \
/* 80 ~ 87 */ 59, 59, 40, 59, 59, 44, 10 , 24, \
/* 88 ~ 95 */  8, 63, 63, 63, 63, 63, 63, 63, \
/* 96 ~103 */ 63, 53, 63, 63, 63, 63, 63, 63, \
/*104 ~111 */ 45, 44, 46, 25, 63, 63, 63, 63, \
/*112 ~119 */  3, 63, 63, 63, 63, 63, 63, 44, \
/*120 ~127 */ 45, 46, 63, 63, 63, 63, 63, 63

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

#define IRQ_MASK0              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0000))
#define IRQ_MASK1              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0004))
#define IRQ_MASK2              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0008))
#define IRQ_MASK3              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x000C))

typedef enum
{
   LISR_UART1     = INVALID_ISR_ID,
   //LISR_UART2     = IRQ_UART2_CODE
} LISR_IRQ_NO;


enum Irq_Code_Def_Enum
{ 
    Enum_IRQ_TDD_WAKEUP_CODE   	      = IRQ_TDD_WAKEUP_CODE,
    Enum_IRQ_TCU_CODE                 = IRQ_TDD_TCU1_CODE,       
    Enum_IRQ_CSCE_CODE                = IRQ_TDD_CSCE1_CODE,      
    Enum_IRQ_JDA_CODE                 = IRQ_TDD_JDA1_CODE,       
    Enum_IRQ_BRPDMA_CODE              = IRQ_TDD_BRPDMA1_CODE,    
    Enum_IRQ_DFEBRIDGE_CODE 	      = IRQ_TDD_DFEBRIDGE1_CODE, 
    Enum_IRQ_PP_CODE		      = IRQ_TDD_PP1_CODE,		  
    Enum_IRQ_ICS_CODE		      = IRQ_TDD_ICS_CODE,		  
    Enum_IRQ_TL1D_TICK3_LISR_CODE     = IRQ_SW_LISR4_CODE,
    Enum_IRQ_TL1C_UPA_LISR_CODE       = IRQ_SW_LISR5_CODE,
    Enum_IRQ_TL1C_DPA_LISR_CODE        = IRQ_SW_LISR6_CODE,
    Enum_IRQ_Code_End                = MAX_ISR_NUM
};

#endif /* end of __INTRCTRL_MT6290_H__ */
