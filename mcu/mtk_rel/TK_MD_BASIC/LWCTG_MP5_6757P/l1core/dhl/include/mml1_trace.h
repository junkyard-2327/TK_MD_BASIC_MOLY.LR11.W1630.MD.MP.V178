#ifndef L1TRC_MML1_RF_DEF_H
#define L1TRC_MML1_RF_DEF_H

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
#define MMRF_TRC_STR_CLKBUF_DRIVING(v1)  (unsigned char)(v1+151)
#define MMRF_TRC_STR_BSILOGGER_RAT_RW(v1)  (unsigned char)(v1+155)
#define MMRF_TRC_STR_BSIMM_PORT(v1)  (unsigned char)(v1+187)
#define MMRF_TRC_STR_HEX(v1)  (unsigned char)(v1+195)
#define MMADT_TRC_ADT_RAT(v1)  (unsigned char)(v1+211)
#define MML1_ADT_CONN_DL_RESULT(v1)  (unsigned char)(v1+215)
#define MML1_ADT_IDLE_REQ(v1)  (unsigned char)(v1+223)
#define MML1_ADT_DL_RESULT(v1)  (unsigned char)(v1+226)
#define MMRF_TRC_STR_VCXO_TYPE(v1)  (unsigned char)(v1+232)
#define MMRF_TRC_MULTI_AFC_RAT(v1)  (unsigned char)(v1+235)
#define MMRF_TRC_TX_POWER_RECORD_RAT(v1)  (unsigned char)(v1+241)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_Init1(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0046, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_Init1(v1)
#endif
#define MMRF_TRC_RF_Init1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0046, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_Init2(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0146, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_Init2(v1)
#endif
#define MMRF_TRC_RF_Init2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0146, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_PowerOn(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0246, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_PowerOn(v1, v2, v3)
#endif
#define MMRF_TRC_RF_PowerOn_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0246, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_PowerOff(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0346, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMRF_TRC_RF_PowerOff(v1, v2)
#endif
#define MMRF_TRC_RF_PowerOff_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0346, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_SET_EG(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0446, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMRF_TRC_RF_SET_EG(v1, v2)
#endif
#define MMRF_TRC_RF_SET_EG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0446, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_RETRIEVE_EG(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0546, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMRF_TRC_RF_RETRIEVE_EG(v1, v2)
#endif
#define MMRF_TRC_RF_RETRIEVE_EG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0546, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_ChipVersion(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0646, (short)(v1)));\
	} while(0)
#else
	#define MMRF_TRC_RF_ChipVersion(v1)
#endif
#define MMRF_TRC_RF_ChipVersion_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0646, (short)(v1)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_CoClockSetting(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0746, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_CoClockSetting(v1, v2, v3, v4)
#endif
#define MMRF_TRC_RF_CoClockSetting_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0746, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_ClkBuf_SWHWMode(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0846, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_ClkBuf_SWHWMode(v1, v2, v3, v4)
#endif
#define MMRF_TRC_RF_ClkBuf_SWHWMode_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0846, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_ClkBuf_SWStatus(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0946, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_ClkBuf_SWStatus(v1, v2, v3, v4)
#endif
#define MMRF_TRC_RF_ClkBuf_SWStatus_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0946, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_ClkBuf_Driving(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A46, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_ClkBuf_Driving(v1, v2, v3, v4)
#endif
#define MMRF_TRC_RF_ClkBuf_Driving_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A46, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_ClkBuf_Driving_CCCI(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B46, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_ClkBuf_Driving_CCCI(v1, v2, v3, v4)
#endif
#define MMRF_TRC_RF_ClkBuf_Driving_CCCI_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B46, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_EnterFlightMode(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C46, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMRF_TRC_RF_EnterFlightMode(v1, v2)
#endif
#define MMRF_TRC_RF_EnterFlightMode_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C46, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_DCXOLPM(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D46, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_RF_DCXOLPM(v1, v2, v3)
#endif
#define MMRF_TRC_RF_DCXOLPM_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D46, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_RF_DCXOFPM(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E46, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_RF_DCXOFPM(v1, v2, v3, v4)
#endif
#define MMRF_TRC_RF_DCXOFPM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E46, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_RF_FIXAFC_EN(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F46, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_FIXAFC_EN(v1, v2, v3)
#endif
#define MMRF_TRC_RF_FIXAFC_EN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F46, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_RF_CRYSTAL_ON_PMIC_EN(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1046, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_CRYSTAL_ON_PMIC_EN(v1, v2, v3)
#endif
#define MMRF_TRC_RF_CRYSTAL_ON_PMIC_EN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1046, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_RF_VCXO_TYPE(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1146, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMRF_TRC_RF_VCXO_TYPE(v1, v2)
#endif
#define MMRF_TRC_RF_VCXO_TYPE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1146, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_RF_COTMS_SCURVE_COEF(v1, v2, v3, v4, v5) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1246, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define MMRF_TRC_RF_COTMS_SCURVE_COEF(v1, v2, v3, v4, v5)
#endif
#define MMRF_TRC_RF_COTMS_SCURVE_COEF_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1246, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_RF_COTMS_CHECK(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1346, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMRF_TRC_RF_COTMS_CHECK(v1, v2)
#endif
#define MMRF_TRC_RF_COTMS_CHECK_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1346, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_RF_DPDADC_26M_EN(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1446, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMRF_TRC_RF_DPDADC_26M_EN(v1, v2)
#endif
#define MMRF_TRC_RF_DPDADC_26M_EN_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1446, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_RF_GET_AFCDAC(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1546, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_GET_AFCDAC(v1, v2)
#endif
#define MMRF_TRC_RF_GET_AFCDAC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1546, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_Conflict(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1646, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_Conflict(v1)
#endif
#define MMRF_TRC_RF_Conflict_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1646, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_Conflict_BPI(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1746, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_RF_Conflict_BPI(v1, v2, v3, v4)
#endif
#define MMRF_TRC_RF_Conflict_BPI_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1746, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_Conflict_RAT(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1846, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_Conflict_RAT(v1, v2, v3, v4)
#endif
#define MMRF_TRC_RF_Conflict_RAT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1846, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_Conflict_Clear(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1946, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define MMRF_TRC_RF_Conflict_Clear(v1)
#endif
#define MMRF_TRC_RF_Conflict_Clear_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1946, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define MMRF_TRC_BPI_IMM_WRITE(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_BPI_IMM_WRITE(v1, v2)
#endif
#define MMRF_TRC_BPI_IMM_WRITE_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BPI_IMM_READ(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1B46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_BPI_IMM_READ(v1, v2)
#endif
#define MMRF_TRC_BPI_IMM_READ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1B46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MMRF_TRC_BPILOGGER_DBG(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1C46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_BPILOGGER_DBG(v1, v2)
#endif
#define MMRF_TRC_BPILOGGER_DBG_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1C46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BPI_IMM_RW_RAT(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1D46, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_BPI_IMM_RW_RAT(v1, v2, v3, v4)
#endif
#define MMRF_TRC_BPI_IMM_RW_RAT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1D46, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_BPI_IMM_RW_RAT_MASK(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E46, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_BPI_IMM_RW_RAT_MASK(v1, v2, v3, v4)
#endif
#define MMRF_TRC_BPI_IMM_RW_RAT_MASK_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E46, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RF_CW_VALUE(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F46, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RF_CW_VALUE(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_RF_CW_VALUE_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F46, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_POR_CW_VALUE(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2046, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_POR_CW_VALUE(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_POR_CW_VALUE_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2046, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_POC_CW_VALUE(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2146, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_POC_CW_VALUE(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_POC_CW_VALUE_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2146, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_POR_RD_CHECK(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2246, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_POR_RD_CHECK(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_POR_RD_CHECK_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2246, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_HWPOR_NUM_CHECK(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2346, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define MMRF_TRC_HWPOR_NUM_CHECK(v1, v2, v3)
#endif
#define MMRF_TRC_HWPOR_NUM_CHECK_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2346, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define MML1_TRC_POR_RD_CHECK_LOG(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2446, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define MML1_TRC_POR_RD_CHECK_LOG(v1, v2, v3, v4)
#endif
#define MML1_TRC_POR_RD_CHECK_LOG_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2446, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MML1_TRC_POR_RD_BYPASS(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2546, (short)(v1)));\
	} while(0)
#else
	#define MML1_TRC_POR_RD_BYPASS(v1)
#endif
#define MML1_TRC_POR_RD_BYPASS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2546, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_ABB_RCCAL(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2646, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_ABB_RCCAL(v1)
#endif
#define MMRF_TRC_ABB_RCCAL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2646, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_ABB_RCCAL_VALUE(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2746, (short)(v1)));\
	} while(0)
#else
	#define MMRF_TRC_ABB_RCCAL_VALUE(v1)
#endif
#define MMRF_TRC_ABB_RCCAL_VALUE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2746, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_ABB_DPDRCAL(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2846, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_ABB_DPDRCAL(v1)
#endif
#define MMRF_TRC_ABB_DPDRCAL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2846, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_ABB_TXDACCAL_NVRAM(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2946, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_ABB_TXDACCAL_NVRAM(v1)
#endif
#define MMRF_TRC_ABB_TXDACCAL_NVRAM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2946, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_ADC_FAIL_CHECK(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2A46, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_ADC_FAIL_CHECK(v1, v2, v3)
#endif
#define MMRF_TRC_ADC_FAIL_CHECK_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2A46, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_DFE_IQ_SWAP_DBG(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B46, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)));\
	} while(0)
#else
	#define MMRF_TRC_DFE_IQ_SWAP_DBG(v1, v2, v3, v4)
#endif
#define MMRF_TRC_DFE_IQ_SWAP_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B46, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_DFE_IQ_INV_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C46, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_DFE_IQ_INV_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_DFE_IQ_INV_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C46, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_DFE_IQ_SWAP(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D46, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)));\
	} while(0)
#else
	#define MMRF_TRC_DFE_IQ_SWAP(v1, v2, v3, v4)
#endif
#define MMRF_TRC_DFE_IQ_SWAP_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D46, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_DFE_IQ_INV(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E46, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_DFE_IQ_INV(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_DFE_IQ_INV_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E46, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_DFE_FC_CON(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F46, (short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_DFE_FC_CON(v1, v2)
#endif
#define MMRF_TRC_DFE_FC_CON_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F46, (short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_PMIC_PWM_SET(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3046, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_PMIC_PWM_SET(v1)
#endif
#define MMRF_TRC_PMIC_PWM_SET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3046, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_PMIC_PWM_CLR(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3146, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_PMIC_PWM_CLR(v1)
#endif
#define MMRF_TRC_PMIC_PWM_CLR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3146, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MMRF_TRC_PMIC_PWM_STATUS(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3246, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_PMIC_PWM_STATUS(v1)
#endif
#define MMRF_TRC_PMIC_PWM_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3246, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MMRF_TRC_PMIC_PWM_BYRAT(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3346, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_PMIC_PWM_BYRAT(v1, v2, v3, v4)
#endif
#define MMRF_TRC_PMIC_PWM_BYRAT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3346, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MMRF_TRC_PMIC_VPA_CONTROL(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3446, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_PMIC_VPA_CONTROL(v1, v2, v3)
#endif
#define MMRF_TRC_PMIC_VPA_CONTROL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3446, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_PMIC_MISC_CTRL(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3546, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_PMIC_MISC_CTRL(v1, v2, v3, v4)
#endif
#define MMRF_TRC_PMIC_MISC_CTRL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3546, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_PMIC_OC_STATUS(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3646, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define MMRF_TRC_PMIC_OC_STATUS(v1)
#endif
#define MMRF_TRC_PMIC_OC_STATUS_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3646, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define MMRF_TRC_PMIC_DCXO_CTRL(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3746, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_PMIC_DCXO_CTRL(v1, v2, v3, v4)
#endif
#define MMRF_TRC_PMIC_DCXO_CTRL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3746, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_PMIC_DCXO_PM_SWITCH(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3846, (short)(v1)));\
	} while(0)
#else
	#define MMRF_TRC_PMIC_DCXO_PM_SWITCH(v1)
#endif
#define MMRF_TRC_PMIC_DCXO_PM_SWITCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3846, (short)(v1)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_MIPI_Init(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3946, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_MIPI_Init(v1)
#endif
#define MMRF_TRC_MIPI_Init_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3946, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_MIPI_PowerOn(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A46, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMRF_TRC_MIPI_PowerOn(v1, v2)
#endif
#define MMRF_TRC_MIPI_PowerOn_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A46, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_MIPI_PowerOff(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B46, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMRF_TRC_MIPI_PowerOff(v1, v2)
#endif
#define MMRF_TRC_MIPI_PowerOff_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B46, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_MIPI_ChipVersion(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3C46, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_MIPI_ChipVersion(v1, v2, v3, v4)
#endif
#define MMRF_TRC_MIPI_ChipVersion_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3C46, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_CONFLICT_RAT_CHECK(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D46, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMRF_TRC_CONFLICT_RAT_CHECK(v1, v2)
#endif
#define MMRF_TRC_CONFLICT_RAT_CHECK_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D46, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_L2MD3_CCIRQ_INFO1(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3E46, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_L2MD3_CCIRQ_INFO1(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_L2MD3_CCIRQ_INFO1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3E46, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_L2MD3_CCIRQ_INFO2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3F46, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define MMRF_TRC_L2MD3_CCIRQ_INFO2(v1, v2, v3, v4, v5, v6, v7)
#endif
#define MMRF_TRC_L2MD3_CCIRQ_INFO2_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3F46, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_L2MD3_CCIRQ_INFO3(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4046, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_L2MD3_CCIRQ_INFO3(v1, v2, v3, v4)
#endif
#define MMRF_TRC_L2MD3_CCIRQ_INFO3_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4046, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_LOAD_VER(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4146, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_LOAD_VER(v1, v2, v3, v4)
#endif
#define MMRF_TRC_LOAD_VER_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4146, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_LOGGERPTR_DBG(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4246, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_LOGGERPTR_DBG(v1, v2)
#endif
#define MMRF_TRC_LOGGERPTR_DBG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4246, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BSILOGGER_TIME_DBG(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4346, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGER_TIME_DBG(v1, v2)
#endif
#define MMRF_TRC_BSILOGGER_TIME_DBG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4346, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BSI_CLK_CG(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4446, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_BSI_CLK_CG(v1, v2)
#endif
#define MMRF_TRC_BSI_CLK_CG_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4446, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_AP_CCIRQ(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4546, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_AP_CCIRQ(v1, v2)
#endif
#define MMRF_TRC_AP_CCIRQ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4546, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_TOPSM_VRF18_REQ(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4646, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_TOPSM_VRF18_REQ(v1, v2)
#endif
#define MMRF_TRC_TOPSM_VRF18_REQ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4646, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_SPM_POWER_ON_VAL0(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4746, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_SPM_POWER_ON_VAL0(v1, v2)
#endif
#define MMRF_TRC_SPM_POWER_ON_VAL0_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4746, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_SPM_POWER_ON_VAL1(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4846, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_SPM_POWER_ON_VAL1(v1, v2)
#endif
#define MMRF_TRC_SPM_POWER_ON_VAL1_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4846, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_PCM_REG0(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4946, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_PCM_REG0(v1, v2)
#endif
#define MMRF_TRC_PCM_REG0_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4946, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_PCM_REG7(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4A46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_PCM_REG7(v1, v2)
#endif
#define MMRF_TRC_PCM_REG7_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4A46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_PCM_REG13(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4B46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_PCM_REG13(v1, v2)
#endif
#define MMRF_TRC_PCM_REG13_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4B46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_SPM_WAKEUP_STA(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4C46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_SPM_WAKEUP_STA(v1, v2)
#endif
#define MMRF_TRC_SPM_WAKEUP_STA_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4C46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_SPM_WAKEUP_EXT_STA(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4D46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_SPM_WAKEUP_EXT_STA(v1, v2)
#endif
#define MMRF_TRC_SPM_WAKEUP_EXT_STA_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4D46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_SPM_SRC_MASK(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4E46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_SPM_SRC_MASK(v1, v2)
#endif
#define MMRF_TRC_SPM_SRC_MASK_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4E46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_PCM_REG6(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4F46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_PCM_REG6(v1, v2)
#endif
#define MMRF_TRC_PCM_REG6_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4F46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_SPM_SW_FLAG(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5046, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_SPM_SW_FLAG(v1, v2)
#endif
#define MMRF_TRC_SPM_SW_FLAG_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5046, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_SPM_SW_DBG(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5146, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_SPM_SW_DBG(v1, v2)
#endif
#define MMRF_TRC_SPM_SW_DBG_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5146, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_SPM_REG15(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5246, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_SPM_REG15(v1, v2)
#endif
#define MMRF_TRC_SPM_REG15_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5246, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MMRF_TRC_WHILE_LOOP_BYPASS(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5346, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define MMRF_TRC_WHILE_LOOP_BYPASS(v1, v2, v3)
#endif
#define MMRF_TRC_WHILE_LOOP_BYPASS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5346, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_SYSPLL_H_STATUS(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5446, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_SYSPLL_H_STATUS(v1, v2, v3)
#endif
#define MMRF_TRC_SYSPLL_H_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5446, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_SYSPLL_L_STATUS(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5546, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_SYSPLL_L_STATUS(v1, v2, v3)
#endif
#define MMRF_TRC_SYSPLL_L_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5546, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_VS1_STATUS(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5646, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_VS1_STATUS(v1, v2, v3)
#endif
#define MMRF_TRC_VS1_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5646, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BSILOGGER_V2_DBG1(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5746, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGER_V2_DBG1(v1, v2, v3)
#endif
#define MMRF_TRC_BSILOGGER_V2_DBG1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5746, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BSILOGGER_V2_DBG2(v1, v2, v3, v4, v5) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5846, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGER_V2_DBG2(v1, v2, v3, v4, v5)
#endif
#define MMRF_TRC_BSILOGGER_V2_DBG2_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5846, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BSILOGGER_V2_DBG3(v1, v2, v3, v4, v5, v6, v7) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5946, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGER_V2_DBG3(v1, v2, v3, v4, v5, v6, v7)
#endif
#define MMRF_TRC_BSILOGGER_V2_DBG3_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5946, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BSILOGGER_V2_DBG4(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x5A46, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v8), TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7), (unsigned long)(v9));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGER_V2_DBG4(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define MMRF_TRC_BSILOGGER_V2_DBG4_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x5A46, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v8), TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BSILOGGER_V2_DBG5(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x5B46, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v8), (unsigned char)(v10)), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7), (unsigned long)(v9), (unsigned long)(v11));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGER_V2_DBG5(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define MMRF_TRC_BSILOGGER_V2_DBG5_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x5B46, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v8), (unsigned char)(v10)), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7), (unsigned long)(v9), (unsigned long)(v11))

#if defined(L1_CATCHER)
	#define MMRF_TRC_BSILOGGERwTIME_V2_DBG1(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5C46, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGERwTIME_V2_DBG1(v1, v2, v3, v4)
#endif
#define MMRF_TRC_BSILOGGERwTIME_V2_DBG1_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5C46, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define MMRF_TRC_BSILOGGERwTIME_V2_DBG2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5D46, (short)(v4)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v6));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGERwTIME_V2_DBG2(v1, v2, v3, v4, v5, v6, v7)
#endif
#define MMRF_TRC_BSILOGGERwTIME_V2_DBG2_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5D46, (short)(v4)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define MMRF_TRC_BSILOGGERwTIME_V2_DBG3(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x5E46, (short)(v4)), TRC_MERGE_2S((short)(v7), (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v5), (unsigned char)(v8)), (unsigned long)(v3), (unsigned long)(v6), (unsigned long)(v9));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGERwTIME_V2_DBG3(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define MMRF_TRC_BSILOGGERwTIME_V2_DBG3_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x5E46, (short)(v4)), TRC_MERGE_2S((short)(v7), (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v5), (unsigned char)(v8)), (unsigned long)(v3), (unsigned long)(v6), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define MMRF_TRC_BSILOGGERwTIME_V2_DBG4(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x5F46, (short)(v4)), TRC_MERGE_2S((short)(v7), (short)(v10)), TRC_MERGE_1S2C((short)(v13), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v8), (unsigned char)(v11), TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v6), (unsigned long)(v9), (unsigned long)(v12));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGERwTIME_V2_DBG4(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#endif
#define MMRF_TRC_BSILOGGERwTIME_V2_DBG4_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) TRC_SEND_8_DATA(TRC_MERGE_2S(0x5F46, (short)(v4)), TRC_MERGE_2S((short)(v7), (short)(v10)), TRC_MERGE_1S2C((short)(v13), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v8), (unsigned char)(v11), TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v6), (unsigned long)(v9), (unsigned long)(v12))

#if defined(L1_CATCHER)
	#define MMRF_TRC_BSILOGGERwTIME_V2_DBG5(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x6046, (short)(v4)), TRC_MERGE_2S((short)(v7), (short)(v10)), TRC_MERGE_2S((short)(v13), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v5), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v14), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v6), (unsigned long)(v9), (unsigned long)(v12), (unsigned long)(v15));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGERwTIME_V2_DBG5(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define MMRF_TRC_BSILOGGERwTIME_V2_DBG5_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_10_DATA(TRC_MERGE_2S(0x6046, (short)(v4)), TRC_MERGE_2S((short)(v7), (short)(v10)), TRC_MERGE_2S((short)(v13), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v5), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v14), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v6), (unsigned long)(v9), (unsigned long)(v12), (unsigned long)(v15))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BSILOGGER_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6146, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGER_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define MMRF_TRC_BSILOGGER_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6146, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_BSILOGGERwTIME_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6246, (short)(v11)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_BSILOGGERwTIME_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define MMRF_TRC_BSILOGGERwTIME_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6246, (short)(v11)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RFCW_DUMP_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6346, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RFCW_DUMP_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_RFCW_DUMP_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6346, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_D16_REG_DBG(v1, v2, v3, v4, v5) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6446, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define MMRF_TRC_D16_REG_DBG(v1, v2, v3, v4, v5)
#endif
#define MMRF_TRC_D16_REG_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6446, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_D32_REG_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6546, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)));\
	} while(0)
#else
	#define MMRF_TRC_D32_REG_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define MMRF_TRC_D32_REG_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6546, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DEBUG1(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6646, (unsigned short)(v1)), (long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_DEBUG1(v1, v2)
#endif
#define MMRF_TRC_DEBUG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6646, (unsigned short)(v1)), (long)(v2))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DEBUG2(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6746, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_DEBUG2(v1, v2, v3)
#endif
#define MMRF_TRC_DEBUG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6746, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DEBUG3(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6846, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_DEBUG3(v1, v2, v3, v4)
#endif
#define MMRF_TRC_DEBUG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6846, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DEBUG4(v1, v2, v3, v4, v5) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6946, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define MMRF_TRC_DEBUG4(v1, v2, v3, v4, v5)
#endif
#define MMRF_TRC_DEBUG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6946, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DEBUG5(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x6A46, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define MMRF_TRC_DEBUG5(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_DEBUG5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x6A46, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DEBUG6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x6B46, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define MMRF_TRC_DEBUG6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define MMRF_TRC_DEBUG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x6B46, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER)
	#define MMRF_TRC_DEBUG7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x6C46, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define MMRF_TRC_DEBUG7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define MMRF_TRC_DEBUG7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x6C46, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define MMRF_TRC_HEX_DEBUG1(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6D46, (unsigned short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_HEX_DEBUG1(v1, v2)
#endif
#define MMRF_TRC_HEX_DEBUG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6D46, (unsigned short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MMRF_TRC_HEX_DEBUG2(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6E46, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_HEX_DEBUG2(v1, v2, v3)
#endif
#define MMRF_TRC_HEX_DEBUG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6E46, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define MMRF_TRC_HEX_DEBUG3(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6F46, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_HEX_DEBUG3(v1, v2, v3, v4)
#endif
#define MMRF_TRC_HEX_DEBUG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6F46, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_HEX_DEBUG4(v1, v2, v3, v4, v5) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x7046, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define MMRF_TRC_HEX_DEBUG4(v1, v2, v3, v4, v5)
#endif
#define MMRF_TRC_HEX_DEBUG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x7046, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define MMRF_TRC_HEX_DEBUG5(v1, v2, v3, v4, v5, v6) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x7146, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define MMRF_TRC_HEX_DEBUG5(v1, v2, v3, v4, v5, v6)
#endif
#define MMRF_TRC_HEX_DEBUG5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x7146, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define MMRF_TRC_HEX_DEBUG6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x7246, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define MMRF_TRC_HEX_DEBUG6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define MMRF_TRC_HEX_DEBUG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x7246, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define MMRF_TRC_HEX_DEBUG7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x7346, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define MMRF_TRC_HEX_DEBUG7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define MMRF_TRC_HEX_DEBUG7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x7346, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define MMRF_TRC_UBIN_WMID(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7446, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define MMRF_TRC_UBIN_WMID(v1, v2)
#endif
#define MMRF_TRC_UBIN_WMID_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7446, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MMRF_TRC_UBIN_SET_WMID(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7546, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_UBIN_SET_WMID(v1, v2, v3)
#endif
#define MMRF_TRC_UBIN_SET_WMID_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7546, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define MMRF_TRC_Current_AFC_SHM(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x7646, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v6), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define MMRF_TRC_Current_AFC_SHM(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define MMRF_TRC_Current_AFC_SHM_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_8_DATA(TRC_MERGE_2S(0x7646, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v6), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define MMRF_TRC_C2K_POC_SET_DB_BEGIN(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7746, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_C2K_POC_SET_DB_BEGIN(v1, v2, v3, v4)
#endif
#define MMRF_TRC_C2K_POC_SET_DB_BEGIN_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7746, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_C2K_POC_SET_DB_END(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7846, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_C2K_POC_SET_DB_END(v1, v2)
#endif
#define MMRF_TRC_C2K_POC_SET_DB_END_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7846, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_C2K_POC_GET_RESULT_BEGIN(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7946, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_C2K_POC_GET_RESULT_BEGIN(v1, v2)
#endif
#define MMRF_TRC_C2K_POC_GET_RESULT_BEGIN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7946, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_C2K_POC_GET_RESULT_END(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7A46, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_C2K_POC_GET_RESULT_END(v1, v2, v3, v4)
#endif
#define MMRF_TRC_C2K_POC_GET_RESULT_END_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7A46, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_C2K_POC_BEGIN(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7B46, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define MMRF_TRC_C2K_POC_BEGIN(v1, v2, v3)
#endif
#define MMRF_TRC_C2K_POC_BEGIN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7B46, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_C2K_POC_END(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7C46, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_C2K_POC_END(v1, v2)
#endif
#define MMRF_TRC_C2K_POC_END_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7C46, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMADT_TRC_BOOT_DL_RAT(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7D46, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMADT_TRC_BOOT_DL_RAT(v1, v2)
#endif
#define MMADT_TRC_BOOT_DL_RAT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7D46, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MMADT_TRC_UBIN_BOOT_DL_RAT(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7E46, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMADT_TRC_UBIN_BOOT_DL_RAT(v1)
#endif
#define MMADT_TRC_UBIN_BOOT_DL_RAT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7E46, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMADT_TRC_SCHEDULE_CONN_DL_RAT(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7F46, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMADT_TRC_SCHEDULE_CONN_DL_RAT(v1, v2)
#endif
#define MMADT_TRC_SCHEDULE_CONN_DL_RAT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7F46, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MMADT_TRC_SCHEDULE_DL_FINISH(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8046, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMADT_TRC_SCHEDULE_DL_FINISH(v1)
#endif
#define MMADT_TRC_SCHEDULE_DL_FINISH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8046, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMADT_TRC_SCHEDULE_UNLOAD(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8146, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMADT_TRC_SCHEDULE_UNLOAD(v1)
#endif
#define MMADT_TRC_SCHEDULE_UNLOAD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8146, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMADT_TRC_SCHEDULE_CANCEL_LOAD(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8246, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMADT_TRC_SCHEDULE_CANCEL_LOAD(v1)
#endif
#define MMADT_TRC_SCHEDULE_CANCEL_LOAD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8246, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMADT_TRC_SCHEDULE_LTE_SET_RAT(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8346, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMADT_TRC_SCHEDULE_LTE_SET_RAT(v1)
#endif
#define MMADT_TRC_SCHEDULE_LTE_SET_RAT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8346, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMADT_TRC_SCHEDULE_ADT_L_ACT(v1) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8446, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMADT_TRC_SCHEDULE_ADT_L_ACT(v1)
#endif
#define MMADT_TRC_SCHEDULE_ADT_L_ACT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8446, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMADT_TRC_SCHEDULE_ADT_L_NO_ACT(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8546, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMADT_TRC_SCHEDULE_ADT_L_NO_ACT(v1, v2)
#endif
#define MMADT_TRC_SCHEDULE_ADT_L_NO_ACT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8546, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMADT_TRC_SCHEDULE_IDLE_RAT(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8646, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MMADT_TRC_SCHEDULE_IDLE_RAT(v1, v2)
#endif
#define MMADT_TRC_SCHEDULE_IDLE_RAT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8646, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RECORD_TX_POWER_INIT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x8746, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define MMRF_TRC_RECORD_TX_POWER_INIT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define MMRF_TRC_RECORD_TX_POWER_INIT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x8746, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MMRF_TRC_RECORD_TX_POWER(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x8846, (short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define MMRF_TRC_RECORD_TX_POWER(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define MMRF_TRC_RECORD_TX_POWER_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_6_DATA(TRC_MERGE_2S(0x8846, (short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define MMRF_TRC_TPO_DBG(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x8946, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_TPO_DBG(v1, v2, v3, v4)
#endif
#define MMRF_TRC_TPO_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x8946, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_TPO_UPDATE_DBG(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x8A46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define MMRF_TRC_TPO_UPDATE_DBG(v1, v2, v3, v4)
#endif
#define MMRF_TRC_TPO_UPDATE_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x8A46, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MMRF_TRC_RFDB_CRYSTAL_CHECK(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8B46, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_RFDB_CRYSTAL_CHECK(v1, v2)
#endif
#define MMRF_TRC_RFDB_CRYSTAL_CHECK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8B46, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_INITIAL_READ_INFO(v1, v2, v3, v4, v5) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x8C46, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define MMRF_TRC_INITIAL_READ_INFO(v1, v2, v3, v4, v5)
#endif
#define MMRF_TRC_INITIAL_READ_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x8C46, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define MMRF_TRC_INITIAL_WRITE_INFO(v1, v2, v3, v4, v5) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x8D46, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define MMRF_TRC_INITIAL_WRITE_INFO(v1, v2, v3, v4, v5)
#endif
#define MMRF_TRC_INITIAL_WRITE_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x8D46, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define MMRF_TRC_AP_SENSOR_RELATIVE_GAP(v1, v2, v3, v4) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8E46, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_AP_SENSOR_RELATIVE_GAP(v1, v2, v3, v4)
#endif
#define MMRF_TRC_AP_SENSOR_RELATIVE_GAP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8E46, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_AP_SENSOR_RELATIVE_UPDATE(v1, v2) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8F46, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MMRF_TRC_AP_SENSOR_RELATIVE_UPDATE(v1, v2)
#endif
#define MMRF_TRC_AP_SENSOR_RELATIVE_UPDATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8F46, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MMRF_TRC_AP_SENSOR_RELATIVE_STATUS(v1, v2, v3) do {\
		if(MML1_RF_Trace_Filter[0]==1 && (MML1_RF_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x9046, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define MMRF_TRC_AP_SENSOR_RELATIVE_STATUS(v1, v2, v3)
#endif
#define MMRF_TRC_AP_SENSOR_RELATIVE_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x9046, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char MML1_RF_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_MMRF_TRC_RF_Init1(unsigned char v1);
void L1TRC_Send_MMRF_TRC_RF_Init2(unsigned char v1);
void L1TRC_Send_MMRF_TRC_RF_PowerOn(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_MMRF_TRC_RF_PowerOff(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_RF_SET_EG(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_RF_RETRIEVE_EG(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_RF_ChipVersion(short v1);
void L1TRC_Send_MMRF_TRC_RF_CoClockSetting(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_MMRF_TRC_RF_ClkBuf_SWHWMode(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_MMRF_TRC_RF_ClkBuf_SWStatus(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_MMRF_TRC_RF_ClkBuf_Driving(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_MMRF_TRC_RF_ClkBuf_Driving_CCCI(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_MMRF_TRC_RF_EnterFlightMode(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_RF_DCXOLPM(short v1, short v2, unsigned long v3);
void L1TRC_Send_MMRF_TRC_RF_DCXOFPM(unsigned char v1, short v2, short v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_RF_FIXAFC_EN(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_MMRF_TRC_RF_CRYSTAL_ON_PMIC_EN(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_MMRF_TRC_RF_VCXO_TYPE(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_RF_COTMS_SCURVE_COEF(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_MMRF_TRC_RF_COTMS_CHECK(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_RF_DPDADC_26M_EN(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_RF_GET_AFCDAC(unsigned char v1, short v2);
void L1TRC_Send_MMRF_TRC_RF_Conflict(unsigned char v1);
void L1TRC_Send_MMRF_TRC_RF_Conflict_BPI(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_RF_Conflict_RAT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_MMRF_TRC_RF_Conflict_Clear(unsigned long v1);
void L1TRC_Send_MMRF_TRC_BPI_IMM_WRITE(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_BPI_IMM_READ(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_BPILOGGER_DBG(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_BPI_IMM_RW_RAT(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_BPI_IMM_RW_RAT_MASK(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_RF_CW_VALUE(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_MMRF_TRC_POR_CW_VALUE(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_MMRF_TRC_POC_CW_VALUE(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_MMRF_TRC_POR_RD_CHECK(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_MMRF_TRC_HWPOR_NUM_CHECK(short v1, short v2, short v3);
void L1TRC_Send_MML1_TRC_POR_RD_CHECK_LOG(short v1, unsigned long v2, short v3, unsigned long v4);
void L1TRC_Send_MML1_TRC_POR_RD_BYPASS(short v1);
void L1TRC_Send_MMRF_TRC_ABB_RCCAL(unsigned char v1);
void L1TRC_Send_MMRF_TRC_ABB_RCCAL_VALUE(short v1);
void L1TRC_Send_MMRF_TRC_ABB_DPDRCAL(unsigned char v1);
void L1TRC_Send_MMRF_TRC_ABB_TXDACCAL_NVRAM(unsigned char v1);
void L1TRC_Send_MMRF_TRC_ADC_FAIL_CHECK(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_MMRF_TRC_DFE_IQ_SWAP_DBG(short v1, unsigned char v2, short v3, unsigned char v4);
void L1TRC_Send_MMRF_TRC_DFE_IQ_INV_DBG(short v1, unsigned char v2, unsigned char v3, short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_MMRF_TRC_DFE_IQ_SWAP(short v1, unsigned char v2, short v3, unsigned char v4);
void L1TRC_Send_MMRF_TRC_DFE_IQ_INV(short v1, unsigned char v2, unsigned char v3, short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_MMRF_TRC_DFE_FC_CON(short v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_PMIC_PWM_SET(unsigned char v1);
void L1TRC_Send_MMRF_TRC_PMIC_PWM_CLR(unsigned char v1);
void L1TRC_Send_MMRF_TRC_PMIC_PWM_STATUS(unsigned char v1);
void L1TRC_Send_MMRF_TRC_PMIC_PWM_BYRAT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_MMRF_TRC_PMIC_VPA_CONTROL(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_MMRF_TRC_PMIC_MISC_CTRL(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_PMIC_OC_STATUS(unsigned long v1);
void L1TRC_Send_MMRF_TRC_PMIC_DCXO_CTRL(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_PMIC_DCXO_PM_SWITCH(short v1);
void L1TRC_Send_MMRF_TRC_MIPI_Init(unsigned char v1);
void L1TRC_Send_MMRF_TRC_MIPI_PowerOn(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_MIPI_PowerOff(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_MIPI_ChipVersion(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_CONFLICT_RAT_CHECK(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_L2MD3_CCIRQ_INFO1(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_MMRF_TRC_L2MD3_CCIRQ_INFO2(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_MMRF_TRC_L2MD3_CCIRQ_INFO3(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_LOAD_VER(short v1, short v2, short v3, short v4);
void L1TRC_Send_MMRF_TRC_LOGGERPTR_DBG(short v1, short v2);
void L1TRC_Send_MMRF_TRC_BSILOGGER_TIME_DBG(unsigned char v1, long v2);
void L1TRC_Send_MMRF_TRC_BSI_CLK_CG(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_AP_CCIRQ(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_TOPSM_VRF18_REQ(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_SPM_POWER_ON_VAL0(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_SPM_POWER_ON_VAL1(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_PCM_REG0(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_PCM_REG7(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_PCM_REG13(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_SPM_WAKEUP_STA(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_SPM_WAKEUP_EXT_STA(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_SPM_SRC_MASK(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_PCM_REG6(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_SPM_SW_FLAG(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_SPM_SW_DBG(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_SPM_REG15(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_WHILE_LOOP_BYPASS(short v1, short v2, short v3);
void L1TRC_Send_MMRF_TRC_SYSPLL_H_STATUS(unsigned long v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_MMRF_TRC_SYSPLL_L_STATUS(unsigned long v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_MMRF_TRC_VS1_STATUS(unsigned char v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_MMRF_TRC_BSILOGGER_V2_DBG1(unsigned char v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_MMRF_TRC_BSILOGGER_V2_DBG2(unsigned char v1, unsigned char v2, unsigned long v3, unsigned char v4, unsigned long v5);
void L1TRC_Send_MMRF_TRC_BSILOGGER_V2_DBG3(unsigned char v1, unsigned char v2, unsigned long v3, unsigned char v4, unsigned long v5, unsigned char v6, unsigned long v7);
void L1TRC_Send_MMRF_TRC_BSILOGGER_V2_DBG4(unsigned char v1, unsigned char v2, unsigned long v3, unsigned char v4, unsigned long v5, unsigned char v6, unsigned long v7, unsigned char v8, unsigned long v9);
void L1TRC_Send_MMRF_TRC_BSILOGGER_V2_DBG5(unsigned char v1, unsigned char v2, unsigned long v3, unsigned char v4, unsigned long v5, unsigned char v6, unsigned long v7, unsigned char v8, unsigned long v9, unsigned char v10, unsigned long v11);
void L1TRC_Send_MMRF_TRC_BSILOGGERwTIME_V2_DBG1(unsigned char v1, unsigned char v2, unsigned long v3, short v4);
void L1TRC_Send_MMRF_TRC_BSILOGGERwTIME_V2_DBG2(unsigned char v1, unsigned char v2, unsigned long v3, short v4, unsigned char v5, unsigned long v6, short v7);
void L1TRC_Send_MMRF_TRC_BSILOGGERwTIME_V2_DBG3(unsigned char v1, unsigned char v2, unsigned long v3, short v4, unsigned char v5, unsigned long v6, short v7, unsigned char v8, unsigned long v9, short v10);
void L1TRC_Send_MMRF_TRC_BSILOGGERwTIME_V2_DBG4(unsigned char v1, unsigned char v2, unsigned long v3, short v4, unsigned char v5, unsigned long v6, short v7, unsigned char v8, unsigned long v9, short v10, unsigned char v11, unsigned long v12, short v13);
void L1TRC_Send_MMRF_TRC_BSILOGGERwTIME_V2_DBG5(unsigned char v1, unsigned char v2, unsigned long v3, short v4, unsigned char v5, unsigned long v6, short v7, unsigned char v8, unsigned long v9, short v10, unsigned char v11, unsigned long v12, short v13, unsigned char v14, unsigned long v15, short v16);
void L1TRC_Send_MMRF_TRC_BSILOGGER_DBG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_MMRF_TRC_BSILOGGERwTIME_DBG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, short v11);
void L1TRC_Send_MMRF_TRC_RFCW_DUMP_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_MMRF_TRC_D16_REG_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_MMRF_TRC_D32_REG_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_MMRF_TRC_DEBUG1(unsigned short v1, long v2);
void L1TRC_Send_MMRF_TRC_DEBUG2(unsigned short v1, long v2, long v3);
void L1TRC_Send_MMRF_TRC_DEBUG3(unsigned short v1, long v2, long v3, long v4);
void L1TRC_Send_MMRF_TRC_DEBUG4(unsigned short v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_MMRF_TRC_DEBUG5(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_MMRF_TRC_DEBUG6(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_MMRF_TRC_DEBUG7(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_MMRF_TRC_HEX_DEBUG1(unsigned short v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_HEX_DEBUG2(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_MMRF_TRC_HEX_DEBUG3(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_HEX_DEBUG4(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_MMRF_TRC_HEX_DEBUG5(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_MMRF_TRC_HEX_DEBUG6(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_MMRF_TRC_HEX_DEBUG7(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_MMRF_TRC_UBIN_WMID(unsigned long v1, unsigned long v2);
void L1TRC_Send_MMRF_TRC_UBIN_SET_WMID(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_MMRF_TRC_Current_AFC_SHM(short v1, short v2, unsigned short v3, unsigned long v4, unsigned char v5, short v6, unsigned short v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_MMRF_TRC_C2K_POC_SET_DB_BEGIN(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_MMRF_TRC_C2K_POC_SET_DB_END(unsigned short v1, unsigned short v2);
void L1TRC_Send_MMRF_TRC_C2K_POC_GET_RESULT_BEGIN(unsigned short v1, unsigned short v2);
void L1TRC_Send_MMRF_TRC_C2K_POC_GET_RESULT_END(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_MMRF_TRC_C2K_POC_BEGIN(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_MMRF_TRC_C2K_POC_END(unsigned short v1, unsigned short v2);
void L1TRC_Send_MMADT_TRC_BOOT_DL_RAT(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMADT_TRC_UBIN_BOOT_DL_RAT(unsigned char v1);
void L1TRC_Send_MMADT_TRC_SCHEDULE_CONN_DL_RAT(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMADT_TRC_SCHEDULE_DL_FINISH(unsigned char v1);
void L1TRC_Send_MMADT_TRC_SCHEDULE_UNLOAD(unsigned char v1);
void L1TRC_Send_MMADT_TRC_SCHEDULE_CANCEL_LOAD(unsigned char v1);
void L1TRC_Send_MMADT_TRC_SCHEDULE_LTE_SET_RAT(unsigned char v1);
void L1TRC_Send_MMADT_TRC_SCHEDULE_ADT_L_ACT(unsigned char v1);
void L1TRC_Send_MMADT_TRC_SCHEDULE_ADT_L_NO_ACT(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMADT_TRC_SCHEDULE_IDLE_RAT(unsigned char v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_RECORD_TX_POWER_INIT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_MMRF_TRC_RECORD_TX_POWER(unsigned char v1, short v2, unsigned long v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9);
void L1TRC_Send_MMRF_TRC_TPO_DBG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_TPO_UPDATE_DBG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_MMRF_TRC_RFDB_CRYSTAL_CHECK(short v1, unsigned char v2);
void L1TRC_Send_MMRF_TRC_INITIAL_READ_INFO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_MMRF_TRC_INITIAL_WRITE_INFO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_MMRF_TRC_AP_SENSOR_RELATIVE_GAP(short v1, short v2, short v3, short v4);
void L1TRC_Send_MMRF_TRC_AP_SENSOR_RELATIVE_UPDATE(short v1, short v2);
void L1TRC_Send_MMRF_TRC_AP_SENSOR_RELATIVE_STATUS(short v1, short v2, short v3);

void Set_MML1_RF_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_MML1_RF()	(MML1_RF_Trace_Filter[0]==1)
#define ChkL1ClsFltr_MML1_RF_MML1_RF_L()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_RF_M()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_RF_H()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_DBG_L()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_DBG_M()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_DBG_H()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2_L()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2T_H()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V1_L()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V1T_L()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_BPILOG_L()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_BPILOG_H()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_ADT_H()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_MML1_RF_MML1_ADT_L()	(ChkL1ModFltr_MML1_RF()&&((MML1_RF_Trace_Filter[2]&0x20)!=0))
#define ChkL1MsgFltr_MMRF_TRC_RF_Init1()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_Init2()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_PowerOn()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_PowerOff()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_SET_EG()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_RETRIEVE_EG()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_ChipVersion()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_CoClockSetting()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_ClkBuf_SWHWMode()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_ClkBuf_SWStatus()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_ClkBuf_Driving()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_ClkBuf_Driving_CCCI()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_EnterFlightMode()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_DCXOLPM()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_DCXOFPM()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_RF_FIXAFC_EN()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_RF_CRYSTAL_ON_PMIC_EN()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_RF_VCXO_TYPE()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_RF_COTMS_SCURVE_COEF()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_RF_COTMS_CHECK()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_RF_DPDADC_26M_EN()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_RF_GET_AFCDAC()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_RF_Conflict()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_Conflict_BPI()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_Conflict_RAT()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_Conflict_Clear()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_BPI_IMM_WRITE()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_BPI_IMM_READ()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_BPILOGGER_DBG()	ChkL1ClsFltr_MML1_RF_MML1_BPILOG_H()
#define ChkL1MsgFltr_MMRF_TRC_BPI_IMM_RW_RAT()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_BPI_IMM_RW_RAT_MASK()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_RF_CW_VALUE()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_POR_CW_VALUE()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_POC_CW_VALUE()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_POR_RD_CHECK()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_HWPOR_NUM_CHECK()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MML1_TRC_POR_RD_CHECK_LOG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MML1_TRC_POR_RD_BYPASS()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_ABB_RCCAL()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_ABB_RCCAL_VALUE()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_ABB_DPDRCAL()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_ABB_TXDACCAL_NVRAM()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_ADC_FAIL_CHECK()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DFE_IQ_SWAP_DBG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_DFE_IQ_INV_DBG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_DFE_IQ_SWAP()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_DFE_IQ_INV()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_DFE_FC_CON()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_PMIC_PWM_SET()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_PMIC_PWM_CLR()	ChkL1ClsFltr_MML1_RF_MML1_RF_L()
#define ChkL1MsgFltr_MMRF_TRC_PMIC_PWM_STATUS()	ChkL1ClsFltr_MML1_RF_MML1_RF_M()
#define ChkL1MsgFltr_MMRF_TRC_PMIC_PWM_BYRAT()	ChkL1ClsFltr_MML1_RF_MML1_RF_M()
#define ChkL1MsgFltr_MMRF_TRC_PMIC_VPA_CONTROL()	ChkL1ClsFltr_MML1_RF_MML1_RF_M()
#define ChkL1MsgFltr_MMRF_TRC_PMIC_MISC_CTRL()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_PMIC_OC_STATUS()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_PMIC_DCXO_CTRL()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_PMIC_DCXO_PM_SWITCH()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_MIPI_Init()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_MIPI_PowerOn()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_MIPI_PowerOff()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_MIPI_ChipVersion()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_CONFLICT_RAT_CHECK()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_L2MD3_CCIRQ_INFO1()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_L2MD3_CCIRQ_INFO2()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_L2MD3_CCIRQ_INFO3()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_LOAD_VER()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_LOGGERPTR_DBG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGER_TIME_DBG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_BSI_CLK_CG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_AP_CCIRQ()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_TOPSM_VRF18_REQ()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_SPM_POWER_ON_VAL0()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_SPM_POWER_ON_VAL1()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_PCM_REG0()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_PCM_REG7()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_PCM_REG13()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_SPM_WAKEUP_STA()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_SPM_WAKEUP_EXT_STA()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_SPM_SRC_MASK()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_PCM_REG6()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_SPM_SW_FLAG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_SPM_SW_DBG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_SPM_REG15()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_WHILE_LOOP_BYPASS()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_SYSPLL_H_STATUS()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_SYSPLL_L_STATUS()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_VS1_STATUS()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGER_V2_DBG1()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2_L()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGER_V2_DBG2()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2_L()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGER_V2_DBG3()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2_L()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGER_V2_DBG4()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2_L()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGER_V2_DBG5()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2_L()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGERwTIME_V2_DBG1()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2T_H()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGERwTIME_V2_DBG2()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2T_H()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGERwTIME_V2_DBG3()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2T_H()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGERwTIME_V2_DBG4()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2T_H()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGERwTIME_V2_DBG5()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V2T_H()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGER_DBG()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V1_L()
#define ChkL1MsgFltr_MMRF_TRC_BSILOGGERwTIME_DBG()	ChkL1ClsFltr_MML1_RF_MML1_BSILOG_V1T_L()
#define ChkL1MsgFltr_MMRF_TRC_RFCW_DUMP_DBG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_D16_REG_DBG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_D32_REG_DBG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DEBUG1()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DEBUG2()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DEBUG3()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DEBUG4()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DEBUG5()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DEBUG6()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_DEBUG7()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_HEX_DEBUG1()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_HEX_DEBUG2()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_HEX_DEBUG3()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_HEX_DEBUG4()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_HEX_DEBUG5()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_HEX_DEBUG6()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_HEX_DEBUG7()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_UBIN_WMID()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_UBIN_SET_WMID()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_Current_AFC_SHM()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_C2K_POC_SET_DB_BEGIN()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_C2K_POC_SET_DB_END()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_C2K_POC_GET_RESULT_BEGIN()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_C2K_POC_GET_RESULT_END()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_C2K_POC_BEGIN()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMRF_TRC_C2K_POC_END()	ChkL1ClsFltr_MML1_RF_MML1_RF_H()
#define ChkL1MsgFltr_MMADT_TRC_BOOT_DL_RAT()	ChkL1ClsFltr_MML1_RF_MML1_ADT_H()
#define ChkL1MsgFltr_MMADT_TRC_UBIN_BOOT_DL_RAT()	ChkL1ClsFltr_MML1_RF_MML1_ADT_H()
#define ChkL1MsgFltr_MMADT_TRC_SCHEDULE_CONN_DL_RAT()	ChkL1ClsFltr_MML1_RF_MML1_ADT_H()
#define ChkL1MsgFltr_MMADT_TRC_SCHEDULE_DL_FINISH()	ChkL1ClsFltr_MML1_RF_MML1_ADT_H()
#define ChkL1MsgFltr_MMADT_TRC_SCHEDULE_UNLOAD()	ChkL1ClsFltr_MML1_RF_MML1_ADT_H()
#define ChkL1MsgFltr_MMADT_TRC_SCHEDULE_CANCEL_LOAD()	ChkL1ClsFltr_MML1_RF_MML1_ADT_H()
#define ChkL1MsgFltr_MMADT_TRC_SCHEDULE_LTE_SET_RAT()	ChkL1ClsFltr_MML1_RF_MML1_ADT_H()
#define ChkL1MsgFltr_MMADT_TRC_SCHEDULE_ADT_L_ACT()	ChkL1ClsFltr_MML1_RF_MML1_ADT_H()
#define ChkL1MsgFltr_MMADT_TRC_SCHEDULE_ADT_L_NO_ACT()	ChkL1ClsFltr_MML1_RF_MML1_ADT_H()
#define ChkL1MsgFltr_MMADT_TRC_SCHEDULE_IDLE_RAT()	ChkL1ClsFltr_MML1_RF_MML1_ADT_L()
#define ChkL1MsgFltr_MMRF_TRC_RECORD_TX_POWER_INIT()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_RECORD_TX_POWER()	ChkL1ClsFltr_MML1_RF_MML1_DBG_L()
#define ChkL1MsgFltr_MMRF_TRC_TPO_DBG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_TPO_UPDATE_DBG()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_RFDB_CRYSTAL_CHECK()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_INITIAL_READ_INFO()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_INITIAL_WRITE_INFO()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_AP_SENSOR_RELATIVE_GAP()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_AP_SENSOR_RELATIVE_UPDATE()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()
#define ChkL1MsgFltr_MMRF_TRC_AP_SENSOR_RELATIVE_STATUS()	ChkL1ClsFltr_MML1_RF_MML1_DBG_H()


#endif
