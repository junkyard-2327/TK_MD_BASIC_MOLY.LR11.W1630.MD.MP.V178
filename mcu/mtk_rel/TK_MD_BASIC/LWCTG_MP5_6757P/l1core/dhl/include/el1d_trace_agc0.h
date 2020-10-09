#ifndef L1TRC_EL1D_AGC0_DEF_H
#define L1TRC_EL1D_AGC0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_AGC_CONTEXT(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_AGC_EVENT_CONTEXT(v1)  (unsigned char)(v1+4)
#define EL1D_TRC_STR_AGC_NEAS_START_TYPE_CONTEXT(v1)  (unsigned char)(v1+8)
#define EL1D_TRC_STR_AGC_REQ_TYPE_CONTEXT(v1)  (unsigned char)(v1+14)
#define EL1D_TRC_STR_AGC_REQ_CONTEXT(v1)  (unsigned char)(v1+19)
#define EL1D_TRC_STR_AGC_PS_REQ_CONTEXT(v1)  (unsigned char)(v1+23)
#define EL1D_TRC_STR_AGC_RXAGC_MEAS_TYPE(v1)  (unsigned char)(v1+26)
#define EL1D_TRC_STR_AGC_RXAGC_RF_CA_TYPE_CONFIG(v1)  (unsigned char)(v1+33)
#define EL1D_TRC_STR_AGC_CP_TYPE(v1)  (unsigned char)(v1+38)
#define EL1D_TRC_STR_AGC_FRAME_TYPE(v1)  (unsigned char)(v1+41)
#define EL1D_TRC_STR_AGC_BW_TYPE(v1)  (unsigned char)(v1+43)
#define EL1D_TRC_STR_AGC_DATA_RATE(v1)  (unsigned char)(v1+49)
#define EL1D_TRC_STR_AGC_RX_LPM_MODE(v1)  (unsigned char)(v1+51)
#define EL1D_TRC_STR_AGC_SET_CALIBRATION_DATA_PHASE(v1)  (unsigned char)(v1+56)
#define EL1D_TRC_STR_AGC_CALDATA_TYPE(v1)  (unsigned char)(v1+59)
#define EL1D_TRC_STR_AGC_REQ_SF_TYPE(v1)  (unsigned char)(v1+62)
#define EL1D_TRC_STR_AGC_SER_TAR_DIFF_TYPE(v1)  (unsigned char)(v1+66)
#define EL1D_TRC_STR_AGC_NBI_RATE_TYPE(v1)  (unsigned char)(v1+68)
#define EL1D_TRC_STR_AGC_ARX_NOT_APPLY_TYPE(v1)  (unsigned char)(v1+73)
#define EL1D_TRC_STR_AGC_TDD_SF_INFO(v1)  (unsigned char)(v1+79)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CONTEXT_ENTRY(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CONTEXT_ENTRY(v1)
#endif
#define EL1D_TRC_AGC_CONTEXT_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_CONTEXT_ENTRY_H(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CONTEXT_ENTRY_H(v1)
#endif
#define EL1D_TRC_AGC_CONTEXT_ENTRY_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_EVENT_TIMING(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x023C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_EVENT_TIMING(v1, v2)
#endif
#define EL1D_TRC_AGC_EVENT_TIMING_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x023C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_MEAS_TYPE_FROM_UPPER_LAYER(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x033C, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_AGC_MEAS_TYPE_FROM_UPPER_LAYER(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_MEAS_TYPE_FROM_UPPER_LAYER_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x033C, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_REQ_GENERAL(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043C, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REQ_GENERAL(v1, v2)
#endif
#define EL1D_TRC_AGC_REQ_GENERAL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043C, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_REQ_TIMING_INFO(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x053C, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REQ_TIMING_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_REQ_TIMING_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x053C, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_DL_SYM_BITMAP(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x063C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_DL_SYM_BITMAP(v1, v2)
#endif
#define EL1D_TRC_AGC_DL_SYM_BITMAP_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x063C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CC_MASK_INFO(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x073C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CC_MASK_INFO(v1, v2)
#endif
#define EL1D_TRC_AGC_CC_MASK_INFO_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x073C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_SER_TAR_DIFF(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x083C, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_SER_TAR_DIFF(v1, v2)
#endif
#define EL1D_TRC_AGC_SER_TAR_DIFF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x083C, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_FWS_SOURCE_SELECTION(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x093C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_AGC_FWS_SOURCE_SELECTION(v1)
#endif
#define EL1D_TRC_AGC_FWS_SOURCE_SELECTION_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x093C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_IS_MBSFN_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0A3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_IS_MBSFN_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_AGC_IS_MBSFN_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0A3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_LITE_ACI_DECISION(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_AGC_LITE_ACI_DECISION(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_LITE_ACI_DECISION_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_TDD_SF_INFO_INFO(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_TDD_SF_INFO_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_TDD_SF_INFO_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_INI_GAIN_INFO_1(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_AGC_INI_GAIN_INFO_1(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_INI_GAIN_INFO_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_INI_GAIN_INFO_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_13_DATA(TRC_MERGE_1S2C(0x0E3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12));\
	} while(0)
#else
	#define EL1D_TRC_AGC_INI_GAIN_INFO_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define EL1D_TRC_AGC_INI_GAIN_INFO_2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_13_DATA(TRC_MERGE_1S2C(0x0E3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_STORE_GAIN_INFO(v1, v2, v3, v4, v5) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_AGC_STORE_GAIN_INFO(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_AGC_STORE_GAIN_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_RFCC_CCCFG_parameters(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x103C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_RFCC_CCCFG_parameters(v1, v2)
#endif
#define EL1D_TRC_AGC_RFCC_CCCFG_parameters_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x103C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_SERVING_CELL_TABLE_IDX(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x113C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_SERVING_CELL_TABLE_IDX(v1, v2)
#endif
#define EL1D_TRC_AGC_SERVING_CELL_TABLE_IDX_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x113C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_INTRA_NONRX_SHORT_WIN_HANDLE(v1, v2, v3, v4, v5) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x123C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_AGC_INTRA_NONRX_SHORT_WIN_HANDLE(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_AGC_INTRA_NONRX_SHORT_WIN_HANDLE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x123C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_INTRA_NONRX_SHORT_WIN_HANDLE_SET_FIXED_GAIN(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x133C, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_AGC_INTRA_NONRX_SHORT_WIN_HANDLE_SET_FIXED_GAIN(v1)
#endif
#define EL1D_TRC_AGC_INTRA_NONRX_SHORT_WIN_HANDLE_SET_FIXED_GAIN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x133C, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_CMIF_MEAS_START_TYPE(v1, v2, v3, v4, v5) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x143C, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_MEAS_START_TYPE(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_AGC_CMIF_MEAS_START_TYPE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x143C, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_CELL_TYPE(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x153C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_CELL_TYPE(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_AGC_CMIF_CELL_TYPE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x153C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_ANT_PATH_CONFIG(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x163C, (unsigned char)(v5), (unsigned char)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_ANT_PATH_CONFIG(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_AGC_CMIF_ANT_PATH_CONFIG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x163C, (unsigned char)(v5), (unsigned char)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_CMIF_COMPOSITE_SFBD(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x173C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_COMPOSITE_SFBD(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_AGC_CMIF_COMPOSITE_SFBD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_7_DATA(TRC_MERGE_2S(0x173C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_CMIF_REQ_SF_TYPE(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x183C, (unsigned char)(v3), (unsigned char)(v4)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_REQ_SF_TYPE(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_CMIF_REQ_SF_TYPE_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x183C, (unsigned char)(v3), (unsigned char)(v4)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_NORMAL_SCENARIO_CONFIG(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x193C, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_NORMAL_SCENARIO_CONFIG(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_AGC_CMIF_NORMAL_SCENARIO_CONFIG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x193C, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_CM_STATUS(v1, v2, v3, v4, v5) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_CM_STATUS(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_AGC_CMIF_CM_STATUS_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x1A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_POS_STATUS(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_POS_STATUS(v1, v2)
#endif
#define EL1D_TRC_AGC_CMIF_POS_STATUS_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_TAS_STATUS(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1C3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_TAS_STATUS(v1, v2)
#endif
#define EL1D_TRC_AGC_CMIF_TAS_STATUS_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1C3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_LITE_ACI_STATUS(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_LITE_ACI_STATUS(v1)
#endif
#define EL1D_TRC_AGC_CMIF_LITE_ACI_STATUS_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_RX_DFE_INFO(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1E3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_RX_DFE_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_CMIF_RX_DFE_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1E3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_AGC_FIRST_TIME_TRACKING(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_AGC_FIRST_TIME_TRACKING(v1)
#endif
#define EL1D_TRC_AGC_CMIF_AGC_FIRST_TIME_TRACKING_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_LITE_ACI_INFO(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x203C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_LITE_ACI_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_CMIF_LITE_ACI_INFO_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x203C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_CMIF_READ_RSSI(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x213C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_READ_RSSI(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_CMIF_READ_RSSI_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x213C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_UPDATE_VALID_BITS(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x223C, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_UPDATE_VALID_BITS(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_CMIF_READ_GAIN_UPDATE_VALID_BITS_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x223C, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_READ_LITE_ACI_UPDATE_VALID_BITS(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x233C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_READ_LITE_ACI_UPDATE_VALID_BITS(v1, v2)
#endif
#define EL1D_TRC_AGC_CMIF_READ_LITE_ACI_UPDATE_VALID_BITS_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x233C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_DUMP_VALID_BITS(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x243C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_DUMP_VALID_BITS(v1, v2)
#endif
#define EL1D_TRC_AGC_CMIF_READ_GAIN_DUMP_VALID_BITS_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x243C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_LITE_ACI_REPORT(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x253C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_LITE_ACI_REPORT(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_CMIF_READ_GAIN_LITE_ACI_REPORT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x253C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_SEARCH_GAIN_UPDATE_VALID_BITS(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x263C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_SEARCH_GAIN_UPDATE_VALID_BITS(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_CMIF_SEARCH_GAIN_UPDATE_VALID_BITS_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x263C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_CMIF_POS_GAIN_DUMP_VALID_BITS(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x273C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_POS_GAIN_DUMP_VALID_BITS(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_CMIF_POS_GAIN_DUMP_VALID_BITS_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x273C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_VALID_TYPE(v1, v2, v3, v4, v5) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x283C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_VALID_TYPE(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_VALID_TYPE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x283C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_TRK_RESULT(v1, v2, v3, v4, v5) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x293C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_TRK_RESULT(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_TRK_RESULT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x293C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_CS_RESULT(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_CS_RESULT(v1)
#endif
#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_CS_RESULT_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_FEATURE_OPTION(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_FEATURE_OPTION(v1)
#endif
#define EL1D_TRC_AGC_CMIF_FEATURE_OPTION_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_LNA_IDX_RESULT(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_LNA_IDX_RESULT(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_LNA_IDX_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_LNA_IDX_TYPE(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_LNA_IDX_TYPE(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_LNA_IDX_TYPE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_SET_DEFAULT_CALDATA(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E3C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_SET_DEFAULT_CALDATA(v1)
#endif
#define EL1D_TRC_AGC_SET_DEFAULT_CALDATA_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E3C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_SET_CALDATA_BURST_GENERAL_INFO(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F3C, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_AGC_SET_CALDATA_BURST_GENERAL_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_SET_CALDATA_BURST_GENERAL_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F3C, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_SET_CALDATA_BURST_PL_PARTIAL_INTERPOLATION_INFO(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x303C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_AGC_SET_CALDATA_BURST_PL_PARTIAL_INTERPOLATION_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_SET_CALDATA_BURST_PL_PARTIAL_INTERPOLATION_INFO_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x303C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_SET_CALDATA_ROUTE_FC100K_INFO(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x313C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_SET_CALDATA_ROUTE_FC100K_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_SET_CALDATA_ROUTE_FC100K_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x313C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_SET_CALDATA_PL_SEARCH_INFO(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x323C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_SET_CALDATA_PL_SEARCH_INFO(v1, v2)
#endif
#define EL1D_TRC_AGC_SET_CALDATA_PL_SEARCH_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x323C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_BUFFER_STATUS(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x333C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_BUFFER_STATUS(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_BUFFER_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x333C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_REG_READ(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x343C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ(v1, v2)
#endif
#define EL1D_TRC_AGC_REG_READ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x343C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_1(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x353C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_1(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x353C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_2(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x363C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_2(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x363C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_3(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x373C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_3(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_3_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x373C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_4(v1, v2, v3, v4) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x383C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_4(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_4_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x383C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_5(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x393C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_5(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_5_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x393C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_6(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_6(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_REG_READ_CHECK_INFO_6_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_REG_READ_H(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ_H(v1, v2)
#endif
#define EL1D_TRC_AGC_REG_READ_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_REG_READ_H_SERVING_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x3C3C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ_H_SERVING_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_AGC_REG_READ_H_SERVING_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_8_DATA(TRC_MERGE_2S(0x3C3C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_REG_READ_H_INTER_RX(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ_H_INTER_RX(v1, v2)
#endif
#define EL1D_TRC_AGC_REG_READ_H_INTER_RX_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_REG_READ_H_CHECK_INFO_1(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3E3C, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_AGC_REG_READ_H_CHECK_INFO_1(v1)
#endif
#define EL1D_TRC_AGC_REG_READ_H_CHECK_INFO_1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3E3C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_NBIF_GET_RESULT_CHECK1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x3F3C, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_NBIF_GET_RESULT_CHECK1(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_NBIF_GET_RESULT_CHECK1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x3F3C, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_NBIF_GET_RESULT_CHECK2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x403C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_NBIF_GET_RESULT_CHECK2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_NBIF_GET_RESULT_CHECK2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x403C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_NBIF_GET_RESULT_CHECK3(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_13_DATA(TRC_MERGE_1S2C(0x413C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12));\
	} while(0)
#else
	#define EL1D_NBIF_GET_RESULT_CHECK3(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define EL1D_NBIF_GET_RESULT_CHECK3_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_13_DATA(TRC_MERGE_1S2C(0x413C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_NBIF_GET_RESULT_CHECK4(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x423C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_NBIF_GET_RESULT_CHECK4(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_NBIF_GET_RESULT_CHECK4_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x423C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_ARX_LPM_SET_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x433C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_AGC_ARX_LPM_SET_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_AGC_ARX_LPM_SET_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x433C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_ARX_LPM_NOT_SET_H(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x443C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_ARX_LPM_NOT_SET_H(v1)
#endif
#define EL1D_TRC_AGC_ARX_LPM_NOT_SET_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x443C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_ARX_RFC_LPM_WRONG_H(v1, v2) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x453C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_ARX_RFC_LPM_WRONG_H(v1, v2)
#endif
#define EL1D_TRC_AGC_ARX_RFC_LPM_WRONG_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x453C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_ARX_WPD_TRG_M(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x463C, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_AGC_ARX_WPD_TRG_M(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_ARX_WPD_TRG_M_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x463C, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_AGC_ARX_DEBUG_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x473C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_AGC_ARX_DEBUG_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_AGC_ARX_DEBUG_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x473C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_ARX_AGC_QUEUE_CHANGE_H(v1, v2, v3) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x483C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AGC_ARX_AGC_QUEUE_CHANGE_H(v1, v2, v3)
#endif
#define EL1D_TRC_AGC_ARX_AGC_QUEUE_CHANGE_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x483C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_CURR_PHYTIME(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x493C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_AGC_CURR_PHYTIME(v1)
#endif
#define EL1D_TRC_AGC_CURR_PHYTIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x493C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AGC_DIFF_PHYTIME(v1) do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_AGC_DIFF_PHYTIME(v1)
#endif
#define EL1D_TRC_AGC_DIFF_PHYTIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_HRT_BYPASS_INI_TICK() do {\
		if(EL1D_AGC0_Trace_Filter[0]==1 && (EL1D_AGC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_HRT_BYPASS_INI_TICK()
#endif
#define EL1D_TRC_HRT_BYPASS_INI_TICK_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_AGC0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_AGC_CONTEXT_ENTRY(unsigned char v1);
void L1TRC_Send_EL1D_TRC_AGC_CONTEXT_ENTRY_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_AGC_EVENT_TIMING(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_AGC_MEAS_TYPE_FROM_UPPER_LAYER(unsigned char v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_AGC_REQ_GENERAL(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_AGC_REQ_TIMING_INFO(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_AGC_DL_SYM_BITMAP(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_AGC_CC_MASK_INFO(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_AGC_SER_TAR_DIFF(unsigned char v1, long v2);
void L1TRC_Send_EL1D_TRC_AGC_FWS_SOURCE_SELECTION(unsigned long v1);
void L1TRC_Send_EL1D_TRC_AGC_IS_MBSFN_INFO(short v1, short v2, unsigned char v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_EL1D_TRC_AGC_LITE_ACI_DECISION(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_AGC_TDD_SF_INFO_INFO(short v1, short v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_AGC_INI_GAIN_INFO_1(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_AGC_INI_GAIN_INFO_2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12);
void L1TRC_Send_EL1D_TRC_AGC_STORE_GAIN_INFO(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_AGC_RFCC_CCCFG_parameters(short v1, short v2);
void L1TRC_Send_EL1D_TRC_AGC_SERVING_CELL_TABLE_IDX(short v1, short v2);
void L1TRC_Send_EL1D_TRC_AGC_INTRA_NONRX_SHORT_WIN_HANDLE(short v1, short v2, short v3, short v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_AGC_INTRA_NONRX_SHORT_WIN_HANDLE_SET_FIXED_GAIN(short v1);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_MEAS_START_TYPE(unsigned char v1, unsigned char v2, unsigned long v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_CELL_TYPE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_ANT_PATH_CONFIG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned char v5, unsigned char v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_COMPOSITE_SFBD(unsigned long v1, unsigned short v2, unsigned long v3, unsigned short v4, unsigned long v5, unsigned short v6, unsigned long v7, unsigned short v8);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_REQ_SF_TYPE(unsigned long v1, unsigned long v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_NORMAL_SCENARIO_CONFIG(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_CM_STATUS(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_POS_STATUS(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_TAS_STATUS(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_LITE_ACI_STATUS(unsigned long v1);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_RX_DFE_INFO(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_AGC_FIRST_TIME_TRACKING(long v1);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_LITE_ACI_INFO(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_READ_RSSI(long v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_READ_GAIN_UPDATE_VALID_BITS(short v1, unsigned long v2, short v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_READ_LITE_ACI_UPDATE_VALID_BITS(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_READ_GAIN_DUMP_VALID_BITS(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_READ_GAIN_LITE_ACI_REPORT(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_SEARCH_GAIN_UPDATE_VALID_BITS(short v1, short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_POS_GAIN_DUMP_VALID_BITS(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_VALID_TYPE(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_TRK_RESULT(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_CS_RESULT(unsigned long v1);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_FEATURE_OPTION(unsigned long v1);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_LNA_IDX_RESULT(short v1, short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_LNA_IDX_TYPE(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_AGC_SET_DEFAULT_CALDATA(unsigned char v1);
void L1TRC_Send_EL1D_TRC_AGC_SET_CALDATA_BURST_GENERAL_INFO(unsigned char v1, unsigned short v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_AGC_SET_CALDATA_BURST_PL_PARTIAL_INTERPOLATION_INFO(unsigned long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_AGC_SET_CALDATA_ROUTE_FC100K_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_AGC_SET_CALDATA_PL_SEARCH_INFO(short v1, short v2);
void L1TRC_Send_EL1D_TRC_AGC_BUFFER_STATUS(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ_CHECK_INFO_1(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ_CHECK_INFO_2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ_CHECK_INFO_3(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ_CHECK_INFO_4(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ_CHECK_INFO_5(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ_CHECK_INFO_6(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ_H_SERVING_TIME(unsigned long v1, unsigned short v2, unsigned long v3, unsigned short v4, unsigned long v5, unsigned short v6, unsigned long v7, unsigned short v8, short v9, short v10);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ_H_INTER_RX(short v1, short v2);
void L1TRC_Send_EL1D_TRC_AGC_REG_READ_H_CHECK_INFO_1(short v1);
void L1TRC_Send_EL1D_NBIF_GET_RESULT_CHECK1(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_NBIF_GET_RESULT_CHECK2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1D_NBIF_GET_RESULT_CHECK3(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12);
void L1TRC_Send_EL1D_NBIF_GET_RESULT_CHECK4(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_AGC_ARX_LPM_SET_H(unsigned short v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_AGC_ARX_LPM_NOT_SET_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_AGC_ARX_RFC_LPM_WRONG_H(short v1, short v2);
void L1TRC_Send_EL1D_TRC_AGC_ARX_WPD_TRG_M(short v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_AGC_ARX_DEBUG_L(short v1, short v2, short v3, short v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_AGC_ARX_AGC_QUEUE_CHANGE_H(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_AGC_CURR_PHYTIME(unsigned long v1);
void L1TRC_Send_EL1D_TRC_AGC_DIFF_PHYTIME(unsigned long v1);
void L1TRC_Send_EL1D_TRC_HRT_BYPASS_INI_TICK(void);

void Set_EL1D_AGC0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_AGC0()	(EL1D_AGC0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_H()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_M()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_H()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_M()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CALDATA_H()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CALDATA_M()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CALDATA_L()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_META_H()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_META_M()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_META_L()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_H()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_M()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()	(ChkL1ModFltr_EL1D_AGC0()&&((EL1D_AGC0_Trace_Filter[2]&0x40)!=0))
#define ChkL1MsgFltr_EL1D_TRC_AGC_CONTEXT_ENTRY()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CONTEXT_ENTRY_H()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_EVENT_TIMING()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_MEAS_TYPE_FROM_UPPER_LAYER()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REQ_GENERAL()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REQ_TIMING_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_DL_SYM_BITMAP()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CC_MASK_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_SER_TAR_DIFF()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_FWS_SOURCE_SELECTION()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_IS_MBSFN_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_LITE_ACI_DECISION()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_TDD_SF_INFO_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_INI_GAIN_INFO_1()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_INI_GAIN_INFO_2()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_STORE_GAIN_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_RFCC_CCCFG_parameters()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_SERVING_CELL_TABLE_IDX()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_INTRA_NONRX_SHORT_WIN_HANDLE()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_INTRA_NONRX_SHORT_WIN_HANDLE_SET_FIXED_GAIN()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_MEAS_START_TYPE()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_CELL_TYPE()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_ANT_PATH_CONFIG()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_COMPOSITE_SFBD()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_REQ_SF_TYPE()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_NORMAL_SCENARIO_CONFIG()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_CM_STATUS()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_POS_STATUS()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_TAS_STATUS()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_LITE_ACI_STATUS()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_RX_DFE_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_AGC_FIRST_TIME_TRACKING()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_LITE_ACI_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_READ_RSSI()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_READ_GAIN_UPDATE_VALID_BITS()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_READ_LITE_ACI_UPDATE_VALID_BITS()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_READ_GAIN_DUMP_VALID_BITS()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_READ_GAIN_LITE_ACI_REPORT()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_SEARCH_GAIN_UPDATE_VALID_BITS()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_POS_GAIN_DUMP_VALID_BITS()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_VALID_TYPE()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_TRK_RESULT()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_CS_RESULT()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_FEATURE_OPTION()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_LNA_IDX_RESULT()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CMIF_READ_GAIN_BACKUP_LNA_IDX_TYPE()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CMIF_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_SET_DEFAULT_CALDATA()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CALDATA_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_SET_CALDATA_BURST_GENERAL_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CALDATA_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_SET_CALDATA_BURST_PL_PARTIAL_INTERPOLATION_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CALDATA_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_SET_CALDATA_ROUTE_FC100K_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CALDATA_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_SET_CALDATA_PL_SEARCH_INFO()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_CALDATA_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_BUFFER_STATUS()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_META_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ_CHECK_INFO_1()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ_CHECK_INFO_2()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ_CHECK_INFO_3()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ_CHECK_INFO_4()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ_CHECK_INFO_5()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ_CHECK_INFO_6()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ_H()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ_H_SERVING_TIME()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ_H_INTER_RX()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_REG_READ_H_CHECK_INFO_1()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_NBIF_GET_RESULT_CHECK1()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_NBIF_GET_RESULT_CHECK2()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_NBIF_GET_RESULT_CHECK3()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_NBIF_GET_RESULT_CHECK4()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_ARX_LPM_SET_H()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_ARX_LPM_NOT_SET_H()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_ARX_RFC_LPM_WRONG_H()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_ARX_WPD_TRG_M()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_ARX_DEBUG_L()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_AGC_ARX_AGC_QUEUE_CHANGE_H()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_CURR_PHYTIME()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_AGC_DIFF_PHYTIME()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_HRT_BYPASS_INI_TICK()	ChkL1ClsFltr_EL1D_AGC0_EL1D_TRC_AGC_MAIN_H()


#endif
