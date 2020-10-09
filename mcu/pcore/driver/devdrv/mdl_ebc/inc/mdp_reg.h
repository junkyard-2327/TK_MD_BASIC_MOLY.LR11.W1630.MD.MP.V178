/*
 * mdp_reg.h
 *
 *  Created on: 2014/8/20
 *      Author: MTK07117
 */

#ifndef MDP_REG_H_
#define MDP_REG_H_

// ===================== MDP register address ========================
#define MDP_HW_NUM		(3)
#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
#define MDP0_BASEADDR	(0xFD601680) // MPC
#define MDP1_BASEADDR	(0xFDE03E80) // IMC
#define MDP2_BASEADDR	(0xFEE01480) // ICC
#elif defined(TK6291)
#define MDP0_BASEADDR	(0xFD601680) // MPC
#define MDP1_BASEADDR	(0xFDE04080) // IMC
#define MDP2_BASEADDR	(0xFEE01280) // ICC
#else
#error
#endif

//MDP Port
#define MDP_CI_8_PORT(i)               ( MDP##i##_BASEADDR + 0x0000 )
#define MDP_TD_16_PORT(i)              ( MDP##i##_BASEADDR + 0x0004 )
#define MDP_CI_16_PORT(i)              ( MDP##i##_BASEADDR + 0x0008 )
#define MDP_TD_32_PORT(i)              ( MDP##i##_BASEADDR + 0x000C )
#define MDP_CI_32_PORT(i)              ( MDP##i##_BASEADDR + 0x0010 )
//Configuration 1
#define MDP_CON0_BEFORE_START_REG(i)   ( MDP##i##_BASEADDR + 0x0014 )
#define MDP_CON0_RUN_TIME_REG(i)       ( MDP##i##_BASEADDR + 0x0018 )
#define MDP_READ_DATA_1_REG(i)         ( MDP##i##_BASEADDR + 0x001C )
#define MDP_READ_DATA_2_REG(i)         ( MDP##i##_BASEADDR + 0x0020 )
#define MDP_READ_DATA_3_REG(i)         ( MDP##i##_BASEADDR + 0x0024 )
#define MDP_READ_DATA_4_REG(i)         ( MDP##i##_BASEADDR + 0x0028 )
#define MDP_HW_MIPS_PER_REG(i)         ( MDP##i##_BASEADDR + 0x002C )
#define MDP_HW_MIPS_INSEN_REG(i)       ( MDP##i##_BASEADDR + 0x0030 )
#define MDP_HW_MIPS_MODULE_EN_REG(i)   ( MDP##i##_BASEADDR + 0x0034 )
//EMI Related
#define MDP_EMI_BUF_SIZE_REG(i)        ( MDP##i##_BASEADDR + 0x0040 )
#define MDP_EMI_BUF_BASE_ADDR_REG(i)   ( MDP##i##_BASEADDR + 0x0044 )
#define MDP_EMI_BUF_START_ADDR_REG(i)  ( MDP##i##_BASEADDR + 0x0048 )
//Configuration 2
#define MDP_CON1_BEFORE_START_REG(i)   ( MDP##i##_BASEADDR + 0x004C )
#define MDP_CON1_RUN_TIME_REG(i)       ( MDP##i##_BASEADDR + 0x0050 )
#define MDP_STA_REG(i)                 ( MDP##i##_BASEADDR + 0x0054 )
#define MDP_SWTEST_PORT(i)             ( MDP##i##_BASEADDR + 0x005C )

// ============= define the register structure for MDP ===============
typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 SW_TRC_EN:1;
		kal_uint32 HW_CONTEXT_EN:1;
		kal_uint32 PC_TRANCE_EN:1;
		kal_uint32 CORE_FRE_DET_EN:1;
		kal_uint32 CORE_FRE_DET_PER:4;
		kal_uint32 SYNC_INTERVAL_EN:1;
		kal_uint32 SYNC_INTERVAL_PER:4;
		kal_uint32 LBUF_SW_READ_EN:1;
		kal_uint32 LBUF_WRAPPING_EN:1;
		kal_uint32 HW_MIPS_EN:1;
		kal_uint32 ATID:7;
		kal_uint32 RESERVE:9;
	};
} MDP_CON0_BS;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 SYNC:1;
		kal_uint32 FRC:1;
		kal_uint32 LBUF_FULL:1;
		kal_uint32 SW_READ:1;
		kal_uint32 SW_READ_ADDR:6;
		kal_uint32 WRAPPING_ADDR:6;
		kal_uint32 RESERVE:16;
	};
}MDP_CON0_RT;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 CLKDIS:1;
		kal_uint32 START:1;
		kal_uint32 RESET:1;
		kal_uint32 OUT_TO_EMI:1;
		kal_uint32 AUTO_TEST_EN:1;
		kal_uint32 EMI_BUF_FULL_NONBUF:1;
		kal_uint32 EMI_BW_CON:2;
		kal_uint32 EMI_WRAP_EN:1;
		kal_uint32 SW_TEST_EN:1;
		kal_uint32 RESERVE:22;
	};
} MDP_CON1_BS;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 EVENT_CTRL_SYNC_MASK:1;
		kal_uint32 LBUF_FLUSH:1;
		kal_uint32 LBUF_ABORT:1;
		kal_uint32 LBUF_FLUSH_ABORT_CLR:1;
		kal_uint32 RESERVE:28;
	};
}MDP_CON1_RT;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 EMI_BUF0_FULL:1;
		kal_uint32 EMI_BUF1_FULL:1;
		kal_uint32 LBUF_FLASH_DONE:1;
		kal_uint32 LBUF_ABORT_DONE:1;
		kal_uint32 EMI_BUF_WRAPPED:1;
		kal_uint32 RESERVE1:1;
		kal_uint32 SW_TEST_WRITE_EN:1;
		kal_uint32 SW_TEST_WRITE_NUM:4;
		kal_uint32 RESERVE2:21;
	};
}MDP_STA;

typedef struct {
	// access port
	kal_uint32  CI_8_PORT;			//0x00
	kal_uint32  TD_16_PORT;			//0x04
	kal_uint32  CI_16_PORT;			//0x08
	kal_uint32  TD_32_PORT;			//0x0C
	kal_uint32  CI_32_PORT;			//0x10
	MDP_CON0_BS CON0_BEFORE_START;	//0x14
	MDP_CON0_RT CON0_RUN_TIME;		//0x18
	kal_uint32	READ_DATA1;			//0x1C
	kal_uint32	READ_DATA2;			//0x20
	kal_uint32	READ_DATA3;			//0x24
	kal_uint32	READ_DATA4;			//0x28
	kal_uint32	HW_MIPS_PER;		//0x2C
	kal_uint32	HW_MIPS_INSEN;		//0x30
	kal_uint32 	HW_MIPS_MODULE_EN;	//0x34
	kal_uint32	RESERVE1;			//0x38
	kal_uint32 	RESERVE2;			//0x3C
	// emi configuration (need backup)
	kal_uint32	EMI_BUF_SIZE;		//0x40
	kal_uint32	EMI_BUF_BASE_ADDR;	//0x44
	kal_uint32	EMI_BUF_START_ADDR;	//0x48
	// configuration (need backup)
	MDP_CON1_BS	CON1_BEFORE_START;	//0x4C
	MDP_CON1_RT CON1_RUN_TIME;		//0x50
	// status (buffer full state need backup)
	MDP_STA		MDP_STA;			//0x54
	kal_uint32	RESERVE3;			//0x58
	kal_uint32	SWTEST_PORT;		//0x5C
} MDP_REG;

extern volatile MDP_REG* const MDP[];
extern const kal_int32 MDP_NUM;

// ============== define the register operation macro ================
// Port Related Macro
#define MDP_WRITE_CI_8(ch, DATA) 				(MDP[ch]->CI_8_PORT = (DATA))
#define MDP_WRITE_TD_16(ch, DATA) 				(MDP[ch]->TD_16_PORT = (DATA))
#define MDP_WRITE_CI_16(ch, DATA) 				(MDP[ch]->CI_16_PORT = (DATA))
#define MDP_WRITE_TD_32(ch, DATA) 				(MDP[ch]->TD_32_PORT = (DATA))
#define MDP_WRITE_CI_32(ch, DATA) 				(MDP[ch]->CI_32_PORT = (DATA))
#define MDP_WRITE_SWTEST(ch, DATA) 				(MDP[ch]->SWTEST_PORT = (DATA))
// MDP_CON0_BEFORE_START
#define MDP_SET_SW_TRC_ON(ch)					(MDP[ch]->CON0_BEFORE_START.SW_TRC_EN = 1)
#define MDP_SET_SW_TRC_OFF(ch)					(MDP[ch]->CON0_BEFORE_START.SW_TRC_EN = 0)
#define MDP_SET_HW_CONTEXT_ON(ch)				(MDP[ch]->CON0_BEFORE_START.HW_CONTEXT_EN = 1)
#define MDP_SET_HW_CONTEXT_OFF(ch)				(MDP[ch]->CON0_BEFORE_START.HW_CONTEXT_EN = 0)
#define MDP_SET_PC_TRANCE_ON(ch)				(MDP[ch]->CON0_BEFORE_START.PC_TRANCE_EN = 1)
#define MDP_SET_PC_TRANCE_OFF(ch)				(MDP[ch]->CON0_BEFORE_START.PC_TRANCE_EN = 0)
#define MDP_SET_CORE_FRE_DET_ON(ch)				(MDP[ch]->CON0_BEFORE_START.CORE_FRE_DET_EN = 1)
#define MDP_SET_CORE_FRE_DET_OFF(ch)			(MDP[ch]->CON0_BEFORE_START.CORE_FRE_DET_EN = 0)
#define MDP_SET_CORE_FRE_DET_PER(ch, PER)		(MDP[ch]->CON0_BEFORE_START.CORE_FRE_DET_PER = PER)
#define MDP_SET_SYNC_INTERVAL_ON(ch)			(MDP[ch]->CON0_BEFORE_START.SYNC_INTERVAL_EN = 1)
#define MDP_SET_SYNC_INTERVAL_OFF(ch)			(MDP[ch]->CON0_BEFORE_START.SYNC_INTERVAL_EN = 0)
#define MDP_SET_SYNC_INTERVAL_PER(ch, PER)		(MDP[ch]->CON0_BEFORE_START.SYNC_INTERVAL_PER = PER)
#define MDP_SET_LBUF_SW_READ_ON(ch)				(MDP[ch]->CON0_BEFORE_START.LBUF_SW_READ_EN = 1)
#define MDP_SET_LBUF_SW_READ_OFF(ch)			(MDP[ch]->CON0_BEFORE_START.LBUF_SW_READ_EN = 0)
#define MDP_SET_LBUF_WRAPPING_ON(ch)			(MDP[ch]->CON0_BEFORE_START.LBUF_WRAPPING_EN = 1)
#define MDP_SET_LBUF_WRAPPING_OFF(ch)			(MDP[ch]->CON0_BEFORE_START.LBUF_WRAPPING_EN = 0)
#define MDP_SET_HW_MIPS_ON(ch)					(MDP[ch]->CON0_BEFORE_START.HW_MIPS_EN = 1)
#define MDP_SET_HW_MIPS_OFF(ch)					(MDP[ch]->CON0_BEFORE_START.HW_MIPS_EN = 0)
#define MDP_SET_ATID(ch, ADID)					(MDP[ch]->CON0_BEFORE_START.MDP_ATID = ADID)
// MDP_CON0_RUN_TIME
#define MDP_RUN_SYNC(ch)						(MDP[ch]->CON0_RUN_TIME.SYNC = 1)
#define MDP_RUN_FRC(ch)							(MDP[ch]->CON0_RUN_TIME.FRC = 1)
#define MDP_UPDATE_SW_READ(ch)					(MDP[ch]->CON0_RUN_TIME.SW_READ = 1)
#define MDP_SET_SW_READ_ADDR(ch, ADDR)			(MDP[ch]->CON0_RUN_TIME.SW_READ_ADDR = ADDR)
#define MDP_SET_WRAPPING_ADDR(ch, ADDR)			(MDP[ch]->CON0_RUN_TIME.WRAPPING_ADDR = ADDR)
#define MDP_GET_LBUF_FULL(ch)					(MDP[ch]->CON0_RUN_TIME.LBUF_FULL)
// MDP READ DATA
#define MDP_GET_RDATA1(ch) 						(MDP[ch]->READ_DATA1)
#define MDP_GET_RDATA2(ch)						(MDP[ch]->READ_DATA2)
#define MDP_GET_RDATA3(ch)						(MDP[ch]->READ_DATA3)
#define MDP_GET_RDATA4(ch)						(MDP[ch]->READ_DATA4)
// MDP MIPS
#define MDP_SET_HW_MIPS_PER(ch, DATA)			(MDP[ch]->HW_MIPS_PER = DATA)
#define MDP_SET_HW_MIPS_INSEN(ch, DATA)			(MDP[ch]->HW_MIPS_INSEN = DATA)
#define MDP_GET_HW_MIPS_PER(ch, DATA)			(MDP[ch]->HW_MIPS_PER)
#define MDP_GET_HW_MIPS_INSEN(ch, DATA)			(MDP[ch]->HW_MIPS_INSEN)
// EMI Related
#define MDP_SET_EMI_BUF_SIZE(ch, SIZE) 			(MDP[ch]->EMI_BUF_SIZE = SIZE)
#define MDP_SET_EMI_BASE_ADDR(ch, ADDR) 		(MDP[ch]->EMI_BUF_BASE_ADDR = ADDR)
#define MDP_GET_EMI_BASE_ADDR(ch)				(MDP[ch]->EMI_BUF_BASE_ADDR)
#define MDP_SET_EMI_START_ADDR(ch, ADDR)		(MDP[ch]->EMI_BUF_START_ADDR = ADDR)
#define MDP_GET_EMI_START_ADDR(ch) 				(MDP[ch]->EMI_BUF_START_ADDR)
// MDP_CON_BEFORE_START
#define MDP_SET_CLOCK_ON(ch)					(MDP[ch]->CON1_BEFORE_START.CLKDIS = 0)
#define MDP_SET_CLOCK_OFF(ch)					(MDP[ch]->CON1_BEFORE_START.CLKDIS = 1)
#define MDP_GET_CLOCK(ch)   					(MDP[ch]->CON1_BEFORE_START.CLKDIS)
#define MDP_SET_START(ch)             			(MDP[ch]->CON1_BEFORE_START.START = 1)
#define MDP_SET_STOP(ch)             			(MDP[ch]->CON1_BEFORE_START.START = 0)
#define MDP_GET_START(ch)                       (MDP[ch]->CON1_BEFORE_START.START)
#define MDP_SET_RESET(ch)             			(MDP[ch]->CON1_BEFORE_START.RESET = 1)
#define MDP_SET_OUTPUT_TO_EMI(ch)       		(MDP[ch]->CON1_BEFORE_START.OUT_TO_EMI = 1)
#define MDP_SET_OUTPUT_TO_ATB(ch)      			(MDP[ch]->CON1_BEFORE_START.OUT_TO_EMI = 0)
#define MDP_GET_OUTPUT_TO_EMI(ch)               (MDP[ch]->CON1_BEFORE_START.OUT_TO_EMI)
#define MDP_SET_AUTO_TEST_ON(ch)        		(MDP[ch]->CON1_BEFORE_START.AUTO_TEST_EN = 1)
#define MDP_SET_AUTO_TEST_OFF(ch)   			(MDP[ch]->CON1_BEFORE_START.AUTO_TEST_EN = 0)
#define MDP_SET_EMI_BANDWIDTH(ch, BW)		  	(MDP[ch]->CON1_BEFORE_START.EMI_BW_CON = BW)
#define MDP_SET_EMI_BUF_WRAP_ON(ch)     		(MDP[ch]->CON1_BEFORE_START.EMI_WRAP_EN = 1)
#define MDP_SET_EMI_BUF_WRAP_OFF(ch)    		(MDP[ch]->CON1_BEFORE_START.EMI_WRAP_EN = 0)
#define MDP_SET_SW_TEST_ON(ch)     				(MDP[ch]->CON1_BEFORE_START.SW_TEST_EN = 1)
#define MDP_SET_SW_TEST_OFF(ch)     			(MDP[ch]->CON1_BEFORE_START.SW_TEST_EN = 0)
// MDP_CON_RUN_TIME
#define MDP_SET_EVENT_CTRL_SYNC_MASK_ON(ch) 	(MDP[ch]->CON1_RUN_TIME.EVENT_CTRL_SYNC_MASK = 1)
#define MDP_SET_EVENT_CTRL_SYNC_MASK_OFF(ch)	(MDP[ch]->CON1_RUN_TIME.EVENT_CTRL_SYNC_MASK = 0)
#define MDP_SET_LBUF_FLUSH(ch)	         	  	(MDP[ch]->CON1_RUN_TIME.LBUF_FLUSH = 1)
#define MDP_SET_LBUF_ABORT(ch)	          	 	(MDP[ch]->CON1_RUN_TIME.LBUF_ABORT = 1)
#define MDP_SET_LBUF_FLUSH_ABORT_CLR(ch)   		(MDP[ch]->CON1_RUN_TIME.LBUF_FLUSH_ABORT_CLR = 1)
#define MDP_GET_LBUF_FLUSH(ch)	           		(MDP[ch]->CON1_RUN_TIME.LBUF_FLUSH)
#define MDP_GET_LBUF_ABORT(ch)	           		(MDP[ch]->CON1_RUN_TIME.LBUF_ABORT)
// MDP Status Register
#define MDP_GET_MDP_STA(ch)						(MDP[ch]->MDP_STA)
#define MDP_SET_EMI_BUF0_FULL(ch, STA)			(MDP[ch]->MDP_STA.EMI_BUF0_FULL = STA)
#define MDP_SET_EMI_BUF1_FULL(ch, STA) 	       	(MDP[ch]->MDP_STA.EMI_BUF1_FULL = STA)
#define MDP_GET_EMI_BUF0_FULL(ch)				(MDP[ch]->MDP_STA.EMI_BUF0_FULL)
#define MDP_GET_EMI_BUF1_FULL(ch)				(MDP[ch]->MDP_STA.EMI_BUF1_FULL)
#define MDP_GET_LBUF_FLUSH_DONE(ch)				(MDP[ch]->MDP_STA.LBUF_FLASH_DONE)
#define MDP_GET_LBUF_ABORT_DONE(ch) 			(MDP[ch]->MDP_STA.LBUF_ABORT_DONE)
#define MDP_GET_EMI_BUF_WRAPPED(ch)				(MDP[ch]->MDP_STA.EMI_BUF_WRAPPED)
#define MDP_GET_SW_TEST_WRITE_EN(ch)			(MDP[ch]->MDP_STA.SW_TEST_WRITE_EN)
#define MDP_GET_SW_TEST_WRITE_NUM(ch)			(MDP[ch]->MDP_STA.SW_TEST_WRITE_NUM)

#endif //MDP_REG_H_
