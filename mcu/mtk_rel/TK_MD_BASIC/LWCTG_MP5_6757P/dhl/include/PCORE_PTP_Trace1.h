#ifndef L1TRC_PCORE_MD_PTP_1_DEF_H
#define L1TRC_PCORE_MD_PTP_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define MD_PTP_Str_Bool(v1)  (unsigned char)(v1+0)
#define MD_PTP_Init_Monitor_String(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define MD_PTP_DBG_INFO(v1, v2) do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x001E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MD_PTP_DBG_INFO(v1, v2)
#endif
#define MD_PTP_DBG_INFO_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x001E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP(v1, v2, v3, v4) do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x011E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP(v1, v2, v3, v4)
#endif
#define MD_PTP_DBG_DUMP_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x011E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP2(v1, v2, v3, v4) do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x021E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP2(v1, v2, v3, v4)
#endif
#define MD_PTP_DBG_DUMP2_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x021E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP3(v1, v2, v3) do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x031E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP3(v1, v2, v3)
#endif
#define MD_PTP_DBG_DUMP3_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x031E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP4(v1, v2) do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x041E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP4(v1, v2)
#endif
#define MD_PTP_DBG_DUMP4_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x041E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP5(v1, v2) do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x051E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP5(v1, v2)
#endif
#define MD_PTP_DBG_DUMP5_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x051E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP_PCore() do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x061E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP_PCore()
#endif
#define MD_PTP_DBG_DUMP_PCore_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x061E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP_L1Core() do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x071E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP_L1Core()
#endif
#define MD_PTP_DBG_DUMP_L1Core_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x071E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP_DSP() do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x081E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP_DSP()
#endif
#define MD_PTP_DBG_DUMP_DSP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x081E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP_PCore_Init() do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x091E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP_PCore_Init()
#endif
#define MD_PTP_DBG_DUMP_PCore_Init_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x091E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP_L1Core_Init() do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A1E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP_L1Core_Init()
#endif
#define MD_PTP_DBG_DUMP_L1Core_Init_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A1E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MD_PTP_DBG_DUMP_DSP_Init() do {\
		if(PCORE_MD_PTP_1_Trace_Filter[0]==1 && (PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B1E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MD_PTP_DBG_DUMP_DSP_Init()
#endif
#define MD_PTP_DBG_DUMP_DSP_Init_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B1E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char PCORE_MD_PTP_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_MD_PTP_DBG_INFO(unsigned char v1, unsigned char v2);
void L1TRC_Send_MD_PTP_DBG_DUMP(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MD_PTP_DBG_DUMP2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MD_PTP_DBG_DUMP3(long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_MD_PTP_DBG_DUMP4(unsigned long v1, unsigned long v2);
void L1TRC_Send_MD_PTP_DBG_DUMP5(unsigned long v1, unsigned long v2);
void L1TRC_Send_MD_PTP_DBG_DUMP_PCore(void);
void L1TRC_Send_MD_PTP_DBG_DUMP_L1Core(void);
void L1TRC_Send_MD_PTP_DBG_DUMP_DSP(void);
void L1TRC_Send_MD_PTP_DBG_DUMP_PCore_Init(void);
void L1TRC_Send_MD_PTP_DBG_DUMP_L1Core_Init(void);
void L1TRC_Send_MD_PTP_DBG_DUMP_DSP_Init(void);

void Set_PCORE_MD_PTP_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_PCORE_MD_PTP_1()	(PCORE_MD_PTP_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()	(ChkL1ModFltr_PCORE_MD_PTP_1()&&((PCORE_MD_PTP_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_MD_PTP_DBG_INFO()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP2()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP3()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP4()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP5()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP_PCore()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP_L1Core()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP_DSP()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP_PCore_Init()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP_L1Core_Init()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()
#define ChkL1MsgFltr_MD_PTP_DBG_DUMP_DSP_Init()	ChkL1ClsFltr_PCORE_MD_PTP_1_MD_PTP_DBG_H()


#endif
