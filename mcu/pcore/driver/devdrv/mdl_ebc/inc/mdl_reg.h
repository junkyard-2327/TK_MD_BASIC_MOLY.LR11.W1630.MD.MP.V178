/*
 * mdl_reg.h
 *
 *  Created on: 2014/6/5
 *      Author: MTK07117
 */

#ifndef MDL_REG_H_
#define MDL_REG_H_

#include "kal_public_api.h"
// ===================== MDL register address ========================
#define MDL_HW_NUM		(6)
#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
#define MDL0_BASEADDR	(0xF7B40000) // DFE
#define MDL1_BASEADDR	(0xF9B40000) // RAKE
#define MDL2_BASEADDR	(0xF9340000) // RXBRP
#define MDL3_BASEADDR	(0xFD601700) // MPC
#define MDL4_BASEADDR	(0xFDE03F00) // IMC
#define MDL5_BASEADDR	(0xFEE01500) // ICC
#elif defined(TK6291)
#define MDL0_BASEADDR	(0xF7B40000) // DFE
#define MDL1_BASEADDR	(0xF9B40000) // RAKE
#define MDL2_BASEADDR	(0xF9340000) // RXBRP
#define MDL3_BASEADDR	(0xFD601700) // MPC
#define MDL4_BASEADDR	(0xFDE04100) // IMC
#define MDL5_BASEADDR	(0xFEE01300) // ICC
#else
#error
#endif // defined

//MDL Port
#define MDL_CSM_PORT(i)					( MDL##i##_BASEADDR + 0x0000 )
#define MDL_PREVCSM_PORT(i)				( MDL##i##_BASEADDR + 0x0004 )
#define MDL_DATA_PORT(i)				( MDL##i##_BASEADDR + 0x0008 )
#define MDL_DATA_16_PORT(i)				( MDL##i##_BASEADDR + 0x000C )
#define MDL_FRC_PORT(i)					( MDL##i##_BASEADDR + 0x0010 )
#define MDL_CC_PORT(i)					( MDL##i##_BASEADDR + 0x0014 )
#define MDL_SWIM_PORT(i)				( MDL##i##_BASEADDR + 0x0018 )
//EMI Related
#define MDL_EMI_BUF_SIZE_REG(i)			( MDL##i##_BASEADDR + 0x0020 )
#define MDL_EMI_BUF_BASE_ADDR_REG(i)	( MDL##i##_BASEADDR + 0x0024 )
#define MDL_EMI_BUF_START_ADDR_REG(i)	( MDL##i##_BASEADDR + 0x0028 )
//Configuration
#define MDL_CON0_BEFORE_START_REG(i)	( MDL##i##_BASEADDR + 0x002C )
#define MDL_CON1_BEFORE_START_REG(i)	( MDL##i##_BASEADDR + 0x0030 )
#define MDL_CON2_BEFORE_START_REG(i)	( MDL##i##_BASEADDR + 0x0034 )
#define MDL_CON_RUN_TIME_REG(i)			( MDL##i##_BASEADDR + 0x0038 )
#define MDL_STA_REG(i)					( MDL##i##_BASEADDR + 0x003C )
#define MDL_CSM_STACK_STA_REG(i)		( MDL##i##_BASEADDR + 0x0040 )
#define MDL_LBUF_STA_REG(i)				( MDL##i##_BASEADDR + 0x0044 )
#define MDL_OVF_STA_REG(i)				( MDL##i##_BASEADDR + 0x0048 )
//Debugging Register
#define MDL_LBUF_IN_VALUE_L_REG(i)		( MDL##i##_BASEADDR + 0x004C )
#define MDL_LBUF_IN_VALUE_H_REG(i)		( MDL##i##_BASEADDR + 0x0050 )
#define MDL_LBUF_RADDR_REG(i)			( MDL##i##_BASEADDR + 0x0054 )
#define MDL_LBUF_RDATA_REG(i)			( MDL##i##_BASEADDR + 0x0058 )
#define MDL_ERR_STAT_N_CON_REG(i)		( MDL##i##_BASEADDR + 0x005C )

// ============= define the register structure for MDL ===============
typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 CLKDIS:1;
		kal_uint32 START:1;
		kal_uint32 RESET:1;
		kal_uint32 OUT_TO_EMI:1;
		kal_uint32 AUTO_TEST_EN:1;
		kal_uint32 SWTR_FRC_EN:1;
		kal_uint32 SWTR_PC_EN:1;
		kal_uint32 SWTR_CSM_EN:1;
		kal_uint32 CSMC_EN:1;
		kal_uint32 CSMR_EN:1;
		kal_uint32 SWOV_EN:1;
		kal_uint32 HWCS_EN:1;
		kal_uint32 EMI_WRAP_EN:1;
		kal_uint32 RESERVE:19;
	};
}MDL_CON0_BS;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 SPECIAL_MARKER:16;
		kal_uint32 HWCS_CSM:8;
		kal_uint32 HWCS_CSM_DETDLY:3;
		kal_uint32 RESERVE:5;
	};
}MDL_CON1_BS;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 CC_STEP:4;
		kal_uint32 LBUF_UNLOCK_THS:2;
		kal_uint32 EMI_BUF_FULL_NONBUF:1;
		kal_uint32 EMI_BW_CON:2;
		kal_uint32 ATID:7;
		kal_uint32 RESERVE:16;
	};
}MDL_CON2_BS;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 EVENT_CTRL_SYNC_MASK:1;
		kal_uint32 LBUF_FLUSH:1;
		kal_uint32 LBUF_ABORT:1;
		kal_uint32 LBUF_FLUSH_ABORT_CLR:1;
		kal_uint32 SWTR_EN:1;
		kal_uint32 LBUF_OUT_DIS:1;
		kal_uint32 LBUF_UNLOCK:1;
		kal_uint32 CSM_STK_ERR_CLR:1;
		kal_uint32 OVF_DATA_DROP_NUM_CLR:1;
		kal_uint32 OVF_NUM_CLR:1;
		kal_uint32 DATA16_MERGE_ERR_CLR:1;
		kal_uint32 DATA_PORT_REPLACE:1;
		kal_uint32 BURST_BUF_REPLACE:1;
		kal_uint32 PORT_DIS:1;
		kal_uint32 RESERVE:10;
		kal_uint32 SWTR_PERIOD:8;
	};
}MDL_CON_RT;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 EMI_BUF0_FULL:1;
		kal_uint32 EMI_BUF1_FULL:1;
		kal_uint32 LBUF_FLASH_DONE:1;
		kal_uint32 LBUF_ABORT_DONE:1;
		kal_uint32 HWCS:1;
		kal_uint32 DATA16_MERGE_ERR:1;
		kal_uint32 EMI_BUF_WRAPPED:1;
		kal_uint32 EMI_BUF0_BUS:1;
		kal_uint32 EMI_BUF1_BUS:1;
		kal_uint32 RESERVE:23;
	};
}MDL_STA;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 CSM_USED_LEVEL:8;
		kal_uint32 CSM_MAX_USED_LEVEL:8;
		kal_uint32 CSM_TOP:8;
		kal_uint32 CSMR_OUT:1;
		kal_uint32 CSM_STK_OVERFLOW:1;
		kal_uint32 CSM_STK_UNDERFLOW:1;
		kal_uint32 RESERVE:5;
	};
}MDL_CSM_STA;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 LBUF_USED_SPACE:12;
		kal_uint32 LBUF_MAX_USED_SPACE:12;
		kal_uint32 LBUF_SIZE:2;
		kal_uint32 LBUF_FULL:1;
		kal_uint32 LBUF_LOCKED:1;
		kal_uint32 LBUF_CAN_UNLOCK:1;
		kal_uint32 RESERVE:3;
	};
}MDL_LBUF_STA;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 OVF_DATA_DROP_NUM:12;
		kal_uint32 OVF_NUM:4;
		kal_uint32 RESERVE:16;
	};
}MDL_OVF_STA;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 DATA16_MERGE_ERR:1;
		kal_uint32 CSM_STK_OVERFLOW:1;
		kal_uint32 CSM_STK_UNDERFLOW:1;
		kal_uint32 RESERVE1:2;
		kal_uint32 CONFLICT_HW_LBUF_RD:1;
		kal_uint32 CONFLICT_HW_PORT:1;
		kal_uint32 RESERVE2:1;
		kal_uint32 LB2BB_MON:8;
		kal_uint32 BBUF_MON:8;
		kal_uint32 LB2BB_MON_SEL:2;
		kal_uint32 BBUF_MON_SEL:2;
		kal_uint32 RESERVE3:3;
		kal_uint32 CLR_ERR:1;
	};
}MDL_ERR_STA;

typedef struct {
	// access port
	kal_uint32 	 CSM_PORT;			//0x00
	kal_uint32 	 PREVCSM_PORT;		//0x04
	kal_uint32 	 DATA_PORT;			//0x08
	kal_uint32 	 DATA16_PORT;		//0x0C
	kal_uint32 	 FRC_PORT;			//0x10
	kal_uint32 	 CC_PORT;			//0x14
	kal_uint32 	 SWIM_PORT;			//0x18
	kal_uint32	 RESERVE;			//0x1C
	// emi configuration (need backup)
	kal_uint32	 EMI_BUF_SIZE;		//0x20
	kal_uint32	 EMI_BUF_BASE_ADDR;	//0x24
	kal_uint32 	 EMI_BUF_START_ADDR;//0x28
	// configuration (need backup)
	MDL_CON0_BS	 CON0_BEFORE_START;	//0x2C
	MDL_CON1_BS	 CON1_BEFORE_START;	//0x30
	MDL_CON2_BS	 CON2_BEFORE_START;	//0x34
	// run time control
	MDL_CON_RT 	 CON_RUN_TIME;		//0x38
	// status (buffer full state need backup)
	MDL_STA		 MDL_STA;			//0x4C
	MDL_CSM_STA  CSM_STA;			//0x40
	MDL_LBUF_STA LBUF_STA;			//0x44
	MDL_OVF_STA	 OVF_STA;			//0x48
	// debug register
	kal_uint32	 LBUF_IN_VALUE_L;	//0x4C
	kal_uint32	 LBUF_IN_VALUE_H;	//0x50
	kal_uint32	 LBUF_RADDR;		//0x54
	kal_uint32	 LBUF_RDATA;		//0x58
	MDL_ERR_STA  ERR_STA;			//0x5C
} MDL_REG;

extern volatile MDL_REG* const MDL[];
extern const kal_int32 MDL_NUM;

// ============== define the register operation macro ================
// Port Related Macro
#define MDL_WRITE_CSM(ch,CSM) 						(MDL[ch]->CSM_PORT = (CSM))
#define MDL_WRITE_PREV_CSM(ch, CSM) 				(MDL[ch]->PREVCSM_PORT = (CSM))
#define MDL_WRITE_DATA32(ch, DATA) 					(MDL[ch]->DATA_PORT = (DATA))
#define MDL_WRITE_DATA16(ch, DATA) 					(MDL[ch]->DATA16_PORT = (DATA))
#define MDL_TRIGGER_FRC(ch) 						(MDL[ch]->FRC_PORT = (1))
#define MDL_TRIGGER_CC(ch) 							(MDL[ch]->CC_PORT = (1))
#define MDL_WRITE_SWIM(ch, SWIM) 					(MDL[ch]->SWIM_PORT = (SWIM))
// EMI Related
#define MDL_SET_EMI_BUF_SIZE(ch, SIZE) 				(MDL[ch]->EMI_BUF_SIZE = SIZE)
#define MDL_SET_EMI_BASE_ADDR(ch, ADDR) 			(MDL[ch]->EMI_BUF_BASE_ADDR = ADDR)
#define MDL_GET_EMI_BASE_ADDR(ch)					(MDL[ch]->EMI_BUF_BASE_ADDR)
#define MDL_SET_EMI_START_ADDR(ch, ADDR)			(MDL[ch]->EMI_BUF_START_ADDR = ADDR)
#define MDL_GET_EMI_START_ADDR(ch) 					(MDL[ch]->EMI_BUF_START_ADDR)
// MDL_CON0_BEFORE_START
#define MDL_SET_MDL_CLOCK_ON(ch)					(MDL[ch]->CON0_BEFORE_START.CLKDIS = 0)
#define MDL_SET_MDL_CLOCK_OFF(ch)					(MDL[ch]->CON0_BEFORE_START.CLKDIS = 1)
#define MDL_GET_MDL_CLOCK(ch)                       (MDL[ch]->CON0_BEFORE_START.CLKDIS)
#define MDL_SET_MDL_START(ch)             			(MDL[ch]->CON0_BEFORE_START.START = 1)
#define MDL_SET_MDL_STOP(ch)             			(MDL[ch]->CON0_BEFORE_START.START = 0)
#define MDL_GET_MDL_START(ch)                       (MDL[ch]->CON0_BEFORE_START.START)
#define MDL_SET_MDL_RESET(ch)             			do{MDL[ch]->CON0_BEFORE_START.RESET = 1; \
													   MDL[ch]->CON0_BEFORE_START.RESET = 0;}while(0)
#define MDL_SET_MDL_OUTPUT_TO_EMI(ch)       		(MDL[ch]->CON0_BEFORE_START.OUT_TO_EMI = 1)
#define MDL_SET_MDL_OUTPUT_TO_ATB(ch)      			(MDL[ch]->CON0_BEFORE_START.OUT_TO_EMI = 0)
#define MDL_GET_MDL_OUTPUT_TO_EMI(ch)               (MDL[ch]->CON0_BEFORE_START.OUT_TO_EMI)
#define MDL_SET_MDL_AUTO_TEST_ON(ch)        		(MDL[ch]->CON0_BEFORE_START.AUTO_TEST_EN = 1)
#define MDL_SET_MDL_AUTO_TEST_OFF(ch)   			(MDL[ch]->CON0_BEFORE_START.AUTO_TEST_EN = 0)
#define MDL_SET_MDL_CSM_REDUCTION_ON(ch)    		(MDL[ch]->CON0_BEFORE_START.CSMR_EN = 1)
#define MDL_SET_MDL_CSM_REDUCTION_OFF(ch)   		(MDL[ch]->CON0_BEFORE_START.CSMR_EN = 0)
#define MDL_SET_MDL_CSM_COMPENSATION_ON(ch)  		(MDL[ch]->CON0_BEFORE_START.CSMC_EN = 1)
#define MDL_SET_MDL_CSM_COMPENSATION_OFF(ch)		(MDL[ch]->CON0_BEFORE_START.CSMC_EN = 0)
#define MDL_SET_MDL_TO_SWOVF_MODE(ch)       		(MDL[ch]->CON0_BEFORE_START.SWOV_EN = 1)
#define MDL_SET_MDL_TO_HWOVF_MODE(ch)      	 		(MDL[ch]->CON0_BEFORE_START.SWOV_EN = 0)
#define MDL_SET_MDL_HWCS_ON(ch)            	 		(MDL[ch]->CON0_BEFORE_START.HWCS_EN = 1)
#define MDL_SET_MDL_HWCS_OFF(ch)            		(MDL[ch]->CON0_BEFORE_START.HWCS_EN = 0)
#define MDL_SET_MDL_EMI_BUF_WRAP_ON(ch)     		(MDL[ch]->CON0_BEFORE_START.EMI_WRAP_EN = 1)
#define MDL_SET_MDL_EMI_BUF_WRAP_OFF(ch)    		(MDL[ch]->CON0_BEFORE_START.EMI_WRAP_EN = 0)
// MDL_CON1_BEFORE_START
#define MDL_SET_MDL_SPECIAL_MARKER(ch, SM)      	(MDL[ch]->CON1_BEFORE_START.SPECIAL_MARKER = SM)
#define MDL_SET_MDL_HW_CSM(vh, HWCSM)          		(MDL[ch]->CON1_BEFORE_START.HWCS_CSM = HWCSM)
// MDL_CON2_BEFORE_START
#define MDL_SET_MDL_CC_STEP(ch, DATA)            	(MDL[ch]->CON2_BEFORE_START.CC_STEP = DATA)
#define MDL_SET_MDL_LBUF_UNLOCK_TH_EMPTY(ch)      	(MDL[ch]->CON2_BEFORE_START.LBUF_UNLOCK_THS = 0)
#define MDL_SET_MDL_LBUF_UNLOCK_TH_HALF_FULL(ch) 	(MDL[ch]->CON2_BEFORE_START.LBUF_UNLOCK_THS = 1)
#define MDL_SET_MDL_EMI_BANDWIDTH(ch, BW)		  	(MDL[ch]->CON2_BEFORE_START.EMI_BW_CON = BW)
#define MDL_SET_MDL_ATID(ch, ATID)           	  	(MDL[ch]->CON2_BEFORE_START.ATID = ATID)
// MDL_CON_RUN_TIME
#define MDL_SET_MDL_EVENT_CTRL_SYNC_MASK_ON(ch) 	(MDL[ch]->CON_RUN_TIME.EVENT_CTRL_SYNC_MASK = 1)
#define MDL_SET_MDL_EVENT_CTRL_SYNC_MASK_OFF(ch)	(MDL[ch]->CON_RUN_TIME.EVENT_CTRL_SYNC_MASK = 0)
#define MDL_SET_MDL_LBUF_FLUSH(ch)	           		(MDL[ch]->CON_RUN_TIME.LBUF_FLUSH = 1)
#define MDL_SET_MDL_LBUF_ABORT(ch)	           	 	(MDL[ch]->CON_RUN_TIME.LBUF_ABORT = 1)
#define MDL_SET_MDL_LBUF_FLUSH_ABORT_CLR(ch)   	 	(MDL[ch]->CON_RUN_TIME.LBUF_FLUSH_ABORT_CLR = 1)
#define MDL_SET_MDL_SWTR_EN_ON(ch)              	(MDL[ch]->CON_RUN_TIME.SWTR_EN = 1)
#define MDL_SET_MDL_SWTR_EN_OFF(ch)             	(MDL[ch]->CON_RUN_TIME.SWTR_EN = 0)
#define MDL_SET_MDL_LBUF_OUT_DIS(ch, disable)       (MDL[ch]->CON_RUN_TIME.LBUF_OUT_DIS = disable)
#define MDL_SET_MDL_LBUF_UNLOCK(ch)             	(MDL[ch]->CON_RUN_TIME.LBUF_UNLOCK = 1)
#define MDL_SET_MDL_CSM_STK_ERR_CLR(ch)         	(MDL[ch]->CON_RUN_TIME.CSM_STK_ERR_CLR = 1)
#define MDL_SET_MDL_OVF_DATA_DROP_NUM_CLR(ch)   	(MDL[ch]->CON_RUN_TIME.OVF_DATA_DROP_NUM_CLR = 1)
#define MDL_SET_MDL_OVF_NUM_CLR(ch)             	(MDL[ch]->CON_RUN_TIME.OVF_NUM_CLR = 1)
#define MDL_SET_MDL_DATA16_MERGE_ERR_CLR(ch)    	(MDL[ch]->CON_RUN_TIME.DATA16_MERGE_ERR_CLR = 1)
#define MDL_SET_MDL_DATA_PORT_REPLACE_ON(ch)    	(MDL[ch]->CON_RUN_TIME.DATA_PORT_REPLACE = 1)
#define MDL_SET_MDL_DATA_PORT_REPLACE_OFF(ch)   	(MDL[ch]->CON_RUN_TIME.DATA_PORT_REPLACE = 0)
#define MDL_SET_MDL_BURST_BUF_REPLACE_ON(ch)    	(MDL[ch]->CON_RUN_TIME.BURST_BUF_REPLACE = 1)
#define MDL_SET_MDL_BURST_BUF_REPLACE_OFF(ch)   	(MDL[ch]->CON_RUN_TIME.BURST_BUF_REPLACE = 0)
#define MDL_SET_MDL_PORT_DIS(ch, disable)           (MDL[ch]->CON_RUN_TIME.PORT_DIS = disable)
#define MDL_SET_MDL_SWTR_PERIOD(ch, DATA)       	(MDL[ch]->CON_RUN_TIME.SWTR_PERIOD = DATA)
#define MDL_GET_MDL_LBUF_FLUSH(ch)	           		(MDL[ch]->CON_RUN_TIME.LBUF_FLUSH)
#define MDL_GET_MDL_LBUF_ABORT(ch)	            	(MDL[ch]->CON_RUN_TIME.LBUF_ABORT)
// MDL Status Register
#define MDL_GET_MDL_STA(ch)								(MDL[ch]->MDL_STA)
#define MDL_SET_EMI_BUF0_FULL(ch, STA)              (MDL[ch]->MDL_STA.EMI_BUF0_FULL = STA)
#define MDL_SET_EMI_BUF1_FULL(ch, STA) 	            (MDL[ch]->MDL_STA.EMI_BUF1_FULL = STA)
#define MDL_GET_EMI_BUF0_FULL(ch)		        	(MDL[ch]->MDL_STA.EMI_BUF0_FULL)
#define MDL_GET_EMI_BUF1_FULL(ch) 					(MDL[ch]->MDL_STA.EMI_BUF1_FULL)
#define MDL_GET_MDL_LBUF_FLUSH_DONE(ch) 			(MDL[ch]->MDL_STA.LBUF_FLASH_DONE)
#define MDL_GET_MDL_LBUF_ABORT_DONE(ch) 			(MDL[ch]->MDL_STA.LBUF_ABORT_DONE)
#define MDL_GET_MDL_HWCS(ch) 						(MDL[ch]->MDL_STA.HWCS)
#define MDL_GET_MDL_DATA16_MERGE_ERR(ch) 			(MDL[ch]->MDL_STA.DATA16_MERGE_ERR)
#define MDL_GET_MDL_EMI_BUF_WRAPPED(ch)				(MDL[ch]->MDL_STA.EMI_BUF_WRAPPED)
// MDL_CSM_STACK_STA
#define MDL_GET_MDL_CSM_USED_LEVEL(ch)				(MDL[ch]->MDL_CSM_STA.CSM_USED_LEVEL)
#define MDL_GET_MDL_CSM_MAX_USED_LEVEL(ch)			(MDL[ch]->MDL_CSM_STA.CSM_MAX_USED_LEVEL)
#define MDL_GET_MDL_CSM_TOP(ch)	 			 		(MDL[ch]->MDL_CSM_STA.CSM_TOP)
#define MDL_GET_CSMR_OUT(ch)           				(MDL[ch]->MDL_CSM_STA.CSMR_OUT)
#define MDL_GET_CSM_STK_OVERFLOW_ERR(ch)   			(MDL[ch]->MDL_CSM_STA.CSM_STK_OVERFLOW)
#define MDL_GET_CSM_STK_UNDERFLOW_ERR(ch)  			(MDL[ch]->MDL_CSM_STA.CSM_STK_UNDERFLOW)
// MDL_LBUF_STA
#define MDL_GET_MDL_LBUF_USED_SPACE(ch) 			(MDL[ch]->LBUF_STA.LBUF_USED_SPACE)
#define MDL_GET_MDL_LBUF_MAX_USED_SPACE(ch) 		(MDL[ch]->LBUF_STA.LBUF_MAX_USED_SPACE)
#define MDL_GET_MDL_LBUF_SIZE(ch) 					(MDL[ch]->LBUF_STA.LBUF_SIZE)
#define MDL_GET_LBUF_FULL(ch)         				(MDL[ch]->LBUF_STA.LBUF_FULL)
#define MDL_GET_LBUF_LOCKED(ch)       				(MDL[ch]->LBUF_STA.LBUF_LOCKED)
#define MDL_GET_LBUF_CAN_UNLOCK(ch)   				(MDL[ch]->LBUF_STA.LBUF_CAN_UNLOCK)
// MDL_OVF_STA
#define MDL_GET_MDL_OVF_DATA_DROP_NUM(ch) 			(MDL[ch]->OVF_STA.OVF_DATA_DROP_NUM)
#define MDL_GET_MDL_OVF_NUM(ch)						(MDL[ch]->OVF_STA.OVF_NUM)
// debug registers
#define MDL_GET_MDL_LBUF_IN_VALUE_L(ch) 			(MDL[ch]->LBUF_IN_VALUE_L)
#define MDL_GET_MDL_LBUF_IN_VALUE_H(ch)				(MDL[ch]->LBUF_IN_VALUE_H)
#define MDL_SET_MDL_LBUF_RADDR(ch, ADDR)   			(MDL[ch]->LBUF_RADDR = ADDR)
#define MDL_GET_MDL_LBUF_RDATA(ch) 					(MDL[ch]->LBUF_RDATA)
#define MDL_SET_MDL_ERR_CLR(ch)   					(MDL[ch]->ERR_STA.CLR_ERR = 1)

#endif /* MDL_REG_H_ */
