#ifndef L1TRC_UL1D_HSPA_THIRD_DEF_H
#define L1TRC_UL1D_HSPA_THIRD_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_TXUPC_DBG(v1)  (unsigned char)(v1+0)
#define UL1D_HSPA_TRC2_E_SC(v1)  (unsigned char)(v1+97)
#define UL1D_WFEC_RACH_IRQ_TYPE(v1)  (unsigned char)(v1+100)
#define UL1D_WFEC_DCH_IRQ_TYPE(v1)  (unsigned char)(v1+104)
#define UL1D_WFEC_DFESYS_BUS(v1)  (unsigned char)(v1+106)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0024, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_POW_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0024, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0124, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_POW_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0124, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_POW_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0224, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_POW_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0224, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HS_DPCCH_SYM_OFFSET(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0324, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_HS_DPCCH_SYM_OFFSET(v1)
#endif
#define UL1D_TRC_HS_DPCCH_SYM_OFFSET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0324, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_CHECK_INT16(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0424, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_CHECK_INT16(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_TXUPC_POW_CHECK_INT16_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0424, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_CHECK_ISSUE() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0524, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_CHECK_ISSUE()
#endif
#define UL1D_TRC_TXUPC_POW_CHECK_ISSUE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0524, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0624, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL(v1, v2)
#endif
#define UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0624, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0724, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_ADDSC_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0724, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0824, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_ADDSC_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0824, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0924, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_ADDSC_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0924, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_UPC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_UPC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_UPC_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_UPC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0B24, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_UPC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_UPC_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0B24, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_UPC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0C24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_UPC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_UPC_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0C24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0D24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0D24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0E24, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0E24, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0F24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0F24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT16G(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1024, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT16G(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT16G_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1024, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RF_BSI_L_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1124, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_L_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_L_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1124, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1224, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_IQDC_COMP_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1224, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1324, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_IQDC_COMP_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1324, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1424, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_IQDC_COMP_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1424, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1524, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_BSI_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1524, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1624, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_BSI_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1624, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1724, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_BSI_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1724, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1824, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1824, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1924, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1924, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1A24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1A24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_MPR_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1B24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_MPR_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_MPR_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1B24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_MPR_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1C24, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_MPR_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_MPR_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1C24, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_MPR_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1D24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_MPR_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_MPR_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1D24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_AUX_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1E24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_AUX_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_AUX_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1E24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_AUX_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1F24, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_AUX_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_AUX_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1F24, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_AUX_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2024, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_AUX_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_AUX_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2024, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2124, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_GAIN_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2124, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2224, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_GAIN_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2224, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_GAIN_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2324, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_GAIN_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_GAIN_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2324, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2424, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DELTA_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2424, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2524, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DELTA_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2524, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DELTA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2624, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DELTA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DELTA_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2624, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RTR_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2724, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RTR_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RTR_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2724, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RTR_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2824, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RTR_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RTR_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2824, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RTR_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2924, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RTR_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RTR_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2924, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DBG_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2A24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DBG_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DBG_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2A24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DBG_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2B24, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DBG_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DBG_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2B24, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DBG_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2C24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DBG_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DBG_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2C24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GENERAL_DEBUG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2D24, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_GENERAL_DEBUG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_GENERAL_DEBUG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2D24, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_LOW_POWER_DEBUG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2E24, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_LOW_POWER_DEBUG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_LOW_POWER_DEBUG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2E24, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TIME_MAC_R99_DBG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F24, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TIME_MAC_R99_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_TIME_MAC_R99_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F24, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TIME_MAC_R6_DBG(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3024, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TIME_MAC_R6_DBG(v1, v2)
#endif
#define UL1D_TRC_TIME_MAC_R6_DBG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3024, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXBRP_L2COPRO_ASSERT(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3124, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_L2COPRO_ASSERT(v1, v2)
#endif
#define UL1D_TRC_ETXBRP_L2COPRO_ASSERT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3124, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_0(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3224, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_0(v1, v2, v3)
#endif
#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3224, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_1(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3324, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_1(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3324, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_2(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3424, (unsigned char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_2(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_2_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3424, (unsigned char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_3(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3524, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_3(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3524, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_4(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3624, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_4(v1, v2, v3)
#endif
#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_4_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3624, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_5(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3724, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_5(v1, v2, v3)
#endif
#define UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_5_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3724, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXBRP_ENCODE_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3824, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_ENCODE_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_ETXBRP_ENCODE_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3824, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ERX_RSLT(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3924, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RSLT(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_ERX_RSLT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3924, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HI_RSLT_BITMAP(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A24, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_RSLT_BITMAP(v1, v2, v3)
#endif
#define UL1D_TRC_ERX_HI_RSLT_BITMAP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A24, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_RSLT_BITMAP(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B24, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_RSLT_BITMAP(v1, v2, v3)
#endif
#define UL1D_TRC_ERX_RG_RSLT_BITMAP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B24, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_EDCH_GAP_CONFIG_AG(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C24, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_GAP_CONFIG_AG(v1)
#endif
#define UL1D_TRC_EDCH_GAP_CONFIG_AG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C24, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_EDCH_GAP_CONFIG_HI(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3D24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_GAP_CONFIG_HI(v1, v2)
#endif
#define UL1D_TRC_EDCH_GAP_CONFIG_HI_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3D24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_EDCH_GAP_CONFIG_RG(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3E24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_GAP_CONFIG_RG(v1, v2)
#endif
#define UL1D_TRC_EDCH_GAP_CONFIG_RG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3E24, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HI_SOFT_DEBUG(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x3F24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_SOFT_DEBUG(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_ERX_HI_SOFT_DEBUG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_7_DATA(TRC_MERGE_2S(0x3F24, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_DEBUG(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x4024, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_DEBUG(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_ERX_RG_DEBUG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_7_DATA(TRC_MERGE_2S(0x4024, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_E2_HIRG_MIC_RLS(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4124, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_ERX_E2_HIRG_MIC_RLS(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_ERX_E2_HIRG_MIC_RLS_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4124, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_AG_ERR(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4224, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ERX_AG_ERR(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_ERX_AG_ERR_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4224, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HIRG_DECODE_DONE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_17_DATA(TRC_MERGE_1S2C(0x4324, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HIRG_DECODE_DONE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_ERX_HIRG_DECODE_DONE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_17_DATA(TRC_MERGE_1S2C(0x4324, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_AGCH_DEBUG(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4424, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_ERX_AGCH_DEBUG(v1, v2, v3)
#endif
#define UL1D_TRC_ERX_AGCH_DEBUG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4424, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_FRAMERATE_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4524, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_FRAMERATE_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_FRAMERATE_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4524, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_FRAMERATE_RTR_INFO(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4624, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FRAMERATE_RTR_INFO(v1, v2)
#endif
#define UL1D_TRC_FRAMERATE_RTR_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4624, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_POW_IND_INT32(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4724, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_POW_IND_INT32(v1, v2, v3)
#endif
#define UL1D_TRC_UL_DCH_POW_IND_INT32_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4724, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4824, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4824, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4924, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32(v1, v2, v3)
#endif
#define UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4924, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_WFEC_RACH_EN(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4A24, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_WFEC_RACH_EN(v1)
#endif
#define UL1D_TRC_WFEC_RACH_EN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4A24, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_WFEC_RACH_IRQ_SET(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4B24, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WFEC_RACH_IRQ_SET(v1, v2)
#endif
#define UL1D_TRC_WFEC_RACH_IRQ_SET_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4B24, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_WFEC_DCH_IRQ_SET(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4C24, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WFEC_DCH_IRQ_SET(v1, v2)
#endif
#define UL1D_TRC_WFEC_DCH_IRQ_SET_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4C24, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_WFEC_DFESYS_BUS_SET(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D24, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WFEC_DFESYS_BUS_SET(v1)
#endif
#define UL1D_TRC_WFEC_DFESYS_BUS_SET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D24, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_WFEC_DETREF_BW_SET(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4E24, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_WFEC_DETREF_BW_SET(v1)
#endif
#define UL1D_TRC_WFEC_DETREF_BW_SET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4E24, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_WFEC_C2M_DL_TRIG() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F24, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WFEC_C2M_DL_TRIG()
#endif
#define UL1D_TRC_WFEC_C2M_DL_TRIG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F24, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_WFEC_SHM_DL_INFO(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5024, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_WFEC_SHM_DL_INFO(v1, v2, v3)
#endif
#define UL1D_TRC_WFEC_SHM_DL_INFO_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5024, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FCM_GAP_START_CASCADE(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5124, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FCM_GAP_START_CASCADE(v1, v2)
#endif
#define UL1D_TRC_FCM_GAP_START_CASCADE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5124, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_CALC_AVAIL_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5224, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (short)(v9)));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_CALC_AVAIL_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_MM_GEMINI_CALC_AVAIL_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5224, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (short)(v9)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_TO_GAP_2G(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5324, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_TO_GAP_2G(v1, v2)
#endif
#define UL1D_TRC_MEAS_TO_GAP_2G_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5324, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_FCM_DONE_LISR() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5424, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_FCM_DONE_LISR()
#endif
#define UL1D_TRC_MM_GEMINI_FCM_DONE_LISR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5424, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_PICH_DONE_LISR(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5524, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_PICH_DONE_LISR(v1)
#endif
#define UL1D_TRC_MM_GEMINI_PICH_DONE_LISR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5524, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_GAP_CHECK_MEAS(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5624, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_2S((short)(v6), (short)(v7)), (unsigned long)(v3), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_GAP_CHECK_MEAS(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_MM_GEMINI_GAP_CHECK_MEAS_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5624, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_2S((short)(v6), (short)(v7)), (unsigned long)(v3), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_MODE(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5724, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_MODE(v1, v2)
#endif
#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_MODE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5724, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_PROHIBITED_TO_CHANGE_FREQ(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5824, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_PROHIBITED_TO_CHANGE_FREQ(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_PROHIBITED_TO_CHANGE_FREQ_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5824, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_ALLOWED(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5924, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_ALLOWED(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_ALLOWED_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5924, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_RUNNING(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A24, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_RUNNING(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_RUNNING_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A24, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5B24, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5B24, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_MEAS_ENTER_IDLE(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C24, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_MEAS_ENTER_IDLE(v1, v2)
#endif
#define UL1D_TRC_MM_GEMINI_MEAS_ENTER_IDLE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C24, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_STANDBY_FCM_DONE_LISR() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D24, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_STANDBY_FCM_DONE_LISR()
#endif
#define UL1D_TRC_STANDBY_FCM_DONE_LISR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D24, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_STOP_PICH_TIMER(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5E24, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_STOP_PICH_TIMER(v1)
#endif
#define UL1D_TRC_MM_GEMINI_STOP_PICH_TIMER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5E24, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_STOP_FCM_TIMER(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5F24, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_STOP_FCM_TIMER(v1)
#endif
#define UL1D_TRC_MM_GEMINI_STOP_FCM_TIMER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5F24, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_RETURN_PICH() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6024, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_RETURN_PICH()
#endif
#define UL1D_TRC_MM_GEMINI_RETURN_PICH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6024, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_FRAME_IDLE(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6124, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_FRAME_IDLE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MEAS_FRAME_IDLE_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6124, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (unsigned long)(v4))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_HSPA_THIRD_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_TXUPC_POW_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_HS_DPCCH_SYM_OFFSET(short v1);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_CHECK_INT16(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_CHECK_ISSUE(void);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL(char v1, char v2);
void L1TRC_Send_UL1D_TRC_TXUPC_ADDSC_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_ADDSC_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_ADDSC_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_UPC_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_UPC_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_UPC_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT16G(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_L_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_IQDC_COMP_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_IQDC_COMP_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_IQDC_COMP_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_BSI_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_BSI_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_BSI_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_MPR_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_MPR_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_MPR_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_AUX_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_AUX_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_AUX_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_GAIN_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_GAIN_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_GAIN_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DELTA_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DELTA_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DELTA_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RTR_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RTR_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RTR_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DBG_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DBG_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DBG_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_GENERAL_DEBUG(short v1, short v2, short v3, short v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_LOW_POWER_DEBUG(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_TIME_MAC_R99_DBG(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_TIME_MAC_R6_DBG(short v1, short v2);
void L1TRC_Send_UL1D_TRC_ETXBRP_L2COPRO_ASSERT(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_0(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_1(unsigned long v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_3(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_4(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_5(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_ETXBRP_ENCODE_TIME(unsigned char v1, short v2, short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9);
void L1TRC_Send_UL1D_TRC_ERX_RSLT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_ERX_HI_RSLT_BITMAP(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_ERX_RG_RSLT_BITMAP(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_EDCH_GAP_CONFIG_AG(unsigned long v1);
void L1TRC_Send_UL1D_TRC_EDCH_GAP_CONFIG_HI(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_EDCH_GAP_CONFIG_RG(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_ERX_HI_SOFT_DEBUG(unsigned char v1, short v2, short v3, short v4, short v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_UL1D_TRC_ERX_RG_DEBUG(unsigned char v1, short v2, short v3, short v4, short v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_UL1D_TRC_ERX_E2_HIRG_MIC_RLS(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_ERX_AG_ERR(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_ERX_HIRG_DECODE_DONE(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16, unsigned long v17);
void L1TRC_Send_UL1D_TRC_ERX_AGCH_DEBUG(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_FRAMERATE_INFO(unsigned short v1, unsigned short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_FRAMERATE_RTR_INFO(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_UL_DCH_POW_IND_INT32(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32(unsigned long v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_WFEC_RACH_EN(short v1);
void L1TRC_Send_UL1D_TRC_WFEC_RACH_IRQ_SET(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_WFEC_DCH_IRQ_SET(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_WFEC_DFESYS_BUS_SET(unsigned char v1);
void L1TRC_Send_UL1D_TRC_WFEC_DETREF_BW_SET(short v1);
void L1TRC_Send_UL1D_TRC_WFEC_C2M_DL_TRIG(void);
void L1TRC_Send_UL1D_TRC_WFEC_SHM_DL_INFO(short v1, unsigned long v2, short v3);
void L1TRC_Send_UL1D_TRC_FCM_GAP_START_CASCADE(unsigned short v1, short v2);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_CALC_AVAIL_TIME(unsigned short v1, unsigned short v2, short v3, unsigned short v4, short v5, unsigned short v6, short v7, unsigned short v8, short v9);
void L1TRC_Send_UL1D_TRC_MEAS_TO_GAP_2G(unsigned short v1, short v2);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_FCM_DONE_LISR(void);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_PICH_DONE_LISR(short v1);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_GAP_CHECK_MEAS(unsigned short v1, short v2, unsigned long v3, short v4, unsigned long v5, short v6, short v7);
void L1TRC_Send_UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_MODE(short v1, short v2);
void L1TRC_Send_UL1D_TRC_MEAS_PROHIBITED_TO_CHANGE_FREQ(unsigned short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_ALLOWED(unsigned short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_RUNNING(unsigned short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_MEAS_FREE_RUN_SCHEDULING(unsigned short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_MEAS_ENTER_IDLE(unsigned short v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_STANDBY_FCM_DONE_LISR(void);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_STOP_PICH_TIMER(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_STOP_FCM_TIMER(unsigned short v1);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_RETURN_PICH(void);
void L1TRC_Send_UL1D_TRC_MEAS_FRAME_IDLE(unsigned short v1, short v2, short v3, unsigned long v4);

void Set_UL1D_HSPA_THIRD_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_HSPA_THIRD()	(UL1D_HSPA_THIRD_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_TXUPC_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_TXUPC_DUMP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_RXBRP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_RXBRP_DBG_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_RXBRP_DBG_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_H()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_H()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x40)!=0))
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_HS_DPCCH_SYM_OFFSET()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_CHECK_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_CHECK_ISSUE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_ADDSC_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_ADDSC_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_ADDSC_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_UPC_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_UPC_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_UPC_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT16G()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_L_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_IQDC_COMP_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_IQDC_COMP_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_IQDC_COMP_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_BSI_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_BSI_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_BSI_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_MPR_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_MPR_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_MPR_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_AUX_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_AUX_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_AUX_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_GAIN_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_GAIN_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_GAIN_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DELTA_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DELTA_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DELTA_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RTR_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RTR_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RTR_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DBG_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DBG_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DBG_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_GENERAL_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_LOW_POWER_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_TIME_MAC_R99_DBG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_L()
#define ChkL1MsgFltr_UL1D_TRC_TIME_MAC_R6_DBG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_L()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_L2COPRO_ASSERT()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_0()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_1()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_2()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_3()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_4()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_L2COPRO_DEBUG_INFO_5()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_ENCODE_TIME()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RSLT()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_H()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_RSLT_BITMAP()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_RSLT_BITMAP()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_GAP_CONFIG_AG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_GAP_CONFIG_HI()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_GAP_CONFIG_RG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_SOFT_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_E2_HIRG_MIC_RLS()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_AG_ERR()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HIRG_DECODE_DONE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_AGCH_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_FRAMERATE_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_FRAMERATE_RTR_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_POW_IND_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_WFEC_RACH_EN()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_WFEC_RACH_IRQ_SET()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_WFEC_DCH_IRQ_SET()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_WFEC_DFESYS_BUS_SET()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_WFEC_DETREF_BW_SET()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_WFEC_C2M_DL_TRIG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_WFEC_SHM_DL_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_FCM_GAP_START_CASCADE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_CALC_AVAIL_TIME()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_TO_GAP_2G()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_FCM_DONE_LISR()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_PICH_DONE_LISR()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_GAP_CHECK_MEAS()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_MODE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_PROHIBITED_TO_CHANGE_FREQ()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_ALLOWED()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_RUNNING()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_FREE_RUN_SCHEDULING()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_MEAS_ENTER_IDLE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_STANDBY_FCM_DONE_LISR()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_STOP_PICH_TIMER()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_STOP_FCM_TIMER()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_RETURN_PICH()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_FRAME_IDLE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()


#endif
