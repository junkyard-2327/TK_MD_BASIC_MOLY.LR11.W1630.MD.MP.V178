#ifndef L1TRC_AST_L1_Trace_ISR_Context_Group6_DEF_H
#define L1TRC_AST_L1_Trace_ISR_Context_Group6_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Str_Bool(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_RSP(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x005F, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_RSP(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_RSP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x005F, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x015F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x015F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_OTCAL() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x025F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_OTCAL()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_OTCAL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x025F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x035F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x035F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x045F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x045F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x055F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x055F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x065F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x065F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x075F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x075F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x085F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x085F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x095F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x095F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x105F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x105F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x115F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x115F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x125F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x125F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x135F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x135F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x145F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x145F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x155F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x155F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x165F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x165F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_CS() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x175F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_CS()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_CS_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x175F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RX() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x185F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RX()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RX_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x185F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_MEAS_RSCP() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x195F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_MEAS_RSCP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_MEAS_RSCP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x195F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_SIR_PWR_TA() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_SIR_PWR_TA()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_SIR_PWR_TA_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RESET() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RESET()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RESET_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_EAGCH_EHICH() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_EAGCH_EHICH()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_EAGCH_EHICH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_TIM_UPD() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_TIM_UPD()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_TIM_UPD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_ABBREG() do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_ABBREG()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_ABBREG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E5F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_DPA_ONLY_RSP(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F5F, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_DPA_ONLY_RSP(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_DPA_ONLY_RSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F5F, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_UPA_ONLY_RSP(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x205F, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_UPA_ONLY_RSP(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_UPA_ONLY_RSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x205F, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TL1D_PHASE3_MDM(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x215F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TL1D_PHASE3_MDM(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TL1D_PHASE3_MDM_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x215F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_BPI_Conflict_INFO(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x225F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_BPI_Conflict_INFO(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_BPI_Conflict_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x225F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_BPI_Conflict_Count(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x235F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_BPI_Conflict_Count(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_BPI_Conflict_Count_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x235F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TL1_HSUPA_STATE(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x245F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TL1_HSUPA_STATE(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TL1_HSUPA_STATE_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x245F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char AST_L1_Trace_ISR_Context_Group6_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_RSP(short v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_OTCAL(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_CS(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RX(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_MEAS_RSCP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_SIR_PWR_TA(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RESET(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_EAGCH_EHICH(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_TIM_UPD(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_ABBREG(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_DPA_ONLY_RSP(short v1, short v2, unsigned short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_UPA_ONLY_RSP(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TL1D_PHASE3_MDM(unsigned long v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_BPI_Conflict_INFO(long v1, long v2, long v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_BPI_Conflict_Count(long v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TL1_HSUPA_STATE(long v1, long v2, long v3);

void Set_AST_L1_Trace_ISR_Context_Group6_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group6()	(AST_L1_Trace_ISR_Context_Group6_Trace_Filter[0]==1)
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group6()&&((AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_2()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group6()&&((AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_3()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group6()&&((AST_L1_Trace_ISR_Context_Group6_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_OTCAL()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_CS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RX()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_MEAS_RSCP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_SIR_PWR_TA()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RESET()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_EAGCH_EHICH()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_TIM_UPD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_ABBREG()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_DPA_ONLY_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_UPA_ONLY_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TL1D_PHASE3_MDM()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_BPI_Conflict_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_BPI_Conflict_Count()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TL1_HSUPA_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group6_TEST_CLASS_1()


#endif
