#ifndef L1TRC_EL1D_COMMON0_DEF_H
#define L1TRC_EL1D_COMMON0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_CT_FBD_UPDATE_SCENE(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_CT_MERGE_TYPE(v1)  (unsigned char)(v1+4)
#define EL1D_TRC_STR_TC_HRT_CASE(v1)  (unsigned char)(v1+8)
#define EL1D_TRC_STR_TC_CELL_TYPE(v1)  (unsigned char)(v1+13)
#define EL1D_TRC_STR_TC_MSTA(v1)  (unsigned char)(v1+16)
#define EL1D_TRC_STR_TC_CIR_MAX_ALIGN_RX(v1)  (unsigned char)(v1+20)
#define EL1D_TRC_STR_RFCC_RX_CMD_MODULE(v1)  (unsigned char)(v1+24)
#define EL1D_TRC_STR_RFCC_RX_OFF_ON(v1)  (unsigned char)(v1+34)
#define EL1D_TRC_STR_RFCC_RX_CELL_TYPE(v1)  (unsigned char)(v1+36)
#define EL1D_TRC_STR_RFCC_RX_FIN_EXE_EVT(v1)  (unsigned char)(v1+38)
#define EL1D_TRC_STR_RFCC_RX_NEED(v1)  (unsigned char)(v1+41)
#define EL1D_TRC_STR_LPWR_SLP_DSP(v1)  (unsigned char)(v1+45)
#define EL1D_TRC_STR_LPWR_SLP_MTCMOS(v1)  (unsigned char)(v1+50)
#define EL1D_TRC_STR_LPWR_SLP_MAIN_ACTION(v1)  (unsigned char)(v1+59)
#define EL1D_TRC_STR_LPWR_SLP_DSP_BKUP_STA(v1)  (unsigned char)(v1+62)
#define EL1D_TRC_STR_LPWR_SLP_FSM(v1)  (unsigned char)(v1+67)
#define EL1D_TRC_STR_LPWR_TOPCG_IDX(v1)  (unsigned char)(v1+70)
#define EL1D_TRC_STR_LPWR_CLKDIVCG_IDX(v1)  (unsigned char)(v1+81)
#define EL1D_TRC_STR_LPWR_DVFS_CASE(v1)  (unsigned char)(v1+84)
#define EL1D_TRC_STR_LPWR_MODONCG_IDX(v1)  (unsigned char)(v1+88)
#define EL1D_TRC_STR_LPWR_SRAM1_PRINT_IDX(v1)  (unsigned char)(v1+100)
#define EL1D_TRC_STR_LPWR_SRAM1_PRINT_IDX_NEW(v1)  (unsigned char)(v1+140)
#define EL1D_TRC_STR_LPWR_SRAM1_STA(v1)  (unsigned char)(v1+187)
#define EL1D_TRC_STR_LPWR_SRAM1_CFG(v1)  (unsigned char)(v1+189)
#define EL1D_TRC_STR_LPWR_SRAM2_SS_SONIC(v1)  (unsigned char)(v1+192)
#define EL1D_TRC_STR_LPWR_SRAM2_SS_SRAM_TYPE(v1)  (unsigned char)(v1+195)
#define EL1D_TRC_STR_LPWR_SRAM2_SS_SRAM_PWR_CFG(v1)  (unsigned char)(v1+198)
#define EL1D_TRC_STR_BOOTDSP_STATE(v1)  (unsigned char)(v1+202)
#define EL1D_TRC_STR_BOOT_MD32_STATE(v1)  (unsigned char)(v1+211)
#define EL1D_TRC_STR_RESET_MD32_STATE(v1)  (unsigned char)(v1+220)
#define EL1D_TRC_STR_BOOTDSP_DLSTATUS(v1)  (unsigned char)(v1+226)
#define EL1D_TRC_STR_BOOTDSP_STATUS(v1)  (unsigned char)(v1+229)
#define EL1D_TRC_STR_GDMA_HW_INT(v1)  (unsigned char)(v1+231)
#define EL1D_TRC_STR_CACHE_TYPE(v1)  (unsigned char)(v1+239)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_COMMON_DBG_2(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0031, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_COMMON_DBG_2(v1, v2, v3)
#endif
#define EL1D_TRC_COMMON_DBG_2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0031, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_COMMON_DBG_4(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0131, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_COMMON_DBG_4(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_COMMON_DBG_4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0131, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CT_PSCELL_HUGE_FBD_DIFF(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0231, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), (unsigned char)(v2), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CT_PSCELL_HUGE_FBD_DIFF(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define EL1D_TRC_CT_PSCELL_HUGE_FBD_DIFF_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0231, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), (unsigned char)(v2), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v9), (unsigned char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CT_GET_UNQUAL_SCELL(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0331, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CT_GET_UNQUAL_SCELL(v1, v2)
#endif
#define EL1D_TRC_CT_GET_UNQUAL_SCELL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0331, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_CT_UPDATE_FBD(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0431, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CT_UPDATE_FBD(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_CT_UPDATE_FBD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0431, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CT_UPDATE_MULTIPLE_CELL_FBD(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x0531, (short)(v1)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1D_TRC_CT_UPDATE_MULTIPLE_CELL_FBD(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_CT_UPDATE_MULTIPLE_CELL_FBD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x0531, (short)(v1)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_CT_MERGE_CELL(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0631, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CT_MERGE_CELL(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CT_MERGE_CELL_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0631, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_CT_C_CLR_CELL(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0731, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CT_C_CLR_CELL(v1, v2)
#endif
#define EL1D_TRC_CT_C_CLR_CELL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0731, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_CT_C_SET_COMMON_CFG(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0831, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CT_C_SET_COMMON_CFG(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CT_C_SET_COMMON_CFG_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0831, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_CT_C_SET_QUAL(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0931, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CT_C_SET_QUAL(v1, v2)
#endif
#define EL1D_TRC_CT_C_SET_QUAL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0931, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_CT_D_SET_SYS_CFG2(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A31, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_CT_D_SET_SYS_CFG2(v1, v2, v3, v4)
#endif
#define EL1D_TRC_CT_D_SET_SYS_CFG2_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A31, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TC_HRT_TIME(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0B31, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_TC_HRT_TIME(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TC_HRT_TIME_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0B31, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TC_HRT_TIME_FAIL(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C31, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_TC_HRT_TIME_FAIL(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TC_HRT_TIME_FAIL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C31, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TC_HRT_RECORD(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0D31, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_TC_HRT_RECORD(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_TC_HRT_RECORD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0D31, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TC_DSP_HRT_MARGIN(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E31, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TC_DSP_HRT_MARGIN(v1, v2)
#endif
#define EL1D_TRC_TC_DSP_HRT_MARGIN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E31, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TC_PHY_SCNT(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TC_PHY_SCNT(v1, v2)
#endif
#define EL1D_TRC_TC_PHY_SCNT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TC_FRC(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1031, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TC_FRC(v1, v2)
#endif
#define EL1D_TRC_TC_FRC_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1031, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TC_IRQ_PHYTIME(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1131, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TC_IRQ_PHYTIME(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TC_IRQ_PHYTIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1131, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TC_EL1CD_HRT(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1231, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TC_EL1CD_HRT(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TC_EL1CD_HRT_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1231, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TC_SFBD(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1331, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TC_SFBD(v1, v2)
#endif
#define EL1D_TRC_TC_SFBD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1331, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TC_SFBD_SHIFT(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1431, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TC_SFBD_SHIFT(v1, v2, v3)
#endif
#define EL1D_TRC_TC_SFBD_SHIFT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1431, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TC_CALC_UNQUAL_SCELL(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1531, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_TC_CALC_UNQUAL_SCELL(v1, v2)
#endif
#define EL1D_TRC_TC_CALC_UNQUAL_SCELL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1531, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TC_UPDATE_CIR_MAX(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1631, (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TC_UPDATE_CIR_MAX(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TC_UPDATE_CIR_MAX_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1631, (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TC_UPDATE_CIR_LEN(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1731, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TC_UPDATE_CIR_LEN(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TC_UPDATE_CIR_LEN_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1731, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TC_TX_TIMING(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1831, (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TC_TX_TIMING(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TC_TX_TIMING_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1831, (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TC_CIR_MAX_ALIGN(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1931, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_TC_CIR_MAX_ALIGN(v1, v2, v3)
#endif
#define EL1D_TRC_TC_CIR_MAX_ALIGN_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1931, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TC_UPDATE_MSTA(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TC_UPDATE_MSTA(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TC_UPDATE_MSTA_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TC_WAKEUP_PHY_TIME(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1B31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TC_WAKEUP_PHY_TIME(v1, v2)
#endif
#define EL1D_TRC_TC_WAKEUP_PHY_TIME_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1B31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TC_SLP_DUR(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TC_SLP_DUR(v1)
#endif
#define EL1D_TRC_TC_SLP_DUR_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TC_HW_STOP_START_DUR(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1D31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_TC_HW_STOP_START_DUR(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TC_HW_STOP_START_DUR_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1D31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TC_HW_STOP_START_FWS(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E31, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)));\
	} while(0)
#else
	#define EL1D_TRC_TC_HW_STOP_START_FWS(v1, v2, v3, v4)
#endif
#define EL1D_TRC_TC_HW_STOP_START_FWS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E31, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TC_HW_STOP_START_LOCK(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TC_HW_STOP_START_LOCK(v1)
#endif
#define EL1D_TRC_TC_HW_STOP_START_LOCK_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TC_IS_3G_U_CONN_BY_UL1D(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2031, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_TC_IS_3G_U_CONN_BY_UL1D(v1)
#endif
#define EL1D_TRC_TC_IS_3G_U_CONN_BY_UL1D_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2031, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TC_HW_SONIC_BOOT_DONE(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2131, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_TC_HW_SONIC_BOOT_DONE(v1)
#endif
#define EL1D_TRC_TC_HW_SONIC_BOOT_DONE_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2131, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TC_HW_SET_DL_RR(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2231, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_TC_HW_SET_DL_RR(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TC_HW_SET_DL_RR_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2231, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_TC_HW_DUMP_DL_RR(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2331, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_TC_HW_DUMP_DL_RR(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_TC_HW_DUMP_DL_RR_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2331, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_TC_HW_DISABLE_IRQ(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2431, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TC_HW_DISABLE_IRQ(v1, v2)
#endif
#define EL1D_TRC_TC_HW_DISABLE_IRQ_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2431, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RFCC_RX_MOD_CMD_BMP(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2531, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_RFCC_RX_MOD_CMD_BMP(v1)
#endif
#define EL1D_TRC_RFCC_RX_MOD_CMD_BMP_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2531, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RFCC_RX_RAW_EXE_LIST(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2631, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RFCC_RX_RAW_EXE_LIST(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RFCC_RX_RAW_EXE_LIST_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2631, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RFCC_RX_FIN_EXE_LIST(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2731, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_RFCC_RX_FIN_EXE_LIST(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1D_TRC_RFCC_RX_FIN_EXE_LIST_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2731, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_RFCC_RX_RFD_BASIC_CFG(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2831, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RFCC_RX_RFD_BASIC_CFG(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1D_TRC_RFCC_RX_RFD_BASIC_CFG_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2831, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RFCC_RX_AGC_RF_ON(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2931, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_RFCC_RX_AGC_RF_ON(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RFCC_RX_AGC_RF_ON_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2931, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_RFCC_RX_EXPIRE_CHK_ERR(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2A31, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_RFCC_RX_EXPIRE_CHK_ERR(v1, v2, v3, v4)
#endif
#define EL1D_TRC_RFCC_RX_EXPIRE_CHK_ERR_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2A31, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_SLP_MAIN_INFO(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B31, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_MAIN_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_LPWR_SLP_MAIN_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B31, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_SLP_MAIN_ACTION(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C31, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_MAIN_ACTION(v1)
#endif
#define EL1D_TRC_LPWR_SLP_MAIN_ACTION_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C31, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_MAIN_INFO(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2D31, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_MAIN_INFO(v1, v2, v3, v4)
#endif
#define EL1D_TRC_LPWR_DVFS_MAIN_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2D31, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_RX_ON() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_RX_ON()
#endif
#define EL1D_TRC_LPWR_DVFS_RX_ON_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_RX_OFF() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_RX_OFF()
#endif
#define EL1D_TRC_LPWR_DVFS_RX_OFF_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_CSI_ON() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3031, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_CSI_ON()
#endif
#define EL1D_TRC_LPWR_DVFS_CSI_ON_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3031, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_CSI_OFF() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3131, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_CSI_OFF()
#endif
#define EL1D_TRC_LPWR_DVFS_CSI_OFF_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3131, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_OCIC_SWITCH(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3231, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_OCIC_SWITCH(v1)
#endif
#define EL1D_TRC_LPWR_DVFS_OCIC_SWITCH_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3231, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_ACTWIN_ON() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3331, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_ACTWIN_ON()
#endif
#define EL1D_TRC_LPWR_DVFS_ACTWIN_ON_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3331, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_ACTWIN_OFF() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3431, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_ACTWIN_OFF()
#endif
#define EL1D_TRC_LPWR_DVFS_ACTWIN_OFF_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3431, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_CHK_RX_IDLE(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3531, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_CHK_RX_IDLE(v1, v2, v3)
#endif
#define EL1D_TRC_LPWR_DVFS_CHK_RX_IDLE_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3531, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_RX_GEAR_RELATED_INFO(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3631, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_RX_GEAR_RELATED_INFO(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_LPWR_DVFS_RX_GEAR_RELATED_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x3631, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_MBPBCH_ON(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3731, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_MBPBCH_ON(v1)
#endif
#define EL1D_TRC_LPWR_DVFS_MBPBCH_ON_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3731, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_MBPBCH_OFF() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3831, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_MBPBCH_OFF()
#endif
#define EL1D_TRC_LPWR_DVFS_MBPBCH_OFF_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3831, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_MINWIN_ONTIME(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3931, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_MINWIN_ONTIME(v1)
#endif
#define EL1D_TRC_LPWR_DVFS_MINWIN_ONTIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3931, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_MINWIN_OFFTIME(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_MINWIN_OFFTIME(v1)
#endif
#define EL1D_TRC_LPWR_DVFS_MINWIN_OFFTIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_DBG(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3B31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_DBG(v1)
#endif
#define EL1D_TRC_LPWR_DVFS_DBG_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3B31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_DVFS_LOCK_OFF(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3C31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_DVFS_LOCK_OFF(v1, v2)
#endif
#define EL1D_TRC_LPWR_DVFS_LOCK_OFF_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3C31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_LPWR_SLP_ABORT_DSP(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D31, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_ABORT_DSP(v1, v2)
#endif
#define EL1D_TRC_LPWR_SLP_ABORT_DSP_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D31, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_LPWR_SLP_DSP_IDLE_FLAG(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3E31, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_DSP_IDLE_FLAG(v1, v2, v3)
#endif
#define EL1D_TRC_LPWR_SLP_DSP_IDLE_FLAG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3E31, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_LPWR_SLP_DSP_BACKUP(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3F31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_DSP_BACKUP(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_LPWR_SLP_DSP_BACKUP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3F31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_LPWR_SLP_DSP_BACKUP_ACK(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4031, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_DSP_BACKUP_ACK(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_LPWR_SLP_DSP_BACKUP_ACK_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4031, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_LPWR_SLP_SONIC_FRC_PWR(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4131, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_SONIC_FRC_PWR(v1, v2, v3, v4)
#endif
#define EL1D_TRC_LPWR_SLP_SONIC_FRC_PWR_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4131, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_SLP_FRC_CLR_NEED(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4231, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_FRC_CLR_NEED(v1)
#endif
#define EL1D_TRC_LPWR_SLP_FRC_CLR_NEED_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4231, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_SLP_SET_SWM_PWR(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4331, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_SET_SWM_PWR(v1, v2, v3, v4)
#endif
#define EL1D_TRC_LPWR_SLP_SET_SWM_PWR_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4331, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_SLP_PWR_OFF2ON(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4431, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_PWR_OFF2ON(v1, v2)
#endif
#define EL1D_TRC_LPWR_SLP_PWR_OFF2ON_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4431, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_LPWR_SLP_CLR_OFF2ON(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4531, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_CLR_OFF2ON(v1)
#endif
#define EL1D_TRC_LPWR_SLP_CLR_OFF2ON_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4531, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_SLP_ABNORMAL_LOCK(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4631, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SLP_ABNORMAL_LOCK(v1)
#endif
#define EL1D_TRC_LPWR_SLP_ABNORMAL_LOCK_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4631, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_LPWR_TOPCG_MAIN_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_12_DATA(TRC_MERGE_1S2C(0x4731, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_TOPCG_MAIN_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define EL1D_TRC_LPWR_TOPCG_MAIN_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_12_DATA(TRC_MERGE_1S2C(0x4731, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_LPWR_TOPCG_SWITCH(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4831, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_TOPCG_SWITCH(v1, v2)
#endif
#define EL1D_TRC_LPWR_TOPCG_SWITCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4831, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_LPWR_TOPCG_MDL_TIME_PRO(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4931, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_TOPCG_MDL_TIME_PRO(v1, v2)
#endif
#define EL1D_TRC_LPWR_TOPCG_MDL_TIME_PRO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4931, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_COM_MML1_CG(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_COM_MML1_CG(v1, v2, v3)
#endif
#define EL1D_TRC_LPWR_COM_MML1_CG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_LPWR_CLKDIVCG_SET_VAL(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4B31, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_CLKDIVCG_SET_VAL(v1, v2)
#endif
#define EL1D_TRC_LPWR_CLKDIVCG_SET_VAL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4B31, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_LPWR_CLKDIVCG_FORCE(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C31, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_CLKDIVCG_FORCE(v1)
#endif
#define EL1D_TRC_LPWR_CLKDIVCG_FORCE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C31, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_LPWR_MODONCG_SWITCH(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D31, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_MODONCG_SWITCH(v1, v2)
#endif
#define EL1D_TRC_LPWR_MODONCG_SWITCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D31, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_BRP_PM_ALLOC(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x4E31, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_BRP_PM_ALLOC(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_LPWR_BRP_PM_ALLOC_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x4E31, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_FEC_PM_ALLOC(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_FEC_PM_ALLOC(v1, v2, v3, v4)
#endif
#define EL1D_TRC_LPWR_FEC_PM_ALLOC_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_LPWR_SRAM1_HW_DRV(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5031, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SRAM1_HW_DRV(v1, v2, v3)
#endif
#define EL1D_TRC_LPWR_SRAM1_HW_DRV_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5031, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_LPWR_SRAM2_HW_DRV_ON(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5131, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SRAM2_HW_DRV_ON(v1, v2, v3)
#endif
#define EL1D_TRC_LPWR_SRAM2_HW_DRV_ON_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5131, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1D_TRC_LPWR_SRAM2_HW_DRV_OFF(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5231, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_SRAM2_HW_DRV_OFF(v1, v2, v3)
#endif
#define EL1D_TRC_LPWR_SRAM2_HW_DRV_OFF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5231, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_TRIGGER(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5331, (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_TRIGGER(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_BOOT_TRIGGER_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5331, (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_MD32_MEM_DL(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5431, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_MD32_MEM_DL(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_BOOT_MD32_MEM_DL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5431, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_RAT_CHG_STATUS(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5531, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_RAT_CHG_STATUS(v1, v2, v3)
#endif
#define EL1D_TRC_BOOT_RAT_CHG_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5531, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_UNGATESONIC() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5631, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_UNGATESONIC()
#endif
#define EL1D_TRC_BOOT_UNGATESONIC_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5631, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_UNGATEMD32() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5731, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_UNGATEMD32()
#endif
#define EL1D_TRC_BOOT_UNGATEMD32_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5731, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_CHECKDLSONIC(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5831, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_CHECKDLSONIC(v1)
#endif
#define EL1D_TRC_BOOT_CHECKDLSONIC_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5831, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_SONICSTATUS(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5931, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_SONICSTATUS(v1, v2, v3)
#endif
#define EL1D_TRC_BOOT_SONICSTATUS_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5931, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_MD32STATUS(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5A31, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_MD32STATUS(v1)
#endif
#define EL1D_TRC_BOOT_MD32STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5A31, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_MD32_FSM(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5B31, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_MD32_FSM(v1, v2, v3, v4)
#endif
#define EL1D_TRC_BOOT_MD32_FSM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5B31, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_MD32_RESET_STA(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5C31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_MD32_RESET_STA(v1, v2, v3)
#endif
#define EL1D_TRC_BOOT_MD32_RESET_STA_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5C31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_SONICCSIF(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5D31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_SONICCSIF(v1, v2, v3)
#endif
#define EL1D_TRC_BOOT_SONICCSIF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5D31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_DORMANT_WAKEUP(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E31, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_DORMANT_WAKEUP(v1)
#endif
#define EL1D_TRC_BOOT_DORMANT_WAKEUP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E31, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_BRP_PMDMCHECK(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_BRP_PMDMCHECK(v1, v2, v3, v4)
#endif
#define EL1D_TRC_BOOT_BRP_PMDMCHECK_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_BOOT_ERROR() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6031, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_BOOT_ERROR()
#endif
#define EL1D_TRC_BOOT_ERROR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6031, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_GDMA_HW_INT(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6131, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_HW_INT(v1)
#endif
#define EL1D_TRC_GDMA_HW_INT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6131, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_GDMA_CH_STARTED(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6231, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_CH_STARTED(v1, v2, v3)
#endif
#define EL1D_TRC_GDMA_CH_STARTED_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6231, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_GDMA_INIT_DMA() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6331, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_INIT_DMA()
#endif
#define EL1D_TRC_GDMA_INIT_DMA_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6331, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_GDMA_REGISTER_DMA(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6431, (short)(v5)), TRC_MERGE_1S2C((short)(v6), (char)(v1), (char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_REGISTER_DMA(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_GDMA_REGISTER_DMA_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6431, (short)(v5)), TRC_MERGE_1S2C((short)(v6), (char)(v1), (char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_GDMA_START_DMA(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6531, (short)(v5)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_START_DMA(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_GDMA_START_DMA_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6531, (short)(v5)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v6), TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_GDMA_START_DMA_CR4(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6631, (short)(v5)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_START_DMA_CR4(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_GDMA_START_DMA_CR4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6631, (short)(v5)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_GDMA_FREE_DMA(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6731, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_FREE_DMA(v1, v2, v3)
#endif
#define EL1D_TRC_GDMA_FREE_DMA_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6731, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_GDMA_MEMCMP_PARSE_OK(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6831, (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_MEMCMP_PARSE_OK(v1, v2, v3, v4)
#endif
#define EL1D_TRC_GDMA_MEMCMP_PARSE_OK_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6831, (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_GDMA_MEMCMP_PARSE_FAIL() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6931, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_MEMCMP_PARSE_FAIL()
#endif
#define EL1D_TRC_GDMA_MEMCMP_PARSE_FAIL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6931, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_GDMA_MEMCMP_SAME(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6A31, (short)(v3)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_MEMCMP_SAME(v1, v2, v3)
#endif
#define EL1D_TRC_GDMA_MEMCMP_SAME_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6A31, (short)(v3)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_GDMA_MEMCMP_DIFF(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6B31, (short)(v3)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_GDMA_MEMCMP_DIFF(v1, v2, v3)
#endif
#define EL1D_TRC_GDMA_MEMCMP_DIFF_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6B31, (short)(v3)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_32K_CAL_PARA(v1, v2, v3, v4, v5) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6C31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_PARA(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_32K_CAL_PARA_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x6C31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_CAL_AFCDAC(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6D31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_AFCDAC(v1, v2)
#endif
#define EL1D_TRC_32K_CAL_AFCDAC_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6D31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_32K_CAL_AFCDAC_INFO(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x6E31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_AFCDAC_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_32K_CAL_AFCDAC_INFO_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x6E31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_CAL_TIME_ERR(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F31, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_TIME_ERR(v1, v2)
#endif
#define EL1D_TRC_32K_CAL_TIME_ERR_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F31, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_32K_CAL_TIME_ERR_INFO_1(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7031, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_TIME_ERR_INFO_1(v1, v2, v3)
#endif
#define EL1D_TRC_32K_CAL_TIME_ERR_INFO_1_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x7031, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_CAL_TIME_ERR_INFO_2(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7131, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_TIME_ERR_INFO_2(v1, v2, v3)
#endif
#define EL1D_TRC_32K_CAL_TIME_ERR_INFO_2_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7131, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_CAL_UNSLP_CNT() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7231, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_UNSLP_CNT()
#endif
#define EL1D_TRC_32K_CAL_UNSLP_CNT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7231, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_CAL_DRX_CYCLE(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7331, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_DRX_CYCLE(v1)
#endif
#define EL1D_TRC_32K_CAL_DRX_CYCLE_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7331, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_CAL_TRIGGER(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7431, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_TRIGGER(v1)
#endif
#define EL1D_TRC_32K_CAL_TRIGGER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7431, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_CAL_REK_TIME(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7531, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_REK_TIME(v1)
#endif
#define EL1D_TRC_32K_CAL_REK_TIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7531, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_32K_CAL_CIR_MAX_DIFF(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7631, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_CAL_CIR_MAX_DIFF(v1, v2)
#endif
#define EL1D_TRC_32K_CAL_CIR_MAX_DIFF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7631, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_ADJ_INFO(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7731, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_ADJ_INFO(v1, v2, v3)
#endif
#define EL1D_TRC_32K_LESS_ADJ_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7731, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_PSYNC_QUERY(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7831, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_PSYNC_QUERY(v1, v2, v3)
#endif
#define EL1D_TRC_32K_LESS_PSYNC_QUERY_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7831, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_PSYNC_CALC_WO_DATA_OUT(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7931, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_PSYNC_CALC_WO_DATA_OUT(v1)
#endif
#define EL1D_TRC_32K_LESS_PSYNC_CALC_WO_DATA_OUT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7931, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_ADJ_MAP(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x7A31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_ADJ_MAP(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_32K_LESS_ADJ_MAP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x7A31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_DSP_CMD(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x7B31, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_DSP_CMD(v1)
#endif
#define EL1D_TRC_32K_LESS_DSP_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x7B31, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_SELF_UPDATE(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7C31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_SELF_UPDATE(v1, v2, v3)
#endif
#define EL1D_TRC_32K_LESS_SELF_UPDATE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7C31, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_UPDATE_RULE_0() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7D31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_UPDATE_RULE_0()
#endif
#define EL1D_TRC_32K_LESS_UPDATE_RULE_0_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7D31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_UPDATE_RULE_1() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7E31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_UPDATE_RULE_1()
#endif
#define EL1D_TRC_32K_LESS_UPDATE_RULE_1_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7E31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_UPDATE_DROP() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_UPDATE_DROP()
#endif
#define EL1D_TRC_32K_LESS_UPDATE_DROP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7F31, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_DELAY_RPT_HANDLE(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8031, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_DELAY_RPT_HANDLE(v1)
#endif
#define EL1D_TRC_32K_LESS_DELAY_RPT_HANDLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8031, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_DSP_RPT_ORI(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8131, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_DSP_RPT_ORI(v1)
#endif
#define EL1D_TRC_32K_LESS_DSP_RPT_ORI_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8131, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_DSP_RPT(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8231, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_DSP_RPT(v1, v2, v3)
#endif
#define EL1D_TRC_32K_LESS_DSP_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8231, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_DL_CHG_CMD() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8331, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_DL_CHG_CMD()
#endif
#define EL1D_TRC_32K_LESS_DL_CHG_CMD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8331, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_DL_CHG_CMD_1() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8431, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_DL_CHG_CMD_1()
#endif
#define EL1D_TRC_32K_LESS_DL_CHG_CMD_1_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8431, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_WARNING_1() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8531, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_WARNING_1()
#endif
#define EL1D_TRC_32K_LESS_WARNING_1_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8531, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_WARNING_2() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8631, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_WARNING_2()
#endif
#define EL1D_TRC_32K_LESS_WARNING_2_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8631, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_NON_DRX(v1, v2, v3) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8731, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_NON_DRX(v1, v2, v3)
#endif
#define EL1D_TRC_32K_LESS_NON_DRX_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8731, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_BOUND_SCELL_FBD() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8831, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_BOUND_SCELL_FBD()
#endif
#define EL1D_TRC_32K_LESS_BOUND_SCELL_FBD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8831, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_WARNING_3() do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8931, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_WARNING_3()
#endif
#define EL1D_TRC_32K_LESS_WARNING_3_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8931, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_WARNING_4(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8A31, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_WARNING_4(v1, v2)
#endif
#define EL1D_TRC_32K_LESS_WARNING_4_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8A31, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_32K_LESS_BOUND(v1, v2, v3, v4) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8B31, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_32K_LESS_BOUND(v1, v2, v3, v4)
#endif
#define EL1D_TRC_32K_LESS_BOUND_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8B31, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_CIDD_BEGIN(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8C31, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_CIDD_BEGIN(v1)
#endif
#define EL1D_TRC_LPWR_CIDD_BEGIN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8C31, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_CIDD_END(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8D31, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_CIDD_END(v1)
#endif
#define EL1D_TRC_LPWR_CIDD_END_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8D31, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_CIDD_QUERY_STATUS(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8E31, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_CIDD_QUERY_STATUS(v1, v2)
#endif
#define EL1D_TRC_LPWR_CIDD_QUERY_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8E31, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_LPWR_CIDD_DISABLE_PM(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8F31, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_LPWR_CIDD_DISABLE_PM(v1)
#endif
#define EL1D_TRC_LPWR_CIDD_DISABLE_PM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8F31, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_SUBF_HISR_ABS_TIME(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x9031, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_SUBF_HISR_ABS_TIME(v1)
#endif
#define EL1D_TRC_SUBF_HISR_ABS_TIME_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x9031, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_UL1D_LISR_MASK_ALLOW(v1) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9131, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_UL1D_LISR_MASK_ALLOW(v1)
#endif
#define EL1D_TRC_UL1D_LISR_MASK_ALLOW_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9131, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_TIME_PRO_GENERAL(v1, v2) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9231, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_TIME_PRO_GENERAL(v1, v2)
#endif
#define EL1D_TRC_TIME_PRO_GENERAL_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x9231, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_ELM_PROFILING(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x9331, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15));\
	} while(0)
#else
	#define EL1D_TRC_ELM_PROFILING(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define EL1D_TRC_ELM_PROFILING_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x9331, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CACHE_PROFILING(v1, v2, v3, v4, v5, v6) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x9431, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1), (long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define EL1D_TRC_CACHE_PROFILING(v1, v2, v3, v4, v5, v6)
#endif
#define EL1D_TRC_CACHE_PROFILING_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x9431, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1), (long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1D_TRC_EL1D_IDLE_RATE(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1D_COMMON0_Trace_Filter[0]==1 && (EL1D_COMMON0_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x9531, (short)(v3)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define EL1D_TRC_EL1D_IDLE_RATE(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1D_TRC_EL1D_IDLE_RATE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_2S(0x9531, (short)(v3)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_COMMON0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_COMMON_DBG_2(unsigned short v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_COMMON_DBG_4(unsigned short v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_CT_PSCELL_HUGE_FBD_DIFF(unsigned short v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned char v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_EL1D_TRC_CT_GET_UNQUAL_SCELL(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_CT_UPDATE_FBD(unsigned short v1, unsigned char v2, unsigned short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_CT_UPDATE_MULTIPLE_CELL_FBD(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_CT_MERGE_CELL(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_CT_C_CLR_CELL(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_CT_C_SET_COMMON_CFG(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_CT_C_SET_QUAL(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_CT_D_SET_SYS_CFG2(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_TC_HRT_TIME(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_TC_HRT_TIME_FAIL(unsigned char v1, unsigned long v2, unsigned long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_TC_HRT_RECORD(unsigned char v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9);
void L1TRC_Send_EL1D_TRC_TC_DSP_HRT_MARGIN(unsigned char v1, long v2);
void L1TRC_Send_EL1D_TRC_TC_PHY_SCNT(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TC_FRC(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TC_IRQ_PHYTIME(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_TC_EL1CD_HRT(unsigned char v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_TC_SFBD(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TC_SFBD_SHIFT(unsigned char v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_TC_CALC_UNQUAL_SCELL(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_TC_UPDATE_CIR_MAX(unsigned char v1, unsigned char v2, short v3, unsigned char v4, unsigned short v5);
void L1TRC_Send_EL1D_TRC_TC_UPDATE_CIR_LEN(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_TC_TX_TIMING(unsigned long v1, unsigned long v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_TC_CIR_MAX_ALIGN(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_TC_UPDATE_MSTA(unsigned char v1, unsigned char v2, unsigned char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_TC_WAKEUP_PHY_TIME(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_TC_SLP_DUR(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TC_HW_STOP_START_DUR(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_TC_HW_STOP_START_FWS(unsigned char v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_TC_HW_STOP_START_LOCK(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TC_IS_3G_U_CONN_BY_UL1D(char v1);
void L1TRC_Send_EL1D_TRC_TC_HW_SONIC_BOOT_DONE(unsigned long v1);
void L1TRC_Send_EL1D_TRC_TC_HW_SET_DL_RR(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_TC_HW_DUMP_DL_RR(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_TC_HW_DISABLE_IRQ(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_RFCC_RX_MOD_CMD_BMP(unsigned long v1);
void L1TRC_Send_EL1D_TRC_RFCC_RX_RAW_EXE_LIST(unsigned char v1, char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_RFCC_RX_FIN_EXE_LIST(unsigned char v1, unsigned long v2, unsigned char v3, unsigned char v4, unsigned long v5, unsigned long v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_EL1D_TRC_RFCC_RX_RFD_BASIC_CFG(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1D_TRC_RFCC_RX_AGC_RF_ON(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_RFCC_RX_EXPIRE_CHK_ERR(unsigned char v1, unsigned long v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_MAIN_INFO(unsigned char v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_MAIN_ACTION(unsigned char v1);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_MAIN_INFO(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_RX_ON(void);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_RX_OFF(void);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_CSI_ON(void);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_CSI_OFF(void);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_OCIC_SWITCH(unsigned long v1);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_ACTWIN_ON(void);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_ACTWIN_OFF(void);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_CHK_RX_IDLE(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_RX_GEAR_RELATED_INFO(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_MBPBCH_ON(unsigned long v1);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_MBPBCH_OFF(void);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_MINWIN_ONTIME(unsigned long v1);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_MINWIN_OFFTIME(unsigned long v1);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_DBG(unsigned long v1);
void L1TRC_Send_EL1D_TRC_LPWR_DVFS_LOCK_OFF(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_ABORT_DSP(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_DSP_IDLE_FLAG(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_DSP_BACKUP(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_DSP_BACKUP_ACK(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_SONIC_FRC_PWR(char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_FRC_CLR_NEED(unsigned char v1);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_SET_SWM_PWR(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_PWR_OFF2ON(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_CLR_OFF2ON(unsigned char v1);
void L1TRC_Send_EL1D_TRC_LPWR_SLP_ABNORMAL_LOCK(unsigned char v1);
void L1TRC_Send_EL1D_TRC_LPWR_TOPCG_MAIN_INFO(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11);
void L1TRC_Send_EL1D_TRC_LPWR_TOPCG_SWITCH(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_LPWR_TOPCG_MDL_TIME_PRO(unsigned char v1, long v2);
void L1TRC_Send_EL1D_TRC_LPWR_COM_MML1_CG(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_LPWR_CLKDIVCG_SET_VAL(unsigned char v1, long v2);
void L1TRC_Send_EL1D_TRC_LPWR_CLKDIVCG_FORCE(unsigned char v1);
void L1TRC_Send_EL1D_TRC_LPWR_MODONCG_SWITCH(unsigned char v1, char v2);
void L1TRC_Send_EL1D_TRC_LPWR_BRP_PM_ALLOC(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_EL1D_TRC_LPWR_FEC_PM_ALLOC(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_LPWR_SRAM1_HW_DRV(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_LPWR_SRAM2_HW_DRV_ON(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_LPWR_SRAM2_HW_DRV_OFF(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_BOOT_TRIGGER(unsigned long v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1D_TRC_BOOT_MD32_MEM_DL(unsigned char v1, char v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_BOOT_RAT_CHG_STATUS(char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_BOOT_UNGATESONIC(void);
void L1TRC_Send_EL1D_TRC_BOOT_UNGATEMD32(void);
void L1TRC_Send_EL1D_TRC_BOOT_CHECKDLSONIC(unsigned char v1);
void L1TRC_Send_EL1D_TRC_BOOT_SONICSTATUS(long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_BOOT_MD32STATUS(unsigned char v1);
void L1TRC_Send_EL1D_TRC_BOOT_MD32_FSM(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_BOOT_MD32_RESET_STA(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_BOOT_SONICCSIF(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_BOOT_DORMANT_WAKEUP(unsigned char v1);
void L1TRC_Send_EL1D_TRC_BOOT_BRP_PMDMCHECK(unsigned long v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_BOOT_ERROR(void);
void L1TRC_Send_EL1D_TRC_GDMA_HW_INT(unsigned char v1);
void L1TRC_Send_EL1D_TRC_GDMA_CH_STARTED(char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_GDMA_INIT_DMA(void);
void L1TRC_Send_EL1D_TRC_GDMA_REGISTER_DMA(char v1, char v2, unsigned long v3, unsigned long v4, short v5, short v6);
void L1TRC_Send_EL1D_TRC_GDMA_START_DMA(char v1, char v2, unsigned long v3, unsigned long v4, short v5, char v6);
void L1TRC_Send_EL1D_TRC_GDMA_START_DMA_CR4(char v1, char v2, unsigned long v3, unsigned long v4, short v5);
void L1TRC_Send_EL1D_TRC_GDMA_FREE_DMA(char v1, char v2, char v3);
void L1TRC_Send_EL1D_TRC_GDMA_MEMCMP_PARSE_OK(char v1, unsigned long v2, unsigned long v3, short v4);
void L1TRC_Send_EL1D_TRC_GDMA_MEMCMP_PARSE_FAIL(void);
void L1TRC_Send_EL1D_TRC_GDMA_MEMCMP_SAME(unsigned long v1, unsigned long v2, short v3);
void L1TRC_Send_EL1D_TRC_GDMA_MEMCMP_DIFF(unsigned long v1, unsigned long v2, short v3);
void L1TRC_Send_EL1D_TRC_32K_CAL_PARA(long v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_32K_CAL_AFCDAC(long v1, long v2);
void L1TRC_Send_EL1D_TRC_32K_CAL_AFCDAC_INFO(long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_32K_CAL_TIME_ERR(char v1, char v2);
void L1TRC_Send_EL1D_TRC_32K_CAL_TIME_ERR_INFO_1(char v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_32K_CAL_TIME_ERR_INFO_2(long v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_32K_CAL_UNSLP_CNT(void);
void L1TRC_Send_EL1D_TRC_32K_CAL_DRX_CYCLE(long v1);
void L1TRC_Send_EL1D_TRC_32K_CAL_TRIGGER(unsigned char v1);
void L1TRC_Send_EL1D_TRC_32K_CAL_REK_TIME(long v1);
void L1TRC_Send_EL1D_TRC_32K_CAL_CIR_MAX_DIFF(short v1, short v2);
void L1TRC_Send_EL1D_TRC_32K_LESS_ADJ_INFO(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_32K_LESS_PSYNC_QUERY(char v1, char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_32K_LESS_PSYNC_CALC_WO_DATA_OUT(unsigned char v1);
void L1TRC_Send_EL1D_TRC_32K_LESS_ADJ_MAP(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_32K_LESS_DSP_CMD(unsigned short v1);
void L1TRC_Send_EL1D_TRC_32K_LESS_SELF_UPDATE(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_32K_LESS_UPDATE_RULE_0(void);
void L1TRC_Send_EL1D_TRC_32K_LESS_UPDATE_RULE_1(void);
void L1TRC_Send_EL1D_TRC_32K_LESS_UPDATE_DROP(void);
void L1TRC_Send_EL1D_TRC_32K_LESS_DELAY_RPT_HANDLE(unsigned char v1);
void L1TRC_Send_EL1D_TRC_32K_LESS_DSP_RPT_ORI(long v1);
void L1TRC_Send_EL1D_TRC_32K_LESS_DSP_RPT(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_32K_LESS_DL_CHG_CMD(void);
void L1TRC_Send_EL1D_TRC_32K_LESS_DL_CHG_CMD_1(void);
void L1TRC_Send_EL1D_TRC_32K_LESS_WARNING_1(void);
void L1TRC_Send_EL1D_TRC_32K_LESS_WARNING_2(void);
void L1TRC_Send_EL1D_TRC_32K_LESS_NON_DRX(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_32K_LESS_BOUND_SCELL_FBD(void);
void L1TRC_Send_EL1D_TRC_32K_LESS_WARNING_3(void);
void L1TRC_Send_EL1D_TRC_32K_LESS_WARNING_4(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_32K_LESS_BOUND(short v1, short v2, short v3, short v4);
void L1TRC_Send_EL1D_TRC_LPWR_CIDD_BEGIN(unsigned char v1);
void L1TRC_Send_EL1D_TRC_LPWR_CIDD_END(unsigned char v1);
void L1TRC_Send_EL1D_TRC_LPWR_CIDD_QUERY_STATUS(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_LPWR_CIDD_DISABLE_PM(unsigned char v1);
void L1TRC_Send_EL1D_TRC_SUBF_HISR_ABS_TIME(short v1);
void L1TRC_Send_EL1D_TRC_UL1D_LISR_MASK_ALLOW(unsigned char v1);
void L1TRC_Send_EL1D_TRC_TIME_PRO_GENERAL(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_ELM_PROFILING(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15);
void L1TRC_Send_EL1D_TRC_CACHE_PROFILING(unsigned long v1, unsigned char v2, unsigned char v3, long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_EL1D_TRC_EL1D_IDLE_RATE(unsigned long v1, unsigned char v2, short v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);

void Set_EL1D_COMMON0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_COMMON0()	(EL1D_COMMON0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_COMMON_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_COMMON_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_M()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_M()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_SFBD_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_SFBD_M()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_SFBD_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HW_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HW_M()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HW_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_MISC_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_MISC_M()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_MISC_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_RFCC_RX_M()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_RFCC_RX_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_M()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_MISC_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_MISC_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[4]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[4]&0x20)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_L()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[4]&0x40)!=0))
#define ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()	(ChkL1ModFltr_EL1D_COMMON0()&&((EL1D_COMMON0_Trace_Filter[4]&0x80)!=0))
#define ChkL1MsgFltr_EL1D_TRC_COMMON_DBG_2()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_COMMON_H()
#define ChkL1MsgFltr_EL1D_TRC_COMMON_DBG_4()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_COMMON_H()
#define ChkL1MsgFltr_EL1D_TRC_CT_PSCELL_HUGE_FBD_DIFF()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_H()
#define ChkL1MsgFltr_EL1D_TRC_CT_GET_UNQUAL_SCELL()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_H()
#define ChkL1MsgFltr_EL1D_TRC_CT_UPDATE_FBD()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_M()
#define ChkL1MsgFltr_EL1D_TRC_CT_UPDATE_MULTIPLE_CELL_FBD()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_H()
#define ChkL1MsgFltr_EL1D_TRC_CT_MERGE_CELL()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_M()
#define ChkL1MsgFltr_EL1D_TRC_CT_C_CLR_CELL()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_M()
#define ChkL1MsgFltr_EL1D_TRC_CT_C_SET_COMMON_CFG()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_M()
#define ChkL1MsgFltr_EL1D_TRC_CT_C_SET_QUAL()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_M()
#define ChkL1MsgFltr_EL1D_TRC_CT_D_SET_SYS_CFG2()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_CT_M()
#define ChkL1MsgFltr_EL1D_TRC_TC_HRT_TIME()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_H()
#define ChkL1MsgFltr_EL1D_TRC_TC_HRT_TIME_FAIL()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_H()
#define ChkL1MsgFltr_EL1D_TRC_TC_HRT_RECORD()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_L()
#define ChkL1MsgFltr_EL1D_TRC_TC_DSP_HRT_MARGIN()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_H()
#define ChkL1MsgFltr_EL1D_TRC_TC_PHY_SCNT()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_M()
#define ChkL1MsgFltr_EL1D_TRC_TC_FRC()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_L()
#define ChkL1MsgFltr_EL1D_TRC_TC_IRQ_PHYTIME()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_L()
#define ChkL1MsgFltr_EL1D_TRC_TC_EL1CD_HRT()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HRT_H()
#define ChkL1MsgFltr_EL1D_TRC_TC_SFBD()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_SFBD_M()
#define ChkL1MsgFltr_EL1D_TRC_TC_SFBD_SHIFT()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_SFBD_L()
#define ChkL1MsgFltr_EL1D_TRC_TC_CALC_UNQUAL_SCELL()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_SFBD_H()
#define ChkL1MsgFltr_EL1D_TRC_TC_UPDATE_CIR_MAX()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_SFBD_L()
#define ChkL1MsgFltr_EL1D_TRC_TC_UPDATE_CIR_LEN()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_SFBD_L()
#define ChkL1MsgFltr_EL1D_TRC_TC_TX_TIMING()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_SFBD_L()
#define ChkL1MsgFltr_EL1D_TRC_TC_CIR_MAX_ALIGN()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_SFBD_M()
#define ChkL1MsgFltr_EL1D_TRC_TC_UPDATE_MSTA()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_TC_WAKEUP_PHY_TIME()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_TC_SLP_DUR()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_TC_HW_STOP_START_DUR()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_TC_HW_STOP_START_FWS()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_MISC_M()
#define ChkL1MsgFltr_EL1D_TRC_TC_HW_STOP_START_LOCK()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_MISC_M()
#define ChkL1MsgFltr_EL1D_TRC_TC_IS_3G_U_CONN_BY_UL1D()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_TC_HW_SONIC_BOOT_DONE()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HW_M()
#define ChkL1MsgFltr_EL1D_TRC_TC_HW_SET_DL_RR()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HW_L()
#define ChkL1MsgFltr_EL1D_TRC_TC_HW_DUMP_DL_RR()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HW_L()
#define ChkL1MsgFltr_EL1D_TRC_TC_HW_DISABLE_IRQ()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_TC_HW_M()
#define ChkL1MsgFltr_EL1D_TRC_RFCC_RX_MOD_CMD_BMP()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_RFCC_RX_L()
#define ChkL1MsgFltr_EL1D_TRC_RFCC_RX_RAW_EXE_LIST()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_RFCC_RX_M()
#define ChkL1MsgFltr_EL1D_TRC_RFCC_RX_FIN_EXE_LIST()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_RFCC_RX_M()
#define ChkL1MsgFltr_EL1D_TRC_RFCC_RX_RFD_BASIC_CFG()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_RFCC_RX_L()
#define ChkL1MsgFltr_EL1D_TRC_RFCC_RX_AGC_RF_ON()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_RFCC_RX_M()
#define ChkL1MsgFltr_EL1D_TRC_RFCC_RX_EXPIRE_CHK_ERR()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_RFCC_RX_M()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_MAIN_INFO()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_MAIN_ACTION()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_MAIN_INFO()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_RX_ON()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_RX_OFF()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_CSI_ON()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_CSI_OFF()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_OCIC_SWITCH()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_ACTWIN_ON()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_ACTWIN_OFF()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_CHK_RX_IDLE()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_RX_GEAR_RELATED_INFO()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_MBPBCH_ON()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_MBPBCH_OFF()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_MINWIN_ONTIME()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_MINWIN_OFFTIME()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_DBG()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_DVFS_LOCK_OFF()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_DVFS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_ABORT_DSP()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_M()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_DSP_IDLE_FLAG()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_L()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_DSP_BACKUP()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_M()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_DSP_BACKUP_ACK()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_M()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_SONIC_FRC_PWR()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_L()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_FRC_CLR_NEED()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_SET_SWM_PWR()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_PWR_OFF2ON()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_CLR_OFF2ON()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_L()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SLP_ABNORMAL_LOCK()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_TOPCG_MAIN_INFO()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_M()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_TOPCG_SWITCH()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_L()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_TOPCG_MDL_TIME_PRO()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_L()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_COM_MML1_CG()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_CLKDIVCG_SET_VAL()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_L()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_CLKDIVCG_FORCE()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_M()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_MODONCG_SWITCH()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_M()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_BRP_PM_ALLOC()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_FEC_PM_ALLOC()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SRAM1_HW_DRV()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_L()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SRAM2_HW_DRV_ON()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_M()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_SRAM2_HW_DRV_OFF()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_M()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_TRIGGER()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_MD32_MEM_DL()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_RAT_CHG_STATUS()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_UNGATESONIC()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_UNGATEMD32()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_CHECKDLSONIC()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_SONICSTATUS()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_MD32STATUS()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_MD32_FSM()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_MD32_RESET_STA()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_SONICCSIF()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_DORMANT_WAKEUP()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_BRP_PMDMCHECK()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_BOOT_ERROR()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_BOOT_H()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_HW_INT()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_H()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_CH_STARTED()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_H()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_INIT_DMA()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_L()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_REGISTER_DMA()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_L()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_START_DMA()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_L()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_START_DMA_CR4()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_L()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_FREE_DMA()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_L()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_MEMCMP_PARSE_OK()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_L()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_MEMCMP_PARSE_FAIL()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_L()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_MEMCMP_SAME()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_L()
#define ChkL1MsgFltr_EL1D_TRC_GDMA_MEMCMP_DIFF()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_GDMA_L()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_PARA()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_L()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_AFCDAC()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_AFCDAC_INFO()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_L()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_TIME_ERR()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_TIME_ERR_INFO_1()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_L()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_TIME_ERR_INFO_2()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_UNSLP_CNT()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_DRX_CYCLE()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_TRIGGER()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_REK_TIME()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_CAL_CIR_MAX_DIFF()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_L()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_ADJ_INFO()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_PSYNC_QUERY()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_PSYNC_CALC_WO_DATA_OUT()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_ADJ_MAP()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_DSP_CMD()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_SELF_UPDATE()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_UPDATE_RULE_0()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_UPDATE_RULE_1()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_UPDATE_DROP()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_DELAY_RPT_HANDLE()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_DSP_RPT_ORI()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_DSP_RPT()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_DL_CHG_CMD()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_DL_CHG_CMD_1()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_WARNING_1()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_WARNING_2()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_NON_DRX()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_BOUND_SCELL_FBD()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_WARNING_3()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_WARNING_4()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_32K_LESS_BOUND()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_32K_LESS_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_CIDD_BEGIN()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_CIDD_END()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_CIDD_QUERY_STATUS()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_LPWR_CIDD_DISABLE_PM()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_LPWR_H()
#define ChkL1MsgFltr_EL1D_TRC_SUBF_HISR_ABS_TIME()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_UL1D_LISR_MASK_ALLOW()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_TIME_PRO_GENERAL()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_ELM_PROFILING()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_MISC_L()
#define ChkL1MsgFltr_EL1D_TRC_CACHE_PROFILING()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_MISC_H()
#define ChkL1MsgFltr_EL1D_TRC_EL1D_IDLE_RATE()	ChkL1ClsFltr_EL1D_COMMON0_EL1D_TRC_CLS_MISC_L()


#endif
