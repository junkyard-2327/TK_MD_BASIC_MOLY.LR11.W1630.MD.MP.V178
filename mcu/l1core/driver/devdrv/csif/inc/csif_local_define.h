/*****************************************************************************
 *
 * Filename:
 * ---------
 *   CSIF_Local_Define.h
 *
 * Project:
 * --------
 *   R11GX Project depend on makefile configuration
 *
 * Description:
 * ------------
 *   History for each file.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by Perforce. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by Perforce. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
**********************************************************************************************************************************************************
*[File         ]       CSIF_Config.h
*[Version      ]       v1.0
*[Revision Date]       2014-06-10
*[Author       ]       Peng-Chih Wang
*[Description  ]
*    The program is for the CSIF to include correspond CR & macro header files.
*
*[Copyright]
*    Copyright (C) 2005 MediaTek Incorporation. All Rights Reserved.
**********************************************************************************************************************************************************
*/

#ifndef __CSIF_LOCAL_DEFINE_H__

#define __CSIF_LOCAL_DEFINE_H__

#include "reg_base.h"
//CSIF DSM base address
#define ICC_CSIF_DSM_BASE                           (L1_BASE_MADDR_ICC_L1CSIF)
#define IMC_CSIF_DSM_BASE                           (L1_BASE_MADDR_IMC_L1CSIF)
#define MPC_CSIF_DSM_BASE                           (L1_BASE_MADDR_MPC_L1CSIF)
//CSIF CR base address
#define ICC_CSIF_BASE                               (ICC_CSIF_DSM_BASE+0x40000)
#define IMC_CSIF_BASE                               (IMC_CSIF_DSM_BASE+0x40000)
#define MPC_CSIF_BASE                               (MPC_CSIF_DSM_BASE+0x40000)
//!!need to do project porting!!
#if defined(TK6291)
    #define ICC_DSM_LEN                                 (0x180)
    #define IMC_DSM_LEN                                 (0x2F8)
    #define MPC_DSM_LEN                                 (0x520)
#elif defined(MT6755) || defined(MT6750) || defined(MT6757) || defined(MT6750S)
    #define ICC_DSM_LEN                                 (0x180)
    #define IMC_DSM_LEN                                 (0x2F8)
    #define MPC_DSM_LEN                                 (0x520)
#elif defined(MT6797)
    #define ICC_DSM_LEN                                 (0x180)
    #define IMC_DSM_LEN                                 (0x2F8)
    #define MPC_DSM_LEN                                 (0x520)
#else
    #error "Need to check compile option in project configuration"
#endif

#include "csif_r11g1_local_define.h"
#include "csif_r11g1_local_asm_define.h"

#endif //__CSIF_LOCAL_DEFINE_H__
