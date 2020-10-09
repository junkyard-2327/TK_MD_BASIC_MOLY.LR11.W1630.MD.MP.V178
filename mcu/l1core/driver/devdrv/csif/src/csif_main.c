/*****************************************************************************
 *
 * Filename:
 * ---------
 *   CSIF_Main.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by Perforce. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
**********************************************************************************************************************************************************
*[File         ]       CSIF_Main.c
*[Version      ]       v1.0
*[Revision Date]       2014-06-10
*[Author       ]       Peng-Chih Wang
*[Description  ]
*    The program is CSIF related APIs implementation.
*
*[Copyright]
*    Copyright (C) 2005 MediaTek Incorporation. All Rights Reserved.
**********************************************************************************************************************************************************
*/

//related header file
#include "csif_local_define.h"
#include "intrCtrl.h"
#include "drv_comm.h"

//redefine macro
#define WRITE_CR(addr, value)   DRV_WriteReg32(addr, value)
#define READ_CR(addr, value)    value=DRV_Reg32(addr)

//import variables
extern kal_uint32 pfICCCSIFFunc[ICC_CSIF_INTERRUPT_NUM];
extern kal_uint32 pfICCCSIFErrFunc[ICC_CSIF_ERR_INTERRUPT_NUM];
extern kal_uint32 pfIMCCSIFFunc[IMC_CSIF_INTERRUPT_NUM];
extern kal_uint32 pfIMCCSIFErrFunc[IMC_CSIF_ERR_INTERRUPT_NUM];
extern kal_uint32 pfMPCCSIFFunc[MPC_CSIF_INTERRUPT_NUM];
extern kal_uint32 pfMPCCSIFErrFunc[MPC_CSIF_ERR_INTERRUPT_NUM];
extern kal_uint32 pfMPCCSIFFunc[MPC_CSIF_INTERRUPT_NUM];
extern kal_uint32 pfICCCSIFRemoteCallbackFunc[ICC_CSIF_Remote_Callback_INTERRUPT_NUM];
extern kal_uint32 pfIMCCSIFRemoteCallbackFunc[IMC_CSIF_Remote_Callback_INTERRUPT_NUM];
extern kal_uint32 pfMPCCSIFRemoteCallbackFunc[MPC_CSIF_Remote_Callback_INTERRUPT_NUM];
volatile kal_uint32 icc_remote_callback_counter = 0;
volatile kal_uint32 imc_remote_callback_counter = 0;
volatile kal_uint32 mpc_remote_callback_counter = 0;
volatile kal_uint32 csif_zi_table_backup_icc_index = 0;
volatile kal_uint32 csif_zi_table_backup_imc_index = 0;
volatile kal_uint32 csif_zi_table_backup_mpc_index = 0;
volatile CSIF_ZI_Table_Backup CSIF_ZI_Table_Backup_ICC[10];
volatile CSIF_ZI_Table_Backup CSIF_ZI_Table_Backup_IMC[10];
volatile CSIF_ZI_Table_Backup CSIF_ZI_Table_Backup_MPC[10];

//prototype declaration
void CSIF_Invalid(kal_uint32 status_index);
void CSIF_Init(void);
void CSIF_ICC_IsrC_Main(void);
void CSIF_IMC_IsrC_Main(void);
void CSIF_MPC_IsrC_Main(void);
void CSIF_Error_ICC_IsrC_Main(void);
void CSIF_Error_IMC_IsrC_Main(void);
void CSIF_Error_MPC_IsrC_Main(void);
void CSIF_C2S_SWI_Set(kal_uint8 core_index, kal_uint8 code);
kal_uint32 CSIF_C2S_SWI_Read(kal_uint8 core_index);
static kal_uint32 CSIF_S2C_SWI_Read(kal_uint8 core_index);
static void CSIF_S2C_SWI_Clear(kal_uint8 core_index, kal_uint8 code);
void CSIF_S2C_SWI_Enable(kal_uint8 core_index, kal_uint32 enable_bit_map);
kal_uint32 CSIF_S2C_SWI_Enable_Read(kal_uint8 core_index);
void CSIF_Disable_WFI(kal_uint8 core_index);
kal_uint32 CSIF_ACD_S2C_Read(kal_uint8 core_index);
void CSIF_ACD_C2S_Set(kal_uint8 core_index, kal_uint8 ACD_indx);
void CSIF_ACD_C2S_Clear(kal_uint8 core_index, kal_uint8 ACD_indx);
kal_uint32 CSIF_ACD_C2S_Read(kal_uint8 core_index);
static kal_uint32 CSIF_CR4_Error_Read(kal_uint8 core_index);
static kal_uint32 CSIF_CR4_Error_Enable_Read(kal_uint8 core_index);
//static void CSIF_CR4_Error_Enable(kal_uint8 core_index, kal_uint32 error_type);
//static kal_uint32 CSIF_C2S_Overflow(kal_uint8 core_index);
void CSIF_C2S_Overflow_clear(kal_uint8 core_index, kal_uint8 code);
//static kal_uint32 CSIF_S2C_Overflow(kal_uint8 core_index);
void CSIF_S2C_Overflow_clear(kal_uint8 core_index, kal_uint8 code);
//static kal_uint32 CSIF_ACD_Conflict(kal_uint8 core_index);
void CSIF_ACD_Conflict_Clear(kal_uint8 core_index);
//static kal_uint32 CSIF_MPU_Violation_DSM_Addr(kal_uint8 core_index);
//static void CSIF_MPU_DSM_Addr_Clear(kal_uint8 core_index);
//MPU configuration will be set by Coresonic
//static void CSIF_DSP_MPU_Start_Addr(kal_uint8 core_index, kal_uint32 start_addr);
//static void CSIF_DSP_MPU_Length(kal_uint8 core_index, kal_uint32 length);
//static void CSIF_CR4_MPU_Start_Addr(kal_uint8 core_index, kal_uint32 start_addr);
//static void CSIF_CR4_MPU_Length(kal_uint8 core_index, kal_uint32 length);

extern void Exception_Bring_Up_Init_ICC(void);
extern void Exception_Bring_Up_Init_IMC(void);
extern void Exception_Bring_Up_Init_MPC(void);

//Implementation
/*
****************************************************************************************************************************
* CSIF_Invalid.
*
* This function is for CSIF default callback function
* 
* Input: corresponded CSIF interrupt status
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Invalid(kal_uint32 status_index)
{
    ASSERT(0);
}

/*
****************************************************************************************************************************
* CSIF_Init.
*
* This function is for initiate the CSIF HW/SW
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
//#define __INIT_TOPSM_FOR_INNER__

#if defined(__INIT_TOPSM_FOR_INNER__)  
#define TOPSIM_ADDR_INNER                                ((UINT32P)(0xf6070000))
#define BASE_ADDR_ICC_C2CRF_INNER                        ((0xfee00000))
#define REG_ICC_C2CRF_CR_LTEL1_CDS_TOP_CDS_VCR13_INNER   ((UINT32P)(BASE_ADDR_ICC_C2CRF_INNER+0x12f8))
#define REG_ICC_C2CRF_CR_LTEL1_CDS_TOP_CDS_DUMMY_INNER   ((UINT32P)(BASE_ADDR_ICC_C2CRF_INNER+0x12fc))
#endif
void CSIF_Init(void)
{
#if defined(__INIT_TOPSM_FOR_INNER__)  
    kal_uint32 i=0;
    volatile kal_uint32* TopSM_address = TOPSIM_ADDR_INNER;
    kal_uint32 TopSM_polling_value=0;
    volatile kal_uint32* ICC_C2CRF_address = REG_ICC_C2CRF_CR_LTEL1_CDS_TOP_CDS_VCR13_INNER;
    volatile kal_uint32* ICC_DUMMY_address = REG_ICC_C2CRF_CR_LTEL1_CDS_TOP_CDS_DUMMY_INNER;
    kal_uint32 ICC_C2CRF_polling_value=0;
    

    //(*ICC_C2CRF_address)=0x3;
    //initial TOPSM 
    for(i=0; i<19; i++)
    {
        (*TopSM_address)=0xb2000082;
        TopSM_address += 1;
    }
   
    TopSM_address = (UINT32P)0xf60700d4;
    TopSM_polling_value = (*TopSM_address);
    while(TopSM_polling_value != 0x7ffff)
    {
        TopSM_polling_value = (*TopSM_address);

    }

    //sync with testbench environment
    (*ICC_C2CRF_address)=0x1;
    ICC_C2CRF_polling_value =(*ICC_DUMMY_address);
    while((ICC_C2CRF_polling_value&0x1) != 0x1)
    {

        ICC_C2CRF_polling_value =(*ICC_DUMMY_address);
    }

#endif


    //[step1.]register LISR 
    //normal
    IRQ_Register_LISR(IRQ_CSIF_ICC_CODE, CSIF_ICC_IsrC_Main, "CSIF ICC LISR");
    IRQ_Register_LISR(IRQ_CSIF_IMC_CODE, CSIF_IMC_IsrC_Main, "CSIF IMC LISR");
    IRQ_Register_LISR(IRQ_CSIF_MPC_CODE, CSIF_MPC_IsrC_Main, "CSIF MPC LISR");
    //IRQ_Register_LISR(0, CSIF_ICC_IsrC_Main, "CSIF ICC LISR");
    //IRQ_Register_LISR(0, CSIF_IMC_IsrC_Main, "CSIF IMC LISR");
    //IRQ_Register_LISR(0, CSIF_MPC_IsrC_Main, "CSIF MPC LISR");
    //error
    //IRQ_Register_LISR(0, CSIF_Error_ICC_IsrC_Main, "CSIF ICC ERR LISR");
    //IRQ_Register_LISR(0, CSIF_Error_IMC_IsrC_Main, "CSIF IMC ERR LISR");
    //IRQ_Register_LISR(0, CSIF_Error_MPC_IsrC_Main, "CSIF MPC ERR LISR");
    IRQ_Register_LISR(IRQ_CSIF_ICC_ERR_CODE, CSIF_Error_ICC_IsrC_Main, "CSIF ICC ERR LISR");
    IRQ_Register_LISR(IRQ_CSIF_IMC_ERR_CODE, CSIF_Error_IMC_IsrC_Main, "CSIF IMC ERR LISR");
    IRQ_Register_LISR(IRQ_CSIF_MPC_ERR_CODE, CSIF_Error_MPC_IsrC_Main, "CSIF MPC ERR LISR");
    
    //[step2.] set IRQ sensitivity
    //normal
    //IRQSensitivity(0, LEVEL_SENSITIVE);
    //IRQSensitivity(0, LEVEL_SENSITIVE);
    //IRQSensitivity(0, LEVEL_SENSITIVE);
    IRQSensitivity(IRQ_CSIF_ICC_CODE, LEVEL_SENSITIVE);
    IRQSensitivity(IRQ_CSIF_IMC_CODE, LEVEL_SENSITIVE);
    IRQSensitivity(IRQ_CSIF_MPC_CODE, LEVEL_SENSITIVE);
    //error
    //IRQSensitivity(0, LEVEL_SENSITIVE);
    //IRQSensitivity(0, LEVEL_SENSITIVE);
    //IRQSensitivity(0, LEVEL_SENSITIVE);
    IRQSensitivity(IRQ_CSIF_ICC_ERR_CODE, LEVEL_SENSITIVE);
    IRQSensitivity(IRQ_CSIF_IMC_ERR_CODE, LEVEL_SENSITIVE);
    IRQSensitivity(IRQ_CSIF_MPC_ERR_CODE, LEVEL_SENSITIVE);    
    
    //[step3.] disable CSIF interrupt source & error type
    //disable CSIF interrupt source 
    WRITE_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, 0x0);
    WRITE_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, 0x0);
    WRITE_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, 0x0);
    
    //disable CR4 error type 
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    
    //[step4.] clear error interrupt (ACD, OVFL, MPU Violation) & CSIF interrupt status
    //clear ACD conflict status
    WRITE_CR(ICC_DSPCSIF_GPI_C_CLEAR, 0xFFFFFFFF);
    WRITE_CR(IMC_DSPCSIF_GPI_C_CLEAR, 0xFFFFFFFF);
    WRITE_CR(MPC_DSPCSIF_GPI_C_CLEAR, 0xFFFFFFFF);
    
    //clear C2S overflow status
    WRITE_CR(ICC_DSPCSIF_ERROR_C2S_OVFL_CLR, 0xFFFFFFFF);
    WRITE_CR(ICC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, 0x1);
    WRITE_CR(IMC_DSPCSIF_ERROR_C2S_OVFL_CLR, 0xFFFFFFFF);
    WRITE_CR(IMC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, 0x1);
    WRITE_CR(MPC_DSPCSIF_ERROR_C2S_OVFL_CLR, 0xFFFFFFFF);
    WRITE_CR(MPC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, 0x1);
    
    //clear S2C overflow status (!!make rule: the overflow should be cleaned by TX side!!)
    //WRITE_CR(ICC_DSPCSIF_ERROR_S2C_OVFL_CLR, 0xFFFFFFFF);
    //WRITE_CR(IMC_DSPCSIF_ERROR_S2C_OVFL_CLR, 0xFFFFFFFF);
    //WRITE_CR(MPC_DSPCSIF_ERROR_S2C_OVFL_CLR, 0xFFFFFFFF);
    
    //clear MPU violation address
    WRITE_CR(ICC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR_CLR, 0x1);
    WRITE_CR(IMC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR_CLR, 0x1);
    WRITE_CR(MPC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR_CLR, 0x1);
    
    //clear irq status
    WRITE_CR(ICC_DSPCSIF_S2C_IRQ_CLR, 0xFFFFFFFF);
    WRITE_CR(IMC_DSPCSIF_S2C_IRQ_CLR, 0xFFFFFFFF);
    WRITE_CR(MPC_DSPCSIF_S2C_IRQ_CLR, 0xFFFFFFFF);
    
    //[step5.] enable CSIF setting
    //set CR4 error status 
    #if defined(TK6291)//hw bug only for TK6291
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0xCF);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0xCF);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0xCF);
    #else
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0xFF);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0xFF);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0xFF);
    #endif
    
    //set irq enable status
    WRITE_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, 0xFFFFFFFE);
    WRITE_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, 0xFFFFFFFE);
    WRITE_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, 0xFFFFFFFE);
   
    //[step6.] unmask CSIF */
    //normal
    //IRQUnmask(0);
    //IRQUnmask(0);
    //IRQUnmask(0);
    IRQUnmask(IRQ_CSIF_ICC_CODE);
    IRQUnmask(IRQ_CSIF_IMC_CODE);
    IRQUnmask(IRQ_CSIF_MPC_CODE);
    //error
    //IRQUnmask(0);
    //IRQUnmask(0);
    //IRQUnmask(0);
    IRQUnmask(IRQ_CSIF_ICC_ERR_CODE);
    IRQUnmask(IRQ_CSIF_IMC_ERR_CODE);
    IRQUnmask(IRQ_CSIF_MPC_ERR_CODE);
    
    Exception_Bring_Up_Init_ICC();
    Exception_Bring_Up_Init_IMC();
    Exception_Bring_Up_Init_MPC();
}

/*
****************************************************************************************************************************
* CSIF_ICC_IsrC_Main.
*
* This function is for ICC CSIF normal interrupt entry point
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_ICC_IsrC_Main(void)
{
    kal_uint32 cr4_irq_status = 0;
    kal_uint32 cr4_irq_enable = 0;
    kal_uint32 index=0;
    PFCSIFFUNC *cb;
    cr4_irq_status = CSIF_S2C_SWI_Read(ICC_CORE);
    cr4_irq_enable = CSIF_S2C_SWI_Enable_Read(ICC_CORE);
    cb = (PFCSIFFUNC *)pfICCCSIFFunc;
    
    //[to-do-list]: add log in here to record transaction message
        
    while( index<ICC_CSIF_INTERRUPT_NUM )
    {
        if( (cr4_irq_enable & 1<<index) && (cr4_irq_status & 1<<index) )
        {
            //execute user callback function & pass interrupt corresponded bit
            (*(cb+index))(index);
            
            //clear CSIF IRQ status
            CSIF_S2C_SWI_Clear(ICC_CORE, index);
        }
        
        index++;
    }
}

/*
****************************************************************************************************************************
* CSIF_IMC_IsrC_Main.
*
* This function is for IMC CSIF normal interrupt entry point
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_IMC_IsrC_Main(void)
{
    kal_uint32 cr4_irq_status = 0;
    kal_uint32 cr4_irq_enable = 0;
    kal_uint32 index=0;
    PFCSIFFUNC *cb;
    cr4_irq_status = CSIF_S2C_SWI_Read(IMC_CORE);
    cr4_irq_enable = CSIF_S2C_SWI_Enable_Read(IMC_CORE);
    cb = (PFCSIFFUNC *)pfIMCCSIFFunc;
    
    //[to-do-list]: add log in here to record transaction message
        
    while( index<IMC_CSIF_INTERRUPT_NUM )
    {
        if( (cr4_irq_enable & 1<<index) && (cr4_irq_status & 1<<index) )
        {
            //execute user callback function & pass interrupt corresponded bit
            (*(cb+index))(index);
            
            //clear CSIF IRQ status
            CSIF_S2C_SWI_Clear(IMC_CORE, index);
        }
        
        index++;
    }
}

/*
****************************************************************************************************************************
* CSIF_MPC_IsrC_Main.
*
* This function is for MPC CSIF normal interrupt entry point
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_MPC_IsrC_Main(void)
{
    kal_uint32 cr4_irq_status = 0;
    kal_uint32 cr4_irq_enable = 0;
    kal_uint32 index=0;
    PFCSIFFUNC *cb;
    cr4_irq_status = CSIF_S2C_SWI_Read(MPC_CORE);
    cr4_irq_enable = CSIF_S2C_SWI_Enable_Read(MPC_CORE);
    cb = (PFCSIFFUNC *)pfMPCCSIFFunc;
    
    //[to-do-list]: add log in here to record transaction message
        
    while( index<MPC_CSIF_INTERRUPT_NUM )
    {
        if( (cr4_irq_enable & 1<<index) && (cr4_irq_status & 1<<index) )
        {
            //execute user callback function & pass interrupt corresponded bit
            (*(cb+index))(index);
            
            //clear CSIF IRQ status
            CSIF_S2C_SWI_Clear(MPC_CORE, index);
        }
        
        index++;
    }
}

/*
****************************************************************************************************************************
* CSIF_Error_ICC_IsrC_Main.
*
* This function is for ICC CSIF Error interrupt entry point
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Error_ICC_IsrC_Main(void)
{
    kal_uint32 cr4_error_type = 0;
    kal_uint32 cr4_error_enable = 0;
    kal_uint32 index=0;
    kal_uint32 count = 0;
    PFCSIFFUNC *cb;
    cr4_error_type = CSIF_CR4_Error_Read(ICC_CORE);
    cr4_error_enable = CSIF_CR4_Error_Enable_Read(ICC_CORE);
    cb = (PFCSIFFUNC *)pfICCCSIFErrFunc;
    
    while( index<ICC_CSIF_ERR_INTERRUPT_NUM )
    {
        if( (cr4_error_enable & 1<<index) && (cr4_error_type & 1<<index) )
        {
            //execute user error callback function & pass interrupt corresponded bit
            (*(cb+index))(index);
            count ++;
        }
        index++;
    }
    if(count == 0){
        ASSERT(0);
    }
}

/*
****************************************************************************************************************************
* CSIF_Error_IMC_IsrC_Main.
*
* This function is for IMC CSIF Error interrupt entry point
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Error_IMC_IsrC_Main(void)
{
    kal_uint32 cr4_error_type = 0;
    kal_uint32 cr4_error_enable = 0;
    kal_uint32 index=0;
    kal_uint32 count = 0;
    PFCSIFFUNC *cb;
    cr4_error_type = CSIF_CR4_Error_Read(IMC_CORE);
    cr4_error_enable = CSIF_CR4_Error_Enable_Read(IMC_CORE);
    cb = (PFCSIFFUNC *)pfIMCCSIFErrFunc;
    
    while( index<IMC_CSIF_ERR_INTERRUPT_NUM )
    {
        if( (cr4_error_enable & 1<<index) && (cr4_error_type & 1<<index) )
        {
            //execute user error callback function & pass interrupt corresponded bit
            (*(cb+index))(index);
            count ++;
        }
        index++;
    }
    if(count == 0){
        ASSERT(0);
    }
}

/*
****************************************************************************************************************************
* CSIF_Error_MPC_IsrC_Main.
*
* This function is for MPC CSIF Error interrupt entry point
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Error_MPC_IsrC_Main(void)
{
    kal_uint32 cr4_error_type = 0;
    kal_uint32 cr4_error_enable = 0;
    kal_uint32 index=0;
    kal_uint32 count = 0;
    PFCSIFFUNC *cb;
    cr4_error_type = CSIF_CR4_Error_Read(MPC_CORE);
    cr4_error_enable = CSIF_CR4_Error_Enable_Read(MPC_CORE);
    cb = (PFCSIFFUNC *)pfMPCCSIFErrFunc;
    
    while( index<MPC_CSIF_ERR_INTERRUPT_NUM )
    {
        if( (cr4_error_enable & 1<<index) && (cr4_error_type & 1<<index) )
        {
            //execute user error callback function & pass interrupt corresponded bit
            (*(cb+index))(index);
            count ++;
        }
        index++;
    }
    if(count == 0){
        ASSERT(0);
    }
}

/*
****************************************************************************************************************************
* CSIF_C2S_SWI_Set.
*
* This function is for L1Core to coresonic interrupt trigger
* 
* Input: trigger corresponded interrupt bit
* 
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_C2S_SWI_Set(kal_uint8 core_index, kal_uint8 code)
{
    //[to-do-list]: add log in here to record invalid operation
    if(CSIF_C2S_SWI_Read(core_index) & (1<<code))
    {
        ASSERT(0);
    }
    //[to-do-list]: add log in here to record transaction message
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_C2S_IRQ_SET, 0x1<<code);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_C2S_IRQ_SET, 0x1<<code);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_C2S_IRQ_SET, 0x1<<code);
            break;
        default:
            ASSERT(0);
    }
}

/*
****************************************************************************************************************************
* CSIF_C2S_SWI_Read.
*
* This function is for L1Core to coresonic interrupt status read
* 
* Input: None
* 
* Output: C2S Interrupt status
*
****************************************************************************************************************************
*/
kal_uint32 CSIF_C2S_SWI_Read(kal_uint8 core_index)
{
    kal_uint32 c2s_swi_read = 0;
    switch (core_index){
        case ICC_CORE:
            READ_CR(ICC_DSPCSIF_C2S_IRQ_READ, c2s_swi_read);
            break;
        case IMC_CORE:
            READ_CR(IMC_DSPCSIF_C2S_IRQ_READ, c2s_swi_read);
            break;
        case MPC_CORE:
            READ_CR(MPC_DSPCSIF_C2S_IRQ_READ, c2s_swi_read);
            break;
        default:
            ASSERT(0);
    }
    return c2s_swi_read;
}

/*
****************************************************************************************************************************
* CSIF_S2C_SWI_Read.
*
* This function is for coresonic to L1Core interrupt status read
* 
* Input: None
* 
* Output: S2C Interrupt status
*
****************************************************************************************************************************
*/
static kal_uint32 CSIF_S2C_SWI_Read(kal_uint8 core_index)
{
    kal_uint32 s2c_swi_read = 0;
    switch (core_index){
        case ICC_CORE:
            READ_CR(ICC_DSPCSIF_S2C_IRQ_READ, s2c_swi_read);
            break;
        case IMC_CORE:
            READ_CR(IMC_DSPCSIF_S2C_IRQ_READ, s2c_swi_read);
            break;
        case MPC_CORE:
            READ_CR(MPC_DSPCSIF_S2C_IRQ_READ, s2c_swi_read);
            break;
        default:
            ASSERT(0);
    }
    //[to-do-list]: add log in here to record invalid operation
    if(!s2c_swi_read)
    {
        ASSERT(0);
    }
    return s2c_swi_read;
}

/*
****************************************************************************************************************************
* CSIF_S2C_SWI_Clear.
*
* This function is for coresonic to L1Core interrupt status clear
* 
* Input: clear corresponded interrupt bit
* 
* Output: None
*
****************************************************************************************************************************
*/
static void CSIF_S2C_SWI_Clear(kal_uint8 core_index, kal_uint8 code)
{
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_S2C_IRQ_CLR, 0x1<<code);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_S2C_IRQ_CLR, 0x1<<code);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_S2C_IRQ_CLR, 0x1<<code);
            break;
        default:
            ASSERT(0);
    }
}

/*
****************************************************************************************************************************
* CSIF_S2C_SWI_Enable.
*
* This function is for L1Core to configure SWI enable status
* 
* Input: coresonic enable SWI status
* 
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_S2C_SWI_Enable(kal_uint8 core_index, kal_uint32 enable_bit_map)
{
    kal_uint32 backup_block_status = 0;
    backup_block_status = SaveAndSetIRQMask();
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, enable_bit_map);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, enable_bit_map);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, enable_bit_map);
            break;
        default:
            RestoreIRQMask(backup_block_status);
            ASSERT(0);
    }
    RestoreIRQMask(backup_block_status);
}

/*
****************************************************************************************************************************
* CSIF_S2C_SWI_Enable_Read.
*
* This function is for L1Core to read SWI enable status
* 
* Input: coresonic enable SWI status
* 
* Output: None
*
****************************************************************************************************************************
*/
kal_uint32 CSIF_S2C_SWI_Enable_Read(kal_uint8 core_index)
{
    kal_uint32 backup_block_status = 0;
    kal_uint32 s2c_swi_enable=0;
    backup_block_status = SaveAndSetIRQMask();
    switch (core_index){
        case ICC_CORE:
            READ_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, s2c_swi_enable);
            break;
        case IMC_CORE:
            READ_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, s2c_swi_enable);
            break;
        case MPC_CORE:
            READ_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, s2c_swi_enable);
            break;
        default:
            RestoreIRQMask(backup_block_status);
            ASSERT(0);
    }
    RestoreIRQMask(backup_block_status);
    return s2c_swi_enable;
}

/*
****************************************************************************************************************************
* CSIF_Disable_WFI.
*
* This function is for L1Core to read SWI enable status
* 
* Input: coresonic enable SWI status
* 
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Disable_WFI(kal_uint8 core_index)
{
    kal_uint32 backup_block_status = 0;
    kal_uint32 s2c_swi_enable=0;
    backup_block_status = SaveAndSetIRQMask();
    switch (core_index){
        case ICC_CORE:
            READ_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, s2c_swi_enable);
            s2c_swi_enable = s2c_swi_enable & 0xFFFFFFFE;
            WRITE_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, s2c_swi_enable);
            break;
        case IMC_CORE:
            READ_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, s2c_swi_enable);
            s2c_swi_enable = s2c_swi_enable & 0xFFFFFFFE;
            WRITE_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, s2c_swi_enable);
            break;
        case MPC_CORE:
            READ_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, s2c_swi_enable);
            s2c_swi_enable = s2c_swi_enable & 0xFFFFFFFE;
            WRITE_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, s2c_swi_enable);
            break;
        default:
            RestoreIRQMask(backup_block_status);
            ASSERT(0);
    }
    RestoreIRQMask(backup_block_status);
}

/*
****************************************************************************************************************************
* CSIF_ACD_S2C_Read.
*
* This function is for L1Core to read coresonic ACD status
* 
* Input: None
* 
* Output: coresonic ACD status
*
****************************************************************************************************************************
*/
kal_uint32 CSIF_ACD_S2C_Read(kal_uint8 core_index)
{
    kal_uint32 gpi_s_read = 0;
    switch (core_index){
        case ICC_CORE:
            READ_CR(ICC_DSPCSIF_GPI_S_READ, gpi_s_read);
            break;
        case IMC_CORE:
            READ_CR(IMC_DSPCSIF_GPI_S_READ, gpi_s_read);
            break;
        case MPC_CORE:
            READ_CR(MPC_DSPCSIF_GPI_S_READ, gpi_s_read);
            break;
        default:
            ASSERT(0);
    }
    return gpi_s_read;
}

/*
****************************************************************************************************************************
* CSIF_ACD_C2S_Set.
*
* This function is for L1Core to set L1Core ACD status
* 
* Input: occupy L1Core used ACD index
* 
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_ACD_C2S_Set(kal_uint8 core_index, kal_uint8 ACD_indx)
{
    //[to-do-list]: add log in here to record invalid operation
    if(CSIF_ACD_S2C_Read(core_index) & (1<<ACD_indx))
    {
        ASSERT(0);
    }
    //[to-do-list]: add log in here to record transaction message
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_GPI_C_SET, 0x1<<ACD_indx);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_GPI_C_SET, 0x1<<ACD_indx);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_GPI_C_SET, 0x1<<ACD_indx);
            break;
        default:
            ASSERT(0);
    }
}

/*
****************************************************************************************************************************
* CSIF_ACD_C2S_Clear.
*
* This function is for L1Core to clear L1Core ACD status
* 
* Input: free L1Core used ACD index
* 
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_ACD_C2S_Clear(kal_uint8 core_index, kal_uint8 ACD_indx)
{
    //[to-do-list]: add log in here to record invalid operation
    if(((1<<ACD_indx)&CSIF_ACD_C2S_Read(core_index)) == 0x0)
    {
        ASSERT(0);
    }
    //[to-do-list]: add log in here to record transaction message
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_GPI_C_CLEAR, 0x1<<ACD_indx);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_GPI_C_CLEAR, 0x1<<ACD_indx);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_GPI_C_CLEAR, 0x1<<ACD_indx);
            break;
        default:
            ASSERT(0);
    }
}

/*
****************************************************************************************************************************
* CSIF_ACD_C2S_Read.
*
* This function is for coresonic to read L1Core ACD status
* 
* Input: None
* 
* Output: L1Core ACD status
*
****************************************************************************************************************************
*/
kal_uint32 CSIF_ACD_C2S_Read(kal_uint8 core_index)
{
    kal_uint32 gpi_c_read = 0;
    switch (core_index){
        case ICC_CORE:
            READ_CR(ICC_DSPCSIF_GPI_C_READ, gpi_c_read);
            break;
        case IMC_CORE:
            READ_CR(IMC_DSPCSIF_GPI_C_READ, gpi_c_read);
            break;
        case MPC_CORE:
            READ_CR(MPC_DSPCSIF_GPI_C_READ, gpi_c_read);
            break;
        default:
            ASSERT(0);
    }
    return gpi_c_read;
}

/*
****************************************************************************************************************************
* CSIF_CR4_Error_Read.
*
* This function is for L1Core to read Error status
* 
* Input: None
* 
* Output: L1Core error status
*
****************************************************************************************************************************
*/
static kal_uint32 CSIF_CR4_Error_Read(kal_uint8 core_index)
{
    kal_uint32 cr4_error = 0;
    switch (core_index){
        case ICC_CORE:
            READ_CR(ICC_DSPCSIF_CR4_ERROR, cr4_error);
            break;
        case IMC_CORE:
            READ_CR(IMC_DSPCSIF_CR4_ERROR, cr4_error);
            break;
        case MPC_CORE:
            READ_CR(MPC_DSPCSIF_CR4_ERROR, cr4_error);
            break;
        default:
            ASSERT(0);
    }
    return cr4_error;
}

/*
****************************************************************************************************************************
* CSIF_CR4_Error_Enable_Read.
*
* This function is for L1Core to eable Error interrupt
* 
* Input: enable L1Core corresponded error_type
* 
* Output: None
*
****************************************************************************************************************************
*/
static kal_uint32 CSIF_CR4_Error_Enable_Read(kal_uint8 core_index)
{
    kal_uint32 backup_block_status = 0;
    kal_uint32 error_type = 0;
    backup_block_status = SaveAndSetIRQMask();
    switch (core_index){
        case ICC_CORE:
            READ_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, error_type);
            break;
        case IMC_CORE:
            READ_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, error_type);
            break;
        case MPC_CORE:
            READ_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, error_type);
            break;
        default:
            RestoreIRQMask(backup_block_status);
            ASSERT(0);
    }
    RestoreIRQMask(backup_block_status);
    return error_type;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if 0

/*
****************************************************************************************************************************
* CSIF_C2S_Overflow_clear.
*
* This function is for coresonic to clear L1Core overflow corresponded interrupt bit
* 
* Input: corresponded overflow bit
* 
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_C2S_Overflow_clear(kal_uint8 core_index, kal_uint8 code)
{
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_ERROR_C2S_OVFL_CLR, 0x1<<code);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_ERROR_C2S_OVFL_CLR, 0x1<<code);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_ERROR_C2S_OVFL_CLR, 0x1<<code);
            break;
        default:
            ASSERT(0);
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if 0

/*
****************************************************************************************************************************
* CSIF_S2C_Overflow_clear.
*
* This function is for coresonic to clear coresonic overflow corresponded interrupt bit
* 
* Input: corresponded overflow bit
* 
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_S2C_Overflow_clear(kal_uint8 core_index, kal_uint8 code)
{
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_ERROR_S2C_OVFL_CLR, 0x1<<code);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_ERROR_S2C_OVFL_CLR, 0x1<<code);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_ERROR_S2C_OVFL_CLR, 0x1<<code);
            break;
        default:
            ASSERT(0);
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if 0

/*
****************************************************************************************************************************
* CSIF_ACD_Conflict_Clear.
*
* This function is for L1Core to clear ACD conflict bit
* 
* Input: None
* 
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_ACD_Conflict_Clear(kal_uint8 core_index)
{
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, 0x1);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, 0x1);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, 0x1);
            break;
        default:
            ASSERT(0);
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if 0

void CSIF_VAS_VALID_SET(kal_uint8 core_index, kal_uint32 code){
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_VAS_VALID, code);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_VAS_VALID, code);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_VAS_VALID, code);
            break;
        default:
            ASSERT(0);
    }
}

void CSIF_VAS_ACK_SET(kal_uint8 core_index, kal_uint32 code){
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_VAS_ACK, code);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_VAS_ACK, code);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_VAS_ACK, code);
            break;
        default:
            ASSERT(0);
    }
}

void CSIF_VAS_SKIP_SET(kal_uint8 core_index, kal_uint32 code){
    switch (core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_VAS_SKIP, code);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_VAS_SKIP, code);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_VAS_SKIP, code);
            break;
        default:
            ASSERT(0);
    }

}

void CSIF_Error_Enable_Init_ICC(void)
{
    #if defined(TK6291)
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0xCF);
    #endif
    Exception_Bring_Up_Init_ICC();
}
void CSIF_Error_Enable_Init_IMC(void)
{
    #if defined(TK6291)
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0xCF);
    #endif
    Exception_Bring_Up_Init_IMC();
}
void CSIF_Error_Enable_Init_MPC(void)
{
    #if defined(TK6291)
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0xCF);
    #endif
    Exception_Bring_Up_Init_MPC();
}

#if (!defined(__CSIF_PRETEST_LOAD_ONLY__))
/*
****************************************************************************************************************************
* CSIF_Remote_Callback_ICC.
*
* This function is for ICC CSIF Remote callback mechanism
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Remote_Callback_ICC(kal_uint32 dummy)
{
    kal_uint32 index;
    PFCSIFFUNC *cb;
    if(0 != icc_remote_callback_counter){
        ASSERT(0);
    }
    icc_remote_callback_counter+=1;
    cb = (PFCSIFFUNC *)pfICCCSIFRemoteCallbackFunc;
    READ_CR(ICC_DSPCSIF_TASK_ID, index);
    if((kal_uint32)ICC_CSIF_Remote_Callback_INTERRUPT_NUM > index ){
        (*(cb+index))(ICC_CORE);
    }
    else{
        ASSERT(0);
    }
    icc_remote_callback_counter-=1;
    CSIF_C2S_SWI_Set( ICC_CORE, CSIF_ID_ICC_RemoteCallback);
}

/*
****************************************************************************************************************************
* CSIF_Remote_Callback_IMC.
*
* This function is for IMC CSIF Remote callback mechanism
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Remote_Callback_IMC(kal_uint32 dummy)
{
    kal_uint32 index;
    PFCSIFFUNC *cb;
    if(0 != imc_remote_callback_counter){
        ASSERT(0);
    }
    imc_remote_callback_counter+=1;
    cb = (PFCSIFFUNC *)pfIMCCSIFRemoteCallbackFunc;
    READ_CR(IMC_DSPCSIF_TASK_ID, index);
    if((kal_uint32)IMC_CSIF_Remote_Callback_INTERRUPT_NUM > index ){
        (*(cb+index))(IMC_CORE);
    }
    else{
        ASSERT(0);
    }
    imc_remote_callback_counter-=1;
    CSIF_C2S_SWI_Set( IMC_CORE, CSIF_ID_IMC_RemoteCallback);
}

/*
****************************************************************************************************************************
* CSIF_Remote_Callback_MPC.
*
* This function is for MPC CSIF Remote callback mechanism
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Remote_Callback_MPC(kal_uint32 dummy)
{
    kal_uint32 index;
    PFCSIFFUNC *cb;
    if(0 != mpc_remote_callback_counter){
        ASSERT(0);
    }
    mpc_remote_callback_counter+=1;
    cb = (PFCSIFFUNC *)pfMPCCSIFRemoteCallbackFunc;
    READ_CR(MPC_DSPCSIF_TASK_ID, index);
    if((kal_uint32)MPC_CSIF_Remote_Callback_INTERRUPT_NUM > index ){
        (*(cb+index))(MPC_CORE);
    }
    else{
        ASSERT(0);
    }
    mpc_remote_callback_counter-=1;    
    CSIF_C2S_SWI_Set( MPC_CORE, CSIF_ID_MPC_RemoteCallback);
}

/*
****************************************************************************************************************************
* CSIF_Remote_callback_ZI_Backup.
*
* This function is for CSIF Remote ZI table backup
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Remote_callback_ZI_Backup(kal_uint32 core_index)
{
    kal_uint32 temp;
    kal_uint32* table_pointer;
    switch(core_index){
        case ICC_CORE:
            READ_CR(ICC_DSPCSIF_VAS_VALID, CSIF_ZI_Table_Backup_ICC[csif_zi_table_backup_icc_index].zi_reason);
            READ_CR(ICC_DSPCSIF_VAS_ACK, CSIF_ZI_Table_Backup_ICC[csif_zi_table_backup_icc_index].table_start);
            table_pointer = (kal_uint32*)((CSIF_ZI_Table_Backup_ICC[csif_zi_table_backup_icc_index].table_start*4)+ICC_CSIF_DSM_BASE);
            READ_CR(ICC_DSPCSIF_VAS_SKIP, CSIF_ZI_Table_Backup_ICC[csif_zi_table_backup_icc_index].table_lengh);
            for(temp = 0; temp < CSIF_ZI_Table_Backup_ICC[csif_zi_table_backup_icc_index].table_lengh ; temp ++){
                CSIF_ZI_Table_Backup_ICC[csif_zi_table_backup_icc_index].zi_table[temp] = *(table_pointer+temp);
            }
            csif_zi_table_backup_icc_index+=1;
            csif_zi_table_backup_icc_index=csif_zi_table_backup_icc_index%10;
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0x7A49426B);
            break;
        case IMC_CORE:
            READ_CR(IMC_DSPCSIF_VAS_VALID, CSIF_ZI_Table_Backup_IMC[csif_zi_table_backup_imc_index].zi_reason);
            READ_CR(IMC_DSPCSIF_VAS_ACK, CSIF_ZI_Table_Backup_IMC[csif_zi_table_backup_imc_index].table_start);
            table_pointer = (kal_uint32*)((CSIF_ZI_Table_Backup_IMC[csif_zi_table_backup_imc_index].table_start*4)+IMC_CSIF_DSM_BASE);
            READ_CR(IMC_DSPCSIF_VAS_SKIP, CSIF_ZI_Table_Backup_IMC[csif_zi_table_backup_imc_index].table_lengh);
            for(temp = 0; temp < CSIF_ZI_Table_Backup_IMC[csif_zi_table_backup_imc_index].table_lengh ; temp ++){
                CSIF_ZI_Table_Backup_IMC[csif_zi_table_backup_imc_index].zi_table[temp] = *(table_pointer+temp);
            }
            csif_zi_table_backup_imc_index+=1;
            csif_zi_table_backup_imc_index=csif_zi_table_backup_imc_index%10;
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0x7A49426B);
            break;
        case MPC_CORE:
            READ_CR(MPC_DSPCSIF_VAS_VALID, CSIF_ZI_Table_Backup_MPC[csif_zi_table_backup_mpc_index].zi_reason);
            READ_CR(MPC_DSPCSIF_VAS_ACK, CSIF_ZI_Table_Backup_MPC[csif_zi_table_backup_mpc_index].table_start);
            table_pointer = (kal_uint32*)((CSIF_ZI_Table_Backup_MPC[csif_zi_table_backup_mpc_index].table_start*4)+MPC_CSIF_DSM_BASE);
            READ_CR(MPC_DSPCSIF_VAS_SKIP, CSIF_ZI_Table_Backup_MPC[csif_zi_table_backup_mpc_index].table_lengh);
            for(temp = 0; temp < CSIF_ZI_Table_Backup_MPC[csif_zi_table_backup_mpc_index].table_lengh ; temp ++){
                CSIF_ZI_Table_Backup_MPC[csif_zi_table_backup_mpc_index].zi_table[temp] = *(table_pointer+temp);
            }
            csif_zi_table_backup_mpc_index+=1;
            csif_zi_table_backup_mpc_index=csif_zi_table_backup_mpc_index%10;
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0x7A49426B);
            break;
        default:
            ASSERT(0);
            break;
    }
}
#endif
