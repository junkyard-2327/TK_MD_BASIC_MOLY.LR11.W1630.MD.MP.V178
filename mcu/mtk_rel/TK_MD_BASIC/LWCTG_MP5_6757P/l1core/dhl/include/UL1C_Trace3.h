#ifndef L1TRC_UL1C_PRI3_DEF_H
#define L1TRC_UL1C_PRI3_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct1(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0028, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct1(v1, v2, v3, v4)
#endif
#define UL1T_TRC_TGPS_Reconstruct1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0028, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct2(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0128, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct2(v1, v2, v3)
#endif
#define UL1T_TRC_TGPS_Reconstruct2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0128, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct3(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0228, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct3(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_TGPS_Reconstruct3_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0228, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct4(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0328, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct4(v1, v2, v3, v4)
#endif
#define UL1T_TRC_TGPS_Reconstruct4_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0328, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct5(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0428, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct5(v1, v2)
#endif
#define UL1T_TRC_TGPS_Reconstruct5_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0428, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct6(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0528, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct6(v1, v2, v3, v4)
#endif
#define UL1T_TRC_TGPS_Reconstruct6_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0528, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0628, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_TGPS_Reconstruct7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0628, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_MeasControl(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0728, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_MeasControl(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_TGPS_MeasControl_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0728, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_MeasControl(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0828, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (char)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_MeasControl(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_TGPS_MeasControl_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0828, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), (char)(v5)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Act(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0928, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Act(v1, v2, v3)
#endif
#define UL1T_TRC_TGPS_Act_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0928, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Frame(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A28, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Frame(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_TGPS_Frame_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A28, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Kill_Pending_MC(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Kill_Pending_MC(v1, v2)
#endif
#define UL1I_TRC_TGPS_Kill_Pending_MC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Status(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Status(v1, v2, v3)
#endif
#define UL1I_TRC_TGPS_Status_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Frame_Type(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Frame_Type(v1, v2, v3)
#endif
#define UL1I_TRC_TGPS_Frame_Type_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Check_InterF(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E28, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Check_InterF(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_TGPS_Check_InterF_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E28, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Frame_Dummy(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Frame_Dummy(v1, v2, v3)
#endif
#define UL1I_TRC_TGPS_Frame_Dummy_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Not_Allow_Recons(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1028, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Not_Allow_Recons(v1, v2)
#endif
#define UL1I_TRC_TGPS_Not_Allow_Recons_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1028, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Frame_Len(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1128, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Frame_Len(v1, v2, v3)
#endif
#define UL1I_TRC_TGPS_Frame_Len_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1128, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_MaxTTI(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1228, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_MaxTTI(v1, v2)
#endif
#define UL1I_TRC_TGPS_MaxTTI_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1228, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Overlap_Reconfig(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1328, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Overlap_Reconfig(v1, v2)
#endif
#define UL1I_TRC_TGPS_Overlap_Reconfig_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1328, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_TGCFN_MODIFY(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1428, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_TGCFN_MODIFY(v1, v2)
#endif
#define UL1T_TRC_TGPS_TGCFN_MODIFY_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1428, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_ConfigUpdate(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1528, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_ConfigUpdate(v1, v2)
#endif
#define UL1T_TRC_TGPS_ConfigUpdate_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1528, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_ConfigUpdate(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1628, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_ConfigUpdate(v1, v2)
#endif
#define UL1I_TRC_TGPS_ConfigUpdate_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1628, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RACH_offset(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1728, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RACH_offset(v1, v2, v3)
#endif
#define UL1I_TRC_RACH_offset_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1728, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Keep_Awake(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1828, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Keep_Awake(v1)
#endif
#define UL1I_TRC_Keep_Awake_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1828, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_VFD_RecoverFrame(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1928, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_VFD_RecoverFrame(v1, v2)
#endif
#define UL1I_TRC_VFD_RecoverFrame_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1928, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_VFD_Status_Delay_VFD_timer(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A28, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_VFD_Status_Delay_VFD_timer(v1)
#endif
#define UL1I_TRC_VFD_Status_Delay_VFD_timer_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A28, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_VFD_Status_Recovery_stage2(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B28, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_VFD_Status_Recovery_stage2(v1)
#endif
#define UL1I_TRC_VFD_Status_Recovery_stage2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B28, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_AssignGAPDBG(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_AssignGAPDBG(v1, v2, v3)
#endif
#define UL1I_TRC_AssignGAPDBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_PM_Done(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D28, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_DM_PM_Done(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DM_PM_Done_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D28, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_PM_Tick(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_PM_Tick(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DM_PM_Tick_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Set_GSM_Gap_Type(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F28, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Set_GSM_Gap_Type(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_DM_Set_GSM_Gap_Type_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F28, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Post_Fail_InSync_Immed(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2028, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Post_Fail_InSync_Immed(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_Post_Fail_InSync_Immed_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2028, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_tgprc_modify_to_zero(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2128, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_tgprc_modify_to_zero(v1)
#endif
#define UL1I_TRC_tgprc_modify_to_zero_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2128, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HHO_Query_Timing_fail(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2228, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HHO_Query_Timing_fail(v1, v2, v3)
#endif
#define UL1I_TRC_HHO_Query_Timing_fail_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2228, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_QueueFunctionOverflow(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2328, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_QueueFunctionOverflow(v1)
#endif
#define UL1I_TRC_QueueFunctionOverflow_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2328, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_timer_delay_type(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2428, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CCM_timer_delay_type(v1, v2, v3)
#endif
#define UL1I_TRC_CCM_timer_delay_type_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2428, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Leave_PLL_save_mode(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2528, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Leave_PLL_save_mode(v1, v2)
#endif
#define UL1I_TRC_Leave_PLL_save_mode_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2528, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Enter_PLL_save_mode(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2628, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Enter_PLL_save_mode(v1, v2)
#endif
#define UL1I_TRC_Enter_PLL_save_mode_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2628, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RestartRACH_ongoing(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2728, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RestartRACH_ongoing(v1, v2)
#endif
#define UL1I_TRC_RestartRACH_ongoing_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2728, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SetResourceDoneFrame(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2828, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SetResourceDoneFrame(v1, v2, v3, v4)
#endif
#define UL1I_TRC_SetResourceDoneFrame_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2828, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UseCountUpdate(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2928, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UseCountUpdate(v1, v2, v3)
#endif
#define UL1I_TRC_UseCountUpdate_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2928, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UseCountDisable(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UseCountDisable(v1, v2)
#endif
#define UL1I_TRC_UseCountDisable_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1_RTB_Reserved_Frames(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_UL1_RTB_Reserved_Frames(v1, v2, v3)
#endif
#define UL1I_TRC_UL1_RTB_Reserved_Frames_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1T_TRC_RSSI_SNIFFER1(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_RSSI_SNIFFER1(v1, v2)
#endif
#define UL1T_TRC_RSSI_SNIFFER1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_RSSI_SNIFFER2(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D28, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_RSSI_SNIFFER2(v1, v2)
#endif
#define UL1T_TRC_RSSI_SNIFFER2_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D28, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_RSSI_SNIFFER3(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_RSSI_SNIFFER3(v1, v2, v3)
#endif
#define UL1T_TRC_RSSI_SNIFFER3_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RSSI_SNIFFER_status(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2F28, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define UL1I_TRC_RSSI_SNIFFER_status(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_RSSI_SNIFFER_status_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2F28, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FrameTick(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3028, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v5));\
	} while(0)
#else
	#define UL1I_TRC_FrameTick(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_FrameTick_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3028, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_LST_RTR_Sync(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3128, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_LST_RTR_Sync(v1, v2, v3, v4)
#endif
#define UL1I_TRC_LST_RTR_Sync_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3128, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_QueueFunction(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3228, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_QueueFunction(v1, v2)
#endif
#define UL1I_TRC_QueueFunction_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3228, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RemoveQueueFunction(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3328, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_RemoveQueueFunction(v1, v2)
#endif
#define UL1I_TRC_RemoveQueueFunction_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3328, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_GetBSFrameNumber(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3428, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4), (long)(v6));\
	} while(0)
#else
	#define UL1I_TRC_GetBSFrameNumber(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_GetBSFrameNumber_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3428, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_GeminiMode(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3528, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_GeminiMode(v1, v2)
#endif
#define UL1T_TRC_GeminiMode_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3528, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_PeerGeminiMode(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3628, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_PeerGeminiMode(v1, v2)
#endif
#define UL1T_TRC_PeerGeminiMode_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3628, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_GeminiMode(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3728, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_GeminiMode(v1, v2)
#endif
#define UL1I_TRC_GeminiMode_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3728, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_ChannelPriority(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3828, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_ChannelPriority(v1, v2)
#endif
#define UL1T_TRC_ChannelPriority_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3828, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_ChannelPriority(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3928, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ChannelPriority(v1, v2, v3)
#endif
#define UL1I_TRC_ChannelPriority_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3928, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FSGapStart(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A28, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FSGapStart(v1)
#endif
#define UL1I_TRC_FSGapStart_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A28, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FSGapStop(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B28, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FSGapStop(v1)
#endif
#define UL1I_TRC_FSGapStop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B28, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FSGapInfo_NoStartTimer(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C28, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_FSGapInfo_NoStartTimer(v1, v2)
#endif
#define UL1I_TRC_FSGapInfo_NoStartTimer_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C28, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FSGapInfo_StartAfter(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FSGapInfo_StartAfter(v1, v2, v3)
#endif
#define UL1I_TRC_FSGapInfo_StartAfter_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FSGapLength(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3E28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FSGapLength(v1, v2, v3)
#endif
#define UL1I_TRC_FSGapLength_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3E28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapStart(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapStart(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CMCSGapStart_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapStop(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4028, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapStop(v1, v2, v3)
#endif
#define UL1I_TRC_CMCSGapStop_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4028, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapTimerStart(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4128, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapTimerStart(v1, v2)
#endif
#define UL1I_TRC_CMCSGapTimerStart_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4128, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapInfo_NoStartTimer(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4228, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapInfo_NoStartTimer(v1, v2)
#endif
#define UL1I_TRC_CMCSGapInfo_NoStartTimer_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4228, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapInfo_StartAfter(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4328, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapInfo_StartAfter(v1, v2, v3)
#endif
#define UL1I_TRC_CMCSGapInfo_StartAfter_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4328, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapLength(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4428, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapLength(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CMCSGapLength_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4428, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGap_overlapBCH(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4528, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGap_overlapBCH(v1, v2)
#endif
#define UL1I_TRC_CMCSGap_overlapBCH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4528, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FCMGapStop(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4628, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FCMGapStop(v1)
#endif
#define UL1I_TRC_FCMGapStop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4628, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxSuspend(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4728, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_RxTxSuspend(v1, v2, v3)
#endif
#define UL1I_TRC_RxTxSuspend_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4728, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxRelease(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4828, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_RxTxRelease(v1, v2, v3)
#endif
#define UL1I_TRC_RxTxRelease_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4828, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxReserve(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4928, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_RxTxReserve(v1, v2, v3)
#endif
#define UL1I_TRC_RxTxReserve_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4928, (unsigned char)(v1), (char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_Check2GTimer(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A28, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_Check2GTimer(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_Check2GTimer_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A28, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_Check2GReservation(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B28, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_Check2GReservation(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_Check2GReservation_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B28, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_CheckHWResource(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C28, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_CheckHWResource(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_CheckHWResource_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C28, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_CheckHWPartial(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4D28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_CheckHWPartial(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_CheckHWPartial_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4D28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_AdjustPri_InternalHigh(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_AdjustPri_InternalHigh(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_AdjustPri_InternalHigh_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_AdjustPri_CheckBCH(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_AdjustPri_CheckBCH(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_AdjustPri_CheckBCH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_AdjustPri_SetPriHigh(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5028, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_AdjustPri_SetPriHigh(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_AdjustPri_SetPriHigh_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5028, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_AdjustPri_geminiPri(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5128, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_AdjustPri_geminiPri(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_AdjustPri_geminiPri_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5128, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_Resume_Priority(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5228, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_Resume_Priority(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_Resume_Priority_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5228, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_RxStart(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5328, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_RxStart(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_RxStart_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5328, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_TxStart(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5428, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_TxStart(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_TxStart_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5428, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_RxStop(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5528, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_RxStop(v1)
#endif
#define UL1I_TRC_RxTxInfo_RxStop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5528, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_TxStop(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5628, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_TxStop(v1)
#endif
#define UL1I_TRC_RxTxInfo_TxStop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5628, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_rtb_been_reserved(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5728, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_rtb_been_reserved(v1)
#endif
#define UL1I_TRC_RxTxInfo_rtb_been_reserved_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5728, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_Change_Rx_reserved(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5828, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_Change_Rx_reserved(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_Change_Rx_reserved_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5828, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_Change_Tx_reserved(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5928, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_Change_Tx_reserved(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_Change_Tx_reserved_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5928, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxSetPriority(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A28, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxSetPriority(v1, v2, v3, v4)
#endif
#define UL1I_TRC_RxTxSetPriority_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A28, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxDCH_modify_event(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5B28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxDCH_modify_event(v1, v2, v3)
#endif
#define UL1I_TRC_RxTxDCH_modify_event_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5B28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxUpdateStarvation(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C28, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxUpdateStarvation(v1, v2, v3)
#endif
#define UL1I_TRC_RxTxUpdateStarvation_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C28, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxStopStarvation(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D28, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxStopStarvation(v1)
#endif
#define UL1I_TRC_RxTxStopStarvation_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D28, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxAdjustPriStarvation(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5E28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxAdjustPriStarvation(v1, v2)
#endif
#define UL1I_TRC_RxTxAdjustPriStarvation_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5E28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxSlotSuspend(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x5F28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define UL1I_TRC_RxTxSlotSuspend(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1I_TRC_RxTxSlotSuspend_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_2S(0x5F28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPCTxStatus(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6028, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CPCTxStatus(v1, v2)
#endif
#define UL1I_TRC_CPCTxStatus_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6028, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPCTxCalInfo(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6128, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CPCTxCalInfo(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_CPCTxCalInfo_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6128, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPCTxRelease(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6228, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CPCTxRelease(v1, v2)
#endif
#define UL1I_TRC_CPCTxRelease_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6228, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPCTxSlotSuspend(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6328, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_CPCTxSlotSuspend(v1, v2, v3)
#endif
#define UL1I_TRC_CPCTxSlotSuspend_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6328, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPCTxNoSync(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6428, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_CPCTxNoSync(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CPCTxNoSync_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6428, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SetSimIndex(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6528, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SetSimIndex(v1, v2, v3, v4)
#endif
#define UL1I_TRC_SetSimIndex_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6528, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RxTxInfo_CheckInterSIMUMTSTimer(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6628, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_CheckInterSIMUMTSTimer(v1, v2)
#endif
#define UL1I_TRC_RxTxInfo_CheckInterSIMUMTSTimer_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6628, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RxTxInfo_ConflictWithInterSIMPCH(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6728, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_ConflictWithInterSIMPCH(v1, v2, v3)
#endif
#define UL1I_TRC_RxTxInfo_ConflictWithInterSIMPCH_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6728, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RxTxInfo_NoConflictWithInterSIMPCH(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6828, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_NoConflictWithInterSIMPCH(v1, v2, v3)
#endif
#define UL1I_TRC_RxTxInfo_NoConflictWithInterSIMPCH_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6828, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RxTxInfo_CheckInterSIMUMTSResource(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6928, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_CheckInterSIMUMTSResource(v1, v2, v3)
#endif
#define UL1I_TRC_RxTxInfo_CheckInterSIMUMTSResource_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x6928, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_InterSIMUMTSUseCountUpdate(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6A28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_InterSIMUMTSUseCountUpdate(v1, v2, v3)
#endif
#define UL1I_TRC_InterSIMUMTSUseCountUpdate_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6A28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_InterSIMUMTSUseCountDisable(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6B28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_InterSIMUMTSUseCountDisable(v1, v2)
#endif
#define UL1I_TRC_InterSIMUMTSUseCountDisable_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6B28, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_InterSIMUMTSResourceReservation(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6C28, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_InterSIMUMTSResourceReservation(v1, v2, v3, v4)
#endif
#define UL1I_TRC_InterSIMUMTSResourceReservation_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6C28, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_InterSIMUMTSResourceLockInfo(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6D28, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_InterSIMUMTSResourceLockInfo(v1, v2, v3, v4)
#endif
#define UL1I_TRC_InterSIMUMTSResourceLockInfo_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6D28, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ResourceCheckPreemptionAttempt(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6E28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ResourceCheckPreemptionAttempt(v1, v2, v3)
#endif
#define UL1I_TRC_ResourceCheckPreemptionAttempt_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6E28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ExtraInterSIMUMTSResource(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6F28, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_ExtraInterSIMUMTSResource(v1, v2)
#endif
#define UL1I_TRC_ExtraInterSIMUMTSResource_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6F28, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CheckHigherPrioritySIM(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7028, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CheckHigherPrioritySIM(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_CheckHigherPrioritySIM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7028, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CheckHigherPriorityTimer(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7128, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CheckHigherPriorityTimer(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_CheckHigherPriorityTimer_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7128, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UpdateSIMWeightRecord(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7228, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UpdateSIMWeightRecord(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_UpdateSIMWeightRecord_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7228, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CreateSIMWeightRecord(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7328, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CreateSIMWeightRecord(v1, v2)
#endif
#define UL1I_TRC_CreateSIMWeightRecord_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7328, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DisplaySIMWeightRecord(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7428, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DisplaySIMWeightRecord(v1, v2)
#endif
#define UL1I_TRC_DisplaySIMWeightRecord_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7428, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FindTimerOtherSIM(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7528, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FindTimerOtherSIM(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_FindTimerOtherSIM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7528, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FindTimerDelayOtherSIM(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x7628, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v5), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FindTimerDelayOtherSIM(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1I_TRC_FindTimerDelayOtherSIM_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x7628, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v5), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ConflictWithPCHOtherSIM(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7728, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ConflictWithPCHOtherSIM(v1, v2, v3)
#endif
#define UL1I_TRC_ConflictWithPCHOtherSIM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7728, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DelayToClosestPCHOtherSIM(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7828, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DelayToClosestPCHOtherSIM(v1, v2, v3)
#endif
#define UL1I_TRC_DelayToClosestPCHOtherSIM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7828, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1C_PRI3_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct1(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct2(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct3(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct4(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct5(unsigned char v1, short v2);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct6(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct7(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1T_TRC_TGPS_MeasControl(unsigned char v1, short v2, short v3, char v4, short v5);
void L1TRC_Send_UL1I_TRC_TGPS_MeasControl(unsigned char v1, char v2, short v3, char v4, char v5);
void L1TRC_Send_UL1T_TRC_TGPS_Act(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_TGPS_Frame(unsigned char v1, short v2, unsigned short v3, char v4, char v5, char v6);
void L1TRC_Send_UL1I_TRC_TGPS_Kill_Pending_MC(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_TGPS_Status(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_TGPS_Frame_Type(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_TGPS_Check_InterF(unsigned char v1, short v2, unsigned short v3, char v4, char v5);
void L1TRC_Send_UL1I_TRC_TGPS_Frame_Dummy(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_TGPS_Not_Allow_Recons(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_TGPS_Frame_Len(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_TGPS_MaxTTI(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_TGPS_Overlap_Reconfig(unsigned char v1, short v2);
void L1TRC_Send_UL1T_TRC_TGPS_TGCFN_MODIFY(unsigned char v1, short v2);
void L1TRC_Send_UL1T_TRC_TGPS_ConfigUpdate(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_TGPS_ConfigUpdate(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_RACH_offset(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_Keep_Awake(unsigned char v1);
void L1TRC_Send_UL1I_TRC_VFD_RecoverFrame(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1I_TRC_VFD_Status_Delay_VFD_timer(unsigned char v1);
void L1TRC_Send_UL1I_TRC_VFD_Status_Recovery_stage2(unsigned char v1);
void L1TRC_Send_UL1I_TRC_AssignGAPDBG(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_DM_PM_Done(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_DM_PM_Tick(unsigned char v1, char v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_DM_Set_GSM_Gap_Type(unsigned char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_UL1I_TRC_Post_Fail_InSync_Immed(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_tgprc_modify_to_zero(unsigned char v1);
void L1TRC_Send_UL1I_TRC_HHO_Query_Timing_fail(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_QueueFunctionOverflow(unsigned char v1);
void L1TRC_Send_UL1I_TRC_CCM_timer_delay_type(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_Leave_PLL_save_mode(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_Enter_PLL_save_mode(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_RestartRACH_ongoing(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_SetResourceDoneFrame(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_UseCountUpdate(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_UseCountDisable(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_UL1_RTB_Reserved_Frames(unsigned char v1, short v2, long v3);
void L1TRC_Send_UL1T_TRC_RSSI_SNIFFER1(unsigned char v1, short v2);
void L1TRC_Send_UL1T_TRC_RSSI_SNIFFER2(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_RSSI_SNIFFER3(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_RSSI_SNIFFER_status(unsigned char v1, char v2, char v3, char v4, long v5);
void L1TRC_Send_UL1I_TRC_FrameTick(unsigned char v1, short v2, long v3, short v4, long v5, short v6);
void L1TRC_Send_UL1I_TRC_LST_RTR_Sync(unsigned char v1, short v2, unsigned short v3, char v4);
void L1TRC_Send_UL1I_TRC_QueueFunction(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1I_TRC_RemoveQueueFunction(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1I_TRC_GetBSFrameNumber(unsigned char v1, short v2, short v3, long v4, short v5, long v6);
void L1TRC_Send_UL1T_TRC_GeminiMode(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_PeerGeminiMode(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_GeminiMode(unsigned char v1, char v2);
void L1TRC_Send_UL1T_TRC_ChannelPriority(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_ChannelPriority(unsigned char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_FSGapStart(unsigned char v1);
void L1TRC_Send_UL1I_TRC_FSGapStop(unsigned char v1);
void L1TRC_Send_UL1I_TRC_FSGapInfo_NoStartTimer(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_FSGapInfo_StartAfter(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_FSGapLength(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_CMCSGapStart(unsigned char v1, char v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_CMCSGapStop(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_CMCSGapTimerStart(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_CMCSGapInfo_NoStartTimer(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_CMCSGapInfo_StartAfter(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_CMCSGapLength(unsigned char v1, char v2, long v3, short v4);
void L1TRC_Send_UL1I_TRC_CMCSGap_overlapBCH(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_FCMGapStop(unsigned char v1);
void L1TRC_Send_UL1I_TRC_RxTxSuspend(unsigned char v1, char v2, unsigned long v3);
void L1TRC_Send_UL1I_TRC_RxTxRelease(unsigned char v1, char v2, unsigned long v3);
void L1TRC_Send_UL1I_TRC_RxTxReserve(unsigned char v1, char v2, unsigned long v3);
void L1TRC_Send_UL1I_TRC_RxTxInfo_Check2GTimer(unsigned char v1, long v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_Check2GReservation(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_CheckHWResource(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_CheckHWPartial(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_AdjustPri_InternalHigh(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_AdjustPri_CheckBCH(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_AdjustPri_SetPriHigh(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_AdjustPri_geminiPri(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_Resume_Priority(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_RxStart(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_TxStart(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_RxStop(unsigned char v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_TxStop(unsigned char v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_rtb_been_reserved(unsigned char v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_Change_Rx_reserved(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_Change_Tx_reserved(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_RxTxSetPriority(unsigned char v1, char v2, char v3, short v4);
void L1TRC_Send_UL1I_TRC_RxTxDCH_modify_event(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_RxTxUpdateStarvation(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_RxTxStopStarvation(unsigned char v1);
void L1TRC_Send_UL1I_TRC_RxTxAdjustPriStarvation(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_RxTxSlotSuspend(unsigned char v1, char v2, short v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_UL1I_TRC_CPCTxStatus(unsigned char v1, char v2);
void L1TRC_Send_UL1I_TRC_CPCTxCalInfo(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_CPCTxRelease(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_CPCTxSlotSuspend(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1I_TRC_CPCTxNoSync(unsigned char v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1I_TRC_SetSimIndex(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_RxTxInfo_CheckInterSIMUMTSTimer(unsigned char v1, long v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_ConflictWithInterSIMPCH(unsigned char v1, long v2, unsigned long v3);
void L1TRC_Send_UL1I_TRC_RxTxInfo_NoConflictWithInterSIMPCH(unsigned char v1, long v2, unsigned long v3);
void L1TRC_Send_UL1I_TRC_RxTxInfo_CheckInterSIMUMTSResource(unsigned char v1, long v2, unsigned long v3);
void L1TRC_Send_UL1I_TRC_InterSIMUMTSUseCountUpdate(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_InterSIMUMTSUseCountDisable(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_InterSIMUMTSResourceReservation(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_InterSIMUMTSResourceLockInfo(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_ResourceCheckPreemptionAttempt(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_ExtraInterSIMUMTSResource(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1I_TRC_CheckHigherPrioritySIM(unsigned char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_CheckHigherPriorityTimer(unsigned char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_UpdateSIMWeightRecord(unsigned char v1, char v2, short v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_CreateSIMWeightRecord(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_DisplaySIMWeightRecord(unsigned char v1, short v2);
void L1TRC_Send_UL1I_TRC_FindTimerOtherSIM(unsigned char v1, char v2, short v3, char v4, short v5);
void L1TRC_Send_UL1I_TRC_FindTimerDelayOtherSIM(unsigned char v1, char v2, short v3, short v4, char v5, short v6, char v7, short v8);
void L1TRC_Send_UL1I_TRC_ConflictWithPCHOtherSIM(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_DelayToClosestPCHOtherSIM(unsigned char v1, short v2, short v3);

void Set_UL1C_PRI3_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1C_PRI3()	(UL1C_PRI3_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_L()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_L()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_L()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_Frame_H()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_M()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_M()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_M()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_H()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[2]&0x08)!=0))
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct1()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct2()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct3()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct4()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct5()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct6()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct7()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_MeasControl()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_MeasControl()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Act()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Frame()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Kill_Pending_MC()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Status()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Frame_Type()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Check_InterF()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Frame_Dummy()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Not_Allow_Recons()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Frame_Len()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_MaxTTI()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Overlap_Reconfig()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_TGCFN_MODIFY()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_ConfigUpdate()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_ConfigUpdate()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_RACH_offset()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_Keep_Awake()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_VFD_RecoverFrame()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_VFD_Status_Delay_VFD_timer()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_L()
#define ChkL1MsgFltr_UL1I_TRC_VFD_Status_Recovery_stage2()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_L()
#define ChkL1MsgFltr_UL1I_TRC_AssignGAPDBG()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_PM_Done()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_PM_Tick()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Set_GSM_Gap_Type()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_Post_Fail_InSync_Immed()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_tgprc_modify_to_zero()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_HHO_Query_Timing_fail()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_QueueFunctionOverflow()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_timer_delay_type()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_Leave_PLL_save_mode()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_Enter_PLL_save_mode()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_RestartRACH_ongoing()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_SetResourceDoneFrame()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_UseCountUpdate()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_UseCountDisable()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1_RTB_Reserved_Frames()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1T_TRC_RSSI_SNIFFER1()	ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_H()
#define ChkL1MsgFltr_UL1T_TRC_RSSI_SNIFFER2()	ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_H()
#define ChkL1MsgFltr_UL1T_TRC_RSSI_SNIFFER3()	ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_H()
#define ChkL1MsgFltr_UL1I_TRC_RSSI_SNIFFER_status()	ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_H()
#define ChkL1MsgFltr_UL1I_TRC_FrameTick()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Frame_H()
#define ChkL1MsgFltr_UL1I_TRC_LST_RTR_Sync()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Frame_H()
#define ChkL1MsgFltr_UL1I_TRC_QueueFunction()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Frame_H()
#define ChkL1MsgFltr_UL1I_TRC_RemoveQueueFunction()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Frame_H()
#define ChkL1MsgFltr_UL1I_TRC_GetBSFrameNumber()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Frame_H()
#define ChkL1MsgFltr_UL1T_TRC_GeminiMode()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1T_TRC_PeerGeminiMode()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_GeminiMode()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1T_TRC_ChannelPriority()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_ChannelPriority()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FSGapStart()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FSGapStop()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FSGapInfo_NoStartTimer()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FSGapInfo_StartAfter()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FSGapLength()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapStart()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapStop()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapTimerStart()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapInfo_NoStartTimer()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapInfo_StartAfter()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapLength()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGap_overlapBCH()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FCMGapStop()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxSuspend()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxRelease()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxReserve()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_Check2GTimer()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_Check2GReservation()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_CheckHWResource()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_CheckHWPartial()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_AdjustPri_InternalHigh()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_AdjustPri_CheckBCH()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_AdjustPri_SetPriHigh()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_AdjustPri_geminiPri()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_Resume_Priority()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_RxStart()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_TxStart()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_RxStop()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_TxStop()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_rtb_been_reserved()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_Change_Rx_reserved()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_Change_Tx_reserved()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxSetPriority()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxDCH_modify_event()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxUpdateStarvation()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxStopStarvation()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxAdjustPriStarvation()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxSlotSuspend()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CPCTxStatus()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CPCTxCalInfo()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CPCTxRelease()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CPCTxSlotSuspend()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CPCTxNoSync()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_SetSimIndex()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_CheckInterSIMUMTSTimer()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_ConflictWithInterSIMPCH()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_NoConflictWithInterSIMPCH()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_CheckInterSIMUMTSResource()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_InterSIMUMTSUseCountUpdate()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_InterSIMUMTSUseCountDisable()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_InterSIMUMTSResourceReservation()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_InterSIMUMTSResourceLockInfo()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_ResourceCheckPreemptionAttempt()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_ExtraInterSIMUMTSResource()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_CheckHigherPrioritySIM()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_CheckHigherPriorityTimer()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_UpdateSIMWeightRecord()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_CreateSIMWeightRecord()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_DisplaySIMWeightRecord()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_FindTimerOtherSIM()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_FindTimerDelayOtherSIM()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_ConflictWithPCHOtherSIM()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()
#define ChkL1MsgFltr_UL1I_TRC_DelayToClosestPCHOtherSIM()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI_LW_H()


#endif
