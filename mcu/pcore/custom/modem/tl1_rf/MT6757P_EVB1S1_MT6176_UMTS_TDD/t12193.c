
#define _T12193_C_

#include "kal_public_api.h"
#include "tl1d_custom_drdi.h"
#include "tl1d_custom_rf.h"
#include "tl1d_custom_mipi.h"
#include "t12193.h"

#if IS_MML1_DRDI_ENABLE
   #if TL1_CUSTOM_TOTAL_SET_NUMS > 0 
   /*Include build for Set0 custom folder*/ 
#include "DRDI/Set0/tl1d_custom_rf.h" 
#include "DRDI/Set0/tl1d_custom_mipi.h" 
#include "DRDI/Set0/t12193.h" 
   #endif 
   #if TL1_CUSTOM_TOTAL_SET_NUMS > 1 
   /*Include build for Set1 custom folder*/ 
#include "DRDI/Set1/tl1d_custom_rf.h" 
#include "DRDI/Set1/tl1d_custom_mipi.h" 
#include "DRDI/Set1/t12193.h"
   #endif 
   #if TL1_CUSTOM_TOTAL_SET_NUMS > 2 
   /*Include build for Set0 custom folder*/ 
#include "DRDI/Set2/tl1d_custom_rf.h" 
#include "DRDI/Set2/tl1d_custom_mipi.h" 
#include "DRDI/Set2/t12193.h"
   #endif 
   #if TL1_CUSTOM_TOTAL_SET_NUMS > 3 
   /*Include build for Set1 custom folder*/ 
#include "DRDI/Set3/tl1d_custom_rf.h" 
#include "DRDI/Set3/tl1d_custom_mipi.h" 
#include "DRDI/Set3/t12193.h"
   #endif
   #if TL1_CUSTOM_TOTAL_SET_NUMS > 4 
   /*Include build for Set0 custom folder*/ 
#include "DRDI/Set4/tl1d_custom_rf.h" 
#include "DRDI/Set4/tl1d_custom_mipi.h" 
#include "DRDI/Set4/t12193.h"
   #endif 
   #if TL1_CUSTOM_TOTAL_SET_NUMS > 5 
   /*Include build for Set1 custom folder*/ 
#include "DRDI/Set5/tl1d_custom_rf.h" 
#include "DRDI/Set5/tl1d_custom_mipi.h" 
#include "DRDI/Set5/t12193.h"
   #endif
   #if TL1_CUSTOM_TOTAL_SET_NUMS > 6 
   /*Include build for Set0 custom folder*/ 
#include "DRDI/Set6/tl1d_custom_rf.h" 
#include "DRDI/Set6/tl1d_custom_mipi.h" 
#include "DRDI/Set6/t12193.h"
   #endif 
   #if TL1_CUSTOM_TOTAL_SET_NUMS > 7 
   /*Include build for Set1 custom folder*/ 
#include "DRDI/Set7/tl1d_custom_rf.h" 
#include "DRDI/Set7/tl1d_custom_mipi.h" 
#include "DRDI/Set7/t12193.h"
   #endif
   #if TL1_CUSTOM_TOTAL_SET_NUMS > 8 
   /*Include build for Set1 custom folder*/ 
#include "DRDI/Set8/tl1d_custom_rf.h" 
#include "DRDI/Set8/tl1d_custom_mipi.h" 
#include "DRDI/Set8/t12193.h"
   #endif
#endif 
 

kal_uint16  const NVRAM_EF_AST_TL1_TEMP_DAC_DATA_DEFAULT[]= 
{
    //-10, 5, 20, 35, 55, 70, 85, 90
    278, 326, 375, 423, 488, 536, 584, 601
};

kal_uint16 const NVRAM_EF_AST_TL1_AFC_DATA_DEFAULT[]= 
{
    4096,   

    1272   

};

kal_int16 const NVRAM_EF_AST_TL1_PATHLOSS_33_35_37_39_DEFAULT[]= 
{

   9420,9440,9460,9480,9500,9520,9540,9560,9580,9601,0,0,0,0,0,
   57,50,57,51,56,67,51,52,51,59,0,0,0,0,0, 36,23,24,27,31,34,35,34,36,37,0,0,0,0,0, 57,65,59,61,57,59,57,53,62,71,0,0,0,0,0,
   0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 

};

kal_int16 const NVRAM_EF_AST_TL1_PATHLOSS_34_DEFAULT[]= 
{
   10070,10087,10104,10122,0,0,0,0,0,0,0,0,0,0,0,
   57,50,49,48,0,0,0,0,0,0,0,0,0,0,0, 30,31,52,37,0,0,0,0,0,0,0,0,0,0,0, 66,64,64,61,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0    
};


kal_int16 const NVRAM_EF_AST_TL1_PATHLOSS_40_DEFAULT[]= 
{

   11600,11700,11800,11900,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0    

};
kal_int16 const NVRAM_EF_AST_TL1_TXCLPC_33_35_37_39_DEFAULT[]= 
{
   -30,
   -30,
   -30,
   800 , 800, 800, 800, 800, 800, 800, 800, 800 , 800, 800, 800, 800, 800, 800
};

kal_int16 const NVRAM_EF_AST_TL1_TXCLPC_34_DEFAULT[]= 
{
   -30,
   -30,
   -30,
   800 , 800, 800, 800, 800, 800, 800, 800, 800 , 800, 800, 800, 800, 800, 800
};

kal_int16 const NVRAM_EF_AST_TL1_TXCLPC_40_DEFAULT[]= 
{
   -30,
   -30,
   -30,
   800 , 800, 800, 800, 800, 800, 800, 800, 800 , 800, 800, 800, 800, 800, 800
};
kal_int16 const NVRAM_EF_AST_TL1_TXDAC_33_35_37_39_DEFAULT[]= 
{
   12,0,0,0, 25,0,0,0, 0,0,0,0,//need check
   705,0,0,0, 281,0,0,0, 0,0,0,0,
   9420,9440,9460,9480,9500,9520,9540,9560,9580,9601,0,0,0,0,0,
   -4,-3,-1,-1,0,1,5,8,12,14,0,0,0,0,0, -4,-1,-1,-1,0,0,1,0,3,6,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,-32,-32,-32, 0,0,0,0,0,-32,-32,-32, 0,0,0,0,0,0,0,0,
   18,18,84,84,
   -17,0

};

kal_int16 const NVRAM_EF_AST_TL1_TXDAC_34_DEFAULT[]= 
{

   12,0,0,0, 25,0,0,0, 0,0,0,0,//need check
   652,0,0,0, 217,0,0,0, 0,0,0,0,
   10070,10087,10104,10122,0,0,0,0,0,0,0,0,0,0,0,
   -4,0,3,6,0,0,0,0,0,0,0,0,0,0,0, 0,0,5,3,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,-32,-32,-32, 0,0,0,0,0,-32,-32,-32, 0,0,0,0,0,0,0,0, 
   18,18,84,84,
   -22,0 

};

kal_int16 const NVRAM_EF_AST_TL1_TXDAC_40_DEFAULT[]= 
{

   0,0,0,0, 0,0,0,0, 0,0,0,0,//need check
   797,0,0,0, 573,0,0,0, 0,0,0,0,
   11733,11750,11767,11780,0,0,0,0,0,0,0,0,0,0,0,
   1,0,2,1,0,0,0,0,0,0,0,0,0,0,0, 0,0,1,4,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 
   12,12,84,84,
   0,0 

};

kal_int16 const NVRAM_EF_AST_TL1_ABB_CAL_DEFAULT[]= 
{
    1, /// first boot-up
    0, 0, 0, 0,
    0, 0, 
    0x0040, 0x0050, 
    0x0, 0, 0, 0, 
    0, 0, 0
};

kal_uint32 const NVRAM_EF_AST_TL1_CAP_DATA_DEFAULT[]= 
{
	80//need check
};
tl1CustomDynamicInitMipiData tl1CustomMipiData[TL1_CUSTOM_TOTAL_SET_NUMS] = {
#if (!IS_MML1_DRDI_ENABLE)
    {
     &AST_TL1_RF_PARAMETER_DEFAULT_SetDefault[0],
	   &AST_TL1_RFFE_PARAMETER_DEFAULT_SetDefault[0],
	   &AST_TL1_SEQ_DEFAULT_SetDefault[0]
    },
#else	
    #if TL1_CUSTOM_TOTAL_SET_NUMS > 0 
    {
     &AST_TL1_RF_PARAMETER_DEFAULT_Set0[0],
	   &AST_TL1_RFFE_PARAMETER_DEFAULT_Set0[0],
	   &AST_TL1_SEQ_DEFAULT_Set0[0]
    },
    #endif
	#if TL1_CUSTOM_TOTAL_SET_NUMS > 1
    {
       &AST_TL1_RF_PARAMETER_DEFAULT_Set1[0],
	   &AST_TL1_RFFE_PARAMETER_DEFAULT_Set1[0],
	   &AST_TL1_SEQ_DEFAULT_Set1[0]
    },
	#endif 
    #if TL1_CUSTOM_TOTAL_SET_NUMS > 2
    {
	   &AST_TL1_RF_PARAMETER_DEFAULT_Set2[0],	
	   &AST_TL1_RFFE_PARAMETER_DEFAULT_Set2[0],
	   &AST_TL1_SEQ_DEFAULT_Set2[0]
    },
    #endif    
    #if TL1_CUSTOM_TOTAL_SET_NUMS > 3 
    {
       &AST_TL1_RF_PARAMETER_DEFAULT_Set3[0],	
       &AST_TL1_RFFE_PARAMETER_DEFAULT_Set3[0],
       &AST_TL1_SEQ_DEFAULT_Set3[0]
    },
    #endif 
    #if TL1_CUSTOM_TOTAL_SET_NUMS > 4
    {
       &AST_TL1_RF_PARAMETER_DEFAULT_Set4[0],	
       &AST_TL1_RFFE_PARAMETER_DEFAULT_Set4[0],
       &AST_TL1_SEQ_DEFAULT_Set4[0]
    },
    #endif 
    #if TL1_CUSTOM_TOTAL_SET_NUMS > 5 
    {
       &AST_TL1_RF_PARAMETER_DEFAULT_Set5[0],	
       &AST_TL1_RFFE_PARAMETER_DEFAULT_Set5[0],
       &AST_TL1_SEQ_DEFAULT_Set5[0]
    },
    #endif 
    #if TL1_CUSTOM_TOTAL_SET_NUMS > 6 
    {
       &AST_TL1_RF_PARAMETER_DEFAULT_Set6[0],	
       &AST_TL1_RFFE_PARAMETER_DEFAULT_Set6[0],
       &AST_TL1_SEQ_DEFAULT_Set6[0]
    },
    #endif 
    #if TL1_CUSTOM_TOTAL_SET_NUMS > 7 
    {
       &AST_TL1_RF_PARAMETER_DEFAULT_Set7[0],	
       &AST_TL1_RFFE_PARAMETER_DEFAULT_Set7[0],
       &AST_TL1_SEQ_DEFAULT_Set7[0]
    },
    #endif 
    #if TL1_CUSTOM_TOTAL_SET_NUMS > 8  
    {
       &AST_TL1_RF_PARAMETER_DEFAULT_Set8[0],	
       &AST_TL1_RFFE_PARAMETER_DEFAULT_Set8[0],
       &AST_TL1_SEQ_DEFAULT_Set8[0]
	  },
	  #endif 
#endif	  
};		



