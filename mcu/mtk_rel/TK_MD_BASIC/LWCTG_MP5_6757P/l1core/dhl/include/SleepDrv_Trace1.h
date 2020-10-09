#ifndef L1TRC_SleepDrv_1_DEF_H
#define L1TRC_SleepDrv_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define SLEEPDRV_Disable_Bool(v1)  (unsigned char)(v1+0)
#define SLEEPDRV_Str_Modem(v1)  (unsigned char)(v1+2)
#define SLEEPDRV_Str_CCIRQ(v1)  (unsigned char)(v1+5)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define SLEEPDRV_DBG_CHECK_SM_CALLER(v1, v2, v3, v4, v5) do {\
		if(SleepDrv_1_Trace_Filter[0]==1 && (SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x004C, (short)(v3)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define SLEEPDRV_DBG_CHECK_SM_CALLER(v1, v2, v3, v4, v5)
#endif
#define SLEEPDRV_DBG_CHECK_SM_CALLER_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x004C, (short)(v3)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define SLEEPDRV_DBG_CHECK_SM_LOCKER(v1, v2) do {\
		if(SleepDrv_1_Trace_Filter[0]==1 && (SleepDrv_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x014C, (short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define SLEEPDRV_DBG_CHECK_SM_LOCKER(v1, v2)
#endif
#define SLEEPDRV_DBG_CHECK_SM_LOCKER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x014C, (short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define SLEEPDRV_DBG_CHECK_MODEM_LOCKER(v1) do {\
		if(SleepDrv_1_Trace_Filter[0]==1 && (SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x024C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define SLEEPDRV_DBG_CHECK_MODEM_LOCKER(v1)
#endif
#define SLEEPDRV_DBG_CHECK_MODEM_LOCKER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x024C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define SLEEPDRV_DBG_CCIRQ_CMD_TRIG(v1, v2, v3, v4) do {\
		if(SleepDrv_1_Trace_Filter[0]==1 && (SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x034C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define SLEEPDRV_DBG_CCIRQ_CMD_TRIG(v1, v2, v3, v4)
#endif
#define SLEEPDRV_DBG_CCIRQ_CMD_TRIG_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x034C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define SLEEPDRV_DBG_CCIRQ_CMD_RECV(v1, v2, v3, v4) do {\
		if(SleepDrv_1_Trace_Filter[0]==1 && (SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x044C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define SLEEPDRV_DBG_CCIRQ_CMD_RECV(v1, v2, v3, v4)
#endif
#define SLEEPDRV_DBG_CCIRQ_CMD_RECV_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x044C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char SleepDrv_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_SLEEPDRV_DBG_CHECK_SM_CALLER(unsigned long v1, unsigned char v2, short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_SLEEPDRV_DBG_CHECK_SM_LOCKER(short v1, unsigned long v2);
void L1TRC_Send_SLEEPDRV_DBG_CHECK_MODEM_LOCKER(unsigned char v1);
void L1TRC_Send_SLEEPDRV_DBG_CCIRQ_CMD_TRIG(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_SLEEPDRV_DBG_CCIRQ_CMD_RECV(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);

void Set_SleepDrv_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_SleepDrv_1()	(SleepDrv_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_H()	(ChkL1ModFltr_SleepDrv_1()&&((SleepDrv_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_L()	(ChkL1ModFltr_SleepDrv_1()&&((SleepDrv_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_SLEEPDRV_DBG_CHECK_SM_CALLER()	ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_H()
#define ChkL1MsgFltr_SLEEPDRV_DBG_CHECK_SM_LOCKER()	ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_L()
#define ChkL1MsgFltr_SLEEPDRV_DBG_CHECK_MODEM_LOCKER()	ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_H()
#define ChkL1MsgFltr_SLEEPDRV_DBG_CCIRQ_CMD_TRIG()	ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_H()
#define ChkL1MsgFltr_SLEEPDRV_DBG_CCIRQ_CMD_RECV()	ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_H()


#endif
