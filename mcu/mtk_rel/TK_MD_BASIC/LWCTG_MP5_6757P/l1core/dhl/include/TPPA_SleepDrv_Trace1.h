#ifndef L1TRC_TPPA_SleepDrv_1_DEF_H
#define L1TRC_TPPA_SleepDrv_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define TPPA_SleepDrv_Str_Bool(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TPPA_TRC_OSTD_TME_STA(v1, v2) do {\
		if(TPPA_SleepDrv_1_Trace_Filter[0]==1 && (TPPA_SleepDrv_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0050, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define TPPA_TRC_OSTD_TME_STA(v1, v2)
#endif
#define TPPA_TRC_OSTD_TME_STA_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0050, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define TPPA_TRC_OSTD_CPU_RATE(v1, v2, v3) do {\
		if(TPPA_SleepDrv_1_Trace_Filter[0]==1 && (TPPA_SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0150, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TPPA_TRC_OSTD_CPU_RATE(v1, v2, v3)
#endif
#define TPPA_TRC_OSTD_CPU_RATE_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0150, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TPPA_TRC_DVFS_VMODEM(v1, v2) do {\
		if(TPPA_SleepDrv_1_Trace_Filter[0]==1 && (TPPA_SleepDrv_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0250, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define TPPA_TRC_DVFS_VMODEM(v1, v2)
#endif
#define TPPA_TRC_DVFS_VMODEM_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0250, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TPPA_TRC_DVFS_CPUFREQ(v1, v2) do {\
		if(TPPA_SleepDrv_1_Trace_Filter[0]==1 && (TPPA_SleepDrv_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0350, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define TPPA_TRC_DVFS_CPUFREQ(v1, v2)
#endif
#define TPPA_TRC_DVFS_CPUFREQ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0350, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define TPPA_TRC_MODEM_TOPSM_POWER(v1, v2, v3) do {\
		if(TPPA_SleepDrv_1_Trace_Filter[0]==1 && (TPPA_SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0450, (char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define TPPA_TRC_MODEM_TOPSM_POWER(v1, v2, v3)
#endif
#define TPPA_TRC_MODEM_TOPSM_POWER_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0450, (char)(v2), (char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define TPPA_TRC_MODEM_TOPSM_PLLCK(v1, v2, v3) do {\
		if(TPPA_SleepDrv_1_Trace_Filter[0]==1 && (TPPA_SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0550, (char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define TPPA_TRC_MODEM_TOPSM_PLLCK(v1, v2, v3)
#endif
#define TPPA_TRC_MODEM_TOPSM_PLLCK_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0550, (char)(v2), (char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define TPPA_TRC_MODEM_TOPSM_SYSTEMCLK(v1, v2, v3) do {\
		if(TPPA_SleepDrv_1_Trace_Filter[0]==1 && (TPPA_SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0650, (char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define TPPA_TRC_MODEM_TOPSM_SYSTEMCLK(v1, v2, v3)
#endif
#define TPPA_TRC_MODEM_TOPSM_SYSTEMCLK_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0650, (char)(v2), (char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define TPPA_TRC_RM_RESOURCE_CONTROL(v1, v2, v3) do {\
		if(TPPA_SleepDrv_1_Trace_Filter[0]==1 && (TPPA_SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0750, (char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define TPPA_TRC_RM_RESOURCE_CONTROL(v1, v2, v3)
#endif
#define TPPA_TRC_RM_RESOURCE_CONTROL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0750, (char)(v2), (char)(v3)), (unsigned long)(v1))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char TPPA_SleepDrv_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_TPPA_TRC_OSTD_TME_STA(unsigned long v1, char v2);
void L1TRC_Send_TPPA_TRC_OSTD_CPU_RATE(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_TPPA_TRC_DVFS_VMODEM(unsigned long v1, unsigned long v2);
void L1TRC_Send_TPPA_TRC_DVFS_CPUFREQ(unsigned long v1, unsigned long v2);
void L1TRC_Send_TPPA_TRC_MODEM_TOPSM_POWER(unsigned long v1, char v2, char v3);
void L1TRC_Send_TPPA_TRC_MODEM_TOPSM_PLLCK(unsigned long v1, char v2, char v3);
void L1TRC_Send_TPPA_TRC_MODEM_TOPSM_SYSTEMCLK(unsigned long v1, char v2, char v3);
void L1TRC_Send_TPPA_TRC_RM_RESOURCE_CONTROL(unsigned long v1, char v2, char v3);

void Set_TPPA_SleepDrv_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_TPPA_SleepDrv_1()	(TPPA_SleepDrv_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_H()	(ChkL1ModFltr_TPPA_SleepDrv_1()&&((TPPA_SleepDrv_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_M()	(ChkL1ModFltr_TPPA_SleepDrv_1()&&((TPPA_SleepDrv_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_L()	(ChkL1ModFltr_TPPA_SleepDrv_1()&&((TPPA_SleepDrv_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_TPPA_TRC_OSTD_TME_STA()	ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_L()
#define ChkL1MsgFltr_TPPA_TRC_OSTD_CPU_RATE()	ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_H()
#define ChkL1MsgFltr_TPPA_TRC_DVFS_VMODEM()	ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_L()
#define ChkL1MsgFltr_TPPA_TRC_DVFS_CPUFREQ()	ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_L()
#define ChkL1MsgFltr_TPPA_TRC_MODEM_TOPSM_POWER()	ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_H()
#define ChkL1MsgFltr_TPPA_TRC_MODEM_TOPSM_PLLCK()	ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_H()
#define ChkL1MsgFltr_TPPA_TRC_MODEM_TOPSM_SYSTEMCLK()	ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_H()
#define ChkL1MsgFltr_TPPA_TRC_RM_RESOURCE_CONTROL()	ChkL1ClsFltr_TPPA_SleepDrv_1_TPPA_SleepDrv_H()


#endif
