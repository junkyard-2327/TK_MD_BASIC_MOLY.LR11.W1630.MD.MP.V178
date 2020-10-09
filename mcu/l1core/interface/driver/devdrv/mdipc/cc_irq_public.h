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
 *   cc_irq_public.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This Module defines CC IRQ API.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CC_IRQ_PUBLIC_H__
#define __CC_IRQ_PUBLIC_H__

#include "global_cc_irq_id.h"
#include "global_cc_user_share_mem_id.h"
/*****************************************************************************
 * Value Definition                                                          *
 *****************************************************************************/
#define CC_IRQ_L2P_NUMBER    (CC_IRQ_L2P_END - CC_IRQ_L2P_BASE)
#define CC_IRQ_P2L_NUMBER    (CC_IRQ_P2L_END - CC_IRQ_P2L_BASE)

#define CC_IRQ_INVALID_VALUE    (0xDEADBEEF)

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
#define CC_IRQ_L2MD3_NUMBER    (CC_IRQ_L2MD3_END - CC_IRQ_L2MD3_BASE)
#define CC_IRQ_P2MD3_NUMBER    (CC_IRQ_P2MD3_END - CC_IRQ_P2MD3_BASE)
#define CC_IRQ_MD32L_NUMBER    (CC_IRQ_MD32L_END - CC_IRQ_MD32L_BASE)
#define CC_IRQ_MD32P_NUMBER    (CC_IRQ_MD32P_END - CC_IRQ_MD32P_BASE)
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

/*****************************************************************************
 * Public Definition                                                         *
 *****************************************************************************/
typedef void (*CC_IRQ_CALLBACK_P)(kal_uint32 para0, kal_uint32 para1, kal_uint32 para2);

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/ /* spinlock for MD1 & MD3 */
/* below for MD3 -------------------------------------------------- */
typedef struct
{
   void       *spinlock_p;/* point to spinlock_t*/
   kal_uint32 irq_status;
   kal_uint32 direction;/* to know its direction and already be initial */   
} CC_SPINLOCK_T;

#define cc_spinlockid CC_SPINLOCK_T*
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/


/*****************************************************************************
 * Public Function                                                           *
 *****************************************************************************/
extern kal_uint32 cc_irq_param_channel_full(kal_uint32 cc_index);
extern kal_uint32 cc_irq_buffer_channel_full(kal_uint32 cc_index); 
extern void cc_irq_init();
extern void cc_irq_sync_init_HS1();

/* RX Side Functions */
extern kal_int32 cc_irq_register_callback(kal_uint32 cc_index, CC_IRQ_CALLBACK_P funcp);
extern kal_int32 cc_irq_mask(kal_uint32 cc_index);
extern kal_int32 cc_irq_unmask(kal_uint32 cc_index);
extern kal_uint32 cc_irq_get_md1_wakeup_status();

/* TX Sdie Functions */ 
extern kal_int32 cc_irq_trigger_interrupt(kal_uint32 cc_index, \
            kal_uint32 para0, kal_uint32 para1, kal_uint32 para2);
extern kal_int32 cc_irq_trigger_interrupt_with_buff(kal_uint32 cc_index, void *addr, kal_uint32 length);
//extern kal_uint32 cc_irq_init_ready();

/* only for MD3 exist */
extern void cc_irq_md1_md3_shared_mem_config();

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
extern kal_uint32 *cc_irq_get_md1_md3_user_shared_memory(kal_uint32 user_id, kal_uint32 size);
extern kal_uint32 cc_irq_get_md3_wakeup_status();

extern cc_spinlockid cc_spin_create_spinlock(kal_char *lock_name);
extern kal_status cc_spin_take_spinlock(cc_spinlockid ext_spinlock_id_ptr, kal_wait_mode wait_mode);
extern void cc_spin_give_spinlock(cc_spinlockid ext_spinlock_id_ptr);
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

#endif    /* __CC_IRQ_PUBLIC_H__ */

