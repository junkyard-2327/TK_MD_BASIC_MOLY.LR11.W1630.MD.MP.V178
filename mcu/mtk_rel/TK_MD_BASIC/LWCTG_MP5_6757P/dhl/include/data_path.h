#ifndef L1TRC_NAS_DATA_PATH_DEF_H
#define L1TRC_NAS_DATA_PATH_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_CONSTRUCT_UL_SDU(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x000B | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define RATDM_CONSTRUCT_UL_SDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_UL_TCP_ACK_COPY_FAIL(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x010B | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define RATDM_UL_TCP_ACK_COPY_FAIL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_QUEUE_UL_SDU(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x020B | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define RATDM_QUEUE_UL_SDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_PROCESS_EPSB_UL_Q(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x030B | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define RATDM_PROCESS_EPSB_UL_Q(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_PROCESS_EPSB_DL(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x040B | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define RATDM_PROCESS_EPSB_DL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_ROLLBACK(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x050B | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define RATDM_ROLLBACK(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_NXT_DRX_IND(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x060B | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define RATDM_NXT_DRX_IND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_EPSB_INIT(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x070B | ((short)(v1) << 16), (kal_uint32)((char)(v4)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define RATDM_EPSB_INIT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_EPSB_ACT(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x080B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define RATDM_EPSB_ACT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_EPSB_DEACT(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x090B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define RATDM_EPSB_DEACT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_IDLE_ENTER(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0A0B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define RATDM_IDLE_ENTER(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_IDLE_ENTER_CHECK(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0B0B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define RATDM_IDLE_ENTER_CHECK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_IDLE_LEAVE(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0C0B | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define RATDM_IDLE_LEAVE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_IDLE_LEAVE_REJ(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0D0B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define RATDM_IDLE_LEAVE_REJ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_IDLE_LEAVE_REJ_DROP(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0E0B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define RATDM_IDLE_LEAVE_REJ_DROP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_SUSPEND(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0F0B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define RATDM_SUSPEND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_RESUME(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x100B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define RATDM_RESUME(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_GEMINI_SUSPEND(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x110B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define RATDM_GEMINI_SUSPEND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_GEMINI_RESUME(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x120B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define RATDM_GEMINI_RESUME(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_QUERY_UL_DATA_STATUS(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x130B | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define RATDM_QUERY_UL_DATA_STATUS(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_IDLE_LEAVE_BY_QUERY(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x140B | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define RATDM_IDLE_LEAVE_BY_QUERY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATDM_IDLE_LEAVE_BY_QUEUED(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x150B | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define RATDM_IDLE_LEAVE_BY_QUEUED(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_RESET_EPSB(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x160B | ((short)(v1) << 16));\
	} while(0)
#else
	#define UPCM_RESET_EPSB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_UL_TFT_NoMatch(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x170B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_UL_TFT_NoMatch(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_DispatchUL(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x180B | ((short)(v1) << 16));\
	} while(0)
#else
	#define UPCM_DispatchUL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_RCV_UL_SUSPEND(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x190B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define UPCM_RCV_UL_SUSPEND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_ProcPF(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x1A0B | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define UPCM_ProcPF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_ProcBearer(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x1B0B | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define UPCM_ProcBearer(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_UnBind(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x1C0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define UPCM_UnBind(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_UnBindRcv(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x1D0B | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define UPCM_UnBindRcv(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_UnBindRsp(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1E0B | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_UnBindRsp(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_Bind(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x1F0B | ((short)(v1) << 16), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UPCM_Bind(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_BindRsp(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x200B | ((short)(v1) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UPCM_BindRsp(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_BindFail(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x210B | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_BindFail(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_BindWthTest(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x220B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_BindWthTest(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_MBMSALBind(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x230B | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UPCM_MBMSALBind(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_MBMSALUnBindRcv(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x240B | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define UPCM_MBMSALUnBindRcv(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_MBMSALUnBindRsp(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x250B | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_MBMSALUnBindRsp(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_SuspendResume(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x260B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_SuspendResume(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_RollbackSDUs(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x270B | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UPCM_RollbackSDUs(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_NotifyLTE_Tick(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x280B | ((short)(v1) << 16));\
	} while(0)
#else
	#define UPCM_NotifyLTE_Tick(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_RcvUL_SDUsEBI(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x290B | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UPCM_RcvUL_SDUsEBI(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_DropUL_SDUs(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x2A0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define UPCM_DropUL_SDUs(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_TEST_MODE_DL(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x2B0B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_TEST_MODE_DL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_ActvTestMode(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x2C0B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_ActvTestMode(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_DeActvTestMode(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x2D0B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_DeActvTestMode(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_TestModeFail(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x2E0B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_TestModeFail(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_TestLoopAct(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x2F0B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_TestLoopAct(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_SetEPSB_IMS_Type(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x300B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define UPCM_SetEPSB_IMS_Type(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_ClrEPSB_IMS_Type(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x310B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define UPCM_ClrEPSB_IMS_Type(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_AddPFLink(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x320B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define TFTPF_AddPFLink(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_RemovePFLink(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x330B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define TFTPF_RemovePFLink(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_GetNoPF_EBI(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x340B | ((short)(v1) << 16));\
	} while(0)
#else
	#define TFTPF_GetNoPF_EBI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_ActvEPSB(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x350B | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define TFTPF_ActvEPSB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DeactEPSB(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x360B | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define TFTPF_DeactEPSB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_AddPF(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x370B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define TFTPF_AddPF(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_ReplacePF(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x380B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define TFTPF_ReplacePF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DelPF(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x390B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define TFTPF_DelPF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_SetDftMatch(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x3A0B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define TFTPF_SetDftMatch(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DelAll(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x3B0B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TFTPF_DelAll(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_PF_NotFound(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x3C0B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define TFTPF_PF_NotFound(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_PF_Link_AllocFail(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x3D0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define TFTPF_PF_Link_AllocFail(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPktFilter1(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_4_word(0x3E0B | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define TFTPF_DumpPktFilter1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpIPAddr(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_4_word(0x3F0B | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TFTPF_DumpIPAddr(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpIPAddrMsk(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_4_word(0x400B | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TFTPF_DumpIPAddrMsk(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPFProtocol(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_2_word(0x410B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TFTPF_DumpPFProtocol(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPFPort(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_3_word(0x420B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define TFTPF_DumpPFPort(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPFSPI(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_2_word(0x430B | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define TFTPF_DumpPFSPI(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPFTOS(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_2_word(0x440B | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define TFTPF_DumpPFTOS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPFFlowLabel(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_2_word(0x450B | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define TFTPF_DumpPFFlowLabel(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_PktCorrupted(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_2_word(0x460B | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TFTPF_PktCorrupted(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_MatchCorrupted(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_1_word(0x470B | ((short)(v1) << 16));\
	} while(0)
#else
	#define TFTPF_MatchCorrupted(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char NAS_DATA_PATH_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_RATDM_CONSTRUCT_UL_SDU(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_RATDM_UL_TCP_ACK_COPY_FAIL(short v1, unsigned long v2);
void L1TRC_Send_RATDM_QUEUE_UL_SDU(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_RATDM_PROCESS_EPSB_UL_Q(unsigned short v1);
void L1TRC_Send_RATDM_PROCESS_EPSB_DL(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_RATDM_ROLLBACK(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_RATDM_NXT_DRX_IND(unsigned short v1, char v2);
void L1TRC_Send_RATDM_EPSB_INIT(short v1, long v2, long v3, char v4);
void L1TRC_Send_RATDM_EPSB_ACT(short v1, char v2);
void L1TRC_Send_RATDM_EPSB_DEACT(short v1, char v2);
void L1TRC_Send_RATDM_IDLE_ENTER(short v1, char v2);
void L1TRC_Send_RATDM_IDLE_ENTER_CHECK(short v1, long v2);
void L1TRC_Send_RATDM_IDLE_LEAVE(short v1, long v2, char v3);
void L1TRC_Send_RATDM_IDLE_LEAVE_REJ(short v1, char v2);
void L1TRC_Send_RATDM_IDLE_LEAVE_REJ_DROP(short v1, char v2, char v3);
void L1TRC_Send_RATDM_SUSPEND(short v1, char v2);
void L1TRC_Send_RATDM_RESUME(short v1, char v2);
void L1TRC_Send_RATDM_GEMINI_SUSPEND(short v1, char v2);
void L1TRC_Send_RATDM_GEMINI_RESUME(short v1, char v2);
void L1TRC_Send_RATDM_QUERY_UL_DATA_STATUS(short v1, unsigned long v2, long v3);
void L1TRC_Send_RATDM_IDLE_LEAVE_BY_QUERY(unsigned short v1);
void L1TRC_Send_RATDM_IDLE_LEAVE_BY_QUEUED(unsigned short v1, unsigned long v2);
void L1TRC_Send_UPCM_RESET_EPSB(short v1);
void L1TRC_Send_UPCM_UL_TFT_NoMatch(short v1, char v2);
void L1TRC_Send_UPCM_DispatchUL(short v1);
void L1TRC_Send_UPCM_RCV_UL_SUSPEND(short v1, char v2, unsigned long v3);
void L1TRC_Send_UPCM_ProcPF(short v1, long v2, char v3);
void L1TRC_Send_UPCM_ProcBearer(unsigned short v1, long v2, char v3);
void L1TRC_Send_UPCM_UnBind(short v1);
void L1TRC_Send_UPCM_UnBindRcv(short v1, long v2, char v3);
void L1TRC_Send_UPCM_UnBindRsp(short v1, short v2);
void L1TRC_Send_UPCM_Bind(short v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_UPCM_BindRsp(short v1, long v2, unsigned long v3, short v4);
void L1TRC_Send_UPCM_BindFail(short v1, short v2);
void L1TRC_Send_UPCM_BindWthTest(short v1, char v2);
void L1TRC_Send_UPCM_MBMSALBind(short v1, long v2, unsigned long v3);
void L1TRC_Send_UPCM_MBMSALUnBindRcv(short v1, long v2, char v3);
void L1TRC_Send_UPCM_MBMSALUnBindRsp(short v1, short v2);
void L1TRC_Send_UPCM_SuspendResume(short v1, char v2);
void L1TRC_Send_UPCM_RollbackSDUs(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UPCM_NotifyLTE_Tick(short v1);
void L1TRC_Send_UPCM_RcvUL_SDUsEBI(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UPCM_DropUL_SDUs(short v1);
void L1TRC_Send_UPCM_TEST_MODE_DL(short v1, char v2, char v3);
void L1TRC_Send_UPCM_ActvTestMode(short v1, char v2);
void L1TRC_Send_UPCM_DeActvTestMode(short v1, char v2);
void L1TRC_Send_UPCM_TestModeFail(short v1, char v2);
void L1TRC_Send_UPCM_TestLoopAct(short v1, char v2, char v3);
void L1TRC_Send_UPCM_SetEPSB_IMS_Type(short v1, char v2, unsigned long v3);
void L1TRC_Send_UPCM_ClrEPSB_IMS_Type(short v1, char v2, unsigned long v3);
void L1TRC_Send_TFTPF_AddPFLink(short v1, long v2, long v3);
void L1TRC_Send_TFTPF_RemovePFLink(short v1, long v2, long v3);
void L1TRC_Send_TFTPF_GetNoPF_EBI(short v1);
void L1TRC_Send_TFTPF_ActvEPSB(short v1, long v2, char v3);
void L1TRC_Send_TFTPF_DeactEPSB(short v1, long v2, char v3);
void L1TRC_Send_TFTPF_AddPF(short v1, char v2, long v3, long v4);
void L1TRC_Send_TFTPF_ReplacePF(short v1, char v2, long v3);
void L1TRC_Send_TFTPF_DelPF(short v1, char v2, long v3);
void L1TRC_Send_TFTPF_SetDftMatch(short v1, long v2);
void L1TRC_Send_TFTPF_DelAll(short v1, char v2);
void L1TRC_Send_TFTPF_PF_NotFound(short v1, long v2);
void L1TRC_Send_TFTPF_PF_Link_AllocFail(short v1);
void L1TRC_Send_TFTPF_DumpPktFilter1(short v1, long v2, char v3, long v4);
void L1TRC_Send_TFTPF_DumpIPAddr(short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_TFTPF_DumpIPAddrMsk(short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_TFTPF_DumpPFProtocol(short v1, char v2);
void L1TRC_Send_TFTPF_DumpPFPort(short v1, long v2, long v3);
void L1TRC_Send_TFTPF_DumpPFSPI(short v1, unsigned long v2);
void L1TRC_Send_TFTPF_DumpPFTOS(unsigned short v1, unsigned long v2);
void L1TRC_Send_TFTPF_DumpPFFlowLabel(short v1, unsigned long v2);
void L1TRC_Send_TFTPF_PktCorrupted(short v1, char v2);
void L1TRC_Send_TFTPF_MatchCorrupted(short v1);

void Set_NAS_DATA_PATH_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_NAS_DATA_PATH()	(NAS_DATA_PATH_Trace_Filter[0]==1)
#define ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_RATDM_DUMP()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_UPCM_DUMP()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x20)!=0))
#define ChkL1MsgFltr_RATDM_CONSTRUCT_UL_SDU()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_UL_TCP_ACK_COPY_FAIL()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_QUEUE_UL_SDU()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_DUMP()
#define ChkL1MsgFltr_RATDM_PROCESS_EPSB_UL_Q()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_PROCESS_EPSB_DL()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_DUMP()
#define ChkL1MsgFltr_RATDM_ROLLBACK()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_NXT_DRX_IND()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_EPSB_INIT()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_EPSB_ACT()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_EPSB_DEACT()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_IDLE_ENTER()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_IDLE_ENTER_CHECK()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_DUMP()
#define ChkL1MsgFltr_RATDM_IDLE_LEAVE()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_DUMP()
#define ChkL1MsgFltr_RATDM_IDLE_LEAVE_REJ()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_IDLE_LEAVE_REJ_DROP()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_SUSPEND()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_RESUME()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_GEMINI_SUSPEND()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_GEMINI_RESUME()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_QUERY_UL_DATA_STATUS()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_IDLE_LEAVE_BY_QUERY()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_RATDM_IDLE_LEAVE_BY_QUEUED()	ChkL1ClsFltr_NAS_DATA_PATH_RATDM_INFO()
#define ChkL1MsgFltr_UPCM_RESET_EPSB()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_UL_TFT_NoMatch()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_DUMP()
#define ChkL1MsgFltr_UPCM_DispatchUL()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_DUMP()
#define ChkL1MsgFltr_UPCM_RCV_UL_SUSPEND()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_ProcPF()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_ProcBearer()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_UnBind()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_UnBindRcv()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_UnBindRsp()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_Bind()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_BindRsp()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_BindFail()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_BindWthTest()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_MBMSALBind()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_MBMSALUnBindRcv()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_MBMSALUnBindRsp()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_SuspendResume()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_RollbackSDUs()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_DUMP()
#define ChkL1MsgFltr_UPCM_NotifyLTE_Tick()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_RcvUL_SDUsEBI()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_DropUL_SDUs()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_TEST_MODE_DL()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_ActvTestMode()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_DeActvTestMode()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_TestModeFail()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_TestLoopAct()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_SetEPSB_IMS_Type()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_ClrEPSB_IMS_Type()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_TFTPF_AddPFLink()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_RemovePFLink()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_GetNoPF_EBI()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_ActvEPSB()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_DeactEPSB()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_AddPF()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_ReplacePF()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_DelPF()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_SetDftMatch()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_DelAll()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_PF_NotFound()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_PF_Link_AllocFail()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_DumpPktFilter1()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpIPAddr()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpIPAddrMsk()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpPFProtocol()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpPFPort()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpPFSPI()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpPFTOS()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpPFFlowLabel()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_PktCorrupted()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_MatchCorrupted()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()


#endif
