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
 *   init.c
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
 * removed!
 * removed!
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
  * 04 06 2013 shenghui.shi
 * removed!
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
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
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
 *
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
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
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
 *
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
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

//#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

// kal
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "kal_trace.h"
#include "reg_base.h"

// init
#include "cp15.h"
#include "config_hw.h"
//#include "init.h"
#include "init_comm.h"
#include "ex_item.h"
// trace
#include "system_trc.h"             //INT_Trace_Enter, INT_Trace_Exit
#include "init_trc_api.h"           //INT_Trace_Enter, INT_Trace_Exit

// system service hw
#include "dsp_file_public.h"        // DSP_Init
#include "ect.h"                    // ECT_Init
#include "bus_drv.h"                // Bus_Init
#include "drv_pcmon.h"              // PCMon driver init
#include "drv_gdma.h"               // GDMA driver init
// system service sw
#include "stack_buff_pool.h"        //stack_resources_init, stack_init_buff_pool_info
#include "ex_item.h"                // ex_memory_dump_init
#include "ex_mem_manager_public.h"  // EMM_Init
#include "mpu.h"                    // CPU_SET_STACK_MPU_PROTECT, mpu_dump

//misc
#include "dcl.h"                    // for peripheral related
#include "wdt_hw_public.h"          //Get_WATCHDOG_BASE, Get_WATCHDOG_RESTART_CMD
#if defined(__SMART_PHONE_MODEM__)
#include "ccci.h"
#endif
#ifdef __HIF_CCCI_SUPPORT__
#include "ccci_if.h"
#endif
#ifdef __CENTRALIZED_SLEEP_MANAGER__
#include "us_timer.h"
#endif
#if !defined(__UBL__) && !defined(__FUE__)
#ifdef __CENTRALIZED_SLEEP_MANAGER__
#include "ostd_public.h"
extern void SleepDrv_Init( void );
extern void RM_Init( void );
#else
extern void startSystemTimer(void);
#endif
#endif
#if DVFS_ENABLE
/* From MODEML1_DVFS.c */
extern void MODEML1_DVFS_Init( void );
#endif /* DVFS_ENABLE */

#if defined(__MTK_TARGET__)
#include "ptp_public.h"
#endif

#include "cc_irq_public.h"
#include "drv_mdap_interface.h"


/******************************************************
 * Declaration and definition of global data
 ******************************************************/
// PCMon
PCM_RECORD l1_pcmon_log;
// WDT
WDT_CTRL_ENABLE_T wdt_data;
DCL_HANDLE init_dcl_wdt_handle;
DCL_HANDLE init_dcl_handle;

DEFINE_NC_SHARED_VAR(volatile kal_uint16, _boot_mode);
DEFINE_NC_SHARED_VAR(volatile kal_uint32, g_l_sw_misc_l);
DEFINE_NC_SHARED_VAR(volatile kal_bool, _IsBootForUSBAT);
DEFINE_NC_SHARED_VAR(volatile INITSYNC_STATE, INT_PSCoreBootModeSync);


typedef enum
{
    E_CHAR,
    E_HALFWORD,
    E_WORD
} POLLING_TYPE;
typedef enum
{
    E_LOCK,
    E_UNLOCK,
    E_GOTHROUGH
} POLLING_LOCK;


DEFINE_NC_SHARED_VAR(volatile INITSYNC_STATE, INT_PCoreSchedulingSync);
DEFINE_NC_SHARED_VAR(volatile INITSYNC_STATE, INT_L1CoreSchedulingSync);
DEFINE_NC_SHARED_VAR(volatile INITSYNC_STATE, INT_PCoreRegionInitSync);
DEFINE_NC_SHARED_VAR(volatile INITSYNC_STATE, INT_L1CoreRegionInitSync);


kal_uint32 init_duration;

__attribute__ ((section("INTSRAM_ZI"))) ECO_VERSION eco_version; /* only used in PLL setup */

static const kal_uint32 RAND_GEN_START_ADDR = 0x70002000;

#if !defined(__SMART_PHONE_MODEM__) && !defined(__MODEM_ONLY__)

#define INT_CLEAR_RETN_FLAG(_flag)
#define INT_CLEAR_SET_FLAG(_flag)

#endif


/******************************************************
 * Declaration of function prototype
 ******************************************************/
/* Application_Initialize */
static void systemInitialization(void);
static void HWDInitialization(void);
static void systemInitializeResource(void);


/******************************************************
 * Declaration of import data and function prototype
 ******************************************************/
/* Application_Initialize */
// WDT
extern boot_mode_type system_boot_mode;
extern kal_uint32 WATCHDOG_BASE;
extern kal_uint32 WATCHDOG_RESTART_CMD;

// SYSstack protection
extern kal_uint32 SYS_Stack_Pool[];

//Init
#ifndef __BL_ENABLE__
extern void boot_init_clock();
#endif
extern void Drv_Init_Phase1(void);
extern void Drv_Init_Phase2(void);
extern int  mainp(void);
extern kal_uint32 SLA_Init(void);
#if defined(DEBUG_SWLA)
    extern kal_uint32 SLA_Enable(void); // enable SWLA by default for easy debug  
#endif

/* HWDInitialization */
#ifdef MTK_SLEEP_ENABLE
    #ifdef __GSM_RAT__
    extern void L1SM_Init( void );
    #endif
    #ifdef __MTK_UL1_FDD__
    extern void UL1SM_Init(void);
    #endif
    #ifdef __LTE_RAT__
    extern void EL1SM_Init(void);
    #endif
#endif

/* systemInitialization */
extern void kal_initialize_mem(void);
extern void kal_profile_init(void);

/* systemInitializeResource */
extern kal_uint32 rand_num_seed;

/******************************************************
 * Definition of functions
 ******************************************************/

/*
* NoteXXX:
*    Please DO NOT place your code in the execution region EMIINITCODE.
*    Code in this region is used for EMI/PLL initialization, and will be
*    OVERWRITTEN after INT_InitRegions.
*/
/*__FUE__ compile option is used for FOTA firmware update engine */
/*add this  compile option  to avoid compiling other function*/

#ifndef __FUE__
/*************************************************************************
* FUNCTION
*  INTInitializeSync
*
* DESCRIPTION
*  This function implements L1Core waiting for PSCore region init.
*
* CALLS
*  Non
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INTInitializeSync(void)
{
#if !defined(__L1CORE_ONLY__)
    while(*SHARED_pVAR(INT_PCoreRegionInitSync) != 0x760404);
    *SHARED_pVAR(INT_PCoreRegionInitSync) = 0x0;
#endif
}
void INT_PSCoreRegionInitPolling(void)
{
    INITSYNC_WriteAndPoll(SHARED_pVAR(INT_L1CoreRegionInitSync), SHARED_pVAR(INT_PCoreRegionInitSync));
}


/*************************************************************************
* FUNCTION
*  Application_Initialize
*
* DESCRIPTION
*   This function implements project protocol stack, hardware depedent
* initialization
*
* CALLS
*  Initialize()
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void Application_Initialize (NU_MEMORY_POOL *system_memory, NU_MEMORY_POOL *uncached_memory)
{
    INT_TRC_C(LABEL_APP_INIT);
    #define TS_BEGIN(id)
    #define TS_END(id)
    //#define INT_Trace_Enter(trc_id, is_tst_duration)
    //#define INT_Trace_Exit(trc_id, is_tst_duration)
    //#define print_bootup_trace(i)

    INT_TRC_C(LABEL_PCM_START);
    drv_pcm_start_capture();

    TS_END(TSID_INIT_ASM);

    TS_BEGIN(TSID_INIT_APPINIT);

    print_bootup_trace(SST_INIT_APPINIT_START);

//#if !defined(__BL_ENABLE__)
    //boot_init_clock();
//#endif

    /* set-up one MPU for system stack protection */
    INT_Trace_Enter(INIT_SYSSTACK_PROT, 0);
    INT_TRC_C(LABEL_SYSSTACK_PROT);
    CPU_SET_STACK_MPU_PROTECT(MPU_REGION_SP_KERNEL, SYS_Stack_Pool);
    INT_Trace_Exit(INIT_SYSSTACK_PROT, 0);


    /* set-up locale for trace */
    INT_Trace_Enter(INIT_CLIB1, 0);
    INT_TRC_C(LABEL_CLIB_BASE_INIT);
    clib_basic_init();
    INT_Trace_Exit(INIT_CLIB1, 0);


    /* set-up WDT base for nuclcues usage */
    INT_Trace_Enter(INIT_SET_NU_WDTBASE, 0);
    INT_TRC_C(LABEL_WDT_VAR_INIT);
    WATCHDOG_BASE = Get_WATCHDOG_BASE();
    WATCHDOG_RESTART_CMD = Get_WATCHDOG_RESTART_CMD();
    INT_Trace_Exit(INIT_NU_WDT_BASE, 0);


#if !defined(__L1CORE_ONLY__)
    INT_Trace_Enter(INIT_WAIT_BOOTMODE_SYNC, 0);
    INT_TRC_C(LABEL_BOOT_MODE_POLLING);
    /* Polling until PSCore INT_BootMode config done */
     while(SHARED_VAR(INT_PSCoreBootModeSync) != E_INITSYNC_Done) INT_EnterExceptionForOtherCore();
    SHARED_VAR(INT_PSCoreBootModeSync) = E_INITSYNC_Passed;
    cp15_data_memory_barrier();
#endif


#if !defined(__L1CORE_ONLY__)
    INT_TRC_C(LABEL_SHARE_MEM_MPU);
    if((SHARED_VAR(CCIF_SHARE_MEM_BASE)!=0) && (SHARED_VAR(CCIF_SHARE_MEM_SIZE)!=0)){
    ccif_set_share_mem_mpu(SHARED_VAR(CCIF_SHARE_MEM_BASE), SHARED_VAR(CCIF_SHARE_MEM_SIZE));
    }
#endif


#if !defined(__L1CORE_ONLY__)
    INT_TRC_C(LABEL_CCIRQ_SHARE_MEM_CONFIG);
    INT_Trace_Enter(INIT_MD1_MD3_CCIRQ, 0);
    cc_irq_md1_md3_shared_mem_config();
#endif


    INT_Trace_Enter(INIT_EMM, 0);
    INT_TRC_C(LABEL_EMM_INIT);
    EMM_Init();


    /* Initialize system specific module */
    INT_Trace_Enter(INIT_SYSTEMINIT, 1);
    systemInitialization();
    INT_Trace_Exit(INIT_SYSTEMINIT, 1);


    /* Initialize HW module */
    INT_Trace_Enter(INIT_HWDINIT, 0);
    HWDInitialization();
    INT_Trace_Exit(INIT_HWDINIT, 0);


    /* Disable Watch dog */
    wdt_data.fgEnable=KAL_FALSE;
    init_dcl_wdt_handle=DclWDT_Open(DCL_WDT,0);
    DclWDT_Control(init_dcl_wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T*)&wdt_data);
    DclWDT_Close(init_dcl_wdt_handle);


#if !defined(_SIMULATION)
    /* Note: Not all HW modules are avaiable in the Co-SIM envrionment */
    /* Note: Need to bypass DRV INIT in Co-SIM (via _SIMULATION) */
    INT_Trace_Enter(INIT_DRV2, 0);
    Drv_Init_Phase2();
    INT_Trace_Exit(INIT_DRV2, 0);
#endif


    /* Resource initialization */
    INT_Trace_Enter(INIT_RESINIT, 1);
    systemInitializeResource();
    INT_Trace_Exit(INIT_RESINIT, 1);


    /* Initialize heap for c library usage */
    INT_Trace_Enter(INIT_CLIB2, 1);
    clib_init();
    INT_Trace_Exit(INIT_CLIB2, 1);


    /* Initialize ECT */
#if !defined(__TCM_ONLY_LOAD__)
    INT_Trace_Enter(INIT_ECT, 0);
    ECT_Init();
    INT_Trace_Exit(INIT_ECT, 0);
#endif //__TCM_ONLY_LOAD__


#if !defined(__TCM_ONLY_LOAD__)
    /* Initialize MD32 */
    INT_Trace_Enter(INIT_MD32, 0);
    DSP_Init();
    INT_Trace_Exit(INIT_MD32, 0);
#endif // __TCM_ONLY_LOAD__


    /* MAUI protocol stack entry routine */
    INT_Trace_Enter(INIT_MAINP, 0);
    mainp();
    INT_Trace_Exit(INIT_MAINP, 0);


#if defined(__LTE_RAT__) && !defined(ATEST_ENABLE)
    //dspfm_init();
#endif


    /* enable SWLA by default for easy debug */
    INT_Trace_Enter(INIT_SLA, 0);
    SLA_Init();
#if defined(DEBUG_SWLA)
    SLA_Enable(); // enable SWLA by default for easy debug  
#endif
    INT_Trace_Exit(INIT_SLA, 0);


#if !defined(__TCM_ONLY_LOAD__)
    /* Initialize MD32 */
    DSP_OutputVersionInfo();
#endif // __TCM_ONLY_LOAD__


#ifdef __PRODUCTION_RELEASE__
#ifdef __MULTI_BOOT__
    if ( system_boot_mode!=FACTORY_BOOT )
#endif
    {
    /* Enable watch dog */
    wdt_data.fgEnable=KAL_TRUE;
    init_dcl_wdt_handle=DclWDT_Open(DCL_WDT,0);
	DclWDT_Control(init_dcl_wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T*)&wdt_data);
	DclWDT_Close(init_dcl_wdt_handle);
	}
#endif

    INT_Trace_Enter(INIT_CCIRQHS1, 0);
    cc_irq_sync_init_HS1();

    INT_backupBootLogs();


    INT_Trace_Enter(INIT_MPU_DUMP, 0);
    /* Dump current MPU setting to NonCacheable region */
    mpu_dump(&ARM_MPU_SETTING);

    /* RMPU violation detection */
    kal_uint32 src = 0;
    if (drv_pcm_get_stop_source(&src) == PCMON_OK) {
        if (src == PCMON_SRC_RMPU) {
            // Backup by MCU, 256B check, Unmask RMPU SRC 
            drv_pcm_backup_and_restart(KAL_TRUE, &l1_pcmon_log, KAL_FALSE);
            // Clear CTI LISR
            ECT_Init_ReEnable_RMPU();
        }
    }

#if !defined(__L1CORE_ONLY__)
    INT_Trace_Enter(INIT_SCHEDULING_SYNC, 0);
    INITSYNC_WriteAndPoll(SHARED_pVAR(INT_L1CoreSchedulingSync), SHARED_pVAR(INT_PCoreSchedulingSync));
#endif


    MDM_TM_END_SUCC_WRITE;

}


/*************************************************************************
* FUNCTION
*  systemInitialization
*
* DESCRIPTION
*   This function implements the system specific initialization, including
*   interrupt central controller, FDD and KAL.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void systemInitialization(void)
{
    // initialize the interrupt controller
    initINTR();

    // Register display handler
    kal_register_print_string_function((kal_print_string_func_ptr)stack_print);

    kal_initialize_mem();

    IRQ_LISR_Init();

    // Initializing the Buffer Pool Information
    stack_init_buff_pool_info();

    // Create buffer pools
    stack_resources_init();

    // Initialize KAL resources
    kal_initialize();

    // Initialize KAL CPU usage profiling
    kal_profile_init();

    // Initialize memory dump switch
    ex_memory_dump_init();
}


#if !defined(__TCM_ONLY_LOAD__)
static void INT_PD_SRAM(void)
{
#if defined(__CENTRALIZED_SLEEP_MANAGER__)
#define MAX_L2SRAM_LENGTH (256*1024) /* max L2SRAM PD range is 256KB */

    extern kal_uint32 custom_get_L2SRAMCODE_Base(void);
    extern kal_uint32 custom_get_L2SRAMDATA_Base(void);
    extern kal_uint32 custom_get_L2SRAMDATA_End(void);
    extern kal_uint32 custom_get_L2SRAM_LENGTH(void);
    extern void MEM_CONFIG_SW_PDN(kal_uint32 start_addr, kal_uint32 length);

    kal_uint32 PD_L2SRAM_base = custom_get_L2SRAMDATA_End();
    kal_uint32 PD_L2SRAM_end = custom_get_L2SRAMCODE_Base() + custom_get_L2SRAM_LENGTH();

    if(PD_L2SRAM_end - PD_L2SRAM_base >= MAX_L2SRAM_LENGTH)
    {
        PD_L2SRAM_base = PD_L2SRAM_end - MAX_L2SRAM_LENGTH;
    }

    MEM_CONFIG_SW_PDN(PD_L2SRAM_base, PD_L2SRAM_end - PD_L2SRAM_base);
#endif
}
#endif

/*************************************************************************
* FUNCTION
*  HWDInitialization
*
* DESCRIPTION
*   This function implements hardware dependent initialization and
*   management
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void HWDInitialization(void)
{

#if !defined(__TCM_ONLY_LOAD__)
	INT_Trace_Enter(INIT_PDSRAM, 1);
    INT_PD_SRAM();
#endif

#if !defined(_SIMULATION)
	INT_Trace_Enter(INIT_BUSDRV, 1);
    BusDrv_Init();
	Drv_MDAPInterface_Init();

#if !defined(__L1CORE_ONLY__)
	INT_Trace_Enter(INIT_CCIRQ, 1);
    cc_irq_init();
#endif

    INT_Trace_Enter(INIT_PCMON, 1);
    drv_pcm_initialize();
    INT_Trace_Exit(INIT_PCMON, 1);

	INT_Trace_Enter(INIT_DRV1, 1);
    Drv_Init_Phase1();
    INT_Trace_Exit(INIT_DRV1, 1);

    //INT_SetChipReg();

#ifdef __CENTRALIZED_SLEEP_MANAGER__
    INT_Trace_Enter(INIT_USC, 1);
    USC_Start();
    INT_Trace_Exit(INIT_USC, 1);
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

#ifdef __CENTRALIZED_SLEEP_MANAGER__
    INT_Trace_Enter(INIT_RM, 1);
    RM_Init(); // before OSTD_Init() and before 2G and 3G SMM's init() function
    INT_Trace_Exit(INIT_RM, 1);

    INT_Trace_Enter(INIT_OSTD, 1);
    OSTD_Init();
    INT_Trace_Exit(INIT_OSTD, 1);

#if DVFS_ENABLE
   INT_Trace_Enter(INIT_DVFS, 1);
   MODEML1_DVFS_Init(); // after cc_irq_init() and RM_Init()
   INT_Trace_Exit(INIT_DVFS, 1);
#endif /* DVFS_ENABLE */
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

    INT_Trace_Enter(INIT_GDMA, 1);
    drv_gdma_init();
    INT_Trace_Exit(INIT_GDMA, 1);

#ifdef MTK_SLEEP_ENABLE
#ifndef ATEST_DRV_ENABLE
   /* Added by Anthony Chin 03/18/2002. For sleep mode management. */
#ifdef __GSM_RAT__
    INT_Trace_Enter(INIT_L1SM, 1);
    L1SM_Init();
    INT_Trace_Exit(INIT_L1SM, 1);
#endif /* __GSM_RAT__ */
#ifdef __MTK_UL1_FDD__
    INT_Trace_Enter(INIT_UL1SM, 1);
    UL1SM_Init();
    INT_Trace_Exit(INIT_UL1SM, 1);
#endif /* __MTK_UL1_FDD__ */
#if defined(__LTE_RAT__) && defined(__EL1_ENABLE__)
    INT_Trace_Enter(INIT_EL1SM, 1);
    EL1SM_Init();
    INT_Trace_Exit(INIT_EL1SM, 1);
#endif /* __LTE_RAT__ && __EL1_ENABLE__ */
#endif /* ATEST_DRV_ENABLE */
#endif /* MTK_SLEEP_ENABLE */

#ifdef __CENTRALIZED_SLEEP_MANAGER__
    INT_Trace_Enter(INIT_ENOST, 1);
    OSTD_SetFrmDur(KAL_MICROSECS_PER_TICK);
    OSTD_EnOST(KAL_TRUE);
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

#if defined(__MTK_TARGET__)
	INT_Trace_Enter(INIT_PTP, 1);
    ptp_init();
#endif

#if 0
#if !defined(L1_NOT_PRESENT) && !defined(ATEST_DRV_ENVIRON)
#ifdef __HW_DIVIDER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __HW_DIVIDER__ */
#endif /* L1_NOT_PRESENT && ATEST_DRV_ENVIRON */
/* under construction !*/
#if defined(IDMA_DOWNLOAD) && !defined(ATEST_DRV_ENVIRON)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* IDMA_DOWNLOAD && !ATEST_DRV_ENVIRON */
/* under construction !*/
#ifdef NAND_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* NAND_SUPPORT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __CENTRALIZED_SLEEP_MANAGER__
/* under construction !*/
#endif
/* under construction !*/
#if defined(__ZIMAGE_SUPPORT__)
/* under construction !*/
#endif /* __ZIMAGE_SUPPORT__ */
/* under construction !*/
#if defined(__DCM_WITH_COMPRESSION__) || defined(__DYNAMIC_CODE_MANAGER__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif
}


/*************************************************************************
* FUNCTION
*   systemInitializeResource
*
* DESCRIPTION
*   This function aims resource initialization, including audio, image,
*   font etc.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void systemInitializeResource(void)
{
   srand(rand_num_seed);
}


/*************************************************************************
* FUNCTION
*  INT_BootMode
*
* DESCRIPTION
*   This function implements to return boot mode. Remember the routine muse
* be called after Application_Initialize.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 INT_BootMode(void)
{
#if !defined(__L1CORE_ONLY__)
    return SHARED_VAR(_boot_mode);
#else
    // if not CoreOnly, assume it is normal mode in L1core.
    return 0;
#endif
}


/*************************************************************************
* FUNCTION
*  INT_SetMetaMode
*
* DESCRIPTION
*   This function implements to set hw register to enable meta mode.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SetMetaMode(void)
{
    *(volatile kal_uint16 *)BOOT_CONFIG_ADDR |= 0x0001;
}


/*************************************************************************
* FUNCTION
*  release_bb_chip
*
* DESCRIPTION
*   This function returns the version number of the baseband chip
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_char* release_bb_chip(void)
{
    static kal_char str_return[]="MTxxxxx";

#if defined(FPGA)
    strcpy(str_return, "FPGA");
#elif defined(TK6291)
    strcpy(str_return, "TK6291");
#elif defined(MT6755)
#if defined(MT6750)
    strcpy(str_return, "MT6750");
#else
    strcpy(str_return, "MT6755");
#endif
#elif defined(MT6750S)
    strcpy(str_return, "MT6750S");
#elif defined(MT6757)
    strcpy(str_return, "MT6757");
#elif defined(MT6797)
    strcpy(str_return, "MT6797");
#else
#endif

    return str_return;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(__SMART_PHONE_MODEM__) && !defined(__MODEM_ONLY__) /* 2012/07/13: Currently, only MT6280 is defined with __SMART_PHONE_MODEM__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #if defined(__MTK_SECURE_PLATFORM__) || defined(__USB_DOWNLOAD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #else /* __MTK_SECURE_PLATFORM__ || __USB_DOWNLOAD__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #endif /* __MTK_SECURE_PLATFORM__ || __USB_DOWNLOAD__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __SMART_PHONE_MODEM__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(__SMART_PHONE_MODEM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #if defined(__FAST_LOGO__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif /* __FAST_LOGO__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			    #if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
			    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
/* under construction !*/
/* under construction !*/
			    #if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
			    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #if defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __SMART_PHONE_MODEM__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*************************************************************************
* FUNCTION
*  INT_GetRandomSeed
*
* DESCRIPTION
*  Get Random Seed -- maybed passed from bootloader or use memory region
*  to create
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_int32 INT_GetRandomSeed(void)
{
    #if defined(__SSDVT_TEST__)
    return 0;
    #else /* __SSDVT_TEST__ */

    kal_uint32 seed;

    //#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
    //kal_uint32 i;
    //#endif

    #ifdef __TIME_STAMP__

    #if 0
    #if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
/* under construction !*/
    #endif
    #endif

    TS_Init(TRUE);

    TS_BEGIN(TSID_INIT_TOTAL);
    TS_BEGIN(TSID_INIT_READY_TO_DISPLAY);
    TS_BEGIN(TSID_INIT_ASM);

    #endif

    #if defined(_SIMULATION)

    /* no need to generate a real random number seed in co-sim */

    seed = 0;

    #else   /* _SIMULATION */

    #if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
    kal_uint32 i;
    /* generate a random number via reading internal SRAM or 32K-clock calibration */
    for (seed = 0, i = 0; i < (1024 / 4); i++) {
        /* XOR memory data */
        seed = seed ^ *((kal_uint32 *)RAND_GEN_START_ADDR + i);
    }


    #else /* !(__BL_ENABLE__ || _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__) */

    #if defined(MT6290)
    //Read random seed from random number generator
    seed = DRV_Reg32(REG_RNDR);
    #else
    ASSERT(((BL_Info_Wrapper_st*)(BL_INFO_ADDR))->m_bl_maui_share_data.m_bl_magic_head == BL_INFO_V1);
    seed = ((BL_Info_Wrapper_st*)(BL_INFO_ADDR))->m_bl_maui_share_data.m_bl_random_seed;
    #endif

    #endif /* !(__BL_ENABLE__ || _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__) */

    #endif  /* _SIMULATION */

    /*
     * NoteXXX: Seed cannot be store in the global variable rand_num_seed directly.
     *          This is because that RW-data will be initialized later.
     *          Just return the seed.
     */

    return seed;
    #endif /* __SSDVT_TEST__ */
}


/*************************************************************************
* FUNCTION
*  INT_IsBootForUSBAT
*
* DESCRIPTION
*  This function is used to for user to query if USBAT is enabled
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
kal_bool INT_IsBootForUSBAT(void)
{
	return SHARED_VAR(_IsBootForUSBAT);
}



/*************************************************************************
* FUNCTION
*  RegionInitDummyReference
*
* DESCRIPTION
*  This function is used to force INT_InitRegions be keeped for CoSim load
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
#if defined(_SIMULATION)
void RegionInitDummyReference(void)
{
    volatile kal_uint32 dummy_ref=0;
    if(dummy_ref==1)
    {
        extern void INT_InitRegions();
        INT_InitRegions();
    }
}
#endif

#endif /*__FUE__*/
