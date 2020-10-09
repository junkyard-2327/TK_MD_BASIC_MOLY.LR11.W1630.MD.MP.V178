#ifndef L1TRC_ROHC_DEF_H
#define L1TRC_ROHC_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_GENERIC(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x000E | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_GENERIC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_ADD_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x010E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_ADD_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_DEL_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x020E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_DEL_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_RST_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x030E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_RST_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_ADD_EXISTED_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x040E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_ADD_EXISTED_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_DEL_NON_EXISTED_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x050E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_DEL_NON_EXISTED_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_RST_NON_EXISTED_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x060E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_RST_NON_EXISTED_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_PHASE1_START(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x070E | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_PHASE1_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_PHASE1_END(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x080E | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_PHASE1_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_TRAN_REJECT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x090E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_TRAN_REJECT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_TRAN_DONE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0A0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_TRAN_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_REJECT_CNTXT_NULL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0B0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_REJECT_CNTXT_NULL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_REJECT_WRONG_PROFILE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0C0E | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_REJECT_WRONG_PROFILE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_REJECT_ALLOWED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0D0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_REJECT_ALLOWED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_ACCEPT_ALLOWED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0E0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_ACCEPT_ALLOWED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_STATE_TRAN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0F0E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_STATE_TRAN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UPDATE_SEQ_WITH_UPDT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x100E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UPDATE_SEQ_WITH_UPDT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_SEQ_WITH_UPDT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x110E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_SEQ_WITH_UPDT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_SEQ_WITH_UPDT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x120E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_SEQ_WITH_UPDT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TMO_IN_SO(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x130E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TMO_IN_SO(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_NACK(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x140E | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_NACK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_SNACK(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x150E | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_SNACK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_CNSM(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x160E | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_CNSM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_SET_DFLT_TS_STRIDE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x170E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_SET_DFLT_TS_STRIDE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_UPDTE_TS_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x180E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_UPDTE_TS_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK_UP_TRAN_NOT_ALLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x190E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK_UP_TRAN_NOT_ALLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_INFO_1(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1A0E | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_INFO_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_INFO_2(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1B0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_INFO_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_TREAT_SNACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1C0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_TREAT_SNACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_ACK_NUM_INVALID(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1D0E | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_ACK_NUM_INVALID(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_1(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1E0E | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_2(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1F0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_TREAT_SNACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x200E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_TREAT_SNACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_INVALID(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x210E | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_INVALID(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_NOT_VALID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x220E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_NOT_VALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_TYPE_INVALID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x230E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_TYPE_INVALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CID_CHNG_TO_CID_0(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x240E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_CID_CHNG_TO_CID_0(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CHNG_RTP(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x250E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CHNG_RTP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CHNG_UNCOMP(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x260E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CHNG_UNCOMP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CREATE(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x270E | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CREATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CREATE_PORT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x280E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CREATE_PORT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MATCH_REJECT_CNTXT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x290E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MATCH_REJECT_CNTXT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_ADD_RTP_FLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2A0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_ADD_RTP_FLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_DEL_RTP_FLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2B0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_DEL_RTP_FLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV4(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2C0E | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV4(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV6(v1, v2, v3, v4, v5) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_5_word(0x2D0E | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV6(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2E0E | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_MATCH(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2F0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_MATCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_ENTER_MATCH_RTP_FLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x300E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_ENTER_MATCH_RTP_FLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_INNER_IP_MATCH(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x310E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_INNER_IP_MATCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_UDP_MATCH(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x320E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_UDP_MATCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_MATCH(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x330E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_MATCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_ECN_USED(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x340E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_ECN_USED(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x350E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_DF(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x360E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_DF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x370E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV6_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x380E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV6_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV6_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x390E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV6_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_IPID_BHVR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3A0E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_IPID_BHVR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3B0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_DSCP(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3C0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_DSCP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_IP_ECN_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3D0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_IP_ECN_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_DF(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3E0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_DF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3F0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x400E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_DSCP(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x410E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_DSCP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_IP_ECN_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x420E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_IP_ECN_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x430E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_IPID_BHVR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x440E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_IPID_BHVR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_IP_FRAG_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x450E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_IP_FRAG_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_UDP_CHECKSUM(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x460E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_UDP_CHECKSUM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_RES_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x470E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_RES_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_ECN_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x480E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_ECN_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_URG_FLAG(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x490E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_URG_FLAG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_ACK_FLAG(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4A0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_ACK_FLAG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_RSF_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4B0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_RSF_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_WINDOW(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4C0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_WINDOW(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_URG_PTR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4D0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_URG_PTR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_OPT_RESET(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4E0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_OPT_RESET(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_OPT_UPDT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4F0E | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_OPT_UPDT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_OPT_DEL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x500E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_OPT_DEL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_ACK_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x510E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_ACK_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_SEQ_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x520E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_SEQ_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_PAD_BIT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x530E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_PAD_BIT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_EXTENSION(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x540E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_EXTENSION(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_P2NULL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x550E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_P2NULL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_NULL2P(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x560E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_NULL2P(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_CHANGE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x570E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_CHANGE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_MARKER_TOGGLE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x580E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_MARKER_TOGGLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_PT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x590E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_PT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021_INF(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5A0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021_INF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_OFF_TS_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5B0E | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_OFF_TS_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_SCLD_LSB(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5C0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_SCLD_LSB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5D0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_WRAP(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5E0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_WRAP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_ENABLE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5F0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_DISABLE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x600E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_UPDATE_TIME_STRIDE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x610E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_UPDATE_TIME_STRIDE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_INSERT_ONLY(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x620E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_INSERT_ONLY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_REMOVE_ONLY(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x630E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_REMOVE_ONLY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_RM_THEN_INS(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x640E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_RM_THEN_INS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_GENERIC(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x650E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_GENERIC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_UDP_ERR_SEL_EXT2(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x660E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_UDP_ERR_SEL_EXT2(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_ENC_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x670E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_ENC_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_ENC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x680E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_ENC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_OPT_INVALID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x690E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_OPT_INVALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_RSF_FLAG_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6A0E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_RSF_FLAG_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UNKNOWN_IP_VER(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6B0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UNKNOWN_IP_VER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_GET_STATIC_FIELD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6C0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_GET_STATIC_FIELD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CNTXT_REPLACE(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x6D0E | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_CNTXT_REPLACE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PARAM_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6E0E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PARAM_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_IPV4_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6F0E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_IPV4_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_IPV6_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x700E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_IPV6_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_UDP_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x710E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_UDP_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x720E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_EOL_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x730E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_EOL_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x740E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_END_ERR(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x750E | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_END_ERR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_IPV4_FLAG_FRAG_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x760E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_IPV4_FLAG_FRAG_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_OUTER_IPV4_INFO_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x770E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_OUTER_IPV4_INFO_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_OUTER_IPV6_INFO_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x780E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_OUTER_IPV6_INFO_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x790E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_C_LOG_REF_CSRC_LIST_UNDERRUN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7A0E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_C_LOG_REF_CSRC_LIST_UNDERRUN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_C_LOG_RM_CSRC_LIST_OVERRUN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7B0E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_C_LOG_RM_CSRC_LIST_OVERRUN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_OUTER_IP_INFO_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7C0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_OUTER_IP_INFO_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CNTXT_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7D0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CNTXT_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_REPAIR_OK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7E0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_REPAIR_OK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_REPAIR_HAPPEN(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7F0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_REPAIR_HAPPEN(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_REPAIR_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x800E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_REPAIR_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC3_OK_FC_TRG_ACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x810E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC3_OK_FC_TRG_ACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC7_OK_FC_TRG_ACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x820E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC7_OK_FC_TRG_ACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_OK_FC_CR_TRG_ACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x830E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_OK_FC_CR_TRG_ACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_FDBK_ACK_NUM(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x840E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_FDBK_ACK_NUM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_PRODUCE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x850E | ((unsigned short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_PRODUCE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_REF_LIST_REPLACED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x860E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_REF_LIST_REPLACED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_REF_LIST_INSERTED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x870E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_REF_LIST_INSERTED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_FDBK_START(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x880E | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_FDBK_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_FDBK_END(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x890E | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_FDBK_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_DONE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8A0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8B0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_V2(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8C0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_V2(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_PARSE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8D0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_PARSE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8E0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_HEADER_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8F0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_HEADER_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_RCVD_MODE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x900E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_RCVD_MODE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_PARSE_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x910E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_PARSE_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_MATCH_CNTXT(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x920E | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_MATCH_CNTXT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_MATCH_NO_CNTXT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x930E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_MATCH_NO_CNTXT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_INIT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x940E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_INIT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NO_NEED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x950E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NO_NEED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_CANCEL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x960E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_CANCEL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_BCID_MATCH(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x970E | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_TCP_BCID_MATCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SIZE_TOO_LARGE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x980E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SIZE_TOO_LARGE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_BUF_FULL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x990E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_BUF_FULL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SUPRESS(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9A0E | ((unsigned short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SUPRESS(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9B0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_CRC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9C0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_CRC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SIZE_VER_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9D0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SIZE_VER_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9E0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PARSE_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9F0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PARSE_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_ROHCV1_PARSE_IP_IN_STATIC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA00E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_ROHCV1_PARSE_IP_IN_STATIC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_STATE_TRAN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA10E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_STATE_TRAN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_VALUE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA20E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_VALUE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_DEC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA30E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_DEC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_DEC_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA40E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_DEC_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IR_DEC_FAIL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA50E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_IR_DEC_FAIL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_ROHCV2_D_RTP_SDVL_LSB_DEC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA60E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_ROHCV2_D_RTP_SDVL_LSB_DEC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_ROHCV2_D_RTP_SDVL_DEC_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA70E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_ROHCV2_D_RTP_SDVL_DEC_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_REF_ID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA80E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_REF_ID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_COUNT_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA90E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_COUNT_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_REF_EXHAUSTED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAA0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_REF_EXHAUSTED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_THEN_INS_REF_ID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAB0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_THEN_INS_REF_ID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_THEN_INS_RM_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAC0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_THEN_INS_RM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_THEN_INS_INS_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAD0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_THEN_INS_INS_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_GP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAE0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_GP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_INS_NUM_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAF0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_INS_NUM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_IDX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB00E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_IDX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_DUP_IDX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB10E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_DUP_IDX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_GP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB20E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_GP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_RM_NUM_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB30E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_RM_NUM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_IR_PARSE_NON_GEN(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB40E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_IR_PARSE_NON_GEN(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_IR_PARSE_GP_NON_ZERO(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB50E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_IR_PARSE_GP_NON_ZERO(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_PARSE_GP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB60E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_PARSE_GP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_DST_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB70E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_DST_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_DUP_IDX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB80E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_DUP_IDX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_RSVD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB90E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_RSVD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_IP2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBA0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_IP2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBB0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBC0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_LIST_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBD0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_LIST_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_TS_STRIDE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBE0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_TS_STRIDE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_TIME_STRIDE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBF0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_TIME_STRIDE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_TSC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC00E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_TSC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC10E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC20E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_IP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC30E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_IP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV2_PARSE_DYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC40E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV2_PARSE_DYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC50E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_IP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC60E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_IP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IP2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC70E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IP2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC80E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC90E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UDP_ROHCV1_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCA0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UDP_ROHCV1_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UDP_ROHCV1_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCB0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UDP_ROHCV1_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UDP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCC0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UDP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UNCOMP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCD0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UNCOMP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_ROHCV1_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCE0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_ROHCV1_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_ROHCV1_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCF0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_ROHCV1_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD00E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD10E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_CR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD20E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_CR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD30E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_BCID_NO_MATCH(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xD40E | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_TCP_BCID_NO_MATCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_REP_PROFILE_NOT_SUPPORT(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xD50E | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_TCP_REP_PROFILE_NOT_SUPPORT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_REP_CNTXT_CPY_FAIL(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xD60E | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_TCP_REP_CNTXT_CPY_FAIL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_OPTIONS_RSVD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD70E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_OPTIONS_RSVD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_IP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD80E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_IP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_OPT_RSVD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD90E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_OPT_RSVD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PROFILE_NOT_SUPPORT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDA0E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PROFILE_NOT_SUPPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PROFILE_SUPPORT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDB0E | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PROFILE_SUPPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UNKNOWN_CID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDC0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UNKNOWN_CID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_ENFORCE_IR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDD0E | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_ENFORCE_IR(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char ROHC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_ROHC_LOG_GENERIC(short v1, long v2, long v3, long v4);
void L1TRC_Send_ROHC_LOG_CFG_ADD_INST(short v1);
void L1TRC_Send_ROHC_LOG_CFG_DEL_INST(short v1);
void L1TRC_Send_ROHC_LOG_CFG_RST_INST(short v1);
void L1TRC_Send_ROHC_LOG_CFG_ADD_EXISTED_INST(short v1);
void L1TRC_Send_ROHC_LOG_CFG_DEL_NON_EXISTED_INST(short v1);
void L1TRC_Send_ROHC_LOG_CFG_RST_NON_EXISTED_INST(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_PHASE1_START(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_PHASE1_END(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_C_MODE_TRAN_REJECT(short v1, long v2);
void L1TRC_Send_ROHC_LOG_C_MODE_TRAN_DONE(short v1);
void L1TRC_Send_ROHC_LOG_C_MODE_REJECT_CNTXT_NULL(short v1);
void L1TRC_Send_ROHC_LOG_C_MODE_REJECT_WRONG_PROFILE(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_REJECT_ALLOWED(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_ACCEPT_ALLOWED(short v1);
void L1TRC_Send_ROHC_LOG_C_STATE_TRAN(short v1, long v2);
void L1TRC_Send_ROHC_LOG_UPDATE_SEQ_WITH_UPDT(unsigned short v1);
void L1TRC_Send_ROHC_LOG_SEQ_WITH_UPDT(unsigned short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_SEQ_WITH_UPDT(unsigned short v1);
void L1TRC_Send_ROHC_LOG_TMO_IN_SO(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_NACK(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_SNACK(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_FDBK_CNSM(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_C_SET_DFLT_TS_STRIDE(short v1);
void L1TRC_Send_ROHC_LOG_C_UPDTE_TS_STRIDE(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK_UP_TRAN_NOT_ALLOW(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK1_INFO_1(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK1_INFO_2(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK1_TREAT_SNACK(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK1_ACK_NUM_INVALID(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_ACK_INFO_1(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_ACK_INFO_2(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_TREAT_SNACK(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_ACK_NUM_INVALID(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_ACK_NUM_NOT_VALID(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_ACK_TYPE_INVALID(unsigned short v1);
void L1TRC_Send_ROHC_LOG_C_CID_CHNG_TO_CID_0(short v1);
void L1TRC_Send_ROHC_LOG_C_CNTXT_CHNG_RTP(short v1);
void L1TRC_Send_ROHC_LOG_C_CNTXT_CHNG_UNCOMP(short v1);
void L1TRC_Send_ROHC_LOG_C_CNTXT_CREATE(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_C_CNTXT_CREATE_PORT(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_MATCH_REJECT_CNTXT(short v1);
void L1TRC_Send_ROHC_LOG_C_REG_ADD_RTP_FLOW(short v1);
void L1TRC_Send_ROHC_LOG_C_REG_DEL_RTP_FLOW(short v1);
void L1TRC_Send_ROHC_LOG_C_REG_RTP_FLOW_IPV4(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_C_REG_RTP_FLOW_IPV6(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP(unsigned short v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_ROHC_LOG_C_REG_RTP_FLOW_MATCH(short v1);
void L1TRC_Send_ROHC_LOG_C_REG_ENTER_MATCH_RTP_FLOW(short v1);
void L1TRC_Send_ROHC_LOG_C_REG_INNER_IP_MATCH(short v1);
void L1TRC_Send_ROHC_LOG_C_REG_UDP_MATCH(short v1);
void L1TRC_Send_ROHC_LOG_C_REG_RTP_MATCH(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_ECN_USED(short v1, long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV4_TOS_TC(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV4_DF(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV4_TTL_HOPL(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV6_TOS_TC(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV6_TTL_HOPL(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV4_IPID_BHVR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_TOS_TC(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_DSCP(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_IP_ECN_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_DF(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_TTL_HOPL(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV6_TOS_TC(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV6_DSCP(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV6_IP_ECN_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV6_TTL_HOPL(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_IPID_BHVR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_PTRN_IP_FRAG_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_UDP_CHECKSUM(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_RES_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_ECN_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_URG_FLAG(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_ACK_FLAG(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_RSF_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_WINDOW(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_URG_PTR(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_OPT_RESET(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_OPT_UPDT(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_OPT_DEL(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_ACK_STRIDE(short v1, long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_SEQ_STRIDE(short v1, long v2);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_PAD_BIT(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_EXTENSION(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_P2NULL(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_NULL2P(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_CHANGE(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_MARKER_TOGGLE(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_PT(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TSC_IND_021_INF(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TS_OFF_TS_STRIDE(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TS_SCLD_LSB(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TSC_IND_021(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TS_WRAP(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TS_TMR_BSD_ENABLE(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TS_TMR_BSD_DISABLE(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_UPDATE_TIME_STRIDE(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_INSERT_ONLY(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_REMOVE_ONLY(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_RM_THEN_INS(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_GENERIC(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PTRN_UDP_ERR_SEL_EXT2(short v1);
void L1TRC_Send_ROHC_LOG_CID_SDVL_ENC_SIZE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_CID_SDVL_ENC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_OPT_INVALID(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_RSF_FLAG_ERR(unsigned short v1);
void L1TRC_Send_ROHC_LOG_UNKNOWN_IP_VER(short v1);
void L1TRC_Send_ROHC_LOG_GET_STATIC_FIELD_ERR(short v1);
void L1TRC_Send_ROHC_LOG_CNTXT_REPLACE(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ROHC_LOG_PARAM_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_IPV4_HDR_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_IPV6_HDR_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_UDP_HDR_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_TCP_HDR_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_TCP_OPT_EOL_ERR(unsigned short v1);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_TCP_OPT_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_TCP_OPT_END_ERR(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_IPV4_FLAG_FRAG_ERR(short v1);
void L1TRC_Send_ROHC_LOG_OUTER_IPV4_INFO_ALLOC_FAIL(short v1);
void L1TRC_Send_ROHC_LOG_OUTER_IPV6_INFO_ALLOC_FAIL(short v1);
void L1TRC_Send_ROHC_LOG_C_CNTXT_ALLOC_FAIL(short v1);
void L1TRC_Send_ROHC_C_LOG_REF_CSRC_LIST_UNDERRUN(short v1, long v2);
void L1TRC_Send_ROHC_C_LOG_RM_CSRC_LIST_OVERRUN(short v1, long v2);
void L1TRC_Send_ROHC_LOG_OUTER_IP_INFO_ALLOC_FAIL(short v1);
void L1TRC_Send_ROHC_LOG_D_CNTXT_ALLOC_FAIL(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC_REPAIR_OK(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC_REPAIR_HAPPEN(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC_REPAIR_FAIL(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC3_OK_FC_TRG_ACK(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC7_OK_FC_TRG_ACK(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC_OK_FC_CR_TRG_ACK(short v1);
void L1TRC_Send_ROHC_LOG_D_FDBK_ACK_NUM(unsigned short v1);
void L1TRC_Send_ROHC_LOG_FDBK_PRODUCE(unsigned short v1, long v2);
void L1TRC_Send_ROHC_LOG_D_REF_LIST_REPLACED(unsigned short v1);
void L1TRC_Send_ROHC_LOG_D_REF_LIST_INSERTED(unsigned short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_FDBK_START(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_FDBK_END(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_DONE(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NOT_ALLOW(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NOT_ALLOW_V2(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NOT_ALLOW_PARSE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NOT_ALLOW_CID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NOT_ALLOW_HEADER_ERR(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_RCVD_MODE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_MODE_PARSE_CID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_MODE_MATCH_CNTXT(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_MODE_MATCH_NO_CNTXT(short v1, long v2);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_INIT(short v1, long v2);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NO_NEED(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_CANCEL(short v1, long v2);
void L1TRC_Send_ROHC_LOG_TCP_BCID_MATCH(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_FDBK_SIZE_TOO_LARGE(short v1);
void L1TRC_Send_ROHC_LOG_FDBK_BUF_FULL(short v1);
void L1TRC_Send_ROHC_LOG_FDBK_SUPRESS(unsigned short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_FDBK_SIZE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_FDBK_CRC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_FDBK_SIZE_VER_ERR(short v1);
void L1TRC_Send_ROHC_LOG_FDBK_CID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_PARSE_CID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_ROHCV1_PARSE_IP_IN_STATIC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_D_STATE_TRAN(short v1, long v2);
void L1TRC_Send_ROHC_LOG_CID_SDVL_VALUE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_CID_SDVL_DEC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_CID_SDVL_DEC_SIZE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IR_DEC_FAIL(short v1, long v2);
void L1TRC_Send_ROHC_LOG_ROHCV2_D_RTP_SDVL_LSB_DEC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_ROHCV2_D_RTP_SDVL_DEC_SIZE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_ONLY_REF_ID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_ONLY_COUNT_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_REF_EXHAUSTED(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_THEN_INS_REF_ID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_THEN_INS_RM_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_THEN_INS_INS_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_INS_ONLY_GP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_INS_ONLY_INS_NUM_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_INS_ONLY_IDX_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_INS_ONLY_DUP_IDX_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_ONLY_GP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_ONLY_RM_NUM_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_IR_PARSE_NON_GEN(short v1);
void L1TRC_Send_ROHC_LOG_LIST_IR_PARSE_GP_NON_ZERO(short v1);
void L1TRC_Send_ROHC_LOG_LIST_GEN_PARSE_GP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_GEN_DST_SIZE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_GEN_DUP_IDX_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_GEN_RSVD_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_IP2_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_IPX_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_IPX2_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_LIST_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_TS_STRIDE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_TIME_STRIDE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_TSC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_CHK_IRDYN_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_CHK_IR_IP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV2_PARSE_DYN_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV2_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV2_CHK_IR_IP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_UDP_ROHCV1_EXT_IP2_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX2_ERR(short v1);
void L1TRC_Send_ROHC_LOG_UDP_ROHCV1_CHK_IRDYN_ERR(short v1);
void L1TRC_Send_ROHC_LOG_UDP_ROHCV1_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_UDP_ROHCV2_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_UNCOMP_ROHCV2_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_ROHCV1_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_ROHCV1_CHK_IRDYN_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_ROHCV2_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_ROHCV2_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_ROHCV2_CHK_IR_CR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_ROHCV2_CHK_IRDYN_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_BCID_NO_MATCH(short v1, long v2);
void L1TRC_Send_ROHC_LOG_TCP_REP_PROFILE_NOT_SUPPORT(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_TCP_REP_CNTXT_CPY_FAIL(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_TCP_OPTIONS_RSVD_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_ROHCV2_CHK_IR_IP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_OPT_RSVD_ERR(short v1);
void L1TRC_Send_ROHC_LOG_PROFILE_NOT_SUPPORT(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PROFILE_SUPPORT(unsigned short v1);
void L1TRC_Send_ROHC_LOG_UNKNOWN_CID(short v1);
void L1TRC_Send_ROHC_LOG_C_ENFORCE_IR(short v1);

void Set_ROHC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_ROHC()	(ROHC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_ROHC_ROHC_INFO()	(ChkL1ModFltr_ROHC()&&((ROHC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_ROHC_ROHC_DUMP()	(ChkL1ModFltr_ROHC()&&((ROHC_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_ROHC_LOG_GENERIC()	ChkL1ClsFltr_ROHC_ROHC_DUMP()
#define ChkL1MsgFltr_ROHC_LOG_CFG_ADD_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CFG_DEL_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CFG_RST_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CFG_ADD_EXISTED_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CFG_DEL_NON_EXISTED_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CFG_RST_NON_EXISTED_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_PHASE1_START()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_PHASE1_END()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_MODE_TRAN_REJECT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_MODE_TRAN_DONE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_MODE_REJECT_CNTXT_NULL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_MODE_REJECT_WRONG_PROFILE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_REJECT_ALLOWED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_ACCEPT_ALLOWED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_STATE_TRAN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UPDATE_SEQ_WITH_UPDT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_SEQ_WITH_UPDT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_SEQ_WITH_UPDT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TMO_IN_SO()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_NACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_SNACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_CNSM()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_SET_DFLT_TS_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_UPDTE_TS_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK_UP_TRAN_NOT_ALLOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK1_INFO_1()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK1_INFO_2()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK1_TREAT_SNACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK1_ACK_NUM_INVALID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_ACK_INFO_1()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_ACK_INFO_2()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_TREAT_SNACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_ACK_NUM_INVALID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_ACK_NUM_NOT_VALID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_ACK_TYPE_INVALID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CID_CHNG_TO_CID_0()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_CHNG_RTP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_CHNG_UNCOMP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_CREATE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_CREATE_PORT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MATCH_REJECT_CNTXT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_ADD_RTP_FLOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_DEL_RTP_FLOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_RTP_FLOW_IPV4()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_RTP_FLOW_IPV6()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_RTP_FLOW_MATCH()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_ENTER_MATCH_RTP_FLOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_INNER_IP_MATCH()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_UDP_MATCH()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_RTP_MATCH()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_ECN_USED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV4_TOS_TC()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV4_DF()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV4_TTL_HOPL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV6_TOS_TC()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV6_TTL_HOPL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV4_IPID_BHVR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_TOS_TC()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_DSCP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_IP_ECN_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_DF()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_TTL_HOPL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV6_TOS_TC()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV6_DSCP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV6_IP_ECN_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV6_TTL_HOPL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_IPID_BHVR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_IP_FRAG_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_UDP_CHECKSUM()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_RES_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_ECN_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_URG_FLAG()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_ACK_FLAG()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_RSF_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_WINDOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_URG_PTR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_OPT_RESET()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_OPT_UPDT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_OPT_DEL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_ACK_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_SEQ_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_PAD_BIT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_EXTENSION()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_P2NULL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_NULL2P()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_CHANGE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_MARKER_TOGGLE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_PT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TSC_IND_021_INF()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TS_OFF_TS_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TS_SCLD_LSB()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TSC_IND_021()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TS_WRAP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TS_TMR_BSD_ENABLE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TS_TMR_BSD_DISABLE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_UPDATE_TIME_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_INSERT_ONLY()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_REMOVE_ONLY()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_RM_THEN_INS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_GENERIC()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_UDP_ERR_SEL_EXT2()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CID_SDVL_ENC_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CID_SDVL_ENC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_OPT_INVALID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_RSF_FLAG_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UNKNOWN_IP_VER()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_GET_STATIC_FIELD_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CNTXT_REPLACE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PARAM_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_IPV4_HDR_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_IPV6_HDR_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_UDP_HDR_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_TCP_HDR_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_TCP_OPT_EOL_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_TCP_OPT_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_TCP_OPT_END_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_IPV4_FLAG_FRAG_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_OUTER_IPV4_INFO_ALLOC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_OUTER_IPV6_INFO_ALLOC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_ALLOC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_C_LOG_REF_CSRC_LIST_UNDERRUN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_C_LOG_RM_CSRC_LIST_OVERRUN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_OUTER_IP_INFO_ALLOC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CNTXT_ALLOC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC_REPAIR_OK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC_REPAIR_HAPPEN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC_REPAIR_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC3_OK_FC_TRG_ACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC7_OK_FC_TRG_ACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC_OK_FC_CR_TRG_ACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_FDBK_ACK_NUM()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_PRODUCE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_REF_LIST_REPLACED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_REF_LIST_INSERTED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_FDBK_START()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_FDBK_END()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_DONE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NOT_ALLOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NOT_ALLOW_V2()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NOT_ALLOW_PARSE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NOT_ALLOW_CID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NOT_ALLOW_HEADER_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_RCVD_MODE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_PARSE_CID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_MATCH_CNTXT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_MATCH_NO_CNTXT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_INIT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NO_NEED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_CANCEL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_BCID_MATCH()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_SIZE_TOO_LARGE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_BUF_FULL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_SUPRESS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_CRC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_SIZE_VER_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_CID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PARSE_CID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_ROHCV1_PARSE_IP_IN_STATIC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_STATE_TRAN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CID_SDVL_VALUE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CID_SDVL_DEC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CID_SDVL_DEC_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IR_DEC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_ROHCV2_D_RTP_SDVL_LSB_DEC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_ROHCV2_D_RTP_SDVL_DEC_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_ONLY_REF_ID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_ONLY_COUNT_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_REF_EXHAUSTED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_THEN_INS_REF_ID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_THEN_INS_RM_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_THEN_INS_INS_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_INS_ONLY_GP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_INS_ONLY_INS_NUM_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_INS_ONLY_IDX_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_INS_ONLY_DUP_IDX_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_ONLY_GP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_ONLY_RM_NUM_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_IR_PARSE_NON_GEN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_IR_PARSE_GP_NON_ZERO()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_GEN_PARSE_GP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_GEN_DST_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_GEN_DUP_IDX_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_GEN_RSVD_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_IP2_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_IPX_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_IPX2_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_LIST_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_TS_STRIDE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_TIME_STRIDE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_TSC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_CHK_IRDYN_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_CHK_IR_IP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV2_PARSE_DYN_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV2_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV2_CHK_IR_IP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_UDP_ROHCV1_EXT_IP2_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX2_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UDP_ROHCV1_CHK_IRDYN_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UDP_ROHCV1_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UDP_ROHCV2_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UNCOMP_ROHCV2_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_ROHCV1_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_ROHCV1_CHK_IRDYN_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_ROHCV2_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_ROHCV2_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_ROHCV2_CHK_IR_CR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_ROHCV2_CHK_IRDYN_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_BCID_NO_MATCH()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_REP_PROFILE_NOT_SUPPORT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_REP_CNTXT_CPY_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_OPTIONS_RSVD_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_ROHCV2_CHK_IR_IP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_OPT_RSVD_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PROFILE_NOT_SUPPORT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PROFILE_SUPPORT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UNKNOWN_CID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_ENFORCE_IR()	ChkL1ClsFltr_ROHC_ROHC_INFO()


#endif
