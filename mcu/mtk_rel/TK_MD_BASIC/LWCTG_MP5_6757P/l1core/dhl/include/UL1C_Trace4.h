#ifndef L1TRC_UL1C_PRI4_DEF_H
#define L1TRC_UL1C_PRI4_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1T_TRC_EDCH_Config(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0029, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EDCH_Config(v1, v2, v3, v4)
#endif
#define UL1T_TRC_EDCH_Config_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0029, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EDCH_Setup(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0129, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EDCH_Setup(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_EDCH_Setup_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0129, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_EDCH_Modify(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0229, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EDCH_Modify(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_EDCH_Modify_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0229, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EDCH_Release(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0329, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EDCH_Release(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_EDCH_Release_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0329, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EAGCH_Calculate_Param(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0429, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_EAGCH_Calculate_Param(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_EAGCH_Calculate_Param_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0429, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EHICH_Calculate_Param(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0529, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EHICH_Calculate_Param(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_EHICH_Calculate_Param_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0529, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Calculate_Result(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0629, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Calculate_Result(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_Calculate_Result_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0629, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_ERGCH_Calculate_Param(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0729, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ERGCH_Calculate_Param(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_ERGCH_Calculate_Param_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0729, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_EAGCH_Param(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0829, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_EAGCH_Param(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1T_TRC_Compare_EAGCH_Param_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0829, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_EHICH_Param(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0929, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_EHICH_Param(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_Compare_EHICH_Param_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0929, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_Param_old(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_Param_old(v1, v2, v3)
#endif
#define UL1T_TRC_Compare_Param_old_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_Param_new(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_Param_new(v1, v2, v3)
#endif
#define UL1T_TRC_Compare_Param_new_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_Result(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C29, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_Result(v1, v2, v3, v4)
#endif
#define UL1T_TRC_Compare_Result_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C29, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_Result2(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_Result2(v1, v2, v3)
#endif
#define UL1T_TRC_Compare_Result2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_Result3(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_Result3(v1, v2, v3)
#endif
#define UL1T_TRC_Compare_Result3_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_ERGCH_Param(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F29, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_ERGCH_Param(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_Compare_ERGCH_Param_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F29, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_ERGCH_Result(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1029, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_ERGCH_Result(v1, v2, v3, v4)
#endif
#define UL1T_TRC_Compare_ERGCH_Result_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1029, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EDCH_Remove(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1129, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EDCH_Remove(v1, v2, v3)
#endif
#define UL1T_TRC_EDCH_Remove_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1129, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_Start_Timer(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1229, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_Start_Timer(v1, v2, v3, v4)
#endif
#define UL1I_TRC_EDCH_Start_Timer_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1229, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Start_EDCH(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1329, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Start_EDCH(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Start_EDCH_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1329, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Internal_Start_EDCH(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1429, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Internal_Start_EDCH(v1, v2)
#endif
#define UL1I_TRC_Internal_Start_EDCH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1429, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Stop_EDCH(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1529, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Stop_EDCH(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Stop_EDCH_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1529, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_ERNTI_Config(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1629, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ERNTI_Config(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_ERNTI_Config_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1629, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_TTI_Config(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1729, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_TTI_Config(v1, v2)
#endif
#define UL1I_TRC_EDCH_TTI_Config_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1729, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDPCCH_Config(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1829, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDPCCH_Config(v1, v2)
#endif
#define UL1I_TRC_EDPCCH_Config_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1829, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDPDCH_Config(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1929, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_EDPDCH_Config(v1, v2, v3)
#endif
#define UL1I_TRC_EDPDCH_Config_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1929, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EDPDCH_Config2(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A29, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDPDCH_Config2(v1, v2, v3, v4)
#endif
#define UL1I_TRC_EDPDCH_Config2_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A29, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_Serv_Cell_Config(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_Serv_Cell_Config(v1, v2, v3)
#endif
#define UL1I_TRC_EDCH_Serv_Cell_Config_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_Channel_Config(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C29, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_Channel_Config(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_EDCH_Channel_Config_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C29, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_HARQ_Config(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D29, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_HARQ_Config(v1, v2)
#endif
#define UL1I_TRC_EDCH_HARQ_Config_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D29, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_UL1D_EDCH_Start(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_EDCH_Start(v1, v2, v3)
#endif
#define UL1I_TRC_UL1D_EDCH_Start_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_UL1D_EHICH_Remove(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1F29, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_EHICH_Remove(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1I_TRC_UL1D_EHICH_Remove_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1F29, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_UL1D_ERGCH_Remove(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2029, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_ERGCH_Remove(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1I_TRC_UL1D_ERGCH_Remove_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2029, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_New_UL1_EHICH_Info(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2129, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_New_UL1_EHICH_Info(v1, v2, v3, v4)
#endif
#define UL1I_TRC_New_UL1_EHICH_Info_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2129, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Delete_UL1_EHICH_Info(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2229, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Delete_UL1_EHICH_Info(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Delete_UL1_EHICH_Info_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2229, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_New_UL1_ERGCH_Info(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2329, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_New_UL1_ERGCH_Info(v1, v2, v3, v4)
#endif
#define UL1I_TRC_New_UL1_ERGCH_Info_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2329, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Delete_UL1_ERGCH_Info(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2429, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Delete_UL1_ERGCH_Info(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Delete_UL1_ERGCH_Info_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2429, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_EDPDCH_Calculate_Param(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2529, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1T_TRC_EDPDCH_Calculate_Param(v1, v2, v3)
#endif
#define UL1T_TRC_EDPDCH_Calculate_Param_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2529, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EDPDCH_Get_Buffer(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2629, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1T_TRC_EDPDCH_Get_Buffer(v1, v2)
#endif
#define UL1T_TRC_EDPDCH_Get_Buffer_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2629, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_EDCH_Action(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2729, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v7), (char)(v8), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_EDCH_Action(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1T_TRC_HSDSCH_EDCH_Action_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2729, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v7), (char)(v8), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_EDCH_Set_MAC_Event(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2829, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_EDCH_Set_MAC_Event(v1, v2)
#endif
#define UL1I_TRC_UL1D_EDCH_Set_MAC_Event_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2829, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_UL1D_Intf(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2929, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_UL1D_Intf(v1, v2, v3)
#endif
#define UL1I_TRC_EDCH_UL1D_Intf_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2929, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Prepare_Sec_EDCH_Action(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A29, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1T_TRC_Prepare_Sec_EDCH_Action(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_Prepare_Sec_EDCH_Action_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A29, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_Config(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B29, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_Config(v1, v2, v3, v4)
#endif
#define UL1T_TRC_HSDSCH_Config_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B29, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_Setup(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_Setup(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_HSDSCH_Setup_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_Modify(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D29, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_Modify(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_HSDSCH_Modify_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D29, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_Release(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_Release(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_HSDSCH_Release_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E29, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_Suspend(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F29, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_Suspend(v1, v2)
#endif
#define UL1T_TRC_HSDSCH_Suspend_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F29, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSDSCH_Start_Timer(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3029, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HSDSCH_Start_Timer(v1, v2, v3)
#endif
#define UL1I_TRC_HSDSCH_Start_Timer_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3029, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Start_HSDSCH(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3129, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Start_HSDSCH(v1, v2, v3)
#endif
#define UL1I_TRC_Start_HSDSCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3129, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Internal_Start_HSDSCH(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3229, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Internal_Start_HSDSCH(v1)
#endif
#define UL1I_TRC_Internal_Start_HSDSCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3229, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Stop_HSDSCH(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3329, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Stop_HSDSCH(v1, v2, v3)
#endif
#define UL1I_TRC_Stop_HSDSCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3329, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_HS_Serv_RL_Config(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3429, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_HS_Serv_RL_Config(v1, v2)
#endif
#define UL1I_TRC_UL1D_HS_Serv_RL_Config_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3429, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSDSCH_Meas_Po(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3529, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HSDSCH_Meas_Po(v1, v2)
#endif
#define UL1I_TRC_HSDSCH_Meas_Po_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3529, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_HS_State_Info(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3629, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_HS_State_Info(v1, v2, v3)
#endif
#define UL1I_TRC_UL1D_HS_State_Info_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3629, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_HS_DSCH_Start(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3729, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_HS_DSCH_Start(v1, v2)
#endif
#define UL1I_TRC_UL1D_HS_DSCH_Start_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3729, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_HS_Set_MAC_Event(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3829, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_HS_Set_MAC_Event(v1, v2)
#endif
#define UL1I_TRC_UL1D_HS_Set_MAC_Event_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3829, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSDSCH_UL1D_Intf(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3929, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_HSDSCH_UL1D_Intf(v1, v2)
#endif
#define UL1I_TRC_HSDSCH_UL1D_Intf_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3929, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Update_Strongest_Cells(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3A29, (short)(v3)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Update_Strongest_Cells(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1I_TRC_Update_Strongest_Cells_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3A29, (short)(v3)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Update_Strongest_Cells_RXD(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3B29, (short)(v3)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Update_Strongest_Cells_RXD(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1I_TRC_Update_Strongest_Cells_RXD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3B29, (short)(v3)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Update_Strongest_Cells(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3C29, (short)(v3)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Update_Strongest_Cells(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_Update_Strongest_Cells_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3C29, (short)(v3)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Update_Strongest_Cells_RXD(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3D29, (short)(v3)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Update_Strongest_Cells_RXD(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_Update_Strongest_Cells_RXD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3D29, (short)(v3)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Update_Serving_Cell(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3E29, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Update_Serving_Cell(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_Update_Serving_Cell_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3E29, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Update_Serving_Cell_RXD(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3F29, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Update_Serving_Cell_RXD(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_Update_Serving_Cell_RXD_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3F29, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Send_DC_Report(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4029, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1T_TRC_Send_DC_Report(v1, v2, v3, v4)
#endif
#define UL1T_TRC_Send_DC_Report_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4029, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HS_Reset_HSCE_DB(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4129, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HS_Reset_HSCE_DB(v1, v2)
#endif
#define UL1T_TRC_HS_Reset_HSCE_DB_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4129, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Sec_HSDSCH_64QAM(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4229, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Sec_HSDSCH_64QAM(v1, v2, v3)
#endif
#define UL1I_TRC_Sec_HSDSCH_64QAM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4229, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Sec_HSDSCH_Meas_Po(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4329, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Sec_HSDSCH_Meas_Po(v1, v2, v3)
#endif
#define UL1I_TRC_Sec_HSDSCH_Meas_Po_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4329, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Sec_HSDSCH_MAC_Type(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4429, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Sec_HSDSCH_MAC_Type(v1, v2, v3)
#endif
#define UL1I_TRC_Sec_HSDSCH_MAC_Type_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4429, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Wakeup(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4529, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Wakeup(v1, v2)
#endif
#define UL1I_TRC_Wakeup_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4529, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPC_Config(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4629, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (char)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_CPC_Config(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_CPC_Config_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4629, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPC_Control(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4729, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CPC_Control(v1, v2)
#endif
#define UL1I_TRC_CPC_Control_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4729, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_Monitor_Order_Status(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4829, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Monitor_Order_Status(v1, v2, v3)
#endif
#define UL1I_TRC_Monitor_Order_Status_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4829, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_Monitor_Order_Timer(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4929, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Monitor_Order_Timer(v1, v2)
#endif
#define UL1I_TRC_Monitor_Order_Timer_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4929, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_SkipSyncA(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A29, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SkipSyncA(v1)
#endif
#define UL1I_TRC_SkipSyncA_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A29, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CEDCH_Termination(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B29, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CEDCH_Termination(v1, v2)
#endif
#define UL1I_TRC_CEDCH_Termination_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B29, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CEDCH_Status(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4C29, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CEDCH_Status(v1, v2)
#endif
#define UL1I_TRC_CEDCH_Status_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4C29, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_CTCH_ChannelPriority(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D29, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_CTCH_ChannelPriority(v1, v2)
#endif
#define UL1T_TRC_CTCH_ChannelPriority_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D29, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSPASYS_Configure(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E29, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HSPASYS_Configure(v1, v2)
#endif
#define UL1I_TRC_HSPASYS_Configure_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E29, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSPASYS_Status(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F29, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HSPASYS_Status(v1, v2)
#endif
#define UL1I_TRC_HSPASYS_Status_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F29, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSPASYS_Delay_frame(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5029, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HSPASYS_Delay_frame(v1, v2)
#endif
#define UL1I_TRC_HSPASYS_Delay_frame_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5029, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSPASYS_ON_Control(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5129, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HSPASYS_ON_Control(v1, v2)
#endif
#define UL1I_TRC_HSPASYS_ON_Control_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5129, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSPASYS_OFF_Control(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5229, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HSPASYS_OFF_Control(v1, v2)
#endif
#define UL1I_TRC_HSPASYS_OFF_Control_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5229, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1C_PRI4_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1T_TRC_EDCH_Config(unsigned char v1, char v2, char v3, unsigned short v4);
void L1TRC_Send_UL1T_TRC_EDCH_Setup(unsigned char v1, short v2, short v3, char v4, char v5);
void L1TRC_Send_UL1T_TRC_EDCH_Modify(unsigned char v1, short v2, short v3, char v4, char v5, unsigned short v6);
void L1TRC_Send_UL1T_TRC_EDCH_Release(unsigned char v1, short v2, short v3, char v4, char v5);
void L1TRC_Send_UL1T_TRC_EAGCH_Calculate_Param(unsigned char v1, short v2, char v3, short v4, short v5, short v6);
void L1TRC_Send_UL1T_TRC_EHICH_Calculate_Param(unsigned char v1, short v2, char v3, short v4, short v5);
void L1TRC_Send_UL1T_TRC_Calculate_Result(unsigned char v1, short v2, short v3, char v4, short v5);
void L1TRC_Send_UL1T_TRC_ERGCH_Calculate_Param(unsigned char v1, short v2, char v3, short v4, short v5);
void L1TRC_Send_UL1T_TRC_Compare_EAGCH_Param(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10);
void L1TRC_Send_UL1T_TRC_Compare_EHICH_Param(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1T_TRC_Compare_Param_old(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_Compare_Param_new(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_Compare_Result(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_Compare_Result2(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_Compare_Result3(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_Compare_ERGCH_Param(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1T_TRC_Compare_ERGCH_Result(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_EDCH_Remove(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_EDCH_Start_Timer(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_Start_EDCH(unsigned char v1, short v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_Internal_Start_EDCH(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_Stop_EDCH(unsigned char v1, short v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_ERNTI_Config(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_EDCH_TTI_Config(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_EDPCCH_Config(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_EDPDCH_Config(unsigned char v1, unsigned long v2, short v3);
void L1TRC_Send_UL1I_TRC_EDPDCH_Config2(unsigned char v1, char v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_EDCH_Serv_Cell_Config(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_EDCH_Channel_Config(unsigned char v1, short v2, char v3, short v4, char v5);
void L1TRC_Send_UL1I_TRC_EDCH_HARQ_Config(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_UL1D_EDCH_Start(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_UL1D_EHICH_Remove(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1I_TRC_UL1D_ERGCH_Remove(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1I_TRC_New_UL1_EHICH_Info(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_Delete_UL1_EHICH_Info(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_New_UL1_ERGCH_Info(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_Delete_UL1_ERGCH_Info(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_EDPDCH_Calculate_Param(unsigned char v1, char v2, unsigned long v3);
void L1TRC_Send_UL1T_TRC_EDPDCH_Get_Buffer(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1T_TRC_HSDSCH_EDCH_Action(unsigned char v1, short v2, short v3, char v4, char v5, unsigned short v6, char v7, char v8, unsigned short v9);
void L1TRC_Send_UL1I_TRC_UL1D_EDCH_Set_MAC_Event(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_EDCH_UL1D_Intf(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1T_TRC_Prepare_Sec_EDCH_Action(unsigned char v1, char v2, char v3, char v4, unsigned short v5);
void L1TRC_Send_UL1T_TRC_HSDSCH_Config(unsigned char v1, char v2, char v3, unsigned short v4);
void L1TRC_Send_UL1T_TRC_HSDSCH_Setup(unsigned char v1, short v2, short v3, char v4, char v5);
void L1TRC_Send_UL1T_TRC_HSDSCH_Modify(unsigned char v1, short v2, short v3, char v4, char v5, unsigned short v6);
void L1TRC_Send_UL1T_TRC_HSDSCH_Release(unsigned char v1, short v2, short v3, char v4, char v5);
void L1TRC_Send_UL1T_TRC_HSDSCH_Suspend(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_HSDSCH_Start_Timer(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_Start_HSDSCH(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_Internal_Start_HSDSCH(unsigned char v1);
void L1TRC_Send_UL1I_TRC_Stop_HSDSCH(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_UL1D_HS_Serv_RL_Config(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_HSDSCH_Meas_Po(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_UL1D_HS_State_Info(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_UL1D_HS_DSCH_Start(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_UL1D_HS_Set_MAC_Event(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_HSDSCH_UL1D_Intf(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_Update_Strongest_Cells(unsigned char v1, char v2, short v3, char v4, char v5, char v6, short v7, short v8, short v9);
void L1TRC_Send_UL1I_TRC_Update_Strongest_Cells_RXD(unsigned char v1, char v2, short v3, char v4, char v5, char v6, short v7, short v8, short v9);
void L1TRC_Send_UL1T_TRC_Update_Strongest_Cells(unsigned char v1, char v2, short v3, char v4, char v5, short v6, short v7, short v8);
void L1TRC_Send_UL1T_TRC_Update_Strongest_Cells_RXD(unsigned char v1, char v2, short v3, char v4, char v5, short v6, short v7, short v8);
void L1TRC_Send_UL1T_TRC_Update_Serving_Cell(unsigned char v1, char v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_Update_Serving_Cell_RXD(unsigned char v1, char v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_Send_DC_Report(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_UL1T_TRC_HS_Reset_HSCE_DB(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_Sec_HSDSCH_64QAM(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_Sec_HSDSCH_Meas_Po(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_Sec_HSDSCH_MAC_Type(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_Wakeup(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_CPC_Config(unsigned char v1, char v2, short v3, char v4, char v5);
void L1TRC_Send_UL1I_TRC_CPC_Control(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_Monitor_Order_Status(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_Monitor_Order_Timer(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_SkipSyncA(unsigned char v1);
void L1TRC_Send_UL1I_TRC_CEDCH_Termination(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_CEDCH_Status(unsigned char v1, short v2);
void L1TRC_Send_UL1T_TRC_CTCH_ChannelPriority(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_HSPASYS_Configure(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_HSPASYS_Status(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_HSPASYS_Delay_frame(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_HSPASYS_ON_Control(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_HSPASYS_OFF_Control(unsigned char v1, short v2);

void Set_UL1C_PRI4_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1C_PRI4()	(UL1C_PRI4_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_L()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_CPC_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_MonitorOrd_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_CEDCH_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_DC_HSDSCH_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_ETWS_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[2]&0x02)!=0))
#define ChkL1MsgFltr_UL1T_TRC_EDCH_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_EDCH_Setup()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_EDCH_Modify()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_EDCH_Release()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_EAGCH_Calculate_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_EHICH_Calculate_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Calculate_Result()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_ERGCH_Calculate_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_EAGCH_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_EHICH_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_Param_old()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_Param_new()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_Result()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_Result2()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_Result3()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_ERGCH_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_ERGCH_Result()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_EDCH_Remove()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_Start_Timer()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_Start_EDCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_Internal_Start_EDCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_Stop_EDCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_ERNTI_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_TTI_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDPCCH_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDPDCH_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDPDCH_Config2()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_Serv_Cell_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_Channel_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_HARQ_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_EDCH_Start()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_EHICH_Remove()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_ERGCH_Remove()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_New_UL1_EHICH_Info()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_Delete_UL1_EHICH_Info()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_New_UL1_ERGCH_Info()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_Delete_UL1_ERGCH_Info()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_EDPDCH_Calculate_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_EDPDCH_Get_Buffer()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_EDCH_Action()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_EDCH_Set_MAC_Event()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_UL1D_Intf()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Prepare_Sec_EDCH_Action()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_Setup()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_Modify()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_Release()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_Suspend()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSDSCH_Start_Timer()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Start_HSDSCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Internal_Start_HSDSCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Stop_HSDSCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_HS_Serv_RL_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSDSCH_Meas_Po()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_HS_State_Info()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_HS_DSCH_Start()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_HS_Set_MAC_Event()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSDSCH_UL1D_Intf()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Update_Strongest_Cells()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Update_Strongest_Cells_RXD()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Update_Strongest_Cells()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Update_Strongest_Cells_RXD()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Update_Serving_Cell()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Update_Serving_Cell_RXD()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Send_DC_Report()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HS_Reset_HSCE_DB()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Sec_HSDSCH_64QAM()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Sec_HSDSCH_Meas_Po()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Sec_HSDSCH_MAC_Type()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Wakeup()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_L()
#define ChkL1MsgFltr_UL1I_TRC_CPC_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_CPC_M()
#define ChkL1MsgFltr_UL1I_TRC_CPC_Control()	ChkL1ClsFltr_UL1C_PRI4_UL1C_CPC_M()
#define ChkL1MsgFltr_UL1I_TRC_Monitor_Order_Status()	ChkL1ClsFltr_UL1C_PRI4_UL1C_MonitorOrd_M()
#define ChkL1MsgFltr_UL1I_TRC_Monitor_Order_Timer()	ChkL1ClsFltr_UL1C_PRI4_UL1C_MonitorOrd_M()
#define ChkL1MsgFltr_UL1I_TRC_SkipSyncA()	ChkL1ClsFltr_UL1C_PRI4_UL1C_CEDCH_M()
#define ChkL1MsgFltr_UL1I_TRC_CEDCH_Termination()	ChkL1ClsFltr_UL1C_PRI4_UL1C_CEDCH_M()
#define ChkL1MsgFltr_UL1I_TRC_CEDCH_Status()	ChkL1ClsFltr_UL1C_PRI4_UL1C_CEDCH_M()
#define ChkL1MsgFltr_UL1T_TRC_CTCH_ChannelPriority()	ChkL1ClsFltr_UL1C_PRI4_UL1C_ETWS_M()
#define ChkL1MsgFltr_UL1I_TRC_HSPASYS_Configure()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSPASYS_Status()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSPASYS_Delay_frame()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSPASYS_ON_Control()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSPASYS_OFF_Control()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()


#endif
