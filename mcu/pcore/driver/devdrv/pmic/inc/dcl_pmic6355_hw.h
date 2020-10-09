/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2016
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
 *     dcl_pmic6355_hw.h
 *
 * Project:
 * --------
 *     MOLY Software
 *
 * Description:
 * ------------
 *     This file is for PMIC 6355
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DCL_PMIC6355_HW_H_STRUCT__
#define __DCL_PMIC6355_HW_H_STRUCT__

#include "dcl_pmic_features.h"

#ifdef PMIC_6355_REG_API

#define MT6355_PMIC_REG_BASE 	(0x0000)

#define PMIC_HWCID                            (MT6355_PMIC_REG_BASE + 0x0000)
#define PMIC_SWCID                            (MT6355_PMIC_REG_BASE + 0x0002)
#define PMIC_TOP_CON                          (MT6355_PMIC_REG_BASE + 0x0200)
#define PMIC_TEST_OUT                         (MT6355_PMIC_REG_BASE + 0x0202)
#define PMIC_TEST_CON0                        (MT6355_PMIC_REG_BASE + 0x0204)
#define PMIC_TEST_CON1                        (MT6355_PMIC_REG_BASE + 0x0206)
#define PMIC_TESTMODE_SW                      (MT6355_PMIC_REG_BASE + 0x0208)
#define PMIC_PGDEBSTATUS0                     (MT6355_PMIC_REG_BASE + 0x020A)
#define PMIC_PGDEBSTATU1                      (MT6355_PMIC_REG_BASE + 0x020C)
#define PMIC_PGSTATUS0                        (MT6355_PMIC_REG_BASE + 0x020E)
#define PMIC_PGSTATUS1                        (MT6355_PMIC_REG_BASE + 0x0210)
#define PMIC_PSOCSTATUS                       (MT6355_PMIC_REG_BASE + 0x0212)
#define PMIC_THERMALSTATUS                    (MT6355_PMIC_REG_BASE + 0x0214)
#define PMIC_TOPSTATUS                        (MT6355_PMIC_REG_BASE + 0x0216)
#define PMIC_TDSEL_CON                        (MT6355_PMIC_REG_BASE + 0x0218)
#define PMIC_RDSEL_CON                        (MT6355_PMIC_REG_BASE + 0x021A)
#define PMIC_SMT_CON0                         (MT6355_PMIC_REG_BASE + 0x021C)
#define PMIC_SMT_CON1                         (MT6355_PMIC_REG_BASE + 0x021E)
#define PMIC_DRV_CON0                         (MT6355_PMIC_REG_BASE + 0x0220)
#define PMIC_DRV_CON1                         (MT6355_PMIC_REG_BASE + 0x0222)
#define PMIC_DRV_CON2                         (MT6355_PMIC_REG_BASE + 0x0224)
#define PMIC_DRV_CON3                         (MT6355_PMIC_REG_BASE + 0x0226)
#define PMIC_FILTER_CON0                      (MT6355_PMIC_REG_BASE + 0x0228)
#define PMIC_FILTER_CON1                      (MT6355_PMIC_REG_BASE + 0x022A)
#define PMIC_TOP_STATUS                       (MT6355_PMIC_REG_BASE + 0x022C)
#define PMIC_TOP_STATUS_SET                   (MT6355_PMIC_REG_BASE + 0x022E)
#define PMIC_TOP_STATUS_CLR                   (MT6355_PMIC_REG_BASE + 0x0230)
#define PMIC_TOP_SPI_CON0                     (MT6355_PMIC_REG_BASE + 0x0232)
#define PMIC_TOP_SPI_CON1                     (MT6355_PMIC_REG_BASE + 0x0234)
#define PMIC_TOP_TRAP                         (MT6355_PMIC_REG_BASE + 0x0236)
#define PMIC_TOP_CKPDN_CON0                   (MT6355_PMIC_REG_BASE + 0x0400)
#define PMIC_TOP_CKPDN_CON0_SET               (MT6355_PMIC_REG_BASE + 0x0402)
#define PMIC_TOP_CKPDN_CON0_CLR               (MT6355_PMIC_REG_BASE + 0x0404)
#define PMIC_TOP_CKPDN_CON1                   (MT6355_PMIC_REG_BASE + 0x0406)
#define PMIC_TOP_CKPDN_CON1_SET               (MT6355_PMIC_REG_BASE + 0x0408)
#define PMIC_TOP_CKPDN_CON1_CLR               (MT6355_PMIC_REG_BASE + 0x040A)
#define PMIC_TOP_CKPDN_CON2                   (MT6355_PMIC_REG_BASE + 0x040C)
#define PMIC_TOP_CKPDN_CON2_SET               (MT6355_PMIC_REG_BASE + 0x040E)
#define PMIC_TOP_CKPDN_CON2_CLR               (MT6355_PMIC_REG_BASE + 0x0410)
#define PMIC_TOP_CKPDN_CON3                   (MT6355_PMIC_REG_BASE + 0x0412)
#define PMIC_TOP_CKPDN_CON3_SET               (MT6355_PMIC_REG_BASE + 0x0414)
#define PMIC_TOP_CKPDN_CON3_CLR               (MT6355_PMIC_REG_BASE + 0x0416)
#define PMIC_TOP_CKPDN_CON4                   (MT6355_PMIC_REG_BASE + 0x0418)
#define PMIC_TOP_CKPDN_CON4_SET               (MT6355_PMIC_REG_BASE + 0x041A)
#define PMIC_TOP_CKPDN_CON4_CLR               (MT6355_PMIC_REG_BASE + 0x041C)
#define PMIC_TOP_CKSEL_CON0                   (MT6355_PMIC_REG_BASE + 0x041E)
#define PMIC_TOP_CKSEL_CON0_SET               (MT6355_PMIC_REG_BASE + 0x0420)
#define PMIC_TOP_CKSEL_CON0_CLR               (MT6355_PMIC_REG_BASE + 0x0422)
#define PMIC_TOP_CKSEL_CON2                   (MT6355_PMIC_REG_BASE + 0x0424)
#define PMIC_TOP_CKSEL_CON2_SET               (MT6355_PMIC_REG_BASE + 0x0426)
#define PMIC_TOP_CKSEL_CON2_CLR               (MT6355_PMIC_REG_BASE + 0x0428)
#define PMIC_TOP_CKDIVSEL_CON0                (MT6355_PMIC_REG_BASE + 0x042A)
#define PMIC_TOP_CKDIVSEL_CON0_SET            (MT6355_PMIC_REG_BASE + 0x042C)
#define PMIC_TOP_CKDIVSEL_CON0_CLR            (MT6355_PMIC_REG_BASE + 0x042E)
#define PMIC_TOP_CKHWEN_CON0                  (MT6355_PMIC_REG_BASE + 0x0430)
#define PMIC_TOP_CKHWEN_CON0_SET              (MT6355_PMIC_REG_BASE + 0x0432)
#define PMIC_TOP_CKHWEN_CON0_CLR              (MT6355_PMIC_REG_BASE + 0x0434)
#define PMIC_TOP_CKHWEN_CON1                  (MT6355_PMIC_REG_BASE + 0x0436)
#define PMIC_TOP_CKHWEN_CON1_SET              (MT6355_PMIC_REG_BASE + 0x0438)
#define PMIC_TOP_CKHWEN_CON1_CLR              (MT6355_PMIC_REG_BASE + 0x043A)
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON0     (MT6355_PMIC_REG_BASE + 0x043C)
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON0_SET (MT6355_PMIC_REG_BASE + 0x043E)
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON0_CLR (MT6355_PMIC_REG_BASE + 0x0440)
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON1     (MT6355_PMIC_REG_BASE + 0x0442)
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON1_SET (MT6355_PMIC_REG_BASE + 0x0444)
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON1_CLR (MT6355_PMIC_REG_BASE + 0x0446)
#define PMIC_TOP_CKTST_CON0                   (MT6355_PMIC_REG_BASE + 0x0448)
#define PMIC_TOP_CKTST_CON1                   (MT6355_PMIC_REG_BASE + 0x044A)
#define PMIC_TOP_CLKSQ                        (MT6355_PMIC_REG_BASE + 0x044C)
#define PMIC_TOP_CLKSQ_SET                    (MT6355_PMIC_REG_BASE + 0x044E)
#define PMIC_TOP_CLKSQ_CLR                    (MT6355_PMIC_REG_BASE + 0x0450)
#define PMIC_TOP_CLKSQ_RTC                    (MT6355_PMIC_REG_BASE + 0x0452)
#define PMIC_TOP_CLKSQ_RTC_SET                (MT6355_PMIC_REG_BASE + 0x0454)
#define PMIC_TOP_CLKSQ_RTC_CLR                (MT6355_PMIC_REG_BASE + 0x0456)
#define PMIC_TOP_CLK_TRIM                     (MT6355_PMIC_REG_BASE + 0x0458)
#define PMIC_TOP_CLK_CON0                     (MT6355_PMIC_REG_BASE + 0x045A)
#define PMIC_TOP_CLK_CON0_SET                 (MT6355_PMIC_REG_BASE + 0x045C)
#define PMIC_TOP_CLK_CON0_CLR                 (MT6355_PMIC_REG_BASE + 0x045E)
#define PMIC_TOP_CLK_CON1                     (MT6355_PMIC_REG_BASE + 0x0460)
#define PMIC_TOP_CLK_CON1_SET                 (MT6355_PMIC_REG_BASE + 0x0462)
#define PMIC_TOP_CLK_CON1_CLR                 (MT6355_PMIC_REG_BASE + 0x0464)
#define PMIC_TOP_CLK_CON2                     (MT6355_PMIC_REG_BASE + 0x0466)
#define PMIC_TOP_RST_CON0                     (MT6355_PMIC_REG_BASE + 0x0600)
#define PMIC_TOP_RST_CON0_SET                 (MT6355_PMIC_REG_BASE + 0x0602)
#define PMIC_TOP_RST_CON0_CLR                 (MT6355_PMIC_REG_BASE + 0x0604)
#define PMIC_TOP_RST_CON1                     (MT6355_PMIC_REG_BASE + 0x0606)
#define PMIC_TOP_RST_CON1_SET                 (MT6355_PMIC_REG_BASE + 0x0608)
#define PMIC_TOP_RST_CON1_CLR                 (MT6355_PMIC_REG_BASE + 0x060A)
#define PMIC_TOP_RST_CON2                     (MT6355_PMIC_REG_BASE + 0x060C)
#define PMIC_TOP_RST_MISC                     (MT6355_PMIC_REG_BASE + 0x060E)
#define PMIC_TOP_RST_MISC_SET                 (MT6355_PMIC_REG_BASE + 0x0610)
#define PMIC_TOP_RST_MISC_CLR                 (MT6355_PMIC_REG_BASE + 0x0612)
#define PMIC_TOP_RST_STATUS                   (MT6355_PMIC_REG_BASE + 0x0614)
#define PMIC_TOP_RST_STATUS_SET               (MT6355_PMIC_REG_BASE + 0x0616)
#define PMIC_TOP_RST_STATUS_CLR               (MT6355_PMIC_REG_BASE + 0x0618)
#define PMIC_TOP_RST_RSV_CON0                 (MT6355_PMIC_REG_BASE + 0x061A)
#define PMIC_TOP_RST_RSV_CON1                 (MT6355_PMIC_REG_BASE + 0x061C)
#define PMIC_TOP_RST_BANK_CON0                (MT6355_PMIC_REG_BASE + 0x061E)
#define PMIC_TOP_RST_BANK_CON0_SET            (MT6355_PMIC_REG_BASE + 0x0620)
#define PMIC_TOP_RST_BANK_CON0_CLR            (MT6355_PMIC_REG_BASE + 0x0622)
#define PMIC_TOP_RST_BANK_CON1                (MT6355_PMIC_REG_BASE + 0x0624)
#define PMIC_TOP_RST_BANK_CON1_SET            (MT6355_PMIC_REG_BASE + 0x0626)
#define PMIC_TOP_RST_BANK_CON1_CLR            (MT6355_PMIC_REG_BASE + 0x0628)
#define PMIC_INT_CON0                         (MT6355_PMIC_REG_BASE + 0x0800)
#define PMIC_INT_CON0_SET                     (MT6355_PMIC_REG_BASE + 0x0802)
#define PMIC_INT_CON0_CLR                     (MT6355_PMIC_REG_BASE + 0x0804)
#define PMIC_INT_CON1                         (MT6355_PMIC_REG_BASE + 0x0806)
#define PMIC_INT_CON1_SET                     (MT6355_PMIC_REG_BASE + 0x0808)
#define PMIC_INT_CON1_CLR                     (MT6355_PMIC_REG_BASE + 0x080A)
#define PMIC_INT_CON2                         (MT6355_PMIC_REG_BASE + 0x080C)
#define PMIC_INT_CON2_SET                     (MT6355_PMIC_REG_BASE + 0x080E)
#define PMIC_INT_CON2_CLR                     (MT6355_PMIC_REG_BASE + 0x0810)
#define PMIC_INT_CON3                         (MT6355_PMIC_REG_BASE + 0x0812)
#define PMIC_INT_CON3_SET                     (MT6355_PMIC_REG_BASE + 0x0814)
#define PMIC_INT_CON3_CLR                     (MT6355_PMIC_REG_BASE + 0x0816)
#define PMIC_INT_CON4                         (MT6355_PMIC_REG_BASE + 0x0818)
#define PMIC_INT_CON4_SET                     (MT6355_PMIC_REG_BASE + 0x081A)
#define PMIC_INT_CON4_CLR                     (MT6355_PMIC_REG_BASE + 0x081C)
#define PMIC_INT_CON5                         (MT6355_PMIC_REG_BASE + 0x081E)
#define PMIC_INT_CON5_SET                     (MT6355_PMIC_REG_BASE + 0x0820)
#define PMIC_INT_CON5_CLR                     (MT6355_PMIC_REG_BASE + 0x0822)
#define PMIC_INT_CON6                         (MT6355_PMIC_REG_BASE + 0x0824)
#define PMIC_INT_CON6_SET                     (MT6355_PMIC_REG_BASE + 0x0826)
#define PMIC_INT_CON6_CLR                     (MT6355_PMIC_REG_BASE + 0x0828)
#define PMIC_INT_MASK_CON0                    (MT6355_PMIC_REG_BASE + 0x082A)
#define PMIC_INT_MASK_CON0_SET                (MT6355_PMIC_REG_BASE + 0x082C)
#define PMIC_INT_MASK_CON0_CLR                (MT6355_PMIC_REG_BASE + 0x082E)
#define PMIC_INT_MASK_CON1                    (MT6355_PMIC_REG_BASE + 0x0830)
#define PMIC_INT_MASK_CON1_SET                (MT6355_PMIC_REG_BASE + 0x0832)
#define PMIC_INT_MASK_CON1_CLR                (MT6355_PMIC_REG_BASE + 0x0834)
#define PMIC_INT_MASK_CON2                    (MT6355_PMIC_REG_BASE + 0x0836)
#define PMIC_INT_MASK_CON2_SET                (MT6355_PMIC_REG_BASE + 0x0838)
#define PMIC_INT_MASK_CON2_CLR                (MT6355_PMIC_REG_BASE + 0x083A)
#define PMIC_INT_MASK_CON3                    (MT6355_PMIC_REG_BASE + 0x083C)
#define PMIC_INT_MASK_CON3_SET                (MT6355_PMIC_REG_BASE + 0x083E)
#define PMIC_INT_MASK_CON3_CLR                (MT6355_PMIC_REG_BASE + 0x0840)
#define PMIC_INT_MASK_CON4                    (MT6355_PMIC_REG_BASE + 0x0842)
#define PMIC_INT_MASK_CON4_SET                (MT6355_PMIC_REG_BASE + 0x0844)
#define PMIC_INT_MASK_CON4_CLR                (MT6355_PMIC_REG_BASE + 0x0846)
#define PMIC_INT_MASK_CON5                    (MT6355_PMIC_REG_BASE + 0x0848)
#define PMIC_INT_MASK_CON5_SET                (MT6355_PMIC_REG_BASE + 0x084A)
#define PMIC_INT_MASK_CON5_CLR                (MT6355_PMIC_REG_BASE + 0x084C)
#define PMIC_INT_MASK_CON6                    (MT6355_PMIC_REG_BASE + 0x084E)
#define PMIC_INT_MASK_CON6_SET                (MT6355_PMIC_REG_BASE + 0x0850)
#define PMIC_INT_MASK_CON6_CLR                (MT6355_PMIC_REG_BASE + 0x0852)
#define PMIC_INT_STATUS0                      (MT6355_PMIC_REG_BASE + 0x0854)
#define PMIC_INT_STATUS1                      (MT6355_PMIC_REG_BASE + 0x0856)
#define PMIC_INT_STATUS2                      (MT6355_PMIC_REG_BASE + 0x0858)
#define PMIC_INT_STATUS3                      (MT6355_PMIC_REG_BASE + 0x085A)
#define PMIC_INT_STATUS4                      (MT6355_PMIC_REG_BASE + 0x085C)
#define PMIC_INT_STATUS5                      (MT6355_PMIC_REG_BASE + 0x085E)
#define PMIC_INT_STATUS6                      (MT6355_PMIC_REG_BASE + 0x0860)
#define PMIC_INT_RAW_STATUS0                  (MT6355_PMIC_REG_BASE + 0x0862)
#define PMIC_INT_RAW_STATUS1                  (MT6355_PMIC_REG_BASE + 0x0864)
#define PMIC_INT_RAW_STATUS2                  (MT6355_PMIC_REG_BASE + 0x0866)
#define PMIC_INT_RAW_STATUS3                  (MT6355_PMIC_REG_BASE + 0x0868)
#define PMIC_INT_RAW_STATUS4                  (MT6355_PMIC_REG_BASE + 0x086A)
#define PMIC_INT_RAW_STATUS5                  (MT6355_PMIC_REG_BASE + 0x086C)
#define PMIC_INT_RAW_STATUS6                  (MT6355_PMIC_REG_BASE + 0x086E)
#define PMIC_INT_MISC_CON                     (MT6355_PMIC_REG_BASE + 0x0870)
#define PMIC_INT_MISC_CON_SET                 (MT6355_PMIC_REG_BASE + 0x0872)
#define PMIC_INT_MISC_CON_CLR                 (MT6355_PMIC_REG_BASE + 0x0874)
#define PMIC_INT_EINT_CON0                    (MT6355_PMIC_REG_BASE + 0x0876)
#define PMIC_INT_EINT_CON0_SET                (MT6355_PMIC_REG_BASE + 0x0878)
#define PMIC_INT_EINT_CON0_CLR                (MT6355_PMIC_REG_BASE + 0x087A)
#define PMIC_INT_EINT_CON1                    (MT6355_PMIC_REG_BASE + 0x087C)
#define PMIC_INT_EINT_CON1_SET                (MT6355_PMIC_REG_BASE + 0x087E)
#define PMIC_INT_EINT_CON1_CLR                (MT6355_PMIC_REG_BASE + 0x0880)
#define PMIC_INT_EINT_CON2                    (MT6355_PMIC_REG_BASE + 0x0882)
#define PMIC_INT_EINT_CON2_SET                (MT6355_PMIC_REG_BASE + 0x0884)
#define PMIC_INT_EINT_CON2_CLR                (MT6355_PMIC_REG_BASE + 0x0886)
#define PMIC_INT_EINT_CON3                    (MT6355_PMIC_REG_BASE + 0x0888)
#define PMIC_INT_EINT_CON3_SET                (MT6355_PMIC_REG_BASE + 0x088A)
#define PMIC_INT_EINT_CON3_CLR                (MT6355_PMIC_REG_BASE + 0x088C)
#define PMIC_INT_EINT_CON4                    (MT6355_PMIC_REG_BASE + 0x088E)
#define PMIC_INT_EINT_CON4_SET                (MT6355_PMIC_REG_BASE + 0x0890)
#define PMIC_INT_EINT_CON4_CLR                (MT6355_PMIC_REG_BASE + 0x0892)
#define PMIC_FQMTR_CON0                       (MT6355_PMIC_REG_BASE + 0x0A00)
#define PMIC_FQMTR_CON1                       (MT6355_PMIC_REG_BASE + 0x0A02)
#define PMIC_FQMTR_CON2                       (MT6355_PMIC_REG_BASE + 0x0A04)
#define PMIC_RG_SPI_CON0                      (MT6355_PMIC_REG_BASE + 0x0C00)
#define PMIC_DEW_DIO_EN                       (MT6355_PMIC_REG_BASE + 0x0C02)
#define PMIC_DEW_READ_TEST                    (MT6355_PMIC_REG_BASE + 0x0C04)
#define PMIC_DEW_WRITE_TEST                   (MT6355_PMIC_REG_BASE + 0x0C06)
#define PMIC_DEW_CRC_SWRST                    (MT6355_PMIC_REG_BASE + 0x0C08)
#define PMIC_DEW_CRC_EN                       (MT6355_PMIC_REG_BASE + 0x0C0A)
#define PMIC_DEW_CRC_VAL                      (MT6355_PMIC_REG_BASE + 0x0C0C)
#define PMIC_DEW_DBG_MON_SEL                  (MT6355_PMIC_REG_BASE + 0x0C0E)
#define PMIC_DEW_CIPHER_KEY_SEL               (MT6355_PMIC_REG_BASE + 0x0C10)
#define PMIC_DEW_CIPHER_IV_SEL                (MT6355_PMIC_REG_BASE + 0x0C12)
#define PMIC_DEW_CIPHER_EN                    (MT6355_PMIC_REG_BASE + 0x0C14)
#define PMIC_DEW_CIPHER_RDY                   (MT6355_PMIC_REG_BASE + 0x0C16)
#define PMIC_DEW_CIPHER_MODE                  (MT6355_PMIC_REG_BASE + 0x0C18)
#define PMIC_DEW_CIPHER_SWRST                 (MT6355_PMIC_REG_BASE + 0x0C1A)
#define PMIC_DEW_RDDMY_NO                     (MT6355_PMIC_REG_BASE + 0x0C1C)
#define PMIC_INT_TYPE_CON0                    (MT6355_PMIC_REG_BASE + 0x0C1E)
#define PMIC_INT_TYPE_CON0_SET                (MT6355_PMIC_REG_BASE + 0x0C20)
#define PMIC_INT_TYPE_CON0_CLR                (MT6355_PMIC_REG_BASE + 0x0C22)
#define PMIC_INT_TYPE_CON1                    (MT6355_PMIC_REG_BASE + 0x0C24)
#define PMIC_INT_TYPE_CON1_SET                (MT6355_PMIC_REG_BASE + 0x0C26)
#define PMIC_INT_TYPE_CON1_CLR                (MT6355_PMIC_REG_BASE + 0x0C28)
#define PMIC_INT_TYPE_CON2                    (MT6355_PMIC_REG_BASE + 0x0C2A)
#define PMIC_INT_TYPE_CON2_SET                (MT6355_PMIC_REG_BASE + 0x0C2C)
#define PMIC_INT_TYPE_CON2_CLR                (MT6355_PMIC_REG_BASE + 0x0C2E)
#define PMIC_INT_TYPE_CON3                    (MT6355_PMIC_REG_BASE + 0x0C30)
#define PMIC_INT_TYPE_CON3_SET                (MT6355_PMIC_REG_BASE + 0x0C32)
#define PMIC_INT_TYPE_CON3_CLR                (MT6355_PMIC_REG_BASE + 0x0C34)
#define PMIC_INT_TYPE_CON4                    (MT6355_PMIC_REG_BASE + 0x0C36)
#define PMIC_INT_TYPE_CON4_SET                (MT6355_PMIC_REG_BASE + 0x0C38)
#define PMIC_INT_TYPE_CON4_CLR                (MT6355_PMIC_REG_BASE + 0x0C3A)
#define PMIC_INT_TYPE_CON5                    (MT6355_PMIC_REG_BASE + 0x0C3C)
#define PMIC_INT_TYPE_CON5_SET                (MT6355_PMIC_REG_BASE + 0x0C3E)
#define PMIC_INT_TYPE_CON5_CLR                (MT6355_PMIC_REG_BASE + 0x0C40)
#define PMIC_INT_TYPE_CON6                    (MT6355_PMIC_REG_BASE + 0x0C42)
#define PMIC_INT_TYPE_CON6_SET                (MT6355_PMIC_REG_BASE + 0x0C44)
#define PMIC_INT_TYPE_CON6_CLR                (MT6355_PMIC_REG_BASE + 0x0C46)
#define PMIC_INT_STA                          (MT6355_PMIC_REG_BASE + 0x0C48)
#define PMIC_RG_SPI_CON1                      (MT6355_PMIC_REG_BASE + 0x0C4A)
#define PMIC_RG_SPI_CON2                      (MT6355_PMIC_REG_BASE + 0x0C4C)
#define PMIC_RG_SPI_CON3                      (MT6355_PMIC_REG_BASE + 0x0C4E)
#define PMIC_RG_SPI_CON4                      (MT6355_PMIC_REG_BASE + 0x0C50)
#define PMIC_RG_SPI_CON5                      (MT6355_PMIC_REG_BASE + 0x0C52)
#define PMIC_RG_SPI_CON6                      (MT6355_PMIC_REG_BASE + 0x0C54)
#define PMIC_RG_SPI_CON7                      (MT6355_PMIC_REG_BASE + 0x0C56)
#define PMIC_RG_SPI_CON8                      (MT6355_PMIC_REG_BASE + 0x0C58)
#define PMIC_RG_SPI_CON9                      (MT6355_PMIC_REG_BASE + 0x0C5A)
#define PMIC_RG_SPI_CON10                     (MT6355_PMIC_REG_BASE + 0x0C5C)
#define PMIC_RG_SPI_CON11                     (MT6355_PMIC_REG_BASE + 0x0C5E)
#define PMIC_RG_SPI_CON12                     (MT6355_PMIC_REG_BASE + 0x0C60)
#define PMIC_RG_SPI_CON13                     (MT6355_PMIC_REG_BASE + 0x0C62)
#define PMIC_STRUP_CON0                       (MT6355_PMIC_REG_BASE + 0x0E00)
#define PMIC_STRUP_CON1                       (MT6355_PMIC_REG_BASE + 0x0E02)
#define PMIC_STRUP_CON2                       (MT6355_PMIC_REG_BASE + 0x0E04)
#define PMIC_STRUP_CON3                       (MT6355_PMIC_REG_BASE + 0x0E06)
#define PMIC_STRUP_CON4                       (MT6355_PMIC_REG_BASE + 0x0E08)
#define PMIC_STRUP_CON5                       (MT6355_PMIC_REG_BASE + 0x0E0A)
#define PMIC_STRUP_CON6                       (MT6355_PMIC_REG_BASE + 0x0E0C)
#define PMIC_STRUP_CON7                       (MT6355_PMIC_REG_BASE + 0x0E0E)
#define PMIC_STRUP_CON8                       (MT6355_PMIC_REG_BASE + 0x0E10)
#define PMIC_STRUP_CON9                       (MT6355_PMIC_REG_BASE + 0x0E12)
#define PMIC_STRUP_CON10                      (MT6355_PMIC_REG_BASE + 0x0E14)
#define PMIC_STRUP_CON11                      (MT6355_PMIC_REG_BASE + 0x0E16)
#define PMIC_STRUP_CON12                      (MT6355_PMIC_REG_BASE + 0x0E18)
#define PMIC_STRUP_CON13                      (MT6355_PMIC_REG_BASE + 0x0E1A)
#define PMIC_STRUP_CON14                      (MT6355_PMIC_REG_BASE + 0x0E1C)
#define PMIC_STRUP_CON15                      (MT6355_PMIC_REG_BASE + 0x0E1E)
#define PMIC_STRUP_CON16                      (MT6355_PMIC_REG_BASE + 0x0E20)
#define PMIC_STRUP_CON17                      (MT6355_PMIC_REG_BASE + 0x0E22)
#define PMIC_STRUP_CON18                      (MT6355_PMIC_REG_BASE + 0x0E24)
#define PMIC_STRUP_CON19                      (MT6355_PMIC_REG_BASE + 0x0E26)
#define PMIC_STRUP_CON20                      (MT6355_PMIC_REG_BASE + 0x0E28)
#define PMIC_STRUP_ANA_CON0                   (MT6355_PMIC_REG_BASE + 0x0E2A)
#define PMIC_STRUP_ANA_CON1                   (MT6355_PMIC_REG_BASE + 0x0E2C)
#define PMIC_PPCCTL0                          (MT6355_PMIC_REG_BASE + 0x0E2E)
#define PMIC_PPCCTL1                          (MT6355_PMIC_REG_BASE + 0x0E30)
#define PMIC_PPCCTL2                          (MT6355_PMIC_REG_BASE + 0x0E32)
#define PMIC_PPCCFG0                          (MT6355_PMIC_REG_BASE + 0x0E34)
#define PMIC_PPCTST0                          (MT6355_PMIC_REG_BASE + 0x0E36)
#define PMIC_PPCRSV0                          (MT6355_PMIC_REG_BASE + 0x0E38)
#define PMIC_BWDTCTL0                         (MT6355_PMIC_REG_BASE + 0x0E3A)
#define PMIC_CPSWKEY                          (MT6355_PMIC_REG_BASE + 0x0E3C)
#define PMIC_CPSCFG0                          (MT6355_PMIC_REG_BASE + 0x0E3E)
#define PMIC_CPSCFG1                          (MT6355_PMIC_REG_BASE + 0x0E40)
#define PMIC_CPSPSA0                          (MT6355_PMIC_REG_BASE + 0x0E42)
#define PMIC_CPSPSA1                          (MT6355_PMIC_REG_BASE + 0x0E44)
#define PMIC_CPSPSA2                          (MT6355_PMIC_REG_BASE + 0x0E46)
#define PMIC_CPSPSA3                          (MT6355_PMIC_REG_BASE + 0x0E48)
#define PMIC_CPSPSA4                          (MT6355_PMIC_REG_BASE + 0x0E4A)
#define PMIC_CPSPSA5                          (MT6355_PMIC_REG_BASE + 0x0E4C)
#define PMIC_CPSPSA6                          (MT6355_PMIC_REG_BASE + 0x0E4E)
#define PMIC_CPSPSA7                          (MT6355_PMIC_REG_BASE + 0x0E50)
#define PMIC_CPSPSA8                          (MT6355_PMIC_REG_BASE + 0x0E52)
#define PMIC_CPSPSA9                          (MT6355_PMIC_REG_BASE + 0x0E54)
#define PMIC_CPSPSA10                         (MT6355_PMIC_REG_BASE + 0x0E56)
#define PMIC_CPSPSA11                         (MT6355_PMIC_REG_BASE + 0x0E58)
#define PMIC_CPSDSA0                          (MT6355_PMIC_REG_BASE + 0x0E5A)
#define PMIC_CPSDSA1                          (MT6355_PMIC_REG_BASE + 0x0E5C)
#define PMIC_CPSDSA2                          (MT6355_PMIC_REG_BASE + 0x0E5E)
#define PMIC_CPSDSA3                          (MT6355_PMIC_REG_BASE + 0x0E60)
#define PMIC_CPSDSA4                          (MT6355_PMIC_REG_BASE + 0x0E62)
#define PMIC_CPSDSA5                          (MT6355_PMIC_REG_BASE + 0x0E64)
#define PMIC_CPSDSA6                          (MT6355_PMIC_REG_BASE + 0x0E66)
#define PMIC_CPSDSA7                          (MT6355_PMIC_REG_BASE + 0x0E68)
#define PMIC_CPSDSA8                          (MT6355_PMIC_REG_BASE + 0x0E6A)
#define PMIC_CPSDSA9                          (MT6355_PMIC_REG_BASE + 0x0E6C)
#define PMIC_CPSDSA10                         (MT6355_PMIC_REG_BASE + 0x0E6E)
#define PMIC_CPSDSA11                         (MT6355_PMIC_REG_BASE + 0x0E70)
#define PMIC_PORFLAG                          (MT6355_PMIC_REG_BASE + 0x0E72)
#define PMIC_PONSTS                           (MT6355_PMIC_REG_BASE + 0x0E74)
#define PMIC_POFFSTS                          (MT6355_PMIC_REG_BASE + 0x0E76)
#define PMIC_PSTSCTL                          (MT6355_PMIC_REG_BASE + 0x0E78)
#define PMIC_BUCK_ALL_CON0                    (MT6355_PMIC_REG_BASE + 0x1000)
#define PMIC_BUCK_STB_CON                     (MT6355_PMIC_REG_BASE + 0x1002)
#define PMIC_BUCK_SLP_CON0                    (MT6355_PMIC_REG_BASE + 0x1004)
#define PMIC_BUCK_SLP_CON1                    (MT6355_PMIC_REG_BASE + 0x1006)
#define PMIC_BUCK_SLP_CON2                    (MT6355_PMIC_REG_BASE + 0x1008)
#define PMIC_BUCK_MINFREQ_CON                 (MT6355_PMIC_REG_BASE + 0x100A)
#define PMIC_BUCK_OC_CON0                     (MT6355_PMIC_REG_BASE + 0x100C)
#define PMIC_BUCK_OC_CON1                     (MT6355_PMIC_REG_BASE + 0x100E)
#define PMIC_BUCK_K_CON0                      (MT6355_PMIC_REG_BASE + 0x1010)
#define PMIC_BUCK_K_CON1                      (MT6355_PMIC_REG_BASE + 0x1012)
#define PMIC_BUCK_K_CON2                      (MT6355_PMIC_REG_BASE + 0x1014)
#define PMIC_BUCK_K_CON3                      (MT6355_PMIC_REG_BASE + 0x1016)
#define PMIC_BUCK_VOW_CON                     (MT6355_PMIC_REG_BASE + 0x1018)
#define PMIC_BUCK_VPROC11_CON0                (MT6355_PMIC_REG_BASE + 0x101A)
#define PMIC_BUCK_VPROC11_CON1                (MT6355_PMIC_REG_BASE + 0x101C)
#define PMIC_BUCK_VPROC11_CON2                (MT6355_PMIC_REG_BASE + 0x101E)
#define PMIC_BUCK_VPROC11_CFG0                (MT6355_PMIC_REG_BASE + 0x1020)
#define PMIC_BUCK_VPROC11_CFG1                (MT6355_PMIC_REG_BASE + 0x1022)
#define PMIC_BUCK_VPROC11_OP_EN               (MT6355_PMIC_REG_BASE + 0x1024)
#define PMIC_BUCK_VPROC11_OP_EN_SET           (MT6355_PMIC_REG_BASE + 0x1026)
#define PMIC_BUCK_VPROC11_OP_EN_CLR           (MT6355_PMIC_REG_BASE + 0x1028)
#define PMIC_BUCK_VPROC11_OP_CFG              (MT6355_PMIC_REG_BASE + 0x102A)
#define PMIC_BUCK_VPROC11_OP_CFG_SET          (MT6355_PMIC_REG_BASE + 0x102C)
#define PMIC_BUCK_VPROC11_OP_CFG_CLR          (MT6355_PMIC_REG_BASE + 0x102E)
#define PMIC_BUCK_VPROC11_SP_CON              (MT6355_PMIC_REG_BASE + 0x1030)
#define PMIC_BUCK_VPROC11_SP_CFG              (MT6355_PMIC_REG_BASE + 0x1032)
#define PMIC_BUCK_VPROC11_OC_CFG              (MT6355_PMIC_REG_BASE + 0x1034)
#define PMIC_BUCK_VPROC11_DBG0                (MT6355_PMIC_REG_BASE + 0x1036)
#define PMIC_BUCK_VPROC11_DBG1                (MT6355_PMIC_REG_BASE + 0x1038)
#define PMIC_BUCK_VPROC11_DBG2                (MT6355_PMIC_REG_BASE + 0x103A)
#define PMIC_BUCK_VPROC12_CON0                (MT6355_PMIC_REG_BASE + 0x103C)
#define PMIC_BUCK_VPROC12_CON1                (MT6355_PMIC_REG_BASE + 0x103E)
#define PMIC_BUCK_VPROC12_CON2                (MT6355_PMIC_REG_BASE + 0x1040)
#define PMIC_BUCK_VPROC12_CFG0                (MT6355_PMIC_REG_BASE + 0x1042)
#define PMIC_BUCK_VPROC12_CFG1                (MT6355_PMIC_REG_BASE + 0x1044)
#define PMIC_BUCK_VPROC12_OP_EN               (MT6355_PMIC_REG_BASE + 0x1046)
#define PMIC_BUCK_VPROC12_OP_EN_SET           (MT6355_PMIC_REG_BASE + 0x1048)
#define PMIC_BUCK_VPROC12_OP_EN_CLR           (MT6355_PMIC_REG_BASE + 0x104A)
#define PMIC_BUCK_VPROC12_OP_CFG              (MT6355_PMIC_REG_BASE + 0x104C)
#define PMIC_BUCK_VPROC12_OP_CFG_SET          (MT6355_PMIC_REG_BASE + 0x104E)
#define PMIC_BUCK_VPROC12_OP_CFG_CLR          (MT6355_PMIC_REG_BASE + 0x1050)
#define PMIC_BUCK_VPROC12_SP_CON              (MT6355_PMIC_REG_BASE + 0x1052)
#define PMIC_BUCK_VPROC12_SP_CFG              (MT6355_PMIC_REG_BASE + 0x1054)
#define PMIC_BUCK_VPROC12_OC_CFG              (MT6355_PMIC_REG_BASE + 0x1056)
#define PMIC_BUCK_VPROC12_DBG0                (MT6355_PMIC_REG_BASE + 0x1058)
#define PMIC_BUCK_VPROC12_DBG1                (MT6355_PMIC_REG_BASE + 0x105A)
#define PMIC_BUCK_VPROC12_DBG2                (MT6355_PMIC_REG_BASE + 0x105C)
#define PMIC_BUCK_VCORE_CON0                  (MT6355_PMIC_REG_BASE + 0x105E)
#define PMIC_BUCK_VCORE_CON1                  (MT6355_PMIC_REG_BASE + 0x1060)
#define PMIC_BUCK_VCORE_CON2                  (MT6355_PMIC_REG_BASE + 0x1062)
#define PMIC_BUCK_VCORE_CFG0                  (MT6355_PMIC_REG_BASE + 0x1064)
#define PMIC_BUCK_VCORE_CFG1                  (MT6355_PMIC_REG_BASE + 0x1066)
#define PMIC_BUCK_VCORE_OP_EN                 (MT6355_PMIC_REG_BASE + 0x1068)
#define PMIC_BUCK_VCORE_OP_EN_SET             (MT6355_PMIC_REG_BASE + 0x106A)
#define PMIC_BUCK_VCORE_OP_EN_CLR             (MT6355_PMIC_REG_BASE + 0x106C)
#define PMIC_BUCK_VCORE_OP_CFG                (MT6355_PMIC_REG_BASE + 0x106E)
#define PMIC_BUCK_VCORE_OP_CFG_SET            (MT6355_PMIC_REG_BASE + 0x1070)
#define PMIC_BUCK_VCORE_OP_CFG_CLR            (MT6355_PMIC_REG_BASE + 0x1072)
#define PMIC_BUCK_VCORE_SP_CON                (MT6355_PMIC_REG_BASE + 0x1074)
#define PMIC_BUCK_VCORE_SP_CFG                (MT6355_PMIC_REG_BASE + 0x1076)
#define PMIC_BUCK_VCORE_OC_CFG                (MT6355_PMIC_REG_BASE + 0x1078)
#define PMIC_BUCK_VCORE_DBG0                  (MT6355_PMIC_REG_BASE + 0x107A)
#define PMIC_BUCK_VCORE_DBG1                  (MT6355_PMIC_REG_BASE + 0x107C)
#define PMIC_BUCK_VCORE_DBG2                  (MT6355_PMIC_REG_BASE + 0x107E)
#define PMIC_BUCK_VCORE_SSHUB_CON             (MT6355_PMIC_REG_BASE + 0x1080)
#define PMIC_BUCK_VGPU_CON0                   (MT6355_PMIC_REG_BASE + 0x1082)
#define PMIC_BUCK_VGPU_CON1                   (MT6355_PMIC_REG_BASE + 0x1084)
#define PMIC_BUCK_VGPU_CON2                   (MT6355_PMIC_REG_BASE + 0x1086)
#define PMIC_BUCK_VGPU_CFG0                   (MT6355_PMIC_REG_BASE + 0x1088)
#define PMIC_BUCK_VGPU_CFG1                   (MT6355_PMIC_REG_BASE + 0x108A)
#define PMIC_BUCK_VGPU_OP_EN                  (MT6355_PMIC_REG_BASE + 0x108C)
#define PMIC_BUCK_VGPU_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x108E)
#define PMIC_BUCK_VGPU_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x1090)
#define PMIC_BUCK_VGPU_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x1092)
#define PMIC_BUCK_VGPU_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x1094)
#define PMIC_BUCK_VGPU_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x1096)
#define PMIC_BUCK_VGPU_SP_CON                 (MT6355_PMIC_REG_BASE + 0x1098)
#define PMIC_BUCK_VGPU_SP_CFG                 (MT6355_PMIC_REG_BASE + 0x109A)
#define PMIC_BUCK_VGPU_OC_CFG                 (MT6355_PMIC_REG_BASE + 0x109C)
#define PMIC_BUCK_VGPU_DBG0                   (MT6355_PMIC_REG_BASE + 0x109E)
#define PMIC_BUCK_VGPU_DBG1                   (MT6355_PMIC_REG_BASE + 0x10A0)
#define PMIC_BUCK_VGPU_DBG2                   (MT6355_PMIC_REG_BASE + 0x10A2)
#define PMIC_BUCK_VDRAM1_CON0                 (MT6355_PMIC_REG_BASE + 0x10A4)
#define PMIC_BUCK_VDRAM1_CON1                 (MT6355_PMIC_REG_BASE + 0x10A6)
#define PMIC_BUCK_VDRAM1_CON2                 (MT6355_PMIC_REG_BASE + 0x10A8)
#define PMIC_BUCK_VDRAM1_CFG0                 (MT6355_PMIC_REG_BASE + 0x10AA)
#define PMIC_BUCK_VDRAM1_CFG1                 (MT6355_PMIC_REG_BASE + 0x10AC)
#define PMIC_BUCK_VDRAM1_OP_EN                (MT6355_PMIC_REG_BASE + 0x10AE)
#define PMIC_BUCK_VDRAM1_OP_EN_SET            (MT6355_PMIC_REG_BASE + 0x10B0)
#define PMIC_BUCK_VDRAM1_OP_EN_CLR            (MT6355_PMIC_REG_BASE + 0x10B2)
#define PMIC_BUCK_VDRAM1_OP_CFG               (MT6355_PMIC_REG_BASE + 0x10B4)
#define PMIC_BUCK_VDRAM1_OP_CFG_SET           (MT6355_PMIC_REG_BASE + 0x10B6)
#define PMIC_BUCK_VDRAM1_OP_CFG_CLR           (MT6355_PMIC_REG_BASE + 0x10B8)
#define PMIC_BUCK_VDRAM1_SP_CON               (MT6355_PMIC_REG_BASE + 0x10BA)
#define PMIC_BUCK_VDRAM1_SP_CFG               (MT6355_PMIC_REG_BASE + 0x10BC)
#define PMIC_BUCK_VDRAM1_OC_CFG               (MT6355_PMIC_REG_BASE + 0x10BE)
#define PMIC_BUCK_VDRAM1_DBG0                 (MT6355_PMIC_REG_BASE + 0x10C0)
#define PMIC_BUCK_VDRAM1_DBG1                 (MT6355_PMIC_REG_BASE + 0x10C2)
#define PMIC_BUCK_VDRAM1_DBG2                 (MT6355_PMIC_REG_BASE + 0x10C4)
#define PMIC_BUCK_VDRAM2_CON0                 (MT6355_PMIC_REG_BASE + 0x10C6)
#define PMIC_BUCK_VDRAM2_CON1                 (MT6355_PMIC_REG_BASE + 0x10C8)
#define PMIC_BUCK_VDRAM2_CON2                 (MT6355_PMIC_REG_BASE + 0x10CA)
#define PMIC_BUCK_VDRAM2_CFG0                 (MT6355_PMIC_REG_BASE + 0x10CC)
#define PMIC_BUCK_VDRAM2_CFG1                 (MT6355_PMIC_REG_BASE + 0x10CE)
#define PMIC_BUCK_VDRAM2_OP_EN                (MT6355_PMIC_REG_BASE + 0x10D0)
#define PMIC_BUCK_VDRAM2_OP_EN_SET            (MT6355_PMIC_REG_BASE + 0x10D2)
#define PMIC_BUCK_VDRAM2_OP_EN_CLR            (MT6355_PMIC_REG_BASE + 0x10D4)
#define PMIC_BUCK_VDRAM2_OP_CFG               (MT6355_PMIC_REG_BASE + 0x10D6)
#define PMIC_BUCK_VDRAM2_OP_CFG_SET           (MT6355_PMIC_REG_BASE + 0x10D8)
#define PMIC_BUCK_VDRAM2_OP_CFG_CLR           (MT6355_PMIC_REG_BASE + 0x10DA)
#define PMIC_BUCK_VDRAM2_SP_CON               (MT6355_PMIC_REG_BASE + 0x10DC)
#define PMIC_BUCK_VDRAM2_SP_CFG               (MT6355_PMIC_REG_BASE + 0x10DE)
#define PMIC_BUCK_VDRAM2_OC_CFG               (MT6355_PMIC_REG_BASE + 0x10E0)
#define PMIC_BUCK_VDRAM2_DBG0                 (MT6355_PMIC_REG_BASE + 0x10E2)
#define PMIC_BUCK_VDRAM2_DBG1                 (MT6355_PMIC_REG_BASE + 0x10E4)
#define PMIC_BUCK_VDRAM2_DBG2                 (MT6355_PMIC_REG_BASE + 0x10E6)
#define PMIC_BUCK_VMODEM_CON0                 (MT6355_PMIC_REG_BASE + 0x10E8)
#define PMIC_BUCK_VMODEM_CON1                 (MT6355_PMIC_REG_BASE + 0x10EA)
#define PMIC_BUCK_VMODEM_CON2                 (MT6355_PMIC_REG_BASE + 0x10EC)
#define PMIC_BUCK_VMODEM_CFG0                 (MT6355_PMIC_REG_BASE + 0x10EE)
#define PMIC_BUCK_VMODEM_CFG1                 (MT6355_PMIC_REG_BASE + 0x10F0)
#define PMIC_BUCK_VMODEM_OP_EN                (MT6355_PMIC_REG_BASE + 0x10F2)
#define PMIC_BUCK_VMODEM_OP_EN_SET            (MT6355_PMIC_REG_BASE + 0x10F4)
#define PMIC_BUCK_VMODEM_OP_EN_CLR            (MT6355_PMIC_REG_BASE + 0x10F6)
#define PMIC_BUCK_VMODEM_OP_CFG               (MT6355_PMIC_REG_BASE + 0x10F8)
#define PMIC_BUCK_VMODEM_OP_CFG_SET           (MT6355_PMIC_REG_BASE + 0x10FA)
#define PMIC_BUCK_VMODEM_OP_CFG_CLR           (MT6355_PMIC_REG_BASE + 0x10FC)
#define PMIC_BUCK_VMODEM_SP_CON               (MT6355_PMIC_REG_BASE + 0x10FE)
#define PMIC_BUCK_VMODEM_SP_CFG               (MT6355_PMIC_REG_BASE + 0x1100)
#define PMIC_BUCK_VMODEM_OC_CFG               (MT6355_PMIC_REG_BASE + 0x1102)
#define PMIC_BUCK_VMODEM_DBG0                 (MT6355_PMIC_REG_BASE + 0x1104)
#define PMIC_BUCK_VMODEM_DBG1                 (MT6355_PMIC_REG_BASE + 0x1106)
#define PMIC_BUCK_VMODEM_DBG2                 (MT6355_PMIC_REG_BASE + 0x1108)
#define PMIC_BUCK_VMODEM_DLC_CON0             (MT6355_PMIC_REG_BASE + 0x110A)
#define PMIC_BUCK_VMODEM_DLC_CON1             (MT6355_PMIC_REG_BASE + 0x110C)
#define PMIC_BUCK_VMODEM_DLC_CON2             (MT6355_PMIC_REG_BASE + 0x110E)
#define PMIC_BUCK_VMODEM_DLC_CON3             (MT6355_PMIC_REG_BASE + 0x1110)
#define PMIC_BUCK_VS1_CON0                    (MT6355_PMIC_REG_BASE + 0x1112)
#define PMIC_BUCK_VS1_CON1                    (MT6355_PMIC_REG_BASE + 0x1114)
#define PMIC_BUCK_VS1_CON2                    (MT6355_PMIC_REG_BASE + 0x1116)
#define PMIC_BUCK_VS1_CFG0                    (MT6355_PMIC_REG_BASE + 0x1118)
#define PMIC_BUCK_VS1_CFG1                    (MT6355_PMIC_REG_BASE + 0x111A)
#define PMIC_BUCK_VS1_OP_EN                   (MT6355_PMIC_REG_BASE + 0x111C)
#define PMIC_BUCK_VS1_OP_EN_SET               (MT6355_PMIC_REG_BASE + 0x111E)
#define PMIC_BUCK_VS1_OP_EN_CLR               (MT6355_PMIC_REG_BASE + 0x1120)
#define PMIC_BUCK_VS1_OP_CFG                  (MT6355_PMIC_REG_BASE + 0x1122)
#define PMIC_BUCK_VS1_OP_CFG_SET              (MT6355_PMIC_REG_BASE + 0x1124)
#define PMIC_BUCK_VS1_OP_CFG_CLR              (MT6355_PMIC_REG_BASE + 0x1126)
#define PMIC_BUCK_VS1_SP_CON                  (MT6355_PMIC_REG_BASE + 0x1128)
#define PMIC_BUCK_VS1_SP_CFG                  (MT6355_PMIC_REG_BASE + 0x112A)
#define PMIC_BUCK_VS1_OC_CFG                  (MT6355_PMIC_REG_BASE + 0x112C)
#define PMIC_BUCK_VS1_DBG0                    (MT6355_PMIC_REG_BASE + 0x112E)
#define PMIC_BUCK_VS1_DBG1                    (MT6355_PMIC_REG_BASE + 0x1130)
#define PMIC_BUCK_VS1_DBG2                    (MT6355_PMIC_REG_BASE + 0x1132)
#define PMIC_BUCK_VS1_VOTER                   (MT6355_PMIC_REG_BASE + 0x1134)
#define PMIC_BUCK_VS1_VOTER_SET               (MT6355_PMIC_REG_BASE + 0x1136)
#define PMIC_BUCK_VS1_VOTER_CLR               (MT6355_PMIC_REG_BASE + 0x1138)
#define PMIC_BUCK_VS1_VOTER_CFG               (MT6355_PMIC_REG_BASE + 0x113A)
#define PMIC_BUCK_VS2_CON0                    (MT6355_PMIC_REG_BASE + 0x113C)
#define PMIC_BUCK_VS2_CON1                    (MT6355_PMIC_REG_BASE + 0x113E)
#define PMIC_BUCK_VS2_CON2                    (MT6355_PMIC_REG_BASE + 0x1140)
#define PMIC_BUCK_VS2_CFG0                    (MT6355_PMIC_REG_BASE + 0x1142)
#define PMIC_BUCK_VS2_CFG1                    (MT6355_PMIC_REG_BASE + 0x1144)
#define PMIC_BUCK_VS2_OP_EN                   (MT6355_PMIC_REG_BASE + 0x1146)
#define PMIC_BUCK_VS2_OP_EN_SET               (MT6355_PMIC_REG_BASE + 0x1148)
#define PMIC_BUCK_VS2_OP_EN_CLR               (MT6355_PMIC_REG_BASE + 0x114A)
#define PMIC_BUCK_VS2_OP_CFG                  (MT6355_PMIC_REG_BASE + 0x114C)
#define PMIC_BUCK_VS2_OP_CFG_SET              (MT6355_PMIC_REG_BASE + 0x114E)
#define PMIC_BUCK_VS2_OP_CFG_CLR              (MT6355_PMIC_REG_BASE + 0x1150)
#define PMIC_BUCK_VS2_SP_CON                  (MT6355_PMIC_REG_BASE + 0x1152)
#define PMIC_BUCK_VS2_SP_CFG                  (MT6355_PMIC_REG_BASE + 0x1154)
#define PMIC_BUCK_VS2_OC_CFG                  (MT6355_PMIC_REG_BASE + 0x1156)
#define PMIC_BUCK_VS2_DBG0                    (MT6355_PMIC_REG_BASE + 0x1158)
#define PMIC_BUCK_VS2_DBG1                    (MT6355_PMIC_REG_BASE + 0x115A)
#define PMIC_BUCK_VS2_DBG2                    (MT6355_PMIC_REG_BASE + 0x115C)
#define PMIC_BUCK_VS2_VOTER                   (MT6355_PMIC_REG_BASE + 0x115E)
#define PMIC_BUCK_VS2_VOTER_SET               (MT6355_PMIC_REG_BASE + 0x1160)
#define PMIC_BUCK_VS2_VOTER_CLR               (MT6355_PMIC_REG_BASE + 0x1162)
#define PMIC_BUCK_VS2_VOTER_CFG               (MT6355_PMIC_REG_BASE + 0x1164)
#define PMIC_BUCK_VPA_CON0                    (MT6355_PMIC_REG_BASE + 0x1166)
#define PMIC_BUCK_VPA_CON1                    (MT6355_PMIC_REG_BASE + 0x1168)
#define PMIC_BUCK_VPA_CFG0                    (MT6355_PMIC_REG_BASE + 0x116A)
#define PMIC_BUCK_VPA_CFG1                    (MT6355_PMIC_REG_BASE + 0x116C)
#define PMIC_BUCK_VPA_OC_CFG                  (MT6355_PMIC_REG_BASE + 0x116E)
#define PMIC_BUCK_VPA_DBG0                    (MT6355_PMIC_REG_BASE + 0x1170)
#define PMIC_BUCK_VPA_DBG1                    (MT6355_PMIC_REG_BASE + 0x1172)
#define PMIC_BUCK_VPA_DBG2                    (MT6355_PMIC_REG_BASE + 0x1174)
#define PMIC_BUCK_VPA_DLC_CON0                (MT6355_PMIC_REG_BASE + 0x1176)
#define PMIC_BUCK_VPA_DLC_CON1                (MT6355_PMIC_REG_BASE + 0x1178)
#define PMIC_BUCK_VPA_DLC_CON2                (MT6355_PMIC_REG_BASE + 0x117A)
#define PMIC_BUCK_VPA_MSFG_CON0               (MT6355_PMIC_REG_BASE + 0x117C)
#define PMIC_BUCK_VPA_MSFG_CON1               (MT6355_PMIC_REG_BASE + 0x117E)
#define PMIC_BUCK_VPA_MSFG_RRATE0             (MT6355_PMIC_REG_BASE + 0x1180)
#define PMIC_BUCK_VPA_MSFG_RRATE1             (MT6355_PMIC_REG_BASE + 0x1182)
#define PMIC_BUCK_VPA_MSFG_RRATE2             (MT6355_PMIC_REG_BASE + 0x1184)
#define PMIC_BUCK_VPA_MSFG_RTHD0              (MT6355_PMIC_REG_BASE + 0x1186)
#define PMIC_BUCK_VPA_MSFG_RTHD1              (MT6355_PMIC_REG_BASE + 0x1188)
#define PMIC_BUCK_VPA_MSFG_RTHD2              (MT6355_PMIC_REG_BASE + 0x118A)
#define PMIC_BUCK_VPA_MSFG_FRATE0             (MT6355_PMIC_REG_BASE + 0x118C)
#define PMIC_BUCK_VPA_MSFG_FRATE1             (MT6355_PMIC_REG_BASE + 0x118E)
#define PMIC_BUCK_VPA_MSFG_FRATE2             (MT6355_PMIC_REG_BASE + 0x1190)
#define PMIC_BUCK_VPA_MSFG_FTHD0              (MT6355_PMIC_REG_BASE + 0x1192)
#define PMIC_BUCK_VPA_MSFG_FTHD1              (MT6355_PMIC_REG_BASE + 0x1194)
#define PMIC_BUCK_VPA_MSFG_FTHD2              (MT6355_PMIC_REG_BASE + 0x1196)
#define PMIC_SMPS_ANA_CON0                    (MT6355_PMIC_REG_BASE + 0x1200)
#define PMIC_SMPS_ANA_CON1                    (MT6355_PMIC_REG_BASE + 0x1202)
#define PMIC_SMPS_ANA_CON2                    (MT6355_PMIC_REG_BASE + 0x1204)
#define PMIC_SMPS_ANA_CON3                    (MT6355_PMIC_REG_BASE + 0x1206)
#define PMIC_SMPS_ANA_CON4                    (MT6355_PMIC_REG_BASE + 0x1208)
#define PMIC_SMPS_ANA_CON5                    (MT6355_PMIC_REG_BASE + 0x120A)
#define PMIC_SMPS_ANA_CON6                    (MT6355_PMIC_REG_BASE + 0x120C)
#define PMIC_SMPS_ANA_CON7                    (MT6355_PMIC_REG_BASE + 0x120E)
#define PMIC_SMPS_ANA_CON8                    (MT6355_PMIC_REG_BASE + 0x1210)
#define PMIC_SMPS_ANA_CON9                    (MT6355_PMIC_REG_BASE + 0x1212)
#define PMIC_SMPS_ANA_CON10                   (MT6355_PMIC_REG_BASE + 0x1214)
#define PMIC_SMPS_ANA_CON11                   (MT6355_PMIC_REG_BASE + 0x1216)
#define PMIC_SMPS_ANA_CON12                   (MT6355_PMIC_REG_BASE + 0x1218)
#define PMIC_SMPS_ANA_CON13                   (MT6355_PMIC_REG_BASE + 0x121A)
#define PMIC_SMPS_ANA_CON14                   (MT6355_PMIC_REG_BASE + 0x121C)
#define PMIC_SMPS_ANA_CON15                   (MT6355_PMIC_REG_BASE + 0x121E)
#define PMIC_VPROC_ANA_CON0                   (MT6355_PMIC_REG_BASE + 0x1220)
#define PMIC_VPROC_ANA_CON1                   (MT6355_PMIC_REG_BASE + 0x1222)
#define PMIC_VPROC_ANA_CON2                   (MT6355_PMIC_REG_BASE + 0x1224)
#define PMIC_VPROC_ANA_CON3                   (MT6355_PMIC_REG_BASE + 0x1226)
#define PMIC_VPROC_ANA_CON4                   (MT6355_PMIC_REG_BASE + 0x1228)
#define PMIC_VPROC_ANA_CON5                   (MT6355_PMIC_REG_BASE + 0x122A)
#define PMIC_VPROC_ANA_CON6                   (MT6355_PMIC_REG_BASE + 0x122C)
#define PMIC_VPROC_ANA_CON7                   (MT6355_PMIC_REG_BASE + 0x122E)
#define PMIC_VPROC_ANA_CON8                   (MT6355_PMIC_REG_BASE + 0x1230)
#define PMIC_VPROC_ANA_CON9                   (MT6355_PMIC_REG_BASE + 0x1232)
#define PMIC_VPROC_ANA_CON10                  (MT6355_PMIC_REG_BASE + 0x1234)
#define PMIC_VPROC_ANA_CON11                  (MT6355_PMIC_REG_BASE + 0x1236)
#define PMIC_VPROC_ANA_CON12                  (MT6355_PMIC_REG_BASE + 0x1238)
#define PMIC_VPROC_ANA_CON13                  (MT6355_PMIC_REG_BASE + 0x123A)
#define PMIC_VPROC_ANA_CON14                  (MT6355_PMIC_REG_BASE + 0x123C)
#define PMIC_VPROC_ANA_CON15                  (MT6355_PMIC_REG_BASE + 0x123E)
#define PMIC_VPROC_ANA_CON16                  (MT6355_PMIC_REG_BASE + 0x1240)
#define PMIC_VCORE_VGPU_ANA_CON0              (MT6355_PMIC_REG_BASE + 0x1242)
#define PMIC_VCORE_VGPU_ANA_CON1              (MT6355_PMIC_REG_BASE + 0x1244)
#define PMIC_VCORE_VGPU_ANA_CON2              (MT6355_PMIC_REG_BASE + 0x1246)
#define PMIC_VCORE_VGPU_ANA_CON3              (MT6355_PMIC_REG_BASE + 0x1248)
#define PMIC_VCORE_VGPU_ANA_CON4              (MT6355_PMIC_REG_BASE + 0x124A)
#define PMIC_VCORE_VGPU_ANA_CON5              (MT6355_PMIC_REG_BASE + 0x124C)
#define PMIC_VCORE_VGPU_ANA_CON6              (MT6355_PMIC_REG_BASE + 0x124E)
#define PMIC_VCORE_VGPU_ANA_CON7              (MT6355_PMIC_REG_BASE + 0x1250)
#define PMIC_VCORE_VGPU_ANA_CON8              (MT6355_PMIC_REG_BASE + 0x1252)
#define PMIC_VCORE_VGPU_ANA_CON9              (MT6355_PMIC_REG_BASE + 0x1254)
#define PMIC_VCORE_VGPU_ANA_CON10             (MT6355_PMIC_REG_BASE + 0x1256)
#define PMIC_VCORE_VGPU_ANA_CON11             (MT6355_PMIC_REG_BASE + 0x1258)
#define PMIC_VCORE_VGPU_ANA_CON12             (MT6355_PMIC_REG_BASE + 0x125A)
#define PMIC_VCORE_VGPU_ANA_CON13             (MT6355_PMIC_REG_BASE + 0x125C)
#define PMIC_VCORE_VGPU_ANA_CON14             (MT6355_PMIC_REG_BASE + 0x125E)
#define PMIC_VCORE_VGPU_ANA_CON15             (MT6355_PMIC_REG_BASE + 0x1260)
#define PMIC_VCORE_VGPU_ANA_CON16             (MT6355_PMIC_REG_BASE + 0x1262)
#define PMIC_VDRAM1_ANA_CON0                  (MT6355_PMIC_REG_BASE + 0x1264)
#define PMIC_VDRAM1_ANA_CON1                  (MT6355_PMIC_REG_BASE + 0x1266)
#define PMIC_VDRAM1_ANA_CON2                  (MT6355_PMIC_REG_BASE + 0x1268)
#define PMIC_VDRAM1_ANA_CON3                  (MT6355_PMIC_REG_BASE + 0x126A)
#define PMIC_VDRAM1_ANA_CON4                  (MT6355_PMIC_REG_BASE + 0x126C)
#define PMIC_VDRAM1_ANA_CON5                  (MT6355_PMIC_REG_BASE + 0x126E)
#define PMIC_VDRAM1_ANA_CON6                  (MT6355_PMIC_REG_BASE + 0x1270)
#define PMIC_VDRAM1_ANA_CON7                  (MT6355_PMIC_REG_BASE + 0x1272)
#define PMIC_VDRAM2_ANA_CON0                  (MT6355_PMIC_REG_BASE + 0x1274)
#define PMIC_VDRAM2_ANA_CON1                  (MT6355_PMIC_REG_BASE + 0x1276)
#define PMIC_VDRAM2_ANA_CON2                  (MT6355_PMIC_REG_BASE + 0x1278)
#define PMIC_VDRAM2_ANA_CON3                  (MT6355_PMIC_REG_BASE + 0x127A)
#define PMIC_VDRAM2_ANA_CON4                  (MT6355_PMIC_REG_BASE + 0x127C)
#define PMIC_VDRAM2_ANA_CON5                  (MT6355_PMIC_REG_BASE + 0x127E)
#define PMIC_VDRAM2_ANA_CON6                  (MT6355_PMIC_REG_BASE + 0x1280)
#define PMIC_VDRAM2_ANA_CON7                  (MT6355_PMIC_REG_BASE + 0x1282)
#define PMIC_VMODEM_ANA_CON0                  (MT6355_PMIC_REG_BASE + 0x1284)
#define PMIC_VMODEM_ANA_CON1                  (MT6355_PMIC_REG_BASE + 0x1286)
#define PMIC_VMODEM_ANA_CON2                  (MT6355_PMIC_REG_BASE + 0x1288)
#define PMIC_VMODEM_ANA_CON3                  (MT6355_PMIC_REG_BASE + 0x128A)
#define PMIC_VMODEM_ANA_CON4                  (MT6355_PMIC_REG_BASE + 0x128C)
#define PMIC_VMODEM_ANA_CON5                  (MT6355_PMIC_REG_BASE + 0x128E)
#define PMIC_VMODEM_ANA_CON6                  (MT6355_PMIC_REG_BASE + 0x1290)
#define PMIC_VMODEM_ANA_CON7                  (MT6355_PMIC_REG_BASE + 0x1292)
#define PMIC_VMODEM_ANA_CON8                  (MT6355_PMIC_REG_BASE + 0x1294)
#define PMIC_VMODEM_ANA_CON9                  (MT6355_PMIC_REG_BASE + 0x1296)
#define PMIC_VS1_ANA_CON0                     (MT6355_PMIC_REG_BASE + 0x1298)
#define PMIC_VS1_ANA_CON1                     (MT6355_PMIC_REG_BASE + 0x129A)
#define PMIC_VS1_ANA_CON2                     (MT6355_PMIC_REG_BASE + 0x129C)
#define PMIC_VS1_ANA_CON3                     (MT6355_PMIC_REG_BASE + 0x129E)
#define PMIC_VS1_ANA_CON4                     (MT6355_PMIC_REG_BASE + 0x12A0)
#define PMIC_VS1_ANA_CON5                     (MT6355_PMIC_REG_BASE + 0x12A2)
#define PMIC_VS1_ANA_CON6                     (MT6355_PMIC_REG_BASE + 0x12A4)
#define PMIC_VS2_ANA_CON0                     (MT6355_PMIC_REG_BASE + 0x12A6)
#define PMIC_VS2_ANA_CON1                     (MT6355_PMIC_REG_BASE + 0x12A8)
#define PMIC_VS2_ANA_CON2                     (MT6355_PMIC_REG_BASE + 0x12AA)
#define PMIC_VS2_ANA_CON3                     (MT6355_PMIC_REG_BASE + 0x12AC)
#define PMIC_VS2_ANA_CON4                     (MT6355_PMIC_REG_BASE + 0x12AE)
#define PMIC_VS2_ANA_CON5                     (MT6355_PMIC_REG_BASE + 0x12B0)
#define PMIC_VS2_ANA_CON6                     (MT6355_PMIC_REG_BASE + 0x12B2)
#define PMIC_VPA_ANA_CON0                     (MT6355_PMIC_REG_BASE + 0x12B4)
#define PMIC_VPA_ANA_CON1                     (MT6355_PMIC_REG_BASE + 0x12B6)
#define PMIC_VPA_ANA_CON2                     (MT6355_PMIC_REG_BASE + 0x12B8)
#define PMIC_VPA_ANA_CON3                     (MT6355_PMIC_REG_BASE + 0x12BA)
#define PMIC_VPA_ANA_CON4                     (MT6355_PMIC_REG_BASE + 0x12BC)
#define PMIC_VPA_ANA_CON5                     (MT6355_PMIC_REG_BASE + 0x12BE)
#define PMIC_WDTDBG_CON0                      (MT6355_PMIC_REG_BASE + 0x1400)
#define PMIC_WDTDBG_MON0                      (MT6355_PMIC_REG_BASE + 0x1402)
#define PMIC_WDTDBG_MON1                      (MT6355_PMIC_REG_BASE + 0x1404)
#define PMIC_WDTDBG_MON2                      (MT6355_PMIC_REG_BASE + 0x1406)
#define PMIC_WDTDBG_MON3                      (MT6355_PMIC_REG_BASE + 0x1408)
#define PMIC_WDTDBG_MON4                      (MT6355_PMIC_REG_BASE + 0x140A)
#define PMIC_WDTDBG_MON5                      (MT6355_PMIC_REG_BASE + 0x140C)
#define PMIC_WDTDBG_MON6                      (MT6355_PMIC_REG_BASE + 0x140E)
#define PMIC_LDO_VIO28_CON0                   (MT6355_PMIC_REG_BASE + 0x1600)
#define PMIC_LDO_VIO28_OP_EN                  (MT6355_PMIC_REG_BASE + 0x1602)
#define PMIC_LDO_VIO28_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x1604)
#define PMIC_LDO_VIO28_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x1606)
#define PMIC_LDO_VIO28_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x1608)
#define PMIC_LDO_VIO28_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x160A)
#define PMIC_LDO_VIO28_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x160C)
#define PMIC_LDO_VIO28_CON1                   (MT6355_PMIC_REG_BASE + 0x160E)
#define PMIC_LDO_VIO28_CON2                   (MT6355_PMIC_REG_BASE + 0x1610)
#define PMIC_LDO_VIO28_CON3                   (MT6355_PMIC_REG_BASE + 0x1612)
#define PMIC_LDO_VIO18_CON0                   (MT6355_PMIC_REG_BASE + 0x1614)
#define PMIC_LDO_VIO18_OP_EN                  (MT6355_PMIC_REG_BASE + 0x1616)
#define PMIC_LDO_VIO18_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x1618)
#define PMIC_LDO_VIO18_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x161A)
#define PMIC_LDO_VIO18_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x161C)
#define PMIC_LDO_VIO18_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x161E)
#define PMIC_LDO_VIO18_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x1620)
#define PMIC_LDO_VIO18_CON1                   (MT6355_PMIC_REG_BASE + 0x1622)
#define PMIC_LDO_VIO18_CON2                   (MT6355_PMIC_REG_BASE + 0x1624)
#define PMIC_LDO_VIO18_CON3                   (MT6355_PMIC_REG_BASE + 0x1626)
#define PMIC_LDO_VUFS18_CON0                  (MT6355_PMIC_REG_BASE + 0x1628)
#define PMIC_LDO_VUFS18_OP_EN                 (MT6355_PMIC_REG_BASE + 0x162A)
#define PMIC_LDO_VUFS18_OP_EN_SET             (MT6355_PMIC_REG_BASE + 0x162C)
#define PMIC_LDO_VUFS18_OP_EN_CLR             (MT6355_PMIC_REG_BASE + 0x162E)
#define PMIC_LDO_VUFS18_OP_CFG                (MT6355_PMIC_REG_BASE + 0x1630)
#define PMIC_LDO_VUFS18_OP_CFG_SET            (MT6355_PMIC_REG_BASE + 0x1632)
#define PMIC_LDO_VUFS18_OP_CFG_CLR            (MT6355_PMIC_REG_BASE + 0x1634)
#define PMIC_LDO_VUFS18_CON1                  (MT6355_PMIC_REG_BASE + 0x1636)
#define PMIC_LDO_VUFS18_CON2                  (MT6355_PMIC_REG_BASE + 0x1638)
#define PMIC_LDO_VUFS18_CON3                  (MT6355_PMIC_REG_BASE + 0x163A)
#define PMIC_LDO_VA10_CON0                    (MT6355_PMIC_REG_BASE + 0x163C)
#define PMIC_LDO_VA10_CON1                    (MT6355_PMIC_REG_BASE + 0x163E)
#define PMIC_LDO_VA10_OP_EN                   (MT6355_PMIC_REG_BASE + 0x1640)
#define PMIC_LDO_VA10_OP_EN_SET               (MT6355_PMIC_REG_BASE + 0x1642)
#define PMIC_LDO_VA10_OP_EN_CLR               (MT6355_PMIC_REG_BASE + 0x1644)
#define PMIC_LDO_VA10_OP_CFG                  (MT6355_PMIC_REG_BASE + 0x1646)
#define PMIC_LDO_VA10_OP_CFG_SET              (MT6355_PMIC_REG_BASE + 0x1648)
#define PMIC_LDO_VA10_OP_CFG_CLR              (MT6355_PMIC_REG_BASE + 0x164A)
#define PMIC_LDO_VA10_CON2                    (MT6355_PMIC_REG_BASE + 0x164C)
#define PMIC_LDO_VA10_CON3                    (MT6355_PMIC_REG_BASE + 0x164E)
#define PMIC_LDO_VA10_CON4                    (MT6355_PMIC_REG_BASE + 0x1650)
#define PMIC_LDO_VA12_CON0                    (MT6355_PMIC_REG_BASE + 0x1652)
#define PMIC_LDO_VA12_OP_EN                   (MT6355_PMIC_REG_BASE + 0x1654)
#define PMIC_LDO_VA12_OP_EN_SET               (MT6355_PMIC_REG_BASE + 0x1656)
#define PMIC_LDO_VA12_OP_EN_CLR               (MT6355_PMIC_REG_BASE + 0x1658)
#define PMIC_LDO_VA12_OP_CFG                  (MT6355_PMIC_REG_BASE + 0x165A)
#define PMIC_LDO_VA12_OP_CFG_SET              (MT6355_PMIC_REG_BASE + 0x165C)
#define PMIC_LDO_VA12_OP_CFG_CLR              (MT6355_PMIC_REG_BASE + 0x165E)
#define PMIC_LDO_VA12_CON1                    (MT6355_PMIC_REG_BASE + 0x1660)
#define PMIC_LDO_VA12_CON2                    (MT6355_PMIC_REG_BASE + 0x1662)
#define PMIC_LDO_VA12_CON3                    (MT6355_PMIC_REG_BASE + 0x1664)
#define PMIC_LDO_VA18_CON0                    (MT6355_PMIC_REG_BASE + 0x1666)
#define PMIC_LDO_VA18_OP_EN                   (MT6355_PMIC_REG_BASE + 0x1668)
#define PMIC_LDO_VA18_OP_EN_SET               (MT6355_PMIC_REG_BASE + 0x166A)
#define PMIC_LDO_VA18_OP_EN_CLR               (MT6355_PMIC_REG_BASE + 0x166C)
#define PMIC_LDO_VA18_OP_CFG                  (MT6355_PMIC_REG_BASE + 0x166E)
#define PMIC_LDO_VA18_OP_CFG_SET              (MT6355_PMIC_REG_BASE + 0x1670)
#define PMIC_LDO_VA18_OP_CFG_CLR              (MT6355_PMIC_REG_BASE + 0x1672)
#define PMIC_LDO_VA18_CON1                    (MT6355_PMIC_REG_BASE + 0x1674)
#define PMIC_LDO_VA18_CON2                    (MT6355_PMIC_REG_BASE + 0x1676)
#define PMIC_LDO_VA18_CON3                    (MT6355_PMIC_REG_BASE + 0x1678)
#define PMIC_LDO_VUSB33_CON0_0                (MT6355_PMIC_REG_BASE + 0x167A)
#define PMIC_LDO_VUSB33_OP_EN                 (MT6355_PMIC_REG_BASE + 0x167C)
#define PMIC_LDO_VUSB33_OP_EN_SET             (MT6355_PMIC_REG_BASE + 0x167E)
#define PMIC_LDO_VUSB33_OP_EN_CLR             (MT6355_PMIC_REG_BASE + 0x1680)
#define PMIC_LDO_VUSB33_OP_CFG                (MT6355_PMIC_REG_BASE + 0x1682)
#define PMIC_LDO_VUSB33_OP_CFG_SET            (MT6355_PMIC_REG_BASE + 0x1684)
#define PMIC_LDO_VUSB33_OP_CFG_CLR            (MT6355_PMIC_REG_BASE + 0x1686)
#define PMIC_LDO_VUSB33_CON0_1                (MT6355_PMIC_REG_BASE + 0x1688)
#define PMIC_LDO_VUSB33_CON1                  (MT6355_PMIC_REG_BASE + 0x168A)
#define PMIC_LDO_VUSB33_CON2                  (MT6355_PMIC_REG_BASE + 0x168C)
#define PMIC_LDO_VUSB33_CON3                  (MT6355_PMIC_REG_BASE + 0x168E)
#define PMIC_LDO_VEMC_CON0                    (MT6355_PMIC_REG_BASE + 0x1690)
#define PMIC_LDO_VEMC_OP_EN                   (MT6355_PMIC_REG_BASE + 0x1692)
#define PMIC_LDO_VEMC_OP_EN_SET               (MT6355_PMIC_REG_BASE + 0x1694)
#define PMIC_LDO_VEMC_OP_EN_CLR               (MT6355_PMIC_REG_BASE + 0x1696)
#define PMIC_LDO_VEMC_OP_CFG                  (MT6355_PMIC_REG_BASE + 0x1698)
#define PMIC_LDO_VEMC_OP_CFG_SET              (MT6355_PMIC_REG_BASE + 0x169A)
#define PMIC_LDO_VEMC_OP_CFG_CLR              (MT6355_PMIC_REG_BASE + 0x169C)
#define PMIC_LDO_VEMC_CON1                    (MT6355_PMIC_REG_BASE + 0x169E)
#define PMIC_LDO_VEMC_CON2                    (MT6355_PMIC_REG_BASE + 0x16A0)
#define PMIC_LDO_VEMC_CON3                    (MT6355_PMIC_REG_BASE + 0x16A2)
#define PMIC_LDO_VXO22_CON0                   (MT6355_PMIC_REG_BASE + 0x16A4)
#define PMIC_LDO_VXO22_OP_EN                  (MT6355_PMIC_REG_BASE + 0x16A6)
#define PMIC_LDO_VXO22_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x16A8)
#define PMIC_LDO_VXO22_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x16AA)
#define PMIC_LDO_VXO22_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x16AC)
#define PMIC_LDO_VXO22_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x16AE)
#define PMIC_LDO_VXO22_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x16B0)
#define PMIC_LDO_VXO22_CON1                   (MT6355_PMIC_REG_BASE + 0x16B2)
#define PMIC_LDO_VXO22_CON2                   (MT6355_PMIC_REG_BASE + 0x16B4)
#define PMIC_LDO_VXO22_CON3                   (MT6355_PMIC_REG_BASE + 0x16B6)
#define PMIC_LDO_VXO18_CON0                   (MT6355_PMIC_REG_BASE + 0x16B8)
#define PMIC_LDO_VXO18_OP_EN                  (MT6355_PMIC_REG_BASE + 0x16BA)
#define PMIC_LDO_VXO18_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x16BC)
#define PMIC_LDO_VXO18_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x16BE)
#define PMIC_LDO_VXO18_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x16C0)
#define PMIC_LDO_VXO18_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x16C2)
#define PMIC_LDO_VXO18_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x16C4)
#define PMIC_LDO_VXO18_CON1                   (MT6355_PMIC_REG_BASE + 0x16C6)
#define PMIC_LDO_VXO18_CON2                   (MT6355_PMIC_REG_BASE + 0x16C8)
#define PMIC_LDO_VXO18_CON3                   (MT6355_PMIC_REG_BASE + 0x16CA)
#define PMIC_LDO_VSIM1_CON0                   (MT6355_PMIC_REG_BASE + 0x16CC)
#define PMIC_LDO_VSIM1_OP_EN                  (MT6355_PMIC_REG_BASE + 0x16CE)
#define PMIC_LDO_VSIM1_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x16D0)
#define PMIC_LDO_VSIM1_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x16D2)
#define PMIC_LDO_VSIM1_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x16D4)
#define PMIC_LDO_VSIM1_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x16D6)
#define PMIC_LDO_VSIM1_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x16D8)
#define PMIC_LDO_VSIM1_CON1                   (MT6355_PMIC_REG_BASE + 0x16DA)
#define PMIC_LDO_VSIM1_CON2                   (MT6355_PMIC_REG_BASE + 0x16DC)
#define PMIC_LDO_VSIM1_CON3                   (MT6355_PMIC_REG_BASE + 0x16DE)
#define PMIC_LDO_VSIM2_CON0                   (MT6355_PMIC_REG_BASE + 0x16E0)
#define PMIC_LDO_VSIM2_OP_EN                  (MT6355_PMIC_REG_BASE + 0x16E2)
#define PMIC_LDO_VSIM2_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x16E4)
#define PMIC_LDO_VSIM2_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x16E6)
#define PMIC_LDO_VSIM2_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x16E8)
#define PMIC_LDO_VSIM2_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x16EA)
#define PMIC_LDO_VSIM2_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x16EC)
#define PMIC_LDO_VSIM2_CON1                   (MT6355_PMIC_REG_BASE + 0x16EE)
#define PMIC_LDO_VSIM2_CON2                   (MT6355_PMIC_REG_BASE + 0x16F0)
#define PMIC_LDO_VSIM2_CON3                   (MT6355_PMIC_REG_BASE + 0x16F2)
#define PMIC_LDO_VCAMD1_CON0                  (MT6355_PMIC_REG_BASE + 0x16F4)
#define PMIC_LDO_VCAMD1_OP_EN                 (MT6355_PMIC_REG_BASE + 0x16F6)
#define PMIC_LDO_VCAMD1_OP_EN_SET             (MT6355_PMIC_REG_BASE + 0x16F8)
#define PMIC_LDO_VCAMD1_OP_EN_CLR             (MT6355_PMIC_REG_BASE + 0x16FA)
#define PMIC_LDO_VCAMD1_OP_CFG                (MT6355_PMIC_REG_BASE + 0x16FC)
#define PMIC_LDO_VCAMD1_OP_CFG_SET            (MT6355_PMIC_REG_BASE + 0x16FE)
#define PMIC_LDO_VCAMD1_OP_CFG_CLR            (MT6355_PMIC_REG_BASE + 0x1700)
#define PMIC_LDO_VCAMD1_CON1                  (MT6355_PMIC_REG_BASE + 0x1702)
#define PMIC_LDO_VCAMD1_CON2                  (MT6355_PMIC_REG_BASE + 0x1704)
#define PMIC_LDO_VCAMD1_CON3                  (MT6355_PMIC_REG_BASE + 0x1706)
#define PMIC_LDO_VCAMD2_CON0                  (MT6355_PMIC_REG_BASE + 0x1708)
#define PMIC_LDO_VCAMD2_OP_EN                 (MT6355_PMIC_REG_BASE + 0x170A)
#define PMIC_LDO_VCAMD2_OP_EN_SET             (MT6355_PMIC_REG_BASE + 0x170C)
#define PMIC_LDO_VCAMD2_OP_EN_CLR             (MT6355_PMIC_REG_BASE + 0x170E)
#define PMIC_LDO_VCAMD2_OP_CFG                (MT6355_PMIC_REG_BASE + 0x1710)
#define PMIC_LDO_VCAMD2_OP_CFG_SET            (MT6355_PMIC_REG_BASE + 0x1712)
#define PMIC_LDO_VCAMD2_OP_CFG_CLR            (MT6355_PMIC_REG_BASE + 0x1714)
#define PMIC_LDO_VCAMD2_CON1                  (MT6355_PMIC_REG_BASE + 0x1716)
#define PMIC_LDO_VCAMD2_CON2                  (MT6355_PMIC_REG_BASE + 0x1718)
#define PMIC_LDO_VCAMD2_CON3                  (MT6355_PMIC_REG_BASE + 0x171A)
#define PMIC_LDO_VCAMIO_CON0                  (MT6355_PMIC_REG_BASE + 0x171C)
#define PMIC_LDO_VCAMIO_OP_EN                 (MT6355_PMIC_REG_BASE + 0x171E)
#define PMIC_LDO_VCAMIO_OP_EN_SET             (MT6355_PMIC_REG_BASE + 0x1720)
#define PMIC_LDO_VCAMIO_OP_EN_CLR             (MT6355_PMIC_REG_BASE + 0x1722)
#define PMIC_LDO_VCAMIO_OP_CFG                (MT6355_PMIC_REG_BASE + 0x1724)
#define PMIC_LDO_VCAMIO_OP_CFG_SET            (MT6355_PMIC_REG_BASE + 0x1726)
#define PMIC_LDO_VCAMIO_OP_CFG_CLR            (MT6355_PMIC_REG_BASE + 0x1728)
#define PMIC_LDO_VCAMIO_CON1                  (MT6355_PMIC_REG_BASE + 0x172A)
#define PMIC_LDO_VCAMIO_CON2                  (MT6355_PMIC_REG_BASE + 0x172C)
#define PMIC_LDO_VCAMIO_CON3                  (MT6355_PMIC_REG_BASE + 0x172E)
#define PMIC_LDO_VMIPI_CON0                   (MT6355_PMIC_REG_BASE + 0x1730)
#define PMIC_LDO_VMIPI_OP_EN                  (MT6355_PMIC_REG_BASE + 0x1732)
#define PMIC_LDO_VMIPI_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x1734)
#define PMIC_LDO_VMIPI_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x1736)
#define PMIC_LDO_VMIPI_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x1738)
#define PMIC_LDO_VMIPI_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x173A)
#define PMIC_LDO_VMIPI_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x173C)
#define PMIC_LDO_VMIPI_CON1                   (MT6355_PMIC_REG_BASE + 0x173E)
#define PMIC_LDO_VMIPI_CON2                   (MT6355_PMIC_REG_BASE + 0x1740)
#define PMIC_LDO_VMIPI_CON3                   (MT6355_PMIC_REG_BASE + 0x1742)
#define PMIC_LDO_VGP_CON0                     (MT6355_PMIC_REG_BASE + 0x1744)
#define PMIC_LDO_VGP_OP_EN                    (MT6355_PMIC_REG_BASE + 0x1746)
#define PMIC_LDO_VGP_OP_EN_SET                (MT6355_PMIC_REG_BASE + 0x1748)
#define PMIC_LDO_VGP_OP_EN_CLR                (MT6355_PMIC_REG_BASE + 0x174A)
#define PMIC_LDO_VGP_OP_CFG                   (MT6355_PMIC_REG_BASE + 0x174C)
#define PMIC_LDO_VGP_OP_CFG_SET               (MT6355_PMIC_REG_BASE + 0x174E)
#define PMIC_LDO_VGP_OP_CFG_CLR               (MT6355_PMIC_REG_BASE + 0x1750)
#define PMIC_LDO_VGP_CON1                     (MT6355_PMIC_REG_BASE + 0x1752)
#define PMIC_LDO_VGP_CON2                     (MT6355_PMIC_REG_BASE + 0x1754)
#define PMIC_LDO_VGP_CON3                     (MT6355_PMIC_REG_BASE + 0x1756)
#define PMIC_LDO_VCN33_CON0_BT                (MT6355_PMIC_REG_BASE + 0x1758)
#define PMIC_LDO_VCN33_OP_EN                  (MT6355_PMIC_REG_BASE + 0x175A)
#define PMIC_LDO_VCN33_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x175C)
#define PMIC_LDO_VCN33_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x175E)
#define PMIC_LDO_VCN33_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x1760)
#define PMIC_LDO_VCN33_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x1762)
#define PMIC_LDO_VCN33_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x1764)
#define PMIC_LDO_VCN33_CON0_WIFI              (MT6355_PMIC_REG_BASE + 0x1766)
#define PMIC_LDO_VCN33_CON1                   (MT6355_PMIC_REG_BASE + 0x1768)
#define PMIC_LDO_VCN33_CON2                   (MT6355_PMIC_REG_BASE + 0x176A)
#define PMIC_LDO_VCN33_CON3                   (MT6355_PMIC_REG_BASE + 0x176C)
#define PMIC_LDO_VCN18_CON0                   (MT6355_PMIC_REG_BASE + 0x176E)
#define PMIC_LDO_VCN18_OP_EN                  (MT6355_PMIC_REG_BASE + 0x1770)
#define PMIC_LDO_VCN18_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x1772)
#define PMIC_LDO_VCN18_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x1774)
#define PMIC_LDO_VCN18_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x1776)
#define PMIC_LDO_VCN18_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x1778)
#define PMIC_LDO_VCN18_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x177A)
#define PMIC_LDO_VCN18_CON1                   (MT6355_PMIC_REG_BASE + 0x177C)
#define PMIC_LDO_VCN18_CON2                   (MT6355_PMIC_REG_BASE + 0x177E)
#define PMIC_LDO_VCN18_CON3                   (MT6355_PMIC_REG_BASE + 0x1780)
#define PMIC_LDO_VCN28_CON0                   (MT6355_PMIC_REG_BASE + 0x1782)
#define PMIC_LDO_VCN28_OP_EN                  (MT6355_PMIC_REG_BASE + 0x1784)
#define PMIC_LDO_VCN28_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x1786)
#define PMIC_LDO_VCN28_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x1788)
#define PMIC_LDO_VCN28_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x178A)
#define PMIC_LDO_VCN28_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x178C)
#define PMIC_LDO_VCN28_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x178E)
#define PMIC_LDO_VCN28_CON1                   (MT6355_PMIC_REG_BASE + 0x1790)
#define PMIC_LDO_VCN28_CON2                   (MT6355_PMIC_REG_BASE + 0x1792)
#define PMIC_LDO_VCN28_CON3                   (MT6355_PMIC_REG_BASE + 0x1794)
#define PMIC_LDO_VBIF28_CON0                  (MT6355_PMIC_REG_BASE + 0x1796)
#define PMIC_LDO_VBIF28_OP_EN                 (MT6355_PMIC_REG_BASE + 0x1798)
#define PMIC_LDO_VBIF28_OP_EN_SET             (MT6355_PMIC_REG_BASE + 0x179A)
#define PMIC_LDO_VBIF28_OP_EN_CLR             (MT6355_PMIC_REG_BASE + 0x179C)
#define PMIC_LDO_VBIF28_OP_CFG                (MT6355_PMIC_REG_BASE + 0x179E)
#define PMIC_LDO_VBIF28_OP_CFG_SET            (MT6355_PMIC_REG_BASE + 0x17A0)
#define PMIC_LDO_VBIF28_OP_CFG_CLR            (MT6355_PMIC_REG_BASE + 0x17A2)
#define PMIC_LDO_VBIF28_CON1                  (MT6355_PMIC_REG_BASE + 0x17A4)
#define PMIC_LDO_VBIF28_CON2                  (MT6355_PMIC_REG_BASE + 0x17A6)
#define PMIC_LDO_VBIF28_CON3                  (MT6355_PMIC_REG_BASE + 0x17A8)
#define PMIC_LDO_VTCXO24_CON0                 (MT6355_PMIC_REG_BASE + 0x17AA)
#define PMIC_LDO_VTCXO24_OP_EN                (MT6355_PMIC_REG_BASE + 0x17AC)
#define PMIC_LDO_VTCXO24_OP_EN_SET            (MT6355_PMIC_REG_BASE + 0x17AE)
#define PMIC_LDO_VTCXO24_OP_EN_CLR            (MT6355_PMIC_REG_BASE + 0x17B0)
#define PMIC_LDO_VTCXO24_OP_CFG               (MT6355_PMIC_REG_BASE + 0x17B2)
#define PMIC_LDO_VTCXO24_OP_CFG_SET           (MT6355_PMIC_REG_BASE + 0x17B4)
#define PMIC_LDO_VTCXO24_OP_CFG_CLR           (MT6355_PMIC_REG_BASE + 0x17B6)
#define PMIC_LDO_VTCXO24_CON1                 (MT6355_PMIC_REG_BASE + 0x17B8)
#define PMIC_LDO_VTCXO24_CON2                 (MT6355_PMIC_REG_BASE + 0x17BA)
#define PMIC_LDO_VTCXO24_CON3                 (MT6355_PMIC_REG_BASE + 0x17BC)
#define PMIC_LDO_VLDO28_CON0_AF               (MT6355_PMIC_REG_BASE + 0x17BE)
#define PMIC_LDO_VLDO28_OP_EN                 (MT6355_PMIC_REG_BASE + 0x17C0)
#define PMIC_LDO_VLDO28_OP_EN_SET             (MT6355_PMIC_REG_BASE + 0x17C2)
#define PMIC_LDO_VLDO28_OP_EN_CLR             (MT6355_PMIC_REG_BASE + 0x17C4)
#define PMIC_LDO_VLDO28_OP_CFG                (MT6355_PMIC_REG_BASE + 0x17C6)
#define PMIC_LDO_VLDO28_OP_CFG_SET            (MT6355_PMIC_REG_BASE + 0x17C8)
#define PMIC_LDO_VLDO28_OP_CFG_CLR            (MT6355_PMIC_REG_BASE + 0x17CA)
#define PMIC_LDO_VLDO28_CON0_TP               (MT6355_PMIC_REG_BASE + 0x17CC)
#define PMIC_LDO_VLDO28_CON1                  (MT6355_PMIC_REG_BASE + 0x17CE)
#define PMIC_LDO_VLDO28_CON2                  (MT6355_PMIC_REG_BASE + 0x17D0)
#define PMIC_LDO_VLDO28_CON3                  (MT6355_PMIC_REG_BASE + 0x17D2)
#define PMIC_LDO_VGP2_CON0                    (MT6355_PMIC_REG_BASE + 0x17D4)
#define PMIC_LDO_VGP2_OP_EN                   (MT6355_PMIC_REG_BASE + 0x17D6)
#define PMIC_LDO_VGP2_OP_EN_SET               (MT6355_PMIC_REG_BASE + 0x17D8)
#define PMIC_LDO_VGP2_OP_EN_CLR               (MT6355_PMIC_REG_BASE + 0x17DA)
#define PMIC_LDO_VGP2_OP_CFG                  (MT6355_PMIC_REG_BASE + 0x17DC)
#define PMIC_LDO_VGP2_OP_CFG_SET              (MT6355_PMIC_REG_BASE + 0x17DE)
#define PMIC_LDO_VGP2_OP_CFG_CLR              (MT6355_PMIC_REG_BASE + 0x17E0)
#define PMIC_LDO_VGP2_CON1                    (MT6355_PMIC_REG_BASE + 0x17E2)
#define PMIC_LDO_VGP2_CON2                    (MT6355_PMIC_REG_BASE + 0x17E4)
#define PMIC_LDO_VGP2_CON3                    (MT6355_PMIC_REG_BASE + 0x17E6)
#define PMIC_LDO_VFE28_CON0                   (MT6355_PMIC_REG_BASE + 0x1800)
#define PMIC_LDO_VFE28_OP_EN                  (MT6355_PMIC_REG_BASE + 0x1802)
#define PMIC_LDO_VFE28_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x1804)
#define PMIC_LDO_VFE28_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x1806)
#define PMIC_LDO_VFE28_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x1808)
#define PMIC_LDO_VFE28_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x180A)
#define PMIC_LDO_VFE28_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x180C)
#define PMIC_LDO_VFE28_CON1                   (MT6355_PMIC_REG_BASE + 0x180E)
#define PMIC_LDO_VFE28_CON2                   (MT6355_PMIC_REG_BASE + 0x1810)
#define PMIC_LDO_VFE28_CON3                   (MT6355_PMIC_REG_BASE + 0x1812)
#define PMIC_LDO_VMCH_CON0                    (MT6355_PMIC_REG_BASE + 0x1814)
#define PMIC_LDO_VMCH_OP_EN                   (MT6355_PMIC_REG_BASE + 0x1816)
#define PMIC_LDO_VMCH_OP_EN_SET               (MT6355_PMIC_REG_BASE + 0x1818)
#define PMIC_LDO_VMCH_OP_EN_CLR               (MT6355_PMIC_REG_BASE + 0x181A)
#define PMIC_LDO_VMCH_OP_CFG                  (MT6355_PMIC_REG_BASE + 0x181C)
#define PMIC_LDO_VMCH_OP_CFG_SET              (MT6355_PMIC_REG_BASE + 0x181E)
#define PMIC_LDO_VMCH_OP_CFG_CLR              (MT6355_PMIC_REG_BASE + 0x1820)
#define PMIC_LDO_VMCH_CON1                    (MT6355_PMIC_REG_BASE + 0x1822)
#define PMIC_LDO_VMCH_CON2                    (MT6355_PMIC_REG_BASE + 0x1824)
#define PMIC_LDO_VMCH_CON3                    (MT6355_PMIC_REG_BASE + 0x1826)
#define PMIC_LDO_VMC_CON0                     (MT6355_PMIC_REG_BASE + 0x1828)
#define PMIC_LDO_VMC_OP_EN                    (MT6355_PMIC_REG_BASE + 0x182A)
#define PMIC_LDO_VMC_OP_EN_SET                (MT6355_PMIC_REG_BASE + 0x182C)
#define PMIC_LDO_VMC_OP_EN_CLR                (MT6355_PMIC_REG_BASE + 0x182E)
#define PMIC_LDO_VMC_OP_CFG                   (MT6355_PMIC_REG_BASE + 0x1830)
#define PMIC_LDO_VMC_OP_CFG_SET               (MT6355_PMIC_REG_BASE + 0x1832)
#define PMIC_LDO_VMC_OP_CFG_CLR               (MT6355_PMIC_REG_BASE + 0x1834)
#define PMIC_LDO_VMC_CON1                     (MT6355_PMIC_REG_BASE + 0x1836)
#define PMIC_LDO_VMC_CON2                     (MT6355_PMIC_REG_BASE + 0x1838)
#define PMIC_LDO_VMC_CON3                     (MT6355_PMIC_REG_BASE + 0x183A)
#define PMIC_LDO_VRF18_1_CON0                 (MT6355_PMIC_REG_BASE + 0x183C)
#define PMIC_LDO_VRF18_1_OP_EN                (MT6355_PMIC_REG_BASE + 0x183E)
#define PMIC_LDO_VRF18_1_OP_EN_SET            (MT6355_PMIC_REG_BASE + 0x1840)
#define PMIC_LDO_VRF18_1_OP_EN_CLR            (MT6355_PMIC_REG_BASE + 0x1842)
#define PMIC_LDO_VRF18_1_OP_CFG               (MT6355_PMIC_REG_BASE + 0x1844)
#define PMIC_LDO_VRF18_1_OP_CFG_SET           (MT6355_PMIC_REG_BASE + 0x1846)
#define PMIC_LDO_VRF18_1_OP_CFG_CLR           (MT6355_PMIC_REG_BASE + 0x1848)
#define PMIC_LDO_VRF18_1_CON1                 (MT6355_PMIC_REG_BASE + 0x184A)
#define PMIC_LDO_VRF18_1_CON2                 (MT6355_PMIC_REG_BASE + 0x184C)
#define PMIC_LDO_VRF18_1_CON3                 (MT6355_PMIC_REG_BASE + 0x184E)
#define PMIC_LDO_VRF18_2_CON0                 (MT6355_PMIC_REG_BASE + 0x1850)
#define PMIC_LDO_VRF18_2_OP_EN                (MT6355_PMIC_REG_BASE + 0x1852)
#define PMIC_LDO_VRF18_2_OP_EN_SET            (MT6355_PMIC_REG_BASE + 0x1854)
#define PMIC_LDO_VRF18_2_OP_EN_CLR            (MT6355_PMIC_REG_BASE + 0x1856)
#define PMIC_LDO_VRF18_2_OP_CFG               (MT6355_PMIC_REG_BASE + 0x1858)
#define PMIC_LDO_VRF18_2_OP_CFG_SET           (MT6355_PMIC_REG_BASE + 0x185A)
#define PMIC_LDO_VRF18_2_OP_CFG_CLR           (MT6355_PMIC_REG_BASE + 0x185C)
#define PMIC_LDO_VRF18_2_CON1                 (MT6355_PMIC_REG_BASE + 0x185E)
#define PMIC_LDO_VRF18_2_CON2                 (MT6355_PMIC_REG_BASE + 0x1860)
#define PMIC_LDO_VRF18_2_CON3                 (MT6355_PMIC_REG_BASE + 0x1862)
#define PMIC_LDO_VRF12_CON0                   (MT6355_PMIC_REG_BASE + 0x1864)
#define PMIC_LDO_VRF12_OP_EN                  (MT6355_PMIC_REG_BASE + 0x1866)
#define PMIC_LDO_VRF12_OP_EN_SET              (MT6355_PMIC_REG_BASE + 0x1868)
#define PMIC_LDO_VRF12_OP_EN_CLR              (MT6355_PMIC_REG_BASE + 0x186A)
#define PMIC_LDO_VRF12_OP_CFG                 (MT6355_PMIC_REG_BASE + 0x186C)
#define PMIC_LDO_VRF12_OP_CFG_SET             (MT6355_PMIC_REG_BASE + 0x186E)
#define PMIC_LDO_VRF12_OP_CFG_CLR             (MT6355_PMIC_REG_BASE + 0x1870)
#define PMIC_LDO_VRF12_CON1                   (MT6355_PMIC_REG_BASE + 0x1872)
#define PMIC_LDO_VRF12_CON2                   (MT6355_PMIC_REG_BASE + 0x1874)
#define PMIC_LDO_VRF12_CON3                   (MT6355_PMIC_REG_BASE + 0x1876)
#define PMIC_LDO_VCAMA1_CON0                  (MT6355_PMIC_REG_BASE + 0x1878)
#define PMIC_LDO_VCAMA1_OP_EN                 (MT6355_PMIC_REG_BASE + 0x187A)
#define PMIC_LDO_VCAMA1_OP_EN_SET             (MT6355_PMIC_REG_BASE + 0x187C)
#define PMIC_LDO_VCAMA1_OP_EN_CLR             (MT6355_PMIC_REG_BASE + 0x187E)
#define PMIC_LDO_VCAMA1_OP_CFG                (MT6355_PMIC_REG_BASE + 0x1880)
#define PMIC_LDO_VCAMA1_OP_CFG_SET            (MT6355_PMIC_REG_BASE + 0x1882)
#define PMIC_LDO_VCAMA1_OP_CFG_CLR            (MT6355_PMIC_REG_BASE + 0x1884)
#define PMIC_LDO_VCAMA1_CON1                  (MT6355_PMIC_REG_BASE + 0x1886)
#define PMIC_LDO_VCAMA1_CON2                  (MT6355_PMIC_REG_BASE + 0x1888)
#define PMIC_LDO_VCAMA1_CON3                  (MT6355_PMIC_REG_BASE + 0x188A)
#define PMIC_LDO_VCAMA2_CON0                  (MT6355_PMIC_REG_BASE + 0x188C)
#define PMIC_LDO_VCAMA2_OP_EN                 (MT6355_PMIC_REG_BASE + 0x188E)
#define PMIC_LDO_VCAMA2_OP_EN_SET             (MT6355_PMIC_REG_BASE + 0x1890)
#define PMIC_LDO_VCAMA2_OP_EN_CLR             (MT6355_PMIC_REG_BASE + 0x1892)
#define PMIC_LDO_VCAMA2_OP_CFG                (MT6355_PMIC_REG_BASE + 0x1894)
#define PMIC_LDO_VCAMA2_OP_CFG_SET            (MT6355_PMIC_REG_BASE + 0x1896)
#define PMIC_LDO_VCAMA2_OP_CFG_CLR            (MT6355_PMIC_REG_BASE + 0x1898)
#define PMIC_LDO_VCAMA2_CON1                  (MT6355_PMIC_REG_BASE + 0x189A)
#define PMIC_LDO_VCAMA2_CON2                  (MT6355_PMIC_REG_BASE + 0x189C)
#define PMIC_LDO_VCAMA2_CON3                  (MT6355_PMIC_REG_BASE + 0x189E)
#define PMIC_LDO_OCFB0                        (MT6355_PMIC_REG_BASE + 0x18A0)
#define PMIC_VRTC_CON0                        (MT6355_PMIC_REG_BASE + 0x18A2)
#define PMIC_LDO_RSV_CON0                     (MT6355_PMIC_REG_BASE + 0x18A4)
#define PMIC_LDO_RSV_CON1                     (MT6355_PMIC_REG_BASE + 0x18A6)
#define PMIC_LDO_VSRAM_PROC_CON0              (MT6355_PMIC_REG_BASE + 0x18A8)
#define PMIC_LDO_VSRAM_PROC_CON1              (MT6355_PMIC_REG_BASE + 0x18AA)
#define PMIC_LDO_VSRAM_PROC_CON2              (MT6355_PMIC_REG_BASE + 0x18AC)
#define PMIC_LDO_VSRAM_PROC_CFG0              (MT6355_PMIC_REG_BASE + 0x18AE)
#define PMIC_LDO_VSRAM_PROC_CFG1              (MT6355_PMIC_REG_BASE + 0x18B0)
#define PMIC_LDO_VSRAM_PROC_OP_EN             (MT6355_PMIC_REG_BASE + 0x18B2)
#define PMIC_LDO_VSRAM_PROC_OP_EN_SET         (MT6355_PMIC_REG_BASE + 0x18B4)
#define PMIC_LDO_VSRAM_PROC_OP_EN_CLR         (MT6355_PMIC_REG_BASE + 0x18B6)
#define PMIC_LDO_VSRAM_PROC_OP_CFG            (MT6355_PMIC_REG_BASE + 0x18B8)
#define PMIC_LDO_VSRAM_PROC_OP_CFG_SET        (MT6355_PMIC_REG_BASE + 0x18BA)
#define PMIC_LDO_VSRAM_PROC_OP_CFG_CLR        (MT6355_PMIC_REG_BASE + 0x18BC)
#define PMIC_LDO_VSRAM_PROC_CON3              (MT6355_PMIC_REG_BASE + 0x18BE)
#define PMIC_LDO_VSRAM_PROC_CON4              (MT6355_PMIC_REG_BASE + 0x18C0)
#define PMIC_LDO_VSRAM_PROC_CON5              (MT6355_PMIC_REG_BASE + 0x18C2)
#define PMIC_LDO_VSRAM_PROC_DBG0              (MT6355_PMIC_REG_BASE + 0x18C4)
#define PMIC_LDO_VSRAM_PROC_DBG1              (MT6355_PMIC_REG_BASE + 0x18C6)
#define PMIC_LDO_VSRAM_CORE_CON0              (MT6355_PMIC_REG_BASE + 0x18C8)
#define PMIC_LDO_VSRAM_CORE_CON1              (MT6355_PMIC_REG_BASE + 0x18CA)
#define PMIC_LDO_VSRAM_CORE_CON2              (MT6355_PMIC_REG_BASE + 0x18CC)
#define PMIC_LDO_VSRAM_CORE_CFG0              (MT6355_PMIC_REG_BASE + 0x18CE)
#define PMIC_LDO_VSRAM_CORE_CFG1              (MT6355_PMIC_REG_BASE + 0x18D0)
#define PMIC_LDO_VSRAM_CORE_OP_EN             (MT6355_PMIC_REG_BASE + 0x18D2)
#define PMIC_LDO_VSRAM_CORE_OP_EN_SET         (MT6355_PMIC_REG_BASE + 0x18D4)
#define PMIC_LDO_VSRAM_CORE_OP_EN_CLR         (MT6355_PMIC_REG_BASE + 0x18D6)
#define PMIC_LDO_VSRAM_CORE_OP_CFG            (MT6355_PMIC_REG_BASE + 0x18D8)
#define PMIC_LDO_VSRAM_CORE_OP_CFG_SET        (MT6355_PMIC_REG_BASE + 0x18DA)
#define PMIC_LDO_VSRAM_CORE_OP_CFG_CLR        (MT6355_PMIC_REG_BASE + 0x18DC)
#define PMIC_LDO_VSRAM_CORE_CON3              (MT6355_PMIC_REG_BASE + 0x18DE)
#define PMIC_LDO_VSRAM_CORE_CON4              (MT6355_PMIC_REG_BASE + 0x18E0)
#define PMIC_LDO_VSRAM_CORE_CON5              (MT6355_PMIC_REG_BASE + 0x18E2)
#define PMIC_LDO_VSRAM_CORE_DBG0              (MT6355_PMIC_REG_BASE + 0x18E4)
#define PMIC_LDO_VSRAM_CORE_DBG1              (MT6355_PMIC_REG_BASE + 0x18E6)
#define PMIC_LDO_VSRAM_GPU_CON0               (MT6355_PMIC_REG_BASE + 0x18E8)
#define PMIC_LDO_VSRAM_GPU_CON1               (MT6355_PMIC_REG_BASE + 0x18EA)
#define PMIC_LDO_VSRAM_GPU_CON2               (MT6355_PMIC_REG_BASE + 0x18EC)
#define PMIC_LDO_VSRAM_GPU_CFG0               (MT6355_PMIC_REG_BASE + 0x18EE)
#define PMIC_LDO_VSRAM_GPU_CFG1               (MT6355_PMIC_REG_BASE + 0x18F0)
#define PMIC_LDO_VSRAM_GPU_OP_EN              (MT6355_PMIC_REG_BASE + 0x18F2)
#define PMIC_LDO_VSRAM_GPU_OP_EN_SET          (MT6355_PMIC_REG_BASE + 0x18F4)
#define PMIC_LDO_VSRAM_GPU_OP_EN_CLR          (MT6355_PMIC_REG_BASE + 0x18F6)
#define PMIC_LDO_VSRAM_GPU_OP_CFG             (MT6355_PMIC_REG_BASE + 0x18F8)
#define PMIC_LDO_VSRAM_GPU_OP_CFG_SET         (MT6355_PMIC_REG_BASE + 0x18FA)
#define PMIC_LDO_VSRAM_GPU_OP_CFG_CLR         (MT6355_PMIC_REG_BASE + 0x18FC)
#define PMIC_LDO_VSRAM_GPU_CON3               (MT6355_PMIC_REG_BASE + 0x18FE)
#define PMIC_LDO_VSRAM_GPU_CON4               (MT6355_PMIC_REG_BASE + 0x1900)
#define PMIC_LDO_VSRAM_GPU_CON5               (MT6355_PMIC_REG_BASE + 0x1902)
#define PMIC_LDO_VSRAM_GPU_DBG0               (MT6355_PMIC_REG_BASE + 0x1904)
#define PMIC_LDO_VSRAM_GPU_DBG1               (MT6355_PMIC_REG_BASE + 0x1906)
#define PMIC_LDO_VSRAM_MD_CON0                (MT6355_PMIC_REG_BASE + 0x1908)
#define PMIC_LDO_VSRAM_MD_CON1                (MT6355_PMIC_REG_BASE + 0x190A)
#define PMIC_LDO_VSRAM_MD_CON2                (MT6355_PMIC_REG_BASE + 0x190C)
#define PMIC_LDO_VSRAM_MD_CFG0                (MT6355_PMIC_REG_BASE + 0x190E)
#define PMIC_LDO_VSRAM_MD_CFG1                (MT6355_PMIC_REG_BASE + 0x1910)
#define PMIC_LDO_VSRAM_MD_OP_EN               (MT6355_PMIC_REG_BASE + 0x1912)
#define PMIC_LDO_VSRAM_MD_OP_EN_SET           (MT6355_PMIC_REG_BASE + 0x1914)
#define PMIC_LDO_VSRAM_MD_OP_EN_CLR           (MT6355_PMIC_REG_BASE + 0x1916)
#define PMIC_LDO_VSRAM_MD_OP_CFG              (MT6355_PMIC_REG_BASE + 0x1918)
#define PMIC_LDO_VSRAM_MD_OP_CFG_SET          (MT6355_PMIC_REG_BASE + 0x191A)
#define PMIC_LDO_VSRAM_MD_OP_CFG_CLR          (MT6355_PMIC_REG_BASE + 0x191C)
#define PMIC_LDO_VSRAM_MD_CON3                (MT6355_PMIC_REG_BASE + 0x191E)
#define PMIC_LDO_VSRAM_MD_CON4                (MT6355_PMIC_REG_BASE + 0x1920)
#define PMIC_LDO_VSRAM_MD_CON5                (MT6355_PMIC_REG_BASE + 0x1922)
#define PMIC_LDO_VSRAM_MD_DBG0                (MT6355_PMIC_REG_BASE + 0x1924)
#define PMIC_LDO_VSRAM_MD_DBG1                (MT6355_PMIC_REG_BASE + 0x1926)
#define PMIC_LDO_TRACKING_CON0                (MT6355_PMIC_REG_BASE + 0x1928)
#define PMIC_LDO_TRACKING_CON1                (MT6355_PMIC_REG_BASE + 0x192A)
#define PMIC_LDO_TRACKING_CON2                (MT6355_PMIC_REG_BASE + 0x192C)
#define PMIC_LDO_TRACKING_CON3                (MT6355_PMIC_REG_BASE + 0x192E)
#define PMIC_LDO_DCM                          (MT6355_PMIC_REG_BASE + 0x1930)
#define PMIC_LDO_VIO28_CG0                    (MT6355_PMIC_REG_BASE + 0x1932)
#define PMIC_LDO_VIO18_CG0                    (MT6355_PMIC_REG_BASE + 0x1934)
#define PMIC_LDO_VUFS18_CG0                   (MT6355_PMIC_REG_BASE + 0x1936)
#define PMIC_LDO_VA10_CG0                     (MT6355_PMIC_REG_BASE + 0x1938)
#define PMIC_LDO_VA12_CG0                     (MT6355_PMIC_REG_BASE + 0x193A)
#define PMIC_LDO_VSRAM_PROC_CG0               (MT6355_PMIC_REG_BASE + 0x193C)
#define PMIC_LDO_VSRAM_CORE_CG0               (MT6355_PMIC_REG_BASE + 0x193E)
#define PMIC_LDO_VSRAM_GPU_CG0                (MT6355_PMIC_REG_BASE + 0x1940)
#define PMIC_LDO_VSRAM_MD_CG0                 (MT6355_PMIC_REG_BASE + 0x1942)
#define PMIC_LDO_VA18_CG0                     (MT6355_PMIC_REG_BASE + 0x1944)
#define PMIC_LDO_VUSB33_CG0                   (MT6355_PMIC_REG_BASE + 0x1946)
#define PMIC_LDO_VEMC_CG0                     (MT6355_PMIC_REG_BASE + 0x1948)
#define PMIC_LDO_VXO22_CG0                    (MT6355_PMIC_REG_BASE + 0x194A)
#define PMIC_LDO_VXO18_CG0                    (MT6355_PMIC_REG_BASE + 0x194C)
#define PMIC_LDO_VSIM1_CG0                    (MT6355_PMIC_REG_BASE + 0x194E)
#define PMIC_LDO_VSIM2_CG0                    (MT6355_PMIC_REG_BASE + 0x1950)
#define PMIC_LDO_VCAMD1_CG0                   (MT6355_PMIC_REG_BASE + 0x1952)
#define PMIC_LDO_VCAMD2_CG0                   (MT6355_PMIC_REG_BASE + 0x1954)
#define PMIC_LDO_VCAMIO_CG0                   (MT6355_PMIC_REG_BASE + 0x1956)
#define PMIC_LDO_VMIPI_CG0                    (MT6355_PMIC_REG_BASE + 0x1958)
#define PMIC_LDO_VGP_CG0                      (MT6355_PMIC_REG_BASE + 0x195A)
#define PMIC_LDO_VCN33_CG0                    (MT6355_PMIC_REG_BASE + 0x195C)
#define PMIC_LDO_VCN18_CG0                    (MT6355_PMIC_REG_BASE + 0x195E)
#define PMIC_LDO_VCN28_CG0                    (MT6355_PMIC_REG_BASE + 0x1960)
#define PMIC_LDO_VGP2_CG0                     (MT6355_PMIC_REG_BASE + 0x1962)
#define PMIC_LDO_VBIF28_CG0                   (MT6355_PMIC_REG_BASE + 0x1964)
#define PMIC_LDO_VFE28_CG0                    (MT6355_PMIC_REG_BASE + 0x1966)
#define PMIC_LDO_VMCH_CG0                     (MT6355_PMIC_REG_BASE + 0x1968)
#define PMIC_LDO_VMC_CG0                      (MT6355_PMIC_REG_BASE + 0x196A)
#define PMIC_LDO_VRF18_1_CG0                  (MT6355_PMIC_REG_BASE + 0x196C)
#define PMIC_LDO_VRF18_2_CG0                  (MT6355_PMIC_REG_BASE + 0x196E)
#define PMIC_LDO_VTCXO24_CG0                  (MT6355_PMIC_REG_BASE + 0x1970)
#define PMIC_LDO_VLDO28_CG0                   (MT6355_PMIC_REG_BASE + 0x1972)
#define PMIC_LDO_VRF12_CG0                    (MT6355_PMIC_REG_BASE + 0x1974)
#define PMIC_LDO_VCAMA1_CG0                   (MT6355_PMIC_REG_BASE + 0x1976)
#define PMIC_LDO_VCAMA2_CG0                   (MT6355_PMIC_REG_BASE + 0x1978)
#define PMIC_LDO_VSRAM_PROC_SP                (MT6355_PMIC_REG_BASE + 0x197A)
#define PMIC_LDO_VSRAM_GPU_SP                 (MT6355_PMIC_REG_BASE + 0x197C)
#define PMIC_LDO_VSRAM_MD_SP                  (MT6355_PMIC_REG_BASE + 0x197E)
#define PMIC_LDO_VSRAM_CORE_SP                (MT6355_PMIC_REG_BASE + 0x1980)
#define PMIC_LDO_VSRAM_CORE_SSHUB             (MT6355_PMIC_REG_BASE + 0x1982)
#define PMIC_LDO_LP_PROTECTION                (MT6355_PMIC_REG_BASE + 0x1984)
#define PMIC_LDO_DUMMY_LOAD_GATED             (MT6355_PMIC_REG_BASE + 0x1986)
#define PMIC_LDO_VSRAM_PROC_R2R_PDN_DIS       (MT6355_PMIC_REG_BASE + 0x1988)
#define PMIC_LDO_VSRAM_CORE_R2R_PDN_DIS       (MT6355_PMIC_REG_BASE + 0x198A)
#define PMIC_LDO_VSRAM_GPU_R2R_PDN_DIS        (MT6355_PMIC_REG_BASE + 0x198C)
#define PMIC_LDO_VSRAM_MD_R2R_PDN_DIS         (MT6355_PMIC_REG_BASE + 0x198E)
#define PMIC_ALDO_ANA_CON0                    (MT6355_PMIC_REG_BASE + 0x1A00)
#define PMIC_ALDO_ANA_CON1                    (MT6355_PMIC_REG_BASE + 0x1A02)
#define PMIC_ALDO_ANA_CON2                    (MT6355_PMIC_REG_BASE + 0x1A04)
#define PMIC_ALDO_ANA_CON3                    (MT6355_PMIC_REG_BASE + 0x1A06)
#define PMIC_ALDO_ANA_CON4                    (MT6355_PMIC_REG_BASE + 0x1A08)
#define PMIC_ALDO_ANA_CON5                    (MT6355_PMIC_REG_BASE + 0x1A0A)
#define PMIC_ALDO_ANA_CON6                    (MT6355_PMIC_REG_BASE + 0x1A0C)
#define PMIC_ALDO_ANA_CON7                    (MT6355_PMIC_REG_BASE + 0x1A0E)
#define PMIC_ALDO_ANA_CON8                    (MT6355_PMIC_REG_BASE + 0x1A10)
#define PMIC_ALDO_ANA_CON9                    (MT6355_PMIC_REG_BASE + 0x1A12)
#define PMIC_ALDO_ANA_CON10                   (MT6355_PMIC_REG_BASE + 0x1A14)
#define PMIC_ALDO_ANA_CON11                   (MT6355_PMIC_REG_BASE + 0x1A16)
#define PMIC_ALDO_ANA_CON12                   (MT6355_PMIC_REG_BASE + 0x1A18)
#define PMIC_ALDO_ANA_CON13                   (MT6355_PMIC_REG_BASE + 0x1A1A)
#define PMIC_ALDO_ANA_CON14                   (MT6355_PMIC_REG_BASE + 0x1A1C)
#define PMIC_ALDO_ANA_CON15                   (MT6355_PMIC_REG_BASE + 0x1A1E)
#define PMIC_ALDO_ANA_CON16                   (MT6355_PMIC_REG_BASE + 0x1A20)
#define PMIC_ALDO_ANA_CON17                   (MT6355_PMIC_REG_BASE + 0x1A22)
#define PMIC_ALDO_ANA_CON18                   (MT6355_PMIC_REG_BASE + 0x1A24)
#define PMIC_ALDO_ANA_CON19                   (MT6355_PMIC_REG_BASE + 0x1A26)
#define PMIC_DLDO_ANA_CON0                    (MT6355_PMIC_REG_BASE + 0x1A28)
#define PMIC_DLDO_ANA_CON1                    (MT6355_PMIC_REG_BASE + 0x1A2A)
#define PMIC_DLDO_ANA_CON2                    (MT6355_PMIC_REG_BASE + 0x1A2C)
#define PMIC_DLDO_ANA_CON3                    (MT6355_PMIC_REG_BASE + 0x1A2E)
#define PMIC_DLDO_ANA_CON4                    (MT6355_PMIC_REG_BASE + 0x1A30)
#define PMIC_DLDO_ANA_CON5                    (MT6355_PMIC_REG_BASE + 0x1A32)
#define PMIC_DLDO_ANA_CON6                    (MT6355_PMIC_REG_BASE + 0x1A34)
#define PMIC_DLDO_ANA_CON7                    (MT6355_PMIC_REG_BASE + 0x1A36)
#define PMIC_DLDO_ANA_CON8                    (MT6355_PMIC_REG_BASE + 0x1A38)
#define PMIC_DLDO_ANA_CON9                    (MT6355_PMIC_REG_BASE + 0x1A3A)
#define PMIC_DLDO_ANA_CON10                   (MT6355_PMIC_REG_BASE + 0x1A3C)
#define PMIC_DLDO_ANA_CON11                   (MT6355_PMIC_REG_BASE + 0x1A3E)
#define PMIC_DLDO_ANA_CON12                   (MT6355_PMIC_REG_BASE + 0x1A40)
#define PMIC_DLDO_ANA_CON13                   (MT6355_PMIC_REG_BASE + 0x1A42)
#define PMIC_DLDO_ANA_CON14                   (MT6355_PMIC_REG_BASE + 0x1A44)
#define PMIC_DLDO_ANA_CON15                   (MT6355_PMIC_REG_BASE + 0x1A46)
#define PMIC_DLDO_ANA_CON16                   (MT6355_PMIC_REG_BASE + 0x1A48)
#define PMIC_DLDO_ANA_CON17                   (MT6355_PMIC_REG_BASE + 0x1A4A)
#define PMIC_SLDO20_ANA_CON0                  (MT6355_PMIC_REG_BASE + 0x1A4C)
#define PMIC_SLDO20_ANA_CON1                  (MT6355_PMIC_REG_BASE + 0x1A4E)
#define PMIC_SLDO20_ANA_CON2                  (MT6355_PMIC_REG_BASE + 0x1A50)
#define PMIC_SLDO20_ANA_CON3                  (MT6355_PMIC_REG_BASE + 0x1A52)
#define PMIC_SLDO20_ANA_CON4                  (MT6355_PMIC_REG_BASE + 0x1A54)
#define PMIC_SLDO20_ANA_CON5                  (MT6355_PMIC_REG_BASE + 0x1A56)
#define PMIC_SLDO20_ANA_CON6                  (MT6355_PMIC_REG_BASE + 0x1A58)
#define PMIC_SLDO20_ANA_CON7                  (MT6355_PMIC_REG_BASE + 0x1A5A)
#define PMIC_SLDO20_ANA_CON8                  (MT6355_PMIC_REG_BASE + 0x1A5C)
#define PMIC_SLDO20_ANA_CON9                  (MT6355_PMIC_REG_BASE + 0x1A5E)
#define PMIC_SLDO20_ANA_CON10                 (MT6355_PMIC_REG_BASE + 0x1A60)
#define PMIC_SLDO20_ANA_CON11                 (MT6355_PMIC_REG_BASE + 0x1A62)
#define PMIC_SLDO20_ANA_CON12                 (MT6355_PMIC_REG_BASE + 0x1A64)
#define PMIC_SLDO20_ANA_CON13                 (MT6355_PMIC_REG_BASE + 0x1A66)
#define PMIC_SLDO20_ANA_CON14                 (MT6355_PMIC_REG_BASE + 0x1A68)
#define PMIC_SLDO20_ANA_CON15                 (MT6355_PMIC_REG_BASE + 0x1A6A)
#define PMIC_SLDO14_ANA_CON0                  (MT6355_PMIC_REG_BASE + 0x1A6C)
#define PMIC_SLDO14_ANA_CON1                  (MT6355_PMIC_REG_BASE + 0x1A6E)
#define PMIC_SLDO14_ANA_CON2                  (MT6355_PMIC_REG_BASE + 0x1A70)
#define PMIC_SLDO14_ANA_CON3                  (MT6355_PMIC_REG_BASE + 0x1A72)
#define PMIC_SLDO14_ANA_CON4                  (MT6355_PMIC_REG_BASE + 0x1A74)
#define PMIC_SLDO14_ANA_CON5                  (MT6355_PMIC_REG_BASE + 0x1A76)
#define PMIC_SLDO14_ANA_CON6                  (MT6355_PMIC_REG_BASE + 0x1A78)
#define PMIC_SLDO14_ANA_CON7                  (MT6355_PMIC_REG_BASE + 0x1A7A)
#define PMIC_SLDO14_ANA_CON8                  (MT6355_PMIC_REG_BASE + 0x1A7C)
#define PMIC_SLDO14_ANA_CON9                  (MT6355_PMIC_REG_BASE + 0x1A7E)
#define PMIC_SLDO14_ANA_CON10                 (MT6355_PMIC_REG_BASE + 0x1A80)
#define PMIC_SLDO14_ANA_CON11                 (MT6355_PMIC_REG_BASE + 0x1A82)
#define PMIC_SLDO14_ANA_CON12                 (MT6355_PMIC_REG_BASE + 0x1A84)
#define PMIC_ACCDET_CON0                      (MT6355_PMIC_REG_BASE + 0x1C00)
#define PMIC_ACCDET_CON1                      (MT6355_PMIC_REG_BASE + 0x1C02)
#define PMIC_ACCDET_CON2                      (MT6355_PMIC_REG_BASE + 0x1C04)
#define PMIC_ACCDET_CON3                      (MT6355_PMIC_REG_BASE + 0x1C06)
#define PMIC_ACCDET_CON4                      (MT6355_PMIC_REG_BASE + 0x1C08)
#define PMIC_ACCDET_CON5                      (MT6355_PMIC_REG_BASE + 0x1C0A)
#define PMIC_ACCDET_CON6                      (MT6355_PMIC_REG_BASE + 0x1C0C)
#define PMIC_ACCDET_CON7                      (MT6355_PMIC_REG_BASE + 0x1C0E)
#define PMIC_ACCDET_CON8                      (MT6355_PMIC_REG_BASE + 0x1C10)
#define PMIC_ACCDET_CON9                      (MT6355_PMIC_REG_BASE + 0x1C12)
#define PMIC_ACCDET_CON10                     (MT6355_PMIC_REG_BASE + 0x1C14)
#define PMIC_ACCDET_CON11                     (MT6355_PMIC_REG_BASE + 0x1C16)
#define PMIC_ACCDET_CON12                     (MT6355_PMIC_REG_BASE + 0x1C18)
#define PMIC_ACCDET_CON13                     (MT6355_PMIC_REG_BASE + 0x1C1A)
#define PMIC_ACCDET_CON14                     (MT6355_PMIC_REG_BASE + 0x1C1C)
#define PMIC_ACCDET_CON15                     (MT6355_PMIC_REG_BASE + 0x1C1E)
#define PMIC_ACCDET_CON16                     (MT6355_PMIC_REG_BASE + 0x1C20)
#define PMIC_ACCDET_CON17                     (MT6355_PMIC_REG_BASE + 0x1C22)
#define PMIC_ACCDET_CON18                     (MT6355_PMIC_REG_BASE + 0x1C24)
#define PMIC_ACCDET_CON19                     (MT6355_PMIC_REG_BASE + 0x1C26)
#define PMIC_ACCDET_CON20                     (MT6355_PMIC_REG_BASE + 0x1C28)
#define PMIC_ACCDET_CON21                     (MT6355_PMIC_REG_BASE + 0x1C2A)
#define PMIC_ACCDET_CON22                     (MT6355_PMIC_REG_BASE + 0x1C2C)
#define PMIC_ACCDET_CON23                     (MT6355_PMIC_REG_BASE + 0x1C2E)
#define PMIC_ACCDET_CON24                     (MT6355_PMIC_REG_BASE + 0x1C30)
#define PMIC_OTP_CON0                         (MT6355_PMIC_REG_BASE + 0x1E00)
#define PMIC_OTP_CON1                         (MT6355_PMIC_REG_BASE + 0x1E02)
#define PMIC_OTP_CON2                         (MT6355_PMIC_REG_BASE + 0x1E04)
#define PMIC_OTP_CON3                         (MT6355_PMIC_REG_BASE + 0x1E06)
#define PMIC_OTP_CON4                         (MT6355_PMIC_REG_BASE + 0x1E08)
#define PMIC_OTP_CON5                         (MT6355_PMIC_REG_BASE + 0x1E0A)
#define PMIC_OTP_CON6                         (MT6355_PMIC_REG_BASE + 0x1E0C)
#define PMIC_OTP_CON7                         (MT6355_PMIC_REG_BASE + 0x1E0E)
#define PMIC_OTP_CON8                         (MT6355_PMIC_REG_BASE + 0x1E10)
#define PMIC_OTP_CON9                         (MT6355_PMIC_REG_BASE + 0x1E12)
#define PMIC_OTP_CON10                        (MT6355_PMIC_REG_BASE + 0x1E14)
#define PMIC_OTP_CON11                        (MT6355_PMIC_REG_BASE + 0x1E16)
#define PMIC_OTP_CON12                        (MT6355_PMIC_REG_BASE + 0x1E18)
#define PMIC_OTP_CON13                        (MT6355_PMIC_REG_BASE + 0x1E1A)
#define PMIC_OTP_CON14                        (MT6355_PMIC_REG_BASE + 0x1E1C)
#define PMIC_OTP_DOUT_0_15                    (MT6355_PMIC_REG_BASE + 0x1E1E)
#define PMIC_OTP_DOUT_16_31                   (MT6355_PMIC_REG_BASE + 0x1E20)
#define PMIC_OTP_DOUT_32_47                   (MT6355_PMIC_REG_BASE + 0x1E22)
#define PMIC_OTP_DOUT_48_63                   (MT6355_PMIC_REG_BASE + 0x1E24)
#define PMIC_OTP_DOUT_64_79                   (MT6355_PMIC_REG_BASE + 0x1E26)
#define PMIC_OTP_DOUT_80_95                   (MT6355_PMIC_REG_BASE + 0x1E28)
#define PMIC_OTP_DOUT_96_111                  (MT6355_PMIC_REG_BASE + 0x1E2A)
#define PMIC_OTP_DOUT_112_127                 (MT6355_PMIC_REG_BASE + 0x1E2C)
#define PMIC_OTP_DOUT_128_143                 (MT6355_PMIC_REG_BASE + 0x1E2E)
#define PMIC_OTP_DOUT_144_159                 (MT6355_PMIC_REG_BASE + 0x1E30)
#define PMIC_OTP_DOUT_160_175                 (MT6355_PMIC_REG_BASE + 0x1E32)
#define PMIC_OTP_DOUT_176_191                 (MT6355_PMIC_REG_BASE + 0x1E34)
#define PMIC_OTP_DOUT_192_207                 (MT6355_PMIC_REG_BASE + 0x1E36)
#define PMIC_OTP_DOUT_208_223                 (MT6355_PMIC_REG_BASE + 0x1E38)
#define PMIC_OTP_DOUT_224_239                 (MT6355_PMIC_REG_BASE + 0x1E3A)
#define PMIC_OTP_DOUT_240_255                 (MT6355_PMIC_REG_BASE + 0x1E3C)
#define PMIC_OTP_DOUT_256_271                 (MT6355_PMIC_REG_BASE + 0x1E3E)
#define PMIC_OTP_DOUT_272_287                 (MT6355_PMIC_REG_BASE + 0x1E40)
#define PMIC_OTP_DOUT_288_303                 (MT6355_PMIC_REG_BASE + 0x1E42)
#define PMIC_OTP_DOUT_304_319                 (MT6355_PMIC_REG_BASE + 0x1E44)
#define PMIC_OTP_DOUT_320_335                 (MT6355_PMIC_REG_BASE + 0x1E46)
#define PMIC_OTP_DOUT_336_351                 (MT6355_PMIC_REG_BASE + 0x1E48)
#define PMIC_OTP_DOUT_352_367                 (MT6355_PMIC_REG_BASE + 0x1E4A)
#define PMIC_OTP_DOUT_368_383                 (MT6355_PMIC_REG_BASE + 0x1E4C)
#define PMIC_OTP_DOUT_384_399                 (MT6355_PMIC_REG_BASE + 0x1E4E)
#define PMIC_OTP_DOUT_400_415                 (MT6355_PMIC_REG_BASE + 0x1E50)
#define PMIC_OTP_DOUT_416_431                 (MT6355_PMIC_REG_BASE + 0x1E52)
#define PMIC_OTP_DOUT_432_447                 (MT6355_PMIC_REG_BASE + 0x1E54)
#define PMIC_OTP_DOUT_448_463                 (MT6355_PMIC_REG_BASE + 0x1E56)
#define PMIC_OTP_DOUT_464_479                 (MT6355_PMIC_REG_BASE + 0x1E58)
#define PMIC_OTP_DOUT_480_495                 (MT6355_PMIC_REG_BASE + 0x1E5A)
#define PMIC_OTP_DOUT_496_511                 (MT6355_PMIC_REG_BASE + 0x1E5C)
#define PMIC_OTP_DOUT_512_527                 (MT6355_PMIC_REG_BASE + 0x1E5E)
#define PMIC_OTP_DOUT_528_543                 (MT6355_PMIC_REG_BASE + 0x1E60)
#define PMIC_OTP_DOUT_544_559                 (MT6355_PMIC_REG_BASE + 0x1E62)
#define PMIC_OTP_DOUT_560_575                 (MT6355_PMIC_REG_BASE + 0x1E64)
#define PMIC_OTP_DOUT_576_591                 (MT6355_PMIC_REG_BASE + 0x1E66)
#define PMIC_OTP_DOUT_592_607                 (MT6355_PMIC_REG_BASE + 0x1E68)
#define PMIC_OTP_DOUT_608_623                 (MT6355_PMIC_REG_BASE + 0x1E6A)
#define PMIC_OTP_DOUT_624_639                 (MT6355_PMIC_REG_BASE + 0x1E6C)
#define PMIC_OTP_DOUT_640_655                 (MT6355_PMIC_REG_BASE + 0x1E6E)
#define PMIC_OTP_DOUT_656_671                 (MT6355_PMIC_REG_BASE + 0x1E70)
#define PMIC_OTP_DOUT_672_687                 (MT6355_PMIC_REG_BASE + 0x1E72)
#define PMIC_OTP_DOUT_688_703                 (MT6355_PMIC_REG_BASE + 0x1E74)
#define PMIC_OTP_DOUT_704_719                 (MT6355_PMIC_REG_BASE + 0x1E76)
#define PMIC_OTP_DOUT_720_735                 (MT6355_PMIC_REG_BASE + 0x1E78)
#define PMIC_OTP_DOUT_736_751                 (MT6355_PMIC_REG_BASE + 0x1E7A)
#define PMIC_OTP_DOUT_752_767                 (MT6355_PMIC_REG_BASE + 0x1E7C)
#define PMIC_OTP_DOUT_768_783                 (MT6355_PMIC_REG_BASE + 0x1E7E)
#define PMIC_OTP_DOUT_784_799                 (MT6355_PMIC_REG_BASE + 0x1E80)
#define PMIC_OTP_DOUT_800_815                 (MT6355_PMIC_REG_BASE + 0x1E82)
#define PMIC_OTP_DOUT_816_831                 (MT6355_PMIC_REG_BASE + 0x1E84)
#define PMIC_OTP_DOUT_832_847                 (MT6355_PMIC_REG_BASE + 0x1E86)
#define PMIC_OTP_DOUT_848_863                 (MT6355_PMIC_REG_BASE + 0x1E88)
#define PMIC_OTP_DOUT_864_879                 (MT6355_PMIC_REG_BASE + 0x1E8A)
#define PMIC_OTP_DOUT_880_895                 (MT6355_PMIC_REG_BASE + 0x1E8C)
#define PMIC_OTP_DOUT_896_911                 (MT6355_PMIC_REG_BASE + 0x1E8E)
#define PMIC_OTP_DOUT_912_927                 (MT6355_PMIC_REG_BASE + 0x1E90)
#define PMIC_OTP_DOUT_928_943                 (MT6355_PMIC_REG_BASE + 0x1E92)
#define PMIC_OTP_DOUT_944_959                 (MT6355_PMIC_REG_BASE + 0x1E94)
#define PMIC_OTP_DOUT_960_975                 (MT6355_PMIC_REG_BASE + 0x1E96)
#define PMIC_OTP_DOUT_976_991                 (MT6355_PMIC_REG_BASE + 0x1E98)
#define PMIC_OTP_DOUT_992_1007                (MT6355_PMIC_REG_BASE + 0x1E9A)
#define PMIC_OTP_DOUT_1008_1023               (MT6355_PMIC_REG_BASE + 0x1E9C)
#define PMIC_OTP_DOUT_1024_1039               (MT6355_PMIC_REG_BASE + 0x1E9E)
#define PMIC_OTP_DOUT_1040_1055               (MT6355_PMIC_REG_BASE + 0x1EA0)
#define PMIC_OTP_DOUT_1056_1071               (MT6355_PMIC_REG_BASE + 0x1EA2)
#define PMIC_OTP_DOUT_1072_1087               (MT6355_PMIC_REG_BASE + 0x1EA4)
#define PMIC_OTP_DOUT_1088_1103               (MT6355_PMIC_REG_BASE + 0x1EA6)
#define PMIC_OTP_DOUT_1104_1119               (MT6355_PMIC_REG_BASE + 0x1EA8)
#define PMIC_OTP_DOUT_1120_1135               (MT6355_PMIC_REG_BASE + 0x1EAA)
#define PMIC_OTP_DOUT_1136_1151               (MT6355_PMIC_REG_BASE + 0x1EAC)
#define PMIC_OTP_DOUT_1152_1167               (MT6355_PMIC_REG_BASE + 0x1EAE)
#define PMIC_OTP_DOUT_1168_1183               (MT6355_PMIC_REG_BASE + 0x1EB0)
#define PMIC_OTP_DOUT_1184_1199               (MT6355_PMIC_REG_BASE + 0x1EB2)
#define PMIC_OTP_DOUT_1200_1215               (MT6355_PMIC_REG_BASE + 0x1EB4)
#define PMIC_OTP_DOUT_1216_1231               (MT6355_PMIC_REG_BASE + 0x1EB6)
#define PMIC_OTP_DOUT_1232_1247               (MT6355_PMIC_REG_BASE + 0x1EB8)
#define PMIC_OTP_DOUT_1248_1263               (MT6355_PMIC_REG_BASE + 0x1EBA)
#define PMIC_OTP_DOUT_1264_1279               (MT6355_PMIC_REG_BASE + 0x1EBC)
#define PMIC_OTP_DOUT_1280_1295               (MT6355_PMIC_REG_BASE + 0x1EBE)
#define PMIC_OTP_DOUT_1296_1311               (MT6355_PMIC_REG_BASE + 0x1EC0)
#define PMIC_OTP_DOUT_1312_1327               (MT6355_PMIC_REG_BASE + 0x1EC2)
#define PMIC_OTP_DOUT_1328_1343               (MT6355_PMIC_REG_BASE + 0x1EC4)
#define PMIC_OTP_DOUT_1344_1359               (MT6355_PMIC_REG_BASE + 0x1EC6)
#define PMIC_OTP_DOUT_1360_1375               (MT6355_PMIC_REG_BASE + 0x1EC8)
#define PMIC_OTP_DOUT_1376_1391               (MT6355_PMIC_REG_BASE + 0x1ECA)
#define PMIC_OTP_DOUT_1392_1407               (MT6355_PMIC_REG_BASE + 0x1ECC)
#define PMIC_OTP_DOUT_1408_1423               (MT6355_PMIC_REG_BASE + 0x1ECE)
#define PMIC_OTP_DOUT_1424_1439               (MT6355_PMIC_REG_BASE + 0x1ED0)
#define PMIC_OTP_DOUT_1440_1455               (MT6355_PMIC_REG_BASE + 0x1ED2)
#define PMIC_OTP_DOUT_1456_1471               (MT6355_PMIC_REG_BASE + 0x1ED4)
#define PMIC_OTP_DOUT_1472_1487               (MT6355_PMIC_REG_BASE + 0x1ED6)
#define PMIC_OTP_DOUT_1488_1503               (MT6355_PMIC_REG_BASE + 0x1ED8)
#define PMIC_OTP_DOUT_1504_1519               (MT6355_PMIC_REG_BASE + 0x1EDA)
#define PMIC_OTP_DOUT_1520_1535               (MT6355_PMIC_REG_BASE + 0x1EDC)
#define PMIC_OTP_VAL_0_15                     (MT6355_PMIC_REG_BASE + 0x1EDE)
#define PMIC_OTP_VAL_16_31                    (MT6355_PMIC_REG_BASE + 0x1EE0)
#define PMIC_OTP_VAL_32_47                    (MT6355_PMIC_REG_BASE + 0x1EE2)
#define PMIC_OTP_VAL_48_63                    (MT6355_PMIC_REG_BASE + 0x1EE4)
#define PMIC_OTP_VAL_64_79                    (MT6355_PMIC_REG_BASE + 0x1EE6)
#define PMIC_OTP_VAL_80_95                    (MT6355_PMIC_REG_BASE + 0x1EE8)
#define PMIC_OTP_VAL_96_111                   (MT6355_PMIC_REG_BASE + 0x1EEA)
#define PMIC_OTP_VAL_112_127                  (MT6355_PMIC_REG_BASE + 0x1EEC)
#define PMIC_OTP_VAL_128_143                  (MT6355_PMIC_REG_BASE + 0x1EEE)
#define PMIC_OTP_VAL_144_159                  (MT6355_PMIC_REG_BASE + 0x1EF0)
#define PMIC_OTP_VAL_160_175                  (MT6355_PMIC_REG_BASE + 0x1EF2)
#define PMIC_OTP_VAL_176_191                  (MT6355_PMIC_REG_BASE + 0x1EF4)
#define PMIC_OTP_VAL_192_207                  (MT6355_PMIC_REG_BASE + 0x1EF6)
#define PMIC_OTP_VAL_208_223                  (MT6355_PMIC_REG_BASE + 0x1EF8)
#define PMIC_OTP_VAL_224_239                  (MT6355_PMIC_REG_BASE + 0x1EFA)
#define PMIC_OTP_VAL_240_255                  (MT6355_PMIC_REG_BASE + 0x1EFC)
#define PMIC_OTP_VAL_256_271                  (MT6355_PMIC_REG_BASE + 0x1EFE)
#define PMIC_OTP_VAL_272_287                  (MT6355_PMIC_REG_BASE + 0x1F00)
#define PMIC_OTP_VAL_288_303                  (MT6355_PMIC_REG_BASE + 0x1F02)
#define PMIC_OTP_VAL_304_319                  (MT6355_PMIC_REG_BASE + 0x1F04)
#define PMIC_OTP_VAL_320_335                  (MT6355_PMIC_REG_BASE + 0x1F06)
#define PMIC_OTP_VAL_336_351                  (MT6355_PMIC_REG_BASE + 0x1F08)
#define PMIC_OTP_VAL_352_367                  (MT6355_PMIC_REG_BASE + 0x1F0A)
#define PMIC_OTP_VAL_368_383                  (MT6355_PMIC_REG_BASE + 0x1F0C)
#define PMIC_OTP_VAL_384_399                  (MT6355_PMIC_REG_BASE + 0x1F0E)
#define PMIC_OTP_VAL_400_415                  (MT6355_PMIC_REG_BASE + 0x1F10)
#define PMIC_OTP_VAL_416_431                  (MT6355_PMIC_REG_BASE + 0x1F12)
#define PMIC_OTP_VAL_432_447                  (MT6355_PMIC_REG_BASE + 0x1F14)
#define PMIC_OTP_VAL_448_463                  (MT6355_PMIC_REG_BASE + 0x1F16)
#define PMIC_OTP_VAL_464_479                  (MT6355_PMIC_REG_BASE + 0x1F18)
#define PMIC_OTP_VAL_480_495                  (MT6355_PMIC_REG_BASE + 0x1F1A)
#define PMIC_OTP_VAL_496_511                  (MT6355_PMIC_REG_BASE + 0x1F1C)
#define PMIC_OTP_VAL_512_527                  (MT6355_PMIC_REG_BASE + 0x1F1E)
#define PMIC_OTP_VAL_528_543                  (MT6355_PMIC_REG_BASE + 0x1F20)
#define PMIC_OTP_VAL_544_559                  (MT6355_PMIC_REG_BASE + 0x1F22)
#define PMIC_OTP_VAL_560_575                  (MT6355_PMIC_REG_BASE + 0x1F24)
#define PMIC_OTP_VAL_576_591                  (MT6355_PMIC_REG_BASE + 0x1F26)
#define PMIC_OTP_VAL_592_607                  (MT6355_PMIC_REG_BASE + 0x1F28)
#define PMIC_OTP_VAL_608_623                  (MT6355_PMIC_REG_BASE + 0x1F2A)
#define PMIC_OTP_VAL_624_639                  (MT6355_PMIC_REG_BASE + 0x1F2C)
#define PMIC_OTP_VAL_640_655                  (MT6355_PMIC_REG_BASE + 0x1F2E)
#define PMIC_OTP_VAL_656_671                  (MT6355_PMIC_REG_BASE + 0x1F30)
#define PMIC_OTP_VAL_672_687                  (MT6355_PMIC_REG_BASE + 0x1F32)
#define PMIC_OTP_VAL_688_703                  (MT6355_PMIC_REG_BASE + 0x1F34)
#define PMIC_OTP_VAL_704_719                  (MT6355_PMIC_REG_BASE + 0x1F36)
#define PMIC_OTP_VAL_720_735                  (MT6355_PMIC_REG_BASE + 0x1F38)
#define PMIC_OTP_VAL_736_751                  (MT6355_PMIC_REG_BASE + 0x1F3A)
#define PMIC_OTP_VAL_752_767                  (MT6355_PMIC_REG_BASE + 0x1F3C)
#define PMIC_OTP_VAL_768_783                  (MT6355_PMIC_REG_BASE + 0x1F3E)
#define PMIC_OTP_VAL_784_799                  (MT6355_PMIC_REG_BASE + 0x1F40)
#define PMIC_OTP_VAL_800_815                  (MT6355_PMIC_REG_BASE + 0x1F42)
#define PMIC_OTP_VAL_816_831                  (MT6355_PMIC_REG_BASE + 0x1F44)
#define PMIC_OTP_VAL_832_847                  (MT6355_PMIC_REG_BASE + 0x1F46)
#define PMIC_OTP_VAL_848_863                  (MT6355_PMIC_REG_BASE + 0x1F48)
#define PMIC_OTP_VAL_864_879                  (MT6355_PMIC_REG_BASE + 0x1F4A)
#define PMIC_OTP_VAL_880_895                  (MT6355_PMIC_REG_BASE + 0x1F4C)
#define PMIC_OTP_VAL_896_911                  (MT6355_PMIC_REG_BASE + 0x1F4E)
#define PMIC_OTP_VAL_912_927                  (MT6355_PMIC_REG_BASE + 0x1F50)
#define PMIC_OTP_VAL_928_943                  (MT6355_PMIC_REG_BASE + 0x1F52)
#define PMIC_OTP_VAL_944_959                  (MT6355_PMIC_REG_BASE + 0x1F54)
#define PMIC_OTP_VAL_960_975                  (MT6355_PMIC_REG_BASE + 0x1F56)
#define PMIC_OTP_VAL_976_991                  (MT6355_PMIC_REG_BASE + 0x1F58)
#define PMIC_OTP_VAL_992_1007                 (MT6355_PMIC_REG_BASE + 0x1F5A)
#define PMIC_OTP_VAL_1008_1023                (MT6355_PMIC_REG_BASE + 0x1F5C)
#define PMIC_OTP_VAL_1024_1039                (MT6355_PMIC_REG_BASE + 0x1F5E)
#define PMIC_OTP_VAL_1040_1055                (MT6355_PMIC_REG_BASE + 0x1F60)
#define PMIC_OTP_VAL_1056_1071                (MT6355_PMIC_REG_BASE + 0x1F62)
#define PMIC_OTP_VAL_1072_1087                (MT6355_PMIC_REG_BASE + 0x1F64)
#define PMIC_OTP_VAL_1088_1103                (MT6355_PMIC_REG_BASE + 0x1F66)
#define PMIC_OTP_VAL_1104_1119                (MT6355_PMIC_REG_BASE + 0x1F68)
#define PMIC_OTP_VAL_1120_1135                (MT6355_PMIC_REG_BASE + 0x1F6A)
#define PMIC_OTP_VAL_1136_1151                (MT6355_PMIC_REG_BASE + 0x1F6C)
#define PMIC_OTP_VAL_1152_1167                (MT6355_PMIC_REG_BASE + 0x1F6E)
#define PMIC_OTP_VAL_1168_1183                (MT6355_PMIC_REG_BASE + 0x1F70)
#define PMIC_OTP_VAL_1184_1199                (MT6355_PMIC_REG_BASE + 0x1F72)
#define PMIC_OTP_VAL_1200_1215                (MT6355_PMIC_REG_BASE + 0x1F74)
#define PMIC_OTP_VAL_1216_1231                (MT6355_PMIC_REG_BASE + 0x1F76)
#define PMIC_OTP_VAL_1232_1247                (MT6355_PMIC_REG_BASE + 0x1F78)
#define PMIC_OTP_VAL_1248_1263                (MT6355_PMIC_REG_BASE + 0x1F7A)
#define PMIC_OTP_VAL_1264_1279                (MT6355_PMIC_REG_BASE + 0x1F7C)
#define PMIC_OTP_VAL_1280_1295                (MT6355_PMIC_REG_BASE + 0x1F7E)
#define PMIC_OTP_VAL_1296_1311                (MT6355_PMIC_REG_BASE + 0x1F80)
#define PMIC_OTP_VAL_1312_1327                (MT6355_PMIC_REG_BASE + 0x1F82)
#define PMIC_OTP_VAL_1328_1343                (MT6355_PMIC_REG_BASE + 0x1F84)
#define PMIC_OTP_VAL_1344_1359                (MT6355_PMIC_REG_BASE + 0x1F86)
#define PMIC_OTP_VAL_1360_1375                (MT6355_PMIC_REG_BASE + 0x1F88)
#define PMIC_OTP_VAL_1376_1391                (MT6355_PMIC_REG_BASE + 0x1F8A)
#define PMIC_OTP_VAL_1392_1407                (MT6355_PMIC_REG_BASE + 0x1F8C)
#define PMIC_OTP_VAL_1408_1423                (MT6355_PMIC_REG_BASE + 0x1F8E)
#define PMIC_OTP_VAL_1424_1439                (MT6355_PMIC_REG_BASE + 0x1F90)
#define PMIC_OTP_VAL_1440_1455                (MT6355_PMIC_REG_BASE + 0x1F92)
#define PMIC_OTP_VAL_1456_1471                (MT6355_PMIC_REG_BASE + 0x1F94)
#define PMIC_OTP_VAL_1472_1487                (MT6355_PMIC_REG_BASE + 0x1F96)
#define PMIC_OTP_VAL_1488_1503                (MT6355_PMIC_REG_BASE + 0x1F98)
#define PMIC_OTP_VAL_1504_1519                (MT6355_PMIC_REG_BASE + 0x1F9A)
#define PMIC_OTP_VAL_1520_1535                (MT6355_PMIC_REG_BASE + 0x1F9C)
#define PMIC_DCXO_CW00                        (MT6355_PMIC_REG_BASE + 0x2000)
#define PMIC_DCXO_CW00_SET                    (MT6355_PMIC_REG_BASE + 0x2002)
#define PMIC_DCXO_CW00_CLR                    (MT6355_PMIC_REG_BASE + 0x2004)
#define PMIC_DCXO_CW01                        (MT6355_PMIC_REG_BASE + 0x2006)
#define PMIC_DCXO_CW02                        (MT6355_PMIC_REG_BASE + 0x2008)
#define PMIC_DCXO_CW03                        (MT6355_PMIC_REG_BASE + 0x200A)
#define PMIC_DCXO_CW04                        (MT6355_PMIC_REG_BASE + 0x200C)
#define PMIC_DCXO_CW05                        (MT6355_PMIC_REG_BASE + 0x200E)
#define PMIC_DCXO_CW06                        (MT6355_PMIC_REG_BASE + 0x2010)
#define PMIC_DCXO_CW07                        (MT6355_PMIC_REG_BASE + 0x2012)
#define PMIC_DCXO_CW08                        (MT6355_PMIC_REG_BASE + 0x2014)
#define PMIC_DCXO_CW09                        (MT6355_PMIC_REG_BASE + 0x2016)
#define PMIC_DCXO_CW10                        (MT6355_PMIC_REG_BASE + 0x2018)
#define PMIC_DCXO_CW11                        (MT6355_PMIC_REG_BASE + 0x201A)
#define PMIC_DCXO_CW11_SET                    (MT6355_PMIC_REG_BASE + 0x201C)
#define PMIC_DCXO_CW11_CLR                    (MT6355_PMIC_REG_BASE + 0x201E)
#define PMIC_DCXO_CW12                        (MT6355_PMIC_REG_BASE + 0x2020)
#define PMIC_DCXO_CW13                        (MT6355_PMIC_REG_BASE + 0x2022)
#define PMIC_DCXO_CW14                        (MT6355_PMIC_REG_BASE + 0x2024)
#define PMIC_DCXO_CW15                        (MT6355_PMIC_REG_BASE + 0x2026)
#define PMIC_DCXO_CW16                        (MT6355_PMIC_REG_BASE + 0x2028)
#define PMIC_DCXO_CW17                        (MT6355_PMIC_REG_BASE + 0x202A)
#define PMIC_DCXO_CW18                        (MT6355_PMIC_REG_BASE + 0x202C)
#define PMIC_DCXO_CW19                        (MT6355_PMIC_REG_BASE + 0x202E)
#define PMIC_DCXO_CW20                        (MT6355_PMIC_REG_BASE + 0x2030)
#define PMIC_DCXO_CW21                        (MT6355_PMIC_REG_BASE + 0x2032)
#define PMIC_DCXO_CW22                        (MT6355_PMIC_REG_BASE + 0x2034)
#define PMIC_CHR_CON0                         (MT6355_PMIC_REG_BASE + 0x2200)
#define PMIC_CHR_CON1                         (MT6355_PMIC_REG_BASE + 0x2202)
#define PMIC_CHR_CON2                         (MT6355_PMIC_REG_BASE + 0x2204)
#define PMIC_CHR_CON3                         (MT6355_PMIC_REG_BASE + 0x2206)
#define PMIC_CHR_CON4                         (MT6355_PMIC_REG_BASE + 0x2208)
#define PMIC_CHR_CON5                         (MT6355_PMIC_REG_BASE + 0x220A)
#define PMIC_CHR_CON6                         (MT6355_PMIC_REG_BASE + 0x220C)
#define PMIC_CHR_CON7                         (MT6355_PMIC_REG_BASE + 0x220E)
#define PMIC_PCHR_VREF_ANA_DA0                (MT6355_PMIC_REG_BASE + 0x2210)
#define PMIC_PCHR_VREF_ANA_CON0               (MT6355_PMIC_REG_BASE + 0x2212)
#define PMIC_PCHR_VREF_ANA_CON1               (MT6355_PMIC_REG_BASE + 0x2214)
#define PMIC_PCHR_VREF_ANA_CON2               (MT6355_PMIC_REG_BASE + 0x2216)
#define PMIC_PCHR_VREF_ANA_CON3               (MT6355_PMIC_REG_BASE + 0x2218)
#define PMIC_GPIO_DIR0                        (MT6355_PMIC_REG_BASE + 0x2400)
#define PMIC_GPIO_DIR0_SET                    (MT6355_PMIC_REG_BASE + 0x2402)
#define PMIC_GPIO_DIR0_CLR                    (MT6355_PMIC_REG_BASE + 0x2404)
#define PMIC_GPIO_PULLEN0                     (MT6355_PMIC_REG_BASE + 0x2406)
#define PMIC_GPIO_PULLEN0_SET                 (MT6355_PMIC_REG_BASE + 0x2408)
#define PMIC_GPIO_PULLEN0_CLR                 (MT6355_PMIC_REG_BASE + 0x240A)
#define PMIC_GPIO_PULLSEL0                    (MT6355_PMIC_REG_BASE + 0x240C)
#define PMIC_GPIO_PULLSEL0_SET                (MT6355_PMIC_REG_BASE + 0x240E)
#define PMIC_GPIO_PULLSEL0_CLR                (MT6355_PMIC_REG_BASE + 0x2410)
#define PMIC_GPIO_DINV0                       (MT6355_PMIC_REG_BASE + 0x2412)
#define PMIC_GPIO_DINV0_SET                   (MT6355_PMIC_REG_BASE + 0x2414)
#define PMIC_GPIO_DINV0_CLR                   (MT6355_PMIC_REG_BASE + 0x2416)
#define PMIC_GPIO_DOUT0                       (MT6355_PMIC_REG_BASE + 0x2418)
#define PMIC_GPIO_DOUT0_SET                   (MT6355_PMIC_REG_BASE + 0x241A)
#define PMIC_GPIO_DOUT0_CLR                   (MT6355_PMIC_REG_BASE + 0x241C)
#define PMIC_GPIO_PI0                         (MT6355_PMIC_REG_BASE + 0x241E)
#define PMIC_GPIO_POE0                        (MT6355_PMIC_REG_BASE + 0x2420)
#define PMIC_GPIO_MODE0                       (MT6355_PMIC_REG_BASE + 0x2422)
#define PMIC_GPIO_MODE0_SET                   (MT6355_PMIC_REG_BASE + 0x2424)
#define PMIC_GPIO_MODE0_CLR                   (MT6355_PMIC_REG_BASE + 0x2426)
#define PMIC_GPIO_MODE1                       (MT6355_PMIC_REG_BASE + 0x2428)
#define PMIC_GPIO_MODE1_SET                   (MT6355_PMIC_REG_BASE + 0x242A)
#define PMIC_GPIO_MODE1_CLR                   (MT6355_PMIC_REG_BASE + 0x242C)
#define PMIC_GPIO_MODE2                       (MT6355_PMIC_REG_BASE + 0x242E)
#define PMIC_GPIO_MODE2_SET                   (MT6355_PMIC_REG_BASE + 0x2430)
#define PMIC_GPIO_MODE2_CLR                   (MT6355_PMIC_REG_BASE + 0x2432)
#define PMIC_GPIO_RSV                         (MT6355_PMIC_REG_BASE + 0x2434)
#define PMIC_RTC_SEC_DUMMY_CON0               (MT6355_PMIC_REG_BASE + 0x2600)
#define PMIC_RTC_DUMMY_CON0                   (MT6355_PMIC_REG_BASE + 0x2800)
#define PMIC_EOSC_CALI_CON0                   (MT6355_PMIC_REG_BASE + 0x2A00)
#define PMIC_EOSC_CALI_CON1                   (MT6355_PMIC_REG_BASE + 0x2A02)
#define PMIC_RTC_MIX_CON0                     (MT6355_PMIC_REG_BASE + 0x2A04)
#define PMIC_RTC_MIX_CON1                     (MT6355_PMIC_REG_BASE + 0x2A06)
#define PMIC_RTC_MIX_CON2                     (MT6355_PMIC_REG_BASE + 0x2A08)
#define PMIC_VRTC_PWM_CON0                    (MT6355_PMIC_REG_BASE + 0x2C00)
#define PMIC_BIF_CON0                         (MT6355_PMIC_REG_BASE + 0x2E00)
#define PMIC_BIF_CON1                         (MT6355_PMIC_REG_BASE + 0x2E02)
#define PMIC_BIF_CON2                         (MT6355_PMIC_REG_BASE + 0x2E04)
#define PMIC_BIF_CON3                         (MT6355_PMIC_REG_BASE + 0x2E06)
#define PMIC_BIF_CON4                         (MT6355_PMIC_REG_BASE + 0x2E08)
#define PMIC_BIF_CON5                         (MT6355_PMIC_REG_BASE + 0x2E0A)
#define PMIC_BIF_CON6                         (MT6355_PMIC_REG_BASE + 0x2E0C)
#define PMIC_BIF_CON7                         (MT6355_PMIC_REG_BASE + 0x2E0E)
#define PMIC_BIF_CON8                         (MT6355_PMIC_REG_BASE + 0x2E10)
#define PMIC_BIF_CON9                         (MT6355_PMIC_REG_BASE + 0x2E12)
#define PMIC_BIF_CON10                        (MT6355_PMIC_REG_BASE + 0x2E14)
#define PMIC_BIF_CON11                        (MT6355_PMIC_REG_BASE + 0x2E16)
#define PMIC_BIF_CON12                        (MT6355_PMIC_REG_BASE + 0x2E18)
#define PMIC_BIF_CON13                        (MT6355_PMIC_REG_BASE + 0x2E1A)
#define PMIC_BIF_CON14                        (MT6355_PMIC_REG_BASE + 0x2E1C)
#define PMIC_BIF_CON15                        (MT6355_PMIC_REG_BASE + 0x2E1E)
#define PMIC_BIF_CON16                        (MT6355_PMIC_REG_BASE + 0x2E20)
#define PMIC_BIF_CON17                        (MT6355_PMIC_REG_BASE + 0x2E22)
#define PMIC_BIF_CON18                        (MT6355_PMIC_REG_BASE + 0x2E24)
#define PMIC_BIF_CON19                        (MT6355_PMIC_REG_BASE + 0x2E26)
#define PMIC_BIF_CON20                        (MT6355_PMIC_REG_BASE + 0x2E28)
#define PMIC_BIF_CON21                        (MT6355_PMIC_REG_BASE + 0x2E2A)
#define PMIC_BIF_CON22                        (MT6355_PMIC_REG_BASE + 0x2E2C)
#define PMIC_BIF_CON23                        (MT6355_PMIC_REG_BASE + 0x2E2E)
#define PMIC_BIF_CON24                        (MT6355_PMIC_REG_BASE + 0x2E30)
#define PMIC_BIF_CON25                        (MT6355_PMIC_REG_BASE + 0x2E32)
#define PMIC_BIF_CON26                        (MT6355_PMIC_REG_BASE + 0x2E34)
#define PMIC_BIF_CON27                        (MT6355_PMIC_REG_BASE + 0x2E36)
#define PMIC_BIF_CON28                        (MT6355_PMIC_REG_BASE + 0x2E38)
#define PMIC_BIF_CON29                        (MT6355_PMIC_REG_BASE + 0x2E3A)
#define PMIC_BIF_CON30                        (MT6355_PMIC_REG_BASE + 0x2E3C)
#define PMIC_BIF_CON31                        (MT6355_PMIC_REG_BASE + 0x2E3E)
#define PMIC_BIF_CON32                        (MT6355_PMIC_REG_BASE + 0x2E40)
#define PMIC_BIF_CON33                        (MT6355_PMIC_REG_BASE + 0x2E42)
#define PMIC_BIF_CON34                        (MT6355_PMIC_REG_BASE + 0x2E44)
#define PMIC_BIF_CON35                        (MT6355_PMIC_REG_BASE + 0x2E46)
#define PMIC_BIF_CON36                        (MT6355_PMIC_REG_BASE + 0x2E48)
#define PMIC_BIF_CON37                        (MT6355_PMIC_REG_BASE + 0x2E4A)
#define PMIC_BIF_CON38                        (MT6355_PMIC_REG_BASE + 0x2E4C)
#define PMIC_BIF_CON39                        (MT6355_PMIC_REG_BASE + 0x2E4E)
#define PMIC_BIF_BAT_CON0                     (MT6355_PMIC_REG_BASE + 0x2E50)
#define PMIC_BIF_BAT_CON1                     (MT6355_PMIC_REG_BASE + 0x2E52)
#define PMIC_BIF_BAT_CON2                     (MT6355_PMIC_REG_BASE + 0x2E54)
#define PMIC_BIF_BAT_CON3                     (MT6355_PMIC_REG_BASE + 0x2E56)
#define PMIC_BIF_ANA_CON0                     (MT6355_PMIC_REG_BASE + 0x2E58)
#define PMIC_FGADC_CON0                       (MT6355_PMIC_REG_BASE + 0x3000)
#define PMIC_FGADC_CON1                       (MT6355_PMIC_REG_BASE + 0x3002)
#define PMIC_FGADC_CON2                       (MT6355_PMIC_REG_BASE + 0x3004)
#define PMIC_FGADC_CON3                       (MT6355_PMIC_REG_BASE + 0x3006)
#define PMIC_FGADC_CON4                       (MT6355_PMIC_REG_BASE + 0x3008)
#define PMIC_FGADC_RST_CON0                   (MT6355_PMIC_REG_BASE + 0x300A)
#define PMIC_FGADC_R_CON0                     (MT6355_PMIC_REG_BASE + 0x300C)
#define PMIC_FGADC_CUR_CON0                   (MT6355_PMIC_REG_BASE + 0x300E)
#define PMIC_FGADC_CUR_CON1                   (MT6355_PMIC_REG_BASE + 0x3010)
#define PMIC_FGADC_CUR_CON2                   (MT6355_PMIC_REG_BASE + 0x3012)
#define PMIC_FGADC_CUR_CON3                   (MT6355_PMIC_REG_BASE + 0x3014)
#define PMIC_FGADC_CAR_CON0                   (MT6355_PMIC_REG_BASE + 0x3016)
#define PMIC_FGADC_CAR_CON1                   (MT6355_PMIC_REG_BASE + 0x3018)
#define PMIC_FGADC_CAR_CON2                   (MT6355_PMIC_REG_BASE + 0x301A)
#define PMIC_FGADC_CAR_CON3                   (MT6355_PMIC_REG_BASE + 0x301C)
#define PMIC_FGADC_CAR_CON4                   (MT6355_PMIC_REG_BASE + 0x301E)
#define PMIC_FGADC_CAR_CON5                   (MT6355_PMIC_REG_BASE + 0x3020)
#define PMIC_FGADC_CAR_CON6                   (MT6355_PMIC_REG_BASE + 0x3022)
#define PMIC_FGADC_CAR_CON7                   (MT6355_PMIC_REG_BASE + 0x3024)
#define PMIC_FGADC_CAR_CON8                   (MT6355_PMIC_REG_BASE + 0x3026)
#define PMIC_FGADC_CAR_CON9                   (MT6355_PMIC_REG_BASE + 0x3028)
#define PMIC_FGADC_NCAR_CON0                  (MT6355_PMIC_REG_BASE + 0x302A)
#define PMIC_FGADC_NCAR_CON1                  (MT6355_PMIC_REG_BASE + 0x302C)
#define PMIC_FGADC_NCAR_CON2                  (MT6355_PMIC_REG_BASE + 0x302E)
#define PMIC_FGADC_NCAR_CON3                  (MT6355_PMIC_REG_BASE + 0x3030)
#define PMIC_FGADC_IAVG_CON0                  (MT6355_PMIC_REG_BASE + 0x3032)
#define PMIC_FGADC_IAVG_CON1                  (MT6355_PMIC_REG_BASE + 0x3034)
#define PMIC_FGADC_IAVG_CON2                  (MT6355_PMIC_REG_BASE + 0x3036)
#define PMIC_FGADC_IAVG_CON3                  (MT6355_PMIC_REG_BASE + 0x3038)
#define PMIC_FGADC_IAVG_CON4                  (MT6355_PMIC_REG_BASE + 0x303A)
#define PMIC_FGADC_IAVG_CON5                  (MT6355_PMIC_REG_BASE + 0x303C)
#define PMIC_FGADC_NTER_CON0                  (MT6355_PMIC_REG_BASE + 0x303E)
#define PMIC_FGADC_NTER_CON1                  (MT6355_PMIC_REG_BASE + 0x3040)
#define PMIC_FGADC_NTER_CON2                  (MT6355_PMIC_REG_BASE + 0x3042)
#define PMIC_FGADC_NTER_CON3                  (MT6355_PMIC_REG_BASE + 0x3044)
#define PMIC_FGADC_OFFSET_CON0                (MT6355_PMIC_REG_BASE + 0x3046)
#define PMIC_FGADC_OFFSET_CON1                (MT6355_PMIC_REG_BASE + 0x3048)
#define PMIC_FGADC_GAIN_CON0                  (MT6355_PMIC_REG_BASE + 0x304A)
#define PMIC_FGADC_SON_CON0                   (MT6355_PMIC_REG_BASE + 0x304C)
#define PMIC_FGADC_SON_CON1                   (MT6355_PMIC_REG_BASE + 0x304E)
#define PMIC_FGADC_SON_CON2                   (MT6355_PMIC_REG_BASE + 0x3050)
#define PMIC_FGADC_SON_CON3                   (MT6355_PMIC_REG_BASE + 0x3052)
#define PMIC_FGADC_SOFF_CON0                  (MT6355_PMIC_REG_BASE + 0x3054)
#define PMIC_FGADC_SOFF_CON1                  (MT6355_PMIC_REG_BASE + 0x3056)
#define PMIC_FGADC_SOFF_CON2                  (MT6355_PMIC_REG_BASE + 0x3058)
#define PMIC_FGADC_SOFF_CON3                  (MT6355_PMIC_REG_BASE + 0x305A)
#define PMIC_FGADC_SOFF_CON4                  (MT6355_PMIC_REG_BASE + 0x305C)
#define PMIC_FGADC_PWR_CON0                   (MT6355_PMIC_REG_BASE + 0x305E)
#define PMIC_FGADC_PWR_CON1                   (MT6355_PMIC_REG_BASE + 0x3060)
#define PMIC_FGADC_ZCV_CON0                   (MT6355_PMIC_REG_BASE + 0x3062)
#define PMIC_FGADC_ZCV_CON1                   (MT6355_PMIC_REG_BASE + 0x3064)
#define PMIC_FGADC_ZCV_CON2                   (MT6355_PMIC_REG_BASE + 0x3066)
#define PMIC_FGADC_ZCV_CON3                   (MT6355_PMIC_REG_BASE + 0x3068)
#define PMIC_FGADC_ZCV_CON4                   (MT6355_PMIC_REG_BASE + 0x306A)
#define PMIC_FGADC_ZCV_CON5                   (MT6355_PMIC_REG_BASE + 0x306C)
#define PMIC_FGADC_ANA_CON0                   (MT6355_PMIC_REG_BASE + 0x306E)
#define PMIC_FGADC_ANA_CON1                   (MT6355_PMIC_REG_BASE + 0x3070)
#define PMIC_FGADC_TEST_CON0                  (MT6355_PMIC_REG_BASE + 0x3072)
#define PMIC_FGADC_RSV_CON0                   (MT6355_PMIC_REG_BASE + 0x3074)
#define PMIC_FGADC_RSV_CON1                   (MT6355_PMIC_REG_BASE + 0x3076)
#define PMIC_FGADC_RSV_CON2                   (MT6355_PMIC_REG_BASE + 0x3078)
#define PMIC_FGADC_RSV_CON3                   (MT6355_PMIC_REG_BASE + 0x307A)
#define PMIC_SYSTEM_INFO_CON0                 (MT6355_PMIC_REG_BASE + 0x307C)
#define PMIC_SYSTEM_INFO_CON1                 (MT6355_PMIC_REG_BASE + 0x307E)
#define PMIC_SYSTEM_INFO_CON2                 (MT6355_PMIC_REG_BASE + 0x3080)
#define PMIC_SYSTEM_INFO_CON3                 (MT6355_PMIC_REG_BASE + 0x3082)
#define PMIC_SYSTEM_INFO_CON4                 (MT6355_PMIC_REG_BASE + 0x3084)
#define PMIC_FGADC_EFUSE_CON0                 (MT6355_PMIC_REG_BASE + 0x3086)
#define PMIC_AUXADC_ADC0                      (MT6355_PMIC_REG_BASE + 0x3200)
#define PMIC_AUXADC_ADC1                      (MT6355_PMIC_REG_BASE + 0x3202)
#define PMIC_AUXADC_ADC2                      (MT6355_PMIC_REG_BASE + 0x3204)
#define PMIC_AUXADC_ADC3                      (MT6355_PMIC_REG_BASE + 0x3206)
#define PMIC_AUXADC_ADC4                      (MT6355_PMIC_REG_BASE + 0x3208)
#define PMIC_AUXADC_ADC5                      (MT6355_PMIC_REG_BASE + 0x320A)
#define PMIC_AUXADC_ADC6                      (MT6355_PMIC_REG_BASE + 0x320C)
#define PMIC_AUXADC_ADC7                      (MT6355_PMIC_REG_BASE + 0x320E)
#define PMIC_AUXADC_ADC8                      (MT6355_PMIC_REG_BASE + 0x3210)
#define PMIC_AUXADC_ADC9                      (MT6355_PMIC_REG_BASE + 0x3212)
#define PMIC_AUXADC_ADC10                     (MT6355_PMIC_REG_BASE + 0x3214)
#define PMIC_AUXADC_ADC11                     (MT6355_PMIC_REG_BASE + 0x3216)
#define PMIC_AUXADC_ADC12                     (MT6355_PMIC_REG_BASE + 0x3218)
#define PMIC_AUXADC_ADC13                     (MT6355_PMIC_REG_BASE + 0x321A)
#define PMIC_AUXADC_ADC14                     (MT6355_PMIC_REG_BASE + 0x321C)
#define PMIC_AUXADC_ADC15                     (MT6355_PMIC_REG_BASE + 0x321E)
#define PMIC_AUXADC_ADC16                     (MT6355_PMIC_REG_BASE + 0x3220)
#define PMIC_AUXADC_ADC17                     (MT6355_PMIC_REG_BASE + 0x3222)
#define PMIC_AUXADC_ADC18                     (MT6355_PMIC_REG_BASE + 0x3224)
#define PMIC_AUXADC_ADC19                     (MT6355_PMIC_REG_BASE + 0x3226)
#define PMIC_AUXADC_ADC20                     (MT6355_PMIC_REG_BASE + 0x3228)
#define PMIC_AUXADC_ADC21                     (MT6355_PMIC_REG_BASE + 0x322A)
#define PMIC_AUXADC_ADC22                     (MT6355_PMIC_REG_BASE + 0x322C)
#define PMIC_AUXADC_ADC23                     (MT6355_PMIC_REG_BASE + 0x322E)
#define PMIC_AUXADC_ADC24                     (MT6355_PMIC_REG_BASE + 0x3230)
#define PMIC_AUXADC_ADC25                     (MT6355_PMIC_REG_BASE + 0x3232)
#define PMIC_AUXADC_ADC26                     (MT6355_PMIC_REG_BASE + 0x3234)
#define PMIC_AUXADC_ADC27                     (MT6355_PMIC_REG_BASE + 0x3236)
#define PMIC_AUXADC_ADC28                     (MT6355_PMIC_REG_BASE + 0x3238)
#define PMIC_AUXADC_ADC29                     (MT6355_PMIC_REG_BASE + 0x323A)
#define PMIC_AUXADC_ADC30                     (MT6355_PMIC_REG_BASE + 0x323C)
#define PMIC_AUXADC_ADC31                     (MT6355_PMIC_REG_BASE + 0x323E)
#define PMIC_AUXADC_ADC32                     (MT6355_PMIC_REG_BASE + 0x3240)
#define PMIC_AUXADC_ADC33                     (MT6355_PMIC_REG_BASE + 0x3242)
#define PMIC_AUXADC_ADC34                     (MT6355_PMIC_REG_BASE + 0x3244)
#define PMIC_AUXADC_ADC35                     (MT6355_PMIC_REG_BASE + 0x3246)
#define PMIC_AUXADC_ADC36                     (MT6355_PMIC_REG_BASE + 0x3248)
#define PMIC_AUXADC_ADC37                     (MT6355_PMIC_REG_BASE + 0x324A)
#define PMIC_AUXADC_ADC38                     (MT6355_PMIC_REG_BASE + 0x324C)
#define PMIC_AUXADC_ADC39                     (MT6355_PMIC_REG_BASE + 0x324E)
#define PMIC_AUXADC_ADC40                     (MT6355_PMIC_REG_BASE + 0x3250)
#define PMIC_AUXADC_ADC41                     (MT6355_PMIC_REG_BASE + 0x3252)
#define PMIC_AUXADC_ADC42                     (MT6355_PMIC_REG_BASE + 0x3254)
#define PMIC_AUXADC_ADC43                     (MT6355_PMIC_REG_BASE + 0x3256)
#define PMIC_AUXADC_ADC44                     (MT6355_PMIC_REG_BASE + 0x3258)
#define PMIC_AUXADC_BUF0                      (MT6355_PMIC_REG_BASE + 0x325A)
#define PMIC_AUXADC_BUF1                      (MT6355_PMIC_REG_BASE + 0x325C)
#define PMIC_AUXADC_BUF2                      (MT6355_PMIC_REG_BASE + 0x325E)
#define PMIC_AUXADC_BUF3                      (MT6355_PMIC_REG_BASE + 0x3260)
#define PMIC_AUXADC_BUF4                      (MT6355_PMIC_REG_BASE + 0x3262)
#define PMIC_AUXADC_BUF5                      (MT6355_PMIC_REG_BASE + 0x3264)
#define PMIC_AUXADC_BUF6                      (MT6355_PMIC_REG_BASE + 0x3266)
#define PMIC_AUXADC_BUF7                      (MT6355_PMIC_REG_BASE + 0x3268)
#define PMIC_AUXADC_BUF8                      (MT6355_PMIC_REG_BASE + 0x326A)
#define PMIC_AUXADC_BUF9                      (MT6355_PMIC_REG_BASE + 0x326C)
#define PMIC_AUXADC_BUF10                     (MT6355_PMIC_REG_BASE + 0x326E)
#define PMIC_AUXADC_BUF11                     (MT6355_PMIC_REG_BASE + 0x3270)
#define PMIC_AUXADC_BUF12                     (MT6355_PMIC_REG_BASE + 0x3272)
#define PMIC_AUXADC_BUF13                     (MT6355_PMIC_REG_BASE + 0x3274)
#define PMIC_AUXADC_BUF14                     (MT6355_PMIC_REG_BASE + 0x3276)
#define PMIC_AUXADC_BUF15                     (MT6355_PMIC_REG_BASE + 0x3278)
#define PMIC_AUXADC_BUF16                     (MT6355_PMIC_REG_BASE + 0x327A)
#define PMIC_AUXADC_BUF17                     (MT6355_PMIC_REG_BASE + 0x327C)
#define PMIC_AUXADC_BUF18                     (MT6355_PMIC_REG_BASE + 0x327E)
#define PMIC_AUXADC_BUF19                     (MT6355_PMIC_REG_BASE + 0x3280)
#define PMIC_AUXADC_BUF20                     (MT6355_PMIC_REG_BASE + 0x3282)
#define PMIC_AUXADC_BUF21                     (MT6355_PMIC_REG_BASE + 0x3284)
#define PMIC_AUXADC_BUF22                     (MT6355_PMIC_REG_BASE + 0x3286)
#define PMIC_AUXADC_BUF23                     (MT6355_PMIC_REG_BASE + 0x3288)
#define PMIC_AUXADC_BUF24                     (MT6355_PMIC_REG_BASE + 0x328A)
#define PMIC_AUXADC_BUF25                     (MT6355_PMIC_REG_BASE + 0x328C)
#define PMIC_AUXADC_BUF26                     (MT6355_PMIC_REG_BASE + 0x328E)
#define PMIC_AUXADC_BUF27                     (MT6355_PMIC_REG_BASE + 0x3290)
#define PMIC_AUXADC_BUF28                     (MT6355_PMIC_REG_BASE + 0x3292)
#define PMIC_AUXADC_BUF29                     (MT6355_PMIC_REG_BASE + 0x3294)
#define PMIC_AUXADC_BUF30                     (MT6355_PMIC_REG_BASE + 0x3296)
#define PMIC_AUXADC_BUF31                     (MT6355_PMIC_REG_BASE + 0x3298)
#define PMIC_AUXADC_STA0                      (MT6355_PMIC_REG_BASE + 0x329A)
#define PMIC_AUXADC_STA1                      (MT6355_PMIC_REG_BASE + 0x329C)
#define PMIC_AUXADC_STA2                      (MT6355_PMIC_REG_BASE + 0x329E)
#define PMIC_AUXADC_RQST0                     (MT6355_PMIC_REG_BASE + 0x32A0)
#define PMIC_AUXADC_RQST0_SET                 (MT6355_PMIC_REG_BASE + 0x32A2)
#define PMIC_AUXADC_RQST0_CLR                 (MT6355_PMIC_REG_BASE + 0x32A4)
#define PMIC_AUXADC_RQST1                     (MT6355_PMIC_REG_BASE + 0x32A6)
#define PMIC_AUXADC_RQST1_SET                 (MT6355_PMIC_REG_BASE + 0x32A8)
#define PMIC_AUXADC_RQST1_CLR                 (MT6355_PMIC_REG_BASE + 0x32AA)
#define PMIC_AUXADC_CON0                      (MT6355_PMIC_REG_BASE + 0x32AC)
#define PMIC_AUXADC_CON0_SET                  (MT6355_PMIC_REG_BASE + 0x32AE)
#define PMIC_AUXADC_CON0_CLR                  (MT6355_PMIC_REG_BASE + 0x32B0)
#define PMIC_AUXADC_CON1                      (MT6355_PMIC_REG_BASE + 0x32B2)
#define PMIC_AUXADC_CON2                      (MT6355_PMIC_REG_BASE + 0x32B4)
#define PMIC_AUXADC_CON3                      (MT6355_PMIC_REG_BASE + 0x32B6)
#define PMIC_AUXADC_CON4                      (MT6355_PMIC_REG_BASE + 0x32B8)
#define PMIC_AUXADC_CON5                      (MT6355_PMIC_REG_BASE + 0x32BA)
#define PMIC_AUXADC_CON6                      (MT6355_PMIC_REG_BASE + 0x32BC)
#define PMIC_AUXADC_CON7                      (MT6355_PMIC_REG_BASE + 0x32BE)
#define PMIC_AUXADC_CON8                      (MT6355_PMIC_REG_BASE + 0x32C0)
#define PMIC_AUXADC_CON9                      (MT6355_PMIC_REG_BASE + 0x32C2)
#define PMIC_AUXADC_CON10                     (MT6355_PMIC_REG_BASE + 0x32C4)
#define PMIC_AUXADC_CON11                     (MT6355_PMIC_REG_BASE + 0x32C6)
#define PMIC_AUXADC_CON12                     (MT6355_PMIC_REG_BASE + 0x32C8)
#define PMIC_AUXADC_CON13                     (MT6355_PMIC_REG_BASE + 0x32CA)
#define PMIC_AUXADC_CON14                     (MT6355_PMIC_REG_BASE + 0x32CC)
#define PMIC_AUXADC_CON15                     (MT6355_PMIC_REG_BASE + 0x32CE)
#define PMIC_AUXADC_CON16                     (MT6355_PMIC_REG_BASE + 0x32D0)
#define PMIC_AUXADC_CON17                     (MT6355_PMIC_REG_BASE + 0x32D2)
#define PMIC_AUXADC_CON18                     (MT6355_PMIC_REG_BASE + 0x32D4)
#define PMIC_AUXADC_CON19                     (MT6355_PMIC_REG_BASE + 0x32D6)
#define PMIC_AUXADC_CON20                     (MT6355_PMIC_REG_BASE + 0x32D8)
#define PMIC_AUXADC_CON21                     (MT6355_PMIC_REG_BASE + 0x32DA)
#define PMIC_AUXADC_CON22                     (MT6355_PMIC_REG_BASE + 0x32DC)
#define PMIC_AUXADC_CON23                     (MT6355_PMIC_REG_BASE + 0x32DE)
#define PMIC_AUXADC_AUTORPT0                  (MT6355_PMIC_REG_BASE + 0x32E0)
#define PMIC_AUXADC_LBAT0                     (MT6355_PMIC_REG_BASE + 0x32E2)
#define PMIC_AUXADC_LBAT1                     (MT6355_PMIC_REG_BASE + 0x32E4)
#define PMIC_AUXADC_LBAT2                     (MT6355_PMIC_REG_BASE + 0x32E6)
#define PMIC_AUXADC_LBAT3                     (MT6355_PMIC_REG_BASE + 0x32E8)
#define PMIC_AUXADC_LBAT4                     (MT6355_PMIC_REG_BASE + 0x32EA)
#define PMIC_AUXADC_LBAT5                     (MT6355_PMIC_REG_BASE + 0x32EC)
#define PMIC_AUXADC_LBAT6                     (MT6355_PMIC_REG_BASE + 0x32EE)
#define PMIC_AUXADC_ACCDET                    (MT6355_PMIC_REG_BASE + 0x32F0)
#define PMIC_AUXADC_THR0                      (MT6355_PMIC_REG_BASE + 0x32F2)
#define PMIC_AUXADC_THR1                      (MT6355_PMIC_REG_BASE + 0x32F4)
#define PMIC_AUXADC_THR2                      (MT6355_PMIC_REG_BASE + 0x32F6)
#define PMIC_AUXADC_THR3                      (MT6355_PMIC_REG_BASE + 0x32F8)
#define PMIC_AUXADC_THR4                      (MT6355_PMIC_REG_BASE + 0x32FA)
#define PMIC_AUXADC_THR5                      (MT6355_PMIC_REG_BASE + 0x32FC)
#define PMIC_AUXADC_THR6                      (MT6355_PMIC_REG_BASE + 0x32FE)
#define PMIC_AUXADC_EFUSE0                    (MT6355_PMIC_REG_BASE + 0x3300)
#define PMIC_AUXADC_EFUSE1                    (MT6355_PMIC_REG_BASE + 0x3302)
#define PMIC_AUXADC_EFUSE2                    (MT6355_PMIC_REG_BASE + 0x3304)
#define PMIC_AUXADC_EFUSE3                    (MT6355_PMIC_REG_BASE + 0x3306)
#define PMIC_AUXADC_EFUSE4                    (MT6355_PMIC_REG_BASE + 0x3308)
#define PMIC_AUXADC_EFUSE5                    (MT6355_PMIC_REG_BASE + 0x330A)
#define PMIC_AUXADC_DBG0                      (MT6355_PMIC_REG_BASE + 0x330C)
#define PMIC_AUXADC_IMP0                      (MT6355_PMIC_REG_BASE + 0x330E)
#define PMIC_AUXADC_IMP1                      (MT6355_PMIC_REG_BASE + 0x3310)
#define PMIC_AUXADC_BAT_TEMP_0                (MT6355_PMIC_REG_BASE + 0x3312)
#define PMIC_AUXADC_BAT_TEMP_1                (MT6355_PMIC_REG_BASE + 0x3314)
#define PMIC_AUXADC_BAT_TEMP_2                (MT6355_PMIC_REG_BASE + 0x3316)
#define PMIC_AUXADC_BAT_TEMP_3                (MT6355_PMIC_REG_BASE + 0x3318)
#define PMIC_AUXADC_BAT_TEMP_4                (MT6355_PMIC_REG_BASE + 0x331A)
#define PMIC_AUXADC_BAT_TEMP_5                (MT6355_PMIC_REG_BASE + 0x331C)
#define PMIC_AUXADC_BAT_TEMP_6                (MT6355_PMIC_REG_BASE + 0x331E)
#define PMIC_AUXADC_BAT_TEMP_7                (MT6355_PMIC_REG_BASE + 0x3320)
#define PMIC_AUXADC_LBAT2_1                   (MT6355_PMIC_REG_BASE + 0x3322)
#define PMIC_AUXADC_LBAT2_2                   (MT6355_PMIC_REG_BASE + 0x3324)
#define PMIC_AUXADC_LBAT2_3                   (MT6355_PMIC_REG_BASE + 0x3326)
#define PMIC_AUXADC_LBAT2_4                   (MT6355_PMIC_REG_BASE + 0x3328)
#define PMIC_AUXADC_LBAT2_5                   (MT6355_PMIC_REG_BASE + 0x332A)
#define PMIC_AUXADC_LBAT2_6                   (MT6355_PMIC_REG_BASE + 0x332C)
#define PMIC_AUXADC_LBAT2_7                   (MT6355_PMIC_REG_BASE + 0x332E)
#define PMIC_AUXADC_MDBG_0                    (MT6355_PMIC_REG_BASE + 0x3330)
#define PMIC_AUXADC_MDBG_1                    (MT6355_PMIC_REG_BASE + 0x3332)
#define PMIC_AUXADC_MDBG_2                    (MT6355_PMIC_REG_BASE + 0x3334)
#define PMIC_AUXADC_MDRT_0                    (MT6355_PMIC_REG_BASE + 0x3336)
#define PMIC_AUXADC_MDRT_1                    (MT6355_PMIC_REG_BASE + 0x3338)
#define PMIC_AUXADC_MDRT_2                    (MT6355_PMIC_REG_BASE + 0x333A)
#define PMIC_AUXADC_MDRT_3                    (MT6355_PMIC_REG_BASE + 0x333C)
#define PMIC_AUXADC_MDRT_4                    (MT6355_PMIC_REG_BASE + 0x333E)
#define PMIC_AUXADC_JEITA_0                   (MT6355_PMIC_REG_BASE + 0x3340)
#define PMIC_AUXADC_JEITA_1                   (MT6355_PMIC_REG_BASE + 0x3342)
#define PMIC_AUXADC_JEITA_2                   (MT6355_PMIC_REG_BASE + 0x3344)
#define PMIC_AUXADC_JEITA_3                   (MT6355_PMIC_REG_BASE + 0x3346)
#define PMIC_AUXADC_JEITA_4                   (MT6355_PMIC_REG_BASE + 0x3348)
#define PMIC_AUXADC_JEITA_5                   (MT6355_PMIC_REG_BASE + 0x334A)
#define PMIC_AUXADC_DCXO_MDRT_0               (MT6355_PMIC_REG_BASE + 0x334C)
#define PMIC_AUXADC_DCXO_MDRT_1               (MT6355_PMIC_REG_BASE + 0x334E)
#define PMIC_AUXADC_DCXO_MDRT_2               (MT6355_PMIC_REG_BASE + 0x3350)
#define PMIC_AUXADC_NAG_0                     (MT6355_PMIC_REG_BASE + 0x3352)
#define PMIC_AUXADC_NAG_1                     (MT6355_PMIC_REG_BASE + 0x3354)
#define PMIC_AUXADC_NAG_2                     (MT6355_PMIC_REG_BASE + 0x3356)
#define PMIC_AUXADC_NAG_3                     (MT6355_PMIC_REG_BASE + 0x3358)
#define PMIC_AUXADC_NAG_4                     (MT6355_PMIC_REG_BASE + 0x335A)
#define PMIC_AUXADC_NAG_5                     (MT6355_PMIC_REG_BASE + 0x335C)
#define PMIC_AUXADC_NAG_6                     (MT6355_PMIC_REG_BASE + 0x335E)
#define PMIC_AUXADC_NAG_7                     (MT6355_PMIC_REG_BASE + 0x3360)
#define PMIC_AUXADC_NAG_8                     (MT6355_PMIC_REG_BASE + 0x3362)
#define PMIC_AUXADC_EFUSE_1                   (MT6355_PMIC_REG_BASE + 0x3364)
#define PMIC_AUXADC_EFUSE_2                   (MT6355_PMIC_REG_BASE + 0x3366)
#define PMIC_AUXADC_EFUSE_3                   (MT6355_PMIC_REG_BASE + 0x3368)
#define PMIC_AUXADC_EFUSE_4                   (MT6355_PMIC_REG_BASE + 0x336A)
#define PMIC_AUXADC_RSV_1                     (MT6355_PMIC_REG_BASE + 0x336C)
#define PMIC_AUXADC_ANA_0                     (MT6355_PMIC_REG_BASE + 0x336E)
#define PMIC_AUXADC_IMP_CG0                   (MT6355_PMIC_REG_BASE + 0x3370)
#define PMIC_AUXADC_LBAT_CG0                  (MT6355_PMIC_REG_BASE + 0x3372)
#define PMIC_AUXADC_THR_CG0                   (MT6355_PMIC_REG_BASE + 0x3374)
#define PMIC_AUXADC_BAT_TEMP_CG0              (MT6355_PMIC_REG_BASE + 0x3376)
#define PMIC_AUXADC_LBAT2_CG0                 (MT6355_PMIC_REG_BASE + 0x3378)
#define PMIC_AUXADC_JEITA_CG0                 (MT6355_PMIC_REG_BASE + 0x337A)
#define PMIC_AUXADC_NAG_CG0                   (MT6355_PMIC_REG_BASE + 0x337C)
#define PMIC_AUXADC_PRI_NEW                   (MT6355_PMIC_REG_BASE + 0x337E)
#define PMIC_DRIVER_ANA_CON0                  (MT6355_PMIC_REG_BASE + 0x3400)
#define PMIC_DRIVER_ANA_CON1                  (MT6355_PMIC_REG_BASE + 0x3402)
#define PMIC_ISINK0_CON1                      (MT6355_PMIC_REG_BASE + 0x3404)
#define PMIC_ISINK1_CON1                      (MT6355_PMIC_REG_BASE + 0x3406)
#define PMIC_ISINK2_CON1                      (MT6355_PMIC_REG_BASE + 0x3408)
#define PMIC_ISINK3_CON1                      (MT6355_PMIC_REG_BASE + 0x340A)
#define PMIC_ISINK_ANA1_SMPL                  (MT6355_PMIC_REG_BASE + 0x340C)
#define PMIC_ISINK_EN_CTRL_SMPL               (MT6355_PMIC_REG_BASE + 0x340E)
#define PMIC_AUDDEC_ANA_CON0                  (MT6355_PMIC_REG_BASE + 0x3600)
#define PMIC_AUDDEC_ANA_CON1                  (MT6355_PMIC_REG_BASE + 0x3602)
#define PMIC_AUDDEC_ANA_CON2                  (MT6355_PMIC_REG_BASE + 0x3604)
#define PMIC_AUDDEC_ANA_CON3                  (MT6355_PMIC_REG_BASE + 0x3606)
#define PMIC_AUDDEC_ANA_CON4                  (MT6355_PMIC_REG_BASE + 0x3608)
#define PMIC_AUDDEC_ANA_CON5                  (MT6355_PMIC_REG_BASE + 0x360A)
#define PMIC_AUDDEC_ANA_CON6                  (MT6355_PMIC_REG_BASE + 0x360C)
#define PMIC_AUDDEC_ANA_CON7                  (MT6355_PMIC_REG_BASE + 0x360E)
#define PMIC_AUDDEC_ANA_CON8                  (MT6355_PMIC_REG_BASE + 0x3610)
#define PMIC_AUDDEC_ANA_CON9                  (MT6355_PMIC_REG_BASE + 0x3612)
#define PMIC_AUDDEC_ANA_CON10                 (MT6355_PMIC_REG_BASE + 0x3614)
#define PMIC_AUDDEC_ANA_CON11                 (MT6355_PMIC_REG_BASE + 0x3616)
#define PMIC_AUDDEC_ANA_CON12                 (MT6355_PMIC_REG_BASE + 0x3618)
#define PMIC_AUDDEC_ANA_CON13                 (MT6355_PMIC_REG_BASE + 0x361A)
#define PMIC_AUDDEC_ANA_CON14                 (MT6355_PMIC_REG_BASE + 0x361C)
#define PMIC_AUDENC_ANA_CON0                  (MT6355_PMIC_REG_BASE + 0x361E)
#define PMIC_AUDENC_ANA_CON1                  (MT6355_PMIC_REG_BASE + 0x3620)
#define PMIC_AUDENC_ANA_CON2                  (MT6355_PMIC_REG_BASE + 0x3622)
#define PMIC_AUDENC_ANA_CON3                  (MT6355_PMIC_REG_BASE + 0x3624)
#define PMIC_AUDENC_ANA_CON4                  (MT6355_PMIC_REG_BASE + 0x3626)
#define PMIC_AUDENC_ANA_CON5                  (MT6355_PMIC_REG_BASE + 0x3628)
#define PMIC_AUDENC_ANA_CON6                  (MT6355_PMIC_REG_BASE + 0x362A)
#define PMIC_AUDENC_ANA_CON7                  (MT6355_PMIC_REG_BASE + 0x362C)
#define PMIC_AUDENC_ANA_CON8                  (MT6355_PMIC_REG_BASE + 0x362E)
#define PMIC_AUDENC_ANA_CON9                  (MT6355_PMIC_REG_BASE + 0x3630)
#define PMIC_AUDENC_ANA_CON10                 (MT6355_PMIC_REG_BASE + 0x3632)
#define PMIC_AUDENC_ANA_CON11                 (MT6355_PMIC_REG_BASE + 0x3634)
#define PMIC_AUDENC_ANA_CON12                 (MT6355_PMIC_REG_BASE + 0x3636)
#define PMIC_AUDENC_ANA_CON13                 (MT6355_PMIC_REG_BASE + 0x3638)
#define PMIC_AUDENC_ANA_CON14                 (MT6355_PMIC_REG_BASE + 0x363A)
#define PMIC_AUDENC_ANA_CON15                 (MT6355_PMIC_REG_BASE + 0x363C)
#define PMIC_AUDENC_ANA_CON16                 (MT6355_PMIC_REG_BASE + 0x363E)
#define PMIC_ZCD_CON0                         (MT6355_PMIC_REG_BASE + 0x3800)
#define PMIC_ZCD_CON1                         (MT6355_PMIC_REG_BASE + 0x3802)
#define PMIC_ZCD_CON2                         (MT6355_PMIC_REG_BASE + 0x3804)
#define PMIC_ZCD_CON3                         (MT6355_PMIC_REG_BASE + 0x3806)
#define PMIC_ZCD_CON4                         (MT6355_PMIC_REG_BASE + 0x3808)
#define PMIC_ZCD_CON5                         (MT6355_PMIC_REG_BASE + 0x380A)
#define PMIC_RSV_CON0                         (MT6355_PMIC_REG_BASE + 0x3A00)
// mask is HEX;  shift is Integer
#define PMIC_HWCID_MASK                                  0xFFFF
#define PMIC_HWCID_SHIFT                                 0
#define PMIC_SWCID_MASK                                  0xFFFF
#define PMIC_SWCID_SHIFT                                 0
#define PMIC_RG_SRCLKEN_IN0_EN_MASK                      0x1
#define PMIC_RG_SRCLKEN_IN0_EN_SHIFT                     0
#define PMIC_RG_SRCLKEN_IN1_EN_MASK                      0x1
#define PMIC_RG_SRCLKEN_IN1_EN_SHIFT                     1
#define PMIC_RG_OSC_SEL_MASK                             0x1
#define PMIC_RG_OSC_SEL_SHIFT                            4
#define PMIC_RG_SRCLKEN_IN0_HW_MODE_MASK                 0x1
#define PMIC_RG_SRCLKEN_IN0_HW_MODE_SHIFT                5
#define PMIC_RG_SRCLKEN_IN1_HW_MODE_MASK                 0x1
#define PMIC_RG_SRCLKEN_IN1_HW_MODE_SHIFT                6
#define PMIC_RG_OSC_SEL_HW_MODE_MASK                     0x1
#define PMIC_RG_OSC_SEL_HW_MODE_SHIFT                    7
#define PMIC_RG_SRCLKEN_IN_SYNC_EN_MASK                  0x1
#define PMIC_RG_SRCLKEN_IN_SYNC_EN_SHIFT                 8
#define PMIC_RG_OSC_EN_AUTO_OFF_MASK                     0x1
#define PMIC_RG_OSC_EN_AUTO_OFF_SHIFT                    9
#define PMIC_TEST_OUT_MASK                               0xFF
#define PMIC_TEST_OUT_SHIFT                              0
#define PMIC_RG_MON_FLAG_SEL_MASK                        0xFF
#define PMIC_RG_MON_FLAG_SEL_SHIFT                       0
#define PMIC_RG_MON_GRP_SEL_MASK                         0x1F
#define PMIC_RG_MON_GRP_SEL_SHIFT                        8
#define PMIC_RG_NANDTREE_MODE_MASK                       0x1
#define PMIC_RG_NANDTREE_MODE_SHIFT                      0
#define PMIC_RG_TEST_AUXADC_MASK                         0x1
#define PMIC_RG_TEST_AUXADC_SHIFT                        1
#define PMIC_RG_EFUSE_MODE_MASK                          0x1
#define PMIC_RG_EFUSE_MODE_SHIFT                         2
#define PMIC_RG_TEST_STRUP_MASK                          0x1
#define PMIC_RG_TEST_STRUP_SHIFT                         3
#define PMIC_TESTMODE_SW_MASK                            0x1
#define PMIC_TESTMODE_SW_SHIFT                           0
#define PMIC_VA12_PG_DEB_MASK                            0x1
#define PMIC_VA12_PG_DEB_SHIFT                           0
#define PMIC_VA10_PG_DEB_MASK                            0x1
#define PMIC_VA10_PG_DEB_SHIFT                           1
#define PMIC_VSRAM_GPU_PG_DEB_MASK                       0x1
#define PMIC_VSRAM_GPU_PG_DEB_SHIFT                      2
#define PMIC_VSRAM_MD_PG_DEB_MASK                        0x1
#define PMIC_VSRAM_MD_PG_DEB_SHIFT                       3
#define PMIC_VSRAM_CORE_PG_DEB_MASK                      0x1
#define PMIC_VSRAM_CORE_PG_DEB_SHIFT                     4
#define PMIC_VA18_PG_DEB_MASK                            0x1
#define PMIC_VA18_PG_DEB_SHIFT                           5
#define PMIC_BUCK_RSV_PG_DEB_MASK                        0x1
#define PMIC_BUCK_RSV_PG_DEB_SHIFT                       6
#define PMIC_VDRAM2_PG_DEB_MASK                          0x1
#define PMIC_VDRAM2_PG_DEB_SHIFT                         7
#define PMIC_VDRAM1_PG_DEB_MASK                          0x1
#define PMIC_VDRAM1_PG_DEB_SHIFT                         8
#define PMIC_VPROC12_PG_DEB_MASK                         0x1
#define PMIC_VPROC12_PG_DEB_SHIFT                        9
#define PMIC_VPROC11_PG_DEB_MASK                         0x1
#define PMIC_VPROC11_PG_DEB_SHIFT                        10
#define PMIC_VS1_PG_DEB_MASK                             0x1
#define PMIC_VS1_PG_DEB_SHIFT                            11
#define PMIC_VMODEM_PG_DEB_MASK                          0x1
#define PMIC_VMODEM_PG_DEB_SHIFT                         12
#define PMIC_VGPU_PG_DEB_MASK                            0x1
#define PMIC_VGPU_PG_DEB_SHIFT                           13
#define PMIC_VCORE_PG_DEB_MASK                           0x1
#define PMIC_VCORE_PG_DEB_SHIFT                          14
#define PMIC_VS2_PG_DEB_MASK                             0x1
#define PMIC_VS2_PG_DEB_SHIFT                            15
#define PMIC_EXT_PMIC_PG_DEB_MASK                        0x1
#define PMIC_EXT_PMIC_PG_DEB_SHIFT                       7
#define PMIC_VXO18_PG_DEB_MASK                           0x1
#define PMIC_VXO18_PG_DEB_SHIFT                          8
#define PMIC_VXO22_PG_DEB_MASK                           0x1
#define PMIC_VXO22_PG_DEB_SHIFT                          9
#define PMIC_VUSB33_PG_DEB_MASK                          0x1
#define PMIC_VUSB33_PG_DEB_SHIFT                         10
#define PMIC_VSRAM_PROC_PG_DEB_MASK                      0x1
#define PMIC_VSRAM_PROC_PG_DEB_SHIFT                     11
#define PMIC_VIO28_PG_DEB_MASK                           0x1
#define PMIC_VIO28_PG_DEB_SHIFT                          12
#define PMIC_VUFS18_PG_DEB_MASK                          0x1
#define PMIC_VUFS18_PG_DEB_SHIFT                         13
#define PMIC_VEMC_PG_DEB_MASK                            0x1
#define PMIC_VEMC_PG_DEB_SHIFT                           14
#define PMIC_VIO18_PG_DEB_MASK                           0x1
#define PMIC_VIO18_PG_DEB_SHIFT                          15
#define PMIC_STRUP_VA12_PG_STATUS_MASK                   0x1
#define PMIC_STRUP_VA12_PG_STATUS_SHIFT                  0
#define PMIC_STRUP_VA10_PG_STATUS_MASK                   0x1
#define PMIC_STRUP_VA10_PG_STATUS_SHIFT                  1
#define PMIC_STRUP_VSRAM_GPU_PG_STATUS_MASK              0x1
#define PMIC_STRUP_VSRAM_GPU_PG_STATUS_SHIFT             2
#define PMIC_STRUP_VSRAM_MD_PG_STATUS_MASK               0x1
#define PMIC_STRUP_VSRAM_MD_PG_STATUS_SHIFT              3
#define PMIC_STRUP_VSRAM_CORE_PG_STATUS_MASK             0x1
#define PMIC_STRUP_VSRAM_CORE_PG_STATUS_SHIFT            4
#define PMIC_STRUP_VA18_PG_STATUS_MASK                   0x1
#define PMIC_STRUP_VA18_PG_STATUS_SHIFT                  5
#define PMIC_STRUP_BUCK_RSV_PG_STATUS_MASK               0x1
#define PMIC_STRUP_BUCK_RSV_PG_STATUS_SHIFT              6
#define PMIC_STRUP_VDRAM2_PG_STATUS_MASK                 0x1
#define PMIC_STRUP_VDRAM2_PG_STATUS_SHIFT                7
#define PMIC_STRUP_VDRAM1_PG_STATUS_MASK                 0x1
#define PMIC_STRUP_VDRAM1_PG_STATUS_SHIFT                8
#define PMIC_STRUP_VPROC12_PG_STATUS_MASK                0x1
#define PMIC_STRUP_VPROC12_PG_STATUS_SHIFT               9
#define PMIC_STRUP_VPROC11_PG_STATUS_MASK                0x1
#define PMIC_STRUP_VPROC11_PG_STATUS_SHIFT               10
#define PMIC_STRUP_VS1_PG_STATUS_MASK                    0x1
#define PMIC_STRUP_VS1_PG_STATUS_SHIFT                   11
#define PMIC_STRUP_VMODEM_PG_STATUS_MASK                 0x1
#define PMIC_STRUP_VMODEM_PG_STATUS_SHIFT                12
#define PMIC_STRUP_VGPU_PG_STATUS_MASK                   0x1
#define PMIC_STRUP_VGPU_PG_STATUS_SHIFT                  13
#define PMIC_STRUP_VCORE_PG_STATUS_MASK                  0x1
#define PMIC_STRUP_VCORE_PG_STATUS_SHIFT                 14
#define PMIC_STRUP_VS2_PG_STATUS_MASK                    0x1
#define PMIC_STRUP_VS2_PG_STATUS_SHIFT                   15
#define PMIC_STRUP_EXT_PMIC_PG_STATUS_MASK               0x1
#define PMIC_STRUP_EXT_PMIC_PG_STATUS_SHIFT              7
#define PMIC_STRUP_VXO18_PG_STATUS_MASK                  0x1
#define PMIC_STRUP_VXO18_PG_STATUS_SHIFT                 8
#define PMIC_STRUP_VXO22_PG_STATUS_MASK                  0x1
#define PMIC_STRUP_VXO22_PG_STATUS_SHIFT                 9
#define PMIC_STRUP_VUSB33_PG_STATUS_MASK                 0x1
#define PMIC_STRUP_VUSB33_PG_STATUS_SHIFT                10
#define PMIC_STRUP_VSRAM_PROC_PG_STATUS_MASK             0x1
#define PMIC_STRUP_VSRAM_PROC_PG_STATUS_SHIFT            11
#define PMIC_STRUP_VIO28_PG_STATUS_MASK                  0x1
#define PMIC_STRUP_VIO28_PG_STATUS_SHIFT                 12
#define PMIC_STRUP_VUFS18_PG_STATUS_MASK                 0x1
#define PMIC_STRUP_VUFS18_PG_STATUS_SHIFT                13
#define PMIC_STRUP_VEMC_PG_STATUS_MASK                   0x1
#define PMIC_STRUP_VEMC_PG_STATUS_SHIFT                  14
#define PMIC_STRUP_VIO18_PG_STATUS_MASK                  0x1
#define PMIC_STRUP_VIO18_PG_STATUS_SHIFT                 15
#define PMIC_STRUP_BUCK_RSV_OC_STATUS_MASK               0x1
#define PMIC_STRUP_BUCK_RSV_OC_STATUS_SHIFT              6
#define PMIC_STRUP_VDRAM2_OC_STATUS_MASK                 0x1
#define PMIC_STRUP_VDRAM2_OC_STATUS_SHIFT                7
#define PMIC_STRUP_VDRAM1_OC_STATUS_MASK                 0x1
#define PMIC_STRUP_VDRAM1_OC_STATUS_SHIFT                8
#define PMIC_STRUP_VPROC12_OC_STATUS_MASK                0x1
#define PMIC_STRUP_VPROC12_OC_STATUS_SHIFT               9
#define PMIC_STRUP_VPROC11_OC_STATUS_MASK                0x1
#define PMIC_STRUP_VPROC11_OC_STATUS_SHIFT               10
#define PMIC_STRUP_VS1_OC_STATUS_MASK                    0x1
#define PMIC_STRUP_VS1_OC_STATUS_SHIFT                   11
#define PMIC_STRUP_VMODEM_OC_STATUS_MASK                 0x1
#define PMIC_STRUP_VMODEM_OC_STATUS_SHIFT                12
#define PMIC_STRUP_VGPU_OC_STATUS_MASK                   0x1
#define PMIC_STRUP_VGPU_OC_STATUS_SHIFT                  13
#define PMIC_STRUP_VCORE_OC_STATUS_MASK                  0x1
#define PMIC_STRUP_VCORE_OC_STATUS_SHIFT                 14
#define PMIC_STRUP_VS2_OC_STATUS_MASK                    0x1
#define PMIC_STRUP_VS2_OC_STATUS_SHIFT                   15
#define PMIC_PMU_THERMAL_DEB_MASK                        0x1
#define PMIC_PMU_THERMAL_DEB_SHIFT                       14
#define PMIC_STRUP_THERMAL_STATUS_MASK                   0x1
#define PMIC_STRUP_THERMAL_STATUS_SHIFT                  15
#define PMIC_PMU_TEST_MODE_SCAN_MASK                     0x1
#define PMIC_PMU_TEST_MODE_SCAN_SHIFT                    0
#define PMIC_PWRKEY_DEB_MASK                             0x1
#define PMIC_PWRKEY_DEB_SHIFT                            1
#define PMIC_HOMEKEY_DEB_MASK                            0x1
#define PMIC_HOMEKEY_DEB_SHIFT                           2
#define PMIC_RTC_XTAL_DET_DONE_MASK                      0x1
#define PMIC_RTC_XTAL_DET_DONE_SHIFT                     6
#define PMIC_XOSC32_ENB_DET_MASK                         0x1
#define PMIC_XOSC32_ENB_DET_SHIFT                        7
#define PMIC_RTC_XTAL_DET_RSV_MASK                       0xF
#define PMIC_RTC_XTAL_DET_RSV_SHIFT                      8
#define PMIC_RG_PMU_TDSEL_MASK                           0x1
#define PMIC_RG_PMU_TDSEL_SHIFT                          0
#define PMIC_RG_SPI_TDSEL_MASK                           0x1
#define PMIC_RG_SPI_TDSEL_SHIFT                          1
#define PMIC_RG_AUD_TDSEL_MASK                           0x1
#define PMIC_RG_AUD_TDSEL_SHIFT                          2
#define PMIC_RG_E32CAL_TDSEL_MASK                        0x1
#define PMIC_RG_E32CAL_TDSEL_SHIFT                       3
#define PMIC_RG_PMU_RDSEL_MASK                           0x1
#define PMIC_RG_PMU_RDSEL_SHIFT                          0
#define PMIC_RG_SPI_RDSEL_MASK                           0x1
#define PMIC_RG_SPI_RDSEL_SHIFT                          1
#define PMIC_RG_AUD_RDSEL_MASK                           0x1
#define PMIC_RG_AUD_RDSEL_SHIFT                          2
#define PMIC_RG_E32CAL_RDSEL_MASK                        0x1
#define PMIC_RG_E32CAL_RDSEL_SHIFT                       3
#define PMIC_RG_SMT_WDTRSTB_IN_MASK                      0x1
#define PMIC_RG_SMT_WDTRSTB_IN_SHIFT                     0
#define PMIC_RG_SMT_HOMEKEY_MASK                         0x1
#define PMIC_RG_SMT_HOMEKEY_SHIFT                        1
#define PMIC_RG_SMT_SRCLKEN_IN0_MASK                     0x1
#define PMIC_RG_SMT_SRCLKEN_IN0_SHIFT                    2
#define PMIC_RG_SMT_SRCLKEN_IN1_MASK                     0x1
#define PMIC_RG_SMT_SRCLKEN_IN1_SHIFT                    3
#define PMIC_RG_SMT_RTC_32K1V8_0_MASK                    0x1
#define PMIC_RG_SMT_RTC_32K1V8_0_SHIFT                   4
#define PMIC_RG_SMT_RTC_32K1V8_1_MASK                    0x1
#define PMIC_RG_SMT_RTC_32K1V8_1_SHIFT                   5
#define PMIC_RG_SMT_SCP_VREQ_VAO_MASK                    0x1
#define PMIC_RG_SMT_SCP_VREQ_VAO_SHIFT                   6
#define PMIC_RG_SMT_SPI_CLK_MASK                         0x1
#define PMIC_RG_SMT_SPI_CLK_SHIFT                        0
#define PMIC_RG_SMT_SPI_CSN_MASK                         0x1
#define PMIC_RG_SMT_SPI_CSN_SHIFT                        1
#define PMIC_RG_SMT_SPI_MOSI_MASK                        0x1
#define PMIC_RG_SMT_SPI_MOSI_SHIFT                       2
#define PMIC_RG_SMT_SPI_MISO_MASK                        0x1
#define PMIC_RG_SMT_SPI_MISO_SHIFT                       3
#define PMIC_RG_SMT_AUD_CLK_MASK                         0x1
#define PMIC_RG_SMT_AUD_CLK_SHIFT                        4
#define PMIC_RG_SMT_AUD_DAT_MOSI_MASK                    0x1
#define PMIC_RG_SMT_AUD_DAT_MOSI_SHIFT                   5
#define PMIC_RG_SMT_AUD_DAT_MISO_MASK                    0x1
#define PMIC_RG_SMT_AUD_DAT_MISO_SHIFT                   6
#define PMIC_RG_SMT_VOW_CLK_MISO_MASK                    0x1
#define PMIC_RG_SMT_VOW_CLK_MISO_SHIFT                   7
#define PMIC_RG_OCTL_SRCLKEN_IN0_MASK                    0xF
#define PMIC_RG_OCTL_SRCLKEN_IN0_SHIFT                   0
#define PMIC_RG_OCTL_SRCLKEN_IN1_MASK                    0xF
#define PMIC_RG_OCTL_SRCLKEN_IN1_SHIFT                   4
#define PMIC_RG_OCTL_RTC_32K1V8_0_MASK                   0xF
#define PMIC_RG_OCTL_RTC_32K1V8_0_SHIFT                  8
#define PMIC_RG_OCTL_RTC_32K1V8_1_MASK                   0xF
#define PMIC_RG_OCTL_RTC_32K1V8_1_SHIFT                  12
#define PMIC_RG_OCTL_SPI_CLK_MASK                        0xF
#define PMIC_RG_OCTL_SPI_CLK_SHIFT                       0
#define PMIC_RG_OCTL_SPI_CSN_MASK                        0xF
#define PMIC_RG_OCTL_SPI_CSN_SHIFT                       4
#define PMIC_RG_OCTL_SPI_MOSI_MASK                       0xF
#define PMIC_RG_OCTL_SPI_MOSI_SHIFT                      8
#define PMIC_RG_OCTL_SPI_MISO_MASK                       0xF
#define PMIC_RG_OCTL_SPI_MISO_SHIFT                      12
#define PMIC_RG_OCTL_AUD_CLK_MASK                        0xF
#define PMIC_RG_OCTL_AUD_CLK_SHIFT                       0
#define PMIC_RG_OCTL_AUD_DAT_MOSI_MASK                   0xF
#define PMIC_RG_OCTL_AUD_DAT_MOSI_SHIFT                  4
#define PMIC_RG_OCTL_AUD_DAT_MISO_MASK                   0xF
#define PMIC_RG_OCTL_AUD_DAT_MISO_SHIFT                  8
#define PMIC_RG_OCTL_VOW_CLK_MISO_MASK                   0xF
#define PMIC_RG_OCTL_VOW_CLK_MISO_SHIFT                  12
#define PMIC_RG_OCTL_HOMEKEY_MASK                        0xF
#define PMIC_RG_OCTL_HOMEKEY_SHIFT                       0
#define PMIC_RG_OCTL_SCP_VREQ_VAO_MASK                   0xF
#define PMIC_RG_OCTL_SCP_VREQ_VAO_SHIFT                  4
#define PMIC_RG_SPI_CLK_FILTER_EN_MASK                   0x1
#define PMIC_RG_SPI_CLK_FILTER_EN_SHIFT                  0
#define PMIC_RG_SPI_CSN_FILTER_EN_MASK                   0x1
#define PMIC_RG_SPI_CSN_FILTER_EN_SHIFT                  1
#define PMIC_RG_SPI_MOSI_FILTER_EN_MASK                  0x1
#define PMIC_RG_SPI_MOSI_FILTER_EN_SHIFT                 2
#define PMIC_RG_SPI_MISO_FILTER_EN_MASK                  0x1
#define PMIC_RG_SPI_MISO_FILTER_EN_SHIFT                 3
#define PMIC_RG_AUD_CLK_FILTER_EN_MASK                   0x1
#define PMIC_RG_AUD_CLK_FILTER_EN_SHIFT                  4
#define PMIC_RG_AUD_DAT_MOSI_FILTER_EN_MASK              0x1
#define PMIC_RG_AUD_DAT_MOSI_FILTER_EN_SHIFT             5
#define PMIC_RG_AUD_DAT_MISO_FILTER_EN_MASK              0x1
#define PMIC_RG_AUD_DAT_MISO_FILTER_EN_SHIFT             6
#define PMIC_RG_VOW_CLK_MISO_FILTER_EN_MASK              0x1
#define PMIC_RG_VOW_CLK_MISO_FILTER_EN_SHIFT             7
#define PMIC_RG_WDTRSTB_IN_FILTER_EN_MASK                0x1
#define PMIC_RG_WDTRSTB_IN_FILTER_EN_SHIFT               8
#define PMIC_RG_HOMEKEY_FILTER_EN_MASK                   0x1
#define PMIC_RG_HOMEKEY_FILTER_EN_SHIFT                  9
#define PMIC_RG_SRCLKEN_IN0_FILTER_EN_MASK               0x1
#define PMIC_RG_SRCLKEN_IN0_FILTER_EN_SHIFT              10
#define PMIC_RG_SRCLKEN_IN1_FILTER_EN_MASK               0x1
#define PMIC_RG_SRCLKEN_IN1_FILTER_EN_SHIFT              11
#define PMIC_RG_RTC32K_1V8_0_FILTER_EN_MASK              0x1
#define PMIC_RG_RTC32K_1V8_0_FILTER_EN_SHIFT             12
#define PMIC_RG_RTC32K_1V8_1_FILTER_EN_MASK              0x1
#define PMIC_RG_RTC32K_1V8_1_FILTER_EN_SHIFT             13
#define PMIC_RG_SCP_VREQ_VAO_FILTER_EN_MASK              0x1
#define PMIC_RG_SCP_VREQ_VAO_FILTER_EN_SHIFT             14
#define PMIC_RG_SPI_CLK_RCSEL_MASK                       0x1
#define PMIC_RG_SPI_CLK_RCSEL_SHIFT                      0
#define PMIC_RG_SPI_CSN_RCSEL_MASK                       0x1
#define PMIC_RG_SPI_CSN_RCSEL_SHIFT                      1
#define PMIC_RG_SPI_MOSI_RCSEL_MASK                      0x1
#define PMIC_RG_SPI_MOSI_RCSEL_SHIFT                     2
#define PMIC_RG_SPI_MISO_RCSEL_MASK                      0x1
#define PMIC_RG_SPI_MISO_RCSEL_SHIFT                     3
#define PMIC_RG_AUD_CLK_RCSEL_MASK                       0x1
#define PMIC_RG_AUD_CLK_RCSEL_SHIFT                      4
#define PMIC_RG_AUD_DAT_MOSI_RCSEL_MASK                  0x1
#define PMIC_RG_AUD_DAT_MOSI_RCSEL_SHIFT                 5
#define PMIC_RG_AUD_DAT_MISO_RCSEL_MASK                  0x1
#define PMIC_RG_AUD_DAT_MISO_RCSEL_SHIFT                 6
#define PMIC_RG_VOW_CLK_MISO_RCSEL_MASK                  0x1
#define PMIC_RG_VOW_CLK_MISO_RCSEL_SHIFT                 7
#define PMIC_RG_WDTRSTB_IN_RCSEL_MASK                    0x1
#define PMIC_RG_WDTRSTB_IN_RCSEL_SHIFT                   8
#define PMIC_RG_HOMEKEY_RCSEL_MASK                       0x1
#define PMIC_RG_HOMEKEY_RCSEL_SHIFT                      9
#define PMIC_RG_SRCLKEN_IN0_RCSEL_MASK                   0x1
#define PMIC_RG_SRCLKEN_IN0_RCSEL_SHIFT                  10
#define PMIC_RG_SRCLKEN_IN1_RCSEL_MASK                   0x1
#define PMIC_RG_SRCLKEN_IN1_RCSEL_SHIFT                  11
#define PMIC_RG_RTC32K_1V8_0_RCSEL_MASK                  0x1
#define PMIC_RG_RTC32K_1V8_0_RCSEL_SHIFT                 12
#define PMIC_RG_RTC32K_1V8_1_RCSEL_MASK                  0x1
#define PMIC_RG_RTC32K_1V8_1_RCSEL_SHIFT                 13
#define PMIC_RG_SCP_VREQ_VAO_RCSEL_MASK                  0x1
#define PMIC_RG_SCP_VREQ_VAO_RCSEL_SHIFT                 14
#define PMIC_TOP_STATUS_MASK                             0xF
#define PMIC_TOP_STATUS_SHIFT                            0
#define PMIC_TOP_STATUS_SET_MASK                         0x3
#define PMIC_TOP_STATUS_SET_SHIFT                        0
#define PMIC_TOP_STATUS_CLR_MASK                         0x3
#define PMIC_TOP_STATUS_CLR_SHIFT                        0
#define PMIC_RG_SRCLKEN_IN2_EN_MASK                      0x1
#define PMIC_RG_SRCLKEN_IN2_EN_SHIFT                     0
#define PMIC_RG_SRCLKEN_IN3_EN_MASK                      0x1
#define PMIC_RG_SRCLKEN_IN3_EN_SHIFT                     0
#define PMIC_VM_MODE_MASK                                0x3
#define PMIC_VM_MODE_SHIFT                               0
#define PMIC_RG_G_SMPS_CK_PDN_MASK                       0x1
#define PMIC_RG_G_SMPS_CK_PDN_SHIFT                      0
#define PMIC_RG_G_SMPS_TEST_CK_PDN_MASK                  0x1
#define PMIC_RG_G_SMPS_TEST_CK_PDN_SHIFT                 1
#define PMIC_RG_INTRP_CK_PDN_MASK                        0x1
#define PMIC_RG_INTRP_CK_PDN_SHIFT                       2
#define PMIC_RG_INTRP_PRE_OC_CK_PDN_MASK                 0x1
#define PMIC_RG_INTRP_PRE_OC_CK_PDN_SHIFT                3
#define PMIC_RG_G_BIF_1M_CK_PDN_MASK                     0x1
#define PMIC_RG_G_BIF_1M_CK_PDN_SHIFT                    4
#define PMIC_RG_BIF_X1_CK_PDN_MASK                       0x1
#define PMIC_RG_BIF_X1_CK_PDN_SHIFT                      5
#define PMIC_RG_BIF_X4_CK_PDN_MASK                       0x1
#define PMIC_RG_BIF_X4_CK_PDN_SHIFT                      6
#define PMIC_RG_BIF_X72_CK_PDN_MASK                      0x1
#define PMIC_RG_BIF_X72_CK_PDN_SHIFT                     7
#define PMIC_RG_AUXADC_AO_1M_CK_PDN_MASK                 0x1
#define PMIC_RG_AUXADC_AO_1M_CK_PDN_SHIFT                8
#define PMIC_RG_AUXADC_CK_PDN_MASK                       0x1
#define PMIC_RG_AUXADC_CK_PDN_SHIFT                      9
#define PMIC_RG_AUXADC_RNG_CK_PDN_MASK                   0x1
#define PMIC_RG_AUXADC_RNG_CK_PDN_SHIFT                  10
#define PMIC_RG_AUXADC_1M_CK_PDN_MASK                    0x1
#define PMIC_RG_AUXADC_1M_CK_PDN_SHIFT                   11
#define PMIC_RG_DRV_32K_CK_PDN_MASK                      0x1
#define PMIC_RG_DRV_32K_CK_PDN_SHIFT                     12
#define PMIC_RG_TOP_CKPDN_CON0_RSV_MASK                  0x7
#define PMIC_RG_TOP_CKPDN_CON0_RSV_SHIFT                 13
#define PMIC_TOP_CKPDN_CON0_SET_MASK                     0xFFFF
#define PMIC_TOP_CKPDN_CON0_SET_SHIFT                    0
#define PMIC_TOP_CKPDN_CON0_CLR_MASK                     0xFFFF
#define PMIC_TOP_CKPDN_CON0_CLR_SHIFT                    0
#define PMIC_RG_BUCK_9M_CK_PDN_MASK                      0x1
#define PMIC_RG_BUCK_9M_CK_PDN_SHIFT                     0
#define PMIC_RG_BUCK_1M_CK_PDN_MASK                      0x1
#define PMIC_RG_BUCK_1M_CK_PDN_SHIFT                     1
#define PMIC_RG_BUCK_18M_CK_PDN_MASK                     0x1
#define PMIC_RG_BUCK_18M_CK_PDN_SHIFT                    2
#define PMIC_RG_BUCK_32K_CK_PDN_MASK                     0x1
#define PMIC_RG_BUCK_32K_CK_PDN_SHIFT                    3
#define PMIC_RG_LDO_9M_CK_PDN_MASK                       0x1
#define PMIC_RG_LDO_9M_CK_PDN_SHIFT                      4
#define PMIC_RG_LDO_1M_CK_PDN_MASK                       0x1
#define PMIC_RG_LDO_1M_CK_PDN_SHIFT                      5
#define PMIC_RG_RSV0_CK_PDN_MASK                         0x1
#define PMIC_RG_RSV0_CK_PDN_SHIFT                        6
#define PMIC_RG_BUCK_ANA_CLK_PDN_MASK                    0x1
#define PMIC_RG_BUCK_ANA_CLK_PDN_SHIFT                   7
#define PMIC_RG_TRIM_75K_CK_PDN_MASK                     0x1
#define PMIC_RG_TRIM_75K_CK_PDN_SHIFT                    8
#define PMIC_RG_CHDET_75K_CK_PDN_MASK                    0x1
#define PMIC_RG_CHDET_75K_CK_PDN_SHIFT                   9
#define PMIC_RG_SPI_CK_PDN_MASK                          0x1
#define PMIC_RG_SPI_CK_PDN_SHIFT                         10
#define PMIC_RG_REG_CK_PDN_MASK                          0x1
#define PMIC_RG_REG_CK_PDN_SHIFT                         11
#define PMIC_RG_BGR_TEST_CK_PDN_MASK                     0x1
#define PMIC_RG_BGR_TEST_CK_PDN_SHIFT                    12
#define PMIC_RG_FQMTR_32K_CK_PDN_MASK                    0x1
#define PMIC_RG_FQMTR_32K_CK_PDN_SHIFT                   13
#define PMIC_RG_FQMTR_CK_PDN_MASK                        0x1
#define PMIC_RG_FQMTR_CK_PDN_SHIFT                       14
#define PMIC_RG_BUCK_ANA_CK_PDN_MASK                     0x1
#define PMIC_RG_BUCK_ANA_CK_PDN_SHIFT                    15
#define PMIC_TOP_CKPDN_CON1_SET_MASK                     0xFFFF
#define PMIC_TOP_CKPDN_CON1_SET_SHIFT                    0
#define PMIC_TOP_CKPDN_CON1_CLR_MASK                     0xFFFF
#define PMIC_TOP_CKPDN_CON1_CLR_SHIFT                    0
#define PMIC_RG_EOSC_CALI_TEST_CK_PDN_MASK               0x1
#define PMIC_RG_EOSC_CALI_TEST_CK_PDN_SHIFT              0
#define PMIC_RG_RTC_EOSC32_CK_PDN_MASK                   0x1
#define PMIC_RG_RTC_EOSC32_CK_PDN_SHIFT                  1
#define PMIC_RG_RTC_SEC_32K_CK_PDN_MASK                  0x1
#define PMIC_RG_RTC_SEC_32K_CK_PDN_SHIFT                 2
#define PMIC_RG_RTC_MCLK_PDN_MASK                        0x1
#define PMIC_RG_RTC_MCLK_PDN_SHIFT                       4
#define PMIC_RG_RTC_32K_CK_PDN_MASK                      0x1
#define PMIC_RG_RTC_32K_CK_PDN_SHIFT                     5
#define PMIC_RG_RTC_26M_CK_PDN_MASK                      0x1
#define PMIC_RG_RTC_26M_CK_PDN_SHIFT                     6
#define PMIC_RG_FGADC_FT_CK_PDN_MASK                     0x1
#define PMIC_RG_FGADC_FT_CK_PDN_SHIFT                    7
#define PMIC_RG_FGADC_DIG_CK_PDN_MASK                    0x1
#define PMIC_RG_FGADC_DIG_CK_PDN_SHIFT                   8
#define PMIC_RG_FGADC_ANA_CK_PDN_MASK                    0x1
#define PMIC_RG_FGADC_ANA_CK_PDN_SHIFT                   9
#define PMIC_RG_STRUP_32K_CK_PDN_MASK                    0x1
#define PMIC_RG_STRUP_32K_CK_PDN_SHIFT                   10
#define PMIC_RG_STRUP_75K_CK_PDN_MASK                    0x1
#define PMIC_RG_STRUP_75K_CK_PDN_SHIFT                   11
#define PMIC_RG_RTC32K_1V8_0_O_PDN_MASK                  0x1
#define PMIC_RG_RTC32K_1V8_0_O_PDN_SHIFT                 12
#define PMIC_RG_RTC32K_1V8_1_O_PDN_MASK                  0x1
#define PMIC_RG_RTC32K_1V8_1_O_PDN_SHIFT                 13
#define PMIC_RG_RTC_2SEC_OFF_DET_PDN_MASK                0x1
#define PMIC_RG_RTC_2SEC_OFF_DET_PDN_SHIFT               14
#define PMIC_RG_SMPS_CK_DIV_PDN_MASK                     0x1
#define PMIC_RG_SMPS_CK_DIV_PDN_SHIFT                    15
#define PMIC_TOP_CKPDN_CON2_SET_MASK                     0xFFFF
#define PMIC_TOP_CKPDN_CON2_SET_SHIFT                    0
#define PMIC_TOP_CKPDN_CON2_CLR_MASK                     0xFFFF
#define PMIC_TOP_CKPDN_CON2_CLR_SHIFT                    0
#define PMIC_RG_BATON_75K_CK_PDN_MASK                    0x1
#define PMIC_RG_BATON_75K_CK_PDN_SHIFT                   0
#define PMIC_RG_EFUSE_CK_PDN_MASK                        0x1
#define PMIC_RG_EFUSE_CK_PDN_SHIFT                       1
#define PMIC_RG_ACCDET_CK_PDN_MASK                       0x1
#define PMIC_RG_ACCDET_CK_PDN_SHIFT                      2
#define PMIC_RG_AUD_CK_PDN_MASK                          0x1
#define PMIC_RG_AUD_CK_PDN_SHIFT                         3
#define PMIC_RG_AUDIF_CK_PDN_MASK                        0x1
#define PMIC_RG_AUDIF_CK_PDN_SHIFT                       4
#define PMIC_RG_VOW32K_CK_PDN_MASK                       0x1
#define PMIC_RG_VOW32K_CK_PDN_SHIFT                      5
#define PMIC_RG_VOW12M_CK_PDN_MASK                       0x1
#define PMIC_RG_VOW12M_CK_PDN_SHIFT                      6
#define PMIC_RG_ZCD13M_CK_PDN_MASK                       0x1
#define PMIC_RG_ZCD13M_CK_PDN_SHIFT                      7
#define PMIC_RG_RTC_SEC_MCLK_PDN_MASK                    0x1
#define PMIC_RG_RTC_SEC_MCLK_PDN_SHIFT                   8
#define PMIC_RG_AUXADC_32K_CK_PDN_MASK                   0x1
#define PMIC_RG_AUXADC_32K_CK_PDN_SHIFT                  9
#define PMIC_RG_EINT_32K_CK_PDN_MASK                     0x1
#define PMIC_RG_EINT_32K_CK_PDN_SHIFT                    10
#define PMIC_RG_TOP_CKPDN_CON3_RSV_MASK                  0x1F
#define PMIC_RG_TOP_CKPDN_CON3_RSV_SHIFT                 11
#define PMIC_TOP_CKPDN_CON3_SET_MASK                     0xFFFF
#define PMIC_TOP_CKPDN_CON3_SET_SHIFT                    0
#define PMIC_TOP_CKPDN_CON3_CLR_MASK                     0xFFFF
#define PMIC_TOP_CKPDN_CON3_CLR_SHIFT                    0
#define PMIC_RG_RTCDET_CK_PDN_MASK                       0x1
#define PMIC_RG_RTCDET_CK_PDN_SHIFT                      0
#define PMIC_RG_RTC_75K_CK_PDN_MASK                      0x1
#define PMIC_RG_RTC_75K_CK_PDN_SHIFT                     1
#define PMIC_TOP_CKPDN_CON4_SET_MASK                     0xFFFF
#define PMIC_TOP_CKPDN_CON4_SET_SHIFT                    0
#define PMIC_TOP_CKPDN_CON4_CLR_MASK                     0xFFFF
#define PMIC_TOP_CKPDN_CON4_CLR_SHIFT                    0
#define PMIC_RG_FQMTR_CK_CKSEL_MASK                      0x7
#define PMIC_RG_FQMTR_CK_CKSEL_SHIFT                     0
#define PMIC_RG_75K_32K_SEL_MASK                         0x1
#define PMIC_RG_75K_32K_SEL_SHIFT                        3
#define PMIC_RG_FGADC_ANA_CK_CKSEL_MASK                  0x1
#define PMIC_RG_FGADC_ANA_CK_CKSEL_SHIFT                 4
#define PMIC_RG_BGR_TEST_CK_CKSEL_MASK                   0x1
#define PMIC_RG_BGR_TEST_CK_CKSEL_SHIFT                  5
#define PMIC_RG_AUD_CK_CKSEL_MASK                        0x1
#define PMIC_RG_AUD_CK_CKSEL_SHIFT                       6
#define PMIC_RG_AUDIF_CK_CKSEL_MASK                      0x1
#define PMIC_RG_AUDIF_CK_CKSEL_SHIFT                     7
#define PMIC_RG_TOP_CKSEL_CON0_RSV_MASK                  0xFF
#define PMIC_RG_TOP_CKSEL_CON0_RSV_SHIFT                 8
#define PMIC_TOP_CKSEL_CON0_SET_MASK                     0xFFFF
#define PMIC_TOP_CKSEL_CON0_SET_SHIFT                    0
#define PMIC_TOP_CKSEL_CON0_CLR_MASK                     0xFFFF
#define PMIC_TOP_CKSEL_CON0_CLR_SHIFT                    0
#define PMIC_RG_SRCVOLTEN_SW_MASK                        0x1
#define PMIC_RG_SRCVOLTEN_SW_SHIFT                       0
#define PMIC_RG_BUCK_OSC_SEL_SW_MASK                     0x1
#define PMIC_RG_BUCK_OSC_SEL_SW_SHIFT                    2
#define PMIC_RG_VOWEN_SW_MASK                            0x1
#define PMIC_RG_VOWEN_SW_SHIFT                           3
#define PMIC_RG_SRCVOLTEN_MODE_MASK                      0x1
#define PMIC_RG_SRCVOLTEN_MODE_SHIFT                     4
#define PMIC_RG_BUCK_OSC_SEL_MODE_MASK                   0x1
#define PMIC_RG_BUCK_OSC_SEL_MODE_SHIFT                  6
#define PMIC_RG_VOWEN_MODE_MASK                          0x1
#define PMIC_RG_VOWEN_MODE_SHIFT                         7
#define PMIC_RG_TOP_CKSEL_CON2_RSV_MASK                  0xFF
#define PMIC_RG_TOP_CKSEL_CON2_RSV_SHIFT                 8
#define PMIC_TOP_CKSEL_CON2_SET_MASK                     0xFFFF
#define PMIC_TOP_CKSEL_CON2_SET_SHIFT                    0
#define PMIC_TOP_CKSEL_CON2_CLR_MASK                     0xFFFF
#define PMIC_TOP_CKSEL_CON2_CLR_SHIFT                    0
#define PMIC_RG_AUXADC_CK_DIVSEL_MASK                    0x3
#define PMIC_RG_AUXADC_CK_DIVSEL_SHIFT                   0
#define PMIC_RG_LDO_9M_CK_DIVSEL_MASK                    0x1
#define PMIC_RG_LDO_9M_CK_DIVSEL_SHIFT                   2
#define PMIC_RG_BUCK_9M_CK_DIVSEL_MASK                   0x1
#define PMIC_RG_BUCK_9M_CK_DIVSEL_SHIFT                  3
#define PMIC_RG_BIF_X4_CK_DIVSEL_MASK                    0x7
#define PMIC_RG_BIF_X4_CK_DIVSEL_SHIFT                   4
#define PMIC_RG_REG_CK_DIVSEL_MASK                       0x3
#define PMIC_RG_REG_CK_DIVSEL_SHIFT                      8
#define PMIC_TOP_CKDIVSEL_CON0_RSV_MASK                  0x3F
#define PMIC_TOP_CKDIVSEL_CON0_RSV_SHIFT                 10
#define PMIC_TOP_CKDIVSEL_CON0_SET_MASK                  0xFFFF
#define PMIC_TOP_CKDIVSEL_CON0_SET_SHIFT                 0
#define PMIC_TOP_CKDIVSEL_CON0_CLR_MASK                  0xFFFF
#define PMIC_TOP_CKDIVSEL_CON0_CLR_SHIFT                 0
#define PMIC_RG_G_SMPS_CK_PDN_HWEN_MASK                  0x1
#define PMIC_RG_G_SMPS_CK_PDN_HWEN_SHIFT                 0
#define PMIC_RG_SMPS_PD_1M_CK_PDN_HWEN_MASK              0x1
#define PMIC_RG_SMPS_PD_1M_CK_PDN_HWEN_SHIFT             1
#define PMIC_RG_AUXADC_CK_PDN_HWEN_MASK                  0x1
#define PMIC_RG_AUXADC_CK_PDN_HWEN_SHIFT                 2
#define PMIC_RG_AUXADC_RNG_CK_PDN_HWEN_MASK              0x1
#define PMIC_RG_AUXADC_RNG_CK_PDN_HWEN_SHIFT             3
#define PMIC_RG_BIF_X4_CK_PDN_HWEN_MASK                  0x1
#define PMIC_RG_BIF_X4_CK_PDN_HWEN_SHIFT                 4
#define PMIC_RG_BIF_X72_CK_PDN_HWEN_MASK                 0x1
#define PMIC_RG_BIF_X72_CK_PDN_HWEN_SHIFT                5
#define PMIC_RG_RTC_26M_CK_PDN_HWEN_MASK                 0x1
#define PMIC_RG_RTC_26M_CK_PDN_HWEN_SHIFT                6
#define PMIC_RG_REG_CK_PDN_HWEN_MASK                     0x1
#define PMIC_RG_REG_CK_PDN_HWEN_SHIFT                    7
#define PMIC_RG_RTC_MCLK_PDN_HWEN_MASK                   0x1
#define PMIC_RG_RTC_MCLK_PDN_HWEN_SHIFT                  8
#define PMIC_RG_RTC_SEC_32K_CK_PDN_HWEN_MASK             0x1
#define PMIC_RG_RTC_SEC_32K_CK_PDN_HWEN_SHIFT            9
#define PMIC_RG_EFUSE_CK_PDN_HWEN_MASK                   0x1
#define PMIC_RG_EFUSE_CK_PDN_HWEN_SHIFT                  10
#define PMIC_RG_RTC_SEC_MCLK_PDN_HWEN_MASK               0x1
#define PMIC_RG_RTC_SEC_MCLK_PDN_HWEN_SHIFT              11
#define PMIC_RG_AUXADC_32K_CK_PDN_HWEN_MASK              0x1
#define PMIC_RG_AUXADC_32K_CK_PDN_HWEN_SHIFT             12
#define PMIC_RG_EINT_32K_CK_PDN_HWEN_MASK                0x1
#define PMIC_RG_EINT_32K_CK_PDN_HWEN_SHIFT               13
#define PMIC_TOP_CKHWEN_CON0_RSV_MASK                    0x3
#define PMIC_TOP_CKHWEN_CON0_RSV_SHIFT                   14
#define PMIC_TOP_CKHWEN_CON0_SET_MASK                    0xFFFF
#define PMIC_TOP_CKHWEN_CON0_SET_SHIFT                   0
#define PMIC_TOP_CKHWEN_CON0_CLR_MASK                    0xFFFF
#define PMIC_TOP_CKHWEN_CON0_CLR_SHIFT                   0
#define PMIC_RG_BUCK_9M_CK_PDN_HWEN_MASK                 0x1
#define PMIC_RG_BUCK_9M_CK_PDN_HWEN_SHIFT                0
#define PMIC_RG_BUCK_1M_CK_PDN_HWEN_MASK                 0x1
#define PMIC_RG_BUCK_1M_CK_PDN_HWEN_SHIFT                1
#define PMIC_RG_BUCK_18M_CK_PDN_HWEN_MASK                0x1
#define PMIC_RG_BUCK_18M_CK_PDN_HWEN_SHIFT               2
#define PMIC_RG_LDO_1M_CK_PDN_HWEN_MASK                  0x1
#define PMIC_RG_LDO_1M_CK_PDN_HWEN_SHIFT                 4
#define PMIC_RG_LDO_9M_CK_PDN_HWEN_MASK                  0x1
#define PMIC_RG_LDO_9M_CK_PDN_HWEN_SHIFT                 5
#define PMIC_RG_BUCK_VMODEM_1M_CK_PDN_HWEN_MASK          0x1
#define PMIC_RG_BUCK_VMODEM_1M_CK_PDN_HWEN_SHIFT         6
#define PMIC_RG_AUXADC_1M_CK_PDN_HWEN_MASK               0x1
#define PMIC_RG_AUXADC_1M_CK_PDN_HWEN_SHIFT              7
#define PMIC_TOP_CKHWEN_RSV_MASK                         0xFF
#define PMIC_TOP_CKHWEN_RSV_SHIFT                        8
#define PMIC_TOP_CKHWEN_CON1_SET_MASK                    0xFFFF
#define PMIC_TOP_CKHWEN_CON1_SET_SHIFT                   0
#define PMIC_TOP_CKHWEN_CON1_CLR_MASK                    0xFFFF
#define PMIC_TOP_CKHWEN_CON1_CLR_SHIFT                   0
#define PMIC_RG_VPROC11_FREQ_SEL_MASK                    0x3
#define PMIC_RG_VPROC11_FREQ_SEL_SHIFT                   0
#define PMIC_RG_VPROC12_FREQ_SEL_MASK                    0x3
#define PMIC_RG_VPROC12_FREQ_SEL_SHIFT                   2
#define PMIC_RG_VCORE_FREQ_SEL_MASK                      0x3
#define PMIC_RG_VCORE_FREQ_SEL_SHIFT                     4
#define PMIC_RG_VGPU_FREQ_SEL_MASK                       0x3
#define PMIC_RG_VGPU_FREQ_SEL_SHIFT                      6
#define PMIC_RG_VDRAM1_FREQ_SEL_MASK                     0x3
#define PMIC_RG_VDRAM1_FREQ_SEL_SHIFT                    8
#define PMIC_RG_VDRAM2_FREQ_SEL_MASK                     0x3
#define PMIC_RG_VDRAM2_FREQ_SEL_SHIFT                    10
#define PMIC_RG_VMODEM_FREQ_SEL_MASK                     0x3
#define PMIC_RG_VMODEM_FREQ_SEL_SHIFT                    12
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON0_RSV_MASK       0x3
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON0_RSV_SHIFT      14
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON0_SET_MASK       0xFFFF
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON0_SET_SHIFT      0
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON0_CLR_MASK       0xFFFF
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON0_CLR_SHIFT      0
#define PMIC_RG_VS1_FREQ_SEL_MASK                        0x3
#define PMIC_RG_VS1_FREQ_SEL_SHIFT                       0
#define PMIC_RG_VS2_FREQ_SEL_MASK                        0x3
#define PMIC_RG_VS2_FREQ_SEL_SHIFT                       2
#define PMIC_RG_VPA_PHS_SEL_MASK                         0x3
#define PMIC_RG_VPA_PHS_SEL_SHIFT                        4
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON1_RSV_MASK       0x3FF
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON1_RSV_SHIFT      6
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON1_SET_MASK       0xFFFF
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON1_SET_SHIFT      0
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON1_CLR_MASK       0xFFFF
#define PMIC_TOP_BUCK_ANACK_FREQ_SEL_CON1_CLR_SHIFT      0
#define PMIC_RG_PMU75K_CK_TST_DIS_MASK                   0x1
#define PMIC_RG_PMU75K_CK_TST_DIS_SHIFT                  0
#define PMIC_RG_SMPS_CK_TST_DIS_MASK                     0x1
#define PMIC_RG_SMPS_CK_TST_DIS_SHIFT                    1
#define PMIC_RG_RTC32K_CK_TST_DIS_MASK                   0x1
#define PMIC_RG_RTC32K_CK_TST_DIS_SHIFT                  2
#define PMIC_RG_FG_CK_TST_DIS_MASK                       0x1
#define PMIC_RG_FG_CK_TST_DIS_SHIFT                      3
#define PMIC_RG_RTC26M_CK_TST_DIS_MASK                   0x1
#define PMIC_RG_RTC26M_CK_TST_DIS_SHIFT                  4
#define PMIC_RG_AUD26M_CK_TST_DIS_MASK                   0x1
#define PMIC_RG_AUD26M_CK_TST_DIS_SHIFT                  5
#define PMIC_RG_VOW12M_CK_TST_DIS_MASK                   0x1
#define PMIC_RG_VOW12M_CK_TST_DIS_SHIFT                  6
#define PMIC_TOP_CKTST_CON0_RSV_MASK                     0xFF
#define PMIC_TOP_CKTST_CON0_RSV_SHIFT                    7
#define PMIC_RG_BUCK_ANA_AUTO_OFF_DIS_MASK               0x1
#define PMIC_RG_BUCK_ANA_AUTO_OFF_DIS_SHIFT              15
#define PMIC_RG_AUXADC_CK_TSTSEL_MASK                    0x1
#define PMIC_RG_AUXADC_CK_TSTSEL_SHIFT                   0
#define PMIC_RG_FQMTR_CK_TSTSEL_MASK                     0x1
#define PMIC_RG_FQMTR_CK_TSTSEL_SHIFT                    1
#define PMIC_RG_RTCDET_CK_TSTSEL_MASK                    0x1
#define PMIC_RG_RTCDET_CK_TSTSEL_SHIFT                   2
#define PMIC_RG_RTC_EOSC32_CK_TSTSEL_MASK                0x1
#define PMIC_RG_RTC_EOSC32_CK_TSTSEL_SHIFT               3
#define PMIC_RG_EOSC_CALI_TEST_CK_TSTSEL_MASK            0x1
#define PMIC_RG_EOSC_CALI_TEST_CK_TSTSEL_SHIFT           4
#define PMIC_RG_RTC26M_CK_TSTSEL_MASK                    0x1
#define PMIC_RG_RTC26M_CK_TSTSEL_SHIFT                   5
#define PMIC_RG_RTC32K_CK_TSTSEL_MASK                    0x1
#define PMIC_RG_RTC32K_CK_TSTSEL_SHIFT                   6
#define PMIC_RG_FG_CK_TSTSEL_MASK                        0x1
#define PMIC_RG_FG_CK_TSTSEL_SHIFT                       7
#define PMIC_RG_FGADC_ANA_CK_TSTSEL_MASK                 0x1
#define PMIC_RG_FGADC_ANA_CK_TSTSEL_SHIFT                8
#define PMIC_RG_BGR_TEST_CK_TSTSEL_MASK                  0x1
#define PMIC_RG_BGR_TEST_CK_TSTSEL_SHIFT                 9
#define PMIC_RG_PMU75K_CK_TSTSEL_MASK                    0x1
#define PMIC_RG_PMU75K_CK_TSTSEL_SHIFT                   10
#define PMIC_RG_SMPS_CK_TSTSEL_MASK                      0x1
#define PMIC_RG_SMPS_CK_TSTSEL_SHIFT                     11
#define PMIC_RG_AUD_CK_TSTSEL_MASK                       0x1
#define PMIC_RG_AUD_CK_TSTSEL_SHIFT                      12
#define PMIC_RG_AUDIF_CK_TSTSEL_MASK                     0x1
#define PMIC_RG_AUDIF_CK_TSTSEL_SHIFT                    13
#define PMIC_RG_AUD26M_CK_TSTSEL_MASK                    0x1
#define PMIC_RG_AUD26M_CK_TSTSEL_SHIFT                   14
#define PMIC_RG_VOW12M_CK_TSTSEL_MASK                    0x1
#define PMIC_RG_VOW12M_CK_TSTSEL_SHIFT                   15
#define PMIC_RG_CLKSQ_EN_AUD_MASK                        0x1
#define PMIC_RG_CLKSQ_EN_AUD_SHIFT                       0
#define PMIC_RG_CLKSQ_EN_FQR_MASK                        0x1
#define PMIC_RG_CLKSQ_EN_FQR_SHIFT                       1
#define PMIC_RG_CLKSQ_EN_AUX_AP_MASK                     0x1
#define PMIC_RG_CLKSQ_EN_AUX_AP_SHIFT                    2
#define PMIC_RG_CLKSQ_EN_AUX_MD_MASK                     0x1
#define PMIC_RG_CLKSQ_EN_AUX_MD_SHIFT                    3
#define PMIC_RG_CLKSQ_EN_AUX_GPS_MASK                    0x1
#define PMIC_RG_CLKSQ_EN_AUX_GPS_SHIFT                   4
#define PMIC_RG_CLKSQ_EN_AUX_RSV_MASK                    0x1
#define PMIC_RG_CLKSQ_EN_AUX_RSV_SHIFT                   5
#define PMIC_RG_CLKSQ_EN_AUX_AP_MODE_MASK                0x1
#define PMIC_RG_CLKSQ_EN_AUX_AP_MODE_SHIFT               8
#define PMIC_RG_CLKSQ_EN_AUX_MD_MODE_MASK                0x1
#define PMIC_RG_CLKSQ_EN_AUX_MD_MODE_SHIFT               9
#define PMIC_RG_CLKSQ_IN_SEL_VA18_MASK                   0x1
#define PMIC_RG_CLKSQ_IN_SEL_VA18_SHIFT                  10
#define PMIC_RG_CLKSQ_IN_SEL_VA18_SWCTRL_MASK            0x1
#define PMIC_RG_CLKSQ_IN_SEL_VA18_SWCTRL_SHIFT           11
#define PMIC_TOP_CLKSQ_RSV_MASK                          0x7
#define PMIC_TOP_CLKSQ_RSV_SHIFT                         12
#define PMIC_DA_CLKSQ_EN_VA18_MASK                       0x1
#define PMIC_DA_CLKSQ_EN_VA18_SHIFT                      15
#define PMIC_TOP_CLKSQ_SET_MASK                          0xFFFF
#define PMIC_TOP_CLKSQ_SET_SHIFT                         0
#define PMIC_TOP_CLKSQ_CLR_MASK                          0xFFFF
#define PMIC_TOP_CLKSQ_CLR_SHIFT                         0
#define PMIC_RG_CLKSQ_RTC_EN_MASK                        0x1
#define PMIC_RG_CLKSQ_RTC_EN_SHIFT                       0
#define PMIC_RG_CLKSQ_RTC_EN_HW_MODE_MASK                0x1
#define PMIC_RG_CLKSQ_RTC_EN_HW_MODE_SHIFT               1
#define PMIC_TOP_CLKSQ_RTC_RSV0_MASK                     0xF
#define PMIC_TOP_CLKSQ_RTC_RSV0_SHIFT                    2
#define PMIC_RG_ENBB_SEL_MASK                            0x1
#define PMIC_RG_ENBB_SEL_SHIFT                           8
#define PMIC_RG_XOSC_EN_SEL_MASK                         0x1
#define PMIC_RG_XOSC_EN_SEL_SHIFT                        9
#define PMIC_TOP_CLKSQ_RTC_RSV1_MASK                     0x3
#define PMIC_TOP_CLKSQ_RTC_RSV1_SHIFT                    10
#define PMIC_DA_CLKSQ_EN_VDIG18_MASK                     0x1
#define PMIC_DA_CLKSQ_EN_VDIG18_SHIFT                    15
#define PMIC_TOP_CLKSQ_RTC_SET_MASK                      0xFFFF
#define PMIC_TOP_CLKSQ_RTC_SET_SHIFT                     0
#define PMIC_TOP_CLKSQ_RTC_CLR_MASK                      0xFFFF
#define PMIC_TOP_CLKSQ_RTC_CLR_SHIFT                     0
#define PMIC_RG_OSC_75K_TRIM_MASK                        0x3F
#define PMIC_RG_OSC_75K_TRIM_SHIFT                       0
#define PMIC_RG_OSC_75K_TRIM_EN_MASK                     0x1
#define PMIC_RG_OSC_75K_TRIM_EN_SHIFT                    6
#define PMIC_RG_OSC_75K_TRIM_RATE_MASK                   0x3
#define PMIC_RG_OSC_75K_TRIM_RATE_SHIFT                  7
#define PMIC_DA_OSC_75K_TRIM_MASK                        0x3F
#define PMIC_DA_OSC_75K_TRIM_SHIFT                       9
#define PMIC_RG_G_SMPS_CK_PDN_SRCLKEN0_EN_MASK           0x1
#define PMIC_RG_G_SMPS_CK_PDN_SRCLKEN0_EN_SHIFT          0
#define PMIC_RG_G_SMPS_CK_PDN_SRCLKEN1_EN_MASK           0x1
#define PMIC_RG_G_SMPS_CK_PDN_SRCLKEN1_EN_SHIFT          1
#define PMIC_RG_G_SMPS_CK_PDN_SRCLKEN2_EN_MASK           0x1
#define PMIC_RG_G_SMPS_CK_PDN_SRCLKEN2_EN_SHIFT          2
#define PMIC_RG_G_SMPS_CK_PDN_BUCK_OSC_SEL_EN_MASK       0x1
#define PMIC_RG_G_SMPS_CK_PDN_BUCK_OSC_SEL_EN_SHIFT      3
#define PMIC_RG_G_SMPS_CK_PDN_VOWEN_EN_MASK              0x1
#define PMIC_RG_G_SMPS_CK_PDN_VOWEN_EN_SHIFT             4
#define PMIC_RG_OSC_SEL_SRCLKEN0_EN_MASK                 0x1
#define PMIC_RG_OSC_SEL_SRCLKEN0_EN_SHIFT                5
#define PMIC_RG_OSC_SEL_SRCLKEN1_EN_MASK                 0x1
#define PMIC_RG_OSC_SEL_SRCLKEN1_EN_SHIFT                6
#define PMIC_RG_OSC_SEL_SRCLKEN2_EN_MASK                 0x1
#define PMIC_RG_OSC_SEL_SRCLKEN2_EN_SHIFT                7
#define PMIC_RG_OSC_SEL_BUCK_LDO_EN_MASK                 0x1
#define PMIC_RG_OSC_SEL_BUCK_LDO_EN_SHIFT                8
#define PMIC_RG_OSC_SEL_VOWEN_EN_MASK                    0x1
#define PMIC_RG_OSC_SEL_VOWEN_EN_SHIFT                   9
#define PMIC_RG_CLK_RSV_MASK                             0x3F
#define PMIC_RG_CLK_RSV_SHIFT                            10
#define PMIC_TOP_CLK_CON0_SET_MASK                       0xFFFF
#define PMIC_TOP_CLK_CON0_SET_SHIFT                      0
#define PMIC_TOP_CLK_CON0_CLR_MASK                       0xFFFF
#define PMIC_TOP_CLK_CON0_CLR_SHIFT                      0
#define PMIC_RG_VPROC2_CKMUX_EN_MASK                     0x1
#define PMIC_RG_VPROC2_CKMUX_EN_SHIFT                    0
#define PMIC_RG_VPA_SW_PDN_EN_MASK                       0x1
#define PMIC_RG_VPA_SW_PDN_EN_SHIFT                      1
#define PMIC_RG_LDO_1M_PDN_W_OSC_SEL_MASK                0x1
#define PMIC_RG_LDO_1M_PDN_W_OSC_SEL_SHIFT               2
#define PMIC_RG_BUCK_1M_PDN_W_OSC_SEL_MASK               0x1
#define PMIC_RG_BUCK_1M_PDN_W_OSC_SEL_SHIFT              3
#define PMIC_RG_CLKCTL_RSV0_MASK                         0xFFF
#define PMIC_RG_CLKCTL_RSV0_SHIFT                        4
#define PMIC_TOP_CLK_CON1_SET_MASK                       0xFFFF
#define PMIC_TOP_CLK_CON1_SET_SHIFT                      0
#define PMIC_TOP_CLK_CON1_CLR_MASK                       0xFFFF
#define PMIC_TOP_CLK_CON1_CLR_SHIFT                      0
#define PMIC_RG_DCXO_PWRKEY_RSTB_SEL_MASK                0x1
#define PMIC_RG_DCXO_PWRKEY_RSTB_SEL_SHIFT               0
#define PMIC_RG_EFUSE_MAN_RST_MASK                       0x1
#define PMIC_RG_EFUSE_MAN_RST_SHIFT                      0
#define PMIC_RG_AUXADC_RST_MASK                          0x1
#define PMIC_RG_AUXADC_RST_SHIFT                         1
#define PMIC_RG_AUXADC_REG_RST_MASK                      0x1
#define PMIC_RG_AUXADC_REG_RST_SHIFT                     2
#define PMIC_RG_AUDIO_RST_MASK                           0x1
#define PMIC_RG_AUDIO_RST_SHIFT                          3
#define PMIC_RG_ACCDET_RST_MASK                          0x1
#define PMIC_RG_ACCDET_RST_SHIFT                         4
#define PMIC_RG_BIF_RST_MASK                             0x1
#define PMIC_RG_BIF_RST_SHIFT                            5
#define PMIC_RG_DRIVER_RST_MASK                          0x1
#define PMIC_RG_DRIVER_RST_SHIFT                         6
#define PMIC_RG_FGADC_RST_MASK                           0x1
#define PMIC_RG_FGADC_RST_SHIFT                          7
#define PMIC_RG_FQMTR_RST_MASK                           0x1
#define PMIC_RG_FQMTR_RST_SHIFT                          8
#define PMIC_RG_RTC_RST_MASK                             0x1
#define PMIC_RG_RTC_RST_SHIFT                            9
#define PMIC_RG_TYPE_C_CC_RST_MASK                       0x1
#define PMIC_RG_TYPE_C_CC_RST_SHIFT                      10
#define PMIC_RG_CHRWDT_RST_MASK                          0x1
#define PMIC_RG_CHRWDT_RST_SHIFT                         11
#define PMIC_RG_ZCD_RST_MASK                             0x1
#define PMIC_RG_ZCD_RST_SHIFT                            12
#define PMIC_RG_AUDNCP_RST_MASK                          0x1
#define PMIC_RG_AUDNCP_RST_SHIFT                         13
#define PMIC_RG_CLK_TRIM_RST_MASK                        0x1
#define PMIC_RG_CLK_TRIM_RST_SHIFT                       14
#define PMIC_RG_BUCK_SRCLKEN_RST_MASK                    0x1
#define PMIC_RG_BUCK_SRCLKEN_RST_SHIFT                   15
#define PMIC_TOP_RST_CON0_SET_MASK                       0xFFFF
#define PMIC_TOP_RST_CON0_SET_SHIFT                      0
#define PMIC_TOP_RST_CON0_CLR_MASK                       0xFFFF
#define PMIC_TOP_RST_CON0_CLR_SHIFT                      0
#define PMIC_RG_STRUP_LONG_PRESS_RST_MASK                0x1
#define PMIC_RG_STRUP_LONG_PRESS_RST_SHIFT               0
#define PMIC_RG_BUCK_PROT_PMPP_RST_MASK                  0x1
#define PMIC_RG_BUCK_PROT_PMPP_RST_SHIFT                 1
#define PMIC_RG_SPK_RST_MASK                             0x1
#define PMIC_RG_SPK_RST_SHIFT                            2
#define PMIC_RG_CHRDET_RST_MASK                          0x1
#define PMIC_RG_CHRDET_RST_SHIFT                         3
#define PMIC_RG_BUCK_LDO_FT_TESTMODE_RST_MASK            0x1
#define PMIC_RG_BUCK_LDO_FT_TESTMODE_RST_SHIFT           4
#define PMIC_RG_BATON_RST_MASK                           0x1
#define PMIC_RG_BATON_RST_SHIFT                          5
#define PMIC_RG_FGADC_RST_SRC_SEL_MASK                   0x1
#define PMIC_RG_FGADC_RST_SRC_SEL_SHIFT                  6
#define PMIC_RG_LDO_CALI_RST_MASK                        0x1
#define PMIC_RG_LDO_CALI_RST_SHIFT                       7
#define PMIC_RG_PSEQ_PWRMSK_RST_SEL_MASK                 0x1
#define PMIC_RG_PSEQ_PWRMSK_RST_SEL_SHIFT                8
#define PMIC_TOP_RST_CON1_RSV_MASK                       0x1
#define PMIC_TOP_RST_CON1_RSV_SHIFT                      9
#define PMIC_TOP_RST_CON1_SET_MASK                       0xFFFF
#define PMIC_TOP_RST_CON1_SET_SHIFT                      0
#define PMIC_TOP_RST_CON1_CLR_MASK                       0xFFFF
#define PMIC_TOP_RST_CON1_CLR_SHIFT                      0
#define PMIC_RG_CHR_LDO_DET_MODE_MASK                    0x1
#define PMIC_RG_CHR_LDO_DET_MODE_SHIFT                   0
#define PMIC_RG_CHR_LDO_DET_SW_MASK                      0x1
#define PMIC_RG_CHR_LDO_DET_SW_SHIFT                     1
#define PMIC_RG_CHRWDT_FLAG_MODE_MASK                    0x1
#define PMIC_RG_CHRWDT_FLAG_MODE_SHIFT                   2
#define PMIC_RG_CHRWDT_FLAG_SW_MASK                      0x1
#define PMIC_RG_CHRWDT_FLAG_SW_SHIFT                     3
#define PMIC_TOP_RST_CON2_RSV_MASK                       0xF
#define PMIC_TOP_RST_CON2_RSV_SHIFT                      4
#define PMIC_RG_WDTRSTB_EN_MASK                          0x1
#define PMIC_RG_WDTRSTB_EN_SHIFT                         0
#define PMIC_RG_WDTRSTB_MODE_MASK                        0x1
#define PMIC_RG_WDTRSTB_MODE_SHIFT                       1
#define PMIC_WDTRSTB_STATUS_MASK                         0x1
#define PMIC_WDTRSTB_STATUS_SHIFT                        2
#define PMIC_WDTRSTB_STATUS_CLR_MASK                     0x1
#define PMIC_WDTRSTB_STATUS_CLR_SHIFT                    3
#define PMIC_RG_WDTRSTB_FB_EN_MASK                       0x1
#define PMIC_RG_WDTRSTB_FB_EN_SHIFT                      4
#define PMIC_RG_WDTRSTB_DEB_MASK                         0x1
#define PMIC_RG_WDTRSTB_DEB_SHIFT                        5
#define PMIC_RG_HOMEKEY_RST_EN_MASK                      0x1
#define PMIC_RG_HOMEKEY_RST_EN_SHIFT                     8
#define PMIC_RG_PWRKEY_RST_EN_MASK                       0x1
#define PMIC_RG_PWRKEY_RST_EN_SHIFT                      9
#define PMIC_RG_PWRRST_TMR_DIS_MASK                      0x1
#define PMIC_RG_PWRRST_TMR_DIS_SHIFT                     10
#define PMIC_RG_PWRKEY_RST_TD_MASK                       0x3
#define PMIC_RG_PWRKEY_RST_TD_SHIFT                      12
#define PMIC_TOP_RST_MISC_RSV_MASK                       0x3
#define PMIC_TOP_RST_MISC_RSV_SHIFT                      14
#define PMIC_TOP_RST_MISC_SET_MASK                       0xFFFF
#define PMIC_TOP_RST_MISC_SET_SHIFT                      0
#define PMIC_TOP_RST_MISC_CLR_MASK                       0xFFFF
#define PMIC_TOP_RST_MISC_CLR_SHIFT                      0
#define PMIC_VPWRIN_RSTB_STATUS_MASK                     0x1
#define PMIC_VPWRIN_RSTB_STATUS_SHIFT                    0
#define PMIC_DDLO_RSTB_STATUS_MASK                       0x1
#define PMIC_DDLO_RSTB_STATUS_SHIFT                      1
#define PMIC_UVLO_RSTB_STATUS_MASK                       0x1
#define PMIC_UVLO_RSTB_STATUS_SHIFT                      2
#define PMIC_RTC_DDLO_RSTB_STATUS_MASK                   0x1
#define PMIC_RTC_DDLO_RSTB_STATUS_SHIFT                  3
#define PMIC_CHRWDT_REG_RSTB_STATUS_MASK                 0x1
#define PMIC_CHRWDT_REG_RSTB_STATUS_SHIFT                4
#define PMIC_CHRDET_REG_RSTB_STATUS_MASK                 0x1
#define PMIC_CHRDET_REG_RSTB_STATUS_SHIFT                5
#define PMIC_BWDT_DDLO_RSTB_STATUS_MASK                  0x1
#define PMIC_BWDT_DDLO_RSTB_STATUS_SHIFT                 6
#define PMIC_TOP_RST_STATUS_RSV_MASK                     0x1
#define PMIC_TOP_RST_STATUS_RSV_SHIFT                    7
#define PMIC_TOP_RST_STATUS_SET_MASK                     0xFFFF
#define PMIC_TOP_RST_STATUS_SET_SHIFT                    0
#define PMIC_TOP_RST_STATUS_CLR_MASK                     0xFFFF
#define PMIC_TOP_RST_STATUS_CLR_SHIFT                    0
#define PMIC_TOP_RST_RSV_CON0_MASK                       0xFFFF
#define PMIC_TOP_RST_RSV_CON0_SHIFT                      0
#define PMIC_TOP_RST_RSV_CON1_MASK                       0xFFFF
#define PMIC_TOP_RST_RSV_CON1_SHIFT                      0
#define PMIC_BANK_FQMTR_SWRST_MASK                       0x1
#define PMIC_BANK_FQMTR_SWRST_SHIFT                      0
#define PMIC_BANK_SPI_SWRST_MASK                         0x1
#define PMIC_BANK_SPI_SWRST_SHIFT                        1
#define PMIC_BANK_STRUP_SWRST_MASK                       0x1
#define PMIC_BANK_STRUP_SWRST_SHIFT                      2
#define PMIC_BANK_BUCK_SWRST_MASK                        0x1
#define PMIC_BANK_BUCK_SWRST_SHIFT                       3
#define PMIC_BANK_BUCK_ANA_SWRST_MASK                    0x1
#define PMIC_BANK_BUCK_ANA_SWRST_SHIFT                   4
#define PMIC_BANK_WDTDBG_SWRST_MASK                      0x1
#define PMIC_BANK_WDTDBG_SWRST_SHIFT                     5
#define PMIC_BANK_LDO_0_SWRST_MASK                       0x1
#define PMIC_BANK_LDO_0_SWRST_SHIFT                      6
#define PMIC_BANK_LDO_1_SWRST_MASK                       0x1
#define PMIC_BANK_LDO_1_SWRST_SHIFT                      7
#define PMIC_BANK_LDO_ANA_SWRST_MASK                     0x1
#define PMIC_BANK_LDO_ANA_SWRST_SHIFT                    8
#define PMIC_BANK_ACCDET_SWRST_MASK                      0x1
#define PMIC_BANK_ACCDET_SWRST_SHIFT                     9
#define PMIC_BANK_EFUSE_SWRST_MASK                       0x1
#define PMIC_BANK_EFUSE_SWRST_SHIFT                      10
#define PMIC_BANK_DCXO_SWRST_MASK                        0x1
#define PMIC_BANK_DCXO_SWRST_SHIFT                       11
#define PMIC_BANK_PCHR_SWRST_MASK                        0x1
#define PMIC_BANK_PCHR_SWRST_SHIFT                       12
#define PMIC_BANK_GPIO_SWRST_MASK                        0x1
#define PMIC_BANK_GPIO_SWRST_SHIFT                       13
#define PMIC_BANK_EOSC_CALI_SWRST_MASK                   0x1
#define PMIC_BANK_EOSC_CALI_SWRST_SHIFT                  14
#define PMIC_BANK_VRTC_PWM_SWRST_MASK                    0x1
#define PMIC_BANK_VRTC_PWM_SWRST_SHIFT                   15
#define PMIC_TOP_RST_BANK_CON0_SET_MASK                  0xFFFF
#define PMIC_TOP_RST_BANK_CON0_SET_SHIFT                 0
#define PMIC_TOP_RST_BANK_CON0_CLR_MASK                  0xFFFF
#define PMIC_TOP_RST_BANK_CON0_CLR_SHIFT                 0
#define PMIC_BANK_RTC_SWRST_MASK                         0x1
#define PMIC_BANK_RTC_SWRST_SHIFT                        0
#define PMIC_BANK_RTC_SEC_SWRST_MASK                     0x1
#define PMIC_BANK_RTC_SEC_SWRST_SHIFT                    1
#define PMIC_BANK_BIF_SWRST_MASK                         0x1
#define PMIC_BANK_BIF_SWRST_SHIFT                        2
#define PMIC_BANK_FGADC_SWRST_MASK                       0x1
#define PMIC_BANK_FGADC_SWRST_SHIFT                      3
#define PMIC_BANK_AUXADC_SWRST_MASK                      0x1
#define PMIC_BANK_AUXADC_SWRST_SHIFT                     4
#define PMIC_BANK_DRIVER_SWRST_MASK                      0x1
#define PMIC_BANK_DRIVER_SWRST_SHIFT                     5
#define PMIC_BANK_AUDIO_SWRST_MASK                       0x1
#define PMIC_BANK_AUDIO_SWRST_SHIFT                      6
#define PMIC_BANK_AUDZCD_SWRST_MASK                      0x1
#define PMIC_BANK_AUDZCD_SWRST_SHIFT                     7
#define PMIC_TOP_RST_BANK_CON1_RSV_MASK                  0xFF
#define PMIC_TOP_RST_BANK_CON1_RSV_SHIFT                 8
#define PMIC_TOP_RST_BANK_CON1_SET_MASK                  0xFFFF
#define PMIC_TOP_RST_BANK_CON1_SET_SHIFT                 0
#define PMIC_TOP_RST_BANK_CON1_CLR_MASK                  0xFFFF
#define PMIC_TOP_RST_BANK_CON1_CLR_SHIFT                 0
#define PMIC_RG_INT_EN_PWRKEY_MASK                       0x1
#define PMIC_RG_INT_EN_PWRKEY_SHIFT                      0
#define PMIC_RG_INT_EN_HOMEKEY_MASK                      0x1
#define PMIC_RG_INT_EN_HOMEKEY_SHIFT                     1
#define PMIC_RG_INT_EN_PWRKEY_R_MASK                     0x1
#define PMIC_RG_INT_EN_PWRKEY_R_SHIFT                    2
#define PMIC_RG_INT_EN_HOMEKEY_R_MASK                    0x1
#define PMIC_RG_INT_EN_HOMEKEY_R_SHIFT                   3
#define PMIC_RG_INT_EN_NI_LBAT_INT_MASK                  0x1
#define PMIC_RG_INT_EN_NI_LBAT_INT_SHIFT                 4
#define PMIC_RG_INT_EN_CHRDET_MASK                       0x1
#define PMIC_RG_INT_EN_CHRDET_SHIFT                      5
#define PMIC_RG_INT_EN_CHRDET_EDGE_MASK                  0x1
#define PMIC_RG_INT_EN_CHRDET_EDGE_SHIFT                 6
#define PMIC_RG_INT_EN_BATON_LV_MASK                     0x1
#define PMIC_RG_INT_EN_BATON_LV_SHIFT                    7
#define PMIC_RG_INT_EN_BATON_HV_MASK                     0x1
#define PMIC_RG_INT_EN_BATON_HV_SHIFT                    8
#define PMIC_RG_INT_EN_BATON_BAT_IN_MASK                 0x1
#define PMIC_RG_INT_EN_BATON_BAT_IN_SHIFT                9
#define PMIC_RG_INT_EN_BATON_BAT_OUT_MASK                0x1
#define PMIC_RG_INT_EN_BATON_BAT_OUT_SHIFT               10
#define PMIC_RG_INT_EN_RTC_MASK                          0x1
#define PMIC_RG_INT_EN_RTC_SHIFT                         11
#define PMIC_RG_INT_EN_RTC_NSEC_MASK                     0x1
#define PMIC_RG_INT_EN_RTC_NSEC_SHIFT                    12
#define PMIC_RG_INT_EN_BIF_MASK                          0x1
#define PMIC_RG_INT_EN_BIF_SHIFT                         13
#define PMIC_RG_INT_EN_VCDT_HV_DET_MASK                  0x1
#define PMIC_RG_INT_EN_VCDT_HV_DET_SHIFT                 14
#define PMIC_INT_CON0_SET_MASK                           0xFFFF
#define PMIC_INT_CON0_SET_SHIFT                          0
#define PMIC_INT_CON0_CLR_MASK                           0xFFFF
#define PMIC_INT_CON0_CLR_SHIFT                          0
#define PMIC_RG_INT_EN_THR_H_MASK                        0x1
#define PMIC_RG_INT_EN_THR_H_SHIFT                       0
#define PMIC_RG_INT_EN_THR_L_MASK                        0x1
#define PMIC_RG_INT_EN_THR_L_SHIFT                       1
#define PMIC_RG_INT_EN_BAT_H_MASK                        0x1
#define PMIC_RG_INT_EN_BAT_H_SHIFT                       2
#define PMIC_RG_INT_EN_BAT_L_MASK                        0x1
#define PMIC_RG_INT_EN_BAT_L_SHIFT                       3
#define PMIC_RG_INT_EN_BAT2_H_MASK                       0x1
#define PMIC_RG_INT_EN_BAT2_H_SHIFT                      4
#define PMIC_RG_INT_EN_BAT2_L_MASK                       0x1
#define PMIC_RG_INT_EN_BAT2_L_SHIFT                      5
#define PMIC_RG_INT_EN_BAT_TEMP_H_MASK                   0x1
#define PMIC_RG_INT_EN_BAT_TEMP_H_SHIFT                  6
#define PMIC_RG_INT_EN_BAT_TEMP_L_MASK                   0x1
#define PMIC_RG_INT_EN_BAT_TEMP_L_SHIFT                  7
#define PMIC_RG_INT_EN_AUXADC_IMP_MASK                   0x1
#define PMIC_RG_INT_EN_AUXADC_IMP_SHIFT                  8
#define PMIC_RG_INT_EN_NAG_C_DLTV_MASK                   0x1
#define PMIC_RG_INT_EN_NAG_C_DLTV_SHIFT                  9
#define PMIC_RG_INT_EN_JEITA_HOT_MASK                    0x1
#define PMIC_RG_INT_EN_JEITA_HOT_SHIFT                   10
#define PMIC_RG_INT_EN_JEITA_WARM_MASK                   0x1
#define PMIC_RG_INT_EN_JEITA_WARM_SHIFT                  11
#define PMIC_RG_INT_EN_JEITA_COOL_MASK                   0x1
#define PMIC_RG_INT_EN_JEITA_COOL_SHIFT                  12
#define PMIC_RG_INT_EN_JEITA_COLD_MASK                   0x1
#define PMIC_RG_INT_EN_JEITA_COLD_SHIFT                  13
#define PMIC_INT_CON1_SET_MASK                           0xFFFF
#define PMIC_INT_CON1_SET_SHIFT                          0
#define PMIC_INT_CON1_CLR_MASK                           0xFFFF
#define PMIC_INT_CON1_CLR_SHIFT                          0
#define PMIC_RG_INT_EN_VPROC11_OC_MASK                   0x1
#define PMIC_RG_INT_EN_VPROC11_OC_SHIFT                  0
#define PMIC_RG_INT_EN_VPROC12_OC_MASK                   0x1
#define PMIC_RG_INT_EN_VPROC12_OC_SHIFT                  1
#define PMIC_RG_INT_EN_VCORE_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VCORE_OC_SHIFT                    2
#define PMIC_RG_INT_EN_VGPU_OC_MASK                      0x1
#define PMIC_RG_INT_EN_VGPU_OC_SHIFT                     3
#define PMIC_RG_INT_EN_VDRAM1_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VDRAM1_OC_SHIFT                   4
#define PMIC_RG_INT_EN_VDRAM2_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VDRAM2_OC_SHIFT                   5
#define PMIC_RG_INT_EN_VMODEM_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VMODEM_OC_SHIFT                   6
#define PMIC_RG_INT_EN_VS1_OC_MASK                       0x1
#define PMIC_RG_INT_EN_VS1_OC_SHIFT                      7
#define PMIC_RG_INT_EN_VS2_OC_MASK                       0x1
#define PMIC_RG_INT_EN_VS2_OC_SHIFT                      8
#define PMIC_RG_INT_EN_VPA_OC_MASK                       0x1
#define PMIC_RG_INT_EN_VPA_OC_SHIFT                      9
#define PMIC_RG_INT_EN_VCORE_PREOC_MASK                  0x1
#define PMIC_RG_INT_EN_VCORE_PREOC_SHIFT                 10
#define PMIC_RG_INT_EN_VA10_OC_MASK                      0x1
#define PMIC_RG_INT_EN_VA10_OC_SHIFT                     11
#define PMIC_RG_INT_EN_VA12_OC_MASK                      0x1
#define PMIC_RG_INT_EN_VA12_OC_SHIFT                     12
#define PMIC_RG_INT_EN_VA18_OC_MASK                      0x1
#define PMIC_RG_INT_EN_VA18_OC_SHIFT                     13
#define PMIC_RG_INT_EN_VBIF28_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VBIF28_OC_SHIFT                   14
#define PMIC_RG_INT_EN_VCAMA1_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VCAMA1_OC_SHIFT                   15
#define PMIC_INT_CON2_SET_MASK                           0xFFFF
#define PMIC_INT_CON2_SET_SHIFT                          0
#define PMIC_INT_CON2_CLR_MASK                           0xFFFF
#define PMIC_INT_CON2_CLR_SHIFT                          0
#define PMIC_RG_INT_EN_VCAMA2_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VCAMA2_OC_SHIFT                   0
#define PMIC_RG_INT_EN_VXO18_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VXO18_OC_SHIFT                    1
#define PMIC_RG_INT_EN_VCAMD1_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VCAMD1_OC_SHIFT                   2
#define PMIC_RG_INT_EN_VCAMD2_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VCAMD2_OC_SHIFT                   3
#define PMIC_RG_INT_EN_VCAMIO_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VCAMIO_OC_SHIFT                   4
#define PMIC_RG_INT_EN_VCN18_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VCN18_OC_SHIFT                    5
#define PMIC_RG_INT_EN_VCN28_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VCN28_OC_SHIFT                    6
#define PMIC_RG_INT_EN_VCN33_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VCN33_OC_SHIFT                    7
#define PMIC_RG_INT_EN_VTCXO24_OC_MASK                   0x1
#define PMIC_RG_INT_EN_VTCXO24_OC_SHIFT                  8
#define PMIC_RG_INT_EN_VEMC_OC_MASK                      0x1
#define PMIC_RG_INT_EN_VEMC_OC_SHIFT                     9
#define PMIC_RG_INT_EN_VFE28_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VFE28_OC_SHIFT                    10
#define PMIC_RG_INT_EN_VGP_OC_MASK                       0x1
#define PMIC_RG_INT_EN_VGP_OC_SHIFT                      11
#define PMIC_RG_INT_EN_VLDO28_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VLDO28_OC_SHIFT                   12
#define PMIC_RG_INT_EN_VIO18_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VIO18_OC_SHIFT                    13
#define PMIC_RG_INT_EN_VIO28_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VIO28_OC_SHIFT                    14
#define PMIC_RG_INT_EN_VMC_OC_MASK                       0x1
#define PMIC_RG_INT_EN_VMC_OC_SHIFT                      15
#define PMIC_INT_CON3_SET_MASK                           0xFFFF
#define PMIC_INT_CON3_SET_SHIFT                          0
#define PMIC_INT_CON3_CLR_MASK                           0xFFFF
#define PMIC_INT_CON3_CLR_SHIFT                          0
#define PMIC_RG_INT_EN_VMCH_OC_MASK                      0x1
#define PMIC_RG_INT_EN_VMCH_OC_SHIFT                     0
#define PMIC_RG_INT_EN_VMIPI_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VMIPI_OC_SHIFT                    1
#define PMIC_RG_INT_EN_VRF12_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VRF12_OC_SHIFT                    2
#define PMIC_RG_INT_EN_VRF18_1_OC_MASK                   0x1
#define PMIC_RG_INT_EN_VRF18_1_OC_SHIFT                  3
#define PMIC_RG_INT_EN_VRF18_2_OC_MASK                   0x1
#define PMIC_RG_INT_EN_VRF18_2_OC_SHIFT                  4
#define PMIC_RG_INT_EN_VSIM1_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VSIM1_OC_SHIFT                    5
#define PMIC_RG_INT_EN_VSIM2_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VSIM2_OC_SHIFT                    6
#define PMIC_RG_INT_EN_VGP2_OC_MASK                      0x1
#define PMIC_RG_INT_EN_VGP2_OC_SHIFT                     7
#define PMIC_RG_INT_EN_VSRAM_CORE_OC_MASK                0x1
#define PMIC_RG_INT_EN_VSRAM_CORE_OC_SHIFT               8
#define PMIC_RG_INT_EN_VSRAM_PROC_OC_MASK                0x1
#define PMIC_RG_INT_EN_VSRAM_PROC_OC_SHIFT               9
#define PMIC_RG_INT_EN_VSRAM_GPU_OC_MASK                 0x1
#define PMIC_RG_INT_EN_VSRAM_GPU_OC_SHIFT                10
#define PMIC_RG_INT_EN_VSRAM_MD_OC_MASK                  0x1
#define PMIC_RG_INT_EN_VSRAM_MD_OC_SHIFT                 11
#define PMIC_RG_INT_EN_VUFS18_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VUFS18_OC_SHIFT                   12
#define PMIC_RG_INT_EN_VUSB33_OC_MASK                    0x1
#define PMIC_RG_INT_EN_VUSB33_OC_SHIFT                   13
#define PMIC_RG_INT_EN_VXO22_OC_MASK                     0x1
#define PMIC_RG_INT_EN_VXO22_OC_SHIFT                    14
#define PMIC_INT_CON4_SET_MASK                           0xFFFF
#define PMIC_INT_CON4_SET_SHIFT                          0
#define PMIC_INT_CON4_CLR_MASK                           0xFFFF
#define PMIC_INT_CON4_CLR_SHIFT                          0
#define PMIC_RG_INT_EN_FG_BAT0_H_MASK                    0x1
#define PMIC_RG_INT_EN_FG_BAT0_H_SHIFT                   0
#define PMIC_RG_INT_EN_FG_BAT0_L_MASK                    0x1
#define PMIC_RG_INT_EN_FG_BAT0_L_SHIFT                   1
#define PMIC_RG_INT_EN_FG_CUR_H_MASK                     0x1
#define PMIC_RG_INT_EN_FG_CUR_H_SHIFT                    2
#define PMIC_RG_INT_EN_FG_CUR_L_MASK                     0x1
#define PMIC_RG_INT_EN_FG_CUR_L_SHIFT                    3
#define PMIC_RG_INT_EN_FG_ZCV_MASK                       0x1
#define PMIC_RG_INT_EN_FG_ZCV_SHIFT                      4
#define PMIC_RG_INT_EN_FG_BAT1_H_MASK                    0x1
#define PMIC_RG_INT_EN_FG_BAT1_H_SHIFT                   5
#define PMIC_RG_INT_EN_FG_BAT1_L_MASK                    0x1
#define PMIC_RG_INT_EN_FG_BAT1_L_SHIFT                   6
#define PMIC_RG_INT_EN_FG_N_CHARGE_L_MASK                0x1
#define PMIC_RG_INT_EN_FG_N_CHARGE_L_SHIFT               7
#define PMIC_RG_INT_EN_FG_IAVG_H_MASK                    0x1
#define PMIC_RG_INT_EN_FG_IAVG_H_SHIFT                   8
#define PMIC_RG_INT_EN_FG_IAVG_L_MASK                    0x1
#define PMIC_RG_INT_EN_FG_IAVG_L_SHIFT                   9
#define PMIC_RG_INT_EN_FG_TIME_H_MASK                    0x1
#define PMIC_RG_INT_EN_FG_TIME_H_SHIFT                   10
#define PMIC_RG_INT_EN_FG_DISCHARGE_MASK                 0x1
#define PMIC_RG_INT_EN_FG_DISCHARGE_SHIFT                11
#define PMIC_RG_INT_EN_FG_CHARGE_MASK                    0x1
#define PMIC_RG_INT_EN_FG_CHARGE_SHIFT                   12
#define PMIC_RG_INT_EN_CON5_MASK                         0x7
#define PMIC_RG_INT_EN_CON5_SHIFT                        13
#define PMIC_INT_CON5_SET_MASK                           0xFFFF
#define PMIC_INT_CON5_SET_SHIFT                          0
#define PMIC_INT_CON5_CLR_MASK                           0xFFFF
#define PMIC_INT_CON5_CLR_SHIFT                          0
#define PMIC_RG_INT_EN_AUDIO_MASK                        0x1
#define PMIC_RG_INT_EN_AUDIO_SHIFT                       0
#define PMIC_RG_INT_EN_MAD_MASK                          0x1
#define PMIC_RG_INT_EN_MAD_SHIFT                         1
#define PMIC_RG_INT_EN_EINT_RTC32K_1V8_1_MASK            0x1
#define PMIC_RG_INT_EN_EINT_RTC32K_1V8_1_SHIFT           2
#define PMIC_RG_INT_EN_EINT_AUD_CLK_MASK                 0x1
#define PMIC_RG_INT_EN_EINT_AUD_CLK_SHIFT                3
#define PMIC_RG_INT_EN_EINT_AUD_DAT_MOSI_MASK            0x1
#define PMIC_RG_INT_EN_EINT_AUD_DAT_MOSI_SHIFT           4
#define PMIC_RG_INT_EN_EINT_AUD_DAT_MISO_MASK            0x1
#define PMIC_RG_INT_EN_EINT_AUD_DAT_MISO_SHIFT           5
#define PMIC_RG_INT_EN_EINT_VOW_CLK_MISO_MASK            0x1
#define PMIC_RG_INT_EN_EINT_VOW_CLK_MISO_SHIFT           6
#define PMIC_RG_INT_EN_ACCDET_MASK                       0x1
#define PMIC_RG_INT_EN_ACCDET_SHIFT                      7
#define PMIC_RG_INT_EN_ACCDET_EINT_MASK                  0x1
#define PMIC_RG_INT_EN_ACCDET_EINT_SHIFT                 8
#define PMIC_RG_INT_EN_SPI_CMD_ALERT_MASK                0x1
#define PMIC_RG_INT_EN_SPI_CMD_ALERT_SHIFT               9
#define PMIC_INT_CON6_SET_MASK                           0xFFFF
#define PMIC_INT_CON6_SET_SHIFT                          0
#define PMIC_INT_CON6_CLR_MASK                           0xFFFF
#define PMIC_INT_CON6_CLR_SHIFT                          0
#define PMIC_RG_INT_MASK_PWRKEY_MASK                     0x1
#define PMIC_RG_INT_MASK_PWRKEY_SHIFT                    0
#define PMIC_RG_INT_MASK_HOMEKEY_MASK                    0x1
#define PMIC_RG_INT_MASK_HOMEKEY_SHIFT                   1
#define PMIC_RG_INT_MASK_PWRKEY_R_MASK                   0x1
#define PMIC_RG_INT_MASK_PWRKEY_R_SHIFT                  2
#define PMIC_RG_INT_MASK_HOMEKEY_R_MASK                  0x1
#define PMIC_RG_INT_MASK_HOMEKEY_R_SHIFT                 3
#define PMIC_RG_INT_MASK_NI_LBAT_INT_MASK                0x1
#define PMIC_RG_INT_MASK_NI_LBAT_INT_SHIFT               4
#define PMIC_RG_INT_MASK_CHRDET_MASK                     0x1
#define PMIC_RG_INT_MASK_CHRDET_SHIFT                    5
#define PMIC_RG_INT_MASK_CHRDET_EDGE_MASK                0x1
#define PMIC_RG_INT_MASK_CHRDET_EDGE_SHIFT               6
#define PMIC_RG_INT_MASK_BATON_LV_MASK                   0x1
#define PMIC_RG_INT_MASK_BATON_LV_SHIFT                  7
#define PMIC_RG_INT_MASK_BATON_HV_MASK                   0x1
#define PMIC_RG_INT_MASK_BATON_HV_SHIFT                  8
#define PMIC_RG_INT_MASK_BATON_BAT_IN_MASK               0x1
#define PMIC_RG_INT_MASK_BATON_BAT_IN_SHIFT              9
#define PMIC_RG_INT_MASK_BATON_BAT_OUT_MASK              0x1
#define PMIC_RG_INT_MASK_BATON_BAT_OUT_SHIFT             10
#define PMIC_RG_INT_MASK_RTC_MASK                        0x1
#define PMIC_RG_INT_MASK_RTC_SHIFT                       11
#define PMIC_RG_INT_MASK_RTC_NSEC_MASK                   0x1
#define PMIC_RG_INT_MASK_RTC_NSEC_SHIFT                  12
#define PMIC_RG_INT_MASK_BIF_MASK                        0x1
#define PMIC_RG_INT_MASK_BIF_SHIFT                       13
#define PMIC_RG_INT_MASK_VCDT_HV_DET_MASK                0x1
#define PMIC_RG_INT_MASK_VCDT_HV_DET_SHIFT               14
#define PMIC_INT_MASK_CON0_SET_MASK                      0xFFFF
#define PMIC_INT_MASK_CON0_SET_SHIFT                     0
#define PMIC_INT_MASK_CON0_CLR_MASK                      0xFFFF
#define PMIC_INT_MASK_CON0_CLR_SHIFT                     0
#define PMIC_RG_INT_MASK_THR_H_MASK                      0x1
#define PMIC_RG_INT_MASK_THR_H_SHIFT                     0
#define PMIC_RG_INT_MASK_THR_L_MASK                      0x1
#define PMIC_RG_INT_MASK_THR_L_SHIFT                     1
#define PMIC_RG_INT_MASK_BAT_H_MASK                      0x1
#define PMIC_RG_INT_MASK_BAT_H_SHIFT                     2
#define PMIC_RG_INT_MASK_BAT_L_MASK                      0x1
#define PMIC_RG_INT_MASK_BAT_L_SHIFT                     3
#define PMIC_RG_INT_MASK_BAT2_H_MASK                     0x1
#define PMIC_RG_INT_MASK_BAT2_H_SHIFT                    4
#define PMIC_RG_INT_MASK_BAT2_L_MASK                     0x1
#define PMIC_RG_INT_MASK_BAT2_L_SHIFT                    5
#define PMIC_RG_INT_MASK_BAT_TEMP_H_MASK                 0x1
#define PMIC_RG_INT_MASK_BAT_TEMP_H_SHIFT                6
#define PMIC_RG_INT_MASK_BAT_TEMP_L_MASK                 0x1
#define PMIC_RG_INT_MASK_BAT_TEMP_L_SHIFT                7
#define PMIC_RG_INT_MASK_AUXADC_IMP_MASK                 0x1
#define PMIC_RG_INT_MASK_AUXADC_IMP_SHIFT                8
#define PMIC_RG_INT_MASK_NAG_C_DLTV_MASK                 0x1
#define PMIC_RG_INT_MASK_NAG_C_DLTV_SHIFT                9
#define PMIC_RG_INT_MASK_JEITA_HOT_MASK                  0x1
#define PMIC_RG_INT_MASK_JEITA_HOT_SHIFT                 10
#define PMIC_RG_INT_MASK_JEITA_WARM_MASK                 0x1
#define PMIC_RG_INT_MASK_JEITA_WARM_SHIFT                11
#define PMIC_RG_INT_MASK_JEITA_COOL_MASK                 0x1
#define PMIC_RG_INT_MASK_JEITA_COOL_SHIFT                12
#define PMIC_RG_INT_MASK_JEITA_COLD_MASK                 0x1
#define PMIC_RG_INT_MASK_JEITA_COLD_SHIFT                13
#define PMIC_INT_MASK_CON1_SET_MASK                      0xFFFF
#define PMIC_INT_MASK_CON1_SET_SHIFT                     0
#define PMIC_INT_MASK_CON1_CLR_MASK                      0xFFFF
#define PMIC_INT_MASK_CON1_CLR_SHIFT                     0
#define PMIC_RG_INT_MASK_VPROC11_OC_MASK                 0x1
#define PMIC_RG_INT_MASK_VPROC11_OC_SHIFT                0
#define PMIC_RG_INT_MASK_VPROC12_OC_MASK                 0x1
#define PMIC_RG_INT_MASK_VPROC12_OC_SHIFT                1
#define PMIC_RG_INT_MASK_VCORE_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VCORE_OC_SHIFT                  2
#define PMIC_RG_INT_MASK_VGPU_OC_MASK                    0x1
#define PMIC_RG_INT_MASK_VGPU_OC_SHIFT                   3
#define PMIC_RG_INT_MASK_VDRAM1_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VDRAM1_OC_SHIFT                 4
#define PMIC_RG_INT_MASK_VDRAM2_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VDRAM2_OC_SHIFT                 5
#define PMIC_RG_INT_MASK_VMODEM_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VMODEM_OC_SHIFT                 6
#define PMIC_RG_INT_MASK_VS1_OC_MASK                     0x1
#define PMIC_RG_INT_MASK_VS1_OC_SHIFT                    7
#define PMIC_RG_INT_MASK_VS2_OC_MASK                     0x1
#define PMIC_RG_INT_MASK_VS2_OC_SHIFT                    8
#define PMIC_RG_INT_MASK_VPA_OC_MASK                     0x1
#define PMIC_RG_INT_MASK_VPA_OC_SHIFT                    9
#define PMIC_RG_INT_MASK_VCORE_PREOC_MASK                0x1
#define PMIC_RG_INT_MASK_VCORE_PREOC_SHIFT               10
#define PMIC_RG_INT_MASK_VA10_OC_MASK                    0x1
#define PMIC_RG_INT_MASK_VA10_OC_SHIFT                   11
#define PMIC_RG_INT_MASK_VA12_OC_MASK                    0x1
#define PMIC_RG_INT_MASK_VA12_OC_SHIFT                   12
#define PMIC_RG_INT_MASK_VA18_OC_MASK                    0x1
#define PMIC_RG_INT_MASK_VA18_OC_SHIFT                   13
#define PMIC_RG_INT_MASK_VBIF28_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VBIF28_OC_SHIFT                 14
#define PMIC_RG_INT_MASK_VCAMA1_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VCAMA1_OC_SHIFT                 15
#define PMIC_INT_MASK_CON2_SET_MASK                      0xFFFF
#define PMIC_INT_MASK_CON2_SET_SHIFT                     0
#define PMIC_INT_MASK_CON2_CLR_MASK                      0xFFFF
#define PMIC_INT_MASK_CON2_CLR_SHIFT                     0
#define PMIC_RG_INT_MASK_VCAMA2_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VCAMA2_OC_SHIFT                 0
#define PMIC_RG_INT_MASK_VXO18_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VXO18_OC_SHIFT                  1
#define PMIC_RG_INT_MASK_VCAMD1_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VCAMD1_OC_SHIFT                 2
#define PMIC_RG_INT_MASK_VCAMD2_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VCAMD2_OC_SHIFT                 3
#define PMIC_RG_INT_MASK_VCAMIO_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VCAMIO_OC_SHIFT                 4
#define PMIC_RG_INT_MASK_VCN18_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VCN18_OC_SHIFT                  5
#define PMIC_RG_INT_MASK_VCN28_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VCN28_OC_SHIFT                  6
#define PMIC_RG_INT_MASK_VCN33_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VCN33_OC_SHIFT                  7
#define PMIC_RG_INT_MASK_VTCXO24_OC_MASK                 0x1
#define PMIC_RG_INT_MASK_VTCXO24_OC_SHIFT                8
#define PMIC_RG_INT_MASK_VEMC_OC_MASK                    0x1
#define PMIC_RG_INT_MASK_VEMC_OC_SHIFT                   9
#define PMIC_RG_INT_MASK_VFE28_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VFE28_OC_SHIFT                  10
#define PMIC_RG_INT_MASK_VGP_OC_MASK                     0x1
#define PMIC_RG_INT_MASK_VGP_OC_SHIFT                    11
#define PMIC_RG_INT_MASK_VLDO28_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VLDO28_OC_SHIFT                 12
#define PMIC_RG_INT_MASK_VIO18_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VIO18_OC_SHIFT                  13
#define PMIC_RG_INT_MASK_VIO28_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VIO28_OC_SHIFT                  14
#define PMIC_RG_INT_MASK_VMC_OC_MASK                     0x1
#define PMIC_RG_INT_MASK_VMC_OC_SHIFT                    15
#define PMIC_INT_MASK_CON3_SET_MASK                      0xFFFF
#define PMIC_INT_MASK_CON3_SET_SHIFT                     0
#define PMIC_INT_MASK_CON3_CLR_MASK                      0xFFFF
#define PMIC_INT_MASK_CON3_CLR_SHIFT                     0
#define PMIC_RG_INT_MASK_VMCH_OC_MASK                    0x1
#define PMIC_RG_INT_MASK_VMCH_OC_SHIFT                   0
#define PMIC_RG_INT_MASK_VMIPI_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VMIPI_OC_SHIFT                  1
#define PMIC_RG_INT_MASK_VRF12_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VRF12_OC_SHIFT                  2
#define PMIC_RG_INT_MASK_VRF18_1_OC_MASK                 0x1
#define PMIC_RG_INT_MASK_VRF18_1_OC_SHIFT                3
#define PMIC_RG_INT_MASK_VRF18_2_OC_MASK                 0x1
#define PMIC_RG_INT_MASK_VRF18_2_OC_SHIFT                4
#define PMIC_RG_INT_MASK_VSIM1_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VSIM1_OC_SHIFT                  5
#define PMIC_RG_INT_MASK_VSIM2_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VSIM2_OC_SHIFT                  6
#define PMIC_RG_INT_MASK_VGP2_OC_MASK                    0x1
#define PMIC_RG_INT_MASK_VGP2_OC_SHIFT                   7
#define PMIC_RG_INT_MASK_VSRAM_CORE_OC_MASK              0x1
#define PMIC_RG_INT_MASK_VSRAM_CORE_OC_SHIFT             8
#define PMIC_RG_INT_MASK_VSRAM_PROC_OC_MASK              0x1
#define PMIC_RG_INT_MASK_VSRAM_PROC_OC_SHIFT             9
#define PMIC_RG_INT_MASK_VSRAM_GPU_OC_MASK               0x1
#define PMIC_RG_INT_MASK_VSRAM_GPU_OC_SHIFT              10
#define PMIC_RG_INT_MASK_VSRAM_MD_OC_MASK                0x1
#define PMIC_RG_INT_MASK_VSRAM_MD_OC_SHIFT               11
#define PMIC_RG_INT_MASK_VUFS18_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VUFS18_OC_SHIFT                 12
#define PMIC_RG_INT_MASK_VUSB33_OC_MASK                  0x1
#define PMIC_RG_INT_MASK_VUSB33_OC_SHIFT                 13
#define PMIC_RG_INT_MASK_VXO22_OC_MASK                   0x1
#define PMIC_RG_INT_MASK_VXO22_OC_SHIFT                  14
#define PMIC_INT_MASK_CON4_SET_MASK                      0xFFFF
#define PMIC_INT_MASK_CON4_SET_SHIFT                     0
#define PMIC_INT_MASK_CON4_CLR_MASK                      0xFFFF
#define PMIC_INT_MASK_CON4_CLR_SHIFT                     0
#define PMIC_RG_INT_MASK_FG_BAT0_H_MASK                  0x1
#define PMIC_RG_INT_MASK_FG_BAT0_H_SHIFT                 0
#define PMIC_RG_INT_MASK_FG_BAT0_L_MASK                  0x1
#define PMIC_RG_INT_MASK_FG_BAT0_L_SHIFT                 1
#define PMIC_RG_INT_MASK_FG_CUR_H_MASK                   0x1
#define PMIC_RG_INT_MASK_FG_CUR_H_SHIFT                  2
#define PMIC_RG_INT_MASK_FG_CUR_L_MASK                   0x1
#define PMIC_RG_INT_MASK_FG_CUR_L_SHIFT                  3
#define PMIC_RG_INT_MASK_FG_ZCV_MASK                     0x1
#define PMIC_RG_INT_MASK_FG_ZCV_SHIFT                    4
#define PMIC_RG_INT_MASK_FG_BAT1_H_MASK                  0x1
#define PMIC_RG_INT_MASK_FG_BAT1_H_SHIFT                 5
#define PMIC_RG_INT_MASK_FG_BAT1_L_MASK                  0x1
#define PMIC_RG_INT_MASK_FG_BAT1_L_SHIFT                 6
#define PMIC_RG_INT_MASK_FG_N_CHARGE_L_MASK              0x1
#define PMIC_RG_INT_MASK_FG_N_CHARGE_L_SHIFT             7
#define PMIC_RG_INT_MASK_FG_IAVG_H_MASK                  0x1
#define PMIC_RG_INT_MASK_FG_IAVG_H_SHIFT                 8
#define PMIC_RG_INT_MASK_FG_IAVG_L_MASK                  0x1
#define PMIC_RG_INT_MASK_FG_IAVG_L_SHIFT                 9
#define PMIC_RG_INT_MASK_FG_TIME_H_MASK                  0x1
#define PMIC_RG_INT_MASK_FG_TIME_H_SHIFT                 10
#define PMIC_RG_INT_MASK_FG_DISCHARGE_MASK               0x1
#define PMIC_RG_INT_MASK_FG_DISCHARGE_SHIFT              11
#define PMIC_RG_INT_MASK_FG_CHARGE_MASK                  0x1
#define PMIC_RG_INT_MASK_FG_CHARGE_SHIFT                 12
#define PMIC_RG_INT_MASK_CON5_MASK                       0x7
#define PMIC_RG_INT_MASK_CON5_SHIFT                      13
#define PMIC_INT_MASK_CON5_SET_MASK                      0xFFFF
#define PMIC_INT_MASK_CON5_SET_SHIFT                     0
#define PMIC_INT_MASK_CON5_CLR_MASK                      0xFFFF
#define PMIC_INT_MASK_CON5_CLR_SHIFT                     0
#define PMIC_RG_INT_MASK_AUDIO_MASK                      0x1
#define PMIC_RG_INT_MASK_AUDIO_SHIFT                     0
#define PMIC_RG_INT_MASK_MAD_MASK                        0x1
#define PMIC_RG_INT_MASK_MAD_SHIFT                       1
#define PMIC_RG_INT_MASK_EINT_RTC32K_1V8_1_MASK          0x1
#define PMIC_RG_INT_MASK_EINT_RTC32K_1V8_1_SHIFT         2
#define PMIC_RG_INT_MASK_EINT_AUD_CLK_MASK               0x1
#define PMIC_RG_INT_MASK_EINT_AUD_CLK_SHIFT              3
#define PMIC_RG_INT_MASK_EINT_AUD_DAT_MOSI_MASK          0x1
#define PMIC_RG_INT_MASK_EINT_AUD_DAT_MOSI_SHIFT         4
#define PMIC_RG_INT_MASK_EINT_AUD_DAT_MISO_MASK          0x1
#define PMIC_RG_INT_MASK_EINT_AUD_DAT_MISO_SHIFT         5
#define PMIC_RG_INT_MASK_EINT_VOW_CLK_MISO_MASK          0x1
#define PMIC_RG_INT_MASK_EINT_VOW_CLK_MISO_SHIFT         6
#define PMIC_RG_INT_MASK_ACCDET_MASK                     0x1
#define PMIC_RG_INT_MASK_ACCDET_SHIFT                    7
#define PMIC_RG_INT_MASK_ACCDET_EINT_MASK                0x1
#define PMIC_RG_INT_MASK_ACCDET_EINT_SHIFT               8
#define PMIC_RG_INT_MASK_SPI_CMD_ALERT_MASK              0x1
#define PMIC_RG_INT_MASK_SPI_CMD_ALERT_SHIFT             9
#define PMIC_INT_MASK_CON6_SET_MASK                      0xFFFF
#define PMIC_INT_MASK_CON6_SET_SHIFT                     0
#define PMIC_INT_MASK_CON6_CLR_MASK                      0xFFFF
#define PMIC_INT_MASK_CON6_CLR_SHIFT                     0
#define PMIC_RG_INT_STATUS_PWRKEY_MASK                   0x1
#define PMIC_RG_INT_STATUS_PWRKEY_SHIFT                  0
#define PMIC_RG_INT_STATUS_HOMEKEY_MASK                  0x1
#define PMIC_RG_INT_STATUS_HOMEKEY_SHIFT                 1
#define PMIC_RG_INT_STATUS_PWRKEY_R_MASK                 0x1
#define PMIC_RG_INT_STATUS_PWRKEY_R_SHIFT                2
#define PMIC_RG_INT_STATUS_HOMEKEY_R_MASK                0x1
#define PMIC_RG_INT_STATUS_HOMEKEY_R_SHIFT               3
#define PMIC_RG_INT_STATUS_NI_LBAT_INT_MASK              0x1
#define PMIC_RG_INT_STATUS_NI_LBAT_INT_SHIFT             4
#define PMIC_RG_INT_STATUS_CHRDET_MASK                   0x1
#define PMIC_RG_INT_STATUS_CHRDET_SHIFT                  5
#define PMIC_RG_INT_STATUS_CHRDET_EDGE_MASK              0x1
#define PMIC_RG_INT_STATUS_CHRDET_EDGE_SHIFT             6
#define PMIC_RG_INT_STATUS_BATON_LV_MASK                 0x1
#define PMIC_RG_INT_STATUS_BATON_LV_SHIFT                7
#define PMIC_RG_INT_STATUS_BATON_HV_MASK                 0x1
#define PMIC_RG_INT_STATUS_BATON_HV_SHIFT                8
#define PMIC_RG_INT_STATUS_BATON_BAT_IN_MASK             0x1
#define PMIC_RG_INT_STATUS_BATON_BAT_IN_SHIFT            9
#define PMIC_RG_INT_STATUS_BATON_BAT_OUT_MASK            0x1
#define PMIC_RG_INT_STATUS_BATON_BAT_OUT_SHIFT           10
#define PMIC_RG_INT_STATUS_RTC_MASK                      0x1
#define PMIC_RG_INT_STATUS_RTC_SHIFT                     11
#define PMIC_RG_INT_STATUS_RTC_NSEC_MASK                 0x1
#define PMIC_RG_INT_STATUS_RTC_NSEC_SHIFT                12
#define PMIC_RG_INT_STATUS_BIF_MASK                      0x1
#define PMIC_RG_INT_STATUS_BIF_SHIFT                     13
#define PMIC_RG_INT_STATUS_VCDT_HV_DET_MASK              0x1
#define PMIC_RG_INT_STATUS_VCDT_HV_DET_SHIFT             14
#define PMIC_RG_INT_STATUS_THR_H_MASK                    0x1
#define PMIC_RG_INT_STATUS_THR_H_SHIFT                   0
#define PMIC_RG_INT_STATUS_THR_L_MASK                    0x1
#define PMIC_RG_INT_STATUS_THR_L_SHIFT                   1
#define PMIC_RG_INT_STATUS_BAT_H_MASK                    0x1
#define PMIC_RG_INT_STATUS_BAT_H_SHIFT                   2
#define PMIC_RG_INT_STATUS_BAT_L_MASK                    0x1
#define PMIC_RG_INT_STATUS_BAT_L_SHIFT                   3
#define PMIC_RG_INT_STATUS_BAT2_H_MASK                   0x1
#define PMIC_RG_INT_STATUS_BAT2_H_SHIFT                  4
#define PMIC_RG_INT_STATUS_BAT2_L_MASK                   0x1
#define PMIC_RG_INT_STATUS_BAT2_L_SHIFT                  5
#define PMIC_RG_INT_STATUS_BAT_TEMP_H_MASK               0x1
#define PMIC_RG_INT_STATUS_BAT_TEMP_H_SHIFT              6
#define PMIC_RG_INT_STATUS_BAT_TEMP_L_MASK               0x1
#define PMIC_RG_INT_STATUS_BAT_TEMP_L_SHIFT              7
#define PMIC_RG_INT_STATUS_AUXADC_IMP_MASK               0x1
#define PMIC_RG_INT_STATUS_AUXADC_IMP_SHIFT              8
#define PMIC_RG_INT_STATUS_NAG_C_DLTV_MASK               0x1
#define PMIC_RG_INT_STATUS_NAG_C_DLTV_SHIFT              9
#define PMIC_RG_INT_STATUS_JEITA_HOT_MASK                0x1
#define PMIC_RG_INT_STATUS_JEITA_HOT_SHIFT               10
#define PMIC_RG_INT_STATUS_JEITA_WARM_MASK               0x1
#define PMIC_RG_INT_STATUS_JEITA_WARM_SHIFT              11
#define PMIC_RG_INT_STATUS_JEITA_COOL_MASK               0x1
#define PMIC_RG_INT_STATUS_JEITA_COOL_SHIFT              12
#define PMIC_RG_INT_STATUS_JEITA_COLD_MASK               0x1
#define PMIC_RG_INT_STATUS_JEITA_COLD_SHIFT              13
#define PMIC_RG_INT_STATUS_VPROC11_OC_MASK               0x1
#define PMIC_RG_INT_STATUS_VPROC11_OC_SHIFT              0
#define PMIC_RG_INT_STATUS_VPROC12_OC_MASK               0x1
#define PMIC_RG_INT_STATUS_VPROC12_OC_SHIFT              1
#define PMIC_RG_INT_STATUS_VCORE_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VCORE_OC_SHIFT                2
#define PMIC_RG_INT_STATUS_VGPU_OC_MASK                  0x1
#define PMIC_RG_INT_STATUS_VGPU_OC_SHIFT                 3
#define PMIC_RG_INT_STATUS_VDRAM1_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VDRAM1_OC_SHIFT               4
#define PMIC_RG_INT_STATUS_VDRAM2_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VDRAM2_OC_SHIFT               5
#define PMIC_RG_INT_STATUS_VMODEM_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VMODEM_OC_SHIFT               6
#define PMIC_RG_INT_STATUS_VS1_OC_MASK                   0x1
#define PMIC_RG_INT_STATUS_VS1_OC_SHIFT                  7
#define PMIC_RG_INT_STATUS_VS2_OC_MASK                   0x1
#define PMIC_RG_INT_STATUS_VS2_OC_SHIFT                  8
#define PMIC_RG_INT_STATUS_VPA_OC_MASK                   0x1
#define PMIC_RG_INT_STATUS_VPA_OC_SHIFT                  9
#define PMIC_RG_INT_STATUS_VCORE_PREOC_MASK              0x1
#define PMIC_RG_INT_STATUS_VCORE_PREOC_SHIFT             10
#define PMIC_RG_INT_STATUS_VA10_OC_MASK                  0x1
#define PMIC_RG_INT_STATUS_VA10_OC_SHIFT                 11
#define PMIC_RG_INT_STATUS_VA12_OC_MASK                  0x1
#define PMIC_RG_INT_STATUS_VA12_OC_SHIFT                 12
#define PMIC_RG_INT_STATUS_VA18_OC_MASK                  0x1
#define PMIC_RG_INT_STATUS_VA18_OC_SHIFT                 13
#define PMIC_RG_INT_STATUS_VBIF28_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VBIF28_OC_SHIFT               14
#define PMIC_RG_INT_STATUS_VCAMA1_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VCAMA1_OC_SHIFT               15
#define PMIC_RG_INT_STATUS_VCAMA2_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VCAMA2_OC_SHIFT               0
#define PMIC_RG_INT_STATUS_VXO18_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VXO18_OC_SHIFT                1
#define PMIC_RG_INT_STATUS_VCAMD1_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VCAMD1_OC_SHIFT               2
#define PMIC_RG_INT_STATUS_VCAMD2_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VCAMD2_OC_SHIFT               3
#define PMIC_RG_INT_STATUS_VCAMIO_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VCAMIO_OC_SHIFT               4
#define PMIC_RG_INT_STATUS_VCN18_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VCN18_OC_SHIFT                5
#define PMIC_RG_INT_STATUS_VCN28_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VCN28_OC_SHIFT                6
#define PMIC_RG_INT_STATUS_VCN33_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VCN33_OC_SHIFT                7
#define PMIC_RG_INT_STATUS_VTCXO24_OC_MASK               0x1
#define PMIC_RG_INT_STATUS_VTCXO24_OC_SHIFT              8
#define PMIC_RG_INT_STATUS_VEMC_OC_MASK                  0x1
#define PMIC_RG_INT_STATUS_VEMC_OC_SHIFT                 9
#define PMIC_RG_INT_STATUS_VFE28_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VFE28_OC_SHIFT                10
#define PMIC_RG_INT_STATUS_VGP_OC_MASK                   0x1
#define PMIC_RG_INT_STATUS_VGP_OC_SHIFT                  11
#define PMIC_RG_INT_STATUS_VLDO28_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VLDO28_OC_SHIFT               12
#define PMIC_RG_INT_STATUS_VIO18_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VIO18_OC_SHIFT                13
#define PMIC_RG_INT_STATUS_VIO28_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VIO28_OC_SHIFT                14
#define PMIC_RG_INT_STATUS_VMC_OC_MASK                   0x1
#define PMIC_RG_INT_STATUS_VMC_OC_SHIFT                  15
#define PMIC_RG_INT_STATUS_VMCH_OC_MASK                  0x1
#define PMIC_RG_INT_STATUS_VMCH_OC_SHIFT                 0
#define PMIC_RG_INT_STATUS_VMIPI_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VMIPI_OC_SHIFT                1
#define PMIC_RG_INT_STATUS_VRF12_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VRF12_OC_SHIFT                2
#define PMIC_RG_INT_STATUS_VRF18_1_OC_MASK               0x1
#define PMIC_RG_INT_STATUS_VRF18_1_OC_SHIFT              3
#define PMIC_RG_INT_STATUS_VRF18_2_OC_MASK               0x1
#define PMIC_RG_INT_STATUS_VRF18_2_OC_SHIFT              4
#define PMIC_RG_INT_STATUS_VSIM1_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VSIM1_OC_SHIFT                5
#define PMIC_RG_INT_STATUS_VSIM2_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VSIM2_OC_SHIFT                6
#define PMIC_RG_INT_STATUS_VGP2_OC_MASK                  0x1
#define PMIC_RG_INT_STATUS_VGP2_OC_SHIFT                 7
#define PMIC_RG_INT_STATUS_VSRAM_CORE_OC_MASK            0x1
#define PMIC_RG_INT_STATUS_VSRAM_CORE_OC_SHIFT           8
#define PMIC_RG_INT_STATUS_VSRAM_PROC_OC_MASK            0x1
#define PMIC_RG_INT_STATUS_VSRAM_PROC_OC_SHIFT           9
#define PMIC_RG_INT_STATUS_VSRAM_GPU_OC_MASK             0x1
#define PMIC_RG_INT_STATUS_VSRAM_GPU_OC_SHIFT            10
#define PMIC_RG_INT_STATUS_VSRAM_MD_OC_MASK              0x1
#define PMIC_RG_INT_STATUS_VSRAM_MD_OC_SHIFT             11
#define PMIC_RG_INT_STATUS_VUFS18_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VUFS18_OC_SHIFT               12
#define PMIC_RG_INT_STATUS_VUSB33_OC_MASK                0x1
#define PMIC_RG_INT_STATUS_VUSB33_OC_SHIFT               13
#define PMIC_RG_INT_STATUS_VXO22_OC_MASK                 0x1
#define PMIC_RG_INT_STATUS_VXO22_OC_SHIFT                14
#define PMIC_RG_INT_STATUS_FG_BAT0_H_MASK                0x1
#define PMIC_RG_INT_STATUS_FG_BAT0_H_SHIFT               0
#define PMIC_RG_INT_STATUS_FG_BAT0_L_MASK                0x1
#define PMIC_RG_INT_STATUS_FG_BAT0_L_SHIFT               1
#define PMIC_RG_INT_STATUS_FG_CUR_H_MASK                 0x1
#define PMIC_RG_INT_STATUS_FG_CUR_H_SHIFT                2
#define PMIC_RG_INT_STATUS_FG_CUR_L_MASK                 0x1
#define PMIC_RG_INT_STATUS_FG_CUR_L_SHIFT                3
#define PMIC_RG_INT_STATUS_FG_ZCV_MASK                   0x1
#define PMIC_RG_INT_STATUS_FG_ZCV_SHIFT                  4
#define PMIC_RG_INT_STATUS_FG_BAT1_H_MASK                0x1
#define PMIC_RG_INT_STATUS_FG_BAT1_H_SHIFT               5
#define PMIC_RG_INT_STATUS_FG_BAT1_L_MASK                0x1
#define PMIC_RG_INT_STATUS_FG_BAT1_L_SHIFT               6
#define PMIC_RG_INT_STATUS_FG_N_CHARGE_L_MASK            0x1
#define PMIC_RG_INT_STATUS_FG_N_CHARGE_L_SHIFT           7
#define PMIC_RG_INT_STATUS_FG_IAVG_H_MASK                0x1
#define PMIC_RG_INT_STATUS_FG_IAVG_H_SHIFT               8
#define PMIC_RG_INT_STATUS_FG_IAVG_L_MASK                0x1
#define PMIC_RG_INT_STATUS_FG_IAVG_L_SHIFT               9
#define PMIC_RG_INT_STATUS_FG_TIME_H_MASK                0x1
#define PMIC_RG_INT_STATUS_FG_TIME_H_SHIFT               10
#define PMIC_RG_INT_STATUS_FG_DISCHARGE_MASK             0x1
#define PMIC_RG_INT_STATUS_FG_DISCHARGE_SHIFT            11
#define PMIC_RG_INT_STATUS_FG_CHARGE_MASK                0x1
#define PMIC_RG_INT_STATUS_FG_CHARGE_SHIFT               12
#define PMIC_RG_INT_STATUS_CON5_MASK                     0x7
#define PMIC_RG_INT_STATUS_CON5_SHIFT                    13
#define PMIC_RG_INT_STATUS_AUDIO_MASK                    0x1
#define PMIC_RG_INT_STATUS_AUDIO_SHIFT                   0
#define PMIC_RG_INT_STATUS_MAD_MASK                      0x1
#define PMIC_RG_INT_STATUS_MAD_SHIFT                     1
#define PMIC_RG_INT_STATUS_EINT_RTC32K_1V8_1_MASK        0x1
#define PMIC_RG_INT_STATUS_EINT_RTC32K_1V8_1_SHIFT       2
#define PMIC_RG_INT_STATUS_EINT_AUD_CLK_MASK             0x1
#define PMIC_RG_INT_STATUS_EINT_AUD_CLK_SHIFT            3
#define PMIC_RG_INT_STATUS_EINT_AUD_DAT_MOSI_MASK        0x1
#define PMIC_RG_INT_STATUS_EINT_AUD_DAT_MOSI_SHIFT       4
#define PMIC_RG_INT_STATUS_EINT_AUD_DAT_MISO_MASK        0x1
#define PMIC_RG_INT_STATUS_EINT_AUD_DAT_MISO_SHIFT       5
#define PMIC_RG_INT_STATUS_EINT_VOW_CLK_MISO_MASK        0x1
#define PMIC_RG_INT_STATUS_EINT_VOW_CLK_MISO_SHIFT       6
#define PMIC_RG_INT_STATUS_ACCDET_MASK                   0x1
#define PMIC_RG_INT_STATUS_ACCDET_SHIFT                  7
#define PMIC_RG_INT_STATUS_ACCDET_EINT_MASK              0x1
#define PMIC_RG_INT_STATUS_ACCDET_EINT_SHIFT             8
#define PMIC_RG_INT_STATUS_SPI_CMD_ALERT_MASK            0x1
#define PMIC_RG_INT_STATUS_SPI_CMD_ALERT_SHIFT           9
#define PMIC_RG_INT_RAW_STATUS_PWRKEY_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_PWRKEY_SHIFT              0
#define PMIC_RG_INT_RAW_STATUS_HOMEKEY_MASK              0x1
#define PMIC_RG_INT_RAW_STATUS_HOMEKEY_SHIFT             1
#define PMIC_RG_INT_RAW_STATUS_PWRKEY_R_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_PWRKEY_R_SHIFT            2
#define PMIC_RG_INT_RAW_STATUS_HOMEKEY_R_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_HOMEKEY_R_SHIFT           3
#define PMIC_RG_INT_RAW_STATUS_NI_LBAT_INT_MASK          0x1
#define PMIC_RG_INT_RAW_STATUS_NI_LBAT_INT_SHIFT         4
#define PMIC_RG_INT_RAW_STATUS_CHRDET_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_CHRDET_SHIFT              5
#define PMIC_RG_INT_RAW_STATUS_CHRDET_EDGE_MASK          0x1
#define PMIC_RG_INT_RAW_STATUS_CHRDET_EDGE_SHIFT         6
#define PMIC_RG_INT_RAW_STATUS_BATON_LV_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_BATON_LV_SHIFT            7
#define PMIC_RG_INT_RAW_STATUS_BATON_HV_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_BATON_HV_SHIFT            8
#define PMIC_RG_INT_RAW_STATUS_BATON_BAT_IN_MASK         0x1
#define PMIC_RG_INT_RAW_STATUS_BATON_BAT_IN_SHIFT        9
#define PMIC_RG_INT_RAW_STATUS_BATON_BAT_OUT_MASK        0x1
#define PMIC_RG_INT_RAW_STATUS_BATON_BAT_OUT_SHIFT       10
#define PMIC_RG_INT_RAW_STATUS_RTC_MASK                  0x1
#define PMIC_RG_INT_RAW_STATUS_RTC_SHIFT                 11
#define PMIC_RG_INT_RAW_STATUS_RTC_NSEC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_RTC_NSEC_SHIFT            12
#define PMIC_RG_INT_RAW_STATUS_BIF_MASK                  0x1
#define PMIC_RG_INT_RAW_STATUS_BIF_SHIFT                 13
#define PMIC_RG_INT_RAW_STATUS_VCDT_HV_DET_MASK          0x1
#define PMIC_RG_INT_RAW_STATUS_VCDT_HV_DET_SHIFT         14
#define PMIC_RG_INT_RAW_STATUS_THR_H_MASK                0x1
#define PMIC_RG_INT_RAW_STATUS_THR_H_SHIFT               0
#define PMIC_RG_INT_RAW_STATUS_THR_L_MASK                0x1
#define PMIC_RG_INT_RAW_STATUS_THR_L_SHIFT               1
#define PMIC_RG_INT_RAW_STATUS_BAT_H_MASK                0x1
#define PMIC_RG_INT_RAW_STATUS_BAT_H_SHIFT               2
#define PMIC_RG_INT_RAW_STATUS_BAT_L_MASK                0x1
#define PMIC_RG_INT_RAW_STATUS_BAT_L_SHIFT               3
#define PMIC_RG_INT_RAW_STATUS_BAT2_H_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_BAT2_H_SHIFT              4
#define PMIC_RG_INT_RAW_STATUS_BAT2_L_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_BAT2_L_SHIFT              5
#define PMIC_RG_INT_RAW_STATUS_BAT_TEMP_H_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_BAT_TEMP_H_SHIFT          6
#define PMIC_RG_INT_RAW_STATUS_BAT_TEMP_L_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_BAT_TEMP_L_SHIFT          7
#define PMIC_RG_INT_RAW_STATUS_AUXADC_IMP_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_AUXADC_IMP_SHIFT          8
#define PMIC_RG_INT_RAW_STATUS_NAG_C_DLTV_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_NAG_C_DLTV_SHIFT          9
#define PMIC_RG_INT_RAW_STATUS_JEITA_HOT_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_JEITA_HOT_SHIFT           10
#define PMIC_RG_INT_RAW_STATUS_JEITA_WARM_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_JEITA_WARM_SHIFT          11
#define PMIC_RG_INT_RAW_STATUS_JEITA_COOL_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_JEITA_COOL_SHIFT          12
#define PMIC_RG_INT_RAW_STATUS_JEITA_COLD_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_JEITA_COLD_SHIFT          13
#define PMIC_RG_INT_RAW_STATUS_VPROC11_OC_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_VPROC11_OC_SHIFT          0
#define PMIC_RG_INT_RAW_STATUS_VPROC12_OC_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_VPROC12_OC_SHIFT          1
#define PMIC_RG_INT_RAW_STATUS_VCORE_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VCORE_OC_SHIFT            2
#define PMIC_RG_INT_RAW_STATUS_VGPU_OC_MASK              0x1
#define PMIC_RG_INT_RAW_STATUS_VGPU_OC_SHIFT             3
#define PMIC_RG_INT_RAW_STATUS_VDRAM1_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VDRAM1_OC_SHIFT           4
#define PMIC_RG_INT_RAW_STATUS_VDRAM2_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VDRAM2_OC_SHIFT           5
#define PMIC_RG_INT_RAW_STATUS_VMODEM_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VMODEM_OC_SHIFT           6
#define PMIC_RG_INT_RAW_STATUS_VS1_OC_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_VS1_OC_SHIFT              7
#define PMIC_RG_INT_RAW_STATUS_VS2_OC_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_VS2_OC_SHIFT              8
#define PMIC_RG_INT_RAW_STATUS_VPA_OC_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_VPA_OC_SHIFT              9
#define PMIC_RG_INT_RAW_STATUS_VCORE_PREOC_MASK          0x1
#define PMIC_RG_INT_RAW_STATUS_VCORE_PREOC_SHIFT         10
#define PMIC_RG_INT_RAW_STATUS_VA10_OC_MASK              0x1
#define PMIC_RG_INT_RAW_STATUS_VA10_OC_SHIFT             11
#define PMIC_RG_INT_RAW_STATUS_VA12_OC_MASK              0x1
#define PMIC_RG_INT_RAW_STATUS_VA12_OC_SHIFT             12
#define PMIC_RG_INT_RAW_STATUS_VA18_OC_MASK              0x1
#define PMIC_RG_INT_RAW_STATUS_VA18_OC_SHIFT             13
#define PMIC_RG_INT_RAW_STATUS_VBIF28_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VBIF28_OC_SHIFT           14
#define PMIC_RG_INT_RAW_STATUS_VCAMA1_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VCAMA1_OC_SHIFT           15
#define PMIC_RG_INT_RAW_STATUS_VCAMA2_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VCAMA2_OC_SHIFT           0
#define PMIC_RG_INT_RAW_STATUS_VXO18_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VXO18_OC_SHIFT            1
#define PMIC_RG_INT_RAW_STATUS_VCAMD1_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VCAMD1_OC_SHIFT           2
#define PMIC_RG_INT_RAW_STATUS_VCAMD2_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VCAMD2_OC_SHIFT           3
#define PMIC_RG_INT_RAW_STATUS_VCAMIO_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VCAMIO_OC_SHIFT           4
#define PMIC_RG_INT_RAW_STATUS_VCN18_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VCN18_OC_SHIFT            5
#define PMIC_RG_INT_RAW_STATUS_VCN28_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VCN28_OC_SHIFT            6
#define PMIC_RG_INT_RAW_STATUS_VCN33_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VCN33_OC_SHIFT            7
#define PMIC_RG_INT_RAW_STATUS_VTCXO24_OC_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_VTCXO24_OC_SHIFT          8
#define PMIC_RG_INT_RAW_STATUS_VEMC_OC_MASK              0x1
#define PMIC_RG_INT_RAW_STATUS_VEMC_OC_SHIFT             9
#define PMIC_RG_INT_RAW_STATUS_VFE28_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VFE28_OC_SHIFT            10
#define PMIC_RG_INT_RAW_STATUS_VGP_OC_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_VGP_OC_SHIFT              11
#define PMIC_RG_INT_RAW_STATUS_VLDO28_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VLDO28_OC_SHIFT           12
#define PMIC_RG_INT_RAW_STATUS_VIO18_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VIO18_OC_SHIFT            13
#define PMIC_RG_INT_RAW_STATUS_VIO28_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VIO28_OC_SHIFT            14
#define PMIC_RG_INT_RAW_STATUS_VMC_OC_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_VMC_OC_SHIFT              15
#define PMIC_RG_INT_RAW_STATUS_VMCH_OC_MASK              0x1
#define PMIC_RG_INT_RAW_STATUS_VMCH_OC_SHIFT             0
#define PMIC_RG_INT_RAW_STATUS_VMIPI_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VMIPI_OC_SHIFT            1
#define PMIC_RG_INT_RAW_STATUS_VRF12_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VRF12_OC_SHIFT            2
#define PMIC_RG_INT_RAW_STATUS_VRF18_1_OC_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_VRF18_1_OC_SHIFT          3
#define PMIC_RG_INT_RAW_STATUS_VRF18_2_OC_MASK           0x1
#define PMIC_RG_INT_RAW_STATUS_VRF18_2_OC_SHIFT          4
#define PMIC_RG_INT_RAW_STATUS_VSIM1_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VSIM1_OC_SHIFT            5
#define PMIC_RG_INT_RAW_STATUS_VSIM2_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VSIM2_OC_SHIFT            6
#define PMIC_RG_INT_RAW_STATUS_VGP2_OC_MASK              0x1
#define PMIC_RG_INT_RAW_STATUS_VGP2_OC_SHIFT             7
#define PMIC_RG_INT_RAW_STATUS_VSRAM_CORE_OC_MASK        0x1
#define PMIC_RG_INT_RAW_STATUS_VSRAM_CORE_OC_SHIFT       8
#define PMIC_RG_INT_RAW_STATUS_VSRAM_PROC_OC_MASK        0x1
#define PMIC_RG_INT_RAW_STATUS_VSRAM_PROC_OC_SHIFT       9
#define PMIC_RG_INT_RAW_STATUS_VSRAM_GPU_OC_MASK         0x1
#define PMIC_RG_INT_RAW_STATUS_VSRAM_GPU_OC_SHIFT        10
#define PMIC_RG_INT_RAW_STATUS_VSRAM_MD_OC_MASK          0x1
#define PMIC_RG_INT_RAW_STATUS_VSRAM_MD_OC_SHIFT         11
#define PMIC_RG_INT_RAW_STATUS_VUFS18_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VUFS18_OC_SHIFT           12
#define PMIC_RG_INT_RAW_STATUS_VUSB33_OC_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_VUSB33_OC_SHIFT           13
#define PMIC_RG_INT_RAW_STATUS_VXO22_OC_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_VXO22_OC_SHIFT            14
#define PMIC_RG_INT_RAW_STATUS_FG_BAT0_H_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_FG_BAT0_H_SHIFT           0
#define PMIC_RG_INT_RAW_STATUS_FG_BAT0_L_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_FG_BAT0_L_SHIFT           1
#define PMIC_RG_INT_RAW_STATUS_FG_CUR_H_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_FG_CUR_H_SHIFT            2
#define PMIC_RG_INT_RAW_STATUS_FG_CUR_L_MASK             0x1
#define PMIC_RG_INT_RAW_STATUS_FG_CUR_L_SHIFT            3
#define PMIC_RG_INT_RAW_STATUS_FG_ZCV_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_FG_ZCV_SHIFT              4
#define PMIC_RG_INT_RAW_STATUS_FG_BAT1_H_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_FG_BAT1_H_SHIFT           5
#define PMIC_RG_INT_RAW_STATUS_FG_BAT1_L_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_FG_BAT1_L_SHIFT           6
#define PMIC_RG_INT_RAW_STATUS_FG_N_CHARGE_L_MASK        0x1
#define PMIC_RG_INT_RAW_STATUS_FG_N_CHARGE_L_SHIFT       7
#define PMIC_RG_INT_RAW_STATUS_FG_IAVG_H_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_FG_IAVG_H_SHIFT           8
#define PMIC_RG_INT_RAW_STATUS_FG_IAVG_L_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_FG_IAVG_L_SHIFT           9
#define PMIC_RG_INT_RAW_STATUS_FG_TIME_H_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_FG_TIME_H_SHIFT           10
#define PMIC_RG_INT_RAW_STATUS_FG_DISCHARGE_MASK         0x1
#define PMIC_RG_INT_RAW_STATUS_FG_DISCHARGE_SHIFT        11
#define PMIC_RG_INT_RAW_STATUS_FG_CHARGE_MASK            0x1
#define PMIC_RG_INT_RAW_STATUS_FG_CHARGE_SHIFT           12
#define PMIC_RG_INT_RAW_STATUS_CON5_MASK                 0x7
#define PMIC_RG_INT_RAW_STATUS_CON5_SHIFT                13
#define PMIC_RG_INT_RAW_STATUS_AUDIO_MASK                0x1
#define PMIC_RG_INT_RAW_STATUS_AUDIO_SHIFT               0
#define PMIC_RG_INT_RAW_STATUS_MAD_MASK                  0x1
#define PMIC_RG_INT_RAW_STATUS_MAD_SHIFT                 1
#define PMIC_RG_INT_RAW_STATUS_EINT_RTC32K_1V8_1_MASK    0x1
#define PMIC_RG_INT_RAW_STATUS_EINT_RTC32K_1V8_1_SHIFT   2
#define PMIC_RG_INT_RAW_STATUS_EINT_AUD_CLK_MASK         0x1
#define PMIC_RG_INT_RAW_STATUS_EINT_AUD_CLK_SHIFT        3
#define PMIC_RG_INT_RAW_STATUS_EINT_AUD_DAT_MOSI_MASK    0x1
#define PMIC_RG_INT_RAW_STATUS_EINT_AUD_DAT_MOSI_SHIFT   4
#define PMIC_RG_INT_RAW_STATUS_EINT_AUD_DAT_MISO_MASK    0x1
#define PMIC_RG_INT_RAW_STATUS_EINT_AUD_DAT_MISO_SHIFT   5
#define PMIC_RG_INT_RAW_STATUS_EINT_VOW_CLK_MISO_MASK    0x1
#define PMIC_RG_INT_RAW_STATUS_EINT_VOW_CLK_MISO_SHIFT   6
#define PMIC_RG_INT_RAW_STATUS_ACCDET_MASK               0x1
#define PMIC_RG_INT_RAW_STATUS_ACCDET_SHIFT              7
#define PMIC_RG_INT_RAW_STATUS_ACCDET_EINT_MASK          0x1
#define PMIC_RG_INT_RAW_STATUS_ACCDET_EINT_SHIFT         8
#define PMIC_RG_INT_RAW_STATUS_SPI_CMD_ALERT_MASK        0x1
#define PMIC_RG_INT_RAW_STATUS_SPI_CMD_ALERT_SHIFT       9
#define PMIC_POLARITY_MASK                               0x1
#define PMIC_POLARITY_SHIFT                              0
#define PMIC_RG_HOMEKEY_INT_SEL_MASK                     0x1
#define PMIC_RG_HOMEKEY_INT_SEL_SHIFT                    1
#define PMIC_RG_PWRKEY_INT_SEL_MASK                      0x1
#define PMIC_RG_PWRKEY_INT_SEL_SHIFT                     2
#define PMIC_RG_CHRDET_INT_SEL_MASK                      0x1
#define PMIC_RG_CHRDET_INT_SEL_SHIFT                     3
#define PMIC_RG_PCHR_CM_VINC_POLARITY_RSV_MASK           0x1
#define PMIC_RG_PCHR_CM_VINC_POLARITY_RSV_SHIFT          4
#define PMIC_RG_PCHR_CM_VDEC_POLARITY_RSV_MASK           0x1
#define PMIC_RG_PCHR_CM_VDEC_POLARITY_RSV_SHIFT          5
#define PMIC_INT_MISC_CON_SET_MASK                       0xFFFF
#define PMIC_INT_MISC_CON_SET_SHIFT                      0
#define PMIC_INT_MISC_CON_CLR_MASK                       0xFFFF
#define PMIC_INT_MISC_CON_CLR_SHIFT                      0
#define PMIC_RG_INT_SEN_EINT_RTC32K_1V8_1_MASK           0x1
#define PMIC_RG_INT_SEN_EINT_RTC32K_1V8_1_SHIFT          0
#define PMIC_RG_INT_SEN_EINT_AUD_CLK_MASK                0x1
#define PMIC_RG_INT_SEN_EINT_AUD_CLK_SHIFT               1
#define PMIC_RG_INT_SEN_EINT_AUD_DAT_MOSI_MASK           0x1
#define PMIC_RG_INT_SEN_EINT_AUD_DAT_MOSI_SHIFT          2
#define PMIC_RG_INT_SEN_EINT_AUD_DAT_MISO_MASK           0x1
#define PMIC_RG_INT_SEN_EINT_AUD_DAT_MISO_SHIFT          3
#define PMIC_RG_INT_SEN_EINT_VOW_CLK_MISO_MASK           0x1
#define PMIC_RG_INT_SEN_EINT_VOW_CLK_MISO_SHIFT          4
#define PMIC_INT_EINT_CON0_SET_MASK                      0xFFFF
#define PMIC_INT_EINT_CON0_SET_SHIFT                     0
#define PMIC_INT_EINT_CON0_CLR_MASK                      0xFFFF
#define PMIC_INT_EINT_CON0_CLR_SHIFT                     0
#define PMIC_RG_INT_POL_EINT_RTC32K_1V8_1_MASK           0x1
#define PMIC_RG_INT_POL_EINT_RTC32K_1V8_1_SHIFT          0
#define PMIC_RG_INT_POL_EINT_AUD_CLK_MASK                0x1
#define PMIC_RG_INT_POL_EINT_AUD_CLK_SHIFT               1
#define PMIC_RG_INT_POL_EINT_AUD_DAT_MOSI_MASK           0x1
#define PMIC_RG_INT_POL_EINT_AUD_DAT_MOSI_SHIFT          2
#define PMIC_RG_INT_POL_EINT_AUD_DAT_MISO_MASK           0x1
#define PMIC_RG_INT_POL_EINT_AUD_DAT_MISO_SHIFT          3
#define PMIC_RG_INT_POL_EINT_VOW_CLK_MISO_MASK           0x1
#define PMIC_RG_INT_POL_EINT_VOW_CLK_MISO_SHIFT          4
#define PMIC_INT_EINT_CON1_SET_MASK                      0xFFFF
#define PMIC_INT_EINT_CON1_SET_SHIFT                     0
#define PMIC_INT_EINT_CON1_CLR_MASK                      0xFFFF
#define PMIC_INT_EINT_CON1_CLR_SHIFT                     0
#define PMIC_RG_SW_SEL_EINT_RTC32K_1V8_1_MASK            0x1
#define PMIC_RG_SW_SEL_EINT_RTC32K_1V8_1_SHIFT           0
#define PMIC_RG_SW_SEL_EINT_AUD_CLK_MASK                 0x1
#define PMIC_RG_SW_SEL_EINT_AUD_CLK_SHIFT                1
#define PMIC_RG_SW_SEL_EINT_AUD_DAT_MOSI_MASK            0x1
#define PMIC_RG_SW_SEL_EINT_AUD_DAT_MOSI_SHIFT           2
#define PMIC_RG_SW_SEL_EINT_AUD_DAT_MISO_MASK            0x1
#define PMIC_RG_SW_SEL_EINT_AUD_DAT_MISO_SHIFT           3
#define PMIC_RG_SW_SEL_EINT_VOW_CLK_MISO_MASK            0x1
#define PMIC_RG_SW_SEL_EINT_VOW_CLK_MISO_SHIFT           4
#define PMIC_INT_EINT_CON2_SET_MASK                      0xFFFF
#define PMIC_INT_EINT_CON2_SET_SHIFT                     0
#define PMIC_INT_EINT_CON2_CLR_MASK                      0xFFFF
#define PMIC_INT_EINT_CON2_CLR_SHIFT                     0
#define PMIC_RG_SW_EINT_RTC32K_1V8_1_MASK                0x1
#define PMIC_RG_SW_EINT_RTC32K_1V8_1_SHIFT               0
#define PMIC_RG_SW_EINT_AUD_CLK_MASK                     0x1
#define PMIC_RG_SW_EINT_AUD_CLK_SHIFT                    1
#define PMIC_RG_SW_EINT_AUD_DAT_MOSI_MASK                0x1
#define PMIC_RG_SW_EINT_AUD_DAT_MOSI_SHIFT               2
#define PMIC_RG_SW_EINT_AUD_DAT_MISO_MASK                0x1
#define PMIC_RG_SW_EINT_AUD_DAT_MISO_SHIFT               3
#define PMIC_RG_SW_EINT_VOW_CLK_MISO_MASK                0x1
#define PMIC_RG_SW_EINT_VOW_CLK_MISO_SHIFT               4
#define PMIC_INT_EINT_CON3_SET_MASK                      0xFFFF
#define PMIC_INT_EINT_CON3_SET_SHIFT                     0
#define PMIC_INT_EINT_CON3_CLR_MASK                      0xFFFF
#define PMIC_INT_EINT_CON3_CLR_SHIFT                     0
#define PMIC_RG_DEB_EINT_RTC32K_1V8_1_MASK               0x3
#define PMIC_RG_DEB_EINT_RTC32K_1V8_1_SHIFT              0
#define PMIC_RG_DEB_EINT_AUD_CLK_MASK                    0x3
#define PMIC_RG_DEB_EINT_AUD_CLK_SHIFT                   2
#define PMIC_RG_DEB_EINT_AUD_DAT_MOSI_MASK               0x3
#define PMIC_RG_DEB_EINT_AUD_DAT_MOSI_SHIFT              4
#define PMIC_RG_DEB_EINT_AUD_DAT_MISO_MASK               0x3
#define PMIC_RG_DEB_EINT_AUD_DAT_MISO_SHIFT              6
#define PMIC_RG_DEB_EINT_VOW_CLK_MISO_MASK               0x3
#define PMIC_RG_DEB_EINT_VOW_CLK_MISO_SHIFT              8
#define PMIC_INT_EINT_CON4_SET_MASK                      0xFFFF
#define PMIC_INT_EINT_CON4_SET_SHIFT                     0
#define PMIC_INT_EINT_CON4_CLR_MASK                      0xFFFF
#define PMIC_INT_EINT_CON4_CLR_SHIFT                     0
#define PMIC_FQMTR_TCKSEL_MASK                           0x7
#define PMIC_FQMTR_TCKSEL_SHIFT                          0
#define PMIC_FQMTR_BUSY_MASK                             0x1
#define PMIC_FQMTR_BUSY_SHIFT                            3
#define PMIC_FQMTR_DCXO26M_EN_MASK                       0x1
#define PMIC_FQMTR_DCXO26M_EN_SHIFT                      4
#define PMIC_FQMTR_EN_MASK                               0x1
#define PMIC_FQMTR_EN_SHIFT                              15
#define PMIC_FQMTR_WINSET_MASK                           0xFFFF
#define PMIC_FQMTR_WINSET_SHIFT                          0
#define PMIC_FQMTR_DATA_MASK                             0xFFFF
#define PMIC_FQMTR_DATA_SHIFT                            0
#define PMIC_RG_SLP_RW_EN_MASK                           0x1
#define PMIC_RG_SLP_RW_EN_SHIFT                          0
#define PMIC_RG_SPI_RSV_MASK                             0x7FFF
#define PMIC_RG_SPI_RSV_SHIFT                            1
#define PMIC_DEW_DIO_EN_MASK                             0x1
#define PMIC_DEW_DIO_EN_SHIFT                            0
#define PMIC_DEW_READ_TEST_MASK                          0xFFFF
#define PMIC_DEW_READ_TEST_SHIFT                         0
#define PMIC_DEW_WRITE_TEST_MASK                         0xFFFF
#define PMIC_DEW_WRITE_TEST_SHIFT                        0
#define PMIC_DEW_CRC_SWRST_MASK                          0x1
#define PMIC_DEW_CRC_SWRST_SHIFT                         0
#define PMIC_DEW_CRC_EN_MASK                             0x1
#define PMIC_DEW_CRC_EN_SHIFT                            0
#define PMIC_DEW_CRC_VAL_MASK                            0xFF
#define PMIC_DEW_CRC_VAL_SHIFT                           0
#define PMIC_DEW_DBG_MON_SEL_MASK                        0xF
#define PMIC_DEW_DBG_MON_SEL_SHIFT                       0
#define PMIC_DEW_CIPHER_KEY_SEL_MASK                     0x3
#define PMIC_DEW_CIPHER_KEY_SEL_SHIFT                    0
#define PMIC_DEW_CIPHER_IV_SEL_MASK                      0x3
#define PMIC_DEW_CIPHER_IV_SEL_SHIFT                     0
#define PMIC_DEW_CIPHER_EN_MASK                          0x1
#define PMIC_DEW_CIPHER_EN_SHIFT                         0
#define PMIC_DEW_CIPHER_RDY_MASK                         0x1
#define PMIC_DEW_CIPHER_RDY_SHIFT                        0
#define PMIC_DEW_CIPHER_MODE_MASK                        0x1
#define PMIC_DEW_CIPHER_MODE_SHIFT                       0
#define PMIC_DEW_CIPHER_SWRST_MASK                       0x1
#define PMIC_DEW_CIPHER_SWRST_SHIFT                      0
#define PMIC_DEW_RDDMY_NO_MASK                           0xF
#define PMIC_DEW_RDDMY_NO_SHIFT                          0
#define PMIC_INT_TYPE_CON0_MASK                          0xFFFF
#define PMIC_INT_TYPE_CON0_SHIFT                         0
#define PMIC_INT_TYPE_CON0_SET_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON0_SET_SHIFT                     0
#define PMIC_INT_TYPE_CON0_CLR_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON0_CLR_SHIFT                     0
#define PMIC_INT_TYPE_CON1_MASK                          0xFFFF
#define PMIC_INT_TYPE_CON1_SHIFT                         0
#define PMIC_INT_TYPE_CON1_SET_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON1_SET_SHIFT                     0
#define PMIC_INT_TYPE_CON1_CLR_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON1_CLR_SHIFT                     0
#define PMIC_INT_TYPE_CON2_MASK                          0xFFFF
#define PMIC_INT_TYPE_CON2_SHIFT                         0
#define PMIC_INT_TYPE_CON2_SET_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON2_SET_SHIFT                     0
#define PMIC_INT_TYPE_CON2_CLR_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON2_CLR_SHIFT                     0
#define PMIC_INT_TYPE_CON3_MASK                          0xFFFF
#define PMIC_INT_TYPE_CON3_SHIFT                         0
#define PMIC_INT_TYPE_CON3_SET_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON3_SET_SHIFT                     0
#define PMIC_INT_TYPE_CON3_CLR_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON3_CLR_SHIFT                     0
#define PMIC_INT_TYPE_CON4_MASK                          0xFFFF
#define PMIC_INT_TYPE_CON4_SHIFT                         0
#define PMIC_INT_TYPE_CON4_SET_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON4_SET_SHIFT                     0
#define PMIC_INT_TYPE_CON4_CLR_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON4_CLR_SHIFT                     0
#define PMIC_INT_TYPE_CON5_MASK                          0xFFFF
#define PMIC_INT_TYPE_CON5_SHIFT                         0
#define PMIC_INT_TYPE_CON5_SET_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON5_SET_SHIFT                     0
#define PMIC_INT_TYPE_CON5_CLR_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON5_CLR_SHIFT                     0
#define PMIC_INT_TYPE_CON6_MASK                          0xFFFF
#define PMIC_INT_TYPE_CON6_SHIFT                         0
#define PMIC_INT_TYPE_CON6_SET_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON6_SET_SHIFT                     0
#define PMIC_INT_TYPE_CON6_CLR_MASK                      0xFFFF
#define PMIC_INT_TYPE_CON6_CLR_SHIFT                     0
#define PMIC_CPU_INT_STA_MASK                            0x1
#define PMIC_CPU_INT_STA_SHIFT                           0
#define PMIC_MD32_INT_STA_MASK                           0x1
#define PMIC_MD32_INT_STA_SHIFT                          1
#define PMIC_RG_SRCLKEN_IN3_SMPS_CLK_MODE_MASK           0x1
#define PMIC_RG_SRCLKEN_IN3_SMPS_CLK_MODE_SHIFT          0
#define PMIC_RG_SRCLKEN_IN3_EN_SMPS_TEST_MASK            0x1
#define PMIC_RG_SRCLKEN_IN3_EN_SMPS_TEST_SHIFT           1
#define PMIC_RG_SRCLKEN_IN2_SMPS_CLK_MODE_MASK           0x1
#define PMIC_RG_SRCLKEN_IN2_SMPS_CLK_MODE_SHIFT          2
#define PMIC_RG_SRCLKEN_IN2_EN_SMPS_TEST_MASK            0x1
#define PMIC_RG_SRCLKEN_IN2_EN_SMPS_TEST_SHIFT           3
#define PMIC_RG_SPI_DLY_SEL_MASK                         0xF
#define PMIC_RG_SPI_DLY_SEL_SHIFT                        0
#define PMIC_RECORD_CMD0_MASK                            0xFFFF
#define PMIC_RECORD_CMD0_SHIFT                           0
#define PMIC_RECORD_CMD1_MASK                            0xFFFF
#define PMIC_RECORD_CMD1_SHIFT                           0
#define PMIC_RECORD_CMD2_MASK                            0xFFFF
#define PMIC_RECORD_CMD2_SHIFT                           0
#define PMIC_RECORD_WDATA0_MASK                          0xFFFF
#define PMIC_RECORD_WDATA0_SHIFT                         0
#define PMIC_RECORD_WDATA1_MASK                          0xFFFF
#define PMIC_RECORD_WDATA1_SHIFT                         0
#define PMIC_RECORD_WDATA2_MASK                          0xFFFF
#define PMIC_RECORD_WDATA2_SHIFT                         0
#define PMIC_RG_ADDR_TARGET_MASK                         0xFFFF
#define PMIC_RG_ADDR_TARGET_SHIFT                        0
#define PMIC_RG_ADDR_MASK_MASK                           0xFFFF
#define PMIC_RG_ADDR_MASK_SHIFT                          0
#define PMIC_RG_WDATA_TARGET_MASK                        0xFFFF
#define PMIC_RG_WDATA_TARGET_SHIFT                       0
#define PMIC_RG_WDATA_MASK_MASK                          0xFFFF
#define PMIC_RG_WDATA_MASK_SHIFT                         0
#define PMIC_RG_SPI_RECORD_CLR_MASK                      0x1
#define PMIC_RG_SPI_RECORD_CLR_SHIFT                     0
#define PMIC_RG_CMD_ALERT_CLR_MASK                       0x1
#define PMIC_RG_CMD_ALERT_CLR_SHIFT                      15
#define PMIC_RG_THR_DET_DIS_MASK                         0x1
#define PMIC_RG_THR_DET_DIS_SHIFT                        12
#define PMIC_RG_THR_TEST_MASK                            0x3
#define PMIC_RG_THR_TEST_SHIFT                           13
#define PMIC_RG_STRUP_THER_DEB_RMAX_MASK                 0xFFFF
#define PMIC_RG_STRUP_THER_DEB_RMAX_SHIFT                0
#define PMIC_RG_STRUP_THER_DEB_FMAX_MASK                 0xFFFF
#define PMIC_RG_STRUP_THER_DEB_FMAX_SHIFT                0
#define PMIC_DDUVLO_DEB_EN_MASK                          0x1
#define PMIC_DDUVLO_DEB_EN_SHIFT                         0
#define PMIC_RG_STRUP_OSC_EN_MASK                        0x1
#define PMIC_RG_STRUP_OSC_EN_SHIFT                       2
#define PMIC_RG_STRUP_OSC_EN_SEL_MASK                    0x1
#define PMIC_RG_STRUP_OSC_EN_SEL_SHIFT                   3
#define PMIC_RG_STRUP_FT_CTRL_MASK                       0x3
#define PMIC_RG_STRUP_FT_CTRL_SHIFT                      4
#define PMIC_RG_STRUP_PWRON_FORCE_MASK                   0x1
#define PMIC_RG_STRUP_PWRON_FORCE_SHIFT                  6
#define PMIC_RG_BIASGEN_FORCE_MASK                       0x1
#define PMIC_RG_BIASGEN_FORCE_SHIFT                      7
#define PMIC_RG_STRUP_PWRON_MASK                         0x1
#define PMIC_RG_STRUP_PWRON_SHIFT                        8
#define PMIC_RG_STRUP_PWRON_SEL_MASK                     0x1
#define PMIC_RG_STRUP_PWRON_SEL_SHIFT                    9
#define PMIC_RG_BIASGEN_MASK                             0x1
#define PMIC_RG_BIASGEN_SHIFT                            10
#define PMIC_RG_BIASGEN_SEL_MASK                         0x1
#define PMIC_RG_BIASGEN_SEL_SHIFT                        11
#define PMIC_RG_RTC_XOSC32_ENB_MASK                      0x1
#define PMIC_RG_RTC_XOSC32_ENB_SHIFT                     12
#define PMIC_RG_RTC_XOSC32_ENB_SEL_MASK                  0x1
#define PMIC_RG_RTC_XOSC32_ENB_SEL_SHIFT                 13
#define PMIC_STRUP_DIG_IO_PG_FORCE_MASK                  0x1
#define PMIC_STRUP_DIG_IO_PG_FORCE_SHIFT                 15
#define PMIC_RG_CLR_JUST_SMART_RST_MASK                  0x1
#define PMIC_RG_CLR_JUST_SMART_RST_SHIFT                 3
#define PMIC_CLR_JUST_RST_MASK                           0x1
#define PMIC_CLR_JUST_RST_SHIFT                          4
#define PMIC_UVLO_L2H_DEB_EN_MASK                        0x1
#define PMIC_UVLO_L2H_DEB_EN_SHIFT                       5
#define PMIC_JUST_SMART_RST_MASK                         0x1
#define PMIC_JUST_SMART_RST_SHIFT                        13
#define PMIC_JUST_PWRKEY_RST_MASK                        0x1
#define PMIC_JUST_PWRKEY_RST_SHIFT                       14
#define PMIC_DA_QI_OSC_EN_MASK                           0x1
#define PMIC_DA_QI_OSC_EN_SHIFT                          15
#define PMIC_RG_STRUP_EXT_PMIC_EN_MASK                   0x1
#define PMIC_RG_STRUP_EXT_PMIC_EN_SHIFT                  0
#define PMIC_RG_STRUP_EXT_PMIC_SEL_MASK                  0x1
#define PMIC_RG_STRUP_EXT_PMIC_SEL_SHIFT                 1
#define PMIC_STRUP_CON8_RSV0_MASK                        0x7F
#define PMIC_STRUP_CON8_RSV0_SHIFT                       8
#define PMIC_DA_QI_EXT_PMIC_EN_MASK                      0x1
#define PMIC_DA_QI_EXT_PMIC_EN_SHIFT                     15
#define PMIC_RG_STRUP_AUXADC_START_SW_MASK               0x1
#define PMIC_RG_STRUP_AUXADC_START_SW_SHIFT              0
#define PMIC_RG_STRUP_AUXADC_RSTB_SW_MASK                0x1
#define PMIC_RG_STRUP_AUXADC_RSTB_SW_SHIFT               1
#define PMIC_RG_STRUP_AUXADC_START_SEL_MASK              0x1
#define PMIC_RG_STRUP_AUXADC_START_SEL_SHIFT             2
#define PMIC_RG_STRUP_AUXADC_RSTB_SEL_MASK               0x1
#define PMIC_RG_STRUP_AUXADC_RSTB_SEL_SHIFT              3
#define PMIC_RG_STRUP_AUXADC_RPCNT_MAX_MASK              0x7F
#define PMIC_RG_STRUP_AUXADC_RPCNT_MAX_SHIFT             4
#define PMIC_STRUP_PWROFF_SEQ_EN_MASK                    0x1
#define PMIC_STRUP_PWROFF_SEQ_EN_SHIFT                   0
#define PMIC_STRUP_PWROFF_PREOFF_EN_MASK                 0x1
#define PMIC_STRUP_PWROFF_PREOFF_EN_SHIFT                1
#define PMIC_STRUP_DIG0_RSV0_MASK                        0xF
#define PMIC_STRUP_DIG0_RSV0_SHIFT                       2
#define PMIC_STRUP_DIG1_RSV0_MASK                        0x1F
#define PMIC_STRUP_DIG1_RSV0_SHIFT                       6
#define PMIC_RG_RSV_SWREG_MASK                           0xFFFF
#define PMIC_RG_RSV_SWREG_SHIFT                          0
#define PMIC_RG_STRUP_UVLO_U1U2_SEL_MASK                 0x1
#define PMIC_RG_STRUP_UVLO_U1U2_SEL_SHIFT                0
#define PMIC_RG_STRUP_UVLO_U1U2_SEL_SWCTRL_MASK          0x1
#define PMIC_RG_STRUP_UVLO_U1U2_SEL_SWCTRL_SHIFT         1
#define PMIC_RG_STRUP_THR_CLR_MASK                       0x1
#define PMIC_RG_STRUP_THR_CLR_SHIFT                      0
#define PMIC_RG_STRUP_LONG_PRESS_EXT_SEL_MASK            0x3
#define PMIC_RG_STRUP_LONG_PRESS_EXT_SEL_SHIFT           0
#define PMIC_RG_STRUP_LONG_PRESS_EXT_TD_MASK             0x3
#define PMIC_RG_STRUP_LONG_PRESS_EXT_TD_SHIFT            2
#define PMIC_RG_STRUP_LONG_PRESS_EXT_EN_MASK             0x1
#define PMIC_RG_STRUP_LONG_PRESS_EXT_EN_SHIFT            4
#define PMIC_RG_STRUP_LONG_PRESS_EXT_CHR_CTRL_MASK       0x1
#define PMIC_RG_STRUP_LONG_PRESS_EXT_CHR_CTRL_SHIFT      5
#define PMIC_RG_STRUP_LONG_PRESS_EXT_PWRKEY_CTRL_MASK    0x1
#define PMIC_RG_STRUP_LONG_PRESS_EXT_PWRKEY_CTRL_SHIFT   6
#define PMIC_RG_STRUP_LONG_PRESS_EXT_SPAR_CTRL_MASK      0x1
#define PMIC_RG_STRUP_LONG_PRESS_EXT_SPAR_CTRL_SHIFT     7
#define PMIC_RG_STRUP_LONG_PRESS_EXT_RTCA_CTRL_MASK      0x1
#define PMIC_RG_STRUP_LONG_PRESS_EXT_RTCA_CTRL_SHIFT     8
#define PMIC_RG_SMART_RST_MODE_MASK                      0x1
#define PMIC_RG_SMART_RST_MODE_SHIFT                     13
#define PMIC_RG_STRUP_ENVTEM_MASK                        0x1
#define PMIC_RG_STRUP_ENVTEM_SHIFT                       14
#define PMIC_RG_STRUP_ENVTEM_CTRL_MASK                   0x1
#define PMIC_RG_STRUP_ENVTEM_CTRL_SHIFT                  15
#define PMIC_RG_STRUP_PWRKEY_COUNT_RESET_MASK            0x1
#define PMIC_RG_STRUP_PWRKEY_COUNT_RESET_SHIFT           0
#define PMIC_RG_STRUP_VA12_PG_H2L_EN_MASK                0x1
#define PMIC_RG_STRUP_VA12_PG_H2L_EN_SHIFT               0
#define PMIC_RG_STRUP_VA10_PG_H2L_EN_MASK                0x1
#define PMIC_RG_STRUP_VA10_PG_H2L_EN_SHIFT               1
#define PMIC_RG_STRUP_VSRAM_GPU_PG_H2L_EN_MASK           0x1
#define PMIC_RG_STRUP_VSRAM_GPU_PG_H2L_EN_SHIFT          2
#define PMIC_RG_STRUP_VSRAM_MD_PG_H2L_EN_MASK            0x1
#define PMIC_RG_STRUP_VSRAM_MD_PG_H2L_EN_SHIFT           3
#define PMIC_RG_STRUP_VSRAM_CORE_PG_H2L_EN_MASK          0x1
#define PMIC_RG_STRUP_VSRAM_CORE_PG_H2L_EN_SHIFT         4
#define PMIC_RG_STRUP_VA18_PG_H2L_EN_MASK                0x1
#define PMIC_RG_STRUP_VA18_PG_H2L_EN_SHIFT               5
#define PMIC_RG_STRUP_BUCK_RSV_PG_H2L_EN_MASK            0x1
#define PMIC_RG_STRUP_BUCK_RSV_PG_H2L_EN_SHIFT           6
#define PMIC_RG_STRUP_VDRAM2_PG_H2L_EN_MASK              0x1
#define PMIC_RG_STRUP_VDRAM2_PG_H2L_EN_SHIFT             7
#define PMIC_RG_STRUP_VDRAM1_PG_H2L_EN_MASK              0x1
#define PMIC_RG_STRUP_VDRAM1_PG_H2L_EN_SHIFT             8
#define PMIC_RG_STRUP_VPROC12_PG_H2L_EN_MASK             0x1
#define PMIC_RG_STRUP_VPROC12_PG_H2L_EN_SHIFT            9
#define PMIC_RG_STRUP_VPROC11_PG_H2L_EN_MASK             0x1
#define PMIC_RG_STRUP_VPROC11_PG_H2L_EN_SHIFT            10
#define PMIC_RG_STRUP_VS1_PG_H2L_EN_MASK                 0x1
#define PMIC_RG_STRUP_VS1_PG_H2L_EN_SHIFT                11
#define PMIC_RG_STRUP_VMODEM_PG_H2L_EN_MASK              0x1
#define PMIC_RG_STRUP_VMODEM_PG_H2L_EN_SHIFT             12
#define PMIC_RG_STRUP_VGPU_PG_H2L_EN_MASK                0x1
#define PMIC_RG_STRUP_VGPU_PG_H2L_EN_SHIFT               13
#define PMIC_RG_STRUP_VCORE_PG_H2L_EN_MASK               0x1
#define PMIC_RG_STRUP_VCORE_PG_H2L_EN_SHIFT              14
#define PMIC_RG_STRUP_VS2_PG_H2L_EN_MASK                 0x1
#define PMIC_RG_STRUP_VS2_PG_H2L_EN_SHIFT                15
#define PMIC_RG_STRUP_EXT_PMIC_PG_H2L_EN_MASK            0x1
#define PMIC_RG_STRUP_EXT_PMIC_PG_H2L_EN_SHIFT           11
#define PMIC_RG_STRUP_VUSB33_PG_H2L_EN_MASK              0x1
#define PMIC_RG_STRUP_VUSB33_PG_H2L_EN_SHIFT             12
#define PMIC_RG_STRUP_VSRAM_PROC_PG_H2L_EN_MASK          0x1
#define PMIC_RG_STRUP_VSRAM_PROC_PG_H2L_EN_SHIFT         13
#define PMIC_RG_STRUP_VUFS18_PG_H2L_EN_MASK              0x1
#define PMIC_RG_STRUP_VUFS18_PG_H2L_EN_SHIFT             14
#define PMIC_RG_STRUP_VEMC_PG_H2L_EN_MASK                0x1
#define PMIC_RG_STRUP_VEMC_PG_H2L_EN_SHIFT               15
#define PMIC_RG_STRUP_VA12_PG_ENB_MASK                   0x1
#define PMIC_RG_STRUP_VA12_PG_ENB_SHIFT                  0
#define PMIC_RG_STRUP_VA10_PG_ENB_MASK                   0x1
#define PMIC_RG_STRUP_VA10_PG_ENB_SHIFT                  1
#define PMIC_RG_STRUP_VSRAM_GPU_PG_ENB_MASK              0x1
#define PMIC_RG_STRUP_VSRAM_GPU_PG_ENB_SHIFT             2
#define PMIC_RG_STRUP_VSRAM_MD_PG_ENB_MASK               0x1
#define PMIC_RG_STRUP_VSRAM_MD_PG_ENB_SHIFT              3
#define PMIC_RG_STRUP_VSRAM_CORE_PG_ENB_MASK             0x1
#define PMIC_RG_STRUP_VSRAM_CORE_PG_ENB_SHIFT            4
#define PMIC_RG_STRUP_VA18_PG_ENB_MASK                   0x1
#define PMIC_RG_STRUP_VA18_PG_ENB_SHIFT                  5
#define PMIC_RG_STRUP_BUCK_RSV_PG_ENB_MASK               0x1
#define PMIC_RG_STRUP_BUCK_RSV_PG_ENB_SHIFT              6
#define PMIC_RG_STRUP_VDRAM2_PG_ENB_MASK                 0x1
#define PMIC_RG_STRUP_VDRAM2_PG_ENB_SHIFT                7
#define PMIC_RG_STRUP_VDRAM1_PG_ENB_MASK                 0x1
#define PMIC_RG_STRUP_VDRAM1_PG_ENB_SHIFT                8
#define PMIC_RG_STRUP_VPROC12_PG_ENB_MASK                0x1
#define PMIC_RG_STRUP_VPROC12_PG_ENB_SHIFT               9
#define PMIC_RG_STRUP_VPROC11_PG_ENB_MASK                0x1
#define PMIC_RG_STRUP_VPROC11_PG_ENB_SHIFT               10
#define PMIC_RG_STRUP_VS1_PG_ENB_MASK                    0x1
#define PMIC_RG_STRUP_VS1_PG_ENB_SHIFT                   11
#define PMIC_RG_STRUP_VMODEM_PG_ENB_MASK                 0x1
#define PMIC_RG_STRUP_VMODEM_PG_ENB_SHIFT                12
#define PMIC_RG_STRUP_VGPU_PG_ENB_MASK                   0x1
#define PMIC_RG_STRUP_VGPU_PG_ENB_SHIFT                  13
#define PMIC_RG_STRUP_VCORE_PG_ENB_MASK                  0x1
#define PMIC_RG_STRUP_VCORE_PG_ENB_SHIFT                 14
#define PMIC_RG_STRUP_VS2_PG_ENB_MASK                    0x1
#define PMIC_RG_STRUP_VS2_PG_ENB_SHIFT                   15
#define PMIC_RG_STRUP_EXT_PMIC_PG_ENB_MASK               0x1
#define PMIC_RG_STRUP_EXT_PMIC_PG_ENB_SHIFT              7
#define PMIC_RG_STRUP_VXO18_PG_ENB_MASK                  0x1
#define PMIC_RG_STRUP_VXO18_PG_ENB_SHIFT                 8
#define PMIC_RG_STRUP_VXO22_PG_ENB_MASK                  0x1
#define PMIC_RG_STRUP_VXO22_PG_ENB_SHIFT                 9
#define PMIC_RG_STRUP_VUSB33_PG_ENB_MASK                 0x1
#define PMIC_RG_STRUP_VUSB33_PG_ENB_SHIFT                10
#define PMIC_RG_STRUP_VSRAM_PROC_PG_ENB_MASK             0x1
#define PMIC_RG_STRUP_VSRAM_PROC_PG_ENB_SHIFT            11
#define PMIC_RG_STRUP_VIO28_PG_ENB_MASK                  0x1
#define PMIC_RG_STRUP_VIO28_PG_ENB_SHIFT                 12
#define PMIC_RG_STRUP_VUFS18_PG_ENB_MASK                 0x1
#define PMIC_RG_STRUP_VUFS18_PG_ENB_SHIFT                13
#define PMIC_RG_STRUP_VEMC_PG_ENB_MASK                   0x1
#define PMIC_RG_STRUP_VEMC_PG_ENB_SHIFT                  14
#define PMIC_RG_STRUP_VIO18_PG_ENB_MASK                  0x1
#define PMIC_RG_STRUP_VIO18_PG_ENB_SHIFT                 15
#define PMIC_RG_STRUP_BUCK_RSV_OC_ENB_MASK               0x1
#define PMIC_RG_STRUP_BUCK_RSV_OC_ENB_SHIFT              6
#define PMIC_RG_STRUP_VDRAM2_OC_ENB_MASK                 0x1
#define PMIC_RG_STRUP_VDRAM2_OC_ENB_SHIFT                7
#define PMIC_RG_STRUP_VDRAM1_OC_ENB_MASK                 0x1
#define PMIC_RG_STRUP_VDRAM1_OC_ENB_SHIFT                8
#define PMIC_RG_STRUP_VPROC12_OC_ENB_MASK                0x1
#define PMIC_RG_STRUP_VPROC12_OC_ENB_SHIFT               9
#define PMIC_RG_STRUP_VPROC11_OC_ENB_MASK                0x1
#define PMIC_RG_STRUP_VPROC11_OC_ENB_SHIFT               10
#define PMIC_RG_STRUP_VS1_OC_ENB_MASK                    0x1
#define PMIC_RG_STRUP_VS1_OC_ENB_SHIFT                   11
#define PMIC_RG_STRUP_VMODEM_OC_ENB_MASK                 0x1
#define PMIC_RG_STRUP_VMODEM_OC_ENB_SHIFT                12
#define PMIC_RG_STRUP_VGPU_OC_ENB_MASK                   0x1
#define PMIC_RG_STRUP_VGPU_OC_ENB_SHIFT                  13
#define PMIC_RG_STRUP_VCORE_OC_ENB_MASK                  0x1
#define PMIC_RG_STRUP_VCORE_OC_ENB_SHIFT                 14
#define PMIC_RG_STRUP_VS2_OC_ENB_MASK                    0x1
#define PMIC_RG_STRUP_VS2_OC_ENB_SHIFT                   15
#define PMIC_RG_STRUP_LONG_PRESS_RESET_EXTEND_MASK       0x1
#define PMIC_RG_STRUP_LONG_PRESS_RESET_EXTEND_SHIFT      0
#define PMIC_RG_EXT_PMIC_PG_DEBTD_MASK                   0x1
#define PMIC_RG_EXT_PMIC_PG_DEBTD_SHIFT                  0
#define PMIC_RG_RTC_SPAR_DEB_EN_MASK                     0x1
#define PMIC_RG_RTC_SPAR_DEB_EN_SHIFT                    8
#define PMIC_RG_RTC_ALARM_DEB_EN_MASK                    0x1
#define PMIC_RG_RTC_ALARM_DEB_EN_SHIFT                   9
#define PMIC_RG_TM_OUT_MASK                              0xF
#define PMIC_RG_TM_OUT_SHIFT                             0
#define PMIC_RG_THR_LOC_SEL_MASK                         0xF
#define PMIC_RG_THR_LOC_SEL_SHIFT                        4
#define PMIC_RG_THRDET_SEL_MASK                          0x1
#define PMIC_RG_THRDET_SEL_SHIFT                         8
#define PMIC_RG_STRUP_THR_SEL_MASK                       0x3
#define PMIC_RG_STRUP_THR_SEL_SHIFT                      9
#define PMIC_RG_THR_TMODE_MASK                           0x1
#define PMIC_RG_THR_TMODE_SHIFT                          11
#define PMIC_RG_VREF_BG_MASK                             0x7
#define PMIC_RG_VREF_BG_SHIFT                            12
#define PMIC_RG_STRUP_IREF_TRIM_MASK                     0x3F
#define PMIC_RG_STRUP_IREF_TRIM_SHIFT                    0
#define PMIC_RG_RST_DRVSEL_MASK                          0x1
#define PMIC_RG_RST_DRVSEL_SHIFT                         6
#define PMIC_RG_EN_DRVSEL_MASK                           0x1
#define PMIC_RG_EN_DRVSEL_SHIFT                          7
#define PMIC_RG_PMU_RSV_MASK                             0xF
#define PMIC_RG_PMU_RSV_SHIFT                            8
#define PMIC_RGS_ANA_CHIP_ID_MASK                        0x7
#define PMIC_RGS_ANA_CHIP_ID_SHIFT                       12
#define PMIC_RG_PWRHOLD_MASK                             0x1
#define PMIC_RG_PWRHOLD_SHIFT                            0
#define PMIC_RG_USBDL_MODE_MASK                          0x1
#define PMIC_RG_USBDL_MODE_SHIFT                         4
#define PMIC_RG_CRST_MASK                                0x1
#define PMIC_RG_CRST_SHIFT                               8
#define PMIC_RG_WRST_MASK                                0x1
#define PMIC_RG_WRST_SHIFT                               9
#define PMIC_RG_RSTB_ONINTV_MASK                         0x3
#define PMIC_RG_RSTB_ONINTV_SHIFT                        0
#define PMIC_RG_CRST_INTV_MASK                           0x3
#define PMIC_RG_CRST_INTV_SHIFT                          8
#define PMIC_RG_WRST_INTV_MASK                           0x3
#define PMIC_RG_WRST_INTV_SHIFT                          10
#define PMIC_RG_PSEQ_IVGEN_SEL_MASK                      0x1
#define PMIC_RG_PSEQ_IVGEN_SEL_SHIFT                     0
#define PMIC_RG_PSEQ_FSM_RST_SEL_MASK                    0x1
#define PMIC_RG_PSEQ_FSM_RST_SEL_SHIFT                   4
#define PMIC_RG_PSEQ_PG_CK_SEL_MASK                      0x1
#define PMIC_RG_PSEQ_PG_CK_SEL_SHIFT                     8
#define PMIC_RG_PSEQ_1MS_TK_EXT_MASK                     0x1
#define PMIC_RG_PSEQ_1MS_TK_EXT_SHIFT                    12
#define PMIC_RG_PSEQ_SPAR_XCPT_MASK_MASK                 0x1
#define PMIC_RG_PSEQ_SPAR_XCPT_MASK_SHIFT                13
#define PMIC_RG_PSEQ_RTCA_XCPT_MASK_MASK                 0x1
#define PMIC_RG_PSEQ_RTCA_XCPT_MASK_SHIFT                14
#define PMIC_RG_WDTRST_EN_MASK                           0x1
#define PMIC_RG_WDTRST_EN_SHIFT                          0
#define PMIC_RG_WDTRST_ACT_MASK                          0x3
#define PMIC_RG_WDTRST_ACT_SHIFT                         4
#define PMIC_RG_PSPG_SHDN_EN_MASK                        0x3
#define PMIC_RG_PSPG_SHDN_EN_SHIFT                       8
#define PMIC_RG_THM_SHDN_EN_MASK                         0x1
#define PMIC_RG_THM_SHDN_EN_SHIFT                        12
#define PMIC_RG_KEYPWR_VCORE_OPT_MASK                    0x1
#define PMIC_RG_KEYPWR_VCORE_OPT_SHIFT                   13
#define PMIC_RG_PSEQ_FORCE_ON_MASK                       0x1
#define PMIC_RG_PSEQ_FORCE_ON_SHIFT                      0
#define PMIC_RG_PSEQ_FORCE_ALL_DOFF_MASK                 0x1
#define PMIC_RG_PSEQ_FORCE_ALL_DOFF_SHIFT                8
#define PMIC_RG_PSEQ_F75K_FORCE_MASK                     0x1
#define PMIC_RG_PSEQ_F75K_FORCE_SHIFT                    12
#define PMIC_RG_PSEQ_RSV0_MASK                           0xFF
#define PMIC_RG_PSEQ_RSV0_SHIFT                          0
#define PMIC_RG_PSEQ_RSV1_MASK                           0xF
#define PMIC_RG_PSEQ_RSV1_SHIFT                          8
#define PMIC_RG_PSEQ_RSV2_MASK                           0xF
#define PMIC_RG_PSEQ_RSV2_SHIFT                          12
#define PMIC_RG_BWDT_EN_MASK                             0x1
#define PMIC_RG_BWDT_EN_SHIFT                            0
#define PMIC_RG_BWDT_TSEL_MASK                           0x1
#define PMIC_RG_BWDT_TSEL_SHIFT                          1
#define PMIC_RG_BWDT_CSEL_MASK                           0x1
#define PMIC_RG_BWDT_CSEL_SHIFT                          2
#define PMIC_RG_BWDT_TD_MASK                             0x3
#define PMIC_RG_BWDT_TD_SHIFT                            7
#define PMIC_RG_BWDT_CHRTD_MASK                          0x1
#define PMIC_RG_BWDT_CHRTD_SHIFT                         12
#define PMIC_RG_BWDT_DDLO_TD_MASK                        0x3
#define PMIC_RG_BWDT_DDLO_TD_SHIFT                       13
#define PMIC_RG_BWDT_SRCSEL_MASK                         0x1
#define PMIC_RG_BWDT_SRCSEL_SHIFT                        15
#define PMIC_RG_CPS_W_KEY_MASK                           0xFFFF
#define PMIC_RG_CPS_W_KEY_SHIFT                          0
#define PMIC_RG_SLOT_INTV_UP_MASK                        0x3
#define PMIC_RG_SLOT_INTV_UP_SHIFT                       0
#define PMIC_RG_SEQ_LEN_MASK                             0x1F
#define PMIC_RG_SEQ_LEN_SHIFT                            8
#define PMIC_RG_SLOT_INTV_DOWN_MASK                      0x3
#define PMIC_RG_SLOT_INTV_DOWN_SHIFT                     0
#define PMIC_RG_DSEQ_LEN_MASK                            0x1F
#define PMIC_RG_DSEQ_LEN_SHIFT                           8
#define PMIC_RG_VS2_USA_MASK                             0x1F
#define PMIC_RG_VS2_USA_SHIFT                            0
#define PMIC_RG_VSRAM_CORE_USA_MASK                      0x1F
#define PMIC_RG_VSRAM_CORE_USA_SHIFT                     8
#define PMIC_RG_VSRAM_MD_USA_MASK                        0x1F
#define PMIC_RG_VSRAM_MD_USA_SHIFT                       0
#define PMIC_RG_VSRAM_GPU_USA_MASK                       0x1F
#define PMIC_RG_VSRAM_GPU_USA_SHIFT                      8
#define PMIC_RG_VCORE_USA_MASK                           0x1F
#define PMIC_RG_VCORE_USA_SHIFT                          0
#define PMIC_RG_VGPU_USA_MASK                            0x1F
#define PMIC_RG_VGPU_USA_SHIFT                           8
#define PMIC_RG_VMODEM_USA_MASK                          0x1F
#define PMIC_RG_VMODEM_USA_SHIFT                         0
#define PMIC_RG_VS1_USA_MASK                             0x1F
#define PMIC_RG_VS1_USA_SHIFT                            8
#define PMIC_RG_VA10_USA_MASK                            0x1F
#define PMIC_RG_VA10_USA_SHIFT                           0
#define PMIC_RG_VA12_USA_MASK                            0x1F
#define PMIC_RG_VA12_USA_SHIFT                           8
#define PMIC_RG_VIO18_USA_MASK                           0x1F
#define PMIC_RG_VIO18_USA_SHIFT                          0
#define PMIC_RG_VEMC_USA_MASK                            0x1F
#define PMIC_RG_VEMC_USA_SHIFT                           8
#define PMIC_RG_VUFS18_USA_MASK                          0x1F
#define PMIC_RG_VUFS18_USA_SHIFT                         0
#define PMIC_RG_VIO28_USA_MASK                           0x1F
#define PMIC_RG_VIO28_USA_SHIFT                          8
#define PMIC_RG_VSRAM_PROC_USA_MASK                      0x1F
#define PMIC_RG_VSRAM_PROC_USA_SHIFT                     0
#define PMIC_RG_VPROC11_USA_MASK                         0x1F
#define PMIC_RG_VPROC11_USA_SHIFT                        8
#define PMIC_RG_VPROC12_USA_MASK                         0x1F
#define PMIC_RG_VPROC12_USA_SHIFT                        0
#define PMIC_RG_EXT_PMIC_USA_MASK                        0x1F
#define PMIC_RG_EXT_PMIC_USA_SHIFT                       8
#define PMIC_RG_VDRAM1_USA_MASK                          0x1F
#define PMIC_RG_VDRAM1_USA_SHIFT                         0
#define PMIC_RG_VDRAM2_USA_MASK                          0x1F
#define PMIC_RG_VDRAM2_USA_SHIFT                         8
#define PMIC_RG_VUSB33_USA_MASK                          0x1F
#define PMIC_RG_VUSB33_USA_SHIFT                         0
#define PMIC_RG_VXO22_USA_MASK                           0x1F
#define PMIC_RG_VXO22_USA_SHIFT                          8
#define PMIC_RG_VXO18_USA_MASK                           0x1F
#define PMIC_RG_VXO18_USA_SHIFT                          0
#define PMIC_RG_BUCK_RSV_USA_MASK                        0x1F
#define PMIC_RG_BUCK_RSV_USA_SHIFT                       8
#define PMIC_RG_VS2_DSA_MASK                             0x1F
#define PMIC_RG_VS2_DSA_SHIFT                            0
#define PMIC_RG_VSRAM_CORE_DSA_MASK                      0x1F
#define PMIC_RG_VSRAM_CORE_DSA_SHIFT                     8
#define PMIC_RG_VSRAM_MD_DSA_MASK                        0x1F
#define PMIC_RG_VSRAM_MD_DSA_SHIFT                       0
#define PMIC_RG_VSRAM_GPU_DSA_MASK                       0x1F
#define PMIC_RG_VSRAM_GPU_DSA_SHIFT                      8
#define PMIC_RG_VCORE_DSA_MASK                           0x1F
#define PMIC_RG_VCORE_DSA_SHIFT                          0
#define PMIC_RG_VGPU_DSA_MASK                            0x1F
#define PMIC_RG_VGPU_DSA_SHIFT                           8
#define PMIC_RG_VMODEM_DSA_MASK                          0x1F
#define PMIC_RG_VMODEM_DSA_SHIFT                         0
#define PMIC_RG_VS1_DSA_MASK                             0x1F
#define PMIC_RG_VS1_DSA_SHIFT                            8
#define PMIC_RG_VA10_DSA_MASK                            0x1F
#define PMIC_RG_VA10_DSA_SHIFT                           0
#define PMIC_RG_VA12_DSA_MASK                            0x1F
#define PMIC_RG_VA12_DSA_SHIFT                           8
#define PMIC_RG_VIO18_DSA_MASK                           0x1F
#define PMIC_RG_VIO18_DSA_SHIFT                          0
#define PMIC_RG_VEMC_DSA_MASK                            0x1F
#define PMIC_RG_VEMC_DSA_SHIFT                           8
#define PMIC_RG_VUFS18_DSA_MASK                          0x1F
#define PMIC_RG_VUFS18_DSA_SHIFT                         0
#define PMIC_RG_VIO28_DSA_MASK                           0x1F
#define PMIC_RG_VIO28_DSA_SHIFT                          8
#define PMIC_RG_VSRAM_PROC_DSA_MASK                      0x1F
#define PMIC_RG_VSRAM_PROC_DSA_SHIFT                     0
#define PMIC_RG_VPROC11_DSA_MASK                         0x1F
#define PMIC_RG_VPROC11_DSA_SHIFT                        8
#define PMIC_RG_VPROC12_DSA_MASK                         0x1F
#define PMIC_RG_VPROC12_DSA_SHIFT                        0
#define PMIC_RG_EXT_PMIC_DSA_MASK                        0x1F
#define PMIC_RG_EXT_PMIC_DSA_SHIFT                       8
#define PMIC_RG_VDRAM1_DSA_MASK                          0x1F
#define PMIC_RG_VDRAM1_DSA_SHIFT                         0
#define PMIC_RG_VDRAM2_DSA_MASK                          0x1F
#define PMIC_RG_VDRAM2_DSA_SHIFT                         8
#define PMIC_RG_VUSB33_DSA_MASK                          0x1F
#define PMIC_RG_VUSB33_DSA_SHIFT                         0
#define PMIC_RG_VXO22_DSA_MASK                           0x1F
#define PMIC_RG_VXO22_DSA_SHIFT                          8
#define PMIC_RG_VXO18_DSA_MASK                           0x1F
#define PMIC_RG_VXO18_DSA_SHIFT                          0
#define PMIC_RG_BUCK_RSV_DSA_MASK                        0x1F
#define PMIC_RG_BUCK_RSV_DSA_SHIFT                       8
#define PMIC_RG_POR_FLAG_MASK                            0x1
#define PMIC_RG_POR_FLAG_SHIFT                           0
#define PMIC_STS_PWRKEY_MASK                             0x1
#define PMIC_STS_PWRKEY_SHIFT                            0
#define PMIC_STS_RTCA_MASK                               0x1
#define PMIC_STS_RTCA_SHIFT                              1
#define PMIC_STS_CHRIN_MASK                              0x1
#define PMIC_STS_CHRIN_SHIFT                             2
#define PMIC_STS_SPAR_MASK                               0x1
#define PMIC_STS_SPAR_SHIFT                              3
#define PMIC_STS_RBOOT_MASK                              0x1
#define PMIC_STS_RBOOT_SHIFT                             4
#define PMIC_STS_UVLO_MASK                               0x1
#define PMIC_STS_UVLO_SHIFT                              0
#define PMIC_STS_PGFAIL_MASK                             0x1
#define PMIC_STS_PGFAIL_SHIFT                            1
#define PMIC_STS_PSOC_MASK                               0x1
#define PMIC_STS_PSOC_SHIFT                              2
#define PMIC_STS_THRDN_MASK                              0x1
#define PMIC_STS_THRDN_SHIFT                             3
#define PMIC_STS_WRST_MASK                               0x1
#define PMIC_STS_WRST_SHIFT                              4
#define PMIC_STS_CRST_MASK                               0x1
#define PMIC_STS_CRST_SHIFT                              5
#define PMIC_STS_PKEYLP_MASK                             0x1
#define PMIC_STS_PKEYLP_SHIFT                            6
#define PMIC_STS_NORMOFF_MASK                            0x1
#define PMIC_STS_NORMOFF_SHIFT                           7
#define PMIC_STS_BWDT_MASK                               0x1
#define PMIC_STS_BWDT_SHIFT                              8
#define PMIC_STS_DDLO_MASK                               0x1
#define PMIC_STS_DDLO_SHIFT                              9
#define PMIC_STS_WDT_MASK                                0x1
#define PMIC_STS_WDT_SHIFT                               10
#define PMIC_STS_PUPSRC_MASK                             0x1
#define PMIC_STS_PUPSRC_SHIFT                            11
#define PMIC_STS_KEYPWR_MASK                             0x1
#define PMIC_STS_KEYPWR_SHIFT                            12
#define PMIC_RG_POFFSTS_CLR_MASK                         0x1
#define PMIC_RG_POFFSTS_CLR_SHIFT                        0
#define PMIC_RG_PONSTS_CLR_MASK                          0x1
#define PMIC_RG_PONSTS_CLR_SHIFT                         8
#define PMIC_RG_BUCK_LDO_FT_EN_MASK                      0x1
#define PMIC_RG_BUCK_LDO_FT_EN_SHIFT                     0
#define PMIC_RG_BUCK_DCM_MODE_MASK                       0x1
#define PMIC_RG_BUCK_DCM_MODE_SHIFT                      1
#define PMIC_RG_BUCK_ALL_CON0_RSV_MASK                   0x3FFF
#define PMIC_RG_BUCK_ALL_CON0_RSV_SHIFT                  2
#define PMIC_RG_BUCK_STB_MAX_MASK                        0x1FF
#define PMIC_RG_BUCK_STB_MAX_SHIFT                       0
#define PMIC_RG_BUCK_LP_PROT_DISABLE_MASK                0x1
#define PMIC_RG_BUCK_LP_PROT_DISABLE_SHIFT               9
#define PMIC_RG_BUCK_VSLEEP_SRC0_MASK                    0x1FF
#define PMIC_RG_BUCK_VSLEEP_SRC0_SHIFT                   0
#define PMIC_RG_BUCK_VSLEEP_SRC1_MASK                    0xF
#define PMIC_RG_BUCK_VSLEEP_SRC1_SHIFT                   12
#define PMIC_RG_BUCK_R2R_SRC0_MASK                       0x1FF
#define PMIC_RG_BUCK_R2R_SRC0_SHIFT                      0
#define PMIC_RG_BUCK_R2R_SRC1_MASK                       0xF
#define PMIC_RG_BUCK_R2R_SRC1_SHIFT                      12
#define PMIC_RG_BUCK_LP_SEQ_COUNT_MASK                   0x1FF
#define PMIC_RG_BUCK_LP_SEQ_COUNT_SHIFT                  0
#define PMIC_RG_BUCK_ON_SEQ_COUNT_MASK                   0xF
#define PMIC_RG_BUCK_ON_SEQ_COUNT_SHIFT                  12
#define PMIC_RG_BUCK_MINFREQ_LATENCY_MAX_MASK            0x3F
#define PMIC_RG_BUCK_MINFREQ_LATENCY_MAX_SHIFT           0
#define PMIC_RG_BUCK_MINFREQ_DURATION_MAX_MASK           0x7
#define PMIC_RG_BUCK_MINFREQ_DURATION_MAX_SHIFT          8
#define PMIC_RG_BUCK_VPROC11_OC_SDN_STATUS_MASK          0x1
#define PMIC_RG_BUCK_VPROC11_OC_SDN_STATUS_SHIFT         0
#define PMIC_RG_BUCK_VPROC12_OC_SDN_STATUS_MASK          0x1
#define PMIC_RG_BUCK_VPROC12_OC_SDN_STATUS_SHIFT         1
#define PMIC_RG_BUCK_VCORE_OC_SDN_STATUS_MASK            0x1
#define PMIC_RG_BUCK_VCORE_OC_SDN_STATUS_SHIFT           2
#define PMIC_RG_BUCK_VGPU_OC_SDN_STATUS_MASK             0x1
#define PMIC_RG_BUCK_VGPU_OC_SDN_STATUS_SHIFT            3
#define PMIC_RG_BUCK_VDRAM1_OC_SDN_STATUS_MASK           0x1
#define PMIC_RG_BUCK_VDRAM1_OC_SDN_STATUS_SHIFT          4
#define PMIC_RG_BUCK_VDRAM2_OC_SDN_STATUS_MASK           0x1
#define PMIC_RG_BUCK_VDRAM2_OC_SDN_STATUS_SHIFT          5
#define PMIC_RG_BUCK_VMODEM_OC_SDN_STATUS_MASK           0x1
#define PMIC_RG_BUCK_VMODEM_OC_SDN_STATUS_SHIFT          6
#define PMIC_RG_BUCK_VS1_OC_SDN_STATUS_MASK              0x1
#define PMIC_RG_BUCK_VS1_OC_SDN_STATUS_SHIFT             7
#define PMIC_RG_BUCK_VS2_OC_SDN_STATUS_MASK              0x1
#define PMIC_RG_BUCK_VS2_OC_SDN_STATUS_SHIFT             8
#define PMIC_RG_BUCK_VPA_OC_SDN_STATUS_MASK              0x1
#define PMIC_RG_BUCK_VPA_OC_SDN_STATUS_SHIFT             9
#define PMIC_RG_BUCK_VPROC11_OC_SDN_EN_MASK              0x1
#define PMIC_RG_BUCK_VPROC11_OC_SDN_EN_SHIFT             0
#define PMIC_RG_BUCK_VPROC12_OC_SDN_EN_MASK              0x1
#define PMIC_RG_BUCK_VPROC12_OC_SDN_EN_SHIFT             1
#define PMIC_RG_BUCK_VCORE_OC_SDN_EN_MASK                0x1
#define PMIC_RG_BUCK_VCORE_OC_SDN_EN_SHIFT               2
#define PMIC_RG_BUCK_VGPU_OC_SDN_EN_MASK                 0x1
#define PMIC_RG_BUCK_VGPU_OC_SDN_EN_SHIFT                3
#define PMIC_RG_BUCK_VDRAM1_OC_SDN_EN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM1_OC_SDN_EN_SHIFT              4
#define PMIC_RG_BUCK_VDRAM2_OC_SDN_EN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM2_OC_SDN_EN_SHIFT              5
#define PMIC_RG_BUCK_VMODEM_OC_SDN_EN_MASK               0x1
#define PMIC_RG_BUCK_VMODEM_OC_SDN_EN_SHIFT              6
#define PMIC_RG_BUCK_VS1_OC_SDN_EN_MASK                  0x1
#define PMIC_RG_BUCK_VS1_OC_SDN_EN_SHIFT                 7
#define PMIC_RG_BUCK_VS2_OC_SDN_EN_MASK                  0x1
#define PMIC_RG_BUCK_VS2_OC_SDN_EN_SHIFT                 8
#define PMIC_RG_BUCK_VPA_OC_SDN_EN_MASK                  0x1
#define PMIC_RG_BUCK_VPA_OC_SDN_EN_SHIFT                 9
#define PMIC_RG_BUCK_K_RST_DONE_MASK                     0x1
#define PMIC_RG_BUCK_K_RST_DONE_SHIFT                    0
#define PMIC_RG_BUCK_K_MAP_SEL_MASK                      0x1
#define PMIC_RG_BUCK_K_MAP_SEL_SHIFT                     1
#define PMIC_RG_BUCK_K_ONCE_EN_MASK                      0x1
#define PMIC_RG_BUCK_K_ONCE_EN_SHIFT                     2
#define PMIC_RG_BUCK_K_ONCE_MASK                         0x1
#define PMIC_RG_BUCK_K_ONCE_SHIFT                        3
#define PMIC_RG_BUCK_K_START_MANUAL_MASK                 0x1
#define PMIC_RG_BUCK_K_START_MANUAL_SHIFT                4
#define PMIC_RG_BUCK_K_SRC_SEL_MASK                      0x1
#define PMIC_RG_BUCK_K_SRC_SEL_SHIFT                     5
#define PMIC_RG_BUCK_K_AUTO_EN_MASK                      0x1
#define PMIC_RG_BUCK_K_AUTO_EN_SHIFT                     6
#define PMIC_RG_BUCK_K_INV_MASK                          0x1
#define PMIC_RG_BUCK_K_INV_SHIFT                         7
#define PMIC_RG_BUCK_K_CK_EN_MASK                        0x1
#define PMIC_RG_BUCK_K_CK_EN_SHIFT                       8
#define PMIC_RG_BUCK_K_CONTROL_SMPS_MASK                 0x3F
#define PMIC_RG_BUCK_K_CONTROL_SMPS_SHIFT                8
#define PMIC_BUCK_K_RESULT_MASK                          0x1
#define PMIC_BUCK_K_RESULT_SHIFT                         0
#define PMIC_BUCK_K_DONE_MASK                            0x1
#define PMIC_BUCK_K_DONE_SHIFT                           1
#define PMIC_BUCK_K_CONTROL_MASK                         0x3F
#define PMIC_BUCK_K_CONTROL_SHIFT                        2
#define PMIC_DA_QI_SMPS_OSC_CAL_MASK                     0x3F
#define PMIC_DA_QI_SMPS_OSC_CAL_SHIFT                    8
#define PMIC_RG_BUCK_K_BUCK_CK_CNT_MASK                  0x3FF
#define PMIC_RG_BUCK_K_BUCK_CK_CNT_SHIFT                 0
#define PMIC_RG_VOW_BUCK_VCORE_DVS_DONE_MASK             0x1
#define PMIC_RG_VOW_BUCK_VCORE_DVS_DONE_SHIFT            0
#define PMIC_RG_VOW_LDO_VSRAM_CORE_DVS_DONE_MASK         0x1
#define PMIC_RG_VOW_LDO_VSRAM_CORE_DVS_DONE_SHIFT        1
#define PMIC_RG_VOW_BUCK_VCORE_DVS_SW_MODE_MASK          0x1
#define PMIC_RG_VOW_BUCK_VCORE_DVS_SW_MODE_SHIFT         8
#define PMIC_RG_VOW_LDO_VSRAM_CORE_DVS_SW_MODE_MASK      0x1
#define PMIC_RG_VOW_LDO_VSRAM_CORE_DVS_SW_MODE_SHIFT     9
#define PMIC_VOW_BUCK_VCORE_DVS_DONE_MASK                0x1
#define PMIC_VOW_BUCK_VCORE_DVS_DONE_SHIFT               13
#define PMIC_VOW_LDO_VSRAM_CORE_DVS_DONE_MASK            0x1
#define PMIC_VOW_LDO_VSRAM_CORE_DVS_DONE_SHIFT           14
#define PMIC_VOW_DVS_DONE_MASK                           0x1
#define PMIC_VOW_DVS_DONE_SHIFT                          15
#define PMIC_RG_BUCK_VPROC11_EN_MASK                     0x1
#define PMIC_RG_BUCK_VPROC11_EN_SHIFT                    0
#define PMIC_RG_BUCK_VPROC11_LP_MASK                     0x1
#define PMIC_RG_BUCK_VPROC11_LP_SHIFT                    1
#define PMIC_RG_BUCK_VPROC11_VOSEL_MASK                  0x7F
#define PMIC_RG_BUCK_VPROC11_VOSEL_SHIFT                 0
#define PMIC_RG_BUCK_VPROC11_VOSEL_SLEEP_MASK            0x7F
#define PMIC_RG_BUCK_VPROC11_VOSEL_SLEEP_SHIFT           0
#define PMIC_RG_BUCK_VPROC11_SFCHG_FRATE_MASK            0x7F
#define PMIC_RG_BUCK_VPROC11_SFCHG_FRATE_SHIFT           0
#define PMIC_RG_BUCK_VPROC11_SFCHG_FEN_MASK              0x1
#define PMIC_RG_BUCK_VPROC11_SFCHG_FEN_SHIFT             7
#define PMIC_RG_BUCK_VPROC11_SFCHG_RRATE_MASK            0x7F
#define PMIC_RG_BUCK_VPROC11_SFCHG_RRATE_SHIFT           8
#define PMIC_RG_BUCK_VPROC11_SFCHG_REN_MASK              0x1
#define PMIC_RG_BUCK_VPROC11_SFCHG_REN_SHIFT             15
#define PMIC_RG_BUCK_VPROC11_DVS_EN_TD_MASK              0x3
#define PMIC_RG_BUCK_VPROC11_DVS_EN_TD_SHIFT             0
#define PMIC_RG_BUCK_VPROC11_DVS_EN_CTRL_MASK            0x3
#define PMIC_RG_BUCK_VPROC11_DVS_EN_CTRL_SHIFT           4
#define PMIC_RG_BUCK_VPROC11_DVS_EN_ONCE_MASK            0x1
#define PMIC_RG_BUCK_VPROC11_DVS_EN_ONCE_SHIFT           6
#define PMIC_RG_BUCK_VPROC11_DVS_DOWN_TD_MASK            0x3
#define PMIC_RG_BUCK_VPROC11_DVS_DOWN_TD_SHIFT           8
#define PMIC_RG_BUCK_VPROC11_DVS_DOWN_CTRL_MASK          0x3
#define PMIC_RG_BUCK_VPROC11_DVS_DOWN_CTRL_SHIFT         12
#define PMIC_RG_BUCK_VPROC11_DVS_DOWN_ONCE_MASK          0x1
#define PMIC_RG_BUCK_VPROC11_DVS_DOWN_ONCE_SHIFT         14
#define PMIC_RG_BUCK_VPROC11_SW_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VPROC11_SW_OP_EN_SHIFT              0
#define PMIC_RG_BUCK_VPROC11_HW0_OP_EN_MASK              0x1
#define PMIC_RG_BUCK_VPROC11_HW0_OP_EN_SHIFT             1
#define PMIC_RG_BUCK_VPROC11_HW1_OP_EN_MASK              0x1
#define PMIC_RG_BUCK_VPROC11_HW1_OP_EN_SHIFT             2
#define PMIC_RG_BUCK_VPROC11_HW2_OP_EN_MASK              0x1
#define PMIC_RG_BUCK_VPROC11_HW2_OP_EN_SHIFT             3
#define PMIC_RG_BUCK_VPROC11_OP_EN_SET_MASK              0xFFFF
#define PMIC_RG_BUCK_VPROC11_OP_EN_SET_SHIFT             0
#define PMIC_RG_BUCK_VPROC11_OP_EN_CLR_MASK              0xFFFF
#define PMIC_RG_BUCK_VPROC11_OP_EN_CLR_SHIFT             0
#define PMIC_RG_BUCK_VPROC11_HW0_OP_CFG_MASK             0x1
#define PMIC_RG_BUCK_VPROC11_HW0_OP_CFG_SHIFT            1
#define PMIC_RG_BUCK_VPROC11_HW1_OP_CFG_MASK             0x1
#define PMIC_RG_BUCK_VPROC11_HW1_OP_CFG_SHIFT            2
#define PMIC_RG_BUCK_VPROC11_HW2_OP_CFG_MASK             0x1
#define PMIC_RG_BUCK_VPROC11_HW2_OP_CFG_SHIFT            3
#define PMIC_RG_BUCK_VPROC11_ON_OP_MASK                  0x1
#define PMIC_RG_BUCK_VPROC11_ON_OP_SHIFT                 8
#define PMIC_RG_BUCK_VPROC11_LP_OP_MASK                  0x1
#define PMIC_RG_BUCK_VPROC11_LP_OP_SHIFT                 9
#define PMIC_RG_BUCK_VPROC11_OP_CFG_SET_MASK             0xFFFF
#define PMIC_RG_BUCK_VPROC11_OP_CFG_SET_SHIFT            0
#define PMIC_RG_BUCK_VPROC11_OP_CFG_CLR_MASK             0xFFFF
#define PMIC_RG_BUCK_VPROC11_OP_CFG_CLR_SHIFT            0
#define PMIC_RG_BUCK_VPROC11_SP_SW_VOSEL_MASK            0x7F
#define PMIC_RG_BUCK_VPROC11_SP_SW_VOSEL_SHIFT           0
#define PMIC_RG_BUCK_VPROC11_SP_SW_VOSEL_EN_MASK         0x1
#define PMIC_RG_BUCK_VPROC11_SP_SW_VOSEL_EN_SHIFT        0
#define PMIC_RG_BUCK_VPROC11_SP_ON_VOSEL_MUX_SEL_MASK    0x1
#define PMIC_RG_BUCK_VPROC11_SP_ON_VOSEL_MUX_SEL_SHIFT   1
#define PMIC_RG_BUCK_VPROC11_OC_DEG_EN_MASK              0x1
#define PMIC_RG_BUCK_VPROC11_OC_DEG_EN_SHIFT             1
#define PMIC_RG_BUCK_VPROC11_OC_WND_MASK                 0x3
#define PMIC_RG_BUCK_VPROC11_OC_WND_SHIFT                2
#define PMIC_RG_BUCK_VPROC11_OC_THD_MASK                 0x3
#define PMIC_RG_BUCK_VPROC11_OC_THD_SHIFT                6
#define PMIC_DA_VPROC11_VOSEL_MASK                       0x7F
#define PMIC_DA_VPROC11_VOSEL_SHIFT                      0
#define PMIC_DA_VPROC11_VOSEL_GRAY_MASK                  0x7F
#define PMIC_DA_VPROC11_VOSEL_GRAY_SHIFT                 8
#define PMIC_DA_VPROC11_EN_MASK                          0x1
#define PMIC_DA_VPROC11_EN_SHIFT                         0
#define PMIC_DA_VPROC11_STB_MASK                         0x1
#define PMIC_DA_VPROC11_STB_SHIFT                        1
#define PMIC_DA_VPROC11_VSLEEP_SEL_MASK                  0x1
#define PMIC_DA_VPROC11_VSLEEP_SEL_SHIFT                 2
#define PMIC_DA_VPROC11_R2R_PDN_MASK                     0x1
#define PMIC_DA_VPROC11_R2R_PDN_SHIFT                    3
#define PMIC_DA_VPROC11_DVS_EN_MASK                      0x1
#define PMIC_DA_VPROC11_DVS_EN_SHIFT                     4
#define PMIC_DA_VPROC11_DVS_DOWN_MASK                    0x1
#define PMIC_DA_VPROC11_DVS_DOWN_SHIFT                   5
#define PMIC_DA_VPROC11_SSH_MASK                         0x1
#define PMIC_DA_VPROC11_SSH_SHIFT                        6
#define PMIC_DA_VPROC11_MINFREQ_DISCHARGE_MASK           0x1
#define PMIC_DA_VPROC11_MINFREQ_DISCHARGE_SHIFT          8
#define PMIC_RG_BUCK_VPROC11_OC_FLAG_CLR_SEL_MASK        0x1
#define PMIC_RG_BUCK_VPROC11_OC_FLAG_CLR_SEL_SHIFT       4
#define PMIC_RG_BUCK_VPROC11_OSC_SEL_DIS_MASK            0x1
#define PMIC_RG_BUCK_VPROC11_OSC_SEL_DIS_SHIFT           5
#define PMIC_RG_BUCK_VPROC11_CK_SW_MODE_MASK             0x1
#define PMIC_RG_BUCK_VPROC11_CK_SW_MODE_SHIFT            6
#define PMIC_RG_BUCK_VPROC11_CK_SW_EN_MASK               0x1
#define PMIC_RG_BUCK_VPROC11_CK_SW_EN_SHIFT              7
#define PMIC_RG_BUCK_VPROC12_EN_MASK                     0x1
#define PMIC_RG_BUCK_VPROC12_EN_SHIFT                    0
#define PMIC_RG_BUCK_VPROC12_LP_MASK                     0x1
#define PMIC_RG_BUCK_VPROC12_LP_SHIFT                    1
#define PMIC_RG_BUCK_VPROC12_VOSEL_MASK                  0x7F
#define PMIC_RG_BUCK_VPROC12_VOSEL_SHIFT                 0
#define PMIC_RG_BUCK_VPROC12_VOSEL_SLEEP_MASK            0x7F
#define PMIC_RG_BUCK_VPROC12_VOSEL_SLEEP_SHIFT           0
#define PMIC_RG_BUCK_VPROC12_SFCHG_FRATE_MASK            0x7F
#define PMIC_RG_BUCK_VPROC12_SFCHG_FRATE_SHIFT           0
#define PMIC_RG_BUCK_VPROC12_SFCHG_FEN_MASK              0x1
#define PMIC_RG_BUCK_VPROC12_SFCHG_FEN_SHIFT             7
#define PMIC_RG_BUCK_VPROC12_SFCHG_RRATE_MASK            0x7F
#define PMIC_RG_BUCK_VPROC12_SFCHG_RRATE_SHIFT           8
#define PMIC_RG_BUCK_VPROC12_SFCHG_REN_MASK              0x1
#define PMIC_RG_BUCK_VPROC12_SFCHG_REN_SHIFT             15
#define PMIC_RG_BUCK_VPROC12_DVS_EN_TD_MASK              0x3
#define PMIC_RG_BUCK_VPROC12_DVS_EN_TD_SHIFT             0
#define PMIC_RG_BUCK_VPROC12_DVS_EN_CTRL_MASK            0x3
#define PMIC_RG_BUCK_VPROC12_DVS_EN_CTRL_SHIFT           4
#define PMIC_RG_BUCK_VPROC12_DVS_EN_ONCE_MASK            0x1
#define PMIC_RG_BUCK_VPROC12_DVS_EN_ONCE_SHIFT           6
#define PMIC_RG_BUCK_VPROC12_DVS_DOWN_TD_MASK            0x3
#define PMIC_RG_BUCK_VPROC12_DVS_DOWN_TD_SHIFT           8
#define PMIC_RG_BUCK_VPROC12_DVS_DOWN_CTRL_MASK          0x3
#define PMIC_RG_BUCK_VPROC12_DVS_DOWN_CTRL_SHIFT         12
#define PMIC_RG_BUCK_VPROC12_DVS_DOWN_ONCE_MASK          0x1
#define PMIC_RG_BUCK_VPROC12_DVS_DOWN_ONCE_SHIFT         14
#define PMIC_RG_BUCK_VPROC12_SW_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VPROC12_SW_OP_EN_SHIFT              0
#define PMIC_RG_BUCK_VPROC12_HW0_OP_EN_MASK              0x1
#define PMIC_RG_BUCK_VPROC12_HW0_OP_EN_SHIFT             1
#define PMIC_RG_BUCK_VPROC12_HW1_OP_EN_MASK              0x1
#define PMIC_RG_BUCK_VPROC12_HW1_OP_EN_SHIFT             2
#define PMIC_RG_BUCK_VPROC12_HW2_OP_EN_MASK              0x1
#define PMIC_RG_BUCK_VPROC12_HW2_OP_EN_SHIFT             3
#define PMIC_RG_BUCK_VPROC12_OP_EN_SET_MASK              0xFFFF
#define PMIC_RG_BUCK_VPROC12_OP_EN_SET_SHIFT             0
#define PMIC_RG_BUCK_VPROC12_OP_EN_CLR_MASK              0xFFFF
#define PMIC_RG_BUCK_VPROC12_OP_EN_CLR_SHIFT             0
#define PMIC_RG_BUCK_VPROC12_HW0_OP_CFG_MASK             0x1
#define PMIC_RG_BUCK_VPROC12_HW0_OP_CFG_SHIFT            1
#define PMIC_RG_BUCK_VPROC12_HW1_OP_CFG_MASK             0x1
#define PMIC_RG_BUCK_VPROC12_HW1_OP_CFG_SHIFT            2
#define PMIC_RG_BUCK_VPROC12_HW2_OP_CFG_MASK             0x1
#define PMIC_RG_BUCK_VPROC12_HW2_OP_CFG_SHIFT            3
#define PMIC_RG_BUCK_VPROC12_ON_OP_MASK                  0x1
#define PMIC_RG_BUCK_VPROC12_ON_OP_SHIFT                 8
#define PMIC_RG_BUCK_VPROC12_LP_OP_MASK                  0x1
#define PMIC_RG_BUCK_VPROC12_LP_OP_SHIFT                 9
#define PMIC_RG_BUCK_VPROC12_OP_CFG_SET_MASK             0xFFFF
#define PMIC_RG_BUCK_VPROC12_OP_CFG_SET_SHIFT            0
#define PMIC_RG_BUCK_VPROC12_OP_CFG_CLR_MASK             0xFFFF
#define PMIC_RG_BUCK_VPROC12_OP_CFG_CLR_SHIFT            0
#define PMIC_RG_BUCK_VPROC12_SP_SW_VOSEL_MASK            0x7F
#define PMIC_RG_BUCK_VPROC12_SP_SW_VOSEL_SHIFT           0
#define PMIC_RG_BUCK_VPROC12_SP_SW_VOSEL_EN_MASK         0x1
#define PMIC_RG_BUCK_VPROC12_SP_SW_VOSEL_EN_SHIFT        0
#define PMIC_RG_BUCK_VPROC12_SP_ON_VOSEL_MUX_SEL_MASK    0x1
#define PMIC_RG_BUCK_VPROC12_SP_ON_VOSEL_MUX_SEL_SHIFT   1
#define PMIC_RG_BUCK_VPROC12_OC_DEG_EN_MASK              0x1
#define PMIC_RG_BUCK_VPROC12_OC_DEG_EN_SHIFT             1
#define PMIC_RG_BUCK_VPROC12_OC_WND_MASK                 0x3
#define PMIC_RG_BUCK_VPROC12_OC_WND_SHIFT                2
#define PMIC_RG_BUCK_VPROC12_OC_THD_MASK                 0x3
#define PMIC_RG_BUCK_VPROC12_OC_THD_SHIFT                6
#define PMIC_DA_VPROC12_VOSEL_MASK                       0x7F
#define PMIC_DA_VPROC12_VOSEL_SHIFT                      0
#define PMIC_DA_VPROC12_VOSEL_GRAY_MASK                  0x7F
#define PMIC_DA_VPROC12_VOSEL_GRAY_SHIFT                 8
#define PMIC_DA_VPROC12_EN_MASK                          0x1
#define PMIC_DA_VPROC12_EN_SHIFT                         0
#define PMIC_DA_VPROC12_STB_MASK                         0x1
#define PMIC_DA_VPROC12_STB_SHIFT                        1
#define PMIC_DA_VPROC12_VSLEEP_SEL_MASK                  0x1
#define PMIC_DA_VPROC12_VSLEEP_SEL_SHIFT                 2
#define PMIC_DA_VPROC12_R2R_PDN_MASK                     0x1
#define PMIC_DA_VPROC12_R2R_PDN_SHIFT                    3
#define PMIC_DA_VPROC12_DVS_EN_MASK                      0x1
#define PMIC_DA_VPROC12_DVS_EN_SHIFT                     4
#define PMIC_DA_VPROC12_DVS_DOWN_MASK                    0x1
#define PMIC_DA_VPROC12_DVS_DOWN_SHIFT                   5
#define PMIC_DA_VPROC12_SSH_MASK                         0x1
#define PMIC_DA_VPROC12_SSH_SHIFT                        6
#define PMIC_DA_VPROC12_MINFREQ_DISCHARGE_MASK           0x1
#define PMIC_DA_VPROC12_MINFREQ_DISCHARGE_SHIFT          8
#define PMIC_RG_BUCK_VPROC12_OC_FLAG_CLR_SEL_MASK        0x1
#define PMIC_RG_BUCK_VPROC12_OC_FLAG_CLR_SEL_SHIFT       4
#define PMIC_RG_BUCK_VPROC12_OSC_SEL_DIS_MASK            0x1
#define PMIC_RG_BUCK_VPROC12_OSC_SEL_DIS_SHIFT           5
#define PMIC_RG_BUCK_VPROC12_CK_SW_MODE_MASK             0x1
#define PMIC_RG_BUCK_VPROC12_CK_SW_MODE_SHIFT            6
#define PMIC_RG_BUCK_VPROC12_CK_SW_EN_MASK               0x1
#define PMIC_RG_BUCK_VPROC12_CK_SW_EN_SHIFT              7
#define PMIC_RG_BUCK_VCORE_EN_MASK                       0x1
#define PMIC_RG_BUCK_VCORE_EN_SHIFT                      0
#define PMIC_RG_BUCK_VCORE_LP_MASK                       0x1
#define PMIC_RG_BUCK_VCORE_LP_SHIFT                      1
#define PMIC_RG_BUCK_VCORE_VOSEL_MASK                    0x7F
#define PMIC_RG_BUCK_VCORE_VOSEL_SHIFT                   0
#define PMIC_RG_BUCK_VCORE_VOSEL_SLEEP_MASK              0x7F
#define PMIC_RG_BUCK_VCORE_VOSEL_SLEEP_SHIFT             0
#define PMIC_RG_BUCK_VCORE_SFCHG_FRATE_MASK              0x7F
#define PMIC_RG_BUCK_VCORE_SFCHG_FRATE_SHIFT             0
#define PMIC_RG_BUCK_VCORE_SFCHG_FEN_MASK                0x1
#define PMIC_RG_BUCK_VCORE_SFCHG_FEN_SHIFT               7
#define PMIC_RG_BUCK_VCORE_SFCHG_RRATE_MASK              0x7F
#define PMIC_RG_BUCK_VCORE_SFCHG_RRATE_SHIFT             8
#define PMIC_RG_BUCK_VCORE_SFCHG_REN_MASK                0x1
#define PMIC_RG_BUCK_VCORE_SFCHG_REN_SHIFT               15
#define PMIC_RG_BUCK_VCORE_DVS_EN_TD_MASK                0x3
#define PMIC_RG_BUCK_VCORE_DVS_EN_TD_SHIFT               0
#define PMIC_RG_BUCK_VCORE_DVS_EN_CTRL_MASK              0x3
#define PMIC_RG_BUCK_VCORE_DVS_EN_CTRL_SHIFT             4
#define PMIC_RG_BUCK_VCORE_DVS_EN_ONCE_MASK              0x1
#define PMIC_RG_BUCK_VCORE_DVS_EN_ONCE_SHIFT             6
#define PMIC_RG_BUCK_VCORE_DVS_DOWN_TD_MASK              0x3
#define PMIC_RG_BUCK_VCORE_DVS_DOWN_TD_SHIFT             8
#define PMIC_RG_BUCK_VCORE_DVS_DOWN_CTRL_MASK            0x3
#define PMIC_RG_BUCK_VCORE_DVS_DOWN_CTRL_SHIFT           12
#define PMIC_RG_BUCK_VCORE_DVS_DOWN_ONCE_MASK            0x1
#define PMIC_RG_BUCK_VCORE_DVS_DOWN_ONCE_SHIFT           14
#define PMIC_RG_BUCK_VCORE_SW_OP_EN_MASK                 0x1
#define PMIC_RG_BUCK_VCORE_SW_OP_EN_SHIFT                0
#define PMIC_RG_BUCK_VCORE_HW0_OP_EN_MASK                0x1
#define PMIC_RG_BUCK_VCORE_HW0_OP_EN_SHIFT               1
#define PMIC_RG_BUCK_VCORE_HW1_OP_EN_MASK                0x1
#define PMIC_RG_BUCK_VCORE_HW1_OP_EN_SHIFT               2
#define PMIC_RG_BUCK_VCORE_HW2_OP_EN_MASK                0x1
#define PMIC_RG_BUCK_VCORE_HW2_OP_EN_SHIFT               3
#define PMIC_RG_BUCK_VCORE_OP_EN_SET_MASK                0xFFFF
#define PMIC_RG_BUCK_VCORE_OP_EN_SET_SHIFT               0
#define PMIC_RG_BUCK_VCORE_OP_EN_CLR_MASK                0xFFFF
#define PMIC_RG_BUCK_VCORE_OP_EN_CLR_SHIFT               0
#define PMIC_RG_BUCK_VCORE_HW0_OP_CFG_MASK               0x1
#define PMIC_RG_BUCK_VCORE_HW0_OP_CFG_SHIFT              1
#define PMIC_RG_BUCK_VCORE_HW1_OP_CFG_MASK               0x1
#define PMIC_RG_BUCK_VCORE_HW1_OP_CFG_SHIFT              2
#define PMIC_RG_BUCK_VCORE_HW2_OP_CFG_MASK               0x1
#define PMIC_RG_BUCK_VCORE_HW2_OP_CFG_SHIFT              3
#define PMIC_RG_BUCK_VCORE_ON_OP_MASK                    0x1
#define PMIC_RG_BUCK_VCORE_ON_OP_SHIFT                   8
#define PMIC_RG_BUCK_VCORE_LP_OP_MASK                    0x1
#define PMIC_RG_BUCK_VCORE_LP_OP_SHIFT                   9
#define PMIC_RG_BUCK_VCORE_OP_CFG_SET_MASK               0xFFFF
#define PMIC_RG_BUCK_VCORE_OP_CFG_SET_SHIFT              0
#define PMIC_RG_BUCK_VCORE_OP_CFG_CLR_MASK               0xFFFF
#define PMIC_RG_BUCK_VCORE_OP_CFG_CLR_SHIFT              0
#define PMIC_RG_BUCK_VCORE_SP_SW_VOSEL_MASK              0x7F
#define PMIC_RG_BUCK_VCORE_SP_SW_VOSEL_SHIFT             0
#define PMIC_RG_BUCK_VCORE_SP_SW_VOSEL_EN_MASK           0x1
#define PMIC_RG_BUCK_VCORE_SP_SW_VOSEL_EN_SHIFT          0
#define PMIC_RG_BUCK_VCORE_SP_ON_VOSEL_MUX_SEL_MASK      0x1
#define PMIC_RG_BUCK_VCORE_SP_ON_VOSEL_MUX_SEL_SHIFT     1
#define PMIC_RG_BUCK_VCORE_OC_DEG_EN_MASK                0x1
#define PMIC_RG_BUCK_VCORE_OC_DEG_EN_SHIFT               1
#define PMIC_RG_BUCK_VCORE_OC_WND_MASK                   0x3
#define PMIC_RG_BUCK_VCORE_OC_WND_SHIFT                  2
#define PMIC_RG_BUCK_VCORE_OC_THD_MASK                   0x3
#define PMIC_RG_BUCK_VCORE_OC_THD_SHIFT                  6
#define PMIC_DA_VCORE_VOSEL_MASK                         0x7F
#define PMIC_DA_VCORE_VOSEL_SHIFT                        0
#define PMIC_DA_VCORE_VOSEL_GRAY_MASK                    0x7F
#define PMIC_DA_VCORE_VOSEL_GRAY_SHIFT                   8
#define PMIC_DA_VCORE_EN_MASK                            0x1
#define PMIC_DA_VCORE_EN_SHIFT                           0
#define PMIC_DA_VCORE_STB_MASK                           0x1
#define PMIC_DA_VCORE_STB_SHIFT                          1
#define PMIC_DA_VCORE_VSLEEP_SEL_MASK                    0x1
#define PMIC_DA_VCORE_VSLEEP_SEL_SHIFT                   2
#define PMIC_DA_VCORE_R2R_PDN_MASK                       0x1
#define PMIC_DA_VCORE_R2R_PDN_SHIFT                      3
#define PMIC_DA_VCORE_DVS_EN_MASK                        0x1
#define PMIC_DA_VCORE_DVS_EN_SHIFT                       4
#define PMIC_DA_VCORE_DVS_DOWN_MASK                      0x1
#define PMIC_DA_VCORE_DVS_DOWN_SHIFT                     5
#define PMIC_DA_VCORE_SSH_MASK                           0x1
#define PMIC_DA_VCORE_SSH_SHIFT                          6
#define PMIC_DA_VCORE_MINFREQ_DISCHARGE_MASK             0x1
#define PMIC_DA_VCORE_MINFREQ_DISCHARGE_SHIFT            8
#define PMIC_RG_BUCK_VCORE_OC_FLAG_CLR_SEL_MASK          0x1
#define PMIC_RG_BUCK_VCORE_OC_FLAG_CLR_SEL_SHIFT         4
#define PMIC_RG_BUCK_VCORE_OSC_SEL_DIS_MASK              0x1
#define PMIC_RG_BUCK_VCORE_OSC_SEL_DIS_SHIFT             5
#define PMIC_RG_BUCK_VCORE_CK_SW_MODE_MASK               0x1
#define PMIC_RG_BUCK_VCORE_CK_SW_MODE_SHIFT              6
#define PMIC_RG_BUCK_VCORE_CK_SW_EN_MASK                 0x1
#define PMIC_RG_BUCK_VCORE_CK_SW_EN_SHIFT                7
#define PMIC_RG_BUCK_VCORE_SSHUB_MODE_MASK               0x1
#define PMIC_RG_BUCK_VCORE_SSHUB_MODE_SHIFT              0
#define PMIC_RG_BUCK_VCORE_SSHUB_ON_MASK                 0x1
#define PMIC_RG_BUCK_VCORE_SSHUB_ON_SHIFT                1
#define PMIC_RG_BUCK_VCORE_SSHUB_VOSEL_MASK              0x7F
#define PMIC_RG_BUCK_VCORE_SSHUB_VOSEL_SHIFT             8
#define PMIC_RG_BUCK_VGPU_EN_MASK                        0x1
#define PMIC_RG_BUCK_VGPU_EN_SHIFT                       0
#define PMIC_RG_BUCK_VGPU_LP_MASK                        0x1
#define PMIC_RG_BUCK_VGPU_LP_SHIFT                       1
#define PMIC_RG_BUCK_VGPU_VOSEL_MASK                     0x7F
#define PMIC_RG_BUCK_VGPU_VOSEL_SHIFT                    0
#define PMIC_RG_BUCK_VGPU_VOSEL_SLEEP_MASK               0x7F
#define PMIC_RG_BUCK_VGPU_VOSEL_SLEEP_SHIFT              0
#define PMIC_RG_BUCK_VGPU_SFCHG_FRATE_MASK               0x7F
#define PMIC_RG_BUCK_VGPU_SFCHG_FRATE_SHIFT              0
#define PMIC_RG_BUCK_VGPU_SFCHG_FEN_MASK                 0x1
#define PMIC_RG_BUCK_VGPU_SFCHG_FEN_SHIFT                7
#define PMIC_RG_BUCK_VGPU_SFCHG_RRATE_MASK               0x7F
#define PMIC_RG_BUCK_VGPU_SFCHG_RRATE_SHIFT              8
#define PMIC_RG_BUCK_VGPU_SFCHG_REN_MASK                 0x1
#define PMIC_RG_BUCK_VGPU_SFCHG_REN_SHIFT                15
#define PMIC_RG_BUCK_VGPU_DVS_EN_TD_MASK                 0x3
#define PMIC_RG_BUCK_VGPU_DVS_EN_TD_SHIFT                0
#define PMIC_RG_BUCK_VGPU_DVS_EN_CTRL_MASK               0x3
#define PMIC_RG_BUCK_VGPU_DVS_EN_CTRL_SHIFT              4
#define PMIC_RG_BUCK_VGPU_DVS_EN_ONCE_MASK               0x1
#define PMIC_RG_BUCK_VGPU_DVS_EN_ONCE_SHIFT              6
#define PMIC_RG_BUCK_VGPU_DVS_DOWN_TD_MASK               0x3
#define PMIC_RG_BUCK_VGPU_DVS_DOWN_TD_SHIFT              8
#define PMIC_RG_BUCK_VGPU_DVS_DOWN_CTRL_MASK             0x3
#define PMIC_RG_BUCK_VGPU_DVS_DOWN_CTRL_SHIFT            12
#define PMIC_RG_BUCK_VGPU_DVS_DOWN_ONCE_MASK             0x1
#define PMIC_RG_BUCK_VGPU_DVS_DOWN_ONCE_SHIFT            14
#define PMIC_RG_BUCK_VGPU_SW_OP_EN_MASK                  0x1
#define PMIC_RG_BUCK_VGPU_SW_OP_EN_SHIFT                 0
#define PMIC_RG_BUCK_VGPU_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_BUCK_VGPU_HW0_OP_EN_SHIFT                1
#define PMIC_RG_BUCK_VGPU_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_BUCK_VGPU_HW1_OP_EN_SHIFT                2
#define PMIC_RG_BUCK_VGPU_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_BUCK_VGPU_HW2_OP_EN_SHIFT                3
#define PMIC_RG_BUCK_VGPU_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_BUCK_VGPU_OP_EN_SET_SHIFT                0
#define PMIC_RG_BUCK_VGPU_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_BUCK_VGPU_OP_EN_CLR_SHIFT                0
#define PMIC_RG_BUCK_VGPU_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_BUCK_VGPU_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_BUCK_VGPU_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_BUCK_VGPU_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_BUCK_VGPU_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_BUCK_VGPU_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_BUCK_VGPU_ON_OP_MASK                     0x1
#define PMIC_RG_BUCK_VGPU_ON_OP_SHIFT                    8
#define PMIC_RG_BUCK_VGPU_LP_OP_MASK                     0x1
#define PMIC_RG_BUCK_VGPU_LP_OP_SHIFT                    9
#define PMIC_RG_BUCK_VGPU_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_BUCK_VGPU_OP_CFG_SET_SHIFT               0
#define PMIC_RG_BUCK_VGPU_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_BUCK_VGPU_OP_CFG_CLR_SHIFT               0
#define PMIC_RG_BUCK_VGPU_SP_SW_VOSEL_MASK               0x7F
#define PMIC_RG_BUCK_VGPU_SP_SW_VOSEL_SHIFT              0
#define PMIC_RG_BUCK_VGPU_SP_SW_VOSEL_EN_MASK            0x1
#define PMIC_RG_BUCK_VGPU_SP_SW_VOSEL_EN_SHIFT           0
#define PMIC_RG_BUCK_VGPU_SP_ON_VOSEL_MUX_SEL_MASK       0x1
#define PMIC_RG_BUCK_VGPU_SP_ON_VOSEL_MUX_SEL_SHIFT      1
#define PMIC_RG_BUCK_VGPU_OC_DEG_EN_MASK                 0x1
#define PMIC_RG_BUCK_VGPU_OC_DEG_EN_SHIFT                1
#define PMIC_RG_BUCK_VGPU_OC_WND_MASK                    0x3
#define PMIC_RG_BUCK_VGPU_OC_WND_SHIFT                   2
#define PMIC_RG_BUCK_VGPU_OC_THD_MASK                    0x3
#define PMIC_RG_BUCK_VGPU_OC_THD_SHIFT                   6
#define PMIC_DA_VGPU_VOSEL_MASK                          0x7F
#define PMIC_DA_VGPU_VOSEL_SHIFT                         0
#define PMIC_DA_VGPU_VOSEL_GRAY_MASK                     0x7F
#define PMIC_DA_VGPU_VOSEL_GRAY_SHIFT                    8
#define PMIC_DA_VGPU_EN_MASK                             0x1
#define PMIC_DA_VGPU_EN_SHIFT                            0
#define PMIC_DA_VGPU_STB_MASK                            0x1
#define PMIC_DA_VGPU_STB_SHIFT                           1
#define PMIC_DA_VGPU_VSLEEP_SEL_MASK                     0x1
#define PMIC_DA_VGPU_VSLEEP_SEL_SHIFT                    2
#define PMIC_DA_VGPU_R2R_PDN_MASK                        0x1
#define PMIC_DA_VGPU_R2R_PDN_SHIFT                       3
#define PMIC_DA_VGPU_DVS_EN_MASK                         0x1
#define PMIC_DA_VGPU_DVS_EN_SHIFT                        4
#define PMIC_DA_VGPU_DVS_DOWN_MASK                       0x1
#define PMIC_DA_VGPU_DVS_DOWN_SHIFT                      5
#define PMIC_DA_VGPU_SSH_MASK                            0x1
#define PMIC_DA_VGPU_SSH_SHIFT                           6
#define PMIC_DA_VGPU_MINFREQ_DISCHARGE_MASK              0x1
#define PMIC_DA_VGPU_MINFREQ_DISCHARGE_SHIFT             8
#define PMIC_RG_BUCK_VGPU_OC_FLAG_CLR_SEL_MASK           0x1
#define PMIC_RG_BUCK_VGPU_OC_FLAG_CLR_SEL_SHIFT          4
#define PMIC_RG_BUCK_VGPU_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_BUCK_VGPU_OSC_SEL_DIS_SHIFT              5
#define PMIC_RG_BUCK_VGPU_CK_SW_MODE_MASK                0x1
#define PMIC_RG_BUCK_VGPU_CK_SW_MODE_SHIFT               6
#define PMIC_RG_BUCK_VGPU_CK_SW_EN_MASK                  0x1
#define PMIC_RG_BUCK_VGPU_CK_SW_EN_SHIFT                 7
#define PMIC_RG_BUCK_VDRAM1_EN_MASK                      0x1
#define PMIC_RG_BUCK_VDRAM1_EN_SHIFT                     0
#define PMIC_RG_BUCK_VDRAM1_LP_MASK                      0x1
#define PMIC_RG_BUCK_VDRAM1_LP_SHIFT                     1
#define PMIC_RG_BUCK_VDRAM1_VOSEL_MASK                   0x7F
#define PMIC_RG_BUCK_VDRAM1_VOSEL_SHIFT                  0
#define PMIC_RG_BUCK_VDRAM1_VOSEL_SLEEP_MASK             0x7F
#define PMIC_RG_BUCK_VDRAM1_VOSEL_SLEEP_SHIFT            0
#define PMIC_RG_BUCK_VDRAM1_SFCHG_FRATE_MASK             0x7F
#define PMIC_RG_BUCK_VDRAM1_SFCHG_FRATE_SHIFT            0
#define PMIC_RG_BUCK_VDRAM1_SFCHG_FEN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM1_SFCHG_FEN_SHIFT              7
#define PMIC_RG_BUCK_VDRAM1_SFCHG_RRATE_MASK             0x7F
#define PMIC_RG_BUCK_VDRAM1_SFCHG_RRATE_SHIFT            8
#define PMIC_RG_BUCK_VDRAM1_SFCHG_REN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM1_SFCHG_REN_SHIFT              15
#define PMIC_RG_BUCK_VDRAM1_DVS_EN_TD_MASK               0x3
#define PMIC_RG_BUCK_VDRAM1_DVS_EN_TD_SHIFT              0
#define PMIC_RG_BUCK_VDRAM1_DVS_EN_CTRL_MASK             0x3
#define PMIC_RG_BUCK_VDRAM1_DVS_EN_CTRL_SHIFT            4
#define PMIC_RG_BUCK_VDRAM1_DVS_EN_ONCE_MASK             0x1
#define PMIC_RG_BUCK_VDRAM1_DVS_EN_ONCE_SHIFT            6
#define PMIC_RG_BUCK_VDRAM1_DVS_DOWN_TD_MASK             0x3
#define PMIC_RG_BUCK_VDRAM1_DVS_DOWN_TD_SHIFT            8
#define PMIC_RG_BUCK_VDRAM1_DVS_DOWN_CTRL_MASK           0x3
#define PMIC_RG_BUCK_VDRAM1_DVS_DOWN_CTRL_SHIFT          12
#define PMIC_RG_BUCK_VDRAM1_DVS_DOWN_ONCE_MASK           0x1
#define PMIC_RG_BUCK_VDRAM1_DVS_DOWN_ONCE_SHIFT          14
#define PMIC_RG_BUCK_VDRAM1_SW_OP_EN_MASK                0x1
#define PMIC_RG_BUCK_VDRAM1_SW_OP_EN_SHIFT               0
#define PMIC_RG_BUCK_VDRAM1_HW0_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM1_HW0_OP_EN_SHIFT              1
#define PMIC_RG_BUCK_VDRAM1_HW1_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM1_HW1_OP_EN_SHIFT              2
#define PMIC_RG_BUCK_VDRAM1_HW2_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM1_HW2_OP_EN_SHIFT              3
#define PMIC_RG_BUCK_VDRAM1_OP_EN_SET_MASK               0xFFFF
#define PMIC_RG_BUCK_VDRAM1_OP_EN_SET_SHIFT              0
#define PMIC_RG_BUCK_VDRAM1_OP_EN_CLR_MASK               0xFFFF
#define PMIC_RG_BUCK_VDRAM1_OP_EN_CLR_SHIFT              0
#define PMIC_RG_BUCK_VDRAM1_HW0_OP_CFG_MASK              0x1
#define PMIC_RG_BUCK_VDRAM1_HW0_OP_CFG_SHIFT             1
#define PMIC_RG_BUCK_VDRAM1_HW1_OP_CFG_MASK              0x1
#define PMIC_RG_BUCK_VDRAM1_HW1_OP_CFG_SHIFT             2
#define PMIC_RG_BUCK_VDRAM1_HW2_OP_CFG_MASK              0x1
#define PMIC_RG_BUCK_VDRAM1_HW2_OP_CFG_SHIFT             3
#define PMIC_RG_BUCK_VDRAM1_ON_OP_MASK                   0x1
#define PMIC_RG_BUCK_VDRAM1_ON_OP_SHIFT                  8
#define PMIC_RG_BUCK_VDRAM1_LP_OP_MASK                   0x1
#define PMIC_RG_BUCK_VDRAM1_LP_OP_SHIFT                  9
#define PMIC_RG_BUCK_VDRAM1_OP_CFG_SET_MASK              0xFFFF
#define PMIC_RG_BUCK_VDRAM1_OP_CFG_SET_SHIFT             0
#define PMIC_RG_BUCK_VDRAM1_OP_CFG_CLR_MASK              0xFFFF
#define PMIC_RG_BUCK_VDRAM1_OP_CFG_CLR_SHIFT             0
#define PMIC_RG_BUCK_VDRAM1_SP_SW_VOSEL_MASK             0x7F
#define PMIC_RG_BUCK_VDRAM1_SP_SW_VOSEL_SHIFT            0
#define PMIC_RG_BUCK_VDRAM1_SP_SW_VOSEL_EN_MASK          0x1
#define PMIC_RG_BUCK_VDRAM1_SP_SW_VOSEL_EN_SHIFT         0
#define PMIC_RG_BUCK_VDRAM1_SP_ON_VOSEL_MUX_SEL_MASK     0x1
#define PMIC_RG_BUCK_VDRAM1_SP_ON_VOSEL_MUX_SEL_SHIFT    1
#define PMIC_RG_BUCK_VDRAM1_OC_DEG_EN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM1_OC_DEG_EN_SHIFT              1
#define PMIC_RG_BUCK_VDRAM1_OC_WND_MASK                  0x3
#define PMIC_RG_BUCK_VDRAM1_OC_WND_SHIFT                 2
#define PMIC_RG_BUCK_VDRAM1_OC_THD_MASK                  0x3
#define PMIC_RG_BUCK_VDRAM1_OC_THD_SHIFT                 6
#define PMIC_DA_VDRAM1_VOSEL_MASK                        0x7F
#define PMIC_DA_VDRAM1_VOSEL_SHIFT                       0
#define PMIC_DA_VDRAM1_VOSEL_GRAY_MASK                   0x7F
#define PMIC_DA_VDRAM1_VOSEL_GRAY_SHIFT                  8
#define PMIC_DA_VDRAM1_EN_MASK                           0x1
#define PMIC_DA_VDRAM1_EN_SHIFT                          0
#define PMIC_DA_VDRAM1_STB_MASK                          0x1
#define PMIC_DA_VDRAM1_STB_SHIFT                         1
#define PMIC_DA_VDRAM1_VSLEEP_SEL_MASK                   0x1
#define PMIC_DA_VDRAM1_VSLEEP_SEL_SHIFT                  2
#define PMIC_DA_VDRAM1_R2R_PDN_MASK                      0x1
#define PMIC_DA_VDRAM1_R2R_PDN_SHIFT                     3
#define PMIC_DA_VDRAM1_DVS_EN_MASK                       0x1
#define PMIC_DA_VDRAM1_DVS_EN_SHIFT                      4
#define PMIC_DA_VDRAM1_DVS_DOWN_MASK                     0x1
#define PMIC_DA_VDRAM1_DVS_DOWN_SHIFT                    5
#define PMIC_DA_VDRAM1_SSH_MASK                          0x1
#define PMIC_DA_VDRAM1_SSH_SHIFT                         6
#define PMIC_DA_VDRAM1_MINFREQ_DISCHARGE_MASK            0x1
#define PMIC_DA_VDRAM1_MINFREQ_DISCHARGE_SHIFT           8
#define PMIC_RG_BUCK_VDRAM1_OC_FLAG_CLR_SEL_MASK         0x1
#define PMIC_RG_BUCK_VDRAM1_OC_FLAG_CLR_SEL_SHIFT        4
#define PMIC_RG_BUCK_VDRAM1_OSC_SEL_DIS_MASK             0x1
#define PMIC_RG_BUCK_VDRAM1_OSC_SEL_DIS_SHIFT            5
#define PMIC_RG_BUCK_VDRAM1_CK_SW_MODE_MASK              0x1
#define PMIC_RG_BUCK_VDRAM1_CK_SW_MODE_SHIFT             6
#define PMIC_RG_BUCK_VDRAM1_CK_SW_EN_MASK                0x1
#define PMIC_RG_BUCK_VDRAM1_CK_SW_EN_SHIFT               7
#define PMIC_RG_BUCK_VDRAM2_EN_MASK                      0x1
#define PMIC_RG_BUCK_VDRAM2_EN_SHIFT                     0
#define PMIC_RG_BUCK_VDRAM2_LP_MASK                      0x1
#define PMIC_RG_BUCK_VDRAM2_LP_SHIFT                     1
#define PMIC_RG_BUCK_VDRAM2_VOSEL_MASK                   0x7F
#define PMIC_RG_BUCK_VDRAM2_VOSEL_SHIFT                  0
#define PMIC_RG_BUCK_VDRAM2_VOSEL_SLEEP_MASK             0x7F
#define PMIC_RG_BUCK_VDRAM2_VOSEL_SLEEP_SHIFT            0
#define PMIC_RG_BUCK_VDRAM2_SFCHG_FRATE_MASK             0x7F
#define PMIC_RG_BUCK_VDRAM2_SFCHG_FRATE_SHIFT            0
#define PMIC_RG_BUCK_VDRAM2_SFCHG_FEN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM2_SFCHG_FEN_SHIFT              7
#define PMIC_RG_BUCK_VDRAM2_SFCHG_RRATE_MASK             0x7F
#define PMIC_RG_BUCK_VDRAM2_SFCHG_RRATE_SHIFT            8
#define PMIC_RG_BUCK_VDRAM2_SFCHG_REN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM2_SFCHG_REN_SHIFT              15
#define PMIC_RG_BUCK_VDRAM2_DVS_EN_TD_MASK               0x3
#define PMIC_RG_BUCK_VDRAM2_DVS_EN_TD_SHIFT              0
#define PMIC_RG_BUCK_VDRAM2_DVS_EN_CTRL_MASK             0x3
#define PMIC_RG_BUCK_VDRAM2_DVS_EN_CTRL_SHIFT            4
#define PMIC_RG_BUCK_VDRAM2_DVS_EN_ONCE_MASK             0x1
#define PMIC_RG_BUCK_VDRAM2_DVS_EN_ONCE_SHIFT            6
#define PMIC_RG_BUCK_VDRAM2_DVS_DOWN_TD_MASK             0x3
#define PMIC_RG_BUCK_VDRAM2_DVS_DOWN_TD_SHIFT            8
#define PMIC_RG_BUCK_VDRAM2_DVS_DOWN_CTRL_MASK           0x3
#define PMIC_RG_BUCK_VDRAM2_DVS_DOWN_CTRL_SHIFT          12
#define PMIC_RG_BUCK_VDRAM2_DVS_DOWN_ONCE_MASK           0x1
#define PMIC_RG_BUCK_VDRAM2_DVS_DOWN_ONCE_SHIFT          14
#define PMIC_RG_BUCK_VDRAM2_SW_OP_EN_MASK                0x1
#define PMIC_RG_BUCK_VDRAM2_SW_OP_EN_SHIFT               0
#define PMIC_RG_BUCK_VDRAM2_HW0_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM2_HW0_OP_EN_SHIFT              1
#define PMIC_RG_BUCK_VDRAM2_HW1_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM2_HW1_OP_EN_SHIFT              2
#define PMIC_RG_BUCK_VDRAM2_HW2_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM2_HW2_OP_EN_SHIFT              3
#define PMIC_RG_BUCK_VDRAM2_OP_EN_SET_MASK               0xFFFF
#define PMIC_RG_BUCK_VDRAM2_OP_EN_SET_SHIFT              0
#define PMIC_RG_BUCK_VDRAM2_OP_EN_CLR_MASK               0xFFFF
#define PMIC_RG_BUCK_VDRAM2_OP_EN_CLR_SHIFT              0
#define PMIC_RG_BUCK_VDRAM2_HW0_OP_CFG_MASK              0x1
#define PMIC_RG_BUCK_VDRAM2_HW0_OP_CFG_SHIFT             1
#define PMIC_RG_BUCK_VDRAM2_HW1_OP_CFG_MASK              0x1
#define PMIC_RG_BUCK_VDRAM2_HW1_OP_CFG_SHIFT             2
#define PMIC_RG_BUCK_VDRAM2_HW2_OP_CFG_MASK              0x1
#define PMIC_RG_BUCK_VDRAM2_HW2_OP_CFG_SHIFT             3
#define PMIC_RG_BUCK_VDRAM2_ON_OP_MASK                   0x1
#define PMIC_RG_BUCK_VDRAM2_ON_OP_SHIFT                  8
#define PMIC_RG_BUCK_VDRAM2_LP_OP_MASK                   0x1
#define PMIC_RG_BUCK_VDRAM2_LP_OP_SHIFT                  9
#define PMIC_RG_BUCK_VDRAM2_OP_CFG_SET_MASK              0xFFFF
#define PMIC_RG_BUCK_VDRAM2_OP_CFG_SET_SHIFT             0
#define PMIC_RG_BUCK_VDRAM2_OP_CFG_CLR_MASK              0xFFFF
#define PMIC_RG_BUCK_VDRAM2_OP_CFG_CLR_SHIFT             0
#define PMIC_RG_BUCK_VDRAM2_SP_SW_VOSEL_MASK             0x7F
#define PMIC_RG_BUCK_VDRAM2_SP_SW_VOSEL_SHIFT            0
#define PMIC_RG_BUCK_VDRAM2_SP_SW_VOSEL_EN_MASK          0x1
#define PMIC_RG_BUCK_VDRAM2_SP_SW_VOSEL_EN_SHIFT         0
#define PMIC_RG_BUCK_VDRAM2_SP_ON_VOSEL_MUX_SEL_MASK     0x1
#define PMIC_RG_BUCK_VDRAM2_SP_ON_VOSEL_MUX_SEL_SHIFT    1
#define PMIC_RG_BUCK_VDRAM2_OC_DEG_EN_MASK               0x1
#define PMIC_RG_BUCK_VDRAM2_OC_DEG_EN_SHIFT              1
#define PMIC_RG_BUCK_VDRAM2_OC_WND_MASK                  0x3
#define PMIC_RG_BUCK_VDRAM2_OC_WND_SHIFT                 2
#define PMIC_RG_BUCK_VDRAM2_OC_THD_MASK                  0x3
#define PMIC_RG_BUCK_VDRAM2_OC_THD_SHIFT                 6
#define PMIC_DA_VDRAM2_VOSEL_MASK                        0x7F
#define PMIC_DA_VDRAM2_VOSEL_SHIFT                       0
#define PMIC_DA_VDRAM2_VOSEL_GRAY_MASK                   0x7F
#define PMIC_DA_VDRAM2_VOSEL_GRAY_SHIFT                  8
#define PMIC_DA_VDRAM2_EN_MASK                           0x1
#define PMIC_DA_VDRAM2_EN_SHIFT                          0
#define PMIC_DA_VDRAM2_STB_MASK                          0x1
#define PMIC_DA_VDRAM2_STB_SHIFT                         1
#define PMIC_DA_VDRAM2_VSLEEP_SEL_MASK                   0x1
#define PMIC_DA_VDRAM2_VSLEEP_SEL_SHIFT                  2
#define PMIC_DA_VDRAM2_R2R_PDN_MASK                      0x1
#define PMIC_DA_VDRAM2_R2R_PDN_SHIFT                     3
#define PMIC_DA_VDRAM2_DVS_EN_MASK                       0x1
#define PMIC_DA_VDRAM2_DVS_EN_SHIFT                      4
#define PMIC_DA_VDRAM2_DVS_DOWN_MASK                     0x1
#define PMIC_DA_VDRAM2_DVS_DOWN_SHIFT                    5
#define PMIC_DA_VDRAM2_SSH_MASK                          0x1
#define PMIC_DA_VDRAM2_SSH_SHIFT                         6
#define PMIC_DA_VDRAM2_MINFREQ_DISCHARGE_MASK            0x1
#define PMIC_DA_VDRAM2_MINFREQ_DISCHARGE_SHIFT           8
#define PMIC_RG_BUCK_VDRAM2_OC_FLAG_CLR_SEL_MASK         0x1
#define PMIC_RG_BUCK_VDRAM2_OC_FLAG_CLR_SEL_SHIFT        4
#define PMIC_RG_BUCK_VDRAM2_OSC_SEL_DIS_MASK             0x1
#define PMIC_RG_BUCK_VDRAM2_OSC_SEL_DIS_SHIFT            5
#define PMIC_RG_BUCK_VDRAM2_CK_SW_MODE_MASK              0x1
#define PMIC_RG_BUCK_VDRAM2_CK_SW_MODE_SHIFT             6
#define PMIC_RG_BUCK_VDRAM2_CK_SW_EN_MASK                0x1
#define PMIC_RG_BUCK_VDRAM2_CK_SW_EN_SHIFT               7
#define PMIC_RG_BUCK_VMODEM_EN_MASK                      0x1
#define PMIC_RG_BUCK_VMODEM_EN_SHIFT                     0
#define PMIC_RG_BUCK_VMODEM_LP_MASK                      0x1
#define PMIC_RG_BUCK_VMODEM_LP_SHIFT                     1
#define PMIC_RG_BUCK_VMODEM_VOSEL_MASK                   0x7F
#define PMIC_RG_BUCK_VMODEM_VOSEL_SHIFT                  0
#define PMIC_RG_BUCK_VMODEM_VOSEL_SLEEP_MASK             0x7F
#define PMIC_RG_BUCK_VMODEM_VOSEL_SLEEP_SHIFT            0
#define PMIC_RG_BUCK_VMODEM_SFCHG_FRATE_MASK             0x7F
#define PMIC_RG_BUCK_VMODEM_SFCHG_FRATE_SHIFT            0
#define PMIC_RG_BUCK_VMODEM_SFCHG_FEN_MASK               0x1
#define PMIC_RG_BUCK_VMODEM_SFCHG_FEN_SHIFT              7
#define PMIC_RG_BUCK_VMODEM_SFCHG_RRATE_MASK             0x7F
#define PMIC_RG_BUCK_VMODEM_SFCHG_RRATE_SHIFT            8
#define PMIC_RG_BUCK_VMODEM_SFCHG_REN_MASK               0x1
#define PMIC_RG_BUCK_VMODEM_SFCHG_REN_SHIFT              15
#define PMIC_RG_BUCK_VMODEM_DVS_EN_TD_MASK               0x3
#define PMIC_RG_BUCK_VMODEM_DVS_EN_TD_SHIFT              0
#define PMIC_RG_BUCK_VMODEM_DVS_EN_CTRL_MASK             0x3
#define PMIC_RG_BUCK_VMODEM_DVS_EN_CTRL_SHIFT            4
#define PMIC_RG_BUCK_VMODEM_DVS_EN_ONCE_MASK             0x1
#define PMIC_RG_BUCK_VMODEM_DVS_EN_ONCE_SHIFT            6
#define PMIC_RG_BUCK_VMODEM_DVS_DOWN_TD_MASK             0x3
#define PMIC_RG_BUCK_VMODEM_DVS_DOWN_TD_SHIFT            8
#define PMIC_RG_BUCK_VMODEM_DVS_DOWN_CTRL_MASK           0x3
#define PMIC_RG_BUCK_VMODEM_DVS_DOWN_CTRL_SHIFT          12
#define PMIC_RG_BUCK_VMODEM_DVS_DOWN_ONCE_MASK           0x1
#define PMIC_RG_BUCK_VMODEM_DVS_DOWN_ONCE_SHIFT          14
#define PMIC_RG_BUCK_VMODEM_SW_OP_EN_MASK                0x1
#define PMIC_RG_BUCK_VMODEM_SW_OP_EN_SHIFT               0
#define PMIC_RG_BUCK_VMODEM_HW0_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VMODEM_HW0_OP_EN_SHIFT              1
#define PMIC_RG_BUCK_VMODEM_HW1_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VMODEM_HW1_OP_EN_SHIFT              2
#define PMIC_RG_BUCK_VMODEM_HW2_OP_EN_MASK               0x1
#define PMIC_RG_BUCK_VMODEM_HW2_OP_EN_SHIFT              3
#define PMIC_RG_BUCK_VMODEM_OP_EN_SET_MASK               0xFFFF
#define PMIC_RG_BUCK_VMODEM_OP_EN_SET_SHIFT              0
#define PMIC_RG_BUCK_VMODEM_OP_EN_CLR_MASK               0xFFFF
#define PMIC_RG_BUCK_VMODEM_OP_EN_CLR_SHIFT              0
#define PMIC_RG_BUCK_VMODEM_HW0_OP_CFG_MASK              0x1
#define PMIC_RG_BUCK_VMODEM_HW0_OP_CFG_SHIFT             1
#define PMIC_RG_BUCK_VMODEM_HW1_OP_CFG_MASK              0x1
#define PMIC_RG_BUCK_VMODEM_HW1_OP_CFG_SHIFT             2
#define PMIC_RG_BUCK_VMODEM_HW2_OP_CFG_MASK              0x1
#define PMIC_RG_BUCK_VMODEM_HW2_OP_CFG_SHIFT             3
#define PMIC_RG_BUCK_VMODEM_ON_OP_MASK                   0x1
#define PMIC_RG_BUCK_VMODEM_ON_OP_SHIFT                  8
#define PMIC_RG_BUCK_VMODEM_LP_OP_MASK                   0x1
#define PMIC_RG_BUCK_VMODEM_LP_OP_SHIFT                  9
#define PMIC_RG_BUCK_VMODEM_OP_CFG_SET_MASK              0xFFFF
#define PMIC_RG_BUCK_VMODEM_OP_CFG_SET_SHIFT             0
#define PMIC_RG_BUCK_VMODEM_OP_CFG_CLR_MASK              0xFFFF
#define PMIC_RG_BUCK_VMODEM_OP_CFG_CLR_SHIFT             0
#define PMIC_RG_BUCK_VMODEM_SP_SW_VOSEL_MASK             0x7F
#define PMIC_RG_BUCK_VMODEM_SP_SW_VOSEL_SHIFT            0
#define PMIC_RG_BUCK_VMODEM_SP_SW_VOSEL_EN_MASK          0x1
#define PMIC_RG_BUCK_VMODEM_SP_SW_VOSEL_EN_SHIFT         0
#define PMIC_RG_BUCK_VMODEM_SP_ON_VOSEL_MUX_SEL_MASK     0x1
#define PMIC_RG_BUCK_VMODEM_SP_ON_VOSEL_MUX_SEL_SHIFT    1
#define PMIC_RG_BUCK_VMODEM_OC_DEG_EN_MASK               0x1
#define PMIC_RG_BUCK_VMODEM_OC_DEG_EN_SHIFT              1
#define PMIC_RG_BUCK_VMODEM_OC_WND_MASK                  0x3
#define PMIC_RG_BUCK_VMODEM_OC_WND_SHIFT                 2
#define PMIC_RG_BUCK_VMODEM_OC_THD_MASK                  0x3
#define PMIC_RG_BUCK_VMODEM_OC_THD_SHIFT                 6
#define PMIC_DA_VMODEM_VOSEL_MASK                        0x7F
#define PMIC_DA_VMODEM_VOSEL_SHIFT                       0
#define PMIC_DA_VMODEM_VOSEL_GRAY_MASK                   0x7F
#define PMIC_DA_VMODEM_VOSEL_GRAY_SHIFT                  8
#define PMIC_DA_VMODEM_EN_MASK                           0x1
#define PMIC_DA_VMODEM_EN_SHIFT                          0
#define PMIC_DA_VMODEM_STB_MASK                          0x1
#define PMIC_DA_VMODEM_STB_SHIFT                         1
#define PMIC_DA_VMODEM_VSLEEP_SEL_MASK                   0x1
#define PMIC_DA_VMODEM_VSLEEP_SEL_SHIFT                  2
#define PMIC_DA_VMODEM_R2R_PDN_MASK                      0x1
#define PMIC_DA_VMODEM_R2R_PDN_SHIFT                     3
#define PMIC_DA_VMODEM_DVS_EN_MASK                       0x1
#define PMIC_DA_VMODEM_DVS_EN_SHIFT                      4
#define PMIC_DA_VMODEM_MINFREQ_DISCHARGE_MASK            0x1
#define PMIC_DA_VMODEM_MINFREQ_DISCHARGE_SHIFT           8
#define PMIC_RG_BUCK_VMODEM_OC_FLAG_CLR_SEL_MASK         0x1
#define PMIC_RG_BUCK_VMODEM_OC_FLAG_CLR_SEL_SHIFT        4
#define PMIC_RG_BUCK_VMODEM_OSC_SEL_DIS_MASK             0x1
#define PMIC_RG_BUCK_VMODEM_OSC_SEL_DIS_SHIFT            5
#define PMIC_RG_BUCK_VMODEM_CK_SW_MODE_MASK              0x1
#define PMIC_RG_BUCK_VMODEM_CK_SW_MODE_SHIFT             6
#define PMIC_RG_BUCK_VMODEM_CK_SW_EN_MASK                0x1
#define PMIC_RG_BUCK_VMODEM_CK_SW_EN_SHIFT               7
#define PMIC_RG_BUCK_VMODEM_VOSEL_DLC0_MASK              0x7F
#define PMIC_RG_BUCK_VMODEM_VOSEL_DLC0_SHIFT             0
#define PMIC_RG_BUCK_VMODEM_VOSEL_DLC1_MASK              0x7F
#define PMIC_RG_BUCK_VMODEM_VOSEL_DLC1_SHIFT             8
#define PMIC_RG_BUCK_VMODEM_VOSEL_DLC2_MASK              0x7F
#define PMIC_RG_BUCK_VMODEM_VOSEL_DLC2_SHIFT             0
#define PMIC_RG_BUCK_VMODEM_DLC0_MASK                    0x7
#define PMIC_RG_BUCK_VMODEM_DLC0_SHIFT                   0
#define PMIC_RG_BUCK_VMODEM_DLC1_MASK                    0x7
#define PMIC_RG_BUCK_VMODEM_DLC1_SHIFT                   4
#define PMIC_RG_BUCK_VMODEM_DLC2_MASK                    0x7
#define PMIC_RG_BUCK_VMODEM_DLC2_SHIFT                   8
#define PMIC_RG_BUCK_VMODEM_DLC3_MASK                    0x7
#define PMIC_RG_BUCK_VMODEM_DLC3_SHIFT                   12
#define PMIC_RG_BUCK_VMODEM_DLC_MAP_EN_MASK              0x1
#define PMIC_RG_BUCK_VMODEM_DLC_MAP_EN_SHIFT             0
#define PMIC_RG_BUCK_VMODEM_DLC_MASK                     0x7
#define PMIC_RG_BUCK_VMODEM_DLC_SHIFT                    8
#define PMIC_DA_VMODEM_DLC_MASK                          0x7
#define PMIC_DA_VMODEM_DLC_SHIFT                         12
#define PMIC_RG_BUCK_VS1_EN_MASK                         0x1
#define PMIC_RG_BUCK_VS1_EN_SHIFT                        0
#define PMIC_RG_BUCK_VS1_LP_MASK                         0x1
#define PMIC_RG_BUCK_VS1_LP_SHIFT                        1
#define PMIC_RG_BUCK_VS1_VOSEL_MASK                      0x7F
#define PMIC_RG_BUCK_VS1_VOSEL_SHIFT                     0
#define PMIC_RG_BUCK_VS1_VOSEL_SLEEP_MASK                0x7F
#define PMIC_RG_BUCK_VS1_VOSEL_SLEEP_SHIFT               0
#define PMIC_RG_BUCK_VS1_SFCHG_FRATE_MASK                0x7F
#define PMIC_RG_BUCK_VS1_SFCHG_FRATE_SHIFT               0
#define PMIC_RG_BUCK_VS1_SFCHG_FEN_MASK                  0x1
#define PMIC_RG_BUCK_VS1_SFCHG_FEN_SHIFT                 7
#define PMIC_RG_BUCK_VS1_SFCHG_RRATE_MASK                0x7F
#define PMIC_RG_BUCK_VS1_SFCHG_RRATE_SHIFT               8
#define PMIC_RG_BUCK_VS1_SFCHG_REN_MASK                  0x1
#define PMIC_RG_BUCK_VS1_SFCHG_REN_SHIFT                 15
#define PMIC_RG_BUCK_VS1_DVS_EN_TD_MASK                  0x3
#define PMIC_RG_BUCK_VS1_DVS_EN_TD_SHIFT                 0
#define PMIC_RG_BUCK_VS1_DVS_EN_CTRL_MASK                0x3
#define PMIC_RG_BUCK_VS1_DVS_EN_CTRL_SHIFT               4
#define PMIC_RG_BUCK_VS1_DVS_EN_ONCE_MASK                0x1
#define PMIC_RG_BUCK_VS1_DVS_EN_ONCE_SHIFT               6
#define PMIC_RG_BUCK_VS1_DVS_DOWN_TD_MASK                0x3
#define PMIC_RG_BUCK_VS1_DVS_DOWN_TD_SHIFT               8
#define PMIC_RG_BUCK_VS1_DVS_DOWN_CTRL_MASK              0x3
#define PMIC_RG_BUCK_VS1_DVS_DOWN_CTRL_SHIFT             12
#define PMIC_RG_BUCK_VS1_DVS_DOWN_ONCE_MASK              0x1
#define PMIC_RG_BUCK_VS1_DVS_DOWN_ONCE_SHIFT             14
#define PMIC_RG_BUCK_VS1_SW_OP_EN_MASK                   0x1
#define PMIC_RG_BUCK_VS1_SW_OP_EN_SHIFT                  0
#define PMIC_RG_BUCK_VS1_HW0_OP_EN_MASK                  0x1
#define PMIC_RG_BUCK_VS1_HW0_OP_EN_SHIFT                 1
#define PMIC_RG_BUCK_VS1_HW1_OP_EN_MASK                  0x1
#define PMIC_RG_BUCK_VS1_HW1_OP_EN_SHIFT                 2
#define PMIC_RG_BUCK_VS1_HW2_OP_EN_MASK                  0x1
#define PMIC_RG_BUCK_VS1_HW2_OP_EN_SHIFT                 3
#define PMIC_RG_BUCK_VS1_OP_EN_SET_MASK                  0xFFFF
#define PMIC_RG_BUCK_VS1_OP_EN_SET_SHIFT                 0
#define PMIC_RG_BUCK_VS1_OP_EN_CLR_MASK                  0xFFFF
#define PMIC_RG_BUCK_VS1_OP_EN_CLR_SHIFT                 0
#define PMIC_RG_BUCK_VS1_HW0_OP_CFG_MASK                 0x1
#define PMIC_RG_BUCK_VS1_HW0_OP_CFG_SHIFT                1
#define PMIC_RG_BUCK_VS1_HW1_OP_CFG_MASK                 0x1
#define PMIC_RG_BUCK_VS1_HW1_OP_CFG_SHIFT                2
#define PMIC_RG_BUCK_VS1_HW2_OP_CFG_MASK                 0x1
#define PMIC_RG_BUCK_VS1_HW2_OP_CFG_SHIFT                3
#define PMIC_RG_BUCK_VS1_ON_OP_MASK                      0x1
#define PMIC_RG_BUCK_VS1_ON_OP_SHIFT                     8
#define PMIC_RG_BUCK_VS1_LP_OP_MASK                      0x1
#define PMIC_RG_BUCK_VS1_LP_OP_SHIFT                     9
#define PMIC_RG_BUCK_VS1_OP_CFG_SET_MASK                 0xFFFF
#define PMIC_RG_BUCK_VS1_OP_CFG_SET_SHIFT                0
#define PMIC_RG_BUCK_VS1_OP_CFG_CLR_MASK                 0xFFFF
#define PMIC_RG_BUCK_VS1_OP_CFG_CLR_SHIFT                0
#define PMIC_RG_BUCK_VS1_SP_SW_VOSEL_MASK                0x7F
#define PMIC_RG_BUCK_VS1_SP_SW_VOSEL_SHIFT               0
#define PMIC_RG_BUCK_VS1_SP_SW_VOSEL_EN_MASK             0x1
#define PMIC_RG_BUCK_VS1_SP_SW_VOSEL_EN_SHIFT            0
#define PMIC_RG_BUCK_VS1_SP_ON_VOSEL_MUX_SEL_MASK        0x1
#define PMIC_RG_BUCK_VS1_SP_ON_VOSEL_MUX_SEL_SHIFT       1
#define PMIC_RG_BUCK_VS1_OC_DEG_EN_MASK                  0x1
#define PMIC_RG_BUCK_VS1_OC_DEG_EN_SHIFT                 1
#define PMIC_RG_BUCK_VS1_OC_WND_MASK                     0x3
#define PMIC_RG_BUCK_VS1_OC_WND_SHIFT                    2
#define PMIC_RG_BUCK_VS1_OC_THD_MASK                     0x3
#define PMIC_RG_BUCK_VS1_OC_THD_SHIFT                    6
#define PMIC_DA_VS1_VOSEL_MASK                           0x7F
#define PMIC_DA_VS1_VOSEL_SHIFT                          0
#define PMIC_DA_VS1_VOSEL_GRAY_MASK                      0x7F
#define PMIC_DA_VS1_VOSEL_GRAY_SHIFT                     8
#define PMIC_DA_VS1_EN_MASK                              0x1
#define PMIC_DA_VS1_EN_SHIFT                             0
#define PMIC_DA_VS1_STB_MASK                             0x1
#define PMIC_DA_VS1_STB_SHIFT                            1
#define PMIC_DA_VS1_VSLEEP_SEL_MASK                      0x1
#define PMIC_DA_VS1_VSLEEP_SEL_SHIFT                     2
#define PMIC_DA_VS1_R2R_PDN_MASK                         0x1
#define PMIC_DA_VS1_R2R_PDN_SHIFT                        3
#define PMIC_DA_VS1_DVS_EN_MASK                          0x1
#define PMIC_DA_VS1_DVS_EN_SHIFT                         4
#define PMIC_DA_VS1_MINFREQ_DISCHARGE_MASK               0x1
#define PMIC_DA_VS1_MINFREQ_DISCHARGE_SHIFT              8
#define PMIC_RG_BUCK_VS1_OC_FLAG_CLR_SEL_MASK            0x1
#define PMIC_RG_BUCK_VS1_OC_FLAG_CLR_SEL_SHIFT           4
#define PMIC_RG_BUCK_VS1_OSC_SEL_DIS_MASK                0x1
#define PMIC_RG_BUCK_VS1_OSC_SEL_DIS_SHIFT               5
#define PMIC_RG_BUCK_VS1_CK_SW_MODE_MASK                 0x1
#define PMIC_RG_BUCK_VS1_CK_SW_MODE_SHIFT                6
#define PMIC_RG_BUCK_VS1_CK_SW_EN_MASK                   0x1
#define PMIC_RG_BUCK_VS1_CK_SW_EN_SHIFT                  7
#define PMIC_RG_BUCK_VS1_VOTER_EN_MASK                   0xFF
#define PMIC_RG_BUCK_VS1_VOTER_EN_SHIFT                  0
#define PMIC_RG_BUCK_VS1_VOTER_EN_SET_MASK               0xFF
#define PMIC_RG_BUCK_VS1_VOTER_EN_SET_SHIFT              0
#define PMIC_RG_BUCK_VS1_VOTER_EN_CLR_MASK               0xFF
#define PMIC_RG_BUCK_VS1_VOTER_EN_CLR_SHIFT              0
#define PMIC_RG_BUCK_VS1_VOTER_VOSEL_MASK                0x7F
#define PMIC_RG_BUCK_VS1_VOTER_VOSEL_SHIFT               0
#define PMIC_RG_BUCK_VS2_EN_MASK                         0x1
#define PMIC_RG_BUCK_VS2_EN_SHIFT                        0
#define PMIC_RG_BUCK_VS2_LP_MASK                         0x1
#define PMIC_RG_BUCK_VS2_LP_SHIFT                        1
#define PMIC_RG_BUCK_VS2_VOSEL_MASK                      0x7F
#define PMIC_RG_BUCK_VS2_VOSEL_SHIFT                     0
#define PMIC_RG_BUCK_VS2_VOSEL_SLEEP_MASK                0x7F
#define PMIC_RG_BUCK_VS2_VOSEL_SLEEP_SHIFT               0
#define PMIC_RG_BUCK_VS2_SFCHG_FRATE_MASK                0x7F
#define PMIC_RG_BUCK_VS2_SFCHG_FRATE_SHIFT               0
#define PMIC_RG_BUCK_VS2_SFCHG_FEN_MASK                  0x1
#define PMIC_RG_BUCK_VS2_SFCHG_FEN_SHIFT                 7
#define PMIC_RG_BUCK_VS2_SFCHG_RRATE_MASK                0x7F
#define PMIC_RG_BUCK_VS2_SFCHG_RRATE_SHIFT               8
#define PMIC_RG_BUCK_VS2_SFCHG_REN_MASK                  0x1
#define PMIC_RG_BUCK_VS2_SFCHG_REN_SHIFT                 15
#define PMIC_RG_BUCK_VS2_DVS_EN_TD_MASK                  0x3
#define PMIC_RG_BUCK_VS2_DVS_EN_TD_SHIFT                 0
#define PMIC_RG_BUCK_VS2_DVS_EN_CTRL_MASK                0x3
#define PMIC_RG_BUCK_VS2_DVS_EN_CTRL_SHIFT               4
#define PMIC_RG_BUCK_VS2_DVS_EN_ONCE_MASK                0x1
#define PMIC_RG_BUCK_VS2_DVS_EN_ONCE_SHIFT               6
#define PMIC_RG_BUCK_VS2_DVS_DOWN_TD_MASK                0x3
#define PMIC_RG_BUCK_VS2_DVS_DOWN_TD_SHIFT               8
#define PMIC_RG_BUCK_VS2_DVS_DOWN_CTRL_MASK              0x3
#define PMIC_RG_BUCK_VS2_DVS_DOWN_CTRL_SHIFT             12
#define PMIC_RG_BUCK_VS2_DVS_DOWN_ONCE_MASK              0x1
#define PMIC_RG_BUCK_VS2_DVS_DOWN_ONCE_SHIFT             14
#define PMIC_RG_BUCK_VS2_SW_OP_EN_MASK                   0x1
#define PMIC_RG_BUCK_VS2_SW_OP_EN_SHIFT                  0
#define PMIC_RG_BUCK_VS2_HW0_OP_EN_MASK                  0x1
#define PMIC_RG_BUCK_VS2_HW0_OP_EN_SHIFT                 1
#define PMIC_RG_BUCK_VS2_HW1_OP_EN_MASK                  0x1
#define PMIC_RG_BUCK_VS2_HW1_OP_EN_SHIFT                 2
#define PMIC_RG_BUCK_VS2_HW2_OP_EN_MASK                  0x1
#define PMIC_RG_BUCK_VS2_HW2_OP_EN_SHIFT                 3
#define PMIC_RG_BUCK_VS2_OP_EN_SET_MASK                  0xFFFF
#define PMIC_RG_BUCK_VS2_OP_EN_SET_SHIFT                 0
#define PMIC_RG_BUCK_VS2_OP_EN_CLR_MASK                  0xFFFF
#define PMIC_RG_BUCK_VS2_OP_EN_CLR_SHIFT                 0
#define PMIC_RG_BUCK_VS2_HW0_OP_CFG_MASK                 0x1
#define PMIC_RG_BUCK_VS2_HW0_OP_CFG_SHIFT                1
#define PMIC_RG_BUCK_VS2_HW1_OP_CFG_MASK                 0x1
#define PMIC_RG_BUCK_VS2_HW1_OP_CFG_SHIFT                2
#define PMIC_RG_BUCK_VS2_HW2_OP_CFG_MASK                 0x1
#define PMIC_RG_BUCK_VS2_HW2_OP_CFG_SHIFT                3
#define PMIC_RG_BUCK_VS2_ON_OP_MASK                      0x1
#define PMIC_RG_BUCK_VS2_ON_OP_SHIFT                     8
#define PMIC_RG_BUCK_VS2_LP_OP_MASK                      0x1
#define PMIC_RG_BUCK_VS2_LP_OP_SHIFT                     9
#define PMIC_RG_BUCK_VS2_OP_CFG_SET_MASK                 0xFFFF
#define PMIC_RG_BUCK_VS2_OP_CFG_SET_SHIFT                0
#define PMIC_RG_BUCK_VS2_OP_CFG_CLR_MASK                 0xFFFF
#define PMIC_RG_BUCK_VS2_OP_CFG_CLR_SHIFT                0
#define PMIC_RG_BUCK_VS2_SP_SW_VOSEL_MASK                0x7F
#define PMIC_RG_BUCK_VS2_SP_SW_VOSEL_SHIFT               0
#define PMIC_RG_BUCK_VS2_SP_SW_VOSEL_EN_MASK             0x1
#define PMIC_RG_BUCK_VS2_SP_SW_VOSEL_EN_SHIFT            0
#define PMIC_RG_BUCK_VS2_SP_ON_VOSEL_MUX_SEL_MASK        0x1
#define PMIC_RG_BUCK_VS2_SP_ON_VOSEL_MUX_SEL_SHIFT       1
#define PMIC_RG_BUCK_VS2_OC_DEG_EN_MASK                  0x1
#define PMIC_RG_BUCK_VS2_OC_DEG_EN_SHIFT                 1
#define PMIC_RG_BUCK_VS2_OC_WND_MASK                     0x3
#define PMIC_RG_BUCK_VS2_OC_WND_SHIFT                    2
#define PMIC_RG_BUCK_VS2_OC_THD_MASK                     0x3
#define PMIC_RG_BUCK_VS2_OC_THD_SHIFT                    6
#define PMIC_DA_VS2_VOSEL_MASK                           0x7F
#define PMIC_DA_VS2_VOSEL_SHIFT                          0
#define PMIC_DA_VS2_VOSEL_GRAY_MASK                      0x7F
#define PMIC_DA_VS2_VOSEL_GRAY_SHIFT                     8
#define PMIC_DA_VS2_EN_MASK                              0x1
#define PMIC_DA_VS2_EN_SHIFT                             0
#define PMIC_DA_VS2_STB_MASK                             0x1
#define PMIC_DA_VS2_STB_SHIFT                            1
#define PMIC_DA_VS2_VSLEEP_SEL_MASK                      0x1
#define PMIC_DA_VS2_VSLEEP_SEL_SHIFT                     2
#define PMIC_DA_VS2_R2R_PDN_MASK                         0x1
#define PMIC_DA_VS2_R2R_PDN_SHIFT                        3
#define PMIC_DA_VS2_DVS_EN_MASK                          0x1
#define PMIC_DA_VS2_DVS_EN_SHIFT                         4
#define PMIC_DA_VS2_MINFREQ_DISCHARGE_MASK               0x1
#define PMIC_DA_VS2_MINFREQ_DISCHARGE_SHIFT              8
#define PMIC_RG_BUCK_VS2_OC_FLAG_CLR_SEL_MASK            0x1
#define PMIC_RG_BUCK_VS2_OC_FLAG_CLR_SEL_SHIFT           4
#define PMIC_RG_BUCK_VS2_OSC_SEL_DIS_MASK                0x1
#define PMIC_RG_BUCK_VS2_OSC_SEL_DIS_SHIFT               5
#define PMIC_RG_BUCK_VS2_CK_SW_MODE_MASK                 0x1
#define PMIC_RG_BUCK_VS2_CK_SW_MODE_SHIFT                6
#define PMIC_RG_BUCK_VS2_CK_SW_EN_MASK                   0x1
#define PMIC_RG_BUCK_VS2_CK_SW_EN_SHIFT                  7
#define PMIC_RG_BUCK_VS2_VOTER_EN_MASK                   0xFF
#define PMIC_RG_BUCK_VS2_VOTER_EN_SHIFT                  0
#define PMIC_RG_BUCK_VS2_VOTER_EN_SET_MASK               0xFF
#define PMIC_RG_BUCK_VS2_VOTER_EN_SET_SHIFT              0
#define PMIC_RG_BUCK_VS2_VOTER_EN_CLR_MASK               0xFF
#define PMIC_RG_BUCK_VS2_VOTER_EN_CLR_SHIFT              0
#define PMIC_RG_BUCK_VS2_VOTER_VOSEL_MASK                0x7F
#define PMIC_RG_BUCK_VS2_VOTER_VOSEL_SHIFT               0
#define PMIC_RG_BUCK_VPA_EN_MASK                         0x1
#define PMIC_RG_BUCK_VPA_EN_SHIFT                        0
#define PMIC_RG_BUCK_VPA_VOSEL_MASK                      0x3F
#define PMIC_RG_BUCK_VPA_VOSEL_SHIFT                     0
#define PMIC_RG_BUCK_VPA_SFCHG_FRATE_MASK                0x7F
#define PMIC_RG_BUCK_VPA_SFCHG_FRATE_SHIFT               0
#define PMIC_RG_BUCK_VPA_SFCHG_FEN_MASK                  0x1
#define PMIC_RG_BUCK_VPA_SFCHG_FEN_SHIFT                 7
#define PMIC_RG_BUCK_VPA_SFCHG_RRATE_MASK                0x7F
#define PMIC_RG_BUCK_VPA_SFCHG_RRATE_SHIFT               8
#define PMIC_RG_BUCK_VPA_SFCHG_REN_MASK                  0x1
#define PMIC_RG_BUCK_VPA_SFCHG_REN_SHIFT                 15
#define PMIC_RG_BUCK_VPA_DVS_TRANST_TD_MASK              0x3
#define PMIC_RG_BUCK_VPA_DVS_TRANST_TD_SHIFT             0
#define PMIC_RG_BUCK_VPA_DVS_TRANST_CTRL_MASK            0x3
#define PMIC_RG_BUCK_VPA_DVS_TRANST_CTRL_SHIFT           4
#define PMIC_RG_BUCK_VPA_DVS_TRANST_ONCE_MASK            0x1
#define PMIC_RG_BUCK_VPA_DVS_TRANST_ONCE_SHIFT           6
#define PMIC_RG_BUCK_VPA_DVS_BW_TD_MASK                  0x3
#define PMIC_RG_BUCK_VPA_DVS_BW_TD_SHIFT                 8
#define PMIC_RG_BUCK_VPA_DVS_BW_CTRL_MASK                0x3
#define PMIC_RG_BUCK_VPA_DVS_BW_CTRL_SHIFT               12
#define PMIC_RG_BUCK_VPA_DVS_BW_ONCE_MASK                0x1
#define PMIC_RG_BUCK_VPA_DVS_BW_ONCE_SHIFT               14
#define PMIC_RG_BUCK_VPA_OC_DEG_EN_MASK                  0x1
#define PMIC_RG_BUCK_VPA_OC_DEG_EN_SHIFT                 1
#define PMIC_RG_BUCK_VPA_OC_WND_MASK                     0x3
#define PMIC_RG_BUCK_VPA_OC_WND_SHIFT                    2
#define PMIC_RG_BUCK_VPA_OC_THD_MASK                     0x3
#define PMIC_RG_BUCK_VPA_OC_THD_SHIFT                    6
#define PMIC_DA_VPA_VOSEL_MASK                           0x3F
#define PMIC_DA_VPA_VOSEL_SHIFT                          0
#define PMIC_DA_VPA_VOSEL_GRAY_MASK                      0x3F
#define PMIC_DA_VPA_VOSEL_GRAY_SHIFT                     8
#define PMIC_DA_VPA_EN_MASK                              0x1
#define PMIC_DA_VPA_EN_SHIFT                             0
#define PMIC_DA_VPA_STB_MASK                             0x1
#define PMIC_DA_VPA_STB_SHIFT                            1
#define PMIC_DA_VPA_DVS_TRANST_MASK                      0x1
#define PMIC_DA_VPA_DVS_TRANST_SHIFT                     5
#define PMIC_DA_VPA_DVS_BW_MASK                          0x1
#define PMIC_DA_VPA_DVS_BW_SHIFT                         6
#define PMIC_RG_BUCK_VPA_OC_FLAG_CLR_SEL_MASK            0x1
#define PMIC_RG_BUCK_VPA_OC_FLAG_CLR_SEL_SHIFT           4
#define PMIC_RG_BUCK_VPA_OSC_SEL_DIS_MASK                0x1
#define PMIC_RG_BUCK_VPA_OSC_SEL_DIS_SHIFT               5
#define PMIC_RG_BUCK_VPA_CK_SW_MODE_MASK                 0x1
#define PMIC_RG_BUCK_VPA_CK_SW_MODE_SHIFT                6
#define PMIC_RG_BUCK_VPA_CK_SW_EN_MASK                   0x1
#define PMIC_RG_BUCK_VPA_CK_SW_EN_SHIFT                  7
#define PMIC_RG_BUCK_VPA_VOSEL_DLC011_MASK               0x3F
#define PMIC_RG_BUCK_VPA_VOSEL_DLC011_SHIFT              0
#define PMIC_RG_BUCK_VPA_VOSEL_DLC111_MASK               0x3F
#define PMIC_RG_BUCK_VPA_VOSEL_DLC111_SHIFT              8
#define PMIC_RG_BUCK_VPA_VOSEL_DLC001_MASK               0x3F
#define PMIC_RG_BUCK_VPA_VOSEL_DLC001_SHIFT              8
#define PMIC_RG_BUCK_VPA_DLC_MAP_EN_MASK                 0x1
#define PMIC_RG_BUCK_VPA_DLC_MAP_EN_SHIFT                0
#define PMIC_RG_BUCK_VPA_DLC_MASK                        0x7
#define PMIC_RG_BUCK_VPA_DLC_SHIFT                       8
#define PMIC_DA_VPA_DLC_MASK                             0x7
#define PMIC_DA_VPA_DLC_SHIFT                            12
#define PMIC_RG_BUCK_VPA_MSFG_EN_MASK                    0x1
#define PMIC_RG_BUCK_VPA_MSFG_EN_SHIFT                   0
#define PMIC_RG_BUCK_VPA_MSFG_RDELTA2GO_MASK             0x3F
#define PMIC_RG_BUCK_VPA_MSFG_RDELTA2GO_SHIFT            0
#define PMIC_RG_BUCK_VPA_MSFG_FDELTA2GO_MASK             0x3F
#define PMIC_RG_BUCK_VPA_MSFG_FDELTA2GO_SHIFT            8
#define PMIC_RG_BUCK_VPA_MSFG_RRATE0_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_RRATE0_SHIFT               0
#define PMIC_RG_BUCK_VPA_MSFG_RRATE1_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_RRATE1_SHIFT               8
#define PMIC_RG_BUCK_VPA_MSFG_RRATE2_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_RRATE2_SHIFT               0
#define PMIC_RG_BUCK_VPA_MSFG_RRATE3_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_RRATE3_SHIFT               8
#define PMIC_RG_BUCK_VPA_MSFG_RRATE4_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_RRATE4_SHIFT               0
#define PMIC_RG_BUCK_VPA_MSFG_RRATE5_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_RRATE5_SHIFT               8
#define PMIC_RG_BUCK_VPA_MSFG_RTHD0_MASK                 0x3F
#define PMIC_RG_BUCK_VPA_MSFG_RTHD0_SHIFT                0
#define PMIC_RG_BUCK_VPA_MSFG_RTHD1_MASK                 0x3F
#define PMIC_RG_BUCK_VPA_MSFG_RTHD1_SHIFT                8
#define PMIC_RG_BUCK_VPA_MSFG_RTHD2_MASK                 0x3F
#define PMIC_RG_BUCK_VPA_MSFG_RTHD2_SHIFT                0
#define PMIC_RG_BUCK_VPA_MSFG_RTHD3_MASK                 0x3F
#define PMIC_RG_BUCK_VPA_MSFG_RTHD3_SHIFT                8
#define PMIC_RG_BUCK_VPA_MSFG_RTHD4_MASK                 0x3F
#define PMIC_RG_BUCK_VPA_MSFG_RTHD4_SHIFT                0
#define PMIC_RG_BUCK_VPA_MSFG_FRATE0_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_FRATE0_SHIFT               0
#define PMIC_RG_BUCK_VPA_MSFG_FRATE1_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_FRATE1_SHIFT               8
#define PMIC_RG_BUCK_VPA_MSFG_FRATE2_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_FRATE2_SHIFT               0
#define PMIC_RG_BUCK_VPA_MSFG_FRATE3_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_FRATE3_SHIFT               8
#define PMIC_RG_BUCK_VPA_MSFG_FRATE4_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_FRATE4_SHIFT               0
#define PMIC_RG_BUCK_VPA_MSFG_FRATE5_MASK                0x1F
#define PMIC_RG_BUCK_VPA_MSFG_FRATE5_SHIFT               8
#define PMIC_RG_BUCK_VPA_MSFG_FTHD0_MASK                 0x3F
#define PMIC_RG_BUCK_VPA_MSFG_FTHD0_SHIFT                0
#define PMIC_RG_BUCK_VPA_MSFG_FTHD1_MASK                 0x3F
#define PMIC_RG_BUCK_VPA_MSFG_FTHD1_SHIFT                8
#define PMIC_RG_BUCK_VPA_MSFG_FTHD2_MASK                 0x3F
#define PMIC_RG_BUCK_VPA_MSFG_FTHD2_SHIFT                0
#define PMIC_RG_BUCK_VPA_MSFG_FTHD3_MASK                 0x3F
#define PMIC_RG_BUCK_VPA_MSFG_FTHD3_SHIFT                8
#define PMIC_RG_BUCK_VPA_MSFG_FTHD4_MASK                 0x3F
#define PMIC_RG_BUCK_VPA_MSFG_FTHD4_SHIFT                0
#define PMIC_RG_SMPS_TESTMODE_B_MASK                     0xFFF
#define PMIC_RG_SMPS_TESTMODE_B_SHIFT                    0
#define PMIC_RG_VPA_BURSTH_MASK                          0x3
#define PMIC_RG_VPA_BURSTH_SHIFT                         12
#define PMIC_RG_VPA_BURSTL_MASK                          0x3
#define PMIC_RG_VPA_BURSTL_SHIFT                         14
#define PMIC_RG_VPA_TRIMH_MASK                           0x1F
#define PMIC_RG_VPA_TRIMH_SHIFT                          0
#define PMIC_RG_VPA_TRIML_MASK                           0x1F
#define PMIC_RG_VPA_TRIML_SHIFT                          5
#define PMIC_RG_VPA_TRIM_REF_MASK                        0x1F
#define PMIC_RG_VPA_TRIM_REF_SHIFT                       10
#define PMIC_RG_VCORE_TRIMH_MASK                         0x1F
#define PMIC_RG_VCORE_TRIMH_SHIFT                        0
#define PMIC_RG_VCORE_TRIML_MASK                         0x1F
#define PMIC_RG_VCORE_TRIML_SHIFT                        5
#define PMIC_RG_VCORE_VSLEEP_TRIM_MASK                   0x7
#define PMIC_RG_VCORE_VSLEEP_TRIM_SHIFT                  10
#define PMIC_RG_VCORE_SLEEP_VOLTAGE_MASK                 0x3
#define PMIC_RG_VCORE_SLEEP_VOLTAGE_SHIFT                13
#define PMIC_RG_VDRAM1_TRIMH_MASK                        0x1F
#define PMIC_RG_VDRAM1_TRIMH_SHIFT                       0
#define PMIC_RG_VDRAM1_TRIML_MASK                        0x1F
#define PMIC_RG_VDRAM1_TRIML_SHIFT                       5
#define PMIC_RG_VDRAM1_VSLEEP_TRIM_MASK                  0x7
#define PMIC_RG_VDRAM1_VSLEEP_TRIM_SHIFT                 10
#define PMIC_RG_VDRAM1_SLEEP_VOLTAGE_MASK                0x1
#define PMIC_RG_VDRAM1_SLEEP_VOLTAGE_SHIFT               13
#define PMIC_RG_VMODEM_TRIMH_MASK                        0x1F
#define PMIC_RG_VMODEM_TRIMH_SHIFT                       0
#define PMIC_RG_VMODEM_TRIML_MASK                        0x1F
#define PMIC_RG_VMODEM_TRIML_SHIFT                       5
#define PMIC_RG_VMODEM_VSLEEP_TRIM_MASK                  0x7
#define PMIC_RG_VMODEM_VSLEEP_TRIM_SHIFT                 10
#define PMIC_RG_VMODEM_SLEEP_VOLTAGE_MASK                0x7
#define PMIC_RG_VMODEM_SLEEP_VOLTAGE_SHIFT               13
#define PMIC_RG_VGPU_TRIMH_MASK                          0x1F
#define PMIC_RG_VGPU_TRIMH_SHIFT                         0
#define PMIC_RG_VGPU_TRIML_MASK                          0x1F
#define PMIC_RG_VGPU_TRIML_SHIFT                         5
#define PMIC_RG_VGPU_VSLEEP_TRIM_MASK                    0x7
#define PMIC_RG_VGPU_VSLEEP_TRIM_SHIFT                   10
#define PMIC_RG_VGPU_SLEEP_VOLTAGE_MASK                  0x3
#define PMIC_RG_VGPU_SLEEP_VOLTAGE_SHIFT                 13
#define PMIC_RG_VS1_TRIMH_MASK                           0x1F
#define PMIC_RG_VS1_TRIMH_SHIFT                          0
#define PMIC_RG_VS1_TRIML_MASK                           0x1F
#define PMIC_RG_VS1_TRIML_SHIFT                          5
#define PMIC_RG_VS1_VSLEEP_TRIM_MASK                     0x7
#define PMIC_RG_VS1_VSLEEP_TRIM_SHIFT                    10
#define PMIC_RG_VS1_SLEEP_VOLTAGE_MASK                   0x1
#define PMIC_RG_VS1_SLEEP_VOLTAGE_SHIFT                  13
#define PMIC_RG_VS2_TRIMH_MASK                           0x1F
#define PMIC_RG_VS2_TRIMH_SHIFT                          0
#define PMIC_RG_VS2_TRIML_MASK                           0x1F
#define PMIC_RG_VS2_TRIML_SHIFT                          5
#define PMIC_RG_VS2_VSLEEP_TRIM_MASK                     0x7
#define PMIC_RG_VS2_VSLEEP_TRIM_SHIFT                    10
#define PMIC_RG_VS2_SLEEP_VOLTAGE_MASK                   0x1
#define PMIC_RG_VS2_SLEEP_VOLTAGE_SHIFT                  13
#define PMIC_RG_VDRAM2_TRIMH_MASK                        0x1F
#define PMIC_RG_VDRAM2_TRIMH_SHIFT                       0
#define PMIC_RG_VDRAM2_TRIML_MASK                        0x1F
#define PMIC_RG_VDRAM2_TRIML_SHIFT                       5
#define PMIC_RG_VDRAM2_VSLEEP_TRIM_MASK                  0x7
#define PMIC_RG_VDRAM2_VSLEEP_TRIM_SHIFT                 10
#define PMIC_RG_VDRAM2_SLEEP_VOLTAGE_MASK                0x1
#define PMIC_RG_VDRAM2_SLEEP_VOLTAGE_SHIFT               13
#define PMIC_RG_VPROC11_TRIMH_MASK                       0x1F
#define PMIC_RG_VPROC11_TRIMH_SHIFT                      0
#define PMIC_RG_VPROC11_TRIML_MASK                       0x1F
#define PMIC_RG_VPROC11_TRIML_SHIFT                      5
#define PMIC_RG_VPROC11_VSLEEP_TRIM_MASK                 0x7
#define PMIC_RG_VPROC11_VSLEEP_TRIM_SHIFT                10
#define PMIC_RG_VPROC11_SLEEP_VOLTAGE_MASK               0x3
#define PMIC_RG_VPROC11_SLEEP_VOLTAGE_SHIFT              13
#define PMIC_RG_VPROC12_TRIMH_MASK                       0x1F
#define PMIC_RG_VPROC12_TRIMH_SHIFT                      0
#define PMIC_RG_VPROC12_TRIML_MASK                       0x1F
#define PMIC_RG_VPROC12_TRIML_SHIFT                      5
#define PMIC_RG_VPROC12_VSLEEP_TRIM_MASK                 0x7
#define PMIC_RG_VPROC12_VSLEEP_TRIM_SHIFT                10
#define PMIC_RG_VPROC12_SLEEP_VOLTAGE_MASK               0x3
#define PMIC_RG_VPROC12_SLEEP_VOLTAGE_SHIFT              13
#define PMIC_RG_VSRAM_PROC_TRIMH_MASK                    0x1F
#define PMIC_RG_VSRAM_PROC_TRIMH_SHIFT                   0
#define PMIC_RG_VSRAM_PROC_TRIML_MASK                    0x1F
#define PMIC_RG_VSRAM_PROC_TRIML_SHIFT                   5
#define PMIC_RG_VSRAM_PROC_VSLEEP_TRIM_MASK              0x7
#define PMIC_RG_VSRAM_PROC_VSLEEP_TRIM_SHIFT             10
#define PMIC_RG_VSRAM_PROC_SLEEP_VOLTAGE_MASK            0x3
#define PMIC_RG_VSRAM_PROC_SLEEP_VOLTAGE_SHIFT           13
#define PMIC_RG_VSRAM_CORE_TRIMH_MASK                    0x1F
#define PMIC_RG_VSRAM_CORE_TRIMH_SHIFT                   0
#define PMIC_RG_VSRAM_CORE_TRIML_MASK                    0x1F
#define PMIC_RG_VSRAM_CORE_TRIML_SHIFT                   5
#define PMIC_RG_VSRAM_CORE_VSLEEP_TRIM_MASK              0x7
#define PMIC_RG_VSRAM_CORE_VSLEEP_TRIM_SHIFT             10
#define PMIC_RG_VSRAM_CORE_SLEEP_VOLTAGE_MASK            0x7
#define PMIC_RG_VSRAM_CORE_SLEEP_VOLTAGE_SHIFT           13
#define PMIC_RG_VSRAM_GPU_TRIMH_MASK                     0x1F
#define PMIC_RG_VSRAM_GPU_TRIMH_SHIFT                    0
#define PMIC_RG_VSRAM_GPU_TRIML_MASK                     0x1F
#define PMIC_RG_VSRAM_GPU_TRIML_SHIFT                    5
#define PMIC_RG_VSRAM_GPU_VSLEEP_TRIM_MASK               0x7
#define PMIC_RG_VSRAM_GPU_VSLEEP_TRIM_SHIFT              10
#define PMIC_RG_VSRAM_GPU_SLEEP_VOLTAGE_MASK             0x3
#define PMIC_RG_VSRAM_GPU_SLEEP_VOLTAGE_SHIFT            13
#define PMIC_RG_VSRAM_MD_TRIMH_MASK                      0x1F
#define PMIC_RG_VSRAM_MD_TRIMH_SHIFT                     0
#define PMIC_RG_VSRAM_MD_TRIML_MASK                      0x1F
#define PMIC_RG_VSRAM_MD_TRIML_SHIFT                     5
#define PMIC_RG_VSRAM_MD_VSLEEP_TRIM_MASK                0x7
#define PMIC_RG_VSRAM_MD_VSLEEP_TRIM_SHIFT               10
#define PMIC_RG_VSRAM_MD_SLEEP_VOLTAGE_MASK              0x7
#define PMIC_RG_VSRAM_MD_SLEEP_VOLTAGE_SHIFT             13
#define PMIC_RG_SMPS_IVGD_DET_MASK                       0x1
#define PMIC_RG_SMPS_IVGD_DET_SHIFT                      0
#define PMIC_RG_VOUTDET_EN_MASK                          0x1
#define PMIC_RG_VOUTDET_EN_SHIFT                         1
#define PMIC_RG_AUTOK_RST_MASK                           0x1
#define PMIC_RG_AUTOK_RST_SHIFT                          2
#define PMIC_RG_VPROC11_FPWM_MASK                        0x1
#define PMIC_RG_VPROC11_FPWM_SHIFT                       1
#define PMIC_RG_VPROC12_FPWM_MASK                        0x1
#define PMIC_RG_VPROC12_FPWM_SHIFT                       2
#define PMIC_RG_VPROC11_NDIS_EN_MASK                     0x1
#define PMIC_RG_VPROC11_NDIS_EN_SHIFT                    3
#define PMIC_RG_VPROC12_NDIS_EN_MASK                     0x1
#define PMIC_RG_VPROC12_NDIS_EN_SHIFT                    4
#define PMIC_RG_VPROC11_FCOT_MASK                        0x1
#define PMIC_RG_VPROC11_FCOT_SHIFT                       5
#define PMIC_RG_VPROC12_FCOT_MASK                        0x1
#define PMIC_RG_VPROC12_FCOT_SHIFT                       6
#define PMIC_RG_VPROC_TMDL_MASK                          0x1
#define PMIC_RG_VPROC_TMDL_SHIFT                         7
#define PMIC_RG_VPROC_DISCONFIG20_MASK                   0x1
#define PMIC_RG_VPROC_DISCONFIG20_SHIFT                  8
#define PMIC_RG_VPROC11_TBDIS_MASK                       0x1
#define PMIC_RG_VPROC11_TBDIS_SHIFT                      9
#define PMIC_RG_VPROC12_TBDIS_MASK                       0x1
#define PMIC_RG_VPROC12_TBDIS_SHIFT                      10
#define PMIC_RG_VPROC11_VDIFFOFF_MASK                    0x1
#define PMIC_RG_VPROC11_VDIFFOFF_SHIFT                   11
#define PMIC_RG_VPROC12_VDIFFOFF_MASK                    0x1
#define PMIC_RG_VPROC12_VDIFFOFF_SHIFT                   12
#define PMIC_RG_VPROC11_RCOMP0_MASK                      0xF
#define PMIC_RG_VPROC11_RCOMP0_SHIFT                     0
#define PMIC_RG_VPROC11_RCOMP1_MASK                      0x7
#define PMIC_RG_VPROC11_RCOMP1_SHIFT                     4
#define PMIC_RG_VPROC11_CCOMP0_MASK                      0x3
#define PMIC_RG_VPROC11_CCOMP0_SHIFT                     7
#define PMIC_RG_VPROC11_CCOMP1_MASK                      0x3
#define PMIC_RG_VPROC11_CCOMP1_SHIFT                     9
#define PMIC_RG_VPROC11_RAMP_SLP_MASK                    0x7
#define PMIC_RG_VPROC11_RAMP_SLP_SHIFT                   11
#define PMIC_RG_VPROC12_RCOMP0_MASK                      0xF
#define PMIC_RG_VPROC12_RCOMP0_SHIFT                     0
#define PMIC_RG_VPROC12_RCOMP1_MASK                      0x7
#define PMIC_RG_VPROC12_RCOMP1_SHIFT                     4
#define PMIC_RG_VPROC12_CCOMP0_MASK                      0x3
#define PMIC_RG_VPROC12_CCOMP0_SHIFT                     7
#define PMIC_RG_VPROC12_CCOMP1_MASK                      0x3
#define PMIC_RG_VPROC12_CCOMP1_SHIFT                     9
#define PMIC_RG_VPROC12_RAMP_SLP_MASK                    0x7
#define PMIC_RG_VPROC12_RAMP_SLP_SHIFT                   11
#define PMIC_RG_VPROC11_RCS_MASK                         0x7
#define PMIC_RG_VPROC11_RCS_SHIFT                        0
#define PMIC_RG_VPROC12_RCS_MASK                         0x7
#define PMIC_RG_VPROC12_RCS_SHIFT                        3
#define PMIC_RG_VPROC11_RCB_MASK                         0xF
#define PMIC_RG_VPROC11_RCB_SHIFT                        6
#define PMIC_RG_VPROC12_RCB_MASK                         0xF
#define PMIC_RG_VPROC12_RCB_SHIFT                        10
#define PMIC_RG_VPROC11_CSP_TRIM_MASK                    0x7
#define PMIC_RG_VPROC11_CSP_TRIM_SHIFT                   0
#define PMIC_RG_VPROC12_CSP_TRIM_MASK                    0x7
#define PMIC_RG_VPROC12_CSP_TRIM_SHIFT                   3
#define PMIC_RG_VPROC11_CSN_TRIM_MASK                    0x7
#define PMIC_RG_VPROC11_CSN_TRIM_SHIFT                   6
#define PMIC_RG_VPROC12_CSN_TRIM_MASK                    0x7
#define PMIC_RG_VPROC12_CSN_TRIM_SHIFT                   9
#define PMIC_RG_VPROC11_ZC_TRIM_MASK                     0x3
#define PMIC_RG_VPROC11_ZC_TRIM_SHIFT                    12
#define PMIC_RG_VPROC12_ZC_TRIM_MASK                     0x3
#define PMIC_RG_VPROC12_ZC_TRIM_SHIFT                    14
#define PMIC_RG_VPROC11_NLIM_TRIM_MASK                   0xF
#define PMIC_RG_VPROC11_NLIM_TRIM_SHIFT                  0
#define PMIC_RG_VPROC12_NLIM_TRIM_MASK                   0xF
#define PMIC_RG_VPROC12_NLIM_TRIM_SHIFT                  4
#define PMIC_RG_VPROC11_RPSI1_TRIM_MASK                  0x7
#define PMIC_RG_VPROC11_RPSI1_TRIM_SHIFT                 8
#define PMIC_RG_VPROC12_RPSI1_TRIM_MASK                  0x7
#define PMIC_RG_VPROC12_RPSI1_TRIM_SHIFT                 11
#define PMIC_RG_VPROC11_TB_WIDTH_MASK                    0x3
#define PMIC_RG_VPROC11_TB_WIDTH_SHIFT                   0
#define PMIC_RG_VPROC12_TB_WIDTH_MASK                    0x3
#define PMIC_RG_VPROC12_TB_WIDTH_SHIFT                   2
#define PMIC_RG_VPROC11_UG_SR_MASK                       0x3
#define PMIC_RG_VPROC11_UG_SR_SHIFT                      4
#define PMIC_RG_VPROC11_LG_SR_MASK                       0x3
#define PMIC_RG_VPROC11_LG_SR_SHIFT                      6
#define PMIC_RG_VPROC12_UG_SR_MASK                       0x3
#define PMIC_RG_VPROC12_UG_SR_SHIFT                      8
#define PMIC_RG_VPROC12_LG_SR_MASK                       0x3
#define PMIC_RG_VPROC12_LG_SR_SHIFT                      10
#define PMIC_RG_VPROC11_PFM_TON_MASK                     0x7
#define PMIC_RG_VPROC11_PFM_TON_SHIFT                    12
#define PMIC_RG_VPROC12_PFM_TON_MASK                     0x7
#define PMIC_RG_VPROC12_PFM_TON_SHIFT                    0
#define PMIC_RG_VPROC11_TON_TRIM_MASK                    0x3F
#define PMIC_RG_VPROC11_TON_TRIM_SHIFT                   3
#define PMIC_RG_VPROC12_TON_TRIM_MASK                    0x3F
#define PMIC_RG_VPROC12_TON_TRIM_SHIFT                   9
#define PMIC_RGS_VPROC11_OC_STATUS_MASK                  0x1
#define PMIC_RGS_VPROC11_OC_STATUS_SHIFT                 15
#define PMIC_RGS_VPROC12_OC_STATUS_MASK                  0x1
#define PMIC_RGS_VPROC12_OC_STATUS_SHIFT                 0
#define PMIC_RGS_VPROC_TRIMOK_STATUS_MASK                0x1
#define PMIC_RGS_VPROC_TRIMOK_STATUS_SHIFT               1
#define PMIC_RGS_VPROC_CONFIG20_STATUS_MASK              0x1
#define PMIC_RGS_VPROC_CONFIG20_STATUS_SHIFT             2
#define PMIC_RGS_VPROC11_PREOC_STATUS_MASK               0x1
#define PMIC_RGS_VPROC11_PREOC_STATUS_SHIFT              3
#define PMIC_RGS_VPROC11_DIG_MON_MASK                    0xFF
#define PMIC_RGS_VPROC11_DIG_MON_SHIFT                   0
#define PMIC_RGS_VPROC12_DIG_MON_MASK                    0xFF
#define PMIC_RGS_VPROC12_DIG_MON_SHIFT                   8
#define PMIC_RG_VPROC11_TRAN_BST_MASK                    0x3F
#define PMIC_RG_VPROC11_TRAN_BST_SHIFT                   0
#define PMIC_RG_VPROC12_TRAN_BST_MASK                    0x3F
#define PMIC_RG_VPROC12_TRAN_BST_SHIFT                   6
#define PMIC_RG_VPROC11_COTRAMP_SLP_MASK                 0x7
#define PMIC_RG_VPROC11_COTRAMP_SLP_SHIFT                0
#define PMIC_RG_VPROC12_COTRAMP_SLP_MASK                 0x7
#define PMIC_RG_VPROC12_COTRAMP_SLP_SHIFT                3
#define PMIC_RG_VPROC11_SLEEP_TIME_MASK                  0x3
#define PMIC_RG_VPROC11_SLEEP_TIME_SHIFT                 6
#define PMIC_RG_VPROC12_SLEEP_TIME_MASK                  0x3
#define PMIC_RG_VPROC12_SLEEP_TIME_SHIFT                 8
#define PMIC_RG_VPROC11_VREFTB_MASK                      0x3
#define PMIC_RG_VPROC11_VREFTB_SHIFT                     10
#define PMIC_RG_VPROC12_VREFTB_MASK                      0x3
#define PMIC_RG_VPROC12_VREFTB_SHIFT                     12
#define PMIC_RG_VPROC11_CSNSLP_TRIM_MASK                 0xF
#define PMIC_RG_VPROC11_CSNSLP_TRIM_SHIFT                0
#define PMIC_RG_VPROC12_CSNSLP_TRIM_MASK                 0xF
#define PMIC_RG_VPROC12_CSNSLP_TRIM_SHIFT                4
#define PMIC_RG_VPROC11_CSPSLP_TRIM_MASK                 0xF
#define PMIC_RG_VPROC11_CSPSLP_TRIM_SHIFT                8
#define PMIC_RG_VPROC12_CSPSLP_TRIM_MASK                 0xF
#define PMIC_RG_VPROC12_CSPSLP_TRIM_SHIFT                12
#define PMIC_RG_VPROC11_FUGON_MASK                       0x1
#define PMIC_RG_VPROC11_FUGON_SHIFT                      0
#define PMIC_RG_VPROC12_FUGON_MASK                       0x1
#define PMIC_RG_VPROC12_FUGON_SHIFT                      1
#define PMIC_RG_VPROC11_FLGON_MASK                       0x1
#define PMIC_RG_VPROC11_FLGON_SHIFT                      2
#define PMIC_RG_VPROC12_FLGON_MASK                       0x1
#define PMIC_RG_VPROC12_FLGON_SHIFT                      3
#define PMIC_RG_VPROC11_PREOC_TRIM_MASK                  0x7
#define PMIC_RG_VPROC11_PREOC_TRIM_SHIFT                 4
#define PMIC_RG_VPROC11_RSV_MASK                         0xFFFF
#define PMIC_RG_VPROC11_RSV_SHIFT                        0
#define PMIC_RG_VPROC12_RSV_MASK                         0xFFFF
#define PMIC_RG_VPROC12_RSV_SHIFT                        0
#define PMIC_RG_VPROC11_NONAUDIBLE_EN_MASK               0x1
#define PMIC_RG_VPROC11_NONAUDIBLE_EN_SHIFT              0
#define PMIC_RG_VPROC12_NONAUDIBLE_EN_MASK               0x1
#define PMIC_RG_VPROC12_NONAUDIBLE_EN_SHIFT              1
#define PMIC_RG_VPROC_DISAUTOK_MASK                      0x1
#define PMIC_RG_VPROC_DISAUTOK_SHIFT                     2
#define PMIC_RG_VCORE_FPWM_MASK                          0x1
#define PMIC_RG_VCORE_FPWM_SHIFT                         1
#define PMIC_RG_VGPU_FPWM_MASK                           0x1
#define PMIC_RG_VGPU_FPWM_SHIFT                          2
#define PMIC_RG_VCORE_NDIS_EN_MASK                       0x1
#define PMIC_RG_VCORE_NDIS_EN_SHIFT                      3
#define PMIC_RG_VGPU_NDIS_EN_MASK                        0x1
#define PMIC_RG_VGPU_NDIS_EN_SHIFT                       4
#define PMIC_RG_VCORE_FCOT_MASK                          0x1
#define PMIC_RG_VCORE_FCOT_SHIFT                         5
#define PMIC_RG_VGPU_FCOT_MASK                           0x1
#define PMIC_RG_VGPU_FCOT_SHIFT                          6
#define PMIC_RG_VCOREVGPU_TMDL_MASK                      0x1
#define PMIC_RG_VCOREVGPU_TMDL_SHIFT                     7
#define PMIC_RG_VCOREVGPU_DISCONFIG20_MASK               0x1
#define PMIC_RG_VCOREVGPU_DISCONFIG20_SHIFT              8
#define PMIC_RG_VCORE_TBDIS_MASK                         0x1
#define PMIC_RG_VCORE_TBDIS_SHIFT                        9
#define PMIC_RG_VGPU_TBDIS_MASK                          0x1
#define PMIC_RG_VGPU_TBDIS_SHIFT                         10
#define PMIC_RG_VCORE_VDIFFOFF_MASK                      0x1
#define PMIC_RG_VCORE_VDIFFOFF_SHIFT                     11
#define PMIC_RG_VGPU_VDIFFOFF_MASK                       0x1
#define PMIC_RG_VGPU_VDIFFOFF_SHIFT                      12
#define PMIC_RG_VCORE_RCOMP0_MASK                        0xF
#define PMIC_RG_VCORE_RCOMP0_SHIFT                       0
#define PMIC_RG_VCORE_RCOMP1_MASK                        0x7
#define PMIC_RG_VCORE_RCOMP1_SHIFT                       4
#define PMIC_RG_VCORE_CCOMP0_MASK                        0x3
#define PMIC_RG_VCORE_CCOMP0_SHIFT                       7
#define PMIC_RG_VCORE_CCOMP1_MASK                        0x3
#define PMIC_RG_VCORE_CCOMP1_SHIFT                       9
#define PMIC_RG_VCORE_RAMP_SLP_MASK                      0x7
#define PMIC_RG_VCORE_RAMP_SLP_SHIFT                     11
#define PMIC_RG_VGPU_RCOMP0_MASK                         0xF
#define PMIC_RG_VGPU_RCOMP0_SHIFT                        0
#define PMIC_RG_VGPU_RCOMP1_MASK                         0x7
#define PMIC_RG_VGPU_RCOMP1_SHIFT                        4
#define PMIC_RG_VGPU_CCOMP0_MASK                         0x3
#define PMIC_RG_VGPU_CCOMP0_SHIFT                        7
#define PMIC_RG_VGPU_CCOMP1_MASK                         0x3
#define PMIC_RG_VGPU_CCOMP1_SHIFT                        9
#define PMIC_RG_VGPU_RAMP_SLP_MASK                       0x7
#define PMIC_RG_VGPU_RAMP_SLP_SHIFT                      11
#define PMIC_RG_VCORE_RCS_MASK                           0x7
#define PMIC_RG_VCORE_RCS_SHIFT                          0
#define PMIC_RG_VGPU_RCS_MASK                            0x7
#define PMIC_RG_VGPU_RCS_SHIFT                           3
#define PMIC_RG_VCORE_RCB_MASK                           0xF
#define PMIC_RG_VCORE_RCB_SHIFT                          6
#define PMIC_RG_VGPU_RCB_MASK                            0xF
#define PMIC_RG_VGPU_RCB_SHIFT                           10
#define PMIC_RG_VCORE_CSP_TRIM_MASK                      0x7
#define PMIC_RG_VCORE_CSP_TRIM_SHIFT                     0
#define PMIC_RG_VGPU_CSP_TRIM_MASK                       0x7
#define PMIC_RG_VGPU_CSP_TRIM_SHIFT                      3
#define PMIC_RG_VCORE_CSN_TRIM_MASK                      0x7
#define PMIC_RG_VCORE_CSN_TRIM_SHIFT                     6
#define PMIC_RG_VGPU_CSN_TRIM_MASK                       0x7
#define PMIC_RG_VGPU_CSN_TRIM_SHIFT                      9
#define PMIC_RG_VCORE_ZC_TRIM_MASK                       0x3
#define PMIC_RG_VCORE_ZC_TRIM_SHIFT                      12
#define PMIC_RG_VGPU_ZC_TRIM_MASK                        0x3
#define PMIC_RG_VGPU_ZC_TRIM_SHIFT                       14
#define PMIC_RG_VCORE_NLIM_TRIM_MASK                     0xF
#define PMIC_RG_VCORE_NLIM_TRIM_SHIFT                    0
#define PMIC_RG_VGPU_NLIM_TRIM_MASK                      0xF
#define PMIC_RG_VGPU_NLIM_TRIM_SHIFT                     4
#define PMIC_RG_VCORE_RPSI1_TRIM_MASK                    0x7
#define PMIC_RG_VCORE_RPSI1_TRIM_SHIFT                   8
#define PMIC_RG_VGPU_RPSI1_TRIM_MASK                     0x7
#define PMIC_RG_VGPU_RPSI1_TRIM_SHIFT                    11
#define PMIC_RG_VCORE_TB_WIDTH_MASK                      0x3
#define PMIC_RG_VCORE_TB_WIDTH_SHIFT                     0
#define PMIC_RG_VGPU_TB_WIDTH_MASK                       0x3
#define PMIC_RG_VGPU_TB_WIDTH_SHIFT                      2
#define PMIC_RG_VCORE_UG_SR_MASK                         0x3
#define PMIC_RG_VCORE_UG_SR_SHIFT                        4
#define PMIC_RG_VCORE_LG_SR_MASK                         0x3
#define PMIC_RG_VCORE_LG_SR_SHIFT                        6
#define PMIC_RG_VGPU_UG_SR_MASK                          0x3
#define PMIC_RG_VGPU_UG_SR_SHIFT                         8
#define PMIC_RG_VGPU_LG_SR_MASK                          0x3
#define PMIC_RG_VGPU_LG_SR_SHIFT                         10
#define PMIC_RG_VCORE_PFM_TON_MASK                       0x7
#define PMIC_RG_VCORE_PFM_TON_SHIFT                      12
#define PMIC_RG_VGPU_PFM_TON_MASK                        0x7
#define PMIC_RG_VGPU_PFM_TON_SHIFT                       0
#define PMIC_RG_VCORE_TON_TRIM_MASK                      0x3F
#define PMIC_RG_VCORE_TON_TRIM_SHIFT                     3
#define PMIC_RG_VGPU_TON_TRIM_MASK                       0x3F
#define PMIC_RG_VGPU_TON_TRIM_SHIFT                      9
#define PMIC_RGS_VCORE_OC_STATUS_MASK                    0x1
#define PMIC_RGS_VCORE_OC_STATUS_SHIFT                   15
#define PMIC_RGS_VGPU_OC_STATUS_MASK                     0x1
#define PMIC_RGS_VGPU_OC_STATUS_SHIFT                    0
#define PMIC_RGS_VCOREVGPU_TRIMOK_STATUS_MASK            0x1
#define PMIC_RGS_VCOREVGPU_TRIMOK_STATUS_SHIFT           1
#define PMIC_RGS_VCOREVGPU_CONFIG20_STATUS_MASK          0x1
#define PMIC_RGS_VCOREVGPU_CONFIG20_STATUS_SHIFT         2
#define PMIC_RGS_VCORE_PREOC_STATUS_MASK                 0x1
#define PMIC_RGS_VCORE_PREOC_STATUS_SHIFT                3
#define PMIC_RGS_VCORE_DIG_MON_MASK                      0xFF
#define PMIC_RGS_VCORE_DIG_MON_SHIFT                     0
#define PMIC_RGS_VGPU_DIG_MON_MASK                       0xFF
#define PMIC_RGS_VGPU_DIG_MON_SHIFT                      8
#define PMIC_RG_VCORE_TRAN_BST_MASK                      0x3F
#define PMIC_RG_VCORE_TRAN_BST_SHIFT                     0
#define PMIC_RG_VGPU_TRAN_BST_MASK                       0x3F
#define PMIC_RG_VGPU_TRAN_BST_SHIFT                      6
#define PMIC_RG_VCORE_COTRAMP_SLP_MASK                   0x7
#define PMIC_RG_VCORE_COTRAMP_SLP_SHIFT                  0
#define PMIC_RG_VGPU_COTRAMP_SLP_MASK                    0x7
#define PMIC_RG_VGPU_COTRAMP_SLP_SHIFT                   3
#define PMIC_RG_VCORE_SLEEP_TIME_MASK                    0x3
#define PMIC_RG_VCORE_SLEEP_TIME_SHIFT                   6
#define PMIC_RG_VGPU_SLEEP_TIME_MASK                     0x3
#define PMIC_RG_VGPU_SLEEP_TIME_SHIFT                    8
#define PMIC_RG_VCORE_VREFTB_MASK                        0x3
#define PMIC_RG_VCORE_VREFTB_SHIFT                       10
#define PMIC_RG_VGPU_VREFTB_MASK                         0x3
#define PMIC_RG_VGPU_VREFTB_SHIFT                        12
#define PMIC_RG_VCORE_CSNSLP_TRIM_MASK                   0xF
#define PMIC_RG_VCORE_CSNSLP_TRIM_SHIFT                  0
#define PMIC_RG_VGPU_CSNSLP_TRIM_MASK                    0xF
#define PMIC_RG_VGPU_CSNSLP_TRIM_SHIFT                   4
#define PMIC_RG_VCORE_CSPSLP_TRIM_MASK                   0xF
#define PMIC_RG_VCORE_CSPSLP_TRIM_SHIFT                  8
#define PMIC_RG_VGPU_CSPSLP_TRIM_MASK                    0xF
#define PMIC_RG_VGPU_CSPSLP_TRIM_SHIFT                   12
#define PMIC_RG_VCORE_FUGON_MASK                         0x1
#define PMIC_RG_VCORE_FUGON_SHIFT                        0
#define PMIC_RG_VGPU_FUGON_MASK                          0x1
#define PMIC_RG_VGPU_FUGON_SHIFT                         1
#define PMIC_RG_VCORE_FLGON_MASK                         0x1
#define PMIC_RG_VCORE_FLGON_SHIFT                        2
#define PMIC_RG_VGPU_FLGON_MASK                          0x1
#define PMIC_RG_VGPU_FLGON_SHIFT                         3
#define PMIC_RG_VCORE_PREOC_TRIM_MASK                    0x7
#define PMIC_RG_VCORE_PREOC_TRIM_SHIFT                   4
#define PMIC_RG_VCORE_RSV_MASK                           0xFFFF
#define PMIC_RG_VCORE_RSV_SHIFT                          0
#define PMIC_RG_VGPU_RSV_MASK                            0xFFFF
#define PMIC_RG_VGPU_RSV_SHIFT                           0
#define PMIC_RG_VCORE_NONAUDIBLE_EN_MASK                 0x1
#define PMIC_RG_VCORE_NONAUDIBLE_EN_SHIFT                1
#define PMIC_RG_VGPU_NONAUDIBLE_EN_MASK                  0x1
#define PMIC_RG_VGPU_NONAUDIBLE_EN_SHIFT                 2
#define PMIC_RG_VCOREVGPU_DISAUTOK_MASK                  0x1
#define PMIC_RG_VCOREVGPU_DISAUTOK_SHIFT                 3
#define PMIC_RG_VDRAM1_FCOT_MASK                         0x1
#define PMIC_RG_VDRAM1_FCOT_SHIFT                        1
#define PMIC_RG_VDRAM1_RCOMP_MASK                        0xF
#define PMIC_RG_VDRAM1_RCOMP_SHIFT                       2
#define PMIC_RG_VDRAM1_TB_DIS_MASK                       0x1
#define PMIC_RG_VDRAM1_TB_DIS_SHIFT                      6
#define PMIC_RG_VDRAM1_DISPG_MASK                        0x1
#define PMIC_RG_VDRAM1_DISPG_SHIFT                       7
#define PMIC_RG_VDRAM1_FPWM_MASK                         0x1
#define PMIC_RG_VDRAM1_FPWM_SHIFT                        8
#define PMIC_RG_VDRAM1_ZC_TRIM_MASK                      0x3
#define PMIC_RG_VDRAM1_ZC_TRIM_SHIFT                     9
#define PMIC_RG_VDRAM1_NLIM_TRIM_MASK                    0xF
#define PMIC_RG_VDRAM1_NLIM_TRIM_SHIFT                   11
#define PMIC_RG_VDRAM1_PFM_TON_MASK                      0x7
#define PMIC_RG_VDRAM1_PFM_TON_SHIFT                     0
#define PMIC_RG_VDRAM1_PWMRAMP_SLP_MASK                  0x7
#define PMIC_RG_VDRAM1_PWMRAMP_SLP_SHIFT                 3
#define PMIC_RG_VDRAM1_COTRAMP_SLP_MASK                  0x7
#define PMIC_RG_VDRAM1_COTRAMP_SLP_SHIFT                 6
#define PMIC_RG_VDRAM1_RCS_MASK                          0x7
#define PMIC_RG_VDRAM1_RCS_SHIFT                         9
#define PMIC_RG_VDRAM1_CSN_TRIM_MASK                     0x7
#define PMIC_RG_VDRAM1_CSN_TRIM_SHIFT                    0
#define PMIC_RG_VDRAM1_CSP_TRIM_MASK                     0x7
#define PMIC_RG_VDRAM1_CSP_TRIM_SHIFT                    3
#define PMIC_RG_VDRAM1_RPSI_TRIM_MASK                    0x7
#define PMIC_RG_VDRAM1_RPSI_TRIM_SHIFT                   6
#define PMIC_RG_VDRAM1_SLEEP_TIME_MASK                   0x3
#define PMIC_RG_VDRAM1_SLEEP_TIME_SHIFT                  9
#define PMIC_RG_VDRAM1_NLIM_GATING_MASK                  0x1
#define PMIC_RG_VDRAM1_NLIM_GATING_SHIFT                 11
#define PMIC_RG_VDRAM1_TON_TRIM_MASK                     0x3F
#define PMIC_RG_VDRAM1_TON_TRIM_SHIFT                    0
#define PMIC_RG_VDRAM1_VDIFF_OFF_MASK                    0x1
#define PMIC_RG_VDRAM1_VDIFF_OFF_SHIFT                   6
#define PMIC_RG_VDRAM1_VREFUP_MASK                       0x3
#define PMIC_RG_VDRAM1_VREFUP_SHIFT                      7
#define PMIC_RG_VDRAM1_TB_WIDTH_MASK                     0x3
#define PMIC_RG_VDRAM1_TB_WIDTH_SHIFT                    9
#define PMIC_RG_VDRAM1_UG_SR_MASK                        0x3
#define PMIC_RG_VDRAM1_UG_SR_SHIFT                       11
#define PMIC_RG_VDRAM1_LG_SR_MASK                        0x3
#define PMIC_RG_VDRAM1_LG_SR_SHIFT                       13
#define PMIC_RG_VDRAM1_CCOMP_MASK                        0x3
#define PMIC_RG_VDRAM1_CCOMP_SHIFT                       0
#define PMIC_RG_VDRAM1_NDIS_EN_MASK                      0x1
#define PMIC_RG_VDRAM1_NDIS_EN_SHIFT                     2
#define PMIC_RG_VDRAM1_TMDL_MASK                         0x1
#define PMIC_RG_VDRAM1_TMDL_SHIFT                        3
#define PMIC_RG_VDRAM1_RSV_MASK                          0xFFFF
#define PMIC_RG_VDRAM1_RSV_SHIFT                         0
#define PMIC_RG_VDRAM1_CSNSLP_TRIM_MASK                  0xF
#define PMIC_RG_VDRAM1_CSNSLP_TRIM_SHIFT                 0
#define PMIC_RG_VDRAM1_CSPSLP_TRIM_MASK                  0xF
#define PMIC_RG_VDRAM1_CSPSLP_TRIM_SHIFT                 4
#define PMIC_RG_VDRAM1_FUGON_MASK                        0x1
#define PMIC_RG_VDRAM1_FUGON_SHIFT                       8
#define PMIC_RG_VDRAM1_FLGON_MASK                        0x1
#define PMIC_RG_VDRAM1_FLGON_SHIFT                       9
#define PMIC_RG_VDRAM1_NONAUDIBLE_EN_MASK                0x1
#define PMIC_RG_VDRAM1_NONAUDIBLE_EN_SHIFT               10
#define PMIC_RG_VDRAM1_VDIFFPFM_OFF_MASK                 0x1
#define PMIC_RG_VDRAM1_VDIFFPFM_OFF_SHIFT                11
#define PMIC_RGS_VDRAM1_OC_STATUS_MASK                   0x1
#define PMIC_RGS_VDRAM1_OC_STATUS_SHIFT                  12
#define PMIC_RGS_VDRAM1_ENPWM_STATUS_MASK                0x1
#define PMIC_RGS_VDRAM1_ENPWM_STATUS_SHIFT               13
#define PMIC_RG_VDRAM1_DISAUTOK_MASK                     0x1
#define PMIC_RG_VDRAM1_DISAUTOK_SHIFT                    14
#define PMIC_RGS_VDRAM1_TRIMOK_STATUS_MASK               0x1
#define PMIC_RGS_VDRAM1_TRIMOK_STATUS_SHIFT              15
#define PMIC_RGS_VDRAM1_DIG_MON_MASK                     0xFF
#define PMIC_RGS_VDRAM1_DIG_MON_SHIFT                    0
#define PMIC_RG_VDRAM2_FCOT_MASK                         0x1
#define PMIC_RG_VDRAM2_FCOT_SHIFT                        1
#define PMIC_RG_VDRAM2_RCOMP_MASK                        0xF
#define PMIC_RG_VDRAM2_RCOMP_SHIFT                       2
#define PMIC_RG_VDRAM2_TB_DIS_MASK                       0x1
#define PMIC_RG_VDRAM2_TB_DIS_SHIFT                      6
#define PMIC_RG_VDRAM2_DISPG_MASK                        0x1
#define PMIC_RG_VDRAM2_DISPG_SHIFT                       7
#define PMIC_RG_VDRAM2_FPWM_MASK                         0x1
#define PMIC_RG_VDRAM2_FPWM_SHIFT                        8
#define PMIC_RG_VDRAM2_ZC_TRIM_MASK                      0x3
#define PMIC_RG_VDRAM2_ZC_TRIM_SHIFT                     9
#define PMIC_RG_VDRAM2_NLIM_TRIM_MASK                    0xF
#define PMIC_RG_VDRAM2_NLIM_TRIM_SHIFT                   11
#define PMIC_RG_VDRAM2_PFM_TON_MASK                      0x7
#define PMIC_RG_VDRAM2_PFM_TON_SHIFT                     0
#define PMIC_RG_VDRAM2_PWMRAMP_SLP_MASK                  0x7
#define PMIC_RG_VDRAM2_PWMRAMP_SLP_SHIFT                 3
#define PMIC_RG_VDRAM2_COTRAMP_SLP_MASK                  0x7
#define PMIC_RG_VDRAM2_COTRAMP_SLP_SHIFT                 6
#define PMIC_RG_VDRAM2_RCS_MASK                          0x7
#define PMIC_RG_VDRAM2_RCS_SHIFT                         9
#define PMIC_RG_VDRAM2_CSN_TRIM_MASK                     0x7
#define PMIC_RG_VDRAM2_CSN_TRIM_SHIFT                    0
#define PMIC_RG_VDRAM2_CSP_TRIM_MASK                     0x7
#define PMIC_RG_VDRAM2_CSP_TRIM_SHIFT                    3
#define PMIC_RG_VDRAM2_RPSI_TRIM_MASK                    0x7
#define PMIC_RG_VDRAM2_RPSI_TRIM_SHIFT                   6
#define PMIC_RG_VDRAM2_SLEEP_TIME_MASK                   0x3
#define PMIC_RG_VDRAM2_SLEEP_TIME_SHIFT                  9
#define PMIC_RG_VDRAM2_NLIM_GATING_MASK                  0x1
#define PMIC_RG_VDRAM2_NLIM_GATING_SHIFT                 11
#define PMIC_RG_VDRAM2_TON_TRIM_MASK                     0x3F
#define PMIC_RG_VDRAM2_TON_TRIM_SHIFT                    0
#define PMIC_RG_VDRAM2_VDIFF_OFF_MASK                    0x1
#define PMIC_RG_VDRAM2_VDIFF_OFF_SHIFT                   6
#define PMIC_RG_VDRAM2_VREFUP_MASK                       0x3
#define PMIC_RG_VDRAM2_VREFUP_SHIFT                      7
#define PMIC_RG_VDRAM2_TB_WIDTH_MASK                     0x3
#define PMIC_RG_VDRAM2_TB_WIDTH_SHIFT                    9
#define PMIC_RG_VDRAM2_UG_SR_MASK                        0x3
#define PMIC_RG_VDRAM2_UG_SR_SHIFT                       11
#define PMIC_RG_VDRAM2_LG_SR_MASK                        0x3
#define PMIC_RG_VDRAM2_LG_SR_SHIFT                       13
#define PMIC_RG_VDRAM2_CCOMP_MASK                        0x3
#define PMIC_RG_VDRAM2_CCOMP_SHIFT                       0
#define PMIC_RG_VDRAM2_NDIS_EN_MASK                      0x1
#define PMIC_RG_VDRAM2_NDIS_EN_SHIFT                     2
#define PMIC_RG_VDRAM2_TMDL_MASK                         0x1
#define PMIC_RG_VDRAM2_TMDL_SHIFT                        3
#define PMIC_RG_VDRAM2_RSV_MASK                          0xFFFF
#define PMIC_RG_VDRAM2_RSV_SHIFT                         0
#define PMIC_RG_VDRAM2_CSNSLP_TRIM_MASK                  0xF
#define PMIC_RG_VDRAM2_CSNSLP_TRIM_SHIFT                 0
#define PMIC_RG_VDRAM2_CSPSLP_TRIM_MASK                  0xF
#define PMIC_RG_VDRAM2_CSPSLP_TRIM_SHIFT                 4
#define PMIC_RG_VDRAM2_FUGON_MASK                        0x1
#define PMIC_RG_VDRAM2_FUGON_SHIFT                       8
#define PMIC_RG_VDRAM2_FLGON_MASK                        0x1
#define PMIC_RG_VDRAM2_FLGON_SHIFT                       9
#define PMIC_RG_VDRAM2_NONAUDIBLE_EN_MASK                0x1
#define PMIC_RG_VDRAM2_NONAUDIBLE_EN_SHIFT               10
#define PMIC_RG_VDRAM2_VDIFFPFM_OFF_MASK                 0x1
#define PMIC_RG_VDRAM2_VDIFFPFM_OFF_SHIFT                11
#define PMIC_RGS_VDRAM2_OC_STATUS_MASK                   0x1
#define PMIC_RGS_VDRAM2_OC_STATUS_SHIFT                  12
#define PMIC_RGS_VDRAM2_ENPWM_STATUS_MASK                0x1
#define PMIC_RGS_VDRAM2_ENPWM_STATUS_SHIFT               13
#define PMIC_RG_VDRAM2_DISAUTOK_MASK                     0x1
#define PMIC_RG_VDRAM2_DISAUTOK_SHIFT                    14
#define PMIC_RGS_VDRAM2_TRIMOK_STATUS_MASK               0x1
#define PMIC_RGS_VDRAM2_TRIMOK_STATUS_SHIFT              15
#define PMIC_RGS_VDRAM2_DIG_MON_MASK                     0xFF
#define PMIC_RGS_VDRAM2_DIG_MON_SHIFT                    0
#define PMIC_RG_VMODEM_MODESET_MASK                      0x1
#define PMIC_RG_VMODEM_MODESET_SHIFT                     1
#define PMIC_RG_VMODEM_NDIS_EN_MASK                      0x1
#define PMIC_RG_VMODEM_NDIS_EN_SHIFT                     2
#define PMIC_RG_VMODEM_VRF18_SSTART_EN_MASK              0x1
#define PMIC_RG_VMODEM_VRF18_SSTART_EN_SHIFT             3
#define PMIC_RG_VMODEM_AUTO_MODE_MASK                    0x1
#define PMIC_RG_VMODEM_AUTO_MODE_SHIFT                   4
#define PMIC_RG_VMODEM_RZSEL0_MASK                       0x7
#define PMIC_RG_VMODEM_RZSEL0_SHIFT                      0
#define PMIC_RG_VMODEM_RZSEL1_MASK                       0xF
#define PMIC_RG_VMODEM_RZSEL1_SHIFT                      3
#define PMIC_RG_VMODEM_CCSEL0_MASK                       0x3
#define PMIC_RG_VMODEM_CCSEL0_SHIFT                      7
#define PMIC_RG_VMODEM_CCSEL1_MASK                       0x3
#define PMIC_RG_VMODEM_CCSEL1_SHIFT                      9
#define PMIC_RG_VMODEM_CSL_MASK                          0xF
#define PMIC_RG_VMODEM_CSL_SHIFT                         11
#define PMIC_RG_VMODEM_SLP_MASK                          0x7
#define PMIC_RG_VMODEM_SLP_SHIFT                         0
#define PMIC_RG_VMODEM_ADRC_FEN_MASK                     0x1
#define PMIC_RG_VMODEM_ADRC_FEN_SHIFT                    3
#define PMIC_RG_VMODEM_VC_CAP_CLAMP_FEN_MASK             0x1
#define PMIC_RG_VMODEM_VC_CAP_CLAMP_FEN_SHIFT            4
#define PMIC_RG_VMODEM_VC_CLAMP_FEN_MASK                 0x1
#define PMIC_RG_VMODEM_VC_CLAMP_FEN_SHIFT                5
#define PMIC_RG_VMODEM_BURST_MASK                        0x7
#define PMIC_RG_VMODEM_BURST_SHIFT                       6
#define PMIC_RG_VMODEM_CSR_MASK                          0x7
#define PMIC_RG_VMODEM_CSR_SHIFT                         9
#define PMIC_RG_VMODEM_ZXOS_TRIM_MASK                    0xFF
#define PMIC_RG_VMODEM_ZXOS_TRIM_SHIFT                   0
#define PMIC_RG_VMODEM_PFMSR_EH_MASK                     0x1
#define PMIC_RG_VMODEM_PFMSR_EH_SHIFT                    0
#define PMIC_RG_VMODEM_NLIM_GATING_MASK                  0x1
#define PMIC_RG_VMODEM_NLIM_GATING_SHIFT                 1
#define PMIC_RG_VMODEM_PWMSR_EH_MASK                     0x1
#define PMIC_RG_VMODEM_PWMSR_EH_SHIFT                    2
#define PMIC_RG_VMODEM_HS_VTHDET_MASK                    0x1
#define PMIC_RG_VMODEM_HS_VTHDET_SHIFT                   3
#define PMIC_RG_VMODEM_PG_GATING_MASK                    0x1
#define PMIC_RG_VMODEM_PG_GATING_SHIFT                   4
#define PMIC_RG_VMODEM_HS_ONSPEED_EH_MASK                0x1
#define PMIC_RG_VMODEM_HS_ONSPEED_EH_SHIFT               5
#define PMIC_RG_VMODEM_NLIM_TRIMMING_MASK                0xF
#define PMIC_RG_VMODEM_NLIM_TRIMMING_SHIFT               6
#define PMIC_RG_VMODEM_SR_P_MASK                         0x3
#define PMIC_RG_VMODEM_SR_P_SHIFT                        0
#define PMIC_RG_VMODEM_SR_N_MASK                         0x3
#define PMIC_RG_VMODEM_SR_N_SHIFT                        2
#define PMIC_RG_VMODEM_PFM_RIP_MASK                      0x7
#define PMIC_RG_VMODEM_PFM_RIP_SHIFT                     4
#define PMIC_RG_VMODEM_TRAN_BST_MASK                     0x3F
#define PMIC_RG_VMODEM_TRAN_BST_SHIFT                    7
#define PMIC_RG_VMODEM_DTS_ENB_MASK                      0x1
#define PMIC_RG_VMODEM_DTS_ENB_SHIFT                     13
#define PMIC_RG_VMODEM_MIN_OFF_MASK                      0x3
#define PMIC_RG_VMODEM_MIN_OFF_SHIFT                     14
#define PMIC_RG_VMODEM_1P35UP_SEL_EN_MASK                0x1
#define PMIC_RG_VMODEM_1P35UP_SEL_EN_SHIFT               0
#define PMIC_RG_VMODEM_DLC_AUTO_MODE_MASK                0x1
#define PMIC_RG_VMODEM_DLC_AUTO_MODE_SHIFT               1
#define PMIC_RG_VMODEM_SRC_AUTO_MODE_MASK                0x1
#define PMIC_RG_VMODEM_SRC_AUTO_MODE_SHIFT               2
#define PMIC_RG_VMODEM_UGP_SR_MASK                       0x3
#define PMIC_RG_VMODEM_UGP_SR_SHIFT                      3
#define PMIC_RG_VMODEM_LGP_SR_MASK                       0x3
#define PMIC_RG_VMODEM_LGP_SR_SHIFT                      5
#define PMIC_RG_VMODEM_UGP_SR_PFM_MASK                   0x3
#define PMIC_RG_VMODEM_UGP_SR_PFM_SHIFT                  7
#define PMIC_RG_VMODEM_LGP_SR_PFM_MASK                   0x3
#define PMIC_RG_VMODEM_LGP_SR_PFM_SHIFT                  9
#define PMIC_RG_VMODEM_UGD_VTHSEL_MASK                   0x3
#define PMIC_RG_VMODEM_UGD_VTHSEL_SHIFT                  11
#define PMIC_RG_VMODEM_FNLX_MASK                         0x1
#define PMIC_RG_VMODEM_FNLX_SHIFT                        13
#define PMIC_RG_VMODEM_VDIFF_ENLOWIQ_MASK                0x1
#define PMIC_RG_VMODEM_VDIFF_ENLOWIQ_SHIFT               14
#define PMIC_RG_VMODEM_PFMOC_FWUPOFF_MASK                0x1
#define PMIC_RG_VMODEM_PFMOC_FWUPOFF_SHIFT               15
#define PMIC_RG_VMODEM_PWMOC_FWUPOFF_MASK                0x1
#define PMIC_RG_VMODEM_PWMOC_FWUPOFF_SHIFT               0
#define PMIC_RG_VMODEM_CP_FWUPOFF_MASK                   0x1
#define PMIC_RG_VMODEM_CP_FWUPOFF_SHIFT                  1
#define PMIC_RG_VMODEM_ZX_GATING_MASK                    0x1
#define PMIC_RG_VMODEM_ZX_GATING_SHIFT                   2
#define PMIC_RG_VMODEM_RSV_MASK                          0xFFFF
#define PMIC_RG_VMODEM_RSV_SHIFT                         0
#define PMIC_RG_VMODEM_AZC_EN_MASK                       0x1
#define PMIC_RG_VMODEM_AZC_EN_SHIFT                      0
#define PMIC_RG_VMODEM_AZC_DELAY_MASK                    0x3
#define PMIC_RG_VMODEM_AZC_DELAY_SHIFT                   1
#define PMIC_RG_VMODEM_AZC_HOLD_ENB_MASK                 0x1
#define PMIC_RG_VMODEM_AZC_HOLD_ENB_SHIFT                3
#define PMIC_RGS_VMODEM_OC_STATUS_MASK                   0x1
#define PMIC_RGS_VMODEM_OC_STATUS_SHIFT                  4
#define PMIC_RGS_VMODEM_DIG_MON_MASK                     0xF
#define PMIC_RGS_VMODEM_DIG_MON_SHIFT                    5
#define PMIC_RGS_VMODEM_ENPWM_STATUS_MASK                0x1
#define PMIC_RGS_VMODEM_ENPWM_STATUS_SHIFT               9
#define PMIC_RG_VMODEM_IODETECT_EN18_MASK                0x1
#define PMIC_RG_VMODEM_IODETECT_EN18_SHIFT               10
#define PMIC_RG_VMODEM_PREOC_SEL_MASK                    0x7
#define PMIC_RG_VMODEM_PREOC_SEL_SHIFT                   11
#define PMIC_RG_VMODEM_NONAUDIBLE_EN_MASK                0x1
#define PMIC_RG_VMODEM_NONAUDIBLE_EN_SHIFT               14
#define PMIC_RG_VS1_MIN_OFF_MASK                         0x3
#define PMIC_RG_VS1_MIN_OFF_SHIFT                        0
#define PMIC_RG_VS1_VRF18_SSTART_EN_MASK                 0x1
#define PMIC_RG_VS1_VRF18_SSTART_EN_SHIFT                2
#define PMIC_RG_VS1_1P35UP_SEL_EN_MASK                   0x1
#define PMIC_RG_VS1_1P35UP_SEL_EN_SHIFT                  3
#define PMIC_RG_VS1_RZSEL_MASK                           0x7
#define PMIC_RG_VS1_RZSEL_SHIFT                          4
#define PMIC_RG_VS1_CSR_MASK                             0x7
#define PMIC_RG_VS1_CSR_SHIFT                            7
#define PMIC_RG_VS1_CSL_MASK                             0xF
#define PMIC_RG_VS1_CSL_SHIFT                            10
#define PMIC_RG_VS1_SLP_MASK                             0x7
#define PMIC_RG_VS1_SLP_SHIFT                            0
#define PMIC_RG_VS1_ZX_OS_MASK                           0xF
#define PMIC_RG_VS1_ZX_OS_SHIFT                          3
#define PMIC_RG_VS1_NDIS_EN_MASK                         0x1
#define PMIC_RG_VS1_NDIS_EN_SHIFT                        7
#define PMIC_RG_VS1_CSM_N_MASK                           0x3F
#define PMIC_RG_VS1_CSM_N_SHIFT                          8
#define PMIC_RG_VS1_CSM_P_MASK                           0x3F
#define PMIC_RG_VS1_CSM_P_SHIFT                          0
#define PMIC_RG_VS1_RSV_MASK                             0xFF
#define PMIC_RG_VS1_RSV_SHIFT                            6
#define PMIC_RG_VS1_ZXOS_TRIM_MASK                       0xFF
#define PMIC_RG_VS1_ZXOS_TRIM_SHIFT                      0
#define PMIC_RG_VS1_MODESET_MASK                         0x1
#define PMIC_RG_VS1_MODESET_SHIFT                        8
#define PMIC_RG_VS1_PFM_RIP_MASK                         0x7
#define PMIC_RG_VS1_PFM_RIP_SHIFT                        9
#define PMIC_RG_VS1_TRAN_BST_MASK                        0x3F
#define PMIC_RG_VS1_TRAN_BST_SHIFT                       0
#define PMIC_RG_VS1_DTS_ENB_MASK                         0x1
#define PMIC_RG_VS1_DTS_ENB_SHIFT                        6
#define PMIC_RG_VS1_AUTO_MODE_MASK                       0x1
#define PMIC_RG_VS1_AUTO_MODE_SHIFT                      7
#define PMIC_RG_VS1_PWM_TRIG_MASK                        0x1
#define PMIC_RG_VS1_PWM_TRIG_SHIFT                       8
#define PMIC_RG_VS1_RSV_H_MASK                           0xF
#define PMIC_RG_VS1_RSV_H_SHIFT                          9
#define PMIC_RG_VS1_RSV_L_MASK                           0xF
#define PMIC_RG_VS1_RSV_L_SHIFT                          0
#define PMIC_RG_VS1_NONAUDIBLE_EN_MASK                   0x1
#define PMIC_RG_VS1_NONAUDIBLE_EN_SHIFT                  4
#define PMIC_RG_VS1_SR_P_MASK                            0x3
#define PMIC_RG_VS1_SR_P_SHIFT                           5
#define PMIC_RG_VS1_SR_N_MASK                            0x3
#define PMIC_RG_VS1_SR_N_SHIFT                           7
#define PMIC_RG_VS1_BURST_MASK                           0x7
#define PMIC_RG_VS1_BURST_SHIFT                          9
#define PMIC_RGS_VS1_ENPWM_STATUS_MASK                   0x1
#define PMIC_RGS_VS1_ENPWM_STATUS_SHIFT                  12
#define PMIC_RGS_VS1_OC_STATUS_MASK                      0x1
#define PMIC_RGS_VS1_OC_STATUS_SHIFT                     13
#define PMIC_RGS_VS1_DIG_MON_MASK                        0xF
#define PMIC_RGS_VS1_DIG_MON_SHIFT                       0
#define PMIC_RG_VS2_MIN_OFF_MASK                         0x3
#define PMIC_RG_VS2_MIN_OFF_SHIFT                        0
#define PMIC_RG_VS2_VRF18_SSTART_EN_MASK                 0x1
#define PMIC_RG_VS2_VRF18_SSTART_EN_SHIFT                2
#define PMIC_RG_VS2_1P35UP_SEL_EN_MASK                   0x1
#define PMIC_RG_VS2_1P35UP_SEL_EN_SHIFT                  3
#define PMIC_RG_VS2_RZSEL_MASK                           0x7
#define PMIC_RG_VS2_RZSEL_SHIFT                          4
#define PMIC_RG_VS2_CSR_MASK                             0x7
#define PMIC_RG_VS2_CSR_SHIFT                            7
#define PMIC_RG_VS2_CSL_MASK                             0xF
#define PMIC_RG_VS2_CSL_SHIFT                            10
#define PMIC_RG_VS2_SLP_MASK                             0x7
#define PMIC_RG_VS2_SLP_SHIFT                            0
#define PMIC_RG_VS2_ZX_OS_MASK                           0xF
#define PMIC_RG_VS2_ZX_OS_SHIFT                          3
#define PMIC_RG_VS2_NDIS_EN_MASK                         0x1
#define PMIC_RG_VS2_NDIS_EN_SHIFT                        7
#define PMIC_RG_VS2_CSM_N_MASK                           0x3F
#define PMIC_RG_VS2_CSM_N_SHIFT                          8
#define PMIC_RG_VS2_CSM_P_MASK                           0x3F
#define PMIC_RG_VS2_CSM_P_SHIFT                          0
#define PMIC_RG_VS2_RSV_MASK                             0xFF
#define PMIC_RG_VS2_RSV_SHIFT                            6
#define PMIC_RG_VS2_ZXOS_TRIM_MASK                       0xFF
#define PMIC_RG_VS2_ZXOS_TRIM_SHIFT                      0
#define PMIC_RG_VS2_MODESET_MASK                         0x1
#define PMIC_RG_VS2_MODESET_SHIFT                        8
#define PMIC_RG_VS2_PFM_RIP_MASK                         0x7
#define PMIC_RG_VS2_PFM_RIP_SHIFT                        9
#define PMIC_RG_VS2_TRAN_BST_MASK                        0x3F
#define PMIC_RG_VS2_TRAN_BST_SHIFT                       0
#define PMIC_RG_VS2_DTS_ENB_MASK                         0x1
#define PMIC_RG_VS2_DTS_ENB_SHIFT                        6
#define PMIC_RG_VS2_AUTO_MODE_MASK                       0x1
#define PMIC_RG_VS2_AUTO_MODE_SHIFT                      7
#define PMIC_RG_VS2_PWM_TRIG_MASK                        0x1
#define PMIC_RG_VS2_PWM_TRIG_SHIFT                       8
#define PMIC_RG_VS2_RSV_H_MASK                           0xF
#define PMIC_RG_VS2_RSV_H_SHIFT                          9
#define PMIC_RG_VS2_RSV_L_MASK                           0xF
#define PMIC_RG_VS2_RSV_L_SHIFT                          0
#define PMIC_RG_VS2_NONAUDIBLE_EN_MASK                   0x1
#define PMIC_RG_VS2_NONAUDIBLE_EN_SHIFT                  4
#define PMIC_RG_VS2_SR_P_MASK                            0x3
#define PMIC_RG_VS2_SR_P_SHIFT                           5
#define PMIC_RG_VS2_SR_N_MASK                            0x3
#define PMIC_RG_VS2_SR_N_SHIFT                           7
#define PMIC_RG_VS2_BURST_MASK                           0x7
#define PMIC_RG_VS2_BURST_SHIFT                          9
#define PMIC_RGS_VS2_ENPWM_STATUS_MASK                   0x1
#define PMIC_RGS_VS2_ENPWM_STATUS_SHIFT                  12
#define PMIC_RGS_VS2_OC_STATUS_MASK                      0x1
#define PMIC_RGS_VS2_OC_STATUS_SHIFT                     13
#define PMIC_RGS_VS2_DIG_MON_MASK                        0xF
#define PMIC_RGS_VS2_DIG_MON_SHIFT                       0
#define PMIC_RG_VPA_NDIS_EN_MASK                         0x1
#define PMIC_RG_VPA_NDIS_EN_SHIFT                        1
#define PMIC_RG_VPA_MODESET_MASK                         0x1
#define PMIC_RG_VPA_MODESET_SHIFT                        3
#define PMIC_RG_VPA_CC_MASK                              0x3
#define PMIC_RG_VPA_CC_SHIFT                             0
#define PMIC_RG_VPA_CSR_MASK                             0x3
#define PMIC_RG_VPA_CSR_SHIFT                            2
#define PMIC_RG_VPA_CSMIR_MASK                           0x3
#define PMIC_RG_VPA_CSMIR_SHIFT                          4
#define PMIC_RG_VPA_CSL_MASK                             0x3
#define PMIC_RG_VPA_CSL_SHIFT                            6
#define PMIC_RG_VPA_SLP_MASK                             0x3
#define PMIC_RG_VPA_SLP_SHIFT                            8
#define PMIC_RG_VPA_AZC_EN_MASK                          0x1
#define PMIC_RG_VPA_AZC_EN_SHIFT                         10
#define PMIC_RG_VPA_CP_FWUPOFF_MASK                      0x1
#define PMIC_RG_VPA_CP_FWUPOFF_SHIFT                     11
#define PMIC_RG_VPA_AZC_DELAY_MASK                       0x3
#define PMIC_RG_VPA_AZC_DELAY_SHIFT                      12
#define PMIC_RG_VPA_RZSEL_MASK                           0x3
#define PMIC_RG_VPA_RZSEL_SHIFT                          14
#define PMIC_RG_VPA_ZXREF_MASK                           0xFF
#define PMIC_RG_VPA_ZXREF_SHIFT                          0
#define PMIC_RG_VPA_NLIM_SEL_MASK                        0xF
#define PMIC_RG_VPA_NLIM_SEL_SHIFT                       8
#define PMIC_RG_VPA_HZP_MASK                             0x1
#define PMIC_RG_VPA_HZP_SHIFT                            12
#define PMIC_RG_VPA_BWEX_GAT_MASK                        0x1
#define PMIC_RG_VPA_BWEX_GAT_SHIFT                       13
#define PMIC_RG_VPA_SLEW_MASK                            0x3
#define PMIC_RG_VPA_SLEW_SHIFT                           14
#define PMIC_RG_VPA_SLEW_NMOS_MASK                       0x3
#define PMIC_RG_VPA_SLEW_NMOS_SHIFT                      0
#define PMIC_RG_VPA_MIN_ON_MASK                          0x3
#define PMIC_RG_VPA_MIN_ON_SHIFT                         2
#define PMIC_RG_VPA_VBAT_DEL_MASK                        0x3
#define PMIC_RG_VPA_VBAT_DEL_SHIFT                       4
#define PMIC_RGS_VPA_AZC_VOS_SEL_MASK                    0xFF
#define PMIC_RGS_VPA_AZC_VOS_SEL_SHIFT                   6
#define PMIC_RG_VPA_MIN_PK_MASK                          0x3
#define PMIC_RG_VPA_MIN_PK_SHIFT                         14
#define PMIC_RG_VPA_RSV1_MASK                            0xFF
#define PMIC_RG_VPA_RSV1_SHIFT                           0
#define PMIC_RG_VPA_RSV2_MASK                            0xFF
#define PMIC_RG_VPA_RSV2_SHIFT                           8
#define PMIC_RGS_VPA_OC_STATUS_MASK                      0x1
#define PMIC_RGS_VPA_OC_STATUS_SHIFT                     0
#define PMIC_RGS_VPA_AZC_ZX_MASK                         0x1
#define PMIC_RGS_VPA_AZC_ZX_SHIFT                        1
#define PMIC_WDTDBG_CLR_MASK                             0x1
#define PMIC_WDTDBG_CLR_SHIFT                            0
#define PMIC_WDTDBG_CON0_RSV0_MASK                       0x1
#define PMIC_WDTDBG_CON0_RSV0_SHIFT                      1
#define PMIC_VPROC11_VOSEL_WDTDBG_MASK                   0x7F
#define PMIC_VPROC11_VOSEL_WDTDBG_SHIFT                  0
#define PMIC_VPROC12_VOSEL_WDTDBG_MASK                   0x7F
#define PMIC_VPROC12_VOSEL_WDTDBG_SHIFT                  8
#define PMIC_VCORE_VOSEL_WDTDBG_MASK                     0x7F
#define PMIC_VCORE_VOSEL_WDTDBG_SHIFT                    0
#define PMIC_VGPU_VOSEL_WDTDBG_MASK                      0x7F
#define PMIC_VGPU_VOSEL_WDTDBG_SHIFT                     8
#define PMIC_VDRAM1_VOSEL_WDTDBG_MASK                    0x7F
#define PMIC_VDRAM1_VOSEL_WDTDBG_SHIFT                   0
#define PMIC_VDRAM2_VOSEL_WDTDBG_MASK                    0x7F
#define PMIC_VDRAM2_VOSEL_WDTDBG_SHIFT                   8
#define PMIC_VMODEM_VOSEL_WDTDBG_MASK                    0x7F
#define PMIC_VMODEM_VOSEL_WDTDBG_SHIFT                   0
#define PMIC_VS1_VOSEL_WDTDBG_MASK                       0x7F
#define PMIC_VS1_VOSEL_WDTDBG_SHIFT                      8
#define PMIC_VS2_VOSEL_WDTDBG_MASK                       0x7F
#define PMIC_VS2_VOSEL_WDTDBG_SHIFT                      0
#define PMIC_VPA_VOSEL_WDTDBG_MASK                       0x7F
#define PMIC_VPA_VOSEL_WDTDBG_SHIFT                      8
#define PMIC_VSRAM_PROC_VOSEL_WDTDBG_MASK                0x7F
#define PMIC_VSRAM_PROC_VOSEL_WDTDBG_SHIFT               0
#define PMIC_VSRAM_CORE_VOSEL_WDTDBG_MASK                0x7F
#define PMIC_VSRAM_CORE_VOSEL_WDTDBG_SHIFT               8
#define PMIC_VSRAM_GPU_VOSEL_WDTDBG_MASK                 0x7F
#define PMIC_VSRAM_GPU_VOSEL_WDTDBG_SHIFT                0
#define PMIC_VSRAM_MD_VOSEL_WDTDBG_MASK                  0x7F
#define PMIC_VSRAM_MD_VOSEL_WDTDBG_SHIFT                 8
#define PMIC_RG_LDO_VIO28_EN_MASK                        0x1
#define PMIC_RG_LDO_VIO28_EN_SHIFT                       0
#define PMIC_RG_LDO_VIO28_LP_MASK                        0x1
#define PMIC_RG_LDO_VIO28_LP_SHIFT                       1
#define PMIC_RG_LDO_VIO28_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VIO28_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VIO28_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VIO28_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VIO28_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VIO28_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VIO28_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VIO28_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VIO28_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VIO28_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VIO28_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VIO28_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VIO28_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VIO28_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VIO28_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VIO28_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VIO28_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VIO28_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VIO28_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VIO28_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VIO28_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VIO28_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VIO28_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VIO28_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VIO28_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VIO28_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VIO28_MODE_MASK                       0x1
#define PMIC_DA_QI_VIO28_MODE_SHIFT                      8
#define PMIC_RG_LDO_VIO28_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VIO28_STBTD_SHIFT                    9
#define PMIC_DA_QI_VIO28_STB_MASK                        0x1
#define PMIC_DA_QI_VIO28_STB_SHIFT                       14
#define PMIC_DA_QI_VIO28_EN_MASK                         0x1
#define PMIC_DA_QI_VIO28_EN_SHIFT                        15
#define PMIC_RG_LDO_VIO28_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VIO28_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VIO28_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VIO28_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VIO28_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VIO28_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VIO28_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VIO28_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VIO18_EN_MASK                        0x1
#define PMIC_RG_LDO_VIO18_EN_SHIFT                       0
#define PMIC_RG_LDO_VIO18_LP_MASK                        0x1
#define PMIC_RG_LDO_VIO18_LP_SHIFT                       1
#define PMIC_RG_LDO_VIO18_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VIO18_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VIO18_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VIO18_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VIO18_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VIO18_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VIO18_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VIO18_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VIO18_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VIO18_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VIO18_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VIO18_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VIO18_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VIO18_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VIO18_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VIO18_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VIO18_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VIO18_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VIO18_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VIO18_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VIO18_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VIO18_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VIO18_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VIO18_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VIO18_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VIO18_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VIO18_MODE_MASK                       0x1
#define PMIC_DA_QI_VIO18_MODE_SHIFT                      8
#define PMIC_RG_LDO_VIO18_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VIO18_STBTD_SHIFT                    9
#define PMIC_DA_QI_VIO18_STB_MASK                        0x1
#define PMIC_DA_QI_VIO18_STB_SHIFT                       14
#define PMIC_DA_QI_VIO18_EN_MASK                         0x1
#define PMIC_DA_QI_VIO18_EN_SHIFT                        15
#define PMIC_RG_LDO_VIO18_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VIO18_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VIO18_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VIO18_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VIO18_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VIO18_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VIO18_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VIO18_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VUFS18_EN_MASK                       0x1
#define PMIC_RG_LDO_VUFS18_EN_SHIFT                      0
#define PMIC_RG_LDO_VUFS18_LP_MASK                       0x1
#define PMIC_RG_LDO_VUFS18_LP_SHIFT                      1
#define PMIC_RG_LDO_VUFS18_SW_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VUFS18_SW_OP_EN_SHIFT                0
#define PMIC_RG_LDO_VUFS18_HW0_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VUFS18_HW0_OP_EN_SHIFT               1
#define PMIC_RG_LDO_VUFS18_HW1_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VUFS18_HW1_OP_EN_SHIFT               2
#define PMIC_RG_LDO_VUFS18_HW2_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VUFS18_HW2_OP_EN_SHIFT               3
#define PMIC_RG_LDO_VUFS18_OP_EN_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VUFS18_OP_EN_SET_SHIFT               0
#define PMIC_RG_LDO_VUFS18_OP_EN_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VUFS18_OP_EN_CLR_SHIFT               0
#define PMIC_RG_LDO_VUFS18_HW0_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VUFS18_HW0_OP_CFG_SHIFT              1
#define PMIC_RG_LDO_VUFS18_HW1_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VUFS18_HW1_OP_CFG_SHIFT              2
#define PMIC_RG_LDO_VUFS18_HW2_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VUFS18_HW2_OP_CFG_SHIFT              3
#define PMIC_RG_LDO_VUFS18_ON_OP_MASK                    0x1
#define PMIC_RG_LDO_VUFS18_ON_OP_SHIFT                   8
#define PMIC_RG_LDO_VUFS18_LP_OP_MASK                    0x1
#define PMIC_RG_LDO_VUFS18_LP_OP_SHIFT                   9
#define PMIC_RG_LDO_VUFS18_OP_CFG_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VUFS18_OP_CFG_SET_SHIFT              0
#define PMIC_RG_LDO_VUFS18_OP_CFG_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VUFS18_OP_CFG_CLR_SHIFT              0
#define PMIC_DA_QI_VUFS18_MODE_MASK                      0x1
#define PMIC_DA_QI_VUFS18_MODE_SHIFT                     8
#define PMIC_RG_LDO_VUFS18_STBTD_MASK                    0x3
#define PMIC_RG_LDO_VUFS18_STBTD_SHIFT                   9
#define PMIC_DA_QI_VUFS18_STB_MASK                       0x1
#define PMIC_DA_QI_VUFS18_STB_SHIFT                      14
#define PMIC_DA_QI_VUFS18_EN_MASK                        0x1
#define PMIC_DA_QI_VUFS18_EN_SHIFT                       15
#define PMIC_RG_LDO_VUFS18_OCFB_EN_MASK                  0x1
#define PMIC_RG_LDO_VUFS18_OCFB_EN_SHIFT                 9
#define PMIC_DA_QI_VUFS18_OCFB_EN_MASK                   0x1
#define PMIC_DA_QI_VUFS18_OCFB_EN_SHIFT                  10
#define PMIC_RG_LDO_VUFS18_DUMMY_LOAD_MASK               0x3
#define PMIC_RG_LDO_VUFS18_DUMMY_LOAD_SHIFT              5
#define PMIC_DA_QI_VUFS18_DUMMY_LOAD_MASK                0x3
#define PMIC_DA_QI_VUFS18_DUMMY_LOAD_SHIFT               14
#define PMIC_RG_LDO_VA10_EN_MASK                         0x1
#define PMIC_RG_LDO_VA10_EN_SHIFT                        0
#define PMIC_RG_LDO_VA10_LP_MASK                         0x1
#define PMIC_RG_LDO_VA10_LP_SHIFT                        1
#define PMIC_RG_VA10_VOCAL_MASK                          0xF
#define PMIC_RG_VA10_VOCAL_SHIFT                         0
#define PMIC_RG_VA10_VOSEL_MASK                          0xF
#define PMIC_RG_VA10_VOSEL_SHIFT                         8
#define PMIC_RG_LDO_VA10_SW_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VA10_SW_OP_EN_SHIFT                  0
#define PMIC_RG_LDO_VA10_HW0_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VA10_HW0_OP_EN_SHIFT                 1
#define PMIC_RG_LDO_VA10_HW1_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VA10_HW1_OP_EN_SHIFT                 2
#define PMIC_RG_LDO_VA10_HW2_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VA10_HW2_OP_EN_SHIFT                 3
#define PMIC_RG_LDO_VA10_OP_EN_SET_MASK                  0xFFFF
#define PMIC_RG_LDO_VA10_OP_EN_SET_SHIFT                 0
#define PMIC_RG_LDO_VA10_OP_EN_CLR_MASK                  0xFFFF
#define PMIC_RG_LDO_VA10_OP_EN_CLR_SHIFT                 0
#define PMIC_RG_LDO_VA10_HW0_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VA10_HW0_OP_CFG_SHIFT                1
#define PMIC_RG_LDO_VA10_HW1_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VA10_HW1_OP_CFG_SHIFT                2
#define PMIC_RG_LDO_VA10_HW2_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VA10_HW2_OP_CFG_SHIFT                3
#define PMIC_RG_LDO_VA10_ON_OP_MASK                      0x1
#define PMIC_RG_LDO_VA10_ON_OP_SHIFT                     8
#define PMIC_RG_LDO_VA10_LP_OP_MASK                      0x1
#define PMIC_RG_LDO_VA10_LP_OP_SHIFT                     9
#define PMIC_RG_LDO_VA10_OP_CFG_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VA10_OP_CFG_SET_SHIFT                0
#define PMIC_RG_LDO_VA10_OP_CFG_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VA10_OP_CFG_CLR_SHIFT                0
#define PMIC_DA_QI_VA10_MODE_MASK                        0x1
#define PMIC_DA_QI_VA10_MODE_SHIFT                       8
#define PMIC_RG_LDO_VA10_STBTD_MASK                      0x3
#define PMIC_RG_LDO_VA10_STBTD_SHIFT                     9
#define PMIC_DA_QI_VA10_STB_MASK                         0x1
#define PMIC_DA_QI_VA10_STB_SHIFT                        14
#define PMIC_DA_QI_VA10_EN_MASK                          0x1
#define PMIC_DA_QI_VA10_EN_SHIFT                         15
#define PMIC_RG_LDO_VA10_SLEEP_MODE_MASK                 0x1
#define PMIC_RG_LDO_VA10_SLEEP_MODE_SHIFT                1
#define PMIC_RG_LDO_VA10_OCFB_EN_MASK                    0x1
#define PMIC_RG_LDO_VA10_OCFB_EN_SHIFT                   9
#define PMIC_DA_QI_VA10_OCFB_EN_MASK                     0x1
#define PMIC_DA_QI_VA10_OCFB_EN_SHIFT                    10
#define PMIC_RG_LDO_VA10_DUMMY_LOAD_MASK                 0x3
#define PMIC_RG_LDO_VA10_DUMMY_LOAD_SHIFT                5
#define PMIC_DA_QI_VA10_DUMMY_LOAD_MASK                  0x3
#define PMIC_DA_QI_VA10_DUMMY_LOAD_SHIFT                 14
#define PMIC_RG_LDO_VA12_EN_MASK                         0x1
#define PMIC_RG_LDO_VA12_EN_SHIFT                        0
#define PMIC_RG_LDO_VA12_LP_MASK                         0x1
#define PMIC_RG_LDO_VA12_LP_SHIFT                        1
#define PMIC_RG_LDO_VA12_SW_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VA12_SW_OP_EN_SHIFT                  0
#define PMIC_RG_LDO_VA12_HW0_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VA12_HW0_OP_EN_SHIFT                 1
#define PMIC_RG_LDO_VA12_HW1_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VA12_HW1_OP_EN_SHIFT                 2
#define PMIC_RG_LDO_VA12_HW2_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VA12_HW2_OP_EN_SHIFT                 3
#define PMIC_RG_LDO_VA12_OP_EN_SET_MASK                  0xFFFF
#define PMIC_RG_LDO_VA12_OP_EN_SET_SHIFT                 0
#define PMIC_RG_LDO_VA12_OP_EN_CLR_MASK                  0xFFFF
#define PMIC_RG_LDO_VA12_OP_EN_CLR_SHIFT                 0
#define PMIC_RG_LDO_VA12_HW0_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VA12_HW0_OP_CFG_SHIFT                1
#define PMIC_RG_LDO_VA12_HW1_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VA12_HW1_OP_CFG_SHIFT                2
#define PMIC_RG_LDO_VA12_HW2_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VA12_HW2_OP_CFG_SHIFT                3
#define PMIC_RG_LDO_VA12_ON_OP_MASK                      0x1
#define PMIC_RG_LDO_VA12_ON_OP_SHIFT                     8
#define PMIC_RG_LDO_VA12_LP_OP_MASK                      0x1
#define PMIC_RG_LDO_VA12_LP_OP_SHIFT                     9
#define PMIC_RG_LDO_VA12_OP_CFG_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VA12_OP_CFG_SET_SHIFT                0
#define PMIC_RG_LDO_VA12_OP_CFG_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VA12_OP_CFG_CLR_SHIFT                0
#define PMIC_DA_QI_VA12_MODE_MASK                        0x1
#define PMIC_DA_QI_VA12_MODE_SHIFT                       8
#define PMIC_RG_LDO_VA12_STBTD_MASK                      0x3
#define PMIC_RG_LDO_VA12_STBTD_SHIFT                     9
#define PMIC_DA_QI_VA12_STB_MASK                         0x1
#define PMIC_DA_QI_VA12_STB_SHIFT                        14
#define PMIC_DA_QI_VA12_EN_MASK                          0x1
#define PMIC_DA_QI_VA12_EN_SHIFT                         15
#define PMIC_RG_LDO_VA12_OCFB_EN_MASK                    0x1
#define PMIC_RG_LDO_VA12_OCFB_EN_SHIFT                   9
#define PMIC_DA_QI_VA12_OCFB_EN_MASK                     0x1
#define PMIC_DA_QI_VA12_OCFB_EN_SHIFT                    10
#define PMIC_RG_LDO_VA12_DUMMY_LOAD_MASK                 0x3
#define PMIC_RG_LDO_VA12_DUMMY_LOAD_SHIFT                5
#define PMIC_DA_QI_VA12_DUMMY_LOAD_MASK                  0x3
#define PMIC_DA_QI_VA12_DUMMY_LOAD_SHIFT                 14
#define PMIC_RG_LDO_VA18_EN_MASK                         0x1
#define PMIC_RG_LDO_VA18_EN_SHIFT                        0
#define PMIC_RG_LDO_VA18_LP_MASK                         0x1
#define PMIC_RG_LDO_VA18_LP_SHIFT                        1
#define PMIC_RG_LDO_VA18_SW_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VA18_SW_OP_EN_SHIFT                  0
#define PMIC_RG_LDO_VA18_HW0_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VA18_HW0_OP_EN_SHIFT                 1
#define PMIC_RG_LDO_VA18_HW1_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VA18_HW1_OP_EN_SHIFT                 2
#define PMIC_RG_LDO_VA18_HW2_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VA18_HW2_OP_EN_SHIFT                 3
#define PMIC_RG_LDO_VA18_OP_EN_SET_MASK                  0xFFFF
#define PMIC_RG_LDO_VA18_OP_EN_SET_SHIFT                 0
#define PMIC_RG_LDO_VA18_OP_EN_CLR_MASK                  0xFFFF
#define PMIC_RG_LDO_VA18_OP_EN_CLR_SHIFT                 0
#define PMIC_RG_LDO_VA18_HW0_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VA18_HW0_OP_CFG_SHIFT                1
#define PMIC_RG_LDO_VA18_HW1_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VA18_HW1_OP_CFG_SHIFT                2
#define PMIC_RG_LDO_VA18_HW2_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VA18_HW2_OP_CFG_SHIFT                3
#define PMIC_RG_LDO_VA18_ON_OP_MASK                      0x1
#define PMIC_RG_LDO_VA18_ON_OP_SHIFT                     8
#define PMIC_RG_LDO_VA18_LP_OP_MASK                      0x1
#define PMIC_RG_LDO_VA18_LP_OP_SHIFT                     9
#define PMIC_RG_LDO_VA18_OP_CFG_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VA18_OP_CFG_SET_SHIFT                0
#define PMIC_RG_LDO_VA18_OP_CFG_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VA18_OP_CFG_CLR_SHIFT                0
#define PMIC_DA_QI_VA18_MODE_MASK                        0x1
#define PMIC_DA_QI_VA18_MODE_SHIFT                       8
#define PMIC_RG_LDO_VA18_STBTD_MASK                      0x3
#define PMIC_RG_LDO_VA18_STBTD_SHIFT                     9
#define PMIC_DA_QI_VA18_STB_MASK                         0x1
#define PMIC_DA_QI_VA18_STB_SHIFT                        14
#define PMIC_DA_QI_VA18_EN_MASK                          0x1
#define PMIC_DA_QI_VA18_EN_SHIFT                         15
#define PMIC_RG_LDO_VA18_AUXADC_PWDB_EN_MASK             0x1
#define PMIC_RG_LDO_VA18_AUXADC_PWDB_EN_SHIFT            2
#define PMIC_RG_LDO_VA18_OCFB_EN_MASK                    0x1
#define PMIC_RG_LDO_VA18_OCFB_EN_SHIFT                   9
#define PMIC_DA_QI_VA18_OCFB_EN_MASK                     0x1
#define PMIC_DA_QI_VA18_OCFB_EN_SHIFT                    10
#define PMIC_RG_LDO_VA18_DUMMY_LOAD_MASK                 0x3
#define PMIC_RG_LDO_VA18_DUMMY_LOAD_SHIFT                5
#define PMIC_DA_QI_VA18_DUMMY_LOAD_MASK                  0x3
#define PMIC_DA_QI_VA18_DUMMY_LOAD_SHIFT                 14
#define PMIC_RG_LDO_VUSB33_EN_0_MASK                     0x1
#define PMIC_RG_LDO_VUSB33_EN_0_SHIFT                    0
#define PMIC_RG_LDO_VUSB33_LP_MASK                       0x1
#define PMIC_RG_LDO_VUSB33_LP_SHIFT                      1
#define PMIC_RG_LDO_VUSB33_SW_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VUSB33_SW_OP_EN_SHIFT                0
#define PMIC_RG_LDO_VUSB33_HW0_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VUSB33_HW0_OP_EN_SHIFT               1
#define PMIC_RG_LDO_VUSB33_HW1_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VUSB33_HW1_OP_EN_SHIFT               2
#define PMIC_RG_LDO_VUSB33_HW2_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VUSB33_HW2_OP_EN_SHIFT               3
#define PMIC_RG_LDO_VUSB33_OP_EN_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VUSB33_OP_EN_SET_SHIFT               0
#define PMIC_RG_LDO_VUSB33_OP_EN_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VUSB33_OP_EN_CLR_SHIFT               0
#define PMIC_RG_LDO_VUSB33_HW0_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VUSB33_HW0_OP_CFG_SHIFT              1
#define PMIC_RG_LDO_VUSB33_HW1_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VUSB33_HW1_OP_CFG_SHIFT              2
#define PMIC_RG_LDO_VUSB33_HW2_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VUSB33_HW2_OP_CFG_SHIFT              3
#define PMIC_RG_LDO_VUSB33_ON_OP_MASK                    0x1
#define PMIC_RG_LDO_VUSB33_ON_OP_SHIFT                   8
#define PMIC_RG_LDO_VUSB33_LP_OP_MASK                    0x1
#define PMIC_RG_LDO_VUSB33_LP_OP_SHIFT                   9
#define PMIC_RG_LDO_VUSB33_OP_CFG_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VUSB33_OP_CFG_SET_SHIFT              0
#define PMIC_RG_LDO_VUSB33_OP_CFG_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VUSB33_OP_CFG_CLR_SHIFT              0
#define PMIC_RG_LDO_VUSB33_EN_1_MASK                     0x1
#define PMIC_RG_LDO_VUSB33_EN_1_SHIFT                    0
#define PMIC_DA_QI_VUSB33_MODE_MASK                      0x1
#define PMIC_DA_QI_VUSB33_MODE_SHIFT                     8
#define PMIC_RG_LDO_VUSB33_STBTD_MASK                    0x3
#define PMIC_RG_LDO_VUSB33_STBTD_SHIFT                   9
#define PMIC_DA_QI_VUSB33_STB_MASK                       0x1
#define PMIC_DA_QI_VUSB33_STB_SHIFT                      14
#define PMIC_DA_QI_VUSB33_EN_MASK                        0x1
#define PMIC_DA_QI_VUSB33_EN_SHIFT                       15
#define PMIC_RG_LDO_VUSB33_OCFB_EN_MASK                  0x1
#define PMIC_RG_LDO_VUSB33_OCFB_EN_SHIFT                 9
#define PMIC_DA_QI_VUSB33_OCFB_EN_MASK                   0x1
#define PMIC_DA_QI_VUSB33_OCFB_EN_SHIFT                  10
#define PMIC_RG_LDO_VUSB33_DUMMY_LOAD_MASK               0x3
#define PMIC_RG_LDO_VUSB33_DUMMY_LOAD_SHIFT              5
#define PMIC_DA_QI_VUSB33_DUMMY_LOAD_MASK                0x3
#define PMIC_DA_QI_VUSB33_DUMMY_LOAD_SHIFT               14
#define PMIC_RG_LDO_VEMC_EN_MASK                         0x1
#define PMIC_RG_LDO_VEMC_EN_SHIFT                        0
#define PMIC_RG_LDO_VEMC_LP_MASK                         0x1
#define PMIC_RG_LDO_VEMC_LP_SHIFT                        1
#define PMIC_RG_LDO_VEMC_SW_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VEMC_SW_OP_EN_SHIFT                  0
#define PMIC_RG_LDO_VEMC_HW0_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VEMC_HW0_OP_EN_SHIFT                 1
#define PMIC_RG_LDO_VEMC_HW1_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VEMC_HW1_OP_EN_SHIFT                 2
#define PMIC_RG_LDO_VEMC_HW2_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VEMC_HW2_OP_EN_SHIFT                 3
#define PMIC_RG_LDO_VEMC_OP_EN_SET_MASK                  0xFFFF
#define PMIC_RG_LDO_VEMC_OP_EN_SET_SHIFT                 0
#define PMIC_RG_LDO_VEMC_OP_EN_CLR_MASK                  0xFFFF
#define PMIC_RG_LDO_VEMC_OP_EN_CLR_SHIFT                 0
#define PMIC_RG_LDO_VEMC_HW0_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VEMC_HW0_OP_CFG_SHIFT                1
#define PMIC_RG_LDO_VEMC_HW1_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VEMC_HW1_OP_CFG_SHIFT                2
#define PMIC_RG_LDO_VEMC_HW2_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VEMC_HW2_OP_CFG_SHIFT                3
#define PMIC_RG_LDO_VEMC_ON_OP_MASK                      0x1
#define PMIC_RG_LDO_VEMC_ON_OP_SHIFT                     8
#define PMIC_RG_LDO_VEMC_LP_OP_MASK                      0x1
#define PMIC_RG_LDO_VEMC_LP_OP_SHIFT                     9
#define PMIC_RG_LDO_VEMC_OP_CFG_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VEMC_OP_CFG_SET_SHIFT                0
#define PMIC_RG_LDO_VEMC_OP_CFG_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VEMC_OP_CFG_CLR_SHIFT                0
#define PMIC_DA_QI_VEMC_MODE_MASK                        0x1
#define PMIC_DA_QI_VEMC_MODE_SHIFT                       8
#define PMIC_RG_LDO_VEMC_STBTD_MASK                      0x3
#define PMIC_RG_LDO_VEMC_STBTD_SHIFT                     9
#define PMIC_DA_QI_VEMC_STB_MASK                         0x1
#define PMIC_DA_QI_VEMC_STB_SHIFT                        14
#define PMIC_DA_QI_VEMC_EN_MASK                          0x1
#define PMIC_DA_QI_VEMC_EN_SHIFT                         15
#define PMIC_RG_LDO_VEMC_OCFB_EN_MASK                    0x1
#define PMIC_RG_LDO_VEMC_OCFB_EN_SHIFT                   9
#define PMIC_DA_QI_VEMC_OCFB_EN_MASK                     0x1
#define PMIC_DA_QI_VEMC_OCFB_EN_SHIFT                    10
#define PMIC_RG_LDO_VEMC_DUMMY_LOAD_MASK                 0x3
#define PMIC_RG_LDO_VEMC_DUMMY_LOAD_SHIFT                5
#define PMIC_DA_QI_VEMC_DUMMY_LOAD_MASK                  0x3
#define PMIC_DA_QI_VEMC_DUMMY_LOAD_SHIFT                 14
#define PMIC_RG_LDO_VXO22_EN_MASK                        0x1
#define PMIC_RG_LDO_VXO22_EN_SHIFT                       0
#define PMIC_RG_LDO_VXO22_LP_MASK                        0x1
#define PMIC_RG_LDO_VXO22_LP_SHIFT                       1
#define PMIC_RG_LDO_VXO22_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VXO22_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VXO22_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VXO22_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VXO22_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VXO22_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VXO22_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VXO22_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VXO22_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VXO22_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VXO22_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VXO22_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VXO22_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VXO22_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VXO22_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VXO22_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VXO22_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VXO22_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VXO22_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VXO22_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VXO22_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VXO22_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VXO22_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VXO22_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VXO22_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VXO22_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VXO22_MODE_MASK                       0x1
#define PMIC_DA_QI_VXO22_MODE_SHIFT                      8
#define PMIC_RG_LDO_VXO22_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VXO22_STBTD_SHIFT                    9
#define PMIC_DA_QI_VXO22_STB_MASK                        0x1
#define PMIC_DA_QI_VXO22_STB_SHIFT                       14
#define PMIC_DA_QI_VXO22_EN_MASK                         0x1
#define PMIC_DA_QI_VXO22_EN_SHIFT                        15
#define PMIC_RG_LDO_VXO22_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VXO22_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VXO22_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VXO22_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VXO22_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VXO22_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VXO22_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VXO22_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VXO18_EN_MASK                        0x1
#define PMIC_RG_LDO_VXO18_EN_SHIFT                       0
#define PMIC_RG_LDO_VXO18_LP_MASK                        0x1
#define PMIC_RG_LDO_VXO18_LP_SHIFT                       1
#define PMIC_RG_LDO_VXO18_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VXO18_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VXO18_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VXO18_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VXO18_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VXO18_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VXO18_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VXO18_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VXO18_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VXO18_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VXO18_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VXO18_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VXO18_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VXO18_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VXO18_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VXO18_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VXO18_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VXO18_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VXO18_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VXO18_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VXO18_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VXO18_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VXO18_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VXO18_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VXO18_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VXO18_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VXO18_MODE_MASK                       0x1
#define PMIC_DA_QI_VXO18_MODE_SHIFT                      8
#define PMIC_RG_LDO_VXO18_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VXO18_STBTD_SHIFT                    9
#define PMIC_DA_QI_VXO18_STB_MASK                        0x1
#define PMIC_DA_QI_VXO18_STB_SHIFT                       14
#define PMIC_DA_QI_VXO18_EN_MASK                         0x1
#define PMIC_DA_QI_VXO18_EN_SHIFT                        15
#define PMIC_RG_LDO_VXO18_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VXO18_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VXO18_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VXO18_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VXO18_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VXO18_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VXO18_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VXO18_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VSIM1_EN_MASK                        0x1
#define PMIC_RG_LDO_VSIM1_EN_SHIFT                       0
#define PMIC_RG_LDO_VSIM1_LP_MASK                        0x1
#define PMIC_RG_LDO_VSIM1_LP_SHIFT                       1
#define PMIC_RG_LDO_VSIM1_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VSIM1_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VSIM1_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VSIM1_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VSIM1_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VSIM1_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VSIM1_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VSIM1_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VSIM1_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VSIM1_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VSIM1_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VSIM1_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VSIM1_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VSIM1_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VSIM1_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VSIM1_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VSIM1_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VSIM1_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VSIM1_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VSIM1_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VSIM1_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VSIM1_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VSIM1_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VSIM1_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VSIM1_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VSIM1_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VSIM1_MODE_MASK                       0x1
#define PMIC_DA_QI_VSIM1_MODE_SHIFT                      8
#define PMIC_RG_LDO_VSIM1_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VSIM1_STBTD_SHIFT                    9
#define PMIC_DA_QI_VSIM1_STB_MASK                        0x1
#define PMIC_DA_QI_VSIM1_STB_SHIFT                       14
#define PMIC_DA_QI_VSIM1_EN_MASK                         0x1
#define PMIC_DA_QI_VSIM1_EN_SHIFT                        15
#define PMIC_RG_LDO_VSIM1_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VSIM1_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VSIM1_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VSIM1_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VSIM1_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VSIM1_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VSIM1_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VSIM1_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VSIM2_EN_MASK                        0x1
#define PMIC_RG_LDO_VSIM2_EN_SHIFT                       0
#define PMIC_RG_LDO_VSIM2_LP_MASK                        0x1
#define PMIC_RG_LDO_VSIM2_LP_SHIFT                       1
#define PMIC_RG_LDO_VSIM2_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VSIM2_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VSIM2_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VSIM2_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VSIM2_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VSIM2_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VSIM2_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VSIM2_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VSIM2_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VSIM2_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VSIM2_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VSIM2_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VSIM2_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VSIM2_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VSIM2_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VSIM2_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VSIM2_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VSIM2_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VSIM2_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VSIM2_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VSIM2_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VSIM2_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VSIM2_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VSIM2_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VSIM2_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VSIM2_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VSIM2_MODE_MASK                       0x1
#define PMIC_DA_QI_VSIM2_MODE_SHIFT                      8
#define PMIC_RG_LDO_VSIM2_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VSIM2_STBTD_SHIFT                    9
#define PMIC_DA_QI_VSIM2_STB_MASK                        0x1
#define PMIC_DA_QI_VSIM2_STB_SHIFT                       14
#define PMIC_DA_QI_VSIM2_EN_MASK                         0x1
#define PMIC_DA_QI_VSIM2_EN_SHIFT                        15
#define PMIC_RG_LDO_VSIM2_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VSIM2_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VSIM2_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VSIM2_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VSIM2_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VSIM2_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VSIM2_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VSIM2_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VCAMD1_EN_MASK                       0x1
#define PMIC_RG_LDO_VCAMD1_EN_SHIFT                      0
#define PMIC_RG_LDO_VCAMD1_LP_MASK                       0x1
#define PMIC_RG_LDO_VCAMD1_LP_SHIFT                      1
#define PMIC_RG_LDO_VCAMD1_SW_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCAMD1_SW_OP_EN_SHIFT                0
#define PMIC_RG_LDO_VCAMD1_HW0_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMD1_HW0_OP_EN_SHIFT               1
#define PMIC_RG_LDO_VCAMD1_HW1_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMD1_HW1_OP_EN_SHIFT               2
#define PMIC_RG_LDO_VCAMD1_HW2_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMD1_HW2_OP_EN_SHIFT               3
#define PMIC_RG_LDO_VCAMD1_OP_EN_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VCAMD1_OP_EN_SET_SHIFT               0
#define PMIC_RG_LDO_VCAMD1_OP_EN_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VCAMD1_OP_EN_CLR_SHIFT               0
#define PMIC_RG_LDO_VCAMD1_HW0_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMD1_HW0_OP_CFG_SHIFT              1
#define PMIC_RG_LDO_VCAMD1_HW1_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMD1_HW1_OP_CFG_SHIFT              2
#define PMIC_RG_LDO_VCAMD1_HW2_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMD1_HW2_OP_CFG_SHIFT              3
#define PMIC_RG_LDO_VCAMD1_ON_OP_MASK                    0x1
#define PMIC_RG_LDO_VCAMD1_ON_OP_SHIFT                   8
#define PMIC_RG_LDO_VCAMD1_LP_OP_MASK                    0x1
#define PMIC_RG_LDO_VCAMD1_LP_OP_SHIFT                   9
#define PMIC_RG_LDO_VCAMD1_OP_CFG_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VCAMD1_OP_CFG_SET_SHIFT              0
#define PMIC_RG_LDO_VCAMD1_OP_CFG_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VCAMD1_OP_CFG_CLR_SHIFT              0
#define PMIC_DA_QI_VCAMD1_MODE_MASK                      0x1
#define PMIC_DA_QI_VCAMD1_MODE_SHIFT                     8
#define PMIC_RG_LDO_VCAMD1_STBTD_MASK                    0x3
#define PMIC_RG_LDO_VCAMD1_STBTD_SHIFT                   9
#define PMIC_DA_QI_VCAMD1_STB_MASK                       0x1
#define PMIC_DA_QI_VCAMD1_STB_SHIFT                      14
#define PMIC_DA_QI_VCAMD1_EN_MASK                        0x1
#define PMIC_DA_QI_VCAMD1_EN_SHIFT                       15
#define PMIC_RG_LDO_VCAMD1_OCFB_EN_MASK                  0x1
#define PMIC_RG_LDO_VCAMD1_OCFB_EN_SHIFT                 9
#define PMIC_DA_QI_VCAMD1_OCFB_EN_MASK                   0x1
#define PMIC_DA_QI_VCAMD1_OCFB_EN_SHIFT                  10
#define PMIC_RG_LDO_VCAMD1_DUMMY_LOAD_MASK               0x3
#define PMIC_RG_LDO_VCAMD1_DUMMY_LOAD_SHIFT              5
#define PMIC_DA_QI_VCAMD1_DUMMY_LOAD_MASK                0x3
#define PMIC_DA_QI_VCAMD1_DUMMY_LOAD_SHIFT               14
#define PMIC_RG_LDO_VCAMD2_EN_MASK                       0x1
#define PMIC_RG_LDO_VCAMD2_EN_SHIFT                      0
#define PMIC_RG_LDO_VCAMD2_LP_MASK                       0x1
#define PMIC_RG_LDO_VCAMD2_LP_SHIFT                      1
#define PMIC_RG_LDO_VCAMD2_SW_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCAMD2_SW_OP_EN_SHIFT                0
#define PMIC_RG_LDO_VCAMD2_HW0_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMD2_HW0_OP_EN_SHIFT               1
#define PMIC_RG_LDO_VCAMD2_HW1_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMD2_HW1_OP_EN_SHIFT               2
#define PMIC_RG_LDO_VCAMD2_HW2_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMD2_HW2_OP_EN_SHIFT               3
#define PMIC_RG_LDO_VCAMD2_OP_EN_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VCAMD2_OP_EN_SET_SHIFT               0
#define PMIC_RG_LDO_VCAMD2_OP_EN_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VCAMD2_OP_EN_CLR_SHIFT               0
#define PMIC_RG_LDO_VCAMD2_HW0_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMD2_HW0_OP_CFG_SHIFT              1
#define PMIC_RG_LDO_VCAMD2_HW1_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMD2_HW1_OP_CFG_SHIFT              2
#define PMIC_RG_LDO_VCAMD2_HW2_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMD2_HW2_OP_CFG_SHIFT              3
#define PMIC_RG_LDO_VCAMD2_ON_OP_MASK                    0x1
#define PMIC_RG_LDO_VCAMD2_ON_OP_SHIFT                   8
#define PMIC_RG_LDO_VCAMD2_LP_OP_MASK                    0x1
#define PMIC_RG_LDO_VCAMD2_LP_OP_SHIFT                   9
#define PMIC_RG_LDO_VCAMD2_OP_CFG_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VCAMD2_OP_CFG_SET_SHIFT              0
#define PMIC_RG_LDO_VCAMD2_OP_CFG_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VCAMD2_OP_CFG_CLR_SHIFT              0
#define PMIC_DA_QI_VCAMD2_MODE_MASK                      0x1
#define PMIC_DA_QI_VCAMD2_MODE_SHIFT                     8
#define PMIC_RG_LDO_VCAMD2_STBTD_MASK                    0x3
#define PMIC_RG_LDO_VCAMD2_STBTD_SHIFT                   9
#define PMIC_DA_QI_VCAMD2_STB_MASK                       0x1
#define PMIC_DA_QI_VCAMD2_STB_SHIFT                      14
#define PMIC_DA_QI_VCAMD2_EN_MASK                        0x1
#define PMIC_DA_QI_VCAMD2_EN_SHIFT                       15
#define PMIC_RG_LDO_VCAMD2_OCFB_EN_MASK                  0x1
#define PMIC_RG_LDO_VCAMD2_OCFB_EN_SHIFT                 9
#define PMIC_DA_QI_VCAMD2_OCFB_EN_MASK                   0x1
#define PMIC_DA_QI_VCAMD2_OCFB_EN_SHIFT                  10
#define PMIC_RG_LDO_VCAMD2_DUMMY_LOAD_MASK               0x3
#define PMIC_RG_LDO_VCAMD2_DUMMY_LOAD_SHIFT              5
#define PMIC_DA_QI_VCAMD2_DUMMY_LOAD_MASK                0x3
#define PMIC_DA_QI_VCAMD2_DUMMY_LOAD_SHIFT               14
#define PMIC_RG_LDO_VCAMIO_EN_MASK                       0x1
#define PMIC_RG_LDO_VCAMIO_EN_SHIFT                      0
#define PMIC_RG_LDO_VCAMIO_LP_MASK                       0x1
#define PMIC_RG_LDO_VCAMIO_LP_SHIFT                      1
#define PMIC_RG_LDO_VCAMIO_SW_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCAMIO_SW_OP_EN_SHIFT                0
#define PMIC_RG_LDO_VCAMIO_HW0_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMIO_HW0_OP_EN_SHIFT               1
#define PMIC_RG_LDO_VCAMIO_HW1_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMIO_HW1_OP_EN_SHIFT               2
#define PMIC_RG_LDO_VCAMIO_HW2_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMIO_HW2_OP_EN_SHIFT               3
#define PMIC_RG_LDO_VCAMIO_OP_EN_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VCAMIO_OP_EN_SET_SHIFT               0
#define PMIC_RG_LDO_VCAMIO_OP_EN_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VCAMIO_OP_EN_CLR_SHIFT               0
#define PMIC_RG_LDO_VCAMIO_HW0_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMIO_HW0_OP_CFG_SHIFT              1
#define PMIC_RG_LDO_VCAMIO_HW1_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMIO_HW1_OP_CFG_SHIFT              2
#define PMIC_RG_LDO_VCAMIO_HW2_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMIO_HW2_OP_CFG_SHIFT              3
#define PMIC_RG_LDO_VCAMIO_ON_OP_MASK                    0x1
#define PMIC_RG_LDO_VCAMIO_ON_OP_SHIFT                   8
#define PMIC_RG_LDO_VCAMIO_LP_OP_MASK                    0x1
#define PMIC_RG_LDO_VCAMIO_LP_OP_SHIFT                   9
#define PMIC_RG_LDO_VCAMIO_OP_CFG_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VCAMIO_OP_CFG_SET_SHIFT              0
#define PMIC_RG_LDO_VCAMIO_OP_CFG_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VCAMIO_OP_CFG_CLR_SHIFT              0
#define PMIC_DA_QI_VCAMIO_MODE_MASK                      0x1
#define PMIC_DA_QI_VCAMIO_MODE_SHIFT                     8
#define PMIC_RG_LDO_VCAMIO_STBTD_MASK                    0x3
#define PMIC_RG_LDO_VCAMIO_STBTD_SHIFT                   9
#define PMIC_DA_QI_VCAMIO_STB_MASK                       0x1
#define PMIC_DA_QI_VCAMIO_STB_SHIFT                      14
#define PMIC_DA_QI_VCAMIO_EN_MASK                        0x1
#define PMIC_DA_QI_VCAMIO_EN_SHIFT                       15
#define PMIC_RG_LDO_VCAMIO_OCFB_EN_MASK                  0x1
#define PMIC_RG_LDO_VCAMIO_OCFB_EN_SHIFT                 9
#define PMIC_DA_QI_VCAMIO_OCFB_EN_MASK                   0x1
#define PMIC_DA_QI_VCAMIO_OCFB_EN_SHIFT                  10
#define PMIC_RG_LDO_VCAMIO_DUMMY_LOAD_MASK               0x3
#define PMIC_RG_LDO_VCAMIO_DUMMY_LOAD_SHIFT              5
#define PMIC_DA_QI_VCAMIO_DUMMY_LOAD_MASK                0x3
#define PMIC_DA_QI_VCAMIO_DUMMY_LOAD_SHIFT               14
#define PMIC_RG_LDO_VMIPI_EN_MASK                        0x1
#define PMIC_RG_LDO_VMIPI_EN_SHIFT                       0
#define PMIC_RG_LDO_VMIPI_LP_MASK                        0x1
#define PMIC_RG_LDO_VMIPI_LP_SHIFT                       1
#define PMIC_RG_LDO_VMIPI_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VMIPI_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VMIPI_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VMIPI_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VMIPI_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VMIPI_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VMIPI_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VMIPI_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VMIPI_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VMIPI_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VMIPI_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VMIPI_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VMIPI_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VMIPI_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VMIPI_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VMIPI_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VMIPI_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VMIPI_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VMIPI_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VMIPI_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VMIPI_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VMIPI_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VMIPI_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VMIPI_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VMIPI_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VMIPI_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VMIPI_MODE_MASK                       0x1
#define PMIC_DA_QI_VMIPI_MODE_SHIFT                      8
#define PMIC_RG_LDO_VMIPI_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VMIPI_STBTD_SHIFT                    9
#define PMIC_DA_QI_VMIPI_STB_MASK                        0x1
#define PMIC_DA_QI_VMIPI_STB_SHIFT                       14
#define PMIC_DA_QI_VMIPI_EN_MASK                         0x1
#define PMIC_DA_QI_VMIPI_EN_SHIFT                        15
#define PMIC_RG_LDO_VMIPI_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VMIPI_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VMIPI_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VMIPI_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VMIPI_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VMIPI_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VMIPI_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VMIPI_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VGP_EN_MASK                          0x1
#define PMIC_RG_LDO_VGP_EN_SHIFT                         0
#define PMIC_RG_LDO_VGP_LP_MASK                          0x1
#define PMIC_RG_LDO_VGP_LP_SHIFT                         1
#define PMIC_RG_LDO_VGP_SW_OP_EN_MASK                    0x1
#define PMIC_RG_LDO_VGP_SW_OP_EN_SHIFT                   0
#define PMIC_RG_LDO_VGP_HW0_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VGP_HW0_OP_EN_SHIFT                  1
#define PMIC_RG_LDO_VGP_HW1_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VGP_HW1_OP_EN_SHIFT                  2
#define PMIC_RG_LDO_VGP_HW2_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VGP_HW2_OP_EN_SHIFT                  3
#define PMIC_RG_LDO_VGP_OP_EN_SET_MASK                   0xFFFF
#define PMIC_RG_LDO_VGP_OP_EN_SET_SHIFT                  0
#define PMIC_RG_LDO_VGP_OP_EN_CLR_MASK                   0xFFFF
#define PMIC_RG_LDO_VGP_OP_EN_CLR_SHIFT                  0
#define PMIC_RG_LDO_VGP_HW0_OP_CFG_MASK                  0x1
#define PMIC_RG_LDO_VGP_HW0_OP_CFG_SHIFT                 1
#define PMIC_RG_LDO_VGP_HW1_OP_CFG_MASK                  0x1
#define PMIC_RG_LDO_VGP_HW1_OP_CFG_SHIFT                 2
#define PMIC_RG_LDO_VGP_HW2_OP_CFG_MASK                  0x1
#define PMIC_RG_LDO_VGP_HW2_OP_CFG_SHIFT                 3
#define PMIC_RG_LDO_VGP_ON_OP_MASK                       0x1
#define PMIC_RG_LDO_VGP_ON_OP_SHIFT                      8
#define PMIC_RG_LDO_VGP_LP_OP_MASK                       0x1
#define PMIC_RG_LDO_VGP_LP_OP_SHIFT                      9
#define PMIC_RG_LDO_VGP_OP_CFG_SET_MASK                  0xFFFF
#define PMIC_RG_LDO_VGP_OP_CFG_SET_SHIFT                 0
#define PMIC_RG_LDO_VGP_OP_CFG_CLR_MASK                  0xFFFF
#define PMIC_RG_LDO_VGP_OP_CFG_CLR_SHIFT                 0
#define PMIC_DA_QI_VGP_MODE_MASK                         0x1
#define PMIC_DA_QI_VGP_MODE_SHIFT                        8
#define PMIC_RG_LDO_VGP_STBTD_MASK                       0x3
#define PMIC_RG_LDO_VGP_STBTD_SHIFT                      9
#define PMIC_DA_QI_VGP_STB_MASK                          0x1
#define PMIC_DA_QI_VGP_STB_SHIFT                         14
#define PMIC_DA_QI_VGP_EN_MASK                           0x1
#define PMIC_DA_QI_VGP_EN_SHIFT                          15
#define PMIC_RG_LDO_VGP_OCFB_EN_MASK                     0x1
#define PMIC_RG_LDO_VGP_OCFB_EN_SHIFT                    9
#define PMIC_DA_QI_VGP_OCFB_EN_MASK                      0x1
#define PMIC_DA_QI_VGP_OCFB_EN_SHIFT                     10
#define PMIC_RG_LDO_VGP_DUMMY_LOAD_MASK                  0x3
#define PMIC_RG_LDO_VGP_DUMMY_LOAD_SHIFT                 5
#define PMIC_DA_QI_VGP_DUMMY_LOAD_MASK                   0x3
#define PMIC_DA_QI_VGP_DUMMY_LOAD_SHIFT                  14
#define PMIC_RG_LDO_VCN33_EN_BT_MASK                     0x1
#define PMIC_RG_LDO_VCN33_EN_BT_SHIFT                    0
#define PMIC_RG_LDO_VCN33_LP_MASK                        0x1
#define PMIC_RG_LDO_VCN33_LP_SHIFT                       1
#define PMIC_RG_LDO_VCN33_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VCN33_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VCN33_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCN33_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VCN33_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCN33_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VCN33_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCN33_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VCN33_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VCN33_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VCN33_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VCN33_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VCN33_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VCN33_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VCN33_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VCN33_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VCN33_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VCN33_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VCN33_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VCN33_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VCN33_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VCN33_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VCN33_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VCN33_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VCN33_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VCN33_OP_CFG_CLR_SHIFT               0
#define PMIC_RG_LDO_VCN33_EN_WIFI_MASK                   0x1
#define PMIC_RG_LDO_VCN33_EN_WIFI_SHIFT                  0
#define PMIC_DA_QI_VCN33_MODE_MASK                       0x1
#define PMIC_DA_QI_VCN33_MODE_SHIFT                      8
#define PMIC_RG_LDO_VCN33_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VCN33_STBTD_SHIFT                    9
#define PMIC_DA_QI_VCN33_STB_MASK                        0x1
#define PMIC_DA_QI_VCN33_STB_SHIFT                       14
#define PMIC_DA_QI_VCN33_EN_MASK                         0x1
#define PMIC_DA_QI_VCN33_EN_SHIFT                        15
#define PMIC_RG_LDO_VCN33_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VCN33_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VCN33_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VCN33_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VCN33_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VCN33_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VCN33_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VCN33_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VCN18_EN_MASK                        0x1
#define PMIC_RG_LDO_VCN18_EN_SHIFT                       0
#define PMIC_RG_LDO_VCN18_LP_MASK                        0x1
#define PMIC_RG_LDO_VCN18_LP_SHIFT                       1
#define PMIC_RG_LDO_VCN18_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VCN18_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VCN18_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCN18_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VCN18_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCN18_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VCN18_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCN18_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VCN18_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VCN18_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VCN18_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VCN18_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VCN18_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VCN18_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VCN18_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VCN18_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VCN18_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VCN18_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VCN18_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VCN18_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VCN18_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VCN18_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VCN18_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VCN18_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VCN18_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VCN18_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VCN18_MODE_MASK                       0x1
#define PMIC_DA_QI_VCN18_MODE_SHIFT                      8
#define PMIC_RG_LDO_VCN18_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VCN18_STBTD_SHIFT                    9
#define PMIC_DA_QI_VCN18_STB_MASK                        0x1
#define PMIC_DA_QI_VCN18_STB_SHIFT                       14
#define PMIC_DA_QI_VCN18_EN_MASK                         0x1
#define PMIC_DA_QI_VCN18_EN_SHIFT                        15
#define PMIC_RG_LDO_VCN18_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VCN18_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VCN18_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VCN18_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VCN18_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VCN18_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VCN18_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VCN18_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VCN28_EN_MASK                        0x1
#define PMIC_RG_LDO_VCN28_EN_SHIFT                       0
#define PMIC_RG_LDO_VCN28_LP_MASK                        0x1
#define PMIC_RG_LDO_VCN28_LP_SHIFT                       1
#define PMIC_RG_LDO_VCN28_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VCN28_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VCN28_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCN28_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VCN28_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCN28_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VCN28_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCN28_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VCN28_HW3_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCN28_HW3_OP_EN_SHIFT                4
#define PMIC_RG_LDO_VCN28_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VCN28_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VCN28_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VCN28_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VCN28_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VCN28_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VCN28_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VCN28_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VCN28_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VCN28_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VCN28_HW3_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VCN28_HW3_OP_CFG_SHIFT               4
#define PMIC_RG_LDO_VCN28_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VCN28_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VCN28_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VCN28_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VCN28_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VCN28_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VCN28_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VCN28_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VCN28_MODE_MASK                       0x1
#define PMIC_DA_QI_VCN28_MODE_SHIFT                      8
#define PMIC_RG_LDO_VCN28_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VCN28_STBTD_SHIFT                    9
#define PMIC_DA_QI_VCN28_STB_MASK                        0x1
#define PMIC_DA_QI_VCN28_STB_SHIFT                       14
#define PMIC_DA_QI_VCN28_EN_MASK                         0x1
#define PMIC_DA_QI_VCN28_EN_SHIFT                        15
#define PMIC_RG_LDO_VCN28_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VCN28_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VCN28_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VCN28_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VCN28_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VCN28_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VCN28_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VCN28_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VBIF28_EN_MASK                       0x1
#define PMIC_RG_LDO_VBIF28_EN_SHIFT                      0
#define PMIC_RG_LDO_VBIF28_LP_MASK                       0x1
#define PMIC_RG_LDO_VBIF28_LP_SHIFT                      1
#define PMIC_RG_LDO_VBIF28_SW_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VBIF28_SW_OP_EN_SHIFT                0
#define PMIC_RG_LDO_VBIF28_HW0_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VBIF28_HW0_OP_EN_SHIFT               1
#define PMIC_RG_LDO_VBIF28_HW1_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VBIF28_HW1_OP_EN_SHIFT               2
#define PMIC_RG_LDO_VBIF28_HW2_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VBIF28_HW2_OP_EN_SHIFT               3
#define PMIC_RG_LDO_VBIF28_OP_EN_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VBIF28_OP_EN_SET_SHIFT               0
#define PMIC_RG_LDO_VBIF28_OP_EN_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VBIF28_OP_EN_CLR_SHIFT               0
#define PMIC_RG_LDO_VBIF28_HW0_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VBIF28_HW0_OP_CFG_SHIFT              1
#define PMIC_RG_LDO_VBIF28_HW1_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VBIF28_HW1_OP_CFG_SHIFT              2
#define PMIC_RG_LDO_VBIF28_HW2_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VBIF28_HW2_OP_CFG_SHIFT              3
#define PMIC_RG_LDO_VBIF28_ON_OP_MASK                    0x1
#define PMIC_RG_LDO_VBIF28_ON_OP_SHIFT                   8
#define PMIC_RG_LDO_VBIF28_LP_OP_MASK                    0x1
#define PMIC_RG_LDO_VBIF28_LP_OP_SHIFT                   9
#define PMIC_RG_LDO_VBIF28_OP_CFG_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VBIF28_OP_CFG_SET_SHIFT              0
#define PMIC_RG_LDO_VBIF28_OP_CFG_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VBIF28_OP_CFG_CLR_SHIFT              0
#define PMIC_DA_QI_VBIF28_MODE_MASK                      0x1
#define PMIC_DA_QI_VBIF28_MODE_SHIFT                     8
#define PMIC_RG_LDO_VBIF28_STBTD_MASK                    0x3
#define PMIC_RG_LDO_VBIF28_STBTD_SHIFT                   9
#define PMIC_DA_QI_VBIF28_STB_MASK                       0x1
#define PMIC_DA_QI_VBIF28_STB_SHIFT                      14
#define PMIC_DA_QI_VBIF28_EN_MASK                        0x1
#define PMIC_DA_QI_VBIF28_EN_SHIFT                       15
#define PMIC_RG_LDO_VBIF28_OCFB_EN_MASK                  0x1
#define PMIC_RG_LDO_VBIF28_OCFB_EN_SHIFT                 9
#define PMIC_DA_QI_VBIF28_OCFB_EN_MASK                   0x1
#define PMIC_DA_QI_VBIF28_OCFB_EN_SHIFT                  10
#define PMIC_RG_LDO_VBIF28_DUMMY_LOAD_MASK               0x3
#define PMIC_RG_LDO_VBIF28_DUMMY_LOAD_SHIFT              5
#define PMIC_DA_QI_VBIF28_DUMMY_LOAD_MASK                0x3
#define PMIC_DA_QI_VBIF28_DUMMY_LOAD_SHIFT               14
#define PMIC_RG_LDO_VTCXO24_EN_MASK                      0x1
#define PMIC_RG_LDO_VTCXO24_EN_SHIFT                     0
#define PMIC_RG_LDO_VTCXO24_LP_MASK                      0x1
#define PMIC_RG_LDO_VTCXO24_LP_SHIFT                     1
#define PMIC_RG_LDO_VTCXO24_SW_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VTCXO24_SW_OP_EN_SHIFT               0
#define PMIC_RG_LDO_VTCXO24_HW0_OP_EN_MASK               0x1
#define PMIC_RG_LDO_VTCXO24_HW0_OP_EN_SHIFT              1
#define PMIC_RG_LDO_VTCXO24_HW1_OP_EN_MASK               0x1
#define PMIC_RG_LDO_VTCXO24_HW1_OP_EN_SHIFT              2
#define PMIC_RG_LDO_VTCXO24_HW2_OP_EN_MASK               0x1
#define PMIC_RG_LDO_VTCXO24_HW2_OP_EN_SHIFT              3
#define PMIC_RG_LDO_VTCXO24_OP_EN_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VTCXO24_OP_EN_SET_SHIFT              0
#define PMIC_RG_LDO_VTCXO24_OP_EN_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VTCXO24_OP_EN_CLR_SHIFT              0
#define PMIC_RG_LDO_VTCXO24_HW0_OP_CFG_MASK              0x1
#define PMIC_RG_LDO_VTCXO24_HW0_OP_CFG_SHIFT             1
#define PMIC_RG_LDO_VTCXO24_HW1_OP_CFG_MASK              0x1
#define PMIC_RG_LDO_VTCXO24_HW1_OP_CFG_SHIFT             2
#define PMIC_RG_LDO_VTCXO24_HW2_OP_CFG_MASK              0x1
#define PMIC_RG_LDO_VTCXO24_HW2_OP_CFG_SHIFT             3
#define PMIC_RG_LDO_VTCXO24_ON_OP_MASK                   0x1
#define PMIC_RG_LDO_VTCXO24_ON_OP_SHIFT                  8
#define PMIC_RG_LDO_VTCXO24_LP_OP_MASK                   0x1
#define PMIC_RG_LDO_VTCXO24_LP_OP_SHIFT                  9
#define PMIC_RG_LDO_VTCXO24_OP_CFG_SET_MASK              0xFFFF
#define PMIC_RG_LDO_VTCXO24_OP_CFG_SET_SHIFT             0
#define PMIC_RG_LDO_VTCXO24_OP_CFG_CLR_MASK              0xFFFF
#define PMIC_RG_LDO_VTCXO24_OP_CFG_CLR_SHIFT             0
#define PMIC_DA_QI_VTCXO24_MODE_MASK                     0x1
#define PMIC_DA_QI_VTCXO24_MODE_SHIFT                    8
#define PMIC_RG_LDO_VTCXO24_STBTD_MASK                   0x3
#define PMIC_RG_LDO_VTCXO24_STBTD_SHIFT                  9
#define PMIC_DA_QI_VTCXO24_STB_MASK                      0x1
#define PMIC_DA_QI_VTCXO24_STB_SHIFT                     14
#define PMIC_DA_QI_VTCXO24_EN_MASK                       0x1
#define PMIC_DA_QI_VTCXO24_EN_SHIFT                      15
#define PMIC_RG_LDO_VTCXO24_OCFB_EN_MASK                 0x1
#define PMIC_RG_LDO_VTCXO24_OCFB_EN_SHIFT                9
#define PMIC_DA_QI_VTCXO24_OCFB_EN_MASK                  0x1
#define PMIC_DA_QI_VTCXO24_OCFB_EN_SHIFT                 10
#define PMIC_RG_LDO_VTCXO24_DUMMY_LOAD_MASK              0x3
#define PMIC_RG_LDO_VTCXO24_DUMMY_LOAD_SHIFT             5
#define PMIC_DA_QI_VTCXO24_DUMMY_LOAD_MASK               0x3
#define PMIC_DA_QI_VTCXO24_DUMMY_LOAD_SHIFT              14
#define PMIC_RG_LDO_VLDO28_EN_AF_MASK                    0x1
#define PMIC_RG_LDO_VLDO28_EN_AF_SHIFT                   0
#define PMIC_RG_LDO_VLDO28_LP_MASK                       0x1
#define PMIC_RG_LDO_VLDO28_LP_SHIFT                      1
#define PMIC_RG_LDO_VLDO28_SW_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VLDO28_SW_OP_EN_SHIFT                0
#define PMIC_RG_LDO_VLDO28_HW0_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VLDO28_HW0_OP_EN_SHIFT               1
#define PMIC_RG_LDO_VLDO28_HW1_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VLDO28_HW1_OP_EN_SHIFT               2
#define PMIC_RG_LDO_VLDO28_HW2_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VLDO28_HW2_OP_EN_SHIFT               3
#define PMIC_RG_LDO_VLDO28_OP_EN_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VLDO28_OP_EN_SET_SHIFT               0
#define PMIC_RG_LDO_VLDO28_OP_EN_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VLDO28_OP_EN_CLR_SHIFT               0
#define PMIC_RG_LDO_VLDO28_HW0_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VLDO28_HW0_OP_CFG_SHIFT              1
#define PMIC_RG_LDO_VLDO28_HW1_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VLDO28_HW1_OP_CFG_SHIFT              2
#define PMIC_RG_LDO_VLDO28_HW2_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VLDO28_HW2_OP_CFG_SHIFT              3
#define PMIC_RG_LDO_VLDO28_ON_OP_MASK                    0x1
#define PMIC_RG_LDO_VLDO28_ON_OP_SHIFT                   8
#define PMIC_RG_LDO_VLDO28_LP_OP_MASK                    0x1
#define PMIC_RG_LDO_VLDO28_LP_OP_SHIFT                   9
#define PMIC_RG_LDO_VLDO28_OP_CFG_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VLDO28_OP_CFG_SET_SHIFT              0
#define PMIC_RG_LDO_VLDO28_OP_CFG_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VLDO28_OP_CFG_CLR_SHIFT              0
#define PMIC_RG_LDO_VLDO28_EN_TP_MASK                    0x1
#define PMIC_RG_LDO_VLDO28_EN_TP_SHIFT                   0
#define PMIC_DA_QI_VLDO28_MODE_MASK                      0x1
#define PMIC_DA_QI_VLDO28_MODE_SHIFT                     8
#define PMIC_RG_LDO_VLDO28_STBTD_MASK                    0x3
#define PMIC_RG_LDO_VLDO28_STBTD_SHIFT                   9
#define PMIC_DA_QI_VLDO28_STB_MASK                       0x1
#define PMIC_DA_QI_VLDO28_STB_SHIFT                      14
#define PMIC_DA_QI_VLDO28_EN_MASK                        0x1
#define PMIC_DA_QI_VLDO28_EN_SHIFT                       15
#define PMIC_RG_LDO_VLDO28_OCFB_EN_MASK                  0x1
#define PMIC_RG_LDO_VLDO28_OCFB_EN_SHIFT                 9
#define PMIC_DA_QI_VLDO28_OCFB_EN_MASK                   0x1
#define PMIC_DA_QI_VLDO28_OCFB_EN_SHIFT                  10
#define PMIC_RG_LDO_VLDO28_DUMMY_LOAD_MASK               0x3
#define PMIC_RG_LDO_VLDO28_DUMMY_LOAD_SHIFT              5
#define PMIC_DA_QI_VLDO28_DUMMY_LOAD_MASK                0x3
#define PMIC_DA_QI_VLDO28_DUMMY_LOAD_SHIFT               14
#define PMIC_RG_LDO_VGP2_EN_MASK                         0x1
#define PMIC_RG_LDO_VGP2_EN_SHIFT                        0
#define PMIC_RG_LDO_VGP2_LP_MASK                         0x1
#define PMIC_RG_LDO_VGP2_LP_SHIFT                        1
#define PMIC_RG_LDO_VGP2_SW_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VGP2_SW_OP_EN_SHIFT                  0
#define PMIC_RG_LDO_VGP2_HW0_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VGP2_HW0_OP_EN_SHIFT                 1
#define PMIC_RG_LDO_VGP2_HW1_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VGP2_HW1_OP_EN_SHIFT                 2
#define PMIC_RG_LDO_VGP2_HW2_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VGP2_HW2_OP_EN_SHIFT                 3
#define PMIC_RG_LDO_VGP2_OP_EN_SET_MASK                  0xFFFF
#define PMIC_RG_LDO_VGP2_OP_EN_SET_SHIFT                 0
#define PMIC_RG_LDO_VGP2_OP_EN_CLR_MASK                  0xFFFF
#define PMIC_RG_LDO_VGP2_OP_EN_CLR_SHIFT                 0
#define PMIC_RG_LDO_VGP2_HW0_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VGP2_HW0_OP_CFG_SHIFT                1
#define PMIC_RG_LDO_VGP2_HW1_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VGP2_HW1_OP_CFG_SHIFT                2
#define PMIC_RG_LDO_VGP2_HW2_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VGP2_HW2_OP_CFG_SHIFT                3
#define PMIC_RG_LDO_VGP2_ON_OP_MASK                      0x1
#define PMIC_RG_LDO_VGP2_ON_OP_SHIFT                     8
#define PMIC_RG_LDO_VGP2_LP_OP_MASK                      0x1
#define PMIC_RG_LDO_VGP2_LP_OP_SHIFT                     9
#define PMIC_RG_LDO_VGP2_OP_CFG_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VGP2_OP_CFG_SET_SHIFT                0
#define PMIC_RG_LDO_VGP2_OP_CFG_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VGP2_OP_CFG_CLR_SHIFT                0
#define PMIC_DA_QI_VGP2_MODE_MASK                        0x1
#define PMIC_DA_QI_VGP2_MODE_SHIFT                       8
#define PMIC_RG_LDO_VGP2_STBTD_MASK                      0x3
#define PMIC_RG_LDO_VGP2_STBTD_SHIFT                     9
#define PMIC_DA_QI_VGP2_STB_MASK                         0x1
#define PMIC_DA_QI_VGP2_STB_SHIFT                        14
#define PMIC_DA_QI_VGP2_EN_MASK                          0x1
#define PMIC_DA_QI_VGP2_EN_SHIFT                         15
#define PMIC_RG_LDO_VGP2_THER_SDN_EN_MASK                0x1
#define PMIC_RG_LDO_VGP2_THER_SDN_EN_SHIFT               4
#define PMIC_RG_LDO_VGP2_OCFB_EN_MASK                    0x1
#define PMIC_RG_LDO_VGP2_OCFB_EN_SHIFT                   9
#define PMIC_DA_QI_VGP2_OCFB_EN_MASK                     0x1
#define PMIC_DA_QI_VGP2_OCFB_EN_SHIFT                    10
#define PMIC_RG_LDO_VGP2_DUMMY_LOAD_MASK                 0x3
#define PMIC_RG_LDO_VGP2_DUMMY_LOAD_SHIFT                5
#define PMIC_DA_QI_VGP2_DUMMY_LOAD_MASK                  0x3
#define PMIC_DA_QI_VGP2_DUMMY_LOAD_SHIFT                 14
#define PMIC_RG_LDO_VFE28_EN_MASK                        0x1
#define PMIC_RG_LDO_VFE28_EN_SHIFT                       0
#define PMIC_RG_LDO_VFE28_LP_MASK                        0x1
#define PMIC_RG_LDO_VFE28_LP_SHIFT                       1
#define PMIC_RG_LDO_VFE28_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VFE28_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VFE28_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VFE28_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VFE28_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VFE28_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VFE28_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VFE28_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VFE28_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VFE28_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VFE28_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VFE28_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VFE28_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VFE28_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VFE28_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VFE28_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VFE28_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VFE28_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VFE28_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VFE28_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VFE28_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VFE28_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VFE28_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VFE28_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VFE28_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VFE28_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VFE28_MODE_MASK                       0x1
#define PMIC_DA_QI_VFE28_MODE_SHIFT                      8
#define PMIC_RG_LDO_VFE28_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VFE28_STBTD_SHIFT                    9
#define PMIC_DA_QI_VFE28_STB_MASK                        0x1
#define PMIC_DA_QI_VFE28_STB_SHIFT                       14
#define PMIC_DA_QI_VFE28_EN_MASK                         0x1
#define PMIC_DA_QI_VFE28_EN_SHIFT                        15
#define PMIC_RG_LDO_VFE28_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VFE28_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VFE28_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VFE28_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VFE28_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VFE28_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VFE28_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VFE28_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VMCH_EN_MASK                         0x1
#define PMIC_RG_LDO_VMCH_EN_SHIFT                        0
#define PMIC_RG_LDO_VMCH_LP_MASK                         0x1
#define PMIC_RG_LDO_VMCH_LP_SHIFT                        1
#define PMIC_RG_LDO_VMCH_SW_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VMCH_SW_OP_EN_SHIFT                  0
#define PMIC_RG_LDO_VMCH_HW0_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VMCH_HW0_OP_EN_SHIFT                 1
#define PMIC_RG_LDO_VMCH_HW1_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VMCH_HW1_OP_EN_SHIFT                 2
#define PMIC_RG_LDO_VMCH_HW2_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VMCH_HW2_OP_EN_SHIFT                 3
#define PMIC_RG_LDO_VMCH_OP_EN_SET_MASK                  0xFFFF
#define PMIC_RG_LDO_VMCH_OP_EN_SET_SHIFT                 0
#define PMIC_RG_LDO_VMCH_OP_EN_CLR_MASK                  0xFFFF
#define PMIC_RG_LDO_VMCH_OP_EN_CLR_SHIFT                 0
#define PMIC_RG_LDO_VMCH_HW0_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VMCH_HW0_OP_CFG_SHIFT                1
#define PMIC_RG_LDO_VMCH_HW1_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VMCH_HW1_OP_CFG_SHIFT                2
#define PMIC_RG_LDO_VMCH_HW2_OP_CFG_MASK                 0x1
#define PMIC_RG_LDO_VMCH_HW2_OP_CFG_SHIFT                3
#define PMIC_RG_LDO_VMCH_ON_OP_MASK                      0x1
#define PMIC_RG_LDO_VMCH_ON_OP_SHIFT                     8
#define PMIC_RG_LDO_VMCH_LP_OP_MASK                      0x1
#define PMIC_RG_LDO_VMCH_LP_OP_SHIFT                     9
#define PMIC_RG_LDO_VMCH_OP_CFG_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VMCH_OP_CFG_SET_SHIFT                0
#define PMIC_RG_LDO_VMCH_OP_CFG_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VMCH_OP_CFG_CLR_SHIFT                0
#define PMIC_DA_QI_VMCH_MODE_MASK                        0x1
#define PMIC_DA_QI_VMCH_MODE_SHIFT                       8
#define PMIC_RG_LDO_VMCH_STBTD_MASK                      0x3
#define PMIC_RG_LDO_VMCH_STBTD_SHIFT                     9
#define PMIC_DA_QI_VMCH_STB_MASK                         0x1
#define PMIC_DA_QI_VMCH_STB_SHIFT                        14
#define PMIC_DA_QI_VMCH_EN_MASK                          0x1
#define PMIC_DA_QI_VMCH_EN_SHIFT                         15
#define PMIC_RG_LDO_VMCH_OCFB_EN_MASK                    0x1
#define PMIC_RG_LDO_VMCH_OCFB_EN_SHIFT                   9
#define PMIC_DA_QI_VMCH_OCFB_EN_MASK                     0x1
#define PMIC_DA_QI_VMCH_OCFB_EN_SHIFT                    10
#define PMIC_RG_LDO_VMCH_DUMMY_LOAD_MASK                 0x3
#define PMIC_RG_LDO_VMCH_DUMMY_LOAD_SHIFT                5
#define PMIC_DA_QI_VMCH_DUMMY_LOAD_MASK                  0x3
#define PMIC_DA_QI_VMCH_DUMMY_LOAD_SHIFT                 14
#define PMIC_RG_LDO_VMC_EN_MASK                          0x1
#define PMIC_RG_LDO_VMC_EN_SHIFT                         0
#define PMIC_RG_LDO_VMC_LP_MASK                          0x1
#define PMIC_RG_LDO_VMC_LP_SHIFT                         1
#define PMIC_RG_LDO_VMC_SW_OP_EN_MASK                    0x1
#define PMIC_RG_LDO_VMC_SW_OP_EN_SHIFT                   0
#define PMIC_RG_LDO_VMC_HW0_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VMC_HW0_OP_EN_SHIFT                  1
#define PMIC_RG_LDO_VMC_HW1_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VMC_HW1_OP_EN_SHIFT                  2
#define PMIC_RG_LDO_VMC_HW2_OP_EN_MASK                   0x1
#define PMIC_RG_LDO_VMC_HW2_OP_EN_SHIFT                  3
#define PMIC_RG_LDO_VMC_OP_EN_SET_MASK                   0xFFFF
#define PMIC_RG_LDO_VMC_OP_EN_SET_SHIFT                  0
#define PMIC_RG_LDO_VMC_OP_EN_CLR_MASK                   0xFFFF
#define PMIC_RG_LDO_VMC_OP_EN_CLR_SHIFT                  0
#define PMIC_RG_LDO_VMC_HW0_OP_CFG_MASK                  0x1
#define PMIC_RG_LDO_VMC_HW0_OP_CFG_SHIFT                 1
#define PMIC_RG_LDO_VMC_HW1_OP_CFG_MASK                  0x1
#define PMIC_RG_LDO_VMC_HW1_OP_CFG_SHIFT                 2
#define PMIC_RG_LDO_VMC_HW2_OP_CFG_MASK                  0x1
#define PMIC_RG_LDO_VMC_HW2_OP_CFG_SHIFT                 3
#define PMIC_RG_LDO_VMC_ON_OP_MASK                       0x1
#define PMIC_RG_LDO_VMC_ON_OP_SHIFT                      8
#define PMIC_RG_LDO_VMC_LP_OP_MASK                       0x1
#define PMIC_RG_LDO_VMC_LP_OP_SHIFT                      9
#define PMIC_RG_LDO_VMC_OP_CFG_SET_MASK                  0xFFFF
#define PMIC_RG_LDO_VMC_OP_CFG_SET_SHIFT                 0
#define PMIC_RG_LDO_VMC_OP_CFG_CLR_MASK                  0xFFFF
#define PMIC_RG_LDO_VMC_OP_CFG_CLR_SHIFT                 0
#define PMIC_DA_QI_VMC_MODE_MASK                         0x1
#define PMIC_DA_QI_VMC_MODE_SHIFT                        8
#define PMIC_RG_LDO_VMC_STBTD_MASK                       0x3
#define PMIC_RG_LDO_VMC_STBTD_SHIFT                      9
#define PMIC_DA_QI_VMC_STB_MASK                          0x1
#define PMIC_DA_QI_VMC_STB_SHIFT                         14
#define PMIC_DA_QI_VMC_EN_MASK                           0x1
#define PMIC_DA_QI_VMC_EN_SHIFT                          15
#define PMIC_RG_LDO_VMC_OCFB_EN_MASK                     0x1
#define PMIC_RG_LDO_VMC_OCFB_EN_SHIFT                    9
#define PMIC_DA_QI_VMC_OCFB_EN_MASK                      0x1
#define PMIC_DA_QI_VMC_OCFB_EN_SHIFT                     10
#define PMIC_RG_LDO_VMC_DUMMY_LOAD_MASK                  0x3
#define PMIC_RG_LDO_VMC_DUMMY_LOAD_SHIFT                 5
#define PMIC_DA_QI_VMC_DUMMY_LOAD_MASK                   0x3
#define PMIC_DA_QI_VMC_DUMMY_LOAD_SHIFT                  14
#define PMIC_RG_LDO_VRF18_1_EN_MASK                      0x1
#define PMIC_RG_LDO_VRF18_1_EN_SHIFT                     0
#define PMIC_RG_LDO_VRF18_1_LP_MASK                      0x1
#define PMIC_RG_LDO_VRF18_1_LP_SHIFT                     1
#define PMIC_RG_LDO_VRF18_1_SW_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VRF18_1_SW_OP_EN_SHIFT               0
#define PMIC_RG_LDO_VRF18_1_HW0_OP_EN_MASK               0x1
#define PMIC_RG_LDO_VRF18_1_HW0_OP_EN_SHIFT              1
#define PMIC_RG_LDO_VRF18_1_HW1_OP_EN_MASK               0x1
#define PMIC_RG_LDO_VRF18_1_HW1_OP_EN_SHIFT              2
#define PMIC_RG_LDO_VRF18_1_HW2_OP_EN_MASK               0x1
#define PMIC_RG_LDO_VRF18_1_HW2_OP_EN_SHIFT              3
#define PMIC_RG_LDO_VRF18_1_OP_EN_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VRF18_1_OP_EN_SET_SHIFT              0
#define PMIC_RG_LDO_VRF18_1_OP_EN_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VRF18_1_OP_EN_CLR_SHIFT              0
#define PMIC_RG_LDO_VRF18_1_HW0_OP_CFG_MASK              0x1
#define PMIC_RG_LDO_VRF18_1_HW0_OP_CFG_SHIFT             1
#define PMIC_RG_LDO_VRF18_1_HW1_OP_CFG_MASK              0x1
#define PMIC_RG_LDO_VRF18_1_HW1_OP_CFG_SHIFT             2
#define PMIC_RG_LDO_VRF18_1_HW2_OP_CFG_MASK              0x1
#define PMIC_RG_LDO_VRF18_1_HW2_OP_CFG_SHIFT             3
#define PMIC_RG_LDO_VRF18_1_ON_OP_MASK                   0x1
#define PMIC_RG_LDO_VRF18_1_ON_OP_SHIFT                  8
#define PMIC_RG_LDO_VRF18_1_LP_OP_MASK                   0x1
#define PMIC_RG_LDO_VRF18_1_LP_OP_SHIFT                  9
#define PMIC_RG_LDO_VRF18_1_OP_CFG_SET_MASK              0xFFFF
#define PMIC_RG_LDO_VRF18_1_OP_CFG_SET_SHIFT             0
#define PMIC_RG_LDO_VRF18_1_OP_CFG_CLR_MASK              0xFFFF
#define PMIC_RG_LDO_VRF18_1_OP_CFG_CLR_SHIFT             0
#define PMIC_DA_QI_VRF18_1_MODE_MASK                     0x1
#define PMIC_DA_QI_VRF18_1_MODE_SHIFT                    8
#define PMIC_RG_LDO_VRF18_1_STBTD_MASK                   0x3
#define PMIC_RG_LDO_VRF18_1_STBTD_SHIFT                  9
#define PMIC_DA_QI_VRF18_1_STB_MASK                      0x1
#define PMIC_DA_QI_VRF18_1_STB_SHIFT                     14
#define PMIC_DA_QI_VRF18_1_EN_MASK                       0x1
#define PMIC_DA_QI_VRF18_1_EN_SHIFT                      15
#define PMIC_RG_LDO_VRF18_1_OCFB_EN_MASK                 0x1
#define PMIC_RG_LDO_VRF18_1_OCFB_EN_SHIFT                9
#define PMIC_DA_QI_VRF18_1_OCFB_EN_MASK                  0x1
#define PMIC_DA_QI_VRF18_1_OCFB_EN_SHIFT                 10
#define PMIC_RG_LDO_VRF18_1_DUMMY_LOAD_MASK              0x3
#define PMIC_RG_LDO_VRF18_1_DUMMY_LOAD_SHIFT             5
#define PMIC_DA_QI_VRF18_1_DUMMY_LOAD_MASK               0x3
#define PMIC_DA_QI_VRF18_1_DUMMY_LOAD_SHIFT              14
#define PMIC_RG_LDO_VRF18_2_EN_MASK                      0x1
#define PMIC_RG_LDO_VRF18_2_EN_SHIFT                     0
#define PMIC_RG_LDO_VRF18_2_LP_MASK                      0x1
#define PMIC_RG_LDO_VRF18_2_LP_SHIFT                     1
#define PMIC_RG_LDO_VRF18_2_SW_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VRF18_2_SW_OP_EN_SHIFT               0
#define PMIC_RG_LDO_VRF18_2_HW0_OP_EN_MASK               0x1
#define PMIC_RG_LDO_VRF18_2_HW0_OP_EN_SHIFT              1
#define PMIC_RG_LDO_VRF18_2_HW1_OP_EN_MASK               0x1
#define PMIC_RG_LDO_VRF18_2_HW1_OP_EN_SHIFT              2
#define PMIC_RG_LDO_VRF18_2_HW2_OP_EN_MASK               0x1
#define PMIC_RG_LDO_VRF18_2_HW2_OP_EN_SHIFT              3
#define PMIC_RG_LDO_VRF18_2_OP_EN_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VRF18_2_OP_EN_SET_SHIFT              0
#define PMIC_RG_LDO_VRF18_2_OP_EN_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VRF18_2_OP_EN_CLR_SHIFT              0
#define PMIC_RG_LDO_VRF18_2_HW0_OP_CFG_MASK              0x1
#define PMIC_RG_LDO_VRF18_2_HW0_OP_CFG_SHIFT             1
#define PMIC_RG_LDO_VRF18_2_HW1_OP_CFG_MASK              0x1
#define PMIC_RG_LDO_VRF18_2_HW1_OP_CFG_SHIFT             2
#define PMIC_RG_LDO_VRF18_2_HW2_OP_CFG_MASK              0x1
#define PMIC_RG_LDO_VRF18_2_HW2_OP_CFG_SHIFT             3
#define PMIC_RG_LDO_VRF18_2_ON_OP_MASK                   0x1
#define PMIC_RG_LDO_VRF18_2_ON_OP_SHIFT                  8
#define PMIC_RG_LDO_VRF18_2_LP_OP_MASK                   0x1
#define PMIC_RG_LDO_VRF18_2_LP_OP_SHIFT                  9
#define PMIC_RG_LDO_VRF18_2_OP_CFG_SET_MASK              0xFFFF
#define PMIC_RG_LDO_VRF18_2_OP_CFG_SET_SHIFT             0
#define PMIC_RG_LDO_VRF18_2_OP_CFG_CLR_MASK              0xFFFF
#define PMIC_RG_LDO_VRF18_2_OP_CFG_CLR_SHIFT             0
#define PMIC_DA_QI_VRF18_2_MODE_MASK                     0x1
#define PMIC_DA_QI_VRF18_2_MODE_SHIFT                    8
#define PMIC_RG_LDO_VRF18_2_STBTD_MASK                   0x3
#define PMIC_RG_LDO_VRF18_2_STBTD_SHIFT                  9
#define PMIC_DA_QI_VRF18_2_STB_MASK                      0x1
#define PMIC_DA_QI_VRF18_2_STB_SHIFT                     14
#define PMIC_DA_QI_VRF18_2_EN_MASK                       0x1
#define PMIC_DA_QI_VRF18_2_EN_SHIFT                      15
#define PMIC_RG_LDO_VRF18_2_OCFB_EN_MASK                 0x1
#define PMIC_RG_LDO_VRF18_2_OCFB_EN_SHIFT                9
#define PMIC_DA_QI_VRF18_2_OCFB_EN_MASK                  0x1
#define PMIC_DA_QI_VRF18_2_OCFB_EN_SHIFT                 10
#define PMIC_RG_LDO_VRF18_2_DUMMY_LOAD_MASK              0x3
#define PMIC_RG_LDO_VRF18_2_DUMMY_LOAD_SHIFT             5
#define PMIC_DA_QI_VRF18_2_DUMMY_LOAD_MASK               0x3
#define PMIC_DA_QI_VRF18_2_DUMMY_LOAD_SHIFT              14
#define PMIC_RG_LDO_VRF12_EN_MASK                        0x1
#define PMIC_RG_LDO_VRF12_EN_SHIFT                       0
#define PMIC_RG_LDO_VRF12_LP_MASK                        0x1
#define PMIC_RG_LDO_VRF12_LP_SHIFT                       1
#define PMIC_RG_LDO_VRF12_SW_OP_EN_MASK                  0x1
#define PMIC_RG_LDO_VRF12_SW_OP_EN_SHIFT                 0
#define PMIC_RG_LDO_VRF12_HW0_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VRF12_HW0_OP_EN_SHIFT                1
#define PMIC_RG_LDO_VRF12_HW1_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VRF12_HW1_OP_EN_SHIFT                2
#define PMIC_RG_LDO_VRF12_HW2_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VRF12_HW2_OP_EN_SHIFT                3
#define PMIC_RG_LDO_VRF12_OP_EN_SET_MASK                 0xFFFF
#define PMIC_RG_LDO_VRF12_OP_EN_SET_SHIFT                0
#define PMIC_RG_LDO_VRF12_OP_EN_CLR_MASK                 0xFFFF
#define PMIC_RG_LDO_VRF12_OP_EN_CLR_SHIFT                0
#define PMIC_RG_LDO_VRF12_HW0_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VRF12_HW0_OP_CFG_SHIFT               1
#define PMIC_RG_LDO_VRF12_HW1_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VRF12_HW1_OP_CFG_SHIFT               2
#define PMIC_RG_LDO_VRF12_HW2_OP_CFG_MASK                0x1
#define PMIC_RG_LDO_VRF12_HW2_OP_CFG_SHIFT               3
#define PMIC_RG_LDO_VRF12_ON_OP_MASK                     0x1
#define PMIC_RG_LDO_VRF12_ON_OP_SHIFT                    8
#define PMIC_RG_LDO_VRF12_LP_OP_MASK                     0x1
#define PMIC_RG_LDO_VRF12_LP_OP_SHIFT                    9
#define PMIC_RG_LDO_VRF12_OP_CFG_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VRF12_OP_CFG_SET_SHIFT               0
#define PMIC_RG_LDO_VRF12_OP_CFG_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VRF12_OP_CFG_CLR_SHIFT               0
#define PMIC_DA_QI_VRF12_MODE_MASK                       0x1
#define PMIC_DA_QI_VRF12_MODE_SHIFT                      8
#define PMIC_RG_LDO_VRF12_STBTD_MASK                     0x3
#define PMIC_RG_LDO_VRF12_STBTD_SHIFT                    9
#define PMIC_DA_QI_VRF12_STB_MASK                        0x1
#define PMIC_DA_QI_VRF12_STB_SHIFT                       14
#define PMIC_DA_QI_VRF12_EN_MASK                         0x1
#define PMIC_DA_QI_VRF12_EN_SHIFT                        15
#define PMIC_RG_LDO_VRF12_OCFB_EN_MASK                   0x1
#define PMIC_RG_LDO_VRF12_OCFB_EN_SHIFT                  9
#define PMIC_DA_QI_VRF12_OCFB_EN_MASK                    0x1
#define PMIC_DA_QI_VRF12_OCFB_EN_SHIFT                   10
#define PMIC_RG_LDO_VRF12_DUMMY_LOAD_MASK                0x3
#define PMIC_RG_LDO_VRF12_DUMMY_LOAD_SHIFT               5
#define PMIC_DA_QI_VRF12_DUMMY_LOAD_MASK                 0x3
#define PMIC_DA_QI_VRF12_DUMMY_LOAD_SHIFT                14
#define PMIC_RG_LDO_VCAMA1_EN_MASK                       0x1
#define PMIC_RG_LDO_VCAMA1_EN_SHIFT                      0
#define PMIC_RG_LDO_VCAMA1_LP_MASK                       0x1
#define PMIC_RG_LDO_VCAMA1_LP_SHIFT                      1
#define PMIC_RG_LDO_VCAMA1_SW_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCAMA1_SW_OP_EN_SHIFT                0
#define PMIC_RG_LDO_VCAMA1_HW0_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMA1_HW0_OP_EN_SHIFT               1
#define PMIC_RG_LDO_VCAMA1_HW1_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMA1_HW1_OP_EN_SHIFT               2
#define PMIC_RG_LDO_VCAMA1_HW2_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMA1_HW2_OP_EN_SHIFT               3
#define PMIC_RG_LDO_VCAMA1_OP_EN_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VCAMA1_OP_EN_SET_SHIFT               0
#define PMIC_RG_LDO_VCAMA1_OP_EN_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VCAMA1_OP_EN_CLR_SHIFT               0
#define PMIC_RG_LDO_VCAMA1_HW0_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMA1_HW0_OP_CFG_SHIFT              1
#define PMIC_RG_LDO_VCAMA1_HW1_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMA1_HW1_OP_CFG_SHIFT              2
#define PMIC_RG_LDO_VCAMA1_HW2_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMA1_HW2_OP_CFG_SHIFT              3
#define PMIC_RG_LDO_VCAMA1_ON_OP_MASK                    0x1
#define PMIC_RG_LDO_VCAMA1_ON_OP_SHIFT                   8
#define PMIC_RG_LDO_VCAMA1_LP_OP_MASK                    0x1
#define PMIC_RG_LDO_VCAMA1_LP_OP_SHIFT                   9
#define PMIC_RG_LDO_VCAMA1_OP_CFG_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VCAMA1_OP_CFG_SET_SHIFT              0
#define PMIC_RG_LDO_VCAMA1_OP_CFG_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VCAMA1_OP_CFG_CLR_SHIFT              0
#define PMIC_DA_QI_VCAMA1_MODE_MASK                      0x1
#define PMIC_DA_QI_VCAMA1_MODE_SHIFT                     8
#define PMIC_RG_LDO_VCAMA1_STBTD_MASK                    0x3
#define PMIC_RG_LDO_VCAMA1_STBTD_SHIFT                   9
#define PMIC_DA_QI_VCAMA1_STB_MASK                       0x1
#define PMIC_DA_QI_VCAMA1_STB_SHIFT                      14
#define PMIC_DA_QI_VCAMA1_EN_MASK                        0x1
#define PMIC_DA_QI_VCAMA1_EN_SHIFT                       15
#define PMIC_RG_LDO_VCAMA1_OCFB_EN_MASK                  0x1
#define PMIC_RG_LDO_VCAMA1_OCFB_EN_SHIFT                 9
#define PMIC_DA_QI_VCAMA1_OCFB_EN_MASK                   0x1
#define PMIC_DA_QI_VCAMA1_OCFB_EN_SHIFT                  10
#define PMIC_RG_LDO_VCAMA1_DUMMY_LOAD_MASK               0x3
#define PMIC_RG_LDO_VCAMA1_DUMMY_LOAD_SHIFT              5
#define PMIC_DA_QI_VCAMA1_DUMMY_LOAD_MASK                0x3
#define PMIC_DA_QI_VCAMA1_DUMMY_LOAD_SHIFT               14
#define PMIC_RG_LDO_VCAMA2_EN_MASK                       0x1
#define PMIC_RG_LDO_VCAMA2_EN_SHIFT                      0
#define PMIC_RG_LDO_VCAMA2_LP_MASK                       0x1
#define PMIC_RG_LDO_VCAMA2_LP_SHIFT                      1
#define PMIC_RG_LDO_VCAMA2_SW_OP_EN_MASK                 0x1
#define PMIC_RG_LDO_VCAMA2_SW_OP_EN_SHIFT                0
#define PMIC_RG_LDO_VCAMA2_HW0_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMA2_HW0_OP_EN_SHIFT               1
#define PMIC_RG_LDO_VCAMA2_HW1_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMA2_HW1_OP_EN_SHIFT               2
#define PMIC_RG_LDO_VCAMA2_HW2_OP_EN_MASK                0x1
#define PMIC_RG_LDO_VCAMA2_HW2_OP_EN_SHIFT               3
#define PMIC_RG_LDO_VCAMA2_OP_EN_SET_MASK                0xFFFF
#define PMIC_RG_LDO_VCAMA2_OP_EN_SET_SHIFT               0
#define PMIC_RG_LDO_VCAMA2_OP_EN_CLR_MASK                0xFFFF
#define PMIC_RG_LDO_VCAMA2_OP_EN_CLR_SHIFT               0
#define PMIC_RG_LDO_VCAMA2_HW0_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMA2_HW0_OP_CFG_SHIFT              1
#define PMIC_RG_LDO_VCAMA2_HW1_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMA2_HW1_OP_CFG_SHIFT              2
#define PMIC_RG_LDO_VCAMA2_HW2_OP_CFG_MASK               0x1
#define PMIC_RG_LDO_VCAMA2_HW2_OP_CFG_SHIFT              3
#define PMIC_RG_LDO_VCAMA2_ON_OP_MASK                    0x1
#define PMIC_RG_LDO_VCAMA2_ON_OP_SHIFT                   8
#define PMIC_RG_LDO_VCAMA2_LP_OP_MASK                    0x1
#define PMIC_RG_LDO_VCAMA2_LP_OP_SHIFT                   9
#define PMIC_RG_LDO_VCAMA2_OP_CFG_SET_MASK               0xFFFF
#define PMIC_RG_LDO_VCAMA2_OP_CFG_SET_SHIFT              0
#define PMIC_RG_LDO_VCAMA2_OP_CFG_CLR_MASK               0xFFFF
#define PMIC_RG_LDO_VCAMA2_OP_CFG_CLR_SHIFT              0
#define PMIC_DA_QI_VCAMA2_MODE_MASK                      0x1
#define PMIC_DA_QI_VCAMA2_MODE_SHIFT                     8
#define PMIC_RG_LDO_VCAMA2_STBTD_MASK                    0x3
#define PMIC_RG_LDO_VCAMA2_STBTD_SHIFT                   9
#define PMIC_DA_QI_VCAMA2_STB_MASK                       0x1
#define PMIC_DA_QI_VCAMA2_STB_SHIFT                      14
#define PMIC_DA_QI_VCAMA2_EN_MASK                        0x1
#define PMIC_DA_QI_VCAMA2_EN_SHIFT                       15
#define PMIC_RG_LDO_VCAMA2_OCFB_EN_MASK                  0x1
#define PMIC_RG_LDO_VCAMA2_OCFB_EN_SHIFT                 9
#define PMIC_DA_QI_VCAMA2_OCFB_EN_MASK                   0x1
#define PMIC_DA_QI_VCAMA2_OCFB_EN_SHIFT                  10
#define PMIC_RG_LDO_VCAMA2_DUMMY_LOAD_MASK               0x3
#define PMIC_RG_LDO_VCAMA2_DUMMY_LOAD_SHIFT              5
#define PMIC_DA_QI_VCAMA2_DUMMY_LOAD_MASK                0x3
#define PMIC_DA_QI_VCAMA2_DUMMY_LOAD_SHIFT               14
#define PMIC_LDO_DEGTD_SEL_MASK                          0x3
#define PMIC_LDO_DEGTD_SEL_SHIFT                         14
#define PMIC_RG_VRTC_EN_MASK                             0x1
#define PMIC_RG_VRTC_EN_SHIFT                            1
#define PMIC_DA_QI_VRTC_EN_MASK                          0x1
#define PMIC_DA_QI_VRTC_EN_SHIFT                         15
#define PMIC_RG_LDO_RSV1_MASK                            0x3FF
#define PMIC_RG_LDO_RSV1_SHIFT                           0
#define PMIC_RG_LDO_RSV0_MASK                            0x3F
#define PMIC_RG_LDO_RSV0_SHIFT                           10
#define PMIC_RG_LDO_RSV2_MASK                            0xFFFF
#define PMIC_RG_LDO_RSV2_SHIFT                           0
#define PMIC_RG_LDO_VSRAM_PROC_EN_MASK                   0x1
#define PMIC_RG_LDO_VSRAM_PROC_EN_SHIFT                  0
#define PMIC_RG_LDO_VSRAM_PROC_LP_MASK                   0x1
#define PMIC_RG_LDO_VSRAM_PROC_LP_SHIFT                  1
#define PMIC_RG_LDO_VSRAM_PROC_VOSEL_MASK                0x7F
#define PMIC_RG_LDO_VSRAM_PROC_VOSEL_SHIFT               0
#define PMIC_RG_LDO_VSRAM_PROC_VOSEL_SLEEP_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_PROC_VOSEL_SLEEP_SHIFT         0
#define PMIC_RG_LDO_VSRAM_PROC_SFCHG_FRATE_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_PROC_SFCHG_FRATE_SHIFT         0
#define PMIC_RG_LDO_VSRAM_PROC_SFCHG_FEN_MASK            0x1
#define PMIC_RG_LDO_VSRAM_PROC_SFCHG_FEN_SHIFT           7
#define PMIC_RG_LDO_VSRAM_PROC_SFCHG_RRATE_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_PROC_SFCHG_RRATE_SHIFT         8
#define PMIC_RG_LDO_VSRAM_PROC_SFCHG_REN_MASK            0x1
#define PMIC_RG_LDO_VSRAM_PROC_SFCHG_REN_SHIFT           15
#define PMIC_RG_LDO_VSRAM_PROC_DVS_TRANS_TD_MASK         0x3
#define PMIC_RG_LDO_VSRAM_PROC_DVS_TRANS_TD_SHIFT        0
#define PMIC_RG_LDO_VSRAM_PROC_DVS_TRANS_CTRL_MASK       0x3
#define PMIC_RG_LDO_VSRAM_PROC_DVS_TRANS_CTRL_SHIFT      4
#define PMIC_RG_LDO_VSRAM_PROC_DVS_TRANS_ONCE_MASK       0x1
#define PMIC_RG_LDO_VSRAM_PROC_DVS_TRANS_ONCE_SHIFT      6
#define PMIC_RG_LDO_VSRAM_PROC_SW_OP_EN_MASK             0x1
#define PMIC_RG_LDO_VSRAM_PROC_SW_OP_EN_SHIFT            0
#define PMIC_RG_LDO_VSRAM_PROC_HW0_OP_EN_MASK            0x1
#define PMIC_RG_LDO_VSRAM_PROC_HW0_OP_EN_SHIFT           1
#define PMIC_RG_LDO_VSRAM_PROC_HW1_OP_EN_MASK            0x1
#define PMIC_RG_LDO_VSRAM_PROC_HW1_OP_EN_SHIFT           2
#define PMIC_RG_LDO_VSRAM_PROC_HW2_OP_EN_MASK            0x1
#define PMIC_RG_LDO_VSRAM_PROC_HW2_OP_EN_SHIFT           3
#define PMIC_RG_LDO_VSRAM_PROC_OP_EN_SET_MASK            0xFFFF
#define PMIC_RG_LDO_VSRAM_PROC_OP_EN_SET_SHIFT           0
#define PMIC_RG_LDO_VSRAM_PROC_OP_EN_CLR_MASK            0xFFFF
#define PMIC_RG_LDO_VSRAM_PROC_OP_EN_CLR_SHIFT           0
#define PMIC_RG_LDO_VSRAM_PROC_HW0_OP_CFG_MASK           0x1
#define PMIC_RG_LDO_VSRAM_PROC_HW0_OP_CFG_SHIFT          1
#define PMIC_RG_LDO_VSRAM_PROC_HW1_OP_CFG_MASK           0x1
#define PMIC_RG_LDO_VSRAM_PROC_HW1_OP_CFG_SHIFT          2
#define PMIC_RG_LDO_VSRAM_PROC_HW2_OP_CFG_MASK           0x1
#define PMIC_RG_LDO_VSRAM_PROC_HW2_OP_CFG_SHIFT          3
#define PMIC_RG_LDO_VSRAM_PROC_ON_OP_MASK                0x1
#define PMIC_RG_LDO_VSRAM_PROC_ON_OP_SHIFT               8
#define PMIC_RG_LDO_VSRAM_PROC_LP_OP_MASK                0x1
#define PMIC_RG_LDO_VSRAM_PROC_LP_OP_SHIFT               9
#define PMIC_RG_LDO_VSRAM_PROC_OP_CFG_SET_MASK           0xFFFF
#define PMIC_RG_LDO_VSRAM_PROC_OP_CFG_SET_SHIFT          0
#define PMIC_RG_LDO_VSRAM_PROC_OP_CFG_CLR_MASK           0xFFFF
#define PMIC_RG_LDO_VSRAM_PROC_OP_CFG_CLR_SHIFT          0
#define PMIC_DA_QI_VSRAM_PROC_MODE_MASK                  0x1
#define PMIC_DA_QI_VSRAM_PROC_MODE_SHIFT                 8
#define PMIC_RG_LDO_VSRAM_PROC_STBTD_MASK                0x3
#define PMIC_RG_LDO_VSRAM_PROC_STBTD_SHIFT               9
#define PMIC_RG_LDO_VSRAM_PROC_OCFB_EN_MASK              0x1
#define PMIC_RG_LDO_VSRAM_PROC_OCFB_EN_SHIFT             9
#define PMIC_DA_QI_VSRAM_PROC_OCFB_EN_MASK               0x1
#define PMIC_DA_QI_VSRAM_PROC_OCFB_EN_SHIFT              10
#define PMIC_RG_LDO_VSRAM_PROC_DUMMY_LOAD_MASK           0x3
#define PMIC_RG_LDO_VSRAM_PROC_DUMMY_LOAD_SHIFT          5
#define PMIC_DA_QI_VSRAM_PROC_DUMMY_LOAD_MASK            0x3
#define PMIC_DA_QI_VSRAM_PROC_DUMMY_LOAD_SHIFT           14
#define PMIC_DA_QI_VSRAM_PROC_VOSEL_GRAY_MASK            0x7F
#define PMIC_DA_QI_VSRAM_PROC_VOSEL_GRAY_SHIFT           0
#define PMIC_DA_QI_VSRAM_PROC_VOSEL_MASK                 0x7F
#define PMIC_DA_QI_VSRAM_PROC_VOSEL_SHIFT                8
#define PMIC_DA_QI_VSRAM_PROC_EN_MASK                    0x1
#define PMIC_DA_QI_VSRAM_PROC_EN_SHIFT                   0
#define PMIC_DA_QI_VSRAM_PROC_STB_MASK                   0x1
#define PMIC_DA_QI_VSRAM_PROC_STB_SHIFT                  1
#define PMIC_DA_NI_VSRAM_PROC_VSLEEP_SEL_MASK            0x1
#define PMIC_DA_NI_VSRAM_PROC_VSLEEP_SEL_SHIFT           2
#define PMIC_DA_NI_VSRAM_PROC_R2R_PDN_MASK               0x1
#define PMIC_DA_NI_VSRAM_PROC_R2R_PDN_SHIFT              3
#define PMIC_DA_NI_VSRAM_PROC_TRACK_NDIS_EN_MASK         0x1
#define PMIC_DA_NI_VSRAM_PROC_TRACK_NDIS_EN_SHIFT        4
#define PMIC_RG_LDO_VSRAM_CORE_EN_MASK                   0x1
#define PMIC_RG_LDO_VSRAM_CORE_EN_SHIFT                  0
#define PMIC_RG_LDO_VSRAM_CORE_LP_MASK                   0x1
#define PMIC_RG_LDO_VSRAM_CORE_LP_SHIFT                  1
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_MASK                0x7F
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_SHIFT               0
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_SLEEP_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_SLEEP_SHIFT         0
#define PMIC_RG_LDO_VSRAM_CORE_SFCHG_FRATE_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_CORE_SFCHG_FRATE_SHIFT         0
#define PMIC_RG_LDO_VSRAM_CORE_SFCHG_FEN_MASK            0x1
#define PMIC_RG_LDO_VSRAM_CORE_SFCHG_FEN_SHIFT           7
#define PMIC_RG_LDO_VSRAM_CORE_SFCHG_RRATE_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_CORE_SFCHG_RRATE_SHIFT         8
#define PMIC_RG_LDO_VSRAM_CORE_SFCHG_REN_MASK            0x1
#define PMIC_RG_LDO_VSRAM_CORE_SFCHG_REN_SHIFT           15
#define PMIC_RG_LDO_VSRAM_CORE_DVS_TRANS_TD_MASK         0x3
#define PMIC_RG_LDO_VSRAM_CORE_DVS_TRANS_TD_SHIFT        0
#define PMIC_RG_LDO_VSRAM_CORE_DVS_TRANS_CTRL_MASK       0x3
#define PMIC_RG_LDO_VSRAM_CORE_DVS_TRANS_CTRL_SHIFT      4
#define PMIC_RG_LDO_VSRAM_CORE_DVS_TRANS_ONCE_MASK       0x1
#define PMIC_RG_LDO_VSRAM_CORE_DVS_TRANS_ONCE_SHIFT      6
#define PMIC_RG_LDO_VSRAM_CORE_SW_OP_EN_MASK             0x1
#define PMIC_RG_LDO_VSRAM_CORE_SW_OP_EN_SHIFT            0
#define PMIC_RG_LDO_VSRAM_CORE_HW0_OP_EN_MASK            0x1
#define PMIC_RG_LDO_VSRAM_CORE_HW0_OP_EN_SHIFT           1
#define PMIC_RG_LDO_VSRAM_CORE_HW1_OP_EN_MASK            0x1
#define PMIC_RG_LDO_VSRAM_CORE_HW1_OP_EN_SHIFT           2
#define PMIC_RG_LDO_VSRAM_CORE_HW2_OP_EN_MASK            0x1
#define PMIC_RG_LDO_VSRAM_CORE_HW2_OP_EN_SHIFT           3
#define PMIC_RG_LDO_VSRAM_CORE_OP_EN_SET_MASK            0xFFFF
#define PMIC_RG_LDO_VSRAM_CORE_OP_EN_SET_SHIFT           0
#define PMIC_RG_LDO_VSRAM_CORE_OP_EN_CLR_MASK            0xFFFF
#define PMIC_RG_LDO_VSRAM_CORE_OP_EN_CLR_SHIFT           0
#define PMIC_RG_LDO_VSRAM_CORE_HW0_OP_CFG_MASK           0x1
#define PMIC_RG_LDO_VSRAM_CORE_HW0_OP_CFG_SHIFT          1
#define PMIC_RG_LDO_VSRAM_CORE_HW1_OP_CFG_MASK           0x1
#define PMIC_RG_LDO_VSRAM_CORE_HW1_OP_CFG_SHIFT          2
#define PMIC_RG_LDO_VSRAM_CORE_HW2_OP_CFG_MASK           0x1
#define PMIC_RG_LDO_VSRAM_CORE_HW2_OP_CFG_SHIFT          3
#define PMIC_RG_LDO_VSRAM_CORE_ON_OP_MASK                0x1
#define PMIC_RG_LDO_VSRAM_CORE_ON_OP_SHIFT               8
#define PMIC_RG_LDO_VSRAM_CORE_LP_OP_MASK                0x1
#define PMIC_RG_LDO_VSRAM_CORE_LP_OP_SHIFT               9
#define PMIC_RG_LDO_VSRAM_CORE_OP_CFG_SET_MASK           0xFFFF
#define PMIC_RG_LDO_VSRAM_CORE_OP_CFG_SET_SHIFT          0
#define PMIC_RG_LDO_VSRAM_CORE_OP_CFG_CLR_MASK           0xFFFF
#define PMIC_RG_LDO_VSRAM_CORE_OP_CFG_CLR_SHIFT          0
#define PMIC_DA_QI_VSRAM_CORE_MODE_MASK                  0x1
#define PMIC_DA_QI_VSRAM_CORE_MODE_SHIFT                 8
#define PMIC_RG_LDO_VSRAM_CORE_STBTD_MASK                0x3
#define PMIC_RG_LDO_VSRAM_CORE_STBTD_SHIFT               9
#define PMIC_RG_LDO_VSRAM_CORE_OCFB_EN_MASK              0x1
#define PMIC_RG_LDO_VSRAM_CORE_OCFB_EN_SHIFT             9
#define PMIC_DA_QI_VSRAM_CORE_OCFB_EN_MASK               0x1
#define PMIC_DA_QI_VSRAM_CORE_OCFB_EN_SHIFT              10
#define PMIC_RG_LDO_VSRAM_CORE_DUMMY_LOAD_MASK           0x3
#define PMIC_RG_LDO_VSRAM_CORE_DUMMY_LOAD_SHIFT          5
#define PMIC_DA_QI_VSRAM_CORE_DUMMY_LOAD_MASK            0x3
#define PMIC_DA_QI_VSRAM_CORE_DUMMY_LOAD_SHIFT           14
#define PMIC_DA_QI_VSRAM_CORE_VOSEL_GRAY_MASK            0x7F
#define PMIC_DA_QI_VSRAM_CORE_VOSEL_GRAY_SHIFT           0
#define PMIC_DA_QI_VSRAM_CORE_VOSEL_MASK                 0x7F
#define PMIC_DA_QI_VSRAM_CORE_VOSEL_SHIFT                8
#define PMIC_DA_QI_VSRAM_CORE_EN_MASK                    0x1
#define PMIC_DA_QI_VSRAM_CORE_EN_SHIFT                   0
#define PMIC_DA_QI_VSRAM_CORE_STB_MASK                   0x1
#define PMIC_DA_QI_VSRAM_CORE_STB_SHIFT                  1
#define PMIC_DA_NI_VSRAM_CORE_VSLEEP_SEL_MASK            0x1
#define PMIC_DA_NI_VSRAM_CORE_VSLEEP_SEL_SHIFT           2
#define PMIC_DA_NI_VSRAM_CORE_R2R_PDN_MASK               0x1
#define PMIC_DA_NI_VSRAM_CORE_R2R_PDN_SHIFT              3
#define PMIC_DA_NI_VSRAM_CORE_TRACK_NDIS_EN_MASK         0x1
#define PMIC_DA_NI_VSRAM_CORE_TRACK_NDIS_EN_SHIFT        4
#define PMIC_RG_LDO_VSRAM_GPU_EN_MASK                    0x1
#define PMIC_RG_LDO_VSRAM_GPU_EN_SHIFT                   0
#define PMIC_RG_LDO_VSRAM_GPU_LP_MASK                    0x1
#define PMIC_RG_LDO_VSRAM_GPU_LP_SHIFT                   1
#define PMIC_RG_LDO_VSRAM_GPU_VOSEL_MASK                 0x7F
#define PMIC_RG_LDO_VSRAM_GPU_VOSEL_SHIFT                0
#define PMIC_RG_LDO_VSRAM_GPU_VOSEL_SLEEP_MASK           0x7F
#define PMIC_RG_LDO_VSRAM_GPU_VOSEL_SLEEP_SHIFT          0
#define PMIC_RG_LDO_VSRAM_GPU_SFCHG_FRATE_MASK           0x7F
#define PMIC_RG_LDO_VSRAM_GPU_SFCHG_FRATE_SHIFT          0
#define PMIC_RG_LDO_VSRAM_GPU_SFCHG_FEN_MASK             0x1
#define PMIC_RG_LDO_VSRAM_GPU_SFCHG_FEN_SHIFT            7
#define PMIC_RG_LDO_VSRAM_GPU_SFCHG_RRATE_MASK           0x7F
#define PMIC_RG_LDO_VSRAM_GPU_SFCHG_RRATE_SHIFT          8
#define PMIC_RG_LDO_VSRAM_GPU_SFCHG_REN_MASK             0x1
#define PMIC_RG_LDO_VSRAM_GPU_SFCHG_REN_SHIFT            15
#define PMIC_RG_LDO_VSRAM_GPU_DVS_TRANS_TD_MASK          0x3
#define PMIC_RG_LDO_VSRAM_GPU_DVS_TRANS_TD_SHIFT         0
#define PMIC_RG_LDO_VSRAM_GPU_DVS_TRANS_CTRL_MASK        0x3
#define PMIC_RG_LDO_VSRAM_GPU_DVS_TRANS_CTRL_SHIFT       4
#define PMIC_RG_LDO_VSRAM_GPU_DVS_TRANS_ONCE_MASK        0x1
#define PMIC_RG_LDO_VSRAM_GPU_DVS_TRANS_ONCE_SHIFT       6
#define PMIC_RG_LDO_VSRAM_GPU_SW_OP_EN_MASK              0x1
#define PMIC_RG_LDO_VSRAM_GPU_SW_OP_EN_SHIFT             0
#define PMIC_RG_LDO_VSRAM_GPU_HW0_OP_EN_MASK             0x1
#define PMIC_RG_LDO_VSRAM_GPU_HW0_OP_EN_SHIFT            1
#define PMIC_RG_LDO_VSRAM_GPU_HW1_OP_EN_MASK             0x1
#define PMIC_RG_LDO_VSRAM_GPU_HW1_OP_EN_SHIFT            2
#define PMIC_RG_LDO_VSRAM_GPU_HW2_OP_EN_MASK             0x1
#define PMIC_RG_LDO_VSRAM_GPU_HW2_OP_EN_SHIFT            3
#define PMIC_RG_LDO_VSRAM_GPU_OP_EN_SET_MASK             0xFFFF
#define PMIC_RG_LDO_VSRAM_GPU_OP_EN_SET_SHIFT            0
#define PMIC_RG_LDO_VSRAM_GPU_OP_EN_CLR_MASK             0xFFFF
#define PMIC_RG_LDO_VSRAM_GPU_OP_EN_CLR_SHIFT            0
#define PMIC_RG_LDO_VSRAM_GPU_HW0_OP_CFG_MASK            0x1
#define PMIC_RG_LDO_VSRAM_GPU_HW0_OP_CFG_SHIFT           1
#define PMIC_RG_LDO_VSRAM_GPU_HW1_OP_CFG_MASK            0x1
#define PMIC_RG_LDO_VSRAM_GPU_HW1_OP_CFG_SHIFT           2
#define PMIC_RG_LDO_VSRAM_GPU_HW2_OP_CFG_MASK            0x1
#define PMIC_RG_LDO_VSRAM_GPU_HW2_OP_CFG_SHIFT           3
#define PMIC_RG_LDO_VSRAM_GPU_ON_OP_MASK                 0x1
#define PMIC_RG_LDO_VSRAM_GPU_ON_OP_SHIFT                8
#define PMIC_RG_LDO_VSRAM_GPU_LP_OP_MASK                 0x1
#define PMIC_RG_LDO_VSRAM_GPU_LP_OP_SHIFT                9
#define PMIC_RG_LDO_VSRAM_GPU_OP_CFG_SET_MASK            0xFFFF
#define PMIC_RG_LDO_VSRAM_GPU_OP_CFG_SET_SHIFT           0
#define PMIC_RG_LDO_VSRAM_GPU_OP_CFG_CLR_MASK            0xFFFF
#define PMIC_RG_LDO_VSRAM_GPU_OP_CFG_CLR_SHIFT           0
#define PMIC_DA_QI_VSRAM_GPU_MODE_MASK                   0x1
#define PMIC_DA_QI_VSRAM_GPU_MODE_SHIFT                  8
#define PMIC_RG_LDO_VSRAM_GPU_STBTD_MASK                 0x3
#define PMIC_RG_LDO_VSRAM_GPU_STBTD_SHIFT                9
#define PMIC_RG_LDO_VSRAM_GPU_OCFB_EN_MASK               0x1
#define PMIC_RG_LDO_VSRAM_GPU_OCFB_EN_SHIFT              9
#define PMIC_DA_QI_VSRAM_GPU_OCFB_EN_MASK                0x1
#define PMIC_DA_QI_VSRAM_GPU_OCFB_EN_SHIFT               10
#define PMIC_RG_LDO_VSRAM_GPU_DUMMY_LOAD_MASK            0x3
#define PMIC_RG_LDO_VSRAM_GPU_DUMMY_LOAD_SHIFT           5
#define PMIC_DA_QI_VSRAM_GPU_DUMMY_LOAD_MASK             0x3
#define PMIC_DA_QI_VSRAM_GPU_DUMMY_LOAD_SHIFT            14
#define PMIC_DA_QI_VSRAM_GPU_VOSEL_GRAY_MASK             0x7F
#define PMIC_DA_QI_VSRAM_GPU_VOSEL_GRAY_SHIFT            0
#define PMIC_DA_QI_VSRAM_GPU_VOSEL_MASK                  0x7F
#define PMIC_DA_QI_VSRAM_GPU_VOSEL_SHIFT                 8
#define PMIC_DA_QI_VSRAM_GPU_EN_MASK                     0x1
#define PMIC_DA_QI_VSRAM_GPU_EN_SHIFT                    0
#define PMIC_DA_QI_VSRAM_GPU_STB_MASK                    0x1
#define PMIC_DA_QI_VSRAM_GPU_STB_SHIFT                   1
#define PMIC_DA_NI_VSRAM_GPU_VSLEEP_SEL_MASK             0x1
#define PMIC_DA_NI_VSRAM_GPU_VSLEEP_SEL_SHIFT            2
#define PMIC_DA_NI_VSRAM_GPU_R2R_PDN_MASK                0x1
#define PMIC_DA_NI_VSRAM_GPU_R2R_PDN_SHIFT               3
#define PMIC_DA_NI_VSRAM_GPU_TRACK_NDIS_EN_MASK          0x1
#define PMIC_DA_NI_VSRAM_GPU_TRACK_NDIS_EN_SHIFT         4
#define PMIC_RG_LDO_VSRAM_MD_EN_MASK                     0x1
#define PMIC_RG_LDO_VSRAM_MD_EN_SHIFT                    0
#define PMIC_RG_LDO_VSRAM_MD_LP_MASK                     0x1
#define PMIC_RG_LDO_VSRAM_MD_LP_SHIFT                    1
#define PMIC_RG_LDO_VSRAM_MD_VOSEL_MASK                  0x7F
#define PMIC_RG_LDO_VSRAM_MD_VOSEL_SHIFT                 0
#define PMIC_RG_LDO_VSRAM_MD_VOSEL_SLEEP_MASK            0x7F
#define PMIC_RG_LDO_VSRAM_MD_VOSEL_SLEEP_SHIFT           0
#define PMIC_RG_LDO_VSRAM_MD_SFCHG_FRATE_MASK            0x7F
#define PMIC_RG_LDO_VSRAM_MD_SFCHG_FRATE_SHIFT           0
#define PMIC_RG_LDO_VSRAM_MD_SFCHG_FEN_MASK              0x1
#define PMIC_RG_LDO_VSRAM_MD_SFCHG_FEN_SHIFT             7
#define PMIC_RG_LDO_VSRAM_MD_SFCHG_RRATE_MASK            0x7F
#define PMIC_RG_LDO_VSRAM_MD_SFCHG_RRATE_SHIFT           8
#define PMIC_RG_LDO_VSRAM_MD_SFCHG_REN_MASK              0x1
#define PMIC_RG_LDO_VSRAM_MD_SFCHG_REN_SHIFT             15
#define PMIC_RG_LDO_VSRAM_MD_DVS_TRANS_TD_MASK           0x3
#define PMIC_RG_LDO_VSRAM_MD_DVS_TRANS_TD_SHIFT          0
#define PMIC_RG_LDO_VSRAM_MD_DVS_TRANS_CTRL_MASK         0x3
#define PMIC_RG_LDO_VSRAM_MD_DVS_TRANS_CTRL_SHIFT        4
#define PMIC_RG_LDO_VSRAM_MD_DVS_TRANS_ONCE_MASK         0x1
#define PMIC_RG_LDO_VSRAM_MD_DVS_TRANS_ONCE_SHIFT        6
#define PMIC_RG_LDO_VSRAM_MD_SW_OP_EN_MASK               0x1
#define PMIC_RG_LDO_VSRAM_MD_SW_OP_EN_SHIFT              0
#define PMIC_RG_LDO_VSRAM_MD_HW0_OP_EN_MASK              0x1
#define PMIC_RG_LDO_VSRAM_MD_HW0_OP_EN_SHIFT             1
#define PMIC_RG_LDO_VSRAM_MD_HW1_OP_EN_MASK              0x1
#define PMIC_RG_LDO_VSRAM_MD_HW1_OP_EN_SHIFT             2
#define PMIC_RG_LDO_VSRAM_MD_HW2_OP_EN_MASK              0x1
#define PMIC_RG_LDO_VSRAM_MD_HW2_OP_EN_SHIFT             3
#define PMIC_RG_LDO_VSRAM_MD_OP_EN_SET_MASK              0xFFFF
#define PMIC_RG_LDO_VSRAM_MD_OP_EN_SET_SHIFT             0
#define PMIC_RG_LDO_VSRAM_MD_OP_EN_CLR_MASK              0xFFFF
#define PMIC_RG_LDO_VSRAM_MD_OP_EN_CLR_SHIFT             0
#define PMIC_RG_LDO_VSRAM_MD_HW0_OP_CFG_MASK             0x1
#define PMIC_RG_LDO_VSRAM_MD_HW0_OP_CFG_SHIFT            1
#define PMIC_RG_LDO_VSRAM_MD_HW1_OP_CFG_MASK             0x1
#define PMIC_RG_LDO_VSRAM_MD_HW1_OP_CFG_SHIFT            2
#define PMIC_RG_LDO_VSRAM_MD_HW2_OP_CFG_MASK             0x1
#define PMIC_RG_LDO_VSRAM_MD_HW2_OP_CFG_SHIFT            3
#define PMIC_RG_LDO_VSRAM_MD_ON_OP_MASK                  0x1
#define PMIC_RG_LDO_VSRAM_MD_ON_OP_SHIFT                 8
#define PMIC_RG_LDO_VSRAM_MD_LP_OP_MASK                  0x1
#define PMIC_RG_LDO_VSRAM_MD_LP_OP_SHIFT                 9
#define PMIC_RG_LDO_VSRAM_MD_OP_CFG_SET_MASK             0xFFFF
#define PMIC_RG_LDO_VSRAM_MD_OP_CFG_SET_SHIFT            0
#define PMIC_RG_LDO_VSRAM_MD_OP_CFG_CLR_MASK             0xFFFF
#define PMIC_RG_LDO_VSRAM_MD_OP_CFG_CLR_SHIFT            0
#define PMIC_DA_QI_VSRAM_MD_MODE_MASK                    0x1
#define PMIC_DA_QI_VSRAM_MD_MODE_SHIFT                   8
#define PMIC_RG_LDO_VSRAM_MD_STBTD_MASK                  0x3
#define PMIC_RG_LDO_VSRAM_MD_STBTD_SHIFT                 9
#define PMIC_RG_LDO_VSRAM_MD_OCFB_EN_MASK                0x1
#define PMIC_RG_LDO_VSRAM_MD_OCFB_EN_SHIFT               9
#define PMIC_DA_QI_VSRAM_MD_OCFB_EN_MASK                 0x1
#define PMIC_DA_QI_VSRAM_MD_OCFB_EN_SHIFT                10
#define PMIC_RG_LDO_VSRAM_MD_DUMMY_LOAD_MASK             0x3
#define PMIC_RG_LDO_VSRAM_MD_DUMMY_LOAD_SHIFT            5
#define PMIC_DA_QI_VSRAM_MD_DUMMY_LOAD_MASK              0x3
#define PMIC_DA_QI_VSRAM_MD_DUMMY_LOAD_SHIFT             14
#define PMIC_DA_QI_VSRAM_MD_VOSEL_GRAY_MASK              0x7F
#define PMIC_DA_QI_VSRAM_MD_VOSEL_GRAY_SHIFT             0
#define PMIC_DA_QI_VSRAM_MD_VOSEL_MASK                   0x7F
#define PMIC_DA_QI_VSRAM_MD_VOSEL_SHIFT                  8
#define PMIC_DA_QI_VSRAM_MD_EN_MASK                      0x1
#define PMIC_DA_QI_VSRAM_MD_EN_SHIFT                     0
#define PMIC_DA_QI_VSRAM_MD_STB_MASK                     0x1
#define PMIC_DA_QI_VSRAM_MD_STB_SHIFT                    1
#define PMIC_DA_NI_VSRAM_MD_VSLEEP_SEL_MASK              0x1
#define PMIC_DA_NI_VSRAM_MD_VSLEEP_SEL_SHIFT             2
#define PMIC_DA_NI_VSRAM_MD_R2R_PDN_MASK                 0x1
#define PMIC_DA_NI_VSRAM_MD_R2R_PDN_SHIFT                3
#define PMIC_DA_NI_VSRAM_MD_TRACK_NDIS_EN_MASK           0x1
#define PMIC_DA_NI_VSRAM_MD_TRACK_NDIS_EN_SHIFT          4
#define PMIC_RG_LDO_VSRAM_CORE_TRACK_SLEEP_CTRL_MASK     0x1
#define PMIC_RG_LDO_VSRAM_CORE_TRACK_SLEEP_CTRL_SHIFT    0
#define PMIC_RG_LDO_VSRAM_CORE_TRACK_ON_CTRL_MASK        0x1
#define PMIC_RG_LDO_VSRAM_CORE_TRACK_ON_CTRL_SHIFT       1
#define PMIC_RG_LDO_VSRAM_CORE_TRACK_VBUCK_ON_CTRL_MASK  0x1
#define PMIC_RG_LDO_VSRAM_CORE_TRACK_VBUCK_ON_CTRL_SHIFT 2
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_DELTA_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_DELTA_SHIFT         0
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_OFFSET_MASK         0x7F
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_OFFSET_SHIFT        8
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_ON_LB_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_ON_LB_SHIFT         0
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_ON_HB_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_ON_HB_SHIFT         8
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_SLEEP_LB_MASK       0x7F
#define PMIC_RG_LDO_VSRAM_CORE_VOSEL_SLEEP_LB_SHIFT      0
#define PMIC_RG_LDO_DCM_MODE_MASK                        0x1
#define PMIC_RG_LDO_DCM_MODE_SHIFT                       0
#define PMIC_RG_LDO_VIO28_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VIO28_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VIO28_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VIO28_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VIO28_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VIO28_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VIO18_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VIO18_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VIO18_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VIO18_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VIO18_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VIO18_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VUFS18_CK_SW_MODE_MASK               0x1
#define PMIC_RG_LDO_VUFS18_CK_SW_MODE_SHIFT              0
#define PMIC_RG_LDO_VUFS18_CK_SW_EN_MASK                 0x1
#define PMIC_RG_LDO_VUFS18_CK_SW_EN_SHIFT                1
#define PMIC_RG_LDO_VUFS18_OSC_SEL_DIS_MASK              0x1
#define PMIC_RG_LDO_VUFS18_OSC_SEL_DIS_SHIFT             2
#define PMIC_RG_LDO_VA10_CK_SW_MODE_MASK                 0x1
#define PMIC_RG_LDO_VA10_CK_SW_MODE_SHIFT                0
#define PMIC_RG_LDO_VA10_CK_SW_EN_MASK                   0x1
#define PMIC_RG_LDO_VA10_CK_SW_EN_SHIFT                  1
#define PMIC_RG_LDO_VA10_OSC_SEL_DIS_MASK                0x1
#define PMIC_RG_LDO_VA10_OSC_SEL_DIS_SHIFT               2
#define PMIC_RG_LDO_VA12_CK_SW_MODE_MASK                 0x1
#define PMIC_RG_LDO_VA12_CK_SW_MODE_SHIFT                0
#define PMIC_RG_LDO_VA12_CK_SW_EN_MASK                   0x1
#define PMIC_RG_LDO_VA12_CK_SW_EN_SHIFT                  1
#define PMIC_RG_LDO_VA12_OSC_SEL_DIS_MASK                0x1
#define PMIC_RG_LDO_VA12_OSC_SEL_DIS_SHIFT               2
#define PMIC_RG_LDO_VSRAM_PROC_CK_SW_MODE_MASK           0x1
#define PMIC_RG_LDO_VSRAM_PROC_CK_SW_MODE_SHIFT          0
#define PMIC_RG_LDO_VSRAM_PROC_CK_SW_EN_MASK             0x1
#define PMIC_RG_LDO_VSRAM_PROC_CK_SW_EN_SHIFT            1
#define PMIC_RG_LDO_VSRAM_PROC_OSC_SEL_DIS_MASK          0x1
#define PMIC_RG_LDO_VSRAM_PROC_OSC_SEL_DIS_SHIFT         2
#define PMIC_RG_LDO_VSRAM_CORE_CK_SW_MODE_MASK           0x1
#define PMIC_RG_LDO_VSRAM_CORE_CK_SW_MODE_SHIFT          0
#define PMIC_RG_LDO_VSRAM_CORE_CK_SW_EN_MASK             0x1
#define PMIC_RG_LDO_VSRAM_CORE_CK_SW_EN_SHIFT            1
#define PMIC_RG_LDO_VSRAM_CORE_OSC_SEL_DIS_MASK          0x1
#define PMIC_RG_LDO_VSRAM_CORE_OSC_SEL_DIS_SHIFT         2
#define PMIC_RG_LDO_VSRAM_GPU_CK_SW_MODE_MASK            0x1
#define PMIC_RG_LDO_VSRAM_GPU_CK_SW_MODE_SHIFT           0
#define PMIC_RG_LDO_VSRAM_GPU_CK_SW_EN_MASK              0x1
#define PMIC_RG_LDO_VSRAM_GPU_CK_SW_EN_SHIFT             1
#define PMIC_RG_LDO_VSRAM_GPU_OSC_SEL_DIS_MASK           0x1
#define PMIC_RG_LDO_VSRAM_GPU_OSC_SEL_DIS_SHIFT          2
#define PMIC_RG_LDO_VSRAM_MD_CK_SW_MODE_MASK             0x1
#define PMIC_RG_LDO_VSRAM_MD_CK_SW_MODE_SHIFT            0
#define PMIC_RG_LDO_VSRAM_MD_CK_SW_EN_MASK               0x1
#define PMIC_RG_LDO_VSRAM_MD_CK_SW_EN_SHIFT              1
#define PMIC_RG_LDO_VSRAM_MD_OSC_SEL_DIS_MASK            0x1
#define PMIC_RG_LDO_VSRAM_MD_OSC_SEL_DIS_SHIFT           2
#define PMIC_RG_LDO_VA18_CK_SW_MODE_MASK                 0x1
#define PMIC_RG_LDO_VA18_CK_SW_MODE_SHIFT                0
#define PMIC_RG_LDO_VA18_CK_SW_EN_MASK                   0x1
#define PMIC_RG_LDO_VA18_CK_SW_EN_SHIFT                  1
#define PMIC_RG_LDO_VA18_OSC_SEL_DIS_MASK                0x1
#define PMIC_RG_LDO_VA18_OSC_SEL_DIS_SHIFT               2
#define PMIC_RG_LDO_VUSB33_CK_SW_MODE_MASK               0x1
#define PMIC_RG_LDO_VUSB33_CK_SW_MODE_SHIFT              0
#define PMIC_RG_LDO_VUSB33_CK_SW_EN_MASK                 0x1
#define PMIC_RG_LDO_VUSB33_CK_SW_EN_SHIFT                1
#define PMIC_RG_LDO_VUSB33_OSC_SEL_DIS_MASK              0x1
#define PMIC_RG_LDO_VUSB33_OSC_SEL_DIS_SHIFT             2
#define PMIC_RG_LDO_VEMC_CK_SW_MODE_MASK                 0x1
#define PMIC_RG_LDO_VEMC_CK_SW_MODE_SHIFT                0
#define PMIC_RG_LDO_VEMC_CK_SW_EN_MASK                   0x1
#define PMIC_RG_LDO_VEMC_CK_SW_EN_SHIFT                  1
#define PMIC_RG_LDO_VEMC_OSC_SEL_DIS_MASK                0x1
#define PMIC_RG_LDO_VEMC_OSC_SEL_DIS_SHIFT               2
#define PMIC_RG_LDO_VXO22_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VXO22_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VXO22_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VXO22_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VXO22_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VXO22_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VXO18_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VXO18_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VXO18_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VXO18_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VXO18_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VXO18_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VSIM1_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VSIM1_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VSIM1_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VSIM1_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VSIM1_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VSIM1_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VSIM2_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VSIM2_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VSIM2_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VSIM2_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VSIM2_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VSIM2_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VCAMD1_CK_SW_MODE_MASK               0x1
#define PMIC_RG_LDO_VCAMD1_CK_SW_MODE_SHIFT              0
#define PMIC_RG_LDO_VCAMD1_CK_SW_EN_MASK                 0x1
#define PMIC_RG_LDO_VCAMD1_CK_SW_EN_SHIFT                1
#define PMIC_RG_LDO_VCAMD1_OSC_SEL_DIS_MASK              0x1
#define PMIC_RG_LDO_VCAMD1_OSC_SEL_DIS_SHIFT             2
#define PMIC_RG_LDO_VCAMD2_CK_SW_MODE_MASK               0x1
#define PMIC_RG_LDO_VCAMD2_CK_SW_MODE_SHIFT              0
#define PMIC_RG_LDO_VCAMD2_CK_SW_EN_MASK                 0x1
#define PMIC_RG_LDO_VCAMD2_CK_SW_EN_SHIFT                1
#define PMIC_RG_LDO_VCAMD2_OSC_SEL_DIS_MASK              0x1
#define PMIC_RG_LDO_VCAMD2_OSC_SEL_DIS_SHIFT             2
#define PMIC_RG_LDO_VCAMIO_CK_SW_MODE_MASK               0x1
#define PMIC_RG_LDO_VCAMIO_CK_SW_MODE_SHIFT              0
#define PMIC_RG_LDO_VCAMIO_CK_SW_EN_MASK                 0x1
#define PMIC_RG_LDO_VCAMIO_CK_SW_EN_SHIFT                1
#define PMIC_RG_LDO_VCAMIO_OSC_SEL_DIS_MASK              0x1
#define PMIC_RG_LDO_VCAMIO_OSC_SEL_DIS_SHIFT             2
#define PMIC_RG_LDO_VMIPI_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VMIPI_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VMIPI_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VMIPI_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VMIPI_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VMIPI_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VGP_CK_SW_MODE_MASK                  0x1
#define PMIC_RG_LDO_VGP_CK_SW_MODE_SHIFT                 0
#define PMIC_RG_LDO_VGP_CK_SW_EN_MASK                    0x1
#define PMIC_RG_LDO_VGP_CK_SW_EN_SHIFT                   1
#define PMIC_RG_LDO_VGP_OSC_SEL_DIS_MASK                 0x1
#define PMIC_RG_LDO_VGP_OSC_SEL_DIS_SHIFT                2
#define PMIC_RG_LDO_VCN33_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VCN33_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VCN33_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VCN33_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VCN33_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VCN33_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VCN18_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VCN18_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VCN18_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VCN18_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VCN18_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VCN18_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VCN28_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VCN28_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VCN28_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VCN28_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VCN28_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VCN28_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VGP2_CK_SW_MODE_MASK                 0x1
#define PMIC_RG_LDO_VGP2_CK_SW_MODE_SHIFT                0
#define PMIC_RG_LDO_VGP2_CK_SW_EN_MASK                   0x1
#define PMIC_RG_LDO_VGP2_CK_SW_EN_SHIFT                  1
#define PMIC_RG_LDO_VGP2_OSC_SEL_DIS_MASK                0x1
#define PMIC_RG_LDO_VGP2_OSC_SEL_DIS_SHIFT               2
#define PMIC_RG_LDO_VBIF28_CK_SW_MODE_MASK               0x1
#define PMIC_RG_LDO_VBIF28_CK_SW_MODE_SHIFT              0
#define PMIC_RG_LDO_VBIF28_CK_SW_EN_MASK                 0x1
#define PMIC_RG_LDO_VBIF28_CK_SW_EN_SHIFT                1
#define PMIC_RG_LDO_VBIF28_OSC_SEL_DIS_MASK              0x1
#define PMIC_RG_LDO_VBIF28_OSC_SEL_DIS_SHIFT             2
#define PMIC_RG_LDO_VFE28_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VFE28_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VFE28_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VFE28_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VFE28_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VFE28_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VMCH_CK_SW_MODE_MASK                 0x1
#define PMIC_RG_LDO_VMCH_CK_SW_MODE_SHIFT                0
#define PMIC_RG_LDO_VMCH_CK_SW_EN_MASK                   0x1
#define PMIC_RG_LDO_VMCH_CK_SW_EN_SHIFT                  1
#define PMIC_RG_LDO_VMCH_OSC_SEL_DIS_MASK                0x1
#define PMIC_RG_LDO_VMCH_OSC_SEL_DIS_SHIFT               2
#define PMIC_RG_LDO_VMC_CK_SW_MODE_MASK                  0x1
#define PMIC_RG_LDO_VMC_CK_SW_MODE_SHIFT                 0
#define PMIC_RG_LDO_VMC_CK_SW_EN_MASK                    0x1
#define PMIC_RG_LDO_VMC_CK_SW_EN_SHIFT                   1
#define PMIC_RG_LDO_VMC_OSC_SEL_DIS_MASK                 0x1
#define PMIC_RG_LDO_VMC_OSC_SEL_DIS_SHIFT                2
#define PMIC_RG_LDO_VRF18_1_CK_SW_MODE_MASK              0x1
#define PMIC_RG_LDO_VRF18_1_CK_SW_MODE_SHIFT             0
#define PMIC_RG_LDO_VRF18_1_CK_SW_EN_MASK                0x1
#define PMIC_RG_LDO_VRF18_1_CK_SW_EN_SHIFT               1
#define PMIC_RG_LDO_VRF18_1_OSC_SEL_DIS_MASK             0x1
#define PMIC_RG_LDO_VRF18_1_OSC_SEL_DIS_SHIFT            2
#define PMIC_RG_LDO_VRF18_2_CK_SW_MODE_MASK              0x1
#define PMIC_RG_LDO_VRF18_2_CK_SW_MODE_SHIFT             0
#define PMIC_RG_LDO_VRF18_2_CK_SW_EN_MASK                0x1
#define PMIC_RG_LDO_VRF18_2_CK_SW_EN_SHIFT               1
#define PMIC_RG_LDO_VRF18_2_OSC_SEL_DIS_MASK             0x1
#define PMIC_RG_LDO_VRF18_2_OSC_SEL_DIS_SHIFT            2
#define PMIC_RG_LDO_VTCXO24_CK_SW_MODE_MASK              0x1
#define PMIC_RG_LDO_VTCXO24_CK_SW_MODE_SHIFT             0
#define PMIC_RG_LDO_VTCXO24_CK_SW_EN_MASK                0x1
#define PMIC_RG_LDO_VTCXO24_CK_SW_EN_SHIFT               1
#define PMIC_RG_LDO_VTCXO24_OSC_SEL_DIS_MASK             0x1
#define PMIC_RG_LDO_VTCXO24_OSC_SEL_DIS_SHIFT            2
#define PMIC_RG_LDO_VLDO28_CK_SW_MODE_MASK               0x1
#define PMIC_RG_LDO_VLDO28_CK_SW_MODE_SHIFT              0
#define PMIC_RG_LDO_VLDO28_CK_SW_EN_MASK                 0x1
#define PMIC_RG_LDO_VLDO28_CK_SW_EN_SHIFT                1
#define PMIC_RG_LDO_VLDO28_OSC_SEL_DIS_MASK              0x1
#define PMIC_RG_LDO_VLDO28_OSC_SEL_DIS_SHIFT             2
#define PMIC_RG_LDO_VRF12_CK_SW_MODE_MASK                0x1
#define PMIC_RG_LDO_VRF12_CK_SW_MODE_SHIFT               0
#define PMIC_RG_LDO_VRF12_CK_SW_EN_MASK                  0x1
#define PMIC_RG_LDO_VRF12_CK_SW_EN_SHIFT                 1
#define PMIC_RG_LDO_VRF12_OSC_SEL_DIS_MASK               0x1
#define PMIC_RG_LDO_VRF12_OSC_SEL_DIS_SHIFT              2
#define PMIC_RG_LDO_VCAMA1_CK_SW_MODE_MASK               0x1
#define PMIC_RG_LDO_VCAMA1_CK_SW_MODE_SHIFT              0
#define PMIC_RG_LDO_VCAMA1_CK_SW_EN_MASK                 0x1
#define PMIC_RG_LDO_VCAMA1_CK_SW_EN_SHIFT                1
#define PMIC_RG_LDO_VCAMA1_OSC_SEL_DIS_MASK              0x1
#define PMIC_RG_LDO_VCAMA1_OSC_SEL_DIS_SHIFT             2
#define PMIC_RG_LDO_VCAMA2_CK_SW_MODE_MASK               0x1
#define PMIC_RG_LDO_VCAMA2_CK_SW_MODE_SHIFT              0
#define PMIC_RG_LDO_VCAMA2_CK_SW_EN_MASK                 0x1
#define PMIC_RG_LDO_VCAMA2_CK_SW_EN_SHIFT                1
#define PMIC_RG_LDO_VCAMA2_OSC_SEL_DIS_MASK              0x1
#define PMIC_RG_LDO_VCAMA2_OSC_SEL_DIS_SHIFT             2
#define PMIC_RG_LDO_VSRAM_PROC_SP_SW_VOSEL_EN_MASK       0x1
#define PMIC_RG_LDO_VSRAM_PROC_SP_SW_VOSEL_EN_SHIFT      0
#define PMIC_RG_LDO_VSRAM_PROC_SP_SW_VOSEL_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_PROC_SP_SW_VOSEL_SHIFT         1
#define PMIC_RG_LDO_VSRAM_GPU_SP_SW_VOSEL_EN_MASK        0x1
#define PMIC_RG_LDO_VSRAM_GPU_SP_SW_VOSEL_EN_SHIFT       0
#define PMIC_RG_LDO_VSRAM_GPU_SP_SW_VOSEL_MASK           0x7F
#define PMIC_RG_LDO_VSRAM_GPU_SP_SW_VOSEL_SHIFT          1
#define PMIC_RG_LDO_VSRAM_MD_SP_SW_VOSEL_EN_MASK         0x1
#define PMIC_RG_LDO_VSRAM_MD_SP_SW_VOSEL_EN_SHIFT        0
#define PMIC_RG_LDO_VSRAM_MD_SP_SW_VOSEL_MASK            0x7F
#define PMIC_RG_LDO_VSRAM_MD_SP_SW_VOSEL_SHIFT           1
#define PMIC_RG_LDO_VSRAM_CORE_SP_SW_VOSEL_EN_MASK       0x1
#define PMIC_RG_LDO_VSRAM_CORE_SP_SW_VOSEL_EN_SHIFT      0
#define PMIC_RG_LDO_VSRAM_CORE_SP_SW_VOSEL_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_CORE_SP_SW_VOSEL_SHIFT         1
#define PMIC_RG_LDO_VSRAM_CORE_SSHUB_ON_MASK             0x1
#define PMIC_RG_LDO_VSRAM_CORE_SSHUB_ON_SHIFT            0
#define PMIC_RG_LDO_VSRAM_CORE_SSHUB_MODE_MASK           0x1
#define PMIC_RG_LDO_VSRAM_CORE_SSHUB_MODE_SHIFT          1
#define PMIC_RG_LDO_VSRAM_CORE_SSHUB_VOSEL_MASK          0x7F
#define PMIC_RG_LDO_VSRAM_CORE_SSHUB_VOSEL_SHIFT         2
#define PMIC_RG_LDO_LP_PROT_DISABLE_MASK                 0x1
#define PMIC_RG_LDO_LP_PROT_DISABLE_SHIFT                0
#define PMIC_RG_LDO_DUMMY_LOAD_GATED_DIS_MASK            0x1
#define PMIC_RG_LDO_DUMMY_LOAD_GATED_DIS_SHIFT           0
#define PMIC_RG_LDO_VSRAM_PROC_R2R_PDN_DIS_MASK          0x1
#define PMIC_RG_LDO_VSRAM_PROC_R2R_PDN_DIS_SHIFT         0
#define PMIC_RG_LDO_VSRAM_CORE_R2R_PDN_DIS_MASK          0x1
#define PMIC_RG_LDO_VSRAM_CORE_R2R_PDN_DIS_SHIFT         0
#define PMIC_RG_LDO_VSRAM_GPU_R2R_PDN_DIS_MASK           0x1
#define PMIC_RG_LDO_VSRAM_GPU_R2R_PDN_DIS_SHIFT          0
#define PMIC_RG_LDO_VSRAM_MD_R2R_PDN_DIS_MASK            0x1
#define PMIC_RG_LDO_VSRAM_MD_R2R_PDN_DIS_SHIFT           0
#define PMIC_RG_VFE28_VOCAL_MASK                         0xF
#define PMIC_RG_VFE28_VOCAL_SHIFT                        0
#define PMIC_RG_VFE28_VOSEL_MASK                         0xF
#define PMIC_RG_VFE28_VOSEL_SHIFT                        8
#define PMIC_RG_VFE28_VOTRIM_MASK                        0xF
#define PMIC_RG_VFE28_VOTRIM_SHIFT                       0
#define PMIC_RGS_VFE28_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VFE28_CAL_INDI_SHIFT                    4
#define PMIC_RG_VFE28_OC_TRIM_MASK                       0x7
#define PMIC_RG_VFE28_OC_TRIM_SHIFT                      8
#define PMIC_RG_VFE28_NDIS_EN_MASK                       0x1
#define PMIC_RG_VFE28_NDIS_EN_SHIFT                      11
#define PMIC_RG_VFE28_STB_SEL_MASK                       0x1
#define PMIC_RG_VFE28_STB_SEL_SHIFT                      12
#define PMIC_RG_VFE28_RSV_MASK                           0x3
#define PMIC_RG_VFE28_RSV_SHIFT                          13
#define PMIC_RG_VFE28_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VFE28_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VTCXO24_VOCAL_MASK                       0xF
#define PMIC_RG_VTCXO24_VOCAL_SHIFT                      0
#define PMIC_RG_VTCXO24_VOSEL_MASK                       0xF
#define PMIC_RG_VTCXO24_VOSEL_SHIFT                      8
#define PMIC_RG_VTCXO24_VOTRIM_MASK                      0xF
#define PMIC_RG_VTCXO24_VOTRIM_SHIFT                     0
#define PMIC_RGS_VTCXO24_CAL_INDI_MASK                   0x1
#define PMIC_RGS_VTCXO24_CAL_INDI_SHIFT                  4
#define PMIC_RG_VTCXO24_OC_TRIM_MASK                     0x7
#define PMIC_RG_VTCXO24_OC_TRIM_SHIFT                    8
#define PMIC_RG_VTCXO24_NDIS_EN_MASK                     0x1
#define PMIC_RG_VTCXO24_NDIS_EN_SHIFT                    11
#define PMIC_RG_VTCXO24_STB_SEL_MASK                     0x1
#define PMIC_RG_VTCXO24_STB_SEL_SHIFT                    12
#define PMIC_RG_VTCXO24_RSV_MASK                         0x3
#define PMIC_RG_VTCXO24_RSV_SHIFT                        13
#define PMIC_RG_VTCXO24_VOS_CAL_EN_MASK                  0x1
#define PMIC_RG_VTCXO24_VOS_CAL_EN_SHIFT                 15
#define PMIC_RG_VXO22_VOCAL_MASK                         0xF
#define PMIC_RG_VXO22_VOCAL_SHIFT                        0
#define PMIC_RG_VXO22_VOSEL_MASK                         0xF
#define PMIC_RG_VXO22_VOSEL_SHIFT                        8
#define PMIC_RG_VXO22_VOTRIM_MASK                        0xF
#define PMIC_RG_VXO22_VOTRIM_SHIFT                       0
#define PMIC_RGS_VXO22_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VXO22_CAL_INDI_SHIFT                    4
#define PMIC_RG_VXO22_OC_TRIM_MASK                       0x7
#define PMIC_RG_VXO22_OC_TRIM_SHIFT                      8
#define PMIC_RG_VXO22_NDIS_EN_MASK                       0x1
#define PMIC_RG_VXO22_NDIS_EN_SHIFT                      11
#define PMIC_RG_VXO22_STB_SEL_MASK                       0x1
#define PMIC_RG_VXO22_STB_SEL_SHIFT                      12
#define PMIC_RG_VXO22_RSV_MASK                           0x3
#define PMIC_RG_VXO22_RSV_SHIFT                          13
#define PMIC_RG_VXO22_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VXO22_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VCN28_VOCAL_MASK                         0xF
#define PMIC_RG_VCN28_VOCAL_SHIFT                        0
#define PMIC_RG_VCN28_VOSEL_MASK                         0xF
#define PMIC_RG_VCN28_VOSEL_SHIFT                        8
#define PMIC_RG_VCN28_VOTRIM_MASK                        0xF
#define PMIC_RG_VCN28_VOTRIM_SHIFT                       0
#define PMIC_RGS_VCN28_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VCN28_CAL_INDI_SHIFT                    4
#define PMIC_RG_VCN28_OC_TRIM_MASK                       0x7
#define PMIC_RG_VCN28_OC_TRIM_SHIFT                      8
#define PMIC_RG_VCN28_NDIS_EN_MASK                       0x1
#define PMIC_RG_VCN28_NDIS_EN_SHIFT                      11
#define PMIC_RG_VCN28_STB_SEL_MASK                       0x1
#define PMIC_RG_VCN28_STB_SEL_SHIFT                      12
#define PMIC_RG_VCN28_RSV_MASK                           0x3
#define PMIC_RG_VCN28_RSV_SHIFT                          13
#define PMIC_RG_VCN28_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VCN28_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VCAMA1_VOCAL_MASK                        0xF
#define PMIC_RG_VCAMA1_VOCAL_SHIFT                       0
#define PMIC_RG_VCAMA1_VOSEL_MASK                        0xF
#define PMIC_RG_VCAMA1_VOSEL_SHIFT                       8
#define PMIC_RG_VCAMA1_VOTRIM_MASK                       0xF
#define PMIC_RG_VCAMA1_VOTRIM_SHIFT                      0
#define PMIC_RGS_VCAMA1_CAL_INDI_MASK                    0x1
#define PMIC_RGS_VCAMA1_CAL_INDI_SHIFT                   4
#define PMIC_RG_VCAMA1_OC_TRIM_MASK                      0x7
#define PMIC_RG_VCAMA1_OC_TRIM_SHIFT                     8
#define PMIC_RG_VCAMA1_NDIS_EN_MASK                      0x1
#define PMIC_RG_VCAMA1_NDIS_EN_SHIFT                     11
#define PMIC_RG_VCAMA1_STB_SEL_MASK                      0x1
#define PMIC_RG_VCAMA1_STB_SEL_SHIFT                     12
#define PMIC_RG_VCAMA1_RSV_MASK                          0x3
#define PMIC_RG_VCAMA1_RSV_SHIFT                         13
#define PMIC_RG_VCAMA1_VOS_CAL_EN_MASK                   0x1
#define PMIC_RG_VCAMA1_VOS_CAL_EN_SHIFT                  15
#define PMIC_RG_VCAMA2_VOCAL_MASK                        0xF
#define PMIC_RG_VCAMA2_VOCAL_SHIFT                       0
#define PMIC_RG_VCAMA2_VOSEL_MASK                        0xF
#define PMIC_RG_VCAMA2_VOSEL_SHIFT                       8
#define PMIC_RG_VCAMA2_VOTRIM_MASK                       0xF
#define PMIC_RG_VCAMA2_VOTRIM_SHIFT                      0
#define PMIC_RGS_VCAMA2_CAL_INDI_MASK                    0x1
#define PMIC_RGS_VCAMA2_CAL_INDI_SHIFT                   4
#define PMIC_RG_VCAMA2_OC_TRIM_MASK                      0x7
#define PMIC_RG_VCAMA2_OC_TRIM_SHIFT                     8
#define PMIC_RG_VCAMA2_NDIS_EN_MASK                      0x1
#define PMIC_RG_VCAMA2_NDIS_EN_SHIFT                     11
#define PMIC_RG_VCAMA2_STB_SEL_MASK                      0x1
#define PMIC_RG_VCAMA2_STB_SEL_SHIFT                     12
#define PMIC_RG_VCAMA2_RSV_MASK                          0x3
#define PMIC_RG_VCAMA2_RSV_SHIFT                         13
#define PMIC_RG_VCAMA2_VOS_CAL_EN_MASK                   0x1
#define PMIC_RG_VCAMA2_VOS_CAL_EN_SHIFT                  15
#define PMIC_RG_VA18_VOCAL_MASK                          0xF
#define PMIC_RG_VA18_VOCAL_SHIFT                         0
#define PMIC_RG_VA18_VOSEL_MASK                          0xF
#define PMIC_RG_VA18_VOSEL_SHIFT                         8
#define PMIC_RG_VA18_VOTRIM_MASK                         0xF
#define PMIC_RG_VA18_VOTRIM_SHIFT                        0
#define PMIC_RGS_VA18_CAL_INDI_MASK                      0x1
#define PMIC_RGS_VA18_CAL_INDI_SHIFT                     4
#define PMIC_RG_VA18_OC_TRIM_MASK                        0x7
#define PMIC_RG_VA18_OC_TRIM_SHIFT                       8
#define PMIC_RG_VA18_NDIS_EN_MASK                        0x1
#define PMIC_RG_VA18_NDIS_EN_SHIFT                       11
#define PMIC_RG_VA18_STB_SEL_MASK                        0x1
#define PMIC_RG_VA18_STB_SEL_SHIFT                       12
#define PMIC_RG_VA18_RSV_MASK                            0x3
#define PMIC_RG_VA18_RSV_SHIFT                           13
#define PMIC_RG_VA18_VOS_CAL_EN_MASK                     0x1
#define PMIC_RG_VA18_VOS_CAL_EN_SHIFT                    15
#define PMIC_RG_VUSB33_VOCAL_MASK                        0xF
#define PMIC_RG_VUSB33_VOCAL_SHIFT                       0
#define PMIC_RG_VUSB33_VOSEL_MASK                        0xF
#define PMIC_RG_VUSB33_VOSEL_SHIFT                       8
#define PMIC_RG_VUSB33_VOTRIM_MASK                       0xF
#define PMIC_RG_VUSB33_VOTRIM_SHIFT                      0
#define PMIC_RGS_VUSB33_CAL_INDI_MASK                    0x1
#define PMIC_RGS_VUSB33_CAL_INDI_SHIFT                   4
#define PMIC_RG_VUSB33_OC_TRIM_MASK                      0x7
#define PMIC_RG_VUSB33_OC_TRIM_SHIFT                     8
#define PMIC_RG_VUSB33_NDIS_EN_MASK                      0x1
#define PMIC_RG_VUSB33_NDIS_EN_SHIFT                     11
#define PMIC_RG_VUSB33_STB_SEL_MASK                      0x1
#define PMIC_RG_VUSB33_STB_SEL_SHIFT                     12
#define PMIC_RG_VUSB33_RSV_MASK                          0x3
#define PMIC_RG_VUSB33_RSV_SHIFT                         13
#define PMIC_RG_VUSB33_VOS_CAL_EN_MASK                   0x1
#define PMIC_RG_VUSB33_VOS_CAL_EN_SHIFT                  15
#define PMIC_RG_VBIF28_VOCAL_MASK                        0xF
#define PMIC_RG_VBIF28_VOCAL_SHIFT                       0
#define PMIC_RG_VBIF28_VOSEL_MASK                        0xF
#define PMIC_RG_VBIF28_VOSEL_SHIFT                       8
#define PMIC_RG_VBIF28_VOTRIM_MASK                       0xF
#define PMIC_RG_VBIF28_VOTRIM_SHIFT                      0
#define PMIC_RGS_VBIF28_CAL_INDI_MASK                    0x1
#define PMIC_RGS_VBIF28_CAL_INDI_SHIFT                   4
#define PMIC_RG_VBIF28_OC_TRIM_MASK                      0x7
#define PMIC_RG_VBIF28_OC_TRIM_SHIFT                     8
#define PMIC_RG_VBIF28_NDIS_EN_MASK                      0x1
#define PMIC_RG_VBIF28_NDIS_EN_SHIFT                     11
#define PMIC_RG_VBIF28_STB_SEL_MASK                      0x1
#define PMIC_RG_VBIF28_STB_SEL_SHIFT                     12
#define PMIC_RG_VBIF28_RSV_MASK                          0x3
#define PMIC_RG_VBIF28_RSV_SHIFT                         13
#define PMIC_RG_VBIF28_VOS_CAL_EN_MASK                   0x1
#define PMIC_RG_VBIF28_VOS_CAL_EN_SHIFT                  15
#define PMIC_RG_VGP2_VOCAL_MASK                          0xF
#define PMIC_RG_VGP2_VOCAL_SHIFT                         0
#define PMIC_RG_VGP2_VOSEL_MASK                          0xF
#define PMIC_RG_VGP2_VOSEL_SHIFT                         8
#define PMIC_RG_VGP2_VOTRIM_MASK                         0xF
#define PMIC_RG_VGP2_VOTRIM_SHIFT                        0
#define PMIC_RGS_VGP2_CAL_INDI_MASK                      0x1
#define PMIC_RGS_VGP2_CAL_INDI_SHIFT                     4
#define PMIC_RG_VGP2_OC_TRIM_MASK                        0x7
#define PMIC_RG_VGP2_OC_TRIM_SHIFT                       8
#define PMIC_RG_VGP2_NDIS_EN_MASK                        0x1
#define PMIC_RG_VGP2_NDIS_EN_SHIFT                       11
#define PMIC_RG_VGP2_STB_SEL_MASK                        0x1
#define PMIC_RG_VGP2_STB_SEL_SHIFT                       12
#define PMIC_RG_VGP2_RSV_MASK                            0x3
#define PMIC_RG_VGP2_RSV_SHIFT                           13
#define PMIC_RG_VGP2_VOS_CAL_EN_MASK                     0x1
#define PMIC_RG_VGP2_VOS_CAL_EN_SHIFT                    15
#define PMIC_RG_VCN33_VOCAL_MASK                         0xF
#define PMIC_RG_VCN33_VOCAL_SHIFT                        0
#define PMIC_RG_VCN33_VOSEL_MASK                         0xF
#define PMIC_RG_VCN33_VOSEL_SHIFT                        8
#define PMIC_RG_VCN33_VOTRIM_MASK                        0xF
#define PMIC_RG_VCN33_VOTRIM_SHIFT                       0
#define PMIC_RGS_VCN33_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VCN33_CAL_INDI_SHIFT                    4
#define PMIC_RG_VCN33_OC_TRIM_MASK                       0x7
#define PMIC_RG_VCN33_OC_TRIM_SHIFT                      8
#define PMIC_RG_VCN33_NDIS_EN_MASK                       0x1
#define PMIC_RG_VCN33_NDIS_EN_SHIFT                      11
#define PMIC_RG_VCN33_STB_SEL_MASK                       0x1
#define PMIC_RG_VCN33_STB_SEL_SHIFT                      12
#define PMIC_RG_VCN33_RSV_MASK                           0x3
#define PMIC_RG_VCN33_RSV_SHIFT                          13
#define PMIC_RG_VCN33_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VCN33_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VSIM1_VOCAL_MASK                         0xF
#define PMIC_RG_VSIM1_VOCAL_SHIFT                        0
#define PMIC_RG_VSIM1_VOSEL_MASK                         0xF
#define PMIC_RG_VSIM1_VOSEL_SHIFT                        8
#define PMIC_RG_VSIM1_VOTRIM_MASK                        0xF
#define PMIC_RG_VSIM1_VOTRIM_SHIFT                       0
#define PMIC_RGS_VSIM1_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VSIM1_CAL_INDI_SHIFT                    4
#define PMIC_RG_VSIM1_OC_TRIM_MASK                       0x7
#define PMIC_RG_VSIM1_OC_TRIM_SHIFT                      8
#define PMIC_RG_VSIM1_NDIS_EN_MASK                       0x1
#define PMIC_RG_VSIM1_NDIS_EN_SHIFT                      11
#define PMIC_RG_VSIM1_STB_SEL_MASK                       0x1
#define PMIC_RG_VSIM1_STB_SEL_SHIFT                      12
#define PMIC_RG_VSIM1_RSV_MASK                           0x3
#define PMIC_RG_VSIM1_RSV_SHIFT                          13
#define PMIC_RG_VSIM1_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VSIM1_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VSIM2_VOCAL_MASK                         0xF
#define PMIC_RG_VSIM2_VOCAL_SHIFT                        0
#define PMIC_RG_VSIM2_VOSEL_MASK                         0xF
#define PMIC_RG_VSIM2_VOSEL_SHIFT                        8
#define PMIC_RG_VSIM2_VOTRIM_MASK                        0xF
#define PMIC_RG_VSIM2_VOTRIM_SHIFT                       0
#define PMIC_RGS_VSIM2_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VSIM2_CAL_INDI_SHIFT                    4
#define PMIC_RG_VSIM2_OC_TRIM_MASK                       0x7
#define PMIC_RG_VSIM2_OC_TRIM_SHIFT                      8
#define PMIC_RG_VSIM2_NDIS_EN_MASK                       0x1
#define PMIC_RG_VSIM2_NDIS_EN_SHIFT                      11
#define PMIC_RG_VSIM2_STB_SEL_MASK                       0x1
#define PMIC_RG_VSIM2_STB_SEL_SHIFT                      12
#define PMIC_RG_VSIM2_RSV_MASK                           0x3
#define PMIC_RG_VSIM2_RSV_SHIFT                          13
#define PMIC_RG_VSIM2_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VSIM2_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VLDO28_VOCAL_MASK                        0xF
#define PMIC_RG_VLDO28_VOCAL_SHIFT                       0
#define PMIC_RG_VLDO28_VOSEL_MASK                        0xF
#define PMIC_RG_VLDO28_VOSEL_SHIFT                       8
#define PMIC_RG_VLDO28_VOTRIM_MASK                       0xF
#define PMIC_RG_VLDO28_VOTRIM_SHIFT                      0
#define PMIC_RGS_VLDO28_CAL_INDI_MASK                    0x1
#define PMIC_RGS_VLDO28_CAL_INDI_SHIFT                   4
#define PMIC_RG_VLDO28_OC_TRIM_MASK                      0x7
#define PMIC_RG_VLDO28_OC_TRIM_SHIFT                     8
#define PMIC_RG_VLDO28_NDIS_EN_MASK                      0x1
#define PMIC_RG_VLDO28_NDIS_EN_SHIFT                     11
#define PMIC_RG_VLDO28_STB_SEL_MASK                      0x1
#define PMIC_RG_VLDO28_STB_SEL_SHIFT                     12
#define PMIC_RG_VLDO28_RSV_MASK                          0x3
#define PMIC_RG_VLDO28_RSV_SHIFT                         13
#define PMIC_RG_VLDO28_VOS_CAL_EN_MASK                   0x1
#define PMIC_RG_VLDO28_VOS_CAL_EN_SHIFT                  15
#define PMIC_RG_VIO28_VOCAL_MASK                         0xF
#define PMIC_RG_VIO28_VOCAL_SHIFT                        0
#define PMIC_RG_VIO28_VOSEL_MASK                         0xF
#define PMIC_RG_VIO28_VOSEL_SHIFT                        8
#define PMIC_RG_VIO28_VOTRIM_MASK                        0xF
#define PMIC_RG_VIO28_VOTRIM_SHIFT                       0
#define PMIC_RGS_VIO28_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VIO28_CAL_INDI_SHIFT                    4
#define PMIC_RG_VIO28_OC_TRIM_MASK                       0x7
#define PMIC_RG_VIO28_OC_TRIM_SHIFT                      8
#define PMIC_RG_VIO28_NDIS_EN_MASK                       0x1
#define PMIC_RG_VIO28_NDIS_EN_SHIFT                      11
#define PMIC_RG_VIO28_STB_SEL_MASK                       0x1
#define PMIC_RG_VIO28_STB_SEL_SHIFT                      12
#define PMIC_RG_VIO28_RSV_MASK                           0x3
#define PMIC_RG_VIO28_RSV_SHIFT                          13
#define PMIC_RG_VIO28_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VIO28_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VMC_VOCAL_MASK                           0xF
#define PMIC_RG_VMC_VOCAL_SHIFT                          0
#define PMIC_RG_VMC_VOSEL_MASK                           0xF
#define PMIC_RG_VMC_VOSEL_SHIFT                          8
#define PMIC_RG_VMC_VOTRIM_MASK                          0xF
#define PMIC_RG_VMC_VOTRIM_SHIFT                         0
#define PMIC_RGS_VMC_CAL_INDI_MASK                       0x1
#define PMIC_RGS_VMC_CAL_INDI_SHIFT                      4
#define PMIC_RG_VMC_OC_TRIM_MASK                         0x7
#define PMIC_RG_VMC_OC_TRIM_SHIFT                        8
#define PMIC_RG_VMC_NDIS_EN_MASK                         0x1
#define PMIC_RG_VMC_NDIS_EN_SHIFT                        11
#define PMIC_RG_VMC_STB_SEL_MASK                         0x1
#define PMIC_RG_VMC_STB_SEL_SHIFT                        12
#define PMIC_RG_VMC_RSV_MASK                             0x3
#define PMIC_RG_VMC_RSV_SHIFT                            13
#define PMIC_RG_VMC_VOS_CAL_EN_MASK                      0x1
#define PMIC_RG_VMC_VOS_CAL_EN_SHIFT                     15
#define PMIC_RG_VMCH_VOCAL_MASK                          0xF
#define PMIC_RG_VMCH_VOCAL_SHIFT                         0
#define PMIC_RG_VMCH_VOSEL_MASK                          0xF
#define PMIC_RG_VMCH_VOSEL_SHIFT                         8
#define PMIC_RG_VMCH_VOTRIM_MASK                         0xF
#define PMIC_RG_VMCH_VOTRIM_SHIFT                        0
#define PMIC_RGS_VMCH_CAL_INDI_MASK                      0x1
#define PMIC_RGS_VMCH_CAL_INDI_SHIFT                     4
#define PMIC_RG_VMCH_OC_TRIM_MASK                        0x7
#define PMIC_RG_VMCH_OC_TRIM_SHIFT                       8
#define PMIC_RG_VMCH_NDIS_EN_MASK                        0x1
#define PMIC_RG_VMCH_NDIS_EN_SHIFT                       11
#define PMIC_RG_VMCH_STB_SEL_MASK                        0x1
#define PMIC_RG_VMCH_STB_SEL_SHIFT                       12
#define PMIC_RG_VMCH_RSV_MASK                            0x3
#define PMIC_RG_VMCH_RSV_SHIFT                           13
#define PMIC_RG_VMCH_VOS_CAL_EN_MASK                     0x1
#define PMIC_RG_VMCH_VOS_CAL_EN_SHIFT                    15
#define PMIC_RG_VEMC_VOCAL_MASK                          0xF
#define PMIC_RG_VEMC_VOCAL_SHIFT                         0
#define PMIC_RG_VEMC_VOSEL_MASK                          0xF
#define PMIC_RG_VEMC_VOSEL_SHIFT                         8
#define PMIC_RG_VEMC_VOTRIM_MASK                         0xF
#define PMIC_RG_VEMC_VOTRIM_SHIFT                        0
#define PMIC_RGS_VEMC_CAL_INDI_MASK                      0x1
#define PMIC_RGS_VEMC_CAL_INDI_SHIFT                     4
#define PMIC_RG_VEMC_OC_TRIM_MASK                        0x7
#define PMIC_RG_VEMC_OC_TRIM_SHIFT                       8
#define PMIC_RG_VEMC_NDIS_EN_MASK                        0x1
#define PMIC_RG_VEMC_NDIS_EN_SHIFT                       11
#define PMIC_RG_VEMC_STB_SEL_MASK                        0x1
#define PMIC_RG_VEMC_STB_SEL_SHIFT                       12
#define PMIC_RG_VEMC_RSV_MASK                            0x3
#define PMIC_RG_VEMC_RSV_SHIFT                           13
#define PMIC_RG_VEMC_VOS_CAL_EN_MASK                     0x1
#define PMIC_RG_VEMC_VOS_CAL_EN_SHIFT                    15
#define PMIC_RG_VGP_VOCAL_MASK                           0xF
#define PMIC_RG_VGP_VOCAL_SHIFT                          0
#define PMIC_RG_VGP_VOSEL_MASK                           0xF
#define PMIC_RG_VGP_VOSEL_SHIFT                          8
#define PMIC_RG_VGP_VOTRIM_MASK                          0xF
#define PMIC_RG_VGP_VOTRIM_SHIFT                         0
#define PMIC_RGS_VGP_CAL_INDI_MASK                       0x1
#define PMIC_RGS_VGP_CAL_INDI_SHIFT                      4
#define PMIC_RG_VGP_OC_TRIM_MASK                         0x7
#define PMIC_RG_VGP_OC_TRIM_SHIFT                        8
#define PMIC_RG_VGP_NDIS_EN_MASK                         0x1
#define PMIC_RG_VGP_NDIS_EN_SHIFT                        11
#define PMIC_RG_VGP_STB_SEL_MASK                         0x1
#define PMIC_RG_VGP_STB_SEL_SHIFT                        12
#define PMIC_RG_VGP_RSV_MASK                             0x3
#define PMIC_RG_VGP_RSV_SHIFT                            13
#define PMIC_RG_VGP_VOS_CAL_EN_MASK                      0x1
#define PMIC_RG_VGP_VOS_CAL_EN_SHIFT                     15
#define PMIC_RG_VRF18_1_VOCAL_MASK                       0xF
#define PMIC_RG_VRF18_1_VOCAL_SHIFT                      0
#define PMIC_RG_VRF18_1_VOSEL_MASK                       0xF
#define PMIC_RG_VRF18_1_VOSEL_SHIFT                      8
#define PMIC_RG_VRF18_1_VOTRIM_MASK                      0xF
#define PMIC_RG_VRF18_1_VOTRIM_SHIFT                     0
#define PMIC_RGS_VRF18_1_CAL_INDI_MASK                   0x1
#define PMIC_RGS_VRF18_1_CAL_INDI_SHIFT                  4
#define PMIC_RG_VRF18_1_OC_TRIM_MASK                     0x7
#define PMIC_RG_VRF18_1_OC_TRIM_SHIFT                    8
#define PMIC_RG_VRF18_1_NDIS_EN_MASK                     0x1
#define PMIC_RG_VRF18_1_NDIS_EN_SHIFT                    11
#define PMIC_RG_VRF18_1_STB_SEL_MASK                     0x1
#define PMIC_RG_VRF18_1_STB_SEL_SHIFT                    12
#define PMIC_RG_VRF18_1_RSV_MASK                         0x3
#define PMIC_RG_VRF18_1_RSV_SHIFT                        13
#define PMIC_RG_VRF18_1_VOS_CAL_EN_MASK                  0x1
#define PMIC_RG_VRF18_1_VOS_CAL_EN_SHIFT                 15
#define PMIC_RG_VRF18_2_VOCAL_MASK                       0xF
#define PMIC_RG_VRF18_2_VOCAL_SHIFT                      0
#define PMIC_RG_VRF18_2_VOSEL_MASK                       0xF
#define PMIC_RG_VRF18_2_VOSEL_SHIFT                      8
#define PMIC_RG_VRF18_2_VOTRIM_MASK                      0xF
#define PMIC_RG_VRF18_2_VOTRIM_SHIFT                     0
#define PMIC_RGS_VRF18_2_CAL_INDI_MASK                   0x1
#define PMIC_RGS_VRF18_2_CAL_INDI_SHIFT                  4
#define PMIC_RG_VRF18_2_OC_TRIM_MASK                     0x7
#define PMIC_RG_VRF18_2_OC_TRIM_SHIFT                    8
#define PMIC_RG_VRF18_2_NDIS_EN_MASK                     0x1
#define PMIC_RG_VRF18_2_NDIS_EN_SHIFT                    11
#define PMIC_RG_VRF18_2_STB_SEL_MASK                     0x1
#define PMIC_RG_VRF18_2_STB_SEL_SHIFT                    12
#define PMIC_RG_VRF18_2_RSV_MASK                         0x3
#define PMIC_RG_VRF18_2_RSV_SHIFT                        13
#define PMIC_RG_VRF18_2_VOS_CAL_EN_MASK                  0x1
#define PMIC_RG_VRF18_2_VOS_CAL_EN_SHIFT                 15
#define PMIC_RG_VCN18_VOCAL_MASK                         0xF
#define PMIC_RG_VCN18_VOCAL_SHIFT                        0
#define PMIC_RG_VCN18_VOSEL_MASK                         0xF
#define PMIC_RG_VCN18_VOSEL_SHIFT                        8
#define PMIC_RG_VCN18_VOTRIM_MASK                        0xF
#define PMIC_RG_VCN18_VOTRIM_SHIFT                       0
#define PMIC_RGS_VCN18_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VCN18_CAL_INDI_SHIFT                    4
#define PMIC_RG_VCN18_OC_TRIM_MASK                       0x7
#define PMIC_RG_VCN18_OC_TRIM_SHIFT                      8
#define PMIC_RG_VCN18_NDIS_EN_MASK                       0x1
#define PMIC_RG_VCN18_NDIS_EN_SHIFT                      11
#define PMIC_RG_VCN18_STB_SEL_MASK                       0x1
#define PMIC_RG_VCN18_STB_SEL_SHIFT                      12
#define PMIC_RG_VCN18_RSV_MASK                           0x3
#define PMIC_RG_VCN18_RSV_SHIFT                          13
#define PMIC_RG_VCN18_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VCN18_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VCAMIO_VOCAL_MASK                        0xF
#define PMIC_RG_VCAMIO_VOCAL_SHIFT                       0
#define PMIC_RG_VCAMIO_VOSEL_MASK                        0xF
#define PMIC_RG_VCAMIO_VOSEL_SHIFT                       8
#define PMIC_RG_VCAMIO_VOTRIM_MASK                       0xF
#define PMIC_RG_VCAMIO_VOTRIM_SHIFT                      0
#define PMIC_RGS_VCAMIO_CAL_INDI_MASK                    0x1
#define PMIC_RGS_VCAMIO_CAL_INDI_SHIFT                   4
#define PMIC_RG_VCAMIO_OC_TRIM_MASK                      0x7
#define PMIC_RG_VCAMIO_OC_TRIM_SHIFT                     8
#define PMIC_RG_VCAMIO_NDIS_EN_MASK                      0x1
#define PMIC_RG_VCAMIO_NDIS_EN_SHIFT                     11
#define PMIC_RG_VCAMIO_STB_SEL_MASK                      0x1
#define PMIC_RG_VCAMIO_STB_SEL_SHIFT                     12
#define PMIC_RG_VCAMIO_RSV_MASK                          0x3
#define PMIC_RG_VCAMIO_RSV_SHIFT                         13
#define PMIC_RG_VCAMIO_VOS_CAL_EN_MASK                   0x1
#define PMIC_RG_VCAMIO_VOS_CAL_EN_SHIFT                  15
#define PMIC_RG_VMIPI_VOCAL_MASK                         0xF
#define PMIC_RG_VMIPI_VOCAL_SHIFT                        0
#define PMIC_RG_VMIPI_VOSEL_MASK                         0xF
#define PMIC_RG_VMIPI_VOSEL_SHIFT                        8
#define PMIC_RG_VMIPI_VOTRIM_MASK                        0xF
#define PMIC_RG_VMIPI_VOTRIM_SHIFT                       0
#define PMIC_RGS_VMIPI_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VMIPI_CAL_INDI_SHIFT                    4
#define PMIC_RG_VMIPI_OC_TRIM_MASK                       0x7
#define PMIC_RG_VMIPI_OC_TRIM_SHIFT                      8
#define PMIC_RG_VMIPI_NDIS_EN_MASK                       0x1
#define PMIC_RG_VMIPI_NDIS_EN_SHIFT                      11
#define PMIC_RG_VMIPI_STB_SEL_MASK                       0x1
#define PMIC_RG_VMIPI_STB_SEL_SHIFT                      12
#define PMIC_RG_VMIPI_RSV_MASK                           0x3
#define PMIC_RG_VMIPI_RSV_SHIFT                          13
#define PMIC_RG_VMIPI_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VMIPI_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VUFS18_VOCAL_MASK                        0xF
#define PMIC_RG_VUFS18_VOCAL_SHIFT                       0
#define PMIC_RG_VUFS18_VOSEL_MASK                        0xF
#define PMIC_RG_VUFS18_VOSEL_SHIFT                       8
#define PMIC_RG_VUFS18_VOTRIM_MASK                       0xF
#define PMIC_RG_VUFS18_VOTRIM_SHIFT                      0
#define PMIC_RGS_VUFS18_CAL_INDI_MASK                    0x1
#define PMIC_RGS_VUFS18_CAL_INDI_SHIFT                   4
#define PMIC_RG_VUFS18_OC_TRIM_MASK                      0x7
#define PMIC_RG_VUFS18_OC_TRIM_SHIFT                     8
#define PMIC_RG_VUFS18_NDIS_EN_MASK                      0x1
#define PMIC_RG_VUFS18_NDIS_EN_SHIFT                     11
#define PMIC_RG_VUFS18_STB_SEL_MASK                      0x1
#define PMIC_RG_VUFS18_STB_SEL_SHIFT                     12
#define PMIC_RG_VUFS18_RSV_MASK                          0x3
#define PMIC_RG_VUFS18_RSV_SHIFT                         13
#define PMIC_RG_VUFS18_VOS_CAL_EN_MASK                   0x1
#define PMIC_RG_VUFS18_VOS_CAL_EN_SHIFT                  15
#define PMIC_RG_VIO18_VOCAL_MASK                         0xF
#define PMIC_RG_VIO18_VOCAL_SHIFT                        0
#define PMIC_RG_VIO18_VOSEL_MASK                         0xF
#define PMIC_RG_VIO18_VOSEL_SHIFT                        8
#define PMIC_RG_VIO18_VOTRIM_MASK                        0xF
#define PMIC_RG_VIO18_VOTRIM_SHIFT                       0
#define PMIC_RGS_VIO18_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VIO18_CAL_INDI_SHIFT                    4
#define PMIC_RG_VIO18_OC_TRIM_MASK                       0x7
#define PMIC_RG_VIO18_OC_TRIM_SHIFT                      8
#define PMIC_RG_VIO18_NDIS_EN_MASK                       0x1
#define PMIC_RG_VIO18_NDIS_EN_SHIFT                      11
#define PMIC_RG_VIO18_STB_SEL_MASK                       0x1
#define PMIC_RG_VIO18_STB_SEL_SHIFT                      12
#define PMIC_RG_VIO18_RSV_MASK                           0x3
#define PMIC_RG_VIO18_RSV_SHIFT                          13
#define PMIC_RG_VIO18_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VIO18_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VXO18_VOCAL_MASK                         0xF
#define PMIC_RG_VXO18_VOCAL_SHIFT                        0
#define PMIC_RG_VXO18_VOSEL_MASK                         0xF
#define PMIC_RG_VXO18_VOSEL_SHIFT                        8
#define PMIC_RG_VXO18_VOTRIM_MASK                        0xF
#define PMIC_RG_VXO18_VOTRIM_SHIFT                       0
#define PMIC_RGS_VXO18_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VXO18_CAL_INDI_SHIFT                    4
#define PMIC_RG_VXO18_OC_TRIM_MASK                       0x7
#define PMIC_RG_VXO18_OC_TRIM_SHIFT                      8
#define PMIC_RG_VXO18_NDIS_EN_MASK                       0x1
#define PMIC_RG_VXO18_NDIS_EN_SHIFT                      11
#define PMIC_RG_VXO18_STB_SEL_MASK                       0x1
#define PMIC_RG_VXO18_STB_SEL_SHIFT                      12
#define PMIC_RG_VXO18_RSV_MASK                           0x3
#define PMIC_RG_VXO18_RSV_SHIFT                          13
#define PMIC_RG_VXO18_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VXO18_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VRF12_VOCAL_MASK                         0xF
#define PMIC_RG_VRF12_VOCAL_SHIFT                        0
#define PMIC_RG_VRF12_VOSEL_MASK                         0xF
#define PMIC_RG_VRF12_VOSEL_SHIFT                        8
#define PMIC_RG_VRF12_VOTRIM_MASK                        0xF
#define PMIC_RG_VRF12_VOTRIM_SHIFT                       0
#define PMIC_RGS_VRF12_CAL_INDI_MASK                     0x1
#define PMIC_RGS_VRF12_CAL_INDI_SHIFT                    4
#define PMIC_RG_VRF12_OC_TRIM_MASK                       0x7
#define PMIC_RG_VRF12_OC_TRIM_SHIFT                      8
#define PMIC_RG_VRF12_NDIS_EN_MASK                       0x1
#define PMIC_RG_VRF12_NDIS_EN_SHIFT                      11
#define PMIC_RG_VRF12_STB_SEL_MASK                       0x1
#define PMIC_RG_VRF12_STB_SEL_SHIFT                      12
#define PMIC_RG_VRF12_RSV_MASK                           0x3
#define PMIC_RG_VRF12_RSV_SHIFT                          13
#define PMIC_RG_VRF12_VOS_CAL_EN_MASK                    0x1
#define PMIC_RG_VRF12_VOS_CAL_EN_SHIFT                   15
#define PMIC_RG_VCAMD1_VOCAL_MASK                        0xF
#define PMIC_RG_VCAMD1_VOCAL_SHIFT                       0
#define PMIC_RG_VCAMD1_VOSEL_MASK                        0xF
#define PMIC_RG_VCAMD1_VOSEL_SHIFT                       8
#define PMIC_RG_VCAMD1_VOTRIM_MASK                       0xF
#define PMIC_RG_VCAMD1_VOTRIM_SHIFT                      0
#define PMIC_RGS_VCAMD1_CAL_INDI_MASK                    0x1
#define PMIC_RGS_VCAMD1_CAL_INDI_SHIFT                   4
#define PMIC_RG_VCAMD1_OC_TRIM_MASK                      0x7
#define PMIC_RG_VCAMD1_OC_TRIM_SHIFT                     8
#define PMIC_RG_VCAMD1_NDIS_EN_MASK                      0x1
#define PMIC_RG_VCAMD1_NDIS_EN_SHIFT                     11
#define PMIC_RG_VCAMD1_STB_SEL_MASK                      0x1
#define PMIC_RG_VCAMD1_STB_SEL_SHIFT                     12
#define PMIC_RG_VCAMD1_RSV_MASK                          0x3
#define PMIC_RG_VCAMD1_RSV_SHIFT                         13
#define PMIC_RG_VCAMD1_VOS_CAL_EN_MASK                   0x1
#define PMIC_RG_VCAMD1_VOS_CAL_EN_SHIFT                  15
#define PMIC_RG_VCAMD2_VOCAL_MASK                        0xF
#define PMIC_RG_VCAMD2_VOCAL_SHIFT                       0
#define PMIC_RG_VCAMD2_VOSEL_MASK                        0xF
#define PMIC_RG_VCAMD2_VOSEL_SHIFT                       8
#define PMIC_RG_VCAMD2_VOTRIM_MASK                       0xF
#define PMIC_RG_VCAMD2_VOTRIM_SHIFT                      0
#define PMIC_RGS_VCAMD2_CAL_INDI_MASK                    0x1
#define PMIC_RGS_VCAMD2_CAL_INDI_SHIFT                   4
#define PMIC_RG_VCAMD2_OC_TRIM_MASK                      0x7
#define PMIC_RG_VCAMD2_OC_TRIM_SHIFT                     8
#define PMIC_RG_VCAMD2_NDIS_EN_MASK                      0x1
#define PMIC_RG_VCAMD2_NDIS_EN_SHIFT                     11
#define PMIC_RG_VCAMD2_STB_SEL_MASK                      0x1
#define PMIC_RG_VCAMD2_STB_SEL_SHIFT                     12
#define PMIC_RG_VCAMD2_RSV_MASK                          0x3
#define PMIC_RG_VCAMD2_RSV_SHIFT                         13
#define PMIC_RG_VCAMD2_VOS_CAL_EN_MASK                   0x1
#define PMIC_RG_VCAMD2_VOS_CAL_EN_SHIFT                  15
#define PMIC_RG_VA10_VOTRIM_MASK                         0xF
#define PMIC_RG_VA10_VOTRIM_SHIFT                        0
#define PMIC_RGS_VA10_CAL_INDI_MASK                      0x1
#define PMIC_RGS_VA10_CAL_INDI_SHIFT                     4
#define PMIC_RG_VA10_OC_TRIM_MASK                        0x7
#define PMIC_RG_VA10_OC_TRIM_SHIFT                       8
#define PMIC_RG_VA10_NDIS_EN_MASK                        0x1
#define PMIC_RG_VA10_NDIS_EN_SHIFT                       11
#define PMIC_RG_VA10_STB_SEL_MASK                        0x1
#define PMIC_RG_VA10_STB_SEL_SHIFT                       12
#define PMIC_RG_VA10_RSV_MASK                            0x3
#define PMIC_RG_VA10_RSV_SHIFT                           13
#define PMIC_RG_VA10_VOS_CAL_EN_MASK                     0x1
#define PMIC_RG_VA10_VOS_CAL_EN_SHIFT                    15
#define PMIC_RG_VA12_VOCAL_MASK                          0xF
#define PMIC_RG_VA12_VOCAL_SHIFT                         0
#define PMIC_RG_VA12_VOSEL_MASK                          0xF
#define PMIC_RG_VA12_VOSEL_SHIFT                         8
#define PMIC_RG_VA12_VOTRIM_MASK                         0xF
#define PMIC_RG_VA12_VOTRIM_SHIFT                        0
#define PMIC_RGS_VA12_CAL_INDI_MASK                      0x1
#define PMIC_RGS_VA12_CAL_INDI_SHIFT                     4
#define PMIC_RG_VA12_OC_TRIM_MASK                        0x7
#define PMIC_RG_VA12_OC_TRIM_SHIFT                       8
#define PMIC_RG_VA12_NDIS_EN_MASK                        0x1
#define PMIC_RG_VA12_NDIS_EN_SHIFT                       11
#define PMIC_RG_VA12_STB_SEL_MASK                        0x1
#define PMIC_RG_VA12_STB_SEL_SHIFT                       12
#define PMIC_RG_VA12_RSV_MASK                            0x3
#define PMIC_RG_VA12_RSV_SHIFT                           13
#define PMIC_RG_VA12_VOS_CAL_EN_MASK                     0x1
#define PMIC_RG_VA12_VOS_CAL_EN_SHIFT                    15
#define PMIC_RG_VSRAM_PROC_OC_TRIM_MASK                  0xF
#define PMIC_RG_VSRAM_PROC_OC_TRIM_SHIFT                 0
#define PMIC_RG_VSRAM_PROC_STB_SEL_MASK                  0x1
#define PMIC_RG_VSRAM_PROC_STB_SEL_SHIFT                 4
#define PMIC_RG_VSRAM_PROC_NDIS_EN_MASK                  0x1
#define PMIC_RG_VSRAM_PROC_NDIS_EN_SHIFT                 5
#define PMIC_RG_VSRAM_PROC_NDIS_PLCUR_MASK               0x3
#define PMIC_RG_VSRAM_PROC_NDIS_PLCUR_SHIFT              6
#define PMIC_RG_VSRAM_PROC_PLCUR_EN_MASK                 0x1
#define PMIC_RG_VSRAM_PROC_PLCUR_EN_SHIFT                8
#define PMIC_RG_VSRAM_PROC_RSV_H_MASK                    0x7
#define PMIC_RG_VSRAM_PROC_RSV_H_SHIFT                   9
#define PMIC_RG_VSRAM_PROC_RSV_L_MASK                    0x7
#define PMIC_RG_VSRAM_PROC_RSV_L_SHIFT                   12
#define PMIC_RG_VSRAM_CORE_OC_TRIM_MASK                  0xF
#define PMIC_RG_VSRAM_CORE_OC_TRIM_SHIFT                 0
#define PMIC_RG_VSRAM_CORE_STB_SEL_MASK                  0x1
#define PMIC_RG_VSRAM_CORE_STB_SEL_SHIFT                 4
#define PMIC_RG_VSRAM_CORE_NDIS_EN_MASK                  0x1
#define PMIC_RG_VSRAM_CORE_NDIS_EN_SHIFT                 5
#define PMIC_RG_VSRAM_CORE_NDIS_PLCUR_MASK               0x3
#define PMIC_RG_VSRAM_CORE_NDIS_PLCUR_SHIFT              6
#define PMIC_RG_VSRAM_CORE_PLCUR_EN_MASK                 0x1
#define PMIC_RG_VSRAM_CORE_PLCUR_EN_SHIFT                8
#define PMIC_RG_VSRAM_CORE_RSV_H_MASK                    0x7
#define PMIC_RG_VSRAM_CORE_RSV_H_SHIFT                   9
#define PMIC_RG_VSRAM_CORE_RSV_L_MASK                    0x7
#define PMIC_RG_VSRAM_CORE_RSV_L_SHIFT                   12
#define PMIC_RG_VSRAM_GPU_OC_TRIM_MASK                   0xF
#define PMIC_RG_VSRAM_GPU_OC_TRIM_SHIFT                  0
#define PMIC_RG_VSRAM_GPU_STB_SEL_MASK                   0x1
#define PMIC_RG_VSRAM_GPU_STB_SEL_SHIFT                  4
#define PMIC_RG_VSRAM_GPU_NDIS_EN_MASK                   0x1
#define PMIC_RG_VSRAM_GPU_NDIS_EN_SHIFT                  5
#define PMIC_RG_VSRAM_GPU_NDIS_PLCUR_MASK                0x3
#define PMIC_RG_VSRAM_GPU_NDIS_PLCUR_SHIFT               6
#define PMIC_RG_VSRAM_GPU_PLCUR_EN_MASK                  0x1
#define PMIC_RG_VSRAM_GPU_PLCUR_EN_SHIFT                 8
#define PMIC_RG_VSRAM_GPU_RSV_H_MASK                     0x7
#define PMIC_RG_VSRAM_GPU_RSV_H_SHIFT                    9
#define PMIC_RG_VSRAM_GPU_RSV_L_MASK                     0x7
#define PMIC_RG_VSRAM_GPU_RSV_L_SHIFT                    12
#define PMIC_RG_VSRAM_MD_OC_TRIM_MASK                    0xF
#define PMIC_RG_VSRAM_MD_OC_TRIM_SHIFT                   0
#define PMIC_RG_VSRAM_MD_STB_SEL_MASK                    0x1
#define PMIC_RG_VSRAM_MD_STB_SEL_SHIFT                   4
#define PMIC_RG_VSRAM_MD_NDIS_EN_MASK                    0x1
#define PMIC_RG_VSRAM_MD_NDIS_EN_SHIFT                   5
#define PMIC_RG_VSRAM_MD_NDIS_PLCUR_MASK                 0x3
#define PMIC_RG_VSRAM_MD_NDIS_PLCUR_SHIFT                6
#define PMIC_RG_VSRAM_MD_PLCUR_EN_MASK                   0x1
#define PMIC_RG_VSRAM_MD_PLCUR_EN_SHIFT                  8
#define PMIC_RG_VSRAM_MD_RSV_H_MASK                      0x7
#define PMIC_RG_VSRAM_MD_RSV_H_SHIFT                     9
#define PMIC_RG_VSRAM_MD_RSV_L_MASK                      0x7
#define PMIC_RG_VSRAM_MD_RSV_L_SHIFT                     12
#define PMIC_AUDACCDETAUXADCSWCTRL_MASK                  0x1
#define PMIC_AUDACCDETAUXADCSWCTRL_SHIFT                 10
#define PMIC_AUDACCDETAUXADCSWCTRL_SEL_MASK              0x1
#define PMIC_AUDACCDETAUXADCSWCTRL_SEL_SHIFT             11
#define PMIC_RG_AUDACCDETRSV_MASK                        0x3
#define PMIC_RG_AUDACCDETRSV_SHIFT                       13
#define PMIC_ACCDET_EN_MASK                              0x1
#define PMIC_ACCDET_EN_SHIFT                             0
#define PMIC_ACCDET_SEQ_INIT_MASK                        0x1
#define PMIC_ACCDET_SEQ_INIT_SHIFT                       1
#define PMIC_ACCDET_EINTDET_EN_MASK                      0x1
#define PMIC_ACCDET_EINTDET_EN_SHIFT                     2
#define PMIC_ACCDET_EINT_SEQ_INIT_MASK                   0x1
#define PMIC_ACCDET_EINT_SEQ_INIT_SHIFT                  3
#define PMIC_ACCDET_ANASWCTRL_SEL_MASK                   0x1
#define PMIC_ACCDET_ANASWCTRL_SEL_SHIFT                  6
#define PMIC_ACCDET_CMP_PWM_EN_MASK                      0x1
#define PMIC_ACCDET_CMP_PWM_EN_SHIFT                     0
#define PMIC_ACCDET_VTH_PWM_EN_MASK                      0x1
#define PMIC_ACCDET_VTH_PWM_EN_SHIFT                     1
#define PMIC_ACCDET_MBIAS_PWM_EN_MASK                    0x1
#define PMIC_ACCDET_MBIAS_PWM_EN_SHIFT                   2
#define PMIC_ACCDET_EINT_PWM_EN_MASK                     0x1
#define PMIC_ACCDET_EINT_PWM_EN_SHIFT                    3
#define PMIC_ACCDET_CMP_PWM_IDLE_MASK                    0x1
#define PMIC_ACCDET_CMP_PWM_IDLE_SHIFT                   4
#define PMIC_ACCDET_VTH_PWM_IDLE_MASK                    0x1
#define PMIC_ACCDET_VTH_PWM_IDLE_SHIFT                   5
#define PMIC_ACCDET_MBIAS_PWM_IDLE_MASK                  0x1
#define PMIC_ACCDET_MBIAS_PWM_IDLE_SHIFT                 6
#define PMIC_ACCDET_EINT_PWM_IDLE_MASK                   0x1
#define PMIC_ACCDET_EINT_PWM_IDLE_SHIFT                  7
#define PMIC_ACCDET_PWM_WIDTH_MASK                       0xFFFF
#define PMIC_ACCDET_PWM_WIDTH_SHIFT                      0
#define PMIC_ACCDET_PWM_THRESH_MASK                      0xFFFF
#define PMIC_ACCDET_PWM_THRESH_SHIFT                     0
#define PMIC_ACCDET_RISE_DELAY_MASK                      0x7FFF
#define PMIC_ACCDET_RISE_DELAY_SHIFT                     0
#define PMIC_ACCDET_FALL_DELAY_MASK                      0x1
#define PMIC_ACCDET_FALL_DELAY_SHIFT                     15
#define PMIC_ACCDET_DEBOUNCE0_MASK                       0xFFFF
#define PMIC_ACCDET_DEBOUNCE0_SHIFT                      0
#define PMIC_ACCDET_DEBOUNCE1_MASK                       0xFFFF
#define PMIC_ACCDET_DEBOUNCE1_SHIFT                      0
#define PMIC_ACCDET_DEBOUNCE2_MASK                       0xFFFF
#define PMIC_ACCDET_DEBOUNCE2_SHIFT                      0
#define PMIC_ACCDET_DEBOUNCE3_MASK                       0xFFFF
#define PMIC_ACCDET_DEBOUNCE3_SHIFT                      0
#define PMIC_ACCDET_DEBOUNCE4_MASK                       0xFFFF
#define PMIC_ACCDET_DEBOUNCE4_SHIFT                      0
#define PMIC_ACCDET_IVAL_CUR_IN_MASK                     0x3
#define PMIC_ACCDET_IVAL_CUR_IN_SHIFT                    0
#define PMIC_ACCDET_EINT_IVAL_CUR_IN_MASK                0x1
#define PMIC_ACCDET_EINT_IVAL_CUR_IN_SHIFT               2
#define PMIC_ACCDET_IVAL_SAM_IN_MASK                     0x3
#define PMIC_ACCDET_IVAL_SAM_IN_SHIFT                    4
#define PMIC_ACCDET_EINT_IVAL_SAM_IN_MASK                0x1
#define PMIC_ACCDET_EINT_IVAL_SAM_IN_SHIFT               6
#define PMIC_ACCDET_IVAL_MEM_IN_MASK                     0x3
#define PMIC_ACCDET_IVAL_MEM_IN_SHIFT                    8
#define PMIC_ACCDET_EINT_IVAL_MEM_IN_MASK                0x1
#define PMIC_ACCDET_EINT_IVAL_MEM_IN_SHIFT               10
#define PMIC_ACCDET_EINT_IVAL_SEL_MASK                   0x1
#define PMIC_ACCDET_EINT_IVAL_SEL_SHIFT                  14
#define PMIC_ACCDET_IVAL_SEL_MASK                        0x1
#define PMIC_ACCDET_IVAL_SEL_SHIFT                       15
#define PMIC_ACCDET_IRQ_MASK                             0x1
#define PMIC_ACCDET_IRQ_SHIFT                            0
#define PMIC_ACCDET_EINT_IRQ_MASK                        0x1
#define PMIC_ACCDET_EINT_IRQ_SHIFT                       2
#define PMIC_ACCDET_IRQ_CLR_MASK                         0x1
#define PMIC_ACCDET_IRQ_CLR_SHIFT                        8
#define PMIC_ACCDET_EINT_IRQ_CLR_MASK                    0x1
#define PMIC_ACCDET_EINT_IRQ_CLR_SHIFT                   10
#define PMIC_ACCDET_EINT_IRQ_POLARITY_MASK               0x1
#define PMIC_ACCDET_EINT_IRQ_POLARITY_SHIFT              15
#define PMIC_ACCDET_TEST_MODE0_MASK                      0x1
#define PMIC_ACCDET_TEST_MODE0_SHIFT                     0
#define PMIC_ACCDET_CMP_SWSEL_MASK                       0x1
#define PMIC_ACCDET_CMP_SWSEL_SHIFT                      1
#define PMIC_ACCDET_VTH_SWSEL_MASK                       0x1
#define PMIC_ACCDET_VTH_SWSEL_SHIFT                      2
#define PMIC_ACCDET_MBIAS_SWSEL_MASK                     0x1
#define PMIC_ACCDET_MBIAS_SWSEL_SHIFT                    3
#define PMIC_ACCDET_TEST_MODE4_MASK                      0x1
#define PMIC_ACCDET_TEST_MODE4_SHIFT                     4
#define PMIC_ACCDET_TEST_MODE5_MASK                      0x1
#define PMIC_ACCDET_TEST_MODE5_SHIFT                     5
#define PMIC_ACCDET_PWM_SEL_MASK                         0x3
#define PMIC_ACCDET_PWM_SEL_SHIFT                        6
#define PMIC_ACCDET_IN_SW_MASK                           0x3
#define PMIC_ACCDET_IN_SW_SHIFT                          8
#define PMIC_ACCDET_CMP_EN_SW_MASK                       0x1
#define PMIC_ACCDET_CMP_EN_SW_SHIFT                      12
#define PMIC_ACCDET_VTH_EN_SW_MASK                       0x1
#define PMIC_ACCDET_VTH_EN_SW_SHIFT                      13
#define PMIC_ACCDET_MBIAS_EN_SW_MASK                     0x1
#define PMIC_ACCDET_MBIAS_EN_SW_SHIFT                    14
#define PMIC_ACCDET_PWM_EN_SW_MASK                       0x1
#define PMIC_ACCDET_PWM_EN_SW_SHIFT                      15
#define PMIC_ACCDET_IN_MASK                              0x3
#define PMIC_ACCDET_IN_SHIFT                             0
#define PMIC_ACCDET_CUR_IN_MASK                          0x3
#define PMIC_ACCDET_CUR_IN_SHIFT                         2
#define PMIC_ACCDET_SAM_IN_MASK                          0x3
#define PMIC_ACCDET_SAM_IN_SHIFT                         4
#define PMIC_ACCDET_MEM_IN_MASK                          0x3
#define PMIC_ACCDET_MEM_IN_SHIFT                         6
#define PMIC_ACCDET_STATE_MASK                           0x7
#define PMIC_ACCDET_STATE_SHIFT                          8
#define PMIC_ACCDET_MBIAS_CLK_MASK                       0x1
#define PMIC_ACCDET_MBIAS_CLK_SHIFT                      12
#define PMIC_ACCDET_VTH_CLK_MASK                         0x1
#define PMIC_ACCDET_VTH_CLK_SHIFT                        13
#define PMIC_ACCDET_CMP_CLK_MASK                         0x1
#define PMIC_ACCDET_CMP_CLK_SHIFT                        14
#define PMIC_DA_AUDACCDETAUXADCSWCTRL_MASK               0x1
#define PMIC_DA_AUDACCDETAUXADCSWCTRL_SHIFT              15
#define PMIC_ACCDET_EINT_DEB_SEL_MASK                    0x1
#define PMIC_ACCDET_EINT_DEB_SEL_SHIFT                   0
#define PMIC_ACCDET_EINT_DEBOUNCE_MASK                   0xF
#define PMIC_ACCDET_EINT_DEBOUNCE_SHIFT                  3
#define PMIC_ACCDET_EINT_PWM_THRESH_MASK                 0x7
#define PMIC_ACCDET_EINT_PWM_THRESH_SHIFT                8
#define PMIC_ACCDET_EINT_PWM_WIDTH_MASK                  0x3
#define PMIC_ACCDET_EINT_PWM_WIDTH_SHIFT                 12
#define PMIC_ACCDET_EINT_PWM_FALL_DELAY_MASK             0x1
#define PMIC_ACCDET_EINT_PWM_FALL_DELAY_SHIFT            5
#define PMIC_ACCDET_EINT_PWM_RISE_DELAY_MASK             0x3FF
#define PMIC_ACCDET_EINT_PWM_RISE_DELAY_SHIFT            6
#define PMIC_ACCDET_TEST_MODE13_MASK                     0x1
#define PMIC_ACCDET_TEST_MODE13_SHIFT                    1
#define PMIC_ACCDET_TEST_MODE12_MASK                     0x1
#define PMIC_ACCDET_TEST_MODE12_SHIFT                    2
#define PMIC_ACCDET_TEST_MODE11_MASK                     0x1
#define PMIC_ACCDET_TEST_MODE11_SHIFT                    5
#define PMIC_ACCDET_TEST_MODE10_MASK                     0x1
#define PMIC_ACCDET_TEST_MODE10_SHIFT                    6
#define PMIC_ACCDET_EINTCMPOUT_SW_MASK                   0x1
#define PMIC_ACCDET_EINTCMPOUT_SW_SHIFT                  7
#define PMIC_ACCDET_TEST_MODE9_MASK                      0x1
#define PMIC_ACCDET_TEST_MODE9_SHIFT                     9
#define PMIC_ACCDET_TEST_MODE8_MASK                      0x1
#define PMIC_ACCDET_TEST_MODE8_SHIFT                     10
#define PMIC_ACCDET_AUXADC_CTRL_SW_MASK                  0x1
#define PMIC_ACCDET_AUXADC_CTRL_SW_SHIFT                 11
#define PMIC_ACCDET_TEST_MODE7_MASK                      0x1
#define PMIC_ACCDET_TEST_MODE7_SHIFT                     13
#define PMIC_ACCDET_TEST_MODE6_MASK                      0x1
#define PMIC_ACCDET_TEST_MODE6_SHIFT                     14
#define PMIC_ACCDET_EINTCMP_EN_SW_MASK                   0x1
#define PMIC_ACCDET_EINTCMP_EN_SW_SHIFT                  15
#define PMIC_ACCDET_EINT_STATE_MASK                      0x7
#define PMIC_ACCDET_EINT_STATE_SHIFT                     0
#define PMIC_ACCDET_AUXADC_DEBOUNCE_END_MASK             0x1
#define PMIC_ACCDET_AUXADC_DEBOUNCE_END_SHIFT            3
#define PMIC_ACCDET_AUXADC_CONNECT_PRE_MASK              0x1
#define PMIC_ACCDET_AUXADC_CONNECT_PRE_SHIFT             4
#define PMIC_ACCDET_EINT_CUR_IN_MASK                     0x1
#define PMIC_ACCDET_EINT_CUR_IN_SHIFT                    8
#define PMIC_ACCDET_EINT_SAM_IN_MASK                     0x1
#define PMIC_ACCDET_EINT_SAM_IN_SHIFT                    9
#define PMIC_ACCDET_EINT_MEM_IN_MASK                     0x1
#define PMIC_ACCDET_EINT_MEM_IN_SHIFT                    10
#define PMIC_AD_EINTCMPOUT_MASK                          0x1
#define PMIC_AD_EINTCMPOUT_SHIFT                         14
#define PMIC_DA_NI_EINTCMPEN_MASK                        0x1
#define PMIC_DA_NI_EINTCMPEN_SHIFT                       15
#define PMIC_ACCDET_CUR_DEB_MASK                         0xFFFF
#define PMIC_ACCDET_CUR_DEB_SHIFT                        0
#define PMIC_ACCDET_EINT_CUR_DEB_MASK                    0x7FFF
#define PMIC_ACCDET_EINT_CUR_DEB_SHIFT                   0
#define PMIC_ACCDET_RSV_CON0_MASK                        0xFFFF
#define PMIC_ACCDET_RSV_CON0_SHIFT                       0
#define PMIC_ACCDET_RSV_CON1_MASK                        0xFFFF
#define PMIC_ACCDET_RSV_CON1_SHIFT                       0
#define PMIC_ACCDET_AUXADC_CONNECT_TIME_MASK             0xFFFF
#define PMIC_ACCDET_AUXADC_CONNECT_TIME_SHIFT            0
#define PMIC_ACCDET_HWMODE_SEL_MASK                      0x1
#define PMIC_ACCDET_HWMODE_SEL_SHIFT                     0
#define PMIC_ACCDET_EINT_DEB_OUT_DFF_MASK                0x1
#define PMIC_ACCDET_EINT_DEB_OUT_DFF_SHIFT               1
#define PMIC_ACCDET_EINT_REVERSE_MASK                    0x1
#define PMIC_ACCDET_EINT_REVERSE_SHIFT                   15
#define PMIC_RG_OTP_PA_MASK                              0xFF
#define PMIC_RG_OTP_PA_SHIFT                             0
#define PMIC_RG_OTP_PDIN_MASK                            0xFF
#define PMIC_RG_OTP_PDIN_SHIFT                           0
#define PMIC_RG_OTP_PTM_MASK                             0x3
#define PMIC_RG_OTP_PTM_SHIFT                            0
#define PMIC_RG_OTP_PWE_MASK                             0x3
#define PMIC_RG_OTP_PWE_SHIFT                            0
#define PMIC_RG_OTP_PPROG_MASK                           0x1
#define PMIC_RG_OTP_PPROG_SHIFT                          0
#define PMIC_RG_OTP_PWE_SRC_MASK                         0x1
#define PMIC_RG_OTP_PWE_SRC_SHIFT                        0
#define PMIC_RG_OTP_PROG_PKEY_MASK                       0xFFFF
#define PMIC_RG_OTP_PROG_PKEY_SHIFT                      0
#define PMIC_RG_OTP_RD_PKEY_MASK                         0xFFFF
#define PMIC_RG_OTP_RD_PKEY_SHIFT                        0
#define PMIC_RG_OTP_RD_TRIG_MASK                         0x1
#define PMIC_RG_OTP_RD_TRIG_SHIFT                        0
#define PMIC_RG_RD_RDY_BYPASS_MASK                       0x1
#define PMIC_RG_RD_RDY_BYPASS_SHIFT                      0
#define PMIC_RG_SKIP_OTP_OUT_MASK                        0x1
#define PMIC_RG_SKIP_OTP_OUT_SHIFT                       0
#define PMIC_RG_OTP_RD_SW_MASK                           0x1
#define PMIC_RG_OTP_RD_SW_SHIFT                          0
#define PMIC_RG_OTP_DOUT_SW_MASK                         0xFFFF
#define PMIC_RG_OTP_DOUT_SW_SHIFT                        0
#define PMIC_RG_OTP_RD_BUSY_MASK                         0x1
#define PMIC_RG_OTP_RD_BUSY_SHIFT                        0
#define PMIC_RG_OTP_RD_ACK_MASK                          0x1
#define PMIC_RG_OTP_RD_ACK_SHIFT                         2
#define PMIC_RG_OTP_PA_SW_MASK                           0x7F
#define PMIC_RG_OTP_PA_SW_SHIFT                          0
#define PMIC_RG_OTP_DOUT_0_15_MASK                       0xFFFF
#define PMIC_RG_OTP_DOUT_0_15_SHIFT                      0
#define PMIC_RG_OTP_DOUT_16_31_MASK                      0xFFFF
#define PMIC_RG_OTP_DOUT_16_31_SHIFT                     0
#define PMIC_RG_OTP_DOUT_32_47_MASK                      0xFFFF
#define PMIC_RG_OTP_DOUT_32_47_SHIFT                     0
#define PMIC_RG_OTP_DOUT_48_63_MASK                      0xFFFF
#define PMIC_RG_OTP_DOUT_48_63_SHIFT                     0
#define PMIC_RG_OTP_DOUT_64_79_MASK                      0xFFFF
#define PMIC_RG_OTP_DOUT_64_79_SHIFT                     0
#define PMIC_RG_OTP_DOUT_80_95_MASK                      0xFFFF
#define PMIC_RG_OTP_DOUT_80_95_SHIFT                     0
#define PMIC_RG_OTP_DOUT_96_111_MASK                     0xFFFF
#define PMIC_RG_OTP_DOUT_96_111_SHIFT                    0
#define PMIC_RG_OTP_DOUT_112_127_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_112_127_SHIFT                   0
#define PMIC_RG_OTP_DOUT_128_143_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_128_143_SHIFT                   0
#define PMIC_RG_OTP_DOUT_144_159_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_144_159_SHIFT                   0
#define PMIC_RG_OTP_DOUT_160_175_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_160_175_SHIFT                   0
#define PMIC_RG_OTP_DOUT_176_191_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_176_191_SHIFT                   0
#define PMIC_RG_OTP_DOUT_192_207_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_192_207_SHIFT                   0
#define PMIC_RG_OTP_DOUT_208_223_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_208_223_SHIFT                   0
#define PMIC_RG_OTP_DOUT_224_239_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_224_239_SHIFT                   0
#define PMIC_RG_OTP_DOUT_240_255_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_240_255_SHIFT                   0
#define PMIC_RG_OTP_DOUT_256_271_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_256_271_SHIFT                   0
#define PMIC_RG_OTP_DOUT_272_287_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_272_287_SHIFT                   0
#define PMIC_RG_OTP_DOUT_288_303_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_288_303_SHIFT                   0
#define PMIC_RG_OTP_DOUT_304_319_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_304_319_SHIFT                   0
#define PMIC_RG_OTP_DOUT_320_335_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_320_335_SHIFT                   0
#define PMIC_RG_OTP_DOUT_336_351_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_336_351_SHIFT                   0
#define PMIC_RG_OTP_DOUT_352_367_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_352_367_SHIFT                   0
#define PMIC_RG_OTP_DOUT_368_383_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_368_383_SHIFT                   0
#define PMIC_RG_OTP_DOUT_384_399_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_384_399_SHIFT                   0
#define PMIC_RG_OTP_DOUT_400_415_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_400_415_SHIFT                   0
#define PMIC_RG_OTP_DOUT_416_431_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_416_431_SHIFT                   0
#define PMIC_RG_OTP_DOUT_432_447_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_432_447_SHIFT                   0
#define PMIC_RG_OTP_DOUT_448_463_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_448_463_SHIFT                   0
#define PMIC_RG_OTP_DOUT_464_479_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_464_479_SHIFT                   0
#define PMIC_RG_OTP_DOUT_480_495_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_480_495_SHIFT                   0
#define PMIC_RG_OTP_DOUT_496_511_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_496_511_SHIFT                   0
#define PMIC_RG_OTP_DOUT_512_527_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_512_527_SHIFT                   0
#define PMIC_RG_OTP_DOUT_528_543_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_528_543_SHIFT                   0
#define PMIC_RG_OTP_DOUT_544_559_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_544_559_SHIFT                   0
#define PMIC_RG_OTP_DOUT_560_575_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_560_575_SHIFT                   0
#define PMIC_RG_OTP_DOUT_576_591_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_576_591_SHIFT                   0
#define PMIC_RG_OTP_DOUT_592_607_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_592_607_SHIFT                   0
#define PMIC_RG_OTP_DOUT_608_623_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_608_623_SHIFT                   0
#define PMIC_RG_OTP_DOUT_624_639_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_624_639_SHIFT                   0
#define PMIC_RG_OTP_DOUT_640_655_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_640_655_SHIFT                   0
#define PMIC_RG_OTP_DOUT_656_671_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_656_671_SHIFT                   0
#define PMIC_RG_OTP_DOUT_672_687_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_672_687_SHIFT                   0
#define PMIC_RG_OTP_DOUT_688_703_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_688_703_SHIFT                   0
#define PMIC_RG_OTP_DOUT_704_719_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_704_719_SHIFT                   0
#define PMIC_RG_OTP_DOUT_720_735_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_720_735_SHIFT                   0
#define PMIC_RG_OTP_DOUT_736_751_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_736_751_SHIFT                   0
#define PMIC_RG_OTP_DOUT_752_767_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_752_767_SHIFT                   0
#define PMIC_RG_OTP_DOUT_768_783_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_768_783_SHIFT                   0
#define PMIC_RG_OTP_DOUT_784_799_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_784_799_SHIFT                   0
#define PMIC_RG_OTP_DOUT_800_815_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_800_815_SHIFT                   0
#define PMIC_RG_OTP_DOUT_816_831_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_816_831_SHIFT                   0
#define PMIC_RG_OTP_DOUT_832_847_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_832_847_SHIFT                   0
#define PMIC_RG_OTP_DOUT_848_863_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_848_863_SHIFT                   0
#define PMIC_RG_OTP_DOUT_864_879_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_864_879_SHIFT                   0
#define PMIC_RG_OTP_DOUT_880_895_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_880_895_SHIFT                   0
#define PMIC_RG_OTP_DOUT_896_911_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_896_911_SHIFT                   0
#define PMIC_RG_OTP_DOUT_912_927_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_912_927_SHIFT                   0
#define PMIC_RG_OTP_DOUT_928_943_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_928_943_SHIFT                   0
#define PMIC_RG_OTP_DOUT_944_959_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_944_959_SHIFT                   0
#define PMIC_RG_OTP_DOUT_960_975_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_960_975_SHIFT                   0
#define PMIC_RG_OTP_DOUT_976_991_MASK                    0xFFFF
#define PMIC_RG_OTP_DOUT_976_991_SHIFT                   0
#define PMIC_RG_OTP_DOUT_992_1007_MASK                   0xFFFF
#define PMIC_RG_OTP_DOUT_992_1007_SHIFT                  0
#define PMIC_RG_OTP_DOUT_1008_1023_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1008_1023_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1024_1039_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1024_1039_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1040_1055_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1040_1055_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1056_1071_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1056_1071_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1072_1087_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1072_1087_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1088_1103_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1088_1103_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1104_1119_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1104_1119_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1120_1135_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1120_1135_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1136_1151_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1136_1151_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1152_1167_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1152_1167_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1168_1183_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1168_1183_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1184_1199_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1184_1199_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1200_1215_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1200_1215_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1216_1231_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1216_1231_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1232_1247_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1232_1247_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1248_1263_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1248_1263_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1264_1279_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1264_1279_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1280_1295_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1280_1295_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1296_1311_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1296_1311_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1312_1327_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1312_1327_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1328_1343_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1328_1343_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1344_1359_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1344_1359_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1360_1375_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1360_1375_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1376_1391_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1376_1391_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1392_1407_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1392_1407_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1408_1423_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1408_1423_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1424_1439_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1424_1439_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1440_1455_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1440_1455_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1456_1471_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1456_1471_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1472_1487_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1472_1487_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1488_1503_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1488_1503_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1504_1519_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1504_1519_SHIFT                 0
#define PMIC_RG_OTP_DOUT_1520_1535_MASK                  0xFFFF
#define PMIC_RG_OTP_DOUT_1520_1535_SHIFT                 0
#define PMIC_RG_OTP_VAL_0_15_MASK                        0xFFFF
#define PMIC_RG_OTP_VAL_0_15_SHIFT                       0
#define PMIC_RG_OTP_VAL_16_31_MASK                       0xFFFF
#define PMIC_RG_OTP_VAL_16_31_SHIFT                      0
#define PMIC_RG_OTP_VAL_32_47_MASK                       0xFFFF
#define PMIC_RG_OTP_VAL_32_47_SHIFT                      0
#define PMIC_RG_OTP_VAL_48_63_MASK                       0xFFFF
#define PMIC_RG_OTP_VAL_48_63_SHIFT                      0
#define PMIC_RG_OTP_VAL_64_79_MASK                       0xFFFF
#define PMIC_RG_OTP_VAL_64_79_SHIFT                      0
#define PMIC_RG_OTP_VAL_80_95_MASK                       0xFFFF
#define PMIC_RG_OTP_VAL_80_95_SHIFT                      0
#define PMIC_RG_OTP_VAL_96_111_MASK                      0xFFFF
#define PMIC_RG_OTP_VAL_96_111_SHIFT                     0
#define PMIC_RG_OTP_VAL_112_127_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_112_127_SHIFT                    0
#define PMIC_RG_OTP_VAL_128_143_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_128_143_SHIFT                    0
#define PMIC_RG_OTP_VAL_144_159_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_144_159_SHIFT                    0
#define PMIC_RG_OTP_VAL_160_175_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_160_175_SHIFT                    0
#define PMIC_RG_OTP_VAL_176_191_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_176_191_SHIFT                    0
#define PMIC_RG_OTP_VAL_192_207_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_192_207_SHIFT                    0
#define PMIC_RG_OTP_VAL_208_223_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_208_223_SHIFT                    0
#define PMIC_RG_OTP_VAL_224_239_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_224_239_SHIFT                    0
#define PMIC_RG_OTP_VAL_240_255_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_240_255_SHIFT                    0
#define PMIC_RG_OTP_VAL_256_271_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_256_271_SHIFT                    0
#define PMIC_RG_OTP_VAL_272_287_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_272_287_SHIFT                    0
#define PMIC_RG_OTP_VAL_288_303_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_288_303_SHIFT                    0
#define PMIC_RG_OTP_VAL_304_319_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_304_319_SHIFT                    0
#define PMIC_RG_OTP_VAL_320_335_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_320_335_SHIFT                    0
#define PMIC_RG_OTP_VAL_336_351_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_336_351_SHIFT                    0
#define PMIC_RG_OTP_VAL_352_367_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_352_367_SHIFT                    0
#define PMIC_RG_OTP_VAL_368_383_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_368_383_SHIFT                    0
#define PMIC_RG_OTP_VAL_384_399_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_384_399_SHIFT                    0
#define PMIC_RG_OTP_VAL_400_415_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_400_415_SHIFT                    0
#define PMIC_RG_OTP_VAL_416_431_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_416_431_SHIFT                    0
#define PMIC_RG_OTP_VAL_432_447_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_432_447_SHIFT                    0
#define PMIC_RG_OTP_VAL_448_463_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_448_463_SHIFT                    0
#define PMIC_RG_OTP_VAL_464_479_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_464_479_SHIFT                    0
#define PMIC_RG_OTP_VAL_480_495_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_480_495_SHIFT                    0
#define PMIC_RG_OTP_VAL_496_511_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_496_511_SHIFT                    0
#define PMIC_RG_OTP_VAL_512_527_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_512_527_SHIFT                    0
#define PMIC_RG_OTP_VAL_528_543_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_528_543_SHIFT                    0
#define PMIC_RG_OTP_VAL_544_559_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_544_559_SHIFT                    0
#define PMIC_RG_OTP_VAL_560_575_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_560_575_SHIFT                    0
#define PMIC_RG_OTP_VAL_576_591_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_576_591_SHIFT                    0
#define PMIC_RG_OTP_VAL_592_607_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_592_607_SHIFT                    0
#define PMIC_RG_OTP_VAL_608_623_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_608_623_SHIFT                    0
#define PMIC_RG_OTP_VAL_624_639_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_624_639_SHIFT                    0
#define PMIC_RG_OTP_VAL_640_655_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_640_655_SHIFT                    0
#define PMIC_RG_OTP_VAL_656_671_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_656_671_SHIFT                    0
#define PMIC_RG_OTP_VAL_672_687_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_672_687_SHIFT                    0
#define PMIC_RG_OTP_VAL_688_703_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_688_703_SHIFT                    0
#define PMIC_RG_OTP_VAL_704_719_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_704_719_SHIFT                    0
#define PMIC_RG_OTP_VAL_720_735_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_720_735_SHIFT                    0
#define PMIC_RG_OTP_VAL_736_751_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_736_751_SHIFT                    0
#define PMIC_RG_OTP_VAL_752_767_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_752_767_SHIFT                    0
#define PMIC_RG_OTP_VAL_768_783_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_768_783_SHIFT                    0
#define PMIC_RG_OTP_VAL_784_799_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_784_799_SHIFT                    0
#define PMIC_RG_OTP_VAL_800_815_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_800_815_SHIFT                    0
#define PMIC_RG_OTP_VAL_816_831_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_816_831_SHIFT                    0
#define PMIC_RG_OTP_VAL_832_847_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_832_847_SHIFT                    0
#define PMIC_RG_OTP_VAL_848_863_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_848_863_SHIFT                    0
#define PMIC_RG_OTP_VAL_864_879_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_864_879_SHIFT                    0
#define PMIC_RG_OTP_VAL_880_895_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_880_895_SHIFT                    0
#define PMIC_RG_OTP_VAL_896_911_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_896_911_SHIFT                    0
#define PMIC_RG_OTP_VAL_912_927_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_912_927_SHIFT                    0
#define PMIC_RG_OTP_VAL_928_943_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_928_943_SHIFT                    0
#define PMIC_RG_OTP_VAL_944_959_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_944_959_SHIFT                    0
#define PMIC_RG_OTP_VAL_960_975_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_960_975_SHIFT                    0
#define PMIC_RG_OTP_VAL_976_991_MASK                     0xFFFF
#define PMIC_RG_OTP_VAL_976_991_SHIFT                    0
#define PMIC_RG_OTP_VAL_992_1007_MASK                    0xFFFF
#define PMIC_RG_OTP_VAL_992_1007_SHIFT                   0
#define PMIC_RG_OTP_VAL_1008_1023_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1008_1023_SHIFT                  0
#define PMIC_RG_OTP_VAL_1024_1039_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1024_1039_SHIFT                  0
#define PMIC_RG_OTP_VAL_1040_1055_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1040_1055_SHIFT                  0
#define PMIC_RG_OTP_VAL_1056_1071_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1056_1071_SHIFT                  0
#define PMIC_RG_OTP_VAL_1072_1087_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1072_1087_SHIFT                  0
#define PMIC_RG_OTP_VAL_1088_1103_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1088_1103_SHIFT                  0
#define PMIC_RG_OTP_VAL_1104_1119_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1104_1119_SHIFT                  0
#define PMIC_RG_OTP_VAL_1120_1135_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1120_1135_SHIFT                  0
#define PMIC_RG_OTP_VAL_1136_1151_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1136_1151_SHIFT                  0
#define PMIC_RG_OTP_VAL_1152_1167_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1152_1167_SHIFT                  0
#define PMIC_RG_OTP_VAL_1168_1183_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1168_1183_SHIFT                  0
#define PMIC_RG_OTP_VAL_1184_1199_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1184_1199_SHIFT                  0
#define PMIC_RG_OTP_VAL_1200_1215_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1200_1215_SHIFT                  0
#define PMIC_RG_OTP_VAL_1216_1231_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1216_1231_SHIFT                  0
#define PMIC_RG_OTP_VAL_1232_1247_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1232_1247_SHIFT                  0
#define PMIC_RG_OTP_VAL_1248_1263_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1248_1263_SHIFT                  0
#define PMIC_RG_OTP_VAL_1264_1279_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1264_1279_SHIFT                  0
#define PMIC_RG_OTP_VAL_1280_1295_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1280_1295_SHIFT                  0
#define PMIC_RG_OTP_VAL_1296_1311_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1296_1311_SHIFT                  0
#define PMIC_RG_OTP_VAL_1312_1327_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1312_1327_SHIFT                  0
#define PMIC_RG_OTP_VAL_1328_1343_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1328_1343_SHIFT                  0
#define PMIC_RG_OTP_VAL_1344_1359_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1344_1359_SHIFT                  0
#define PMIC_RG_OTP_VAL_1360_1375_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1360_1375_SHIFT                  0
#define PMIC_RG_OTP_VAL_1376_1391_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1376_1391_SHIFT                  0
#define PMIC_RG_OTP_VAL_1392_1407_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1392_1407_SHIFT                  0
#define PMIC_RG_OTP_VAL_1408_1423_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1408_1423_SHIFT                  0
#define PMIC_RG_OTP_VAL_1424_1439_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1424_1439_SHIFT                  0
#define PMIC_RG_OTP_VAL_1440_1455_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1440_1455_SHIFT                  0
#define PMIC_RG_OTP_VAL_1456_1471_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1456_1471_SHIFT                  0
#define PMIC_RG_OTP_VAL_1472_1487_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1472_1487_SHIFT                  0
#define PMIC_RG_OTP_VAL_1488_1503_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1488_1503_SHIFT                  0
#define PMIC_RG_OTP_VAL_1504_1519_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1504_1519_SHIFT                  0
#define PMIC_RG_OTP_VAL_1520_1535_MASK                   0xFFFF
#define PMIC_RG_OTP_VAL_1520_1535_SHIFT                  0
#define PMIC_XO_EXTBUF1_MODE_MASK                        0x3
#define PMIC_XO_EXTBUF1_MODE_SHIFT                       0
#define PMIC_XO_EXTBUF1_EN_M_MASK                        0x1
#define PMIC_XO_EXTBUF1_EN_M_SHIFT                       2
#define PMIC_XO_EXTBUF2_MODE_MASK                        0x3
#define PMIC_XO_EXTBUF2_MODE_SHIFT                       3
#define PMIC_XO_EXTBUF2_EN_M_MASK                        0x1
#define PMIC_XO_EXTBUF2_EN_M_SHIFT                       5
#define PMIC_XO_EXTBUF3_MODE_MASK                        0x3
#define PMIC_XO_EXTBUF3_MODE_SHIFT                       6
#define PMIC_XO_EXTBUF3_EN_M_MASK                        0x1
#define PMIC_XO_EXTBUF3_EN_M_SHIFT                       8
#define PMIC_XO_EXTBUF4_MODE_MASK                        0x3
#define PMIC_XO_EXTBUF4_MODE_SHIFT                       9
#define PMIC_XO_EXTBUF4_EN_M_MASK                        0x1
#define PMIC_XO_EXTBUF4_EN_M_SHIFT                       11
#define PMIC_XO_BB_LPM_EN_MASK                           0x1
#define PMIC_XO_BB_LPM_EN_SHIFT                          12
#define PMIC_XO_ENBB_MAN_MASK                            0x1
#define PMIC_XO_ENBB_MAN_SHIFT                           13
#define PMIC_XO_ENBB_EN_M_MASK                           0x1
#define PMIC_XO_ENBB_EN_M_SHIFT                          14
#define PMIC_XO_CLKSEL_MAN_MASK                          0x1
#define PMIC_XO_CLKSEL_MAN_SHIFT                         15
#define PMIC_DCXO_CW00_SET_MASK                          0xFFFF
#define PMIC_DCXO_CW00_SET_SHIFT                         0
#define PMIC_DCXO_CW00_CLR_MASK                          0xFFFF
#define PMIC_DCXO_CW00_CLR_SHIFT                         0
#define PMIC_XO_CLKSEL_EN_M_MASK                         0x1
#define PMIC_XO_CLKSEL_EN_M_SHIFT                        0
#define PMIC_XO_EXTBUF1_CKG_MAN_MASK                     0x1
#define PMIC_XO_EXTBUF1_CKG_MAN_SHIFT                    1
#define PMIC_XO_EXTBUF1_CKG_EN_M_MASK                    0x1
#define PMIC_XO_EXTBUF1_CKG_EN_M_SHIFT                   2
#define PMIC_XO_EXTBUF2_CKG_MAN_MASK                     0x1
#define PMIC_XO_EXTBUF2_CKG_MAN_SHIFT                    3
#define PMIC_XO_EXTBUF2_CKG_EN_M_MASK                    0x1
#define PMIC_XO_EXTBUF2_CKG_EN_M_SHIFT                   4
#define PMIC_XO_EXTBUF3_CKG_MAN_MASK                     0x1
#define PMIC_XO_EXTBUF3_CKG_MAN_SHIFT                    5
#define PMIC_XO_EXTBUF3_CKG_EN_M_MASK                    0x1
#define PMIC_XO_EXTBUF3_CKG_EN_M_SHIFT                   6
#define PMIC_XO_EXTBUF4_CKG_MAN_MASK                     0x1
#define PMIC_XO_EXTBUF4_CKG_MAN_SHIFT                    7
#define PMIC_XO_EXTBUF4_CKG_EN_M_MASK                    0x1
#define PMIC_XO_EXTBUF4_CKG_EN_M_SHIFT                   8
#define PMIC_XO_INTBUF_MAN_MASK                          0x1
#define PMIC_XO_INTBUF_MAN_SHIFT                         9
#define PMIC_XO_PBUF_EN_M_MASK                           0x1
#define PMIC_XO_PBUF_EN_M_SHIFT                          10
#define PMIC_XO_IBUF_EN_M_MASK                           0x1
#define PMIC_XO_IBUF_EN_M_SHIFT                          11
#define PMIC_XO_LPMBUF_MAN_MASK                          0x1
#define PMIC_XO_LPMBUF_MAN_SHIFT                         12
#define PMIC_XO_LPM_PREBUF_EN_M_MASK                     0x1
#define PMIC_XO_LPM_PREBUF_EN_M_SHIFT                    13
#define PMIC_XO_LPBUF_EN_M_MASK                          0x1
#define PMIC_XO_LPBUF_EN_M_SHIFT                         14
#define PMIC_XO_BBLPM_CKSEL_M_MASK                       0x1
#define PMIC_XO_BBLPM_CKSEL_M_SHIFT                      15
#define PMIC_XO_EN32K_MAN_MASK                           0x1
#define PMIC_XO_EN32K_MAN_SHIFT                          0
#define PMIC_XO_EN32K_M_MASK                             0x1
#define PMIC_XO_EN32K_M_SHIFT                            1
#define PMIC_XO_XMODE_MAN_MASK                           0x1
#define PMIC_XO_XMODE_MAN_SHIFT                          2
#define PMIC_XO_XMODE_M_MASK                             0x1
#define PMIC_XO_XMODE_M_SHIFT                            3
#define PMIC_XO_STRUP_MODE_MASK                          0x1
#define PMIC_XO_STRUP_MODE_SHIFT                         4
#define PMIC_XO_AAC_FPM_TIME_MASK                        0x3
#define PMIC_XO_AAC_FPM_TIME_SHIFT                       5
#define PMIC_XO_AAC_MODE_LPM_MASK                        0x3
#define PMIC_XO_AAC_MODE_LPM_SHIFT                       7
#define PMIC_XO_AAC_MODE_FPM_MASK                        0x3
#define PMIC_XO_AAC_MODE_FPM_SHIFT                       9
#define PMIC_XO_EN26M_OFFSQ_EN_MASK                      0x1
#define PMIC_XO_EN26M_OFFSQ_EN_SHIFT                     11
#define PMIC_XO_LDOCAL_EN_MASK                           0x1
#define PMIC_XO_LDOCAL_EN_SHIFT                          12
#define PMIC_XO_CBANK_SYNC_DYN_MASK                      0x1
#define PMIC_XO_CBANK_SYNC_DYN_SHIFT                     13
#define PMIC_XO_26MLP_MAN_EN_MASK                        0x1
#define PMIC_XO_26MLP_MAN_EN_SHIFT                       14
#define PMIC_XO_BUFLDOK_EN_MASK                          0x1
#define PMIC_XO_BUFLDOK_EN_SHIFT                         15
#define PMIC_XO_RESERVED2_MASK                           0x3
#define PMIC_XO_RESERVED2_SHIFT                          0
#define PMIC_XO_EXTBUF6_CKG_MAN_MASK                     0x1
#define PMIC_XO_EXTBUF6_CKG_MAN_SHIFT                    2
#define PMIC_XO_EXTBUF6_CKG_EN_M_MASK                    0x1
#define PMIC_XO_EXTBUF6_CKG_EN_M_SHIFT                   3
#define PMIC_XO_EXTBUF7_CKG_MAN_MASK                     0x1
#define PMIC_XO_EXTBUF7_CKG_MAN_SHIFT                    4
#define PMIC_XO_EXTBUF7_CKG_EN_M_MASK                    0x1
#define PMIC_XO_EXTBUF7_CKG_EN_M_SHIFT                   5
#define PMIC_XO_LPM_ISEL_MAN_MASK                        0x1F
#define PMIC_XO_LPM_ISEL_MAN_SHIFT                       6
#define PMIC_XO_FPM_ISEL_MAN_MASK                        0x1F
#define PMIC_XO_FPM_ISEL_MAN_SHIFT                       11
#define PMIC_XO_CDAC_FPM_MASK                            0xFF
#define PMIC_XO_CDAC_FPM_SHIFT                           0
#define PMIC_XO_CDAC_LPM_MASK                            0xFF
#define PMIC_XO_CDAC_LPM_SHIFT                           8
#define PMIC_XO_32KDIV_NFRAC_FPM_MASK                    0x3FFF
#define PMIC_XO_32KDIV_NFRAC_FPM_SHIFT                   0
#define PMIC_XO_COFST_FPM_MASK                           0x3
#define PMIC_XO_COFST_FPM_SHIFT                          14
#define PMIC_XO_32KDIV_NFRAC_LPM_MASK                    0x3FFF
#define PMIC_XO_32KDIV_NFRAC_LPM_SHIFT                   0
#define PMIC_XO_COFST_LPM_MASK                           0x3
#define PMIC_XO_COFST_LPM_SHIFT                          14
#define PMIC_XO_CORE_MAN_MASK                            0x1
#define PMIC_XO_CORE_MAN_SHIFT                           0
#define PMIC_XO_CORE_EN_M_MASK                           0x1
#define PMIC_XO_CORE_EN_M_SHIFT                          1
#define PMIC_XO_CORE_TURBO_EN_M_MASK                     0x1
#define PMIC_XO_CORE_TURBO_EN_M_SHIFT                    2
#define PMIC_XO_CORE_AAC_EN_M_MASK                       0x1
#define PMIC_XO_CORE_AAC_EN_M_SHIFT                      3
#define PMIC_XO_STARTUP_EN_M_MASK                        0x1
#define PMIC_XO_STARTUP_EN_M_SHIFT                       4
#define PMIC_XO_CORE_VBFPM_EN_M_MASK                     0x1
#define PMIC_XO_CORE_VBFPM_EN_M_SHIFT                    5
#define PMIC_XO_CORE_VBLPM_EN_M_MASK                     0x1
#define PMIC_XO_CORE_VBLPM_EN_M_SHIFT                    6
#define PMIC_XO_LPMBIAS_EN_M_MASK                        0x1
#define PMIC_XO_LPMBIAS_EN_M_SHIFT                       7
#define PMIC_XO_VTCGEN_EN_M_MASK                         0x1
#define PMIC_XO_VTCGEN_EN_M_SHIFT                        8
#define PMIC_XO_IAAC_COMP_EN_M_MASK                      0x1
#define PMIC_XO_IAAC_COMP_EN_M_SHIFT                     9
#define PMIC_XO_IFPM_COMP_EN_M_MASK                      0x1
#define PMIC_XO_IFPM_COMP_EN_M_SHIFT                     10
#define PMIC_XO_ILPM_COMP_EN_M_MASK                      0x1
#define PMIC_XO_ILPM_COMP_EN_M_SHIFT                     11
#define PMIC_XO_CORE_BYPCAS_FPM_MASK                     0x1
#define PMIC_XO_CORE_BYPCAS_FPM_SHIFT                    12
#define PMIC_XO_CORE_GMX2_FPM_MASK                       0x1
#define PMIC_XO_CORE_GMX2_FPM_SHIFT                      13
#define PMIC_XO_CORE_IDAC_FPM_MASK                       0x3
#define PMIC_XO_CORE_IDAC_FPM_SHIFT                      14
#define PMIC_XO_AAC_COMP_MAN_MASK                        0x1
#define PMIC_XO_AAC_COMP_MAN_SHIFT                       0
#define PMIC_XO_AAC_EN_M_MASK                            0x1
#define PMIC_XO_AAC_EN_M_SHIFT                           1
#define PMIC_XO_AAC_MONEN_M_MASK                         0x1
#define PMIC_XO_AAC_MONEN_M_SHIFT                        2
#define PMIC_XO_COMP_EN_M_MASK                           0x1
#define PMIC_XO_COMP_EN_M_SHIFT                          3
#define PMIC_XO_COMP_TSTEN_M_MASK                        0x1
#define PMIC_XO_COMP_TSTEN_M_SHIFT                       4
#define PMIC_XO_AAC_HV_FPM_MASK                          0x1
#define PMIC_XO_AAC_HV_FPM_SHIFT                         5
#define PMIC_XO_AAC_IBIAS_FPM_MASK                       0x3
#define PMIC_XO_AAC_IBIAS_FPM_SHIFT                      6
#define PMIC_XO_AAC_VOFST_FPM_MASK                       0x3
#define PMIC_XO_AAC_VOFST_FPM_SHIFT                      8
#define PMIC_XO_AAC_COMP_HV_FPM_MASK                     0x1
#define PMIC_XO_AAC_COMP_HV_FPM_SHIFT                    10
#define PMIC_XO_AAC_VSEL_FPM_MASK                        0xF
#define PMIC_XO_AAC_VSEL_FPM_SHIFT                       11
#define PMIC_XO_AAC_COMP_POL_MASK                        0x1
#define PMIC_XO_AAC_COMP_POL_SHIFT                       15
#define PMIC_XO_CORE_BYPCAS_LPM_MASK                     0x1
#define PMIC_XO_CORE_BYPCAS_LPM_SHIFT                    0
#define PMIC_XO_CORE_GMX2_LPM_MASK                       0x1
#define PMIC_XO_CORE_GMX2_LPM_SHIFT                      1
#define PMIC_XO_CORE_IDAC_LPM_MASK                       0x3
#define PMIC_XO_CORE_IDAC_LPM_SHIFT                      2
#define PMIC_XO_AAC_COMP_HV_LPM_MASK                     0x1
#define PMIC_XO_AAC_COMP_HV_LPM_SHIFT                    4
#define PMIC_XO_AAC_VSEL_LPM_MASK                        0xF
#define PMIC_XO_AAC_VSEL_LPM_SHIFT                       5
#define PMIC_XO_AAC_HV_LPM_MASK                          0x1
#define PMIC_XO_AAC_HV_LPM_SHIFT                         9
#define PMIC_XO_AAC_IBIAS_LPM_MASK                       0x3
#define PMIC_XO_AAC_IBIAS_LPM_SHIFT                      10
#define PMIC_XO_AAC_VOFST_LPM_MASK                       0x3
#define PMIC_XO_AAC_VOFST_LPM_SHIFT                      12
#define PMIC_XO_AAC_FPM_SWEN_MASK                        0x1
#define PMIC_XO_AAC_FPM_SWEN_SHIFT                       14
#define PMIC_XO_SWRST_MASK                               0x1
#define PMIC_XO_SWRST_SHIFT                              15
#define PMIC_XO_32KDIV_SWRST_MASK                        0x1
#define PMIC_XO_32KDIV_SWRST_SHIFT                       0
#define PMIC_XO_32KDIV_RATIO_MAN_MASK                    0x1
#define PMIC_XO_32KDIV_RATIO_MAN_SHIFT                   1
#define PMIC_XO_32KDIV_TEST_EN_MASK                      0x1
#define PMIC_XO_32KDIV_TEST_EN_SHIFT                     2
#define PMIC_XO_CBANK_SYNC_MAN_MASK                      0x1
#define PMIC_XO_CBANK_SYNC_MAN_SHIFT                     3
#define PMIC_XO_CBANK_SYNC_EN_M_MASK                     0x1
#define PMIC_XO_CBANK_SYNC_EN_M_SHIFT                    4
#define PMIC_XO_CTL_SYNC_MAN_MASK                        0x1
#define PMIC_XO_CTL_SYNC_MAN_SHIFT                       5
#define PMIC_XO_CTL_SYNC_EN_M_MASK                       0x1
#define PMIC_XO_CTL_SYNC_EN_M_SHIFT                      6
#define PMIC_XO_LDO_MAN_MASK                             0x1
#define PMIC_XO_LDO_MAN_SHIFT                            7
#define PMIC_XO_LDOPBUF_EN_M_MASK                        0x1
#define PMIC_XO_LDOPBUF_EN_M_SHIFT                       8
#define PMIC_XO_LDOPBUF_VSET_M_MASK                      0xF
#define PMIC_XO_LDOPBUF_VSET_M_SHIFT                     9
#define PMIC_XO_LDOVTST_EN_M_MASK                        0x1
#define PMIC_XO_LDOVTST_EN_M_SHIFT                       13
#define PMIC_XO_TEST_VCAL_EN_M_MASK                      0x1
#define PMIC_XO_TEST_VCAL_EN_M_SHIFT                     14
#define PMIC_XO_VBIST_EN_M_MASK                          0x1
#define PMIC_XO_VBIST_EN_M_SHIFT                         15
#define PMIC_XO_VTEST_SEL_MUX_MASK                       0x1F
#define PMIC_XO_VTEST_SEL_MUX_SHIFT                      0
#define PMIC_XO_RESERVED3_MASK                           0x7
#define PMIC_XO_RESERVED3_SHIFT                          5
#define PMIC_XO_EXTBUF6_MODE_MASK                        0x3
#define PMIC_XO_EXTBUF6_MODE_SHIFT                       8
#define PMIC_XO_EXTBUF6_EN_M_MASK                        0x1
#define PMIC_XO_EXTBUF6_EN_M_SHIFT                       10
#define PMIC_XO_EXTBUF7_MODE_MASK                        0x3
#define PMIC_XO_EXTBUF7_MODE_SHIFT                       11
#define PMIC_XO_EXTBUF7_EN_M_MASK                        0x1
#define PMIC_XO_EXTBUF7_EN_M_SHIFT                       13
#define PMIC_XO_BUFLDOK_MAN_MASK                         0x1
#define PMIC_XO_BUFLDOK_MAN_SHIFT                        14
#define PMIC_XO_BUF1LDO_CAL_M_MASK                       0x1
#define PMIC_XO_BUF1LDO_CAL_M_SHIFT                      15
#define PMIC_DCXO_CW11_SET_MASK                          0xFFFF
#define PMIC_DCXO_CW11_SET_SHIFT                         0
#define PMIC_DCXO_CW11_CLR_MASK                          0xFFFF
#define PMIC_DCXO_CW11_CLR_SHIFT                         0
#define PMIC_XO_BUFLDO_CAL_M_MASK                        0x1
#define PMIC_XO_BUFLDO_CAL_M_SHIFT                       0
#define PMIC_XO_EXTBUF4_CLKSEL_MAN_MASK                  0x1
#define PMIC_XO_EXTBUF4_CLKSEL_MAN_SHIFT                 1
#define PMIC_XO_VIO18PG_BUFEN_MASK                       0x1
#define PMIC_XO_VIO18PG_BUFEN_SHIFT                      2
#define PMIC_XO_CAL_EN_MAN_MASK                          0x1
#define PMIC_XO_CAL_EN_MAN_SHIFT                         3
#define PMIC_XO_CAL_EN_M_MASK                            0x1
#define PMIC_XO_CAL_EN_M_SHIFT                           4
#define PMIC_RG_XO_CORE_OSCTD_MASK                       0x3
#define PMIC_RG_XO_CORE_OSCTD_SHIFT                      5
#define PMIC_XO_THADC_EN_MASK                            0x1
#define PMIC_XO_THADC_EN_SHIFT                           7
#define PMIC_RG_XO_SYNC_CKPOL_MASK                       0x1
#define PMIC_RG_XO_SYNC_CKPOL_SHIFT                      8
#define PMIC_RG_XO_CBANK_POL_MASK                        0x1
#define PMIC_RG_XO_CBANK_POL_SHIFT                       9
#define PMIC_RG_XO_CBANK_SYNC_BYP_MASK                   0x1
#define PMIC_RG_XO_CBANK_SYNC_BYP_SHIFT                  10
#define PMIC_RG_XO_CTL_POL_MASK                          0x1
#define PMIC_RG_XO_CTL_POL_SHIFT                         11
#define PMIC_RG_XO_CTL_SYNC_BYP_MASK                     0x1
#define PMIC_RG_XO_CTL_SYNC_BYP_SHIFT                    12
#define PMIC_RG_XO_LPBUF_INV_MASK                        0x1
#define PMIC_RG_XO_LPBUF_INV_SHIFT                       13
#define PMIC_RG_XO_LDOPBUF_BYP_MASK                      0x1
#define PMIC_RG_XO_LDOPBUF_BYP_SHIFT                     14
#define PMIC_RG_XO_LDOPBUF_ENCL_MASK                     0x1
#define PMIC_RG_XO_LDOPBUF_ENCL_SHIFT                    15
#define PMIC_RG_XO_VGBIAS_VSET_MASK                      0x3
#define PMIC_RG_XO_VGBIAS_VSET_SHIFT                     0
#define PMIC_RG_XO_PBUF_ISET_MASK                        0x3
#define PMIC_RG_XO_PBUF_ISET_SHIFT                       2
#define PMIC_RG_XO_IBUF_ISET_MASK                        0x3
#define PMIC_RG_XO_IBUF_ISET_SHIFT                       4
#define PMIC_RG_XO_RESERVED4_MASK                        0x3
#define PMIC_RG_XO_RESERVED4_SHIFT                       6
#define PMIC_RG_XO_VOW_EN_MASK                           0x1
#define PMIC_RG_XO_VOW_EN_SHIFT                          8
#define PMIC_RG_XO_VOW_DIV_MASK                          0x3
#define PMIC_RG_XO_VOW_DIV_SHIFT                         9
#define PMIC_RG_XO_BUFLDO24_ENCL_MASK                    0x1
#define PMIC_RG_XO_BUFLDO24_ENCL_SHIFT                   11
#define PMIC_RG_XO_BUFLDO24_IBX2_MASK                    0x1
#define PMIC_RG_XO_BUFLDO24_IBX2_SHIFT                   12
#define PMIC_RG_XO_RESERVED5_MASK                        0x7
#define PMIC_RG_XO_RESERVED5_SHIFT                       13
#define PMIC_RG_XO_BUFLDO13_ENCL_MASK                    0x1
#define PMIC_RG_XO_BUFLDO13_ENCL_SHIFT                   0
#define PMIC_RG_XO_BUFLDO13_IBX2_MASK                    0x1
#define PMIC_RG_XO_BUFLDO13_IBX2_SHIFT                   1
#define PMIC_RG_XO_BUFLDO13_IX2_MASK                     0x1
#define PMIC_RG_XO_BUFLDO13_IX2_SHIFT                    2
#define PMIC_RG_XO_LVLDO_I_CTRL_MASK                     0x3
#define PMIC_RG_XO_LVLDO_I_CTRL_SHIFT                    3
#define PMIC_RG_XO_BUFLDO67_ENCL_MASK                    0x1
#define PMIC_RG_XO_BUFLDO67_ENCL_SHIFT                   5
#define PMIC_RG_XO_BUFLDO67_IBX2_MASK                    0x1
#define PMIC_RG_XO_BUFLDO67_IBX2_SHIFT                   6
#define PMIC_RG_XO_BUFLDO67_IX2_MASK                     0x1
#define PMIC_RG_XO_BUFLDO67_IX2_SHIFT                    7
#define PMIC_RG_XO_LVLDO_RFB_MASK                        0x3
#define PMIC_RG_XO_LVLDO_RFB_SHIFT                       8
#define PMIC_RG_XO_EXTBUF_INV_MASK                       0x1
#define PMIC_RG_XO_EXTBUF_INV_SHIFT                      10
#define PMIC_RG_XO_RESERVED0_MASK                        0x1
#define PMIC_RG_XO_RESERVED0_SHIFT                       11
#define PMIC_XO_EXTBUF2_CLKSEL_MAN_MASK                  0x1
#define PMIC_XO_EXTBUF2_CLKSEL_MAN_SHIFT                 12
#define PMIC_XO_AUDIO_EN_M_MASK                          0x1
#define PMIC_XO_AUDIO_EN_M_SHIFT                         13
#define PMIC_RG_XO_AUDIO_ATTEN_MASK                      0x3
#define PMIC_RG_XO_AUDIO_ATTEN_SHIFT                     14
#define PMIC_RG_XO_AUDIO_ISET_MASK                       0x3
#define PMIC_RG_XO_AUDIO_ISET_SHIFT                      0
#define PMIC_RG_XO_EXTBUF1_HD_MASK                       0x3
#define PMIC_RG_XO_EXTBUF1_HD_SHIFT                      2
#define PMIC_RG_XO_EXTBUF2_HD_MASK                       0x3
#define PMIC_RG_XO_EXTBUF2_HD_SHIFT                      4
#define PMIC_RG_XO_EXTBUF3_HD_MASK                       0x3
#define PMIC_RG_XO_EXTBUF3_HD_SHIFT                      6
#define PMIC_RG_XO_EXTBUF4_HD_MASK                       0x3
#define PMIC_RG_XO_EXTBUF4_HD_SHIFT                      8
#define PMIC_RG_XO_RESERVED8_MASK                        0x3
#define PMIC_RG_XO_RESERVED8_SHIFT                       10
#define PMIC_RG_XO_EXTBUF6_HD_MASK                       0x3
#define PMIC_RG_XO_EXTBUF6_HD_SHIFT                      12
#define PMIC_RG_XO_EXTBUF7_HD_MASK                       0x3
#define PMIC_RG_XO_EXTBUF7_HD_SHIFT                      14
#define PMIC_XO_EXTBUF1_ISET_M_MASK                      0x3
#define PMIC_XO_EXTBUF1_ISET_M_SHIFT                     0
#define PMIC_XO_EXTBUF2_ISET_M_MASK                      0x3
#define PMIC_XO_EXTBUF2_ISET_M_SHIFT                     2
#define PMIC_XO_EXTBUF3_ISET_M_MASK                      0x3
#define PMIC_XO_EXTBUF3_ISET_M_SHIFT                     4
#define PMIC_XO_EXTBUF4_ISET_M_MASK                      0x3
#define PMIC_XO_EXTBUF4_ISET_M_SHIFT                     6
#define PMIC_XO_RESERVED9_MASK                           0x3
#define PMIC_XO_RESERVED9_SHIFT                          8
#define PMIC_XO_EXTBUF6_ISET_M_MASK                      0x3
#define PMIC_XO_EXTBUF6_ISET_M_SHIFT                     10
#define PMIC_XO_EXTBUF7_ISET_M_MASK                      0x3
#define PMIC_XO_EXTBUF7_ISET_M_SHIFT                     12
#define PMIC_RG_XO_LPM_PREBUF_ISET_MASK                  0x3
#define PMIC_RG_XO_LPM_PREBUF_ISET_SHIFT                 14
#define PMIC_RG_XO_RESERVED1_MASK                        0x3
#define PMIC_RG_XO_RESERVED1_SHIFT                       0
#define PMIC_XO_THADC_EN_MAN_MASK                        0x1
#define PMIC_XO_THADC_EN_MAN_SHIFT                       2
#define PMIC_RG_XO_TSOURCE_EN_MASK                       0x1
#define PMIC_RG_XO_TSOURCE_EN_SHIFT                      3
#define PMIC_XO_BUFLDO13_VSET_M_MASK                     0xF
#define PMIC_XO_BUFLDO13_VSET_M_SHIFT                    4
#define PMIC_XO_BUFLDO24_VSET_M_MASK                     0xF
#define PMIC_XO_BUFLDO24_VSET_M_SHIFT                    8
#define PMIC_XO_BUFLDO67_VSET_M_MASK                     0xF
#define PMIC_XO_BUFLDO67_VSET_M_SHIFT                    12
#define PMIC_XO_STATIC_AUXOUT_SEL_MASK                   0x3F
#define PMIC_XO_STATIC_AUXOUT_SEL_SHIFT                  0
#define PMIC_XO_AUXOUT_SEL_MASK                          0x3FF
#define PMIC_XO_AUXOUT_SEL_SHIFT                         6
#define PMIC_XO_STATIC_AUXOUT_MASK                       0xFFFF
#define PMIC_XO_STATIC_AUXOUT_SHIFT                      0
#define PMIC_RG_XO_PCTAT_COMP_EN_MASK                    0x1
#define PMIC_RG_XO_PCTAT_COMP_EN_SHIFT                   0
#define PMIC_RG_XO_PCTAT_RDEG_SEL_MASK                   0x1
#define PMIC_RG_XO_PCTAT_RDEG_SEL_SHIFT                  1
#define PMIC_RG_XO_GS_VTEMP_MASK                         0x7
#define PMIC_RG_XO_GS_VTEMP_SHIFT                        2
#define PMIC_RG_XO_HEATER_SEL_MASK                       0x3
#define PMIC_RG_XO_HEATER_SEL_SHIFT                      5
#define PMIC_RG_XO_CORNER_DETECT_EN_MASK                 0x1
#define PMIC_RG_XO_CORNER_DETECT_EN_SHIFT                7
#define PMIC_RG_XO_CORNER_DETECT_EN_MAN_MASK             0x1
#define PMIC_RG_XO_CORNER_DETECT_EN_MAN_SHIFT            8
#define PMIC_RG_XO_RESRVED10_MASK                        0x7F
#define PMIC_RG_XO_RESRVED10_SHIFT                       9
#define PMIC_RG_XO_CORNER_SETTING_TUNE_MASK              0x3FF
#define PMIC_RG_XO_CORNER_SETTING_TUNE_SHIFT             0
#define PMIC_RG_XO_RESRVED11_MASK                        0x3F
#define PMIC_RG_XO_RESRVED11_SHIFT                       10
#define PMIC_RG_AD_XO_CORNER_CAL_DONE_MASK               0x1
#define PMIC_RG_AD_XO_CORNER_CAL_DONE_SHIFT              0
#define PMIC_RG_AD_XO_CORNER_SEL_MASK                    0xF
#define PMIC_RG_AD_XO_CORNER_SEL_SHIFT                   1
#define PMIC_RG_VCDT_HV_EN_MASK                          0x1
#define PMIC_RG_VCDT_HV_EN_SHIFT                         0
#define PMIC_RG_VCDT_DEB_SEL_MASK                        0x1
#define PMIC_RG_VCDT_DEB_SEL_SHIFT                       2
#define PMIC_RG_PCHR_FT_CTRL_MASK                        0x1
#define PMIC_RG_PCHR_FT_CTRL_SHIFT                       4
#define PMIC_RGS_CHRDET_MASK                             0x1
#define PMIC_RGS_CHRDET_SHIFT                            5
#define PMIC_RGS_VCDT_LV_DET_MASK                        0x1
#define PMIC_RGS_VCDT_LV_DET_SHIFT                       6
#define PMIC_RGS_VCDT_HV_DET_MASK                        0x1
#define PMIC_RGS_VCDT_HV_DET_SHIFT                       7
#define PMIC_RG_VCDT_LV_VTH_MASK                         0xF
#define PMIC_RG_VCDT_LV_VTH_SHIFT                        0
#define PMIC_RG_VCDT_HV_VTH_MASK                         0xF
#define PMIC_RG_VCDT_HV_VTH_SHIFT                        4
#define PMIC_RGS_PCHR_FLAG_OUT_MASK                      0xF
#define PMIC_RGS_PCHR_FLAG_OUT_SHIFT                     0
#define PMIC_RG_PCHR_FLAG_EN_MASK                        0x1
#define PMIC_RG_PCHR_FLAG_EN_SHIFT                       4
#define PMIC_RG_PCHR_FLAG_SEL_MASK                       0xF
#define PMIC_RG_PCHR_FLAG_SEL_SHIFT                      0
#define PMIC_RG_PCHR_RSV_MASK                            0xFF
#define PMIC_RG_PCHR_RSV_SHIFT                           0
#define PMIC_RG_ENVTEM_D_MASK                            0x1
#define PMIC_RG_ENVTEM_D_SHIFT                           0
#define PMIC_RG_ENVTEM_EN_MASK                           0x1
#define PMIC_RG_ENVTEM_EN_SHIFT                          1
#define PMIC_RG_CHR_CON6_RSV_MASK                        0xFFFF
#define PMIC_RG_CHR_CON6_RSV_SHIFT                       0
#define PMIC_RG_ADCIN_VSEN_MUX_EN_MASK                   0x1
#define PMIC_RG_ADCIN_VSEN_MUX_EN_SHIFT                  8
#define PMIC_RG_ADCIN_VSEN_EXT_BATON_EN_MASK             0x1
#define PMIC_RG_ADCIN_VSEN_EXT_BATON_EN_SHIFT            9
#define PMIC_RG_ADCIN_VBAT_EN_MASK                       0x1
#define PMIC_RG_ADCIN_VBAT_EN_SHIFT                      10
#define PMIC_RG_ADCIN_VSEN_EN_MASK                       0x1
#define PMIC_RG_ADCIN_VSEN_EN_SHIFT                      11
#define PMIC_RG_ADCIN_CHR_EN_MASK                        0x1
#define PMIC_RG_ADCIN_CHR_EN_SHIFT                       12
#define PMIC_DA_QI_BATON_LT_EN_MASK                      0x1
#define PMIC_DA_QI_BATON_LT_EN_SHIFT                     0
#define PMIC_DA_QI_BGR_EXT_BUF_EN_MASK                   0x1
#define PMIC_DA_QI_BGR_EXT_BUF_EN_SHIFT                  1
#define PMIC_BATON_TDET_EN_MASK                          0x1
#define PMIC_BATON_TDET_EN_SHIFT                         2
#define PMIC_RG_BGR_UNCHOP_MASK                          0x1
#define PMIC_RG_BGR_UNCHOP_SHIFT                         0
#define PMIC_RG_BGR_UNCHOP_PH_MASK                       0x1
#define PMIC_RG_BGR_UNCHOP_PH_SHIFT                      1
#define PMIC_RG_BGR_RSEL_MASK                            0xF
#define PMIC_RG_BGR_RSEL_SHIFT                           2
#define PMIC_RG_BGR_TRIM_EN_MASK                         0x1
#define PMIC_RG_BGR_TRIM_EN_SHIFT                        6
#define PMIC_RG_BGR_TEST_RSTB_MASK                       0x1
#define PMIC_RG_BGR_TEST_RSTB_SHIFT                      7
#define PMIC_RG_BGR_TRIM_MASK                            0x1F
#define PMIC_RG_BGR_TRIM_SHIFT                           8
#define PMIC_RG_BGR_TEST_EN_MASK                         0x1
#define PMIC_RG_BGR_TEST_EN_SHIFT                        13
#define PMIC_RG_VCDT_TRIM_MASK                           0xF
#define PMIC_RG_VCDT_TRIM_SHIFT                          0
#define PMIC_RG_BATON_EN_MASK                            0x1
#define PMIC_RG_BATON_EN_SHIFT                           4
#define PMIC_RG_BATON_HT_TRIM_MASK                       0x7
#define PMIC_RG_BATON_HT_TRIM_SHIFT                      5
#define PMIC_RG_HW_VTH1_MASK                             0x3
#define PMIC_RG_HW_VTH1_SHIFT                            8
#define PMIC_RG_HW_VTH2_MASK                             0x3
#define PMIC_RG_HW_VTH2_SHIFT                            10
#define PMIC_RG_HW_VTH_CTRL_MASK                         0x1
#define PMIC_RG_HW_VTH_CTRL_SHIFT                        12
#define PMIC_RG_OTG_BVALID_EN_MASK                       0x1
#define PMIC_RG_OTG_BVALID_EN_SHIFT                      13
#define PMIC_RG_UVLO_VTHL_MASK                           0x1F
#define PMIC_RG_UVLO_VTHL_SHIFT                          0
#define PMIC_RG_UVLO_VH_LAT_MASK                         0x1
#define PMIC_RG_UVLO_VH_LAT_SHIFT                        5
#define PMIC_RG_LBAT_INT_VTH_MASK                        0x1F
#define PMIC_RG_LBAT_INT_VTH_SHIFT                       6
#define PMIC_RG_PCHR_RV_MASK                             0xF
#define PMIC_RG_PCHR_RV_SHIFT                            0
#define PMIC_RGS_BATON_UNDET_MASK                        0x1
#define PMIC_RGS_BATON_UNDET_SHIFT                       4
#define PMIC_RGS_OTG_BVALID_DET_MASK                     0x1
#define PMIC_RGS_OTG_BVALID_DET_SHIFT                    5
#define PMIC_RGS_CHR_LDO_DET_MASK                        0x1
#define PMIC_RGS_CHR_LDO_DET_SHIFT                       6
#define PMIC_RGS_BATON_HV_MASK                           0x1
#define PMIC_RGS_BATON_HV_SHIFT                          7
#define PMIC_RG_PCHR_ANA3_RSV_MASK                       0x1
#define PMIC_RG_PCHR_ANA3_RSV_SHIFT                      8
#define PMIC_RG_VCDT_UVLO_VTH_MASK                       0xF
#define PMIC_RG_VCDT_UVLO_VTH_SHIFT                      9
#define PMIC_GPIO_DIR0_MASK                              0x3FFF
#define PMIC_GPIO_DIR0_SHIFT                             0
#define PMIC_GPIO_DIR0_SET_MASK                          0xFFFF
#define PMIC_GPIO_DIR0_SET_SHIFT                         0
#define PMIC_GPIO_DIR0_CLR_MASK                          0xFFFF
#define PMIC_GPIO_DIR0_CLR_SHIFT                         0
#define PMIC_GPIO_PULLEN0_MASK                           0x3FFF
#define PMIC_GPIO_PULLEN0_SHIFT                          0
#define PMIC_GPIO_PULLEN0_SET_MASK                       0xFFFF
#define PMIC_GPIO_PULLEN0_SET_SHIFT                      0
#define PMIC_GPIO_PULLEN0_CLR_MASK                       0xFFFF
#define PMIC_GPIO_PULLEN0_CLR_SHIFT                      0
#define PMIC_GPIO_PULLSEL0_MASK                          0x3FFF
#define PMIC_GPIO_PULLSEL0_SHIFT                         0
#define PMIC_GPIO_PULLSEL0_SET_MASK                      0xFFFF
#define PMIC_GPIO_PULLSEL0_SET_SHIFT                     0
#define PMIC_GPIO_PULLSEL0_CLR_MASK                      0xFFFF
#define PMIC_GPIO_PULLSEL0_CLR_SHIFT                     0
#define PMIC_GPIO_DINV0_MASK                             0x3FFF
#define PMIC_GPIO_DINV0_SHIFT                            0
#define PMIC_GPIO_DINV0_SET_MASK                         0xFFFF
#define PMIC_GPIO_DINV0_SET_SHIFT                        0
#define PMIC_GPIO_DINV0_CLR_MASK                         0xFFFF
#define PMIC_GPIO_DINV0_CLR_SHIFT                        0
#define PMIC_GPIO_DOUT0_MASK                             0x3FFF
#define PMIC_GPIO_DOUT0_SHIFT                            0
#define PMIC_GPIO_DOUT0_SET_MASK                         0xFFFF
#define PMIC_GPIO_DOUT0_SET_SHIFT                        0
#define PMIC_GPIO_DOUT0_CLR_MASK                         0xFFFF
#define PMIC_GPIO_DOUT0_CLR_SHIFT                        0
#define PMIC_GPIO_PI0_MASK                               0x3FFF
#define PMIC_GPIO_PI0_SHIFT                              0
#define PMIC_GPIO_POE0_MASK                              0x3FFF
#define PMIC_GPIO_POE0_SHIFT                             0
#define PMIC_GPIO0_MODE_MASK                             0x7
#define PMIC_GPIO0_MODE_SHIFT                            0
#define PMIC_GPIO1_MODE_MASK                             0x7
#define PMIC_GPIO1_MODE_SHIFT                            3
#define PMIC_GPIO2_MODE_MASK                             0x7
#define PMIC_GPIO2_MODE_SHIFT                            6
#define PMIC_GPIO3_MODE_MASK                             0x7
#define PMIC_GPIO3_MODE_SHIFT                            9
#define PMIC_GPIO4_MODE_MASK                             0x7
#define PMIC_GPIO4_MODE_SHIFT                            12
#define PMIC_GPIO_MODE0_SET_MASK                         0xFFFF
#define PMIC_GPIO_MODE0_SET_SHIFT                        0
#define PMIC_GPIO_MODE0_CLR_MASK                         0xFFFF
#define PMIC_GPIO_MODE0_CLR_SHIFT                        0
#define PMIC_GPIO5_MODE_MASK                             0x7
#define PMIC_GPIO5_MODE_SHIFT                            0
#define PMIC_GPIO6_MODE_MASK                             0x7
#define PMIC_GPIO6_MODE_SHIFT                            3
#define PMIC_GPIO7_MODE_MASK                             0x7
#define PMIC_GPIO7_MODE_SHIFT                            6
#define PMIC_GPIO8_MODE_MASK                             0x7
#define PMIC_GPIO8_MODE_SHIFT                            9
#define PMIC_GPIO9_MODE_MASK                             0x7
#define PMIC_GPIO9_MODE_SHIFT                            12
#define PMIC_GPIO_MODE1_SET_MASK                         0xFFFF
#define PMIC_GPIO_MODE1_SET_SHIFT                        0
#define PMIC_GPIO_MODE1_CLR_MASK                         0xFFFF
#define PMIC_GPIO_MODE1_CLR_SHIFT                        0
#define PMIC_GPIO10_MODE_MASK                            0x7
#define PMIC_GPIO10_MODE_SHIFT                           0
#define PMIC_GPIO11_MODE_MASK                            0x7
#define PMIC_GPIO11_MODE_SHIFT                           3
#define PMIC_GPIO12_MODE_MASK                            0x7
#define PMIC_GPIO12_MODE_SHIFT                           6
#define PMIC_GPIO13_MODE_MASK                            0x7
#define PMIC_GPIO13_MODE_SHIFT                           9
#define PMIC_GPIO_MODE2_SET_MASK                         0xFFFF
#define PMIC_GPIO_MODE2_SET_SHIFT                        0
#define PMIC_GPIO_MODE2_CLR_MASK                         0xFFFF
#define PMIC_GPIO_MODE2_CLR_SHIFT                        0
#define PMIC_GPIO_RSV_MASK                               0xFFFF
#define PMIC_GPIO_RSV_SHIFT                              0
#define PMIC_RTC_SEC_DUMMY_MASK                          0xFFFF
#define PMIC_RTC_SEC_DUMMY_SHIFT                         0
#define PMIC_RTC_DUMMY_MASK                              0xFFFF
#define PMIC_RTC_DUMMY_SHIFT                             0
#define PMIC_EOSC_CALI_START_MASK                        0x1
#define PMIC_EOSC_CALI_START_SHIFT                       0
#define PMIC_EOSC_CALI_TD_MASK                           0x7
#define PMIC_EOSC_CALI_TD_SHIFT                          5
#define PMIC_EOSC_CALI_TEST_MASK                         0xF
#define PMIC_EOSC_CALI_TEST_SHIFT                        9
#define PMIC_EOSC_CALI_DCXO_RDY_TD_MASK                  0x7
#define PMIC_EOSC_CALI_DCXO_RDY_TD_SHIFT                 0
#define PMIC_FRC_VTCXO0_ON_MASK                          0x1
#define PMIC_FRC_VTCXO0_ON_SHIFT                         8
#define PMIC_EOSC_CALI_RSV_MASK                          0xF
#define PMIC_EOSC_CALI_RSV_SHIFT                         11
#define PMIC_MIX_EOSC32_STP_LPDTB_MASK                   0x1
#define PMIC_MIX_EOSC32_STP_LPDTB_SHIFT                  1
#define PMIC_MIX_EOSC32_STP_LPDEN_MASK                   0x1
#define PMIC_MIX_EOSC32_STP_LPDEN_SHIFT                  2
#define PMIC_MIX_XOSC32_STP_PWDB_MASK                    0x1
#define PMIC_MIX_XOSC32_STP_PWDB_SHIFT                   3
#define PMIC_MIX_XOSC32_STP_LPDTB_MASK                   0x1
#define PMIC_MIX_XOSC32_STP_LPDTB_SHIFT                  4
#define PMIC_MIX_XOSC32_STP_LPDEN_MASK                   0x1
#define PMIC_MIX_XOSC32_STP_LPDEN_SHIFT                  5
#define PMIC_MIX_XOSC32_STP_LPDRST_MASK                  0x1
#define PMIC_MIX_XOSC32_STP_LPDRST_SHIFT                 6
#define PMIC_MIX_XOSC32_STP_CALI_MASK                    0x1F
#define PMIC_MIX_XOSC32_STP_CALI_SHIFT                   7
#define PMIC_STMP_MODE_MASK                              0x1
#define PMIC_STMP_MODE_SHIFT                             12
#define PMIC_MIX_EOSC32_STP_CHOP_EN_MASK                 0x1
#define PMIC_MIX_EOSC32_STP_CHOP_EN_SHIFT                0
#define PMIC_MIX_DCXO_STP_LVSH_EN_MASK                   0x1
#define PMIC_MIX_DCXO_STP_LVSH_EN_SHIFT                  1
#define PMIC_MIX_PMU_STP_DDLO_VRTC_MASK                  0x1
#define PMIC_MIX_PMU_STP_DDLO_VRTC_SHIFT                 2
#define PMIC_MIX_PMU_STP_DDLO_VRTC_EN_MASK               0x1
#define PMIC_MIX_PMU_STP_DDLO_VRTC_EN_SHIFT              3
#define PMIC_MIX_RTC_STP_XOSC32_ENB_MASK                 0x1
#define PMIC_MIX_RTC_STP_XOSC32_ENB_SHIFT                4
#define PMIC_MIX_DCXO_STP_TEST_DEGLITCH_MODE_MASK        0x1
#define PMIC_MIX_DCXO_STP_TEST_DEGLITCH_MODE_SHIFT       5
#define PMIC_MIX_EOSC32_STP_RSV_MASK                     0x3
#define PMIC_MIX_EOSC32_STP_RSV_SHIFT                    6
#define PMIC_MIX_EOSC32_VCT_EN_MASK                      0x1
#define PMIC_MIX_EOSC32_VCT_EN_SHIFT                     8
#define PMIC_MIX_EOSC32_OPT_MASK                         0x3
#define PMIC_MIX_EOSC32_OPT_SHIFT                        9
#define PMIC_MIX_DCXO_STP_LVSH_EN_INT_MASK               0x1
#define PMIC_MIX_DCXO_STP_LVSH_EN_INT_SHIFT              11
#define PMIC_MIX_RTC_GPIO_COREDETB_MASK                  0x1
#define PMIC_MIX_RTC_GPIO_COREDETB_SHIFT                 12
#define PMIC_MIX_RTC_GPIO_F32KOB_MASK                    0x1
#define PMIC_MIX_RTC_GPIO_F32KOB_SHIFT                   13
#define PMIC_MIX_RTC_GPIO_GPO_MASK                       0x1
#define PMIC_MIX_RTC_GPIO_GPO_SHIFT                      14
#define PMIC_MIX_RTC_GPIO_OE_MASK                        0x1
#define PMIC_MIX_RTC_GPIO_OE_SHIFT                       15
#define PMIC_MIX_RTC_STP_DEBUG_OUT_MASK                  0x3
#define PMIC_MIX_RTC_STP_DEBUG_OUT_SHIFT                 0
#define PMIC_MIX_RTC_STP_DEBUG_SEL_MASK                  0x3
#define PMIC_MIX_RTC_STP_DEBUG_SEL_SHIFT                 4
#define PMIC_MIX_RTC_STP_K_EOSC32_EN_MASK                0x1
#define PMIC_MIX_RTC_STP_K_EOSC32_EN_SHIFT               7
#define PMIC_MIX_RTC_STP_EMBCK_SEL_MASK                  0x1
#define PMIC_MIX_RTC_STP_EMBCK_SEL_SHIFT                 8
#define PMIC_MIX_STP_BBWAKEUP_MASK                       0x1
#define PMIC_MIX_STP_BBWAKEUP_SHIFT                      9
#define PMIC_MIX_STP_RTC_DDLO_MASK                       0x1
#define PMIC_MIX_STP_RTC_DDLO_SHIFT                      10
#define PMIC_MIX_RTC_XOSC32_ENB_MASK                     0x1
#define PMIC_MIX_RTC_XOSC32_ENB_SHIFT                    11
#define PMIC_MIX_EFUSE_XOSC32_ENB_OPT_MASK               0x1
#define PMIC_MIX_EFUSE_XOSC32_ENB_OPT_SHIFT              12
#define PMIC_VRTC_PWM_MODE_MASK                          0x1
#define PMIC_VRTC_PWM_MODE_SHIFT                         0
#define PMIC_VRTC_PWM_RSV_MASK                           0x7
#define PMIC_VRTC_PWM_RSV_SHIFT                          1
#define PMIC_VRTC_PWM_L_DUTY_MASK                        0xF
#define PMIC_VRTC_PWM_L_DUTY_SHIFT                       4
#define PMIC_VRTC_PWM_H_DUTY_MASK                        0xF
#define PMIC_VRTC_PWM_H_DUTY_SHIFT                       8
#define PMIC_VRTC_CAP_SEL_MASK                           0x1
#define PMIC_VRTC_CAP_SEL_SHIFT                          12
#define PMIC_BIF_COMMAND_0_MASK                          0x7FF
#define PMIC_BIF_COMMAND_0_SHIFT                         0
#define PMIC_BIF_COMMAND_1_MASK                          0x7FF
#define PMIC_BIF_COMMAND_1_SHIFT                         0
#define PMIC_BIF_COMMAND_2_MASK                          0x7FF
#define PMIC_BIF_COMMAND_2_SHIFT                         0
#define PMIC_BIF_COMMAND_3_MASK                          0x7FF
#define PMIC_BIF_COMMAND_3_SHIFT                         0
#define PMIC_BIF_COMMAND_4_MASK                          0x7FF
#define PMIC_BIF_COMMAND_4_SHIFT                         0
#define PMIC_BIF_COMMAND_5_MASK                          0x7FF
#define PMIC_BIF_COMMAND_5_SHIFT                         0
#define PMIC_BIF_COMMAND_6_MASK                          0x7FF
#define PMIC_BIF_COMMAND_6_SHIFT                         0
#define PMIC_BIF_COMMAND_7_MASK                          0x7FF
#define PMIC_BIF_COMMAND_7_SHIFT                         0
#define PMIC_BIF_COMMAND_8_MASK                          0x7FF
#define PMIC_BIF_COMMAND_8_SHIFT                         0
#define PMIC_BIF_COMMAND_9_MASK                          0x7FF
#define PMIC_BIF_COMMAND_9_SHIFT                         0
#define PMIC_BIF_COMMAND_10_MASK                         0x7FF
#define PMIC_BIF_COMMAND_10_SHIFT                        0
#define PMIC_BIF_COMMAND_11_MASK                         0x7FF
#define PMIC_BIF_COMMAND_11_SHIFT                        0
#define PMIC_BIF_COMMAND_12_MASK                         0x7FF
#define PMIC_BIF_COMMAND_12_SHIFT                        0
#define PMIC_BIF_COMMAND_13_MASK                         0x7FF
#define PMIC_BIF_COMMAND_13_SHIFT                        0
#define PMIC_BIF_COMMAND_14_MASK                         0x7FF
#define PMIC_BIF_COMMAND_14_SHIFT                        0
#define PMIC_BIF_RSV_MASK                                0x7F
#define PMIC_BIF_RSV_SHIFT                               0
#define PMIC_BIF_COMMAND_TYPE_MASK                       0x3
#define PMIC_BIF_COMMAND_TYPE_SHIFT                      8
#define PMIC_BIF_TRASFER_NUM_MASK                        0xF
#define PMIC_BIF_TRASFER_NUM_SHIFT                       12
#define PMIC_BIF_LOGIC_0_SET_MASK                        0xF
#define PMIC_BIF_LOGIC_0_SET_SHIFT                       0
#define PMIC_BIF_LOGIC_1_SET_MASK                        0x1F
#define PMIC_BIF_LOGIC_1_SET_SHIFT                       4
#define PMIC_BIF_STOP_SET_MASK                           0x3F
#define PMIC_BIF_STOP_SET_SHIFT                          10
#define PMIC_BIF_DEBOUNCE_EN_MASK                        0x1
#define PMIC_BIF_DEBOUNCE_EN_SHIFT                       4
#define PMIC_BIF_READ_EXPECT_NUM_MASK                    0xF
#define PMIC_BIF_READ_EXPECT_NUM_SHIFT                   12
#define PMIC_BIF_TRASACT_TRIGGER_MASK                    0x1
#define PMIC_BIF_TRASACT_TRIGGER_SHIFT                   0
#define PMIC_BIF_DATA_NUM_MASK                           0xF
#define PMIC_BIF_DATA_NUM_SHIFT                          0
#define PMIC_BIF_RESPONSE_MASK                           0x1
#define PMIC_BIF_RESPONSE_SHIFT                          12
#define PMIC_BIF_DATA_0_MASK                             0xFF
#define PMIC_BIF_DATA_0_SHIFT                            0
#define PMIC_BIF_ACK_0_MASK                              0x1
#define PMIC_BIF_ACK_0_SHIFT                             8
#define PMIC_BIF_ERROR_0_MASK                            0x1
#define PMIC_BIF_ERROR_0_SHIFT                           15
#define PMIC_BIF_DATA_1_MASK                             0xFF
#define PMIC_BIF_DATA_1_SHIFT                            0
#define PMIC_BIF_ACK_1_MASK                              0x1
#define PMIC_BIF_ACK_1_SHIFT                             8
#define PMIC_BIF_ERROR_1_MASK                            0x1
#define PMIC_BIF_ERROR_1_SHIFT                           15
#define PMIC_BIF_DATA_2_MASK                             0xFF
#define PMIC_BIF_DATA_2_SHIFT                            0
#define PMIC_BIF_ACK_2_MASK                              0x1
#define PMIC_BIF_ACK_2_SHIFT                             8
#define PMIC_BIF_ERROR_2_MASK                            0x1
#define PMIC_BIF_ERROR_2_SHIFT                           15
#define PMIC_BIF_DATA_3_MASK                             0xFF
#define PMIC_BIF_DATA_3_SHIFT                            0
#define PMIC_BIF_ACK_3_MASK                              0x1
#define PMIC_BIF_ACK_3_SHIFT                             8
#define PMIC_BIF_ERROR_3_MASK                            0x1
#define PMIC_BIF_ERROR_3_SHIFT                           15
#define PMIC_BIF_DATA_4_MASK                             0xFF
#define PMIC_BIF_DATA_4_SHIFT                            0
#define PMIC_BIF_ACK_4_MASK                              0x1
#define PMIC_BIF_ACK_4_SHIFT                             8
#define PMIC_BIF_ERROR_4_MASK                            0x1
#define PMIC_BIF_ERROR_4_SHIFT                           15
#define PMIC_BIF_DATA_5_MASK                             0xFF
#define PMIC_BIF_DATA_5_SHIFT                            0
#define PMIC_BIF_ACK_5_MASK                              0x1
#define PMIC_BIF_ACK_5_SHIFT                             8
#define PMIC_BIF_ERROR_5_MASK                            0x1
#define PMIC_BIF_ERROR_5_SHIFT                           15
#define PMIC_BIF_DATA_6_MASK                             0xFF
#define PMIC_BIF_DATA_6_SHIFT                            0
#define PMIC_BIF_ACK_6_MASK                              0x1
#define PMIC_BIF_ACK_6_SHIFT                             8
#define PMIC_BIF_ERROR_6_MASK                            0x1
#define PMIC_BIF_ERROR_6_SHIFT                           15
#define PMIC_BIF_DATA_7_MASK                             0xFF
#define PMIC_BIF_DATA_7_SHIFT                            0
#define PMIC_BIF_ACK_7_MASK                              0x1
#define PMIC_BIF_ACK_7_SHIFT                             8
#define PMIC_BIF_ERROR_7_MASK                            0x1
#define PMIC_BIF_ERROR_7_SHIFT                           15
#define PMIC_BIF_DATA_8_MASK                             0xFF
#define PMIC_BIF_DATA_8_SHIFT                            0
#define PMIC_BIF_ACK_8_MASK                              0x1
#define PMIC_BIF_ACK_8_SHIFT                             8
#define PMIC_BIF_ERROR_8_MASK                            0x1
#define PMIC_BIF_ERROR_8_SHIFT                           15
#define PMIC_BIF_DATA_9_MASK                             0xFF
#define PMIC_BIF_DATA_9_SHIFT                            0
#define PMIC_BIF_ACK_9_MASK                              0x1
#define PMIC_BIF_ACK_9_SHIFT                             8
#define PMIC_BIF_ERROR_9_MASK                            0x1
#define PMIC_BIF_ERROR_9_SHIFT                           15
#define PMIC_BIF_TEST_MODE0_MASK                         0x1
#define PMIC_BIF_TEST_MODE0_SHIFT                        0
#define PMIC_BIF_TEST_MODE1_MASK                         0x1
#define PMIC_BIF_TEST_MODE1_SHIFT                        1
#define PMIC_BIF_TEST_MODE2_MASK                         0x1
#define PMIC_BIF_TEST_MODE2_SHIFT                        2
#define PMIC_BIF_TEST_MODE3_MASK                         0x1
#define PMIC_BIF_TEST_MODE3_SHIFT                        3
#define PMIC_BIF_TEST_MODE4_MASK                         0x1
#define PMIC_BIF_TEST_MODE4_SHIFT                        4
#define PMIC_BIF_TEST_MODE5_MASK                         0x1
#define PMIC_BIF_TEST_MODE5_SHIFT                        5
#define PMIC_BIF_TEST_MODE6_MASK                         0x1
#define PMIC_BIF_TEST_MODE6_SHIFT                        6
#define PMIC_BIF_TEST_MODE7_MASK                         0x1
#define PMIC_BIF_TEST_MODE7_SHIFT                        7
#define PMIC_BIF_TEST_MODE8_MASK                         0x1
#define PMIC_BIF_TEST_MODE8_SHIFT                        8
#define PMIC_BIF_BAT_LOST_SW_MASK                        0x1
#define PMIC_BIF_BAT_LOST_SW_SHIFT                       11
#define PMIC_BIF_RX_DATA_SW_MASK                         0x1
#define PMIC_BIF_RX_DATA_SW_SHIFT                        12
#define PMIC_BIF_TX_DATA_SW_MASK                         0x1
#define PMIC_BIF_TX_DATA_SW_SHIFT                        13
#define PMIC_BIF_RX_EN_SW_MASK                           0x1
#define PMIC_BIF_RX_EN_SW_SHIFT                          14
#define PMIC_BIF_TX_EN_SW_MASK                           0x1
#define PMIC_BIF_TX_EN_SW_SHIFT                          15
#define PMIC_BIF_BACK_NORMAL_MASK                        0x1
#define PMIC_BIF_BACK_NORMAL_SHIFT                       0
#define PMIC_BIF_IRQ_CLR_MASK                            0x1
#define PMIC_BIF_IRQ_CLR_SHIFT                           1
#define PMIC_BIF_IRQ_MASK                                0x1
#define PMIC_BIF_IRQ_SHIFT                               11
#define PMIC_BIF_TIMEOUT_MASK                            0x1
#define PMIC_BIF_TIMEOUT_SHIFT                           12
#define PMIC_BIF_BAT_UNDET_MASK                          0x1
#define PMIC_BIF_BAT_UNDET_SHIFT                         13
#define PMIC_BIF_TOTAL_VALID_MASK                        0x1
#define PMIC_BIF_TOTAL_VALID_SHIFT                       14
#define PMIC_BIF_BUS_STATUS_MASK                         0x1
#define PMIC_BIF_BUS_STATUS_SHIFT                        15
#define PMIC_BIF_POWER_UP_COUNT_MASK                     0x1F
#define PMIC_BIF_POWER_UP_COUNT_SHIFT                    0
#define PMIC_BIF_POWER_UP_MASK                           0x1
#define PMIC_BIF_POWER_UP_SHIFT                          15
#define PMIC_BIF_RX_ERROR_UNKNOW_MASK                    0x1
#define PMIC_BIF_RX_ERROR_UNKNOW_SHIFT                   2
#define PMIC_BIF_RX_ERROR_INSUFF_MASK                    0x1
#define PMIC_BIF_RX_ERROR_INSUFF_SHIFT                   3
#define PMIC_BIF_RX_ERROR_LOWPHASE_MASK                  0x1
#define PMIC_BIF_RX_ERROR_LOWPHASE_SHIFT                 4
#define PMIC_BIF_RX_STATE_MASK                           0x7
#define PMIC_BIF_RX_STATE_SHIFT                          5
#define PMIC_BIF_FLOW_CTL_STATE_MASK                     0x3
#define PMIC_BIF_FLOW_CTL_STATE_SHIFT                    8
#define PMIC_BIF_TX_STATE_MASK                           0x3
#define PMIC_BIF_TX_STATE_SHIFT                          10
#define PMIC_AD_QI_BIF_RX_DATA_MASK                      0x1
#define PMIC_AD_QI_BIF_RX_DATA_SHIFT                     12
#define PMIC_DA_QI_BIF_RX_EN_MASK                        0x1
#define PMIC_DA_QI_BIF_RX_EN_SHIFT                       13
#define PMIC_DA_QI_BIF_TX_DATA_MASK                      0x1
#define PMIC_DA_QI_BIF_TX_DATA_SHIFT                     14
#define PMIC_DA_QI_BIF_TX_EN_MASK                        0x1
#define PMIC_DA_QI_BIF_TX_EN_SHIFT                       15
#define PMIC_BIF_TX_DATA_FIANL_MASK                      0xFFFF
#define PMIC_BIF_TX_DATA_FIANL_SHIFT                     0
#define PMIC_BIF_RX_DATA_SAMPLING_MASK                   0xFFFF
#define PMIC_BIF_RX_DATA_SAMPLING_SHIFT                  0
#define PMIC_BIF_RX_DATA_RECOVERY_MASK                   0x3FFF
#define PMIC_BIF_RX_DATA_RECOVERY_SHIFT                  0
#define PMIC_RG_BATON_HT_EN_MASK                         0x1
#define PMIC_RG_BATON_HT_EN_SHIFT                        14
#define PMIC_RG_BATON_HT_EN_DLY_TIME_MASK                0x1
#define PMIC_RG_BATON_HT_EN_DLY_TIME_SHIFT               15
#define PMIC_BIF_TIMEOUT_SET_MASK                        0xFFFF
#define PMIC_BIF_TIMEOUT_SET_SHIFT                       0
#define PMIC_BIF_RX_DEG_WND_MASK                         0x3FF
#define PMIC_BIF_RX_DEG_WND_SHIFT                        0
#define PMIC_BIF_RX_DEG_EN_MASK                          0x1
#define PMIC_BIF_RX_DEG_EN_SHIFT                         15
#define PMIC_BIF_RSV1_MASK                               0xFF
#define PMIC_BIF_RSV1_SHIFT                              0
#define PMIC_BIF_RSV0_MASK                               0xFF
#define PMIC_BIF_RSV0_SHIFT                              8
#define PMIC_DA_QI_BATON_HT_EN_MASK                      0x1
#define PMIC_DA_QI_BATON_HT_EN_SHIFT                     5
#define PMIC_RG_BATON_DEBOUNCE_WND_MASK                  0x3
#define PMIC_RG_BATON_DEBOUNCE_WND_SHIFT                 0
#define PMIC_RG_BATON_DEBOUNCE_THD_MASK                  0x3
#define PMIC_RG_BATON_DEBOUNCE_THD_SHIFT                 2
#define PMIC_RG_BATON_VBIF_STB_MASK                      0x1
#define PMIC_RG_BATON_VBIF_STB_SHIFT                     4
#define PMIC_RG_BATON_CHRDET_TEST_MODE_MASK              0x1
#define PMIC_RG_BATON_CHRDET_TEST_MODE_SHIFT             0
#define PMIC_RG_BATON_UNDET_TEST_MODE_MASK               0x1
#define PMIC_RG_BATON_UNDET_TEST_MODE_SHIFT              1
#define PMIC_RG_BATON_AUXADC_TEST_MODE_MASK              0x1
#define PMIC_RG_BATON_AUXADC_TEST_MODE_SHIFT             2
#define PMIC_RG_BATON_FGADC_TEST_MODE_MASK               0x1
#define PMIC_RG_BATON_FGADC_TEST_MODE_SHIFT              3
#define PMIC_RG_BATON_RTC_TEST_MODE_MASK                 0x1
#define PMIC_RG_BATON_RTC_TEST_MODE_SHIFT                4
#define PMIC_RG_BATON_BIF_TEST_MODE_MASK                 0x1
#define PMIC_RG_BATON_BIF_TEST_MODE_SHIFT                5
#define PMIC_RG_BATON_RSV_MASK                           0x3
#define PMIC_RG_BATON_RSV_SHIFT                          6
#define PMIC_RG_BATON_CHRDET_SW_MASK                     0x1
#define PMIC_RG_BATON_CHRDET_SW_SHIFT                    8
#define PMIC_RG_BATON_UNDET_SW_MASK                      0x1
#define PMIC_RG_BATON_UNDET_SW_SHIFT                     9
#define PMIC_RG_BATON_AUXADC_SW_MASK                     0x1
#define PMIC_RG_BATON_AUXADC_SW_SHIFT                    10
#define PMIC_RG_BATON_FGADC_SW_MASK                      0x1
#define PMIC_RG_BATON_FGADC_SW_SHIFT                     11
#define PMIC_RG_BATON_RTC_SW_MASK                        0x1
#define PMIC_RG_BATON_RTC_SW_SHIFT                       12
#define PMIC_RG_BATON_BIF_SW_MASK                        0x1
#define PMIC_RG_BATON_BIF_SW_SHIFT                       13
#define PMIC_RG_BATON_RSV_SW_MASK                        0x3
#define PMIC_RG_BATON_RSV_SW_SHIFT                       14
#define PMIC_BATON_STATUS_MASK                           0x1
#define PMIC_BATON_STATUS_SHIFT                          0
#define PMIC_BATON_AUXADC_SET_MASK                       0x1
#define PMIC_BATON_AUXADC_SET_SHIFT                      1
#define PMIC_BATON_DEB_VALID_MASK                        0x1
#define PMIC_BATON_DEB_VALID_SHIFT                       2
#define PMIC_BATON_BIF_STATUS_MASK                       0x1
#define PMIC_BATON_BIF_STATUS_SHIFT                      3
#define PMIC_BATON_RTC_STATUS_MASK                       0x1
#define PMIC_BATON_RTC_STATUS_SHIFT                      4
#define PMIC_BATON_FGADC_STATUS_MASK                     0x1
#define PMIC_BATON_FGADC_STATUS_SHIFT                    5
#define PMIC_BATON_AUXADC_TRIG_MASK                      0x1
#define PMIC_BATON_AUXADC_TRIG_SHIFT                     6
#define PMIC_BATON_CHRDET_DEB_MASK                       0x1
#define PMIC_BATON_CHRDET_DEB_SHIFT                      7
#define PMIC_BATON_IVGEN_ENB_MASK                        0x1
#define PMIC_BATON_IVGEN_ENB_SHIFT                       8
#define PMIC_BATON_VBIF28_STB_MASK                       0x1
#define PMIC_BATON_VBIF28_STB_SHIFT                      9
#define PMIC_BATON_VBIF28_EN_MASK                        0x1
#define PMIC_BATON_VBIF28_EN_SHIFT                       10
#define PMIC_BATON_RSV_0_MASK                            0x1F
#define PMIC_BATON_RSV_0_SHIFT                           11
#define PMIC_RG_BIF_BATID_SW_EN_MASK                     0x1
#define PMIC_RG_BIF_BATID_SW_EN_SHIFT                    0
#define PMIC_FG_ON_MASK                                  0x1
#define PMIC_FG_ON_SHIFT                                 0
#define PMIC_FG_CAL_MASK                                 0x3
#define PMIC_FG_CAL_SHIFT                                2
#define PMIC_FG_AUTOCALRATE_MASK                         0x7
#define PMIC_FG_AUTOCALRATE_SHIFT                        4
#define PMIC_FG_SON_SLP_EN_MASK                          0x1
#define PMIC_FG_SON_SLP_EN_SHIFT                         8
#define PMIC_FG_SOFF_SLP_EN_MASK                         0x1
#define PMIC_FG_SOFF_SLP_EN_SHIFT                        9
#define PMIC_FG_ZCV_DET_EN_MASK                          0x1
#define PMIC_FG_ZCV_DET_EN_SHIFT                         10
#define PMIC_FG_AUXADC_R_MASK                            0x1
#define PMIC_FG_AUXADC_R_SHIFT                           11
#define PMIC_FG_IAVG_MODE_MASK                           0xF
#define PMIC_FG_IAVG_MODE_SHIFT                          12
#define PMIC_FG_SW_READ_PRE_MASK                         0x1
#define PMIC_FG_SW_READ_PRE_SHIFT                        0
#define PMIC_FG_SW_RSTCLR_MASK                           0x1
#define PMIC_FG_SW_RSTCLR_SHIFT                          1
#define PMIC_FG_SW_CR_MASK                               0x1
#define PMIC_FG_SW_CR_SHIFT                              2
#define PMIC_FG_SW_CLEAR_MASK                            0x1
#define PMIC_FG_SW_CLEAR_SHIFT                           3
#define PMIC_FG_OFFSET_RST_MASK                          0x1
#define PMIC_FG_OFFSET_RST_SHIFT                         8
#define PMIC_FG_TIME_RST_MASK                            0x1
#define PMIC_FG_TIME_RST_SHIFT                           9
#define PMIC_FG_CHARGE_RST_MASK                          0x1
#define PMIC_FG_CHARGE_RST_SHIFT                         10
#define PMIC_FG_N_CHARGE_RST_MASK                        0x1
#define PMIC_FG_N_CHARGE_RST_SHIFT                       11
#define PMIC_FG_SOFF_RST_MASK                            0x1
#define PMIC_FG_SOFF_RST_SHIFT                           12
#define PMIC_FG_LATCHDATA_ST_MASK                        0x1
#define PMIC_FG_LATCHDATA_ST_SHIFT                       15
#define PMIC_EVENT_FG_BAT0_L_MASK                        0x1
#define PMIC_EVENT_FG_BAT0_L_SHIFT                       0
#define PMIC_EVENT_FG_BAT0_H_MASK                        0x1
#define PMIC_EVENT_FG_BAT0_H_SHIFT                       1
#define PMIC_EVENT_FG_BAT1_L_MASK                        0x1
#define PMIC_EVENT_FG_BAT1_L_SHIFT                       2
#define PMIC_EVENT_FG_BAT1_H_MASK                        0x1
#define PMIC_EVENT_FG_BAT1_H_SHIFT                       3
#define PMIC_EVENT_FG_CUR_L_MASK                         0x1
#define PMIC_EVENT_FG_CUR_L_SHIFT                        4
#define PMIC_EVENT_FG_CUR_H_MASK                         0x1
#define PMIC_EVENT_FG_CUR_H_SHIFT                        5
#define PMIC_EVENT_FG_IAVG_L_MASK                        0x1
#define PMIC_EVENT_FG_IAVG_L_SHIFT                       6
#define PMIC_EVENT_FG_IAVG_H_MASK                        0x1
#define PMIC_EVENT_FG_IAVG_H_SHIFT                       7
#define PMIC_EVENT_FG_N_CHARGE_L_MASK                    0x1
#define PMIC_EVENT_FG_N_CHARGE_L_SHIFT                   8
#define PMIC_EVENT_FG_TIME_H_MASK                        0x1
#define PMIC_EVENT_FG_TIME_H_SHIFT                       11
#define PMIC_EVENT_FG_DISCHARGE_MASK                     0x1
#define PMIC_EVENT_FG_DISCHARGE_SHIFT                    12
#define PMIC_EVENT_FG_CHARGE_MASK                        0x1
#define PMIC_EVENT_FG_CHARGE_SHIFT                       13
#define PMIC_EVENT_FG_ZCV_MASK                           0x1
#define PMIC_EVENT_FG_ZCV_SHIFT                          14
#define PMIC_FG_OSR1_MASK                                0xF
#define PMIC_FG_OSR1_SHIFT                               0
#define PMIC_FG_OSR2_MASK                                0x3
#define PMIC_FG_OSR2_SHIFT                               8
#define PMIC_FG_FIR1BYPASS_MASK                          0x1
#define PMIC_FG_FIR1BYPASS_SHIFT                         0
#define PMIC_FG_FIR2BYPASS_MASK                          0x1
#define PMIC_FG_FIR2BYPASS_SHIFT                         1
#define PMIC_FG_ADJ_OFFSET_EN_MASK                       0x1
#define PMIC_FG_ADJ_OFFSET_EN_SHIFT                      2
#define PMIC_FG_ADC_AUTORST_MASK                         0x1
#define PMIC_FG_ADC_AUTORST_SHIFT                        3
#define PMIC_FG_ADC_RSTDETECT_MASK                       0x1
#define PMIC_FG_ADC_RSTDETECT_SHIFT                      4
#define PMIC_FG_VA18_AON_MASK                            0x1
#define PMIC_FG_VA18_AON_SHIFT                           5
#define PMIC_FG_VA18_AOFF_MASK                           0x1
#define PMIC_FG_VA18_AOFF_SHIFT                          6
#define PMIC_FG_SON_SW_MASK                              0x1
#define PMIC_FG_SON_SW_SHIFT                             7
#define PMIC_FG_SON_SW_MODE_MASK                         0x1
#define PMIC_FG_SON_SW_MODE_SHIFT                        8
#define PMIC_FGADC_CON4_RSV_MASK                         0x7F
#define PMIC_FGADC_CON4_RSV_SHIFT                        9
#define PMIC_FG_RSTB_STATUS_MASK                         0x1
#define PMIC_FG_RSTB_STATUS_SHIFT                        0
#define PMIC_FG_R_CURR_MASK                              0xFFFF
#define PMIC_FG_R_CURR_SHIFT                             0
#define PMIC_FG_CURRENT_OUT_MASK                         0xFFFF
#define PMIC_FG_CURRENT_OUT_SHIFT                        0
#define PMIC_FG_CUR_LTH_MASK                             0xFFFF
#define PMIC_FG_CUR_LTH_SHIFT                            0
#define PMIC_FG_CUR_HTH_MASK                             0xFFFF
#define PMIC_FG_CUR_HTH_SHIFT                            0
#define PMIC_FG_CIC2_MASK                                0xFFFF
#define PMIC_FG_CIC2_SHIFT                               0
#define PMIC_FG_CAR_31_16_MASK                           0xFFFF
#define PMIC_FG_CAR_31_16_SHIFT                          0
#define PMIC_FG_CAR_15_00_MASK                           0xFFFF
#define PMIC_FG_CAR_15_00_SHIFT                          0
#define PMIC_FG_BAT0_LTH_31_16_MASK                      0xFFFF
#define PMIC_FG_BAT0_LTH_31_16_SHIFT                     0
#define PMIC_FG_BAT0_LTH_15_14_MASK                      0x3
#define PMIC_FG_BAT0_LTH_15_14_SHIFT                     14
#define PMIC_FG_BAT0_HTH_31_16_MASK                      0xFFFF
#define PMIC_FG_BAT0_HTH_31_16_SHIFT                     0
#define PMIC_FG_BAT0_HTH_15_14_MASK                      0x3
#define PMIC_FG_BAT0_HTH_15_14_SHIFT                     14
#define PMIC_FG_BAT1_LTH_31_16_MASK                      0xFFFF
#define PMIC_FG_BAT1_LTH_31_16_SHIFT                     0
#define PMIC_FG_BAT1_LTH_15_14_MASK                      0x3
#define PMIC_FG_BAT1_LTH_15_14_SHIFT                     14
#define PMIC_FG_BAT1_HTH_31_16_MASK                      0xFFFF
#define PMIC_FG_BAT1_HTH_31_16_SHIFT                     0
#define PMIC_FG_BAT1_HTH_15_14_MASK                      0x3
#define PMIC_FG_BAT1_HTH_15_14_SHIFT                     14
#define PMIC_FG_NCAR_31_16_MASK                          0xFFFF
#define PMIC_FG_NCAR_31_16_SHIFT                         0
#define PMIC_FG_NCAR_15_00_MASK                          0xFFFF
#define PMIC_FG_NCAR_15_00_SHIFT                         0
#define PMIC_FG_N_CHARGE_LTH_31_16_MASK                  0xFFFF
#define PMIC_FG_N_CHARGE_LTH_31_16_SHIFT                 0
#define PMIC_FG_N_CHARGE_LTH_15_14_MASK                  0x3
#define PMIC_FG_N_CHARGE_LTH_15_14_SHIFT                 14
#define PMIC_FG_IAVG_27_16_MASK                          0xFFF
#define PMIC_FG_IAVG_27_16_SHIFT                         0
#define PMIC_FG_IAVG_VLD_MASK                            0x1
#define PMIC_FG_IAVG_VLD_SHIFT                           15
#define PMIC_FG_IAVG_15_00_MASK                          0xFFFF
#define PMIC_FG_IAVG_15_00_SHIFT                         0
#define PMIC_FG_IAVG_LTH_28_16_MASK                      0x1FFF
#define PMIC_FG_IAVG_LTH_28_16_SHIFT                     0
#define PMIC_FG_IAVG_LTH_15_00_MASK                      0xFFFF
#define PMIC_FG_IAVG_LTH_15_00_SHIFT                     0
#define PMIC_FG_IAVG_HTH_28_16_MASK                      0x1FFF
#define PMIC_FG_IAVG_HTH_28_16_SHIFT                     0
#define PMIC_FG_IAVG_HTH_15_00_MASK                      0xFFFF
#define PMIC_FG_IAVG_HTH_15_00_SHIFT                     0
#define PMIC_FG_NTER_29_16_MASK                          0x3FFF
#define PMIC_FG_NTER_29_16_SHIFT                         0
#define PMIC_FG_NTER_15_00_MASK                          0xFFFF
#define PMIC_FG_NTER_15_00_SHIFT                         0
#define PMIC_FG_TIME_HTH_29_16_MASK                      0x3FFF
#define PMIC_FG_TIME_HTH_29_16_SHIFT                     0
#define PMIC_FG_TIME_HTH_15_00_MASK                      0xFFFF
#define PMIC_FG_TIME_HTH_15_00_SHIFT                     0
#define PMIC_FG_OFFSET_MASK                              0xFFFF
#define PMIC_FG_OFFSET_SHIFT                             0
#define PMIC_FG_ADJUST_OFFSET_VALUE_MASK                 0xFFFF
#define PMIC_FG_ADJUST_OFFSET_VALUE_SHIFT                0
#define PMIC_FG_GAIN_MASK                                0x1FFF
#define PMIC_FG_GAIN_SHIFT                               0
#define PMIC_FG_SON_SLP_CUR_TH_MASK                      0xFFFF
#define PMIC_FG_SON_SLP_CUR_TH_SHIFT                     0
#define PMIC_FG_SON_SLP_TIME_MASK                        0x3FF
#define PMIC_FG_SON_SLP_TIME_SHIFT                       0
#define PMIC_FG_SON_DET_TIME_MASK                        0x3FF
#define PMIC_FG_SON_DET_TIME_SHIFT                       0
#define PMIC_FG_FP_FTIME_MASK                            0xFF
#define PMIC_FG_FP_FTIME_SHIFT                           0
#define PMIC_FG_SOFF_SLP_CUR_TH_MASK                     0xFFFF
#define PMIC_FG_SOFF_SLP_CUR_TH_SHIFT                    0
#define PMIC_FG_SOFF_SLP_TIME_MASK                       0x3FF
#define PMIC_FG_SOFF_SLP_TIME_SHIFT                      0
#define PMIC_FG_SOFF_DET_TIME_MASK                       0x3FF
#define PMIC_FG_SOFF_DET_TIME_SHIFT                      0
#define PMIC_FG_SOFF_TIME_29_16_MASK                     0x3FFF
#define PMIC_FG_SOFF_TIME_29_16_SHIFT                    0
#define PMIC_FG_SOFF_MASK                                0x1
#define PMIC_FG_SOFF_SHIFT                               15
#define PMIC_FG_SOFF_TIME_15_00_MASK                     0xFFFF
#define PMIC_FG_SOFF_TIME_15_00_SHIFT                    0
#define PMIC_FG_PWR_TIME0_MASK                           0xFF
#define PMIC_FG_PWR_TIME0_SHIFT                          0
#define PMIC_FG_PWR_TIME1_MASK                           0xFF
#define PMIC_FG_PWR_TIME1_SHIFT                          8
#define PMIC_FG_PWR_TIME2_MASK                           0xFF
#define PMIC_FG_PWR_TIME2_SHIFT                          0
#define PMIC_FG_ZCV_DET_IV_MASK                          0xF
#define PMIC_FG_ZCV_DET_IV_SHIFT                         0
#define PMIC_FG_ZCV_CAR_TH_30_16_MASK                    0x7FFF
#define PMIC_FG_ZCV_CAR_TH_30_16_SHIFT                   0
#define PMIC_FG_ZCV_CAR_TH_15_00_MASK                    0xFFFF
#define PMIC_FG_ZCV_CAR_TH_15_00_SHIFT                   0
#define PMIC_FG_ZCV_CAR_31_16_MASK                       0xFFFF
#define PMIC_FG_ZCV_CAR_31_16_SHIFT                      0
#define PMIC_FG_ZCV_CAR_15_00_MASK                       0xFFFF
#define PMIC_FG_ZCV_CAR_15_00_SHIFT                      0
#define PMIC_FG_ZCV_CURR_MASK                            0xFFFF
#define PMIC_FG_ZCV_CURR_SHIFT                           0
#define PMIC_RG_FGANALOGTEST_3_1_MASK                    0x7
#define PMIC_RG_FGANALOGTEST_3_1_SHIFT                   1
#define PMIC_RG_FGRINTMODE_MASK                          0x1
#define PMIC_RG_FGRINTMODE_SHIFT                         4
#define PMIC_RG_SPARE_MASK                               0xFF
#define PMIC_RG_SPARE_SHIFT                              5
#define PMIC_RG_FG_OFFSET_SWAP_MASK                      0x7
#define PMIC_RG_FG_OFFSET_SWAP_SHIFT                     0
#define PMIC_FG_MODE_MASK                                0x1
#define PMIC_FG_MODE_SHIFT                               0
#define PMIC_FG_RST_SW_MASK                              0x1
#define PMIC_FG_RST_SW_SHIFT                             1
#define PMIC_FG_FGCAL_EN_SW_MASK                         0x1
#define PMIC_FG_FGCAL_EN_SW_SHIFT                        2
#define PMIC_FG_FGADC_EN_SW_MASK                         0x1
#define PMIC_FG_FGADC_EN_SW_SHIFT                        3
#define PMIC_FG_RNG_BIT_MODE_MASK                        0x1
#define PMIC_FG_RNG_BIT_MODE_SHIFT                       4
#define PMIC_FG_RNG_BIT_SW_MASK                          0x1
#define PMIC_FG_RNG_BIT_SW_SHIFT                         5
#define PMIC_FG_RNG_EN_MODE_MASK                         0x1
#define PMIC_FG_RNG_EN_MODE_SHIFT                        6
#define PMIC_FG_RNG_EN_SW_MASK                           0x1
#define PMIC_FG_RNG_EN_SW_SHIFT                          7
#define PMIC_FG_DWA_T0_MASK                              0x3
#define PMIC_FG_DWA_T0_SHIFT                             8
#define PMIC_FG_DWA_T1_MASK                              0x3
#define PMIC_FG_DWA_T1_SHIFT                             10
#define PMIC_FG_DWA_RST_MODE_MASK                        0x1
#define PMIC_FG_DWA_RST_MODE_SHIFT                       12
#define PMIC_FG_DWA_RST_SW_MASK                          0x1
#define PMIC_FG_DWA_RST_SW_SHIFT                         13
#define PMIC_FG_DWA_RST_MASK                             0x1
#define PMIC_FG_DWA_RST_SHIFT                            15
#define PMIC_FG_RSV_CON0_RSV_MASK                        0xFFFF
#define PMIC_FG_RSV_CON0_RSV_SHIFT                       0
#define PMIC_FG_RSV_CON1_RSV_MASK                        0xFFFF
#define PMIC_FG_RSV_CON1_RSV_SHIFT                       0
#define PMIC_FG_RSV_CON2_RSV_MASK                        0xFFFF
#define PMIC_FG_RSV_CON2_RSV_SHIFT                       0
#define PMIC_FG_RSV_CON3_RSV_MASK                        0xFFFF
#define PMIC_FG_RSV_CON3_RSV_SHIFT                       0
#define PMIC_SYSTEM_INFO_CON0_MASK                       0xFFFF
#define PMIC_SYSTEM_INFO_CON0_SHIFT                      0
#define PMIC_SYSTEM_INFO_CON1_MASK                       0xFFFF
#define PMIC_SYSTEM_INFO_CON1_SHIFT                      0
#define PMIC_SYSTEM_INFO_CON2_MASK                       0xFFFF
#define PMIC_SYSTEM_INFO_CON2_SHIFT                      0
#define PMIC_SYSTEM_INFO_CON3_MASK                       0xFFFF
#define PMIC_SYSTEM_INFO_CON3_SHIFT                      0
#define PMIC_SYSTEM_INFO_CON4_MASK                       0xFFFF
#define PMIC_SYSTEM_INFO_CON4_SHIFT                      0
#define PMIC_RG_FGADC_GAINERROR_CAL_MASK                 0x1FFF
#define PMIC_RG_FGADC_GAINERROR_CAL_SHIFT                0
#define PMIC_AUXADC_ADC_OUT_CH0_MASK                     0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH0_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_CH0_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_CH0_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_CH1_MASK                     0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH1_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_CH1_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_CH1_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_CH2_MASK                     0xFFF
#define PMIC_AUXADC_ADC_OUT_CH2_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_CH2_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_CH2_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_CH3_MASK                     0xFFF
#define PMIC_AUXADC_ADC_OUT_CH3_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_CH3_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_CH3_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_CH4_MASK                     0xFFF
#define PMIC_AUXADC_ADC_OUT_CH4_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_CH4_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_CH4_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_CH5_MASK                     0xFFF
#define PMIC_AUXADC_ADC_OUT_CH5_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_CH5_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_CH5_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_CH6_MASK                     0xFFF
#define PMIC_AUXADC_ADC_OUT_CH6_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_CH6_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_CH6_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_CH7_MASK                     0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH7_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_CH7_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_CH7_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_CH8_MASK                     0xFFF
#define PMIC_AUXADC_ADC_OUT_CH8_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_CH8_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_CH8_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_CH9_MASK                     0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH9_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_CH9_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_CH9_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_CH10_MASK                    0xFFF
#define PMIC_AUXADC_ADC_OUT_CH10_SHIFT                   0
#define PMIC_AUXADC_ADC_RDY_CH10_MASK                    0x1
#define PMIC_AUXADC_ADC_RDY_CH10_SHIFT                   15
#define PMIC_AUXADC_ADC_OUT_CH11_MASK                    0xFFF
#define PMIC_AUXADC_ADC_OUT_CH11_SHIFT                   0
#define PMIC_AUXADC_ADC_RDY_CH11_MASK                    0x1
#define PMIC_AUXADC_ADC_RDY_CH11_SHIFT                   15
#define PMIC_AUXADC_ADC_OUT_CH12_15_MASK                 0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH12_15_SHIFT                0
#define PMIC_AUXADC_ADC_RDY_CH12_15_MASK                 0x1
#define PMIC_AUXADC_ADC_RDY_CH12_15_SHIFT                15
#define PMIC_AUXADC_ADC_OUT_THR_HW_MASK                  0xFFF
#define PMIC_AUXADC_ADC_OUT_THR_HW_SHIFT                 0
#define PMIC_AUXADC_ADC_RDY_THR_HW_MASK                  0x1
#define PMIC_AUXADC_ADC_RDY_THR_HW_SHIFT                 15
#define PMIC_AUXADC_ADC_OUT_LBAT_MASK                    0xFFF
#define PMIC_AUXADC_ADC_OUT_LBAT_SHIFT                   0
#define PMIC_AUXADC_ADC_RDY_LBAT_MASK                    0x1
#define PMIC_AUXADC_ADC_RDY_LBAT_SHIFT                   15
#define PMIC_AUXADC_ADC_OUT_LBAT2_MASK                   0xFFF
#define PMIC_AUXADC_ADC_OUT_LBAT2_SHIFT                  0
#define PMIC_AUXADC_ADC_RDY_LBAT2_MASK                   0x1
#define PMIC_AUXADC_ADC_RDY_LBAT2_SHIFT                  15
#define PMIC_AUXADC_ADC_OUT_CH7_BY_GPS_MASK              0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH7_BY_GPS_SHIFT             0
#define PMIC_AUXADC_ADC_RDY_CH7_BY_GPS_MASK              0x1
#define PMIC_AUXADC_ADC_RDY_CH7_BY_GPS_SHIFT             15
#define PMIC_AUXADC_ADC_OUT_CH7_BY_MD_MASK               0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH7_BY_MD_SHIFT              0
#define PMIC_AUXADC_ADC_RDY_CH7_BY_MD_MASK               0x1
#define PMIC_AUXADC_ADC_RDY_CH7_BY_MD_SHIFT              15
#define PMIC_AUXADC_ADC_OUT_CH7_BY_AP_MASK               0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH7_BY_AP_SHIFT              0
#define PMIC_AUXADC_ADC_RDY_CH7_BY_AP_MASK               0x1
#define PMIC_AUXADC_ADC_RDY_CH7_BY_AP_SHIFT              15
#define PMIC_AUXADC_ADC_OUT_CH4_BY_MD_MASK               0xFFF
#define PMIC_AUXADC_ADC_OUT_CH4_BY_MD_SHIFT              0
#define PMIC_AUXADC_ADC_RDY_CH4_BY_MD_MASK               0x1
#define PMIC_AUXADC_ADC_RDY_CH4_BY_MD_SHIFT              15
#define PMIC_AUXADC_ADC_OUT_PWRON_PCHR_MASK              0x7FFF
#define PMIC_AUXADC_ADC_OUT_PWRON_PCHR_SHIFT             0
#define PMIC_AUXADC_ADC_RDY_PWRON_PCHR_MASK              0x1
#define PMIC_AUXADC_ADC_RDY_PWRON_PCHR_SHIFT             15
#define PMIC_AUXADC_ADC_OUT_PWRON_SWCHR_MASK             0x7FFF
#define PMIC_AUXADC_ADC_OUT_PWRON_SWCHR_SHIFT            0
#define PMIC_AUXADC_ADC_RDY_PWRON_SWCHR_MASK             0x1
#define PMIC_AUXADC_ADC_RDY_PWRON_SWCHR_SHIFT            15
#define PMIC_AUXADC_ADC_OUT_WAKEUP_PCHR_MASK             0x7FFF
#define PMIC_AUXADC_ADC_OUT_WAKEUP_PCHR_SHIFT            0
#define PMIC_AUXADC_ADC_RDY_WAKEUP_PCHR_MASK             0x1
#define PMIC_AUXADC_ADC_RDY_WAKEUP_PCHR_SHIFT            15
#define PMIC_AUXADC_ADC_OUT_WAKEUP_SWCHR_MASK            0x7FFF
#define PMIC_AUXADC_ADC_OUT_WAKEUP_SWCHR_SHIFT           0
#define PMIC_AUXADC_ADC_RDY_WAKEUP_SWCHR_MASK            0x1
#define PMIC_AUXADC_ADC_RDY_WAKEUP_SWCHR_SHIFT           15
#define PMIC_AUXADC_ADC_OUT_CH0_BY_MD_MASK               0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH0_BY_MD_SHIFT              0
#define PMIC_AUXADC_ADC_RDY_CH0_BY_MD_MASK               0x1
#define PMIC_AUXADC_ADC_RDY_CH0_BY_MD_SHIFT              15
#define PMIC_AUXADC_ADC_OUT_CH0_BY_AP_MASK               0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH0_BY_AP_SHIFT              0
#define PMIC_AUXADC_ADC_RDY_CH0_BY_AP_MASK               0x1
#define PMIC_AUXADC_ADC_RDY_CH0_BY_AP_SHIFT              15
#define PMIC_AUXADC_ADC_OUT_CH1_BY_MD_MASK               0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH1_BY_MD_SHIFT              0
#define PMIC_AUXADC_ADC_RDY_CH1_BY_MD_MASK               0x1
#define PMIC_AUXADC_ADC_RDY_CH1_BY_MD_SHIFT              15
#define PMIC_AUXADC_ADC_OUT_CH1_BY_AP_MASK               0x7FFF
#define PMIC_AUXADC_ADC_OUT_CH1_BY_AP_SHIFT              0
#define PMIC_AUXADC_ADC_RDY_CH1_BY_AP_MASK               0x1
#define PMIC_AUXADC_ADC_RDY_CH1_BY_AP_SHIFT              15
#define PMIC_AUXADC_ADC_OUT_BAT_TEMP_MASK                0xFFF
#define PMIC_AUXADC_ADC_OUT_BAT_TEMP_SHIFT               0
#define PMIC_AUXADC_ADC_RDY_BAT_TEMP_MASK                0x1
#define PMIC_AUXADC_ADC_RDY_BAT_TEMP_SHIFT               15
#define PMIC_AUXADC_ADC_OUT_FGADC_PCHR_MASK              0x7FFF
#define PMIC_AUXADC_ADC_OUT_FGADC_PCHR_SHIFT             0
#define PMIC_AUXADC_ADC_RDY_FGADC_PCHR_MASK              0x1
#define PMIC_AUXADC_ADC_RDY_FGADC_PCHR_SHIFT             15
#define PMIC_AUXADC_ADC_OUT_FGADC_SWCHR_MASK             0x7FFF
#define PMIC_AUXADC_ADC_OUT_FGADC_SWCHR_SHIFT            0
#define PMIC_AUXADC_ADC_RDY_FGADC_SWCHR_MASK             0x1
#define PMIC_AUXADC_ADC_RDY_FGADC_SWCHR_SHIFT            15
#define PMIC_AUXADC_ADC_OUT_BAT_PLUGIN_PCHR_MASK         0x7FFF
#define PMIC_AUXADC_ADC_OUT_BAT_PLUGIN_PCHR_SHIFT        0
#define PMIC_AUXADC_ADC_RDY_BAT_PLUGIN_PCHR_MASK         0x1
#define PMIC_AUXADC_ADC_RDY_BAT_PLUGIN_PCHR_SHIFT        15
#define PMIC_AUXADC_ADC_OUT_BAT_PLUGIN_SWCHR_MASK        0x7FFF
#define PMIC_AUXADC_ADC_OUT_BAT_PLUGIN_SWCHR_SHIFT       0
#define PMIC_AUXADC_ADC_RDY_BAT_PLUGIN_SWCHR_MASK        0x1
#define PMIC_AUXADC_ADC_RDY_BAT_PLUGIN_SWCHR_SHIFT       15
#define PMIC_AUXADC_ADC_OUT_IMP_MASK                     0x7FFF
#define PMIC_AUXADC_ADC_OUT_IMP_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_IMP_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_IMP_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_IMP_AVG_MASK                 0x7FFF
#define PMIC_AUXADC_ADC_OUT_IMP_AVG_SHIFT                0
#define PMIC_AUXADC_ADC_RDY_IMP_AVG_MASK                 0x1
#define PMIC_AUXADC_ADC_RDY_IMP_AVG_SHIFT                15
#define PMIC_AUXADC_ADC_OUT_RAW_MASK                     0x7FFF
#define PMIC_AUXADC_ADC_OUT_RAW_SHIFT                    0
#define PMIC_AUXADC_ADC_OUT_MDRT_MASK                    0x7FFF
#define PMIC_AUXADC_ADC_OUT_MDRT_SHIFT                   0
#define PMIC_AUXADC_ADC_RDY_MDRT_MASK                    0x1
#define PMIC_AUXADC_ADC_RDY_MDRT_SHIFT                   15
#define PMIC_AUXADC_ADC_OUT_MDBG_MASK                    0x7FFF
#define PMIC_AUXADC_ADC_OUT_MDBG_SHIFT                   0
#define PMIC_AUXADC_ADC_RDY_MDBG_MASK                    0x1
#define PMIC_AUXADC_ADC_RDY_MDBG_SHIFT                   15
#define PMIC_AUXADC_ADC_OUT_JEITA_MASK                   0xFFF
#define PMIC_AUXADC_ADC_OUT_JEITA_SHIFT                  0
#define PMIC_AUXADC_ADC_RDY_JEITA_MASK                   0x1
#define PMIC_AUXADC_ADC_RDY_JEITA_SHIFT                  15
#define PMIC_AUXADC_ADC_OUT_DCXO_BY_GPS_MASK             0x7FFF
#define PMIC_AUXADC_ADC_OUT_DCXO_BY_GPS_SHIFT            0
#define PMIC_AUXADC_ADC_RDY_DCXO_BY_GPS_MASK             0x1
#define PMIC_AUXADC_ADC_RDY_DCXO_BY_GPS_SHIFT            15
#define PMIC_AUXADC_ADC_OUT_DCXO_BY_MD_MASK              0x7FFF
#define PMIC_AUXADC_ADC_OUT_DCXO_BY_MD_SHIFT             0
#define PMIC_AUXADC_ADC_RDY_DCXO_BY_MD_MASK              0x1
#define PMIC_AUXADC_ADC_RDY_DCXO_BY_MD_SHIFT             15
#define PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_MASK              0x7FFF
#define PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_SHIFT             0
#define PMIC_AUXADC_ADC_RDY_DCXO_BY_AP_MASK              0x1
#define PMIC_AUXADC_ADC_RDY_DCXO_BY_AP_SHIFT             15
#define PMIC_AUXADC_ADC_OUT_DCXO_MDRT_MASK               0x7FFF
#define PMIC_AUXADC_ADC_OUT_DCXO_MDRT_SHIFT              0
#define PMIC_AUXADC_ADC_RDY_DCXO_MDRT_MASK               0x1
#define PMIC_AUXADC_ADC_RDY_DCXO_MDRT_SHIFT              15
#define PMIC_AUXADC_ADC_OUT_NAG_MASK                     0x7FFF
#define PMIC_AUXADC_ADC_OUT_NAG_SHIFT                    0
#define PMIC_AUXADC_ADC_RDY_NAG_MASK                     0x1
#define PMIC_AUXADC_ADC_RDY_NAG_SHIFT                    15
#define PMIC_AUXADC_ADC_OUT_BATID_MASK                   0xFFF
#define PMIC_AUXADC_ADC_OUT_BATID_SHIFT                  0
#define PMIC_AUXADC_ADC_RDY_BATID_MASK                   0x1
#define PMIC_AUXADC_ADC_RDY_BATID_SHIFT                  15
#define PMIC_AUXADC_BUF_OUT_00_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_00_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_00_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_00_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_01_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_01_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_01_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_01_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_02_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_02_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_02_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_02_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_03_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_03_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_03_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_03_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_04_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_04_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_04_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_04_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_05_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_05_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_05_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_05_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_06_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_06_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_06_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_06_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_07_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_07_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_07_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_07_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_08_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_08_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_08_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_08_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_09_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_09_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_09_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_09_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_10_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_10_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_10_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_10_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_11_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_11_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_11_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_11_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_12_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_12_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_12_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_12_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_13_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_13_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_13_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_13_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_14_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_14_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_14_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_14_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_15_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_15_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_15_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_15_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_16_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_16_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_16_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_16_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_17_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_17_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_17_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_17_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_18_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_18_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_18_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_18_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_19_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_19_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_19_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_19_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_20_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_20_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_20_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_20_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_21_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_21_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_21_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_21_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_22_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_22_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_22_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_22_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_23_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_23_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_23_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_23_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_24_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_24_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_24_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_24_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_25_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_25_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_25_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_25_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_26_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_26_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_26_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_26_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_27_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_27_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_27_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_27_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_28_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_28_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_28_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_28_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_29_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_29_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_29_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_29_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_30_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_30_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_30_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_30_SHIFT                     15
#define PMIC_AUXADC_BUF_OUT_31_MASK                      0x7FFF
#define PMIC_AUXADC_BUF_OUT_31_SHIFT                     0
#define PMIC_AUXADC_BUF_RDY_31_MASK                      0x1
#define PMIC_AUXADC_BUF_RDY_31_SHIFT                     15
#define PMIC_AUXADC_ADC_BUSY_IN_MASK                     0xFFF
#define PMIC_AUXADC_ADC_BUSY_IN_SHIFT                    0
#define PMIC_AUXADC_ADC_BUSY_IN_LBAT_MASK                0x1
#define PMIC_AUXADC_ADC_BUSY_IN_LBAT_SHIFT               12
#define PMIC_AUXADC_ADC_BUSY_IN_LBAT2_MASK               0x1
#define PMIC_AUXADC_ADC_BUSY_IN_LBAT2_SHIFT              13
#define PMIC_AUXADC_ADC_BUSY_IN_BAT_TEMP_MASK            0x1
#define PMIC_AUXADC_ADC_BUSY_IN_BAT_TEMP_SHIFT           14
#define PMIC_AUXADC_ADC_BUSY_IN_WAKEUP_MASK              0x1
#define PMIC_AUXADC_ADC_BUSY_IN_WAKEUP_SHIFT             15
#define PMIC_AUXADC_ADC_BUSY_IN_DCXO_MDRT_MASK           0x1
#define PMIC_AUXADC_ADC_BUSY_IN_DCXO_MDRT_SHIFT          0
#define PMIC_AUXADC_ADC_BUSY_IN_DCXO_GPS_AP_MASK         0x1
#define PMIC_AUXADC_ADC_BUSY_IN_DCXO_GPS_AP_SHIFT        1
#define PMIC_AUXADC_ADC_BUSY_IN_DCXO_GPS_MD_MASK         0x1
#define PMIC_AUXADC_ADC_BUSY_IN_DCXO_GPS_MD_SHIFT        2
#define PMIC_AUXADC_ADC_BUSY_IN_DCXO_GPS_MASK            0x1
#define PMIC_AUXADC_ADC_BUSY_IN_DCXO_GPS_SHIFT           3
#define PMIC_AUXADC_ADC_BUSY_IN_JEITA_MASK               0x1
#define PMIC_AUXADC_ADC_BUSY_IN_JEITA_SHIFT              4
#define PMIC_AUXADC_ADC_BUSY_IN_MDRT_MASK                0x1
#define PMIC_AUXADC_ADC_BUSY_IN_MDRT_SHIFT               5
#define PMIC_AUXADC_ADC_BUSY_IN_MDBG_MASK                0x1
#define PMIC_AUXADC_ADC_BUSY_IN_MDBG_SHIFT               6
#define PMIC_AUXADC_ADC_BUSY_IN_SHARE_MASK               0x1
#define PMIC_AUXADC_ADC_BUSY_IN_SHARE_SHIFT              7
#define PMIC_AUXADC_ADC_BUSY_IN_IMP_MASK                 0x1
#define PMIC_AUXADC_ADC_BUSY_IN_IMP_SHIFT                8
#define PMIC_AUXADC_ADC_BUSY_IN_FGADC_PCHR_MASK          0x1
#define PMIC_AUXADC_ADC_BUSY_IN_FGADC_PCHR_SHIFT         9
#define PMIC_AUXADC_ADC_BUSY_IN_FGADC_SWCHR_MASK         0x1
#define PMIC_AUXADC_ADC_BUSY_IN_FGADC_SWCHR_SHIFT        10
#define PMIC_AUXADC_ADC_BUSY_IN_GPS_AP_MASK              0x1
#define PMIC_AUXADC_ADC_BUSY_IN_GPS_AP_SHIFT             11
#define PMIC_AUXADC_ADC_BUSY_IN_GPS_MD_MASK              0x1
#define PMIC_AUXADC_ADC_BUSY_IN_GPS_MD_SHIFT             12
#define PMIC_AUXADC_ADC_BUSY_IN_GPS_MASK                 0x1
#define PMIC_AUXADC_ADC_BUSY_IN_GPS_SHIFT                13
#define PMIC_AUXADC_ADC_BUSY_IN_THR_HW_MASK              0x1
#define PMIC_AUXADC_ADC_BUSY_IN_THR_HW_SHIFT             14
#define PMIC_AUXADC_ADC_BUSY_IN_THR_MD_MASK              0x1
#define PMIC_AUXADC_ADC_BUSY_IN_THR_MD_SHIFT             15
#define PMIC_AUXADC_ADC_BUSY_IN_BAT_PLUGIN_PCHR_MASK     0x1
#define PMIC_AUXADC_ADC_BUSY_IN_BAT_PLUGIN_PCHR_SHIFT    0
#define PMIC_AUXADC_ADC_BUSY_IN_BAT_PLUGIN_SWCHR_MASK    0x1
#define PMIC_AUXADC_ADC_BUSY_IN_BAT_PLUGIN_SWCHR_SHIFT   1
#define PMIC_AUXADC_ADC_BUSY_IN_BATID_MASK               0x1
#define PMIC_AUXADC_ADC_BUSY_IN_BATID_SHIFT              2
#define PMIC_AUXADC_ADC_BUSY_IN_PWRON_MASK               0x1
#define PMIC_AUXADC_ADC_BUSY_IN_PWRON_SHIFT              3
#define PMIC_AUXADC_ADC_BUSY_IN_NAG_MASK                 0x1
#define PMIC_AUXADC_ADC_BUSY_IN_NAG_SHIFT                15
#define PMIC_AUXADC_RQST_CH0_MASK                        0x1
#define PMIC_AUXADC_RQST_CH0_SHIFT                       0
#define PMIC_AUXADC_RQST_CH1_MASK                        0x1
#define PMIC_AUXADC_RQST_CH1_SHIFT                       1
#define PMIC_AUXADC_RQST_CH2_MASK                        0x1
#define PMIC_AUXADC_RQST_CH2_SHIFT                       2
#define PMIC_AUXADC_RQST_CH3_MASK                        0x1
#define PMIC_AUXADC_RQST_CH3_SHIFT                       3
#define PMIC_AUXADC_RQST_CH4_MASK                        0x1
#define PMIC_AUXADC_RQST_CH4_SHIFT                       4
#define PMIC_AUXADC_RQST_CH5_MASK                        0x1
#define PMIC_AUXADC_RQST_CH5_SHIFT                       5
#define PMIC_AUXADC_RQST_CH6_MASK                        0x1
#define PMIC_AUXADC_RQST_CH6_SHIFT                       6
#define PMIC_AUXADC_RQST_CH7_MASK                        0x1
#define PMIC_AUXADC_RQST_CH7_SHIFT                       7
#define PMIC_AUXADC_RQST_CH8_MASK                        0x1
#define PMIC_AUXADC_RQST_CH8_SHIFT                       8
#define PMIC_AUXADC_RQST_CH9_MASK                        0x1
#define PMIC_AUXADC_RQST_CH9_SHIFT                       9
#define PMIC_AUXADC_RQST_CH10_MASK                       0x1
#define PMIC_AUXADC_RQST_CH10_SHIFT                      10
#define PMIC_AUXADC_RQST_CH11_MASK                       0x1
#define PMIC_AUXADC_RQST_CH11_SHIFT                      11
#define PMIC_AUXADC_RQST_CH12_MASK                       0x1
#define PMIC_AUXADC_RQST_CH12_SHIFT                      12
#define PMIC_AUXADC_RQST_CH13_MASK                       0x1
#define PMIC_AUXADC_RQST_CH13_SHIFT                      13
#define PMIC_AUXADC_RQST_CH14_MASK                       0x1
#define PMIC_AUXADC_RQST_CH14_SHIFT                      14
#define PMIC_AUXADC_RQST_CH15_MASK                       0x1
#define PMIC_AUXADC_RQST_CH15_SHIFT                      15
#define PMIC_AUXADC_RQST0_SET_MASK                       0xFFFF
#define PMIC_AUXADC_RQST0_SET_SHIFT                      0
#define PMIC_AUXADC_RQST0_CLR_MASK                       0xFFFF
#define PMIC_AUXADC_RQST0_CLR_SHIFT                      0
#define PMIC_AUXADC_RQST_CH0_BY_MD_MASK                  0x1
#define PMIC_AUXADC_RQST_CH0_BY_MD_SHIFT                 0
#define PMIC_AUXADC_RQST_CH1_BY_MD_MASK                  0x1
#define PMIC_AUXADC_RQST_CH1_BY_MD_SHIFT                 1
#define PMIC_AUXADC_RQST_RSV0_MASK                       0x1
#define PMIC_AUXADC_RQST_RSV0_SHIFT                      2
#define PMIC_AUXADC_RQST_BATID_MASK                      0x1
#define PMIC_AUXADC_RQST_BATID_SHIFT                     3
#define PMIC_AUXADC_RQST_CH4_BY_MD_MASK                  0x1
#define PMIC_AUXADC_RQST_CH4_BY_MD_SHIFT                 4
#define PMIC_AUXADC_RQST_CH7_BY_MD_MASK                  0x1
#define PMIC_AUXADC_RQST_CH7_BY_MD_SHIFT                 7
#define PMIC_AUXADC_RQST_CH7_BY_GPS_MASK                 0x1
#define PMIC_AUXADC_RQST_CH7_BY_GPS_SHIFT                8
#define PMIC_AUXADC_RQST_DCXO_BY_MD_MASK                 0x1
#define PMIC_AUXADC_RQST_DCXO_BY_MD_SHIFT                9
#define PMIC_AUXADC_RQST_DCXO_BY_GPS_MASK                0x1
#define PMIC_AUXADC_RQST_DCXO_BY_GPS_SHIFT               10
#define PMIC_AUXADC_RQST_RSV1_MASK                       0x1F
#define PMIC_AUXADC_RQST_RSV1_SHIFT                      11
#define PMIC_AUXADC_RQST1_SET_MASK                       0xFFFF
#define PMIC_AUXADC_RQST1_SET_SHIFT                      0
#define PMIC_AUXADC_RQST1_CLR_MASK                       0xFFFF
#define PMIC_AUXADC_RQST1_CLR_SHIFT                      0
#define PMIC_AUXADC_CK_ON_EXTD_MASK                      0x3F
#define PMIC_AUXADC_CK_ON_EXTD_SHIFT                     0
#define PMIC_AUXADC_SRCLKEN_SRC_SEL_MASK                 0x3
#define PMIC_AUXADC_SRCLKEN_SRC_SEL_SHIFT                6
#define PMIC_AUXADC_ADC_PWDB_MASK                        0x1
#define PMIC_AUXADC_ADC_PWDB_SHIFT                       8
#define PMIC_AUXADC_ADC_PWDB_SWCTRL_MASK                 0x1
#define PMIC_AUXADC_ADC_PWDB_SWCTRL_SHIFT                9
#define PMIC_AUXADC_STRUP_CK_ON_ENB_MASK                 0x1
#define PMIC_AUXADC_STRUP_CK_ON_ENB_SHIFT                10
#define PMIC_AUXADC_SRCLKEN_CK_EN_MASK                   0x1
#define PMIC_AUXADC_SRCLKEN_CK_EN_SHIFT                  12
#define PMIC_AUXADC_CK_AON_GPS_MASK                      0x1
#define PMIC_AUXADC_CK_AON_GPS_SHIFT                     13
#define PMIC_AUXADC_CK_AON_MD_MASK                       0x1
#define PMIC_AUXADC_CK_AON_MD_SHIFT                      14
#define PMIC_AUXADC_CK_AON_MASK                          0x1
#define PMIC_AUXADC_CK_AON_SHIFT                         15
#define PMIC_AUXADC_CON0_SET_MASK                        0xFFFF
#define PMIC_AUXADC_CON0_SET_SHIFT                       0
#define PMIC_AUXADC_CON0_CLR_MASK                        0xFFFF
#define PMIC_AUXADC_CON0_CLR_SHIFT                       0
#define PMIC_AUXADC_AVG_NUM_SMALL_MASK                   0x7
#define PMIC_AUXADC_AVG_NUM_SMALL_SHIFT                  0
#define PMIC_AUXADC_AVG_NUM_LARGE_MASK                   0x7
#define PMIC_AUXADC_AVG_NUM_LARGE_SHIFT                  3
#define PMIC_AUXADC_SPL_NUM_MASK                         0x3FF
#define PMIC_AUXADC_SPL_NUM_SHIFT                        6
#define PMIC_AUXADC_AVG_NUM_SEL_MASK                     0xFFF
#define PMIC_AUXADC_AVG_NUM_SEL_SHIFT                    0
#define PMIC_AUXADC_AVG_NUM_SEL_SHARE_MASK               0x1
#define PMIC_AUXADC_AVG_NUM_SEL_SHARE_SHIFT              12
#define PMIC_AUXADC_AVG_NUM_SEL_LBAT_MASK                0x1
#define PMIC_AUXADC_AVG_NUM_SEL_LBAT_SHIFT               13
#define PMIC_AUXADC_AVG_NUM_SEL_BAT_TEMP_MASK            0x1
#define PMIC_AUXADC_AVG_NUM_SEL_BAT_TEMP_SHIFT           14
#define PMIC_AUXADC_AVG_NUM_SEL_WAKEUP_MASK              0x1
#define PMIC_AUXADC_AVG_NUM_SEL_WAKEUP_SHIFT             15
#define PMIC_AUXADC_SPL_NUM_LARGE_MASK                   0x3FF
#define PMIC_AUXADC_SPL_NUM_LARGE_SHIFT                  0
#define PMIC_AUXADC_SPL_NUM_SLEEP_MASK                   0x3FF
#define PMIC_AUXADC_SPL_NUM_SLEEP_SHIFT                  0
#define PMIC_AUXADC_SPL_NUM_SLEEP_SEL_MASK               0x1
#define PMIC_AUXADC_SPL_NUM_SLEEP_SEL_SHIFT              15
#define PMIC_AUXADC_SPL_NUM_SEL_MASK                     0xFFF
#define PMIC_AUXADC_SPL_NUM_SEL_SHIFT                    0
#define PMIC_AUXADC_SPL_NUM_SEL_SHARE_MASK               0x1
#define PMIC_AUXADC_SPL_NUM_SEL_SHARE_SHIFT              12
#define PMIC_AUXADC_SPL_NUM_SEL_LBAT_MASK                0x1
#define PMIC_AUXADC_SPL_NUM_SEL_LBAT_SHIFT               13
#define PMIC_AUXADC_SPL_NUM_SEL_BAT_TEMP_MASK            0x1
#define PMIC_AUXADC_SPL_NUM_SEL_BAT_TEMP_SHIFT           14
#define PMIC_AUXADC_SPL_NUM_SEL_WAKEUP_MASK              0x1
#define PMIC_AUXADC_SPL_NUM_SEL_WAKEUP_SHIFT             15
#define PMIC_AUXADC_SPL_NUM_CH0_MASK                     0x3FF
#define PMIC_AUXADC_SPL_NUM_CH0_SHIFT                    0
#define PMIC_AUXADC_SPL_NUM_CH3_MASK                     0x3FF
#define PMIC_AUXADC_SPL_NUM_CH3_SHIFT                    0
#define PMIC_AUXADC_SPL_NUM_CH7_MASK                     0x3FF
#define PMIC_AUXADC_SPL_NUM_CH7_SHIFT                    0
#define PMIC_AUXADC_AVG_NUM_LBAT_MASK                    0x7
#define PMIC_AUXADC_AVG_NUM_LBAT_SHIFT                   0
#define PMIC_AUXADC_AVG_NUM_CH7_MASK                     0x7
#define PMIC_AUXADC_AVG_NUM_CH7_SHIFT                    4
#define PMIC_AUXADC_AVG_NUM_CH3_MASK                     0x7
#define PMIC_AUXADC_AVG_NUM_CH3_SHIFT                    8
#define PMIC_AUXADC_AVG_NUM_CH0_MASK                     0x7
#define PMIC_AUXADC_AVG_NUM_CH0_SHIFT                    12
#define PMIC_AUXADC_AVG_NUM_HPC_MASK                     0x7
#define PMIC_AUXADC_AVG_NUM_HPC_SHIFT                    0
#define PMIC_AUXADC_AVG_NUM_DCXO_MASK                    0x7
#define PMIC_AUXADC_AVG_NUM_DCXO_SHIFT                   4
#define PMIC_AUXADC_TRIM_CH0_SEL_MASK                    0x3
#define PMIC_AUXADC_TRIM_CH0_SEL_SHIFT                   0
#define PMIC_AUXADC_TRIM_CH1_SEL_MASK                    0x3
#define PMIC_AUXADC_TRIM_CH1_SEL_SHIFT                   2
#define PMIC_AUXADC_TRIM_CH2_SEL_MASK                    0x3
#define PMIC_AUXADC_TRIM_CH2_SEL_SHIFT                   4
#define PMIC_AUXADC_TRIM_CH3_SEL_MASK                    0x3
#define PMIC_AUXADC_TRIM_CH3_SEL_SHIFT                   6
#define PMIC_AUXADC_TRIM_CH4_SEL_MASK                    0x3
#define PMIC_AUXADC_TRIM_CH4_SEL_SHIFT                   8
#define PMIC_AUXADC_TRIM_CH5_SEL_MASK                    0x3
#define PMIC_AUXADC_TRIM_CH5_SEL_SHIFT                   10
#define PMIC_AUXADC_TRIM_CH6_SEL_MASK                    0x3
#define PMIC_AUXADC_TRIM_CH6_SEL_SHIFT                   12
#define PMIC_AUXADC_TRIM_CH7_SEL_MASK                    0x3
#define PMIC_AUXADC_TRIM_CH7_SEL_SHIFT                   14
#define PMIC_AUXADC_TRIM_CH8_SEL_MASK                    0x3
#define PMIC_AUXADC_TRIM_CH8_SEL_SHIFT                   0
#define PMIC_AUXADC_TRIM_CH9_SEL_MASK                    0x3
#define PMIC_AUXADC_TRIM_CH9_SEL_SHIFT                   2
#define PMIC_AUXADC_TRIM_CH10_SEL_MASK                   0x3
#define PMIC_AUXADC_TRIM_CH10_SEL_SHIFT                  4
#define PMIC_AUXADC_TRIM_CH11_SEL_MASK                   0x3
#define PMIC_AUXADC_TRIM_CH11_SEL_SHIFT                  6
#define PMIC_AUXADC_ADC_2S_COMP_ENB_MASK                 0x1
#define PMIC_AUXADC_ADC_2S_COMP_ENB_SHIFT                14
#define PMIC_AUXADC_ADC_TRIM_COMP_MASK                   0x1
#define PMIC_AUXADC_ADC_TRIM_COMP_SHIFT                  15
#define PMIC_AUXADC_SW_GAIN_TRIM_MASK                    0x7FFF
#define PMIC_AUXADC_SW_GAIN_TRIM_SHIFT                   0
#define PMIC_AUXADC_SW_OFFSET_TRIM_MASK                  0x7FFF
#define PMIC_AUXADC_SW_OFFSET_TRIM_SHIFT                 0
#define PMIC_AUXADC_RNG_EN_MASK                          0x1
#define PMIC_AUXADC_RNG_EN_SHIFT                         0
#define PMIC_AUXADC_TEST_MODE_MASK                       0x1
#define PMIC_AUXADC_TEST_MODE_SHIFT                      3
#define PMIC_AUXADC_BIT_SEL_MASK                         0x1
#define PMIC_AUXADC_BIT_SEL_SHIFT                        4
#define PMIC_AUXADC_START_SW_MASK                        0x1
#define PMIC_AUXADC_START_SW_SHIFT                       5
#define PMIC_AUXADC_START_SWCTRL_MASK                    0x1
#define PMIC_AUXADC_START_SWCTRL_SHIFT                   6
#define PMIC_AUXADC_TS_VBE_SEL_MASK                      0x1
#define PMIC_AUXADC_TS_VBE_SEL_SHIFT                     7
#define PMIC_AUXADC_TS_VBE_SEL_SWCTRL_MASK               0x1
#define PMIC_AUXADC_TS_VBE_SEL_SWCTRL_SHIFT              8
#define PMIC_AUXADC_VBUF_EN_MASK                         0x1
#define PMIC_AUXADC_VBUF_EN_SHIFT                        9
#define PMIC_AUXADC_VBUF_EN_SWCTRL_MASK                  0x1
#define PMIC_AUXADC_VBUF_EN_SWCTRL_SHIFT                 10
#define PMIC_AUXADC_OUT_SEL_MASK                         0x1
#define PMIC_AUXADC_OUT_SEL_SHIFT                        11
#define PMIC_AUXADC_DA_DAC_MASK                          0xFFF
#define PMIC_AUXADC_DA_DAC_SHIFT                         0
#define PMIC_AUXADC_DA_DAC_SWCTRL_MASK                   0x1
#define PMIC_AUXADC_DA_DAC_SWCTRL_SHIFT                  12
#define PMIC_AD_AUXADC_COMP_MASK                         0x1
#define PMIC_AD_AUXADC_COMP_SHIFT                        15
#define PMIC_RG_AUXADC_CALI_MASK                         0xF
#define PMIC_RG_AUXADC_CALI_SHIFT                        0
#define PMIC_RG_AUX_RSV_MASK                             0xF
#define PMIC_RG_AUX_RSV_SHIFT                            4
#define PMIC_RG_VBUF_BYP_MASK                            0x1
#define PMIC_RG_VBUF_BYP_SHIFT                           8
#define PMIC_RG_VBUF_CALEN_MASK                          0x1
#define PMIC_RG_VBUF_CALEN_SHIFT                         9
#define PMIC_RG_VBUF_EXTEN_MASK                          0x1
#define PMIC_RG_VBUF_EXTEN_SHIFT                         10
#define PMIC_AUXADC_ADCIN_VSEN_EN_MASK                   0x1
#define PMIC_AUXADC_ADCIN_VSEN_EN_SHIFT                  0
#define PMIC_AUXADC_ADCIN_VBAT_EN_MASK                   0x1
#define PMIC_AUXADC_ADCIN_VBAT_EN_SHIFT                  1
#define PMIC_AUXADC_ADCIN_VSEN_MUX_EN_MASK               0x1
#define PMIC_AUXADC_ADCIN_VSEN_MUX_EN_SHIFT              2
#define PMIC_AUXADC_ADCIN_VSEN_EXT_BATON_EN_MASK         0x1
#define PMIC_AUXADC_ADCIN_VSEN_EXT_BATON_EN_SHIFT        3
#define PMIC_AUXADC_ADCIN_CHR_EN_MASK                    0x1
#define PMIC_AUXADC_ADCIN_CHR_EN_SHIFT                   4
#define PMIC_AUXADC_ADCIN_BATON_TDET_EN_MASK             0x1
#define PMIC_AUXADC_ADCIN_BATON_TDET_EN_SHIFT            5
#define PMIC_AUXADC_ACCDET_ANASWCTRL_EN_MASK             0x1
#define PMIC_AUXADC_ACCDET_ANASWCTRL_EN_SHIFT            6
#define PMIC_AUXADC_XO_THADC_EN_MASK                     0x1
#define PMIC_AUXADC_XO_THADC_EN_SHIFT                    7
#define PMIC_AUXADC_ADCIN_BATID_SW_EN_MASK               0x1
#define PMIC_AUXADC_ADCIN_BATID_SW_EN_SHIFT              8
#define PMIC_AUXADC_DIG0_RSV0_MASK                       0x3
#define PMIC_AUXADC_DIG0_RSV0_SHIFT                      9
#define PMIC_AUXADC_CHSEL_MASK                           0xF
#define PMIC_AUXADC_CHSEL_SHIFT                          11
#define PMIC_AUXADC_SWCTRL_EN_MASK                       0x1
#define PMIC_AUXADC_SWCTRL_EN_SHIFT                      15
#define PMIC_AUXADC_SOURCE_LBAT_SEL_MASK                 0x1
#define PMIC_AUXADC_SOURCE_LBAT_SEL_SHIFT                0
#define PMIC_AUXADC_SOURCE_LBAT2_SEL_MASK                0x1
#define PMIC_AUXADC_SOURCE_LBAT2_SEL_SHIFT               1
#define PMIC_AUXADC_START_EXTD_MASK                      0x7F
#define PMIC_AUXADC_START_EXTD_SHIFT                     2
#define PMIC_AUXADC_DAC_EXTD_MASK                        0xF
#define PMIC_AUXADC_DAC_EXTD_SHIFT                       11
#define PMIC_AUXADC_DAC_EXTD_EN_MASK                     0x1
#define PMIC_AUXADC_DAC_EXTD_EN_SHIFT                    15
#define PMIC_AUXADC_PMU_THR_PDN_SW_MASK                  0x1
#define PMIC_AUXADC_PMU_THR_PDN_SW_SHIFT                 10
#define PMIC_AUXADC_PMU_THR_PDN_SEL_MASK                 0x1
#define PMIC_AUXADC_PMU_THR_PDN_SEL_SHIFT                11
#define PMIC_AUXADC_PMU_THR_PDN_STATUS_MASK              0x1
#define PMIC_AUXADC_PMU_THR_PDN_STATUS_SHIFT             12
#define PMIC_AUXADC_DIG0_RSV1_MASK                       0x7
#define PMIC_AUXADC_DIG0_RSV1_SHIFT                      13
#define PMIC_AUXADC_START_SHADE_NUM_MASK                 0x3FF
#define PMIC_AUXADC_START_SHADE_NUM_SHIFT                0
#define PMIC_AUXADC_START_SHADE_EN_MASK                  0x1
#define PMIC_AUXADC_START_SHADE_EN_SHIFT                 14
#define PMIC_AUXADC_START_SHADE_SEL_MASK                 0x1
#define PMIC_AUXADC_START_SHADE_SEL_SHIFT                15
#define PMIC_AUXADC_ADC_RDY_WAKEUP_CLR_MASK              0x1
#define PMIC_AUXADC_ADC_RDY_WAKEUP_CLR_SHIFT             0
#define PMIC_AUXADC_ADC_RDY_FGADC_CLR_MASK               0x1
#define PMIC_AUXADC_ADC_RDY_FGADC_CLR_SHIFT              1
#define PMIC_AUXADC_ADC_RDY_BAT_PLUGIN_CLR_MASK          0x1
#define PMIC_AUXADC_ADC_RDY_BAT_PLUGIN_CLR_SHIFT         2
#define PMIC_AUXADC_ADC_RDY_PWRON_CLR_MASK               0x1
#define PMIC_AUXADC_ADC_RDY_PWRON_CLR_SHIFT              3
#define PMIC_AUXADC_DATA_REUSE_SEL_MASK                  0x3
#define PMIC_AUXADC_DATA_REUSE_SEL_SHIFT                 0
#define PMIC_AUXADC_CH0_DATA_REUSE_SEL_MASK              0x3
#define PMIC_AUXADC_CH0_DATA_REUSE_SEL_SHIFT             2
#define PMIC_AUXADC_CH1_DATA_REUSE_SEL_MASK              0x3
#define PMIC_AUXADC_CH1_DATA_REUSE_SEL_SHIFT             4
#define PMIC_AUXADC_DCXO_DATA_REUSE_SEL_MASK             0x3
#define PMIC_AUXADC_DCXO_DATA_REUSE_SEL_SHIFT            6
#define PMIC_AUXADC_DATA_REUSE_EN_MASK                   0x1
#define PMIC_AUXADC_DATA_REUSE_EN_SHIFT                  8
#define PMIC_AUXADC_CH0_DATA_REUSE_EN_MASK               0x1
#define PMIC_AUXADC_CH0_DATA_REUSE_EN_SHIFT              9
#define PMIC_AUXADC_CH1_DATA_REUSE_EN_MASK               0x1
#define PMIC_AUXADC_CH1_DATA_REUSE_EN_SHIFT              10
#define PMIC_AUXADC_DCXO_DATA_REUSE_EN_MASK              0x1
#define PMIC_AUXADC_DCXO_DATA_REUSE_EN_SHIFT             11
#define PMIC_AUXADC_AUTORPT_PRD_MASK                     0x3FF
#define PMIC_AUXADC_AUTORPT_PRD_SHIFT                    0
#define PMIC_AUXADC_AUTORPT_EN_MASK                      0x1
#define PMIC_AUXADC_AUTORPT_EN_SHIFT                     15
#define PMIC_AUXADC_LBAT_DEBT_MAX_MASK                   0xFF
#define PMIC_AUXADC_LBAT_DEBT_MAX_SHIFT                  0
#define PMIC_AUXADC_LBAT_DEBT_MIN_MASK                   0xFF
#define PMIC_AUXADC_LBAT_DEBT_MIN_SHIFT                  8
#define PMIC_AUXADC_LBAT_DET_PRD_15_0_MASK               0xFFFF
#define PMIC_AUXADC_LBAT_DET_PRD_15_0_SHIFT              0
#define PMIC_AUXADC_LBAT_DET_PRD_19_16_MASK              0xF
#define PMIC_AUXADC_LBAT_DET_PRD_19_16_SHIFT             0
#define PMIC_AUXADC_LBAT_VOLT_MAX_MASK                   0xFFF
#define PMIC_AUXADC_LBAT_VOLT_MAX_SHIFT                  0
#define PMIC_AUXADC_LBAT_IRQ_EN_MAX_MASK                 0x1
#define PMIC_AUXADC_LBAT_IRQ_EN_MAX_SHIFT                12
#define PMIC_AUXADC_LBAT_EN_MAX_MASK                     0x1
#define PMIC_AUXADC_LBAT_EN_MAX_SHIFT                    13
#define PMIC_AUXADC_LBAT_MAX_IRQ_B_MASK                  0x1
#define PMIC_AUXADC_LBAT_MAX_IRQ_B_SHIFT                 15
#define PMIC_AUXADC_LBAT_VOLT_MIN_MASK                   0xFFF
#define PMIC_AUXADC_LBAT_VOLT_MIN_SHIFT                  0
#define PMIC_AUXADC_LBAT_IRQ_EN_MIN_MASK                 0x1
#define PMIC_AUXADC_LBAT_IRQ_EN_MIN_SHIFT                12
#define PMIC_AUXADC_LBAT_EN_MIN_MASK                     0x1
#define PMIC_AUXADC_LBAT_EN_MIN_SHIFT                    13
#define PMIC_AUXADC_LBAT_MIN_IRQ_B_MASK                  0x1
#define PMIC_AUXADC_LBAT_MIN_IRQ_B_SHIFT                 15
#define PMIC_AUXADC_LBAT_DEBOUNCE_COUNT_MAX_MASK         0x1FF
#define PMIC_AUXADC_LBAT_DEBOUNCE_COUNT_MAX_SHIFT        0
#define PMIC_AUXADC_LBAT_DEBOUNCE_COUNT_MIN_MASK         0x1FF
#define PMIC_AUXADC_LBAT_DEBOUNCE_COUNT_MIN_SHIFT        0
#define PMIC_AUXADC_ACCDET_AUTO_SPL_MASK                 0x1
#define PMIC_AUXADC_ACCDET_AUTO_SPL_SHIFT                0
#define PMIC_AUXADC_ACCDET_AUTO_RQST_CLR_MASK            0x1
#define PMIC_AUXADC_ACCDET_AUTO_RQST_CLR_SHIFT           1
#define PMIC_AUXADC_ACCDET_DIG1_RSV0_MASK                0x3F
#define PMIC_AUXADC_ACCDET_DIG1_RSV0_SHIFT               2
#define PMIC_AUXADC_ACCDET_DIG0_RSV0_MASK                0xFF
#define PMIC_AUXADC_ACCDET_DIG0_RSV0_SHIFT               8
#define PMIC_AUXADC_THR_DEBT_MAX_MASK                    0xFF
#define PMIC_AUXADC_THR_DEBT_MAX_SHIFT                   0
#define PMIC_AUXADC_THR_DEBT_MIN_MASK                    0xFF
#define PMIC_AUXADC_THR_DEBT_MIN_SHIFT                   8
#define PMIC_AUXADC_THR_DET_PRD_15_0_MASK                0xFFFF
#define PMIC_AUXADC_THR_DET_PRD_15_0_SHIFT               0
#define PMIC_AUXADC_THR_DET_PRD_19_16_MASK               0xF
#define PMIC_AUXADC_THR_DET_PRD_19_16_SHIFT              0
#define PMIC_AUXADC_THR_VOLT_MAX_MASK                    0xFFF
#define PMIC_AUXADC_THR_VOLT_MAX_SHIFT                   0
#define PMIC_AUXADC_THR_IRQ_EN_MAX_MASK                  0x1
#define PMIC_AUXADC_THR_IRQ_EN_MAX_SHIFT                 12
#define PMIC_AUXADC_THR_EN_MAX_MASK                      0x1
#define PMIC_AUXADC_THR_EN_MAX_SHIFT                     13
#define PMIC_AUXADC_THR_MAX_IRQ_B_MASK                   0x1
#define PMIC_AUXADC_THR_MAX_IRQ_B_SHIFT                  15
#define PMIC_AUXADC_THR_VOLT_MIN_MASK                    0xFFF
#define PMIC_AUXADC_THR_VOLT_MIN_SHIFT                   0
#define PMIC_AUXADC_THR_IRQ_EN_MIN_MASK                  0x1
#define PMIC_AUXADC_THR_IRQ_EN_MIN_SHIFT                 12
#define PMIC_AUXADC_THR_EN_MIN_MASK                      0x1
#define PMIC_AUXADC_THR_EN_MIN_SHIFT                     13
#define PMIC_AUXADC_THR_MIN_IRQ_B_MASK                   0x1
#define PMIC_AUXADC_THR_MIN_IRQ_B_SHIFT                  15
#define PMIC_AUXADC_THR_DEBOUNCE_COUNT_MAX_MASK          0x1FF
#define PMIC_AUXADC_THR_DEBOUNCE_COUNT_MAX_SHIFT         0
#define PMIC_AUXADC_THR_DEBOUNCE_COUNT_MIN_MASK          0x1FF
#define PMIC_AUXADC_THR_DEBOUNCE_COUNT_MIN_SHIFT         0
#define PMIC_EFUSE_GAIN_CH4_TRIM_MASK                    0xFFF
#define PMIC_EFUSE_GAIN_CH4_TRIM_SHIFT                   0
#define PMIC_EFUSE_OFFSET_CH4_TRIM_MASK                  0x7FF
#define PMIC_EFUSE_OFFSET_CH4_TRIM_SHIFT                 0
#define PMIC_EFUSE_GAIN_CH0_TRIM_MASK                    0xFFF
#define PMIC_EFUSE_GAIN_CH0_TRIM_SHIFT                   0
#define PMIC_EFUSE_OFFSET_CH0_TRIM_MASK                  0x7FF
#define PMIC_EFUSE_OFFSET_CH0_TRIM_SHIFT                 0
#define PMIC_EFUSE_GAIN_CH7_TRIM_MASK                    0xFFF
#define PMIC_EFUSE_GAIN_CH7_TRIM_SHIFT                   0
#define PMIC_EFUSE_OFFSET_CH7_TRIM_MASK                  0x7FF
#define PMIC_EFUSE_OFFSET_CH7_TRIM_SHIFT                 0
#define PMIC_AUXADC_FGADC_START_SW_MASK                  0x1
#define PMIC_AUXADC_FGADC_START_SW_SHIFT                 0
#define PMIC_AUXADC_FGADC_START_SEL_MASK                 0x1
#define PMIC_AUXADC_FGADC_START_SEL_SHIFT                1
#define PMIC_AUXADC_FGADC_R_SW_MASK                      0x1
#define PMIC_AUXADC_FGADC_R_SW_SHIFT                     2
#define PMIC_AUXADC_FGADC_R_SEL_MASK                     0x1
#define PMIC_AUXADC_FGADC_R_SEL_SHIFT                    3
#define PMIC_AUXADC_BAT_PLUGIN_START_SW_MASK             0x1
#define PMIC_AUXADC_BAT_PLUGIN_START_SW_SHIFT            4
#define PMIC_AUXADC_BAT_PLUGIN_START_SEL_MASK            0x1
#define PMIC_AUXADC_BAT_PLUGIN_START_SEL_SHIFT           5
#define PMIC_AUXADC_DBG_DIG0_RSV2_MASK                   0xF
#define PMIC_AUXADC_DBG_DIG0_RSV2_SHIFT                  6
#define PMIC_AUXADC_DBG_DIG1_RSV2_MASK                   0x3F
#define PMIC_AUXADC_DBG_DIG1_RSV2_SHIFT                  10
#define PMIC_AUXADC_IMPEDANCE_CNT_MASK                   0x3F
#define PMIC_AUXADC_IMPEDANCE_CNT_SHIFT                  0
#define PMIC_AUXADC_IMPEDANCE_CHSEL_MASK                 0x1
#define PMIC_AUXADC_IMPEDANCE_CHSEL_SHIFT                6
#define PMIC_AUXADC_IMPEDANCE_IRQ_CLR_MASK               0x1
#define PMIC_AUXADC_IMPEDANCE_IRQ_CLR_SHIFT              7
#define PMIC_AUXADC_IMPEDANCE_IRQ_STATUS_MASK            0x1
#define PMIC_AUXADC_IMPEDANCE_IRQ_STATUS_SHIFT           8
#define PMIC_AUXADC_CLR_IMP_CNT_STOP_MASK                0x1
#define PMIC_AUXADC_CLR_IMP_CNT_STOP_SHIFT               14
#define PMIC_AUXADC_IMPEDANCE_MODE_MASK                  0x1
#define PMIC_AUXADC_IMPEDANCE_MODE_SHIFT                 15
#define PMIC_AUXADC_IMP_AUTORPT_PRD_MASK                 0x3FF
#define PMIC_AUXADC_IMP_AUTORPT_PRD_SHIFT                0
#define PMIC_AUXADC_IMP_AUTORPT_EN_MASK                  0x1
#define PMIC_AUXADC_IMP_AUTORPT_EN_SHIFT                 15
#define PMIC_AUXADC_BAT_TEMP_FROZE_EN_MASK               0x1
#define PMIC_AUXADC_BAT_TEMP_FROZE_EN_SHIFT              0
#define PMIC_AUXADC_BAT_TEMP_DEBT_MAX_MASK               0xFF
#define PMIC_AUXADC_BAT_TEMP_DEBT_MAX_SHIFT              0
#define PMIC_AUXADC_BAT_TEMP_DEBT_MIN_MASK               0xFF
#define PMIC_AUXADC_BAT_TEMP_DEBT_MIN_SHIFT              8
#define PMIC_AUXADC_BAT_TEMP_DET_PRD_15_0_MASK           0xFFFF
#define PMIC_AUXADC_BAT_TEMP_DET_PRD_15_0_SHIFT          0
#define PMIC_AUXADC_BAT_TEMP_DET_PRD_19_16_MASK          0xF
#define PMIC_AUXADC_BAT_TEMP_DET_PRD_19_16_SHIFT         0
#define PMIC_AUXADC_BAT_TEMP_VOLT_MAX_MASK               0xFFF
#define PMIC_AUXADC_BAT_TEMP_VOLT_MAX_SHIFT              0
#define PMIC_AUXADC_BAT_TEMP_IRQ_EN_MAX_MASK             0x1
#define PMIC_AUXADC_BAT_TEMP_IRQ_EN_MAX_SHIFT            12
#define PMIC_AUXADC_BAT_TEMP_EN_MAX_MASK                 0x1
#define PMIC_AUXADC_BAT_TEMP_EN_MAX_SHIFT                13
#define PMIC_AUXADC_BAT_TEMP_MAX_IRQ_B_MASK              0x1
#define PMIC_AUXADC_BAT_TEMP_MAX_IRQ_B_SHIFT             15
#define PMIC_AUXADC_BAT_TEMP_VOLT_MIN_MASK               0xFFF
#define PMIC_AUXADC_BAT_TEMP_VOLT_MIN_SHIFT              0
#define PMIC_AUXADC_BAT_TEMP_IRQ_EN_MIN_MASK             0x1
#define PMIC_AUXADC_BAT_TEMP_IRQ_EN_MIN_SHIFT            12
#define PMIC_AUXADC_BAT_TEMP_EN_MIN_MASK                 0x1
#define PMIC_AUXADC_BAT_TEMP_EN_MIN_SHIFT                13
#define PMIC_AUXADC_BAT_TEMP_MIN_IRQ_B_MASK              0x1
#define PMIC_AUXADC_BAT_TEMP_MIN_IRQ_B_SHIFT             15
#define PMIC_AUXADC_BAT_TEMP_DEBOUNCE_COUNT_MAX_MASK     0x1FF
#define PMIC_AUXADC_BAT_TEMP_DEBOUNCE_COUNT_MAX_SHIFT    0
#define PMIC_AUXADC_BAT_TEMP_DEBOUNCE_COUNT_MIN_MASK     0x1FF
#define PMIC_AUXADC_BAT_TEMP_DEBOUNCE_COUNT_MIN_SHIFT    0
#define PMIC_AUXADC_LBAT2_DEBT_MAX_MASK                  0xFF
#define PMIC_AUXADC_LBAT2_DEBT_MAX_SHIFT                 0
#define PMIC_AUXADC_LBAT2_DEBT_MIN_MASK                  0xFF
#define PMIC_AUXADC_LBAT2_DEBT_MIN_SHIFT                 8
#define PMIC_AUXADC_LBAT2_DET_PRD_15_0_MASK              0xFFFF
#define PMIC_AUXADC_LBAT2_DET_PRD_15_0_SHIFT             0
#define PMIC_AUXADC_LBAT2_DET_PRD_19_16_MASK             0xF
#define PMIC_AUXADC_LBAT2_DET_PRD_19_16_SHIFT            0
#define PMIC_AUXADC_LBAT2_VOLT_MAX_MASK                  0xFFF
#define PMIC_AUXADC_LBAT2_VOLT_MAX_SHIFT                 0
#define PMIC_AUXADC_LBAT2_IRQ_EN_MAX_MASK                0x1
#define PMIC_AUXADC_LBAT2_IRQ_EN_MAX_SHIFT               12
#define PMIC_AUXADC_LBAT2_EN_MAX_MASK                    0x1
#define PMIC_AUXADC_LBAT2_EN_MAX_SHIFT                   13
#define PMIC_AUXADC_LBAT2_MAX_IRQ_B_MASK                 0x1
#define PMIC_AUXADC_LBAT2_MAX_IRQ_B_SHIFT                15
#define PMIC_AUXADC_LBAT2_VOLT_MIN_MASK                  0xFFF
#define PMIC_AUXADC_LBAT2_VOLT_MIN_SHIFT                 0
#define PMIC_AUXADC_LBAT2_IRQ_EN_MIN_MASK                0x1
#define PMIC_AUXADC_LBAT2_IRQ_EN_MIN_SHIFT               12
#define PMIC_AUXADC_LBAT2_EN_MIN_MASK                    0x1
#define PMIC_AUXADC_LBAT2_EN_MIN_SHIFT                   13
#define PMIC_AUXADC_LBAT2_MIN_IRQ_B_MASK                 0x1
#define PMIC_AUXADC_LBAT2_MIN_IRQ_B_SHIFT                15
#define PMIC_AUXADC_LBAT2_DEBOUNCE_COUNT_MAX_MASK        0x1FF
#define PMIC_AUXADC_LBAT2_DEBOUNCE_COUNT_MAX_SHIFT       0
#define PMIC_AUXADC_LBAT2_DEBOUNCE_COUNT_MIN_MASK        0x1FF
#define PMIC_AUXADC_LBAT2_DEBOUNCE_COUNT_MIN_SHIFT       0
#define PMIC_AUXADC_MDBG_DET_PRD_MASK                    0x3FF
#define PMIC_AUXADC_MDBG_DET_PRD_SHIFT                   0
#define PMIC_AUXADC_MDBG_DET_EN_MASK                     0x1
#define PMIC_AUXADC_MDBG_DET_EN_SHIFT                    15
#define PMIC_AUXADC_MDBG_R_PTR_MASK                      0x3F
#define PMIC_AUXADC_MDBG_R_PTR_SHIFT                     0
#define PMIC_AUXADC_MDBG_W_PTR_MASK                      0x3F
#define PMIC_AUXADC_MDBG_W_PTR_SHIFT                     8
#define PMIC_AUXADC_MDBG_BUF_LENGTH_MASK                 0x3F
#define PMIC_AUXADC_MDBG_BUF_LENGTH_SHIFT                0
#define PMIC_AUXADC_MDRT_DET_PRD_MASK                    0x3FF
#define PMIC_AUXADC_MDRT_DET_PRD_SHIFT                   0
#define PMIC_AUXADC_MDRT_DET_EN_MASK                     0x1
#define PMIC_AUXADC_MDRT_DET_EN_SHIFT                    15
#define PMIC_AUXADC_MDRT_DET_WKUP_START_CNT_MASK         0xFFF
#define PMIC_AUXADC_MDRT_DET_WKUP_START_CNT_SHIFT        0
#define PMIC_AUXADC_MDRT_DET_WKUP_START_CLR_MASK         0x1
#define PMIC_AUXADC_MDRT_DET_WKUP_START_CLR_SHIFT        15
#define PMIC_AUXADC_MDRT_DET_WKUP_START_MASK             0x1
#define PMIC_AUXADC_MDRT_DET_WKUP_START_SHIFT            0
#define PMIC_AUXADC_MDRT_DET_WKUP_START_SEL_MASK         0x1
#define PMIC_AUXADC_MDRT_DET_WKUP_START_SEL_SHIFT        1
#define PMIC_AUXADC_MDRT_DET_WKUP_EN_MASK                0x1
#define PMIC_AUXADC_MDRT_DET_WKUP_EN_SHIFT               2
#define PMIC_AUXADC_MDRT_DET_SRCLKEN_IND_MASK            0x1
#define PMIC_AUXADC_MDRT_DET_SRCLKEN_IND_SHIFT           3
#define PMIC_AUXADC_MDRT_DET_RDY_ST_PRD_MASK             0x3FF
#define PMIC_AUXADC_MDRT_DET_RDY_ST_PRD_SHIFT            0
#define PMIC_AUXADC_MDRT_DET_RDY_ST_EN_MASK              0x1
#define PMIC_AUXADC_MDRT_DET_RDY_ST_EN_SHIFT             15
#define PMIC_AUXADC_MDRT_DET_START_SEL_MASK              0x1
#define PMIC_AUXADC_MDRT_DET_START_SEL_SHIFT             0
#define PMIC_AUXADC_JEITA_IRQ_EN_MASK                    0x1
#define PMIC_AUXADC_JEITA_IRQ_EN_SHIFT                   0
#define PMIC_AUXADC_JEITA_EN_MASK                        0x1
#define PMIC_AUXADC_JEITA_EN_SHIFT                       1
#define PMIC_AUXADC_JEITA_DET_PRD_MASK                   0xF
#define PMIC_AUXADC_JEITA_DET_PRD_SHIFT                  2
#define PMIC_AUXADC_JEITA_DEBT_MASK                      0xF
#define PMIC_AUXADC_JEITA_DEBT_SHIFT                     6
#define PMIC_AUXADC_JEITA_MIPI_DIS_MASK                  0x1
#define PMIC_AUXADC_JEITA_MIPI_DIS_SHIFT                 10
#define PMIC_AUXADC_JEITA_FROZE_EN_MASK                  0x1
#define PMIC_AUXADC_JEITA_FROZE_EN_SHIFT                 11
#define PMIC_AUXADC_JEITA_VOLT_HOT_MASK                  0xFFF
#define PMIC_AUXADC_JEITA_VOLT_HOT_SHIFT                 0
#define PMIC_AUXADC_JEITA_HOT_IRQ_MASK                   0x1
#define PMIC_AUXADC_JEITA_HOT_IRQ_SHIFT                  15
#define PMIC_AUXADC_JEITA_VOLT_WARM_MASK                 0xFFF
#define PMIC_AUXADC_JEITA_VOLT_WARM_SHIFT                0
#define PMIC_AUXADC_JEITA_WARM_IRQ_MASK                  0x1
#define PMIC_AUXADC_JEITA_WARM_IRQ_SHIFT                 15
#define PMIC_AUXADC_JEITA_VOLT_COOL_MASK                 0xFFF
#define PMIC_AUXADC_JEITA_VOLT_COOL_SHIFT                0
#define PMIC_AUXADC_JEITA_COOL_IRQ_MASK                  0x1
#define PMIC_AUXADC_JEITA_COOL_IRQ_SHIFT                 15
#define PMIC_AUXADC_JEITA_VOLT_COLD_MASK                 0xFFF
#define PMIC_AUXADC_JEITA_VOLT_COLD_SHIFT                0
#define PMIC_AUXADC_JEITA_COLD_IRQ_MASK                  0x1
#define PMIC_AUXADC_JEITA_COLD_IRQ_SHIFT                 15
#define PMIC_AUXADC_JEITA_DEBOUNCE_COUNT_COLD_MASK       0xF
#define PMIC_AUXADC_JEITA_DEBOUNCE_COUNT_COLD_SHIFT      0
#define PMIC_AUXADC_JEITA_DEBOUNCE_COUNT_COOL_MASK       0xF
#define PMIC_AUXADC_JEITA_DEBOUNCE_COUNT_COOL_SHIFT      4
#define PMIC_AUXADC_JEITA_DEBOUNCE_COUNT_WARM_MASK       0xF
#define PMIC_AUXADC_JEITA_DEBOUNCE_COUNT_WARM_SHIFT      8
#define PMIC_AUXADC_JEITA_DEBOUNCE_COUNT_HOT_MASK        0xF
#define PMIC_AUXADC_JEITA_DEBOUNCE_COUNT_HOT_SHIFT       12
#define PMIC_AUXADC_DCXO_MDRT_DET_PRD_MASK               0x3FF
#define PMIC_AUXADC_DCXO_MDRT_DET_PRD_SHIFT              0
#define PMIC_AUXADC_DCXO_MDRT_DET_EN_MASK                0x1
#define PMIC_AUXADC_DCXO_MDRT_DET_EN_SHIFT               15
#define PMIC_AUXADC_DCXO_MDRT_DET_WKUP_START_CNT_MASK    0xFFF
#define PMIC_AUXADC_DCXO_MDRT_DET_WKUP_START_CNT_SHIFT   0
#define PMIC_AUXADC_DCXO_MDRT_DET_WKUP_START_CLR_MASK    0x1
#define PMIC_AUXADC_DCXO_MDRT_DET_WKUP_START_CLR_SHIFT   15
#define PMIC_AUXADC_DCXO_MDRT_DET_WKUP_EN_MASK           0x1
#define PMIC_AUXADC_DCXO_MDRT_DET_WKUP_EN_SHIFT          0
#define PMIC_AUXADC_DCXO_MDRT_DET_WKUP_START_SEL_MASK    0x1
#define PMIC_AUXADC_DCXO_MDRT_DET_WKUP_START_SEL_SHIFT   1
#define PMIC_AUXADC_DCXO_MDRT_DET_WKUP_START_MASK        0x1
#define PMIC_AUXADC_DCXO_MDRT_DET_WKUP_START_SHIFT       2
#define PMIC_AUXADC_DCXO_MDRT_DET_SRCLKEN_IND_MASK       0x1
#define PMIC_AUXADC_DCXO_MDRT_DET_SRCLKEN_IND_SHIFT      3
#define PMIC_AUXADC_DCXO_CH4_MUX_AP_SEL_MASK             0x1
#define PMIC_AUXADC_DCXO_CH4_MUX_AP_SEL_SHIFT            4
#define PMIC_AUXADC_NAG_EN_MASK                          0x1
#define PMIC_AUXADC_NAG_EN_SHIFT                         0
#define PMIC_AUXADC_NAG_CLR_MASK                         0x1
#define PMIC_AUXADC_NAG_CLR_SHIFT                        1
#define PMIC_AUXADC_NAG_VBAT1_SEL_MASK                   0x1
#define PMIC_AUXADC_NAG_VBAT1_SEL_SHIFT                  2
#define PMIC_AUXADC_NAG_PRD_MASK                         0x7F
#define PMIC_AUXADC_NAG_PRD_SHIFT                        3
#define PMIC_AUXADC_NAG_IRQ_EN_MASK                      0x1
#define PMIC_AUXADC_NAG_IRQ_EN_SHIFT                     10
#define PMIC_AUXADC_NAG_C_DLTV_IRQ_MASK                  0x1
#define PMIC_AUXADC_NAG_C_DLTV_IRQ_SHIFT                 15
#define PMIC_AUXADC_NAG_ZCV_MASK                         0x7FFF
#define PMIC_AUXADC_NAG_ZCV_SHIFT                        0
#define PMIC_AUXADC_NAG_C_DLTV_TH_15_0_MASK              0xFFFF
#define PMIC_AUXADC_NAG_C_DLTV_TH_15_0_SHIFT             0
#define PMIC_AUXADC_NAG_C_DLTV_TH_26_16_MASK             0x7FF
#define PMIC_AUXADC_NAG_C_DLTV_TH_26_16_SHIFT            0
#define PMIC_AUXADC_NAG_CNT_15_0_MASK                    0xFFFF
#define PMIC_AUXADC_NAG_CNT_15_0_SHIFT                   0
#define PMIC_AUXADC_NAG_CNT_25_16_MASK                   0x3FF
#define PMIC_AUXADC_NAG_CNT_25_16_SHIFT                  0
#define PMIC_AUXADC_NAG_DLTV_MASK                        0xFFFF
#define PMIC_AUXADC_NAG_DLTV_SHIFT                       0
#define PMIC_AUXADC_NAG_C_DLTV_15_0_MASK                 0xFFFF
#define PMIC_AUXADC_NAG_C_DLTV_15_0_SHIFT                0
#define PMIC_AUXADC_NAG_C_DLTV_26_16_MASK                0x7FF
#define PMIC_AUXADC_NAG_C_DLTV_26_16_SHIFT               0
#define PMIC_AUXADC_EFUSE_DEGC_CALI_MASK                 0x3F
#define PMIC_AUXADC_EFUSE_DEGC_CALI_SHIFT                0
#define PMIC_AUXADC_EFUSE_ADC_CALI_EN_MASK               0x1
#define PMIC_AUXADC_EFUSE_ADC_CALI_EN_SHIFT              8
#define PMIC_AUXADC_EFUSE_1RSV0_MASK                     0x7F
#define PMIC_AUXADC_EFUSE_1RSV0_SHIFT                    9
#define PMIC_AUXADC_EFUSE_O_VTS_MASK                     0x1FFF
#define PMIC_AUXADC_EFUSE_O_VTS_SHIFT                    0
#define PMIC_AUXADC_EFUSE_2RSV0_MASK                     0x7
#define PMIC_AUXADC_EFUSE_2RSV0_SHIFT                    13
#define PMIC_AUXADC_EFUSE_O_SLOPE_MASK                   0x3F
#define PMIC_AUXADC_EFUSE_O_SLOPE_SHIFT                  0
#define PMIC_AUXADC_EFUSE_O_SLOPE_SIGN_MASK              0x1
#define PMIC_AUXADC_EFUSE_O_SLOPE_SIGN_SHIFT             8
#define PMIC_AUXADC_EFUSE_3RSV0_MASK                     0x7F
#define PMIC_AUXADC_EFUSE_3RSV0_SHIFT                    9
#define PMIC_AUXADC_EFUSE_AUXADC_RSV_MASK                0xF
#define PMIC_AUXADC_EFUSE_AUXADC_RSV_SHIFT               0
#define PMIC_AUXADC_EFUSE_ID_MASK                        0x1
#define PMIC_AUXADC_EFUSE_ID_SHIFT                       4
#define PMIC_AUXADC_EFUSE_4RSV0_MASK                     0x7FF
#define PMIC_AUXADC_EFUSE_4RSV0_SHIFT                    5
#define PMIC_AUXADC_RSV_1RSV0_MASK                       0xFFFF
#define PMIC_AUXADC_RSV_1RSV0_SHIFT                      0
#define PMIC_DA_ADCIN_VBAT_EN_MASK                       0x1
#define PMIC_DA_ADCIN_VBAT_EN_SHIFT                      0
#define PMIC_DA_AUXADC_VBAT_EN_MASK                      0x1
#define PMIC_DA_AUXADC_VBAT_EN_SHIFT                     1
#define PMIC_DA_ADCIN_VSEN_MUX_EN_MASK                   0x1
#define PMIC_DA_ADCIN_VSEN_MUX_EN_SHIFT                  2
#define PMIC_DA_ADCIN_VSEN_EN_MASK                       0x1
#define PMIC_DA_ADCIN_VSEN_EN_SHIFT                      3
#define PMIC_DA_ADCIN_CHR_EN_MASK                        0x1
#define PMIC_DA_ADCIN_CHR_EN_SHIFT                       4
#define PMIC_DA_BATON_TDET_EN_MASK                       0x1
#define PMIC_DA_BATON_TDET_EN_SHIFT                      5
#define PMIC_DA_ADCIN_BATID_SW_EN_MASK                   0x1
#define PMIC_DA_ADCIN_BATID_SW_EN_SHIFT                  6
#define PMIC_RG_AUXADC_IMP_CK_SW_MODE_MASK               0x1
#define PMIC_RG_AUXADC_IMP_CK_SW_MODE_SHIFT              0
#define PMIC_RG_AUXADC_IMP_CK_SW_EN_MASK                 0x1
#define PMIC_RG_AUXADC_IMP_CK_SW_EN_SHIFT                1
#define PMIC_RG_AUXADC_LBAT_CK_SW_MODE_MASK              0x1
#define PMIC_RG_AUXADC_LBAT_CK_SW_MODE_SHIFT             0
#define PMIC_RG_AUXADC_LBAT_CK_SW_EN_MASK                0x1
#define PMIC_RG_AUXADC_LBAT_CK_SW_EN_SHIFT               1
#define PMIC_RG_AUXADC_THR_CK_SW_MODE_MASK               0x1
#define PMIC_RG_AUXADC_THR_CK_SW_MODE_SHIFT              0
#define PMIC_RG_AUXADC_THR_CK_SW_EN_MASK                 0x1
#define PMIC_RG_AUXADC_THR_CK_SW_EN_SHIFT                1
#define PMIC_RG_AUXADC_BAT_TEMP_CK_SW_MODE_MASK          0x1
#define PMIC_RG_AUXADC_BAT_TEMP_CK_SW_MODE_SHIFT         0
#define PMIC_RG_AUXADC_BAT_TEMP_CK_SW_EN_MASK            0x1
#define PMIC_RG_AUXADC_BAT_TEMP_CK_SW_EN_SHIFT           1
#define PMIC_RG_AUXADC_LBAT2_CK_SW_MODE_MASK             0x1
#define PMIC_RG_AUXADC_LBAT2_CK_SW_MODE_SHIFT            0
#define PMIC_RG_AUXADC_LBAT2_CK_SW_EN_MASK               0x1
#define PMIC_RG_AUXADC_LBAT2_CK_SW_EN_SHIFT              1
#define PMIC_RG_AUXADC_JEITA_CK_SW_MODE_MASK             0x1
#define PMIC_RG_AUXADC_JEITA_CK_SW_MODE_SHIFT            0
#define PMIC_RG_AUXADC_JEITA_CK_SW_EN_MASK               0x1
#define PMIC_RG_AUXADC_JEITA_CK_SW_EN_SHIFT              1
#define PMIC_RG_AUXADC_NAG_CK_SW_MODE_MASK               0x1
#define PMIC_RG_AUXADC_NAG_CK_SW_MODE_SHIFT              0
#define PMIC_RG_AUXADC_NAG_CK_SW_EN_MASK                 0x1
#define PMIC_RG_AUXADC_NAG_CK_SW_EN_SHIFT                1
#define PMIC_RG_AUXADC_NEW_PRIORITY_LIST_SEL_MASK        0x1
#define PMIC_RG_AUXADC_NEW_PRIORITY_LIST_SEL_SHIFT       0
#define PMIC_RG_ISINK_TRIM_EN_MASK                       0x1
#define PMIC_RG_ISINK_TRIM_EN_SHIFT                      0
#define PMIC_RG_ISINK_TRIM_SEL_MASK                      0x7
#define PMIC_RG_ISINK_TRIM_SEL_SHIFT                     1
#define PMIC_RG_ISINK_TRIM_BIAS_MASK                     0x7
#define PMIC_RG_ISINK_TRIM_BIAS_SHIFT                    4
#define PMIC_RG_ISINK_RSV_MASK                           0xF
#define PMIC_RG_ISINK_RSV_SHIFT                          7
#define PMIC_RG_ISINK0_CHOP_EN_MASK                      0x1
#define PMIC_RG_ISINK0_CHOP_EN_SHIFT                     11
#define PMIC_RG_ISINK1_CHOP_EN_MASK                      0x1
#define PMIC_RG_ISINK1_CHOP_EN_SHIFT                     12
#define PMIC_RG_ISINK2_CHOP_EN_MASK                      0x1
#define PMIC_RG_ISINK2_CHOP_EN_SHIFT                     13
#define PMIC_RG_ISINK3_CHOP_EN_MASK                      0x1
#define PMIC_RG_ISINK3_CHOP_EN_SHIFT                     14
#define PMIC_RG_ISINK0_DOUBLE_MASK                       0x1
#define PMIC_RG_ISINK0_DOUBLE_SHIFT                      15
#define PMIC_RG_ISINK1_DOUBLE_MASK                       0x1
#define PMIC_RG_ISINK1_DOUBLE_SHIFT                      0
#define PMIC_RG_ISINK2_DOUBLE_MASK                       0x1
#define PMIC_RG_ISINK2_DOUBLE_SHIFT                      1
#define PMIC_RG_ISINK3_DOUBLE_MASK                       0x1
#define PMIC_RG_ISINK3_DOUBLE_SHIFT                      2
#define PMIC_ISINK0_RSV1_MASK                            0xF
#define PMIC_ISINK0_RSV1_SHIFT                           0
#define PMIC_ISINK0_RSV0_MASK                            0x7
#define PMIC_ISINK0_RSV0_SHIFT                           4
#define PMIC_ISINK_CH0_STEP_MASK                         0x7
#define PMIC_ISINK_CH0_STEP_SHIFT                        12
#define PMIC_ISINK1_RSV1_MASK                            0xF
#define PMIC_ISINK1_RSV1_SHIFT                           0
#define PMIC_ISINK1_RSV0_MASK                            0x7
#define PMIC_ISINK1_RSV0_SHIFT                           4
#define PMIC_ISINK_CH1_STEP_MASK                         0x7
#define PMIC_ISINK_CH1_STEP_SHIFT                        12
#define PMIC_ISINK2_RSV1_MASK                            0xF
#define PMIC_ISINK2_RSV1_SHIFT                           0
#define PMIC_ISINK2_RSV0_MASK                            0x7
#define PMIC_ISINK2_RSV0_SHIFT                           4
#define PMIC_ISINK_CH2_STEP_MASK                         0x7
#define PMIC_ISINK_CH2_STEP_SHIFT                        12
#define PMIC_ISINK3_RSV1_MASK                            0xF
#define PMIC_ISINK3_RSV1_SHIFT                           0
#define PMIC_ISINK3_RSV0_MASK                            0x7
#define PMIC_ISINK3_RSV0_SHIFT                           4
#define PMIC_ISINK_CH3_STEP_MASK                         0x7
#define PMIC_ISINK_CH3_STEP_SHIFT                        12
#define PMIC_AD_NI_ISINK0_STATUS_MASK                    0x1
#define PMIC_AD_NI_ISINK0_STATUS_SHIFT                   0
#define PMIC_AD_NI_ISINK1_STATUS_MASK                    0x1
#define PMIC_AD_NI_ISINK1_STATUS_SHIFT                   1
#define PMIC_AD_NI_ISINK2_STATUS_MASK                    0x1
#define PMIC_AD_NI_ISINK2_STATUS_SHIFT                   2
#define PMIC_AD_NI_ISINK3_STATUS_MASK                    0x1
#define PMIC_AD_NI_ISINK3_STATUS_SHIFT                   3
#define PMIC_ISINK_CH3_EN_MASK                           0x1
#define PMIC_ISINK_CH3_EN_SHIFT                          0
#define PMIC_ISINK_CH2_EN_MASK                           0x1
#define PMIC_ISINK_CH2_EN_SHIFT                          1
#define PMIC_ISINK_CH1_EN_MASK                           0x1
#define PMIC_ISINK_CH1_EN_SHIFT                          2
#define PMIC_ISINK_CH0_EN_MASK                           0x1
#define PMIC_ISINK_CH0_EN_SHIFT                          3
#define PMIC_ISINK_CHOP3_EN_MASK                         0x1
#define PMIC_ISINK_CHOP3_EN_SHIFT                        4
#define PMIC_ISINK_CHOP2_EN_MASK                         0x1
#define PMIC_ISINK_CHOP2_EN_SHIFT                        5
#define PMIC_ISINK_CHOP1_EN_MASK                         0x1
#define PMIC_ISINK_CHOP1_EN_SHIFT                        6
#define PMIC_ISINK_CHOP0_EN_MASK                         0x1
#define PMIC_ISINK_CHOP0_EN_SHIFT                        7
#define PMIC_ISINK_CH3_BIAS_EN_MASK                      0x1
#define PMIC_ISINK_CH3_BIAS_EN_SHIFT                     8
#define PMIC_ISINK_CH2_BIAS_EN_MASK                      0x1
#define PMIC_ISINK_CH2_BIAS_EN_SHIFT                     9
#define PMIC_ISINK_CH1_BIAS_EN_MASK                      0x1
#define PMIC_ISINK_CH1_BIAS_EN_SHIFT                     10
#define PMIC_ISINK_CH0_BIAS_EN_MASK                      0x1
#define PMIC_ISINK_CH0_BIAS_EN_SHIFT                     11
#define PMIC_RG_AUDDACLPWRUP_VAUDP32_MASK                0x1
#define PMIC_RG_AUDDACLPWRUP_VAUDP32_SHIFT               0
#define PMIC_RG_AUDDACRPWRUP_VAUDP32_MASK                0x1
#define PMIC_RG_AUDDACRPWRUP_VAUDP32_SHIFT               1
#define PMIC_RG_AUD_DAC_PWR_UP_VA32_MASK                 0x1
#define PMIC_RG_AUD_DAC_PWR_UP_VA32_SHIFT                2
#define PMIC_RG_AUD_DAC_PWL_UP_VA32_MASK                 0x1
#define PMIC_RG_AUD_DAC_PWL_UP_VA32_SHIFT                3
#define PMIC_RG_AUDHPLPWRUP_VAUDP32_MASK                 0x1
#define PMIC_RG_AUDHPLPWRUP_VAUDP32_SHIFT                4
#define PMIC_RG_AUDHPRPWRUP_VAUDP32_MASK                 0x1
#define PMIC_RG_AUDHPRPWRUP_VAUDP32_SHIFT                5
#define PMIC_RG_AUDHPLPWRUP_IBIAS_VAUDP32_MASK           0x1
#define PMIC_RG_AUDHPLPWRUP_IBIAS_VAUDP32_SHIFT          6
#define PMIC_RG_AUDHPRPWRUP_IBIAS_VAUDP32_MASK           0x1
#define PMIC_RG_AUDHPRPWRUP_IBIAS_VAUDP32_SHIFT          7
#define PMIC_RG_AUDHPLMUXINPUTSEL_VAUDP32_MASK           0x3
#define PMIC_RG_AUDHPLMUXINPUTSEL_VAUDP32_SHIFT          8
#define PMIC_RG_AUDHPRMUXINPUTSEL_VAUDP32_MASK           0x3
#define PMIC_RG_AUDHPRMUXINPUTSEL_VAUDP32_SHIFT          10
#define PMIC_RG_AUDHPLSCDISABLE_VAUDP32_MASK             0x1
#define PMIC_RG_AUDHPLSCDISABLE_VAUDP32_SHIFT            12
#define PMIC_RG_AUDHPRSCDISABLE_VAUDP32_MASK             0x1
#define PMIC_RG_AUDHPRSCDISABLE_VAUDP32_SHIFT            13
#define PMIC_RG_AUDHPLBSCCURRENT_VAUDP32_MASK            0x1
#define PMIC_RG_AUDHPLBSCCURRENT_VAUDP32_SHIFT           14
#define PMIC_RG_AUDHPRBSCCURRENT_VAUDP32_MASK            0x1
#define PMIC_RG_AUDHPRBSCCURRENT_VAUDP32_SHIFT           15
#define PMIC_RG_AUDHPLOUTPWRUP_VAUDP32_MASK              0x1
#define PMIC_RG_AUDHPLOUTPWRUP_VAUDP32_SHIFT             0
#define PMIC_RG_AUDHPROUTPWRUP_VAUDP32_MASK              0x1
#define PMIC_RG_AUDHPROUTPWRUP_VAUDP32_SHIFT             1
#define PMIC_RG_AUDHPLOUTAUXPWRUP_VAUDP32_MASK           0x1
#define PMIC_RG_AUDHPLOUTAUXPWRUP_VAUDP32_SHIFT          2
#define PMIC_RG_AUDHPROUTAUXPWRUP_VAUDP32_MASK           0x1
#define PMIC_RG_AUDHPROUTAUXPWRUP_VAUDP32_SHIFT          3
#define PMIC_RG_HPLAUXFBRSW_EN_VAUDP32_MASK              0x1
#define PMIC_RG_HPLAUXFBRSW_EN_VAUDP32_SHIFT             4
#define PMIC_RG_HPRAUXFBRSW_EN_VAUDP32_MASK              0x1
#define PMIC_RG_HPRAUXFBRSW_EN_VAUDP32_SHIFT             5
#define PMIC_RG_HPLSHORT2HPLAUX_EN_VAUDP32_MASK          0x1
#define PMIC_RG_HPLSHORT2HPLAUX_EN_VAUDP32_SHIFT         6
#define PMIC_RG_HPRSHORT2HPRAUX_EN_VAUDP32_MASK          0x1
#define PMIC_RG_HPRSHORT2HPRAUX_EN_VAUDP32_SHIFT         7
#define PMIC_RG_HPLOUTSTGCTRL_VAUDP32_MASK               0x7
#define PMIC_RG_HPLOUTSTGCTRL_VAUDP32_SHIFT              8
#define PMIC_RG_HPROUTSTGCTRL_VAUDP32_MASK               0x7
#define PMIC_RG_HPROUTSTGCTRL_VAUDP32_SHIFT              11
#define PMIC_RG_HPLOUTPUTSTBENH_VAUDP32_MASK             0x7
#define PMIC_RG_HPLOUTPUTSTBENH_VAUDP32_SHIFT            0
#define PMIC_RG_HPROUTPUTSTBENH_VAUDP32_MASK             0x7
#define PMIC_RG_HPROUTPUTSTBENH_VAUDP32_SHIFT            4
#define PMIC_RG_AUDHPSTARTUP_VAUDP32_MASK                0x1
#define PMIC_RG_AUDHPSTARTUP_VAUDP32_SHIFT               13
#define PMIC_RG_AUDREFN_DERES_EN_VAUDP32_MASK            0x1
#define PMIC_RG_AUDREFN_DERES_EN_VAUDP32_SHIFT           14
#define PMIC_RG_HPPSHORT2VCM_VAUDP32_MASK                0x1
#define PMIC_RG_HPPSHORT2VCM_VAUDP32_SHIFT               15
#define PMIC_RG_AUDHPLTRIM_VAUDP32_MASK                  0xF
#define PMIC_RG_AUDHPLTRIM_VAUDP32_SHIFT                 0
#define PMIC_RG_AUDHPRTRIM_VAUDP32_MASK                  0xF
#define PMIC_RG_AUDHPRTRIM_VAUDP32_SHIFT                 4
#define PMIC_RG_AUDHPLFINETRIM_VAUDP32_MASK              0x3
#define PMIC_RG_AUDHPLFINETRIM_VAUDP32_SHIFT             8
#define PMIC_RG_AUDHPRFINETRIM_VAUDP32_MASK              0x3
#define PMIC_RG_AUDHPRFINETRIM_VAUDP32_SHIFT             10
#define PMIC_RG_AUDHPTRIM_EN_VAUDP32_MASK                0x1
#define PMIC_RG_AUDHPTRIM_EN_VAUDP32_SHIFT               12
#define PMIC_RG_HPINPUTSTBENH_VAUDP32_MASK               0x1
#define PMIC_RG_HPINPUTSTBENH_VAUDP32_SHIFT              13
#define PMIC_RG_HPINPUTRESET0_VAUDP32_MASK               0x1
#define PMIC_RG_HPINPUTRESET0_VAUDP32_SHIFT              14
#define PMIC_RG_HPOUTPUTRESET0_VAUDP32_MASK              0x1
#define PMIC_RG_HPOUTPUTRESET0_VAUDP32_SHIFT             15
#define PMIC_RG_AUDHPDIFFINPBIASADJ_VAUDP32_MASK         0x7
#define PMIC_RG_AUDHPDIFFINPBIASADJ_VAUDP32_SHIFT        0
#define PMIC_RG_AUDHPLFCOMPRESSEL_VAUDP32_MASK           0x7
#define PMIC_RG_AUDHPLFCOMPRESSEL_VAUDP32_SHIFT          4
#define PMIC_RG_AUDHPHFCOMPRESSEL_VAUDP32_MASK           0x7
#define PMIC_RG_AUDHPHFCOMPRESSEL_VAUDP32_SHIFT          8
#define PMIC_RG_AUDHPHFCOMPBUFGAINSEL_VAUDP32_MASK       0x3
#define PMIC_RG_AUDHPHFCOMPBUFGAINSEL_VAUDP32_SHIFT      12
#define PMIC_RG_AUDHPCOMP_EN_VAUDP32_MASK                0x1
#define PMIC_RG_AUDHPCOMP_EN_VAUDP32_SHIFT               15
#define PMIC_RG_AUDHPDECMGAINADJ_VAUDP32_MASK            0x7
#define PMIC_RG_AUDHPDECMGAINADJ_VAUDP32_SHIFT           0
#define PMIC_RG_AUDHPDEDMGAINADJ_VAUDP32_MASK            0x7
#define PMIC_RG_AUDHPDEDMGAINADJ_VAUDP32_SHIFT           4
#define PMIC_RG_AUDHSPWRUP_VAUDP32_MASK                  0x1
#define PMIC_RG_AUDHSPWRUP_VAUDP32_SHIFT                 0
#define PMIC_RG_AUDHSPWRUP_IBIAS_VAUDP32_MASK            0x1
#define PMIC_RG_AUDHSPWRUP_IBIAS_VAUDP32_SHIFT           1
#define PMIC_RG_AUDHSMUXINPUTSEL_VAUDP32_MASK            0x3
#define PMIC_RG_AUDHSMUXINPUTSEL_VAUDP32_SHIFT           2
#define PMIC_RG_AUDHSSCDISABLE_VAUDP32_MASK              0x1
#define PMIC_RG_AUDHSSCDISABLE_VAUDP32_SHIFT             4
#define PMIC_RG_AUDHSBSCCURRENT_VAUDP32_MASK             0x1
#define PMIC_RG_AUDHSBSCCURRENT_VAUDP32_SHIFT            5
#define PMIC_RG_AUDHSSTARTUP_VAUDP32_MASK                0x1
#define PMIC_RG_AUDHSSTARTUP_VAUDP32_SHIFT               6
#define PMIC_RG_HSOUTPUTSTBENH_VAUDP32_MASK              0x1
#define PMIC_RG_HSOUTPUTSTBENH_VAUDP32_SHIFT             7
#define PMIC_RG_HSINPUTSTBENH_VAUDP32_MASK               0x1
#define PMIC_RG_HSINPUTSTBENH_VAUDP32_SHIFT              8
#define PMIC_RG_HSINPUTRESET0_VAUDP32_MASK               0x1
#define PMIC_RG_HSINPUTRESET0_VAUDP32_SHIFT              9
#define PMIC_RG_HSOUTPUTRESET0_VAUDP32_MASK              0x1
#define PMIC_RG_HSOUTPUTRESET0_VAUDP32_SHIFT             10
#define PMIC_RG_HSOUT_SHORTVCM_VAUDP32_MASK              0x1
#define PMIC_RG_HSOUT_SHORTVCM_VAUDP32_SHIFT             11
#define PMIC_RG_AUDLOLPWRUP_VAUDP32_MASK                 0x1
#define PMIC_RG_AUDLOLPWRUP_VAUDP32_SHIFT                0
#define PMIC_RG_AUDLOLPWRUP_IBIAS_VAUDP32_MASK           0x1
#define PMIC_RG_AUDLOLPWRUP_IBIAS_VAUDP32_SHIFT          1
#define PMIC_RG_AUDLOLMUXINPUTSEL_VAUDP32_MASK           0x3
#define PMIC_RG_AUDLOLMUXINPUTSEL_VAUDP32_SHIFT          2
#define PMIC_RG_AUDLOLSCDISABLE_VAUDP32_MASK             0x1
#define PMIC_RG_AUDLOLSCDISABLE_VAUDP32_SHIFT            4
#define PMIC_RG_AUDLOLBSCCURRENT_VAUDP32_MASK            0x1
#define PMIC_RG_AUDLOLBSCCURRENT_VAUDP32_SHIFT           5
#define PMIC_RG_AUDLOSTARTUP_VAUDP32_MASK                0x1
#define PMIC_RG_AUDLOSTARTUP_VAUDP32_SHIFT               6
#define PMIC_RG_LOINPUTSTBENH_VAUDP32_MASK               0x1
#define PMIC_RG_LOINPUTSTBENH_VAUDP32_SHIFT              7
#define PMIC_RG_LOOUTPUTSTBENH_VAUDP32_MASK              0x1
#define PMIC_RG_LOOUTPUTSTBENH_VAUDP32_SHIFT             8
#define PMIC_RG_LOINPUTRESET0_VAUDP32_MASK               0x1
#define PMIC_RG_LOINPUTRESET0_VAUDP32_SHIFT              9
#define PMIC_RG_LOOUTPUTRESET0_VAUDP32_MASK              0x1
#define PMIC_RG_LOOUTPUTRESET0_VAUDP32_SHIFT             10
#define PMIC_RG_LOOUT_SHORTVCM_VAUDP32_MASK              0x1
#define PMIC_RG_LOOUT_SHORTVCM_VAUDP32_SHIFT             11
#define PMIC_RG_AUDTRIMBUF_INPUTMUXSEL_VAUDP32_MASK      0xF
#define PMIC_RG_AUDTRIMBUF_INPUTMUXSEL_VAUDP32_SHIFT     0
#define PMIC_RG_AUDTRIMBUF_GAINSEL_VAUDP32_MASK          0x3
#define PMIC_RG_AUDTRIMBUF_GAINSEL_VAUDP32_SHIFT         4
#define PMIC_RG_AUDTRIMBUF_EN_VAUDP32_MASK               0x1
#define PMIC_RG_AUDTRIMBUF_EN_VAUDP32_SHIFT              6
#define PMIC_RG_AUDHPSPKDET_INPUTMUXSEL_VAUDP32_MASK     0x3
#define PMIC_RG_AUDHPSPKDET_INPUTMUXSEL_VAUDP32_SHIFT    8
#define PMIC_RG_AUDHPSPKDET_OUTPUTMUXSEL_VAUDP32_MASK    0x3
#define PMIC_RG_AUDHPSPKDET_OUTPUTMUXSEL_VAUDP32_SHIFT   10
#define PMIC_RG_AUDHPSPKDET_EN_VAUDP32_MASK              0x1
#define PMIC_RG_AUDHPSPKDET_EN_VAUDP32_SHIFT             12
#define PMIC_RG_ABIDEC_RSVD0_VA32_MASK                   0xFF
#define PMIC_RG_ABIDEC_RSVD0_VA32_SHIFT                  0
#define PMIC_RG_ABIDEC_RSVD0_VAUDP32_MASK                0xFF
#define PMIC_RG_ABIDEC_RSVD0_VAUDP32_SHIFT               8
#define PMIC_RG_ABIDEC_RSVD1_VAUDP32_MASK                0xFF
#define PMIC_RG_ABIDEC_RSVD1_VAUDP32_SHIFT               0
#define PMIC_RG_ABIDEC_RSVD2_VAUDP32_MASK                0xFF
#define PMIC_RG_ABIDEC_RSVD2_VAUDP32_SHIFT               8
#define PMIC_RG_AUDZCDMUXSEL_VAUDP32_MASK                0x7
#define PMIC_RG_AUDZCDMUXSEL_VAUDP32_SHIFT               0
#define PMIC_RG_AUDZCDCLKSEL_VAUDP32_MASK                0x1
#define PMIC_RG_AUDZCDCLKSEL_VAUDP32_SHIFT               3
#define PMIC_RG_AUDBIASADJ_0_VAUDP32_MASK                0x1FF
#define PMIC_RG_AUDBIASADJ_0_VAUDP32_SHIFT               7
#define PMIC_RG_AUDBIASADJ_1_VAUDP32_MASK                0xFF
#define PMIC_RG_AUDBIASADJ_1_VAUDP32_SHIFT               0
#define PMIC_RG_AUDIBIASPWRDN_VAUDP32_MASK               0x1
#define PMIC_RG_AUDIBIASPWRDN_VAUDP32_SHIFT              8
#define PMIC_RG_RSTB_DECODER_VA32_MASK                   0x1
#define PMIC_RG_RSTB_DECODER_VA32_SHIFT                  0
#define PMIC_RG_SEL_DECODER_96K_VA32_MASK                0x1
#define PMIC_RG_SEL_DECODER_96K_VA32_SHIFT               1
#define PMIC_RG_SEL_DELAY_VCORE_MASK                     0x1
#define PMIC_RG_SEL_DELAY_VCORE_SHIFT                    2
#define PMIC_RG_AUDGLB_PWRDN_VA32_MASK                   0x1
#define PMIC_RG_AUDGLB_PWRDN_VA32_SHIFT                  4
#define PMIC_RG_AUDGLB_LP_VOW_EN_VA32_MASK               0x1
#define PMIC_RG_AUDGLB_LP_VOW_EN_VA32_SHIFT              5
#define PMIC_RG_AUDGLB_LP2_VOW_EN_VA32_MASK              0x1
#define PMIC_RG_AUDGLB_LP2_VOW_EN_VA32_SHIFT             6
#define PMIC_RG_LCLDO_DEC_EN_VA32_MASK                   0x1
#define PMIC_RG_LCLDO_DEC_EN_VA32_SHIFT                  0
#define PMIC_RG_LCLDO_DEC_PDDIS_EN_VA18_MASK             0x1
#define PMIC_RG_LCLDO_DEC_PDDIS_EN_VA18_SHIFT            1
#define PMIC_RG_LCLDO_DEC_REMOTE_SENSE_VA18_MASK         0x1
#define PMIC_RG_LCLDO_DEC_REMOTE_SENSE_VA18_SHIFT        2
#define PMIC_RG_NVREG_EN_VAUDP32_MASK                    0x1
#define PMIC_RG_NVREG_EN_VAUDP32_SHIFT                   4
#define PMIC_RG_NVREG_PULL0V_VAUDP32_MASK                0x1
#define PMIC_RG_NVREG_PULL0V_VAUDP32_SHIFT               5
#define PMIC_RG_AUDPMU_RSVD_VA18_MASK                    0xFF
#define PMIC_RG_AUDPMU_RSVD_VA18_SHIFT                   8
#define PMIC_RG_AUDPREAMPLON_MASK                        0x1
#define PMIC_RG_AUDPREAMPLON_SHIFT                       0
#define PMIC_RG_AUDPREAMPLDCCEN_MASK                     0x1
#define PMIC_RG_AUDPREAMPLDCCEN_SHIFT                    1
#define PMIC_RG_AUDPREAMPLDCPRECHARGE_MASK               0x1
#define PMIC_RG_AUDPREAMPLDCPRECHARGE_SHIFT              2
#define PMIC_RG_AUDPREAMPLPGATEST_MASK                   0x1
#define PMIC_RG_AUDPREAMPLPGATEST_SHIFT                  3
#define PMIC_RG_AUDPREAMPLVSCALE_MASK                    0x3
#define PMIC_RG_AUDPREAMPLVSCALE_SHIFT                   4
#define PMIC_RG_AUDPREAMPLINPUTSEL_MASK                  0x3
#define PMIC_RG_AUDPREAMPLINPUTSEL_SHIFT                 6
#define PMIC_RG_AUDPREAMPLGAIN_MASK                      0x7
#define PMIC_RG_AUDPREAMPLGAIN_SHIFT                     8
#define PMIC_RG_BULKL_VCM_EN_MASK                        0x1
#define PMIC_RG_BULKL_VCM_EN_SHIFT                       11
#define PMIC_RG_AUDADCLPWRUP_MASK                        0x1
#define PMIC_RG_AUDADCLPWRUP_SHIFT                       12
#define PMIC_RG_AUDADCLINPUTSEL_MASK                     0x3
#define PMIC_RG_AUDADCLINPUTSEL_SHIFT                    13
#define PMIC_RG_AUDPREAMPRON_MASK                        0x1
#define PMIC_RG_AUDPREAMPRON_SHIFT                       0
#define PMIC_RG_AUDPREAMPRDCCEN_MASK                     0x1
#define PMIC_RG_AUDPREAMPRDCCEN_SHIFT                    1
#define PMIC_RG_AUDPREAMPRDCPRECHARGE_MASK               0x1
#define PMIC_RG_AUDPREAMPRDCPRECHARGE_SHIFT              2
#define PMIC_RG_AUDPREAMPRPGATEST_MASK                   0x1
#define PMIC_RG_AUDPREAMPRPGATEST_SHIFT                  3
#define PMIC_RG_AUDPREAMPRVSCALE_MASK                    0x3
#define PMIC_RG_AUDPREAMPRVSCALE_SHIFT                   4
#define PMIC_RG_AUDPREAMPRINPUTSEL_MASK                  0x3
#define PMIC_RG_AUDPREAMPRINPUTSEL_SHIFT                 6
#define PMIC_RG_AUDPREAMPRGAIN_MASK                      0x7
#define PMIC_RG_AUDPREAMPRGAIN_SHIFT                     8
#define PMIC_RG_BULKR_VCM_EN_MASK                        0x1
#define PMIC_RG_BULKR_VCM_EN_SHIFT                       11
#define PMIC_RG_AUDADCRPWRUP_MASK                        0x1
#define PMIC_RG_AUDADCRPWRUP_SHIFT                       12
#define PMIC_RG_AUDADCRINPUTSEL_MASK                     0x3
#define PMIC_RG_AUDADCRINPUTSEL_SHIFT                    13
#define PMIC_RG_AUDULHALFBIAS_MASK                       0x1
#define PMIC_RG_AUDULHALFBIAS_SHIFT                      0
#define PMIC_RG_AUDGLBVOWLPWEN_MASK                      0x1
#define PMIC_RG_AUDGLBVOWLPWEN_SHIFT                     1
#define PMIC_RG_AUDPREAMPLPEN_MASK                       0x1
#define PMIC_RG_AUDPREAMPLPEN_SHIFT                      2
#define PMIC_RG_AUDADC1STSTAGELPEN_MASK                  0x1
#define PMIC_RG_AUDADC1STSTAGELPEN_SHIFT                 3
#define PMIC_RG_AUDADC2NDSTAGELPEN_MASK                  0x1
#define PMIC_RG_AUDADC2NDSTAGELPEN_SHIFT                 4
#define PMIC_RG_AUDADCFLASHLPEN_MASK                     0x1
#define PMIC_RG_AUDADCFLASHLPEN_SHIFT                    5
#define PMIC_RG_AUDPREAMPIDDTEST_MASK                    0x3
#define PMIC_RG_AUDPREAMPIDDTEST_SHIFT                   6
#define PMIC_RG_AUDADC1STSTAGEIDDTEST_MASK               0x3
#define PMIC_RG_AUDADC1STSTAGEIDDTEST_SHIFT              8
#define PMIC_RG_AUDADC2NDSTAGEIDDTEST_MASK               0x3
#define PMIC_RG_AUDADC2NDSTAGEIDDTEST_SHIFT              10
#define PMIC_RG_AUDADCREFBUFIDDTEST_MASK                 0x3
#define PMIC_RG_AUDADCREFBUFIDDTEST_SHIFT                12
#define PMIC_RG_AUDADCFLASHIDDTEST_MASK                  0x3
#define PMIC_RG_AUDADCFLASHIDDTEST_SHIFT                 14
#define PMIC_RG_AUDADCCLKRSTB_MASK                       0x1
#define PMIC_RG_AUDADCCLKRSTB_SHIFT                      0
#define PMIC_RG_AUDADCCLKSEL_MASK                        0x3
#define PMIC_RG_AUDADCCLKSEL_SHIFT                       1
#define PMIC_RG_AUDADCCLKSOURCE_MASK                     0x3
#define PMIC_RG_AUDADCCLKSOURCE_SHIFT                    3
#define PMIC_RG_AUDADCCLKGENMODE_MASK                    0x3
#define PMIC_RG_AUDADCCLKGENMODE_SHIFT                   5
#define PMIC_RG_AUDADCDAC0P25FS_MASK                     0x1
#define PMIC_RG_AUDADCDAC0P25FS_SHIFT                    7
#define PMIC_RG_AUDPREAMPAAFEN_MASK                      0x1
#define PMIC_RG_AUDPREAMPAAFEN_SHIFT                     8
#define PMIC_RG_DCCVCMBUFLPMODSEL_MASK                   0x1
#define PMIC_RG_DCCVCMBUFLPMODSEL_SHIFT                  9
#define PMIC_RG_DCCVCMBUFLPSWEN_MASK                     0x1
#define PMIC_RG_DCCVCMBUFLPSWEN_SHIFT                    10
#define PMIC_RG_AUDSPAREPGA_MASK                         0x1F
#define PMIC_RG_AUDSPAREPGA_SHIFT                        11
#define PMIC_RG_AUDADC1STSTAGESDENB_MASK                 0x1
#define PMIC_RG_AUDADC1STSTAGESDENB_SHIFT                0
#define PMIC_RG_AUDADC2NDSTAGERESET_MASK                 0x1
#define PMIC_RG_AUDADC2NDSTAGERESET_SHIFT                1
#define PMIC_RG_AUDADC3RDSTAGERESET_MASK                 0x1
#define PMIC_RG_AUDADC3RDSTAGERESET_SHIFT                2
#define PMIC_RG_AUDADCFSRESET_MASK                       0x1
#define PMIC_RG_AUDADCFSRESET_SHIFT                      3
#define PMIC_RG_AUDADCWIDECM_MASK                        0x1
#define PMIC_RG_AUDADCWIDECM_SHIFT                       4
#define PMIC_RG_AUDADCNOPATEST_MASK                      0x1
#define PMIC_RG_AUDADCNOPATEST_SHIFT                     5
#define PMIC_RG_AUDADCBYPASS_MASK                        0x1
#define PMIC_RG_AUDADCBYPASS_SHIFT                       6
#define PMIC_RG_AUDADCFFBYPASS_MASK                      0x1
#define PMIC_RG_AUDADCFFBYPASS_SHIFT                     7
#define PMIC_RG_AUDADCDACFBCURRENT_MASK                  0x1
#define PMIC_RG_AUDADCDACFBCURRENT_SHIFT                 8
#define PMIC_RG_AUDADCDACIDDTEST_MASK                    0x3
#define PMIC_RG_AUDADCDACIDDTEST_SHIFT                   9
#define PMIC_RG_AUDADCDACNRZ_MASK                        0x1
#define PMIC_RG_AUDADCDACNRZ_SHIFT                       11
#define PMIC_RG_AUDADCNODEM_MASK                         0x1
#define PMIC_RG_AUDADCNODEM_SHIFT                        12
#define PMIC_RG_AUDADCDACTEST_MASK                       0x1
#define PMIC_RG_AUDADCDACTEST_SHIFT                      13
#define PMIC_RG_AUDADCTESTDATA_MASK                      0xFFFF
#define PMIC_RG_AUDADCTESTDATA_SHIFT                     0
#define PMIC_RG_AUDRCTUNEL_MASK                          0x1F
#define PMIC_RG_AUDRCTUNEL_SHIFT                         0
#define PMIC_RG_AUDRCTUNELSEL_MASK                       0x1
#define PMIC_RG_AUDRCTUNELSEL_SHIFT                      5
#define PMIC_RG_AUDRCTUNER_MASK                          0x1F
#define PMIC_RG_AUDRCTUNER_SHIFT                         8
#define PMIC_RG_AUDRCTUNERSEL_MASK                       0x1
#define PMIC_RG_AUDRCTUNERSEL_SHIFT                      13
#define PMIC_RGS_AUDRCTUNELREAD_MASK                     0x1F
#define PMIC_RGS_AUDRCTUNELREAD_SHIFT                    0
#define PMIC_RGS_AUDRCTUNERREAD_MASK                     0x1F
#define PMIC_RGS_AUDRCTUNERREAD_SHIFT                    8
#define PMIC_RG_AUDSPAREVA30_MASK                        0xFF
#define PMIC_RG_AUDSPAREVA30_SHIFT                       0
#define PMIC_RG_AUDSPAREVA18_MASK                        0xFF
#define PMIC_RG_AUDSPAREVA18_SHIFT                       8
#define PMIC_RG_AUDDIGMICEN_MASK                         0x1
#define PMIC_RG_AUDDIGMICEN_SHIFT                        0
#define PMIC_RG_AUDDIGMICBIAS_MASK                       0x3
#define PMIC_RG_AUDDIGMICBIAS_SHIFT                      1
#define PMIC_RG_DMICHPCLKEN_MASK                         0x1
#define PMIC_RG_DMICHPCLKEN_SHIFT                        3
#define PMIC_RG_AUDDIGMICPDUTY_MASK                      0x3
#define PMIC_RG_AUDDIGMICPDUTY_SHIFT                     4
#define PMIC_RG_AUDDIGMICNDUTY_MASK                      0x3
#define PMIC_RG_AUDDIGMICNDUTY_SHIFT                     6
#define PMIC_RG_DMICMONEN_MASK                           0x1
#define PMIC_RG_DMICMONEN_SHIFT                          8
#define PMIC_RG_DMICMONSEL_MASK                          0x7
#define PMIC_RG_DMICMONSEL_SHIFT                         9
#define PMIC_RG_AUDSPAREVMIC_MASK                        0xF
#define PMIC_RG_AUDSPAREVMIC_SHIFT                       12
#define PMIC_RG_AUDPWDBMICBIAS0_MASK                     0x1
#define PMIC_RG_AUDPWDBMICBIAS0_SHIFT                    0
#define PMIC_RG_AUDMICBIAS0DCSW0P1EN_MASK                0x1
#define PMIC_RG_AUDMICBIAS0DCSW0P1EN_SHIFT               1
#define PMIC_RG_AUDMICBIAS0DCSW0P2EN_MASK                0x1
#define PMIC_RG_AUDMICBIAS0DCSW0P2EN_SHIFT               2
#define PMIC_RG_AUDMICBIAS0DCSW0NEN_MASK                 0x1
#define PMIC_RG_AUDMICBIAS0DCSW0NEN_SHIFT                3
#define PMIC_RG_AUDMICBIAS0VREF_MASK                     0x7
#define PMIC_RG_AUDMICBIAS0VREF_SHIFT                    4
#define PMIC_RG_AUDMICBIAS0LOWPEN_MASK                   0x1
#define PMIC_RG_AUDMICBIAS0LOWPEN_SHIFT                  7
#define PMIC_RG_AUDPWDBMICBIAS2_MASK                     0x1
#define PMIC_RG_AUDPWDBMICBIAS2_SHIFT                    8
#define PMIC_RG_AUDMICBIAS0DCSW2P1EN_MASK                0x1
#define PMIC_RG_AUDMICBIAS0DCSW2P1EN_SHIFT               9
#define PMIC_RG_AUDMICBIAS0DCSW2P2EN_MASK                0x1
#define PMIC_RG_AUDMICBIAS0DCSW2P2EN_SHIFT               10
#define PMIC_RG_AUDMICBIAS0DCSW2NEN_MASK                 0x1
#define PMIC_RG_AUDMICBIAS0DCSW2NEN_SHIFT                11
#define PMIC_RG_AUDPWDBMICBIAS1_MASK                     0x1
#define PMIC_RG_AUDPWDBMICBIAS1_SHIFT                    0
#define PMIC_RG_AUDMICBIAS1DCSW1PEN_MASK                 0x1
#define PMIC_RG_AUDMICBIAS1DCSW1PEN_SHIFT                1
#define PMIC_RG_AUDMICBIAS1DCSW1NEN_MASK                 0x1
#define PMIC_RG_AUDMICBIAS1DCSW1NEN_SHIFT                2
#define PMIC_RG_AUDMICBIAS1VREF_MASK                     0x7
#define PMIC_RG_AUDMICBIAS1VREF_SHIFT                    4
#define PMIC_RG_AUDMICBIAS1LOWPEN_MASK                   0x1
#define PMIC_RG_AUDMICBIAS1LOWPEN_SHIFT                  7
#define PMIC_RG_AUDMICBIAS1HVEN_MASK                     0x1
#define PMIC_RG_AUDMICBIAS1HVEN_SHIFT                    8
#define PMIC_RG_AUDMICBIAS1HVVREF_MASK                   0x1
#define PMIC_RG_AUDMICBIAS1HVVREF_SHIFT                  9
#define PMIC_RG_BANDGAPGEN_MASK                          0x1
#define PMIC_RG_BANDGAPGEN_SHIFT                         10
#define PMIC_RG_AUDACCDETMICBIAS0PULLLOW_MASK            0x1
#define PMIC_RG_AUDACCDETMICBIAS0PULLLOW_SHIFT           0
#define PMIC_RG_AUDACCDETMICBIAS1PULLLOW_MASK            0x1
#define PMIC_RG_AUDACCDETMICBIAS1PULLLOW_SHIFT           1
#define PMIC_RG_AUDACCDETMICBIAS2PULLLOW_MASK            0x1
#define PMIC_RG_AUDACCDETMICBIAS2PULLLOW_SHIFT           2
#define PMIC_RG_AUDACCDETVIN1PULLLOW_MASK                0x1
#define PMIC_RG_AUDACCDETVIN1PULLLOW_SHIFT               3
#define PMIC_RG_EINTHIRENB_MASK                          0x1
#define PMIC_RG_EINTHIRENB_SHIFT                         4
#define PMIC_RG_AUDACCDETVTHACAL_MASK                    0x1
#define PMIC_RG_AUDACCDETVTHACAL_SHIFT                   5
#define PMIC_RG_AUDACCDETVTHBCAL_MASK                    0x1
#define PMIC_RG_AUDACCDETVTHBCAL_SHIFT                   6
#define PMIC_RG_AUDACCDETTVDET_MASK                      0x1
#define PMIC_RG_AUDACCDETTVDET_SHIFT                     7
#define PMIC_RG_ACCDETSEL_MASK                           0x1
#define PMIC_RG_ACCDETSEL_SHIFT                          8
#define PMIC_RG_SWBUFMODSEL_MASK                         0x1
#define PMIC_RG_SWBUFMODSEL_SHIFT                        9
#define PMIC_RG_SWBUFSWEN_MASK                           0x1
#define PMIC_RG_SWBUFSWEN_SHIFT                          10
#define PMIC_RG_EINTCOMPVTH_MASK                         0x1
#define PMIC_RG_EINTCOMPVTH_SHIFT                        11
#define PMIC_RG_EINTCONFIGACCDET_MASK                    0x1
#define PMIC_RG_EINTCONFIGACCDET_SHIFT                   12
#define PMIC_RG_ACCDETSPAREVA30_MASK                     0x7
#define PMIC_RG_ACCDETSPAREVA30_SHIFT                    13
#define PMIC_RG_AUDENCSPAREVA30_MASK                     0xFF
#define PMIC_RG_AUDENCSPAREVA30_SHIFT                    0
#define PMIC_RG_AUDENCSPAREVA18_MASK                     0xFF
#define PMIC_RG_AUDENCSPAREVA18_SHIFT                    8
#define PMIC_RG_PLL_EN_MASK                              0x1
#define PMIC_RG_PLL_EN_SHIFT                             0
#define PMIC_RG_PLLBS_RST_MASK                           0x1
#define PMIC_RG_PLLBS_RST_SHIFT                          1
#define PMIC_RG_PLL_DCKO_SEL_MASK                        0x3
#define PMIC_RG_PLL_DCKO_SEL_SHIFT                       2
#define PMIC_RG_PLL_DIV1_MASK                            0x3F
#define PMIC_RG_PLL_DIV1_SHIFT                           4
#define PMIC_RG_PLL_RLATCH_EN_MASK                       0x1
#define PMIC_RG_PLL_RLATCH_EN_SHIFT                      10
#define PMIC_RG_PLL_PDIV1_EN_MASK                        0x1
#define PMIC_RG_PLL_PDIV1_EN_SHIFT                       11
#define PMIC_RG_PLL_PDIV1_MASK                           0xF
#define PMIC_RG_PLL_PDIV1_SHIFT                          12
#define PMIC_RG_PLL_BC_MASK                              0x3
#define PMIC_RG_PLL_BC_SHIFT                             0
#define PMIC_RG_PLL_BP_MASK                              0x3
#define PMIC_RG_PLL_BP_SHIFT                             2
#define PMIC_RG_PLL_BR_MASK                              0x3
#define PMIC_RG_PLL_BR_SHIFT                             4
#define PMIC_RG_CKO_SEL_MASK                             0x3
#define PMIC_RG_CKO_SEL_SHIFT                            6
#define PMIC_RG_PLL_IBSEL_MASK                           0x3
#define PMIC_RG_PLL_IBSEL_SHIFT                          8
#define PMIC_RG_PLL_CKT_SEL_MASK                         0x3
#define PMIC_RG_PLL_CKT_SEL_SHIFT                        10
#define PMIC_RG_PLL_VCT_EN_MASK                          0x1
#define PMIC_RG_PLL_VCT_EN_SHIFT                         12
#define PMIC_RG_PLL_CKT_EN_MASK                          0x1
#define PMIC_RG_PLL_CKT_EN_SHIFT                         13
#define PMIC_RG_PLL_HPM_EN_MASK                          0x1
#define PMIC_RG_PLL_HPM_EN_SHIFT                         14
#define PMIC_RG_PLL_DCHP_EN_MASK                         0x1
#define PMIC_RG_PLL_DCHP_EN_SHIFT                        15
#define PMIC_RG_PLL_CDIV_MASK                            0x7
#define PMIC_RG_PLL_CDIV_SHIFT                           0
#define PMIC_RG_VCOBAND_MASK                             0x7
#define PMIC_RG_VCOBAND_SHIFT                            3
#define PMIC_RG_CKDRV_EN_MASK                            0x1
#define PMIC_RG_CKDRV_EN_SHIFT                           6
#define PMIC_RG_PLL_DCHP_AEN_MASK                        0x1
#define PMIC_RG_PLL_DCHP_AEN_SHIFT                       7
#define PMIC_RG_PLL_RSVA_MASK                            0xFF
#define PMIC_RG_PLL_RSVA_SHIFT                           8
#define PMIC_RG_AUDZCDENABLE_MASK                        0x1
#define PMIC_RG_AUDZCDENABLE_SHIFT                       0
#define PMIC_RG_AUDZCDGAINSTEPTIME_MASK                  0x7
#define PMIC_RG_AUDZCDGAINSTEPTIME_SHIFT                 1
#define PMIC_RG_AUDZCDGAINSTEPSIZE_MASK                  0x3
#define PMIC_RG_AUDZCDGAINSTEPSIZE_SHIFT                 4
#define PMIC_RG_AUDZCDTIMEOUTMODESEL_MASK                0x1
#define PMIC_RG_AUDZCDTIMEOUTMODESEL_SHIFT               6
#define PMIC_RG_AUDZCDCLKSEL_VAUDP15_MASK                0x1
#define PMIC_RG_AUDZCDCLKSEL_VAUDP15_SHIFT               7
#define PMIC_RG_AUDZCDMUXSEL_VAUDP15_MASK                0x7
#define PMIC_RG_AUDZCDMUXSEL_VAUDP15_SHIFT               8
#define PMIC_RG_AUDLOLGAIN_MASK                          0x1F
#define PMIC_RG_AUDLOLGAIN_SHIFT                         0
#define PMIC_RG_AUDLORGAIN_MASK                          0x1F
#define PMIC_RG_AUDLORGAIN_SHIFT                         7
#define PMIC_RG_AUDHPLGAIN_MASK                          0x1F
#define PMIC_RG_AUDHPLGAIN_SHIFT                         0
#define PMIC_RG_AUDHPRGAIN_MASK                          0x1F
#define PMIC_RG_AUDHPRGAIN_SHIFT                         7
#define PMIC_RG_AUDHSGAIN_MASK                           0x1F
#define PMIC_RG_AUDHSGAIN_SHIFT                          0
#define PMIC_RG_AUDIVLGAIN_MASK                          0x7
#define PMIC_RG_AUDIVLGAIN_SHIFT                         0
#define PMIC_RG_AUDIVRGAIN_MASK                          0x7
#define PMIC_RG_AUDIVRGAIN_SHIFT                         8
#define PMIC_RG_AUDINTGAIN1_MASK                         0x3F
#define PMIC_RG_AUDINTGAIN1_SHIFT                        0
#define PMIC_RG_AUDINTGAIN2_MASK                         0x3F
#define PMIC_RG_AUDINTGAIN2_SHIFT                        8
#define PMIC_RSV_CON0_RSV_MASK                           0x1
#define PMIC_RSV_CON0_RSV_SHIFT                          0

#endif // #ifdef PMIC_6355_REG_API
#endif // #ifndef __DCL_PMIC6355_HW_H_STRUCT__

