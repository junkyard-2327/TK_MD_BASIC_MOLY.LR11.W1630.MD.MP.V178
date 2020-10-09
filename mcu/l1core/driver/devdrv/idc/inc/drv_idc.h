#ifndef __DRV_IDC_H__
#define __DRV_IDC_H__

#if defined(TK6291) && !defined(ATEST_DRV_ENABLE)
#define IDC_6291_WORKAROUND
#endif

#include "kal_general_types.h"

void drv_idc_init(kal_bool is_sm);
void drv_idc_init_uart(void);
void drv_idc_init_isr(void);
void drv_sleep_notify(void);
void drv_idc_activate(void);
void drv_idc_get_support(IDC_SUPPORT_T *support);
void drv_idc_conn_txrx_count(kal_bool is_start);
void drv_idc_open(kal_uint32 mod_id);
void drv_idc_close(void);
void drv_idc_set_dcb_config(IDC_CTRL_DCB_CONFIG_T idc_config);
void drv_idc_get_dcb_config(IDC_CTRL_DCB_CONFIG_T *DCB);
void drv_idc_set_baudrate(kal_uint32 baudrate);
void drv_idc_set_fifo_trigger(kal_uint8 rx_threshold);
void drv_idc_set_pm_config(kal_bool start, kal_uint8 priority, kal_uint8 priority_bit_en, kal_uint8 pattern, kal_uint8 pattern_bit_en);
void drv_idc_get_pm_config(kal_bool start, kal_uint8 *priority, kal_uint8 *priority_bit_en, kal_uint8 *pattern, kal_uint8 *pattern_bit_en);
void drv_idc_send_event(kal_uint8 num_event, IDC_EVENT_T *event, kal_bool sleep_mode);
void drv_idc_schedule_event(kal_uint8 schedule_num, kal_uint8 num_event, IDC_EVENT_T *event);
void drv_idc_set_global_offset(kal_uint8 schedule_num, kal_uint32 time_base);
void drv_idc_start_event(kal_uint8 schedule_num, kal_uint32 bitmap);
void drv_idc_stop_event(kal_uint8 schedule_num, kal_uint32 bitmap);
void drv_idc_purge(UART_buffer dir);
void drv_idc_get_schedule_status(kal_uint32 *schedule_status);
kal_bool drv_idc_check_event_send_out(void);
DCL_STATUS drv_idc_set_pin_config(IDC_PIN_MODE_T pin_mode);
DCL_STATUS drv_idc_get_pin_config(IDC_PIN_MODE_T *pin_mode);
void drv_idc_set_ilm(kal_bool ilm_mode);
void idc_uart_lisr(kal_uint32 vector);
void idc_uart_hisr(void);
void idc_pm_lisr(kal_uint32 vector);
void idc_pm_hisr(void);
void idc_send_rx_data_by_ilm(void);
int drv_idc_register_pm_callback(kal_uint8 pm_idx, IDC_DRV_TO_EL1_CALLBACK func_ptr , kal_bool private_data) ;
int drv_idc_unregister_pm_callback(kal_uint8 pm_idx) ;

#if defined(IDC_6291_WORKAROUND)
void drv_idc_wait_event_complete(void);
#endif


#endif
