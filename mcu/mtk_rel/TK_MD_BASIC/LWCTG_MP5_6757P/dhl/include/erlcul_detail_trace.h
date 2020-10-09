#ifndef L1TRC_ERLCUL_DETAIL_DEF_H
#define L1TRC_ERLCUL_DETAIL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_SIT_REL(v1, v2, v3) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x0004 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_UL_SIT_REL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_PDU_REL(v1, v2) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0104 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_PDU_REL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_BSR_REDUCE(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0204 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_BSR_REDUCE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_TRG_SDU_SEG(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0304 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_TRG_SDU_SEG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_TRG_AMD_RESEG(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0404 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_TRG_AMD_RESEG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_SDU_1(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0504 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SRV_SDU_1(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_SDU_2(v1, v2) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0604 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_SRV_SDU_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_SDU_3(v1, v2, v3) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0704 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SRV_SDU_3(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_SDU_4(v1, v2, v3, v4) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x0804 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_SRV_SDU_4(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_SDU(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0904 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SRV_SDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_SDU_BY_SEG(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0A04 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SRV_SDU_BY_SEG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_SDU_NO_GRANT(v1, v2, v3) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0B04 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SRV_SDU_NO_GRANT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_RETX_PDU_NO_GRANT(v1, v2, v3) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0C04 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SRV_RETX_PDU_NO_GRANT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRV_RETX_SEG_NO_GRANT(v1, v2, v3, v4) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x0D04 | ((short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((short)(v4))) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_SRV_RETX_SEG_NO_GRANT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RESRV_PST(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0E04 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_RESRV_PST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_WRITE_PST(v1, v2) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0F04 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_UL_WRITE_PST(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_CLEAR_PST(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1004 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_CLEAR_PST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_WRITE_PST_FAIL(v1, v2) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1104 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_UL_WRITE_PST_FAIL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_CLEAR_PST_FAIL(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1204 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_CLEAR_PST_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RAW_1_BYTE(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x1304 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_RAW_1_BYTE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RAW_2_BYTE(v1, v2) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x1404 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_RAW_2_BYTE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RAW_3_BYTE(v1, v2, v3) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1504 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24), (kal_uint32)((unsigned char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_RAW_3_BYTE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RAW_4_BYTE(v1) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1604 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1));\
	} while(0)
#else
	#define ERLC_LOG_UL_RAW_4_BYTE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RAW_8_BYTE(v1, v2) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x1704 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_UL_RAW_8_BYTE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RAW_12_BYTE(v1, v2, v3) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x1804 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_UL_RAW_12_BYTE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RAW_16_BYTE(v1, v2, v3, v4) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_5_word(0x1904 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_UL_RAW_16_BYTE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_SIT_ENTRY(v1, v2) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1A04 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_SIT_ENTRY(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_UPD_RLC_DSC(v1, v2) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x1B04 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_UL_UPD_RLC_DSC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_UPD_RLC_HDR(v1, v2, v3, v4) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1C04 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24), (kal_uint32)((unsigned char)(v3)) | (((kal_uint32)((unsigned char)(v4))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_UPD_RLC_HDR(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_UPD_MAC_SUB_HDR(v1, v2, v3) do {\
		if(ERLCUL_DETAIL_Trace_Filter[0]==1 && (ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x1D04 | (((kal_uint32)((unsigned char)(v1))) << 16) | (((kal_uint32)((unsigned char)(v2))) << 24), (kal_uint32)((unsigned char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERLC_LOG_UL_UPD_MAC_SUB_HDR(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char ERLCUL_DETAIL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_ERLC_LOG_UL_SIT_REL(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_ERLC_LOG_UL_PDU_REL(short v1, short v2);
void L1TRC_Send_ERLC_LOG_BSR_REDUCE(short v1);
void L1TRC_Send_ERLC_LOG_TRG_SDU_SEG(short v1);
void L1TRC_Send_ERLC_LOG_TRG_AMD_RESEG(short v1);
void L1TRC_Send_ERLC_LOG_SRV_SDU_1(short v1);
void L1TRC_Send_ERLC_LOG_SRV_SDU_2(short v1, short v2);
void L1TRC_Send_ERLC_LOG_SRV_SDU_3(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_SRV_SDU_4(short v1, short v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_SRV_SDU(short v1);
void L1TRC_Send_ERLC_LOG_SRV_SDU_BY_SEG(short v1);
void L1TRC_Send_ERLC_LOG_SRV_SDU_NO_GRANT(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_SRV_RETX_PDU_NO_GRANT(short v1, short v2, short v3);
void L1TRC_Send_ERLC_LOG_SRV_RETX_SEG_NO_GRANT(short v1, unsigned long v2, short v3, short v4);
void L1TRC_Send_ERLC_LOG_UL_RESRV_PST(short v1);
void L1TRC_Send_ERLC_LOG_UL_WRITE_PST(short v1, long v2);
void L1TRC_Send_ERLC_LOG_UL_CLEAR_PST(short v1);
void L1TRC_Send_ERLC_LOG_UL_WRITE_PST_FAIL(short v1, long v2);
void L1TRC_Send_ERLC_LOG_UL_CLEAR_PST_FAIL(short v1);
void L1TRC_Send_ERLC_LOG_UL_RAW_1_BYTE(unsigned char v1);
void L1TRC_Send_ERLC_LOG_UL_RAW_2_BYTE(unsigned char v1, unsigned char v2);
void L1TRC_Send_ERLC_LOG_UL_RAW_3_BYTE(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_ERLC_LOG_UL_RAW_4_BYTE(unsigned long v1);
void L1TRC_Send_ERLC_LOG_UL_RAW_8_BYTE(unsigned long v1, unsigned long v2);
void L1TRC_Send_ERLC_LOG_UL_RAW_12_BYTE(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_ERLC_LOG_UL_RAW_16_BYTE(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ERLC_LOG_UL_SIT_ENTRY(short v1, short v2);
void L1TRC_Send_ERLC_LOG_UL_UPD_RLC_DSC(unsigned long v1, unsigned long v2);
void L1TRC_Send_ERLC_LOG_UL_UPD_RLC_HDR(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_ERLC_LOG_UL_UPD_MAC_SUB_HDR(unsigned char v1, unsigned char v2, unsigned char v3);

void Set_ERLCUL_DETAIL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_ERLCUL_DETAIL()	(ERLCUL_DETAIL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_FUNC()	(ChkL1ModFltr_ERLCUL_DETAIL()&&((ERLCUL_DETAIL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_BRANCH()	(ChkL1ModFltr_ERLCUL_DETAIL()&&((ERLCUL_DETAIL_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()	(ChkL1ModFltr_ERLCUL_DETAIL()&&((ERLCUL_DETAIL_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_ERLC_LOG_UL_SIT_REL()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_PDU_REL()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_BSR_REDUCE()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_TRG_SDU_SEG()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_TRG_AMD_RESEG()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_SRV_SDU_1()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_SRV_SDU_2()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_SRV_SDU_3()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_SRV_SDU_4()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_SRV_SDU()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_SRV_SDU_BY_SEG()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_SRV_SDU_NO_GRANT()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_SRV_RETX_PDU_NO_GRANT()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_SRV_RETX_SEG_NO_GRANT()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_RESRV_PST()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_FUNC()
#define ChkL1MsgFltr_ERLC_LOG_UL_WRITE_PST()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_FUNC()
#define ChkL1MsgFltr_ERLC_LOG_UL_CLEAR_PST()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_FUNC()
#define ChkL1MsgFltr_ERLC_LOG_UL_WRITE_PST_FAIL()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_FUNC()
#define ChkL1MsgFltr_ERLC_LOG_UL_CLEAR_PST_FAIL()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_FUNC()
#define ChkL1MsgFltr_ERLC_LOG_UL_RAW_1_BYTE()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_RAW_2_BYTE()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_RAW_3_BYTE()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_RAW_4_BYTE()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_RAW_8_BYTE()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_RAW_12_BYTE()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_RAW_16_BYTE()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_SIT_ENTRY()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_UPD_RLC_DSC()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_UPD_RLC_HDR()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()
#define ChkL1MsgFltr_ERLC_LOG_UL_UPD_MAC_SUB_HDR()	ChkL1ClsFltr_ERLCUL_DETAIL_ERLCUL_PACKET()


#endif
