#ifndef L1TRC_EL1D_CS_DEF_H
#define L1TRC_EL1D_CS_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_FSM_CHG_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0033, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_FSM_CHG_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_CS_FSM_CHG_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0033, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CMD_ID_H(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0133, (unsigned char)(v2), (unsigned char)(v3)), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CS_CMD_ID_H(v1, v2, v3)
#endif
#define EL1D_TRC_CS_CMD_ID_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0133, (unsigned char)(v2), (unsigned char)(v3)), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CSC_CMD_INFO_1_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0233, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v8), (char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v7), (char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), (unsigned char)(v13), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_CSC_CMD_INFO_1_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#endif
#define EL1D_TRC_CS_CSC_CMD_INFO_1_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0233, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v8), (char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v7), (char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), (unsigned char)(v13), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CSC_CMD_INFO_2_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0333, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_CSC_CMD_INFO_2_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_CS_CSC_CMD_INFO_2_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0333, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CDC_CMD_INFO_1_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0433, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v13)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), (unsigned char)(v5), (unsigned char)(v7)), TRC_MERGE_4C((char)(v8), (char)(v9), (unsigned char)(v10), (unsigned char)(v12)));\
	} while(0)
#else
	#define EL1D_TRC_CS_CDC_CMD_INFO_1_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#endif
#define EL1D_TRC_CS_CDC_CMD_INFO_1_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0433, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v13)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), (unsigned char)(v5), (unsigned char)(v7)), TRC_MERGE_4C((char)(v8), (char)(v9), (unsigned char)(v10), (unsigned char)(v12)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CDC_CMD_INFO_2_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0533, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_CDC_CMD_INFO_2_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_CS_CDC_CMD_INFO_2_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0533, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_MC_CMD_INFO_1_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0633, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v13)), TRC_MERGE_1S2C((unsigned short)(v15), (char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((char)(v5), (unsigned char)(v6), (char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((char)(v9), (char)(v10), (char)(v11), (unsigned char)(v12)), TRC_MERGE_4C((unsigned char)(v14), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_MC_CMD_INFO_1_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define EL1D_TRC_CS_MC_CMD_INFO_1_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0633, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v13)), TRC_MERGE_1S2C((unsigned short)(v15), (char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((char)(v5), (unsigned char)(v6), (char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((char)(v9), (char)(v10), (char)(v11), (unsigned char)(v12)), TRC_MERGE_4C((unsigned char)(v14), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_MC_CMD_INFO_2_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0733, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (char)(v9), (char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_MC_CMD_INFO_2_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define EL1D_TRC_CS_MC_CMD_INFO_2_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0733, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (char)(v9), (char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_GCC_CMD_INFO_H(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0833, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_GCC_CMD_INFO_H(v1, v2, v3)
#endif
#define EL1D_TRC_CS_GCC_CMD_INFO_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0833, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SIC_SKIP_CMD_H(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0933, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_SIC_SKIP_CMD_H(v1, v2, v3)
#endif
#define EL1D_TRC_CS_SIC_SKIP_CMD_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0933, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_ABORT_RXNBI_BY_ABORT_CMD_H() do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_ABORT_RXNBI_BY_ABORT_CMD_H()
#endif
#define EL1D_TRC_CS_ABORT_RXNBI_BY_ABORT_CMD_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO01(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B33, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO01(v1, v2)
#endif
#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO01_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B33, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO02(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0C33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO02(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO02_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0C33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO03(v1, v2, v3, v4) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0D33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO03(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO03_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0D33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO04(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0E33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO04(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_SET_PAGE_PREPARE_INFO04_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0E33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_ENABLE_PAGE(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F33, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_ENABLE_PAGE(v1, v2)
#endif
#define EL1D_TRC_CS_ENABLE_PAGE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F33, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_FREE_PAGE(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1033, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_FREE_PAGE(v1, v2)
#endif
#define EL1D_TRC_CS_FREE_PAGE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1033, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_WB_BUFFER_INSERT01(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1133, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_CS_WB_BUFFER_INSERT01(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CS_WB_BUFFER_INSERT01_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1133, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_WB_BUFFER_INSERT02(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1233, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_CS_WB_BUFFER_INSERT02(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CS_WB_BUFFER_INSERT02_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1233, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_PAGE_RPT01(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1333, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_PAGE_RPT01(v1, v2)
#endif
#define EL1D_TRC_CS_PAGE_RPT01_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1333, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_PAGE_RPT02() do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1433, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_PAGE_RPT02()
#endif
#define EL1D_TRC_CS_PAGE_RPT02_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1433, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_PAGE_RPT03() do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1533, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_PAGE_RPT03()
#endif
#define EL1D_TRC_CS_PAGE_RPT03_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1533, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_PAGE_RPT_WARN01(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1633, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_PAGE_RPT_WARN01(v1, v2)
#endif
#define EL1D_TRC_CS_PAGE_RPT_WARN01_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1633, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_PAGE_END_TIME(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1733, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_CS_PAGE_END_TIME(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CS_PAGE_END_TIME_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1733, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_ABORT_CMD_PARSE_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1833, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_ABORT_CMD_PARSE_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_ABORT_CMD_PARSE_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1833, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_ABORT_WB_STATE_CHANGE_H(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1933, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_ABORT_WB_STATE_CHANGE_H(v1, v2, v3)
#endif
#define EL1D_TRC_CS_ABORT_WB_STATE_CHANGE_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1933, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_ABORT_DUMP_WB_STATE_CHANGE_H(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A33, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_ABORT_DUMP_WB_STATE_CHANGE_H(v1, v2, v3)
#endif
#define EL1D_TRC_CS_ABORT_DUMP_WB_STATE_CHANGE_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A33, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_ABORT_IF_HW_STOPPED_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B33, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_ABORT_IF_HW_STOPPED_H(v1, v2)
#endif
#define EL1D_TRC_CS_ABORT_IF_HW_STOPPED_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B33, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_ABORT_REPORT_PARSE_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1C33, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_ABORT_REPORT_PARSE_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_CS_ABORT_REPORT_PARSE_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1C33, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_PUT_ABORTED_CMD_REPORT_TO_HISR(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D33, (unsigned char)(v1), (char)(v2)), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CS_PUT_ABORTED_CMD_REPORT_TO_HISR(v1, v2, v3)
#endif
#define EL1D_TRC_CS_PUT_ABORTED_CMD_REPORT_TO_HISR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D33, (unsigned char)(v1), (char)(v2)), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_HRT_MARGIN_NOT_ENOUGH(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1E33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CS_HRT_MARGIN_NOT_ENOUGH(v1, v2, v3)
#endif
#define EL1D_TRC_CS_HRT_MARGIN_NOT_ENOUGH_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1E33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CA_INTERRUPT_TIME_QUERY_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F33, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), (unsigned char)(v3)), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_CS_CA_INTERRUPT_TIME_QUERY_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_CA_INTERRUPT_TIME_QUERY_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F33, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), (unsigned char)(v3)), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CA_INTERRUPT_TIME_CHECK_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2033, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_CS_CA_INTERRUPT_TIME_CHECK_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_CS_CA_INTERRUPT_TIME_CHECK_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2033, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_RXNBI_ABORTED_BY_INTERRUPT_TIME_H(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2133, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_RXNBI_ABORTED_BY_INTERRUPT_TIME_H(v1)
#endif
#define EL1D_TRC_CS_RXNBI_ABORTED_BY_INTERRUPT_TIME_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2133, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_HISR_REPORT_TRIGGERED_BY_ABORT_H(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2233, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_HISR_REPORT_TRIGGERED_BY_ABORT_H(v1)
#endif
#define EL1D_TRC_CS_HISR_REPORT_TRIGGERED_BY_ABORT_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2233, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CDC_REPORT_COMPLETED_H(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2333, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v7), (char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v6), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_CS_CDC_REPORT_COMPLETED_H(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_CS_CDC_REPORT_COMPLETED_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2333, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v7), (char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v6), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CDC_REPORT_ABORTED_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2433, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_CDC_REPORT_ABORTED_H(v1, v2)
#endif
#define EL1D_TRC_CS_CDC_REPORT_ABORTED_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2433, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CSC_REPORT_COMPLETED_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2533, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_CS_CSC_REPORT_COMPLETED_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_CSC_REPORT_COMPLETED_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2533, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CSC_CELL_RESULT_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2633, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v7)), TRC_MERGE_4C((char)(v2), (char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_CSC_CELL_RESULT_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_CS_CSC_CELL_RESULT_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2633, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v7)), TRC_MERGE_4C((char)(v2), (char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CSC_REPORT_ABORTED_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2733, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_CSC_REPORT_ABORTED_H(v1, v2)
#endif
#define EL1D_TRC_CS_CSC_REPORT_ABORTED_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2733, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CSCM_REPORT_COMPLETED_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2833, (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_CSCM_REPORT_COMPLETED_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_CS_CSCM_REPORT_COMPLETED_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2833, (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CSCM_CELL_RESULT_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2933, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v4), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CS_CSCM_CELL_RESULT_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CS_CSCM_CELL_RESULT_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2933, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v4), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CSCM_REPORT_ABORTED_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A33, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_CSCM_REPORT_ABORTED_H(v1, v2)
#endif
#define EL1D_TRC_CS_CSCM_REPORT_ABORTED_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A33, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_GCC_REPORT_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B33, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_GCC_REPORT_H(v1, v2)
#endif
#define EL1D_TRC_CS_GCC_REPORT_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B33, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_HALF_FRAME_TIMING_TYPE_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C33, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_HALF_FRAME_TIMING_TYPE_H(v1, v2)
#endif
#define EL1D_TRC_CS_HALF_FRAME_TIMING_TYPE_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C33, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_DUMP_DONE_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D33, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CS_DUMP_DONE_H(v1, v2)
#endif
#define EL1D_TRC_CS_DUMP_DONE_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D33, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SCPSMC_DUMP_DONE_H(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E33, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_SCPSMC_DUMP_DONE_H(v1)
#endif
#define EL1D_TRC_CS_SCPSMC_DUMP_DONE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E33, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SIC_TIMING(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F33, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_SIC_TIMING(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_SIC_TIMING_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F33, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_F_BIN(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3033, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_F_BIN(v1, v2)
#endif
#define EL1D_TRC_CS_F_BIN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3033, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_HW_WORKAROUND(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3133, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_HW_WORKAROUND(v1, v2, v3)
#endif
#define EL1D_TRC_CS_HW_WORKAROUND_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3133, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_HW_RESULT(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3233, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_HW_RESULT(v1, v2, v3)
#endif
#define EL1D_TRC_CS_HW_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3233, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_FBD_H(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3333, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CS_FBD_H(v1, v2, v3)
#endif
#define EL1D_TRC_CS_FBD_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3333, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_RF_ON_INFO_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3433, (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_CS_RF_ON_INFO_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_CS_RF_ON_INFO_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3433, (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_RF_OFF_INFO_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3533, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_CS_RF_OFF_INFO_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CS_RF_OFF_INFO_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3533, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_AFIFO_INFO_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3633, (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_CS_AFIFO_INFO_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_CS_AFIFO_INFO_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3633, (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_DUMP_INFO_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x3733, (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), (char)(v11), TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_CS_DUMP_INFO_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_CS_DUMP_INFO_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x3733, (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), (char)(v11), TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_DUMP_ABORT_INFO_H(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3833, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_DUMP_ABORT_INFO_H(v1, v2, v3)
#endif
#define EL1D_TRC_CS_DUMP_ABORT_INFO_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3833, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CAL_RF_ON_DURATION_FOR_RXNBI_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3933, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_CAL_RF_ON_DURATION_FOR_RXNBI_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_CAL_RF_ON_DURATION_FOR_RXNBI_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3933, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_PARTIAL_DUMP_REF_INFO(v1, v2, v3, v4) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_PARTIAL_DUMP_REF_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CS_PARTIAL_DUMP_REF_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_GCC_OUT_OFF_DUMP_REGION(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B33, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_GCC_OUT_OFF_DUMP_REGION(v1)
#endif
#define EL1D_TRC_CS_GCC_OUT_OFF_DUMP_REGION_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B33, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_AGC_CC_ADD(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C33, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CS_AGC_CC_ADD(v1, v2, v3)
#endif
#define EL1D_TRC_CS_AGC_CC_ADD_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C33, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_AGC_CC_DELETE(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D33, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CS_AGC_CC_DELETE(v1, v2, v3)
#endif
#define EL1D_TRC_CS_AGC_CC_DELETE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D33, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_AGC_CC_REQ() do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_AGC_CC_REQ()
#endif
#define EL1D_TRC_CS_AGC_CC_REQ_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SFTMR_NEXT_DUMP_SET(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3F33, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_SFTMR_NEXT_DUMP_SET(v1, v2, v3)
#endif
#define EL1D_TRC_CS_SFTMR_NEXT_DUMP_SET_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3F33, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SFTMR_STOP_RF_AND_AFIFO_SET(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4033, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_SFTMR_STOP_RF_AND_AFIFO_SET(v1, v2, v3)
#endif
#define EL1D_TRC_CS_SFTMR_STOP_RF_AND_AFIFO_SET_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4033, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SFTMR_RF_STOP_SET(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4133, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_SFTMR_RF_STOP_SET(v1, v2, v3)
#endif
#define EL1D_TRC_CS_SFTMR_RF_STOP_SET_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4133, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SFTMR_AFIFO_STOP_SET(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4233, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_SFTMR_AFIFO_STOP_SET(v1, v2, v3)
#endif
#define EL1D_TRC_CS_SFTMR_AFIFO_STOP_SET_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4233, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SFTMR_EXPIRE(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4333, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_SFTMR_EXPIRE(v1, v2)
#endif
#define EL1D_TRC_CS_SFTMR_EXPIRE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4333, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_SFTMR_REMOVE(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4433, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_SFTMR_REMOVE(v1, v2)
#endif
#define EL1D_TRC_CS_SFTMR_REMOVE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4433, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_MAIN_TICK(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4533, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CS_MAIN_TICK(v1)
#endif
#define EL1D_TRC_CS_MAIN_TICK_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4533, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_MAIN_EXPIRE(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4633, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CS_MAIN_EXPIRE(v1)
#endif
#define EL1D_TRC_CS_MAIN_EXPIRE_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4633, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_MAIN_END() do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4733, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_MAIN_END()
#endif
#define EL1D_TRC_CS_MAIN_END_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4733, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_DMA0_TEST(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4833, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CS_DMA0_TEST(v1)
#endif
#define EL1D_TRC_CS_DMA0_TEST_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4833, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_DMA1_TEST(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4933, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CS_DMA1_TEST(v1)
#endif
#define EL1D_TRC_CS_DMA1_TEST_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4933, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_RP_SRAM(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4A33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_RP_SRAM(v1, v2)
#endif
#define EL1D_TRC_CS_RP_SRAM_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4A33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_RP_FAIL_INFO(v1, v2, v3, v4) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4B33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_CS_RP_FAIL_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CS_RP_FAIL_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4B33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_HW_CRC(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4C33, (short)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_CS_HW_CRC(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_HW_CRC_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4C33, (short)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_COSIM_STATISTICS(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4D33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CS_COSIM_STATISTICS(v1, v2, v3)
#endif
#define EL1D_TRC_CS_COSIM_STATISTICS_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4D33, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_HW_DBG_INFO_0(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4E33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v5), (unsigned char)(v6), (char)(v7)), (long)(v4), (long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_CS_HW_DBG_INFO_0(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_CS_HW_DBG_INFO_0_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4E33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v5), (unsigned char)(v6), (char)(v7)), (long)(v4), (long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_HW_DBG_INFO_1(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4F33, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_CS_HW_DBG_INFO_1(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_HW_DBG_INFO_1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4F33, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_HW_DBG_INFO_2(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x5033, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_CS_HW_DBG_INFO_2(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_HW_DBG_INFO_2_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x5033, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_PRINT_RAW_DATA_RX0(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x5133, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_CS_PRINT_RAW_DATA_RX0(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_CS_PRINT_RAW_DATA_RX0_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x5133, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_PRINT_RAW_DATA_RX1(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x5233, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_CS_PRINT_RAW_DATA_RX1(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_CS_PRINT_RAW_DATA_RX1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x5233, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_FREQ_BIN_FAIL(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5333, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_FREQ_BIN_FAIL(v1, v2, v3)
#endif
#define EL1D_TRC_CS_FREQ_BIN_FAIL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5333, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_DSPCNWDMA_INFO_0() do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5433, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_DSPCNWDMA_INFO_0()
#endif
#define EL1D_TRC_CS_DSPCNWDMA_INFO_0_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5433, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_DSPCNWDMA_INFO_1() do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5533, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_DSPCNWDMA_INFO_1()
#endif
#define EL1D_TRC_CS_DSPCNWDMA_INFO_1_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5533, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_LPWR_SLEEP(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5633, (char)(v1), (char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_LPWR_SLEEP(v1, v2, v3)
#endif
#define EL1D_TRC_CS_LPWR_SLEEP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5633, (char)(v1), (char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_LPWR_CSHW_POWER(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5733, (char)(v1), (char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_LPWR_CSHW_POWER(v1, v2, v3)
#endif
#define EL1D_TRC_CS_LPWR_CSHW_POWER_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5733, (char)(v1), (char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_LPWR_CSHW_CLOCK(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5833, (char)(v1), (char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_LPWR_CSHW_CLOCK(v1, v2, v3)
#endif
#define EL1D_TRC_CS_LPWR_CSHW_CLOCK_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5833, (char)(v1), (char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_LPWR_CSHW_TIMER_START(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5933, (char)(v1), (char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_LPWR_CSHW_TIMER_START(v1, v2, v3)
#endif
#define EL1D_TRC_CS_LPWR_CSHW_TIMER_START_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5933, (char)(v1), (char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_LPWR_CSHW_TIMER_EXPIRY(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A33, (char)(v1), (char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_LPWR_CSHW_TIMER_EXPIRY(v1, v2, v3)
#endif
#define EL1D_TRC_CS_LPWR_CSHW_TIMER_EXPIRY_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A33, (char)(v1), (char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_LPWR_CSHW_TIMER_STOP(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5B33, (char)(v1), (char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_LPWR_CSHW_TIMER_STOP(v1, v2, v3)
#endif
#define EL1D_TRC_CS_LPWR_CSHW_TIMER_STOP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5B33, (char)(v1), (char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_INJECT_STRING_PCI_SET(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5C33, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_CS_INJECT_STRING_PCI_SET(v1)
#endif
#define EL1D_TRC_CS_INJECT_STRING_PCI_SET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5C33, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_INJECT_STRING_THRESHOLD_SET(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5D33, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_CS_INJECT_STRING_THRESHOLD_SET(v1)
#endif
#define EL1D_TRC_CS_INJECT_STRING_THRESHOLD_SET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5D33, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_INJECT_STRING_BIAS_SET(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E33, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_INJECT_STRING_BIAS_SET(v1)
#endif
#define EL1D_TRC_CS_INJECT_STRING_BIAS_SET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E33, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_INJECT_STRING_TOTAL_INFO(v1, v2, v3, v4, v5) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5F33, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CS_INJECT_STRING_TOTAL_INFO(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CS_INJECT_STRING_TOTAL_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5F33, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_INJECT_STRING_ASSERT_FAIL() do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6033, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_INJECT_STRING_ASSERT_FAIL()
#endif
#define EL1D_TRC_CS_INJECT_STRING_ASSERT_FAIL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6033, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_INJECT_STRING_FORCE_BIN_INFO(v1, v2, v3) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6133, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_INJECT_STRING_FORCE_BIN_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_CS_INJECT_STRING_FORCE_BIN_INFO_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6133, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_INJECT_STRINC_PRINT_RAW_DATA_INFO(v1) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6233, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CS_INJECT_STRINC_PRINT_RAW_DATA_INFO(v1)
#endif
#define EL1D_TRC_CS_INJECT_STRINC_PRINT_RAW_DATA_INFO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6233, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_CYCLE_CNT_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6333, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_CYCLE_CNT_H(v1, v2)
#endif
#define EL1D_TRC_CS_CYCLE_CNT_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6333, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CS_ELM_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6433, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CS_ELM_H(v1, v2)
#endif
#define EL1D_TRC_CS_ELM_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6433, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_CS_OVER_THRESHOLD_TIME_PROFILE_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6533, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_CS_OVER_THRESHOLD_TIME_PROFILE_H(v1, v2)
#endif
#define EL1D_CS_OVER_THRESHOLD_TIME_PROFILE_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6533, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_CS_PENDING_TIME_PROFILE_H(v1, v2) do {\
		if(EL1D_CS_Trace_Filter[0]==1 && (EL1D_CS_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6633, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_CS_PENDING_TIME_PROFILE_H(v1, v2)
#endif
#define EL1D_CS_PENDING_TIME_PROFILE_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6633, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_CS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_CS_FSM_CHG_H(char v1, char v2, char v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_EL1D_TRC_CS_CMD_ID_H(long v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_CS_CSC_CMD_INFO_1_H(char v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned char v5, unsigned short v6, unsigned char v7, unsigned short v8, char v9, unsigned char v10, unsigned char v11, unsigned char v12, unsigned char v13);
void L1TRC_Send_EL1D_TRC_CS_CSC_CMD_INFO_2_H(char v1, char v2, unsigned char v3, unsigned char v4, char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_CS_CDC_CMD_INFO_1_H(char v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned char v5, unsigned short v6, unsigned char v7, char v8, char v9, unsigned char v10, unsigned short v11, unsigned char v12, unsigned short v13);
void L1TRC_Send_EL1D_TRC_CS_CDC_CMD_INFO_2_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, char v5, char v6, unsigned char v7, unsigned char v8, char v9, unsigned char v10, unsigned char v11);
void L1TRC_Send_EL1D_TRC_CS_MC_CMD_INFO_1_H(char v1, unsigned short v2, unsigned char v3, unsigned short v4, char v5, unsigned char v6, char v7, unsigned char v8, char v9, char v10, char v11, unsigned char v12, unsigned short v13, unsigned char v14, unsigned short v15);
void L1TRC_Send_EL1D_TRC_CS_MC_CMD_INFO_2_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, char v5, char v6, unsigned char v7, unsigned char v8, char v9, char v10, unsigned char v11, unsigned char v12);
void L1TRC_Send_EL1D_TRC_CS_GCC_CMD_INFO_H(char v1, char v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_CS_SIC_SKIP_CMD_H(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_CS_ABORT_RXNBI_BY_ABORT_CMD_H(void);
void L1TRC_Send_EL1D_TRC_CS_SET_PAGE_PREPARE_INFO01(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_SET_PAGE_PREPARE_INFO02(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_CS_SET_PAGE_PREPARE_INFO03(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_CS_SET_PAGE_PREPARE_INFO04(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_CS_ENABLE_PAGE(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_FREE_PAGE(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_WB_BUFFER_INSERT01(unsigned char v1, char v2, unsigned char v3, char v4, unsigned char v5, char v6);
void L1TRC_Send_EL1D_TRC_CS_WB_BUFFER_INSERT02(unsigned char v1, char v2, unsigned char v3, char v4, unsigned char v5, char v6);
void L1TRC_Send_EL1D_TRC_CS_PAGE_RPT01(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_PAGE_RPT02(void);
void L1TRC_Send_EL1D_TRC_CS_PAGE_RPT03(void);
void L1TRC_Send_EL1D_TRC_CS_PAGE_RPT_WARN01(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_PAGE_END_TIME(unsigned char v1, unsigned char v2, char v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_CS_ABORT_CMD_PARSE_H(unsigned char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_CS_ABORT_WB_STATE_CHANGE_H(unsigned char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_CS_ABORT_DUMP_WB_STATE_CHANGE_H(unsigned char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_CS_ABORT_IF_HW_STOPPED_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_ABORT_REPORT_PARSE_H(unsigned char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_EL1D_TRC_CS_PUT_ABORTED_CMD_REPORT_TO_HISR(unsigned char v1, char v2, long v3);
void L1TRC_Send_EL1D_TRC_CS_HRT_MARGIN_NOT_ENOUGH(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_CS_CA_INTERRUPT_TIME_QUERY_H(char v1, unsigned short v2, unsigned char v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_EL1D_TRC_CS_CA_INTERRUPT_TIME_CHECK_H(char v1, unsigned short v2, unsigned char v3, unsigned long v4, unsigned short v5, unsigned char v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_CS_RXNBI_ABORTED_BY_INTERRUPT_TIME_H(char v1);
void L1TRC_Send_EL1D_TRC_CS_HISR_REPORT_TRIGGERED_BY_ABORT_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_CS_CDC_REPORT_COMPLETED_H(unsigned char v1, char v2, unsigned short v3, char v4, unsigned char v5, long v6, unsigned char v7, unsigned long v8, char v9);
void L1TRC_Send_EL1D_TRC_CS_CDC_REPORT_ABORTED_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_CSC_REPORT_COMPLETED_H(unsigned char v1, char v2, unsigned short v3, char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_CS_CSC_CELL_RESULT_H(unsigned short v1, char v2, unsigned short v3, char v4, unsigned char v5, unsigned char v6, unsigned short v7, char v8);
void L1TRC_Send_EL1D_TRC_CS_CSC_REPORT_ABORTED_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_CSCM_REPORT_COMPLETED_H(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned short v7);
void L1TRC_Send_EL1D_TRC_CS_CSCM_CELL_RESULT_H(unsigned short v1, unsigned short v2, long v3, unsigned char v4, unsigned short v5, char v6);
void L1TRC_Send_EL1D_TRC_CS_CSCM_REPORT_ABORTED_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_GCC_REPORT_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_HALF_FRAME_TIMING_TYPE_H(unsigned short v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_DUMP_DONE_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_CS_SCPSMC_DUMP_DONE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_CS_SIC_TIMING(unsigned char v1, unsigned short v2, char v3, unsigned short v4, char v5);
void L1TRC_Send_EL1D_TRC_CS_F_BIN(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_CS_HW_WORKAROUND(unsigned short v1, long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_CS_HW_RESULT(unsigned short v1, long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_CS_FBD_H(unsigned char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_CS_RF_ON_INFO_H(unsigned char v1, char v2, char v3, char v4, char v5, char v6, unsigned short v7, char v8, unsigned short v9, unsigned long v10);
void L1TRC_Send_EL1D_TRC_CS_RF_OFF_INFO_H(unsigned char v1, char v2, char v3, char v4, unsigned short v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_CS_AFIFO_INFO_H(unsigned char v1, char v2, char v3, char v4, char v5, char v6, unsigned short v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_CS_DUMP_INFO_H(unsigned char v1, char v2, char v3, char v4, char v5, char v6, unsigned long v7, unsigned long v8, unsigned short v9, unsigned long v10, char v11);
void L1TRC_Send_EL1D_TRC_CS_DUMP_ABORT_INFO_H(unsigned char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_CS_CAL_RF_ON_DURATION_FOR_RXNBI_H(char v1, unsigned long v2, char v3, short v4, char v5);
void L1TRC_Send_EL1D_TRC_CS_PARTIAL_DUMP_REF_INFO(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_CS_GCC_OUT_OFF_DUMP_REGION(char v1);
void L1TRC_Send_EL1D_TRC_CS_AGC_CC_ADD(char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_CS_AGC_CC_DELETE(char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_CS_AGC_CC_REQ(void);
void L1TRC_Send_EL1D_TRC_CS_SFTMR_NEXT_DUMP_SET(unsigned char v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_CS_SFTMR_STOP_RF_AND_AFIFO_SET(unsigned char v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_CS_SFTMR_RF_STOP_SET(unsigned char v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_CS_SFTMR_AFIFO_STOP_SET(unsigned char v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_CS_SFTMR_EXPIRE(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CS_SFTMR_REMOVE(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CS_MAIN_TICK(unsigned long v1);
void L1TRC_Send_EL1D_TRC_CS_MAIN_EXPIRE(unsigned long v1);
void L1TRC_Send_EL1D_TRC_CS_MAIN_END(void);
void L1TRC_Send_EL1D_TRC_CS_DMA0_TEST(long v1);
void L1TRC_Send_EL1D_TRC_CS_DMA1_TEST(long v1);
void L1TRC_Send_EL1D_TRC_CS_RP_SRAM(long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CS_RP_FAIL_INFO(long v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_CS_HW_CRC(long v1, short v2, char v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_CS_COSIM_STATISTICS(long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_CS_HW_DBG_INFO_0(unsigned char v1, unsigned char v2, char v3, long v4, unsigned char v5, unsigned char v6, char v7, long v8);
void L1TRC_Send_EL1D_TRC_CS_HW_DBG_INFO_1(char v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_CS_HW_DBG_INFO_2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_CS_PRINT_RAW_DATA_RX0(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1D_TRC_CS_PRINT_RAW_DATA_RX1(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1D_TRC_CS_FREQ_BIN_FAIL(unsigned char v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_CS_DSPCNWDMA_INFO_0(void);
void L1TRC_Send_EL1D_TRC_CS_DSPCNWDMA_INFO_1(void);
void L1TRC_Send_EL1D_TRC_CS_LPWR_SLEEP(char v1, unsigned long v2, char v3);
void L1TRC_Send_EL1D_TRC_CS_LPWR_CSHW_POWER(char v1, unsigned long v2, char v3);
void L1TRC_Send_EL1D_TRC_CS_LPWR_CSHW_CLOCK(char v1, unsigned long v2, char v3);
void L1TRC_Send_EL1D_TRC_CS_LPWR_CSHW_TIMER_START(char v1, unsigned long v2, char v3);
void L1TRC_Send_EL1D_TRC_CS_LPWR_CSHW_TIMER_EXPIRY(char v1, unsigned long v2, char v3);
void L1TRC_Send_EL1D_TRC_CS_LPWR_CSHW_TIMER_STOP(char v1, unsigned long v2, char v3);
void L1TRC_Send_EL1D_TRC_CS_INJECT_STRING_PCI_SET(unsigned short v1);
void L1TRC_Send_EL1D_TRC_CS_INJECT_STRING_THRESHOLD_SET(unsigned short v1);
void L1TRC_Send_EL1D_TRC_CS_INJECT_STRING_BIAS_SET(unsigned char v1);
void L1TRC_Send_EL1D_TRC_CS_INJECT_STRING_TOTAL_INFO(unsigned long v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_CS_INJECT_STRING_ASSERT_FAIL(void);
void L1TRC_Send_EL1D_TRC_CS_INJECT_STRING_FORCE_BIN_INFO(unsigned short v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_CS_INJECT_STRINC_PRINT_RAW_DATA_INFO(char v1);
void L1TRC_Send_EL1D_TRC_CS_CYCLE_CNT_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CS_ELM_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_CS_OVER_THRESHOLD_TIME_PROFILE_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_CS_PENDING_TIME_PROFILE_H(unsigned long v1, unsigned long v2);

void Set_EL1D_CS_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_CS()	(EL1D_CS_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FSM_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FSM_L()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_L()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_ABORT_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_ABORT_L()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_L()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_UTILITY_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_UTILITY_L()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_L()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_L()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_L()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FPGA_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FPGA_L()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_HW_DBG_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_LPWR_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_INJECT_STRING_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RUN_TIME_H()	(ChkL1ModFltr_EL1D_CS()&&((EL1D_CS_Trace_Filter[3]&0x20)!=0))
#define ChkL1MsgFltr_EL1D_TRC_CS_FSM_CHG_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CMD_ID_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CSC_CMD_INFO_1_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CSC_CMD_INFO_2_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CDC_CMD_INFO_1_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CDC_CMD_INFO_2_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_MC_CMD_INFO_1_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_MC_CMD_INFO_2_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_GCC_CMD_INFO_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SIC_SKIP_CMD_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_ABORT_RXNBI_BY_ABORT_CMD_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SET_PAGE_PREPARE_INFO01()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SET_PAGE_PREPARE_INFO02()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SET_PAGE_PREPARE_INFO03()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SET_PAGE_PREPARE_INFO04()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_ENABLE_PAGE()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_FREE_PAGE()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_WB_BUFFER_INSERT01()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_WB_BUFFER_INSERT02()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_PAGE_RPT01()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_PAGE_RPT02()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_PAGE_RPT03()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_PAGE_RPT_WARN01()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_PAGE_END_TIME()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_PAGE_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_ABORT_CMD_PARSE_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_ABORT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_ABORT_WB_STATE_CHANGE_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_ABORT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_ABORT_DUMP_WB_STATE_CHANGE_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_ABORT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_ABORT_IF_HW_STOPPED_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_ABORT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_ABORT_REPORT_PARSE_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_ABORT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_PUT_ABORTED_CMD_REPORT_TO_HISR()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_ABORT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_HRT_MARGIN_NOT_ENOUGH()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_ABORT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CA_INTERRUPT_TIME_QUERY_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_UTILITY_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CA_INTERRUPT_TIME_CHECK_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_UTILITY_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_RXNBI_ABORTED_BY_INTERRUPT_TIME_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_UTILITY_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_HISR_REPORT_TRIGGERED_BY_ABORT_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CDC_REPORT_COMPLETED_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CDC_REPORT_ABORTED_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CSC_REPORT_COMPLETED_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CSC_CELL_RESULT_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CSC_REPORT_ABORTED_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CSCM_REPORT_COMPLETED_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CSCM_CELL_RESULT_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CSCM_REPORT_ABORTED_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_GCC_REPORT_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_HALF_FRAME_TIMING_TYPE_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_DUMP_DONE_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SCPSMC_DUMP_DONE_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SIC_TIMING()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_F_BIN()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_HW_WORKAROUND()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_HW_RESULT()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_FBD_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_RF_ON_INFO_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_RF_OFF_INFO_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_AFIFO_INFO_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_DUMP_INFO_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_DUMP_ABORT_INFO_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CAL_RF_ON_DURATION_FOR_RXNBI_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_PARTIAL_DUMP_REF_INFO()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_GCC_OUT_OFF_DUMP_REGION()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_AGC_CC_ADD()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_AGC_CC_DELETE()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_AGC_CC_REQ()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SFTMR_NEXT_DUMP_SET()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SFTMR_STOP_RF_AND_AFIFO_SET()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SFTMR_RF_STOP_SET()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SFTMR_AFIFO_STOP_SET()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SFTMR_EXPIRE()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_SFTMR_REMOVE()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_MAIN_TICK()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_MAIN_EXPIRE()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_MAIN_END()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_SFTMR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_DMA0_TEST()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FPGA_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_DMA1_TEST()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FPGA_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_RP_SRAM()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FPGA_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_RP_FAIL_INFO()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FPGA_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_HW_CRC()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FPGA_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_COSIM_STATISTICS()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_FPGA_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_HW_DBG_INFO_0()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_HW_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_HW_DBG_INFO_1()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_HW_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_HW_DBG_INFO_2()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_HW_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_PRINT_RAW_DATA_RX0()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_HW_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_PRINT_RAW_DATA_RX1()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_HW_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_FREQ_BIN_FAIL()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_HW_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_DSPCNWDMA_INFO_0()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_HW_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_DSPCNWDMA_INFO_1()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_HW_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_LPWR_SLEEP()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_LPWR_CSHW_POWER()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_LPWR_CSHW_CLOCK()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_LPWR_CSHW_TIMER_START()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_LPWR_CSHW_TIMER_EXPIRY()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_LPWR_CSHW_TIMER_STOP()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_INJECT_STRING_PCI_SET()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_INJECT_STRING_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_INJECT_STRING_THRESHOLD_SET()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_INJECT_STRING_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_INJECT_STRING_BIAS_SET()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_INJECT_STRING_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_INJECT_STRING_TOTAL_INFO()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_INJECT_STRING_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_INJECT_STRING_ASSERT_FAIL()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_INJECT_STRING_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_INJECT_STRING_FORCE_BIN_INFO()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_INJECT_STRING_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_INJECT_STRINC_PRINT_RAW_DATA_INFO()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_INJECT_STRING_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_CYCLE_CNT_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_INJECT_STRING_H()
#define ChkL1MsgFltr_EL1D_TRC_CS_ELM_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_INJECT_STRING_H()
#define ChkL1MsgFltr_EL1D_CS_OVER_THRESHOLD_TIME_PROFILE_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RUN_TIME_H()
#define ChkL1MsgFltr_EL1D_CS_PENDING_TIME_PROFILE_H()	ChkL1ClsFltr_EL1D_CS_EL1D_TRC_CS_RUN_TIME_H()


#endif
