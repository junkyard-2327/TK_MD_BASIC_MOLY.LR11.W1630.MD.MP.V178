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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   mml1_rf_cal_def.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   The definition of MML1 RF calibration
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MML1_RF_CAL_DEF_H
#define MML1_RF_CAL_DEF_H

#include "kal_general_types.h"


/*******************************************************************************
 * #define
 ******************************************************************************/
#ifdef TK6291_E1EVB
#define MMRFC_RX_IRR_COMP_ROUTE_MAX          4                            
#define MMRFC_RX_DC_COMP_ROUTE_MAX           MMRFC_RX_IRR_COMP_ROUTE_MAX  ///< Set maximum number as same as RXIRR
#define MMRFC_RX_IIP2_COMP_ROUTE_MAX         10
#define LTE_RX_IRR_COMP_ROUTE_MAX            MMRFC_RX_IRR_COMP_ROUTE_MAX  ///< Don't change for TK6291
#define LTE_RX_DC_COMP_ROUTE_MAX             MMRFC_RX_DC_COMP_ROUTE_MAX   ///< Don't change for TK6291
#else
#define MMRFC_RX_IRR_COMP_ROUTE_MAX          5                           
#define MMRFC_RX_DC_COMP_ROUTE_MAX           MMRFC_RX_IRR_COMP_ROUTE_MAX  ///< Set maximum number as same as RXIRR
#define MMRFC_RX_IIP2_COMP_ROUTE_MAX         11
#define LTE_RX_IRR_COMP_ROUTE_MAX            6                            ///< Only for LTE
#define LTE_RX_DC_COMP_ROUTE_MAX             LTE_RX_IRR_COMP_ROUTE_MAX    ///< Only for LTE
#endif
#define MMRFC_LTE_RX_CBW_NUM                 9   ///< 1.4, 3, 5, 10, 15, 20, 30, 35, 40MHz
#define MMRFC_LTE_TX_CBW_NUM                 6   ///< 1.4, 3, 5, 10, 15, 20MHz
#define MMRFC_UMTS_RX_CBW_NUM                3   ///< 5, 10, 15MHz
#define MMRFC_UMTS_TX_CBW_NUM                2   ///< 5, 10MHz
#define MMRFC_RXDC_TIA_GAIN_STEPS            2
#define MMRFC_RXDC_PGA_GAIN_STEPS            7   ///< Maximum numbers of PGA gains
#define MMRFC_RXDC_PGA_GAIN_LTE_STEPS        6   ///< Only 6 PGA gains are needed for LTE 
#define MMRFC_RXDC_PGA_GAIN_WCDMA_STEPS      7   ///< 7 PGA gains are needed for WCDMA 
#define MMRFC_RXDC_PGA_GAIN_TDSCDMA_STEPS    6   ///< Only 6 PGA gains are needed for TDSCDMA 
#define MMRFC_DET_FE_GAIN_STEPS              2
#define MMRFC_DET_GAIN_STEPS                 15
#define MMRFC_DET_SAMPLE_RATE_NUM            4
#define MMRFC_TX_PGA_A_SLICE_NUM             5
#define MMRFC_TX_PGA_B_SLICE_NUM             2
#define MMRFC_TX_PGA_SLICE_NUM               (MMRFC_TX_PGA_A_SLICE_NUM + MMRFC_TX_PGA_B_SLICE_NUM)
#define MMRFC_TX_RC_LPF_CBW_NUM              5
#define MMRFC_TX_DNL_PGA_A_GAIN_STEPS        21  ///< G0~G20
#define MMRFC_TX_DNL_PGA_B_GAIN_STEPS        10  ///< G12~G21
#define MMRFC_TX_DNL_PGA_AUX_GAIN_STEPS      7   ///< G22~G28
#define MMRFC_TX_DNL_PGA_A_SEQ_NUM           (MMRFC_TX_DNL_PGA_A_GAIN_STEPS - 1)//20  ///< Calibration sequence for PGA-A
#define MMRFC_TX_DNL_PGA_B_SEQ_NUM           (MMRFC_TX_DNL_PGA_B_GAIN_STEPS + MMRFC_TX_DNL_PGA_AUX_GAIN_STEPS - 1) //16  ///< Calibration sequence for PGA-B and PGA-AUX
#define MMRFC_TX_PGA_TYPE_NUM                3   ///< PGA-A, PGA-B, PGA-AUX
#define MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM   12
#define MMRFC_TX_PGA_GAIN_STEP_NUM           10  ///< G11a-G12b, G12a-G13b, G13a-G14b, G14a-G15b, G15a-G16b, G16a-G17b, G17a-G18b, G18a-G19b, G19a-G20b, G20a-G21b
#define MMRFC_TX_PGA_CAP_TUNING_SUBBAND_NUM  3   ///< 3 subband for B40/41

#define MMRFC_FILT_TAPS_NUM                  7   ///< maximum numbers of compensation filter taps 
#define MMRFC_TXGA_MAX_TONES                 10  ///< maximum numbers of test tones for TXGA
#define MMRFC_ANT_NUM                        2

/* Definition for LTE Re-CAL mechanism(debug use) */
#define MMPOC_LTE_RECAL_ENABLE (0)

#if MMPOC_LTE_RECAL_ENABLE
#define RECAL_ITER (2)
#define RECAL_ITER_RX_DCOC_TRACKING (3)
#else
#define RECAL_ITER (1)
#define RECAL_ITER_RX_DCOC_TRACKING (1)
#endif


/*   NOTE!!! This definition check part should be after MMPOC_LTE_RECAL_ENABLE definition      */
/*   If LTE RAT is not defined , remove all MMPOC LTE RECAL code , set param to default value  */
#ifndef __LTE_RAT__
#undef  MMPOC_LTE_RECAL_ENABLE
#undef  RECAL_ITER
#undef  RECAL_ITER_RX_DCOC_TRACKING

#define MMPOC_LTE_RECAL_ENABLE      (0)
#define RECAL_ITER                  (1)
#define RECAL_ITER_RX_DCOC_TRACKING (1)
#endif

/*******************************************************************************
 * Enum
 ******************************************************************************/
typedef enum{    
    MMRFC_TX_COMP_INDEX_0, /* PGA-A G0~G8     (Slice 8) */
    MMRFC_TX_COMP_INDEX_1, /* PGA-A G9        (Slice 7) */
    MMRFC_TX_COMP_INDEX_2, /* PGA-A G10~G11   (Slice 4) */
    MMRFC_TX_COMP_INDEX_3, /* PGA-A G12~G13   (Slice 2) */
    MMRFC_TX_COMP_INDEX_4, /* PGA-A G14~G20   (Slice 1) */
    MMRFC_TX_COMP_INDEX_5, /* PGA-B G12~G13   (Slice 2) */
    MMRFC_TX_COMP_INDEX_6, /* PGA-B G14~G20   (Slice 1) */
    MMRFC_TX_COMP_INDEX_7, /* PGA-AUX G21~G27 (Slice 1) */
} MMRFC_TX_COMP_INDEX_E;

typedef enum{    
    MMRFC_DET_TIA_COMP_INDEX_0, /* DET G0~G6 (TIA MID gain) */
    MMRFC_DET_TIA_COMP_INDEX_1, /* DET G7~G14(TIA LOW gain) */
} MMRFC_DET_TIA_COMP_INDEX_E;


#endif
