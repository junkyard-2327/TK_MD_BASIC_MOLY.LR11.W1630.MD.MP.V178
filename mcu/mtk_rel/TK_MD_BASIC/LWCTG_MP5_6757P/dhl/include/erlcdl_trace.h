#ifndef L1TRC_ERLCDL_DEF_H
#define L1TRC_ERLCDL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_STATE_VAR_AM(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0005 | ((short)(v2) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((short)(v4))) << 16), (kal_uint32)((char)(v1)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_STATE_VAR_AM(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_STATE_VAR_AM_EQ(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0105 | ((short)(v2) << 16), (kal_uint32)((char)(v1)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_STATE_VAR_AM_EQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_STATE_VAR_UM(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0205 | ((short)(v2) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_STATE_VAR_UM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_STATE_VAR_UM_EQ(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0305 | ((short)(v2) << 16), (kal_uint32)((char)(v1)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_STATE_VAR_UM_EQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_START_AM(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0405 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_START_AM(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_START_UM(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0505 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_START_UM(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_STOP(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0605 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_EXPRY(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0705 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_EXPRY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_EXPRY_FAKE(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0805 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_EXPRY_FAKE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_EXPRY_MULTI(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0905 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_EXPRY_MULTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_UM_FORCE_45MS(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0A05 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_UM_FORCE_45MS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RLC_PDU_UNKNOWN(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0B05 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_RLC_PDU_UNKNOWN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_CUR_DUP_PDU_CNTR(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0C05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_CUR_DUP_PDU_CNTR(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MAX_DUP_PDU_CNTR(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0D05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_MAX_DUP_PDU_CNTR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_POLL(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0E05 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_POLL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AM_SEG(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0F05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_RX_AM_SEG(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AM_SEG_LSF(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1005 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_RX_AM_SEG_LSF(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AM_SEG_OOW(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1105 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_RX_AM_SEG_OOW(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AM_SEG_DUP(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1205 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_RX_AM_SEG_DUP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AM_SEG_BAD_SZ(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1305 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_AM_SEG_BAD_SZ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AM_PDU(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1405 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_AM_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AM_PDU_OOW(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1505 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_RX_AM_PDU_OOW(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AM_PDU_DUP(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1605 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_RX_AM_PDU_DUP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AM_PDU_BAD_SZ(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1705 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_AM_PDU_BAD_SZ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM5_PDU(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1805 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM5_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM5_PDU_DRP(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1905 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM5_PDU_DRP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM5_PDU_DUP(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1A05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM5_PDU_DUP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM5_PDU_BAD_SZ(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1B05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM5_PDU_BAD_SZ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM10_PDU(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1C05 | ((short)(v2) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM10_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM10_PDU_DRP(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1D05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM10_PDU_DRP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM10_PDU_DUP(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1E05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM10_PDU_DUP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM10_PDU_BAD_SZ(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1F05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM10_PDU_BAD_SZ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM10_PDU_BAD_R1(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2005 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM10_PDU_BAD_R1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM_PDU_DRP_N(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2105 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM_PDU_DRP_N(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_LI_VAL_ERR(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2205 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_LI_VAL_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_LI_SUM_ERR(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2305 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_LI_SUM_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_FI_LI_INFO_NO_LI(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2405 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_FI_LI_INFO_NO_LI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_FI_LI_INFO(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x2505 | ((short)(v2) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((short)(v4))) << 16), (kal_uint32)((char)(v1)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_FI_LI_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_FAIL_TO_ALLOC_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2605 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_FAIL_TO_ALLOC_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_FAIL_TO_ALLOC_NACK(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x2705 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (unsigned long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_FAIL_TO_ALLOC_NACK(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_NACK_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2805 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_NACK_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_NACK_SEG(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2905 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_NACK_SEG(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_STUS_PDU(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2A05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_STUS_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_STUS_PDU_BAD_SZ(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2B05 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_STUS_PDU_BAD_SZ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_STUS_PDU_BAD_CPT(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2C05 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_STUS_PDU_BAD_CPT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_STUS_PDU_BAD_E(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2D05 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_STUS_PDU_BAD_E(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_ADD_NACK_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2E05 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_ADD_NACK_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_ADD_NACK_SEG(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2F05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_ADD_NACK_SEG(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_GEN_STUS_PDU(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3005 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_GEN_STUS_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SEG_STUS_PDU(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3105 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_SEG_STUS_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_FORCE_STUS_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3205 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_FORCE_STUS_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RSB_SDU_BAD_SZ(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3305 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RSB_SDU_BAD_SZ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RSB_PDU_BAD_LI() do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x3405 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_RSB_PDU_BAD_LI()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RSB_PDU_BAD_FI(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x3505 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RSB_PDU_BAD_FI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RSB_FULL_PDU_DISCARD(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3605 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_RSB_FULL_PDU_DISCARD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_CHK_OK(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3705 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_CHK_OK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_CACHE(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3805 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_CACHE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_OOW(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x3905 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_OOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_INVALID(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x3A05 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_INVALID(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CHK(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3B05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CHK(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_CHK(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3C05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_CHK(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDU_TS_OOO(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x3D05 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDU_TS_OOO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDU_MODIFY_TS(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3E05 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDU_MODIFY_TS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDU_MODIFY_SN(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3F05 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDU_MODIFY_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_RST_COPRO_IDX(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4005 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_RST_COPRO_IDX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_POLL_IN_COPRO_OFF(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4105 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_POLL_IN_COPRO_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_ZERO(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4205 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_ZERO(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_ADD_SRB(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4305 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_ADD_SRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_ADD_DRB_1(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4405 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_ADD_DRB_1(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_ADD_DRB_2(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4505 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_ADD_DRB_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_DEL_SRB(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4605 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_DEL_SRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_DEL_DRB(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4705 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_DEL_DRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_DEL_OLD_DRB(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4805 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_DEL_OLD_DRB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_DEL_NEW_DRB(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4905 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_DEL_NEW_DRB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_RECFG_RB(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4A05 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_RECFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_REEST_WI_CFG_RB(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4B05 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_REEST_WI_CFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_REEST_WO_CFG_RB(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4C05 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_REEST_WO_CFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VOLTE_RB_STATUS(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4D05 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24));\
	} while(0)
#else
	#define ERLC_LOG_VOLTE_RB_STATUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_RB_PARAM_ERR(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4E05 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_RB_PARAM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_RB_STUS_ERR(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4F05 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_RB_STUS_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_HWB_STATS(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x5005 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_DL_HWB_STATS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_HWB_STATS_2048(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x5105 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_HWB_STATS_2048(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_HWB_STATS_4096(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x5205 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_HWB_STATS_4096(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_PDU_POOL_STATS(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x5305 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_PDU_POOL_STATS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_HWB_EXHAUST(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5405 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_HWB_EXHAUST(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_HWB_EXHAUST_SEND_STATUS(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5505 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_HWB_EXHAUST_SEND_STATUS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_HWB_EXHAUST_FLUSH_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5605 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_HWB_EXHAUST_FLUSH_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_DATA_LOSS_START(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5705 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_DATA_LOSS_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_DATA_LOSS_END(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5805 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_DATA_LOSS_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_DATA_LOSS_TMOUT(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5905 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_DATA_LOSS_TMOUT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MBMS_ADD_MRB(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5A05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_MBMS_ADD_MRB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MBMS_DEL_MRB(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5B05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_MBMS_DEL_MRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MBMS_SWAP_IDX_TBL(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5C05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_MBMS_SWAP_IDX_TBL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MBMS_ADD_MCCH(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5D05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_MBMS_ADD_MCCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MBMS_DEL_MCCH(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5E05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_MBMS_DEL_MCCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MBMS_REASM_MRB(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5F05 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_MBMS_REASM_MRB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MBMS_REASM_POLL(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6005 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_MBMS_REASM_POLL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_POLL_FUNC(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6105 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define ERLC_LOG_DL_POLL_FUNC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_INJ_DL_DEBUG_FILTER(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6205 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define ERLC_LOG_INJ_DL_DEBUG_FILTER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RECFG_SNF_LEN_CHG(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6305 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RECFG_SNF_LEN_CHG(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char ERLCDL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_ERLC_LOG_DL_STATE_VAR_AM(char v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_DL_STATE_VAR_AM_EQ(char v1, short v2);
void L1TRC_Send_ERLC_LOG_DL_STATE_VAR_UM(char v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_DL_STATE_VAR_UM_EQ(char v1, short v2);
void L1TRC_Send_ERLC_LOG_T_REORDER_START_AM(short v1, short v2);
void L1TRC_Send_ERLC_LOG_T_REORDER_START_UM(short v1, short v2);
void L1TRC_Send_ERLC_LOG_T_REORDER_STOP(short v1);
void L1TRC_Send_ERLC_LOG_T_REORDER_EXPRY(short v1);
void L1TRC_Send_ERLC_LOG_T_REORDER_EXPRY_FAKE(short v1);
void L1TRC_Send_ERLC_LOG_T_REORDER_EXPRY_MULTI(short v1);
void L1TRC_Send_ERLC_LOG_T_REORDER_UM_FORCE_45MS(unsigned short v1);
void L1TRC_Send_ERLC_LOG_RLC_PDU_UNKNOWN(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_ERLC_LOG_CUR_DUP_PDU_CNTR(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_MAX_DUP_PDU_CNTR(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_POLL(short v1);
void L1TRC_Send_ERLC_LOG_RX_AM_SEG(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_RX_AM_SEG_LSF(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_RX_AM_SEG_OOW(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_RX_AM_SEG_DUP(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_RX_AM_SEG_BAD_SZ(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_AM_PDU(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_AM_PDU_OOW(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_RX_AM_PDU_DUP(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_RX_AM_PDU_BAD_SZ(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_UM5_PDU(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_UM5_PDU_DRP(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_UM5_PDU_DUP(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_UM5_PDU_BAD_SZ(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_UM10_PDU(char v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_UM10_PDU_DRP(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_UM10_PDU_DUP(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_UM10_PDU_BAD_SZ(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_UM10_PDU_BAD_R1(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_UM_PDU_DRP_N(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_LI_VAL_ERR(short v1, short v2);
void L1TRC_Send_ERLC_LOG_LI_SUM_ERR(short v1, short v2);
void L1TRC_Send_ERLC_LOG_FI_LI_INFO_NO_LI(short v1);
void L1TRC_Send_ERLC_LOG_FI_LI_INFO(char v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_FAIL_TO_ALLOC_PDU(short v1);
void L1TRC_Send_ERLC_LOG_FAIL_TO_ALLOC_NACK(short v1, short v2, short v3, unsigned long v4);
void L1TRC_Send_ERLC_LOG_RX_NACK_PDU(short v1);
void L1TRC_Send_ERLC_LOG_RX_NACK_SEG(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_STUS_PDU(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RX_STUS_PDU_BAD_SZ(short v1);
void L1TRC_Send_ERLC_LOG_RX_STUS_PDU_BAD_CPT(short v1);
void L1TRC_Send_ERLC_LOG_RX_STUS_PDU_BAD_E(short v1);
void L1TRC_Send_ERLC_LOG_ADD_NACK_PDU(short v1);
void L1TRC_Send_ERLC_LOG_ADD_NACK_SEG(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_GEN_STUS_PDU(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_SEG_STUS_PDU(short v1, short v2);
void L1TRC_Send_ERLC_LOG_FORCE_STUS_PDU(short v1);
void L1TRC_Send_ERLC_LOG_RSB_SDU_BAD_SZ(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_RSB_PDU_BAD_LI(void);
void L1TRC_Send_ERLC_LOG_RSB_PDU_BAD_FI(short v1);
void L1TRC_Send_ERLC_LOG_RSB_FULL_PDU_DISCARD(short v1, short v2);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_CHK_OK(short v1, short v2);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_CACHE(short v1, short v2);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_OOW(short v1);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_INVALID(long v1, long v2);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CHK(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_CHK(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDU_TS_OOO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDU_MODIFY_TS(unsigned short v1, unsigned short v2);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDU_MODIFY_SN(unsigned short v1, unsigned short v2);
void L1TRC_Send_ERLC_LOG_DL_RST_COPRO_IDX(short v1);
void L1TRC_Send_ERLC_LOG_DL_POLL_IN_COPRO_OFF(short v1);
void L1TRC_Send_ERLC_LOG_T_REORDER_ZERO(short v1);
void L1TRC_Send_ERLC_LOG_DL_ADD_SRB(short v1, short v2);
void L1TRC_Send_ERLC_LOG_DL_ADD_DRB_1(short v1, short v2);
void L1TRC_Send_ERLC_LOG_DL_ADD_DRB_2(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_DL_DEL_SRB(short v1, short v2);
void L1TRC_Send_ERLC_LOG_DL_DEL_DRB(short v1, short v2);
void L1TRC_Send_ERLC_LOG_DL_DEL_OLD_DRB(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_DL_DEL_NEW_DRB(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_DL_RECFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_DL_REEST_WI_CFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_DL_REEST_WO_CFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_VOLTE_RB_STATUS(unsigned char v1, unsigned char v2);
void L1TRC_Send_ERLC_LOG_DL_RB_PARAM_ERR(short v1);
void L1TRC_Send_ERLC_LOG_DL_RB_STUS_ERR(short v1);
void L1TRC_Send_ERLC_LOG_DL_HWB_STATS(short v1, short v2);
void L1TRC_Send_ERLC_LOG_DL_HWB_STATS_2048(short v1);
void L1TRC_Send_ERLC_LOG_DL_HWB_STATS_4096(short v1);
void L1TRC_Send_ERLC_LOG_PDU_POOL_STATS(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_HWB_EXHAUST(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_HWB_EXHAUST_SEND_STATUS(short v1);
void L1TRC_Send_ERLC_LOG_HWB_EXHAUST_FLUSH_PDU(short v1);
void L1TRC_Send_ERLC_LOG_RX_DATA_LOSS_START(short v1);
void L1TRC_Send_ERLC_LOG_RX_DATA_LOSS_END(short v1);
void L1TRC_Send_ERLC_LOG_RX_DATA_LOSS_TMOUT(short v1);
void L1TRC_Send_ERLC_LOG_MBMS_ADD_MRB(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_MBMS_DEL_MRB(short v1, short v2);
void L1TRC_Send_ERLC_LOG_MBMS_SWAP_IDX_TBL(short v1, short v2);
void L1TRC_Send_ERLC_LOG_MBMS_ADD_MCCH(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_MBMS_DEL_MCCH(short v1, short v2);
void L1TRC_Send_ERLC_LOG_MBMS_REASM_MRB(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_MBMS_REASM_POLL(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_DL_POLL_FUNC(unsigned long v1);
void L1TRC_Send_ERLC_LOG_INJ_DL_DEBUG_FILTER(unsigned long v1);
void L1TRC_Send_ERLC_LOG_RECFG_SNF_LEN_CHG(short v1);

void Set_ERLCDL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_ERLCDL()	(ERLCDL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()	(ChkL1ModFltr_ERLCDL()&&((ERLCDL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()	(ChkL1ModFltr_ERLCDL()&&((ERLCDL_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_ERLC_LOG_DL_STATE_VAR_AM()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_STATE_VAR_AM_EQ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_STATE_VAR_UM()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_STATE_VAR_UM_EQ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_START_AM()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_START_UM()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_STOP()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_EXPRY()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_EXPRY_FAKE()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_EXPRY_MULTI()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_UM_FORCE_45MS()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RLC_PDU_UNKNOWN()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_CUR_DUP_PDU_CNTR()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_MAX_DUP_PDU_CNTR()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_POLL()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_AM_SEG()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_AM_SEG_LSF()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_AM_SEG_OOW()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_AM_SEG_DUP()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_AM_SEG_BAD_SZ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_AM_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_AM_PDU_OOW()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_AM_PDU_DUP()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_AM_PDU_BAD_SZ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM5_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM5_PDU_DRP()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM5_PDU_DUP()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM5_PDU_BAD_SZ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM10_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM10_PDU_DRP()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM10_PDU_DUP()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM10_PDU_BAD_SZ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM10_PDU_BAD_R1()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM_PDU_DRP_N()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_LI_VAL_ERR()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_LI_SUM_ERR()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_FI_LI_INFO_NO_LI()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_FI_LI_INFO()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_FAIL_TO_ALLOC_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_FAIL_TO_ALLOC_NACK()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_NACK_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_NACK_SEG()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_STUS_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_STUS_PDU_BAD_SZ()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_STUS_PDU_BAD_CPT()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_STUS_PDU_BAD_E()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_ADD_NACK_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_ADD_NACK_SEG()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_GEN_STUS_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SEG_STUS_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_FORCE_STUS_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RSB_SDU_BAD_SZ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RSB_PDU_BAD_LI()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RSB_PDU_BAD_FI()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RSB_FULL_PDU_DISCARD()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_CHK_OK()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_CACHE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_OOW()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_INVALID()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CHK()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_CHK()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDU_TS_OOO()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDU_MODIFY_TS()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDU_MODIFY_SN()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_RST_COPRO_IDX()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_POLL_IN_COPRO_OFF()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_ZERO()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_ADD_SRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_ADD_DRB_1()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_ADD_DRB_2()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_DEL_SRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_DEL_DRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_DEL_OLD_DRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_DEL_NEW_DRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_RECFG_RB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_REEST_WI_CFG_RB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_REEST_WO_CFG_RB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_VOLTE_RB_STATUS()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_RB_PARAM_ERR()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_RB_STUS_ERR()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_HWB_STATS()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_HWB_STATS_2048()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_HWB_STATS_4096()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_PDU_POOL_STATS()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_HWB_EXHAUST()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_HWB_EXHAUST_SEND_STATUS()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_HWB_EXHAUST_FLUSH_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_DATA_LOSS_START()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_DATA_LOSS_END()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_DATA_LOSS_TMOUT()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_MBMS_ADD_MRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_MBMS_DEL_MRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_MBMS_SWAP_IDX_TBL()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_MBMS_ADD_MCCH()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_MBMS_DEL_MCCH()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_MBMS_REASM_MRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_MBMS_REASM_POLL()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_POLL_FUNC()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_INJ_DL_DEBUG_FILTER()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RECFG_SNF_LEN_CHG()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()


#endif
