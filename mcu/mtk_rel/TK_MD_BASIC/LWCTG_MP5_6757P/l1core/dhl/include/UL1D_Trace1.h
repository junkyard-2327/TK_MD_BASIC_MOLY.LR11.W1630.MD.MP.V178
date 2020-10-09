#ifndef L1TRC_UL1D_SEC_DEF_H
#define L1TRC_UL1D_SEC_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_STATE_MACHINE(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_UL_DCH_STATE(v1)  (unsigned char)(v1+6)
#define UL1D_TRC_STR_DL_DCH_STATE(v1)  (unsigned char)(v1+10)
#define UL1D_TRC_STR_FACH_STATE(v1)  (unsigned char)(v1+17)
#define UL1D_TRC_STR_PCH_STATE(v1)  (unsigned char)(v1+20)
#define UL1D_TRC_STR_PCH_MODE(v1)  (unsigned char)(v1+24)
#define UL1D_TRC_STR_BCH_STATE(v1)  (unsigned char)(v1+28)
#define UL1D_TRC_STR_SFN_STATE(v1)  (unsigned char)(v1+33)
#define UL1D_TRC_STR_RACH_STATE(v1)  (unsigned char)(v1+41)
#define UL1D_TRC_STR_RXBRP_STATE(v1)  (unsigned char)(v1+48)
#define UL1D_TRC_STR_SFN_DECISION_METHOD(v1)  (unsigned char)(v1+51)
#define UL1D_TRC_STR_AICH_RESULT(v1)  (unsigned char)(v1+55)
#define UL1D_TRC_STR_EVAL_LIST(v1)  (unsigned char)(v1+59)
#define UL1D_TRC_STR_DPC_RECONFIG_FLAG(v1)  (unsigned char)(v1+62)
#define UL1D_TRC_STR_RACH_ACCESS_STATUS(v1)  (unsigned char)(v1+67)
#define UL1D_TRC_STR_32K_LESS_TIMING_ERROR_STATUS(v1)  (unsigned char)(v1+73)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1D_TRC_STATE_MACHINE(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x001C, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_STATE_MACHINE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_STATE_MACHINE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x001C, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PICH_STATE_MACHINE(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x011C, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PICH_STATE_MACHINE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PICH_STATE_MACHINE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x011C, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FORCE_NORMAL_DUMMY_TIMER(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x021C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FORCE_NORMAL_DUMMY_TIMER(v1)
#endif
#define UL1D_TRC_FORCE_NORMAL_DUMMY_TIMER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x021C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PICH_TM_ERROR(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x031C, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PICH_TM_ERROR(v1, v2, v3)
#endif
#define UL1D_TRC_PICH_TM_ERROR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x031C, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PICH_TM_ADJ(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x041C, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_PICH_TM_ADJ(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_PICH_TM_ADJ_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x041C, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PICH_LST_FN(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x051C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_PICH_LST_FN(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_PICH_LST_FN_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x051C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCH_TM_INFO(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x061C, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_PCH_TM_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PCH_TM_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x061C, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PICH_SRCHR_INTR_CFG_DBG(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x071C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PICH_SRCHR_INTR_CFG_DBG(v1, v2, v3)
#endif
#define UL1D_TRC_PICH_SRCHR_INTR_CFG_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x071C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PICH_SRCHR_INTR_CHK_DBG(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x081C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PICH_SRCHR_INTR_CHK_DBG(v1, v2, v3)
#endif
#define UL1D_TRC_PICH_SRCHR_INTR_CHK_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x081C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXBRP_STATE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x091C, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXBRP_STATE(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_RXBRP_STATE_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x091C, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_UL_TGPS_INFO(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A1C, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UL_TGPS_INFO(v1, v2, v3)
#endif
#define UL1D_TRC_UL_TGPS_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A1C, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_TGPS_INFO(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B1C, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_DL_TGPS_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DL_TGPS_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B1C, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RACH_PREAMBLE_PARAMETERS(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C1C, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_RACH_PREAMBLE_PARAMETERS(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RACH_PREAMBLE_PARAMETERS_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C1C, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RACH_INIT_POWER_PARAM(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D1C, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RACH_INIT_POWER_PARAM(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RACH_INIT_POWER_PARAM_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D1C, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RACH_PREAMBLE_TRANSMIT(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RACH_PREAMBLE_TRANSMIT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RACH_PREAMBLE_TRANSMIT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RACH_SEND_REPORT(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F1C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RACH_SEND_REPORT(v1)
#endif
#define UL1D_TRC_RACH_SEND_REPORT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F1C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_AICH_DEBUG(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x101C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_AICH_DEBUG(v1, v2, v3)
#endif
#define UL1D_TRC_AICH_DEBUG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x101C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_UPDATE_AICH_TH(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x111C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_UPDATE_AICH_TH(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_UPDATE_AICH_TH_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x111C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_AICH_RESULT(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x121C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_AICH_RESULT(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_AICH_RESULT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x121C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_AICH_NO_AI_INT(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x131C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_AICH_NO_AI_INT(v1, v2)
#endif
#define UL1D_TRC_AICH_NO_AI_INT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x131C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FACH_FMO(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x141C, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_FACH_FMO(v1, v2)
#endif
#define UL1D_TRC_FACH_FMO_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x141C, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FACH_SUSPEND_GAP(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x151C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_FACH_SUSPEND_GAP(v1, v2, v3)
#endif
#define UL1D_TRC_FACH_SUSPEND_GAP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x151C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FACH_FAKE_TFCI(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x161C, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_FACH_FAKE_TFCI(v1)
#endif
#define UL1D_TRC_FACH_FAKE_TFCI_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x161C, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FACH_RX_SUSPEND(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x171C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_FACH_RX_SUSPEND(v1, v2, v3)
#endif
#define UL1D_TRC_FACH_RX_SUSPEND_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x171C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FACH_RXCRP_DELAY_START(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x181C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FACH_RXCRP_DELAY_START(v1)
#endif
#define UL1D_TRC_FACH_RXCRP_DELAY_START_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x181C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FACH_START_FOR_DEDICATED_FACH() do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x191C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FACH_START_FOR_DEDICATED_FACH()
#endif
#define UL1D_TRC_FACH_START_FOR_DEDICATED_FACH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x191C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FACH_SET_RPT_FOR_DEDICATED_FACH() do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FACH_SET_RPT_FOR_DEDICATED_FACH()
#endif
#define UL1D_TRC_FACH_SET_RPT_FOR_DEDICATED_FACH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FACH_PCH_STATE_TRCH_NUM(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B1C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FACH_PCH_STATE_TRCH_NUM(v1, v2)
#endif
#define UL1D_TRC_FACH_PCH_STATE_TRCH_NUM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B1C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SFN_START(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_SFN_START(v1)
#endif
#define UL1D_TRC_SFN_START_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SFN_DETECTED(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D1C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SFN_DETECTED(v1)
#endif
#define UL1D_TRC_SFN_DETECTED_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D1C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SFN_TRY_CNT(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E1C, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_SFN_TRY_CNT(v1)
#endif
#define UL1D_TRC_SFN_TRY_CNT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E1C, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SFN_REPORT_RESULT(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1F1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_SFN_REPORT_RESULT(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_SFN_REPORT_RESULT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1F1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_BCH_START_PARAM(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x201C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_BCH_START_PARAM(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_BCH_START_PARAM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x201C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_BCH_MPS_TRIGGER(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x211C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_BCH_MPS_TRIGGER(v1)
#endif
#define UL1D_TRC_BCH_MPS_TRIGGER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x211C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_BCH_STATE_INFO(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x221C, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_BCH_STATE_INFO(v1, v2)
#endif
#define UL1D_TRC_BCH_STATE_INFO_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x221C, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CMB_EN(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x231C, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CMB_EN(v1, v2, v3)
#endif
#define UL1D_TRC_CMB_EN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x231C, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CODEGEN_RL0(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x241C, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_CODEGEN_RL0(v1)
#endif
#define UL1D_TRC_CODEGEN_RL0_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x241C, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXBRP_TF(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x251C, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXBRP_TF(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_TXBRP_TF_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x251C, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXBRP_ACTIVE_TRCH(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x261C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_TXBRP_ACTIVE_TRCH(v1)
#endif
#define UL1D_TRC_TXBRP_ACTIVE_TRCH_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x261C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXBRP_START_TIME(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x271C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXBRP_START_TIME(v1, v2, v3)
#endif
#define UL1D_TRC_TXBRP_START_TIME_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x271C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXBRP_DONE_TIME(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x281C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXBRP_DONE_TIME(v1, v2, v3)
#endif
#define UL1D_TRC_TXBRP_DONE_TIME_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x281C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXBRP_ENC_TIME(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x291C, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_TXBRP_ENC_TIME(v1)
#endif
#define UL1D_TRC_TXBRP_ENC_TIME_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x291C, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CHEST_SPEED(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A1C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CHEST_SPEED(v1)
#endif
#define UL1D_TRC_CHEST_SPEED_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A1C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCH_SET_RXD_FORCE_NORMAL(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B1C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PCH_SET_RXD_FORCE_NORMAL(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PCH_SET_RXD_FORCE_NORMAL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B1C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PCH_SET_CSFB(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C1C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PCH_SET_CSFB(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PCH_SET_CSFB_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C1C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SRCHR_PI_WAKEUP_STATUS(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D1C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SRCHR_PI_WAKEUP_STATUS(v1)
#endif
#define UL1D_TRC_SRCHR_PI_WAKEUP_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D1C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SRCHR_PI_FOE_RESULT(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SRCHR_PI_FOE_RESULT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_SRCHR_PI_FOE_RESULT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PICH_RESULT(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F1C, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PICH_RESULT(v1, v2, v3)
#endif
#define UL1D_TRC_PICH_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F1C, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SRCHR_PICH_RESULT(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x301C, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_SRCHR_PICH_RESULT(v1, v2, v3)
#endif
#define UL1D_TRC_SRCHR_PICH_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x301C, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SRCHR_PICH_TRACKER_THR(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x311C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SRCHR_PICH_TRACKER_THR(v1)
#endif
#define UL1D_TRC_SRCHR_PICH_TRACKER_THR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x311C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PICH_SKIP_BY_UL1D(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x321C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PICH_SKIP_BY_UL1D(v1)
#endif
#define UL1D_TRC_PICH_SKIP_BY_UL1D_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x321C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PICH_SKIP(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x331C, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_PICH_SKIP(v1)
#endif
#define UL1D_TRC_PICH_SKIP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x331C, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PICH_PI_POSITION(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x341C, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_PICH_PI_POSITION(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_PICH_PI_POSITION_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x341C, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SRCHR_PI_DECODE(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x351C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_SRCHR_PI_DECODE(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_SRCHR_PI_DECODE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x351C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SRCHR_PI_SCHEDULE(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x361C, (short)(v1)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_SRCHR_PI_SCHEDULE(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_SRCHR_PI_SCHEDULE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x361C, (short)(v1)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_OFFLINE_PCH_DCXO_DD(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x371C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_OFFLINE_PCH_DCXO_DD(v1, v2)
#endif
#define UL1D_TRC_OFFLINE_PCH_DCXO_DD_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x371C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_OFFLINE_PCH_DBG(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x381C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_OFFLINE_PCH_DBG(v1, v2, v3)
#endif
#define UL1D_TRC_OFFLINE_PCH_DBG_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x381C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_OFFLINE_PCH_SET(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x391C, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_OFFLINE_PCH_SET(v1)
#endif
#define UL1D_TRC_OFFLINE_PCH_SET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x391C, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_TFCI_STATE(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A1C, (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_TFCI_STATE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_TFCI_STATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A1C, (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DMA_DONE(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B1C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DMA_DONE(v1, v2)
#endif
#define UL1D_TRC_DMA_DONE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B1C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CMB_ICHCON(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3C1C, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_CMB_ICHCON(v1)
#endif
#define UL1D_TRC_CMB_ICHCON_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3C1C, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_SPEST_STA(v1, v2, v3) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3D1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SPEST_STA(v1, v2, v3)
#endif
#define UL1D_TRC_SPEST_STA_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3D1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_SPEST_RESULT(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E1C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SPEST_RESULT(v1)
#endif
#define UL1D_TRC_SPEST_RESULT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E1C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXBRP_TFCI_OUT_OF_RANGE(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3F1C, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_RXBRP_TFCI_OUT_OF_RANGE(v1)
#endif
#define UL1D_TRC_RXBRP_TFCI_OUT_OF_RANGE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3F1C, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HWTPC_WTXUPC_ASPOW(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x401C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_WTXUPC_ASPOW(v1)
#endif
#define UL1D_TRC_HWTPC_WTXUPC_ASPOW_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x401C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HWTPC_SLOTMASK(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x411C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_SLOTMASK(v1, v2)
#endif
#define UL1D_TRC_HWTPC_SLOTMASK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x411C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HWTPC_SLOT_FORMAT(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x421C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_SLOT_FORMAT(v1, v2)
#endif
#define UL1D_TRC_HWTPC_SLOT_FORMAT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x421C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HWTPC_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x431C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define UL1D_TRC_HWTPC_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_8_DATA(TRC_MERGE_2S(0x431C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HWTPC_DBG(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x441C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HWTPC_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x441C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HWTPC_PWR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x451C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), (char)(v10)), TRC_MERGE_4C((char)(v11), (char)(v12), (char)(v13), (char)(v14)), TRC_MERGE_4C((char)(v15), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_PWR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define UL1D_TRC_HWTPC_PWR_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x451C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), (char)(v10)), TRC_MERGE_4C((char)(v11), (char)(v12), (char)(v13), (char)(v14)), TRC_MERGE_4C((char)(v15), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HWTPC_PWR_RF(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x461C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), (char)(v10)), TRC_MERGE_4C((char)(v11), (char)(v12), (char)(v13), (char)(v14)), TRC_MERGE_4C((char)(v15), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_PWR_RF(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define UL1D_TRC_HWTPC_PWR_RF_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x461C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), (char)(v10)), TRC_MERGE_4C((char)(v11), (char)(v12), (char)(v13), (char)(v14)), TRC_MERGE_4C((char)(v15), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HWTPC_PWR_PD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x471C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), (char)(v10)), TRC_MERGE_4C((char)(v11), (char)(v12), (char)(v13), (char)(v14)), TRC_MERGE_4C((char)(v15), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_PWR_PD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define UL1D_TRC_HWTPC_PWR_PD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x471C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), (char)(v10)), TRC_MERGE_4C((char)(v11), (char)(v12), (char)(v13), (char)(v14)), TRC_MERGE_4C((char)(v15), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HWTPC_PWR_MAX_MIN(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x481C, (short)(v6)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_PWR_MAX_MIN(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_HWTPC_PWR_MAX_MIN_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x481C, (short)(v6)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HWTPC_PWR_AP_REP(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x491C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_PWR_AP_REP(v1)
#endif
#define UL1D_TRC_HWTPC_PWR_AP_REP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x491C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HWTPC_CMD(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_CMD(v1)
#endif
#define UL1D_TRC_HWTPC_CMD_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HWTPC_CMD2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x4B1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)));\
	} while(0)
#else
	#define UL1D_TRC_HWTPC_CMD2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define UL1D_TRC_HWTPC_CMD2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_8_DATA(TRC_MERGE_2S(0x4B1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EM_PWR_TX(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4C1C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_EM_PWR_TX(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_EM_PWR_TX_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4C1C, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ACS_START(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D1C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ACS_START(v1)
#endif
#define UL1D_TRC_ACS_START_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D1C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_TIMING_ERROR_ACS(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E1C, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TIMING_ERROR_ACS(v1, v2)
#endif
#define UL1D_TRC_TIMING_ERROR_ACS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E1C, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_32KLESS_TIMING_ERROR_VALID(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F1C, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_32KLESS_TIMING_ERROR_VALID(v1, v2)
#endif
#define UL1D_TRC_32KLESS_TIMING_ERROR_VALID_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F1C, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_32KLESS_TIMING_ERROR(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x501C, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_32KLESS_TIMING_ERROR(v1, v2)
#endif
#define UL1D_TRC_32KLESS_TIMING_ERROR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x501C, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_32KLESS_DIVIDER(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x511C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_32KLESS_DIVIDER(v1)
#endif
#define UL1D_TRC_32KLESS_DIVIDER_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x511C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_32KLESS_FPM_DIVIDER(v1) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x521C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_32KLESS_FPM_DIVIDER(v1)
#endif
#define UL1D_TRC_32KLESS_FPM_DIVIDER_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x521C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SM_FREQ_OFFSET(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x531C, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_SM_FREQ_OFFSET(v1, v2, v3, v4)
#endif
#define UL1D_TRC_SM_FREQ_OFFSET_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x531C, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RFM_CHECK_SINGLE_CELL(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x541C, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_CHECK_SINGLE_CELL(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RFM_CHECK_SINGLE_CELL_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x541C, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RFM_UPDATE_TIMING_FROM_CM(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x551C, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_UPDATE_TIMING_FROM_CM(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RFM_UPDATE_TIMING_FROM_CM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x551C, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RFM_UPDATE_TIMING_TO_MPS(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x561C, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_UPDATE_TIMING_TO_MPS(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RFM_UPDATE_TIMING_TO_MPS_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x561C, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RFM_UPDATE_TIMING_GSR_UPDATE(v1, v2, v3, v4) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x571C, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_UPDATE_TIMING_GSR_UPDATE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RFM_UPDATE_TIMING_GSR_UPDATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x571C, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RFM_UPDATE_TIMING_FNG_DEL(v1, v2) do {\
		if(UL1D_SEC_Trace_Filter[0]==1 && (UL1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x581C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFM_UPDATE_TIMING_FNG_DEL(v1, v2)
#endif
#define UL1D_TRC_RFM_UPDATE_TIMING_FNG_DEL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x581C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_SEC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_STATE_MACHINE(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_PICH_STATE_MACHINE(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_FORCE_NORMAL_DUMMY_TIMER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_PICH_TM_ERROR(unsigned short v1, short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_PICH_TM_ADJ(unsigned short v1, short v2, unsigned char v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_PICH_LST_FN(unsigned short v1, unsigned char v2, unsigned short v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_PCH_TM_INFO(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_PICH_SRCHR_INTR_CFG_DBG(unsigned short v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_PICH_SRCHR_INTR_CHK_DBG(unsigned short v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_RXBRP_STATE(char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1D_TRC_UL_TGPS_INFO(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_DL_TGPS_INFO(unsigned char v1, unsigned short v2, unsigned char v3, short v4);
void L1TRC_Send_UL1D_TRC_RACH_PREAMBLE_PARAMETERS(unsigned char v1, unsigned long v2, unsigned char v3, char v4, char v5);
void L1TRC_Send_UL1D_TRC_RACH_INIT_POWER_PARAM(char v1, char v2, short v3, char v4);
void L1TRC_Send_UL1D_TRC_RACH_PREAMBLE_TRANSMIT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_RACH_SEND_REPORT(unsigned char v1);
void L1TRC_Send_UL1D_TRC_AICH_DEBUG(unsigned short v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_UPDATE_AICH_TH(short v1, short v2, short v3, short v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_AICH_RESULT(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_AICH_NO_AI_INT(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_FACH_FMO(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_FACH_SUSPEND_GAP(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_FACH_FAKE_TFCI(short v1);
void L1TRC_Send_UL1D_TRC_FACH_RX_SUSPEND(unsigned short v1, unsigned short v2, short v3);
void L1TRC_Send_UL1D_TRC_FACH_RXCRP_DELAY_START(char v1);
void L1TRC_Send_UL1D_TRC_FACH_START_FOR_DEDICATED_FACH(void);
void L1TRC_Send_UL1D_TRC_FACH_SET_RPT_FOR_DEDICATED_FACH(void);
void L1TRC_Send_UL1D_TRC_FACH_PCH_STATE_TRCH_NUM(short v1, short v2);
void L1TRC_Send_UL1D_TRC_SFN_START(long v1);
void L1TRC_Send_UL1D_TRC_SFN_DETECTED(unsigned char v1);
void L1TRC_Send_UL1D_TRC_SFN_TRY_CNT(short v1);
void L1TRC_Send_UL1D_TRC_SFN_REPORT_RESULT(short v1, short v2, char v3, long v4, short v5);
void L1TRC_Send_UL1D_TRC_BCH_START_PARAM(unsigned short v1, unsigned short v2, long v3, long v4, short v5, char v6);
void L1TRC_Send_UL1D_TRC_BCH_MPS_TRIGGER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_BCH_STATE_INFO(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_CMB_EN(char v1, char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_CODEGEN_RL0(unsigned short v1);
void L1TRC_Send_UL1D_TRC_TXBRP_TF(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_TXBRP_ACTIVE_TRCH(unsigned long v1);
void L1TRC_Send_UL1D_TRC_TXBRP_START_TIME(unsigned short v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_TXBRP_DONE_TIME(unsigned short v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_TXBRP_ENC_TIME(unsigned short v1);
void L1TRC_Send_UL1D_TRC_CHEST_SPEED(unsigned char v1);
void L1TRC_Send_UL1D_TRC_PCH_SET_RXD_FORCE_NORMAL(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_PCH_SET_CSFB(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_SRCHR_PI_WAKEUP_STATUS(unsigned char v1);
void L1TRC_Send_UL1D_TRC_SRCHR_PI_FOE_RESULT(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_PICH_RESULT(unsigned char v1, short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_SRCHR_PICH_RESULT(unsigned char v1, long v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_SRCHR_PICH_TRACKER_THR(unsigned char v1);
void L1TRC_Send_UL1D_TRC_PICH_SKIP_BY_UL1D(unsigned char v1);
void L1TRC_Send_UL1D_TRC_PICH_SKIP(unsigned short v1);
void L1TRC_Send_UL1D_TRC_PICH_PI_POSITION(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_SRCHR_PI_DECODE(long v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_SRCHR_PI_SCHEDULE(short v1, long v2, long v3, long v4, short v5);
void L1TRC_Send_UL1D_TRC_OFFLINE_PCH_DCXO_DD(long v1, long v2);
void L1TRC_Send_UL1D_TRC_OFFLINE_PCH_DBG(long v1, long v2, long v3);
void L1TRC_Send_UL1D_TRC_OFFLINE_PCH_SET(unsigned short v1);
void L1TRC_Send_UL1D_TRC_TFCI_STATE(char v1, char v2, short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_DMA_DONE(char v1, short v2);
void L1TRC_Send_UL1D_TRC_CMB_ICHCON(unsigned short v1);
void L1TRC_Send_UL1D_TRC_SPEST_STA(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_SPEST_RESULT(unsigned char v1);
void L1TRC_Send_UL1D_TRC_RXBRP_TFCI_OUT_OF_RANGE(unsigned short v1);
void L1TRC_Send_UL1D_TRC_HWTPC_WTXUPC_ASPOW(unsigned long v1);
void L1TRC_Send_UL1D_TRC_HWTPC_SLOTMASK(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_HWTPC_SLOT_FORMAT(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_HWTPC_INFO(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15);
void L1TRC_Send_UL1D_TRC_HWTPC_DBG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_HWTPC_PWR(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8, char v9, char v10, char v11, char v12, char v13, char v14, char v15);
void L1TRC_Send_UL1D_TRC_HWTPC_PWR_RF(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8, char v9, char v10, char v11, char v12, char v13, char v14, char v15);
void L1TRC_Send_UL1D_TRC_HWTPC_PWR_PD(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8, char v9, char v10, char v11, char v12, char v13, char v14, char v15);
void L1TRC_Send_UL1D_TRC_HWTPC_PWR_MAX_MIN(char v1, char v2, char v3, char v4, char v5, short v6);
void L1TRC_Send_UL1D_TRC_HWTPC_PWR_AP_REP(char v1);
void L1TRC_Send_UL1D_TRC_HWTPC_CMD(unsigned long v1);
void L1TRC_Send_UL1D_TRC_HWTPC_CMD2(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15);
void L1TRC_Send_UL1D_TRC_EM_PWR_TX(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_ACS_START(char v1);
void L1TRC_Send_UL1D_TRC_TIMING_ERROR_ACS(unsigned short v1, short v2);
void L1TRC_Send_UL1D_TRC_32KLESS_TIMING_ERROR_VALID(unsigned char v1, char v2);
void L1TRC_Send_UL1D_TRC_32KLESS_TIMING_ERROR(short v1, char v2);
void L1TRC_Send_UL1D_TRC_32KLESS_DIVIDER(unsigned long v1);
void L1TRC_Send_UL1D_TRC_32KLESS_FPM_DIVIDER(unsigned long v1);
void L1TRC_Send_UL1D_TRC_SM_FREQ_OFFSET(unsigned short v1, short v2, short v3, long v4);
void L1TRC_Send_UL1D_TRC_RFM_CHECK_SINGLE_CELL(unsigned char v1, short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_RFM_UPDATE_TIMING_FROM_CM(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_RFM_UPDATE_TIMING_TO_MPS(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_RFM_UPDATE_TIMING_GSR_UPDATE(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_RFM_UPDATE_TIMING_FNG_DEL(short v1, short v2);

void Set_UL1D_SEC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_SEC()	(UL1D_SEC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_SEC_SM_L()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_SEC_SM_M()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_SEC_SM_H()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_SEC_RACH_H()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_SEC_RACH_M()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_SEC_RACH_L()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_SEC_PICH_H()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_SEC_HWTPC_L()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_SEC_HWTPCBSI_L()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_SEC_HWTPC_M()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_SEC_HWTPC_H()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_SEC_RXBRP_L()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_SEC_RXBRP_M()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_SEC_RXBRP_H()	(ChkL1ModFltr_UL1D_SEC()&&((UL1D_SEC_Trace_Filter[2]&0x20)!=0))
#define ChkL1MsgFltr_UL1D_TRC_STATE_MACHINE()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_PICH_STATE_MACHINE()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_FORCE_NORMAL_DUMMY_TIMER()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_PICH_TM_ERROR()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_PICH_TM_ADJ()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_PICH_LST_FN()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_PCH_TM_INFO()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_PICH_SRCHR_INTR_CFG_DBG()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_PICH_SRCHR_INTR_CHK_DBG()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_RXBRP_STATE()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_UL_TGPS_INFO()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_TGPS_INFO()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_RACH_PREAMBLE_PARAMETERS()	ChkL1ClsFltr_UL1D_SEC_RACH_H()
#define ChkL1MsgFltr_UL1D_TRC_RACH_INIT_POWER_PARAM()	ChkL1ClsFltr_UL1D_SEC_RACH_H()
#define ChkL1MsgFltr_UL1D_TRC_RACH_PREAMBLE_TRANSMIT()	ChkL1ClsFltr_UL1D_SEC_RACH_H()
#define ChkL1MsgFltr_UL1D_TRC_RACH_SEND_REPORT()	ChkL1ClsFltr_UL1D_SEC_RACH_M()
#define ChkL1MsgFltr_UL1D_TRC_AICH_DEBUG()	ChkL1ClsFltr_UL1D_SEC_RACH_M()
#define ChkL1MsgFltr_UL1D_TRC_UPDATE_AICH_TH()	ChkL1ClsFltr_UL1D_SEC_RACH_L()
#define ChkL1MsgFltr_UL1D_TRC_AICH_RESULT()	ChkL1ClsFltr_UL1D_SEC_RACH_H()
#define ChkL1MsgFltr_UL1D_TRC_AICH_NO_AI_INT()	ChkL1ClsFltr_UL1D_SEC_RACH_H()
#define ChkL1MsgFltr_UL1D_TRC_FACH_FMO()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_FACH_SUSPEND_GAP()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_FACH_FAKE_TFCI()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_FACH_RX_SUSPEND()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_FACH_RXCRP_DELAY_START()	ChkL1ClsFltr_UL1D_SEC_SM_M()
#define ChkL1MsgFltr_UL1D_TRC_FACH_START_FOR_DEDICATED_FACH()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_FACH_SET_RPT_FOR_DEDICATED_FACH()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_FACH_PCH_STATE_TRCH_NUM()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_SFN_START()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_SFN_DETECTED()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_SFN_TRY_CNT()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_SFN_REPORT_RESULT()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_BCH_START_PARAM()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_BCH_MPS_TRIGGER()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_BCH_STATE_INFO()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_CMB_EN()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_CODEGEN_RL0()	ChkL1ClsFltr_UL1D_SEC_SM_M()
#define ChkL1MsgFltr_UL1D_TRC_TXBRP_TF()	ChkL1ClsFltr_UL1D_SEC_SM_L()
#define ChkL1MsgFltr_UL1D_TRC_TXBRP_ACTIVE_TRCH()	ChkL1ClsFltr_UL1D_SEC_SM_M()
#define ChkL1MsgFltr_UL1D_TRC_TXBRP_START_TIME()	ChkL1ClsFltr_UL1D_SEC_SM_M()
#define ChkL1MsgFltr_UL1D_TRC_TXBRP_DONE_TIME()	ChkL1ClsFltr_UL1D_SEC_SM_M()
#define ChkL1MsgFltr_UL1D_TRC_TXBRP_ENC_TIME()	ChkL1ClsFltr_UL1D_SEC_SM_L()
#define ChkL1MsgFltr_UL1D_TRC_CHEST_SPEED()	ChkL1ClsFltr_UL1D_SEC_SM_M()
#define ChkL1MsgFltr_UL1D_TRC_PCH_SET_RXD_FORCE_NORMAL()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_PCH_SET_CSFB()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_SRCHR_PI_WAKEUP_STATUS()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_SRCHR_PI_FOE_RESULT()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_PICH_RESULT()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_SRCHR_PICH_RESULT()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_SRCHR_PICH_TRACKER_THR()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_PICH_SKIP_BY_UL1D()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_PICH_SKIP()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_PICH_PI_POSITION()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_SRCHR_PI_DECODE()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_SRCHR_PI_SCHEDULE()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_OFFLINE_PCH_DCXO_DD()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_OFFLINE_PCH_DBG()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_OFFLINE_PCH_SET()	ChkL1ClsFltr_UL1D_SEC_PICH_H()
#define ChkL1MsgFltr_UL1D_TRC_TFCI_STATE()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_DMA_DONE()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_CMB_ICHCON()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_SPEST_STA()	ChkL1ClsFltr_UL1D_SEC_SM_M()
#define ChkL1MsgFltr_UL1D_TRC_SPEST_RESULT()	ChkL1ClsFltr_UL1D_SEC_SM_M()
#define ChkL1MsgFltr_UL1D_TRC_RXBRP_TFCI_OUT_OF_RANGE()	ChkL1ClsFltr_UL1D_SEC_RXBRP_L()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_WTXUPC_ASPOW()	ChkL1ClsFltr_UL1D_SEC_HWTPC_M()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_SLOTMASK()	ChkL1ClsFltr_UL1D_SEC_HWTPC_L()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_SLOT_FORMAT()	ChkL1ClsFltr_UL1D_SEC_HWTPC_M()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_INFO()	ChkL1ClsFltr_UL1D_SEC_HWTPC_L()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_DBG()	ChkL1ClsFltr_UL1D_SEC_HWTPC_L()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_PWR()	ChkL1ClsFltr_UL1D_SEC_HWTPC_L()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_PWR_RF()	ChkL1ClsFltr_UL1D_SEC_HWTPC_L()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_PWR_PD()	ChkL1ClsFltr_UL1D_SEC_HWTPC_M()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_PWR_MAX_MIN()	ChkL1ClsFltr_UL1D_SEC_HWTPC_H()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_PWR_AP_REP()	ChkL1ClsFltr_UL1D_SEC_HWTPC_H()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_CMD()	ChkL1ClsFltr_UL1D_SEC_HWTPC_H()
#define ChkL1MsgFltr_UL1D_TRC_HWTPC_CMD2()	ChkL1ClsFltr_UL1D_SEC_HWTPC_L()
#define ChkL1MsgFltr_UL1D_TRC_EM_PWR_TX()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_ACS_START()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_TIMING_ERROR_ACS()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_32KLESS_TIMING_ERROR_VALID()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_32KLESS_TIMING_ERROR()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_32KLESS_DIVIDER()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_32KLESS_FPM_DIVIDER()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_SM_FREQ_OFFSET()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_RFM_CHECK_SINGLE_CELL()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_RFM_UPDATE_TIMING_FROM_CM()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_RFM_UPDATE_TIMING_TO_MPS()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_RFM_UPDATE_TIMING_GSR_UPDATE()	ChkL1ClsFltr_UL1D_SEC_SM_H()
#define ChkL1MsgFltr_UL1D_TRC_RFM_UPDATE_TIMING_FNG_DEL()	ChkL1ClsFltr_UL1D_SEC_SM_H()


#endif
