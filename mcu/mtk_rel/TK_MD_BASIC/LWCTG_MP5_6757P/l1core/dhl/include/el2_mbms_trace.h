#ifndef L1TRC_EMBMS_API_DEF_H
#define L1TRC_EMBMS_API_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_RESET_SYNC_AREA_INIT(v1, v2, v3) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x000A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMBMS_LOG_RESET_SYNC_AREA_INIT(v1, v2, v3)
#endif
#define EMBMS_LOG_RESET_SYNC_AREA_INIT_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x000A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_DELETE_ACTIVE_AREA(v1, v2, v3, v4) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x010A, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMBMS_LOG_DELETE_ACTIVE_AREA(v1, v2, v3, v4)
#endif
#define EMBMS_LOG_DELETE_ACTIVE_AREA_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x010A, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MCCH_CONFIG_INIT(v1, v2, v3, v4) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x020A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMBMS_LOG_MCCH_CONFIG_INIT(v1, v2, v3, v4)
#endif
#define EMBMS_LOG_MCCH_CONFIG_INIT_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x020A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_EXIST_MCCH(v1, v2, v3, v4) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x030A, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMBMS_LOG_EXIST_MCCH(v1, v2, v3, v4)
#endif
#define EMBMS_LOG_EXIST_MCCH_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x030A, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_NEW_CFG_MCCH(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x040A, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v6));\
	} while(0)
#else
	#define EMBMS_LOG_NEW_CFG_MCCH(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EMBMS_LOG_NEW_CFG_MCCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_2S(0x040A, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_ADD_MCCH(v1, v2, v3, v4) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x050A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMBMS_LOG_ADD_MCCH(v1, v2, v3, v4)
#endif
#define EMBMS_LOG_ADD_MCCH_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x050A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_UPDATE_MCCH(v1, v2) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x060A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMBMS_LOG_UPDATE_MCCH(v1, v2)
#endif
#define EMBMS_LOG_UPDATE_MCCH_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x060A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_DELETE_MCCH(v1, v2) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x070A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMBMS_LOG_DELETE_MCCH(v1, v2)
#endif
#define EMBMS_LOG_DELETE_MCCH_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x070A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MCCH_CFG_IDX(v1, v2) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x080A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMBMS_LOG_MCCH_CFG_IDX(v1, v2)
#endif
#define EMBMS_LOG_MCCH_CFG_IDX_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x080A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_PMCH_CONFIG_INIT(v1, v2, v3, v4, v5, v6) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x090A, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EMBMS_LOG_PMCH_CONFIG_INIT(v1, v2, v3, v4, v5, v6)
#endif
#define EMBMS_LOG_PMCH_CONFIG_INIT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x090A, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_PMCH_AREA_ID(v1) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A0A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EMBMS_LOG_PMCH_AREA_ID(v1)
#endif
#define EMBMS_LOG_PMCH_AREA_ID_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A0A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_PMCH_RESET(v1, v2) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0B0A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMBMS_LOG_PMCH_RESET(v1, v2)
#endif
#define EMBMS_LOG_PMCH_RESET_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0B0A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_ADD_PMCH(v1, v2) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C0A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMBMS_LOG_ADD_PMCH(v1, v2)
#endif
#define EMBMS_LOG_ADD_PMCH_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C0A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_PMCH_SF_LIST(v1, v2) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D0A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMBMS_LOG_PMCH_SF_LIST(v1, v2)
#endif
#define EMBMS_LOG_PMCH_SF_LIST_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D0A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_PMCH_CFG_ERR_ALLOC_END(v1, v2, v3) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E0A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3));\
	} while(0)
#else
	#define EMBMS_LOG_PMCH_CFG_ERR_ALLOC_END(v1, v2, v3)
#endif
#define EMBMS_LOG_PMCH_CFG_ERR_ALLOC_END_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E0A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_UPDATE_MSI_INIT(v1, v2, v3, v4, v5) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F0A, (unsigned short)(v5)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMBMS_LOG_UPDATE_MSI_INIT(v1, v2, v3, v4, v5)
#endif
#define EMBMS_LOG_UPDATE_MSI_INIT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F0A, (unsigned short)(v5)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_INVAILD_AREA_INFO_ID() do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x100A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EMBMS_LOG_INVAILD_AREA_INFO_ID()
#endif
#define EMBMS_LOG_INVAILD_AREA_INFO_ID_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x100A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_RECEPTION_MODE_INIT(v1, v2, v3) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x110A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3));\
	} while(0)
#else
	#define EMBMS_LOG_RECEPTION_MODE_INIT(v1, v2, v3)
#endif
#define EMBMS_LOG_RECEPTION_MODE_INIT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x110A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_CFG_RECEPTION_MODE(v1, v2, v3) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x120A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMBMS_LOG_CFG_RECEPTION_MODE(v1, v2, v3)
#endif
#define EMBMS_LOG_CFG_RECEPTION_MODE_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x120A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_QUERY_IDX(v1, v2) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x130A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMBMS_LOG_QUERY_IDX(v1, v2)
#endif
#define EMBMS_LOG_QUERY_IDX_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x130A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_UPDATE_SCHED_INIT(v1, v2, v3, v4, v5) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x140A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EMBMS_LOG_UPDATE_SCHED_INIT(v1, v2, v3, v4, v5)
#endif
#define EMBMS_LOG_UPDATE_SCHED_INIT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x140A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_SCHED_NO_VALID_RESULT(v1) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x150A, (unsigned short)(v1)));\
	} while(0)
#else
	#define EMBMS_LOG_SCHED_NO_VALID_RESULT(v1)
#endif
#define EMBMS_LOG_SCHED_NO_VALID_RESULT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x150A, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_UPDATE_SCHED_RESULT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x160A, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EMBMS_LOG_UPDATE_SCHED_RESULT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EMBMS_LOG_UPDATE_SCHED_RESULT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x160A, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_UPDATE_SCHED_RESULT_GEMINI(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x170A, (unsigned short)(v3)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EMBMS_LOG_UPDATE_SCHED_RESULT_GEMINI(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EMBMS_LOG_UPDATE_SCHED_RESULT_GEMINI_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x170A, (unsigned short)(v3)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MCCH_UPDATE_SCHED(v1, v2, v3, v4, v5) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x180A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EMBMS_LOG_MCCH_UPDATE_SCHED(v1, v2, v3, v4, v5)
#endif
#define EMBMS_LOG_MCCH_UPDATE_SCHED_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x180A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MCCH_SCHED_RESULT(v1, v2, v3, v4) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x190A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMBMS_LOG_MCCH_SCHED_RESULT(v1, v2, v3, v4)
#endif
#define EMBMS_LOG_MCCH_SCHED_RESULT_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x190A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MCCH_SCHED_NEXT(v1, v2, v3, v4) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1A0A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMBMS_LOG_MCCH_SCHED_NEXT(v1, v2, v3, v4)
#endif
#define EMBMS_LOG_MCCH_SCHED_NEXT_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1A0A, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MCCH_NO_VAILD_NEXT() do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B0A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EMBMS_LOG_MCCH_NO_VAILD_NEXT()
#endif
#define EMBMS_LOG_MCCH_NO_VAILD_NEXT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B0A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_RPID_MPID(v1, v2, v3) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C0A, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMBMS_LOG_RPID_MPID(v1, v2, v3)
#endif
#define EMBMS_LOG_RPID_MPID_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C0A, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_FORCE_RECV_MCCH(v1, v2, v3) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D0A, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EMBMS_LOG_FORCE_RECV_MCCH(v1, v2, v3)
#endif
#define EMBMS_LOG_FORCE_RECV_MCCH_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D0A, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_PMCH_UPDATE_SCHED(v1, v2, v3, v4, v5) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1E0A, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EMBMS_LOG_PMCH_UPDATE_SCHED(v1, v2, v3, v4, v5)
#endif
#define EMBMS_LOG_PMCH_UPDATE_SCHED_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1E0A, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_PMCH_SCHED_RESULT(v1, v2, v3, v4, v5) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1F0A, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v5));\
	} while(0)
#else
	#define EMBMS_LOG_PMCH_SCHED_RESULT(v1, v2, v3, v4, v5)
#endif
#define EMBMS_LOG_PMCH_SCHED_RESULT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1F0A, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MSI_HANDLE_CSA_IDX(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x200A, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EMBMS_LOG_MSI_HANDLE_CSA_IDX(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EMBMS_LOG_MSI_HANDLE_CSA_IDX_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x200A, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_PMCH_SCHED_NEXT(v1, v2, v3) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x210A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EMBMS_LOG_PMCH_SCHED_NEXT(v1, v2, v3)
#endif
#define EMBMS_LOG_PMCH_SCHED_NEXT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x210A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_SCHED_NEXT_INIT(v1, v2) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x220A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMBMS_LOG_SCHED_NEXT_INIT(v1, v2)
#endif
#define EMBMS_LOG_SCHED_NEXT_INIT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x220A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_REDUNDANT_SCHED_NEXT(v1) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x230A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EMBMS_LOG_REDUNDANT_SCHED_NEXT(v1)
#endif
#define EMBMS_LOG_REDUNDANT_SCHED_NEXT_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x230A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_SCHED_NEXT_RESULT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x240A, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EMBMS_LOG_SCHED_NEXT_RESULT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EMBMS_LOG_SCHED_NEXT_RESULT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x240A, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_SCHED_NEXT_RESULT_2(v1, v2, v3) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x250A, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EMBMS_LOG_SCHED_NEXT_RESULT_2(v1, v2, v3)
#endif
#define EMBMS_LOG_SCHED_NEXT_RESULT_2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x250A, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_SCHED_NEXT_RESULT_GEMINI(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x260A, (unsigned short)(v3)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EMBMS_LOG_SCHED_NEXT_RESULT_GEMINI(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EMBMS_LOG_SCHED_NEXT_RESULT_GEMINI_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x260A, (unsigned short)(v3)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_NUM_MTCH_RESOURCE(v1, v2, v3) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x270A, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMBMS_LOG_NUM_MTCH_RESOURCE(v1, v2, v3)
#endif
#define EMBMS_LOG_NUM_MTCH_RESOURCE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x270A, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_SIB2_MBSFN_CFG_UPDATE(v1, v2, v3, v4) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x280A, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EMBMS_LOG_SIB2_MBSFN_CFG_UPDATE(v1, v2, v3, v4)
#endif
#define EMBMS_LOG_SIB2_MBSFN_CFG_UPDATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x280A, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_SF_CFG_INVALID_WITH_SIB2(v1, v2) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x290A, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EMBMS_LOG_SF_CFG_INVALID_WITH_SIB2(v1, v2)
#endif
#define EMBMS_LOG_SF_CFG_INVALID_WITH_SIB2_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x290A, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MBSFN_CFG_UNPACK_SF_LIST_PERIOD_RF(v1) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2A0A, (unsigned short)(v1)));\
	} while(0)
#else
	#define EMBMS_LOG_MBSFN_CFG_UNPACK_SF_LIST_PERIOD_RF(v1)
#endif
#define EMBMS_LOG_MBSFN_CFG_UNPACK_SF_LIST_PERIOD_RF_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2A0A, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MBSFN_SF_CONFIG_INFO(v1, v2, v3, v4) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B0A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EMBMS_LOG_MBSFN_SF_CONFIG_INFO(v1, v2, v3, v4)
#endif
#define EMBMS_LOG_MBSFN_SF_CONFIG_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B0A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MBSFN_SF_CONFIG_SF_LIST_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2C0A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EMBMS_LOG_MBSFN_SF_CONFIG_SF_LIST_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EMBMS_LOG_MBSFN_SF_CONFIG_SF_LIST_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2C0A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMBMS_LOG_MCCH_SF_LIST_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EMBMS_API_Trace_Filter[0]==1 && (EMBMS_API_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2D0A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EMBMS_LOG_MCCH_SF_LIST_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EMBMS_LOG_MCCH_SF_LIST_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2D0A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EMBMS_API_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EMBMS_LOG_RESET_SYNC_AREA_INIT(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMBMS_LOG_DELETE_ACTIVE_AREA(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMBMS_LOG_MCCH_CONFIG_INIT(unsigned long v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMBMS_LOG_EXIST_MCCH(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMBMS_LOG_NEW_CFG_MCCH(unsigned short v1, unsigned long v2, unsigned long v3, unsigned short v4, unsigned short v5, unsigned long v6, char v7);
void L1TRC_Send_EMBMS_LOG_ADD_MCCH(unsigned long v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMBMS_LOG_UPDATE_MCCH(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMBMS_LOG_DELETE_MCCH(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMBMS_LOG_MCCH_CFG_IDX(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMBMS_LOG_PMCH_CONFIG_INIT(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EMBMS_LOG_PMCH_AREA_ID(unsigned long v1);
void L1TRC_Send_EMBMS_LOG_PMCH_RESET(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMBMS_LOG_ADD_PMCH(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMBMS_LOG_PMCH_SF_LIST(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMBMS_LOG_PMCH_CFG_ERR_ALLOC_END(unsigned long v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EMBMS_LOG_UPDATE_MSI_INIT(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_EMBMS_LOG_INVAILD_AREA_INFO_ID(void);
void L1TRC_Send_EMBMS_LOG_RECEPTION_MODE_INIT(unsigned long v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EMBMS_LOG_CFG_RECEPTION_MODE(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMBMS_LOG_QUERY_IDX(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMBMS_LOG_UPDATE_SCHED_INIT(unsigned long v1, unsigned short v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EMBMS_LOG_SCHED_NO_VALID_RESULT(unsigned short v1);
void L1TRC_Send_EMBMS_LOG_UPDATE_SCHED_RESULT(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EMBMS_LOG_UPDATE_SCHED_RESULT_GEMINI(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, char v8);
void L1TRC_Send_EMBMS_LOG_MCCH_UPDATE_SCHED(unsigned long v1, unsigned short v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EMBMS_LOG_MCCH_SCHED_RESULT(unsigned long v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMBMS_LOG_MCCH_SCHED_NEXT(unsigned long v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMBMS_LOG_MCCH_NO_VAILD_NEXT(void);
void L1TRC_Send_EMBMS_LOG_RPID_MPID(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMBMS_LOG_FORCE_RECV_MCCH(unsigned short v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EMBMS_LOG_PMCH_UPDATE_SCHED(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EMBMS_LOG_PMCH_SCHED_RESULT(unsigned long v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned long v5);
void L1TRC_Send_EMBMS_LOG_MSI_HANDLE_CSA_IDX(unsigned long v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_EMBMS_LOG_PMCH_SCHED_NEXT(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMBMS_LOG_SCHED_NEXT_INIT(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMBMS_LOG_REDUNDANT_SCHED_NEXT(unsigned long v1);
void L1TRC_Send_EMBMS_LOG_SCHED_NEXT_RESULT(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EMBMS_LOG_SCHED_NEXT_RESULT_2(char v1, unsigned short v2, char v3);
void L1TRC_Send_EMBMS_LOG_SCHED_NEXT_RESULT_GEMINI(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, char v8);
void L1TRC_Send_EMBMS_LOG_NUM_MTCH_RESOURCE(unsigned long v1, unsigned long v2, char v3);
void L1TRC_Send_EMBMS_LOG_SIB2_MBSFN_CFG_UPDATE(unsigned char v1, char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMBMS_LOG_SF_CFG_INVALID_WITH_SIB2(unsigned char v1, char v2);
void L1TRC_Send_EMBMS_LOG_MBSFN_CFG_UNPACK_SF_LIST_PERIOD_RF(unsigned short v1);
void L1TRC_Send_EMBMS_LOG_MBSFN_SF_CONFIG_INFO(unsigned char v1, unsigned char v2, unsigned char v3, char v4);
void L1TRC_Send_EMBMS_LOG_MBSFN_SF_CONFIG_SF_LIST_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EMBMS_LOG_MCCH_SF_LIST_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);

void Set_EMBMS_API_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EMBMS_API()	(EMBMS_API_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()	(ChkL1ModFltr_EMBMS_API()&&((EMBMS_API_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EMBMS_API_EMBMS_DUMP()	(ChkL1ModFltr_EMBMS_API()&&((EMBMS_API_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_EMBMS_LOG_RESET_SYNC_AREA_INIT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_DELETE_ACTIVE_AREA()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_MCCH_CONFIG_INIT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_EXIST_MCCH()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_NEW_CFG_MCCH()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_ADD_MCCH()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_UPDATE_MCCH()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_DELETE_MCCH()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_MCCH_CFG_IDX()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_PMCH_CONFIG_INIT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_PMCH_AREA_ID()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_PMCH_RESET()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_ADD_PMCH()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_PMCH_SF_LIST()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_PMCH_CFG_ERR_ALLOC_END()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_UPDATE_MSI_INIT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_INVAILD_AREA_INFO_ID()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_RECEPTION_MODE_INIT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_CFG_RECEPTION_MODE()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_QUERY_IDX()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_UPDATE_SCHED_INIT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_SCHED_NO_VALID_RESULT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_UPDATE_SCHED_RESULT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_UPDATE_SCHED_RESULT_GEMINI()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_MCCH_UPDATE_SCHED()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_MCCH_SCHED_RESULT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_MCCH_SCHED_NEXT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_MCCH_NO_VAILD_NEXT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_RPID_MPID()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_FORCE_RECV_MCCH()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_PMCH_UPDATE_SCHED()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_PMCH_SCHED_RESULT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_MSI_HANDLE_CSA_IDX()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_PMCH_SCHED_NEXT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_SCHED_NEXT_INIT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_REDUNDANT_SCHED_NEXT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_SCHED_NEXT_RESULT()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_SCHED_NEXT_RESULT_2()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_SCHED_NEXT_RESULT_GEMINI()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_NUM_MTCH_RESOURCE()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_SIB2_MBSFN_CFG_UPDATE()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_SF_CFG_INVALID_WITH_SIB2()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_MBSFN_CFG_UNPACK_SF_LIST_PERIOD_RF()	ChkL1ClsFltr_EMBMS_API_EMBMS_INFO()
#define ChkL1MsgFltr_EMBMS_LOG_MBSFN_SF_CONFIG_INFO()	ChkL1ClsFltr_EMBMS_API_EMBMS_DUMP()
#define ChkL1MsgFltr_EMBMS_LOG_MBSFN_SF_CONFIG_SF_LIST_INFO()	ChkL1ClsFltr_EMBMS_API_EMBMS_DUMP()
#define ChkL1MsgFltr_EMBMS_LOG_MCCH_SF_LIST_INFO()	ChkL1ClsFltr_EMBMS_API_EMBMS_DUMP()


#endif
