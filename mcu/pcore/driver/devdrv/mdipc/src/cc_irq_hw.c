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
 *   cc_irq_hw.c
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
 *****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "cc_irq_hw.h"

/*****************************************************************************
  * Internal Definition                                                       *
  *****************************************************************************/
#define CC_IRQ_HW_IS_OVERFLOW(cc_index_offset)    (*CC_IRQ_EXC_OVERFLOW  & (1 << (cc_index_offset)))
#define CC_IRQ_HW_IS_UNDERFLOW(cc_index_offset)   (*CC_IRQ_EXC_UNDERFLOW & (1 << (cc_index_offset)))
#define CC_IRQ_HW_GET_OFF(cc_index_offset)        (((cc_index_offset) % CC_IRQ_HW_CFG_NUMBER) * CC_IRQ_HW_CFG_BIT_SIZE)

/*****************************************************************************
  * Public API                                                                *
  *****************************************************************************/
__attribute__ ((section ("INTSRAM_ROCODE")))
void cc_irq_hw_trigger_md1_irq(kal_uint32 cc_index_offset)
{
    ASSERT(cc_index_offset < CC_IRQ_HW_TX_NUMBER);
    *CC_IRQ_SET_IRQ = CC_IRQ_HW_WRITE_MAGIC | (1 << cc_index_offset);

    /* check overflow status */
    ASSERT(CC_IRQ_HW_IS_OVERFLOW(cc_index_offset) == 0);

    /* TODO: check when CC_IRQ_HW_EXC_FACTOR works, is the latency too short???  */
}

__attribute__ ((section ("INTSRAM_ROCODE")))
void cc_irq_hw_ack_md1_irq(kal_uint32 cc_index_offset, kal_uint32 prc_cnt)
{
    ASSERT(cc_index_offset < CC_IRQ_HW_RX_NUMBER);
		
    *CC_IRQ_CNT_ACK(cc_index_offset) = CC_IRQ_HW_ACK_MAGIC | prc_cnt;
    
    ASSERT(CC_IRQ_HW_IS_UNDERFLOW(cc_index_offset) == 0);
}

__attribute__ ((section ("INTSRAM_ROCODE")))
kal_uint32 cc_irq_hw_get_md1_trigger_cnt(kal_uint32 cc_index_offset)
{
    ASSERT(cc_index_offset < CC_IRQ_HW_RX_NUMBER);

    return *CC_IRQ_CNT_IRQ(cc_index_offset);
}

/*------------------------------------------------------------------------
 * void         cc_irq_hw_get_md1_wakeup_status
 * Purpose:     Get the CC IRQ wakeup event trigger from MD1  
 *              
 * Parameters:
 *    Input:	None
 *    Output:	None  
 * returns :	the bit mask of CC IRQ wakeup event, one bit per-channel, EX: 0x00000001 means wakeup event from cc_index_offset 0.
 * Note    :    This function only support on JADE(MT6755) and later platform, don't support TK6291.
 *------------------------------------------------------------------------
 */
kal_uint32 cc_irq_hw_get_md1_wakeup_status()
{
#if defined(TK6291)
    return 0xDEADBEEF;/* CC_IRQ_INVALID_VALUE means not support */
#else/* only support on JADE(MT6755) and later platform */
    return *CC_IRQ_WAKEUP_STA;
#endif	
}

#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/ 
/* below for MD3 -------------------------------------------------- */		
/*****************************************************************************
  * Internal Definition                                                       *
  *****************************************************************************/
#define CC_IRQ_MD3_HW_IS_OVERFLOW(cc_index_offset)    (*CC_IRQ_MD3_EXC_OVERFLOW  & (1 << (cc_index_offset)))
#define CC_IRQ_MD3_HW_IS_UNDERFLOW(cc_index_offset)   (*CC_IRQ_MD3_EXC_UNDERFLOW & (1 << (cc_index_offset)))

/*****************************************************************************
  * Public API                                                                *
  *****************************************************************************/
__attribute__ ((section ("INTSRAM_ROCODE")))
void cc_irq_hw_trigger_md3_irq(kal_uint32 cc_index_offset)
{
    ASSERT(cc_index_offset < CC_IRQ_MD3_HW_TX_NUMBER);
    *CC_IRQ_MD3_SET_IRQ = CC_IRQ_MD3_HW_WRITE_MAGIC | (1 << cc_index_offset);

    /* check overflow status */
    ASSERT(CC_IRQ_MD3_HW_IS_OVERFLOW(cc_index_offset) == 0);

    /* TODO: check when CC_IRQ_HW_EXC_FACTOR works, is the latency too short???  */
}

__attribute__ ((section ("INTSRAM_ROCODE")))
void cc_irq_hw_ack_md3_irq(kal_uint32 cc_index_offset, kal_uint32 prc_cnt)
{
    ASSERT(cc_index_offset < CC_IRQ_MD3_HW_RX_NUMBER);

    *CC_IRQ_MD3_CNT_ACK(cc_index_offset) = CC_IRQ_MD3_HW_ACK_MAGIC | prc_cnt;
   
    ASSERT(CC_IRQ_MD3_HW_IS_UNDERFLOW(cc_index_offset) == 0);	
}

__attribute__ ((section ("INTSRAM_ROCODE")))
kal_uint32 cc_irq_hw_get_md3_trigger_cnt(kal_uint32 cc_index_offset)
{
    ASSERT(cc_index_offset < CC_IRQ_MD3_HW_RX_NUMBER);

    return *CC_IRQ_MD3_CNT_IRQ(cc_index_offset);
}		

/*------------------------------------------------------------------------
 * void         cc_irq_hw_get_md3_wakeup_status
 * Purpose:     Get the CC IRQ wakeup event trigger from MD3  
 *              
 * Parameters:
 *    Input:	None
 *    Output:	None  
 * returns :	the bit mask of CC IRQ wakeup event, one bit per-channel, EX: 0x00000001 means wakeup event from cc_index_offset 0.
 * Note    :    This function only support on JADE(MT6755) and later platform, don't support TK6291.
 *------------------------------------------------------------------------
 */
kal_uint32 cc_irq_hw_get_md3_wakeup_status()
{
#if defined(TK6291)
    return 0xDEADBEEF;/* CC_IRQ_INVALID_VALUE means not support */
#else/* only support on JADE(MT6755) and later platform */
    return *CC_IRQ_MD3_WAKEUP_STA;
#endif	
}

/*------------------------------------------------------------------------
 * void         cc_irq_hw_write_ps2md3_dummy
 * Purpose:		record the CC IRQ share memory address dispatched between MD1 and MD3 in PScore to MD3 CC IRQ dummy register 
 *              
 * Parameters:
 *    Input:	
 *              kal_uint32 index: 
 *                                0 ==> The start address of CC IRQ PScore & MD3 share data 
 *                                1 ==> The start address of CC IRQ L1core & MD3 share data
 *                                2 ==> The start address of CC IRQ MD1 & MD3 user share memory
 *                                3 ==> No use 
 *           	kal_uint32 value: the share memory start address
 *    Output:	None
 * returns :	None
 * Note    :    None
 *------------------------------------------------------------------------
 */
void cc_irq_hw_write_ps2md3_dummy(kal_uint32 index, kal_uint32 value)
{
	switch(index)
	{
		case 0:
			*CC_IRQ_PS2MD3_DUMMY_0 = value;
			break;
		case 1:
			*CC_IRQ_PS2MD3_DUMMY_1 = value;
			break;	
		case 2:
			*CC_IRQ_PS2MD3_DUMMY_2 = value;
			break;
		case 3:
			*CC_IRQ_PS2MD3_DUMMY_3 = value;
			break;	
		default:
			ASSERT(0);
			break;			
	}
}

/*------------------------------------------------------------------------
 * void         cc_irq_hw_get_ps2md3_dummy
 * Purpose:		get the CC IRQ share memory address dispatched between MD1 and MD3 from PScore to MD3 CC IRQ dummy register 
 *              
 * Parameters:
 *    Input:	
 *              kal_uint32 index: 
 *                                0 ==> The start address of CC IRQ PScore & MD3 share data 
 *                                1 ==> The start address of CC IRQ L1core & MD3 share data
 *                                2 ==> The start address of CC IRQ MD1 & MD3 user share memory
 *                                3 ==> No use 
 *           	
 *    Output:	kal_uint32 ret_value: the start address
 * returns :	None
 * Note    :    None
 *------------------------------------------------------------------------
 */
kal_uint32 cc_irq_hw_get_ps2md3_dummy(kal_uint32 index)
{
	kal_uint32  ret_value = 0;
		
	switch(index)
	{
		case 0:
			ret_value = *CC_IRQ_PS2MD3_DUMMY_0;
			break;
		case 1:
			ret_value = *CC_IRQ_PS2MD3_DUMMY_1;
			break;	
		case 2:
			ret_value = *CC_IRQ_PS2MD3_DUMMY_2;
			break;
		case 3:
			ret_value = *CC_IRQ_PS2MD3_DUMMY_3;
			break;	
		default:
			ASSERT(0);
			break;			
	}
	
	return ret_value;    
}

/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/

