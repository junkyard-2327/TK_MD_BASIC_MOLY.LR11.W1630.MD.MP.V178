#ifndef __DRV_L1GDMA_H__
#define __DRV_L1GDMA_H__


typedef enum {
    GDMA_CH_LOGGING,
    GDMA_CH_00 = GDMA_CH_LOGGING,
    GDMA_CH_INTRAT,
    GDMA_CH_01 = GDMA_CH_INTRAT,
    GDMA_CH_RESERVED1,
    GDMA_CH_02 = GDMA_CH_RESERVED1,
    GDMA_CH_RESERVED2,
    GDMA_CH_03 = GDMA_CH_RESERVED2,
    GDMA_CH_MAX,
} gdma_channel_type_e;


typedef struct gdma_gpd_addr_s {
    kal_uint32 gdma_src_Gpd;
    kal_uint32 gdma_dst_Gpd;
} gdma_gpd_addr_t;


typedef enum {
    GDMA_MOD_LINKLIST,
    GDMA_MOD_BASIC,
    GDMA_MOD_DESCRIPTOR,
    GDMA_MOD_MEMSET,
} gdma_mod_e;


typedef enum {
    GDMA_BUS_WIDTH_8BITS,
    GDMA_BUS_WIDTH_16BITS,
    GDMA_BUS_WIDTH_32BITS,
    GDMA_BUS_WIDTH_MAX,
} gdma_bus_width_e;


typedef struct gdma_bus_width_s {
    gdma_bus_width_e src_bus_width;
    gdma_bus_width_e dst_bus_width;
} gdma_bus_width_t;


typedef enum {
    GDMA_PRI_HIGH,
    GDMA_PRI_MEDIAN,
    GDMA_PRI_LOW,
} gdma_priority_e;


typedef struct gdma_cfg_s {
    gdma_channel_type_e gdma_sel_channel;
    gdma_mod_e          gdma_mod;
    gdma_gpd_addr_t     gdma_gpd_addr;
    kal_uint32          gdma_mod_basic_tx_size;
    kal_uint16          gdma_other_para;
    gdma_bus_width_t    gdma_bus_width;
    gdma_priority_e     gdma_priority;
    kal_bool            gdma_bd_dat_cs_en;
    kal_bool            gdma_gpd_cs_en;
} gdma_cfg_t;


typedef enum {
    GDMA_START,
    GDMA_RESUME,
} gdma_start_cmd_type_e;


typedef enum {
    GDMA_STARTED,
    GDMA_STOP,
} gdma_status_type_e;


typedef enum {
    GDMA_SRC_DONE=0,
    GDMA_DST_DONE=4,
    GDMA_SRC_QUE_EMPTY=8,
    GDMA_DST_QUE_EMPTY=12,
    GDMA_LEN_ERR=16,
    GDMA_ALO_LEN_ERR=20,
    GDMA_BD_CS_ERR=24,
    GDMA_GPD_CS_ERR=28,
    GDMA_BD_DAT_CS_ERR=32,
    GDMA_INT_TYPE_MAX=36,
} gdma_int_type_e;


typedef struct gdma_cbType_s {
    gdma_channel_type_e     gdma_channel;
    gdma_int_type_e         gdma_int_type;
} gdma_cbType_t;


typedef struct gdma_cbParameter_s {
    gdma_int_type_e     gdma_int_type;
    gdma_gpd_addr_t     gpd_info;
} gdma_cbParameter_t;


typedef void (*gdma_pcb_f)(gdma_cbParameter_t *gpd_info);

typedef enum {
    GDMA_CB_SRC_GPD_DONE,
    GDMA_CB_DST_GPD_DONE,
    GDMA_CB_SRC_QUE_EMPTY,
    GDMA_CB_DST_QUE_EMPTY,
    GDMA_CB_LEN_ERR,
    GDMA_CB_ALO_LEN_ERR,
    GDMA_CB_GPD_CS_ERR,
    GDMA_CB_BD_CS_ERR,
    GDMA_CB_BD_DAT_CS_ERR,
    GDMA_CB_MAX,
    GDMA_CB_ERROR,
} gdma_cbType_e;


/*****************************************************************************
 *                       function declaration                                *
 *****************************************************************************/

void drv_gdma_init(void);
kal_bool drv_gdma_set_config(gdma_cfg_t *gdmaCfg_p);
kal_bool drv_gdma_start_cmd(gdma_channel_type_e chId, gdma_start_cmd_type_e cmd);
void drv_gdma_stop_cmd(gdma_channel_type_e chId);
void drv_gdma_set_priority(gdma_channel_type_e chId, gdma_priority_e priority);
void drv_gdma_get_curGPD(gdma_channel_type_e chId, gdma_gpd_addr_t *cur_gpd_addr);
gdma_status_type_e drv_gdma_get_status(gdma_channel_type_e chId);
kal_bool drv_gdma_register_callback(gdma_cbType_t *cbType, gdma_pcb_f callback);
void drv_gdma_clear_intr(gdma_channel_type_e chId);
void drv_gdma_clear_all_intr();
kal_uint8 drv_gdma_calculate_bd_chksum(void *data_ptr, kal_uint32 data_len);

void drv_gdma_lock_sleep();
void drv_gdma_unlock_sleep();

void drv_gdma_pre_start(gdma_channel_type_e chId);
void drv_gdma_post_stop(gdma_channel_type_e chId);

void drv_psgdma_pdn_clr();

#endif /* end of __DEV_L1GDMA_H__ */
