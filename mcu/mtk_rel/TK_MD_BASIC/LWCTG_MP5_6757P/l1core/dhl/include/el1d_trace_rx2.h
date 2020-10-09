#ifndef L1TRC_EL1D_RX2_DEF_H
#define L1TRC_EL1D_RX2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_RX_TIME_CRITICAL(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_RX_RAS_SWITCH(v1)  (unsigned char)(v1+3)
#define EL1D_TRC_STR_RX_FORCE_RXD(v1)  (unsigned char)(v1+5)
#define EL1D_TRC_STR_RX_FORCE_RXD_MOD(v1)  (unsigned char)(v1+9)
#define EL1D_TRC_STR_RX_LORX_EN_TYPE(v1)  (unsigned char)(v1+41)
#define EL1D_TRC_STR_RX_LORX_REQ_TYPE(v1)  (unsigned char)(v1+44)
#define EL1D_TRC_STR_RX_LORX_TEST_PATTERN(v1)  (unsigned char)(v1+48)
#define EL1D_TRC_STR_RX_LORX_TYPE(v1)  (unsigned char)(v1+52)
#define EL1D_TRC_STR_RX_LORX_NO_TRIG_REASON(v1)  (unsigned char)(v1+61)
#define EL1D_TRC_STR_RX_PO_MODE(v1)  (unsigned char)(v1+77)
#define EL1D_TRC_STR_RX_TAS_RX_ANT_MODE(v1)  (unsigned char)(v1+80)
#define EL1D_TRC_STR_RX_LPWR_ADAPT_MODE(v1)  (unsigned char)(v1+82)
#define EL1D_TRC_STR_RX_FSM_DCI_RPT_TYPE(v1)  (unsigned char)(v1+88)
#define EL1D_TRC_STR_RX_IDLE_PI_GEAR(v1)  (unsigned char)(v1+91)
#define EL1D_TRC_STR_RX_CA_TYPE(v1)  (unsigned char)(v1+97)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_PHY_CSIF_TICK_T1_TIME_M(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x003B, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PHY_CSIF_TICK_T1_TIME_M(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_PHY_CSIF_TICK_T1_TIME_M_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x003B, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_PHY_CSIF_TICK_T2_TIME_M(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x013B, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PHY_CSIF_TICK_T2_TIME_M(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_PHY_CSIF_TICK_T2_TIME_M_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x013B, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PHY_CSIF_TICK_T2_TIME_DBG_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x023B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PHY_CSIF_TICK_T2_TIME_DBG_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_PHY_CSIF_TICK_T2_TIME_DBG_H_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x023B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PUB_SET_MEAS_GAP_INFO_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x033B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PUB_SET_MEAS_GAP_INFO_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_PUB_SET_MEAS_GAP_INFO_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x033B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PUB_SET_CONN_DRX_CONFIG_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x043B, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PUB_SET_CONN_DRX_CONFIG_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_PUB_SET_CONN_DRX_CONFIG_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x043B, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PUB_SET_DATA_VOLTE_ONLY_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x053B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PUB_SET_DATA_VOLTE_ONLY_H(v1)
#endif
#define EL1D_TRC_RX2_PUB_SET_DATA_VOLTE_ONLY_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x053B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PUB_SET_TAS_RX_ANT_MODE_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x063B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PUB_SET_TAS_RX_ANT_MODE_H(v1)
#endif
#define EL1D_TRC_RX2_PUB_SET_TAS_RX_ANT_MODE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x063B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PUB_SET_TAS_TX_SWAP_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x073B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PUB_SET_TAS_TX_SWAP_H(v1)
#endif
#define EL1D_TRC_RX2_PUB_SET_TAS_TX_SWAP_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x073B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PUB_SET_FORCE_ACK_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x083B, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PUB_SET_FORCE_ACK_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_PUB_SET_FORCE_ACK_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x083B, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PUB_SET_GEMINI_FAKE_ACK_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x093B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PUB_SET_GEMINI_FAKE_ACK_H(v1, v2)
#endif
#define EL1D_TRC_RX2_PUB_SET_GEMINI_FAKE_ACK_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x093B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PUB_SET_RAS_DISABLE_BY_VZW_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A3B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PUB_SET_RAS_DISABLE_BY_VZW_H(v1)
#endif
#define EL1D_TRC_RX2_PUB_SET_RAS_DISABLE_BY_VZW_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A3B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PUB_SET_RX_PATH_BY_VZW_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B3B, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PUB_SET_RX_PATH_BY_VZW_H(v1, v2)
#endif
#define EL1D_TRC_RX2_PUB_SET_RX_PATH_BY_VZW_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B3B, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_PUB_SET_MBMS_AR_RESET_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C3B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_PUB_SET_MBMS_AR_RESET_H(v1)
#endif
#define EL1D_TRC_RX2_PUB_SET_MBMS_AR_RESET_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C3B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LCE_START_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D3B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LCE_START_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LCE_START_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D3B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LCE_STOP_H() do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E3B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LCE_STOP_H()
#endif
#define EL1D_TRC_RX2_LCE_STOP_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E3B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LCE_PULL_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F3B, (short)(v3)), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LCE_PULL_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LCE_PULL_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F3B, (short)(v3)), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LCE_REPORT_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x103B, (short)(v3)), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LCE_REPORT_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LCE_REPORT_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x103B, (short)(v3)), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_SET_INNER_LOW_POWER_CMD_M(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x113B, (unsigned short)(v11)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), (unsigned char)(v12), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_SET_INNER_LOW_POWER_CMD_M(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define EL1D_TRC_RX2_LPWR_SET_INNER_LOW_POWER_CMD_M_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_2S(0x113B, (unsigned short)(v11)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), (unsigned char)(v12), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_F1_UPDATE_ANT_Q_GOOD_ENOUGH_M(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x123B, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_F1_UPDATE_ANT_Q_GOOD_ENOUGH_M(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX2_LPWR_F1_UPDATE_ANT_Q_GOOD_ENOUGH_M_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x123B, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_F2_IS_SA_QUALIT_HAS_RISK_L(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x133B, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_F2_IS_SA_QUALIT_HAS_RISK_L(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX2_LPWR_F2_IS_SA_QUALIT_HAS_RISK_L_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x133B, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_GET_INTRA_NCM_RESULT_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x143B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), (char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_GET_INTRA_NCM_RESULT_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX2_LPWR_GET_INTRA_NCM_RESULT_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x143B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), (char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CHECK_VOICE_LIKE_FAIL_L(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x153B, (char)(v1), (unsigned char)(v3)), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CHECK_VOICE_LIKE_FAIL_L(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LPWR_CHECK_VOICE_LIKE_FAIL_L_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x153B, (char)(v1), (unsigned char)(v3)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_SET_AFC_RESULT_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x163B, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_SET_AFC_RESULT_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_SET_AFC_RESULT_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x163B, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_F1_TEST_MODE_FORCE_GEAR_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x173B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F1_TEST_MODE_FORCE_GEAR_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F1_TEST_MODE_FORCE_GEAR_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x173B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_F1_INJECT_MODE_FORCE_GEAR_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x183B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F1_INJECT_MODE_FORCE_GEAR_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F1_INJECT_MODE_FORCE_GEAR_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x183B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_F1_LOW_POWR_DISABLED_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x193B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F1_LOW_POWR_DISABLED_H(v1)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F1_LOW_POWR_DISABLED_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x193B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F1_UPDATE_SF_PARAM_M(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1A3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F1_UPDATE_SF_PARAM_M(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F1_UPDATE_SF_PARAM_M_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1A3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F1_SELECTED_GEAR_M(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F1_SELECTED_GEAR_M(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F1_SELECTED_GEAR_M_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_F1_MD_TIMER_EXPIRE_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C3B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F1_MD_TIMER_EXPIRE_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F1_MD_TIMER_EXPIRE_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C3B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F1_IS_VOLTE_AND_TM1_2_L(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F1_IS_VOLTE_AND_TM1_2_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F1_IS_VOLTE_AND_TM1_2_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_1_L(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E3B, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_1_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_1_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E3B, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_2_L(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_2_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_2_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_3_L(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x203B, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_3_L(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_3_L_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x203B, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_WT_POST_VRS_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x213B, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_WT_POST_VRS_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_WT_POST_VRS_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x213B, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_A_L(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x223B, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (char)(v5), (unsigned char)(v6), (char)(v7)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_A_L(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_A_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_4_DATA(TRC_MERGE_2S(0x223B, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (char)(v5), (unsigned char)(v6), (char)(v7)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_B_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x233B, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_B_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_B_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x233B, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_C_L(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x243B, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_C_L(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_C_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x243B, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_D_L(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x253B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_D_L(v1)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_D_L_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x253B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F4_SELECT_CTRL_CE_NORMAL_L(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x263B, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F4_SELECT_CTRL_CE_NORMAL_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F4_SELECT_CTRL_CE_NORMAL_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x263B, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_1_L(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x273B, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), (char)(v6), (char)(v7)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_1_L(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_1_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x273B, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), (char)(v6), (char)(v7)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_2_L(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x283B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_2_L(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_2_L_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x283B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_3_L(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x293B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_3_L(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_3_L_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x293B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_4_L(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_4_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_4_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_F6_CALC_SYNC_GATED_BITMAP_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2B3B, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_F6_CALC_SYNC_GATED_BITMAP_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_F6_CALC_SYNC_GATED_BITMAP_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2B3B, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_CONN_BLER_L(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_BLER_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_BLER_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_GEAR_H(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2D3B, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_GEAR_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_GEAR_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2D3B, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_SET_DRX_CYCLE_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E3B, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_SET_DRX_CYCLE_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_SET_DRX_CYCLE_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E3B, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_SET_DRX_OFF_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F3B, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_SET_DRX_OFF_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_SET_DRX_OFF_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F3B, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_SHIFT_SF_TICK_1_SYM_H(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x303B, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_SHIFT_SF_TICK_1_SYM_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_SHIFT_SF_TICK_1_SYM_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x303B, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_SET_TEST_MODE_PARAM_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x313B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_SET_TEST_MODE_PARAM_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_SET_TEST_MODE_PARAM_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x313B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_SET_INJECT_MODE_PARAM_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x323B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_SET_INJECT_MODE_PARAM_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_SET_INJECT_MODE_PARAM_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x323B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_STATISTICS_AFTER_POWER_ON_H(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x333B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_STATISTICS_AFTER_POWER_ON_H(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_STATISTICS_AFTER_POWER_ON_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x333B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_CONN_STATISTICS_LAST_CONN_H(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x343B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_CONN_STATISTICS_LAST_CONN_H(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX2_LPWR_CONN_STATISTICS_LAST_CONN_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x343B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_IDLE_LOW_POWR_DISABLED_H() do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x353B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_IDLE_LOW_POWR_DISABLED_H()
#endif
#define EL1D_TRC_RX2_LPWR_IDLE_LOW_POWR_DISABLED_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x353B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PI_LOW_POWER_FAIL_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x363B, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PI_LOW_POWER_FAIL_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PI_LOW_POWER_FAIL_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x363B, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_IDLE_FIRST_DUMP_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x373B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_IDLE_FIRST_DUMP_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_IDLE_FIRST_DUMP_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x373B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_IDLE_CTRL_STATUS_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x383B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_IDLE_CTRL_STATUS_H(v1)
#endif
#define EL1D_TRC_RX2_LPWR_IDLE_CTRL_STATUS_H_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x383B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_GEAR_BY_TM_FORCE_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x393B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_GEAR_BY_TM_FORCE_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_GEAR_BY_TM_FORCE_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x393B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_GEAR_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A3B, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_GEAR_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_GEAR_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A3B, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_RESULT_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3B3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_RESULT_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_RESULT_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3B3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_RAS_FACTORY_RX_MODE_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C3B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_RAS_FACTORY_RX_MODE_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_RAS_FACTORY_RX_MODE_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C3B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_LPWR_RAS_DISABLE_BY_VZW_H() do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D3B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_RAS_DISABLE_BY_VZW_H()
#endif
#define EL1D_TRC_RX2_LPWR_RAS_DISABLE_BY_VZW_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D3B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_TAS_TX_ANT_IDX_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E3B, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_TAS_TX_ANT_IDX_H(v1)
#endif
#define EL1D_TRC_RX2_LPWR_TAS_TX_ANT_IDX_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E3B, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_RAS_INNER_ANTENNA_SWITCH_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F3B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_RAS_INNER_ANTENNA_SWITCH_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_RAS_INNER_ANTENNA_SWITCH_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F3B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_RAS_F2_SELECT_ANT_FORCE_RXD_IMM_L(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x403B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_RAS_F2_SELECT_ANT_FORCE_RXD_IMM_L(v1)
#endif
#define EL1D_TRC_RX2_LPWR_RAS_F2_SELECT_ANT_FORCE_RXD_IMM_L_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x403B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_RAS_F2_SELECT_ANT_FORCE_RXD_L(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x413B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_RAS_F2_SELECT_ANT_FORCE_RXD_L(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_RAS_F2_SELECT_ANT_FORCE_RXD_L_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x413B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_RAS_FORCE_DL_RXD_MOD_BMP_L(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x423B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_RAS_FORCE_DL_RXD_MOD_BMP_L(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_RAS_FORCE_DL_RXD_MOD_BMP_L_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x423B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_RAS_ANTENNA_FINAL_STATUS_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x433B, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_RAS_ANTENNA_FINAL_STATUS_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_RAS_ANTENNA_FINAL_STATUS_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x433B, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_LORX_NOT_ALLOW_H() do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x443B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_NOT_ALLOW_H()
#endif
#define EL1D_TRC_RX2_LPWR_LORX_NOT_ALLOW_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x443B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_LPWR_LORX_TYPE_INFO_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x453B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_TYPE_INFO_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_TYPE_INFO_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x453B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_LORX_INNER_PROHIBIT_BMP_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x463B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_INNER_PROHIBIT_BMP_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_INNER_PROHIBIT_BMP_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x463B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_LPWR_LORX_RF_PROHIBIT_BMP_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x473B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_RF_PROHIBIT_BMP_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_RF_PROHIBIT_BMP_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x473B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_LORX_INNER_MODE_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x483B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_INNER_MODE_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_INNER_MODE_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x483B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_LORX_RF_MODE_M(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x493B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_RF_MODE_M(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_RF_MODE_M_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x493B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_LORX_IS_REMAINING_CRS_M(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_IS_REMAINING_CRS_M(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_IS_REMAINING_CRS_M_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A3B, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_LORX_TEST_PATTERN_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4B3B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_TEST_PATTERN_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_TEST_PATTERN_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4B3B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_LORX_SET_ALLOW_IN_CA_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C3B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_SET_ALLOW_IN_CA_H(v1)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_SET_ALLOW_IN_CA_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C3B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_LORX_NOT_ALLOW_IN_CA_H() do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D3B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_NOT_ALLOW_IN_CA_H()
#endif
#define EL1D_TRC_RX2_LPWR_LORX_NOT_ALLOW_IN_CA_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D3B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_LORX_RF_PROHIBIT_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E3B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_RF_PROHIBIT_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_RF_PROHIBIT_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E3B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_LORX_AGC_PROHIBIT_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F3B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_AGC_PROHIBIT_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_AGC_PROHIBIT_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F3B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_LORX_MIN_ON_SCNT_OVERFLOW_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x503B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_MIN_ON_SCNT_OVERFLOW_H(v1)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_MIN_ON_SCNT_OVERFLOW_H_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x503B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_LORX_INNRE_TRIGGER_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x513B, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_INNRE_TRIGGER_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_INNRE_TRIGGER_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x513B, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_LORX_INNRE_NO_TRIGGER_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x523B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_LORX_INNRE_NO_TRIGGER_H(v1)
#endif
#define EL1D_TRC_RX2_LPWR_LORX_INNRE_NO_TRIGGER_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x523B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_SET_FEC_MODE_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x533B, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_SET_FEC_MODE_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_SET_FEC_MODE_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x533B, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_DET_MODE_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x543B, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_DET_MODE_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_DET_MODE_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x543B, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD1_L(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x553B, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v8), (unsigned char)(v9)), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD1_L(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD1_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x553B, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v8), (unsigned char)(v9)), (long)(v6), (long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD2_L(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x563B, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD2_L(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD2_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x563B, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD3_L(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x573B, (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD3_L(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD3_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x573B, (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_H(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x583B, (unsigned short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_H(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x583B, (unsigned short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_ADAPT_REQ_IRR_GAP_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x593B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_REQ_IRR_GAP_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_REQ_IRR_GAP_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x593B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_ADAPT_CONFIRM_IRR_GAP_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5A3B, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_CONFIRM_IRR_GAP_H(v1)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_CONFIRM_IRR_GAP_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5A3B, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_ADAPT_SE_REGION_CHG_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5B3B, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_SE_REGION_CHG_H(v1)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_SE_REGION_CHG_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5B3B, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_HPM_TIMER_L(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C3B, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_HPM_TIMER_L(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_HPM_TIMER_L_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C3B, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_WPD_TRG_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5D3B, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_WPD_TRG_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_WPD_TRG_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5D3B, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_WPD_RESULTS_L(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x5E3B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v9), (unsigned char)(v10), TRC_BOXSTER_PAD), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_WPD_RESULTS_L(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_WPD_RESULTS_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_7_DATA(TRC_MERGE_2S(0x5E3B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v9), (unsigned char)(v10), TRC_BOXSTER_PAD), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_DEBUG_L(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5F3B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_DEBUG_L(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_DEBUG_L_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5F3B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_RESET_CR_AR_L(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x603B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_RESET_CR_AR_L(v1)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_RESET_CR_AR_L_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x603B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_LPWR_ADAPT_RESET_ARX_L(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x613B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_RESET_ARX_L(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_RESET_ARX_L_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x613B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_NVRAM_INFO_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x623B, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_NVRAM_INFO_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_LPWR_NVRAM_INFO_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x623B, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_LPWR_ADAPT_SE_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x633B, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_LPWR_ADAPT_SE_H(v1, v2)
#endif
#define EL1D_TRC_RX2_LPWR_ADAPT_SE_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x633B, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_DBG_TDB_DUMP_INJECT_STRING_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x643B, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG_TDB_DUMP_INJECT_STRING_H(v1, v2)
#endif
#define EL1D_TRC_RX2_DBG_TDB_DUMP_INJECT_STRING_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x643B, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_DBG_TDB_DUMP_INCORRECT_SCENARIO_H(v1) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x653B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG_TDB_DUMP_INCORRECT_SCENARIO_H(v1)
#endif
#define EL1D_TRC_RX2_DBG_TDB_DUMP_INCORRECT_SCENARIO_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x653B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_DBG_TDB_DUMP_H(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x663B, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD), (long)(v5), (long)(v6), (unsigned long)(v7), (unsigned long)(v8), (long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG_TDB_DUMP_H(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX2_DBG_TDB_DUMP_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_7_DATA(TRC_MERGE_2S(0x663B, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD), (long)(v5), (long)(v6), (unsigned long)(v7), (unsigned long)(v8), (long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_DBG_DSP_FEATURE_INJECT_STRING_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x673B, (char)(v1), (char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG_DSP_FEATURE_INJECT_STRING_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_DBG_DSP_FEATURE_INJECT_STRING_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x673B, (char)(v1), (char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_DBG1_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x683B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG1_H(v1, v2)
#endif
#define EL1D_TRC_RX2_DBG1_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x683B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_DBG2_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x693B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG2_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_DBG2_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x693B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_DBG3_H(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x6A3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG3_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_DBG3_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x6A3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_DBG4_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x6B3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG4_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_DBG4_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x6B3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_DBG1_M(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6C3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG1_M(v1, v2)
#endif
#define EL1D_TRC_RX2_DBG1_M_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6C3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_DBG2_M(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6D3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG2_M(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_DBG2_M_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6D3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_DBG3_M(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x6E3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG3_M(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_DBG3_M_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x6E3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_DBG4_M(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x6F3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG4_M(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_DBG4_M_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x6F3B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_DBG1_L(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x703B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG1_L(v1, v2)
#endif
#define EL1D_TRC_RX2_DBG1_L_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x703B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_DBG2_L(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x713B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG2_L(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_DBG2_L_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x713B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_DBG3_L(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x723B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG3_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_DBG3_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x723B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_DBG4_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x733B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_DBG4_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_DBG4_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x733B, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_XDBG1_H(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x743B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG1_H(v1, v2)
#endif
#define EL1D_TRC_RX2_XDBG1_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x743B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_XDBG2_H(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x753B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG2_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_XDBG2_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x753B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_XDBG3_H(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x763B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG3_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_XDBG3_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x763B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_XDBG4_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x773B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG4_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_XDBG4_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x773B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_XDBG1_M(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x783B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG1_M(v1, v2)
#endif
#define EL1D_TRC_RX2_XDBG1_M_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x783B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_XDBG2_M(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x793B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG2_M(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_XDBG2_M_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x793B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_XDBG3_M(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7A3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG3_M(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_XDBG3_M_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7A3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX2_XDBG4_M(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7B3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG4_M(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_XDBG4_M_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7B3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_XDBG1_L(v1, v2) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7C3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG1_L(v1, v2)
#endif
#define EL1D_TRC_RX2_XDBG1_L_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7C3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_XDBG2_L(v1, v2, v3) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7D3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG2_L(v1, v2, v3)
#endif
#define EL1D_TRC_RX2_XDBG2_L_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7D3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_XDBG3_L(v1, v2, v3, v4) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7E3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG3_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX2_XDBG3_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7E3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX2_XDBG4_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7F3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_XDBG4_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_XDBG4_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7F3B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_ARM_CYCLE_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x803B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX2_ARM_CYCLE_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX2_ARM_CYCLE_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x803B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_ARM_CYCLE_ERROR_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x813B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX2_ARM_CYCLE_ERROR_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX2_ARM_CYCLE_ERROR_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x813B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_ARM_CYCLE_TOTAL_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x823B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_ARM_CYCLE_TOTAL_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_ARM_CYCLE_TOTAL_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x823B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX2_ARM_CYCLE_TOTAL_ERROR_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX2_Trace_Filter[0]==1 && (EL1D_RX2_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x833B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX2_ARM_CYCLE_TOTAL_ERROR_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX2_ARM_CYCLE_TOTAL_ERROR_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x833B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (unsigned long)(v5))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_RX2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_RX2_PHY_CSIF_TICK_T1_TIME_M(unsigned short v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX2_PHY_CSIF_TICK_T2_TIME_M(unsigned short v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX2_PHY_CSIF_TICK_T2_TIME_DBG_H(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX2_PUB_SET_MEAS_GAP_INFO_H(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX2_PUB_SET_CONN_DRX_CONFIG_H(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_RX2_PUB_SET_DATA_VOLTE_ONLY_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_PUB_SET_TAS_RX_ANT_MODE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_PUB_SET_TAS_TX_SWAP_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_PUB_SET_FORCE_ACK_H(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_RX2_PUB_SET_GEMINI_FAKE_ACK_H(unsigned char v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_RX2_PUB_SET_RAS_DISABLE_BY_VZW_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_PUB_SET_RX_PATH_BY_VZW_H(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_PUB_SET_MBMS_AR_RESET_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_LCE_START_H(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX2_LCE_STOP_H(void);
void L1TRC_Send_EL1D_TRC_RX2_LCE_PULL_H(long v1, long v2, short v3);
void L1TRC_Send_EL1D_TRC_RX2_LCE_REPORT_H(long v1, long v2, short v3);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_SET_INNER_LOW_POWER_CMD_M(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned short v11, unsigned char v12);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_F1_UPDATE_ANT_Q_GOOD_ENOUGH_M(char v1, unsigned char v2, char v3, char v4, unsigned long v5, char v6);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_F2_IS_SA_QUALIT_HAS_RISK_L(char v1, short v2, char v3, char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_GET_INTRA_NCM_RESULT_H(char v1, short v2, short v3, short v4, short v5, char v6);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CHECK_VOICE_LIKE_FAIL_L(char v1, long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_SET_AFC_RESULT_L(char v1, unsigned char v2, unsigned char v3, unsigned char v4, long v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F1_TEST_MODE_FORCE_GEAR_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F1_INJECT_MODE_FORCE_GEAR_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F1_LOW_POWR_DISABLED_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F1_UPDATE_SF_PARAM_M(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F1_SELECTED_GEAR_M(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F1_MD_TIMER_EXPIRE_H(unsigned char v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F1_IS_VOLTE_AND_TM1_2_L(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_1_L(unsigned char v1, char v2, char v3, short v4);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_2_L(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_3_L(unsigned char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_WT_POST_VRS_L(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_A_L(unsigned char v1, char v2, unsigned short v3, unsigned char v4, char v5, unsigned char v6, char v7, unsigned char v8, unsigned short v9);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_B_L(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_C_L(unsigned char v1, char v2, char v3, char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_D_L(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F4_SELECT_CTRL_CE_NORMAL_L(unsigned char v1, char v2, unsigned char v3, char v4);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_1_L(unsigned char v1, short v2, unsigned long v3, unsigned long v4, unsigned char v5, char v6, char v7);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_2_L(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_3_L(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_4_L(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_F6_CALC_SYNC_GATED_BITMAP_H(unsigned char v1, unsigned short v2, unsigned short v3, unsigned char v4, unsigned char v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_BLER_L(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_GEAR_H(char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_SET_DRX_CYCLE_H(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_SET_DRX_OFF_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_SHIFT_SF_TICK_1_SYM_H(unsigned char v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_SET_TEST_MODE_PARAM_H(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_SET_INJECT_MODE_PARAM_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_STATISTICS_AFTER_POWER_ON_H(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_CONN_STATISTICS_LAST_CONN_H(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_IDLE_LOW_POWR_DISABLED_H(void);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_IDLE_CALC_PI_LOW_POWER_FAIL_H(char v1, char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_IDLE_FIRST_DUMP_H(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_IDLE_CTRL_STATUS_H(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_GEAR_BY_TM_FORCE_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_GEAR_H(unsigned char v1, unsigned char v2, unsigned short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_RESULT_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_RAS_FACTORY_RX_MODE_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_RAS_DISABLE_BY_VZW_H(void);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_TAS_TX_ANT_IDX_H(char v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_RAS_INNER_ANTENNA_SWITCH_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_RAS_F2_SELECT_ANT_FORCE_RXD_IMM_L(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_RAS_F2_SELECT_ANT_FORCE_RXD_L(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_RAS_FORCE_DL_RXD_MOD_BMP_L(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_RAS_ANTENNA_FINAL_STATUS_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned short v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_NOT_ALLOW_H(void);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_TYPE_INFO_H(unsigned char v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_INNER_PROHIBIT_BMP_H(unsigned char v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_RF_PROHIBIT_BMP_H(unsigned char v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_INNER_MODE_L(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_RF_MODE_M(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_IS_REMAINING_CRS_M(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_TEST_PATTERN_H(unsigned char v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_SET_ALLOW_IN_CA_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_NOT_ALLOW_IN_CA_H(void);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_RF_PROHIBIT_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_AGC_PROHIBIT_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_MIN_ON_SCNT_OVERFLOW_H(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_INNRE_TRIGGER_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_LORX_INNRE_NO_TRIGGER_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_SET_FEC_MODE_H(unsigned char v1, short v2, short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_DET_MODE_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, short v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD1_L(unsigned char v1, short v2, unsigned char v3, short v4, short v5, long v6, long v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD2_L(unsigned char v1, long v2, long v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD3_L(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_H(unsigned char v1, unsigned short v2, unsigned char v3, short v4, short v5, short v6, long v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_REQ_IRR_GAP_H(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_CONFIRM_IRR_GAP_H(short v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_SE_REGION_CHG_H(unsigned short v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_HPM_TIMER_L(unsigned char v1, short v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_WPD_TRG_L(unsigned char v1, short v2, short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_WPD_RESULTS_L(unsigned char v1, short v2, short v3, short v4, long v5, long v6, long v7, long v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_DEBUG_L(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_RESET_CR_AR_L(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_RESET_ARX_L(short v1, short v2);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_NVRAM_INFO_H(char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_RX2_LPWR_ADAPT_SE_H(char v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_RX2_DBG_TDB_DUMP_INJECT_STRING_H(char v1, char v2);
void L1TRC_Send_EL1D_TRC_RX2_DBG_TDB_DUMP_INCORRECT_SCENARIO_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX2_DBG_TDB_DUMP_H(char v1, short v2, char v3, char v4, long v5, long v6, unsigned long v7, unsigned long v8, long v9);
void L1TRC_Send_EL1D_TRC_RX2_DBG_DSP_FEATURE_INJECT_STRING_H(char v1, unsigned long v2, char v3);
void L1TRC_Send_EL1D_TRC_RX2_DBG1_H(char v1, long v2);
void L1TRC_Send_EL1D_TRC_RX2_DBG2_H(char v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_RX2_DBG3_H(char v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RX2_DBG4_H(char v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RX2_DBG1_M(char v1, long v2);
void L1TRC_Send_EL1D_TRC_RX2_DBG2_M(char v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_RX2_DBG3_M(char v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RX2_DBG4_M(char v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RX2_DBG1_L(char v1, long v2);
void L1TRC_Send_EL1D_TRC_RX2_DBG2_L(char v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_RX2_DBG3_L(char v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_RX2_DBG4_L(char v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RX2_XDBG1_H(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX2_XDBG2_H(char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX2_XDBG3_H(char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX2_XDBG4_H(char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX2_XDBG1_M(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX2_XDBG2_M(char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX2_XDBG3_M(char v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_EL1D_TRC_RX2_XDBG4_M(char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX2_XDBG1_L(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX2_XDBG2_L(char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX2_XDBG3_L(char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX2_XDBG4_L(char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX2_ARM_CYCLE_H(long v1, long v2, long v3, long v4, long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RX2_ARM_CYCLE_ERROR_H(long v1, long v2, long v3, long v4, long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RX2_ARM_CYCLE_TOTAL_H(long v1, long v2, long v3, long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX2_ARM_CYCLE_TOTAL_ERROR_H(long v1, long v2, long v3, long v4, unsigned long v5);

void Set_EL1D_RX2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_RX2()	(EL1D_RX2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PHY_H()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PHY_M()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PHY_L()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_M()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_L()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_M()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_M()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_L()	(ChkL1ModFltr_EL1D_RX2()&&((EL1D_RX2_Trace_Filter[2]&0x08)!=0))
#define ChkL1MsgFltr_EL1D_TRC_RX2_PHY_CSIF_TICK_T1_TIME_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PHY_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PHY_CSIF_TICK_T2_TIME_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PHY_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PHY_CSIF_TICK_T2_TIME_DBG_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PHY_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PUB_SET_MEAS_GAP_INFO_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PUB_SET_CONN_DRX_CONFIG_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PUB_SET_DATA_VOLTE_ONLY_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PUB_SET_TAS_RX_ANT_MODE_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PUB_SET_TAS_TX_SWAP_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PUB_SET_FORCE_ACK_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PUB_SET_GEMINI_FAKE_ACK_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PUB_SET_RAS_DISABLE_BY_VZW_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PUB_SET_RX_PATH_BY_VZW_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_PUB_SET_MBMS_AR_RESET_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LCE_START_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LCE_STOP_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LCE_PULL_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LCE_REPORT_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_PUB_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_SET_INNER_LOW_POWER_CMD_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_F1_UPDATE_ANT_Q_GOOD_ENOUGH_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_F2_IS_SA_QUALIT_HAS_RISK_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_GET_INTRA_NCM_RESULT_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CHECK_VOICE_LIKE_FAIL_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_SET_AFC_RESULT_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F1_TEST_MODE_FORCE_GEAR_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F1_INJECT_MODE_FORCE_GEAR_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F1_LOW_POWR_DISABLED_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F1_UPDATE_SF_PARAM_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F1_SELECTED_GEAR_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F1_MD_TIMER_EXPIRE_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F1_IS_VOLTE_AND_TM1_2_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_1_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_2_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F5_SELECT_FULL_SYNC_3_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_WT_POST_VRS_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_A_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_B_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_C_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F3_SELECT_DATA_CE_FULL_OP_D_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F4_SELECT_CTRL_CE_NORMAL_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_1_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_2_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_3_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F6_SELECT_NO_DOWN_SAMPLE_4_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_F6_CALC_SYNC_GATED_BITMAP_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_BLER_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_GEAR_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_SET_DRX_CYCLE_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_SET_DRX_OFF_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_SHIFT_SF_TICK_1_SYM_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_SET_TEST_MODE_PARAM_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_SET_INJECT_MODE_PARAM_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_STATISTICS_AFTER_POWER_ON_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_CONN_STATISTICS_LAST_CONN_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_IDLE_LOW_POWR_DISABLED_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_IDLE_CALC_PI_LOW_POWER_FAIL_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_IDLE_FIRST_DUMP_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_IDLE_CTRL_STATUS_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_GEAR_BY_TM_FORCE_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_GEAR_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_IDLE_CALC_PO_RESULT_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_RAS_FACTORY_RX_MODE_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_RAS_DISABLE_BY_VZW_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_TAS_TX_ANT_IDX_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_RAS_INNER_ANTENNA_SWITCH_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_RAS_F2_SELECT_ANT_FORCE_RXD_IMM_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_RAS_F2_SELECT_ANT_FORCE_RXD_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_RAS_FORCE_DL_RXD_MOD_BMP_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_RAS_ANTENNA_FINAL_STATUS_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_NOT_ALLOW_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_TYPE_INFO_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_INNER_PROHIBIT_BMP_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_RF_PROHIBIT_BMP_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_INNER_MODE_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_RF_MODE_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_IS_REMAINING_CRS_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_TEST_PATTERN_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_SET_ALLOW_IN_CA_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_NOT_ALLOW_IN_CA_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_RF_PROHIBIT_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_AGC_PROHIBIT_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_MIN_ON_SCNT_OVERFLOW_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_INNRE_TRIGGER_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_LORX_INNRE_NO_TRIGGER_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_SET_FEC_MODE_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_DET_MODE_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD1_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD2_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_CSD3_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_IN_PARAM_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_REQ_IRR_GAP_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_CONFIRM_IRR_GAP_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_SE_REGION_CHG_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_HPM_TIMER_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_WPD_TRG_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_WPD_RESULTS_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_DEBUG_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_RESET_CR_AR_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_RESET_ARX_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_NVRAM_INFO_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_LPWR_ADAPT_SE_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_LPW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG_TDB_DUMP_INJECT_STRING_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG_TDB_DUMP_INCORRECT_SCENARIO_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG_TDB_DUMP_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG_DSP_FEATURE_INJECT_STRING_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG1_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG2_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG3_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG4_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG1_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG2_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG3_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG4_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG1_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG2_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG3_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_DBG4_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG1_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG2_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG3_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG4_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG1_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG2_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG3_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG4_M()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_M()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG1_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG2_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG3_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_XDBG4_L()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_L()
#define ChkL1MsgFltr_EL1D_TRC_RX2_ARM_CYCLE_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_ARM_CYCLE_ERROR_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_ARM_CYCLE_TOTAL_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()
#define ChkL1MsgFltr_EL1D_TRC_RX2_ARM_CYCLE_TOTAL_ERROR_H()	ChkL1ClsFltr_EL1D_RX2_EL1D_TRC_RX2_DBG_H()


#endif
