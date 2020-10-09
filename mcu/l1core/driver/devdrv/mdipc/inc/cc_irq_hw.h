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
 *   cc_irq_hw.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file is the CC IRQ HW API for MD1/MD3
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
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
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 *****************************************************************************/

#ifndef __CC_IRQ_HW_H__
#define __CC_IRQ_HW_H__

#include "reg_base.h"

#if defined(__PCORE__)
#define CC_IRQ_REG_base       L1_BASE_MADDR_PS2L1_CCIRQ /* PSCore to L1core, for TX */
#define CC_IRQ_REG_RX_base    L1_BASE_MADDR_L12PS_CCIRQ /* L1core to PSCore, for RX */
#elif defined(__L1CORE__)
#define CC_IRQ_REG_base       L1_BASE_MADDR_L12PS_CCIRQ
#define CC_IRQ_REG_RX_base    L1_BASE_MADDR_PS2L1_CCIRQ
#else
#error "Correct core type should be defined"
#endif
/* Use for TX */
#define CC_IRQ_SET_IRQ            ((volatile kal_uint32 *)(CC_IRQ_REG_base + 0x00))
#define CC_IRQ_CLEAR_IRQ          ((volatile kal_uint32 *)(CC_IRQ_REG_base + 0x04))
#define CC_IRQ_CLEAR_AUTH_EXEC    ((volatile kal_uint32 *)(CC_IRQ_REG_base + 0x0C))
#define CC_IRQ_EXC_IRQ            ((volatile kal_uint32 *)(CC_IRQ_REG_base + 0x10))
#define CC_IRQ_EXC_AUTH_FAIL      ((volatile kal_uint32 *)(CC_IRQ_REG_base + 0x14))
#define CC_IRQ_EXC_OVERFLOW       ((volatile kal_uint32 *)(CC_IRQ_REG_base + 0x18))

#define CC_IRQ_CTI_EVENT          ((volatile kal_uint32 *)(CC_IRQ_REG_base + 0x80))

/* Use for RX */
#define CC_IRQ_EXC_UNDERFLOW      ((volatile kal_uint32 *)(CC_IRQ_REG_RX_base + 0x1C))
#define CC_IRQ_CNT_IRQ(n)         ((volatile kal_uint32 *)(CC_IRQ_REG_RX_base + 0x100 + 4 * (n)))
#define CC_IRQ_CNT_ACK(n)         ((volatile kal_uint32 *)(CC_IRQ_REG_RX_base + 0x180 + 4 * (n)))

/* CC_IRQ_WAKEUPxxx only support on JADE(MT6755) and later platform */
#define CC_IRQ_WAKEUP_MASK        ((volatile kal_uint32 *)(CC_IRQ_REG_RX_base + 0x30))
#define CC_IRQ_WAKEUP_MASK_SET    ((volatile kal_uint32 *)(CC_IRQ_REG_RX_base + 0x34))
#define CC_IRQ_WAKEUP_MASK_CLR    ((volatile kal_uint32 *)(CC_IRQ_REG_RX_base + 0x38))
#define CC_IRQ_WAKEUP_STA         ((volatile kal_uint32 *)(CC_IRQ_REG_RX_base + 0x3C))


/* Use for all core */
#define CC_IRQ_PS2L1_DUMMY_0            ((volatile kal_uint32 *)(L1_BASE_MADDR_PS2L1_CCIRQ + 0x40))
#define CC_IRQ_PS2L1_DUMMY_1            ((volatile kal_uint32 *)(L1_BASE_MADDR_PS2L1_CCIRQ + 0x44))
#define CC_IRQ_PS2L1_DUMMY_2            ((volatile kal_uint32 *)(L1_BASE_MADDR_PS2L1_CCIRQ + 0x48))
#define CC_IRQ_PS2L1_DUMMY_3            ((volatile kal_uint32 *)(L1_BASE_MADDR_PS2L1_CCIRQ + 0x4C))

#define CC_IRQ_L12PS_DUMMY_0            ((volatile kal_uint32 *)(L1_BASE_MADDR_L12PS_CCIRQ + 0x40))
#define CC_IRQ_L12PS_DUMMY_1            ((volatile kal_uint32 *)(L1_BASE_MADDR_L12PS_CCIRQ + 0x44))
#define CC_IRQ_L12PS_DUMMY_2            ((volatile kal_uint32 *)(L1_BASE_MADDR_L12PS_CCIRQ + 0x48))
#define CC_IRQ_L12PS_DUMMY_3            ((volatile kal_uint32 *)(L1_BASE_MADDR_L12PS_CCIRQ + 0x4C))

#define CC_IRQ_HW_WRITE_MAGIC    0xA0000000 
#define CC_IRQ_HW_ACK_MAGIC      0xB0000000
#define CC_IRQ_HW_WRITE_MAGIC_OFFSET    28
#define CC_IRQ_HW_WRITE_MAGIC_MASK      (0xF << CC_IRQ_HW_WRITE_MAGIC_OFFSET)

#define CC_IRQ_HW_TX_NUMBER     16 /* supported IRQ number between PScore and L1core */
#define CC_IRQ_HW_RX_NUMBER     16  
#define CC_IRQ_HW_CFG_NUMBER    4    //- number of RCCIF in a write register 
#define CC_IRQ_HW_CFG_BIT_SIZE  6                                       
#define CC_IRQ_HW_CFG_MASK      0x3F /* no use */                                   

#define CC_IRQ_HW_MAX_TRIG_CNT  31   /* no use, but HW support to 63 */ 

extern void cc_irq_hw_trigger_md1_irq(kal_uint32 cc_index);
extern void cc_irq_hw_ack_md1_irq(kal_uint32 cc_index, kal_uint32 prc_cnt);
extern kal_uint32 cc_irq_hw_get_md1_trigger_cnt(kal_uint32 cc_index);
extern kal_uint32 cc_irq_hw_get_md1_wakeup_status();

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */

#if defined(TK6291)/* fake Reg Base in TK6291==> there is no MD3, for build pass only */
#define BASE_MADDR_PS_C2K_CCIRQ    0
#define BASE_MADDR_C2K_PS_CCIRQ    0
#define BASE_MADDR_L1_C2K_CCIRQ    0
#define BASE_MADDR_C2K_L1_CCIRQ    0
#endif

#if defined(__PCORE__)
#define CC_IRQ_MD3_REG_base       BASE_MADDR_PS_C2K_CCIRQ /* PSCore to MD3, for TX */
#define CC_IRQ_MD3_REG_RX_base    BASE_MADDR_C2K_PS_CCIRQ /* MD3 to PSCore, for RX */
#elif defined(__L1CORE__)
#define CC_IRQ_MD3_REG_base       BASE_MADDR_L1_C2K_CCIRQ /* L1Core to MD3, for TX */
#define CC_IRQ_MD3_REG_RX_base    BASE_MADDR_C2K_L1_CCIRQ /* MD3 to L1Core, for RX */
#endif

/* Use for TX */
#define CC_IRQ_MD3_SET_IRQ            ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_base + 0x00))
#define CC_IRQ_MD3_CLEAR_IRQ          ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_base + 0x04))
#define CC_IRQ_MD3_CLEAR_AUTH_EXEC    ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_base + 0x0C))
#define CC_IRQ_MD3_EXC_IRQ            ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_base + 0x10))
#define CC_IRQ_MD3_EXC_AUTH_FAIL      ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_base + 0x14))
#define CC_IRQ_MD3_EXC_OVERFLOW       ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_base + 0x18))

#define CC_IRQ_MD3_CTI_EVENT          ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_base + 0x80))

/* Use for RX */
#define CC_IRQ_MD3_EXC_UNDERFLOW      ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_RX_base + 0x1C))
#define CC_IRQ_MD3_CNT_IRQ(n)         ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_RX_base + 0x100 + 4 * (n)))
#define CC_IRQ_MD3_CNT_ACK(n)         ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_RX_base + 0x180 + 4 * (n)))

/* CC_IRQ_MD3_WAKEUPxxx only support on JADE(MT6755) and later platform */
#define CC_IRQ_MD3_WAKEUP_MASK        ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_RX_base + 0x30))
#define CC_IRQ_MD3_WAKEUP_MASK_SET    ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_RX_base + 0x34))
#define CC_IRQ_MD3_WAKEUP_MASK_CLR    ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_RX_base + 0x38))
#define CC_IRQ_MD3_WAKEUP_STA         ((volatile kal_uint32 *)(CC_IRQ_MD3_REG_RX_base + 0x3C))

/* Use for all core */
#define CC_IRQ_PS2MD3_DUMMY_0            ((volatile kal_uint32 *)(BASE_MADDR_PS_C2K_CCIRQ + 0x40))
#define CC_IRQ_PS2MD3_DUMMY_1            ((volatile kal_uint32 *)(BASE_MADDR_PS_C2K_CCIRQ + 0x44))
#define CC_IRQ_PS2MD3_DUMMY_2            ((volatile kal_uint32 *)(BASE_MADDR_PS_C2K_CCIRQ + 0x48))
#define CC_IRQ_PS2MD3_DUMMY_3            ((volatile kal_uint32 *)(BASE_MADDR_PS_C2K_CCIRQ + 0x4C))
#define CC_IRQ_MD32PS_DUMMY_0            ((volatile kal_uint32 *)(BASE_MADDR_C2K_PS_CCIRQ + 0x40))
#define CC_IRQ_MD32PS_DUMMY_1            ((volatile kal_uint32 *)(BASE_MADDR_C2K_PS_CCIRQ + 0x44))
#define CC_IRQ_MD32PS_DUMMY_2            ((volatile kal_uint32 *)(BASE_MADDR_C2K_PS_CCIRQ + 0x48))
#define CC_IRQ_MD32PS_DUMMY_3            ((volatile kal_uint32 *)(BASE_MADDR_C2K_PS_CCIRQ + 0x4C))

#define CC_IRQ_L12MD3_DUMMY_0            ((volatile kal_uint32 *)(BASE_MADDR_L1_C2K_CCIRQ + 0x40))
#define CC_IRQ_L12MD3_DUMMY_1            ((volatile kal_uint32 *)(BASE_MADDR_L1_C2K_CCIRQ + 0x44))
#define CC_IRQ_L12MD3_DUMMY_2            ((volatile kal_uint32 *)(BASE_MADDR_L1_C2K_CCIRQ + 0x48))
#define CC_IRQ_L12MD3_DUMMY_3            ((volatile kal_uint32 *)(BASE_MADDR_L1_C2K_CCIRQ + 0x4C))
#define CC_IRQ_MD32L1_DUMMY_0            ((volatile kal_uint32 *)(BASE_MADDR_C2K_L1_CCIRQ + 0x40))
#define CC_IRQ_MD32L1_DUMMY_1            ((volatile kal_uint32 *)(BASE_MADDR_C2K_L1_CCIRQ + 0x44))
#define CC_IRQ_MD32L1_DUMMY_2            ((volatile kal_uint32 *)(BASE_MADDR_C2K_L1_CCIRQ + 0x48))
#define CC_IRQ_MD32L1_DUMMY_3            ((volatile kal_uint32 *)(BASE_MADDR_C2K_L1_CCIRQ + 0x4C))

#define CC_IRQ_MD3_HW_WRITE_MAGIC    0xA0000000 
#define CC_IRQ_MD3_HW_ACK_MAGIC      0xB0000000
#define CC_IRQ_MD3_HW_WRITE_MAGIC_OFFSET    28
#define CC_IRQ_MD3_HW_WRITE_MAGIC_MASK      (0xF << CC_IRQ_HW_WRITE_MAGIC_OFFSET)
#if defined(__PCORE__)
#define CC_IRQ_MD3_HW_TX_NUMBER     4  
#define CC_IRQ_MD3_HW_RX_NUMBER     4   
#define CC_IRQ_MD3_HW_MAX_TRIG_CNT  31    
#elif defined(__L1CORE__)
#define CC_IRQ_MD3_HW_TX_NUMBER     8  
#define CC_IRQ_MD3_HW_RX_NUMBER     8  
#define CC_IRQ_MD3_HW_MAX_TRIG_CNT  31    
#endif

extern void cc_irq_hw_trigger_md3_irq(kal_uint32 cc_index);
extern void cc_irq_hw_ack_md3_irq(kal_uint32 cc_index, kal_uint32 prc_cnt);
extern kal_uint32 cc_irq_hw_get_md3_trigger_cnt(kal_uint32 cc_index);
extern void cc_irq_hw_write_ps2md3_dummy(kal_uint32 index, kal_uint32 value);
extern kal_uint32 cc_irq_hw_get_ps2md3_dummy(kal_uint32 index);
extern kal_uint32 cc_irq_hw_get_md3_wakeup_status();
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

#endif  /* __CC_IRQ_HW_H__ */

