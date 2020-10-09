#ifndef __CS_SRAM_CTRL_LOCAL_DEFS_H__
#define __CS_SRAM_CTRL_LOCAL_DEFS_H__
#include "cs_sram_ctrl_global_extern.h"
#include "reg_base.h"

#if (defined(TK6291))
    typedef enum{
        rxtdb_g0_1_cm_sram_active = 14,
        rxtdb_g2_3_4_cm_sram_active,
        rxtdb_g5_cm_sram_active,
        rxtdb_g6_7_cm_sram_active,
        rxtdb_g8_9_10_cm_sram_active,
        rxtdb_g0_test_sram_active,
        rxtdb_g0_1_rx_sram_active,
        rxtdb_g2_3_rx_sram_active,
        rxtdb_g9_rx_sram_active,
        rxtdb_g4_5_rx_sram_active,
        rxtdb_g6_7_rx_sram_active,
        rxtdb_g8_rx_sram_active,
        cs_sram_no_error_enable_tdb
    }en_sram_ctrl_err_en_rxtdb;
    
    typedef enum{
        rxdmp_ext_sram_active=0,
        cs_sram_no_error_enable_bmp
    }en_sram_ctrl_err_en_rxdmp;

    #define SRAM_CTRL_C2CRF_ENABLE (L1_BASE_MADDR_IMC_DSPBTDMA + 0x34)
    #define SRAM_CTRL_RXTDB_ERR_ENBALE (L1_BASE_MADDR_IMC_C2CRF + (4780*4))
    #define SRAM_CTRL_RXDMP_ERR_ENABLE ((L1_BASE_MADDR_MMUSYS_MMU_MON)+12)
#elif (defined(MT6755) || defined(MT6797) || defined(MT6750) || defined(MT6757) || defined(MT6750S))
    typedef enum{
        rxtdb_g0_1_cm_sram_active = 9,
        rxtdb_g2_3_4_cm_sram_active,
        rxtdb_g5_cm_sram_active,
        rxtdb_g6_7_cm_sram_active,
        rxtdb_g8_9_10_cm_sram_active,
        rxtdb_g0_test_sram_active,
        rxtdb_g0_1_rx_sram_active,
        rxtdb_g2_3_rx_sram_active,
        rxtdb_g9_rx_sram_active,
        rxtdb_g4_5_rx_sram_active,
        rxtdb_g6_7_rx_sram_active,
        rxtdb_g8_rx_sram_active,
        cs_sram_no_error_enable_tdb
    }en_sram_ctrl_err_en_rxtdb;
    
    typedef enum{
        rxdmp_ext_sram_active=0,
        cs_sram_no_error_enable_bmp
    }en_sram_ctrl_err_en_rxdmp;

    #define SRAM_CTRL_C2CRF_ENABLE (L1_BASE_MADDR_IMC_DSPBTDMA + 0x34)
    #define SRAM_CTRL_RXTDB_QDC_CG (L1_BASE_MADDR_IMC_C2CRF + (4525*4))
    #define SRAM_CTRL_RXTDB_QDC_CG_MASK (0x10)
    #define SRAM_CTRL_RXTDB_QDC_CG_CMP (L1_BASE_MADDR_IMC_C2CRF + (4529*4))
    #define SRAM_CTRL_RXTDB_QDC_CG_CMP_MASK ((kal_uint32)(0x1 << 31))
    #define SRAM_CTRL_RXTDB_ERR_CTRL (L1_BASE_MADDR_IMC_C2CRF + (4779*4))
    #define SRAM_CTRL_RXTDB_ERR_ENBALE (L1_BASE_MADDR_IMC_C2CRF + (4782*4))
    #define SRAM_CTRL_RXTDB_ERR_FLAG    (L1_BASE_MADDR_IMC_C2CRF + (4785*4))
    #define SRAM_CTRL_RXDMP_ERR_CTRL ((L1_BASE_MADDR_MMUSYS_MMU_MON)+0)
    #define SRAM_CTRL_RXDMP_ERR_ENABLE ((L1_BASE_MADDR_MMUSYS_MMU_MON)+8)
    #define SRAM_CTRL_RXDMP_ERR_FLAG    ((L1_BASE_MADDR_MMUSYS_MMU_MON)+16)
#else
    #error "SRAM CTRL not support.."
#endif

typedef struct
{
    en_sram_pwr_stat init_on_state:3;
    en_sram_pwr_stat init_of_state:3;
    en_sram_ctrl_err_en_rxtdb err_detect_id:7;
    en_sram_owner sram_owner:2;
}st_ctrl_rxtdb_main_info;

typedef struct
{
    en_sram_pwr_stat init_on_state:3;
    en_sram_pwr_stat init_of_state:3;
    en_sram_ctrl_err_en_rxdmp err_detect_id:7;
    en_sram_owner sram_owner:2;
}st_ctrl_rxdmp_main_info;

#endif
