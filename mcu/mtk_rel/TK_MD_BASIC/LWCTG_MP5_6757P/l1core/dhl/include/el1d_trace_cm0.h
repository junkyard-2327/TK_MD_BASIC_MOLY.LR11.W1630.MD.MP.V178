#ifndef L1TRC_EL1D_CM0_DEF_H
#define L1TRC_EL1D_CM0_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_INTERNAL_DUMP_BITMAP_H(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x002E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_INTERNAL_DUMP_BITMAP_H(v1)
#endif
#define EL1D_TRC_CM0_INTERNAL_DUMP_BITMAP_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x002E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_NBR_CONTROL_INFO_H(v1, v2, v3, v4) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x012E, (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CM0_NBR_CONTROL_INFO_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM0_NBR_CONTROL_INFO_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x012E, (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_NBR_CELL_INFO_SET_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x022E, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_NBR_CELL_INFO_SET_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_CM0_NBR_CELL_INFO_SET_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x022E, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_INTERNAL_REDUCE_CELL_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x032E, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_CM0_INTERNAL_REDUCE_CELL_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_INTERNAL_REDUCE_CELL_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x032E, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_1MS_AFIFO_ON_OFF_CTRL_H(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x042E, (char)(v5), (char)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_CM0_1MS_AFIFO_ON_OFF_CTRL_H(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_CM0_1MS_AFIFO_ON_OFF_CTRL_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x042E, (char)(v5), (char)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_1MS_DFE_BITMAP_H(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x052E, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_CM0_1MS_DFE_BITMAP_H(v1)
#endif
#define EL1D_TRC_CM0_1MS_DFE_BITMAP_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x052E, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_CELL_ON_OFF_TIME_L(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x062E, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_CM0_CELL_ON_OFF_TIME_L(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_CM0_CELL_ON_OFF_TIME_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x062E, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_TDD_FDD_CHECK_L(v1, v2, v3, v4) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x072E, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_TDD_FDD_CHECK_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM0_TDD_FDD_CHECK_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x072E, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RESTRICTION_PAT_CHK_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x082E, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RESTRICTION_PAT_CHK_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_RESTRICTION_PAT_CHK_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x082E, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_MBSFN_CHECK_L(v1, v2, v3, v4) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x092E, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_MBSFN_CHECK_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM0_MBSFN_CHECK_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x092E, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_MBSFN_CHECK_WITH_NCCF_L(v1, v2, v3, v4) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A2E, (short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_MBSFN_CHECK_WITH_NCCF_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM0_MBSFN_CHECK_WITH_NCCF_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A2E, (short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RS_POS_TIME_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B2E, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), (unsigned char)(v6)));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RS_POS_TIME_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CM0_RS_POS_TIME_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B2E, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RS_POS_TIME_FOR_RSSI_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C2E, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RS_POS_TIME_FOR_RSSI_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_RS_POS_TIME_FOR_RSSI_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C2E, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_NBR_SCELL_CHANGE_H(v1, v2, v3, v4) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D2E, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_NBR_SCELL_CHANGE_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM0_NBR_SCELL_CHANGE_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D2E, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RS_COFFT_RS_CUT_H(v1, v2, v3) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E2E, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RS_COFFT_RS_CUT_H(v1, v2, v3)
#endif
#define EL1D_TRC_CM0_RS_COFFT_RS_CUT_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E2E, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_NBR_SCELL_ACTIVATE_H(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F2E, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_NBR_SCELL_ACTIVATE_H(v1)
#endif
#define EL1D_TRC_CM0_NBR_SCELL_ACTIVATE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F2E, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_SRAM_OFF_H(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x102E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_SRAM_OFF_H(v1)
#endif
#define EL1D_TRC_CM0_SRAM_OFF_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x102E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_NBR_ABORT_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x112E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_CM0_NBR_ABORT_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_NBR_ABORT_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x112E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_NEXT_SF_TICK_TRIG_H(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x122E, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CM0_NEXT_SF_TICK_TRIG_H(v1, v2)
#endif
#define EL1D_TRC_CM0_NEXT_SF_TICK_TRIG_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x122E, (char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_NBR_RESTRICTION_PAT_CHK_H(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x132E, (unsigned short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), (unsigned char)(v8), (char)(v9)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_CM0_NBR_RESTRICTION_PAT_CHK_H(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_CM0_NBR_RESTRICTION_PAT_CHK_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_6_DATA(TRC_MERGE_2S(0x132E, (unsigned short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), (unsigned char)(v8), (char)(v9)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_FSM_ENTER_NCM_STATE_H(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x142E, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_FSM_ENTER_NCM_STATE_H(v1)
#endif
#define EL1D_TRC_CM0_FSM_ENTER_NCM_STATE_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x142E, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_FSM_CHG_H(v1, v2, v3) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x152E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_FSM_CHG_H(v1, v2, v3)
#endif
#define EL1D_TRC_CM0_FSM_CHG_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x152E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_FSM_IDLE_STATE_CHK_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x162E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_FSM_IDLE_STATE_CHK_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_FSM_IDLE_STATE_CHK_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x162E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_FSM_ENTRY_L(v1, v2, v3, v4) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x172E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_CM0_FSM_ENTRY_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM0_FSM_ENTRY_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x172E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_CMD_HANDLER_OTHER_H(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x182E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CM0_CMD_HANDLER_OTHER_H(v1)
#endif
#define EL1D_TRC_CM0_CMD_HANDLER_OTHER_H_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x182E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_CMD_HANDLER_RP_H(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x192E, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CM0_CMD_HANDLER_RP_H(v1, v2)
#endif
#define EL1D_TRC_CM0_CMD_HANDLER_RP_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x192E, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_CMD_HANDLER_NORMAL_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A2E, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), (char)(v4), (char)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_CM0_CMD_HANDLER_NORMAL_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_CMD_HANDLER_NORMAL_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A2E, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), (unsigned char)(v3), (char)(v4), (char)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_MEAS_BW_CHANGE_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B2E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_MEAS_BW_CHANGE_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_MEAS_BW_CHANGE_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B2E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RPT_NBR_RX_PATH_H(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C2E, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RPT_NBR_RX_PATH_H(v1, v2)
#endif
#define EL1D_TRC_CM0_RPT_NBR_RX_PATH_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C2E, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RPT_NBR_RESULT_H(v1, v2, v3, v4) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D2E, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RPT_NBR_RESULT_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM0_RPT_NBR_RESULT_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D2E, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RPT_CM_DONE_H(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E2E, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RPT_CM_DONE_H(v1, v2)
#endif
#define EL1D_TRC_CM0_RPT_CM_DONE_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E2E, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RPT_ABT_H(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F2E, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RPT_ABT_H(v1, v2)
#endif
#define EL1D_TRC_CM0_RPT_ABT_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F2E, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RPT_EARLY_H(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x202E, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RPT_EARLY_H(v1)
#endif
#define EL1D_TRC_CM0_RPT_EARLY_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x202E, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RPT_READ_H(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x212E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RPT_READ_H(v1, v2)
#endif
#define EL1D_TRC_CM0_RPT_READ_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x212E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RPT_UPDATE_TIMING_CHECK_H(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x222E, (char)(v2), TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RPT_UPDATE_TIMING_CHECK_H(v1, v2)
#endif
#define EL1D_TRC_CM0_RPT_UPDATE_TIMING_CHECK_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x222E, (char)(v2), TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RPT_CELL_UPDATE_TIMING_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x232E, (short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_4C((char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RPT_CELL_UPDATE_TIMING_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_RPT_CELL_UPDATE_TIMING_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x232E, (short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_4C((char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RF_ON_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x242E, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RF_ON_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CM0_RF_ON_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x242E, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_RF_OFF_H(v1, v2, v3) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x252E, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RF_OFF_H(v1, v2, v3)
#endif
#define EL1D_TRC_CM0_RF_OFF_H_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x252E, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_CM0_RF_ON_MASK_M(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x262E, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_RF_ON_MASK_M(v1)
#endif
#define EL1D_TRC_CM0_RF_ON_MASK_M_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x262E, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_AGC_DUMP_GET_GAIN_H(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x272E, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CM0_AGC_DUMP_GET_GAIN_H(v1, v2)
#endif
#define EL1D_TRC_CM0_AGC_DUMP_GET_GAIN_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x272E, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_AGC_DUMP_CHANGE_OFST_DUR_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x282E, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_AGC_DUMP_CHANGE_OFST_DUR_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_AGC_DUMP_CHANGE_OFST_DUR_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x282E, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_AGC_DUMP_CHANGE_POINT_L(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x292E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_AGC_DUMP_CHANGE_POINT_L(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_CM0_AGC_DUMP_CHANGE_POINT_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x292E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_AGC_REF_MBSFN_JUDGE_L(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A2E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_AGC_REF_MBSFN_JUDGE_L(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_AGC_REF_MBSFN_JUDGE_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A2E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_AGC_REQ_L(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B2E, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM0_AGC_REQ_L(v1, v2)
#endif
#define EL1D_TRC_CM0_AGC_REQ_L_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B2E, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_AGC_SF_CONFIG_L(v1, v2, v3, v4) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2C2E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_CM0_AGC_SF_CONFIG_L(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CM0_AGC_SF_CONFIG_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2C2E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_AGC_GAIN_QUERY_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D2E, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM0_AGC_GAIN_QUERY_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_AGC_GAIN_QUERY_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D2E, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_DFE_BMP_QUERY_INTER_H(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E2E, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_DFE_BMP_QUERY_INTER_H(v1)
#endif
#define EL1D_TRC_CM0_DFE_BMP_QUERY_INTER_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E2E, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_DFE_BMP_QUERY_INTRA_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F2E, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CM0_DFE_BMP_QUERY_INTRA_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CM0_DFE_BMP_QUERY_INTRA_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F2E, (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_DFE_PATH_DELAY_H(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x302E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CM0_DFE_PATH_DELAY_H(v1)
#endif
#define EL1D_TRC_CM0_DFE_PATH_DELAY_H_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x302E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_DUMP_DONE_H(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x312E, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CM0_DUMP_DONE_H(v1, v2)
#endif
#define EL1D_TRC_CM0_DUMP_DONE_H_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x312E, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_DUMP_CTRL_H(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x322E, (char)(v1), (char)(v3)), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_CM0_DUMP_CTRL_H(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CM0_DUMP_CTRL_H_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x322E, (char)(v1), (char)(v3)), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CM0_DUMP_NBR_ABORT_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x332E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_CM0_DUMP_NBR_ABORT_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CM0_DUMP_NBR_ABORT_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x332E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_DUMP_DRAM_INIT_L(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x342E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM0_DUMP_DRAM_INIT_L(v1, v2)
#endif
#define EL1D_TRC_CM0_DUMP_DRAM_INIT_L_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x342E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_MDM_WRITE_L(v1) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x352E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_CM0_MDM_WRITE_L(v1)
#endif
#define EL1D_TRC_CM0_MDM_WRITE_L_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x352E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_CYCLE_CNT_L(v1, v2, v3) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x362E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_CM0_CYCLE_CNT_L(v1, v2, v3)
#endif
#define EL1D_TRC_CM0_CYCLE_CNT_L_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x362E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_CM0_ELM_L(v1, v2) do {\
		if(EL1D_CM0_Trace_Filter[0]==1 && (EL1D_CM0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x372E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_CM0_ELM_L(v1, v2)
#endif
#define EL1D_TRC_CM0_ELM_L_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x372E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_CM0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_CM0_INTERNAL_DUMP_BITMAP_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_CM0_NBR_CONTROL_INFO_H(char v1, char v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_CM0_NBR_CELL_INFO_SET_H(unsigned short v1, char v2, char v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_EL1D_TRC_CM0_INTERNAL_REDUCE_CELL_H(unsigned short v1, char v2, unsigned short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_CM0_1MS_AFIFO_ON_OFF_CTRL_H(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, char v5, char v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_CM0_1MS_DFE_BITMAP_H(unsigned short v1);
void L1TRC_Send_EL1D_TRC_CM0_CELL_ON_OFF_TIME_L(char v1, unsigned short v2, unsigned short v3, unsigned long v4, unsigned short v5, unsigned short v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_CM0_TDD_FDD_CHECK_L(char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_CM0_RESTRICTION_PAT_CHK_H(char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_CM0_MBSFN_CHECK_L(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_CM0_MBSFN_CHECK_WITH_NCCF_L(short v1, char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_CM0_RS_POS_TIME_H(char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_CM0_RS_POS_TIME_FOR_RSSI_H(char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1D_TRC_CM0_NBR_SCELL_CHANGE_H(char v1, char v2, unsigned short v3, char v4);
void L1TRC_Send_EL1D_TRC_CM0_RS_COFFT_RS_CUT_H(short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_CM0_NBR_SCELL_ACTIVATE_H(char v1);
void L1TRC_Send_EL1D_TRC_CM0_SRAM_OFF_H(unsigned char v1);
void L1TRC_Send_EL1D_TRC_CM0_NBR_ABORT_H(char v1, char v2, char v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_CM0_NEXT_SF_TICK_TRIG_H(unsigned long v1, char v2);
void L1TRC_Send_EL1D_TRC_CM0_NBR_RESTRICTION_PAT_CHK_H(char v1, char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned short v7, unsigned char v8, char v9);
void L1TRC_Send_EL1D_TRC_CM0_FSM_ENTER_NCM_STATE_H(char v1);
void L1TRC_Send_EL1D_TRC_CM0_FSM_CHG_H(char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_CM0_FSM_IDLE_STATE_CHK_H(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_CM0_FSM_ENTRY_L(char v1, char v2, char v3, long v4);
void L1TRC_Send_EL1D_TRC_CM0_CMD_HANDLER_OTHER_H(long v1);
void L1TRC_Send_EL1D_TRC_CM0_CMD_HANDLER_RP_H(long v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_CM0_CMD_HANDLER_NORMAL_H(char v1, unsigned short v2, unsigned char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_CM0_MEAS_BW_CHANGE_H(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_CM0_RPT_NBR_RX_PATH_H(char v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_CM0_RPT_NBR_RESULT_H(char v1, short v2, char v3, long v4);
void L1TRC_Send_EL1D_TRC_CM0_RPT_CM_DONE_H(char v1, char v2);
void L1TRC_Send_EL1D_TRC_CM0_RPT_ABT_H(char v1, char v2);
void L1TRC_Send_EL1D_TRC_CM0_RPT_EARLY_H(char v1);
void L1TRC_Send_EL1D_TRC_CM0_RPT_READ_H(long v1, long v2);
void L1TRC_Send_EL1D_TRC_CM0_RPT_UPDATE_TIMING_CHECK_H(long v1, char v2);
void L1TRC_Send_EL1D_TRC_CM0_RPT_CELL_UPDATE_TIMING_H(char v1, short v2, unsigned short v3, unsigned char v4, unsigned short v5);
void L1TRC_Send_EL1D_TRC_CM0_RF_ON_H(char v1, char v2, char v3, unsigned short v4, unsigned short v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_CM0_RF_OFF_H(char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_CM0_RF_ON_MASK_M(char v1);
void L1TRC_Send_EL1D_TRC_CM0_AGC_DUMP_GET_GAIN_H(char v1, char v2);
void L1TRC_Send_EL1D_TRC_CM0_AGC_DUMP_CHANGE_OFST_DUR_L(char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_CM0_AGC_DUMP_CHANGE_POINT_L(char v1, char v2, char v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_EL1D_TRC_CM0_AGC_REF_MBSFN_JUDGE_L(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_CM0_AGC_REQ_L(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CM0_AGC_SF_CONFIG_L(char v1, char v2, char v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_CM0_AGC_GAIN_QUERY_H(unsigned char v1, long v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1D_TRC_CM0_DFE_BMP_QUERY_INTER_H(char v1);
void L1TRC_Send_EL1D_TRC_CM0_DFE_BMP_QUERY_INTRA_H(char v1, char v2, char v3, char v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_EL1D_TRC_CM0_DFE_PATH_DELAY_H(unsigned long v1);
void L1TRC_Send_EL1D_TRC_CM0_DUMP_DONE_H(char v1, char v2);
void L1TRC_Send_EL1D_TRC_CM0_DUMP_CTRL_H(char v1, unsigned long v2, char v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_CM0_DUMP_NBR_ABORT_H(char v1, char v2, char v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_CM0_DUMP_DRAM_INIT_L(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_CM0_MDM_WRITE_L(unsigned long v1);
void L1TRC_Send_EL1D_TRC_CM0_CYCLE_CNT_L(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_CM0_ELM_L(unsigned long v1, unsigned long v2);

void Set_EL1D_CM0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_CM0()	(EL1D_CM0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_M()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_L()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_FSM_H()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_FSM_M()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_FSM_L()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_CMD_H()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_CMD_M()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_CMD_L()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_H()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_M()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_L()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RF_H()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RF_M()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RF_L()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AFIFO_H()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AFIFO_M()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AFIFO_L()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AGC_H()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AGC_M()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AGC_L()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DFE_H()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DFE_M()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DFE_L()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DUMP_H()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DUMP_M()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DUMP_L()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_UTIL_H()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_UTIL_M()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[4]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_UTIL_L()	(ChkL1ModFltr_EL1D_CM0()&&((EL1D_CM0_Trace_Filter[4]&0x20)!=0))
#define ChkL1MsgFltr_EL1D_TRC_CM0_INTERNAL_DUMP_BITMAP_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_NBR_CONTROL_INFO_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_NBR_CELL_INFO_SET_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_INTERNAL_REDUCE_CELL_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_1MS_AFIFO_ON_OFF_CTRL_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_1MS_DFE_BITMAP_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_CELL_ON_OFF_TIME_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_TDD_FDD_CHECK_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RESTRICTION_PAT_CHK_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_MBSFN_CHECK_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_MBSFN_CHECK_WITH_NCCF_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RS_POS_TIME_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RS_POS_TIME_FOR_RSSI_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_NBR_SCELL_CHANGE_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RS_COFFT_RS_CUT_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_NBR_SCELL_ACTIVATE_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_SRAM_OFF_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_NBR_ABORT_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_NEXT_SF_TICK_TRIG_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_NBR_RESTRICTION_PAT_CHK_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_FSM_ENTER_NCM_STATE_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_FSM_CHG_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_FSM_IDLE_STATE_CHK_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_FSM_ENTRY_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_FSM_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_CMD_HANDLER_OTHER_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_CMD_HANDLER_RP_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_CMD_HANDLER_NORMAL_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_MEAS_BW_CHANGE_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RPT_NBR_RX_PATH_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RPT_NBR_RESULT_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RPT_CM_DONE_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RPT_ABT_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RPT_EARLY_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RPT_READ_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RPT_UPDATE_TIMING_CHECK_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RPT_CELL_UPDATE_TIMING_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RF_ON_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RF_OFF_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_RF_ON_MASK_M()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RF_M()
#define ChkL1MsgFltr_EL1D_TRC_CM0_AGC_DUMP_GET_GAIN_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_AGC_DUMP_CHANGE_OFST_DUR_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AGC_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_AGC_DUMP_CHANGE_POINT_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AGC_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_AGC_REF_MBSFN_JUDGE_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AGC_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_AGC_REQ_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AGC_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_AGC_SF_CONFIG_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AGC_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_AGC_GAIN_QUERY_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_AGC_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_DFE_BMP_QUERY_INTER_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DFE_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_DFE_BMP_QUERY_INTRA_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DFE_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_DFE_PATH_DELAY_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DFE_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_DUMP_DONE_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_DUMP_CTRL_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_DUMP_NBR_ABORT_H()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DUMP_H()
#define ChkL1MsgFltr_EL1D_TRC_CM0_DUMP_DRAM_INIT_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_DUMP_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_MDM_WRITE_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_CYCLE_CNT_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RF_L()
#define ChkL1MsgFltr_EL1D_TRC_CM0_ELM_L()	ChkL1ClsFltr_EL1D_CM0_EL1D_TRC_CM0_RF_L()


#endif
