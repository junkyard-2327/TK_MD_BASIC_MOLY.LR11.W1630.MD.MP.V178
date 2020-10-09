/*
 * mtol_reg.h
 *
 *  Created on: 2014/8/20
 *      Author: MTK07117
 */

#ifndef MTOL_REG_H_
#define MTOL_REG_H_

// ===================== MTOL register address ========================
#define MTOL_HW_NUM		(3)
#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
#define MTOL0_BASEADDR	(0xFD601600) // MPC
#define MTOL1_BASEADDR	(0xFDE03E00) // IMC
#define MTOL2_BASEADDR	(0xFEE01400) // ICC
#elif defined(TK6291)
#define MTOL0_BASEADDR	(0xFD601600) // MPC
#define MTOL1_BASEADDR	(0xFDE04000) // IMC
#define MTOL2_BASEADDR	(0xFEE01200) // ICC
#else
#error
#endif

//MTOL Port
#define MTOL_LENGTH(i)					( MTOL##i##_BASEADDR + 0x0000 )
#define MTOL_ATID(i)					( MTOL##i##_BASEADDR + 0x0004 )
#define MTOL_SW_INFO1(i)				( MTOL##i##_BASEADDR + 0x0008 )
#define MTOL_SW_INFO2(i)				( MTOL##i##_BASEADDR + 0x000C )
#define MTOL_SW_INFO3(i)				( MTOL##i##_BASEADDR + 0x0010 )
#define MTOL_ESCAPE(i)					( MTOL##i##_BASEADDR + 0x0014 )
//EMI Related
#define MTOL_EMI_BUF_SIZE_REG(i)		( MTOL##i##_BASEADDR + 0x0020 )
#define MTOL_EMI_BUF_BASE_ADDR_REG(i)	( MTOL##i##_BASEADDR + 0x0024 )
#define MTOL_EMI_BUF_START_ADDR_REG(i)	( MTOL##i##_BASEADDR + 0x0028 )
//Configuration
#define MTOL_CON_BEFORE_START_REG(i)	( MTOL##i##_BASEADDR + 0x002C )
#define MTOL_CON_RUN_TIME_REG(i)		( MTOL##i##_BASEADDR + 0x0030 )
#define MTOL_STA_REG(i)					( MTOL##i##_BASEADDR + 0x0034 )
#define MTOL_TIME_OUT_REG(i)			( MTOL##i##_BASEADDR + 0x0038 )
#define MTOL_SWTEST_PORT(i)			    ( MTOL##i##_BASEADDR + 0x003C )

// ============= define the register structure for MTOL ===============
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
		kal_uint32 SIB_BW_CON:1;
		kal_uint32 RESERVE:21;
	};
} MTOL_CON_BS;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 EVENT_CTRL_SYNC_MASK:1;
		kal_uint32 LBUF_FLUSH:1;
		kal_uint32 LBUF_ABORT:1;
		kal_uint32 LBUF_FLUSH_ABORT_CLR:1;
		kal_uint32 STOP:1;
		kal_uint32 RESERVE:27;
	};
}MTOL_CON_RT;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 EMI_BUF0_FULL:1;
		kal_uint32 EMI_BUF1_FULL:1;
		kal_uint32 LBUF_FLASH_DONE:1;
		kal_uint32 LBUF_ABORT_DONE:1;
		kal_uint32 EMI_BUF_WRAPPED:1;
		kal_uint32 TRAN_DONE:1;
		kal_uint32 SW_TEST_WRITE_EN:1;
		kal_uint32 SW_TEST_WRITE_NUM:4;
		kal_uint32 START_EN:1;
		kal_uint32 RESERVE:20;
	};
}MTOL_STA;

typedef union {
	kal_uint32 ALL;
	struct {
		kal_uint32 TIME_OUT:31;
		kal_uint32 TIME_OUT_INDICATE:1;
	};
}MTOL_TO;

typedef struct {
	// access port
	kal_uint32 	 LENGTH;			//0x00
	kal_uint32 	 ATID;				//0x04
	kal_uint32 	 SW_INFO1;			//0x08
	kal_uint32 	 SW_INFO2;			//0x0C
	kal_uint32 	 SW_INFO3;			//0x10
	kal_uint32 	 ESCAPE;			//0x14
	kal_uint32 	 FRC_H;				//0x18
	kal_uint32	 FRC_L;				//0x1C
	// emi configuration (need backup)
	kal_uint32	 EMI_BUF_SIZE;		//0x20
	kal_uint32	 EMI_BUF_BASE_ADDR;	//0x24
	kal_uint32 	 EMI_BUF_START_ADDR;//0x28
	// configuration (need backup)
	MTOL_CON_BS	 CON_BEFORE_START;	//0x2C
	MTOL_CON_RT  CON_RUN_TIME;		//0x30
	// status (buffer full state need backup)
	MTOL_STA	 MTOL_STA;			//0x34
	MTOL_TO 	 TIME_OUT;			//0x38
	kal_uint32 	 SWTEST_PORT;		//0x3C
} MTOL_REG;

extern volatile MTOL_REG* const MTOL[];
extern const kal_int32 MTOL_NUM;

// ============== define the register operation macro ================
// Port Related Macro
#define MTOL_SET_ATID(ch, ATID)           		  	(MTOL[ch]->ATID = ATID)
#define MTOL_WRITE_SWINFO1(ch, DATA) 				(MTOL[ch]->SW_INFO1 = (DATA))
#define MTOL_WRITE_SWINFO2(ch, DATA) 				(MTOL[ch]->SW_INFO1 = (DATA))
#define MTOL_WRITE_SWINFO3(ch, DATA) 				(MTOL[ch]->SW_INFO1 = (DATA))
#define MTOL_WRITE_SWTEST(ch, DATA) 				(MTOL[ch]->SWTEST_PORT = (DATA))
#define MTOL_SET_SPECIAL_MARKER(ch, SM)      		(MTOL[ch]->ESCAPE = (SM << 16))
// EMI Related
#define MTOL_SET_EMI_BUF_SIZE(ch, SIZE) 			(MTOL[ch]->EMI_BUF_SIZE = SIZE)
#define MTOL_SET_EMI_BASE_ADDR(ch, ADDR) 			(MTOL[ch]->EMI_BUF_BASE_ADDR = ADDR)
#define MTOL_GET_EMI_BASE_ADDR(ch)					(MTOL[ch]->EMI_BUF_BASE_ADDR)
#define MTOL_SET_EMI_START_ADDR(ch, ADDR)			(MTOL[ch]->EMI_BUF_START_ADDR = ADDR)
#define MTOL_GET_EMI_START_ADDR(ch) 				(MTOL[ch]->EMI_BUF_START_ADDR)
// MTOL_CON_BEFORE_START
#define MTOL_SET_CLOCK_ON(ch)						(MTOL[ch]->CON_BEFORE_START.CLKDIS = 0)
#define MTOL_SET_CLOCK_OFF(ch)						(MTOL[ch]->CON_BEFORE_START.CLKDIS = 1)
#define MTOL_GET_CLOCK(ch)						    (MTOL[ch]->CON_BEFORE_START.CLKDIS)
#define MTOL_SET_START(ch)             				(MTOL[ch]->CON_BEFORE_START.START = 1)
#define MTOL_SET_STOP(ch)             				(MTOL[ch]->CON_RUN_TIME.STOP = 1)
#define MTOL_GET_START(ch)                          (MTOL[ch]->CON_BEFORE_START.START)
#define MTOL_SET_RESET(ch)             				(MTOL[ch]->CON_BEFORE_START.RESET = 1)
#define MTOL_SET_OUTPUT_TO_EMI(ch)       			(MTOL[ch]->CON_BEFORE_START.OUT_TO_EMI = 1)
#define MTOL_SET_OUTPUT_TO_ATB(ch)      			(MTOL[ch]->CON_BEFORE_START.OUT_TO_EMI = 0)
#define MTOL_GET_OUTPUT_TO_EMI(ch)                  (MTOL[ch]->CON_BEFORE_START.OUT_TO_EMI)
#define MTOL_SET_AUTO_TEST_ON(ch)        			(MTOL[ch]->CON_BEFORE_START.AUTO_TEST_EN = 1)
#define MTOL_SET_AUTO_TEST_OFF(ch)   				(MTOL[ch]->CON_BEFORE_START.AUTO_TEST_EN = 0)
#define MTOL_SET_EMI_BANDWIDTH(ch, BW)		  		(MTOL[ch]->CON_BEFORE_START.EMI_BW_CON = BW)
#define MTOL_SET_EMI_BUF_WRAP_ON(ch)     			(MTOL[ch]->CON_BEFORE_START.EMI_WRAP_EN = 1)
#define MTOL_SET_EMI_BUF_WRAP_OFF(ch)    			(MTOL[ch]->CON_BEFORE_START.EMI_WRAP_EN = 0)
#define MTOL_SET_SW_TEST_ON(ch)     				(MTOL[ch]->CON_BEFORE_START.SW_TEST_EN = 1)
#define MTOL_SET_SW_TEST_OFF(ch)     				(MTOL[ch]->CON_BEFORE_START.SW_TEST_EN = 0)
// MTOL_CON_RUN_TIME
#define MTOL_SET_EVENT_CTRL_SYNC_MASK_ON(ch) 		(MTOL[ch]->CON_RUN_TIME.EVENT_CTRL_SYNC_MASK = 1)
#define MTOL_SET_EVENT_CTRL_SYNC_MASK_OFF(ch)		(MTOL[ch]->CON_RUN_TIME.EVENT_CTRL_SYNC_MASK = 0)
#define MTOL_SET_LBUF_FLUSH(ch)	         	  		(MTOL[ch]->CON_RUN_TIME.LBUF_FLUSH = 1)
#define MTOL_SET_LBUF_ABORT(ch)	          	 		(MTOL[ch]->CON_RUN_TIME.LBUF_ABORT = 1)
#define MTOL_SET_LBUF_FLUSH_ABORT_CLR(ch)   		(MTOL[ch]->CON_RUN_TIME.LBUF_FLUSH_ABORT_CLR = 1)
#define MTOL_GET_LBUF_FLUSH(ch)	           			(MTOL[ch]->CON_RUN_TIME.LBUF_FLUSH)
#define MTOL_GET_LBUF_ABORT(ch)	           			(MTOL[ch]->CON_RUN_TIME.LBUF_ABORT)
// MTOL Status Register
#define MTOL_GET_MTOL_STA(ch)						(MTOL[ch]->MTOL_STA)
#define MTOL_SET_EMI_BUF0_FULL(ch, STA)             (MTOL[ch]->MTOL_STA.EMI_BUF0_FULL = STA)
#define MTOL_SET_EMI_BUF1_FULL(ch, STA) 	        (MTOL[ch]->MTOL_STA.EMI_BUF1_FULL = STA)
#define MTOL_GET_EMI_BUF0_FULL(ch)		        	(MTOL[ch]->MTOL_STA.EMI_BUF0_FULL)
#define MTOL_GET_EMI_BUF1_FULL(ch) 					(MTOL[ch]->MTOL_STA.EMI_BUF1_FULL)
#define MTOL_GET_LBUF_FLUSH_DONE(ch) 				(MTOL[ch]->MTOL_STA.LBUF_FLASH_DONE)
#define MTOL_GET_LBUF_ABORT_DONE(ch) 				(MTOL[ch]->MTOL_STA.LBUF_ABORT_DONE)
#define MTOL_GET_EMI_BUF_WRAPPED(ch)				(MTOL[ch]->MTOL_STA.EMI_BUF_WRAPPED)
#define MTOL_GET_TRAN_DONE(ch)						(MTOL[ch]->MTOL_STA.TRAN_DONE)
#define MTOL_GET_SW_TEST_WRITE_EN(ch)				(MTOL[ch]->MTOL_STA.SW_TEST_WRITE_EN)
#define MTOL_GET_SW_TEST_WRITE_NUM(ch)				(MTOL[ch]->MTOL_STA.SW_TEST_WRITE_NUM)
#define MTOL_GET_START_EN(ch)						(MTOL[ch]->MTOL_STA.START_EN)
// MTOL timeout register
#define MTOL_GET_TIME_OUT(ch)						(MTOL[ch]->TIME_OUT.TIME_OUT)
#define MTOL_GET_TIME_OUT_EN(ch)					(MTOL[ch]->TIME_OUT.TIME_OUT_INDICATE)
#endif //MTOL_REG_H_
