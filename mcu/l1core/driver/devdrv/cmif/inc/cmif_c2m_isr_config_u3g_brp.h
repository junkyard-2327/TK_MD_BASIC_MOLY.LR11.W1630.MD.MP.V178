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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Note: Do not change order of configuration!!!! */

#if !defined(__MAUI_BASIC__)

// normal load
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_HSPA_SERV_SCCH)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_HSPA_AGCH)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_HSPA_NC_SCCH)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_HSPA_HARQ)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_HSPA_HARQ_RESTART)
irq_index(CMIF_C2M_U3G_BRP_IRQ5)
irq_index(CMIF_C2M_U3G_BRP_IRQ6)
irq_index(CMIF_C2M_U3G_BRP_IRQ7)
irq_index(CMIF_C2M_U3G_BRP_IRQ8)
irq_index(CMIF_C2M_U3G_BRP_IRQ9)
irq_index(CMIF_C2M_U3G_BRP_IRQA)
irq_index(CMIF_C2M_U3G_BRP_IRQB)
irq_index(CMIF_C2M_U3G_BRP_IRQC)
irq_index(CMIF_C2M_U3G_BRP_IRQD)
irq_index(CMIF_C2M_U3G_BRP_IRQE)
irq_index(CMIF_C2M_U3G_BRP_IRQF)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_CC0_START)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_CC1_START)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_CC0_CFG_OK)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_CC1_CFG_OK)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_CC0_GUIDED_CFG_OK)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_CC1_GUIDED_CFG_OK)
irq_index(CMIF_C2M_U3G_BRP_IRQ16)
irq_index(CMIF_C2M_U3G_BRP_IRQ17)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_BCHSFN_START)
irq_index(CMIF_C2M_U3G_BRP_IRQ19)
irq_index(CMIF_C2M_U3G_BRP_IRQ1A)
irq_index(CMIF_C2M_U3G_BRP_IRQ1B)
irq_index(CMIF_C2M_U3G_BRP_IRQ1C)
irq_index(CMIF_C2M_U3G_BRP_IRQ1D)
irq_index(CMIF_C2M_U3G_BRP_IRQ1E)
irq_index(BRP_IRQ_C2M_U3G_IRQ_STA_BRP_SLEEP)

#else   /*  !__MAUI_BASIC__*/

// basic load
irq_index(CMIF_C2M_U3G_BRP_IRQ0)    // 0
irq_index(CMIF_C2M_U3G_BRP_IRQ1)    // 1
irq_index(CMIF_C2M_U3G_BRP_IRQ2)    // 2
irq_index(CMIF_C2M_U3G_BRP_IRQ3)    // 3
irq_index(CMIF_C2M_U3G_BRP_IRQ4)    // 4
irq_index(CMIF_C2M_U3G_BRP_IRQ5)    // 5
irq_index(CMIF_C2M_U3G_BRP_IRQ6)    // 6
irq_index(CMIF_C2M_U3G_BRP_IRQ7)    // 7
irq_index(CMIF_C2M_U3G_BRP_IRQ8)    // 8
irq_index(CMIF_C2M_U3G_BRP_IRQ9)    // 9
irq_index(CMIF_C2M_U3G_BRP_IRQA)    // 10
irq_index(CMIF_C2M_U3G_BRP_IRQB)    // 11
irq_index(CMIF_C2M_U3G_BRP_IRQC)    // 12
irq_index(CMIF_C2M_U3G_BRP_IRQD)    // 13
irq_index(CMIF_C2M_U3G_BRP_IRQE)    // 14
irq_index(CMIF_C2M_U3G_BRP_IRQF)    // 15
irq_index(CMIF_C2M_U3G_BRP_IRQ10)   // 16
irq_index(CMIF_C2M_U3G_BRP_IRQ11)   // 17
irq_index(CMIF_C2M_U3G_BRP_IRQ12)   // 18
irq_index(CMIF_C2M_U3G_BRP_IRQ13)   // 19
irq_index(CMIF_C2M_U3G_BRP_IRQ14)   // 20
irq_index(CMIF_C2M_U3G_BRP_IRQ15)   // 21
irq_index(CMIF_C2M_U3G_BRP_IRQ16)   // 22
irq_index(CMIF_C2M_U3G_BRP_IRQ17)   // 23
irq_index(CMIF_C2M_U3G_BRP_IRQ18)   // 24
irq_index(CMIF_C2M_U3G_BRP_IRQ19)   // 25
irq_index(CMIF_C2M_U3G_BRP_IRQ1A)   // 26
irq_index(CMIF_C2M_U3G_BRP_IRQ1B)   // 27
irq_index(CMIF_C2M_U3G_BRP_IRQ1C)   // 28
irq_index(CMIF_C2M_U3G_BRP_IRQ1D)   // 29
irq_index(CMIF_C2M_U3G_BRP_IRQ1E)   // 30
irq_index(CMIF_C2M_U3G_BRP_IRQ1F)   // 31

#endif  /* !__MAUI_BASIC__ */
