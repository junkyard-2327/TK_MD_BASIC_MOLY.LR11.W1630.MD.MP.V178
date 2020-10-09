#ifndef L1TRC_PCORE_DVFS_1_DEF_H
#define L1TRC_PCORE_DVFS_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define PCORE_DVFS_Debug_String(v1)  (unsigned char)(v1+0)
#define PCORE_DVFS_Check_Requirement_String(v1)  (unsigned char)(v1+41)
#define PCORE_DVFS_Dump_Description_String(v1)  (unsigned char)(v1+46)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_FLOW_DEBUG(v1) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0021, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_FLOW_DEBUG(v1)
#endif
#define PCORE_DVFS_TRC_FLOW_DEBUG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0021, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_REGISTER(v1, v2) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0121, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_REGISTER(v1, v2)
#endif
#define PCORE_DVFS_TRC_REGISTER_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0121, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_CHECK(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x0221, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_CHECK(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define PCORE_DVFS_TRC_CHECK_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x0221, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_PRE_CTRL_SET_SCENARIO(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0321, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), (char)(v7)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_PRE_CTRL_SET_SCENARIO(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PCORE_DVFS_TRC_PRE_CTRL_SET_SCENARIO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0321, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), (char)(v7)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_POST_CTRL_SET_SCENARIO(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0421, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), (char)(v7)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_POST_CTRL_SET_SCENARIO(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PCORE_DVFS_TRC_POST_CTRL_SET_SCENARIO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0421, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), (char)(v7)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_SET_SCENARIO(v1, v2, v3, v4) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0521, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_SET_SCENARIO(v1, v2, v3, v4)
#endif
#define PCORE_DVFS_TRC_SET_SCENARIO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0521, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_SET_TRACE_ON_OFF(v1, v2) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0621, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_SET_TRACE_ON_OFF(v1, v2)
#endif
#define PCORE_DVFS_TRC_SET_TRACE_ON_OFF_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0621, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_SET_BY_MODEML1(v1, v2, v3, v4) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0721, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_SET_BY_MODEML1(v1, v2, v3, v4)
#endif
#define PCORE_DVFS_TRC_SET_BY_MODEML1_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0721, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_SET_PLL_HW(v1, v2, v3) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0821, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_SET_PLL_HW(v1, v2, v3)
#endif
#define PCORE_DVFS_TRC_SET_PLL_HW_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0821, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_SET_PMIC_HW(v1, v2, v3) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0921, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_SET_PMIC_HW(v1, v2, v3)
#endif
#define PCORE_DVFS_TRC_SET_PMIC_HW_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0921, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_SET_MODEML1_RANGE(v1, v2, v3, v4) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A21, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_SET_MODEML1_RANGE(v1, v2, v3, v4)
#endif
#define PCORE_DVFS_TRC_SET_MODEML1_RANGE_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A21, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_MDL1_REQUEST_CCIRQ(v1, v2) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B21, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_MDL1_REQUEST_CCIRQ(v1, v2)
#endif
#define PCORE_DVFS_TRC_MDL1_REQUEST_CCIRQ_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B21, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_MDL1_REQUEST_CNF_CCIRQ(v1, v2) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C21, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_MDL1_REQUEST_CNF_CCIRQ(v1, v2)
#endif
#define PCORE_DVFS_TRC_MDL1_REQUEST_CNF_CCIRQ_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C21, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_CCIRQ_ACK(v1, v2, v3) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D21, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_CCIRQ_ACK(v1, v2, v3)
#endif
#define PCORE_DVFS_TRC_CCIRQ_ACK_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D21, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_SEQ_NUM_UPDATE(v1, v2) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E21, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_SEQ_NUM_UPDATE(v1, v2)
#endif
#define PCORE_DVFS_TRC_SEQ_NUM_UPDATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E21, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_P_FREQ_TITLE(v1) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F21, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_P_FREQ_TITLE(v1)
#endif
#define PCORE_DVFS_TRC_DUMP_P_FREQ_TITLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F21, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_P_VOLT_TITLE(v1) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1021, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_P_VOLT_TITLE(v1)
#endif
#define PCORE_DVFS_TRC_DUMP_P_VOLT_TITLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1021, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_MODEML1_TITLE(v1) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1121, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_MODEML1_TITLE(v1)
#endif
#define PCORE_DVFS_TRC_DUMP_MODEML1_TITLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1121, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_1(v1, v2) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1221, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_1(v1, v2)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1221, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_1(v1, v2) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1321, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_1(v1, v2)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1321, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_2(v1, v2, v3) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1421, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_2(v1, v2, v3)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1421, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_2(v1, v2, v3) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1521, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_2(v1, v2, v3)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1521, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_3(v1, v2, v3, v4) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1621, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_3(v1, v2, v3, v4)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1621, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_3(v1, v2, v3, v4) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1721, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_3(v1, v2, v3, v4)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1721, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_4(v1, v2, v3, v4, v5) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1821, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_4(v1, v2, v3, v4, v5)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1821, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_4(v1, v2, v3, v4, v5) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1921, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_4(v1, v2, v3, v4, v5)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1921, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_5(v1, v2, v3, v4, v5, v6) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1A21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_5(v1, v2, v3, v4, v5, v6)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1A21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_5(v1, v2, v3, v4, v5, v6) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1B21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_5(v1, v2, v3, v4, v5, v6)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1B21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1C21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1C21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1D21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1D21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x1E21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x1E21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x1F21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x1F21, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2021, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2021, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2121, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2121, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x2221, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_9_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x2221, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x2321, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_9_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x2321, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x2421, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_DEC_10_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x2421, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x2521, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_HEX_10_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x2521, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_INIT_STATE(v1, v2, v3, v4) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2621, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_INIT_STATE(v1, v2, v3, v4)
#endif
#define PCORE_DVFS_TRC_INIT_STATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2621, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_ENUM_6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2721, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_ENUM_6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_ENUM_6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2721, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_VALUE_ENUM_8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2821, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_VALUE_ENUM_8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define PCORE_DVFS_TRC_DUMP_VALUE_ENUM_8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2821, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_TABLE_MAX(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2921, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_TABLE_MAX(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PCORE_DVFS_TRC_DUMP_TABLE_MAX_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2921, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_SW_RECORD_HW_VALUE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x2A21, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_SW_RECORD_HW_VALUE(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PCORE_DVFS_TRC_DUMP_SW_RECORD_HW_VALUE_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x2A21, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_LOCAL_OP(v1, v2, v3) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B21, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_LOCAL_OP(v1, v2, v3)
#endif
#define PCORE_DVFS_TRC_DUMP_LOCAL_OP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B21, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DUMP_LOCAL_PLL_INT_STATE(v1, v2, v3) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C21, (char)(v1), (char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DUMP_LOCAL_PLL_INT_STATE(v1, v2, v3)
#endif
#define PCORE_DVFS_TRC_DUMP_LOCAL_PLL_INT_STATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C21, (char)(v1), (char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DVFS_HW_STATE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2D21, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DVFS_HW_STATE(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PCORE_DVFS_TRC_DVFS_HW_STATE_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2D21, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_DVFS_ADJ_STATE(v1, v2, v3, v4) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2E21, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_DVFS_ADJ_STATE(v1, v2, v3, v4)
#endif
#define PCORE_DVFS_TRC_DVFS_ADJ_STATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2E21, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_FM_CHECK(v1, v2, v3) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2F21, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_FM_CHECK(v1, v2, v3)
#endif
#define PCORE_DVFS_TRC_FM_CHECK_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2F21, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_ATCMD_CONTROL_DVFS(v1, v2) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3021, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_ATCMD_CONTROL_DVFS(v1, v2)
#endif
#define PCORE_DVFS_TRC_ATCMD_CONTROL_DVFS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3021, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_PTP_EN_STATE(v1, v2, v3) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3121, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_PTP_EN_STATE(v1, v2, v3)
#endif
#define PCORE_DVFS_TRC_PTP_EN_STATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3121, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_PTP_SET_MODEML1_RANGE(v1, v2, v3) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3221, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_PTP_SET_MODEML1_RANGE(v1, v2, v3)
#endif
#define PCORE_DVFS_TRC_PTP_SET_MODEML1_RANGE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3221, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define PCORE_DVFS_TRC_PTP_SET_PMIC_HW(v1, v2) do {\
		if(PCORE_DVFS_1_Trace_Filter[0]==1 && (PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3321, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PCORE_DVFS_TRC_PTP_SET_PMIC_HW(v1, v2)
#endif
#define PCORE_DVFS_TRC_PTP_SET_PMIC_HW_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3321, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char PCORE_DVFS_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_PCORE_DVFS_TRC_FLOW_DEBUG(unsigned char v1);
void L1TRC_Send_PCORE_DVFS_TRC_REGISTER(unsigned char v1, char v2);
void L1TRC_Send_PCORE_DVFS_TRC_CHECK(unsigned char v1, char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, char v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_PCORE_DVFS_TRC_PRE_CTRL_SET_SCENARIO(unsigned char v1, char v2, unsigned long v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_PCORE_DVFS_TRC_POST_CTRL_SET_SCENARIO(unsigned char v1, char v2, unsigned long v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_PCORE_DVFS_TRC_SET_SCENARIO(unsigned char v1, char v2, unsigned long v3, char v4);
void L1TRC_Send_PCORE_DVFS_TRC_SET_TRACE_ON_OFF(char v1, char v2);
void L1TRC_Send_PCORE_DVFS_TRC_SET_BY_MODEML1(unsigned long v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PCORE_DVFS_TRC_SET_PLL_HW(unsigned long v1, unsigned long v2, char v3);
void L1TRC_Send_PCORE_DVFS_TRC_SET_PMIC_HW(unsigned long v1, unsigned long v2, char v3);
void L1TRC_Send_PCORE_DVFS_TRC_SET_MODEML1_RANGE(unsigned long v1, unsigned short v2, unsigned short v3, char v4);
void L1TRC_Send_PCORE_DVFS_TRC_MDL1_REQUEST_CCIRQ(char v1, unsigned long v2);
void L1TRC_Send_PCORE_DVFS_TRC_MDL1_REQUEST_CNF_CCIRQ(char v1, unsigned long v2);
void L1TRC_Send_PCORE_DVFS_TRC_CCIRQ_ACK(unsigned long v1, unsigned long v2, char v3);
void L1TRC_Send_PCORE_DVFS_TRC_SEQ_NUM_UPDATE(unsigned long v1, char v2);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_P_FREQ_TITLE(unsigned char v1);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_P_VOLT_TITLE(unsigned char v1);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_MODEML1_TITLE(unsigned char v1);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_DEC_1(unsigned char v1, unsigned long v2);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_HEX_1(unsigned char v1, unsigned long v2);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_DEC_2(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_HEX_2(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_DEC_3(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_HEX_3(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_DEC_4(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_HEX_4(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_DEC_5(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_HEX_5(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_DEC_6(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_HEX_6(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_DEC_7(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_HEX_7(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_DEC_8(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_HEX_8(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_DEC_9(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_HEX_9(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_DEC_10(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_HEX_10(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11);
void L1TRC_Send_PCORE_DVFS_TRC_INIT_STATE(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_ENUM_6(unsigned char v1, char v2, char v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_VALUE_ENUM_8(unsigned char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8, char v9);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_TABLE_MAX(unsigned char v1, unsigned long v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned char v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_SW_RECORD_HW_VALUE(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_LOCAL_OP(char v1, char v2, char v3);
void L1TRC_Send_PCORE_DVFS_TRC_DUMP_LOCAL_PLL_INT_STATE(char v1, char v2, unsigned long v3);
void L1TRC_Send_PCORE_DVFS_TRC_DVFS_HW_STATE(unsigned char v1, char v2, char v3, char v4, char v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PCORE_DVFS_TRC_DVFS_ADJ_STATE(char v1, char v2, char v3, char v4);
void L1TRC_Send_PCORE_DVFS_TRC_FM_CHECK(unsigned long v1, unsigned long v2, char v3);
void L1TRC_Send_PCORE_DVFS_TRC_ATCMD_CONTROL_DVFS(unsigned char v1, char v2);
void L1TRC_Send_PCORE_DVFS_TRC_PTP_EN_STATE(char v1, char v2, char v3);
void L1TRC_Send_PCORE_DVFS_TRC_PTP_SET_MODEML1_RANGE(unsigned short v1, unsigned short v2, char v3);
void L1TRC_Send_PCORE_DVFS_TRC_PTP_SET_PMIC_HW(unsigned long v1, char v2);

void Set_PCORE_DVFS_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_PCORE_DVFS_1()	(PCORE_DVFS_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()	(ChkL1ModFltr_PCORE_DVFS_1()&&((PCORE_DVFS_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_PCORE_DVFS_TRC_FLOW_DEBUG()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_REGISTER()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_CHECK()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_PRE_CTRL_SET_SCENARIO()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_POST_CTRL_SET_SCENARIO()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_SET_SCENARIO()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_SET_TRACE_ON_OFF()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_SET_BY_MODEML1()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_SET_PLL_HW()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_SET_PMIC_HW()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_SET_MODEML1_RANGE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_MDL1_REQUEST_CCIRQ()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_MDL1_REQUEST_CNF_CCIRQ()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_CCIRQ_ACK()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_SEQ_NUM_UPDATE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_P_FREQ_TITLE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_P_VOLT_TITLE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_MODEML1_TITLE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_DEC_1()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_HEX_1()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_DEC_2()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_HEX_2()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_DEC_3()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_HEX_3()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_DEC_4()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_HEX_4()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_DEC_5()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_HEX_5()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_DEC_6()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_HEX_6()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_DEC_7()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_HEX_7()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_DEC_8()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_HEX_8()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_DEC_9()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_HEX_9()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_DEC_10()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_HEX_10()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_INIT_STATE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_ENUM_6()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_VALUE_ENUM_8()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_TABLE_MAX()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_SW_RECORD_HW_VALUE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_LOCAL_OP()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DUMP_LOCAL_PLL_INT_STATE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DVFS_HW_STATE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_DVFS_ADJ_STATE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_FM_CHECK()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_ATCMD_CONTROL_DVFS()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_PTP_EN_STATE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_PTP_SET_MODEML1_RANGE()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()
#define ChkL1MsgFltr_PCORE_DVFS_TRC_PTP_SET_PMIC_HW()	ChkL1ClsFltr_PCORE_DVFS_1_PCORE_DVFS_H()


#endif
