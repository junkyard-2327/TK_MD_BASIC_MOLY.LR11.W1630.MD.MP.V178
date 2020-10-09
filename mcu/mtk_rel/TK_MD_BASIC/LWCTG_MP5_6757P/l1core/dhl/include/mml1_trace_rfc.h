#ifndef L1TRC_MML1_RFC_DEF_H
#define L1TRC_MML1_RFC_DEF_H

/******************************/
/* String category definition */
/******************************/
#define MMRF_TRC_STR_RAT_RFC(v1)  (unsigned char)(v1+0)
#define MMRF_TRC_STR_PHASE_RFC(v1)  (unsigned char)(v1+33)
#define MMRF_TRC_STR_POC_ITEM(v1)  (unsigned char)(v1+35)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define MMRF_TRC_POC_ITEM_INFO(v1, v2, v3, v4) do {\
		if(MML1_RFC_Trace_Filter[0]==1 && (MML1_RFC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0048, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_POC_ITEM_INFO(v1, v2, v3, v4)
#endif
#define MMRF_TRC_POC_ITEM_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0048, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char MML1_RFC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_MMRF_TRC_POC_ITEM_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);

void Set_MML1_RFC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_MML1_RFC()	(MML1_RFC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_MML1_RFC_MML1_RF_H()	(ChkL1ModFltr_MML1_RFC()&&((MML1_RFC_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_MMRF_TRC_POC_ITEM_INFO()	ChkL1ClsFltr_MML1_RFC_MML1_RF_H()


#endif
