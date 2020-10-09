/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   tl1d_custom_mipi.h
 *
 * Project:
 * --------
 *   MT6176
 *
 * Description:
 * ------------
 *   MT6176 3G TDS RF constance definition
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *******************************************************************************/

#ifndef  _TL1D_CUSTOM_MIPI_Set2_H_
#define  _TL1D_CUSTOM_MIPI_Set2_H_
/* --------------------------------------------------------------------------- */
#include "tl1d_custom_drdi.h"

/*--------------------------------------------------------*/
/*   MIPI Module                                          */
/*--------------------------------------------------------*/
/*MT6176*/   #define  TDD_MIPI_PA_Set2       0xf         //DO NOT CHANGE
/*MT6176*/   #define  TDD_MIPI_ASM_Set2      0xb         //DO NOT CHANGE
/*MT6176*/   #define  DATA_NULL_Set2         0xffff
/*MT6176*/   #define  DEVICE_NULL_Set2       0xf0f0
/*MT6176*/   #define  PA_SEL_FLAG_Set2       0xf000      //PA mode selection 表示PA MODE通过设定PA积存器
/*MT6176*/   #define  PA_REG_NUM_B34_Set2    5           //RegNum
/*MT6176*/   #define  PA_REG_NUM_B39_Set2    5           //RegNum
/*MT6176*/   #define  TDD_MIPI_TR_SKIP_Set2 0x10            // TR Switch skip 
/*MT6176*/   #define  TDD_MIPI_ETM_Set2      0xc

/*--------------------------------------------------------*/
/*   MIPI Port                                            */
/*--------------------------------------------------------*/
/*MT6176*/   #define  MIPI_PORT0_Set2    0
/*MT6176*/   #define  MIPI_PORT1_Set2    1
/*MT6176*/   #define  MIPI_PORT2_Set2    2
/*MT6176*/   #define  MIPI_PORT3_Set2    3

/*--------------------------------------------------------*/
/*   for parsing tool                                     */
/*   bit0~bit3: usid; bit4~bit7: portindex                */
/*--------------------------------------------------------*/
/*MT6176*/   #define  MIPI_USID_INIT0_PORT0_Set2   0x0000
/*MT6176*/   #define  MIPI_USID_ASM0_PORT0_Set2    0x000E
/*MT6176*/   #define  MIPI_USID_ASM0_PORT3_Set2    0x003E
/*MT6176*/   #define  MIPI_USID_ASM1_PORT0_Set2    0x0008
/*MT6176*/   #define  MIPI_USID_ASM2_PORT0_Set2    0x000A
/*MT6176*/   #define  MIPI_USID_ASM3_PORT0_Set2    0x0009
/*MT6176*/   #define  MIPI_USID_PA0_PORT0_Set2     0x000E
/*MT6176*/   #define  MIPI_USID_PA0_PORT3_Set2     0x003E
/*MT6176*/   #define  MIPI_USID_PA1_PORT0_Set2     0x000E
/*MT6176*/   #define  MIPI_USID_ANT0_PORT0_Set2    0x0006

/*-----------------------------------------------------------*/
/*  ETM configuration                                       */
/*----------------------------------------------------------*/
/*MT6176*/   #define TDD_ETM_BAND34_ENABLE_Set2               0    //1: band34 ETM enable; 0: disable
/*MT6176*/   #define TDD_ETM_BAND39_ENABLE_Set2               0    //1: band39 ETM enable; 0: disable

/*MT6176*/   #define TDD_ETM_EVENT_A_len_Set2                 5    //Tx On A
/*MT6176*/   #define TDD_ETM_EVENT_B_len_Set2                 2    //Tx On B
/*MT6176*/   #define TDD_ETM_EVENT_C_len_Set2                 3    //Tx on c
/*MT6176*/   #define TDD_ETM_EVENT_D_len_Set2                 1    //Tx on D
/*MT6176*/   #define TDD_ETM_EVENT_E_len_Set2                 1    // TX TPC bank sel
/*MT6176*/   #define TDD_ETM_EVENT_F_len_Set2                 4    // TX off
/*MT6176*/   #define TDD_ETM_EVENT_G_len_Set2                 6    // TX TPC bank write
/*MT6176*/   #define TDD_ETM_VOLT_NUM_Set2                    2    // Tx volt write reg num



#if defined(_T12193_C_) 
 
T_MIPI_CUSTOMIZATION_STRUCT AST_TL1_RFFE_PARAMETER_DEFAULT_Set2[] ={
{
    //Init Register Number
    0,
    //MIPI DEVICE ID
    {
            TDD_MIPI_PA_Set2, //fixed, do not change      
            TDD_MIPI_ASM_Set2, //fixed, do not change
            DEVICE_NULL_Set2,
            DEVICE_NULL_Set2,
    },
    //MIPI Init data
    /*0:bit0:Band34 Enable; bit1:Band39 Enable; bit4:7 ETM USID; bit12:15 MIPI port
      1:bit0:3 EventA len; bit4:7 EnventB len; bit8:11 EventC len; bit12:15 EventD len
      2:bit0:3 EventE len; bit4:7 EventF len; bit8:11 EventG len; bit12:15 reg num fot volt
      3:7 EventA write reg/data; 
      8:9 EventB write reg/data; 
      10:12 EventC write reg/data;
      13 EventD write reg/data; 
      14:Event E write reg/data; 
      15:18 EventF write reg/data; 
      19:24 EventG PA high mode TPC data; 
      25:30 EventG PA middle mode TPC data;
      31:35 EventG PA Low mode TPC data
      e.g.0x7000: bit16:8 data; bit 7:0 reg addr
    */
    {
                            //    PORT            |     USID              |    BAND39_ETM_ENABLE        | BAND34_ETM_ENABLE
                     /*  0 */(MIPI_PORT2_Set2<<12) | (TDD_MIPI_ETM_Set2<<4)| (TDD_ETM_BAND39_ENABLE_Set2<<1) | TDD_ETM_BAND34_ENABLE_Set2,    
                     /*  1 */(TDD_ETM_EVENT_D_len_Set2<<12)|(TDD_ETM_EVENT_C_len_Set2<<8)|(TDD_ETM_EVENT_B_len_Set2<<4)|TDD_ETM_EVENT_A_len_Set2,
                    /*  2 */ (TDD_ETM_VOLT_NUM_Set2<<12)|(TDD_ETM_EVENT_G_len_Set2<<8) |(TDD_ETM_EVENT_F_len_Set2<<4) |TDD_ETM_EVENT_E_len_Set2,
                             /* addr: 0:7  data: 8:16*/      
                    /*  3 */ 0x7000,                         0x038E,                        0x0001,                        
                    /*  6 */ 0x0C08,                         0x0B0F,                        0x7400,
                    /*  9 */ 0x4209,                         0x076D,                        0x0383,
                    /*  12*/ 0x089A,                         0x0083,                        0x7400, 
                    /*  15*/ 0x0009,                         0x7000,                        0x0000,
                    /*  18*/ 0x0B6D,                         0x0101,                        0x5308, 
                    /*  21*/ 0x0A0F,                         0x5308,                        0x0A0F,
                    /*  24*/ 0x4209,                         0x0201,                        0x5308, 
                    /*  27*/ 0x0A0F,                         0x5308,                        0x0A0F, 
                    /*  30*/ 0x4209,                         0x0301,                        0x5308,                               
                    /*  33*/ 0x0A0F,                         0x5308,                        0x0A0F,                                   
    },
    //MIPI Event table
    {
            //Rx ON Event
            {
                /*            module       start    stop*/
                {  /*  0 */  TDD_MIPI_ASM_Set2  ,     0  ,     1 },
                {  /*  1 */  DATA_NULL_Set2 ,     0  ,     0 },
                {  /*  2 */  DATA_NULL_Set2 ,     0  ,     0 },
                {  /*  3 */  DATA_NULL_Set2 ,     0  ,     0 }
            },
            //Rx Off Event
            {   
                /*            module       start    stop*/
                {  /*  0 */  TDD_MIPI_ASM_Set2  ,     0  ,     2 },
                {  /*  1 */  DATA_NULL_Set2 ,     0  ,     0 },
                {  /*  2 */  DATA_NULL_Set2 ,     0  ,     0 },
                {  /*  3 */  DATA_NULL_Set2 ,     0  ,     0 }
            },
            //Tx ON Event
            {
                /*            module       start    stop*/
                {  /*  0 */  TDD_MIPI_PA_Set2   ,     0  ,     0 },
                {  /*  1 */  TDD_MIPI_ASM_Set2  ,     1  ,     1 },
                {  /*  2 */  DATA_NULL_Set2 ,     0  ,     0 },
                {  /*  3 */  DATA_NULL_Set2 ,     0  ,     0 }
            },
            //Tx Off Event
            {
                /*            module       start    stop*/
                {  /*  0 */  TDD_MIPI_PA_Set2  ,     0  ,     1},
                {  /*  1 */  DATA_NULL_Set2 ,     0  ,     0 },
                {  /*  2 */  DATA_NULL_Set2 ,     0  ,     0 },
                {  /*  3 */  DATA_NULL_Set2 ,     0  ,     0 }
            }
    },
    //MIPI Data table
    {
            //Rx On Data
            {
                /*            module      |     port          ,     band34 low 16bit    ,   band34 high 16bit   ,   band39 low 16bit   ,    band39 high 16bit  */
                {  /*  0 */  TDD_MIPI_ASM_Set2 | (MIPI_PORT0_Set2<<12) | (TDD_MIPI_TR_SKIP_Set2),                0x3800,                0x0E5C,                0x3800,                0x0E5C},
                {  /*  1 */  TDD_MIPI_ASM_Set2 | (MIPI_PORT0_Set2<<12),                0x0100,              0x0E45,                0x0200,                0x0E45},
                {  /*  2 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  3 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  4 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  5 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  6 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  7 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  8 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  9 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  0 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  1 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0}
            },
            //Rx Off Data
            {
                /*            module      |     port          ,     band34 low 16bit    ,   band34 high 16bit   ,   band39 low 16bit   ,    band39 high 16bit  */
                {  /*  0 */  TDD_MIPI_ASM_Set2     | (MIPI_PORT0_Set2<<12),                0x0000,                0x0E45,                0x0000,                0x0E45},
                {  /*  1 */  TDD_MIPI_ASM_Set2 | (MIPI_PORT0_Set2<<12),           0x8000,            0x1E43,           0x8000,            0x1E43},
                {  /*  2 */  TDD_MIPI_ASM_Set2 | (MIPI_PORT0_Set2<<12),           0xB800,            0x0E5C,           0xB800,            0x0E5C},
                {  /*  3 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  4 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  5 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  6 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  7 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  8 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  9 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  0 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  1 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0}
            },          
            //Tx On Data
            {
                /*            module      |     port          ,     band34 low 16bit    ,   band34 high 16bit   ,   band39 low 16bit   ,    band39 high 16bit  */
                {  /*  0 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),        PA_REG_NUM_B34_Set2,           PA_SEL_FLAG_Set2,        PA_REG_NUM_B39_Set2,           PA_SEL_FLAG_Set2},
                {  /*  1 */  TDD_MIPI_ASM_Set2     | (MIPI_PORT0_Set2<<12),                0x0F00,                0x0E45,                0x0F00,                0x0E45},
                {  /*  2 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  3 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  4 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  5 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  6 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  7 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  8 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  9 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  0 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  1 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0}
            },            
            //Tx Off Data
            { 
                /*            module      |     port          ,     band34 low 16bit    ,   band34 high 16bit   ,   band39 low 16bit   ,    band39 high 16bit  */
                {  /*  0 */  TDD_MIPI_PA_Set2  | (MIPI_PORT0_Set2<<12)|(TDD_MIPI_TR_SKIP_Set2),           0x8000,            0x1E43,           0x8000,           0x1E43},
                {  /*  1 */  TDD_MIPI_PA_Set2     | (MIPI_PORT0_Set2<<12)|(TDD_MIPI_TR_SKIP_Set2),                0xB800,                0x0E5C,                0xB800,                0x0E5C},
                {  /*  2 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  3 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  4 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  5 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  6 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  7 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  8 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  9 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  0 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0},
                {  /*  1 */  DATA_NULL_Set2    |          (0<<12),                     0,                     0,                     0,                     0}
            }
    },
    //PA MODE SETTING
    {         
           {
                /*            module      |     port          ,     band34 low 16bit    ,   band34 high 16bit   ,   band39 low 16bit   ,    band39 high 16bit  */
                {  /*  0 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x3800,                0x0E5C,                0x3800,                0x0E5C},//FOR PA HIGH MODE
                {  /*  1 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x8F00,                0x0E40,                0x8F00,                0x0E40},//FOR PA HIGH MODE
                {  /*  2 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x8E00,                0x0E41,                0x8E00,                0x0E41},//FOR PA HIGH MODE
                {  /*  3 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x0000,                0x0E44,                0x0000,                0x0E44},//FOR PA HIGH MODE
                {  /*  4 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x0000,                0x0E42,                0x0000,                0x0E42},//FOR PA HIGH MODE            
            },
            {
                /*            module      |     port          ,     band34 low 16bit    ,   band34 high 16bit   ,   band39 low 16bit   ,    band39 high 16bit  */
                {  /*  0 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x3800,                0x0E5C,                0x3800,                0x0E5C},//FOR PA MIDDLE MODE
                {  /*  1 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0xAF00,                0x0E40,                0xAF00,                0x0E40},//FOR PA MIDDLE MODE
                {  /*  2 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x2800,                0x0E41,                0x2800,                0x0E41},//FOR PA MIDDLE MODE
                {  /*  3 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x0000,                0x0E44,                0x0000,                0x0E44},//FOR PA MIDDLE MODE
                {  /*  4 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x0000,                0x0E42,                0x0000,                0x0E42},//FOR PA MIDDLE MODE
            },
            {
                /*            module      |     port          ,     band34 low 16bit    ,   band34 high 16bit   ,   band39 low 16bit   ,    band39 high 16bit  */
                {  /*  0 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x3800,                0x0E5C,                0x3800,                0x0E5C},//FOR PA LOW MODE
                {  /*  1 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0xAF00,                0x0E40,                0xAF00,                0x0E40},//FOR PA LOW MODE
                {  /*  2 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x2800,                0x0E41,                0x2800,                0x0E41},//FOR PA LOW MODE
                {  /*  3 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x0000,                0x0E44,                0x0000,                0x0E44},//FOR PA LOW MODE
                {  /*  4 */  TDD_MIPI_PA_Set2      | (MIPI_PORT0_Set2<<12),            0x0000,                0x0E42,                0x0000,                0x0E42},//FOR PA LOW MODE
            }   
    }
}};
#endif

#endif
