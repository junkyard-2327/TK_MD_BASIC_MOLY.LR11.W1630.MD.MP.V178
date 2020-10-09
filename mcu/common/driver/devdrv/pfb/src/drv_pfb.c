/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   drv_pfb.c
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This file declares CR4 prefetch buffer related APIs.
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 06 16 2015 alan-tl.lin
 * [MOLY00120489] [Jade] PFB driver update for MT6755
 * [PFB] Update driver for MT6755
 *
 * 07 07 2014 alan-tl.lin
 * [MOLY00068778][TK6291_DEV] Update PFB driver : Add project compile option
 * Merge from MOLY to TK6291_DEV
 *
 * 04 08 2014 alan-tl.lin
 * [MOLY00061497] Update PFB dirver
 * [DEVDRV] update PFB driver for TK6291
 *
 ****************************************************************************/

#include "drv_comm.h"
#include "drvpdn.h"
#include "devdrv_ls.h"
#include "sync_data.h"
#include "pfb_reg.h"
#include "dcm_sw.h"
#include "cp15_int.h"

/******************************************************************************
 * CONFIGURATIONS
 *****************************************************************************/

#define PFB_PF_2X

#ifdef PFB_PF_2X
    #define PFB_EN_VALUE  (PFB_PF_LEN_SEL_64B | PFB_PF_LENGTH_EQ4 | PFB_PF_ARID | PFB_CNT_ENABLE | PFB_EN)
#else
    #define PFB_EN_VALUE  (PFB_PF_LEN_SEL_32B | PFB_PF_LENGTH_EQ4 | PFB_PF_ARID | PFB_CNT_ENABLE | PFB_EN)
#endif

/*****************************************************************************
 * FUNCTION
 *   enablePrefetchBuffer
 *
 * DESCRIPTION
 *   Enable instruction prefetch buffer.
 *
 * CALLS
 *
 * CALL BY
 *   MPU_Init (mcu/common/driver/sys_drv/cache/src/mpu.c)
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 *****************************************************************************/
#if defined(__MTK_TARGET__)
DEVDRV_LS_INTSRAM_ROCODE void enablePrefetchBuffer(void)
#else
void enablePrefetchBuffer(void)
#endif
{
    DRV_WriteReg32(REG_PFB_CTRL, (DRV_Reg32(REG_PFB_CTRL) & ~PFB_PF_LEN_SEL_MASK) | PFB_EN_VALUE);

#if defined(__PCORE__)
    //while((DRV_Reg32(REG_PFB_STATUS) & PFB_UPDATE_STATUS) != 1);
#elif defined(__L1CORE__)
    // TODO : Check PFB update bit
#endif
}

/*****************************************************************************
 * FUNCTION
 *   disablePrefetchBuffer
 *
 * DESCRIPTION
 *   Disable instruction prefetch buffer.
 *
 * CALLS
 *
 * CALL BY
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 *****************************************************************************/
#if defined(__MTK_TARGET__)
DEVDRV_LS_INTSRAM_ROCODE void disablePrefetchBuffer(void)
#else
void disablePrefetchBuffer(void)
#endif
{
    DRV_WriteReg32(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) & (~PFB_EN));
#if defined(__PCORE__)
    while((DRV_Reg32(REG_PFB_STATUS) & PFB_UPDATE_STATUS) != 1);
#elif defined(__L1CORE__)
    // TODO : Check PFB update bit
#endif
}

/*****************************************************************************
 * FUNCTION
 *   drv_pfb_cnt_enable
 *
 * DESCRIPTION
 *   Enable the counting of instruction prefetch buffer.
 *
 * CALLS
 *
 * CALL BY
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 *****************************************************************************/
void drv_pfb_cnt_enable(void)
{
#if (defined(__L1CORE__)&&(defined(TK6291)))
    DRV_WriteReg32(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) | (~PFB_PF_LAT_CNT));
#endif  // __L1CORE__
    DRV_WriteReg32(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) | PFB_CNT_ENABLE);
}

/*****************************************************************************
 * FUNCTION
 *   drv_pfb_cnt_disable
 *
 * DESCRIPTION
 *   Disable the counting of instruction prefetch buffer.
 *
 * CALLS
 *
 * CALL BY
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 *****************************************************************************/
void drv_pfb_cnt_disable(void)
{
#if (defined(__L1CORE__)&&(defined(TK6291)))
    DRV_WriteReg32(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) | (PFB_PF_LAT_CNT));
#endif  // __L1CORE__
    DRV_WriteReg32(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) & (~PFB_CNT_ENABLE));
}

/*****************************************************************************
 * FUNCTION
 *   drv_pfb_get_cnt
 *
 * DESCRIPTION
 *   Get the counter of instruction prefetch buffer.
 *
 * CALLS
 *
 * CALL BY
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   FPB counter
 *
 *****************************************************************************/
kal_uint32 drv_pfb_get_cnt(void)
{
#if (defined(__L1CORE__)&&(defined(TK6291)))
    DRV_WriteReg32(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) | (~PFB_PF_LAT_CNT));
    DRV_WriteReg32(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) | (PFB_PF_LAT_CNT));
#endif  // __L1CORE__

    return DRV_Reg32(REG_PFB_HIT_CNT);
}

