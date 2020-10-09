#ifndef L1TRC_UL1D_PRI_PCORE_DEF_H
#define L1TRC_UL1D_PRI_PCORE_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_PCORE_HSDSCH_HARQ_DBG_STR(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_PCORE_ETFCI_RESTRICT_TYPE(v1)  (unsigned char)(v1+2)
#define UL1D_TRC_STR_PCORE_E_SCELL(v1)  (unsigned char)(v1+8)
#define UL1D_TRC_STR_PCORE_ULDCH_TIME_CHECK(v1)  (unsigned char)(v1+10)
#define UL1D_TRC_STR_PCORE_ETX_TIME_CHECK(v1)  (unsigned char)(v1+12)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1D_TRC_PCORE_ULDCH_TIME_CHECK(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PRI_PCORE_Trace_Filter[0]==1 && (UL1D_PRI_PCORE_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0015, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_PCORE_ULDCH_TIME_CHECK(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_PCORE_ULDCH_TIME_CHECK_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0015, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCORE_DCH_ASU_CHECK(v1, v2, v3) do {\
		if(UL1D_PRI_PCORE_Trace_Filter[0]==1 && (UL1D_PRI_PCORE_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0115, (unsigned short)(v3)), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_PCORE_DCH_ASU_CHECK(v1, v2, v3)
#endif
#define UL1D_TRC_PCORE_DCH_ASU_CHECK_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0115, (unsigned short)(v3)), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCORE_HS_IND(v1, v2, v3, v4) do {\
		if(UL1D_PRI_PCORE_Trace_Filter[0]==1 && (UL1D_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0215, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_PCORE_HS_IND(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PCORE_HS_IND_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0215, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCORE_HS_DATA(v1, v2, v3, v4, v5) do {\
		if(UL1D_PRI_PCORE_Trace_Filter[0]==1 && (UL1D_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0315, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PCORE_HS_DATA(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_PCORE_HS_DATA_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0315, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCORE_HARQ_OFF_DBG(v1, v2, v3, v4) do {\
		if(UL1D_PRI_PCORE_Trace_Filter[0]==1 && (UL1D_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0415, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_PCORE_HARQ_OFF_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PCORE_HARQ_OFF_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0415, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCORE_RRC_DETECTION_DBG(v1, v2) do {\
		if(UL1D_PRI_PCORE_Trace_Filter[0]==1 && (UL1D_PRI_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0515, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PCORE_RRC_DETECTION_DBG(v1, v2)
#endif
#define UL1D_TRC_PCORE_RRC_DETECTION_DBG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0515, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_PCORE_ETX_UPDATE_REF_ETPR(v1, v2, v3, v4) do {\
		if(UL1D_PRI_PCORE_Trace_Filter[0]==1 && (UL1D_PRI_PCORE_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0615, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_PCORE_ETX_UPDATE_REF_ETPR(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PCORE_ETX_UPDATE_REF_ETPR_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0615, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCORE_ETX_EVAL_INPUT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_PRI_PCORE_Trace_Filter[0]==1 && (UL1D_PRI_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0715, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define UL1D_TRC_PCORE_ETX_EVAL_INPUT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_PCORE_ETX_EVAL_INPUT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0715, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCORE_ETX_EVAL_OUTPUT(v1, v2, v3) do {\
		if(UL1D_PRI_PCORE_Trace_Filter[0]==1 && (UL1D_PRI_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0815, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PCORE_ETX_EVAL_OUTPUT(v1, v2, v3)
#endif
#define UL1D_TRC_PCORE_ETX_EVAL_OUTPUT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0815, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCORE_ETX_TIME_CHECK(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PRI_PCORE_Trace_Filter[0]==1 && (UL1D_PRI_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0915, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_PCORE_ETX_TIME_CHECK(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_PCORE_ETX_TIME_CHECK_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0915, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v5))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_PRI_PCORE_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_PCORE_ULDCH_TIME_CHECK(unsigned char v1, unsigned long v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_PCORE_DCH_ASU_CHECK(long v1, long v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_PCORE_HS_IND(short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_PCORE_HS_DATA(short v1, char v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_PCORE_HARQ_OFF_DBG(unsigned char v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_UL1D_TRC_PCORE_RRC_DETECTION_DBG(char v1, short v2);
void L1TRC_Send_UL1D_TRC_PCORE_ETX_UPDATE_REF_ETPR(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_PCORE_ETX_EVAL_INPUT(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_UL1D_TRC_PCORE_ETX_EVAL_OUTPUT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_PCORE_ETX_TIME_CHECK(unsigned char v1, unsigned long v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned char v6);

void Set_UL1D_PRI_PCORE_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_PRI_PCORE()	(UL1D_PRI_PCORE_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_PRI_PCORE_ULDCH_P_H()	(ChkL1ModFltr_UL1D_PRI_PCORE()&&((UL1D_PRI_PCORE_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_PRI_PCORE_DCH_ASU_CHECK_P_H()	(ChkL1ModFltr_UL1D_PRI_PCORE()&&((UL1D_PRI_PCORE_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_PRI_PCORE_HSDSCH_P_H()	(ChkL1ModFltr_UL1D_PRI_PCORE()&&((UL1D_PRI_PCORE_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_PRI_PCORE_ETX_P_H()	(ChkL1ModFltr_UL1D_PRI_PCORE()&&((UL1D_PRI_PCORE_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_PRI_PCORE_ETX_P_L()	(ChkL1ModFltr_UL1D_PRI_PCORE()&&((UL1D_PRI_PCORE_Trace_Filter[1]&0x10)!=0))
#define ChkL1MsgFltr_UL1D_TRC_PCORE_ULDCH_TIME_CHECK()	ChkL1ClsFltr_UL1D_PRI_PCORE_ULDCH_P_H()
#define ChkL1MsgFltr_UL1D_TRC_PCORE_DCH_ASU_CHECK()	ChkL1ClsFltr_UL1D_PRI_PCORE_DCH_ASU_CHECK_P_H()
#define ChkL1MsgFltr_UL1D_TRC_PCORE_HS_IND()	ChkL1ClsFltr_UL1D_PRI_PCORE_HSDSCH_P_H()
#define ChkL1MsgFltr_UL1D_TRC_PCORE_HS_DATA()	ChkL1ClsFltr_UL1D_PRI_PCORE_HSDSCH_P_H()
#define ChkL1MsgFltr_UL1D_TRC_PCORE_HARQ_OFF_DBG()	ChkL1ClsFltr_UL1D_PRI_PCORE_HSDSCH_P_H()
#define ChkL1MsgFltr_UL1D_TRC_PCORE_RRC_DETECTION_DBG()	ChkL1ClsFltr_UL1D_PRI_PCORE_HSDSCH_P_H()
#define ChkL1MsgFltr_UL1D_TRC_PCORE_ETX_UPDATE_REF_ETPR()	ChkL1ClsFltr_UL1D_PRI_PCORE_ETX_P_L()
#define ChkL1MsgFltr_UL1D_TRC_PCORE_ETX_EVAL_INPUT()	ChkL1ClsFltr_UL1D_PRI_PCORE_ETX_P_H()
#define ChkL1MsgFltr_UL1D_TRC_PCORE_ETX_EVAL_OUTPUT()	ChkL1ClsFltr_UL1D_PRI_PCORE_ETX_P_H()
#define ChkL1MsgFltr_UL1D_TRC_PCORE_ETX_TIME_CHECK()	ChkL1ClsFltr_UL1D_PRI_PCORE_ETX_P_H()


#endif
