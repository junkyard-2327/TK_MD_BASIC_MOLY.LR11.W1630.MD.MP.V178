#ifndef L1TRC_EL1D_COSIM_DEF_H
#define L1TRC_EL1D_COSIM_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_COSIM_SUCCESS(v1, v2, v3) do {\
		if(EL1D_COSIM_Trace_Filter[0]==1 && (EL1D_COSIM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x003F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_COSIM_SUCCESS(v1, v2, v3)
#endif
#define EL1D_TRC_COSIM_SUCCESS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x003F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define EL1D_TRC_COSIM_FAIL(v1, v2, v3) do {\
		if(EL1D_COSIM_Trace_Filter[0]==1 && (EL1D_COSIM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x013F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define EL1D_TRC_COSIM_FAIL(v1, v2, v3)
#endif
#define EL1D_TRC_COSIM_FAIL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x013F, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_COSIM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_COSIM_SUCCESS(short v1, short v2, short v3);
void L1TRC_Send_EL1D_TRC_COSIM_FAIL(short v1, short v2, short v3);

void Set_EL1D_COSIM_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_COSIM()	(EL1D_COSIM_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_COSIM_EL1D_COSIM_H()	(ChkL1ModFltr_EL1D_COSIM()&&((EL1D_COSIM_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_EL1D_TRC_COSIM_SUCCESS()	ChkL1ClsFltr_EL1D_COSIM_EL1D_COSIM_H()
#define ChkL1MsgFltr_EL1D_TRC_COSIM_FAIL()	ChkL1ClsFltr_EL1D_COSIM_EL1D_COSIM_H()


#endif
