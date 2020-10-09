#ifndef L1TRC_EL1_TSTM_2_DEF_H
#define L1TRC_EL1_TSTM_2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define TSTM_NSFT_St_String(v1)  (unsigned char)(v1+0)
#define TSTM_SFBD_Mode_String(v1)  (unsigned char)(v1+6)
#define TSTM_Inject_String(v1)  (unsigned char)(v1+10)
#define TSTM_Rpt_String(v1)  (unsigned char)(v1+11)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NSFT_ST(v1) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0009, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_NSFT_ST(v1)
#endif
#define TSTM_LOG_NSFT_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0009, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NSFT_NEXT_STATE(v1) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0109, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_NSFT_NEXT_STATE(v1)
#endif
#define TSTM_LOG_NSFT_NEXT_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0109, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NSFT_NEXT_DUPLEX_TIME(v1) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0209, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_NSFT_NEXT_DUPLEX_TIME(v1)
#endif
#define TSTM_LOG_NSFT_NEXT_DUPLEX_TIME_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0209, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NSFT_TX_TRIG_CHK() do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0309, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_NSFT_TX_TRIG_CHK()
#endif
#define TSTM_LOG_NSFT_TX_TRIG_CHK_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0309, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NSFT_LIST_SET_TX_TRIG(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0409, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_NSFT_LIST_SET_TX_TRIG(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_NSFT_LIST_SET_TX_TRIG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0409, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NSFT_CHNG_BAND_FREQ(v1, v2, v3) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0509, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_NSFT_CHNG_BAND_FREQ(v1, v2, v3)
#endif
#define TSTM_LOG_NSFT_CHNG_BAND_FREQ_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0509, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NSFT_STEP_SWITCH_TIME(v1, v2) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0609, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_NSFT_STEP_SWITCH_TIME(v1, v2)
#endif
#define TSTM_LOG_NSFT_STEP_SWITCH_TIME_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0609, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NSFT_RE_SYNC_TIME(v1) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0709, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_NSFT_RE_SYNC_TIME(v1)
#endif
#define TSTM_LOG_NSFT_RE_SYNC_TIME_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0709, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NSFT_TX_TRIGG_END() do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0809, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_NSFT_TX_TRIGG_END()
#endif
#define TSTM_LOG_NSFT_TX_TRIGG_END_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0809, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NEXT_DUPLEX_TIME(v1, v2) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0909, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define TSTM_LOG_NEXT_DUPLEX_TIME(v1, v2)
#endif
#define TSTM_LOG_NEXT_DUPLEX_TIME_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0909, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NEXT_TX_TRIGGER_TIME(v1, v2) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A09, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define TSTM_LOG_NEXT_TX_TRIGGER_TIME(v1, v2)
#endif
#define TSTM_LOG_NEXT_TX_TRIGGER_TIME_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A09, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RESYNC_CNT(v1) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B09, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_RESYNC_CNT(v1)
#endif
#define TSTM_LOG_RESYNC_CNT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B09, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NBR_MEAS_DUMP_0(v1, v2, v3, v4) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C09, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_NBR_MEAS_DUMP_0(v1, v2, v3, v4)
#endif
#define TSTM_LOG_NBR_MEAS_DUMP_0_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C09, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_SRV_MEAS_PERIOD(v1, v2) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D09, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_SRV_MEAS_PERIOD(v1, v2)
#endif
#define TSTM_LOG_SET_SRV_MEAS_PERIOD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D09, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SFBD_RPT(v1, v2, v3, v4) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E09, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SFBD_RPT(v1, v2, v3, v4)
#endif
#define TSTM_LOG_SFBD_RPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E09, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_VZW_REQ_CMD(v1, v2, v3, v4) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F09, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_VZW_REQ_CMD(v1, v2, v3, v4)
#endif
#define TSTM_LOG_VZW_REQ_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F09, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_VZW_MEAS_RLT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1009, (unsigned short)(v1)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_VZW_MEAS_RLT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define TSTM_LOG_VZW_MEAS_RLT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1009, (unsigned short)(v1)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_INJECT_STRING(v1, v2) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1109, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_INJECT_STRING(v1, v2)
#endif
#define TSTM_LOG_INJECT_STRING_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1109, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_EICIC_MSG() do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1209, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_EICIC_MSG()
#endif
#define TSTM_LOG_EICIC_MSG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1209, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_TX_REPORT_IND(v1) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1309, (short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_TX_REPORT_IND(v1)
#endif
#define TSTM_LOG_TX_REPORT_IND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1309, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_TX_REPORT_NOT_IN_FLIGHT() do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1409, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_TX_REPORT_NOT_IN_FLIGHT()
#endif
#define TSTM_LOG_TX_REPORT_NOT_IN_FLIGHT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1409, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_LISR_RPT(v1) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1509, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_LISR_RPT(v1)
#endif
#define TSTM_LOG_LISR_RPT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1509, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_TASK_RPT(v1) do {\
		if(EL1_TSTM_2_Trace_Filter[0]==1 && (EL1_TSTM_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1609, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_TASK_RPT(v1)
#endif
#define TSTM_LOG_TASK_RPT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1609, (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_TSTM_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_TSTM_LOG_NSFT_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_NSFT_NEXT_STATE(unsigned char v1);
void L1TRC_Send_TSTM_LOG_NSFT_NEXT_DUPLEX_TIME(unsigned short v1);
void L1TRC_Send_TSTM_LOG_NSFT_TX_TRIG_CHK(void);
void L1TRC_Send_TSTM_LOG_NSFT_LIST_SET_TX_TRIG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, short v6);
void L1TRC_Send_TSTM_LOG_NSFT_CHNG_BAND_FREQ(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_NSFT_STEP_SWITCH_TIME(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_NSFT_RE_SYNC_TIME(unsigned short v1);
void L1TRC_Send_TSTM_LOG_NSFT_TX_TRIGG_END(void);
void L1TRC_Send_TSTM_LOG_NEXT_DUPLEX_TIME(unsigned long v1, unsigned long v2);
void L1TRC_Send_TSTM_LOG_NEXT_TX_TRIGGER_TIME(unsigned long v1, unsigned long v2);
void L1TRC_Send_TSTM_LOG_RESYNC_CNT(unsigned short v1);
void L1TRC_Send_TSTM_LOG_NBR_MEAS_DUMP_0(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_SET_SRV_MEAS_PERIOD(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_SFBD_RPT(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_VZW_REQ_CMD(unsigned short v1, unsigned char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_VZW_MEAS_RLT(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4, short v5, short v6, unsigned short v7);
void L1TRC_Send_TSTM_LOG_INJECT_STRING(unsigned char v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_EICIC_MSG(void);
void L1TRC_Send_TSTM_LOG_TX_REPORT_IND(short v1);
void L1TRC_Send_TSTM_LOG_TX_REPORT_NOT_IN_FLIGHT(void);
void L1TRC_Send_TSTM_LOG_LISR_RPT(unsigned char v1);
void L1TRC_Send_TSTM_LOG_TASK_RPT(unsigned char v1);

void Set_EL1_TSTM_2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_TSTM_2()	(EL1_TSTM_2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_func_trace()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_func_trace_1()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace_l()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_var2_trace()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_var2_trace_l()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_var3_trace()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_var3_trace_l()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_flow_trace()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_flow_trace_l()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_error_trace()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_msg_trace()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1_TSTM_2_tstm_debug_trace()	(ChkL1ModFltr_EL1_TSTM_2()&&((EL1_TSTM_2_Trace_Filter[2]&0x10)!=0))
#define ChkL1MsgFltr_TSTM_LOG_NSFT_ST()	ChkL1ClsFltr_EL1_TSTM_2_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_NSFT_NEXT_STATE()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NSFT_NEXT_DUPLEX_TIME()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NSFT_TX_TRIG_CHK()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NSFT_LIST_SET_TX_TRIG()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NSFT_CHNG_BAND_FREQ()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NSFT_STEP_SWITCH_TIME()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NSFT_RE_SYNC_TIME()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NSFT_TX_TRIGG_END()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NEXT_DUPLEX_TIME()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NEXT_TX_TRIGGER_TIME()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_RESYNC_CNT()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NBR_MEAS_DUMP_0()	ChkL1ClsFltr_EL1_TSTM_2_tstm_debug_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_SRV_MEAS_PERIOD()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SFBD_RPT()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_VZW_REQ_CMD()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_VZW_MEAS_RLT()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_INJECT_STRING()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_EICIC_MSG()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_TX_REPORT_IND()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_TX_REPORT_NOT_IN_FLIGHT()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_LISR_RPT()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_TASK_RPT()	ChkL1ClsFltr_EL1_TSTM_2_tstm_var_trace()


#endif
