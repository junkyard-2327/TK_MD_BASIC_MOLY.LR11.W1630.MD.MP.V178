#ifndef L1TRC_ROHC_DETAIL_DEF_H
#define L1TRC_ROHC_DETAIL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_IP_PTRN(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x000F | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_IP_PTRN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_MATCH(v1, v2, v3) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x010F | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_MATCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_PKT_ARRV(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x020F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_PKT_ARRV(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_TRAN(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x030F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_TRAN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_OUTER_IPID(v1) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x040F | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_OUTER_IPID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_UDP_PTRN(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x050F | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_UDP_PTRN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_TCP_PTRN(v1, v2, v3, v4) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x060F | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_C_TCP_PTRN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_RTP_PTRN(v1, v2, v3) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x070F | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_C_RTP_PTRN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_ROHCV1_PT(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x080F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_ROHCV1_PT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_PTRN_SEQ(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x090F | ((unsigned short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_PTRN_SEQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_ROHCV2_PT(v1) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0A0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_ROHCV2_PT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_PKT_ARRV(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0B0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_PKT_ARRV(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_INNER_IPID(v1) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0C0F | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_INNER_IPID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_MODE_TRAN(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0D0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_MODE_TRAN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_OUTER_IPID(v1) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0E0F | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_OUTER_IPID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_INNER_IPID_TS(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0F0F | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_INNER_IPID_TS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_MSN_PT(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x100F | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_MSN_PT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_DELTA_MSN(v1) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x110F | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_DELTA_MSN(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_MSN_DELTA_PT(v1, v2, v3) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x120F | ((unsigned short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_D_MSN_DELTA_PT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_MSN_PT_INNER_IPID(v1, v2, v3) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x130F | ((unsigned short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_D_MSN_PT_INNER_IPID(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_SEQ_ACK(v1, v2, v3) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x140F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_D_SEQ_ACK(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_PTRN_SEQ_TICK(v1, v2, v3) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x150F | ((unsigned short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_D_PTRN_SEQ_TICK(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_PT_INNER_IPID(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x160F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_PT_INNER_IPID(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_MSN_SEQ_ACK(v1, v2, v3) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x170F | ((unsigned short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_D_MSN_SEQ_ACK(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_MSN_RECOVERY(v1, v2, v3, v4) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x180F | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_D_MSN_RECOVERY(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_FAIL_NO_RETRY(v1) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x190F | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_FAIL_NO_RETRY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_FAIL_TS_RETRY(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1A0F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_FAIL_TS_RETRY(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_UPDT_RTP_TS_STRIDE(v1, v2, v3) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x1B0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_D_UPDT_RTP_TS_STRIDE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_WEIRD_TS_STRIDE(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1C0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_WEIRD_TS_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CHECK_TS_STRIDE(v1, v2, v3) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x1D0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_D_CHECK_TS_STRIDE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CNTXT_MATCH(v1, v2, v3) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x1E0F | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_D_CNTXT_MATCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CNTXT_NO_MATCH(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1F0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_CNTXT_NO_MATCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_RET(v1) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x200F | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_RET(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_DUMP_LEN(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x210F | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ROHC_LOG_C_DUMP_LEN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_DUMP(v1, v2, v3, v4, v5) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_5_word(0x220F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define ROHC_LOG_C_DUMP(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_DUMP_LEN(v1, v2) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x230F | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ROHC_LOG_D_DUMP_LEN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_DUMP(v1, v2, v3, v4, v5) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_5_word(0x240F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define ROHC_LOG_D_DUMP(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_ENFORCE_IR_PT(v1) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x250F | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_ENFORCE_IR_PT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_ENFORCE_IR_PT_COUNT(v1) do {\
		if(ROHC_DETAIL_Trace_Filter[0]==1 && (ROHC_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x260F | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_ENFORCE_IR_PT_COUNT(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char ROHC_DETAIL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_ROHC_LOG_C_IP_PTRN(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_C_CNTXT_MATCH(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_C_PKT_ARRV(short v1, long v2);
void L1TRC_Send_ROHC_LOG_C_MODE_TRAN(short v1, long v2);
void L1TRC_Send_ROHC_LOG_C_OUTER_IPID(unsigned short v1);
void L1TRC_Send_ROHC_LOG_C_UDP_PTRN(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_C_TCP_PTRN(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ROHC_LOG_C_RTP_PTRN(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_ROHC_LOG_C_ROHCV1_PT(short v1, long v2);
void L1TRC_Send_ROHC_LOG_C_PTRN_SEQ(unsigned short v1, long v2);
void L1TRC_Send_ROHC_LOG_C_ROHCV2_PT(short v1);
void L1TRC_Send_ROHC_LOG_D_PKT_ARRV(short v1, long v2);
void L1TRC_Send_ROHC_LOG_D_INNER_IPID(unsigned short v1);
void L1TRC_Send_ROHC_LOG_D_MODE_TRAN(short v1, long v2);
void L1TRC_Send_ROHC_LOG_D_OUTER_IPID(unsigned short v1);
void L1TRC_Send_ROHC_LOG_D_INNER_IPID_TS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_D_MSN_PT(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_D_DELTA_MSN(short v1);
void L1TRC_Send_ROHC_LOG_D_MSN_DELTA_PT(unsigned short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_D_MSN_PT_INNER_IPID(unsigned short v1, long v2, unsigned long v3);
void L1TRC_Send_ROHC_LOG_D_SEQ_ACK(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_ROHC_LOG_D_PTRN_SEQ_TICK(unsigned short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_D_PT_INNER_IPID(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_D_MSN_SEQ_ACK(unsigned short v1, long v2, unsigned long v3);
void L1TRC_Send_ROHC_LOG_D_MSN_RECOVERY(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ROHC_LOG_D_CRC_FAIL_NO_RETRY(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC_FAIL_TS_RETRY(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_D_UPDT_RTP_TS_STRIDE(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_D_WEIRD_TS_STRIDE(short v1, long v2);
void L1TRC_Send_ROHC_LOG_D_CHECK_TS_STRIDE(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_D_CNTXT_MATCH(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_D_CNTXT_NO_MATCH(short v1, long v2);
void L1TRC_Send_ROHC_LOG_D_RET(short v1);
void L1TRC_Send_ROHC_LOG_C_DUMP_LEN(short v1, short v2);
void L1TRC_Send_ROHC_LOG_C_DUMP(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_ROHC_LOG_D_DUMP_LEN(short v1, short v2);
void L1TRC_Send_ROHC_LOG_D_DUMP(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_ROHC_LOG_C_ENFORCE_IR_PT(short v1);
void L1TRC_Send_ROHC_LOG_C_ENFORCE_IR_PT_COUNT(short v1);

void Set_ROHC_DETAIL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_ROHC_DETAIL()	(ROHC_DETAIL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_ROHC_DETAIL_ROHC_FUNC()	(ChkL1ModFltr_ROHC_DETAIL()&&((ROHC_DETAIL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_ROHC_DETAIL_ROHC_BRANCH()	(ChkL1ModFltr_ROHC_DETAIL()&&((ROHC_DETAIL_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()	(ChkL1ModFltr_ROHC_DETAIL()&&((ROHC_DETAIL_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_ROHC_DETAIL_ROHC_DUMP()	(ChkL1ModFltr_ROHC_DETAIL()&&((ROHC_DETAIL_Trace_Filter[1]&0x08)!=0))
#define ChkL1MsgFltr_ROHC_LOG_C_IP_PTRN()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_MATCH()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_PKT_ARRV()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_MODE_TRAN()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_OUTER_IPID()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_UDP_PTRN()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_TCP_PTRN()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_RTP_PTRN()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_ROHCV1_PT()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_PTRN_SEQ()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_ROHCV2_PT()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_PKT_ARRV()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_INNER_IPID()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_MODE_TRAN()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_OUTER_IPID()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_INNER_IPID_TS()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_MSN_PT()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_DELTA_MSN()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_MSN_DELTA_PT()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_MSN_PT_INNER_IPID()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_SEQ_ACK()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_PTRN_SEQ_TICK()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_PT_INNER_IPID()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_MSN_SEQ_ACK()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_MSN_RECOVERY()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC_FAIL_NO_RETRY()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC_FAIL_TS_RETRY()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_UPDT_RTP_TS_STRIDE()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_WEIRD_TS_STRIDE()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_CHECK_TS_STRIDE()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_CNTXT_MATCH()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_CNTXT_NO_MATCH()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_D_RET()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_DUMP_LEN()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_DUMP()
#define ChkL1MsgFltr_ROHC_LOG_C_DUMP()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_DUMP()
#define ChkL1MsgFltr_ROHC_LOG_D_DUMP_LEN()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_DUMP()
#define ChkL1MsgFltr_ROHC_LOG_D_DUMP()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_DUMP()
#define ChkL1MsgFltr_ROHC_LOG_C_ENFORCE_IR_PT()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()
#define ChkL1MsgFltr_ROHC_LOG_C_ENFORCE_IR_PT_COUNT()	ChkL1ClsFltr_ROHC_DETAIL_ROHC_PACKET()


#endif
