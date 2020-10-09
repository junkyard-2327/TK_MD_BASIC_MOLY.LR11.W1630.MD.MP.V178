/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   idc_internal.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for IDC.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __IDC_INTERNAL_H__
#define __IDC_INTERNAL_H__

#include "dcl.h"

#include "kal_general_types.h"
#include "drv_comm.h"

#include "dcl_idc.h"

#define IDC_PM_NUM 4


struct idc_drv_to_el1_callback {	
	IDC_DRV_TO_EL1_CALLBACK callback_func ;
	kal_bool private_data ;
};

typedef struct
{
	kal_uint32		owner_id;
	kal_uint8		main_state;
	kal_bool		intr_en;
	kal_uint8		schedule_state[2];
	kal_uint8		event_cnt[2];
	kal_uint8		event_w_index;
	kal_uint16		event_usage_bit_map[2];
	kal_uint8		event_pending_cnt[2];		// Pend an event when offset is larger than 1 ms
	kal_uint8		event_pending_idx[2][16];	// Store the index that indicates which event is pending
	kal_uint32		rx_buf;
	IDC_CTRL_DCB_CONFIG_T	DCB;
	IDC_PIN_MODE_T		pin_mode;
	struct idc_drv_to_el1_callback pm_cb_handle[IDC_PM_NUM];
} idc_struct_t;

typedef struct
{
	kal_uint8	type;
	kal_uint16	msg;
} IDC_ILM_MSG_T;

typedef enum
{
	IDC_OPEN,
	IDC_IN_USE,
	IDC_IN_SLEEP,
	IDC_SUSPEND,
	IDC_CLOSED
} IDC_MAIN_STATE_T;

typedef enum
{
	IDC_PLAN,
	IDC_RUN
} IDC_SCHEDULE_STATE_T;
#endif
