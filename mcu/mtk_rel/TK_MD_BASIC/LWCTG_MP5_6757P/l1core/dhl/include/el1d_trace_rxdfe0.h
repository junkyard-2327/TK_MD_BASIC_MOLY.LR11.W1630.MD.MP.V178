#ifndef L1TRC_EL1D_RXDFE0_DEF_H
#define L1TRC_EL1D_RXDFE0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_RXDFE_FLAG(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_RXDFE_PRE_NCO_BW(v1)  (unsigned char)(v1+2)
#define EL1D_TRC_STR_RXDFE_POST_NCO_BW(v1)  (unsigned char)(v1+11)
#define EL1D_TRC_STR_RXDFE_PATH(v1)  (unsigned char)(v1+17)
#define EL1D_TRC_STR_RXDFE_NCO_PATH(v1)  (unsigned char)(v1+19)
#define EL1D_TRC_STR_RXDFE_ANTENNA(v1)  (unsigned char)(v1+22)
#define EL1D_TRC_STR_AFC_TYPE(v1)  (unsigned char)(v1+24)
#define EL1D_TRC_WIN_ON_OFF_TYPE(v1)  (unsigned char)(v1+26)
#define EL1D_TRC_RXDFE_ALPHA_TYPE(v1)  (unsigned char)(v1+28)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG_CONTEXT_ENTRY(v1) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0040, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_CONTEXT_ENTRY(v1)
#endif
#define EL1D_TRC_RXDFE_DBG_CONTEXT_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0040, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG_D16_REG_DBG(v1, v2, v3, v4, v5) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0140, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_D16_REG_DBG(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RXDFE_DBG_D16_REG_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0140, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG_D32_REG_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0240, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_D32_REG_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RXDFE_DBG_D32_REG_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0240, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG1(v1, v2) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0340, (unsigned short)(v1)), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG1(v1, v2)
#endif
#define EL1D_TRC_RXDFE_DBG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0340, (unsigned short)(v1)), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG2(v1, v2, v3) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0440, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG2(v1, v2, v3)
#endif
#define EL1D_TRC_RXDFE_DBG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0440, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG3(v1, v2, v3, v4) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0540, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG3(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXDFE_DBG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0540, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG4(v1, v2, v3, v4, v5) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0640, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG4(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RXDFE_DBG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0640, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG5(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0740, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG5(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXDFE_DBG5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0740, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x0840, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RXDFE_DBG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x0840, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x0940, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RXDFE_DBG7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x0940, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A40, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RXDFE_DBG8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A40, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x0B40, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RXDFE_DBG9_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_2S(0x0B40, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_HEX_DBG1(v1, v2) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C40, (unsigned short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_HEX_DBG1(v1, v2)
#endif
#define EL1D_TRC_RXDFE_HEX_DBG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C40, (unsigned short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_HEX_DBG2(v1, v2, v3) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D40, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_HEX_DBG2(v1, v2, v3)
#endif
#define EL1D_TRC_RXDFE_HEX_DBG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D40, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_HEX_DBG3(v1, v2, v3, v4) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E40, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_HEX_DBG3(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXDFE_HEX_DBG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E40, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_HEX_DBG4(v1, v2, v3, v4, v5) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F40, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_HEX_DBG4(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RXDFE_HEX_DBG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F40, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_HEX_DBG5(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1040, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_HEX_DBG5(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXDFE_HEX_DBG5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1040, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_HEX_DBG6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x1140, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_HEX_DBG6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RXDFE_HEX_DBG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x1140, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_HEX_DBG7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x1240, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_HEX_DBG7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RXDFE_HEX_DBG7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x1240, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_HEX_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1340, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_HEX_DBG8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RXDFE_HEX_DBG8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1340, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_HEX_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x1440, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_HEX_DBG9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RXDFE_HEX_DBG9_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_2S(0x1440, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG_CHECKSUM_ALPHA_4(v1, v2, v3, v4) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1540, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_CHECKSUM_ALPHA_4(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXDFE_DBG_CHECKSUM_ALPHA_4_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1540, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_DBG_CHECKSUM_ALPHA_TYPE(v1) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1640, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_CHECKSUM_ALPHA_TYPE(v1)
#endif
#define EL1D_TRC_RXDFE_DBG_CHECKSUM_ALPHA_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1640, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_WIN_ON_OFF_5(v1, v2, v3, v4, v5) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1740, (unsigned char)(v3), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_WIN_ON_OFF_5(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RXDFE_WIN_ON_OFF_5_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1740, (unsigned char)(v3), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_WINDOW_STATUS(v1, v2, v3) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1840, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_WINDOW_STATUS(v1, v2, v3)
#endif
#define EL1D_TRC_RXDFE_WINDOW_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1840, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_FEC_GET_DFE_INFO10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x1940, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_FEC_GET_DFE_INFO10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RXDFE_FEC_GET_DFE_INFO10_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x1940, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_NCO_STATUS(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1A40, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_NCO_STATUS(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXDFE_NCO_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1A40, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_DBG_NBIF_PARAMS6(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1B40, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_NBIF_PARAMS6(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXDFE_DBG_NBIF_PARAMS6_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1B40, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_DBG_PATH_ON4(v1, v2, v3, v4) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1C40, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_PATH_ON4(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXDFE_DBG_PATH_ON4_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1C40, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_DBG_PATH_ON_NBIF4(v1, v2, v3, v4) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1D40, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_PATH_ON_NBIF4(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXDFE_DBG_PATH_ON_NBIF4_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1D40, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_DBG_NBI_UPDATE_COEF0() do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E40, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_NBI_UPDATE_COEF0()
#endif
#define EL1D_TRC_RXDFE_DBG_NBI_UPDATE_COEF0_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E40, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_SET_LITE_ACI_WB_COEF2(v1, v2) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1F40, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_SET_LITE_ACI_WB_COEF2(v1, v2)
#endif
#define EL1D_TRC_RXDFE_SET_LITE_ACI_WB_COEF2_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1F40, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_RESET_LITE_ACI_WB_COEF2(v1, v2) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2040, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_RESET_LITE_ACI_WB_COEF2(v1, v2)
#endif
#define EL1D_TRC_RXDFE_RESET_LITE_ACI_WB_COEF2_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2040, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_DBG_FDPM6(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2140, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_FDPM6(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXDFE_DBG_FDPM6_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2140, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_DBG_IQC6(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2240, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_IQC6(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RXDFE_DBG_IQC6_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2240, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_DBG_CARRIER_MAP(v1, v2) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2340, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_DBG_CARRIER_MAP(v1, v2)
#endif
#define EL1D_TRC_RXDFE_DBG_CARRIER_MAP_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2340, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_FC_CONFIG_SET_BMP(v1) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2440, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_FC_CONFIG_SET_BMP(v1)
#endif
#define EL1D_TRC_RXDFE_FC_CONFIG_SET_BMP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2440, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDFE_FC_DLY8(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2540, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_FC_DLY8(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RXDFE_FC_DLY8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2540, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDFE_MU_BW_DIFF(v1, v2, v3) do {\
		if(EL1D_RXDFE0_Trace_Filter[0]==1 && (EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2640, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RXDFE_MU_BW_DIFF(v1, v2, v3)
#endif
#define EL1D_TRC_RXDFE_MU_BW_DIFF_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2640, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_RXDFE0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_RXDFE_DBG_CONTEXT_ENTRY(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_D16_REG_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_D32_REG_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG1(unsigned short v1, long v2);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG2(unsigned short v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG3(unsigned short v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG4(unsigned short v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG5(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG6(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG7(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG8(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG9(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10);
void L1TRC_Send_EL1D_TRC_RXDFE_HEX_DBG1(unsigned short v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RXDFE_HEX_DBG2(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RXDFE_HEX_DBG3(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RXDFE_HEX_DBG4(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RXDFE_HEX_DBG5(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RXDFE_HEX_DBG6(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_RXDFE_HEX_DBG7(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_RXDFE_HEX_DBG8(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1D_TRC_RXDFE_HEX_DBG9(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_CHECKSUM_ALPHA_4(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_CHECKSUM_ALPHA_TYPE(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RXDFE_WIN_ON_OFF_5(long v1, long v2, unsigned char v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RXDFE_WINDOW_STATUS(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RXDFE_FEC_GET_DFE_INFO10(long v1, long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1D_TRC_RXDFE_NCO_STATUS(unsigned char v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_NBIF_PARAMS6(long v1, long v2, long v3, long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_PATH_ON4(long v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_PATH_ON_NBIF4(long v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_NBI_UPDATE_COEF0(void);
void L1TRC_Send_EL1D_TRC_RXDFE_SET_LITE_ACI_WB_COEF2(long v1, long v2);
void L1TRC_Send_EL1D_TRC_RXDFE_RESET_LITE_ACI_WB_COEF2(long v1, long v2);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_FDPM6(long v1, long v2, long v3, long v4, long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_IQC6(long v1, long v2, long v3, long v4, long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RXDFE_DBG_CARRIER_MAP(char v1, char v2);
void L1TRC_Send_EL1D_TRC_RXDFE_FC_CONFIG_SET_BMP(short v1);
void L1TRC_Send_EL1D_TRC_RXDFE_FC_DLY8(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_EL1D_TRC_RXDFE_MU_BW_DIFF(long v1, long v2, long v3);

void Set_EL1D_RXDFE0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_RXDFE0()	(EL1D_RXDFE0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()	(ChkL1ModFltr_EL1D_RXDFE0()&&((EL1D_RXDFE0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_M()	(ChkL1ModFltr_EL1D_RXDFE0()&&((EL1D_RXDFE0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()	(ChkL1ModFltr_EL1D_RXDFE0()&&((EL1D_RXDFE0_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_CONTEXT_ENTRY()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_D16_REG_DBG()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_D32_REG_DBG()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG1()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG2()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG3()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG4()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG5()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG6()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG7()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG8()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG9()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_HEX_DBG1()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_HEX_DBG2()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_HEX_DBG3()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_HEX_DBG4()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_HEX_DBG5()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_HEX_DBG6()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_HEX_DBG7()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_HEX_DBG8()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_HEX_DBG9()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_CHECKSUM_ALPHA_4()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_CHECKSUM_ALPHA_TYPE()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_WIN_ON_OFF_5()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_WINDOW_STATUS()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_FEC_GET_DFE_INFO10()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_NCO_STATUS()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_NBIF_PARAMS6()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_PATH_ON4()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_PATH_ON_NBIF4()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_NBI_UPDATE_COEF0()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_SET_LITE_ACI_WB_COEF2()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_RESET_LITE_ACI_WB_COEF2()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_FDPM6()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_IQC6()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_DBG_CARRIER_MAP()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_FC_CONFIG_SET_BMP()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_FC_DLY8()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDFE_MU_BW_DIFF()	ChkL1ClsFltr_EL1D_RXDFE0_EL1D_TRC_CLS_RXDFE_H()


#endif
