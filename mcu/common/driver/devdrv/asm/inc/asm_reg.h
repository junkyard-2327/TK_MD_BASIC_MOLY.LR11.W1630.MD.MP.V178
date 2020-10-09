/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * asm_reg.h
 *
 * Project:
 * --------
 *   UMOLY_Software
 *
 * Description:
 * ------------
 *   This file defines ASM drivers register
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __ASM_REG_H__
#define __ASM_REG_H__

#include "kal_general_types.h"
#include "reg_base.h"  
#include "irqid.h"


#if defined(__PCORE__)
  #define ASM_BASEADDR_DEV                 (BASE_ADDR_MDASM)
  #define ASM_BASEADDR_SO                  (BASE_MADDR_MDASM)
  #define ASM_IRQID                        PS_IRQID_ADOE
  #define ASM_L12PS_IRQID                  PS_IRQID_L1_ADOE_INT
#else
  #define ASM_BASEADDR_DEV                 (L1_BASE_ADDR_ASM)
  #define ASM_BASEADDR_SO                  (L1_BASE_MADDR_ASM)
  #define ASM_IRQID                        L1_ADOE_INT_B
#endif  // __PCORE__



typedef enum {
    ASM_STATE_DORMANT = 0,
    ASM_STATE_DCM,
    ASM_STATE_STOP,
    ASM_STATE_START,
    
}MALMO_ASM_STATE;

typedef enum {
    ASM_BUF_BASE = 0,
    ASM_BUF_SIZE,
    ASM_BUF_RD_REG,
    ASM_BUF_WR_REG,
    ASM_BUF_INFOR_READY,
    ASM_BUF_RD_PTR,
    ASM_BUF_WR_PTR,
    ASM_STATE,
    
}MALMO_ASM_INFOR;

typedef struct _ASM_BUF_INFO_STRUCT {
    
    kal_uint32   buf_base_address;
    kal_uint32   buf_size;
    kal_uint32   buf_read_ptr_reg;
    kal_uint32   buf_write_ptr_reg;
    kal_uint32   init_ready_fg;
    kal_uint32   buf_read_ptr;
    kal_uint32   buf_write_ptr;

} ASM_BUF_INFO_STRUCT;


typedef struct _ASM_STRUCT {
    kal_uint32   asm_mode;
    kal_uint32   gen_enable;
    kal_uint32   mode_config;
    
    kal_uint32   buf_base_address;
    kal_uint32   buf_size;
    kal_uint32   buf_read_ptr;
    kal_uint32   buf_write_ptr;
    
    kal_uint32   sram_read_ptr;
    kal_uint32   sram_write_ptr;
    kal_uint32   config_write_buffer_ptr;
    kal_uint32   sram_target_getout_ptr;
    kal_uint32   sram_saved_target_ptr;
    kal_uint32   sram_curr_ptr;
    
    
    kal_uint32   bus_mon_range_0_start;
    kal_uint32   bus_mon_range_0_end;
    kal_uint32   bus_mon_range_1_start;
    kal_uint32   bus_mon_range_1_end;
    kal_uint32   bus_mon_range_2_start;
    kal_uint32   bus_mon_range_2_end;
    kal_uint32   bus_mon_range_3_start;
    kal_uint32   bus_mon_range_3_end;
    
    kal_uint32   profile_en;
    kal_uint32   addon[12];
    
    kal_uint32   sample_rate;

    kal_uint32   int_en;
    kal_uint32   thresh_value;
    kal_uint32   asm_is_enabled;
    kal_uint32   trigger_cnt;
    kal_uint32   spm_set;
    kal_uint32   dcm_set;
    
} ASM_STRUCT;

//////////////////ASM Registers/////////////////////////////

#define ASM_GEN_CONFIG			              ( ASM_BASEADDR_SO  + 0x0000 )
#define ASM_MODE_CONFIG			              ( ASM_BASEADDR_DEV + 0x0004 )
#define ASM_SRAM_FLUSH_TRIG		              ( ASM_BASEADDR_DEV + 0x0008 )
#define ASM_SRAM_MAX_BUF_SIZE                 ( ASM_BASEADDR_DEV + 0x000C )
                                              
#define ASM_BUSY_STATE			              ( ASM_BASEADDR_DEV + 0x001C )
#define ASM_SWLA_TRIG   		              ( ASM_BASEADDR_SO  + 0x0020 )
#define ASM_SWLA_TRACER_SYNC_HEADER_0_ADDR	  ( ASM_BASEADDR_DEV + 0x0024 )
#define ASM_SWLA_TRACER_SYNC_HEADER_1_ADDR	  ( ASM_BASEADDR_DEV + 0x0028 )
                                              
#define ASM_SYNC_TRIG			              ( ASM_BASEADDR_DEV + 0x0030 )
#define ASM_SYNC_PATTERN_ADDR                 ( ASM_BASEADDR_DEV + 0x0034 )
#define ASM_SYNC_HEADER_ADDR	              ( ASM_BASEADDR_DEV + 0x0038 )
                                              
#define ASM_TRACER_SAMPLE_RATE	              ( ASM_BASEADDR_DEV + 0x0040 )
#ifndef TK6291                                   
#define ASM_TRACER_CONFIG	                  ( ASM_BASEADDR_DEV + 0x0044 )
#endif  //TK6291                                
                                              
#ifndef TK6291                                   
#define ASM_PROFILE_EN			              ( ASM_BASEADDR_DEV + 0x0060 )
                                              
#define ASM_PROFILE_ADDON_INFO0	              ( ASM_BASEADDR_DEV + 0x0064 )
#define ASM_PROFILE_ADDON_INFO1	              ( ASM_BASEADDR_DEV + 0x0068 )
#define ASM_PROFILE_ADDON_INFO2	              ( ASM_BASEADDR_DEV + 0x006C )
#define ASM_PROFILE_ADDON_INFO3               ( ASM_BASEADDR_DEV + 0x0070 )
#define ASM_PROFILE_ADDON_INFO4	              ( ASM_BASEADDR_DEV + 0x0074 )
#define ASM_PROFILE_ADDON_INFO5	              ( ASM_BASEADDR_DEV + 0x0078 )
#define ASM_PROFILE_ADDON_INFO6	              ( ASM_BASEADDR_DEV + 0x007C )
#define ASM_PROFILE_ADDON_INFO7               ( ASM_BASEADDR_DEV + 0x0080 )
#define ASM_PROFILE_ADDON_INFO8	              ( ASM_BASEADDR_DEV + 0x0084 )
#define ASM_PROFILE_ADDON_INFO9	              ( ASM_BASEADDR_DEV + 0x008C )
#define ASM_PROFILE_ADDON_INFO10              ( ASM_BASEADDR_DEV + 0x0090 )
#define ASM_PROFILE_ADDON_INFO11              ( ASM_BASEADDR_DEV + 0x0094 )
#define ASM_MON_TRANS_PER_PKT	              ( ASM_BASEADDR_DEV + 0x009C )
                                              
#define ASM_MON_RANGE_START_0	              ( ASM_BASEADDR_DEV + 0x00A0 )
#define ASM_MON_RANGE_END_0 	              ( ASM_BASEADDR_DEV + 0x00A4 )
#define ASM_MON_RANGE_START_1                 ( ASM_BASEADDR_DEV + 0x00A8 )
#define ASM_MON_RANGE_END_1  	              ( ASM_BASEADDR_DEV + 0x00AC )
#define ASM_MON_RANGE_START_2	              ( ASM_BASEADDR_DEV + 0x00B0 )
#define ASM_MON_RANGE_END_2		              ( ASM_BASEADDR_DEV + 0x00B4 )
#define ASM_MON_RANGE_START_3	              ( ASM_BASEADDR_DEV + 0x00B8 )
#define ASM_MON_RANGE_END_3		              ( ASM_BASEADDR_DEV + 0x00BC )
#define ASM_MON_HEADER 		                  ( ASM_BASEADDR_DEV + 0x00C0 )
#define ASM_MON_HEADER1		                  ( ASM_BASEADDR_DEV + 0x00C4 )
                                              
#else                                         
                                              
#define ASM_PROFILE_EN	                      ( ASM_BASEADDR_DEV + 0x0060 )
#define ASM_PROFILE_ADDON_INFO0	              ( ASM_BASEADDR_DEV + 0x0064 )
#define ASM_PROFILE_ADDON_INFO1	              ( ASM_BASEADDR_DEV + 0x0068 )
#define ASM_PROFILE_ADDON_INFO2	              ( ASM_BASEADDR_DEV + 0x006C )
#define ASM_PROFILE_ADDON_INFO3	              ( ASM_BASEADDR_DEV + 0x0070 )
#define ASM_PROFILE_ADDON_INFO4	              ( ASM_BASEADDR_DEV + 0x0074 )
#define ASM_PROFILE_ADDON_INFO5	              ( ASM_BASEADDR_DEV + 0x0078 )
#define ASM_PROFILE_ADDON_INFO6	              ( ASM_BASEADDR_DEV + 0x007C )
#define ASM_PROFILE_ADDON_INFO7	              ( ASM_BASEADDR_DEV + 0x0080 )
#define ASM_PROFILE_ADDON_INFO8	              ( ASM_BASEADDR_DEV + 0x0084 )
#define ASM_PROFILE_ADDON_INFO9	              ( ASM_BASEADDR_DEV + 0x008C )
#define ASM_PROFILE_ADDON_INFO10	          ( ASM_BASEADDR_DEV + 0x0090 )
#define ASM_PROFILE_ADDON_INFO11	          ( ASM_BASEADDR_DEV + 0x0094 )
#define ASM_MON_TRANS_PER_PKT	              ( ASM_BASEADDR_DEV + 0x009C )
                                                               
#define ASM_MON_RANGE_START_0	              ( ASM_BASEADDR_DEV + 0x00A0 )
#define ASM_MON_RANGE_END_0	                  ( ASM_BASEADDR_DEV + 0x00A4 )
#define ASM_MON_RANGE_START_1	              ( ASM_BASEADDR_DEV + 0x00A8 )
#define ASM_MON_RANGE_END_1	                  ( ASM_BASEADDR_DEV + 0x00C0 )
#define ASM_MON_RANGE_START_2	              ( ASM_BASEADDR_DEV + 0x00C4 )
#define ASM_MON_RANGE_END_2	                  ( ASM_BASEADDR_DEV + 0x00E0 )
#define ASM_MON_RANGE_START_3	              ( ASM_BASEADDR_DEV + 0x00E4 )
#define ASM_MON_RANGE_END_3	                  ( ASM_BASEADDR_DEV + 0x00E8 )
#define ASM_MON_HEADER 		                  ( ASM_BASEADDR_DEV + 0x0100 )
#define ASM_MON_HEADER1		                  ( ASM_BASEADDR_DEV + 0x0104 )
#endif  //TK6291



#define ASM_LOG_BUF_BASEADDR	              ( ASM_BASEADDR_DEV + 0x0108 )
#define ASM_LOG_BUF_SIZE		              ( ASM_BASEADDR_DEV + 0x010C )

#define ASM_PDI_HEADER_0   		              ( ASM_BASEADDR_DEV + 0x0110 )
#define ASM_PDI_HEADER_1   		              ( ASM_BASEADDR_DEV + 0x0114 )
#define ASM_PDI_CNT   		                  ( ASM_BASEADDR_DEV + 0x0118 )
                                            
#define ASM_ETM_MCU_PC_ADDR		              ( ASM_BASEADDR_DEV + 0x011C )
#define ASM_ETM_CONTEXT_ID		              ( ASM_BASEADDR_DEV + 0x0120 )

#define ASM_PMU_PMC0			              ( ASM_BASEADDR_DEV + 0x0124 )
#define ASM_PMU_PMC1			              ( ASM_BASEADDR_DEV + 0x0128 )
#define ASM_PMU_PMC2			              ( ASM_BASEADDR_DEV + 0x0180 )
#define ASM_PMU_CYCLE_COUNTER	              ( ASM_BASEADDR_DEV + 0x0184 )

#define ASM_EMI_BCNT			              ( ASM_BASEADDR_DEV + 0x0188 )
#define ASM_EMI_BACT			              ( ASM_BASEADDR_DEV + 0x018C )
#define ASM_EMI_BSCT			              ( ASM_BASEADDR_DEV + 0x0190 )
#define ASM_EMI_BSCT2			              ( ASM_BASEADDR_DEV + 0x0194 )
#define ASM_EMI_BSCT3			              ( ASM_BASEADDR_DEV + 0x0198 )
#define ASM_DBG1	                          ( ASM_BASEADDR_DEV + 0x019C )
#define ASM_DBG2	                          ( ASM_BASEADDR_DEV + 0x01A0 )
#define ASM_DBG3	                          ( ASM_BASEADDR_DEV + 0x01A4 )
#define ASM_DBG4	                          ( ASM_BASEADDR_DEV + 0x01A8 )
#define ASM_DBG5	                          ( ASM_BASEADDR_DEV + 0x01AC )
#define ASM_DBG6	                          ( ASM_BASEADDR_DEV + 0x01B0 )
#define ASM_DBG7	                          ( ASM_BASEADDR_DEV + 0x01B4 )
#define ASM_DBG8	                          ( ASM_BASEADDR_DEV + 0x01B8 )
#define ASM_DBG9	                          ( ASM_BASEADDR_DEV + 0x01BC )


#ifndef TK6291                                   
                                                    
#define ASM_DBG10	                          ( ASM_BASEADDR_DEV + 0x01C0 )
#define ASM_DBG11	                          ( ASM_BASEADDR_DEV + 0x01C4 )
#define ASM_VERSION	                          ( ASM_BASEADDR_DEV + 0x01C8 )
#define ASM_SRAM_WPTR						  ( ASM_BASEADDR_DEV + 0x01CC )
#define ASM_SRAM_RPTR						  ( ASM_BASEADDR_DEV + 0x01D0 )
#define ASM_SPM_CONFIG						  ( ASM_BASEADDR_DEV + 0x01D4 )
#define ASM_WR_BUF_PTR						  ( ASM_BASEADDR_DEV + 0x01D8 )
#define ASM_TARGET_GETOUT_SRAM				  ( ASM_BASEADDR_DEV + 0x01DC )
#define ASM_SAVED_TAR_SRAM_PTR				  ( ASM_BASEADDR_DEV + 0x01E0 )
#define ASM_CURR_SRAM_PTR					  ( ASM_BASEADDR_DEV + 0x01E4 )
#define ASM_SRAM_DBG_ADDR					  ( ASM_BASEADDR_DEV + 0x0200 )
#define ASM_SRAM_DBG_DATA					  ( ASM_BASEADDR_DEV + 0x0204 )
#define ASM_RD_PTR                            ( ASM_BASEADDR_DEV + 0x0208 )
#define ASM_WR_PTR      					  ( ASM_BASEADDR_DEV + 0x020C )
#define ASM_BUF_ALT_TH           			  ( ASM_BASEADDR_DEV + 0x0210 )
#define ASM_INT_EN							  ( ASM_BASEADDR_DEV + 0x0214 )
#define ASM_REM_LOG_BUF_SIZE				  ( ASM_BASEADDR_DEV + 0x0218 )
#define ASM_RAW_LOSTHEADER                    ( ASM_BASEADDR_DEV + 0x0220 )
#else

#define ASM_VERSION	                       	  ( ASM_BASEADDR_DEV + 0x01C0 )
                                                                   
#define ASM_SRAM_WPTR						  ( ASM_BASEADDR_DEV + 0x01C4 )
#define ASM_SRAM_RPTR						  ( ASM_BASEADDR_DEV + 0x01C8 )
#define ASM_SPM_CONFIG						  ( ASM_BASEADDR_DEV + 0x01CC )
#define ASM_WR_BUF_PTR						  ( ASM_BASEADDR_DEV + 0x01D0 )
#define ASM_TARGET_GETOUT_SRAM				  ( ASM_BASEADDR_DEV + 0x01D4 )
#define ASM_SAVED_TAR_SRAM_PTR				  ( ASM_BASEADDR_DEV + 0x01D8 )
#define ASM_CURR_SRAM_PTR					  ( ASM_BASEADDR_DEV + 0x01DC )
#define ASM_SRAM_DBG_ADDR					  ( ASM_BASEADDR_DEV + 0x01E0 )
#define ASM_SRAM_DBG_DATA					  ( ASM_BASEADDR_DEV + 0x01E4 )
                                                                   
#define ASM_RD_PTR   					      ( ASM_BASEADDR_DEV + 0x0200 )
#define ASM_WR_PTR  					      ( ASM_BASEADDR_DEV + 0x0204 )
#define ASM_BUF_ALT_TH                        ( ASM_BASEADDR_DEV + 0x0208 )
#define ASM_INT_EN							  ( ASM_BASEADDR_DEV + 0x020C )
#define ASM_REM_LOG_BUF_SIZE				  ( ASM_BASEADDR_DEV + 0x0210 )

#endif  //TK6291


#define MALMO_ASM_EXTRA_INFO_NUM              (12) //extra info(addon)
#define ASM_MAX_BUF_BIT_LEN                   (16)

#define MALMO_ASM_ERR_CODE_ERROR              (0)
#define MALMO_ASM_ERR_CODE_NO_ERROR           (1)


#define ASM_BUS_MONITOR_HEADER                (0x45D10000)
#define ASM_PDI_HEADER 				          (0x45D30000)
#define ASM_SYNC_HEADER 			          (0x45D50001)	//have to check 
#define ASM_HW_SWTR_HEADER         	          (0x45D60001)
#define ASM_HW_SWLA_HEADER 			          (0x45D70001)  
#define ASM_SRAM_SIZE_WORD 				      (256*1024)    //1MB
#define ASM_SRAM_FLUSH_TIMEOUT			      (0xFF)

#define ASM_HW_SWLA_MODE_CONFIG		          (0x00101)
#define ASM_HW_SWTR_MODE_CONFIG    	          (0x01111)
#define ASM_BUSMONITOR_MODE_CONFIG	          (0x10010)
#define ASM_WRAP_MODE_CONFIG	              (0x10000000)

#define ASM_HW_SWTR_SAMPLING_RATE_DUMMY          (0)
#define ASM_HW_SWTR_FILTER_DUMMY                 (0)

//ASM_GEN_CONFIG
#define ASM_ENABLE_BIT	                      0
#define ASM_DISABLE_BIT	                      1
#define ASM_RESET_BIT	                      4
#define ASM_PDI_BIT		                      8
#define ASM_WRAP_MODE_PDI_BIT                 9
#define ASM_ELM_BIT		                      12

#define ASM_ELM_MSK		                      ((1<< MALMO_ASM_ELM_CNT0)|(1 << MALMO_ASM_ELM_CNT1)|(1 << MALMO_ASM_ELM_CNT2)|(1 << MALMO_ASM_ELM_CNT3))

//ASM_SPM_CONFIG
#define ASM_SPM_REQ_BIT		                  0
#define ASM_SPM_GRANT_BIT	                  4
#define ASM_IDLE_BIT		                  12

 //Threshold value: unit is wrod(4 bytes), set 1/4 buffer size = 4x4 = 16
#define ASM_BUF_ALT_TH_VAL                    (16)   

//////////////////////////ASM Control Macro///////////////////////////////////
#define ASM_ENABLE(VAL) do{ \
		    *((volatile kal_uint32*) (ASM_GEN_CONFIG)) = (VAL|(1 << ASM_ENABLE_BIT));\
        }while(0)//;while(((*(volatile kal_uint32*) (ASM_GEN_CONFIG))&(1 << ASM_ENABLE_BIT)) != 1){}

#define ASM_DISABLE(VAL) do{ \
	        *((volatile kal_uint32*) (ASM_GEN_CONFIG)) = (VAL |(1 << ASM_DISABLE_BIT));\
        }while(0)


#define ASM_RESET do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) |= (1 << ASM_RESET_BIT) ;\
		}while(0)
		
#define ASM_PDI_ENABLE do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) |= (1 << ASM_PDI_BIT) ;\
		}while(0)

#define ASM_PDI_DISABLE do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) &= (~(1 << ASM_PDI_BIT)) ;\
		}while(0)

#define ASM_MONITOR_TIMER_ENABLE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) |= (0x10) ;\
		}while(0)

#define ASM_MONITOR_TIMER_DISABLE do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) &= (0xFFFFFFF0) ;\
		}while(0)
		
#define ASM_SET_MODE_TO_HW_SWLA_MODE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) = (ASM_HW_SWLA_MODE_CONFIG) ;\
		}while(0)

#define ASM_SET_MODE_TO_HW_SWTR_MODE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) = (ASM_HW_SWTR_MODE_CONFIG) ;\
		}while(0)

#define ASM_SET_MODE_TO_BUS_MONITOR_MODE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) = (ASM_BUSMONITOR_MODE_CONFIG) ;\
		}while(0)

#define ASM_SET_MODE_TO_WRAP_MODE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) = (ASM_WRAP_MODE_CONFIG) ;\
		}while(0)

#define ASM_SET_MODE(VAL) do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) = (VAL) ;\
		}while(0)

#define ASM_SET_MODE_TO_SYNC_PATTERN_OUTPUT_MODE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) &= (0xFFF0F0FF) ;\
		}while(0)

#define ASM_GET_ASM_BUSY_STATE(VAL) do{ \
      VAL = (*(volatile kal_uint32*) (ASM_BUSY_STATE)) ;\
    }while(0)


//Once you write out the SYNC PATTERN, the SYNC PACKET will be generated at once
#define ASM_SET_SYNC_PATTERN(VAL) do{ \
			*(volatile unsigned int*) (ASM_SYNC_PATTERN_ADDR) = (VAL) ;\
			ASM_POLL_BUSY;\
		}while(0)

#define ASM_SET_SYNC_HEADER(VAL) do{ \
			*(volatile unsigned int*) (ASM_SYNC_HEADER_ADDR) = (VAL) ;\
		}while(0)

#define ASM_SET_SRAM_FLUSH_TRIGGER do{ \
			*((volatile unsigned int*) (ASM_SRAM_FLUSH_TRIG)) = 1 ;\
			ASM_POLL_BUSY;\
		}while(0)
//The ASM auto-flush feature is not available
#define ASM_SET_SRAM_FLUSH_TIMEOUT(VAL) do{ \
			*(volatile unsigned int*) (ASM_MODE_CONFIG) &= ( 0x000FFFFF ) ;\
		}while(0)		

#define ASM_SET_SRAM_MAX_BUF_SIZE(VAL) do{ \
			*(volatile unsigned int*) (ASM_SRAM_MAX_BUF_SIZE) = (VAL) ;\
		}while(0)

//ASM HWLA
#define ASM_SET_HW_SWLA_TRIG do{ \
			*((volatile unsigned int*) (ASM_SWLA_TRIG)) = 1 ;\
		}while(0)

#define ASM_SET_HW_SWLA_AND_HW_SWTR_HEADER(VAL) do{ \
			*(volatile unsigned int*) (ASM_SWLA_TRACER_SYNC_HEADER_0_ADDR) = (VAL) ;\
		}while(0)

//ASM HWTR
#define ASM_SET_HW_SWTR_SAMPLING_RATE(VAL) do{ \
			*(volatile unsigned int*) (ASM_TRACER_SAMPLE_RATE) = (VAL) ;\
		}while(0)


#define ASM_SET_PROFILE_FILTER(VAL) do{                             \
			*(volatile unsigned int*) (ASM_PROFILE_EN) = (VAL) ;             \
		}while(0)

//ASM Extra Addon-info
#define ASM_SET_HW_MONITOR_EXTRA_ADDON_0(VAL) do{ \
			*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO0) = (VAL) ;\
		}while(0)

#define ASM_SET_HW_MONITOR_EXTRA_ADDON_1(VAL) do{ \
			*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO1) = (VAL) ;\
		}while(0)

#define ASM_SET_HW_MONITOR_EXTRA_ADDON_2(VAL) do{ \
			*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO2) = (VAL) ;\
		}while(0)

#define ASM_SET_HW_MONITOR_EXTRA_ADDON_3(VAL) do{ \
			*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO3) = (VAL) ;\
		}while(0)

//ASM Bus Monitor
#define ASM_SET_BUS_MONITOR_RAGE_0_START(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_START_0) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_0_END(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_END_0) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_1_START(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_START_1) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_1_END(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_END_1) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_2_START(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_START_2) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_2_END(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_END_2) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_3_START(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_START_3) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_3_END(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_END_3) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_HEADER(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_HEADER) = (VAL) ;\
		}while(0)

//ASM Logging Buffer
#define ASM_SET_LOG_BUF_BASEADDR(VAL) do{ \
			*(volatile unsigned int*) (ASM_LOG_BUF_BASEADDR) = (VAL) ;\
		}while(0)
////In KB
#define ASM_SET_LOG_BUF_SIZE(VAL) do{ \
			*(volatile unsigned int*) (ASM_LOG_BUF_SIZE) = (VAL) ;\
		}while(0)

//ASM PDI
#define ASM_SET_PDI_HEADER(VAL) do{ \
			*(volatile unsigned int*) (ASM_PDI_HEADER_0) = (VAL) ;\
		}while(0)

//ASM Debugging Info
#define ASM_GET_ETM_MCU_PC_ADDR(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_ETM_MCU_PC_ADDR)) ;\
		}while(0)

#define ASM_GET_ETM_CONTEX_ID(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_ETM_CONTEXT_ID)) ;\
		}while(0)

#define ASM_GET_PMU_PMC0(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PMU_PMC0)) ;\
		}while(0)

#define ASM_GET_PMU_PMC1(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PMU_PMC1)) ;\
		}while(0)

#define ASM_GET_PMU_PMC2(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PMU_PMC2)) ;\
		}while(0)

#define ASM_GET_PMU_CYCLE_COUNTER(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PMU_CYCLE_COUNTER)) ;\
		}while(0)

#define ASM_GET_EMI_BCNT(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_EMI_BCNT)) ;\
		}while(0)

#define ASM_GET_EMI_BACT(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_EMI_BACT)) ;\
		}while(0)

#define ASM_GET_EMI_BSCT(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_EMI_BSCT)) ;\
		}while(0)

#define ASM_GET_EMI_BSCT2(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_EMI_BSCT2)) ;\
		}while(0)

#define ASM_GET_EMI_BSCT3(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_EMI_BSCT3)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO0(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO0)) ;\
		}while(0)
		
#define ASM_GET_EXTRA_INFO1(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO1)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO2(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO2)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO3(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO3)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO4(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO4)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO5(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO5)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO6(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO6)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO7(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO7)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO8(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO8)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO9(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO9)) ;\
		}while(0)


#define ASM_GET_EXTRA_INFO10(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO10)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO11(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO11)) ;\
		}while(0)

#define ASM_GET_RD_PTR(PTR) do{ \
      PTR = (*(volatile kal_uint32*) (ASM_RD_PTR)) ;\
    }while(0)

//ASM Buffer read/write point
#define ASM_GET_WR_PTR(PTR) do{ \
      PTR = (*(volatile kal_uint32*) (ASM_WR_PTR)) ;\
    }while(0)

#define ASM_SET_WR_PTR(PTR) do{ \
      *(volatile kal_uint32*) (ASM_WR_PTR) = (PTR) ;\
    }while(0)
  
#define ASM_SET_RD_PTR(PTR) do{ \
      *(volatile kal_uint32*) (ASM_RD_PTR) = (PTR) ;\
    }while(0)

/*Save Buffer Read and Write pointer for Sleep*/
#define ASM_GET_WR_BUF_PTR(PTR) do{ \
      PTR = (*(volatile kal_uint32*) (ASM_WR_BUF_PTR)) ;\
    }while(0)

#define ASM_SET_WR_BUF_PTR(PTR) do{ \
      *(volatile kal_uint32*) (ASM_WR_BUF_PTR) = (PTR) ;\
    }while(0)


//ADOE_BUFFER_ALT_THRESHOLD
#define ASM_SET_BUFFER_ALT_THRESHOLD(VAL) do{ \
			*(volatile unsigned int*) (ASM_BUF_ALT_TH) = (VAL) ;\
		}while(0)

#define ASM_INT_ENABLE(VAL) do{ \
      *(volatile kal_uint32*) (ASM_INT_EN) = (VAL) ;\
    }while(0)
    
#define ASM_GET_IDLE(PTR) do{ \
      PTR = ((*(volatile kal_uint32*) (ASM_SPM_CONFIG))&(1 << ASM_IDLE_BIT)) ;\
    }while(0)

#define ASM_WAIT_FOR_IDLE 		while(((*(volatile kal_uint32*) (ASM_SPM_CONFIG))&(1 << ASM_IDLE_BIT)) == 0){}

    
/*SRAM Read and Write pointer*/
#define ASM_SRAM_GET_RD_PTR(PTR) do{ \
      PTR = (*(volatile kal_uint32*) (ASM_SRAM_RPTR)) ;\
    }while(0)

#define ASM_SRAM_GET_WR_PTR(PTR) do{ \
      PTR = (*(volatile kal_uint32*) (ASM_SRAM_WPTR)) ;\
    }while(0)

#define ASM_SRAM_SET_RD_PTR(PTR) do{ \
      *(volatile kal_uint32*) (ASM_SRAM_RPTR) = (PTR) ;\
    }while(0)
  
#define ASM_SRAM_SET_WR_PTR(PTR) do{ \
      *(volatile kal_uint32*) (ASM_SRAM_WPTR) = (PTR) ;\
    }while(0)
    
#define ASM_SRAM_GET_TARGET_GETOUT(PTR) do{ \
      PTR = (*(volatile kal_uint32*) (ASM_TARGET_GETOUT_SRAM)) ;\
    }while(0)
    
#define ASM_SRAM_SET_TARGET_GETOUT(PTR) do{ \
      *(volatile kal_uint32*) (ASM_TARGET_GETOUT_SRAM) = (PTR) ;\
    }while(0)

#define ASM_SRAM_GET_ASM_SAVED_TAR_SRAM_PTR(PTR) do{ \
      PTR = (*(volatile kal_uint32*) (ASM_SAVED_TAR_SRAM_PTR)) ;\
    }while(0)
    
#define ASM_SRAM_SET_ASM_SAVED_TAR_SRAM_PTR(PTR) do{ \
      *(volatile kal_uint32*) (ASM_SAVED_TAR_SRAM_PTR) = (PTR) ;\
    }while(0)
    
#define ASM_SRAM_GET_ASM_CURR_SRAM_PTR(PTR) do{ \
      PTR = (*(volatile kal_uint32*) (ASM_CURR_SRAM_PTR)) ;\
    }while(0)
    
#define ASM_SRAM_SET_ASM_CURR_SRAM_PTR(PTR) do{ \
      *(volatile kal_uint32*) (ASM_CURR_SRAM_PTR) = (PTR) ;\
    }while(0)

/*Sleep mode req and grant*/
#define ASM_SET_SPM_REQ() do{ \
      *(volatile kal_uint32*) (ASM_SPM_CONFIG) |= (1 << ASM_SPM_REQ_BIT) ;\
    }while(0)

#define ASM_GET_SPM_GRANT(PTR) do{ \
      PTR = ((*(volatile kal_uint32*) (ASM_SPM_CONFIG))&(1 << ASM_SPM_GRANT_BIT)) ;\
    }while(0)
    
#define ASM_WAIT_FOR_SPM_GRANT 	while(((*(volatile kal_uint32*) (ASM_SPM_CONFIG))&(1 << ASM_SPM_GRANT_BIT)) == 0){}

//////////////////ASM L1core Registers/////////////////////////////

#if defined(__PCORE__)
#define ASM_GET_L1_RD_PTR(PTR) do{ \
      PTR = (*(volatile kal_uint32*) (L1core_Asm_Buf_Info.buf_read_ptr_reg)) ;\
    }while(0)

#define ASM_GET_L1_WR_PTR(PTR) do{ \
      PTR = (*(volatile kal_uint32*) (L1core_Asm_Buf_Info.buf_write_ptr_reg)) ;\
    }while(0)

#define ASM_SET_L1_RD_PTR(PTR) do{ \
      *(volatile kal_uint32*) (L1core_Asm_Buf_Info.buf_read_ptr_reg) = (PTR) ;\
    }while(0)

#endif  //defined(__PCORE__)



#endif  //__ASM_REG_H__

