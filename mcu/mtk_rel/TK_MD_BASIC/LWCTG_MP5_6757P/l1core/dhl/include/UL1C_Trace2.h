#ifndef L1TRC_UL1C_PRI2_DEF_H
#define L1TRC_UL1C_PRI2_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Start(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0027, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Start(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_CTCH_Start_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0027, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Next_L1(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0127, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Next_L1(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CTCH_Next_L1_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0127, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_BS_Start(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0227, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_BS_Start(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1I_TRC_CTCH_BS_Start_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0227, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Rx_Status(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0327, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Rx_Status(v1, v2, v3)
#endif
#define UL1I_TRC_CTCH_Rx_Status_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0327, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_L2_BP(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0427, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_L2_BP(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_CTCH_L2_BP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0427, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Reschedule(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0527, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Reschedule(v1, v2)
#endif
#define UL1I_TRC_CTCH_Reschedule_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0527, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Priority_Change(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0627, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Priority_Change(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CTCH_Priority_Change_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0627, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_PCH_Type_Changed(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0727, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_PCH_Type_Changed(v1, v2)
#endif
#define UL1I_TRC_CTCH_PCH_Type_Changed_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0727, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Timer(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0827, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Timer(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Timer_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0827, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UnexpectedTimerStart(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0927, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_UnexpectedTimerStart(v1, v2, v3, v4)
#endif
#define UL1I_TRC_UnexpectedTimerStart_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0927, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_LeaveConfig(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0A27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_LeaveConfig(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1I_TRC_LeaveConfig_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0A27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterConfig(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EnterConfig(v1, v2, v3, v4)
#endif
#define UL1I_TRC_EnterConfig_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_AbortConfig(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_AbortConfig(v1, v2)
#endif
#define UL1I_TRC_AbortConfig_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SuspendCNF(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D27, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SuspendCNF(v1, v2, v3, v4)
#endif
#define UL1I_TRC_SuspendCNF_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D27, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_BCH_CCM_SIB_STATUS(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_BCH_CCM_SIB_STATUS(v1, v2, v3)
#endif
#define UL1I_TRC_BCH_CCM_SIB_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_BCH_CCM_SFN_STATUS(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_BCH_CCM_SFN_STATUS(v1, v2, v3)
#endif
#define UL1I_TRC_BCH_CCM_SFN_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterMode(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1027, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_EnterMode(v1, v2)
#endif
#define UL1I_TRC_EnterMode_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1027, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterDCH(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1127, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), (char)(v10)), (long)(v5));\
	} while(0)
#else
	#define UL1I_TRC_EnterDCH(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define UL1I_TRC_EnterDCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1127, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), (char)(v10)), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterPCH(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1227, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define UL1I_TRC_EnterPCH(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_EnterPCH_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1227, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterFACH(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1327, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define UL1I_TRC_EnterFACH(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_EnterFACH_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1327, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterNull(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1427, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_EnterNull(v1, v2, v3, v4)
#endif
#define UL1I_TRC_EnterNull_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1427, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_SetFN(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1527, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CCM_SetFN(v1, v2)
#endif
#define UL1I_TRC_CCM_SetFN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1527, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_StartDLDCH(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1627, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_StartDLDCH(v1, v2, v3)
#endif
#define UL1I_TRC_StartDLDCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1627, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Early_Sync(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1727, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Early_Sync(v1)
#endif
#define UL1I_TRC_Early_Sync_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1727, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Early_Sync_traces(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1827, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Early_Sync_traces(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_Early_Sync_traces_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1827, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TTI(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1927, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TTI(v1, v2, v3)
#endif
#define UL1I_TRC_TTI_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1927, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_State(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CCM_State(v1, v2)
#endif
#define UL1I_TRC_CCM_State_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Master_CCM_State(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_Master_CCM_State(v1, v2)
#endif
#define UL1I_TRC_Master_CCM_State_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_StopCC_Slave_CCM_State(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_StopCC_Slave_CCM_State(v1, v2)
#endif
#define UL1I_TRC_StopCC_Slave_CCM_State_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_All_SIM_Stopped(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D27, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CCM_All_SIM_Stopped(v1)
#endif
#define UL1I_TRC_CCM_All_SIM_Stopped_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D27, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_Not_All_SIM_Stopped(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E27, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CCM_Not_All_SIM_Stopped(v1, v2)
#endif
#define UL1I_TRC_CCM_Not_All_SIM_Stopped_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E27, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_All_SIM_Started(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F27, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CCM_All_SIM_Started(v1)
#endif
#define UL1I_TRC_CCM_All_SIM_Started_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F27, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_Not_All_SIM_Started(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2027, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CCM_Not_All_SIM_Started(v1, v2)
#endif
#define UL1I_TRC_CCM_Not_All_SIM_Started_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2027, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TimingInfo(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2127, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_TimingInfo(v1, v2, v3, v4)
#endif
#define UL1I_TRC_TimingInfo_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2127, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ReportTimingDrift(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2227, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_ReportTimingDrift(v1, v2, v3, v4)
#endif
#define UL1I_TRC_ReportTimingDrift_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2227, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ModifyTimingDrift(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2327, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_ModifyTimingDrift(v1, v2)
#endif
#define UL1I_TRC_ModifyTimingDrift_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2327, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Reschedule_Status(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2427, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Reschedule_Status(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1I_TRC_Reschedule_Status_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2427, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SFN_Stop(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2527, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SFN_Stop(v1)
#endif
#define UL1T_TRC_SFN_Stop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2527, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SFN_Start(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2627, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1T_TRC_SFN_Start(v1, v2, v3, v4)
#endif
#define UL1T_TRC_SFN_Start_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2627, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Reschedule(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2727, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Reschedule(v1, v2)
#endif
#define UL1I_TRC_SFN_Reschedule_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2727, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Rx(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2827, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Rx(v1, v2, v3)
#endif
#define UL1I_TRC_SFN_Rx_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2827, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_State(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2927, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_SFN_State(v1, v2)
#endif
#define UL1I_TRC_SFN_State_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2927, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_State_RunningSIM(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_State_RunningSIM(v1, v2, v3)
#endif
#define UL1I_TRC_SFN_State_RunningSIM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SFN_Data(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B27, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SFN_Data(v1, v2, v3)
#endif
#define UL1T_TRC_SFN_Data_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B27, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Report(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Report(v1, v2, v3, v4)
#endif
#define UL1I_TRC_SFN_Report_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_RetryAllow(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D27, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_SFN_RetryAllow(v1, v2, v3, v4)
#endif
#define UL1I_TRC_SFN_RetryAllow_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D27, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_InternalStop(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E27, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_SFN_InternalStop(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_SFN_InternalStop_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E27, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v5)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Compensation(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Compensation(v1, v2)
#endif
#define UL1I_TRC_SFN_Compensation_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Avail_Dec_Frms(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3027, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Avail_Dec_Frms(v1, v2)
#endif
#define UL1I_TRC_SFN_Avail_Dec_Frms_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3027, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_AdjustProtectPriority(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3127, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_SFN_AdjustProtectPriority(v1, v2)
#endif
#define UL1I_TRC_SFN_AdjustProtectPriority_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3127, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_ReStart(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3227, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_ReStart(v1, v2, v3)
#endif
#define UL1I_TRC_SFN_ReStart_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3227, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_CMResult(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3327, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_CMResult(v1, v2, v3, v4)
#endif
#define UL1I_TRC_SFN_CMResult_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3327, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_CM_Result(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3427, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_CM_Result(v1, v2, v3, v4)
#endif
#define UL1I_TRC_SFN_CM_Result_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3427, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_TwoStage_State(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3527, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_TwoStage_State(v1, v2, v3)
#endif
#define UL1I_TRC_SFN_TwoStage_State_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3527, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_MPS_Position(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3627, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_SFN_MPS_Position(v1, v2)
#endif
#define UL1I_TRC_SFN_MPS_Position_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3627, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Pending_Stop_Report(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3727, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Pending_Stop_Report(v1)
#endif
#define UL1I_TRC_SFN_Pending_Stop_Report_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3727, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SIB_Start(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x3827, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v9)), TRC_MERGE_4C((char)(v10), (char)(v11), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v6));\
	} while(0)
#else
	#define UL1T_TRC_SIB_Start(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define UL1T_TRC_SIB_Start_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x3827, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v9)), TRC_MERGE_4C((char)(v10), (char)(v11), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v6))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SIB_Reconfig(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3927, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v6), (char)(v7)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SIB_Reconfig(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_SIB_Reconfig_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3927, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v6), (char)(v7)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_Reschedule(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SIB_Reschedule(v1, v2)
#endif
#define UL1I_TRC_SIB_Reschedule_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_Rx(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SIB_Rx(v1, v2)
#endif
#define UL1I_TRC_SIB_Rx_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_State(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_SIB_State(v1, v2)
#endif
#define UL1I_TRC_SIB_State_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_Rpt(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SIB_Rpt(v1, v2, v3)
#endif
#define UL1I_TRC_SIB_Rpt_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SIB_CM(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E27, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_SIB_CM(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_SIB_CM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E27, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_AdjustProtectPriority(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_SIB_AdjustProtectPriority(v1, v2)
#endif
#define UL1I_TRC_SIB_AdjustProtectPriority_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_PCH_Type_Changed(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4027, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_SIB_PCH_Type_Changed(v1, v2)
#endif
#define UL1I_TRC_SIB_PCH_Type_Changed_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4027, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_ConfigBAList(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4127, (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v7), (char)(v8), (char)(v9)), TRC_MERGE_4C((char)(v10), (char)(v11), (char)(v12), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ConfigBAList(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define UL1T_TRC_ConfigBAList_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4127, (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v7), (char)(v8), (char)(v9)), TRC_MERGE_4C((char)(v10), (char)(v11), (char)(v12), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CellInfo(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4227, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1T_TRC_CellInfo(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CellInfo_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4227, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CellInfo_1(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4327, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CellInfo_1(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_CellInfo_1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4327, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ConfigDetectedCell(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4427, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ConfigDetectedCell(v1, v2, v3)
#endif
#define UL1T_TRC_ConfigDetectedCell_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4427, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_BA_Mapping(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4527, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_BA_Mapping(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_BA_Mapping_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4527, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_BAStatusUpdateInfo(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4627, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_BAStatusUpdateInfo(v1, v2, v3, v4)
#endif
#define UL1T_TRC_BAStatusUpdateInfo_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4627, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Alloc_CMM_Report(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4727, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_Alloc_CMM_Report(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_Alloc_CMM_Report_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4727, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_DCH_1st_Tick(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4827, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_DCH_1st_Tick(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_DCH_1st_Tick_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4827, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Prepare_BA_status(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4927, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_Prepare_BA_status(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_Prepare_BA_status_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4927, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_DeleteBA(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4A27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_DeleteBA(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_DeleteBA_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4A27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Protected_in_DCH(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4B27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_Protected_in_DCH(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_Protected_in_DCH_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4B27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_EvaluateReq(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4C27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_EvaluateReq(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_EvaluateReq_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4C27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Trigger_EnhancedCM(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4D27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_Trigger_EnhancedCM(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_Trigger_EnhancedCM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4D27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_DetectedCell_InvalidTM(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4E27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_DetectedCell_InvalidTM(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_DetectedCell_InvalidTM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4E27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_freq_not_existed(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4F27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_freq_not_existed(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_freq_not_existed_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4F27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_ConfigBA_by_CCM(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5027, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_ConfigBA_by_CCM(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_ConfigBA_by_CCM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5027, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Restore_CM_result(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5127, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_Restore_CM_result(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_Restore_CM_result_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5127, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Compensate_CMCS(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5227, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_Compensate_CMCS(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_Compensate_CMCS_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5227, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_AlarmTimeoutForInterF(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5327, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CM_AlarmTimeoutForInterF(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CM_AlarmTimeoutForInterF_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5327, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CM_freq_spec_compress_mode(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5427, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CM_freq_spec_compress_mode(v1, v2, v3)
#endif
#define UL1I_TRC_CM_freq_spec_compress_mode_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5427, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CM_RptHasCleared(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5527, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CM_RptHasCleared(v1, v2)
#endif
#define UL1I_TRC_CM_RptHasCleared_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5527, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMHalt(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5627, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMHalt(v1, v2)
#endif
#define UL1I_TRC_CMHalt_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5627, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ConfigCell(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5727, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), (char)(v2)), (long)(v6));\
	} while(0)
#else
	#define UL1T_TRC_ConfigCell(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_ConfigCell_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5727, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), (char)(v2)), (long)(v6))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMResult(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5827, (unsigned short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMResult(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_CMResult_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5827, (unsigned short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMResult_RXD(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5927, (unsigned short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMResult_RXD(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_CMResult_RXD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5927, (unsigned short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMDone(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMDone(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CMDone_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMStart(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5B27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMStart(v1, v2, v3)
#endif
#define UL1T_TRC_CMStart_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5B27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PrioCMCS(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C27, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_PrioCMCS(v1, v2, v3, v4)
#endif
#define UL1I_TRC_PrioCMCS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C27, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PrioCMCS_InterF_EFACH_DRX(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5D27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PrioCMCS_InterF_EFACH_DRX(v1, v2, v3, v4)
#endif
#define UL1I_TRC_PrioCMCS_InterF_EFACH_DRX_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5D27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMStart(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5E27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMStart(v1, v2, v3)
#endif
#define UL1I_TRC_CMStart_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5E27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMStart_Failed(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5F27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMStart_Failed(v1, v2)
#endif
#define UL1I_TRC_CMStart_Failed_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5F27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMStop(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6027, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_CMStop(v1, v2)
#endif
#define UL1T_TRC_CMStop_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6027, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMReportStop(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6127, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMReportStop(v1)
#endif
#define UL1T_TRC_CMReportStop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6127, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMStop(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6227, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMStop(v1, v2, v3)
#endif
#define UL1I_TRC_CMStop_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6227, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_CMAlphaFilter(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6327, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAlphaFilter(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_CMAlphaFilter_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6327, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMReport(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6427, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMReport(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CMReport_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6427, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CM_AllocReportEnhancedCM(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6527, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CM_AllocReportEnhancedCM(v1, v2, v3)
#endif
#define UL1I_TRC_CM_AllocReportEnhancedCM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6527, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6627, (short)(v4)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_CMAverager_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6627, (short)(v4)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager_RXD(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6727, (short)(v4)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager_RXD(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_CMAverager_RXD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6727, (short)(v4)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager_MAX(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6827, (short)(v4)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager_MAX(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_CMAverager_MAX_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6827, (short)(v4)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager2(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6927, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager2(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CMAverager2_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6927, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager2_RXD(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6A27, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager2_RXD(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CMAverager2_RXD_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6A27, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CMAVG_Put(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6B27, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMAVG_Put(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CMAVG_Put_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6B27, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CMAVG_Apply(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6C27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMAVG_Apply(v1, v2, v3)
#endif
#define UL1I_TRC_CMAVG_Apply_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6C27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CMAVG_Apply_RXD(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6D27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMAVG_Apply_RXD(v1, v2, v3)
#endif
#define UL1I_TRC_CMAVG_Apply_RXD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6D27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_CMAVG_LINValue(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6E27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAVG_LINValue(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CMAVG_LINValue_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6E27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_CMAVG_DBG(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_CMAVG_DBG(v1, v2)
#endif
#define UL1T_TRC_CMAVG_DBG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CMTreselection(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CMTreselection(v1, v2, v3)
#endif
#define UL1_TRC_CMTreselection_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASCurrentAnt(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7127, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASCurrentAnt(v1, v2)
#endif
#define UL1_TRC_CM_TASCurrentAnt_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7127, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSelectDefaultAnt(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7227, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSelectDefaultAnt(v1, v2, v3)
#endif
#define UL1_TRC_CM_TASSelectDefaultAnt_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7227, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASForceTxAnt(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7327, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASForceTxAnt(v1, v2, v3)
#endif
#define UL1_TRC_CM_TASForceTxAnt_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7327, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASGuardExpire(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7427, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASGuardExpire(v1)
#endif
#define UL1_TRC_CM_TASGuardExpire_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7427, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSwitchBackExpire(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7527, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSwitchBackExpire(v1)
#endif
#define UL1_TRC_CM_TASSwitchBackExpire_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7527, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASEnterState(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7627, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASEnterState(v1, v2)
#endif
#define UL1_TRC_CM_TASEnterState_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7627, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASDedicateAllowed(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7727, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASDedicateAllowed(v1, v2, v3, v4)
#endif
#define UL1_TRC_CM_TASDedicateAllowed_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7727, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASPCHNotAllowed(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7827, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASPCHNotAllowed(v1)
#endif
#define UL1_TRC_CM_TASPCHNotAllowed_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7827, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASAbortSwitch(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7927, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASAbortSwitch(v1)
#endif
#define UL1_TRC_CM_TASAbortSwitch_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7927, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSwitchAnt(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7A27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSwitchAnt(v1, v2, v3, v4)
#endif
#define UL1_TRC_CM_TASSwitchAnt_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7A27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASRevertSwitch(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7B27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASRevertSwitch(v1, v2, v3, v4)
#endif
#define UL1_TRC_CM_TASRevertSwitch_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7B27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASStartSwitchBack(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7C27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASStartSwitchBack(v1, v2)
#endif
#define UL1_TRC_CM_TASStartSwitchBack_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7C27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSwitchBack(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7D27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSwitchBack(v1, v2)
#endif
#define UL1_TRC_CM_TASSwitchBack_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7D27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSwitchingMetric(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7E27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSwitchingMetric(v1, v2, v3, v4, v5, v6)
#endif
#define UL1_TRC_CM_TASSwitchingMetric_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7E27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType1Conditions(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x7F27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType1Conditions(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1_TRC_CM_TASType1Conditions_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x7F27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType2Conditions(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x8027, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType2Conditions(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define UL1_TRC_CM_TASType2Conditions_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x8027, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType1Evaluate(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8127, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType1Evaluate(v1, v2, v3, v4, v5)
#endif
#define UL1_TRC_CM_TASType1Evaluate_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8127, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType2Evaluate(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x8227, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType2Evaluate(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1_TRC_CM_TASType2Evaluate_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x8227, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType1SBConditions(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x8327, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType1SBConditions(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1_TRC_CM_TASType1SBConditions_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x8327, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType2SBConditions(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x8427, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType2SBConditions(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1_TRC_CM_TASType2SBConditions_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x8427, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_FuncTest(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x8527, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_FuncTest(v1)
#endif
#define UL1_TRC_CM_TAS_FuncTest_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x8527, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_Floating_Threshold(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x8627, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_Floating_Threshold(v1)
#endif
#define UL1_TRC_CM_TAS_Floating_Threshold_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x8627, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_SetAntOnTestSIM(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8727, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_SetAntOnTestSIM(v1, v2, v3, v4, v5, v6)
#endif
#define UL1_TRC_CM_TAS_SetAntOnTestSIM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8727, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_DBG_SetAntIdx_TestSIM(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8827, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_DBG_SetAntIdx_TestSIM(v1, v2, v3, v4, v5)
#endif
#define UL1_TRC_CM_TAS_DBG_SetAntIdx_TestSIM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8827, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_Overlap_freq(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8927, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_Overlap_freq(v1, v2)
#endif
#define UL1_TRC_CM_Overlap_freq_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8927, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_return_due2_overlap(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x8A27, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_return_due2_overlap(v1)
#endif
#define UL1_TRC_CM_RAS_return_due2_overlap_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x8A27, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_Set_CS_Flag(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x8B27, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_Set_CS_Flag(v1)
#endif
#define UL1_TRC_CM_Set_CS_Flag_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x8B27, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_Set_CS_Flag_Status(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x8C27, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_Set_CS_Flag_Status(v1)
#endif
#define UL1_TRC_CM_Set_CS_Flag_Status_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x8C27, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_start_ras_status1(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x8D27, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_start_ras_status1(v1)
#endif
#define UL1_TRC_CM_RAS_start_ras_status1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x8D27, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_start_ras_status(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8E27, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_start_ras_status(v1, v2)
#endif
#define UL1_TRC_CM_RAS_start_ras_status_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8E27, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_avg_buff_index(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x8F27, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_avg_buff_index(v1)
#endif
#define UL1_TRC_CM_RAS_avg_buff_index_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x8F27, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_live_sim_status(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9027, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_live_sim_status(v1)
#endif
#define UL1_TRC_CM_RAS_live_sim_status_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9027, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_ras_status(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9127, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_ras_status(v1)
#endif
#define UL1_TRC_CM_RAS_ras_status_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9127, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_inisde_firsttimer(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9227, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_inisde_firsttimer(v1)
#endif
#define UL1_TRC_CM_RAS_inisde_firsttimer_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9227, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_ras_status_inCMCS_DCH(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9327, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_ras_status_inCMCS_DCH(v1)
#endif
#define UL1_TRC_CM_RAS_ras_status_inCMCS_DCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9327, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_ras_status_inCMCS_FACH(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9427, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_ras_status_inCMCS_FACH(v1)
#endif
#define UL1_TRC_CM_RAS_ras_status_inCMCS_FACH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9427, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_Seting_tas_type(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9527, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_Seting_tas_type(v1)
#endif
#define UL1_TRC_CM_Seting_tas_type_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9527, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_get_tas_type(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9627, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_get_tas_type(v1)
#endif
#define UL1_TRC_CM_get_tas_type_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9627, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_SET_TAS_TYPE_DONE(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9727, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_SET_TAS_TYPE_DONE(v1)
#endif
#define UL1_TRC_CM_RAS_SET_TAS_TYPE_DONE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9727, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_Evaluate_function(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9827, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_Evaluate_function(v1)
#endif
#define UL1_TRC_CM_RAS_Evaluate_function_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9827, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_Evaluate_initial_status(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9927, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_Evaluate_initial_status(v1, v2, v3, v4, v5)
#endif
#define UL1_TRC_CM_RAS_Evaluate_initial_status_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9927, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_Evaluate_end_status(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9A27, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_Evaluate_end_status(v1, v2, v3, v4, v5)
#endif
#define UL1_TRC_CM_RAS_Evaluate_end_status_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9A27, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_antennaonoff(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9B27, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_antennaonoff(v1)
#endif
#define UL1_TRC_CM_RAS_antennaonoff_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9B27, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_antennaonoff1(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9C27, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_antennaonoff1(v1)
#endif
#define UL1_TRC_CM_RAS_antennaonoff1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9C27, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_rscp_rssi_ecno_avg(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x9D27, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_rscp_rssi_ecno_avg(v1, v2, v3)
#endif
#define UL1_TRC_CM_RAS_rscp_rssi_ecno_avg_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x9D27, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_RAS_antennaonoff2(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9E27, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_RAS_antennaonoff2(v1)
#endif
#define UL1_TRC_CM_RAS_antennaonoff2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9E27, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSendCMReport(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9F27, (short)(v2)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSendCMReport(v1, v2, v3, v4, v5, v6)
#endif
#define UL1_TRC_CM_TASSendCMReport_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9F27, (short)(v2)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASDeriveMeasSample(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0xA027, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASDeriveMeasSample(v1, v2, v3, v4, v5, v6)
#endif
#define UL1_TRC_CM_TASDeriveMeasSample_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0xA027, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASDeriveMeasSample_Div(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA127, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASDeriveMeasSample_Div(v1, v2, v3, v4)
#endif
#define UL1_TRC_CM_TASDeriveMeasSample_Div_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA127, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASQueueMeasSample(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xA227, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASQueueMeasSample(v1, v2)
#endif
#define UL1_TRC_CM_TASQueueMeasSample_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0xA227, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASInitDedi(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0xA327, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASInitDedi(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1_TRC_CM_TASInitDedi_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0xA327, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASInitIdle(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0xA427, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASInitIdle(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1_TRC_CM_TASInitIdle_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_5_DATA(TRC_MERGE_2S(0xA427, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_ServingIdx(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xA527, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_ServingIdx(v1, v2)
#endif
#define UL1_TRC_CM_ServingIdx_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0xA527, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_HTP_Power(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xA627, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_HTP_Power(v1, v2)
#endif
#define UL1_TRC_CM_HTP_Power_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0xA627, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_HTP_Ratio(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xA727, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_HTP_Ratio(v1, v2, v3)
#endif
#define UL1_TRC_CM_HTP_Ratio_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0xA727, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_DPCCH_TXPWR(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xA827, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_DPCCH_TXPWR(v1, v2, v3)
#endif
#define UL1_TRC_CM_DPCCH_TXPWR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0xA827, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_Dynamic_Barrier(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA927, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_Dynamic_Barrier(v1, v2, v3, v4, v5)
#endif
#define UL1_TRC_CM_TAS_Dynamic_Barrier_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA927, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_Avg_Buf_idx(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xAA27, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_Avg_Buf_idx(v1, v2, v3)
#endif
#define UL1_TRC_CM_TAS_Avg_Buf_idx_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0xAA27, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_Floating_Thre(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xAB27, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_Floating_Thre(v1, v2, v3)
#endif
#define UL1_TRC_CM_TAS_Floating_Thre_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0xAB27, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_Type1_NoDiv(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xAC27, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_Type1_NoDiv(v1)
#endif
#define UL1_TRC_CM_TAS_Type1_NoDiv_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xAC27, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_StopTimer(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xAD27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_StopTimer(v1, v2)
#endif
#define UL1_TRC_CM_TAS_StopTimer_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0xAD27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_SendTasStats(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0xAE27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_SendTasStats(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1_TRC_CM_TAS_SendTasStats_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0xAE27, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RF_TUNING_State(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xAF27, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_RF_TUNING_State(v1, v2)
#endif
#define UL1I_TRC_RF_TUNING_State_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xAF27, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CSDone(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xB027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CSDone(v1, v2, v3)
#endif
#define UL1I_TRC_CSDone_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xB027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CSResult(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xB127, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CSResult(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CSResult_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0xB127, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CSStart(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xB227, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (char)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_CSStart(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_CSStart_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0xB227, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (char)(v5)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CS_Stop(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB327, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CS_Stop(v1, v2)
#endif
#define UL1I_TRC_CS_Stop_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB327, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CS_RptHasCleared(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB427, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CS_RptHasCleared(v1, v2)
#endif
#define UL1I_TRC_CS_RptHasCleared_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB427, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CS_PreCSPending_Return(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB527, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CS_PreCSPending_Return(v1, v2)
#endif
#define UL1I_TRC_CS_PreCSPending_Return_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB527, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Unlock_gapStopCnf(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB627, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_Unlock_gapStopCnf(v1, v2)
#endif
#define UL1I_TRC_Unlock_gapStopCnf_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xB627, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DMStopGap(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xB727, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DMStopGap(v1, v2, v3)
#endif
#define UL1T_TRC_DMStopGap_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xB727, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_SetGap(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0xB827, (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v5), (char)(v6), (char)(v8)), TRC_MERGE_4C((char)(v9), (char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1T_TRC_DM_SetGap(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1T_TRC_DM_SetGap_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0xB827, (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v5), (char)(v6), (char)(v8)), TRC_MERGE_4C((char)(v9), (char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_DRXTick(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xB927, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DM_DRXTick(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_DM_DRXTick_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0xB927, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_CMCSTickInfo(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xBA27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_CMCSTickInfo(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_DM_CMCSTickInfo_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xBA27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_SetCurrActiveMode(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xBB27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_DM_SetCurrActiveMode(v1, v2)
#endif
#define UL1T_TRC_DM_SetCurrActiveMode_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xBB27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_AssignGAP(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0xBC27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_DM_AssignGAP(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DM_AssignGAP_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0xBC27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_GapStatus(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xBD27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_GapStatus(v1, v2)
#endif
#define UL1I_TRC_DM_GapStatus_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0xBD27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Start_GAP_Timer1(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0xBE27, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v6));\
	} while(0)
#else
	#define UL1I_TRC_Start_GAP_Timer1(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_Start_GAP_Timer1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0xBE27, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v6))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Start_GAP_Timer2(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xBF27, (unsigned char)(v1), (char)(v2)), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_Start_GAP_Timer2(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Start_GAP_Timer2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xBF27, (unsigned char)(v1), (char)(v2)), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Start_GAP(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xC027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_Start_GAP(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Start_GAP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xC027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_TimeSyncStart(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xC127, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_DM_TimeSyncStart(v1, v2, v3)
#endif
#define UL1I_TRC_DM_TimeSyncStart_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0xC127, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_TimeSyncReport(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0xC227, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_DM_TimeSyncReport(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DM_TimeSyncReport_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0xC227, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_ShowUSC(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xC327, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1I_TRC_DM_ShowUSC(v1)
#endif
#define UL1I_TRC_DM_ShowUSC_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xC327, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_Cancel_ActiveGAP(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xC427, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DM_Cancel_ActiveGAP(v1)
#endif
#define UL1T_TRC_DM_Cancel_ActiveGAP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xC427, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Cancel_2G_GAP_Cnf(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xC527, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Cancel_2G_GAP_Cnf(v1)
#endif
#define UL1I_TRC_DM_Cancel_2G_GAP_Cnf_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xC527, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Query_GAP(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xC627, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_DM_Query_GAP(v1, v2, v3)
#endif
#define UL1I_TRC_DM_Query_GAP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xC627, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Query_GAP_SM(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xC727, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Query_GAP_SM(v1, v2, v3)
#endif
#define UL1I_TRC_DM_Query_GAP_SM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0xC727, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Query_PSEUDO(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xC827, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Query_PSEUDO(v1)
#endif
#define UL1I_TRC_DM_Query_PSEUDO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xC827, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Sleep_Ind(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0xC927, (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (long)(v8), (long)(v9));\
	} while(0)
#else
	#define UL1I_TRC_DM_Sleep_Ind(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1I_TRC_DM_Sleep_Ind_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_9_DATA(TRC_MERGE_2S(0xC927, (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (long)(v8), (long)(v9))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_EFACHDRX_NeedGap(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xCA27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_DM_EFACHDRX_NeedGap(v1, v2)
#endif
#define UL1T_TRC_DM_EFACHDRX_NeedGap_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xCA27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_EFACHDRX_Disable(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xCB27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)));\
	} while(0)
#else
	#define UL1I_TRC_DM_EFACHDRX_Disable(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_DM_EFACHDRX_Disable_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xCB27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_EFACHDRX_SkipGap(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xCC27, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_DM_EFACHDRX_SkipGap(v1, v2)
#endif
#define UL1I_TRC_DM_EFACHDRX_SkipGap_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xCC27, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_EFACHDRX_Cm_Session_Info(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xCD27, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_EFACHDRX_Cm_Session_Info(v1, v2, v3)
#endif
#define UL1I_TRC_DM_EFACHDRX_Cm_Session_Info_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0xCD27, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMA_Auto_Gap_Assign(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0xCE27, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_DMA_Auto_Gap_Assign(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DMA_Auto_Gap_Assign_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0xCE27, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMA_Auto_Gap_Update(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xCF27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DMA_Auto_Gap_Update(v1, v2, v3)
#endif
#define UL1I_TRC_DMA_Auto_Gap_Update_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xCF27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMS_Auto_Gap_State(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xD027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DMS_Auto_Gap_State(v1, v2, v3)
#endif
#define UL1I_TRC_DMS_Auto_Gap_State_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xD027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMS_Auto_Gap_Req(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0xD127, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_DMS_Auto_Gap_Req(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DMS_Auto_Gap_Req_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0xD127, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMS_Auto_Gap_AvailStart(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xD227, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DMS_Auto_Gap_AvailStart(v1, v2, v3)
#endif
#define UL1I_TRC_DMS_Auto_Gap_AvailStart_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xD227, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMS_Auto_Gap_Assign(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0xD327, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define UL1I_TRC_DMS_Auto_Gap_Assign(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_DMS_Auto_Gap_Assign_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0xD327, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RTB_Timer(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xD427, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v5), TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_RTB_Timer(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_RTB_Timer_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0xD427, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v5), TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_AGPS_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0xD527, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_AGPS_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_AGPS_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0xD527, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_ADJUSTMENT_STATUS(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xD627, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_ADJUSTMENT_STATUS(v1, v2)
#endif
#define UL1I_TRC_CTCH_ADJUSTMENT_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xD627, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0xD727, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND(v1, v2, v3)
#endif
#define UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0xD727, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Resume(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0xD827, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Resume(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1I_TRC_CTCH_Resume_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0xD827, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Delay(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xD927, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Delay(v1, v2, v3)
#endif
#define UL1I_TRC_CTCH_Delay_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0xD927, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1C_PRI2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1I_TRC_CTCH_Start(unsigned char v1, short v2, long v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_CTCH_Next_L1(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_CTCH_BS_Start(unsigned char v1, short v2, short v3, short v4, long v5, short v6, short v7);
void L1TRC_Send_UL1I_TRC_CTCH_Rx_Status(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_CTCH_L2_BP(unsigned char v1, short v2, short v3, long v4, short v5);
void L1TRC_Send_UL1I_TRC_CTCH_Reschedule(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_CTCH_Priority_Change(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_CTCH_PCH_Type_Changed(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_Timer(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_UnexpectedTimerStart(unsigned char v1, char v2, long v3, short v4);
void L1TRC_Send_UL1I_TRC_LeaveConfig(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_UL1I_TRC_EnterConfig(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_AbortConfig(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_SuspendCNF(unsigned char v1, char v2, char v3, short v4);
void L1TRC_Send_UL1I_TRC_BCH_CCM_SIB_STATUS(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_BCH_CCM_SFN_STATUS(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_EnterMode(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_EnterDCH(unsigned char v1, short v2, short v3, char v4, long v5, short v6, char v7, char v8, char v9, char v10, short v11);
void L1TRC_Send_UL1I_TRC_EnterPCH(unsigned char v1, short v2, short v3, char v4, long v5, short v6);
void L1TRC_Send_UL1I_TRC_EnterFACH(unsigned char v1, short v2, short v3, char v4, long v5, short v6);
void L1TRC_Send_UL1I_TRC_EnterNull(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_CCM_SetFN(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_StartDLDCH(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_Early_Sync(unsigned char v1);
void L1TRC_Send_UL1I_TRC_Early_Sync_traces(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_TTI(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_CCM_State(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_Master_CCM_State(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_StopCC_Slave_CCM_State(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_CCM_All_SIM_Stopped(unsigned char v1);
void L1TRC_Send_UL1I_TRC_CCM_Not_All_SIM_Stopped(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1I_TRC_CCM_All_SIM_Started(unsigned char v1);
void L1TRC_Send_UL1I_TRC_CCM_Not_All_SIM_Started(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1I_TRC_TimingInfo(unsigned char v1, short v2, long v3, char v4);
void L1TRC_Send_UL1I_TRC_ReportTimingDrift(unsigned char v1, long v2, short v3, long v4);
void L1TRC_Send_UL1I_TRC_ModifyTimingDrift(unsigned char v1, long v2);
void L1TRC_Send_UL1I_TRC_Reschedule_Status(unsigned char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1T_TRC_SFN_Stop(unsigned char v1);
void L1TRC_Send_UL1T_TRC_SFN_Start(unsigned char v1, short v2, short v3, long v4);
void L1TRC_Send_UL1I_TRC_SFN_Reschedule(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_SFN_Rx(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_SFN_State(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_SFN_State_RunningSIM(unsigned char v1, char v2, unsigned char v3);
void L1TRC_Send_UL1T_TRC_SFN_Data(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_SFN_Report(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_SFN_RetryAllow(unsigned char v1, short v2, char v3, short v4);
void L1TRC_Send_UL1I_TRC_SFN_InternalStop(unsigned char v1, char v2, char v3, short v4, char v5);
void L1TRC_Send_UL1I_TRC_SFN_Compensation(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_SFN_Avail_Dec_Frms(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_SFN_AdjustProtectPriority(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_SFN_ReStart(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_SFN_CMResult(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_SFN_CM_Result(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_SFN_TwoStage_State(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_SFN_MPS_Position(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_SFN_Pending_Stop_Report(unsigned char v1);
void L1TRC_Send_UL1T_TRC_SIB_Start(unsigned char v1, short v2, short v3, short v4, short v5, long v6, short v7, short v8, char v9, char v10, char v11);
void L1TRC_Send_UL1T_TRC_SIB_Reconfig(unsigned char v1, short v2, short v3, char v4, short v5, char v6, char v7, char v8);
void L1TRC_Send_UL1I_TRC_SIB_Reschedule(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_SIB_Rx(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_SIB_State(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_SIB_Rpt(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1T_TRC_SIB_CM(unsigned char v1, char v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_SIB_AdjustProtectPriority(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_SIB_PCH_Type_Changed(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_ConfigBAList(unsigned char v1, char v2, char v3, char v4, char v5, short v6, char v7, char v8, char v9, char v10, char v11, char v12);
void L1TRC_Send_UL1T_TRC_CellInfo(unsigned char v1, char v2, short v3, long v4);
void L1TRC_Send_UL1T_TRC_CellInfo_1(unsigned char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_UL1T_TRC_ConfigDetectedCell(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_BA_Mapping(unsigned char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_UL1T_TRC_BAStatusUpdateInfo(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_Alloc_CMM_Report(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_DCH_1st_Tick(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_Prepare_BA_status(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_DeleteBA(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_Protected_in_DCH(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_EvaluateReq(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_Trigger_EnhancedCM(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_DetectedCell_InvalidTM(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_freq_not_existed(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_ConfigBA_by_CCM(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_Restore_CM_result(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_Compensate_CMCS(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_CM_AlarmTimeoutForInterF(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_CM_freq_spec_compress_mode(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_CM_RptHasCleared(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_CMHalt(unsigned char v1, short v2);
void L1TRC_Send_UL1T_TRC_ConfigCell(unsigned char v1, char v2, short v3, short v4, short v5, long v6, short v7);
void L1TRC_Send_UL1I_TRC_CMResult(unsigned char v1, char v2, char v3, unsigned short v4, short v5);
void L1TRC_Send_UL1I_TRC_CMResult_RXD(unsigned char v1, char v2, char v3, unsigned short v4, short v5);
void L1TRC_Send_UL1I_TRC_CMDone(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_CMStart(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_PrioCMCS(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_PrioCMCS_InterF_EFACH_DRX(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_CMStart(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_CMStart_Failed(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_CMStop(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_CMReportStop(unsigned char v1);
void L1TRC_Send_UL1I_TRC_CMStop(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_CMAlphaFilter(unsigned char v1, char v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_CMReport(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_CM_AllocReportEnhancedCM(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_CMAverager(unsigned char v1, char v2, char v3, short v4, char v5, short v6, short v7, short v8);
void L1TRC_Send_UL1T_TRC_CMAverager_RXD(unsigned char v1, char v2, char v3, short v4, char v5, short v6, short v7, short v8);
void L1TRC_Send_UL1T_TRC_CMAverager_MAX(unsigned char v1, char v2, char v3, short v4, char v5, short v6, short v7, short v8);
void L1TRC_Send_UL1T_TRC_CMAverager2(unsigned char v1, char v2, char v3, short v4);
void L1TRC_Send_UL1T_TRC_CMAverager2_RXD(unsigned char v1, char v2, char v3, short v4);
void L1TRC_Send_UL1I_TRC_CMAVG_Put(unsigned char v1, char v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_CMAVG_Apply(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_CMAVG_Apply_RXD(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_CMAVG_LINValue(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_CMAVG_DBG(unsigned char v1, char v2);
void L1TRC_Send_UL1_TRC_CMTreselection(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1_TRC_CM_TASCurrentAnt(unsigned char v1, char v2);
void L1TRC_Send_UL1_TRC_CM_TASSelectDefaultAnt(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1_TRC_CM_TASForceTxAnt(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1_TRC_CM_TASGuardExpire(unsigned char v1);
void L1TRC_Send_UL1_TRC_CM_TASSwitchBackExpire(unsigned char v1);
void L1TRC_Send_UL1_TRC_CM_TASEnterState(unsigned char v1, char v2);
void L1TRC_Send_UL1_TRC_CM_TASDedicateAllowed(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1_TRC_CM_TASPCHNotAllowed(unsigned char v1);
void L1TRC_Send_UL1_TRC_CM_TASAbortSwitch(unsigned char v1);
void L1TRC_Send_UL1_TRC_CM_TASSwitchAnt(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1_TRC_CM_TASRevertSwitch(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1_TRC_CM_TASStartSwitchBack(unsigned char v1, short v2);
void L1TRC_Send_UL1_TRC_CM_TASSwitchBack(unsigned char v1, char v2);
void L1TRC_Send_UL1_TRC_CM_TASSwitchingMetric(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1_TRC_CM_TASType1Conditions(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10);
void L1TRC_Send_UL1_TRC_CM_TASType2Conditions(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11);
void L1TRC_Send_UL1_TRC_CM_TASType1Evaluate(unsigned char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1_TRC_CM_TASType2Evaluate(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1_TRC_CM_TASType1SBConditions(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_UL1_TRC_CM_TASType2SBConditions(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_UL1_TRC_CM_TAS_FuncTest(short v1);
void L1TRC_Send_UL1_TRC_CM_TAS_Floating_Threshold(short v1);
void L1TRC_Send_UL1_TRC_CM_TAS_SetAntOnTestSIM(unsigned char v1, short v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_UL1_TRC_CM_TAS_DBG_SetAntIdx_TestSIM(unsigned char v1, short v2, char v3, short v4, short v5);
void L1TRC_Send_UL1_TRC_CM_Overlap_freq(short v1, short v2);
void L1TRC_Send_UL1_TRC_CM_RAS_return_due2_overlap(short v1);
void L1TRC_Send_UL1_TRC_CM_Set_CS_Flag(short v1);
void L1TRC_Send_UL1_TRC_CM_Set_CS_Flag_Status(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_start_ras_status1(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_start_ras_status(short v1, short v2);
void L1TRC_Send_UL1_TRC_CM_RAS_avg_buff_index(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_live_sim_status(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_ras_status(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_inisde_firsttimer(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_ras_status_inCMCS_DCH(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_ras_status_inCMCS_FACH(short v1);
void L1TRC_Send_UL1_TRC_CM_Seting_tas_type(short v1);
void L1TRC_Send_UL1_TRC_CM_get_tas_type(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_SET_TAS_TYPE_DONE(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_Evaluate_function(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_Evaluate_initial_status(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1_TRC_CM_RAS_Evaluate_end_status(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1_TRC_CM_RAS_antennaonoff(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_antennaonoff1(short v1);
void L1TRC_Send_UL1_TRC_CM_RAS_rscp_rssi_ecno_avg(short v1, short v2, short v3);
void L1TRC_Send_UL1_TRC_CM_RAS_antennaonoff2(short v1);
void L1TRC_Send_UL1_TRC_CM_TASSendCMReport(unsigned char v1, short v2, char v3, char v4, short v5, short v6);
void L1TRC_Send_UL1_TRC_CM_TASDeriveMeasSample(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1_TRC_CM_TASDeriveMeasSample_Div(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1_TRC_CM_TASQueueMeasSample(unsigned char v1, short v2);
void L1TRC_Send_UL1_TRC_CM_TASInitDedi(unsigned char v1, short v2, short v3, char v4, char v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_UL1_TRC_CM_TASInitIdle(unsigned char v1, short v2, short v3, char v4, char v5, short v6, short v7, short v8, short v9, short v10);
void L1TRC_Send_UL1_TRC_CM_ServingIdx(unsigned char v1, short v2);
void L1TRC_Send_UL1_TRC_CM_HTP_Power(unsigned char v1, short v2);
void L1TRC_Send_UL1_TRC_CM_HTP_Ratio(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1_TRC_CM_DPCCH_TXPWR(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1_TRC_CM_TAS_Dynamic_Barrier(unsigned char v1, char v2, short v3, short v4, short v5);
void L1TRC_Send_UL1_TRC_CM_TAS_Avg_Buf_idx(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1_TRC_CM_TAS_Floating_Thre(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1_TRC_CM_TAS_Type1_NoDiv(unsigned char v1);
void L1TRC_Send_UL1_TRC_CM_TAS_StopTimer(unsigned char v1, short v2);
void L1TRC_Send_UL1_TRC_CM_TAS_SendTasStats(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1I_TRC_RF_TUNING_State(unsigned char v1, long v2);
void L1TRC_Send_UL1I_TRC_CSDone(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_CSResult(unsigned char v1, char v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_CSStart(unsigned char v1, char v2, short v3, char v4, char v5);
void L1TRC_Send_UL1I_TRC_CS_Stop(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_CS_RptHasCleared(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_CS_PreCSPending_Return(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_Unlock_gapStopCnf(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_DMStopGap(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_DM_SetGap(unsigned char v1, long v2, long v3, long v4, char v5, char v6, short v7, char v8, char v9, char v10);
void L1TRC_Send_UL1T_TRC_DM_DRXTick(unsigned char v1, char v2, short v3, char v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_DM_CMCSTickInfo(unsigned char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_UL1T_TRC_DM_SetCurrActiveMode(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_DM_AssignGAP(unsigned char v1, short v2, long v3, long v4);
void L1TRC_Send_UL1I_TRC_DM_GapStatus(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_Start_GAP_Timer1(unsigned char v1, long v2, short v3, long v4, short v5, long v6);
void L1TRC_Send_UL1I_TRC_Start_GAP_Timer2(unsigned char v1, char v2, long v3, long v4);
void L1TRC_Send_UL1I_TRC_Start_GAP(unsigned char v1, char v2, long v3, char v4);
void L1TRC_Send_UL1I_TRC_DM_TimeSyncStart(unsigned char v1, long v2, long v3);
void L1TRC_Send_UL1I_TRC_DM_TimeSyncReport(unsigned char v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_UL1I_TRC_DM_ShowUSC(unsigned long v1);
void L1TRC_Send_UL1T_TRC_DM_Cancel_ActiveGAP(unsigned char v1);
void L1TRC_Send_UL1I_TRC_DM_Cancel_2G_GAP_Cnf(unsigned char v1);
void L1TRC_Send_UL1I_TRC_DM_Query_GAP(unsigned char v1, char v2, unsigned long v3);
void L1TRC_Send_UL1I_TRC_DM_Query_GAP_SM(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_DM_Query_PSEUDO(unsigned char v1);
void L1TRC_Send_UL1I_TRC_DM_Sleep_Ind(unsigned char v1, long v2, long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned char v7, long v8, long v9, short v10);
void L1TRC_Send_UL1T_TRC_DM_EFACHDRX_NeedGap(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_DM_EFACHDRX_Disable(unsigned char v1, char v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_UL1I_TRC_DM_EFACHDRX_SkipGap(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_DM_EFACHDRX_Cm_Session_Info(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_DMA_Auto_Gap_Assign(unsigned char v1, long v2, long v3, long v4);
void L1TRC_Send_UL1I_TRC_DMA_Auto_Gap_Update(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_DMS_Auto_Gap_State(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_DMS_Auto_Gap_Req(unsigned char v1, short v2, long v3, long v4);
void L1TRC_Send_UL1I_TRC_DMS_Auto_Gap_AvailStart(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_DMS_Auto_Gap_Assign(unsigned char v1, short v2, long v3, long v4, long v5);
void L1TRC_Send_UL1I_TRC_RTB_Timer(unsigned char v1, char v2, short v3, long v4, char v5);
void L1TRC_Send_UL1I_TRC_AGPS_INFO(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_CTCH_ADJUSTMENT_STATUS(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_CTCH_Resume(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1I_TRC_CTCH_Delay(unsigned char v1, short v2, long v3);

void Set_UL1C_PRI2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1C_PRI2()	(UL1C_PRI2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x20)!=0))
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Next_L1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_BS_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Rx_Status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_L2_BP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Reschedule()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Priority_Change()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_PCH_Type_Changed()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Timer()	ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_H()
#define ChkL1MsgFltr_UL1I_TRC_UnexpectedTimerStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_H()
#define ChkL1MsgFltr_UL1I_TRC_LeaveConfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterConfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_AbortConfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_SuspendCNF()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_BCH_CCM_SIB_STATUS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_BCH_CCM_SFN_STATUS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterMode()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterDCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterPCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterFACH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterNull()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_SetFN()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_StartDLDCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_Early_Sync()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_Early_Sync_traces()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_TTI()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_Master_CCM_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_StopCC_Slave_CCM_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_All_SIM_Stopped()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_Not_All_SIM_Stopped()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_All_SIM_Started()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_Not_All_SIM_Started()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_TimingInfo()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_ReportTimingDrift()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_ModifyTimingDrift()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_Reschedule_Status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1T_TRC_SFN_Stop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1T_TRC_SFN_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Reschedule()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Rx()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_State_RunningSIM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1T_TRC_SFN_Data()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Report()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_RetryAllow()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_InternalStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Compensation()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Avail_Dec_Frms()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_AdjustProtectPriority()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_ReStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_CMResult()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_CM_Result()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_TwoStage_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_MPS_Position()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Pending_Stop_Report()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1T_TRC_SIB_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1T_TRC_SIB_Reconfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_Reschedule()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_Rx()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_Rpt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1T_TRC_SIB_CM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_AdjustProtectPriority()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_PCH_Type_Changed()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1T_TRC_ConfigBAList()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_M()
#define ChkL1MsgFltr_UL1T_TRC_CellInfo()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CellInfo_1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_ConfigDetectedCell()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_BA_Mapping()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_M()
#define ChkL1MsgFltr_UL1T_TRC_BAStatusUpdateInfo()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Alloc_CMM_Report()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_DCH_1st_Tick()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Prepare_BA_status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_DeleteBA()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Protected_in_DCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_EvaluateReq()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Trigger_EnhancedCM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_DetectedCell_InvalidTM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_freq_not_existed()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_ConfigBA_by_CCM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Restore_CM_result()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Compensate_CMCS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_AlarmTimeoutForInterF()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CM_freq_spec_compress_mode()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CM_RptHasCleared()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMHalt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_ConfigCell()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMResult()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMResult_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMDone()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_PrioCMCS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_PrioCMCS_InterF_EFACH_DRX()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMStart_Failed()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMReportStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAlphaFilter()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_L()
#define ChkL1MsgFltr_UL1T_TRC_CMReport()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CM_AllocReportEnhancedCM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager_MAX()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager2()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager2_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1I_TRC_CMAVG_Put()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1I_TRC_CMAVG_Apply()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1I_TRC_CMAVG_Apply_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1T_TRC_CMAVG_LINValue()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1T_TRC_CMAVG_DBG()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1_TRC_CMTreselection()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASCurrentAnt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSelectDefaultAnt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASForceTxAnt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASGuardExpire()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSwitchBackExpire()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASEnterState()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASDedicateAllowed()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASPCHNotAllowed()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASAbortSwitch()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSwitchAnt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASRevertSwitch()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASStartSwitchBack()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSwitchBack()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSwitchingMetric()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType1Conditions()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType2Conditions()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType1Evaluate()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType2Evaluate()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType1SBConditions()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType2SBConditions()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_FuncTest()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_Floating_Threshold()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_SetAntOnTestSIM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_DBG_SetAntIdx_TestSIM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_Overlap_freq()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_return_due2_overlap()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_Set_CS_Flag()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_Set_CS_Flag_Status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_start_ras_status1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_start_ras_status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_avg_buff_index()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_live_sim_status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_ras_status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_inisde_firsttimer()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_ras_status_inCMCS_DCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_ras_status_inCMCS_FACH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_Seting_tas_type()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_get_tas_type()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_SET_TAS_TYPE_DONE()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_Evaluate_function()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_Evaluate_initial_status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_Evaluate_end_status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_antennaonoff()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_antennaonoff1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_rscp_rssi_ecno_avg()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_RAS_antennaonoff2()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSendCMReport()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASDeriveMeasSample()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASDeriveMeasSample_Div()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASQueueMeasSample()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASInitDedi()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASInitIdle()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_ServingIdx()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_HTP_Power()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_HTP_Ratio()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_DPCCH_TXPWR()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_Dynamic_Barrier()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_Avg_Buf_idx()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_Floating_Thre()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_Type1_NoDiv()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_StopTimer()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_SendTasStats()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_RF_TUNING_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CSDone()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_CSResult()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_L()
#define ChkL1MsgFltr_UL1I_TRC_CSStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_CS_Stop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_CS_RptHasCleared()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_CS_PreCSPending_Return()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_Unlock_gapStopCnf()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DMStopGap()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_SetGap()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_DRXTick()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_CMCSTickInfo()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_SetCurrActiveMode()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_AssignGAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_GapStatus()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_Start_GAP_Timer1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_Start_GAP_Timer2()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_Start_GAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_TimeSyncStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_TimeSyncReport()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_ShowUSC()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_Cancel_ActiveGAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Cancel_2G_GAP_Cnf()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Query_GAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Query_GAP_SM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Query_PSEUDO()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Sleep_Ind()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_EFACHDRX_NeedGap()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_EFACHDRX_Disable()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_EFACHDRX_SkipGap()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_EFACHDRX_Cm_Session_Info()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMA_Auto_Gap_Assign()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMA_Auto_Gap_Update()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMS_Auto_Gap_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMS_Auto_Gap_Req()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMS_Auto_Gap_AvailStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMS_Auto_Gap_Assign()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_RTB_Timer()	ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_H()
#define ChkL1MsgFltr_UL1I_TRC_AGPS_INFO()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_ADJUSTMENT_STATUS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Resume()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Delay()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()


#endif
