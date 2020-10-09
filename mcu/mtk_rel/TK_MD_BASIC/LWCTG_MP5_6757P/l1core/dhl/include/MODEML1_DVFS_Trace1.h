#ifndef L1TRC_MODEML1_DVFS_1_DEF_H
#define L1TRC_MODEML1_DVFS_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define MODEML1_DVFS_Str_Scenario(v1)  (unsigned char)(v1+0)
#define MODEML1_DVFS_Str_Rat(v1)  (unsigned char)(v1+34)
#define MODEML1_DVFS_Str_Ccirq_MDL1_Request_Module(v1)  (unsigned char)(v1+37)
#define MODEML1_DVFS_Str_Debug(v1)  (unsigned char)(v1+39)
#define MODEML1_DVFS_Str_Bool(v1)  (unsigned char)(v1+51)
#define MODEML1_DVFS_Str_PTP_Mode(v1)  (unsigned char)(v1+53)
#define MODEML1_DVFS_Str_Project(v1)  (unsigned char)(v1+64)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_CHANGE_RANGE_CMD(v1, v2, v3) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x004F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_CHANGE_RANGE_CMD(v1, v2, v3)
#endif
#define MODEML1_DVFS_TRACE_CHANGE_RANGE_CMD_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x004F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_MDL1_REQUEST(v1, v2, v3, v4, v5) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x014F, (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_MDL1_REQUEST(v1, v2, v3, v4, v5)
#endif
#define MODEML1_DVFS_TRACE_MDL1_REQUEST_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x014F, (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_MDL1_REQUEST_CNF(v1, v2, v3) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x024F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_MDL1_REQUEST_CNF(v1, v2, v3)
#endif
#define MODEML1_DVFS_TRACE_MDL1_REQUEST_CNF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x024F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_ACK_CMD(v1) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x034F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_ACK_CMD(v1)
#endif
#define MODEML1_DVFS_TRACE_ACK_CMD_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x034F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_MDL1_PTP_START_CMD() do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x044F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_MDL1_PTP_START_CMD()
#endif
#define MODEML1_DVFS_TRACE_MDL1_PTP_START_CMD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x044F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_PTP_DONE_CNF(v1, v2) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x054F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_PTP_DONE_CNF(v1, v2)
#endif
#define MODEML1_DVFS_TRACE_PTP_DONE_CNF_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x054F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_INIT_IDEL_GEAR_DONE() do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x064F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_INIT_IDEL_GEAR_DONE()
#endif
#define MODEML1_DVFS_TRACE_INIT_IDEL_GEAR_DONE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x064F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_DEBUG_HEX(v1, v2) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x074F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_DEBUG_HEX(v1, v2)
#endif
#define MODEML1_DVFS_TRACE_DEBUG_HEX_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x074F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_DEBUG(v1, v2) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x084F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_DEBUG(v1, v2)
#endif
#define MODEML1_DVFS_TRACE_DEBUG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x084F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_LOCK_DVFS_PTP(v1, v2) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x094F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_LOCK_DVFS_PTP(v1, v2)
#endif
#define MODEML1_DVFS_TRACE_LOCK_DVFS_PTP_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x094F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_IMCPLL_SDM_PCW(v1, v2) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A4F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_IMCPLL_SDM_PCW(v1, v2)
#endif
#define MODEML1_DVFS_TRACE_IMCPLL_SDM_PCW_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A4F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_PMIC_PLL_STATUS_CHECK(v1, v2, v3, v4) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0B4F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_PMIC_PLL_STATUS_CHECK(v1, v2, v3, v4)
#endif
#define MODEML1_DVFS_TRACE_PMIC_PLL_STATUS_CHECK_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0B4F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_CHIP_SW_VERSION(v1, v2, v3) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C4F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_CHIP_SW_VERSION(v1, v2, v3)
#endif
#define MODEML1_DVFS_TRACE_CHIP_SW_VERSION_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C4F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_HW_CURRENT_GEAR(v1, v2, v3, v4) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0D4F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_HW_CURRENT_GEAR(v1, v2, v3, v4)
#endif
#define MODEML1_DVFS_TRACE_HW_CURRENT_GEAR_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0D4F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_UPPER_BOUND_CHANGE(v1, v2, v3, v4) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0E4F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_UPPER_BOUND_CHANGE(v1, v2, v3, v4)
#endif
#define MODEML1_DVFS_TRACE_UPPER_BOUND_CHANGE_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0E4F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_SET_SCH_WIN(v1, v2, v3) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F4F, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_SET_SCH_WIN(v1, v2, v3)
#endif
#define MODEML1_DVFS_TRACE_SET_SCH_WIN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F4F, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_SET_IMM_EVENT(v1, v2) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x104F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_SET_IMM_EVENT(v1, v2)
#endif
#define MODEML1_DVFS_TRACE_SET_IMM_EVENT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x104F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_ACTIVE_WINDOW(v1, v2, v3, v4) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x114F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_ACTIVE_WINDOW(v1, v2, v3, v4)
#endif
#define MODEML1_DVFS_TRACE_ACTIVE_WINDOW_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x114F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_META_RETURN() do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x124F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_META_RETURN()
#endif
#define MODEML1_DVFS_TRACE_META_RETURN_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x124F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_LTE_GEAR_CONVERTER(v1, v2) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x134F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_LTE_GEAR_CONVERTER(v1, v2)
#endif
#define MODEML1_DVFS_TRACE_LTE_GEAR_CONVERTER_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x134F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_GEAR_CONVERTER(v1, v2) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x144F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_GEAR_CONVERTER(v1, v2)
#endif
#define MODEML1_DVFS_TRACE_GEAR_CONVERTER_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x144F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_PTP_VOLT_DATA(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x154F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_PTP_VOLT_DATA(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define MODEML1_DVFS_TRACE_PTP_VOLT_DATA_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x154F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define MODEML1_DVFS_TRACE_PTP_STATUS(v1, v2) do {\
		if(MODEML1_DVFS_1_Trace_Filter[0]==1 && (MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x164F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define MODEML1_DVFS_TRACE_PTP_STATUS(v1, v2)
#endif
#define MODEML1_DVFS_TRACE_PTP_STATUS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x164F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char MODEML1_DVFS_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_MODEML1_DVFS_TRACE_CHANGE_RANGE_CMD(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_MODEML1_DVFS_TRACE_MDL1_REQUEST(unsigned char v1, unsigned long v2, unsigned long v3, unsigned char v4, unsigned long v5);
void L1TRC_Send_MODEML1_DVFS_TRACE_MDL1_REQUEST_CNF(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_MODEML1_DVFS_TRACE_ACK_CMD(unsigned long v1);
void L1TRC_Send_MODEML1_DVFS_TRACE_MDL1_PTP_START_CMD(void);
void L1TRC_Send_MODEML1_DVFS_TRACE_PTP_DONE_CNF(unsigned long v1, unsigned long v2);
void L1TRC_Send_MODEML1_DVFS_TRACE_INIT_IDEL_GEAR_DONE(void);
void L1TRC_Send_MODEML1_DVFS_TRACE_DEBUG_HEX(unsigned char v1, unsigned long v2);
void L1TRC_Send_MODEML1_DVFS_TRACE_DEBUG(unsigned char v1, unsigned long v2);
void L1TRC_Send_MODEML1_DVFS_TRACE_LOCK_DVFS_PTP(unsigned char v1, unsigned char v2);
void L1TRC_Send_MODEML1_DVFS_TRACE_IMCPLL_SDM_PCW(unsigned long v1, unsigned long v2);
void L1TRC_Send_MODEML1_DVFS_TRACE_PMIC_PLL_STATUS_CHECK(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MODEML1_DVFS_TRACE_CHIP_SW_VERSION(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_MODEML1_DVFS_TRACE_HW_CURRENT_GEAR(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MODEML1_DVFS_TRACE_UPPER_BOUND_CHANGE(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MODEML1_DVFS_TRACE_SET_SCH_WIN(unsigned char v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_MODEML1_DVFS_TRACE_SET_IMM_EVENT(unsigned char v1, unsigned long v2);
void L1TRC_Send_MODEML1_DVFS_TRACE_ACTIVE_WINDOW(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_MODEML1_DVFS_TRACE_META_RETURN(void);
void L1TRC_Send_MODEML1_DVFS_TRACE_LTE_GEAR_CONVERTER(unsigned char v1, unsigned char v2);
void L1TRC_Send_MODEML1_DVFS_TRACE_GEAR_CONVERTER(unsigned char v1, unsigned char v2);
void L1TRC_Send_MODEML1_DVFS_TRACE_PTP_VOLT_DATA(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_MODEML1_DVFS_TRACE_PTP_STATUS(unsigned char v1, unsigned long v2);

void Set_MODEML1_DVFS_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_MODEML1_DVFS_1()	(MODEML1_DVFS_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()	(ChkL1ModFltr_MODEML1_DVFS_1()&&((MODEML1_DVFS_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_CHANGE_RANGE_CMD()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_MDL1_REQUEST()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_MDL1_REQUEST_CNF()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_ACK_CMD()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_MDL1_PTP_START_CMD()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_PTP_DONE_CNF()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_INIT_IDEL_GEAR_DONE()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_DEBUG_HEX()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_DEBUG()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_LOCK_DVFS_PTP()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_IMCPLL_SDM_PCW()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_PMIC_PLL_STATUS_CHECK()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_CHIP_SW_VERSION()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_HW_CURRENT_GEAR()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_UPPER_BOUND_CHANGE()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_SET_SCH_WIN()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_SET_IMM_EVENT()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_ACTIVE_WINDOW()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_META_RETURN()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_LTE_GEAR_CONVERTER()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_GEAR_CONVERTER()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_PTP_VOLT_DATA()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()
#define ChkL1MsgFltr_MODEML1_DVFS_TRACE_PTP_STATUS()	ChkL1ClsFltr_MODEML1_DVFS_1_MODEML1_DVFS_H()


#endif
