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
 *   mml1_custom_mipi.h
 *
 * Project:
 * --------
 *   MT6290 EVB
 *
 * Description:
 * ------------
 *   MT6290 EVB Multi-Mode Multi-RAT L1 constance definition
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *******************************************************************************/
#ifndef  _MML1_CUSTOM_MIPI_H_
#define  _MML1_CUSTOM_MIPI_H_

#include "mml1_mipi_public.h"

#define MIPI_USID_INIT0           0x0000
#define MIPI_USID_ASM0            0x000F
#define MIPI_USID_ASM1            0x0008
#define MIPI_USID_ASM2            0x000A
#define MIPI_USID_ASM3            0x0009
#define MIPI_USID_PA0             0x000F
#define MIPI_USID_PA1             0x000E
#define MIPI_USID_ANT0            0x0006

#define MIPI_USID_INIT0_P3           0x0000
#define MIPI_USID_ASM0_P3            0x000E    //3P18T for Main
#define MIPI_USID_ASM1_P3            0x000A    //DP12T for Div 
#define MIPI_USID_ASM2_P3            0x000F                    
#define MIPI_USID_ASM3_P3            0x0009                    
#define MIPI_USID_PA0_P3             0x000F    //MH PA         
#define MIPI_USID_PA1_P3             0x000C    //LPA           
#define MIPI_USID_PA2_P3             0x000E    // B11_21PA          
#define MIPI_USID_ANT0_P3            0x0006

#define MIPI_USID_ETM             0x000C

/* ============================================================================= */
/*   ET feature enable control flag                                                                                                                                  */
/* ============================================================================= */
#define IS_MML1_ET_FRONT_END_ENABLE            0   // 0: Disable ET feature; 1:Enable ET feature.

/* ============================================================================= */
/*   ET MIPI Port Index                                                                                                                                                 */
/* ============================================================================= */
#define MML1_ET_MIPI_PORT                      2   // Please fill in the MIPI port number for ETM chip, 0: MIPI_PORT_0, 1: MIPI_PORT_1, 2: MIPI_PORT_2, 3: MIPI_PORT_3.

/* ============================================================================= */
/*   ETM vendor / chip information definitions                                                                                                                 */
/* ============================================================================= */

#if IS_MML1_ET_FRONT_END_ENABLE

#define ETM_CHIP_TYPE                          ETM_NONE_CHIP
#define ETM_MTK_MT6300_VERSION                 ETM_MTK_MT6300_E2

#endif   // #if IS_MML1_ET_FRONT_END_ENABLE

#endif


