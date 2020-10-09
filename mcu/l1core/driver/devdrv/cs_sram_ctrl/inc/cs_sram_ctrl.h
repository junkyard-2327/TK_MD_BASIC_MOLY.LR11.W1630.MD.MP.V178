/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cs_sram_ctrl.h
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
*[File         ]       cs_sram_ctrl.h
*[Version      ]       v1.0
*[Revision Date]       2014-12-23
*[Author       ]       Boky Chen
*[Description  ]
*    The program is for sram control header file.
*
*[Copyright]
*    Copyright (C) 2005 MediaTek Incorporation. All Rights Reserved.
**********************************************************************************************************************************************************
*/

#ifndef __CS_SRAM_CTRL_H__
#define __CS_SRAM_CTRL_H__

#include "kal_general_types.h"

#define SRAM_CTRL_SLOW_TRIG_CLR             (0)
#define SRAM_CTRL_CR4_TRIG_SLOW             (1)
#define SRAM_CTRL_TDB_TRIG_SLOW             (2)

#define SRAM_CTRL_CR4_FSM_MASK              (0xC0)
#define SRAM_CTRL_TDB_FSM_MASK              (0x300)

#define SRAM_CTRL_FSM_IDLE                  (0)

#define SRAM_RD_PWR_ON                      (0x3)
#define SRAM_RD_PWR_DWN                     (0xA)
#define SRAM_RD_PWR_SLP                     (0x0)
#define SRAM_RD_PWR_DSLP                    (0x6)

#define SRAM_RD_CFG_MASK                    (0xF)

#if defined(TK6291)
    #define SRAM_CTRL_RXTDB_BMAP_MASK       (0x3FFFFF)
    #define SRAM_CTRL_RXTDB_NUM             (22)
    #define SRAM_CTRL_RXTDB_REG_NUM         (3)
    #define SRAM_CTRL_RXTDB_MTCMOS_ON_MASK  (0x33333333)
    #define SRAM_CTRL_REG_WIDTH             (32)
    #define SRAM_CTRL_INFO_RD_CFG_OFFST     (4)
#elif defined(MT6755) || defined(MT6797) || defined(MT6750) || defined(MT6757) || defined(MT6750S)
    #define SRAM_CTRL_RXTDB_BMAP_MASK       (0x3FFFFF)
    #define SRAM_CTRL_RXTDB_NUM             (22)
    #define SRAM_CTRL_RXTDB_REG_NUM         (3)
    #define SRAM_CTRL_RXTDB_MTCMOS_ON_MASK  (0x33333333)
    #define SRAM_CTRL_REG_WIDTH             (32)
    #define SRAM_CTRL_INFO_RD_CFG_OFFST     (4)
#else
    #error "SRAM control didn't support on this chip!!!"
#endif

typedef struct
{
    kal_uint32  reg_addr;
    kal_uint32  reg_value_mask;
}st_addr_val_mask;

typedef struct
{
    kal_uint32  reg_ctrl;
    kal_uint32  reg_stat;
}st_ctrl_stat;

#define SRAM_CTRL_WriteReg32(addr,data)     ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define SRAM_CTRL_ReadReg32(addr)           (*(volatile kal_uint32 *)(addr))

#endif  //__CS_SRAM_CTRL_H__

