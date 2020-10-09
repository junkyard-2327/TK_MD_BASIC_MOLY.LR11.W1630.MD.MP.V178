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

/*******************************************************************************
 * Include header files.
 *******************************************************************************/
#ifndef MD32_BOOT_PUBLIC_H
#define MD32_BOOT_PUBLIC_H


/* feature switch */
#if defined(MT6755) || defined(MT6750) || defined(MT6750S)
#define __MD32_PM_PROTECT_SUPPORT__
#endif /* MT6755 */

typedef enum {
    BRP,
    DFE,
    RAKE,
    BRP_COM,
    BRP_FDD,
    BRP_TDD,
    BRP_LTE,
    MD32_BIN_NUM,
    MD32_BIN_MAX = 0xFFFFFFFF,
} MD32_BIN_TYPE;


#ifndef __MD32_PBP__
#include "kal_public_api.h"

/****************************/
/*********** Init ***********/
/****************************/
kal_int32 MD32_Init();


/****************************/
/********** Loader **********/
/****************************/
typedef enum {
    MD32_LOADER_RET_OK,
    MD32_LOADER_RET_DMA_RUNNING,
    MD32_LOADER_RET_ERR,
} MD32_LOADER_RET;

MD32_LOADER_RET MD32_Load(MD32_BIN_TYPE md32_type);
MD32_LOADER_RET MD32_Ungate(MD32_BIN_TYPE md32_type);	// backward compatible
MD32_LOADER_RET MD32_BootByDMA(MD32_BIN_TYPE *md32_bins, kal_uint32 bin_num);


/****************************/
/********** Query ***********/
/****************************/
typedef enum {
   MD32_3G_FDD,
   MD32_3G_TDD,
} MD32_3G_MODE;

typedef struct {
   kal_uint32 pm_com;
   kal_uint32 dm_com;
   kal_uint32 pm_3g;
   kal_uint32 dm_3g;
   kal_uint32 pm_lte;
   kal_uint32 dm_lte;
   kal_uint32 pm_unused;
   kal_uint32 dm_unused;
} MD32_MEM_STATUS;

const MD32_MEM_STATUS *MD32_GetBRPMemStatus(MD32_3G_MODE mode);
const MD32_MEM_STATUS *MD32_GetDFEMemStatus(void);
kal_bool MD32_IsMD32Running(MD32_BIN_TYPE md32_type);


/****************************/
/********* Version **********/
/****************************/
const kal_char *MD32_GetProject(MD32_BIN_TYPE md32_type);
const kal_char *MD32_GetFlavor(MD32_BIN_TYPE md32_type);
const kal_char *MD32_GetLabel(MD32_BIN_TYPE md32_type);
const kal_char *MD32_GetBuildTime(MD32_BIN_TYPE md32_type);


/****************************/
/******** Exception *********/
/****************************/
void MD32_ExcpNotify();


/****************************/
/******** PM protect ********/
/****************************/
#if defined(__MD32_PM_PROTECT_SUPPORT__)
kal_uint32 MD32_PM_Protect_Enable(MD32_BIN_TYPE md32);
kal_uint32 MD32_PM_Protect_Disable(MD32_BIN_TYPE md32);
kal_uint32 MD32_PM_Protect_Mask_Write(MD32_BIN_TYPE md32, kal_uint32 msk);
kal_uint32 MD32_PM_Protect_Mask_Read(MD32_BIN_TYPE md32);
#endif  /* __MD32_PM_PROTECT_SUPPORT__ */

#endif /* __MD32_PBP__ */

#endif /* MD32_BOOT_PUBLIC_H */
