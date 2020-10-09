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
 *   global_cc_irq_id.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   CC IRQ Index user definition for MD1 and MD3.
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
//- CC IRQ Index user definition 
#ifndef _GLOBAL_CC_IRQ_ID_H_
#define _GLOBAL_CC_IRQ_ID_H_

typedef enum {
    /* L2P */
    CC_IRQ_L2P_BASE = 0UL,
    /* 0 */
    CC_IRQ_L2P_SYS = CC_IRQ_L2P_BASE,
    CC_IRQ_L2P_SLEEP_MODE,
    CC_IRQ_L2P_GSM,
    CC_IRQ_L2P_DSP,
    CC_IRQ_L2P_TDD_0,
    /* 5 */
    CC_IRQ_L2P_TDD_1,
    CC_IRQ_L2P_FDD,
    CC_IRQ_L2P_PS_SUBFRM_IND,
    CC_IRQ_L2P_PHR_IND,   
    CC_IRQ_L2P_END,
    
    /* L2MD3 */
    CC_IRQ_L2MD3_BASE = CC_IRQ_L2P_END,	
    CC_IRQ_L2MD3_SYS = CC_IRQ_L2MD3_BASE,
    CC_IRQ_L2MD3_RTB,
    CC_IRQ_L2MD3_MMRF,    
    CC_IRQ_L2MD3_END,

    /* P2L */
    CC_IRQ_P2L_BASE = CC_IRQ_L2MD3_END,	
    CC_IRQ_P2L_SYS = CC_IRQ_P2L_BASE,
    CC_IRQ_P2L_SLEEP_MODE,    
    CC_IRQ_P2L_GSM,
    CC_IRQ_P2L_DSP_0,
    CC_IRQ_P2L_DSP_1,
    CC_IRQ_P2L_TDD,
    CC_IRQ_P2L_FDD,
    CC_IRQ_P2L_PS_SUBFRM_RSP,
    CC_IRQ_P2L_MSG4_IND,    
    CC_IRQ_P2L_END,

	/* P2MD3 */
    CC_IRQ_P2MD3_BASE = CC_IRQ_P2L_END,	
    CC_IRQ_P2MD3_SYS = CC_IRQ_P2MD3_BASE,   
    CC_IRQ_P2MD3_END,

	/* MD32P */    
    CC_IRQ_MD32P_BASE = CC_IRQ_P2MD3_END,			
    CC_IRQ_MD32P_SYS = CC_IRQ_MD32P_BASE,    
    CC_IRQ_MD32P_END,
    
	/* MD32L */    
    CC_IRQ_MD32L_BASE = CC_IRQ_MD32P_END,	
    CC_IRQ_MD32L_SYS = CC_IRQ_MD32L_BASE,
    CC_IRQ_MD32L_RTB,         
    CC_IRQ_MD32L_END 
} CC_IRQ_ID_T;


typedef enum {
    CC_IRQ_SUCCESS = 0,
    CC_IRQ_ERR_PARAM = -0x1001,
    CC_IRQ_ERR_CHANNEL_FULL = -0x1002,
    CC_IRQ_ERR_PEER_ASYNC = -0x1003      
} CC_IRQ_RET_STATUS_E;

typedef enum{
    /* start of exception */
//    CC_IRQ_PEER_TRIGGER_EXCEP = 0, /* no use */
    /* start of no response */
    CC_IRQ_PEER_NO_RESPONSE_TX = 0x101, /* tx channel full */
    CC_IRQ_PEER_NO_RESPONSE_SYNC,       /* long time no response */    
    CC_IRQ_PEER_EXCEP_MAX
} CC_IRQ_PEER_EXCEP_REASON_T;

#endif /* _GLOBAL_CC_IRQ_ID_H_ */

/* End of file */

