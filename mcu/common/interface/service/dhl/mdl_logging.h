/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   mdl_logging.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Definition of MDL Logging 
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 12 02 2016 cynthia.sun
 * [MOLY00216513] Add Rosa Option
 * . add Rosa option
 *
 * 08 23 2016 cynthia.sun
 * [MOLY00197541] EL1D MDL filter setting handshake for low power improvement -- interface part
 * . w1630 interface
 *
 * 06 03 2016 cynthia.sun
 * [MOLY00183146] [MDL] Set filter every 5s / Don't flush padding when PORT_DIS on / Don't print power_up sync if filter all off
 * .
 *
 * 04 22 2016 yancy.chien
 * [MOLY00175083] [DHL&MDL] Buffer reduction for Cat4 Modem.
 *
 * 03 08 2016 cynthia.sun
 * [MOLY00168033] [MDL] MP3 Integration
 * .
 *
 * 03 08 2016 cynthia.sun
 * [MOLY00168033] [MDL] MP3 Integration
 * .
 *
 * 03 08 2016 cynthia.sun
 * [MOLY00168033] [MDL] MP3 Integration
 * . enable MDL clock off for all chip
 *
 * 12 18 2015 cynthia.sun
 * [MOLY00153216] [EL1D] Check Sonic MDL status before switching off Sonic root CG.
 * .
 *
 * 10 22 2015 cynthia.sun
 * [MOLY00146243] Detect MDL MPU violation and add MDL HW register status logs
 * .
 *
 * 10 14 2015 cynthia.sun
 * [MOLY00145251] [MDL] fix implicit declaration of function
 * .
 *
 * 10 13 2015 cynthia.sun
 * [MOLY00144895] [MDL] Check MDL is initialized already
 * .
 *
 * 10 06 2015 cynthia.sun
 * [MOLY00143555] [MDL] Swap trace_id of power_up and power_down / stop sync of MD32 when sys_idle / reduce BRP buffer size
 * .
 *
 * 09 21 2015 cynthia.sun
 * [MOLY00142563] [MT6755][Jade Phone] Missing DSP trace when coresonic received exception(force assert by ELT)
 * .
 *
 * 09 08 2015 cynthia.sun
 * [MOLY00140148] [MDL] Clean buffer and reappear EMI buffer content when exception occurs
 * .
 *
 * 08 27 2015 cynthia.sun
 * [MOLY00139417] [DHL] MDL logging buffer reduction and disable DDREN
 * .
 *
 * 08 06 2015 cynthia.sun
 * [MOLY00134636] [Blocking][MT6755][CMW500_MLAPI][FDD B7][3.1.2.1.A-1] No MPC log in Idle mode, Need tool support
 * .
 *
 * 08 05 2015 cynthia.sun
 * [MOLY00135406] [MDL] Memory Dump Feature of MDL Logging Buffer
 * .
 *
 * 07 30 2015 cynthia.sun
 * [MOLY00133413] [MDL] MDL Filter to NVRAM
 * .
 *
 * 06 16 2015 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 06 03 2015 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 06 02 2015 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 05 26 2015 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 03 18 2015 willie.pan
 * [MOLY00099410] [TK6291E1][1st AIQ Call] ELG dsp info lost when l1core exception happens
 * 	.
 *
 * 12 29 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 12 10 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 11 27 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 11 20 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 11 18 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 11 17 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 11 09 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 11 06 2014 eason.lai
 * [MOLY00082322] [MT6291_DEV][DHL] MDL porting
 * fix build error
 *
 * 11 06 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 11 06 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 09 09 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 08 08 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 08 07 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 08 07 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 * 08 06 2014 willie.pan
 * [MOLY00074379] [MT6291][MDL] MDL Logging Phase-in
 * 	.
 *
 ****************************************************************************/
#ifndef _MDL_LOGGING_H_
#define _MDL_LOGGING_H_

//#define __MDL_LOGGING_BUF_DUMP_MODE__

#include "dhl_def.h"
#include "kal_general_types.h"

#if defined(__MTK_TARGET__) 
    #if defined(__PCORE__)
        #include "ebc_drv.h"
    #endif        
#endif

#if defined(__MTK_TARGET__)

////////////////////DEFINITION////////////////////////
//The buffer side definition is in byte!

#if defined(__PCORE_ONLY__)  //Reduce buffer size on PCORE only project, but reduce the complexity also.
    #define MDL_LOGGING_BUF_SIZE_DFE  (4)
    #define MDL_LOGGING_BUF_SIZE_RAKE (4)
    #define MDL_LOGGING_BUF_SIZE_BRP  (4)
    #define MDL_LOGGING_BUF_SIZE_ICC  (4)
    #define MDL_LOGGING_BUF_SIZE_IMC  (4)
    #define MDL_LOGGING_BUF_SIZE_MPC  (4)
#else
	#define MDL_LOGGING_BUF_SIZE_RAKE (1216256)
	#define MDL_LOGGING_BUF_SIZE_MPC  (1205760)
#ifdef __LTE_A_CA__	
    #define MDL_LOGGING_BUF_SIZE_DFE  (1751040)
    #define MDL_LOGGING_BUF_SIZE_BRP  (1048576)
    #define MDL_LOGGING_BUF_SIZE_ICC  (996096)
    #define MDL_LOGGING_BUF_SIZE_IMC  (251648)
#else
	#define MDL_LOGGING_BUF_SIZE_DFE  (1623296)
    #define MDL_LOGGING_BUF_SIZE_BRP  (878592)
    #define MDL_LOGGING_BUF_SIZE_ICC  (573184)
    #define MDL_LOGGING_BUF_SIZE_IMC  (143360)
#endif
#endif

    //#if defined(TK6291)

    typedef enum
    {
        MDL_MD32_DFE,
        MDL_MD32_RAKE,
        MDL_MD32_BRP,
        MDL_CS_MPC,
        MDL_CS_IMC,
        MDL_CS_ICC,
        MDL_CORE_NUM
    }mdl_core_enum;

    typedef enum
    {
        MDL_CMIF,
        MDL_CSIF,
        MDL_MEM_TYPE_NUM
    } mdl_memory_type;

    typedef enum
    {
        GET_INFO_SUCCESS,
        ERROR_TYPE,
        NOT_INIT,
        NOT_POWER_DOWN,
    } mdl_xxif_info_error_code;

#if defined(__L1CORE__)
#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
    #define MDL0_BASEADDR	(0xF7B40000) // DFE
    #define MDL1_BASEADDR	(0xF9B40000) // RAKE
    #define MDL2_BASEADDR	(0xF9340000) // RXBRP
    #define MDL3_BASEADDR	(0xFD601700) // MPC
    #define MDL4_BASEADDR	(0xFDE03F00) // IMC
    #define MDL5_BASEADDR	(0xFEE01500) // ICC
#endif // defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
#endif // defined(__L1CORE__)

    // =========== L1 debug enable register ==============
    #define DFESYS_BASEADDR            (0xF7800000)
    #define RXBRP_BASEADDR             (0xF9000000)
    #define RAKE_BASEADDR              (0xF9800000)
    #define MPC_BASEADDR	           (0xFD601700) // MPC
    #define IMC_BASEADDR	           (0xFDE04100) // IMC
    #define ICC_BASEADDR	           (0xFEE01300) // ICC

    ///////////////////////////////////////////////////////////////   
    //DSP_EN
    #define DSP_DBG_EN_OFFSET           (0x00351000)
    
    #define DFESYS_PERI_CTRL_BASE_ADDR	     (DFESYS_BASEADDR+DSP_DBG_EN_OFFSET)
    #define DFESYS_PERI_CTRL_L1_DBG_EN 		 (DFESYS_PERI_CTRL_BASE_ADDR + 0x10)
    #define DFESYS_PERI_CTRL_L1_DBG_EN_MARK	 (0x62910001)
    #define DFESYS_PERI_CTRL_SET_L1_DBG_EN_ON do{ \
    			*((volatile kal_uint32*) (DFESYS_PERI_CTRL_L1_DBG_EN)) = (DFESYS_PERI_CTRL_L1_DBG_EN_MARK) ;\
    		}while(0)	

    #define RXBRP_PERI_CTRL_BASE_ADDR	     (RXBRP_BASEADDR+DSP_DBG_EN_OFFSET)
    #define RXBRP_PERI_CTRL_L1_DBG_EN 		 (RXBRP_PERI_CTRL_BASE_ADDR + 0x10)
    #define RXBRP_PERI_CTRL_L1_DBG_EN_MARK	 (0x62910001)
    #define RXBRP_PERI_CTRL_SET_L1_DBG_EN_ON do{ \
    			*((volatile kal_uint32*) (RXBRP_PERI_CTRL_L1_DBG_EN)) = (RXBRP_PERI_CTRL_L1_DBG_EN_MARK) ;\
    		}while(0)	

    #define RAKE_PERI_CTRL_BASE_ADDR	     (RAKE_BASEADDR+DSP_DBG_EN_OFFSET)
    #define RAKE_PERI_CTRL_L1_DBG_EN 		 (RAKE_PERI_CTRL_BASE_ADDR + 0x10)
    #define RAKE_PERI_CTRL_L1_DBG_EN_MARK	 (0x62910001)
    #define RAKE_PERI_CTRL_SET_L1_DBG_EN_ON do{ \
    			*((volatile kal_uint32*) (RAKE_PERI_CTRL_L1_DBG_EN)) = (RAKE_PERI_CTRL_L1_DBG_EN_MARK) ;\
    		}while(0)
    		
    #define MAX_MODULE_ID_NUM (64)    

    typedef struct 
    {
        kal_uint32 mdl_guard_id;                 // Should be 0x24542482         (0)
        kal_uint32 mdl_magic_id;                 // See MDL_INFO_CODE_XXX        (1)
        
        kal_uint32 mdl_buffer_size;              // MCU: Write , DSP: Read       (2)
        kal_uint32 mdl_buffer_addr;              // MCU: Write , DSP: Read       (3)
        kal_uint32 mdl_buffer_start_addr;        // MCU: Write , DSP: Read/B&R   (4)
        
        kal_uint8 mdl_swtr_period;               // MCU: Write , DSP: Read 

        kal_uint8 mdl_enable:1;                  // Enable MDL logging or not?  MCU: Write , DSP: Read
        //Disable MDL when all filters are off
        kal_uint8 mdl_buffer0_full: 1;           // MCU: Write , DSP: Read/B&R
        kal_uint8 mdl_buffer1_full: 1;           // MCU: Write , DSP: Read/B&R   
        kal_uint8 mdl_output_mode: 1;            // MCU: Write , DSP: Read
        //(__MDL_OUTPUT_MODE_EMI__(0): EMI, __MDL_OUTPUT_MODE_ATB__(1): ATB)
        kal_uint8 mdl_swla_enable: 1;            // MCU: Write , DSP: Read
        //(0: Disable, 1: Enable)
        kal_uint8 mdl_swtr_enable: 1;            // MCU: Write , DSP: Read
        //(0: Disable, 1: Enable)
        kal_uint8 mdl_emi_output_mode: 1;        // MCU: Write , DSP: Read       
        // ( __MDL_EMI_OUTPUT_WRAPPING_MODE__(0): Wrapping Mode,
        //   __MDL_EMI_OUTPUT_STREAMING_MODE__(1): Streaming Mode )
        kal_uint8 mdl_emi_buffer_wrapped: 1;     // MCU: Read , DSP: Write
        
        kal_uint8 mdl_info_guard_pattern_1;
        kal_uint8 mdl_info_guard_pattern_2;                                 // (5)
        
        kal_uint32 reserved_1;                                              // (6)
        kal_uint32 reserved_2;                                              // (7)     
        kal_uint32 reserved_3;                                              // (8)             
        kal_uint32 mdl_filter_flag;                                         // (9) Used as ATID in SIB mode
        kal_uint32 mdl_filter[MAX_MODULE_ID_NUM/4];                                          // (10)~(26)
    } mdl_info_t;        

    #define __MDL_INFO_GUARD_ID__                       (0x24542482)
    #define __MDL_INFO_CODE_DSP_FIRST_POWER_UP__        (0x24548001) //First Power Up (MCU->DSP)
    #define __MDL_INFO_CODE_DSP_FIRST_POWER_UP_DONE__   (0x24548002) //First Power Up Done! (DSP->MCU)
    #define __MDL_INFO_CODE_DSP_ENTER_IDLE__            (0x24548003) //IDLE is NOT Power Down (DSP->DSP)
    #define __MDL_INFO_CODE_DSP_POWER_DOWN__            (0x24548004) //DSP Power Down (DSP->MCU)
    #define __MDL_INFO_CODE_DSP_WAKE_UP__               (0x24548005) //Wake Up! (DSP->MCU)
    #define __MDL_INFO_CODE_DSP_CLOCK_OFF__             (0x24548006) //DSP can be clock off

    #define __MDL_OUTPUT_MODE_EMI__ (0)
    #define __MDL_OUTPUT_MODE_ATB__ (1)
    
    //MDL EMI Output Mode
    #define __MDL_EMI_OUTPUT_WRAPPING_MODE__ (0)
    #define __MDL_EMI_OUTPUT_STREAMING_MODE__ (1)

    ///////////////////////////////////////////////////////////////

    //MDL
    #define MDL_OFFSET  		        (0x00340000)

    #define MDL_DFE_EMI_BUF_SIZE_REG            ( DFESYS_BASEADDR + MDL_OFFSET + 0x0020 )
    #define MDL_DFE_EMI_BUF_BASE_ADDR_REG       ( DFESYS_BASEADDR + MDL_OFFSET + 0x0024 )
    #define MDL_DFE_EMI_BUF_START_ADDR_REG      ( DFESYS_BASEADDR + MDL_OFFSET + 0x0028 )

    #define MDL_BRP_EMI_BUF_SIZE_REG            ( RXBRP_BASEADDR + MDL_OFFSET + 0x0020 )
    #define MDL_BRP_EMI_BUF_BASE_ADDR_REG       ( RXBRP_BASEADDR + MDL_OFFSET + 0x0024 )
    #define MDL_BRP_EMI_BUF_START_ADDR_REG      ( RXBRP_BASEADDR + MDL_OFFSET + 0x0028 )

    #define MDL_RAKE_EMI_BUF_SIZE_REG           ( RAKE_BASEADDR + MDL_OFFSET + 0x0020 )
    #define MDL_RAKE_EMI_BUF_BASE_ADDR_REG      ( RAKE_BASEADDR + MDL_OFFSET + 0x0024 )
    #define MDL_RAKE_EMI_BUF_START_ADDR_REG     ( RAKE_BASEADDR + MDL_OFFSET + 0x0028 )

    #define MDL_ICC_EMI_BUF_SIZE_REG            ( ICC_BASEADDR + 0x0020 )
    #define MDL_ICC_EMI_BUF_BASE_ADDR_REG       ( ICC_BASEADDR + 0x0024 )
    #define MDL_ICC_EMI_BUF_START_ADDR_REG      ( ICC_BASEADDR + 0x0028 )

    #define MDL_IMC_EMI_BUF_SIZE_REG            ( IMC_BASEADDR + 0x0020 )
    #define MDL_IMC_EMI_BUF_BASE_ADDR_REG       ( IMC_BASEADDR + 0x0024 )
    #define MDL_IMC_EMI_BUF_START_ADDR_REG      ( IMC_BASEADDR + 0x0028 )

    #define MDL_MPC_EMI_BUF_SIZE_REG            ( MPC_BASEADDR + 0x0020 )
    #define MDL_MPC_EMI_BUF_BASE_ADDR_REG       ( MPC_BASEADDR + 0x0024 )
    #define MDL_MPC_EMI_BUF_START_ADDR_REG      ( MPC_BASEADDR + 0x0028 )    
    
    //////////DFE////////////
    #define MDL_SET_DFE_EMI_BUF_SIZE(SIZE) do{ \
                *((volatile kal_uint32*) (MDL_DFE_EMI_BUF_SIZE_REG)) = (SIZE) ;\
            }while(0)
            
    #define MDL_SET_DFE_EMI_BASE_ADDR(ADDR) do{ \
                *((volatile kal_uint32*) (MDL_DFE_EMI_BUF_BASE_ADDR_REG)) = (ADDR) ;\
            }while(0)   
    
    #define MDL_SET_DFE_EMI_START_ADDR(ADDR) do{ \
                *((volatile kal_uint32*) (MDL_DFE_EMI_BUF_START_ADDR_REG)) = (ADDR) ;\
            }while(0)   

    //////////RAKE////////////
    #define MDL_SET_RAKE_EMI_BUF_SIZE(SIZE) do{ \
			*((volatile kal_uint32*) (MDL_RAKE_EMI_BUF_SIZE_REG)) = (SIZE) ;\
		}while(0)
		
    #define MDL_SET_RAKE_EMI_BASE_ADDR(ADDR) do{ \
			*((volatile kal_uint32*) (MDL_RAKE_EMI_BUF_BASE_ADDR_REG)) = (ADDR) ;\
		}while(0)	

    #define MDL_SET_RAKE_EMI_START_ADDR(ADDR) do{ \
			*((volatile kal_uint32*) (MDL_RAKE_EMI_BUF_START_ADDR_REG)) = (ADDR) ;\
		}while(0)	
		
    //////////BRP////////////
    #define MDL_SET_BRP_EMI_BUF_SIZE(SIZE) do{ \
			*((volatile kal_uint32*) (MDL_BRP_EMI_BUF_SIZE_REG)) = (SIZE) ;\
		}while(0)
		
    #define MDL_SET_BRP_EMI_BASE_ADDR(ADDR) do{ \
			*((volatile kal_uint32*) (MDL_BRP_EMI_BUF_BASE_ADDR_REG)) = (ADDR) ;\
		}while(0)	

    #define MDL_SET_BRP_EMI_START_ADDR(ADDR) do{ \
			*((volatile kal_uint32*) (MDL_BRP_EMI_BUF_START_ADDR_REG)) = (ADDR) ;\
		}while(0)	


    //////////ICC////////////
    #define MDL_SET_ICC_EMI_BUF_SIZE(SIZE) do{ \
			*((volatile kal_uint32*) (MDL_ICC_EMI_BUF_SIZE_REG)) = (SIZE) ;\
		}while(0)
		
    #define MDL_SET_ICC_EMI_BASE_ADDR(ADDR) do{ \
			*((volatile kal_uint32*) (MDL_ICC_EMI_BUF_BASE_ADDR_REG)) = (ADDR) ;\
		}while(0)	

    #define MDL_SET_ICC_EMI_START_ADDR(ADDR) do{ \
			*((volatile kal_uint32*) (MDL_ICC_EMI_BUF_START_ADDR_REG)) = (ADDR) ;\
		}while(0)

    //////////IMC////////////
    #define MDL_SET_IMC_EMI_BUF_SIZE(SIZE) do{ \
			*((volatile kal_uint32*) (MDL_IMC_EMI_BUF_SIZE_REG)) = (SIZE) ;\
		}while(0)
		
    #define MDL_SET_IMC_EMI_BASE_ADDR(ADDR) do{ \
			*((volatile kal_uint32*) (MDL_IMC_EMI_BUF_BASE_ADDR_REG)) = (ADDR) ;\
		}while(0)	

    #define MDL_SET_IMC_EMI_START_ADDR(ADDR) do{ \
			*((volatile kal_uint32*) (MDL_IMC_EMI_BUF_START_ADDR_REG)) = (ADDR) ;\
		}while(0)

    //////////MPC////////////
    #define MDL_SET_MPC_EMI_BUF_SIZE(SIZE) do{ \
			*((volatile kal_uint32*) (MDL_MPC_EMI_BUF_SIZE_REG)) = (SIZE) ;\
		}while(0)
		
    #define MDL_SET_MPC_EMI_BASE_ADDR(ADDR) do{ \
			*((volatile kal_uint32*) (MDL_MPC_EMI_BUF_BASE_ADDR_REG)) = (ADDR) ;\
		}while(0)	

    #define MDL_SET_MPC_EMI_START_ADDR(ADDR) do{ \
			*((volatile kal_uint32*) (MDL_MPC_EMI_BUF_START_ADDR_REG)) = (ADDR) ;\
		}while(0)
		
    //Filter Setting///////////////////////////////////////
    
    #define __MDL_FILTER_INFO_SET_FILTER__    (0x1)  //Only write in MCU side
    
    #define get_cr(ADDR)        (*((volatile unsigned int*) (ADDR)))
    #define set_cr(ADDR, VALUE) (*((volatile unsigned int*) (ADDR)) = (VALUE))  
    #define MDL_SET_FILTER_SET_FLAG_CMIF(ADDR) do{ \
                set_cr(ADDR+MDL_XXIF_MDL_FILTER_FLAG_OFFSET, (unsigned int)(get_cr(ADDR+MDL_XXIF_MDL_FILTER_FLAG_OFFSET) | (__MDL_FILTER_INFO_SET_FILTER__) ));\
            }while(0)
    #define MDL_SET_FILTER_SET_FLAG_CSIF(ADDR) do{ \
                set_cr(ADDR, (unsigned int)(get_cr(ADDR) | (__MDL_FILTER_INFO_SET_FILTER__) ));\
            }while(0)

    //#else //#if defined(MT6291)

    //    #error "Non-supported platform"

    //#endif  //#if defined(MT6291)

///////Willie: For Multi-core logging/////////////

	void MdlDummyref();
	unsigned int get_core_baseaddr(mdl_core_enum core);

#if defined(__PCORE__)

    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_dfe, (MDL_LOGGING_BUF_SIZE_DFE/4))
    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_rake, (MDL_LOGGING_BUF_SIZE_RAKE/4))
    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_brp, (MDL_LOGGING_BUF_SIZE_BRP/4))
    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_icc, (MDL_LOGGING_BUF_SIZE_ICC/4))
    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_imc, (MDL_LOGGING_BUF_SIZE_IMC/4))
    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_mpc, (MDL_LOGGING_BUF_SIZE_MPC/4))

    #define g_mdl_logging_buf_dfe       SHARED_ARRAY(mdl_logging_buf_dfe)
    #define g_mdl_logging_buf_rake      SHARED_ARRAY(mdl_logging_buf_rake)
    #define g_mdl_logging_buf_brp       SHARED_ARRAY(mdl_logging_buf_brp)
    #define g_mdl_logging_buf_icc       SHARED_ARRAY(mdl_logging_buf_icc)
    #define g_mdl_logging_buf_imc       SHARED_ARRAY(mdl_logging_buf_imc)
    #define g_mdl_logging_buf_mpc       SHARED_ARRAY(mdl_logging_buf_mpc)

    extern volatile unsigned int g_mdl_logging_buf_dfe_ptr;
    extern volatile unsigned int g_mdl_logging_buf_rake_ptr;
    extern volatile unsigned int g_mdl_logging_buf_brp_ptr;
    extern volatile unsigned int g_mdl_logging_buf_icc_ptr;
    extern volatile unsigned int g_mdl_logging_buf_imc_ptr;
    extern volatile unsigned int g_mdl_logging_buf_mpc_ptr;    

    extern volatile unsigned int g_mdl_logging_buf_dfe_size;
    extern volatile unsigned int g_mdl_logging_buf_rake_size;
    extern volatile unsigned int g_mdl_logging_buf_brp_size;
    extern volatile unsigned int g_mdl_logging_buf_icc_size;
    extern volatile unsigned int g_mdl_logging_buf_imc_size;
    extern volatile unsigned int g_mdl_logging_buf_mpc_size;    
    
#elif defined(__L1CORE__)

    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_dfe, (MDL_LOGGING_BUF_SIZE_DFE/4))
    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_rake, (MDL_LOGGING_BUF_SIZE_RAKE/4))
    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_brp, (MDL_LOGGING_BUF_SIZE_BRP/4))
    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_icc, (MDL_LOGGING_BUF_SIZE_ICC/4))
    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_imc, (MDL_LOGGING_BUF_SIZE_IMC/4))
    DECLARE_SHARED_ARRAY(kal_uint32, mdl_logging_buf_mpc, (MDL_LOGGING_BUF_SIZE_MPC/4))
    
    #define g_mdl_logging_buf_dfe       SHARED_ARRAY(mdl_logging_buf_dfe)
    #define g_mdl_logging_buf_rake      SHARED_ARRAY(mdl_logging_buf_rake)
    #define g_mdl_logging_buf_brp       SHARED_ARRAY(mdl_logging_buf_brp)
    #define g_mdl_logging_buf_icc       SHARED_ARRAY(mdl_logging_buf_icc)
    #define g_mdl_logging_buf_imc       SHARED_ARRAY(mdl_logging_buf_imc)
    #define g_mdl_logging_buf_mpc       SHARED_ARRAY(mdl_logging_buf_mpc)

    extern volatile unsigned int g_mdl_logging_buf_dfe_ptr;
    extern volatile unsigned int g_mdl_logging_buf_rake_ptr;
    extern volatile unsigned int g_mdl_logging_buf_brp_ptr;
    extern volatile unsigned int g_mdl_logging_buf_icc_ptr;
    extern volatile unsigned int g_mdl_logging_buf_imc_ptr;
    extern volatile unsigned int g_mdl_logging_buf_mpc_ptr;    

    extern volatile unsigned int g_mdl_logging_buf_dfe_size;
    extern volatile unsigned int g_mdl_logging_buf_rake_size;
    extern volatile unsigned int g_mdl_logging_buf_brp_size;
    extern volatile unsigned int g_mdl_logging_buf_icc_size;
    extern volatile unsigned int g_mdl_logging_buf_imc_size;
    extern volatile unsigned int g_mdl_logging_buf_mpc_size;  
    
#endif //#if defined(__PCORE__)

#if defined(__PCORE__)

    typedef struct 
    {
        kal_uint32 *buf_addr;
        kal_uint32 buf_size;
        kal_uint32 id;    
        kal_uint8 enable;
    } MdlConfigStruct_t;

    mdl_xxif_info_error_code MdlGetXXifInfo(mdl_core_enum core, kal_uint32 *buffer_size, kal_uint32 *base_addr, kal_uint32 *write_ptr );
    mdl_xxif_info_error_code MdlGetXXifWrap(mdl_core_enum core, kal_uint8 *mdl_emi_buffer_wrapped);

    #define MDL_LOGGING_CHANNEL_NUM   (EBC_CH_NUM)

    extern MdlConfigStruct_t g_mdl_config[EBC_CH_NUM];   
    extern void MdlLoggingInitByCore(mdl_core_enum core);    
    extern void MdlLoggingInit(int mode);

    kal_uint32 MdlMemoryDumpInit();
    void mdl_print_memory_dump_info();

#elif defined(__L1CORE__)

    /* copy from ebc driver include file
    kal_uint32 MDL_DFE:  1; //ch id = 0
    kal_uint32 MDL_RAKE: 1; //ch id = 1
    kal_uint32 MDL_RXBRP:1; //ch id = 2
    kal_uint32 MDL_CMP:  1; //ch id = 3
    kal_uint32 MDL_IMC:  1; //ch id = 4
    kal_uint32 MDL_ICC:  1; //ch id = 5
    kal_uint32 MDP_CMP:  1; //ch id = 6
    kal_uint32 MDP_IMC:  1; //ch id = 7
    kal_uint32 MDP_ICC:  1; //ch id = 8
    kal_uint32 MTOL_CMP: 1; //ch id = 9
    kal_uint32 MTOL_IMC: 1; //ch id = 10
    kal_uint32 MTOL_ICC: 1; //ch id = 11
    */
   
    //Filter Setting:
    #define MAX_MODULE_ID_NUM (64)
    #define PRINT_SLAVE_FILTER_AND_ACCESS_CXIF_COUNTDOWN_NUM (4)

    typedef struct
    {
        kal_uint8 available;
        kal_uint8 filter;
    }mdl_set_filter_str;

    void MdlSetFilter(dhl_cmd_set_mdl_filter_struct *mdl_filter_struct);
    void MdlSetFilterOnCmif(kal_uint32 xxif_baseaddr, mdl_set_filter_str filter_buf[MAX_MODULE_ID_NUM]);
    void MdlSetFilterOnCsif(mdl_core_enum core, mdl_set_filter_str filter_buf[MAX_MODULE_ID_NUM]);
    void PrintSlaveFilterSetting();
    void PrintCxifValue();	
    void PrintCxifValueByCore(mdl_core_enum core);
    void SendMdlCxifIlm();

    //Please call this function before ungating DSP!
    //(But DSP needs to be powered-on first!)
    //Mode: 
    //     3G(UL1): 3
    //     4G(EL1): 4
    void MdlLoggingInit(int mode);
    void MdlCmifFirstInit
        ( kal_uint32 xxif_baseaddr, kal_uint32 buf_addr, kal_uint32 buf_start_addr, 
          kal_uint32 buf_size, kal_uint8 buf0_full, kal_uint8 buf1_full, 
          kal_uint8 set_all_filter_on, kal_uint8 output_to_emi, kal_uint8 emi_streaming_mode);
    void MdlCsifFirstInit
    ( mdl_core_enum core, kal_uint32 buf_addr, kal_uint32 buf_start_addr, 
      kal_uint32 buf_size, kal_uint8 buf0_full, kal_uint8 buf1_full, 
      kal_uint8 set_all_filter_on, kal_uint8 output_to_emi, kal_uint8 emi_streaming_mode);

    void MdlSetFilterAllOnCmif(kal_uint32 xxif_baseaddr);
    void MdlSetFilterAllOnCsif(mdl_core_enum core);
    
    void MdlSetLoggingNormalMode3G();
    void MdlSetLoggingBufDumpMode3G();  
    void MdlSetLoggingNormalMode4G();
    void MdlSetLoggingBufDumpMode4G();      
    void MdlLoggingInitDhl();
    void MdlLoggingInit();
    void MdlLoggingInitByCore(mdl_core_enum core);    
    void MdlSetLoggingBufDumpModeByCore(mdl_core_enum core);
    void MdlSetLoggingNormalModeByCore(mdl_core_enum core);    
    void MdlSetFilterAgainByCore(mdl_core_enum core);
    void MdlSetFilterAgain();
    kal_bool CheckMdlInitDone(mdl_core_enum core_id);
    void MdlSetSingleCoreFilter(mdl_memory_type type, mdl_core_enum core, kal_uint8 mod_num, mdl_log_filter_struct *cfg, kal_uint32 xxif_baseaddr);

#if defined(MT6755) || defined(MT6797) || defined(MT6757)
    kal_bool CheckMdlEnterIdle();
    kal_bool CheckMdlEnterIdleByCore(mdl_core_enum core_id);
#endif

#endif //#if defined(__L1CORE__)

#else //#if defined(__MTK_TARGET__)

#if defined(__L1CORE__)
    void MdlLoggingInit(int mode);
#endif  //#if defined(__L1CORE__)

#endif //#if defined(__MTK_TARGET__)

#endif //_MDL_LOGGING_H_


