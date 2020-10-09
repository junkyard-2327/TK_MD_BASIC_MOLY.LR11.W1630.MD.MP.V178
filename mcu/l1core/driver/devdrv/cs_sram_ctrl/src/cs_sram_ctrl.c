/*****************************************************************************
 *
 * Filename:
 * ---------
 *   sram_ctrl.c
 *
 * Project:
 * --------
 *   R11GX Project depend on makefile configuration
 *
 * Description:
 * ------------
 *   History for each file.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by Perforce. DO NOT MODIFY!!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by Perforce. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
**********************************************************************************************************************************************************
*[File         ]       sram_ctrl.c
*[Version      ]       v1.0
*[Revision Date]       2014-12-23
*[Author       ]       Boky Chen
*[Description  ]
*    The program is sram control related APIs implementation.
*
*[Copyright]
*    Copyright (C) 2005 MediaTek Incorporation. All Rights Reserved.
**********************************************************************************************************************************************************
*/

#include "kal_general_types.h"
#include "kal_public_api.h"
#if defined(__ENABLE_CS_SRAM_CTRL__)
//#include "cs_sram_ctrl_cs_global_defs.h"
#include "cs_sram_ctrl_global_extern.h"
//#include "cs_sram_ctrl_icc_global_defs.h"
//#include "cs_sram_ctrl_imc_global_defs.h"
//#include "cs_sram_ctrl_mmu_global_defs.h"
//#include "cs_sram_ctrl_mpc_global_defs.h"
#include "cs_sram_ctrl.h"
#include "cs_sram_ctrl_icc_defs.h"
#include "cs_sram_ctrl_cs_defs.h"
#include "cs_sram_ctrl_imc_defs.h"
#include "cs_sram_ctrl_mmu_defs.h"
#include "cs_sram_ctrl_mpc_defs.h"
#include "init_trc_api.h" 
#include "cs_sram_ctrl_local_defs.h"
#include "intrCtrl.h"

void CS_SRAM_CTRL_IsrC_Main(void); 
void ICC_SRAM_CTRL_IsrC_Main(void); 
void IMC_SRAM_CTRL_IsrC_Main(void); 
void MPC_SRAM_CTRL_IsrC_Main(void); 
void MMU_SRAM_CTRL_IsrC_Main(void); 

//#define SRAM_CTRL_MDM_EN
    #if (defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6750) || defined(MT6757) || defined(MT6750S))
    st_addr_val_mask csif_info_mask[CS_CORE_NUM]=
    {
        //ICC
        {CS_SRAM_CTRL_ICC_INFO_12       ,0x3},
        //IMC
        {CS_SRAM_CTRL_IMC_INFO_14       ,0x3},
        //MPC
        {CS_SRAM_CTRL_MPC_INFO_5        ,0x3},
    };
    
    st_addr_val_mask csif_rd_cfg_mask[CS_CORE_NUM]=
    {
        //ICC
        {CS_SRAM_CTRL_ICC_RD_CFG_12     ,0xF},
        //IMC
        {CS_SRAM_CTRL_IMC_RD_CFG_14     ,0xF},
        //MPC
        {CS_SRAM_CTRL_MPC_RD_CFG_5      ,0xF},
    };
    
    st_addr_val_mask csif_mtcmos_off_info_mask[CS_CORE_NUM]=
    {
        //ICC
        {CS_SRAM_CTRL_ICC_INFO_12       ,0xC},
        //IMC
        {CS_SRAM_CTRL_IMC_INFO_14       ,0xC},
        //MPC
        {CS_SRAM_CTRL_MPC_INFO_5        ,0xC},
    };
    
    st_addr_val_mask pm_icm_info_mask[CS_CORE_NUM][3]=
    {
        //ICC
        {
            {CS_SRAM_CTRL_ICC_INFO_12   ,0x33333330},
            {CS_SRAM_CTRL_ICC_INFO_13   ,0x33333333},
            {CS_SRAM_CTRL_ICC_INFO_14   ,0x03333333},
        },
        //IMC
        {
            {CS_SRAM_CTRL_IMC_INFO_14   ,0x33333330},
            {CS_SRAM_CTRL_IMC_INFO_15   ,0x03303303},
            {CS_SRAM_CTRL_IMC_INFO_16   ,0x00000033},
        },
        //MPC
        {
            {CS_SRAM_CTRL_MPC_INFO_5    ,0x30333330},
            {CS_SRAM_CTRL_MPC_INFO_6    ,0x00003030},
            {0                          ,0         },
        },
    };
    
    st_addr_val_mask pm_icm_mtcmos_off_info_mask[CS_CORE_NUM][3]=
    {
        //ICC
        {
            {CS_SRAM_CTRL_ICC_INFO_12   ,0xCCCCCCC0},
            {CS_SRAM_CTRL_ICC_INFO_13   ,0xCCCCCCCC},
            {CS_SRAM_CTRL_ICC_INFO_14   ,0x0CCCCCCC},
        },
        //IMC
        {
            {CS_SRAM_CTRL_IMC_INFO_14   ,0xCCCCCCC0},
            {CS_SRAM_CTRL_IMC_INFO_15   ,0x0CC0CC0C},
            {CS_SRAM_CTRL_IMC_INFO_16   ,0x000000CC},
        },
        //MPC
        {
            {CS_SRAM_CTRL_MPC_INFO_5    ,0xC0CCCCC0},
            {CS_SRAM_CTRL_MPC_INFO_6    ,0x0000C0C0},
            {0                          ,0         },
        },
    };
    
    st_addr_val_mask pm_icm_rd_cfg_mask[CS_CORE_NUM][3]=
    {
        //ICC
        {
            {CS_SRAM_CTRL_ICC_RD_CFG_12   ,0xFFFFFFF0},
            {CS_SRAM_CTRL_ICC_RD_CFG_13   ,0xFFFFFFFF},
            {CS_SRAM_CTRL_ICC_RD_CFG_14   ,0x0FFFFFFF},
        },
        //IMC
        {
            {CS_SRAM_CTRL_IMC_RD_CFG_14   ,0xFFFFFFF0},
            {CS_SRAM_CTRL_IMC_RD_CFG_15   ,0x0FF0FF0F},
            {CS_SRAM_CTRL_IMC_RD_CFG_16   ,0x000000FF},
        },
        //MPC
        {
            {CS_SRAM_CTRL_MPC_RD_CFG_5    ,0xF0FFFFF0},
            {CS_SRAM_CTRL_MPC_RD_CFG_6    ,0x0000F0F0},
            {0                            ,0         },
        },
    };
    
    st_addr_val_mask ddl_pm_info_mask[CS_CORE_NUM][2]=
    {
        //ICC
        {
            {0                          ,0         },
            {0                          ,0         },
        },
        //IMC
        {
            {CS_SRAM_CTRL_IMC_INFO_15   ,0x30030030},
            {CS_SRAM_CTRL_IMC_INFO_16   ,0x00000300},
        },
        //MPC
        {
            {CS_SRAM_CTRL_MPC_INFO_5    ,0x03000000},
            {CS_SRAM_CTRL_MPC_INFO_6    ,0x00030303},
        },
    };
    
    st_addr_val_mask ddl_pm_mtcmos_off_info_mask[CS_CORE_NUM][2]=
    {
        //ICC
        {
            {0                          ,0         },
            {0                          ,0         },
        },
        //IMC
        {
            {CS_SRAM_CTRL_IMC_INFO_15   ,0xC00C00C0},
            {CS_SRAM_CTRL_IMC_INFO_16   ,0x00000C00},
        },
        //MPC
        {
            {CS_SRAM_CTRL_MPC_INFO_5    ,0x0C000000},
            {CS_SRAM_CTRL_MPC_INFO_6    ,0x000C0C0C},
        },
    };
    
    st_addr_val_mask ddl_pm_rd_cfg_mask[CS_CORE_NUM][2]=
    {
        //ICC
        {
            {0                          ,0         },
            {0                          ,0         },
        },
        //IMC
        {
            {CS_SRAM_CTRL_IMC_RD_CFG_15 ,0xF00F00F0},
            {CS_SRAM_CTRL_IMC_RD_CFG_16 ,0x00000F00},
        },
        //MPC
        {
            {CS_SRAM_CTRL_MPC_RD_CFG_5  ,0x0F000000},
            {CS_SRAM_CTRL_MPC_RD_CFG_6  ,0x000F0F0F},
        },
    };
    
    st_ctrl_stat ctrl_stat[CS_CORE_NUM]=
    {
        //ICC
        {CS_SRAM_CTRL_ICC_CTRL_0        ,CS_SRAM_CTRL_ICC_STATUS_0},
        //IMC
        {CS_SRAM_CTRL_IMC_CTRL_0        ,CS_SRAM_CTRL_IMC_STATUS_0},
        //MPC
        {CS_SRAM_CTRL_MPC_CTRL_0        ,CS_SRAM_CTRL_MPC_STATUS_0},    
    };
    #else
        #error "unsupported chip!!!"
    #endif
st_ctrl_rxtdb_main_info cs_sram_ctrl_rxtdb_main_info[CS_SRAM_RXTDB_GROUP_END] ={
    #undef CS_SRAM_CTRL_ICC_CSIF_REG
    #undef CS_SRAM_CTRL_IMC_CSIF_REG
    #undef CS_SRAM_CTRL_IMP_CSIF_REG
    #undef CS_SRAM_CTRL_ICC_PMICM_REG
    #undef CS_SRAM_CTRL_IMC_PMICM_REG
    #undef CS_SRAM_CTRL_MPC_PMICM_REG
    #undef CS_SRAM_CTRL_IMC_DDLPM_REG
    #undef CS_SRAM_CTRL_MPC_DDLPM_REG
    #undef CS_SRAM_CTRL_RXTDB_REG
    #undef CS_SRAM_CTRL_RXDMP_REG

    #define CS_SRAM_CTRL_ICC_CSIF_REG(power_on_init_state, power_down_init_state) 
    #define CS_SRAM_CTRL_IMC_CSIF_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_MPC_CSIF_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_ICC_PMICM_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_IMC_PMICM_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_MPC_PMICM_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_IMC_DDLPM_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_MPC_DDLPM_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_RXDMP_REG(group_name, err_detect_id, sw_or_hw_ctrl, power_on_init_state, power_down_init_state) 
    #define CS_SRAM_CTRL_RXTDB_REG(group_name, err_detect_id, sw_or_hw_ctrl, power_on_init_state, power_down_init_state) \
    {\
        (power_on_init_state),(power_down_init_state),(err_detect_id),(sw_or_hw_ctrl)\
    },

    #include "cs_sram_ctrl_register.h"
    #undef CS_SRAM_CTRL_ICC_CSIF_REG
    #undef CS_SRAM_CTRL_IMC_CSIF_REG
    #undef CS_SRAM_CTRL_IMP_CSIF_REG
    #undef CS_SRAM_CTRL_ICC_PMICM_REG
    #undef CS_SRAM_CTRL_IMC_PMICM_REG
    #undef CS_SRAM_CTRL_MPC_PMICM_REG
    #undef CS_SRAM_CTRL_IMC_DDLPM_REG
    #undef CS_SRAM_CTRL_MPC_DDLPM_REG
    #undef CS_SRAM_CTRL_RXTDB_REG
    #undef CS_SRAM_CTRL_RXDMP_REG
};
st_ctrl_rxdmp_main_info cs_sram_ctrl_rxdmp_main_info[CS_SRAM_RXDMP_GROUP_END] ={
    #undef CS_SRAM_CTRL_ICC_CSIF_REG
    #undef CS_SRAM_CTRL_IMC_CSIF_REG
    #undef CS_SRAM_CTRL_IMP_CSIF_REG
    #undef CS_SRAM_CTRL_ICC_PMICM_REG
    #undef CS_SRAM_CTRL_IMC_PMICM_REG
    #undef CS_SRAM_CTRL_MPC_PMICM_REG
    #undef CS_SRAM_CTRL_IMC_DDLPM_REG
    #undef CS_SRAM_CTRL_MPC_DDLPM_REG
    #undef CS_SRAM_CTRL_RXTDB_REG
    #undef CS_SRAM_CTRL_RXDMP_REG

    #define CS_SRAM_CTRL_ICC_CSIF_REG(power_on_init_state, power_down_init_state) 
    #define CS_SRAM_CTRL_IMC_CSIF_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_MPC_CSIF_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_ICC_PMICM_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_IMC_PMICM_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_MPC_PMICM_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_IMC_DDLPM_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_MPC_DDLPM_REG(power_on_init_state, power_down_init_state)
    #define CS_SRAM_CTRL_RXTDB_REG(group_name, err_detect_id, sw_or_hw_ctrl, power_on_init_state, power_down_init_state)  
    #define CS_SRAM_CTRL_RXDMP_REG(group_name, err_detect_id, sw_or_hw_ctrl, power_on_init_state, power_down_init_state) \
    {\
        (power_on_init_state),(power_down_init_state),(err_detect_id),(sw_or_hw_ctrl)\
    },
    #include "cs_sram_ctrl_register.h"
    
    #undef CS_SRAM_CTRL_ICC_CSIF_REG
    #undef CS_SRAM_CTRL_IMC_CSIF_REG
    #undef CS_SRAM_CTRL_IMP_CSIF_REG
    #undef CS_SRAM_CTRL_ICC_PMICM_REG
    #undef CS_SRAM_CTRL_IMC_PMICM_REG
    #undef CS_SRAM_CTRL_MPC_PMICM_REG
    #undef CS_SRAM_CTRL_IMC_DDLPM_REG
    #undef CS_SRAM_CTRL_MPC_DDLPM_REG
    #undef CS_SRAM_CTRL_RXTDB_REG
    #undef CS_SRAM_CTRL_RXDMP_REG
};

void set_sram_ctrl_init_value(void){
    kal_uint32 index, counter, buffer, sram_ctrl_info_base;
    kal_uint32 tmp_stat, tmp_ctrl;
    //pm/icm/csif part
    set_cur_pic_pwr_stat(CS_ICC, CS_CSIF, CS_SRAM_CTRL_ICC_CSIF_ON_INIT);
    set_cur_pic_pwr_stat(CS_IMC, CS_CSIF, CS_SRAM_CTRL_IMC_CSIF_ON_INIT);
    set_cur_pic_pwr_stat(CS_MPC, CS_CSIF, CS_SRAM_CTRL_MPC_CSIF_ON_INIT);
    set_mtcmos_off_pic_pwr_stat(CS_ICC, CS_CSIF, CS_SRAM_CTRL_ICC_CSIF_OF_INIT);
    set_mtcmos_off_pic_pwr_stat(CS_IMC, CS_CSIF, CS_SRAM_CTRL_IMC_CSIF_OF_INIT);
    set_mtcmos_off_pic_pwr_stat(CS_MPC, CS_CSIF, CS_SRAM_CTRL_MPC_CSIF_OF_INIT);

    set_cur_pic_pwr_stat(CS_ICC, CS_PM_ICM, CS_SRAM_CTRL_ICC_PMICM_ON_INIT);
    set_cur_pic_pwr_stat(CS_IMC, CS_PM_ICM, CS_SRAM_CTRL_IMC_PMICM_ON_INIT);
    set_cur_pic_pwr_stat(CS_MPC, CS_PM_ICM, CS_SRAM_CTRL_MPC_PMICM_ON_INIT);
    set_mtcmos_off_pic_pwr_stat(CS_ICC, CS_PM_ICM, CS_SRAM_CTRL_ICC_PMICM_OF_INIT);
    set_mtcmos_off_pic_pwr_stat(CS_IMC, CS_PM_ICM, CS_SRAM_CTRL_IMC_PMICM_OF_INIT);
    set_mtcmos_off_pic_pwr_stat(CS_MPC, CS_PM_ICM, CS_SRAM_CTRL_MPC_PMICM_OF_INIT);

    set_cur_pic_pwr_stat(CS_IMC, CS_DDL_PM, CS_SRAM_CTRL_IMC_DDLPM_ON_INIT);
    set_cur_pic_pwr_stat(CS_MPC, CS_DDL_PM, CS_SRAM_CTRL_MPC_DDLPM_ON_INIT);
    set_mtcmos_off_pic_pwr_stat(CS_IMC, CS_DDL_PM, CS_SRAM_CTRL_IMC_DDLPM_OF_INIT);
    set_mtcmos_off_pic_pwr_stat(CS_MPC, CS_DDL_PM, CS_SRAM_CTRL_MPC_DDLPM_OF_INIT);

    sram_ctrl_info_base = CS_SRAM_CTRL_RXTDB_INFO_0;
    for(index = 0, counter = 0, buffer = 0; index < CS_SRAM_RXTDB_GROUP_END; index ++ ){
        if(cs_sram_ctrl_rxtdb_main_info[index].sram_owner == SRAM_HW_CTRL){ //keep init value
            buffer |=
            (SRAM_CTRL_ReadReg32(sram_ctrl_info_base)&(0xF<< (counter *4)) );
        }
        else{
            buffer |=
            (((cs_sram_ctrl_rxtdb_main_info[index].init_on_state)|(cs_sram_ctrl_rxtdb_main_info[index].init_of_state << 2)) << (counter *4));
        }
        counter ++;
        if(counter == 8){
            SRAM_CTRL_WriteReg32(sram_ctrl_info_base,buffer);
            sram_ctrl_info_base+=4;
            counter = 0;
            buffer= 0;
        }
    }
    if(counter != 0){
        SRAM_CTRL_WriteReg32(sram_ctrl_info_base,buffer);
    }
    // trigger slow dynamic
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_IMC_CTRL_0,SRAM_CTRL_TDB_TRIG_SLOW);
    do{
        tmp_stat=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_IMC_STATUS_0);
    }while(SRAM_CTRL_FSM_IDLE!=(tmp_stat&SRAM_CTRL_TDB_FSM_MASK));
    // clear slow dynamic 
    tmp_ctrl=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_IMC_CTRL_0);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_IMC_CTRL_0,tmp_ctrl&~SRAM_CTRL_TDB_TRIG_SLOW);

    sram_ctrl_info_base = CS_SRAM_CTRL_RXDMP_INFO_0;
    for(index = 0, counter = 0, buffer = 0; index < CS_SRAM_RXDMP_GROUP_END; index ++ ){
        if(cs_sram_ctrl_rxdmp_main_info[index].sram_owner == SRAM_HW_CTRL){
            buffer |=
            (SRAM_CTRL_ReadReg32(sram_ctrl_info_base)&(0xF << (counter *4)) );
        }
        else{
            buffer |=
            (((cs_sram_ctrl_rxdmp_main_info[index].init_on_state)|(cs_sram_ctrl_rxdmp_main_info[index].init_of_state << 2)) << (counter *4));
        }
        counter ++;
        if(counter == 8){
            SRAM_CTRL_WriteReg32(sram_ctrl_info_base,buffer);
            sram_ctrl_info_base+=4;
            counter = 0;
            buffer= 0;
        }
    }
    if(counter != 0){
        SRAM_CTRL_WriteReg32(sram_ctrl_info_base,buffer);
    }
    // trigger slow dynamic
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MMU_CTRL_0,SRAM_CTRL_TDB_TRIG_SLOW);
    do{
        tmp_stat=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_MMU_STATUS_0);
    }while(SRAM_CTRL_FSM_IDLE!=(tmp_stat&SRAM_CTRL_TDB_FSM_MASK));
    // clear slow dynamic 
    tmp_ctrl=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_MMU_CTRL_0);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MMU_CTRL_0,tmp_ctrl&~SRAM_CTRL_TDB_TRIG_SLOW);
}

void cs_sram_ctrl_init(void)
{

    //register error interrupt
    IRQ_Register_LISR(IRQ_ICC_SRAM_CTRL_CODE, ICC_SRAM_CTRL_IsrC_Main, "ICC SRAM CTRL LISR");
    IRQ_Register_LISR(IRQ_IMC_SRAM_CTRL_CODE, IMC_SRAM_CTRL_IsrC_Main, "IMC SRAM CTRL LISR");
    IRQ_Register_LISR(IRQ_MPC_SRAM_CTRL_CODE, MPC_SRAM_CTRL_IsrC_Main, "MPC SRAM CTRL LISR");
    IRQ_Register_LISR(IRQ_MMU_SRAM_CTRL_CODE, MMU_SRAM_CTRL_IsrC_Main, "MMU SRAM CTRL LISR");
    IRQ_Register_LISR(IRQ_CS_SRAM_CTRL_CODE, CS_SRAM_CTRL_IsrC_Main, "CS SRAM CTRL LISR");
    
    IRQSensitivity(IRQ_ICC_SRAM_CTRL_CODE, LEVEL_SENSITIVE);
    IRQSensitivity(IRQ_IMC_SRAM_CTRL_CODE, LEVEL_SENSITIVE);
    IRQSensitivity(IRQ_MPC_SRAM_CTRL_CODE, LEVEL_SENSITIVE);
    IRQSensitivity(IRQ_MMU_SRAM_CTRL_CODE, LEVEL_SENSITIVE);
    IRQSensitivity(IRQ_CS_SRAM_CTRL_CODE, LEVEL_SENSITIVE);

    //clear irq flag 
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_CS_EIRQ_STS, 0x7);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_ICC_EIRQ_STS, 0x7);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_IMC_EIRQ_STS, 0x7);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MPC_EIRQ_STS, 0x7);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MMU_EIRQ_STS, 0x7);
    //enable irq
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_CS_EIRQ_EN, 0x7);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_ICC_EIRQ_EN, 0x7);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_IMC_EIRQ_EN, 0x7);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MPC_EIRQ_EN, 0x7);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MMU_EIRQ_EN, 0x7);


    IRQUnmask(IRQ_ICC_SRAM_CTRL_CODE);
    IRQUnmask(IRQ_IMC_SRAM_CTRL_CODE);
    IRQUnmask(IRQ_MPC_SRAM_CTRL_CODE);
    IRQUnmask(IRQ_MMU_SRAM_CTRL_CODE);
    IRQUnmask(IRQ_CS_SRAM_CTRL_CODE);

    //set CTRL_5=0 (all_sram_on_trig&sram_on_mode=0) for all MTCMOS domain
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_ICC_CTRL_5,0);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_IMC_CTRL_5,0);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MPC_CTRL_5,0);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_CS_CTRL_5,0);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MMU_CTRL_5,0);
    
    //set CTRL_6 (which srams are controlled by CR4/DSP) for all MTCMOS domain 
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_ICC_CTRL_6,6);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_IMC_CTRL_6,6);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MPC_CTRL_6,6);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_CS_CTRL_6,6);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MMU_CTRL_6,6);    

    set_sram_ctrl_init_value();

    cs_sram_tiny_init(CS_IMC);
    cs_sram_tiny_init(CS_MMU);
}

//[TODO] add a API for give/get PM/ICM controlship to QDC (CTRL_9)

void set_cur_pic_pwr_stat(en_cs_core cs_core, en_pic_sram_type pic_sram_type, en_sram_pwr_stat pwr_stat)
{
    kal_uint32 info_idx=0;
    kal_uint32 rd_cfg_idx=0;
    kal_uint32 tmp_info=0;
    kal_uint32 tmp_rd_cfg=0;
    kal_uint32 info_ptn=0;
    kal_uint32 rd_cfg_ptn=0;
    kal_uint32 tmp_stat=0,tmp_ctrl=0;
    kal_uint32 backup_block_status = 0;

    // disable interrupt
    backup_block_status = SaveAndSetIRQMask();
    
    if((CS_ICC==cs_core) && (CS_DDL_PM==pic_sram_type))
    {
        #if defined(SRAM_CTRL_MDM_EN)
            MDM_INT32_WRITE(0xFFFFFF23)
            MDM_INT32_WRITE(cs_core)
            MDM_INT32_WRITE(pic_sram_type)
            MDM_INT32_WRITE(pwr_stat)
        #else
            EXT_ASSERT(0, cs_core, pic_sram_type, pwr_stat);
        #endif
    }

    switch(pwr_stat)
    {
        case SRAM_PWR_ON:
        {
            info_ptn=0;
            rd_cfg_ptn=0x33333333;
            break;
        }
        case SRAM_PWR_DWN:
        {
            info_ptn=0x11111111;
            rd_cfg_ptn=0xAAAAAAAA;
            break;
        }
        case SRAM_PWR_SLP:
        {
            info_ptn=0x22222222;
            rd_cfg_ptn=0;
            break;
        }
        default:
        {
            #if defined(SRAM_CTRL_MDM_EN)
                MDM_INT32_WRITE(0xFFFFFF22)
                MDM_INT32_WRITE(cs_core)
                MDM_INT32_WRITE(pic_sram_type)
                MDM_INT32_WRITE(pwr_stat)
            #else
                EXT_ASSERT(0, cs_core, pic_sram_type, pwr_stat);
            #endif    
            break;
        }
    }

    switch(pic_sram_type)
    {
        case CS_CSIF:
        {
            tmp_info=SRAM_CTRL_ReadReg32(csif_info_mask[cs_core].reg_addr)&~csif_info_mask[cs_core].reg_value_mask;
            tmp_info|=(info_ptn&csif_info_mask[cs_core].reg_value_mask);
            SRAM_CTRL_WriteReg32(csif_info_mask[cs_core].reg_addr,tmp_info);
            break;
        }
        case CS_PM_ICM:
        {
            for(info_idx=0;info_idx<3;info_idx++)
            {
                if(0!=pm_icm_info_mask[cs_core][info_idx].reg_addr)
                {    
                    tmp_info=SRAM_CTRL_ReadReg32(pm_icm_info_mask[cs_core][info_idx].reg_addr)&~pm_icm_info_mask[cs_core][info_idx].reg_value_mask;
                    tmp_info|=(info_ptn&pm_icm_info_mask[cs_core][info_idx].reg_value_mask);
                    SRAM_CTRL_WriteReg32(pm_icm_info_mask[cs_core][info_idx].reg_addr,tmp_info);
                }
            }
            break;
        }
        case CS_DDL_PM:
        {            
            for(info_idx=0;info_idx<2;info_idx++)
            {
                if(0!=ddl_pm_info_mask[cs_core][info_idx].reg_addr)
                {    
                    tmp_info=SRAM_CTRL_ReadReg32(ddl_pm_info_mask[cs_core][info_idx].reg_addr)&~ddl_pm_info_mask[cs_core][info_idx].reg_value_mask;
                    tmp_info|=(info_ptn&ddl_pm_info_mask[cs_core][info_idx].reg_value_mask);
                    SRAM_CTRL_WriteReg32(ddl_pm_info_mask[cs_core][info_idx].reg_addr,tmp_info);
                }
            }
            break;
        }
        default:
        {
            #if defined(SRAM_CTRL_MDM_EN)
                MDM_INT32_WRITE(0xFFFFFF21)
                MDM_INT32_WRITE(cs_core)
                MDM_INT32_WRITE(pic_sram_type)
                MDM_INT32_WRITE(pwr_stat)
            #else
                EXT_ASSERT(0, cs_core, pic_sram_type, pwr_stat);
            #endif
            break;
        }
    }
    
    // trigger slow dynamic
    SRAM_CTRL_WriteReg32(ctrl_stat[cs_core].reg_ctrl,SRAM_CTRL_CR4_TRIG_SLOW);
    do{
        tmp_stat=SRAM_CTRL_ReadReg32(ctrl_stat[cs_core].reg_stat);
    }while(SRAM_CTRL_FSM_IDLE!=(tmp_stat&SRAM_CTRL_CR4_FSM_MASK));

    // clear slow dynamic 
    tmp_ctrl=SRAM_CTRL_ReadReg32(ctrl_stat[cs_core].reg_ctrl);
    SRAM_CTRL_WriteReg32(ctrl_stat[cs_core].reg_ctrl,tmp_ctrl&~SRAM_CTRL_CR4_TRIG_SLOW);
    
    // get current power stat
    switch(pic_sram_type)
    {
        case CS_CSIF:
        {
            tmp_rd_cfg=SRAM_CTRL_ReadReg32(csif_rd_cfg_mask[cs_core].reg_addr);
            
            if((rd_cfg_ptn&csif_rd_cfg_mask[cs_core].reg_value_mask) != (tmp_rd_cfg&csif_rd_cfg_mask[cs_core].reg_value_mask))
            {
                #if defined(SRAM_CTRL_MDM_EN)
                        MDM_INT32_WRITE(0xFFFFFF20)
                            MDM_INT32_WRITE(cs_core)
                            MDM_INT32_WRITE(tmp_rd_cfg)
                            MDM_INT32_WRITE(rd_cfg_ptn)
                            MDM_INT32_WRITE(pwr_stat)
                #else
                    EXT_ASSERT(0, cs_core, tmp_rd_cfg, pwr_stat);
                #endif    
            }    

            break;
        }
        case CS_PM_ICM:
        {
            for(rd_cfg_idx=0;rd_cfg_idx<3;rd_cfg_idx++)
            {
                if(0!=pm_icm_rd_cfg_mask[cs_core][rd_cfg_idx].reg_addr)
                {    
                    tmp_rd_cfg=SRAM_CTRL_ReadReg32(pm_icm_rd_cfg_mask[cs_core][rd_cfg_idx].reg_addr);
                    
                    if((rd_cfg_ptn&pm_icm_rd_cfg_mask[cs_core][rd_cfg_idx].reg_value_mask) != (tmp_rd_cfg&pm_icm_rd_cfg_mask[cs_core][rd_cfg_idx].reg_value_mask))
                    {
                        #if defined(SRAM_CTRL_MDM_EN)
                            MDM_INT32_WRITE(0xFFFFFF19)
                            MDM_INT32_WRITE(cs_core)
                            MDM_INT32_WRITE(tmp_rd_cfg)
                            MDM_INT32_WRITE(rd_cfg_ptn)
                            MDM_INT32_WRITE(pwr_stat)
                        #else
                            EXT_ASSERT(0, cs_core, tmp_rd_cfg, pwr_stat);
                        #endif
                    } 
                }
            }
            break;
        }
        case CS_DDL_PM:
        {            
            for(rd_cfg_idx=0;rd_cfg_idx<2;rd_cfg_idx++)
            {
                if(0!=ddl_pm_rd_cfg_mask[cs_core][rd_cfg_idx].reg_addr)
                {    
                    tmp_rd_cfg=SRAM_CTRL_ReadReg32(ddl_pm_rd_cfg_mask[cs_core][rd_cfg_idx].reg_addr);
                    
                    if((rd_cfg_ptn&ddl_pm_rd_cfg_mask[cs_core][rd_cfg_idx].reg_value_mask) != (tmp_rd_cfg&ddl_pm_rd_cfg_mask[cs_core][rd_cfg_idx].reg_value_mask))
                    {
                        #if defined(SRAM_CTRL_MDM_EN)
                            MDM_INT32_WRITE(0xFFFFFF18)
                            MDM_INT32_WRITE(cs_core)
                            MDM_INT32_WRITE(tmp_rd_cfg)
                            MDM_INT32_WRITE(rd_cfg_ptn)
                            MDM_INT32_WRITE(pwr_stat)
                        #else
                            EXT_ASSERT(0, cs_core, tmp_rd_cfg, pwr_stat);
                        #endif
                    } 
                }
            }
            break;
        }
        default:
        {
            #if defined(SRAM_CTRL_MDM_EN)
                MDM_INT32_WRITE(0xFFFFFF17)
                MDM_INT32_WRITE(cs_core)
                MDM_INT32_WRITE(pic_sram_type)
                MDM_INT32_WRITE(pwr_stat)
            #else
                EXT_ASSERT(0, cs_core, pic_sram_type, pwr_stat);
            #endif
            break;                
        }    
    }
    // enable interrupt
    RestoreIRQMask(backup_block_status);

}

en_sram_pwr_stat get_cur_pic_pwr_stat(en_cs_core cs_core, en_pic_sram_type pic_sram_type)
{
    kal_uint32 tmp_rd_cfg=0;
    en_sram_pwr_stat sram_power_stat=0;

    if((CS_ICC==cs_core) && (CS_DDL_PM==pic_sram_type))
    {
        #if defined(SRAM_CTRL_MDM_EN)
            MDM_INT32_WRITE(0xFFFFFF16)
            MDM_INT32_WRITE(cs_core)
            MDM_INT32_WRITE(pic_sram_type)
        #else
            EXT_ASSERT(0, cs_core, pic_sram_type, 0);
        #endif
    }

    switch(pic_sram_type)
    {
        case CS_CSIF:
        {
            tmp_rd_cfg=SRAM_CTRL_ReadReg32(csif_rd_cfg_mask[cs_core].reg_addr);
            tmp_rd_cfg&=0xF;
            break;
        }
        case CS_PM_ICM:
        {
            tmp_rd_cfg=SRAM_CTRL_ReadReg32(pm_icm_rd_cfg_mask[cs_core][0].reg_addr);
            tmp_rd_cfg=(tmp_rd_cfg>>4)&0xF;
            break;
        }
        case CS_DDL_PM:
        {
            tmp_rd_cfg=SRAM_CTRL_ReadReg32(ddl_pm_rd_cfg_mask[cs_core][1].reg_addr);
            tmp_rd_cfg=(tmp_rd_cfg>>8)&0xF;
            break;
        }
        default:
        {
            #if defined(SRAM_CTRL_MDM_EN)
                MDM_INT32_WRITE(0xFFFFFF15)
                MDM_INT32_WRITE(cs_core)
                MDM_INT32_WRITE(pic_sram_type)
            #else
                EXT_ASSERT(0, cs_core, pic_sram_type, 0);
            #endif    
            break;                
        }    
    }
    
    switch(tmp_rd_cfg)
    {
        case SRAM_RD_PWR_ON:
        {
            sram_power_stat=SRAM_PWR_ON;
            break;
        }
        case SRAM_RD_PWR_DWN:
        {
            sram_power_stat=SRAM_PWR_DWN;
            break;
        }
        case SRAM_RD_PWR_SLP:
        {
            sram_power_stat=SRAM_PWR_SLP;
            break;
        }
        default:
        {
            #if defined(SRAM_CTRL_MDM_EN)
                MDM_INT32_WRITE(0xFFFFFF14)
                MDM_INT32_WRITE(cs_core)
                MDM_INT32_WRITE(pic_sram_type)
                MDM_INT32_WRITE(tmp_rd_cfg)
            #else
                EXT_ASSERT(0, cs_core, pic_sram_type, tmp_rd_cfg);
            #endif    
            break;
        }
    }
    return sram_power_stat;
}


void set_mtcmos_off_pic_pwr_stat(en_cs_core cs_core, en_pic_sram_type pic_sram_type, en_sram_pwr_stat pwr_stat)
{
    kal_uint32 info_idx=0;
    kal_uint32 tmp_info=0;
    kal_uint32 info_ptn=0;
    kal_uint32 backup_block_status = 0;

    // disable interrupt
    backup_block_status = SaveAndSetIRQMask();

    if((CS_ICC==cs_core) && (CS_DDL_PM==pic_sram_type))
    {
        #if defined(SRAM_CTRL_MDM_EN)
            MDM_INT32_WRITE(0xFFFFFF13)
            MDM_INT32_WRITE(cs_core)
            MDM_INT32_WRITE(pic_sram_type)
            MDM_INT32_WRITE(pwr_stat)
        #else
            EXT_ASSERT(0, cs_core, pic_sram_type, pwr_stat);
        #endif    
    }

    switch(pwr_stat)
    {
        case SRAM_PWR_ON:
        {
            info_ptn=0;
            break;
        }
        case SRAM_PWR_DWN:
        {
            info_ptn=0x44444444;
            break;
        }
        case SRAM_PWR_SLP:
        {
            info_ptn=0x88888888;
            break;
        }
        default:
        {
            #if defined(SRAM_CTRL_MDM_EN)
                MDM_INT32_WRITE(0xFFFFFF12)
                MDM_INT32_WRITE(cs_core)
                MDM_INT32_WRITE(pic_sram_type)
                MDM_INT32_WRITE(pwr_stat)
            #else
                EXT_ASSERT(0, cs_core, pic_sram_type, pwr_stat);
            #endif    
            break;
        }
    }

    switch(pic_sram_type)
    {
        //[TODO] CSIF static???
        case CS_CSIF:
        {
            tmp_info=SRAM_CTRL_ReadReg32(csif_mtcmos_off_info_mask[cs_core].reg_addr)&~csif_mtcmos_off_info_mask[cs_core].reg_value_mask;
            tmp_info|=(info_ptn&csif_mtcmos_off_info_mask[cs_core].reg_value_mask);
            SRAM_CTRL_WriteReg32(csif_mtcmos_off_info_mask[cs_core].reg_addr,tmp_info);
            break;
        }
        case CS_PM_ICM:
        {
            for(info_idx=0;info_idx<3;info_idx++)
            {
                if(0!=pm_icm_mtcmos_off_info_mask[cs_core][info_idx].reg_addr)
                {    
                    tmp_info=SRAM_CTRL_ReadReg32(pm_icm_mtcmos_off_info_mask[cs_core][info_idx].reg_addr)&~pm_icm_mtcmos_off_info_mask[cs_core][info_idx].reg_value_mask;
                    tmp_info|=(info_ptn&pm_icm_mtcmos_off_info_mask[cs_core][info_idx].reg_value_mask);
                    SRAM_CTRL_WriteReg32(pm_icm_mtcmos_off_info_mask[cs_core][info_idx].reg_addr,tmp_info);
                }
            }
            break;
        }
        case CS_DDL_PM:
        {            
            for(info_idx=0;info_idx<2;info_idx++)
            {
                if(0!=ddl_pm_mtcmos_off_info_mask[cs_core][info_idx].reg_addr)
                {
                    tmp_info=SRAM_CTRL_ReadReg32(ddl_pm_mtcmos_off_info_mask[cs_core][info_idx].reg_addr)&~ddl_pm_mtcmos_off_info_mask[cs_core][info_idx].reg_value_mask;
                    tmp_info|=(info_ptn&ddl_pm_mtcmos_off_info_mask[cs_core][info_idx].reg_value_mask);
                    SRAM_CTRL_WriteReg32(ddl_pm_mtcmos_off_info_mask[cs_core][info_idx].reg_addr,tmp_info);
                }
            }
            break;
        }
        default:
        {
            #if defined(SRAM_CTRL_MDM_EN)
                MDM_INT32_WRITE(0xFFFFFF11)
                MDM_INT32_WRITE(cs_core)
                MDM_INT32_WRITE(pic_sram_type)
                MDM_INT32_WRITE(pwr_stat)
            #else
                EXT_ASSERT(0, cs_core, pic_sram_type, pwr_stat);
            #endif
            break;
        }
    }    
    RestoreIRQMask(backup_block_status);
}

en_sram_pwr_stat get_mtcmos_off_pic_pwr_stat(en_cs_core cs_core, en_pic_sram_type pic_sram_type)
{
    en_sram_pwr_stat sram_power_stat=0;

    if((CS_ICC==cs_core) && (CS_DDL_PM==pic_sram_type))
    {
        #if defined(SRAM_CTRL_MDM_EN)
            MDM_INT32_WRITE(0xFFFFFF10)
            MDM_INT32_WRITE(cs_core)
            MDM_INT32_WRITE(pic_sram_type)
        #else
            EXT_ASSERT(0, cs_core, pic_sram_type, 0);
        #endif    
    }

    switch(pic_sram_type)
    {
        case CS_CSIF:
        {
            sram_power_stat=((SRAM_CTRL_ReadReg32(csif_mtcmos_off_info_mask[cs_core].reg_addr)&csif_mtcmos_off_info_mask[cs_core].reg_value_mask)>>2)&0x3;
            break;
        }
        case CS_PM_ICM:
        {
            sram_power_stat=((SRAM_CTRL_ReadReg32(pm_icm_mtcmos_off_info_mask[cs_core][0].reg_addr)&pm_icm_mtcmos_off_info_mask[cs_core][0].reg_value_mask)>>6)&0x3;
            break;
        }
        case CS_DDL_PM:
        {
            sram_power_stat=((SRAM_CTRL_ReadReg32(ddl_pm_mtcmos_off_info_mask[cs_core][1].reg_addr)&ddl_pm_mtcmos_off_info_mask[cs_core][1].reg_value_mask)>>10)&0x3;
            break;
        }
        default:
        {
            #if defined(SRAM_CTRL_MDM_EN)
                    MDM_INT32_WRITE(0xFFFFFF09)
                    MDM_INT32_WRITE(cs_core)
                    MDM_INT32_WRITE(pic_sram_type)
            #else
                EXT_ASSERT(0, cs_core, pic_sram_type, 0);
            #endif
            break;                
        }    
    }
    return sram_power_stat;    
}


void set_cur_rxtdb_pwr_stat(kal_uint32 rxtdb_bmap)
{
    kal_uint32 tmp_stat, tmp_ctrl;
    kal_uint32 bmap_idx;
    kal_uint32 rxtdb_info[3];
    kal_uint32 rxtdb_rd_cfg[3];
    kal_uint32 rb_rxtdb_rd_cfg[3];
    kal_uint32 rxtdb_info_idx=0;
    kal_uint32 rxtdb_rd_cfg_idx=0;
    kal_uint32 rxtdb_buffer = 0;
    kal_uint32 rxtdb_buffer_bak = 0;
    kal_uint32 backup_block_status = 0;

    cs_sram_check_error_enable(CS_IMC);

    //[TODO] disable interrupt
    backup_block_status = SaveAndSetIRQMask();

    // [TODO] it can be disabled by compile option for code size saving, it should enabled in development stage
    if(0!=(rxtdb_bmap&~SRAM_CTRL_RXTDB_BMAP_MASK))
    {
        #if defined(SRAM_CTRL_MDM_EN)
            MDM_INT32_WRITE(0xFFFFFF08)
            MDM_INT32_WRITE(SRAM_CTRL_RXTDB_BMAP_MASK)
            MDM_INT32_WRITE(rxtdb_bmap)
        #else
            EXT_ASSERT(0, SRAM_CTRL_RXTDB_BMAP_MASK, rxtdb_bmap, 0);
        #endif
    }
    
    // get original value of rxtdb_info
    for(rxtdb_info_idx=0;rxtdb_info_idx<3;rxtdb_info_idx++)
    {
        rxtdb_info[rxtdb_info_idx]=(SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_RXTDB_INFO_0+(rxtdb_info_idx*4))&(~SRAM_CTRL_RXTDB_MTCMOS_ON_MASK));
        //[TODO] why no region init
        rxtdb_rd_cfg[rxtdb_info_idx]=0;
    }

    // prepare rxtdb_info for write
    for(bmap_idx=0,rxtdb_info_idx=0,rxtdb_rd_cfg_idx=0;bmap_idx<SRAM_CTRL_RXTDB_NUM;bmap_idx++)
    {
        //if(SRAM_PWR_DWN==((rxtdb_bmap>>bmap_idx)&0x1)) senck
        if(0==((rxtdb_bmap>>bmap_idx)&0x1))
        {
            #if (!defined(TK6291)) //disable TK6291 because hw bug
            if((SRAM_PWR_DWN<<((bmap_idx*SRAM_CTRL_INFO_RD_CFG_OFFST)%SRAM_CTRL_REG_WIDTH)) 
                    != (rxtdb_info[rxtdb_info_idx]& (0x3<<(bmap_idx*SRAM_CTRL_INFO_RD_CFG_OFFST)%SRAM_CTRL_REG_WIDTH)) ){
                rxtdb_buffer |= (1<<cs_sram_ctrl_rxtdb_main_info[bmap_idx].err_detect_id);
            }
            #endif
            rxtdb_info[rxtdb_info_idx] |= (SRAM_PWR_DWN<<((bmap_idx*SRAM_CTRL_INFO_RD_CFG_OFFST)%SRAM_CTRL_REG_WIDTH));
            rxtdb_rd_cfg[rxtdb_rd_cfg_idx] |= (SRAM_RD_PWR_DWN<<((bmap_idx*SRAM_CTRL_INFO_RD_CFG_OFFST)%SRAM_CTRL_REG_WIDTH));
        }
        else
        {
            #if (!defined(TK6291)) //disable because hw bug
            if((SRAM_PWR_ON<<((bmap_idx*SRAM_CTRL_INFO_RD_CFG_OFFST)%SRAM_CTRL_REG_WIDTH)) 
                    != (rxtdb_info[rxtdb_info_idx]& (0x3<<(bmap_idx*SRAM_CTRL_INFO_RD_CFG_OFFST)%SRAM_CTRL_REG_WIDTH)) ){
                rxtdb_buffer |= (1<<cs_sram_ctrl_rxtdb_main_info[bmap_idx].err_detect_id);
            }
            #endif
            rxtdb_rd_cfg[rxtdb_rd_cfg_idx] |= (SRAM_RD_PWR_ON<<((bmap_idx*SRAM_CTRL_INFO_RD_CFG_OFFST)%SRAM_CTRL_REG_WIDTH));
        }
        if(7==(bmap_idx%(SRAM_CTRL_REG_WIDTH/SRAM_CTRL_INFO_RD_CFG_OFFST)))
        {
            rxtdb_info_idx++;
            rxtdb_rd_cfg_idx++;
        }    
         
    }

    // write rxtdb_info
    for(rxtdb_info_idx=0;rxtdb_info_idx<3;rxtdb_info_idx++)
    {
        SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_RXTDB_INFO_0+(rxtdb_info_idx*4),rxtdb_info[rxtdb_info_idx]);
    }

    SRAM_CTRL_WriteReg32(SRAM_CTRL_C2CRF_ENABLE, 0x1);
    rxtdb_buffer_bak = SRAM_CTRL_ReadReg32(SRAM_CTRL_RXTDB_ERR_ENBALE);
    #if defined(TK6291)
    rxtdb_buffer |= (0x80000000);
    #endif
    //SRAM_CTRL_WriteReg32(SRAM_CTRL_RXTDB_ERR_ENBALE, rxtdb_buffer);
    SRAM_CTRL_WriteReg32(SRAM_CTRL_RXTDB_ERR_ENBALE, (rxtdb_buffer|rxtdb_buffer_bak));

    // trigger slow dynamic
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_IMC_CTRL_0,SRAM_CTRL_TDB_TRIG_SLOW);
    do{
        tmp_stat=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_IMC_STATUS_0);
    }while(SRAM_CTRL_FSM_IDLE!=(tmp_stat&SRAM_CTRL_TDB_FSM_MASK));
    
    // clear slow dynamic 
    tmp_ctrl=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_IMC_CTRL_0);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_IMC_CTRL_0,tmp_ctrl&~SRAM_CTRL_TDB_TRIG_SLOW);

    //SRAM_CTRL_WriteReg32(SRAM_CTRL_RXTDB_ERR_ENBALE, 0);
    //SRAM_CTRL_WriteReg32(SRAM_CTRL_RXTDB_ERR_ENBALE, ((~rxtdb_buffer)&SRAM_CTRL_ReadReg32(SRAM_CTRL_RXTDB_ERR_ENBALE)) );
    SRAM_CTRL_WriteReg32(SRAM_CTRL_RXTDB_ERR_ENBALE, (rxtdb_buffer_bak));
    SRAM_CTRL_WriteReg32(SRAM_CTRL_C2CRF_ENABLE, 0x0);
    
    // get current power state
    // [TODO] it can be disabled by compile option for code size saving, it should enabled in development stage
    for(rxtdb_rd_cfg_idx=0;rxtdb_rd_cfg_idx<3;rxtdb_rd_cfg_idx++)
    {
        rb_rxtdb_rd_cfg[rxtdb_rd_cfg_idx]=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_RXTDB_RD_CFG_0+rxtdb_rd_cfg_idx*4);
        if(rb_rxtdb_rd_cfg[rxtdb_rd_cfg_idx] != rxtdb_rd_cfg[rxtdb_rd_cfg_idx])
        {
            #if defined(SRAM_CTRL_MDM_EN)
                MDM_INT32_WRITE(0xFFFFFF07)
                MDM_INT32_WRITE(rb_rxtdb_rd_cfg[rxtdb_rd_cfg_idx])
                MDM_INT32_WRITE(rxtdb_rd_cfg[rxtdb_rd_cfg_idx])
                MDM_INT32_WRITE(rxtdb_rd_cfg_idx)
            #else
                EXT_ASSERT(0, rb_rxtdb_rd_cfg[rxtdb_rd_cfg_idx], rxtdb_rd_cfg[rxtdb_rd_cfg_idx], rxtdb_rd_cfg_idx);
            #endif    
        }    
    }
    
    //[TODO] enable interrupt
    RestoreIRQMask(backup_block_status);
}

kal_uint32 get_cur_rxtdb_pwr_stat(void)
{
    kal_uint32 rxtdb_rd_cfg_idx=0;
    kal_uint32 rxtdb_bmap=0;
    kal_uint32 rxtdb_rd_cfg=0;
    kal_uint32 bmap_idx=0;
    kal_uint32 idx=0;
    
    for(rxtdb_rd_cfg_idx=0;rxtdb_rd_cfg_idx<3;rxtdb_rd_cfg_idx++)
    {
        rxtdb_rd_cfg=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_RXTDB_RD_CFG_0+(rxtdb_rd_cfg_idx*4));
        
        for(idx=0;idx<8;idx++,bmap_idx++)
        {
            //if(SRAM_RD_PWR_DWN==((rxtdb_rd_cfg>>(idx*4))&0xF)) senck
            if(SRAM_RD_PWR_ON==((rxtdb_rd_cfg>>(idx*4))&0xF))
            {
                //rxtdb_bmap|=SRAM_PWR_DWN<<bmap_idx; senck
                rxtdb_bmap|=1<<bmap_idx;
            }
            //else if(SRAM_RD_PWR_ON!=((rxtdb_rd_cfg>>(idx*4))&0xF)) senck
            else if(SRAM_RD_PWR_DWN!=((rxtdb_rd_cfg>>(idx*4))&0xF))
            {
                if((2==rxtdb_rd_cfg_idx)&&(6<=idx))
                {
                }
                else
                {        
                    #if defined(SRAM_CTRL_MDM_EN)
                        MDM_INT32_WRITE(0xFFFFFF06)
                        MDM_INT32_WRITE(rxtdb_rd_cfg)
                        MDM_INT32_WRITE(idx)
                    #else
                        EXT_ASSERT(0, rxtdb_rd_cfg, idx, 0);
                    #endif
                }
            }
        }
    }
    return rxtdb_bmap;
}

void set_cur_rxdmp_pwr_stat(kal_uint32 rxdmp_bmap)
{
    kal_uint32 tmp_stat=0;
    kal_uint32 tmp_ctrl=0;
    kal_uint32 tmp_info=0;
    kal_uint32 tmp_rd_cfg=0;
    kal_uint32 rxdmp_buffer = 0;
    kal_uint32 backup_block_status = 0;

    cs_sram_check_error_enable(CS_MMU);
    // disable interrupt
    backup_block_status = SaveAndSetIRQMask();
    
    
    tmp_info=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_RXDMP_INFO_0)&~0x3;

    //[TODO] remember do not corrupt mtcmos off region
    //if(SRAM_PWR_ON==(rxdmp_bmap&0x1)) senck
    if( 1 ==(rxdmp_bmap&0x1))
    {
        SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_RXDMP_INFO_0,tmp_info|SRAM_PWR_ON);
    }
    //else if(SRAM_PWR_DWN==(rxdmp_bmap&0x1))
    else if( 0 ==(rxdmp_bmap&0x1))
    {
        SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_RXDMP_INFO_0,tmp_info|SRAM_PWR_DWN);
    }
    else
    {
        #if defined(SRAM_CTRL_MDM_EN)
            MDM_INT32_WRITE(0xFFFFFF05)
            MDM_INT32_WRITE(rxdmp_bmap)
        #else
            EXT_ASSERT(0, rxdmp_bmap, 0, 0);
        #endif    
    }
    rxdmp_buffer |= (1<<cs_sram_ctrl_rxdmp_main_info[0].err_detect_id);

    //SRAM_CTRL_WriteReg32(SRAM_CTRL_RXDMP_ERR_ENABLE, rxdmp_buffer);
    SRAM_CTRL_WriteReg32(SRAM_CTRL_RXDMP_ERR_ENABLE, (rxdmp_buffer|SRAM_CTRL_ReadReg32(SRAM_CTRL_RXDMP_ERR_ENABLE)) );
    
    // trigger slow dynamic
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MMU_CTRL_0,SRAM_CTRL_TDB_TRIG_SLOW);
    do{
        tmp_stat=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_MMU_STATUS_0);
    }while(SRAM_CTRL_FSM_IDLE!=(tmp_stat&SRAM_CTRL_TDB_FSM_MASK));

    // clear slow dynamic 
    tmp_ctrl=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_MMU_CTRL_0);
    SRAM_CTRL_WriteReg32(CS_SRAM_CTRL_MMU_CTRL_0,tmp_ctrl&~SRAM_CTRL_TDB_TRIG_SLOW);

    SRAM_CTRL_WriteReg32(SRAM_CTRL_RXDMP_ERR_ENABLE, ((~rxdmp_buffer)&SRAM_CTRL_ReadReg32(SRAM_CTRL_RXDMP_ERR_ENABLE)));

    tmp_rd_cfg=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_RXDMP_RD_CFG_0);
    
    //if(SRAM_PWR_ON==(rxdmp_bmap&0x1)) senck
    if( 1 ==(rxdmp_bmap&0x1))
    {
        if(SRAM_RD_PWR_ON!=(tmp_rd_cfg&0xF))
        {
            #if defined(SRAM_CTRL_MDM_EN)
                MDM_INT32_WRITE(0xFFFFFF28)
                MDM_INT32_WRITE(tmp_rd_cfg&0xF)
            #else
                EXT_ASSERT(0, rxdmp_bmap, 0, 0);
            #endif
        }    
    }
    else
    {
        if(SRAM_RD_PWR_DWN!=(tmp_rd_cfg&0xF))
        {
            #if defined(SRAM_CTRL_MDM_EN)
                MDM_INT32_WRITE(0xFFFFFF29)
                MDM_INT32_WRITE(tmp_rd_cfg&0xF)
            #else
                EXT_ASSERT(0, rxdmp_bmap, 0, 0);
            #endif
        }         
    }     
    
    // enable interrupt
    RestoreIRQMask(backup_block_status);
}

kal_uint32 get_cur_rxdmp_pwr_stat(void)
{
    kal_uint32 rxdmp_rd_cfg=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_RXDMP_RD_CFG_0)&0xF;
    
    if(SRAM_RD_PWR_ON==rxdmp_rd_cfg)
    {
        return SRAM_PWR_ON;    
    }
    else if(SRAM_RD_PWR_DWN==rxdmp_rd_cfg)
    {
        return SRAM_PWR_DWN;
    }
    else
    {
        #if defined(SRAM_CTRL_MDM_EN)
            MDM_INT32_WRITE(0xFFFFFF24)
            MDM_INT32_WRITE(rxdmp_rd_cfg)
        #else
            EXT_ASSERT(0, rxdmp_rd_cfg, 0, 0);
        #endif    
    }
    return 0;
}

void cs_sram_tiny_init_ICC(void){

}

void cs_sram_tiny_init(en_cs_core cs_core){
#if !defined(TK6291)
    volatile kal_uint32 temp_buffer = 0;
    switch(cs_core){
        case CS_ICC: 
            break;
        case CS_IMC: 
            SRAM_CTRL_WriteReg32(SRAM_CTRL_C2CRF_ENABLE, 0x1);
            SRAM_CTRL_WriteReg32(SRAM_CTRL_RXTDB_QDC_CG, SRAM_CTRL_RXTDB_QDC_CG_MASK);
            //polling the complete signal
            while(1){
                temp_buffer = SRAM_CTRL_ReadReg32(SRAM_CTRL_RXTDB_QDC_CG_CMP);
                if( (temp_buffer & SRAM_CTRL_RXTDB_QDC_CG_CMP_MASK) == SRAM_CTRL_RXTDB_QDC_CG_CMP_MASK ){
                    break;
                }
            }
            SRAM_CTRL_WriteReg32(SRAM_CTRL_RXTDB_ERR_ENBALE, 0x0);
            SRAM_CTRL_WriteReg32(SRAM_CTRL_RXTDB_ERR_CTRL, 0x4);
            SRAM_CTRL_WriteReg32(SRAM_CTRL_C2CRF_ENABLE, 0x0);
            break;
        case CS_MPC: 
            break;
        case CS_MMU: 
            SRAM_CTRL_WriteReg32(SRAM_CTRL_RXDMP_ERR_ENABLE, 0x0);
            SRAM_CTRL_WriteReg32(SRAM_CTRL_RXDMP_ERR_CTRL, 0x4);
            break;
        default:
            ASSERT(0);
            break;
    }
#endif
}

void cs_sram_check_error_enable(en_cs_core cs_core){
#if !defined(TK6291)
    volatile kal_uint32 temp_buffer;
    switch(cs_core){
        case CS_ICC: 
            break;
        case CS_IMC: 
            SRAM_CTRL_WriteReg32(SRAM_CTRL_C2CRF_ENABLE, 0x1);
            temp_buffer = SRAM_CTRL_ReadReg32(SRAM_CTRL_RXTDB_ERR_CTRL);
            if((temp_buffer&0x4) != 0x4 ){
                ASSERT(0);
            }
            SRAM_CTRL_WriteReg32(SRAM_CTRL_C2CRF_ENABLE, 0x0);
            break;
        case CS_MPC: 
            break;
        case CS_MMU: 
            temp_buffer = SRAM_CTRL_ReadReg32(SRAM_CTRL_RXDMP_ERR_CTRL);
            if((temp_buffer&0x4) != 0x4 ){
                ASSERT(0);
            }
            break;
        default:
            ASSERT(0);
            break;
    }
#endif
}

void CS_SRAM_CTRL_IsrC_Main(void){
    kal_uint32 temp0, temp1, temp2;
    temp0=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_CS_EIRQ_EN);
    temp1=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_CS_EIRQ_STS);
    temp2=0; 
    EXT_ASSERT(0, temp0, temp1, temp2);
}
void ICC_SRAM_CTRL_IsrC_Main(void){
    kal_uint32 temp0, temp1, temp2;
    temp0=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_ICC_EIRQ_EN);
    temp1=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_ICC_EIRQ_STS);
    temp2=0; 
    EXT_ASSERT(0, temp0, temp1, temp2);
}
void IMC_SRAM_CTRL_IsrC_Main(void){
    kal_uint32 temp0, temp1, temp2;
    temp0=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_IMC_EIRQ_EN);
    temp1=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_IMC_EIRQ_STS);
    temp2=0; 
    EXT_ASSERT(0, temp0, temp1, temp2);
}
void MPC_SRAM_CTRL_IsrC_Main(void){
    kal_uint32 temp0, temp1, temp2;
    temp0=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_MPC_EIRQ_EN);
    temp1=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_MPC_EIRQ_STS);
    temp2=0; 
    EXT_ASSERT(0, temp0, temp1, temp2);
}
void MMU_SRAM_CTRL_IsrC_Main(void){
    kal_uint32 temp0, temp1, temp2;
    temp0=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_MMU_EIRQ_EN);
    temp1=SRAM_CTRL_ReadReg32(CS_SRAM_CTRL_MMU_EIRQ_STS);
    temp2=0; 
    EXT_ASSERT(0, temp0, temp1, temp2);
}
#endif

void CS_SRAM_CTRL_ICC_ERROR(void){
    EXT_ASSERT(0, 0, 0, 0);
}
void CS_SRAM_CTRL_IMC_ERROR(void){
    kal_uint32 temp0,temp1;
    temp0 = 0;
    temp1 = 0;
    #if defined(__ENABLE_CS_SRAM_CTRL__)
    SRAM_CTRL_WriteReg32(SRAM_CTRL_C2CRF_ENABLE, 0x1);
    temp0 = SRAM_CTRL_ReadReg32(SRAM_CTRL_RXTDB_ERR_FLAG);
    temp1 = SRAM_CTRL_ReadReg32(SRAM_CTRL_RXTDB_ERR_FLAG+4);
    SRAM_CTRL_WriteReg32(SRAM_CTRL_C2CRF_ENABLE, 0x0);
    #endif
    EXT_ASSERT(0, 1, temp0, temp1);
}
void CS_SRAM_CTRL_MPC_ERROR(void){
    EXT_ASSERT(0, 2, 0, 0);
}
void CS_SRAM_CTRL_MMU_ERROR(void){
    kal_uint32 temp0;
    temp0 = 0;
    #if defined(__ENABLE_CS_SRAM_CTRL__)
    temp0 = SRAM_CTRL_ReadReg32(SRAM_CTRL_RXDMP_ERR_FLAG);
    #endif
    EXT_ASSERT(0, 3, temp0, 0);
}

