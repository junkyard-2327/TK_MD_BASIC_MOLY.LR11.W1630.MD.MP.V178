#ifndef _T12193_Set2_H_
#define _T12193_Set2_H_

#include "tl1d_custom_drdi.h"


#define END_Set2       0xffff
// Control action name define for timing control  

/****************RF event definition Begin*********************/
#define TXDFE_WIN_CTRL_Set2                 1
#define TXCRP_FIFO_WIN_CTRL_Set2            2
#define DPD_MODE_SEL_Set2                   4

#define RF_TXGAIN_SET_Set2                  6
#define RF_RXGAIN_SET_Set2                  7
#define RF_TX_ENABLE_Set2                   8
#define RF_RX_ENABLE_Set2                   9
#define RF_TX_DISABLE_Set2                 10
#define RF_RX_DISABLE_Set2                  11
#define RF_TEMP_COMP_Set2                   12

#define RXE_CFG_Set2                        14
#define DAC_ENABLE_Set2                     19
#define ADC_ENABLE_Set2                     20
#define DAC_DISABLE_Set2                    21
#define ADC_DISABLE_Set2                    22

#define RF_TX_COMPENSATION_Set2             23
#define RF_RX_COMPENSATION_Set2             24

#define TXDFE_CLK_ON_Set2                   25
#define TXDFE_CLK_OFF_Set2                  26
#define RXDFE_CLK_ON_Set2                   27
#define RXDFE_CLK_OFF_Set2                  28
#define RXE_WIN_ON_Set2                     29
#define RXE_WIN_OFF_Set2                    30
#define RXE_TICK_SET_Set2                   31

#define RX_BPI_CTRL_EN_Set2                 34
#define RX_BPI_CTRL_DIS_Set2                35
#define TX_BPI_CTRL_EN_Set2                 36
#define TX_BPI_CTRL_DIS_Set2                37

#define RXDFE_MS_CFG_Set2                   38
#define RXDFE_GET_WBRSSI_Set2               39
#define TXDFE_MODE_SEL_Set2                 40

#define TX_PA_ENABLE_Set2                   41
#define TX_PA_DISABLE_Set2                  42
#define VPA_ENABLE_Set2                     43
#define VPA_DISABLE_Set2                    44

#define MIPI_DEVICE1_RX_ENABLE_Set2         45
#define MIPI_DEVICE1_RX_DISABLE_Set2        46
#define MIPI_DEVICE1_TX_ENABLE_Set2         47
#define MIPI_DEVICE1_TX_DISABLE_Set2        48
#define MIPI_DEVICE2_RX_ENABLE_Set2         49
#define MIPI_DEVICE2_RX_DISABLE_Set2        50
#define MIPI_DEVICE2_TX_ENABLE_Set2         51
#define MIPI_DEVICE2_TX_DISABLE_Set2        52
#define MIPI_DEVICE3_RX_ENABLE_Set2         53
#define MIPI_DEVICE3_RX_DISABLE_Set2        54
#define MIPI_DEVICE3_TX_ENABLE_Set2         55
#define MIPI_DEVICE3_TX_DISABLE_Set2        56
#define SRX_RELOCK_Set2                     57
#define BPI_CONFLICT_CLEAR_Set2             58
#define MIPI_DEVICE2_TR_ENABLE_Set2         59
#define MIPI_DEVICE1_TR_DISABLE_Set2        60





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
T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_Set2[] = {{
//control action timing based on the beginning of the timeslot must be sorted by an increasing order 
//timing advance range : -400 ~ 0
//ENABLE_DOWNLINK_TIMING_DEFAULT[60]
{
    RX_BPI_CTRL_EN_Set2             , -590,
    MIPI_DEVICE3_RX_ENABLE_Set2     , -560,//no use    
    MIPI_DEVICE2_RX_ENABLE_Set2     , -530,//asm
    MIPI_DEVICE1_RX_ENABLE_Set2     , -500,//no use
    RXE_CFG_Set2                    , 0,
    ADC_ENABLE_Set2                 , 0,
    RXDFE_MS_CFG_Set2               , -40,     /*Set DC/WB1+SPUR/WB2 Measure in a slot*/
    RXE_WIN_ON_Set2                 , -4,
    RXE_TICK_SET_Set2               , 0,
    RF_RXGAIN_SET_Set2              , -260,
    RF_RX_ENABLE_Set2               , -250, 
    RF_TEMP_COMP_Set2               ,  -50,     // Temperature trigger
    //RF_RX_COMPENSATION_Set2           ,     -92,          /* Compensate IQ mismatch at RF WARMUP*/              
    END_Set2                        ,  END_Set2 // This line means the end of the actions,so it must be follow the last action.

},

//control action timing based on the end of the timeslot must be sorted by an increasing order 
//timing advance range : -200 ~ +100
//DISABLE_DOWNLINK_TIMING_DEFAULT[60]= 
{
    RF_RX_DISABLE_Set2              , -29,
    RX_BPI_CTRL_DIS_Set2            ,  -9,
    MIPI_DEVICE1_RX_DISABLE_Set2    ,  30,
    MIPI_DEVICE2_RX_DISABLE_Set2    ,  30,//asm
    MIPI_DEVICE3_RX_DISABLE_Set2    ,  30,
    ADC_DISABLE_Set2                ,   8,
    RXE_WIN_OFF_Set2                ,  -4,
    RXDFE_CLK_OFF_Set2              , 120,
    RXDFE_GET_WBRSSI_Set2           ,  50,
    BPI_CONFLICT_CLEAR_Set2         ,  70,
    END_Set2                        ,  END_Set2  // This line means the end of the actions,so it must be follow the last action.    

},


//control action timing based on the beginning of the timeslot must be sorted by an increasing order 
//timing advance range : -332 ~ 0
//ENABLE_UPLINK_TIMING_DEFAULT[60]= 
{
#if defined(__MT6291_TDD_RTL__)||defined(TL1_SIM)
    TXDFE_WIN_CTRL_Set2             ,      0,
#else
    TXDFE_WIN_CTRL_Set2             , -218,
#endif
    SRX_RELOCK_Set2                 , -720,
    VPA_ENABLE_Set2                 , -310,     
    MIPI_DEVICE3_TX_ENABLE_Set2     , -300,//no use
    MIPI_DEVICE1_TX_ENABLE_Set2     , -260,//pa txm
    MIPI_DEVICE2_TX_ENABLE_Set2     , -200,//asm txm
    TX_BPI_CTRL_EN_Set2             , -170,//BPI      
    RF_TX_ENABLE_Set2               , -150,
    RF_TXGAIN_SET_Set2              , -110,
    TXDFE_MODE_SEL_Set2             , -120,   /* not The time information is not used*/
    RF_TX_COMPENSATION_Set2         , -100,
    END_Set2                        ,   END_Set2  // This line means the end of the actions,so it must be follow the last action.                            
},


//control action timing based on the end of the timeslot must be sorted by an increasing order 
//timing advance range : -200 ~ +100
//DISABLE_UPLINK_TIMING_DEFAULT[60]= 
{
    RF_TX_DISABLE_Set2             ,  -160,
    MIPI_DEVICE1_TX_DISABLE_Set2   ,  -150,//PA
    TX_BPI_CTRL_DIS_Set2           ,  -120, //The time can not modify  
    MIPI_DEVICE2_TX_DISABLE_Set2   ,  -100,//ASM
    MIPI_DEVICE3_TX_DISABLE_Set2   ,   -70,//NO USE
    BPI_CONFLICT_CLEAR_Set2        ,   -30,
    VPA_DISABLE_Set2               ,     0,            
    END_Set2                       ,  END_Set2  // This line means the end of the actions,so it must be follow the last action.
},


//control action timing based on the beginning of the second timeslot must be sorted by an increasing order 
//timing advance range : -373 ~ 0
//DL_DL_GAP_CTRL_TIMING_DEFAULT[60]= 
{
    MIPI_DEVICE2_RX_ENABLE_Set2     , -300,//asm, TBD, need check ASM-RF group delay.
    RF_RXGAIN_SET_Set2              , -260,  
    MIPI_DEVICE1_RX_ENABLE_Set2     , -190,//no use
    MIPI_DEVICE3_RX_ENABLE_Set2     , -190,//no use      
    RX_BPI_CTRL_EN_Set2             , -80, // dl->dl tas need moify rf front end config                                              
    RXE_CFG_Set2                    , 0,
    RXE_TICK_SET_Set2               , 0,    
    RXDFE_MS_CFG_Set2               , 0,   
    RXDFE_GET_WBRSSI_Set2           , 0,
    END_Set2                     ,   END_Set2  // This line means the end of the actions,so it must be follow the last action. 

},


//control action timing based on the beginning of the second timeslot must be sorted by an increasing order 
//timing advance range : -250 ~ 0
//UL_UL_GAP_CTRL_TIMING_DEFAULT[60]= 
{
#if defined(__MT6291_TDD_RTL__)||defined(TL1_SIM)
    TXDFE_WIN_CTRL_Set2             ,    0,
#else
    TXDFE_WIN_CTRL_Set2             ,  -218,
#endif
    TXDFE_MODE_SEL_Set2             ,  -120,
    RF_TX_COMPENSATION_Set2         ,  -100,
    RF_TXGAIN_SET_Set2              ,  -110,
    VPA_ENABLE_Set2                ,  -105,    
    MIPI_DEVICE1_TX_ENABLE_Set2     ,  -100,//PA,TXIQ->PA delay 4us.
    END_Set2                        ,  END_Set2 // This line means the end of the actions,so it must be follow the last action.
},


//control action timing based on the beginning of downlink timeslot must be sorted by an increasing order 
//timing advance range : -400 ~ 0
//UL_DL_GAP_CTRL_TIMING_DEFAULT[60]= 
{
    MIPI_DEVICE3_TX_DISABLE_Set2   , 0,//no use
    ADC_ENABLE_Set2                ,    0,
    RXE_CFG_Set2                   , 0,            
    RXE_WIN_ON_Set2                , 0,      
    RXE_TICK_SET_Set2              , 0,       
    RX_BPI_CTRL_EN_Set2            , -200,       
    MIPI_DEVICE2_TR_ENABLE_Set2    , -190,//asms
    RF_RXGAIN_SET_Set2             , -185,
    RF_RX_ENABLE_Set2              , -180,
    MIPI_DEVICE1_TR_DISABLE_Set2   , -150,//PA        
    RXDFE_MS_CFG_Set2              ,  0,
    RF_RX_COMPENSATION_Set2        ,  0,//no use
    VPA_DISABLE_Set2               , 100, 
    END_Set2                       ,  END_Set2 // This line means the end of the actions,so it must be follow the last action.
 },
 
/**********************************Below is for B39*****************************************/
//control action timing based on the beginning of the timeslot must be sorted by an increasing order 
//timing advance range : -332 ~ 0
//ENABLE_UPLINK_TIMING_DEFAULT[60]= 
{
#if defined(__MT6291_TDD_RTL__)||defined(TL1_SIM)
    TXDFE_WIN_CTRL_Set2             ,      0,
#else
    TXDFE_WIN_CTRL_Set2             , -218,
#endif
    SRX_RELOCK_Set2                 , -720,
    VPA_ENABLE_Set2                 , -310,     
    MIPI_DEVICE3_TX_ENABLE_Set2     , -300,//no use
    MIPI_DEVICE1_TX_ENABLE_Set2     , -260,//pa txm
    MIPI_DEVICE2_TX_ENABLE_Set2     , -200,//asm txm
    TX_BPI_CTRL_EN_Set2             , -170,//BPI      
    RF_TX_ENABLE_Set2               , -150,
    RF_TXGAIN_SET_Set2              , -110,
    TXDFE_MODE_SEL_Set2             , -120,   /* not The time information is not used*/
    RF_TX_COMPENSATION_Set2         , -100,
    END_Set2                        ,   END_Set2  // This line means the end of the actions,so it must be follow the last action.                            
},


//control action timing based on the end of the timeslot must be sorted by an increasing order 
//timing advance range : -200 ~ +100
//DISABLE_UPLINK_TIMING_DEFAULT[60]= 
{
    RF_TX_DISABLE_Set2             ,  -160,
    MIPI_DEVICE1_TX_DISABLE_Set2   ,  -150,//PA
    TX_BPI_CTRL_DIS_Set2           ,  -120, //The time can not modify  
    MIPI_DEVICE2_TX_DISABLE_Set2   ,  -100,//ASM
    MIPI_DEVICE3_TX_DISABLE_Set2   ,   -70,//NO USE
    BPI_CONFLICT_CLEAR_Set2        ,   -30,
    VPA_DISABLE_Set2               ,     0, 
    END_Set2                       ,  END_Set2  // This line means the end of the actions,so it must be follow the last action.
},
/**********************************Above is for B39*****************************************/

/**********************************Below is for B40*****************************************/
//control action timing based on the beginning of the timeslot must be sorted by an increasing order 
//timing advance range : -332 ~ 0
//ENABLE_UPLINK_TIMING_DEFAULT[60]= 
{
#if defined(__MT6291_TDD_RTL__)||defined(TL1_SIM)
    TXDFE_WIN_CTRL_Set2             ,      0,
#else
    TXDFE_WIN_CTRL_Set2             , -218,
#endif
    SRX_RELOCK_Set2                 , -720,
    VPA_ENABLE_Set2                 , -310,     
    MIPI_DEVICE3_TX_ENABLE_Set2     , -300,//no use
    MIPI_DEVICE1_TX_ENABLE_Set2     , -260,//pa txm
    MIPI_DEVICE2_TX_ENABLE_Set2     , -200,//asm txm
    TX_BPI_CTRL_EN_Set2             , -170,//BPI      
    RF_TX_ENABLE_Set2               , -150,
    RF_TXGAIN_SET_Set2              , -110,
    TXDFE_MODE_SEL_Set2             , -120,   /* not The time information is not used*/
    RF_TX_COMPENSATION_Set2         , -100,
    END_Set2                        ,   END_Set2  // This line means the end of the actions,so it must be follow the last action.                            
},


//control action timing based on the end of the timeslot must be sorted by an increasing order 
//timing advance range : -200 ~ +100
//DISABLE_UPLINK_TIMING_DEFAULT[60]= 
{
    RF_TX_DISABLE_Set2             ,  -160,
    MIPI_DEVICE1_TX_DISABLE_Set2   ,  -150,//PA
    TX_BPI_CTRL_DIS_Set2           ,  -120, //The time can not modify  
    MIPI_DEVICE2_TX_DISABLE_Set2   ,  -100,//ASM
    MIPI_DEVICE3_TX_DISABLE_Set2   ,   -70,//NO USE
    BPI_CONFLICT_CLEAR_Set2        ,   -30,
    VPA_DISABLE_Set2               ,     0, 
    END_Set2                       ,  END_Set2  // This line means the end of the actions,so it must be follow the last action.
}

/**********************************Above is for B40*****************************************/

}};

#endif

#endif
