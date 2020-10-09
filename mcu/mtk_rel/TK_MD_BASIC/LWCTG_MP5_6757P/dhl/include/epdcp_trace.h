#ifndef L1TRC_EPDCP_DEF_H
#define L1TRC_EPDCP_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_START_POLLING(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0009 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_START_POLLING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_RX_PDU_CNT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0109 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_RX_PDU_CNT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SEND_DCCH_DATA_IND(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0209 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SEND_DCCH_DATA_IND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_SRB_PDU_INT_ERR(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0309 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_SRB_PDU_INT_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_PDU_BY_STATE(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0409 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_PDU_BY_STATE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_PDU_BY_HDR_ERR_OR_ZERO_LEN(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x0509 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_PDU_BY_HDR_ERR_OR_ZERO_LEN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_PDU_TO_STOP_CHNL(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0609 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_PDU_TO_STOP_CHNL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_PDU_BY_FLUSH(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0709 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_PDU_BY_FLUSH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UTILIZE_TAIL_GPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0809 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UTILIZE_TAIL_GPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_PDU_BY_TAIL_DONE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0909 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_PDU_BY_TAIL_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RESTORE_DL_QMU(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0A09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RESTORE_DL_QMU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EXEC_DL_ROHC(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0B09 | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_EXEC_DL_ROHC(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_OOW_PDU_HWM_DCIP(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0C09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REL_OOW_PDU_HWM_DCIP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_OOW_PDU_SWM_DCIP(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0D09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REL_OOW_PDU_SWM_DCIP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_NXT_SRB1_DL_PDU(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0E09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_NXT_SRB1_DL_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INV_UM_STATUS_REPORT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0F09 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_INV_UM_STATUS_REPORT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RX_ROHC_FBK_PDU(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1009 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RX_ROHC_FBK_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RX_FDBK_WHEN_NO_ROHC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1109 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RX_FDBK_WHEN_NO_ROHC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RX_INVALID_CTRL_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1209 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RX_INVALID_CTRL_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RX_INVALID_R_BIT_PDU(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x1309 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RX_INVALID_R_BIT_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_GATHER_GPD_RESULT(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1409 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_GATHER_GPD_RESULT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CE_OUTPUT_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1509 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_CE_OUTPUT_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INT_PROT_DL_MACI_CMP(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1609 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_INT_PROT_DL_MACI_CMP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_RBUF_RGPD_SWITCH(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1709 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DL_RBUF_RGPD_SWITCH(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPDT_DL_UMDRB_SN(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x1809 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UPDT_DL_UMDRB_SN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STILL_WAIT_FOR_FLUSH(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1909 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_STILL_WAIT_FOR_FLUSH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FLUSH_FOR_REEST_DONE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1A09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FLUSH_FOR_REEST_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FLUSH_FOR_REL_DONE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1B09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FLUSH_FOR_REL_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_POLLING_DL_ROHC_RESULT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1C09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_POLLING_DL_ROHC_RESULT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_OOW_PDU_AFTER_ROHC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1D09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REL_OOW_PDU_AFTER_ROHC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRB_DLVR_BMP(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x1E09 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DRB_DLVR_BMP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRB_HAS_DL_DATA_TO_LTM(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1F09 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DRB_HAS_DL_DATA_TO_LTM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SEND_LTM_DATA_IND(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2009 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SEND_LTM_DATA_IND(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INS_TO_DL_WND(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2109 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_INS_TO_DL_WND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_PDCP_SN_OOO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2209 | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_DL_PDCP_SN_OOO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_DUPL_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2309 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REL_DUPL_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_AM_INORDR_DLVR(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2409 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_AM_INORDR_DLVR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RELOAD_DL_GPDS(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2509 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RELOAD_DL_GPDS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RELOAD_DL_GPDS_IN_HO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2609 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RELOAD_DL_GPDS_IN_HO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STATUS_RPRT_WND_INFO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2709 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_STATUS_RPRT_WND_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_GEN_STATUS_RPRT(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2809 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_GEN_STATUS_RPRT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STATUS_EXCEED_MAX_LEN(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2909 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_STATUS_EXCEED_MAX_LEN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DUMP_DRB_RGPD_INFO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2A09 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DUMP_DRB_RGPD_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CURR_DL_SN_INFO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2B09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_CURR_DL_SN_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FC_DLVR_PDUS_IN_WND(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x2C09 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FC_DLVR_PDUS_IN_WND(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FC_UPDT_LAST_SUB_SN(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x2D09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FC_UPDT_LAST_SUB_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FC_ENTER(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2E09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FC_ENTER(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_PDCP_CNT_2_IPID(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2F09 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DL_PDCP_CNT_2_IPID(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SEND_MCCH_DATA_IND(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3009 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SEND_MCCH_DATA_IND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SEND_MTCH_DATA_IND(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3109 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SEND_MTCH_DATA_IND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_ALLOC_SPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3209 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_ALLOC_SPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_DUMP_RBUF_INFO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3309 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DL_DUMP_RBUF_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_INVALID_RBUF(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3409 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_INVALID_RBUF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FOUND_RBUF(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3509 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FOUND_RBUF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_PIT_RW_IDX(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3609 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_PIT_RW_IDX(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_PIT_INFO1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3709 | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_DL_PIT_INFO1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_PIT_INFO2(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3809 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DL_PIT_INFO2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_HEAD(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3909 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_HEAD(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_TAIL(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3A09 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_TAIL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_COUNT_GAP(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x3B09 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v1), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_COUNT_GAP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_DATA_LEN(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3C09 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_DATA_LEN(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_PKT_NUM(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3D09 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_PKT_NUM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_RBUF_DATA_IND(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3E09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_RBUF_DATA_IND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_DUMP_LEN(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3F09 | ((unsigned short)(v2) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_DUMP_LEN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_DUMP_PI_RAW(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x4009 | ((unsigned short)(v2) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_DUMP_PI_RAW(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_DUMP_PIE_RAW(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4109 | ((unsigned short)(v2) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)((unsigned short)(v4))) << 16), (unsigned long)(v1));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_DUMP_PIE_RAW(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_DUMP_PIE_READ(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4209 | ((unsigned short)(v2) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)((unsigned short)(v4))) << 16), (unsigned long)(v1));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_DUMP_PIE_READ(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_DUMP_IP_INFO(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4309 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_DUMP_IP_INFO(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPD_DUMP_LIST(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4409 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPD_DUMP_LIST(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_RBUF_PIT_REMAIN(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4509 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DL_RBUF_PIT_REMAIN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_INIT_RBUF(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4609 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_DL_INIT_RBUF(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_REL_PIT_IDX(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4709 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_REL_PIT_IDX(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_REL_FOUND_RBUF(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4809 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_REL_FOUND_RBUF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SORT_START(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4909 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SORT_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SORT_CMP(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4A09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SORT_CMP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SORT_END(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4B09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SORT_END(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_REL_TBL_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4C09 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_DL_REL_TBL_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_REL_AVAIL_ENTRY_FOUND(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4D09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_REL_AVAIL_ENTRY_FOUND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_REL_IDX_DUMP(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4E09 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_REL_IDX_DUMP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_REL_INC_DRV_CNT(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4F09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_REL_INC_DRV_CNT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_SPLIT_SPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5009 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_SPLIT_SPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RCV_LB_CFG_REQ(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5109 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RCV_LB_CFG_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_LB_CFG_CNF(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5209 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SND_LB_CFG_CNF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_WRONG_IN_LB_CFG_REQ(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x5309 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_WRONG_IN_LB_CFG_REQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LB_WI_SCALE(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x5409 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_LB_WI_SCALE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LB_WO_SCALE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5509 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LB_WO_SCALE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LB_DISC_PDU(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5609 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LB_DISC_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ENABLE_DRB_LB_MODE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5709 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ENABLE_DRB_LB_MODE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRB_LB_MODE_C_OK(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5809 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DRB_LB_MODE_C_OK(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRB_LB_MODE_C_NOT_OK(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5909 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DRB_LB_MODE_C_NOT_OK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPD_SEC_PARAM_CIP(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5A09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UPD_SEC_PARAM_CIP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPD_SEC_PARAM_INT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5B09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UPD_SEC_PARAM_INT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPD_SEC_IN_SRB_HW(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5C09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UPD_SEC_IN_SRB_HW(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPD_SEC_IN_DRB_HW(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x5D09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UPD_SEC_IN_DRB_HW(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ACTIVATE_DL_SEC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5E09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_ACTIVATE_DL_SEC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ACTIVATE_UL_SEC(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5F09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_ACTIVATE_UL_SEC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CHK_INACT_TMR_EVENT(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x6009 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_CHK_INACT_TMR_EVENT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RCV_DETN_TMR_START_REQ(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6109 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RCV_DETN_TMR_START_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_DETN_TMR_TMOUT_IND(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6209 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SND_DETN_TMR_TMOUT_IND(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_PS_DATA_INACT_IND(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x6309 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SND_PS_DATA_INACT_IND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UDRX_TMR_TMOUT(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6409 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_UDRX_TMR_TMOUT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UDRX_TMR_RESTART(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6509 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_UDRX_TMR_RESTART(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RCV_CNT_INFO_REQ(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6609 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RCV_CNT_INFO_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_CNT_INFO_CNF(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6709 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SND_CNT_INFO_CNF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SHOW_DRB_COUNT_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x6809 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_SHOW_DRB_COUNT_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RCV_CFG_REQ(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6909 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RCV_CFG_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_CFG_CNF(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6A09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SND_CFG_CNF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PROC_CONFIG_REQ(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x6B09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_PROC_CONFIG_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EXEC_SAVED_CFG_REQ(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x6C09 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_EXEC_SAVED_CFG_REQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SAVE_CFG_REQ(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x6D09 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SAVE_CFG_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_WRONG_IN_CFG_REQ(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x6E09 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_WRONG_IN_CFG_REQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DEL_RB_HNDLR(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6F09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DEL_RB_HNDLR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DELETE_RB(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x7009 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DELETE_RB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_MODIFY_RB(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x7109 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_MODIFY_RB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ESTABLISH_RB(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x7209 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ESTABLISH_RB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_MODE_CHNG(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7309 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SND_MODE_CHNG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EST_SRB_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x7409 | ((short)(v1) << 16), (kal_uint32)((char)(v4)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_EST_SRB_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RESUME_SRB_INFO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x7509 | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RESUME_SRB_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EST_DRB_INFO_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x7609 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_EST_DRB_INFO_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EST_DRB_INFO_2(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x7709 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_EST_DRB_INFO_2(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EST_DRB_INFO_3(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x7809 | ((short)(v1) << 16), (kal_uint32)((char)(v4)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_EST_DRB_INFO_3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RECFG_DRB_INFO_1(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x7909 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RECFG_DRB_INFO_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RECFG_DRB_INFO_2(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x7A09 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RECFG_DRB_INFO_2(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ADD_ROHC_CHNL(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7B09 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_ADD_ROHC_CHNL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DEL_ROHC_CHNL(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7C09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DEL_ROHC_CHNL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CHNG_ROHC_CHNL(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7D09 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_CHNG_ROHC_CHNL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_NOT_CHNG_ROHC_CHNL(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7E09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_NOT_CHNG_ROHC_CHNL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ROHC_NOT_SUPPORT(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x7F09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_ROHC_NOT_SUPPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TOGGLE_ACTV_ENT_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x8009 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_TOGGLE_ACTV_ENT_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TOGGLE_ACTV_ENT_2(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8109 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_TOGGLE_ACTV_ENT_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RECFG_UM_HW_CHNL(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x8209 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RECFG_UM_HW_CHNL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RECFG_AM_HW_CIP_CHNL(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x8309 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RECFG_AM_HW_CIP_CHNL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RECFG_AM_HW_DCIP_CHNL(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x8409 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RECFG_AM_HW_DCIP_CHNL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RELEASE_DRB(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x8509 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RELEASE_DRB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_DL_PDUS(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8609 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_REL_DL_PDUS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REDIR_UL_DATA(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8709 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REDIR_UL_DATA(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_IDC_START(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8809 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_IDC_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_IDC_END(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8909 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_IDC_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PWRDWN_HW(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8A09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_PWRDWN_HW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REINIT_HW(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8B09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_REINIT_HW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PWRON_CIP_QUEUE_INFO_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8C09 | ((short)(v1) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)((char)(v2))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_PWRON_CIP_QUEUE_INFO_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PWRON_CIP_QUEUE_INFO_2(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8D09 | ((short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((short)(v4))) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_PWRON_CIP_QUEUE_INFO_2(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PWRON_CIP_QUEUE_INFO_3(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8E09 | ((short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((short)(v4))) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_PWRON_CIP_QUEUE_INFO_3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INV_SEC_STATE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8F09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_INV_SEC_STATE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_FORCE_DISABLE_ROHC(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x9009 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_FORCE_DISABLE_ROHC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_VOLTE_EBI_IND(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9109 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_VOLTE_EBI_IND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPCM_IMS_BEARER_BMP(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9209 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define EPDCP_LOG_UPCM_IMS_BEARER_BMP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CFG_RBUF_ENABLE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9309 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_CFG_RBUF_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_DCCH_DATA_CNF(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9409 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SND_DCCH_DATA_CNF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CFN_DISC_MSG_IN_ACK_TBL(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9509 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_CFN_DISC_MSG_IN_ACK_TBL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CFN_DISC_MSG_IN_CIP_QUE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9609 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_CFN_DISC_MSG_IN_CIP_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CFN_DISC_MSG_IN_SDU_QUE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9709 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_CFN_DISC_MSG_IN_SDU_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CLEAN_ROHC_QUE_RSLT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9809 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_CLEAN_ROHC_QUE_RSLT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UNROHC_RETX_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9909 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UNROHC_RETX_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_ROHC_FBK_PDU(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9A09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_REL_ROHC_FBK_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UNROHC_SDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9B09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UNROHC_SDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UNROHC_RSLT_CNT(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9C09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UNROHC_RSLT_CNT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STOP_UL_ROHC(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9D09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_STOP_UL_ROHC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CLEAR_CIP_QUE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9E09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_CLEAR_CIP_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_CTRL_QUE_SIZE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9F09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_REL_CTRL_QUE_SIZE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RETX_PDU_WI_SAVED_PC(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xA009 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RETX_PDU_WI_SAVED_PC(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RETX_PDU_WO_SAVED_PC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA109 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RETX_PDU_WO_SAVED_PC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRBUM_RESUME_TX_INFO_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xA209 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DRBUM_RESUME_TX_INFO_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRBUM_RESUME_TX_INFO_2(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA309 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DRBUM_RESUME_TX_INFO_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xA409 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_2(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA509 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_3(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xA609 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RETX_PDU_WI_NEW_SN(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA709 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RETX_PDU_WI_NEW_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RETX_PDU_WI_OLD_SN(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA809 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RETX_PDU_WI_OLD_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_WRONG_IN_DCCH_DATA(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0xA909 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_WRONG_IN_DCCH_DATA(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_WRONG_IN_PDCP_DATA_REQ(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0xAA09 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_WRONG_IN_PDCP_DATA_REQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_PARTIAL_DATA_REQ(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0xAB09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_PARTIAL_DATA_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_PDCP_DATA_REQ(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0xAC09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_PDCP_DATA_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ACPT_PDCP_DATA_REQ(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0xAD09 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ACPT_PDCP_DATA_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ENQ_TO_UL_ROHC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xAE09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_ENQ_TO_UL_ROHC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRB_ENQ_TO_UL_CIP_HW(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xAF09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DRB_ENQ_TO_UL_CIP_HW(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_ENQ_TO_UL_CIP_HW(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB009 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_ENQ_TO_UL_CIP_HW(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_BKT_VACANCY(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB109 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_BKT_VACANCY(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_FORM_ROHC_FBK_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB209 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_FORM_ROHC_FBK_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_FORM_SRB_DATA_PDU(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB309 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UL_FORM_SRB_DATA_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_VOLTE_DATA_REQ(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB409 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_VOLTE_DATA_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PRETX_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0xB509 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_PRETX_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ROHC_FBK_ENQ_NML_QUE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB609 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ROHC_FBK_ENQ_NML_QUE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ROHC_FBK_ENQ_CTRL_QUE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB709 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ROHC_FBK_ENQ_CTRL_QUE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RCV_UL_ROHC_RSLT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB809 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RCV_UL_ROHC_RSLT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_ROHC_OF_RETX_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB909 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_ROHC_OF_RETX_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_ROHC_OF_PRI_SDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xBA09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_ROHC_OF_PRI_SDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_ROHC_OF_NML_SDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xBB09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_ROHC_OF_NML_SDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SEARCH_TMOUT_SDU(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xBC09 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SEARCH_TMOUT_SDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TMOUT_IN_CIP_QUE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xBD09 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_TMOUT_IN_CIP_QUE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xBE09 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_2(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xBF09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_3(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xC009 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_END(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xC109 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STOP_DISC_TMOUT_GPD(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC209 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_STOP_DISC_TMOUT_GPD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RESEND_UNTXSCHED_GPDS(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xC309 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RESEND_UNTXSCHED_GPDS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CTRL_PDU_INFO(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xC409 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_CTRL_PDU_INFO(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TMOUT_PDU_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xC509 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_TMOUT_PDU_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_NTMOUT_PDU_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xC609 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_NTMOUT_PDU_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TMOUT_RETX_Q_PDU_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xC709 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_TMOUT_RETX_Q_PDU_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_NTMOUT_RETX_Q_PDU_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xC809 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_NTMOUT_RETX_Q_PDU_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TMOUT_QUEUED_SDU_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xC909 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_TMOUT_QUEUED_SDU_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_DESYNC_AVOID_TRICK1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xCA09 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UL_DESYNC_AVOID_TRICK1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_DESYNC_AVOID_TRICK2(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xCB09 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UL_DESYNC_AVOID_TRICK2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_RETX_Q_END(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xCC09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_RETX_Q_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_SDU_Q_END(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xCD09 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_SDU_Q_END(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INT_PROT_PARAM(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xCE09 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_INT_PROT_PARAM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INT_PROT_RSLT_MACI(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xCF09 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_INT_PROT_RSLT_MACI(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RB_UL_BKT_INFO_1(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xD009 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RB_UL_BKT_INFO_1(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RB_UL_BKT_INFO_2(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xD109 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RB_UL_BKT_INFO_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RB_UL_BKT_INFO_3(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xD209 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RB_UL_BKT_INFO_3(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RB_UL_BKT_INFO_4(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xD309 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RB_UL_BKT_INFO_4(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UMDRB_REL_ULGPD_START(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0xD409 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UMDRB_REL_ULGPD_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SCHED_GPD_DELAY(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xD509 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SCHED_GPD_DELAY(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_SCHED_CIP_QUE_GPD(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xD609 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_REL_SCHED_CIP_QUE_GPD(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UNSCHED_CIP_QUE_GPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xD709 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UNSCHED_CIP_QUE_GPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_AMDRB_ACK_ULGPD_START(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0xD809 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_AMDRB_ACK_ULGPD_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ACKED_GPD_DELAY(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xD909 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ACKED_GPD_DELAY(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_ACKED_CIP_QUE_GPD(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xDA09 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_REL_ACKED_CIP_QUE_GPD(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UNACKED_CIP_QUE_GPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xDB09 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UNACKED_CIP_QUE_GPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ENABLE_UL_FC(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDC09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_ENABLE_UL_FC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISABLE_UL_FC(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDD09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DISABLE_UL_FC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ACPT_DCCH_DATA_REQ(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xDE09 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ACPT_DCCH_DATA_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_REL_CPLT_GPD(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xDF09 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_REL_CPLT_GPD(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_DATA_ACK_HNDLR(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE009 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_DATA_ACK_HNDLR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_ACK_ULSDU(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE109 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_ACK_ULSDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_ACK_ULSDU_CIP_QUE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE209 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_ACK_ULSDU_CIP_QUE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_ACK_ULSDU_START(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xE309 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_ACK_ULSDU_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_UPD_NXT_REl_SIT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE409 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_UPD_NXT_REl_SIT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PROC_STATUS_REPORT(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE509 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_PROC_STATUS_REPORT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_RPRT_BITMAP_LONG(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE609 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_RPRT_BITMAP_LONG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_RPRT_REF_FMS_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xE709 | ((short)(v1) << 16), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_RPRT_REF_FMS_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xE809 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_2(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE909 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_3(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xEA09 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_END(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xEB09 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STOP_DISC_ACKED_GPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xEC09 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_STOP_DISC_ACKED_GPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_PDU_SIT_AND_SN(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xED09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_PDU_SIT_AND_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_REQ_TO_RLC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xEE09 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_REQ_TO_RLC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INV_FMS_STATUS_REPORT(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0xEF09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_INV_FMS_STATUS_REPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_GPD_N_IP_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xF009 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UL_GPD_N_IP_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_CIP_GPD_N_IP_INFO(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xF109 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_CIP_GPD_N_IP_INFO(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_PDCP_CNT_2_IPID(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xF209 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UL_PDCP_CNT_2_IPID(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_FC_DROP_SDU(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xF309 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UL_FC_DROP_SDU(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_FC_CHK_DRB_UL_STATUS(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xF409 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UL_FC_CHK_DRB_UL_STATUS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_SDU_SENT_N_UNACKED(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xF509 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UL_SDU_SENT_N_UNACKED(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_SEND_AUTO_RLC_POLL(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF609 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_UL_SEND_AUTO_RLC_POLL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_MAX_UL_BKT(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xF709 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define EPDCP_LOG_MAX_UL_BKT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INJ_CHG_REL_GPD_NUM(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0xF809 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_INJ_CHG_REL_GPD_NUM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INJ_CHG_DLFC_DLVR_ENTER_THRSH(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0xF909 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_INJ_CHG_DLFC_DLVR_ENTER_THRSH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INJ_CHG_DLFC_DLVR_CNT(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0xFA09 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_INJ_CHG_DLFC_DLVR_CNT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DUMMY_SIGNED(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0xFB09 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DUMMY_SIGNED(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DUMMY(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0xFC09 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DUMMY(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DUMMY_HEX(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0xFD09 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DUMMY_HEX(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EPDCP_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EPDCP_LOG_START_POLLING(short v1);
void L1TRC_Send_EPDCP_LOG_SRB_RX_PDU_CNT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_SEND_DCCH_DATA_IND(short v1, short v2, long v3);
void L1TRC_Send_EPDCP_LOG_DROP_SRB_PDU_INT_ERR(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DROP_PDU_BY_STATE(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_DROP_PDU_BY_HDR_ERR_OR_ZERO_LEN(short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_DROP_PDU_TO_STOP_CHNL(short v1);
void L1TRC_Send_EPDCP_LOG_DROP_PDU_BY_FLUSH(short v1);
void L1TRC_Send_EPDCP_LOG_UTILIZE_TAIL_GPD(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_DROP_PDU_BY_TAIL_DONE(short v1);
void L1TRC_Send_EPDCP_LOG_RESTORE_DL_QMU(short v1);
void L1TRC_Send_EPDCP_LOG_EXEC_DL_ROHC(short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_REL_OOW_PDU_HWM_DCIP(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_REL_OOW_PDU_SWM_DCIP(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_NXT_SRB1_DL_PDU(short v1);
void L1TRC_Send_EPDCP_LOG_INV_UM_STATUS_REPORT(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RX_ROHC_FBK_PDU(short v1);
void L1TRC_Send_EPDCP_LOG_RX_FDBK_WHEN_NO_ROHC(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RX_INVALID_CTRL_PDU(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RX_INVALID_R_BIT_PDU(short v1);
void L1TRC_Send_EPDCP_LOG_GATHER_GPD_RESULT(short v1, short v2, short v3);
void L1TRC_Send_EPDCP_LOG_CE_OUTPUT_INFO(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_INT_PROT_DL_MACI_CMP(short v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DL_RBUF_RGPD_SWITCH(unsigned short v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_UPDT_DL_UMDRB_SN(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_STILL_WAIT_FOR_FLUSH(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DL_FLUSH_FOR_REEST_DONE(short v1);
void L1TRC_Send_EPDCP_LOG_DL_FLUSH_FOR_REL_DONE(short v1);
void L1TRC_Send_EPDCP_LOG_POLLING_DL_ROHC_RESULT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_REL_OOW_PDU_AFTER_ROHC(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DRB_DLVR_BMP(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_DRB_HAS_DL_DATA_TO_LTM(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_SEND_LTM_DATA_IND(short v1);
void L1TRC_Send_EPDCP_LOG_INS_TO_DL_WND(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DL_PDCP_SN_OOO(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_REL_DUPL_PDU(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_AM_INORDR_DLVR(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_RELOAD_DL_GPDS(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_RELOAD_DL_GPDS_IN_HO(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_STATUS_RPRT_WND_INFO(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_GEN_STATUS_RPRT(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_STATUS_EXCEED_MAX_LEN(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DUMP_DRB_RGPD_INFO(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_CURR_DL_SN_INFO(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_DL_FC_DLVR_PDUS_IN_WND(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DL_FC_UPDT_LAST_SUB_SN(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DL_FC_ENTER(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_DL_PDCP_CNT_2_IPID(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_SEND_MCCH_DATA_IND(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SEND_MTCH_DATA_IND(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DL_ALLOC_SPD(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_DL_DUMP_RBUF_INFO(short v1, short v2, long v3);
void L1TRC_Send_EPDCP_LOG_DL_INVALID_RBUF(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DL_FOUND_RBUF(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DL_PIT_RW_IDX(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DL_PIT_INFO1(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_DL_PIT_INFO2(unsigned short v1, unsigned short v2, long v3);
void L1TRC_Send_EPDCP_LOG_DL_SPD_HEAD(unsigned short v1, unsigned short v2, long v3);
void L1TRC_Send_EPDCP_LOG_DL_SPD_TAIL(unsigned short v1, unsigned short v2, long v3);
void L1TRC_Send_EPDCP_LOG_DL_SPD_COUNT_GAP(long v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DL_SPD_DATA_LEN(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_DL_SPD_PKT_NUM(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_DL_RBUF_DATA_IND(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DL_SPD_DUMP_LEN(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_DL_SPD_DUMP_PI_RAW(unsigned long v1, unsigned short v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_DL_SPD_DUMP_PIE_RAW(unsigned long v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_DL_SPD_DUMP_PIE_READ(unsigned long v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_DL_SPD_DUMP_IP_INFO(unsigned long v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_DL_SPD_DUMP_LIST(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DL_RBUF_PIT_REMAIN(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DL_INIT_RBUF(short v1, short v2, short v3, short v4);
void L1TRC_Send_EPDCP_LOG_DL_REL_PIT_IDX(short v1, short v2, short v3);
void L1TRC_Send_EPDCP_LOG_DL_REL_FOUND_RBUF(short v1, short v2, short v3);
void L1TRC_Send_EPDCP_LOG_DL_SORT_START(short v1);
void L1TRC_Send_EPDCP_LOG_DL_SORT_CMP(short v1);
void L1TRC_Send_EPDCP_LOG_DL_SORT_END(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DL_REL_TBL_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_EPDCP_LOG_DL_REL_AVAIL_ENTRY_FOUND(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DL_REL_IDX_DUMP(short v1, short v2, short v3);
void L1TRC_Send_EPDCP_LOG_DL_REL_INC_DRV_CNT(short v1);
void L1TRC_Send_EPDCP_LOG_DL_SPLIT_SPD(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_RCV_LB_CFG_REQ(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SND_LB_CFG_CNF(short v1);
void L1TRC_Send_EPDCP_LOG_WRONG_IN_LB_CFG_REQ(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_LB_WI_SCALE(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_LB_WO_SCALE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_LB_DISC_PDU(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_ENABLE_DRB_LB_MODE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_DRB_LB_MODE_C_OK(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DRB_LB_MODE_C_NOT_OK(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_UPD_SEC_PARAM_CIP(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_UPD_SEC_PARAM_INT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UPD_SEC_IN_SRB_HW(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UPD_SEC_IN_DRB_HW(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_ACTIVATE_DL_SEC(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_ACTIVATE_UL_SEC(short v1);
void L1TRC_Send_EPDCP_LOG_CHK_INACT_TMR_EVENT(short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_RCV_DETN_TMR_START_REQ(short v1);
void L1TRC_Send_EPDCP_LOG_SND_DETN_TMR_TMOUT_IND(short v1);
void L1TRC_Send_EPDCP_LOG_SND_PS_DATA_INACT_IND(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_UDRX_TMR_TMOUT(short v1);
void L1TRC_Send_EPDCP_LOG_UDRX_TMR_RESTART(short v1);
void L1TRC_Send_EPDCP_LOG_RCV_CNT_INFO_REQ(short v1);
void L1TRC_Send_EPDCP_LOG_SND_CNT_INFO_CNF(short v1);
void L1TRC_Send_EPDCP_LOG_SHOW_DRB_COUNT_INFO(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_RCV_CFG_REQ(short v1);
void L1TRC_Send_EPDCP_LOG_SND_CFG_CNF(short v1);
void L1TRC_Send_EPDCP_LOG_PROC_CONFIG_REQ(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_EXEC_SAVED_CFG_REQ(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_SAVE_CFG_REQ(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_WRONG_IN_CFG_REQ(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_DEL_RB_HNDLR(short v1);
void L1TRC_Send_EPDCP_LOG_DELETE_RB(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_MODIFY_RB(short v1, char v2, long v3);
void L1TRC_Send_EPDCP_LOG_ESTABLISH_RB(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SND_MODE_CHNG(short v1);
void L1TRC_Send_EPDCP_LOG_EST_SRB_INFO(short v1, unsigned long v2, unsigned long v3, char v4);
void L1TRC_Send_EPDCP_LOG_RESUME_SRB_INFO(short v1, unsigned long v2, char v3);
void L1TRC_Send_EPDCP_LOG_EST_DRB_INFO_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_EST_DRB_INFO_2(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_EST_DRB_INFO_3(short v1, unsigned long v2, unsigned long v3, char v4);
void L1TRC_Send_EPDCP_LOG_RECFG_DRB_INFO_1(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_RECFG_DRB_INFO_2(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_ADD_ROHC_CHNL(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_DEL_ROHC_CHNL(short v1);
void L1TRC_Send_EPDCP_LOG_CHNG_ROHC_CHNL(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_NOT_CHNG_ROHC_CHNL(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_ROHC_NOT_SUPPORT(short v1);
void L1TRC_Send_EPDCP_LOG_TOGGLE_ACTV_ENT_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_TOGGLE_ACTV_ENT_2(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_RECFG_UM_HW_CHNL(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_RECFG_AM_HW_CIP_CHNL(short v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_RECFG_AM_HW_DCIP_CHNL(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_RELEASE_DRB(short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_REL_DL_PDUS(short v1);
void L1TRC_Send_EPDCP_LOG_REDIR_UL_DATA(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_IDC_START(short v1);
void L1TRC_Send_EPDCP_LOG_IDC_END(short v1);
void L1TRC_Send_EPDCP_LOG_PWRDWN_HW(short v1);
void L1TRC_Send_EPDCP_LOG_REINIT_HW(short v1);
void L1TRC_Send_EPDCP_LOG_PWRON_CIP_QUEUE_INFO_1(short v1, char v2, unsigned long v3, short v4);
void L1TRC_Send_EPDCP_LOG_PWRON_CIP_QUEUE_INFO_2(short v1, unsigned long v2, short v3, short v4);
void L1TRC_Send_EPDCP_LOG_PWRON_CIP_QUEUE_INFO_3(short v1, unsigned long v2, short v3, short v4);
void L1TRC_Send_EPDCP_LOG_INV_SEC_STATE(short v1);
void L1TRC_Send_EPDCP_LOG_FORCE_DISABLE_ROHC(short v1);
void L1TRC_Send_EPDCP_LOG_VOLTE_EBI_IND(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_UPCM_IMS_BEARER_BMP(unsigned long v1);
void L1TRC_Send_EPDCP_LOG_CFG_RBUF_ENABLE(short v1);
void L1TRC_Send_EPDCP_LOG_SND_DCCH_DATA_CNF(short v1, unsigned long v2, long v3);
void L1TRC_Send_EPDCP_LOG_CFN_DISC_MSG_IN_ACK_TBL(short v1);
void L1TRC_Send_EPDCP_LOG_CFN_DISC_MSG_IN_CIP_QUE(short v1);
void L1TRC_Send_EPDCP_LOG_CFN_DISC_MSG_IN_SDU_QUE(short v1);
void L1TRC_Send_EPDCP_LOG_CLEAN_ROHC_QUE_RSLT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UNROHC_RETX_PDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_REL_ROHC_FBK_PDU(short v1);
void L1TRC_Send_EPDCP_LOG_UNROHC_SDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UNROHC_RSLT_CNT(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_STOP_UL_ROHC(short v1);
void L1TRC_Send_EPDCP_LOG_CLEAR_CIP_QUE(short v1);
void L1TRC_Send_EPDCP_LOG_REL_CTRL_QUE_SIZE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_RETX_PDU_WI_SAVED_PC(short v1, unsigned long v2, long v3);
void L1TRC_Send_EPDCP_LOG_RETX_PDU_WO_SAVED_PC(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DRBUM_RESUME_TX_INFO_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DRBUM_RESUME_TX_INFO_2(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DRBAM_RESUME_TX_INFO_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DRBAM_RESUME_TX_INFO_2(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DRBAM_RESUME_TX_INFO_3(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_RETX_PDU_WI_NEW_SN(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RETX_PDU_WI_OLD_SN(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_WRONG_IN_DCCH_DATA(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_WRONG_IN_PDCP_DATA_REQ(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_DISC_PARTIAL_DATA_REQ(short v1);
void L1TRC_Send_EPDCP_LOG_DISC_PDCP_DATA_REQ(short v1);
void L1TRC_Send_EPDCP_LOG_ACPT_PDCP_DATA_REQ(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_ENQ_TO_UL_ROHC(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DRB_ENQ_TO_UL_CIP_HW(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SRB_ENQ_TO_UL_CIP_HW(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_UL_BKT_VACANCY(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_UL_FORM_ROHC_FBK_PDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UL_FORM_SRB_DATA_PDU(short v1, unsigned long v2, long v3);
void L1TRC_Send_EPDCP_LOG_VOLTE_DATA_REQ(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_PRETX_INFO(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_ROHC_FBK_ENQ_NML_QUE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_ROHC_FBK_ENQ_CTRL_QUE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_RCV_UL_ROHC_RSLT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UL_ROHC_OF_RETX_PDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UL_ROHC_OF_PRI_SDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UL_ROHC_OF_NML_SDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_SEARCH_TMOUT_SDU(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_TMOUT_IN_CIP_QUE(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_CIP_QUE_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_CIP_QUE_2(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_CIP_QUE_3(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_CIP_QUE_END(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_STOP_DISC_TMOUT_GPD(short v1);
void L1TRC_Send_EPDCP_LOG_RESEND_UNTXSCHED_GPDS(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_CTRL_PDU_INFO(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_TMOUT_PDU_INFO(short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_NTMOUT_PDU_INFO(short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_TMOUT_RETX_Q_PDU_INFO(short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_NTMOUT_RETX_Q_PDU_INFO(short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_TMOUT_QUEUED_SDU_INFO(short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_UL_DESYNC_AVOID_TRICK1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_UL_DESYNC_AVOID_TRICK2(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_RETX_Q_END(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_SDU_Q_END(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_INT_PROT_PARAM(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_INT_PROT_RSLT_MACI(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RB_UL_BKT_INFO_1(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RB_UL_BKT_INFO_2(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_RB_UL_BKT_INFO_3(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RB_UL_BKT_INFO_4(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_UMDRB_REL_ULGPD_START(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_SCHED_GPD_DELAY(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_REL_SCHED_CIP_QUE_GPD(short v1, short v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_UNSCHED_CIP_QUE_GPD(long v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_AMDRB_ACK_ULGPD_START(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_ACKED_GPD_DELAY(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_REL_ACKED_CIP_QUE_GPD(short v1, short v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_UNACKED_CIP_QUE_GPD(long v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_ENABLE_UL_FC(short v1);
void L1TRC_Send_EPDCP_LOG_DISABLE_UL_FC(short v1);
void L1TRC_Send_EPDCP_LOG_ACPT_DCCH_DATA_REQ(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_SRB_REL_CPLT_GPD(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SRB_DATA_ACK_HNDLR(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SRB_ACK_ULSDU(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SRB_ACK_ULSDU_CIP_QUE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SRB_ACK_ULSDU_START(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_SRB_UPD_NXT_REl_SIT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_PROC_STATUS_REPORT(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_STUS_RPRT_BITMAP_LONG(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_STUS_RPRT_REF_FMS_INFO(short v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_STUS_ACK_CIP_QUE_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_STUS_ACK_CIP_QUE_2(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_STUS_ACK_CIP_QUE_3(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_STUS_ACK_CIP_QUE_END(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_STOP_DISC_ACKED_GPD(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_UL_PDU_SIT_AND_SN(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DISC_REQ_TO_RLC(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_INV_FMS_STATUS_REPORT(short v1);
void L1TRC_Send_EPDCP_LOG_UL_GPD_N_IP_INFO(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_UL_CIP_GPD_N_IP_INFO(unsigned long v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_UL_PDCP_CNT_2_IPID(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_UL_FC_DROP_SDU(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_UL_FC_CHK_DRB_UL_STATUS(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_UL_SDU_SENT_N_UNACKED(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_UL_SEND_AUTO_RLC_POLL(short v1);
void L1TRC_Send_EPDCP_LOG_MAX_UL_BKT(unsigned long v1);
void L1TRC_Send_EPDCP_LOG_INJ_CHG_REL_GPD_NUM(short v1);
void L1TRC_Send_EPDCP_LOG_INJ_CHG_DLFC_DLVR_ENTER_THRSH(short v1);
void L1TRC_Send_EPDCP_LOG_INJ_CHG_DLFC_DLVR_CNT(short v1);
void L1TRC_Send_EPDCP_LOG_DUMMY_SIGNED(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DUMMY(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_DUMMY_HEX(short v1, unsigned long v2, unsigned long v3, unsigned long v4);

void Set_EPDCP_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EPDCP()	(EPDCP_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EPDCP_EPDCP_INFO()	(ChkL1ModFltr_EPDCP()&&((EPDCP_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()	(ChkL1ModFltr_EPDCP()&&((EPDCP_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EPDCP_EPDCP_WARN()	(ChkL1ModFltr_EPDCP()&&((EPDCP_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EPDCP_EPDCP_DUMP()	(ChkL1ModFltr_EPDCP()&&((EPDCP_Trace_Filter[1]&0x08)!=0))
#define ChkL1MsgFltr_EPDCP_LOG_START_POLLING()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_RX_PDU_CNT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SEND_DCCH_DATA_IND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_SRB_PDU_INT_ERR()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_PDU_BY_STATE()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_PDU_BY_HDR_ERR_OR_ZERO_LEN()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_PDU_TO_STOP_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_PDU_BY_FLUSH()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_UTILIZE_TAIL_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_PDU_BY_TAIL_DONE()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_RESTORE_DL_QMU()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_EXEC_DL_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_OOW_PDU_HWM_DCIP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_OOW_PDU_SWM_DCIP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_NXT_SRB1_DL_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INV_UM_STATUS_REPORT()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_RX_ROHC_FBK_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RX_FDBK_WHEN_NO_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_RX_INVALID_CTRL_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_RX_INVALID_R_BIT_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_GATHER_GPD_RESULT()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_CE_OUTPUT_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INT_PROT_DL_MACI_CMP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_RBUF_RGPD_SWITCH()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPDT_DL_UMDRB_SN()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_STILL_WAIT_FOR_FLUSH()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FLUSH_FOR_REEST_DONE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FLUSH_FOR_REL_DONE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_POLLING_DL_ROHC_RESULT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_OOW_PDU_AFTER_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRB_DLVR_BMP()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_DRB_HAS_DL_DATA_TO_LTM()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_SEND_LTM_DATA_IND()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_INS_TO_DL_WND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_PDCP_SN_OOO()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_REL_DUPL_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_AM_INORDR_DLVR()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_RELOAD_DL_GPDS()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RELOAD_DL_GPDS_IN_HO()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_STATUS_RPRT_WND_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_GEN_STATUS_RPRT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STATUS_EXCEED_MAX_LEN()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DUMP_DRB_RGPD_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_CURR_DL_SN_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FC_DLVR_PDUS_IN_WND()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FC_UPDT_LAST_SUB_SN()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FC_ENTER()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DL_PDCP_CNT_2_IPID()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SEND_MCCH_DATA_IND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SEND_MTCH_DATA_IND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_ALLOC_SPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_DUMP_RBUF_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_INVALID_RBUF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FOUND_RBUF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_PIT_RW_IDX()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_PIT_INFO1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_PIT_INFO2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_HEAD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_TAIL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_COUNT_GAP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_DATA_LEN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_PKT_NUM()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_RBUF_DATA_IND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_DUMP_LEN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_DUMP_PI_RAW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_DUMP_PIE_RAW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_DUMP_PIE_READ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_DUMP_IP_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPD_DUMP_LIST()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_RBUF_PIT_REMAIN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_INIT_RBUF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_REL_PIT_IDX()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_REL_FOUND_RBUF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SORT_START()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SORT_CMP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SORT_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_REL_TBL_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_REL_AVAIL_ENTRY_FOUND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_REL_IDX_DUMP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_REL_INC_DRV_CNT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_SPLIT_SPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RCV_LB_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_LB_CFG_CNF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_WRONG_IN_LB_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_LB_WI_SCALE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_LB_WO_SCALE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_LB_DISC_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ENABLE_DRB_LB_MODE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRB_LB_MODE_C_OK()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRB_LB_MODE_C_NOT_OK()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPD_SEC_PARAM_CIP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPD_SEC_PARAM_INT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPD_SEC_IN_SRB_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPD_SEC_IN_DRB_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ACTIVATE_DL_SEC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ACTIVATE_UL_SEC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CHK_INACT_TMR_EVENT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RCV_DETN_TMR_START_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_DETN_TMR_TMOUT_IND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_PS_DATA_INACT_IND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UDRX_TMR_TMOUT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UDRX_TMR_RESTART()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RCV_CNT_INFO_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_CNT_INFO_CNF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SHOW_DRB_COUNT_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RCV_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_CFG_CNF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PROC_CONFIG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EXEC_SAVED_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_SAVE_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_WRONG_IN_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DEL_RB_HNDLR()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DELETE_RB()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_MODIFY_RB()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ESTABLISH_RB()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_MODE_CHNG()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EST_SRB_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RESUME_SRB_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EST_DRB_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EST_DRB_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EST_DRB_INFO_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RECFG_DRB_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RECFG_DRB_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ADD_ROHC_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DEL_ROHC_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CHNG_ROHC_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_NOT_CHNG_ROHC_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ROHC_NOT_SUPPORT()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_TOGGLE_ACTV_ENT_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_TOGGLE_ACTV_ENT_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RECFG_UM_HW_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RECFG_AM_HW_CIP_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RECFG_AM_HW_DCIP_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RELEASE_DRB()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_DL_PDUS()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REDIR_UL_DATA()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_IDC_START()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_IDC_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PWRDWN_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REINIT_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PWRON_CIP_QUEUE_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PWRON_CIP_QUEUE_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PWRON_CIP_QUEUE_INFO_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INV_SEC_STATE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_FORCE_DISABLE_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_VOLTE_EBI_IND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPCM_IMS_BEARER_BMP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CFG_RBUF_ENABLE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_DCCH_DATA_CNF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CFN_DISC_MSG_IN_ACK_TBL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CFN_DISC_MSG_IN_CIP_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CFN_DISC_MSG_IN_SDU_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CLEAN_ROHC_QUE_RSLT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UNROHC_RETX_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_ROHC_FBK_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UNROHC_SDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UNROHC_RSLT_CNT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STOP_UL_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CLEAR_CIP_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_CTRL_QUE_SIZE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RETX_PDU_WI_SAVED_PC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RETX_PDU_WO_SAVED_PC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRBUM_RESUME_TX_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRBUM_RESUME_TX_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRBAM_RESUME_TX_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRBAM_RESUME_TX_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRBAM_RESUME_TX_INFO_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RETX_PDU_WI_NEW_SN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RETX_PDU_WI_OLD_SN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_WRONG_IN_DCCH_DATA()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_WRONG_IN_PDCP_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_PARTIAL_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_PDCP_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_ACPT_PDCP_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_ENQ_TO_UL_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRB_ENQ_TO_UL_CIP_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_ENQ_TO_UL_CIP_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_BKT_VACANCY()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_FORM_ROHC_FBK_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_FORM_SRB_DATA_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_VOLTE_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PRETX_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_ROHC_FBK_ENQ_NML_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ROHC_FBK_ENQ_CTRL_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RCV_UL_ROHC_RSLT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_ROHC_OF_RETX_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_ROHC_OF_PRI_SDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_ROHC_OF_NML_SDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SEARCH_TMOUT_SDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_TMOUT_IN_CIP_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_CIP_QUE_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_CIP_QUE_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_CIP_QUE_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_CIP_QUE_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STOP_DISC_TMOUT_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RESEND_UNTXSCHED_GPDS()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CTRL_PDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_TMOUT_PDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_NTMOUT_PDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_TMOUT_RETX_Q_PDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_NTMOUT_RETX_Q_PDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_TMOUT_QUEUED_SDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_DESYNC_AVOID_TRICK1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_DESYNC_AVOID_TRICK2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_RETX_Q_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_SDU_Q_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INT_PROT_PARAM()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INT_PROT_RSLT_MACI()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RB_UL_BKT_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RB_UL_BKT_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RB_UL_BKT_INFO_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RB_UL_BKT_INFO_4()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UMDRB_REL_ULGPD_START()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_SCHED_GPD_DELAY()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_SCHED_CIP_QUE_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UNSCHED_CIP_QUE_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_AMDRB_ACK_ULGPD_START()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_ACKED_GPD_DELAY()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_ACKED_CIP_QUE_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UNACKED_CIP_QUE_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ENABLE_UL_FC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISABLE_UL_FC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ACPT_DCCH_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_REL_CPLT_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_DATA_ACK_HNDLR()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_ACK_ULSDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_ACK_ULSDU_CIP_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_ACK_ULSDU_START()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_UPD_NXT_REl_SIT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PROC_STATUS_REPORT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_RPRT_BITMAP_LONG()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_RPRT_REF_FMS_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_ACK_CIP_QUE_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_ACK_CIP_QUE_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_ACK_CIP_QUE_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_ACK_CIP_QUE_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STOP_DISC_ACKED_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_PDU_SIT_AND_SN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_REQ_TO_RLC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INV_FMS_STATUS_REPORT()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_UL_GPD_N_IP_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_CIP_GPD_N_IP_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_PDCP_CNT_2_IPID()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_FC_DROP_SDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_FC_CHK_DRB_UL_STATUS()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_SDU_SENT_N_UNACKED()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_SEND_AUTO_RLC_POLL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_MAX_UL_BKT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INJ_CHG_REL_GPD_NUM()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_INJ_CHG_DLFC_DLVR_ENTER_THRSH()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_INJ_CHG_DLFC_DLVR_CNT()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DUMMY_SIGNED()	ChkL1ClsFltr_EPDCP_EPDCP_DUMP()
#define ChkL1MsgFltr_EPDCP_LOG_DUMMY()	ChkL1ClsFltr_EPDCP_EPDCP_DUMP()
#define ChkL1MsgFltr_EPDCP_LOG_DUMMY_HEX()	ChkL1ClsFltr_EPDCP_EPDCP_DUMP()


#endif
