#ifndef L1TRC_OSTD_1_DEF_H
#define L1TRC_OSTD_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define OSTD_TIMER_TYPE_Str(v1)  (unsigned char)(v1+0)
#define OSTD_Str_Bool(v1)  (unsigned char)(v1+5)
#define OSTD_Str_Pause_Req(v1)  (unsigned char)(v1+7)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define OSTD_TRC_DEBUG1(v1, v2, v3) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x004A, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define OSTD_TRC_DEBUG1(v1, v2, v3)
#endif
#define OSTD_TRC_DEBUG1_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x004A, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define OSTD_TRC_DEBUG2(v1, v2, v3) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x014A, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define OSTD_TRC_DEBUG2(v1, v2, v3)
#endif
#define OSTD_TRC_DEBUG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x014A, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define OSTD_SM_STATUS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x024A, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define OSTD_SM_STATUS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define OSTD_SM_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_2S(0x024A, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define OSTD_SM_STATUS_DBG(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x034A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define OSTD_SM_STATUS_DBG(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define OSTD_SM_STATUS_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x034A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define OSTD_SM_STATUS2(v1, v2, v3, v4) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x044A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define OSTD_SM_STATUS2(v1, v2, v3, v4)
#endif
#define OSTD_SM_STATUS2_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x044A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define OSTD_FM_STATUS(v1, v2, v3, v4, v5, v6) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x054A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define OSTD_FM_STATUS(v1, v2, v3, v4, v5, v6)
#endif
#define OSTD_FM_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x054A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define OSTD_TRC_INF_SLEEP_TRG(v1) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x064A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define OSTD_TRC_INF_SLEEP_TRG(v1)
#endif
#define OSTD_TRC_INF_SLEEP_TRG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x064A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define OSTD_TRC_INF_SLEEP_TIMER_CB(v1, v2, v3) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x074A, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define OSTD_TRC_INF_SLEEP_TIMER_CB(v1, v2, v3)
#endif
#define OSTD_TRC_INF_SLEEP_TIMER_CB_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x074A, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char OSTD_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_OSTD_TRC_DEBUG1(unsigned short v1, long v2, long v3);
void L1TRC_Send_OSTD_TRC_DEBUG2(unsigned short v1, long v2, long v3);
void L1TRC_Send_OSTD_SM_STATUS(unsigned short v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_OSTD_SM_STATUS_DBG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_OSTD_SM_STATUS2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_OSTD_FM_STATUS(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_OSTD_TRC_INF_SLEEP_TRG(unsigned long v1);
void L1TRC_Send_OSTD_TRC_INF_SLEEP_TIMER_CB(unsigned char v1, unsigned char v2, unsigned long v3);

void Set_OSTD_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_OSTD_1()	(OSTD_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_OSTD_1_OSTD_DBG_L()	(ChkL1ModFltr_OSTD_1()&&((OSTD_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_OSTD_1_OSTD_SM_H()	(ChkL1ModFltr_OSTD_1()&&((OSTD_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_OSTD_1_OSTD_IS_H()	(ChkL1ModFltr_OSTD_1()&&((OSTD_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_OSTD_TRC_DEBUG1()	ChkL1ClsFltr_OSTD_1_OSTD_DBG_L()
#define ChkL1MsgFltr_OSTD_TRC_DEBUG2()	ChkL1ClsFltr_OSTD_1_OSTD_DBG_L()
#define ChkL1MsgFltr_OSTD_SM_STATUS()	ChkL1ClsFltr_OSTD_1_OSTD_SM_H()
#define ChkL1MsgFltr_OSTD_SM_STATUS_DBG()	ChkL1ClsFltr_OSTD_1_OSTD_SM_H()
#define ChkL1MsgFltr_OSTD_SM_STATUS2()	ChkL1ClsFltr_OSTD_1_OSTD_SM_H()
#define ChkL1MsgFltr_OSTD_FM_STATUS()	ChkL1ClsFltr_OSTD_1_OSTD_SM_H()
#define ChkL1MsgFltr_OSTD_TRC_INF_SLEEP_TRG()	ChkL1ClsFltr_OSTD_1_OSTD_IS_H()
#define ChkL1MsgFltr_OSTD_TRC_INF_SLEEP_TIMER_CB()	ChkL1ClsFltr_OSTD_1_OSTD_IS_H()


#endif
