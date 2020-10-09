#ifndef L1TRC_MML1_RF_PCORE_DEF_H
#define L1TRC_MML1_RF_PCORE_DEF_H

/******************************/
/* String category definition */
/******************************/
#define MMRF_TRC_STR_SINGLE_RAT(v1)  (unsigned char)(v1+0)
#define MMRF_TRC_STR_RAT(v1)  (unsigned char)(v1+33)
#define MMRF_TRC_STR_RATs(v1)  (unsigned char)(v1+66)
#define MMRF_TRC_STR_MD(v1)  (unsigned char)(v1+130)
#define MMRF_TRC_STR_PHASE(v1)  (unsigned char)(v1+133)
#define MMRF_TRC_STR_STATE(v1)  (unsigned char)(v1+135)
#define MMRF_TRC_STR_FLAG(v1)  (unsigned char)(v1+137)
#define MMRF_TRC_STR_ONOFF(v1)  (unsigned char)(v1+139)
#define MMRF_TRC_STR_CLK_BUF_MODE(v1)  (unsigned char)(v1+141)
#define MMRF_TRC_STR_CLK_BUF_SW_STATUS(v1)  (unsigned char)(v1+144)
#define MMRF_TRC_STR_RW(v1)  (unsigned char)(v1+146)
#define MMRF_TRC_STR_RFIC(v1)  (unsigned char)(v1+148)
#define MMRF_TRC_STR_BSILOGGER_RAT_RW(v1)  (unsigned char)(v1+151)
#define MMRF_TRC_STR_BSIMM_PORT(v1)  (unsigned char)(v1+183)
#define MMRF_TRC_STR_HEX(v1)  (unsigned char)(v1+191)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define MMRF_TRC_DRDI_Init(v1, v2, v3) do {\
		if(MML1_RF_PCORE_Trace_Filter[0]==1 && (MML1_RF_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x001B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_DRDI_Init(v1, v2, v3)
#endif
#define MMRF_TRC_DRDI_Init_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x001B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DRDI_Update(v1, v2, v3) do {\
		if(MML1_RF_PCORE_Trace_Filter[0]==1 && (MML1_RF_PCORE_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x011B, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_DRDI_Update(v1, v2, v3)
#endif
#define MMRF_TRC_DRDI_Update_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x011B, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DRDI_Nvram_DBG(v1) do {\
		if(MML1_RF_PCORE_Trace_Filter[0]==1 && (MML1_RF_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x021B, (short)(v1)));\
	} while(0)
#else
	#define MMRF_TRC_DRDI_Nvram_DBG(v1)
#endif
#define MMRF_TRC_DRDI_Nvram_DBG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x021B, (short)(v1)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DRDI_ReMap_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_PCORE_Trace_Filter[0]==1 && (MML1_RF_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x031B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_DRDI_ReMap_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_DRDI_ReMap_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x031B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DRDI_ReMapSetNum_DBG(v1, v2, v3, v4) do {\
		if(MML1_RF_PCORE_Trace_Filter[0]==1 && (MML1_RF_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x041B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_DRDI_ReMapSetNum_DBG(v1, v2, v3, v4)
#endif
#define MMRF_TRC_DRDI_ReMapSetNum_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x041B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DRDI_GPIO_QUERY_DBG(v1, v2, v3) do {\
		if(MML1_RF_PCORE_Trace_Filter[0]==1 && (MML1_RF_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x051B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_DRDI_GPIO_QUERY_DBG(v1, v2, v3)
#endif
#define MMRF_TRC_DRDI_GPIO_QUERY_DBG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x051B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DRDI_ADC_QUERY_DBG(v1) do {\
		if(MML1_RF_PCORE_Trace_Filter[0]==1 && (MML1_RF_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x061B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define MMRF_TRC_DRDI_ADC_QUERY_DBG(v1)
#endif
#define MMRF_TRC_DRDI_ADC_QUERY_DBG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x061B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define MMRF_TRC_SAR_BITMASK_DBG(v1) do {\
		if(MML1_RF_PCORE_Trace_Filter[0]==1 && (MML1_RF_PCORE_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x071B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define MMRF_TRC_SAR_BITMASK_DBG(v1)
#endif
#define MMRF_TRC_SAR_BITMASK_DBG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x071B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char MML1_RF_PCORE_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_MMRF_TRC_DRDI_Init(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_MMRF_TRC_DRDI_Update(unsigned char v1, short v2, short v3);
void L1TRC_Send_MMRF_TRC_DRDI_Nvram_DBG(short v1);
void L1TRC_Send_MMRF_TRC_DRDI_ReMap_DBG(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_MMRF_TRC_DRDI_ReMapSetNum_DBG(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_MMRF_TRC_DRDI_GPIO_QUERY_DBG(short v1, short v2, unsigned long v3);
void L1TRC_Send_MMRF_TRC_DRDI_ADC_QUERY_DBG(unsigned long v1);
void L1TRC_Send_MMRF_TRC_SAR_BITMASK_DBG(unsigned long v1);

void Set_MML1_RF_PCORE_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_MML1_RF_PCORE()	(MML1_RF_PCORE_Trace_Filter[0]==1)
#define ChkL1ClsFltr_MML1_RF_PCORE_MML1_RF_L()	(ChkL1ModFltr_MML1_RF_PCORE()&&((MML1_RF_PCORE_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_MML1_RF_PCORE_MML1_RF_M()	(ChkL1ModFltr_MML1_RF_PCORE()&&((MML1_RF_PCORE_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_MML1_RF_PCORE_MML1_RF_H()	(ChkL1ModFltr_MML1_RF_PCORE()&&((MML1_RF_PCORE_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_MML1_RF_PCORE_MML1_DBG_H()	(ChkL1ModFltr_MML1_RF_PCORE()&&((MML1_RF_PCORE_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_MML1_RF_PCORE_MML1_DBG_L()	(ChkL1ModFltr_MML1_RF_PCORE()&&((MML1_RF_PCORE_Trace_Filter[1]&0x10)!=0))
#define ChkL1MsgFltr_MMRF_TRC_DRDI_Init()	ChkL1ClsFltr_MML1_RF_PCORE_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_DRDI_Update()	ChkL1ClsFltr_MML1_RF_PCORE_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_DRDI_Nvram_DBG()	ChkL1ClsFltr_MML1_RF_PCORE_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DRDI_ReMap_DBG()	ChkL1ClsFltr_MML1_RF_PCORE_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DRDI_ReMapSetNum_DBG()	ChkL1ClsFltr_MML1_RF_PCORE_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DRDI_GPIO_QUERY_DBG()	ChkL1ClsFltr_MML1_RF_PCORE_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DRDI_ADC_QUERY_DBG()	ChkL1ClsFltr_MML1_RF_PCORE_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_SAR_BITMASK_DBG()	ChkL1ClsFltr_MML1_RF_PCORE_MML1_DBG_H()


#endif
