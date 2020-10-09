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
 *   cp15.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for coprocessor(CP15) control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CP15_H__
#define __CP15_H__
#include "kal_general_types.h"

/*************************************
 *  CR4 MPU Related
 *************************************/
extern void cp15_enable_mpu(void);
extern void cp15_disable_mpu(void);
extern void cp15_mpu_set_rgn_index(kal_uint32);
extern void cp15_mpu_set_rgn_addr(kal_uint32);
extern void cp15_mpu_set_rgn_accctrl(kal_uint32);
extern void cp15_mpu_set_rgn_size(kal_uint32);
extern void cp15_mpu_set_rgn_enable(kal_uint32);
extern void cp15_mpu_set_subregion_disable(kal_uint32);
extern void cp15_mpu_set_bg_region_enable(void);
extern void cp15_mpu_set_bg_region_disable(void);
extern kal_uint32 cp15_mpu_get_rbar(void);
extern kal_uint32 cp15_mpu_get_racr(void);
extern kal_uint32 cp15_mpu_get_rser(void);

/*************************************
 *  CR4 TCM Related
 *************************************/
extern void cp15_enable_btcm(kal_uint32);
extern void cp15_enable_atcm(kal_uint32);

/*************************************
 *  CR4 ICache Related
 *************************************/
extern void cp15_enable_icache(void);
extern void cp15_disable_icache(void);
extern void cp15_invalidate_icache(void);
extern void cp15_invalidate_icache_single(kal_uint32);
extern void cp15_invalidate_icache_region(kal_uint32, kal_uint32);
extern kal_bool cp15_is_icache_enabled(void);
extern kal_uint32 cp15_read_icache_info(void);

/*************************************
 *  CR4 DCache Related
 *************************************/
extern void cp15_enable_dcache(void);
extern void cp15_disable_dcache(void);
extern void cp15_invalidate_dcache(void);
extern void cp15_invalidate_dcache_single(kal_uint32);
extern void cp15_clean_dcache_single(kal_uint32);
extern void cp15_invalidate_dcache_region(kal_uint32, kal_uint32);
extern void cp15_clean_dcache_region(kal_uint32, kal_uint32);
extern void cp15_clean_and_invalidate_dcache_region(kal_uint32, kal_uint32);
extern void cp15_clean_dcache(void);
extern kal_bool cp15_is_dcache_enabled(void);
extern void cp15_clean_and_invalidate_dcache_by_setway(kal_uint32, kal_uint32);
extern void cp15_clean_all_dcache_by_setway(void);
extern void cp15_clean_and_invalidate_all_dcache_by_setway(void);
extern kal_uint32 cp15_read_dcache_info(void);

/*************************************
 *  Debug Related
 *************************************/
extern kal_uint32 cp15_read_dfsr(void);
extern kal_uint32 cp15_read_far(void);
extern kal_uint32 cp15_read_ifsr(void);
extern kal_uint32 cp15_read_ifar(void);

/*************************************
 *  ARM Core Options
 *************************************/
extern void cp15_switch_vector(kal_uint32);
extern void cp15_enable_alignment_fault(void);
extern void cp15_disable_alignment_fault(void);
extern void cp15_disable_LIL_STLDM(void);
extern void cp15_enable_undef_div_by_zero(void);

/*************************************
 *  Misc. CP15 operations
 *************************************/
extern void cp15_data_synchronization_barrier(void);
extern void cp15_inst_synchronization_barrier(void);
extern void cp15_data_memory_barrier(void);
extern void cp15_drain_write_buffer(void);
extern void cp15_enter_low_pwr_state(void);

/*************************************
 * ARM PMU Related
 *************************************/
extern void cp15_write_context_id(kal_uint32);
extern kal_uint32 cp15_read_context_id(void);
extern kal_uint32 cp15_PMU_read_control_register(void);
extern void cp15_PMU_write_control_register(kal_uint32);
extern void cp15_PMU_write_counter_enable_set(kal_uint32);
extern kal_uint32 cp15_PMU_read_counter_enable_set(void);
extern void cp15_PMU_write_counter_enable_clear(kal_uint32);
extern kal_uint32 cp15_PMU_read_counter_overflow_status(void);
extern void cp15_PMU_write_event_selection(kal_uint32, kal_uint32);
extern kal_uint32 cp15_PMU_read_cycle_counter(void);
extern void cp15_PMU_write_cycle_counter(kal_uint32);
extern kal_uint32 cp15_PMU_read_event_counter(kal_uint32);
extern void cp15_PMU_write_event_counter(kal_uint32, kal_uint32);

#endif  /* __CP15_H__ */

