#ifndef L1TRC_EL1D_RX1_DEF_H
#define L1TRC_EL1D_RX1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_RX_RF_LPM_TYPE(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_RX_AGC_LPM_REQ(v1)  (unsigned char)(v1+9)
#define EL1D_TRC_STR_RX_AFC_FO_PROCESS(v1)  (unsigned char)(v1+13)
#define EL1D_TRC_STR_RX_AFC_STORE_REL(v1)  (unsigned char)(v1+22)
#define EL1D_TRC_STR_RX_AFC_TRX_TYPE(v1)  (unsigned char)(v1+24)
#define EL1D_TRC_STR_RX_AFC_FRAME_TYPE(v1)  (unsigned char)(v1+26)
#define EL1D_TRC_STR_RX_AFC_TEMP_DATA_TYPE(v1)  (unsigned char)(v1+28)
#define EL1D_TRC_STR_RX_AFC_TMS_MAIN_TIMESTAMP_TYPE(v1)  (unsigned char)(v1+30)
#define EL1D_TRC_STR_RX_AFC_DEBUG(v1)  (unsigned char)(v1+32)
#define EL1D_TRC_STR_RX_AFC_TMS_SCHEDULE_TYPE(v1)  (unsigned char)(v1+52)
#define EL1D_TRC_STR_RX_CSI_TYPE(v1)  (unsigned char)(v1+54)
#define EL1D_TRC_STR_RX_CSI_DCI0_EVENT_TYPE(v1)  (unsigned char)(v1+57)
#define EL1D_TRC_STR_RX_CSI_OCCUPY_FREE_TYPE(v1)  (unsigned char)(v1+59)
#define EL1D_TRC_STR_RX_CSI_RPT_MODE(v1)  (unsigned char)(v1+63)
#define EL1D_TRC_STR_RX_CSI_RI(v1)  (unsigned char)(v1+75)
#define EL1D_TRC_STR_RX_IC_LST_STS(v1)  (unsigned char)(v1+77)
#define EL1D_TRC_STR_RX_NBI_TYPE(v1)  (unsigned char)(v1+82)
#define EL1D_TRC_STR_RX_NBI_CC_ANT_TYPE(v1)  (unsigned char)(v1+85)
#define EL1D_TRC_STR_RX_NBI_TDT_TYPE(v1)  (unsigned char)(v1+93)
#define EL1D_TRC_ACSI_PMI_CTRL_STATE(v1)  (unsigned char)(v1+97)
#define EL1D_TRC_STR_ICSP_PBCH_IC(v1)  (unsigned char)(v1+101)
#define EL1D_TRC_STR_AFC_HST_FORCE_MD_INFO(v1)  (unsigned char)(v1+106)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_HW_SET_DDR_EN_RXBRP_UNMASK_H(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x003A, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX1_HW_SET_DDR_EN_RXBRP_UNMASK_H(v1, v2)
#endif
#define EL1D_TRC_RX1_HW_SET_DDR_EN_RXBRP_UNMASK_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x003A, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_RFCC_PRE_SYNC_LAST_SYMBOL_H(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_RFCC_PRE_SYNC_LAST_SYMBOL_H(v1)
#endif
#define EL1D_TRC_RX1_RFCC_PRE_SYNC_LAST_SYMBOL_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_RFCC_OFF_TO_ON_H(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x023A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_RFCC_OFF_TO_ON_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_RFCC_OFF_TO_ON_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x023A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_RFCC_ON_TO_OFF_H(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x033A, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_RFCC_ON_TO_OFF_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_RFCC_ON_TO_OFF_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x033A, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_RF_SF_LOW_POWER_CMD_M(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x043A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_RF_SF_LOW_POWER_CMD_M(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_RF_SF_LOW_POWER_CMD_M_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x043A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_TDB_OFF_TO_ON_H(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x053A, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX1_TDB_OFF_TO_ON_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_TDB_OFF_TO_ON_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x053A, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_TDB_ON_TO_OFF_H(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x063A, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX1_TDB_ON_TO_OFF_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_TDB_ON_TO_OFF_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x063A, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AGC_SET_REQUEST_H(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x073A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AGC_SET_REQUEST_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_AGC_SET_REQUEST_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x073A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AGC_CLEAR_REQUEST_H(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x083A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AGC_CLEAR_REQUEST_H(v1)
#endif
#define EL1D_TRC_RX1_AGC_CLEAR_REQUEST_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x083A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_AGC_SF_CONFIG_M(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x093A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AGC_SF_CONFIG_M(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_AGC_SF_CONFIG_M_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x093A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_PROC_INFO(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A3A, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_PROC_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_AFC_PROC_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A3A, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_FOM_TX(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0B3A, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_FOM_TX(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_FOM_TX_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0B3A, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_FOM_RX(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C3A, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_FOM_RX(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_FOM_RX_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C3A, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_FOM_C_TX(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0D3A, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_FOM_C_TX(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_AFC_FOM_C_TX_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0D3A, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v6), (long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_FOM_C_RX(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x0E3A, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_FOM_C_RX(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX1_AFC_FOM_C_RX_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x0E3A, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_PERIODIC(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F3A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_PERIODIC(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_AFC_PERIODIC_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F3A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_CS_BIN_TO_DAC(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x103A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_CS_BIN_TO_DAC(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_AFC_CS_BIN_TO_DAC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x103A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_CELL_SWITCH(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x113A, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_CELL_SWITCH(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX1_AFC_CELL_SWITCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x113A, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_RELOAD_MBMS(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x123A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v5), (unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_RELOAD_MBMS(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_AFC_RELOAD_MBMS_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x123A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v5), (unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_RELOAD_C_MBMS(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x133A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_RELOAD_C_MBMS(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX1_AFC_RELOAD_C_MBMS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x133A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_RXNCO_CSCM(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x143A, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_RXNCO_CSCM(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_RXNCO_CSCM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x143A, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX1_AFC_SAVE_TRUST_DAC(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x153A, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_SAVE_TRUST_DAC(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_AFC_SAVE_TRUST_DAC_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x153A, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_OTHER_RAT(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x163A, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_OTHER_RAT(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_AFC_OTHER_RAT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x163A, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_OTHER_RAT_DAC_ABNORMAL_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x173A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_OTHER_RAT_DAC_ABNORMAL_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_OTHER_RAT_DAC_ABNORMAL_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x173A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_SWAP_DAC(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x183A, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_SWAP_DAC(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_AFC_SWAP_DAC_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x183A, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_RST(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x193A, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_RST(v1)
#endif
#define EL1D_TRC_RX1_AFC_RST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x193A, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_RST_BEFORE_ICS(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1A3A, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_RST_BEFORE_ICS(v1)
#endif
#define EL1D_TRC_RX1_AFC_RST_BEFORE_ICS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1A3A, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_DAC_FORCE(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B3A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_DAC_FORCE(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_AFC_DAC_FORCE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B3A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_LRST(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C3A, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_LRST(v1)
#endif
#define EL1D_TRC_RX1_AFC_LRST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C3A, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_COCLK_LRST(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_COCLK_LRST(v1)
#endif
#define EL1D_TRC_RX1_AFC_COCLK_LRST_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX1_AFC_SET_SYN_ON(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E3A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_SET_SYN_ON(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_AFC_SET_SYN_ON_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E3A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_SET_RX_SYN_PARAM(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x1F3A, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_SET_RX_SYN_PARAM(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_AFC_SET_RX_SYN_PARAM_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x1F3A, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_SET_TX_SYN_PARAM(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x203A, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_SET_TX_SYN_PARAM(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_AFC_SET_TX_SYN_PARAM_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x203A, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_SET_SYN_OTF(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x213A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_SET_SYN_OTF(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_SET_SYN_OTF_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x213A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_REQ_TX_ON_IN_NBR() do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x223A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_REQ_TX_ON_IN_NBR()
#endif
#define EL1D_TRC_RX1_AFC_REQ_TX_ON_IN_NBR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x223A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_ENTER_NONRX_INTER_FREQ_WIN(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x233A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_ENTER_NONRX_INTER_FREQ_WIN(v1)
#endif
#define EL1D_TRC_RX1_AFC_ENTER_NONRX_INTER_FREQ_WIN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x233A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_DSP_PROC_INFO(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x243A, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_DSP_PROC_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_AFC_DSP_PROC_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x243A, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_DSP_CMD(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x253A, (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), (char)(v7)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_DSP_CMD(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_AFC_DSP_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x253A, (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), (char)(v7)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_DSP_CMD_SCELL(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x263A, (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_DSP_CMD_SCELL(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_DSP_CMD_SCELL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x263A, (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_UL_TXNCO(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x273A, (short)(v1)), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_UL_TXNCO(v1, v2)
#endif
#define EL1D_TRC_RX1_AFC_UL_TXNCO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x273A, (short)(v1)), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_UL_RR(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x283A, (char)(v3), TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_UL_RR(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_AFC_UL_RR_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x283A, (char)(v3), TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX1_AFC_DL_RR(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x293A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_DL_RR(v1, v2)
#endif
#define EL1D_TRC_RX1_AFC_DL_RR_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x293A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_AFC_OC_SNR(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2A3A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_OC_SNR(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_AFC_OC_SNR_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2A3A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_HANDLE_OC_RPT(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B3A, (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_HANDLE_OC_RPT(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_AFC_HANDLE_OC_RPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B3A, (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_HANDLE_MBMS_RPT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2C3A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_HANDLE_MBMS_RPT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_AFC_HANDLE_MBMS_RPT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2C3A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_PREPARE_TX_SYN_SET(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D3A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), (char)(v4)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_PREPARE_TX_SYN_SET(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_AFC_PREPARE_TX_SYN_SET_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D3A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_HST_FOE_DIFF(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2E3A, (char)(v2), (unsigned char)(v4)), (unsigned long)(v1), (long)(v3), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_HST_FOE_DIFF(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_HST_FOE_DIFF_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2E3A, (char)(v2), (unsigned char)(v4)), (unsigned long)(v1), (long)(v3), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_AFC_HST_SCH(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F3A, (char)(v1), (unsigned char)(v2)), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_HST_SCH(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_AFC_HST_SCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F3A, (char)(v1), (unsigned char)(v2)), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_READ_AUXADC_LATEST(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x303A, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_READ_AUXADC_LATEST(v1)
#endif
#define EL1D_TRC_RX1_AFC_READ_AUXADC_LATEST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x303A, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_STATUS_NOT_RDY_H(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x313A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_STATUS_NOT_RDY_H(v1)
#endif
#define EL1D_TRC_RX1_AFC_STATUS_NOT_RDY_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x313A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_DIFF_FROM_RF_FREQ_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x323A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_DIFF_FROM_RF_FREQ_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_DIFF_FROM_RF_FREQ_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x323A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_TEMPER_NO_UPD(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x333A, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TEMPER_NO_UPD(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_AFC_TEMPER_NO_UPD_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x333A, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_AFC_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x343A, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX1_AFC_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x343A, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_AFC_TMS_ACCUM(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x353A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_ACCUM(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_AFC_TMS_ACCUM_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x353A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_AFC_TMS_OTF(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x363A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_OTF(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX1_AFC_TMS_OTF_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x363A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_AFC_TMS_OTF_TBL(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x373A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_OTF_TBL(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_TMS_OTF_TBL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x373A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_TMS_OTF_VMAP(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x383A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_OTF_VMAP(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_TMS_OTF_VMAP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x383A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_TMS_TFC(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_13_DATA(TRC_MERGE_1S2C(0x393A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_TFC(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define EL1D_TRC_RX1_AFC_TMS_TFC_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_13_DATA(TRC_MERGE_1S2C(0x393A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_AFC_TMS_TFC_2(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3A3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_TFC_2(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_AFC_TMS_TFC_2_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3A3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_AFC_TMS_TFC_TBL(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3B3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_TFC_TBL(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_TMS_TFC_TBL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3B3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_TMS_ICL(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3C3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_ICL(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_AFC_TMS_ICL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3C3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_TMS_FREQERR_CALC(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3D3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_FREQERR_CALC(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_AFC_TMS_FREQERR_CALC_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3D3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_TMS_SCHEDULE(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3E3A, (unsigned char)(v6), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_SCHEDULE(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_AFC_TMS_SCHEDULE_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3E3A, (unsigned char)(v6), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_TMS_UFPAIR_COLLECT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3F3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_UFPAIR_COLLECT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_AFC_TMS_UFPAIR_COLLECT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3F3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_AFC_TMS_MAIN_TIMESTAMP(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x403A, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_MAIN_TIMESTAMP(v1, v2)
#endif
#define EL1D_TRC_RX1_AFC_TMS_MAIN_TIMESTAMP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x403A, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_TMS_USE_RAT(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x413A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_TMS_USE_RAT(v1)
#endif
#define EL1D_TRC_RX1_AFC_TMS_USE_RAT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x413A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_AFC_HST_FORCE_MD_INFO(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x423A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_AFC_HST_FORCE_MD_INFO(v1)
#endif
#define EL1D_TRC_RX1_AFC_HST_FORCE_MD_INFO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x423A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_FWS_RPT_ACCU_SYMCNT(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x433A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), (char)(v4)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_RPT_ACCU_SYMCNT(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_FWS_RPT_ACCU_SYMCNT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x433A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), (char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_FWS_RPT_SYM_OFST(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x443A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_RPT_SYM_OFST(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_FWS_RPT_SYM_OFST_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x443A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_FWS_RPT_GIC(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x453A, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_RPT_GIC(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_FWS_RPT_GIC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x453A, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_FWS_RPT_COMB_1(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x463A, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_RPT_COMB_1(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX1_FWS_RPT_COMB_1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x463A, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_FWS_FBD_ADJUST(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x473A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_FBD_ADJUST(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_FWS_FBD_ADJUST_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x473A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_FWS_ACCU_ERR(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x483A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_ACCU_ERR(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_FWS_ACCU_ERR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x483A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_FWS_CRS_RLT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x493A, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_CRS_RLT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_FWS_CRS_RLT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x493A, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_FWS_MRS_RLT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4A3A, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_MRS_RLT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_FWS_MRS_RLT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4A3A, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_FWS_1ST_RLT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4B3A, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_1ST_RLT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_FWS_1ST_RLT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4B3A, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_FWS_SYM_RST(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C3A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_SYM_RST(v1)
#endif
#define EL1D_TRC_RX1_FWS_SYM_RST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C3A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_FWS_ASSERT_TRC_0(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4D3A, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v4)), (long)(v3), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_ASSERT_TRC_0(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_FWS_ASSERT_TRC_0_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4D3A, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v4)), (long)(v3), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_FWS_2CC_BOUND(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E3A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_2CC_BOUND(v1)
#endif
#define EL1D_TRC_RX1_FWS_2CC_BOUND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E3A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_FWS_DELAY_RPT(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4F3A, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX1_FWS_DELAY_RPT(v1, v2)
#endif
#define EL1D_TRC_RX1_FWS_DELAY_RPT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4F3A, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_CSI_RPT_MODE(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x503A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_CSI_RPT_MODE(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_CSI_RPT_MODE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x503A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_CSI_DSP_RPT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x513A, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_CSI_DSP_RPT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_CSI_DSP_RPT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x513A, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_CSI_TX_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x523A, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (unsigned char)(v3), (char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_RX1_CSI_TX_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RX1_CSI_TX_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x523A, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (unsigned char)(v3), (char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_PCSI_PRIORITY_DET(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x533A, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_PCSI_PRIORITY_DET(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_PCSI_PRIORITY_DET_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x533A, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_PCSI_EVENT(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x543A, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_PCSI_EVENT(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_PCSI_EVENT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x543A, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_PCSI_ACSI_COLLISION() do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x553A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_PCSI_ACSI_COLLISION()
#endif
#define EL1D_TRC_RX1_PCSI_ACSI_COLLISION_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x553A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_PCSI_TX(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x563A, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_PCSI_TX(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_PCSI_TX_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x563A, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ACSI_DCI0_DET_ERROR(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x573A, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ACSI_DCI0_DET_ERROR(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_ACSI_DCI0_DET_ERROR_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x573A, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ACSI_DCI0_DET_VLD(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x583A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ACSI_DCI0_DET_VLD(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_ACSI_DCI0_DET_VLD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x583A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ACSI_DCI0_DET_BUF(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x593A, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v5)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ACSI_DCI0_DET_BUF(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_ACSI_DCI0_DET_BUF_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x593A, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v5)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ACSI_DCI0_LISR(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A3A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ACSI_DCI0_LISR(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_ACSI_DCI0_LISR_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A3A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ACSI_DCI0_EVENT(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5B3A, (short)(v2)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v7), TRC_BOXSTER_PAD), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ACSI_DCI0_EVENT(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX1_ACSI_DCI0_EVENT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5B3A, (short)(v2)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v7), TRC_BOXSTER_PAD), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ACSI_DCI0_TX(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5C3A, (short)(v1)), TRC_MERGE_1S2C((short)(v5), (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ACSI_DCI0_TX(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_ACSI_DCI0_TX_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5C3A, (short)(v1)), TRC_MERGE_1S2C((short)(v5), (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ACSI_RAR_TRIGGER() do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ACSI_RAR_TRIGGER()
#endif
#define EL1D_TRC_RX1_ACSI_RAR_TRIGGER_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ACSI_RAR_EVENT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5E3A, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v5)), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ACSI_RAR_EVENT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_ACSI_RAR_EVENT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5E3A, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v5)), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ACSI_RAR_TX(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5F3A, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ACSI_RAR_TX(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_ACSI_RAR_TX_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5F3A, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_CSI_OCCUPY_FREE_SET(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x603A, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX1_CSI_OCCUPY_FREE_SET(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_CSI_OCCUPY_FREE_SET_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x603A, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_CSI_OCCUPY_BUSY_SET(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x613A, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_CSI_OCCUPY_BUSY_SET(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_CSI_OCCUPY_BUSY_SET_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x613A, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_CSI_INFO_BUF_SET(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x623A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_CSI_INFO_BUF_SET(v1)
#endif
#define EL1D_TRC_RX1_CSI_INFO_BUF_SET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x623A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_CSI_TICK_SET(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x633A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_CSI_TICK_SET(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_CSI_TICK_SET_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x633A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_CSI_ONLY(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x643A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_CSI_ONLY(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_CSI_ONLY_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x643A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_CSI_DROP_ACSI() do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x653A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_CSI_DROP_ACSI()
#endif
#define EL1D_TRC_RX1_CSI_DROP_ACSI_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x653A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_ACSI_TXINFO_BY_L1C(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x663A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX0_ACSI_TXINFO_BY_L1C(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_ACSI_TXINFO_BY_L1C_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x663A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_ACSI_PMI_CMD(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x673A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX0_ACSI_PMI_CMD(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_ACSI_PMI_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x673A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_ACSI_PMI_CTRL_LISR_UPDATE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x683A, (short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v7)), (unsigned long)(v3), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX0_ACSI_PMI_CTRL_LISR_UPDATE(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX0_ACSI_PMI_CTRL_LISR_UPDATE_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x683A, (short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v7)), (unsigned long)(v3), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_ACSI_PMI_SEARCH_LATEST(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x693A, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX0_ACSI_PMI_SEARCH_LATEST(v1, v2)
#endif
#define EL1D_TRC_RX0_ACSI_PMI_SEARCH_LATEST_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x693A, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_ACSI_PMI_CTRL_UPDATE(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6A3A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_ACSI_PMI_CTRL_UPDATE(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_ACSI_PMI_CTRL_UPDATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6A3A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_ACSI_FAST_DETECTED_DCI0() do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6B3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_ACSI_FAST_DETECTED_DCI0()
#endif
#define EL1D_TRC_RX0_ACSI_FAST_DETECTED_DCI0_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6B3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_ACSI_FAST_DETECTED_INVLD_DCI0() do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6C3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_ACSI_FAST_DETECTED_INVLD_DCI0()
#endif
#define EL1D_TRC_RX0_ACSI_FAST_DETECTED_INVLD_DCI0_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6C3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_ACSI_SET_BUF_INFO(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6D3A, (unsigned short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX0_ACSI_SET_BUF_INFO(v1, v2)
#endif
#define EL1D_TRC_RX0_ACSI_SET_BUF_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6D3A, (unsigned short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_ACSI_SET_BUF_MAIN(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6E3A, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_ACSI_SET_BUF_MAIN(v1, v2)
#endif
#define EL1D_TRC_RX0_ACSI_SET_BUF_MAIN_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6E3A, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_SCC_ACTING_PSEUDO_PCSI() do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_SCC_ACTING_PSEUDO_PCSI()
#endif
#define EL1D_TRC_RX0_SCC_ACTING_PSEUDO_PCSI_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCI0_VALID_CHECK(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x703A, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCI0_VALID_CHECK(v1, v2)
#endif
#define EL1D_TRC_RX0_DCI0_VALID_CHECK_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x703A, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PCSI_ACSI_COLLISION() do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x713A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PCSI_ACSI_COLLISION()
#endif
#define EL1D_TRC_RX0_PCSI_ACSI_COLLISION_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x713A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CSI_HO_CONFIG(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x723A, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CSI_HO_CONFIG(v1)
#endif
#define EL1D_TRC_RX0_CSI_HO_CONFIG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x723A, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CSI_FLAG_BAD_CONDITION(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x733A, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CSI_FLAG_BAD_CONDITION(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_CSI_FLAG_BAD_CONDITION_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x733A, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CSI_FORCE_CQI(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x743A, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CSI_FORCE_CQI(v1, v2)
#endif
#define EL1D_TRC_RX0_CSI_FORCE_CQI_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x743A, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_CSI_OOS_INFO(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x753A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_CSI_OOS_INFO(v1)
#endif
#define EL1D_TRC_RX1_CSI_OOS_INFO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x753A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_FDD_CTRL(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x763A, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_FDD_CTRL(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_NBI_FDD_CTRL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x763A, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_TDT_CTRL(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x773A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_TDT_CTRL(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_NBI_TDT_CTRL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x773A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_FDD_RPT(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x783A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_FDD_RPT(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_NBI_FDD_RPT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x783A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_FDD_PWR_RPT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x793A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_FDD_PWR_RPT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_NBI_FDD_PWR_RPT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_2S(0x793A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_TDT_RPT(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7A3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_TDT_RPT(v1, v2)
#endif
#define EL1D_TRC_RX1_NBI_TDT_RPT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7A3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_TYPE(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7B3A, (short)(v1)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_TYPE(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_TYPE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7B3A, (short)(v1)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_POWER(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_2S(0x7C3A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_POWER(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_POWER_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_11_DATA(TRC_MERGE_2S(0x7C3A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_CORR(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x7D3A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_CORR(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_CORR_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_2S(0x7D3A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_PWR_N(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x7E3A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_PWR_N(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_PWR_N_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x7E3A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_PWR_M(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x7F3A, (short)(v1)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_PWR_M(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_PWR_M_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_7_DATA(TRC_MERGE_2S(0x7F3A, (short)(v1)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_FINE_POS(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x803A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_FINE_POS(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX1_NBI_TDT_CC_RPT_FINE_POS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x803A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_MONITOR_LIST(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x813A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_MONITOR_LIST(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX1_NBI_MONITOR_LIST_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x813A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_NOTCHED_LIST(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x823A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_NOTCHED_LIST(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_NBI_NOTCHED_LIST_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x823A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_FIXED_NBIF_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x833A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_FIXED_NBIF_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_RX1_NBI_FIXED_NBIF_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x833A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_FIXED_NBIF_POSITION(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x843A, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), (unsigned long)(v2), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_FIXED_NBIF_POSITION(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_RX1_NBI_FIXED_NBIF_POSITION_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_10_DATA(TRC_MERGE_2S(0x843A, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), (unsigned long)(v2), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_FIXED_POWER_COMPARE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_2S(0x853A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_FIXED_POWER_COMPARE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_RX1_NBI_FIXED_POWER_COMPARE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_11_DATA(TRC_MERGE_2S(0x853A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_NBIF_INFO(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x863A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_NBIF_INFO(v1, v2)
#endif
#define EL1D_TRC_RX1_NBI_NBIF_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x863A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX1_NBI_NBIF_COEF(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x873A, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_NBIF_COEF(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_RX1_NBI_NBIF_COEF_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x873A, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_RESET_INFO(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x883A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_RESET_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_NBI_RESET_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x883A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_FORCE_NBIF_OFF(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x893A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_FORCE_NBIF_OFF(v1)
#endif
#define EL1D_TRC_RX1_NBI_FORCE_NBIF_OFF_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x893A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_NBI_NOTCH_BW_CHG(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x8A3A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_NBI_NOTCH_BW_CHG(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX1_NBI_NOTCH_BW_CHG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x8A3A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_UPDATE_OC_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8B3A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_UPDATE_OC_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_ICSP_UPDATE_OC_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8B3A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_FORCE_UPDATE(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8C3A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_FORCE_UPDATE(v1)
#endif
#define EL1D_TRC_RX1_ICSP_FORCE_UPDATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8C3A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_CALCULATE_OC_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x8D3A, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), (unsigned char)(v11), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_CALCULATE_OC_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_RX1_ICSP_CALCULATE_OC_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_4_DATA(TRC_MERGE_2S(0x8D3A, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), (unsigned char)(v11), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_CALCULATE_OC_LIST(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8E3A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_CALCULATE_OC_LIST(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_ICSP_CALCULATE_OC_LIST_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8E3A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_CALCULATE_IC_LIST(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8F3A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_CALCULATE_IC_LIST(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_ICSP_CALCULATE_IC_LIST_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8F3A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_CALCULATE_IC_LIST1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x903A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_CALCULATE_IC_LIST1(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_ICSP_CALCULATE_IC_LIST1_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x903A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_CALCULATE_SP_LIST(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x913A, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_CALCULATE_SP_LIST(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RX1_ICSP_CALCULATE_SP_LIST_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_5_DATA(TRC_MERGE_2S(0x913A, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_OC_MIB_SCHEDULE(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x923A, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_OC_MIB_SCHEDULE(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_ICSP_OC_MIB_SCHEDULE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x923A, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_OC_INFO_CHECK(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x933A, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_2S((unsigned short)(v6), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v7), (unsigned char)(v11), (unsigned char)(v12)), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_OC_INFO_CHECK(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define EL1D_TRC_RX1_ICSP_OC_INFO_CHECK_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_6_DATA(TRC_MERGE_2S(0x933A, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_2S((unsigned short)(v6), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v7), (unsigned char)(v11), (unsigned char)(v12)), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_SC_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x943A, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_SC_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_ICSP_SC_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x943A, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_SC_RSRP_Info(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x953A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_SC_RSRP_Info(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX1_ICSP_SC_RSRP_Info_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x953A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_OC_RSRP_Info(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x963A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_OC_RSRP_Info(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX1_ICSP_OC_RSRP_Info_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x963A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_IC_THRD_INFO(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x973A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_IC_THRD_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_ICSP_IC_THRD_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x973A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_MISC_INFO(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x983A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_MISC_INFO(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX1_ICSP_MISC_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x983A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_CMD(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x993A, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_CMD(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_ICSP_CMD_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x993A, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_PBCH_IC_INFO0(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9A3A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_PBCH_IC_INFO0(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_ICSP_PBCH_IC_INFO0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9A3A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_PBCH_IC_INFO1(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9B3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_PBCH_IC_INFO1(v1)
#endif
#define EL1D_TRC_RX1_ICSP_PBCH_IC_INFO1_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9B3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_HO_INFO(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9C3A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_HO_INFO(v1)
#endif
#define EL1D_TRC_RX1_ICSP_HO_INFO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9C3A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_PHASE1_INFO(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9D3A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_PHASE1_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_ICSP_PHASE1_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9D3A, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_OC_EXIST_FLAG(v1, v2, v3) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9E3A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_OC_EXIST_FLAG(v1, v2, v3)
#endif
#define EL1D_TRC_RX1_ICSP_OC_EXIST_FLAG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9E3A, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_OC_DVFS1(v1, v2) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9F3A, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_OC_DVFS1(v1, v2)
#endif
#define EL1D_TRC_RX1_ICSP_OC_DVFS1_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9F3A, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_OC_DVFS2(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA03A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_OC_DVFS2(v1)
#endif
#define EL1D_TRC_RX1_ICSP_OC_DVFS2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA03A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_OC_DVFS3(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA13A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_OC_DVFS3(v1)
#endif
#define EL1D_TRC_RX1_ICSP_OC_DVFS3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA13A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_ICSP_OC_DVFS4() do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA23A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_ICSP_OC_DVFS4()
#endif
#define EL1D_TRC_RX1_ICSP_OC_DVFS4_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA23A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_DCTG_INFO0(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0xA33A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_DCTG_INFO0(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_DCTG_INFO0_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0xA33A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_DCTG_INFO1(v1, v2, v3, v4) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0xA43A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX1_DCTG_INFO1(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX1_DCTG_INFO1_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0xA43A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_DCTG_INFO2(v1) do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xA53A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX1_DCTG_INFO2(v1)
#endif
#define EL1D_TRC_RX1_DCTG_INFO2_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xA53A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX1_DCTG_INFO3() do {\
		if(EL1D_RX1_Trace_Filter[0]==1 && (EL1D_RX1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA63A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX1_DCTG_INFO3()
#endif
#define EL1D_TRC_RX1_DCTG_INFO3_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA63A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_RX1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_RX1_HW_SET_DDR_EN_RXBRP_UNMASK_H(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX1_RFCC_PRE_SYNC_LAST_SYMBOL_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX1_RFCC_OFF_TO_ON_H(unsigned char v1, unsigned short v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RX1_RFCC_ON_TO_OFF_H(unsigned char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX1_RF_SF_LOW_POWER_CMD_M(unsigned char v1, unsigned short v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RX1_TDB_OFF_TO_ON_H(unsigned short v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX1_TDB_ON_TO_OFF_H(unsigned short v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX1_AGC_SET_REQUEST_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX1_AGC_CLEAR_REQUEST_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX1_AGC_SF_CONFIG_M(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX1_AFC_PROC_INFO(unsigned char v1, char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RX1_AFC_FOM_TX(unsigned char v1, unsigned short v2, long v3, long v4, short v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_FOM_RX(char v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_FOM_C_TX(unsigned char v1, unsigned short v2, long v3, long v4, short v5, long v6, long v7);
void L1TRC_Send_EL1D_TRC_RX1_AFC_FOM_C_RX(char v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_EL1D_TRC_RX1_AFC_PERIODIC(short v1, short v2, short v3, long v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_RX1_AFC_CS_BIN_TO_DAC(short v1, short v2, long v3, short v4);
void L1TRC_Send_EL1D_TRC_RX1_AFC_CELL_SWITCH(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, long v5, long v6, long v7, char v8);
void L1TRC_Send_EL1D_TRC_RX1_AFC_RELOAD_MBMS(char v1, unsigned char v2, long v3, long v4, char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_RX1_AFC_RELOAD_C_MBMS(char v1, unsigned char v2, long v3, long v4, long v5, long v6, char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_EL1D_TRC_RX1_AFC_RXNCO_CSCM(char v1, short v2, long v3, long v4, char v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_SAVE_TRUST_DAC(unsigned char v1, short v2, long v3);
void L1TRC_Send_EL1D_TRC_RX1_AFC_OTHER_RAT(char v1, char v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_RX1_AFC_OTHER_RAT_DAC_ABNORMAL_H(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_SWAP_DAC(unsigned short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_RX1_AFC_RST(short v1);
void L1TRC_Send_EL1D_TRC_RX1_AFC_RST_BEFORE_ICS(short v1);
void L1TRC_Send_EL1D_TRC_RX1_AFC_DAC_FORCE(char v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_RX1_AFC_LRST(short v1);
void L1TRC_Send_EL1D_TRC_RX1_AFC_COCLK_LRST(long v1);
void L1TRC_Send_EL1D_TRC_RX1_AFC_SET_SYN_ON(char v1, unsigned char v2, unsigned char v3, char v4);
void L1TRC_Send_EL1D_TRC_RX1_AFC_SET_RX_SYN_PARAM(char v1, unsigned short v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_EL1D_TRC_RX1_AFC_SET_TX_SYN_PARAM(unsigned short v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_RX1_AFC_SET_SYN_OTF(char v1, unsigned char v2, unsigned char v3, char v4, long v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_REQ_TX_ON_IN_NBR(void);
void L1TRC_Send_EL1D_TRC_RX1_AFC_ENTER_NONRX_INTER_FREQ_WIN(char v1);
void L1TRC_Send_EL1D_TRC_RX1_AFC_DSP_PROC_INFO(char v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX1_AFC_DSP_CMD(unsigned long v1, char v2, char v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_EL1D_TRC_RX1_AFC_DSP_CMD_SCELL(unsigned long v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_UL_TXNCO(short v1, long v2);
void L1TRC_Send_EL1D_TRC_RX1_AFC_UL_RR(long v1, long v2, char v3);
void L1TRC_Send_EL1D_TRC_RX1_AFC_DL_RR(long v1, long v2);
void L1TRC_Send_EL1D_TRC_RX1_AFC_OC_SNR(char v1, unsigned char v2, long v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX1_AFC_HANDLE_OC_RPT(char v1, unsigned char v2, long v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RX1_AFC_HANDLE_MBMS_RPT(char v1, unsigned char v2, unsigned char v3, long v4, long v5, char v6);
void L1TRC_Send_EL1D_TRC_RX1_AFC_PREPARE_TX_SYN_SET(char v1, unsigned short v2, unsigned short v3, char v4);
void L1TRC_Send_EL1D_TRC_RX1_AFC_HST_FOE_DIFF(unsigned long v1, char v2, long v3, unsigned char v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_HST_SCH(char v1, unsigned char v2, long v3);
void L1TRC_Send_EL1D_TRC_RX1_AFC_READ_AUXADC_LATEST(short v1);
void L1TRC_Send_EL1D_TRC_RX1_AFC_STATUS_NOT_RDY_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX1_AFC_DIFF_FROM_RF_FREQ_H(char v1, unsigned short v2, unsigned short v3, unsigned char v4, char v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TEMPER_NO_UPD(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RX1_AFC_DBG(long v1, unsigned char v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_ACCUM(long v1, long v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_OTF(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_OTF_TBL(long v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_OTF_VMAP(long v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_TFC(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_TFC_2(long v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_TFC_TBL(long v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_ICL(long v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_FREQERR_CALC(long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_SCHEDULE(long v1, long v2, long v3, long v4, long v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_UFPAIR_COLLECT(long v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_MAIN_TIMESTAMP(unsigned char v1, long v2);
void L1TRC_Send_EL1D_TRC_RX1_AFC_TMS_USE_RAT(char v1);
void L1TRC_Send_EL1D_TRC_RX1_AFC_HST_FORCE_MD_INFO(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX1_FWS_RPT_ACCU_SYMCNT(char v1, short v2, short v3, char v4);
void L1TRC_Send_EL1D_TRC_RX1_FWS_RPT_SYM_OFST(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_RX1_FWS_RPT_GIC(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RX1_FWS_RPT_COMB_1(unsigned char v1, unsigned char v2, long v3, long v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_EL1D_TRC_RX1_FWS_FBD_ADJUST(char v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_RX1_FWS_ACCU_ERR(char v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_RX1_FWS_CRS_RLT(short v1, unsigned short v2, unsigned short v3, short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_EL1D_TRC_RX1_FWS_MRS_RLT(short v1, unsigned short v2, unsigned short v3, short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_EL1D_TRC_RX1_FWS_1ST_RLT(short v1, unsigned short v2, unsigned short v3, short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_EL1D_TRC_RX1_FWS_SYM_RST(char v1);
void L1TRC_Send_EL1D_TRC_RX1_FWS_ASSERT_TRC_0(unsigned short v1, unsigned short v2, long v3, unsigned short v4, long v5);
void L1TRC_Send_EL1D_TRC_RX1_FWS_2CC_BOUND(char v1);
void L1TRC_Send_EL1D_TRC_RX1_FWS_DELAY_RPT(unsigned long v1, char v2);
void L1TRC_Send_EL1D_TRC_RX1_CSI_RPT_MODE(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX1_CSI_DSP_RPT(char v1, char v2, char v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_EL1D_TRC_RX1_CSI_TX_INFO(char v1, char v2, unsigned char v3, short v4, char v5, unsigned char v6, char v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1D_TRC_RX1_PCSI_PRIORITY_DET(char v1, short v2, char v3, short v4, char v5);
void L1TRC_Send_EL1D_TRC_RX1_PCSI_EVENT(char v1, char v2, short v3, char v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX1_PCSI_ACSI_COLLISION(void);
void L1TRC_Send_EL1D_TRC_RX1_PCSI_TX(short v1, char v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX1_ACSI_DCI0_DET_ERROR(short v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX1_ACSI_DCI0_DET_VLD(short v1, short v2, char v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX1_ACSI_DCI0_DET_BUF(char v1, char v2, char v3, short v4, char v5, unsigned long v6, char v7);
void L1TRC_Send_EL1D_TRC_RX1_ACSI_DCI0_LISR(char v1, char v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_RX1_ACSI_DCI0_EVENT(unsigned char v1, short v2, char v3, char v4, char v5, short v6, char v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_RX1_ACSI_DCI0_TX(short v1, char v2, char v3, char v4, short v5, char v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_RX1_ACSI_RAR_TRIGGER(void);
void L1TRC_Send_EL1D_TRC_RX1_ACSI_RAR_EVENT(char v1, char v2, char v3, short v4, char v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RX1_ACSI_RAR_TX(char v1, short v2, char v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX1_CSI_OCCUPY_FREE_SET(unsigned char v1, char v2, unsigned char v3, char v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RX1_CSI_OCCUPY_BUSY_SET(unsigned char v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX1_CSI_INFO_BUF_SET(char v1);
void L1TRC_Send_EL1D_TRC_RX1_CSI_TICK_SET(char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_RX1_CSI_ONLY(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_RX1_CSI_DROP_ACSI(void);
void L1TRC_Send_EL1D_TRC_RX0_ACSI_TXINFO_BY_L1C(unsigned char v1, unsigned char v2, unsigned char v3, char v4, unsigned long v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX0_ACSI_PMI_CMD(char v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX0_ACSI_PMI_CTRL_LISR_UPDATE(char v1, short v2, unsigned long v3, unsigned char v4, unsigned long v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_RX0_ACSI_PMI_SEARCH_LATEST(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX0_ACSI_PMI_CTRL_UPDATE(char v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_RX0_ACSI_FAST_DETECTED_DCI0(void);
void L1TRC_Send_EL1D_TRC_RX0_ACSI_FAST_DETECTED_INVLD_DCI0(void);
void L1TRC_Send_EL1D_TRC_RX0_ACSI_SET_BUF_INFO(unsigned short v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX0_ACSI_SET_BUF_MAIN(char v1, char v2);
void L1TRC_Send_EL1D_TRC_RX0_SCC_ACTING_PSEUDO_PCSI(void);
void L1TRC_Send_EL1D_TRC_RX0_DCI0_VALID_CHECK(char v1, char v2);
void L1TRC_Send_EL1D_TRC_RX0_PCSI_ACSI_COLLISION(void);
void L1TRC_Send_EL1D_TRC_RX0_CSI_HO_CONFIG(unsigned short v1);
void L1TRC_Send_EL1D_TRC_RX0_CSI_FLAG_BAD_CONDITION(char v1, char v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_RX0_CSI_FORCE_CQI(char v1, char v2);
void L1TRC_Send_EL1D_TRC_RX1_CSI_OOS_INFO(char v1);
void L1TRC_Send_EL1D_TRC_RX1_NBI_FDD_CTRL(short v1, char v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_RX1_NBI_TDT_CTRL(short v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX1_NBI_FDD_RPT(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_RX1_NBI_FDD_PWR_RPT(short v1, short v2, short v3, short v4, unsigned long v5, long v6, long v7);
void L1TRC_Send_EL1D_TRC_RX1_NBI_TDT_RPT(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX1_NBI_TDT_CC_RPT_TYPE(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_EL1D_TRC_RX1_NBI_TDT_CC_RPT_POWER(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11);
void L1TRC_Send_EL1D_TRC_RX1_NBI_TDT_CC_RPT_CORR(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1D_TRC_RX1_NBI_TDT_CC_RPT_PWR_N(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_RX1_NBI_TDT_CC_RPT_PWR_M(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_EL1D_TRC_RX1_NBI_TDT_CC_RPT_FINE_POS(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_RX1_NBI_MONITOR_LIST(short v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_RX1_NBI_NOTCHED_LIST(short v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX1_NBI_FIXED_NBIF_INFO(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_EL1D_TRC_RX1_NBI_FIXED_NBIF_POSITION(short v1, unsigned long v2, short v3, short v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11);
void L1TRC_Send_EL1D_TRC_RX1_NBI_FIXED_POWER_COMPARE(short v1, unsigned long v2, unsigned long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11);
void L1TRC_Send_EL1D_TRC_RX1_NBI_NBIF_INFO(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX1_NBI_NBIF_COEF(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11);
void L1TRC_Send_EL1D_TRC_RX1_NBI_RESET_INFO(short v1, short v2, short v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX1_NBI_FORCE_NBIF_OFF(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RX1_NBI_NOTCH_BW_CHG(short v1, short v2, long v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_UPDATE_OC_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_FORCE_UPDATE(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_CALCULATE_OC_INFO(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_CALCULATE_OC_LIST(char v1, unsigned char v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_CALCULATE_IC_LIST(char v1, char v2, char v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_CALCULATE_IC_LIST1(char v1, unsigned char v2, char v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_CALCULATE_SP_LIST(char v1, char v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_OC_MIB_SCHEDULE(char v1, char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_OC_INFO_CHECK(unsigned short v1, unsigned char v2, unsigned short v3, short v4, long v5, unsigned short v6, unsigned char v7, short v8, short v9, short v10, unsigned char v11, unsigned char v12);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_SC_INFO(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_SC_RSRP_Info(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_OC_RSRP_Info(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_IC_THRD_INFO(unsigned char v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_MISC_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_CMD(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_PBCH_IC_INFO0(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_PBCH_IC_INFO1(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_HO_INFO(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_PHASE1_INFO(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_OC_EXIST_FLAG(char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_OC_DVFS1(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_OC_DVFS2(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_OC_DVFS3(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX1_ICSP_OC_DVFS4(void);
void L1TRC_Send_EL1D_TRC_RX1_DCTG_INFO0(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX1_DCTG_INFO1(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX1_DCTG_INFO2(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RX1_DCTG_INFO3(void);

void Set_EL1D_RX1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_RX1()	(EL1D_RX1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_HW_H()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_HW_M()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_HW_L()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_RF_H()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_RF_M()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_RF_L()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_TDB_H()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_TDB_M()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_TDB_L()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AGC_H()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AGC_M()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AGC_L()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_M()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_L()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_H()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_M()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_L()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_M()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_L()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_M()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_L()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_M()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_L()	(ChkL1ModFltr_EL1D_RX1()&&((EL1D_RX1_Trace_Filter[4]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_RX1_HW_SET_DDR_EN_RXBRP_UNMASK_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_HW_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_RFCC_PRE_SYNC_LAST_SYMBOL_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_RFCC_OFF_TO_ON_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_RFCC_ON_TO_OFF_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_RF_SF_LOW_POWER_CMD_M()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_TDB_OFF_TO_ON_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_TDB_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_TDB_ON_TO_OFF_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_TDB_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AGC_SET_REQUEST_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AGC_CLEAR_REQUEST_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AGC_SF_CONFIG_M()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AGC_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_PROC_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_FOM_TX()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_FOM_RX()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_FOM_C_TX()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_FOM_C_RX()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_PERIODIC()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_CS_BIN_TO_DAC()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_CELL_SWITCH()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_RELOAD_MBMS()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_RELOAD_C_MBMS()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_RXNCO_CSCM()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_SAVE_TRUST_DAC()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_M()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_OTHER_RAT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_OTHER_RAT_DAC_ABNORMAL_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_SWAP_DAC()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_RST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_RST_BEFORE_ICS()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_DAC_FORCE()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_LRST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_COCLK_LRST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_SET_SYN_ON()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_M()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_SET_RX_SYN_PARAM()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_SET_TX_SYN_PARAM()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_SET_SYN_OTF()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_REQ_TX_ON_IN_NBR()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_ENTER_NONRX_INTER_FREQ_WIN()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_DSP_PROC_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_DSP_CMD()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_DSP_CMD_SCELL()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_UL_TXNCO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_UL_RR()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_DL_RR()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_M()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_OC_SNR()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_HANDLE_OC_RPT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_HANDLE_MBMS_RPT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_PREPARE_TX_SYN_SET()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_HST_FOE_DIFF()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_HST_SCH()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_READ_AUXADC_LATEST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_STATUS_NOT_RDY_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_DIFF_FROM_RF_FREQ_H()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TEMPER_NO_UPD()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_DBG()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_ACCUM()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_OTF()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_OTF_TBL()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_OTF_VMAP()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_TFC()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_TFC_2()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_TFC_TBL()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_ICL()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_FREQERR_CALC()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_SCHEDULE()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_UFPAIR_COLLECT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_MAIN_TIMESTAMP()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_TMS_USE_RAT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_AFC_HST_FORCE_MD_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_AFC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_RPT_ACCU_SYMCNT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_RPT_SYM_OFST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_RPT_GIC()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_RPT_COMB_1()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_FBD_ADJUST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_ACCU_ERR()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_CRS_RLT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_MRS_RLT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_1ST_RLT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_SYM_RST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_ASSERT_TRC_0()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_2CC_BOUND()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_FWS_DELAY_RPT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_FWS_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_CSI_RPT_MODE()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_CSI_DSP_RPT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_CSI_TX_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_PCSI_PRIORITY_DET()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_PCSI_EVENT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_PCSI_ACSI_COLLISION()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_PCSI_TX()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ACSI_DCI0_DET_ERROR()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ACSI_DCI0_DET_VLD()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ACSI_DCI0_DET_BUF()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ACSI_DCI0_LISR()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ACSI_DCI0_EVENT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ACSI_DCI0_TX()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ACSI_RAR_TRIGGER()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ACSI_RAR_EVENT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ACSI_RAR_TX()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_CSI_OCCUPY_FREE_SET()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_CSI_OCCUPY_BUSY_SET()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_CSI_INFO_BUF_SET()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_CSI_TICK_SET()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_CSI_ONLY()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_CSI_DROP_ACSI()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_ACSI_TXINFO_BY_L1C()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_ACSI_PMI_CMD()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_ACSI_PMI_CTRL_LISR_UPDATE()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_ACSI_PMI_SEARCH_LATEST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_ACSI_PMI_CTRL_UPDATE()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_ACSI_FAST_DETECTED_DCI0()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_ACSI_FAST_DETECTED_INVLD_DCI0()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_ACSI_SET_BUF_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_ACSI_SET_BUF_MAIN()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_SCC_ACTING_PSEUDO_PCSI()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCI0_VALID_CHECK()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PCSI_ACSI_COLLISION()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CSI_HO_CONFIG()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CSI_FLAG_BAD_CONDITION()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CSI_FORCE_CQI()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_CSI_OOS_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_CSI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_FDD_CTRL()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_TDT_CTRL()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_FDD_RPT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_FDD_PWR_RPT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_TDT_RPT()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_TDT_CC_RPT_TYPE()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_TDT_CC_RPT_POWER()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_TDT_CC_RPT_CORR()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_TDT_CC_RPT_PWR_N()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_TDT_CC_RPT_PWR_M()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_TDT_CC_RPT_FINE_POS()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_MONITOR_LIST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_NOTCHED_LIST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_FIXED_NBIF_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_FIXED_NBIF_POSITION()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_FIXED_POWER_COMPARE()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_NBIF_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_NBIF_COEF()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_L()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_RESET_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_FORCE_NBIF_OFF()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_NBI_NOTCH_BW_CHG()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_NBI_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_UPDATE_OC_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_FORCE_UPDATE()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_CALCULATE_OC_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_CALCULATE_OC_LIST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_CALCULATE_IC_LIST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_CALCULATE_IC_LIST1()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_CALCULATE_SP_LIST()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_OC_MIB_SCHEDULE()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_OC_INFO_CHECK()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_SC_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_SC_RSRP_Info()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_OC_RSRP_Info()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_IC_THRD_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_MISC_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_CMD()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_PBCH_IC_INFO0()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_PBCH_IC_INFO1()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_HO_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_PHASE1_INFO()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_OC_EXIST_FLAG()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_OC_DVFS1()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_OC_DVFS2()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_OC_DVFS3()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_ICSP_OC_DVFS4()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_DCTG_INFO0()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_DCTG_INFO1()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_DCTG_INFO2()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()
#define ChkL1MsgFltr_EL1D_TRC_RX1_DCTG_INFO3()	ChkL1ClsFltr_EL1D_RX1_EL1D_TRC_RX1_ICSP_H()


#endif
