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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Note: Do not change order of configuration!!!! */

#if !defined(__MAUI_BASIC__)

// normal load 
irq_index(CMIF_C2M_U3G_RAKE_IRQ0)   // 0
irq_index(CMIF_C2M_U3G_RAKE_IRQ1)   // 1
irq_index(CMIF_C2M_U3G_RAKE_IRQ2)   // 2
irq_index(CMIF_C2M_U3G_RAKE_IRQ3)   // 3
irq_index(CMIF_C2M_U3G_RAKE_IRQ4)   // 4
irq_index(CMIF_C2M_U3G_RAKE_IRQ5)   // 5
irq_index(CMIF_C2M_U3G_RAKE_IRQ6)   // 6
irq_index(CMIF_C2M_U3G_RAKE_IRQ7)   // 7
irq_index(CMIF_C2M_U3G_RAKE_IRQ8)   // 8
irq_index(CMIF_C2M_U3G_RAKE_IRQ9)   // 9
irq_index(CMIF_C2M_U3G_RAKE_IRQA)   // 10
irq_index(CMIF_C2M_U3G_RAKE_IRQB)   // 11
irq_index(CMIF_C2M_U3G_RAKE_IRQC)   // 12
irq_index(CMIF_C2M_U3G_RAKE_IRQD)   // 13
irq_index(CMIF_C2M_U3G_RAKE_IRQE)   // 14
irq_index(CMIF_C2M_U3G_RAKE_IRQF)   // 15
irq_index(CMIF_C2M_U3G_RAKE_IRQ10)  // 16
irq_index(CMIF_C2M_U3G_RAKE_IRQ11)  // 17
irq_index(CMIF_C2M_U3G_RAKE_IRQ12)  // 18
irq_index(CMIF_C2M_U3G_RAKE_IRQ13)  // 19
irq_index(CMIF_C2M_U3G_RAKE_IRQ14)  // 20
irq_index(CMIF_C2M_U3G_RAKE_IRQ15)  // 21
irq_index(CMIF_C2M_U3G_RAKE_IRQ16)  // 22
irq_index(CMIF_C2M_U3G_RAKE_IRQ17)  // 23
irq_index(CMIF_C2M_U3G_RAKE_IRQ18)  // 24
irq_index(CMIF_C2M_U3G_RAKE_IRQ19)  // 25
irq_index(CMIF_C2M_U3G_RAKE_IRQ1A)  // 26
irq_index(CMIF_C2M_U3G_RAKE_IRQ1B)  // 27
irq_index(CMIF_C2M_U3G_RAKE_IRQ1C)  // 28
irq_index(CMIF_C2M_U3G_RAKE_IRQ1D)  // 29
irq_index(CMIF_C2M_U3G_RAKE_IRQ1E)  // 30
irq_index(CMIF_C2M_U3G_RAKE_IRQ1F)  // 31

#else   /*  !__MAUI_BASIC__*/

// basic load
irq_index(CMIF_C2M_U3G_RAKE_IRQ0)   // 0
irq_index(CMIF_C2M_U3G_RAKE_IRQ1)   // 1
irq_index(CMIF_C2M_U3G_RAKE_IRQ2)   // 2
irq_index(CMIF_C2M_U3G_RAKE_IRQ3)   // 3
irq_index(CMIF_C2M_U3G_RAKE_IRQ4)   // 4
irq_index(CMIF_C2M_U3G_RAKE_IRQ5)   // 5
irq_index(CMIF_C2M_U3G_RAKE_IRQ6)   // 6
irq_index(CMIF_C2M_U3G_RAKE_IRQ7)   // 7
irq_index(CMIF_C2M_U3G_RAKE_IRQ8)   // 8
irq_index(CMIF_C2M_U3G_RAKE_IRQ9)   // 9
irq_index(CMIF_C2M_U3G_RAKE_IRQA)   // 10
irq_index(CMIF_C2M_U3G_RAKE_IRQB)   // 11
irq_index(CMIF_C2M_U3G_RAKE_IRQC)   // 12
irq_index(CMIF_C2M_U3G_RAKE_IRQD)   // 13
irq_index(CMIF_C2M_U3G_RAKE_IRQE)   // 14
irq_index(CMIF_C2M_U3G_RAKE_IRQF)   // 15
irq_index(CMIF_C2M_U3G_RAKE_IRQ10)  // 16
irq_index(CMIF_C2M_U3G_RAKE_IRQ11)  // 17
irq_index(CMIF_C2M_U3G_RAKE_IRQ12)  // 18
irq_index(CMIF_C2M_U3G_RAKE_IRQ13)  // 19
irq_index(CMIF_C2M_U3G_RAKE_IRQ14)  // 20
irq_index(CMIF_C2M_U3G_RAKE_IRQ15)  // 21
irq_index(CMIF_C2M_U3G_RAKE_IRQ16)  // 22
irq_index(CMIF_C2M_U3G_RAKE_IRQ17)  // 23
irq_index(CMIF_C2M_U3G_RAKE_IRQ18)  // 24
irq_index(CMIF_C2M_U3G_RAKE_IRQ19)  // 25
irq_index(CMIF_C2M_U3G_RAKE_IRQ1A)  // 26
irq_index(CMIF_C2M_U3G_RAKE_IRQ1B)  // 27
irq_index(CMIF_C2M_U3G_RAKE_IRQ1C)  // 28
irq_index(CMIF_C2M_U3G_RAKE_IRQ1D)  // 29
irq_index(CMIF_C2M_U3G_RAKE_IRQ1E)  // 30
irq_index(CMIF_C2M_U3G_RAKE_IRQ1F)  // 31

#endif  /*  !__MAUI_BASIC__*/
