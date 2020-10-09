/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *   cmif_config_isr.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   ISR Config for CMIF interrupt 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
  * $Revision$
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Note: Do not change order of configuration!!!! */

#if !(defined(__MD32S_CMIF_DRV_TEST__) || defined(__MAUI_BASIC__))

// 0
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ0)
irq_name("CMIF_M2C_U3G_RAKE_IRQ0")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 1
/************************* Core ISR Configure Begin ****************/
irq_index(RAKE_IRQ_M2C_U3G_IRQ_STA_AI)
irq_name("RAKE_IRQ_M2C_U3G_IRQ_STA_AI")
irq_entry_function(UL1D_RAKE_Interrupt_Handler)
irq_auto_eoi(CMIF_FALSE)
/************************* Core ISR Configure END ******************/

// 2
/************************* Core ISR Configure Begin ****************/
irq_index(RAKE_IRQ_M2C_U3G_IRQ_STA_PI)
irq_name("RAKE_IRQ_M2C_U3G_IRQ_STA_PI")
irq_entry_function(UL1D_RAKE_Interrupt_Handler)
irq_auto_eoi(CMIF_FALSE)
/************************* Core ISR Configure END ******************/

// 3
/************************* Core ISR Configure Begin ****************/
irq_index(RAKE_IRQ_M2C_U3G_IRQ_STA_TFCI_0)
irq_name("RAKE_IRQ_M2C_U3G_IRQ_STA_TFCI_0")
irq_entry_function(UL1D_RAKE_Interrupt_Handler)
irq_auto_eoi(CMIF_FALSE)
/************************* Core ISR Configure END ******************/

// 4
/************************* Core ISR Configure Begin ****************/
irq_index(RAKE_IRQ_M2C_U3G_IRQ_STA_TFCI_1)
irq_name("RAKE_IRQ_M2C_U3G_IRQ_STA_TFCI_1")
irq_entry_function(UL1D_RAKE_Interrupt_Handler)
irq_auto_eoi(CMIF_FALSE)
/************************* Core ISR Configure END ******************/

// 5
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ5)
irq_name("CMIF_M2C_U3G_RAKE_IRQ5")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 6
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ6)
irq_name("CMIF_M2C_U3G_RAKE_IRQ6")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 7
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ7)
irq_name("CMIF_M2C_U3G_RAKE_IRQ7")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 8
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ8)
irq_name("CMIF_M2C_U3G_RAKE_IRQ8")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 9
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ9)
irq_name("CMIF_M2C_U3G_RAKE_IRQ9")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 10
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQA)
irq_name("CMIF_M2C_U3G_RAKE_IRQA")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 11
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQB)
irq_name("CMIF_M2C_U3G_RAKE_IRQB")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 12
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQC)
irq_name("CMIF_M2C_U3G_RAKE_IRQC")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 13
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQD)
irq_name("CMIF_M2C_U3G_RAKE_IRQD")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 14
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQE)
irq_name("CMIF_M2C_U3G_RAKE_IRQE")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 15
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQF)
irq_name("CMIF_M2C_U3G_RAKE_IRQF")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 16
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ10)
irq_name("CMIF_M2C_U3G_RAKE_IRQ10")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 17
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ11)
irq_name("CMIF_M2C_U3G_RAKE_IRQ11")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 18
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ12)
irq_name("CMIF_M2C_U3G_RAKE_IRQ12")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 19
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ13)
irq_name("CMIF_M2C_U3G_RAKE_IRQ13")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 20
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ14)
irq_name("CMIF_M2C_U3G_RAKE_IRQ14")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 21
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ15)
irq_name("CMIF_M2C_U3G_RAKE_IRQ15")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 22
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ16)
irq_name("CMIF_M2C_U3G_RAKE_IRQ16")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 23
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ17)
irq_name("CMIF_M2C_U3G_RAKE_IRQ17")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 24
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ18)
irq_name("CMIF_M2C_U3G_RAKE_IRQ18")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 25
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ19)
irq_name("CMIF_M2C_U3G_RAKE_IRQ19")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 26
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1A)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1A")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 27
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1B)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1B")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 28
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1C)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1C")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 29
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1D)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1D")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 30
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1E)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1E")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 31
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1F)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1F")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

#else   /*  !(__MD32S_CMIF_DRV_TEST__ || __MAUI_BASIC__) */

#if defined(__MAUI_BASIC__)
// Basic load

// 0
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ0)
irq_name("CMIF_M2C_U3G_RAKE_IRQ0")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 1
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 2
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ2)
irq_name("CMIF_M2C_U3G_RAKE_IRQ2")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 3
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ3)
irq_name("CMIF_M2C_U3G_RAKE_IRQ3")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 4
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ4)
irq_name("CMIF_M2C_U3G_RAKE_IRQ4")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 5
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ5)
irq_name("CMIF_M2C_U3G_RAKE_IRQ5")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 6
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ6)
irq_name("CMIF_M2C_U3G_RAKE_IRQ6")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 7
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ7)
irq_name("CMIF_M2C_U3G_RAKE_IRQ7")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 8
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ8)
irq_name("CMIF_M2C_U3G_RAKE_IRQ8")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 9
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ9)
irq_name("CMIF_M2C_U3G_RAKE_IRQ9")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 10
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQA)
irq_name("CMIF_M2C_U3G_RAKE_IRQA")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 11
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQB)
irq_name("CMIF_M2C_U3G_RAKE_IRQB")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 12
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQC)
irq_name("CMIF_M2C_U3G_RAKE_IRQC")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 13
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQD)
irq_name("CMIF_M2C_U3G_RAKE_IRQD")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 14
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQE)
irq_name("CMIF_M2C_U3G_RAKE_IRQE")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 15
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQF)
irq_name("CMIF_M2C_U3G_RAKE_IRQF")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 16
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ10)
irq_name("CMIF_M2C_U3G_RAKE_IRQ10")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 17
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ11)
irq_name("CMIF_M2C_U3G_RAKE_IRQ11")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 18
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ12)
irq_name("CMIF_M2C_U3G_RAKE_IRQ12")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 19
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ13)
irq_name("CMIF_M2C_U3G_RAKE_IRQ13")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 20
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ14)
irq_name("CMIF_M2C_U3G_RAKE_IRQ14")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 21
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ15)
irq_name("CMIF_M2C_U3G_RAKE_IRQ15")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 22
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ16)
irq_name("CMIF_M2C_U3G_RAKE_IRQ16")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 23
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ17)
irq_name("CMIF_M2C_U3G_RAKE_IRQ17")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 24
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ18)
irq_name("CMIF_M2C_U3G_RAKE_IRQ18")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 25
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ19)
irq_name("CMIF_M2C_U3G_RAKE_IRQ19")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 26
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1A)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1A")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 27
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1B)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1B")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 28
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1C)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1C")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 29
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1D)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1D")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 30
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1E)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1E")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 31
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1F)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1F")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/


#else   /* __MAUI_BASIC__ */
// CMIF Driver test

// 0
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ0)
irq_name("CMIF_M2C_U3G_RAKE_IRQ0")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 1
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1")
irq_entry_function(CMIF_DrierTestISR_RAKE_U3G)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 2
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ2)
irq_name("CMIF_M2C_U3G_RAKE_IRQ2")
irq_entry_function(CMIF_DrierTestISR_RAKE_U3G)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 3
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ3)
irq_name("CMIF_M2C_U3G_RAKE_IRQ3")
irq_entry_function(CMIF_DrierTestISR_RAKE_U3G)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 4
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ4)
irq_name("CMIF_M2C_U3G_RAKE_IRQ4")
irq_entry_function(CMIF_DrierTestISR_RAKE_U3G)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 5
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ5)
irq_name("CMIF_M2C_U3G_RAKE_IRQ5")
irq_entry_function(CMIF_DrierTestISR_RAKE_U3G)
irq_auto_eoi(CMIF_FALSE)
/************************* Core ISR Configure END ******************/

// 6
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ6)
irq_name("CMIF_M2C_U3G_RAKE_IRQ6")
irq_entry_function(CMIF_DrierTestISR_RAKE_U3G)
irq_auto_eoi(CMIF_FALSE)
/************************* Core ISR Configure END ******************/

// 7
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ7)
irq_name("CMIF_M2C_U3G_RAKE_IRQ7")
irq_entry_function(CMIF_DrierTestISR_RAKE_U3G)
irq_auto_eoi(CMIF_FALSE)
/************************* Core ISR Configure END ******************/

// 8
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ8)
irq_name("CMIF_M2C_U3G_RAKE_IRQ8")
irq_entry_function(CMIF_DrierTestISR_RAKE_U3G)
irq_auto_eoi(CMIF_FALSE)
/************************* Core ISR Configure END ******************/

// 9
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ9)
irq_name("CMIF_M2C_U3G_RAKE_IRQ9")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 10
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQA)
irq_name("CMIF_M2C_U3G_RAKE_IRQA")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 11
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQB)
irq_name("CMIF_M2C_U3G_RAKE_IRQB")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 12
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQC)
irq_name("CMIF_M2C_U3G_RAKE_IRQC")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 13
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQD)
irq_name("CMIF_M2C_U3G_RAKE_IRQD")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 14
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQE)
irq_name("CMIF_M2C_U3G_RAKE_IRQE")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 15
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQF)
irq_name("CMIF_M2C_U3G_RAKE_IRQF")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 16
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ10)
irq_name("CMIF_M2C_U3G_RAKE_IRQ10")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 17
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ11)
irq_name("CMIF_M2C_U3G_RAKE_IRQ11")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 18
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ12)
irq_name("CMIF_M2C_U3G_RAKE_IRQ12")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 19
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ13)
irq_name("CMIF_M2C_U3G_RAKE_IRQ13")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 20
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ14)
irq_name("CMIF_M2C_U3G_RAKE_IRQ14")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 21
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ15)
irq_name("CMIF_M2C_U3G_RAKE_IRQ15")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 22
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ16)
irq_name("CMIF_M2C_U3G_RAKE_IRQ16")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 23
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ17)
irq_name("CMIF_M2C_U3G_RAKE_IRQ17")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 24
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ18)
irq_name("CMIF_M2C_U3G_RAKE_IRQ18")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 25
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ19)
irq_name("CMIF_M2C_U3G_RAKE_IRQ19")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 26
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1A)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1A")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 27
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1B)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1B")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 28
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1C)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1C")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 29
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1D)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1D")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 30
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1E)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1E")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/

// 31
/************************* Core ISR Configure Begin ****************/
irq_index(CMIF_M2C_U3G_RAKE_IRQ1F)
irq_name("CMIF_M2C_U3G_RAKE_IRQ1F")
irq_entry_function(CMIF_DefaultISR)
irq_auto_eoi(CMIF_TRUE)
/************************* Core ISR Configure END ******************/
#endif /* __MAUI_BASIC__ */

#endif  /*  !__MD32S_CMIF_DRV_TEST__ */
