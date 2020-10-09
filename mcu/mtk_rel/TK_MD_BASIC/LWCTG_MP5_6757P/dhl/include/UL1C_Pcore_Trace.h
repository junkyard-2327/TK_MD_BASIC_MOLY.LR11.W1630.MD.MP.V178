#ifndef L1TRC_UL1C_PRI_PCORE_DEF_H
#define L1TRC_UL1C_PRI_PCORE_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1PcoreI_TRC_PutHISRQueue(v1, v2, v3) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0016, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1PcoreI_TRC_PutHISRQueue(v1, v2, v3)
#endif
#define UL1PcoreI_TRC_PutHISRQueue_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0016, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1PcoreT_TRC_ControlInit() do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0116, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1PcoreT_TRC_ControlInit()
#endif
#define UL1PcoreT_TRC_ControlInit_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0116, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1PcoreT_TRC_GetCurrentTime(v1, v2) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0216, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1PcoreT_TRC_GetCurrentTime(v1, v2)
#endif
#define UL1PcoreT_TRC_GetCurrentTime_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0216, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1PcoreT_TRC_CEDCHCheckStarted(v1) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0316, (short)(v1)));\
	} while(0)
#else
	#define UL1PcoreT_TRC_CEDCHCheckStarted(v1)
#endif
#define UL1PcoreT_TRC_CEDCHCheckStarted_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0316, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1PcoreT_TRC_CurrAndPendingConfigTGPS(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0416, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1PcoreT_TRC_CurrAndPendingConfigTGPS(v1, v2, v3, v4, v5, v6)
#endif
#define UL1PcoreT_TRC_CurrAndPendingConfigTGPS_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0416, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1PcoreT_TRC_PendingConfigTGPS_byTGPSI(v1, v2) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0516, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1PcoreT_TRC_PendingConfigTGPS_byTGPSI(v1, v2)
#endif
#define UL1PcoreT_TRC_PendingConfigTGPS_byTGPSI_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0516, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1PcoreT_TRC_CurrAndPendingTGPS_Status_byTGMP(v1, v2) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0616, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1PcoreT_TRC_CurrAndPendingTGPS_Status_byTGMP(v1, v2)
#endif
#define UL1PcoreT_TRC_CurrAndPendingTGPS_Status_byTGMP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0616, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1PcoreT_TRC_FreeDLDataBuffer(v1) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0716, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1PcoreT_TRC_FreeDLDataBuffer(v1)
#endif
#define UL1PcoreT_TRC_FreeDLDataBuffer_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0716, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1PcoreI_TRC_FreeDLDataReport(v1) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0816, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1PcoreI_TRC_FreeDLDataReport(v1)
#endif
#define UL1PcoreI_TRC_FreeDLDataReport_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0816, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1PcoreI_TRC_DLDataReportHandler0(v1) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0916, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1PcoreI_TRC_DLDataReportHandler0(v1)
#endif
#define UL1PcoreI_TRC_DLDataReportHandler0_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0916, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1PcoreI_TRC_DLDataReportHandler1(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1PcoreI_TRC_DLDataReportHandler1(v1, v2, v3, v4, v5)
#endif
#define UL1PcoreI_TRC_DLDataReportHandler1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1PcoreI_TRC_DLDataReportHandler2(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1PcoreI_TRC_DLDataReportHandler2(v1, v2, v3, v4, v5)
#endif
#define UL1PcoreI_TRC_DLDataReportHandler2_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1PcoreI_TRC_DLDataReportHandler3(v1, v2, v3) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1PcoreI_TRC_DLDataReportHandler3(v1, v2, v3)
#endif
#define UL1PcoreI_TRC_DLDataReportHandler3_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1PcoreI_TRC_DLDataReportHandler4(v1, v2, v3, v4) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1PcoreI_TRC_DLDataReportHandler4(v1, v2, v3, v4)
#endif
#define UL1PcoreI_TRC_DLDataReportHandler4_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1PcoreI_TRC_PhyMsgHandler(v1) do {\
		if(UL1C_PRI_PCORE_Trace_Filter[0]==1 && (UL1C_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E16, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1PcoreI_TRC_PhyMsgHandler(v1)
#endif
#define UL1PcoreI_TRC_PhyMsgHandler_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E16, (char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1C_PRI_PCORE_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1PcoreI_TRC_PutHISRQueue(long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1PcoreT_TRC_ControlInit(void);
void L1TRC_Send_UL1PcoreT_TRC_GetCurrentTime(short v1, short v2);
void L1TRC_Send_UL1PcoreT_TRC_CEDCHCheckStarted(short v1);
void L1TRC_Send_UL1PcoreT_TRC_CurrAndPendingConfigTGPS(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1PcoreT_TRC_PendingConfigTGPS_byTGPSI(short v1, short v2);
void L1TRC_Send_UL1PcoreT_TRC_CurrAndPendingTGPS_Status_byTGMP(short v1, short v2);
void L1TRC_Send_UL1PcoreT_TRC_FreeDLDataBuffer(unsigned long v1);
void L1TRC_Send_UL1PcoreI_TRC_FreeDLDataReport(unsigned long v1);
void L1TRC_Send_UL1PcoreI_TRC_DLDataReportHandler0(unsigned long v1);
void L1TRC_Send_UL1PcoreI_TRC_DLDataReportHandler1(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1PcoreI_TRC_DLDataReportHandler2(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1PcoreI_TRC_DLDataReportHandler3(short v1, short v2, short v3);
void L1TRC_Send_UL1PcoreI_TRC_DLDataReportHandler4(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1PcoreI_TRC_PhyMsgHandler(char v1);

void Set_UL1C_PRI_PCORE_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1C_PRI_PCORE()	(UL1C_PRI_PCORE_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_CORE_H()	(ChkL1ModFltr_UL1C_PRI_PCORE()&&((UL1C_PRI_PCORE_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_CTRL_H()	(ChkL1ModFltr_UL1C_PRI_PCORE()&&((UL1C_PRI_PCORE_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_DATA_H()	(ChkL1ModFltr_UL1C_PRI_PCORE()&&((UL1C_PRI_PCORE_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_UL1PcoreI_TRC_PutHISRQueue()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_CORE_H()
#define ChkL1MsgFltr_UL1PcoreT_TRC_ControlInit()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_CTRL_H()
#define ChkL1MsgFltr_UL1PcoreT_TRC_GetCurrentTime()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_CTRL_H()
#define ChkL1MsgFltr_UL1PcoreT_TRC_CEDCHCheckStarted()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_CTRL_H()
#define ChkL1MsgFltr_UL1PcoreT_TRC_CurrAndPendingConfigTGPS()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_CTRL_H()
#define ChkL1MsgFltr_UL1PcoreT_TRC_PendingConfigTGPS_byTGPSI()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_CTRL_H()
#define ChkL1MsgFltr_UL1PcoreT_TRC_CurrAndPendingTGPS_Status_byTGMP()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_CTRL_H()
#define ChkL1MsgFltr_UL1PcoreT_TRC_FreeDLDataBuffer()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_DATA_H()
#define ChkL1MsgFltr_UL1PcoreI_TRC_FreeDLDataReport()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_DATA_H()
#define ChkL1MsgFltr_UL1PcoreI_TRC_DLDataReportHandler0()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_DATA_H()
#define ChkL1MsgFltr_UL1PcoreI_TRC_DLDataReportHandler1()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_DATA_H()
#define ChkL1MsgFltr_UL1PcoreI_TRC_DLDataReportHandler2()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_DATA_H()
#define ChkL1MsgFltr_UL1PcoreI_TRC_DLDataReportHandler3()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_DATA_H()
#define ChkL1MsgFltr_UL1PcoreI_TRC_DLDataReportHandler4()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_DATA_H()
#define ChkL1MsgFltr_UL1PcoreI_TRC_PhyMsgHandler()	ChkL1ClsFltr_UL1C_PRI_PCORE_UL1C_PCORE_DATA_H()


#endif
