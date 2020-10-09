#ifndef L1TRC_L1SM_1_DEF_H
#define L1TRC_L1SM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1D_Trace_Str_TM_Sync_State(v1)  (unsigned char)(v1+0)
#define L1SM_Str_Wakeup(v1)  (unsigned char)(v1+2)
#define L1SM_Str_Bool(v1)  (unsigned char)(v1+13)
#define L1SM_Disable_Bool(v1)  (unsigned char)(v1+15)
#define L1SM_Str_Sleep_FRC(v1)  (unsigned char)(v1+17)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define L1SM_DBG_CALI_START() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0056, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_CALI_START()
#endif
#define L1SM_DBG_CALI_START_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0056, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_DBG_TOPSM_PASS_2G(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0156, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define L1SM_DBG_TOPSM_PASS_2G(v1, v2)
#endif
#define L1SM_DBG_TOPSM_PASS_2G_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0156, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define L1SM_DBG_SW_WAKEUP(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0256, (unsigned char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L1SM_DBG_SW_WAKEUP(v1, v2, v3, v4)
#endif
#define L1SM_DBG_SW_WAKEUP_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0256, (unsigned char)(v4), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_DBG_SW_WAKEUP_DONE(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0356, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L1SM_DBG_SW_WAKEUP_DONE(v1, v2, v3)
#endif
#define L1SM_DBG_SW_WAKEUP_DONE_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0356, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_DBG_CAL_SLEEP(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0456, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define L1SM_DBG_CAL_SLEEP(v1, v2, v3, v4)
#endif
#define L1SM_DBG_CAL_SLEEP_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0456, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define L1SM_DBG_WAKEUP_INFO_1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x0556, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define L1SM_DBG_WAKEUP_INFO_1(v1, v2, v3, v4, v5, v6, v7)
#endif
#define L1SM_DBG_WAKEUP_INFO_1_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x0556, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define L1SM_DBG_WAKEUP_INFO_2(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0656, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define L1SM_DBG_WAKEUP_INFO_2(v1, v2, v3, v4, v5)
#endif
#define L1SM_DBG_WAKEUP_INFO_2_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0656, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define L1SM_DBG_SET_DURATION(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0756, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define L1SM_DBG_SET_DURATION(v1, v2, v3, v4, v5, v6)
#endif
#define L1SM_DBG_SET_DURATION_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0756, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define L1SM_DBG_SLEEP_CONDITION(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0856, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_SLEEP_CONDITION(v1, v2, v3, v4, v5, v6, v7)
#endif
#define L1SM_DBG_SLEEP_CONDITION_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0856, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_DBG_L1SM_FRAME_TICK(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0956, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L1SM_DBG_L1SM_FRAME_TICK(v1, v2, v3)
#endif
#define L1SM_DBG_L1SM_FRAME_TICK_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0956, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_DBG_ENTER_SLEEP(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x0A56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define L1SM_DBG_ENTER_SLEEP(v1, v2, v3, v4, v5, v6)
#endif
#define L1SM_DBG_ENTER_SLEEP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x0A56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define L1SM_DBG_WAKEUP_INT(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0B56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define L1SM_DBG_WAKEUP_INT(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define L1SM_DBG_WAKEUP_INT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0B56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define L1SM_DBG_WAKEUP_Done(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define L1SM_DBG_WAKEUP_Done(v1, v2, v3, v4)
#endif
#define L1SM_DBG_WAKEUP_Done_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define L1SM_DBG_Execute_L1(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D56, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define L1SM_DBG_Execute_L1(v1, v2)
#endif
#define L1SM_DBG_Execute_L1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D56, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define L1SM_TRC_WakeUp_Handler_1(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E56, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define L1SM_TRC_WakeUp_Handler_1(v1, v2, v3)
#endif
#define L1SM_TRC_WakeUp_Handler_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E56, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define L1SM_TRC_WakeUp_Handler_2(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F56, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_TRC_WakeUp_Handler_2(v1, v2)
#endif
#define L1SM_TRC_WakeUp_Handler_2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F56, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_TRC_TWO_STAGE_RF(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1056, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_TRC_TWO_STAGE_RF(v1, v2, v3)
#endif
#define L1SM_TRC_TWO_STAGE_RF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1056, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_Meta() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1156, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_Meta()
#endif
#define L1SM_TRC_Sleep_Return_Meta_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1156, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_L1D(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1256, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_L1D(v1, v2, v3)
#endif
#define L1SM_TRC_Sleep_Return_L1D_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1256, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_L1C(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1356, (unsigned short)(v1)));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_L1C(v1)
#endif
#define L1SM_TRC_Sleep_Return_L1C_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1356, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_Trace32(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1456, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_Trace32(v1)
#endif
#define L1SM_TRC_Sleep_Return_Trace32_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1456, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_SMDis(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1556, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_SMDis(v1)
#endif
#define L1SM_TRC_Sleep_Return_SMDis_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1556, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_OS(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1656, (unsigned short)(v1)));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_OS(v1)
#endif
#define L1SM_TRC_Sleep_Return_OS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1656, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_ASSERT() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1756, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_ASSERT()
#endif
#define L1SM_TRC_Sleep_Return_ASSERT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1756, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_SMLock() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1856, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_SMLock()
#endif
#define L1SM_TRC_Sleep_Return_SMLock_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1856, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_DCXO() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1956, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_DCXO()
#endif
#define L1SM_TRC_Sleep_Return_DCXO_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1956, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_Cali() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_Cali()
#endif
#define L1SM_TRC_Sleep_Return_Cali_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Return_THRD(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B56, (unsigned short)(v1)));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Return_THRD(v1)
#endif
#define L1SM_TRC_Sleep_Return_THRD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B56, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Sleep_Large_Offset(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define L1SM_TRC_Sleep_Large_Offset(v1)
#endif
#define L1SM_TRC_Sleep_Large_Offset_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Disable_Turbo_Sleep(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D56, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_TRC_Disable_Turbo_Sleep(v1, v2, v3)
#endif
#define L1SM_TRC_Disable_Turbo_Sleep_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D56, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_TRC_Over_Sleep(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define L1SM_TRC_Over_Sleep(v1, v2)
#endif
#define L1SM_TRC_Over_Sleep_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define L1SM_TRC_DEBUG(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F56, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define L1SM_TRC_DEBUG(v1, v2, v3)
#endif
#define L1SM_TRC_DEBUG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F56, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_TRC_DEBUG_HEX(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2056, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L1SM_TRC_DEBUG_HEX(v1, v2, v3)
#endif
#define L1SM_TRC_DEBUG_HEX_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2056, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_2G_COMMON(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2156, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define DUAL_OS_TICK_2G_COMMON(v1, v2)
#endif
#define DUAL_OS_TICK_2G_COMMON_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2156, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_2G_RECOVER(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2256, (unsigned short)(v1)));\
	} while(0)
#else
	#define DUAL_OS_TICK_2G_RECOVER(v1)
#endif
#define DUAL_OS_TICK_2G_RECOVER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2256, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_INITIAL(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2356, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DUAL_OS_TICK_INITIAL(v1, v2, v3)
#endif
#define DUAL_OS_TICK_INITIAL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2356, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_3G_COMMON(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2456, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define DUAL_OS_TICK_3G_COMMON(v1, v2)
#endif
#define DUAL_OS_TICK_3G_COMMON_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2456, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_3G_RECOVER(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2556, (unsigned short)(v1)));\
	} while(0)
#else
	#define DUAL_OS_TICK_3G_RECOVER(v1)
#endif
#define DUAL_OS_TICK_3G_RECOVER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2556, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_3G_DBG(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2656, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define DUAL_OS_TICK_3G_DBG(v1, v2)
#endif
#define DUAL_OS_TICK_3G_DBG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2656, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define DUAL_OS_TICK_ReSync() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2756, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DUAL_OS_TICK_ReSync()
#endif
#define DUAL_OS_TICK_ReSync_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2756, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_RTC(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x2856, (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v11), (unsigned char)(v1), (unsigned char)(v9)), TRC_MERGE_4C((unsigned char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v12));\
	} while(0)
#else
	#define DUAL_OS_RTC(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define DUAL_OS_RTC_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_10_DATA(TRC_MERGE_2S(0x2856, (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v11), (unsigned char)(v1), (unsigned char)(v9)), TRC_MERGE_4C((unsigned char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v12))

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW1(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2956, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L1SM_Trace_SW1(v1, v2, v3)
#endif
#define L1SM_Trace_SW1_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2956, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW2(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2A56, (short)(v1)));\
	} while(0)
#else
	#define L1SM_Trace_SW2(v1)
#endif
#define L1SM_Trace_SW2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2A56, (short)(v1)))

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW3(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define L1SM_Trace_SW3(v1)
#endif
#define L1SM_Trace_SW3_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW4(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2C56, (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define L1SM_Trace_SW4(v1, v2, v3, v4, v5, v6)
#endif
#define L1SM_Trace_SW4_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2C56, (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW5(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2D56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define L1SM_Trace_SW5(v1, v2, v3, v4)
#endif
#define L1SM_Trace_SW5_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2D56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define L1SM_DBG_R_32K_UPDATE(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2E56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define L1SM_DBG_R_32K_UPDATE(v1, v2)
#endif
#define L1SM_DBG_R_32K_UPDATE_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2E56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define L1I_Msg_AvgTAC(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F56, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_AvgTAC(v1, v2)
#endif
#define L1I_Msg_AvgTAC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F56, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_DBG_32KLESS_WAKEUP(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3056, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_32KLESS_WAKEUP(v1, v2)
#endif
#define L1SM_DBG_32KLESS_WAKEUP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3056, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SM_DBG_32KLESS_FORCE_REPORT() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3156, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_32KLESS_FORCE_REPORT()
#endif
#define L1SM_DBG_32KLESS_FORCE_REPORT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3156, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SM_DBG_STABLE_PARAM(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3256, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_STABLE_PARAM(v1, v2, v3, v4)
#endif
#define L1SM_DBG_STABLE_PARAM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3256, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3356, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define L1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5, v6)
#endif
#define L1SM_DBG_32KLESS_UPDATE_LPM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3356, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define L1SM_DBG_Timing_Profile(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x3456, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define L1SM_DBG_Timing_Profile(v1, v2, v3, v4, v5, v6)
#endif
#define L1SM_DBG_Timing_Profile_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x3456, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define L1SM_DBG_TP_A(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3556, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define L1SM_DBG_TP_A(v1, v2, v3, v4)
#endif
#define L1SM_DBG_TP_A_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3556, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER)
	#define L1SM_DBG_TP_B(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3656, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define L1SM_DBG_TP_B(v1, v2, v3, v4, v5)
#endif
#define L1SM_DBG_TP_B_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3656, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define L1SM_DBG_TP_C(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3756, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define L1SM_DBG_TP_C(v1, v2, v3, v4, v5)
#endif
#define L1SM_DBG_TP_C_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3756, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define L1SM_DBG_Timing_Profile_Best_Region(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3856, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define L1SM_DBG_Timing_Profile_Best_Region(v1, v2, v3)
#endif
#define L1SM_DBG_Timing_Profile_Best_Region_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3856, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_DBG_Timing_Profile_Worst_Region(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3956, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define L1SM_DBG_Timing_Profile_Worst_Region(v1, v2, v3)
#endif
#define L1SM_DBG_Timing_Profile_Worst_Region_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3956, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_DBG_COCLK_UPDATE_FreqOffset(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3A56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define L1SM_DBG_COCLK_UPDATE_FreqOffset(v1, v2)
#endif
#define L1SM_DBG_COCLK_UPDATE_FreqOffset_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3A56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define L1SM_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3B56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L1SM_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3)
#endif
#define L1SM_DBG_COCLK_UPDATE_FMRESULT_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3B56, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (unsigned long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1SM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1SM_DBG_CALI_START(void);
void L1TRC_Send_L1SM_DBG_TOPSM_PASS_2G(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1SM_DBG_SW_WAKEUP(unsigned long v1, unsigned long v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_L1SM_DBG_SW_WAKEUP_DONE(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L1SM_DBG_CAL_SLEEP(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_L1SM_DBG_WAKEUP_INFO_1(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_L1SM_DBG_WAKEUP_INFO_2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_L1SM_DBG_SET_DURATION(unsigned short v1, unsigned short v2, unsigned short v3, unsigned long v4, unsigned long v5, unsigned char v6);
void L1TRC_Send_L1SM_DBG_SLEEP_CONDITION(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_L1SM_DBG_L1SM_FRAME_TICK(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L1SM_DBG_ENTER_SLEEP(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, long v5, unsigned long v6);
void L1TRC_Send_L1SM_DBG_WAKEUP_INT(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, long v7, unsigned long v8);
void L1TRC_Send_L1SM_DBG_WAKEUP_Done(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1SM_DBG_Execute_L1(unsigned char v1, unsigned long v2);
void L1TRC_Send_L1SM_TRC_WakeUp_Handler_1(short v1, short v2, short v3);
void L1TRC_Send_L1SM_TRC_WakeUp_Handler_2(short v1, short v2);
void L1TRC_Send_L1SM_TRC_TWO_STAGE_RF(unsigned short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1SM_TRC_Sleep_Return_Meta(void);
void L1TRC_Send_L1SM_TRC_Sleep_Return_L1D(unsigned short v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_L1SM_TRC_Sleep_Return_L1C(unsigned short v1);
void L1TRC_Send_L1SM_TRC_Sleep_Return_Trace32(unsigned long v1);
void L1TRC_Send_L1SM_TRC_Sleep_Return_SMDis(unsigned long v1);
void L1TRC_Send_L1SM_TRC_Sleep_Return_OS(unsigned short v1);
void L1TRC_Send_L1SM_TRC_Sleep_Return_ASSERT(void);
void L1TRC_Send_L1SM_TRC_Sleep_Return_SMLock(void);
void L1TRC_Send_L1SM_TRC_Sleep_Return_DCXO(void);
void L1TRC_Send_L1SM_TRC_Sleep_Return_Cali(void);
void L1TRC_Send_L1SM_TRC_Sleep_Return_THRD(unsigned short v1);
void L1TRC_Send_L1SM_TRC_Sleep_Large_Offset(long v1);
void L1TRC_Send_L1SM_TRC_Disable_Turbo_Sleep(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1SM_TRC_Over_Sleep(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1SM_TRC_DEBUG(unsigned short v1, long v2, long v3);
void L1TRC_Send_L1SM_TRC_DEBUG_HEX(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_DUAL_OS_TICK_2G_COMMON(unsigned long v1, unsigned long v2);
void L1TRC_Send_DUAL_OS_TICK_2G_RECOVER(unsigned short v1);
void L1TRC_Send_DUAL_OS_TICK_INITIAL(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_DUAL_OS_TICK_3G_COMMON(unsigned long v1, unsigned long v2);
void L1TRC_Send_DUAL_OS_TICK_3G_RECOVER(unsigned short v1);
void L1TRC_Send_DUAL_OS_TICK_3G_DBG(unsigned char v1, unsigned char v2);
void L1TRC_Send_DUAL_OS_TICK_ReSync(void);
void L1TRC_Send_DUAL_OS_RTC(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, long v5, unsigned short v6, unsigned long v7, unsigned long v8, unsigned char v9, unsigned char v10, unsigned short v11, unsigned long v12);
void L1TRC_Send_L1SM_Trace_SW1(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L1SM_Trace_SW2(short v1);
void L1TRC_Send_L1SM_Trace_SW3(unsigned long v1);
void L1TRC_Send_L1SM_Trace_SW4(unsigned char v1, unsigned long v2, unsigned long v3, unsigned char v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_L1SM_Trace_SW5(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1SM_DBG_R_32K_UPDATE(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1I_Msg_AvgTAC(unsigned char v1, short v2);
void L1TRC_Send_L1SM_DBG_32KLESS_WAKEUP(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1SM_DBG_32KLESS_FORCE_REPORT(void);
void L1TRC_Send_L1SM_DBG_STABLE_PARAM(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1SM_DBG_32KLESS_UPDATE_LPM(short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1SM_DBG_Timing_Profile(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_L1SM_DBG_TP_A(unsigned short v1, long v2, unsigned short v3, long v4);
void L1TRC_Send_L1SM_DBG_TP_B(unsigned short v1, long v2, unsigned short v3, long v4, long v5);
void L1TRC_Send_L1SM_DBG_TP_C(unsigned short v1, long v2, unsigned short v3, long v4, long v5);
void L1TRC_Send_L1SM_DBG_Timing_Profile_Best_Region(unsigned short v1, long v2, long v3);
void L1TRC_Send_L1SM_DBG_Timing_Profile_Worst_Region(unsigned short v1, long v2, long v3);
void L1TRC_Send_L1SM_DBG_COCLK_UPDATE_FreqOffset(long v1, long v2);
void L1TRC_Send_L1SM_DBG_COCLK_UPDATE_FMRESULT(unsigned long v1, long v2, unsigned long v3);

void Set_L1SM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1SM_1()	(L1SM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1SM_1_GSM_SM_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_SM_M()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_SM_L()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1SM_1_SM_LOCKER_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1SM_1_DUAL_OS_L()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1SM_1_DUAL_OS_DBG_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_32K_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_32K_M()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x80)!=0))
#define ChkL1MsgFltr_L1SM_DBG_CALI_START()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TOPSM_PASS_2G()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_SW_WAKEUP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_SW_WAKEUP_DONE()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CAL_SLEEP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_WAKEUP_INFO_1()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_WAKEUP_INFO_2()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_SET_DURATION()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_SLEEP_CONDITION()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_L1SM_FRAME_TICK()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_ENTER_SLEEP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_WAKEUP_INT()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_WAKEUP_Done()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_Execute_L1()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_WakeUp_Handler_1()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_WakeUp_Handler_2()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_TWO_STAGE_RF()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_Meta()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_L1D()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_L1C()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_Trace32()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_SMDis()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_OS()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_ASSERT()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_SMLock()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_DCXO()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_Cali()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Return_THRD()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Sleep_Large_Offset()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Disable_Turbo_Sleep()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_Over_Sleep()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_DEBUG()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_DEBUG_HEX()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_DUAL_OS_TICK_2G_COMMON()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_2G_RECOVER()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_INITIAL()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_3G_COMMON()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_3G_RECOVER()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_3G_DBG()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_ReSync()	ChkL1ClsFltr_L1SM_1_DUAL_OS_DBG_H()
#define ChkL1MsgFltr_DUAL_OS_RTC()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_L1SM_Trace_SW1()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW2()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW3()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW4()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW5()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_R_32K_UPDATE()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1I_Msg_AvgTAC()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1SM_DBG_32KLESS_WAKEUP()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1SM_DBG_32KLESS_FORCE_REPORT()	ChkL1ClsFltr_L1SM_1_GSM_32K_M()
#define ChkL1MsgFltr_L1SM_DBG_STABLE_PARAM()	ChkL1ClsFltr_L1SM_1_GSM_32K_M()
#define ChkL1MsgFltr_L1SM_DBG_32KLESS_UPDATE_LPM()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1SM_DBG_Timing_Profile()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TP_A()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TP_B()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TP_C()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_Timing_Profile_Best_Region()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_Timing_Profile_Worst_Region()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_COCLK_UPDATE_FreqOffset()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_COCLK_UPDATE_FMRESULT()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()


#endif
