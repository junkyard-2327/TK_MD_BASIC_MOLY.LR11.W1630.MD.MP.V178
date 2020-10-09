#ifndef L1TRC_ERLCUL_DEF_H
#define L1TRC_ERLCUL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_GENERIC(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0003 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_GENERIC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_ERROR(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0103 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SCH_GRANT_IND(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0203 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_SCH_GRANT_IND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SCH_RESULT(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0303 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SCH_RESULT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SCH_RESULT_PAD(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0403 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SCH_RESULT_PAD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_1ST_RND_START(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0503 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_1ST_RND_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_1ST_RND_RESTART(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0603 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_1ST_RND_RESTART(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_1ST_RND_END(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0703 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_1ST_RND_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_2ND_RND_START(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0803 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_2ND_RND_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_2ND_RND_RESTART(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0903 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_2ND_RND_RESTART(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_2ND_RND_END(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0A03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_2ND_RND_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SIT_IDX_JMP(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0B03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_SIT_IDX_JMP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_SDU_SUMMARY(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0C03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_SRV_SDU_SUMMARY(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_RETX_PDU(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0D03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SRV_RETX_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_RETX_SEG(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0E03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SRV_RETX_SEG(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_RETX_PDU_BY_RESEG(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0F03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_SRV_RETX_PDU_BY_RESEG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_RETX_SEG_BY_RESEG(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1003 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SRV_RETX_SEG_BY_RESEG(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DEL_POLL_NACK(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1103 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DEL_POLL_NACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MAX_RETX(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1203 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_MAX_RETX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_AM_SN(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1303 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_AM_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_UM5_SN(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1403 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_UM5_SN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_UM10_SN(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1503 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_UM10_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SEND_STUS_PDU(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1603 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_SEND_STUS_PDU(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REGEN_STUS_PDU(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1703 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_REGEN_STUS_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VT_A_UPDATE(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1803 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_VT_A_UPDATE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_STUS_PDU_IND(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1903 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_STUS_PDU_IND(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_STUS_PDU_IND_DUP(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1A03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_STUS_PDU_IND_DUP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_DUP(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x1B03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_NACK_DUP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_BAD_SO(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1C03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_NACK_BAD_SO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRB_DATA_CNF(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1D03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_SRB_DATA_CNF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DISCARD_SIT(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1E03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DISCARD_SIT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DISCARD_SIT_RANGE(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1F03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DISCARD_SIT_RANGE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_STUS_PROH(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2003 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_STUS_PROH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_BIT(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2103 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_BIT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_START(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2203 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_STOP(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2303 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2403 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY_ADD_PDU(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2503 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY_ADD_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY_NO_SDU(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2603 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY_NO_SDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY_NO_LOSS(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2703 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY_NO_LOSS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY_FAKE(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2803 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY_FAKE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY_MULTI(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2903 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY_MULTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_IDC_START(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2A03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_IDC_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_IDC_RESTART(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2B03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_IDC_RESTART(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_IDC_END(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2C03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_IDC_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_PDU_RETX_CNTR(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2D03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_PDU_RETX_CNTR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MAX_RETX_CNTR(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2E03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_MAX_RETX_CNTR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RST_COPRO_IDX(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2F03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_RST_COPRO_IDX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_POLL_IN_COPRO_OFF(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3003 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_POLL_IN_COPRO_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_START_EVENT(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3103 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_START_EVENT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_HWB_REL_FOR_NO_RB(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3203 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_HWB_REL_FOR_NO_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_ADD_SRB(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3303 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_ADD_SRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_ADD_DRB_1(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3403 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_ADD_DRB_1(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_ADD_DRB_2(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3503 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_ADD_DRB_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_DEL_SRB(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3603 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_DEL_SRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_DEL_DRB(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3703 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_DEL_DRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_DEL_OLD_DRB(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3803 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_DEL_OLD_DRB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_DEL_NEW_DRB(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3903 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_DEL_NEW_DRB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RECFG_RB(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3A03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_RECFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_REEST_WI_CFG_RB(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3B03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_REEST_WI_CFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_REEST_WO_CFG_RB(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3C03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_REEST_WO_CFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RB_PARAM_ERR(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3D03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_RB_PARAM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RB_STUS_ERR(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3E03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_RB_STUS_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_HWB_STATS(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3F03 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_HWB_STATS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_HWB_STATS_2048(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x4003 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_HWB_STATS_2048(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_POOL_STATS(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x4103 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_NACK_POOL_STATS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VIP_DATA_INFO(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4203 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_VIP_DATA_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VIP_DATA_FULL(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4303 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_VIP_DATA_FULL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VIP_DATA_TMOUT(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4403 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_VIP_DATA_TMOUT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_POLL_FUNC(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4503 | ((unsigned short)(v2) << 16), (unsigned long)(v1));\
	} while(0)
#else
	#define ERLC_LOG_UL_POLL_FUNC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_POWER_OFF(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4603 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_POWER_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_INJ_UL_DEBUG_FILTER(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4703 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define ERLC_LOG_INJ_UL_DEBUG_FILTER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_STUS_GUARD_TMR_START(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4803 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_STUS_GUARD_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_STUS_GUARD_TMR_STOP(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4903 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_STUS_GUARD_TMR_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VIRTUAL_CONNECTED_CNF(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4A03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_VIRTUAL_CONNECTED_CNF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RECFG_UL_SNF_LEN_CHG(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4B03 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RECFG_UL_SNF_LEN_CHG(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char ERLCUL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_ERLC_LOG_GENERIC(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_ERROR(short v1);
void L1TRC_Send_ERLC_LOG_SCH_GRANT_IND(short v1, short v2);
void L1TRC_Send_ERLC_LOG_SCH_RESULT(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_SCH_RESULT_PAD(short v1);
void L1TRC_Send_ERLC_LOG_1ST_RND_START(short v1, short v2, short v3, long v4);
void L1TRC_Send_ERLC_LOG_1ST_RND_RESTART(short v1, short v2, long v3);
void L1TRC_Send_ERLC_LOG_1ST_RND_END(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_2ND_RND_START(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_2ND_RND_RESTART(short v1, short v2);
void L1TRC_Send_ERLC_LOG_2ND_RND_END(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_SIT_IDX_JMP(short v1, short v2);
void L1TRC_Send_ERLC_LOG_SRV_SDU_SUMMARY(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_SRV_RETX_PDU(short v1);
void L1TRC_Send_ERLC_LOG_SRV_RETX_SEG(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_SRV_RETX_PDU_BY_RESEG(short v1, short v2);
void L1TRC_Send_ERLC_LOG_SRV_RETX_SEG_BY_RESEG(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_DEL_POLL_NACK(short v1);
void L1TRC_Send_ERLC_LOG_MAX_RETX(short v1);
void L1TRC_Send_ERLC_LOG_UL_AM_SN(short v1, short v2);
void L1TRC_Send_ERLC_LOG_UL_UM5_SN(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_UL_UM10_SN(short v1, short v2);
void L1TRC_Send_ERLC_LOG_SEND_STUS_PDU(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_REGEN_STUS_PDU(short v1);
void L1TRC_Send_ERLC_LOG_VT_A_UPDATE(short v1, short v2);
void L1TRC_Send_ERLC_LOG_STUS_PDU_IND(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_STUS_PDU_IND_DUP(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_NACK_DUP(short v1);
void L1TRC_Send_ERLC_LOG_NACK_BAD_SO(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_SRB_DATA_CNF(short v1, short v2);
void L1TRC_Send_ERLC_LOG_DISCARD_SIT(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_DISCARD_SIT_RANGE(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_STUS_PROH(short v1, long v2);
void L1TRC_Send_ERLC_LOG_POLL_BIT(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_START(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_STOP(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY_ADD_PDU(short v1, short v2);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY_NO_SDU(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY_NO_LOSS(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY_FAKE(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY_MULTI(short v1);
void L1TRC_Send_ERLC_LOG_IDC_START(short v1);
void L1TRC_Send_ERLC_LOG_IDC_RESTART(short v1);
void L1TRC_Send_ERLC_LOG_IDC_END(short v1);
void L1TRC_Send_ERLC_LOG_PDU_RETX_CNTR(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_MAX_RETX_CNTR(short v1, short v2);
void L1TRC_Send_ERLC_LOG_UL_RST_COPRO_IDX(short v1);
void L1TRC_Send_ERLC_LOG_UL_POLL_IN_COPRO_OFF(short v1);
void L1TRC_Send_ERLC_LOG_START_EVENT(short v1);
void L1TRC_Send_ERLC_LOG_HWB_REL_FOR_NO_RB(short v1);
void L1TRC_Send_ERLC_LOG_UL_ADD_SRB(short v1, short v2);
void L1TRC_Send_ERLC_LOG_UL_ADD_DRB_1(short v1, short v2);
void L1TRC_Send_ERLC_LOG_UL_ADD_DRB_2(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_UL_DEL_SRB(short v1, short v2);
void L1TRC_Send_ERLC_LOG_UL_DEL_DRB(short v1, short v2);
void L1TRC_Send_ERLC_LOG_UL_DEL_OLD_DRB(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_UL_DEL_NEW_DRB(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_UL_RECFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_UL_REEST_WI_CFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_UL_REEST_WO_CFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_UL_RB_PARAM_ERR(short v1);
void L1TRC_Send_ERLC_LOG_UL_RB_STUS_ERR(short v1);
void L1TRC_Send_ERLC_LOG_UL_HWB_STATS(short v1, short v2);
void L1TRC_Send_ERLC_LOG_UL_HWB_STATS_2048(short v1);
void L1TRC_Send_ERLC_LOG_NACK_POOL_STATS(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_VIP_DATA_INFO(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_VIP_DATA_FULL(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_VIP_DATA_TMOUT(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_UL_POLL_FUNC(unsigned long v1, unsigned short v2);
void L1TRC_Send_ERLC_LOG_UL_POWER_OFF(short v1);
void L1TRC_Send_ERLC_LOG_INJ_UL_DEBUG_FILTER(unsigned long v1);
void L1TRC_Send_ERLC_LOG_STUS_GUARD_TMR_START(short v1);
void L1TRC_Send_ERLC_LOG_STUS_GUARD_TMR_STOP(short v1);
void L1TRC_Send_ERLC_LOG_VIRTUAL_CONNECTED_CNF(short v1);
void L1TRC_Send_ERLC_LOG_RECFG_UL_SNF_LEN_CHG(short v1);

void Set_ERLCUL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_ERLCUL()	(ERLCUL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()	(ChkL1ModFltr_ERLCUL()&&((ERLCUL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()	(ChkL1ModFltr_ERLCUL()&&((ERLCUL_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_ERLC_LOG_GENERIC()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_ERROR()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SCH_GRANT_IND()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SCH_RESULT()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SCH_RESULT_PAD()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_1ST_RND_START()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_1ST_RND_RESTART()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_1ST_RND_END()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_2ND_RND_START()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_2ND_RND_RESTART()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_2ND_RND_END()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SIT_IDX_JMP()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SRV_SDU_SUMMARY()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SRV_RETX_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SRV_RETX_SEG()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SRV_RETX_PDU_BY_RESEG()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SRV_RETX_SEG_BY_RESEG()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DEL_POLL_NACK()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_MAX_RETX()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_AM_SN()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_UM5_SN()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_UM10_SN()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SEND_STUS_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_REGEN_STUS_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_VT_A_UPDATE()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_STUS_PDU_IND()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_STUS_PDU_IND_DUP()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_NACK_DUP()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_NACK_BAD_SO()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SRB_DATA_CNF()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DISCARD_SIT()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DISCARD_SIT_RANGE()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_STUS_PROH()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_BIT()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_START()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_STOP()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY_ADD_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY_NO_SDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY_NO_LOSS()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY_FAKE()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY_MULTI()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_IDC_START()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_IDC_RESTART()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_IDC_END()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_PDU_RETX_CNTR()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_MAX_RETX_CNTR()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_UL_RST_COPRO_IDX()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_POLL_IN_COPRO_OFF()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_START_EVENT()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_HWB_REL_FOR_NO_RB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_ADD_SRB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_ADD_DRB_1()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_ADD_DRB_2()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_DEL_SRB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_DEL_DRB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_DEL_OLD_DRB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_DEL_NEW_DRB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_RECFG_RB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_REEST_WI_CFG_RB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_REEST_WO_CFG_RB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_RB_PARAM_ERR()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_RB_STUS_ERR()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_HWB_STATS()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_UL_HWB_STATS_2048()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_NACK_POOL_STATS()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_VIP_DATA_INFO()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_VIP_DATA_FULL()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_VIP_DATA_TMOUT()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_POLL_FUNC()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_POWER_OFF()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_INJ_UL_DEBUG_FILTER()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_STUS_GUARD_TMR_START()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_STUS_GUARD_TMR_STOP()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_VIRTUAL_CONNECTED_CNF()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RECFG_UL_SNF_LEN_CHG()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()


#endif
