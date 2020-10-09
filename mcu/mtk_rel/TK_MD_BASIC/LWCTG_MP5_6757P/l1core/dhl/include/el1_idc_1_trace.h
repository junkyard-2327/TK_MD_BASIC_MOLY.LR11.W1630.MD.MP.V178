#ifndef L1TRC_EL1_IDC_1_DEF_H
#define L1TRC_EL1_IDC_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1_IDC_Str(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_TX_NTF(v1, v2) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0005, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_IDC_TX_NTF(v1, v2)
#endif
#define EL1_IDC_TX_NTF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0005, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_TDM_TIMER_EXPIRY(v1, v2, v3, v4) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0105, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_IDC_TDM_TIMER_EXPIRY(v1, v2, v3, v4)
#endif
#define EL1_IDC_TDM_TIMER_EXPIRY_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0105, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_TDM_REQ_HNDLR(v1, v2, v3, v4, v5) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0205, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1_IDC_TDM_REQ_HNDLR(v1, v2, v3, v4, v5)
#endif
#define EL1_IDC_TDM_REQ_HNDLR_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0205, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_WIFI_BT_RX_HNDLR(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0305, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_IDC_WIFI_BT_RX_HNDLR(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_IDC_WIFI_BT_RX_HNDLR_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0305, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_RESEND_HNDLR(v1, v2) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0405, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_IDC_RESEND_HNDLR(v1, v2)
#endif
#define EL1_IDC_RESEND_HNDLR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0405, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_CH_FRAME_CFG(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0505, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1_IDC_CH_FRAME_CFG(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_IDC_CH_FRAME_CFG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0505, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_CH_UPDT_FREQ(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0605, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1_IDC_CH_UPDT_FREQ(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_IDC_CH_UPDT_FREQ_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0605, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_SLP_DRX_NTF(v1, v2, v3, v4) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0705, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_IDC_SLP_DRX_NTF(v1, v2, v3, v4)
#endif
#define EL1_IDC_SLP_DRX_NTF_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0705, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_SLP_WAKEUP(v1, v2, v3) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0805, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_IDC_SLP_WAKEUP(v1, v2, v3)
#endif
#define EL1_IDC_SLP_WAKEUP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0805, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_SLP_WAKE_NTF(v1, v2, v3) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0905, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_IDC_SLP_WAKE_NTF(v1, v2, v3)
#endif
#define EL1_IDC_SLP_WAKE_NTF_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0905, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_PHS_RX_PROTECT(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0A05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_IDC_PHS_RX_PROTECT(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1_IDC_PHS_RX_PROTECT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0A05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_PHS_PRE_ABORT(v1) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B05, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1_IDC_PHS_PRE_ABORT(v1)
#endif
#define EL1_IDC_PHS_PRE_ABORT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B05, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_CH_HO_PROTECT(v1, v2, v3, v4, v5) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0C05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1_IDC_CH_HO_PROTECT(v1, v2, v3, v4, v5)
#endif
#define EL1_IDC_CH_HO_PROTECT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0C05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_CH_DRX_CHG(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0D05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1_IDC_CH_DRX_CHG(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_IDC_CH_DRX_CHG_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0D05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_CH_DRX_UPDT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0E05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1_IDC_CH_DRX_UPDT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_IDC_CH_DRX_UPDT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0E05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_IRT_LTE_ACTV_NTF(v1, v2, v3, v4) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_IDC_IRT_LTE_ACTV_NTF(v1, v2, v3, v4)
#endif
#define EL1_IDC_IRT_LTE_ACTV_NTF_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_PATTERN_SYNC(v1, v2, v3, v4) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1005, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_IDC_PATTERN_SYNC(v1, v2, v3, v4)
#endif
#define EL1_IDC_PATTERN_SYNC_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1005, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_CMD_START(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1105, (unsigned short)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1_IDC_CMD_START(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_IDC_CMD_START_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1105, (unsigned short)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_CMD_WRITE(v1) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1205, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1_IDC_CMD_WRITE(v1)
#endif
#define EL1_IDC_CMD_WRITE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1205, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_CMD_TYPE(v1, v2, v3, v4, v5) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1305, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1_IDC_CMD_TYPE(v1, v2, v3, v4, v5)
#endif
#define EL1_IDC_CMD_TYPE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1305, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_CMD_DELL(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1405, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1_IDC_CMD_DELL(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_IDC_CMD_DELL_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1405, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_CMD_WRITE2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x1505, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1_IDC_CMD_WRITE2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1_IDC_CMD_WRITE2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_7_DATA(TRC_MERGE_2S(0x1505, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_DENIAL_CHK(v1, v2, v3, v4, v5) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1605, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1_IDC_DENIAL_CHK(v1, v2, v3, v4, v5)
#endif
#define EL1_IDC_DENIAL_CHK_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1605, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_SCHDL_SET(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1705, (unsigned short)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1_IDC_SCHDL_SET(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_IDC_SCHDL_SET_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1705, (unsigned short)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_WIFI_BT_PARAM_HNDLR(v1, v2, v3, v4, v5) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1805, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define EL1_IDC_WIFI_BT_PARAM_HNDLR(v1, v2, v3, v4, v5)
#endif
#define EL1_IDC_WIFI_BT_PARAM_HNDLR_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1805, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_WIFI_BT_PARAM_HNDLR2(v1, v2, v3, v4) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1905, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_IDC_WIFI_BT_PARAM_HNDLR2(v1, v2, v3, v4)
#endif
#define EL1_IDC_WIFI_BT_PARAM_HNDLR2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1905, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_SCHDL_IDC_CMD_TRC(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1A05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1_SCHDL_IDC_CMD_TRC(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_SCHDL_IDC_CMD_TRC_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1A05, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_TX_FILTER_MODE(v1) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B05, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1_TX_FILTER_MODE(v1)
#endif
#define EL1_TX_FILTER_MODE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B05, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_WARNIG(v1) do {\
		if(EL1_IDC_1_Trace_Filter[0]==1 && (EL1_IDC_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C05, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1_IDC_WARNIG(v1)
#endif
#define EL1_IDC_WARNIG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C05, (unsigned short)(v1)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_IDC_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1_IDC_TX_NTF(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1_IDC_TDM_TIMER_EXPIRY(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1_IDC_TDM_REQ_HNDLR(unsigned short v1, unsigned short v2, unsigned short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1_IDC_WIFI_BT_RX_HNDLR(unsigned short v1, unsigned long v2, unsigned long v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_EL1_IDC_RESEND_HNDLR(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1_IDC_CH_FRAME_CFG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1_IDC_CH_UPDT_FREQ(unsigned short v1, unsigned long v2, unsigned long v3, unsigned short v4, unsigned short v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1_IDC_SLP_DRX_NTF(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1_IDC_SLP_WAKEUP(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1_IDC_SLP_WAKE_NTF(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1_IDC_PHS_RX_PROTECT(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8);
void L1TRC_Send_EL1_IDC_PHS_PRE_ABORT(unsigned short v1);
void L1TRC_Send_EL1_IDC_CH_HO_PROTECT(unsigned short v1, unsigned short v2, unsigned short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1_IDC_CH_DRX_CHG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1_IDC_CH_DRX_UPDT(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1_IDC_IRT_LTE_ACTV_NTF(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1_IDC_PATTERN_SYNC(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1_IDC_CMD_START(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned short v6);
void L1TRC_Send_EL1_IDC_CMD_WRITE(unsigned short v1);
void L1TRC_Send_EL1_IDC_CMD_TYPE(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1_IDC_CMD_DELL(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1_IDC_CMD_WRITE2(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1_IDC_DENIAL_CHK(unsigned long v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_IDC_SCHDL_SET(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned short v6);
void L1TRC_Send_EL1_IDC_WIFI_BT_PARAM_HNDLR(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_IDC_WIFI_BT_PARAM_HNDLR2(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1_SCHDL_IDC_CMD_TRC(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1_TX_FILTER_MODE(unsigned short v1);
void L1TRC_Send_EL1_IDC_WARNIG(unsigned short v1);

void Set_EL1_IDC_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_IDC_1()	(EL1_IDC_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()	(ChkL1ModFltr_EL1_IDC_1()&&((EL1_IDC_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_EL1_IDC_TX_NTF()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_TDM_TIMER_EXPIRY()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_TDM_REQ_HNDLR()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_WIFI_BT_RX_HNDLR()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_RESEND_HNDLR()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_CH_FRAME_CFG()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_CH_UPDT_FREQ()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_SLP_DRX_NTF()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_SLP_WAKEUP()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_SLP_WAKE_NTF()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_PHS_RX_PROTECT()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_PHS_PRE_ABORT()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_CH_HO_PROTECT()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_CH_DRX_CHG()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_CH_DRX_UPDT()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_IRT_LTE_ACTV_NTF()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_PATTERN_SYNC()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_CMD_START()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_CMD_WRITE()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_CMD_TYPE()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_CMD_DELL()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_CMD_WRITE2()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_DENIAL_CHK()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_SCHDL_SET()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_WIFI_BT_PARAM_HNDLR()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_WIFI_BT_PARAM_HNDLR2()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_SCHDL_IDC_CMD_TRC()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_TX_FILTER_MODE()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_IDC_WARNIG()	ChkL1ClsFltr_EL1_IDC_1_el1_idc_var_trace()


#endif
