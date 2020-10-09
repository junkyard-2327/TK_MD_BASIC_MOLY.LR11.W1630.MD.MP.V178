#ifndef L1TRC_PCORE_MD_TOPSM_1_DEF_H
#define L1TRC_PCORE_MD_TOPSM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define MD_TOPSM_Str_Bool(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define MD_TOPSM_TRC_CALIBRATION(v1, v2, v3) do {\
		if(PCORE_MD_TOPSM_1_Trace_Filter[0]==1 && (PCORE_MD_TOPSM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0020, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define MD_TOPSM_TRC_CALIBRATION(v1, v2, v3)
#endif
#define MD_TOPSM_TRC_CALIBRATION_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0020, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define MD_TOPSM_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3, v4) do {\
		if(PCORE_MD_TOPSM_1_Trace_Filter[0]==1 && (PCORE_MD_TOPSM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0120, (unsigned short)(v1)), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MD_TOPSM_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3, v4)
#endif
#define MD_TOPSM_DBG_COCLK_UPDATE_FMRESULT_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0120, (unsigned short)(v1)), (unsigned long)(v2), (long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MD_TOPSM_TRC_RESOURCE_SET(v1, v2) do {\
		if(PCORE_MD_TOPSM_1_Trace_Filter[0]==1 && (PCORE_MD_TOPSM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0220, (unsigned short)(v1)), (long)(v2));\
	} while(0)
#else
	#define MD_TOPSM_TRC_RESOURCE_SET(v1, v2)
#endif
#define MD_TOPSM_TRC_RESOURCE_SET_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0220, (unsigned short)(v1)), (long)(v2))

#if defined(L1_CATCHER)
	#define MD_TOPSM_TRC_POLLING(v1, v2, v3, v4, v5) do {\
		if(PCORE_MD_TOPSM_1_Trace_Filter[0]==1 && (PCORE_MD_TOPSM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0320, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define MD_TOPSM_TRC_POLLING(v1, v2, v3, v4, v5)
#endif
#define MD_TOPSM_TRC_POLLING_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0320, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define MD_TOPSM_TRC_SRCLK_FORCE_ON_OFF(v1, v2, v3) do {\
		if(PCORE_MD_TOPSM_1_Trace_Filter[0]==1 && (PCORE_MD_TOPSM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0420, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define MD_TOPSM_TRC_SRCLK_FORCE_ON_OFF(v1, v2, v3)
#endif
#define MD_TOPSM_TRC_SRCLK_FORCE_ON_OFF_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0420, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define MD_TOPSM_TRC_PLL_FORCE_ON_OFF(v1, v2, v3) do {\
		if(PCORE_MD_TOPSM_1_Trace_Filter[0]==1 && (PCORE_MD_TOPSM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0520, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define MD_TOPSM_TRC_PLL_FORCE_ON_OFF(v1, v2, v3)
#endif
#define MD_TOPSM_TRC_PLL_FORCE_ON_OFF_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0520, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char PCORE_MD_TOPSM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_MD_TOPSM_TRC_CALIBRATION(unsigned short v1, long v2, long v3);
void L1TRC_Send_MD_TOPSM_DBG_COCLK_UPDATE_FMRESULT(unsigned short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_MD_TOPSM_TRC_RESOURCE_SET(unsigned short v1, long v2);
void L1TRC_Send_MD_TOPSM_TRC_POLLING(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_MD_TOPSM_TRC_SRCLK_FORCE_ON_OFF(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_MD_TOPSM_TRC_PLL_FORCE_ON_OFF(unsigned long v1, unsigned short v2, unsigned short v3);

void Set_PCORE_MD_TOPSM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_PCORE_MD_TOPSM_1()	(PCORE_MD_TOPSM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_PCORE_MD_TOPSM_1_MD_TOPSM_SM_H()	(ChkL1ModFltr_PCORE_MD_TOPSM_1()&&((PCORE_MD_TOPSM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_MD_TOPSM_TRC_CALIBRATION()	ChkL1ClsFltr_PCORE_MD_TOPSM_1_MD_TOPSM_SM_H()
#define ChkL1MsgFltr_MD_TOPSM_DBG_COCLK_UPDATE_FMRESULT()	ChkL1ClsFltr_PCORE_MD_TOPSM_1_MD_TOPSM_SM_H()
#define ChkL1MsgFltr_MD_TOPSM_TRC_RESOURCE_SET()	ChkL1ClsFltr_PCORE_MD_TOPSM_1_MD_TOPSM_SM_H()
#define ChkL1MsgFltr_MD_TOPSM_TRC_POLLING()	ChkL1ClsFltr_PCORE_MD_TOPSM_1_MD_TOPSM_SM_H()
#define ChkL1MsgFltr_MD_TOPSM_TRC_SRCLK_FORCE_ON_OFF()	ChkL1ClsFltr_PCORE_MD_TOPSM_1_MD_TOPSM_SM_H()
#define ChkL1MsgFltr_MD_TOPSM_TRC_PLL_FORCE_ON_OFF()	ChkL1ClsFltr_PCORE_MD_TOPSM_1_MD_TOPSM_SM_H()


#endif
