#ifndef L1TRC_TPPA_L1SM_1_DEF_H
#define L1TRC_TPPA_L1SM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define TPPA_L1SM_Str_Bool(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TPPA_L1SM_TMR_STA(v1, v2) do {\
		if(TPPA_L1SM_1_Trace_Filter[0]==1 && (TPPA_L1SM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0057, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define TPPA_L1SM_TMR_STA(v1, v2)
#endif
#define TPPA_L1SM_TMR_STA_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0057, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char TPPA_L1SM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_TPPA_L1SM_TMR_STA(unsigned long v1, char v2);

void Set_TPPA_L1SM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_TPPA_L1SM_1()	(TPPA_L1SM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_TPPA_L1SM_1_TPPA_L1SM_H()	(ChkL1ModFltr_TPPA_L1SM_1()&&((TPPA_L1SM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_TPPA_L1SM_1_TPPA_L1SM_M()	(ChkL1ModFltr_TPPA_L1SM_1()&&((TPPA_L1SM_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_TPPA_L1SM_1_TPPA_L1SM_L()	(ChkL1ModFltr_TPPA_L1SM_1()&&((TPPA_L1SM_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_TPPA_L1SM_TMR_STA()	ChkL1ClsFltr_TPPA_L1SM_1_TPPA_L1SM_L()


#endif
