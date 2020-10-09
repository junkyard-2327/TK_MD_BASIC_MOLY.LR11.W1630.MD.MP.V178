#ifndef L1TRC_PTP_1_DEF_H
#define L1TRC_PTP_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define PTP_Str_Bool(v1)  (unsigned char)(v1+0)
#define PTP_Core_String(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define PTP_DBG_DUMP(v1, v2, v3, v4) do {\
		if(PTP_1_Trace_Filter[0]==1 && (PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x004B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PTP_DBG_DUMP(v1, v2, v3, v4)
#endif
#define PTP_DBG_DUMP_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x004B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define PTP_DBG_MON(v1, v2, v3, v4) do {\
		if(PTP_1_Trace_Filter[0]==1 && (PTP_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x014B, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PTP_DBG_MON(v1, v2, v3, v4)
#endif
#define PTP_DBG_MON_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x014B, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v3), (unsigned long)(v4))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char PTP_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_PTP_DBG_DUMP(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PTP_DBG_MON(long v1, unsigned char v2, unsigned long v3, unsigned long v4);

void Set_PTP_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_PTP_1()	(PTP_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_PTP_1_PTP_H()	(ChkL1ModFltr_PTP_1()&&((PTP_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_PTP_DBG_DUMP()	ChkL1ClsFltr_PTP_1_PTP_H()
#define ChkL1MsgFltr_PTP_DBG_MON()	ChkL1ClsFltr_PTP_1_PTP_H()


#endif
