#ifndef L1TRC_EL1_PHS_2_DEF_H
#define L1TRC_EL1_PHS_2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define PHS_Msg_String(v1)  (unsigned char)(v1+0)
#define PHS_Main_St_String(v1)  (unsigned char)(v1+68)
#define PHS_Main_Evt_String(v1)  (unsigned char)(v1+104)
#define PHS_Schdl_St_String(v1)  (unsigned char)(v1+123)
#define PHS_Sub_Chg_Type_String(v1)  (unsigned char)(v1+129)
#define PHS_Scell_Chg_Type_String(v1)  (unsigned char)(v1+144)
#define PHS_CH_Req_Type_String(v1)  (unsigned char)(v1+150)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_HNDLR_ENTRY(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0002, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_HNDLR_ENTRY(v1)
#endif
#define PHS_LOG_HNDLR_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0002, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_HNDLR_ENTRY_L(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0102, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_HNDLR_ENTRY_L(v1)
#endif
#define PHS_LOG_HNDLR_ENTRY_L_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0102, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_SCH_RNTI_CTRL(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0202, (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v8)));\
	} while(0)
#else
	#define PHS_LOG_RCV_SCH_RNTI_CTRL(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PHS_LOG_RCV_SCH_RNTI_CTRL_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0202, (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v8)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CH_CHNG_ST(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0302, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_CH_CHNG_ST(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_CH_CHNG_ST_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0302, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SUB_CHNG(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0402, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_SUB_CHNG(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PHS_LOG_SUB_CHNG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0402, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_NXT_CH_CHNG(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0502, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_SRCH_NXT_CH_CHNG(v1, v2, v3)
#endif
#define PHS_LOG_SRCH_NXT_CH_CHNG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0502, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCELL_CHNG(v1, v2) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0602, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_SCELL_CHNG(v1, v2)
#endif
#define PHS_LOG_SCELL_CHNG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0602, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_CH_CTRL(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0702, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_CH_CTRL(v1)
#endif
#define PHS_LOG_RCV_CH_CTRL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0702, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CH_NBR_MIB_GET(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0802, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_CH_NBR_MIB_GET(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_CH_NBR_MIB_GET_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0802, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CH_NBR_SI_GET(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0902, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_CH_NBR_SI_GET(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_CH_NBR_SI_GET_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0902, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RCV_POS_CTRL(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RCV_POS_CTRL(v1, v2, v3)
#endif
#define PHS_LOG_RCV_POS_CTRL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_POS_SYNC_GET(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0B02, (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_POS_SYNC_GET(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_POS_SYNC_GET_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0B02, (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_POS_MEAS_GET(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0C02, (unsigned char)(v2), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_POS_MEAS_GET(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_POS_MEAS_GET_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0C02, (unsigned char)(v2), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_POS_CTRL_STUS(v1, v2, v3, v4) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_POS_CTRL_STUS(v1, v2, v3, v4)
#endif
#define PHS_LOG_POS_CTRL_STUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_SPECIAL_MB_MIB(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0E02, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_GET_SPECIAL_MB_MIB(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PHS_LOG_GET_SPECIAL_MB_MIB_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0E02, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXE_EVT_INDX_RANGE(v1, v2, v3, v4) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_EXE_EVT_INDX_RANGE(v1, v2, v3, v4)
#endif
#define PHS_LOG_EXE_EVT_INDX_RANGE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NXT_STBY_GAP_TIME(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1002, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_NXT_STBY_GAP_TIME(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_NXT_STBY_GAP_TIME_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1002, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_TAS_TIMER(v1, v2, v3, v4) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1102, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_TAS_TIMER(v1, v2, v3, v4)
#endif
#define PHS_LOG_TAS_TIMER_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1102, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_LOIF_TIMER(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1202, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_LOIF_TIMER(v1)
#endif
#define PHS_LOG_LOIF_TIMER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1202, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_ARX_TIMER(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1302, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_ARX_TIMER(v1)
#endif
#define PHS_LOG_ARX_TIMER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1302, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_HRT_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x1402, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define PHS_LOG_HRT_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define PHS_LOG_HRT_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x1402, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_HRT_TIME_FAIL(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1502, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_HRT_TIME_FAIL(v1)
#endif
#define PHS_LOG_HRT_TIME_FAIL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1502, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NBR_TR32K(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1602, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_GET_NBR_TR32K(v1, v2, v3)
#endif
#define PHS_LOG_GET_NBR_TR32K_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1602, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_LAST_TR32K_TIME(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1702, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_LAST_TR32K_TIME(v1)
#endif
#define PHS_LOG_LAST_TR32K_TIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1702, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FIRST_PDP_STATUS(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1802, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_FIRST_PDP_STATUS(v1)
#endif
#define PHS_LOG_FIRST_PDP_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1802, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NBR_FREEZE_STATUS(v1, v2, v3, v4) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1902, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_NBR_FREEZE_STATUS(v1, v2, v3, v4)
#endif
#define PHS_LOG_NBR_FREEZE_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1902, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GAP_SUSP_TRIG(v1, v2) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A02, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_GAP_SUSP_TRIG(v1, v2)
#endif
#define PHS_LOG_GAP_SUSP_TRIG_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A02, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_IRT_GAP_SUSP_RESUME(v1, v2, v3, v4) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_IRT_GAP_SUSP_RESUME(v1, v2, v3, v4)
#endif
#define PHS_LOG_IRT_GAP_SUSP_RESUME_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_AUTO_GAP_TIME_INFO(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1C02, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_AUTO_GAP_TIME_INFO(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_AUTO_GAP_TIME_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1C02, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRVCC_AUTO_GAP_REQ(v1, v2) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1D02, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_SRVCC_AUTO_GAP_REQ(v1, v2)
#endif
#define PHS_LOG_SRVCC_AUTO_GAP_REQ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1D02, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRVCC_AUTO_GAP_CHK(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E02, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_SRVCC_AUTO_GAP_CHK(v1, v2, v3)
#endif
#define PHS_LOG_SRVCC_AUTO_GAP_CHK_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E02, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCELL_SRV_RX(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1F02, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_SCELL_SRV_RX(v1, v2, v3)
#endif
#define PHS_LOG_SCELL_SRV_RX_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1F02, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MBMS_AR_RESET_TIME(v1, v2, v3, v4) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2002, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_MBMS_AR_RESET_TIME(v1, v2, v3, v4)
#endif
#define PHS_LOG_MBMS_AR_RESET_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2002, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_PHS_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_PHS_LOG_HNDLR_ENTRY(unsigned char v1);
void L1TRC_Send_PHS_LOG_HNDLR_ENTRY_L(unsigned char v1);
void L1TRC_Send_PHS_LOG_RCV_SCH_RNTI_CTRL(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned short v6, unsigned short v7, unsigned char v8);
void L1TRC_Send_PHS_LOG_CH_CHNG_ST(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_SUB_CHNG(unsigned char v1, unsigned long v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_PHS_LOG_SRCH_NXT_CH_CHNG(unsigned long v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_SCELL_CHNG(unsigned char v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_RCV_CH_CTRL(unsigned char v1);
void L1TRC_Send_PHS_LOG_CH_NBR_MIB_GET(unsigned short v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_CH_NBR_SI_GET(unsigned short v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_RCV_POS_CTRL(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_POS_SYNC_GET(unsigned long v1, unsigned long v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned long v6, unsigned char v7);
void L1TRC_Send_PHS_LOG_POS_MEAS_GET(unsigned long v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned char v5, unsigned char v6, unsigned long v7);
void L1TRC_Send_PHS_LOG_POS_CTRL_STUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_GET_SPECIAL_MB_MIB(unsigned long v1, unsigned long v2, unsigned short v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_PHS_LOG_EXE_EVT_INDX_RANGE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_NXT_STBY_GAP_TIME(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_TAS_TIMER(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_LOIF_TIMER(unsigned char v1);
void L1TRC_Send_PHS_LOG_ARX_TIMER(unsigned char v1);
void L1TRC_Send_PHS_LOG_HRT_TIME(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_PHS_LOG_HRT_TIME_FAIL(char v1);
void L1TRC_Send_PHS_LOG_GET_NBR_TR32K(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_LAST_TR32K_TIME(unsigned long v1);
void L1TRC_Send_PHS_LOG_FIRST_PDP_STATUS(unsigned char v1);
void L1TRC_Send_PHS_LOG_NBR_FREEZE_STATUS(unsigned char v1, unsigned char v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_GAP_SUSP_TRIG(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_IRT_GAP_SUSP_RESUME(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_AUTO_GAP_TIME_INFO(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_SRVCC_AUTO_GAP_REQ(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_SRVCC_AUTO_GAP_CHK(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_SCELL_SRV_RX(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_MBMS_AR_RESET_TIME(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);

void Set_EL1_PHS_2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_PHS_2()	(EL1_PHS_2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_PHS_2_phs_func_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_func_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var2_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var2_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var3_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var3_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_error_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_msg_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_msg_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_debug_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x20)!=0))
#define ChkL1MsgFltr_PHS_LOG_HNDLR_ENTRY()	ChkL1ClsFltr_EL1_PHS_2_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_HNDLR_ENTRY_L()	ChkL1ClsFltr_EL1_PHS_2_phs_msg_trace_l()
#define ChkL1MsgFltr_PHS_LOG_RCV_SCH_RNTI_CTRL()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_CH_CHNG_ST()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SUB_CHNG()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_NXT_CH_CHNG()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SCELL_CHNG()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_CH_CTRL()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_CH_NBR_MIB_GET()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_CH_NBR_SI_GET()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_RCV_POS_CTRL()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_POS_SYNC_GET()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_POS_MEAS_GET()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_POS_CTRL_STUS()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_GET_SPECIAL_MB_MIB()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_EXE_EVT_INDX_RANGE()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_NXT_STBY_GAP_TIME()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_TAS_TIMER()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_LOIF_TIMER()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_ARX_TIMER()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_HRT_TIME()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_HRT_TIME_FAIL()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_NBR_TR32K()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_LAST_TR32K_TIME()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_FIRST_PDP_STATUS()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_NBR_FREEZE_STATUS()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_GAP_SUSP_TRIG()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_IRT_GAP_SUSP_RESUME()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_AUTO_GAP_TIME_INFO()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SRVCC_AUTO_GAP_REQ()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SRVCC_AUTO_GAP_CHK()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SCELL_SRV_RX()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_MBMS_AR_RESET_TIME()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()


#endif
