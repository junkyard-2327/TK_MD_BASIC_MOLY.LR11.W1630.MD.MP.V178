#ifndef L1TRC_GL1_PCORE_DEF_H
#define L1TRC_GL1_PCORE_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_CCIRQ_Handler(v1, v2, v3) do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0017, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define GL1_PCORE_TRC_CCIRQ_Handler(v1, v2, v3)
#endif
#define GL1_PCORE_TRC_CCIRQ_Handler_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0017, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_CCIRQ_SACCH_UPLINK(v1, v2, v3, v4) do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0117, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define GL1_PCORE_TRC_CCIRQ_SACCH_UPLINK(v1, v2, v3, v4)
#endif
#define GL1_PCORE_TRC_CCIRQ_SACCH_UPLINK_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0117, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_CCIRQ_SDCCH_UPLINK(v1, v2, v3, v4) do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0217, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define GL1_PCORE_TRC_CCIRQ_SDCCH_UPLINK(v1, v2, v3, v4)
#endif
#define GL1_PCORE_TRC_CCIRQ_SDCCH_UPLINK_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0217, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_CCIRQ_FACCH_UPLINK(v1, v2, v3, v4) do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0317, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define GL1_PCORE_TRC_CCIRQ_FACCH_UPLINK(v1, v2, v3, v4)
#endif
#define GL1_PCORE_TRC_CCIRQ_FACCH_UPLINK_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0317, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_CCIRQ_UPLINK_TRANSFER(v1, v2, v3, v4) do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0417, (unsigned char)(v4), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define GL1_PCORE_TRC_CCIRQ_UPLINK_TRANSFER(v1, v2, v3, v4)
#endif
#define GL1_PCORE_TRC_CCIRQ_UPLINK_TRANSFER_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0417, (unsigned char)(v4), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_MAIN_Init() do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0517, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define GL1_PCORE_TRC_MAIN_Init()
#endif
#define GL1_PCORE_TRC_MAIN_Init_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0517, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_MAIN_SACCH_DOWNLINK() do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0617, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define GL1_PCORE_TRC_MAIN_SACCH_DOWNLINK()
#endif
#define GL1_PCORE_TRC_MAIN_SACCH_DOWNLINK_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0617, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_MAIN_SDCCH_DOWNLINK() do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0717, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define GL1_PCORE_TRC_MAIN_SDCCH_DOWNLINK()
#endif
#define GL1_PCORE_TRC_MAIN_SDCCH_DOWNLINK_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0717, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_MAIN_FACCH_DOWNLINK() do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0817, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define GL1_PCORE_TRC_MAIN_FACCH_DOWNLINK()
#endif
#define GL1_PCORE_TRC_MAIN_FACCH_DOWNLINK_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0817, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_MAIN_PACKET_DOWNLINK() do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0917, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define GL1_PCORE_TRC_MAIN_PACKET_DOWNLINK()
#endif
#define GL1_PCORE_TRC_MAIN_PACKET_DOWNLINK_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0917, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_TOOL_GetFn(v1) do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A17, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define GL1_PCORE_TRC_TOOL_GetFn(v1)
#endif
#define GL1_PCORE_TRC_TOOL_GetFn_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A17, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_CSD_Activate() do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B17, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define GL1_PCORE_TRC_CSD_Activate()
#endif
#define GL1_PCORE_TRC_CSD_Activate_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B17, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_CSD_Deactivate() do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C17, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define GL1_PCORE_TRC_CSD_Deactivate()
#endif
#define GL1_PCORE_TRC_CSD_Deactivate_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C17, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_CSD_DnlinkData1(v1, v2, v3, v4) do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D17, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define GL1_PCORE_TRC_CSD_DnlinkData1(v1, v2, v3, v4)
#endif
#define GL1_PCORE_TRC_CSD_DnlinkData1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D17, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_CSD_DnlinkData2(v1, v2) do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E17, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define GL1_PCORE_TRC_CSD_DnlinkData2(v1, v2)
#endif
#define GL1_PCORE_TRC_CSD_DnlinkData2_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E17, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define GL1_PCORE_TRC_FCS(v1) do {\
		if(GL1_PCORE_Trace_Filter[0]==1 && (GL1_PCORE_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F17, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define GL1_PCORE_TRC_FCS(v1)
#endif
#define GL1_PCORE_TRC_FCS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F17, (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char GL1_PCORE_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_GL1_PCORE_TRC_CCIRQ_Handler(long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_GL1_PCORE_TRC_CCIRQ_SACCH_UPLINK(char v1, char v2, unsigned char v3, long v4);
void L1TRC_Send_GL1_PCORE_TRC_CCIRQ_SDCCH_UPLINK(char v1, char v2, unsigned char v3, long v4);
void L1TRC_Send_GL1_PCORE_TRC_CCIRQ_FACCH_UPLINK(char v1, char v2, unsigned char v3, long v4);
void L1TRC_Send_GL1_PCORE_TRC_CCIRQ_UPLINK_TRANSFER(long v1, long v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_GL1_PCORE_TRC_MAIN_Init(void);
void L1TRC_Send_GL1_PCORE_TRC_MAIN_SACCH_DOWNLINK(void);
void L1TRC_Send_GL1_PCORE_TRC_MAIN_SDCCH_DOWNLINK(void);
void L1TRC_Send_GL1_PCORE_TRC_MAIN_FACCH_DOWNLINK(void);
void L1TRC_Send_GL1_PCORE_TRC_MAIN_PACKET_DOWNLINK(void);
void L1TRC_Send_GL1_PCORE_TRC_TOOL_GetFn(long v1);
void L1TRC_Send_GL1_PCORE_TRC_CSD_Activate(void);
void L1TRC_Send_GL1_PCORE_TRC_CSD_Deactivate(void);
void L1TRC_Send_GL1_PCORE_TRC_CSD_DnlinkData1(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_GL1_PCORE_TRC_CSD_DnlinkData2(unsigned char v1, unsigned char v2);
void L1TRC_Send_GL1_PCORE_TRC_FCS(unsigned char v1);

void Set_GL1_PCORE_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_GL1_PCORE()	(GL1_PCORE_Trace_Filter[0]==1)
#define ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CCIRQ_H()	(ChkL1ModFltr_GL1_PCORE()&&((GL1_PCORE_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_MAIN_H()	(ChkL1ModFltr_GL1_PCORE()&&((GL1_PCORE_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_TOOL_H()	(ChkL1ModFltr_GL1_PCORE()&&((GL1_PCORE_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CSD_H()	(ChkL1ModFltr_GL1_PCORE()&&((GL1_PCORE_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_FCS_H()	(ChkL1ModFltr_GL1_PCORE()&&((GL1_PCORE_Trace_Filter[1]&0x10)!=0))
#define ChkL1MsgFltr_GL1_PCORE_TRC_CCIRQ_Handler()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CCIRQ_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_CCIRQ_SACCH_UPLINK()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CCIRQ_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_CCIRQ_SDCCH_UPLINK()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CCIRQ_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_CCIRQ_FACCH_UPLINK()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CCIRQ_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_CCIRQ_UPLINK_TRANSFER()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CCIRQ_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_MAIN_Init()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_MAIN_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_MAIN_SACCH_DOWNLINK()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_MAIN_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_MAIN_SDCCH_DOWNLINK()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_MAIN_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_MAIN_FACCH_DOWNLINK()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_MAIN_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_MAIN_PACKET_DOWNLINK()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_MAIN_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_TOOL_GetFn()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_TOOL_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_CSD_Activate()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CSD_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_CSD_Deactivate()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CSD_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_CSD_DnlinkData1()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CSD_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_CSD_DnlinkData2()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_CSD_H()
#define ChkL1MsgFltr_GL1_PCORE_TRC_FCS()	ChkL1ClsFltr_GL1_PCORE_GL1_PCORE_FCS_H()


#endif
