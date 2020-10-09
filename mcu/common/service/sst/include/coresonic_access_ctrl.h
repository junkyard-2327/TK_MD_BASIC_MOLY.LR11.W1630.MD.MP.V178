/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   coresonic_access_ctrl.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
 *
 * Author:
 * -------
 *   
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files.
 *******************************************************************************/
#ifndef CORESONIC_ACCESS_CTRL_H
#define CORESONIC_ACCESS_CTRL_H

#include "reg_base.h"

#if defined(TK6291)
    #define ICC_PM_ICM_ACCESS_ADDR              (L1_BASE_MADDR_ICC_C2CRF+0x0E68)	//ICC 0xFEE00000+E68 (DSPDMA_CTRL(922)*4=0x0E68)
    #define IMC_PM_ICM_ACCESS_ADDR              (L1_BASE_MADDR_IMC_C2CRF+0x3AE8)	//IMC 0xFDE00000+3AE8 (DSPDMA_CTRL(3770)*4=0x3AE8)
    #define MPC_PM_ICM_ACCESS_ADDR              (L1_BASE_MADDR_MPC_C2CRF+0x1268)	//MPC 0xFD600000+1268 (DSPDMA_CTRL(1178)*4=0x1268)
#elif defined(MT6755) || defined(MT6797)|| defined(MT6750) || defined(MT6757) || defined(MT6750S)
    #define ICC_PM_ICM_ACCESS_ADDR              (L1_BASE_MADDR_ICC_C2CRF+0x10E8)	//ICC 0xFEE00000+10E8 (DSPDMA_CTRL(1082)*4=0x10E8)
    #define IMC_PM_ICM_ACCESS_ADDR              (L1_BASE_MADDR_IMC_C2CRF+0x3AE8)	//IMC 0xFDE00000+3AE8 (DSPDMA_CTRL(3770)*4=0x3AE8)
    #define MPC_PM_ICM_ACCESS_ADDR              (L1_BASE_MADDR_MPC_C2CRF+0x12E8)	//MPC 0xFD600000+12E8 (DSPDMA_CTRL(1210)*4=0x12E8)
#else
    #error  "Please define chip comple option for Coresonic PM, ICM access control address"
#endif

#define DSPBT_C2CRF_EN_OFFSET               (0x34)

#define MASK_PM_ICM_ACCESS_EN               (0xF)
#define PM_ICM_ACCESS_EN                    (0x5)
#define PM_ICM_ACCESS_DIS                   (0xF)

#define WRONG_CORESONIC_C2CRF_CTRL_STATE    (1)
#define WRONG_CORESONIC_PM_ICM_CTRL_STATE   (2)

// DSPBT_C2CRF register bits definition
#define C2CRF_EN                            (0x1)

typedef struct
{
    kal_uint32          m_dspbt_c2crf_en;
    kal_uint32          m_dspbt_pm_icm_access;
}coresonic_access_ctrl_addr;

#endif  /* CORESONIC_ACCESS_CTRL_H */

