#ifndef L1TRC_EL1_TSTM_1_DEF_H
#define L1TRC_EL1_TSTM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define TSTM_Func_String(v1)  (unsigned char)(v1+0)
#define TSTM_Func_String_Dummy_Emac(v1)  (unsigned char)(v1+50)
#define TSTM_Main_St_String(v1)  (unsigned char)(v1+68)
#define TSTM_DL_Rx_St_String(v1)  (unsigned char)(v1+77)
#define TSTM_UL_Tx_St_String(v1)  (unsigned char)(v1+81)
#define TSTM_Tx_Rx_St_String(v1)  (unsigned char)(v1+85)
#define TSTM_Ps_Tx_Rx_St_String(v1)  (unsigned char)(v1+89)
#define TSTM_DL_Cs_St_String(v1)  (unsigned char)(v1+93)
#define TSTM_Rx_Fsm_St_String(v1)  (unsigned char)(v1+98)
#define TSTM_Reset_Tstm_St_String(v1)  (unsigned char)(v1+103)
#define TSTM_MB_MIB_DC_St_String(v1)  (unsigned char)(v1+112)
#define TSTM_Nrml_MIB_DC_St_String(v1)  (unsigned char)(v1+117)
#define TSTM_SI_DC_St_String(v1)  (unsigned char)(v1+123)
#define TSTM_DL_CS_Sub_St_String(v1)  (unsigned char)(v1+129)
#define TSTM_Error_St_String(v1)  (unsigned char)(v1+137)
#define TSTM_Rx_Fsm_Mod_String(v1)  (unsigned char)(v1+155)
#define TSTM_Pcell_St_String(v1)  (unsigned char)(v1+167)
#define TSTM_Scell_St_String(v1)  (unsigned char)(v1+188)
#define TSTM_Nbr_Cmd_Type_String(v1)  (unsigned char)(v1+200)
#define TSTM_Nbr_Cell_String(v1)  (unsigned char)(v1+205)
#define TSTM_Nbr_Mode_String(v1)  (unsigned char)(v1+210)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_FUNC_ENTRY(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0008, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_FUNC_ENTRY(v1)
#endif
#define TSTM_LOG_FUNC_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0008, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SYS_TIME(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0108, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v5));\
	} while(0)
#else
	#define TSTM_LOG_SYS_TIME(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_SYS_TIME_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0108, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_MAIN_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0208, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_MAIN_ST(v1)
#endif
#define TSTM_LOG_MAIN_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0208, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NEXT_MAIN_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0308, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_NEXT_MAIN_ST(v1)
#endif
#define TSTM_LOG_NEXT_MAIN_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0308, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DL_RX_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0408, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DL_RX_ST(v1)
#endif
#define TSTM_LOG_DL_RX_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0408, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_UL_TX_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0508, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_UL_TX_ST(v1)
#endif
#define TSTM_LOG_UL_TX_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0508, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DL_CS_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0608, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DL_CS_ST(v1)
#endif
#define TSTM_LOG_DL_CS_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0608, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_TX_RX_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0708, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_TX_RX_ST(v1)
#endif
#define TSTM_LOG_TX_RX_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0708, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_PS_TX_RX_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0808, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_PS_TX_RX_ST(v1)
#endif
#define TSTM_LOG_PS_TX_RX_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0808, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RX_FSM_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0908, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_RX_FSM_ST(v1)
#endif
#define TSTM_LOG_RX_FSM_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0908, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RESET_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A08, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_RESET_ST(v1)
#endif
#define TSTM_LOG_RESET_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A08, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_MB_MIB_DC_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B08, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_MB_MIB_DC_ST(v1)
#endif
#define TSTM_LOG_MB_MIB_DC_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B08, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NRML_MIB_DC_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C08, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_NRML_MIB_DC_ST(v1)
#endif
#define TSTM_LOG_NRML_MIB_DC_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C08, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SI_DC_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D08, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SI_DC_ST(v1)
#endif
#define TSTM_LOG_SI_DC_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D08, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_PCELL_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E08, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_PCELL_ST(v1)
#endif
#define TSTM_LOG_PCELL_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E08, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SCELL_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F08, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SCELL_ST(v1)
#endif
#define TSTM_LOG_SCELL_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F08, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RX_FSM_MOD(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1008, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_RX_FSM_MOD(v1, v2, v3)
#endif
#define TSTM_LOG_RX_FSM_MOD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1008, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_JUMP_MOD(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1108, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_JUMP_MOD(v1, v2)
#endif
#define TSTM_LOG_JUMP_MOD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1108, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_ERR_ST(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1208, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_ERR_ST(v1)
#endif
#define TSTM_LOG_ERR_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1208, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_WAIT_ABORT_DONE_BMP(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1308, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_WAIT_ABORT_DONE_BMP(v1)
#endif
#define TSTM_LOG_WAIT_ABORT_DONE_BMP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1308, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_WAIT_EXE_DONE_BMP(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1408, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_WAIT_EXE_DONE_BMP(v1)
#endif
#define TSTM_LOG_WAIT_EXE_DONE_BMP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1408, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_MBSFN_CMD(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1508, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_MBSFN_CMD(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_MBSFN_CMD_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1508, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_EN_CNF_SEND() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1608, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_EN_CNF_SEND()
#endif
#define TSTM_LOG_EN_CNF_SEND_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1608, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_ABORT_RPT() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1708, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_ABORT_RPT()
#endif
#define TSTM_LOG_ABORT_RPT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1708, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_PHY_CONFIG(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1808, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_SET_PHY_CONFIG(v1, v2, v3)
#endif
#define TSTM_LOG_SET_PHY_CONFIG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1808, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_CH_CONFIG(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1908, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_CH_CONFIG(v1, v2, v3, v4)
#endif
#define TSTM_LOG_SET_CH_CONFIG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1908, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_COMM_CONFIG(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_COMM_CONFIG(v1, v2, v3, v4)
#endif
#define TSTM_LOG_SET_COMM_CONFIG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_CELL_DEL_CONFIG(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_CELL_DEL_CONFIG(v1, v2, v3, v4)
#endif
#define TSTM_LOG_SET_CELL_DEL_CONFIG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_CSCSR_CMD() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_CSCSR_CMD()
#endif
#define TSTM_LOG_SET_CSCSR_CMD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_CSCD_CMD() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_CSCD_CMD()
#endif
#define TSTM_LOG_SET_CSCD_CMD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_CSM_CMD() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_CSM_CMD()
#endif
#define TSTM_LOG_SET_CSM_CMD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_MEAS_CMD() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_MEAS_CMD()
#endif
#define TSTM_LOG_SET_MEAS_CMD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_CSCONT_CMD() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2008, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_CSCONT_CMD()
#endif
#define TSTM_LOG_SET_CSCONT_CMD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2008, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_PRE_SYNC_CMD() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2108, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_PRE_SYNC_CMD()
#endif
#define TSTM_LOG_SET_PRE_SYNC_CMD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2108, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_AFC_DAC_CMD(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2208, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_AFC_DAC_CMD(v1, v2)
#endif
#define TSTM_LOG_SET_AFC_DAC_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2208, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_TA_CMD(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2308, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_SET_TA_CMD(v1)
#endif
#define TSTM_LOG_SET_TA_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2308, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_FBD(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2408, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_SET_FBD(v1, v2, v3)
#endif
#define TSTM_LOG_SET_FBD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2408, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_FREQ_BIN(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2508, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_FREQ_BIN(v1, v2)
#endif
#define TSTM_LOG_SET_FREQ_BIN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2508, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_ADD_MEAS_TBL_CELL(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2608, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_ADD_MEAS_TBL_CELL(v1, v2, v3)
#endif
#define TSTM_LOG_ADD_MEAS_TBL_CELL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2608, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DEL_MEAS_TBL_CELL(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2708, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_DEL_MEAS_TBL_CELL(v1, v2, v3)
#endif
#define TSTM_LOG_DEL_MEAS_TBL_CELL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2708, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_ADD_SRV_CELL(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2808, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_ADD_SRV_CELL(v1, v2, v3, v4)
#endif
#define TSTM_LOG_ADD_SRV_CELL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2808, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_ADD_FAKE_CELL(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2908, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_ADD_FAKE_CELL(v1, v2, v3)
#endif
#define TSTM_LOG_ADD_FAKE_CELL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2908, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_FAKE_CELL_DETECT_RLT(v1, v2, v3, v4, v5) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define TSTM_LOG_FAKE_CELL_DETECT_RLT(v1, v2, v3, v4, v5)
#endif
#define TSTM_LOG_FAKE_CELL_DETECT_RLT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CS_PARAM_1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2B08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_CS_PARAM_1(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_CS_PARAM_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2B08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CS_PARAM_2(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2C08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_CS_PARAM_2(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_CS_PARAM_2_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2C08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CS_PARAM_3(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_CS_PARAM_3(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_CS_PARAM_3_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NBR_CM_RPT_RCV(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_NBR_CM_RPT_RCV(v1)
#endif
#define TSTM_LOG_NBR_CM_RPT_RCV_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SIC_PARAM(v1, v2, v3, v4, v5) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define TSTM_LOG_SIC_PARAM(v1, v2, v3, v4, v5)
#endif
#define TSTM_LOG_SIC_PARAM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_MEAS_PARAM_1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3008, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v2), (unsigned char)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_MEAS_PARAM_1(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_MEAS_PARAM_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3008, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v2), (unsigned char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_MEAS_PARAM_2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3108, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v6)));\
	} while(0)
#else
	#define TSTM_LOG_MEAS_PARAM_2(v1, v2, v3, v4, v5, v6, v7)
#endif
#define TSTM_LOG_MEAS_PARAM_2_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3108, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_MEAS_PARAM_3(v1, v2, v3, v4, v5) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3208, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_MEAS_PARAM_3(v1, v2, v3, v4, v5)
#endif
#define TSTM_LOG_MEAS_PARAM_3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3208, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_PWRSCN_CMD(v1, v2, v3, v4, v5) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3308, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define TSTM_LOG_SET_PWRSCN_CMD(v1, v2, v3, v4, v5)
#endif
#define TSTM_LOG_SET_PWRSCN_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3308, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_PCELL_RNTI_EN(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3408, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_PCELL_RNTI_EN(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define TSTM_LOG_PCELL_RNTI_EN_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3408, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SCELL_RNTI_EN(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3508, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SCELL_RNTI_EN(v1)
#endif
#define TSTM_LOG_SCELL_RNTI_EN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3508, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RNTI_BMP(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3608, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_RNTI_BMP(v1, v2)
#endif
#define TSTM_LOG_RNTI_BMP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3608, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_MBMS_BMP(v1, v2, v3, v4, v5) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3708, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define TSTM_LOG_MBMS_BMP(v1, v2, v3, v4, v5)
#endif
#define TSTM_LOG_MBMS_BMP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3708, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_MBMS_CTRL_EN_BMP(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3808, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_MBMS_CTRL_EN_BMP(v1, v2, v3, v4)
#endif
#define TSTM_LOG_MBMS_CTRL_EN_BMP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3808, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_MBMS_CTRL_DIS_BMP(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3908, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_MBMS_CTRL_DIS_BMP(v1, v2, v3, v4)
#endif
#define TSTM_LOG_MBMS_CTRL_DIS_BMP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3908, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_DL_CHNG() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_DL_CHNG()
#endif
#define TSTM_LOG_SET_DL_CHNG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DL_CHNG_PCELL_PARAM(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3B08, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DL_CHNG_PCELL_PARAM(v1, v2, v3, v4, v5, v6, v7)
#endif
#define TSTM_LOG_DL_CHNG_PCELL_PARAM_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3B08, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DL_CHNG_SCELL_PARAM_1(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C08, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DL_CHNG_SCELL_PARAM_1(v1, v2, v3, v4)
#endif
#define TSTM_LOG_DL_CHNG_SCELL_PARAM_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C08, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DL_CHNG_SCELL_PARAM_2(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DL_CHNG_SCELL_PARAM_2(v1, v2, v3, v4)
#endif
#define TSTM_LOG_DL_CHNG_SCELL_PARAM_2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_ST_MEAS_RLT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E08, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define TSTM_LOG_ST_MEAS_RLT(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_ST_MEAS_RLT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E08, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_PWR_SCN_RLT(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F08, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_PWR_SCN_RLT(v1, v2)
#endif
#define TSTM_LOG_PWR_SCN_RLT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F08, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_PHICH_PARAM_1(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4008, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_PHICH_PARAM_1(v1, v2, v3)
#endif
#define TSTM_LOG_PHICH_PARAM_1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4008, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_PHICH_PARAM_2(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4108, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define TSTM_LOG_PHICH_PARAM_2(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_PHICH_PARAM_2_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4108, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_PHICH_PARAM_3(v1, v2, v3, v4, v5) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4208, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_PHICH_PARAM_3(v1, v2, v3, v4, v5)
#endif
#define TSTM_LOG_PHICH_PARAM_3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4208, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_PHICH_REC_INDX(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4308, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_PHICH_REC_INDX(v1)
#endif
#define TSTM_LOG_PHICH_REC_INDX_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4308, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_PRE_SYNC_PARAM_1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4408, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define TSTM_LOG_PRE_SYNC_PARAM_1(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_PRE_SYNC_PARAM_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4408, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_PRE_SYNC_PARAM_2(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4508, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_PRE_SYNC_PARAM_2(v1, v2, v3, v4)
#endif
#define TSTM_LOG_PRE_SYNC_PARAM_2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4508, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_OTHER_CNT_1(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4608, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_CQI_OTHER_CNT_1(v1)
#endif
#define TSTM_LOG_CQI_OTHER_CNT_1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4608, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_OTHER_SET2_CNT_1(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4708, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_CQI_OTHER_SET2_CNT_1(v1)
#endif
#define TSTM_LOG_CQI_OTHER_SET2_CNT_1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4708, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_OTHER_CNT_2(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4808, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_CQI_OTHER_CNT_2(v1)
#endif
#define TSTM_LOG_CQI_OTHER_CNT_2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4808, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_OTHER_CNT_3(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4908, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_CQI_OTHER_CNT_3(v1)
#endif
#define TSTM_LOG_CQI_OTHER_CNT_3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4908, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_OTHER_SET2_CNT_3(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4A08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_CQI_OTHER_SET2_CNT_3(v1)
#endif
#define TSTM_LOG_CQI_OTHER_SET2_CNT_3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4A08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_OTHER_CNT_4(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4B08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_CQI_OTHER_CNT_4(v1)
#endif
#define TSTM_LOG_CQI_OTHER_CNT_4_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4B08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_OTHER_CNT_5(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4C08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_CQI_OTHER_CNT_5(v1)
#endif
#define TSTM_LOG_CQI_OTHER_CNT_5_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4C08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_OTHER_SET2_CNT_5(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4D08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_CQI_OTHER_SET2_CNT_5(v1)
#endif
#define TSTM_LOG_CQI_OTHER_SET2_CNT_5_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4D08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_OTHER_CNT_6(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4E08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_CQI_OTHER_CNT_6(v1)
#endif
#define TSTM_LOG_CQI_OTHER_CNT_6_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4E08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_OTHER_CNT_7(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4F08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_CQI_OTHER_CNT_7(v1)
#endif
#define TSTM_LOG_CQI_OTHER_CNT_7_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4F08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_PTI_CNT(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5008, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_CQI_PTI_CNT(v1, v2)
#endif
#define TSTM_LOG_CQI_PTI_CNT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5008, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_PTI_SET2_CNT(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5108, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_CQI_PTI_SET2_CNT(v1, v2)
#endif
#define TSTM_LOG_CQI_PTI_SET2_CNT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5108, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_RANK_CNT(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5208, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_CQI_RANK_CNT(v1, v2, v3, v4)
#endif
#define TSTM_LOG_CQI_RANK_CNT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5208, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CQI_RANK_SET2_CNT(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5308, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_CQI_RANK_SET2_CNT(v1, v2, v3, v4)
#endif
#define TSTM_LOG_CQI_RANK_SET2_CNT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5308, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_EARFCN_TO_FREQ(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5408, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_EARFCN_TO_FREQ(v1, v2, v3)
#endif
#define TSTM_LOG_EARFCN_TO_FREQ_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5408, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_FREQ_TO_EARFCN(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5508, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_FREQ_TO_EARFCN(v1, v2, v3)
#endif
#define TSTM_LOG_FREQ_TO_EARFCN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5508, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_MIB_CRC_RLT(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5608, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_MIB_CRC_RLT(v1)
#endif
#define TSTM_LOG_MIB_CRC_RLT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5608, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_MBMS_EN(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5708, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_MBMS_EN(v1)
#endif
#define TSTM_LOG_SET_MBMS_EN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5708, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RX_CTRL_TIMING_RNTI(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5808, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TSTM_LOG_RX_CTRL_TIMING_RNTI(v1, v2, v3, v4)
#endif
#define TSTM_LOG_RX_CTRL_TIMING_RNTI_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5808, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RX_CTRL_TIMING_POST_RS(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5908, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TSTM_LOG_RX_CTRL_TIMING_POST_RS(v1, v2, v3, v4)
#endif
#define TSTM_LOG_RX_CTRL_TIMING_POST_RS_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5908, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RX_CTRL_TIMING_PRE_SYNC(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5A08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TSTM_LOG_RX_CTRL_TIMING_PRE_SYNC(v1, v2, v3, v4)
#endif
#define TSTM_LOG_RX_CTRL_TIMING_PRE_SYNC_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5A08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RX_CTRL_TIMING_MB_EN(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5B08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TSTM_LOG_RX_CTRL_TIMING_MB_EN(v1, v2, v3, v4)
#endif
#define TSTM_LOG_RX_CTRL_TIMING_MB_EN_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5B08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RX_FSM_RX_STRT(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5C08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define TSTM_LOG_RX_FSM_RX_STRT(v1, v2)
#endif
#define TSTM_LOG_RX_FSM_RX_STRT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5C08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SRCH_EXIST_MCS_RCD(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5D08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_SRCH_EXIST_MCS_RCD(v1)
#endif
#define TSTM_LOG_SRCH_EXIST_MCS_RCD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5D08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SI_CAL(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5E08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SI_CAL(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_SI_CAL_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5E08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_UPDT_STRT_TIME_BASE(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5F08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_UPDT_STRT_TIME_BASE(v1)
#endif
#define TSTM_LOG_UPDT_STRT_TIME_BASE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5F08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_TEST_MODE_CFG(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6008, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_TEST_MODE_CFG(v1)
#endif
#define TSTM_LOG_DUMMY_EMAC_TEST_MODE_CFG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6008, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_DELAY_INIT(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6108, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_DELAY_INIT(v1)
#endif
#define TSTM_LOG_DUMMY_EMAC_DELAY_INIT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6108, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_SWO_BIT(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6208, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_SWO_BIT(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_SWO_BIT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6208, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_RX_HT_SUBHDR_INFO(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6308, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_RX_HT_SUBHDR_INFO(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_RX_HT_SUBHDR_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6308, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_RX_SUBHDR_INFO(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6408, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_RX_SUBHDR_INFO(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_RX_SUBHDR_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6408, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_SUBFRM_IND_BMP(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x6508, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_SUBFRM_IND_BMP(v1)
#endif
#define TSTM_LOG_DUMMY_EMAC_SUBFRM_IND_BMP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x6508, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_TX_RESULT_INFO(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6608, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_TX_RESULT_INFO(v1, v2, v3, v4)
#endif
#define TSTM_LOG_DUMMY_EMAC_TX_RESULT_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6608, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_TX_RESULT_INFO_I(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6708, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), (char)(v4)));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_TX_RESULT_INFO_I(v1, v2, v3, v4)
#endif
#define TSTM_LOG_DUMMY_EMAC_TX_RESULT_INFO_I_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6708, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), (char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_PRINT_TIME(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6808, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_PRINT_TIME(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_PRINT_TIME_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6808, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_SF_TYPE_GAP_INFO(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6908, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_SF_TYPE_GAP_INFO(v1, v2, v3)
#endif
#define TSTM_LOG_DUMMY_EMAC_SF_TYPE_GAP_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6908, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_STATUS_BITMAP(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x6A08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_STATUS_BITMAP(v1)
#endif
#define TSTM_LOG_DUMMY_EMAC_STATUS_BITMAP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x6A08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_HARQ_CLOSE(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x6B08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_HARQ_CLOSE(v1)
#endif
#define TSTM_LOG_DUMMY_EMAC_HARQ_CLOSE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x6B08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_RCV_PHICH(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6C08, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_RCV_PHICH(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_RCV_PHICH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6C08, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_TX_GRANT_INFO(v1, v2, v3, v4, v5) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6D08, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_TX_GRANT_INFO(v1, v2, v3, v4, v5)
#endif
#define TSTM_LOG_DUMMY_EMAC_TX_GRANT_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6D08, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_TX_TIME(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6E08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_TX_TIME(v1, v2, v3)
#endif
#define TSTM_LOG_DUMMY_EMAC_TX_TIME_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6E08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_TX_TIMELINE_INFO(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6F08, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_TX_TIMELINE_INFO(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_TX_TIMELINE_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6F08, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_TX_MODE(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7008, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_TX_MODE(v1)
#endif
#define TSTM_LOG_DUMMY_EMAC_TX_MODE_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7008, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_CONFIG(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7108, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_CONFIG(v1, v2, v3)
#endif
#define TSTM_LOG_DUMMY_EMAC_CONFIG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7108, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_SCHED_CONFIG(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7208, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_SCHED_CONFIG(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_SCHED_CONFIG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7208, (unsigned short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_PHY_INFO_TYPE_AND_MIB(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7308, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_PHY_INFO_TYPE_AND_MIB(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_PHY_INFO_TYPE_AND_MIB_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7308, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_PHY_INFO_CONFIG_1(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7408, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_PHY_INFO_CONFIG_1(v1, v2, v3, v4)
#endif
#define TSTM_LOG_DUMMY_EMAC_PHY_INFO_CONFIG_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7408, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_PHY_INFO_CONFIG_2(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7508, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_PHY_INFO_CONFIG_2(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_PHY_INFO_CONFIG_2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7508, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_NDI_NON_TOGGLE_TRICK() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7608, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_NDI_NON_TOGGLE_TRICK()
#endif
#define TSTM_LOG_DUMMY_EMAC_NDI_NON_TOGGLE_TRICK_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7608, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_GET_HARQ_UPD(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7708, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_GET_HARQ_UPD(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_GET_HARQ_UPD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7708, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_RCV_RETX_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7808, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_RCV_RETX_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_DUMMY_EMAC_RCV_RETX_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7808, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_INIT() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7908, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_INIT()
#endif
#define TSTM_LOG_DUMMY_EMAC_INIT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7908, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_TRIGGER_LMAC(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x7A08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_TRIGGER_LMAC(v1)
#endif
#define TSTM_LOG_DUMMY_EMAC_TRIGGER_LMAC_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x7A08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_TTI_BUNDLE_IDX(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7B08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_TTI_BUNDLE_IDX(v1)
#endif
#define TSTM_LOG_DUMMY_EMAC_TTI_BUNDLE_IDX_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7B08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DUMMY_EMAC_PRINT_ADDR(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7C08, (unsigned short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define TSTM_LOG_DUMMY_EMAC_PRINT_ADDR(v1, v2)
#endif
#define TSTM_LOG_DUMMY_EMAC_PRINT_ADDR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7C08, (unsigned short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NBR_TIME_CAL(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7D08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TSTM_LOG_NBR_TIME_CAL(v1, v2, v3, v4)
#endif
#define TSTM_LOG_NBR_TIME_CAL_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x7D08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_NBR_OFFST_GET(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x7E08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define TSTM_LOG_NBR_OFFST_GET(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define TSTM_LOG_NBR_OFFST_GET_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x7E08, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_RX_RLM(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x7F08, (short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_RX_RLM(v1)
#endif
#define TSTM_LOG_RX_RLM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x7F08, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_FULL_MEAS_ONE_ROUND_FIN() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8008, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_FULL_MEAS_ONE_ROUND_FIN()
#endif
#define TSTM_LOG_FULL_MEAS_ONE_ROUND_FIN_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8008, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CSI_RPT_RAW_1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x8108, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define TSTM_LOG_CSI_RPT_RAW_1(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_CSI_RPT_RAW_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x8108, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CSI_RPT_RAW_2(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x8208, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define TSTM_LOG_CSI_RPT_RAW_2(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_CSI_RPT_RAW_2_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x8208, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_CSI_RPT_MODE(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8308, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_CSI_RPT_MODE(v1, v2)
#endif
#define TSTM_LOG_CSI_RPT_MODE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8308, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SOFT_COMB(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8408, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SOFT_COMB(v1, v2)
#endif
#define TSTM_LOG_SOFT_COMB_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8408, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DEBUG_1(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8508, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define TSTM_LOG_DEBUG_1(v1)
#endif
#define TSTM_LOG_DEBUG_1_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8508, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_DEBUG_6(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x8608, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define TSTM_LOG_DEBUG_6(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_DEBUG_6_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x8608, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_FORCE_TX_NOT_IN_FLIGHT() do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8708, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_FORCE_TX_NOT_IN_FLIGHT()
#endif
#define TSTM_LOG_FORCE_TX_NOT_IN_FLIGHT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8708, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_FORCE_TX_CMD(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8808, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_FORCE_TX_CMD(v1)
#endif
#define TSTM_LOG_FORCE_TX_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8808, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_FORCE_TX_PARA_1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8908, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_FORCE_TX_PARA_1(v1, v2, v3, v4, v5, v6)
#endif
#define TSTM_LOG_FORCE_TX_PARA_1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8908, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_FORCE_TX_PARA_2(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8A08, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_FORCE_TX_PARA_2(v1, v2, v3, v4)
#endif
#define TSTM_LOG_FORCE_TX_PARA_2_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8A08, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_FORCE_TX_PARA_ERROR(v1) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x8B08, (unsigned short)(v1)));\
	} while(0)
#else
	#define TSTM_LOG_FORCE_TX_PARA_ERROR(v1)
#endif
#define TSTM_LOG_FORCE_TX_PARA_ERROR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x8B08, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_SET_RX_PATH(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8C08, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_SET_RX_PATH(v1, v2)
#endif
#define TSTM_LOG_SET_RX_PATH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8C08, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_FORCE_TAS(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8D08, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_FORCE_TAS(v1, v2)
#endif
#define TSTM_LOG_FORCE_TAS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8D08, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_POS_PRS_OCCASION(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8E08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define TSTM_LOG_POS_PRS_OCCASION(v1, v2, v3)
#endif
#define TSTM_LOG_POS_PRS_OCCASION_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8E08, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_POS_PRS_MUTING(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8F08, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define TSTM_LOG_POS_PRS_MUTING(v1, v2, v3, v4)
#endif
#define TSTM_LOG_POS_PRS_MUTING_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8F08, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_POS_PRE_SYNC_IN_PARAM(v1, v2, v3) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9008, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TSTM_LOG_POS_PRE_SYNC_IN_PARAM(v1, v2, v3)
#endif
#define TSTM_LOG_POS_PRE_SYNC_IN_PARAM_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9008, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_POS_PRE_SYNC_OUT_PARAM(v1, v2, v3, v4) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9108, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define TSTM_LOG_POS_PRE_SYNC_OUT_PARAM(v1, v2, v3, v4)
#endif
#define TSTM_LOG_POS_PRE_SYNC_OUT_PARAM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9108, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_POS_CMD_FREQ(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x9208, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v5)), TRC_MERGE_4C((unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10), (char)(v11)), TRC_MERGE_4C((unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_POS_CMD_FREQ(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define TSTM_LOG_POS_CMD_FREQ_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_5_DATA(TRC_MERGE_2S(0x9208, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v5)), TRC_MERGE_4C((unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10), (char)(v11)), TRC_MERGE_4C((unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_POS_CMD_CELL(v1, v2) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9308, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define TSTM_LOG_POS_CMD_CELL(v1, v2)
#endif
#define TSTM_LOG_POS_CMD_CELL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9308, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_POS_RPT(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x9408, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TSTM_LOG_POS_RPT(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define TSTM_LOG_POS_RPT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x9408, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TSTM_LOG_POS_RSTD_RPT(v1, v2, v3, v4, v5) do {\
		if(EL1_TSTM_1_Trace_Filter[0]==1 && (EL1_TSTM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x9508, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define TSTM_LOG_POS_RSTD_RPT(v1, v2, v3, v4, v5)
#endif
#define TSTM_LOG_POS_RSTD_RPT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x9508, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_TSTM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_TSTM_LOG_FUNC_ENTRY(unsigned char v1);
void L1TRC_Send_TSTM_LOG_SYS_TIME(unsigned long v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned long v5, unsigned short v6);
void L1TRC_Send_TSTM_LOG_MAIN_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_NEXT_MAIN_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_DL_RX_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_UL_TX_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_DL_CS_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_TX_RX_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_PS_TX_RX_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_RX_FSM_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_RESET_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_MB_MIB_DC_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_NRML_MIB_DC_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_SI_DC_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_PCELL_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_SCELL_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_RX_FSM_MOD(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_JUMP_MOD(unsigned char v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_ERR_ST(unsigned char v1);
void L1TRC_Send_TSTM_LOG_WAIT_ABORT_DONE_BMP(unsigned short v1);
void L1TRC_Send_TSTM_LOG_WAIT_EXE_DONE_BMP(unsigned short v1);
void L1TRC_Send_TSTM_LOG_MBSFN_CMD(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_TSTM_LOG_EN_CNF_SEND(void);
void L1TRC_Send_TSTM_LOG_ABORT_RPT(void);
void L1TRC_Send_TSTM_LOG_SET_PHY_CONFIG(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_SET_CH_CONFIG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_SET_COMM_CONFIG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_SET_CELL_DEL_CONFIG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_SET_CSCSR_CMD(void);
void L1TRC_Send_TSTM_LOG_SET_CSCD_CMD(void);
void L1TRC_Send_TSTM_LOG_SET_CSM_CMD(void);
void L1TRC_Send_TSTM_LOG_SET_MEAS_CMD(void);
void L1TRC_Send_TSTM_LOG_SET_CSCONT_CMD(void);
void L1TRC_Send_TSTM_LOG_SET_PRE_SYNC_CMD(void);
void L1TRC_Send_TSTM_LOG_SET_AFC_DAC_CMD(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_SET_TA_CMD(unsigned short v1);
void L1TRC_Send_TSTM_LOG_SET_FBD(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_SET_FREQ_BIN(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_ADD_MEAS_TBL_CELL(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_DEL_MEAS_TBL_CELL(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_ADD_SRV_CELL(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_ADD_FAKE_CELL(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_FAKE_CELL_DETECT_RLT(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_TSTM_LOG_CS_PARAM_1(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_TSTM_LOG_CS_PARAM_2(unsigned short v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_TSTM_LOG_CS_PARAM_3(unsigned short v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_TSTM_LOG_NBR_CM_RPT_RCV(unsigned short v1);
void L1TRC_Send_TSTM_LOG_SIC_PARAM(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_TSTM_LOG_MEAS_PARAM_1(unsigned short v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_TSTM_LOG_MEAS_PARAM_2(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5, unsigned char v6, unsigned short v7);
void L1TRC_Send_TSTM_LOG_MEAS_PARAM_3(unsigned char v1, unsigned short v2, unsigned short v3, unsigned char v4, unsigned short v5);
void L1TRC_Send_TSTM_LOG_SET_PWRSCN_CMD(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_TSTM_LOG_PCELL_RNTI_EN(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_TSTM_LOG_SCELL_RNTI_EN(unsigned char v1);
void L1TRC_Send_TSTM_LOG_RNTI_BMP(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_MBMS_BMP(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_TSTM_LOG_MBMS_CTRL_EN_BMP(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_MBMS_CTRL_DIS_BMP(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_SET_DL_CHNG(void);
void L1TRC_Send_TSTM_LOG_DL_CHNG_PCELL_PARAM(unsigned char v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_TSTM_LOG_DL_CHNG_SCELL_PARAM_1(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_DL_CHNG_SCELL_PARAM_2(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_ST_MEAS_RLT(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_TSTM_LOG_PWR_SCN_RLT(short v1, short v2);
void L1TRC_Send_TSTM_LOG_PHICH_PARAM_1(unsigned short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_TSTM_LOG_PHICH_PARAM_2(unsigned long v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_TSTM_LOG_PHICH_PARAM_3(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_TSTM_LOG_PHICH_REC_INDX(unsigned short v1);
void L1TRC_Send_TSTM_LOG_PRE_SYNC_PARAM_1(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_TSTM_LOG_PRE_SYNC_PARAM_2(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_CQI_OTHER_CNT_1(unsigned short v1);
void L1TRC_Send_TSTM_LOG_CQI_OTHER_SET2_CNT_1(unsigned short v1);
void L1TRC_Send_TSTM_LOG_CQI_OTHER_CNT_2(unsigned short v1);
void L1TRC_Send_TSTM_LOG_CQI_OTHER_CNT_3(unsigned short v1);
void L1TRC_Send_TSTM_LOG_CQI_OTHER_SET2_CNT_3(unsigned short v1);
void L1TRC_Send_TSTM_LOG_CQI_OTHER_CNT_4(unsigned short v1);
void L1TRC_Send_TSTM_LOG_CQI_OTHER_CNT_5(unsigned short v1);
void L1TRC_Send_TSTM_LOG_CQI_OTHER_SET2_CNT_5(unsigned short v1);
void L1TRC_Send_TSTM_LOG_CQI_OTHER_CNT_6(unsigned short v1);
void L1TRC_Send_TSTM_LOG_CQI_OTHER_CNT_7(unsigned short v1);
void L1TRC_Send_TSTM_LOG_CQI_PTI_CNT(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_CQI_PTI_SET2_CNT(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_CQI_RANK_CNT(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_CQI_RANK_SET2_CNT(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_EARFCN_TO_FREQ(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_FREQ_TO_EARFCN(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_MIB_CRC_RLT(unsigned short v1);
void L1TRC_Send_TSTM_LOG_SET_MBMS_EN(unsigned char v1);
void L1TRC_Send_TSTM_LOG_RX_CTRL_TIMING_RNTI(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TSTM_LOG_RX_CTRL_TIMING_POST_RS(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TSTM_LOG_RX_CTRL_TIMING_PRE_SYNC(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TSTM_LOG_RX_CTRL_TIMING_MB_EN(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TSTM_LOG_RX_FSM_RX_STRT(unsigned long v1, unsigned long v2);
void L1TRC_Send_TSTM_LOG_SRCH_EXIST_MCS_RCD(unsigned short v1);
void L1TRC_Send_TSTM_LOG_SI_CAL(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_TSTM_LOG_UPDT_STRT_TIME_BASE(unsigned short v1);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_TEST_MODE_CFG(long v1);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_DELAY_INIT(char v1);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_SWO_BIT(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_RX_HT_SUBHDR_INFO(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_RX_SUBHDR_INFO(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_SUBFRM_IND_BMP(unsigned short v1);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_TX_RESULT_INFO(char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_TX_RESULT_INFO_I(char v1, unsigned short v2, unsigned short v3, char v4);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_PRINT_TIME(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_SF_TYPE_GAP_INFO(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_STATUS_BITMAP(unsigned short v1);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_HARQ_CLOSE(unsigned short v1);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_RCV_PHICH(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_TX_GRANT_INFO(char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_TX_TIME(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_TX_TIMELINE_INFO(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_TX_MODE(long v1);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_CONFIG(long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_SCHED_CONFIG(char v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_PHY_INFO_TYPE_AND_MIB(char v1, char v2);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_PHY_INFO_CONFIG_1(unsigned short v1, unsigned short v2, char v3, char v4);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_PHY_INFO_CONFIG_2(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_NDI_NON_TOGGLE_TRICK(void);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_GET_HARQ_UPD(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_RCV_RETX_INFO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_INIT(void);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_TRIGGER_LMAC(unsigned short v1);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_TTI_BUNDLE_IDX(long v1);
void L1TRC_Send_TSTM_LOG_DUMMY_EMAC_PRINT_ADDR(unsigned short v1, unsigned long v2);
void L1TRC_Send_TSTM_LOG_NBR_TIME_CAL(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TSTM_LOG_NBR_OFFST_GET(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, long v6, long v7, long v8);
void L1TRC_Send_TSTM_LOG_RX_RLM(short v1);
void L1TRC_Send_TSTM_LOG_FULL_MEAS_ONE_ROUND_FIN(void);
void L1TRC_Send_TSTM_LOG_CSI_RPT_RAW_1(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_TSTM_LOG_CSI_RPT_RAW_2(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_TSTM_LOG_CSI_RPT_MODE(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_SOFT_COMB(unsigned char v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_DEBUG_1(unsigned long v1);
void L1TRC_Send_TSTM_LOG_DEBUG_6(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_TSTM_LOG_FORCE_TX_NOT_IN_FLIGHT(void);
void L1TRC_Send_TSTM_LOG_FORCE_TX_CMD(unsigned char v1);
void L1TRC_Send_TSTM_LOG_FORCE_TX_PARA_1(unsigned char v1, unsigned char v2, unsigned short v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_TSTM_LOG_FORCE_TX_PARA_2(unsigned char v1, unsigned char v2, unsigned char v3, short v4);
void L1TRC_Send_TSTM_LOG_FORCE_TX_PARA_ERROR(unsigned short v1);
void L1TRC_Send_TSTM_LOG_SET_RX_PATH(unsigned short v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_FORCE_TAS(unsigned char v1, unsigned short v2);
void L1TRC_Send_TSTM_LOG_POS_PRS_OCCASION(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_TSTM_LOG_POS_PRS_MUTING(unsigned short v1, unsigned char v2, unsigned long v3, unsigned char v4);
void L1TRC_Send_TSTM_LOG_POS_PRE_SYNC_IN_PARAM(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_TSTM_LOG_POS_PRE_SYNC_OUT_PARAM(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_TSTM_LOG_POS_CMD_FREQ(unsigned char v1, char v2, char v3, unsigned short v4, char v5, unsigned short v6, unsigned short v7, unsigned char v8, unsigned char v9, unsigned char v10, char v11, unsigned char v12);
void L1TRC_Send_TSTM_LOG_POS_CMD_CELL(unsigned char v1, char v2);
void L1TRC_Send_TSTM_LOG_POS_RPT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_TSTM_LOG_POS_RSTD_RPT(unsigned short v1, short v2, short v3, short v4, unsigned long v5);

void Set_EL1_TSTM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_TSTM_1()	(EL1_TSTM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_func_trace()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_func_trace_1()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace_l()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_var2_trace()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_var2_trace_l()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_var3_trace()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_var3_trace_l()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace_l()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_error_trace()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_msg_trace()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1_TSTM_1_tstm_debug_trace()	(ChkL1ModFltr_EL1_TSTM_1()&&((EL1_TSTM_1_Trace_Filter[2]&0x10)!=0))
#define ChkL1MsgFltr_TSTM_LOG_FUNC_ENTRY()	ChkL1ClsFltr_EL1_TSTM_1_tstm_func_trace()
#define ChkL1MsgFltr_TSTM_LOG_SYS_TIME()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_MAIN_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_NEXT_MAIN_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_DL_RX_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_UL_TX_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_DL_CS_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_TX_RX_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_PS_TX_RX_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_RX_FSM_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_RESET_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_MB_MIB_DC_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_NRML_MIB_DC_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_SI_DC_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_PCELL_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_SCELL_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_RX_FSM_MOD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_JUMP_MOD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_ERR_ST()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_WAIT_ABORT_DONE_BMP()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_WAIT_EXE_DONE_BMP()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_MBSFN_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_EN_CNF_SEND()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_ABORT_RPT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_PHY_CONFIG()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_CH_CONFIG()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_COMM_CONFIG()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_CELL_DEL_CONFIG()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_CSCSR_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_CSCD_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_CSM_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_MEAS_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_CSCONT_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_PRE_SYNC_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_AFC_DAC_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_TA_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_FBD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_FREQ_BIN()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_ADD_MEAS_TBL_CELL()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DEL_MEAS_TBL_CELL()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_ADD_SRV_CELL()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_ADD_FAKE_CELL()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_FAKE_CELL_DETECT_RLT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CS_PARAM_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CS_PARAM_2()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CS_PARAM_3()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NBR_CM_RPT_RCV()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SIC_PARAM()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_MEAS_PARAM_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_MEAS_PARAM_2()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_MEAS_PARAM_3()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_PWRSCN_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_PCELL_RNTI_EN()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SCELL_RNTI_EN()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_RNTI_BMP()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_MBMS_BMP()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_MBMS_CTRL_EN_BMP()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_MBMS_CTRL_DIS_BMP()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_DL_CHNG()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DL_CHNG_PCELL_PARAM()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DL_CHNG_SCELL_PARAM_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DL_CHNG_SCELL_PARAM_2()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_ST_MEAS_RLT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_PWR_SCN_RLT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_PHICH_PARAM_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_PHICH_PARAM_2()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_PHICH_PARAM_3()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_PHICH_REC_INDX()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_PRE_SYNC_PARAM_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_PRE_SYNC_PARAM_2()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_OTHER_CNT_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_OTHER_SET2_CNT_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_OTHER_CNT_2()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_OTHER_CNT_3()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_OTHER_SET2_CNT_3()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_OTHER_CNT_4()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_OTHER_CNT_5()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_OTHER_SET2_CNT_5()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_OTHER_CNT_6()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_OTHER_CNT_7()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_PTI_CNT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_PTI_SET2_CNT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_RANK_CNT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CQI_RANK_SET2_CNT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_EARFCN_TO_FREQ()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_FREQ_TO_EARFCN()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_MIB_CRC_RLT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_MBMS_EN()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_RX_CTRL_TIMING_RNTI()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_RX_CTRL_TIMING_POST_RS()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_RX_CTRL_TIMING_PRE_SYNC()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_RX_CTRL_TIMING_MB_EN()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_RX_FSM_RX_STRT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SRCH_EXIST_MCS_RCD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SI_CAL()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_UPDT_STRT_TIME_BASE()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_TEST_MODE_CFG()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_DELAY_INIT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_SWO_BIT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_RX_HT_SUBHDR_INFO()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_RX_SUBHDR_INFO()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_SUBFRM_IND_BMP()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_TX_RESULT_INFO()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_TX_RESULT_INFO_I()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_PRINT_TIME()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_SF_TYPE_GAP_INFO()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_STATUS_BITMAP()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_HARQ_CLOSE()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_RCV_PHICH()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_TX_GRANT_INFO()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_TX_TIME()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_TX_TIMELINE_INFO()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_TX_MODE()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_CONFIG()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_SCHED_CONFIG()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_PHY_INFO_TYPE_AND_MIB()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_PHY_INFO_CONFIG_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_PHY_INFO_CONFIG_2()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_NDI_NON_TOGGLE_TRICK()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_GET_HARQ_UPD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_RCV_RETX_INFO()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_INIT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_TRIGGER_LMAC()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_TTI_BUNDLE_IDX()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DUMMY_EMAC_PRINT_ADDR()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NBR_TIME_CAL()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_NBR_OFFST_GET()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_RX_RLM()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_FULL_MEAS_ONE_ROUND_FIN()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CSI_RPT_RAW_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CSI_RPT_RAW_2()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_CSI_RPT_MODE()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_SOFT_COMB()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_DEBUG_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_debug_trace()
#define ChkL1MsgFltr_TSTM_LOG_DEBUG_6()	ChkL1ClsFltr_EL1_TSTM_1_tstm_debug_trace()
#define ChkL1MsgFltr_TSTM_LOG_FORCE_TX_NOT_IN_FLIGHT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_FORCE_TX_CMD()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_FORCE_TX_PARA_1()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_FORCE_TX_PARA_2()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_FORCE_TX_PARA_ERROR()	ChkL1ClsFltr_EL1_TSTM_1_tstm_flow_trace()
#define ChkL1MsgFltr_TSTM_LOG_SET_RX_PATH()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_FORCE_TAS()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_POS_PRS_OCCASION()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_POS_PRS_MUTING()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_POS_PRE_SYNC_IN_PARAM()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_POS_PRE_SYNC_OUT_PARAM()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_POS_CMD_FREQ()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_POS_CMD_CELL()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_POS_RPT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()
#define ChkL1MsgFltr_TSTM_LOG_POS_RSTD_RPT()	ChkL1ClsFltr_EL1_TSTM_1_tstm_var_trace()


#endif
