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
 *   coresonic_hw.h
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
#ifndef CORESONIC_HW_H
#define CORESONIC_HW_H

// DSPBT register offset definition
#define DSPBT_CTRL_OFFSET                   (0x0)
#define DSPBT_STATUS_OFFSET                 (0x4)
#define DSPBT_PM_LENGTH_OFFSET              (0x8)
#define DSPBT_ICM_LENGTH_OFFSET             (0xC)
#define DSPBT_PM_ICM_LENGTH_OFFSET          (0x10)
#define DSPBT_INC_SIZE_OFFSET               (0x14)
#define DSPBT_PM_CRC32_OFFSET               (0x18)
#define DSPBT_ICM_CRC32_OFFSET              (0x1C)
#define DSPBT_PM_READ_CNT_OFFSET            (0x20)
#define DSPBT_PM_WRITE_CNT_OFFSET           (0x24)
#define DSPBT_ICM_READ_CNT_OFFSET           (0x28)
#define DSPBT_ICM_WRITE_CNT_OFFSET          (0x2C)
#define DSPBT_DYNAMIC_DL_OFFSET             (0x30)
#define DSPBT_C2CRF_EN_OFFSET               (0x34)

// DSPBT_CTRL register bits definition
#define MASK_DSPBT_EN                       (0x1)
#define DSPBT_EN                            (0x1)

#define MASK_CIPHER_EN                      (0x2)
#define CIPHER_EN                           (0x2)
#define CIPHER_DIS                          (0x0)

#define MASK_CIPHER_KEY_LEVEL               (0x4)
#define BASIC_CIPHER                        (0x0)
#define ADV_CIPHER                          (0x4)

#define MASK_CIPHER_KEY_SEL                 (0x18)
#define CIPHER_KEY0                         (0)
#define CIPHER_KEY1                         (0x8)
#define CIPHER_KEY2                         (0x10)
#define CIPHER_KEY3                         (0x18)

#define MASK_BOOT_MODE                      (0x20)
#define AUTO_MODE                           (0)
#define MANAUAL_MODE                        (0x20)

#define MASK_MANUAL_BOOT_CONTROL            (0x40)
#define MANUAL_BOOT_CONTROL                 (0x40)

// DSPBT_STATUS register bits definition
#define BOOT_START                          (0x1)
#define BOOT_DONE                           (0x2)

// DSPBT_DYNAMIC_DL register bits definition
#define DYNDL_EN                            (0x1)


#endif  /* CORESONIC_HW_H */

