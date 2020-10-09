#ifndef L1TRC_EL1D_CSIF_DEF_H
#define L1TRC_EL1D_CSIF_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1D_TRC_STR_CSIF_IRQERROR(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1D_TRC_CSIF_IRQERR_H(v1) do {\
		if(EL1D_CSIF_Trace_Filter[0]==1 && (EL1D_CSIF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0034, (short)(v1)));\
	} while(0)
#else
	#define EL1D_TRC_CSIF_IRQERR_H(v1)
#endif
#define EL1D_TRC_CSIF_IRQERR_H_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0034, (short)(v1)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1D_CSIF_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1D_TRC_CSIF_IRQERR_H(short v1);

void Set_EL1D_CSIF_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1D_CSIF()	(EL1D_CSIF_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1D_CSIF_EL1D_TRC_CLS_CSIF_H()	(ChkL1ModFltr_EL1D_CSIF()&&((EL1D_CSIF_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1D_CSIF_EL1D_TRC_CLS_CSIF_M()	(ChkL1ModFltr_EL1D_CSIF()&&((EL1D_CSIF_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1D_CSIF_EL1D_TRC_CLS_CSIF_L()	(ChkL1ModFltr_EL1D_CSIF()&&((EL1D_CSIF_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_EL1D_TRC_CSIF_IRQERR_H()	ChkL1ClsFltr_EL1D_CSIF_EL1D_TRC_CLS_CSIF_H()


#endif
