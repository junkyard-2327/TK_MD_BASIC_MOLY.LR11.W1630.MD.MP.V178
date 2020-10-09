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
 *   global_cc_sync_func_id.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   CC IRQ SYNC function ID definition for MD1 and MD3.
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
 
/* for function registered by user to execute before/after sync packet to/from MD3. */
/* CC IRQ SYNC function ID */
#ifndef _GLOBAL_CC_SYNC_FUNC_ID_H_
#define _GLOBAL_CC_SYNC_FUNC_ID_H_


typedef enum {
    CC_IRQ_SYNC_P2MD3_BASE = 0,
    /* ==== Start of PScore to MD3 sync index(PScore ping MD3) ==== */
    CC_IRQ_SYNC_P2MD3_LPM_CNT = CC_IRQ_SYNC_P2MD3_BASE,
    /* ==== End of PScore to MD3 sync index(PScore ping MD3) ==== */
    CC_IRQ_SYNC_P2MD3_END, 
    CC_IRQ_SYNC_MD32P_START = CC_IRQ_SYNC_P2MD3_END,
    /* ==== Start of MD3 to PScore sync index(MD3 ack PScore) ==== */ 
//    CC_IRQ_SYNC_MD32P_RESERVED = CC_IRQ_SYNC_MD32P_START,
    /* ==== End of MD3 to PScore sync index(MD3 ack PScore) ==== */
    CC_IRQ_SYNC_MD32P_END = CC_IRQ_SYNC_MD32P_START /* no user now */
} CC_IRQ_SYNC_FUNC_ID_T;

typedef enum {
    CC_IRQ_SYS_STATE_INIT = 0,
    CC_IRQ_SYS_STATE_RUNNING,
    CC_IRQ_SYS_STATE_ASYNC,    
    CC_IRQ_SYS_STATE_MAX
} CC_IRQ_SYS_STATE_T;

typedef enum{
    CC_IRQ_SYNC_PKT_TYPE_INIT_HS1 = 0x1111,
    CC_IRQ_SYNC_PKT_TYPE_INIT_HS2 = 0x2222,		
    CC_IRQ_SYNC_PKT_TYPE_PING = 0xCCCC,
    CC_IRQ_SYNC_PKT_TYPE_PING_ACK = 0xAAAA,    
    CC_IRQ_SYNC_PKT_MAX
} CC_IRQ_SYNC_PKT_TYPE_T;	

#endif  /* _GLOBAL_CC_SYNC_FUNC_ID_H_ */

/* End of file*/

