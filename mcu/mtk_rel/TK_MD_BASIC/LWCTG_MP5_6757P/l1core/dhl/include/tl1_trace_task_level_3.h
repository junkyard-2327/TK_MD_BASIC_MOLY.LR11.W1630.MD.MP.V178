#ifndef L1TRC_AST_L1_Trace_Task_Context_Group3_DEF_H
#define L1TRC_AST_L1_Trace_Task_Context_Group3_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Str_Bool(v1)  (unsigned char)(v1+0)
#define Str_Gap_Control_State(v1)  (unsigned char)(v1+2)
#define Str_Gap_Suspend_State(v1)  (unsigned char)(v1+6)
#define Str_Auto_Suspend_Normal_State(v1)  (unsigned char)(v1+9)
#define Str_Tl1a_Gap_Internal(v1)  (unsigned char)(v1+12)
#define Str_Auto_Gap_Control_State(v1)  (unsigned char)(v1+14)
#define Str_Auto_Gap_Available_State(v1)  (unsigned char)(v1+17)
#define Str_Auto_Gap_Start_State(v1)  (unsigned char)(v1+19)
#define Str_TL1TCM_State(v1)  (unsigned char)(v1+21)
#define Str_TL1RXBRP_RST_State(v1)  (unsigned char)(v1+23)
#define Str_TL1RXBRP_DL_BOOT_State(v1)  (unsigned char)(v1+25)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_TEST_MSG_1(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0062, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_TEST_MSG_1(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_TEST_MSG_1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0062, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_TEST_MSG_2(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0162, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_TEST_MSG_2(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_TEST_MSG_2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0162, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_TEST_MSG_3(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0262, (unsigned short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_TEST_MSG_3(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_TEST_MSG_3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0262, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_GAP_CONTROL_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0362, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_GAP_CONTROL_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_GAP_CONTROL_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0362, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_AUTO_GAP_CONTROL_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0462, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_AUTO_GAP_CONTROL_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_AUTO_GAP_CONTROL_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0462, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_AUTO_GAP_AVAILABLE_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0562, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_AUTO_GAP_AVAILABLE_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_AUTO_GAP_AVAILABLE_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0562, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_AUTO_GAP_START_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0662, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_AUTO_GAP_START_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_AUTO_GAP_START_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0662, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_CURRENT_GAP_INFO(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0762, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_CURRENT_GAP_INFO(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_Task_Context_Group3_CURRENT_GAP_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0762, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_CURRENT_AUTO_GAP_INFO(v1, v2, v3) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0862, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_CURRENT_AUTO_GAP_INFO(v1, v2, v3)
#endif
#define AST_L1_Trace_Task_Context_Group3_CURRENT_AUTO_GAP_INFO_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0862, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_CURRENT_GAP_INFO_1(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0962, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_CURRENT_GAP_INFO_1(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_Task_Context_Group3_CURRENT_GAP_INFO_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0962, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_GAP_STOP_POINT(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A62, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_GAP_STOP_POINT(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_GAP_STOP_POINT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A62, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_TD_SYNC_CLEAR(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B62, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_TD_SYNC_CLEAR(v1, v2)
#endif
#define AST_L1_Trace_Task_Context_Group3_TD_SYNC_CLEAR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B62, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_TD_AUTO_SYNC_CLEAR(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C62, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_TD_AUTO_SYNC_CLEAR(v1, v2)
#endif
#define AST_L1_Trace_Task_Context_Group3_TD_AUTO_SYNC_CLEAR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C62, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_GAP_ADDI_INFO(v1, v2, v3) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D62, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_GAP_ADDI_INFO(v1, v2, v3)
#endif
#define AST_L1_Trace_Task_context_Group3_GAP_ADDI_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D62, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_2G_STOP_GAP_REQ(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E62, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_2G_STOP_GAP_REQ(v1)
#endif
#define AST_L1_Trace_Task_context_Group3_2G_STOP_GAP_REQ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E62, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_CURRENT_GAP_INDEX(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F62, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_CURRENT_GAP_INDEX(v1, v2)
#endif
#define AST_L1_Trace_Task_context_Group3_CURRENT_GAP_INDEX_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F62, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_L1A_GAP_STORE(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1062, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_L1A_GAP_STORE(v1, v2)
#endif
#define AST_L1_Trace_Task_context_Group3_L1A_GAP_STORE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1062, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_CLEAR_TL1C_GAP() do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1162, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_CLEAR_TL1C_GAP()
#endif
#define AST_L1_Trace_Task_context_Group3_CLEAR_TL1C_GAP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1162, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_DMS_TASK_ACT_BMP(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1262, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_DMS_TASK_ACT_BMP(v1, v2)
#endif
#define AST_L1_Trace_Task_context_Group3_DMS_TASK_ACT_BMP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1262, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_SYNC_PERIOD_LENGTH_2G(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1362, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_SYNC_PERIOD_LENGTH_2G(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_SYNC_PERIOD_LENGTH_2G_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1362, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_SYNC_PERIOD_LENGTH_3G(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1462, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_SYNC_PERIOD_LENGTH_3G(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_SYNC_PERIOD_LENGTH_3G_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1462, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_WAKEUP_DSP(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1562, (unsigned short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_WAKEUP_DSP(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_WAKEUP_DSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1562, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_POWERDOWN_TL1D(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1662, (unsigned short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_POWERDOWN_TL1D(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_POWERDOWN_TL1D_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1662, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_TL1A_BOOT_RXBRP_FW(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1762, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_TL1A_BOOT_RXBRP_FW(v1, v2)
#endif
#define AST_L1_Trace_Task_Context_Group3_TL1A_BOOT_RXBRP_FW_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1762, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_DYNAMIC_TCM_UBIN_T_STATUS(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1862, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_DYNAMIC_TCM_UBIN_T_STATUS(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_DYNAMIC_TCM_UBIN_T_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1862, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_TL1A_RXBRP_PWR_CTRL(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1962, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_TL1A_RXBRP_PWR_CTRL(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_TL1A_RXBRP_PWR_CTRL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1962, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_TL1A_RXBRP_RESET_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A62, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_TL1A_RXBRP_RESET_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_TL1A_RXBRP_RESET_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A62, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_GAP_ADDI_INFO_1(v1, v2, v3) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B62, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_GAP_ADDI_INFO_1(v1, v2, v3)
#endif
#define AST_L1_Trace_Task_context_Group3_GAP_ADDI_INFO_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B62, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_ACTIVE_RAT_REQ_GAP_STOP(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C62, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_ACTIVE_RAT_REQ_GAP_STOP(v1)
#endif
#define AST_L1_Trace_Task_context_Group3_ACTIVE_RAT_REQ_GAP_STOP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C62, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_MMS_TASK_ACT_BMP(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D62, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_MMS_TASK_ACT_BMP(v1, v2)
#endif
#define AST_L1_Trace_Task_context_Group3_MMS_TASK_ACT_BMP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D62, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_MMS_MSG_INFO(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E62, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_MMS_MSG_INFO(v1, v2)
#endif
#define AST_L1_Trace_Task_context_Group3_MMS_MSG_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E62, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_TEST_SUSPEND_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F62, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_TEST_SUSPEND_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_TEST_SUSPEND_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F62, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group3_AUTO_SUSPEND_NORMAL_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2062, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group3_AUTO_SUSPEND_NORMAL_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group3_AUTO_SUSPEND_NORMAL_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2062, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_context_Group3_MMS_GAP_TID_INFO(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2162, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_context_Group3_MMS_GAP_TID_INFO(v1, v2)
#endif
#define AST_L1_Trace_Task_context_Group3_MMS_GAP_TID_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2162, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char AST_L1_Trace_Task_Context_Group3_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_TEST_MSG_1(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_TEST_MSG_2(char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_TEST_MSG_3(unsigned short v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_GAP_CONTROL_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_AUTO_GAP_CONTROL_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_AUTO_GAP_AVAILABLE_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_AUTO_GAP_START_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_CURRENT_GAP_INFO(short v1, short v2, unsigned short v3, long v4);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_CURRENT_AUTO_GAP_INFO(short v1, unsigned short v2, long v3);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_CURRENT_GAP_INFO_1(short v1, short v2, unsigned short v3, long v4);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_GAP_STOP_POINT(short v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_TD_SYNC_CLEAR(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_TD_AUTO_SYNC_CLEAR(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_GAP_ADDI_INFO(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_2G_STOP_GAP_REQ(short v1);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_CURRENT_GAP_INDEX(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_L1A_GAP_STORE(unsigned char v1, short v2);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_CLEAR_TL1C_GAP(void);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_DMS_TASK_ACT_BMP(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_SYNC_PERIOD_LENGTH_2G(long v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_SYNC_PERIOD_LENGTH_3G(long v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_WAKEUP_DSP(unsigned short v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_POWERDOWN_TL1D(unsigned short v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_TL1A_BOOT_RXBRP_FW(unsigned char v1, unsigned short v2);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_DYNAMIC_TCM_UBIN_T_STATUS(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_TL1A_RXBRP_PWR_CTRL(short v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_TL1A_RXBRP_RESET_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_GAP_ADDI_INFO_1(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_ACTIVE_RAT_REQ_GAP_STOP(short v1);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_MMS_TASK_ACT_BMP(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_MMS_MSG_INFO(unsigned char v1, short v2);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_TEST_SUSPEND_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group3_AUTO_SUSPEND_NORMAL_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_context_Group3_MMS_GAP_TID_INFO(short v1, short v2);

void Set_AST_L1_Trace_Task_Context_Group3_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_AST_L1_Trace_Task_Context_Group3()	(AST_L1_Trace_Task_Context_Group3_Trace_Filter[0]==1)
#define ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()	(ChkL1ModFltr_AST_L1_Trace_Task_Context_Group3()&&((AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_2()	(ChkL1ModFltr_AST_L1_Trace_Task_Context_Group3()&&((AST_L1_Trace_Task_Context_Group3_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_TEST_MSG_1()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_TEST_MSG_2()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_TEST_MSG_3()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_GAP_CONTROL_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_AUTO_GAP_CONTROL_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_AUTO_GAP_AVAILABLE_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_AUTO_GAP_START_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_CURRENT_GAP_INFO()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_CURRENT_AUTO_GAP_INFO()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_CURRENT_GAP_INFO_1()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_GAP_STOP_POINT()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_TD_SYNC_CLEAR()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_TD_AUTO_SYNC_CLEAR()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_GAP_ADDI_INFO()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_2G_STOP_GAP_REQ()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_CURRENT_GAP_INDEX()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_L1A_GAP_STORE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_CLEAR_TL1C_GAP()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_DMS_TASK_ACT_BMP()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_SYNC_PERIOD_LENGTH_2G()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_SYNC_PERIOD_LENGTH_3G()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_WAKEUP_DSP()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_POWERDOWN_TL1D()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_TL1A_BOOT_RXBRP_FW()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_DYNAMIC_TCM_UBIN_T_STATUS()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_TL1A_RXBRP_PWR_CTRL()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_TL1A_RXBRP_RESET_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_GAP_ADDI_INFO_1()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_ACTIVE_RAT_REQ_GAP_STOP()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_MMS_TASK_ACT_BMP()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_MMS_MSG_INFO()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_TEST_SUSPEND_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group3_AUTO_SUSPEND_NORMAL_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_context_Group3_MMS_GAP_TID_INFO()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group3_TEST_CLASS_1()


#endif
