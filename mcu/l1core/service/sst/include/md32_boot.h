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
 *   md32_boot.h
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
 * -------
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
#ifndef MD32_BOOT_H
#define MD32_BOOT_H

#include "md32_boot_public.h"
#include "md32_file.h"
#include "reg_base.h"

/* MD32 core sys */
#define MD32_BRP_SYS            (BASE_MADDR_MD32_BRP)
#define MD32_DFE_SYS            (BASE_MADDR_MD32_DFE)
#define MD32_RAKE_SYS           (BASE_MADDR_MD32_RAKE)
#define MD32_NUM	3

/* platform dependent setting*/
#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6750) || defined(MT6757) || defined(MT6750S)
#define MD32_MAGIC_KEY          (0x62910000)
#else
#error "Unknown Platform!!"
#endif

/* MD32 offset */
#define MD32_PM             (0x00380000)
#define MD32_DM             (0x003E0000)
#define MD32_CMIF           (0x00358000)
#define MD32_BTSLV          (0x35100C)
#define MD32_DBG_EN			(0x351010)
#define MD32_DMP_EN 		(0x35101C)
#define MD32_PERI_CTRL  	(0x351000)

#if defined(TK6291)
#define BRP_PM_SZ           (0x40000)
#define BRP_DM_SZ           (0x30000)
#define BRP_CMIF_SZ         (0x2000)
#define DFE_PM_SZ           (0x20000)
#define DFE_DM_SZ           (0x10000)
#define DFE_CMIF_SZ         (0x8000)
#define RAKE_PM_SZ           (0x14000)
#define RAKE_DM_SZ           (0xC000)
#define RAKE_CMIF_SZ         (0x1000)
#elif defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
#define BRP_PM_SZ           (0x2C000)
#define BRP_DM_SZ           (0x14000)
#define BRP_CMIF_SZ         (0x2000)
#define DFE_PM_SZ           (0x20000)
#define DFE_DM_SZ           (0x10000)
#define DFE_CMIF_SZ         (0x8000)
#define RAKE_PM_SZ           (0x14000)
#define RAKE_DM_SZ           (0xC000)
#define RAKE_CMIF_SZ         (0x1000)
#else
#error "Unknown Platform!!"
#endif

#if defined(__MD32_PM_PROTECT_SUPPORT__)
#define MD32_PM_PROTECT_EN_OFF       (0x351020)
#define MD32_PM_PROTECT_BNK_OFF      (0x351024)
#define MD32_PM_PROTECT_INSTR_OFF    (0x351028)
#define MD32_UDF_INST_VAL            (0x00F400F4)
#endif /* __MD32_PM_PROTECT_SUPPORT__ */

/* MD32 setting */
#define MD32_PERI_CTRL_MAGIC	(0x80A180A1)
#define MD32_MEM_BNK_SZ			(16 * 1024)
#define MD32_ENABLE		(MD32_MAGIC_KEY | 0x1)
#define MD32_DISABLE	(MD32_MAGIC_KEY | 0x0)

#endif  /* MD32_BOOT_H */

