#ifndef L1TRC_LCORE_L1Audio_DEF_H
#define L1TRC_LCORE_L1Audio_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1AUDIO_Str_onoff(v1)  (unsigned char)(v1+0)
#define L1Audio_Speech_State_L(v1)  (unsigned char)(v1+2)
#define SAL_PROC_NAME(v1)  (unsigned char)(v1+6)
#define SAL_DSP_VALUE_NAME(v1)  (unsigned char)(v1+46)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_AudioManager_L(v1, v2, v3, v4) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x002D, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), (unsigned char)(v4)));\
	} while(0)
#else
	#define L1Audio_Msg_AM_AudioManager_L(v1, v2, v3, v4)
#endif
#define L1Audio_Msg_AM_AudioManager_L_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x002D, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_AudioManager2_L(v1, v2) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x012D, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1Audio_Msg_AM_AudioManager2_L(v1, v2)
#endif
#define L1Audio_Msg_AM_AudioManager2_L_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x012D, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_Handover(v1, v2) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x022D, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define L1Audio_Msg_AM_Handover(v1, v2)
#endif
#define L1Audio_Msg_AM_Handover_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x022D, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_AudioManagerInfo(v1, v2) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x032D, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define L1Audio_Msg_AM_AudioManagerInfo(v1, v2)
#endif
#define L1Audio_Msg_AM_AudioManagerInfo_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x032D, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_TCH_NOTIFY_L(v1, v2) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x042D, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1Audio_Msg_TCH_NOTIFY_L(v1, v2)
#endif
#define L1Audio_Msg_TCH_NOTIFY_L_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x042D, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_Speech_L(v1) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x052D, (short)(v1)));\
	} while(0)
#else
	#define L1Audio_Msg_AM_Speech_L(v1)
#endif
#define L1Audio_Msg_AM_Speech_L_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x052D, (short)(v1)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_PutQ_L(v1) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x062D, (short)(v1)));\
	} while(0)
#else
	#define L1Audio_Msg_PutQ_L(v1)
#endif
#define L1Audio_Msg_PutQ_L_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x062D, (short)(v1)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_GetQ_L(v1, v2, v3, v4, v5, v6, v7) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x072D, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define L1Audio_Msg_GetQ_L(v1, v2, v3, v4, v5, v6, v7)
#endif
#define L1Audio_Msg_GetQ_L_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x072D, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_SAL_SET_VALUE(v1, v2) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x082D, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1Audio_Msg_SAL_SET_VALUE(v1, v2)
#endif
#define L1Audio_Msg_SAL_SET_VALUE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x082D, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_SAL_SET_VALUE_MULTI(v1, v2, v3, v4, v5, v6) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x092D, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1Audio_Msg_SAL_SET_VALUE_MULTI(v1, v2, v3, v4, v5, v6)
#endif
#define L1Audio_Msg_SAL_SET_VALUE_MULTI_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x092D, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_SAL_PROC(v1, v2, v3, v4, v5) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A2D, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1Audio_Msg_SAL_PROC(v1, v2, v3, v4, v5)
#endif
#define L1Audio_Msg_SAL_PROC_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A2D, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_L1D_GetRF_L(v1) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B2D, (short)(v1)));\
	} while(0)
#else
	#define L1Audio_Msg_L1D_GetRF_L(v1)
#endif
#define L1Audio_Msg_L1D_GetRF_L_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B2D, (short)(v1)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_DELAY_TABLE(v1) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0C2D, (short)(v1)));\
	} while(0)
#else
	#define L1Audio_Msg_AM_DELAY_TABLE(v1)
#endif
#define L1Audio_Msg_AM_DELAY_TABLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0C2D, (short)(v1)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_VBI_RESET() do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1Audio_Msg_VBI_RESET()
#endif
#define L1Audio_Msg_VBI_RESET_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_VBI_END() do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1Audio_Msg_VBI_END()
#endif
#define L1Audio_Msg_VBI_END_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_SRC1(v1, v2, v3) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F2D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define L1Audio_Msg_AM_SRC1(v1, v2, v3)
#endif
#define L1Audio_Msg_AM_SRC1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F2D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_SRC2(v1, v2, v3) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x102D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define L1Audio_Msg_AM_SRC2(v1, v2, v3)
#endif
#define L1Audio_Msg_AM_SRC2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x102D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_3G_Reset_Time_Drift_L() do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x112D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1Audio_Msg_AM_3G_Reset_Time_Drift_L()
#endif
#define L1Audio_Msg_AM_3G_Reset_Time_Drift_L_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x112D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_L1D_Backup_L(v1, v2) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x122D, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1Audio_Msg_AM_L1D_Backup_L(v1, v2)
#endif
#define L1Audio_Msg_AM_L1D_Backup_L_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x122D, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_HandoverInfo_L(v1, v2, v3) do {\
		if(LCORE_L1Audio_Trace_Filter[0]==1 && (LCORE_L1Audio_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x132D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define L1Audio_Msg_AM_HandoverInfo_L(v1, v2, v3)
#endif
#define L1Audio_Msg_AM_HandoverInfo_L_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x132D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char LCORE_L1Audio_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1Audio_Msg_AM_AudioManager_L(short v1, char v2, short v3, unsigned char v4);
void L1TRC_Send_L1Audio_Msg_AM_AudioManager2_L(char v1, short v2);
void L1TRC_Send_L1Audio_Msg_AM_Handover(char v1, char v2);
void L1TRC_Send_L1Audio_Msg_AM_AudioManagerInfo(char v1, char v2);
void L1TRC_Send_L1Audio_Msg_TCH_NOTIFY_L(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_AM_Speech_L(short v1);
void L1TRC_Send_L1Audio_Msg_PutQ_L(short v1);
void L1TRC_Send_L1Audio_Msg_GetQ_L(unsigned short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_L1Audio_Msg_SAL_SET_VALUE(unsigned char v1, unsigned short v2);
void L1TRC_Send_L1Audio_Msg_SAL_SET_VALUE_MULTI(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_L1Audio_Msg_SAL_PROC(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_L1Audio_Msg_L1D_GetRF_L(short v1);
void L1TRC_Send_L1Audio_Msg_AM_DELAY_TABLE(short v1);
void L1TRC_Send_L1Audio_Msg_VBI_RESET(void);
void L1TRC_Send_L1Audio_Msg_VBI_END(void);
void L1TRC_Send_L1Audio_Msg_AM_SRC1(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1Audio_Msg_AM_SRC2(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1Audio_Msg_AM_3G_Reset_Time_Drift_L(void);
void L1TRC_Send_L1Audio_Msg_AM_L1D_Backup_L(short v1, unsigned short v2);
void L1TRC_Send_L1Audio_Msg_AM_HandoverInfo_L(short v1, short v2, short v3);

void Set_LCORE_L1Audio_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_LCORE_L1Audio()	(LCORE_L1Audio_Trace_Filter[0]==1)
#define ChkL1ClsFltr_LCORE_L1Audio_AFE_Inf_H()	(ChkL1ModFltr_LCORE_L1Audio()&&((LCORE_L1Audio_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()	(ChkL1ModFltr_LCORE_L1Audio()&&((LCORE_L1Audio_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_L1Audio_Msg_AM_AudioManager_L()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_AudioManager2_L()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_Handover()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_AudioManagerInfo()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_TCH_NOTIFY_L()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_Speech_L()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_PutQ_L()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_GetQ_L()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_SAL_SET_VALUE()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_SAL_SET_VALUE_MULTI()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_SAL_PROC()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_L1D_GetRF_L()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_DELAY_TABLE()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_VBI_RESET()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_VBI_END()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_SRC1()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_SRC2()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_3G_Reset_Time_Drift_L()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_L1D_Backup_L()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_HandoverInfo_L()	ChkL1ClsFltr_LCORE_L1Audio_AM_Inf_H()


#endif
