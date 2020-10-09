#ifndef L1TRC_EPDCP_DETAIL_DEF_H
#define L1TRC_EPDCP_DETAIL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_RX_CB_PDU_TO_CB_QUE(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x000A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_RX_CB_PDU_TO_CB_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_RX_CB_PDU_TO_OK_QUE(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x010A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_RX_CB_PDU_TO_OK_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_RX_OK_PDU_TO_OK_QUE(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x020A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_RX_OK_PDU_TO_OK_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_HWM(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x030A | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_HWM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_SWM(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x040A | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_SWM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_ROHC(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x050A | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_ROHC(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_SCALE_LPBK_SDU(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x060A | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_SCALE_LPBK_SDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_NO_SCALE_LPBK_SDU(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x070A | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_NO_SCALE_LPBK_SDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_DL_SPD_UPDT_PKT_HDR(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x080A | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_DL_SPD_UPDT_PKT_HDR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_SCHED_GPD_DELAY(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x090A | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_SCHED_GPD_DELAY(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_ACKED_GPD_DELAY(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0A0A | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_ACKED_GPD_DELAY(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_DCCH_DATA_RES_PARAM_WRONG(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0B0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_DCCH_DATA_RES_PARAM_WRONG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_RESUME_CHNL_WO_VALID_DRB(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0C0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_RESUME_CHNL_WO_VALID_DRB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_EMPTY_DL_WINDOW(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0D0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_EMPTY_DL_WINDOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_MERGE_DL_PDUS_TO_REORD_WND(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0E0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_MERGE_DL_PDUS_TO_REORD_WND(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_SEARCH_CONTINUE_PC_FROM_WND(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0F0A | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_SEARCH_CONTINUE_PC_FROM_WND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_UNEXP_PC_STOP(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x100A | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_UNEXP_PC_STOP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_DL_FC_WND_EMPTY(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x110A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_DL_FC_WND_EMPTY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_DL_FC_DLVR_UNEXP_PC_STOP(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x120A | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_DL_FC_DLVR_UNEXP_PC_STOP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_SWITCH_VIRTUAL_CONNECTED_REQ(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x130A | (((kal_uint32)((char)(v2))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v1), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_SWITCH_VIRTUAL_CONNECTED_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_VC_STATE_CHANGE_CHK(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x140A | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_VC_STATE_CHANGE_CHK(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_VC_POLLING(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x150A | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_VC_POLLING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_VC_ENABLE_FLAG_CHANGE(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x160A | (((kal_uint32)((char)(v1))) << 16) | (((kal_uint32)((char)(v2))) << 24));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_VC_ENABLE_FLAG_CHANGE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_VC_OFFSET_CHECK_INFO(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x170A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_VC_OFFSET_CHECK_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_VC_OFFSET_CHECK_RB(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x180A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_VC_OFFSET_CHECK_RB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_VC_OFFSET_CIPQ(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x190A | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_VC_OFFSET_CIPQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_VC_OFFSET_ROHCQ(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1A0A | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_VC_OFFSET_ROHCQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_VC_OFFSET_SUSPQ(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1B0A | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_VC_OFFSET_SUSPQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_VC_OFFSET_SDUQ(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1C0A | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_VC_OFFSET_SDUQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_VC_OFFSET_DATA(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1D0A | ((unsigned short)(v2) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_VC_OFFSET_DATA(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_INIT(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x1E0A | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_INIT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_INIT_DL_SHRD_MEM(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x1F0A | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_INIT_DL_SHRD_MEM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_UNINIT_DL_SHRD_MEM(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x200A | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_UNINIT_DL_SHRD_MEM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_UPCTRL_MSG_SEND(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x210A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_UPCTRL_MSG_SEND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_UPCTRL_MSG_RECV(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x220A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_UPCTRL_MSG_RECV(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_UPCTRL_PKT_NTF_ON_OFF(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x230A | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24), (kal_uint32)((unsigned char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_UPCTRL_PKT_NTF_ON_OFF(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_UPCTRL_SHRD_MEM_SPRT_LIST(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x240A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_UPCTRL_SHRD_MEM_SPRT_LIST(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_EST_LWA_DRB(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x250A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_EST_LWA_DRB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_REL_LWA_DRB(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x260A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_REL_LWA_DRB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_REL_PDCP_SEC_ENT_WI_LWA(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x270A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_REL_PDCP_SEC_ENT_WI_LWA(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_ENBL_LWA_ON_EXG_DRB(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x280A | ((short)(v1) << 16), (kal_uint32)((unsigned char)(v2)) | (((kal_uint32)((unsigned char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_ENBL_LWA_ON_EXG_DRB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_ENBL_LWA_ON_TRANZ_DRB(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x290A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_ENBL_LWA_ON_TRANZ_DRB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DSBL_LWA_BUT_NOT_REL_DRB(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x2A0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DSBL_LWA_BUT_NOT_REL_DRB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_BACK_TO_LTE_DATA_PATH(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x2B0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_BACK_TO_LTE_DATA_PATH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RECOFIG_LWA_PARA(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x2C0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RECOFIG_LWA_PARA(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RBUF_NOT_ACTIVATED(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x2D0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RBUF_NOT_ACTIVATED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DRB_IDX(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x2E0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DRB_IDX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SW_PIT_WRI_IDX(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x2F0A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SW_PIT_WRI_IDX(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_HW_PIT_READ_IDX(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x300A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_HW_PIT_READ_IDX(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_HW_PIT_READ_RLST(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x310A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_HW_PIT_READ_RLST(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DRB_HRL_HRW_UTD(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x320A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DRB_HRL_HRW_UTD(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DRB_HRL_HRW(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x330A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DRB_HRL_HRW(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RCV_ZERO_SZ_LTE_PKT(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x340A | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RCV_ZERO_SZ_LTE_PKT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RCV_INV_RBID_WIFI_PKT(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x350A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)((unsigned char)(v2))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RCV_INV_RBID_WIFI_PKT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RCV_UNEST_DRB_WIFI_PKT(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x360A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)((unsigned char)(v2))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RCV_UNEST_DRB_WIFI_PKT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RCV_LTE_DRB_WIFI_PKT(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x370A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v4))) << 16), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RCV_LTE_DRB_WIFI_PKT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RCV_BPS_WIFI_PKT(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x380A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)((unsigned char)(v2))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RCV_BPS_WIFI_PKT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RCV_ZERO_SZ_WIFI_PKT(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x390A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)((unsigned char)(v2))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RCV_ZERO_SZ_WIFI_PKT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RX_IW_FROM_LTE(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x3A0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RX_IW_FROM_LTE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RX_OOW_FROM_LTE(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x3B0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RX_OOW_FROM_LTE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RX_OOW_BY_HW_FROM_LTE(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x3C0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RX_OOW_BY_HW_FROM_LTE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RX_IW_FROM_WIFI(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x3D0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RX_IW_FROM_WIFI(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RX_OOW_FROM_WIFI(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x3E0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RX_OOW_FROM_WIFI(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RX_DUPE_WI_LST_ONE_FROM_WIFI(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x3F0A | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RX_DUPE_WI_LST_ONE_FROM_WIFI(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RX_OOW_DUPE_SN(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x400A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RX_OOW_DUPE_SN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RX_DUPE_SN(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x410A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)((unsigned short)(v4))) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RX_DUPE_SN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DRB_STATE(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x420A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)((char)(v2))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DRB_STATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_MRGE_RCV_PKT_TO_RO_WND(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x430A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_MRGE_RCV_PKT_TO_RO_WND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_PKT_NUM_IN_WND(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x440A | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_PKT_NUM_IN_WND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_COL_INORDER_ROD(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x450A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_COL_INORDER_ROD(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RO_WND_ADV(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x460A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RO_WND_ADV(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_ENQ_ROD_TO_DLVR_Q(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x470A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_ENQ_ROD_TO_DLVR_Q(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_ENQ_ROD_WI_RO_FUN_TO_DLVR_Q(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x480A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_ENQ_ROD_WI_RO_FUN_TO_DLVR_Q(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_PROC_ROD_DLVR_Q(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x490A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_PROC_ROD_DLVR_Q(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_CMPL_A_SPD(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x4A0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_CMPL_A_SPD(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_ROD_DLVR_Q_PROC_RLST(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x4B0A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v4))) << 16), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_ROD_DLVR_Q_PROC_RLST(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DEQ_PKTS_IN_ROD_DLVR_Q(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x4C0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DEQ_PKTS_IN_ROD_DLVR_Q(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_TFC_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x4D0A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_TFC_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_ALLOC_ROD_RO_TBL(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x4E0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_ALLOC_ROD_RO_TBL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_CLR_ROD_RO_WND(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x4F0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_CLR_ROD_RO_WND(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_FREE_ROD_RO_TBL(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x500A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_FREE_ROD_RO_TBL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_CLR_ROD_DLVR_Q(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x510A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_CLR_ROD_DLVR_Q(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RO_TMR_START(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x520A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RO_TMR_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RO_TMR_EXP(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x530A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RO_TMR_EXP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RO_TMR_EVENT_ID(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x540A | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RO_TMR_EVENT_ID(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RPT_TMR_START(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x550A | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RPT_TMR_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RPT_TMR_EXP(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x560A | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RPT_TMR_EXP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_TMR_STOP(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x570A | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_TMR_STOP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DL_POLL_TMR_START(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x580A | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DL_POLL_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DL_POLL_TMR_EXP(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x590A | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DL_POLL_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DL_POLL_TMR_STOP(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x5A0A | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DL_POLL_TMR_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DL_POLL_TMR_RUNNING(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x5B0A | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DL_POLL_TMR_RUNNING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DELAY_SETTING_TMR_START(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x5C0A | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DELAY_SETTING_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DELAY_SETTING_TMR_EXP(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x5D0A | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DELAY_SETTING_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DELAY_SETTING_TMR_STOP(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x5E0A | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DELAY_SETTING_TMR_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_PDCP_STAT_RPT_TIMER_STOPPED(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x5F0A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_PDCP_STAT_RPT_TIMER_STOPPED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_LWA_STAT_RPT_TIMER_STOPPED(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x600A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_LWA_STAT_RPT_TIMER_STOPPED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_PDCP_PER_STAT_RPT_INFO(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x610A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_PDCP_PER_STAT_RPT_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_LWA_PER_STAT_RPT_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x620A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_LWA_PER_STAT_RPT_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SHRD_MEM_READ_RLST(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x630A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SHRD_MEM_READ_RLST(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SWM_ENQ(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x640A | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SWM_ENQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SWM_NULL_HW_CUR_ADDR(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x650A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SWM_NULL_HW_CUR_ADDR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SWM_RQUE(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x660A | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SWM_RQUE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SWM_RQUE_GDMA(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x670A | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SWM_RQUE_GDMA(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SWM_DEQ(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x680A | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SWM_DEQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_PIT_REL_TBL_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x690A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_PIT_REL_TBL_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_PIT_ENT_REL_ONE_DIR(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x6A0A | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_PIT_ENT_REL_ONE_DIR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_PIT_ENT_REL_MUL_DIR(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x6B0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_PIT_ENT_REL_MUL_DIR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_PIT_ENT_REL_FROM_SPD(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x6C0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_PIT_ENT_REL_FROM_SPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RBUF_RESRC_REL_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x6D0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RBUF_RESRC_REL_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_AVAIL_PIT_IDX_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x6E0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_AVAIL_PIT_IDX_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_PKT_IN_PIT_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x6F0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_PKT_IN_PIT_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_EARLY_DLVR_CHK_ON_OFF(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x700A | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_EARLY_DLVR_CHK_ON_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_EARLY_DLVR_CHK_LTE(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x710A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_EARLY_DLVR_CHK_LTE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_EARLY_DLVR_CHK_WIFI(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x720A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_EARLY_DLVR_CHK_WIFI(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DBG_SHRD_MEM_DESCP_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x730A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v4))) << 16), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DBG_SHRD_MEM_DESCP_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_RPT_BY_POLL_CFG(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x740A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_RPT_BY_POLL_CFG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_UPCTRL_DL_SHRD_MEM_INIT_FAIL(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x750A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_UPCTRL_DL_SHRD_MEM_INIT_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_DL_DIR_RX_CTRL_PDU(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x760A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_DL_DIR_RX_CTRL_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SHRTG_OF_SPD(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x770A | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SHRTG_OF_SPD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SHRTG_OF_HW_RBUF_RESRC(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x780A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SHRTG_OF_HW_RBUF_RESRC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SHRTG_OF_SW_RBUF_RESRC(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x790A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v3)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SHRTG_OF_SW_RBUF_RESRC(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_SHRTG_OF_PIT_REL_TBL_RESRC(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x7A0A | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_SHRTG_OF_PIT_REL_TBL_RESRC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_GDMA_BUSY_CNT(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x7B0A | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_GDMA_BUSY_CNT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LWA_EARLY_DLVR(v1, v2, v3, v4) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x7C0A | ((short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((unsigned short)(v3))) << 16), (kal_uint32)((unsigned short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_LWA_EARLY_DLVR(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EPDCP_DETAIL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EPDCP_DTL_LOG_RX_CB_PDU_TO_CB_QUE(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_RX_CB_PDU_TO_OK_QUE(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_RX_OK_PDU_TO_OK_QUE(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_OOW_PDU_INFO_HWM(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_OOW_PDU_INFO_SWM(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_OOW_PDU_INFO_ROHC(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_SCALE_LPBK_SDU(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_NO_SCALE_LPBK_SDU(short v1, long v2);
void L1TRC_Send_EPDCP_DTL_LOG_DL_SPD_UPDT_PKT_HDR(short v1, long v2);
void L1TRC_Send_EPDCP_DTL_LOG_SCHED_GPD_DELAY(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_DTL_LOG_ACKED_GPD_DELAY(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_DTL_LOG_DCCH_DATA_RES_PARAM_WRONG(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_RESUME_CHNL_WO_VALID_DRB(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_EMPTY_DL_WINDOW(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_MERGE_DL_PDUS_TO_REORD_WND(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_SEARCH_CONTINUE_PC_FROM_WND(short v1, long v2);
void L1TRC_Send_EPDCP_DTL_LOG_UNEXP_PC_STOP(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_DL_FC_WND_EMPTY(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_DL_FC_DLVR_UNEXP_PC_STOP(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_SWITCH_VIRTUAL_CONNECTED_REQ(long v1, char v2, unsigned long v3);
void L1TRC_Send_EPDCP_DTL_LOG_VC_STATE_CHANGE_CHK(short v1, char v2, char v3);
void L1TRC_Send_EPDCP_DTL_LOG_VC_POLLING(char v1);
void L1TRC_Send_EPDCP_DTL_LOG_VC_ENABLE_FLAG_CHANGE(char v1, char v2);
void L1TRC_Send_EPDCP_DTL_LOG_VC_OFFSET_CHECK_INFO(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_DTL_LOG_VC_OFFSET_CHECK_RB(short v1, unsigned short v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_VC_OFFSET_CIPQ(unsigned long v1, unsigned long v2);
void L1TRC_Send_EPDCP_DTL_LOG_VC_OFFSET_ROHCQ(unsigned long v1, unsigned long v2);
void L1TRC_Send_EPDCP_DTL_LOG_VC_OFFSET_SUSPQ(unsigned long v1, unsigned long v2);
void L1TRC_Send_EPDCP_DTL_LOG_VC_OFFSET_SDUQ(unsigned long v1, unsigned long v2);
void L1TRC_Send_EPDCP_DTL_LOG_VC_OFFSET_DATA(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_INIT(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_LWA_INIT_DL_SHRD_MEM(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_LWA_UNINIT_DL_SHRD_MEM(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_LWA_UPCTRL_MSG_SEND(short v1, unsigned short v2);
void L1TRC_Send_EPDCP_LOG_LWA_UPCTRL_MSG_RECV(short v1, unsigned short v2);
void L1TRC_Send_EPDCP_LOG_LWA_UPCTRL_PKT_NTF_ON_OFF(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_LWA_UPCTRL_SHRD_MEM_SPRT_LIST(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_EST_LWA_DRB(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_REL_LWA_DRB(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_REL_PDCP_SEC_ENT_WI_LWA(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_ENBL_LWA_ON_EXG_DRB(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EPDCP_LOG_LWA_ENBL_LWA_ON_TRANZ_DRB(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_DSBL_LWA_BUT_NOT_REL_DRB(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_BACK_TO_LTE_DATA_PATH(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_RECOFIG_LWA_PARA(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_RBUF_NOT_ACTIVATED(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_DRB_IDX(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_SW_PIT_WRI_IDX(short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_HW_PIT_READ_IDX(short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_HW_PIT_READ_RLST(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_DRB_HRL_HRW_UTD(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_DRB_HRL_HRW(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RCV_ZERO_SZ_LTE_PKT(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_LWA_RCV_INV_RBID_WIFI_PKT(unsigned short v1, unsigned char v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RCV_UNEST_DRB_WIFI_PKT(unsigned short v1, unsigned char v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RCV_LTE_DRB_WIFI_PKT(unsigned short v1, unsigned short v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RCV_BPS_WIFI_PKT(unsigned short v1, unsigned char v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RCV_ZERO_SZ_WIFI_PKT(unsigned short v1, unsigned char v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RX_IW_FROM_LTE(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RX_OOW_FROM_LTE(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RX_OOW_BY_HW_FROM_LTE(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RX_IW_FROM_WIFI(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RX_OOW_FROM_WIFI(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RX_DUPE_WI_LST_ONE_FROM_WIFI(short v1, short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_RX_OOW_DUPE_SN(short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_RX_DUPE_SN(short v1, char v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_DRB_STATE(short v1, char v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_MRGE_RCV_PKT_TO_RO_WND(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_PKT_NUM_IN_WND(short v1, short v2, short v3);
void L1TRC_Send_EPDCP_LOG_LWA_COL_INORDER_ROD(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RO_WND_ADV(short v1, unsigned short v2, unsigned short v3, short v4);
void L1TRC_Send_EPDCP_LOG_LWA_ENQ_ROD_TO_DLVR_Q(short v1, unsigned short v2, short v3, short v4);
void L1TRC_Send_EPDCP_LOG_LWA_ENQ_ROD_WI_RO_FUN_TO_DLVR_Q(short v1, unsigned short v2, short v3);
void L1TRC_Send_EPDCP_LOG_LWA_PROC_ROD_DLVR_Q(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_CMPL_A_SPD(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_ROD_DLVR_Q_PROC_RLST(short v1, unsigned short v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_DEQ_PKTS_IN_ROD_DLVR_Q(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_TFC_INFO(short v1, unsigned short v2, unsigned short v3, short v4);
void L1TRC_Send_EPDCP_LOG_LWA_ALLOC_ROD_RO_TBL(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_CLR_ROD_RO_WND(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_FREE_ROD_RO_TBL(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_CLR_ROD_DLVR_Q(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_RO_TMR_START(short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_RO_TMR_EXP(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RO_TMR_EVENT_ID(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_LWA_RPT_TMR_START(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_LWA_RPT_TMR_EXP(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_LWA_TMR_STOP(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_LWA_DL_POLL_TMR_START(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_LWA_DL_POLL_TMR_EXP(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_LWA_DL_POLL_TMR_STOP(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_LWA_DL_POLL_TMR_RUNNING(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_LWA_DELAY_SETTING_TMR_START(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_LWA_DELAY_SETTING_TMR_EXP(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_LWA_DELAY_SETTING_TMR_STOP(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_LWA_PDCP_STAT_RPT_TIMER_STOPPED(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_LWA_STAT_RPT_TIMER_STOPPED(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_PDCP_PER_STAT_RPT_INFO(short v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_LWA_LWA_PER_STAT_RPT_INFO(short v1, unsigned short v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_LWA_SHRD_MEM_READ_RLST(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_SWM_ENQ(unsigned short v1, unsigned long v2, short v3);
void L1TRC_Send_EPDCP_LOG_LWA_SWM_NULL_HW_CUR_ADDR(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_SWM_RQUE(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_LWA_SWM_RQUE_GDMA(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_LWA_SWM_DEQ(unsigned short v1, short v2);
void L1TRC_Send_EPDCP_LOG_LWA_PIT_REL_TBL_INFO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_PIT_ENT_REL_ONE_DIR(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_LWA_PIT_ENT_REL_MUL_DIR(unsigned short v1, unsigned short v2);
void L1TRC_Send_EPDCP_LOG_LWA_PIT_ENT_REL_FROM_SPD(unsigned short v1, unsigned short v2);
void L1TRC_Send_EPDCP_LOG_LWA_RBUF_RESRC_REL_INFO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_AVAIL_PIT_IDX_INFO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_PKT_IN_PIT_INFO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_EARLY_DLVR_CHK_ON_OFF(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_LWA_EARLY_DLVR_CHK_LTE(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_EARLY_DLVR_CHK_WIFI(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_DBG_SHRD_MEM_DESCP_INFO(unsigned short v1, unsigned short v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_RPT_BY_POLL_CFG(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_UPCTRL_DL_SHRD_MEM_INIT_FAIL(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_DL_DIR_RX_CTRL_PDU(short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_SHRTG_OF_SPD(short v1);
void L1TRC_Send_EPDCP_LOG_LWA_SHRTG_OF_HW_RBUF_RESRC(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_SHRTG_OF_SW_RBUF_RESRC(unsigned short v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_EPDCP_LOG_LWA_SHRTG_OF_PIT_REL_TBL_RESRC(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EPDCP_LOG_LWA_GDMA_BUSY_CNT(unsigned short v1);
void L1TRC_Send_EPDCP_LOG_LWA_EARLY_DLVR(short v1, unsigned short v2, unsigned short v3, unsigned short v4);

void Set_EPDCP_DETAIL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EPDCP_DETAIL()	(EPDCP_DETAIL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()	(ChkL1ModFltr_EPDCP_DETAIL()&&((EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()	(ChkL1ModFltr_EPDCP_DETAIL()&&((EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_DBG()	(ChkL1ModFltr_EPDCP_DETAIL()&&((EPDCP_DETAIL_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()	(ChkL1ModFltr_EPDCP_DETAIL()&&((EPDCP_DETAIL_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()	(ChkL1ModFltr_EPDCP_DETAIL()&&((EPDCP_DETAIL_Trace_Filter[1]&0x10)!=0))
#define ChkL1MsgFltr_EPDCP_DTL_LOG_RX_CB_PDU_TO_CB_QUE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_RX_CB_PDU_TO_OK_QUE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_RX_OK_PDU_TO_OK_QUE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_DBG()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_OOW_PDU_INFO_HWM()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_OOW_PDU_INFO_SWM()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_OOW_PDU_INFO_ROHC()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_SCALE_LPBK_SDU()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_NO_SCALE_LPBK_SDU()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_DL_SPD_UPDT_PKT_HDR()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_SCHED_GPD_DELAY()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_ACKED_GPD_DELAY()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_DCCH_DATA_RES_PARAM_WRONG()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_RESUME_CHNL_WO_VALID_DRB()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_EMPTY_DL_WINDOW()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_DBG()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_MERGE_DL_PDUS_TO_REORD_WND()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_SEARCH_CONTINUE_PC_FROM_WND()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_UNEXP_PC_STOP()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_DL_FC_WND_EMPTY()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_DL_FC_DLVR_UNEXP_PC_STOP()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_SWITCH_VIRTUAL_CONNECTED_REQ()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_VC_STATE_CHANGE_CHK()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_VC_POLLING()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_VC_ENABLE_FLAG_CHANGE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_VC_OFFSET_CHECK_INFO()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_VC_OFFSET_CHECK_RB()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_VC_OFFSET_CIPQ()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_VC_OFFSET_ROHCQ()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_VC_OFFSET_SUSPQ()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_VC_OFFSET_SDUQ()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_VC_OFFSET_DATA()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_VC_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_INIT()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_INIT_DL_SHRD_MEM()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_UNINIT_DL_SHRD_MEM()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_UPCTRL_MSG_SEND()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_UPCTRL_MSG_RECV()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_UPCTRL_PKT_NTF_ON_OFF()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_UPCTRL_SHRD_MEM_SPRT_LIST()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_EST_LWA_DRB()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_REL_LWA_DRB()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_REL_PDCP_SEC_ENT_WI_LWA()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_ENBL_LWA_ON_EXG_DRB()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_ENBL_LWA_ON_TRANZ_DRB()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DSBL_LWA_BUT_NOT_REL_DRB()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_BACK_TO_LTE_DATA_PATH()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RECOFIG_LWA_PARA()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RBUF_NOT_ACTIVATED()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DRB_IDX()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SW_PIT_WRI_IDX()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_HW_PIT_READ_IDX()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_HW_PIT_READ_RLST()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DRB_HRL_HRW_UTD()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DRB_HRL_HRW()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RCV_ZERO_SZ_LTE_PKT()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RCV_INV_RBID_WIFI_PKT()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RCV_UNEST_DRB_WIFI_PKT()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RCV_LTE_DRB_WIFI_PKT()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RCV_BPS_WIFI_PKT()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RCV_ZERO_SZ_WIFI_PKT()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RX_IW_FROM_LTE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RX_OOW_FROM_LTE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RX_OOW_BY_HW_FROM_LTE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RX_IW_FROM_WIFI()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RX_OOW_FROM_WIFI()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RX_DUPE_WI_LST_ONE_FROM_WIFI()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RX_OOW_DUPE_SN()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RX_DUPE_SN()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DRB_STATE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_MRGE_RCV_PKT_TO_RO_WND()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_PKT_NUM_IN_WND()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_COL_INORDER_ROD()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RO_WND_ADV()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_ENQ_ROD_TO_DLVR_Q()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_ENQ_ROD_WI_RO_FUN_TO_DLVR_Q()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_PROC_ROD_DLVR_Q()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_CMPL_A_SPD()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_ROD_DLVR_Q_PROC_RLST()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DEQ_PKTS_IN_ROD_DLVR_Q()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_TFC_INFO()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_ALLOC_ROD_RO_TBL()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_CLR_ROD_RO_WND()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_FREE_ROD_RO_TBL()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_CLR_ROD_DLVR_Q()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RO_TMR_START()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RO_TMR_EXP()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RO_TMR_EVENT_ID()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RPT_TMR_START()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RPT_TMR_EXP()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_TMR_STOP()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DL_POLL_TMR_START()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DL_POLL_TMR_EXP()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DL_POLL_TMR_STOP()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DL_POLL_TMR_RUNNING()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DELAY_SETTING_TMR_START()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DELAY_SETTING_TMR_EXP()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DELAY_SETTING_TMR_STOP()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_PDCP_STAT_RPT_TIMER_STOPPED()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_LWA_STAT_RPT_TIMER_STOPPED()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_PDCP_PER_STAT_RPT_INFO()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_LWA_PER_STAT_RPT_INFO()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SHRD_MEM_READ_RLST()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SWM_ENQ()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SWM_NULL_HW_CUR_ADDR()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SWM_RQUE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SWM_RQUE_GDMA()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SWM_DEQ()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_PIT_REL_TBL_INFO()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_PIT_ENT_REL_ONE_DIR()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_PIT_ENT_REL_MUL_DIR()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_PIT_ENT_REL_FROM_SPD()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RBUF_RESRC_REL_INFO()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_AVAIL_PIT_IDX_INFO()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_PKT_IN_PIT_INFO()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_EARLY_DLVR_CHK_ON_OFF()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_EARLY_DLVR_CHK_LTE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_EARLY_DLVR_CHK_WIFI()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DBG_SHRD_MEM_DESCP_INFO()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_RPT_BY_POLL_CFG()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_UPCTRL_DL_SHRD_MEM_INIT_FAIL()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_DL_DIR_RX_CTRL_PDU()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SHRTG_OF_SPD()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SHRTG_OF_HW_RBUF_RESRC()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SHRTG_OF_SW_RBUF_RESRC()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_SHRTG_OF_PIT_REL_TBL_RESRC()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_GDMA_BUSY_CNT()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()
#define ChkL1MsgFltr_EPDCP_LOG_LWA_EARLY_DLVR()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_LWA()


#endif
