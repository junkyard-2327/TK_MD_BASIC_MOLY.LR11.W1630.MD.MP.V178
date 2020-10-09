#ifndef L1TRC_EL1D_COMMON1_DEF_H
#define L1TRC_EL1D_COMMON1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_AFIFO_PATH(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_AFIFO_USER(v1)  (unsigned char)(v1+5)
#define EL1D_TRC_AFIFO_COMMAND(v1)  (unsigned char)(v1+9)
#define EL1D_TRC_AFIFO_CSCM_PATH(v1)  (unsigned char)(v1+11)
#define EL1D_TRC_AFIFO_CSCM_COMMAND(v1)  (unsigned char)(v1+14)
#define EL1D_TRC_AFIFO_CSCM_ANT(v1)  (unsigned char)(v1+16)
#define EL1D_TRC_RXDMP_HW(v1)  (unsigned char)(v1+19)
#define EL1D_TRC_RXDMP_USER(v1)  (unsigned char)(v1+24)
#define EL1D_TRC_RXTDB_SRAM_CM_COMMAND(v1)  (unsigned char)(v1+28)
#define EL1D_TRC_RXTDB_SRAM_RX_COMMAND(v1)  (unsigned char)(v1+31)
#define EL1D_TRC_CAM_STATE(v1)  (unsigned char)(v1+33)
#define EL1D_TRC_TPPA_L1MOD_IDX(v1)  (unsigned char)(v1+36)
#define EL1D_TRC_TPPA_DSP_IDX(v1)  (unsigned char)(v1+42)
#define EL1D_TRC_RX_INJECT_STR(v1)  (unsigned char)(v1+47)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_AFIFO_CONTROL(v1, v2, v3) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0032, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_AFIFO_CONTROL(v1, v2, v3)
#endif
#define EL1D_TRC_AFIFO_CONTROL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0032, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AFIFO_CONTROL_IMM(v1, v2) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0132, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_AFIFO_CONTROL_IMM(v1, v2)
#endif
#define EL1D_TRC_AFIFO_CONTROL_IMM_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0132, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_AFIFO_REQ(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0232, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_AFIFO_REQ(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_AFIFO_REQ_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0232, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AFIFO_CSCM_CONTROL(v1, v2, v3, v4) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0332, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_AFIFO_CSCM_CONTROL(v1, v2, v3, v4)
#endif
#define EL1D_TRC_AFIFO_CSCM_CONTROL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0332, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_AFIFO_CSCM_REQ(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0432, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_AFIFO_CSCM_REQ(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_AFIFO_CSCM_REQ_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0432, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1D_TRC_AFIFO_CSCM_EVENT1(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0532, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_AFIFO_CSCM_EVENT1(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_AFIFO_CSCM_EVENT1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0532, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDMP_AFIFO_STS_DBG(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0632, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXDMP_AFIFO_STS_DBG(v1)
#endif
#define EL1D_TRC_RXDMP_AFIFO_STS_DBG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0632, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDMP_IRQ(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0732, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_RXDMP_IRQ(v1)
#endif
#define EL1D_TRC_RXDMP_IRQ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0732, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDMP_START(v1, v2, v3, v4) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0832, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RXDMP_START(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RXDMP_START_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0832, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDMP_ABORT(v1, v2) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0932, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RXDMP_ABORT(v1, v2)
#endif
#define EL1D_TRC_RXDMP_ABORT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0932, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXDMP_SRAM(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A32, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXDMP_SRAM(v1)
#endif
#define EL1D_TRC_RXDMP_SRAM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A32, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDMP_RX_SWITCH_CON(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B32, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXDMP_RX_SWITCH_CON(v1)
#endif
#define EL1D_TRC_RXDMP_RX_SWITCH_CON_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B32, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDMP_RX_SWITCH_SET(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C32, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXDMP_RX_SWITCH_SET(v1)
#endif
#define EL1D_TRC_RXDMP_RX_SWITCH_SET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C32, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXDMP_Fail(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D32, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RXDMP_Fail(v1)
#endif
#define EL1D_TRC_RXDMP_Fail_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D32, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXTDB_SRAM(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E32, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RXTDB_SRAM(v1)
#endif
#define EL1D_TRC_RXTDB_SRAM_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E32, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXTDB_RX_SWITCH(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F32, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXTDB_RX_SWITCH(v1)
#endif
#define EL1D_TRC_RXTDB_RX_SWITCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F32, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RXTDB_SWAP_STS(v1, v2) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1032, (char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RXTDB_SWAP_STS(v1, v2)
#endif
#define EL1D_TRC_RXTDB_SWAP_STS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1032, (char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXTDB_SRAM_CM_ON_REQ(v1, v2) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1132, (char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RXTDB_SRAM_CM_ON_REQ(v1, v2)
#endif
#define EL1D_TRC_RXTDB_SRAM_CM_ON_REQ_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1132, (char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXTDB_SRAM_CM_OFF_REQ(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1232, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RXTDB_SRAM_CM_OFF_REQ(v1)
#endif
#define EL1D_TRC_RXTDB_SRAM_CM_OFF_REQ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1232, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RXTDB_SRAM_RX_REQ(v1, v2) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1332, (char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RXTDB_SRAM_RX_REQ(v1, v2)
#endif
#define EL1D_TRC_RXTDB_SRAM_RX_REQ_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1332, (char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LCAM_STATE_CHANGE(v1, v2) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1432, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_LCAM_STATE_CHANGE(v1, v2)
#endif
#define EL1D_TRC_LCAM_STATE_CHANGE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1432, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LCAM_INTERRUPTION(v1, v2) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1532, (short)(v2)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_LCAM_INTERRUPTION(v1, v2)
#endif
#define EL1D_TRC_LCAM_INTERRUPTION_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1532, (short)(v2)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LCAM_CA_PARA(v1, v2, v3, v4) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1632, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LCAM_CA_PARA(v1, v2, v3, v4)
#endif
#define EL1D_TRC_LCAM_CA_PARA_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1632, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LCAM_RF_SWITCH(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1732, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LCAM_RF_SWITCH(v1)
#endif
#define EL1D_TRC_LCAM_RF_SWITCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1732, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LCAM_DCTG_SOL(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1832, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LCAM_DCTG_SOL(v1)
#endif
#define EL1D_TRC_LCAM_DCTG_SOL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1832, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LCAM_DCTG_SOL_CHG_NOTIFY() do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1932, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LCAM_DCTG_SOL_CHG_NOTIFY()
#endif
#define EL1D_TRC_LCAM_DCTG_SOL_CHG_NOTIFY_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1932, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LCAM_SCC_STATUS(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A32, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LCAM_SCC_STATUS(v1)
#endif
#define EL1D_TRC_LCAM_SCC_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A32, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LCAM_SCC_RF_PATH(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B32, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LCAM_SCC_RF_PATH(v1)
#endif
#define EL1D_TRC_LCAM_SCC_RF_PATH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B32, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_PCC_LOG_DFE(v1, v2, v3, v4) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C32, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_PCC_LOG_DFE(v1, v2, v3, v4)
#endif
#define EL1D_TRC_PCC_LOG_DFE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C32, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_RX_INJECT_STRING(v1, v2) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D32, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_RX_INJECT_STRING(v1, v2)
#endif
#define EL1D_TRC_RX_INJECT_STRING_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D32, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TPPA_L1MOD_DSP(v1, v2, v3) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E32, (unsigned char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TPPA_L1MOD_DSP(v1, v2, v3)
#endif
#define EL1D_TRC_TPPA_L1MOD_DSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E32, (unsigned char)(v2), (char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_NVRAM_ERROR_CHECK() do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F32, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_NVRAM_ERROR_CHECK()
#endif
#define EL1D_TRC_NVRAM_ERROR_CHECK_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F32, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_32K_LESS_DBG(v1) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2032, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_DBG(v1)
#endif
#define EL1D_TRC_32K_LESS_DBG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2032, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_ELP_LOADING(v1, v2) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2132, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_ELP_LOADING(v1, v2)
#endif
#define EL1D_TRC_ELP_LOADING_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2132, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_CAL_PAGING_CHK(v1, v2, v3, v4) do {\
		if(EL1D_COMMON1_Trace_Filter[0]==1 && (EL1D_COMMON1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2232, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_PAGING_CHK(v1, v2, v3, v4)
#endif
#define EL1D_TRC_32K_CAL_PAGING_CHK_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2232, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_COMMON1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_AFIFO_CONTROL(unsigned char v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_AFIFO_CONTROL_IMM(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_AFIFO_REQ(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_AFIFO_CSCM_CONTROL(unsigned char v1, unsigned char v2, short v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_AFIFO_CSCM_REQ(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned char v5, unsigned short v6, unsigned long v7);
void L1TRC_Send_EL1D_TRC_AFIFO_CSCM_EVENT1(unsigned char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_RXDMP_AFIFO_STS_DBG(unsigned char v1);
void L1TRC_Send_EL1D_TRC_RXDMP_IRQ(unsigned short v1);
void L1TRC_Send_EL1D_TRC_RXDMP_START(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RXDMP_ABORT(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RXDMP_SRAM(char v1);
void L1TRC_Send_EL1D_TRC_RXDMP_RX_SWITCH_CON(char v1);
void L1TRC_Send_EL1D_TRC_RXDMP_RX_SWITCH_SET(char v1);
void L1TRC_Send_EL1D_TRC_RXDMP_Fail(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RXTDB_SRAM(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RXTDB_RX_SWITCH(char v1);
void L1TRC_Send_EL1D_TRC_RXTDB_SWAP_STS(char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RXTDB_SRAM_CM_ON_REQ(char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_RXTDB_SRAM_CM_OFF_REQ(char v1);
void L1TRC_Send_EL1D_TRC_RXTDB_SRAM_RX_REQ(char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_LCAM_STATE_CHANGE(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_LCAM_INTERRUPTION(unsigned long v1, short v2);
void L1TRC_Send_EL1D_TRC_LCAM_CA_PARA(char v1, char v2, char v3, char v4);
void L1TRC_Send_EL1D_TRC_LCAM_RF_SWITCH(unsigned char v1);
void L1TRC_Send_EL1D_TRC_LCAM_DCTG_SOL(char v1);
void L1TRC_Send_EL1D_TRC_LCAM_DCTG_SOL_CHG_NOTIFY(void);
void L1TRC_Send_EL1D_TRC_LCAM_SCC_STATUS(char v1);
void L1TRC_Send_EL1D_TRC_LCAM_SCC_RF_PATH(char v1);
void L1TRC_Send_EL1D_TRC_PCC_LOG_DFE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RX_INJECT_STRING(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TPPA_L1MOD_DSP(unsigned long v1, unsigned char v2, char v3);
void L1TRC_Send_EL1D_TRC_NVRAM_ERROR_CHECK(void);
void L1TRC_Send_EL1D_TRC_32K_LESS_DBG(short v1);
void L1TRC_Send_EL1D_TRC_ELP_LOADING(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_32K_CAL_PAGING_CHK(short v1, short v2, short v3, short v4);

void Set_EL1D_COMMON1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_COMMON1()	(EL1D_COMMON1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()	(ChkL1ModFltr_EL1D_COMMON1()&&((EL1D_COMMON1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_M()	(ChkL1ModFltr_EL1D_COMMON1()&&((EL1D_COMMON1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_L()	(ChkL1ModFltr_EL1D_COMMON1()&&((EL1D_COMMON1_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_AFIFO_CONTROL()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_AFIFO_CONTROL_IMM()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_AFIFO_REQ()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_M()
#define ChkL1MsgFltr_EL1D_TRC_AFIFO_CSCM_CONTROL()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_AFIFO_CSCM_REQ()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_M()
#define ChkL1MsgFltr_EL1D_TRC_AFIFO_CSCM_EVENT1()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDMP_AFIFO_STS_DBG()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDMP_IRQ()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDMP_START()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDMP_ABORT()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDMP_SRAM()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_L()
#define ChkL1MsgFltr_EL1D_TRC_RXDMP_RX_SWITCH_CON()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDMP_RX_SWITCH_SET()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXDMP_Fail()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXTDB_SRAM()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXTDB_RX_SWITCH()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXTDB_SWAP_STS()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RXTDB_SRAM_CM_ON_REQ()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_L()
#define ChkL1MsgFltr_EL1D_TRC_RXTDB_SRAM_CM_OFF_REQ()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_L()
#define ChkL1MsgFltr_EL1D_TRC_RXTDB_SRAM_RX_REQ()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_L()
#define ChkL1MsgFltr_EL1D_TRC_LCAM_STATE_CHANGE()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_LCAM_INTERRUPTION()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_LCAM_CA_PARA()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_LCAM_RF_SWITCH()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_LCAM_DCTG_SOL()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_LCAM_DCTG_SOL_CHG_NOTIFY()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_LCAM_SCC_STATUS()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_LCAM_SCC_RF_PATH()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_PCC_LOG_DFE()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_RX_INJECT_STRING()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_TPPA_L1MOD_DSP()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_NVRAM_ERROR_CHECK()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_DBG()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_L()
#define ChkL1MsgFltr_EL1D_TRC_ELP_LOADING()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_PAGING_CHK()	ChkL1ClsFltr_EL1D_COMMON1_EL1D_TRC_CLS_COMMON1_H()


#endif
