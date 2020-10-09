#ifndef L1TRC_L1DM_DEF_H
#define L1TRC_L1DM_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1DM_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1DM_Str_DMState(v1)  (unsigned char)(v1+2)
#define L1DM_Str_2g_resel_mode(v1)  (unsigned char)(v1+15)
#define L1DM_Str_switch_2G_resel_mode_when(v1)  (unsigned char)(v1+17)
#define L1DM_Str_gap_purpose(v1)  (unsigned char)(v1+22)
#define L1DM_Str_pm_period(v1)  (unsigned char)(v1+28)
#define L1DM_Str_ignore_gap_cause(v1)  (unsigned char)(v1+30)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_SB(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0018, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_SB(v1, v2, v3, v4)
#endif
#define L1DM_MSG_SB_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0018, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_FB(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0118, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)));\
	} while(0)
#else
	#define L1DM_MSG_FB(v1, v2, v3, v4)
#endif
#define L1DM_MSG_FB_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0118, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_IRATSYNC(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0218, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v4));\
	} while(0)
#else
	#define L1DM_MSG_IRATSYNC(v1, v2, v3, v4)
#endif
#define L1DM_MSG_IRATSYNC_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0218, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMCell(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0318, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_PMCell(v1, v2)
#endif
#define L1DM_MSG_PMCell_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0318, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_3GGap(v1, v2, v3, v4, v5, v6) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0418, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v6)), (unsigned long)(v2), (long)(v4));\
	} while(0)
#else
	#define L1DM_MSG_3GGap(v1, v2, v3, v4, v5, v6)
#endif
#define L1DM_MSG_3GGap_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0418, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v6)), (unsigned long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_AbortBSIC(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0518, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_AbortBSIC(v1)
#endif
#define L1DM_MSG_AbortBSIC_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0518, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GGap(v1, v2, v3, v4, v5) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0618, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v4));\
	} while(0)
#else
	#define L1DM_MSG_2GGap(v1, v2, v3, v4, v5)
#endif
#define L1DM_MSG_2GGap_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0618, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GGapStop(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0718, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_2GGapStop(v1)
#endif
#define L1DM_MSG_2GGapStop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0718, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_StartGapSchedule(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0818, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_StartGapSchedule(v1)
#endif
#define L1DM_MSG_StartGapSchedule_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0818, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_StopGapSchedule(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0918, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_StopGapSchedule(v1, v2)
#endif
#define L1DM_MSG_StopGapSchedule_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0918, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_FMOLock(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A18, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1DM_MSG_FMOLock(v1, v2)
#endif
#define L1DM_MSG_FMOLock_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A18, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_CancelGap(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B18, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_CancelGap(v1)
#endif
#define L1DM_MSG_CancelGap_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B18, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_Lock2G(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C18, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1DM_MSG_Lock2G(v1, v2)
#endif
#define L1DM_MSG_Lock2G_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C18, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_DMState(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D18, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1DM_MSG_DMState(v1, v2)
#endif
#define L1DM_MSG_DMState_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D18, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMTick(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E18, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_PMTick(v1, v2)
#endif
#define L1DM_MSG_PMTick_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E18, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMTick_HPSearch(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F18, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_PMTick_HPSearch(v1, v2)
#endif
#define L1DM_MSG_PMTick_HPSearch_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F18, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMDone(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1018, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_PMDone(v1, v2, v3, v4)
#endif
#define L1DM_MSG_PMDone_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1018, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_DeleteGap(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1118, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_DeleteGap(v1)
#endif
#define L1DM_MSG_DeleteGap_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1118, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GAP_STANDBY(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x1218, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v9)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v5), (long)(v8), (long)(v10), (long)(v12));\
	} while(0)
#else
	#define L1DM_MSG_GAP_STANDBY(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define L1DM_MSG_GAP_STANDBY_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_8_DATA(TRC_MERGE_2S(0x1218, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v9)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v5), (long)(v8), (long)(v10), (long)(v12))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GapType_TD(v1, v2, v3, v4, v5) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1318, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_GapType_TD(v1, v2, v3, v4, v5)
#endif
#define L1DM_MSG_GapType_TD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1318, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_SetGap_TD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1418, (short)(v2)), TRC_MERGE_2S((short)(v5), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), (unsigned char)(v7), (unsigned char)(v10)), (long)(v3), (long)(v6), (long)(v9));\
	} while(0)
#else
	#define L1DM_MSG_SetGap_TD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define L1DM_MSG_SetGap_TD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1418, (short)(v2)), TRC_MERGE_2S((short)(v5), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), (unsigned char)(v7), (unsigned char)(v10)), (long)(v3), (long)(v6), (long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_Ignore_gaps(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1518, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)));\
	} while(0)
#else
	#define L1DM_MSG_Ignore_gaps(v1, v2, v3, v4)
#endif
#define L1DM_MSG_Ignore_gaps_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1518, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_BSICSchedule_TD(v1, v2, v3, v4, v5, v6) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1618, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v6));\
	} while(0)
#else
	#define L1DM_MSG_BSICSchedule_TD(v1, v2, v3, v4, v5, v6)
#endif
#define L1DM_MSG_BSICSchedule_TD_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1618, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMLock_TD(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1718, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1DM_MSG_PMLock_TD(v1, v2)
#endif
#define L1DM_MSG_PMLock_TD_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1718, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMPeriod(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1818, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1DM_MSG_PMPeriod(v1, v2, v3, v4)
#endif
#define L1DM_MSG_PMPeriod_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1818, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_ReselMode_Standby(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1918, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_ReselMode_Standby(v1, v2, v3)
#endif
#define L1DM_MSG_ReselMode_Standby_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1918, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GAutoGapStart(v1, v2, v3, v4, v5) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1A18, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define L1DM_MSG_2GAutoGapStart(v1, v2, v3, v4, v5)
#endif
#define L1DM_MSG_2GAutoGapStart_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1A18, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GAutoGapEnd(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B18, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_2GAutoGapEnd(v1)
#endif
#define L1DM_MSG_2GAutoGapEnd_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B18, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GAutoGAPTimer(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C18, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1DM_MSG_2GAutoGAPTimer(v1, v2)
#endif
#define L1DM_MSG_2GAutoGAPTimer_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C18, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GSMAutoGAPGet(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D18, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define L1DM_MSG_GSMAutoGAPGet(v1, v2, v3)
#endif
#define L1DM_MSG_GSMAutoGAPGet_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D18, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GSMAutoGAPPut(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E18, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_GSMAutoGAPPut(v1)
#endif
#define L1DM_MSG_GSMAutoGAPPut_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E18, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GSMAutoGAPConfirm(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F18, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3));\
	} while(0)
#else
	#define L1DM_MSG_GSMAutoGAPConfirm(v1, v2, v3)
#endif
#define L1DM_MSG_GSMAutoGAPConfirm_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F18, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GSMAutoGAPStop(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2018, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define L1DM_MSG_GSMAutoGAPStop(v1, v2)
#endif
#define L1DM_MSG_GSMAutoGAPStop_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2018, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GetGSMAutoGAPLength(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2118, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1DM_MSG_GetGSMAutoGAPLength(v1, v2)
#endif
#define L1DM_MSG_GetGSMAutoGAPLength_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2118, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_LTE_Connecedt_GAP(v1, v2, v3, v4, v5) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2218, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_LTE_Connecedt_GAP(v1, v2, v3, v4, v5)
#endif
#define L1DM_MSG_LTE_Connecedt_GAP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2218, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1DM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1DM_MSG_SB(unsigned char v1, short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1DM_MSG_FB(unsigned char v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_L1DM_MSG_IRATSYNC(unsigned char v1, unsigned long v2, short v3, long v4);
void L1TRC_Send_L1DM_MSG_PMCell(unsigned char v1, short v2);
void L1TRC_Send_L1DM_MSG_3GGap(unsigned char v1, unsigned long v2, short v3, long v4, short v5, unsigned char v6);
void L1TRC_Send_L1DM_MSG_AbortBSIC(unsigned char v1);
void L1TRC_Send_L1DM_MSG_2GGap(unsigned char v1, unsigned long v2, short v3, long v4, short v5);
void L1TRC_Send_L1DM_MSG_2GGapStop(unsigned char v1);
void L1TRC_Send_L1DM_MSG_StartGapSchedule(unsigned char v1);
void L1TRC_Send_L1DM_MSG_StopGapSchedule(unsigned char v1, short v2);
void L1TRC_Send_L1DM_MSG_FMOLock(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1DM_MSG_CancelGap(unsigned char v1);
void L1TRC_Send_L1DM_MSG_Lock2G(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1DM_MSG_DMState(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1DM_MSG_PMTick(unsigned char v1, short v2);
void L1TRC_Send_L1DM_MSG_PMTick_HPSearch(unsigned char v1, short v2);
void L1TRC_Send_L1DM_MSG_PMDone(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_L1DM_MSG_DeleteGap(unsigned char v1);
void L1TRC_Send_L1DM_MSG_GAP_STANDBY(unsigned char v1, short v2, short v3, unsigned char v4, unsigned long v5, short v6, short v7, long v8, short v9, long v10, short v11, long v12);
void L1TRC_Send_L1DM_MSG_GapType_TD(unsigned char v1, unsigned char v2, short v3, short v4, unsigned char v5);
void L1TRC_Send_L1DM_MSG_SetGap_TD(unsigned char v1, short v2, long v3, unsigned char v4, short v5, long v6, unsigned char v7, short v8, long v9, unsigned char v10);
void L1TRC_Send_L1DM_MSG_Ignore_gaps(unsigned char v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_L1DM_MSG_BSICSchedule_TD(unsigned char v1, short v2, unsigned char v3, unsigned char v4, short v5, long v6);
void L1TRC_Send_L1DM_MSG_PMLock_TD(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1DM_MSG_PMPeriod(unsigned char v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_L1DM_MSG_ReselMode_Standby(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1DM_MSG_2GAutoGapStart(unsigned char v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_L1DM_MSG_2GAutoGapEnd(unsigned char v1);
void L1TRC_Send_L1DM_MSG_2GAutoGAPTimer(unsigned char v1, long v2);
void L1TRC_Send_L1DM_MSG_GSMAutoGAPGet(unsigned char v1, unsigned long v2, short v3);
void L1TRC_Send_L1DM_MSG_GSMAutoGAPPut(unsigned char v1);
void L1TRC_Send_L1DM_MSG_GSMAutoGAPConfirm(unsigned char v1, unsigned char v2, long v3);
void L1TRC_Send_L1DM_MSG_GSMAutoGAPStop(unsigned char v1, unsigned long v2);
void L1TRC_Send_L1DM_MSG_GetGSMAutoGAPLength(unsigned char v1, long v2);
void L1TRC_Send_L1DM_MSG_LTE_Connecedt_GAP(unsigned char v1, short v2, short v3, short v4, unsigned short v5);

void Set_L1DM_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1DM()	(L1DM_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1DM_DMBSIC_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1DM_DMSYNC_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1DM_DMPM_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1DM_DMGAP_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1DM_DMTick_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x10)!=0))
#define ChkL1MsgFltr_L1DM_MSG_SB()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_FB()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_IRATSYNC()	ChkL1ClsFltr_L1DM_DMSYNC_M()
#define ChkL1MsgFltr_L1DM_MSG_PMCell()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_3GGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_AbortBSIC()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_2GGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_2GGapStop()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_StartGapSchedule()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_StopGapSchedule()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_FMOLock()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_CancelGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_Lock2G()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_DMState()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_PMTick()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_PMTick_HPSearch()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_PMDone()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_DeleteGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GAP_STANDBY()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GapType_TD()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_SetGap_TD()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_Ignore_gaps()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_BSICSchedule_TD()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_PMLock_TD()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_PMPeriod()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_ReselMode_Standby()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_2GAutoGapStart()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_2GAutoGapEnd()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_2GAutoGAPTimer()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GSMAutoGAPGet()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GSMAutoGAPPut()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GSMAutoGAPConfirm()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GSMAutoGAPStop()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GetGSMAutoGAPLength()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_LTE_Connecedt_GAP()	ChkL1ClsFltr_L1DM_DMGAP_M()


#endif
