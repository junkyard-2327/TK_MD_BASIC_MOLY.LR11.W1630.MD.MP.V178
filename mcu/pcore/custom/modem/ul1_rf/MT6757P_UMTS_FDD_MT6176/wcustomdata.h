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
 *	wcustomdata.h
 *
 * Project:
 * --------
 *  Dual Mode 3G Project
 *
 * Description:
 * ------------
 *  Dynamic RF parameters custom macro definitions
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/

#ifndef  _WCUSTOMDATA_H_
#define  _WCUSTOMDATA_H_


/*******************************************************************************
** Includes
*******************************************************************************/
#include "kal_general_types.h"
#include "ul1cal.h"

#include "mml1_custom_drdi.h"

/****************************************************************************
 * Csutomization Defines
 ****************************************************************************/

/********************
 * Common
 *******************/
/*****************************************************************************
* Constant    : UL1CUSTOM_GPIO_ENABLE
*               UL1CUSTOM_ADC_ENABLE
*               UL1CUSTOM_NVRAM_BARCODE_ENABLE
* Group       : Real target, Customization, UL1D common operation
* Description : Constants to enable "Dynamic Initialization RF parameters"
*               mechanism
*****************************************************************************/
#define UL1CUSTOM_GPIO_ENABLE           (0)
#define UL1CUSTOM_ADC_ENABLE            (0)
#define UL1CUSTOM_NVRAM_BARCODE_ENABLE  (0)

#define UL1CUSTOM_DRDI_ENABLE IS_MML1_DRDI_ENABLE

#if UL1CUSTOM_DRDI_ENABLE
#define UL1CUSTOM_TOTAL_REAL_SET_NUMS MML1_DRDI_REMAP_UMTS_REAL_SET_NUMS
#else
#define UL1CUSTOM_TOTAL_REAL_SET_NUMS 1
#endif

/*****************************************************************************
* Constant    : UL1CUSTOM_GPIO_SET_NUMS
*               UL1CUSTOM_ADC_SET_NUMS
*               UL1CUSTOM_NVRAM_BARCODE_SET_NUMS
* Group       : Real target, Customization, UL1D common operation
* Description : Constants to define number of sets can be represented by each
*               mechanism respectively
*****************************************************************************/
#define UL1CUSTOM_GPIO_SET_NUMS           (2)
#define UL1CUSTOM_ADC_SET_NUMS            (0)
#define UL1CUSTOM_NVRAM_BARCODE_SET_NUMS  (0)

/*****************************************************************************
* Constant    : UL1CUSTOM_FIRST_INDEX
*               UL1CUSTOM_SECOND_INDEX
*               UL1CUSTOM_THIRD_INDEX
* Group       : Real target, Customization, UL1D common operation
* Description : Constants to first, second and third index for the
*               representation in configuration set index table
*****************************************************************************/
#define UL1CUSTOM_FIRST_INDEX   (UL1CUSTOM_NULL_ACTION)
#define UL1CUSTOM_SECOND_INDEX  (UL1CUSTOM_NULL_ACTION)
#define UL1CUSTOM_THIRD_INDEX   (UL1CUSTOM_NULL_ACTION)

/*****************************************************************************
* Constant    : UL1CUSTOM_DEBUG_ENABLE
* Group       : Real target, Customization, UL1D common operation
* Description : Constants to enable "Dynamic Initialization RF parameters"
*               debug info logging, which will save debug info into NVRAM
*               LID NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_LID
*****************************************************************************/
#define UL1CUSTOM_DEBUG_ENABLE  (1)


/********************
 * GPIO
 *******************/
/*****************************************************************************
* Constant    : UL1CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE
* Group       : Real target, Customization, UL1D common operation
* Description : Customization constant to be used for customer to determine
*               the number of GPIO detection pins in use
*****************************************************************************/
#define UL1CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE  (0)

/********************
 * ADC
 *******************/
/* Sample of ADC votlage to level look-up table

---------------------------------------------------------------------
ADC levels - 8

Level   Level(V)        Level(uV)       Upper(uV)       Lower(uV)
0       0.089285        89285           178571          0
1       0.357142        357142          535713          178571
2       0.714284        714284          892855          535713
3       1.071426        1071426         1249997         892855
4       1.428568        1428568         1607139         1249997
5       1.78571         1785710         1964281         1607139
6       2.142852        2142852         2321423         1964281
7       2.410711        2410711         2500000         2321423

---------------------------------------------------------------------
ADC levels - 6

Level   Level(V)        Level(uV)       Upper(uV)       Lower(uV)
0       0.125           125000          250000          0
1       0.5             500000          750000          250000
2       1               1000000         1250000         750000
3       1.5             1500000         1750000         1250000
4       2               2000000         2250000         1750000
5       2.375           2375000         2500000         2250000

---------------------------------------------------------------------
ADC levels - 4

Level   Level(V)        Level(uV)       Upper(uV)       Lower(uV)
0       0.208333        208333          416666          0
1       0.833332        833332          1249999         416666
2       1.666665        1666665         2083332         1249999
3       2.291666        2291666         2500000         2083332


---------------------------------------------------------------------
ADC levels - 2

Level   Level(V)        Level(uV)       Upper(uV)       Lower(uV)
0       0.625           625000          1250000         0
1       1.875           1875000         2500000         1250000

*/

/*****************************************************************************
* Constant    : UL1CUSTOM_ADC_LEVEL_TOTAL
* Group       : Real target, Customization, UL1D common operation
* Description : Customization constant to be used for customer to determine
*               number of ADC levels to be used to distinguish between the
*               RF HW configurations
*****************************************************************************/
#define UL1CUSTOM_ADC_LEVEL_TOTAL         (4)

/*****************************************************************************
* Constant    : UL1CUSTOM_ADC_MEAS_COUNT_2_ORDER
* Group       : Real target, Customization, UL1D common operation
* Description : Customization constant to be used for customer to determine
*               number of ADC channel measurement counts (in 2's order)
*               ex: 7 => 2^7 = 128
*****************************************************************************/
#define UL1CUSTOM_ADC_MEAS_COUNT_2_ORDER  (7) //2^7 = 128

#define UL1CUSTOM_ADC_LVL0  (UL1CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP)
#define UL1CUSTOM_ADC_LVL1  (UL1CUSTOM_ADC_LVL0 + UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
#define UL1CUSTOM_ADC_LVL2  (UL1CUSTOM_ADC_LVL1 + UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
#define UL1CUSTOM_ADC_LVL3  (UL1CUSTOM_ADC_LVL2 + UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
#define UL1CUSTOM_ADC_LVL4  (UL1CUSTOM_ADC_LVL3 + UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
#define UL1CUSTOM_ADC_LVL5  (UL1CUSTOM_ADC_LVL4 + UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
#define UL1CUSTOM_ADC_LVL6  (UL1CUSTOM_ADC_LVL5 + UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE)

/********************
 * NVRAM Barcode
 *******************/
/*****************************************************************************
* Constant    : UL1CUSTOM_BARCODE_READ_DIGIT_NUM
* Group       : Real target, Customization, UL1D common operation
* Description : Customization constant to be used for customer to determine
*               the n:th digit of UE barcode to detect the RF configurations
*               n starts from 0
*****************************************************************************/
#define UL1CUSTOM_BARCODE_READ_DIGIT_NUM  (5)

/*****************************************************************************
* Constant    : UL1CUSTOM_BARCODE_DIGIT_VALUE_X
* Group       : Real target, Customization, UL1D common operation
* Description : Customization constant to be used for customer to determine
*               at most three (for now) kinds of ASM representation barcode
*               digit number (in ASCII) to detect the RF configurations
*****************************************************************************/
#define UL1CUSTOM_BARCODE_DIGIT_VALUE_1   (8) // ex: for MURATA_SP7T
#define UL1CUSTOM_BARCODE_DIGIT_VALUE_2   (7) // ex: for MURATA_SP10T
#define UL1CUSTOM_BARCODE_DIGIT_VALUE_3   (3) // ex: for RFMD1291

/****************************************************************************
 * Custom Data Extern
 ****************************************************************************/





/****************************************************************************
 * Below defines not allowed customer to modify
 * Below defines not allowed customer to modify
 * Below defines not allowed customer to modify
 * Below defines not allowed customer to modify
 * Below defines not allowed customer to modify
 ****************************************************************************/

/********************
 * ADC
 *******************/
/*****************************************************************************
* Constant    : UL1CUSTOM_ADC_BITS
* Group       : Real target, Customization, UL1D common operation
* Description : Customization constant to be used for customer to determine
*               the bits of ADC in use
*****************************************************************************/
#define UL1CUSTOM_ADC_BITS                (12) // MT6573/MT6575 ADC is 12 bit (1/4096) per step

/*****************************************************************************
* Constant    : UL1CUSTOM_ADC_MAX_INPUT_VOLTAGE
* Group       : Real target, Internals, UL1D common operation
* Description : Constant to be used to determine the maximum input voltage
*               on the board, in micro volt unit
*****************************************************************************/
#define UL1CUSTOM_ADC_MAX_INPUT_VOLTAGE   (2500000) // uV unit

/*****************************************************************************
* Constant    : UL1CUSTOM_ADC_INACCURACY_MARGIN
* Group       : Real target, Customization, UL1D common operation
* Description : Customization constant to be used for customer to determine
*               the inaccuracy margin (in micro volt unit) on the board
*****************************************************************************/
#define UL1CUSTOM_ADC_INACCURACY_MARGIN   (50000) // uV uint

/*******************************************************************************************
* Constant    : UL1CUSTOM_ADC_VOLT_LVL_RESOLUTION_THRESHOLD
*               UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE
*               UL1CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP
* Group       : Real target, Internals, UL1D common operation
* Description : Constant to be used to determine the each step level of
*               ADC voltage to level look-up table on the board, in micro volt unit
*
*               UL1CUSTOM_ADC_VOLT_LVL_RESOLUTION_THRESHOLD - two times inaccuracy margin
*               UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE - step size of consecutive levels
*               UL1CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP - the first level upper bound to 0 volt
*******************************************************************************************/
#define UL1CUSTOM_ADC_VOLT_LVL_RESOLUTION_THRESHOLD  (UL1CUSTOM_ADC_INACCURACY_MARGIN * 2)
#define UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE             ( (UL1CUSTOM_ADC_MAX_INPUT_VOLTAGE) / (UL1CUSTOM_ADC_LEVEL_TOTAL - 1) )
#define UL1CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP          (UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE / 2)


/* Error check pre-compile processing */
/* Error check pre-compile processing */
/* Error check pre-compile processing */
#if ( (UL1CUSTOM_ADC_VOLT_LVL_STEP_SIZE - UL1CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP) < UL1CUSTOM_ADC_VOLT_LVL_RESOLUTION_THRESHOLD)
#error "Too much ADC voltage level, please decrease the defined UL1CUSTOM_ADC_LEVEL_TOTAL value"
#endif

#if (UL1CUSTOM_ADC_LVL1 < UL1CUSTOM_ADC_INACCURACY_MARGIN)
#error "Too large inaccuracy error margin, please redefine UL1CUSTOM_ADC_INACCURACY_MARGIN"
#endif

/********************
 * Common
 *******************/
/* Error check pre-compile processing to check rediculous index definitions */
#if (UL1CUSTOM_THIRD_INDEX != UL1CUSTOM_NULL_ACTION)
   #if (UL1CUSTOM_SECOND_INDEX == UL1CUSTOM_NULL_ACTION)  || (UL1CUSTOM_FIRST_INDEX == UL1CUSTOM_NULL_ACTION)
   #error "Should not define UL1CUSTOM_SECOND_INDEX or UL1CUSTOM_FIRST_INDEX to UL1CUSTOM_NULL_ACTION_ID while UL1CUSTOM_THIRD_INDEX is not UL1CUSTOM_NULL_ACTION_ID"
   #endif
#endif

#if (UL1CUSTOM_SECOND_INDEX != UL1CUSTOM_NULL_ACTION)
   #if (UL1CUSTOM_FIRST_INDEX == UL1CUSTOM_NULL_ACTION)
   #error "Should not define UL1CUSTOM_FIRST_INDEX to UL1CUSTOM_NULL_ACTION_ID while UL1CUSTOM_SECOND_INDEX is not UL1CUSTOM_NULL_ACTION_ID"
   #endif
#endif

/* Define the first index base */
#if (UL1CUSTOM_FIRST_INDEX == UL1CUSTOM_NULL_ACTION)
   #if (UL1CUSTOM_SECOND_INDEX == UL1CUSTOM_NULL_ACTION) && (UL1CUSTOM_THIRD_INDEX == UL1CUSTOM_NULL_ACTION)
   #define UL1CUSTOM_FIRST_INDEX_BASE  (0)
   #else
   #error "UL1CUSTOM_FIRST_INDEX can not be defined to UL1CUSTOM_NULL_ACTION_ID while either UL1CUSTOM_SECOND_INDEX or UL1CUSTOM_THIRD_INDEX not UL1CUSTOM_NULL_ACTION_ID"
   #endif 
#else
   #define UL1CUSTOM_FIRST_INDEX_BASE  (1)
#endif

/*****************************************************************************
* Constant    : UL1CUSTOM_GPIO_NUMS_IN_CALC
*               UL1CUSTOM_ADC_NUMS_IN_CALC
*               UL1CUSTOM_NVRAM_BARCODE_NUMS_IN_CALC
* Group       : Real target, Internals, UL1D common operation
* Description : Constant for the second and third index base to be calculated
*****************************************************************************/
#if (UL1CUSTOM_GPIO_ENABLE)
#define UL1CUSTOM_GPIO_NUMS_IN_CALC            (UL1CUSTOM_GPIO_SET_NUMS)
#else
#define UL1CUSTOM_GPIO_NUMS_IN_CALC            (1)
#endif

#if (UL1CUSTOM_ADC_ENABLE)
#define UL1CUSTOM_ADC_NUMS_IN_CALC             (UL1CUSTOM_ADC_SET_NUMS)
#else
#define UL1CUSTOM_ADC_NUMS_IN_CALC             (1)
#endif

#if (UL1CUSTOM_NVRAM_BARCODE_ENABLE)
#define UL1CUSTOM_NVRAM_BARCODE_NUMS_IN_CALC   (UL1CUSTOM_NVRAM_BARCODE_SET_NUMS)
#else
#define UL1CUSTOM_NVRAM_BARCODE_NUMS_IN_CALC   (1)
#endif

/*****************************************************************************
* Constant    : UL1CUSTOM_TOTAL_SET_NUMS
* Group       : Real target, Internals, UL1D common operation
* Description : Constant to be used as the number of total configuration sets
*****************************************************************************/
#define UL1CUSTOM_TOTAL_SET_NUMS  (UL1CUSTOM_GPIO_NUMS_IN_CALC * UL1CUSTOM_ADC_NUMS_IN_CALC * UL1CUSTOM_NVRAM_BARCODE_NUMS_IN_CALC)

/*****************************************************************************
* Constant    : UL1CUSTOM_ADC_CALIBARTE_ENABLE
* Group       : Real target, Customization, UL1D common operation
* Description : Customization constant to be used for customer to determine
*               if AuxADC calibration is enabled or not
*****************************************************************************/
#define UL1CUSTOM_ADC_CALIBARTE_ENABLE    (0)


/****************************************************************************
 * Function Prototypes
 ****************************************************************************/
void UL1CUSTOM_ReplaceAuxAdcCalibrate(kal_uint32 adcDigitalValue, kal_int32 *volt);


/***************************************************************************
 * Global Function extern
 ***************************************************************************/
extern void UL1CUSTOM_DynamicInitByGPIO(void *data);
extern void UL1CUSTOM_DynamicInitByADC(void *data);
extern void UL1CUSTOM_DynamicInitByNvramBarcode(void *data);

//*************************************************
// UMTS Rx calibration data Custom data definition
//*************************************************

#if (IS_3G_DRDI_SUPPORT)
#define UMTS_CAL_CUSTOM_DATA(sET)   \
{                                   \
    U_AGC_PATHLOSS_TABLE_##sET      \
   ,U_AGC_PATHLOSS_RXD_TABLE_##sET  \
   ,U_PA_OCTLEV_TABLE_##sET         \
   ,U_PA_RACH_COMP_TABLE_##sET      \
   ,U_PA_DRIFT_TABLE_##sET          \
   ,UMTS_RampData_##sET             \
   ,U_TEMP_DAC_##sET                \
   ,&U_AFC_CAP_##sET                \
   ,&U_AFC_DAC_##sET                \
}

#if (IS_3G_ET_SUPPORT)
#define UMTS_MIPI_CUSTOM_DATA(sET)                \
   {                                              \
        MIPI_ENABLE    /*IS_3G_MIPI_ENABLE*/      \
       ,UMTS_MIPI_RX_EVENT_TABLE_##sET            \
       ,UMTS_MIPI_RX_DATA_TABLE_##sET             \
       ,UMTS_MIPI_TX_EVENT_TABLE_##sET            \
       ,UMTS_MIPI_TX_DATA_TABLE_##sET             \
       ,UMTS_MIPI_TPC_TABLE_##sET                 \
       ,UMTS_MIPI_ASM_ISOLATION_DATA_TABLE_##sET  \
       ,UMTS_MIPI_ET_TABLE_##sET                  \
       ,UMTS_MIPI_ET_ON_STATIC_CW_##sET           \
       ,UMTS_MIPI_ET_OFF_STATIC_CW_##sET          \
       ,&UL1_ET_PARAM_##sET                       \
       ,UMTS_VPA_SRC_SEL_TABLE_##sET              \
   }
#else
#define UMTS_MIPI_CUSTOM_DATA(sET)                \
   {                                              \
        MIPI_ENABLE    /*IS_3G_MIPI_ENABLE*/      \
       ,UMTS_MIPI_RX_EVENT_TABLE_##sET            \
       ,UMTS_MIPI_RX_DATA_TABLE_##sET             \
       ,UMTS_MIPI_TX_EVENT_TABLE_##sET            \
       ,UMTS_MIPI_TX_DATA_TABLE_##sET             \
       ,UMTS_MIPI_TPC_TABLE_##sET                 \
       ,UMTS_MIPI_ASM_ISOLATION_DATA_TABLE_##sET  \
   }
#endif
#if (IS_3G_TAS_ANTENNA_IDX_ON_TEST_SIM)
#define UMTS_TAS_CUSTOM_DATA(sET)       \
{                                       \
   {                                    \
      UMTS_TAS_BPI_PIN_MASK_##sET,      \
      {                                 \
         /*umtsTasPdata*/               \
         PDATA_Band1_TAS1_##sET,        \
         PDATA_Band1_TAS2_##sET,        \
         PDATA_Band1_TAS3_##sET,        \
         PDATA_Band2_TAS1_##sET,        \
         PDATA_Band2_TAS2_##sET,        \
         PDATA_Band2_TAS3_##sET,        \
         PDATA_Band3_TAS1_##sET,        \
         PDATA_Band3_TAS2_##sET,        \
         PDATA_Band3_TAS3_##sET,        \
         PDATA_Band4_TAS1_##sET,        \
         PDATA_Band4_TAS2_##sET,        \
         PDATA_Band4_TAS3_##sET,        \
         PDATA_Band5_TAS1_##sET,        \
         PDATA_Band5_TAS2_##sET,        \
         PDATA_Band5_TAS3_##sET,        \
         PDATA_Band6_TAS1_##sET,        \
         PDATA_Band6_TAS2_##sET,        \
         PDATA_Band6_TAS3_##sET,        \
         PDATA_Band7_TAS1_##sET,        \
         PDATA_Band7_TAS2_##sET,        \
         PDATA_Band7_TAS3_##sET,        \
         PDATA_Band8_TAS1_##sET,        \
         PDATA_Band8_TAS2_##sET,        \
         PDATA_Band8_TAS3_##sET,        \
         PDATA_Band9_TAS1_##sET,        \
         PDATA_Band9_TAS2_##sET,        \
         PDATA_Band9_TAS3_##sET,        \
         PDATA_Band10_TAS1_##sET,       \
         PDATA_Band10_TAS2_##sET,       \
         PDATA_Band10_TAS3_##sET,       \
         PDATA_Band11_TAS1_##sET,       \
         PDATA_Band11_TAS2_##sET,       \
         PDATA_Band11_TAS3_##sET,       \
         PDATA_Band19_TAS1_##sET,       \
         PDATA_Band19_TAS2_##sET,       \
         PDATA_Band19_TAS3_##sET        \
      }                                 \
   },                                   \
   &UMTS_TAS_Configuration_Table_##sET, \
   {                                    \
      UMTS_TAS_INIT_ANT_Band1_##sET,    \
      UMTS_TAS_INIT_ANT_Band2_##sET,    \
      UMTS_TAS_INIT_ANT_Band3_##sET,    \
      UMTS_TAS_INIT_ANT_Band4_##sET,    \
      UMTS_TAS_INIT_ANT_Band5_##sET,    \
      UMTS_TAS_INIT_ANT_Band6_##sET,    \
      UMTS_TAS_INIT_ANT_Band8_##sET,    \
      UMTS_TAS_INIT_ANT_Band9_##sET,    \
      UMTS_TAS_INIT_ANT_Band10_##sET,   \
      UMTS_TAS_INIT_ANT_Band11_##sET,   \
      UMTS_TAS_INIT_ANT_Band19_##sET    \
   }                                    \
}
#else
#define UMTS_TAS_CUSTOM_DATA(sET)       \
{                                       \
   {                                    \
      UMTS_TAS_BPI_PIN_MASK_##sET,      \
      {                                 \
         /*umtsTasPdata*/               \
         PDATA_Band1_TAS1_##sET,        \
         PDATA_Band1_TAS2_##sET,        \
         PDATA_Band1_TAS3_##sET,        \
         PDATA_Band2_TAS1_##sET,        \
         PDATA_Band2_TAS2_##sET,        \
         PDATA_Band2_TAS3_##sET,        \
         PDATA_Band3_TAS1_##sET,        \
         PDATA_Band3_TAS2_##sET,        \
         PDATA_Band3_TAS3_##sET,        \
         PDATA_Band4_TAS1_##sET,        \
         PDATA_Band4_TAS2_##sET,        \
         PDATA_Band4_TAS3_##sET,        \
         PDATA_Band5_TAS1_##sET,        \
         PDATA_Band5_TAS2_##sET,        \
         PDATA_Band5_TAS3_##sET,        \
         PDATA_Band6_TAS1_##sET,        \
         PDATA_Band6_TAS2_##sET,        \
         PDATA_Band6_TAS3_##sET,        \
         PDATA_Band7_TAS1_##sET,        \
         PDATA_Band7_TAS2_##sET,        \
         PDATA_Band7_TAS3_##sET,        \
         PDATA_Band8_TAS1_##sET,        \
         PDATA_Band8_TAS2_##sET,        \
         PDATA_Band8_TAS3_##sET,        \
         PDATA_Band9_TAS1_##sET,        \
         PDATA_Band9_TAS2_##sET,        \
         PDATA_Band9_TAS3_##sET,        \
         PDATA_Band10_TAS1_##sET,       \
         PDATA_Band10_TAS2_##sET,       \
         PDATA_Band10_TAS3_##sET,       \
         PDATA_Band11_TAS1_##sET,       \
         PDATA_Band11_TAS2_##sET,       \
         PDATA_Band11_TAS3_##sET,       \
         PDATA_Band19_TAS1_##sET,       \
         PDATA_Band19_TAS2_##sET,       \
         PDATA_Band19_TAS3_##sET        \
      }                                 \
   },                                   \
   &UMTS_TAS_Configuration_Table_##sET  \
}
#endif

#if IS_3G_BAND5_AND_BAND6_INDICATOR_SUPPORT
#if (IS_3G_ET_SUPPORT)
#define UMTS_RF_PARAMETER(sET)            \
{                                         \
   PMU_PASETTING_##sET,                   \
   RX_DIVERSITY_ALWAYS_ON_##sET,          \
   ULTRA_LOW_COST_EN_##sET,               \
   PA_DIRFT_COMPENSATION_##sET,           \
   PA_SECTION_##sET,                      \
   BAND5_AND_BAND6_INDICATOR_##sET,       \
   {                                      \
      -TC_PR1_##sET,                      \
      -TC_PR2_##sET,                      \
      -TC_PR2B_##sET,                     \
       TC_PR3_##sET,                      \
       TC_PR3_##sET+20,                   \
      -TC_PT1_##sET,                      \
      -TC_PT2_##sET,                      \
      -TC_PT2B_##sET,                     \
       TC_PT3_##sET,                      \
       TC_PT3_##sET+20                    \
   },                                     \
   {                                      \
      MAX_OFFSET_##sET,                   \
      VM_OFFSET_##sET,                    \
      VBIAS_OFFSET_##sET,                 \
      DC2DC_OFFSET_##sET,                 \
      VGA_OFFSET_##sET                    \
   },                                     \
   {                                      \
      {                                   \
         MPR_BACK_OFF_HSDPA_BAND1_##sET , MPR_BACK_OFF_HSDPA_BAND2_##sET , MPR_BACK_OFF_HSDPA_BAND3_##sET , MPR_BACK_OFF_HSDPA_BAND4_##sET , MPR_BACK_OFF_HSDPA_BAND5_##sET , \
         MPR_BACK_OFF_HSDPA_BAND6_##sET , MPR_BACK_OFF_HSDPA_BAND7       , MPR_BACK_OFF_HSDPA_BAND8_##sET , MPR_BACK_OFF_HSDPA_BAND9_##sET , MPR_BACK_OFF_HSDPA_BAND10_##sET, \
         MPR_BACK_OFF_HSDPA_BAND11_##sET, MPR_BACK_OFF_HSDPA_BAND12      , MPR_BACK_OFF_HSDPA_BAND13      , MPR_BACK_OFF_HSDPA_BAND14      , MPR_BACK_OFF_HSDPA_BAND15      , \
         MPR_BACK_OFF_HSDPA_BAND16      , MPR_BACK_OFF_HSDPA_BAND16      , MPR_BACK_OFF_HSDPA_BAND17      , MPR_BACK_OFF_HSDPA_BAND18      , MPR_BACK_OFF_HSDPA_BAND19_##sET  \
      },                                                                                                                                                                      \
      {                                                                                                                                                                       \
         MPR_BACK_OFF_HSUPA_BAND1_##sET , MPR_BACK_OFF_HSUPA_BAND2_##sET , MPR_BACK_OFF_HSUPA_BAND3_##sET , MPR_BACK_OFF_HSUPA_BAND4_##sET , MPR_BACK_OFF_HSUPA_BAND5_##sET , \
         MPR_BACK_OFF_HSUPA_BAND6_##sET , MPR_BACK_OFF_HSUPA_BAND7       , MPR_BACK_OFF_HSUPA_BAND8       , MPR_BACK_OFF_HSUPA_BAND9       , MPR_BACK_OFF_HSUPA_BAND10      , \
         MPR_BACK_OFF_HSUPA_BAND11      , MPR_BACK_OFF_HSUPA_BAND12      , MPR_BACK_OFF_HSUPA_BAND13      , MPR_BACK_OFF_HSUPA_BAND14      , MPR_BACK_OFF_HSUPA_BAND15      , \
         MPR_BACK_OFF_HSUPA_BAND16      , MPR_BACK_OFF_HSUPA_BAND16      , MPR_BACK_OFF_HSUPA_BAND17      , MPR_BACK_OFF_HSUPA_BAND18      , MPR_BACK_OFF_HSUPA_BAND19_##sET  \
      }                                   \
   },                                     \
   {                                      \
      IS_3G_MIPI_ENABLE_##sET,            \
      MIPI_OFFSET_##sET,                  \
      IS_3G_ET_ENABLE_##sET,              \
   }                                      \
}
#else
#define UMTS_RF_PARAMETER(sET)            \
{                                         \
   PMU_PASETTING_##sET,                   \
   RX_DIVERSITY_ALWAYS_ON_##sET,          \
   ULTRA_LOW_COST_EN_##sET,               \
   PA_DIRFT_COMPENSATION_##sET,           \
   PA_SECTION_##sET,                      \
   BAND5_AND_BAND6_INDICATOR_##sET,       \
   {                                      \
      -TC_PR1_##sET,                      \
      -TC_PR2_##sET,                      \
      -TC_PR2B_##sET,                     \
       TC_PR3_##sET,                      \
       TC_PR3_##sET+20,                   \
      -TC_PT1_##sET,                      \
      -TC_PT2_##sET,                      \
      -TC_PT2B_##sET,                     \
       TC_PT3_##sET,                      \
       TC_PT3_##sET+20                    \
   },                                     \
   {                                      \
      MAX_OFFSET_##sET,                   \
      VM_OFFSET_##sET,                    \
      VBIAS_OFFSET_##sET,                 \
      DC2DC_OFFSET_##sET,                 \
      VGA_OFFSET_##sET                    \
   },                                     \
   {                                      \
      {                                   \
         MPR_BACK_OFF_HSDPA_BAND1_##sET , MPR_BACK_OFF_HSDPA_BAND2_##sET , MPR_BACK_OFF_HSDPA_BAND3_##sET , MPR_BACK_OFF_HSDPA_BAND4_##sET , MPR_BACK_OFF_HSDPA_BAND5_##sET , \
         MPR_BACK_OFF_HSDPA_BAND6_##sET , MPR_BACK_OFF_HSDPA_BAND7       , MPR_BACK_OFF_HSDPA_BAND8_##sET , MPR_BACK_OFF_HSDPA_BAND9_##sET , MPR_BACK_OFF_HSDPA_BAND10_##sET, \
         MPR_BACK_OFF_HSDPA_BAND11_##sET, MPR_BACK_OFF_HSDPA_BAND12      , MPR_BACK_OFF_HSDPA_BAND13      , MPR_BACK_OFF_HSDPA_BAND14      , MPR_BACK_OFF_HSDPA_BAND15      , \
         MPR_BACK_OFF_HSDPA_BAND16      , MPR_BACK_OFF_HSDPA_BAND16      , MPR_BACK_OFF_HSDPA_BAND17      , MPR_BACK_OFF_HSDPA_BAND18      , MPR_BACK_OFF_HSDPA_BAND19_##sET  \
      },                                                                                                                                                                      \
      {                                                                                                                                                                       \
         MPR_BACK_OFF_HSUPA_BAND1_##sET , MPR_BACK_OFF_HSUPA_BAND2_##sET , MPR_BACK_OFF_HSUPA_BAND3_##sET , MPR_BACK_OFF_HSUPA_BAND4_##sET , MPR_BACK_OFF_HSUPA_BAND5_##sET , \
         MPR_BACK_OFF_HSUPA_BAND6_##sET , MPR_BACK_OFF_HSUPA_BAND7       , MPR_BACK_OFF_HSUPA_BAND8       , MPR_BACK_OFF_HSUPA_BAND9       , MPR_BACK_OFF_HSUPA_BAND10      , \
         MPR_BACK_OFF_HSUPA_BAND11      , MPR_BACK_OFF_HSUPA_BAND12      , MPR_BACK_OFF_HSUPA_BAND13      , MPR_BACK_OFF_HSUPA_BAND14      , MPR_BACK_OFF_HSUPA_BAND15      , \
         MPR_BACK_OFF_HSUPA_BAND16      , MPR_BACK_OFF_HSUPA_BAND16      , MPR_BACK_OFF_HSUPA_BAND17      , MPR_BACK_OFF_HSUPA_BAND18      , MPR_BACK_OFF_HSUPA_BAND19_##sET  \
      }                                   \
   },                                     \
   {                                      \
      IS_3G_MIPI_ENABLE_##sET,            \
      MIPI_OFFSET_##sET                   \
   }                                      \
}
#endif

#else
#if (IS_3G_ET_SUPPORT)
#define UMTS_RF_PARAMETER(sET)            \
{                                         \
   PMU_PASETTING_##sET,                   \
   RX_DIVERSITY_ALWAYS_ON_##sET,          \
   ULTRA_LOW_COST_EN_##sET,               \
   PA_DIRFT_COMPENSATION_##sET,           \
   PA_SECTION_##sET,                      \
   {                                      \
      -TC_PR1_##sET,                      \
      -TC_PR2_##sET,                      \
      -TC_PR2B_##sET,                     \
       TC_PR3_##sET,                      \
       TC_PR3_##sET+20,                   \
      -TC_PT1_##sET,                      \
      -TC_PT2_##sET,                      \
      -TC_PT2B_##sET,                     \
       TC_PT3_##sET,                      \
       TC_PT3_##sET+20                    \
   },                                     \
   {                                      \
      MAX_OFFSET_##sET,                   \
      VM_OFFSET_##sET,                    \
      VBIAS_OFFSET_##sET,                 \
      DC2DC_OFFSET_##sET,                 \
      VGA_OFFSET_##sET                    \
   },                                     \
   {                                      \
      {                                   \
         MPR_BACK_OFF_HSDPA_BAND1_##sET , MPR_BACK_OFF_HSDPA_BAND2_##sET , MPR_BACK_OFF_HSDPA_BAND3_##sET , MPR_BACK_OFF_HSDPA_BAND4_##sET , MPR_BACK_OFF_HSDPA_BAND5_##sET , \
         MPR_BACK_OFF_HSDPA_BAND6_##sET , MPR_BACK_OFF_HSDPA_BAND7       , MPR_BACK_OFF_HSDPA_BAND8_##sET , MPR_BACK_OFF_HSDPA_BAND9_##sET , MPR_BACK_OFF_HSDPA_BAND10_##sET, \
         MPR_BACK_OFF_HSDPA_BAND11_##sET, MPR_BACK_OFF_HSDPA_BAND12      , MPR_BACK_OFF_HSDPA_BAND13      , MPR_BACK_OFF_HSDPA_BAND14      , MPR_BACK_OFF_HSDPA_BAND15      , \
         MPR_BACK_OFF_HSDPA_BAND16      , MPR_BACK_OFF_HSDPA_BAND16      , MPR_BACK_OFF_HSDPA_BAND17      , MPR_BACK_OFF_HSDPA_BAND18      , MPR_BACK_OFF_HSDPA_BAND19_##sET  \
      },                                                                                                                                                                      \
      {                                                                                                                                                                       \
         MPR_BACK_OFF_HSUPA_BAND1_##sET , MPR_BACK_OFF_HSUPA_BAND2_##sET , MPR_BACK_OFF_HSUPA_BAND3_##sET , MPR_BACK_OFF_HSUPA_BAND4_##sET , MPR_BACK_OFF_HSUPA_BAND5_##sET , \
         MPR_BACK_OFF_HSUPA_BAND6_##sET , MPR_BACK_OFF_HSUPA_BAND7       , MPR_BACK_OFF_HSUPA_BAND8       , MPR_BACK_OFF_HSUPA_BAND9       , MPR_BACK_OFF_HSUPA_BAND10      , \
         MPR_BACK_OFF_HSUPA_BAND11      , MPR_BACK_OFF_HSUPA_BAND12      , MPR_BACK_OFF_HSUPA_BAND13      , MPR_BACK_OFF_HSUPA_BAND14      , MPR_BACK_OFF_HSUPA_BAND15      , \
         MPR_BACK_OFF_HSUPA_BAND16      , MPR_BACK_OFF_HSUPA_BAND16      , MPR_BACK_OFF_HSUPA_BAND17      , MPR_BACK_OFF_HSUPA_BAND18      , MPR_BACK_OFF_HSUPA_BAND19_##sET  \
      }                                   \
   },                                     \
   {                                      \
      IS_3G_MIPI_ENABLE_##sET,            \
      MIPI_OFFSET_##sET,                  \
      IS_3G_ET_ENABLE_##sET,              \
   }                                      \
}
#else
#define UMTS_RF_PARAMETER(sET)            \
{                                         \
   PMU_PASETTING_##sET,                   \
   RX_DIVERSITY_ALWAYS_ON_##sET,          \
   ULTRA_LOW_COST_EN_##sET,               \
   PA_DIRFT_COMPENSATION_##sET,           \
   PA_SECTION_##sET,                      \
   {                                      \
      -TC_PR1_##sET,                      \
      -TC_PR2_##sET,                      \
      -TC_PR2B_##sET,                     \
       TC_PR3_##sET,                      \
       TC_PR3_##sET+20,                   \
      -TC_PT1_##sET,                      \
      -TC_PT2_##sET,                      \
      -TC_PT2B_##sET,                     \
       TC_PT3_##sET,                      \
       TC_PT3_##sET+20                    \
   },                                     \
   {                                      \
      MAX_OFFSET_##sET,                   \
      VM_OFFSET_##sET,                    \
      VBIAS_OFFSET_##sET,                 \
      DC2DC_OFFSET_##sET,                 \
      VGA_OFFSET_##sET                    \
   },                                     \
   {                                      \
      {                                   \
         MPR_BACK_OFF_HSDPA_BAND1_##sET , MPR_BACK_OFF_HSDPA_BAND2_##sET , MPR_BACK_OFF_HSDPA_BAND3_##sET , MPR_BACK_OFF_HSDPA_BAND4_##sET , MPR_BACK_OFF_HSDPA_BAND5_##sET , \
         MPR_BACK_OFF_HSDPA_BAND6_##sET , MPR_BACK_OFF_HSDPA_BAND7       , MPR_BACK_OFF_HSDPA_BAND8_##sET , MPR_BACK_OFF_HSDPA_BAND9_##sET , MPR_BACK_OFF_HSDPA_BAND10_##sET, \
         MPR_BACK_OFF_HSDPA_BAND11_##sET, MPR_BACK_OFF_HSDPA_BAND12      , MPR_BACK_OFF_HSDPA_BAND13      , MPR_BACK_OFF_HSDPA_BAND14      , MPR_BACK_OFF_HSDPA_BAND15      , \
         MPR_BACK_OFF_HSDPA_BAND16      , MPR_BACK_OFF_HSDPA_BAND16      , MPR_BACK_OFF_HSDPA_BAND17      , MPR_BACK_OFF_HSDPA_BAND18      , MPR_BACK_OFF_HSDPA_BAND19_##sET  \
      },                                                                                                                                                                      \
      {                                                                                                                                                                       \
         MPR_BACK_OFF_HSUPA_BAND1_##sET , MPR_BACK_OFF_HSUPA_BAND2_##sET , MPR_BACK_OFF_HSUPA_BAND3_##sET , MPR_BACK_OFF_HSUPA_BAND4_##sET , MPR_BACK_OFF_HSUPA_BAND5_##sET , \
         MPR_BACK_OFF_HSUPA_BAND6_##sET , MPR_BACK_OFF_HSUPA_BAND7       , MPR_BACK_OFF_HSUPA_BAND8       , MPR_BACK_OFF_HSUPA_BAND9       , MPR_BACK_OFF_HSUPA_BAND10      , \
         MPR_BACK_OFF_HSUPA_BAND11      , MPR_BACK_OFF_HSUPA_BAND12      , MPR_BACK_OFF_HSUPA_BAND13      , MPR_BACK_OFF_HSUPA_BAND14      , MPR_BACK_OFF_HSUPA_BAND15      , \
         MPR_BACK_OFF_HSUPA_BAND16      , MPR_BACK_OFF_HSUPA_BAND16      , MPR_BACK_OFF_HSUPA_BAND17      , MPR_BACK_OFF_HSUPA_BAND18      , MPR_BACK_OFF_HSUPA_BAND19_##sET  \
      }                                   \
   },                                     \
   {                                      \
      IS_3G_MIPI_ENABLE_##sET,            \
      MIPI_OFFSET_##sET                   \
   }                                      \
}
#endif
#endif
#if (IS_3G_TX_POWER_OFFSET_SUPPORT || IS_3G_SAR_TX_POWER_BACKOFF_SUPPORT)
#define UMTS_TPO_CUSTOM_DATA(sET)    {U_TX_POWER_OFFSET_TABLE_##sET}
#endif

#if (IS_3G_DAT_UL1_CUSTOM_SUPPORT)
#define UMTS_DAT_CUSTOM_FE_ROUTE_DATABASE(sET) {&UMTS_DAT_FE_ROUTE_DATABASE_##sET}

#define UMTS_DAT_CUSTOM_FE_DATABASE(sET)     \
{                                            \
      &UMTS_DAT_CAT_A_DATABASE_##sET,        \
      &UMTS_DAT_CAT_B_DATABASE_##sET,        \
}

#define UMTS_DAT_CUSTOM_FEATURE_BY_RAT(sET)  \
{                                            \
   {                                         \
         UMTS_DAT_FEATURE_ENABLE_##sET,        \
         UMTS_DAT_SCENARIO_DEFAULT           \
   },                                        \
}

#if (IS_3G_MIPI_SUPPORT)
#define UMTS_DAT_CUSTOM_MIPI_DATA(sET)       \
{                                            \
   UMTS_DAT_CAT_A_MIPI_EVENT_TABLE_##sET,    \
   UMTS_DAT_CAT_A_MIPI_DATA_TABLE_##sET,     \
   UMTS_DAT_CAT_B_MIPI_EVENT_TABLE_##sET,    \
   UMTS_DAT_CAT_B_MIPI_DATA_TABLE_##sET,     \
}
#endif //(IS_3G_MIPI_SUPPORT)
#endif //(IS_3G_DAT_UL1_CUSTOM_SUPPORT)
extern UMTSBand ul1CustomBand[][UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];
#if (IS_3G_MIPI_SUPPORT)
extern Ul1CustomDynamicInitMipiData ul1CustomMipiData[UL1CUSTOM_TOTAL_REAL_SET_NUMS];
#endif
extern Ul1CustomDynamicInitUmtsFeSettingData ul1CustomUmtsFeSettingData[UL1CUSTOM_TOTAL_REAL_SET_NUMS];
extern Ul1CustomDynamicInitUmtsCalData ul1CustomUmtsCalData[UL1CUSTOM_TOTAL_REAL_SET_NUMS];
extern Ul1CustomDynamicRfParameter ul1CustomUmtsRfParameter[UL1CUSTOM_TOTAL_REAL_SET_NUMS];
#if (IS_3G_DAT_UL1_CUSTOM_SUPPORT)
extern Ul1CustomDynamicDatRoute ul1CustomDatRoute[UL1CUSTOM_TOTAL_REAL_SET_NUMS];
extern Ul1CustomDynamicDatDb ul1CustomDatDb[UL1CUSTOM_TOTAL_REAL_SET_NUMS];
extern Ul1CustomDynamicDatFeatureByRat ul1CustomDatByRat[UL1CUSTOM_TOTAL_REAL_SET_NUMS];
#if (IS_3G_MIPI_SUPPORT)
extern Ul1CustomDynamicDatMipiData ul1CustomDatMipiData[UL1CUSTOM_TOTAL_REAL_SET_NUMS];
#endif 
#endif
#if (IS_3G_TAS_NVRAM_SUPPORT)
extern Ul1CustomDynamicTasData ul1CustomUmtsTasData[UL1CUSTOM_TOTAL_REAL_SET_NUMS];
#endif
#if (IS_3G_TX_POWER_OFFSET_SUPPORT || IS_3G_SAR_TX_POWER_BACKOFF_SUPPORT)
extern Ul1CustomDynamicTpoData ul1CustomTpoData[UL1CUSTOM_TOTAL_REAL_SET_NUMS];
#endif
extern kal_bool isWcdmaDrdiEnable;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T* ul1PwrOnCalData[UL1CUSTOM_TOTAL_REAL_SET_NUMS][UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBandNone_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand1_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand2_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand3_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand4_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand5_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand6_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand8_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand9_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand11_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand18_PWRON_CAL_DATA;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand19_PWRON_CAL_DATA;
#endif/*IS_3G_DRDI_SUPPORT*/

#endif /* _WCUSTOMDATA_H_ */

