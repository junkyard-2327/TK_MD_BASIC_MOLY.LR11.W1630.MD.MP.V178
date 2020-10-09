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
 *   cc_irq_adaptation.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   Adaptation layer for CC IRQ.
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
 *
 *****************************************************************************/
#ifndef __CC_IRQ_ADAPTATION_H__
#define __CC_IRQ_ADAPTATION_H__

#include "intrCtrl.h"
#include "cc_irq_public.h"
#include "us_timer.h"
#include "sync_data.h"
#include "kal_public_api.h"
#include "cc_irq_int.h"
#include "kal_internal_api.h"
#include "cc_sys_comm_int.h"

#if defined(CC_IRQ_IT)
  #if defined(__PCORE__)
  #define CC_IRQ_IRQ_CODE            IRQ_L2P_CCIRQ_0_CODE, IRQ_L2P_CCIRQ_1_CODE, IRQ_L2P_CCIRQ_2_CODE, IRQ_L2P_CCIRQ_3_CODE, \
                                     IRQ_L2P_CCIRQ_4_CODE, IRQ_L2P_CCIRQ_5_CODE, IRQ_L2P_CCIRQ_6_CODE, IRQ_L2P_CCIRQ_7_CODE, \
                                     IRQ_L2P_CCIRQ_8_CODE, IRQ_L2P_CCIRQ_9_CODE, IRQ_L2P_CCIRQ_10_CODE, IRQ_L2P_CCIRQ_11_CODE, IRQ_L2P_CCIRQ_12_CODE, IRQ_L2P_CCIRQ_13_CODE, IRQ_L2P_CCIRQ_14_CODE, IRQ_L2P_CCIRQ_15_CODE
  #define CC_IRQ_IRQ_CODE_FROM_MD3   IRQ_C2K_PS_CCIRQ_0_CODE, IRQ_C2K_PS_CCIRQ_1_CODE, IRQ_C2K_PS_CCIRQ_2_CODE, IRQ_C2K_PS_CCIRQ_3_CODE                                  
  #else /* L1core */
  #define CC_IRQ_IRQ_CODE            IRQ_P2L_CCIRQ_0_CODE, IRQ_P2L_CCIRQ_1_CODE, IRQ_P2L_CCIRQ_2_CODE, IRQ_P2L_CCIRQ_3_CODE, IRQ_P2L_CCIRQ_4_CODE, \
                                     IRQ_P2L_CCIRQ_5_CODE, IRQ_P2L_CCIRQ_6_CODE, IRQ_P2L_CCIRQ_7_CODE, \
                                     IRQ_P2L_CCIRQ_8_CODE, IRQ_P2L_CCIRQ_9_CODE, IRQ_P2L_CCIRQ_10_CODE, IRQ_P2L_CCIRQ_11_CODE, IRQ_P2L_CCIRQ_12_CODE, IRQ_P2L_CCIRQ_13_CODE, IRQ_P2L_CCIRQ_14_CODE, IRQ_P2L_CCIRQ_15_CODE 
  #define CC_IRQ_IRQ_CODE_FROM_MD3   IRQ_C2K_L1_CCIRQ_0_CODE, IRQ_C2K_L1_CCIRQ_1_CODE, IRQ_C2K_L1_CCIRQ_2_CODE, IRQ_C2K_L1_CCIRQ_3_CODE, \
                                     IRQ_C2K_L1_CCIRQ_4_CODE, IRQ_C2K_L1_CCIRQ_5_CODE, IRQ_C2K_L1_CCIRQ_6_CODE, IRQ_C2K_L1_CCIRQ_7_CODE  	
  #endif
#endif

#if defined(__PCORE__)
#define CC_IRQ_MD1_IRQ_START_INDEX     IRQ_L2P_CCIRQ_0_CODE /*IRQ_L2P_CCIRQ_0_CODE=85*/ 
#else/* L1core */
#define CC_IRQ_MD1_IRQ_START_INDEX     IRQ_P2L_CCIRQ_0_CODE /*IRQ_P2L_CCIRQ_0_CODE=80*/
#endif

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */

#if defined(TK6291)/* fake IRQ ID in TK6291==> there is no MD3, for build pass only */
#define IRQ_C2K_PS_CCIRQ_0_CODE    0
#define IRQ_C2K_L1_CCIRQ_0_CODE    0
#endif

#if defined(__PCORE__)
#define CC_IRQ_MD3_IRQ_START_INDEX     IRQ_C2K_PS_CCIRQ_0_CODE /*IRQ_C2K_PS_CCIRQ_0_CODE=108*/
#else/* L1core */
#define CC_IRQ_MD3_IRQ_START_INDEX     IRQ_C2K_L1_CCIRQ_0_CODE /*IRQ_C2K_L1_CCIRQ_0_CODE=96*/
#endif
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

/* Memory Barrier */
#define CC_IRQ_DMB()    Data_Mem_Barrier()

extern kal_bool INT_QueryExceptionStatus(void);
/* USC */
#define CC_IRQ_GET_US()                                       ust_get_current_time()
#define CC_IRQ_GET_DURATION_US(start, end, duration)    (duration = ust_us_duration((start), (end)))
/* global timestamp between PScore and L1core */
#define CC_IRQ_GET_GLB_TS()                                     fma_get_glb_ts()/* the value is FRC(us)/64 */

/* ==== Interrupt Driver Adaptation ==== */
#define CC_IRQ_DRV_MASK(irq_number)                        IRQMask(irq_number)
#define CC_IRQ_DRV_UNMASK(irq_number)                      IRQUnmask(irq_number)

#define CC_IRQ_IN_EXCEP()                                  INT_QueryExceptionStatus()
#define CC_IRQ_SET_SENSITIVITY_LEVEL(irq_number)                IRQSensitivity((irq_number), LEVEL_SENSITIVE)
#define CC_IRQ_DRV_MASK_ALL_INTERRUPT(irq_status)          do { \
	                                                             irq_status = SaveAndSetIRQMask(); \
	                                                         } while(0)
#define CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(irq_status)       RestoreIRQMask(irq_status)
//#define CC_IRQ_FREE_BUFFER(buffer_addr)                 free_local_para(buffer_addr)

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */
extern kal_bool gmss_is_cdma2000_supported();
#define CC_IRQ_MD3_IS_EXIST()                      gmss_is_cdma2000_supported()
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

#if defined(__PCORE__)
#define CC_IRQ_TX_INDEX_IS_IN_RANGE(cc_index)                 ((cc_index) >= CC_IRQ_P2L_BASE && (cc_index) < CC_IRQ_P2L_END)
#define CC_IRQ_RX_INDEX_IS_IN_RANGE(cc_index)                 ((cc_index) >= CC_IRQ_L2P_BASE && (cc_index) < CC_IRQ_L2P_END)
#define CC_IRQ_TX_MD1_INDEX_OFFSET(cc_index)                      ((cc_index) - CC_IRQ_P2L_BASE)
#define CC_IRQ_RX_MD1_INDEX_OFFSET(cc_index)                      ((cc_index) - CC_IRQ_L2P_BASE)

  #if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
  /* below for MD3 -------------------------------------------------- */	
  #undef  CC_IRQ_TX_INDEX_IS_IN_RANGE
  #undef  CC_IRQ_RX_INDEX_IS_IN_RANGE
  #define CC_IRQ_TX_INDEX_IS_IN_RANGE(cc_index)                 ((cc_index) >= CC_IRQ_P2L_BASE && (cc_index) < CC_IRQ_P2MD3_END)
  #define CC_IRQ_RX_INDEX_IS_IN_RANGE(cc_index)                 ( ((cc_index) >= CC_IRQ_L2P_BASE && (cc_index) < CC_IRQ_L2P_END) || ((cc_index) >= CC_IRQ_MD32P_BASE && (cc_index) < CC_IRQ_MD32P_END) )
  #define CC_IRQ_RX_MD3_INDEX_OFFSET(cc_index)                      ((cc_index) - CC_IRQ_MD32P_BASE)
  #define CC_IRQ_TX_MD3_INDEX_OFFSET(cc_index)                      ((cc_index) - CC_IRQ_P2MD3_BASE)  
  #define CC_IRQ_TX_TO_MD3(cc_index)                                ((cc_index) >= CC_IRQ_P2MD3_BASE && (cc_index) < CC_IRQ_P2MD3_END)
  #define CC_IRQ_RX_FROM_MD3(cc_index)                              ((cc_index) >= CC_IRQ_MD32P_BASE && (cc_index) < CC_IRQ_MD32P_END)      
  /* up for MD3    -------------------------------------------------- */
  #endif/*_MD3_SUPPORT_*/

#elif defined(__L1CORE__)
#define CC_IRQ_TX_INDEX_IS_IN_RANGE(cc_index)                 ((cc_index) >= CC_IRQ_L2P_BASE && (cc_index) < CC_IRQ_L2P_END)
#define CC_IRQ_RX_INDEX_IS_IN_RANGE(cc_index)                 ((cc_index) >= CC_IRQ_P2L_BASE && (cc_index) < CC_IRQ_P2L_END)
#define CC_IRQ_TX_MD1_INDEX_OFFSET(cc_index)                      ((cc_index) - CC_IRQ_L2P_BASE)
#define CC_IRQ_RX_MD1_INDEX_OFFSET(cc_index)                      ((cc_index) - CC_IRQ_P2L_BASE)

  #if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
  /* below for MD3 -------------------------------------------------- */		
  #undef  CC_IRQ_TX_INDEX_IS_IN_RANGE  
  #undef  CC_IRQ_RX_INDEX_IS_IN_RANGE
  #define CC_IRQ_TX_INDEX_IS_IN_RANGE(cc_index)                 ((cc_index) >= CC_IRQ_L2P_BASE && (cc_index) < CC_IRQ_L2MD3_END)
  #define CC_IRQ_RX_INDEX_IS_IN_RANGE(cc_index)                 ( ((cc_index) >= CC_IRQ_P2L_BASE && (cc_index) < CC_IRQ_P2L_END) || ((cc_index) >= CC_IRQ_MD32L_BASE && (cc_index) < CC_IRQ_MD32L_END) )  
  #define CC_IRQ_RX_MD3_INDEX_OFFSET(cc_index)                      ((cc_index) - CC_IRQ_MD32L_BASE)
  #define CC_IRQ_TX_MD3_INDEX_OFFSET(cc_index)                      ((cc_index) - CC_IRQ_L2MD3_BASE)
  #define CC_IRQ_TX_TO_MD3(cc_index)                                ((cc_index) >= CC_IRQ_L2MD3_BASE && (cc_index) < CC_IRQ_L2MD3_END)  
  #define CC_IRQ_RX_FROM_MD3(cc_index)                              ((cc_index) >= CC_IRQ_MD32L_BASE && (cc_index) < CC_IRQ_MD32L_END)      
  /* up for MD3    -------------------------------------------------- */
  #endif/*_MD3_SUPPORT_*/

#endif


#endif  /* __CC_IRQ_ADAPTATION_H__ */

