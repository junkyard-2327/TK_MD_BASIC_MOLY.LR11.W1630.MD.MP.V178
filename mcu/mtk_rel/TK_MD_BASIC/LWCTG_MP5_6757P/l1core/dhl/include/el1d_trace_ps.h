#ifndef L1TRC_EL1D_PS_DEF_H
#define L1TRC_EL1D_PS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_PS_FSM_STATE(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_PS_AGC_CONFIG(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_MAIN_INIT_H(v1, v2) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0036, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_PS_MAIN_INIT_H(v1, v2)
#endif
#define EL1D_TRC_PS_MAIN_INIT_H_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0036, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_MAIN_TIMER_H() do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0136, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_MAIN_TIMER_H()
#endif
#define EL1D_TRC_PS_MAIN_TIMER_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0136, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_MAIN_ENTRY_H() do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0236, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_MAIN_ENTRY_H()
#endif
#define EL1D_TRC_PS_MAIN_ENTRY_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0236, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_FSM_SWITCH_H(v1, v2, v3) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0336, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_FSM_SWITCH_H(v1, v2, v3)
#endif
#define EL1D_TRC_PS_FSM_SWITCH_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0336, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_FSM_HANDLER_H(v1, v2, v3) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0436, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_FSM_HANDLER_H(v1, v2, v3)
#endif
#define EL1D_TRC_PS_FSM_HANDLER_H_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0436, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_CMD_REQ_PRE_PROCESS_H(v1, v2) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0536, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_CMD_REQ_PRE_PROCESS_H(v1, v2)
#endif
#define EL1D_TRC_PS_CMD_REQ_PRE_PROCESS_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0536, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_CMD_ABORT_PRE_PROCESS_H() do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0636, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_CMD_ABORT_PRE_PROCESS_H()
#endif
#define EL1D_TRC_PS_CMD_ABORT_PRE_PROCESS_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0636, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_CMD_REQ_INFO1_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0736, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_CMD_REQ_INFO1_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_PS_CMD_REQ_INFO1_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0736, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_CMD_REQ_INFO2_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0836, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_PS_CMD_REQ_INFO2_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_PS_CMD_REQ_INFO2_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0836, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_RPT_ABORT_SUCCESS_H(v1, v2, v3, v4) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0936, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_RPT_ABORT_SUCCESS_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_PS_RPT_ABORT_SUCCESS_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0936, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_RPT_ABORT_NO_NEED_H() do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A36, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_RPT_ABORT_NO_NEED_H()
#endif
#define EL1D_TRC_PS_RPT_ABORT_NO_NEED_H_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A36, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_RPT_RESULT_FROM_AGC_H(v1, v2, v3, v4, v5) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B36, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define EL1D_TRC_PS_RPT_RESULT_FROM_AGC_H(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_PS_RPT_RESULT_FROM_AGC_H_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B36, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_RPT_RESULT_TO_L1C_H(v1, v2) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C36, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_RPT_RESULT_TO_L1C_H(v1, v2)
#endif
#define EL1D_TRC_PS_RPT_RESULT_TO_L1C_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C36, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_RF_ON_H(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0D36, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (unsigned short)(v7)), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_PS_RF_ON_H(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_PS_RF_ON_H_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0D36, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (unsigned short)(v7)), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_RF_OFF_H(v1, v2, v3, v4) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E36, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_PS_RF_OFF_H(v1, v2, v3, v4)
#endif
#define EL1D_TRC_PS_RF_OFF_H_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E36, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PS_AGC_CONFIG_H(v1, v2) do {\
		if(EL1D_PS_Trace_Filter[0]==1 && (EL1D_PS_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F36, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PS_AGC_CONFIG_H(v1, v2)
#endif
#define EL1D_TRC_PS_AGC_CONFIG_H_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F36, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_PS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_PS_MAIN_INIT_H(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_PS_MAIN_TIMER_H(void);
void L1TRC_Send_EL1D_TRC_PS_MAIN_ENTRY_H(void);
void L1TRC_Send_EL1D_TRC_PS_FSM_SWITCH_H(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_PS_FSM_HANDLER_H(short v1, unsigned char v2, short v3);
void L1TRC_Send_EL1D_TRC_PS_CMD_REQ_PRE_PROCESS_H(short v1, short v2);
void L1TRC_Send_EL1D_TRC_PS_CMD_ABORT_PRE_PROCESS_H(void);
void L1TRC_Send_EL1D_TRC_PS_CMD_REQ_INFO1_H(short v1, unsigned char v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_PS_CMD_REQ_INFO2_H(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_PS_RPT_ABORT_SUCCESS_H(short v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_PS_RPT_ABORT_NO_NEED_H(void);
void L1TRC_Send_EL1D_TRC_PS_RPT_RESULT_FROM_AGC_H(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_EL1D_TRC_PS_RPT_RESULT_TO_L1C_H(short v1, short v2);
void L1TRC_Send_EL1D_TRC_PS_RF_ON_H(short v1, short v2, short v3, short v4, short v5, short v6, unsigned short v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_PS_RF_OFF_H(short v1, short v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_PS_AGC_CONFIG_H(short v1, unsigned char v2);

void Set_EL1D_PS_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_PS()	(EL1D_PS_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_MAIN_H()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_MAIN_M()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_MAIN_L()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_FSM_H()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_FSM_M()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_FSM_L()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_CMD_H()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_CMD_M()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_CMD_L()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RPT_H()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RPT_M()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RPT_L()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RF_H()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RF_M()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RF_L()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_AGC_H()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_AGC_M()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_AGC_L()	(ChkL1ModFltr_EL1D_PS()&&((EL1D_PS_Trace_Filter[3]&0x02)!=0))
#define ChkL1MsgFltr_EL1D_TRC_PS_MAIN_INIT_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_MAIN_TIMER_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_MAIN_ENTRY_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_FSM_SWITCH_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_FSM_HANDLER_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_FSM_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_CMD_REQ_PRE_PROCESS_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_CMD_ABORT_PRE_PROCESS_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_CMD_REQ_INFO1_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_CMD_REQ_INFO2_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_CMD_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_RPT_ABORT_SUCCESS_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_RPT_ABORT_NO_NEED_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_RPT_RESULT_FROM_AGC_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_RPT_RESULT_TO_L1C_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RPT_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_RF_ON_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_RF_OFF_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_RF_H()
#define ChkL1MsgFltr_EL1D_TRC_PS_AGC_CONFIG_H()	ChkL1ClsFltr_EL1D_PS_EL1D_TRC_PS_AGC_H()


#endif
