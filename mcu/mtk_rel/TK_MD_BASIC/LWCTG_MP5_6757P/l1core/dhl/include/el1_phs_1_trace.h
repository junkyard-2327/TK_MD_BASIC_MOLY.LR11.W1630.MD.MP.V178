#ifndef L1TRC_EL1_PHS_1_DEF_H
#define L1TRC_EL1_PHS_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define PHS_Func_String(v1)  (unsigned char)(v1+0)
#define PHS_Evt_String(v1)  (unsigned char)(v1+85)
#define PHS_Exe_Stus_String(v1)  (unsigned char)(v1+118)
#define PHS_Sub_Ctrl_String(v1)  (unsigned char)(v1+144)
#define PHS_Meas_Trig_String(v1)  (unsigned char)(v1+172)
#define PHS_Cnf_Type_String(v1)  (unsigned char)(v1+180)
#define PHS_EXE_PRE_CHK_String(v1)  (unsigned char)(v1+200)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FUNC_ENTRY(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0001, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_FUNC_ENTRY(v1)
#endif
#define PHS_LOG_FUNC_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0001, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FUNC_ENTRY_L(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0101, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_FUNC_ENTRY_L(v1)
#endif
#define PHS_LOG_FUNC_ENTRY_L_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0101, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SYS_TIME(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0201, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v5), (short)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_SYS_TIME(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_SYS_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0201, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v5), (short)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PDCCH_RPT(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0301, (unsigned char)(v3), (unsigned char)(v4)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_PDCCH_RPT(v1, v2, v3, v4)
#endif
#define PHS_LOG_PDCCH_RPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0301, (unsigned char)(v3), (unsigned char)(v4)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PHICH_RPT(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0401, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_PHICH_RPT(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_PHICH_RPT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0401, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_M_RNTI_RPT(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0501, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_M_RNTI_RPT(v1, v2, v3, v4)
#endif
#define PHS_LOG_M_RNTI_RPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0501, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SLP_IND_DROP() do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0601, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SLP_IND_DROP()
#endif
#define PHS_LOG_SLP_IND_DROP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0601, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_DELAY_DL_CHNG() do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0701, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_DELAY_DL_CHNG()
#endif
#define PHS_LOG_DELAY_DL_CHNG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0701, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXE_EVT_EXIST(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0801, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_EXE_EVT_EXIST(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define PHS_LOG_EXE_EVT_EXIST_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0801, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXE_EVT_CLEAR(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0901, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_EXE_EVT_CLEAR(v1)
#endif
#define PHS_LOG_EXE_EVT_CLEAR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0901, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXE_SUB_CTRL_EXIST(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0A01, (unsigned char)(v1), (unsigned char)(v6)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_EXE_SUB_CTRL_EXIST(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_EXE_SUB_CTRL_EXIST_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0A01, (unsigned char)(v1), (unsigned char)(v6)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCHDL_EVT_CHK(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0B01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_SCHDL_EVT_CHK(v1, v2, v3)
#endif
#define PHS_LOG_SCHDL_EVT_CHK_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0B01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCHDL_EVT_EXPIRE(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SCHDL_EVT_EXPIRE(v1, v2, v3)
#endif
#define PHS_LOG_SCHDL_EVT_EXPIRE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CTRL_EXE_STUS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0D01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), (unsigned char)(v13), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RX_CTRL_EXE_STUS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#endif
#define PHS_LOG_RX_CTRL_EXE_STUS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0D01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), (unsigned char)(v13), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CTRL_REQ1(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0E01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RX_CTRL_REQ1(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define PHS_LOG_RX_CTRL_REQ1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0E01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CTRL_REQ2(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RX_CTRL_REQ2(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define PHS_LOG_RX_CTRL_REQ2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CTRL_RNTI_P(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1001, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RX_CTRL_RNTI_P(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define PHS_LOG_RX_CTRL_RNTI_P_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1001, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CTRL_RNTI_S(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1101, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RX_CTRL_RNTI_S(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define PHS_LOG_RX_CTRL_RNTI_S_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1101, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SLEEP_TIME(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1201, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_SLEEP_TIME(v1, v2)
#endif
#define PHS_LOG_SLEEP_TIME_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1201, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SLEEP_PARAM(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1301, (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_SLEEP_PARAM(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_SLEEP_PARAM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1301, (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_UPDT_MCCH_INFO(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1401, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_UPDT_MCCH_INFO(v1)
#endif
#define PHS_LOG_UPDT_MCCH_INFO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1401, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_UPDT_PMCH_CFG(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1501, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_UPDT_PMCH_CFG(v1)
#endif
#define PHS_LOG_UPDT_PMCH_CFG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1501, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_MIB_RPT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1601, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_MIB_RPT(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_RCV_MIB_RPT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1601, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_RA_TC(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1701, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_RCV_RA_TC(v1, v2, v3, v4)
#endif
#define PHS_LOG_RCV_RA_TC_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1701, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_DRX_SLP(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1801, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_RCV_DRX_SLP(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_RCV_DRX_SLP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1801, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_DRX_CTRL(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1901, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_DRX_CTRL(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_RCV_DRX_CTRL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1901, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MAC_DRX_TRIG(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_MAC_DRX_TRIG(v1, v2)
#endif
#define PHS_LOG_MAC_DRX_TRIG_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_MEAS_CTRL(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1B01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_MEAS_CTRL(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_RCV_MEAS_CTRL_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1B01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_RAT_CHNG(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C01, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_RAT_CHNG(v1)
#endif
#define PHS_LOG_RCV_RAT_CHNG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C01, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_DL_CHNG(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D01, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_DL_CHNG(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_RCV_DL_CHNG_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D01, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_IRT_GAP_MEAS(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E01, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_RCV_IRT_GAP_MEAS(v1, v2)
#endif
#define PHS_LOG_RCV_IRT_GAP_MEAS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E01, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_IRT_MEAS(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F01, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_IRT_MEAS(v1)
#endif
#define PHS_LOG_RCV_IRT_MEAS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F01, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_GAP_CNCL(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2001, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_GAP_CNCL(v1)
#endif
#define PHS_LOG_RCV_GAP_CNCL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2001, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_MIB_SIB1_REQ(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2101, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_MIB_SIB1_REQ(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PHS_LOG_RCV_MIB_SIB1_REQ_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2101, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_MIB_CRC_CHK(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2201, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_MIB_CRC_CHK(v1, v2, v3, v4)
#endif
#define PHS_LOG_RCV_MIB_CRC_CHK_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2201, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_MIB_CRC_CHK_END(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2301, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_MIB_CRC_CHK_END(v1, v2, v3)
#endif
#define PHS_LOG_RCV_MIB_CRC_CHK_END_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2301, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_M_RNTI_CHNG_NTF(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2401, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_M_RNTI_CHNG_NTF(v1, v2, v3)
#endif
#define PHS_LOG_RCV_M_RNTI_CHNG_NTF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2401, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EVT_OP_ALLOW(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2501, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_EVT_OP_ALLOW(v1, v2, v3)
#endif
#define PHS_LOG_EVT_OP_ALLOW_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2501, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MB_MIB_PARAM(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2601, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_MB_MIB_PARAM(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_MB_MIB_PARAM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2601, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CMD_UPDT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2701, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_RX_CMD_UPDT(v1, v2)
#endif
#define PHS_LOG_RX_CMD_UPDT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2701, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CMD_UPDT_1(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2801, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RX_CMD_UPDT_1(v1, v2, v3, v4)
#endif
#define PHS_LOG_RX_CMD_UPDT_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2801, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CMD_UPDT_2(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2901, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RX_CMD_UPDT_2(v1, v2, v3)
#endif
#define PHS_LOG_RX_CMD_UPDT_2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2901, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CMD_UPDT_3(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RX_CMD_UPDT_3(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_RX_CMD_UPDT_3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CMD_UPDT_4(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2B01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RX_CMD_UPDT_4(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_RX_CMD_UPDT_4_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2B01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_CMD_PARAM(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2C01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_RX_CMD_PARAM(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_RX_CMD_PARAM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2C01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PRE_SYNC_CMD_UPDT(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D01, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define PHS_LOG_PRE_SYNC_CMD_UPDT(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_PRE_SYNC_CMD_UPDT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D01, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PRE_SYNC_CMD_PARAM(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2E01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_PRE_SYNC_CMD_PARAM(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_PRE_SYNC_CMD_PARAM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2E01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SUB_CTRL_EXE_STRT(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SUB_CTRL_EXE_STRT(v1, v2, v3, v4)
#endif
#define PHS_LOG_SUB_CTRL_EXE_STRT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SUB_CTRL_EXE_STOP(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3001, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SUB_CTRL_EXE_STOP(v1, v2, v3)
#endif
#define PHS_LOG_SUB_CTRL_EXE_STOP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3001, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CNCL_POST_RS(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3101, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_CNCL_POST_RS(v1, v2, v3)
#endif
#define PHS_LOG_CNCL_POST_RS_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3101, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_MIB_RX_EVT(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3201, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SRCH_MIB_RX_EVT(v1)
#endif
#define PHS_LOG_SRCH_MIB_RX_EVT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3201, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_EXE_EVT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3301, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_SRCH_EXE_EVT(v1, v2)
#endif
#define PHS_LOG_SRCH_EXE_EVT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3301, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_PRE_SYNC_EVT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3401, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_SRCH_PRE_SYNC_EVT(v1, v2)
#endif
#define PHS_LOG_SRCH_PRE_SYNC_EVT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3401, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_SRV_RX_EVT(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3501, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SRCH_SRV_RX_EVT(v1)
#endif
#define PHS_LOG_SRCH_SRV_RX_EVT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3501, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_SRV_RX_OP(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3601, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_SRCH_SRV_RX_OP(v1, v2, v3)
#endif
#define PHS_LOG_SRCH_SRV_RX_OP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3601, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_IF_EVT_EXE(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3701, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SRCH_IF_EVT_EXE(v1)
#endif
#define PHS_LOG_SRCH_IF_EVT_EXE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3701, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_NEAR_SRV_RX(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3801, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_SRCH_NEAR_SRV_RX(v1, v2, v3)
#endif
#define PHS_LOG_SRCH_NEAR_SRV_RX_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3801, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_NEAR_SRV_RX_1(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3901, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_SRCH_NEAR_SRV_RX_1(v1, v2, v3, v4)
#endif
#define PHS_LOG_SRCH_NEAR_SRV_RX_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3901, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_IDLE_PAG_OP(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3A01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_SRCH_IDLE_PAG_OP(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_SRCH_IDLE_PAG_OP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3A01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_RNTI_SUB_INDX(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3B01, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_SRCH_RNTI_SUB_INDX(v1, v2)
#endif
#define PHS_LOG_SRCH_RNTI_SUB_INDX_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3B01, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_EVT_ALLOW_STRT(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3C01, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_SRCH_EVT_ALLOW_STRT(v1, v2, v3)
#endif
#define PHS_LOG_SRCH_EVT_ALLOW_STRT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3C01, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_EVT_ALLOW_END(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3D01, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_SRCH_EVT_ALLOW_END(v1, v2, v3)
#endif
#define PHS_LOG_SRCH_EVT_ALLOW_END_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3D01, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_HIGH_PRIOR_EXE(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E01, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_SRCH_HIGH_PRIOR_EXE(v1, v2)
#endif
#define PHS_LOG_SRCH_HIGH_PRIOR_EXE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E01, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_LOW_PRIOR_EXE(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SRCH_LOW_PRIOR_EXE(v1, v2, v3)
#endif
#define PHS_LOG_SRCH_LOW_PRIOR_EXE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_LIFE_TIME(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4001, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_GET_LIFE_TIME(v1, v2, v3)
#endif
#define PHS_LOG_GET_LIFE_TIME_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4001, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_LIFE_TIME_UPDT(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4101, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_LIFE_TIME_UPDT(v1, v2, v3)
#endif
#define PHS_LOG_LIFE_TIME_UPDT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4101, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCHDL_EVT_ADD(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4201, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_SCHDL_EVT_ADD(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_SCHDL_EVT_ADD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4201, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCHDL_EVT_ADD_1(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4301, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_SCHDL_EVT_ADD_1(v1, v2, v3, v4)
#endif
#define PHS_LOG_SCHDL_EVT_ADD_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4301, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCHDL_SUB_CTRL_ADD(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4401, (unsigned char)(v1), (unsigned char)(v6)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_SCHDL_SUB_CTRL_ADD(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_SCHDL_SUB_CTRL_ADD_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4401, (unsigned char)(v1), (unsigned char)(v6)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCHDL_EVT_EXE_CHK(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4501, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_SCHDL_EVT_EXE_CHK(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_SCHDL_EVT_EXE_CHK_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4501, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCHDL_EVT_EXE_CHK_1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x4601, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_SCHDL_EVT_EXE_CHK_1(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_SCHDL_EVT_EXE_CHK_1_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x4601, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NXT_SYNC_TIME(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4701, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define PHS_LOG_GET_NXT_SYNC_TIME(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_GET_NXT_SYNC_TIME_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4701, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NXT_SYNC_TIME_1(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4801, (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_GET_NXT_SYNC_TIME_1(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PHS_LOG_GET_NXT_SYNC_TIME_1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4801, (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NXT_SYNC_TIME_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x4901, (short)(v7)), TRC_MERGE_2S((short)(v8), (unsigned short)(v9)), TRC_MERGE_1S2C((unsigned short)(v10), (unsigned char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_GET_NXT_SYNC_TIME_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define PHS_LOG_GET_NXT_SYNC_TIME_2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x4901, (short)(v7)), TRC_MERGE_2S((short)(v8), (unsigned short)(v9)), TRC_MERGE_1S2C((unsigned short)(v10), (unsigned char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NXT_SYNC_TIME_3(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4A01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_GET_NXT_SYNC_TIME_3(v1, v2, v3, v4)
#endif
#define PHS_LOG_GET_NXT_SYNC_TIME_3_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4A01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NXT_SYNC_TIME_4(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4B01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_GET_NXT_SYNC_TIME_4(v1, v2, v3, v4)
#endif
#define PHS_LOG_GET_NXT_SYNC_TIME_4_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4B01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MB_PRE_SYNC_TIME(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4C01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_MB_PRE_SYNC_TIME(v1, v2, v3, v4)
#endif
#define PHS_LOG_MB_PRE_SYNC_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4C01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_INTRA_CM_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4D01, (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_1S2C((unsigned short)(v10), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define PHS_LOG_GET_INTRA_CM_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define PHS_LOG_GET_INTRA_CM_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4D01, (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_1S2C((unsigned short)(v10), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_INTRA_CM_TIME_1(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x4E01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define PHS_LOG_GET_INTRA_CM_TIME_1(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define PHS_LOG_GET_INTRA_CM_TIME_1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x4E01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NEW_TIME(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_GET_NEW_TIME(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_GET_NEW_TIME_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NEW_TIME_1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5001, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_GET_NEW_TIME_1(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_GET_NEW_TIME_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5001, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NEW_TIME_3(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5101, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_GET_NEW_TIME_3(v1, v2, v3)
#endif
#define PHS_LOG_GET_NEW_TIME_3_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5101, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NEW_TIME_4(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5201, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_GET_NEW_TIME_4(v1, v2, v3)
#endif
#define PHS_LOG_GET_NEW_TIME_4_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5201, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_BCCH_NEW_TIME(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5301, (unsigned char)(v1), (unsigned char)(v6)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_BCCH_NEW_TIME(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_BCCH_NEW_TIME_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5301, (unsigned char)(v1), (unsigned char)(v6)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_IDLE_DRX_TRIG(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5401, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_IDLE_DRX_TRIG(v1, v2, v3)
#endif
#define PHS_LOG_IDLE_DRX_TRIG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5401, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_TIMER_TIMEOUT(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5501, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_TIMER_TIMEOUT(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_TIMER_TIMEOUT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5501, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRV_RX_STOP(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5601, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SRV_RX_STOP(v1, v2, v3)
#endif
#define PHS_LOG_SRV_RX_STOP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5601, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRV_RX_ACTV(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5701, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_SRV_RX_ACTV(v1, v2)
#endif
#define PHS_LOG_SRV_RX_ACTV_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5701, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CH_CHNG_PARAM(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x5801, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_CH_CHNG_PARAM(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_CH_CHNG_PARAM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x5801, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CH_CHNG_FAIL_QUE(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5901, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_CH_CHNG_FAIL_QUE(v1, v2)
#endif
#define PHS_LOG_CH_CHNG_FAIL_QUE_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5901, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CH_CHNG_FAIL_SND(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_CH_CHNG_FAIL_SND(v1)
#endif
#define PHS_LOG_CH_CHNG_FAIL_SND_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CH_CHNG_QUE(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5B01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_CH_CHNG_QUE(v1)
#endif
#define PHS_LOG_CH_CHNG_QUE_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5B01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXE_CH_CHNG_QUE(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5C01, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_EXE_CH_CHNG_QUE(v1)
#endif
#define PHS_LOG_EXE_CH_CHNG_QUE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5C01, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MCH_CHNG(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5D01, (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_MCH_CHNG(v1, v2, v3, v4)
#endif
#define PHS_LOG_MCH_CHNG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5D01, (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MEAS_TRIG_INIT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x5E01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_MEAS_TRIG_INIT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_MEAS_TRIG_INIT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x5E01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MCH_CHNG_2(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5F01, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_MCH_CHNG_2(v1, v2)
#endif
#define PHS_LOG_MCH_CHNG_2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5F01, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MCH_CHNG_3(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6001, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_MCH_CHNG_3(v1, v2, v3)
#endif
#define PHS_LOG_MCH_CHNG_3_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6001, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SUB_CHNG_2(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6101, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_SUB_CHNG_2(v1, v2)
#endif
#define PHS_LOG_SUB_CHNG_2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6101, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SUB_CHNG_3(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6201, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_SUB_CHNG_3(v1, v2)
#endif
#define PHS_LOG_SUB_CHNG_3_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6201, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCELL_CHNG_2(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6301, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_SCELL_CHNG_2(v1, v2)
#endif
#define PHS_LOG_SCELL_CHNG_2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6301, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCELL_CHNG_3(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6401, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_SCELL_CHNG_3(v1, v2)
#endif
#define PHS_LOG_SCELL_CHNG_3_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6401, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_ABS_TO_LTE_TIME(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x6501, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define PHS_LOG_ABS_TO_LTE_TIME(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PHS_LOG_ABS_TO_LTE_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x6501, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PAST_ABS_TIME(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x6601, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_PAST_ABS_TIME(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_PAST_ABS_TIME_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x6601, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MIB_TIME_GET(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6701, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_MIB_TIME_GET(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_MIB_TIME_GET_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6701, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SIB1_TIME_GET(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6801, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_SIB1_TIME_GET(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_SIB1_TIME_GET_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6801, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SI_TIME_GET(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6901, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_SI_TIME_GET(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_SI_TIME_GET_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6901, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SI_PARAM_GET_1(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6A01, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)));\
	} while(0)
#else
	#define PHS_LOG_SI_PARAM_GET_1(v1, v2, v3, v4)
#endif
#define PHS_LOG_SI_PARAM_GET_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6A01, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SI_PARAM_GET_2(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6B01, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SI_PARAM_GET_2(v1, v2)
#endif
#define PHS_LOG_SI_PARAM_GET_2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6B01, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRV_MIB_BUF_RST(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x6C01, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_SRV_MIB_BUF_RST(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_SRV_MIB_BUF_RST_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x6C01, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NBR_MIB_BUF_RST(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6D01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define PHS_LOG_NBR_MIB_BUF_RST(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PHS_LOG_NBR_MIB_BUF_RST_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6D01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRV_SIB1_BUF_RST(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x6E01, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_SRV_SIB1_BUF_RST(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_SRV_SIB1_BUF_RST_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x6E01, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NBR_SIB1_BUF_RST(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_NBR_SIB1_BUF_RST(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_NBR_SIB1_BUF_RST_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NBR_TIME_CAL(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x7001, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5));\
	} while(0)
#else
	#define PHS_LOG_NBR_TIME_CAL(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_NBR_TIME_CAL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x7001, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRV_BCCH_TIME_GET_1(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7101, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_SRV_BCCH_TIME_GET_1(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_SRV_BCCH_TIME_GET_1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7101, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRV_BCCH_TIME_GET_2(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7201, (unsigned char)(v3), (unsigned char)(v5)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_SRV_BCCH_TIME_GET_2(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_SRV_BCCH_TIME_GET_2_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7201, (unsigned char)(v3), (unsigned char)(v5)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_R_NBR_BCCH_GET_1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7301, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_R_NBR_BCCH_GET_1(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_R_NBR_BCCH_GET_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7301, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_R_NBR_BCCH_GET_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x7401, (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v9)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7), (unsigned long)(v10), (unsigned long)(v11));\
	} while(0)
#else
	#define PHS_LOG_R_NBR_BCCH_GET_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define PHS_LOG_R_NBR_BCCH_GET_2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_8_DATA(TRC_MERGE_2S(0x7401, (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v9)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7), (unsigned long)(v10), (unsigned long)(v11))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_F_NBR_BCCH_GET_1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7501, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_F_NBR_BCCH_GET_1(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_F_NBR_BCCH_GET_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7501, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_F_NBR_BCCH_GET_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x7601, (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v9)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7), (unsigned long)(v10), (unsigned long)(v11));\
	} while(0)
#else
	#define PHS_LOG_F_NBR_BCCH_GET_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define PHS_LOG_F_NBR_BCCH_GET_2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_8_DATA(TRC_MERGE_2S(0x7601, (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v9)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7), (unsigned long)(v10), (unsigned long)(v11))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRV_PAG_TIME_GET_1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7701, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_SRV_PAG_TIME_GET_1(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_SRV_PAG_TIME_GET_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7701, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRV_PAG_TIME_GET_2(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7801, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_SRV_PAG_TIME_GET_2(v1, v2, v3)
#endif
#define PHS_LOG_SRV_PAG_TIME_GET_2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7801, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_M_RNTI_TIME_GET_1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x7901, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_M_RNTI_TIME_GET_1(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_M_RNTI_TIME_GET_1_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x7901, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_M_RNTI_TIME_GET_2(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7A01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_M_RNTI_TIME_GET_2(v1, v2)
#endif
#define PHS_LOG_M_RNTI_TIME_GET_2_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7A01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NBR_OFFST_GET(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x7B01, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define PHS_LOG_NBR_OFFST_GET(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PHS_LOG_NBR_OFFST_GET_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x7B01, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_NEAR_POS(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7C01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_SRCH_NEAR_POS(v1, v2, v3)
#endif
#define PHS_LOG_SRCH_NEAR_POS_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7C01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_NEAR_POS_1(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7D01, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_SRCH_NEAR_POS_1(v1, v2, v3, v4)
#endif
#define PHS_LOG_SRCH_NEAR_POS_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7D01, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXE_PRE_CHK(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7E01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_EXE_PRE_CHK(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_EXE_PRE_CHK_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7E01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_VMODE_PATTERN(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7F01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_VMODE_PATTERN(v1, v2, v3)
#endif
#define PHS_LOG_VMODE_PATTERN_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7F01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_VMODE_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x8001, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define PHS_LOG_VMODE_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define PHS_LOG_VMODE_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x8001, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_PHS_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_PHS_LOG_FUNC_ENTRY(unsigned char v1);
void L1TRC_Send_PHS_LOG_FUNC_ENTRY_L(unsigned char v1);
void L1TRC_Send_PHS_LOG_SYS_TIME(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned short v5, short v6, unsigned long v7);
void L1TRC_Send_PHS_LOG_PDCCH_RPT(unsigned long v1, unsigned long v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_PHICH_RPT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_M_RNTI_RPT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_SLP_IND_DROP(void);
void L1TRC_Send_PHS_LOG_DELAY_DL_CHNG(void);
void L1TRC_Send_PHS_LOG_EXE_EVT_EXIST(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned char v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_PHS_LOG_EXE_EVT_CLEAR(unsigned char v1);
void L1TRC_Send_PHS_LOG_EXE_SUB_CTRL_EXIST(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned char v6);
void L1TRC_Send_PHS_LOG_SCHDL_EVT_CHK(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_SCHDL_EVT_EXPIRE(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_RX_CTRL_EXE_STUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12, unsigned char v13);
void L1TRC_Send_PHS_LOG_RX_CTRL_REQ1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12);
void L1TRC_Send_PHS_LOG_RX_CTRL_REQ2(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_PHS_LOG_RX_CTRL_RNTI_P(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12);
void L1TRC_Send_PHS_LOG_RX_CTRL_RNTI_S(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12);
void L1TRC_Send_PHS_LOG_SLEEP_TIME(unsigned long v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_SLEEP_PARAM(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_UPDT_MCCH_INFO(unsigned char v1);
void L1TRC_Send_PHS_LOG_UPDT_PMCH_CFG(unsigned char v1);
void L1TRC_Send_PHS_LOG_RCV_MIB_RPT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_PHS_LOG_RCV_RA_TC(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_PHS_LOG_RCV_DRX_SLP(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_RCV_DRX_CTRL(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_PHS_LOG_MAC_DRX_TRIG(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_RCV_MEAS_CTRL(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_PHS_LOG_RCV_RAT_CHNG(unsigned char v1);
void L1TRC_Send_PHS_LOG_RCV_DL_CHNG(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_PHS_LOG_RCV_IRT_GAP_MEAS(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_RCV_IRT_MEAS(unsigned char v1);
void L1TRC_Send_PHS_LOG_RCV_GAP_CNCL(unsigned char v1);
void L1TRC_Send_PHS_LOG_RCV_MIB_SIB1_REQ(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_PHS_LOG_RCV_MIB_CRC_CHK(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_RCV_MIB_CRC_CHK_END(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_RCV_M_RNTI_CHNG_NTF(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_PHS_LOG_EVT_OP_ALLOW(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_MB_MIB_PARAM(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_RX_CMD_UPDT(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_RX_CMD_UPDT_1(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_RX_CMD_UPDT_2(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_RX_CMD_UPDT_3(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_RX_CMD_UPDT_4(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_PHS_LOG_RX_CMD_PARAM(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_PRE_SYNC_CMD_UPDT(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_PRE_SYNC_CMD_PARAM(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_SUB_CTRL_EXE_STRT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_SUB_CTRL_EXE_STOP(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_CNCL_POST_RS(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_SRCH_MIB_RX_EVT(unsigned char v1);
void L1TRC_Send_PHS_LOG_SRCH_EXE_EVT(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_SRCH_PRE_SYNC_EVT(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_SRCH_SRV_RX_EVT(unsigned char v1);
void L1TRC_Send_PHS_LOG_SRCH_SRV_RX_OP(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_SRCH_IF_EVT_EXE(unsigned char v1);
void L1TRC_Send_PHS_LOG_SRCH_NEAR_SRV_RX(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_SRCH_NEAR_SRV_RX_1(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_SRCH_IDLE_PAG_OP(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_SRCH_RNTI_SUB_INDX(unsigned long v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_SRCH_EVT_ALLOW_STRT(unsigned long v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_SRCH_EVT_ALLOW_END(unsigned long v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_SRCH_HIGH_PRIOR_EXE(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_SRCH_LOW_PRIOR_EXE(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_GET_LIFE_TIME(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_LIFE_TIME_UPDT(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_SCHDL_EVT_ADD(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_SCHDL_EVT_ADD_1(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_SCHDL_SUB_CTRL_ADD(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned char v6);
void L1TRC_Send_PHS_LOG_SCHDL_EVT_EXE_CHK(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_SCHDL_EVT_EXE_CHK_1(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned char v7);
void L1TRC_Send_PHS_LOG_GET_NXT_SYNC_TIME(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_PHS_LOG_GET_NXT_SYNC_TIME_1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned short v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_PHS_LOG_GET_NXT_SYNC_TIME_2(unsigned char v1, unsigned long v2, unsigned long v3, unsigned char v4, unsigned char v5, unsigned char v6, short v7, short v8, unsigned short v9, unsigned short v10);
void L1TRC_Send_PHS_LOG_GET_NXT_SYNC_TIME_3(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_GET_NXT_SYNC_TIME_4(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_MB_PRE_SYNC_TIME(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_GET_INTRA_CM_TIME(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10);
void L1TRC_Send_PHS_LOG_GET_INTRA_CM_TIME_1(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_PHS_LOG_GET_NEW_TIME(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_GET_NEW_TIME_1(unsigned char v1, unsigned long v2, unsigned long v3, unsigned short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_PHS_LOG_GET_NEW_TIME_3(unsigned char v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_PHS_LOG_GET_NEW_TIME_4(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_BCCH_NEW_TIME(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned char v6);
void L1TRC_Send_PHS_LOG_IDLE_DRX_TRIG(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_TIMER_TIMEOUT(unsigned long v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_SRV_RX_STOP(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_SRV_RX_ACTV(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_CH_CHNG_PARAM(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_CH_CHNG_FAIL_QUE(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_CH_CHNG_FAIL_SND(unsigned long v1);
void L1TRC_Send_PHS_LOG_CH_CHNG_QUE(unsigned long v1);
void L1TRC_Send_PHS_LOG_EXE_CH_CHNG_QUE(unsigned char v1);
void L1TRC_Send_PHS_LOG_MCH_CHNG(unsigned long v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_MEAS_TRIG_INIT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PHS_LOG_MCH_CHNG_2(unsigned long v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_MCH_CHNG_3(unsigned long v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_SUB_CHNG_2(unsigned long v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_SUB_CHNG_3(unsigned long v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_SCELL_CHNG_2(unsigned long v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_SCELL_CHNG_3(unsigned long v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_ABS_TO_LTE_TIME(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_PHS_LOG_PAST_ABS_TIME(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_MIB_TIME_GET(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_SIB1_TIME_GET(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_SI_TIME_GET(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_SI_PARAM_GET_1(unsigned char v1, unsigned short v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_PHS_LOG_SI_PARAM_GET_2(unsigned char v1, unsigned short v2);
void L1TRC_Send_PHS_LOG_SRV_MIB_BUF_RST(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_NBR_MIB_BUF_RST(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_PHS_LOG_SRV_SIB1_BUF_RST(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_NBR_SIB1_BUF_RST(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PHS_LOG_NBR_TIME_CAL(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, long v5);
void L1TRC_Send_PHS_LOG_SRV_BCCH_TIME_GET_1(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_SRV_BCCH_TIME_GET_2(unsigned long v1, unsigned long v2, unsigned char v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_R_NBR_BCCH_GET_1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_R_NBR_BCCH_GET_2(unsigned char v1, unsigned long v2, unsigned long v3, unsigned char v4, unsigned long v5, unsigned char v6, unsigned long v7, unsigned short v8, unsigned char v9, unsigned long v10, unsigned long v11);
void L1TRC_Send_PHS_LOG_F_NBR_BCCH_GET_1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_F_NBR_BCCH_GET_2(unsigned char v1, unsigned long v2, unsigned long v3, unsigned char v4, unsigned long v5, unsigned char v6, unsigned long v7, unsigned short v8, unsigned char v9, unsigned long v10, unsigned long v11);
void L1TRC_Send_PHS_LOG_SRV_PAG_TIME_GET_1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_SRV_PAG_TIME_GET_2(unsigned long v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_PHS_LOG_M_RNTI_TIME_GET_1(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PHS_LOG_M_RNTI_TIME_GET_2(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_NBR_OFFST_GET(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned long v5, long v6, long v7, long v8);
void L1TRC_Send_PHS_LOG_SRCH_NEAR_POS(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_SRCH_NEAR_POS_1(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_EXE_PRE_CHK(unsigned char v1, unsigned char v2, unsigned long v3, unsigned char v4, unsigned long v5, unsigned char v6, unsigned long v7);
void L1TRC_Send_PHS_LOG_VMODE_PATTERN(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_VMODE_TIME(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);

void Set_EL1_PHS_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_PHS_1()	(EL1_PHS_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_func_trace_l()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var2_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var2_trace_l()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace_l()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_error_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_msg_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_debug_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x10)!=0))
#define ChkL1MsgFltr_PHS_LOG_FUNC_ENTRY()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_FUNC_ENTRY_L()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SYS_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_PDCCH_RPT()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_PHICH_RPT()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_M_RNTI_RPT()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SLP_IND_DROP()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_DELAY_DL_CHNG()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_EXE_EVT_EXIST()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_EXE_EVT_CLEAR()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_EXE_SUB_CTRL_EXIST()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SCHDL_EVT_CHK()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SCHDL_EVT_EXPIRE()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RX_CTRL_EXE_STUS()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_RX_CTRL_REQ1()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_RX_CTRL_REQ2()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_RX_CTRL_RNTI_P()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_RX_CTRL_RNTI_S()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SLEEP_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SLEEP_PARAM()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_UPDT_MCCH_INFO()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_UPDT_PMCH_CFG()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_MIB_RPT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_RA_TC()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_DRX_SLP()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_DRX_CTRL()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_MAC_DRX_TRIG()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_MEAS_CTRL()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_RAT_CHNG()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_DL_CHNG()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_IRT_GAP_MEAS()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_IRT_MEAS()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_GAP_CNCL()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_MIB_SIB1_REQ()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_MIB_CRC_CHK()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_MIB_CRC_CHK_END()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_M_RNTI_CHNG_NTF()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_EVT_OP_ALLOW()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_MB_MIB_PARAM()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_RX_CMD_UPDT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_RX_CMD_UPDT_1()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RX_CMD_UPDT_2()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_RX_CMD_UPDT_3()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_RX_CMD_UPDT_4()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_RX_CMD_PARAM()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_PRE_SYNC_CMD_UPDT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_PRE_SYNC_CMD_PARAM()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SUB_CTRL_EXE_STRT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SUB_CTRL_EXE_STOP()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_CNCL_POST_RS()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_MIB_RX_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SRCH_EXE_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_PRE_SYNC_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_SRV_RX_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_SRV_RX_OP()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SRCH_IF_EVT_EXE()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SRCH_NEAR_SRV_RX()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SRCH_NEAR_SRV_RX_1()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_IDLE_PAG_OP()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_RNTI_SUB_INDX()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SRCH_EVT_ALLOW_STRT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_EVT_ALLOW_END()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_HIGH_PRIOR_EXE()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_LOW_PRIOR_EXE()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_LIFE_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_LIFE_TIME_UPDT()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SCHDL_EVT_ADD()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SCHDL_EVT_ADD_1()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SCHDL_SUB_CTRL_ADD()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SCHDL_EVT_EXE_CHK()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SCHDL_EVT_EXE_CHK_1()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_NXT_SYNC_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_NXT_SYNC_TIME_1()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_GET_NXT_SYNC_TIME_2()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_NXT_SYNC_TIME_3()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_GET_NXT_SYNC_TIME_4()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_MB_PRE_SYNC_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_GET_INTRA_CM_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_INTRA_CM_TIME_1()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_NEW_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_NEW_TIME_1()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_NEW_TIME_3()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_GET_NEW_TIME_4()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_BCCH_NEW_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_IDLE_DRX_TRIG()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_TIMER_TIMEOUT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRV_RX_STOP()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRV_RX_ACTV()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_CH_CHNG_PARAM()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_CH_CHNG_FAIL_QUE()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_CH_CHNG_FAIL_SND()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_CH_CHNG_QUE()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_EXE_CH_CHNG_QUE()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_MCH_CHNG()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_MEAS_TRIG_INIT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()
#define ChkL1MsgFltr_PHS_LOG_MCH_CHNG_2()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_MCH_CHNG_3()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SUB_CHNG_2()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SUB_CHNG_3()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SCELL_CHNG_2()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SCELL_CHNG_3()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_ABS_TO_LTE_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var2_trace_l()
#define ChkL1MsgFltr_PHS_LOG_PAST_ABS_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var2_trace()
#define ChkL1MsgFltr_PHS_LOG_MIB_TIME_GET()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SIB1_TIME_GET()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SI_TIME_GET()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SI_PARAM_GET_1()	ChkL1ClsFltr_EL1_PHS_1_phs_var2_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SI_PARAM_GET_2()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SRV_MIB_BUF_RST()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_NBR_MIB_BUF_RST()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SRV_SIB1_BUF_RST()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_NBR_SIB1_BUF_RST()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_NBR_TIME_CAL()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SRV_BCCH_TIME_GET_1()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SRV_BCCH_TIME_GET_2()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_R_NBR_BCCH_GET_1()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_R_NBR_BCCH_GET_2()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_F_NBR_BCCH_GET_1()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_F_NBR_BCCH_GET_2()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SRV_PAG_TIME_GET_1()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SRV_PAG_TIME_GET_2()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_M_RNTI_TIME_GET_1()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_M_RNTI_TIME_GET_2()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_NBR_OFFST_GET()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_NEAR_POS()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_SRCH_NEAR_POS_1()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_EXE_PRE_CHK()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_VMODE_PATTERN()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_VMODE_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()


#endif
