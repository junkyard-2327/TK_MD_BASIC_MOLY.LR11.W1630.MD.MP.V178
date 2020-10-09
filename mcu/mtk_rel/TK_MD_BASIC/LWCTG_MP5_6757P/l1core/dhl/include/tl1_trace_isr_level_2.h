#ifndef L1TRC_AST_L1_Trace_ISR_Context_Group2_DEF_H
#define L1TRC_AST_L1_Trace_ISR_Context_Group2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Str_Bool(v1)  (unsigned char)(v1+0)
#define Str_L1c_UeState(v1)  (unsigned char)(v1+2)
#define Str_Tl1_M_L_Func(v1)  (unsigned char)(v1+10)
#define Str_L1c_Rtb_Channel(v1)  (unsigned char)(v1+49)
#define Str_L1c_Rtb_ConflictType(v1)  (unsigned char)(v1+60)
#define Str_L1c_Rtb_Assert_Cause(v1)  (unsigned char)(v1+76)
#define Str_LPM_SHORT_SLP_State(v1)  (unsigned char)(v1+87)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE0(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x005B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE0(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE0_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x005B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE1(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x015B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE1(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE1_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x015B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE2(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x025B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE2(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE2_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x025B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE3(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x035B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE3(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x035B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE4(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x045B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE4(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE4_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x045B, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE0(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x055B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE0(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE0_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x055B, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE1(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x065B, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE1(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x065B, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE2(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x075B, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE2(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x075B, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE3(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x085B, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE3(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x085B, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE4(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x095B, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE4(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE4_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x095B, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_FS_RSP(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_FS_RSP(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_FS_RSP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_FS_RSSI(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0B5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_FS_RSSI(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group2_FS_RSSI_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0B5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_CS_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0C5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_CS_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define AST_L1_Trace_ISR_Context_Group2_CS_RSP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0C5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_RSP(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_RSP(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_RSP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RA_RSP(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E5B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RA_RSP(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RA_RSP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E5B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_1(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_1(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x105B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_2(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_2_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x105B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_3(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x115B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_3(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_3_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x115B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_4(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x125B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_4(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_4_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x125B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_5(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x135B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_5(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_5_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) TRC_SEND_7_DATA(TRC_MERGE_2S(0x135B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_6(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x145B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_6(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_6_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_8_DATA(TRC_MERGE_2S(0x145B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_7(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x155B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_7(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x155B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_8(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x165B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_2S((short)(v18), (short)(v19)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_8(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19) TRC_SEND_10_DATA(TRC_MERGE_2S(0x165B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_2S((short)(v18), (short)(v19)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_PICH_RSP(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x175B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_PICH_RSP(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_PICH_RSP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x175B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SIR_RSP(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x185B, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SIR_RSP(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SIR_RSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x185B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SPEECH_INFO_RSP(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x195B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SPEECH_INFO_RSP(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SPEECH_INFO_RSP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x195B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_ISCP_RSP(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_ISCP_RSP(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_ISCP_RSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESET_RSP(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B5B, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESET_RSP(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESET_RSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B5B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_ERROR_RSP(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C5B, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_ERROR_RSP(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_ERROR_RSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C5B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RSP(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RSP(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RSP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_EDCH_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1E5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_EDCH_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define AST_L1_Trace_ISR_Context_Group2_EDCH_RSP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1E5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_DRX_RSP(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_DRX_RSP(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_DRX_RSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SYNC_RSP(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x205B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SYNC_RSP(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SYNC_RSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x205B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TIM_UPDATE_RSP(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x215B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TIM_UPDATE_RSP(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TIM_UPDATE_RSP_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x215B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), (long)(v6), (long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TRACE_INFO_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x225B, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v6));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TRACE_INFO_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TRACE_INFO_RSP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_7_DATA(TRC_MERGE_2S(0x225B, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x235B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3), (long)(v5));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x235B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP_BRP(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x245B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP_BRP(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP_BRP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x245B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TIM_ADJ_RSP(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x255B, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TIM_ADJ_RSP(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TIM_ADJ_RSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x255B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SERVING_CELL_RSCP_FILTERED(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x265B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SERVING_CELL_RSCP_FILTERED(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SERVING_CELL_RSCP_FILTERED_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x265B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SIR_WARNING(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x275B, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SIR_WARNING(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SIR_WARNING_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x275B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TX_POWER_WARNING(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x285B, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TX_POWER_WARNING(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TX_POWER_WARNING_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x285B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TA_WARNING(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x295B, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TA_WARNING(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TA_WARNING_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x295B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TX_IS_SRB(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TX_IS_SRB(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TX_IS_SRB_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_IS_SRB(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_IS_SRB(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_IS_SRB_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_IN_OUT_SYNC(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C5B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_IN_OUT_SYNC(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_IN_OUT_SYNC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C5B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_Bch(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_Bch(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_Bch_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Fach(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2F5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Fach(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Fach_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2F5B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Dch(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x305B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Dch(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Dch_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x305B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Hspa(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x315B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Hspa(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Hspa_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x315B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_HSDPA_DATA_IND(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x325B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_HSDPA_DATA_IND(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_HSDPA_DATA_IND_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x325B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TD_MM_TX_MODULE_HW_INIT() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x335B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TD_MM_TX_MODULE_HW_INIT()
#endif
#define AST_L1_Trace_ISR_Context_Group2_TD_MM_TX_MODULE_HW_INIT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x335B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Start3GChannel(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x345B, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Start3GChannel(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_Start3GChannel_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x345B, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Stop3GChannel(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x355B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Stop3GChannel(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_Stop3GChannel_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x355B, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Change_3G_Timer_priority(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x365B, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Change_3G_Timer_priority(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_Change_3G_Timer_priority_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x365B, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Check3GResource(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x375B, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Check3GResource(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_Check3GResource_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x375B, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_3GPeekRTBHigherTask(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x385B, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_3GPeekRTBHigherTask(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_3GPeekRTBHigherTask_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x385B, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_RtbAssertCause(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x395B, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_RtbAssertCause(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_RtbAssertCause_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x395B, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_LPM_SHORT_SLP_STATE(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A5B, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_LPM_SHORT_SLP_STATE(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_LPM_SHORT_SLP_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A5B, (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char AST_L1_Trace_ISR_Context_Group2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE0(unsigned char v1, unsigned long v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE1(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE2(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE3(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE4(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE0(unsigned char v1, unsigned short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE1(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE2(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE3(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE4(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_FS_RSP(short v1, short v2, short v3, unsigned short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_FS_RSSI(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_CS_RSP(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_RSP(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RA_RSP(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_1(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_2(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_3(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_4(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_5(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_6(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_7(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_8(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17, short v18, short v19);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_PICH_RSP(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SIR_RSP(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SPEECH_INFO_RSP(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_ISCP_RSP(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESET_RSP(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_ERROR_RSP(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RSP(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_EDCH_RSP(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_DRX_RSP(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SYNC_RSP(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TIM_UPDATE_RSP(short v1, short v2, short v3, short v4, short v5, long v6, long v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TRACE_INFO_RSP(short v1, unsigned char v2, short v3, short v4, short v5, long v6, short v7, short v8, short v9, short v10, short v11, short v12);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP(short v1, short v2, long v3, short v4, long v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP_BRP(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TIM_ADJ_RSP(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SERVING_CELL_RSCP_FILTERED(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SIR_WARNING(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TX_POWER_WARNING(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TA_WARNING(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TX_IS_SRB(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_IS_SRB(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_IN_OUT_SYNC(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch(short v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_Bch(short v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Fach(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Dch(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Hspa(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_HSDPA_DATA_IND(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TD_MM_TX_MODULE_HW_INIT(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_Start3GChannel(unsigned char v1, short v2, long v3, long v4, long v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_Stop3GChannel(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_Change_3G_Timer_priority(unsigned char v1, long v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_Check3GResource(unsigned char v1, long v2, short v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_3GPeekRTBHigherTask(unsigned char v1, short v2, long v3, long v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_RtbAssertCause(unsigned char v1, short v2, long v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_LPM_SHORT_SLP_STATE(unsigned char v1);

void Set_AST_L1_Trace_ISR_Context_Group2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group2()	(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group2()&&((AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group2()&&((AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE0()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE2()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE3()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE4()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE0()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE2()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE3()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE4()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_FS_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_FS_RSSI()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_CS_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RA_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_2()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_3()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_4()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_5()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_6()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_7()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_8()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_PICH_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SIR_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SPEECH_INFO_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_ISCP_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESET_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_ERROR_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_EDCH_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_DRX_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SYNC_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TIM_UPDATE_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TRACE_INFO_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP_BRP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TIM_ADJ_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SERVING_CELL_RSCP_FILTERED()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SIR_WARNING()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TX_POWER_WARNING()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TA_WARNING()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TX_IS_SRB()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_IS_SRB()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_IN_OUT_SYNC()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_Bch()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Fach()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Dch()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Hspa()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_HSDPA_DATA_IND()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TD_MM_TX_MODULE_HW_INIT()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_Start3GChannel()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_Stop3GChannel()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_Change_3G_Timer_priority()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_Check3GResource()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_3GPeekRTBHigherTask()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_RtbAssertCause()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_LPM_SHORT_SLP_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()


#endif
