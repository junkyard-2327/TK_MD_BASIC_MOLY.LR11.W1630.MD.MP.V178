#ifndef L1TRC_EL1D_RX0_DEF_H
#define L1TRC_EL1D_RX0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_RX_FRAME_TYPE(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_RX_CP_TYPE(v1)  (unsigned char)(v1+2)
#define EL1D_TRC_STR_RX_SF_TYPE(v1)  (unsigned char)(v1+4)
#define EL1D_TRC_STR_RX_DL_BW(v1)  (unsigned char)(v1+7)
#define EL1D_TRC_STR_RX_ANT_PORT(v1)  (unsigned char)(v1+13)
#define EL1D_TRC_STR_RX_MIB_SPARE_CTRL(v1)  (unsigned char)(v1+17)
#define EL1D_TRC_STR_RX_PHICH_DUR(v1)  (unsigned char)(v1+20)
#define EL1D_TRC_STR_RX_PHICH_RES(v1)  (unsigned char)(v1+22)
#define EL1D_TRC_STR_RX_ANT_MASK(v1)  (unsigned char)(v1+26)
#define EL1D_TRC_STR_RX_FSM_STATE(v1)  (unsigned char)(v1+30)
#define EL1D_TRC_STR_RX_SYNC_STATE(v1)  (unsigned char)(v1+43)
#define EL1D_TRC_STR_RX_PRE_SYNC_MODE(v1)  (unsigned char)(v1+58)
#define EL1D_TRC_STR_RX_PRE_SYNC_TARGET_MODE(v1)  (unsigned char)(v1+71)
#define EL1D_TRC_STR_RX_PRE_SYNC_TARGET_TYPE(v1)  (unsigned char)(v1+76)
#define EL1D_TRC_STR_RX_NEIGH_CONFIG(v1)  (unsigned char)(v1+79)
#define EL1D_TRC_STR_RX_LTE_STATUS(v1)  (unsigned char)(v1+83)
#define EL1D_TRC_STR_RX_RRC_CHOICE(v1)  (unsigned char)(v1+86)
#define EL1D_TRC_STR_RX_AGGRE_TDD_CONFIG(v1)  (unsigned char)(v1+88)
#define EL1D_TRC_STR_RX_SRV_NBR_CHANGE(v1)  (unsigned char)(v1+91)
#define EL1D_TRC_STR_RX_CELL_IND(v1)  (unsigned char)(v1+95)
#define EL1D_TRC_STR_RX_MIB_TYPE(v1)  (unsigned char)(v1+99)
#define EL1D_TRC_STR_RX_DL_SPS_SOURCE(v1)  (unsigned char)(v1+105)
#define EL1D_TRC_STR_RX_EVENT_TYPE(v1)  (unsigned char)(v1+109)
#define EL1D_TRC_STR_RX_CMD_ID(v1)  (unsigned char)(v1+127)
#define EL1D_TRC_STR_RX_DLSYNC_TYPE(v1)  (unsigned char)(v1+153)
#define EL1D_TRC_STR_RX_SCHEDULE_CELL_INFO(v1)  (unsigned char)(v1+155)
#define EL1D_TRC_STR_RX_DSP_TICK_EN_BMP(v1)  (unsigned char)(v1+157)
#define EL1D_TRC_STR_RX_FORCE_IDLE_BMP(v1)  (unsigned char)(v1+173)
#define EL1D_TRC_STR_RX_PCSI_CMD(v1)  (unsigned char)(v1+181)
#define EL1D_TRC_STR_RX_PI_LPWR_SUBMODE(v1)  (unsigned char)(v1+189)
#define EL1D_TRC_STR_RX_PI_LPWR_GEAR(v1)  (unsigned char)(v1+192)
#define EL1D_TRC_STR_RX_CSIF_CELL_STATUS(v1)  (unsigned char)(v1+197)
#define EL1D_TRC_STR_RX_CIDD_MOD(v1)  (unsigned char)(v1+201)
#define EL1D_TRC_STR_RX_TIMESTAMP(v1)  (unsigned char)(v1+203)
#define EL1D_TRC_STR_RX_RRC_STATE(v1)  (unsigned char)(v1+215)
#define EL1D_TRC_STR_RX_SLEEP_LOCK_REASON(v1)  (unsigned char)(v1+217)
#define EL1D_TRC_STR_RX_SYNC_ERR_HANDLE(v1)  (unsigned char)(v1+221)
#define EL1D_TRC_STR_RX_INFO_CAL_WORST_LEN(v1)  (unsigned char)(v1+226)
#define EL1D_TRC_STR_RX_INFO_HST_CALL_BY_EL1C(v1)  (unsigned char)(v1+229)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_REF_CELL_CHG_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0039, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_REF_CELL_CHG_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_REF_CELL_CHG_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0039, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SRV_CELL_INFO_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0139, (unsigned short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), (unsigned char)(v11), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SRV_CELL_INFO_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_RX0_FSM_SRV_CELL_INFO_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0139, (unsigned short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), (unsigned char)(v11), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_REF_CELL_TIME_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0239, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_REF_CELL_TIME_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_FSM_REF_CELL_TIME_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0239, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_NBR_CELL_TIME_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0339, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_NBR_CELL_TIME_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_NBR_CELL_TIME_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0339, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_NBR_CELL_TIME_BY_EL1C_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0439, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_NBR_CELL_TIME_BY_EL1C_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_NBR_CELL_TIME_BY_EL1C_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0439, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_NBR_CELL_TIME_MISMATCH_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0539, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_NBR_CELL_TIME_MISMATCH_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_NBR_CELL_TIME_MISMATCH_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0539, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_CC_STATE_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0639, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_CC_STATE_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_FSM_CC_STATE_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0639, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_CELL_INFO_CHG_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0739, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), (unsigned char)(v11), (unsigned char)(v12)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_CELL_INFO_CHG_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define EL1D_TRC_RX0_FSM_CELL_INFO_CHG_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0739, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v7), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), (unsigned char)(v11), (unsigned char)(v12)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SRV_NBR_CHANGE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0839, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SRV_NBR_CHANGE_H(v1)
#endif
#define EL1D_TRC_RX0_FSM_SRV_NBR_CHANGE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0839, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SCELL_ADD_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0939, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SCELL_ADD_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_FSM_SCELL_ADD_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0939, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SCELL_DELETE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SCELL_DELETE_H()
#endif
#define EL1D_TRC_RX0_FSM_SCELL_DELETE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SCELL_ACTIVATE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SCELL_ACTIVATE_H()
#endif
#define EL1D_TRC_RX0_FSM_SCELL_ACTIVATE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SCELL_DEACTIVATE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SCELL_DEACTIVATE_H()
#endif
#define EL1D_TRC_RX0_FSM_SCELL_DEACTIVATE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_FORCE_PDSCH_IN_MBSFN_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_FORCE_PDSCH_IN_MBSFN_H()
#endif
#define EL1D_TRC_RX0_FSM_FORCE_PDSCH_IN_MBSFN_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_MBSFN_CONFIG_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_MBSFN_CONFIG_H()
#endif
#define EL1D_TRC_RX0_FSM_MBSFN_CONFIG_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_RRC_CONFIG_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0F39, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_RRC_CONFIG_H(v1)
#endif
#define EL1D_TRC_RX0_FSM_RRC_CONFIG_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0F39, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_RRC_CONFIG_SCELL_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1039, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_RRC_CONFIG_SCELL_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_RRC_CONFIG_SCELL_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1039, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_TDD_AND_UL_BW_CONFIG_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1139, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_TDD_AND_UL_BW_CONFIG_H()
#endif
#define EL1D_TRC_RX0_FSM_TDD_AND_UL_BW_CONFIG_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1139, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_NOTIFY_DCTG_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1239, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_NOTIFY_DCTG_H()
#endif
#define EL1D_TRC_RX0_FSM_NOTIFY_DCTG_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1239, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_POST_HANDLER_TRACE_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1339, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_POST_HANDLER_TRACE_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_FSM_POST_HANDLER_TRACE_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1339, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_POST_TIME_CRITICAL_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1439, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v6), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_POST_TIME_CRITICAL_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_FSM_POST_TIME_CRITICAL_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1439, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v6), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_PI_LPWR_MODE_GEAR_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1539, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_PI_LPWR_MODE_GEAR_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_PI_LPWR_MODE_GEAR_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1539, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_LOCK_SLEEP_MODE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1639, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_LOCK_SLEEP_MODE_H()
#endif
#define EL1D_TRC_RX0_FSM_LOCK_SLEEP_MODE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1639, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_UNLOCK_SLEEP_MODE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1739, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_UNLOCK_SLEEP_MODE_H()
#endif
#define EL1D_TRC_RX0_FSM_UNLOCK_SLEEP_MODE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1739, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SLEEP_LOCK_REASON_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1839, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SLEEP_LOCK_REASON_H(v1)
#endif
#define EL1D_TRC_RX0_FSM_SLEEP_LOCK_REASON_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1839, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_RXTDB_SRAM_STILL_LOCK_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1939, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_RXTDB_SRAM_STILL_LOCK_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_FSM_RXTDB_SRAM_STILL_LOCK_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1939, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SET_RXTDB_SRAM_POWER_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A39, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SET_RXTDB_SRAM_POWER_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_SET_RXTDB_SRAM_POWER_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A39, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_NOTIFY_CIDD_DONE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_NOTIFY_CIDD_DONE_H(v1)
#endif
#define EL1D_TRC_RX0_FSM_NOTIFY_CIDD_DONE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_CIDD_MOD_BMP_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C39, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_CIDD_MOD_BMP_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_FSM_CIDD_MOD_BMP_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C39, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX0_FSM_FORCE_RXD_MOD_BMP_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D39, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_FORCE_RXD_MOD_BMP_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_FORCE_RXD_MOD_BMP_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D39, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX0_FSM_FORCE_RXD_BY_CM_BW_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E39, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_FORCE_RXD_BY_CM_BW_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_FORCE_RXD_BY_CM_BW_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E39, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_PSYNC_ABORT_DELAY_UPDATE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_PSYNC_ABORT_DELAY_UPDATE_H()
#endif
#define EL1D_TRC_RX0_FSM_PSYNC_ABORT_DELAY_UPDATE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_BOOT_RAT_CHG_DONE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2039, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_BOOT_RAT_CHG_DONE_H()
#endif
#define EL1D_TRC_RX0_FSM_BOOT_RAT_CHG_DONE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2039, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SET_DVFS_RX_ON_OFF_M(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2139, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SET_DVFS_RX_ON_OFF_M(v1)
#endif
#define EL1D_TRC_RX0_FSM_SET_DVFS_RX_ON_OFF_M_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2139, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SET_DVFS_Inner_ON_M() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2239, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SET_DVFS_Inner_ON_M()
#endif
#define EL1D_TRC_RX0_FSM_SET_DVFS_Inner_ON_M_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2239, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SET_DVFS_CSI_ON_OFF_M(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2339, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SET_DVFS_CSI_ON_OFF_M(v1)
#endif
#define EL1D_TRC_RX0_FSM_SET_DVFS_CSI_ON_OFF_M_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2339, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SET_DVFS_GEAR_INFO_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2439, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SET_DVFS_GEAR_INFO_H(v1)
#endif
#define EL1D_TRC_RX0_FSM_SET_DVFS_GEAR_INFO_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2439, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_DVFS_DEBUG1_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2539, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_DVFS_DEBUG1_H()
#endif
#define EL1D_TRC_RX0_FSM_DVFS_DEBUG1_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2539, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SLEEP_DURATION_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2639, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SLEEP_DURATION_H(v1)
#endif
#define EL1D_TRC_RX0_FSM_SLEEP_DURATION_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2639, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_ABS_TIME_NOT_MATCH_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2739, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_ABS_TIME_NOT_MATCH_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_ABS_TIME_NOT_MATCH_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2739, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_FORCE_DL_ANT_MASK_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2839, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_FORCE_DL_ANT_MASK_H(v1, v2)
#endif
#define EL1D_TRC_RX0_FSM_FORCE_DL_ANT_MASK_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2839, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_PHICH_DROP_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2939, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_PHICH_DROP_H()
#endif
#define EL1D_TRC_RX0_FSM_PHICH_DROP_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2939, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_WORST_CASE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_WORST_CASE_H()
#endif
#define EL1D_TRC_RX0_FSM_WORST_CASE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_FSM_SET_RX_STATUS_FOR_TAS_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_FSM_SET_RX_STATUS_FOR_TAS_H(v1)
#endif
#define EL1D_TRC_RX0_FSM_SET_RX_STATUS_FOR_TAS_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_SYNC_CC_STATE_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C39, (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v8), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_SYNC_CC_STATE_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_SYNC_CC_STATE_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C39, (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v8), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_SYNC_CC_PRE_SYNC_EXE_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2D39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_SYNC_CC_PRE_SYNC_EXE_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_SYNC_CC_PRE_SYNC_EXE_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2D39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_SYNC_CC_POS_PRE_SYNC_EXE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_SYNC_CC_POS_PRE_SYNC_EXE_H(v1)
#endif
#define EL1D_TRC_RX0_SYNC_CC_POS_PRE_SYNC_EXE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_SYNC_INVALID_LIGHT_SYNC_SF_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_SYNC_INVALID_LIGHT_SYNC_SF_H()
#endif
#define EL1D_TRC_RX0_SYNC_INVALID_LIGHT_SYNC_SF_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_SYNC_ERROR_HANDLING_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3039, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_SYNC_ERROR_HANDLING_H(v1, v2)
#endif
#define EL1D_TRC_RX0_SYNC_ERROR_HANDLING_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3039, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_IN_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x3139, (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v10), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), (unsigned char)(v13), TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_IN_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_IN_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) TRC_SEND_6_DATA(TRC_MERGE_2S(0x3139, (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v10), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v8)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), (unsigned char)(v13), TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_OUT_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3239, (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_OUT_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_OUT_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3239, (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX0_PSYNC_CALC_PARAM_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3339, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_PARAM_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_PARAM_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3339, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_WO_DATA_IN_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3439, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_WO_DATA_IN_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_WO_DATA_IN_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3439, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_WO_DATA_OUT_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3539, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_WO_DATA_OUT_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_WO_DATA_OUT_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3539, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_POS_IN_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3639, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_POS_IN_H(v1, v2)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_POS_IN_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3639, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_POS_OUT_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3739, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_POS_OUT_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_POS_OUT_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3739, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_PROGRESSIVE_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3839, (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_1S2C((unsigned short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_PROGRESSIVE_H(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_MODE_PROGRESSIVE_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3839, (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_1S2C((unsigned short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_A_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3939, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_A_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_A_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3939, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_B_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A39, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_B_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_B_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A39, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_C_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B39, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_C_H(v1, v2)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_C_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B39, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NO_PRE_SYNC1_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NO_PRE_SYNC1_H()
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NO_PRE_SYNC1_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NO_PRE_SYNC2_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D39, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NO_PRE_SYNC2_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NO_PRE_SYNC2_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D39, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NOT_READY_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NOT_READY_H()
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NOT_READY_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NOT_DRX_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NOT_DRX_H()
#endif
#define EL1D_TRC_RX0_PSYNC_CALC_MODE_NOT_DRX_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_SET_DUMP_ALLOWED_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4039, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_SET_DUMP_ALLOWED_H(v1)
#endif
#define EL1D_TRC_RX0_PSYNC_SET_DUMP_ALLOWED_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4039, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_FORCE_FAST_MODE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4139, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_FORCE_FAST_MODE_H(v1)
#endif
#define EL1D_TRC_RX0_PSYNC_FORCE_FAST_MODE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4139, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_FORCE_PROGRESSIVE_MODE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4239, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_FORCE_PROGRESSIVE_MODE_H(v1)
#endif
#define EL1D_TRC_RX0_PSYNC_FORCE_PROGRESSIVE_MODE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4239, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_FORCE_NORMAL_MODE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4339, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_FORCE_NORMAL_MODE_H(v1)
#endif
#define EL1D_TRC_RX0_PSYNC_FORCE_NORMAL_MODE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4339, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_FORCE_NORMAL_LENGTH_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4439, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_FORCE_NORMAL_LENGTH_H(v1)
#endif
#define EL1D_TRC_RX0_PSYNC_FORCE_NORMAL_LENGTH_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4439, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_FORCE_USING_RS_EN_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4539, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_FORCE_USING_RS_EN_H(v1)
#endif
#define EL1D_TRC_RX0_PSYNC_FORCE_USING_RS_EN_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4539, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_FORCE_USING_RS_EN2_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4639, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_FORCE_USING_RS_EN2_H()
#endif
#define EL1D_TRC_RX0_PSYNC_FORCE_USING_RS_EN2_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4639, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_FORCE_NON_DUMP_BY_SNR_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4739, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_FORCE_NON_DUMP_BY_SNR_H(v1, v2)
#endif
#define EL1D_TRC_RX0_PSYNC_FORCE_NON_DUMP_BY_SNR_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4739, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_PSYNC_DRX_WAKE_UP_UPDATE_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4839, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_PSYNC_DRX_WAKE_UP_UPDATE_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX0_PSYNC_DRX_WAKE_UP_UPDATE_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4839, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_PRE_CAL_RRC_INFO_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4939, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_PRE_CAL_RRC_INFO_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_INFO_PRE_CAL_RRC_INFO_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4939, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_PRE_CAL_MBSFN_INFO_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A39, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_PRE_CAL_MBSFN_INFO_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_INFO_PRE_CAL_MBSFN_INFO_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A39, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_PRE_CAL_PAGING_INFO_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B39, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_PRE_CAL_PAGING_INFO_H(v1, v2)
#endif
#define EL1D_TRC_RX0_INFO_PRE_CAL_PAGING_INFO_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B39, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_CAL_MEAS_SF_PATTERN_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4C39, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_CAL_MEAS_SF_PATTERN_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_INFO_CAL_MEAS_SF_PATTERN_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4C39, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_CAL_MBSFN_INFO_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4D39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_CAL_MBSFN_INFO_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_INFO_CAL_MBSFN_INFO_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4D39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_CAL_SF_INFO_FORCE_UL_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E39, (char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_CAL_SF_INFO_FORCE_UL_H(v1, v2)
#endif
#define EL1D_TRC_RX0_INFO_CAL_SF_INFO_FORCE_UL_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E39, (char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_RRC_CROSS_SCHEDULE_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4F39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_RRC_CROSS_SCHEDULE_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_INFO_RRC_CROSS_SCHEDULE_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4F39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_SFBD_SF_DIFF_ABNORMAL_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5039, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_SFBD_SF_DIFF_ABNORMAL_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_INFO_SFBD_SF_DIFF_ABNORMAL_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5039, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_INFO_PCSI_MEAS_SET_L(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5139, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_PCSI_MEAS_SET_L(v1, v2)
#endif
#define EL1D_TRC_RX0_INFO_PCSI_MEAS_SET_L_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5139, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_CAL_HST_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5239, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v7)), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_CAL_HST_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX0_INFO_CAL_HST_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5239, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v6), (unsigned char)(v7)), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_CAL_WORST_LEN_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5339, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_CAL_WORST_LEN_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_INFO_CAL_WORST_LEN_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5339, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_CAL_GENIE_PATTERN_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5439, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_CAL_GENIE_PATTERN_H(v1)
#endif
#define EL1D_TRC_RX0_INFO_CAL_GENIE_PATTERN_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5439, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_PCSI_MEAS_SF_PATTERN_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5539, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_PCSI_MEAS_SF_PATTERN_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_INFO_PCSI_MEAS_SF_PATTERN_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5539, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_EL1C_HST_UPDATE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5639, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_EL1C_HST_UPDATE_H(v1)
#endif
#define EL1D_TRC_RX0_INFO_EL1C_HST_UPDATE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5639, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_INFO_HO_ENABLE_INFO_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5739, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_INFO_HO_ENABLE_INFO_H(v1)
#endif
#define EL1D_TRC_RX0_INFO_HO_ENABLE_INFO_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5739, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_EVENT_EXPIRE_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5839, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX0_EVENT_EXPIRE_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_EVENT_EXPIRE_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5839, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_EVENT_DL_SPS_EXPIRE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5939, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_EVENT_DL_SPS_EXPIRE_H()
#endif
#define EL1D_TRC_RX0_EVENT_DL_SPS_EXPIRE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5939, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_RAT_CHG_PARSE_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5A39, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_RAT_CHG_PARSE_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_CMD_RAT_CHG_PARSE_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5A39, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_TX_IND_PARSE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5B39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_TX_IND_PARSE_H(v1)
#endif
#define EL1D_TRC_RX0_CMD_TX_IND_PARSE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5B39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_DL_REL_PARSE_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5C39, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_DL_REL_PARSE_H(v1, v2)
#endif
#define EL1D_TRC_RX0_CMD_DL_REL_PARSE_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5C39, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_DL_CHG_TAS_PARSE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_DL_CHG_TAS_PARSE_H(v1)
#endif
#define EL1D_TRC_RX0_CMD_DL_CHG_TAS_PARSE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_DL_CHG_CC0_PARSE_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5E39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_DL_CHG_CC0_PARSE_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_CMD_DL_CHG_CC0_PARSE_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5E39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_DL_CHG_CC1_PARSE_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5F39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_DL_CHG_CC1_PARSE_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_CMD_DL_CHG_CC1_PARSE_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5F39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_SCELL_ACT_PARSE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6039, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_SCELL_ACT_PARSE_H(v1)
#endif
#define EL1D_TRC_RX0_CMD_SCELL_ACT_PARSE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6039, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_SCELL_ACT_SYNC_PARSE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6139, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_SCELL_ACT_SYNC_PARSE_H()
#endif
#define EL1D_TRC_RX0_CMD_SCELL_ACT_SYNC_PARSE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6139, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_SCELL_PSEUDO_ACT_PARSE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6239, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_SCELL_PSEUDO_ACT_PARSE_H(v1)
#endif
#define EL1D_TRC_RX0_CMD_SCELL_PSEUDO_ACT_PARSE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6239, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_PRE_SYNC_PARSE_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6339, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_PRE_SYNC_PARSE_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_CMD_PRE_SYNC_PARSE_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6339, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_MAIN_CC0_PARSE_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6439, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_MAIN_CC0_PARSE_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_CMD_MAIN_CC0_PARSE_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6439, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_MAIN_CC1_PARSE_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6539, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_MAIN_CC1_PARSE_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_CMD_MAIN_CC1_PARSE_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6539, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_MAIN_NBR_PARSE_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6639, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_MAIN_NBR_PARSE_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_CMD_MAIN_NBR_PARSE_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6639, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_PHICH_PARSE_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6739, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_PHICH_PARSE_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_CMD_PHICH_PARSE_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6739, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_DL_SPS_PARSE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6839, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_DL_SPS_PARSE_H(v1)
#endif
#define EL1D_TRC_RX0_CMD_DL_SPS_PARSE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6839, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_POS_PRE_SYNC_PARSE_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6939, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_POS_PRE_SYNC_PARSE_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_CMD_POS_PRE_SYNC_PARSE_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6939, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_CMD_DISABLE_TO_ENABLE_M(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6A39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_DISABLE_TO_ENABLE_M(v1)
#endif
#define EL1D_TRC_RX0_CMD_DISABLE_TO_ENABLE_M_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6A39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_TASK_CONFIG_WITH_DL_CHG_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6B39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_TASK_CONFIG_WITH_DL_CHG_H(v1)
#endif
#define EL1D_TRC_RX0_CMD_TASK_CONFIG_WITH_DL_CHG_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6B39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_MIB_PARAM_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6C39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_MIB_PARAM_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_CMD_MIB_PARAM_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6C39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_MIB_PARAM2_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6D39, (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v8), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_MIB_PARAM2_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_CMD_MIB_PARAM2_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6D39, (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v8), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_SI_PARAM_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6E39, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v7), (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_SI_PARAM_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX0_CMD_SI_PARAM_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6E39, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v7), (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_PI_PARAM_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6F39, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_PI_PARAM_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_CMD_PI_PARAM_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6F39, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_MBMS_PARAM_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7039, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_MBMS_PARAM_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_CMD_MBMS_PARAM_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7039, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_PCSI_PARSE_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7139, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_PCSI_PARSE_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_CMD_PCSI_PARSE_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7139, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_NEIGH_CELL_CONFIG_PARSE_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7239, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_NEIGH_CELL_CONFIG_PARSE_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_CMD_NEIGH_CELL_CONFIG_PARSE_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7239, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_VZW_TEST_REQ_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7339, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_VZW_TEST_REQ_H(v1)
#endif
#define EL1D_TRC_RX0_CMD_VZW_TEST_REQ_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7339, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_VZW_SRV_MEAS_REQ_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7439, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_VZW_SRV_MEAS_REQ_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_CMD_VZW_SRV_MEAS_REQ_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7439, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_GET_CMD_BY_EL1C_ERROR_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7539, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_GET_CMD_BY_EL1C_ERROR_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_CMD_GET_CMD_BY_EL1C_ERROR_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7539, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_CMD_DISABLE_FAST_PSYNC_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7639, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_CMD_DISABLE_FAST_PSYNC_H(v1)
#endif
#define EL1D_TRC_RX0_CMD_DISABLE_FAST_PSYNC_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7639, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_RPT_RLM_DBG_INFO_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7739, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX0_RPT_RLM_DBG_INFO_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_RPT_RLM_DBG_INFO_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7739, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_RRC_RECONFIG_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7839, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_RRC_RECONFIG_H(v1)
#endif
#define EL1D_TRC_RX0_DCMD_RRC_RECONFIG_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7839, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_CELL_RECONFIG_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7939, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_CELL_RECONFIG_H(v1)
#endif
#define EL1D_TRC_RX0_DCMD_CELL_RECONFIG_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7939, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_DSP_TICK_INNER_INFO_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7A39, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v6)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_DSP_TICK_INNER_INFO_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_DCMD_DSP_TICK_INNER_INFO_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7A39, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v6)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_SET_PMCH_CMD_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7B39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_PMCH_CMD_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_DCMD_SET_PMCH_CMD_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7B39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_DCMD_SET_RX_PATH_CMD_M(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7C39, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_RX_PATH_CMD_M(v1, v2)
#endif
#define EL1D_TRC_RX0_DCMD_SET_RX_PATH_CMD_M_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7C39, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_MIB_REQUEST_FAIL_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7D39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_MIB_REQUEST_FAIL_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DCMD_MIB_REQUEST_FAIL_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7D39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX0_DCMD_SET_CMD_BMP_WI_AFTER_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7E39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_CMD_BMP_WI_AFTER_H(v1, v2)
#endif
#define EL1D_TRC_RX0_DCMD_SET_CMD_BMP_WI_AFTER_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7E39, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_SET_RNTI_ENABLE_M(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7F39, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_RNTI_ENABLE_M(v1, v2)
#endif
#define EL1D_TRC_RX0_DCMD_SET_RNTI_ENABLE_M_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7F39, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_DL_HARQ_IS_DISABLED_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8039, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_DL_HARQ_IS_DISABLED_H()
#endif
#define EL1D_TRC_RX0_DCMD_DL_HARQ_IS_DISABLED_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8039, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_WR_PI_DUMP_INFO_M(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x8139, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_WR_PI_DUMP_INFO_M(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DCMD_WR_PI_DUMP_INFO_M_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x8139, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_DCMD_SET_DUMP_BMP_INFO_M(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8239, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_DUMP_BMP_INFO_M(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DCMD_SET_DUMP_BMP_INFO_M_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8239, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_DCMD_SET_LPWR_CTRL_M(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8339, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_LPWR_CTRL_M(v1, v2)
#endif
#define EL1D_TRC_RX0_DCMD_SET_LPWR_CTRL_M_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8339, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_WRITE_CSIF_CHG_INFO_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8439, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_WRITE_CSIF_CHG_INFO_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_DCMD_WRITE_CSIF_CHG_INFO_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8439, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_WRITE_CMIF_CMD_INIT_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8539, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_WRITE_CMIF_CMD_INIT_H(v1)
#endif
#define EL1D_TRC_RX0_DCMD_WRITE_CMIF_CMD_INIT_H_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8539, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_DCI_QI_CHECK_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8639, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_DCI_QI_CHECK_H(v1, v2)
#endif
#define EL1D_TRC_RX0_DCMD_DCI_QI_CHECK_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8639, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_SET_CTRL_NE_CMD_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8739, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_CTRL_NE_CMD_H(v1, v2)
#endif
#define EL1D_TRC_RX0_DCMD_SET_CTRL_NE_CMD_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8739, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_DCMD_INTRA_NBR_INFO_L(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8839, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_INTRA_NBR_INFO_L(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_DCMD_INTRA_NBR_INFO_L_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8839, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_POS_REF_PDP_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8939, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_POS_REF_PDP_H()
#endif
#define EL1D_TRC_RX0_DCMD_POS_REF_PDP_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8939, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_SET_PCSI_CMD_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8A39, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_PCSI_CMD_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX0_DCMD_SET_PCSI_CMD_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8A39, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_DCMD_SET_CSI_CMD_L(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8B39, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_CSI_CMD_L(v1, v2)
#endif
#define EL1D_TRC_RX0_DCMD_SET_CSI_CMD_L_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8B39, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_CSI_LAST_TICK_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8C39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_CSI_LAST_TICK_H(v1)
#endif
#define EL1D_TRC_RX0_DCMD_CSI_LAST_TICK_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8C39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_CSI_RESET_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8D39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_CSI_RESET_H(v1)
#endif
#define EL1D_TRC_RX0_DCMD_CSI_RESET_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8D39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_SET_PCSI_TXINFO_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8E39, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_PCSI_TXINFO_H(v1, v2)
#endif
#define EL1D_TRC_RX0_DCMD_SET_PCSI_TXINFO_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8E39, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_SET_Quantized_PCSI_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8F39, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_SET_Quantized_PCSI_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_DCMD_SET_Quantized_PCSI_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8F39, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_MIB_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9039, (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_MIB_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_DRPT_MIB_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9039, (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9139, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DRPT_DCI_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9139, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_DRPT_DCI_PDSCH_BMP_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9239, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI_PDSCH_BMP_H(v1, v2)
#endif
#define EL1D_TRC_RX0_DRPT_DCI_PDSCH_BMP_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9239, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI_C_RNTI_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9339, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI_C_RNTI_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_DRPT_DCI_C_RNTI_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9339, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI_CC0_TC_RNTI_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9439, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI_CC0_TC_RNTI_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_DRPT_DCI_CC0_TC_RNTI_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9439, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI_CC0_SPS_RNTI_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9539, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI_CC0_SPS_RNTI_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DRPT_DCI_CC0_SPS_RNTI_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x9539, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI_CC0_SPS_FALSE_ALARM_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9639, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI_CC0_SPS_FALSE_ALARM_H(v1)
#endif
#define EL1D_TRC_RX0_DRPT_DCI_CC0_SPS_FALSE_ALARM_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9639, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI_M_RNTI_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9739, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI_M_RNTI_H(v1, v2)
#endif
#define EL1D_TRC_RX0_DRPT_DCI_M_RNTI_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9739, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI_ORDER_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9839, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI_ORDER_H(v1, v2)
#endif
#define EL1D_TRC_RX0_DRPT_DCI_ORDER_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9839, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI_CELL_TIME_MISMATCH_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9939, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI_CELL_TIME_MISMATCH_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_DRPT_DCI_CELL_TIME_MISMATCH_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9939, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI_MISS_H(v1, v2) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x9A39, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI_MISS_H(v1, v2)
#endif
#define EL1D_TRC_RX0_DRPT_DCI_MISS_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x9A39, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_CRC_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9B39, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_CRC_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_DRPT_CRC_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9B39, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_CRC_C_TC_SPS_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x9C39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_CRC_C_TC_SPS_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_DRPT_CRC_C_TC_SPS_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x9C39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_CRC_RA_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9D39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_CRC_RA_H(v1)
#endif
#define EL1D_TRC_RX0_DRPT_CRC_RA_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9D39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_CRC_SI_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x9E39, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_CRC_SI_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DRPT_CRC_SI_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x9E39, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_CRC_PI_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x9F39, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_CRC_PI_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_DRPT_CRC_PI_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x9F39, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_DRPT_CRC_DEBUG_INFO_M(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0xA039, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_CRC_DEBUG_INFO_M(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_DRPT_CRC_DEBUG_INFO_M_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0xA039, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_DRPT_CRC_DEBUG_INFO2_M(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA139, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_CRC_DEBUG_INFO2_M(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_DRPT_CRC_DEBUG_INFO2_M_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA139, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_CRC_CELL_TIME_MISMATCH_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA239, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_CRC_CELL_TIME_MISMATCH_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_DRPT_CRC_CELL_TIME_MISMATCH_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA239, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_CRC_C_TC_SPS_MISMATCH_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xA339, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_CRC_C_TC_SPS_MISMATCH_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DRPT_CRC_C_TC_SPS_MISMATCH_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xA339, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_PHICH_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xA439, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_PHICH_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DRPT_PHICH_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xA439, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI0_CSI_INVLD_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xA539, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI0_CSI_INVLD_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_RX0_DRPT_DCI0_CSI_INVLD_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xA539, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI0_CSI_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA639, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI0_CSI_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_RX0_DRPT_DCI0_CSI_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA639, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DCI0_SPS_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA739, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DCI0_SPS_H(v1)
#endif
#define EL1D_TRC_RX0_DRPT_DCI0_SPS_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA739, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_RLM_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xA839, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), (char)(v4)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_RLM_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_RLM_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0xA839, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_RLM_FROM_NE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA939, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_RLM_FROM_NE_H()
#endif
#define EL1D_TRC_RX0_DRPT_INNER_RLM_FROM_NE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA939, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_RLM_UNDER_SA_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xAA39, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_RLM_UNDER_SA_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_RLM_UNDER_SA_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0xAA39, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RX0_DRPT_INNER_RRM_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0xAB39, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_RRM_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_RRM_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0xAB39, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_RRM_OC_TIME_OUT_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xAC39, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_RRM_OC_TIME_OUT_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_RRM_OC_TIME_OUT_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0xAC39, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_NE_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xAD39, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_NE_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_NE_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xAD39, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_MD_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xAE39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_MD_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_MD_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xAE39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_FWSSD_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xAF39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_FWSSD_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_FWSSD_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xAF39, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_RRM_IMC_ICC_ERROR_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xB039, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_RRM_IMC_ICC_ERROR_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_RRM_IMC_ICC_ERROR_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xB039, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_DMRS_HW_ISSUE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB139, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_DMRS_HW_ISSUE_H(v1)
#endif
#define EL1D_TRC_RX0_DRPT_DMRS_HW_ISSUE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB139, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_RRM_SELF_SCHEDULE_H() do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB239, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_RRM_SELF_SCHEDULE_H()
#endif
#define EL1D_TRC_RX0_DRPT_INNER_RRM_SELF_SCHEDULE_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB239, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_MD_FORCE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB339, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_MD_FORCE_H(v1)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_MD_FORCE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB339, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_SD_FORCE_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB439, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_SD_FORCE_H(v1)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_SD_FORCE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB439, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_PMCH_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0xB539, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_PMCH_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RX0_DRPT_PMCH_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0xB539, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_DRPT_RLM_DBG_INFO_H(v1, v2, v3, v4) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0xB639, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_RLM_DBG_INFO_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RX0_DRPT_RLM_DBG_INFO_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0xB639, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RX0_DRPT_RLM_DBG_INFO2_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB739, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_RLM_DBG_INFO2_H(v1)
#endif
#define EL1D_TRC_RX0_DRPT_RLM_DBG_INFO2_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB739, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_VZW_MEAS_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0xB839, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_VZW_MEAS_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_VZW_MEAS_H_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0xB839, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_VZW_MEAS_ERROR_H(v1, v2, v3) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xB939, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_VZW_MEAS_ERROR_H(v1, v2, v3)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_VZW_MEAS_ERROR_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xB939, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DRPT_INNER_IS_STATIC_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xBA39, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DRPT_INNER_IS_STATIC_H(v1)
#endif
#define EL1D_TRC_RX0_DRPT_INNER_IS_STATIC_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xBA39, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX0_DCMD_NVRAM_INFO_H(v1) do {\
		if(EL1D_RX0_Trace_Filter[0]==1 && (EL1D_RX0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0xBB39, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RX0_DCMD_NVRAM_INFO_H(v1)
#endif
#define EL1D_TRC_RX0_DCMD_NVRAM_INFO_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0xBB39, (unsigned short)(v1)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_RX0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_RX0_FSM_REF_CELL_CHG_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SRV_CELL_INFO_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, short v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11);
void L1TRC_Send_EL1D_TRC_RX0_FSM_REF_CELL_TIME_H(unsigned short v1, unsigned char v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_FSM_NBR_CELL_TIME_H(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_NBR_CELL_TIME_BY_EL1C_H(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_NBR_CELL_TIME_MISMATCH_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_CC_STATE_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_FSM_CELL_INFO_CHG_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned short v5, unsigned short v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SRV_NBR_CHANGE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SCELL_ADD_H(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SCELL_DELETE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SCELL_ACTIVATE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SCELL_DEACTIVATE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_FORCE_PDSCH_IN_MBSFN_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_MBSFN_CONFIG_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_RRC_CONFIG_H(unsigned short v1);
void L1TRC_Send_EL1D_TRC_RX0_FSM_RRC_CONFIG_SCELL_H(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_TDD_AND_UL_BW_CONFIG_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_NOTIFY_DCTG_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_POST_HANDLER_TRACE_H(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_EL1D_TRC_RX0_FSM_POST_TIME_CRITICAL_H(unsigned char v1, unsigned short v2, unsigned short v3, unsigned long v4, unsigned short v5, unsigned long v6, unsigned short v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_RX0_FSM_PI_LPWR_MODE_GEAR_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_LOCK_SLEEP_MODE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_UNLOCK_SLEEP_MODE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SLEEP_LOCK_REASON_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_FSM_RXTDB_SRAM_STILL_LOCK_H(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SET_RXTDB_SRAM_POWER_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_NOTIFY_CIDD_DONE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_FSM_CIDD_MOD_BMP_H(unsigned char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_RX0_FSM_FORCE_RXD_MOD_BMP_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_FORCE_RXD_BY_CM_BW_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_PSYNC_ABORT_DELAY_UPDATE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_BOOT_RAT_CHG_DONE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SET_DVFS_RX_ON_OFF_M(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SET_DVFS_Inner_ON_M(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SET_DVFS_CSI_ON_OFF_M(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SET_DVFS_GEAR_INFO_H(unsigned short v1);
void L1TRC_Send_EL1D_TRC_RX0_FSM_DVFS_DEBUG1_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SLEEP_DURATION_H(unsigned short v1);
void L1TRC_Send_EL1D_TRC_RX0_FSM_ABS_TIME_NOT_MATCH_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_FORCE_DL_ANT_MASK_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_FSM_PHICH_DROP_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_WORST_CASE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_FSM_SET_RX_STATUS_FOR_TAS_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_SYNC_CC_STATE_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned short v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RX0_SYNC_CC_PRE_SYNC_EXE_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_SYNC_CC_POS_PRE_SYNC_EXE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_SYNC_INVALID_LIGHT_SYNC_SF_H(void);
void L1TRC_Send_EL1D_TRC_RX0_SYNC_ERROR_HANDLING_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_IN_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned long v6, unsigned short v7, unsigned char v8, unsigned long v9, unsigned short v10, unsigned char v11, unsigned char v12, unsigned char v13);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_OUT_H(unsigned char v1, char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned long v6, unsigned short v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_PARAM_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_WO_DATA_IN_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_WO_DATA_OUT_H(unsigned char v1, char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_POS_IN_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_POS_OUT_H(unsigned char v1, unsigned char v2, unsigned long v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_MODE_PROGRESSIVE_H(long v1, long v2, long v3, long v4, long v5, long v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_A_H(char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_B_H(unsigned long v1, unsigned short v2, unsigned char v3, char v4);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_C_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_MODE_NO_PRE_SYNC1_H(void);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_MODE_NO_PRE_SYNC2_H(char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_MODE_NOT_READY_H(void);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_CALC_MODE_NOT_DRX_H(void);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_SET_DUMP_ALLOWED_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_FORCE_FAST_MODE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_FORCE_PROGRESSIVE_MODE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_FORCE_NORMAL_MODE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_FORCE_NORMAL_LENGTH_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_FORCE_USING_RS_EN_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_FORCE_USING_RS_EN2_H(void);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_FORCE_NON_DUMP_BY_SNR_H(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_RX0_PSYNC_DRX_WAKE_UP_UPDATE_H(char v1, unsigned short v2, unsigned short v3, unsigned short v4, short v5, short v6, short v7);
void L1TRC_Send_EL1D_TRC_RX0_INFO_PRE_CAL_RRC_INFO_H(char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_INFO_PRE_CAL_MBSFN_INFO_H(char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX0_INFO_PRE_CAL_PAGING_INFO_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_INFO_CAL_MEAS_SF_PATTERN_H(char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8);
void L1TRC_Send_EL1D_TRC_RX0_INFO_CAL_MBSFN_INFO_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX0_INFO_CAL_SF_INFO_FORCE_UL_H(char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_INFO_RRC_CROSS_SCHEDULE_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX0_INFO_SFBD_SF_DIFF_ABNORMAL_H(unsigned char v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned char v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RX0_INFO_PCSI_MEAS_SET_L(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_RX0_INFO_CAL_HST_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_RX0_INFO_CAL_WORST_LEN_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RX0_INFO_CAL_GENIE_PATTERN_H(char v1);
void L1TRC_Send_EL1D_TRC_RX0_INFO_PCSI_MEAS_SF_PATTERN_H(char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8);
void L1TRC_Send_EL1D_TRC_RX0_INFO_EL1C_HST_UPDATE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_INFO_HO_ENABLE_INFO_H(char v1);
void L1TRC_Send_EL1D_TRC_RX0_EVENT_EXPIRE_H(unsigned char v1, unsigned short v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX0_EVENT_DL_SPS_EXPIRE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_CMD_RAT_CHG_PARSE_H(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RX0_CMD_TX_IND_PARSE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_CMD_DL_REL_PARSE_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_CMD_DL_CHG_TAS_PARSE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_CMD_DL_CHG_CC0_PARSE_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX0_CMD_DL_CHG_CC1_PARSE_H(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX0_CMD_SCELL_ACT_PARSE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_CMD_SCELL_ACT_SYNC_PARSE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_CMD_SCELL_PSEUDO_ACT_PARSE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_CMD_PRE_SYNC_PARSE_H(unsigned char v1, unsigned char v2, unsigned char v3, char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RX0_CMD_MAIN_CC0_PARSE_H(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX0_CMD_MAIN_CC1_PARSE_H(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX0_CMD_MAIN_NBR_PARSE_H(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX0_CMD_PHICH_PARSE_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_CMD_DL_SPS_PARSE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_CMD_POS_PRE_SYNC_PARSE_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, char v5);
void L1TRC_Send_EL1D_TRC_RX0_CMD_DISABLE_TO_ENABLE_M(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_CMD_TASK_CONFIG_WITH_DL_CHG_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_CMD_MIB_PARAM_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX0_CMD_MIB_PARAM2_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned short v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RX0_CMD_SI_PARAM_H(char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned short v5, unsigned char v6, unsigned short v7);
void L1TRC_Send_EL1D_TRC_RX0_CMD_PI_PARAM_H(unsigned char v1, unsigned short v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RX0_CMD_MBMS_PARAM_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RX0_CMD_PCSI_PARSE_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_CMD_NEIGH_CELL_CONFIG_PARSE_H(short v1, unsigned char v2, short v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_CMD_VZW_TEST_REQ_H(char v1);
void L1TRC_Send_EL1D_TRC_RX0_CMD_VZW_SRV_MEAS_REQ_H(char v1, char v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_RX0_CMD_GET_CMD_BY_EL1C_ERROR_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX0_CMD_DISABLE_FAST_PSYNC_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_RPT_RLM_DBG_INFO_H(unsigned short v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_RRC_RECONFIG_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_CELL_RECONFIG_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_DSP_TICK_INNER_INFO_H(unsigned char v1, unsigned long v2, unsigned long v3, unsigned short v4, unsigned short v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_PMCH_CMD_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_RX_PATH_CMD_M(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_MIB_REQUEST_FAIL_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_CMD_BMP_WI_AFTER_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_RNTI_ENABLE_M(char v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_DL_HARQ_IS_DISABLED_H(void);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_WR_PI_DUMP_INFO_M(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_DUMP_BMP_INFO_M(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_LPWR_CTRL_M(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_WRITE_CSIF_CHG_INFO_H(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_WRITE_CMIF_CMD_INIT_H(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_DCI_QI_CHECK_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_CTRL_NE_CMD_H(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_INTRA_NBR_INFO_L(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_POS_REF_PDP_H(void);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_PCSI_CMD_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned short v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_CSI_CMD_L(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_CSI_LAST_TICK_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_CSI_RESET_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_PCSI_TXINFO_H(char v1, char v2);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_SET_Quantized_PCSI_H(unsigned char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_MIB_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned short v8);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI_H(unsigned short v1, unsigned char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI_PDSCH_BMP_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI_C_RNTI_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI_CC0_TC_RNTI_H(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI_CC0_SPS_RNTI_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI_CC0_SPS_FALSE_ALARM_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI_M_RNTI_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI_ORDER_H(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI_CELL_TIME_MISMATCH_H(unsigned char v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI_MISS_H(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_CRC_H(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_CRC_C_TC_SPS_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_CRC_RA_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_CRC_SI_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_CRC_PI_H(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_CRC_DEBUG_INFO_M(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_CRC_DEBUG_INFO2_M(unsigned char v1, unsigned char v2, unsigned short v3, unsigned char v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_CRC_CELL_TIME_MISMATCH_H(unsigned char v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_CRC_C_TC_SPS_MISMATCH_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_PHICH_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI0_CSI_INVLD_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI0_CSI_H(unsigned char v1, unsigned char v2, unsigned char v3, short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DCI0_SPS_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_RLM_H(char v1, unsigned short v2, short v3, char v4);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_RLM_FROM_NE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_RLM_UNDER_SA_H(unsigned short v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_RRM_H(unsigned char v1, short v2, short v3, short v4, short v5, short v6, char v7);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_RRM_OC_TIME_OUT_H(unsigned char v1, short v2, long v3);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_NE_H(unsigned char v1, char v2, char v3, char v4, char v5, unsigned char v6, char v7);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_MD_H(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_FWSSD_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_RRM_IMC_ICC_ERROR_H(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_DMRS_HW_ISSUE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_RRM_SELF_SCHEDULE_H(void);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_MD_FORCE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_SD_FORCE_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_PMCH_H(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_RLM_DBG_INFO_H(unsigned short v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_RLM_DBG_INFO2_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_VZW_MEAS_H(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_VZW_MEAS_ERROR_H(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_RX0_DRPT_INNER_IS_STATIC_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RX0_DCMD_NVRAM_INFO_H(unsigned short v1);

void Set_EL1D_RX0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_RX0()	(EL1D_RX0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_M()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_L()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_SYNC_H()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_SYNC_M()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_SYNC_L()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_M()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_L()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_M()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_L()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_EVENT_H()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_EVENT_M()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_EVENT_L()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_M()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_L()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_RPT_H()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_RPT_M()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_RPT_L()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_M()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_L()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_M()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_L()	(ChkL1ModFltr_EL1D_RX0()&&((EL1D_RX0_Trace_Filter[4]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_REF_CELL_CHG_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SRV_CELL_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_REF_CELL_TIME_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_NBR_CELL_TIME_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_NBR_CELL_TIME_BY_EL1C_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_NBR_CELL_TIME_MISMATCH_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_CC_STATE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_CELL_INFO_CHG_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SRV_NBR_CHANGE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SCELL_ADD_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SCELL_DELETE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SCELL_ACTIVATE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SCELL_DEACTIVATE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_FORCE_PDSCH_IN_MBSFN_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_MBSFN_CONFIG_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_RRC_CONFIG_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_RRC_CONFIG_SCELL_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_TDD_AND_UL_BW_CONFIG_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_NOTIFY_DCTG_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_POST_HANDLER_TRACE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_POST_TIME_CRITICAL_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_PI_LPWR_MODE_GEAR_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_LOCK_SLEEP_MODE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_UNLOCK_SLEEP_MODE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SLEEP_LOCK_REASON_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_RXTDB_SRAM_STILL_LOCK_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SET_RXTDB_SRAM_POWER_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_NOTIFY_CIDD_DONE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_CIDD_MOD_BMP_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_FORCE_RXD_MOD_BMP_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_M()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_FORCE_RXD_BY_CM_BW_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_M()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_PSYNC_ABORT_DELAY_UPDATE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_BOOT_RAT_CHG_DONE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SET_DVFS_RX_ON_OFF_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SET_DVFS_Inner_ON_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SET_DVFS_CSI_ON_OFF_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SET_DVFS_GEAR_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_DVFS_DEBUG1_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SLEEP_DURATION_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_ABS_TIME_NOT_MATCH_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_FORCE_DL_ANT_MASK_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_PHICH_DROP_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_WORST_CASE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_FSM_SET_RX_STATUS_FOR_TAS_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_SYNC_CC_STATE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_SYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_SYNC_CC_PRE_SYNC_EXE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_SYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_SYNC_CC_POS_PRE_SYNC_EXE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_SYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_SYNC_INVALID_LIGHT_SYNC_SF_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_SYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_SYNC_ERROR_HANDLING_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_SYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_IN_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_OUT_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_PARAM_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_M()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_WO_DATA_IN_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_WO_DATA_OUT_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_POS_IN_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_POS_OUT_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_MODE_PROGRESSIVE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_A_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_B_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_MODE_CRITERION_C_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_MODE_NO_PRE_SYNC1_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_MODE_NO_PRE_SYNC2_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_MODE_NOT_READY_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_CALC_MODE_NOT_DRX_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_SET_DUMP_ALLOWED_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_FORCE_FAST_MODE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_FORCE_PROGRESSIVE_MODE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_FORCE_NORMAL_MODE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_FORCE_NORMAL_LENGTH_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_FORCE_USING_RS_EN_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_FORCE_USING_RS_EN2_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_FORCE_NON_DUMP_BY_SNR_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_PSYNC_DRX_WAKE_UP_UPDATE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_PSYNC_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_PRE_CAL_RRC_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_PRE_CAL_MBSFN_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_PRE_CAL_PAGING_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_CAL_MEAS_SF_PATTERN_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_CAL_MBSFN_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_CAL_SF_INFO_FORCE_UL_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_RRC_CROSS_SCHEDULE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_SFBD_SF_DIFF_ABNORMAL_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_PCSI_MEAS_SET_L()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_CAL_HST_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_CAL_WORST_LEN_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_CAL_GENIE_PATTERN_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_PCSI_MEAS_SF_PATTERN_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_EL1C_HST_UPDATE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_INFO_HO_ENABLE_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_EVENT_EXPIRE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_EVENT_DL_SPS_EXPIRE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_INFO_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_RAT_CHG_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_TX_IND_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_DL_REL_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_DL_CHG_TAS_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_DL_CHG_CC0_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_DL_CHG_CC1_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_SCELL_ACT_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_SCELL_ACT_SYNC_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_SCELL_PSEUDO_ACT_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_PRE_SYNC_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_MAIN_CC0_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_MAIN_CC1_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_MAIN_NBR_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_PHICH_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_DL_SPS_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_POS_PRE_SYNC_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_DISABLE_TO_ENABLE_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_TASK_CONFIG_WITH_DL_CHG_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_MIB_PARAM_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_MIB_PARAM2_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_SI_PARAM_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_PI_PARAM_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_MBMS_PARAM_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_PCSI_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_NEIGH_CELL_CONFIG_PARSE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_VZW_TEST_REQ_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_VZW_SRV_MEAS_REQ_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_GET_CMD_BY_EL1C_ERROR_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_CMD_DISABLE_FAST_PSYNC_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_RPT_RLM_DBG_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_RPT_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_RRC_RECONFIG_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_CELL_RECONFIG_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_DSP_TICK_INNER_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_PMCH_CMD_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_RX_PATH_CMD_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_MIB_REQUEST_FAIL_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_CMD_BMP_WI_AFTER_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_M()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_RNTI_ENABLE_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_DL_HARQ_IS_DISABLED_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_WR_PI_DUMP_INFO_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_DUMP_BMP_INFO_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_LPWR_CTRL_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_WRITE_CSIF_CHG_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_WRITE_CMIF_CMD_INIT_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_DCI_QI_CHECK_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_CTRL_NE_CMD_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_INTRA_NBR_INFO_L()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_POS_REF_PDP_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_PCSI_CMD_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_CSI_CMD_L()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_CSI_LAST_TICK_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_CSI_RESET_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_PCSI_TXINFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_SET_Quantized_PCSI_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_MIB_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI_PDSCH_BMP_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI_C_RNTI_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI_CC0_TC_RNTI_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI_CC0_SPS_RNTI_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI_CC0_SPS_FALSE_ALARM_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI_M_RNTI_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI_ORDER_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI_CELL_TIME_MISMATCH_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI_MISS_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_CRC_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_CRC_C_TC_SPS_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_CRC_RA_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_CRC_SI_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_CRC_PI_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_CRC_DEBUG_INFO_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_CRC_DEBUG_INFO2_M()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_CRC_CELL_TIME_MISMATCH_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_CRC_C_TC_SPS_MISMATCH_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_PHICH_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI0_CSI_INVLD_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI0_CSI_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DCI0_SPS_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_RLM_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_RLM_FROM_NE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_RLM_UNDER_SA_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_RRM_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_M()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_RRM_OC_TIME_OUT_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_NE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_MD_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_FWSSD_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_RRM_IMC_ICC_ERROR_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_DMRS_HW_ISSUE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_RRM_SELF_SCHEDULE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_MD_FORCE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_SD_FORCE_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_PMCH_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_RLM_DBG_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_RLM_DBG_INFO2_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_L()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_VZW_MEAS_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_VZW_MEAS_ERROR_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DRPT_INNER_IS_STATIC_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_RX0_DCMD_NVRAM_INFO_H()	ChkL1ClsFltr_EL1D_RX0_EL1D_TRC_RX0_DSP_CMD_H()


#endif
