#ifndef L1TRC_EL1D_DPD0_DEF_H
#define L1TRC_EL1D_DPD0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_DPD_FAC_DBG_MSG_TYPE(v1)  (unsigned char)(v1+0)
#define EL1D_TRC_STR_DPD_FAC_CIM3_GET_SET_TYPE(v1)  (unsigned char)(v1+20)
#define EL1D_TRC_STR_DPD_FAC_DPD_GET_SET_TYPE(v1)  (unsigned char)(v1+22)
#define EL1D_TRC_STR_DPD_FAC_PA_GET_SET_TYPE(v1)  (unsigned char)(v1+26)
#define EL1D_TRC_STR_DPD_OTFC_CMIF_HANDSHAKE_ENTRY_EYPE(v1)  (unsigned char)(v1+28)
#define EL1D_TRC_STR_DPD_OTFC_CMIF_MEAS_STATE(v1)  (unsigned char)(v1+30)
#define EL1D_TRC_STR_DPD_OTFC_LISR_STATE(v1)  (unsigned char)(v1+35)
#define EL1D_TRC_STR_DPD_OTFC_CMIF_ABORT_STATE(v1)  (unsigned char)(v1+39)
#define EL1D_TRC_STR_DPD_OTFC_DBG_MSG_TYPE(v1)  (unsigned char)(v1+42)
#define EL1D_TRC_STR_DPD_LTE_TX_BANDS(v1)  (unsigned char)(v1+50)
#define EL1D_TRC_STR_DPD_LTE_TX_CBW(v1)  (unsigned char)(v1+95)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DBG_MSG0(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0043, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DBG_MSG0(v1)
#endif
#define EL1D_TRC_DPD_FAC_DBG_MSG0_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0043, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DBG_MSG1(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0143, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DBG_MSG1(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_DBG_MSG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0143, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DBG_MSG2(v1, v2, v3) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0243, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DBG_MSG2(v1, v2, v3)
#endif
#define EL1D_TRC_DPD_FAC_DBG_MSG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0243, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DBG_MSG3(v1, v2, v3, v4) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0343, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DBG_MSG3(v1, v2, v3, v4)
#endif
#define EL1D_TRC_DPD_FAC_DBG_MSG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0343, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DBG_MSG4(v1, v2, v3, v4, v5) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0443, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DBG_MSG4(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_DPD_FAC_DBG_MSG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0443, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_DBG_MSG0(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0543, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_DBG_MSG0(v1)
#endif
#define EL1D_TRC_DPD_OTFC_DBG_MSG0_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0543, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_DBG_MSG1(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0643, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_DBG_MSG1(v1, v2)
#endif
#define EL1D_TRC_DPD_OTFC_DBG_MSG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0643, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_DBG_MSG2(v1, v2, v3) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0743, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_DBG_MSG2(v1, v2, v3)
#endif
#define EL1D_TRC_DPD_OTFC_DBG_MSG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0743, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_DBG_MSG3(v1, v2, v3, v4) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0843, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_DBG_MSG3(v1, v2, v3, v4)
#endif
#define EL1D_TRC_DPD_OTFC_DBG_MSG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0843, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_DBG_MSG4(v1, v2, v3, v4, v5) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0943, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_DBG_MSG4(v1, v2, v3, v4, v5)
#endif
#define EL1D_TRC_DPD_OTFC_DBG_MSG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0943, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DPD_START_ENTER(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A43, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DPD_START_ENTER(v1)
#endif
#define EL1D_TRC_DPD_FAC_DPD_START_ENTER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A43, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DPD_START_LEAVE(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B43, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DPD_START_LEAVE(v1)
#endif
#define EL1D_TRC_DPD_FAC_DPD_START_LEAVE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B43, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DPD_GET_ENTER(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DPD_GET_ENTER(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_DPD_GET_ENTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DPD_GET_LEAVE(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DPD_GET_LEAVE(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_DPD_GET_LEAVE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DPD_SET_ENTER(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DPD_SET_ENTER(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_DPD_SET_ENTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_DPD_SET_LEAVE(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_DPD_SET_LEAVE(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_DPD_SET_LEAVE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_CIM3_START_ENTER(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1043, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_CIM3_START_ENTER(v1)
#endif
#define EL1D_TRC_DPD_FAC_CIM3_START_ENTER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1043, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_CIM3_START_LEAVE(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1143, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_CIM3_START_LEAVE(v1)
#endif
#define EL1D_TRC_DPD_FAC_CIM3_START_LEAVE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1143, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_CIM3_GET_ENTER(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1243, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_CIM3_GET_ENTER(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_CIM3_GET_ENTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1243, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_CIM3_GET_LEAVE(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1343, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_CIM3_GET_LEAVE(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_CIM3_GET_LEAVE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1343, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_CIM3_SET_ENTER(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1443, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_CIM3_SET_ENTER(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_CIM3_SET_ENTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1443, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_CIM3_SET_LEAVE(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1543, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_CIM3_SET_LEAVE(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_CIM3_SET_LEAVE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1543, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_PA_START_ENTER(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1643, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_PA_START_ENTER(v1)
#endif
#define EL1D_TRC_DPD_FAC_PA_START_ENTER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1643, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_PA_START_LEAVE(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1743, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_PA_START_LEAVE(v1)
#endif
#define EL1D_TRC_DPD_FAC_PA_START_LEAVE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1743, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_PA_GET_ENTER(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1843, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_PA_GET_ENTER(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_PA_GET_ENTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1843, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_PA_GET_LEAVE(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1943, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_PA_GET_LEAVE(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_PA_GET_LEAVE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1943, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_PA_SET_ENTER(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_PA_SET_ENTER(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_PA_SET_ENTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_PA_SET_LEAVE(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_PA_SET_LEAVE(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_PA_SET_LEAVE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B43, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_CIM3_GET_LUT_CONFIG_ENTER(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C43, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_CIM3_GET_LUT_CONFIG_ENTER(v1, v2)
#endif
#define EL1D_TRC_DPD_CIM3_GET_LUT_CONFIG_ENTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C43, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_CIM3_GET_LUT_CONFIG_LEAVE(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D43, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_CIM3_GET_LUT_CONFIG_LEAVE(v1, v2)
#endif
#define EL1D_TRC_DPD_CIM3_GET_LUT_CONFIG_LEAVE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D43, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_SWITCH_ENTER(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E43, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_SWITCH_ENTER(v1, v2)
#endif
#define EL1D_TRC_DPD_SWITCH_ENTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E43, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CIM3_SWITCH_ENTER(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F43, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CIM3_SWITCH_ENTER(v1, v2)
#endif
#define EL1D_TRC_CIM3_SWITCH_ENTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F43, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_SF_TICK_RF_FEC_CTRL_ENTER(v1, v2, v3, v4) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2043, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_SF_TICK_RF_FEC_CTRL_ENTER(v1, v2, v3, v4)
#endif
#define EL1D_TRC_DPD_FAC_SF_TICK_RF_FEC_CTRL_ENTER_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2043, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_TAR_TIME_WAIT(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2143, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_TAR_TIME_WAIT(v1, v2)
#endif
#define EL1D_TRC_DPD_FAC_TAR_TIME_WAIT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2143, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_FAC_GAIN_CTRL() do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2243, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_FAC_GAIN_CTRL()
#endif
#define EL1D_TRC_DPD_FAC_GAIN_CTRL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2243, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_CIM3_OTFC_GDMA_HISR_ENTER(v1, v2, v3, v4) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2343, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_DPD_CIM3_OTFC_GDMA_HISR_ENTER(v1, v2, v3, v4)
#endif
#define EL1D_TRC_DPD_CIM3_OTFC_GDMA_HISR_ENTER_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2343, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_CIM3_OTFC_GDMA_HISR_LEAVE(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2443, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_DPD_CIM3_OTFC_GDMA_HISR_LEAVE(v1, v2)
#endif
#define EL1D_TRC_DPD_CIM3_OTFC_GDMA_HISR_LEAVE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2443, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_COMP_EN() do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2543, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_COMP_EN()
#endif
#define EL1D_TRC_DPD_OTFC_COMP_EN_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2543, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_CIM3_OTFC_COMP_EN() do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2643, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_CIM3_OTFC_COMP_EN()
#endif
#define EL1D_TRC_CIM3_OTFC_COMP_EN_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2643, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_SRAM_CONFLICT(v1, v2, v3) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2743, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_SRAM_CONFLICT(v1, v2, v3)
#endif
#define EL1D_TRC_DPD_OTFC_SRAM_CONFLICT_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2743, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_ENTER_CMIF_HANDSHAKE(v1, v2, v3, v4) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2843, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_ENTER_CMIF_HANDSHAKE(v1, v2, v3, v4)
#endif
#define EL1D_TRC_DPD_OTFC_ENTER_CMIF_HANDSHAKE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2843, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_LEAVE_CMIF_HANDSHAKE(v1, v2, v3) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2943, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_LEAVE_CMIF_HANDSHAKE(v1, v2, v3)
#endif
#define EL1D_TRC_DPD_OTFC_LEAVE_CMIF_HANDSHAKE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2943, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_SEND_DPD_LUT_TO_FEC(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A43, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_SEND_DPD_LUT_TO_FEC(v1)
#endif
#define EL1D_TRC_DPD_OTFC_SEND_DPD_LUT_TO_FEC_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A43, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_ISSUE_LISR(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B43, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_ISSUE_LISR(v1)
#endif
#define EL1D_TRC_DPD_OTFC_ISSUE_LISR_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B43, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_TX_SHARE_CH_OFF() do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C43, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_TX_SHARE_CH_OFF()
#endif
#define EL1D_TRC_DPD_OTFC_TX_SHARE_CH_OFF_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C43, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_COPY_CMIF_RESULT() do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D43, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_COPY_CMIF_RESULT()
#endif
#define EL1D_TRC_DPD_OTFC_COPY_CMIF_RESULT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D43, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_AM_ACTIVE_BUF(v1, v2, v3) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E43, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_AM_ACTIVE_BUF(v1, v2, v3)
#endif
#define EL1D_TRC_DPD_OTFC_AM_ACTIVE_BUF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E43, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_PM_ACTIVE_BUF(v1, v2, v3) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F43, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_PM_ACTIVE_BUF(v1, v2, v3)
#endif
#define EL1D_TRC_DPD_OTFC_PM_ACTIVE_BUF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F43, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_AM_RESULT(v1, v2, v3) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3043, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_AM_RESULT(v1, v2, v3)
#endif
#define EL1D_TRC_DPD_OTFC_AM_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3043, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_PM_RESULT(v1, v2, v3) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3143, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_PM_RESULT(v1, v2, v3)
#endif
#define EL1D_TRC_DPD_OTFC_PM_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3143, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_LISR_UPDATE_SRAM() do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3243, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_LISR_UPDATE_SRAM()
#endif
#define EL1D_TRC_DPD_OTFC_LISR_UPDATE_SRAM_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3243, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_LISR_NO_UPDATE_SRAM() do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3343, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_LISR_NO_UPDATE_SRAM()
#endif
#define EL1D_TRC_DPD_OTFC_LISR_NO_UPDATE_SRAM_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3343, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_EXCEED_MAX_SUBFRAME(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3443, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_EXCEED_MAX_SUBFRAME(v1)
#endif
#define EL1D_TRC_DPD_OTFC_EXCEED_MAX_SUBFRAME_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3443, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_HW_LUT_IDX(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3543, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_HW_LUT_IDX(v1, v2)
#endif
#define EL1D_TRC_DPD_OTFC_HW_LUT_IDX_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3543, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_AM_PM_UPDATE_EN(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3643, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_AM_PM_UPDATE_EN(v1, v2)
#endif
#define EL1D_TRC_DPD_OTFC_AM_PM_UPDATE_EN_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3643, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_UPDATE_SHARE_MEMORY() do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3743, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_UPDATE_SHARE_MEMORY()
#endif
#define EL1D_TRC_DPD_OTFC_UPDATE_SHARE_MEMORY_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3743, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_ABORT_DSP() do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3843, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_ABORT_DSP()
#endif
#define EL1D_TRC_DPD_OTFC_ABORT_DSP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3843, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_COMP_EN_AM_OR_PM_DISABLE(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3943, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_COMP_EN_AM_OR_PM_DISABLE(v1)
#endif
#define EL1D_TRC_DPD_OTFC_COMP_EN_AM_OR_PM_DISABLE_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3943, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_BYPASS_DUETO_BAD_TDE() do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A43, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_BYPASS_DUETO_BAD_TDE()
#endif
#define EL1D_TRC_DPD_OTFC_BYPASS_DUETO_BAD_TDE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A43, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_TEMPERATURE(v1) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3B43, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_TEMPERATURE(v1)
#endif
#define EL1D_TRC_DPD_OTFC_TEMPERATURE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3B43, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_FORCE_TO_APT(v1, v2) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C43, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_FORCE_TO_APT(v1, v2)
#endif
#define EL1D_TRC_DPD_OTFC_FORCE_TO_APT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C43, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1D_TRC_DPD_OTFC_TR_DELAY_SELECT(v1, v2, v3) do {\
		if(EL1D_DPD0_Trace_Filter[0]==1 && (EL1D_DPD0_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3D43, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1D_TRC_DPD_OTFC_TR_DELAY_SELECT(v1, v2, v3)
#endif
#define EL1D_TRC_DPD_OTFC_TR_DELAY_SELECT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3D43, (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v1))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_DPD0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_DPD_FAC_DBG_MSG0(unsigned char v1);
void L1TRC_Send_EL1D_TRC_DPD_FAC_DBG_MSG1(unsigned char v1, long v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_DBG_MSG2(unsigned char v1, long v2, long v3);
void L1TRC_Send_EL1D_TRC_DPD_FAC_DBG_MSG3(unsigned char v1, long v2, long v3, long v4);
void L1TRC_Send_EL1D_TRC_DPD_FAC_DBG_MSG4(unsigned char v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_DBG_MSG0(unsigned char v1);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_DBG_MSG1(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_DBG_MSG2(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_DBG_MSG3(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_DBG_MSG4(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1D_TRC_DPD_FAC_DPD_START_ENTER(short v1);
void L1TRC_Send_EL1D_TRC_DPD_FAC_DPD_START_LEAVE(short v1);
void L1TRC_Send_EL1D_TRC_DPD_FAC_DPD_GET_ENTER(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_DPD_GET_LEAVE(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_DPD_SET_ENTER(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_DPD_SET_LEAVE(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_CIM3_START_ENTER(short v1);
void L1TRC_Send_EL1D_TRC_DPD_FAC_CIM3_START_LEAVE(short v1);
void L1TRC_Send_EL1D_TRC_DPD_FAC_CIM3_GET_ENTER(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_CIM3_GET_LEAVE(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_CIM3_SET_ENTER(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_CIM3_SET_LEAVE(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_PA_START_ENTER(short v1);
void L1TRC_Send_EL1D_TRC_DPD_FAC_PA_START_LEAVE(short v1);
void L1TRC_Send_EL1D_TRC_DPD_FAC_PA_GET_ENTER(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_PA_GET_LEAVE(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_PA_SET_ENTER(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_PA_SET_LEAVE(short v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_CIM3_GET_LUT_CONFIG_ENTER(short v1, short v2);
void L1TRC_Send_EL1D_TRC_DPD_CIM3_GET_LUT_CONFIG_LEAVE(short v1, short v2);
void L1TRC_Send_EL1D_TRC_DPD_SWITCH_ENTER(short v1, short v2);
void L1TRC_Send_EL1D_TRC_CIM3_SWITCH_ENTER(short v1, short v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_SF_TICK_RF_FEC_CTRL_ENTER(short v1, char v2, short v3, long v4);
void L1TRC_Send_EL1D_TRC_DPD_FAC_TAR_TIME_WAIT(long v1, long v2);
void L1TRC_Send_EL1D_TRC_DPD_FAC_GAIN_CTRL(void);
void L1TRC_Send_EL1D_TRC_DPD_CIM3_OTFC_GDMA_HISR_ENTER(unsigned long v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_EL1D_TRC_DPD_CIM3_OTFC_GDMA_HISR_LEAVE(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_COMP_EN(void);
void L1TRC_Send_EL1D_TRC_CIM3_OTFC_COMP_EN(void);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_SRAM_CONFLICT(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_ENTER_CMIF_HANDSHAKE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_LEAVE_CMIF_HANDSHAKE(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_SEND_DPD_LUT_TO_FEC(unsigned long v1);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_ISSUE_LISR(unsigned long v1);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_TX_SHARE_CH_OFF(void);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_COPY_CMIF_RESULT(void);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_AM_ACTIVE_BUF(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_PM_ACTIVE_BUF(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_AM_RESULT(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_PM_RESULT(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_LISR_UPDATE_SRAM(void);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_LISR_NO_UPDATE_SRAM(void);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_EXCEED_MAX_SUBFRAME(short v1);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_HW_LUT_IDX(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_AM_PM_UPDATE_EN(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_UPDATE_SHARE_MEMORY(void);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_ABORT_DSP(void);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_COMP_EN_AM_OR_PM_DISABLE(unsigned long v1);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_BYPASS_DUETO_BAD_TDE(void);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_TEMPERATURE(short v1);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_FORCE_TO_APT(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1D_TRC_DPD_OTFC_TR_DELAY_SELECT(unsigned long v1, unsigned char v2, unsigned char v3);

void Set_EL1D_DPD0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_DPD0()	(EL1D_DPD0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()	(ChkL1ModFltr_EL1D_DPD0()&&((EL1D_DPD0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_M()	(ChkL1ModFltr_EL1D_DPD0()&&((EL1D_DPD0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_L()	(ChkL1ModFltr_EL1D_DPD0()&&((EL1D_DPD0_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()	(ChkL1ModFltr_EL1D_DPD0()&&((EL1D_DPD0_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_M()	(ChkL1ModFltr_EL1D_DPD0()&&((EL1D_DPD0_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_L()	(ChkL1ModFltr_EL1D_DPD0()&&((EL1D_DPD0_Trace_Filter[1]&0x20)!=0))
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DBG_MSG0()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DBG_MSG1()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DBG_MSG2()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DBG_MSG3()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DBG_MSG4()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_DBG_MSG0()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_DBG_MSG1()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_DBG_MSG2()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_DBG_MSG3()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_DBG_MSG4()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DPD_START_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DPD_START_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DPD_GET_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DPD_GET_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DPD_SET_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_DPD_SET_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_CIM3_START_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_CIM3_START_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_CIM3_GET_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_CIM3_GET_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_CIM3_SET_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_CIM3_SET_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_PA_START_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_PA_START_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_PA_GET_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_PA_GET_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_PA_SET_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_PA_SET_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_CIM3_GET_LUT_CONFIG_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_CIM3_GET_LUT_CONFIG_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_SWITCH_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CIM3_SWITCH_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_SF_TICK_RF_FEC_CTRL_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_TAR_TIME_WAIT()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_FAC_GAIN_CTRL()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_FAC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_CIM3_OTFC_GDMA_HISR_ENTER()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_CIM3_OTFC_GDMA_HISR_LEAVE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_COMP_EN()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_CIM3_OTFC_COMP_EN()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_SRAM_CONFLICT()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_ENTER_CMIF_HANDSHAKE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_LEAVE_CMIF_HANDSHAKE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_SEND_DPD_LUT_TO_FEC()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_ISSUE_LISR()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_TX_SHARE_CH_OFF()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_COPY_CMIF_RESULT()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_AM_ACTIVE_BUF()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_PM_ACTIVE_BUF()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_AM_RESULT()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_PM_RESULT()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_LISR_UPDATE_SRAM()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_LISR_NO_UPDATE_SRAM()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_EXCEED_MAX_SUBFRAME()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_HW_LUT_IDX()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_AM_PM_UPDATE_EN()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_UPDATE_SHARE_MEMORY()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_ABORT_DSP()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_COMP_EN_AM_OR_PM_DISABLE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_BYPASS_DUETO_BAD_TDE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_TEMPERATURE()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_FORCE_TO_APT()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()
#define ChkL1MsgFltr_EL1D_TRC_DPD_OTFC_TR_DELAY_SELECT()	ChkL1ClsFltr_EL1D_DPD0_EL1D_TRC_CLS_DPD_OTFC_MAIN_H()


#endif
