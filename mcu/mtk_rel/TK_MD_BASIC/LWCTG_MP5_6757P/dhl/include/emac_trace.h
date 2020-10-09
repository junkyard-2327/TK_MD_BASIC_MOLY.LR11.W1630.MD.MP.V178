#ifndef L1TRC_EMAC_DEF_H
#define L1TRC_EMAC_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DUMMY(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0007 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DUMMY(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MAC_RESET(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0107 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_MAC_RESET(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RESET_HW(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0207 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RESET_HW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_EMAC_STATUS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0307 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_EMAC_STATUS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_COM_INIT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0407 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_COM_INIT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CH_MODE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0507 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CH_MODE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_FIRST_MIB_VALID(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0607 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_FIRST_MIB_VALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MBMS_RESET(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_MBMS_RESET(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_RRC(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0807 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_CFG_RRC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_STATUSBITMAP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0907 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_STATUSBITMAP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_CLOSE_RB(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0A07 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_CLOSE_RB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_OPEN_RB(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0B07 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CFG_OPEN_RB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_OPEN_RB2(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0C07 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_OPEN_RB2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_RA(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0D07 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CFG_RA(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DED_RA(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0E07 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DED_RA(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_TTI_ENABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0F07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_TTI_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_SCH(v1, v2, v3, v4, v5) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1007 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)((unsigned short)(v5))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_SCH(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DRX(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1107 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DRX(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DRX2(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1207 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DRX2(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_SHORT_DRX(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1307 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_SHORT_DRX(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_SHORT_DRX_NO_SLP(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1407 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_SHORT_DRX_NO_SLP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DRX_DISABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1507 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DRX_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_PHR(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1607 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CFG_PHR(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_NO_PHR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_NO_PHR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_CA(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1807 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_CFG_CA(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_SIM_PUCCH_PUSCH(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1907 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_SIM_PUCCH_PUSCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_PHY(v1, v2, v3, v4, v5) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1A07 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)((unsigned short)(v4))) << 16), (kal_uint32)((unsigned short)(v5)) | (((kal_uint32)((char)(v2))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CFG_PHY(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_SR(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1B07 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_SR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_UL_SPS_ENABLE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1C07 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_CFG_UL_SPS_ENABLE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_UL_SPS_DISABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1D07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_UL_SPS_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DL_SPS_ENABLE(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1E07 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DL_SPS_ENABLE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DL_SPS_DISABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1F07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DL_SPS_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_HARQ_NB(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2007 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_HARQ_NB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SET_EL1_MSG_STATUS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2107 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_SET_EL1_MSG_STATUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_EL1_CLR_MSG_STATUS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2207 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_EL1_CLR_MSG_STATUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RCV_EL1_MSG_CNF(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2307 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RCV_EL1_MSG_CNF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SET_EL1_MSG_WAIT_CNF(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2407 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_SET_EL1_MSG_WAIT_CNF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CLR_EL1_MSG_CNF(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2507 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CLR_EL1_MSG_CNF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RNTI_RA_ENABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2607 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RNTI_RA_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RNTI_TC_ENABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RNTI_TC_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RNTI_RA_DISABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2807 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RNTI_RA_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RNTI_TC_DISABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2907 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RNTI_TC_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RNTI_C_ENABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2A07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RNTI_C_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SEND_RNTI_UPDATE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2B07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SEND_RNTI_UPDATE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_REL_PUCCH_SRS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2C07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_REL_PUCCH_SRS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_REL_ULDL_SPS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2D07 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_REL_ULDL_SPS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_GRANT(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2E07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_UL_GRANT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_GRANT2(v1, v2, v3, v4, v5) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2F07 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v5));\
	} while(0)
#else
	#define EMAC_LOG_UL_GRANT2(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DET_HARQ_INFO(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3007 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)((unsigned short)(v4))) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_DET_HARQ_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DET_GRANT_INFO(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3107 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)((unsigned short)(v4))) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_DET_GRANT_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_NEWTX_HARQ(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3207 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_NEWTX_HARQ(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_HARQ_CLOSE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3307 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_HARQ_CLOSE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_TX_MODE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3407 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_UL_TX_MODE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_TTI_BUNDLING_ID(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3507 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_TTI_BUNDLING_ID(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_SPS_REL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3607 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_UL_SPS_REL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_SPS_ACT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_UL_SPS_ACT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_NEXT_SPS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3807 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_UL_NEXT_SPS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CCCH_MTX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3907 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CCCH_MTX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CCCH_MTX_PADDING(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3A07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CCCH_MTX_PADDING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CE_CANCEL_BSR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3B07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CE_CANCEL_BSR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_UL_SPS_UNSENT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3C07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_UL_SPS_UNSENT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_UL_SPS_IMP_RELEASE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3D07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_UL_SPS_IMP_RELEASE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_HARQ_TX_MAX(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3E07 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_UL_HARQ_TX_MAX(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RCV_INVALID_PHICH(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3F07 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_RCV_INVALID_PHICH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RCV_PHICH(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4007 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_RCV_PHICH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_FORCE_CLOSE_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4107 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_FORCE_CLOSE_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RETX_TBS_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4207 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RETX_TBS_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_NEW_TX_NDI_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4307 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_NEW_TX_NDI_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TC_RNTI_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4407 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TC_RNTI_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SPS_RETX_GRANT_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4507 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SPS_RETX_GRANT_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SPS_COL_TC_HARQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4607 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SPS_COL_TC_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_INVALID_RETX_UL_GRANT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_INVALID_RETX_UL_GRANT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CQI_COL_BUNDLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4807 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CQI_COL_BUNDLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CQI_WARNING(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4907 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_CQI_WARNING(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_SPS_REL_WARNING(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4A07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_UL_SPS_REL_WARNING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_GRANT_COLL(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4B07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_UL_GRANT_COLL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_GRANT_DROP(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4C07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_UL_GRANT_DROP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_GRANT_OVERWRITE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4D07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_UL_GRANT_OVERWRITE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TL_HARQ_CLOSE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4E07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TL_HARQ_CLOSE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_COL_TX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4F07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_COL_TX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_COL_PREAMBLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5007 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_COL_PREAMBLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RETX_HARQ_COL_MSG3(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5107 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_RETX_HARQ_COL_MSG3(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RETX_HARQ_COL(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5207 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_RETX_HARQ_COL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_TTI_NO_HARQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5307 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_TTI_NO_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_MSG3_TTI_HARQ_COL(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5407 | ((unsigned short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_MSG3_TTI_HARQ_COL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DELAY_TTI_HARQ(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5507 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TX_DELAY_TTI_HARQ(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_BSR_HOLD_BY_HO(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5607 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_BSR_HOLD_BY_HO(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_TRIGGER(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5707 | ((unsigned short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_PHR_TRIGGER(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_VALUE_IND(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5807 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_PHR_VALUE_IND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_VALUE_IND_MSG3(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5907 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_PHR_VALUE_IND_MSG3(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_PHR_PER_TMR_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5A07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_PHR_PER_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_PHR_PRO_TMR_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5B07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_PHR_PRO_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_INT_BEFORE_PACK_FINISH(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5C07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_PHR_INT_BEFORE_PACK_FINISH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_NOT_REPORT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5D07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_PHR_NOT_REPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_CANCEL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5E07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_CANCEL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_TRIGGER(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5F07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_TRIGGER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_TX(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6007 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_SR_TX(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_STOP_BY_RAR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6107 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_SR_STOP_BY_RAR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_NO_SR_RESOURCE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6207 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_NO_SR_RESOURCE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_SR_MAX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6307 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_SR_MAX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_RESTART(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6407 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_RESTART(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_START_PROHIBIT_TMR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6507 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_START_PROHIBIT_TMR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_CHECK_WAKE_TIME(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x6607 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_SR_CHECK_WAKE_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_SLEEP_NO_SR_RESOURCE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_SLEEP_NO_SR_RESOURCE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_TX_ABORT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6807 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_TX_ABORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_CMD(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6907 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TA_CMD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_TMR_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6A07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_TMR_STOP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6B07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_TMR_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_TMR_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6C07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_WARNING(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6D07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_WARNING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_NAG_TA(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6E07 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_NAG_TA(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_DISCARD_TC_RNTI(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6F07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_DISCARD_TC_RNTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SPS_ACT(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x7007 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DL_SPS_ACT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SPS_REL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7107 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_SPS_REL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SPS_UPDATE(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x7207 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DL_SPS_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SPS_REQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7307 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_SPS_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_CTRL_DATA(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x7407 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DL_CTRL_DATA(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_DROP_DL_DATA(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7507 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_DROP_DL_DATA(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_DROP_RAR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7607 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DL_DROP_RAR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_RETX_CNT_ERROR(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x7707 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DL_RETX_CNT_ERROR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SPS_REQ_AND_REL() do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7807 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_SPS_REQ_AND_REL()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INIT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7907 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INIT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_MONITOR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7A07 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_MONITOR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UL_INA_TIMER_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7B07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UL_INA_TIMER_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_DL_INA_TIMER_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7C07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_DL_INA_TIMER_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ON_TIMER_START(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x7D07 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ON_TIMER_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ON_TIMER_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7E07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ON_TIMER_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ON_TMR_STOP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7F07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ON_TMR_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INA_TMR_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8007 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INA_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INA_TMR_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8107 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INA_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INA_TMR_STOP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8207 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INA_TMR_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_RTT_TMR_NOT_START(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8307 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_RTT_TMR_NOT_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_RTT_TMR_START(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x8407 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DRX_RTT_TMR_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_RTT_TMR_STOP(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8507 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_RTT_TMR_STOP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SHORT_TIMER_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8607 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SHORT_TIMER_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SHORT_TMR_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SHORT_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_RETX_TMR_START(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x8807 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DRX_RETX_TMR_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_RETX_TMR_STOP(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8907 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_RETX_TMR_STOP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_DECODING_TMR_START(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8A07 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_DECODING_TMR_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ON_LENGTH(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8B07 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ON_LENGTH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SET_CYCLE_TYPE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8C07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SET_CYCLE_TYPE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SLEEP(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x8D07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SLEEP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ORI_WAKE_TIME(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8E07 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ORI_WAKE_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_NEXT_PST_TIME(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8F07 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_NEXT_PST_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_MOD_WAKE_TIME(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9007 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_MOD_WAKE_TIME(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_NEXT_CYCLE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9107 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_NEXT_CYCLE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_NEXT_IS_SHORT(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9207 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_NEXT_IS_SHORT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_NEXT_IS_LONG(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9307 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_NEXT_IS_LONG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CMD(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9407 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CMD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CMD_NO_DRX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9507 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CMD_NO_DRX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SET_RA_FLAG(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9607 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SET_RA_FLAG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CLR_RA_FLAG(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CLR_RA_FLAG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ACTIVE_SATATUS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9807 | ((unsigned short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ACTIVE_SATATUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_TX_ACTIVE_STATUS(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9907 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)((char)(v3))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_TX_ACTIVE_STATUS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UL_BUF(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9A07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UL_BUF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SEND_CYC_NTF(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x9B07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SEND_CYC_NTF(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SLEEP_PDCCH(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9C07 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SLEEP_PDCCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_MIB_VALID(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9D07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_MIB_VALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_HOST_DATA_CNF_NOTSLP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9E07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_HOST_DATA_CNF_NOTSLP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_HOST_DATA_CNF_NO_DRX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9F07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_HOST_DATA_CNF_NO_DRX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CHANGE_TO_LONG_CYCLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA007 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CHANGE_TO_LONG_CYCLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UPDATE_SRS_CQI_ADMIN(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA107 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UPDATE_SRS_CQI_ADMIN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_START(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xA207 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_RA_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_ASSIGN_IN_SLEEP(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA307 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DL_ASSIGN_IN_SLEEP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_DATA_IN_SLEEP(v1, v2, v3, v4, v5) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_5_word(0xA407 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EMAC_LOG_DL_DATA_IN_SLEEP(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xA507 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_START_SR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA607 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_START_SR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RA_ONGOING(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA707 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_RA_ONGOING(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_POT_MSG3(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA807 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_POT_MSG3(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_MSG_POW_OFFSET_B(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA907 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_MSG_POW_OFFSET_B(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_GROUPB(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xAA07 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_RA_GROUPB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_MSG3_SZ(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xAB07 | ((unsigned short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_MSG3_SZ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_ASSIGN_RAPID(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAC07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_ASSIGN_RAPID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_GROUP_A_RAPID(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAD07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_GROUP_A_RAPID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_GROUP_B_RAPID(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAE07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_GROUP_B_RAPID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PRACH_TX(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xAF07 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_PRACH_TX(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PRACH_REPORT(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB007 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_PRACH_REPORT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_STATE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB107 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_STATE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_COMP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB207 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_COMP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_WND(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB307 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_WND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_RCV(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xB407 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_RCV(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_GRANT(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB507 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_GRANT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_OUT_WND(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB607 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_OUT_WND(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_CNT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_CNT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_END_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB807 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_END_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH_RESTART(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB907 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH_RESTART(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RETRY(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBA07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RETRY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_BACKOFF(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xBB07 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_BACKOFF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_UL_CCCH_REQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBC07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_UL_CCCH_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CR_TMR_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBD07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_CR_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CR_TMR_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBE07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_CR_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_UEID_FAIL(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xBF07 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_RA_UEID_FAIL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CR_FAIL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC007 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_CR_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_MATCH(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xC107 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_MATCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_MISMATCH(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC207 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_MISMATCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_MSG3_HARQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC307 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_MSG3_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_FLUSH_MSG3_HARQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC407 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_FLUSH_MSG3_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_TC_CR_FAIL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC507 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_TC_CR_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_TC_CR_SUCCESS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC607 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_TC_CR_SUCCESS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RCV_PDCCH(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xC707 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_RCV_PDCCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CHK_DL_CTRL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC807 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_CHK_DL_CTRL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CE_CR_SUCCESS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC907 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_CE_CR_SUCCESS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RELOAD_MSG3(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCA07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RELOAD_MSG3(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_ABORT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCB07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_ABORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_DL_ERROR(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xCC07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_DL_ERROR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CFG_RESTART(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xCD07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_CFG_RESTART(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CRNTI_TO_TC(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCE07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CRNTI_TO_TC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PREAMBLE_COL_TX(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xCF07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_PREAMBLE_COL_TX(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_STATE_ERROR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xD007 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_STATE_ERROR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_MSG3_FLUSH_WARNING(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD107 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_MSG3_FLUSH_WARNING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PRACH_AF_TX_REQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD207 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_PRACH_AF_TX_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH_COL_HO(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD307 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH_COL_HO(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH_COL_UL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD407 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH_COL_UL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH_ORDER_GIVE_UP(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xD507 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH_ORDER_GIVE_UP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_GAP_WARNING(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xD607 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_GAP_WARNING(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MSG3_FORCE_CLOSE_SKIP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_MSG3_FORCE_CLOSE_SKIP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_SAME_TC_RNTI(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD807 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_SAME_TC_RNTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TC_RNTI_DL_WARNING(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xD907 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TC_RNTI_DL_WARNING(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TC_RNTI_DL_AS_CRNTI(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDA07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TC_RNTI_DL_AS_CRNTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_TCRNTI_DATA_ERROR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xDB07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DL_TCRNTI_DATA_ERROR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_CCCH_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDC07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_CCCH_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RA_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDD07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RA_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_UL_CRNTI_CHK_SUS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDE07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_UL_CRNTI_CHK_SUS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_NEW_UL_CRNTI_CHK_SUS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDF07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_NEW_UL_CRNTI_CHK_SUS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_DL_RNTI_CHK_SUS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE007 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_DL_RNTI_CHK_SUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_SAVE_MSG3_BUFF(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE107 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_SAVE_MSG3_BUFF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_INT_IN_WRONG_STATE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE207 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_INT_IN_WRONG_STATE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_INT_BEROFE_PDCCH_IND(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE307 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_INT_BEROFE_PDCCH_IND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_TA_TIMEOUT(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE407 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)((char)(v4))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_TA_TIMEOUT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_TA_STOP_CR_TIMER(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xE507 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_TA_STOP_CR_TIMER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_TA_CLR_RAR_UL_GRANT(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE607 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_TA_CLR_RAR_UL_GRANT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_SMALL_RAR_GRANT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xE707 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_SMALL_RAR_GRANT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_LMAC_ERR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE807 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DL_LMAC_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_LMAC_ERR_0(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE907 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_UL_LMAC_ERR_0(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_LMAC_ERR_1(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xEA07 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_UL_LMAC_ERR_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MAC_CE_LEN_ERROR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xEB07 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_MAC_CE_LEN_ERROR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_START_PAST_ON(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xEC07 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_START_PAST_ON(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_RECV_TDM_REQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xED07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_RECV_TDM_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_SUSPEND_ALL_DRB(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xEE07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_SUSPEND_ALL_DRB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_LEAVE_TDM(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xEF07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_LEAVE_TDM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_IGNORE_TDM_CH_MODE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xF007 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_IDC_IGNORE_TDM_CH_MODE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_IGNORE_TDM_HO_RA(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF107 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_IGNORE_TDM_HO_RA(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_STOP_SR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF207 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_STOP_SR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_CANCEL_BSR_TRIGGER(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF307 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_CANCEL_BSR_TRIGGER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_STOP_RETX_BSR_TIMER(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF407 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_STOP_RETX_BSR_TIMER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_FORCE_LEAVE_TDM(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF507 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_FORCE_LEAVE_TDM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_CANCEL_BSR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xF607 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_IDC_CANCEL_BSR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_ERR_RA_GROUP_A_ERR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xF707 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_ERR_RA_GROUP_A_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RCV_UEID_IN_WRONG_TYPE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF807 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RCV_UEID_IN_WRONG_TYPE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_ERR_SPS_GRANT_ERR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xF907 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_ERR_SPS_GRANT_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_CCCH_LEN_ERR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xFA07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_CCCH_LEN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_CCCH_NO_GPD(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xFB07 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_CCCH_NO_GPD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RX_NO_SRB_GPD(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xFC07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RX_NO_SRB_GPD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_GRANT_INCONSIST(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xFD07 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_GRANT_INCONSIST(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_PUSCH_TX_REQ(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xFE07 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_IDC_PUSCH_TX_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_NULL_TX_REQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xFF07 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_NULL_TX_REQ(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EMAC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EMAC_LOG_DUMMY(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_MAC_RESET(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RESET_HW(unsigned short v1);
void L1TRC_Send_EMAC_LOG_EMAC_STATUS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_COM_INIT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CH_MODE(short v1, char v2);
void L1TRC_Send_EMAC_LOG_FIRST_MIB_VALID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_MBMS_RESET(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_RRC(unsigned short v1, char v2, char v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_CFG_STATUSBITMAP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_CLOSE_RB(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_CFG_OPEN_RB(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_CFG_OPEN_RB2(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_CFG_RA(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_CFG_DED_RA(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_CFG_TTI_ENABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_SCH(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EMAC_LOG_CFG_DRX(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_CFG_DRX2(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_SHORT_DRX(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_CFG_SHORT_DRX_NO_SLP(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_CFG_DRX_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_PHR(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_CFG_NO_PHR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_CA(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_CFG_SIM_PUCCH_PUSCH(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_PHY(unsigned short v1, char v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EMAC_LOG_CFG_SR(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_CFG_UL_SPS_ENABLE(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_CFG_UL_SPS_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_DL_SPS_ENABLE(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_CFG_DL_SPS_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_HARQ_NB(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EMAC_LOG_SET_EL1_MSG_STATUS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_EL1_CLR_MSG_STATUS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RCV_EL1_MSG_CNF(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_SET_EL1_MSG_WAIT_CNF(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_CLR_EL1_MSG_CNF(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RNTI_RA_ENABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RNTI_TC_ENABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RNTI_RA_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RNTI_TC_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RNTI_C_ENABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SEND_RNTI_UPDATE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_REL_PUCCH_SRS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_REL_ULDL_SPS(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_GRANT(unsigned short v1, unsigned long v2, char v3);
void L1TRC_Send_EMAC_LOG_UL_GRANT2(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned long v5);
void L1TRC_Send_EMAC_LOG_TX_DET_HARQ_INFO(unsigned short v1, char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_TX_DET_GRANT_INFO(unsigned short v1, char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_TX_NEWTX_HARQ(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_HARQ_CLOSE(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_TX_MODE(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_TX_TTI_BUNDLING_ID(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_SPS_REL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_UL_SPS_ACT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_UL_NEXT_SPS(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_CCCH_MTX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_CCCH_MTX_PADDING(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_CE_CANCEL_BSR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_UL_SPS_UNSENT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_UL_SPS_IMP_RELEASE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_UL_HARQ_TX_MAX(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_RCV_INVALID_PHICH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_RCV_PHICH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_FORCE_CLOSE_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RETX_TBS_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_NEW_TX_NDI_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TC_RNTI_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SPS_RETX_GRANT_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SPS_COL_TC_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_INVALID_RETX_UL_GRANT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CQI_COL_BUNDLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CQI_WARNING(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_SPS_REL_WARNING(unsigned short v1);
void L1TRC_Send_EMAC_LOG_UL_GRANT_COLL(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_UL_GRANT_DROP(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_UL_GRANT_OVERWRITE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TL_HARQ_CLOSE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_COL_TX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_COL_PREAMBLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_RETX_HARQ_COL_MSG3(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_RETX_HARQ_COL(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_TTI_NO_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_MSG3_TTI_HARQ_COL(unsigned short v1, long v2);
void L1TRC_Send_EMAC_LOG_TX_DELAY_TTI_HARQ(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EMAC_LOG_BSR_HOLD_BY_HO(unsigned short v1);
void L1TRC_Send_EMAC_LOG_PHR_TRIGGER(unsigned short v1, long v2, long v3);
void L1TRC_Send_EMAC_LOG_PHR_VALUE_IND(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_PHR_VALUE_IND_MSG3(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_PHR_PER_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_PHR_PRO_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_PHR_INT_BEFORE_PACK_FINISH(unsigned short v1);
void L1TRC_Send_EMAC_LOG_PHR_NOT_REPORT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_CANCEL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_TRIGGER(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_TX(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_SR_STOP_BY_RAR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_SR_NO_SR_RESOURCE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_SR_MAX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_RESTART(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_START_PROHIBIT_TMR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_CHECK_WAKE_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_SR_SLEEP_NO_SR_RESOURCE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_TX_ABORT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_CMD(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_TA_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_TMR_STOP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_TMR_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_WARNING(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_NAG_TA(short v1);
void L1TRC_Send_EMAC_LOG_DL_DISCARD_TC_RNTI(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_SPS_ACT(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DL_SPS_REL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_SPS_UPDATE(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DL_SPS_REQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_CTRL_DATA(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DL_DROP_DL_DATA(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_DROP_RAR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DL_RETX_CNT_ERROR(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_SPS_REQ_AND_REL(void);
void L1TRC_Send_EMAC_LOG_DRX_INIT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_MONITOR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_UL_INA_TIMER_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_DL_INA_TIMER_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_ON_TIMER_START(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_ON_TIMER_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_ON_TMR_STOP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INA_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INA_TMR_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INA_TMR_STOP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_RTT_TMR_NOT_START(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_RTT_TMR_START(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DRX_RTT_TMR_STOP(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_SHORT_TIMER_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_SHORT_TMR_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_RETX_TMR_START(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DRX_RETX_TMR_STOP(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_DECODING_TMR_START(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_ON_LENGTH(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_SET_CYCLE_TYPE(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_DRX_SLEEP(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DRX_ORI_WAKE_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_NEXT_PST_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_MOD_WAKE_TIME(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_NEXT_CYCLE(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_NEXT_IS_SHORT(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_NEXT_IS_LONG(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_CMD(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_CMD_NO_DRX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_SET_RA_FLAG(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_CLR_RA_FLAG(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_ACTIVE_SATATUS(unsigned short v1, long v2);
void L1TRC_Send_EMAC_LOG_DRX_TX_ACTIVE_STATUS(unsigned short v1, unsigned long v2, char v3, short v4);
void L1TRC_Send_EMAC_LOG_DRX_UL_BUF(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_SEND_CYC_NTF(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DRX_SLEEP_PDCCH(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_MIB_VALID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_HOST_DATA_CNF_NOTSLP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_HOST_DATA_CNF_NO_DRX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_CHANGE_TO_LONG_CYCLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_UPDATE_SRS_CQI_ADMIN(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_START(unsigned short v1, char v2, char v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DL_ASSIGN_IN_SLEEP(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DL_DATA_IN_SLEEP(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EMAC_LOG_RA_PDCCH(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_START_SR(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_RA_ONGOING(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_POT_MSG3(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_MSG_POW_OFFSET_B(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_GROUPB(short v1, long v2, long v3, long v4);
void L1TRC_Send_EMAC_LOG_RA_MSG3_SZ(unsigned short v1, long v2);
void L1TRC_Send_EMAC_LOG_RA_ASSIGN_RAPID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_GROUP_A_RAPID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_GROUP_B_RAPID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PRACH_TX(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_PRACH_REPORT(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_STATE(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_COMP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_WND(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_RAR_RCV(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_RA_RAR_GRANT(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_RAR_OUT_WND(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RAR_CNT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RAR_END_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PDCCH_RESTART(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_RETRY(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_BACKOFF(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_UL_CCCH_REQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_CR_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_CR_TMR_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_UEID_FAIL(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_RA_CR_FAIL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RAR_MATCH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_RAR_MISMATCH(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_MSG3_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_FLUSH_MSG3_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_TC_CR_FAIL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_TC_CR_SUCCESS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RCV_PDCCH(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_CHK_DL_CTRL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_CE_CR_SUCCESS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RELOAD_MSG3(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_ABORT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RAR_DL_ERROR(unsigned short v1, char v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_CFG_RESTART(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_CRNTI_TO_TC(unsigned short v1);
void L1TRC_Send_EMAC_LOG_PREAMBLE_COL_TX(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_RAR_STATE_ERROR(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_MSG3_FLUSH_WARNING(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PRACH_AF_TX_REQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PDCCH_COL_HO(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PDCCH_COL_UL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PDCCH_ORDER_GIVE_UP(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_GAP_WARNING(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_MSG3_FORCE_CLOSE_SKIP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_SAME_TC_RNTI(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TC_RNTI_DL_WARNING(unsigned short v1, char v2, char v3);
void L1TRC_Send_EMAC_LOG_TC_RNTI_DL_AS_CRNTI(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_TCRNTI_DATA_ERROR(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_DL_CCCH_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RA_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_UL_CRNTI_CHK_SUS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_NEW_UL_CRNTI_CHK_SUS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_DL_RNTI_CHK_SUS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_SAVE_MSG3_BUFF(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_RAR_INT_IN_WRONG_STATE(short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_RAR_INT_BEROFE_PDCCH_IND(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_TA_TIMEOUT(short v1, char v2, char v3, char v4);
void L1TRC_Send_EMAC_LOG_RA_TA_STOP_CR_TIMER(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_TA_CLR_RAR_UL_GRANT(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_SMALL_RAR_GRANT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_LMAC_ERR(short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_LMAC_ERR_0(short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_LMAC_ERR_1(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_MAC_CE_LEN_ERROR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_START_PAST_ON(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_IDC_RECV_TDM_REQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_SUSPEND_ALL_DRB(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_LEAVE_TDM(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_IGNORE_TDM_CH_MODE(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_IDC_IGNORE_TDM_HO_RA(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_STOP_SR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_CANCEL_BSR_TRIGGER(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_STOP_RETX_BSR_TIMER(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_FORCE_LEAVE_TDM(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_CANCEL_BSR(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_ERR_RA_GROUP_A_ERR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RCV_UEID_IN_WRONG_TYPE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_ERR_SPS_GRANT_ERR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DL_CCCH_LEN_ERR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_CCCH_NO_GPD(short v1);
void L1TRC_Send_EMAC_LOG_RX_NO_SRB_GPD(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RAR_GRANT_INCONSIST(unsigned short v1, unsigned long v2, char v3);
void L1TRC_Send_EMAC_LOG_IDC_PUSCH_TX_REQ(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_IDC_NULL_TX_REQ(unsigned short v1);

void Set_EMAC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EMAC()	(EMAC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EMAC_EMAC_INFO()	(ChkL1ModFltr_EMAC()&&((EMAC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EMAC_EMAC_DUMP()	(ChkL1ModFltr_EMAC()&&((EMAC_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_EMAC_LOG_DUMMY()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MAC_RESET()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RESET_HW()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_EMAC_STATUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_COM_INIT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CH_MODE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_FIRST_MIB_VALID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MBMS_RESET()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_RRC()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_STATUSBITMAP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_CLOSE_RB()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_OPEN_RB()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_OPEN_RB2()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_RA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DED_RA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_TTI_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_SCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DRX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DRX2()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_SHORT_DRX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_SHORT_DRX_NO_SLP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DRX_DISABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_PHR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_NO_PHR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_CA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_SIM_PUCCH_PUSCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_PHY()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_SR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_UL_SPS_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_UL_SPS_DISABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DL_SPS_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DL_SPS_DISABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_HARQ_NB()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SET_EL1_MSG_STATUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_EL1_CLR_MSG_STATUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RCV_EL1_MSG_CNF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SET_EL1_MSG_WAIT_CNF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CLR_EL1_MSG_CNF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RNTI_RA_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RNTI_TC_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RNTI_RA_DISABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RNTI_TC_DISABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RNTI_C_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SEND_RNTI_UPDATE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_REL_PUCCH_SRS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_REL_ULDL_SPS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_GRANT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_GRANT2()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_DET_HARQ_INFO()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_DET_GRANT_INFO()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_NEWTX_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_HARQ_CLOSE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_TX_MODE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_TTI_BUNDLING_ID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_SPS_REL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_SPS_ACT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_NEXT_SPS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_CCCH_MTX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_CCCH_MTX_PADDING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_CE_CANCEL_BSR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_UL_SPS_UNSENT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_UL_SPS_IMP_RELEASE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_HARQ_TX_MAX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_RCV_INVALID_PHICH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_RCV_PHICH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_FORCE_CLOSE_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RETX_TBS_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_NEW_TX_NDI_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TC_RNTI_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SPS_RETX_GRANT_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SPS_COL_TC_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_INVALID_RETX_UL_GRANT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CQI_COL_BUNDLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CQI_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_SPS_REL_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_GRANT_COLL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_GRANT_DROP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_GRANT_OVERWRITE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TL_HARQ_CLOSE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_COL_TX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_COL_PREAMBLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_RETX_HARQ_COL_MSG3()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_RETX_HARQ_COL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_TTI_NO_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_MSG3_TTI_HARQ_COL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_DELAY_TTI_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_BSR_HOLD_BY_HO()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_TRIGGER()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_VALUE_IND()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_VALUE_IND_MSG3()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_PHR_PER_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_PHR_PRO_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_INT_BEFORE_PACK_FINISH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_NOT_REPORT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_CANCEL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_TRIGGER()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_TX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_STOP_BY_RAR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_NO_SR_RESOURCE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_SR_MAX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_RESTART()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_START_PROHIBIT_TMR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_CHECK_WAKE_TIME()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_SLEEP_NO_SR_RESOURCE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_TX_ABORT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_CMD()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_TMR_STOP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_TMR_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_NAG_TA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_DISCARD_TC_RNTI()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_SPS_ACT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_SPS_REL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_SPS_UPDATE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_SPS_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_CTRL_DATA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_DROP_DL_DATA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_DROP_RAR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_RETX_CNT_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SPS_REQ_AND_REL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INIT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_MONITOR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UL_INA_TIMER_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_DL_INA_TIMER_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ON_TIMER_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ON_TIMER_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ON_TMR_STOP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INA_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INA_TMR_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INA_TMR_STOP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_RTT_TMR_NOT_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_RTT_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_RTT_TMR_STOP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SHORT_TIMER_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SHORT_TMR_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_RETX_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_RETX_TMR_STOP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_DECODING_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ON_LENGTH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SET_CYCLE_TYPE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SLEEP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ORI_WAKE_TIME()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_NEXT_PST_TIME()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_MOD_WAKE_TIME()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_NEXT_CYCLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_NEXT_IS_SHORT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_NEXT_IS_LONG()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CMD()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CMD_NO_DRX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SET_RA_FLAG()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CLR_RA_FLAG()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ACTIVE_SATATUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_TX_ACTIVE_STATUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UL_BUF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SEND_CYC_NTF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SLEEP_PDCCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_MIB_VALID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_HOST_DATA_CNF_NOTSLP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_HOST_DATA_CNF_NO_DRX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CHANGE_TO_LONG_CYCLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UPDATE_SRS_CQI_ADMIN()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_ASSIGN_IN_SLEEP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_DATA_IN_SLEEP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_START_SR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RA_ONGOING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_POT_MSG3()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_MSG_POW_OFFSET_B()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_GROUPB()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_MSG3_SZ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_ASSIGN_RAPID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_GROUP_A_RAPID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_GROUP_B_RAPID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PRACH_TX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PRACH_REPORT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_STATE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_COMP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_WND()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_RCV()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_GRANT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_OUT_WND()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_CNT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_END_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH_RESTART()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RETRY()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_BACKOFF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_UL_CCCH_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CR_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CR_TMR_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_UEID_FAIL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CR_FAIL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_MATCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_MISMATCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_MSG3_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_FLUSH_MSG3_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_TC_CR_FAIL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_TC_CR_SUCCESS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RCV_PDCCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CHK_DL_CTRL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CE_CR_SUCCESS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RELOAD_MSG3()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_ABORT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_DL_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CFG_RESTART()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CRNTI_TO_TC()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PREAMBLE_COL_TX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_STATE_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_MSG3_FLUSH_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PRACH_AF_TX_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH_COL_HO()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH_COL_UL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH_ORDER_GIVE_UP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_GAP_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MSG3_FORCE_CLOSE_SKIP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_SAME_TC_RNTI()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TC_RNTI_DL_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TC_RNTI_DL_AS_CRNTI()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_TCRNTI_DATA_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_CCCH_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RA_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_UL_CRNTI_CHK_SUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_NEW_UL_CRNTI_CHK_SUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_DL_RNTI_CHK_SUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_SAVE_MSG3_BUFF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_INT_IN_WRONG_STATE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_INT_BEROFE_PDCCH_IND()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_TA_TIMEOUT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_TA_STOP_CR_TIMER()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_TA_CLR_RAR_UL_GRANT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_SMALL_RAR_GRANT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_LMAC_ERR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_LMAC_ERR_0()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_LMAC_ERR_1()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MAC_CE_LEN_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_START_PAST_ON()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_RECV_TDM_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_SUSPEND_ALL_DRB()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_LEAVE_TDM()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_IGNORE_TDM_CH_MODE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_IGNORE_TDM_HO_RA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_STOP_SR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_CANCEL_BSR_TRIGGER()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_STOP_RETX_BSR_TIMER()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_FORCE_LEAVE_TDM()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_CANCEL_BSR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_ERR_RA_GROUP_A_ERR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RCV_UEID_IN_WRONG_TYPE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_ERR_SPS_GRANT_ERR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_CCCH_LEN_ERR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_CCCH_NO_GPD()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RX_NO_SRB_GPD()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_GRANT_INCONSIST()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_PUSCH_TX_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_NULL_TX_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()


#endif
