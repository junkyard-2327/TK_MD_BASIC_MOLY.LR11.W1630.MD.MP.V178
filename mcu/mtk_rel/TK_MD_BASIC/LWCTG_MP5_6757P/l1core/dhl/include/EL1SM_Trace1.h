#ifndef L1TRC_EL1SM_1_DEF_H
#define L1TRC_EL1SM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1SM_Str_Locker(v1)  (unsigned char)(v1+0)
#define EL1SM_Str_Bool(v1)  (unsigned char)(v1+10)
#define EL1SM_Str_Enable(v1)  (unsigned char)(v1+12)
#define EL1SM_Str_IdleRate_User(v1)  (unsigned char)(v1+14)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1SM_DBG_CHECK_SM_LOCKER(v1, v2, v3, v4) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0058, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1SM_DBG_CHECK_SM_LOCKER(v1, v2, v3, v4)
#endif
#define EL1SM_DBG_CHECK_SM_LOCKER_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0058, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_Enter_Sleep(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x0158, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1SM_DBG_Enter_Sleep(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1SM_DBG_Enter_Sleep_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x0158, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_SW_Wakeup(v1, v2) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0258, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1SM_DBG_SW_Wakeup(v1, v2)
#endif
#define EL1SM_DBG_SW_Wakeup_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0258, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_Wakeup_IRQ(v1, v2, v3, v4) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0358, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1SM_DBG_Wakeup_IRQ(v1, v2, v3, v4)
#endif
#define EL1SM_DBG_Wakeup_IRQ_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0358, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_CALI_START() do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0458, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1SM_DBG_CALI_START()
#endif
#define EL1SM_DBG_CALI_START_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0458, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_CALI_DONE(v1, v2) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0558, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1SM_DBG_CALI_DONE(v1, v2)
#endif
#define EL1SM_DBG_CALI_DONE_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0558, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_CHECK_CALI() do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0658, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1SM_DBG_CHECK_CALI()
#endif
#define EL1SM_DBG_CHECK_CALI_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0658, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_CHECK_DCXO_DIV() do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0758, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1SM_DBG_CHECK_DCXO_DIV()
#endif
#define EL1SM_DBG_CHECK_DCXO_DIV_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0758, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_Timing_Check_1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x0858, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1SM_DBG_Timing_Check_1(v1, v2, v3, v4, v5, v6)
#endif
#define EL1SM_DBG_Timing_Check_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x0858, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_Timing_Check_2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x0958, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1SM_DBG_Timing_Check_2(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1SM_DBG_Timing_Check_2_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x0958, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_CHECK_SLEEP_1(v1, v2, v3, v4) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A58, (unsigned char)(v2), (unsigned char)(v4)), (unsigned long)(v1), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1SM_DBG_CHECK_SLEEP_1(v1, v2, v3, v4)
#endif
#define EL1SM_DBG_CHECK_SLEEP_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A58, (unsigned char)(v2), (unsigned char)(v4)), (unsigned long)(v1), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_CHECK_SLEEP_2(v1, v2, v3, v4, v5, v6) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0B58, (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1SM_DBG_CHECK_SLEEP_2(v1, v2, v3, v4, v5, v6)
#endif
#define EL1SM_DBG_CHECK_SLEEP_2_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0B58, (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1SM_TRC_DEBUG(v1, v2, v3) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C58, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1SM_TRC_DEBUG(v1, v2, v3)
#endif
#define EL1SM_TRC_DEBUG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C58, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1SM_TRC_DEBUG_HEX(v1, v2, v3) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D58, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1SM_TRC_DEBUG_HEX(v1, v2, v3)
#endif
#define EL1SM_TRC_DEBUG_HEX_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D58, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1SM_TRC_4G_L1IDLERATIO_USERDEF(v1, v2, v3, v4, v5, v6) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0E58, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1SM_TRC_4G_L1IDLERATIO_USERDEF(v1, v2, v3, v4, v5, v6)
#endif
#define EL1SM_TRC_4G_L1IDLERATIO_USERDEF_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0E58, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_32KLESS_WAKEUP(v1, v2) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F58, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1SM_DBG_32KLESS_WAKEUP(v1, v2)
#endif
#define EL1SM_DBG_32KLESS_WAKEUP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F58, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1058, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5)
#endif
#define EL1SM_DBG_32KLESS_UPDATE_LPM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1058, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_COCLK_UPDATE_FreqOffset(v1, v2) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1158, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1SM_DBG_COCLK_UPDATE_FreqOffset(v1, v2)
#endif
#define EL1SM_DBG_COCLK_UPDATE_FreqOffset_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1158, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1258, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1SM_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3)
#endif
#define EL1SM_DBG_COCLK_UPDATE_FMRESULT_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1258, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (unsigned long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1SM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1SM_DBG_CHECK_SM_LOCKER(unsigned char v1, unsigned char v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_EL1SM_DBG_Enter_Sleep(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1SM_DBG_SW_Wakeup(unsigned long v1, unsigned char v2);
void L1TRC_Send_EL1SM_DBG_Wakeup_IRQ(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1SM_DBG_CALI_START(void);
void L1TRC_Send_EL1SM_DBG_CALI_DONE(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1SM_DBG_CHECK_CALI(void);
void L1TRC_Send_EL1SM_DBG_CHECK_DCXO_DIV(void);
void L1TRC_Send_EL1SM_DBG_Timing_Check_1(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1SM_DBG_Timing_Check_2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1SM_DBG_CHECK_SLEEP_1(unsigned long v1, unsigned char v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_EL1SM_DBG_CHECK_SLEEP_2(unsigned long v1, unsigned long v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned short v6);
void L1TRC_Send_EL1SM_TRC_DEBUG(unsigned short v1, long v2, long v3);
void L1TRC_Send_EL1SM_TRC_DEBUG_HEX(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1SM_TRC_4G_L1IDLERATIO_USERDEF(unsigned long v1, unsigned long v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1SM_DBG_32KLESS_WAKEUP(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1SM_DBG_32KLESS_UPDATE_LPM(short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_EL1SM_DBG_COCLK_UPDATE_FreqOffset(long v1, long v2);
void L1TRC_Send_EL1SM_DBG_COCLK_UPDATE_FMRESULT(unsigned long v1, long v2, unsigned long v3);

void Set_EL1SM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1SM_1()	(EL1SM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1SM_1_LTE_SM_H()	(ChkL1ModFltr_EL1SM_1()&&((EL1SM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1SM_1_LTE_SM_L()	(ChkL1ModFltr_EL1SM_1()&&((EL1SM_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_EL1SM_DBG_CHECK_SM_LOCKER()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_Enter_Sleep()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_SW_Wakeup()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_Wakeup_IRQ()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_CALI_START()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_CALI_DONE()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_CHECK_CALI()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_CHECK_DCXO_DIV()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_Timing_Check_1()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_Timing_Check_2()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_CHECK_SLEEP_1()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_CHECK_SLEEP_2()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_TRC_DEBUG()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_TRC_DEBUG_HEX()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_TRC_4G_L1IDLERATIO_USERDEF()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_32KLESS_WAKEUP()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_32KLESS_UPDATE_LPM()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_COCLK_UPDATE_FreqOffset()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_COCLK_UPDATE_FMRESULT()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()


#endif
