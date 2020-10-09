#ifndef L1TRC_AST_L1_Trace_ISR_Context_Group5_DEF_H
#define L1TRC_AST_L1_Trace_ISR_Context_Group5_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Str_Bool(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_FS_CMD(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x005E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_FS_CMD(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_FS_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x005E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_CS_CMD(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x015E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_CS_CMD(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define AST_L1_Trace_ISR_Context_Group2_CS_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x015E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_BCH_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x025E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_BCH_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_BCH_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x025E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_PCH_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x035E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_PCH_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_PCH_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x035E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_FACH_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x045E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_FACH_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_FACH_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x045E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_DCH_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x055E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_DCH_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_DCH_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x055E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TX_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x065E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TX_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TX_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x065E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RA_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x075E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RA_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RA_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x075E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_PICH_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x085E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_PICH_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_PICH_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x085E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TX_DATA_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x095E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TX_DATA_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TX_DATA_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x095E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SERVING_RSCP_MEAS_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SERVING_RSCP_MEAS_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SERVING_RSCP_MEAS_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_INTRA_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x0B5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_INTRA_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define AST_L1_Trace_ISR_Context_Group2_INTRA_RSCP_MEAS_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_7_DATA(TRC_MERGE_2S(0x0B5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_INTER_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x0C5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_INTER_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define AST_L1_Trace_ISR_Context_Group2_INTER_RSCP_MEAS_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_7_DATA(TRC_MERGE_2S(0x0C5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SCS_RSCP_MEAS_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D5E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SCS_RSCP_MEAS_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SCS_RSCP_MEAS_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D5E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_PCH_CS_RSCP_MEAS_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_PCH_CS_RSCP_MEAS_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_PCH_CS_RSCP_MEAS_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_HSDPA_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F5E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_HSDPA_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_HSDPA_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F5E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_STOP_HSDPA_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x105E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_STOP_HSDPA_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_STOP_HSDPA_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x105E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RA_PC_TA_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x115E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RA_PC_TA_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RA_PC_TA_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x115E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_BEGIN_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x125E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_BEGIN_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_BEGIN_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x125E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_END_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x135E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_END_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_END_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x135E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESEL_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x145E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESEL_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESEL_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x145E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RECONFIG_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x155E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RECONFIG_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RECONFIG_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x155E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_HHO_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x165E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_HHO_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_HHO_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x165E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_BHO_UL_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x175E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_BHO_UL_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_BHO_UL_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x175E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_BHO_DL_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x185E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_BHO_DL_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_BHO_DL_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x185E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_REVERT_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x195E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_REVERT_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_REVERT_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x195E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_ISCP_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_ISCP_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_ISCP_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_UARFCN_SET_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B5E, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_UARFCN_SET_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_UARFCN_SET_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B5E, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_ENDIAN_PADDING_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C5E, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_ENDIAN_PADDING_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_ENDIAN_PADDING_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C5E, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MCU_TRACE_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1D5E, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MCU_TRACE_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MCU_TRACE_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1D5E, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESET_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E5E, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESET_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESET_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E5E, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_DRX_TASK_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_DRX_TASK_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_DRX_TASK_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_HSUPA_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x205E, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_HSUPA_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_HSUPA_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x205E, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_EDCH_DATA_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x215E, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_EDCH_DATA_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_EDCH_DATA_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x215E, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SUSPEND_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x225E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SUSPEND_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SUSPEND_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x225E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TIM_BASE_ADJ_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x235E, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TIM_BASE_ADJ_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TIM_BASE_ADJ_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x235E, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_S1S2_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x245E, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_S1S2_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_S1S2_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x245E, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_5MS_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x255E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_5MS_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group2_5MS_RSCP_MEAS_CMD_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x255E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SCELL_SWITCH_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x265E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SCELL_SWITCH_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SCELL_SWITCH_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x265E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SLEEP_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x275E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SLEEP_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SLEEP_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x275E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_GAUGING_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x285E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_GAUGING_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_GAUGING_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x285E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_INJECT_MSG_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x295E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_INJECT_MSG_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_INJECT_MSG_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x295E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_DMO_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A5E, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_DMO_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_DMO_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A5E, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_DRX_ANT_S_CMD(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2C5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_1S2C((short)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_DRX_ANT_S_CMD(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_DRX_ANT_S_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2C5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_1S2C((short)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_ANT_S_CMD(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2D5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_1S2C((short)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_ANT_S_CMD(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_ANT_S_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2D5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_1S2C((short)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TAS_SWITCH_PHYSICAL_ANT_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E5E, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TAS_SWITCH_PHYSICAL_ANT_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TAS_SWITCH_PHYSICAL_ANT_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E5E, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TAS_TX_PWR_DEBUG(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2F5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TAS_TX_PWR_DEBUG(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TAS_TX_PWR_DEBUG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2F5E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_REL_TAS(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x305E, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_REL_TAS(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_REL_TAS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x305E, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_UPDATE_TAS_MEAS(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x315E, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_UPDATE_TAS_MEAS(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group1_UPDATE_TAS_MEAS_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x315E, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_UPDATE_TAS_FSCS(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x325E, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_UPDATE_TAS_FSCS(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group1_UPDATE_TAS_FSCS_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x325E, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TAS_DRX_TRIGGER(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x335E, (short)(v1)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TAS_DRX_TRIGGER(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TAS_DRX_TRIGGER_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x335E, (short)(v1)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TAS_RSSI_RSCP_SNR(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x345E, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TAS_RSSI_RSCP_SNR(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TAS_RSSI_RSCP_SNR_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x345E, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TAS_HTP_FLAG_DEBUG(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x355E, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TAS_HTP_FLAG_DEBUG(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TAS_HTP_FLAG_DEBUG_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x355E, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TAS_SWITCH_ANT_DEBUG(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x365E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TAS_SWITCH_ANT_DEBUG(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TAS_SWITCH_ANT_DEBUG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_9_DATA(TRC_MERGE_2S(0x365E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TAS_DEBUG(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x375E, (short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TAS_DEBUG(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TAS_DEBUG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x375E, (short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TAS_TXPWR_REDUC(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x385E, (short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TAS_TXPWR_REDUC(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TAS_TXPWR_REDUC_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x385E, (short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_B39_TX_SUSPEND(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x395E, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_B39_TX_SUSPEND(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_B39_TX_SUSPEND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x395E, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TEST_3G_FREQ_B34_B39(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A5E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TEST_3G_FREQ_B34_B39(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TEST_3G_FREQ_B34_B39_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A5E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TL1_LL1_TIMER_SYNC(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B5E, (short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TL1_LL1_TIMER_SYNC(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TL1_LL1_TIMER_SYNC_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B5E, (short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TL1_TRIGGER_MAC_INFO(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3C5E, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TL1_TRIGGER_MAC_INFO(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TL1_TRIGGER_MAC_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3C5E, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_TL1_RECEIVE_TRIGGER_INFO(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3D5E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_TL1_RECEIVE_TRIGGER_INFO(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group1_TL1_RECEIVE_TRIGGER_INFO_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3D5E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char AST_L1_Trace_ISR_Context_Group5_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_FS_CMD(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_CS_CMD(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_BCH_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_PCH_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_FACH_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_DCH_CMD(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TX_CMD(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RA_CMD(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_PICH_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TX_DATA_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SERVING_RSCP_MEAS_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_INTRA_RSCP_MEAS_CMD(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_INTER_RSCP_MEAS_CMD(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SCS_RSCP_MEAS_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_PCH_CS_RSCP_MEAS_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_HSDPA_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_STOP_HSDPA_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RA_PC_TA_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_BEGIN_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_END_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESEL_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RECONFIG_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_HHO_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_BHO_UL_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_BHO_DL_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_REVERT_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_ISCP_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_UARFCN_SET_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_ENDIAN_PADDING_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MCU_TRACE_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESET_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_DRX_TASK_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_HSUPA_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_EDCH_DATA_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SUSPEND_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TIM_BASE_ADJ_CMD(short v1, unsigned short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_S1S2_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_5MS_RSCP_MEAS_CMD(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SCELL_SWITCH_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SLEEP_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_GAUGING_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_INJECT_MSG_CMD(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_DMO_CMD(short v1, unsigned short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_DRX_ANT_S_CMD(short v1, short v2, short v3, short v4, long v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_ANT_S_CMD(short v1, short v2, short v3, short v4, long v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TAS_SWITCH_PHYSICAL_ANT_CMD(short v1, unsigned char v2, unsigned char v3, short v4, unsigned char v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TAS_TX_PWR_DEBUG(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_REL_TAS(short v1, unsigned char v2, unsigned char v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_UPDATE_TAS_MEAS(short v1, unsigned char v2, short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_UPDATE_TAS_FSCS(short v1, unsigned char v2, short v3, short v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TAS_DRX_TRIGGER(short v1, unsigned char v2, unsigned char v3, unsigned char v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TAS_RSSI_RSCP_SNR(short v1, unsigned char v2, unsigned char v3, short v4, short v5, long v6, long v7, long v8);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TAS_HTP_FLAG_DEBUG(short v1, unsigned char v2, unsigned char v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TAS_SWITCH_ANT_DEBUG(short v1, short v2, unsigned char v3, long v4, long v5, long v6, long v7, long v8, long v9, unsigned char v10, unsigned char v11);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TAS_DEBUG(short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TAS_TXPWR_REDUC(short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_B39_TX_SUSPEND(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TEST_3G_FREQ_B34_B39(unsigned char v1, unsigned char v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TL1_LL1_TIMER_SYNC(short v1, long v2, long v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TL1_TRIGGER_MAC_INFO(short v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_TL1_RECEIVE_TRIGGER_INFO(unsigned long v1, unsigned long v2, long v3);

void Set_AST_L1_Trace_ISR_Context_Group5_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group5()	(AST_L1_Trace_ISR_Context_Group5_Trace_Filter[0]==1)
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group5()&&((AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group5()&&((AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_3()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group5()&&((AST_L1_Trace_ISR_Context_Group5_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_FS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_CS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_BCH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_PCH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_FACH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_DCH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TX_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_PICH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TX_DATA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SERVING_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_INTRA_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_INTER_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SCS_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_PCH_CS_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_HSDPA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_STOP_HSDPA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RA_PC_TA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_BEGIN_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_END_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESEL_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RECONFIG_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_HHO_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_BHO_UL_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_BHO_DL_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_REVERT_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_ISCP_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_UARFCN_SET_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_ENDIAN_PADDING_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MCU_TRACE_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESET_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_DRX_TASK_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_HSUPA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_EDCH_DATA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SUSPEND_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TIM_BASE_ADJ_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_S1S2_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_5MS_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SCELL_SWITCH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SLEEP_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_GAUGING_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_INJECT_MSG_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_DMO_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_DRX_ANT_S_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_ANT_S_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TAS_SWITCH_PHYSICAL_ANT_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TAS_TX_PWR_DEBUG()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_REL_TAS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_UPDATE_TAS_MEAS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_UPDATE_TAS_FSCS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TAS_DRX_TRIGGER()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TAS_RSSI_RSCP_SNR()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TAS_HTP_FLAG_DEBUG()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TAS_SWITCH_ANT_DEBUG()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TAS_DEBUG()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TAS_TXPWR_REDUC()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_B39_TX_SUSPEND()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TEST_3G_FREQ_B34_B39()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TL1_LL1_TIMER_SYNC()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TL1_TRIGGER_MAC_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_TL1_RECEIVE_TRIGGER_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group5_TEST_CLASS_1()


#endif
