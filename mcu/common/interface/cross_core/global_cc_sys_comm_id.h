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
 *   global_cc_sys_comm_id.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   Define the Communication ID for CC SYS IRQ
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
#ifndef _GLOBAL_CC_SYS_COMM_ID_H_
#define _GLOBAL_CC_SYS_COMM_ID_H_


typedef enum {
    CC_SYS_COMM_L2P_BASE = 0, 
    /*L2P*//*0*/
    CC_SYS_COMM_L2P_IPC = CC_SYS_COMM_L2P_BASE,	/* for ILM */
    CC_SYS_COMM_L2P_EVG, 
    CC_SYS_COMM_L2P_MUTEX, 
    CC_SYS_COMM_L2P_SYNC,
    CC_SYS_COMM_L2P_END, 
    /*L2MD3*/
    CC_SYS_COMM_L2MD3_BASE = CC_SYS_COMM_L2P_END,	
    CC_SYS_COMM_L2MD3_MSG = CC_SYS_COMM_L2MD3_BASE,
    CC_SYS_COMM_L2MD3_RPC, 
    CC_SYS_COMM_L2MD3_SYNC,   /* L1core only receive state change pkt from MD3 but doesn't send to MD3 */  
    CC_SYS_COMM_L2MD3_END,
    /*P2L*/
    CC_SYS_COMM_P2L_BASE = CC_SYS_COMM_L2MD3_END,	
    CC_SYS_COMM_P2L_IPC = CC_SYS_COMM_P2L_BASE,
    CC_SYS_COMM_P2L_EVG, 
    CC_SYS_COMM_P2L_MUTEX,
    CC_SYS_COMM_P2L_SYNC,  
    CC_SYS_COMM_P2L_END,
    /*P2MD3*/
    CC_SYS_COMM_P2MD3_BASE = CC_SYS_COMM_P2L_END,	
    CC_SYS_COMM_P2MD3_MSG = CC_SYS_COMM_P2MD3_BASE,
    CC_SYS_COMM_P2MD3_RPC,
    CC_SYS_COMM_P2MD3_SYNC,    
    CC_SYS_COMM_P2MD3_END,
    /*MD32P*/
    CC_SYS_COMM_MD32P_BASE = CC_SYS_COMM_P2MD3_END,	
    CC_SYS_COMM_MD32P_MSG = CC_SYS_COMM_MD32P_BASE,
    CC_SYS_COMM_MD32P_RPC,
    CC_SYS_COMM_MD32P_SYNC,
    CC_SYS_COMM_MD32P_EPOF_NOTIFICATION,    
    CC_SYS_COMM_MD32P_END,
    /*MD32L*/
    CC_SYS_COMM_MD32L_BASE = CC_SYS_COMM_MD32P_END,	
    CC_SYS_COMM_MD32L_MSG = CC_SYS_COMM_MD32L_BASE,
    CC_SYS_COMM_MD32L_RPC, 
    CC_SYS_COMM_MD32L_SYNC,
    CC_SYS_COMM_MD32L_EPOF_NOTIFICATION,    
    CC_SYS_COMM_MD32L_END
} CC_SYS_COMM_ID_MASTER_T;

typedef enum {
    CC_SYS_COMM_SUCCESS = 0,
    CC_SYS_COMM_ERR_PARAM = -0x1001,
    CC_SYS_COMM_TX_CALLED_DURING_INIT = -0x1002,
} CC_SYS_COMM_RET_STATUS_E;

#endif /* _GLOBAL_CC_SYS_COMM_ID_H_ */

/* End of file*/

