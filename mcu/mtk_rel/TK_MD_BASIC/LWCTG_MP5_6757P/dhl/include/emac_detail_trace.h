#ifndef L1TRC_EMAC_DETAIL_DEF_H
#define L1TRC_EMAC_DETAIL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TIMER_START(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0008 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_TIMER_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_OUT_RANGE(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x0108 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_OUT_RANGE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_MCE_IGNORE(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x0208 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_MCE_IGNORE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PDCCH_VALID(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x0308 | ((unsigned short)(v3) << 16), (kal_uint32)((unsigned char)(v1)) | (((kal_uint32)((unsigned char)(v2))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_PDCCH_VALID(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH_TX_INFO(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0408 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH_TX_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PRACH_INFO(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0508 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_PRACH_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PRACH_INFO_BY_PDCCH(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0608 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_PRACH_INFO_BY_PDCCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CAL_CR_TIMER(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0708 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_CAL_CR_TIMER(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_INFO_REQ(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x0808 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_INFO_REQ(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PRACH_TX_INFO_REQ(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0908 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_PRACH_TX_INFO_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_MSG3_HARQ_RELOAD_UPD(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x0A08 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_MSG3_HARQ_RELOAD_UPD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_SAVE_MSG3_HWB(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x0B08 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_SAVE_MSG3_HWB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_DEFER_FIRST_TX_QUERY() do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x0C08 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_DEFER_FIRST_TX_QUERY()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAPID_MISMATCH_DUMP(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x0D08 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAPID_MISMATCH_DUMP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAPID_SHIFT_REPORT(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x0E08 | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAPID_SHIFT_REPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RNTI_MISSING(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0F08 | ((unsigned short)(v3) << 16), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_RNTI_MISSING(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_RA_INFO_NTF_EL1(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1008 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_CFG_RA_INFO_NTF_EL1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_UL_PARA_NTF_EL1(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x1108 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_CFG_UL_PARA_NTF_EL1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_BUNDLING_INVALID(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x1208 | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CFG_BUNDLING_INVALID(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_FDD_TDD_UDC(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1308 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((char)(v2))) << 24), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CFG_FDD_TDD_UDC(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_GET_HARQ(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1408 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_GET_HARQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_TTI_GET_HARQ(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1508 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_TTI_GET_HARQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_REQ_DATA(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x1608 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_REQ_DATA(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CE_CRNTI(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x1708 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CE_CRNTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CE_LBSR(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x1808 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CE_LBSR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CE_SBSR(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x1908 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CE_SBSR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CE_PHR(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1A08 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_CE_PHR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_STATUS_IND(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x1B08 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_STATUS_IND(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DATA_REQ(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1C08 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)((char)(v2))) << 16) | (((kal_uint32)((char)(v3))) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_DATA_REQ(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DATA_REQ2(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1D08 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_DATA_REQ2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CLOSS_SSID(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x1E08 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CLOSS_SSID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CLR_TX_TL(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1F08 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_CLR_TX_TL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_SET_TX_TL(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x2008 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_SET_TX_TL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DUP_RETX_INFO(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x2108 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_DUP_RETX_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_VALUE_FILL(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x2208 | ((unsigned short)(v2) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_PHR_VALUE_FILL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_EPHR_VALUE_FILL(v1, v2, v3, v4, v5, v6) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x2308 | ((unsigned short)(v5) << 16), (kal_uint32)((unsigned short)(v6)) | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24), (kal_uint32)((unsigned char)(v3)) | (((kal_uint32)((unsigned char)(v4))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_EPHR_VALUE_FILL(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_BSR_RETX_TMR_START(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x2408 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_BSR_RETX_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_BSR_PERI_TMR_START(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x2508 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_BSR_PERI_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_BSR_INCLUDE(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2608 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_BSR_INCLUDE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_BSR_TRIGGER(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x2708 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_BSR_TRIGGER(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_BSR_LCG_STATUS(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2808 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_BSR_LCG_STATUS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_SET_LONG_BSR(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_5_word(0x2908 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_SET_LONG_BSR(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_SET_SHORT_BSR(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2A08 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_SET_SHORT_BSR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_SET_TRU_BSR(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x2B08 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_SET_TRU_BSR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RETX_INFO1(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x2C08 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_RETX_INFO1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RETX_INFO2(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x2D08 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_RETX_INFO2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_HT(v1, v2, v3, v4, v5) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2E08 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)((unsigned short)(v5))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_HT(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EAMC_LOG_DL_ASSIGNMENT(v1, v2, v3, v4, v5) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2F08 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)((unsigned short)(v4))) << 16), (kal_uint32)((unsigned short)(v5)) | (((kal_uint32)((char)(v2))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EAMC_LOG_DL_ASSIGNMENT(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SWO(v1, v2, v3, v4, v5) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x3008 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)((unsigned short)(v5))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_SWO(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_1ST_HARQ_TX_TIME(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x3108 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_1ST_HARQ_TX_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_HT_SCELL_DEACT(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x3208 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DL_HT_SCELL_DEACT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UST_RESET_INIT(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x3308 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UST_RESET_INIT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UST_UPDATE(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x3408 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UST_UPDATE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UST_DIFF(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x3508 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UST_DIFF(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CA_SCELL_DEACT_TMR_START(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x3608 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_CA_SCELL_DEACT_TMR_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CA_SCELL_DEACT_TMR_STOP(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x3708 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CA_SCELL_DEACT_TMR_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CA_SCELL_DEACT_TMR_EXPIRE(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x3808 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CA_SCELL_DEACT_TMR_EXPIRE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CA_SCELL_NOTIFY_EL1(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x3908 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_CA_SCELL_NOTIFY_EL1(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CA_SCELL_ACT_DEACT_BITMAP(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x3A08 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CA_SCELL_ACT_DEACT_BITMAP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CA_SCELL_DEACT_BY_THERMAL(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x3B08 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CA_SCELL_DEACT_BY_THERMAL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CA_SCELL_RESUME_BY_THERMAL() do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x3C08 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CA_SCELL_RESUME_BY_THERMAL()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_EVA_N5_DRX_STATUS(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x3D08 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_EVA_N5_DRX_STATUS(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_EVA_N5_DRX_CMD_STATUS(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x3E08 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_EVA_N5_DRX_CMD_STATUS(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_N5_DRX_CMD_STATUS(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x3F08 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_N5_DRX_CMD_STATUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_POSSIBLE_LAST_ACT_SF(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x4008 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_POSSIBLE_LAST_ACT_SF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_STATUS(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x4108 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)((char)(v4))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_STATUS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_TIME_TO_DL_HARQ(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x4208 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_TIME_TO_DL_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_TIME_TO_UL_HARQ(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x4308 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_TIME_TO_UL_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_TIME_TO_UL_HARQ_PDCCH(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x4408 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_TIME_TO_UL_HARQ_PDCCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_TIME_TO_PDCCH(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x4508 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_TIME_TO_PDCCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_TIME_TO_UL_GRANT(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x4608 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_TIME_TO_UL_GRANT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_TIME_TO_RTT_TMR(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x4708 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_TIME_TO_RTT_TMR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_HOST_WAKEUP(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x4808 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_HOST_WAKEUP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_DRX_LOG_UPDATE_T_PDCCH(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x4908 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_DRX_LOG_UPDATE_T_PDCCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SR_UPDATE_WAKE_TIME(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x4A08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SR_UPDATE_WAKE_TIME(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_DL_HARQ_UPDATE_WAKE_TIME(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x4B08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_DL_HARQ_UPDATE_WAKE_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UL_HARQ_UPDATE_WAKE_TIME(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x4C08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UL_HARQ_UPDATE_WAKE_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CANCEL_DRX_RETX_TIMER(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x4D08 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CANCEL_DRX_RETX_TIMER(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UL_HARQ_PDCCH_UPDATE_WAKE_TIME(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x4E08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UL_HARQ_PDCCH_UPDATE_WAKE_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SPS_UPDATE_WAKE_TIME(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x4F08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SPS_UPDATE_WAKE_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_WAKE_DRX_CYCLE(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x5008 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_WAKE_DRX_CYCLE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CHANGE_SLP_STATUS(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x5108 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CHANGE_SLP_STATUS(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INIT_RECONFIG_INACT_TMR_OPER(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x5208 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INIT_RECONFIG_INACT_TMR_OPER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_MSG3_PHICH_TMR_START(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x5308 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_MSG3_PHICH_TMR_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_RTT_RETX_OPER_BUT_DL_HARQ_NUM_ZERO(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x5408 | ((unsigned short)(v3) << 16), (kal_uint32)((unsigned char)(v1)) | (((kal_uint32)((unsigned char)(v2))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_RTT_RETX_OPER_BUT_DL_HARQ_NUM_ZERO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SKIP_ACKED_RETX_WAKE(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x5508 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SKIP_ACKED_RETX_WAKE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_GAP_SBP_OFF(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x5608 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_GAP_SBP_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_GAP_IGNORE(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x5708 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_GAP_IGNORE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_GAP_RCV_START(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x5808 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_GAP_RCV_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_GAP_DUP_START(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x5908 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_GAP_DUP_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_GAP_RCV_END(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x5A08 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_GAP_RCV_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_GAP_TMR_EXP(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x5B08 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_GAP_TMR_EXP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_GAP_DRX_SUS(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x5C08 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_GAP_DRX_SUS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_GAP_RCV_END_AFT(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x5D08 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_GAP_RCV_END_AFT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_GAP_TMR_START(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x5E08 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_GAP_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_RESUME(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x5F08 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_RESUME(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_INJECT_GAP(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x6008 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_INJECT_GAP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_HARQ_CLOSE(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x6108 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_HARQ_CLOSE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_ACK_IN_GAP(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x6208 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_ACK_IN_GAP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INC_NACK_IN_GAP(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x6308 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INC_NACK_IN_GAP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_MAX_IF_ACKED(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x6408 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24), (kal_uint32)((unsigned char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_MAX_IF_ACKED(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_SUSPEND_DRX(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x6508 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_SUSPEND_DRX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_WAIT_TX_READY(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x6608 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_SR_WAIT_TX_READY(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CHK_WAKE(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x6708 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CHK_WAKE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CHK_WAKE_DELAY() do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x6808 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CHK_WAKE_DELAY()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RESERVE_GRANT(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x6908 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_RESERVE_GRANT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CLOSE_RESV_HARQ(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x6A08 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CLOSE_RESV_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_SCH_RESV_ADP_RETX(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x6B08 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_SCH_RESV_ADP_RETX(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_SCH_RESV_NON_ADP_RETX(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x6C08 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_SCH_RESV_NON_ADP_RETX(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_REQ_IN_GEMINI_GAP(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x6D08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_REQ_IN_GEMINI_GAP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_PDCCH_MAY_BE_IN_GAP(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x6E08 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_PDCCH_MAY_BE_IN_GAP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SIM_GAP_START(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x6F08 | ((unsigned short)(v2) << 16), (unsigned long)(v1), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_SIM_GAP_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SIM_GAP_IN_GAP(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x7008 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_SIM_GAP_IN_GAP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_GAP_STATE(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x7108 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_GAP_STATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_GEMINI_GAP_RX_START(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x7208 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_GEMINI_GAP_RX_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_GEMINI_GAP_RX_END(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x7308 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_GEMINI_GAP_RX_END(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_SET_GEMINI_PHICH(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x7408 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_SET_GEMINI_PHICH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_GAP_FORCE_BSR(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x7508 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_GAP_FORCE_BSR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_JUDGE_RETX_MODE(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x7608 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_JUDGE_RETX_MODE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_TX_SKIP_FOR_GAP(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x7708 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_TX_SKIP_FOR_GAP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_UPDATE_G_GAP(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x7808 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_UPDATE_G_GAP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_SKIP_FOR_G_GAP(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x7908 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_SKIP_FOR_G_GAP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_NOT_SKIP_LONG_GAP(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x7A08 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_NOT_SKIP_LONG_GAP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_NOT_SKIP_TX_NB(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x7B08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_TX_NOT_SKIP_TX_NB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DISABLE_PHICH(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x7C08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_TX_DISABLE_PHICH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DISABLE_PHICH_BUNDLING(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x7D08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_DISABLE_PHICH_BUNDLING(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_GEMINI_ALIGNED_GAP_TIME(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x7E08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_TX_GEMINI_ALIGNED_GAP_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_GEMINI_SIM_RESULT(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x7F08 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_GEMINI_SIM_RESULT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_PHICH_FORCE_ACK(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x8008 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_PHICH_FORCE_ACK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_REPORT(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x8108 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_REPORT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_CALLON(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x8208 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_CALLON(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_CALLOFF(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x8308 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_CALLOFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_REPORT_TIMING(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x8408 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_REPORT_TIMING(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_RB_STATUS(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x8508 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_RB_STATUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_PREDICTION(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x8608 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_PREDICTION(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_NOT_WAKEUP(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x8708 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_NOT_WAKEUP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_PREDICTION_HIT(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x8808 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_PREDICTION_HIT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_VSR_COVER(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x8908 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_VSR_COVER(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_USING_VSR(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x8A08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_USING_VSR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_VSR_CFG(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x8B08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_VSR_CFG(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UPDATE_WAKEUP(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x8C08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UPDATE_WAKEUP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UPDATE_RX_TIME(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x8D08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UPDATE_RX_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CHECK_SR_WAKEUP(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x8E08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CHECK_SR_WAKEUP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_MODIFY_CAUSE(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x8F08 | (((kal_uint32)((char)(v3))) << 16) | (((kal_uint32)((char)(v4))) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_MODIFY_CAUSE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_VOLTE_SET_SILENCE(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x9008 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_VOLTE_SET_SILENCE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_PN_SCRM_PADDING(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x9108 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_PN_SCRM_PADDING(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_CFG_CLOSE_MCCH(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x9208 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_CFG_CLOSE_MCCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_CFG_CLOSE_MRB(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x9308 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_CFG_CLOSE_MRB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_CFG_OPEN_MCCH(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x9408 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_CFG_OPEN_MCCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_CFG_OPEN_MRB(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x9508 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_CFG_OPEN_MRB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_CFG_CLOSE_MLT(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x9608 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_CFG_CLOSE_MLT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_CFG_OPEN_MLT(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x9708 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_CFG_OPEN_MLT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_SEND_MSI_NTF(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x9808 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_SEND_MSI_NTF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_SWAP_IDX_TBL(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x9908 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_SWAP_IDX_TBL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_SWO(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x9A08 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_SWO(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_MOT(v1, v2, v3, v4, v5) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_5_word(0x9B08 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_MOT(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_MOT_2(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x9C08 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_MOT_2(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_DATA_IND(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_5_word(0x9D08 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_DATA_IND(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_INVALID_PMCH(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x9E08 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_INVALID_PMCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_MSI_SIZE_ODD(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x9F08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_MSI_SIZE_ODD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_MSI_NEW_ENTRY(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0xA008 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_MSI_NEW_ENTRY(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_MSI_EXTEND_LAST(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0xA108 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_MSI_EXTEND_LAST(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_MSI_LCID_INFO(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0xA208 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_MSI_LCID_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_MSI_IGNORE(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0xA308 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_MSI_IGNORE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_MSI_IGNORE_NO_PMCH(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0xA408 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_MSI_IGNORE_NO_PMCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_ONLY_PADDING(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0xA508 | ((unsigned short)(v3) << 16), (kal_uint32)((unsigned char)(v1)) | (((kal_uint32)((unsigned char)(v2))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_ONLY_PADDING(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CLOSE_INVALID_SSID(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xA608 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CLOSE_INVALID_SSID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_BYPASS_DRX_CONFIG(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xA708 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_BYPASS_DRX_CONFIG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PROBING_REQUEST(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xA808 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_PROBING_REQUEST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PROBING_TRIGGER_RA() do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xA908 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_PROBING_TRIGGER_RA()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PROBING_REQUEST_COLLISION(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0xAA08 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_PROBING_REQUEST_COLLISION(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RX_LMAC_RELEASE_HT(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xAB08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RX_LMAC_RELEASE_HT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_POWER_OFF() do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xAC08 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_POWER_OFF()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SLP_CNF_1(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0xAD08 | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)((char)(v2))) << 24), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SLP_CNF_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SLP_CNF_2(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xAE08 | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)((char)(v2))) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SLP_CNF_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PENDING_HOST_DATA_REQ() do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xAF08 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_PENDING_HOST_DATA_REQ()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SPS_UNSYNC_ERROR(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0xB008 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_SPS_UNSYNC_ERROR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SPS_WHEN_DISABLE(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xB108 | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DL_SPS_WHEN_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_ENABLE(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xB208 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_DISABLE(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xB308 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_RRC_PROHIBIT_TIME(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0xB408 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_RRC_PROHIBIT_TIME(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_NAS_PROHIBIT_TIME(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0xB508 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_NAS_PROHIBIT_TIME(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_RCV_UL_DL(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0xB608 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24), (kal_uint32)((unsigned char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_RCV_UL_DL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_NOT_SLEEP(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0xB708 | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_NOT_SLEEP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_SRB_UNACKED_NOT_SLEEP(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0xB808 | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_SRB_UNACKED_NOT_SLEEP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_TA_NOT_SLEEP(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0xB908 | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_TA_NOT_SLEEP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_SLEEP(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0xBA08 | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_SLEEP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_SEND_CYC_NTF(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0xBB08 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_SEND_CYC_NTF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_SLEEP_STATUS(v1, v2, v3, v4) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0xBC08 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_SLEEP_STATUS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_STATUS(v1, v2) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0xBD08 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_STATUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_RCV_UL_IN_SLEEP(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xBE08 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_RCV_UL_IN_SLEEP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_RCV_RRC_PROHIBIT_CMD(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0xBF08 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_RCV_RRC_PROHIBIT_CMD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_RCV_NAS_PROHIBIT_CMD(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0xC008 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_RCV_NAS_PROHIBIT_CMD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_RCV_PDCP_TMR_EXP(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xC108 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_RCV_PDCP_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_RCV_PDCP_TMR_RESTR(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xC208 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_RCV_PDCP_TMR_RESTR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_UPDATE_SLP_TIME(v1, v2, v3) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0xC308 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_UPDATE_SLP_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_REPORT_RRC_SLP_TIME(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0xC408 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_REPORT_RRC_SLP_TIME(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_AUDRX_PDCCH_RA_IN_SLEEP(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xC508 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_AUDRX_PDCCH_RA_IN_SLEEP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_IGNORE_TDM_VM_RA(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xC608 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_IGNORE_TDM_VM_RA(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH_COL_VM_RA(v1) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0xC708 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH_COL_VM_RA(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RSIM_DEBUG(v1, v2, v3, v4, v5) do {\
		if(EMAC_DETAIL_Trace_Filter[0]==1 && (EMAC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0xC808 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)((unsigned short)(v5))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RSIM_DEBUG(v1, v2, v3, v4, v5)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EMAC_DETAIL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EMAC_LOG_TIMER_START(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_TA_OUT_RANGE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_MCE_IGNORE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_PDCCH_VALID(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_RA_PDCCH_TX_INFO(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_PRACH_INFO(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_PRACH_INFO_BY_PDCCH(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_CAL_CR_TIMER(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_RAR_INFO_REQ(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_RA_PRACH_TX_INFO_REQ(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_MSG3_HARQ_RELOAD_UPD(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_SAVE_MSG3_HWB(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_DEFER_FIRST_TX_QUERY(void);
void L1TRC_Send_EMAC_LOG_RA_RAPID_MISMATCH_DUMP(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_RAPID_SHIFT_REPORT(char v1);
void L1TRC_Send_EMAC_LOG_RA_RNTI_MISSING(unsigned long v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_CFG_RA_INFO_NTF_EL1(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_CFG_UL_PARA_NTF_EL1(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_CFG_BUNDLING_INVALID(char v1, unsigned char v2);
void L1TRC_Send_EMAC_LOG_CFG_FDD_TDD_UDC(unsigned char v1, char v2, char v3);
void L1TRC_Send_EMAC_LOG_TX_GET_HARQ(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_TTI_GET_HARQ(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_REQ_DATA(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_TX_CE_CRNTI(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_CE_LBSR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_CE_SBSR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_CE_PHR(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_TX_STATUS_IND(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_TX_DATA_REQ(unsigned short v1, char v2, char v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_TX_DATA_REQ2(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_TX_CLOSS_SSID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_CLR_TX_TL(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_SET_TX_TL(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_DUP_RETX_INFO(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_PHR_VALUE_FILL(unsigned char v1, unsigned short v2, short v3);
void L1TRC_Send_EMAC_LOG_EPHR_VALUE_FILL(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_EMAC_LOG_BSR_RETX_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_BSR_PERI_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_BSR_INCLUDE(unsigned short v1, char v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_BSR_TRIGGER(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_BSR_LCG_STATUS(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_TX_SET_LONG_BSR(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_TX_SET_SHORT_BSR(unsigned short v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_TX_SET_TRU_BSR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_RETX_INFO1(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_TX_RETX_INFO2(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_DL_HT(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EAMC_LOG_DL_ASSIGNMENT(unsigned short v1, char v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EMAC_LOG_DL_SWO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EMAC_LOG_DL_1ST_HARQ_TX_TIME(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_DL_HT_SCELL_DEACT(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_UST_RESET_INIT(short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_UST_UPDATE(short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_UST_DIFF(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_CA_SCELL_DEACT_TMR_START(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_CA_SCELL_DEACT_TMR_STOP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CA_SCELL_DEACT_TMR_EXPIRE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CA_SCELL_NOTIFY_EL1(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_CA_SCELL_ACT_DEACT_BITMAP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CA_SCELL_DEACT_BY_THERMAL(unsigned short v1, unsigned short v2);
void L1TRC_Send_EMAC_LOG_CA_SCELL_RESUME_BY_THERMAL(void);
void L1TRC_Send_EMAC_LOG_DRX_EVA_N5_DRX_STATUS(unsigned short v1, char v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_EVA_N5_DRX_CMD_STATUS(unsigned short v1, char v2, char v3);
void L1TRC_Send_EMAC_LOG_DRX_N5_DRX_CMD_STATUS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_DRX_POSSIBLE_LAST_ACT_SF(unsigned short v1, unsigned long v2, char v3);
void L1TRC_Send_EMAC_LOG_DRX_STATUS(short v1, char v2, char v3, char v4);
void L1TRC_Send_EMAC_LOG_DRX_TIME_TO_DL_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_TIME_TO_UL_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_TIME_TO_UL_HARQ_PDCCH(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_TIME_TO_PDCCH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_TIME_TO_UL_GRANT(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_TIME_TO_RTT_TMR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_HOST_WAKEUP(unsigned short v1, char v2, unsigned long v3);
void L1TRC_Send_EMAC_DRX_LOG_UPDATE_T_PDCCH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_SR_UPDATE_WAKE_TIME(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DRX_DL_HARQ_UPDATE_WAKE_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_UL_HARQ_UPDATE_WAKE_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_CANCEL_DRX_RETX_TIMER(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_UL_HARQ_PDCCH_UPDATE_WAKE_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_SPS_UPDATE_WAKE_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_WAKE_DRX_CYCLE(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_CHANGE_SLP_STATUS(unsigned short v1, char v2, char v3);
void L1TRC_Send_EMAC_LOG_DRX_INIT_RECONFIG_INACT_TMR_OPER(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_MSG3_PHICH_TMR_START(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_RTT_RETX_OPER_BUT_DL_HARQ_NUM_ZERO(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_DRX_SKIP_ACKED_RETX_WAKE(unsigned char v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_INC_GAP_SBP_OFF(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INC_GAP_IGNORE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INC_GAP_RCV_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INC_GAP_DUP_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INC_GAP_RCV_END(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INC_GAP_TMR_EXP(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_INC_GAP_DRX_SUS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INC_GAP_RCV_END_AFT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INC_GAP_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INC_RESUME(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INC_INJECT_GAP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INC_HARQ_CLOSE(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_INC_ACK_IN_GAP(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_INC_NACK_IN_GAP(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_TX_MAX_IF_ACKED(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EMAC_LOG_SR_SUSPEND_DRX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_WAIT_TX_READY(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_CHK_WAKE(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_CHK_WAKE_DELAY(void);
void L1TRC_Send_EMAC_LOG_TX_RESERVE_GRANT(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_CLOSE_RESV_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_SCH_RESV_ADP_RETX(unsigned short v1, unsigned long v2, char v3);
void L1TRC_Send_EMAC_LOG_TX_SCH_RESV_NON_ADP_RETX(unsigned short v1, unsigned long v2, char v3);
void L1TRC_Send_EMAC_LOG_TX_REQ_IN_GEMINI_GAP(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_TX_PDCCH_MAY_BE_IN_GAP(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_SIM_GAP_START(unsigned long v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_SIM_GAP_IN_GAP(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_GAP_STATE(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_GEMINI_GAP_RX_START(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_GEMINI_GAP_RX_END(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_SET_GEMINI_PHICH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_GAP_FORCE_BSR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_JUDGE_RETX_MODE(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_TX_SKIP_FOR_GAP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_UPDATE_G_GAP(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_TX_SKIP_FOR_G_GAP(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_TX_NOT_SKIP_LONG_GAP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_NOT_SKIP_TX_NB(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_TX_DISABLE_PHICH(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_TX_DISABLE_PHICH_BUNDLING(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_TX_GEMINI_ALIGNED_GAP_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_TX_GEMINI_SIM_RESULT(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_TX_PHICH_FORCE_ACK(unsigned short v1, unsigned short v2);
void L1TRC_Send_EMAC_LOG_VOLTE_REPORT(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_VOLTE_CALLON(unsigned short v1);
void L1TRC_Send_EMAC_LOG_VOLTE_CALLOFF(unsigned short v1);
void L1TRC_Send_EMAC_LOG_VOLTE_REPORT_TIMING(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_VOLTE_RB_STATUS(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_VOLTE_PREDICTION(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_VOLTE_NOT_WAKEUP(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_VOLTE_PREDICTION_HIT(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_VOLTE_VSR_COVER(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_VOLTE_USING_VSR(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_VOLTE_VSR_CFG(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DRX_UPDATE_WAKEUP(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_UPDATE_RX_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_CHECK_SR_WAKEUP(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_MODIFY_CAUSE(unsigned long v1, unsigned long v2, char v3, char v4);
void L1TRC_Send_EMAC_LOG_VOLTE_SET_SILENCE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_PN_SCRM_PADDING(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_MBMS_CFG_CLOSE_MCCH(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_MBMS_CFG_CLOSE_MRB(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_MBMS_CFG_OPEN_MCCH(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_MBMS_CFG_OPEN_MRB(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_MBMS_CFG_CLOSE_MLT(short v1);
void L1TRC_Send_EMAC_LOG_MBMS_CFG_OPEN_MLT(short v1);
void L1TRC_Send_EMAC_LOG_MBMS_SEND_MSI_NTF(short v1);
void L1TRC_Send_EMAC_LOG_MBMS_SWAP_IDX_TBL(short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_MBMS_SWO(short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_MBMS_MOT(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EMAC_LOG_MBMS_MOT_2(short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_MBMS_DATA_IND(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_MBMS_INVALID_PMCH(unsigned long v1);
void L1TRC_Send_EMAC_LOG_MBMS_MSI_SIZE_ODD(short v1);
void L1TRC_Send_EMAC_LOG_MBMS_MSI_NEW_ENTRY(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_MBMS_MSI_EXTEND_LAST(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_MBMS_MSI_LCID_INFO(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_MBMS_MSI_IGNORE(short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_MBMS_MSI_IGNORE_NO_PMCH(short v1);
void L1TRC_Send_EMAC_LOG_MBMS_ONLY_PADDING(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_TX_CLOSE_INVALID_SSID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_BYPASS_DRX_CONFIG(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PROBING_REQUEST(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PROBING_TRIGGER_RA(void);
void L1TRC_Send_EMAC_LOG_RA_PROBING_REQUEST_COLLISION(unsigned short v1, unsigned short v2);
void L1TRC_Send_EMAC_LOG_RX_LMAC_RELEASE_HT(short v1);
void L1TRC_Send_EMAC_LOG_TX_POWER_OFF(void);
void L1TRC_Send_EMAC_LOG_DRX_SLP_CNF_1(char v1, char v2, char v3);
void L1TRC_Send_EMAC_LOG_DRX_SLP_CNF_2(char v1, char v2);
void L1TRC_Send_EMAC_LOG_PENDING_HOST_DATA_REQ(void);
void L1TRC_Send_EMAC_LOG_SPS_UNSYNC_ERROR(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DL_SPS_WHEN_DISABLE(char v1);
void L1TRC_Send_EMAC_LOG_AUDRX_ENABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_AUDRX_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_AUDRX_RRC_PROHIBIT_TIME(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_AUDRX_NAS_PROHIBIT_TIME(unsigned long v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_AUDRX_RCV_UL_DL(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_AUDRX_NOT_SLEEP(char v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_AUDRX_SRB_UNACKED_NOT_SLEEP(char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_AUDRX_TA_NOT_SLEEP(char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_AUDRX_SLEEP(char v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_AUDRX_SEND_CYC_NTF(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_AUDRX_SLEEP_STATUS(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_AUDRX_STATUS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_AUDRX_RCV_UL_IN_SLEEP(unsigned char v1);
void L1TRC_Send_EMAC_LOG_AUDRX_RCV_RRC_PROHIBIT_CMD(unsigned long v1);
void L1TRC_Send_EMAC_LOG_AUDRX_RCV_NAS_PROHIBIT_CMD(unsigned long v1);
void L1TRC_Send_EMAC_LOG_AUDRX_RCV_PDCP_TMR_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_AUDRX_RCV_PDCP_TMR_RESTR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_AUDRX_UPDATE_SLP_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_AUDRX_REPORT_RRC_SLP_TIME(unsigned long v1);
void L1TRC_Send_EMAC_LOG_AUDRX_PDCCH_RA_IN_SLEEP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_IGNORE_TDM_VM_RA(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PDCCH_COL_VM_RA(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RSIM_DEBUG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);

void Set_EMAC_DETAIL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EMAC_DETAIL()	(EMAC_DETAIL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EMAC_DETAIL_EMAC_FUNC()	(ChkL1ModFltr_EMAC_DETAIL()&&((EMAC_DETAIL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EMAC_DETAIL_EMAC_BRANCH()	(ChkL1ModFltr_EMAC_DETAIL()&&((EMAC_DETAIL_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()	(ChkL1ModFltr_EMAC_DETAIL()&&((EMAC_DETAIL_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()	(ChkL1ModFltr_EMAC_DETAIL()&&((EMAC_DETAIL_Trace_Filter[1]&0x08)!=0))
#define ChkL1MsgFltr_EMAC_LOG_TIMER_START()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_FUNC()
#define ChkL1MsgFltr_EMAC_LOG_TA_OUT_RANGE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_MCE_IGNORE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PDCCH_VALID()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH_TX_INFO()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PRACH_INFO()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PRACH_INFO_BY_PDCCH()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CAL_CR_TIMER()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_INFO_REQ()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PRACH_TX_INFO_REQ()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_MSG3_HARQ_RELOAD_UPD()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_SAVE_MSG3_HWB()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_DEFER_FIRST_TX_QUERY()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAPID_MISMATCH_DUMP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAPID_SHIFT_REPORT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RNTI_MISSING()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_RA_INFO_NTF_EL1()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_UL_PARA_NTF_EL1()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_BUNDLING_INVALID()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_FDD_TDD_UDC()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_GET_HARQ()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_TTI_GET_HARQ()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_REQ_DATA()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_CE_CRNTI()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_CE_LBSR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_CE_SBSR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_CE_PHR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_STATUS_IND()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_DATA_REQ()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_DATA_REQ2()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_CLOSS_SSID()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_CLR_TX_TL()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_SET_TX_TL()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_DUP_RETX_INFO()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_VALUE_FILL()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_EPHR_VALUE_FILL()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_BSR_RETX_TMR_START()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_BSR_PERI_TMR_START()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_BSR_INCLUDE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_BSR_TRIGGER()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_BSR_LCG_STATUS()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_SET_LONG_BSR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_SET_SHORT_BSR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_SET_TRU_BSR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_RETX_INFO1()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_RETX_INFO2()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_HT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EAMC_LOG_DL_ASSIGNMENT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_DL_SWO()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_DL_1ST_HARQ_TX_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_DL_HT_SCELL_DEACT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UST_RESET_INIT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UST_UPDATE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UST_DIFF()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CA_SCELL_DEACT_TMR_START()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CA_SCELL_DEACT_TMR_STOP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CA_SCELL_DEACT_TMR_EXPIRE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CA_SCELL_NOTIFY_EL1()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CA_SCELL_ACT_DEACT_BITMAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CA_SCELL_DEACT_BY_THERMAL()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CA_SCELL_RESUME_BY_THERMAL()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_EVA_N5_DRX_STATUS()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_EVA_N5_DRX_CMD_STATUS()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_N5_DRX_CMD_STATUS()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_POSSIBLE_LAST_ACT_SF()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_STATUS()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_TIME_TO_DL_HARQ()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_TIME_TO_UL_HARQ()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_TIME_TO_UL_HARQ_PDCCH()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_TIME_TO_PDCCH()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_TIME_TO_UL_GRANT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_TIME_TO_RTT_TMR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_HOST_WAKEUP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_DRX_LOG_UPDATE_T_PDCCH()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SR_UPDATE_WAKE_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_DL_HARQ_UPDATE_WAKE_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UL_HARQ_UPDATE_WAKE_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CANCEL_DRX_RETX_TIMER()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UL_HARQ_PDCCH_UPDATE_WAKE_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SPS_UPDATE_WAKE_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_WAKE_DRX_CYCLE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CHANGE_SLP_STATUS()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INIT_RECONFIG_INACT_TMR_OPER()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_MSG3_PHICH_TMR_START()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_RTT_RETX_OPER_BUT_DL_HARQ_NUM_ZERO()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SKIP_ACKED_RETX_WAKE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_GAP_SBP_OFF()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_GAP_IGNORE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_GAP_RCV_START()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_GAP_DUP_START()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_GAP_RCV_END()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_GAP_TMR_EXP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_GAP_DRX_SUS()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_GAP_RCV_END_AFT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_GAP_TMR_START()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_RESUME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_INJECT_GAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_HARQ_CLOSE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_ACK_IN_GAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INC_NACK_IN_GAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_MAX_IF_ACKED()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_SUSPEND_DRX()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_WAIT_TX_READY()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CHK_WAKE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CHK_WAKE_DELAY()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_RESERVE_GRANT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_CLOSE_RESV_HARQ()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_SCH_RESV_ADP_RETX()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_SCH_RESV_NON_ADP_RETX()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_REQ_IN_GEMINI_GAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_PDCCH_MAY_BE_IN_GAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SIM_GAP_START()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SIM_GAP_IN_GAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_GAP_STATE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_GEMINI_GAP_RX_START()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_GEMINI_GAP_RX_END()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_SET_GEMINI_PHICH()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_GAP_FORCE_BSR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_JUDGE_RETX_MODE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_TX_SKIP_FOR_GAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_UPDATE_G_GAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_SKIP_FOR_G_GAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_NOT_SKIP_LONG_GAP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_NOT_SKIP_TX_NB()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_DISABLE_PHICH()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_DISABLE_PHICH_BUNDLING()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_GEMINI_ALIGNED_GAP_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_GEMINI_SIM_RESULT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_PHICH_FORCE_ACK()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_REPORT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_CALLON()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_CALLOFF()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_REPORT_TIMING()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_RB_STATUS()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_PREDICTION()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_NOT_WAKEUP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_PREDICTION_HIT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_VSR_COVER()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_USING_VSR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_VSR_CFG()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UPDATE_WAKEUP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UPDATE_RX_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CHECK_SR_WAKEUP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_MODIFY_CAUSE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_VOLTE_SET_SILENCE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_PN_SCRM_PADDING()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_CFG_CLOSE_MCCH()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_CFG_CLOSE_MRB()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_CFG_OPEN_MCCH()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_CFG_OPEN_MRB()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_CFG_CLOSE_MLT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_CFG_OPEN_MLT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_SEND_MSI_NTF()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_SWAP_IDX_TBL()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_SWO()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_MOT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_MOT_2()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_DATA_IND()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_INVALID_PMCH()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_MSI_SIZE_ODD()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_MSI_NEW_ENTRY()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_MSI_EXTEND_LAST()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_MSI_LCID_INFO()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_MSI_IGNORE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_MSI_IGNORE_NO_PMCH()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_ONLY_PADDING()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_PACKET()
#define ChkL1MsgFltr_EMAC_LOG_TX_CLOSE_INVALID_SSID()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_BYPASS_DRX_CONFIG()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PROBING_REQUEST()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PROBING_TRIGGER_RA()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PROBING_REQUEST_COLLISION()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RX_LMAC_RELEASE_HT()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_POWER_OFF()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SLP_CNF_1()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SLP_CNF_2()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PENDING_HOST_DATA_REQ()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SPS_UNSYNC_ERROR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_SPS_WHEN_DISABLE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_ENABLE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_DISABLE()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_RRC_PROHIBIT_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_NAS_PROHIBIT_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_RCV_UL_DL()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_NOT_SLEEP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_SRB_UNACKED_NOT_SLEEP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_TA_NOT_SLEEP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_SLEEP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_SEND_CYC_NTF()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_SLEEP_STATUS()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_STATUS()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_RCV_UL_IN_SLEEP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_RCV_RRC_PROHIBIT_CMD()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_RCV_NAS_PROHIBIT_CMD()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_RCV_PDCP_TMR_EXP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_RCV_PDCP_TMR_RESTR()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_UPDATE_SLP_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_REPORT_RRC_SLP_TIME()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_AUDRX_PDCCH_RA_IN_SLEEP()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_IGNORE_TDM_VM_RA()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH_COL_VM_RA()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RSIM_DEBUG()	ChkL1ClsFltr_EMAC_DETAIL_EMAC_INFO()


#endif
