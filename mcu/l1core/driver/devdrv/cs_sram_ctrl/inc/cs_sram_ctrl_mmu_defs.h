/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cs_sram_ctrl_mmu_defs.h
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
*[File         ]       cs_sram_ctrl_mmu_defs.h
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

#ifndef __CS_SRAM_CTRL_MMU_DEFS_H__
#define __CS_SRAM_CTRL_MMU_DEFS_H__

#include "reg_base.h"

#if defined(TK6291)

    #define CS_SRAM_CTRL_MMU_CTRL_0     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+0)     
    #define CS_SRAM_CTRL_MMU_CTRL_1     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+4)
    #define CS_SRAM_CTRL_MMU_CTRL_2     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+8)
    #define CS_SRAM_CTRL_MMU_CTRL_3     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+12)
    #define CS_SRAM_CTRL_MMU_CTRL_4     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+16)
    #define CS_SRAM_CTRL_MMU_CTRL_5     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+20)
    #define CS_SRAM_CTRL_MMU_CTRL_6     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+24)
    #define CS_SRAM_CTRL_MMU_CTRL_7     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+28)
    #define CS_SRAM_CTRL_MMU_CTRL_8     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+32)
    #define CS_SRAM_CTRL_MMU_CTRL_9     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+36)
    #define CS_SRAM_CTRL_MMU_INFO_0     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+40)
    #define CS_SRAM_CTRL_MMU_INFO_1     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+44)
    #define CS_SRAM_CTRL_MMU_INFO_2     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+48)
    #define CS_SRAM_CTRL_MMU_INFO_3     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+52)
    #define CS_SRAM_CTRL_MMU_INFO_4     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+56)
    #define CS_SRAM_CTRL_MMU_INFO_5     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+60)
    #define CS_SRAM_CTRL_MMU_INFO_6     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+64)
    #define CS_SRAM_CTRL_MMU_INFO_7     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+68)
    #define CS_SRAM_CTRL_MMU_INFO_8     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+72)
    #define CS_SRAM_CTRL_MMU_INFO_9     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+76)
        #define CS_SRAM_CTRL_RXDMP_INFO_0   CS_SRAM_CTRL_MMU_INFO_9
    #define CS_SRAM_CTRL_MMU_DELSEL_0   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+80)
    #define CS_SRAM_CTRL_MMU_DELSEL_1   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+84)
    #define CS_SRAM_CTRL_MMU_DELSEL_2   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+88)
    #define CS_SRAM_CTRL_MMU_DELSEL_3   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+92)
    #define CS_SRAM_CTRL_MMU_DELSEL_4   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+96)
    #define CS_SRAM_CTRL_MMU_DELSEL_5   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+100)
    #define CS_SRAM_CTRL_MMU_DELSEL_6   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+104)
    #define CS_SRAM_CTRL_MMU_DELSEL_7   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+108)
    #define CS_SRAM_CTRL_MMU_FUSE_0     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+112)
    #define CS_SRAM_CTRL_MMU_FUSE_1     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+116)
    #define CS_SRAM_CTRL_MMU_FUSE_2     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+120)
    #define CS_SRAM_CTRL_MMU_FUSE_3     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+124)
    #define CS_SRAM_CTRL_MMU_FUSE_4     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+128)
    #define CS_SRAM_CTRL_MMU_FUSE_5     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+132)
    #define CS_SRAM_CTRL_MMU_FUSE_6     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+136)
    #define CS_SRAM_CTRL_MMU_FUSE_7     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+140)
    #define CS_SRAM_CTRL_MMU_FUSE_8     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+144)
    #define CS_SRAM_CTRL_MMU_FUSE_9     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+148)
    #define CS_SRAM_CTRL_MMU_FUSE_10    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+152)
    #define CS_SRAM_CTRL_MMU_FUSE_11    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+156)
    #define CS_SRAM_CTRL_MMU_FUSE_12    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+160)
    #define CS_SRAM_CTRL_MMU_FUSE_13    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+164)
    #define CS_SRAM_CTRL_MMU_FUSE_14    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+168)
    #define CS_SRAM_CTRL_MMU_FUSE_15    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+172)
    #define CS_SRAM_CTRL_MMU_FUSE_16    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+176)
    #define CS_SRAM_CTRL_MMU_FUSE_17    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+180)
    #define CS_SRAM_CTRL_MMU_FUSE_18    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+184)
    #define CS_SRAM_CTRL_MMU_FUSE_19    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+188)
    #define CS_SRAM_CTRL_MMU_FUSE_20    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+192)
    #define CS_SRAM_CTRL_MMU_FUSE_21    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+196)
    #define CS_SRAM_CTRL_MMU_FUSE_22    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+200)
    #define CS_SRAM_CTRL_MMU_FUSE_23    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+204)
    #define CS_SRAM_CTRL_MMU_STATUS_0   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+208)
    #define CS_SRAM_CTRL_MMU_RD_CFG_0   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+212)
    #define CS_SRAM_CTRL_MMU_RD_CFG_1   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+216)
    #define CS_SRAM_CTRL_MMU_RD_CFG_2   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+220)
    #define CS_SRAM_CTRL_MMU_RD_CFG_3   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+224)
    #define CS_SRAM_CTRL_MMU_RD_CFG_4   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+228)
    #define CS_SRAM_CTRL_MMU_RD_CFG_5   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+232)
    #define CS_SRAM_CTRL_MMU_RD_CFG_6   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+236)
    #define CS_SRAM_CTRL_MMU_RD_CFG_7   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+240)
    #define CS_SRAM_CTRL_MMU_RD_CFG_8   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+244)
    #define CS_SRAM_CTRL_MMU_RD_CFG_9   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+248)
        #define CS_SRAM_CTRL_RXDMP_RD_CFG_0   CS_SRAM_CTRL_MMU_RD_CFG_9
    #define CS_SRAM_CTRL_MMU_EIRQ_EN    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+252)
    #define CS_SRAM_CTRL_MMU_EIRQ_STS   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+256)
#elif defined(MT6755) || defined(MT6797) || defined(MT6750) || defined(MT6757) || defined(MT6750S)

    #define CS_SRAM_CTRL_MMU_CTRL_0     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+0)     
    #define CS_SRAM_CTRL_MMU_CTRL_1     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+4)
    #define CS_SRAM_CTRL_MMU_CTRL_2     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+8)
    #define CS_SRAM_CTRL_MMU_CTRL_3     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+12)
    #define CS_SRAM_CTRL_MMU_CTRL_4     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+16)
    #define CS_SRAM_CTRL_MMU_CTRL_5     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+20)
    #define CS_SRAM_CTRL_MMU_CTRL_6     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+24)
    #define CS_SRAM_CTRL_MMU_CTRL_7     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+28)
    #define CS_SRAM_CTRL_MMU_CTRL_8     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+32)
    #define CS_SRAM_CTRL_MMU_CTRL_9     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+36)
    #define CS_SRAM_CTRL_MMU_INFO_0     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+40)
    #define CS_SRAM_CTRL_MMU_INFO_1     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+44)
    #define CS_SRAM_CTRL_MMU_INFO_2     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+48)
    #define CS_SRAM_CTRL_MMU_INFO_3     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+52)
    #define CS_SRAM_CTRL_MMU_INFO_4     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+56)
    #define CS_SRAM_CTRL_MMU_INFO_5     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+60)
    #define CS_SRAM_CTRL_MMU_INFO_6     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+64)
    #define CS_SRAM_CTRL_MMU_INFO_7     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+68)
    #define CS_SRAM_CTRL_MMU_INFO_8     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+72)
    #define CS_SRAM_CTRL_MMU_INFO_9     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+76)
        #define CS_SRAM_CTRL_RXDMP_INFO_0   CS_SRAM_CTRL_MMU_INFO_9
    #define CS_SRAM_CTRL_MMU_DELSEL_0   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+80)
    #define CS_SRAM_CTRL_MMU_DELSEL_1   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+84)
    #define CS_SRAM_CTRL_MMU_DELSEL_2   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+88)
    #define CS_SRAM_CTRL_MMU_DELSEL_3   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+92)
    #define CS_SRAM_CTRL_MMU_DELSEL_4   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+96)
    #define CS_SRAM_CTRL_MMU_DELSEL_5   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+100)
    #define CS_SRAM_CTRL_MMU_DELSEL_6   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+104)
    #define CS_SRAM_CTRL_MMU_DELSEL_7   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+108)
    #define CS_SRAM_CTRL_MMU_FUSE_CTRL_0     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+112)
    #define CS_SRAM_CTRL_MMU_FUSE_CTRL_1     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+116)
    #define CS_SRAM_CTRL_MMU_FUSE_CTRL_2     (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+120)
    #define CS_SRAM_CTRL_MMU_STATUS_0   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+124)
    #define CS_SRAM_CTRL_MMU_RD_CFG_0   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+128)
    #define CS_SRAM_CTRL_MMU_RD_CFG_1   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+132)
    #define CS_SRAM_CTRL_MMU_RD_CFG_2   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+136)
    #define CS_SRAM_CTRL_MMU_RD_CFG_3   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+140)
    #define CS_SRAM_CTRL_MMU_RD_CFG_4   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+144)
    #define CS_SRAM_CTRL_MMU_RD_CFG_5   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+148)
    #define CS_SRAM_CTRL_MMU_RD_CFG_6   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+152)
    #define CS_SRAM_CTRL_MMU_RD_CFG_7   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+156)
    #define CS_SRAM_CTRL_MMU_RD_CFG_8   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+160)
    #define CS_SRAM_CTRL_MMU_RD_CFG_9   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+164)
        #define CS_SRAM_CTRL_RXDMP_RD_CFG_0   CS_SRAM_CTRL_MMU_RD_CFG_9
    #define CS_SRAM_CTRL_MMU_EIRQ_EN    (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+168)
    #define CS_SRAM_CTRL_MMU_EIRQ_STS   (L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG+172)
#else
    #error "unknown chip option!!!"
#endif

#endif  //__CS_SRAM_CTRL_MMU_DEFS_H__
