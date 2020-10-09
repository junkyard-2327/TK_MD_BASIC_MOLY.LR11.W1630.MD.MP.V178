#ifndef L1TRC_UL1D_HSPA_SEC_DEF_H
#define L1TRC_UL1D_HSPA_SEC_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_MS3_ACTION(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_DD_SRC(v1)  (unsigned char)(v1+4)
#define UL1D_TRC_STR_MS3_PROC_ACTION(v1)  (unsigned char)(v1+8)
#define UL1D_TRC_STR_DFE_LNA_STATE(v1)  (unsigned char)(v1+18)
#define UL1D_TRC_STR_FSM_STATE(v1)  (unsigned char)(v1+22)
#define UL1D_TRC_STR_FREQ_IDX(v1)  (unsigned char)(v1+29)
#define UL1D_TRC_STR_REMAPPING_FREQ_IDX(v1)  (unsigned char)(v1+34)
#define UL1D_TRC_STR_FEC_CASE(v1)  (unsigned char)(v1+55)
#define UL1D_TRC_STR_CASE(v1)  (unsigned char)(v1+71)
#define UL1D_TRC_STR_IMD2_STATUS(v1)  (unsigned char)(v1+84)
#define UL1D_TRC_STR_ANT_SEL(v1)  (unsigned char)(v1+89)
#define UL1D_TRC_STR_RXDFE_DBG(v1)  (unsigned char)(v1+92)
#define UL1D_TRC_STR_FHC_STATE_DBG(v1)  (unsigned char)(v1+135)
#define UL1D_HSPA_TRC1_E_SC(v1)  (unsigned char)(v1+144)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_ST_MASK_DBG1(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0023, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_ST_MASK_DBG1(v1, v2, v3, v4)
#endif
#define UL1D_TRC_CS_ST_MASK_DBG1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0023, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_ST_MASK_DBG2(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0123, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_ST_MASK_DBG2(v1, v2)
#endif
#define UL1D_TRC_CS_ST_MASK_DBG2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0123, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEQ_CON_R6S(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0223, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_SEQ_CON_R6S(v1, v2, v3, v4)
#endif
#define UL1D_TRC_SEQ_CON_R6S_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0223, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MS3_ABORT_R6S(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0323, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MS3_ABORT_R6S(v1, v2, v3)
#endif
#define UL1D_TRC_MS3_ABORT_R6S_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0323, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_Meas_Avg_R6S(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0423, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_Meas_Avg_R6S(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_Meas_Avg_R6S_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0423, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_RXD_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0523, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v7), (short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v5), (char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_RXD_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define UL1D_TRC_MEAS_RXD_MEAS_OPT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0523, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v7), (short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v5), (char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_MEAS_OPT_E2(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0623, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_1S2C((short)(v8), (char)(v2), (unsigned char)(v7)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_OPT_E2(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_MEAS_MEAS_OPT_E2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0623, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_1S2C((short)(v8), (char)(v2), (unsigned char)(v7)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0723, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_4C((char)(v2), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_MEAS_MEAS_OPT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0723, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_4C((char)(v2), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0823, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_RXD_MEAS_OPT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0823, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_PROHIBITED_TIMER_START(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0923, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_PROHIBITED_TIMER_START(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_PROHIBITED_TIMER_START_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0923, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_PROHIBITED_TIMER_EXPIRY(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A23, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_PROHIBITED_TIMER_EXPIRY(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_PROHIBITED_TIMER_EXPIRY_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A23, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEQ_PROC_CON(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0B23, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SEQ_PROC_CON(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_SEQ_PROC_CON_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0B23, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MEAS_PATH_R6S(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0C23, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_PATH_R6S(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1D_TRC_MEAS_PATH_R6S_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0C23, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DD_RESULT_R6S(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D23, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DD_RESULT_R6S(v1, v2, v3)
#endif
#define UL1D_TRC_DD_RESULT_R6S_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D23, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DD_RESULT_MPS(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E23, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_DD_RESULT_MPS(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DD_RESULT_MPS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E23, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DBG_SG_R6S(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F23, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DBG_SG_R6S(v1, v2, v3)
#endif
#define UL1D_TRC_DBG_SG_R6S_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F23, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DBG_2STAGE(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1023, (unsigned short)(v1)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DBG_2STAGE(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_DBG_2STAGE_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1023, (unsigned short)(v1)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS3_2STAGE_TIMING_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1123, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v7)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_CS3_2STAGE_TIMING_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_CS3_2STAGE_TIMING_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1123, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v7)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CALC_CELL_TIME(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1223, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_CALC_CELL_TIME(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_CALC_CELL_TIME_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1223, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DBG_TIMED_CELL_FOUND(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1323, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_DBG_TIMED_CELL_FOUND(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DBG_TIMED_CELL_FOUND_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1323, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DBG_NON_TIMED_CELL_FOUND(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1423, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DBG_NON_TIMED_CELL_FOUND(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_DBG_NON_TIMED_CELL_FOUND_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1423, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_IQGAINPHASE(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1523, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_IQGAINPHASE(v1, v2)
#endif
#define UL1D_TRC_HW_RXDFE_IQGAINPHASE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1523, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_RXDFE_CURR_STA_AGC(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1623, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CURR_STA_AGC(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_HW_RXDFE_CURR_STA_AGC_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1623, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_RXDFE_CURR_DCIQ(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1723, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CURR_DCIQ(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXDFE_CURR_DCIQ_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1723, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_RXDFE_INT_STA_RSSI(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1823, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_INT_STA_RSSI(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HW_RXDFE_INT_STA_RSSI_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1823, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_EST_DCIQ(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1923, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_EST_DCIQ(v1, v2)
#endif
#define UL1D_TRC_HW_RXDFE_EST_DCIQ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1923, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_HDC_VALIDE01(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A23, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_HDC_VALIDE01(v1, v2)
#endif
#define UL1D_TRC_HW_RXDFE_HDC_VALIDE01_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A23, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_AD_SCALER_CLIP(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_AD_SCALER_CLIP(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXDFE_AD_SCALER_CLIP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_RSSI(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C23, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_RSSI(v1, v2, v3)
#endif
#define UL1D_TRC_HW_RXDFE_RSSI_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C23, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_SLOT_RSSI(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_SLOT_RSSI(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXDFE_SLOT_RSSI_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_DC_FL(v1) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E23, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_DC_FL(v1)
#endif
#define UL1D_TRC_HW_RXDFE_DC_FL_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E23, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG2(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2023, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG2(v1, v2)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2023, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG3(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2123, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG3(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2123, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG4(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2223, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG4(v1, v2, v3)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG4_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2223, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG5(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2323, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG5(v1, v2, v3)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG5_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2323, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG6(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2423, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG6(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG6_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2423, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG7(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2523, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG7(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG7_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2523, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG8(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2623, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG8(v1, v2)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG8_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2623, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_IMD2_LMS_COEFF(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2723, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_IMD2_LMS_COEFF(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_IMD2_LMS_COEFF_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2723, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_IMD2_LMS_STA_DC(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2823, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_IMD2_LMS_STA_DC(v1, v2, v3, v4)
#endif
#define UL1D_TRC_IMD2_LMS_STA_DC_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2823, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_CMB(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2923, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_CMB(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_EHI_DBG_CMB_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2923, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_CMB_COM(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A23, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_CMB_COM(v1, v2)
#endif
#define UL1D_TRC_EHI_DBG_CMB_COM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A23, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_ALL(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B23, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_ALL(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_EHI_DBG_ALL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B23, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_RAKE_RFM_FNG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C23, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_RAKE_RFM_FNG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_EHI_DBG_RAKE_RFM_FNG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C23, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_FNG_MIC_PWR(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D23, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v8), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_FNG_MIC_PWR(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_EHI_DBG_FNG_MIC_PWR_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D23, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v8), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_SOFT(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2E23, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_SOFT(v1, v2)
#endif
#define UL1D_TRC_EHI_DBG_SOFT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2E23, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_CG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F23, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_CG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_EHI_DBG_CG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F23, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG1_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3023, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG1_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG1_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3023, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG1_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3123, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG1_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG1_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3123, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG1_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3223, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG1_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG1_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3223, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_DBG1_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3323, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG1_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG1_INT32X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3323, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG2_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3423, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG2_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG2_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3423, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG2_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3523, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG2_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG2_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3523, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG2_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3623, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG2_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG2_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3623, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG2_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3723, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG2_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG2_INT32X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3723, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG3_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3823, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG3_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG3_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3823, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG3_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3923, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG3_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG3_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3923, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG3_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3A23, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG3_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG3_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3A23, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG3_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3B23, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG3_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG3_INT32X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3B23, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_DBG4_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3C23, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG4_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG4_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3C23, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_DBG4_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3D23, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG4_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG4_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3D23, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_DBG4_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3E23, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG4_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG4_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3E23, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_DBG4_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3F23, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG4_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG4_INT32X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3F23, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFPWRCTRL(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4023, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_RFPWRCTRL(v1, v2, v3)
#endif
#define UL1D_TRC_RFPWRCTRL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4023, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RFDMPWRCTRL(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4123, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFDMPWRCTRL(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RFDMPWRCTRL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4123, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_AUX_DBG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4223, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_AUX_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_AUX_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4223, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_DYN_THRESH_TICK(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4323, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_DYN_THRESH_TICK(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_RG_DYN_THRESH_TICK_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4323, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_DYN_THRESH_SG_STATE_CHANGE(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4423, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_DYN_THRESH_SG_STATE_CHANGE(v1, v2)
#endif
#define UL1D_TRC_ERX_RG_DYN_THRESH_SG_STATE_CHANGE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4423, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_DYN_THRESH_RESTORE(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4523, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_DYN_THRESH_RESTORE(v1, v2)
#endif
#define UL1D_TRC_ERX_RG_DYN_THRESH_RESTORE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4523, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_DYN_THRESH_RESET(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4623, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_DYN_THRESH_RESET(v1, v2)
#endif
#define UL1D_TRC_ERX_RG_DYN_THRESH_RESET_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4623, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HIRG_THRESH_BY_CPICH(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4723, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HIRG_THRESH_BY_CPICH(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_ERX_HIRG_THRESH_BY_CPICH_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4723, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_LOW_INT(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4823, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_LOW_INT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_RG_LOW_INT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4823, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HI_FILTER_STATUS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4923, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), (unsigned char)(v13), TRC_BOXSTER_PAD), (unsigned long)(v14));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_FILTER_STATUS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#endif
#define UL1D_TRC_ERX_HI_FILTER_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4923, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), (unsigned char)(v13), TRC_BOXSTER_PAD), (unsigned long)(v14))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HI_NACK_BOOST(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A23, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_NACK_BOOST(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_HI_NACK_BOOST_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A23, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_RXPOST(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4B23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_RXPOST(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RXDFE_RXPOST_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4B23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_RXPOST_L(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x4C23, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_RXPOST_L(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RXDFE_RXPOST_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x4C23, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_RXPOST_FULL(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x4D23, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_RXPOST_FULL(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_RXDFE_RXPOST_FULL_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x4D23, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FHC_DBG1_INT16(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4E23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FHC_DBG1_INT16(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FHC_DBG1_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4E23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FHC_DBG1_INT16X(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4F23, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FHC_DBG1_INT16X(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FHC_DBG1_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4F23, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FHC_DBG1_INT32(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x5023, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_FHC_DBG1_INT32(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FHC_DBG1_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x5023, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FHC_DBG1_INT32X(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x5123, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_FHC_DBG1_INT32X(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FHC_DBG1_INT32X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x5123, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FHC_STATE(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5223, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FHC_STATE(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FHC_STATE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5223, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXD_TESTMODE() do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5323, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_TESTMODE()
#endif
#define UL1D_TRC_RXD_TESTMODE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5323, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_IDLE_CM(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5423, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_IDLE_CM(v1, v2, v3, v4)
#endif
#define UL1D_TRC_IDLE_CM_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5423, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_MEAS_START(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5523, (unsigned short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_MEAS_START(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_RXD_MEAS_START_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5523, (unsigned short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_MPS_START(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5623, (unsigned short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_MPS_START(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_RXD_MPS_START_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5623, (unsigned short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_SET_MS3_PARM(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5723, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_RXD_SET_MS3_PARM(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RXD_SET_MS3_PARM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5723, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_CS3_2STAGE_START(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5823, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_CS3_2STAGE_START(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_RXD_CS3_2STAGE_START_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5823, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_CS_SET_PARM(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5923, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define UL1D_TRC_RXD_CS_SET_PARM(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_RXD_CS_SET_PARM_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5923, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_IDLE_RXD_TURN_ON(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A23, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_IDLE_RXD_TURN_ON(v1, v2, v3)
#endif
#define UL1D_TRC_IDLE_RXD_TURN_ON_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A23, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_LISR_DBG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5B23, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_LISR_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RXD_LISR_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5B23, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_IDLE_FREE_RXD_DEBUG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5C23, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_IDLE_FREE_RXD_DEBUG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_IDLE_FREE_RXD_DEBUG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5C23, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_TX_OFFSET(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5D23, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FEC_TX_OFFSET(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_FEC_TX_OFFSET_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5D23, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_CURR_STA_AGC1(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x5E23, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_FEC_CURR_STA_AGC1(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FEC_CURR_STA_AGC1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x5E23, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_CURR_RSSI(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5F23, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FEC_CURR_RSSI(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FEC_CURR_RSSI_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5F23, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_CURR_DCIQ(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x6023, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4), (long)(v5), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define UL1D_TRC_FEC_CURR_DCIQ(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_FEC_CURR_DCIQ_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_7_DATA(TRC_MERGE_2S(0x6023, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4), (long)(v5), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_CURR_STA_AGC2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x6123, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (unsigned char)(v5)), (long)(v10));\
	} while(0)
#else
	#define UL1D_TRC_FEC_CURR_STA_AGC2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define UL1D_TRC_FEC_CURR_STA_AGC2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x6123, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (unsigned char)(v5)), (long)(v10))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_CURR_STA_AGC3(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x6223, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define UL1D_TRC_FEC_CURR_STA_AGC3(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_FEC_CURR_STA_AGC3_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x6223, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_CURR_STA_AGC4(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6323, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_FEC_CURR_STA_AGC4(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FEC_CURR_STA_AGC4_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6323, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_READ_RSSI(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6423, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v7), (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_FEC_READ_RSSI(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FEC_READ_RSSI_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6423, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v7), (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_ONOFF(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6523, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_FEC_ONOFF(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_FEC_ONOFF_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6523, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_FEC_GAIN(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6623, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FEC_GAIN(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FEC_GAIN_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6623, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_GENERAL_DBG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6723, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_FEC_GENERAL_DBG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_FEC_GENERAL_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6723, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_FREQIDX(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6823, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_FEC_FREQIDX(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FEC_FREQIDX_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6823, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_FREQIDX2(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6923, (short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_FEC_FREQIDX2(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_FEC_FREQIDX2_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6923, (short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_INIT1(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6A23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (unsigned long)(v4), (long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_FEC_INIT1(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_FEC_INIT1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6A23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (unsigned long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_INIT2(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6B23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_FEC_INIT2(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FEC_INIT2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6B23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_FEC_PATHLOSS1(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x6C23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v13));\
	} while(0)
#else
	#define UL1D_TRC_FEC_PATHLOSS1(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#endif
#define UL1D_TRC_FEC_PATHLOSS1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) TRC_SEND_8_DATA(TRC_MERGE_2S(0x6C23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v13))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_PATHLOSS2(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x6D23, (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_FEC_PATHLOSS2(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FEC_PATHLOSS2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_7_DATA(TRC_MERGE_2S(0x6D23, (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_META_DBG(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x6E23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v8)), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define UL1D_TRC_FEC_META_DBG(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FEC_META_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x6E23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v8)), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_ADJUST_SP(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6F23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_FEC_ADJUST_SP(v1, v2, v3)
#endif
#define UL1D_TRC_FEC_ADJUST_SP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6F23, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_DC_TABLE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_2S(0x7023, (short)(v2)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_2S((short)(v17), (short)(v18)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_FEC_DC_TABLE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18)
#endif
#define UL1D_TRC_FEC_DC_TABLE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18) TRC_SEND_11_DATA(TRC_MERGE_2S(0x7023, (short)(v2)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_2S((short)(v17), (short)(v18)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_ARX(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7123, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_FEC_ARX(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_FEC_ARX_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7123, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_ARX_OB(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7223, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_FEC_ARX_OB(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_FEC_ARX_OB_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7223, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FEC_ELNA(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7323, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_FEC_ELNA(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_FEC_ELNA_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7323, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_ONE_SLOT_DIFF(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x7423, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_CS_ONE_SLOT_DIFF(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_CS_ONE_SLOT_DIFF_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x7423, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_TRIGGER_EXTEND_RLF(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7523, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_TRIGGER_EXTEND_RLF(v1, v2)
#endif
#define UL1D_TRC_CS_TRIGGER_EXTEND_RLF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7523, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_HSPA_SEC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_CS_ST_MASK_DBG1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_CS_ST_MASK_DBG2(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_SEQ_CON_R6S(unsigned short v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_MS3_ABORT_R6S(unsigned short v1, long v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_Meas_Avg_R6S(unsigned short v1, unsigned short v2, unsigned char v3, unsigned char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1D_TRC_MEAS_RXD_MEAS_OPT(unsigned short v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned char v5, char v6, unsigned short v7, short v8, unsigned short v9, unsigned short v10, short v11, short v12);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_OPT_E2(unsigned short v1, char v2, unsigned short v3, short v4, unsigned short v5, unsigned short v6, unsigned char v7, short v8);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_OPT(unsigned short v1, char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned char v7, short v8, short v9);
void L1TRC_Send_UL1D_TRC_RXD_MEAS_OPT(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_MEAS_PROHIBITED_TIMER_START(unsigned short v1, long v2, long v3);
void L1TRC_Send_UL1D_TRC_MEAS_PROHIBITED_TIMER_EXPIRY(unsigned short v1, long v2, short v3);
void L1TRC_Send_UL1D_TRC_SEQ_PROC_CON(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_UL1D_TRC_MEAS_PATH_R6S(char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10);
void L1TRC_Send_UL1D_TRC_DD_RESULT_R6S(unsigned char v1, short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_DD_RESULT_MPS(unsigned char v1, unsigned char v2, short v3, short v4, short v5, unsigned short v6, unsigned short v7, unsigned short v8);
void L1TRC_Send_UL1D_TRC_DBG_SG_R6S(unsigned char v1, unsigned char v2, short v3);
void L1TRC_Send_UL1D_TRC_DBG_2STAGE(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_CS3_2STAGE_TIMING_INFO(unsigned short v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, short v7);
void L1TRC_Send_UL1D_TRC_CALC_CELL_TIME(short v1, unsigned long v2, short v3, short v4, short v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_DBG_TIMED_CELL_FOUND(unsigned short v1, short v2, short v3, short v4, short v5, short v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_UL1D_TRC_DBG_NON_TIMED_CELL_FOUND(unsigned short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_IQGAINPHASE(short v1, short v2);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CURR_STA_AGC(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CURR_DCIQ(short v1, short v2, long v3, long v4);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_INT_STA_RSSI(unsigned char v1, unsigned char v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_EST_DCIQ(long v1, long v2);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_HDC_VALIDE01(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_AD_SCALER_CLIP(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_RSSI(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_SLOT_RSSI(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_DC_FL(unsigned long v1);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG2(short v1, short v2);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG3(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG4(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG5(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG6(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG7(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG8(short v1, short v2);
void L1TRC_Send_UL1D_TRC_IMD2_LMS_COEFF(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_IMD2_LMS_STA_DC(unsigned char v1, short v2, long v3, long v4);
void L1TRC_Send_UL1D_TRC_EHI_DBG_CMB(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_UL1D_TRC_EHI_DBG_CMB_COM(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_EHI_DBG_ALL(unsigned short v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_EHI_DBG_RAKE_RFM_FNG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_EHI_DBG_FNG_MIC_PWR(unsigned char v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned char v5, unsigned short v6, unsigned char v7, unsigned short v8);
void L1TRC_Send_UL1D_TRC_EHI_DBG_SOFT(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_EHI_DBG_CG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG1_INT16(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG1_INT16X(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16, unsigned short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG1_INT32(unsigned char v1, unsigned char v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12, long v13, long v14, long v15, long v16, long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG1_INT32X(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16, unsigned long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG2_INT16(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG2_INT16X(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16, unsigned short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG2_INT32(unsigned char v1, unsigned char v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12, long v13, long v14, long v15, long v16, long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG2_INT32X(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16, unsigned long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG3_INT16(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG3_INT16X(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16, unsigned short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG3_INT32(unsigned char v1, unsigned char v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12, long v13, long v14, long v15, long v16, long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG3_INT32X(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16, unsigned long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG4_INT16(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG4_INT16X(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16, unsigned short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG4_INT32(unsigned char v1, unsigned char v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12, long v13, long v14, long v15, long v16, long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG4_INT32X(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16, unsigned long v17);
void L1TRC_Send_UL1D_TRC_RFPWRCTRL(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_RFDMPWRCTRL(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_AUX_DBG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_ERX_RG_DYN_THRESH_TICK(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_ERX_RG_DYN_THRESH_SG_STATE_CHANGE(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_ERX_RG_DYN_THRESH_RESTORE(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_ERX_RG_DYN_THRESH_RESET(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_ERX_HIRG_THRESH_BY_CPICH(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_ERX_RG_LOW_INT(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_ERX_HI_FILTER_STATUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12, unsigned char v13, unsigned long v14);
void L1TRC_Send_UL1D_TRC_ERX_HI_NACK_BOOST(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_RXDFE_RXPOST(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_RXDFE_RXPOST_L(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_RXDFE_RXPOST_FULL(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_UL1D_TRC_FHC_DBG1_INT16(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_FHC_DBG1_INT16X(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8);
void L1TRC_Send_UL1D_TRC_FHC_DBG1_INT32(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_UL1D_TRC_FHC_DBG1_INT32X(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_UL1D_TRC_FHC_STATE(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_RXD_TESTMODE(void);
void L1TRC_Send_UL1D_TRC_IDLE_CM(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_RXD_MEAS_START(unsigned short v1, unsigned char v2, unsigned char v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1D_TRC_RXD_MPS_START(unsigned short v1, unsigned char v2, unsigned char v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1D_TRC_RXD_SET_MS3_PARM(unsigned short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_RXD_CS3_2STAGE_START(unsigned short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_RXD_CS_SET_PARM(unsigned short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1D_TRC_IDLE_RXD_TURN_ON(unsigned short v1, short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_RXD_LISR_DBG(unsigned short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_IDLE_FREE_RXD_DEBUG(unsigned short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_FEC_TX_OFFSET(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_FEC_CURR_STA_AGC1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, short v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_UL1D_TRC_FEC_CURR_RSSI(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_FEC_CURR_DCIQ(unsigned char v1, short v2, short v3, long v4, long v5, unsigned char v6, short v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_UL1D_TRC_FEC_CURR_STA_AGC2(unsigned char v1, short v2, short v3, short v4, unsigned char v5, short v6, unsigned short v7, unsigned short v8, short v9, long v10, short v11);
void L1TRC_Send_UL1D_TRC_FEC_CURR_STA_AGC3(unsigned char v1, long v2, long v3, long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_UL1D_TRC_FEC_CURR_STA_AGC4(unsigned char v1, short v2, short v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_FEC_READ_RSSI(unsigned char v1, short v2, short v3, short v4, unsigned char v5, unsigned long v6, short v7, unsigned short v8);
void L1TRC_Send_UL1D_TRC_FEC_ONOFF(unsigned char v1, long v2, long v3, short v4, short v5, short v6, unsigned short v7);
void L1TRC_Send_UL1D_TRC_FEC_GAIN(short v1, short v2, short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_FEC_GENERAL_DBG(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_FEC_FREQIDX(long v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_FEC_FREQIDX2(short v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_UL1D_TRC_FEC_INIT1(short v1, short v2, short v3, unsigned long v4, long v5);
void L1TRC_Send_UL1D_TRC_FEC_INIT2(short v1, short v2, unsigned long v3, short v4);
void L1TRC_Send_UL1D_TRC_FEC_PATHLOSS1(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, unsigned long v13);
void L1TRC_Send_UL1D_TRC_FEC_PATHLOSS2(long v1, long v2, long v3, long v4, unsigned long v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_FEC_META_DBG(short v1, short v2, short v3, short v4, unsigned long v5, unsigned long v6, unsigned long v7, short v8);
void L1TRC_Send_UL1D_TRC_FEC_ADJUST_SP(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_FEC_DC_TABLE(unsigned char v1, short v2, long v3, long v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17, short v18);
void L1TRC_Send_UL1D_TRC_FEC_ARX(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_FEC_ARX_OB(unsigned long v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_FEC_ELNA(short v1, unsigned short v2, short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_CS_ONE_SLOT_DIFF(unsigned short v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_CS_TRIGGER_EXTEND_RLF(unsigned short v1, short v2);

void Set_UL1D_HSPA_SEC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_HSPA_SEC()	(UL1D_HSPA_SEC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_EHI_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_RXDFE_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_RXDFE_DUMP_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_IMD2_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG2_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG3_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RFPwrCtrl_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RFPwrCtrl_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_AUX_DBG_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HIRG_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HIRG_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x80)!=0))
#define ChkL1MsgFltr_UL1D_TRC_CS_ST_MASK_DBG1()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_ST_MASK_DBG2()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_SEQ_CON_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_MS3_ABORT_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_Meas_Avg_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_RXD_MEAS_OPT()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_OPT_E2()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_OPT()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_MEAS_OPT()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_PROHIBITED_TIMER_START()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_PROHIBITED_TIMER_EXPIRY()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_SEQ_PROC_CON()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_PATH_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_DD_RESULT_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_DD_RESULT_MPS()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_DBG_SG_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_DBG_2STAGE()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_CS3_2STAGE_TIMING_INFO()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_CALC_CELL_TIME()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_DBG_TIMED_CELL_FOUND()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_DBG_NON_TIMED_CELL_FOUND()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_IQGAINPHASE()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CURR_STA_AGC()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CURR_DCIQ()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_INT_STA_RSSI()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_EST_DCIQ()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_HDC_VALIDE01()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_AD_SCALER_CLIP()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_RSSI()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_SLOT_RSSI()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_DC_FL()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG2()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG3()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG4()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG5()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG6()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG7()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG8()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_IMD2_LMS_COEFF()	ChkL1ClsFltr_UL1D_HSPA_SEC_IMD2_L()
#define ChkL1MsgFltr_UL1D_TRC_IMD2_LMS_STA_DC()	ChkL1ClsFltr_UL1D_HSPA_SEC_IMD2_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_CMB()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_CMB_COM()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_ALL()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_RAKE_RFM_FNG()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_FNG_MIC_PWR()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_SOFT()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_CG()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG1_INT16()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG1_INT16X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG1_INT32()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG1_INT32X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG2_INT16()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG2_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG2_INT16X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG2_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG2_INT32()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG2_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG2_INT32X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG2_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG3_INT16()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG3_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG3_INT16X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG3_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG3_INT32()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG3_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG3_INT32X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG3_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG4_INT16()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG4_INT16X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG4_INT32()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG4_INT32X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RFPWRCTRL()	ChkL1ClsFltr_UL1D_HSPA_SEC_RFPwrCtrl_M()
#define ChkL1MsgFltr_UL1D_TRC_RFDMPWRCTRL()	ChkL1ClsFltr_UL1D_HSPA_SEC_RFPwrCtrl_H()
#define ChkL1MsgFltr_UL1D_TRC_AUX_DBG()	ChkL1ClsFltr_UL1D_HSPA_SEC_AUX_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_DYN_THRESH_TICK()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_DYN_THRESH_SG_STATE_CHANGE()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_DYN_THRESH_RESTORE()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_DYN_THRESH_RESET()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HIRG_THRESH_BY_CPICH()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HIRG_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_LOW_INT()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_FILTER_STATUS()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_NACK_BOOST()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_RXPOST()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_RXPOST_L()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_RXPOST_FULL()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_FHC_DBG1_INT16()	ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()
#define ChkL1MsgFltr_UL1D_TRC_FHC_DBG1_INT16X()	ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()
#define ChkL1MsgFltr_UL1D_TRC_FHC_DBG1_INT32()	ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()
#define ChkL1MsgFltr_UL1D_TRC_FHC_DBG1_INT32X()	ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()
#define ChkL1MsgFltr_UL1D_TRC_FHC_STATE()	ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()
#define ChkL1MsgFltr_UL1D_TRC_RXD_TESTMODE()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_M()
#define ChkL1MsgFltr_UL1D_TRC_IDLE_CM()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_MEAS_START()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_MPS_START()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_SET_MS3_PARM()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_CS3_2STAGE_START()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_CS_SET_PARM()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_IDLE_RXD_TURN_ON()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_LISR_DBG()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_IDLE_FREE_RXD_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_TX_OFFSET()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_CURR_STA_AGC1()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_CURR_RSSI()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_CURR_DCIQ()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_CURR_STA_AGC2()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_CURR_STA_AGC3()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_CURR_STA_AGC4()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_READ_RSSI()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_ONOFF()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_GAIN()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_L()
#define ChkL1MsgFltr_UL1D_TRC_FEC_GENERAL_DBG()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_FREQIDX()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_FREQIDX2()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_INIT1()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_INIT2()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_PATHLOSS1()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_L()
#define ChkL1MsgFltr_UL1D_TRC_FEC_PATHLOSS2()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_META_DBG()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_ADJUST_SP()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_DC_TABLE()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_ARX()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_ARX_OB()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_FEC_ELNA()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXFEC_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_ONE_SLOT_DIFF()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_TRIGGER_EXTEND_RLF()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()


#endif
