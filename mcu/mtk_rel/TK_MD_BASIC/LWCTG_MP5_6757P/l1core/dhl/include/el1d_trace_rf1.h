#ifndef L1TRC_EL1D_RF1_DEF_H
#define L1TRC_EL1D_RF1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_RF_DBG_FLAG(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_RF_DBG_HEX(v1)  (unsigned char)(v1+2)
#define EL1TST_TRC_STR_COMMAND_TYPE(v1)  (unsigned char)(v1+18)
#define EL1TST_TRC_STR_RESULT(v1)  (unsigned char)(v1+27)
#define EL1TST_TRC_STR_ROUTE_TYPE(v1)  (unsigned char)(v1+37)
#define EL1TST_TRC_STR_FT_MSG_TYPE(v1)  (unsigned char)(v1+42)
#define EL1TST_TRC_STR_L1D_API(v1)  (unsigned char)(v1+97)
#define EL1TST_TRC_STR_TST_API(v1)  (unsigned char)(v1+116)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG_CONTEXT_ENTRY(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0038, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG_CONTEXT_ENTRY(v1)
#endif
#define EL1D_TRC_RF_DBG_CONTEXT_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0038, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG_D16_REG_DBG(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0138, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG_D16_REG_DBG(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RF_DBG_D16_REG_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0138, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG_D32_REG_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0238, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG_D32_REG_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RF_DBG_D32_REG_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0238, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG1(v1, v2) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0338, (unsigned short)(v1)), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG1(v1, v2)
#endif
#define EL1D_TRC_RF_DBG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0338, (unsigned short)(v1)), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG2(v1, v2, v3) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0438, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG2(v1, v2, v3)
#endif
#define EL1D_TRC_RF_DBG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0438, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG3(v1, v2, v3, v4) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0538, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG3(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_DBG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0538, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG4(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0638, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG4(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RF_DBG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0638, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG5(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0738, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG5(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RF_DBG5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0738, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x0838, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RF_DBG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x0838, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x0938, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RF_DBG7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x0938, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A38, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RF_DBG8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A38, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x0B38, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RF_DBG9_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_2S(0x0B38, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_HEX_DBG1(v1, v2) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C38, (unsigned short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RF_HEX_DBG1(v1, v2)
#endif
#define EL1D_TRC_RF_HEX_DBG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C38, (unsigned short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_HEX_DBG2(v1, v2, v3) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D38, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RF_HEX_DBG2(v1, v2, v3)
#endif
#define EL1D_TRC_RF_HEX_DBG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D38, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_HEX_DBG3(v1, v2, v3, v4) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E38, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RF_HEX_DBG3(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_HEX_DBG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E38, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_HEX_DBG4(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F38, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RF_HEX_DBG4(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RF_HEX_DBG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F38, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_HEX_DBG5(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1038, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RF_HEX_DBG5(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RF_HEX_DBG5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1038, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_HEX_DBG6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x1138, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RF_HEX_DBG6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RF_HEX_DBG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x1138, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_HEX_DBG7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x1238, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RF_HEX_DBG7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RF_HEX_DBG7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x1238, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_HEX_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1338, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RF_HEX_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RF_HEX_DBG8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1338, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_HEX_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x1438, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_RF_HEX_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RF_HEX_DBG9_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_2S(0x1438, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG_BSI_CW_REPEAT(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1538, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG_BSI_CW_REPEAT(v1)
#endif
#define EL1D_TRC_RF_DBG_BSI_CW_REPEAT_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1538, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DBG_BSI_L_DATA_READ(v1, v2) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1638, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RF_DBG_BSI_L_DATA_READ(v1, v2)
#endif
#define EL1D_TRC_RF_DBG_BSI_L_DATA_READ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1638, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_EL1TST_ETSTM_MSG_TYPE(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1738, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TST_TRC_EL1TST_ETSTM_MSG_TYPE(v1)
#endif
#define EL1TST_TRC_EL1TST_ETSTM_MSG_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1738, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_FT_EL1TST_MSG_TYPE(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1838, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TST_TRC_FT_EL1TST_MSG_TYPE(v1)
#endif
#define EL1TST_TRC_FT_EL1TST_MSG_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1838, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_HISR_MSG_TYPE(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1938, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TST_TRC_HISR_MSG_TYPE(v1)
#endif
#define EL1TST_TRC_HISR_MSG_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1938, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_CMD_TYPE(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A38, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TST_TRC_CMD_TYPE(v1)
#endif
#define EL1TST_TRC_CMD_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A38, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_RXROUTE_TYPE(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B38, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TST_TRC_RXROUTE_TYPE(v1)
#endif
#define EL1TST_TRC_RXROUTE_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B38, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_CDQ_IDX_CNT_INFO(v1, v2, v3, v4) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TST_TRC_CDQ_IDX_CNT_INFO(v1, v2, v3, v4)
#endif
#define EL1TST_TRC_CDQ_IDX_CNT_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_API_START(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D38, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_API_START(v1)
#endif
#define EL1TST_TRC_L1D_API_START_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D38, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_API_END(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E38, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_API_END(v1)
#endif
#define EL1TST_TRC_L1D_API_END_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E38, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_TST_API_START(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F38, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TST_TRC_TST_API_START(v1)
#endif
#define EL1TST_TRC_TST_API_START_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F38, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_TST_API_END(v1) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2038, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TST_TRC_TST_API_END(v1)
#endif
#define EL1TST_TRC_TST_API_END_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2038, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_DBG1(v1, v2) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2138, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_DBG1(v1, v2)
#endif
#define EL1TST_TRC_L1D_DBG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2138, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_DBG2(v1, v2, v3) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2238, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_DBG2(v1, v2, v3)
#endif
#define EL1TST_TRC_L1D_DBG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2238, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_DBG3(v1, v2, v3, v4) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2338, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_DBG3(v1, v2, v3, v4)
#endif
#define EL1TST_TRC_L1D_DBG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2338, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_DBG4(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2438, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_DBG4(v1, v2, v3, v4, v5)
#endif
#define EL1TST_TRC_L1D_DBG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2438, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_DBG5(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x2538, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_DBG5(v1, v2, v3, v4, v5, v6)
#endif
#define EL1TST_TRC_L1D_DBG5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x2538, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_DBG6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2638, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_DBG6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1TST_TRC_L1D_DBG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2638, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_DBG7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x2738, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_DBG7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1TST_TRC_L1D_DBG7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x2738, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2838, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1TST_TRC_L1D_DBG8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2838, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9))

#if defined(L1_CATCHER)
	#define EL1TST_TRC_L1D_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RF1_Trace_Filter[0]==1 && (EL1D_RF1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x2938, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10));\
	} while(0)
#else
	#define EL1TST_TRC_L1D_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1TST_TRC_L1D_DBG9_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x2938, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_RF1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_RF_DBG_CONTEXT_ENTRY(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RF_DBG_D16_REG_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RF_DBG_D32_REG_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_EL1D_TRC_RF_DBG1(unsigned short v1, long v2);
void L1TRC_Send_EL1D_TRC_RF_DBG2(unsigned short v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_RF_DBG3(unsigned short v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RF_DBG4(unsigned short v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RF_DBG5(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_RF_DBG6(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_EL1D_TRC_RF_DBG7(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_EL1D_TRC_RF_DBG8(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9);
void L1TRC_Send_EL1D_TRC_RF_DBG9(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10);
void L1TRC_Send_EL1D_TRC_RF_HEX_DBG1(unsigned short v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RF_HEX_DBG2(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RF_HEX_DBG3(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RF_HEX_DBG4(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RF_HEX_DBG5(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RF_HEX_DBG6(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_RF_HEX_DBG7(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_RF_HEX_DBG8(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1D_TRC_RF_HEX_DBG9(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1D_TRC_RF_DBG_BSI_CW_REPEAT(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RF_DBG_BSI_L_DATA_READ(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1TST_TRC_EL1TST_ETSTM_MSG_TYPE(unsigned char v1);
void L1TRC_Send_EL1TST_TRC_FT_EL1TST_MSG_TYPE(unsigned char v1);
void L1TRC_Send_EL1TST_TRC_HISR_MSG_TYPE(unsigned char v1);
void L1TRC_Send_EL1TST_TRC_CMD_TYPE(unsigned char v1);
void L1TRC_Send_EL1TST_TRC_RXROUTE_TYPE(unsigned char v1);
void L1TRC_Send_EL1TST_TRC_CDQ_IDX_CNT_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1TST_TRC_L1D_API_START(unsigned char v1);
void L1TRC_Send_EL1TST_TRC_L1D_API_END(unsigned char v1);
void L1TRC_Send_EL1TST_TRC_TST_API_START(unsigned char v1);
void L1TRC_Send_EL1TST_TRC_TST_API_END(unsigned char v1);
void L1TRC_Send_EL1TST_TRC_L1D_DBG1(unsigned char v1, long v2);
void L1TRC_Send_EL1TST_TRC_L1D_DBG2(unsigned char v1, long v2, long v3);
void L1TRC_Send_EL1TST_TRC_L1D_DBG3(unsigned char v1, long v2, long v3, long v4);
void L1TRC_Send_EL1TST_TRC_L1D_DBG4(unsigned char v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1TST_TRC_L1D_DBG5(unsigned char v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1TST_TRC_L1D_DBG6(unsigned char v1, long v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_EL1TST_TRC_L1D_DBG7(unsigned char v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_EL1TST_TRC_L1D_DBG8(unsigned char v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9);
void L1TRC_Send_EL1TST_TRC_L1D_DBG9(unsigned char v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10);

void Set_EL1D_RF1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_RF1()	(EL1D_RF1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()	(ChkL1ModFltr_EL1D_RF1()&&((EL1D_RF1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_L()	(ChkL1ModFltr_EL1D_RF1()&&((EL1D_RF1_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG_CONTEXT_ENTRY()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG_D16_REG_DBG()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG_D32_REG_DBG()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG1()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG2()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG3()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG4()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG5()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG6()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG7()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG8()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG9()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_HEX_DBG1()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_HEX_DBG2()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_HEX_DBG3()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_HEX_DBG4()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_HEX_DBG5()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_HEX_DBG6()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_HEX_DBG7()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_HEX_DBG8()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_HEX_DBG9()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG_BSI_CW_REPEAT()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DBG_BSI_L_DATA_READ()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_EL1TST_ETSTM_MSG_TYPE()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_FT_EL1TST_MSG_TYPE()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_HISR_MSG_TYPE()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_CMD_TYPE()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_RXROUTE_TYPE()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_CDQ_IDX_CNT_INFO()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_API_START()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_API_END()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_TST_API_START()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_TST_API_END()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_DBG1()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_DBG2()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_DBG3()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_DBG4()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_DBG5()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_DBG6()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_DBG7()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_DBG8()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()
#define ChkL1MsgFltr_EL1TST_TRC_L1D_DBG9()	ChkL1ClsFltr_EL1D_RF1_EL1D_TRC_CLS_RF_DBG_H()


#endif
