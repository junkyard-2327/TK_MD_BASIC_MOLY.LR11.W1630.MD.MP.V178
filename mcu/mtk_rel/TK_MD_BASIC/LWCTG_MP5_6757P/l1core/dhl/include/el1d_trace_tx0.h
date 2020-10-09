#ifndef L1TRC_EL1D_TX0_DEF_H
#define L1TRC_EL1D_TX0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_TX_CHANNEL(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_TX_SPECIAL_CASE(v1)  (unsigned char)(v1+9)
#define EL1D_TRC_STR_SCH_STATE(v1)  (unsigned char)(v1+20)
#define EL1D_TRC_STR_TX_TIMING_UPDATE_FSM(v1)  (unsigned char)(v1+22)
#define EL1D_TRC_STR_TIMING_ADJ_TYPE(v1)  (unsigned char)(v1+26)
#define EL1D_TRC_STR_TIMING_SRC(v1)  (unsigned char)(v1+29)
#define EL1D_TRC_STR_TX_CMD(v1)  (unsigned char)(v1+32)
#define EL1D_TRC_STR_PUCCH_FMT(v1)  (unsigned char)(v1+36)
#define EL1D_TRC_STR_HARQ_MOD(v1)  (unsigned char)(v1+44)
#define EL1D_TRC_STR_PUCCH_RES_IDX(v1)  (unsigned char)(v1+49)
#define EL1D_TRC_STR_SPECIAL_CASE(v1)  (unsigned char)(v1+54)
#define EL1D_TRC_STR_TDD_UDC(v1)  (unsigned char)(v1+65)
#define EL1D_TRC_STR_TDD_SSF(v1)  (unsigned char)(v1+74)
#define EL1D_TRC_STR_FRAME_TYPE(v1)  (unsigned char)(v1+86)
#define EL1D_TRC_STR_CP_TYPE(v1)  (unsigned char)(v1+88)
#define EL1D_TRC_STR_UL_DL_TYPE(v1)  (unsigned char)(v1+91)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_CMD_TX_EN(v1, v2, v3, v4, v5) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x003E, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_TX_CMD_TX_EN(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TX_CMD_TX_EN_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x003E, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_CMD_NRT_UPDATE() do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_CMD_NRT_UPDATE()
#endif
#define EL1D_TRC_TX_CMD_NRT_UPDATE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_CMD_TIMING_UPDATE(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x023E, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_CMD_TIMING_UPDATE(v1, v2, v3)
#endif
#define EL1D_TRC_TX_CMD_TIMING_UPDATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x023E, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_CH_BITMAP(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x033E, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_CH_BITMAP(v1, v2, v3)
#endif
#define EL1D_TRC_TX_CH_BITMAP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x033E, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_CUR_CH(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_CUR_CH(v1)
#endif
#define EL1D_TRC_TX_CUR_CH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_CMD_BITMAP(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x053E, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_TX_CMD_BITMAP(v1)
#endif
#define EL1D_TRC_TX_CMD_BITMAP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x053E, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_TIMING_UPDATE_FSM(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x063E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_TIMING_UPDATE_FSM(v1)
#endif
#define EL1D_TRC_TX_TIMING_UPDATE_FSM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x063E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_TIMING_SPECIAL(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x073E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_TIMING_SPECIAL(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_TIMING_SPECIAL_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x073E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_TARGET_TX_FBD(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x083E, (char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TX_TARGET_TX_FBD(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_TARGET_TX_FBD_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x083E, (char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_MAINTAIN_TIMGIN(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x093E, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TX_MAINTAIN_TIMGIN(v1, v2, v3)
#endif
#define EL1D_TRC_TX_MAINTAIN_TIMGIN_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x093E, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_RAR_MISMATCH(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A3E, (short)(v1)), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TX_RAR_MISMATCH(v1, v2, v3)
#endif
#define EL1D_TRC_TX_RAR_MISMATCH_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A3E, (short)(v1)), (long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_TIMGIN_ADJUST(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B3E, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_TX_TIMGIN_ADJUST(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_TIMGIN_ADJUST_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B3E, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_Cir_Info(v1, v2, v3, v4, v5) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C3E, (char)(v4), TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_TX_Cir_Info(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TX_Cir_Info_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C3E, (char)(v4), TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PRACH_INDEX(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D3E, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_TX_PRACH_INDEX(v1, v2)
#endif
#define EL1D_TRC_TX_PRACH_INDEX_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D3E, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUSCH_TPUT(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E3E, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_TPUT(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_PUSCH_TPUT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E3E, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUSCH_RM_CALC_IN(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F3E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_RM_CALC_IN(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUSCH_RM_CALC_IN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F3E, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUSCH_RM_CALC_OUT(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x103E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_RM_CALC_OUT(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUSCH_RM_CALC_OUT_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x103E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUSCH_RM_CALC_OUT_CODED(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x113E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_RM_CALC_OUT_CODED(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_PUSCH_RM_CALC_OUT_CODED_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x113E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUSCH_process_id_check(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x123E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_process_id_check(v1, v2)
#endif
#define EL1D_TRC_TX_PUSCH_process_id_check_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x123E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUSCH_HARQ_CTRL(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x133E, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_HARQ_CTRL(v1, v2)
#endif
#define EL1D_TRC_TX_PUSCH_HARQ_CTRL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x133E, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUSCH_HARQ_CONFIG(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x143E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_HARQ_CONFIG(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_TX_PUSCH_HARQ_CONFIG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x143E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUSCH_HARQ_NUM_CALC(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x153E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_HARQ_NUM_CALC(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUSCH_HARQ_NUM_CALC_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x153E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUSCH_HARQ_BUNDLE(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x163E, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_HARQ_BUNDLE(v1, v2)
#endif
#define EL1D_TRC_TX_PUSCH_HARQ_BUNDLE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x163E, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUSCH_HARQ_Multiplex(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x173E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_HARQ_Multiplex(v1)
#endif
#define EL1D_TRC_TX_PUSCH_HARQ_Multiplex_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x173E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUSCH_HARQ_FMT3_MISS_DETECT(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x183E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_HARQ_FMT3_MISS_DETECT(v1)
#endif
#define EL1D_TRC_TX_PUSCH_HARQ_FMT3_MISS_DETECT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x183E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUSCH_HARQ_1B_CS(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x193E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUSCH_HARQ_1B_CS(v1)
#endif
#define EL1D_TRC_TX_PUSCH_HARQ_1B_CS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x193E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUCCH_INFO(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A3E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_INFO(v1, v2)
#endif
#define EL1D_TRC_TX_PUCCH_INFO_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A3E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_PUCCH_RES_PRECALC_OUT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1B3E, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_RES_PRECALC_OUT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_TX_PUCCH_RES_PRECALC_OUT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1B3E, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUCCH_RES_CALC_OUT(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C3E, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_RES_CALC_OUT(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUCCH_RES_CALC_OUT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C3E, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUCCH_CSI_INFO(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D3E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_CSI_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_PUCCH_CSI_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D3E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUCCH_CALC_OUT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1E3E, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_CALC_OUT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_TX_PUCCH_CALC_OUT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1E3E, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_PUCCH_BUND_N_1(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F3E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_BUND_N_1(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUCCH_BUND_N_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F3E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_PUCCH_MULTI_N_1(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x203E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_MULTI_N_1(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUCCH_MULTI_N_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x203E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_PUCCH_FDD_N_1(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x213E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_FDD_N_1(v1, v2)
#endif
#define EL1D_TRC_TX_PUCCH_FDD_N_1_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x213E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_PUCCH_FMT3_TDD_M1_N_1(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x223E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_FMT3_TDD_M1_N_1(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUCCH_FMT3_TDD_M1_N_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x223E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_PUCCH_FMT3_TDD_M2_N_1(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x233E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_FMT3_TDD_M2_N_1(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUCCH_FMT3_TDD_M2_N_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x233E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_PUCCH_1BCS_M1_N_1(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x243E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_1BCS_M1_N_1(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUCCH_1BCS_M1_N_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x243E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_PUCCH_1BCS_M2_N_1(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x253E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_1BCS_M2_N_1(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUCCH_1BCS_M2_N_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x253E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_PUCCH_1BCS_M34_N_1(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x263E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_1BCS_M34_N_1(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUCCH_1BCS_M34_N_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x263E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUCCH_HARQ_CTRL(v1, v2, v3, v4, v5) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x273E, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_HARQ_CTRL(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TX_PUCCH_HARQ_CTRL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x273E, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUCCH_HARQ_CONFIG(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x283E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_HARQ_CONFIG(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_TX_PUCCH_HARQ_CONFIG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x283E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUCCH_M_VALUE(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x293E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_M_VALUE(v1, v2, v3)
#endif
#define EL1D_TRC_TX_PUCCH_M_VALUE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x293E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUCCH_HARQ_BUNDLE(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A3E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_HARQ_BUNDLE(v1, v2)
#endif
#define EL1D_TRC_TX_PUCCH_HARQ_BUNDLE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A3E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUCCH_HARQ_Multiplex(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B3E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_HARQ_Multiplex(v1, v2)
#endif
#define EL1D_TRC_TX_PUCCH_HARQ_Multiplex_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B3E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUCCH_HARQ_FMT3(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C3E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_HARQ_FMT3(v1)
#endif
#define EL1D_TRC_TX_PUCCH_HARQ_FMT3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C3E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUCCH_HARQ_FMT3_TDD_fmt_1_2(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D3E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_HARQ_FMT3_TDD_fmt_1_2(v1, v2)
#endif
#define EL1D_TRC_TX_PUCCH_HARQ_FMT3_TDD_fmt_1_2_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D3E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUCCH_HARQ_1B_CS_GETMUX(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E3E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_HARQ_1B_CS_GETMUX(v1)
#endif
#define EL1D_TRC_TX_PUCCH_HARQ_1B_CS_GETMUX_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E3E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUCCH_HARQ_1B_CS(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F3E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_HARQ_1B_CS(v1, v2)
#endif
#define EL1D_TRC_TX_PUCCH_HARQ_1B_CS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F3E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUCCH_HARQ_REP() do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x303E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUCCH_HARQ_REP()
#endif
#define EL1D_TRC_TX_PUCCH_HARQ_REP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x303E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_SRS_ENCODER(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x313E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_SRS_ENCODER(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_SRS_ENCODER_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x313E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_SRS_RESERVED() do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x323E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_SRS_RESERVED()
#endif
#define EL1D_TRC_TX_SRS_RESERVED_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x323E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_SRS_HWCTRL(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x333E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_TX_SRS_HWCTRL(v1, v2)
#endif
#define EL1D_TRC_TX_SRS_HWCTRL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x333E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_GET_CRC(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x343E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TX_GET_CRC(v1, v2, v3)
#endif
#define EL1D_TRC_TX_GET_CRC_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x343E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_PUT_CRC(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x353E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUT_CRC(v1)
#endif
#define EL1D_TRC_TX_PUT_CRC_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x353E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_GET_CSI(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x363E, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_GET_CSI(v1, v2)
#endif
#define EL1D_TRC_TX_GET_CSI_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x363E, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUT_CSI(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x373E, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUT_CSI(v1, v2)
#endif
#define EL1D_TRC_TX_PUT_CSI_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x373E, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_GET_DCI(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x383E, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_GET_DCI(v1, v2, v3)
#endif
#define EL1D_TRC_TX_GET_DCI_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x383E, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUT_DCI(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x393E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUT_DCI(v1)
#endif
#define EL1D_TRC_TX_PUT_DCI_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x393E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_TPC(v1, v2, v3, v4, v5) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3A3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_TX_TPC(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TX_TPC_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3A3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_UL_BIAS(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3B3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_UL_BIAS(v1)
#endif
#define EL1D_TRC_TX_UL_BIAS_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3B3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_TICK_TIME(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_TICK_TIME(v1)
#endif
#define EL1D_TRC_TX_TICK_TIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_FDCTL_TIME(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3D3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_FDCTL_TIME(v1)
#endif
#define EL1D_TRC_TX_FDCTL_TIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3D3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_TDCTL_TIME(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3E3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_TDCTL_TIME(v1)
#endif
#define EL1D_TRC_TX_TDCTL_TIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3E3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_LMAC(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3F3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TX_LMAC(v1, v2)
#endif
#define EL1D_TRC_TX_LMAC_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3F3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LMAC_MDDBGMON(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x403E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_LMAC_MDDBGMON(v1)
#endif
#define EL1D_TRC_LMAC_MDDBGMON_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x403E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LMAC_L2MISC(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x413E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_LMAC_L2MISC(v1)
#endif
#define EL1D_TRC_LMAC_L2MISC_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x413E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_ASSERT_TIME(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x423E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_ASSERT_TIME(v1)
#endif
#define EL1D_TRC_TX_ASSERT_TIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x423E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_ENC_HWCR(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x433E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TX_ENC_HWCR(v1, v2)
#endif
#define EL1D_TRC_TX_ENC_HWCR_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x433E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_MSG4_ACK_ADD() do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x443E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_MSG4_ACK_ADD()
#endif
#define EL1D_TRC_TX_MSG4_ACK_ADD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x443E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_SPECIAL_CASE(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x453E, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TX_SPECIAL_CASE(v1, v2)
#endif
#define EL1D_TRC_TX_SPECIAL_CASE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x453E, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_T_TICK_START() do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x463E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_T_TICK_START()
#endif
#define EL1D_TRC_TX_T_TICK_START_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x463E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_T_TICK_END() do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x473E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_T_TICK_END()
#endif
#define EL1D_TRC_TX_T_TICK_END_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x473E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_SLEEP_LOCK_STATUS(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x483E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_SLEEP_LOCK_STATUS(v1)
#endif
#define EL1D_TRC_TX_SLEEP_LOCK_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x483E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_TPC_DFE_STATUS(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x493E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TX_TPC_DFE_STATUS(v1, v2)
#endif
#define EL1D_TRC_TX_TPC_DFE_STATUS_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x493E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_DFE_READY_BIT_1(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_DFE_READY_BIT_1(v1)
#endif
#define EL1D_TRC_TX_DFE_READY_BIT_1_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_DFE_READY_BIT_2(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4B3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_DFE_READY_BIT_2(v1)
#endif
#define EL1D_TRC_TX_DFE_READY_BIT_2_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4B3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TX_NRT_VALUE_SAME() do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_NRT_VALUE_SAME()
#endif
#define EL1D_TRC_TX_NRT_VALUE_SAME_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_TM_CHANGE() do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_TM_CHANGE()
#endif
#define EL1D_TRC_TX_TM_CHANGE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_RPT_CSI() do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_RPT_CSI()
#endif
#define EL1D_TRC_TX_RPT_CSI_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TX_PUXCH_LAST_SYMBOL_MASK(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F3E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_PUXCH_LAST_SYMBOL_MASK(v1)
#endif
#define EL1D_TRC_TX_PUXCH_LAST_SYMBOL_MASK_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F3E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_WARNING(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x503E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TX_WARNING(v1)
#endif
#define EL1D_TRC_TX_WARNING_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x503E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_GET_DL_HARQ_RUL(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x513E, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_TX_GET_DL_HARQ_RUL(v1)
#endif
#define EL1D_TRC_TX_GET_DL_HARQ_RUL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x513E, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_GET_DL_TB_HARQ_RUL(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x523E, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_TX_GET_DL_TB_HARQ_RUL(v1)
#endif
#define EL1D_TRC_TX_GET_DL_TB_HARQ_RUL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x523E, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_NRT_PUCCH_CS(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x533E, (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_NRT_PUCCH_CS(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_NRT_PUCCH_CS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x533E, (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_NRT_SR_CONFIG(v1) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x543E, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_TX_NRT_SR_CONFIG(v1)
#endif
#define EL1D_TRC_TX_NRT_SR_CONFIG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x543E, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_NRT_PUSCH_UES_R11(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x553E, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_NRT_PUSCH_UES_R11(v1, v2, v3)
#endif
#define EL1D_TRC_TX_NRT_PUSCH_UES_R11_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x553E, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_NRT_PUCCH_UES(v1, v2) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x563E, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_NRT_PUCCH_UES(v1, v2)
#endif
#define EL1D_TRC_TX_NRT_PUCCH_UES_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x563E, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_NRT_PUCCH_UES_R11(v1, v2, v3) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x573E, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_NRT_PUCCH_UES_R11(v1, v2, v3)
#endif
#define EL1D_TRC_TX_NRT_PUCCH_UES_R11_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x573E, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_NRT_PUCCH_CS1_LIST(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x583E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_NRT_PUCCH_CS1_LIST(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_NRT_PUCCH_CS1_LIST_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x583E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_NRT_PUCCH_CS0_LIST(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x593E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_NRT_PUCCH_CS0_LIST(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_NRT_PUCCH_CS0_LIST_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x593E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_NRT_PUCCH_FMT3_LIST(v1, v2, v3, v4) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5A3E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TX_NRT_PUCCH_FMT3_LIST(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TX_NRT_PUCCH_FMT3_LIST_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5A3E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TX_NRT_TDD_INFO(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_TX0_Trace_Filter[0]==1 && (EL1D_TX0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5B3E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_TX_NRT_TDD_INFO(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_TX_NRT_TDD_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5B3E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v8))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_TX0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_TX_CMD_TX_EN(unsigned char v1, unsigned char v2, short v3, char v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_TX_CMD_NRT_UPDATE(void);
void L1TRC_Send_EL1D_TRC_TX_CMD_TIMING_UPDATE(short v1, unsigned char v2, short v3);
void L1TRC_Send_EL1D_TRC_TX_CH_BITMAP(unsigned short v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TX_CUR_CH(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TX_CMD_BITMAP(unsigned short v1);
void L1TRC_Send_EL1D_TRC_TX_TIMING_UPDATE_FSM(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TX_TIMING_SPECIAL(char v1, char v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_TX_TARGET_TX_FBD(unsigned long v1, unsigned long v2, long v3, char v4);
void L1TRC_Send_EL1D_TRC_TX_MAINTAIN_TIMGIN(unsigned long v1, long v2, char v3);
void L1TRC_Send_EL1D_TRC_TX_RAR_MISMATCH(short v1, long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TX_TIMGIN_ADJUST(char v1, short v2, char v3, short v4);
void L1TRC_Send_EL1D_TRC_TX_Cir_Info(long v1, unsigned long v2, unsigned long v3, char v4, long v5);
void L1TRC_Send_EL1D_TRC_TX_PRACH_INDEX(char v1, char v2);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_TPUT(short v1, char v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_RM_CALC_IN(char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_RM_CALC_OUT(long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_RM_CALC_OUT_CODED(long v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_process_id_check(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_HARQ_CTRL(char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_HARQ_CONFIG(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_HARQ_NUM_CALC(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_HARQ_BUNDLE(unsigned long v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_HARQ_Multiplex(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_HARQ_FMT3_MISS_DETECT(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TX_PUSCH_HARQ_1B_CS(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_INFO(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_RES_PRECALC_OUT(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_RES_CALC_OUT(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_CSI_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_CALC_OUT(unsigned short v1, unsigned short v2, unsigned short v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_BUND_N_1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_MULTI_N_1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_FDD_N_1(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_FMT3_TDD_M1_N_1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_FMT3_TDD_M2_N_1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_1BCS_M1_N_1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_1BCS_M2_N_1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_1BCS_M34_N_1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_HARQ_CTRL(unsigned char v1, unsigned long v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_HARQ_CONFIG(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_M_VALUE(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_HARQ_BUNDLE(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_HARQ_Multiplex(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_HARQ_FMT3(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_HARQ_FMT3_TDD_fmt_1_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_HARQ_1B_CS_GETMUX(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_HARQ_1B_CS(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TX_PUCCH_HARQ_REP(void);
void L1TRC_Send_EL1D_TRC_TX_SRS_ENCODER(unsigned char v1, unsigned char v2, unsigned char v3, char v4);
void L1TRC_Send_EL1D_TRC_TX_SRS_RESERVED(void);
void L1TRC_Send_EL1D_TRC_TX_SRS_HWCTRL(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TX_GET_CRC(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TX_PUT_CRC(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_GET_CSI(unsigned long v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TX_PUT_CSI(unsigned long v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TX_GET_DCI(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_TX_PUT_DCI(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_TPC(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_TX_UL_BIAS(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_TICK_TIME(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_FDCTL_TIME(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_TDCTL_TIME(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_LMAC(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_LMAC_MDDBGMON(unsigned long v1);
void L1TRC_Send_EL1D_TRC_LMAC_L2MISC(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_ASSERT_TIME(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_ENC_HWCR(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TX_MSG4_ACK_ADD(void);
void L1TRC_Send_EL1D_TRC_TX_SPECIAL_CASE(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TX_T_TICK_START(void);
void L1TRC_Send_EL1D_TRC_TX_T_TICK_END(void);
void L1TRC_Send_EL1D_TRC_TX_SLEEP_LOCK_STATUS(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TX_TPC_DFE_STATUS(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TX_DFE_READY_BIT_1(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_DFE_READY_BIT_2(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_NRT_VALUE_SAME(void);
void L1TRC_Send_EL1D_TRC_TX_TM_CHANGE(void);
void L1TRC_Send_EL1D_TRC_TX_RPT_CSI(void);
void L1TRC_Send_EL1D_TRC_TX_PUXCH_LAST_SYMBOL_MASK(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TX_WARNING(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TX_GET_DL_HARQ_RUL(unsigned short v1);
void L1TRC_Send_EL1D_TRC_TX_GET_DL_TB_HARQ_RUL(unsigned short v1);
void L1TRC_Send_EL1D_TRC_TX_NRT_PUCCH_CS(char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_TX_NRT_SR_CONFIG(short v1);
void L1TRC_Send_EL1D_TRC_TX_NRT_PUSCH_UES_R11(char v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_TX_NRT_PUCCH_UES(char v1, short v2);
void L1TRC_Send_EL1D_TRC_TX_NRT_PUCCH_UES_R11(char v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_TX_NRT_PUCCH_CS1_LIST(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_TX_NRT_PUCCH_CS0_LIST(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_TX_NRT_PUCCH_FMT3_LIST(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_TX_NRT_TDD_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned long v8);

void Set_EL1D_TX0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_TX0()	(EL1D_TX0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()	(ChkL1ModFltr_EL1D_TX0()&&((EL1D_TX0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()	(ChkL1ModFltr_EL1D_TX0()&&((EL1D_TX0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()	(ChkL1ModFltr_EL1D_TX0()&&((EL1D_TX0_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_TX_CMD_TX_EN()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_CMD_NRT_UPDATE()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_CMD_TIMING_UPDATE()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_CH_BITMAP()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_CUR_CH()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_CMD_BITMAP()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_TIMING_UPDATE_FSM()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_TIMING_SPECIAL()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_TARGET_TX_FBD()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_MAINTAIN_TIMGIN()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_RAR_MISMATCH()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_TIMGIN_ADJUST()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_Cir_Info()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PRACH_INDEX()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_TPUT()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_RM_CALC_IN()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_RM_CALC_OUT()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_RM_CALC_OUT_CODED()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_process_id_check()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_HARQ_CTRL()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_HARQ_CONFIG()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_HARQ_NUM_CALC()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_HARQ_BUNDLE()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_HARQ_Multiplex()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_HARQ_FMT3_MISS_DETECT()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUSCH_HARQ_1B_CS()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_INFO()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_RES_PRECALC_OUT()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_RES_CALC_OUT()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_CSI_INFO()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_CALC_OUT()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_BUND_N_1()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_MULTI_N_1()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_FDD_N_1()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_FMT3_TDD_M1_N_1()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_FMT3_TDD_M2_N_1()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_1BCS_M1_N_1()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_1BCS_M2_N_1()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_1BCS_M34_N_1()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_HARQ_CTRL()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_HARQ_CONFIG()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_M_VALUE()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_HARQ_BUNDLE()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_HARQ_Multiplex()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_HARQ_FMT3()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_HARQ_FMT3_TDD_fmt_1_2()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_HARQ_1B_CS_GETMUX()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_HARQ_1B_CS()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUCCH_HARQ_REP()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_SRS_ENCODER()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_SRS_RESERVED()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_SRS_HWCTRL()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_GET_CRC()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUT_CRC()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_GET_CSI()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUT_CSI()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_GET_DCI()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUT_DCI()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_TPC()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_UL_BIAS()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_TICK_TIME()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_FDCTL_TIME()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_TDCTL_TIME()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_LMAC()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_LMAC_MDDBGMON()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_LMAC_L2MISC()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_ASSERT_TIME()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_ENC_HWCR()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_MSG4_ACK_ADD()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_SPECIAL_CASE()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_T_TICK_START()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_T_TICK_END()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_SLEEP_LOCK_STATUS()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_TPC_DFE_STATUS()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_DFE_READY_BIT_1()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_DFE_READY_BIT_2()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_NRT_VALUE_SAME()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_L()
#define ChkL1MsgFltr_EL1D_TRC_TX_TM_CHANGE()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_RPT_CSI()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_PUXCH_LAST_SYMBOL_MASK()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_H()
#define ChkL1MsgFltr_EL1D_TRC_TX_WARNING()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_GET_DL_HARQ_RUL()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_GET_DL_TB_HARQ_RUL()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_NRT_PUCCH_CS()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_NRT_SR_CONFIG()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_NRT_PUSCH_UES_R11()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_NRT_PUCCH_UES()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_NRT_PUCCH_UES_R11()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_NRT_PUCCH_CS1_LIST()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_NRT_PUCCH_CS0_LIST()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_NRT_PUCCH_FMT3_LIST()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()
#define ChkL1MsgFltr_EL1D_TRC_TX_NRT_TDD_INFO()	ChkL1ClsFltr_EL1D_TX0_EL1D_TRC_CLS_TX_M()


#endif
