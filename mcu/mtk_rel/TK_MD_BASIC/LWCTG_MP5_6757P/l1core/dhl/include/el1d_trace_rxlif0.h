#ifndef L1TRC_EL1D_RXLIF0_DEF_H
#define L1TRC_EL1D_RXLIF0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_RXLIF_FLAG(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_RXLIF_PRE_NCO_BW(v1)  (unsigned char)(v1+2)
#define EL1D_TRC_STR_RXLIF_POST_NCO_BW(v1)  (unsigned char)(v1+11)
#define EL1D_TRC_STR_RXLIF_PATH(v1)  (unsigned char)(v1+17)
#define EL1D_TRC_STR_RXLIF_NCO_PATH(v1)  (unsigned char)(v1+19)
#define EL1D_TRC_STR_RXLIF_ANTENNA(v1)  (unsigned char)(v1+22)
#define EL1D_TRC_STR_RXLIF_CC(v1)  (unsigned char)(v1+24)
#define EL1D_TRC_HANDLING_TYPE(v1)  (unsigned char)(v1+27)
#define EL1D_TRC_SOLUTION_TYPE(v1)  (unsigned char)(v1+33)
#define EL1D_TRC_ENTRY_POINT(v1)  (unsigned char)(v1+36)
#define EL1D_TRC_LITE_ACI_STATE(v1)  (unsigned char)(v1+39)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG_CONTEXT_ENTRY(v1) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0042, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG_CONTEXT_ENTRY(v1)
#endif
#define EL1D_TRC_RXLIF_DBG_CONTEXT_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0042, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG_D16_REG_DBG(v1, v2, v3, v4, v5) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0142, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG_D16_REG_DBG(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RXLIF_DBG_D16_REG_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0142, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG_D32_REG_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0242, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG_D32_REG_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RXLIF_DBG_D32_REG_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0242, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG1(v1, v2) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0342, (unsigned short)(v1)), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG1(v1, v2)
#endif
#define EL1D_TRC_RXLIF_DBG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0342, (unsigned short)(v1)), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG2(v1, v2, v3) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0442, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG2(v1, v2, v3)
#endif
#define EL1D_TRC_RXLIF_DBG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0442, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG3(v1, v2, v3, v4) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0542, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG3(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXLIF_DBG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0542, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG4(v1, v2, v3, v4, v5) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0642, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG4(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RXLIF_DBG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0642, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG5(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0742, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG5(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXLIF_DBG5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0742, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x0842, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RXLIF_DBG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x0842, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x0942, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RXLIF_DBG7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x0942, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A42, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RXLIF_DBG8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A42, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x0B42, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RXLIF_DBG9_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_2S(0x0B42, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HEX_DBG1(v1, v2) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C42, (unsigned short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HEX_DBG1(v1, v2)
#endif
#define EL1D_TRC_RXLIF_HEX_DBG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C42, (unsigned short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HEX_DBG2(v1, v2, v3) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D42, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HEX_DBG2(v1, v2, v3)
#endif
#define EL1D_TRC_RXLIF_HEX_DBG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D42, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HEX_DBG3(v1, v2, v3, v4) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E42, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HEX_DBG3(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXLIF_HEX_DBG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E42, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HEX_DBG4(v1, v2, v3, v4, v5) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F42, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HEX_DBG4(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RXLIF_HEX_DBG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F42, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HEX_DBG5(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1042, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HEX_DBG5(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXLIF_HEX_DBG5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1042, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HEX_DBG6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x1142, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HEX_DBG6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RXLIF_HEX_DBG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x1142, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HEX_DBG7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x1242, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HEX_DBG7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RXLIF_HEX_DBG7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x1242, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HEX_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1342, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HEX_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RXLIF_HEX_DBG8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1342, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HEX_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x1442, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HEX_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RXLIF_HEX_DBG9_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_2S(0x1442, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_INPUT_OF_ENTRY_FUNC6(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1542, (unsigned char)(v5), (unsigned char)(v6)), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_INPUT_OF_ENTRY_FUNC6(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXLIF_INPUT_OF_ENTRY_FUNC6_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1542, (unsigned char)(v5), (unsigned char)(v6)), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_OUTPUT_OF_ENTRY_FUNC6(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1642, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_OUTPUT_OF_ENTRY_FUNC6(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXLIF_OUTPUT_OF_ENTRY_FUNC6_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1642, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_INPUT_OF_SOLUTION_DECISION7(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1742, (unsigned char)(v1), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_INPUT_OF_SOLUTION_DECISION7(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RXLIF_INPUT_OF_SOLUTION_DECISION7_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1742, (unsigned char)(v1), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_OUTPUT_OF_SOLUTION_DECISION7(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1842, (unsigned char)(v7), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_OUTPUT_OF_SOLUTION_DECISION7(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RXLIF_OUTPUT_OF_SOLUTION_DECISION7_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1842, (unsigned char)(v7), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_TABLE_INFO6(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1942, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_TABLE_INFO6(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXLIF_TABLE_INFO6_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1942, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_TDD_VCO3DIV3_SPECIAL_HANDELING6(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1A42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_TDD_VCO3DIV3_SPECIAL_HANDELING6(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXLIF_TDD_VCO3DIV3_SPECIAL_HANDELING6_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1A42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_THRESHOLD_AVG_INFO5(v1, v2, v3, v4, v5) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1B42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_THRESHOLD_AVG_INFO5(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RXLIF_THRESHOLD_AVG_INFO5_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1B42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_QUANTIZE_LIF_SOLUTION4(v1, v2, v3, v4) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1C42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_QUANTIZE_LIF_SOLUTION4(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXLIF_QUANTIZE_LIF_SOLUTION4_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1C42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HANDLING_TYPE3(v1, v2, v3) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1D42, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HANDLING_TYPE3(v1, v2, v3)
#endif
#define EL1D_TRC_RXLIF_HANDLING_TYPE3_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1D42, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_LITE_ACI_STATE1(v1) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E42, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_LITE_ACI_STATE1(v1)
#endif
#define EL1D_TRC_RXLIF_LITE_ACI_STATE1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E42, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_ZERO2(v1, v2) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1F42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_ZERO2(v1, v2)
#endif
#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_ZERO2_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1F42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_ONE5(v1, v2, v3, v4, v5) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x2042, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_ONE5(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_ONE5_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x2042, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_TWO4(v1, v2, v3, v4) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2142, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_TWO4(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_TWO4_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2142, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_THREE4(v1, v2, v3, v4) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2242, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_THREE4(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXLIF_LITE_ACI_CRITERION_THREE4_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2242, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_RX_ACI_DECISION4(v1, v2, v3, v4) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2342, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_RX_ACI_DECISION4(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXLIF_RX_ACI_DECISION4_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2342, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_RFD_QUERY_IF_LIF_SOLUTION_CHANGE1(v1) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2442, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_RFD_QUERY_IF_LIF_SOLUTION_CHANGE1(v1)
#endif
#define EL1D_TRC_RXLIF_RFD_QUERY_IF_LIF_SOLUTION_CHANGE1_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2442, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_RFD_CLEAR_IS_LIF_CHANGE2(v1, v2) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2542, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_RFD_CLEAR_IS_LIF_CHANGE2(v1, v2)
#endif
#define EL1D_TRC_RXLIF_RFD_CLEAR_IS_LIF_CHANGE2_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2542, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_INFORM_L1C_CHANGE_SOLUTION1(v1) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2642, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_INFORM_L1C_CHANGE_SOLUTION1(v1)
#endif
#define EL1D_TRC_RXLIF_INFORM_L1C_CHANGE_SOLUTION1_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2642, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_LITE_ACI_PARAMS_RESET0() do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2742, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_LITE_ACI_PARAMS_RESET0()
#endif
#define EL1D_TRC_RXLIF_LITE_ACI_PARAMS_RESET0_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2742, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_LITE_ACI_RESET_L1C_RPT_FLAG0() do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2842, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_LITE_ACI_RESET_L1C_RPT_FLAG0()
#endif
#define EL1D_TRC_RXLIF_LITE_ACI_RESET_L1C_RPT_FLAG0_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2842, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_TX_OFFSET_ADJUSTMENT6(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2942, (unsigned char)(v1), (unsigned char)(v4)), (long)(v2), (long)(v3), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_TX_OFFSET_ADJUSTMENT6(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXLIF_TX_OFFSET_ADJUSTMENT6_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2942, (unsigned char)(v1), (unsigned char)(v4)), (long)(v2), (long)(v3), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_INFORM_SMALL_GAP_SPECIAL_CA2(v1, v2) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2A42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_INFORM_SMALL_GAP_SPECIAL_CA2(v1, v2)
#endif
#define EL1D_TRC_RXLIF_INFORM_SMALL_GAP_SPECIAL_CA2_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2A42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_HANDLE_LO_SPUR_AT_DC3(v1, v2, v3) do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B42, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_HANDLE_LO_SPUR_AT_DC3(v1, v2, v3)
#endif
#define EL1D_TRC_RXLIF_HANDLE_LO_SPUR_AT_DC3_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B42, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_LIF_PARAMS_INIT0() do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_LIF_PARAMS_INIT0()
#endif
#define EL1D_TRC_RXLIF_LIF_PARAMS_INIT0_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXLIF_LIF_INJECT_SUCCESS0() do {\
		if(EL1D_RXLIF0_Trace_Filter[0]==1 && (EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_LIF_INJECT_SUCCESS0()
#endif
#define EL1D_TRC_RXLIF_LIF_INJECT_SUCCESS0_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D42, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_RXLIF0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_RXLIF_DBG_CONTEXT_ENTRY(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG_D16_REG_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG_D32_REG_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG1(unsigned short v1, long v2);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG2(unsigned short v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG3(unsigned short v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG4(unsigned short v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG5(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG6(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG7(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG8(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9);
void L1TRC_Send_EL1D_TRC_RXLIF_DBG9(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10);
void L1TRC_Send_EL1D_TRC_RXLIF_HEX_DBG1(unsigned short v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RXLIF_HEX_DBG2(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RXLIF_HEX_DBG3(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RXLIF_HEX_DBG4(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RXLIF_HEX_DBG5(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RXLIF_HEX_DBG6(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_RXLIF_HEX_DBG7(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_RXLIF_HEX_DBG8(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1D_TRC_RXLIF_HEX_DBG9(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1D_TRC_RXLIF_INPUT_OF_ENTRY_FUNC6(long v1, long v2, long v3, long v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RXLIF_OUTPUT_OF_ENTRY_FUNC6(long v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_RXLIF_INPUT_OF_SOLUTION_DECISION7(unsigned char v1, long v2, long v3, long v4, long v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_RXLIF_OUTPUT_OF_SOLUTION_DECISION7(long v1, long v2, long v3, long v4, long v5, long v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_RXLIF_TABLE_INFO6(long v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_RXLIF_TDD_VCO3DIV3_SPECIAL_HANDELING6(long v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_RXLIF_THRESHOLD_AVG_INFO5(long v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RXLIF_QUANTIZE_LIF_SOLUTION4(long v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RXLIF_HANDLING_TYPE3(unsigned char v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_RXLIF_LITE_ACI_STATE1(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RXLIF_LITE_ACI_CRITERION_ZERO2(long v1, long v2);
void L1TRC_Send_EL1D_TRC_RXLIF_LITE_ACI_CRITERION_ONE5(long v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RXLIF_LITE_ACI_CRITERION_TWO4(long v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RXLIF_LITE_ACI_CRITERION_THREE4(long v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RXLIF_RX_ACI_DECISION4(unsigned char v1, unsigned char v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RXLIF_RFD_QUERY_IF_LIF_SOLUTION_CHANGE1(long v1);
void L1TRC_Send_EL1D_TRC_RXLIF_RFD_CLEAR_IS_LIF_CHANGE2(long v1, long v2);
void L1TRC_Send_EL1D_TRC_RXLIF_INFORM_L1C_CHANGE_SOLUTION1(long v1);
void L1TRC_Send_EL1D_TRC_RXLIF_LITE_ACI_PARAMS_RESET0(void);
void L1TRC_Send_EL1D_TRC_RXLIF_LITE_ACI_RESET_L1C_RPT_FLAG0(void);
void L1TRC_Send_EL1D_TRC_RXLIF_TX_OFFSET_ADJUSTMENT6(unsigned char v1, long v2, long v3, unsigned char v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_RXLIF_INFORM_SMALL_GAP_SPECIAL_CA2(long v1, long v2);
void L1TRC_Send_EL1D_TRC_RXLIF_HANDLE_LO_SPUR_AT_DC3(unsigned char v1, unsigned char v2, long v3);
void L1TRC_Send_EL1D_TRC_RXLIF_LIF_PARAMS_INIT0(void);
void L1TRC_Send_EL1D_TRC_RXLIF_LIF_INJECT_SUCCESS0(void);

void Set_EL1D_RXLIF0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_RXLIF0()	(EL1D_RXLIF0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()	(ChkL1ModFltr_EL1D_RXLIF0()&&((EL1D_RXLIF0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_M()	(ChkL1ModFltr_EL1D_RXLIF0()&&((EL1D_RXLIF0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_L()	(ChkL1ModFltr_EL1D_RXLIF0()&&((EL1D_RXLIF0_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG_CONTEXT_ENTRY()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG_D16_REG_DBG()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG_D32_REG_DBG()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG1()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG2()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG3()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG4()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG5()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG6()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG7()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG8()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_DBG9()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HEX_DBG1()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HEX_DBG2()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HEX_DBG3()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HEX_DBG4()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HEX_DBG5()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HEX_DBG6()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HEX_DBG7()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HEX_DBG8()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HEX_DBG9()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_INPUT_OF_ENTRY_FUNC6()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_OUTPUT_OF_ENTRY_FUNC6()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_INPUT_OF_SOLUTION_DECISION7()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_OUTPUT_OF_SOLUTION_DECISION7()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_TABLE_INFO6()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_TDD_VCO3DIV3_SPECIAL_HANDELING6()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_THRESHOLD_AVG_INFO5()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_QUANTIZE_LIF_SOLUTION4()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HANDLING_TYPE3()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_LITE_ACI_STATE1()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_LITE_ACI_CRITERION_ZERO2()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_LITE_ACI_CRITERION_ONE5()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_LITE_ACI_CRITERION_TWO4()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_LITE_ACI_CRITERION_THREE4()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_RX_ACI_DECISION4()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_RFD_QUERY_IF_LIF_SOLUTION_CHANGE1()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_RFD_CLEAR_IS_LIF_CHANGE2()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_INFORM_L1C_CHANGE_SOLUTION1()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_LITE_ACI_PARAMS_RESET0()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_LITE_ACI_RESET_L1C_RPT_FLAG0()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_TX_OFFSET_ADJUSTMENT6()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_INFORM_SMALL_GAP_SPECIAL_CA2()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_HANDLE_LO_SPUR_AT_DC3()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_LIF_PARAMS_INIT0()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_LIF_INJECT_SUCCESS0()	ChkL1ClsFltr_EL1D_RXLIF0_EL1D_TRC_CLS_RXLIF_H()


#endif
