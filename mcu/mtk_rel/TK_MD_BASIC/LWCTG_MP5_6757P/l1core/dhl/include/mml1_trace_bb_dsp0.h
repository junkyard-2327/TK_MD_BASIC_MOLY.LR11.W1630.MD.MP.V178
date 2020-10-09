#ifndef L1TRC_MML1_BB_DSP0_DEF_H
#define L1TRC_MML1_BB_DSP0_DEF_H

/******************************/
/* String category definition */
/******************************/
#define MML1_BB_TRC_STR_DSP_IDX(v1)  (unsigned char)(v1+0)
#define MML1_BB_TRC_STR_DSP_UBIN(v1)  (unsigned char)(v1+2)
#define MML1_BB_TRC_STR_BRP_WFI_DISPATCH_IDX(v1)  (unsigned char)(v1+4)
#define MML1_BB_TRC_STR_FEC_WFI_DISPATCH_IDX(v1)  (unsigned char)(v1+11)
#define MML1_BB_TRC_STR_MD32_ACTION(v1)  (unsigned char)(v1+14)
#define MML1_BB_TRC_STR_MD32_BIN_TYPE(v1)  (unsigned char)(v1+16)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define MML1_BB_TRC_DSP_DUMMY_WFI_DISPATCH(v1) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0047, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_DUMMY_WFI_DISPATCH(v1)
#endif
#define MML1_BB_TRC_DSP_DUMMY_WFI_DISPATCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0047, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MML1_BB_TRC_DSP_SET_BRP_WFI_DISPATCH(v1) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0147, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_SET_BRP_WFI_DISPATCH(v1)
#endif
#define MML1_BB_TRC_DSP_SET_BRP_WFI_DISPATCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0147, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MML1_BB_TRC_DSP_SET_FEC_WFI_DISPATCH(v1) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0247, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_SET_FEC_WFI_DISPATCH(v1)
#endif
#define MML1_BB_TRC_DSP_SET_FEC_WFI_DISPATCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0247, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MML1_BB_TRC_DSP_HANDLE_WFI_IRQ(v1, v2, v3) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0347, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_HANDLE_WFI_IRQ(v1, v2, v3)
#endif
#define MML1_BB_TRC_DSP_HANDLE_WFI_IRQ_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0347, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define MML1_BB_TRC_DSP_FEC_PMDM_ALLOC(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0447, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_FEC_PMDM_ALLOC(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define MML1_BB_TRC_DSP_FEC_PMDM_ALLOC_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x0447, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MML1_BB_TRC_DSP_BACKUP_INFO_NOW(v1, v2, v3, v4, v5) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0547, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_BACKUP_INFO_NOW(v1, v2, v3, v4, v5)
#endif
#define MML1_BB_TRC_DSP_BACKUP_INFO_NOW_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0547, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MML1_BB_TRC_DSP_UPD_BOOT_INFO(v1, v2, v3) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0647, (unsigned char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_UPD_BOOT_INFO(v1, v2, v3)
#endif
#define MML1_BB_TRC_DSP_UPD_BOOT_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0647, (unsigned char)(v2), (char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MML1_BB_TRC_DSP_UPD_BACKUP_INFO(v1, v2, v3) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0747, (unsigned char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_UPD_BACKUP_INFO(v1, v2, v3)
#endif
#define MML1_BB_TRC_DSP_UPD_BACKUP_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0747, (unsigned char)(v2), (char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MML1_BB_TRC_DSP_UPD_PMDM_INFO(v1, v2, v3) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0847, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_UPD_PMDM_INFO(v1, v2, v3)
#endif
#define MML1_BB_TRC_DSP_UPD_PMDM_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0847, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define MML1_BB_TRC_DSP_UPD_PWR_INFO(v1, v2, v3, v4) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0947, (unsigned char)(v1), (char)(v3)), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_UPD_PWR_INFO(v1, v2, v3, v4)
#endif
#define MML1_BB_TRC_DSP_UPD_PWR_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0947, (unsigned char)(v1), (char)(v3)), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MML1_BB_TRC_DSP_UPD_DEMAND_INFO(v1, v2, v3, v4) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A47, (unsigned char)(v1), (char)(v3)), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_UPD_DEMAND_INFO(v1, v2, v3, v4)
#endif
#define MML1_BB_TRC_DSP_UPD_DEMAND_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0A47, (unsigned char)(v1), (char)(v3)), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define MML1_BB_TRC_DSP_CLR_BOOT_DONE(v1) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B47, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_CLR_BOOT_DONE(v1)
#endif
#define MML1_BB_TRC_DSP_CLR_BOOT_DONE_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B47, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define MML1_BB_TRC_DSP_SET_ZI_REGION(v1, v2, v3) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C47, (unsigned char)(v1), (char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_SET_ZI_REGION(v1, v2, v3)
#endif
#define MML1_BB_TRC_DSP_SET_ZI_REGION_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C47, (unsigned char)(v1), (char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MML1_BB_TRC_DSP_SET_HW_CG(v1, v2, v3) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D47, (unsigned char)(v1), (char)(v3)), (unsigned long)(v2));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_SET_HW_CG(v1, v2, v3)
#endif
#define MML1_BB_TRC_DSP_SET_HW_CG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D47, (unsigned char)(v1), (char)(v3)), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define MML1_BB_TRC_DSP_MD32_ACTION(v1, v2) do {\
		if(MML1_BB_DSP0_Trace_Filter[0]==1 && (MML1_BB_DSP0_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E47, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define MML1_BB_TRC_DSP_MD32_ACTION(v1, v2)
#endif
#define MML1_BB_TRC_DSP_MD32_ACTION_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E47, (unsigned char)(v1), (unsigned char)(v2)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char MML1_BB_DSP0_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_MML1_BB_TRC_DSP_DUMMY_WFI_DISPATCH(unsigned char v1);
void L1TRC_Send_MML1_BB_TRC_DSP_SET_BRP_WFI_DISPATCH(unsigned char v1);
void L1TRC_Send_MML1_BB_TRC_DSP_SET_FEC_WFI_DISPATCH(unsigned char v1);
void L1TRC_Send_MML1_BB_TRC_DSP_HANDLE_WFI_IRQ(unsigned char v1, char v2, unsigned short v3);
void L1TRC_Send_MML1_BB_TRC_DSP_FEC_PMDM_ALLOC(char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_MML1_BB_TRC_DSP_BACKUP_INFO_NOW(unsigned char v1, char v2, unsigned long v3, char v4, unsigned long v5);
void L1TRC_Send_MML1_BB_TRC_DSP_UPD_BOOT_INFO(unsigned long v1, unsigned char v2, char v3);
void L1TRC_Send_MML1_BB_TRC_DSP_UPD_BACKUP_INFO(unsigned long v1, unsigned char v2, char v3);
void L1TRC_Send_MML1_BB_TRC_DSP_UPD_PMDM_INFO(unsigned char v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_MML1_BB_TRC_DSP_UPD_PWR_INFO(unsigned char v1, unsigned long v2, char v3, unsigned long v4);
void L1TRC_Send_MML1_BB_TRC_DSP_UPD_DEMAND_INFO(unsigned char v1, unsigned long v2, char v3, unsigned long v4);
void L1TRC_Send_MML1_BB_TRC_DSP_CLR_BOOT_DONE(unsigned long v1);
void L1TRC_Send_MML1_BB_TRC_DSP_SET_ZI_REGION(unsigned char v1, unsigned long v2, char v3);
void L1TRC_Send_MML1_BB_TRC_DSP_SET_HW_CG(unsigned char v1, unsigned long v2, char v3);
void L1TRC_Send_MML1_BB_TRC_DSP_MD32_ACTION(unsigned char v1, unsigned char v2);

void Set_MML1_BB_DSP0_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_MML1_BB_DSP0()	(MML1_BB_DSP0_Trace_Filter[0]==1)
#define ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_H()	(ChkL1ModFltr_MML1_BB_DSP0()&&((MML1_BB_DSP0_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_M()	(ChkL1ModFltr_MML1_BB_DSP0()&&((MML1_BB_DSP0_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_L()	(ChkL1ModFltr_MML1_BB_DSP0()&&((MML1_BB_DSP0_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_DUMMY_WFI_DISPATCH()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_H()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_SET_BRP_WFI_DISPATCH()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_M()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_SET_FEC_WFI_DISPATCH()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_M()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_HANDLE_WFI_IRQ()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_M()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_FEC_PMDM_ALLOC()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_H()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_BACKUP_INFO_NOW()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_M()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_UPD_BOOT_INFO()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_M()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_UPD_BACKUP_INFO()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_L()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_UPD_PMDM_INFO()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_M()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_UPD_PWR_INFO()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_L()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_UPD_DEMAND_INFO()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_M()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_CLR_BOOT_DONE()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_H()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_SET_ZI_REGION()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_M()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_SET_HW_CG()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_H()
#define ChkL1MsgFltr_MML1_BB_TRC_DSP_MD32_ACTION()	ChkL1ClsFltr_MML1_BB_DSP0_MML1_BB_TRC_CLS_DSP_H()


#endif
