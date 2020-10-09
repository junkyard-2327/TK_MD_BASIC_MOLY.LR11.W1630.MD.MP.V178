#ifndef L1TRC_EL1D_POS_DEF_H
#define L1TRC_EL1D_POS_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MAIN_GET_ALL_FREQ_INFO_H(v1) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0035, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_POS_MAIN_GET_ALL_FREQ_INFO_H(v1)
#endif
#define EL1D_TRC_POS_MAIN_GET_ALL_FREQ_INFO_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0035, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_POS_MAIN_GET_PER_FREQ_INFO_L(v1, v2, v3, v4) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0135, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MAIN_GET_PER_FREQ_INFO_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_POS_MAIN_GET_PER_FREQ_INFO_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0135, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MAIN_BYPASS_REQ_H(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0235, (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), (char)(v7), (char)(v9)));\
	} while(0)
#else
	#define EL1D_TRC_POS_MAIN_BYPASS_REQ_H(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_POS_MAIN_BYPASS_REQ_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0235, (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), (char)(v7), (char)(v9)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_STATE_SWITCH_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0335, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_STATE_SWITCH_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_STATE_SWITCH_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0335, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_CMD_PRE_PROC_REQ_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0435, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_CMD_PRE_PROC_REQ_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_CMD_PRE_PROC_REQ_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0435, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_CMD_COR_PDP_REQ_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0535, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_POS_CMD_COR_PDP_REQ_H(v1, v2)
#endif
#define EL1D_TRC_POS_CMD_COR_PDP_REQ_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0535, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_CMD_PROC_H(v1) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0635, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_POS_CMD_PROC_H(v1)
#endif
#define EL1D_TRC_POS_CMD_PROC_H_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0635, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_SM_CMD_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0735, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v6), (char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (char)(v12), (char)(v13), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_SM_CMD_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#endif
#define EL1D_TRC_POS_DUMP_SM_CMD_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0735, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v6), (char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (char)(v12), (char)(v13), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_SM_SF_CFG_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0835, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_SM_SF_CFG_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_POS_DUMP_SM_SF_CFG_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0835, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_SM_TDD_HAND_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0935, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_SM_TDD_HAND_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_POS_DUMP_SM_TDD_HAND_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0935, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_SM_SEG_LENG_INTER_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0A35, (char)(v4), (char)(v5)), (long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_SM_SEG_LENG_INTER_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_DUMP_SM_SEG_LENG_INTER_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0A35, (char)(v4), (char)(v5)), (long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_SM_SEG_LENG_TDD_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B35, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_SM_SEG_LENG_TDD_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_DUMP_SM_SEG_LENG_TDD_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B35, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_SM_SEG_LENG_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0C35, (short)(v4)), (long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_SM_SEG_LENG_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_DUMP_SM_SEG_LENG_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0C35, (short)(v4)), (long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_SM_CFG_RFCC_START_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0D35, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v6), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_SM_CFG_RFCC_START_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_POS_DUMP_SM_CFG_RFCC_START_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0D35, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v6), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_SM_ADD_DFE_DELAY_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E35, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_SM_ADD_DFE_DELAY_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_DUMP_SM_ADD_DFE_DELAY_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E35, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_SM_CFG_RFCC_END_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F35, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_SM_CFG_RFCC_END_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_DUMP_SM_CFG_RFCC_END_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F35, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_SM_CAL_REF_TIME_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1035, (short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_SM_CAL_REF_TIME_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_DUMP_SM_CAL_REF_TIME_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1035, (short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_LOAD_CORR_RLT_H(v1, v2, v3, v4) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1135, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), (char)(v4)));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_LOAD_CORR_RLT_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_POS_DUMP_LOAD_CORR_RLT_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1135, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), (char)(v4)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_CAI_START_TIME_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1235, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), (char)(v4)), (unsigned long)(v3), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_CAI_START_TIME_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_POS_DUMP_CAI_START_TIME_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1235, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), (char)(v4)), (unsigned long)(v3), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_UPDATE_CAI_INFO_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1335, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v9), (char)(v10), TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_UPDATE_CAI_INFO_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_POS_DUMP_UPDATE_CAI_INFO_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1335, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v9), (char)(v10), TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_RXDMP_STATUS_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1435, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_RXDMP_STATUS_H(v1, v2)
#endif
#define EL1D_TRC_POS_RXDMP_STATUS_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1435, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_CONFIG_RXDMP_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1535, (char)(v1), (char)(v5)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_CONFIG_RXDMP_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_POS_DUMP_CONFIG_RXDMP_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1535, (char)(v1), (char)(v5)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_QUERY_RF_PRENCO_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1635, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_QUERY_RF_PRENCO_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_DUMP_QUERY_RF_PRENCO_H_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1635, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DUMP_FIRST_CMD_SCHEME_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1735, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_DUMP_FIRST_CMD_SCHEME_H(v1, v2)
#endif
#define EL1D_TRC_POS_DUMP_FIRST_CMD_SCHEME_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1735, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_FSM_MEAS_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1835, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_FSM_MEAS_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_MEAS_FSM_MEAS_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1835, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_MAIN_ENTRY_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1935, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_MAIN_ENTRY_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_MEAS_MAIN_ENTRY_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1935, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_DUMP_DONE_HISR_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A35, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_DUMP_DONE_HISR_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_POS_MEAS_DUMP_DONE_HISR_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A35, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_TD2FD_DONE_ISR_H(v1) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_TD2FD_DONE_ISR_H(v1)
#endif
#define EL1D_TRC_POS_MEAS_TD2FD_DONE_ISR_H_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_TD2FD_DONE_HISR_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C35, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_TD2FD_DONE_HISR_H(v1, v2)
#endif
#define EL1D_TRC_POS_MEAS_TD2FD_DONE_HISR_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C35, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_MEAS_HISR_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D35, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_MEAS_HISR_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_MEAS_MEAS_HISR_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D35, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_PERCEELL_DONE_ISR_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E35, (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((char)(v4), (unsigned char)(v5), (char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_PERCEELL_DONE_ISR_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_POS_MEAS_PERCEELL_DONE_ISR_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E35, (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((char)(v4), (unsigned char)(v5), (char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_PERCEELL_DONE_HISR_1_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1F35, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_PERCEELL_DONE_HISR_1_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_POS_MEAS_PERCEELL_DONE_HISR_1_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1F35, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_PERCEELL_DONE_HISR_2_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2035, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_PERCEELL_DONE_HISR_2_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_MEAS_PERCEELL_DONE_HISR_2_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2035, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_WRITE_TD2FD_H(v1) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2135, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_WRITE_TD2FD_H(v1)
#endif
#define EL1D_TRC_POS_MEAS_WRITE_TD2FD_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2135, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_WRITE_TD2FD_CSIF_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2235, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_WRITE_TD2FD_CSIF_H(v1, v2)
#endif
#define EL1D_TRC_POS_MEAS_WRITE_TD2FD_CSIF_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2235, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_WRITE_PERCELL_INFO_1_H(v1, v2, v3, v4) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2335, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_WRITE_PERCELL_INFO_1_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_POS_MEAS_WRITE_PERCELL_INFO_1_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2335, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_WRITE_PERCELL_INFO_2_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2435, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_WRITE_PERCELL_INFO_2_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_POS_MEAS_WRITE_PERCELL_INFO_2_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2435, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_WRITE_L1C_RPT_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2535, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_WRITE_L1C_RPT_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_MEAS_WRITE_L1C_RPT_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2535, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_CLR_MEAS_RESULT_H() do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2635, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_CLR_MEAS_RESULT_H()
#endif
#define EL1D_TRC_POS_MEAS_CLR_MEAS_RESULT_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2635, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_IS_IDLE_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2735, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_IS_IDLE_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_MEAS_IS_IDLE_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2735, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_ABORT_DONE_ISR_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2835, (char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_ABORT_DONE_ISR_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_MEAS_ABORT_DONE_ISR_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2835, (char)(v2), (char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_IN_MEASURING_H(v1, v2, v3, v4) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2935, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_IN_MEASURING_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_POS_MEAS_IN_MEASURING_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2935, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_WRITE_ABORT_RPT_H(v1) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2A35, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_WRITE_ABORT_RPT_H(v1)
#endif
#define EL1D_TRC_POS_MEAS_WRITE_ABORT_RPT_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2A35, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_WRITE_PERCELL_CSIF_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B35, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_WRITE_PERCELL_CSIF_H(v1, v2)
#endif
#define EL1D_TRC_POS_MEAS_WRITE_PERCELL_CSIF_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B35, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_ASSISTANCE_DATA_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x2C35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_ASSISTANCE_DATA_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_POS_MEAS_ASSISTANCE_DATA_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x2C35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_SEND_IRQ_H(v1) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D35, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_SEND_IRQ_H(v1)
#endif
#define EL1D_TRC_POS_MEAS_SEND_IRQ_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D35, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_DEBUG_1_H(v1) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E35, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_DEBUG_1_H(v1)
#endif
#define EL1D_TRC_POS_MEAS_DEBUG_1_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E35, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_DEBUG_2_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_DEBUG_2_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_MEAS_DEBUG_2_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_DEBUG_3_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3035, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_DEBUG_3_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_MEAS_DEBUG_3_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3035, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_HW_PATH_DELAY_INFO_H(v1, v2, v3, v4) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3135, (char)(v4), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_HW_PATH_DELAY_INFO_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_POS_MEAS_HW_PATH_DELAY_INFO_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3135, (char)(v4), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_TOA_BIAS_INFO_H(v1, v2, v3, v4) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3235, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_TOA_BIAS_INFO_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_POS_MEAS_TOA_BIAS_INFO_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3235, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_FINAL_TOA_SNR_INFO_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3335, (unsigned char)(v1), (char)(v6)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_FINAL_TOA_SNR_INFO_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_POS_MEAS_FINAL_TOA_SNR_INFO_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3335, (unsigned char)(v1), (char)(v6)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_MEAS_SKIP_CELL_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3435, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_MEAS_SKIP_CELL_H(v1, v2)
#endif
#define EL1D_TRC_POS_MEAS_SKIP_CELL_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3435, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_STATE_HANDLER_L(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3535, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_STATE_HANDLER_L(v1, v2, v3)
#endif
#define EL1D_TRC_POS_AGC_STATE_HANDLER_L_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3535, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_STATE_SWITCH_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3635, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_STATE_SWITCH_H(v1, v2)
#endif
#define EL1D_TRC_POS_AGC_STATE_SWITCH_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3635, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_SET_REQ_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3735, (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_SET_REQ_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_POS_AGC_SET_REQ_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3735, (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_SET_REQ_INTER_H(v1, v2, v3, v4) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3835, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_SET_REQ_INTER_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_POS_AGC_SET_REQ_INTER_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3835, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_CLEAR_REQ_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3935, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_CLEAR_REQ_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_AGC_CLEAR_REQ_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3935, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_CONFIG_SF_H(v1, v2, v3, v4) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A35, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_CONFIG_SF_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_POS_AGC_CONFIG_SF_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A35, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_SET_CONFIG_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B35, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_SET_CONFIG_H(v1, v2)
#endif
#define EL1D_TRC_POS_AGC_SET_CONFIG_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B35, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_PROC_RLT_INIT_GAIN_H(v1, v2, v3, v4) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3C35, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_PROC_RLT_INIT_GAIN_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_POS_AGC_PROC_RLT_INIT_GAIN_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3C35, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_PROC_RLT_NORMAL_1_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3D35, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_PROC_RLT_NORMAL_1_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_AGC_PROC_RLT_NORMAL_1_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3D35, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_PROC_RLT_NORMAL_2_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3E35, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_PROC_RLT_NORMAL_2_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_AGC_PROC_RLT_NORMAL_2_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3E35, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_REF_CELL_INFO_H(v1, v2, v3, v4) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F35, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_REF_CELL_INFO_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_POS_AGC_REF_CELL_INFO_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F35, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_CTRL_NUM_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4035, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_CTRL_NUM_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_POS_AGC_CTRL_NUM_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4035, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_DRAM_BUF_ADDRESS_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4135, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_POS_DRAM_BUF_ADDRESS_H(v1, v2)
#endif
#define EL1D_TRC_POS_DRAM_BUF_ADDRESS_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4135, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_POS_WRITE_AGC_INFO_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4235, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_POS_WRITE_AGC_INFO_H(v1, v2)
#endif
#define EL1D_TRC_POS_WRITE_AGC_INFO_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4235, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_RXLPWR_H(v1) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4335, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_RXLPWR_H(v1)
#endif
#define EL1D_TRC_POS_RXLPWR_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4335, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_DEBUG_1_H(v1, v2, v3) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4435, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_DEBUG_1_H(v1, v2, v3)
#endif
#define EL1D_TRC_POS_AGC_DEBUG_1_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4435, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_POS_AGC_DEBUG_2_H(v1, v2) do {\
		if(EL1D_POS_Trace_Filter[0]==1 && (EL1D_POS_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4535, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_POS_AGC_DEBUG_2_H(v1, v2)
#endif
#define EL1D_TRC_POS_AGC_DEBUG_2_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4535, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_POS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_POS_MAIN_GET_ALL_FREQ_INFO_H(short v1);
void L1TRC_Send_EL1D_TRC_POS_MAIN_GET_PER_FREQ_INFO_L(char v1, unsigned short v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_POS_MAIN_BYPASS_REQ_H(unsigned char v1, char v2, unsigned char v3, unsigned char v4, char v5, char v6, char v7, unsigned short v8, char v9);
void L1TRC_Send_EL1D_TRC_POS_STATE_SWITCH_H(unsigned char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_POS_CMD_PRE_PROC_REQ_H(char v1, char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_POS_CMD_COR_PDP_REQ_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_POS_CMD_PROC_H(long v1);
void L1TRC_Send_EL1D_TRC_POS_DUMP_SM_CMD_H(unsigned char v1, unsigned char v2, char v3, char v4, unsigned short v5, char v6, unsigned short v7, unsigned short v8, unsigned short v9, char v10, unsigned char v11, char v12, char v13);
void L1TRC_Send_EL1D_TRC_POS_DUMP_SM_SF_CFG_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, char v6, char v7, char v8, unsigned char v9, unsigned char v10, unsigned char v11);
void L1TRC_Send_EL1D_TRC_POS_DUMP_SM_TDD_HAND_H(unsigned char v1, unsigned char v2, char v3, unsigned char v4, short v5, char v6);
void L1TRC_Send_EL1D_TRC_POS_DUMP_SM_SEG_LENG_INTER_H(long v1, unsigned long v2, unsigned long v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_POS_DUMP_SM_SEG_LENG_TDD_H(char v1, unsigned short v2, long v3);
void L1TRC_Send_EL1D_TRC_POS_DUMP_SM_SEG_LENG_H(long v1, unsigned long v2, unsigned long v3, short v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_POS_DUMP_SM_CFG_RFCC_START_H(char v1, char v2, unsigned short v3, char v4, char v5, unsigned short v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_POS_DUMP_SM_ADD_DFE_DELAY_H(unsigned long v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_POS_DUMP_SM_CFG_RFCC_END_H(char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_POS_DUMP_SM_CAL_REF_TIME_H(short v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_POS_DUMP_LOAD_CORR_RLT_H(short v1, char v2, short v3, char v4);
void L1TRC_Send_EL1D_TRC_POS_DUMP_CAI_START_TIME_H(char v1, unsigned short v2, unsigned long v3, char v4, unsigned short v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_POS_DUMP_UPDATE_CAI_INFO_H(char v1, char v2, char v3, unsigned short v4, unsigned long v5, unsigned long v6, unsigned short v7, unsigned long v8, char v9, char v10);
void L1TRC_Send_EL1D_TRC_POS_RXDMP_STATUS_H(char v1, short v2);
void L1TRC_Send_EL1D_TRC_POS_DUMP_CONFIG_RXDMP_H(char v1, unsigned long v2, unsigned long v3, unsigned long v4, char v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_POS_DUMP_QUERY_RF_PRENCO_H(long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_POS_DUMP_FIRST_CMD_SCHEME_H(char v1, short v2);
void L1TRC_Send_EL1D_TRC_POS_MEAS_FSM_MEAS_L(unsigned char v1, unsigned char v2, char v3, unsigned char v4, char v5);
void L1TRC_Send_EL1D_TRC_POS_MEAS_MAIN_ENTRY_H(char v1, unsigned char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_POS_MEAS_DUMP_DONE_HISR_H(unsigned char v1, unsigned char v2, unsigned char v3, char v4, unsigned char v5, char v6);
void L1TRC_Send_EL1D_TRC_POS_MEAS_TD2FD_DONE_ISR_H(unsigned long v1);
void L1TRC_Send_EL1D_TRC_POS_MEAS_TD2FD_DONE_HISR_H(char v1, char v2);
void L1TRC_Send_EL1D_TRC_POS_MEAS_MEAS_HISR_H(unsigned char v1, unsigned char v2, char v3, unsigned char v4, char v5);
void L1TRC_Send_EL1D_TRC_POS_MEAS_PERCEELL_DONE_ISR_H(unsigned long v1, unsigned char v2, unsigned char v3, char v4, unsigned char v5, char v6);
void L1TRC_Send_EL1D_TRC_POS_MEAS_PERCEELL_DONE_HISR_1_H(unsigned char v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_POS_MEAS_PERCEELL_DONE_HISR_2_H(unsigned char v1, unsigned char v2, char v3, unsigned char v4, char v5);
void L1TRC_Send_EL1D_TRC_POS_MEAS_WRITE_TD2FD_H(char v1);
void L1TRC_Send_EL1D_TRC_POS_MEAS_WRITE_TD2FD_CSIF_H(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_POS_MEAS_WRITE_PERCELL_INFO_1_H(short v1, char v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_POS_MEAS_WRITE_PERCELL_INFO_2_H(char v1, unsigned char v2, unsigned char v3, char v4, unsigned char v5, char v6);
void L1TRC_Send_EL1D_TRC_POS_MEAS_WRITE_L1C_RPT_H(short v1, unsigned char v2, short v3, unsigned char v4, char v5);
void L1TRC_Send_EL1D_TRC_POS_MEAS_CLR_MEAS_RESULT_H(void);
void L1TRC_Send_EL1D_TRC_POS_MEAS_IS_IDLE_H(short v1, char v2, short v3);
void L1TRC_Send_EL1D_TRC_POS_MEAS_ABORT_DONE_ISR_H(unsigned long v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_POS_MEAS_IN_MEASURING_H(char v1, char v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_POS_MEAS_WRITE_ABORT_RPT_H(short v1);
void L1TRC_Send_EL1D_TRC_POS_MEAS_WRITE_PERCELL_CSIF_H(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_POS_MEAS_ASSISTANCE_DATA_H(short v1, short v2, short v3, short v4, short v5, unsigned long v6, unsigned long v7, short v8);
void L1TRC_Send_EL1D_TRC_POS_MEAS_SEND_IRQ_H(char v1);
void L1TRC_Send_EL1D_TRC_POS_MEAS_DEBUG_1_H(short v1);
void L1TRC_Send_EL1D_TRC_POS_MEAS_DEBUG_2_H(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_POS_MEAS_DEBUG_3_H(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_POS_MEAS_HW_PATH_DELAY_INFO_H(long v1, long v2, long v3, char v4);
void L1TRC_Send_EL1D_TRC_POS_MEAS_TOA_BIAS_INFO_H(long v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_POS_MEAS_FINAL_TOA_SNR_INFO_H(unsigned char v1, long v2, long v3, long v4, long v5, char v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_POS_MEAS_SKIP_CELL_H(short v1, short v2);
void L1TRC_Send_EL1D_TRC_POS_AGC_STATE_HANDLER_L(unsigned char v1, char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_POS_AGC_STATE_SWITCH_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_POS_AGC_SET_REQ_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned short v6, unsigned long v7, unsigned char v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_EL1D_TRC_POS_AGC_SET_REQ_INTER_H(unsigned char v1, char v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_POS_AGC_CLEAR_REQ_H(unsigned char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_POS_AGC_CONFIG_SF_H(unsigned char v1, unsigned char v2, unsigned char v3, char v4);
void L1TRC_Send_EL1D_TRC_POS_AGC_SET_CONFIG_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_POS_AGC_PROC_RLT_INIT_GAIN_H(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_POS_AGC_PROC_RLT_NORMAL_1_L(unsigned char v1, unsigned char v2, unsigned long v3, unsigned short v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_POS_AGC_PROC_RLT_NORMAL_2_H(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_EL1D_TRC_POS_AGC_REF_CELL_INFO_H(unsigned char v1, unsigned char v2, char v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_POS_AGC_CTRL_NUM_H(unsigned long v1, unsigned short v2, unsigned char v3, char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_POS_DRAM_BUF_ADDRESS_H(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_POS_WRITE_AGC_INFO_H(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_POS_RXLPWR_H(char v1);
void L1TRC_Send_EL1D_TRC_POS_AGC_DEBUG_1_H(short v1, short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_POS_AGC_DEBUG_2_H(short v1, short v2);

void Set_EL1D_POS_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_POS()	(EL1D_POS_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MAIN_H()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MAIN_M()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MAIN_L()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_CMD_H()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_CMD_M()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_CMD_L()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_M()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_L()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_M()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_L()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_M()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_L()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DEBUG_H()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DEBUG_L()	(ChkL1ModFltr_EL1D_POS()&&((EL1D_POS_Trace_Filter[3]&0x01)!=0))
#define ChkL1MsgFltr_EL1D_TRC_POS_MAIN_GET_ALL_FREQ_INFO_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MAIN_GET_PER_FREQ_INFO_L()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_POS_MAIN_BYPASS_REQ_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_STATE_SWITCH_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_CMD_PRE_PROC_REQ_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_CMD_COR_PDP_REQ_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_CMD_PROC_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_SM_CMD_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_SM_SF_CFG_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_SM_TDD_HAND_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_SM_SEG_LENG_INTER_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_SM_SEG_LENG_TDD_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_SM_SEG_LENG_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_SM_CFG_RFCC_START_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_SM_ADD_DFE_DELAY_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_SM_CFG_RFCC_END_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_SM_CAL_REF_TIME_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_LOAD_CORR_RLT_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_CAI_START_TIME_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_UPDATE_CAI_INFO_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_RXDMP_STATUS_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_CONFIG_RXDMP_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_QUERY_RF_PRENCO_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DUMP_FIRST_CMD_SCHEME_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_FSM_MEAS_L()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_MAIN_ENTRY_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_DUMP_DONE_HISR_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_TD2FD_DONE_ISR_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_TD2FD_DONE_HISR_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_MEAS_HISR_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_PERCEELL_DONE_ISR_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_PERCEELL_DONE_HISR_1_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_PERCEELL_DONE_HISR_2_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_WRITE_TD2FD_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_WRITE_TD2FD_CSIF_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_WRITE_PERCELL_INFO_1_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_WRITE_PERCELL_INFO_2_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_WRITE_L1C_RPT_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_CLR_MEAS_RESULT_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_IS_IDLE_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_ABORT_DONE_ISR_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_IN_MEASURING_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_WRITE_ABORT_RPT_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_WRITE_PERCELL_CSIF_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_ASSISTANCE_DATA_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_SEND_IRQ_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_DEBUG_1_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_DEBUG_2_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_DEBUG_3_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_HW_PATH_DELAY_INFO_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_TOA_BIAS_INFO_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_FINAL_TOA_SNR_INFO_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_MEAS_SKIP_CELL_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_MEAS_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_STATE_HANDLER_L()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_STATE_SWITCH_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_SET_REQ_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_SET_REQ_INTER_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_CLEAR_REQ_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_CONFIG_SF_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_SET_CONFIG_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_PROC_RLT_INIT_GAIN_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_PROC_RLT_NORMAL_1_L()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_PROC_RLT_NORMAL_2_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_REF_CELL_INFO_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_CTRL_NUM_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_DRAM_BUF_ADDRESS_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DEBUG_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_WRITE_AGC_INFO_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DEBUG_L()
#define ChkL1MsgFltr_EL1D_TRC_POS_RXLPWR_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DEBUG_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_DEBUG_1_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DEBUG_H()
#define ChkL1MsgFltr_EL1D_TRC_POS_AGC_DEBUG_2_H()	ChkL1ClsFltr_EL1D_POS_EL1D_TRC_POS_DEBUG_H()


#endif
