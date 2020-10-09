#ifndef L1TRC_EL1_MAIN_DEF_H
#define L1TRC_EL1_MAIN_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1_BOOLING_Str(v1)  (unsigned char)(v1+0)
#define EL1_EFUSE_Str(v1)  (unsigned char)(v1+2)
#define EL1_BW_Str(v1)  (unsigned char)(v1+5)
#define EL1_CH_Str(v1)  (unsigned char)(v1+13)
#define EL1_CH_Evt_Str(v1)  (unsigned char)(v1+25)
#define EL1_CH_Ctrl_Str(v1)  (unsigned char)(v1+41)
#define EL1_CH_MainSt_Str(v1)  (unsigned char)(v1+47)
#define EL1_CH_ALLOC_TASK_CMD_Str(v1)  (unsigned char)(v1+55)
#define EL1_CH_ALLOC_TASK2RX_CMD_Str(v1)  (unsigned char)(v1+59)
#define EL1_SCS_Ctrl_Str(v1)  (unsigned char)(v1+66)
#define EL1_DRX_Next_Str(v1)  (unsigned char)(v1+71)
#define EL1_DRX_Cycle_Str(v1)  (unsigned char)(v1+75)
#define EL1_BCCH_PURPOSE_Str(v1)  (unsigned char)(v1+77)
#define EL1_BCCH_TYPE_Str(v1)  (unsigned char)(v1+84)
#define EL1_PCH_NB_Str(v1)  (unsigned char)(v1+88)
#define EL1_PCH_MOD_Str(v1)  (unsigned char)(v1+96)
#define EL1_SCH_EVT_Str(v1)  (unsigned char)(v1+100)
#define EL1_CSR_Str(v1)  (unsigned char)(v1+109)
#define EL1_CSR_ST_Str(v1)  (unsigned char)(v1+117)
#define EL1_CSR_Purpose_Str(v1)  (unsigned char)(v1+124)
#define EL1_CSR_Cause_Str(v1)  (unsigned char)(v1+129)
#define EL1_CSR_CmdQStatus_Str(v1)  (unsigned char)(v1+132)
#define EL1_CSR_CmdQEnabled_Str(v1)  (unsigned char)(v1+137)
#define EL1_CSR_CmdType_Str(v1)  (unsigned char)(v1+139)
#define EL1_Duplex_Mode(v1)  (unsigned char)(v1+141)
#define EL1_CSR_SpecialType_Str(v1)  (unsigned char)(v1+144)
#define EL1_MEAS_CmdType_Str(v1)  (unsigned char)(v1+150)
#define EL1_MEAS_PhsCmdType_Str(v1)  (unsigned char)(v1+155)
#define EL1_MEAS_CmdQueueSt_Str(v1)  (unsigned char)(v1+165)
#define EL1_MEAS_MainSt_Str(v1)  (unsigned char)(v1+170)
#define EL1_MEAS_NaccSetting_Str(v1)  (unsigned char)(v1+175)
#define EL1_MEAS_NaccMode_Str(v1)  (unsigned char)(v1+180)
#define EL1_MEAS_Speed_Mode_Str(v1)  (unsigned char)(v1+184)
#define EL1_RNTI_Str0(v1)  (unsigned char)(v1+187)
#define EL1_RNTI_Str1(v1)  (unsigned char)(v1+195)
#define EL1_RNTI_Str2(v1)  (unsigned char)(v1+203)
#define EL1_RNTI_Str3(v1)  (unsigned char)(v1+211)
#define Rx_Qual_Str(v1)  (unsigned char)(v1+213)
#define EM_Func(v1)  (unsigned char)(v1+225)
#define LCE_Str(v1)  (unsigned char)(v1+227)
#define PWR_INJECT_Str(v1)  (unsigned char)(v1+230)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_RECAL_SLEEP_TIME(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0007, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_RECAL_SLEEP_TIME(v1, v2, v3)
#endif
#define EL1_RECAL_SLEEP_TIME_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0007, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_EFUSE_TURN_OFF(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0107, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_EFUSE_TURN_OFF(v1)
#endif
#define EL1_EFUSE_TURN_OFF_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0107, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_RXPATH_LOG(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0207, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_RXPATH_LOG(v1, v2)
#endif
#define EL1_RXPATH_LOG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0207, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_HRT_TIME_FORCE_ON(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x0307, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1_HRT_TIME_FORCE_ON(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1_HRT_TIME_FORCE_ON_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x0307, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CAPTURE_START(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0407, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1_CAPTURE_START(v1)
#endif
#define EL1_CAPTURE_START_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0407, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CAPTURE_STOP(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0507, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1_CAPTURE_STOP(v1)
#endif
#define EL1_CAPTURE_STOP_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0507, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CAPTURE_STOP_COUNT_DOWN(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0607, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CAPTURE_STOP_COUNT_DOWN(v1)
#endif
#define EL1_CAPTURE_STOP_COUNT_DOWN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0607, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_RNTI_PCELL(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0707, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_RNTI_PCELL(v1, v2, v3, v4, v5)
#endif
#define EL1_RNTI_PCELL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0707, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_RNTI_SCELL(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0807, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_RNTI_SCELL(v1, v2)
#endif
#define EL1_RNTI_SCELL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0807, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_RX_QUAL_RPT(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0907, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1_CH_RX_QUAL_RPT(v1, v2, v3, v4)
#endif
#define EL1_CH_RX_QUAL_RPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0907, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_DL_UL_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A07, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned char)(v6)), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1_CH_LOG_DL_UL_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_CH_LOG_DL_UL_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A07, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned char)(v6)), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_MCS_INFO(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B07, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_MCS_INFO(v1, v2, v3, v4)
#endif
#define EL1_CH_LOG_MCS_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B07, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_RX0_INFO(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C07, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_RX0_INFO(v1, v2, v3, v4)
#endif
#define EL1_CH_LOG_RX0_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C07, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_PWR0_INFO(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_PWR0_INFO(v1, v2, v3, v4, v5)
#endif
#define EL1_CH_LOG_PWR0_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_PWR1_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E07, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v6)), TRC_MERGE_4C((char)(v1), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_PWR1_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_CH_LOG_PWR1_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E07, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v6)), TRC_MERGE_4C((char)(v1), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_DRX_CFG(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F07, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_DRX_CFG(v1, v2, v3, v4, v5)
#endif
#define EL1_CH_DRX_CFG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F07, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_DRX_CFG1(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1007, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_DRX_CFG1(v1, v2, v3, v4)
#endif
#define EL1_CH_DRX_CFG1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1007, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_DRX_CYC_SLP_EN(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1107, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_CH_DRX_CYC_SLP_EN(v1, v2)
#endif
#define EL1_CH_DRX_CYC_SLP_EN_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1107, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_DRX_CYC_NTF(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1207, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_CH_DRX_CYC_NTF(v1, v2, v3)
#endif
#define EL1_CH_DRX_CYC_NTF_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1207, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_DRX_SLP_NTF(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1307, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_CH_DRX_SLP_NTF(v1, v2, v3, v4)
#endif
#define EL1_CH_DRX_SLP_NTF_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1307, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1407, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_CH_LOG(v1, v2)
#endif
#define EL1_CH_LOG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1407, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG0(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1507, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_CH_LOG0(v1, v2, v3, v4, v5)
#endif
#define EL1_CH_LOG0_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1507, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG1(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG1(v1, v2, v3)
#endif
#define EL1_CH_LOG1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_DLCHG0(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1707, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_DLCHG0(v1, v2, v3, v4)
#endif
#define EL1_CH_DLCHG0_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1707, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_DLCHG1(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1807, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_DLCHG1(v1, v2)
#endif
#define EL1_CH_DLCHG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1807, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_DLCHG_SCELL(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1907, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_DLCHG_SCELL(v1, v2, v3)
#endif
#define EL1_CH_DLCHG_SCELL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1907, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_DLCHGRPT(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A07, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_CH_DLCHGRPT(v1, v2)
#endif
#define EL1_CH_DLCHGRPT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A07, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_PHS_CNF(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B07, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_CH_PHS_CNF(v1, v2)
#endif
#define EL1_CH_PHS_CNF_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B07, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_ALLOC_TASK_CMD(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C07, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_ALLOC_TASK_CMD(v1)
#endif
#define EL1_CH_LOG_ALLOC_TASK_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C07, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_ALLOC_TASK2RX_CMD(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D07, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_ALLOC_TASK2RX_CMD(v1)
#endif
#define EL1_CH_LOG_ALLOC_TASK2RX_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D07, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_MBSFN_CMD(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_MBSFN_CMD(v1, v2, v3, v4)
#endif
#define EL1_CH_LOG_MBSFN_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_SPEED_PHS_REQ() do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F07, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_SPEED_PHS_REQ()
#endif
#define EL1_CH_LOG_SPEED_PHS_REQ_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F07, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_USE_GLB_PHS_REQ() do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2007, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_USE_GLB_PHS_REQ()
#endif
#define EL1_CH_LOG_USE_GLB_PHS_REQ_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2007, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_CALL_PHS_REQ_API() do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2107, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_CALL_PHS_REQ_API()
#endif
#define EL1_CH_LOG_CALL_PHS_REQ_API_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2107, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG_CLR_SPEED_FLG() do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2207, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CH_LOG_CLR_SPEED_FLG()
#endif
#define EL1_CH_LOG_CLR_SPEED_FLG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2207, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_BCCH_LOG1(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2307, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_BCCH_LOG1(v1, v2, v3, v4)
#endif
#define EL1_BCCH_LOG1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2307, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_BCCH_LOG2(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2407, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_BCCH_LOG2(v1, v2)
#endif
#define EL1_BCCH_LOG2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2407, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_BCCH_MIB_RPT0(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2507, (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_BCCH_MIB_RPT0(v1, v2, v3, v4, v5)
#endif
#define EL1_BCCH_MIB_RPT0_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2507, (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_BCCH_MIB_RPT1(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_BCCH_MIB_RPT1(v1, v2, v3, v4)
#endif
#define EL1_BCCH_MIB_RPT1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_BCCH_SI_RPT(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2707, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_BCCH_SI_RPT(v1, v2, v3, v4)
#endif
#define EL1_BCCH_SI_RPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2707, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_PCH_LOG0(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2807, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_PCH_LOG0(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_PCH_LOG0_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2807, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_PCH_LOG1(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2907, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), (char)(v7), (char)(v8)));\
	} while(0)
#else
	#define EL1_PCH_LOG1(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1_PCH_LOG1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2907, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), (char)(v7), (char)(v8)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_PCH_PI_BUF_ALLOC(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A07, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_PCH_PI_BUF_ALLOC(v1, v2, v3)
#endif
#define EL1_PCH_PI_BUF_ALLOC_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A07, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_PCH_PI_RPT(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B07, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)));\
	} while(0)
#else
	#define EL1_PCH_PI_RPT(v1, v2, v3, v4)
#endif
#define EL1_PCH_PI_RPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B07, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_REQ(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_REQ(v1, v2, v3)
#endif
#define EL1_CSR_LOG_REQ_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_PARAM0(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2D07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_PARAM0(v1, v2, v3)
#endif
#define EL1_CSR_LOG_PARAM0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2D07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_PARAM1(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2E07, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1_CSR_LOG_PARAM1(v1, v2, v3)
#endif
#define EL1_CSR_LOG_PARAM1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2E07, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_CMD(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F07, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_CMD(v1)
#endif
#define EL1_CSR_LOG_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F07, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_START_CNF(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3007, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_CSR_LOG_START_CNF(v1, v2)
#endif
#define EL1_CSR_LOG_START_CNF_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3007, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_STOP_CNF(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3107, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_CSR_LOG_STOP_CNF(v1, v2)
#endif
#define EL1_CSR_LOG_STOP_CNF_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3107, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_PHS_REL() do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3207, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_PHS_REL()
#endif
#define EL1_CSR_LOG_PHS_REL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3207, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_REGEN_SRCH_LIST(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3307, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_REGEN_SRCH_LIST(v1, v2, v3)
#endif
#define EL1_CSR_LOG_REGEN_SRCH_LIST_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3307, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_RPT(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3407, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_RPT(v1, v2, v3)
#endif
#define EL1_CSR_LOG_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3407, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_MAX_RSSI_VALUE(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3507, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1_CSR_LOG_MAX_RSSI_VALUE(v1, v2, v3)
#endif
#define EL1_CSR_LOG_MAX_RSSI_VALUE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3507, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_CELL(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3607, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_CSR_LOG_CELL(v1, v2, v3, v4, v5)
#endif
#define EL1_CSR_LOG_CELL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3607, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_RCV_RPT(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3707, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_CSR_LOG_RCV_RPT(v1, v2, v3, v4, v5)
#endif
#define EL1_CSR_LOG_RCV_RPT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3707, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_FREQ_IDX(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3807, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_FREQ_IDX(v1, v2, v3, v4, v5)
#endif
#define EL1_CSR_LOG_FREQ_IDX_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3807, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_BandJDG(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3907, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define EL1_CSR_LOG_BandJDG(v1, v2, v3)
#endif
#define EL1_CSR_LOG_BandJDG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3907, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_SET_PWR_SCN_CMD(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_SET_PWR_SCN_CMD(v1, v2)
#endif
#define EL1_CSR_LOG_SET_PWR_SCN_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_CMD_Q_CONTROL(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B07, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_CMD_Q_CONTROL(v1)
#endif
#define EL1_CSR_CMD_Q_CONTROL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B07, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_CMD_Q_BEFORE_UPT(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C07, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_CMD_Q_BEFORE_UPT(v1, v2, v3, v4)
#endif
#define EL1_CSR_CMD_Q_BEFORE_UPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C07, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_CMD_Q_AFTER_UPT(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D07, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_CMD_Q_AFTER_UPT(v1, v2, v3, v4)
#endif
#define EL1_CSR_CMD_Q_AFTER_UPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D07, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_CMD_IS_LAST_CMD(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E07, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_CMD_IS_LAST_CMD(v1, v2, v3, v4)
#endif
#define EL1_CSR_CMD_IS_LAST_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E07, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_BEF_CMD_Q_QRY(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3F07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_BEF_CMD_Q_QRY(v1, v2, v3, v4, v5)
#endif
#define EL1_CSR_LOG_BEF_CMD_Q_QRY_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3F07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_AFT_CMD_Q_QRY(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4007, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_AFT_CMD_Q_QRY(v1, v2)
#endif
#define EL1_CSR_LOG_AFT_CMD_Q_QRY_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4007, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_REC_PTR(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4107, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_CSR_LOG_REC_PTR(v1, v2)
#endif
#define EL1_CSR_LOG_REC_PTR_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4107, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_NOT_VALID_CMD_QRY(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4207, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_NOT_VALID_CMD_QRY(v1, v2, v3)
#endif
#define EL1_CSR_LOG_NOT_VALID_CMD_QRY_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4207, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_CMD_Q_CS_Exe(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4307, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_CMD_Q_CS_Exe(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1_CSR_LOG_CMD_Q_CS_Exe_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4307, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_CMD_Q_PS_Exe(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4407, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v7)), TRC_MERGE_2S((short)(v8), (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_CMD_Q_PS_Exe(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1_CSR_LOG_CMD_Q_PS_Exe_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4407, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v7)), TRC_MERGE_2S((short)(v8), (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_CMD_Q_UPDT_STATUS(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4507, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_CMD_Q_UPDT_STATUS(v1, v2, v3, v4)
#endif
#define EL1_MEAS_LOG_CMD_Q_UPDT_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4507, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_CMD_Q_QUERY(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4607, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1_MEAS_LOG_CMD_Q_QUERY(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_CMD_Q_QUERY_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4607, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_CMD_Q_QUERY_AB(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4707, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_CMD_Q_QUERY_AB(v1, v2, v3, v4)
#endif
#define EL1_MEAS_LOG_CMD_Q_QUERY_AB_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4707, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_CMD_Q_QUERY_RLT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4807, (unsigned short)(v2)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_MEAS_LOG_CMD_Q_QUERY_RLT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_MEAS_LOG_CMD_Q_QUERY_RLT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4807, (unsigned short)(v2)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_CH_CELL_OFST(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4907, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1_MEAS_LOG_CH_CELL_OFST(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_MEAS_LOG_CH_CELL_OFST_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4907, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_CH_CELL_OFST2(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4A07, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_CH_CELL_OFST2(v1, v2, v3, v4)
#endif
#define EL1_MEAS_LOG_CH_CELL_OFST2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4A07, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_STATE(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B07, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_STATE(v1)
#endif
#define EL1_MEAS_LOG_MEAS_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B07, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_Q_REFRESH(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4C07, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_Q_REFRESH(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_MEAS_LOG_MEAS_Q_REFRESH_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4C07, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_IDLE_RULE_CHK(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4D07, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_IDLE_RULE_CHK(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1_MEAS_LOG_MEAS_IDLE_RULE_CHK_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4D07, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_BUILD_TBL(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E07, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_BUILD_TBL(v1, v2)
#endif
#define EL1_MEAS_LOG_MEAS_BUILD_TBL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E07, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_BUILD_TBL_HPS(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F07, (unsigned short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_BUILD_TBL_HPS(v1, v2)
#endif
#define EL1_MEAS_LOG_MEAS_BUILD_TBL_HPS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F07, (unsigned short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_BUILD_TBL_ADD(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x5007, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((short)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_BUILD_TBL_ADD(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_MEAS_LOG_MEAS_BUILD_TBL_ADD_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_2S(0x5007, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((short)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_DRX_PCELL_SCH() do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5107, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_DRX_PCELL_SCH()
#endif
#define EL1_MEAS_LOG_MEAS_DRX_PCELL_SCH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5107, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_PINTRA_TICK_INC(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5207, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define EL1_MEAS_LOG_PINTRA_TICK_INC(v1, v2, v3)
#endif
#define EL1_MEAS_LOG_PINTRA_TICK_INC_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5207, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_SINTRA_TICK_INC(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5307, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define EL1_MEAS_LOG_SINTRA_TICK_INC(v1, v2, v3)
#endif
#define EL1_MEAS_LOG_SINTRA_TICK_INC_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5307, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_ENQUEUE(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5407, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_ENQUEUE(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1_MEAS_LOG_MEAS_ENQUEUE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5407, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_CELL_ADD(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5507, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_CELL_ADD(v1, v2, v3, v4)
#endif
#define EL1_MEAS_LOG_MEAS_CELL_ADD_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5507, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_TIMER_STRT(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5607, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_TIMER_STRT(v1, v2, v3)
#endif
#define EL1_MEAS_LOG_MEAS_TIMER_STRT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5607, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_TIMER_TASK(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5707, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_TIMER_TASK(v1, v2, v3)
#endif
#define EL1_MEAS_LOG_MEAS_TIMER_TASK_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5707, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_ADD_CS(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5807, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v4), (unsigned char)(v5)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_ADD_CS(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_MEAS_ADD_CS_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5807, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v4), (unsigned char)(v5)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_ADD_MEAS2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5907, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((unsigned short)(v7), (char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_ADD_MEAS2(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_MEAS_LOG_MEAS_ADD_MEAS2_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5907, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((unsigned short)(v7), (char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_DRX_CS(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A07, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_DRX_CS(v1, v2)
#endif
#define EL1_MEAS_LOG_MEAS_DRX_CS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A07, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_DRX_CM(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5B07, (short)(v1)));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_DRX_CM(v1)
#endif
#define EL1_MEAS_LOG_MEAS_DRX_CM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5B07, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_CELL_DEL2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x5C07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_CELL_DEL2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1_MEAS_LOG_MEAS_CELL_DEL2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x5C07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_CELL_DEL(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5D07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_CELL_DEL(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_MEAS_CELL_DEL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5D07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_SIC_REC(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5E07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define EL1_MEAS_LOG_SIC_REC(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_SIC_REC_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5E07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_L1_FILTER(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5F07, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_4C((char)(v6), (char)(v7), (unsigned char)(v10), (unsigned char)(v11)));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_L1_FILTER(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1_MEAS_LOG_MEAS_L1_FILTER_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5F07, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_4C((char)(v6), (char)(v7), (unsigned char)(v10), (unsigned char)(v11)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_ENQUEUE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6007, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_ENQUEUE(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_MEAS_ENQUEUE_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6007, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_SCHDL_TICK_INTVL_Q(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6107, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_SCHDL_TICK_INTVL_Q(v1, v2)
#endif
#define EL1_MEAS_LOG_SCHDL_TICK_INTVL_Q_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6107, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_GAP_TICK_SHIFT_Q(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6207, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_GAP_TICK_SHIFT_Q(v1, v2, v3, v4)
#endif
#define EL1_MEAS_LOG_GAP_TICK_SHIFT_Q_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6207, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_INC_CELL_CS_CNT(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6307, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_INC_CELL_CS_CNT(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_INC_CELL_CS_CNT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6307, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_INC_CELL_CM_CNT(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6407, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_INC_CELL_CM_CNT(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_INC_CELL_CM_CNT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6407, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_INC_CELL_CS_SIC_CNT(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6507, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_INC_CELL_CS_SIC_CNT(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_INC_CELL_CS_SIC_CNT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6507, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_INC_CELL_CM_REF_CNT(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6607, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_INC_CELL_CM_REF_CNT(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_INC_CELL_CM_REF_CNT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6607, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_DEC_CELL_CS_CNT(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6707, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_DEC_CELL_CS_CNT(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_DEC_CELL_CS_CNT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6707, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_DEC_CELL_CM_CNT(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6807, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_DEC_CELL_CM_CNT(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_DEC_CELL_CM_CNT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6807, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_DEC_CELL_CS_SIC_CNT(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6907, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_DEC_CELL_CS_SIC_CNT(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_DEC_CELL_CS_SIC_CNT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6907, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_DEC_CELL_CM_REF_CNT(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6A07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_DEC_CELL_CM_REF_CNT(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_DEC_CELL_CM_REF_CNT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6A07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_INC_FREQ_CS_CNT(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6B07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_INC_FREQ_CS_CNT(v1, v2, v3)
#endif
#define EL1_MEAS_LOG_INC_FREQ_CS_CNT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6B07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_INC_FREQ_CM_CNT(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6C07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_INC_FREQ_CM_CNT(v1, v2, v3)
#endif
#define EL1_MEAS_LOG_INC_FREQ_CM_CNT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6C07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_DEC_FREQ_CS_CNT(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6D07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_DEC_FREQ_CS_CNT(v1, v2, v3)
#endif
#define EL1_MEAS_LOG_DEC_FREQ_CS_CNT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6D07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_DEC_FREQ_CM_CNT(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6E07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_DEC_FREQ_CM_CNT(v1, v2, v3)
#endif
#define EL1_MEAS_LOG_DEC_FREQ_CM_CNT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6E07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_RESET_CELL_ALL_CNT(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6F07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_MEAS_LOG_RESET_CELL_ALL_CNT(v1, v2, v3, v4)
#endif
#define EL1_MEAS_LOG_RESET_CELL_ALL_CNT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6F07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_SPEED_MODE_JDG(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x7007, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1_MEAS_LOG_SPEED_MODE_JDG(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_MEAS_LOG_SPEED_MODE_JDG_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x7007, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_NACC_MODE_JDG(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7107, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_NACC_MODE_JDG(v1, v2, v3, v4)
#endif
#define EL1_MEAS_LOG_NACC_MODE_JDG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7107, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_SIR_CAL(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x7207, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_SIR_CAL(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define EL1_MEAS_LOG_SIR_CAL_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_7_DATA(TRC_MERGE_2S(0x7207, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_DYN_SPD_CS_JDG(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7307, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_MEAS_LOG_DYN_SPD_CS_JDG(v1, v2, v3, v4)
#endif
#define EL1_MEAS_LOG_DYN_SPD_CS_JDG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7307, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_CS_SPEED_UP(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7407, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_CS_SPEED_UP(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_CS_SPEED_UP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7407, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_SPEED_CS_NTF(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7507, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_SPEED_CS_NTF(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_MEAS_LOG_SPEED_CS_NTF_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7507, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_SPEED_CS_NTF2() do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7607, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_SPEED_CS_NTF2()
#endif
#define EL1_MEAS_LOG_SPEED_CS_NTF2_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7607, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MAX_RSRP_VALUE(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7707, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MAX_RSRP_VALUE(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_MAX_RSRP_VALUE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7707, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_CS_CONT_CHK(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7807, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_CS_CONT_CHK(v1, v2, v3)
#endif
#define EL1_MEAS_LOG_MEAS_CS_CONT_CHK_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7807, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_MEAS_LOG_MEAS_GAP_CS_CHK(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7907, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v3), (unsigned char)(v4)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1_MEAS_LOG_MEAS_GAP_CS_CHK(v1, v2, v3, v4, v5)
#endif
#define EL1_MEAS_LOG_MEAS_GAP_CS_CHK_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7907, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v3), (unsigned char)(v4)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_UPDT_NEXT_PRS(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7A07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_LPP_UPDT_NEXT_PRS(v1, v2, v3, v4)
#endif
#define EL1_LPP_UPDT_NEXT_PRS_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7A07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_IS_MUTE_NBR(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7B07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_LPP_IS_MUTE_NBR(v1, v2, v3)
#endif
#define EL1_LPP_IS_MUTE_NBR_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7B07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_UPDT_NEXT_REF(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7C07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_LPP_UPDT_NEXT_REF(v1, v2, v3, v4)
#endif
#define EL1_LPP_UPDT_NEXT_REF_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7C07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_UPDT_NBR_DATA(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x7D07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1_LPP_UPDT_NBR_DATA(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1_LPP_UPDT_NBR_DATA_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x7D07, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_GAP(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x7E07, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1_LPP_GAP(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_LPP_GAP_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x7E07, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_GAP_PRS_DIFF(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7F07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_LPP_GAP_PRS_DIFF(v1, v2)
#endif
#define EL1_LPP_GAP_PRS_DIFF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7F07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LCE_INFO(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8007, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_LCE_INFO(v1, v2, v3, v4)
#endif
#define EL1_LCE_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8007, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LCE_INFO2(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8107, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_LCE_INFO2(v1, v2, v3)
#endif
#define EL1_LCE_INFO2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8107, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LOG_PWR_INJECT(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8207, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_LOG_PWR_INJECT(v1, v2)
#endif
#define EL1_LOG_PWR_INJECT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8207, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_MAIN_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1_RECAL_SLEEP_TIME(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1_EFUSE_TURN_OFF(unsigned char v1);
void L1TRC_Send_EL1_RXPATH_LOG(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_HRT_TIME_FORCE_ON(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1_CAPTURE_START(unsigned long v1);
void L1TRC_Send_EL1_CAPTURE_STOP(unsigned long v1);
void L1TRC_Send_EL1_CAPTURE_STOP_COUNT_DOWN(unsigned char v1);
void L1TRC_Send_EL1_RNTI_PCELL(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1_RNTI_SCELL(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_CH_RX_QUAL_RPT(unsigned char v1, char v2, short v3, short v4);
void L1TRC_Send_EL1_CH_LOG_DL_UL_INFO(unsigned char v1, char v2, unsigned char v3, unsigned short v4, unsigned long v5, unsigned char v6);
void L1TRC_Send_EL1_CH_LOG_MCS_INFO(unsigned char v1, char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1_CH_LOG_RX0_INFO(char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_EL1_CH_LOG_PWR0_INFO(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1_CH_LOG_PWR1_INFO(char v1, short v2, short v3, unsigned char v4, char v5, unsigned short v6);
void L1TRC_Send_EL1_CH_DRX_CFG(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_EL1_CH_DRX_CFG1(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1_CH_DRX_CYC_SLP_EN(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_CH_DRX_CYC_NTF(unsigned short v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1_CH_DRX_SLP_NTF(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_EL1_CH_LOG(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_CH_LOG0(unsigned char v1, unsigned char v2, unsigned long v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_CH_LOG1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1_CH_DLCHG0(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_EL1_CH_DLCHG1(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1_CH_DLCHG_SCELL(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1_CH_DLCHGRPT(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_CH_PHS_CNF(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_CH_LOG_ALLOC_TASK_CMD(unsigned char v1);
void L1TRC_Send_EL1_CH_LOG_ALLOC_TASK2RX_CMD(unsigned char v1);
void L1TRC_Send_EL1_CH_LOG_MBSFN_CMD(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1_CH_LOG_SPEED_PHS_REQ(void);
void L1TRC_Send_EL1_CH_LOG_USE_GLB_PHS_REQ(void);
void L1TRC_Send_EL1_CH_LOG_CALL_PHS_REQ_API(void);
void L1TRC_Send_EL1_CH_LOG_CLR_SPEED_FLG(void);
void L1TRC_Send_EL1_BCCH_LOG1(unsigned char v1, unsigned char v2, char v3, unsigned char v4);
void L1TRC_Send_EL1_BCCH_LOG2(unsigned char v1, short v2);
void L1TRC_Send_EL1_BCCH_MIB_RPT0(unsigned char v1, unsigned char v2, short v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_EL1_BCCH_MIB_RPT1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1_BCCH_SI_RPT(unsigned char v1, unsigned char v2, unsigned char v3, short v4);
void L1TRC_Send_EL1_PCH_LOG0(unsigned short v1, unsigned short v2, unsigned short v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1_PCH_LOG1(unsigned short v1, unsigned short v2, unsigned char v3, unsigned char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_EL1_PCH_PI_BUF_ALLOC(unsigned char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1_PCH_PI_RPT(unsigned char v1, unsigned short v2, char v3, short v4);
void L1TRC_Send_EL1_CSR_LOG_REQ(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1_CSR_LOG_PARAM0(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1_CSR_LOG_PARAM1(unsigned long v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1_CSR_LOG_CMD(unsigned char v1);
void L1TRC_Send_EL1_CSR_LOG_START_CNF(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_CSR_LOG_STOP_CNF(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_CSR_LOG_PHS_REL(void);
void L1TRC_Send_EL1_CSR_LOG_REGEN_SRCH_LIST(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1_CSR_LOG_RPT(unsigned char v1, unsigned short v2, short v3);
void L1TRC_Send_EL1_CSR_LOG_MAX_RSSI_VALUE(short v1, short v2, short v3);
void L1TRC_Send_EL1_CSR_LOG_CELL(unsigned char v1, unsigned short v2, unsigned long v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_CSR_LOG_RCV_RPT(unsigned short v1, short v2, unsigned short v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_EL1_CSR_LOG_FREQ_IDX(unsigned char v1, unsigned short v2, unsigned short v3, short v4, short v5);
void L1TRC_Send_EL1_CSR_LOG_BandJDG(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1_CSR_LOG_SET_PWR_SCN_CMD(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1_CSR_CMD_Q_CONTROL(unsigned char v1);
void L1TRC_Send_EL1_CSR_CMD_Q_BEFORE_UPT(short v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_EL1_CSR_CMD_Q_AFTER_UPT(short v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_EL1_CSR_CMD_IS_LAST_CMD(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_EL1_CSR_LOG_BEF_CMD_Q_QRY(unsigned short v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_EL1_CSR_LOG_AFT_CMD_Q_QRY(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1_CSR_LOG_REC_PTR(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1_CSR_LOG_NOT_VALID_CMD_QRY(unsigned short v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_EL1_CSR_LOG_CMD_Q_CS_Exe(unsigned char v1, unsigned short v2, unsigned short v3, unsigned char v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9);
void L1TRC_Send_EL1_CSR_LOG_CMD_Q_PS_Exe(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, short v5, unsigned char v6, short v7, short v8, unsigned short v9);
void L1TRC_Send_EL1_MEAS_LOG_CMD_Q_UPDT_STATUS(unsigned char v1, unsigned char v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_EL1_MEAS_LOG_CMD_Q_QUERY(unsigned char v1, unsigned short v2, unsigned short v3, unsigned char v4, unsigned long v5);
void L1TRC_Send_EL1_MEAS_LOG_CMD_Q_QUERY_AB(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1_MEAS_LOG_CMD_Q_QUERY_RLT(unsigned char v1, unsigned short v2, unsigned long v3, unsigned long v4, short v5, short v6);
void L1TRC_Send_EL1_MEAS_LOG_CH_CELL_OFST(unsigned long v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_EL1_MEAS_LOG_CH_CELL_OFST2(unsigned short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_STATE(unsigned char v1);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_Q_REFRESH(unsigned char v1, short v2, short v3, short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_IDLE_RULE_CHK(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_BUILD_TBL(short v1, short v2);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_BUILD_TBL_HPS(unsigned short v1, unsigned long v2);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_BUILD_TBL_ADD(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned long v5, unsigned long v6, short v7);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_DRX_PCELL_SCH(void);
void L1TRC_Send_EL1_MEAS_LOG_PINTRA_TICK_INC(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1_MEAS_LOG_SINTRA_TICK_INC(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_ENQUEUE(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_CELL_ADD(unsigned short v1, unsigned long v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_TIMER_STRT(unsigned short v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_TIMER_TASK(unsigned short v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_ADD_CS(unsigned short v1, unsigned long v2, unsigned short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_ADD_MEAS2(short v1, short v2, short v3, short v4, short v5, char v6, unsigned short v7);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_DRX_CS(short v1, short v2);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_DRX_CM(short v1);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_CELL_DEL2(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, short v7, short v8, short v9, short v10);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_CELL_DEL(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_MEAS_LOG_SIC_REC(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_L1_FILTER(short v1, short v2, short v3, short v4, unsigned short v5, char v6, char v7, unsigned short v8, unsigned short v9, unsigned char v10, unsigned char v11);
void L1TRC_Send_EL1_MEAS_ENQUEUE(char v1, char v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_EL1_MEAS_LOG_SCHDL_TICK_INTVL_Q(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1_MEAS_LOG_GAP_TICK_SHIFT_Q(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1_MEAS_LOG_INC_CELL_CS_CNT(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_MEAS_LOG_INC_CELL_CM_CNT(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_MEAS_LOG_INC_CELL_CS_SIC_CNT(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_MEAS_LOG_INC_CELL_CM_REF_CNT(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_MEAS_LOG_DEC_CELL_CS_CNT(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_MEAS_LOG_DEC_CELL_CM_CNT(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_MEAS_LOG_DEC_CELL_CS_SIC_CNT(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_MEAS_LOG_DEC_CELL_CM_REF_CNT(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_MEAS_LOG_INC_FREQ_CS_CNT(unsigned short v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_EL1_MEAS_LOG_INC_FREQ_CM_CNT(unsigned short v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_EL1_MEAS_LOG_DEC_FREQ_CS_CNT(unsigned short v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_EL1_MEAS_LOG_DEC_FREQ_CM_CNT(unsigned short v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_EL1_MEAS_LOG_RESET_CELL_ALL_CNT(unsigned short v1, unsigned long v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1_MEAS_LOG_SPEED_MODE_JDG(unsigned char v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1_MEAS_LOG_NACC_MODE_JDG(short v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_EL1_MEAS_LOG_SIR_CAL(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12);
void L1TRC_Send_EL1_MEAS_LOG_DYN_SPD_CS_JDG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1_MEAS_LOG_CS_SPEED_UP(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1_MEAS_LOG_SPEED_CS_NTF(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_EL1_MEAS_LOG_SPEED_CS_NTF2(void);
void L1TRC_Send_EL1_MEAS_LOG_MAX_RSRP_VALUE(short v1, short v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_CS_CONT_CHK(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1_MEAS_LOG_MEAS_GAP_CS_CHK(unsigned long v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned short v5);
void L1TRC_Send_EL1_LPP_UPDT_NEXT_PRS(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1_LPP_IS_MUTE_NBR(unsigned short v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1_LPP_UPDT_NEXT_REF(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1_LPP_UPDT_NBR_DATA(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1_LPP_GAP(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1_LPP_GAP_PRS_DIFF(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1_LCE_INFO(unsigned char v1, short v2, char v3, char v4);
void L1TRC_Send_EL1_LCE_INFO2(unsigned char v1, short v2, short v3);
void L1TRC_Send_EL1_LOG_PWR_INJECT(unsigned char v1, short v2);

void Set_EL1_MAIN_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_MAIN()	(EL1_MAIN_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_MAIN_el1_main_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_main_var_trace_l()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_MAIN_inject_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_rnti_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_bcch_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_pch_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_lce_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[2]&0x04)!=0))
#define ChkL1MsgFltr_EL1_RECAL_SLEEP_TIME()	ChkL1ClsFltr_EL1_MAIN_el1_main_var_trace()
#define ChkL1MsgFltr_EL1_EFUSE_TURN_OFF()	ChkL1ClsFltr_EL1_MAIN_el1_main_var_trace()
#define ChkL1MsgFltr_EL1_RXPATH_LOG()	ChkL1ClsFltr_EL1_MAIN_el1_main_var_trace()
#define ChkL1MsgFltr_EL1_HRT_TIME_FORCE_ON()	ChkL1ClsFltr_EL1_MAIN_el1_main_var_trace_l()
#define ChkL1MsgFltr_EL1_CAPTURE_START()	ChkL1ClsFltr_EL1_MAIN_inject_var_trace()
#define ChkL1MsgFltr_EL1_CAPTURE_STOP()	ChkL1ClsFltr_EL1_MAIN_inject_var_trace()
#define ChkL1MsgFltr_EL1_CAPTURE_STOP_COUNT_DOWN()	ChkL1ClsFltr_EL1_MAIN_inject_var_trace()
#define ChkL1MsgFltr_EL1_RNTI_PCELL()	ChkL1ClsFltr_EL1_MAIN_el1_rnti_trace()
#define ChkL1MsgFltr_EL1_RNTI_SCELL()	ChkL1ClsFltr_EL1_MAIN_el1_rnti_trace()
#define ChkL1MsgFltr_EL1_CH_RX_QUAL_RPT()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_DL_UL_INFO()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_MCS_INFO()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_RX0_INFO()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_PWR0_INFO()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_PWR1_INFO()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_DRX_CFG()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_DRX_CFG1()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_DRX_CYC_SLP_EN()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_DRX_CYC_NTF()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_DRX_SLP_NTF()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG0()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG1()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_DLCHG0()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_DLCHG1()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_DLCHG_SCELL()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_DLCHGRPT()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_PHS_CNF()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_ALLOC_TASK_CMD()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_ALLOC_TASK2RX_CMD()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_MBSFN_CMD()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_SPEED_PHS_REQ()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_USE_GLB_PHS_REQ()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_CALL_PHS_REQ_API()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG_CLR_SPEED_FLG()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_BCCH_LOG1()	ChkL1ClsFltr_EL1_MAIN_el1_bcch_var_trace()
#define ChkL1MsgFltr_EL1_BCCH_LOG2()	ChkL1ClsFltr_EL1_MAIN_el1_bcch_var_trace()
#define ChkL1MsgFltr_EL1_BCCH_MIB_RPT0()	ChkL1ClsFltr_EL1_MAIN_el1_bcch_var_trace()
#define ChkL1MsgFltr_EL1_BCCH_MIB_RPT1()	ChkL1ClsFltr_EL1_MAIN_el1_bcch_var_trace()
#define ChkL1MsgFltr_EL1_BCCH_SI_RPT()	ChkL1ClsFltr_EL1_MAIN_el1_bcch_var_trace()
#define ChkL1MsgFltr_EL1_PCH_LOG0()	ChkL1ClsFltr_EL1_MAIN_el1_pch_var_trace()
#define ChkL1MsgFltr_EL1_PCH_LOG1()	ChkL1ClsFltr_EL1_MAIN_el1_pch_var_trace()
#define ChkL1MsgFltr_EL1_PCH_PI_BUF_ALLOC()	ChkL1ClsFltr_EL1_MAIN_el1_pch_var_trace()
#define ChkL1MsgFltr_EL1_PCH_PI_RPT()	ChkL1ClsFltr_EL1_MAIN_el1_pch_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_REQ()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_PARAM0()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_PARAM1()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_CMD()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_START_CNF()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_STOP_CNF()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_PHS_REL()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_REGEN_SRCH_LIST()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_RPT()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_MAX_RSSI_VALUE()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_CELL()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_RCV_RPT()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_FREQ_IDX()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_BandJDG()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_SET_PWR_SCN_CMD()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_CMD_Q_CONTROL()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_CMD_Q_BEFORE_UPT()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_CMD_Q_AFTER_UPT()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_CMD_IS_LAST_CMD()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_BEF_CMD_Q_QRY()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_AFT_CMD_Q_QRY()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_REC_PTR()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_NOT_VALID_CMD_QRY()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_CMD_Q_CS_Exe()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_CMD_Q_PS_Exe()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_CMD_Q_UPDT_STATUS()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_CMD_Q_QUERY()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_CMD_Q_QUERY_AB()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_CMD_Q_QUERY_RLT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_CH_CELL_OFST()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_CH_CELL_OFST2()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_STATE()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_Q_REFRESH()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_IDLE_RULE_CHK()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_BUILD_TBL()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_BUILD_TBL_HPS()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_BUILD_TBL_ADD()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_DRX_PCELL_SCH()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_PINTRA_TICK_INC()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_SINTRA_TICK_INC()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_ENQUEUE()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_CELL_ADD()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_TIMER_STRT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_TIMER_TASK()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_ADD_CS()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_ADD_MEAS2()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_DRX_CS()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_DRX_CM()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_CELL_DEL2()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_CELL_DEL()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_SIC_REC()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_L1_FILTER()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_ENQUEUE()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_SCHDL_TICK_INTVL_Q()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_GAP_TICK_SHIFT_Q()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_INC_CELL_CS_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_INC_CELL_CM_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_INC_CELL_CS_SIC_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_INC_CELL_CM_REF_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_DEC_CELL_CS_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_DEC_CELL_CM_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_DEC_CELL_CS_SIC_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_DEC_CELL_CM_REF_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_INC_FREQ_CS_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_INC_FREQ_CM_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_DEC_FREQ_CS_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_DEC_FREQ_CM_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_RESET_CELL_ALL_CNT()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_SPEED_MODE_JDG()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_NACC_MODE_JDG()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_SIR_CAL()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_DYN_SPD_CS_JDG()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_CS_SPEED_UP()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_SPEED_CS_NTF()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_SPEED_CS_NTF2()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MAX_RSRP_VALUE()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_CS_CONT_CHK()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_MEAS_LOG_MEAS_GAP_CS_CHK()	ChkL1ClsFltr_EL1_MAIN_el1_meas_var_trace()
#define ChkL1MsgFltr_EL1_LPP_UPDT_NEXT_PRS()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LPP_IS_MUTE_NBR()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LPP_UPDT_NEXT_REF()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LPP_UPDT_NBR_DATA()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LPP_GAP()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LPP_GAP_PRS_DIFF()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LCE_INFO()	ChkL1ClsFltr_EL1_MAIN_el1_lce_var_trace()
#define ChkL1MsgFltr_EL1_LCE_INFO2()	ChkL1ClsFltr_EL1_MAIN_el1_lce_var_trace()
#define ChkL1MsgFltr_EL1_LOG_PWR_INJECT()	ChkL1ClsFltr_EL1_MAIN_el1_main_var_trace()


#endif
