#ifndef L1TRC_UL1SM_1_DEF_H
#define L1TRC_UL1SM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1SM_Trc_Str_Bool(v1)  (unsigned char)(v1+0)
#define UL1SM_Str_IdleRate_User(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_META() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x002B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_META()
#endif
#define UL1SM_DBG_CHECK_META_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x002B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_HISR() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x012B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_HISR()
#endif
#define UL1SM_DBG_CHECK_HISR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x012B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_ASSIGN_GAP() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x022B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_ASSIGN_GAP()
#endif
#define UL1SM_DBG_CHECK_ASSIGN_GAP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x022B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_SLEEP_DIS(v1) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x032B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_SLEEP_DIS(v1)
#endif
#define UL1SM_DBG_CHECK_SLEEP_DIS_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x032B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_RTOS() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x042B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_RTOS()
#endif
#define UL1SM_DBG_CHECK_RTOS_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x042B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_UL1C() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x052B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_UL1C()
#endif
#define UL1SM_DBG_CHECK_UL1C_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x052B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_SLEEP_DUR(v1, v2, v3, v4) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x062B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_SLEEP_DUR(v1, v2, v3, v4)
#endif
#define UL1SM_DBG_CHECK_SLEEP_DUR_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x062B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_LOCKED() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x072B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_LOCKED()
#endif
#define UL1SM_DBG_CHECK_LOCKED_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x072B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_CALI() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x082B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_CALI()
#endif
#define UL1SM_DBG_CHECK_CALI_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x082B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_DCXO_DIV() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x092B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_DCXO_DIV()
#endif
#define UL1SM_DBG_CHECK_DCXO_DIV_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x092B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_SLOT_END() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A2B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_SLOT_END()
#endif
#define UL1SM_DBG_CHECK_SLOT_END_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A2B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CHECK_IS(v1, v2, v3) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B2B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_IS(v1, v2, v3)
#endif
#define UL1SM_DBG_CHECK_IS_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B2B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CALI_START() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C2B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CALI_START()
#endif
#define UL1SM_DBG_CALI_START_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C2B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_LONG_CALI_DONE(v1, v2, v3) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D2B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1SM_DBG_LONG_CALI_DONE(v1, v2, v3)
#endif
#define UL1SM_DBG_LONG_CALI_DONE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D2B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_TOPSM_PASS_3G(v1, v2) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0E2B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1SM_DBG_TOPSM_PASS_3G(v1, v2)
#endif
#define UL1SM_DBG_TOPSM_PASS_3G_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0E2B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_SW_WAKEUP(v1, v2) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F2B, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1SM_DBG_SW_WAKEUP(v1, v2)
#endif
#define UL1SM_DBG_SW_WAKEUP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F2B, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_SW_WAKEUP_END(v1) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x102B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1SM_DBG_SW_WAKEUP_END(v1)
#endif
#define UL1SM_DBG_SW_WAKEUP_END_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x102B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_SLEEP(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x112B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define UL1SM_DBG_SLEEP(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1SM_DBG_SLEEP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x112B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_WAKEUP(v1, v2, v3, v4, v5) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x122B, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1SM_DBG_WAKEUP(v1, v2, v3, v4, v5)
#endif
#define UL1SM_DBG_WAKEUP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x122B, (unsigned short)(v2)), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_RECOVER(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x132B, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (short)(v8)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7), (unsigned long)(v9));\
	} while(0)
#else
	#define UL1SM_DBG_RECOVER(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1SM_DBG_RECOVER_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_8_DATA(TRC_MERGE_2S(0x132B, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (short)(v8)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v7), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_WAKEUP_END(v1, v2, v3) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x142B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1SM_DBG_WAKEUP_END(v1, v2, v3)
#endif
#define UL1SM_DBG_WAKEUP_END_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x142B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_TRC_3G_L1IDLERATIO_USERDEF(v1, v2, v3, v4, v5, v6) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x152B, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1SM_TRC_3G_L1IDLERATIO_USERDEF(v1, v2, v3, v4, v5, v6)
#endif
#define UL1SM_TRC_3G_L1IDLERATIO_USERDEF_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x152B, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1SM_TRC_3G_L1IDLERATIO_SLOT(v1, v2) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x162B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1SM_TRC_3G_L1IDLERATIO_SLOT(v1, v2)
#endif
#define UL1SM_TRC_3G_L1IDLERATIO_SLOT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x162B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_TRC_DEBUG(v1, v2, v3) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x172B, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1SM_TRC_DEBUG(v1, v2, v3)
#endif
#define UL1SM_TRC_DEBUG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x172B, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1SM_DBG_32KLESS_WAKEUP(v1, v2) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x182B, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_32KLESS_WAKEUP(v1, v2)
#endif
#define UL1SM_DBG_32KLESS_WAKEUP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x182B, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x192B, (short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5)
#endif
#define UL1SM_DBG_32KLESS_UPDATE_LPM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x192B, (short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_COCLK_UPDATE_FreqOffset(v1, v2) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A2B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1SM_DBG_COCLK_UPDATE_FreqOffset(v1, v2)
#endif
#define UL1SM_DBG_COCLK_UPDATE_FreqOffset_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A2B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1B2B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1SM_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3)
#endif
#define UL1SM_DBG_COCLK_UPDATE_FMRESULT_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1B2B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2), (unsigned long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1SM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1SM_DBG_CHECK_META(void);
void L1TRC_Send_UL1SM_DBG_CHECK_HISR(void);
void L1TRC_Send_UL1SM_DBG_CHECK_ASSIGN_GAP(void);
void L1TRC_Send_UL1SM_DBG_CHECK_SLEEP_DIS(unsigned long v1);
void L1TRC_Send_UL1SM_DBG_CHECK_RTOS(void);
void L1TRC_Send_UL1SM_DBG_CHECK_UL1C(void);
void L1TRC_Send_UL1SM_DBG_CHECK_SLEEP_DUR(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1SM_DBG_CHECK_LOCKED(void);
void L1TRC_Send_UL1SM_DBG_CHECK_CALI(void);
void L1TRC_Send_UL1SM_DBG_CHECK_DCXO_DIV(void);
void L1TRC_Send_UL1SM_DBG_CHECK_SLOT_END(void);
void L1TRC_Send_UL1SM_DBG_CHECK_IS(unsigned char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_UL1SM_DBG_CALI_START(void);
void L1TRC_Send_UL1SM_DBG_LONG_CALI_DONE(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1SM_DBG_TOPSM_PASS_3G(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1SM_DBG_SW_WAKEUP(unsigned long v1, unsigned char v2);
void L1TRC_Send_UL1SM_DBG_SW_WAKEUP_END(unsigned long v1);
void L1TRC_Send_UL1SM_DBG_SLEEP(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_UL1SM_DBG_WAKEUP(unsigned long v1, unsigned short v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1SM_DBG_RECOVER(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned short v5, unsigned short v6, unsigned long v7, short v8, unsigned long v9);
void L1TRC_Send_UL1SM_DBG_WAKEUP_END(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1SM_TRC_3G_L1IDLERATIO_USERDEF(unsigned long v1, unsigned long v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1SM_TRC_3G_L1IDLERATIO_SLOT(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1SM_TRC_DEBUG(unsigned short v1, long v2, long v3);
void L1TRC_Send_UL1SM_DBG_32KLESS_WAKEUP(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1SM_DBG_32KLESS_UPDATE_LPM(short v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_UL1SM_DBG_COCLK_UPDATE_FreqOffset(long v1, long v2);
void L1TRC_Send_UL1SM_DBG_COCLK_UPDATE_FMRESULT(unsigned long v1, long v2, unsigned long v3);

void Set_UL1SM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1SM_1()	(UL1SM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()	(ChkL1ModFltr_UL1SM_1()&&((UL1SM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1SM_1_UMTS_SM_L()	(ChkL1ModFltr_UL1SM_1()&&((UL1SM_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1SM_1_UMTS_32K_H()	(ChkL1ModFltr_UL1SM_1()&&((UL1SM_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_META()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_HISR()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_ASSIGN_GAP()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_SLEEP_DIS()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_RTOS()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_UL1C()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_SLEEP_DUR()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_LOCKED()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_CALI()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_DCXO_DIV()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_SLOT_END()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_IS()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CALI_START()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_LONG_CALI_DONE()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_TOPSM_PASS_3G()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_SW_WAKEUP()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_SW_WAKEUP_END()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_SLEEP()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_WAKEUP()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_RECOVER()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_WAKEUP_END()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_TRC_3G_L1IDLERATIO_USERDEF()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_TRC_3G_L1IDLERATIO_SLOT()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_L()
#define ChkL1MsgFltr_UL1SM_TRC_DEBUG()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_32KLESS_WAKEUP()	ChkL1ClsFltr_UL1SM_1_UMTS_32K_H()
#define ChkL1MsgFltr_UL1SM_DBG_32KLESS_UPDATE_LPM()	ChkL1ClsFltr_UL1SM_1_UMTS_32K_H()
#define ChkL1MsgFltr_UL1SM_DBG_COCLK_UPDATE_FreqOffset()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_COCLK_UPDATE_FMRESULT()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()


#endif
