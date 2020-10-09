#ifndef L1TRC_UL1C_PRI1_DEF_H
#define L1TRC_UL1C_PRI1_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1I_TRC_CM_Obsolete(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0026, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CM_Obsolete(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_CM_Obsolete_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0026, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PS_TASFreqScanAnt(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0126, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PS_TASFreqScanAnt(v1, v2)
#endif
#define UL1I_TRC_PS_TASFreqScanAnt_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0126, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PS_Result(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0226, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_PS_Result(v1, v2)
#endif
#define UL1I_TRC_PS_Result_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0226, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PS_SortedFreq(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0326, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PS_SortedFreq(v1, v2, v3)
#endif
#define UL1I_TRC_PS_SortedFreq_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0326, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_Result(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0426, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_Result(v1, v2, v3)
#endif
#define UL1I_TRC_FS_Result_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0426, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_State(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0526, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_State(v1, v2, v3)
#endif
#define UL1I_TRC_FS_State_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0526, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_UL1_Suspend(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0626, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_UL1_Suspend(v1, v2, v3)
#endif
#define UL1I_TRC_FS_UL1_Suspend_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0626, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_FS_Start(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0726, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_FS_Start(v1, v2, v3)
#endif
#define UL1T_TRC_FS_Start_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0726, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_FS_Cont(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0826, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_FS_Cont(v1)
#endif
#define UL1T_TRC_FS_Cont_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0826, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_FS_Suspend(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0926, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_FS_Suspend(v1)
#endif
#define UL1T_TRC_FS_Suspend_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0926, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_FB_PwrScanNext(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A26, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_FB_PwrScanNext(v1, v2, v3)
#endif
#define UL1I_TRC_FS_FB_PwrScanNext_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A26, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_AutoGap_State(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B26, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_FS_AutoGap_State(v1, v2)
#endif
#define UL1I_TRC_FS_AutoGap_State_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B26, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_ScanSuspend(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_ScanSuspend(v1, v2, v3, v4)
#endif
#define UL1I_TRC_FS_ScanSuspend_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_ProcessScanStart(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_ProcessScanStart(v1, v2, v3, v4)
#endif
#define UL1I_TRC_FS_ProcessScanStart_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_NextFullbandAnt(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_NextFullbandAnt(v1, v2)
#endif
#define UL1I_TRC_FS_NextFullbandAnt_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_SuspendFullbandScan(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F26, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_SuspendFullbandScan(v1, v2, v3)
#endif
#define UL1I_TRC_FS_SuspendFullbandScan_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F26, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ECS_Start(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1026, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ECS_Start(v1, v2)
#endif
#define UL1T_TRC_ECS_Start_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1026, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ECS_Stop(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1126, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ECS_Stop(v1)
#endif
#define UL1T_TRC_ECS_Stop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1126, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ECS_InternalStop(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1226, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ECS_InternalStop(v1)
#endif
#define UL1I_TRC_ECS_InternalStop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1226, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ECS_Status(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1326, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_ECS_Status(v1, v2)
#endif
#define UL1I_TRC_ECS_Status_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1326, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ECS_Result(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1426, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ECS_Result(v1, v2, v3)
#endif
#define UL1I_TRC_ECS_Result_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1426, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_BeforeGetPendingResult(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1526, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_BeforeGetPendingResult(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_FS_BeforeGetPendingResult_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1526, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_AfterGetPendingResult(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1626, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_AfterGetPendingResult(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_FS_AfterGetPendingResult_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1626, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_AfterResume(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1726, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_AfterResume(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_FS_AfterResume_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1726, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HFS_DBG(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1826, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HFS_DBG(v1, v2, v3)
#endif
#define UL1I_TRC_HFS_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1826, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HFS_DBG2(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1926, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HFS_DBG2(v1, v2, v3)
#endif
#define UL1I_TRC_HFS_DBG2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1926, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Get_ULDCHData(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A26, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Get_ULDCHData(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_Get_ULDCHData_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A26, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Get_ULDCHTRCHData(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B26, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Get_ULDCHTRCHData(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_Get_ULDCHTRCHData_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B26, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_StartULDCh(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C26, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_StartULDCh(v1, v2, v3, v4)
#endif
#define UL1I_TRC_StartULDCh_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C26, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TxStatus(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TxStatus(v1, v2, v3)
#endif
#define UL1I_TRC_TxStatus_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL_Timer_TFC_CB(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UL_Timer_TFC_CB(v1, v2)
#endif
#define UL1I_TRC_UL_Timer_TFC_CB_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL_Timer_Data_CB(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UL_Timer_Data_CB(v1, v2, v3, v4)
#endif
#define UL1I_TRC_UL_Timer_Data_CB_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Report_ULCB_Data(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2026, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Report_ULCB_Data(v1, v2, v3, v4)
#endif
#define UL1T_TRC_Report_ULCB_Data_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2026, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Report_ULCB_TFC(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2126, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Report_ULCB_TFC(v1, v2)
#endif
#define UL1T_TRC_Report_ULCB_TFC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2126, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_StopULDCh(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2226, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_StopULDCh(v1, v2)
#endif
#define UL1I_TRC_StopULDCh_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2226, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ULDCH_next_timer_delay(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2326, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_ULDCH_next_timer_delay(v1, v2)
#endif
#define UL1I_TRC_ULDCH_next_timer_delay_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2326, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ULDCH_UL1D_Intf(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2426, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ULDCH_UL1D_Intf(v1, v2, v3)
#endif
#define UL1I_TRC_ULDCH_UL1D_Intf_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2426, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ULDCH_Set_MAC_Event(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2526, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_ULDCH_Set_MAC_Event(v1, v2)
#endif
#define UL1I_TRC_ULDCH_Set_MAC_Event_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2526, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Get_DLDCHData(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2626, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_Get_DLDCHData(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Get_DLDCHData_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2626, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Get_DLDCHTRCHData(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2726, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_Get_DLDCHTRCHData(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Get_DLDCHTRCHData_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2726, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RefDCH(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2826, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_RefDCH(v1, v2)
#endif
#define UL1I_TRC_RefDCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2826, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RefDCHCFN(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2926, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_RefDCHCFN(v1, v2, v3)
#endif
#define UL1I_TRC_RefDCHCFN_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2926, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DLSync_State(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DLSync_State(v1, v2, v3)
#endif
#define UL1I_TRC_DLSync_State_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DLSync_Qin(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DLSync_Qin(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DLSync_Qin_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_New_DPCH_Type(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C26, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_New_DPCH_Type(v1, v2, v3)
#endif
#define UL1I_TRC_New_DPCH_Type_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C26, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DPCH_Type(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D26, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_DPCH_Type(v1, v2)
#endif
#define UL1I_TRC_DPCH_Type_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D26, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ReconfigDCH(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2E26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ReconfigDCH(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_ReconfigDCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2E26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ReconfigDCH_ASAP(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ReconfigDCH_ASAP(v1, v2, v3, v4)
#endif
#define UL1T_TRC_ReconfigDCH_ASAP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_LoopMode2(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3026, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1T_TRC_LoopMode2(v1, v2, v3, v4)
#endif
#define UL1T_TRC_LoopMode2_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3026, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ASU(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3126, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ASU(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_ASU_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3126, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DL_DCHQual(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3226, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DL_DCHQual(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1I_TRC_DL_DCHQual_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3226, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DL_CRC_Value(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3326, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_DL_CRC_Value(v1, v2)
#endif
#define UL1I_TRC_DL_CRC_Value_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3326, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DL_Sync_Type(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3426, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DL_Sync_Type(v1, v2, v3)
#endif
#define UL1I_TRC_DL_Sync_Type_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3426, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DL_Sync_Info(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3526, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_DL_Sync_Info(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_DL_Sync_Info_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3526, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DLSync_Config(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3626, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DLSync_Config(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DLSync_Config_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3626, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ReconfigDCH_TTI(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3726, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ReconfigDCH_TTI(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_ReconfigDCH_TTI_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3726, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ReconfigDCH_TGPS(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3826, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ReconfigDCH_TGPS(v1, v2, v3)
#endif
#define UL1T_TRC_ReconfigDCH_TGPS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3826, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Modify_Abort(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3926, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Modify_Abort(v1, v2, v3)
#endif
#define UL1T_TRC_Modify_Abort_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3926, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UpdateDpchRl(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UpdateDpchRl(v1, v2, v3, v4)
#endif
#define UL1I_TRC_UpdateDpchRl_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Sec_ASU_Config(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B26, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Sec_ASU_Config(v1, v2, v3)
#endif
#define UL1T_TRC_Sec_ASU_Config_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B26, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Sec_DLDCH_Config(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C26, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_Sec_DLDCH_Config(v1, v2)
#endif
#define UL1I_TRC_Sec_DLDCH_Config_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C26, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DLDCH_TriggerExtendRLF(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D26, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_DLDCH_TriggerExtendRLF(v1, v2)
#endif
#define UL1I_TRC_DLDCH_TriggerExtendRLF_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D26, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FMO(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E26, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_FMO(v1, v2)
#endif
#define UL1I_TRC_FMO_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E26, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_FMO_Config(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3F26, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_FMO_Config(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_FMO_Config_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3F26, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FACH_Data(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4026, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FACH_Data(v1, v2)
#endif
#define UL1I_TRC_FACH_Data_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4026, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DRX_GAP(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4126, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DRX_GAP(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DRX_GAP_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4126, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DRX_Change(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4226, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DRX_Change(v1, v2, v3)
#endif
#define UL1I_TRC_DRX_Change_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4226, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SCS_Start(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4326, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SCS_Start(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_SCS_Start_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4326, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SCS_Stop(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4426, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SCS_Stop(v1)
#endif
#define UL1T_TRC_SCS_Stop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4426, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SCS_State(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4526, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SCS_State(v1, v2, v3)
#endif
#define UL1I_TRC_SCS_State_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4526, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SCS_Result(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4626, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SCS_Result(v1, v2)
#endif
#define UL1I_TRC_SCS_Result_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4626, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SCS_Conflict(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4726, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SCS_Conflict(v1, v2, v3)
#endif
#define UL1I_TRC_SCS_Conflict_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4726, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_MBSCS_ResourceConflict(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4826, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_MBSCS_ResourceConflict(v1, v2)
#endif
#define UL1I_TRC_MBSCS_ResourceConflict_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4826, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_MBSCS_Resource(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4926, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_MBSCS_Resource(v1, v2, v3, v4)
#endif
#define UL1I_TRC_MBSCS_Resource_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4926, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SCS_Init(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A26, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SCS_Init(v1)
#endif
#define UL1I_TRC_SCS_Init_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A26, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_Status(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B26, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_Status(v1, v2)
#endif
#define UL1I_TRC_PCH_Status_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B26, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_PICHOverlapFrames(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4C26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_PICHOverlapFrames(v1, v2)
#endif
#define UL1I_TRC_PCH_PICHOverlapFrames_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4C26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ReconfigPCH(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4D26, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1T_TRC_ReconfigPCH(v1, v2, v3, v4)
#endif
#define UL1T_TRC_ReconfigPCH_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4D26, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_BlindPCH(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E26, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_BlindPCH(v1, v2)
#endif
#define UL1I_TRC_BlindPCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E26, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_drx_cycle2_life(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_drx_cycle2_life(v1, v2)
#endif
#define UL1I_TRC_PCH_drx_cycle2_life_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_SmartPagingState(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5026, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_SmartPagingState(v1, v2, v3)
#endif
#define UL1I_TRC_PCH_SmartPagingState_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5026, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_SmartPagingEvaluate(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5126, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_SmartPagingEvaluate(v1, v2, v3)
#endif
#define UL1I_TRC_PCH_SmartPagingEvaluate_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5126, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_SmartPagingLog(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5226, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v7)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_SmartPagingLog(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1I_TRC_PCH_SmartPagingLog_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5226, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v7)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_SmartCSState(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5326, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_SmartCSState(v1, v2)
#endif
#define UL1I_TRC_PCH_SmartCSState_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5326, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_PCH_SmartCSLog(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5426, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_PCH_SmartCSLog(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1T_TRC_PCH_SmartCSLog_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5426, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_SmartCSSkip(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5526, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_SmartCSSkip(v1, v2)
#endif
#define UL1I_TRC_PCH_SmartCSSkip_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5526, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_UL1D_Start_PCH(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5626, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_UL1D_Start_PCH(v1, v2, v3)
#endif
#define UL1I_TRC_PCH_UL1D_Start_PCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5626, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_UL1D_CheckResource(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5726, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_UL1D_CheckResource(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_PCH_UL1D_CheckResource_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5726, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_ChangeTo_NormalPI(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5826, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_ChangeTo_NormalPI(v1, v2)
#endif
#define UL1I_TRC_PCH_ChangeTo_NormalPI_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5826, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_NormalPI_Period(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5926, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_NormalPI_Period(v1, v2)
#endif
#define UL1I_TRC_PCH_NormalPI_Period_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5926, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RescheduleRTBTimer(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5A26, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RescheduleRTBTimer(v1)
#endif
#define UL1I_TRC_PCH_RescheduleRTBTimer_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5A26, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RescheduleRTBTimerImm(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5B26, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RescheduleRTBTimerImm(v1)
#endif
#define UL1I_TRC_PCH_RescheduleRTBTimerImm_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5B26, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RxDEnSkip(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RxDEnSkip(v1, v2)
#endif
#define UL1I_TRC_PCH_RxDEnSkip_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RxDEn(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5D26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RxDEn(v1, v2)
#endif
#define UL1I_TRC_PCH_RxDEn_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5D26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RxDSwitchDelay(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5E26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RxDSwitchDelay(v1, v2)
#endif
#define UL1I_TRC_PCH_RxDSwitchDelay_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5E26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RxDEcnoRscp(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5F26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RxDEcnoRscp(v1, v2, v3, v4)
#endif
#define UL1I_TRC_PCH_RxDEcnoRscp_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5F26, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RxDServingInfo(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6026, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RxDServingInfo(v1, v2, v3)
#endif
#define UL1I_TRC_PCH_RxDServingInfo_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6026, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_TASEvaluate(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6126, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_TASEvaluate(v1, v2)
#endif
#define UL1I_TRC_PCH_TASEvaluate_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6126, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_TASProcOngoing(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6226, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_TASProcOngoing(v1)
#endif
#define UL1I_TRC_PCH_TASProcOngoing_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6226, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_TASStartTimer(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6326, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_TASStartTimer(v1, v2)
#endif
#define UL1I_TRC_PCH_TASStartTimer_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6326, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_TASTriggerUnsync(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6426, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_TASTriggerUnsync(v1, v2)
#endif
#define UL1I_TRC_PCH_TASTriggerUnsync_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6426, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TxAccess(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6526, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TxAccess(v1, v2, v3)
#endif
#define UL1T_TRC_TxAccess_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6526, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_RAChData(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6626, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1T_TRC_RAChData(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_RAChData_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6626, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RACH_ASCSetting(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6726, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RACH_ASCSetting(v1, v2, v3)
#endif
#define UL1I_TRC_RACH_ASCSetting_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6726, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Get_Access_Slot(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6826, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Get_Access_Slot(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_Get_Access_Slot_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6826, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RACH_Start(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6926, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_RACH_Start(v1, v2)
#endif
#define UL1I_TRC_RACH_Start_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6926, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1T_TRC_RACH_NextASS(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6A26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1T_TRC_RACH_NextASS(v1, v2, v3)
#endif
#define UL1T_TRC_RACH_NextASS_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6A26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TxAccess(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6B26, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_TxAccess(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_TxAccess_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6B26, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DelayTxAccess_CCM(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6C26, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)), (long)(v5));\
	} while(0)
#else
	#define UL1I_TRC_DelayTxAccess_CCM(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_DelayTxAccess_CCM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6C26, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DelayTxAccess_FMO(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6D26, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_DelayTxAccess_FMO(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DelayTxAccess_FMO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6D26, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_InitReport(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6E26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1T_TRC_InitReport(v1, v2, v3)
#endif
#define UL1T_TRC_InitReport_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6E26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1AC_TRC_EvtReport(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F26, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1AC_TRC_EvtReport(v1, v2)
#endif
#define UL1AC_TRC_EvtReport_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F26, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_AllocDlDataReport(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7026, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_AllocDlDataReport(v1, v2, v3, v4)
#endif
#define UL1I_TRC_AllocDlDataReport_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7026, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FreeDLDataReport(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7126, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_FreeDLDataReport(v1, v2, v3, v4)
#endif
#define UL1I_TRC_FreeDLDataReport_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7126, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1_TRC_FreeReport(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7226, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_FreeReport(v1, v2, v3)
#endif
#define UL1_TRC_FreeReport_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7226, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_HoldReport(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7326, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HoldReport(v1, v2, v3)
#endif
#define UL1T_TRC_HoldReport_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7326, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_State_Conflict(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7426, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_State_Conflict(v1, v2)
#endif
#define UL1I_TRC_UL1D_State_Conflict_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7426, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EM_Switch(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7526, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EM_Switch(v1, v2)
#endif
#define UL1T_TRC_EM_Switch_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7526, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EM_RL_Sync_Switch(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x7626, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_EM_RL_Sync_Switch(v1)
#endif
#define UL1I_TRC_EM_RL_Sync_Switch_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x7626, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_REDUMP(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7726, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_REDUMP(v1)
#endif
#define UL1T_TRC_REDUMP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7726, (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1C_PRI1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1I_TRC_CM_Obsolete(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_PS_TASFreqScanAnt(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_PS_Result(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1I_TRC_PS_SortedFreq(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_FS_Result(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_FS_State(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_FS_UL1_Suspend(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_FS_Start(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_FS_Cont(unsigned char v1);
void L1TRC_Send_UL1T_TRC_FS_Suspend(unsigned char v1);
void L1TRC_Send_UL1I_TRC_FS_FB_PwrScanNext(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_FS_AutoGap_State(unsigned char v1, long v2);
void L1TRC_Send_UL1I_TRC_FS_ScanSuspend(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_FS_ProcessScanStart(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_FS_NextFullbandAnt(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_FS_SuspendFullbandScan(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_ECS_Start(unsigned char v1, short v2);
void L1TRC_Send_UL1T_TRC_ECS_Stop(unsigned char v1);
void L1TRC_Send_UL1I_TRC_ECS_InternalStop(unsigned char v1);
void L1TRC_Send_UL1I_TRC_ECS_Status(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_ECS_Result(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_FS_BeforeGetPendingResult(unsigned char v1, short v2, char v3, short v4, char v5, char v6);
void L1TRC_Send_UL1I_TRC_FS_AfterGetPendingResult(unsigned char v1, short v2, char v3, short v4, char v5, char v6);
void L1TRC_Send_UL1I_TRC_FS_AfterResume(unsigned char v1, short v2, char v3, short v4, char v5, char v6);
void L1TRC_Send_UL1I_TRC_HFS_DBG(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_HFS_DBG2(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_Get_ULDCHData(unsigned char v1, short v2, char v3, char v4, short v5, char v6);
void L1TRC_Send_UL1I_TRC_Get_ULDCHTRCHData(unsigned char v1, char v2, short v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_StartULDCh(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_TxStatus(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_UL_Timer_TFC_CB(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_UL_Timer_Data_CB(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_Report_ULCB_Data(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_Report_ULCB_TFC(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_StopULDCh(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_ULDCH_next_timer_delay(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_ULDCH_UL1D_Intf(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_ULDCH_Set_MAC_Event(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_Get_DLDCHData(unsigned char v1, short v2, char v3, short v4);
void L1TRC_Send_UL1I_TRC_Get_DLDCHTRCHData(unsigned char v1, char v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_RefDCH(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_RefDCHCFN(unsigned char v1, long v2, short v3);
void L1TRC_Send_UL1I_TRC_DLSync_State(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_DLSync_Qin(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_New_DPCH_Type(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_DPCH_Type(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_ReconfigDCH(unsigned char v1, short v2, short v3, char v4, char v5, char v6, short v7, char v8);
void L1TRC_Send_UL1T_TRC_ReconfigDCH_ASAP(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_LoopMode2(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_UL1T_TRC_ASU(unsigned char v1, short v2, short v3, char v4, char v5, short v6);
void L1TRC_Send_UL1I_TRC_DL_DCHQual(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1I_TRC_DL_CRC_Value(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1I_TRC_DL_Sync_Type(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_DL_Sync_Info(unsigned char v1, short v2, char v3, short v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_DLSync_Config(unsigned char v1, short v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_ReconfigDCH_TTI(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_ReconfigDCH_TGPS(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_Modify_Abort(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1I_TRC_UpdateDpchRl(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_Sec_ASU_Config(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_Sec_DLDCH_Config(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_DLDCH_TriggerExtendRLF(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_FMO(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_FMO_Config(unsigned char v1, char v2, char v3, char v4, short v5, char v6, char v7);
void L1TRC_Send_UL1I_TRC_FACH_Data(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_DRX_GAP(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_DRX_Change(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_SCS_Start(unsigned char v1, short v2, short v3, char v4, char v5);
void L1TRC_Send_UL1T_TRC_SCS_Stop(unsigned char v1);
void L1TRC_Send_UL1I_TRC_SCS_State(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_SCS_Result(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_SCS_Conflict(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_MBSCS_ResourceConflict(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_MBSCS_Resource(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_SCS_Init(unsigned char v1);
void L1TRC_Send_UL1I_TRC_PCH_Status(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_PCH_PICHOverlapFrames(unsigned char v1, short v2);
void L1TRC_Send_UL1T_TRC_ReconfigPCH(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_BlindPCH(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_PCH_drx_cycle2_life(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_PCH_SmartPagingState(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_PCH_SmartPagingEvaluate(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_PCH_SmartPagingLog(unsigned char v1, char v2, char v3, short v4, short v5, short v6, char v7, short v8, short v9);
void L1TRC_Send_UL1I_TRC_PCH_SmartCSState(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_PCH_SmartCSLog(unsigned char v1, char v2, char v3, short v4, short v5, short v6, char v7, short v8, short v9, short v10);
void L1TRC_Send_UL1I_TRC_PCH_SmartCSSkip(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_PCH_UL1D_Start_PCH(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_PCH_UL1D_CheckResource(unsigned char v1, char v2, char v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_PCH_ChangeTo_NormalPI(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_PCH_NormalPI_Period(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1I_TRC_PCH_RescheduleRTBTimer(unsigned char v1);
void L1TRC_Send_UL1I_TRC_PCH_RescheduleRTBTimerImm(unsigned char v1);
void L1TRC_Send_UL1I_TRC_PCH_RxDEnSkip(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_PCH_RxDEn(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_PCH_RxDSwitchDelay(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_PCH_RxDEcnoRscp(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_PCH_RxDServingInfo(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_PCH_TASEvaluate(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_PCH_TASProcOngoing(unsigned char v1);
void L1TRC_Send_UL1I_TRC_PCH_TASStartTimer(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_PCH_TASTriggerUnsync(unsigned char v1, short v2);
void L1TRC_Send_UL1T_TRC_TxAccess(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1T_TRC_RAChData(unsigned char v1, short v2, short v3, char v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_RACH_ASCSetting(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_Get_Access_Slot(unsigned char v1, char v2, short v3, char v4, char v5, char v6);
void L1TRC_Send_UL1I_TRC_RACH_Start(unsigned char v1, long v2);
void L1TRC_Send_UL1T_TRC_RACH_NextASS(unsigned char v1, short v2, long v3);
void L1TRC_Send_UL1I_TRC_TxAccess(unsigned char v1, char v2, long v3, char v4, short v5);
void L1TRC_Send_UL1I_TRC_DelayTxAccess_CCM(unsigned char v1, char v2, short v3, short v4, long v5);
void L1TRC_Send_UL1I_TRC_DelayTxAccess_FMO(unsigned char v1, short v2, short v3, long v4);
void L1TRC_Send_UL1T_TRC_InitReport(unsigned char v1, short v2, unsigned long v3);
void L1TRC_Send_UL1AC_TRC_EvtReport(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_AllocDlDataReport(unsigned char v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1I_TRC_FreeDLDataReport(unsigned char v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1_TRC_FreeReport(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1T_TRC_HoldReport(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_UL1D_State_Conflict(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_EM_Switch(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_EM_RL_Sync_Switch(short v1);
void L1TRC_Send_UL1T_TRC_REDUMP(unsigned char v1);

void Set_UL1C_PRI1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1C_PRI1()	(UL1C_PRI1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_CM_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_ERROR_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_EM_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_CM_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_CM_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[4]&0x10)!=0))
#define ChkL1MsgFltr_UL1I_TRC_CM_Obsolete()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_PS_TASFreqScanAnt()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_PS_Result()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_PS_SortedFreq()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_Result()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_State()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_UL1_Suspend()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1T_TRC_FS_Start()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1T_TRC_FS_Cont()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1T_TRC_FS_Suspend()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_FB_PwrScanNext()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_AutoGap_State()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_ScanSuspend()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_ProcessScanStart()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_NextFullbandAnt()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_SuspendFullbandScan()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1T_TRC_ECS_Start()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1T_TRC_ECS_Stop()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_ECS_InternalStop()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_ECS_Status()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_ECS_Result()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_BeforeGetPendingResult()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_AfterGetPendingResult()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_AfterResume()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_HFS_DBG()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_HFS_DBG2()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_Get_ULDCHData()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Get_ULDCHTRCHData()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_StartULDCh()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_TxStatus()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL_Timer_TFC_CB()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL_Timer_Data_CB()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Report_ULCB_Data()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Report_ULCB_TFC()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_StopULDCh()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_ULDCH_next_timer_delay()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_ULDCH_UL1D_Intf()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_ULDCH_Set_MAC_Event()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Get_DLDCHData()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Get_DLDCHTRCHData()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_RefDCH()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_RefDCHCFN()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DLSync_State()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DLSync_Qin()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_New_DPCH_Type()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DPCH_Type()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ReconfigDCH()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ReconfigDCH_ASAP()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_LoopMode2()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ASU()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DL_DCHQual()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DL_CRC_Value()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DL_Sync_Type()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DL_Sync_Info()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DLSync_Config()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ReconfigDCH_TTI()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ReconfigDCH_TGPS()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Modify_Abort()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UpdateDpchRl()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Sec_ASU_Config()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Sec_DLDCH_Config()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DLDCH_TriggerExtendRLF()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_FMO()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()
#define ChkL1MsgFltr_UL1T_TRC_FMO_Config()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()
#define ChkL1MsgFltr_UL1I_TRC_FACH_Data()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()
#define ChkL1MsgFltr_UL1I_TRC_DRX_GAP()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()
#define ChkL1MsgFltr_UL1I_TRC_DRX_Change()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()
#define ChkL1MsgFltr_UL1T_TRC_SCS_Start()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1T_TRC_SCS_Stop()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_SCS_State()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_SCS_Result()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_SCS_Conflict()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_MBSCS_ResourceConflict()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_MBSCS_Resource()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_SCS_Init()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_Status()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_PICHOverlapFrames()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ReconfigPCH()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_BlindPCH()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_drx_cycle2_life()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_SmartPagingState()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_SmartPagingEvaluate()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_SmartPagingLog()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_SmartCSState()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1T_TRC_PCH_SmartCSLog()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_SmartCSSkip()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_UL1D_Start_PCH()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_UL1D_CheckResource()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_ChangeTo_NormalPI()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_NormalPI_Period()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RescheduleRTBTimer()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RescheduleRTBTimerImm()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RxDEnSkip()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RxDEn()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RxDSwitchDelay()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RxDEcnoRscp()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RxDServingInfo()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_TASEvaluate()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_TASProcOngoing()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_TASStartTimer()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_TASTriggerUnsync()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1T_TRC_TxAccess()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1T_TRC_RAChData()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_RACH_ASCSetting()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_Get_Access_Slot()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_RACH_Start()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1T_TRC_RACH_NextASS()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_TxAccess()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_DelayTxAccess_CCM()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_DelayTxAccess_FMO()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1T_TRC_InitReport()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_L()
#define ChkL1MsgFltr_UL1AC_TRC_EvtReport()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_H()
#define ChkL1MsgFltr_UL1I_TRC_AllocDlDataReport()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_H()
#define ChkL1MsgFltr_UL1I_TRC_FreeDLDataReport()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_H()
#define ChkL1MsgFltr_UL1_TRC_FreeReport()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_L()
#define ChkL1MsgFltr_UL1T_TRC_HoldReport()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_L()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_State_Conflict()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_H()
#define ChkL1MsgFltr_UL1T_TRC_EM_Switch()	ChkL1ClsFltr_UL1C_PRI1_UL1C_EM_L()
#define ChkL1MsgFltr_UL1I_TRC_EM_RL_Sync_Switch()	ChkL1ClsFltr_UL1C_PRI1_UL1C_EM_L()
#define ChkL1MsgFltr_UL1T_TRC_REDUMP()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ERROR_L()


#endif
