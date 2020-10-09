#ifndef L1TRC_PCORE_TPPA_SLEEPDRV_1_DEF_H
#define L1TRC_PCORE_TPPA_SLEEPDRV_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define PCORE_TPPA_SLEEPDRV_Str_Bool(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define PCORE_TPPA_SLEEPDRV_TRC_TIME_SYNC(v1, v2) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0022, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_TIME_SYNC(v1, v2)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_TIME_SYNC_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0022, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PCORE_TPPA_SLEEPDRV_TRC_OSTD(v1, v2) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0122, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_OSTD(v1, v2)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_OSTD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0122, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define PCORE_TPPA_SLEEPDRV_TRC_PWR(v1, v2, v3) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0222, (char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_PWR(v1, v2, v3)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_PWR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0222, (char)(v2), (char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define PCORE_TPPA_SLEEPDRV_TRC_SYSCLK(v1, v2) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0322, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_SYSCLK(v1, v2)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_SYSCLK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0322, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define PCORE_TPPA_SLEEPDRV_TRC_PLL(v1, v2, v3) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0422, (char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_PLL(v1, v2, v3)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_PLL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0422, (char)(v2), (char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define PCORE_TPPA_SLEEPDRV_TRC_VMD1(v1, v2) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0522, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_VMD1(v1, v2)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_VMD1_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0522, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define PCORE_TPPA_SLEEPDRV_TRC_VSRAM(v1, v2) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0622, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_VSRAM(v1, v2)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_VSRAM_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0622, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define PCORE_TPPA_SLEEPDRV_TRC_VMODEM(v1, v2) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0722, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_VMODEM(v1, v2)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_VMODEM_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0722, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define PCORE_TPPA_SLEEPDRV_TRC_CPUFREQ(v1, v2) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0822, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_CPUFREQ(v1, v2)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_CPUFREQ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0822, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define PCORE_TPPA_SLEEPDRV_TRC_CPURATE(v1, v2, v3) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0922, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_CPURATE(v1, v2, v3)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_CPURATE_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0922, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define PCORE_TPPA_SLEEPDRV_TRC_TEMP(v1, v2) do {\
		if(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1 && (PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A22, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2));\
	} while(0)
#else
	#define PCORE_TPPA_SLEEPDRV_TRC_TEMP(v1, v2)
#endif
#define PCORE_TPPA_SLEEPDRV_TRC_TEMP_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A22, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char PCORE_TPPA_SLEEPDRV_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_TIME_SYNC(unsigned long v1, unsigned long v2);
void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_OSTD(unsigned long v1, char v2);
void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_PWR(unsigned long v1, char v2, char v3);
void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_SYSCLK(unsigned long v1, char v2);
void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_PLL(unsigned long v1, char v2, char v3);
void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_VMD1(unsigned long v1, unsigned long v2);
void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_VSRAM(unsigned long v1, unsigned long v2);
void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_VMODEM(unsigned long v1, unsigned long v2);
void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_CPUFREQ(unsigned long v1, unsigned long v2);
void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_CPURATE(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PCORE_TPPA_SLEEPDRV_TRC_TEMP(unsigned long v1, long v2);

void Set_PCORE_TPPA_SLEEPDRV_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_PCORE_TPPA_SLEEPDRV_1()	(PCORE_TPPA_SLEEPDRV_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_H()	(ChkL1ModFltr_PCORE_TPPA_SLEEPDRV_1()&&((PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()	(ChkL1ModFltr_PCORE_TPPA_SLEEPDRV_1()&&((PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_L()	(ChkL1ModFltr_PCORE_TPPA_SLEEPDRV_1()&&((PCORE_TPPA_SLEEPDRV_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_TIME_SYNC()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_OSTD()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_L()
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_PWR()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_SYSCLK()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_PLL()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_VMD1()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_VSRAM()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_VMODEM()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_CPUFREQ()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_CPURATE()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()
#define ChkL1MsgFltr_PCORE_TPPA_SLEEPDRV_TRC_TEMP()	ChkL1ClsFltr_PCORE_TPPA_SLEEPDRV_1_PCORE_TPPA_SLEEPDRV_M()


#endif
