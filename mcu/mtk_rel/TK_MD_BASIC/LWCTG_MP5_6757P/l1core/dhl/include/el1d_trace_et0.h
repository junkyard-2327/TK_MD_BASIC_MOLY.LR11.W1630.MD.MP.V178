#ifndef L1TRC_EL1D_ET0_DEF_H
#define L1TRC_EL1D_ET0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_ET_DBG_MSG_TYPE(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG0(v1) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0044, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG0(v1)
#endif
#define EL1D_TRC_ET_DBG0_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0044, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG1(v1) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0144, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG1(v1)
#endif
#define EL1D_TRC_ET_DBG1_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0144, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG2(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0244, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG2(v1, v2, v3)
#endif
#define EL1D_TRC_ET_DBG2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0244, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG3(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0344, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG3(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_DBG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0344, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG4(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0444, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG4(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_DBG4_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0444, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG5(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0544, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG5(v1, v2, v3)
#endif
#define EL1D_TRC_ET_DBG5_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0544, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG12(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0644, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG12(v1, v2, v3)
#endif
#define EL1D_TRC_ET_DBG12_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0644, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG15(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0744, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG15(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_ET_DBG15_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0744, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG16(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0844, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG16(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_DBG16_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0844, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG17(v1, v2) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0944, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG17(v1, v2)
#endif
#define EL1D_TRC_ET_DBG17_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0944, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG18(v1, v2) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG18(v1, v2)
#endif
#define EL1D_TRC_ET_DBG18_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG19(v1) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG19(v1)
#endif
#define EL1D_TRC_ET_DBG19_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG20(v1, v2) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG20(v1, v2)
#endif
#define EL1D_TRC_ET_DBG20_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DBG21(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0D44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_ET_DBG21(v1, v2, v3)
#endif
#define EL1D_TRC_ET_DBG21_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0D44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FEC_TPC_TABLE_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FEC_TPC_TABLE_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FEC_TPC_TABLE_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FEC_EVENT_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FEC_EVENT_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FEC_EVENT_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FEC_TPC_DATA_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1044, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_ET_FEC_TPC_DATA_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FEC_TPC_DATA_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1044, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FEC_VPA_TABLE_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1144, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FEC_VPA_TABLE_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FEC_VPA_TABLE_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1144, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FEC_VPA_DATA_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1244, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_ET_FEC_VPA_DATA_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FEC_VPA_DATA_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1244, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FEC_BW_TABLE_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1344, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FEC_BW_TABLE_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FEC_BW_TABLE_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1344, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FEC_BW_DATA_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1444, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_ET_FEC_BW_DATA_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FEC_BW_DATA_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1444, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FEC_MODE_TABLE_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1544, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FEC_MODE_TABLE_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FEC_MODE_TABLE_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1544, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FEC_MODE_DATA_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1644, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_ET_FEC_MODE_DATA_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FEC_MODE_DATA_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1644, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_PA_VPA_CONF_INFO(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1744, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_PA_VPA_CONF_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_ET_FAC_PA_VPA_CONF_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1744, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_SUBBAND_COUNT_INFO(v1, v2) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1844, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_SUBBAND_COUNT_INFO(v1, v2)
#endif
#define EL1D_TRC_ET_FAC_SUBBAND_COUNT_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1844, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_BAND_WIDTH_INFO(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1944, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_BAND_WIDTH_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_ET_FAC_BAND_WIDTH_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1944, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_IMM_MIPI_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1A44, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_IMM_MIPI_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FAC_IMM_MIPI_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1A44, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_S2_A_B_CAL_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1B44, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_S2_A_B_CAL_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_ET_FAC_S2_A_B_CAL_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1B44, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_S2_REPEAT_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_S2_REPEAT_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FAC_S2_REPEAT_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DET_GAIN_INFO(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DET_GAIN_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FAC_DET_GAIN_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_S2_POST_DELAY_INFO(v1, v2, v3, v4, v5) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1E44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_S2_POST_DELAY_INFO(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_ET_FAC_S2_POST_DELAY_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1E44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG0(v1) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1F44, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG0(v1)
#endif
#define EL1D_TRC_ET_FAC_DBG0_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1F44, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG1(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2044, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG1(v1, v2, v3)
#endif
#define EL1D_TRC_ET_FAC_DBG1_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2044, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG2(v1, v2) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2144, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG2(v1, v2)
#endif
#define EL1D_TRC_ET_FAC_DBG2_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2144, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG3(v1, v2) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2244, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG3(v1, v2)
#endif
#define EL1D_TRC_ET_FAC_DBG3_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2244, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG4(v1, v2) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2344, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG4(v1, v2)
#endif
#define EL1D_TRC_ET_FAC_DBG4_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2344, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG5(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2444, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG5(v1, v2, v3)
#endif
#define EL1D_TRC_ET_FAC_DBG5_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2444, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG6(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2544, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG6(v1, v2, v3)
#endif
#define EL1D_TRC_ET_FAC_DBG6_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2544, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG7(v1) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2644, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG7(v1)
#endif
#define EL1D_TRC_ET_FAC_DBG7_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2644, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG8(v1, v2) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2744, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG8(v1, v2)
#endif
#define EL1D_TRC_ET_FAC_DBG8_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2744, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG9(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2844, (short)(v3)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG9(v1, v2, v3)
#endif
#define EL1D_TRC_ET_FAC_DBG9_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2844, (short)(v3)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG10(v1, v2, v3, v4, v5) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2944, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG10(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_ET_FAC_DBG10_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2944, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG11(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG11(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_FAC_DBG11_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG12(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG12(v1, v2, v3)
#endif
#define EL1D_TRC_ET_FAC_DBG12_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG13(v1, v2) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2C44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG13(v1, v2)
#endif
#define EL1D_TRC_ET_FAC_DBG13_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2C44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_FAC_DBG14(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2D44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_ET_FAC_DBG14(v1, v2, v3)
#endif
#define EL1D_TRC_ET_FAC_DBG14_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2D44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_OTFC_DBG0(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_ET_OTFC_DBG0(v1, v2, v3)
#endif
#define EL1D_TRC_ET_OTFC_DBG0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E44, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_OTFC_DBG1(v1) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2F44, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_ET_OTFC_DBG1(v1)
#endif
#define EL1D_TRC_ET_OTFC_DBG1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2F44, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_OTFC_DBG2(v1) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3044, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_ET_OTFC_DBG2(v1)
#endif
#define EL1D_TRC_ET_OTFC_DBG2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3044, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_OTFC_DBG3(v1) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3144, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_ET_OTFC_DBG3(v1)
#endif
#define EL1D_TRC_ET_OTFC_DBG3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3144, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_OTFC_DBG4(v1) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3244, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_ET_OTFC_DBG4(v1)
#endif
#define EL1D_TRC_ET_OTFC_DBG4_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3244, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_OTFC_DBG5(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3344, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_ET_OTFC_DBG5(v1, v2, v3)
#endif
#define EL1D_TRC_ET_OTFC_DBG5_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3344, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_OTFC_DBG6(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x3444, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_ET_OTFC_DBG6(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_ET_OTFC_DBG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x3444, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_OTFC_DBG7(v1, v2, v3, v4, v5) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3544, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_ET_OTFC_DBG7(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_ET_OTFC_DBG7_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3544, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_OTFC_DBG8(v1, v2, v3, v4) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3644, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_ET_OTFC_DBG8(v1, v2, v3, v4)
#endif
#define EL1D_TRC_ET_OTFC_DBG8_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3644, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_OTFC_DBG9(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3744, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_ET_OTFC_DBG9(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_ET_OTFC_DBG9_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3744, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_META_PATH_DELAY(v1, v2, v3, v4, v5) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3844, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_ET_META_PATH_DELAY(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_ET_META_PATH_DELAY_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3844, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DRV_EVENT_INFO(v1, v2, v3) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3944, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_ET_DRV_EVENT_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_ET_DRV_EVENT_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3944, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ET_DRV_STATUS_INFO(v1) do {\
		if(EL1D_ET0_Trace_Filter[0]==1 && (EL1D_ET0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_ET_DRV_STATUS_INFO(v1)
#endif
#define EL1D_TRC_ET_DRV_STATUS_INFO_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A44, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_ET0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_ET_DBG0(short v1);
void L1TRC_Send_EL1D_TRC_ET_DBG1(unsigned long v1);
void L1TRC_Send_EL1D_TRC_ET_DBG2(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_ET_DBG3(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_ET_DBG4(short v1, short v2, long v3, short v4);
void L1TRC_Send_EL1D_TRC_ET_DBG5(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_ET_DBG12(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_ET_DBG15(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_EL1D_TRC_ET_DBG16(long v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_ET_DBG17(long v1, long v2);
void L1TRC_Send_EL1D_TRC_ET_DBG18(long v1, long v2);
void L1TRC_Send_EL1D_TRC_ET_DBG19(long v1);
void L1TRC_Send_EL1D_TRC_ET_DBG20(long v1, long v2);
void L1TRC_Send_EL1D_TRC_ET_DBG21(long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_ET_FEC_TPC_TABLE_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_ET_FEC_EVENT_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_ET_FEC_TPC_DATA_INFO(short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_ET_FEC_VPA_TABLE_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_ET_FEC_VPA_DATA_INFO(short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_ET_FEC_BW_TABLE_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_ET_FEC_BW_DATA_INFO(short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_ET_FEC_MODE_TABLE_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_ET_FEC_MODE_DATA_INFO(short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_ET_FAC_PA_VPA_CONF_INFO(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_ET_FAC_SUBBAND_COUNT_INFO(short v1, short v2);
void L1TRC_Send_EL1D_TRC_ET_FAC_BAND_WIDTH_INFO(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_ET_FAC_IMM_MIPI_INFO(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_ET_FAC_S2_A_B_CAL_INFO(short v1, short v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_ET_FAC_S2_REPEAT_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_ET_FAC_DET_GAIN_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_ET_FAC_S2_POST_DELAY_INFO(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG0(short v1);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG1(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG2(unsigned long v1, long v2);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG3(short v1, short v2);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG4(short v1, short v2);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG5(unsigned long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG6(unsigned long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG7(long v1);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG8(long v1, long v2);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG9(unsigned long v1, unsigned long v2, short v3);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG10(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG11(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG12(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG13(long v1, long v2);
void L1TRC_Send_EL1D_TRC_ET_FAC_DBG14(long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_ET_OTFC_DBG0(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_ET_OTFC_DBG1(short v1);
void L1TRC_Send_EL1D_TRC_ET_OTFC_DBG2(short v1);
void L1TRC_Send_EL1D_TRC_ET_OTFC_DBG3(short v1);
void L1TRC_Send_EL1D_TRC_ET_OTFC_DBG4(short v1);
void L1TRC_Send_EL1D_TRC_ET_OTFC_DBG5(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_ET_OTFC_DBG6(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_EL1D_TRC_ET_OTFC_DBG7(long v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_ET_OTFC_DBG8(long v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_ET_OTFC_DBG9(long v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_ET_META_PATH_DELAY(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_ET_DRV_EVENT_INFO(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_ET_DRV_STATUS_INFO(unsigned long v1);

void Set_EL1D_ET0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_ET0()	(EL1D_ET0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()	(ChkL1ModFltr_EL1D_ET0()&&((EL1D_ET0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_M()	(ChkL1ModFltr_EL1D_ET0()&&((EL1D_ET0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_L()	(ChkL1ModFltr_EL1D_ET0()&&((EL1D_ET0_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG0()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG1()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG2()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG3()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG4()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG5()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG12()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG15()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG16()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG17()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG18()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG19()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG20()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DBG21()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FEC_TPC_TABLE_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FEC_EVENT_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FEC_TPC_DATA_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FEC_VPA_TABLE_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FEC_VPA_DATA_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FEC_BW_TABLE_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FEC_BW_DATA_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FEC_MODE_TABLE_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FEC_MODE_DATA_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_PA_VPA_CONF_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_SUBBAND_COUNT_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_BAND_WIDTH_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_IMM_MIPI_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_S2_A_B_CAL_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_S2_REPEAT_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DET_GAIN_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_S2_POST_DELAY_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG0()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG1()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG2()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG3()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG4()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG5()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG6()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG7()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG8()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG9()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG10()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG11()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG12()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG13()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_FAC_DBG14()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_OTFC_DBG0()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_OTFC_DBG1()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_OTFC_DBG2()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_OTFC_DBG3()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_OTFC_DBG4()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_OTFC_DBG5()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_OTFC_DBG6()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_OTFC_DBG7()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_OTFC_DBG8()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_OTFC_DBG9()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_META_PATH_DELAY()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DRV_EVENT_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_ET_DRV_STATUS_INFO()	ChkL1ClsFltr_EL1D_ET0_EL1D_TRC_CLS_ET_MAIN_H()


#endif
