#ifndef __DRV_L1GDMA_H__
#define __DRV_L1GDMA_H__

#include "drv_gdma.h"

typedef enum {
    L1GDMA_CH_00,
    L1GDMA_CH_LOGGING = L1GDMA_CH_00,
    L1GDMA_CH_01,
    L1GDMA_CH_02,
    L1GDMA_CH_03,
    L1GDMA_CH_EX_COPY = L1GDMA_CH_03,
    L1GDMA_CH_MAX,
} l1gdma_channel_type_e;

typedef gdma_gpd_addr_t l1gdma_gpd_addr_t;


typedef gdma_mod_e l1gdma_mod_e;


typedef gdma_bus_width_e l1gdma_bus_width_e;


typedef gdma_bus_width_t l1gdma_bus_width_t;


typedef enum {
    GDMA_PRI_HIGH,
    GDMA_PRI_MEDIAN,
    GDMA_PRI_LOW,
} l1gdma_priority_e;

typedef gdma_cfg_t l1gdma_cfg_t;


typedef gdma_start_cmd_type_e l1gdma_start_cmd_type_e;


typedef gdma_status_type_e l1gdma_status_type_e;


typedef gdma_int_type_e l1gdma_int_type_e;


typedef gdma_cbType_t l1gdma_cbType_t;


typedef gdma_cbParameter_t l1gdma_cbParameter_t;


typedef void (*l1gdma_pcb_f)(l1gdma_cbParameter_t *gpd_info);

typedef gdma_cbType_e l1gdma_cbType_e;


/*****************************************************************************
 *                       function declaration                                *
 *****************************************************************************/
kal_bool drv_l1gdma_ex_init(void);
kal_bool drv_l1gdma_set_config(l1gdma_cfg_t *gdmaCfg_p);
kal_bool drv_l1gdma_start_cmd(l1gdma_channel_type_e chId, l1gdma_start_cmd_type_e cmd);
void drv_l1gdma_stop_cmd(l1gdma_channel_type_e chId);
void drv_l1gdma_clear_status(l1gdma_channel_type_e chId);
void drv_l1gdma_set_priority(l1gdma_channel_type_e chId, l1gdma_priority_e priority);
void drv_l1gdma_get_curGPD(l1gdma_channel_type_e chId, l1gdma_gpd_addr_t *cur_gpd_addr);
l1gdma_status_type_e drv_l1gdma_get_status(l1gdma_channel_type_e chId);

#endif /* end of __DEV_L1GDMA_H__ */
