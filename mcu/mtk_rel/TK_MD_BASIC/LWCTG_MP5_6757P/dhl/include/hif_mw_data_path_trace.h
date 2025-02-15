#ifndef L1TRC_HIF_MW_DEF_H
#define L1TRC_HIF_MW_DEF_H

/******************************/
/* String category definition */
/******************************/
#define IPC_IP_TYPE(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_UPLINK_CALLBACK(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0013 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_UPLINK_CALLBACK(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_DEQUEUE_UPLINK_PRIORITY_QUEUE(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0113 | ((short)(v1) << 16), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_DEQUEUE_UPLINK_PRIORITY_QUEUE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_DEQUEUE_UPLINK_QUEUE(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0213 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_UL_DEQUEUE_UPLINK_QUEUE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_ON_PROCESS_NORMAL_IOR(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x04)!=0 )\
			l2trc_send_3_word(0x0313 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_UL_ON_PROCESS_NORMAL_IOR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_THROTTLE_IMS_EMERGEMCY_IND(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0413 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define IPC_UL_THROTTLE_IMS_EMERGEMCY_IND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_TR_TIMER_UL_THROTTLE_TIMEOUT(v1, v2, v3, v4, v5) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_5_word(0x0513 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define IPC_TR_TIMER_UL_THROTTLE_TIMEOUT(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_TR_START_UL_THROTTLE_TIMER(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0613 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define IPC_TR_START_UL_THROTTLE_TIMER(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_RELOAD_UPLINK(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x04)!=0 )\
			l2trc_send_4_word(0x0713 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_RELOAD_UPLINK(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_RELOAD_UPLINK_RESULT(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0813 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define IPC_UL_RELOAD_UPLINK_RESULT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_RELOAD_RETRY(v1, v2, v3, v4, v5) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x04)!=0 )\
			l2trc_send_5_word(0x0913 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define IPC_UL_RELOAD_RETRY(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_RELOAD_RETRY_RACE_COND(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0A13 | ((short)(v1) << 16), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_RELOAD_RETRY_RACE_COND(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_RELOAD_RETRY_FLAG(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x04)!=0 )\
			l2trc_send_3_word(0x0B13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_UL_RELOAD_RETRY_FLAG(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_SET_NEED_RELOAD(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x04)!=0 )\
			l2trc_send_4_word(0x0C13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_SET_NEED_RELOAD(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_SET_NEED_RELOAD_FLAG(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x04)!=0 )\
			l2trc_send_2_word(0x0D13 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define IPC_UL_SET_NEED_RELOAD_FLAG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_ON_RETRY_RELOAD(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0E13 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define IPC_UL_ON_RETRY_RELOAD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_ON_RETRY_RELOAD_FOR_NETIF(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0F13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_UL_ON_RETRY_RELOAD_FOR_NETIF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_CHECK_UL_RELOAD_RETRY(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1013 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define IPC_UL_CHECK_UL_RELOAD_RETRY(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_DROP_UL_IOR(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1113 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_UL_DROP_UL_IOR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_LOOPBACK_UL_IOR(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1213 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_LOOPBACK_UL_IOR(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_LOOPBACK_UL_IOR_DROP(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1313 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_LOOPBACK_UL_IOR_DROP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_HANDLE_UL_GPD_LIST(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1413 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_HANDLE_UL_GPD_LIST(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_FORWARD_UL_SDU(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1513 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_FORWARD_UL_SDU(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_HANDLE_IPV4_UL_GPD_LIST(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x04)!=0 )\
			l2trc_send_4_word(0x1613 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_HANDLE_IPV4_UL_GPD_LIST(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_FORWARD_IPV4_UL_SDU(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1713 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_FORWARD_IPV4_UL_SDU(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_HANDLE_IPV6_UL_GPD_LIST(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1813 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_HANDLE_IPV6_UL_GPD_LIST(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_FORWARD_IPV6_UL_SDU(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1913 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_FORWARD_IPV6_UL_SDU(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_FORWARD_UL_SDU_MULTI_PS(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1A13 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define IPC_UL_FORWARD_UL_SDU_MULTI_PS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_FORWARD_UL_SDU_BY_EBI_MULTI_PS(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1B13 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define IPC_UL_FORWARD_UL_SDU_BY_EBI_MULTI_PS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_DHCP4C_PKT_SESSION(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1C13 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_DHCP4C_PKT_SESSION(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_DHCP4C_PKT_UPLINK(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1D13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_DHCP4C_PKT_UPLINK(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_SEND_PKT(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1E13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_UL_SEND_PKT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_SEND_PKT_BY_PDN(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1F13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_SEND_PKT_BY_PDN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_SEND_PKT_MULTI_PS(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2013 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define IPC_UL_SEND_PKT_MULTI_PS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_SEND_PKT_BY_PDN_MULTI_PS(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2113 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define IPC_UL_SEND_PKT_BY_PDN_MULTI_PS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_SEND_PKT_FORWARD(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2213 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_UL_SEND_PKT_FORWARD(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_UL_SEND_PKT_BY_PDN_FORWARD(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2313 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_UL_SEND_PKT_BY_PDN_FORWARD(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_DL_SEND_IPV4_PKT(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x2413 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_DL_SEND_IPV4_PKT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_DL_SEND_IPV6_PKT(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x2513 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_DL_SEND_IPV6_PKT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_DL_ON_DOWNLINK(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x2613 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_DL_ON_DOWNLINK(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_DL_ON_DOWNLINK_FILTER_OUT(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x2713 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_DL_ON_DOWNLINK_FILTER_OUT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_DL_ON_DOWNLINK_CALLBACK_INFO(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x08)!=0 )\
			l2trc_send_3_word(0x2813 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_DL_ON_DOWNLINK_CALLBACK_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_DL_ON_DOWNLINK_CALLBACK_GPD(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x2913 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_DL_ON_DOWNLINK_CALLBACK_GPD(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_DL_ON_DOWNLINK_MULTI_PS(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2A13 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define IPC_DL_ON_DOWNLINK_MULTI_PS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_DL_INVALID_LEN_CHK(v1, v2, v3, v4, v5) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_5_word(0x2B13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define IPC_DL_INVALID_LEN_CHK(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_DL_INVALID_LEN_PKT_IP_HDR(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2C13 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define IPC_DL_INVALID_LEN_PKT_IP_HDR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_FILTER_RULE_MATCHED(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x2D13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define IPC_GE_FILTER_RULE_MATCHED(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_SPD_ENTRY_IGR_INFO(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x2E13 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define IPC_GE_SPD_ENTRY_IGR_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_SPD_ALL_IGR_INFO(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x2F13 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define IPC_GE_SPD_ALL_IGR_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_DO_FILTER_GPD_UPDATE(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x3013 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define IPC_GE_DO_FILTER_GPD_UPDATE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_FILTER_OUT_INFO(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x3113 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_GE_FILTER_OUT_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_FILTER_OUT_GPD(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x3213 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define IPC_GE_FILTER_OUT_GPD(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_UNITE_FAIL_DROP(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x3313 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define IPC_GE_UNITE_FAIL_DROP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_UNITE_FAIL_DROP_INFO(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x3413 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define IPC_GE_UNITE_FAIL_DROP_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_HANDLE_GPD(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x3513 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define IPC_GE_HANDLE_GPD(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_SET_ALLOC_DATA(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x3613 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define IPC_GE_SET_ALLOC_DATA(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_FILL_HEADER(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x3713 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define IPC_GE_FILL_HEADER(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IPC_GE_UNITED_GPD(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x3813 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define IPC_GE_UNITED_GPD(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PFM_GE_DROP_PACKET_INFO(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x3913 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PFM_GE_DROP_PACKET_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PFM_GE_DROP_PACKET_DUMP(v1, v2, v3, v4, v5) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_5_word(0x3A13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PFM_GE_DROP_PACKET_DUMP(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_POLL_QUEUE_TX(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x3B13 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define USBCORE_POLL_QUEUE_TX(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_POLL_QUEUE_TX_NOTIFY_END(v1) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x3C13 | ((short)(v1) << 16));\
	} while(0)
#else
	#define USBCORE_POLL_QUEUE_TX_NOTIFY_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_POLL_QUEUE_RX(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x3D13 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define USBCORE_POLL_QUEUE_RX(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_POLL_QUEUE_RX_NOTIFY_END(v1) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x3E13 | ((short)(v1) << 16));\
	} while(0)
#else
	#define USBCORE_POLL_QUEUE_RX_NOTIFY_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_POLL_QUEUE_LEN_TX(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x3F13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define USBCORE_POLL_QUEUE_LEN_TX(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_POLL_QUEUE_LEN_RX(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x4013 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define USBCORE_POLL_QUEUE_LEN_RX(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_CLASS_SUBMIT_IO_REQUEST_HWQ(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x4113 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define USBCORE_CLASS_SUBMIT_IO_REQUEST_HWQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_CLASS_SUBMIT_IO_REQUEST_SWQ(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x4213 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define USBCORE_CLASS_SUBMIT_IO_REQUEST_SWQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_CLASS_FLUSH_HW_QUEUE(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x4313 | ((unsigned short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define USBCORE_CLASS_FLUSH_HW_QUEUE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_CLASS_FLUSH_SW_QUEUE(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x4413 | ((unsigned short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define USBCORE_CLASS_FLUSH_SW_QUEUE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_RESTORE_RX_GPD_SWQ2HWQ(v1) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x4513 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define USBCORE_RESTORE_RX_GPD_SWQ2HWQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define USBCORE_RESTORE_TX_GPD_SWQ2HWQ(v1) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x4613 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define USBCORE_RESTORE_TX_GPD_SWQ2HWQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_DATA_DUMP_TRACE(v1, v2, v3, v4, v5) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x01)!=0 )\
			l2trc_send_5_word(0x4713 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define CCMNI_DATA_DUMP_TRACE(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_DATA_DUMP_GPD_PTR(v1, v2, v3, v4, v5) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x01)!=0 )\
			l2trc_send_5_word(0x4813 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define CCMNI_DATA_DUMP_GPD_PTR(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_DL_DATA_IPv6_PACKET_TRACE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x40)!=0 )\
			l2trc_send_7_word(0x4913 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define CCMNI_DL_DATA_IPv6_PACKET_TRACE(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_UL_DATA_IPv6_PACKET_TRACE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x80)!=0 )\
			l2trc_send_7_word(0x4A13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define CCMNI_UL_DATA_IPv6_PACKET_TRACE(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_DL_DATA_PACKET_TRACE(v1, v2, v3, v4, v5) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x40)!=0 )\
			l2trc_send_5_word(0x4B13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define CCMNI_DL_DATA_PACKET_TRACE(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_DL_DATA_PACKET_NON_IPV4V6_TRACE(v1, v2, v3, v4, v5) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x40)!=0 )\
			l2trc_send_5_word(0x4C13 | ((short)(v1) << 16), (kal_uint32)((short)(v5)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define CCMNI_DL_DATA_PACKET_NON_IPV4V6_TRACE(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_UL_DATA_PACKET_TRACE(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x80)!=0 )\
			l2trc_send_4_word(0x4D13 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define CCMNI_UL_DATA_PACKET_TRACE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_UL_GPD_IN_HIF(v1, v2, v3, v4, v5, v6) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x80)!=0 )\
			l2trc_send_6_word(0x4E13 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define CCMNI_UL_GPD_IN_HIF(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_UL_RELOAD_RGPD(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x80)!=0 )\
			l2trc_send_4_word(0x4F13 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define CCMNI_UL_RELOAD_RGPD(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_UL_RELOAD_RGPD_IN_HIF(v1, v2, v3, v4, v5, v6, v7) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x80)!=0 )\
			l2trc_send_7_word(0x5013 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define CCMNI_UL_RELOAD_RGPD_IN_HIF(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_MAX_RELOAD_RGPD_IN_HIF(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_3_word(0x5113 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define CCMNI_MAX_RELOAD_RGPD_IN_HIF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCMNI_DEVICE_STATUS(v1, v2, v3, v4) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_4_word(0x5213 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define CCMNI_DEVICE_STATUS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCITTY_DATA_DUMP_TRACE(v1, v2, v3, v4, v5) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[2]&0x02)!=0 )\
			l2trc_send_5_word(0x5313 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define CCCITTY_DATA_DUMP_TRACE(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCIDEV_PROCESS_DL_SPD_TRACE(v1, v2) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x5413 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define CCCIDEV_PROCESS_DL_SPD_TRACE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCIDEV_PROCESS_DL_SPD_SET_IGR_TRACE(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x5513 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define CCCIDEV_PROCESS_DL_SPD_SET_IGR_TRACE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCIDEV_SPD_RELAYOUT_SET_PKTNUM_TRACE(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x5613 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define CCCIDEV_SPD_RELAYOUT_SET_PKTNUM_TRACE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CCCIDEV_SPD_RELAYOUT_GET_EOL_BREAK_TRACE(v1, v2, v3) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x5713 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define CCCIDEV_SPD_RELAYOUT_GET_EOL_BREAK_TRACE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_SIM_TPUT_ANALYSIS(v1, v2, v3, v4, v5, v6) do {\
		if(HIF_MW_Trace_Filter[0]==1 && (HIF_MW_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_6_word(0x5813 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define LTM_SIM_TPUT_ANALYSIS(v1, v2, v3, v4, v5, v6)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char HIF_MW_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_IPC_UL_UPLINK_CALLBACK(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_DEQUEUE_UPLINK_PRIORITY_QUEUE(short v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_DEQUEUE_UPLINK_QUEUE(short v1, short v2, unsigned long v3);
void L1TRC_Send_IPC_UL_ON_PROCESS_NORMAL_IOR(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IPC_UL_THROTTLE_IMS_EMERGEMCY_IND(short v1, long v2);
void L1TRC_Send_IPC_TR_TIMER_UL_THROTTLE_TIMEOUT(short v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_IPC_TR_START_UL_THROTTLE_TIMER(short v1, long v2);
void L1TRC_Send_IPC_UL_RELOAD_UPLINK(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_RELOAD_UPLINK_RESULT(short v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_IPC_UL_RELOAD_RETRY(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_IPC_UL_RELOAD_RETRY_RACE_COND(short v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_RELOAD_RETRY_FLAG(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IPC_UL_SET_NEED_RELOAD(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_SET_NEED_RELOAD_FLAG(short v1, unsigned long v2);
void L1TRC_Send_IPC_UL_ON_RETRY_RELOAD(short v1, unsigned long v2);
void L1TRC_Send_IPC_UL_ON_RETRY_RELOAD_FOR_NETIF(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IPC_UL_CHECK_UL_RELOAD_RETRY(short v1, unsigned long v2);
void L1TRC_Send_IPC_UL_DROP_UL_IOR(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IPC_UL_LOOPBACK_UL_IOR(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_LOOPBACK_UL_IOR_DROP(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_HANDLE_UL_GPD_LIST(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_FORWARD_UL_SDU(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_HANDLE_IPV4_UL_GPD_LIST(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_FORWARD_IPV4_UL_SDU(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_HANDLE_IPV6_UL_GPD_LIST(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_FORWARD_IPV6_UL_SDU(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_FORWARD_UL_SDU_MULTI_PS(short v1, long v2);
void L1TRC_Send_IPC_UL_FORWARD_UL_SDU_BY_EBI_MULTI_PS(short v1, long v2);
void L1TRC_Send_IPC_UL_DHCP4C_PKT_SESSION(short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_DHCP4C_PKT_UPLINK(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_SEND_PKT(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IPC_UL_SEND_PKT_BY_PDN(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_UL_SEND_PKT_MULTI_PS(short v1, long v2);
void L1TRC_Send_IPC_UL_SEND_PKT_BY_PDN_MULTI_PS(short v1, long v2);
void L1TRC_Send_IPC_UL_SEND_PKT_FORWARD(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IPC_UL_SEND_PKT_BY_PDN_FORWARD(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_DL_SEND_IPV4_PKT(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_DL_SEND_IPV6_PKT(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_DL_ON_DOWNLINK(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IPC_DL_ON_DOWNLINK_FILTER_OUT(short v1, long v2, unsigned long v3);
void L1TRC_Send_IPC_DL_ON_DOWNLINK_CALLBACK_INFO(short v1, long v2, unsigned long v3);
void L1TRC_Send_IPC_DL_ON_DOWNLINK_CALLBACK_GPD(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IPC_DL_ON_DOWNLINK_MULTI_PS(short v1, long v2);
void L1TRC_Send_IPC_DL_INVALID_LEN_CHK(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_IPC_DL_INVALID_LEN_PKT_IP_HDR(short v1, unsigned long v2);
void L1TRC_Send_IPC_GE_FILTER_RULE_MATCHED(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_IPC_GE_SPD_ENTRY_IGR_INFO(short v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_IPC_GE_SPD_ALL_IGR_INFO(short v1, unsigned long v2, long v3);
void L1TRC_Send_IPC_GE_DO_FILTER_GPD_UPDATE(short v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_IPC_GE_FILTER_OUT_INFO(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IPC_GE_FILTER_OUT_GPD(short v1, unsigned long v2, long v3);
void L1TRC_Send_IPC_GE_UNITE_FAIL_DROP(short v1, long v2);
void L1TRC_Send_IPC_GE_UNITE_FAIL_DROP_INFO(short v1, long v2, long v3, long v4);
void L1TRC_Send_IPC_GE_HANDLE_GPD(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_IPC_GE_SET_ALLOC_DATA(short v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_IPC_GE_FILL_HEADER(short v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_IPC_GE_UNITED_GPD(short v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_PFM_GE_DROP_PACKET_INFO(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PFM_GE_DROP_PACKET_DUMP(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_USBCORE_POLL_QUEUE_TX(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_USBCORE_POLL_QUEUE_TX_NOTIFY_END(short v1);
void L1TRC_Send_USBCORE_POLL_QUEUE_RX(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_USBCORE_POLL_QUEUE_RX_NOTIFY_END(short v1);
void L1TRC_Send_USBCORE_POLL_QUEUE_LEN_TX(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_USBCORE_POLL_QUEUE_LEN_RX(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_USBCORE_CLASS_SUBMIT_IO_REQUEST_HWQ(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_USBCORE_CLASS_SUBMIT_IO_REQUEST_SWQ(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_USBCORE_CLASS_FLUSH_HW_QUEUE(unsigned short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_USBCORE_CLASS_FLUSH_SW_QUEUE(unsigned short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_USBCORE_RESTORE_RX_GPD_SWQ2HWQ(unsigned short v1);
void L1TRC_Send_USBCORE_RESTORE_TX_GPD_SWQ2HWQ(unsigned short v1);
void L1TRC_Send_CCMNI_DATA_DUMP_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_CCMNI_DATA_DUMP_GPD_PTR(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_CCMNI_DL_DATA_IPv6_PACKET_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_CCMNI_UL_DATA_IPv6_PACKET_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_CCMNI_DL_DATA_PACKET_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_CCMNI_DL_DATA_PACKET_NON_IPV4V6_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, short v5);
void L1TRC_Send_CCMNI_UL_DATA_PACKET_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_CCMNI_UL_GPD_IN_HIF(short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_CCMNI_UL_RELOAD_RGPD(short v1, long v2, long v3, long v4);
void L1TRC_Send_CCMNI_UL_RELOAD_RGPD_IN_HIF(short v1, long v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_CCMNI_MAX_RELOAD_RGPD_IN_HIF(short v1, long v2, long v3);
void L1TRC_Send_CCMNI_DEVICE_STATUS(short v1, long v2, long v3, long v4);
void L1TRC_Send_CCCITTY_DATA_DUMP_TRACE(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_CCCIDEV_PROCESS_DL_SPD_TRACE(short v1, unsigned long v2);
void L1TRC_Send_CCCIDEV_PROCESS_DL_SPD_SET_IGR_TRACE(short v1, short v2, unsigned long v3);
void L1TRC_Send_CCCIDEV_SPD_RELAYOUT_SET_PKTNUM_TRACE(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_CCCIDEV_SPD_RELAYOUT_GET_EOL_BREAK_TRACE(short v1, short v2, unsigned long v3);
void L1TRC_Send_LTM_SIM_TPUT_ANALYSIS(short v1, long v2, long v3, long v4, long v5, long v6);

void Set_HIF_MW_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_HIF_MW()	(HIF_MW_Trace_Filter[0]==1)
#define ChkL1ClsFltr_HIF_MW_UL()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_HIF_MW_DL()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_HIF_MW_GE()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_HIF_MW_USBCORE_POLL_QUEUE()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_HIF_MW_USBCORE_CLASS_REQUEST()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_HIF_MW_CCMNI()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_HIF_MW_CCMNI_DL()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_HIF_MW_CCMNI_UL()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_HIF_MW_CCMNI_DUMP()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_HIF_MW_CCCITTY_DUMP()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_HIF_MW_UL_DETAIL()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_HIF_MW_DL_DETAIL()	(ChkL1ModFltr_HIF_MW()&&((HIF_MW_Trace_Filter[2]&0x08)!=0))
#define ChkL1MsgFltr_IPC_UL_UPLINK_CALLBACK()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_DEQUEUE_UPLINK_PRIORITY_QUEUE()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_DEQUEUE_UPLINK_QUEUE()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_ON_PROCESS_NORMAL_IOR()	ChkL1ClsFltr_HIF_MW_UL_DETAIL()
#define ChkL1MsgFltr_IPC_UL_THROTTLE_IMS_EMERGEMCY_IND()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_TR_TIMER_UL_THROTTLE_TIMEOUT()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_TR_START_UL_THROTTLE_TIMER()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_RELOAD_UPLINK()	ChkL1ClsFltr_HIF_MW_UL_DETAIL()
#define ChkL1MsgFltr_IPC_UL_RELOAD_UPLINK_RESULT()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_RELOAD_RETRY()	ChkL1ClsFltr_HIF_MW_UL_DETAIL()
#define ChkL1MsgFltr_IPC_UL_RELOAD_RETRY_RACE_COND()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_RELOAD_RETRY_FLAG()	ChkL1ClsFltr_HIF_MW_UL_DETAIL()
#define ChkL1MsgFltr_IPC_UL_SET_NEED_RELOAD()	ChkL1ClsFltr_HIF_MW_UL_DETAIL()
#define ChkL1MsgFltr_IPC_UL_SET_NEED_RELOAD_FLAG()	ChkL1ClsFltr_HIF_MW_UL_DETAIL()
#define ChkL1MsgFltr_IPC_UL_ON_RETRY_RELOAD()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_ON_RETRY_RELOAD_FOR_NETIF()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_CHECK_UL_RELOAD_RETRY()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_DROP_UL_IOR()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_LOOPBACK_UL_IOR()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_LOOPBACK_UL_IOR_DROP()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_HANDLE_UL_GPD_LIST()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_FORWARD_UL_SDU()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_HANDLE_IPV4_UL_GPD_LIST()	ChkL1ClsFltr_HIF_MW_UL_DETAIL()
#define ChkL1MsgFltr_IPC_UL_FORWARD_IPV4_UL_SDU()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_HANDLE_IPV6_UL_GPD_LIST()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_FORWARD_IPV6_UL_SDU()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_FORWARD_UL_SDU_MULTI_PS()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_FORWARD_UL_SDU_BY_EBI_MULTI_PS()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_DHCP4C_PKT_SESSION()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_DHCP4C_PKT_UPLINK()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_SEND_PKT()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_SEND_PKT_BY_PDN()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_SEND_PKT_MULTI_PS()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_SEND_PKT_BY_PDN_MULTI_PS()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_SEND_PKT_FORWARD()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_UL_SEND_PKT_BY_PDN_FORWARD()	ChkL1ClsFltr_HIF_MW_UL()
#define ChkL1MsgFltr_IPC_DL_SEND_IPV4_PKT()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_IPC_DL_SEND_IPV6_PKT()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_IPC_DL_ON_DOWNLINK()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_IPC_DL_ON_DOWNLINK_FILTER_OUT()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_IPC_DL_ON_DOWNLINK_CALLBACK_INFO()	ChkL1ClsFltr_HIF_MW_DL_DETAIL()
#define ChkL1MsgFltr_IPC_DL_ON_DOWNLINK_CALLBACK_GPD()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_IPC_DL_ON_DOWNLINK_MULTI_PS()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_IPC_DL_INVALID_LEN_CHK()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_IPC_DL_INVALID_LEN_PKT_IP_HDR()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_IPC_GE_FILTER_RULE_MATCHED()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_SPD_ENTRY_IGR_INFO()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_SPD_ALL_IGR_INFO()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_DO_FILTER_GPD_UPDATE()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_FILTER_OUT_INFO()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_FILTER_OUT_GPD()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_UNITE_FAIL_DROP()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_UNITE_FAIL_DROP_INFO()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_HANDLE_GPD()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_SET_ALLOC_DATA()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_FILL_HEADER()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_IPC_GE_UNITED_GPD()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_PFM_GE_DROP_PACKET_INFO()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_PFM_GE_DROP_PACKET_DUMP()	ChkL1ClsFltr_HIF_MW_GE()
#define ChkL1MsgFltr_USBCORE_POLL_QUEUE_TX()	ChkL1ClsFltr_HIF_MW_USBCORE_POLL_QUEUE()
#define ChkL1MsgFltr_USBCORE_POLL_QUEUE_TX_NOTIFY_END()	ChkL1ClsFltr_HIF_MW_USBCORE_POLL_QUEUE()
#define ChkL1MsgFltr_USBCORE_POLL_QUEUE_RX()	ChkL1ClsFltr_HIF_MW_USBCORE_POLL_QUEUE()
#define ChkL1MsgFltr_USBCORE_POLL_QUEUE_RX_NOTIFY_END()	ChkL1ClsFltr_HIF_MW_USBCORE_POLL_QUEUE()
#define ChkL1MsgFltr_USBCORE_POLL_QUEUE_LEN_TX()	ChkL1ClsFltr_HIF_MW_USBCORE_POLL_QUEUE()
#define ChkL1MsgFltr_USBCORE_POLL_QUEUE_LEN_RX()	ChkL1ClsFltr_HIF_MW_USBCORE_POLL_QUEUE()
#define ChkL1MsgFltr_USBCORE_CLASS_SUBMIT_IO_REQUEST_HWQ()	ChkL1ClsFltr_HIF_MW_USBCORE_CLASS_REQUEST()
#define ChkL1MsgFltr_USBCORE_CLASS_SUBMIT_IO_REQUEST_SWQ()	ChkL1ClsFltr_HIF_MW_USBCORE_CLASS_REQUEST()
#define ChkL1MsgFltr_USBCORE_CLASS_FLUSH_HW_QUEUE()	ChkL1ClsFltr_HIF_MW_USBCORE_CLASS_REQUEST()
#define ChkL1MsgFltr_USBCORE_CLASS_FLUSH_SW_QUEUE()	ChkL1ClsFltr_HIF_MW_USBCORE_CLASS_REQUEST()
#define ChkL1MsgFltr_USBCORE_RESTORE_RX_GPD_SWQ2HWQ()	ChkL1ClsFltr_HIF_MW_USBCORE_CLASS_REQUEST()
#define ChkL1MsgFltr_USBCORE_RESTORE_TX_GPD_SWQ2HWQ()	ChkL1ClsFltr_HIF_MW_USBCORE_CLASS_REQUEST()
#define ChkL1MsgFltr_CCMNI_DATA_DUMP_TRACE()	ChkL1ClsFltr_HIF_MW_CCMNI_DUMP()
#define ChkL1MsgFltr_CCMNI_DATA_DUMP_GPD_PTR()	ChkL1ClsFltr_HIF_MW_CCMNI_DUMP()
#define ChkL1MsgFltr_CCMNI_DL_DATA_IPv6_PACKET_TRACE()	ChkL1ClsFltr_HIF_MW_CCMNI_DL()
#define ChkL1MsgFltr_CCMNI_UL_DATA_IPv6_PACKET_TRACE()	ChkL1ClsFltr_HIF_MW_CCMNI_UL()
#define ChkL1MsgFltr_CCMNI_DL_DATA_PACKET_TRACE()	ChkL1ClsFltr_HIF_MW_CCMNI_DL()
#define ChkL1MsgFltr_CCMNI_DL_DATA_PACKET_NON_IPV4V6_TRACE()	ChkL1ClsFltr_HIF_MW_CCMNI_DL()
#define ChkL1MsgFltr_CCMNI_UL_DATA_PACKET_TRACE()	ChkL1ClsFltr_HIF_MW_CCMNI_UL()
#define ChkL1MsgFltr_CCMNI_UL_GPD_IN_HIF()	ChkL1ClsFltr_HIF_MW_CCMNI_UL()
#define ChkL1MsgFltr_CCMNI_UL_RELOAD_RGPD()	ChkL1ClsFltr_HIF_MW_CCMNI_UL()
#define ChkL1MsgFltr_CCMNI_UL_RELOAD_RGPD_IN_HIF()	ChkL1ClsFltr_HIF_MW_CCMNI_UL()
#define ChkL1MsgFltr_CCMNI_MAX_RELOAD_RGPD_IN_HIF()	ChkL1ClsFltr_HIF_MW_CCMNI()
#define ChkL1MsgFltr_CCMNI_DEVICE_STATUS()	ChkL1ClsFltr_HIF_MW_CCMNI()
#define ChkL1MsgFltr_CCCITTY_DATA_DUMP_TRACE()	ChkL1ClsFltr_HIF_MW_CCCITTY_DUMP()
#define ChkL1MsgFltr_CCCIDEV_PROCESS_DL_SPD_TRACE()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_CCCIDEV_PROCESS_DL_SPD_SET_IGR_TRACE()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_CCCIDEV_SPD_RELAYOUT_SET_PKTNUM_TRACE()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_CCCIDEV_SPD_RELAYOUT_GET_EOL_BREAK_TRACE()	ChkL1ClsFltr_HIF_MW_DL()
#define ChkL1MsgFltr_LTM_SIM_TPUT_ANALYSIS()	ChkL1ClsFltr_HIF_MW_GE()


#endif
