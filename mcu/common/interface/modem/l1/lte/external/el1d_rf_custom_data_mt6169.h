/******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

/*==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
/* Doxygen Group Header ****************************************************//**
 * @addtogroup EL1D_RF_CUSTOM_DATA_MT6169
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @file       el1d_rf_public.h
 * @author     LY Chen (MTK04356)
 * @date       2014.12.16
 * @brief      EL1D RF Custom data for MT6169
 * @details    provide definition for MT6169
 ******************************************************************************/
  
#ifndef __EL1D_RF_CUSTOM_DATA_MT6169_H__
#define __EL1D_RF_CUSTOM_DATA_MT6169_H__

/*******************************************************************************
 * #include
 ******************************************************************************/


/*******************************************************************************
 * #define
 ******************************************************************************/

#if !defined(MT6169_RF)
   #error "rf files mismatch with compile option!"
#endif
/*--------------------------------------------------------*/


/*--------------------------------------------------------*/
/*   Specific Event Timing Define (Should not modified)   */
/*--------------------------------------------------------*/
#define TC_SR2G        MICROSECOND_TO_26M(5)     //Initial RX Gain & AFC
#define TC_SR2S        MICROSECOND_TO_26M(4)     //RX Bandwidth Switch
#define TC_SR2F        MICROSECOND_TO_26M(2)     //AFC update timing
#define TC_ST2S        MICROSECOND_TO_26M(5)     //TX Bandwidth Switch
#define TC_ST2F        MICROSECOND_TO_26M(10)    //TX AFC

//FPR0 & TPR0 are reserved for RF Conflict event
#define TC_FPR0        MICROSECOND_TO_26M(142)
#define TC_FPT0        MICROSECOND_TO_26M(142)
#define TC_TPR0        MICROSECOND_TO_26M(142)
#define TC_TPT0        MICROSECOND_TO_26M(142)

#define TC_FPR3B       MICROSECOND_TO_26M(0)     //reserved
#define TC_FPR3C       MICROSECOND_TO_26M(0)     //reserved

//To-Do: TPR3B is special event & should be larger than TC_TPT1
#define TC_TPR3B       MICROSECOND_TO_26M(22)
#define TC_TPR3C       MICROSECOND_TO_26M(0)

/*--------------------------------------------------------*/
/*   FDD Mode Event Timing Define (Should not modified)   */
/*--------------------------------------------------------*/
#define TC_FSR0        MICROSECOND_TO_26M(140)
#define TC_FSR1        MICROSECOND_TO_26M(135)
#define TC_FSR2        MICROSECOND_TO_26M(26)
#define TC_FSR3        MICROSECOND_TO_26M(12)

#define TC_FST0        MICROSECOND_TO_26M(125)
#define TC_FST1        MICROSECOND_TO_26M(125)
#define TC_FST2        MICROSECOND_TO_26M(9)
#define TC_FST3        MICROSECOND_TO_26M(0)

/*--------------------------------------------------------*/
/*   TDD Mode Event Timing Define                         */
/*--------------------------------------------------------*/
#define TC_SRX1        MICROSECOND_TO_26M(132)
#define TC_STX1        MICROSECOND_TO_26M(132)
#define TC_SRX3        MICROSECOND_TO_26M(10)
#define TC_STX3        MICROSECOND_TO_26M(10)

#define TC_TSR0        MICROSECOND_TO_26M(140)  //Off for Freq change
#define TC_TSR2        MICROSECOND_TO_26M(21)
#define TC_TSR3        MICROSECOND_TO_26M(1)

#define TC_TST2        MICROSECOND_TO_26M(9)
#define TC_TST3        MICROSECOND_TO_26M(1)


/*--------------------------------------------------------*/
/*   TPC Event Timing Define                              */
/*--------------------------------------------------------*/
#define TC_STPC0       MICROSECOND_TO_26M(4)   //TX Gain Slot0
#define TC_STPC1       MICROSECOND_TO_26M(0)   //reserved
#define TC_SPTPC0      MICROSECOND_TO_26M(26)  //PAVCC
#define TC_SPTPC1      MICROSECOND_TO_26M(0)   //reserved
#define TC_SMTPC0      MICROSECOND_TO_26M(4)   //PA Mode change of MIPI PA
#define TC_SMTPC1      MICROSECOND_TO_26M(0)   //reserved
#define TC_PTPC0       MICROSECOND_TO_26M(4) //VM mode change
#define TC_PTPC1       MICROSECOND_TO_26M(0) //reserved


/*--------------------------------------------------------*/
/*   TRX IO Setting Define                                */
/*--------------------------------------------------------*/
#define RX_IO_NON_USED     0xFF
#define RXD_IO_NON_USED    0xFF
#define TX_IO_NON_USED     0xFF

#define RX_IO_HB1          0
#define RX_IO_HB2          1
#define RX_IO_HB3          2
#define RX_IO_MB1          3
#define RX_IO_MB2          4
#define RX_IO_LB1          5
#define RX_IO_LB2          6
#define RX_IO_LB3          7

#define RXD_IO_HB1         0
#define RXD_IO_HB2         1
#define RXD_IO_HB3         2
#define RXD_IO_MB1         3
#define RXD_IO_MB2         4
#define RXD_IO_LB1         5
#define RXD_IO_LB2         6
#define RXD_IO_LB3         7

#define TX_IO_HB1          0
#define TX_IO_HB2          1
#define TX_IO_MB1          2
#define TX_IO_MB2          3
#define TX_IO_LB1          4
#define TX_IO_LB2          5
#define TX_IO_LB3          6
#define TX_IO_LB4          7

/*******************************************************************************
 * Typedef
 ******************************************************************************/

/*******************************************************************************
 * Constant
 ******************************************************************************/

/*******************************************************************************
 * Global variables (Extern)
 ******************************************************************************/




/*******************************************************************************
 * Global Functions Prototype (Interface)
 ******************************************************************************/


#endif /*__EL1D_RF_CUSTOM_DATA_MT6169_H__*/

/* Doxygen Group End ***************************************************//**@}*/
