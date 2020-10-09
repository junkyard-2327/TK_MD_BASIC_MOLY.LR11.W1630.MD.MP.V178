#ifndef L1TRC_AST_L1_Trace_ISR_Context_Group1_DEF_H
#define L1TRC_AST_L1_Trace_ISR_Context_Group1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Str_Bool(v1)  (unsigned char)(v1+0)
#define Str_L1c_Fscs_State(v1)  (unsigned char)(v1+2)
#define Str_L1c_Scs_State(v1)  (unsigned char)(v1+7)
#define Str_TL1_Task_Name(v1)  (unsigned char)(v1+10)
#define Str_TL1_Duration_Name(v1)  (unsigned char)(v1+115)
#define Str_TL1_Conflict_Type(v1)  (unsigned char)(v1+125)
#define Str_TL1_Meas_Drx_State(v1)  (unsigned char)(v1+130)
#define Str_TL1_Meas_Drx_Event(v1)  (unsigned char)(v1+138)
#define Str_TL1_Meas_Connect_State(v1)  (unsigned char)(v1+145)
#define Str_TL1_Meas_Connect_Event(v1)  (unsigned char)(v1+155)
#define Str_TL1_Meas_Iscp_State(v1)  (unsigned char)(v1+162)
#define Str_TL1_Meas_Iscp_Event(v1)  (unsigned char)(v1+167)
#define Str_TL1_Powersaving_State(v1)  (unsigned char)(v1+170)
#define Str_TL1_Powersaving_Event(v1)  (unsigned char)(v1+182)
#define Str_TL1_Sleep_State(v1)  (unsigned char)(v1+193)
#define Str_TL1_Gap_State(v1)  (unsigned char)(v1+196)
#define Str_TL1_Suspend_State(v1)  (unsigned char)(v1+199)
#define Str_TL1_Peer2G_State(v1)  (unsigned char)(v1+202)
#define Str_TL1_Peer2G_Event(v1)  (unsigned char)(v1+205)
#define Str_TL1_DRXCTRL_State(v1)  (unsigned char)(v1+209)
#define Str_TL1_DRXCTRL_Event(v1)  (unsigned char)(v1+212)
#define Str_TL1_RxTx_State(v1)  (unsigned char)(v1+215)
#define Str_TL1_Rule5_Gap_State(v1)  (unsigned char)(v1+221)
#define Str_L1c_Ue_State(v1)  (unsigned char)(v1+227)
#define Str_L1c_Afc_Mode(v1)  (unsigned char)(v1+235)
#define Str_L1c_Rat_Mode(v1)  (unsigned char)(v1+239)
#define Str_L1c_3GTD_State(v1)  (unsigned char)(v1+243)
#define Str_Tl1c_EMI_Trans_State(v1)  (unsigned char)(v1+246)
#define Str_Tl1c_EMI_PROFILE_Context(v1)  (unsigned char)(v1+248)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_SYSTEM_EXECUTION_TICK(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x005A, (short)(v6)), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v7), (long)(v8), (long)(v9));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_SYSTEM_EXECUTION_TICK(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define AST_L1_Trace_ISR_Context_Group1_SYSTEM_EXECUTION_TICK_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_2S(0x005A, (short)(v6)), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v7), (long)(v8), (long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_DCH_Time(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x015A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_DCH_Time(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group1_DCH_Time_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x015A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_EXECUTION_TICK(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x025A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_EXECUTION_TICK(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_EXECUTION_TICK_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x025A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_TIME_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x035A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_TIME_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group1_HSUPA_TIME_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x035A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_FSCS_STATE(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x045A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_FSCS_STATE(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_FSCS_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x045A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_SCS_STATE(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x055A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_SCS_STATE(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_SCS_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x055A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TD_AFC_RELIABLE(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x065A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TD_AFC_RELIABLE(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TD_AFC_RELIABLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x065A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Prepare_Data(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x075A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Prepare_Data(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Prepare_Data_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x075A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Get_Data(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x085A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Get_Data(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Get_Data_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x085A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Tx_Data_Param(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x095A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Tx_Data_Param(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Tx_Data_Param_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x095A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK1(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0A5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK1(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0A5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_NEW(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0B5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_NEW(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_NEW_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0B5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_RETX(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0C5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_RETX(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_RETX_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0C5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_SI(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_SI(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_SI_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_BAD_TRRI(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E5A, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_HSUPA_BAD_TRRI(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_HSUPA_BAD_TRRI_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E5A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Smart_Paging(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Smart_Paging(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Smart_Paging_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Bad_Fach(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x105A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Bad_Fach(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Bad_Fach_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x105A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_BCH_DATA(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x115A, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_BCH_DATA(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define AST_L1_Trace_ISR_Context_Group1_BCH_DATA_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x115A, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE0(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x125A, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE0(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE0_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x125A, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE1(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x135A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE1(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x135A, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE2(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x145A, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE2(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x145A, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE3(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x155A, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE3(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x155A, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE4(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x165A, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE4(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TEST_TRACE4_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x165A, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Update_Task(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x175A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Update_Task(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Update_Task_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x175A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Activate(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x185A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Activate(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Activate_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x185A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Task(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x195A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Task(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Task_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x195A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Duration(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A5A, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Duration(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Duration_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A5A, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Conflict(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Conflict(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Conflict_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Pch(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Pch(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Gap_Pch_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Pch_Bch(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Pch_Bch(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Gap_Pch_Bch_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Fach(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E5A, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Fach(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Gap_Fach_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E5A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Fach_All(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1F5A, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Fach_All(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Gap_Fach_All_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1F5A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Dch(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x205A, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Dch(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Gap_Dch_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x205A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Dch_All(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x215A, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Dch_All(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Gap_Dch_All_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x215A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Hsdpa(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x225A, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Hsdpa(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Gap_Hsdpa_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x225A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Hsdpa_All(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x235A, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Hsdpa_All(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Gap_Hsdpa_All_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x235A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Suspend(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x245A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Gap_Suspend(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Gap_Suspend_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x245A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_RXTX_STATE(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x255A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_RXTX_STATE(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_RXTX_STATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x255A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_MEAS_DRX_STATE(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x265A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_MEAS_DRX_STATE(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_MEAS_DRX_STATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x265A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_MEAS_CONNECT_STATE(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x275A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_MEAS_CONNECT_STATE(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_MEAS_CONNECT_STATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x275A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_MEAS_ISCP_STATE(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x285A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_MEAS_ISCP_STATE(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_MEAS_ISCP_STATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x285A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_POWERSAVING_STATE(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x295A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_POWERSAVING_STATE(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_POWERSAVING_STATE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x295A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_SLEEP_STATE(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_SLEEP_STATE(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_SLEEP_STATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_GAP_STATE(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_GAP_STATE(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_GAP_STATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_SUSPEND_STATE(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_SUSPEND_STATE(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_SUSPEND_STATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_PEER_2G_STATE(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_PEER_2G_STATE(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_PEER_2G_STATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_DRX_CTRL_STATE(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_DRX_CTRL_STATE(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_DRX_CTRL_STATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E5A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_CHANNEL_STATUS(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2F5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_CHANNEL_STATUS(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group1_CHANNEL_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2F5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_MULTIAFC_UPDATE_MODE(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x305A, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_MULTIAFC_UPDATE_MODE(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_MULTIAFC_UPDATE_MODE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x305A, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_QUERY_3G_TD_AFC_DAC(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x315A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_QUERY_3G_TD_AFC_DAC(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_QUERY_3G_TD_AFC_DAC_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x315A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_AFC_DAC_UPDATE_CMD(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x325A, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_AFC_DAC_UPDATE_CMD(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group1_AFC_DAC_UPDATE_CMD_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x325A, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_AFC_DAC_UPDATE_RSEP(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x335A, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_AFC_DAC_UPDATE_RSEP(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_AFC_DAC_UPDATE_RSEP_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x335A, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Active3G(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x345A, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Active3G(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_Active3G_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x345A, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_SyncTime_3G(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x355A, (short)(v1)), (long)(v2));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_SyncTime_3G(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_SyncTime_3G_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x355A, (short)(v1)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_AdjustTime_3G(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x365A, (short)(v1)), (long)(v2));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_AdjustTime_3G(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_AdjustTime_3G_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x365A, (short)(v1)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_3GStartVirtualMeas(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x375A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_3GStartVirtualMeas(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_3GStartVirtualMeas_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x375A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TL1C_SW_PROFILE_ELM_MAX(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x385A, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TL1C_SW_PROFILE_ELM_MAX(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TL1C_SW_PROFILE_ELM_MAX_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x385A, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TL1C_SW_PROFILE_ELM_MIN(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x395A, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TL1C_SW_PROFILE_ELM_MIN(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TL1C_SW_PROFILE_ELM_MIN_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x395A, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_FixAFC_32KLESS_STATE(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A5A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_FixAFC_32KLESS_STATE(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_FixAFC_32KLESS_STATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A5A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TL1_SW_INFO(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3B5A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TL1_SW_INFO(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TL1_SW_INFO_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3B5A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_Channel_Protect_Activate(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3C5A, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_Channel_Protect_Activate(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_Channel_Protect_Activate_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3C5A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_List_Mode_Info(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x3D5A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_List_Mode_Info(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group1_List_Mode_Info_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x3D5A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3E5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3E5A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_FixAFC_TFC_SCURVE(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3F5A, (short)(v5)), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_FixAFC_TFC_SCURVE(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group1_FixAFC_TFC_SCURVE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3F5A, (short)(v5)), (long)(v1), (long)(v2), (long)(v3), (long)(v4))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char AST_L1_Trace_ISR_Context_Group1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_SYSTEM_EXECUTION_TICK(long v1, long v2, long v3, long v4, long v5, short v6, long v7, long v8, long v9);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_DCH_Time(long v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_EXECUTION_TICK(long v1, long v2, long v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_HSUPA_TIME_INFO(long v1, long v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_FSCS_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_SCS_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TD_AFC_RELIABLE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Prepare_Data(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Get_Data(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Tx_Data_Param(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK1(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_NEW(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_RETX(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_SI(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_HSUPA_BAD_TRRI(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Smart_Paging(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Bad_Fach(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_BCH_DATA(short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16, unsigned short v17);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TEST_TRACE0(unsigned char v1, unsigned short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TEST_TRACE1(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TEST_TRACE2(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TEST_TRACE3(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TEST_TRACE4(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Update_Task(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Activate(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Task(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Duration(short v1, unsigned char v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Conflict(short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Gap_Pch(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Gap_Pch_Bch(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Gap_Fach(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Gap_Fach_All(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Gap_Dch(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Gap_Dch_All(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Gap_Hsdpa(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Gap_Hsdpa_All(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Gap_Suspend(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_RXTX_STATE(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_MEAS_DRX_STATE(short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_MEAS_CONNECT_STATE(short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_MEAS_ISCP_STATE(short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_POWERSAVING_STATE(short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_SLEEP_STATE(short v1, unsigned char v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_GAP_STATE(short v1, unsigned char v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_SUSPEND_STATE(short v1, unsigned char v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_PEER_2G_STATE(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_DRX_CTRL_STATE(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_CHANNEL_STATUS(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_MULTIAFC_UPDATE_MODE(unsigned char v1, unsigned char v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_QUERY_3G_TD_AFC_DAC(unsigned char v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_AFC_DAC_UPDATE_CMD(unsigned char v1, unsigned char v2, unsigned char v3, short v4, short v5, unsigned char v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_AFC_DAC_UPDATE_RSEP(unsigned char v1, short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_Active3G(unsigned char v1, unsigned char v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_SyncTime_3G(short v1, long v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_AdjustTime_3G(short v1, long v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_3GStartVirtualMeas(short v1, short v2, long v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TL1C_SW_PROFILE_ELM_MAX(unsigned char v1, unsigned char v2, long v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TL1C_SW_PROFILE_ELM_MIN(unsigned char v1, unsigned char v2, long v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_FixAFC_32KLESS_STATE(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TL1_SW_INFO(long v1, long v2, long v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_Channel_Protect_Activate(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_List_Mode_Info(long v1, long v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_FixAFC_TFC_SCURVE(long v1, long v2, long v3, long v4, short v5);

void Set_AST_L1_Trace_ISR_Context_Group1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group1()	(AST_L1_Trace_ISR_Context_Group1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group1()&&((AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group1()&&((AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_3()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group1()&&((AST_L1_Trace_ISR_Context_Group1_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_SYSTEM_EXECUTION_TICK()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_DCH_Time()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_EXECUTION_TICK()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_HSUPA_TIME_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_FSCS_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_SCS_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TD_AFC_RELIABLE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Prepare_Data()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Get_Data()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Tx_Data_Param()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_NEW()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_RETX()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_HSUPA_UPLINK_TICK2_SI()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_HSUPA_BAD_TRRI()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Smart_Paging()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Bad_Fach()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_BCH_DATA()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_3()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TEST_TRACE0()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TEST_TRACE1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TEST_TRACE2()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TEST_TRACE3()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TEST_TRACE4()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Update_Task()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Activate()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Task()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Duration()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Conflict()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Gap_Pch()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Gap_Pch_Bch()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Gap_Fach()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Gap_Fach_All()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Gap_Dch()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Gap_Dch_All()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Gap_Hsdpa()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Gap_Hsdpa_All()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Gap_Suspend()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_RXTX_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_MEAS_DRX_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_MEAS_CONNECT_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_MEAS_ISCP_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_POWERSAVING_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_SLEEP_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_GAP_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_SUSPEND_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_PEER_2G_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_DRX_CTRL_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_CHANNEL_STATUS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_MULTIAFC_UPDATE_MODE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_QUERY_3G_TD_AFC_DAC()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_AFC_DAC_UPDATE_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_AFC_DAC_UPDATE_RSEP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_Active3G()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_SyncTime_3G()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_AdjustTime_3G()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_3GStartVirtualMeas()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TL1C_SW_PROFILE_ELM_MAX()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TL1C_SW_PROFILE_ELM_MIN()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_FixAFC_32KLESS_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TL1_SW_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_Channel_Protect_Activate()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_List_Mode_Info()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_FixAFC_TFC_SCURVE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group1_TEST_CLASS_1()


#endif
