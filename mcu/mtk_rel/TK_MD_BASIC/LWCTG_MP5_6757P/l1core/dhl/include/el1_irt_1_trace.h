#ifndef L1TRC_EL1_IRT_1_DEF_H
#define L1TRC_EL1_IRT_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define RF_CONFLICT_RAT_String(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_RF_CONFLICT(v1, v2) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0004, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define IRT_LOG_RF_CONFLICT(v1, v2)
#endif
#define IRT_LOG_RF_CONFLICT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0004, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_RF_CONFLICT_RAT(v1, v2, v3) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0104, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IRT_LOG_RF_CONFLICT_RAT(v1, v2, v3)
#endif
#define IRT_LOG_RF_CONFLICT_RAT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0104, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_RF_CONFLICT_STRT(v1, v2, v3) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0204, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define IRT_LOG_RF_CONFLICT_STRT(v1, v2, v3)
#endif
#define IRT_LOG_RF_CONFLICT_STRT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0204, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_RF_CONFLICT_STOP(v1, v2, v3) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0304, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define IRT_LOG_RF_CONFLICT_STOP(v1, v2, v3)
#endif
#define IRT_LOG_RF_CONFLICT_STOP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0304, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_SWITCH_AFC_CONTROL(v1, v2) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0404, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define IRT_LOG_SWITCH_AFC_CONTROL(v1, v2)
#endif
#define IRT_LOG_SWITCH_AFC_CONTROL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0404, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_MULTI_AFC_QUERY(v1, v2, v3, v4) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0504, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (long)(v4));\
	} while(0)
#else
	#define IRT_LOG_MULTI_AFC_QUERY(v1, v2, v3, v4)
#endif
#define IRT_LOG_MULTI_AFC_QUERY_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0504, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_AGPS_TIME_SYNC(v1, v2, v3) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0604, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3));\
	} while(0)
#else
	#define IRT_LOG_AGPS_TIME_SYNC(v1, v2, v3)
#endif
#define IRT_LOG_AGPS_TIME_SYNC_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0604, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_AGPS_SYNC(v1, v2) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0704, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define IRT_LOG_AGPS_SYNC(v1, v2)
#endif
#define IRT_LOG_AGPS_SYNC_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0704, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_AGPS_PHYTIME(v1, v2) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0804, (unsigned short)(v2)), (unsigned long)(v1));\
	} while(0)
#else
	#define IRT_LOG_AGPS_PHYTIME(v1, v2)
#endif
#define IRT_LOG_AGPS_PHYTIME_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0804, (unsigned short)(v2)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_SRVCC_GAP_INFO_1(v1, v2) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0904, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define IRT_LOG_SRVCC_GAP_INFO_1(v1, v2)
#endif
#define IRT_LOG_SRVCC_GAP_INFO_1_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0904, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_SRVCC_GAP_INFO_2(v1, v2, v3, v4) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0A04, (unsigned short)(v4)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IRT_LOG_SRVCC_GAP_INFO_2(v1, v2, v3, v4)
#endif
#define IRT_LOG_SRVCC_GAP_INFO_2_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0A04, (unsigned short)(v4)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_SRVCC_PROCESS_1(v1, v2) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B04, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define IRT_LOG_SRVCC_PROCESS_1(v1, v2)
#endif
#define IRT_LOG_SRVCC_PROCESS_1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B04, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_IRT_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_IRT_LOG_RF_CONFLICT(unsigned long v1, unsigned long v2);
void L1TRC_Send_IRT_LOG_RF_CONFLICT_RAT(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IRT_LOG_RF_CONFLICT_STRT(unsigned char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_IRT_LOG_RF_CONFLICT_STOP(unsigned char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_IRT_LOG_SWITCH_AFC_CONTROL(unsigned short v1, unsigned short v2);
void L1TRC_Send_IRT_LOG_MULTI_AFC_QUERY(unsigned short v1, unsigned short v2, unsigned short v3, long v4);
void L1TRC_Send_IRT_LOG_AGPS_TIME_SYNC(unsigned long v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_IRT_LOG_AGPS_SYNC(unsigned long v1, unsigned long v2);
void L1TRC_Send_IRT_LOG_AGPS_PHYTIME(unsigned long v1, unsigned short v2);
void L1TRC_Send_IRT_LOG_SRVCC_GAP_INFO_1(unsigned long v1, unsigned long v2);
void L1TRC_Send_IRT_LOG_SRVCC_GAP_INFO_2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_IRT_LOG_SRVCC_PROCESS_1(unsigned short v1, unsigned short v2);

void Set_EL1_IRT_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_IRT_1()	(EL1_IRT_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()	(ChkL1ModFltr_EL1_IRT_1()&&((EL1_IRT_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_IRT_LOG_RF_CONFLICT()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_RF_CONFLICT_RAT()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_RF_CONFLICT_STRT()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_RF_CONFLICT_STOP()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_SWITCH_AFC_CONTROL()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_MULTI_AFC_QUERY()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_AGPS_TIME_SYNC()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_AGPS_SYNC()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_AGPS_PHYTIME()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_SRVCC_GAP_INFO_1()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_SRVCC_GAP_INFO_2()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_SRVCC_PROCESS_1()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()


#endif
