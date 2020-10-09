#ifndef L1TRC_EDATA_PATH_DETAIL_DEF_H
#define L1TRC_EDATA_PATH_DETAIL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_ERT_HISR_IN(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0002 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (unsigned long)(v4));\
	} while(0)
#else
	#define ILM_ERT_HISR_IN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_ERT_HISR_DSP_TIMER(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0102 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((short)(v4))) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ILM_ERT_HISR_DSP_TIMER(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_IN(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0202 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define ILM_IN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_OUT(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0302 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ILM_OUT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERT_ILM_IN(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0402 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define ERT_ILM_IN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERT_ILM_OUT(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0502 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ERT_ILM_OUT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERT_ILM_OUT_2(v1, v2) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0602 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ERT_ILM_OUT_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ENTER_DSP_TIMER_HISR_IN(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0702 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define ENTER_DSP_TIMER_HISR_IN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ENTER_DSP_TIMER_HISR_IN_2(v1, v2) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0802 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ENTER_DSP_TIMER_HISR_IN_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define POLL_CYCLES(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0902 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define POLL_CYCLES(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ENTER_DSP_TIMER_HISR_OUT(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0A02 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ENTER_DSP_TIMER_HISR_OUT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ENTER_DSP_TIMER_HISR_OUT_2(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0B02 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ENTER_DSP_TIMER_HISR_OUT_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PROTECT(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0C02 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define PROTECT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_PROCESS_EPSB_DL_CYCLES(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x0D02 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define LTM_PROCESS_EPSB_DL_CYCLES(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_PROCESS_UL_SDU(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x0E02 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define LTM_PROCESS_UL_SDU(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_RCV_UL(v1, v2) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0F02 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_RCV_UL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TRC_WPR_TIMEOUT_INVALID(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1002 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TRC_WPR_TIMEOUT_INVALID(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TRC_WPR_PROC_ES_INSTR(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1102 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define TRC_WPR_PROC_ES_INSTR(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TRC_WPR_ES_CANCEL_EVENT(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1202 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TRC_WPR_ES_CANCEL_EVENT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TRC_WPR_ES_SET_EVENT(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1302 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TRC_WPR_ES_SET_EVENT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TRC_WPR_PROC_ILM_INSTR(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1402 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define TRC_WPR_PROC_ILM_INSTR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TRC_WPR_MSG_SEND(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1502 | ((short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define TRC_WPR_MSG_SEND(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TRC_WPR_GET_DATA_BUFF(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1602 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define TRC_WPR_GET_DATA_BUFF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TRC_WPR_FREE_DATA_BUFF(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1702 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define TRC_WPR_FREE_DATA_BUFF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_ERT_HISR_IN_WO_TIME(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1802 | ((unsigned short)(v1) << 16), (kal_uint32)((unsigned short)(v2)) | (((kal_uint32)((short)(v3))) << 16));\
	} while(0)
#else
	#define ILM_ERT_HISR_IN_WO_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_OUT_WO_TIME(v1, v2) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1902 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ILM_OUT_WO_TIME(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_IN_WO_TIME(v1, v2) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1A02 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ILM_IN_WO_TIME(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERT_ILM_IN_WO_TIME(v1, v2) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1B02 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define ERT_ILM_IN_WO_TIME(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERT_ILM_OUT_2_WO_TIME(v1) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x1C02 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ERT_ILM_OUT_2_WO_TIME(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ENTER_DSP_TIMER_HISR_IN_2_WO_TIME(v1) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1D02 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ENTER_DSP_TIMER_HISR_IN_2_WO_TIME(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ENTER_DSP_TIMER_HISR_OUT_2_WO_TIME(v1) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x1E02 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ENTER_DSP_TIMER_HISR_OUT_2_WO_TIME(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EDYN_LOG_COPRO_PWR_DWN_MPIF_ACTIVE() do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x1F02 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EDYN_LOG_COPRO_PWR_DWN_MPIF_ACTIVE()
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EDATA_PATH_DETAIL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_ILM_ERT_HISR_IN(unsigned short v1, unsigned short v2, short v3, unsigned long v4);
void L1TRC_Send_ILM_ERT_HISR_DSP_TIMER(unsigned short v1, unsigned long v2, short v3, short v4);
void L1TRC_Send_ILM_IN(unsigned short v1, short v2, unsigned long v3);
void L1TRC_Send_ILM_OUT(unsigned short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ERT_ILM_IN(unsigned short v1, short v2, unsigned long v3);
void L1TRC_Send_ERT_ILM_OUT(unsigned short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ERT_ILM_OUT_2(unsigned short v1, unsigned long v2);
void L1TRC_Send_ENTER_DSP_TIMER_HISR_IN(short v1, char v2, unsigned long v3);
void L1TRC_Send_ENTER_DSP_TIMER_HISR_IN_2(unsigned short v1, unsigned long v2);
void L1TRC_Send_POLL_CYCLES(unsigned short v1, char v2, unsigned long v3);
void L1TRC_Send_ENTER_DSP_TIMER_HISR_OUT(short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ENTER_DSP_TIMER_HISR_OUT_2(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PROTECT(short v1, char v2, char v3);
void L1TRC_Send_LTM_PROCESS_EPSB_DL_CYCLES(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_LTM_PROCESS_UL_SDU(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_LTM_RCV_UL(short v1, char v2);
void L1TRC_Send_TRC_WPR_TIMEOUT_INVALID(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_TRC_WPR_PROC_ES_INSTR(short v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_TRC_WPR_ES_CANCEL_EVENT(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_TRC_WPR_ES_SET_EVENT(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_TRC_WPR_PROC_ILM_INSTR(short v1, short v2, long v3);
void L1TRC_Send_TRC_WPR_MSG_SEND(short v1, long v2, short v3, long v4);
void L1TRC_Send_TRC_WPR_GET_DATA_BUFF(short v1, long v2, long v3);
void L1TRC_Send_TRC_WPR_FREE_DATA_BUFF(short v1, long v2, long v3);
void L1TRC_Send_ILM_ERT_HISR_IN_WO_TIME(unsigned short v1, unsigned short v2, short v3);
void L1TRC_Send_ILM_OUT_WO_TIME(unsigned short v1, short v2);
void L1TRC_Send_ILM_IN_WO_TIME(unsigned short v1, short v2);
void L1TRC_Send_ERT_ILM_IN_WO_TIME(unsigned short v1, short v2);
void L1TRC_Send_ERT_ILM_OUT_2_WO_TIME(unsigned short v1);
void L1TRC_Send_ENTER_DSP_TIMER_HISR_IN_2_WO_TIME(unsigned short v1);
void L1TRC_Send_ENTER_DSP_TIMER_HISR_OUT_2_WO_TIME(unsigned short v1);
void L1TRC_Send_EDYN_LOG_COPRO_PWR_DWN_MPIF_ACTIVE(void);

void Set_EDATA_PATH_DETAIL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EDATA_PATH_DETAIL()	(EDATA_PATH_DETAIL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()	(ChkL1ModFltr_EDATA_PATH_DETAIL()&&((EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()	(ChkL1ModFltr_EDATA_PATH_DETAIL()&&((EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EDATA_PATH_DETAIL_LTM_DFT()	(ChkL1ModFltr_EDATA_PATH_DETAIL()&&((EDATA_PATH_DETAIL_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_ILM_ERT_HISR_IN()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ILM_ERT_HISR_DSP_TIMER()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ILM_IN()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ILM_OUT()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ERT_ILM_IN()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_ERT_ILM_OUT()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_ERT_ILM_OUT_2()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_ENTER_DSP_TIMER_HISR_IN()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ENTER_DSP_TIMER_HISR_IN_2()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_POLL_CYCLES()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ENTER_DSP_TIMER_HISR_OUT()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_ENTER_DSP_TIMER_HISR_OUT_2()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_PROTECT()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_LTM_PROCESS_EPSB_DL_CYCLES()	ChkL1ClsFltr_EDATA_PATH_DETAIL_LTM_DFT()
#define ChkL1MsgFltr_LTM_PROCESS_UL_SDU()	ChkL1ClsFltr_EDATA_PATH_DETAIL_LTM_DFT()
#define ChkL1MsgFltr_LTM_RCV_UL()	ChkL1ClsFltr_EDATA_PATH_DETAIL_LTM_DFT()
#define ChkL1MsgFltr_TRC_WPR_TIMEOUT_INVALID()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_TRC_WPR_PROC_ES_INSTR()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_TRC_WPR_ES_CANCEL_EVENT()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_TRC_WPR_ES_SET_EVENT()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_TRC_WPR_PROC_ILM_INSTR()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_TRC_WPR_MSG_SEND()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_TRC_WPR_GET_DATA_BUFF()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_TRC_WPR_FREE_DATA_BUFF()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ILM_ERT_HISR_IN_WO_TIME()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ILM_OUT_WO_TIME()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ILM_IN_WO_TIME()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ERT_ILM_IN_WO_TIME()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_ERT_ILM_OUT_2_WO_TIME()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_ENTER_DSP_TIMER_HISR_IN_2_WO_TIME()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ENTER_DSP_TIMER_HISR_OUT_2_WO_TIME()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_EDYN_LOG_COPRO_PWR_DWN_MPIF_ACTIVE()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()


#endif
