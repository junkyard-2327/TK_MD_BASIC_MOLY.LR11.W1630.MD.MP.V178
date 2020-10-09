#ifndef L1TRC_EL1D_TXDFE0_DEF_H
#define L1TRC_EL1D_TXDFE0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_TXDFE_DAC_WIN_ONOFF(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TXDFE_DFE_CTRL(v1, v2, v3) do {\
		if(EL1D_TXDFE0_Trace_Filter[0]==1 && (EL1D_TXDFE0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0041, (short)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TXDFE_DFE_CTRL(v1, v2, v3)
#endif
#define EL1D_TRC_TXDFE_DFE_CTRL_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0041, (short)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TXDFE_DAC_CTRL(v1, v2, v3) do {\
		if(EL1D_TXDFE0_Trace_Filter[0]==1 && (EL1D_TXDFE0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0141, (short)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TXDFE_DAC_CTRL(v1, v2, v3)
#endif
#define EL1D_TRC_TXDFE_DAC_CTRL_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0141, (short)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TXDFE_NRT_UPDATE(v1, v2, v3) do {\
		if(EL1D_TXDFE0_Trace_Filter[0]==1 && (EL1D_TXDFE0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0241, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_TXDFE_NRT_UPDATE(v1, v2, v3)
#endif
#define EL1D_TRC_TXDFE_NRT_UPDATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0241, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TXDFE_GET_HRM_INFO(v1, v2) do {\
		if(EL1D_TXDFE0_Trace_Filter[0]==1 && (EL1D_TXDFE0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0341, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TXDFE_GET_HRM_INFO(v1, v2)
#endif
#define EL1D_TRC_TXDFE_GET_HRM_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0341, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TXDFE_DELAY(v1) do {\
		if(EL1D_TXDFE0_Trace_Filter[0]==1 && (EL1D_TXDFE0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0441, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TXDFE_DELAY(v1)
#endif
#define EL1D_TRC_TXDFE_DELAY_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0441, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_TXDFE0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_TXDFE_DFE_CTRL(unsigned long v1, short v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TXDFE_DAC_CTRL(unsigned long v1, short v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TXDFE_NRT_UPDATE(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_TXDFE_GET_HRM_INFO(short v1, short v2);
void L1TRC_Send_EL1D_TRC_TXDFE_DELAY(long v1);

void Set_EL1D_TXDFE0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_TXDFE0()	(EL1D_TXDFE0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_TXDFE0_EL1D_TRC_CLS_TXDFE_H()	(ChkL1ModFltr_EL1D_TXDFE0()&&((EL1D_TXDFE0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_TXDFE0_EL1D_TRC_CLS_TXDFE_M()	(ChkL1ModFltr_EL1D_TXDFE0()&&((EL1D_TXDFE0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_TXDFE0_EL1D_TRC_CLS_TXDFE_L()	(ChkL1ModFltr_EL1D_TXDFE0()&&((EL1D_TXDFE0_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_TXDFE_DFE_CTRL()	ChkL1ClsFltr_EL1D_TXDFE0_EL1D_TRC_CLS_TXDFE_M()
#define ChkL1MsgFltr_EL1D_TRC_TXDFE_DAC_CTRL()	ChkL1ClsFltr_EL1D_TXDFE0_EL1D_TRC_CLS_TXDFE_M()
#define ChkL1MsgFltr_EL1D_TRC_TXDFE_NRT_UPDATE()	ChkL1ClsFltr_EL1D_TXDFE0_EL1D_TRC_CLS_TXDFE_M()
#define ChkL1MsgFltr_EL1D_TRC_TXDFE_GET_HRM_INFO()	ChkL1ClsFltr_EL1D_TXDFE0_EL1D_TRC_CLS_TXDFE_M()
#define ChkL1MsgFltr_EL1D_TRC_TXDFE_DELAY()	ChkL1ClsFltr_EL1D_TXDFE0_EL1D_TRC_CLS_TXDFE_M()


#endif
