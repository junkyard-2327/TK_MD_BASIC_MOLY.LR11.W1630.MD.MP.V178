#ifndef _T12193_H_
#define _T12193_H_

#include "tl1d_custom_drdi.h"


#define END       0xffff
// Control action name define for timing control  

/****************RF event definition Begin*********************/
#define TXDFE_WIN_CTRL                 1
#define TXCRP_FIFO_WIN_CTRL            2
#define DPD_MODE_SEL                   4

#define RF_TXGAIN_SET                  6
#define RF_RXGAIN_SET                  7
#define RF_TX_ENABLE                   8
#define RF_RX_ENABLE                   9
#define RF_TX_DISABLE                  10
#define RF_RX_DISABLE                  11
#define RF_TEMP_COMP                   12

#define RXE_CFG                        14
#define DAC_ENABLE                     19
#define ADC_ENABLE                     20
#define DAC_DISABLE                    21
#define ADC_DISABLE                    22

#define RF_TX_COMPENSATION             23
#define RF_RX_COMPENSATION             24

#define TXDFE_CLK_ON                   25
#define TXDFE_CLK_OFF                  26
#define RXDFE_CLK_ON                   27
#define RXDFE_CLK_OFF                  28
#define RXE_WIN_ON                     29
#define RXE_WIN_OFF                    30
#define RXE_TICK_SET                   31

#define RX_BPI_CTRL_EN                 34
#define RX_BPI_CTRL_DIS                35
#define TX_BPI_CTRL_EN                 36
#define TX_BPI_CTRL_DIS                37

#define RXDFE_MS_CFG                   38
#define RXDFE_GET_WBRSSI               39
#define TXDFE_MODE_SEL                 40

#define TX_PA_ENABLE                   41
#define TX_PA_DISABLE                  42
#define VPA_ENABLE                     43
#define VPA_DISABLE                    44

#define MIPI_DEVICE1_RX_ENABLE         45
#define MIPI_DEVICE1_RX_DISABLE        46
#define MIPI_DEVICE1_TX_ENABLE         47
#define MIPI_DEVICE1_TX_DISABLE        48
#define MIPI_DEVICE2_RX_ENABLE         49
#define MIPI_DEVICE2_RX_DISABLE        50
#define MIPI_DEVICE2_TX_ENABLE         51
#define MIPI_DEVICE2_TX_DISABLE        52
#define MIPI_DEVICE3_RX_ENABLE         53
#define MIPI_DEVICE3_RX_DISABLE        54
#define MIPI_DEVICE3_TX_ENABLE         55
#define MIPI_DEVICE3_TX_DISABLE        56
#define SRX_RELOCK                     57
#define BPI_CONFLICT_CLEAR             58
#define MIPI_DEVICE2_TR_ENABLE         59
#define MIPI_DEVICE1_TR_DISABLE        60





/****************RF event definition End**********************/

 //////////////////////////////////////////////////////////////////////////////////////////////
#if defined(_T12193_C_) 
//Timing advance setting rule:                                                                                 
//The time difference between RF_RX_ENABLE  and the follow SPI action(RF_? ) is at least 10.                   
//The time difference between RF_RX_DISABLE and the follow SPI action(RF_? ) is at least 20.                   
//The time difference between RF_TX_ENABLE  and the follow SPI action(RF_? ) is at least 10.                   
//The time difference between RF_TX_DISABLE and the follow SPI action(RF_? ) is at least 20.                   
//The time difference between RF_?   action and the follow BPI action(ABB_?/DBB_?/DCO_? ) is at least 7.       
//The time difference between ABB_?  action and the follow SPI action(ABB_? ) is at least 18.                  
//The time difference between ABB_?  action and the follow BPI action(RF_?/DBB_?/DCO_? ) is at least 7.        
//The time difference between ABB_RX_SCALE  action and the follow SPI action(ABB_? ) is at least 36.           
//The time difference between ABB_RX_SCALE  action and the follow BPI action(RF_?/DBB_?/DCO_? ) is at least 25.
//The time difference between DBB_?  action and the follow action is at least 5.                               
//The time difference between DCO_?  action and the follow action is at least 17. 
T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_SetDefault[] = {{
//control action timing based on the beginning of the timeslot must be sorted by an increasing order 
//timing advance range : -400 ~ 0
//ENABLE_DOWNLINK_TIMING_DEFAULT[60]
{
    RX_BPI_CTRL_EN             , -590,
    MIPI_DEVICE3_RX_ENABLE     , -560,//no use    
    MIPI_DEVICE2_RX_ENABLE     , -530,//asm
    MIPI_DEVICE1_RX_ENABLE     , -500,//no use
    RXE_CFG                    , 0,
    ADC_ENABLE                 , 0,
    RXDFE_MS_CFG               , -40,     /*Set DC/WB1+SPUR/WB2 Measure in a slot*/
    RXE_WIN_ON                 , -4,
    RXE_TICK_SET               , 0,
    RF_RXGAIN_SET              , -260,
    RF_RX_ENABLE               , -250, 
    RF_TEMP_COMP               ,  -50,     // Temperature trigger
    //RF_RX_COMPENSATION           ,     -92,          /* Compensate IQ mismatch at RF WARMUP*/              
    END                        ,  END // This line means the end of the actions,so it must be follow the last action.

},

//control action timing based on the end of the timeslot must be sorted by an increasing order 
//timing advance range : -200 ~ +100
//DISABLE_DOWNLINK_TIMING_DEFAULT[60]= 
{
    RF_RX_DISABLE              , -29,
    RX_BPI_CTRL_DIS            ,  -9,
    MIPI_DEVICE1_RX_DISABLE    ,  30,
    MIPI_DEVICE2_RX_DISABLE    ,  30,//asm
    MIPI_DEVICE3_RX_DISABLE    ,  30,
    ADC_DISABLE                ,   8,
    RXE_WIN_OFF                ,  -4,
    RXDFE_CLK_OFF              , 120,
    RXDFE_GET_WBRSSI           ,  50,
    BPI_CONFLICT_CLEAR         ,  70,
    END                        ,  END  // This line means the end of the actions,so it must be follow the last action.    

},


//control action timing based on the beginning of the timeslot must be sorted by an increasing order 
//timing advance range : -332 ~ 0
//ENABLE_UPLINK_TIMING_DEFAULT[60]= 
{
#if defined(__MT6291_TDD_RTL__)||defined(TL1_SIM)
    TXDFE_WIN_CTRL             ,      0,
#else
    TXDFE_WIN_CTRL             , -218,
#endif
    SRX_RELOCK                 , -720,
    VPA_ENABLE                 , -310,     
    MIPI_DEVICE3_TX_ENABLE     , -300,//no use
    MIPI_DEVICE1_TX_ENABLE     , -260,//pa txm
    MIPI_DEVICE2_TX_ENABLE     , -200,//asm txm
    TX_BPI_CTRL_EN             , -170,//BPI      
    RF_TX_ENABLE               , -150,
    RF_TXGAIN_SET              , -110,
    TXDFE_MODE_SEL             , -120,   /* not The time information is not used*/
    RF_TX_COMPENSATION         , -100,
    END                        ,   END  // This line means the end of the actions,so it must be follow the last action.                            
},


//control action timing based on the end of the timeslot must be sorted by an increasing order 
//timing advance range : -200 ~ +100
//DISABLE_UPLINK_TIMING_DEFAULT[60]= 
{
    RF_TX_DISABLE             ,  -160,
    MIPI_DEVICE1_TX_DISABLE   ,  -150,//PA
    TX_BPI_CTRL_DIS           ,  -120, //The time can not modify  
    MIPI_DEVICE2_TX_DISABLE   ,  -100,//ASM
    MIPI_DEVICE3_TX_DISABLE   ,   -70,//NO USE
    BPI_CONFLICT_CLEAR        ,   -30,
    VPA_DISABLE               ,     0,            
    END                       ,  END  // This line means the end of the actions,so it must be follow the last action.
},


//control action timing based on the beginning of the second timeslot must be sorted by an increasing order 
//timing advance range : -373 ~ 0
//DL_DL_GAP_CTRL_TIMING_DEFAULT[60]= 
{
    MIPI_DEVICE2_RX_ENABLE     , -300,//asm, TBD, need check ASM-RF group delay.
    RF_RXGAIN_SET              , -260,  
    MIPI_DEVICE1_RX_ENABLE     , -190,//no use
    MIPI_DEVICE3_RX_ENABLE     , -190,//no use       
    RX_BPI_CTRL_EN             , -80, //for dl-dl rf front end config modify                                           
    RF_TEMP_COMP               ,  -50,     // Temperature trigger                                           
    RXE_CFG                    , 0,
    RXE_TICK_SET               , 0,    
    RXDFE_MS_CFG               , 0,   
    RXDFE_GET_WBRSSI           , 0,
    END                     ,   END  // This line means the end of the actions,so it must be follow the last action. 

},


//control action timing based on the beginning of the second timeslot must be sorted by an increasing order 
//timing advance range : -250 ~ 0
//UL_UL_GAP_CTRL_TIMING_DEFAULT[60]= 
{
#if defined(__MT6291_TDD_RTL__)||defined(TL1_SIM)
    TXDFE_WIN_CTRL             ,    0,
#else
    TXDFE_WIN_CTRL             ,  -218,
#endif
    TXDFE_MODE_SEL             ,  -120,
    RF_TX_COMPENSATION         ,  -100,
    RF_TXGAIN_SET              ,  -110,
    VPA_ENABLE                 ,  -105,    
    MIPI_DEVICE1_TX_ENABLE     ,  -100,//PA,TXIQ->PA delay 4us.
    END                        ,  END // This line means the end of the actions,so it must be follow the last action.
},


//control action timing based on the beginning of downlink timeslot must be sorted by an increasing order 
//timing advance range : -400 ~ 0
//UL_DL_GAP_CTRL_TIMING_DEFAULT[60]= 
{
    MIPI_DEVICE3_TX_DISABLE   , 0,//no use
    ADC_ENABLE                ,    0,
    RXE_CFG                   , 0,            
    RXE_WIN_ON                , 0,      
    RXE_TICK_SET              , 0,       
    RX_BPI_CTRL_EN            , -200,       
    MIPI_DEVICE2_TR_ENABLE    , -190,//asms
    RF_RXGAIN_SET             , -185,
    RF_RX_ENABLE              , -180,
    MIPI_DEVICE1_TR_DISABLE   , -150,//PA        
    RXDFE_MS_CFG              ,  0,
    RF_RX_COMPENSATION        ,  0,//no use
    VPA_DISABLE               , 100, 
    END                       ,  END // This line means the end of the actions,so it must be follow the last action.
 },
 
/**********************************Below is for B39*****************************************/
//control action timing based on the beginning of the timeslot must be sorted by an increasing order 
//timing advance range : -332 ~ 0
//ENABLE_UPLINK_TIMING_DEFAULT[60]= 
{
#if defined(__MT6291_TDD_RTL__)||defined(TL1_SIM)
    TXDFE_WIN_CTRL             ,      0,
#else
    TXDFE_WIN_CTRL             , -218,
#endif
    SRX_RELOCK                 , -720,
    VPA_ENABLE                 , -310,     
    MIPI_DEVICE3_TX_ENABLE     , -300,//no use
    MIPI_DEVICE1_TX_ENABLE     , -260,//pa txm
    MIPI_DEVICE2_TX_ENABLE     , -200,//asm txm
    TX_BPI_CTRL_EN             , -170,//BPI      
    RF_TX_ENABLE               , -150,
    RF_TXGAIN_SET              , -110,
    TXDFE_MODE_SEL             , -120,   /* not The time information is not used*/
    RF_TX_COMPENSATION         , -100,
    END                        ,   END  // This line means the end of the actions,so it must be follow the last action.                            
},


//control action timing based on the end of the timeslot must be sorted by an increasing order 
//timing advance range : -200 ~ +100
//DISABLE_UPLINK_TIMING_DEFAULT[60]= 
{
    RF_TX_DISABLE             ,  -160,
    MIPI_DEVICE1_TX_DISABLE   ,  -150,//PA
    TX_BPI_CTRL_DIS           ,  -120, //The time can not modify  
    MIPI_DEVICE2_TX_DISABLE   ,  -100,//ASM
    MIPI_DEVICE3_TX_DISABLE   ,   -70,//NO USE
    BPI_CONFLICT_CLEAR        ,   -30,
    VPA_DISABLE               ,     0, 
    END                       ,  END  // This line means the end of the actions,so it must be follow the last action.
},
/**********************************Above is for B39*****************************************/

/**********************************Below is for B40*****************************************/
//control action timing based on the beginning of the timeslot must be sorted by an increasing order 
//timing advance range : -332 ~ 0
//ENABLE_UPLINK_TIMING_DEFAULT[60]= 
{
#if defined(__MT6291_TDD_RTL__)||defined(TL1_SIM)
    TXDFE_WIN_CTRL             ,      0,
#else
    TXDFE_WIN_CTRL             , -218,
#endif
    SRX_RELOCK                 , -720,
    VPA_ENABLE                 , -310,     
    MIPI_DEVICE3_TX_ENABLE     , -300,//no use
    MIPI_DEVICE1_TX_ENABLE     , -260,//pa txm
    MIPI_DEVICE2_TX_ENABLE     , -200,//asm txm
    TX_BPI_CTRL_EN             , -170,//BPI      
    RF_TX_ENABLE               , -150,
    RF_TXGAIN_SET              , -110,
    TXDFE_MODE_SEL             , -120,   /* not The time information is not used*/
    RF_TX_COMPENSATION         , -100,
    END                        ,   END  // This line means the end of the actions,so it must be follow the last action.                            
},


//control action timing based on the end of the timeslot must be sorted by an increasing order 
//timing advance range : -200 ~ +100
//DISABLE_UPLINK_TIMING_DEFAULT[60]= 
{
    RF_TX_DISABLE             ,  -160,
    MIPI_DEVICE1_TX_DISABLE   ,  -150,//PA
    TX_BPI_CTRL_DIS           ,  -120, //The time can not modify  
    MIPI_DEVICE2_TX_DISABLE   ,  -100,//ASM
    MIPI_DEVICE3_TX_DISABLE   ,   -70,//NO USE
    BPI_CONFLICT_CLEAR        ,   -30,
    VPA_DISABLE               ,     0, 
    END                       ,  END  // This line means the end of the actions,so it must be follow the last action.
}

/**********************************Above is for B40*****************************************/

}};

#endif

#endif
