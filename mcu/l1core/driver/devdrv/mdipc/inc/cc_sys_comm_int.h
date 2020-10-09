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
 *   cc_sys_comm_int.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   Internal definition of CC SYS IRQ.
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
#ifndef __CC_SYS_COMM_INT__
#define __CC_SYS_COMM_INT__
#include "cc_sys_comm_public.h"

#define CC_SYS_COMM_BUFF_MAX        64UL
//#define CC_SYS_COMM_RX_THRESHOLD    ((CC_SYS_COMM_BUFF_MAX / 4) * 3) /*48*/
#define CC_SYS_COMM_RX_THRESHOLD    ((CC_SYS_COMM_BUFF_MAX / 4) * 2) /*32*/ /* wolf need restore */ /* need remove */
#define CC_SYS_COMM_LOG_MAX         64UL

#define CC_IRQ_SYS_TX_TIMEOUT              (10000UL)    /* 10ms */
#define CC_IRQ_SYS_TX_POLLING_DISABLE    (0xFFFFFFFFUL)

typedef struct {
    kal_uint32 comm_id;      
    kal_uint32 data[2];      
    kal_uint32 dbg_rx_global_ts; /* the value is FRC(us)/64 */ 
} cc_sys_comm_buff_t;


typedef struct {
    kal_uint32 flow_ctrl_enable; 
} cc_sys_comm_shared_buff_ctrl_t;

#if defined(__PCORE__)
#define CC_SYS_COMM_RX_MD1_NUMBER    (CC_SYS_COMM_L2P_END - CC_SYS_COMM_L2P_BASE)
#define CC_SYS_COMM_TX_MD1_NUMBER    (CC_SYS_COMM_P2L_END - CC_SYS_COMM_P2L_BASE)
#elif defined(__L1CORE__)
#define CC_SYS_COMM_RX_MD1_NUMBER    (CC_SYS_COMM_P2L_END - CC_SYS_COMM_P2L_BASE)
#define CC_SYS_COMM_TX_MD1_NUMBER    (CC_SYS_COMM_L2P_END - CC_SYS_COMM_L2P_BASE)
#endif

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */		
    #if defined(__PCORE__)
    #define CC_SYS_COMM_RX_MD3_NUMBER    (CC_SYS_COMM_MD32P_END - CC_SYS_COMM_MD32P_BASE)
    #define CC_SYS_COMM_TX_MD3_NUMBER    (CC_SYS_COMM_P2MD3_END - CC_SYS_COMM_P2MD3_BASE)
    #elif defined(__L1CORE__)
    #define CC_SYS_COMM_RX_MD3_NUMBER    (CC_SYS_COMM_MD32L_END - CC_SYS_COMM_MD32L_BASE)
    #define CC_SYS_COMM_TX_MD3_NUMBER    (CC_SYS_COMM_L2MD3_END - CC_SYS_COMM_L2MD3_BASE)
    #endif		
/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

#if defined(__PCORE__)
#define CC_SYS_COMM_TX_IS_IN_RANGE(comm_id)                 ((comm_id) >= CC_SYS_COMM_P2L_BASE && (comm_id) < CC_SYS_COMM_P2L_END)
#define CC_SYS_COMM_RX_IS_IN_RANGE(comm_id)                 ((comm_id) >= CC_SYS_COMM_L2P_BASE && (comm_id) < CC_SYS_COMM_L2P_END)
#define CC_SYS_COMM_TX_MD1_OFFSET(comm_id)                      ((comm_id) - CC_SYS_COMM_P2L_BASE)
#define CC_SYS_COMM_RX_MD1_OFFSET(comm_id)                      ((comm_id) - CC_SYS_COMM_L2P_BASE)
//#define CC_SYS_COMM_TX_TO_MD1(comm_id)                      ((comm_id) >= CC_SYS_COMM_P2L_BASE && (comm_id) < CC_SYS_COMM_P2L_END)
#define CC_SYS_COMM_RX_FROM_MD1(comm_id)                    ((comm_id) >= CC_SYS_COMM_L2P_BASE && (comm_id) < CC_SYS_COMM_L2P_END) 

  #if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
  /* below for MD3 -------------------------------------------------- */
  #undef  CC_SYS_COMM_TX_IS_IN_RANGE  
  #undef  CC_SYS_COMM_RX_IS_IN_RANGE
  #define CC_SYS_COMM_TX_IS_IN_RANGE(comm_id)                 ((comm_id) >= CC_SYS_COMM_P2L_BASE && (comm_id) < CC_SYS_COMM_P2MD3_END)
  #define CC_SYS_COMM_RX_IS_IN_RANGE(comm_id)                 ( ((comm_id) >= CC_SYS_COMM_L2P_BASE && (comm_id) < CC_SYS_COMM_L2P_END) || ((comm_id) >= CC_SYS_COMM_MD32P_BASE && (comm_id) < CC_SYS_COMM_MD32P_END) )
  #define CC_SYS_COMM_RX_MD3_OFFSET(comm_id)                  ((comm_id) - CC_SYS_COMM_MD32P_BASE)
  #define CC_SYS_COMM_TX_MD3_OFFSET(comm_id)                  ((comm_id) - CC_SYS_COMM_P2MD3_BASE)  
  #define CC_SYS_COMM_TX_TO_MD3(comm_id)                      ((comm_id) >= CC_SYS_COMM_P2MD3_BASE && (comm_id) < CC_SYS_COMM_P2MD3_END)
  #define CC_SYS_COMM_RX_FROM_MD3(comm_id)                    ((comm_id) >= CC_SYS_COMM_MD32P_BASE && (comm_id) < CC_SYS_COMM_MD32P_END)  
  #define CC_SYS_COMM_RX_MD3_EPOF_NOTIFICATION(comm_id)       (comm_id == CC_SYS_COMM_MD32P_EPOF_NOTIFICATION)  
  /* up for MD3    -------------------------------------------------- */
  #endif/*_MD3_SUPPORT_*/

#elif defined(__L1CORE__)
#define CC_SYS_COMM_TX_IS_IN_RANGE(comm_id)                 ((comm_id) >= CC_SYS_COMM_L2P_BASE && (comm_id) < CC_SYS_COMM_L2P_END)
#define CC_SYS_COMM_RX_IS_IN_RANGE(comm_id)                 ((comm_id) >= CC_SYS_COMM_P2L_BASE && (comm_id) < CC_SYS_COMM_P2L_END)
#define CC_SYS_COMM_TX_MD1_OFFSET(comm_id)                      ((comm_id) - CC_SYS_COMM_L2P_BASE)
#define CC_SYS_COMM_RX_MD1_OFFSET(comm_id)                      ((comm_id) - CC_SYS_COMM_P2L_BASE)
//#define CC_SYS_COMM_TX_TO_MD1(comm_id)                      ((comm_id) >= CC_SYS_COMM_L2P_BASE && (comm_id) < CC_SYS_COMM_L2P_END)
#define CC_SYS_COMM_RX_FROM_MD1(comm_id)                    ((comm_id) >= CC_SYS_COMM_P2L_BASE && (comm_id) < CC_SYS_COMM_P2L_END)

  #if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
  /* below for MD3 -------------------------------------------------- */
  #undef  CC_SYS_COMM_TX_IS_IN_RANGE  
  #undef  CC_SYS_COMM_RX_IS_IN_RANGE
  #define CC_SYS_COMM_TX_IS_IN_RANGE(comm_id)                 ((comm_id) >= CC_SYS_COMM_L2P_BASE && (comm_id) < CC_SYS_COMM_L2MD3_END)
  #define CC_SYS_COMM_RX_IS_IN_RANGE(comm_id)                 ( ((comm_id) >= CC_SYS_COMM_P2L_BASE && (comm_id) < CC_SYS_COMM_P2L_END) || ((comm_id) >= CC_SYS_COMM_MD32L_BASE && (comm_id) < CC_SYS_COMM_MD32L_END) )
  #define CC_SYS_COMM_RX_MD3_OFFSET(comm_id)                  ((comm_id) - CC_SYS_COMM_MD32L_BASE)
  #define CC_SYS_COMM_TX_MD3_OFFSET(comm_id)                  ((comm_id) - CC_SYS_COMM_L2MD3_BASE)  
  #define CC_SYS_COMM_TX_TO_MD3(comm_id)                      ((comm_id) >= CC_SYS_COMM_L2MD3_BASE && (comm_id) < CC_SYS_COMM_L2MD3_END)
  #define CC_SYS_COMM_RX_FROM_MD3(comm_id)                    ((comm_id) >= CC_SYS_COMM_MD32L_BASE && (comm_id) < CC_SYS_COMM_MD32L_END)   
  #define CC_SYS_COMM_RX_MD3_EPOF_NOTIFICATION(comm_id)       (comm_id == CC_SYS_COMM_MD32L_EPOF_NOTIFICATION)  
  /* up for MD3    -------------------------------------------------- */
  #endif/*_MD3_SUPPORT_*/

#endif

extern void cc_sys_comm_init();

#endif    /* __CC_SYS_COMM_INT__ */

