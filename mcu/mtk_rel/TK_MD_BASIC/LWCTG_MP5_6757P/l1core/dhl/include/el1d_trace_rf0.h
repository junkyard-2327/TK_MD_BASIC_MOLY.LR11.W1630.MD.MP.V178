#ifndef L1TRC_EL1D_RF0_DEF_H
#define L1TRC_EL1D_RF0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_RF_FLAG(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_RF_CBW(v1)  (unsigned char)(v1+2)
#define EL1D_TRC_STR_RF_MODE(v1)  (unsigned char)(v1+8)
#define EL1D_TRC_STR_RF_CPTYPE(v1)  (unsigned char)(v1+10)
#define EL1D_TRC_STR_RF_REQ(v1)  (unsigned char)(v1+12)
#define EL1D_TRC_STR_RF_RTX(v1)  (unsigned char)(v1+24)
#define EL1D_TRC_STR_RF_CC(v1)  (unsigned char)(v1+26)
#define EL1D_TRC_STR_RF_SRX(v1)  (unsigned char)(v1+28)
#define EL1D_TRC_STR_RF_CALLBACK(v1)  (unsigned char)(v1+30)
#define EL1D_TRC_STR_RF_HANDLER(v1)  (unsigned char)(v1+42)
#define EL1D_TRC_STR_RF_RX_LPM_TYPE(v1)  (unsigned char)(v1+46)
#define EL1D_TRC_STR_RF_CONTEXT_ENTRY(v1)  (unsigned char)(v1+55)
#define EL1D_TRC_STR_RF_WIN_EXIST(v1)  (unsigned char)(v1+68)
#define EL1D_TRC_STR_RF_MIPI_STATE(v1)  (unsigned char)(v1+76)
#define EL1D_TRC_STR_RF_BPI_BSI(v1)  (unsigned char)(v1+80)
#define EL1D_TRC_STR_RF_FUNCTION_ENABLE(v1)  (unsigned char)(v1+84)
#define EL1D_FIX_AFC_SYNTH_CALC_CALLER(v1)  (unsigned char)(v1+92)
#define EL1D_TRC_SINGLE_ANT_STATE(v1)  (unsigned char)(v1+97)
#define EL1D_TRC_STR_RF_TX_HRM_MODE(v1)  (unsigned char)(v1+100)
#define EL1D_TRC_STR_RF_LPM_PATH_ENABLE(v1)  (unsigned char)(v1+103)
#define EL1D_TRC_STR_RF_TX_BYPASS_MODE(v1)  (unsigned char)(v1+107)
#define EL1D_TRC_STR_RF_TAS_CALL_FROM(v1)  (unsigned char)(v1+109)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_CONTEXT_ENTRY(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0037, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CONTEXT_ENTRY(v1)
#endif
#define EL1D_TRC_RF_CONTEXT_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0037, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_CONTEXT_QUIT(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0137, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CONTEXT_QUIT(v1)
#endif
#define EL1D_TRC_RF_CONTEXT_QUIT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0137, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_CTRL_SCH_CALLBACK(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0237, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_SCH_CALLBACK(v1, v2)
#endif
#define EL1D_TRC_RF_CTRL_SCH_CALLBACK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0237, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_SCH_CALLBACK_END(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0337, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_SCH_CALLBACK_END(v1)
#endif
#define EL1D_TRC_RF_CTRL_SCH_CALLBACK_END_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0337, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_SFTICK(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0437, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_SFTICK(v1)
#endif
#define EL1D_TRC_RF_CTRL_SFTICK_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0437, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_CTRL_SET_REQ(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0537, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (char)(v6), (char)(v7)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_SET_REQ(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RF_CTRL_SET_REQ_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0537, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (char)(v6), (char)(v7)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_CTRL_SET_RF_REQ(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0637, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_SET_RF_REQ(v1, v2)
#endif
#define EL1D_TRC_RF_CTRL_SET_RF_REQ_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0637, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_TX_REQ_CANCEL(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0737, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_TX_REQ_CANCEL(v1)
#endif
#define EL1D_TRC_RF_CTRL_TX_REQ_CANCEL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0737, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_TX_EVT_CANCEL_PROC(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0837, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_TX_EVT_CANCEL_PROC(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_CTRL_TX_EVT_CANCEL_PROC_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0837, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_TX_EVT_CANCEL_FAIL() do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0937, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_TX_EVT_CANCEL_FAIL()
#endif
#define EL1D_TRC_RF_CTRL_TX_EVT_CANCEL_FAIL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0937, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_VCO_SEL(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A37, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_VCO_SEL(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RF_CTRL_VCO_SEL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A37, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_SRX_CCIDX(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B37, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_SRX_CCIDX(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_CTRL_SRX_CCIDX_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B37, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RX_LPM_INFO(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C37, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RX_LPM_INFO(v1)
#endif
#define EL1D_TRC_RF_CTRL_RX_LPM_INFO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C37, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_CC_CFG(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D37, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_CC_CFG(v1, v2)
#endif
#define EL1D_TRC_RF_CTRL_CC_CFG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D37, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_CTRL_CC_LIST(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0E37, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v5), (char)(v6), (char)(v7)), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_CC_LIST(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RF_CTRL_CC_LIST_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0E37, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v5), (char)(v6), (char)(v7)), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_CTRL_RX_PARAM(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0F37, (unsigned char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RX_PARAM(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_CTRL_RX_PARAM_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0F37, (unsigned char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_CTRL_TX_PARAM(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1037, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_TX_PARAM(v1)
#endif
#define EL1D_TRC_RF_CTRL_TX_PARAM_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1037, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_WIN_EXIST(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1137, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_WIN_EXIST(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_CTRL_WIN_EXIST_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1137, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_WIN_EXIST_RTX(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1237, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_WIN_EXIST_RTX(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RF_CTRL_WIN_EXIST_RTX_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1237, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_EVT_CAN_CTRL_QUEUE(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1337, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_EVT_CAN_CTRL_QUEUE(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RF_CTRL_EVT_CAN_CTRL_QUEUE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1337, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_TX_CHECK_RXCA_PCC_CFG(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1437, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_TX_CHECK_RXCA_PCC_CFG(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RF_CTRL_TX_CHECK_RXCA_PCC_CFG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1437, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_TX_CHECK_RXCA_SCC_CFG(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1537, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_TX_CHECK_RXCA_SCC_CFG(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RF_CTRL_TX_CHECK_RXCA_SCC_CFG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1537, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_SW_SECVERSION(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1637, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_SW_SECVERSION(v1)
#endif
#define EL1D_TRC_RF_CTRL_SW_SECVERSION_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1637, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_CTRL_FLAG_STATUS(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1737, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_FLAG_STATUS(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_CTRL_FLAG_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1737, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RXDFE_FC(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1837, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RXDFE_FC(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_CTRL_RXDFE_FC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1837, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RXDFE_FC_PATH(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1937, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v1), (char)(v7)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RXDFE_FC_PATH(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RF_CTRL_RXDFE_FC_PATH_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1937, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v1), (char)(v7)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RXDFE_FC_NCO_PATH(v1, v2, v3) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A37, (unsigned char)(v1), (char)(v3)), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RXDFE_FC_NCO_PATH(v1, v2, v3)
#endif
#define EL1D_TRC_RF_CTRL_RXDFE_FC_NCO_PATH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A37, (unsigned char)(v1), (char)(v3)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RXDFE_WIN(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B37, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RXDFE_WIN(v1, v2)
#endif
#define EL1D_TRC_RF_CTRL_RXDFE_WIN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B37, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RXDFE_WIN_PATH(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1C37, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), (unsigned char)(v7), TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v4), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RXDFE_WIN_PATH(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RF_CTRL_RXDFE_WIN_PATH_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1C37, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v5), (unsigned char)(v7), TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v4), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RXDFE_WIN_EVT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D37, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RXDFE_WIN_EVT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RF_CTRL_RXDFE_WIN_EVT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D37, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RXDFE_REQ_BMP_PRE(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E37, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RXDFE_REQ_BMP_PRE(v1)
#endif
#define EL1D_TRC_RF_CTRL_RXDFE_REQ_BMP_PRE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E37, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RXDFE_NBI_STA(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F37, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RXDFE_NBI_STA(v1, v2)
#endif
#define EL1D_TRC_RF_CTRL_RXDFE_NBI_STA_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F37, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RXDFE_REQ_BMP_AFT(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2037, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RXDFE_REQ_BMP_AFT(v1)
#endif
#define EL1D_TRC_RF_CTRL_RXDFE_REQ_BMP_AFT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2037, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RXDFE_CC_EN_MASK(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2137, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RXDFE_CC_EN_MASK(v1)
#endif
#define EL1D_TRC_RF_CTRL_RXDFE_CC_EN_MASK_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2137, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_CHK_CCREC_INT_TIME(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2237, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_CHK_CCREC_INT_TIME(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RF_CTRL_CHK_CCREC_INT_TIME_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2237, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_CA_INT_BYPASS_MODE(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2337, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_CA_INT_BYPASS_MODE(v1)
#endif
#define EL1D_TRC_RF_CTRL_CA_INT_BYPASS_MODE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2337, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_TEMPER_CALC_BY_DAC(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2437, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_TEMPER_CALC_BY_DAC(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_CTRL_TEMPER_CALC_BY_DAC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2437, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_TEMPER_CURR_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2537, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_TEMPER_CURR_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RF_CTRL_TEMPER_CURR_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2537, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_FUNCTION_ENABLE(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2637, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_FUNCTION_ENABLE(v1, v2)
#endif
#define EL1D_TRC_RF_CTRL_FUNCTION_ENABLE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2637, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_HW_EVT_CHECK(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2737, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_HW_EVT_CHECK(v1)
#endif
#define EL1D_TRC_RF_CTRL_HW_EVT_CHECK_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2737, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RX_FIXED_RF_GAIN(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2837, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RX_FIXED_RF_GAIN(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_CTRL_RX_FIXED_RF_GAIN_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2837, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RX_FIXED_RF_DC(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2937, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RX_FIXED_RF_DC(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_CTRL_RX_FIXED_RF_DC_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2937, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_TX_INIT_GAIN(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2A37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_TX_INIT_GAIN(v1, v2)
#endif
#define EL1D_TRC_RF_CTRL_TX_INIT_GAIN_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2A37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_AFC_DAC_UPDATE(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2B37, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_AFC_DAC_UPDATE(v1)
#endif
#define EL1D_TRC_RF_CTRL_AFC_DAC_UPDATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2B37, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_CAPID_UPDATE(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2C37, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_CAPID_UPDATE(v1)
#endif
#define EL1D_TRC_RF_CTRL_CAPID_UPDATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2C37, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_QUEUE_PROC_CHK0(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2D37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RF_QUEUE_PROC_CHK0(v1)
#endif
#define EL1D_TRC_RF_QUEUE_PROC_CHK0_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2D37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_QUEUE_PROC_CHK1(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2E37, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RF_QUEUE_PROC_CHK1(v1, v2)
#endif
#define EL1D_TRC_RF_QUEUE_PROC_CHK1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2E37, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_QUEUE_PROC_PRE(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F37, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RF_QUEUE_PROC_PRE(v1, v2)
#endif
#define EL1D_TRC_RF_QUEUE_PROC_PRE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F37, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_QUEUE_PROC_POST(v1, v2, v3) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3037, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RF_QUEUE_PROC_POST(v1, v2, v3)
#endif
#define EL1D_TRC_RF_QUEUE_PROC_POST_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3037, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_QUEUE_INVALID_ADV(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3137, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RF_QUEUE_INVALID_ADV(v1, v2)
#endif
#define EL1D_TRC_RF_QUEUE_INVALID_ADV_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3137, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_TOOL_LIST_QUEUE(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3237, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RF_TOOL_LIST_QUEUE(v1, v2)
#endif
#define EL1D_TRC_RF_TOOL_LIST_QUEUE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3237, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_FIX_AFC_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x3337, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_FIX_AFC_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_FIX_AFC_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x3337, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_FIX_AFC_GET_COMP_FE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x3437, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_FIX_AFC_GET_COMP_FE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_FIX_AFC_GET_COMP_FE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x3437, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_FIX_AFC_GET_INFO(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x3537, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_FIX_AFC_GET_INFO(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_FIX_AFC_GET_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x3537, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_FIX_AFC_SET_BSI(v1, v2, v3) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3637, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_FIX_AFC_SET_BSI(v1, v2, v3)
#endif
#define EL1D_FIX_AFC_SET_BSI_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3637, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_FIX_AFC_SYNTH_CALC(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3737, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_FIX_AFC_SYNTH_CALC(v1, v2, v3, v4, v5)
#endif
#define EL1D_FIX_AFC_SYNTH_CALC_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3737, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_FIX_AFC_TX_PARSE(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3837, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_FIX_AFC_TX_PARSE(v1, v2)
#endif
#define EL1D_FIX_AFC_TX_PARSE_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3837, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_FIX_AFC_OTF_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x3937, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_FIX_AFC_OTF_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_FIX_AFC_OTF_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x3937, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_FIX_AFC_OTF_RX(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x3A37, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_FIX_AFC_OTF_RX(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_FIX_AFC_OTF_RX_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x3A37, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_FIX_AFC_OTF_TX(v1, v2, v3, v4, v5) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3B37, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_FIX_AFC_OTF_TX(v1, v2, v3, v4, v5)
#endif
#define EL1D_FIX_AFC_OTF_TX_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3B37, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_NCO_UPDATE_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x3C37, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_NCO_UPDATE_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_NCO_UPDATE_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x3C37, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_NCO_UPDATE_CALLBACK(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3D37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_NCO_UPDATE_CALLBACK(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_NCO_UPDATE_CALLBACK_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3D37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_NCO_UPDATE_HANDLER(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3E37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_NCO_UPDATE_HANDLER(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_NCO_UPDATE_HANDLER_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3E37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_NCO_UPDATE_STATUS(v1, v2, v3) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3F37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_NCO_UPDATE_STATUS(v1, v2, v3)
#endif
#define EL1D_NCO_UPDATE_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3F37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_TAS_BPI(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4037, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RF_TAS_BPI(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_TAS_BPI_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4037, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_TAS_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x4137, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RF_TAS_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RF_TAS_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x4137, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DAT_INFO(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4237, (short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RF_DAT_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_DAT_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4237, (short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DAT_BPI(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4337, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RF_DAT_BPI(v1, v2)
#endif
#define EL1D_TRC_RF_DAT_BPI_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4337, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DAT_MIPI(v1, v2, v3, v4) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4437, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RF_DAT_MIPI(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RF_DAT_MIPI_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4437, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DAT_DBG(v1, v2, v3) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4537, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RF_DAT_DBG(v1, v2, v3)
#endif
#define EL1D_TRC_RF_DAT_DBG_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4537, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_RX_LPM_DEBUG(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x4637, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_RX_LPM_DEBUG(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RF_CTRL_RX_LPM_DEBUG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x4637, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_SINGLE_ANT_INFO(v1, v2, v3) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4737, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_SINGLE_ANT_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_SINGLE_ANT_INFO_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4737, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_HRM_SUPPORT_INDICATOR(v1, v2, v3) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4837, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TX_HRM_SUPPORT_INDICATOR(v1, v2, v3)
#endif
#define EL1D_TRC_TX_HRM_SUPPORT_INDICATOR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4837, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_HRM_SUPPORT(v1, v2, v3) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4937, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_HRM_SUPPORT(v1, v2, v3)
#endif
#define EL1D_TRC_TX_HRM_SUPPORT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4937, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CTRL_TX_HRM_STATE_CHECK(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A37, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RF_CTRL_TX_HRM_STATE_CHECK(v1, v2)
#endif
#define EL1D_TRC_RF_CTRL_TX_HRM_STATE_CHECK_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A37, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_CAL_RX_IRR_COMP_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4B37, (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RF_CAL_RX_IRR_COMP_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RF_CAL_RX_IRR_COMP_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4B37, (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_DB_BAND_2_IND(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4C37, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)));\
	} while(0)
#else
	#define EL1D_TRC_RF_DB_BAND_2_IND(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RF_DB_BAND_2_IND_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4C37, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_DB_BAND_SUPPORT_MASK(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4D37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RF_DB_BAND_SUPPORT_MASK(v1, v2)
#endif
#define EL1D_TRC_RF_DB_BAND_SUPPORT_MASK_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4D37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXLIF_NCO_INFO(v1, v2, v3) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4E37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RXLIF_NCO_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_RXLIF_NCO_INFO_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4E37, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_TX_BYPASS_PATH(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F37, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RF_TX_BYPASS_PATH(v1, v2)
#endif
#define EL1D_TRC_RF_TX_BYPASS_PATH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F37, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_AMPR_SPECIAL_HANDLE_BITMAP(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5037, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RF_AMPR_SPECIAL_HANDLE_BITMAP(v1)
#endif
#define EL1D_TRC_RF_AMPR_SPECIAL_HANDLE_BITMAP_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5037, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_ELNA_INFO(v1, v2) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5137, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_ELNA_INFO(v1, v2)
#endif
#define EL1D_TRC_RF_ELNA_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5137, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RF_ELNA_NCCA_INFO(v1) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5237, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RF_ELNA_NCCA_INFO(v1)
#endif
#define EL1D_TRC_RF_ELNA_NCCA_INFO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5237, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_TPO_STATUS(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5337, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_TPO_STATUS(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RF_TPO_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5337, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RF_TPO_STATUS_POUT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RF0_Trace_Filter[0]==1 && (EL1D_RF0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5437, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RF_TPO_STATUS_POUT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RF_TPO_STATUS_POUT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5437, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_RF0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_RF_CONTEXT_ENTRY(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RF_CONTEXT_QUIT(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_SCH_CALLBACK(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RF_CTRL_SCH_CALLBACK_END(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_SFTICK(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_SET_REQ(unsigned char v1, unsigned char v2, unsigned long v3, unsigned char v4, unsigned char v5, char v6, char v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RF_CTRL_SET_RF_REQ(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RF_CTRL_TX_REQ_CANCEL(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_TX_EVT_CANCEL_PROC(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RF_CTRL_TX_EVT_CANCEL_FAIL(void);
void L1TRC_Send_EL1D_TRC_RF_CTRL_VCO_SEL(unsigned char v1, unsigned char v2, unsigned short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RF_CTRL_SRX_CCIDX(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RX_LPM_INFO(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_CC_CFG(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RF_CTRL_CC_LIST(unsigned char v1, unsigned char v2, char v3, unsigned long v4, char v5, char v6, char v7);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RX_PARAM(unsigned long v1, unsigned long v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RF_CTRL_TX_PARAM(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_WIN_EXIST(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RF_CTRL_WIN_EXIST_RTX(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RF_CTRL_EVT_CAN_CTRL_QUEUE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RF_CTRL_TX_CHECK_RXCA_PCC_CFG(unsigned char v1, unsigned char v2, char v3, char v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RF_CTRL_TX_CHECK_RXCA_SCC_CFG(unsigned char v1, unsigned char v2, char v3, char v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RF_CTRL_SW_SECVERSION(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_FLAG_STATUS(short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RXDFE_FC(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RXDFE_FC_PATH(unsigned char v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, char v7);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RXDFE_FC_NCO_PATH(unsigned char v1, long v2, char v3);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RXDFE_WIN(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RXDFE_WIN_PATH(unsigned char v1, unsigned long v2, unsigned short v3, long v4, unsigned char v5, long v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RXDFE_WIN_EVT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RXDFE_REQ_BMP_PRE(short v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RXDFE_NBI_STA(short v1, short v2);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RXDFE_REQ_BMP_AFT(short v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RXDFE_CC_EN_MASK(short v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_CHK_CCREC_INT_TIME(unsigned char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_RF_CTRL_CA_INT_BYPASS_MODE(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_TEMPER_CALC_BY_DAC(unsigned short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_RF_CTRL_TEMPER_CURR_INFO(unsigned short v1, short v2, short v3, short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_EL1D_TRC_RF_CTRL_FUNCTION_ENABLE(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RF_CTRL_HW_EVT_CHECK(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RX_FIXED_RF_GAIN(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RX_FIXED_RF_DC(char v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RF_CTRL_TX_INIT_GAIN(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RF_CTRL_AFC_DAC_UPDATE(unsigned short v1);
void L1TRC_Send_EL1D_TRC_RF_CTRL_CAPID_UPDATE(unsigned short v1);
void L1TRC_Send_EL1D_TRC_RF_QUEUE_PROC_CHK0(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RF_QUEUE_PROC_CHK1(unsigned long v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RF_QUEUE_PROC_PRE(unsigned long v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RF_QUEUE_PROC_POST(unsigned long v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RF_QUEUE_INVALID_ADV(unsigned long v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RF_TOOL_LIST_QUEUE(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_FIX_AFC_DBG(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_FIX_AFC_GET_COMP_FE(long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1D_FIX_AFC_GET_INFO(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_FIX_AFC_SET_BSI(long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_FIX_AFC_SYNTH_CALC(unsigned char v1, long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_FIX_AFC_TX_PARSE(long v1, unsigned long v2);
void L1TRC_Send_EL1D_FIX_AFC_OTF_DBG(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_FIX_AFC_OTF_RX(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_FIX_AFC_OTF_TX(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, long v5);
void L1TRC_Send_EL1D_NCO_UPDATE_DBG(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_NCO_UPDATE_CALLBACK(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_NCO_UPDATE_HANDLER(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_NCO_UPDATE_STATUS(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RF_TAS_BPI(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RF_TAS_INFO(unsigned long v1, unsigned long v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RF_DAT_INFO(unsigned long v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RF_DAT_BPI(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RF_DAT_MIPI(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RF_DAT_DBG(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RF_CTRL_RX_LPM_DEBUG(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_SINGLE_ANT_INFO(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TX_HRM_SUPPORT_INDICATOR(unsigned char v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TX_HRM_SUPPORT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RF_CTRL_TX_HRM_STATE_CHECK(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RF_CAL_RX_IRR_COMP_INFO(long v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_RF_DB_BAND_2_IND(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_EL1D_TRC_RF_DB_BAND_SUPPORT_MASK(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RXLIF_NCO_INFO(long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_RF_TX_BYPASS_PATH(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RF_AMPR_SPECIAL_HANDLE_BITMAP(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RF_ELNA_INFO(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_RF_ELNA_NCCA_INFO(unsigned short v1);
void L1TRC_Send_EL1D_TRC_RF_TPO_STATUS(unsigned short v1, unsigned short v2, short v3, unsigned short v4, short v5, short v6);
void L1TRC_Send_EL1D_TRC_RF_TPO_STATUS_POUT(unsigned short v1, unsigned short v2, short v3, unsigned short v4, short v5, short v6);

void Set_EL1D_RF0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_RF0()	(EL1D_RF0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()	(ChkL1ModFltr_EL1D_RF0()&&((EL1D_RF0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_M()	(ChkL1ModFltr_EL1D_RF0()&&((EL1D_RF0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()	(ChkL1ModFltr_EL1D_RF0()&&((EL1D_RF0_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_RF_CONTEXT_ENTRY()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_CONTEXT_QUIT()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_SCH_CALLBACK()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_SCH_CALLBACK_END()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_SFTICK()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_SET_REQ()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_SET_RF_REQ()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_TX_REQ_CANCEL()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_TX_EVT_CANCEL_PROC()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_TX_EVT_CANCEL_FAIL()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_VCO_SEL()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_SRX_CCIDX()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RX_LPM_INFO()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_CC_CFG()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_CC_LIST()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RX_PARAM()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_TX_PARAM()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_WIN_EXIST()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_WIN_EXIST_RTX()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_EVT_CAN_CTRL_QUEUE()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_TX_CHECK_RXCA_PCC_CFG()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_TX_CHECK_RXCA_SCC_CFG()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_SW_SECVERSION()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_FLAG_STATUS()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RXDFE_FC()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RXDFE_FC_PATH()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RXDFE_FC_NCO_PATH()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RXDFE_WIN()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RXDFE_WIN_PATH()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RXDFE_WIN_EVT()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RXDFE_REQ_BMP_PRE()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RXDFE_NBI_STA()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RXDFE_REQ_BMP_AFT()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RXDFE_CC_EN_MASK()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_CHK_CCREC_INT_TIME()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_CA_INT_BYPASS_MODE()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_TEMPER_CALC_BY_DAC()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_TEMPER_CURR_INFO()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_FUNCTION_ENABLE()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_HW_EVT_CHECK()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RX_FIXED_RF_GAIN()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RX_FIXED_RF_DC()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_TX_INIT_GAIN()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_AFC_DAC_UPDATE()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_CAPID_UPDATE()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_QUEUE_PROC_CHK0()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_QUEUE_PROC_CHK1()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_QUEUE_PROC_PRE()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_QUEUE_PROC_POST()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_QUEUE_INVALID_ADV()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_TOOL_LIST_QUEUE()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_FIX_AFC_DBG()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_FIX_AFC_GET_COMP_FE()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_FIX_AFC_GET_INFO()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_M()
#define ChkL1MsgFltr_EL1D_FIX_AFC_SET_BSI()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_FIX_AFC_SYNTH_CALC()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_FIX_AFC_TX_PARSE()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_FIX_AFC_OTF_DBG()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_FIX_AFC_OTF_RX()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_FIX_AFC_OTF_TX()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_NCO_UPDATE_DBG()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_NCO_UPDATE_CALLBACK()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_NCO_UPDATE_HANDLER()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_NCO_UPDATE_STATUS()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_TAS_BPI()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_TAS_INFO()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DAT_INFO()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DAT_BPI()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DAT_MIPI()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_DAT_DBG()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_RX_LPM_DEBUG()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_SINGLE_ANT_INFO()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_HRM_SUPPORT_INDICATOR()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_HRM_SUPPORT()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CTRL_TX_HRM_STATE_CHECK()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_CAL_RX_IRR_COMP_INFO()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_DB_BAND_2_IND()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_DB_BAND_SUPPORT_MASK()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RXLIF_NCO_INFO()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_TX_BYPASS_PATH()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_AMPR_SPECIAL_HANDLE_BITMAP()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_ELNA_INFO()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_ELNA_NCCA_INFO()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RF_TPO_STATUS()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RF_TPO_STATUS_POUT()	ChkL1ClsFltr_EL1D_RF0_EL1D_TRC_CLS_RF_L()


#endif
