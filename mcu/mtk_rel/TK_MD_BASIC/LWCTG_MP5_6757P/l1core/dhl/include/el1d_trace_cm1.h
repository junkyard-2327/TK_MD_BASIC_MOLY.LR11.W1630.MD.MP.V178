#ifndef L1TRC_EL1D_CM1_DEF_H
#define L1TRC_EL1D_CM1_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_GROUPING_START_H(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x002F, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_GROUPING_START_H(v1)
#endif
#define EL1D_TRC_CM1_FEICIC_GROUPING_START_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x002F, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_UPDATE_GROUPING_H(v1, v2, v3, v4) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x012F, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_UPDATE_GROUPING_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM1_FEICIC_UPDATE_GROUPING_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x012F, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_BACK_UP_CT_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x022F, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v3)), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_BACK_UP_CT_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM1_FEICIC_BACK_UP_CT_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x022F, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v3)), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_CONFIG_MPC_INFO_H(v1, v2, v3) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x032F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_CONFIG_MPC_INFO_H(v1, v2, v3)
#endif
#define EL1D_TRC_CM1_FEICIC_CONFIG_MPC_INFO_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x032F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_CONFIG_MPC_CELL_LIST_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x042F, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_1S2C((short)(v17), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_CONFIG_MPC_CELL_LIST_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define EL1D_TRC_CM1_FEICIC_CONFIG_MPC_CELL_LIST_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x042F, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_1S2C((short)(v17), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_SET_SCC_DL_FREQ_H(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x052F, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_SET_SCC_DL_FREQ_H(v1)
#endif
#define EL1D_TRC_CM1_FEICIC_SET_SCC_DL_FREQ_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x052F, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_H(v1, v2, v3) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x062F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_H(v1, v2, v3)
#endif
#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x062F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_CELL_INFO_H(v1, v2, v3) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x072F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_CELL_INFO_H(v1, v2, v3)
#endif
#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_CELL_INFO_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x072F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_NEW_GROUP_H(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x082F, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_NEW_GROUP_H(v1, v2)
#endif
#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_NEW_GROUP_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x082F, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_SELECT_T_FIRST_H(v1, v2, v3) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x092F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_SELECT_T_FIRST_H(v1, v2, v3)
#endif
#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_SELECT_T_FIRST_H_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x092F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_DIFF_JUDGE_H(v1, v2, v3, v4) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0A2F, (short)(v4)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_DIFF_JUDGE_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_DIFF_JUDGE_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0A2F, (short)(v4)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FEICIC_CM_RSTR_H(v1, v2, v3, v4) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B2F, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FEICIC_CM_RSTR_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM1_FEICIC_CM_RSTR_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B2F, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SRV_CM_START_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C2F, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_CM_START_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM1_SRV_CM_START_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C2F, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SRV_CM_BUF_H(v1, v2, v3) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D2F, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_CM_BUF_H(v1, v2, v3)
#endif
#define EL1D_TRC_CM1_SRV_CM_BUF_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D2F, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_SRV_RPT_INFO_L(v1, v2, v3) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E2F, (char)(v1), (char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_RPT_INFO_L(v1, v2, v3)
#endif
#define EL1D_TRC_CM1_SRV_RPT_INFO_L_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E2F, (char)(v1), (char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SRV_RPT_INFO_H(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F2F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_RPT_INFO_H(v1)
#endif
#define EL1D_TRC_CM1_SRV_RPT_INFO_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F2F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SRV_RPT_CELL_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x102F, (unsigned short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((char)(v1), (char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_RPT_CELL_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define EL1D_TRC_CM1_SRV_RPT_CELL_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_8_DATA(TRC_MERGE_2S(0x102F, (unsigned short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((char)(v1), (char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SRV_CC_CHANGE_H(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x112F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_CC_CHANGE_H(v1)
#endif
#define EL1D_TRC_CM1_SRV_CC_CHANGE_H_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x112F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SRV_CMD_PRE_PROCESS_H(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x122F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_CMD_PRE_PROCESS_H(v1, v2)
#endif
#define EL1D_TRC_CM1_SRV_CMD_PRE_PROCESS_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x122F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_SRV_RX_CC_INFO_L(v1, v2, v3, v4) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x132F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_RX_CC_INFO_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM1_SRV_RX_CC_INFO_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x132F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SRV_CM_RSTR_PCELL_H(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x142F, (unsigned short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), (unsigned char)(v8), (char)(v9)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_CM_RSTR_PCELL_H(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_CM1_SRV_CM_RSTR_PCELL_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_6_DATA(TRC_MERGE_2S(0x142F, (unsigned short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), (unsigned char)(v8), (char)(v9)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SRV_RX_PATH_IN_H(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x152F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_RX_PATH_IN_H(v1, v2)
#endif
#define EL1D_TRC_CM1_SRV_RX_PATH_IN_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x152F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SRV_RX_PATH_OUT_H(v1, v2, v3, v4) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x162F, (short)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SRV_RX_PATH_OUT_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM1_SRV_RX_PATH_OUT_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x162F, (short)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_CSIF_IRQ_TRIG_H(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x172F, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_IRQ_TRIG_H(v1)
#endif
#define EL1D_TRC_CM1_CSIF_IRQ_TRIG_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x172F, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_RPT_ABORT_VALID_SET_L(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x182F, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_RPT_ABORT_VALID_SET_L(v1, v2)
#endif
#define EL1D_TRC_CM1_CSIF_RPT_ABORT_VALID_SET_L_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x182F, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_RPT_ABORT_VALID_READ_L(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x192F, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_RPT_ABORT_VALID_READ_L(v1, v2)
#endif
#define EL1D_TRC_CM1_CSIF_RPT_ABORT_VALID_READ_L_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x192F, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_1_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A2F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v6), (char)(v7), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_1_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_1_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A2F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v6), (char)(v7), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_2_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B2F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_2_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_2_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B2F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_3_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C2F, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_3_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_3_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C2F, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_RPT_INFO_SET_L(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1D2F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_RPT_INFO_SET_L(v1, v2)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_RPT_INFO_SET_L_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1D2F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_SRV_INFO_SET_L(v1, v2, v3, v4) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E2F, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_SRV_INFO_SET_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_SRV_INFO_SET_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E2F, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_1_L(v1, v2, v3) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F2F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_1_L(v1, v2, v3)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_1_L_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F2F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_2_L(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x202F, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_2_L(v1)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_2_L_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x202F, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_3_L(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x212F, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_3_L(v1, v2)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_3_L_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x212F, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_4_L(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x222F, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_4_L(v1)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_4_L_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x222F, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_5_L(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x232F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_5_L(v1)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_5_L_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x232F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_NBR_CELL_INFO_SET_1_L(v1, v2, v3, v4) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x242F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_5MS_CMD_NBR_CELL_INFO_SET_1_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM1_CSIF_5MS_CMD_NBR_CELL_INFO_SET_1_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x242F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_CSIF_1MS_CMD_COMMON_SET_1_H(v1, v2, v3) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x252F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_1MS_CMD_COMMON_SET_1_H(v1, v2, v3)
#endif
#define EL1D_TRC_CM1_CSIF_1MS_CMD_COMMON_SET_1_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x252F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_CM1_CSIF_1MS_CMD_DUMP_SET_1_M(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x262F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_1MS_CMD_DUMP_SET_1_M(v1, v2)
#endif
#define EL1D_TRC_CM1_CSIF_1MS_CMD_DUMP_SET_1_M_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x262F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_1MS_CMD_WINSTART_SET_L(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x272F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_1MS_CMD_WINSTART_SET_L(v1, v2)
#endif
#define EL1D_TRC_CM1_CSIF_1MS_CMD_WINSTART_SET_L_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x272F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_CSIF_RPT_ABORT_READ_H(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x282F, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_RPT_ABORT_READ_H(v1)
#endif
#define EL1D_TRC_CM1_CSIF_RPT_ABORT_READ_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x282F, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_CSIF_RPT_INFO_READ_1_H(v1, v2, v3, v4) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x292F, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), (unsigned char)(v4)));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_RPT_INFO_READ_1_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM1_CSIF_RPT_INFO_READ_1_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x292F, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_CSIF_RPT_ALL_INFO_1_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2A2F, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_2S((short)(v18), (short)(v19)), TRC_MERGE_4C((char)(v1), (char)(v5), (char)(v6), (char)(v7)));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_RPT_ALL_INFO_1_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19)
#endif
#define EL1D_TRC_CM1_CSIF_RPT_ALL_INFO_1_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2A2F, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_2S((short)(v18), (short)(v19)), TRC_MERGE_4C((char)(v1), (char)(v5), (char)(v6), (char)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_CSIF_RPT_ALL_INFO_2_L(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_14_DATA(TRC_MERGE_2S(0x2B2F, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_2S((short)(v17), (short)(v18)), TRC_MERGE_2S((short)(v19), (short)(v20)), TRC_MERGE_2S((short)(v21), (short)(v22)), TRC_MERGE_2S((short)(v23), (short)(v24)), TRC_MERGE_2S((short)(v25), (short)(v26)), TRC_MERGE_1S2C((short)(v27), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_CSIF_RPT_ALL_INFO_2_L(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27)
#endif
#define EL1D_TRC_CM1_CSIF_RPT_ALL_INFO_2_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27) TRC_SEND_14_DATA(TRC_MERGE_2S(0x2B2F, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_2S((short)(v17), (short)(v18)), TRC_MERGE_2S((short)(v19), (short)(v20)), TRC_MERGE_2S((short)(v21), (short)(v22)), TRC_MERGE_2S((short)(v23), (short)(v24)), TRC_MERGE_2S((short)(v25), (short)(v26)), TRC_MERGE_1S2C((short)(v27), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_DCTG_CONFIG1_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C2F, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_DCTG_CONFIG1_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CM1_DCTG_CONFIG1_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C2F, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_DCTG_CONFIG2_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D2F, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_DCTG_CONFIG2_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CM1_DCTG_CONFIG2_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D2F, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_DCTG_CONFIG3_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2E2F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_CM1_DCTG_CONFIG3_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CM1_DCTG_CONFIG3_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2E2F, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_STIRQ_TRIG_L(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F2F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM1_STIRQ_TRIG_L(v1, v2)
#endif
#define EL1D_TRC_CM1_STIRQ_TRIG_L_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F2F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_LITE_ACI_SOL_CHG1_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x302F, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_LITE_ACI_SOL_CHG1_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CM1_LITE_ACI_SOL_CHG1_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x302F, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_LITE_ACI_SOL_CHG2_H(v1, v2, v3, v4) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x312F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_LITE_ACI_SOL_CHG2_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM1_LITE_ACI_SOL_CHG2_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x312F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_DBG_TDB_DUMP_INJECT_STRING_H(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x322F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_DBG_TDB_DUMP_INJECT_STRING_H(v1)
#endif
#define EL1D_TRC_CM1_DBG_TDB_DUMP_INJECT_STRING_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x322F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_DBG_FEICIC_ON_OFF_INJECT_STRING_H(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x332F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_DBG_FEICIC_ON_OFF_INJECT_STRING_H(v1)
#endif
#define EL1D_TRC_CM1_DBG_FEICIC_ON_OFF_INJECT_STRING_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x332F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_TO_DBG_H(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x342F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_TO_DBG_H(v1)
#endif
#define EL1D_TRC_CM1_TO_DBG_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x342F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SPV_H(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x352F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SPV_H(v1, v2)
#endif
#define EL1D_TRC_CM1_SPV_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x352F, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_SPV_CM_H(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x362F, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CM1_SPV_CM_H(v1, v2)
#endif
#define EL1D_TRC_CM1_SPV_CM_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x362F, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM1_FORCE_MAN_ZERO_H(v1) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x372F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM1_FORCE_MAN_ZERO_H(v1)
#endif
#define EL1D_TRC_CM1_FORCE_MAN_ZERO_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x372F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM1_DBG_REF_UDC_L(v1, v2) do {\
		if(EL1D_CM1_Trace_Filter[0]==1 && (EL1D_CM1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x382F, (char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CM1_DBG_REF_UDC_L(v1, v2)
#endif
#define EL1D_TRC_CM1_DBG_REF_UDC_L_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x382F, (char)(v1), (unsigned char)(v2)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_CM1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_CM1_FEICIC_GROUPING_START_H(char v1);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_UPDATE_GROUPING_H(char v1, short v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_BACK_UP_CT_H(char v1, unsigned short v2, char v3, short v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_CONFIG_MPC_INFO_H(char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_CONFIG_MPC_CELL_LIST_H(char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_SET_SCC_DL_FREQ_H(short v1);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_H(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_CELL_INFO_H(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_NEW_GROUP_H(short v1, short v2);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_SELECT_T_FIRST_H(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_DIFF_JUDGE_H(unsigned long v1, unsigned long v2, unsigned long v3, short v4);
void L1TRC_Send_EL1D_TRC_CM1_FEICIC_CM_RSTR_H(char v1, unsigned short v2, unsigned char v3, char v4);
void L1TRC_Send_EL1D_TRC_CM1_SRV_CM_START_H(char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_CM1_SRV_CM_BUF_H(unsigned short v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_CM1_SRV_RPT_INFO_L(char v1, char v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_CM1_SRV_RPT_INFO_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_CM1_SRV_RPT_CELL_H(char v1, char v2, unsigned short v3, unsigned char v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_EL1D_TRC_CM1_SRV_CC_CHANGE_H(unsigned long v1);
void L1TRC_Send_EL1D_TRC_CM1_SRV_CMD_PRE_PROCESS_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CM1_SRV_RX_CC_INFO_L(char v1, char v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_CM1_SRV_CM_RSTR_PCELL_H(char v1, char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned short v7, unsigned char v8, char v9);
void L1TRC_Send_EL1D_TRC_CM1_SRV_RX_PATH_IN_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CM1_SRV_RX_PATH_OUT_H(unsigned long v1, unsigned long v2, short v3, char v4);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_IRQ_TRIG_H(char v1);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_RPT_ABORT_VALID_SET_L(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_RPT_ABORT_VALID_READ_L(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_1_H(unsigned short v1, char v2, char v3, char v4, unsigned short v5, char v6, char v7);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_2_H(char v1, char v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_3_H(unsigned short v1, char v2, char v3, char v4, unsigned char v5, char v6);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_RPT_INFO_SET_L(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_SRV_INFO_SET_L(char v1, unsigned short v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_1_L(char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_2_L(char v1);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_3_L(char v1, char v2);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_4_L(char v1);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_5_L(long v1);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_5MS_CMD_NBR_CELL_INFO_SET_1_L(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_1MS_CMD_COMMON_SET_1_H(char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_1MS_CMD_DUMP_SET_1_M(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_1MS_CMD_WINSTART_SET_L(long v1, long v2);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_RPT_ABORT_READ_H(char v1);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_RPT_INFO_READ_1_H(char v1, unsigned short v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_RPT_ALL_INFO_1_H(char v1, unsigned short v2, unsigned short v3, short v4, char v5, char v6, char v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17, short v18, short v19);
void L1TRC_Send_EL1D_TRC_CM1_CSIF_RPT_ALL_INFO_2_L(char v1, unsigned short v2, unsigned short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17, short v18, short v19, short v20, short v21, short v22, short v23, short v24, short v25, short v26, short v27);
void L1TRC_Send_EL1D_TRC_CM1_DCTG_CONFIG1_H(char v1, short v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_EL1D_TRC_CM1_DCTG_CONFIG2_H(char v1, char v2, char v3, short v4, short v5, short v6);
void L1TRC_Send_EL1D_TRC_CM1_DCTG_CONFIG3_H(char v1, char v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_EL1D_TRC_CM1_STIRQ_TRIG_L(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CM1_LITE_ACI_SOL_CHG1_H(char v1, short v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_EL1D_TRC_CM1_LITE_ACI_SOL_CHG2_H(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_CM1_DBG_TDB_DUMP_INJECT_STRING_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_CM1_DBG_FEICIC_ON_OFF_INJECT_STRING_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_CM1_TO_DBG_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_CM1_SPV_H(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CM1_SPV_CM_H(unsigned long v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_CM1_FORCE_MAN_ZERO_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_CM1_DBG_REF_UDC_L(char v1, unsigned char v2);

void Set_EL1D_CM1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_CM1()	(EL1D_CM1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_M()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_L()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_H()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_M()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_L()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_M()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_DBG_H()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_DBG_M()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_DBG_L()	(ChkL1ModFltr_EL1D_CM1()&&((EL1D_CM1_Trace_Filter[2]&0x08)!=0))
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_GROUPING_START_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_UPDATE_GROUPING_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_BACK_UP_CT_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_CONFIG_MPC_INFO_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_CONFIG_MPC_CELL_LIST_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_SET_SCC_DL_FREQ_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_CELL_INFO_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_NEW_GROUP_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_SELECT_T_FIRST_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_COFFT_GROUP_SPLIT_DIFF_JUDGE_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FEICIC_CM_RSTR_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_FEICIC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_CM_START_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_CM_BUF_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_RPT_INFO_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_RPT_INFO_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_RPT_CELL_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_CC_CHANGE_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_CMD_PRE_PROCESS_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_RX_CC_INFO_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_CM_RSTR_PCELL_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_RX_PATH_IN_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SRV_RX_PATH_OUT_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_SRV_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_IRQ_TRIG_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_RPT_ABORT_VALID_SET_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_RPT_ABORT_VALID_READ_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_1_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_2_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_COMMON_SET_3_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_RPT_INFO_SET_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_SRV_INFO_SET_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_1_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_2_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_3_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_4_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_GRP_INFO_SET_5_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_5MS_CMD_NBR_CELL_INFO_SET_1_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_1MS_CMD_COMMON_SET_1_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_1MS_CMD_DUMP_SET_1_M()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_M()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_1MS_CMD_WINSTART_SET_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_RPT_ABORT_READ_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_RPT_INFO_READ_1_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_RPT_ALL_INFO_1_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_CSIF_RPT_ALL_INFO_2_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_DCTG_CONFIG1_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_DCTG_CONFIG2_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_DCTG_CONFIG3_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_STIRQ_TRIG_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM1_LITE_ACI_SOL_CHG1_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_LITE_ACI_SOL_CHG2_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_CSIF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_DBG_TDB_DUMP_INJECT_STRING_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_DBG_FEICIC_ON_OFF_INJECT_STRING_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_TO_DBG_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SPV_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_SPV_CM_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_FORCE_MAN_ZERO_H()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CM1_DBG_REF_UDC_L()	ChkL1ClsFltr_EL1D_CM1_EL1D_TRC_CM1_DBG_L()


#endif
