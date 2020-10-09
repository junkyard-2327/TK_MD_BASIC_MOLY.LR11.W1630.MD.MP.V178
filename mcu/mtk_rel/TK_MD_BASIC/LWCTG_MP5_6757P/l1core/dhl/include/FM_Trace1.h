#ifndef L1TRC_FM_1_DEF_H
#define L1TRC_FM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define FM_Str_Bool(v1)  (unsigned char)(v1+0)
#define FM_Str_Calibration(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define FM_TRC_CALIBRATION(v1, v2, v3, v4) do {\
		if(FM_1_Trace_Filter[0]==1 && (FM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x004E, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define FM_TRC_CALIBRATION(v1, v2, v3, v4)
#endif
#define FM_TRC_CALIBRATION_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x004E, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char FM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_FM_TRC_CALIBRATION(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);

void Set_FM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_FM_1()	(FM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_FM_1_FM_H()	(ChkL1ModFltr_FM_1()&&((FM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_FM_TRC_CALIBRATION()	ChkL1ClsFltr_FM_1_FM_H()


#endif
