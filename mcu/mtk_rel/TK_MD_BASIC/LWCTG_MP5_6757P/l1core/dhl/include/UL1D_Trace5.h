#ifndef L1TRC_UL1D_SIXTH_DEF_H
#define L1TRC_UL1D_SIXTH_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_DL_DCH_RECONFIG(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_DPCH_TYPE(v1)  (unsigned char)(v1+8)
#define UL1D_TRC_STR_UL_DPCH_CONFIG(v1)  (unsigned char)(v1+10)
#define UL1D_TRC_STR_DPC_MODE(v1)  (unsigned char)(v1+20)
#define UL1D_TRC_STR_NWSCAN_EVENT(v1)  (unsigned char)(v1+22)
#define UL1D_TRC_CM_CONFIG_STR(v1)  (unsigned char)(v1+28)
#define UL1D_TRC5_DL_CARR(v1)  (unsigned char)(v1+31)
#define UL1D_TRC_PhCHScramblingCodeUsage_STR(v1)  (unsigned char)(v1+33)
#define UL1D_TRC_STR_DSP_SM_STATE(v1)  (unsigned char)(v1+36)
#define UL1D_TRC_DSP_SM_WARN_MESSAGE_STR(v1)  (unsigned char)(v1+50)
#define UL1D_TRC_DSP_SM_MESSAGE_STR(v1)  (unsigned char)(v1+55)
#define UL1D_TRC_UBIN_SM_WARN_MESSAGE_STR(v1)  (unsigned char)(v1+78)
#define UL1D_TRC_UBIN_SM_MESSAGE_STR(v1)  (unsigned char)(v1+87)
#define UL1D_TRC_DSP_MD32_STR(v1)  (unsigned char)(v1+113)
#define UL1D_TRC_STR_DSP_PMDM_RELOADING_SM_STATE(v1)  (unsigned char)(v1+117)
#define UL1D_TRC_DSP_MML1_REC_RAT_INFO_STR(v1)  (unsigned char)(v1+126)
#define UL1D_TRC_DSP_MD32_CMIF_ZI_CAUSE_STR(v1)  (unsigned char)(v1+129)
#define UL1D_TRC_DSP_SRAM_TYPE_STR(v1)  (unsigned char)(v1+134)
#define UL1D_TRC_SLEEP_MESSAGE_STR(v1)  (unsigned char)(v1+137)
#define UL1D_TRC_DSP_DVFS_EVENT_STR(v1)  (unsigned char)(v1+145)
#define UL1D_TRC_DSP_DVFS_SCENARIO_STR(v1)  (unsigned char)(v1+150)
#define UL1D_TRC_UBIN_UMTS_DUPLEX_MODE_TYPE_STR(v1)  (unsigned char)(v1+155)
#define UL1D_TRC_UBIN_LTE_DUPLEX_MODE_TYPE_STR(v1)  (unsigned char)(v1+157)
#define UL1D_TRC_DSP_SRAM_CONFIG_STR(v1)  (unsigned char)(v1+160)
#define UL1D_TRC_ARX_VOTER(v1)  (unsigned char)(v1+164)
#define UL1D_TRC_ARX_POWER_MODE(v1)  (unsigned char)(v1+170)
#define UL1D_TRC_ARX_CMD_TYPE(v1)  (unsigned char)(v1+172)
#define UL1D_TRC_ARX_COMMITTEE_STATE(v1)  (unsigned char)(v1+176)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DL_DCH_UPDATE_RXBRP_ID(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0020, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_UPDATE_RXBRP_ID(v1, v2)
#endif
#define UL1D_TRC_DL_DCH_UPDATE_RXBRP_ID_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0020, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_DPCH_TYPE(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0120, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_DPCH_TYPE(v1)
#endif
#define UL1D_TRC_DL_DCH_DPCH_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0120, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_RECONFIG(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0220, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_RECONFIG(v1)
#endif
#define UL1D_TRC_DL_DCH_RECONFIG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0220, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0320, (unsigned short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define UL1D_TRC_DL_DCH_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0320, (unsigned short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_RXBRP_CALCULATE_PARAM() do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0420, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_RXBRP_CALCULATE_PARAM()
#endif
#define UL1D_TRC_DL_DCH_RXBRP_CALCULATE_PARAM_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0420, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_RXBRP_CONFIG() do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0520, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_RXBRP_CONFIG()
#endif
#define UL1D_TRC_DL_DCH_RXBRP_CONFIG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0520, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_DMA_DONE_POST_RECONFIG(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0620, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_DMA_DONE_POST_RECONFIG(v1)
#endif
#define UL1D_TRC_DL_DCH_DMA_DONE_POST_RECONFIG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0620, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_GET_RL_BUFFER(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0720, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_GET_RL_BUFFER(v1)
#endif
#define UL1D_TRC_DL_DCH_GET_RL_BUFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0720, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_FREE_RL_BUFFER(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0820, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_FREE_RL_BUFFER(v1)
#endif
#define UL1D_TRC_DL_DCH_FREE_RL_BUFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0820, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_GET_RXBRP_BUFFER(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0920, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_GET_RXBRP_BUFFER(v1)
#endif
#define UL1D_TRC_DL_DCH_GET_RXBRP_BUFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0920, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_FREE_RXBRP_BUFFER(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A20, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_FREE_RXBRP_BUFFER(v1)
#endif
#define UL1D_TRC_DL_DCH_FREE_RXBRP_BUFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A20, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_ADAPT_IOT_WORKAROUND(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B20, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_ADAPT_IOT_WORKAROUND(v1, v2)
#endif
#define UL1D_TRC_DL_DCH_ADAPT_IOT_WORKAROUND_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B20, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_CM_METHOD(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C20, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_CM_METHOD(v1, v2, v3)
#endif
#define UL1D_TRC_DL_DCH_CM_METHOD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C20, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_RECFG_EVENT(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D20, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_RECFG_EVENT(v1, v2)
#endif
#define UL1D_TRC_DL_DCH_RECFG_EVENT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D20, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_SET_RL_INFO(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E20, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_SET_RL_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DL_DCH_SET_RL_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E20, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DC_EDCH_FDPCH_RL_CFG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F20, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v6)));\
	} while(0)
#else
	#define UL1D_TRC_DC_EDCH_FDPCH_RL_CFG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_DC_EDCH_FDPCH_RL_CFG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F20, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_DL_RL_NUM(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1020, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_DL_RL_NUM(v1, v2)
#endif
#define UL1D_TRC_DL_DCH_DL_RL_NUM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1020, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_SYNCH_INFO(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1120, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_SYNCH_INFO(v1)
#endif
#define UL1D_TRC_DL_DCH_SYNCH_INFO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1120, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ARX_EVAL_RSLT(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1220, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_ARX_EVAL_RSLT(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_ARX_EVAL_RSLT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1220, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ARX_HAND_IN_RSLT(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1320, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_ARX_HAND_IN_RSLT(v1, v2, v3)
#endif
#define UL1D_TRC_ARX_HAND_IN_RSLT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1320, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ARX_ARBITRATE_RSLT(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1420, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ARX_ARBITRATE_RSLT(v1, v2, v3)
#endif
#define UL1D_TRC_ARX_ARBITRATE_RSLT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1420, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ARX_INJECT_CMD(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1520, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ARX_INJECT_CMD(v1)
#endif
#define UL1D_TRC_ARX_INJECT_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1520, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ARX_SNR(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1620, (unsigned char)(v7), (unsigned char)(v8)), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_ARX_SNR(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_ARX_SNR_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1620, (unsigned char)(v7), (unsigned char)(v8)), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ARX_SE(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1720, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ARX_SE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ARX_SE_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1720, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ARX_OB(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_12_DATA(TRC_MERGE_1S2C(0x1820, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11));\
	} while(0)
#else
	#define UL1D_TRC_ARX_OB(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define UL1D_TRC_ARX_OB_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_12_DATA(TRC_MERGE_1S2C(0x1820, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ARX_MODE(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1920, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ARX_MODE(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_ARX_MODE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1920, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ARX_GAP_DBG(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ARX_GAP_DBG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_ARX_GAP_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ARX_DECIDE_COMMITTEE_ONOFF(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1B20, (unsigned char)(v1), (char)(v5)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ARX_DECIDE_COMMITTEE_ONOFF(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_ARX_DECIDE_COMMITTEE_ONOFF_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1B20, (unsigned char)(v1), (char)(v5)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_OFF_SLOTFORMAT(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C20, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_OFF_SLOTFORMAT(v1)
#endif
#define UL1D_TRC_RXCRP_CHCFG_DLDCH_OFF_SLOTFORMAT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C20, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_CHEN(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D20, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_CHEN(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RXCRP_CHCFG_DLDCH_CHEN_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D20, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_SLOTFORMAT_INPUT(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1E20, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_SLOTFORMAT_INPUT(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RXCRP_CHCFG_DLDCH_SLOTFORMAT_INPUT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1E20, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_SLOTFORMAT(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F20, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_SLOTFORMAT(v1, v2, v3)
#endif
#define UL1D_TRC_RXCRP_CHCFG_DLDCH_SLOTFORMAT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F20, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_FRAMETICK(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2020, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_FRAMETICK(v1, v2, v3)
#endif
#define UL1D_TRC_RXCRP_CHCFG_DLDCH_FRAMETICK_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2020, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_START(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2120, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_START(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RXCRP_CHCFG_DLDCH_START_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2120, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_STOP() do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2220, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_DLDCH_STOP()
#endif
#define UL1D_TRC_RXCRP_CHCFG_DLDCH_STOP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2220, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_FDPCH_CC_START(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2320, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_FDPCH_CC_START(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RXCRP_CHCFG_FDPCH_CC_START_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2320, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_RL0_OFF_SLOTFORMAT(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2420, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_RL0_OFF_SLOTFORMAT(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RXCRP_CHCFG_RL0_OFF_SLOTFORMAT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2420, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_RL0_CHEN(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2520, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_RL0_CHEN(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RXCRP_CHCFG_RL0_CHEN_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2520, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_rl0_START_CPICH(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2620, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_rl0_START_CPICH(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RXCRP_CHCFG_rl0_START_CPICH_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2620, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_rl0_START_PHCH(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2720, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_rl0_START_PHCH(v1, v2)
#endif
#define UL1D_TRC_RXCRP_CHCFG_rl0_START_PHCH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2720, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXCRP_CHCFG_rl0_STOP() do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2820, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXCRP_CHCFG_rl0_STOP()
#endif
#define UL1D_TRC_RXCRP_CHCFG_rl0_STOP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2820, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_INI_PWR(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2920, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_INI_PWR(v1, v2, v3)
#endif
#define UL1D_TRC_UL_DCH_INI_PWR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2920, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_HISR_PARAM_INFO(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_HISR_PARAM_INFO(v1, v2, v3)
#endif
#define UL1D_TRC_UL_DCH_HISR_PARAM_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_UL_DCH_HISR_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B20, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_HISR_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_UL_DCH_HISR_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B20, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_UL_DCH_CONFIG_INFO(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C20, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_CONFIG_INFO(v1, v2)
#endif
#define UL1D_TRC_UL_DCH_CONFIG_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C20, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DPC_FDPCH_CER_TARGET(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D20, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_CER_TARGET(v1, v2)
#endif
#define UL1D_TRC_DPC_FDPCH_CER_TARGET_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D20, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_FDPCH_SIR_TARGET(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E20, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_SIR_TARGET(v1, v2, v3)
#endif
#define UL1D_TRC_DPC_FDPCH_SIR_TARGET_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E20, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_FDPCH_RMIS(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F20, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_RMIS(v1, v2, v3)
#endif
#define UL1D_TRC_DPC_FDPCH_RMIS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F20, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_FDPCH_RMIS_EST(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3020, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_RMIS_EST(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_DPC_FDPCH_RMIS_EST_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3020, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_FDPCH_ADJUST(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3120, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_ADJUST(v1, v2, v3)
#endif
#define UL1D_TRC_DPC_FDPCH_ADJUST_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3120, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DPC_FDPCH_RMIS_RATE(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3220, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_RMIS_RATE(v1, v2)
#endif
#define UL1D_TRC_DPC_FDPCH_RMIS_RATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3220, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_FDPCH_WIND_UP_DOWN(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3320, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_WIND_UP_DOWN(v1, v2, v3)
#endif
#define UL1D_TRC_DPC_FDPCH_WIND_UP_DOWN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3320, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_FDPCH_DBG3(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3420, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_DBG3(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DPC_FDPCH_DBG3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3420, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_RXSRP_SIG_AMP(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3520, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_RXSRP_SIG_AMP(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_DPC_RXSRP_SIG_AMP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3520, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DPC_RXSRP_SVC_ID(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3620, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_RXSRP_SVC_ID(v1, v2)
#endif
#define UL1D_TRC_DPC_RXSRP_SVC_ID_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3620, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_Trc_DPC_CMD(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3720, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_DPC_CMD(v1, v2, v3, v4)
#endif
#define UL1D_Trc_DPC_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3720, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DPC_DBG_LEVEL1(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3820, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL1(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3820, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_TRCH_IND_MAP(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3920, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_TRCH_IND_MAP(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_TRCH_IND_MAP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3920, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_RECONFIG_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3A20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_RECONFIG_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_RECONFIG_FLAG_TRCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3A20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_EVAL_LIST(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3B20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_EVAL_LIST(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_EVAL_LIST_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3B20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_USE_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3C20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_USE_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_USE_FLAG_TRCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3C20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_VERY_LOW_BLER_FLAG(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3D20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_VERY_LOW_BLER_FLAG(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_VERY_LOW_BLER_FLAG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3D20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_BLOCK_TRCH_IND(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3E20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_BLOCK_TRCH_IND(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_BLOCK_TRCH_IND_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3E20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_ACTIVE_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3F20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_ACTIVE_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_ACTIVE_FLAG_TRCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3F20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_NUM_ERASED_BLK_ACQ(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4020, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_DPC_NUM_ERASED_BLK_ACQ(v1)
#endif
#define UL1D_TRC_DPC_NUM_ERASED_BLK_ACQ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4020, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_REF_TRCH_ELAPSED_FRAME_CNT(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4120, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DPC_REF_TRCH_ELAPSED_FRAME_CNT(v1, v2, v3)
#endif
#define UL1D_TRC_DPC_REF_TRCH_ELAPSED_FRAME_CNT_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4120, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_BLOCK_TRCH_TTI_CNT(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4220, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_BLOCK_TRCH_TTI_CNT(v1, v2)
#endif
#define UL1D_TRC_DPC_BLOCK_TRCH_TTI_CNT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4220, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DPCOUNTER_STARTED(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4320, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DPCOUNTER_STARTED(v1, v2)
#endif
#define UL1D_TRC_DPC_DPCOUNTER_STARTED_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4320, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_BLER_EST(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x4420, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_DPC_BLER_EST(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_DPC_BLER_EST_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x4420, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_SIR_MEASURED_DB(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4520, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DPC_SIR_MEASURED_DB(v1, v2, v3)
#endif
#define UL1D_TRC_DPC_SIR_MEASURED_DB_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4520, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_TRK_BACK_TO_ACQ_CHECK(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4620, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_TRK_BACK_TO_ACQ_CHECK(v1)
#endif
#define UL1D_TRC_DPC_TRK_BACK_TO_ACQ_CHECK_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4620, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_SUSPEND_WIND_UP_CHECK(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4720, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_SUSPEND_WIND_UP_CHECK(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DPC_SUSPEND_WIND_UP_CHECK_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4720, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DPC_DPCCH_INTEREFENCE_DETECT(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4820, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DPCCH_INTEREFENCE_DETECT(v1, v2, v3)
#endif
#define UL1D_TRC_DPC_DPCCH_INTEREFENCE_DETECT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4820, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_MEAS_CFG(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4920, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_NEW_MEAS_CFG(v1, v2, v3)
#endif
#define UL1D_TRC_NEW_MEAS_CFG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4920, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_SET_MEAS_CALLBACK(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4A20, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SET_MEAS_CALLBACK(v1, v2, v3)
#endif
#define UL1D_TRC_SET_MEAS_CALLBACK_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4A20, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GET_MEAS_CALLBACK(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4B20, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_GET_MEAS_CALLBACK(v1, v2, v3)
#endif
#define UL1D_TRC_GET_MEAS_CALLBACK_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4B20, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CONFIG_CELL_LIST(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4C20, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CONFIG_CELL_LIST(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_CONFIG_CELL_LIST_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4C20, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_50MS_RESET(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4D20, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_50MS_RESET(v1)
#endif
#define UL1D_TRC_50MS_RESET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4D20, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_50MS_CELL_CONFIG(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4E20, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_50MS_CELL_CONFIG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_50MS_CELL_CONFIG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4E20, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_50MS_LIST_FULL(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F20, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_50MS_LIST_FULL(v1, v2, v3)
#endif
#define UL1D_TRC_50MS_LIST_FULL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F20, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_50MS_CS4_INFO(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5020, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_50MS_CS4_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_50MS_CS4_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5020, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ENHANCED_CM_CELL(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5120, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ENHANCED_CM_CELL(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ENHANCED_CM_CELL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5120, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_TIMING_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5220, (unsigned short)(v1)), TRC_MERGE_2S((short)(v5), (short)(v6)), (long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_TIMING_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MEAS_TIMING_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5220, (unsigned short)(v1)), TRC_MERGE_2S((short)(v5), (short)(v6)), (long)(v2), (unsigned long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_INTER_FREQ_CHANGE_DURING_BCH_SFN(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5320, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_INTER_FREQ_CHANGE_DURING_BCH_SFN(v1, v2)
#endif
#define UL1D_TRC_INTER_FREQ_CHANGE_DURING_BCH_SFN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5320, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TRCH_BLER(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5420, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TRCH_BLER(v1, v2, v3, v4)
#endif
#define UL1D_TRC_TRCH_BLER_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5420, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TRCH_BLER_RESET(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5520, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TRCH_BLER_RESET(v1)
#endif
#define UL1D_TRC_TRCH_BLER_RESET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5520, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PICH_DISABLE(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5620, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PICH_DISABLE(v1)
#endif
#define UL1D_TRC_PICH_DISABLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5620, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PCH_TFCI_ADJ(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5720, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PCH_TFCI_ADJ(v1)
#endif
#define UL1D_TRC_PCH_TFCI_ADJ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5720, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PI_REPEAT(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5820, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PI_REPEAT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PI_REPEAT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5820, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DRX_CYCLE_CONFIG(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5920, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DRX_CYCLE_CONFIG(v1, v2)
#endif
#define UL1D_TRC_DRX_CYCLE_CONFIG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5920, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NWSCAN_EVENT(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A20, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NWSCAN_EVENT(v1, v2, v3)
#endif
#define UL1D_TRC_NWSCAN_EVENT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A20, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NWSCAN_ADDNEWCELL(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5B20, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NWSCAN_ADDNEWCELL(v1, v2, v3, v4)
#endif
#define UL1D_TRC_NWSCAN_ADDNEWCELL_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5B20, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NWSCAN_FSCM_DONE(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C20, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_NWSCAN_FSCM_DONE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_NWSCAN_FSCM_DONE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C20, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NWSCAN_MEASCELLFULL(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5D20, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NWSCAN_MEASCELLFULL(v1, v2)
#endif
#define UL1D_TRC_NWSCAN_MEASCELLFULL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5D20, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_STATE_MACHINE(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5E20, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_STATE_MACHINE(v1, v2, v3)
#endif
#define UL1D_TRC_DSP_SM_STATE_MACHINE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5E20, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_CHANNEL_POWER_ON(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5F20, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_DSP_CHANNEL_POWER_ON(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DSP_CHANNEL_POWER_ON_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5F20, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DSP_SM_MML1_REC_RAT_INFO(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6020, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_MML1_REC_RAT_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DSP_SM_MML1_REC_RAT_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6020, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_LOCK_SLEEP(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6120, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_LOCK_SLEEP(v1, v2, v3)
#endif
#define UL1D_TRC_DSP_SM_LOCK_SLEEP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6120, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_VALID_CNT_CONFIG(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6220, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_VALID_CNT_CONFIG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DSP_SM_VALID_CNT_CONFIG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6220, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_MESSAGE(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6320, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_MESSAGE(v1, v2)
#endif
#define UL1D_TRC_DSP_SM_MESSAGE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6320, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DSP_SM_WARN_MESSAGE(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6420, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_WARN_MESSAGE(v1, v2)
#endif
#define UL1D_TRC_DSP_SM_WARN_MESSAGE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6420, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DSP_SM_WARN_BYPASS_BACKUP(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6520, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_WARN_BYPASS_BACKUP(v1, v2, v3)
#endif
#define UL1D_TRC_DSP_SM_WARN_BYPASS_BACKUP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6520, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_CONFIG_RAKE_T3_INIT(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6620, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_CONFIG_RAKE_T3_INIT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DSP_SM_CONFIG_RAKE_T3_INIT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6620, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_CONFIG_RAKE_LOADER_OFF(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6720, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_CONFIG_RAKE_LOADER_OFF(v1, v2, v3)
#endif
#define UL1D_TRC_DSP_SM_CONFIG_RAKE_LOADER_OFF_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6720, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_RAKE_T3_INIT(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6820, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_RAKE_T3_INIT(v1, v2)
#endif
#define UL1D_TRC_DSP_SM_RAKE_T3_INIT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6820, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_C2M_IRQ(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6920, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_C2M_IRQ(v1, v2, v3)
#endif
#define UL1D_TRC_DSP_SM_C2M_IRQ_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6920, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_M2C_IRQ(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6A20, (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_M2C_IRQ(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DSP_SM_M2C_IRQ_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6A20, (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_ALLOW_SLEEP(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6B20, (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_ALLOW_SLEEP(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_DSP_SM_ALLOW_SLEEP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6B20, (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SM_INIT_READY(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6C20, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_INIT_READY(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DSP_SM_INIT_READY_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6C20, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_DVFS_EQ_EXIST(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6D20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSP_DVFS_EQ_EXIST(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DSP_DVFS_EQ_EXIST_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6D20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_DVFS_EVENT_EXPIRE(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x6E20, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_DSP_DVFS_EVENT_EXPIRE(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_DSP_DVFS_EVENT_EXPIRE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_7_DATA(TRC_MERGE_2S(0x6E20, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_DVFS_EVENT_SET(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x6F20, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_DSP_DVFS_EVENT_SET(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_DSP_DVFS_EVENT_SET_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_7_DATA(TRC_MERGE_2S(0x6F20, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_DVFS_EVENT_CANCEL(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7020, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSP_DVFS_EVENT_CANCEL(v1, v2)
#endif
#define UL1D_TRC_DSP_DVFS_EVENT_CANCEL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7020, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_DVFS_EVENT_IDLE_LOCKED(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7120, (unsigned short)(v2)), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_DSP_DVFS_EVENT_IDLE_LOCKED(v1, v2)
#endif
#define UL1D_TRC_DSP_DVFS_EVENT_IDLE_LOCKED_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7120, (unsigned short)(v2)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DSP_DVFS_DBG(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7220, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_DSP_DVFS_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DSP_DVFS_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7220, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_DVFS_COMPILE_OPTION(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7320, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_DSP_DVFS_COMPILE_OPTION(v1, v2)
#endif
#define UL1D_TRC_DSP_DVFS_COMPILE_OPTION_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7320, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SRAM_PMDM_BITMAP_FEC(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x7420, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SRAM_PMDM_BITMAP_FEC(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1D_TRC_DSP_SRAM_PMDM_BITMAP_FEC_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_2S(0x7420, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SRAM_PMDM_BITMAP_RXBRP(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x7520, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SRAM_PMDM_BITMAP_RXBRP(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1D_TRC_DSP_SRAM_PMDM_BITMAP_RXBRP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_10_DATA(TRC_MERGE_2S(0x7520, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SRAM_SW_PWDN_STATUS_FEC(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7620, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SRAM_SW_PWDN_STATUS_FEC(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DSP_SRAM_SW_PWDN_STATUS_FEC_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7620, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SRAM_SW_PWDN_STATUS_RXBRP(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x7720, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SRAM_SW_PWDN_STATUS_RXBRP(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_DSP_SRAM_SW_PWDN_STATUS_RXBRP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x7720, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SRAM_PMDM_TYPE_FEC(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7820, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SRAM_PMDM_TYPE_FEC(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DSP_SRAM_PMDM_TYPE_FEC_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7820, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SRAM_PMDM_TYPE_RXBRP(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x7920, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SRAM_PMDM_TYPE_RXBRP(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_DSP_SRAM_PMDM_TYPE_RXBRP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x7920, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SRAM_CONFIG_PMDM_TYPE(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7A20, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SRAM_CONFIG_PMDM_TYPE(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DSP_SRAM_CONFIG_PMDM_TYPE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7A20, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_SRAM_CONFIG_SW_PWDN(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7B20, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SRAM_CONFIG_SW_PWDN(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DSP_SRAM_CONFIG_SW_PWDN_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7B20, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DSP_SRAM_CONFIG(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7C20, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SRAM_CONFIG(v1, v2, v3)
#endif
#define UL1D_TRC_DSP_SRAM_CONFIG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7C20, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DSP_SM_MDL_STATUS(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x7D20, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_MDL_STATUS(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_DSP_SM_MDL_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x7D20, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DSP_SM_MDL_STATUS_RAKE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x7E20, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_MDL_STATUS_RAKE(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_DSP_SM_MDL_STATUS_RAKE_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x7E20, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DSP_SM_MDL_STATUS_BRP(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x7F20, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define UL1D_TRC_DSP_SM_MDL_STATUS_BRP(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_DSP_SM_MDL_STATUS_BRP_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x7F20, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SLEEP_MESSAGE(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8020, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SLEEP_MESSAGE(v1, v2)
#endif
#define UL1D_TRC_SLEEP_MESSAGE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8020, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CHECK_L1_ALLOW_SLEEP(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x8120, (unsigned short)(v5)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_CHECK_L1_ALLOW_SLEEP(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_CHECK_L1_ALLOW_SLEEP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x8120, (unsigned short)(v5)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SLEEP_LOCK(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8220, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SLEEP_LOCK(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_SLEEP_LOCK_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8220, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SLEEP_WAKEUP_ISR_EXE_TIME(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x8320, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_SLEEP_WAKEUP_ISR_EXE_TIME(v1, v2, v3)
#endif
#define UL1D_TRC_SLEEP_WAKEUP_ISR_EXE_TIME_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x8320, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SLEEP_EL1D_HRT_MARGIN_EVAL(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8420, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SLEEP_EL1D_HRT_MARGIN_EVAL(v1, v2, v3)
#endif
#define UL1D_TRC_SLEEP_EL1D_HRT_MARGIN_EVAL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8420, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SLEEP_DUMMY_SLOTTICK_WAKEUP(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8520, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SLEEP_DUMMY_SLOTTICK_WAKEUP(v1)
#endif
#define UL1D_TRC_SLEEP_DUMMY_SLOTTICK_WAKEUP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8520, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_PMDM_RELOADING_STATE_MACHINE(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8620, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DSP_PMDM_RELOADING_STATE_MACHINE(v1, v2)
#endif
#define UL1D_TRC_DSP_PMDM_RELOADING_STATE_MACHINE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8620, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DSP_PMDM_RELOADING_POLLING_MML1(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x8720, (char)(v2), (char)(v3)), (unsigned long)(v1), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_DSP_PMDM_RELOADING_POLLING_MML1(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DSP_PMDM_RELOADING_POLLING_MML1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x8720, (char)(v2), (char)(v3)), (unsigned long)(v1), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_UBIN_PMDM_QUERY_RESULT(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8820, (unsigned short)(v5)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_UBIN_PMDM_QUERY_RESULT(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_UBIN_PMDM_QUERY_RESULT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8820, (unsigned short)(v5)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_UBIN_TCM_POLLING_TDD_TIMER(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8920, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_UBIN_TCM_POLLING_TDD_TIMER(v1, v2)
#endif
#define UL1D_TRC_UBIN_TCM_POLLING_TDD_TIMER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8920, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_UBIN_MESSAGE(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8A20, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_UBIN_MESSAGE(v1, v2, v3)
#endif
#define UL1D_TRC_UBIN_MESSAGE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8A20, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UBIN_WARN_MESSAGE(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8B20, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_UBIN_WARN_MESSAGE(v1, v2, v3)
#endif
#define UL1D_TRC_UBIN_WARN_MESSAGE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8B20, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_UBIN_DUPLEX_MODE_CHANGE(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8C20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UBIN_DUPLEX_MODE_CHANGE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_UBIN_DUPLEX_MODE_CHANGE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8C20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_UBIN_SET_RAT_MODE(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8D20, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_UBIN_SET_RAT_MODE(v1, v2)
#endif
#define UL1D_TRC_UBIN_SET_RAT_MODE_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8D20, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_GSR_CTRL_CON_DBG1(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x8E20, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_GSR_CTRL_CON_DBG1(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_GSR_CTRL_CON_DBG1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x8E20, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_GSR_CTRL_CON_DBG2(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x8F20, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_GSR_CTRL_CON_DBG2(v1)
#endif
#define UL1D_TRC_GSR_CTRL_CON_DBG2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x8F20, (unsigned short)(v1)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_SIXTH_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_DL_DCH_UPDATE_RXBRP_ID(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_DL_DCH_DPCH_TYPE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_RECONFIG(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned short v8, short v9, short v10, short v11);
void L1TRC_Send_UL1D_TRC_DL_DCH_RXBRP_CALCULATE_PARAM(void);
void L1TRC_Send_UL1D_TRC_DL_DCH_RXBRP_CONFIG(void);
void L1TRC_Send_UL1D_TRC_DL_DCH_DMA_DONE_POST_RECONFIG(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_GET_RL_BUFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_FREE_RL_BUFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_GET_RXBRP_BUFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_FREE_RXBRP_BUFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_ADAPT_IOT_WORKAROUND(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_DL_DCH_CM_METHOD(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_DL_DCH_RECFG_EVENT(short v1, short v2);
void L1TRC_Send_UL1D_TRC_DL_DCH_SET_RL_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_DC_EDCH_FDPCH_RL_CFG(unsigned char v1, short v2, short v3, short v4, short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_DL_DCH_DL_RL_NUM(short v1, short v2);
void L1TRC_Send_UL1D_TRC_DL_DCH_SYNCH_INFO(short v1);
void L1TRC_Send_UL1D_TRC_ARX_EVAL_RSLT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_ARX_HAND_IN_RSLT(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_ARX_ARBITRATE_RSLT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_ARX_INJECT_CMD(unsigned char v1);
void L1TRC_Send_UL1D_TRC_ARX_SNR(long v1, long v2, long v3, long v4, long v5, long v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_ARX_SE(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_ARX_OB(unsigned long v1, unsigned long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11);
void L1TRC_Send_UL1D_TRC_ARX_MODE(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8, char v9);
void L1TRC_Send_UL1D_TRC_ARX_GAP_DBG(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_UL1D_TRC_ARX_DECIDE_COMMITTEE_ONOFF(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, char v5, char v6, char v7);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_DLDCH_OFF_SLOTFORMAT(short v1);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_DLDCH_CHEN(short v1, short v2, char v3, char v4);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_DLDCH_SLOTFORMAT_INPUT(short v1, short v2, unsigned short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_DLDCH_SLOTFORMAT(short v1, unsigned long v2, short v3);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_DLDCH_FRAMETICK(short v1, short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_DLDCH_START(short v1, short v2, short v3, short v4, unsigned short v5, short v6);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_DLDCH_STOP(void);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_FDPCH_CC_START(short v1, short v2, short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_RL0_OFF_SLOTFORMAT(short v1, short v2, short v3, short v4, unsigned short v5, short v6);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_RL0_CHEN(short v1, short v2, short v3, char v4, char v5);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_rl0_START_CPICH(short v1, short v2, short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_rl0_START_PHCH(short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_RXCRP_CHCFG_rl0_STOP(void);
void L1TRC_Send_UL1D_TRC_UL_DCH_INI_PWR(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_UL_DCH_HISR_PARAM_INFO(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_UL_DCH_HISR_INFO(unsigned char v1, short v2, unsigned char v3, unsigned char v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_UL_DCH_CONFIG_INFO(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_CER_TARGET(short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_SIR_TARGET(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_RMIS(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_RMIS_EST(unsigned char v1, short v2, short v3, long v4, long v5, long v6);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_ADJUST(unsigned char v1, long v2, long v3);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_RMIS_RATE(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_WIND_UP_DOWN(unsigned char v1, unsigned char v2, long v3);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_DBG3(unsigned char v1, long v2, long v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_DPC_RXSRP_SIG_AMP(unsigned char v1, short v2, unsigned char v3, unsigned char v4, short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_DPC_RXSRP_SVC_ID(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_Trc_DPC_CMD(unsigned short v1, short v2, unsigned short v3, short v4);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL1(unsigned char v1, long v2, char v3, char v4, char v5);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_TRCH_IND_MAP(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_RECONFIG_FLAG_TRCH(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_EVAL_LIST(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_USE_FLAG_TRCH(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_VERY_LOW_BLER_FLAG(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_BLOCK_TRCH_IND(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_ACTIVE_FLAG_TRCH(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1D_TRC_DPC_NUM_ERASED_BLK_ACQ(short v1);
void L1TRC_Send_UL1D_TRC_DPC_REF_TRCH_ELAPSED_FRAME_CNT(long v1, long v2, long v3);
void L1TRC_Send_UL1D_TRC_DPC_BLOCK_TRCH_TTI_CNT(char v1, short v2);
void L1TRC_Send_UL1D_TRC_DPC_DPCOUNTER_STARTED(unsigned char v1, char v2);
void L1TRC_Send_UL1D_TRC_DPC_BLER_EST(char v1, char v2, long v3, long v4, long v5, long v6, char v7);
void L1TRC_Send_UL1D_TRC_DPC_SIR_MEASURED_DB(unsigned char v1, long v2, long v3);
void L1TRC_Send_UL1D_TRC_DPC_TRK_BACK_TO_ACQ_CHECK(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DPC_SUSPEND_WIND_UP_CHECK(unsigned char v1, unsigned char v2, unsigned char v3, short v4);
void L1TRC_Send_UL1D_TRC_DPC_DPCCH_INTEREFENCE_DETECT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_NEW_MEAS_CFG(short v1, long v2, short v3);
void L1TRC_Send_UL1D_TRC_SET_MEAS_CALLBACK(unsigned short v1, unsigned char v2, short v3);
void L1TRC_Send_UL1D_TRC_GET_MEAS_CALLBACK(unsigned short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_CONFIG_CELL_LIST(unsigned short v1, short v2, short v3, short v4, short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_50MS_RESET(short v1);
void L1TRC_Send_UL1D_TRC_50MS_CELL_CONFIG(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_50MS_LIST_FULL(unsigned short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_50MS_CS4_INFO(unsigned short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_ENHANCED_CM_CELL(unsigned short v1, short v2, short v3, char v4);
void L1TRC_Send_UL1D_TRC_MEAS_TIMING_INFO(unsigned short v1, long v2, unsigned long v3, long v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_INTER_FREQ_CHANGE_DURING_BCH_SFN(unsigned short v1, char v2);
void L1TRC_Send_UL1D_TRC_TRCH_BLER(char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_TRCH_BLER_RESET(char v1);
void L1TRC_Send_UL1D_TRC_PICH_DISABLE(char v1);
void L1TRC_Send_UL1D_TRC_PCH_TFCI_ADJ(char v1);
void L1TRC_Send_UL1D_TRC_PI_REPEAT(short v1, short v2, char v3, short v4);
void L1TRC_Send_UL1D_TRC_DRX_CYCLE_CONFIG(short v1, short v2);
void L1TRC_Send_UL1D_TRC_NWSCAN_EVENT(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1D_TRC_NWSCAN_ADDNEWCELL(short v1, char v2, char v3, char v4);
void L1TRC_Send_UL1D_TRC_NWSCAN_FSCM_DONE(unsigned char v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_NWSCAN_MEASCELLFULL(short v1, char v2);
void L1TRC_Send_UL1D_TRC_DSP_SM_STATE_MACHINE(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_DSP_CHANNEL_POWER_ON(unsigned short v1, unsigned short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_DSP_SM_MML1_REC_RAT_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_DSP_SM_LOCK_SLEEP(unsigned long v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_DSP_SM_VALID_CNT_CONFIG(unsigned char v1, unsigned long v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_DSP_SM_MESSAGE(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_DSP_SM_WARN_MESSAGE(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_DSP_SM_WARN_BYPASS_BACKUP(unsigned char v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_DSP_SM_CONFIG_RAKE_T3_INIT(char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_DSP_SM_CONFIG_RAKE_LOADER_OFF(unsigned long v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_DSP_SM_RAKE_T3_INIT(short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_DSP_SM_C2M_IRQ(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_DSP_SM_M2C_IRQ(unsigned char v1, unsigned long v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_DSP_SM_ALLOW_SLEEP(unsigned char v1, char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned short v6);
void L1TRC_Send_UL1D_TRC_DSP_SM_INIT_READY(unsigned char v1, char v2, char v3, char v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_DSP_DVFS_EQ_EXIST(char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1D_TRC_DSP_DVFS_EVENT_EXPIRE(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned short v5, unsigned short v6, unsigned long v7, unsigned long v8, unsigned short v9);
void L1TRC_Send_UL1D_TRC_DSP_DVFS_EVENT_SET(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned short v5, unsigned short v6, unsigned long v7, unsigned long v8, unsigned short v9);
void L1TRC_Send_UL1D_TRC_DSP_DVFS_EVENT_CANCEL(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_DSP_DVFS_EVENT_IDLE_LOCKED(unsigned long v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_DSP_DVFS_DBG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_DSP_DVFS_COMPILE_OPTION(char v1, char v2);
void L1TRC_Send_UL1D_TRC_DSP_SRAM_PMDM_BITMAP_FEC(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_UL1D_TRC_DSP_SRAM_PMDM_BITMAP_RXBRP(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_UL1D_TRC_DSP_SRAM_SW_PWDN_STATUS_FEC(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_DSP_SRAM_SW_PWDN_STATUS_RXBRP(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_DSP_SRAM_PMDM_TYPE_FEC(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_DSP_SRAM_PMDM_TYPE_RXBRP(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_DSP_SRAM_CONFIG_PMDM_TYPE(unsigned short v1, unsigned long v2, unsigned char v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_DSP_SRAM_CONFIG_SW_PWDN(unsigned short v1, unsigned long v2, unsigned char v3, unsigned long v4, char v5);
void L1TRC_Send_UL1D_TRC_DSP_SRAM_CONFIG(unsigned short v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_DSP_SM_MDL_STATUS(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_UL1D_TRC_DSP_SM_MDL_STATUS_RAKE(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_UL1D_TRC_DSP_SM_MDL_STATUS_BRP(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_UL1D_TRC_SLEEP_MESSAGE(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_CHECK_L1_ALLOW_SLEEP(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_SLEEP_LOCK(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_UL1D_TRC_SLEEP_WAKEUP_ISR_EXE_TIME(long v1, long v2, long v3);
void L1TRC_Send_UL1D_TRC_SLEEP_EL1D_HRT_MARGIN_EVAL(unsigned short v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_SLEEP_DUMMY_SLOTTICK_WAKEUP(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DSP_PMDM_RELOADING_STATE_MACHINE(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_DSP_PMDM_RELOADING_POLLING_MML1(unsigned long v1, char v2, char v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_UBIN_PMDM_QUERY_RESULT(char v1, char v2, char v3, char v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_UBIN_TCM_POLLING_TDD_TIMER(char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_UBIN_MESSAGE(unsigned char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_UBIN_WARN_MESSAGE(unsigned char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_UBIN_DUPLEX_MODE_CHANGE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_UBIN_SET_RAT_MODE(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_GSR_CTRL_CON_DBG1(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_UL1D_TRC_GSR_CTRL_CON_DBG2(unsigned short v1);

void Set_UL1D_SIXTH_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_SIXTH()	(UL1D_SIXTH_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DLDCH_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DLDCH_L()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_ULDCH_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_ULDCH_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_ULDCH_L()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DPC_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DPC_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DPC_L()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_L()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_BLER_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_PICH_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_NWSCAN_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DC_EDCH_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_L()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_ARX_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_ARX_L()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[3]&0x20)!=0))
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_UPDATE_RXBRP_ID()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_L()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_DPCH_TYPE()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_RECONFIG()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_INFO()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_RXBRP_CALCULATE_PARAM()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_RXBRP_CONFIG()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_DMA_DONE_POST_RECONFIG()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_GET_RL_BUFFER()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_FREE_RL_BUFFER()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_GET_RXBRP_BUFFER()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_FREE_RXBRP_BUFFER()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_ADAPT_IOT_WORKAROUND()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_CM_METHOD()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_RECFG_EVENT()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_SET_RL_INFO()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DC_EDCH_FDPCH_RL_CFG()	ChkL1ClsFltr_UL1D_SIXTH_DC_EDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_DL_RL_NUM()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_SYNCH_INFO()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_ARX_EVAL_RSLT()	ChkL1ClsFltr_UL1D_SIXTH_ARX_H()
#define ChkL1MsgFltr_UL1D_TRC_ARX_HAND_IN_RSLT()	ChkL1ClsFltr_UL1D_SIXTH_ARX_H()
#define ChkL1MsgFltr_UL1D_TRC_ARX_ARBITRATE_RSLT()	ChkL1ClsFltr_UL1D_SIXTH_ARX_H()
#define ChkL1MsgFltr_UL1D_TRC_ARX_INJECT_CMD()	ChkL1ClsFltr_UL1D_SIXTH_ARX_H()
#define ChkL1MsgFltr_UL1D_TRC_ARX_SNR()	ChkL1ClsFltr_UL1D_SIXTH_ARX_H()
#define ChkL1MsgFltr_UL1D_TRC_ARX_SE()	ChkL1ClsFltr_UL1D_SIXTH_ARX_H()
#define ChkL1MsgFltr_UL1D_TRC_ARX_OB()	ChkL1ClsFltr_UL1D_SIXTH_ARX_H()
#define ChkL1MsgFltr_UL1D_TRC_ARX_MODE()	ChkL1ClsFltr_UL1D_SIXTH_ARX_H()
#define ChkL1MsgFltr_UL1D_TRC_ARX_GAP_DBG()	ChkL1ClsFltr_UL1D_SIXTH_ARX_H()
#define ChkL1MsgFltr_UL1D_TRC_ARX_DECIDE_COMMITTEE_ONOFF()	ChkL1ClsFltr_UL1D_SIXTH_ARX_H()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_DLDCH_OFF_SLOTFORMAT()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_DLDCH_CHEN()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_DLDCH_SLOTFORMAT_INPUT()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_DLDCH_SLOTFORMAT()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_DLDCH_FRAMETICK()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_DLDCH_START()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_DLDCH_STOP()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_FDPCH_CC_START()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_RL0_OFF_SLOTFORMAT()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_RL0_CHEN()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_rl0_START_CPICH()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_rl0_START_PHCH()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_RXCRP_CHCFG_rl0_STOP()	ChkL1ClsFltr_UL1D_SIXTH_RXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_INI_PWR()	ChkL1ClsFltr_UL1D_SIXTH_ULDCH_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_HISR_PARAM_INFO()	ChkL1ClsFltr_UL1D_SIXTH_ULDCH_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_HISR_INFO()	ChkL1ClsFltr_UL1D_SIXTH_ULDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_CONFIG_INFO()	ChkL1ClsFltr_UL1D_SIXTH_ULDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_CER_TARGET()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_SIR_TARGET()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_RMIS()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_RMIS_EST()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_ADJUST()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_RMIS_RATE()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_WIND_UP_DOWN()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_DBG3()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_RXSRP_SIG_AMP()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_RXSRP_SVC_ID()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_Trc_DPC_CMD()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL1()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_TRCH_IND_MAP()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_RECONFIG_FLAG_TRCH()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_EVAL_LIST()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_USE_FLAG_TRCH()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_VERY_LOW_BLER_FLAG()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_BLOCK_TRCH_IND()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_ACTIVE_FLAG_TRCH()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_NUM_ERASED_BLK_ACQ()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_REF_TRCH_ELAPSED_FRAME_CNT()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_BLOCK_TRCH_TTI_CNT()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DPCOUNTER_STARTED()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_BLER_EST()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_SIR_MEASURED_DB()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_TRK_BACK_TO_ACQ_CHECK()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_SUSPEND_WIND_UP_CHECK()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DPCCH_INTEREFENCE_DETECT()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_TRC_NEW_MEAS_CFG()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_SET_MEAS_CALLBACK()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_GET_MEAS_CALLBACK()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_CONFIG_CELL_LIST()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_50MS_RESET()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_50MS_CELL_CONFIG()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_50MS_LIST_FULL()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_50MS_CS4_INFO()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_ENHANCED_CM_CELL()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_TIMING_INFO()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_INTER_FREQ_CHANGE_DURING_BCH_SFN()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_TRCH_BLER()	ChkL1ClsFltr_UL1D_SIXTH_BLER_M()
#define ChkL1MsgFltr_UL1D_TRC_TRCH_BLER_RESET()	ChkL1ClsFltr_UL1D_SIXTH_BLER_M()
#define ChkL1MsgFltr_UL1D_TRC_PICH_DISABLE()	ChkL1ClsFltr_UL1D_SIXTH_PICH_M()
#define ChkL1MsgFltr_UL1D_TRC_PCH_TFCI_ADJ()	ChkL1ClsFltr_UL1D_SIXTH_PICH_M()
#define ChkL1MsgFltr_UL1D_TRC_PI_REPEAT()	ChkL1ClsFltr_UL1D_SIXTH_PICH_M()
#define ChkL1MsgFltr_UL1D_TRC_DRX_CYCLE_CONFIG()	ChkL1ClsFltr_UL1D_SIXTH_PICH_M()
#define ChkL1MsgFltr_UL1D_TRC_NWSCAN_EVENT()	ChkL1ClsFltr_UL1D_SIXTH_NWSCAN_M()
#define ChkL1MsgFltr_UL1D_TRC_NWSCAN_ADDNEWCELL()	ChkL1ClsFltr_UL1D_SIXTH_NWSCAN_M()
#define ChkL1MsgFltr_UL1D_TRC_NWSCAN_FSCM_DONE()	ChkL1ClsFltr_UL1D_SIXTH_NWSCAN_M()
#define ChkL1MsgFltr_UL1D_TRC_NWSCAN_MEASCELLFULL()	ChkL1ClsFltr_UL1D_SIXTH_NWSCAN_M()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_STATE_MACHINE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_CHANNEL_POWER_ON()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_MML1_REC_RAT_INFO()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_L()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_LOCK_SLEEP()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_VALID_CNT_CONFIG()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_MESSAGE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_WARN_MESSAGE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_M()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_WARN_BYPASS_BACKUP()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_M()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_CONFIG_RAKE_T3_INIT()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_CONFIG_RAKE_LOADER_OFF()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_RAKE_T3_INIT()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_C2M_IRQ()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_M2C_IRQ()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_ALLOW_SLEEP()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_INIT_READY()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_DVFS_EQ_EXIST()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_DVFS_EVENT_EXPIRE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_DVFS_EVENT_SET()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_DVFS_EVENT_CANCEL()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_DVFS_EVENT_IDLE_LOCKED()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_DVFS_DBG()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_L()
#define ChkL1MsgFltr_UL1D_TRC_DSP_DVFS_COMPILE_OPTION()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SRAM_PMDM_BITMAP_FEC()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SRAM_PMDM_BITMAP_RXBRP()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SRAM_SW_PWDN_STATUS_FEC()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SRAM_SW_PWDN_STATUS_RXBRP()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SRAM_PMDM_TYPE_FEC()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SRAM_PMDM_TYPE_RXBRP()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SRAM_CONFIG_PMDM_TYPE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SRAM_CONFIG_SW_PWDN()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SRAM_CONFIG()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_L()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_MDL_STATUS()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_L()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_MDL_STATUS_RAKE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_L()
#define ChkL1MsgFltr_UL1D_TRC_DSP_SM_MDL_STATUS_BRP()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_L()
#define ChkL1MsgFltr_UL1D_TRC_SLEEP_MESSAGE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_CHECK_L1_ALLOW_SLEEP()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_SLEEP_LOCK()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_SLEEP_WAKEUP_ISR_EXE_TIME()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_SLEEP_EL1D_HRT_MARGIN_EVAL()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_SLEEP_DUMMY_SLOTTICK_WAKEUP()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_PMDM_RELOADING_STATE_MACHINE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_DSP_PMDM_RELOADING_POLLING_MML1()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_UBIN_PMDM_QUERY_RESULT()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_UBIN_TCM_POLLING_TDD_TIMER()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_UBIN_MESSAGE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_UBIN_WARN_MESSAGE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_M()
#define ChkL1MsgFltr_UL1D_TRC_UBIN_DUPLEX_MODE_CHANGE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_UBIN_SET_RAT_MODE()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_GSR_CTRL_CON_DBG1()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()
#define ChkL1MsgFltr_UL1D_TRC_GSR_CTRL_CON_DBG2()	ChkL1ClsFltr_UL1D_SIXTH_Sleep_Mode_H()


#endif
