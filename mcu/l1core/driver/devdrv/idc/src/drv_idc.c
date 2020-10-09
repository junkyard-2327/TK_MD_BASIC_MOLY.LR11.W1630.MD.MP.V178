#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "us_timer.h"
#include "sync_data.h"	
#include "sleepdrv_interface.h"

#include "drv_features.h"
#include "drv_comm.h"

#include "drv_msgid.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"

#include "intrCtrl.h"

#include "idc_internal.h"
#include "dcl_idc.h"
#include "drv_idc.h"

#include "idc_reg.h"
#include "svc_sap.h"

#ifdef ATEST_DRV_ENABLE
#define __4G_IDC__
#define dhl_trace(...) 
#define DT_IDC_PRINTF(x...) \
do{                         \
	dbg_print(x);           \
	dbg_flush();            \
}while(0)
#else /*ATEST_DRV_ENABLE*/
#include "dhl_trace.h"
#include "idc_trace.h"
#endif

#define LTE_TIMER_MHZ	(61.44)
#define LTE_CLOCK_MHZ	(52) 
#define LTE_TIMER_BASE 			0xF60E0000
#define LTE_TIMER_START			LTE_TIMER_BASE


idc_struct_t idc_port = {0, IDC_CLOSED, KAL_FALSE, {IDC_PLAN, IDC_PLAN}, {0, 0}, 0, {0, 0}, {0, 0}, {{0}, {0}}, 0, {0, len_8, sb_1, pa_none}, IDC_INTERNAL_PIN};
kal_char idc_dbg_str[100];
kal_bool idc_read_RBR = KAL_FALSE;
kal_uint8 idc_rx_count = 0;
kal_uint8 idc_rx_history[20] = {0};
kal_uint32 idc_rx_history_time[20] = {0};
kal_uint8 idc_lisr_count, idc_hisr_count = 0;
kal_uint32 idc_hisr_time[20] = {0};
kal_uint16 IIR_L, IIR_H, IER_L, LSR_L, LSR_H;

kal_bool idc_rx_suspend = KAL_FALSE;
kal_uint8 idc_rx_suspend_timer = 0;
kal_bool idc_count_start = KAL_FALSE;
kal_bool idc_ilm_on = KAL_FALSE;
kal_uint32 idc_80211_tx_count = 0;
kal_uint32 idc_80211_rx_count = 0;


static kal_hisrid idc_pm_hisrid;
static kal_hisrid idc_uart_hisrid;
kal_uint8 idc_sleep_handle;

#if defined(ATEST_DRV_ENABLE)
#define LTE_TIMER_BASE 			0xF60E0000
#define LTE_TIMER_READ_TIME0		(LTE_TIMER_BASE + 0x0C)
#define LTE_TIMER_STIME_READ0		(LTE_TIMER_BASE + 0x10)
#endif

#if defined(IDC_6291_WORKAROUND)
kal_uint32 idc_event_offset[2][16] = {{0}, {0}};
kal_uint32 idc_pending_event_offset[2][16] = {{0}, {0}};
#endif

void drv_idc_conn_txrx_count(kal_bool is_start)
{
	if (KAL_TRUE == is_start)
	{
		dhl_trace(TRACE_INFO, 0, IDC_START_COUNT_MSG);
		idc_count_start = KAL_TRUE;
		idc_80211_tx_count = 0;
		idc_80211_rx_count = 0;
	}
	else
	{
		idc_count_start = KAL_FALSE;
		dhl_trace(TRACE_INFO, 0, IDC_END_COUNT_MSG, idc_80211_tx_count, idc_80211_rx_count);
	}
}

void drv_idc_init_uart(void)
{
#if !defined(ATEST_DRV_ENABLE)
	dhl_trace(TRACE_INFO, 0, IDC_UART_INIT_MSG);
#else
	kal_sprintf(idc_dbg_str, "drv_idc: IDC UART Init\n\r");
	DT_IDC_PRINTF(idc_dbg_str);
#endif

#if defined(TK6291) || defined(MT6755) || defined(MT6797)||defined(MT6757)||defined(MT6750S)
	// Open Clock Gating of IDC_UART
	DRV_WriteReg32(0xF6800008, (0x1 << 6));

	// Open Clock Gating of IDC_CTRL
	DRV_WriteReg32(0xF60F0008, (0x1 << 6));

	// Set UART_CK_CG_DIS
	DRV_WriteReg32(IDC_UART_BASE + 0xB4, 1);
#endif

	// Initialize IDC UART FIFO threshold
	drv_idc_set_fifo_trigger(1);
	DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_FIFOINI);
	dhl_trace(TRACE_INFO, 0, IDC_CLEAN_RXFIFO_MSG , __FUNCTION__);
	// Enable RX interrupt
	DRV_WriteReg32(IDC_UART_IER, IDC_UART_IER_ERBFI);

	// Initialize baud rate
	drv_idc_set_baudrate(4000000);

	return;
}

void drv_idc_init_isr(void)
{
	IRQ_Register_LISR(IRQ_IDC_UART_CODE, idc_uart_lisr, "IDC_UART");
	idc_uart_hisrid = kal_init_hisr(IDC_UART_HISR);
	IRQSensitivity(IRQ_IDC_UART_CODE, KAL_FALSE);// KAL_TRUE :pulse trigger KAL_FALSE: level trigger
	IRQClearInt(IRQ_IDC_UART_CODE);
	IRQUnmask(IRQ_IDC_UART_CODE);
	dhl_trace(TRACE_INFO, 0, IDC_UNMASK_UART_ISR_MSG , __FUNCTION__);
	
	IRQ_Register_LISR(IRQ_IDC_PM_CODE, idc_pm_lisr, "IDC_PM");
	idc_pm_hisrid = kal_init_hisr(IDC_PM_HISR);
	IRQSensitivity(IRQ_IDC_PM_CODE, KAL_FALSE);
	IRQClearInt(IRQ_IDC_PM_CODE);
	IRQUnmask(IRQ_IDC_PM_CODE);
	
}

//Before in sleep mode, El1 call this function to let IDC know us in sleep mode
void drv_sleep_notify(void)
{
	idc_port.main_state = IDC_IN_SLEEP;
	
	IRQMask(IRQ_IDC_UART_CODE);

	// Clear scheduled events
	drv_idc_stop_event(0, 0xFFFF);
	drv_idc_stop_event(1, 0xFFFF);

	// Turn off ERBFI and turn on ETBEI
	DRV_WriteReg32(IDC_UART_IER, IDC_UART_IER_ETBEI);
	IRQUnmask(IRQ_IDC_UART_CODE);
	dhl_trace(TRACE_INFO, 0, IDC_UNMASK_UART_ISR_MSG , __FUNCTION__);	
}

// After wake-up, IRQ is masked until first SF tick in order to prevent rx data error
void drv_idc_activate(void)
{	
	dhl_trace(TRACE_INFO, 0, IDC_ACTIVATE_MSG);	
		
	// Clean IDC UART FIFO
	DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_FIFOINI);
	dhl_trace(TRACE_INFO, 0, IDC_CLEAN_RXFIFO_MSG , __FUNCTION__);
	// Clean IRQ status and then unmask
	IRQClearInt(IRQ_IDC_UART_CODE);
	IRQUnmask(IRQ_IDC_UART_CODE);
	dhl_trace(TRACE_INFO, 0, IDC_UNMASK_UART_ISR_MSG , __FUNCTION__);
}

// Bootup init: drv_idc_init(KAL_FALSE)
// Reinit after sleep: drv_idc_init(KAL_TRUE) -> drv_idc_activate
void drv_idc_init(kal_bool sleep_mode)
{
#if defined(__4G_IDC__)
	kal_uint32 i = 0;
	//check IDC_UART_FRACDIV_L is preset value(0xEA) Add SAMPLE_COUNT by 1 for bit[0], bit[2], bit[4], bit[5], bit[6]
	//If yes , md nonsleep last time
	if(DRV_Reg32(IDC_UART_FRACDIV_L) == 0xEA)
	{
		dhl_trace(TRACE_INFO, 0, IDC_NONSLEEP_MSG);
	}
	

	// Mask IRQs before init
	IRQMask(IRQ_IDC_UART_CODE);
	IRQMask(IRQ_IDC_PM_CODE);

	// Initial flags/config of IDC driver
	idc_port.schedule_state[0] = IDC_PLAN;
	idc_port.schedule_state[1] = IDC_PLAN;
	idc_port.event_cnt[0] = 0;
	idc_port.event_cnt[1] = 0;
	idc_port.event_w_index = 0;
	idc_port.event_usage_bit_map[0] = 0;
	idc_port.event_usage_bit_map[1] = 0;
	idc_port.rx_buf = 0;
	
	drv_idc_init_uart();
	dhl_trace(TRACE_INFO, 0, IDC_SLEEP_MSG, sleep_mode);

	
	// ISR and callback functions do not need init after sleep
	if (!sleep_mode)
	{
#ifndef ATEST_DRV_ENABLE
		idc_sleep_handle = SleepDrv_GetHandle();
#endif

		// Init callback functions
		for (i = 0; i < IDC_PM_NUM; ++i)
			idc_port.pm_cb_handle[i].callback_func = NULL;

		// Register UART, PM ISR, then unmask IRQ
		drv_idc_init_isr();
		idc_port.intr_en = KAL_TRUE;
		
		// Enable TX Count of IDC_CTRL
		DRV_WriteReg32(IDC_CTRL_DATA_CNT_CTRL, 0x1);
	}

	idc_port.main_state = IDC_IN_USE;
#else	
	//IDC should not be initialized if __4G_IDC__ was not defined
	ASSERT(0);
#endif

	return;
}

void drv_idc_get_support(IDC_SUPPORT_T *support)
{
#if defined(__4G_IDC__)
	support->idc = KAL_TRUE;

#if defined(MT6290)
	if (TDM_REQ_LO_EINT_NO == EINT_CHANNEL_NOT_EXIST) // EINT variables are not defined in codegen.dws
	{
		support->gpio = KAL_FALSE;
		support->uart = KAL_TRUE;
	}
	else	// For 82LTE, 92LTE 
	{
		support->gpio = KAL_TRUE;
		support->uart = KAL_FALSE;
	}
#else
	support->gpio = KAL_FALSE;
	support->uart = KAL_TRUE;
#endif

#else // !defined(__4G_IDC__)
	support->idc = KAL_FALSE;
	support->gpio = KAL_FALSE;
	support->uart = KAL_FALSE;
#endif
	return;
}

void drv_idc_open(kal_uint32 mod_id)
{
	idc_port.owner_id = mod_id;
	idc_port.main_state = IDC_OPEN;

	return;
}

void drv_idc_close()
{
	kal_uint32 i = 0;

	// stop all events before closing IDC
	DRV_WriteReg32(IDC_CTRL_SCH_STOP_1500, 0xFFFF);

	// disable interrupt
	IRQMask(IRQ_IDC_UART_CODE);
	DRV_WriteReg8(IDC_UART_IER, IDC_UART_IER_ALLOFF);
	IRQUnmask(IRQ_IDC_UART_CODE);
	dhl_trace(TRACE_INFO, 0, IDC_UNMASK_UART_ISR_MSG , __FUNCTION__);
	idc_port.intr_en = KAL_FALSE;
	idc_port.rx_buf = 0;

	for (i = 0; i < 4; ++i)
	{
		DRV_WriteReg32(IDC_PRI(i), 0);
		DRV_WriteReg32(IDC_PRI_BITEN(i), 0);
		DRV_WriteReg32(IDC_PAT(i), 0);
		DRV_WriteReg32(IDC_PAT_BITEN(i), 0);
	}

	idc_port.schedule_state[0] = IDC_PLAN;
	idc_port.schedule_state[1] = IDC_PLAN;
	idc_port.event_cnt[0] = 0;
	idc_port.event_cnt[1] = 0;
	idc_port.event_usage_bit_map[0] = 0;
	idc_port.event_usage_bit_map[1] = 0;
	idc_port.event_pending_cnt[0] = 0;
	idc_port.event_pending_cnt[1] = 0;
	idc_port.rx_buf = 0;

	idc_port.owner_id = 0;
	idc_port.main_state = IDC_CLOSED;

	return;
}

void drv_idc_set_dcb_config(IDC_CTRL_DCB_CONFIG_T idc_config)
{
	kal_uint8 tmp_lcr, tmp_ier;

	IRQMask(IRQ_IDC_UART_CODE);
	tmp_ier = DRV_Reg8(IDC_UART_IER);
	DRV_WriteReg8(IDC_UART_IER, IDC_UART_IER_ALLOFF);
	IRQUnmask(IRQ_IDC_UART_CODE);
	dhl_trace(TRACE_INFO, 0, IDC_UNMASK_UART_ISR_MSG , __FUNCTION__);
	// set baud rate
	drv_idc_set_baudrate(idc_config.u4Baud);

	tmp_lcr = DRV_Reg32(IDC_UART_LCR);
	tmp_lcr &= ~0x3F;
	// set number of bits per character
	switch(idc_config.u1DataBits)
	{
		case len_5:
			tmp_lcr |= IDC_UART_WLS_5;
			break;
		case len_6:
			tmp_lcr |= IDC_UART_WLS_6;
			break;
		case len_7:
			tmp_lcr |= IDC_UART_WLS_7;
			break;
		case len_8:
			tmp_lcr |= IDC_UART_WLS_8;
			break;
		default:
			break;
	}

	switch(idc_config.u1StopBits)
	{
		case sb_1:
			tmp_lcr |= IDC_UART_1_STOP;
			break;
		case sb_2:
			tmp_lcr |= IDC_UART_2_STOP;
			break;
		case sb_1_5:
			tmp_lcr |= IDC_UART_1_5_STOP;
			break;
		default:
			break;
	}

	switch(idc_config.u1Parity)
	{
		case pa_none:
			tmp_lcr |= IDC_UART_NONE_PARITY;
			break;
		case pa_odd:
			tmp_lcr |= IDC_UART_ODD_PARITY;
			break;
		case pa_even:
			tmp_lcr |= IDC_UART_EVEN_PARITY;
			break;
		default:
			break;
	}

	DRV_WriteReg32(IDC_UART_LCR, tmp_lcr);

	kal_mem_cpy((void *) &idc_port.DCB, (void *) &idc_config, sizeof(IDC_CTRL_DCB_CONFIG_T));
   
	IRQMask(IRQ_IDC_UART_CODE);
	DRV_WriteReg8(IDC_UART_IER, tmp_ier);
	IRQUnmask(IRQ_IDC_UART_CODE);
	dhl_trace(TRACE_INFO, 0, IDC_UNMASK_UART_ISR_MSG , __FUNCTION__);
}


void drv_idc_get_dcb_config(IDC_CTRL_DCB_CONFIG_T *DCB)
{
	kal_mem_cpy((void *) DCB, (void *) &idc_port.DCB, sizeof(IDC_CTRL_DCB_CONFIG_T));

	return;
}

void drv_idc_set_baudrate(kal_uint32 baudrate)
{
	kal_uint8 tmp_lcr = 0;
	kal_uint32 freq_div = 1;
	kal_uint32 sample_count = 0;

	idc_port.DCB.u4Baud = baudrate;

	// Only 4M baudrate is used in IDC now
	ASSERT(baudrate == 4000000);

	sample_count = 6;
	freq_div = 1;

	// configure register
	// based on sample_count * baud_pulse, baud_rate = system clock frequency / (SAMPLE_COUNT + 1) / {DLM, DLL}
	DRV_WriteReg32(IDC_UART_HIGHSPEED, IDC_UART_HIGHSPEED_X);

	tmp_lcr = DRV_Reg32(IDC_UART_LCR);
	DRV_WriteReg32(IDC_UART_LCR, tmp_lcr | IDC_UART_LCR_DLAB);
	// -- DLAB start --

	DRV_WriteReg32(IDC_UART_DLL, freq_div & 0xFF);
	DRV_WriteReg32(IDC_UART_DLM, (freq_div >> 8) & 0xFF);

	DRV_WriteReg32(IDC_UART_SAMPLE_COUNT, sample_count - 1);
	DRV_WriteReg32(IDC_UART_SAMPLE_POINT, (sample_count - 1) >> 1);

#if defined(TK6291) || defined(MT6755) || defined(MT6797)||defined(MT6757)||defined(MT6750S)
	// Add SAMPLE_COUNT by 1 for bit[0], bit[2], bit[4], bit[5], bit[6] (8'b11101010) because FRACDIV_M is not availble in TK6291
	DRV_WriteReg32(IDC_UART_FRACDIV_L, 0xEA);
#else
	// Add SAMPLE_COUNT by 1 for bit[0], bit[2], bit[4], bit[6] (8'b10101010)
	DRV_WriteReg32(IDC_UART_FRACDIV_L, 0x55);
	// Add SAMPLE_COUNT by 1 for STOP bits (2'b10)
	DRV_WriteReg32(IDC_UART_FRACDIV_M, 0x2);
#endif

	DRV_WriteReg32(IDC_UART_LCR, tmp_lcr | 0x3);
	// -- DLAB end --
}


void drv_idc_set_fifo_trigger(kal_uint8 rx_threshold)
{
	DRV_WriteReg32(IDC_UART_RXTRIG, rx_threshold);
	return;
}

void drv_idc_set_pm_config(kal_uint8 pm_idx, kal_uint8 priority, kal_uint8 priority_bit_en, kal_uint8 pattern, kal_uint8 pattern_bit_en)
{
	IRQMask(IRQ_IDC_PM_CODE);

	// Use DSB to make sure that pattern match is turned off before setting pattern
	DRV_WriteReg32(IDC_PRI_BITEN(pm_idx), 0);
	Data_Sync_Barrier();

	IRQClearInt(IRQ_IDC_PM_CODE);
	Data_Sync_Barrier();

	// PRI_BITEN should be set lastly
	DRV_WriteReg32(IDC_PAT(pm_idx), pattern);
	DRV_WriteReg32(IDC_PAT_BITEN(pm_idx), pattern_bit_en);
	DRV_WriteReg32(IDC_PRI(pm_idx), priority);
	DRV_WriteReg32(IDC_PRI_BITEN(pm_idx), priority_bit_en);

	IRQUnmask(IRQ_IDC_PM_CODE);
}

void drv_idc_get_pm_config(kal_uint8 pm_idx, kal_uint8 *priority, kal_uint8 *priority_bit_en, kal_uint8 *pattern, kal_uint8 *pattern_bit_en)
{
	*priority = DRV_Reg8(IDC_PRI(pm_idx));
	*priority_bit_en = DRV_Reg8(IDC_PRI_BITEN(pm_idx));
	*pattern = DRV_Reg8(IDC_PAT(pm_idx));
	*pattern_bit_en = DRV_Reg8(IDC_PAT_BITEN(pm_idx));
}

void drv_idc_send_event(kal_uint8 num_event, IDC_EVENT_T *event, kal_bool sleep_mode)
{
	kal_uint32 i = 0;
	
#ifdef ATEST_DRV_ENABLE
//	DT_IDC_PRINTF("drv_idc: send event\n\r");
#endif
	
	if (sleep_mode)
	{
		//IRQMask(IRQ_IDC_UART_CODE);

		// Clear scheduled events
		drv_idc_stop_event(0, 0xFFFF);
		drv_idc_stop_event(1, 0xFFFF);
#ifndef ATEST_DRV_ENABLE
		SleepDrv_SleepDisable(idc_sleep_handle);
#endif
	}

	for(i = 0; i < num_event; i++)
	{
		DRV_WriteReg32(IDC_UART_BASE, event[i].data[0]);
		DRV_WriteReg32(IDC_UART_BASE, event[i].data[1]);
	}

/*	if (sleep_mode)
	{
		// Turn off ERBFI and turn on ETBEI
		DRV_WriteReg32(IDC_UART_IER, IDC_UART_IER_ETBEI);
		IRQUnmask(IRQ_IDC_UART_CODE);
		dhl_trace(TRACE_INFO, 0, IDC_UNMASK_UART_ISR_MSG , __FUNCTION__);
	}
*/
	return;
}

void drv_idc_schedule_event(kal_uint8 schedule_num, kal_uint8 num_event, IDC_EVENT_T *event)
{
	kal_bool is_pending = KAL_FALSE;
	kal_uint8 schedule_num_temp = 0;
	kal_uint32 i = 0;
	kal_uint32 event_usage_status = 0;
	kal_uint32 event_usage_this = 0;

	if(schedule_num > 1) ASSERT(0);

	dhl_trace(TRACE_INFO, 0, IDC_SCHEDULE_0_MSG, schedule_num, num_event);
#ifdef ATEST_DRV_ENABLE
//	DT_IDC_PRINTF("drv_idc: schedule_num = %d, num_event = %d\n\r", schedule_num, num_event);
#endif

	for(i = 0; i < num_event; i++)
	{
		is_pending = KAL_FALSE;
		schedule_num_temp = schedule_num;

		event_usage_status = idc_port.event_usage_bit_map[0] | idc_port.event_usage_bit_map[1];
		if(event_usage_status == 0xFFFF) ASSERT(0);

		while (1)
		{
			if ((1 << idc_port.event_w_index) & event_usage_status)
			{
				idc_port.event_w_index++;
				if (idc_port.event_w_index == 16) idc_port.event_w_index = 0;
			}
			else
			{
				break;
			}
		}
		
		// Set event config
		DRV_WriteReg32(IDC_CTRL_IND_ADDR_D, IDC_BSI_SCH_EVT_CON(idc_port.event_w_index));
		DRV_WriteReg32(IDC_CTRL_IND_DATA_D, IDC_BSI_SCH_EVT_CON_STP_STA_ADDR((idc_port.event_w_index << 1) + 1, idc_port.event_w_index << 1));
		
		// Check the range of the event offset
		if (event[i].offset < 61440)
			idc_port.schedule_state[schedule_num] = IDC_RUN;		// < 1ms
		else if (event[i].offset >= 122880)	// >= 2ms, pending to the same scheduler
		{
			is_pending = KAL_TRUE;	
			event[i].offset -= 122880;
		}
		else					// 1 ~ 2 ms, pending to the other scheduler
		{
			is_pending = KAL_TRUE;
			event[i].offset -= 61440;
			schedule_num_temp = ~schedule_num & 0x1;
		}

		DRV_WriteReg32(IDC_CTRL_IND_DATA_D, schedule_num_temp);
		// Transform from 61.44M to 52M/2
		DRV_WriteReg32(IDC_CTRL_IND_DATA_D, event[i].offset * LTE_CLOCK_MHZ / 2 / LTE_TIMER_MHZ);

		//dhl_trace(TRACE_INFO, 0, IDC_SCHEDULE_1_MSG, event[i].offset);
#ifdef ATEST_DRV_ENABLE
//		DT_IDC_PRINTF("drv_idc: event offset = %x, data = %x %x\n\r", event[i].offset, event[i].data[0], event[i].data[1]);
#endif
		// Set event data
		DRV_WriteReg32(IDC_CTRL_IND_ADDR_D, IDC_BSI_SCH_DATA(idc_port.event_w_index << 1));
		DRV_WriteReg32(IDC_CTRL_IND_DATA_D, event[i].data[0]);
		DRV_WriteReg32(IDC_CTRL_IND_DATA_D, event[i].data[1]);

		if (KAL_TRUE == is_pending)
		{
			idc_port.event_pending_idx[schedule_num_temp][idc_port.event_pending_cnt[schedule_num_temp]] = idc_port.event_w_index;
			idc_port.event_pending_cnt[schedule_num_temp]++;
#if defined(IDC_6291_WORKAROUND)
			idc_pending_event_offset[schedule_num_temp][idc_port.event_cnt[schedule_num_temp]] = event[i].offset;
#endif
			// Should not exceed the maximum number of events
			ASSERT(idc_port.event_pending_cnt[schedule_num_temp] <= 16);
		}
		else
		{
			event_usage_this |= (1 << idc_port.event_w_index);
#if defined(IDC_6291_WORKAROUND)
			idc_event_offset[schedule_num_temp][idc_port.event_cnt[schedule_num_temp]] = event[i].offset;
#endif
		}
		
		// Record the number and usage bitmap for the scheduler
		idc_port.event_cnt[schedule_num_temp]++;
		idc_port.event_usage_bit_map[schedule_num_temp] |= (1 << idc_port.event_w_index);

		idc_port.event_w_index++;
		if (idc_port.event_w_index == 16) idc_port.event_w_index = 0;
	}
	drv_idc_start_event(schedule_num, event_usage_this);
	return;
}

void drv_idc_set_global_offset(kal_uint8 schedule_num, kal_uint32 time_base)
{
	kal_uint32 i = 0;
	kal_uint32 j = 0;
	kal_uint32 status = 0;
	kal_uint32 tx_cnt = 0;
	kal_uint32 idc_event_status = 0;
#ifdef ATEST_DRV_ENABLE
//	kal_uint32 status_head, status_tail;
#endif

	if (schedule_num > 1) ASSERT(0);
	if (time_base >= 614400) ASSERT(0);

	if (idc_rx_suspend == KAL_TRUE)
	{
		if (idc_port.main_state == IDC_SUSPEND)
		{
			if (++idc_rx_suspend_timer >= 10)
			{	
				dhl_trace(TRACE_INFO, 0, IDC_RX_RESUME_MSG);
				idc_rx_suspend = KAL_FALSE;
				// Clear RX FIFO and enalbe RX interrupt
				IRQMask(IRQ_IDC_UART_CODE);
				DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_CLRR | IDC_UART_FCR_FIFOEN);
				DRV_WriteReg32(IDC_UART_IER, IDC_UART_IER_ERBFI);
				// Change idc_port state
				idc_port.main_state = IDC_IN_USE;
				IRQClearInt(IRQ_IDC_UART_CODE);
				IRQUnmask(IRQ_IDC_UART_CODE);
				dhl_trace(TRACE_INFO, 0, IDC_UNMASK_UART_ISR_MSG , __FUNCTION__);
			}	
		}
		else
		{
			dhl_trace(TRACE_INFO, 0, IDC_WAKEUP_RX_RESUME_MSG);
			idc_rx_suspend = KAL_FALSE;
		}
		
	}
	
	//get tx count
	tx_cnt = DRV_Reg32(IDC_CTRL_DATA_CNT) & 0xFFFF;
	if (tx_cnt >= 65536) ASSERT(0);
	
	if(idc_port.schedule_state[schedule_num] == IDC_RUN)
		dhl_trace(TRACE_INFO, 0, IDC_TX_COUNT_MSG, tx_cnt);
	//transform event_usage_bit_map 16bit->32bit
	for(j = 0; j < 16; j++)
	{
		if((idc_port.event_usage_bit_map[schedule_num] >> j) & 0x1)
			idc_event_status = (idc_event_status | (0x3 << (j*2)));
	}
	// Stop uncompleted events
	if ((status = (DRV_Reg32(IDC_CTRL_SCH_STATUS_1500) & idc_event_status)))
	{
#ifdef ATEST_DRV_ENABLE
//		status_head = status >> 16;
//		status_tail = ((status << 16) >>16);
#endif
		drv_idc_stop_event(schedule_num, 0xFFFF);
#ifdef ATEST_DRV_ENABLE
//		DT_IDC_PRINTF("drv_idc: [Warning] Some events are still busy in scheduler %d. Status = %x/%x \n\r", schedule_num, status_head, status_tail);
#endif
		dhl_trace(TRACE_INFO, 0, IDC_EVENTS_STILL_BUSY_MSG, schedule_num, status);
	}

	// Set TX global offset with LTE timer value that TX offset timer will start to toggle
	DRV_WriteReg32(IDC_CTRL_TIMER_GLO_OS(schedule_num), time_base);

	// Set the state to PLAN and clear the usage bitmap
	idc_port.schedule_state[schedule_num] = IDC_PLAN;
	idc_port.schedule_state[(schedule_num+1) %2] = IDC_PLAN;
	idc_port.event_usage_bit_map[schedule_num] = 0;
	idc_port.event_usage_bit_map[(schedule_num+1) %2] = 0;

	// Check if there are pending events
	idc_port.event_cnt[schedule_num] = idc_port.event_pending_cnt[schedule_num];
	idc_port.event_cnt[(schedule_num+1) %2] = 0;

	if (idc_port.event_pending_cnt[schedule_num] > 0)
	{
		// Set the state to RUN and start the pending events
		idc_port.schedule_state[schedule_num] = IDC_RUN;

		for (i = 0; i < idc_port.event_pending_cnt[schedule_num]; i++)
		{
			idc_port.event_usage_bit_map[schedule_num] |= (1 << idc_port.event_pending_idx[schedule_num][i]);
		}
		drv_idc_start_event(schedule_num, idc_port.event_usage_bit_map[schedule_num]);

		// Reset pending count
		idc_port.event_pending_cnt[schedule_num] = 0;
	}

	return;
}

kal_uint32 idc_time_base;
void drv_idc_start_event(kal_uint8 schedule_num, kal_uint32 bitmap)
{
#ifdef ATEST_DRV_ENABLE
	DRV_WriteReg32(LTE_TIMER_READ_TIME0, 0x1);
	idc_time_base = DRV_Reg32(LTE_TIMER_STIME_READ0);
//	DT_IDC_PRINTF("drv_idc: start event %d, bitmap = %x\n\r", schedule_num, bitmap);
#endif
	DRV_WriteReg32(IDC_CTRL_SCH_START_1500, idc_port.event_usage_bit_map[schedule_num] & bitmap);

	return;
}

void drv_idc_stop_event(kal_uint8 schedule_num, kal_uint32 bitmap)
{
	DRV_WriteReg32(IDC_CTRL_SCH_STOP_1500, idc_port.event_usage_bit_map[schedule_num] & bitmap);

	return;
}

void drv_idc_purge(UART_buffer dir)
{
	if(dir == TX_BUF)
		DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_CLRT | IDC_UART_FCR_FIFOEN);
	else
		DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_CLRR | IDC_UART_FCR_FIFOEN);
}

void drv_idc_get_schedule_status(kal_uint32 *schedule_status)
{
	kal_uint32 j = 0;
	kal_uint32 idc_event_status_0 = 0, idc_event_status_1 = 0;
#ifdef ATEST_DRV_ENABLE
//	kal_uint32 status_0_head, status_0_tail, status_1_head, status_1_tail;
#endif
	//transform event_usage_bit_map 16bit->32bit
	for(j = 0; j < 16; j++)
	{
		if((idc_port.event_usage_bit_map[0] >> j) & 0x1)
		{	
			idc_event_status_0 = (idc_event_status_0 | (0x3 << (j*2)));
		}
			
		if((idc_port.event_usage_bit_map[1] >> j) & 0x1)
			idc_event_status_1 = (idc_event_status_0 | (0x3 << (j*2)));
	}
	schedule_status[0] = DRV_Reg32(IDC_CTRL_SCH_STATUS_1500) & idc_event_status_0;
	schedule_status[1] = DRV_Reg32(IDC_CTRL_SCH_STATUS_1500) & idc_event_status_1;
#ifdef ATEST_DRV_ENABLE

//	status_0_head = schedule_status[0] >> 16;
//	status_0_tail = ((schedule_status[0] << 16) >>16);
//	status_1_head = schedule_status[1] >> 16;
//	status_1_tail = ((schedule_status[1] << 16) >>16);

	// %x/%x -> 16bit/16bit
//	DT_IDC_PRINTF("***********change:%x ,%x , status: %x/%x, %x/%x\r\n", idc_event_status_0,idc_event_status_1,status_0_head, status_0_tail,status_1_head,status_1_tail);
	dhl_trace(TRACE_INFO, 0, IDC_SCHEDULE_STATUS_MSG, schedule_status[0], schedule_status[1]);
#endif

	return;
}

kal_bool drv_idc_check_event_send_out(void)
{
	kal_uint32 schedule_status[2];

	// check that schedule is busy or not
	drv_idc_get_schedule_status(schedule_status);
	if(schedule_status[0] | schedule_status[1]) return KAL_FALSE;

	// check that IDC FIFO has data or not
	if(DRV_Reg32(IDC_UART_LSR) & IDC_UART_LSR_TEMT) return KAL_TRUE;

	return KAL_FALSE;
}

DCL_STATUS drv_idc_set_pin_config(IDC_PIN_MODE_T pin_mode)
{
	DCL_STATUS return_value = STATUS_FAIL;

#if defined(MT6755) || defined(MT6797)||defined(MT6757)||defined(MT6750S)
	// IRQMask to prevent unexpected interrupt
	IRQMask(IRQ_IDC_UART_CODE);

	if (pin_mode == IDC_INTERNAL_PIN)
	{
		#if !defined(ATEST_DRV_ENABLE)
			dhl_trace(TRACE_INFO, 0, IDC_INTERNAL_PIN_MSG);
		#else
			kal_sprintf(idc_dbg_str, "drv_idc: Switch to internal pins\n\r");
			DT_IDC_PRINTF(idc_dbg_str);
		#endif
		
		idc_port.pin_mode = IDC_INTERNAL_PIN;

		// Switch to internal pins
		#if defined(MT6755)|| defined(MT6757)||defined(MT6750S)
			DRV_WriteReg32(0xC0005000 + 0x6C0, DRV_Reg32(0xC0005000+ 0x6C0) & ~(0x10));
		#elif defined(MT6797)
			DRV_WriteReg32(0xC0005000 + 0x600, DRV_Reg32(0xC0005000+ 0x600) & ~(0x10));
		#endif

		return_value = STATUS_OK;
	}
	else if (pin_mode == IDC_EXTERNAL_PIN)
	{
		#if !defined(ATEST_DRV_ENABLE)
			dhl_trace(TRACE_INFO, 0, IDC_EXTERNAL_PIN_MSG);
		#else
			kal_sprintf(idc_dbg_str, "drv_idc: Switch to external pins\n\r");
			DT_IDC_PRINTF(idc_dbg_str);
		#endif

		idc_port.pin_mode = IDC_EXTERNAL_PIN;

		// Switch to external pins
		#if defined(MT6755)|| defined(MT6757)||defined(MT6750S)
			DRV_WriteReg32(0xC0005000 + 0x6C0, DRV_Reg32(0xC0005000+ 0x6C0) | 0x10);
		#endif
/*
		#if defined(MT6752)
			// Enable GPIO37 (PTA_TX) pull-up/pull-down
			DRV_WriteReg32(IOCFG_L_BASE+0xA0, DRV_Reg32(IOCFG_L_BASE+0xA0) | 0x20);
			// Select GPIO37 (PTA_TX) pull-up
			DRV_WriteReg32(IOCFG_L_BASE+0xD0, DRV_Reg32(IOCFG_L_BASE+0xD0) | 0x20);
	
			// Enable GPIO130 (PTA_RX) pull-up/pull-down
			DRV_WriteReg32(IOCFG_L_BASE+0x90, DRV_Reg32(IOCFG_L_BASE+0x90) | 0x40000);
			// Select GPIO130 (PTA_RX) pull-up
			DRV_WriteReg32(IOCFG_L_BASE+0xC0, DRV_Reg32(IOCFG_L_BASE+0xC0) | 0x40000);
		#elif defined(MT6735)
			// Enable GPIO1, 2 pull-up/pull-down
			DRV_WriteReg32(GPIO_base + 0x930, (DRV_Reg32(GPIO_base + 0x930) | (0x3 << 24)));
			// Select GPIO1, 2 pull-up
			DRV_WriteReg32(GPIO_base + 0x950, (DRV_Reg32(GPIO_base + 0x950) | (0x3 << 24)));
		#endif
*/
		return_value = STATUS_OK;
	}

	// Clear TX/RX FIFO
	DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_FIFOINI);
	dhl_trace(TRACE_INFO, 0, IDC_CLEAN_RXFIFO_MSG , __FUNCTION__);
	IRQClearInt(IRQ_IDC_UART_CODE);
	IRQUnmask(IRQ_IDC_UART_CODE);
	dhl_trace(TRACE_INFO, 0, IDC_UNMASK_UART_ISR_MSG , __FUNCTION__);
#endif

	return return_value;
}

DCL_STATUS drv_idc_get_pin_config(IDC_PIN_MODE_T *pin_mode)
{
	DCL_STATUS return_value = STATUS_FAIL;

#if defined(MT6755) || defined(MT6797)||defined(MT6757)||defined(MT6750S)
	*pin_mode = idc_port.pin_mode;
	return_value = STATUS_OK;
#endif

	return return_value;
}

// Enable ilm: drv_idc_set_ilm(KAL_TRUE)
// Disable ilm: drv_idc_set_ilm(KAL_FALSE)
void drv_idc_set_ilm(kal_bool ilm_mode)
{
	idc_ilm_on = ilm_mode;
	if(ilm_mode == KAL_TRUE)
	{
		dhl_trace(TRACE_INFO, 0, IDC_ILM_ENABLE_MSG);	
	
		return;		
	}
	else
	{
		dhl_trace(TRACE_INFO, 0, IDC_ILM_DISABLE_MSG);
		
		return;
	}
	
}

kal_uint32 idc_isr_count = 0;
void idc_uart_lisr(kal_uint32 vector)
{
		
	IRQMask(IRQ_IDC_UART_CODE);

	IIR_L = DRV_Reg(IDC_UART_IIR) & IDC_UART_IIR_INT_MASK;
	IER_L = DRV_Reg(IDC_UART_IER) & IDC_UART_IER_INT_MASK;
	LSR_L = DRV_Reg(IDC_UART_LSR);
	if (IIR_L & IDC_UART_IIR_THR_EMPTY)
	{
		DRV_WriteReg32(IDC_UART_IER, IDC_UART_IER_ALLOFF);

#ifndef ATEST_DRV_ENABLE
		SleepDrv_SleepEnable(idc_sleep_handle);
#endif
		IRQClearInt(IRQ_IDC_UART_CODE);
		IRQUnmask(IRQ_IDC_UART_CODE);
		return;
	}
	else if (IIR_L & IDC_UART_IIR_INT_INVALID)
	{
		IRQClearInt(IRQ_IDC_UART_CODE);
		IRQUnmask(IRQ_IDC_UART_CODE);
		return;
	}

	kal_activate_hisr(idc_uart_hisrid);
	idc_lisr_count++;
	if (idc_lisr_count == 20)
	{
		idc_lisr_count = 0;
	}
	return;
}

void idc_uart_hisr(void)
{
	kal_uint16 RXTRIG;

#if defined(IDC_6291_WORKAROUND)
	drv_idc_wait_event_complete();
	drv_idc_stop_event(0, idc_port.event_usage_bit_map[0]);
	drv_idc_stop_event(1, idc_port.event_usage_bit_map[1]);
#endif

	IIR_H = DRV_Reg(IDC_UART_IIR) & IDC_UART_IIR_INT_MASK;
	LSR_H = DRV_Reg(IDC_UART_LSR);
	RXTRIG = DRV_Reg(IDC_UART_RXTRIG);

#if defined(ATEST_DRV_ENABLE)
//		kal_sprintf(idc_dbg_str, "drv_idc: HISR %d, IIR = %x\n\r", ++idc_isr_count, IIR);
//		DT_IDC_PRINTF(idc_dbg_str);
#endif

	idc_hisr_time[idc_hisr_count] = ust_get_current_time();
	idc_hisr_count++;
	if (idc_hisr_count == 20)
	{
		idc_hisr_count = 0;
	}

	idc_send_rx_data_by_ilm();
	
	if (KAL_FALSE == idc_read_RBR)
	{
		#if !defined(ATEST_DRV_ENABLE)
		dhl_trace(TRACE_ERROR, 0, IDC_RX_LISR_MSG, IIR_L, IER_L, LSR_L);
		dhl_trace(TRACE_ERROR, 0, IDC_RX_HISR_MSG, IIR_H, LSR_H, RXTRIG, idc_port.main_state, idc_port.owner_id, idc_port.intr_en);
		#else
		kal_sprintf(idc_dbg_str, "drv_idc: HISR without Read Data, IIR = %x, LSR = %x, RXTRIG = %x, (%d, %d, %d)\n\r", 
			IIR_H, LSR_H, RXTRIG, idc_port.main_state, idc_port.owner_id, idc_port.intr_en);
		DT_IDC_PRINTF(idc_dbg_str);
		#endif
	}
	else if (!(IIR_H & IDC_UART_IIR_RDT))
	{
		#if !defined(ATEST_DRV_ENABLE)
		dhl_trace(TRACE_ERROR, 0, IDC_RX_EXCEPTION_MSG, IIR_H, LSR_H, RXTRIG, idc_port.main_state, idc_port.owner_id, idc_port.intr_en);
		#else
		kal_sprintf(idc_dbg_str, "drv_idc: Exception occur, IIR = %x, LSR = %x, RXTRIG = %x, (%d, %d, %d)\n\r",
			IIR_H, LSR_H, RXTRIG, idc_port.main_state, idc_port.owner_id, idc_port.intr_en);
		DT_IDC_PRINTF(idc_dbg_str);
		#endif
	}
	else if ((LSR_H == 0) | (RXTRIG == 0));
	
	idc_read_RBR = KAL_FALSE;

#if defined(IDC_6291_WORKAROUND)
	drv_idc_start_event(0, idc_port.event_usage_bit_map[0]);
	drv_idc_start_event(1, idc_port.event_usage_bit_map[1]);
#endif

	IRQClearInt(IRQ_IDC_UART_CODE);
	IRQUnmask(IRQ_IDC_UART_CODE);

	return;
}

void idc_send_rx_data_by_ilm(void)
{
	kal_uint32 count = 0;

	while(DRV_Reg(IDC_UART_LSR) & IDC_UART_LSR_DR)
	{
		// read bytes from IDC UART FIFO to SW buffer
		idc_port.rx_buf = (idc_port.rx_buf << 16) | (1 << 8) | DRV_Reg8(IDC_UART_RBR);
		idc_read_RBR = KAL_TRUE;

		idc_rx_history[idc_rx_count] = (kal_uint8)(idc_port.rx_buf & 0xFF);
		idc_rx_history_time[idc_rx_count] = ust_get_current_time();
#if defined(ATEST_DRV_ENABLE)
		DT_IDC_PRINTF("drv_idc: receive %x\n\r", idc_port.rx_buf & 0xFF);
#endif
		idc_rx_count++;
		if (idc_rx_count == 20)
		{
			idc_rx_count = 0;
			#if !defined(ATEST_DRV_ENABLE)
			dhl_trace(TRACE_INFO, 0, IDC_RX_HISTORY_MSG,
				idc_rx_history[0], idc_rx_history[1], idc_rx_history[2], idc_rx_history[3], idc_rx_history[4],
				idc_rx_history[5], idc_rx_history[6], idc_rx_history[7], idc_rx_history[8], idc_rx_history[9],
				idc_rx_history[10], idc_rx_history[11], idc_rx_history[12], idc_rx_history[13], idc_rx_history[14],
				idc_rx_history[15], idc_rx_history[16], idc_rx_history[17], idc_rx_history[18], idc_rx_history[19]
				);
			#else
			kal_sprintf(idc_dbg_str, "drv_idc: Receive %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\n\r", 
				idc_rx_history[0], idc_rx_history[1], idc_rx_history[2], idc_rx_history[3], idc_rx_history[4],
				idc_rx_history[5], idc_rx_history[6], idc_rx_history[7], idc_rx_history[8], idc_rx_history[9],
				idc_rx_history[10], idc_rx_history[11], idc_rx_history[12], idc_rx_history[13], idc_rx_history[14],
				idc_rx_history[15], idc_rx_history[16], idc_rx_history[17], idc_rx_history[18], idc_rx_history[19]
				);
			DT_IDC_PRINTF(idc_dbg_str);
			#endif
			
			// Check if the IDC commands receive too frequently
			if ((idc_rx_history_time[19] - idc_rx_history_time[0]) < 100)
			{
				idc_rx_suspend = KAL_TRUE;
				// Reset timer and start to wait 10 ms (EL1 will call event_start for each 1 ms)
				idc_rx_suspend_timer = 0;
				IRQMask(IRQ_IDC_UART_CODE);
				// Disable RX interrupt
				DRV_WriteReg32(IDC_UART_IER, IDC_UART_IER_ALLOFF);
				// Check writing register is finished
				while (DRV_Reg32(IDC_UART_IER) != IDC_UART_IER_ALLOFF)
				{
					dhl_trace(TRACE_INFO, 0, IDC_WAIT_IER_OFF_MSG, count++);
				}
				if(count);
				// Clean RX FIFO
				DRV_WriteReg32(IDC_UART_FCR, IDC_UART_FCR_RXTRIG | IDC_UART_FCR_FIFOINI);
				dhl_trace(TRACE_INFO, 0, IDC_CLEAN_RXFIFO_MSG , __FUNCTION__);
				// Change idc_port state
				idc_port.main_state = IDC_SUSPEND;
				// Use DSB to ensure that the interrupt is disabled before leaving HISR
				Data_Sync_Barrier();
				// Print warining message
				dhl_trace(TRACE_ERROR, 0, IDC_RX_SUSPEND_MSG);
				return;
			}

		}

		// if there are two-byte data in fifo and data is valid, send them by ilm
		if((idc_port.rx_buf & 0x01010101) == 0x01000101)
		{
			IDC_ILM_MSG_T tmp;
			tmp.type  = (idc_port.rx_buf & 0x001E0000) >> 17;
			tmp.msg = ((idc_port.rx_buf & 0x00E00000) >> 21) | ((idc_port.rx_buf & 0x000000FE) << 2);
			//DT_IDC_PRINTF("%x %x\n\r", tmp.type, tmp.msg);
			if (tmp.type == 0)
                        {
                                if (KAL_TRUE == idc_count_start)
				{
                                        idc_80211_rx_count++;
					dhl_trace(TRACE_INFO, 0, IDC_RX_80211_RX_MSG, tmp.type, tmp.msg);
				}
                        }
                        else if (tmp.type == 1)
                        {
                                if (KAL_TRUE == idc_count_start)
                                {
					idc_80211_tx_count++;
					dhl_trace(TRACE_INFO, 0, IDC_RX_80211_TX_MSG, tmp.type, tmp.msg);
				}
                        }
			else
			{
				if(idc_ilm_on == KAL_TRUE)
				{
					#if !defined(ATEST_DRV_ENABLE)
					dhl_trace(TRACE_INFO, 0, IDC_RX_SEND_ILM_MSG, idc_port.rx_buf, tmp.type, tmp.msg);
					#else
					kal_sprintf(idc_dbg_str, "drv_idc: MSG Send to EL1: %x, type:%x, msg:%x\n\r", idc_port.rx_buf, tmp.type, tmp.msg);
					DT_IDC_PRINTF(idc_dbg_str);
					#endif
					msg_send_inline6(MOD_IDC_UART_HISR, idc_port.owner_id, DRIVER_PS_SAP | INLINE_ILM_FLAG_SAP, MSG_ID_IDC_RX_DATA, (void *) &tmp, sizeof(IDC_ILM_MSG_T));
				}
				else
				{
					#if !defined(ATEST_DRV_ENABLE)
					dhl_trace(TRACE_INFO, 0, IDC_RX_NOT_SEND_ILM_MSG, idc_port.rx_buf, tmp.type, tmp.msg);
					#else
					kal_sprintf(idc_dbg_str, "drv_idc: MSG Not Send to EL1: %x, type:%x, msg:%x\n\r", idc_port.rx_buf, tmp.type, tmp.msg);
					DT_IDC_PRINTF(idc_dbg_str);
					#endif
				}
			
			}

			idc_port.rx_buf = 0;
		}
	}

	return;
}

void idc_pm_lisr(kal_uint32 vector)
{
	IRQMask(IRQ_IDC_PM_CODE);
	kal_activate_hisr(idc_pm_hisrid);

	return;
}

void idc_pm_hisr(void)
{
	kal_uint32 i, pm_status;

#if defined(IDC_6291_WORKAROUND)
	drv_idc_wait_event_complete();
	drv_idc_stop_event(0, idc_port.event_usage_bit_map[0]);
	drv_idc_stop_event(1, idc_port.event_usage_bit_map[1]);
#endif

	pm_status = DRV_Reg32(IDC_PM_STATUS);
#ifdef ATEST_DRV_ENABLE
//	DT_IDC_PRINTF("drv_idc: PM HISR %d, pm_idx = %x\n\r", ++idc_isr_count, pm_status);
#endif
	for (i = 0; i < 4; ++i)
	{
		if (pm_status & (1 << i))
		{
			// Write 1 to clear the status
			DRV_WriteReg32(IDC_PM_STATUS, (0x1 << i));

			// Callback to EL1
			if (idc_port.pm_cb_handle[i].callback_func)
				idc_port.pm_cb_handle[i].callback_func(idc_port.pm_cb_handle[i].private_data);
		}
	}

#if defined(IDC_6291_WORKAROUND)
	drv_idc_start_event(0, idc_port.event_usage_bit_map[0]);
	drv_idc_start_event(1, idc_port.event_usage_bit_map[1]);
#endif

	IRQClearInt(IRQ_IDC_PM_CODE);
	IRQUnmask(IRQ_IDC_PM_CODE);

	return;
}

int drv_idc_register_pm_callback(kal_uint8 pm_idx, IDC_DRV_TO_EL1_CALLBACK func_ptr , kal_bool private_data) 
{
	ASSERT(pm_idx < IDC_PM_NUM) ;

#ifdef ATEST_DRV_ENABLE
	DT_IDC_PRINTF("Register PM Callback, pm_idx = %d\n\r", pm_idx);
#endif
	idc_port.pm_cb_handle[pm_idx].callback_func = func_ptr;
	idc_port.pm_cb_handle[pm_idx].private_data = private_data;
	
	return KAL_SUCCESS ; 
}

int drv_idc_unregister_pm_callback(kal_uint8 pm_idx) 
{
	ASSERT(pm_idx < IDC_PM_NUM) ;

#ifdef ATEST_DRV_ENABLE
	DT_IDC_PRINTF("Unregister PM Callback, pm_idx = %d\n\r", pm_idx);
#endif
	idc_port.pm_cb_handle[pm_idx].callback_func = NULL;
	idc_port.pm_cb_handle[pm_idx].private_data= 0;
	
	return KAL_SUCCESS ; 
}

#if defined(IDC_6291_WORKAROUND)
// This function is used to do SW workaround for TK6291.
void drv_idc_wait_event_complete()
{
	kal_bool wait = KAL_TRUE;
	kal_uint32 timer_s;
	kal_uint32 i, j, offset_timer[2], offset_diff;

	// Read mirrored value of timer offset from IDC_CTRL_TIMERx_STA.
	// The unit of this mirrored value is 52M, and the value is updated per 32T (615 ns).
	// Convert the unit from 52M to 26M.
	offset_timer[0] = (DRV_Reg32(IDC_CTRL_TIMER0_STA_ADDR) & 0xFF) / 2;
	offset_timer[1] = (DRV_Reg32(IDC_CTRL_TIMER1_STA_ADDR) & 0xFF) / 2;
	
	while (wait == KAL_TRUE)
	{
		wait = KAL_FALSE;

		for (i = 0; i < 2; ++i)
		{
			for (j = 0; j < idc_port.event_cnt[i]; ++j)
			{
				offset_diff = offset_timer[i] - idc_event_offset[i][j];

				// Check if the offset_diff is smaller than 5 us
				if ((offset_diff > 0) && (offset_diff < 130)) wait = KAL_TRUE;
			}
		}

		for (i = 0; i < 2; ++i)
		{
			for (j = 0; j < idc_port.event_pending_cnt[i]; ++j)
			{
				offset_diff = offset_timer[i] - idc_pending_event_offset[i][j];

				// Check if the offset_diff is smaller than 5 us
				if ((offset_diff > 0) && (offset_diff < 130)) wait = KAL_TRUE;
			}
		}

		if (wait == KAL_TRUE)
		{
			// Wait 5 us to make sure that we won't access IDC_UART when IDC_CTRL is sending codeword
			timer_s = ust_get_current_time();
			while ((ust_get_current_time() - timer_s) < 5);
		}
		else
		{
			// No event that we need to wait for
			break;
		}
	}
}
#endif
