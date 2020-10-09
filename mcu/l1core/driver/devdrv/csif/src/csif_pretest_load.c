/*****************************************************************************
 *
 * Filename:
 * ---------
 *   CSIF_PRETEST_MAIN.c
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
*[File         ]       CSIF_PRETEST_MAIN.c
*[Version      ]       v1.0
*[Revision Date]       2014-06-18
*[Author       ]       Peng-Chih Wang
*[Description  ]
*    The program is CSIF related APIs implementation.
*
*[Copyright]
*    Copyright (C) 2005 MediaTek Incorporation. All Rights Reserved.
**********************************************************************************************************************************************************
*/

//related header file
#include "csif_global_extern.h"
#include "intrCtrl.h"
#include "drv_comm.h"
//#include "mdm.h"

//redefine macro
#define WRITE_CR(addr, value)   DRV_WriteReg32(addr, value)
#define READ_CR(addr, value)    value=DRV_Reg32(addr)

//PC: open the define when interrupt is ready
#define IT_WITH_DSP
//#define CSIF_TIME_OUT
#define CSIF_HW_TEST
//#define CSIF_API_TEST
//#define CSIF_SYNC_TEST
//prototype declaration
void CSIF_PreTest(void);
void CSIF_Interrupt_Test(void);
void CSIF_Interrupt_Handler(kal_uint32 status_index);
#if defined(CSIF_HW_TEST)
static void CSIF_SSDVT_TEST(void);
#endif
#if defined(CSIF_API_TEST)
static void CSIF_DRIVER_TEST(void);
#endif

//Implementation
volatile kal_uint32 csif_pretest_case = 0;
#if defined(CSIF_TIME_OUT)
volatile kal_uint32 csif_time_out = 0;
#endif

//case0
#define SRAM_PATTERN_ARRAY 4
volatile kal_uint32 csif_debug_sram_pattern_index=0;
volatile kal_uint32 csif_debug_sram_pattern[SRAM_PATTERN_ARRAY]={0x0, 0xFFFFFFFF, 0x5a5a5a5a, 0xa5a5a5a5};
volatile kal_uint32* csif_debug_icc_sram_addr = (kal_uint32*)ICC_CSIF_DSM_BASE;
volatile kal_uint32* csif_debug_imc_sram_addr = (kal_uint32*)IMC_CSIF_DSM_BASE;
volatile kal_uint32* csif_debug_mpc_sram_addr = (kal_uint32*)MPC_CSIF_DSM_BASE;

//case1
volatile kal_uint8 csif_debug_reg_index = 0;

//case2
volatile kal_uint8 csif_debug_interrupt_index = 0;

//case3
volatile kal_uint32 csif_debug_icc_handshake_ack_flag = 0;
volatile kal_uint32 csif_debug_imc_handshake_ack_flag = 0;
volatile kal_uint32 csif_debug_mpc_handshake_ack_flag = 0;

volatile unsigned int icc_csif_debug_interrupt_index=0;
volatile unsigned int imc_csif_debug_interrupt_index=0;
volatile unsigned int mpc_csif_debug_interrupt_index=0;
/*
****************************************************************************************************************************
* CSIF_PreTest.
*
* This function is for testing the CSIF HW/SW
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_PreTest(void)
{
    //DVT test
    #if defined(CSIF_HW_TEST)
    CSIF_SSDVT_TEST();
    #endif
    
    //Driver test
    #if defined(CSIF_API_TEST)
    CSIF_DRIVER_TEST();
    #endif
}

/*
****************************************************************************************************************************
* CSIF_SSDVT_TEST.
*
* This function is for CSIF HW testing
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
#if defined(CSIF_HW_TEST)
static void CSIF_SSDVT_TEST(void)
{
    volatile kal_uint32 index=0;
    volatile kal_uint32 count=0;
    volatile kal_uint32 icc_error_addr=0, imc_error_addr=0, mpc_error_addr=0;
    
#if defined(IT_WITH_DSP)
    //MDM_INT32_WRITE(0xB5B50100);
    //sync point 1
    READ_CR(ICC_DSPCSIF_TASK_ID, csif_debug_icc_handshake_ack_flag);
    READ_CR(IMC_DSPCSIF_TASK_ID, csif_debug_imc_handshake_ack_flag);
    READ_CR(MPC_DSPCSIF_TASK_ID, csif_debug_mpc_handshake_ack_flag);
    while( (csif_debug_icc_handshake_ack_flag != 0xffff0001) || (csif_debug_imc_handshake_ack_flag != 0xffff0001) || (csif_debug_mpc_handshake_ack_flag != 0xffff0001) )
    {
    #if defined(CSIF_TIME_OUT)
        if(csif_time_out++ > 1000)
        {
           ASSERT(0);
        }
    #endif
        //read update register
        READ_CR(ICC_DSPCSIF_TASK_ID, csif_debug_icc_handshake_ack_flag);
        READ_CR(IMC_DSPCSIF_TASK_ID, csif_debug_imc_handshake_ack_flag);
        READ_CR(MPC_DSPCSIF_TASK_ID, csif_debug_mpc_handshake_ack_flag);
    }
#endif
#if defined(CSIF_SYNC_TEST)
    MDM_TM_END_SUCC_WRITE;
#endif
    
    //case0: SRAM read/write
    csif_pretest_case = 0;
    //MDM_INT32_WRITE(0xB5B50200);
    while(csif_debug_sram_pattern_index < SRAM_PATTERN_ARRAY)
    {
        //write memory pattern
        for(index=0; index<ICC_DSM_LEN; index++)
        {
            *(csif_debug_icc_sram_addr+index) = csif_debug_sram_pattern[csif_debug_sram_pattern_index];
        }
        for(index=0; index<IMC_DSM_LEN; index++)
        {
            *(csif_debug_imc_sram_addr+index) = csif_debug_sram_pattern[csif_debug_sram_pattern_index];
        }
        for(index=0; index<MPC_DSM_LEN; index++)
        {
            *(csif_debug_mpc_sram_addr+index) = csif_debug_sram_pattern[csif_debug_sram_pattern_index];
        }
        //read memory pattern 
        for(index=0; index<ICC_DSM_LEN; index++)
        {
            if( *(csif_debug_icc_sram_addr+index) != csif_debug_sram_pattern[csif_debug_sram_pattern_index] )
            {
                //MDM_INT32_WRITE(0xB5B50300+index);
                //MDM_TM_END_FAIL_WRITE;
                ASSERT(0);
            }
        }
        for(index=0; index<IMC_DSM_LEN; index++)
        {
            if( *(csif_debug_imc_sram_addr+index) != csif_debug_sram_pattern[csif_debug_sram_pattern_index] )
            {
                //MDM_INT32_WRITE(0xB5B50500+index);
                //MDM_TM_END_FAIL_WRITE;
                ASSERT(0);
            }
        }
        for(index=0; index<MPC_DSM_LEN; index++)
        {
            if( *(csif_debug_mpc_sram_addr+index) != csif_debug_sram_pattern[csif_debug_sram_pattern_index] )
            {
                //MDM_INT32_WRITE(0xB5B50800+index);
                //MDM_TM_END_FAIL_WRITE;
                ASSERT(0);
            }
        }
        csif_debug_sram_pattern_index++;
    }
   
    //case1: CR4 Reg RW test
    csif_pretest_case++;
    //MDM_INT32_WRITE(0xB5B50E00);
    
    //disable CR4 to receive DSP interrupt
    WRITE_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, 0x0);  
    WRITE_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, 0x0); 
    WRITE_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, 0x0); 
    
    //disable CR4 error interrupt 
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);  
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x0); 
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x0); 
      
    //for ACD register test
    for(csif_debug_reg_index=0; csif_debug_reg_index<32; csif_debug_reg_index++)
    {
        //write C2S ACD index       
        WRITE_CR(ICC_DSPCSIF_GPI_C_SET, 0x1<<csif_debug_reg_index);  
        WRITE_CR(IMC_DSPCSIF_GPI_C_SET, 0x1<<csif_debug_reg_index); 
        WRITE_CR(MPC_DSPCSIF_GPI_C_SET, 0x1<<csif_debug_reg_index); 
        
        
        //read C2S ACD index
        READ_CR(ICC_DSPCSIF_GPI_C_READ, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B50F00+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        READ_CR(IMC_DSPCSIF_GPI_C_READ, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B51000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        READ_CR(MPC_DSPCSIF_GPI_C_READ, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B52000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        //clear C2S ACD index
        WRITE_CR(ICC_DSPCSIF_GPI_C_CLEAR, 0x1<<csif_debug_reg_index);  
        WRITE_CR(IMC_DSPCSIF_GPI_C_CLEAR, 0x1<<csif_debug_reg_index); 
        WRITE_CR(MPC_DSPCSIF_GPI_C_CLEAR, 0x1<<csif_debug_reg_index); 
        
        //read C2S ACD index
        READ_CR(ICC_DSPCSIF_GPI_C_READ, index);
        if(index!=0)
        {
            //MDM_INT32_WRITE(0xB5B53000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        READ_CR(IMC_DSPCSIF_GPI_C_READ, index);
        if(index!=0)
        {
            //MDM_INT32_WRITE(0xB5B54000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        READ_CR(MPC_DSPCSIF_GPI_C_READ, index);
        if(index!=0)
        {
            //MDM_INT32_WRITE(0xB5B55000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
    }
    
    //for S2C enable test
    for(csif_debug_reg_index=0; csif_debug_reg_index<32; csif_debug_reg_index++)
    {
        //write s2c enable register
        WRITE_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, 0x1<<csif_debug_reg_index);  
        WRITE_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, 0x1<<csif_debug_reg_index); 
        WRITE_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, 0x1<<csif_debug_reg_index); 
        
        //read s2c enable register
        READ_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B56000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B57000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B58000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
    }
    
    //for Valid enable test
    //for(csif_debug_reg_index=0; csif_debug_reg_index<32; csif_debug_reg_index++)
    //{
        //write valid register
    //    WRITE_CR(ICC_DSPCSIF_VAS_VALID, 0x1<<csif_debug_reg_index);
    //    WRITE_CR(IMC_DSPCSIF_VAS_VALID, 0x1<<csif_debug_reg_index);
    //    WRITE_CR(MPC_DSPCSIF_VAS_VALID, 0x1<<csif_debug_reg_index);
        
        //read valid register
    //    READ_CR(ICC_DSPCSIF_VAS_VALID, index);
    //    if(index!= (0x1<<csif_debug_reg_index) )
    //    {
    //        MDM_INT32_WRITE(0xB5B59000+csif_debug_reg_index);
    //        MDM_TM_END_FAIL_WRITE;
    //        ASSERT(0);
    //    }
        
    //    READ_CR(IMC_DSPCSIF_VAS_VALID, index);
    //    if(index!= (0x1<<csif_debug_reg_index) )
    //    {
    //        MDM_INT32_WRITE(0xB5B5a000+csif_debug_reg_index);
    //        MDM_TM_END_FAIL_WRITE;
    //        ASSERT(0);
    //    }
        
    //    READ_CR(MPC_DSPCSIF_VAS_VALID, index);
    //    if(index!= (0x1<<csif_debug_reg_index) )
    //    {
    //        MDM_INT32_WRITE(0xB5B5b000+csif_debug_reg_index);
    ///       MDM_TM_END_FAIL_WRITE;
    //        ASSERT(0);
    //    }
    //}
   
    //for CR4 error type test
    for(csif_debug_reg_index=0; csif_debug_reg_index<4; csif_debug_reg_index++)
    {
        //skip s2c ovfl interrupt
        //if(csif_debug_reg_index == 2)
        //    continue;
            
        //write CR4 error register
        WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x1<<csif_debug_reg_index);
        WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x1<<csif_debug_reg_index);
        WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x1<<csif_debug_reg_index);
        
        //read CR4 error register
        READ_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B5c000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B5d000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B5e000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
    }
    
    //for DSP MPU start test
    for(csif_debug_reg_index=0; csif_debug_reg_index<8; csif_debug_reg_index++)
    {
        //write DSP MPU start register
        WRITE_CR(ICC_DSPCSIF_DSP_RANGE_START_ADDR, 0x1<<csif_debug_reg_index);
        WRITE_CR(IMC_DSPCSIF_DSP_RANGE_START_ADDR, 0x1<<csif_debug_reg_index);
        WRITE_CR(MPC_DSPCSIF_DSP_RANGE_START_ADDR, 0x1<<csif_debug_reg_index);
        
        //read DSP MPU start register
        READ_CR(ICC_DSPCSIF_DSP_RANGE_START_ADDR, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B5f000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(IMC_DSPCSIF_DSP_RANGE_START_ADDR, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B60000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(MPC_DSPCSIF_DSP_RANGE_START_ADDR, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B61000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
    }
    
    //for DSP MPU size test
    for(csif_debug_reg_index=0; csif_debug_reg_index<8; csif_debug_reg_index++)
    {
        //write DSP MPU size register
        WRITE_CR(ICC_DSPCSIF_DSP_RANGE_SIZE, 0x1<<csif_debug_reg_index);
        WRITE_CR(IMC_DSPCSIF_DSP_RANGE_SIZE, 0x1<<csif_debug_reg_index);
        WRITE_CR(MPC_DSPCSIF_DSP_RANGE_SIZE, 0x1<<csif_debug_reg_index);
        
        //read DSP MPU size register
        READ_CR(ICC_DSPCSIF_DSP_RANGE_SIZE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B62000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(IMC_DSPCSIF_DSP_RANGE_SIZE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B63000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(MPC_DSPCSIF_DSP_RANGE_SIZE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B64000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
    }
    
     //for CR4 MPU start test
    for(csif_debug_reg_index=0; csif_debug_reg_index<8; csif_debug_reg_index++)
    {
        //write CR4 MPU start register
        WRITE_CR(ICC_DSPCSIF_CR4_RANGE_START_ADDR, 0x1<<csif_debug_reg_index);
        WRITE_CR(IMC_DSPCSIF_CR4_RANGE_START_ADDR, 0x1<<csif_debug_reg_index);
        WRITE_CR(MPC_DSPCSIF_CR4_RANGE_START_ADDR, 0x1<<csif_debug_reg_index);
        
        //read CR4 MPU start register
        READ_CR(ICC_DSPCSIF_CR4_RANGE_START_ADDR, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B65000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(IMC_DSPCSIF_CR4_RANGE_START_ADDR, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B66000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(MPC_DSPCSIF_CR4_RANGE_START_ADDR, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B67000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
    }
    
    //for CR4 MPU size test
    for(csif_debug_reg_index=0; csif_debug_reg_index<8; csif_debug_reg_index++)
    {
        //write CR4 MPU size register
        WRITE_CR(ICC_DSPCSIF_CR4_RANGE_SIZE, 0x1<<csif_debug_reg_index);
        WRITE_CR(IMC_DSPCSIF_CR4_RANGE_SIZE, 0x1<<csif_debug_reg_index);
        WRITE_CR(MPC_DSPCSIF_CR4_RANGE_SIZE, 0x1<<csif_debug_reg_index);
        
        //read CR4 MPU size register
        READ_CR(ICC_DSPCSIF_CR4_RANGE_SIZE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B68000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(IMC_DSPCSIF_CR4_RANGE_SIZE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B69000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
        
        READ_CR(MPC_DSPCSIF_CR4_RANGE_SIZE, index);
        if(index!= (0x1<<csif_debug_reg_index) )
        {
            //MDM_INT32_WRITE(0xB5B6a000+csif_debug_reg_index);
            //MDM_TM_END_FAIL_WRITE;
            ASSERT(0);
        }
    }
  
    //case2: Error exception: overflow interrupt testing
    csif_pretest_case++;
    
    //CSIF_Init();
    
    //MDM_INT32_WRITE(0xB5B6b000);
    //disable Coresonic interrupt
    WRITE_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, 0x0);  
    WRITE_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, 0x0); 
    WRITE_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, 0x0);
    
    //enable overflow error type
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x1);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x1);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x1);
    
    for(csif_debug_interrupt_index=0; csif_debug_interrupt_index<32; csif_debug_interrupt_index++)
    {
        WRITE_CR(ICC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(ICC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(IMC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index));
        WRITE_CR(IMC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(MPC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index));    
    }
    for(index=0; index<10; index++)
    {
        count = count + index;
    }
    for(csif_debug_interrupt_index=0; csif_debug_interrupt_index<32; csif_debug_interrupt_index++)
    {
        WRITE_CR(ICC_DSPCSIF_ERROR_C2S_OVFL_CLR, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(IMC_DSPCSIF_ERROR_C2S_OVFL_CLR, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_ERROR_C2S_OVFL_CLR, (0x1<<csif_debug_interrupt_index));    
    }
    for(index=0; index<10; index++)
    {
        count = count + index;
    }
    
    //disable overflow error type
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    
    for(csif_debug_interrupt_index=0; csif_debug_interrupt_index<32; csif_debug_interrupt_index++)
    {
        WRITE_CR(ICC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(ICC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(IMC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index));
        WRITE_CR(IMC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(MPC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index));    
    }
    for(index=0; index<10; index++)
    {
        count = count + index;
    }
    for(csif_debug_interrupt_index=0; csif_debug_interrupt_index<32; csif_debug_interrupt_index++)
    {
        WRITE_CR(ICC_DSPCSIF_ERROR_C2S_OVFL_CLR, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(IMC_DSPCSIF_ERROR_C2S_OVFL_CLR, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_ERROR_C2S_OVFL_CLR, (0x1<<csif_debug_interrupt_index));    
    }
    for(index=0; index<10; index++)
    {
        count = count + index;
    }
    
    //enable conflict error type
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x4);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x4);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x4);
    
    for(csif_debug_interrupt_index=0; csif_debug_interrupt_index<32; csif_debug_interrupt_index++)
    {
        WRITE_CR(ICC_DSPCSIF_GPI_C_SET, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(IMC_DSPCSIF_GPI_C_SET, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_GPI_C_SET, (0x1<<csif_debug_interrupt_index));   

        WRITE_CR(ICC_DSPCSIF_GPI_C_CLEAR, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(IMC_DSPCSIF_GPI_C_CLEAR, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_GPI_C_CLEAR, (0x1<<csif_debug_interrupt_index));  
        
        WRITE_CR(ICC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(IMC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, (0x1<<csif_debug_interrupt_index));  
    }
    for(index=0; index<10; index++)
    {
        count = count + index;
    }
    
    //disable conflict error type
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    
    for(csif_debug_interrupt_index=0; csif_debug_interrupt_index<32; csif_debug_interrupt_index++)
    {
        WRITE_CR(ICC_DSPCSIF_GPI_C_SET, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(IMC_DSPCSIF_GPI_C_SET, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_GPI_C_SET, (0x1<<csif_debug_interrupt_index));   

        WRITE_CR(ICC_DSPCSIF_GPI_C_CLEAR, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(IMC_DSPCSIF_GPI_C_CLEAR, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_GPI_C_CLEAR, (0x1<<csif_debug_interrupt_index));  
        
        WRITE_CR(ICC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(IMC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_ERROR_ACD_CONFLICT_CLR, (0x1<<csif_debug_interrupt_index));  
    }
    for(index=0; index<10; index++)
    {
        count = count + index;
    }
    
    //for MPU violate exception
    //enable mpu error type
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x8);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x8);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x8);
    
    WRITE_CR(ICC_DSPCSIF_CR4_RANGE_START_ADDR, 0x00000000);
    WRITE_CR(ICC_DSPCSIF_CR4_RANGE_SIZE, 0x40);
    WRITE_CR(IMC_DSPCSIF_CR4_RANGE_START_ADDR, 0x00000000);
    WRITE_CR(IMC_DSPCSIF_CR4_RANGE_SIZE, 0x40);
    WRITE_CR(MPC_DSPCSIF_CR4_RANGE_START_ADDR, 0x00000000);
    WRITE_CR(MPC_DSPCSIF_CR4_RANGE_SIZE, 0x40);
    for(csif_debug_interrupt_index=0; csif_debug_interrupt_index<16; csif_debug_interrupt_index++)
    {
        //write illegal address
        *(csif_debug_icc_sram_addr+csif_debug_interrupt_index) = 0x12345678;
        *(csif_debug_imc_sram_addr+csif_debug_interrupt_index) = 0x12345678;
        *(csif_debug_mpc_sram_addr+csif_debug_interrupt_index) = 0x12345678;
        
        for(index=0; index<10; index++)
        {
            count = count + index;
        }
        READ_CR(ICC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR, icc_error_addr);
        READ_CR(IMC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR, imc_error_addr);
        READ_CR(MPC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR, mpc_error_addr);
        
        if( (icc_error_addr != csif_debug_interrupt_index) || (imc_error_addr != csif_debug_interrupt_index) || (mpc_error_addr != csif_debug_interrupt_index) )
        {
            //MDM_INT32_WRITE(0xB5DD0000+csif_debug_interrupt_index);
        }
        WRITE_CR(ICC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR_CLR, 0x1);
        WRITE_CR(IMC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR_CLR, 0x1);
        WRITE_CR(MPC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR_CLR, 0x1);
    }
    //MDM_TM_END_SUCC_WRITE;
  
}
#endif //CSIF_HW_TEST

/*
****************************************************************************************************************************
* CSIF_Interrupt_Test.
*
* This function is for interrupt test
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Interrupt_Test(void)
{
//#if defined(CSIF_Interrupt_Test)
    volatile kal_uint32 index=0;
    volatile kal_uint32 count=0;
    
#if defined(IT_WITH_DSP)
    //case3: handshake with Coresonic (interrupt testing)
    csif_pretest_case++;
    //MDM_INT32_WRITE(0xB5B6c000);
    
    //clear  Coresonic interrupt
    WRITE_CR(ICC_DSPCSIF_S2C_IRQ_CLR, 0xffffffff);  
    WRITE_CR(IMC_DSPCSIF_S2C_IRQ_CLR, 0xffffffff); 
    WRITE_CR(MPC_DSPCSIF_S2C_IRQ_CLR, 0xffffffff);
    
    //enable Coresonic interrupt
    WRITE_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, 0xfffffffe);  
    WRITE_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, 0xfffffffe); 
    WRITE_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, 0xfffffffe);
    
    //disable error type
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    
    //re-init CSIF HW
    //CSIF_Init();
    WRITE_CR(ICC_DSPCSIF_VAS_VALID, 0x12345678);
    WRITE_CR(IMC_DSPCSIF_VAS_VALID, 0x12345678);
    WRITE_CR(MPC_DSPCSIF_VAS_VALID, 0x12345678);
    
    #if defined(CSIF_TIME_OUT)
    csif_time_out = 0;
    #endif
    READ_CR(ICC_DSPCSIF_TASK_ID, csif_debug_icc_handshake_ack_flag);
    READ_CR(IMC_DSPCSIF_TASK_ID, csif_debug_imc_handshake_ack_flag);
    READ_CR(MPC_DSPCSIF_TASK_ID, csif_debug_mpc_handshake_ack_flag);
    while( (csif_debug_icc_handshake_ack_flag != 0x87654321) || (csif_debug_imc_handshake_ack_flag != 0x87654321) || (csif_debug_mpc_handshake_ack_flag != 0x87654321) )
    {
        #if defined(CSIF_TIME_OUT)
        if(csif_time_out++ > 1000)
        {
           ASSERT(0);
        }
        #endif
        READ_CR(ICC_DSPCSIF_TASK_ID, csif_debug_icc_handshake_ack_flag);
        READ_CR(IMC_DSPCSIF_TASK_ID, csif_debug_imc_handshake_ack_flag);
        READ_CR(MPC_DSPCSIF_TASK_ID, csif_debug_mpc_handshake_ack_flag);
    }
    
    for(csif_debug_interrupt_index=0; csif_debug_interrupt_index<32; csif_debug_interrupt_index++)
    {
        WRITE_CR(ICC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index));  
        WRITE_CR(IMC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index)); 
        WRITE_CR(MPC_DSPCSIF_C2S_IRQ_SET, (0x1<<csif_debug_interrupt_index));
    }
    
    //add delay for interrupt handling
    for(count=0; count<100; count++)
    {
        index = index + count;
    }
    
    WRITE_CR(ICC_DSPCSIF_VAS_VALID, 0xA5A5A5A5);
    WRITE_CR(IMC_DSPCSIF_VAS_VALID, 0xA5A5A5A5);
    WRITE_CR(MPC_DSPCSIF_VAS_VALID, 0xA5A5A5A5);
    
    
    //MDM_TM_END_SUCC_WRITE; bit 0 in DSP is for core idle signal
    if(icc_csif_debug_interrupt_index != 31 || imc_csif_debug_interrupt_index!= 31 || mpc_csif_debug_interrupt_index != 31){
        //MDM_TM_END_FAIL_WRITE;
    }       
#endif //IT_WITH_DSP
//#endif //CSIF_Interrupt_Test
}

/*
****************************************************************************************************************************
* CSIF_ICC_Interrupt_Handler.
*
* This function is for ICC normal interrupt handler
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_ICC_Interrupt_Handler(kal_uint32 status_index)
{
    icc_csif_debug_interrupt_index++;
}

/*
****************************************************************************************************************************
* CSIF_ICC_C2S_OVFL_Interrupt_Handler.
*
* This function is for ICC c2s overflow interrupt handler
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_ICC_C2S_OVFL_Interrupt_Handler(kal_uint32 status_index)
{
    unsigned int index=0;
    READ_CR(ICC_DSPCSIF_CR4_ERROR, index);
    if((index&0x2) != 0x2)
    {
        //MDM_INT32_WRITE(0xB5B6b200+index);
        //MDM_TM_END_FAIL_WRITE;
        ASSERT(0);
    }
    
    //MDM_INT32_WRITE(0xB5B6b001);
    READ_CR(ICC_DSPCSIF_ERROR_C2S_OVFL, index);
    if( !(index &(0x1<<status_index)) )
    {
        //MDM_INT32_WRITE(0xB5B6b100+status_index);
        //MDM_TM_END_FAIL_WRITE;
        ASSERT(0);
    }
    WRITE_CR(ICC_DSPCSIF_ERROR_C2S_OVFL_CLR, 0x1<<status_index);
}

/*
****************************************************************************************************************************
* CSIF_IMC_Interrupt_Handler.
*
* This function is for IMC normal interrupt handler
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_IMC_Interrupt_Handler(kal_uint32 status_index)
{
    imc_csif_debug_interrupt_index++;
}

/*
****************************************************************************************************************************
* CSIF_IMC_Interrupt_Handler.
*
* This function is for IMC c2s overflow interrupt handler
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_IMC_C2S_OVFL_Interrupt_Handler(kal_uint32 status_index)
{
    unsigned int index=0;
    READ_CR(IMC_DSPCSIF_CR4_ERROR, index);
    if((index&0x2) != 0x2)
    {
        //MDM_INT32_WRITE(0xB5B6b400+index);
        //MDM_TM_END_FAIL_WRITE;
        ASSERT(0);
    }
    
    //MDM_INT32_WRITE(0xB5B6b002);
    READ_CR(IMC_DSPCSIF_ERROR_C2S_OVFL, index);
    if( !(index &(0x1<<status_index)) )
    {
        //MDM_INT32_WRITE(0xB5B6b300+status_index);
        //MDM_TM_END_FAIL_WRITE;
        ASSERT(0);
    }
    WRITE_CR(IMC_DSPCSIF_ERROR_C2S_OVFL_CLR, 0x1<<status_index);
}

/*
****************************************************************************************************************************
* CSIF_MPC_Interrupt_Handler.
*
* This function is for MPC normal interrupt handler
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_MPC_Interrupt_Handler(kal_uint32 status_index)
{
    mpc_csif_debug_interrupt_index++;
}

/*
****************************************************************************************************************************
* CSIF_MPC_Interrupt_Handler.
*
* This function is for MPC c2s overflow interrupt handler
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_MPC_C2S_OVFL_Interrupt_Handler(kal_uint32 status_index)
{
    unsigned int index=0;
    READ_CR(MPC_DSPCSIF_CR4_ERROR, index);
    if((index&0x2) != 0x2)
    {
        //MDM_INT32_WRITE(0xB5B6b600+index);
        //MDM_TM_END_FAIL_WRITE;
        ASSERT(0);
    }
    
    //MDM_INT32_WRITE(0xB5B6b003);
    READ_CR(MPC_DSPCSIF_ERROR_C2S_OVFL, index);
    if( !(index &(0x1<<status_index)) )
    {
        //MDM_INT32_WRITE(0xB5B6b500+status_index);
        //MDM_TM_END_FAIL_WRITE;
        ASSERT(0);
    }
    WRITE_CR(MPC_DSPCSIF_ERROR_C2S_OVFL_CLR, 0x1<<status_index);
}

/*
****************************************************************************************************************************
* CSIF_Interrupt_Handler.
*
* This function is for un-test error interrupt callback
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
void CSIF_Interrupt_Handler(kal_uint32 status_index)
{
    if(csif_debug_interrupt_index != status_index)
    {
        //MDM_INT32_WRITE(0xB5B6b700 + status_index);
        //MDM_TM_END_FAIL_WRITE;
    }
}

/*
****************************************************************************************************************************
* CSIF_DRIVER_TEST.
*
* This function is for CSIF HW testing
* 
* Input: None
*
* Output: None
*
****************************************************************************************************************************
*/
#if defined(CSIF_API_TEST)
static void CSIF_DRIVER_TEST(void)
{
    kal_uint32 index = 0;
    kal_uint32 result = 0;
    
    //disable error interrupt
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    
    //disable coresonic interrrupt
     WRITE_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, 0x0);
     WRITE_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, 0x0);
     WRITE_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, 0x0);
    
    #if defined(IT_WITH_DSP)
    //MDM_INT32_WRITE(0xB5B70000);
    //sync point 1
    READ_CR(ICC_DSPCSIF_TASK_ID, csif_debug_icc_handshake_ack_flag);
    READ_CR(IMC_DSPCSIF_TASK_ID, csif_debug_imc_handshake_ack_flag);
    READ_CR(MPC_DSPCSIF_TASK_ID, csif_debug_mpc_handshake_ack_flag);
    while( (csif_debug_icc_handshake_ack_flag != 0xffff0001) || (csif_debug_imc_handshake_ack_flag != 0xffff0001) || (csif_debug_mpc_handshake_ack_flag != 0xffff0001) )
    {
    #if defined(CSIF_TIME_OUT)
        if(csif_time_out++ > 1000)
        {
           ASSERT(0);
        }
    #endif
        //read update register
        READ_CR(ICC_DSPCSIF_TASK_ID, csif_debug_icc_handshake_ack_flag);
        READ_CR(IMC_DSPCSIF_TASK_ID, csif_debug_imc_handshake_ack_flag);
        READ_CR(MPC_DSPCSIF_TASK_ID, csif_debug_mpc_handshake_ack_flag);
    }
    #endif
    
    //CSIF_C2S_SWI_SET & CSIF_C2S_SWI_Read UT
    for(index=0; index<32; index++)
    {
        //MDM_INT32_WRITE(0xB5B80000 + index);
        //ICC
        CSIF_C2S_SWI_Set(ICC_CORE, index);
        READ_CR(ICC_DSPCSIF_C2S_IRQ_READ, result);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B80100 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        
        //IMC
        CSIF_C2S_SWI_Set(IMC_CORE, index);
        READ_CR(IMC_DSPCSIF_C2S_IRQ_READ, result);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B80200 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        
        //MPC
        CSIF_C2S_SWI_Set(MPC_CORE, index);
        READ_CR(MPC_DSPCSIF_C2S_IRQ_READ, result);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B80300 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
    }
    
    //CSIF_S2C_SWI_Enable & CSIF_S2C_SWI_Enable_Read
    for(index=0; index<32; index++)
    {
        //MDM_INT32_WRITE(0xB5B80400 + index);
        //ICC
        CSIF_S2C_SWI_Enable(ICC_CORE, 1<<index);
        READ_CR(ICC_DSPCSIF_S2C_IRQ_ENABLE, result);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B80500 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        
        //IMC
        CSIF_S2C_SWI_Enable(IMC_CORE, 1<<index);
        READ_CR(IMC_DSPCSIF_S2C_IRQ_ENABLE, result);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B80600 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        
        //MPC
        CSIF_S2C_SWI_Enable(MPC_CORE, 1<<index);
        READ_CR(MPC_DSPCSIF_S2C_IRQ_ENABLE, result);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B80700 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
    }
    
    //CSIF_ACD_C2S_Set & CSIF_ACD_C2S_Clear & CSIF_ACD_C2S_Read
    for(index=0; index<32; index++)
    {
        //MDM_INT32_WRITE(0xB5B80800 + index);
        //ICC
        CSIF_ACD_C2S_Set(ICC_CORE, index);
        result = CSIF_ACD_C2S_Read(ICC_CORE);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B80900 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        CSIF_ACD_C2S_Clear(ICC_CORE, index);
        result = CSIF_ACD_C2S_Read(ICC_CORE);
        if((result & (1<<index)))
        {
            //MDM_INT32_WRITE(0xB5B80a00 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        
        //IMC
        CSIF_ACD_C2S_Set(IMC_CORE, index);
        result = CSIF_ACD_C2S_Read(IMC_CORE);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B80b00 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        CSIF_ACD_C2S_Clear(IMC_CORE, index);
        result = CSIF_ACD_C2S_Read(IMC_CORE);
        if((result & (1<<index)))
        {
            //MDM_INT32_WRITE(0xB5B80c00 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        
        //MPC
        CSIF_ACD_C2S_Set(MPC_CORE, index);
        result = CSIF_ACD_C2S_Read(MPC_CORE);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B80d00 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        CSIF_ACD_C2S_Clear(MPC_CORE, index);
        result = CSIF_ACD_C2S_Read(MPC_CORE);
        if((result & (1<<index)))
        {
            //MDM_INT32_WRITE(0xB5B80e00 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
    }
    
    //disable error interrupt
    WRITE_CR(ICC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(IMC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    WRITE_CR(MPC_DSPCSIF_CR4_ERROR_ENABLE, 0x0);
    
    //test overflow 
    for(index=0; index<32; index++)
    {
        //MDM_INT32_WRITE(0xB5B81300 + index);
        //trigger overflow
        //ICC
        CSIF_C2S_SWI_Set(ICC_CORE, index);
        READ_CR(ICC_DSPCSIF_ERROR_C2S_OVFL, result);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B81400 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        CSIF_C2S_Overflow_clear(ICC_CORE, index);
        READ_CR(ICC_DSPCSIF_ERROR_C2S_OVFL, result);
        if((result & (1<<index)))
        {
            //MDM_INT32_WRITE(0xB5B81400 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        //IMC
        CSIF_C2S_SWI_Set(IMC_CORE, index);
        READ_CR(IMC_DSPCSIF_ERROR_C2S_OVFL, result);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B81500 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        CSIF_C2S_Overflow_clear(IMC_CORE, index);
        READ_CR(IMC_DSPCSIF_ERROR_C2S_OVFL, result);
        if((result & (1<<index)))
        {
            //MDM_INT32_WRITE(0xB5B81600 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        //MPC
        CSIF_C2S_SWI_Set(MPC_CORE, index);
        READ_CR(MPC_DSPCSIF_ERROR_C2S_OVFL, result);
        if((result & (1<<index)) == 0)
        {
            //MDM_INT32_WRITE(0xB5B81700 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
        CSIF_C2S_Overflow_clear(MPC_CORE, index);
        READ_CR(MPC_DSPCSIF_ERROR_C2S_OVFL, result);
        if((result & (1<<index)))
        {
            //MDM_INT32_WRITE(0xB5B81800 + index);
            //MDM_TM_END_FAIL_WRITE;
        }
    }
}
#endif //CSIF_API_TEST

#if (defined(CSIF_MOMORY_BACKUP_TEST))
#include "csif_local_define.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "dsp_header_define_csif.h"
#define WRITE_CR(addr, value)   DRV_WriteReg32(addr, value)
#define READ_CR(addr, value)    value=DRV_Reg32(addr)
extern volatile CSIF_ZI_Table_Backup CSIF_ZI_Table_Backup_ICC[10];
extern volatile CSIF_ZI_Table_Backup CSIF_ZI_Table_Backup_IMC[10];
extern volatile CSIF_ZI_Table_Backup CSIF_ZI_Table_Backup_MPC[10];
extern volatile kal_uint32 csif_zi_table_backup_icc_index; 
extern volatile kal_uint32 csif_zi_table_backup_imc_index; 
extern volatile kal_uint32 csif_zi_table_backup_mpc_index; 
void CSIF_Memory_Callback_Pass(kal_uint32 core_index){
    kal_uint32 index, temp;
    switch(core_index){
        case ICC_CORE:
            if(csif_zi_table_backup_icc_index != 0){
                WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0003);//fail
                return;     
            }
            for(index = 0; index < 10 ; index++){
                if(CSIF_ZI_Table_Backup_ICC[index].zi_reason != 0xa5a5a5a5+index){
                    WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                    return;     
                }
                if(CSIF_ZI_Table_Backup_ICC[index].table_start != 0xa5a5a5a5+index+1){
                    WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                    return;     
                }
                if(CSIF_ZI_Table_Backup_ICC[index].table_lengh != 0xa5a5a5a5+index+2){
                    WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                    return;  
                }
                for(temp = 0 ; temp < 32 ; temp ++){
                    if(CSIF_ZI_Table_Backup_ICC[index].zi_table[temp] != 0x5a5a5a5a+index+temp){
                        WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                        return;  
                    }  
                }
            }
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0001);//pass
            break;
        case IMC_CORE:
            if(csif_zi_table_backup_imc_index != 0){
                WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xAAAA0003);//fail
                return;     
            }
            for(index = 0; index < 10 ; index++){
                if(CSIF_ZI_Table_Backup_IMC[index].zi_reason != 0xa5a5a5a5+index){
                    WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                    return;     
                }
                if(CSIF_ZI_Table_Backup_IMC[index].table_start != 0xa5a5a5a5+index+1){
                    WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                    return;     
                }
                if(CSIF_ZI_Table_Backup_IMC[index].table_lengh != 0xa5a5a5a5+index+2){
                    WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                    return;  
                }
                for(temp = 0 ; temp < 32 ; temp ++){
                    if(CSIF_ZI_Table_Backup_IMC[index].zi_table[temp] != 0x5a5a5a5a+index+temp){
                        WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                        return;  
                    }  
                }
            }
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xAAAA0001);//pass
            break;
        case MPC_CORE:
            if(csif_zi_table_backup_mpc_index != 0){
                WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xAAAA0003);//fail
                return;     
            }
            for(index = 0; index < 10 ; index++){
                if(CSIF_ZI_Table_Backup_MPC[index].zi_reason != 0xa5a5a5a5+index){
                    WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                    return;     
                }
                if(CSIF_ZI_Table_Backup_MPC[index].table_start != 0xa5a5a5a5+index+1){
                    WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                    return;     
                }
                if(CSIF_ZI_Table_Backup_MPC[index].table_lengh != 0xa5a5a5a5+index+2){
                    WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                    return;  
                }
                for(temp = 0 ; temp < 32 ; temp ++){
                    if(CSIF_ZI_Table_Backup_MPC[index].zi_table[temp] != 0x5a5a5a5a+index+temp){
                        WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xAAAA0002);//fail
                        return;  
                    }  
                }
            }
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xAAAA0001);//pass
            break;
        default:
            ASSERT(0);
            break;
    }
}

#endif

#if (defined(CSIF_REMOTE_TEST))
#include "csif_local_define.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "CSIF_ICC_ALL.h"
#include "CSIF_IMC_ALL.h"
#include "CSIF_MPC_ALL.h"
#define WRITE_CR(addr, value)   DRV_WriteReg32(addr, value)
#define READ_CR(addr, value)    value=DRV_Reg32(addr)
void CSIF_Prestest_0(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0000);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB0000);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC0000);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_1(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0001);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB0001);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC0001);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_2(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0002);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB0002);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC0002);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_3(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0003);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB0003);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC0003);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_4(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0004);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB0004);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC0004);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_5(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0005);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB0005);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC0005);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_6(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0006);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB0006);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC0006);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_7(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0007);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB0007);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC0007);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_8(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0008);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB0008);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC0008);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_9(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA0009);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB0009);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC0009);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_10(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA000A);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB000A);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC000A);
            break;
        default:
            ASSERT(0);
    }
}
void CSIF_Prestest_11(kal_uint32 core_index){
    switch(core_index){
        case ICC_CORE:
            WRITE_CR(ICC_DSPCSIF_TASK_ID, 0xAAAA000B);
            break;
        case IMC_CORE:
            WRITE_CR(IMC_DSPCSIF_TASK_ID, 0xBBBB000B);
            break;
        case MPC_CORE:
            WRITE_CR(MPC_DSPCSIF_TASK_ID, 0xCCCC000B);
            break;
        default:
            ASSERT(0);
    }
}
#endif
