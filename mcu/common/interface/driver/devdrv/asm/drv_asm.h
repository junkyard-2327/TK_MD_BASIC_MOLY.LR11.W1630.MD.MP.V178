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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * drv_asm.h
 *
 * Project:
 * --------
 *   UMOLY_Software
 *
 * Description:
 * ------------
 *   This file defines ASM drivers interface
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DRV_ASM_H__
#define __DRV_ASM_H__

#include "kal_general_types.h"
typedef enum {
	MALMO_ASM_MCU_PC, 
	MALMO_ASM_CONTEXT_ID, 
	MALMO_ASM_PMC0, 
	MALMO_ASM_PMC1, 
	MALMO_ASM_PMC2,
	MALMO_ASM_CYCLE_CNT, 
	MALMO_ASM_ELM_CNT0, 
	MALMO_ASM_ELM_CNT1, 
	MALMO_ASM_ELM_CNT2, 
	MALMO_ASM_ELM_CNT3,
	MALMO_ASM_EMI_BSCT3, 
	MALMO_ASM_TIMESTAMP, 

	MALMO_ASM_EXTRA0, 
	MALMO_ASM_EXTRA1, 
	MALMO_ASM_EXTRA2,
	MALMO_ASM_EXTRA3,
	MALMO_ASM_EXTRA4, 
	MALMO_ASM_EXTRA5, 
	MALMO_ASM_EXTRA6,
	MALMO_ASM_EXTRA7,	
	MALMO_ASM_EXTRA8, 
	MALMO_ASM_EXTRA9, 
	MALMO_ASM_EXTRA10,
	MALMO_ASM_EXTRA11,
	MALMO_ASM_REG_END		
} MALMO_ASM_MONITORED_REGISTERS;


typedef enum {
	ASM_SWLA_MODE = 0,
	ASM_WRAP_MODE, 
	ASM_HW_SWLA_MODE, 
	ASM_HW_SWTR_MODE, 
	ASM_BUS_MONITOR_MODE, 
}MALMO_ASM_MODE;

#define MALLMO_ASM_MONITOR_FILTER_WIDTH       (12+12) //basic 12 option and extra info(addon) x 12

#define ASM_SLEEP_MODE_SPM                    (0)
#define ASM_SLEEP_MODE_FLUSH                  (1)


//////////////////ASM APIs/////////////////////////////

kal_uint32 MALMO_ASM_InitBusMonitorMode(kal_uint32* buffer_baseaddr,kal_uint32 buffer_len,kal_uint32* range);
kal_uint32 MALMO_ASM_InitHwSwtrMode(kal_uint32* buffer_baseaddr,kal_uint32 buffer_len,kal_uint32 filter_mask,kal_uint32 sampling_rate);
kal_uint32 MALMO_ASM_InitHwSwlaMode(kal_uint32* buffer_baseaddr, kal_uint32 buffer_len, kal_uint32 filter_mask);
kal_uint32 MALMO_ASM_InitWrapMode(kal_uint32* buffer_baseaddr, kal_uint32 buffer_len, kal_uint32 filter_mask);

kal_uint32 MALMO_ASM_StopBusMonitorMode( void );
kal_uint32 MALMO_ASM_StopHwSwtrMode( void );
kal_uint32 MALMO_ASM_StopHwSwlaMode( void );
kal_uint32 MALMO_ASM_StopWrapMode( void );

kal_uint32 MALMO_ASM_Stop(void);
void MALMO_ASM_Start(void);

kal_uint32 MALMO_ASM_SetMonitorFilter( kal_uint32 bitMask );
kal_uint32 MALMO_ASM_FillExtraData( kal_uint32 *buf, kal_uint32 size, kal_uint32 start_index);
kal_uint32* MALMO_ASM_GetMonitorFilterInfo( void );
kal_uint32 MALMO_ASM_GetBufferSize(kal_uint32);
void MALMO_ASM_SendTrigger( void );

kal_uint32 MALMO_ASM_IsEnable(void);
kal_uint32 MALMO_ASM_GetMode(void);
void MALMO_ASM_SetDefaultMode(kal_uint32 mode);
kal_bool MALMO_ASM_BufferIsWrap(void);

//For L1core to set L1core ASM buffer infor
kal_uint32 MALMO_ASM_InitL1Infor(kal_uint32 buffer_base_address, kal_uint32 buffer_size);

//For PScore to set L1core ASM buffer infor
kal_uint32 MALMO_ASM_SetL1Infor(void);

kal_uint32 MALMO_ASM_SleepSave(kal_uint32 sleep_mode);
kal_uint32 MALMO_ASM_SleepRestore(void);

kal_uint32 MALMO_ASM_DcmSave(void);
kal_uint32 MALMO_ASM_DcmRestore(void);


void MALMO_ASM_GetBufferAddrSize(kal_uint32 *base_addr, kal_uint32 *size);
void MALMO_ASM_GetBufferPtr(kal_uint32 *read_ptr, kal_uint32 *write_ptr);
void MALMO_ASM_UpdateReadPtr(kal_uint32 ptr);
void MALMO_ASM_IRQMask(void);
void MALMO_ASM_IRQUnMask(void);
void MALMO_ASM_RegsterLISR(void* reg_lisr);
void MALMO_ASM_WaitTriggerDone(void);

#if defined(__PCORE__)
void MALMO_ASM_GetL1BufferAddrSize(kal_uint32 *base_addr, kal_uint32 *size);
void MALMO_ASM_GetL1BufferPtr(kal_uint32 *read_ptr, kal_uint32 *write_ptr);
void MALMO_ASM_UpdateL1ReadPtr(kal_uint32 ptr);
void MALMO_ASM_L1IRQMask(void);
void MALMO_ASM_L1IRQUnMask(void);
void MALMO_ASM_RegsterL1LISR(void* reg_lisr);
kal_bool MALMO_ASM_L1BufferIsWrap(void);
kal_uint32 MALMO_ASM_PSCheckL1BufferInit(void);


#endif  //defined(__PCORE__)

#endif  //__DRV_ASM_H__

