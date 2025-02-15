/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *
 * Filename:
 * ---------
 *   init_memory_stack.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Exported APIs for non-HAL users
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __INIT_MEMORY_STACK_H__
#define __INIT_MEMORY_STACK_H__

#include "kal_general_types.h"

/*************************************************************************
 * Define import function prototype
 *************************************************************************/
 
 /*******************************************************************************
 * <GROUP Functions>
 * 
 * FUNCTION
 *  INT_SwitchStackToRun
 * DESCRIPTION
 *  Switch current stack pointer to new_stack and then run func(...).
 * PARAMETERS
 *  stack_start: [IN] the start address of the new stack (NOT a pointer of start address)
 *  stack_size: [IN] the size of the stack
 *  func: [IN] the pointer of function which want to run
 *  argc: [IN] the number of arguments of func
 *  ...: [IN] the arguments of func
 * RETURNS
 *  The reture value of func 
 ******************************************************************************/
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);

typedef enum {
    L1GDMA_RET_OK = 0,
    L1GDMA_RET_FAIL = -1,
    L1GDMA_RET_CHN_NOT_STOPPED = -2,
    L1GDMA_RET_SET_CONFIG_FAIL = -3,
    L1GDMA_RET_START_FAIL = -4,
} L1GDMA_RET;

/**
 * @brief Use L1_GDMA to do memory copy
 *
 * @param src Source address.
 * @param dst Destination address.
 * @param size Data size in bytes.
 *
 * @retval L1GDMA_RET_OK Memory copy is success.
 * @retval L1GDMA_RET_FAIL Memory copy is failed. Unknow error.
 * @retval L1GDMA_RET_CHN_NOT_STOPPED Channel is in active.
 * @retval L1GDMA_RET_SET_CONFIG_FAIL Failed to set configuration of channel.
 * @retval L1GDMA_RET_START_FAIL Failed to start DMA.
 */
kal_int32 l1gdma_copy(kal_uint8 *src, kal_uint8 *dst, kal_uint32 size);

#endif  /* !__INIT_MEMORY_STACK_H__ */

