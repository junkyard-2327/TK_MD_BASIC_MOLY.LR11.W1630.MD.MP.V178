#ifndef L1TRC_EL1D_TPC0_DEF_H
#define L1TRC_EL1D_TPC0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_CONTEXT(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_TPC_CHECK_TX_1ST_FLAG(v1)  (unsigned char)(v1+3)
#define EL1D_TRC_STR_TPC_DFE_BUS(v1)  (unsigned char)(v1+6)
#define EL1D_TRC_STR_TPC_START_REQUEST(v1)  (unsigned char)(v1+8)
#define EL1D_TRC_STR_TPC_OFF_REQUEST(v1)  (unsigned char)(v1+10)
#define EL1D_TRC_STR_TPC_CHANNEL(v1)  (unsigned char)(v1+13)
#define EL1D_TRC_STR_TPC_MMTX_SHMDL(v1)  (unsigned char)(v1+19)
#define EL1D_TRC_STR_TPC_MODE(v1)  (unsigned char)(v1+23)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_CONTEXT_ENTRY(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_CONTEXT_ENTRY(v1)
#endif
#define EL1D_TRC_TPC_CONTEXT_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_SHM_DL_INFO(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x013D, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TPC_SHM_DL_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_SHM_DL_INFO_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x013D, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_REQUEST_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x023D, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_TPC_REQUEST_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_TPC_REQUEST_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x023D, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_OFF_REQUEST_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x033D, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v5), (long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_TPC_OFF_REQUEST_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_TPC_OFF_REQUEST_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x033D, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_CANCEL_REQUEST(v1, v2) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x043D, (short)(v2)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TPC_CANCEL_REQUEST(v1, v2)
#endif
#define EL1D_TRC_TPC_CANCEL_REQUEST_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x043D, (short)(v2)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_PUCCH_RB_START(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x053D, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PUCCH_RB_START(v1)
#endif
#define EL1D_TRC_TPC_PUCCH_RB_START_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x053D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_TIME_CHECK_INFO(v1, v2) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x063D, (short)(v1)), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TPC_TIME_CHECK_INFO(v1, v2)
#endif
#define EL1D_TRC_TPC_TIME_CHECK_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x063D, (short)(v1)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_CHECK_TX_1ST_FLAG(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x073D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_CHECK_TX_1ST_FLAG(v1)
#endif
#define EL1D_TRC_TPC_CHECK_TX_1ST_FLAG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x073D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_NOT_TX_1ST_CNT_DOWN(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x083D, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_TPC_NOT_TX_1ST_CNT_DOWN(v1)
#endif
#define EL1D_TRC_TPC_NOT_TX_1ST_CNT_DOWN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x083D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_LTPC_IRQ_SCH(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x093D, (short)(v1)), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TPC_LTPC_IRQ_SCH(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_LTPC_IRQ_SCH_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x093D, (short)(v1)), (long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_LTPC_GDMA_TRIG(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A3D, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_TPC_LTPC_GDMA_TRIG(v1)
#endif
#define EL1D_TRC_TPC_LTPC_GDMA_TRIG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A3D, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_LTPC_C2M_TRIG() do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_LTPC_C2M_TRIG()
#endif
#define EL1D_TRC_TPC_LTPC_C2M_TRIG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_LTPC_DFE_BUS(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C3D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_LTPC_DFE_BUS(v1)
#endif
#define EL1D_TRC_TPC_LTPC_DFE_BUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C3D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_PGA_AB_G_DIFF(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PGA_AB_G_DIFF(v1)
#endif
#define EL1D_TRC_TPC_PGA_AB_G_DIFF_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_CAL_DATA_UPDATE(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_TPC_CAL_DATA_UPDATE(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_CAL_DATA_UPDATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_MODE_SEL(v1, v2) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F3D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_MODE_SEL(v1, v2)
#endif
#define EL1D_TRC_TPC_MODE_SEL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F3D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_TX_POUT_TARGET(v1, v2) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x103D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_TX_POUT_TARGET(v1, v2)
#endif
#define EL1D_TRC_TPC_TX_POUT_TARGET_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x103D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_DFESYS_BUS_DBG(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x113D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TPC_DFESYS_BUS_DBG(v1)
#endif
#define EL1D_TRC_TPC_DFESYS_BUS_DBG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x113D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_SINETONE_INPUT(v1, v2, v3, v4) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x123D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TPC_SINETONE_INPUT(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TPC_SINETONE_INPUT_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x123D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_SINETONE_OUTPUT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x133D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_TPC_SINETONE_OUTPUT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_TPC_SINETONE_OUTPUT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x133D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_SINETONE_TEST(v1, v2, v3, v4) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x143D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TPC_SINETONE_TEST(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TPC_SINETONE_TEST_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x143D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_ALGO_TEST1(v1, v2) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x153D, (short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TPC_ALGO_TEST1(v1, v2)
#endif
#define EL1D_TRC_TPC_ALGO_TEST1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x153D, (short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_ALGO_TEST2(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x163D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TPC_ALGO_TEST2(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_ALGO_TEST2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x163D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_ALGO_TEST3(v1, v2, v3, v4) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x173D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TPC_ALGO_TEST3(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TPC_ALGO_TEST3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x173D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_PGA_DNL(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x183D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PGA_DNL(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_PGA_DNL_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x183D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_GAIN_ASYM_CAL(v1, v2, v3, v4) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x193D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TPC_GAIN_ASYM_CAL(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TPC_GAIN_ASYM_CAL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x193D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_GA_CMIF(v1, v2, v3, v4) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1A3D, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TPC_GA_CMIF(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TPC_GA_CMIF_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1A3D, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_MMTX_SHMDL(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B3D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_MMTX_SHMDL(v1)
#endif
#define EL1D_TRC_TPC_MMTX_SHMDL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B3D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_TAR_GAIN(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1C3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TPC_TAR_GAIN(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_TAR_GAIN_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1C3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_OP_MODE(v1, v2, v3, v4) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_OP_MODE(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TPC_OP_MODE_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_OP_CNT(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1E3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TPC_OP_CNT(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_OP_CNT_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1E3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_ET_DPD_CHECK(v1, v2) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F3D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_ET_DPD_CHECK(v1, v2)
#endif
#define EL1D_TRC_TPC_ET_DPD_CHECK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F3D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_PGA_GAIN_STEP(v1, v2, v3, v4) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x203D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PGA_GAIN_STEP(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TPC_PGA_GAIN_STEP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x203D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TXDFE_FILTER_DELAY(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x213D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TXDFE_FILTER_DELAY(v1, v2, v3)
#endif
#define EL1D_TRC_TXDFE_FILTER_DELAY_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x213D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_CHECK_APC_enable(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x223D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TPC_CHECK_APC_enable(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_CHECK_APC_enable_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x223D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_TEMPE_THD(v1, v2, v3, v4, v5) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x233D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_TPC_TEMPE_THD(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TPC_TEMPE_THD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x233D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_TEMPE_BO(v1, v2) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x243D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TPC_TEMPE_BO(v1, v2)
#endif
#define EL1D_TRC_TPC_TEMPE_BO_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x243D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_PA_Mode_Thd(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x253D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PA_Mode_Thd(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_TPC_PA_Mode_Thd_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x253D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_PA_Vcc_Thd(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x263D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PA_Vcc_Thd(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_TPC_PA_Vcc_Thd_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x263D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_PA_gain_In(v1, v2, v3, v4) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x273D, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PA_gain_In(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TPC_PA_gain_In_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x273D, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_PA_gain_Out(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x283D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PA_gain_Out(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_PA_gain_Out_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x283D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_PA_rel_freq_RB(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x293D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PA_rel_freq_RB(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define EL1D_TRC_TPC_PA_rel_freq_RB_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x293D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_PA_gain_table(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2A3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PA_gain_table(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define EL1D_TRC_TPC_PA_gain_table_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2A3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_PA_slope_seg(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_15_DATA(TRC_MERGE_1S2C(0x2B3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PA_slope_seg(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#endif
#define EL1D_TRC_TPC_PA_slope_seg_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) TRC_SEND_15_DATA(TRC_MERGE_1S2C(0x2B3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_PA_comp_value(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2C3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PA_comp_value(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define EL1D_TRC_TPC_PA_comp_value_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2C3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_PA_comp_slope(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_15_DATA(TRC_MERGE_1S2C(0x2D3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14));\
	} while(0)
#else
	#define EL1D_TRC_TPC_PA_comp_slope(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#endif
#define EL1D_TRC_TPC_PA_comp_slope_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) TRC_SEND_15_DATA(TRC_MERGE_1S2C(0x2D3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_GA_freq_point(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_2S(0x2E3D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11));\
	} while(0)
#else
	#define EL1D_TRC_TPC_GA_freq_point(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_TPC_GA_freq_point_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_11_DATA(TRC_MERGE_2S(0x2E3D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_GA_comp_table(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x2F3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10));\
	} while(0)
#else
	#define EL1D_TRC_TPC_GA_comp_table(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_TPC_GA_comp_table_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_11_DATA(TRC_MERGE_1S2C(0x2F3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_GA_slope(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x303D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_TPC_GA_slope(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_TPC_GA_slope_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_10_DATA(TRC_MERGE_1S2C(0x303D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_GA_Out(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x313D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TPC_GA_Out(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_GA_Out_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x313D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_HRM_STATUS(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x323D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_TPC_HRM_STATUS(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_HRM_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x323D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_FILTER_PATH_SWITCH(v1, v2) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x333D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_FILTER_PATH_SWITCH(v1, v2)
#endif
#define EL1D_TRC_TPC_FILTER_PATH_SWITCH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x333D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_MODE(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x343D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_MODE(v1)
#endif
#define EL1D_TRC_TPC_MODE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x343D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_OP_THD(v1, v2, v3, v4, v5) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x353D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_TPC_OP_THD(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TPC_OP_THD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x353D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_MIPI_TPC_EVT_OFFSET(v1) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x363D, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_TPC_MIPI_TPC_EVT_OFFSET(v1)
#endif
#define EL1D_TRC_TPC_MIPI_TPC_EVT_OFFSET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x363D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_DROP_C2MIRQ_B() do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x373D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_DROP_C2MIRQ_B()
#endif
#define EL1D_TRC_TPC_DROP_C2MIRQ_B_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x373D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TPC_TX_POWER_OFFSET(v1, v2, v3, v4) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x383D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_TX_POWER_OFFSET(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TPC_TX_POWER_OFFSET_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x383D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TPC_ET_GAIN_POUT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x393D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_TPC_ET_GAIN_POUT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_TPC_ET_GAIN_POUT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x393D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_HPUE_DELAY(v1, v2) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A3D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_HPUE_DELAY(v1, v2)
#endif
#define EL1D_TRC_TPC_HPUE_DELAY_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A3D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_HPUE_FUNCTION(v1, v2, v3) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_TPC_HPUE_FUNCTION(v1, v2, v3)
#endif
#define EL1D_TRC_TPC_HPUE_FUNCTION_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_HPUE_MIPI_CW(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3C3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_TPC_HPUE_MIPI_CW(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_TPC_HPUE_MIPI_CW_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3C3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_HPUE_MIPI_EVENT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3D3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_HPUE_MIPI_EVENT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_TPC_HPUE_MIPI_EVENT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3D3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPC_HPUE_MIPI_ALLOC(v1, v2, v3, v4) do {\
		if(EL1D_TPC0_Trace_Filter[0]==1 && (EL1D_TPC0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TPC_HPUE_MIPI_ALLOC(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TPC_HPUE_MIPI_ALLOC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_TPC0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_TPC_CONTEXT_ENTRY(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TPC_SHM_DL_INFO(short v1, unsigned long v2, short v3);
void L1TRC_Send_EL1D_TRC_TPC_REQUEST_INFO(unsigned char v1, short v2, short v3, unsigned long v4, long v5, short v6);
void L1TRC_Send_EL1D_TRC_TPC_OFF_REQUEST_INFO(unsigned char v1, short v2, short v3, short v4, unsigned long v5, long v6, short v7);
void L1TRC_Send_EL1D_TRC_TPC_CANCEL_REQUEST(unsigned long v1, short v2);
void L1TRC_Send_EL1D_TRC_TPC_PUCCH_RB_START(short v1);
void L1TRC_Send_EL1D_TRC_TPC_TIME_CHECK_INFO(short v1, long v2);
void L1TRC_Send_EL1D_TRC_TPC_CHECK_TX_1ST_FLAG(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TPC_NOT_TX_1ST_CNT_DOWN(short v1);
void L1TRC_Send_EL1D_TRC_TPC_LTPC_IRQ_SCH(short v1, long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TPC_LTPC_GDMA_TRIG(short v1);
void L1TRC_Send_EL1D_TRC_TPC_LTPC_C2M_TRIG(void);
void L1TRC_Send_EL1D_TRC_TPC_LTPC_DFE_BUS(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TPC_PGA_AB_G_DIFF(long v1);
void L1TRC_Send_EL1D_TRC_TPC_CAL_DATA_UPDATE(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_TPC_MODE_SEL(short v1, short v2);
void L1TRC_Send_EL1D_TRC_TPC_TX_POUT_TARGET(short v1, short v2);
void L1TRC_Send_EL1D_TRC_TPC_DFESYS_BUS_DBG(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TPC_SINETONE_INPUT(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_TPC_SINETONE_OUTPUT(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_TPC_SINETONE_TEST(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_TPC_ALGO_TEST1(short v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TPC_ALGO_TEST2(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TPC_ALGO_TEST3(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_TPC_PGA_DNL(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TPC_GAIN_ASYM_CAL(short v1, short v2, long v3, short v4);
void L1TRC_Send_EL1D_TRC_TPC_GA_CMIF(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_TPC_MMTX_SHMDL(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TPC_TAR_GAIN(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TPC_OP_MODE(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_TPC_OP_CNT(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TPC_ET_DPD_CHECK(short v1, short v2);
void L1TRC_Send_EL1D_TRC_TPC_PGA_GAIN_STEP(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_TXDFE_FILTER_DELAY(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TPC_CHECK_APC_enable(short v1, short v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TPC_TEMPE_THD(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_TPC_TEMPE_BO(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TPC_PA_Mode_Thd(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1D_TRC_TPC_PA_Vcc_Thd(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1D_TRC_TPC_PA_gain_In(short v1, unsigned long v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_TPC_PA_gain_Out(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TPC_PA_rel_freq_RB(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15);
void L1TRC_Send_EL1D_TRC_TPC_PA_gain_table(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15);
void L1TRC_Send_EL1D_TRC_TPC_PA_slope_seg(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14);
void L1TRC_Send_EL1D_TRC_TPC_PA_comp_value(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15);
void L1TRC_Send_EL1D_TRC_TPC_PA_comp_slope(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14);
void L1TRC_Send_EL1D_TRC_TPC_GA_freq_point(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11);
void L1TRC_Send_EL1D_TRC_TPC_GA_comp_table(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10);
void L1TRC_Send_EL1D_TRC_TPC_GA_slope(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1D_TRC_TPC_GA_Out(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TPC_HRM_STATUS(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_TPC_FILTER_PATH_SWITCH(short v1, short v2);
void L1TRC_Send_EL1D_TRC_TPC_MODE(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TPC_OP_THD(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_TPC_MIPI_TPC_EVT_OFFSET(short v1);
void L1TRC_Send_EL1D_TRC_TPC_DROP_C2MIRQ_B(void);
void L1TRC_Send_EL1D_TRC_TPC_TX_POWER_OFFSET(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_TPC_ET_GAIN_POUT(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_TPC_HPUE_DELAY(short v1, short v2);
void L1TRC_Send_EL1D_TRC_TPC_HPUE_FUNCTION(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_TPC_HPUE_MIPI_CW(short v1, short v2, short v3, short v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_TPC_HPUE_MIPI_EVENT(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_EL1D_TRC_TPC_HPUE_MIPI_ALLOC(short v1, short v2, short v3, short v4);

void Set_EL1D_TPC0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_TPC0()	(EL1D_TPC0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()	(ChkL1ModFltr_EL1D_TPC0()&&((EL1D_TPC0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()	(ChkL1ModFltr_EL1D_TPC0()&&((EL1D_TPC0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()	(ChkL1ModFltr_EL1D_TPC0()&&((EL1D_TPC0_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_TPC_CONTEXT_ENTRY()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_SHM_DL_INFO()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_REQUEST_INFO()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_OFF_REQUEST_INFO()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_CANCEL_REQUEST()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PUCCH_RB_START()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_TIME_CHECK_INFO()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_CHECK_TX_1ST_FLAG()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_NOT_TX_1ST_CNT_DOWN()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_LTPC_IRQ_SCH()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_LTPC_GDMA_TRIG()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_LTPC_C2M_TRIG()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_LTPC_DFE_BUS()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PGA_AB_G_DIFF()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_CAL_DATA_UPDATE()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_MODE_SEL()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_TX_POUT_TARGET()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_DFESYS_BUS_DBG()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_SINETONE_INPUT()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_SINETONE_OUTPUT()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_SINETONE_TEST()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_ALGO_TEST1()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_ALGO_TEST2()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_ALGO_TEST3()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PGA_DNL()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_GAIN_ASYM_CAL()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_GA_CMIF()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_MMTX_SHMDL()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_TAR_GAIN()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_OP_MODE()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_OP_CNT()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_ET_DPD_CHECK()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PGA_GAIN_STEP()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TXDFE_FILTER_DELAY()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_CHECK_APC_enable()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_TEMPE_THD()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_TEMPE_BO()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PA_Mode_Thd()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PA_Vcc_Thd()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PA_gain_In()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PA_gain_Out()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PA_rel_freq_RB()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PA_gain_table()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PA_slope_seg()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PA_comp_value()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_PA_comp_slope()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_GA_freq_point()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_GA_comp_table()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_GA_slope()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_GA_Out()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_HRM_STATUS()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_FILTER_PATH_SWITCH()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_MODE()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_OP_THD()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_MIPI_TPC_EVT_OFFSET()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_DROP_C2MIRQ_B()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_TX_POWER_OFFSET()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_M()
#define ChkL1MsgFltr_EL1D_TRC_TPC_ET_GAIN_POUT()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_L()
#define ChkL1MsgFltr_EL1D_TRC_TPC_HPUE_DELAY()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_HPUE_FUNCTION()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_HPUE_MIPI_CW()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_HPUE_MIPI_EVENT()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()
#define ChkL1MsgFltr_EL1D_TRC_TPC_HPUE_MIPI_ALLOC()	ChkL1ClsFltr_EL1D_TPC0_EL1D_TRC_CLS_TPC_H()


#endif
