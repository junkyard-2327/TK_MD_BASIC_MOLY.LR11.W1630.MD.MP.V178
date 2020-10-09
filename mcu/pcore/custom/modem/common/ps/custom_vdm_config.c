/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2017
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
 *
 * Filename:
 * ---------
 *   custom_vdm_config.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file is used to define the VDM configuration.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/


#include "custom_vdm_config.h"


/*****************************************************************************
* FUNCTION
*   vdm_custom_disable_emergency_allow_ims
* DESCRIPTION
*   This function is used to define allow_ims for emergency call is disabled for
*   specific operator
* PARAMETERS
*   sim_sbp_id
* RETURNS
*   KAL_FALSE:default (read nvram)
    KAL_TRUE:allow_ims for emergency is disabled
*****************************************************************************/
kal_bool vdm_custom_disable_emergency_allow_ims(void)
{
    kal_uint8 imsi[9], mnc_length = 0;
    kal_uint16 mcc = 0, mnc = 0;

    l4csmu_get_imsi_by_idx((kal_uint8*) imsi, 0);
    mnc_length = sim_query_mnc_num(SIM1);

    mcc = (imsi[0]>>4)*100 + (imsi[1]&0x0f)*10 + (imsi[1]>>4);
    mnc = (imsi[2]&0x0f)*10 + (imsi[2]>>4);
    
    if (mnc_length == 3)
    {
        mnc = mnc*10 + (imsi[3]&0x0f);
    }
    else
    {
        // treat the length of mnc is 2 because some SIM card don't have MNC length value in the EF_AD.
    }

    /* disable emergency allow_ims according to MCC/MNC */

    if ( ((mcc == 238) && (mnc == 01)) ||
         ((mcc == 238) && (mnc == 10)) )
    {
        return KAL_TRUE; // Denmark TDC
    }
    else if ( ((mcc == 466) && (mnc == 89)) ||
              ((mcc == 466) && (mnc == 90)) )
    {
        return KAL_TRUE; // T-star
    }
    else if ( ((mcc == 204) && (mnc == 16)) ||
              ((mcc == 204) && (mnc == 20)) )
    {
        return KAL_TRUE; // Telekom (T-Moble) Netherlands
    }
    else if ((mcc == 204) && (mnc == 02))
    {
        return KAL_TRUE; // Tele2 Netherlands
    }
    else if ((mcc == 246) && (mnc == 01))
    {
        return KAL_TRUE; // Telia Lithuania
    }
    else if ((mcc == 206) && (mnc == 01))
    {
        return KAL_TRUE; // Proximus Belgium
    }
    else if ((mcc == 655) && (mnc == 02))
    {
        return KAL_TRUE; // Telkom South Afr
    }
    else if ((mcc == 722) && (mnc == 07))
    {
        return KAL_TRUE; // MoviStar Argentina
    }
    else if ((mcc == 730) && (mnc == 03))
    {
        return KAL_TRUE; // Claro Chile
    }
    else if ((mcc == 732) && (mnc == 123))
    {
        return KAL_TRUE; // Movistar Colombia
    }
    else if ((mcc == 740) && (mnc == 00))
    {
        return KAL_TRUE; // Movistar Ecuador
    }
    else if ((mcc == 334) && (mnc == 030))
    {
        return KAL_TRUE; // Movistar Mexico
    }
    else if ((mcc == 250) && (mnc == 99))
    {
        return KAL_TRUE; // Beeline Russia
    }
    else /* default */
    {
        return KAL_FALSE;
    }

}


/*****************************************************************************
* FUNCTION
*   vdm_custom_disable_emergency_allow_wfc
* DESCRIPTION
*   This function is used to define allow_wfc for emergency call is disabled for
*   specific operator
* PARAMETERS
*   NONE
* RETURNS
*   KAL_FALSE:default (read nvram)
    KAL_TRUE:allow_ims for emergency is disabled
*****************************************************************************/
kal_bool vdm_custom_disable_emergency_allow_wfc(void)
{
    kal_uint8 imsi[9], mnc_length = 0;
    kal_uint16 mcc = 0, mnc = 0;

    l4csmu_get_imsi_by_idx((kal_uint8*) imsi, 0);
    mnc_length = sim_query_mnc_num(SIM1);

    mcc = (imsi[0]>>4)*100 + (imsi[1]&0x0f)*10 + (imsi[1]>>4);
    mnc = (imsi[2]&0x0f)*10 + (imsi[2]>>4);
    
    if (mnc_length == 3)
    {
        mnc = mnc*10 + (imsi[3]&0x0f);
    }
    else
    {
        // treat the length of mnc is 2 because some SIM card don't have MNC length value in the EF_AD.
    }

    /* disable emergency allow_ims according to MCC/MNC */
    if ((mcc == 216) && (mnc == 01))
    {
        return KAL_TRUE; // Telenor Hungary
    }
    else if ((mcc == 655) && (mnc == 02))
    {
        return KAL_TRUE; // Telkom South Afr
    }
    else if ((mcc == 716) && (mnc == 06))
    {
        return KAL_TRUE; // Movistar Peru
    }
    else if ((mcc == 730) && (mnc == 02))
    {
        return KAL_TRUE; // Movistar Chile
    }
    else if ((mcc == 515) && (mnc == 03))
    {
        return KAL_TRUE; // Smart Philippines
    }
    else if ((mcc == 655) && (mnc == 10))
    {
        return KAL_TRUE; // MTN ZA South Africa
    }
    else if ((mcc == 722) && (mnc == 07))
    {
        return KAL_TRUE; // MoviStar Argentina
    }
    else if ((mcc == 730) && (mnc == 03))
    {
        return KAL_TRUE; // Claro Chile
    }
    else if ((mcc == 732) && (mnc == 123))
    {
        return KAL_TRUE; // Movistar Colombia
    }
    else if ((mcc == 740) && (mnc == 00))
    {
        return KAL_TRUE; // Movistar Ecuador
    }
    else if ((mcc == 334) && (mnc == 030))
    {
        return KAL_TRUE; // Movistar Mexico
    }
    else if ((mcc == 250) && (mnc == 99))
    {
        return KAL_TRUE; // Beeline Russia
    }
    else if ((mcc == 216) && (mnc == 03))
    {
        return KAL_TRUE; // Digi Hungary
    }
    else /* default */
    {
        return KAL_FALSE;
    }
}
