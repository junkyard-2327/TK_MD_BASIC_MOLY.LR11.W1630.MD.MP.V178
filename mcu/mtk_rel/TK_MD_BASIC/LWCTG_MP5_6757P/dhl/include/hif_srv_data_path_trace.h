#ifndef L1TRC_HIF_SRV_DEF_H
#define L1TRC_HIF_SRV_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HIF_SRV_DUMMY(v1) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0014 | ((short)(v1) << 16));\
	} while(0)
#else
	#define HIF_SRV_DUMMY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HMU_DATA_EVENT_TRIGGER(v1, v2, v3, v4) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x0114 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define HMU_DATA_EVENT_TRIGGER(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HMU_DATA_EVENT_TRIGGER_TIMEOUT_WARNING(v1, v2, v3, v4) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x0214 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define HMU_DATA_EVENT_TRIGGER_TIMEOUT_WARNING(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HMU_DATA_EVENT_TRIGGER_TIMEOUT_ERROR(v1, v2, v3, v4) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x0314 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define HMU_DATA_EVENT_TRIGGER_TIMEOUT_ERROR(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HMU_HIFEG_STOP(v1, v2, v3) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0414 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define HMU_HIFEG_STOP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HMU_HIFEG_START(v1, v2, v3) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0514 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define HMU_HIFEG_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HMU_CHANGE_TIMER_DSP() do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x0614 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define HMU_CHANGE_TIMER_DSP()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HMU_CHANGE_TIMER_GPT() do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x0714 | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define HMU_CHANGE_TIMER_GPT()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_WRITE_DATA_TRACE(v1, v2, v3, v4) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x0814 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define CCCI_WRITE_DATA_TRACE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_WRITE_GPD_RET_DATA_TRACE(v1, v2, v3, v4) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x0914 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define CCCI_WRITE_GPD_RET_DATA_TRACE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_WRITE_GPD_CONTROL_PATH_TRACE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x40)!=0 )\
			l2trc_send_7_word(0x0A14 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define CCCI_WRITE_GPD_CONTROL_PATH_TRACE(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_WRITE_GPD_DATA_PATH_TRACE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_7_word(0x0B14 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define CCCI_WRITE_GPD_DATA_PATH_TRACE(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_RELOAD_GPD_TRACE(v1, v2, v3, v4) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x80)!=0 )\
			l2trc_send_4_word(0x0C14 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define CCCI_RELOAD_GPD_TRACE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_ULIOR_CB_DATA_TRACE(v1, v2, v3, v4, v5, v6) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x80)!=0 )\
			l2trc_send_6_word(0x0D14 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define CCCI_ULIOR_CB_DATA_TRACE(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_ULBUFF_CB_DATA_TRACE(v1, v2, v3, v4, v5, v6) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[1]&0x80)!=0 )\
			l2trc_send_6_word(0x0E14 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define CCCI_ULBUFF_CB_DATA_TRACE(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_DATA_DUMP_TRACE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[2]&0x01)!=0 )\
			l2trc_send_7_word(0x0F14 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define CCCI_DATA_DUMP_TRACE(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_IMS_DATA_DUMP_TRACE(v1, v2, v3, v4, v5, v6) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[2]&0x02)!=0 )\
			l2trc_send_6_word(0x1014 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define CCCI_IMS_DATA_DUMP_TRACE(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_IMS_UL_LATENCY(v1, v2, v3, v4, v5, v6) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[2]&0x02)!=0 )\
			l2trc_send_6_word(0x1114 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define CCCI_IMS_UL_LATENCY(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_IMS_DL_LATENCY(v1, v2, v3, v4, v5) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[2]&0x02)!=0 )\
			l2trc_send_5_word(0x1214 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define CCCI_IMS_DL_LATENCY(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_FS_DATA_DUMP_TRACE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[2]&0x04)!=0 )\
			l2trc_send_7_word(0x1314 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define CCCI_FS_DATA_DUMP_TRACE(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_DEBUG_ADD_SEQ_TRACE(v1, v2, v3, v4, v5, v6) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[2]&0x08)!=0 )\
			l2trc_send_6_word(0x1414 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define CCCI_DEBUG_ADD_SEQ_TRACE(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCI_DEBUG_CHECK_SEQ_TRACE(v1, v2, v3, v4, v5, v6) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[2]&0x08)!=0 )\
			l2trc_send_6_word(0x1514 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define CCCI_DEBUG_CHECK_SEQ_TRACE(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HLT_OVER_BOUND_TRACE(v1, v2, v3, v4, v5, v6) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[2]&0x10)!=0 )\
			l2trc_send_6_word(0x1614 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define HLT_OVER_BOUND_TRACE(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HLT_OVER_BOUND_AVG_TRACE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(HIF_SRV_Trace_Filter[0]==1 && (HIF_SRV_Trace_Filter[2]&0x10)!=0 )\
			l2trc_send_7_word(0x1714 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define HLT_OVER_BOUND_AVG_TRACE(v1, v2, v3, v4, v5, v6, v7)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char HIF_SRV_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_HIF_SRV_DUMMY(short v1);
void L1TRC_Send_HMU_DATA_EVENT_TRIGGER(short v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_HMU_DATA_EVENT_TRIGGER_TIMEOUT_WARNING(short v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_HMU_DATA_EVENT_TRIGGER_TIMEOUT_ERROR(short v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_HMU_HIFEG_STOP(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_HMU_HIFEG_START(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_HMU_CHANGE_TIMER_DSP(void);
void L1TRC_Send_HMU_CHANGE_TIMER_GPT(void);
void L1TRC_Send_CCCI_WRITE_DATA_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_CCCI_WRITE_GPD_RET_DATA_TRACE(short v1, long v2, long v3, long v4);
void L1TRC_Send_CCCI_WRITE_GPD_CONTROL_PATH_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_CCCI_WRITE_GPD_DATA_PATH_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_CCCI_RELOAD_GPD_TRACE(short v1, long v2, long v3, long v4);
void L1TRC_Send_CCCI_ULIOR_CB_DATA_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_CCCI_ULBUFF_CB_DATA_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_CCCI_DATA_DUMP_TRACE(short v1, unsigned long v2, long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_CCCI_IMS_DATA_DUMP_TRACE(short v1, long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_CCCI_IMS_UL_LATENCY(short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_CCCI_IMS_DL_LATENCY(short v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_CCCI_FS_DATA_DUMP_TRACE(short v1, unsigned long v2, long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_CCCI_DEBUG_ADD_SEQ_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_CCCI_DEBUG_CHECK_SEQ_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_HLT_OVER_BOUND_TRACE(short v1, char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_HLT_OVER_BOUND_AVG_TRACE(short v1, char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);

void Set_HIF_SRV_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_HIF_SRV()	(HIF_SRV_Trace_Filter[0]==1)
#define ChkL1ClsFltr_HIF_SRV_UL()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_HIF_SRV_DL()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_HIF_SRV_HMU()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_HIF_SRV_HMU_HIF()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_HIF_SRV_CCCI_DL()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_HIF_SRV_CCCI_DL_DATA()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_HIF_SRV_CCCI_DL_CONTROL()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_HIF_SRV_CCCI_UL()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_HIF_SRV_CCCI_DUMP()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_HIF_SRV_CCCI_IMS_DUMP()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_HIF_SRV_CCCI_FS_DUMP()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_HIF_SRV_CCCI_DEBUG_SEQ()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_HIF_SRV_HLT()	(ChkL1ModFltr_HIF_SRV()&&((HIF_SRV_Trace_Filter[2]&0x10)!=0))
#define ChkL1MsgFltr_HIF_SRV_DUMMY()	ChkL1ClsFltr_HIF_SRV_UL()
#define ChkL1MsgFltr_HMU_DATA_EVENT_TRIGGER()	ChkL1ClsFltr_HIF_SRV_HMU()
#define ChkL1MsgFltr_HMU_DATA_EVENT_TRIGGER_TIMEOUT_WARNING()	ChkL1ClsFltr_HIF_SRV_HMU()
#define ChkL1MsgFltr_HMU_DATA_EVENT_TRIGGER_TIMEOUT_ERROR()	ChkL1ClsFltr_HIF_SRV_HMU()
#define ChkL1MsgFltr_HMU_HIFEG_STOP()	ChkL1ClsFltr_HIF_SRV_HMU_HIF()
#define ChkL1MsgFltr_HMU_HIFEG_START()	ChkL1ClsFltr_HIF_SRV_HMU_HIF()
#define ChkL1MsgFltr_HMU_CHANGE_TIMER_DSP()	ChkL1ClsFltr_HIF_SRV_HMU_HIF()
#define ChkL1MsgFltr_HMU_CHANGE_TIMER_GPT()	ChkL1ClsFltr_HIF_SRV_HMU_HIF()
#define ChkL1MsgFltr_CCCI_WRITE_DATA_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_DL()
#define ChkL1MsgFltr_CCCI_WRITE_GPD_RET_DATA_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_DL()
#define ChkL1MsgFltr_CCCI_WRITE_GPD_CONTROL_PATH_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_DL_CONTROL()
#define ChkL1MsgFltr_CCCI_WRITE_GPD_DATA_PATH_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_DL_DATA()
#define ChkL1MsgFltr_CCCI_RELOAD_GPD_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_UL()
#define ChkL1MsgFltr_CCCI_ULIOR_CB_DATA_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_UL()
#define ChkL1MsgFltr_CCCI_ULBUFF_CB_DATA_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_UL()
#define ChkL1MsgFltr_CCCI_DATA_DUMP_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_DUMP()
#define ChkL1MsgFltr_CCCI_IMS_DATA_DUMP_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_IMS_DUMP()
#define ChkL1MsgFltr_CCCI_IMS_UL_LATENCY()	ChkL1ClsFltr_HIF_SRV_CCCI_IMS_DUMP()
#define ChkL1MsgFltr_CCCI_IMS_DL_LATENCY()	ChkL1ClsFltr_HIF_SRV_CCCI_IMS_DUMP()
#define ChkL1MsgFltr_CCCI_FS_DATA_DUMP_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_FS_DUMP()
#define ChkL1MsgFltr_CCCI_DEBUG_ADD_SEQ_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_DEBUG_SEQ()
#define ChkL1MsgFltr_CCCI_DEBUG_CHECK_SEQ_TRACE()	ChkL1ClsFltr_HIF_SRV_CCCI_DEBUG_SEQ()
#define ChkL1MsgFltr_HLT_OVER_BOUND_TRACE()	ChkL1ClsFltr_HIF_SRV_HLT()
#define ChkL1MsgFltr_HLT_OVER_BOUND_AVG_TRACE()	ChkL1ClsFltr_HIF_SRV_HLT()


#endif
