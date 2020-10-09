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
 * drv_asm.c
 *
 * Project:
 * --------
 *   UMOLY_Software
 *
 * Description:
 * ------------
 *   This file implements ASM drivers
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

#include "asm_reg.h"
#include "drv_asm.h"
#include "intrCtrl.h"

#define __intsram_zi__     __attribute__((zero_init, section("INTSRAM_ZI")))

__intsram_zi__ ASM_STRUCT Asm_Infor;
__intsram_zi__ ASM_BUF_INFO_STRUCT L1core_Asm_Buf_Info;


#if defined(__PCORE__)
DEFINE_NC_ALIGNED_SHARED_ARRAY_ASSIGN(kal_uint32, L1core_Asm_Buf_Info_Share,8,64,0,0,0,0,0,0,0,0)
#else
DEFINE_NC_ALIGNED_SHARED_ARRAY(kal_uint32, L1core_Asm_Buf_Info_Share,8,64)
#endif  //defined(__PCORE__)

#if defined(__KAL_CROSS_CORE_SUPPORT__)     

#define GET_L1CORE_ASM_BUF_INFO(index)      SHARED_ARRAY(L1core_Asm_Buf_Info_Share)[index]
#define SET_L1CORE_ASM_BUF_INFO(index,val)  SHARED_ARRAY(L1core_Asm_Buf_Info_Share)[index] = val

#else
#define GET_L1CORE_ASM_BUF_INFO(index)      
#define SET_L1CORE_ASM_BUF_INFO(index,val)  

#endif  //__KAL_CROSS_CORE_SUPPORT__

#define ASM_BUF_END (0x444E4542)

//DHL max buffer is 64K: 64K/4 = 16K(word, 4bytes)
#define ASM_TH_MAX 16000   
kal_uint32 MALMO_ASM_MonitorFilter[MALLMO_ASM_MONITOR_FILTER_WIDTH];

#define ASM_DSB()                                   \
do{                                                                            \
    __asm__ __volatile__                                                       \
    (                                                                          \
       "DSB"                                        \
       :                                                          \
       :                                                                       \
    );                                                                         \
}while(0)

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////ASM Function ///////////////////////////////////////////

void ASMWaitIdle(void)
{
	kal_uint32 idle_state;
	kal_uint32 wait_cnt = 0;
	do
	{
	    ASM_GET_IDLE(idle_state);
	    wait_cnt++;
	}while((idle_state&(1 << ASM_IDLE_BIT)) == 0 && wait_cnt < 100);

#if defined(__MTK_INTERNAL__)
	if(wait_cnt == 100)
	    ASSERT(0);
#endif  //__MTK_INTERNAL__
}

void ASMEnable(void)
{
	Asm_Infor.gen_enable |= 0x01;
	*((volatile kal_uint32*) (ASM_GEN_CONFIG)) = Asm_Infor.gen_enable;
}

void ASMDisable(void)
{
	kal_uint32 busy_stat = 0;
	kal_uint32 wait_cnt = 0;
  
  if((Asm_Infor.asm_mode == ASM_WRAP_MODE)||(Asm_Infor.asm_mode == ASM_HW_SWLA_MODE))
  {
	    do
	    {
	       ASM_GET_ASM_BUSY_STATE(busy_stat);
	       wait_cnt++;
	    }while(busy_stat && wait_cnt < 100);
  }	
#if defined(__MTK_INTERNAL__)
	if(wait_cnt == 100)
	    ASSERT(0);
#endif  //__MTK_INTERNAL__

	Asm_Infor.gen_enable &= (~(1 << ASM_ENABLE_BIT));
	ASM_DISABLE(Asm_Infor.gen_enable);

//Wait ASM Ping Pong buffer flush and transation done
	ASMWaitIdle();
}

void ASMSetIntEnable(void)
{
	Asm_Infor.int_en = 1;
	ASM_INT_ENABLE(Asm_Infor.int_en);

}

void ASMSetIntDisable(void)
{
	Asm_Infor.int_en = 0;
	ASM_INT_ENABLE(Asm_Infor.int_en);

}


void ASMSetEnablePDI(void)
{
	if(Asm_Infor.asm_mode == ASM_WRAP_MODE)
	{
	    Asm_Infor.gen_enable |= (1 << ASM_WRAP_MODE_PDI_BIT);
	    Asm_Infor.gen_enable &= (~(1 << ASM_PDI_BIT));
	}
	else
	{
	    Asm_Infor.gen_enable |= (1 << ASM_PDI_BIT);
	    Asm_Infor.gen_enable &= (~(1 << ASM_WRAP_MODE_PDI_BIT));
	}
	ASM_SET_PDI_HEADER(ASM_PDI_HEADER);
}


void ASMSetDisablePDI(void)
{
	if(Asm_Infor.asm_mode == ASM_WRAP_MODE)
	{
	    Asm_Infor.gen_enable &= (~(1 << ASM_WRAP_MODE_PDI_BIT));
	}
	else
	{
	    Asm_Infor.gen_enable &= (~(1 << ASM_PDI_BIT));
	}
}


void ASMSetBufferEndMark(void)
{
    *(volatile kal_uint32*)(Asm_Infor.buf_base_address+Asm_Infor.buf_size*1024-4) = ASM_BUF_END;
}

kal_bool ASMCheckBufferEndMark(void)
{
    if(*(volatile kal_uint32*)(Asm_Infor.buf_base_address+Asm_Infor.buf_size*1024-4) != ASM_BUF_END)
    {
    	//Buffer warp
    	return KAL_TRUE;
    }
    else
    {
    	//Buffer not warp
    	return KAL_FALSE;
    }
}

void AsmInitBusMonitorRange(kal_uint32* range)
{
	Asm_Infor.bus_mon_range_0_start = range[0];
	Asm_Infor.bus_mon_range_0_end = range[1];	
	Asm_Infor.bus_mon_range_1_start = range[2];
	Asm_Infor.bus_mon_range_1_end = range[3];	
	Asm_Infor.bus_mon_range_2_start = range[4];
	Asm_Infor.bus_mon_range_2_end = range[5];	
	Asm_Infor.bus_mon_range_3_start = range[6];
	Asm_Infor.bus_mon_range_3_end = range[7];
}

void ASMSetBusMonitorRange(void)
{
	ASM_SET_BUS_MONITOR_RAGE_0_START(Asm_Infor.bus_mon_range_0_start);
	ASM_SET_BUS_MONITOR_RAGE_0_END(Asm_Infor.bus_mon_range_0_end);
	ASM_SET_BUS_MONITOR_RAGE_1_START(Asm_Infor.bus_mon_range_1_start);
	ASM_SET_BUS_MONITOR_RAGE_1_END(Asm_Infor.bus_mon_range_1_end);
	ASM_SET_BUS_MONITOR_RAGE_2_START(Asm_Infor.bus_mon_range_2_start);
	ASM_SET_BUS_MONITOR_RAGE_2_END(Asm_Infor.bus_mon_range_2_end);
	ASM_SET_BUS_MONITOR_RAGE_3_START(Asm_Infor.bus_mon_range_3_start);
	ASM_SET_BUS_MONITOR_RAGE_3_END(Asm_Infor.bus_mon_range_3_end);
}

void ASMSetModeConfig(kal_uint32 mode, kal_uint32 *buffer,kal_uint32 buffer_length,kal_uint32 filter_mask,kal_uint32 sampling_rate)
{
	//Reset
	ASMDisable();
	ASM_RESET;

	//Set logging buffer
    Asm_Infor.buf_base_address = (kal_uint32)buffer; 
	ASM_SET_LOG_BUF_BASEADDR(Asm_Infor.buf_base_address);
	
    Asm_Infor.thresh_value = buffer_length / ASM_BUF_ALT_TH_VAL; 
    if(ASM_TH_MAX < Asm_Infor.thresh_value)
    {
        Asm_Infor.thresh_value = ASM_TH_MAX;
    }
        
    ASM_SET_BUFFER_ALT_THRESHOLD(Asm_Infor.thresh_value);
    
    Asm_Infor.buf_size = buffer_length>>8; 
	ASM_SET_LOG_BUF_SIZE(Asm_Infor.buf_size);  //in KB

#if defined(__L1CORE__)

    MALMO_ASM_InitL1Infor(Asm_Infor.buf_base_address,(Asm_Infor.buf_size << 10));

#endif // if defined(__L1CORE__)

	Asm_Infor.asm_mode = mode;
	
	//Set mode
	if( Asm_Infor.asm_mode == ASM_BUS_MONITOR_MODE )
	{
#ifdef TK6291
		ASM_SET_BUS_MONITOR_HEADER(ASM_BUS_MONITOR_HEADER);
#endif  //ifdef TK6291		
		Asm_Infor.mode_config = ASM_BUSMONITOR_MODE_CONFIG;
		ASMSetBusMonitorRange();
    ASMSetIntEnable();
	}
	else if( Asm_Infor.asm_mode == ASM_HW_SWLA_MODE )
	{
#ifdef TK6291
		ASM_SET_HW_SWLA_AND_HW_SWTR_HEADER(ASM_HW_SWLA_HEADER);
#endif  //ifdef TK6291		
		Asm_Infor.mode_config = ASM_HW_SWLA_MODE_CONFIG;
		MALMO_ASM_SetMonitorFilter(filter_mask);
		Asm_Infor.trigger_cnt = 0;
    ASMSetIntEnable();
	}
	else if( Asm_Infor.asm_mode == ASM_HW_SWTR_MODE )
	{
#ifdef TK6291
		ASM_SET_HW_SWLA_AND_HW_SWTR_HEADER(ASM_HW_SWTR_HEADER);
#endif  //ifdef TK6291		
		Asm_Infor.mode_config = ASM_HW_SWTR_MODE_CONFIG;
		MALMO_ASM_SetMonitorFilter(filter_mask);
		Asm_Infor.sample_rate = sampling_rate;
		ASM_SET_HW_SWTR_SAMPLING_RATE(Asm_Infor.sample_rate);
    ASMSetIntEnable();
	}
#ifndef TK6291
	else if( Asm_Infor.asm_mode == ASM_WRAP_MODE )
	{
		Asm_Infor.mode_config = ASM_WRAP_MODE_CONFIG;
		MALMO_ASM_SetMonitorFilter(filter_mask);
		ASMSetBufferEndMark();
    ASMSetIntDisable();
	}
#endif  //ifndef TK6291	
	else
	{
#if defined(__MTK_INTERNAL__)
		ASSERT(0);
#endif  //__MTK_INTERNAL__
	}

    ASM_SET_MODE(Asm_Infor.mode_config);
    ASMSetEnablePDI();
//	ASMEnable();	
}

void ASMGetBufReadWritePtr(void)
{
	ASM_GET_WR_PTR(Asm_Infor.buf_write_ptr);
	ASM_GET_RD_PTR(Asm_Infor.buf_read_ptr);
	
}

void ASMSetBuffer(void)
{
	ASM_SET_LOG_BUF_BASEADDR(Asm_Infor.buf_base_address);
	ASM_SET_LOG_BUF_SIZE(Asm_Infor.buf_size);
	ASM_SET_WR_BUF_PTR(Asm_Infor.buf_write_ptr);
	ASM_SET_RD_PTR(Asm_Infor.buf_read_ptr);
  ASM_SET_BUFFER_ALT_THRESHOLD(Asm_Infor.thresh_value);
}

void ASMGetSramPtr(void)
{
	ASM_SRAM_GET_RD_PTR(Asm_Infor.sram_read_ptr);
	ASM_SRAM_GET_WR_PTR(Asm_Infor.sram_write_ptr);
	ASM_SRAM_GET_TARGET_GETOUT(Asm_Infor.sram_target_getout_ptr);
	ASM_SRAM_GET_ASM_SAVED_TAR_SRAM_PTR(Asm_Infor.sram_saved_target_ptr);
	ASM_SRAM_GET_ASM_CURR_SRAM_PTR(Asm_Infor.sram_curr_ptr);
}

void ASMSetSramPtr(void)
{
	ASM_SRAM_SET_RD_PTR(Asm_Infor.sram_read_ptr);
	ASM_SRAM_SET_WR_PTR(Asm_Infor.sram_write_ptr);
	ASM_SRAM_SET_TARGET_GETOUT(Asm_Infor.sram_target_getout_ptr);
	ASM_SRAM_SET_ASM_SAVED_TAR_SRAM_PTR(Asm_Infor.sram_saved_target_ptr);
	ASM_SRAM_SET_ASM_CURR_SRAM_PTR(Asm_Infor.sram_curr_ptr);
}


void ASMSaveConfigForSPM(void)
{
	ASMGetBufReadWritePtr();
	ASMGetSramPtr();
}

void ASMSetProfilingMode(void)
{
    kal_uint32 index;
    kal_uint32 addon_index;
    
    ASM_SET_PROFILE_FILTER(Asm_Infor.profile_en);
    
    addon_index = (Asm_Infor.profile_en&0x00FFF000) >> 12;
    if(addon_index)
    {
    	for(index = 0; addon_index != 0; index++)
    	{
    		if(addon_index&(1 << index))
    		{
#ifdef TK6291
    			if(index < (MALMO_ASM_EXTRA9-MALMO_ASM_EXTRA0))
    				*(volatile kal_uint32*) (ASM_PROFILE_ADDON_INFO0+index*4) = Asm_Infor.addon[index];
    			else
    				*(volatile kal_uint32*) (ASM_PROFILE_ADDON_INFO0+index*4+4) = Asm_Infor.addon[index];

#else
    				*(volatile kal_uint32*) (ASM_PROFILE_ADDON_INFO0+index*4) = Asm_Infor.addon[index];

#endif  //TK6291    			
    			addon_index &= ~((1 << index));
    		}
    	}
    }
}

void ASMStopNonTriggerMode(void)
{
    //Set to HW_SWLA mode to disable HW_SWTR Mode
    //Because if disable ASM will only finish last transaction then enable idle state.
    //Switch to another mode to wait SRAM empty
    //ASM_SET_MODE_TO_HW_SWLA_MODE; 
    
 	//Wait ASM SRAM empty
    ASMDisable();
    ASMWaitIdle();
}

void ASMStopTriggerMode(void)
{
 	//Wait ASM SRAM empty
    ASMDisable();
 	ASMWaitIdle();
}


void ASMRestoreModeConfig(void)
{
	if( Asm_Infor.asm_mode == ASM_BUS_MONITOR_MODE )
	{
#ifdef TK6291
		ASM_SET_BUS_MONITOR_HEADER(ASM_BUS_MONITOR_HEADER);
#endif  //ifdef TK6291	
		ASMSetBusMonitorRange();
	}
	else if( Asm_Infor.asm_mode == ASM_HW_SWLA_MODE )
	{
#ifdef TK6291
		ASM_SET_HW_SWLA_AND_HW_SWTR_HEADER(ASM_HW_SWLA_HEADER);
#endif  //ifdef TK6291	
        ASMSetProfilingMode();
	}
	else if( Asm_Infor.asm_mode == ASM_HW_SWTR_MODE )
	{
#ifdef TK6291
		ASM_SET_HW_SWLA_AND_HW_SWTR_HEADER(ASM_HW_SWTR_HEADER);
#endif  //ifdef TK6291	
		ASM_SET_HW_SWTR_SAMPLING_RATE(Asm_Infor.sample_rate);
        ASMSetProfilingMode();
	}
#ifndef TK6291
	else if( Asm_Infor.asm_mode == ASM_WRAP_MODE )
	{
        ASMSetProfilingMode();
	}
#endif  //ifdef TK6291	
	else
	{
#if defined(__MTK_INTERNAL__)
		ASSERT(0);
#endif  //__MTK_INTERNAL__
	}
	
	ASM_SET_MODE(Asm_Infor.mode_config);
	ASM_INT_ENABLE(Asm_Infor.int_en);

}


void ASMWaitSMPGrant(void)
{
	kal_uint32 grant = 0;
	kal_uint32 wait_cnt = 0;
	do
	{
	    ASM_GET_SPM_GRANT(grant);
	    wait_cnt++;
	}while((grant&(1 << ASM_SPM_GRANT_BIT)) == 0 &&(wait_cnt < 10));
	
#if defined(__MTK_INTERNAL__)
	if(wait_cnt == 10)
	     ASSERT(0);
#endif  //__MTK_INTERNAL__

//	ASM_WAIT_FOR_SPM_GRANT;
}

void ASMEnableELM(void)
{
	Asm_Infor.gen_enable |= (0x01 << ASM_ELM_BIT);
}



/////////////////////////////////////End///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

kal_uint32 MALMO_ASM_GetBufferSize(kal_uint32 buffer_len)
{
	kal_uint32 i;
	buffer_len = buffer_len >> 8;

#if defined(__MTK_INTERNAL__)
	if( buffer_len == 0 )
		ASSERT(0); //should not happen
#endif  //__MTK_INTERNAL__
		
	for( i = 0 ; i < ASM_MAX_BUF_BIT_LEN; ++i )
	{
		if(buffer_len == 0)
		{
			break;
		}
		buffer_len = (buffer_len >> 1);
	}
	
	buffer_len = (1 << (i-1+8));	

    return buffer_len;

}

void MALMO_ASM_ConfigBuffer(int base_addr, unsigned int buffer_size)
{
			Asm_Infor.buf_base_address = base_addr; 
			ASM_SET_LOG_BUF_BASEADDR(Asm_Infor.buf_base_address); // 64byte aligned
			
			Asm_Infor.buf_size = buffer_size; 
			ASM_SET_LOG_BUF_SIZE(Asm_Infor.buf_size); // unit: KB			
}


kal_uint32 MALMO_ASM_SetMonitorFilter( kal_uint32 bit_mask )
{
	Asm_Infor.profile_en = bit_mask;
	ASM_SET_PROFILE_FILTER(Asm_Infor.profile_en);

	if(Asm_Infor.profile_en&ASM_ELM_MSK)
	{
		ASMEnableELM();
	}

	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

kal_uint32 MALMO_ASM_InitBusMonitorMode(kal_uint32* buffer_baseaddr,kal_uint32 buffer_len,kal_uint32* range)
{
    buffer_len = MALMO_ASM_GetBufferSize(buffer_len);
	AsmInitBusMonitorRange(range);
	ASMSetModeConfig( ASM_BUS_MONITOR_MODE, buffer_baseaddr, buffer_len, ASM_HW_SWTR_FILTER_DUMMY, ASM_HW_SWTR_SAMPLING_RATE_DUMMY );
	
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

kal_uint32 MALMO_ASM_InitHwSwlaMode( kal_uint32* buffer_baseaddr, kal_uint32 buffer_len, kal_uint32 filter_mask )
{
    buffer_len = MALMO_ASM_GetBufferSize(buffer_len);
//    filter_mask |= (( 1<< MALMO_ASM_CONTEXT_ID)|(1 << MALMO_ASM_TIMESTAMP));
    filter_mask |= ( 1<< MALMO_ASM_CONTEXT_ID);
	ASMSetModeConfig( ASM_HW_SWLA_MODE, buffer_baseaddr, buffer_len, filter_mask, ASM_HW_SWTR_SAMPLING_RATE_DUMMY );

	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

kal_uint32 MALMO_ASM_InitHwSwtrMode(kal_uint32* buffer_baseaddr,kal_uint32 buffer_len,kal_uint32 filter_mask,kal_uint32 sampling_rate)
{
    buffer_len = MALMO_ASM_GetBufferSize(buffer_len);
	ASMSetModeConfig( ASM_HW_SWTR_MODE, buffer_baseaddr, buffer_len, filter_mask, sampling_rate);	

	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

kal_uint32 MALMO_ASM_InitWrapMode( kal_uint32* buffer_baseaddr, kal_uint32 buffer_len, kal_uint32 filter_mask )
{
    buffer_len = MALMO_ASM_GetBufferSize(buffer_len);
	ASMSetModeConfig( ASM_WRAP_MODE, buffer_baseaddr, buffer_len, filter_mask, ASM_HW_SWTR_SAMPLING_RATE_DUMMY );

	return MALMO_ASM_ERR_CODE_NO_ERROR;
}


kal_uint32 MALMO_ASM_FillExtraData( kal_uint32 *buf, kal_uint32 size, kal_uint32 start_index)
{
	kal_uint32 i;
	volatile kal_uint32 *extra_addon_info_base_addr = (kal_uint32 *)ASM_PROFILE_ADDON_INFO0;

	if(start_index < MALMO_ASM_REG_END && start_index >= MALMO_ASM_EXTRA0)
	{
		start_index -= MALMO_ASM_EXTRA0;
		if( (start_index + size) > MALMO_ASM_EXTRA_INFO_NUM)
			return MALMO_ASM_ERR_CODE_ERROR;
	}
	else
	{
		return MALMO_ASM_ERR_CODE_ERROR;
	}

    //use addon0~1 to log FRC and Timestamp when ASM_HW_SWLA_MODE


	for( i = 0 ; i < size ; ++i )
	{
#ifdef TK6291
		if(i < 9)
		{
		  Asm_Infor.addon[start_index+i] = buf[i];
		  *(extra_addon_info_base_addr+start_index+i) = Asm_Infor.addon[start_index+i];
		}
		else
		{
		  Asm_Infor.addon[start_index+i]= buf[i];
		  *(extra_addon_info_base_addr+start_index+i+1) = Asm_Infor.addon[start_index+i];
		}
#else
		Asm_Infor.addon[start_index+i]= buf[i];
		*(extra_addon_info_base_addr+start_index+i) = Asm_Infor.addon[start_index+i];

#endif  //TK6291

        
	}
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

void MALMO_ASM_WaitTriggerDone(void)
{
	kal_uint32 busy_stat;
	kal_uint32 wait_cnt = 0;
	
    if((Asm_Infor.gen_enable&0x01) && (Asm_Infor.asm_mode == ASM_WRAP_MODE))
    {
        do
        {
        	ASM_GET_ASM_BUSY_STATE(busy_stat);
        	wait_cnt++;
        }while( busy_stat && wait_cnt < 20);
        	
#if defined(__MTK_INTERNAL__)
        if(wait_cnt > 10)
    	    EXT_ASSERT(0,5,wait_cnt,Asm_Infor.asm_mode);
#endif  //#if defined(__MTK_INTERNAL__)

    }
    
}

void MALMO_ASM_SendTrigger( void )
{

    if(Asm_Infor.gen_enable&0x01)
    {
        Asm_Infor.trigger_cnt++;
        ASM_SET_HW_SWLA_TRIG;
    }
}


kal_uint32* MALMO_ASM_GetMonitorFilterInfo( void )
{

	MALMO_ASM_MonitorFilter[0] = MALMO_ASM_MCU_PC;
	MALMO_ASM_MonitorFilter[1] = MALMO_ASM_CONTEXT_ID;
	MALMO_ASM_MonitorFilter[2] = MALMO_ASM_PMC0;
	MALMO_ASM_MonitorFilter[3] = MALMO_ASM_PMC1;
	MALMO_ASM_MonitorFilter[4] = MALMO_ASM_PMC2;
	MALMO_ASM_MonitorFilter[5] = MALMO_ASM_CYCLE_CNT;
	MALMO_ASM_MonitorFilter[6] = MALMO_ASM_ELM_CNT0;
	MALMO_ASM_MonitorFilter[7] = MALMO_ASM_ELM_CNT1;
	MALMO_ASM_MonitorFilter[8] = MALMO_ASM_ELM_CNT2;
	MALMO_ASM_MonitorFilter[9] = MALMO_ASM_ELM_CNT3;
	MALMO_ASM_MonitorFilter[10] = MALMO_ASM_EMI_BSCT3;
	MALMO_ASM_MonitorFilter[11] = MALMO_ASM_TIMESTAMP;
	MALMO_ASM_MonitorFilter[12] = MALMO_ASM_EXTRA0;
	MALMO_ASM_MonitorFilter[13] = MALMO_ASM_EXTRA1;
	MALMO_ASM_MonitorFilter[14] = MALMO_ASM_EXTRA2; 
	MALMO_ASM_MonitorFilter[15] = MALMO_ASM_EXTRA3;
	MALMO_ASM_MonitorFilter[16] = MALMO_ASM_EXTRA4;
	MALMO_ASM_MonitorFilter[17] = MALMO_ASM_EXTRA5;
	MALMO_ASM_MonitorFilter[18] = MALMO_ASM_EXTRA6; 
	MALMO_ASM_MonitorFilter[19] = MALMO_ASM_EXTRA7;
	MALMO_ASM_MonitorFilter[20] = MALMO_ASM_EXTRA8;
	MALMO_ASM_MonitorFilter[21] = MALMO_ASM_EXTRA9;
	MALMO_ASM_MonitorFilter[22] = MALMO_ASM_EXTRA10; 
	MALMO_ASM_MonitorFilter[23] = MALMO_ASM_EXTRA11;

	return MALMO_ASM_MonitorFilter;
}

kal_uint32 MALMO_ASM_StopHwSwTrMode( void )
{
 	ASMStopNonTriggerMode();
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}


kal_uint32 MALMO_ASM_StopBusMonitorMode( void )
{
 	ASMStopNonTriggerMode();
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}



kal_uint32 MALMO_ASM_StopHwSwlaMode( void )
{
 	ASMStopTriggerMode();
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}


kal_uint32 MALMO_ASM_StopWrapMode( void )
{
 	ASMStopTriggerMode();
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

kal_uint32 MALMO_ASM_IsEnable(void)
{
	return (Asm_Infor.gen_enable&0x01);
}


kal_uint32 MALMO_ASM_GetMode(void)
{
	return Asm_Infor.asm_mode;
}


void MALMO_ASM_SetDefaultMode(kal_uint32 mode)
{
	Asm_Infor.asm_mode = mode;
}

void MALMO_ASM_Start(void)
{
	  Asm_Infor.spm_set = 0;
    ASMEnable();
#if defined(__L1CORE__)
        SET_L1CORE_ASM_BUF_INFO(ASM_BUF_WR_PTR,0);
        SET_L1CORE_ASM_BUF_INFO(ASM_BUF_RD_PTR,0);
        SET_L1CORE_ASM_BUF_INFO(ASM_STATE,ASM_STATE_START);
        ASM_DSB();
#endif  //__L1CORE__	      
    
}


kal_uint32 MALMO_ASM_Stop(void)
{
    if(Asm_Infor.gen_enable&0x01)
    {
        if(Asm_Infor.asm_mode > ASM_HW_SWLA_MODE)
        {
    	    ASMStopNonTriggerMode();
        }
        else
        {
    	    ASMStopTriggerMode();
        }
    
	      ASM_GET_WR_PTR(Asm_Infor.buf_write_ptr);
	      ASM_GET_RD_PTR(Asm_Infor.buf_read_ptr);
 
#if defined(__L1CORE__)
        SET_L1CORE_ASM_BUF_INFO(ASM_BUF_WR_PTR,Asm_Infor.buf_write_ptr);
        SET_L1CORE_ASM_BUF_INFO(ASM_BUF_RD_PTR,Asm_Infor.buf_read_ptr);
        SET_L1CORE_ASM_BUF_INFO(ASM_STATE,ASM_STATE_STOP);
        ASM_DSB();
#endif  //__L1CORE__	      
    }
	  return MALMO_ASM_ERR_CODE_NO_ERROR;
}


kal_uint32 MALMO_ASM_InitL1Infor(kal_uint32 buffer_base_address, kal_uint32 buffer_size)
{
	buffer_size >>= 10;

	if(buffer_base_address != 0 && buffer_size != 0)
    {
        SET_L1CORE_ASM_BUF_INFO(ASM_BUF_BASE,buffer_base_address);
        SET_L1CORE_ASM_BUF_INFO(ASM_BUF_SIZE,buffer_size);
        SET_L1CORE_ASM_BUF_INFO(ASM_BUF_RD_REG,ASM_RD_PTR);
        SET_L1CORE_ASM_BUF_INFO(ASM_BUF_WR_REG,ASM_WR_PTR);
        SET_L1CORE_ASM_BUF_INFO(ASM_STATE,ASM_STATE_STOP);
        SET_L1CORE_ASM_BUF_INFO(ASM_BUF_INFOR_READY,1);
        ASM_DSB();

        
 	    return MALMO_ASM_ERR_CODE_NO_ERROR;
   }
   else
   {
	    return MALMO_ASM_ERR_CODE_ERROR;
   }
}





kal_uint32 MALMO_ASM_DcmSave(void)
{
	  kal_uint32 offset;
	  Asm_Infor.dcm_set++;
	
	  if(Asm_Infor.gen_enable&0x01)
	  {
#if defined(__L1CORE__)
      SET_L1CORE_ASM_BUF_INFO(ASM_STATE,ASM_STATE_DCM);
      ASM_INT_ENABLE(0);
#endif  //__L1CORE__	      

    	Asm_Infor.asm_is_enabled = 1;
   		ASMDisable();
 
   		ASM_GET_WR_PTR(Asm_Infor.buf_write_ptr);
      ASM_SRAM_GET_RD_PTR(Asm_Infor.sram_read_ptr);
      ASM_SRAM_GET_ASM_SAVED_TAR_SRAM_PTR(Asm_Infor.sram_saved_target_ptr);
      ASM_SRAM_GET_ASM_CURR_SRAM_PTR(Asm_Infor.sram_curr_ptr);
  		 		
  		//For ASM start address issue, align 16 words
  		offset = Asm_Infor.buf_write_ptr%16;
  		Asm_Infor.buf_write_ptr -= offset;
  		Asm_Infor.sram_read_ptr -= offset;
	    Asm_Infor.sram_saved_target_ptr-= offset;
	    Asm_Infor.sram_curr_ptr-= offset;
   		ASM_SET_SPM_REQ();
  		ASMWaitSMPGrant();
    }
    else
    {
    	Asm_Infor.asm_is_enabled = 0;
    }
	
	return MALMO_ASM_ERR_CODE_NO_ERROR;

}

kal_uint32 MALMO_ASM_SleepSave(kal_uint32 sleep_mode)
{
	  kal_uint32 offset;
	  Asm_Infor.spm_set++;
	
	  if(Asm_Infor.gen_enable&0x01)
	  {
#if defined(__L1CORE__)
      SET_L1CORE_ASM_BUF_INFO(ASM_STATE,ASM_STATE_DORMANT);
      ASM_INT_ENABLE(0);
#endif  //__L1CORE__	      

    	Asm_Infor.asm_is_enabled = 1;
   		ASMDisable();
  		ASMSaveConfigForSPM();
  		
  		//For ASM start address issue, align 16 words
  		offset = Asm_Infor.buf_write_ptr%16;
  		Asm_Infor.buf_write_ptr -= offset;
  		Asm_Infor.sram_read_ptr -= offset;
//	    Asm_Infor.sram_target_getout_ptr-= offset;
	    Asm_Infor.sram_saved_target_ptr-= offset;
	    Asm_Infor.sram_curr_ptr-= offset;
   		ASM_SET_SPM_REQ();
  		ASMWaitSMPGrant();
    }
    else
    {
    	Asm_Infor.asm_is_enabled = 0;
    }
	
	return MALMO_ASM_ERR_CODE_NO_ERROR;

}

kal_uint32 MALMO_ASM_DcmRestore(void)
{
	if(Asm_Infor.asm_is_enabled)
	{
      ASM_SRAM_SET_RD_PTR(Asm_Infor.sram_read_ptr);
      ASM_SRAM_SET_ASM_SAVED_TAR_SRAM_PTR(Asm_Infor.sram_saved_target_ptr);
      ASM_SRAM_SET_ASM_CURR_SRAM_PTR(Asm_Infor.sram_curr_ptr);     

	    ASM_SET_WR_BUF_PTR(Asm_Infor.buf_write_ptr);
        
	    ASM_INT_ENABLE(Asm_Infor.int_en);
	    
     	ASMEnable();
     	Asm_Infor.asm_is_enabled = 0;

#if defined(__L1CORE__)
      SET_L1CORE_ASM_BUF_INFO(ASM_STATE,ASM_STATE_START);
      ASM_DSB();
#endif  //__L1CORE__	      
  }
	
	return MALMO_ASM_ERR_CODE_NO_ERROR;

}

kal_uint32 MALMO_ASM_SleepRestore(void)
{
	if(Asm_Infor.asm_is_enabled)
	{
   		ASMSetSramPtr();
    	ASMSetBuffer();
    	ASMRestoreModeConfig();
     	ASMEnable();
     	Asm_Infor.asm_is_enabled = 0;

#if defined(__L1CORE__)
      SET_L1CORE_ASM_BUF_INFO(ASM_STATE,ASM_STATE_START);
      ASM_DSB();
#endif  //__L1CORE__	      

  }
	
	return MALMO_ASM_ERR_CODE_NO_ERROR;

}


void MALMO_ASM_GetBufferPtr(kal_uint32 *read_ptr, kal_uint32 *write_ptr)
{
	
	if(Asm_Infor.gen_enable&0x01)
	{
	    ASM_GET_WR_PTR(Asm_Infor.buf_write_ptr);
	    ASM_GET_RD_PTR(Asm_Infor.buf_read_ptr);
  }
  
  *write_ptr = (Asm_Infor.buf_write_ptr<<2);  
	*read_ptr = (Asm_Infor.buf_read_ptr<<2) ; 


}

void MALMO_ASM_GetBufferAddrSize(kal_uint32 *base_addr, kal_uint32 *size)
{
    *base_addr = Asm_Infor.buf_base_address;
    *size = Asm_Infor.buf_size*1024;
}


kal_bool MALMO_ASM_BufferIsWrap(void)
{
    return ASMCheckBufferEndMark();
}

void MALMO_ASM_UpdateReadPtr(kal_uint32 ptr)
{
    Asm_Infor.buf_read_ptr = (ptr>>2); 
    ASM_SET_RD_PTR(Asm_Infor.buf_read_ptr); //In word
}

void MALMO_ASM_IRQMask(void)
{
    IRQMask(ASM_IRQID);
}

void MALMO_ASM_IRQUnMask(void)
{
    IRQUnmask(ASM_IRQID);
}


void MALMO_ASM_RegsterLISR(void* reg_lisr)
{
    IRQ_Register_LISR(ASM_IRQID, reg_lisr, "malmo lisr");
    IRQSensitivity(ASM_IRQID, KAL_FALSE);
    IRQUnmask(ASM_IRQID);  
}

#if defined(__PCORE__)



kal_uint32 MALMO_ASM_SetL1Infor(void)
{
#if defined(__KAL_CROSS_CORE_SUPPORT__)  

	if(GET_L1CORE_ASM_BUF_INFO(ASM_BUF_INFOR_READY))
	{
	    L1core_Asm_Buf_Info.buf_base_address = GET_L1CORE_ASM_BUF_INFO(ASM_BUF_BASE);
	    L1core_Asm_Buf_Info.buf_size = GET_L1CORE_ASM_BUF_INFO(ASM_BUF_SIZE);
	    L1core_Asm_Buf_Info.buf_read_ptr_reg = GET_L1CORE_ASM_BUF_INFO(ASM_BUF_RD_REG);
	    L1core_Asm_Buf_Info.buf_write_ptr_reg = GET_L1CORE_ASM_BUF_INFO(ASM_BUF_WR_REG);
	    L1core_Asm_Buf_Info.init_ready_fg = 1;
	    
	    return MALMO_ASM_ERR_CODE_NO_ERROR;
	}
	else
	{
	    return MALMO_ASM_ERR_CODE_ERROR;
	}
#else

	return MALMO_ASM_ERR_CODE_NO_ERROR;

#endif  //	defined(__KAL_CROSS_CORE_SUPPORT__)  
}

kal_uint32 MALMO_ASM_PSCheckL1BufferInit(void)
{
    if( L1core_Asm_Buf_Info.init_ready_fg == 0)
    {
         if(MALMO_ASM_ERR_CODE_NO_ERROR == MALMO_ASM_SetL1Infor())   
         {
              return MALMO_ASM_ERR_CODE_NO_ERROR;
         }
         else
         {
              return MALMO_ASM_ERR_CODE_ERROR;
         }
    }
    
    return MALMO_ASM_ERR_CODE_NO_ERROR;
    
}


void MALMO_ASM_GetL1BufferPtr(kal_uint32 *read_ptr, kal_uint32 *write_ptr)
{
#if defined(__KAL_CROSS_CORE_SUPPORT__) 

    kal_uint32 rd_ptr;
    if(L1core_Asm_Buf_Info.init_ready_fg == 0)
    {
         if(MALMO_ASM_ERR_CODE_NO_ERROR != MALMO_ASM_SetL1Infor())   
         {
#if defined(__MTK_INTERNAL__)
             ASSERT(0);
#endif  //_MTK_INTERNAL__
         }
    }
    
    if(GET_L1CORE_ASM_BUF_INFO(ASM_STATE) == ASM_STATE_START)
    {
        ASM_GET_L1_WR_PTR(L1core_Asm_Buf_Info.buf_write_ptr);
        ASM_GET_L1_RD_PTR(rd_ptr); //word unit
        
        if(L1core_Asm_Buf_Info.buf_read_ptr != rd_ptr)
        {
    	      MALMO_ASM_UpdateL1ReadPtr(L1core_Asm_Buf_Info.buf_read_ptr << 2);
        }
    }
    else if(GET_L1CORE_ASM_BUF_INFO(ASM_STATE) == ASM_STATE_STOP)
    {
    	  L1core_Asm_Buf_Info.buf_write_ptr = GET_L1CORE_ASM_BUF_INFO(ASM_BUF_WR_PTR);
    	  L1core_Asm_Buf_Info.buf_read_ptr = GET_L1CORE_ASM_BUF_INFO(ASM_BUF_RD_PTR);
    }


    *read_ptr = ((L1core_Asm_Buf_Info.buf_read_ptr)<<2) ; 
    *write_ptr = ((L1core_Asm_Buf_Info.buf_write_ptr)<<2);  
    
    if(GET_L1CORE_ASM_BUF_INFO(ASM_STATE) == ASM_STATE_STOP)
    {
         if(L1core_Asm_Buf_Info.buf_write_ptr == L1core_Asm_Buf_Info.buf_read_ptr)
         {
         	    L1core_Asm_Buf_Info.buf_write_ptr = 0;
         	    L1core_Asm_Buf_Info.buf_read_ptr = 0;
         }    
    }
#endif  //	defined(__KAL_CROSS_CORE_SUPPORT__)  
}


void MALMO_ASM_UpdateL1ReadPtr(kal_uint32 ptr)
{
#if defined(__KAL_CROSS_CORE_SUPPORT__) 
    L1core_Asm_Buf_Info.buf_read_ptr = (ptr>>2);
    ASM_SET_L1_RD_PTR(L1core_Asm_Buf_Info.buf_read_ptr); //In word
    
    if(GET_L1CORE_ASM_BUF_INFO(ASM_STATE) == ASM_STATE_STOP)
    {
         SET_L1CORE_ASM_BUF_INFO(ASM_BUF_RD_PTR,L1core_Asm_Buf_Info.buf_read_ptr);
         
         if(L1core_Asm_Buf_Info.buf_write_ptr == L1core_Asm_Buf_Info.buf_read_ptr)
         {
         	    L1core_Asm_Buf_Info.buf_write_ptr = 0;
         	    L1core_Asm_Buf_Info.buf_read_ptr = 0;
         }    
    }
#endif  //	defined(__KAL_CROSS_CORE_SUPPORT__)  
}

void MALMO_ASM_L1IRQMask(void)
{
    IRQMask(ASM_L12PS_IRQID);
}

void MALMO_ASM_L1IRQUnMask(void)
{
    IRQUnmask(ASM_L12PS_IRQID);
}

void MALMO_ASM_RegsterL1LISR(void* reg_lisr)
{
    IRQ_Register_LISR(ASM_L12PS_IRQID, reg_lisr, "malmo l1 lisr");
    IRQSensitivity(ASM_L12PS_IRQID, KAL_FALSE);
    IRQUnmask(ASM_L12PS_IRQID);  
}

kal_bool ASMCheckL1BufferEndMark(void)
{
    if(*(volatile kal_uint32*)(L1core_Asm_Buf_Info.buf_base_address+L1core_Asm_Buf_Info.buf_size*1024-4) != ASM_BUF_END)
    {
    	//Buffer warp
    	return KAL_TRUE;
    }
    else
    {
    	//Buffer not warp
    	return KAL_FALSE;
    }
}

kal_bool MALMO_ASM_L1BufferIsWrap(void)
{
    return ASMCheckL1BufferEndMark();
}
void MALMO_ASM_GetL1BufferAddrSize(kal_uint32 *base_addr, kal_uint32 *size)
{
    *base_addr = L1core_Asm_Buf_Info.buf_base_address;
    *size = L1core_Asm_Buf_Info.buf_size*1024;
}


#endif  //defined(__PCORE__)
