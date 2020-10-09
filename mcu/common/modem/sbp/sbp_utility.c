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
 * sbp_utility.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file is intends for SBP definition
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
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
 * removed!
 *
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
 *
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
 *
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
 *
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
 * removed!
 *
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
 *
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
 *
 * removed!
 * removed!
 *
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
 *
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
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 *
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
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define SBP_UTILITY_C

#include "kal_general_types.h"
#include "sbp_public_utility.h"
#include "kal_public_api.h"
#include "ps_em_enum.h"
#include "nvram_interface.h"
#include "nvram_data_items.h"
#include "nvram_enums.h"
#include "nvram_editor_data_item.h"
#include "sim_ps_api.h"
#include "custom_imc_config.h"

extern sim_interface_enum l4c_gemini_get_actual_sim_id(sim_interface_enum simId);
extern ps_conf_test_mode_enum query_ps_conf_test_mode(void);
kal_bool nvram_custom_config_rrc_dynamic_cap(kal_uint32 sbp_id);
kal_bool nvram_custom_config_rrc_band_priority_order(kal_uint32 sbp_id);

/*MTK08505: This part is to declare the functions and data structures for NVRAM Reset 
      if the SBP ID changes from previous after the boot up*/
void nvram_custom_reset_mscap();
void nvram_custom_reset_rrc_dynamic_cap();
void custom_nvram_reset_regional_phone_mode();
void custom_nvram_reset_ltecsr_profile();
#ifdef __LTE_RAT__
void nvram_custom_reset_errc_para();
void custom_nvram_reset_lte_pref();
#endif

#ifdef __VOLTE_SUPPORT__
void nvram_custom_reset_vdm_ads_profile();
#endif /* __VOLTE_SUPPORT__ */

void custom_reset_nvram_lids(kal_uint32 sbp_id);

typedef void(*SBP_RESET_NVRAM_LID)();

typedef struct{
	SBP_RESET_NVRAM_LID sbp_reset_nvram_lid_funcptr;
}sbp_nvram_lid_reset_table;

sbp_nvram_lid_reset_table nvram_lid_reset_func_tbl[]={
	    nvram_custom_reset_mscap,
		nvram_custom_reset_rrc_dynamic_cap,
		custom_nvram_reset_regional_phone_mode,
#ifdef __VOLTE_SUPPORT__
		nvram_custom_reset_vdm_ads_profile,
#endif
#ifdef __LTE_RAT__        
		nvram_custom_reset_errc_para,
		custom_nvram_reset_lte_pref,
		custom_nvram_reset_ltecsr_profile
#endif  

};
/* MTK08505: NVRAM RESET Declaration ends here*/

#define SBP_TEST_MODE 8286
#define ERRC_FGI_01      0x80000000
#define ERRC_FGI_03      0x20000000
#define ERRC_FGI_07      0x02000000
#define ERRC_FGI_08      0x01000000
#define ERRC_FGI_09      0x00800000
#define ERRC_FGI_10      0x00400000
#define ERRC_FGI_23      0x00000200
#define ERRC_FGI_27      0x00000020
#define ERRC_FGI_28      0x00000010
#define ERRC_FGI_29      0x00000008
#define ERRC_FGI_31      0x00000002
#define ERRC_FGI_34      0x40000000
#define ERRC_FGI_108     0x01000000



kal_uint32 old_sbp_id = 0;
kal_uint32 sbp_sub_id = 0;

#if defined(__PCORE__)
kal_uint32 default_sbp_id = 0;
kal_uint32 ims_operator_code[MAX_SIM_NUM] = {0};
nvram_ef_sbp_modem_config_struct sbp_config;
nvram_ef_sbp_modem_data_config_struct sbp_data_config;

DEFINE_NC_SHARED_VAR(nvram_ef_sbp_modem_config_struct, sbp_config_shared)
DEFINE_NC_SHARED_VAR(nvram_ef_sbp_modem_data_config_struct, sbp_data_config_shared)
#elif defined(__L1CORE__)
DEFINE_NC_SHARED_VAR(nvram_ef_sbp_modem_config_struct, sbp_config_shared)
DEFINE_NC_SHARED_VAR(nvram_ef_sbp_modem_data_config_struct, sbp_data_config_shared)
#endif

#if defined (__MOD_IMC__)
kal_bool nvram_custom_config_ims_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id);
kal_bool nvram_custom_config_ltecsr_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id);
static kal_bool convert_mcc_mnc_from_imsi(kal_uint8* mccmnc, kal_uint8* imsi);
#endif /* __MOD_IMC__ */

#ifdef __VOLTE_SUPPORT__
kal_bool nvram_custom_config_sdm_ads_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id);
kal_bool nvram_custom_config_vdm_ads_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id);
#endif /* __VOLTE_SUPPORT__ */

#ifdef __LTE_RAT__
void custom_nvram_set_errc_para(kal_uint32 sbp_id);
void custom_nvram_set_lte_pref(kal_uint32 sbp_id);
#endif

const mccmnc_to_sbp_id_struct mcc_mnc_to_sbp_id_table[] = {
    {"46000", SBP_ID_CMCC}, 
    {"46001", SBP_ID_CU}, 
    {"310170",SBP_ID_ATT} 
};




/*****************************************************************************
 * FUNCTION
 *  sbp_is_test_mode
 *
 * DESCRIPTION
 * Set SBP to test mode.
 * In test mode, we read current values of nvram files instead of using default values before applying SBP settings.
 *
 * PARAMETERS
 *  [IN]    N/A
 * RETURNS
 *   KAL_TRUE    : SBP is in test mode
 *   KAL_FALSE   : SBP is not in test mode
 *****************************************************************************/

kal_bool sbp_is_test_mode (void)
{
    nvram_ef_sbp_modem_data_config_struct sbp_data_buf;

    nvram_external_read_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                             1, 
                             (kal_uint8*)&sbp_data_buf, 
                             NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);

    if (SBP_TEST_MODE == sbp_data_buf.sbp_mode)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}


/*****************************************************************************
* FUNCTION
*   sbp_query_md_feature()
*
* DESCRIPTION
*   This function is used to query modem configuration
*
* PARAMETERS
*   feature [IN]    modem feature
*
* RETURNS
*   KAL_TRUE    : if this feature is turned on
*   KAL_FALSE   : if this feature is turned off
*****************************************************************************/
kal_bool sbp_query_md_feature(sbp_md_feature_enum feature)
{
    kal_uint8 *bitmask_ptr;
    kal_uint32 byte_offset;
    kal_uint8 bit_offset;
    kal_bool result;

#if defined(__L1CORE__)
    nvram_ef_sbp_modem_config_struct sbp_config = SHARED_VAR(sbp_config_shared);
#endif

    if (feature >= SBP_MAX_MD_FEATURE)
    {
        ASSERT(0);
    }
    byte_offset = feature / 8;
    bit_offset = feature % 8;
    bitmask_ptr = &(sbp_config.modem_sbp_config[byte_offset]);

    result = (((*bitmask_ptr) & (0x01 << bit_offset)) != 0)? KAL_TRUE : KAL_FALSE;

    //For GCF or other test modes, you may overwrite the result.
    result = sbp_md_feature_overwrite(feature, result);
    
    return result;
}


/*****************************************************************************
* FUNCTION
*   sbp_query_md_feature_no_overwrite()
*
* DESCRIPTION
*   This function is used to query modem configuration without overwrite
*
* PARAMETERS
*   feature [IN]    modem feature
*
* RETURNS
*   KAL_TRUE    : if this feature is turned on
*   KAL_FALSE   : if this feature is turned off
*****************************************************************************/
kal_bool sbp_query_md_feature_no_overwrite(sbp_md_feature_enum feature)
{
    kal_uint8 *bitmask_ptr;
    kal_uint32 byte_offset;
    kal_uint8 bit_offset;
    kal_bool result;

#if defined(__L1CORE__)
    nvram_ef_sbp_modem_config_struct sbp_config = SHARED_VAR(sbp_config_shared);
#endif

    if (feature >= SBP_MAX_MD_FEATURE)
    {
        ASSERT(0);
    }
    byte_offset = feature / 8;
    bit_offset = feature % 8;
    bitmask_ptr = &(sbp_config.modem_sbp_config[byte_offset]);

    result = (((*bitmask_ptr) & (0x01 << bit_offset)) != 0)? KAL_TRUE : KAL_FALSE;
    
    return result;
}


/*****************************************************************************
* FUNCTION
*   sbp_set_md_feature()
*
* DESCRIPTION
*   This function is used to set modem configuration
*
* PARAMETERS
*   feature         [IN]    modem feature
*   is_turned_on    [IN]
*   sbp_feature_ptr [IN/OUT]
*
* RETURNS
*   KAL_TRUE if success; otherwise KAL_FALSE
*****************************************************************************/
kal_bool sbp_set_md_feature(sbp_md_feature_enum feature,
                            kal_bool is_turned_on, 
                            nvram_ef_sbp_modem_config_struct *sbp_feature_ptr)
{
    kal_uint8 *bitmask_ptr;
    kal_uint32 byte_offset;
    kal_uint8 bit_offset;
    

    if (feature >= SBP_MAX_MD_FEATURE)
    {
        return KAL_FALSE;
    }
    else
    {
        byte_offset = feature / 8;
        bit_offset = feature % 8;
        bitmask_ptr = &(sbp_feature_ptr->modem_sbp_config[byte_offset]);
        if (is_turned_on == KAL_TRUE)
        {
            *bitmask_ptr = ((*bitmask_ptr) | (0x01 << bit_offset));
        }
        else
        {
            *bitmask_ptr = ((*bitmask_ptr) & ~(0x01 << bit_offset));
        }
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
* FUNCTION
*   sbp_query_md_feature_data()
*
* DESCRIPTION
*   This function is used to query modem configuration data
*
* PARAMETERS
*   feature [IN]    modem feature
*
* RETURNS
*   the unsigned byte value for the feature
*****************************************************************************/
kal_uint8 sbp_query_md_feature_data(sbp_md_feature_data_enum feature)
{
    kal_uint8 result;

#if defined(__L1CORE__)
    nvram_ef_sbp_modem_data_config_struct sbp_data_config = SHARED_VAR(sbp_data_config_shared);
#endif

    if (feature >= SBP_DATA_MAX_MD_FEATURE)
    {
        ASSERT(0);
    }
    
    result = sbp_data_config.modem_sbp_data_config[feature];

    //For GCF or other test modes, you may overwrite the result.
    result = sbp_md_feature_data_overwrite(feature, result);

    return result;
}


/*****************************************************************************
* FUNCTION
*   sbp_query_md_feature_data_no_overwrite()
*
* DESCRIPTION
*   This function is used to query modem configuration data without overwrite
*
* PARAMETERS
*   feature [IN]    modem feature
*
* RETURNS
*   the unsigned byte value for the feature
*****************************************************************************/
kal_uint8 sbp_query_md_feature_data_no_overwrite(sbp_md_feature_data_enum feature)
{
    kal_uint8 result;

#if defined(__L1CORE__)
    nvram_ef_sbp_modem_data_config_struct sbp_data_config = SHARED_VAR(sbp_data_config_shared);
#endif

    if (feature >= SBP_DATA_MAX_MD_FEATURE)
    {
        ASSERT(0);
    }
    
    result = sbp_data_config.modem_sbp_data_config[feature];

    return result;
}


/*****************************************************************************
* FUNCTION
*   sbp_set_md_feature_data()
*
* DESCRIPTION
*   This function is used to set modem configuration data
*
* PARAMETERS
*   feature [IN]    modem feature
*
* RETURNS
*   the unsigned byte value for the feature
*****************************************************************************/
kal_bool sbp_set_md_feature_data(sbp_md_feature_data_enum feature, 
                                 kal_uint8 data, 
                                 nvram_ef_sbp_modem_data_config_struct *sbp_data_ptr)
{
    if (feature >= SBP_DATA_MAX_MD_FEATURE)
    {
        return KAL_FALSE;
    }
    else
    {
        sbp_data_ptr->modem_sbp_data_config[feature] = data;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
* FUNCTION
*   sbp_md_feature_overwrite()
*
* DESCRIPTION
*   This function is used to overwrite the configuration for GCF or other test modes
*
* PARAMETERS
*   feature [IN]    modem feature
*   enabled [IN]   feature is turned on or not 
*
* RETURNS
*   KAL_TRUE    : if this feature is turned on
*   KAL_FALSE   : if this feature is turned off
*****************************************************************************/
kal_bool sbp_md_feature_overwrite(sbp_md_feature_enum feature, kal_bool enabled)
{
    kal_bool result = enabled;
    
    switch (feature)
    {
        
        case SBP_UMTS_CB_OFF:
            {
                // This is an example of overwriting the configuration for FTA
                // if(query_ps_conf_test_mode() == PS_CONF_TEST_FTA)
                //     result = KAL_TRUE;
            }
            break;
        
        case SBP_IS_OP07:
        case SBP_FINGERPRINT:
            {
                if(query_ps_conf_test_mode() == PS_CONF_TEST_FTA)
                     result = KAL_FALSE;
            }
            break;

        default:
            break;
    }

    return result;
}


/*****************************************************************************
* FUNCTION
*   sbp_md_feature_data_overwrite()
*
* DESCRIPTION
*   This function is used to overwrite the configuration for GCF or other test modes
*
* PARAMETERS
*   feature [IN]    modem feature
*   value [IN]       the value of the feature 
*
* RETURNS
*   the overwrited value for the feature
*****************************************************************************/
kal_uint8 sbp_md_feature_data_overwrite(sbp_md_feature_data_enum feature, kal_uint8 value)
{
    kal_uint8 result = value;
    
    switch (feature)
    {           
        case SBP_DATA_VAMOS:
            {
                // This is an example of overwriting the configuration for FTA         
                // if(query_ps_conf_test_mode() == PS_CONF_TEST_FTA)
                //     result = 3;
            }
            break;
        
        default:
            break;
    }

    return result;
}


/*****************************************************************************
* FUNCTION
*   sbp_query_id()
*
* DESCRIPTION
*   This function is used to query SBP ID received by modem
*
* PARAMETERS
*   [IN]    N/A
*
* RETURNS
*   the unsigned 4-byte value for the SBP ID
*****************************************************************************/
kal_uint32 sbp_query_id(void)
{
#if defined(__L1CORE__)
    nvram_ef_sbp_modem_config_struct sbp_config = SHARED_VAR(sbp_config_shared);
#endif

    return sbp_config.sbp_mode;
}


/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_sbp_id
 * DESCRIPTION
 * Set SBP features and data according to SBP ID.
 * PARAMETERS
 *  sbp_mode  [IN]
 * RETURNS
 *   KAL_TRUE    : Set SBP ID successfully
 *   KAL_FALSE   : Error happens when setting SBP ID
 *****************************************************************************/
kal_bool custom_nvram_set_sbp_id(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id)
{
    nvram_ef_sbp_modem_config_struct *default_sbp_feature = NULL;
    nvram_ef_sbp_modem_config_struct sbp_feature_buf;
    nvram_ef_sbp_modem_data_config_struct *default_sbp_data_buf = NULL;
    nvram_ef_sbp_modem_data_config_struct sbp_data_buf;

    if (sbp_id != SBP_ID_INVALID && ps_id != PROTOCOL_1)
    {
        /* For Dual IMS, IMC/LTECSR/VDM/SDM has multiple record in NV LID */
    #if defined (__MOD_IMC__)
        nvram_custom_config_ltecsr_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
        nvram_custom_config_ims_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
    #endif

    #ifdef __VOLTE_SUPPORT__
        nvram_custom_config_vdm_ads_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id); 
        nvram_custom_config_sdm_ads_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
    #endif
    }
    else if (sbp_id != SBP_ID_INVALID && ps_id == PROTOCOL_1)
    {
        if ((KAL_FALSE == sbp_is_test_mode())&&
            (NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_SBP_MODEM_CONFIG_LID, 1, (kal_uint8**)&default_sbp_feature)))
        {
            /* Reset to the default value first */
            kal_mem_cpy(&sbp_feature_buf, default_sbp_feature, sizeof(nvram_ef_sbp_modem_config_struct));
        }
        else
        {
            /* Read current settings in NVRAM */
            nvram_external_read_data(NVRAM_EF_SBP_MODEM_CONFIG_LID, 
                                     1,
                                     (kal_uint8*)&sbp_feature_buf, 
                                     NVRAM_EF_SBP_MODEM_CONFIG_SIZE);
        }

        if ((KAL_FALSE == sbp_is_test_mode())&&
            (NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 1, (kal_uint8**)&default_sbp_data_buf)))
        {
            kal_uint8 world_mode;   // world_mode is set by AP project config, could not reset to default by Dynamic SBP

            world_mode = sbp_query_md_feature_data(SBP_WORLD_MODE);

            if (world_mode == 0) 
                world_mode = DEFAULT_WORLD_MODE_ID; //Set it to default value to avoid world mode = 0 in modem only load. Because no world mode from CCCI

            sbp_set_md_feature_data(SBP_WORLD_MODE, world_mode, default_sbp_data_buf);
                        
            /* Reset to the default value first */
            kal_mem_cpy(&sbp_data_buf, default_sbp_data_buf, sizeof(nvram_ef_sbp_modem_data_config_struct));
        }
        else
        {
            /* Read current settings in NVRAM */
            nvram_external_read_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                                     1,
                                     (kal_uint8*)&sbp_data_buf, 
                                     NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);
        }
        
       	custom_reset_nvram_lids(sbp_id);// this will reset the NVRAM LIDs if the SBP ID is changed from previous one
        sbp_feature_buf.sbp_mode = sbp_id;
        
        /* Update related NVRAM files */        
        {

        #ifdef __VOLTE_SUPPORT__
            nvram_custom_config_vdm_ads_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id); 
        #endif

#if defined (__MOD_IMC__)
            if(sbp_id != 0)
            {
                nvram_custom_config_ltecsr_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
                nvram_custom_config_ims_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
            }
#endif /* __MOD_IMC__ */     

            if (sbp_id == 0) //OM
            {
                sbp_set_md_feature(SBP_DISABLE_DISPLAY_ROAMING_HPLMN_IN_EPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);    
            }
            else if (sbp_id == 1) //for CMCC
            {
                sbp_set_md_feature(SBP_OP01_TEST_MODE_CONSIDER_SIM, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_OP01_AT_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_PREFER_SEARCH_3G, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_PREFER_SEARCH_4G, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);                
                sbp_set_md_feature(SBP_OP01_COMMON_FEATURE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_RESUME_GPRS_AFTER_LU_ABNORMAL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_WRAP_AROUND_INT_FAIL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                #ifndef __MULTIPLE_IMS_SUPPORT__
                sbp_set_md_feature(SBP_VDM_REDIAL_IMS_VT_TO_CS_VOICE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                #endif

                sbp_set_md_feature(SBP_SDM_RETRY_CS_WHEN_IMS_SEND_FAIL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SDM_ALWAYS_CS_WHEN_2G, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SDM_ALWAYS_CS_WHEN_3G, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_EMM_IGNORE_MT_CS_WHEN_IMS_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_CMHK_CUSTOMIZE_EPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_RAC_CHANGE_VDP_WHEN_IMS_ONOFF, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_CMCC_VOLTE_FT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_PLMN_SEARCH_ABORT_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_CUSTOM_FPLMN_USED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                sbp_set_md_feature(SBP_CMCC_SRVCC_CDRX_EHEN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SRVCC_STOP_UAS_MEAS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SRVCC_DRX_INC_GAP, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SRVCC_STOP_EAS_MEAS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_REL_12_EPLMN_LIST_HANDLING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_HSR_ENHANCE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_DISALLOW_SRVCC_HO_WO_VOLTE_CALL, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
#if defined(__LTE_EPLMN_SEARCH__)
                sbp_set_md_feature(SBP_LTE_EPLMN_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
#endif
                sbp_set_md_feature(SBP_IMCSMS_RETRY_FOR_202_REV_OR_NOT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_OP01_SIM_LOCK, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                sbp_set_md_feature(SBP_EARLY_IMPLEMENT_FREQ_BAND_PRIO_ADJUST, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_CMCC_VOLTE_HST, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
#ifdef __VOLTE_SUPPORT__
				nvram_custom_config_sdm_ads_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
#endif /* __VOLTE_SUPPORT__ */
            }
            else if (sbp_id == 2) // for CU
            {
            }
            else if (sbp_id == 3) //for Orange
            {
#ifdef __LTE_RAT__
                custom_nvram_set_errc_para(sbp_id);
#endif	

                sbp_set_md_feature(SBP_HPPLMN_REGARDLESS_ANY_MCC, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_RPLMN_FROM_GLOCI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ORANGE_H_PLUS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                #ifdef __LTE_RAT__
                sbp_set_md_feature(SBP_OMIT_ESM_INFORMATION_FLAG, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                #endif
                sbp_set_md_feature(SBP_ORANGE_HPPLMN_DEFAULT_TIMER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_PREFER_SEARCH_4G, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_PREFER_SEARCH_3G, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SDM_RETRY_IMS_WHEN_CS_SEND_FAIL, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SEARCH_NOT_PREFERRED_AVAILABLE_PLMN, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_HSPA_TO_LTE_FAST_RESEL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf); 
                
                
                nvram_custom_config_rrc_dynamic_cap(sbp_id);

#ifdef __LTE_RAT__
                custom_nvram_set_lte_pref(sbp_id);
#endif

#ifdef __VOLTE_SUPPORT__
				// update SDM ADS profile
				nvram_custom_config_sdm_ads_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
#endif 
            }
            else if (sbp_id == 5) //For DTAG
            {
            }
            else if (sbp_id == 6) //for Vodafone
            {
                nvram_ef_regional_phone_mode_struct regional_phone_mode;
                
                regional_phone_mode.mode = 1;
                nvram_external_write_data(NVRAM_EF_REGIONAL_PHONE_MODE_LID, 
                                          1, 
                                          (kal_uint8*)&regional_phone_mode, 
                                          NVRAM_EF_REGIONAL_PHONE_MODE_SIZE);
                
                sbp_set_md_feature(SBP_MM_TRY_ABNORMAL_LAI_ONCE_MORE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_USE_SM_QOS_SUBSCRIBED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_RPLMN_FROM_HISTORY_TABLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_IMS_PDN_IGNORE_IPV4V6_FALLBACK_FOR_SPECIFIC_CAUSES, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*) &sbp_feature_buf);
            }
            else if (sbp_id == 7 || sbp_id == 145) //for AT&T and Cricket
            {
			    /* Cricket is sub branding of AT&T and has almost all features common to AT&T. 
			       Please check if your feature is common to both the operators, 
			       or specific to AT&T or Cricket and set/reset accordingly
                   if any question for your feature, please find ATT/Cricket spec PM to confirm*/

			
			    /* Features common for AT&T and Cricket both */
#ifdef __LTE_RAT__
                custom_nvram_set_errc_para(sbp_id);
#endif				
                sbp_set_md_feature(SBP_IS_OP07, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_USIM_CSP_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ENS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ENS_RAT_BALANCING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ATNT_HPPLMN_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_AUTO_RETURN_PRE_RPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_RPLMN_FROM_GLOCI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_AT_ME_IDENTIFICATION_WITHOUT_HEADER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SAT_NO_EVDL_IN_SESSION, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_IMEI_LOCK_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_STAR_SHORT_STRING_AS_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_CUSTOMIZED_IDLE_STRING_AS_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_MM_DISABLE_RETRY_ABNORMAL_LAI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_MM_NOT_TRY_ANOTHER_RAT_FOR_LU_ABNORMAL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SAT_REISSUE_REFRESH_AFTER_CALL_END, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ALLOW_SIM_REFRESH_RESET_WHEN_IN_CALL, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_IS_ATT_CONN_REJ, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                sbp_set_md_feature(SBP_CONSERVATIVE_IPV4V6_FALLBACK_STRATEGY, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_REPORT_CSG_LIST_IN_SIGNAL_DECREASING_ORDER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_IS_ATT_CONN_REJ, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_CLEAR_LOCI_WHEN_UICC_RESET, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SDM_TRY_CS_WHEN_2G_VOICE_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SDM_RETRY_CS_WHEN_IMS_SEND_FAIL, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_USER_REQ_NOT_INIT_MM_PROC_WHEN_ABNORMAL_T3212_RUNNING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_USER_REQ_NOT_INIT_GMM_PROC_WHEN_ABNORMAL_T3302_RUNNING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_EUTRAN_AFTER_NO_SUITABLE, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_CSFB_PAGE_CSMT, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_TCM_QOS_SIG_IND_ENABLED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SAT_REISSUE_REFRESH_WHEN_UE_IDLE_AFTER_CALL_END, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SAT_REISSUE_REFRESH_AFTER_SMS_ACK, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISCARD_MTSMS_WITH_SIM_DATA_DOWNLOAD_AND_DCS_NOT_0XF6, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_MMS_TIMER_BY_DEFAULT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf); 
                sbp_set_md_feature(SBP_DISABLE_B17_IN_B12MFBI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);                
                sbp_set_md_feature(SBP_SDM_IMS_SMART_CONGESTION_REPORT_TO_AP, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf); 
				sbp_set_md_feature(SBP_WAIT_RRC_CONN_REL_FOR_SET_RAT_MODE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_MM_IMSI_DETACH_WHEN_MM_CONN_ACTIVE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);				
                sbp_set_md_feature(SBP_R11_COMB_BUT_EPS_ABNORMAL_HANDLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
	            sbp_set_md_feature(SBP_EL1C_OPT_OP08_MEAS_TEST, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_3G_CSG, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_HSPA_TO_LTE_FAST_RESEL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_CHANGE_REALTIME_TRAFFIC_CLASS_TO_BACKGROUND, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);                      	
				// EMAC will keep reporting VSR to speech driver after HO for ATT and Cricket. Speech driver will reset DSP silently in these 2 operator.
				sbp_set_md_feature(SBP_VOLTE_NO_VSR_AFTER_HO, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_BAND_SCAN_PRIORITY, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_EARLY_IMPLEMENT_FREQ_BAND_PRIO_ADJUST, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf); 

                #ifndef __MULTIPLE_IMS_SUPPORT__
                sbp_set_md_feature(SBP_IS_ACCESS_BARRING_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                #endif

#ifdef __VOLTE_SUPPORT__
                // update SDM ADS profile
                nvram_custom_config_sdm_ads_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
#endif        
                // AT&T & Cricket both need to wait for IMS dereg before doing LTE detach
                sbp_set_md_feature(SBP_SIM_DETACH_WAIT_FOR_IMS_DEREG, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_INFORM_ECC_CALL_SESSION, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                // AT&T E911 call attempting to leave flight mode, setup RRC connection with cause emergency
                // [CMW 500][AT&T][LTE-BTR-1-8901]&[LTE-BTR-1-8902]
                sbp_set_md_feature(SBP_EMM_EMC_EST_CONNECTION, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

				/*Features specific to Cricket Only*/
				if( sbp_id == 145)
				{					
					sbp_set_md_feature(SBP_LTE_CA, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
					sbp_set_md_feature(SBP_3G_CSG, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);      
					sbp_set_md_feature(SBP_DISABLE_4G_CSG, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);    
				}

				/*Features specific to AT&T Only*/
				else if( sbp_id == 7)
				{
				    
				}
            }
            else if (sbp_id == 8) //for T-Mobile
            {
#ifdef __LTE_RAT__
                custom_nvram_set_errc_para(sbp_id);
#endif
                sbp_set_md_feature(SBP_TMO_US_SPECIFIC_CQI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                sbp_set_md_feature(SBP_ATNT_HPPLMN_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_TMO_PLMN_MATCHING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_TMO_ECC_NOTIFICATION_ENABLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_USE_SM_QOS_SUBSCRIBED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_EMR_REPORTING_WITH_SI2Q_BSIC_PARA, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_MM_NOT_STAY_ON_FBLA_FOR_REG_PROV, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_NO_OPTIONAL_RAU_AFTER_CCO_FAILURE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_GSMA_NETWORK_ACCESS_CONTROL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_TMO_IRAT_SET_ACTIVE_FLAG, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                /* If require TMO SML support, please unmask the following code */
                //sbp_set_md_feature(SBP_TMO_REMOTE_SIM_LOCK, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                sbp_set_md_feature(SBP_AMR_WB_GSM, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_AMR_WB_UMTS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SDM_RETRY_CS_WHEN_IMS_SEND_FAIL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_TMOUS_VOLTE_FT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_LU_BEFORE_CSFB_ECC_IF_LAI_DIFF, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SET_FOLLOW_ON_REQUEST_FOR_IMS_PDP, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_NOT_REPORT_IMS_UL_DATA_STATUS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_BEFORE_RINGING_CSFB, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                #ifndef __MULTIPLE_IMS_SUPPORT__
                sbp_set_md_feature(SBP_VDM_REDIAL_IMS_VT_TO_CS_VOICE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_VDM_REVERT_TO_CELLULAR_FOR_ECC, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ECBM_ENABLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature_data(SBP_ECBM_MODE_TIMER_SEC, 0, (nvram_ef_sbp_modem_data_config_struct*)&sbp_data_buf);
                sbp_set_md_feature_data(SBP_ECBM_MODE_TIMER_MIN, 3, (nvram_ef_sbp_modem_data_config_struct*)&sbp_data_buf);
                sbp_set_md_feature(SBP_ALLOW_WFC_CELLULAR_PREFER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                #endif

                sbp_set_md_feature(SBP_4G23_LOCAL_REL_IMS_PDN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
	            sbp_set_md_feature(SBP_EL1C_OPT_OP08_MEAS_TEST, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_MM_SKIP_LU_AFTER_CSFB_FOR_EAFR, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_EMM_CONN_FAIL_ABNORMAL_B, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_EARLY_IMPLEMENT_FREQ_BAND_PRIO_ADJUST, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_CUSTOM_FOR_BIT_SETTING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf); 

#if defined (__MOD_IMC__)
                /* TMO GBA flag checking in ISIM */
                sbp_set_md_feature(SBP_TMO_GBA, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
#endif /* __MOD_IMC__ */  
#ifdef __SCM_SUPPORT__
				sbp_set_md_feature(SBP_SCM_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_DISABLE_VOICE_SERVICE_CAUSE_IND_CHK, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf); //TMO request to disable report est-cause = mo-VoiceCall in MR4
#endif  /* __SCM_SUPPORT__ */ 

                sbp_set_md_feature(SBP_EARLY_IMPLEMENT_FREQ_BAND_PRIO_ADJUST, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_2G_CAP_FORCE_R9, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature_data(SBP_MODIFY_RLC_FOR_SACCH_DECODE, 6, (nvram_ef_sbp_modem_data_config_struct*)&sbp_data_buf);
                sbp_set_md_feature(SBP_DISABLE_TM9, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                {
                    nvram_ef_mscap_struct* nvram_mscap_ptr = NULL;
                    kal_uint8  *nvram_read_buf_ptr = (kal_uint8*) get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_MSCAP_SIZE);
                
                    nvram_external_read_data(NVRAM_EF_MSCAP_LID,
                                             1,
                                             nvram_read_buf_ptr,
                                             NVRAM_EF_MSCAP_SIZE);
                
                    nvram_mscap_ptr = (nvram_ef_mscap_struct*)nvram_read_buf_ptr;
                
                    nvram_mscap_ptr->mm_non_drx_timer_value = 0x0f; // Make it 15s to TMO
    
                    nvram_external_write_data(NVRAM_EF_MSCAP_LID,
                                              1,
                                              nvram_read_buf_ptr,
                                              NVRAM_EF_MSCAP_SIZE);
                
                    free_ctrl_buffer(nvram_read_buf_ptr);
                }
            }
            else if (sbp_id == 9) // for CT
            {
#ifdef __LTE_RAT__
                custom_nvram_set_errc_para(sbp_id);
#endif
                sbp_set_md_feature(SBP_OP09_SIM_LOCK, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_2MIN_MINIMUM_HPPLMN_TIMER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_PERMANENT_AUTO_SEL_MODE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_OP09_LTE_ROAMING, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_OP09_C2K, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_VZW_LTE_SCANNING_ENHANCEMENT_1XRTT_ACTIVE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_VZW_LTE_SCANNING_ENHANCEMENT_EVDO_ACTIVE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if (sbp_id == 10) //for Tier2
            {
            }
            else if (sbp_id == 11) //for H3G
            {
                sbp_set_md_feature(SBP_PERMANENT_AUTO_SEL_MODE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_MM_TRY_ABNORMAL_LAI_ONCE_MORE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_MM_HPPLMN_1ST_ATTEMPT_ENHANCE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_RPLMN_HPLMN_COMBINED_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_MM_SEARCH_HPLMN_BEFORE_RPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if (sbp_id == 12) //for VzW
            {
                #ifdef __OP12_CDMA_LESS__
                #ifndef __MULTIPLE_IMS_SUPPORT__
                sbp_set_md_feature(SBP_IS_ACCESS_BARRING_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                #endif
                #endif

                sbp_set_md_feature(SBP_SAT_NOTIFY_PLMN_BEFORE_READ_IMSI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_IS_OP12, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_EMM_CONN_FAIL_ABNORMAL_B, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_T3402_STOP_WHEN_MANUAL_SELECT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);                
                sbp_set_md_feature(SBP_T3402_POWER_ON_RESTART, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_T3346_POWER_ON_RESTART, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_BEARER_RSC_ALLOC, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_BEARER_RSC_MOD, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_MTC_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);                
                sbp_set_md_feature(SBP_MTC_T3396_REMAINS_WHEN_PLMN_CHANGE, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_LTE_FEMTOCELL_SYSTEM_SELECTION, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_LTE_MRU_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_EMAC_SCRM_PADDING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_OP09_LTE_ROAMING, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_OP12_C2K, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ACL_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ONE_APN_FOR_ONE_PDN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_THROTTLE_COUNTER_RESET_EXEMPTION, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_FORCE_SET_PCO_IN_LTE_ATTACH_PDN_REQUEST, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SEPARATE_PCO_IN_LTE_FOR_CIPHERING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_EMM_IGNORE_TAC_ALL_ZEROS_CHECK, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                sbp_set_md_feature(SBP_HVOLTE_ENABLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_VZW_RLF_CAUSE_SPARE1_ENABLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SAT_READ_PNN_ON_REFRESH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_REPORT_MBMS_IN_SERVICE_FOR_SIB15_ONLY_CELL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                
				sbp_set_md_feature(SBP_MM_SKIP_LU_AFTER_CSFB_FOR_EAFR, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                #ifndef __MULTIPLE_IMS_SUPPORT__
                sbp_set_md_feature(SBP_ECBM_ENABLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature_data(SBP_ECBM_MODE_TIMER_SEC, 0, (nvram_ef_sbp_modem_data_config_struct*)&sbp_data_buf);
                sbp_set_md_feature_data(SBP_ECBM_MODE_TIMER_MIN, 5, (nvram_ef_sbp_modem_data_config_struct*)&sbp_data_buf);
                #endif
                sbp_set_md_feature_data(SBP_SDM_RETRY_TIMER, 30, (nvram_ef_sbp_modem_data_config_struct*)&sbp_data_buf);
		        sbp_set_md_feature(SBP_EL1C_OPT_OP12_MEAS_TEST, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
		        sbp_set_md_feature(SBP_NWSEL_SEARCH_23G_LIMITED_SERVICE_FIRST, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DO_NOT_CHECK_PLMNID_IN_GUTI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_IS_CONN_PAGING_LOCAL_REL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ERRC_DETECTION_TIMER, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
	            sbp_set_md_feature(SBP_DISABLE_EUTRAN_AFTER_NO_SUITABLE, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_EMM_RETRY_EMC_WHEN_ABNORMAL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SIM_DETACH_WAIT_FOR_IMS_DEREG, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
               	sbp_set_md_feature(SBP_EMM_RETRY_EMC_IN_SAME_PLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
#ifdef __SCM_SUPPORT__
				sbp_set_md_feature(SBP_SCM_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
#endif  /* __SCM_SUPPORT__ */ 

#ifdef __LTE_RAT__
                custom_nvram_set_errc_para(sbp_id);
#endif

#ifdef __VOLTE_SUPPORT__
				// update SDM ADS profile
                nvram_custom_config_sdm_ads_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
#endif /* __VOLTE_SUPPORT__ */

            }
            else if (sbp_id == 15) //for Telefonica
            {
                sbp_set_md_feature(SBP_DISABLE_DISPLAY_ROAMING_HPLMN_IN_EPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if (sbp_id == 16) //for EE
            {
                sbp_set_md_feature(SBP_PERMANENT_AUTO_SEL_MODE , KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_AUTO_RETURN_PRE_RPLMN , KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_RAC_CHANGE_VDP_WHEN_IMS_ONOFF, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if (sbp_id == 17) //for DOCOMO
            {
                sbp_set_md_feature(SBP_RTP_FLOW_USE_CID_0, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                sbp_set_md_feature(SBP_DISABLE_BEARER_RSC_ALLOC, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_BEARER_RSC_MOD, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SDM_RETRY_CS_WHEN_IMS_SEND_FAIL, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SDM_RETRY_CS_DOMAIN_WHEN_IMS_TR1M_EXPIRY, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_R12_CHECK_SSAC_IN_CONNECTED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_RAC_CHANGE_VDP_IMS_CONFIG_BY_ROAMING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_RAC_CHANGE_VDP_WHEN_IMS_ONOFF, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

#ifdef __VOLTE_SUPPORT__
                // update SDM ADS profile
                nvram_custom_config_sdm_ads_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);

                #ifndef __MULTIPLE_IMS_SUPPORT__
                // Do not convert ATD to ATDE for ECC check result or it may cause empty emergency service category in CC SETUP
                sbp_set_md_feature(SBP_VDM_CONVERT_ATD_TO_ATDE_FOR_ECC_CHECK, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                #endif

#endif /* __VOLTE_SUPPORT__ */

                sbp_set_md_feature(SBP_DCM_ETWS_TEST_UE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if (sbp_id == 18) //for RJIL
            {
#ifdef __VOLTE_SUPPORT__
                // update SDM ADS profile
                nvram_custom_config_sdm_ads_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
#endif 
                sbp_set_md_feature(SBP_SDM_RETRY_IMS_WHEN_IMS_SEND_FAIL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_DISPLAY_ROAMING_HPLMN_IN_EPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_EMM_IGNORE_TAC_ALL_ZEROS_CHECK, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DRX_TEST_TRACE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);				
                sbp_set_md_feature(SBP_LTE_DISABLE_ENH_CELLSEL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SCA_CONFIGURED_BY_CUSTOMER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
			    sbp_set_md_feature(SBP_CONVERT_ATTACH_REJECT_FROM_CAUSE_7_TO_14, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ROHC_COMPR_DECOMPR_TRACE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if (sbp_id == 19) //for Telstra
            {
                sbp_set_md_feature(SBP_TELSTRA_BAND_PRIORITY_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if (sbp_id == 20) //for Sprint
            {
                sbp_set_md_feature(SBP_TCM_ENABLE_INACTIVITY_TIMER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SAT_SPRINT_IMEI_LOCK_WITHOUT_SIM_RECOVERY, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_BAND_SCAN_PRIORITY, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_HVOLTE_ENABLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SPRINT_MD1_ROAMING_CONTROL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_IS_OP20, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_EL1C_OPT_OP12_MEAS_TEST, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DO_NOT_CHECK_PLMNID_IN_GUTI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_ATNT_HPPLMN_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                sbp_set_md_feature(SBP_LTE_SCANNING_ENHANCEMENT_1XRTT_ACTIVE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_LTE_SCANNING_ENHANCEMENT_EVDO_ACTIVE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
#ifdef __HPUE_FEATURE_SUPPORT__
                sbp_set_md_feature(SBP_HPUE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);  //LG's request: Sprint HPUE=ON
#endif

#ifdef __LTE_RAT__
                custom_nvram_set_errc_para(sbp_id);
#endif
               sbp_set_md_feature(SBP_NO_COLDRESET_AFTER_CDMA_DETECT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

               nvram_custom_config_rrc_band_priority_order(sbp_id);      
            }
            else if(sbp_id == 50) //for Softbank
            {
#ifdef __LTE_RAT__
                custom_nvram_set_errc_para(sbp_id);
#endif

                sbp_set_md_feature(SBP_LTE_DISABLE_BW, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature_data(SBP_EUTRAN_DISABLE_TIMER_VALUE, 54, (nvram_ef_sbp_modem_data_config_struct*)&sbp_data_buf);
                sbp_set_md_feature_data(SBP_EUTRAN_DISABLE_TD_TIMER_VALUE, 54, (nvram_ef_sbp_modem_data_config_struct*)&sbp_data_buf);
                sbp_set_md_feature(SBP_DISABLE_CS_DETACH_FOR_SET_MULTIRAT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_RAC_CHANGE_USAGE_SETTING_BY_SIM, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_NWSEL_DO_NOT_SEARCH_NEXT_FOR_REJ_12, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf); 
                sbp_set_md_feature(SBP_DO_NOT_START_TD_DISABLE_TIMER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);              
                sbp_set_md_feature(SBP_CS_AUTHENTICATION_REJECT_PS_UNAFFECTED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_FORCE_LU_FOR_SPECIAL_NW_EMM_DETACH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_WAIT_RRC_CONN_REL_FOR_SET_RAT_MODE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_AVOID_PS_DETACH_WHEN_EUTRAN_DISABLED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SM_DISABLE_PS_SIG_CONN_RETRY_TIMER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_USE_SM_QOS_SUBSCRIBED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf); 
                sbp_set_md_feature(SBP_ALLOW_REGISTRATION_FOR_PPAC_RESTRICTION, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DO_NOT_CLEAR_CS_FPLMN_FOR_RAT_MODE_CHANGE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_LTE_DISABLE_ENH_CELLSEL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);        
                sbp_set_md_feature(SBP_DISABLE_LTE_B41, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_LTE_FORCE_RX_NESIB_B4_CONN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_BEARER_RSC_ALLOC, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_BEARER_RSC_MOD, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_PLMN_SEL_WHEN_ACCESS_BARRED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DISABLE_EUTRAN_AFTER_NO_SUITABLE, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_SEARCH_4G_WHEN_FIRST_PS_ATTACH, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_PREFER_SEARCH_3G, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_PREFER_SEARCH_4G, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_RAC_CHANGE_VDP_WHEN_IMS_ONOFF, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_BAND_SCAN_PRIORITY, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
                sbp_set_md_feature(SBP_DRX_TEST_TRACE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
				sbp_set_md_feature(SBP_R12_CHECK_SSAC_IN_CONNECTED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

                nvram_custom_config_rrc_dynamic_cap(sbp_id);
            }
            else if (sbp_id == 100) //for CSL
            {
            }
            else if (sbp_id == 101) //for PCCW
            {
                sbp_set_md_feature(SBP_INTERROGATE_GROUPS_OF_SS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if (sbp_id == 102) //for SMT
            {
            }
            else if (sbp_id == 103) //for SingTel
            {
            }
            else if (sbp_id == 104) //for StarHub
            {
            }
            else if(sbp_id == 105) //for AMX
            {
                sbp_set_md_feature(SBP_CLEAR_CODE_33, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if (sbp_id == 106) //for 3HK
            {
            }
            else if (sbp_id == 107) //for SFR
            {
#ifdef __VOLTE_SUPPORT__
				// update SDM ADS profile
                nvram_custom_config_sdm_ads_profile(sbp_id, is_in_dynamic_sbp, imsi, ps_id);
#endif /* __VOLTE_SUPPORT__ */ 
            }
            else if (sbp_id == 108) //for TWN
            {
            }
            else if (sbp_id == 109) //for CHT
            {
            }
            else if (sbp_id == 110) //for FET
            {
            }
			else if (sbp_id == 111) //for Vodafone India
            {
				#ifdef __LTE_RAT__
                custom_nvram_set_lte_pref(sbp_id);
				#endif
            }
            else if(sbp_id == 112) //for Telcel
            {
               sbp_set_md_feature(SBP_CLEAR_CODE_33, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf); // SBP_CLEAR_CODE_33_29_NO_RETRY is the Tercel's new requirement. SBP_CLEAR_CODE_33 should be disabled. 
               sbp_set_md_feature(SBP_CLEAR_CODE_33_29_NO_RETRY, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
               sbp_set_md_feature(SBP_EARLY_REPORT_PS_REG_STATUS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
               nvram_custom_config_rrc_dynamic_cap(sbp_id); 

               {
                  kal_uint32 pSetting;
                  kal_uint8  *profile_setting_ptr = (kal_uint8*) get_ctrl_buffer(NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

                  nvram_external_read_data(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
                                           1,
                                           profile_setting_ptr,
                                           NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

                  kal_mem_cpy((kal_uint8*)&pSetting, profile_setting_ptr, NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

                  pSetting |= 0x00400000;
                  kal_mem_cpy(profile_setting_ptr,(kal_uint8*) &pSetting, NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);
                  nvram_external_write_data(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
                                            1,
                                            profile_setting_ptr,
                                            NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

                  free_ctrl_buffer(profile_setting_ptr);
               }
            }
            else if (sbp_id == 113) //for Beeline
            {
            }
            else if(sbp_id == 114) //for KT
            {
            }
            else if(sbp_id == 115) //for SKT
            {
            }
            else if(sbp_id == 116) //for Uplus
            {
            }
            else if (sbp_id == 117) //for Smartfren
            {
            }
            else if (sbp_id == 118) //for YTL
            {
            }
            else if(sbp_id == 119) //for Natcom
            {
            }
            else if(sbp_id == 120) //for Claro
            {
               nvram_custom_config_rrc_dynamic_cap(sbp_id); 

               {
                  kal_uint32 pSetting;
                  kal_uint8  *profile_setting_ptr = (kal_uint8*) get_ctrl_buffer(NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

                  nvram_external_read_data(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
                                           1,
                                           profile_setting_ptr,
                                           NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

                  kal_mem_cpy((kal_uint8*)&pSetting, profile_setting_ptr, NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

                  pSetting |= 0x00400000;
                  kal_mem_cpy(profile_setting_ptr,(kal_uint8*) &pSetting, NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);
                  nvram_external_write_data(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
                                            1,
                                            profile_setting_ptr,
                                            NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE);

                  free_ctrl_buffer(profile_setting_ptr);
               }

               sbp_set_md_feature(SBP_NO_CHANGERAT_RETRY_FOR_EMERGENCY_CALL_REJECT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
			   sbp_set_md_feature(SBP_EARLY_REPORT_PS_REG_STATUS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if(sbp_id == 121) //for Bell
            {
            }
            else if(sbp_id == 122) //for AIS
            {
                sbp_set_md_feature(SBP_VDM_DISABLE_RETRY_WHEN_VOWIFI_GOT_NW_REJECT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if(sbp_id == 124) //for APTG
            {
            }
            else if(sbp_id == 125) //for DTAC
            {
            }
            else if (sbp_id == 126) //for Turkey Avea
            {
            }
            else if (sbp_id == 130) //for TIM Italy
            {
                sbp_set_md_feature(SBP_SDM_PREFER_SMS_OVER_SGS_TO_IMS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
            else if(sbp_id == 131) //for TrueMove
            {
            }
            else if (sbp_id == 132) //for Movistar
            {
                sbp_set_md_feature(SBP_EMM_IGNORE_MT_CS_WHEN_IMS_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
			#ifdef __LTE_RAT__
				custom_nvram_set_lte_pref(sbp_id);
			#endif
            }
            else if(sbp_id == 133) //for DU
            {
            }
            else if(sbp_id == 136) //for ENTEL
            {
            }
            else if(sbp_id == 147) //for Airtel
            {
	            sbp_set_md_feature(SBP_PAM_OP147_T3396_DEFAULT_VALUE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
		    else if(sbp_id == 153) //VHA/Australia
            {
			#ifdef __LTE_RAT__
				custom_nvram_set_lte_pref(sbp_id);
			#endif
            }
            else if(sbp_id == 1001) //for Ericsson IMS IWLAN
            {
            }
            else if(sbp_id == 1002) //for Nokia Finland collaboration testing
            {
            }
            else if(sbp_id == 1003) //for HQLAB_ERICSSON
            {
            }
            else if(sbp_id == 1004) //for Huawei IMS
            {
            }

            if (sbp_id != 0)// MTK internal optimization, turn off for operator 
            {
                sbp_set_md_feature(SBP_REG_HISTORY_FOR_PLMN_SELECTION, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            }
        }
        
        /* Write the new settings back to NVRAM */
        nvram_external_write_data(NVRAM_EF_SBP_MODEM_CONFIG_LID, 
                                  1,
                                  (kal_uint8*)&sbp_feature_buf, 
                                  NVRAM_EF_SBP_MODEM_CONFIG_SIZE);

        nvram_external_write_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                                  1,
                                  (kal_uint8*)&sbp_data_buf, 
                                  NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);
    
#if defined(__PCORE__)
        kal_mem_cpy(&sbp_config, &sbp_feature_buf, sizeof(nvram_ef_sbp_modem_config_struct));
        kal_mem_cpy(&sbp_data_config, &sbp_data_buf, sizeof(nvram_ef_sbp_modem_data_config_struct));
     
        SHARED_VAR(sbp_config_shared) = sbp_config;
        SHARED_VAR(sbp_data_config_shared) = sbp_data_config;
#endif

    }
    else
    {
        return KAL_FALSE;
    }
    
    return KAL_TRUE;
    
}


/*****************************************************************************
 * FUNCTION
 *  nvram_custom_config_ltecsr_profile
 * DESCRIPTION
 *  Pre-process nvram data items for LTECSR PROFILE at customer function.
 *  User can pre-process nvram data items using NVRAM external API here.
 *  nvram_external_write_data()
 *  nvram_external_read_data()
 * PARAMETERS
 *  sbp_id
 *  is_in_dynamic_sbp   // Not used
 *  imsi                // Not used
 *  ps_id 
 * RETURNS
 *  KAL_TRUE
 * NOTE
 *  Here ua_config.operator_code from nvram_ims_profile is used.
 *  So that this function has to be called before nvram_custom_config_ims_profile()
 *****************************************************************************/
#if defined (__MOD_IMC__)
kal_bool nvram_custom_config_ltecsr_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id)
{
    kal_uint8* nvram_read_ltecsr_buf_ptr = NULL;
    kal_uint8* nvram_read_ims_buf_ptr = NULL;
    nvram_ef_ltecsr_profile_record_struct* nvram_ltecsr_profile_ptr = NULL;
    nvram_ef_ltecsr_profile_record_struct* default_ltecsr_profile_ptr = NULL;
    nvram_ef_ims_profile_record_struct* nvram_ims_profile_ptr = NULL;
    sim_interface_enum sim_slot_id;
    kal_uint8  mccmnc[6] = {0};

    sim_slot_id = l4c_gemini_get_actual_sim_id((sim_interface_enum)ps_id);

    if(is_in_dynamic_sbp){
        convert_mcc_mnc_from_imsi(mccmnc, imsi);
    }
    /* Allocate buffer to read NVRAM setting */
    nvram_read_ltecsr_buf_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_LTECSR_PROFILE_SIZE);
    nvram_external_read_data(NVRAM_EF_LTECSR_PROFILE_LID,
                             sim_slot_id+1,
                             nvram_read_ltecsr_buf_ptr,
                             NVRAM_EF_LTECSR_PROFILE_SIZE);
    nvram_ltecsr_profile_ptr = (nvram_ef_ltecsr_profile_record_struct*)nvram_read_ltecsr_buf_ptr;


    /* Due to DSBP mechanism will not reset NVRAM buffer to default value,
     * Our customization may cause accumulation to NVRAM buffer.
     * Reset default NVRAM here.
     * compare sbp_id and operator_code, 
     * to keep the same operator's parameter which no need to customize.
     */
    nvram_read_ims_buf_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_IMS_PROFILE_SIZE);
    nvram_external_read_data(NVRAM_EF_IMS_PROFILE_LID,
#ifdef __MULTIPLE_IMS_SUPPORT__
                             sim_slot_id+1,
#else
                             SIM1+1,
#endif
                             nvram_read_ims_buf_ptr,
                             NVRAM_EF_IMS_PROFILE_SIZE);
    nvram_ims_profile_ptr = (nvram_ef_ims_profile_record_struct*)nvram_read_ims_buf_ptr;

    /* Even though it may use [SIM1].operator_code (hard coded to SIM1) for sbp_id checking when MIMS is OFF,
     * ltecsr profile still need to be read/write with real sim id (use sim_slot_id)
     * It is because ltecsr has already re-arch for Gemini/MIMS without compile flag,
     * and hence the nvram read/write operation in ltecsr will base on real sim id
     */
    if(sbp_id != nvram_ims_profile_ptr->ua_config.operator_code) {
        if(NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_LTECSR_PROFILE_LID, sim_slot_id+1, (kal_uint8**)&default_ltecsr_profile_ptr)){
            kal_mem_cpy(nvram_ltecsr_profile_ptr, default_ltecsr_profile_ptr, sizeof(nvram_ef_ltecsr_profile_record_struct));
        }
    }

    free_ctrl_buffer(nvram_read_ims_buf_ptr);
    nvram_read_ims_buf_ptr = NULL;

    /* Customize NVRAM according to SBP ID */
    switch(sbp_id)
    {
        case 1: /* CMCC */
        {
            nvram_ltecsr_profile_ptr->evs_prefer_rate = 4; /* VoLTE_EVS_Codec_Bitrate_13_2 */
            break;
        }
        case 3: /* Orange */
        {
            nvram_ltecsr_profile_ptr->ltecsr_common_para2 = nvram_ltecsr_profile_ptr->ltecsr_common_para2 | (1<<4); //LTECSR_FEATURE_DYNAMIC_QOS
            break;
        }
        case 5: /* DTAG (TMOEU) */
        {
            nvram_ltecsr_profile_ptr->rtp_expire_warning_timer = 1000;
            break;
        }
        case 6: /* VDF */
        {
            nvram_ltecsr_profile_ptr->rtp_expire_warning_timer = 1000;
            break;
        }
        case 7: /* ATT */
        {
            nvram_ltecsr_profile_ptr->rtp_expire_timer = 20000;
            nvram_ltecsr_profile_ptr->rtcp_expire_timer = 20000;
            nvram_ltecsr_profile_ptr->silence_dropcall_threshold   = 20000; // Inactivity timeouts for both RTP and RTCP shall be set to 20 seconds
            nvram_ltecsr_profile_ptr->stat_feature_option = nvram_ltecsr_profile_ptr->stat_feature_option | (1<<1); //LTECSR_STAT_CIQ
            break;
        }
        case 8: /* TMO-US */
        {
            nvram_ltecsr_profile_ptr->ltecsr_common_para2 = nvram_ltecsr_profile_ptr->ltecsr_common_para2 | (1<<7) | (1<<8); //LTECSR_FEATURE_PING_PCSCF_ENABLE, LTECSR_FEATURE_RTCP_MIN_DISABLE, LTECSR_FEATURE_RTCP_MAX_DISABLE
            nvram_ltecsr_profile_ptr->rtcp_max_interval = 2000;
            nvram_ltecsr_profile_ptr->rtp_expire_timer = 30000;
            nvram_ltecsr_profile_ptr->rtcp_expire_timer = 30000;
            nvram_ltecsr_profile_ptr->rtp_expire_warning_timer = 1000;
            nvram_ltecsr_profile_ptr->stat_feature_option = nvram_ltecsr_profile_ptr->stat_feature_option | (1<<2); //LTECSR_STAT_ECHO            
            break;
        }
        case 9: /* CT */
        {
            nvram_ltecsr_profile_ptr->silence_dropcall_threshold   = 20000; //CT requirment: 20s
            nvram_ltecsr_profile_ptr->ltecsr_common_para2 = nvram_ltecsr_profile_ptr->ltecsr_common_para2 | (1<<1); //LTECSR_FEATURE_HOLDCALL_DL_CHECK
            break;
        }
        case 11: /* H3G */
        {
            if (strncmp((char *)mccmnc, "232", 3) == 0) {
                /* Austria */
                nvram_ltecsr_profile_ptr->rtp_expire_timer  = 15000;
                nvram_ltecsr_profile_ptr->rtcp_expire_timer = 15000;
            }           
            break;
        }
        case 12: /* VzW */
        {
            nvram_ltecsr_profile_ptr->silence_dropcall_threshold   = 20000; //VzW requirment: 20s
            nvram_ltecsr_profile_ptr->ltecsr_common_para2 = nvram_ltecsr_profile_ptr->ltecsr_common_para2 | (1<<1) | (1<<0) | (1<<5) | (1<<6) ; //LTECSR_FEATURE_HOLDCALL_DL_CHECK and LTECSR_FEATURE_DTMF_MUTE and LTECSR_FEATURE_FIX_RTCP_INTERVAL_ACTIVE and LTECSR_FEATURE_FIX_RTCP_INTERVAL_HOLD
            nvram_ltecsr_profile_ptr->rtcp_fix_interval_hold = 2000; //VzW requirement: 2s while the call is not active
            break;
        }
        case 15: /* Telefonica */
        {
            nvram_ltecsr_profile_ptr->silence_dropcall_threshold   = 20000; //Telefonica requirment: 20s
            break;
        }
        case 16: /* EE */
        {
            nvram_ltecsr_profile_ptr->ltecsr_common_para2 = nvram_ltecsr_profile_ptr->ltecsr_common_para2 | (1<<1); //LTECSR_FEATURE_HOLDCALL_DL_CHECK
            break;
        }
        case 17: /* DOCOMO */
        {
            nvram_ltecsr_profile_ptr->silence_dropcall_threshold   = 12000; //DCM requirment: 12s
            nvram_ltecsr_profile_ptr->ltecsr_common_para2 = nvram_ltecsr_profile_ptr->ltecsr_common_para2 | 0x1; //LTECSR_FEATURE_DTMF_MUTE
            break;
        }
        case 18: /* RJIL */
        {
            nvram_ltecsr_profile_ptr->ltecsr_common_para2 = nvram_ltecsr_profile_ptr->ltecsr_common_para2 | (1<<1); //LTECSR_FEATURE_HOLDCALL_DL_CHECK
            break;
        }
        case 120: /* Claro */
        {
            nvram_ltecsr_profile_ptr->rtp_expire_timer = 30000;
            nvram_ltecsr_profile_ptr->rtcp_expire_timer = 25000;
            break;
        }
        case 129: /* KDDI */
        {
            nvram_ltecsr_profile_ptr->rtp_expire_timer = 20000;
            nvram_ltecsr_profile_ptr->rtcp_expire_timer = 20000;
            break;
        }
        case 132: /**/
        {
            if (strncmp((char *)mccmnc, "334", 3) == 0) {
                /* Mexico */
                nvram_ltecsr_profile_ptr->rtp_expire_timer = 30000;
            } else if (strncmp((char *)mccmnc, "748", 3) == 0) {
                /*Uruguay*/
                nvram_ltecsr_profile_ptr->rtp_expire_timer = 60000;
            } else {
                /* default */
                nvram_ltecsr_profile_ptr->rtp_expire_timer = 10000;
            }
            break;
        }
        case 134: /* Elisa */
        {
            nvram_ltecsr_profile_ptr->rtp_expire_warning_timer = 1000;
            break;
        }
        case 145: /* Cricket (should be aligned with AT&T) */
        {
            nvram_ltecsr_profile_ptr->rtp_expire_timer = 20000;
            nvram_ltecsr_profile_ptr->rtcp_expire_timer = 20000;
            nvram_ltecsr_profile_ptr->stat_feature_option = nvram_ltecsr_profile_ptr->stat_feature_option | (1<<1); //LTECSR_STAT_CIQ
            break;
        }
        case 147: /* Airtel */
        {
            nvram_ltecsr_profile_ptr->silence_dropcall_threshold   = 90000;
            break;
        }
        case 156: /* Telenor */
        {
            nvram_ltecsr_profile_ptr->rtp_expire_warning_timer = 1000;
            break;
        }
        case 155: /* DIGI */
        {
            if (strncmp((char *)mccmnc, "216", 3) == 0) {
                 /*Hungary*/
                nvram_ltecsr_profile_ptr->silence_dropcall_threshold = 5000; //DIGI requirment: 5s
                nvram_ltecsr_profile_ptr->wfc_silence_threshold = 3000; //DIGI requirment: 3s
            }
            else if (strncmp((char *)mccmnc, "226", 3) == 0) {
                 /*Romania*/
                nvram_ltecsr_profile_ptr->rtp_expire_warning_timer = 1000;
            }
            break;
        }
        case 157: /* TELUS */
        {
            nvram_ltecsr_profile_ptr->silence_dropcall_threshold   = 14000;
            break;
        }
        case 195: /* O2 Czech */
        {
            nvram_ltecsr_profile_ptr->rtp_expire_warning_timer = 1000;
            break;
        }
        case 209: /* Avantel */
        {
            // LTECSR_FEATURE_FIX_RTCP_INTERVAL_ACTIVE and LTECSR_FEATURE_FIX_RTCP_INTERVAL_HOLD
	        nvram_ltecsr_profile_ptr->ltecsr_common_para2 = nvram_ltecsr_profile_ptr->ltecsr_common_para2 | (1<<5) | (1<<6);
            nvram_ltecsr_profile_ptr->rtcp_fix_interval_active = 20000;
            nvram_ltecsr_profile_ptr->rtcp_fix_interval_hold = 20000;
            break;
        }
    }

    /* Write back customized settings to NVRAM */
    nvram_external_write_data(NVRAM_EF_LTECSR_PROFILE_LID,
                              sim_slot_id+1,
                              nvram_read_ltecsr_buf_ptr,
                              NVRAM_EF_LTECSR_PROFILE_SIZE);

    /* Free allocated buffer */
    free_ctrl_buffer(nvram_read_ltecsr_buf_ptr);
    nvram_read_ltecsr_buf_ptr = NULL;

    return KAL_TRUE;
}
#endif

#if defined (__MOD_IMC__)
/*****************************************************************************
 * FUNCTION
 *  convert_mcc_mnc_from_imsi
 * DESCRIPTION
 *  get mcc, mnc from imsi
 * PARAMETERS
 *  imsi
 * RETURNS
 *  KAL_TRUE
 *****************************************************************************/
static kal_bool convert_mcc_mnc_from_imsi(kal_uint8* mccmnc, kal_uint8* imsi)
{
    /* get mcc/mnc and convert to ASCII */
    mccmnc[0] = (imsi[0] >> 4) + 48;   //mcc1
    mccmnc[1] = (imsi[1] & 0x0F) + 48; //mcc2
    mccmnc[2] = (imsi[1] >> 4) + 48;   //mcc3

    mccmnc[3] = (imsi[2] & 0x0F) + 48; //mnc1
    mccmnc[4] = (imsi[2] >> 4) + 48;   //mnc2
    mccmnc[5] = (imsi[3] & 0x0F) + 48; //mnc3

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_custom_config_ims_profile
 * DESCRIPTION
 *  Pre-process nvram data items for IMS PROFILE at customer function.
 *  User can pre-process nvram data items using NVRAM external API here.
 *  nvram_external_write_data()
 *  nvram_external_read_data()
 * PARAMETERS
 *  sbp_id
 *  is_in_dynamic_sbp
 *  imsi (Note: only avaiable when is_in_dynamic_sbp is KAL_TRUE
 * RETURNS
 *  KAL_TRUE
 *****************************************************************************/
 kal_bool nvram_custom_config_ims_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id)
 {
    kal_uint8* nvram_read_buf_ptr = NULL;
    nvram_ef_ims_profile_record_struct* nvram_ims_profile_ptr = NULL; 
    kal_uint8  imsi_mnc_len = 0;
    kal_uint8  mccmnc[6] = {0};
    sim_interface_enum sim_slot_id;

#ifdef __MULTIPLE_IMS_SUPPORT__
    sim_slot_id = l4c_gemini_get_actual_sim_id((sim_interface_enum)ps_id);
#else
    sim_slot_id = SIM1;
#endif
    
    imsi_mnc_len = sim_query_mnc_num(sim_slot_id);
    if(is_in_dynamic_sbp){
        convert_mcc_mnc_from_imsi(mccmnc, imsi);
    }

    imc_nvram_customization(sbp_id, sim_slot_id, is_in_dynamic_sbp, imsi_mnc_len, &mccmnc[0]);

    // Allocate buffer to read NVRAM setting
    nvram_read_buf_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_IMS_PROFILE_SIZE);

    nvram_external_read_data(NVRAM_EF_IMS_PROFILE_LID, 
                             sim_slot_id+1, 
                             nvram_read_buf_ptr, 
                             NVRAM_EF_IMS_PROFILE_SIZE);
    
    nvram_ims_profile_ptr = (nvram_ef_ims_profile_record_struct*)nvram_read_buf_ptr;

    ims_operator_code[sim_slot_id] = (kal_uint32) nvram_ims_profile_ptr->ua_config.operator_code;

    // Free allocated buffer
    free_ctrl_buffer(nvram_read_buf_ptr);
    nvram_read_buf_ptr = NULL;

    return KAL_FALSE;
 }
 #endif /* __MOD_IMC__ */

#ifdef __VOLTE_SUPPORT__
/*****************************************************************************
  * FUNCTION
  *  nvram_custom_config_sdm_ads_profile
  * DESCRIPTION
  *  Pre-process nvram data items for SDM ADS PROFILE at customer function.
  *  User can pre-process nvram data items using NVRAM external API here.
  *  nvram_external_write_data()
  *  nvram_external_read_data()
  * PARAMETERS
  *  sbp_id
  * RETURNS
  *  KAL_TRUE
  *****************************************************************************/
 kal_bool nvram_custom_config_sdm_ads_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id)
 {
 #ifdef __MULTIPLE_IMS_SUPPORT__
     kal_uint8* nvram_read_buf_ptr = NULL;
     nvram_ef_sdm_ads_profile_struct* nvram_sdm_ads_profile_ptr = NULL;
     nvram_ef_sdm_ads_profile_struct* default_sdm_ads_profile_ptr = NULL;
     sim_interface_enum sim_slot_id = SIM1;

     sim_slot_id = l4c_gemini_get_actual_sim_id((sim_interface_enum)ps_id);

 
     // Allocate buffer to read NVRAM setting
     nvram_read_buf_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_SDM_ADS_PROFILE_SIZE);
 
     // Read NVRAM setting
     nvram_external_read_data(NVRAM_EF_SDM_ADS_PROFILE_LID,
                              sim_slot_id+1,
                              nvram_read_buf_ptr,
                              NVRAM_EF_SDM_ADS_PROFILE_SIZE);
 
     nvram_sdm_ads_profile_ptr = (nvram_ef_sdm_ads_profile_struct*)nvram_read_buf_ptr;


     /*
      * Reset default NVRAM here.
      */
	 if(NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_SDM_ADS_PROFILE_LID, sim_slot_id+1, (kal_uint8**)&default_sdm_ads_profile_ptr))
	 {
		 kal_mem_cpy(nvram_sdm_ads_profile_ptr, default_sdm_ads_profile_ptr, sizeof(nvram_ef_sdm_ads_profile_struct));
	 }


 
     switch (sbp_id)
     {
         case 1: /* CMCC */
         {
             nvram_sdm_ads_profile_ptr->imcsms_retry_for_202_rev = 1;
       
             break;             
         }
         case 7: /* AT&T */
         case 145: /* Cricket */
         {
             nvram_sdm_ads_profile_ptr->try_cs_when_2g_voice_call = 1;
             nvram_sdm_ads_profile_ptr->retry_cs_when_ims_send_fail = 0;
             nvram_sdm_ads_profile_ptr->ims_smart_congestion_report_to_ap = 1;
       
             break;
         }
         case 12: /* VzW */
         {
             nvram_sdm_ads_profile_ptr->sdm_retry_timer = 30;

             break;               
         }
         case 17: /* DOCOMO */
         {
             nvram_sdm_ads_profile_ptr->retry_cs_when_ims_send_fail = 0;
             nvram_sdm_ads_profile_ptr->retry_cs_when_ims_tr1m_expiry = 1;

             break;
         }
         case 18: /* RJIL */
         {
             nvram_sdm_ads_profile_ptr->retry_ims_when_ims_send_fail = 1;

             break;  
         }         
         case 107: /* SFR */
		 case 111: /* Vodafone India */
         {
             nvram_sdm_ads_profile_ptr->prefer_sms_over_sgs_to_ims = 1;

             break;
         }
       
         default:
             break;
     }
 
     // Update NVRAM setting
     nvram_external_write_data(NVRAM_EF_SDM_ADS_PROFILE_LID,
                               sim_slot_id+1,
                               nvram_read_buf_ptr,
                               NVRAM_EF_SDM_ADS_PROFILE_SIZE);

 
     // Free allocated buffer
     if (nvram_read_buf_ptr != NULL)
     {
         free_ctrl_buffer(nvram_read_buf_ptr);
         nvram_read_buf_ptr = NULL;
     }
 
     return KAL_TRUE;
#else
	 return KAL_TRUE;
#endif /* __MULTIPLE_IMS_SUPPORT__ */
 }
 
 /*****************************************************************************
  * FUNCTION
  *  nvram_custom_config_vdm_ads_profile
  * DESCRIPTION
  *  Pre-process nvram data items for VDM ADS PROFILE at customer function.
  *  User can pre-process nvram data items using NVRAM external API here.
  *  nvram_external_write_data()
  *  nvram_external_read_data()
  * PARAMETERS
  *  sbp_id
  *  is_in_dynamic_sbp (not used)
  *  imsi (not used)
  *  ps_id
  * RETURNS
  *  KAL_TRUE
  *****************************************************************************/
 kal_bool nvram_custom_config_vdm_ads_profile(kal_uint32 sbp_id, kal_bool is_in_dynamic_sbp, kal_uint8 *imsi, protocol_id_enum ps_id)
 {
     kal_uint8* nvram_read_buf_ptr = NULL;
     kal_uint8 vdm_ims_reconfig_enable = 1;
     nvram_ef_vdm_nv_data_struct* nvram_vdm_nv_data_ptr = NULL;
     nvram_ef_vdm_ads_profile_struct* nvram_vdm_ads_profile_ptr = NULL;
     nvram_ef_vdm_ads_profile_struct* default_vdm_ads_profile_ptr = NULL;

     // Allocate buffer to read VDM_NV_DATA setting
     nvram_vdm_nv_data_ptr = (nvram_ef_vdm_nv_data_struct*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_VDM_NV_DATA_SIZE);

     // read VDM ims_reconfig_enable setting first
     nvram_external_read_data(NVRAM_EF_VDM_NV_DATA_LID,
                             l4c_gemini_get_actual_sim_id((sim_interface_enum)ps_id)+1,
                             (kal_uint8*)nvram_vdm_nv_data_ptr,
                             NVRAM_EF_VDM_NV_DATA_SIZE);
     vdm_ims_reconfig_enable = nvram_vdm_nv_data_ptr->ims_reconfig_enable;
     // Free allocated buffer
     if (nvram_vdm_nv_data_ptr != NULL)
     {
         free_ctrl_buffer(nvram_vdm_nv_data_ptr);
         nvram_vdm_nv_data_ptr = NULL;
     }

     //reconfig NVRAM settings for ims reconfig
     if (vdm_ims_reconfig_enable == 1)//ims reconfig is enabled
     {
         // Allocate buffer to read VDM_ADS_PROFILE setting
         nvram_read_buf_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_VDM_ADS_PROFILE_SIZE);
         nvram_vdm_ads_profile_ptr = (nvram_ef_vdm_ads_profile_struct*)nvram_read_buf_ptr;

         //set to default value
         if(NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_VDM_ADS_PROFILE_LID, l4c_gemini_get_actual_sim_id((sim_interface_enum)ps_id)+1,
                                              (kal_uint8**)&default_vdm_ads_profile_ptr))
         {
             kal_mem_cpy(nvram_vdm_ads_profile_ptr, default_vdm_ads_profile_ptr, sizeof(nvram_ef_vdm_ads_profile_struct));
         }
         else// Read current NVRAM setting
         {
             nvram_external_read_data(NVRAM_EF_VDM_ADS_PROFILE_LID,
                                     l4c_gemini_get_actual_sim_id((sim_interface_enum)ps_id)+1,
                                     nvram_read_buf_ptr,
                                     NVRAM_EF_VDM_ADS_PROFILE_SIZE);
         }

         switch (sbp_id)
         {
             case 1: /* CMCC */
             {
                 #ifdef __MULTIPLE_IMS_SUPPORT__
                 //SBP_VDM_REDIAL_IMS_VT_TO_CS_VOICE
                 nvram_vdm_ads_profile_ptr->profile_common.allow_vdm_redial_ims_vt_to_cs_voice = 1;
                 #endif

                 nvram_vdm_ads_profile_ptr->profile_normal.general_setting_normal.need_check_emb_support_eutran = 1;

                 break;
             }

             case 5: /* TMOEU */
             {
                 nvram_vdm_ads_profile_ptr->profile_normal.general_setting_normal.need_check_emb_support_eutran = 1;
                 break;
             }

             case 7: /* AT&T */
             {
                 // Disallow IMS emergency call with negative IMS voice over PS session indicator
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims_with_negative_imsvops_eutran = 0;
                 // Disallow retry CS domain after IMS call attempt fail for normal call
                 nvram_vdm_ads_profile_ptr->profile_normal.general_setting_normal.allow_retry_cs_after_ims_fail = 0;

                 nvram_vdm_ads_profile_ptr->profile_emerg.prefer_ims_in_lte_limited_srv = 0;

                 #ifdef __MULTIPLE_IMS_SUPPORT__
                 nvram_vdm_ads_profile_ptr->profile_common.is_access_barring_enable = 1;
                 #endif

                 break;
             }
             
             case 8: /* TMOUS */
             {
                 // Disallow IMS emergency call with negative IMS voice over PS session indicator
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims_with_negative_imsvops_eutran = 0;
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims_with_negative_imsvops_utran = 0;
     
                 #ifdef __MULTIPLE_IMS_SUPPORT__
                 //SBP_VDM_REDIAL_IMS_VT_TO_CS_VOICE
                 nvram_vdm_ads_profile_ptr->profile_common.allow_vdm_redial_ims_vt_to_cs_voice = 1;

                 //SBP_VDM_REVERT_TO_CELLULAR_FOR_ECC
                 nvram_vdm_ads_profile_ptr->profile_common.allow_revert_to_cellular_for_ecc = 1;

                 //SBP_ECBM_ENABLE
                 nvram_vdm_ads_profile_ptr->profile_common.is_ecbm_enable = 1;

                 //SBP_ECBM_MODE_TIMER_SEC, SBP_ECBM_MODE_TIMER_MIN
                 nvram_vdm_ads_profile_ptr->profile_common.ecbm_mode_timer_sec = 0;
                 nvram_vdm_ads_profile_ptr->profile_common.ecbm_mode_timer_min = 3;

                 //SBP_BEFORE_RINGING_CSFB
                 nvram_vdm_ads_profile_ptr->profile_common.allow_before_ringing_csfb = 1;

                 //SBP_ALLOW_WFC_CELLULAR_PREFER
                 nvram_vdm_ads_profile_ptr->profile_common.allow_wfc_cellular_prefer = 1;
                 #endif

                 break;
             }

             case 12: /* VzW */
             {
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.max_attempt_total_num = 10;
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.max_attempt_consecutive_ims_num = 5;
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.max_attempt_consecutive_cs_num = 5;

                 #ifdef __OP12_CDMA_LESS__
                 // Disallow CS during ssac barring
                 nvram_vdm_ads_profile_ptr->profile_normal.allow_cs_during_ssac_barring = 0;
                 #ifdef __MULTIPLE_IMS_SUPPORT__
                 nvram_vdm_ads_profile_ptr->profile_common.is_access_barring_enable = 1;
                 #endif
                 #endif
                 
                 #ifdef __MULTIPLE_IMS_SUPPORT__
                 //SBP_ECBM_ENABLE
                 nvram_vdm_ads_profile_ptr->profile_common.is_ecbm_enable = 1;

                 //allow_global_emc_scan
                 nvram_vdm_ads_profile_ptr->profile_common.allow_global_emc_scan = 1;

                 //SBP_ECBM_MODE_TIMER_SEC, SBP_ECBM_MODE_TIMER_MIN
                 nvram_vdm_ads_profile_ptr->profile_common.ecbm_mode_timer_sec = 0;
                 nvram_vdm_ads_profile_ptr->profile_common.ecbm_mode_timer_min = 5;
                 #endif

                 break;
             }

             case 17: /*DOCOMO*/
             {
                 // Disallow CS during ssac barring
                 nvram_vdm_ads_profile_ptr->profile_normal.allow_cs_during_ssac_barring = 0;

                 // Disallow any PLMN search when connected OOS for ECC
                 nvram_vdm_ads_profile_ptr->profile_emerg.allow_any_plmn_search_for_ecc = 0;

                 #ifdef __MULTIPLE_IMS_SUPPORT__
                 /* SBP_VDM_CONVERT_ATD_TO_ATDE_FOR_ECC_CHECK
                             * Do not convert ATD to ATDE for ECC check result or it may cause empty emergency service category in CC SETUP */
                 nvram_vdm_ads_profile_ptr->profile_common.allow_convert_atd_to_atde_for_ecc_check = 0;
                 #endif

                 break;
             }

             case 18: /* RJIL */
             {
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.max_attempt_total_num = 6;
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.max_attempt_consecutive_ims_num = 5;
                 break;
             }

             case 50: //for Softbank
             {
                nvram_vdm_ads_profile_ptr->profile_normal.allow_cs_during_ssac_barring = 0;
                break;
             }
             case 107: /* SFR */
             {
                 // Disallow emergency call over IMS
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims = 0;
     
                 break;
             }
             case 108: /* TWN */
             {
                 // Disallow emergency call over IMS
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims = 0;

                 //TWM requirement: treat 110/119 as normal CS call w/ valid SIM
                 #ifdef __MULTIPLE_IMS_SUPPORT__
                 nvram_vdm_ads_profile_ptr->profile_common.allow_special_ecc_as_normal_cs = 1;
                 #endif
                 
                 break;
             }
             case 109: /* CHT */
             {
                 // treat 110/119 as normal CS call w/ valid SIM
                 #ifdef __MULTIPLE_IMS_SUPPORT__
                 nvram_vdm_ads_profile_ptr->profile_common.allow_special_ecc_as_normal_cs = 1;
                 #endif

                 break;
             }
             case 122: /* AIS */
             {
                 //SBP_VDM_DISABLE_RETRY_WHEN_VOWIFI_GOT_NW_REJECT
                 #ifdef __MULTIPLE_IMS_SUPPORT__
                 nvram_vdm_ads_profile_ptr->profile_common.disable_retry_when_vowifi_got_nw_reject = 1;
                 #endif

                 break;
             }
             case 124: /* APTG */
             {
                // Disallow WFC emergency call
                nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_wfc = 0;

                break;
             }
             case 139: /* Bouygues */
             {
                 // Disallow emergency call over IMS
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims = 0;

                break;
             }
             case 143: /* TurkCell */
             {
                 // Disallow emergency call over IMS
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims = 0;
                
                 break;
             }

             case 145: /* Cricket */
             {
                 // Disallow IMS emergency call with negative IMS voice over PS session indicator
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims_with_negative_imsvops_eutran = 0;
                 // Disallow retry CS domain after IMS call attempt fail for normal call
                 nvram_vdm_ads_profile_ptr->profile_normal.general_setting_normal.allow_retry_cs_after_ims_fail = 0;

                 #ifdef __MULTIPLE_IMS_SUPPORT__
                 nvram_vdm_ads_profile_ptr->profile_common.is_access_barring_enable = 1;
                 #endif

                 break;
             }
             case 157: /* TELUS in Canada */
             {
                 nvram_vdm_ads_profile_ptr->profile_emerg.prefer_ims_in_lte_limited_srv = 0;
                 /* TELUS-Feb2017_VOLTE-247
                                 * The UE SHALL use CS Fallback (CSFB) for emergency call while camped on E-UTRAN
                                 * having non-VoLTE TAC since UE SHALL NOT include the 'MMTel' feature tag when 
                                 * attempting to register to IMS while camped on non-VoLTE TAC.
                                 */
                 nvram_vdm_ads_profile_ptr->profile_emerg.prefer_cs_when_volte_unreged = 1;
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.prefer_cs_when_lte_roaming = 1;
                 
                 /* VoLTE-TC-89, workaround 
                 ** if call fails in 23G (LTE only coverage), NWSEL will search back to LTE automarically, VDM won't have to trigger ANY PLMN search to interrupt it immediately
                 */
                 #ifdef __MULTIPLE_IMS_SUPPORT__          
                 nvram_vdm_ads_profile_ptr->profile_common.timer_length_delay_resume_ads_for_service_recover_from_23g = 5;
                 nvram_vdm_ads_profile_ptr->profile_common.allow_recursive_cs = 1;
				 #endif

                 /* To improve ECC performance for LTE only coverage, UE would not force select 2/3G for the first CS domain attempt.
                               * Therefore we change below setting to let UE have chance to force select 2/3G after IMS ECC failed.
                               */
                 nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.max_attempt_consecutive_cs_num = 2;

                 break;
             }
             case 176: /* T-star */
             {
                // Disallow emergency call over IMS
                nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims = 0;
                // treat 110/119 as normal CS call w/ valid SIM
                #ifdef __MULTIPLE_IMS_SUPPORT__
                nvram_vdm_ads_profile_ptr->profile_common.allow_special_ecc_as_normal_cs = 1;
                #endif

                break;
             }

             default:
                 break;
         }
     
         nvram_external_write_data(NVRAM_EF_VDM_ADS_PROFILE_LID,
                                   l4c_gemini_get_actual_sim_id((sim_interface_enum)ps_id)+1,
                                   nvram_read_buf_ptr,
                                   NVRAM_EF_VDM_ADS_PROFILE_SIZE);
     
         // Free allocated buffer
         if (nvram_read_buf_ptr != NULL)
         {
             free_ctrl_buffer(nvram_read_buf_ptr);
             nvram_read_buf_ptr = NULL;
         }
     }
     return KAL_TRUE;
 }
#endif /* __VOLTE_SUPPORT__ */

/*****************************************************************************
* FUNCTION
*   sbp_get_sbp_id_from_mcc_mnc()
*
* DESCRIPTION
*   This function converts MCC/MNC to SBP ID
*
* PARAMETERS
*   mcc_mnc [IN]    MCC/MNC
*
* RETURNS
*   SBP ID
*****************************************************************************/

kal_uint32 sbp_get_sbp_id_from_mcc_mnc(kal_uint8 *mcc_mnc)
{
    kal_uint16 table_size, i;
    kal_uint8 item_length;
    mccmnc_to_sbp_id_struct item;

    table_size = sizeof(mcc_mnc_to_sbp_id_table)/sizeof(mcc_mnc_to_sbp_id_table[0]);

    for (i=0; i < table_size; i++)
    {
        item = mcc_mnc_to_sbp_id_table[i];
        
        item_length = (kal_uint8)strlen((char*)item.mcc_mnc);

        if(strncmp((kal_char*)mcc_mnc, (kal_char*)item.mcc_mnc, item_length) == 0)
            return (item.sbp_id);
            
    }

    return 0;
}

kal_bool nvram_custom_config_rrc_dynamic_cap(kal_uint32 sbp_id)
{
    kal_uint8* nvram_read_buf_ptr = NULL, *nvram_read_buf_tdd_ptr = NULL;
    nvram_ef_umts_usime_rrc_dynamic_fdd_struct* pUMTS_USIME_RRC_dynamic_cap;
	nvram_ef_umts_usime_rrc_dynamic_tdd_struct* pUMTS_USIME_RRC_dynamic_tdd_cap;
    kal_bool is_nvram_need_update = KAL_FALSE;


    // Allocate buffer to read NVRAM setting
    nvram_read_buf_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_FDD_SIZE);
    nvram_read_buf_tdd_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TDD_SIZE);


    // Read NVRAM setting
    nvram_external_read_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_FDD_LID,
                             1,
                             nvram_read_buf_ptr,
                             NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_FDD_SIZE);
    pUMTS_USIME_RRC_dynamic_cap = (nvram_ef_umts_usime_rrc_dynamic_fdd_struct*)nvram_read_buf_ptr;
    nvram_external_read_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TDD_LID,
                             1,
                             nvram_read_buf_tdd_ptr,
                             NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TDD_SIZE);
    pUMTS_USIME_RRC_dynamic_tdd_cap = (nvram_ef_umts_usime_rrc_dynamic_tdd_struct*)nvram_read_buf_tdd_ptr;

    switch (sbp_id)
    {
        case 3: /* Orange */
            pUMTS_USIME_RRC_dynamic_cap->rrce_feature_cap |= 0x10;  
            pUMTS_USIME_RRC_dynamic_tdd_cap->rrce_feature_cap |= 0x10;  
           
            is_nvram_need_update = KAL_TRUE;
            break;
        case 20: /*Sprint*/
        case 50: /*Softbank*/
            /* ALPS02096485: SoftBank requests UE to set supportOfInterRATHOToEUTRAFDD
             * and supportOfInterRATHOToEUTRATDD to FALSE.
             */
            #ifdef __LTE_RAT__
            #if defined(__UMTS_FDD_MODE__) && defined(__UMTS_R9__)
            pUMTS_USIME_RRC_dynamic_cap->r8_cap1 &= 0xF7; //set r8_cap1 bit 4 to 0
            pUMTS_USIME_RRC_dynamic_cap->r8_cap2 &= 0x7F; //set r8_cap2 bit 8 to 0

            is_nvram_need_update = KAL_TRUE;
            #endif
            #endif //LTE_RAT
            break;
        case 112: /* Telcel */
        case 120: /* Claro */	
#if defined(__UMTS_FDD_MODE__) && defined(__UMTS_R8__)
           /* eFACH/eRACH/eDRX feature enable */
        	  pUMTS_USIME_RRC_dynamic_cap->r7_cap1 |= 0x04; //_MAC_EHS_SUPPORT

        	  //__CUSTOMIZE_ENHANCED_COMMON_STATE_SUPPORT__
        	  pUMTS_USIME_RRC_dynamic_cap->r7_cap1 |= 0x40; //hsdschReceptionCellUraPch (bit 7)
        	  pUMTS_USIME_RRC_dynamic_cap->r7_cap1 |= 0x20; //hsdschReceptionCellFach (bit 6)

        	  //__CUSTOMIZE_HSDSCH_DRX_CELL_FACH_SUPPORT__
        	  pUMTS_USIME_RRC_dynamic_cap->r8_cap1 |= 0x02; //supportOfHsdschDrxOperation (bit 2)

        	  //__CUSTOMIZE_MAC_IIS_SUPPORT
        	  pUMTS_USIME_RRC_dynamic_cap->r8_cap2 |= 0x04; //supportOfMACiis  (bit 3)

        	  //__CUSTOMIZE_COMMON_EDCH_SUPPORT__
        	  pUMTS_USIME_RRC_dynamic_cap->r8_cap2 |= 0x02; // supportOfCommonEDCH  (bit 2)

        	  is_nvram_need_update = KAL_TRUE;
#endif
        	  break;
        default:
            // No need to update NVRAM
            is_nvram_need_update = KAL_FALSE;
            break;
    }

    // Update NVRAM setting if needed
    if (is_nvram_need_update == KAL_TRUE)
    {
        nvram_external_write_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_FDD_LID,
                                  1,
                                  nvram_read_buf_ptr,
                                  NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_FDD_SIZE);
        nvram_external_write_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TDD_LID,
                                  1,
                                  nvram_read_buf_tdd_ptr,
                                  NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TDD_SIZE);
    }

    // Free allocated buffer
    if (nvram_read_buf_ptr != NULL)
    {
        free_ctrl_buffer(nvram_read_buf_ptr);
        nvram_read_buf_ptr = NULL;
    }
    if (nvram_read_buf_tdd_ptr != NULL)
    {
        free_ctrl_buffer(nvram_read_buf_tdd_ptr);
        nvram_read_buf_tdd_ptr = NULL;
    }

    return is_nvram_need_update;
}

/*****************************************************************************
* FUNCTION
 *  nvram_custom_config_rrc_band_priority_order
 * DESCRIPTION
 *  Pre-process nvram data items forRRC at customer function.
 *  User can pre-process nvram data items using NVRAM external API here.
 *  nvram_external_write_data()
 *  nvram_external_read_data()
 * PARAMETERS
 *  sbp_id
 * RETURNS
 *  KAL_TRUE
 *****************************************************************************/
kal_bool nvram_custom_config_rrc_band_priority_order(kal_uint32 sbp_id)
{
    kal_uint8* nvram_read_buf_ptr = NULL;
    nvram_ef_umts_band_priority_struct* pUMTS_BAND_Priority;
    kal_bool is_nvram_need_update = KAL_FALSE;

    // Allocate buffer to read NVRAM setting
    nvram_read_buf_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_UMTS_BAND_PRIORITY_SIZE);

    // Read NVRAM setting
    nvram_external_read_data(NVRAM_EF_UMTS_BAND_PRIORITY_LID,
                             1,
                             nvram_read_buf_ptr,
                             NVRAM_EF_UMTS_BAND_PRIORITY_SIZE);
                             
    pUMTS_BAND_Priority = (nvram_ef_umts_band_priority_struct*)nvram_read_buf_ptr;

    switch (sbp_id)
    {

        case 20: /*Sprint*/
                {
                     /* Sprint UMTS Band priority order 5,2,1,4,8 */
                     kal_uint8 band_prio[NVRAM_EF_UMTS_BAND_PRIORITY_SIZE] = {0x03,0x02,0xFF,0x04,0x01,
                                                                              0xFF,0xFF,0x05,0xFF,0xFF,
                                                                              0xFF,0xFF,0xFF,0xFF,0xFF,
                                                                              0xFF,0xFF,0xFF,0xFF,0xFF,
                                                                              0xFF,0xFF,0xFF,0xFF,0xFF,
                                                                              0xFF};
                     
                     kal_mem_cpy(pUMTS_BAND_Priority->band, (nvram_ef_umts_band_priority_struct*)band_prio, NVRAM_EF_UMTS_BAND_PRIORITY_SIZE);
                     
                     is_nvram_need_update = KAL_TRUE;
                 
                };
                break;
        default:
            // No need to update NVRAM
            is_nvram_need_update = KAL_FALSE;
            break;
    }

    // Update NVRAM setting if needed
    if (is_nvram_need_update == KAL_TRUE)
    {
        nvram_external_write_data(NVRAM_EF_UMTS_BAND_PRIORITY_LID,
                                  1,
                                  nvram_read_buf_ptr,
                                  NVRAM_EF_UMTS_BAND_PRIORITY_SIZE);
    }

    // Free allocated buffer
    if (nvram_read_buf_ptr != NULL)
    {
        free_ctrl_buffer(nvram_read_buf_ptr);
        nvram_read_buf_ptr = NULL;
    }
    return is_nvram_need_update;
}

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_sbp_from_imsi_mcc_mnc
 * DESCRIPTION
 * Set SBP features and data according imsi mcc/mnc in OM load
 * PARAMETERS
 *  imsi  [IN]
 *  simInterface [IN]
 * RETURNS
 *   void
 *****************************************************************************/
void custom_nvram_set_sbp_from_imsi_mcc_mnc(kal_uint8 *imsi, kal_uint8 simInterface)
{
	kal_uint8 mcc1;
    kal_uint8 mcc2;
    kal_uint8 mcc3;
    kal_uint8 mnc1;
    kal_uint8 mnc2;
	kal_uint8 mnc3;
	
    /* derive MCC/MNC */
	mcc1 = (imsi[1] >> 4);
	mcc2 = (imsi[2] & 0x0f);
	mcc3 = (imsi[2] >> 4);
	mnc1 = (imsi[3] & 0x0f);
	mnc2 = (imsi[3] >> 4);
	mnc3 = (imsi[4] & 0x0f);

#if defined(__PCORE__)
	if(simInterface == SIM1 && sbp_config.sbp_mode == 0)//OM load
	{	
		/* reliance Jio */
		/* PLMN 405- 840, 410-854...859, 410-860...869, 410-870...874 */
		if (mcc1 == 0x04 && mcc2 == 0x00 && mcc3 == 0x05)
		{
		    if((mnc1 == 0x08 && mnc2 == 0x04 && mnc3 == 0x00) ||
			   (mnc1 == 0x08 && mnc2 == 0x05 && (mnc3 >= 0x04 && mnc3 <= 0x09)) ||
			   (mnc1 == 0x08 && mnc2 == 0x06 && (mnc3 >= 0x00 && mnc3 <= 0x09)) ||
			   (mnc1 == 0x08 && mnc2 == 0x07 && (mnc3 >= 0x00 && mnc3 <= 0x04)))
		    {
		       sbp_set_md_feature(SBP_DISABLE_DISPLAY_ROAMING_HPLMN_IN_EPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_config);
		  	   sbp_set_md_feature(SBP_SCA_CONFIGURED_BY_CUSTOMER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_config);
		       sbp_set_md_feature(SBP_CONVERT_ATTACH_REJECT_FROM_CAUSE_7_TO_14, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_config);
		    }
		}
    	/* place setting of other PLMNs here */
	}
#endif
}

#ifdef __LTE_RAT__
/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_errc_para
 * DESCRIPTION
 * Set ERRC para in nvram
 * PARAMETERS
 *  sbp_id
 * RETURNS
 *  none
 *****************************************************************************/
void custom_nvram_set_errc_para(kal_uint32 sbp_id)
{
    kal_uint8 *buf_performance;
    kal_uint8 *buf_eutra_cap_csfb;
    kal_uint8 *buf_eutra_cap_mmdc;
    kal_uint8 *buf_lte_cap;
    kal_uint8 *buf_vzw_lte_scan_enh_inf;
    kal_uint8 *buf_asband_setting;

    if (sbp_id == 3) //for Orange
    {
        nvram_ef_errc_performance_para_struct* pERRC_performance_para;
        buf_performance = get_ctrl_buffer(NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

        /* modify ERRC_PERFORMANCE_PARA_LID */
        nvram_external_read_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                1,
                                buf_performance,
                                NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

        pERRC_performance_para = (nvram_ef_errc_performance_para_struct*)buf_performance;
		
        //disable 3G AFR
        pERRC_performance_para->csfb_enhancement_item_status &= 0xEF;

        nvram_external_write_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                1,
                                buf_performance,
                                NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

        free_ctrl_buffer(buf_performance);
    }
    else if (sbp_id == 7 || sbp_id == 145) //for AT&T
    {
        kal_uint32 i, j;
        kal_uint32 att_plmn[] = {31118, 31041, 31015, 31017, 31038, 31056, 31068, 31007, 31009, 31003, 31028};
        kal_uint32 att_band[] = {4, 17, 12, 2, 5, 29, 30, 66};
        kal_uint32 num_att_plmn, num_att_band;

#ifdef __SGLTE__
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_mmdc;
#else
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_csfb;
#endif
        nvram_ef_errc_performance_para_struct* pERRC_performance_para;
        kal_uint8* p_asband_setting;

        /*disable b17 when AT&T*/
        buf_asband_setting = get_ctrl_buffer(NVRAM_EF_AS_BAND_SETTING_SIZE);

        nvram_external_read_data(NVRAM_EF_AS_BAND_SETTING_LID,
                                                      1,
                                                      buf_asband_setting,
                                                      NVRAM_EF_AS_BAND_SETTING_SIZE);

        p_asband_setting = (kal_uint8*)buf_asband_setting;

        //if band 12 is enabled, disable band 17
        if((p_asband_setting[6] & 0x08) == 0x08)
        {
           p_asband_setting[7] &= ~(0x01);
        }

        nvram_external_write_data(NVRAM_EF_AS_BAND_SETTING_LID,
                                                      1,
                                                      buf_asband_setting,
                                                      NVRAM_EF_AS_BAND_SETTING_SIZE);

        free_ctrl_buffer(buf_asband_setting);
        
        /* modify ERRC_PERFORMANCE_PARA_LID */
        buf_performance = get_ctrl_buffer(NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);
        
        nvram_external_read_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                                      1,
                                                      buf_performance,
                                                      NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);
        
        pERRC_performance_para = (nvram_ef_errc_performance_para_struct*)buf_performance;

        //disable 23G AFR for AT&T
        pERRC_performance_para->csfb_enhancement_item_status &= 0xE7;
        
        //adjust 'bar cell' mechanism
        pERRC_performance_para->trach = 6;
        pERRC_performance_para->max_kraerr = 4;
        pERRC_performance_para->traerr = 60;
        pERRC_performance_para->tvalid_raerr = 80;
        
        num_att_plmn = sizeof(att_plmn) / sizeof(kal_uint32);
        num_att_band = sizeof(att_band) / sizeof(kal_uint32);

        for (i = 0; i < num_att_plmn; i++)
        {
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc1 = (att_plmn[i] / 10000);
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc2 = (att_plmn[i] / 1000) % 10;
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc3 = (att_plmn[i] / 100) % 10;
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc1 = (att_plmn[i] / 10) % 10;
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc2 = (att_plmn[i] % 10);
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc3 = 0x0;
            
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].band_num = num_att_band;

            for (j = 0; j < num_att_band; j++)
            {
                pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].band_list[j] = att_band[j];	
            }
        } 

        //plmn=313100 (FirstNet)
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc1=0x3;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc2=0x1;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc3=0x3;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc1=0x1;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc2=0x0;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc3=0x0;

        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].band_num = 1;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].band_list[0] = 14;

        pERRC_performance_para->designated_carrier_inf.priority_band_inf_num = i + 1;
        
        nvram_external_write_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                                       1,
                                                       buf_performance,
                                                      NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

        free_ctrl_buffer(buf_performance);


        //disable FGI 1,9,10,23 for AT&T        
#ifdef __SGLTE__
        buf_eutra_cap_mmdc = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                                      1,
                                                      buf_eutra_cap_mmdc,
                                                      NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        pEutra_cap_mmdc = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_mmdc;

        pEutra_cap_mmdc->feature_group_ind_fdd &= (~(ERRC_FGI_01));
        pEutra_cap_mmdc->feature_group_ind_tdd &= (~(ERRC_FGI_01));
        pEutra_cap_mmdc->feature_group_ind_fdd &= (~(ERRC_FGI_09));
        pEutra_cap_mmdc->feature_group_ind_tdd &= (~(ERRC_FGI_09));
        pEutra_cap_mmdc->feature_group_ind_fdd &= (~(ERRC_FGI_10));
        pEutra_cap_mmdc->feature_group_ind_tdd &= (~(ERRC_FGI_10));
        pEutra_cap_mmdc->feature_group_ind_fdd &= (~(ERRC_FGI_23));
        pEutra_cap_mmdc->feature_group_ind_tdd &= (~(ERRC_FGI_23));
        pEutra_cap_mmdc->feature_group_ind_add_r9_fdd &= (~(ERRC_FGI_34));
        pEutra_cap_mmdc->feature_group_ind_add_r9_tdd &= (~(ERRC_FGI_34));
        pEutra_cap_mmdc->feature_group_ind_r10_fdd &= (~(ERRC_FGI_108));
        pEutra_cap_mmdc->feature_group_ind_r10_tdd &= (~(ERRC_FGI_108));

        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                                      1,
                                                      buf_eutra_cap_mmdc,
                                                      NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        free_ctrl_buffer(buf_eutra_cap_mmdc);
#else
        buf_eutra_cap_csfb = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);

        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                                      1,
                                                      buf_eutra_cap_csfb,
                                                      NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
		

        pEutra_cap_csfb = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_csfb;

        pEutra_cap_csfb->feature_group_ind_fdd &= (~(ERRC_FGI_01));
        pEutra_cap_csfb->feature_group_ind_tdd &= (~(ERRC_FGI_01));        
        pEutra_cap_csfb->feature_group_ind_fdd &= (~(ERRC_FGI_09));
        pEutra_cap_csfb->feature_group_ind_tdd &= (~(ERRC_FGI_09));       
        pEutra_cap_csfb->feature_group_ind_fdd &= (~(ERRC_FGI_10));
        pEutra_cap_csfb->feature_group_ind_tdd &= (~(ERRC_FGI_10));
        pEutra_cap_csfb->feature_group_ind_fdd &= (~(ERRC_FGI_23));
        pEutra_cap_csfb->feature_group_ind_tdd &= (~(ERRC_FGI_23));
        pEutra_cap_csfb->feature_group_ind_add_r9_fdd &= (~(ERRC_FGI_34));
        pEutra_cap_csfb->feature_group_ind_add_r9_tdd &= (~(ERRC_FGI_34));
        pEutra_cap_csfb->feature_group_ind_r10_fdd &= (~(ERRC_FGI_108));
        pEutra_cap_csfb->feature_group_ind_r10_tdd &= (~(ERRC_FGI_108));

        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                                       1,
                                                       buf_eutra_cap_csfb,
                                                       NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
		
        free_ctrl_buffer(buf_eutra_cap_csfb);
#endif
        
    }
    else if (sbp_id == 8) // for TMO-US
    {
#ifdef __SGLTE__
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_mmdc;
#else
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_csfb;
#endif

        
#ifdef __SGLTE__
        buf_eutra_cap_mmdc = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                                      1,
                                                      buf_eutra_cap_mmdc,
                                                      NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        pEutra_cap_mmdc = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_mmdc;

        pEutra_cap_mmdc->feature_group_ind_fdd &= (~(ERRC_FGI_29));
				pEutra_cap_mmdc->feature_group_ind_tdd &= (~(ERRC_FGI_29));

        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                                      1,
                                                      buf_eutra_cap_mmdc,
                                                      NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        free_ctrl_buffer(buf_eutra_cap_mmdc);
#else
        buf_eutra_cap_csfb = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);

        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                                      1,
                                                      buf_eutra_cap_csfb,
                                                      NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
		

        pEutra_cap_csfb = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_csfb;

        pEutra_cap_csfb->feature_group_ind_fdd &= (~(ERRC_FGI_29));
        pEutra_cap_csfb->feature_group_ind_tdd &= (~(ERRC_FGI_29));


        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                                       1,
                                                       buf_eutra_cap_csfb,
                                                       NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
		
        free_ctrl_buffer(buf_eutra_cap_csfb);
#endif
    }
    else if (sbp_id == 9) // for CT
    {
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_csfb;
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_mmdc;
        nvram_ef_errc_vzw_lte_scan_enhance_struct *p_vzw_lte_scan_enh_inf;
        buf_eutra_cap_csfb = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
        buf_eutra_cap_mmdc = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);
        buf_vzw_lte_scan_enh_inf = get_ctrl_buffer(NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_SIZE);
		
	 /* disable ue-SpecificRefSigsSupported */
        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                                      1,
                                                      buf_eutra_cap_csfb,
                                                      NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
		
        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                                      1,
                                                      buf_eutra_cap_mmdc,
                                                      NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        nvram_external_read_data(NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_LID,
                                                      1,
                                                      buf_vzw_lte_scan_enh_inf,
                                                      NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_SIZE);

        pEutra_cap_csfb = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_csfb;
        pEutra_cap_csfb->phylayer_param.ue_specific_ref_sigs = 0;
        pEutra_cap_mmdc = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_mmdc;
        pEutra_cap_mmdc->phylayer_param.ue_specific_ref_sigs = 0;

        p_vzw_lte_scan_enh_inf = (nvram_ef_errc_vzw_lte_scan_enhance_struct *)buf_vzw_lte_scan_enh_inf;
        p_vzw_lte_scan_enh_inf->LTE_scan_active_duration_1xRTT = 0x02; //unit in 500ms
        p_vzw_lte_scan_enh_inf->LTE_scan_active_duration_DO = 0x03; //unit in 100ms
        p_vzw_lte_scan_enh_inf->LTE_scan_active_interval_1xRTT = 0x3c; //unit in 500ms
        p_vzw_lte_scan_enh_inf->LTE_scan_active_interval_DO = 0x3c; //unit in 500ms 
        

        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                                       1,
                                                       buf_eutra_cap_csfb,
                                                       NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
		
        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                                      1,
                                                      buf_eutra_cap_mmdc,
                                                      NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        nvram_external_write_data(NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_LID,
                                                      1,
                                                      buf_vzw_lte_scan_enh_inf,
                                                      NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_SIZE);

        free_ctrl_buffer(buf_eutra_cap_csfb);
        free_ctrl_buffer(buf_eutra_cap_mmdc);
        free_ctrl_buffer(buf_vzw_lte_scan_enh_inf);
    }
    else if (sbp_id == 12) //for VzW
    {
        nvram_ef_errc_performance_para_struct* pERRC_performance_para;
        buf_performance = get_ctrl_buffer(NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);
		
        /* modify ERRC_PERFORMANCE_PARA_LID */
        nvram_external_read_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                                      1,
                                                      buf_performance,
                                                      NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);
						
        pERRC_performance_para = (nvram_ef_errc_performance_para_struct*)buf_performance;
		
        pERRC_performance_para->designated_carrier_inf.priority_band_inf_num = 2;

        //Dennis Weng 2014/12/09: set priority band record
        //plmn=ffffff (default)
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mcc1=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mcc2=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mcc3=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mnc1=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mnc2=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mnc3=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].band_num=7;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].band_list[0]=13;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].band_list[1]=4;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].band_list[2]=3;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].band_list[3]=7;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].band_list[4]=20;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].band_list[5]=5;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].band_list[6]=2;
		
        //plmn=310fff
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].plmn_id.mcc1=0x3;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].plmn_id.mcc2=0x1;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].plmn_id.mcc3=0x0;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].plmn_id.mnc1=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].plmn_id.mnc2=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].plmn_id.mnc3=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].band_num=4;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].band_list[0]=13;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].band_list[1]=4;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].band_list[2]=2;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[1].band_list[3]=5;        

        /* Adjust 'bar cell' mechanism (for SBP_EMM_CONN_FAIL_ABNORMAL_B) */
        pERRC_performance_para->trach = 60;
        pERRC_performance_para->max_kraerr = 30;
        pERRC_performance_para->traerr = 55;
        pERRC_performance_para->tvalid_raerr = 60;

        nvram_external_write_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                                       1,
                                                       buf_performance,
                                                      NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

        free_ctrl_buffer(buf_performance);

    }
    else if (sbp_id == 20) // for Sprint
    {
#ifdef __SGLTE__
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_mmdc;
#else
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_csfb;
#endif
        kal_uint32 i, j;
        kal_uint32 mcc[] = {310, 311, 312, 313, 314, 315, 316, 330};        
        kal_uint32 band1[] = {25, 26, 41, 12, 2, 4, 5};
        kal_uint32 band_default[] = {41, 2, 4, 5};        
        kal_uint32 num_mcc, num_band1, num_band_default;
        nvram_ef_errc_performance_para_struct* pERRC_performance_para;
        nvram_ef_errc_vzw_lte_scan_enhance_struct *p_vzw_lte_scan_enh_inf;

#ifdef __SGLTE__
        buf_eutra_cap_mmdc = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                                      1,
                                                      buf_eutra_cap_mmdc,
                                                      NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        pEutra_cap_mmdc = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_mmdc;
        pEutra_cap_mmdc->feature_group_ind_fdd &= (~(ERRC_FGI_03));
        pEutra_cap_mmdc->feature_group_ind_tdd &= (~(ERRC_FGI_03));
        pEutra_cap_mmdc->feature_group_ind_fdd &= (~(ERRC_FGI_28));
        pEutra_cap_mmdc->feature_group_ind_fdd &= (~(ERRC_FGI_27));
        pEutra_cap_mmdc->feature_group_ind_fdd &= (~(ERRC_FGI_29));
        pEutra_cap_mmdc->phylayer_param.ue_specific_ref_sigs = 0;
        pEutra_cap_mmdc->nei_cell_si_acq_r9.intraFreqSI_AcquisitionForHO_r9_fdd = 0;
        pEutra_cap_mmdc->nei_cell_si_acq_r9.intraFreqSI_AcquisitionForHO_r9_tdd = 0;
        pEutra_cap_mmdc->nei_cell_si_acq_r9.interFreqSI_AcquisitionForHO_r9_fdd = 0;
        pEutra_cap_mmdc->nei_cell_si_acq_r9.interFreqSI_AcquisitionForHO_r9_tdd = 0;
        pEutra_cap_mmdc->nei_cell_si_acq_r9.utran_SI_AcquisitionForHO_r9_fdd = 0;
        pEutra_cap_mmdc->nei_cell_si_acq_r9.utran_SI_AcquisitionForHO_r9_tdd = 0;

       nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                                      1,
                                                      buf_eutra_cap_mmdc,
                                                      NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        free_ctrl_buffer(buf_eutra_cap_mmdc);
#else
        buf_eutra_cap_csfb = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);

        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                                      1,
                                                      buf_eutra_cap_csfb,
                                                      NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
		

        pEutra_cap_csfb = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_csfb;
        pEutra_cap_csfb->feature_group_ind_fdd &= (~(ERRC_FGI_03));
        pEutra_cap_csfb->feature_group_ind_tdd &= (~(ERRC_FGI_03));
        pEutra_cap_csfb->feature_group_ind_fdd &= (~(ERRC_FGI_27));
        pEutra_cap_csfb->feature_group_ind_fdd &= (~(ERRC_FGI_28));
        pEutra_cap_csfb->feature_group_ind_fdd &= (~(ERRC_FGI_29));
        pEutra_cap_csfb->phylayer_param.ue_specific_ref_sigs = 0;
        pEutra_cap_csfb->nei_cell_si_acq_r9.intraFreqSI_AcquisitionForHO_r9_fdd = 0;
        pEutra_cap_csfb->nei_cell_si_acq_r9.intraFreqSI_AcquisitionForHO_r9_tdd = 0;
        pEutra_cap_csfb->nei_cell_si_acq_r9.interFreqSI_AcquisitionForHO_r9_fdd = 0;
        pEutra_cap_csfb->nei_cell_si_acq_r9.interFreqSI_AcquisitionForHO_r9_tdd = 0;
        pEutra_cap_csfb->nei_cell_si_acq_r9.utran_SI_AcquisitionForHO_r9_fdd = 0;
        pEutra_cap_csfb->nei_cell_si_acq_r9.utran_SI_AcquisitionForHO_r9_tdd = 0;

        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                                       1,
                                                       buf_eutra_cap_csfb,
                                                       NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
		
        free_ctrl_buffer(buf_eutra_cap_csfb);
#endif

        /*Apply band scarn priority*/
        buf_performance = get_ctrl_buffer(NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

        /* modify ERRC_PERFORMANCE_PARA_LID */
        nvram_external_read_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                  1,
                                  buf_performance,
                                  NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

        pERRC_performance_para = (nvram_ef_errc_performance_para_struct*)buf_performance;

        num_mcc = sizeof(mcc) / sizeof(kal_uint32);
        num_band1 = sizeof(band1) / sizeof(kal_uint32);
        
        // plmn in North america , mcc = 310~316 or 330
        // 1. NA area: search B25, 26, 41, 12, 2, 4, 5 when MCC is 310~316 or 330
        // 2. non NA area: search B41, 2, 4, 5
        for (i = 0; i < num_mcc; i++)
        {
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc1 = (mcc[i] / 100);
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc2 = (mcc[i] / 10) % 10;
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc3 = (mcc[i] % 10);
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc1 = 0xf;
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc2 = 0xf;
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc3 = 0xf;
            
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].band_num = num_band1;

            for (j = 0; j < num_band1; j++)
            {
                pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].band_list[j] = band1[j];	
            }
        }

        //plmn=ffffff (default)
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc1=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc2=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mcc3=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc1=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc2=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].plmn_id.mnc3=0xf;

        num_band_default = sizeof(band_default) / sizeof(kal_uint32);

        pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].band_num = num_band_default;
        
        for (j = 0; j < num_band_default; j++)
        {
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[i].band_list[j] = band_default[j];	
        }        

        pERRC_performance_para->designated_carrier_inf.priority_band_inf_num = i + 1;
        
        nvram_external_write_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                   1,
                                   buf_performance,
                                   NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);
       
        free_ctrl_buffer(buf_performance);

        /* apply LTE_SCAN_ENHANCEMENT parameter */
        buf_vzw_lte_scan_enh_inf = get_ctrl_buffer(NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_SIZE);

        /* modify ERRC_VZW_LTE_SCAN_ENHANCE_LID */
        nvram_external_read_data(NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_LID,
                                  1,
                                  buf_vzw_lte_scan_enh_inf,
                                  NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_SIZE);

        p_vzw_lte_scan_enh_inf = (nvram_ef_errc_vzw_lte_scan_enhance_struct *)buf_vzw_lte_scan_enh_inf;
        p_vzw_lte_scan_enh_inf->LTE_scan_active_duration_1xRTT = 0x02; //unit in 500ms
        p_vzw_lte_scan_enh_inf->LTE_scan_active_duration_DO = 0x03; //unit in 100ms
        p_vzw_lte_scan_enh_inf->LTE_scan_active_interval_1xRTT = 0x3c; //unit in 500ms
        p_vzw_lte_scan_enh_inf->LTE_scan_active_interval_DO = 0x3c; //unit in 500ms 
      
        nvram_external_write_data(NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_LID,
                                   1,
                                   buf_vzw_lte_scan_enh_inf,
                                   NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_SIZE);

        free_ctrl_buffer(buf_vzw_lte_scan_enh_inf);

    }
    else if(sbp_id == 50) //for Softbank
    {
        nvram_ef_lte_cap_struct* pLte_cap;
#ifdef __SGLTE__
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_mmdc;
#else
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_csfb;
#endif
        kal_uint32 j;
        kal_uint32 band_default[] = {41, 1, 3, 8, 25, 26, 2, 4, 5, 7, 12, 17, 38, 39, 40};
        kal_uint32 num_band_default;        
        nvram_ef_errc_performance_para_struct* pERRC_performance_para;        
        
        buf_lte_cap = get_ctrl_buffer(NVRAM_EF_LTE_CAP_SIZE);

        /* turn on Disable BW */
        nvram_external_read_data(NVRAM_EF_LTE_CAP_LID, 1, buf_lte_cap, NVRAM_EF_LTE_CAP_SIZE);
           
        pLte_cap = (nvram_ef_lte_cap_struct*)buf_lte_cap;
        pLte_cap->disable_bw[0] = 0x03;
        pLte_cap->disable_bw[7] = 0x30;
        pLte_cap->disable_bw[40] = 0x17;

        nvram_external_write_data(NVRAM_EF_LTE_CAP_LID,1, buf_lte_cap, NVRAM_EF_LTE_CAP_SIZE);

        free_ctrl_buffer(buf_lte_cap);

#ifdef __SGLTE__
        buf_eutra_cap_mmdc = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                                      1,
                                                      buf_eutra_cap_mmdc,
                                                      NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        pEutra_cap_mmdc = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_mmdc;
        pEutra_cap_mmdc->feature_group_ind_fdd &= (~(ERRC_FGI_31));
        pEutra_cap_mmdc->feature_group_ind_tdd &= (~(ERRC_FGI_31));
        pEutra_cap_mmdc->phylayer_param.ue_specific_ref_sigs = 0;

        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                                       1,
                                                       buf_eutra_cap_mmdc,
                                                       NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        free_ctrl_buffer(buf_eutra_cap_mmdc);
#else
        buf_eutra_cap_csfb = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);

		
        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                                      1,
                                                      buf_eutra_cap_csfb,
                                                      NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);           

        pEutra_cap_csfb = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_csfb;
        pEutra_cap_csfb->feature_group_ind_fdd &= (~(ERRC_FGI_31));
        pEutra_cap_csfb->feature_group_ind_tdd &= (~(ERRC_FGI_31));
        pEutra_cap_csfb->phylayer_param.ue_specific_ref_sigs = 0;

        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                                       1,
                                                       buf_eutra_cap_csfb,
                                                       NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);			

        free_ctrl_buffer(buf_eutra_cap_csfb);
#endif

        /*Apply band scarn priority*/
        /* modify ERRC_PERFORMANCE_PARA_LID */
        buf_performance = get_ctrl_buffer(NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);	

        nvram_external_read_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                  1,
                                  buf_performance,
                                  NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

        pERRC_performance_para = (nvram_ef_errc_performance_para_struct*)buf_performance;
        
       //plmn=ffffff (default)
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mcc1=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mcc2=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mcc3=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mnc1=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mnc2=0xf;
        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].plmn_id.mnc3=0xf;

        num_band_default = sizeof(band_default) / sizeof(kal_uint32);

        pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].band_num = num_band_default;
        
        for (j = 0; j < num_band_default; j++)
        {
            pERRC_performance_para->designated_carrier_inf.priority_band_inf[0].band_list[j] = band_default[j];	
        }        

        pERRC_performance_para->designated_carrier_inf.priority_band_inf_num = 1;

        //disable 3G AFR
        pERRC_performance_para->csfb_enhancement_item_status &= 0xEF;

        nvram_external_write_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                   1,
                                   buf_performance,
                                   NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

        free_ctrl_buffer(buf_performance);
        
    }
}
/***************************************************************************** 
 * FUNCTION 
 *  custom_nvram_set_lte_pref 
 * DESCRIPTION 
 * Set LTE preferences in nvram 
 * PARAMETERS 
 *  sbp_id 
 * RETURNS 
 *  none 
 *****************************************************************************/ 
void custom_nvram_set_lte_pref(kal_uint32 sbp_id) 
{ 
    nvram_ef_lte_preference_struct* pLte_pref; 
    kal_uint8* nvram_read_buf_ptr; 

    //for Orange, Vodafone/India, Movistar/Columbia and VHA/Australia, disable SMS over IP due to NW not supported
    if ((sbp_id == 3) || (sbp_id == 111) || (sbp_id == 132) || (sbp_id == 153)) 
    { 
        nvram_read_buf_ptr = get_ctrl_buffer(NVRAM_EF_LTE_PREFERENCE_SIZE); 

        nvram_external_read_data(NVRAM_EF_LTE_PREFERENCE_LID, 1, nvram_read_buf_ptr, NVRAM_EF_LTE_PREFERENCE_SIZE); 

        pLte_pref = (nvram_ef_lte_preference_struct*)nvram_read_buf_ptr; 

        /* turn off SMS over IP */ 
        pLte_pref->sms_over_ip = 0x00; 

        nvram_external_write_data(NVRAM_EF_LTE_PREFERENCE_LID, 1, nvram_read_buf_ptr, NVRAM_EF_LTE_PREFERENCE_SIZE); 

        if (MAX_SIM_NUM > 1) 
        { 
            memset(nvram_read_buf_ptr, 0, NVRAM_EF_LTE_PREFERENCE_SIZE); 

            nvram_external_read_data(NVRAM_EF_LTE_PREFERENCE_LID, 2, nvram_read_buf_ptr, NVRAM_EF_LTE_PREFERENCE_SIZE); 

            pLte_pref = (nvram_ef_lte_preference_struct*)nvram_read_buf_ptr; 

            /* turn off SMS over IP */ 
            pLte_pref->sms_over_ip = 0x00; 

            nvram_external_write_data(NVRAM_EF_LTE_PREFERENCE_LID, 2, nvram_read_buf_ptr, NVRAM_EF_LTE_PREFERENCE_SIZE); 
        } 
        free_ctrl_buffer(nvram_read_buf_ptr); 
    } 
} 

#endif /* __LTE_RAT__ */ 

/*****************************************************************************
 * FUNCTION
 *  custom_reset_nvram_lids
 * DESCRIPTION
 *  This function will reset nvram parameters to the default value for the lids present in the table nvram_lid_reset_func_tbl
 * PARAMETERS
 *   SBP ID: this is the new sbp_id received from the CCCI
 * RETURNS
 *****************************************************************************/
void custom_reset_nvram_lids(kal_uint32 sbp_id)
{
    kal_uint8 table_size = 0, i = 0;
	nvram_ef_sbp_modem_config_struct *sbp_feature_buf;
	
	sbp_feature_buf = (nvram_ef_sbp_modem_config_struct*)get_ctrl_buffer
						(sizeof(nvram_ef_sbp_modem_config_struct));

	nvram_external_read_data(NVRAM_EF_SBP_MODEM_CONFIG_LID, 
							 1,
							 (kal_uint8*)sbp_feature_buf, 
						     NVRAM_EF_SBP_MODEM_CONFIG_SIZE);

	old_sbp_id = sbp_feature_buf->sbp_mode;

	/* This Prompt trace is for Testing Purpose and will be omitted in MAIN branch Check-in*/
    //kal_prompt_trace(MOD_L4C, "Old SBP_ID = %d , New SBP_ID = %d", old_sbp_id, sbp_id);

	if(old_sbp_id != sbp_id)
	{
	    table_size = sizeof(nvram_lid_reset_func_tbl)/sizeof(sbp_nvram_lid_reset_table);

		for(i = 0; i < table_size; i++)
		{
		  nvram_lid_reset_func_tbl[i].sbp_reset_nvram_lid_funcptr();
		}
	}

	// Free allocated buffer
    if (sbp_feature_buf != NULL)
    {
        free_ctrl_buffer(sbp_feature_buf);
        sbp_feature_buf = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  nvram_custom_reset_rrc_dynamic_cap
 * DESCRIPTION
 *  This function will reset nvram parameters to the default value for NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID.
 * PARAMETERS
 *   null
 * RETURNS
 *****************************************************************************/
void nvram_custom_reset_rrc_dynamic_cap()
{
	kal_uint8* nvram_write_buf_ptr = NULL;

	if (NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_FDD_LID,
															 1,
															 &nvram_write_buf_ptr))
	{
		nvram_external_write_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_FDD_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_FDD_SIZE);
	}

	if (NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TDD_LID,
															 1,
															 &nvram_write_buf_ptr))
	{
		nvram_external_write_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TDD_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TDD_SIZE);
	}
}

/*****************************************************************************
 * FUNCTION
 *  nvram_custom_reset_mscap
 * DESCRIPTION
 *  This function will reset nvram parameters to the default value for NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID.
 * PARAMETERS
 *   null
 * RETURNS
 *****************************************************************************/
void nvram_custom_reset_mscap()
{
	kal_uint8* nvram_write_buf_ptr = NULL;

	if (NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_MSCAP_LID,
															 1,
															 &nvram_write_buf_ptr))
	{
		nvram_external_write_data(NVRAM_EF_MSCAP_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_MSCAP_SIZE);
	}

}

#ifdef __LTE_RAT__
/*****************************************************************************
 * FUNCTION
 *  nvram_custom_reset_errc_para
 * DESCRIPTION
 *  This function will reset nvram parameters to the default value for 
 *  1. NVRAM_EF_UE_EUTRA_CAP_CSFB_LID
 *  2. NVRAM_EF_UE_EUTRA_CAP_MMDC_LID
 *  3. NVRAM_EF_ERRC_PERFORMANCE_PARA_LID
 *  4. NVRAM_EF_LTE_CAP_LID
 * PARAMETERS
 *   null
 * RETURNS
 *****************************************************************************/
void nvram_custom_reset_errc_para()
{
    kal_uint8* nvram_write_buf_ptr = NULL;

    //NVRAM_EF_UE_EUTRA_CAP_CSFB_LID
	if(NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
															1, 
															&nvram_write_buf_ptr))
	{
	    nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
	}		

    //NVRAM_EF_UE_EUTRA_CAP_MMDC_LID
	if(NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
															1, 
															&nvram_write_buf_ptr))
	{
	    nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);
	}		

    //NVRAM_EF_ERRC_PERFORMANCE_PARA_LID
	if(NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
															1, 
															&nvram_write_buf_ptr))
	{
	    nvram_external_write_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);
	}		

    //NVRAM_EF_LTE_CAP_LID
	if(NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_LTE_CAP_LID,
															1, 
															&nvram_write_buf_ptr))
	{
	    nvram_external_write_data(NVRAM_EF_LTE_CAP_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_LTE_CAP_SIZE);
	}		

}

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_reset_lte_pref
 *
 * DESCRIPTION
 *  This function will reset nvram parameters to the default value for NVRAM_EF_LTE_PREFERENCE_LID.
 *
 * PARAMETERS
 *  none
 *
 * RETURNS
 *  none
 *
 *****************************************************************************/
void custom_nvram_reset_lte_pref()
{
    kal_uint8* nvram_write_buf_ptr = NULL;
    
	if(NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_LTE_PREFERENCE_LID,
															1, 
															&nvram_write_buf_ptr))
	{
	    nvram_external_write_data(NVRAM_EF_LTE_PREFERENCE_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_LTE_PREFERENCE_SIZE);
	}		

    return;
    
} /* end of custom_nvram_reset_lte_pref() */
#endif /* __LTE_RAT__ */

#ifdef __VOLTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  nvram_custom_reset_vdm_ads_profile
 *
 * DESCRIPTION
 *  This function will reset nvram parameters to the default value for NVRAM_EF_VDM_ADS_PROFILE_LID.
 *
 * PARAMETERS
 *  none
 *
 * RETURNS
 *  none
 *
 *****************************************************************************/
void nvram_custom_reset_vdm_ads_profile()
{
    kal_uint8* nvram_write_buf_ptr = NULL;

    if (NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_VDM_ADS_PROFILE_LID,
                                                             1,
                                                             &nvram_write_buf_ptr))
    {
        nvram_external_write_data(NVRAM_EF_VDM_ADS_PROFILE_LID,
                                  1,
                                  nvram_write_buf_ptr,
                                  NVRAM_EF_VDM_ADS_PROFILE_SIZE);
    }
    
    return;
}
#endif /* __VOLTE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *	custom_nvram_reset_regional_phone_mode
 *
 * DESCRIPTION
 *	This function will reset nvram parameters to the default value for NVRAM_EF_REGIONAL_PHONE_MODE_LID.
 *
 * PARAMETERS
 *	none
 *
 * RETURNS
 *	none
 *
 *****************************************************************************/
void custom_nvram_reset_regional_phone_mode()
{
	kal_uint8* nvram_write_buf_ptr = NULL;
	nvram_ef_regional_phone_mode_struct regional_phone_mode;
	nvram_default_value_enum result;

	result = nvram_get_default_value(NVRAM_EF_REGIONAL_PHONE_MODE_LID,
									1,
									&nvram_write_buf_ptr);

	if (NVRAM_DEFAULT_VALUE_ZERO == result)
	{
		
		regional_phone_mode.mode = 0;
		nvram_external_write_data(NVRAM_EF_REGIONAL_PHONE_MODE_LID, 
								  1, 
								  (kal_uint8*)&regional_phone_mode, 
								  NVRAM_EF_REGIONAL_PHONE_MODE_SIZE);

	}
	else if (NVRAM_DEFAULT_VALUE_FF == result)
	{
		
		regional_phone_mode.mode = 0xff;
		nvram_external_write_data(NVRAM_EF_REGIONAL_PHONE_MODE_LID, 
								  1, 
								  (kal_uint8*)&regional_phone_mode, 
								  NVRAM_EF_REGIONAL_PHONE_MODE_SIZE);

	
	}
	
	return;
}

/*****************************************************************************
 * FUNCTION
 *	custom_nvram_reset_ltecsr_profile
 *
 * DESCRIPTION
 *	This function will reset nvram parameters to the default value for NVRAM_EF_LTECSR_PROFILE_LID.
 *
 * PARAMETERS
 *	none
 *
 * RETURNS
 *	none
 *
 *****************************************************************************/
void custom_nvram_reset_ltecsr_profile()
{
#if defined (__MOD_IMC__)

	kal_uint8* nvram_write_buf_ptr = NULL;

	if (NVRAM_DEFAULT_VALUE_POINT == nvram_get_default_value(NVRAM_EF_LTECSR_PROFILE_LID,
															 1,
															 &nvram_write_buf_ptr))
	{
		nvram_external_write_data(NVRAM_EF_LTECSR_PROFILE_LID,
								  1,
								  nvram_write_buf_ptr,
								  NVRAM_EF_LTECSR_PROFILE_SIZE);
	}
	
	return;
#endif
}




