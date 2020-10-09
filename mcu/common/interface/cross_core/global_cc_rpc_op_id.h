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
 *   global_cc_rpc_op_id.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   CC IRQ RPC operation ID definition for MD1 and MD3.
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


#ifndef _GLOBAL_CC_RPC_OP_ID_H_
#define _GLOBAL_CC_RPC_OP_ID_H_

 
typedef enum {
    CC_IRQ_RPC_SUCCESS = 0,
    CC_IRQ_RPC_ERR_PARAM = -0x1001,
    CC_IRQ_RPC_SHRAE_BUFFER_FULL = -0x1002,    
    CC_IRQ_RPC_TX_CALLED_DURING_INIT = -0x1003,
} CC_IRQ_RPC_RET_STATUS_E;

typedef enum {
	/* PScore RPC service */
    CC_IRQ_RPC_MD32P_BASE = 0, 	
    CC_IRQ_RPC_MD32P_MRS_OCCUPY_LLA = CC_IRQ_RPC_MD32P_BASE,
    CC_IRQ_RPC_MD32P_MRS_RELEASE_LLA,  
    CC_IRQ_RPC_MD32P_MRS_GET_LLA_OCCUPY_RAT,    
    CC_IRQ_RPC_MD32P_AS_SERVICE_SEM_OCCUPY,
    CC_IRQ_RPC_MD32P_AS_SERVICE_SEM_RELEASE,
    CC_IRQ_RPC_MD32P_AS_SERVICE_SEM_TRANSFER,
    CC_IRQ_RPC_MD32P_AS_SERVICE_SEM_QUERY,
    CC_IRQ_RPC_MD32P_END,
	/* L1core RPC service */    
    CC_IRQ_RPC_MD32L_BASE = CC_IRQ_RPC_MD32P_END,    
    CC_IRQ_RPC_MD32L_TEST1 = CC_IRQ_RPC_MD32L_BASE,
    CC_IRQ_RPC_MD32L_TEST2,  
    CC_IRQ_RPC_MD32L_TEST3,
    CC_IRQ_RPC_MD32L_TEST4,    
    CC_IRQ_RPC_MD32L_END,
	/* MD3 RPC service */    
    CC_IRQ_RPC_P2MD3_BASE = CC_IRQ_RPC_MD32L_END,    
    CC_IRQ_RPC_P2MD3_TEST1 = CC_IRQ_RPC_P2MD3_BASE,  
    CC_IRQ_RPC_P2MD3_TEST2,     
    CC_IRQ_RPC_P2MD3_TEST3,
    CC_IRQ_RPC_P2MD3_TEST4,    
    CC_IRQ_RPC_P2MD3_END,	
    CC_IRQ_RPC_L2MD3_BASE = CC_IRQ_RPC_P2MD3_END,    
    CC_IRQ_RPC_L2MD3_TEST1 = CC_IRQ_RPC_L2MD3_BASE,  
    CC_IRQ_RPC_L2MD3_TEST2,     
    CC_IRQ_RPC_L2MD3_TEST3,
    CC_IRQ_RPC_L2MD3_TEST4,    
    CC_IRQ_RPC_L2MD3_END,    
} CC_IRQ_RPC_OP_ID_T;

#endif /* _GLOBAL_CC_RPC_OP_ID_H_ */

/* End of file */

