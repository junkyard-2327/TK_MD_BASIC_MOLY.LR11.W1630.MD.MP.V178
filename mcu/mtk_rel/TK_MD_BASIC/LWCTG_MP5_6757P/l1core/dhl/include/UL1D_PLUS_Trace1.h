#ifndef L1TRC_UL1D_PLUS_PRI_DEF_H
#define L1TRC_UL1D_PLUS_PRI_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_HSPA_PLUS_TICK(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_DECIDE_HSSCCH(v1)  (unsigned char)(v1+4)
#define UL1D_TRC_STR_DECIDE_EAGCH(v1)  (unsigned char)(v1+12)
#define UL1D_TRC_STR_DECIDE_ERGCH_NSERV(v1)  (unsigned char)(v1+22)
#define UL1D_TRC_STR_DECIDE_EHICH(v1)  (unsigned char)(v1+28)
#define UL1D_TRC_STR_DECIDE_CQI(v1)  (unsigned char)(v1+32)
#define UL1D_TRC_STR_DECIDE_MAC_DTX_PTN(v1)  (unsigned char)(v1+43)
#define UL1D_TRC_STR_ERX_CHANNEL(v1)  (unsigned char)(v1+48)
#define UL1D_TRC_STR_DSCH_HRNTI(v1)  (unsigned char)(v1+52)
#define UL1D_TRC_STR_MISS_DECODE_DONE(v1)  (unsigned char)(v1+58)
#define UL1D_TRC_STR_CEDCH_PREAMBE_STATE(v1)  (unsigned char)(v1+66)
#define UL1D_TRC_STR_CEDCH_STATE(v1)  (unsigned char)(v1+73)
#define UL1D_TRC_STR_EPCH_STATE(v1)  (unsigned char)(v1+81)
#define UL1D_TRC_STR_PICH_RX_MODE(v1)  (unsigned char)(v1+87)
#define UL1D_TRC_STR_EFACH_STATE(v1)  (unsigned char)(v1+90)
#define UL1D_TRC_STR_EFACH_DRX_EVENT(v1)  (unsigned char)(v1+96)
#define UL1D_TRC_STR_EFACH_DRX_STATE(v1)  (unsigned char)(v1+101)
#define UL1D_TRC_STR_EFACH_DRX_STATUS(v1)  (unsigned char)(v1+105)
#define UL1D_TRC_STR_CEDCH_EVENT(v1)  (unsigned char)(v1+108)
#define UL1D_TRC_STR_CEDCH_TTI(v1)  (unsigned char)(v1+112)
#define UL1D_TRC_STR_EAI_RESULT(v1)  (unsigned char)(v1+114)
#define UL1D_TRC_STR_RAKE_CPICH_ONOFF(v1)  (unsigned char)(v1+118)
#define UL1D_TRC_STR_MIRROR_FINGER_STATUS(v1)  (unsigned char)(v1+123)
#define UL1D_TRC_STR_HSCE_CONFIG_TIMING(v1)  (unsigned char)(v1+127)
#define UL1D_TRC_STR_OPTI_CMB_GENERAL(v1)  (unsigned char)(v1+132)
#define UL1D_TRC_STR_OPTI_CMB_FACH(v1)  (unsigned char)(v1+135)
#define UL1D_TRC_STR_OPTI_CMB_DCH(v1)  (unsigned char)(v1+138)
#define UL1D_TRC_STR_RFM_DEACTIVE_REASON(v1)  (unsigned char)(v1+144)
#define UL1D_TRC_STR_HOP3G_PLL_TYPE(v1)  (unsigned char)(v1+149)
#define UL1D_PLUS_TRC1_E_SC(v1)  (unsigned char)(v1+151)
#define UL1D_PLUS_TRC1_DL_CARR(v1)  (unsigned char)(v1+154)
#define UL1D_TRC_STR_RF_CTRL_EVENT(v1)  (unsigned char)(v1+157)
#define UL1D_TRC_STR_SKIP_RFM_REASON(v1)  (unsigned char)(v1+161)
#define UL1D_TRC_STR_RAS(v1)  (unsigned char)(v1+164)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CPC_CONFID1(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0025, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CPC_CONFID1(v1, v2, v3)
#endif
#define UL1D_TRC_CPC_CONFID1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0025, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CPC_ENABLED(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0125, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CPC_ENABLED(v1, v2)
#endif
#define UL1D_TRC_CPC_ENABLED_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0125, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CPC_ORDER(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0225, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CPC_ORDER(v1, v2, v3, v4)
#endif
#define UL1D_TRC_CPC_ORDER_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0225, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CPC_FORECAST_ERR(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0325, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_CPC_FORECAST_ERR(v1, v2, v3, v4)
#endif
#define UL1D_TRC_CPC_FORECAST_ERR_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0325, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TICK_ENTRY(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0425, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TICK_ENTRY(v1, v2, v3)
#endif
#define UL1D_TRC_TICK_ENTRY_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0425, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CARRY_HSSCCH(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0525, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CARRY_HSSCCH(v1, v2, v3)
#endif
#define UL1D_TRC_CARRY_HSSCCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0525, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DECIDE_HSSCCH(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0625, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_DECIDE_HSSCCH(v1, v2)
#endif
#define UL1D_TRC_DECIDE_HSSCCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0625, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSSCCH_CPC_DECISION(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0725, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSSCCH_CPC_DECISION(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSSCCH_CPC_DECISION_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0725, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PROGRAM_HSSCCH(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0825, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v2), (unsigned char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_PROGRAM_HSSCCH(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_PROGRAM_HSSCCH_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0825, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v2), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DECIDE_EAGCH(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0925, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DECIDE_EAGCH(v1, v2, v3)
#endif
#define UL1D_TRC_DECIDE_EAGCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0925, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DECIDE_ERGCH_SERV(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DECIDE_ERGCH_SERV(v1, v2, v3)
#endif
#define UL1D_TRC_DECIDE_ERGCH_SERV_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DECIDE_ERGCH_NSERV(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DECIDE_ERGCH_NSERV(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DECIDE_ERGCH_NSERV_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DECIDE_EHICH(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DECIDE_EHICH(v1, v2, v3)
#endif
#define UL1D_TRC_DECIDE_EHICH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PROGRAM_ERX_SERV(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)));\
	} while(0)
#else
	#define UL1D_TRC_PROGRAM_ERX_SERV(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1D_TRC_PROGRAM_ERX_SERV_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PROGRAM_ERX_NON_SERV(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0E25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)));\
	} while(0)
#else
	#define UL1D_TRC_PROGRAM_ERX_NON_SERV(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1D_TRC_PROGRAM_ERX_NON_SERV_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0E25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ULDPCCH_FDPCH_GATE_INFO(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F25, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ULDPCCH_FDPCH_GATE_INFO(v1, v2, v3)
#endif
#define UL1D_TRC_ULDPCCH_FDPCH_GATE_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F25, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DECIDE_CQI(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1025, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DECIDE_CQI(v1, v2, v3)
#endif
#define UL1D_TRC_DECIDE_CQI_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1025, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DPCCH_PTN(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1125, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UL_DPCCH_PTN(v1, v2, v3)
#endif
#define UL1D_TRC_UL_DPCCH_PTN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1125, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_LESS_CONFIG(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1225, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_LESS_CONFIG(v1, v2)
#endif
#define UL1D_TRC_LESS_CONFIG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1225, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_LESS_ORDER(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1325, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_LESS_ORDER(v1, v2, v3)
#endif
#define UL1D_TRC_LESS_ORDER_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1325, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEC_SERV_ENABLED(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1425, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SEC_SERV_ENABLED(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_SEC_SERV_ENABLED_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1425, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEC_ORDER(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1525, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_SEC_ORDER(v1, v2, v3, v4)
#endif
#define UL1D_TRC_SEC_ORDER_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1525, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEC_UL_ORDER(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1625, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SEC_UL_ORDER(v1, v2, v3)
#endif
#define UL1D_TRC_SEC_UL_ORDER_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1625, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEC_ORDER_APPLY_TIME_SET(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1725, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SEC_ORDER_APPLY_TIME_SET(v1, v2, v3)
#endif
#define UL1D_TRC_SEC_ORDER_APPLY_TIME_SET_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1725, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEC_ORDER_APPLY_TIME(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1825, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SEC_ORDER_APPLY_TIME(v1, v2, v3)
#endif
#define UL1D_TRC_SEC_ORDER_APPLY_TIME_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1825, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEC_ORDER_BYPASS_CHECK(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1925, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_SEC_ORDER_BYPASS_CHECK(v1, v2, v3)
#endif
#define UL1D_TRC_SEC_ORDER_BYPASS_CHECK_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1925, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEC_ORDER_ACTIVE(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A25, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SEC_ORDER_ACTIVE(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_SEC_ORDER_ACTIVE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A25, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEC_ORDER_RECEIVE(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B25, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_SEC_ORDER_RECEIVE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_SEC_ORDER_RECEIVE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B25, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_TARGET_CELL(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C25, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TARGET_CELL(v1, v2)
#endif
#define UL1D_TRC_TARGET_CELL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C25, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TARGET_SCCH_RESULT(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D25, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TARGET_SCCH_RESULT(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_TARGET_SCCH_RESULT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D25, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RF_RX_CENTRAL_CTRL_1(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1E25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_RX_CENTRAL_CTRL_1(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RF_RX_CENTRAL_CTRL_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1E25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RF_RX_CENTRAL_CTRL_2(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_RX_CENTRAL_CTRL_2(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RF_RX_CENTRAL_CTRL_2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RF_TX_CENTRAL_CONTROL(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2025, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_TX_CENTRAL_CONTROL(v1, v2, v3)
#endif
#define UL1D_TRC_RF_TX_CENTRAL_CONTROL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2025, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_SEC_SYNTH_CH(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2125, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), (unsigned char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_RF_SEC_SYNTH_CH(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RF_SEC_SYNTH_CH_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2125, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_SEC_SYNTH_MEAS(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2225, (short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_SEC_SYNTH_MEAS(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RF_SEC_SYNTH_MEAS_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2225, (short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RF_CENTRAL_FRAMETICK(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2325, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v2), (unsigned char)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_RF_CENTRAL_FRAMETICK(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RF_CENTRAL_FRAMETICK_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2325, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v2), (unsigned char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RF_CTRL_EVENT(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2425, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_CTRL_EVENT(v1)
#endif
#define UL1D_TRC_RF_CTRL_EVENT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2425, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DSCH_HRNTI_TYPE(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2525, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSCH_HRNTI_TYPE(v1)
#endif
#define UL1D_TRC_DSCH_HRNTI_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2525, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MISS_DECODE_DONE(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2625, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MISS_DECODE_DONE(v1)
#endif
#define UL1D_TRC_MISS_DECODE_DONE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2625, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MISS_EAGCH_DECODE_DONE() do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2725, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MISS_EAGCH_DECODE_DONE()
#endif
#define UL1D_TRC_MISS_EAGCH_DECODE_DONE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2725, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MISS_ERGCH_DECODE_DONE() do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2825, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MISS_ERGCH_DECODE_DONE()
#endif
#define UL1D_TRC_MISS_ERGCH_DECODE_DONE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2825, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EPCH_STATE(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2925, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EPCH_STATE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_EPCH_STATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2925, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EPCH_RECEIVE(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A25, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_EPCH_RECEIVE(v1, v2)
#endif
#define UL1D_TRC_EPCH_RECEIVE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A25, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EPCH_HANDLE_CONFIG(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B25, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EPCH_HANDLE_CONFIG(v1, v2, v3)
#endif
#define UL1D_TRC_EPCH_HANDLE_CONFIG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B25, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_STATE(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C25, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_STATE(v1, v2)
#endif
#define UL1D_TRC_EFACH_STATE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C25, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_FMO(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2D25, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_FMO(v1)
#endif
#define UL1D_TRC_EFACH_FMO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2D25, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_RECONFIG(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2E25, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_RECONFIG(v1)
#endif
#define UL1D_TRC_EFACH_RECONFIG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2E25, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_DRX_CONFIG(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_DRX_CONFIG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_EFACH_DRX_CONFIG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_DRX_EVENT(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3025, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_DRX_EVENT(v1, v2)
#endif
#define UL1D_TRC_EFACH_DRX_EVENT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3025, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_DRX_STATE(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3125, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_DRX_STATE(v1, v2, v3)
#endif
#define UL1D_TRC_EFACH_DRX_STATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3125, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_DRX_STOP_DSCH_IMM(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3225, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_DRX_STOP_DSCH_IMM(v1, v2)
#endif
#define UL1D_TRC_EFACH_DRX_STOP_DSCH_IMM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3225, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_HSDPCCH_CONFIG(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3325, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_HSDPCCH_CONFIG(v1, v2)
#endif
#define UL1D_TRC_EFACH_HSDPCCH_CONFIG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3325, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_HSDPCCH_START(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3425, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_HSDPCCH_START(v1, v2)
#endif
#define UL1D_TRC_EFACH_HSDPCCH_START_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3425, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_HSDPCCH_FRAMETICK(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3525, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_HSDPCCH_FRAMETICK(v1, v2)
#endif
#define UL1D_TRC_EFACH_HSDPCCH_FRAMETICK_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3525, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EFACH_HSDPCCH_STOP() do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3625, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EFACH_HSDPCCH_STOP()
#endif
#define UL1D_TRC_EFACH_HSDPCCH_STOP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3625, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_STATE(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3725, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_STATE(v1, v2)
#endif
#define UL1D_TRC_CEDCH_STATE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3725, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_EVENT(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3825, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_EVENT(v1, v2)
#endif
#define UL1D_TRC_CEDCH_EVENT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3825, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_EAI_RESULT(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3925, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_EAI_RESULT(v1, v2, v3)
#endif
#define UL1D_TRC_CEDCH_EAI_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3925, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_START(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A25, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_START(v1, v2, v3, v4)
#endif
#define UL1D_TRC_CEDCH_START_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A25, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_RECONFIG(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3B25, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_RECONFIG(v1)
#endif
#define UL1D_TRC_CEDCH_RECONFIG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3B25, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_TRANSMIT_PREPARE(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_TRANSMIT_PREPARE(v1, v2, v3)
#endif
#define UL1D_TRC_CEDCH_TRANSMIT_PREPARE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_AGHICH_LATCH_TIME(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D25, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_AGHICH_LATCH_TIME(v1, v2)
#endif
#define UL1D_TRC_CEDCH_AGHICH_LATCH_TIME_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D25, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_TRANSMIT(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3E25, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_TRANSMIT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_CEDCH_TRANSMIT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3E25, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_TRANSMIT_ULDPCCH(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3F25, (char)(v1), (char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_TRANSMIT_ULDPCCH(v1, v2, v3)
#endif
#define UL1D_TRC_CEDCH_TRANSMIT_ULDPCCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3F25, (char)(v1), (char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_TRANSMIT_FDPCH(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4025, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_TRANSMIT_FDPCH(v1, v2)
#endif
#define UL1D_TRC_CEDCH_TRANSMIT_FDPCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4025, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_TRANSMIT_EHIRGCH(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4125, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_TRANSMIT_EHIRGCH(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_CEDCH_TRANSMIT_EHIRGCH_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4125, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CEDCH_TRANSMIT_EAGCH(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4225, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_CEDCH_TRANSMIT_EAGCH(v1, v2)
#endif
#define UL1D_TRC_CEDCH_TRANSMIT_EAGCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4225, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_ADJUST_UAT(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4325, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_ADJUST_UAT(v1, v2)
#endif
#define UL1D_TRC_NEW_RFM_ADJUST_UAT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4325, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_TIME56(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4425, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_TIME56(v1, v2)
#endif
#define UL1D_TRC_NEW_RFM_TIME56_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4425, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_TIME8(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4525, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_TIME8(v1)
#endif
#define UL1D_TRC_NEW_RFM_TIME8_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4525, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_LATCH_TIME(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4625, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_LATCH_TIME(v1, v2, v3)
#endif
#define UL1D_TRC_NEW_RFM_LATCH_TIME_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4625, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_DYNAMIC_LATCH(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4725, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_DYNAMIC_LATCH(v1, v2)
#endif
#define UL1D_TRC_NEW_RFM_DYNAMIC_LATCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4725, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_SKIP_HANDLE(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4825, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_SKIP_HANDLE(v1, v2, v3)
#endif
#define UL1D_TRC_NEW_RFM_SKIP_HANDLE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4825, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_MIRROR_FNG(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4925, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_MIRROR_FNG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_NEW_RFM_MIRROR_FNG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4925, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_MIRROR_STATUS(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_MIRROR_STATUS(v1, v2, v3, v4)
#endif
#define UL1D_TRC_NEW_RFM_MIRROR_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_MIRROR_ABORT() do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B25, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_MIRROR_ABORT()
#endif
#define UL1D_TRC_NEW_RFM_MIRROR_ABORT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B25, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_MIRROR_FNG_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4C25, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_MIRROR_FNG_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_NEW_RFM_MIRROR_FNG_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4C25, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_MIRROR_HSCE(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D25, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_MIRROR_HSCE(v1, v2)
#endif
#define UL1D_TRC_NEW_RFM_MIRROR_HSCE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D25, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_RFM_MIRROR_DBG(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4E25, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_NEW_RFM_MIRROR_DBG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_NEW_RFM_MIRROR_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4E25, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_NORMAL_DEACTIVATE(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4F25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_NORMAL_DEACTIVATE(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RFM_NORMAL_DEACTIVATE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4F25, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_COMPENSATION_VALUE(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5025, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_COMPENSATION_VALUE(v1, v2, v3)
#endif
#define UL1D_TRC_RFM_COMPENSATION_VALUE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5025, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_QUERY_SRV_TIMING(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5125, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_QUERY_SRV_TIMING(v1, v2)
#endif
#define UL1D_TRC_RFM_QUERY_SRV_TIMING_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5125, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_STATIC_CHANNEL_DETECT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5225, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v5), (unsigned char)(v7)));\
	} while(0)
#else
	#define UL1D_TRC_STATIC_CHANNEL_DETECT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_STATIC_CHANNEL_DETECT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5225, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v5), (unsigned char)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_STATIC_CHANNEL_COLLECT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5325, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_STATIC_CHANNEL_COLLECT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_STATIC_CHANNEL_COLLECT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5325, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MPS_2ND_PART(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x5425, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_1S2C((unsigned short)(v11), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MPS_2ND_PART(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define UL1D_TRC_MPS_2ND_PART_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x5425, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_1S2C((unsigned short)(v11), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MPS_VALID_PATH(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x5525, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MPS_VALID_PATH(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define UL1D_TRC_MPS_VALID_PATH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x5525, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_RECORD_PATH(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5625, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_RECORD_PATH(v1, v2, v3)
#endif
#define UL1D_TRC_RFM_RECORD_PATH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5625, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_RSSI_VAR_ACC(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5725, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_RSSI_VAR_ACC(v1, v2, v3)
#endif
#define UL1D_TRC_RFM_RSSI_VAR_ACC_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5725, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_RSSI_VAR_RESULT(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5825, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_RSSI_VAR_RESULT(v1, v2, v3)
#endif
#define UL1D_TRC_RFM_RSSI_VAR_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5825, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_SPEST_RELIABLE(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5925, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_SPEST_RELIABLE(v1, v2, v3)
#endif
#define UL1D_TRC_RFM_SPEST_RELIABLE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5925, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_CHECK_VALID_MIRROR(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5A25, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_RFM_CHECK_VALID_MIRROR(v1, v2, v3)
#endif
#define UL1D_TRC_RFM_CHECK_VALID_MIRROR_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5A25, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HRFM_LS_TIMING_ZERO(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5B25, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_LS_TIMING_ZERO(v1)
#endif
#define UL1D_TRC_HRFM_LS_TIMING_ZERO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5B25, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_STATIC_CHANNEL_DETAIL(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C25, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_STATIC_CHANNEL_DETAIL(v1, v2, v3)
#endif
#define UL1D_TRC_STATIC_CHANNEL_DETAIL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C25, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_FINGER_SYM_IDX(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5D25, (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_FINGER_SYM_IDX(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_RFM_FINGER_SYM_IDX_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5D25, (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_RL0_DIRECT_ADJ(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E25, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_RL0_DIRECT_ADJ(v1, v2)
#endif
#define UL1D_TRC_RFM_RL0_DIRECT_ADJ_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E25, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_FNG_REJECT(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5F25, (unsigned char)(v1), (char)(v2)), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_RFM_FNG_REJECT(v1, v2, v3)
#endif
#define UL1D_TRC_RFM_FNG_REJECT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5F25, (unsigned char)(v1), (char)(v2)), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_CH_OFFSET(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6025, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_CH_OFFSET(v1)
#endif
#define UL1D_TRC_RFM_CH_OFFSET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6025, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_DD_SAMPLE_IDX(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6125, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_RFM_DD_SAMPLE_IDX(v1, v2, v3)
#endif
#define UL1D_TRC_RFM_DD_SAMPLE_IDX_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6125, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_SW_SYNC_SAMPLE_IDX(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6225, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_SW_SYNC_SAMPLE_IDX(v1, v2)
#endif
#define UL1D_TRC_RFM_SW_SYNC_SAMPLE_IDX_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6225, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFM_FNG_LATCH_TIME_GSR(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x6325, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_RFM_FNG_LATCH_TIME_GSR(v1)
#endif
#define UL1D_TRC_RFM_FNG_LATCH_TIME_GSR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x6325, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_HSCE_FRAME_CONFIG(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6425, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NEW_HSCE_FRAME_CONFIG(v1)
#endif
#define UL1D_TRC_NEW_HSCE_FRAME_CONFIG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6425, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_STATIC_EQBYPASS(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6525, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_STATIC_EQBYPASS(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSCE_STATIC_EQBYPASS_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6525, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_LS_DECISION(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6625, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_LS_DECISION(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSCE_LS_DECISION_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6625, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_LS_TIMING_TOGGLE(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6725, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_LS_TIMING_TOGGLE(v1)
#endif
#define UL1D_TRC_HSCE_LS_TIMING_TOGGLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6725, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_HW_STATUS(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6825, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_HW_STATUS(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSCE_HW_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6825, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_OTR_CELL_DBG(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6925, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v2), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_OTR_CELL_DBG(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_HSCE_OTR_CELL_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6925, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v2), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_LS_ON_FOR_DCM(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x6A25, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_LS_ON_FOR_DCM(v1)
#endif
#define UL1D_TRC_HSCE_LS_ON_FOR_DCM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x6A25, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_DETAIL_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6B25, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v5)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_DETAIL_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_HSCE_DETAIL_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6B25, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v5)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_ANT2_INFO(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6C25, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_ANT2_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSCE_ANT2_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6C25, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OCIC_ABS_THR(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6D25, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_OCIC_ABS_THR(v1, v2, v3, v4)
#endif
#define UL1D_TRC_OCIC_ABS_THR_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6D25, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OCIC_REL_THR(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6E25, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_OCIC_REL_THR(v1, v2, v3, v4)
#endif
#define UL1D_TRC_OCIC_REL_THR_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6E25, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OCIC_SWITCH_THR(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6F25, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_OCIC_SWITCH_THR(v1, v2, v3, v4)
#endif
#define UL1D_TRC_OCIC_SWITCH_THR_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6F25, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_UPDATE_ECNO(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7025, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_UPDATE_ECNO(v1, v2, v3)
#endif
#define UL1D_TRC_HSCE_UPDATE_ECNO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7025, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_LS_ASSIGN_INFO(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7125, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_LS_ASSIGN_INFO(v1, v2, v3)
#endif
#define UL1D_TRC_HSCE_LS_ASSIGN_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7125, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_ABNORMAL(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7225, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_ABNORMAL(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSCE_ABNORMAL_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7225, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_SPEST_WIN_CTR(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7325, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_SPEST_WIN_CTR(v1, v2)
#endif
#define UL1D_TRC_HSCE_SPEST_WIN_CTR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7325, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_SPEST_WIN_BOUND(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7425, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_SPEST_WIN_BOUND(v1, v2)
#endif
#define UL1D_TRC_HSCE_SPEST_WIN_BOUND_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7425, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_SPEST_LCR_ENABLE(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7525, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_SPEST_LCR_ENABLE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSCE_SPEST_LCR_ENABLE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7525, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_SPEST_INTEGRATOR(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7625, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_SPEST_INTEGRATOR(v1, v2, v3)
#endif
#define UL1D_TRC_HSCE_SPEST_INTEGRATOR_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7625, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_SPEST_ALPHA_FILTER(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7725, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_SPEST_ALPHA_FILTER(v1, v2, v3)
#endif
#define UL1D_TRC_HSCE_SPEST_ALPHA_FILTER_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7725, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_SPEST_RESET(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7825, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_SPEST_RESET(v1, v2)
#endif
#define UL1D_TRC_HSCE_SPEST_RESET_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7825, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_PBASP_DBG_3(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7925, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_PBASP_DBG_3(v1, v2, v3, v4, v5)
#endif
#define UL1D_PBASP_DBG_3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7925, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_PBASP_DBG_4(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x7A25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_PBASP_DBG_4(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_PBASP_DBG_4_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x7A25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_PBASP_DBG_5(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7B25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_PBASP_DBG_5(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_PBASP_DBG_5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7B25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_PBASP_DBG_6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7C25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define UL1D_PBASP_DBG_6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_PBASP_DBG_6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7C25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_PBASP_DBG_7(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7D25, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_PBASP_DBG_7(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_PBASP_DBG_7_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7D25, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_PBASP_DBG_8(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7E25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_PBASP_DBG_8(v1, v2, v3)
#endif
#define UL1D_PBASP_DBG_8_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7E25, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SET_POINT_STATUS(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7F25, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SET_POINT_STATUS(v1)
#endif
#define UL1D_TRC_SET_POINT_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7F25, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SET_POINT_CHANGE(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8025, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SET_POINT_CHANGE(v1)
#endif
#define UL1D_TRC_SET_POINT_CHANGE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8025, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SET_POINT_INJECT(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x8125, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_SET_POINT_INJECT(v1)
#endif
#define UL1D_TRC_SET_POINT_INJECT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x8125, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_INI_TX_POWER(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8225, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_INI_TX_POWER(v1, v2, v3)
#endif
#define UL1D_TRC_INI_TX_POWER_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8225, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OCIC_USING_ECNO(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8325, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_OCIC_USING_ECNO(v1)
#endif
#define UL1D_TRC_OCIC_USING_ECNO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8325, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RAKE_CPICH_ONOFF(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x8425, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v5), (char)(v6), (char)(v7), (char)(v8)), TRC_MERGE_4C((char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RAKE_CPICH_ONOFF(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_RAKE_CPICH_ONOFF_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_4_DATA(TRC_MERGE_2S(0x8425, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v5), (char)(v6), (char)(v7), (char)(v8)), TRC_MERGE_4C((char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RAKE_CPICH_ONOFF_TIME(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x8525, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_RAKE_CPICH_ONOFF_TIME(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RAKE_CPICH_ONOFF_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x8525, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RAKE_CPICH_ONOFF_STATUS(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8625, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_RAKE_CPICH_ONOFF_STATUS(v1, v2)
#endif
#define UL1D_TRC_RAKE_CPICH_ONOFF_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8625, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RAKE_CPICH_ONOFF_FWSTATUS(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8725, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RAKE_CPICH_ONOFF_FWSTATUS(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RAKE_CPICH_ONOFF_FWSTATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8725, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RAKE_CPICH_ONOFF_FWREG_STATUS(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x8825, (short)(v1)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_RAKE_CPICH_ONOFF_FWREG_STATUS(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RAKE_CPICH_ONOFF_FWREG_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x8825, (short)(v1)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_REG_DBG(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8925, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_REG_DBG(v1, v2)
#endif
#define UL1D_TRC_REG_DBG_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8925, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DBG_HS_SUSPEND_GAP_CHECK(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x8A25, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_DBG_HS_SUSPEND_GAP_CHECK(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DBG_HS_SUSPEND_GAP_CHECK_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x8A25, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEIGHBOR_USER_DETECTION(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8B25, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NEIGHBOR_USER_DETECTION(v1)
#endif
#define UL1D_TRC_NEIGHBOR_USER_DETECTION_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8B25, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_REG_DBG_LOW(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8C25, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_REG_DBG_LOW(v1, v2)
#endif
#define UL1D_TRC_REG_DBG_LOW_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8C25, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RAS_DBG(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8D25, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RAS_DBG(v1, v2, v3)
#endif
#define UL1D_TRC_RAS_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8D25, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CSFB_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x8E25, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_1S2C((unsigned short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CSFB_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1D_TRC_CSFB_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x8E25, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_1S2C((unsigned short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UNHANDLED_IRQ(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8F25, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UNHANDLED_IRQ(v1, v2)
#endif
#define UL1D_TRC_UNHANDLED_IRQ_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8F25, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UNHANDLED_CC_STATE(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9025, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UNHANDLED_CC_STATE(v1)
#endif
#define UL1D_TRC_UNHANDLED_CC_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9025, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_REG_DBG_SLOT(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_17_DATA(TRC_MERGE_1S2C(0x9125, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_REG_DBG_SLOT(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_REG_DBG_SLOT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_17_DATA(TRC_MERGE_1S2C(0x9125, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MISS_SCCH_STS0_DBG(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x9225, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MISS_SCCH_STS0_DBG(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_MISS_SCCH_STS0_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x9225, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CPC_DQE_SIR(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9325, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_CPC_DQE_SIR(v1, v2, v3)
#endif
#define UL1D_TRC_CPC_DQE_SIR_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9325, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_HW_WIND_SIR(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9425, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DPC_HW_WIND_SIR(v1, v2, v3)
#endif
#define UL1D_TRC_DPC_HW_WIND_SIR_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9425, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXSRP_SIG_AMP_RAW(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9525, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_RXSRP_SIG_AMP_RAW(v1, v2, v3)
#endif
#define UL1D_TRC_RXSRP_SIG_AMP_RAW_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9525, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DQE_SIR_WORKAROUND(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9625, (unsigned char)(v3), TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DQE_SIR_WORKAROUND(v1, v2, v3)
#endif
#define UL1D_TRC_DQE_SIR_WORKAROUND_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9625, (unsigned char)(v3), TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FPGA_FLASH_VERSION(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x9725, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_FPGA_FLASH_VERSION(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FPGA_FLASH_VERSION_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x9725, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_SLOT_NUM(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9825, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SLOT_NUM(v1)
#endif
#define UL1D_TRC_SLOT_NUM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9825, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OPTI_CMB_BASIC(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9925, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_OPTI_CMB_BASIC(v1, v2, v3, v4)
#endif
#define UL1D_TRC_OPTI_CMB_BASIC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9925, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OPTI_CMB_FACH(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9A25, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_OPTI_CMB_FACH(v1)
#endif
#define UL1D_TRC_OPTI_CMB_FACH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9A25, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OPTI_CMB_DCH_TICK(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x9B25, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_OPTI_CMB_DCH_TICK(v1, v2, v3)
#endif
#define UL1D_TRC_OPTI_CMB_DCH_TICK_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x9B25, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OPTI_CMB_DCH_SPECIAL(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9C25, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_OPTI_CMB_DCH_SPECIAL(v1)
#endif
#define UL1D_TRC_OPTI_CMB_DCH_SPECIAL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9C25, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OPTI_CMB_REG_SET(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9D25, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_OPTI_CMB_REG_SET(v1, v2)
#endif
#define UL1D_TRC_OPTI_CMB_REG_SET_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9D25, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OPTI_CMB_ECPT_CNT(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9E25, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_OPTI_CMB_ECPT_CNT(v1)
#endif
#define UL1D_TRC_OPTI_CMB_ECPT_CNT_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9E25, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HOP3G_PLL(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9F25, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HOP3G_PLL(v1)
#endif
#define UL1D_TRC_HOP3G_PLL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9F25, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DSCH_BLER(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA025, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSCH_BLER(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DSCH_BLER_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA025, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_EDCH_ACK_RATE(v1) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0xA125, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_ACK_RATE(v1)
#endif
#define UL1D_TRC_EDCH_ACK_RATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0xA125, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_CW(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xA225, (unsigned short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_RF_CW(v1, v2)
#endif
#define UL1D_TRC_RF_CW_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0xA225, (unsigned short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_CW1_CONFIG(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA325, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_CW1_CONFIG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RF_CW1_CONFIG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA325, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TPO_DBG1(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xA425, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TPO_DBG1(v1, v2)
#endif
#define UL1D_TRC_TPO_DBG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0xA425, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TPO_DBG2(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA525, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TPO_DBG2(v1, v2, v3, v4)
#endif
#define UL1D_TRC_TPO_DBG2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA525, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_SAR_TPO_DBG1(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA625, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SAR_TPO_DBG1(v1, v2, v3, v4)
#endif
#define UL1D_TRC_SAR_TPO_DBG1_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA625, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_SAR_TPO_DBG2(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA725, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_SAR_TPO_DBG2(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_SAR_TPO_DBG2_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA725, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_SAR_TPO_DBG3(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0xA825, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SAR_TPO_DBG3(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_SAR_TPO_DBG3_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0xA825, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_EDCH_BITMAP(v1, v2) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xA925, (unsigned short)(v2)), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_BITMAP(v1, v2)
#endif
#define UL1D_TRC_EDCH_BITMAP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0xA925, (unsigned short)(v2)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UPDATE_SERVING(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xAA25, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UPDATE_SERVING(v1, v2, v3, v4)
#endif
#define UL1D_TRC_UPDATE_SERVING_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0xAA25, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UPDATE_SERVING_DIV(v1, v2, v3, v4) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xAB25, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UPDATE_SERVING_DIV(v1, v2, v3, v4)
#endif
#define UL1D_TRC_UPDATE_SERVING_DIV_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0xAB25, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UPDATE_STRONGEST(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xAC25, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UPDATE_STRONGEST(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_UPDATE_STRONGEST_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0xAC25, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UPDATE_STRONGEST_DIV(v1, v2, v3, v4, v5) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xAD25, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UPDATE_STRONGEST_DIV(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_UPDATE_STRONGEST_DIV_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0xAD25, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TM_DBG(v1, v2, v3) do {\
		if(UL1D_PLUS_PRI_Trace_Filter[0]==1 && (UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xAE25, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_TM_DBG(v1, v2, v3)
#endif
#define UL1D_TRC_TM_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0xAE25, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_PLUS_PRI_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_CPC_CONFID1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_CPC_ENABLED(unsigned short v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_CPC_ORDER(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_CPC_FORECAST_ERR(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_TICK_ENTRY(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_CARRY_HSSCCH(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_DECIDE_HSSCCH(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_HSSCCH_CPC_DECISION(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_PROGRAM_HSSCCH(unsigned short v1, unsigned char v2, unsigned short v3, unsigned char v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_UL1D_TRC_DECIDE_EAGCH(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_DECIDE_ERGCH_SERV(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_DECIDE_ERGCH_NSERV(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_DECIDE_EHICH(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_PROGRAM_ERX_SERV(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_UL1D_TRC_PROGRAM_ERX_NON_SERV(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_UL1D_TRC_ULDPCCH_FDPCH_GATE_INFO(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_DECIDE_CQI(char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_UL_DPCCH_PTN(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_LESS_CONFIG(unsigned short v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_LESS_ORDER(unsigned short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_SEC_SERV_ENABLED(unsigned short v1, short v2, unsigned char v3, short v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_SEC_ORDER(short v1, unsigned short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_SEC_UL_ORDER(unsigned short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_SEC_ORDER_APPLY_TIME_SET(unsigned short v1, unsigned char v2, short v3);
void L1TRC_Send_UL1D_TRC_SEC_ORDER_APPLY_TIME(short v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_SEC_ORDER_BYPASS_CHECK(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_SEC_ORDER_ACTIVE(short v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_SEC_ORDER_RECEIVE(short v1, unsigned short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_TARGET_CELL(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_TARGET_SCCH_RESULT(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_RF_RX_CENTRAL_CTRL_1(short v1, short v2, short v3, unsigned short v4, short v5, char v6);
void L1TRC_Send_UL1D_TRC_RF_RX_CENTRAL_CTRL_2(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_RF_TX_CENTRAL_CONTROL(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_RF_SEC_SYNTH_CH(short v1, unsigned char v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_RF_SEC_SYNTH_MEAS(short v1, unsigned char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_RF_CENTRAL_FRAMETICK(short v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_RF_CTRL_EVENT(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DSCH_HRNTI_TYPE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MISS_DECODE_DONE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_MISS_EAGCH_DECODE_DONE(void);
void L1TRC_Send_UL1D_TRC_MISS_ERGCH_DECODE_DONE(void);
void L1TRC_Send_UL1D_TRC_EPCH_STATE(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_UL1D_TRC_EPCH_RECEIVE(unsigned char v1, char v2);
void L1TRC_Send_UL1D_TRC_EPCH_HANDLE_CONFIG(char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_EFACH_STATE(unsigned char v1, char v2);
void L1TRC_Send_UL1D_TRC_EFACH_FMO(unsigned short v1);
void L1TRC_Send_UL1D_TRC_EFACH_RECONFIG(unsigned long v1);
void L1TRC_Send_UL1D_TRC_EFACH_DRX_CONFIG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_EFACH_DRX_EVENT(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_EFACH_DRX_STATE(unsigned char v1, unsigned short v2, char v3);
void L1TRC_Send_UL1D_TRC_EFACH_DRX_STOP_DSCH_IMM(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_EFACH_HSDPCCH_CONFIG(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_EFACH_HSDPCCH_START(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_EFACH_HSDPCCH_FRAMETICK(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_EFACH_HSDPCCH_STOP(void);
void L1TRC_Send_UL1D_TRC_CEDCH_STATE(unsigned char v1, char v2);
void L1TRC_Send_UL1D_TRC_CEDCH_EVENT(unsigned char v1, char v2);
void L1TRC_Send_UL1D_TRC_CEDCH_EAI_RESULT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_CEDCH_START(char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_CEDCH_RECONFIG(unsigned long v1);
void L1TRC_Send_UL1D_TRC_CEDCH_TRANSMIT_PREPARE(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_CEDCH_AGHICH_LATCH_TIME(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_CEDCH_TRANSMIT(unsigned char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_CEDCH_TRANSMIT_ULDPCCH(char v1, char v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_CEDCH_TRANSMIT_FDPCH(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_CEDCH_TRANSMIT_EHIRGCH(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, char v5);
void L1TRC_Send_UL1D_TRC_CEDCH_TRANSMIT_EAGCH(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_NEW_RFM_ADJUST_UAT(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_NEW_RFM_TIME56(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_NEW_RFM_TIME8(unsigned char v1);
void L1TRC_Send_UL1D_TRC_NEW_RFM_LATCH_TIME(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_NEW_RFM_DYNAMIC_LATCH(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_NEW_RFM_SKIP_HANDLE(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_NEW_RFM_MIRROR_FNG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_NEW_RFM_MIRROR_STATUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_NEW_RFM_MIRROR_ABORT(void);
void L1TRC_Send_UL1D_TRC_NEW_RFM_MIRROR_FNG_INFO(unsigned char v1, char v2, unsigned char v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_NEW_RFM_MIRROR_HSCE(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_NEW_RFM_MIRROR_DBG(unsigned char v1, unsigned long v2, unsigned char v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_RFM_NORMAL_DEACTIVATE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_RFM_COMPENSATION_VALUE(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_RFM_QUERY_SRV_TIMING(char v1, char v2);
void L1TRC_Send_UL1D_TRC_STATIC_CHANNEL_DETECT(unsigned char v1, unsigned char v2, short v3, short v4, char v5, short v6, unsigned char v7);
void L1TRC_Send_UL1D_TRC_STATIC_CHANNEL_COLLECT(long v1, short v2, short v3, short v4, short v5, short v6, unsigned char v7);
void L1TRC_Send_UL1D_TRC_MPS_2ND_PART(char v1, short v2, short v3, short v4, short v5, short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11);
void L1TRC_Send_UL1D_TRC_MPS_VALID_PATH(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11);
void L1TRC_Send_UL1D_TRC_RFM_RECORD_PATH(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_RFM_RSSI_VAR_ACC(unsigned short v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_RFM_RSSI_VAR_RESULT(unsigned short v1, unsigned short v2, short v3);
void L1TRC_Send_UL1D_TRC_RFM_SPEST_RELIABLE(short v1, short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_RFM_CHECK_VALID_MIRROR(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_HRFM_LS_TIMING_ZERO(unsigned char v1);
void L1TRC_Send_UL1D_TRC_STATIC_CHANNEL_DETAIL(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_RFM_FINGER_SYM_IDX(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_UL1D_TRC_RFM_RL0_DIRECT_ADJ(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_RFM_FNG_REJECT(unsigned char v1, char v2, long v3);
void L1TRC_Send_UL1D_TRC_RFM_CH_OFFSET(unsigned char v1);
void L1TRC_Send_UL1D_TRC_RFM_DD_SAMPLE_IDX(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_RFM_SW_SYNC_SAMPLE_IDX(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_RFM_FNG_LATCH_TIME_GSR(unsigned short v1);
void L1TRC_Send_UL1D_TRC_NEW_HSCE_FRAME_CONFIG(unsigned char v1);
void L1TRC_Send_UL1D_TRC_HSCE_STATIC_EQBYPASS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_HSCE_LS_DECISION(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_HSCE_LS_TIMING_TOGGLE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_HSCE_HW_STATUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_HSCE_OTR_CELL_DBG(unsigned short v1, unsigned char v2, long v3, unsigned short v4, unsigned char v5, long v6, unsigned char v7);
void L1TRC_Send_UL1D_TRC_HSCE_LS_ON_FOR_DCM(short v1);
void L1TRC_Send_UL1D_TRC_HSCE_DETAIL_DBG(unsigned short v1, unsigned short v2, unsigned char v3, unsigned char v4, short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_HSCE_ANT2_INFO(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_OCIC_ABS_THR(short v1, char v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_OCIC_REL_THR(short v1, char v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_OCIC_SWITCH_THR(short v1, char v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HSCE_UPDATE_ECNO(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_HSCE_LS_ASSIGN_INFO(unsigned short v1, unsigned char v2, short v3);
void L1TRC_Send_UL1D_TRC_HSCE_ABNORMAL(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_HSCE_SPEST_WIN_CTR(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_HSCE_SPEST_WIN_BOUND(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_HSCE_SPEST_LCR_ENABLE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_HSCE_SPEST_INTEGRATOR(unsigned char v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_HSCE_SPEST_ALPHA_FILTER(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_HSCE_SPEST_RESET(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_PBASP_DBG_3(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_PBASP_DBG_4(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_PBASP_DBG_5(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_PBASP_DBG_6(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1D_PBASP_DBG_7(char v1, char v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1D_PBASP_DBG_8(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_SET_POINT_STATUS(char v1);
void L1TRC_Send_UL1D_TRC_SET_POINT_CHANGE(char v1);
void L1TRC_Send_UL1D_TRC_SET_POINT_INJECT(short v1);
void L1TRC_Send_UL1D_TRC_INI_TX_POWER(short v1, short v2, char v3);
void L1TRC_Send_UL1D_TRC_OCIC_USING_ECNO(char v1);
void L1TRC_Send_UL1D_TRC_RAKE_CPICH_ONOFF(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, char v5, char v6, char v7, char v8, char v9);
void L1TRC_Send_UL1D_TRC_RAKE_CPICH_ONOFF_TIME(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_RAKE_CPICH_ONOFF_STATUS(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_RAKE_CPICH_ONOFF_FWSTATUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_RAKE_CPICH_ONOFF_FWREG_STATUS(short v1, unsigned long v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_REG_DBG(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_DBG_HS_SUSPEND_GAP_CHECK(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_NEIGHBOR_USER_DETECTION(char v1);
void L1TRC_Send_UL1D_TRC_REG_DBG_LOW(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_RAS_DBG(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_CSFB_DBG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10);
void L1TRC_Send_UL1D_TRC_UNHANDLED_IRQ(short v1, short v2);
void L1TRC_Send_UL1D_TRC_UNHANDLED_CC_STATE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_REG_DBG_SLOT(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_MISS_SCCH_STS0_DBG(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_UL1D_TRC_CPC_DQE_SIR(unsigned char v1, long v2, short v3);
void L1TRC_Send_UL1D_TRC_DPC_HW_WIND_SIR(unsigned char v1, long v2, long v3);
void L1TRC_Send_UL1D_TRC_RXSRP_SIG_AMP_RAW(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_DQE_SIR_WORKAROUND(long v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_FPGA_FLASH_VERSION(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_SLOT_NUM(unsigned char v1);
void L1TRC_Send_UL1D_TRC_OPTI_CMB_BASIC(unsigned char v1, unsigned short v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_OPTI_CMB_FACH(unsigned char v1);
void L1TRC_Send_UL1D_TRC_OPTI_CMB_DCH_TICK(unsigned short v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_OPTI_CMB_DCH_SPECIAL(unsigned char v1);
void L1TRC_Send_UL1D_TRC_OPTI_CMB_REG_SET(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_OPTI_CMB_ECPT_CNT(unsigned long v1);
void L1TRC_Send_UL1D_TRC_HOP3G_PLL(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DSCH_BLER(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_EDCH_ACK_RATE(unsigned short v1);
void L1TRC_Send_UL1D_TRC_RF_CW(unsigned short v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_RF_CW1_CONFIG(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_TPO_DBG1(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_TPO_DBG2(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_SAR_TPO_DBG1(unsigned short v1, unsigned short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_SAR_TPO_DBG2(unsigned short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_SAR_TPO_DBG3(short v1, unsigned short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_EDCH_BITMAP(unsigned long v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_UPDATE_SERVING(char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_UPDATE_SERVING_DIV(char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_UPDATE_STRONGEST(char v1, unsigned char v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_UPDATE_STRONGEST_DIV(char v1, unsigned char v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_TM_DBG(unsigned short v1, unsigned short v2, short v3);

void Set_UL1D_PLUS_PRI_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_PLUS_PRI()	(UL1D_PLUS_PRI_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_L()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EPCH_H()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EPCH_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_HSCE_SPEST_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_RAKE_H()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_L()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_DPC_R8_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_FPGA_INFO_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_OPTI_CMB_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_DQE_WORKAROUND_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_MISC_H()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_MISC_M()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_RF_H()	(ChkL1ModFltr_UL1D_PLUS_PRI()&&((UL1D_PLUS_PRI_Trace_Filter[3]&0x20)!=0))
#define ChkL1MsgFltr_UL1D_TRC_CPC_CONFID1()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_CPC_ENABLED()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_CPC_ORDER()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_CPC_FORECAST_ERR()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_TICK_ENTRY()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_L()
#define ChkL1MsgFltr_UL1D_TRC_CARRY_HSSCCH()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_DECIDE_HSSCCH()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_HSSCCH_CPC_DECISION()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_PROGRAM_HSSCCH()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_DECIDE_EAGCH()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_DECIDE_ERGCH_SERV()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_DECIDE_ERGCH_NSERV()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_DECIDE_EHICH()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_PROGRAM_ERX_SERV()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_PROGRAM_ERX_NON_SERV()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_ULDPCCH_FDPCH_GATE_INFO()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_DECIDE_CQI()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DPCCH_PTN()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_LESS_CONFIG()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_LESS_ORDER()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_SEC_SERV_ENABLED()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_SEC_ORDER()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_SEC_UL_ORDER()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_SEC_ORDER_APPLY_TIME_SET()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_SEC_ORDER_APPLY_TIME()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_SEC_ORDER_BYPASS_CHECK()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_SEC_ORDER_ACTIVE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_SEC_ORDER_RECEIVE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_TARGET_CELL()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_TARGET_SCCH_RESULT()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_RF_RX_CENTRAL_CTRL_1()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_RF_RX_CENTRAL_CTRL_2()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_RF_TX_CENTRAL_CONTROL()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_RF_SEC_SYNTH_CH()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_SEC_SYNTH_MEAS()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_CENTRAL_FRAMETICK()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_RF_CTRL_EVENT()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_DSCH_HRNTI_TYPE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_L()
#define ChkL1MsgFltr_UL1D_TRC_MISS_DECODE_DONE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_MISS_EAGCH_DECODE_DONE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_MISS_ERGCH_DECODE_DONE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_H()
#define ChkL1MsgFltr_UL1D_TRC_EPCH_STATE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EPCH_H()
#define ChkL1MsgFltr_UL1D_TRC_EPCH_RECEIVE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EPCH_H()
#define ChkL1MsgFltr_UL1D_TRC_EPCH_HANDLE_CONFIG()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EPCH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_STATE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_FMO()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_RECONFIG()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_DRX_CONFIG()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_DRX_EVENT()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_DRX_STATE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_DRX_STOP_DSCH_IMM()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_HSDPCCH_CONFIG()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_HSDPCCH_START()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_HSDPCCH_FRAMETICK()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_EFACH_HSDPCCH_STOP()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_EFACH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_STATE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_EVENT()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_EAI_RESULT()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_START()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_RECONFIG()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_TRANSMIT_PREPARE()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_AGHICH_LATCH_TIME()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_TRANSMIT()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_TRANSMIT_ULDPCCH()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_TRANSMIT_FDPCH()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_TRANSMIT_EHIRGCH()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_CEDCH_TRANSMIT_EAGCH()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_CEDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_ADJUST_UAT()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_TIME56()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_TIME8()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_LATCH_TIME()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_DYNAMIC_LATCH()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_SKIP_HANDLE()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_MIRROR_FNG()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_MIRROR_STATUS()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_MIRROR_ABORT()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_MIRROR_FNG_INFO()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_MIRROR_HSCE()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_RFM_MIRROR_DBG()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_NORMAL_DEACTIVATE()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_COMPENSATION_VALUE()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_QUERY_SRV_TIMING()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_STATIC_CHANNEL_DETECT()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_STATIC_CHANNEL_COLLECT()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_MPS_2ND_PART()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_MPS_VALID_PATH()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_RECORD_PATH()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_RSSI_VAR_ACC()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_RSSI_VAR_RESULT()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_SPEST_RELIABLE()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_CHECK_VALID_MIRROR()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_LS_TIMING_ZERO()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_STATIC_CHANNEL_DETAIL()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_FINGER_SYM_IDX()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_RL0_DIRECT_ADJ()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_FNG_REJECT()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_CH_OFFSET()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_DD_SAMPLE_IDX()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_SW_SYNC_SAMPLE_IDX()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_RFM_FNG_LATCH_TIME_GSR()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_RFM_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_HSCE_FRAME_CONFIG()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_STATIC_EQBYPASS()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_LS_DECISION()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_LS_TIMING_TOGGLE()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_HW_STATUS()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_OTR_CELL_DBG()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_LS_ON_FOR_DCM()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_DETAIL_DBG()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_ANT2_INFO()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_OCIC_ABS_THR()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_OCIC_REL_THR()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_OCIC_SWITCH_THR()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_UPDATE_ECNO()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_LS_ASSIGN_INFO()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_ABNORMAL()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_SPEST_WIN_CTR()	ChkL1ClsFltr_UL1D_PLUS_PRI_HSCE_SPEST_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_SPEST_WIN_BOUND()	ChkL1ClsFltr_UL1D_PLUS_PRI_HSCE_SPEST_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_SPEST_LCR_ENABLE()	ChkL1ClsFltr_UL1D_PLUS_PRI_HSCE_SPEST_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_SPEST_INTEGRATOR()	ChkL1ClsFltr_UL1D_PLUS_PRI_HSCE_SPEST_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_SPEST_ALPHA_FILTER()	ChkL1ClsFltr_UL1D_PLUS_PRI_HSCE_SPEST_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_SPEST_RESET()	ChkL1ClsFltr_UL1D_PLUS_PRI_HSCE_SPEST_M()
#define ChkL1MsgFltr_UL1D_PBASP_DBG_3()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_PBASP_DBG_4()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_PBASP_DBG_5()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_PBASP_DBG_6()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_PBASP_DBG_7()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_PBASP_DBG_8()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_SET_POINT_STATUS()	ChkL1ClsFltr_UL1D_PLUS_PRI_RAKE_H()
#define ChkL1MsgFltr_UL1D_TRC_SET_POINT_CHANGE()	ChkL1ClsFltr_UL1D_PLUS_PRI_RAKE_H()
#define ChkL1MsgFltr_UL1D_TRC_SET_POINT_INJECT()	ChkL1ClsFltr_UL1D_PLUS_PRI_RAKE_H()
#define ChkL1MsgFltr_UL1D_TRC_INI_TX_POWER()	ChkL1ClsFltr_UL1D_PLUS_PRI_RAKE_H()
#define ChkL1MsgFltr_UL1D_TRC_OCIC_USING_ECNO()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_RAKE_CPICH_ONOFF()	ChkL1ClsFltr_UL1D_PLUS_PRI_RAKE_H()
#define ChkL1MsgFltr_UL1D_TRC_RAKE_CPICH_ONOFF_TIME()	ChkL1ClsFltr_UL1D_PLUS_PRI_RAKE_H()
#define ChkL1MsgFltr_UL1D_TRC_RAKE_CPICH_ONOFF_STATUS()	ChkL1ClsFltr_UL1D_PLUS_PRI_RAKE_H()
#define ChkL1MsgFltr_UL1D_TRC_RAKE_CPICH_ONOFF_FWSTATUS()	ChkL1ClsFltr_UL1D_PLUS_PRI_RAKE_H()
#define ChkL1MsgFltr_UL1D_TRC_RAKE_CPICH_ONOFF_FWREG_STATUS()	ChkL1ClsFltr_UL1D_PLUS_PRI_RAKE_H()
#define ChkL1MsgFltr_UL1D_TRC_REG_DBG()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_DBG_HS_SUSPEND_GAP_CHECK()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_NEIGHBOR_USER_DETECTION()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_REG_DBG_LOW()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_RAS_DBG()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_CSFB_DBG()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_UNHANDLED_IRQ()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_UNHANDLED_CC_STATE()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_REG_DBG_SLOT()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MISS_SCCH_STS0_DBG()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_CPC_DQE_SIR()	ChkL1ClsFltr_UL1D_PLUS_PRI_DPC_R8_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_HW_WIND_SIR()	ChkL1ClsFltr_UL1D_PLUS_PRI_DPC_R8_M()
#define ChkL1MsgFltr_UL1D_TRC_RXSRP_SIG_AMP_RAW()	ChkL1ClsFltr_UL1D_PLUS_PRI_DPC_R8_M()
#define ChkL1MsgFltr_UL1D_TRC_DQE_SIR_WORKAROUND()	ChkL1ClsFltr_UL1D_PLUS_PRI_DQE_WORKAROUND_M()
#define ChkL1MsgFltr_UL1D_TRC_FPGA_FLASH_VERSION()	ChkL1ClsFltr_UL1D_PLUS_PRI_FPGA_INFO_M()
#define ChkL1MsgFltr_UL1D_TRC_SLOT_NUM()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_OPTI_CMB_BASIC()	ChkL1ClsFltr_UL1D_PLUS_PRI_OPTI_CMB_M()
#define ChkL1MsgFltr_UL1D_TRC_OPTI_CMB_FACH()	ChkL1ClsFltr_UL1D_PLUS_PRI_OPTI_CMB_M()
#define ChkL1MsgFltr_UL1D_TRC_OPTI_CMB_DCH_TICK()	ChkL1ClsFltr_UL1D_PLUS_PRI_OPTI_CMB_M()
#define ChkL1MsgFltr_UL1D_TRC_OPTI_CMB_DCH_SPECIAL()	ChkL1ClsFltr_UL1D_PLUS_PRI_OPTI_CMB_M()
#define ChkL1MsgFltr_UL1D_TRC_OPTI_CMB_REG_SET()	ChkL1ClsFltr_UL1D_PLUS_PRI_OPTI_CMB_M()
#define ChkL1MsgFltr_UL1D_TRC_OPTI_CMB_ECPT_CNT()	ChkL1ClsFltr_UL1D_PLUS_PRI_OPTI_CMB_M()
#define ChkL1MsgFltr_UL1D_TRC_HOP3G_PLL()	ChkL1ClsFltr_UL1D_PLUS_PRI_MISC_H()
#define ChkL1MsgFltr_UL1D_TRC_DSCH_BLER()	ChkL1ClsFltr_UL1D_PLUS_PRI_MISC_M()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_ACK_RATE()	ChkL1ClsFltr_UL1D_PLUS_PRI_MISC_M()
#define ChkL1MsgFltr_UL1D_TRC_RF_CW()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_CW1_CONFIG()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_RF_H()
#define ChkL1MsgFltr_UL1D_TRC_TPO_DBG1()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_TPO_DBG2()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_SAR_TPO_DBG1()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_SAR_TPO_DBG2()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_SAR_TPO_DBG3()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_BITMAP()	ChkL1ClsFltr_UL1D_PLUS_PRI_UL1D_HSPA_PLUS_M()
#define ChkL1MsgFltr_UL1D_TRC_UPDATE_SERVING()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_UPDATE_SERVING_DIV()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_UPDATE_STRONGEST()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_UPDATE_STRONGEST_DIV()	ChkL1ClsFltr_UL1D_PLUS_PRI_New_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_TM_DBG()	ChkL1ClsFltr_UL1D_PLUS_PRI_REG_DBG_M()


#endif
