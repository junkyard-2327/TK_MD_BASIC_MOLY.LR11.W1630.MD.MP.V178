#ifndef _TL1D_CUSTOM_RF_Set2_H_
#define _TL1D_CUSTOM_RF_Set2_H_

#include "tl1d_custom_drdi.h"

// The default value are the same
#ifdef __TAS_SUPPORT__
#define TDD_TAS_BPI_PIN0_BPI_NUM_Set2   18                // TAS BPI PIN 0 BPI Number
#define TDD_TAS_BPI_PIN1_BPI_NUM_Set2   TDD_TAS_PIN_NULL  // TAS BPI PIN 1 BPI Number
#define TDD_TAS_BPI_PIN2_BPI_NUM_Set2   TDD_TAS_PIN_NULL  // TAS BPI PIN 2 BPI Number
#define TDD_TAS_BPI_PIN3_BPI_NUM_Set2   TDD_TAS_PIN_NULL  // TAS BPI PIN 3 BPI Number

#define  TDD_TAS_ANT0_MASK_Set2       TDD_TAS_BPI_PIN_GEN(1,0,0,0,Set2)
#define  TDD_TAS_ANT1_MASK_Set2       TDD_TAS_BPI_PIN_GEN(1,0,0,0,Set2)
#define  TDD_TAS_ANT0_UNMASK_Set2     TDD_TAS_BPI_PIN_GEN(0,0,0,0,Set2)
#define  TDD_TAS_ANT1_UNMASK_Set2     TDD_TAS_BPI_PIN_GEN(0,0,0,0,Set2)

#define  TDD_TAS_ANT0_SET_Set2        TDD_TAS_BPI_PIN_GEN(0,0,0,0,Set2)
#define  TDD_TAS_ANT1_SET_Set2        TDD_TAS_BPI_PIN_GEN(1,0,0,0,Set2)

#define TDS_TAS_ENA_Set2    1  // TAS Enable Flag, [0 - TAS Disable, 1 - TAS Enable]
#else
#define TDS_TAS_ENA_Set2    0  // TAS Enable Flag, [0 - TAS Disable, 1 - TAS Enable]
#endif

#ifdef __TAS_SUPPORT__
#define TAS_TEST_SIM_ENABLE_Set2         0 // TDS TAS Test Sim Enable Flag, [0 - Disable	1 - Enable]
#define TDS_BAND34_SUPPORT_TAS_Set2		1 // Band34 Support TAS Flag, [0 - Not Support, 1 - Support]
#define TDS_BAND39_SUPPORT_TAS_Set2		1 // Band39 Support TAS Flag, [0 - Not Support, 1 - Support]
#define TDS_BAND40_SUPPORT_TAS_Set2		1 // Band40 Support TAS Flag, [0 - Not Support, 1 - Support]
#define TDS_FORCE_TX_ANT_SWITCH_Set2		0 // TAS Force Tx Antenna Select Enable, [0 - Disable	1 - Enable]
#define TDS_TAS_TX_PARAM_RSCP_DIFF_Set2        (3)   //rscp threadhold when in sar.
#define TDS_TAS_TX_PARAM_TP_OFE_Set2           (3)   //TP_OFT not use currently. set as default
#define TDS_TAS_TX_PARAM_HTP_Set2              (-1)  // HTP offset value when HTP condition
#define TDS_TAS_TX_PARAM_RESERVE_Set2          (0)   //reserve set to 0
#ifdef __TAS_ANTENNA_IDX_ON_TEST_SIM__
#define TDS_TAS_INIT_ANT_B34_Set2         (1)
#define TDS_TAS_INIT_ANT_B39_Set2         (0)
#define TDS_TAS_INIT_ANT_B40_Set2         (1)
#endif
#endif

#if defined(MT6176_RF)    
/*don't modify the name and value*/
/*RX PORT*/
#define TDS_PRX1_Set2       ( 1<<3 )+( 1<<6 )+( 1<<11 )+( 1<<15 )    // Group4,LNA1
#define TDS_PRX2_Set2       ( 1<<3 )+( 1<<7 )+( 1<<11 )+( 1<<15 )    // Group4,LNA2
#define TDS_PRX3_Set2       ( 1<<3 )+( 1<<8 )+( 1<<11 )+( 1<<15 )    // Group4,LNA3
#define TDS_PRX4_Set2       ( 1<<2 )+( 1<<6 )+( 1<<11 )+( 1<<15 )    // Group3,LNA1
#define TDS_PRX5_Set2       ( 1<<2 )+( 1<<7 )+( 1<<11 )+( 1<<15 )    // Group3,LNA2
#define TDS_PRX6_Set2       ( 1<<2 )+( 1<<8 )+( 1<<11 )+( 1<<15 )    // Group3,LNA3
#define TDS_PRX7_Set2       ( 1<<2 )+( 1<<9 )+( 1<<11 )+( 1<<15 )    // Group3,LNA4
#define TDS_PRX8_Set2       ( 1<<1 )+( 1<<6 )+( 1<<11 )+( 1<<15 )    // Group2,LNA1 
#define TDS_PRX9_Set2       ( 1<<1 )+( 1<<7 )+( 1<<11 )+( 1<<15 )    // Group2,LNA2
#define TDS_PRX10_Set2      ( 1<<1 )+( 1<<8 )+( 1<<11 )+( 1<<15 )    // Group2,LNA3
#define TDS_PRX11_Set2      ( 1<<1 )+( 1<<9 )+( 1<<11 )+( 1<<15 )    // Group2,LNA4
#define TDS_PRX12_Set2      ( 1<<0 )+( 1<<6 )+( 1<<11 )+( 1<<15 )    // Group1,LNA1
#define TDS_PRX13_Set2      ( 1<<0 )+( 1<<7 )+( 1<<11 )+( 1<<15 )    // Group1,LNA2
#define TDS_PRX14_Set2      ( 1<<0 )+( 1<<8 )+( 1<<11 )+( 1<<15 )    // Group1,LNA3
/*TX PORT*/
#define TDS_TX_LB1_Set2       ( 1<<0 )    
#define TDS_TX_LB2_Set2       ( 1<<1 )    
#define TDS_TX_LB3_Set2       ( 1<<2 )    
#define TDS_TX_LB4_Set2       ( 1<<3 )    
#define TDS_TX_MB1_Set2       ( 1<<5 )    
#define TDS_TX_MB2_Set2       ( 1<<6 )    
#define TDS_TX_MB3_Set2       ( 1<<7 )   
#define TDS_TX_MB4_Set2       ( 1<<8 )   
#define TDS_TX_HB1_Set2       ( 1<<10 )    
#define TDS_TX_HB2_Set2       ( 1<<11 )    

#if defined(_T12193_C_) 


 /*--------------------------------------------------------*/
 /*           bit   pin                                    */
 /*            0    GPCTRL0                                */                                     
 /*            1    GPCTRL1                            */                                     
 /*            2    GPCTRL2                             */                                     
 /*            3    TX_EX                                  */                                     
 /*            4    not used                                    */                                     
 /*            5    not used                               */                                     
 /*            6    not used                                    */                                     
 /*            7    not used                                */                                     
 /*            8    not used                                */                                     
 /*            9    not used                                 */  
 /*            10   not used                               */ 
 /*            11   VEN                               */ 
 /*            12   VC1                                 */       
 /*            13   VC2                              */   
 /*            14   not used                               */                         
 /*--------------------------------------------------------*/ 
 T_TD_CUSTOMIZATION_STRUCT    AST_TL1_RF_PARAMETER_DEFAULT_Set2[] = {{ 
 //T_BPI_SETTING 
 {
  //TX_2G34   TX_2G01/TX_1G90 
 // [7:4]     [3:0] 	
 	 (1<<4)     +   2,                                 //PA_STAGE          data[0]
 	 																						       //3:PA_HGAIN PA_MGAIN PA_LGAIN
 	 																						       //2:PA_HGAIN PA_MGAIN
 	 																						       //1:PA_HGAIN
 

   {	
  /////////////////////DBB_BPI_AREA1 begin (fix for TX Control )/////////////////////////////
		// V1	       V2	        V3		        	 RFconflict 
#ifdef __TAS_SUPPORT__  
     (TDD_TAS_ANT0_MASK_Set2) + (0<<21) + (1<<31),          //TX_CTRL_BITMASK   data[1]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) + (1<<31),          //TX_2G34 PA_HGAIN  data[2]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) + (1<<31),          //TX_2G34 PA_MGAIN  data[3]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) + (1<<31),          //TX_2G34 PA_LGAIN  data[4]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) + (1<<31),          //TX_2G01 PA_HGAIN  data[5]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) + (1<<31),          //TX_2G01 PA_MGAIN  data[6]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) + (1<<31),          //TX_2G01 PA_LGAIN  data[7]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) + (1<<31),          //TX_1G90 PA_HGAIN  data[8]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) + (1<<31),          //TX_1G90 PA_MGAIN  data[9]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) + (1<<31),          //TX_1G90 PA_LGAIN  data[10] 
     (TDD_TAS_ANT0_UNMASK_Set2) + (0<<21) + (0<<31),          //TX_DISABLE	      data[11]
#else										
     (1<<18)+(1<<19)+(0<<21) + (1<<31),          //TX_CTRL_BITMASK   data[1]	
     (1<<18)+(1<<19)+(0<<21) + (1<<31),          //TX_2G34 PA_HGAIN  data[2]	
     (1<<18)+(1<<19)+(0<<21) + (1<<31),          //TX_2G34 PA_MGAIN  data[3]	
     (1<<18)+(1<<19)+(0<<21) + (1<<31),          //TX_2G34 PA_LGAIN  data[4]	
     (1<<18)+(1<<19)+(0<<21) + (1<<31),          //TX_2G01 PA_HGAIN  data[5]	
     (1<<18)+(1<<19)+(0<<21) + (1<<31),          //TX_2G01 PA_MGAIN  data[6]	
     (1<<18)+(1<<19)+(0<<21) + (1<<31),          //TX_2G01 PA_LGAIN  data[7]	
     (1<<18)+(1<<19)+(0<<21) + (1<<31),          //TX_1G90 PA_HGAIN  data[8]	
     (1<<18)+(1<<19)+(0<<21) + (1<<31),          //TX_1G90 PA_MGAIN  data[9]	
     (1<<18)+(1<<19)+(0<<21) + (1<<31),          //TX_1G90 PA_LGAIN  data[10] 
     (0<<18)+(0<<19)+(0<<21) + (0<<31),          //TX_DISABLE	      data[11]
#endif     
    },

    {
	/////////////////////DBB_BPI_AREA2 begin (fix for RX Control)///////////////////////////
		// V1	       V2	        V3		    		  RFconflict	
#ifdef __TAS_SUPPORT__  
     (TDD_TAS_ANT0_MASK_Set2) + (0<<21) +(1<<31),           //RX_CTRL_BITMASK   data[12]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) +(1<<31),           //RX_2G34           data[13]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) +(1<<31),           //RX_2G01           data[14]	
     (TDD_TAS_ANT0_SET_Set2) + (0<<21) +(1<<31),           //RX_1G90           data[15]	
     (TDD_TAS_ANT0_UNMASK_Set2) + (0<<21) +(0<<31),           //RX_DISABLE        data[16]
#else											
     (1<<18)+(1<<19)+(0<<21) +(1<<31),           //RX_CTRL_BITMASK   data[12]	
     (1<<18)+(1<<19)+(0<<21) +(1<<31),           //RX_2G34           data[13]	
     (1<<18)+(1<<19)+(0<<21) +(1<<31),           //RX_2G01           data[14]	
     (1<<18)+(1<<19)+(0<<21) +(1<<31),           //RX_1G90           data[15]	
     (0<<18)+(0<<19)+(0<<21) +(0<<31),           //RX_DISABLE        data[16]
#endif     
	 /////////////////////DBB_BPI_AREA2 end///////////////////////////////////////////////////
    },

#ifdef __TAS_SUPPORT__    
   {	
  /////////////////////DBB_BPI_AREA1 begin (fix for TX Control )/////////////////////////////
		// V1	       V2	        V3		        	 RFconflict 								
     (TDD_TAS_ANT1_MASK_Set2) + (0<<21) + (1<<31),          //TX_CTRL_BITMASK   data[1]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) + (1<<31),          //TX_2G34 PA_HGAIN  data[2]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) + (1<<31),          //TX_2G34 PA_MGAIN  data[3]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) + (1<<31),          //TX_2G34 PA_LGAIN  data[4]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) + (1<<31),          //TX_2G01 PA_HGAIN  data[5]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) + (1<<31),          //TX_2G01 PA_MGAIN  data[6]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) + (1<<31),          //TX_2G01 PA_LGAIN  data[7]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) + (1<<31),          //TX_1G90 PA_HGAIN  data[8]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) + (1<<31),          //TX_1G90 PA_MGAIN  data[9]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) + (1<<31),          //TX_1G90 PA_LGAIN  data[10] 
     (TDD_TAS_ANT1_UNMASK_Set2) + (0<<21) + (0<<31),          //TX_DISABLE	      data[11]
    },

    {
	/////////////////////DBB_BPI_AREA2 begin (fix for RX Control)///////////////////////////
		// V1	       V2	        V3		    		  RFconflict										
     (TDD_TAS_ANT1_MASK_Set2) + (0<<21) +(1<<31),           //RX_CTRL_BITMASK   data[12]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) +(1<<31),           //RX_2G34           data[13]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) +(1<<31),           //RX_2G01           data[14]	
     (TDD_TAS_ANT1_SET_Set2) + (0<<21) +(1<<31),           //RX_1G90           data[15]	
     (TDD_TAS_ANT1_UNMASK_Set2) + (0<<21) +(0<<31),           //RX_DISABLE        data[16]
	 /////////////////////DBB_BPI_AREA2 end///////////////////////////////////////////////////
    },    
#endif

    {
  /////////////////////DBB_BPI_AREA3 begin/////////////////////////////////////////////////   
	  //TXEN	 VEN																		   
     (0<<0),                      //PA_BITMASK        data[17]  
     (0<<0),                      //PA_ENABLE_2G34    data[18]  
     (0<<0),                      //PA_ENABLE_2G01    data[19]  
     (0<<0),                      //PA_ENABLE_1G90    data[20]  
     (0<<0)	                      //PA_DISABLE        data[21]  
  /////////////////////DBB_BPI_AREA3 end///////////////////////////////////////////////////
    },

    {
  /////////////////////DBB_BPI_AREA4 begin/////////////////////////////////////////////////   
 //enable/disable Other fuction 
    (0<<0),                                             //?_BITMASK        data[22]
    (0<<0),                                             //?_ENABLE         data[23]    
    (1<<0)                 //?_DISABLE         data[24]   
  /////////////////////DBB_BPI_AREA4 end///////////////////////////////////////////////////                                                                                     
    },

    {
  /////////////////////DBB_BPI_AREA5 begin/////////////////////////////////////////////////   
  //enable/disable Other fuction 
     (0<<0),                              //?_BITMASK         data[25]
     (0<<0),                              //?_ENABLE          data[26]    
     (0<<0)                               //?_DISABLE         data[27]   
  /////////////////////DBB_BPI_AREA5 end///////////////////////////////////////////////////
    }
 },

//T_ABB_APC_VOLT 
 {
     0x11, //Decide which volt Used for PA!!! carefull ! bit	0x11 
             //VPA POWER from PMIC    APC power from MT6176
          	 //bit 0:  B34 volt choice 0: VPC  1:APC
		     //bit 4:  B39 volt choice 0: VPC  1:APC 
     0x329, //B34 HGv  0.0028V *X   2.26v
     0xD9, //B34 MGv  0.0028V *X
     0x329, //B34 LGv  0.0028V *X
     0x329, //B39 HGv  0.0028V *X
     0xD9, //B39 MGv  0.0028V *X
     0x329, //B39 LGv  0.0028V *X
     0
 },

//T_RF_PORT_SEL
 {
     TDS_TX_MB3_Set2,  //Tx2G01
     TDS_TX_MB3_Set2,  //Tx1G90
     TDS_TX_MB3_Set2,  //Tx2G34
     TDS_PRX6_Set2,    //Rx2G01
     TDS_PRX6_Set2,    //Rx1G90
     TDS_PRX6_Set2,    //Rx2G34
 },

//T_IQ_SWAP_CFG_STRUCT
 {
     1,//RX :0    IQswap diable     1:    IQswap enable
     0 //TX :0    IQswap diable     1:    IQswap enable
 },
//T_VPA_VOLT_STRUCT
 {
 	34,  //B34,High gain 3.4V
	34,  //B34,Mid  gain 3.4V
	34,  //B34,Low  gain 3.4V
	34,  //B39,High gain 3.4V
	34,  //B39,Mid  gain 3.4V
	34,  //B39,Low  gain 3.4V
 }

#ifdef __TAS_SUPPORT__
 ,
 {
	 TDS_TAS_ENA_Set2,			 // TDS TAS Enable
	 ANTENNA_1,			 	 // TAS Default Main Physical Antenna //ANT
	 2,// TAS Default Type: 0 - Disable   1 - With Rx Diversity   2 - Without Rx Diversity, Fixed
	 (TDS_BAND34_SUPPORT_TAS_Set2<<0) + (TDS_BAND39_SUPPORT_TAS_Set2<<1) + (TDS_BAND40_SUPPORT_TAS_Set2<<2),	// TAS Type by Band
	 TDS_FORCE_TX_ANT_SWITCH_Set2,// TAS Force Tx Antenna Enable
	 ANTENNA_1,			 	 // TAS Force Tx Antenna Index //ANT
	 TAS_TEST_SIM_ENABLE_Set2,           // TDS TAS Test Sim Enable
     TDS_TAS_TX_PARAM_RESERVE_Set2,               //reserve 0
     TDS_TAS_TX_PARAM_RSCP_DIFF_Set2,             //rscp threadhold used under sar  
     TDS_TAS_TX_PARAM_RESERVE_Set2,                //tp_oft not use. 
     TDS_TAS_TX_PARAM_HTP_Set2,                   //HTP offset value when HTP   
     TDS_TAS_TX_PARAM_RESERVE_Set2                //reserve 0  	 
 }

#ifdef __TAS_ANTENNA_IDX_ON_TEST_SIM__
 ,
 {
     TDS_TAS_INIT_ANT_B34_Set2,
     TDS_TAS_INIT_ANT_B39_Set2,
     TDS_TAS_INIT_ANT_B40_Set2
 }
#endif

#endif
#if defined(__TX_POWER_OFFSET_SUPPORT__)
  ,
  { 	//uwSwtpPowerOffset q3
	   /*max_arfcn should be same between table0~table3, and must be orded*/
	   /*table0*/
	  {
	   
			 /*max_arfcn,normal offset,16QAM offset,reserve*/
			 {9400, 		0,		   0,		  0},/*begain of band 39,donot change */
			 {9440, 		0,		   0,		  0},
			 {9460, 		0,		   0,		  0},
			 {9480, 		0,		   0,		  0},
			 {9500, 		0,		   0,		  0},
			 {9520, 		0,		   0,		  0},
			 {9540, 		0,		   0,		  0},
			 {9560, 		0,		   0,		  0},
			 {9580, 		0,		   0,		  0},
			 {9600, 		0, 	       0,		  0},/*end of band 39,donot change */
			 {10050,		0, 	       0,		  0},/*begain of band 34,donot change */
			 {10087,		0, 	       0,		  0},
			 {10104,		0, 	       0,		  0},
			 {10125,		0, 	       0,		  0},/*end of band 34,donot change */
			 {0,			0,		   0,		  0},
			 {0,			0,		   0,		  0},
			 {0,			0,		   0,		  0},
			 {0,			0,		   0,		  0},
			 {0,			0,		   0,		  0},
			 {0,			0,		   0,		  0}
	  },
		   
	   /*table1*/
	  {
			 /*max_arfcn,normal offset,16QAM offset,reserve*/
			 {9400, 		0,		   0,		  0},/*begain of band 39,donot change */
			 {9440, 		0,		   0,		  0},
			 {9460, 		0,		   0,		  0},
			 {9480, 		0,		   0,		  0},
			 {9500, 		0,		   0,		  0},
			 {9520, 		0,		   0,		  0},
			 {9540, 		0,		   0,		  0},
			 {9560, 		0,		   0,		  0},
			 {9580, 		0,		   0,		  0},
			 {9600, 		0,		   0,		  0},/*end of band 39,donot change */
			 {10050,		0,		   0,		  0},/*begain of band 34,donot change */
			 {10087,		0,		   0,		  0},
			 {10104,		0,		   0,		  0},
			 {10125,		0,		   0,		  0},/*end of band 34,donot change */
			 {0,			0,		   0,		  0},
			 {0,			0,		   0,		  0},
			 {0,			0,		   0,		  0},
			 {0,			0,		   0,		  0},
			 {0,			0,		   0,		  0},
			 {0,			0,		   0,		  0}
	  }
	  
  }
  
 #endif
 ,
 //T_PADDING_RESV_STRUCT
 {
  0,0,0,0,0,0,0,0
 }
}};


#endif
#endif

#endif  //#ifndef _TL1D_CUSTOM_RF_H_
