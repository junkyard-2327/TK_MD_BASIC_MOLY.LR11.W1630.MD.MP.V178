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
 *    dcl_pmic6339_sw.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file is for PMIC 6339
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 ****************************************************************************/



#ifndef __DCL_PMU6339_SW_H_STRUCT__
#define __DCL_PMU6339_SW_H_STRUCT__

//define for PMIC6339 debug
#define PMIC_6339_DEBUG

#include "dcl_pmic_features.h"


// Combinational functions
void pmic6339_customization_init(void);
typedef enum
{
        CID0,
        ECO_VERSION,
        RG_VIO28_VOSEL,
        RG_VIO28_EN,
        RG_VUSB11_EN,
        RG_VCORE_VOSEL,
    RG_VRF18_MODESET,
    RG_VRF18_ON_CTRL,
    RG_VRF18_EN,
    VRF18_srclken_sel,
	RG_VRF18_2_MODESET,
	RG_VRF18_2_ON_CTRL,
	RG_VRF18_2_EN,
	VRF18_2_srclken_sel,
	RG_VPA_MODESET,
	VPA_VOSEL_MAP_EN,
        RG_VPA_EN, 
        VPA_VOSEL,
	RG_VRF18_BK_LDO,
	RG_VRF18_2_BK_LDO,
	RG_VSIM1_EN,
	RG_VSIM2_EN,
	RG_VSIM1_VOSEL,
	RG_VSIM2_VOSEL,
	RG_VMC_VOSEL,
	RG_VMC_EN,
	RG_VMCH_VOSEL,
	RG_VMCH_EN,
	RG_VMIPI_EN,
	VPA_TABLE0,
	VPA_TABLE1,
	VPA_TABLE2,
	VPA_TABLE3,
	VPA_TABLE4,
	VPA_TABLE5,
	VPA_TABLE6,
	VPA_TABLE7,
        VPA_MAP_SEL,
	PMU_FLAGS_LIST_MAX
}PMU_FLAGS_LIST_ENUM;


#endif // #ifndef __DCL_PMU6327_SW_H_STRUCT__

