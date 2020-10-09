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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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

// trace
#include "system_trc.h"             //INT_Trace_Enter, INT_Trace_Exit
#include "init_trc_api.h"           //INT_Trace_Enter, INT_Trace_Exit
#include "br_time_stamp.h"          // TS_END
#include "maui_time_stamp_util.h"   // TS_DumpTimeStamps

// system service hw
#include "pll.h"                    // INT_SetPLL
#include "dsp_loader.h"             // DSP_Load
#include "ect.h"                    // ECT_Init
#include "bus_drv.h"                // Bus_Init
#include "drv_pcmon.h"              // PCMon driver init
#include "drv_gdma.h"               // GDMA driver init
// system service sw
#include "stack_buff_pool.h"        //stack_resources_init, stack_init_buff_pool_info
#include "ex_item.h"                // ex_memory_dump_init
#include "ex_mem_manager_public.h"  // EMM_Init
#include "mpu.h"                    // CPU_SET_STACK_MPU_PROTECT, mpu_dump
#include "dsp_file_public.h"        // DSP related service init

//misc
#include "dcl.h"                    // for peripheral related
#include "wdt_hw_public.h"          //Get_WATCHDOG_BASE, Get_WATCHDOG_RESTART_CMD
//#include "bl_common.h"              // BL_Info_Wrapper_st
#include "drv_cfgctl.h"             //drv_cfgctl_clear_misc, drv_cfgctl_set_misc
#ifdef __HMU_ENABLE__
#include "hmu.h"                    // hif_boot_init
#endif
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
#ifdef DVFS_ENABLE
extern void DVFS_Init(void);
#endif

#include "cc_irq_public.h"
#include "drv_mdap_interface.h"
#include "sleepdrv_interface.h"

/******************************************************
 * Declaration and definition of global data
 ******************************************************/
//PCMon log
PCM_RECORD pcmon_log;
//WDT
WDT_CTRL_ENABLE_T wdt_data;
DCL_HANDLE init_dcl_wdt_handle;
DCL_HANDLE init_dcl_handle;


static kal_uint32 init_ev_timestamp = 0;
volatile DEFINE_NC_SHARED_VAR_ASSIGN(kal_uint16, _boot_mode,0xFFFF);
volatile DEFINE_NC_SHARED_VAR_ASSIGN(kal_uint32, g_l_sw_misc_l,0xFFFF);
volatile DEFINE_NC_SHARED_VAR_ASSIGN(kal_bool, _IsBootForUSBAT,KAL_FALSE);
volatile DEFINE_NC_SHARED_VAR_ASSIGN(INITSYNC_STATE, INT_PSCoreBootModeSync, E_INITSYNC_Waiting);

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

volatile DEFINE_NC_SHARED_VAR_ASSIGN(INITSYNC_STATE, INT_PCoreSchedulingSync, E_INITSYNC_Waiting);
volatile DEFINE_NC_SHARED_VAR_ASSIGN(INITSYNC_STATE, INT_L1CoreSchedulingSync, E_INITSYNC_Waiting);
volatile DEFINE_NC_SHARED_VAR_ASSIGN(INITSYNC_STATE, INT_PCoreRegionInitSync, E_INITSYNC_Waiting);
volatile DEFINE_NC_SHARED_VAR_ASSIGN(INITSYNC_STATE, INT_L1CoreRegionInitSync, E_INITSYNC_Waiting);

__attr_emiinit_zi ECO_VERSION eco_version; /* only used in PLL setup */

static const kal_uint32 RAND_GEN_START_ADDR = 0x70002000;

#if !defined(__SMART_PHONE_MODEM__) && !defined(__MODEM_ONLY__)
#define INT_CLEAR_RETN_FLAG(_flag)       drv_cfgctl_clear_misc()
#define INT_CLEAR_SET_FLAG(_flag)        drv_cfgctl_set_misc(_flag)
#endif /*__SMART_PHONE_MODEM__*/


/******************************************************
 * Declaration of function prototype
 ******************************************************/
static void INT_SetBootMode(void);
static void HWDInitialization(void);
static void systemInitialization(void);
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
void boot_init_clock();
#endif
extern kal_uint32 DummyReference();
extern void Drv_Init_Phase1(void);
extern void Drv_Init_Phase2(void);
extern void ECT_Init(void);
extern int  mainp(void);
extern kal_uint32 SLA_Init(void);
#if defined(DEBUG_SWLA)
    extern kal_uint32 SLA_Enable(void); // enable SWLA by default for easy debug  
#endif

/* HWDInitialization */
extern void NFI_Reset(void);
extern void DCM_PreInit(void);

/* systemInitialization */
#if !(defined(__NONE_FLASH_EXIST__))
#if !(defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)) || defined(__NANDFDM_MULTI_INSTANCE__)
extern void Initialize_FDD_tables(void);
#endif
#endif
extern void kal_initialize_mem(void);
extern void kal_profile_init(void);

/* systemInitializeResource */
extern kal_uint32 rand_num_seed;

/* INT_VersionNumbers */
extern kal_char *release_dsp_fw(void);
extern kal_char *release_dsp_ptch(void);
extern kal_char *release_verno(void);
extern kal_char *release_branch(void);
extern kal_char *release_hw_ver(void);
extern kal_char *release_flavor(void);

/* Misc. */
extern void SST_InvokEngine(kal_int32, kal_int32);

// for Security
#ifdef __SECURE_DATA_STORAGE__
extern kal_int32 SDS_Init(void);
#endif
#if defined(__BOOT_CERT__)
extern kal_uint32 srd_dl_ctrl_check(void);
extern kal_uint32 srd_dl_ctrl_pre_check(void);
#endif

/******************************************************
 * Definition of functions
 ******************************************************/

/*__FUE__ compile option is used for FOTA firmware update engine */
/*add this  compile option  to avoid compiling other function*/
#ifndef __FUE__
/*
 * NoteXXX:
 *    Please DO NOT place your code in the execution region EMIINITCODE.
 *    Code in this region is used for EMI/PLL initialization, and will be
 *    OVERWRITTEN after INT_InitRegions.
 */
/* [BB porting] Make sure the flow to set EMI&SFI and the placement of the code */
/*************************************************************************
* FUNCTION
*  INT_SetEMIPLL
*
* DESCRIPTION
*  This function dedicates for PLL setting.
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
__attribute__ ((section ("EMIINITCODE"))) void INT_SetEMIPLL(void)
{
   custom_setEMI();
   INT_SetPLL(PLL_MODE_MAUI);
}

//#define BASICLOAD_BRINGUP_TEST
#ifdef BASICLOAD_BRINGUP_TEST
extern void slt_dbg_print(char* fmt,...);
void INT_BasicLoad_SimepleTest_GPTCallback(void *para)
{
    slt_dbg_print("uart test\r\n");
    return;
}

kal_int32 INT_BasicLoad_SimpleTest(kal_uint32 dummy)
{
    kal_uint32          cbms_para = 0;
    DCL_HANDLE          handle_cbms;
    SGPT_CTRL_START_T   sgpt_ctrls;

    handle_cbms = DclSGPT_Open(DCL_GPT_CB, 0);
    sgpt_ctrls.u2Tick = (1);
    sgpt_ctrls.pfCallback = INT_BasicLoad_SimepleTest_GPTCallback;
    sgpt_ctrls.vPara = &cbms_para;

    DclSGPT_Control(handle_cbms, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&sgpt_ctrls);
    return 0;
}
#endif

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
void Application_Initialize(NU_MEMORY_POOL *system_memory, NU_MEMORY_POOL *uncached_memory)
{
    INT_TRC_C(LABEL_APP_INIT);
    INT_TRC_C(LABEL_PCM_START);
    drv_pcm_start_capture();

    TS_END(TSID_INIT_ASM);

    TS_BEGIN(TSID_INIT_APPINIT);

    print_bootup_trace(SST_INIT_APPINIT_START);

#if !defined(_SIMULATION)
#if !defined(__BL_ENABLE__)
    INT_TRC_C(LABEL_INIT_CLOCK);
    boot_init_clock();
#endif
#endif

    /* set-up one MPU for system stack protection */
    INT_Trace_Enter(INIT_SYSSTACK_PROT, 0);
    INT_TRC_C(LABEL_SYSSTACK_PROT);
    CPU_SET_STACK_MPU_PROTECT(MPU_REGION_SP_KERNEL, SYS_Stack_Pool);


    /* set-up locale for trace */
    INT_Trace_Enter(INIT_CLIB1, 0);
    INT_TRC_C(LABEL_CLIB_BASE_INIT);
    clib_basic_init();
    INT_Trace_Exit(INIT_CLIB1, 0);


    /* Toggle DummyReference for Boot Loader */
    INT_TRC_C(LABEL_DUMMY_REF);
    DummyReference();


    /* Set WDT base for nuclcues usage */
    INT_Trace_Enter(INIT_SET_NU_WDTBASE, 0);
    INT_TRC_C(LABEL_WDT_VAR_INIT);
    WATCHDOG_BASE = Get_WATCHDOG_BASE();
    WATCHDOG_RESTART_CMD = Get_WATCHDOG_RESTART_CMD();


#ifdef __HIF_CCCI_SUPPORT__
    /* Call HIF initialize and do phase-1 handshake with AP */
    INT_Trace_Enter(INIT_CCCIHW, 0);
    INT_TRC_C(LABEL_CCCI_HW_INIT);
    lte_ccci_hw_init();

    INT_Trace_Enter(INIT_CCCIHS1, 0);
    INT_TRC_C(LABEL_CCCI_HS1);
    lte_ccci_init_handshake_phase1();
    INT_Trace_Exit(INIT_CCCIHS1, 0);
#endif


    INT_Trace_Enter(INIT_EMM, 0);
    INT_TRC_C(LABEL_EMM_INIT);
    EMM_Init();
    // print_bootup_trace_duration() can be invoked after TDMA timer is initialized


    /* Set INT_BootMode config done flag to untrap L1Core */
    INT_Trace_Enter(INIT_BOOTMODE, 1);
    INT_SetBootMode();
    INT_Trace_Exit(INIT_BOOTMODE, 1);


    INT_Trace_Enter(INIT_MD1_MD3_CCIRQ, 0);
    cc_irq_md1_md3_shared_mem_config();


    /* After INT_SetBootMode() finished, must config bootmode done for L1Core */
    INT_Trace_Enter(INIT_FREE_BOOTMODE_SYNC, 0);
    SHARED_VAR(INT_PSCoreBootModeSync)=E_INITSYNC_Done;
    cp15_data_memory_barrier();


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


#if !defined(_SIMULATION)
#if !defined(__TCM_ONLY_LOAD__)
    /* Initialize ECT in the begging of Application_Initialize */
    INT_Trace_Enter(INIT_ECT, 0);
    ECT_Init();
#endif //__TCM_ONLY_LOAD__
#endif


#if !defined(_SIMULATION)
    INT_Trace_Enter(INIT_DSP_LOAD, 0);
    DSP_Load();
#endif


    /* DSP Init */
    INT_Trace_Enter(INIT_DSP, 0);
    DSP_Init();


    /* MAUI protocol stack entry routine */
    INT_Trace_Enter(INIT_MAINP, 0);
    mainp();


    init_ev_timestamp = kal_get_systicks();


    /* enable SWLA by default for easy debug */
#if !defined(_SIMULATION)
    INT_Trace_Enter(INIT_SLA, 0);
    SLA_Init();
#if defined(DEBUG_SWLA)
    SLA_Enable(); // enable SWLA by default for easy debug  
#endif
#endif


#ifdef __PRODUCTION_RELEASE__
#ifdef __MULTI_BOOT__
    if ( system_boot_mode!=FACTORY_BOOT )
#endif  /* __MULTI_BOOT__ */
    {
        /* Enable watch dog */
        wdt_data.fgEnable=KAL_TRUE;
        init_dcl_wdt_handle=DclWDT_Open(DCL_WDT,0);
    	DclWDT_Control(init_dcl_wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T*)&wdt_data);
    	DclWDT_Close(init_dcl_wdt_handle);
	}
#endif /* __PRODUCTION_RELEASE__ */

#ifdef __HMU_ENABLE__
    INT_Trace_Enter(INIT_HIFBOOT, 0);
    hif_boot_init();
#endif

    INT_Trace_Enter(INIT_CCIRQHS1, 0);
    cc_irq_sync_init_HS1();

#ifdef __HIF_CCCI_SUPPORT__
    /* Do phase-2 handshake with AP */
    INT_Trace_Enter(INIT_CCCIHS2, 1);
    lte_ccci_init_handshake_phase2(SHARED_VAR(_boot_mode));
    lte_ccci_hw_init_phase2();
    INT_Trace_Exit(INIT_CCCIHS2, 1);
#endif

    TS_END(TSID_INIT_APPINIT);
    TS_END(TSID_INIT_TOTAL);


    // dump time stamp from UART
    TS_DumpTimeStamps();
    INT_backupBootLogs();


#ifdef BASICLOAD_BRINGUP_TEST
    INT_BasicLoad_SimpleTest(0);
#endif


    INT_Trace_Enter(INIT_MPU_DUMP, 0);
    /* Dump current MPU setting to NonCacheable region */
    mpu_dump(&ARM_MPU_SETTING);

    /* RMPU violation detection */
    kal_uint32 src = 0;
    if (drv_pcm_get_stop_source(&src) == PCMON_OK) {
        if (src == PCMON_SRC_RMPU) {
            // Backup by MCU, Unmask RMPU_SRC
            drv_pcm_backup_and_restart(KAL_TRUE, &pcmon_log, KAL_FALSE);
            // Clear CTI LISR
            ECT_Init_ReEnable_RMPU();
        }
    }    

#if !defined(__PCORE_ONLY__)
    INT_Trace_Enter(INIT_SCHEDULING_SYNC, 0);
    INITSYNC_WriteAndPoll(SHARED_pVAR(INT_PCoreSchedulingSync), SHARED_pVAR(INT_L1CoreSchedulingSync));
#endif

#if defined(__PCORE__)
    // Disable DBG clock
    MD_TOPSM_PLL_SW_Control(PS_PLL_FORCEON_USER_CTI, PS_TOPSM_DBG_PLL, KAL_FALSE); 
#endif
}


/*************************************************************************
* FUNCTION
*  INT_SetBootMode
*
* DESCRIPTION
*   This function sets global variables related to boot mode
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*    _boot_mode
*    g_l_sw_misc_l
*    _IsBootForUSBAT
*
*************************************************************************/
static void INT_SetBootMode(void)
{
    /* for SiP TDD SLT, force META bootup */
#if defined(__TDDSYS_SLT_FACTORY_BOOT__) || defined(__LTE_PHY_TEST__)
    INT_SetMetaMode();
#endif

    /* Multi-Boot */
#ifdef __MULTI_BOOT__

    SHARED_VAR(_boot_mode) = 0x1 & *(volatile kal_uint16 *)BOOT_CONFIG_ADDR;

    SHARED_VAR(g_l_sw_misc_l) =  *(volatile kal_uint16 *)BOOT_CONFIG_ADDR;

    if (0x4 & *(volatile kal_uint16 *)BOOT_CONFIG_ADDR)
    {
        SHARED_VAR(_IsBootForUSBAT) = KAL_TRUE;
    }

#if !defined(L1_NOT_PRESENT) && !defined(ATEST_DRV_ENVIRON)
    /* Set mode for L1 usage */
	//pcore doesn't need L1D_SetInitMode.
    //L1D_SetInitMode(_boot_mode);
#endif /* !L1_NOT_PRESENT && !ATEST_DRV_ENVIRON */

#endif /* __MULTI_BOOT__ */
}


/*************************************************************************
* FUNCTION
*  INT_Ungate_L1Core
*
* DESCRIPTION
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
void INT_L1CoreVectorInit(void)
{
    *(volatile kal_uint32 *)(0xF60F0108) = (*(volatile kal_uint32 *)(0xF60F0108))|0x00200000;
    extern void INT_InitL1coreBootVector();
    INT_InitL1coreBootVector();
}
void INT_UngateL1Core(void)
{
    *(volatile kal_uint32 *)(0xF60F0104) = 0x6291F8EE;
    *(volatile kal_uint32 *)(0xF60F0100) = 0x1;
    *(volatile kal_uint32 *)(0xF60F0104) = 0x1;
    *(volatile kal_uint32 *)(0xF60F0104) = 0x629110C4;
}
void INT_L1CoreRegionInitPolling(void)
{
    INITSYNC_WriteAndPoll(SHARED_pVAR(INT_PCoreRegionInitSync), SHARED_pVAR(INT_L1CoreRegionInitSync));
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
   /* initialize the interrupt controller */
   initINTR();  /* initialize the interrupt controller */

#if !(defined(__NONE_FLASH_EXIST__))
#if !(defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)) || defined(__NANDFDM_MULTI_INSTANCE__)
   Initialize_FDD_tables();
#endif /* !(_NAND_FLASH_BOOTING_ || __EMMC_BOOTING__) || __NANDFDM_MULTI_INSTANCE__ */
#endif /* !(__NONE_FLASH_EXIST__) */

   /* Register display handler */
   kal_register_print_string_function((kal_print_string_func_ptr)stack_print);

   kal_initialize_mem();

   IRQ_LISR_Init();

   /* Initializing the Buffer Pool Information */
   stack_init_buff_pool_info();

   /* Create buffer pools */
   stack_resources_init();

   /* Initialize KAL resources */
   kal_initialize();

   /* Initialize KAL CPU usage profiling */
   kal_profile_init();

   /* Initialize memory dump switch */
   ex_memory_dump_init();
}

#if !defined(__TCM_ONLY_LOAD__)
static void INT_PD_SRAM(void)
{
#if defined(__CENTRALIZED_SLEEP_MANAGER__)
#define MAX_TCM_LENGTH (128*1024) /* max TCM PD range is 128KB */

    extern void MD_TOPSM_MEM_CONFIG_SW_PDN(kal_uint32 start_addr, kal_uint32 length);
    extern kal_uint32 custom_get_INTSRAMDATA_End(void);
    extern kal_uint32 custom_get_INTSRAM_End(void);

    kal_uint32 PD_TCM_base = custom_get_INTSRAMDATA_End();
    kal_uint32 PD_TCM_end = custom_get_INTSRAM_End();

    if(PD_TCM_end - PD_TCM_base >= MAX_TCM_LENGTH)
    {
        PD_TCM_base = PD_TCM_end - MAX_TCM_LENGTH;
    }

    MD_TOPSM_MEM_CONFIG_SW_PDN(PD_TCM_base, PD_TCM_end - PD_TCM_base);
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
    //INT_SetChipReg();
    INT_Trace_Enter(INIT_BUSDRV, 1);
    BusDrv_Init();
	Drv_MDAPInterface_Init();

#if !defined(__PCORE_ONLY__)
    INT_Trace_Enter(INIT_CCIRQ, 1);
    cc_irq_init();
#endif

    INT_Trace_Enter(INIT_PCMON, 1);
    drv_pcm_initialize();
    INT_Trace_Exit(INIT_PCMON, 1);

    INT_Trace_Enter(INIT_INIT_MISC, 1);
    INT_Init_Misc();
    INT_Trace_Exit(INIT_INIT_MISC, 1);

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
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

#ifdef MTK_SLEEP_ENABLE
#ifndef ATEST_DRV_ENABLE
   /* Added by Anthony Chin 03/18/2002. For sleep mode management. */
#ifdef __MTK_UL1_FDD__
    INT_Trace_Enter(INIT_UL1SM, 1);
	//pcore doesn't need UL1SM_Init.
    //UL1SM_Init();
    INT_Trace_Exit(INIT_UL1SM, 1);
#endif /* __MTK_UL1_FDD__ */
#endif /* ATEST_DRV_ENABLE */
#endif /* MTK_SLEEP_ENABLE */

#ifdef __CENTRALIZED_SLEEP_MANAGER__
    INT_Trace_Enter(INIT_ENOST, 1);
    OSTD_SetFrmDur(KAL_MICROSECS_PER_TICK);
    OSTD_EnOST(KAL_TRUE);
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

#ifdef DVFS_ENABLE
    INT_Trace_Enter(INIT_DVFS, 1);
    DVFS_Init();
    INT_Trace_Exit(INIT_DVFS, 1);
#endif
    
    INT_Trace_Enter(INIT_GDMA, 1);
    drv_gdma_init();
    INT_Trace_Exit(INIT_GDMA, 1);

#if 0
#if defined(IDMA_DOWNLOAD) && !defined(ATEST_DRV_ENVIRON)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* IDMA_DOWNLOAD && !ATEST_DRV_ENVIRON */
#endif

#ifdef NAND_SUPPORT
    INT_Trace_Enter(INIT_NFIRESET, 1);
    NFI_Reset();
    INT_Trace_Exit(INIT_NFIRESET, 1);
#endif /* NAND_SUPPORT */

    INT_Trace_Enter(INIT_DRV1, 1);
    Drv_Init_Phase1();
    INT_Trace_Exit(INIT_DRV1, 1);

#ifndef __CENTRALIZED_SLEEP_MANAGER__
    INT_Trace_Enter(INIT_START_SYSTIMER, 1);
    startSystemTimer();
#endif

#if defined(__ZIMAGE_SUPPORT__)
    ZImageDecompress();
#endif /* __ZIMAGE_SUPPORT__ */

#if defined(__DCM_WITH_COMPRESSION__) || defined(__DYNAMIC_CODE_MANAGER__)
    DCMGR_Init();
#endif
    DCM_PreInit();

#else

#endif /* !defined(_SIMULATION) */

}


/*************************************************************************
* FUNCTION
*   INT_Get_PowerOn_Type
*
* DESCRIPTION
*   This function used to return the power on reason
*
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
PW_CTRL_POWER_ON_REASON INT_Get_PowerOn_Type(void)
{
    PW_CTRL_GET_POWERON_REASON CtrlVal;
    DCL_HANDLE handle;


    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(handle,PW_CMD_GET_POWERON_REASON,(DCL_CTRL_DATA_T *)&CtrlVal);
    DclPW_Close(handle);

    return CtrlVal.powerOnReason;
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
*  INT_Config
*
* DESCRIPTION
*   This function implements adjusting Memory Block 0 (EMI_CON0) Wait
*  State's setting
*
* CALLS
*  INT_Decrypt, INT_SetPLL, INT_SetChipReg
*
* PARAMETERS
*
* RETURNS
*  the seed value for random number
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_Config(void)
{
#if !defined(_SIMULATION)

#if 0
#if defined(__MULTI_BOOT__) && !defined(L1D_TEST_COSIM)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MCU_26M)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #elif defined(MCU_52M)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
/* under construction !*/
#endif   /* __MULTI_BOOT__ & !L1D_TEST_COSIM */
#endif
   INT_SetEMIPLL();

#endif
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
   return SHARED_VAR(_boot_mode);
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
*  INT_InvokeSSTEngine
*
*************************************************************************/
#define _SST_FUNCTION_ENABLE_
void INT_InvokeSSTEngine(kal_int32 err_code, kal_int32 os_err_code)
{
    #ifdef _SST_FUNCTION_ENABLE_
    /* _SST_FUNCTION_ENABLE_ should be locally defined such that
     * custom release will remove these code
     */
        SST_InvokEngine(err_code, os_err_code);
    #endif
    return;
}

#if defined(__MTK_TARGET__)
/*************************************************************************
* FUNCTION
*   INT_SLA_QueryLoggingBuffer
*
* DESCRIPTION
*   0.This function is used for DHL to query if it is need to dump SWLA.
*   1.For engineering load, __MTK_INTERNAL__ be defined to support SWLA dump.
*   2.For user load, __MTK_INTERNAL__ will not be defined. If ACS want to
*     enable SWLA, he could define DEBUG_SWLA and rebuild it.
*   3.The switch function be maked here due to SWLA is released lib.
*
*************************************************************************/
kal_bool INT_SLA_QueryLoggingBuffer(kal_uint8 **startAddr, kal_uint32 *size, kal_uint8 **currPtr)
{
#if defined(__MTK_INTERNAL__) || defined(DEBUG_SWLA)
    extern kal_bool SLA_RetreiveLoggingBuffer(kal_uint8 **startAddr, kal_uint32 *size, kal_uint8 **currPtr);
    /* compile option can be modify such that
        * custom release will remove these code */
    return SLA_RetreiveLoggingBuffer(startAddr, size, currPtr);
#else
    return KAL_FALSE;
#endif
}


/*************************************************************************
* FUNCTION
*   INT_SLA_QueryL1coreLoggingBuffer
*
* DESCRIPTION
*   0.This function is used for DHL to query if it is need to dump SWLA.
*   1.For engineering load, __MTK_INTERNAL__ be defined to support SWLA dump.
*   2.For user load, __MTK_INTERNAL__ will not be defined. If ACS want to
*     enable SWLA, he could define DEBUG_SWLA and rebuild it.
*   3.The switch function be maked here due to SWLA is released lib.
*   4.This function can only be called in exception flow.
*
*************************************************************************/
kal_bool INT_SLA_QueryL1coreLoggingBuffer(kal_uint8 **startAddr, kal_uint32 *size, kal_uint8 **currPtr)
{
#if defined(__MTK_INTERNAL__) || defined(DEBUG_SWLA)
    extern kal_bool SLA_RetreiveL1coreLoggingBuffer(kal_uint8 **startAddr, kal_uint32 *size, kal_uint8 **currPtr);
    /* compile option can be modify such that
        * custom release will remove these code */
    return SLA_RetreiveL1coreLoggingBuffer(startAddr, size, currPtr);
#else
    return KAL_FALSE;
#endif
}

#endif

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

/*************************************************************************
* FUNCTION
*  INT_VersionNumbers
*
* DESCRIPTION
*   This function returns the version number of the followings
*   1. Chip version
*   2. DSP version
*   3. DSP patch version
*   4. MCU software version
*   5. Baseband board version
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
void INT_VersionNumbers(version_struct * ptr_version)
{
   ptr_version->bb_chip = release_bb_chip();
#if !defined(__DSP_FCORE4__)
   ptr_version->dsp_fw = release_dsp_fw();
   ptr_version->dsp_ptch = release_dsp_ptch();
#else
	// Note: use empty string temporarily, need to discuss how we should fill these fields in FCore case
   ptr_version->dsp_fw = " ";
   ptr_version->dsp_ptch = " ";
#endif //!__DSP_FCORE4__
   ptr_version->mcu_sw = release_verno();
   ptr_version->mcu_sw_branch = release_branch();
   ptr_version->bb_board = release_hw_ver();
   ptr_version->mcu_sw_flavor = release_flavor();
   return;
}


/*************************************************************************
* FUNCTION
*  INT_LteDspVersionNumbers
*
* DESCRIPTION
*   This function returns the version number of LTE DSP version
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
kal_bool INT_LteDspVersionNumbers(lte_dsp_version_struct * ptr_version)
{
#if defined(__LTE_RAT__)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    {
        ptr_version->dsp_fw = " ";
        ptr_version->dsp_btime = " ";
        return KAL_FALSE;
    }

#else
    ptr_version->dsp_fw = DSP_GetVersionString();
    ptr_version->dsp_btime = " ";

    return KAL_FALSE;
#endif
}


#if 1
/*************************************************************************
* FUNCTION
*  INT_SetCmdToSys
*
* DESCRIPTION
*  This function provide API for user to set necessary command to system
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
void INT_SetCmdToSys(INIT_SYSCMD_CODE cmd_val)
{
#if !defined(__SMART_PHONE_MODEM__) && !defined(__MODEM_ONLY__) /* 2012/07/13: Currently, only MT6280 is defined with __SMART_PHONE_MODEM__ */

   // RETN_REG[2]: 1: Enter USBDL
   // RETN_REG[1]: 1: BL download, 0: BROM download

   /* Secure mode or BL support USB DL  */
      // Normal mode: enter bootloader download after reboot
      // Rescue mode: enter BROM download after reboot

   /* Others */
      // Enter BROM download after reboot under either mode

   INT_CLEAR_RETN_FLAG(0x06);   // 3'b110

   switch (cmd_val)
   {
      #if defined(__MTK_SECURE_PLATFORM__) || defined(__USB_DOWNLOAD__)
      case SYS_CMD_SET_BL_DL:
         INT_CLEAR_SET_FLAG(0x06);   // 3'b110
         break;

      case SYS_CMD_SET_BROM_DL:
         INT_CLEAR_SET_FLAG(0x04);   // 3'b100
         break;
      #else /* __MTK_SECURE_PLATFORM__ || __USB_DOWNLOAD__ */
      /* if BL does not support USB DL, enter BROM download after reboot under either mode */
      case SYS_CMD_SET_BROM_DL:
      case SYS_CMD_SET_BL_DL:   /* this is actually BROM download */
         INT_CLEAR_SET_FLAG(0x04);   // 3'b100
         break;
      #endif /* __MTK_SECURE_PLATFORM__ || __USB_DOWNLOAD__ */

      // do not enter download mode
      case SYS_CMD_CLR_DL_FLAG:
         break;

      default:
         ASSERT(0);
         break;
    }

#endif /* __SMART_PHONE_MODEM__ */

}


/*************************************************************************
* FUNCTION
*  INT_GetSysStaByCmd
*
* DESCRIPTION
*  This function provided for user to query the status of system
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_uint32 INT_GetSysStaByCmd(INIT_SYSCMD_CODE cmd_val, void *data_p)
{
#if !defined(__SMART_PHONE_MODEM__)

    switch (cmd_val)
    {
			case CHK_USB_META_WO_BAT:
				if (SHARED_VAR(g_l_sw_misc_l) & (0x1 << 3))
				{
					return KAL_TRUE;
				}
				else
				{
					return KAL_FALSE;
				}

			case CHK_FAST_META:

#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))

#else
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
				{
					return KAL_FALSE;
				}

	     case SYS_CMD_BL_LOGO_DISPLAYED:

                #if defined(__FAST_LOGO__)
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
				#endif /* __FAST_LOGO__ */
				{
				  return KAL_FALSE;
				}

            case SYS_CMD_GET_PWN_STA:


			    #if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))

			        return KAL_FALSE;

			    #else

                #if 0
/* under construction !*/
				#endif
				#endif

         case SYS_CMD_GET_EMI_PARAM:
			    #if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))

			        return KAL_FALSE;

			    #else

                #if 0
/* under construction !*/
                #endif
				return KAL_TRUE;
				#endif

	     break;

	   case SYS_CMD_BL_BROM_CMD_MODE_DISABLED:
         #if defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)
         #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	     #endif
         #endif
			{
			   return KAL_FALSE;
			}
			default:
                ASSERT(0);
                break;
    }


#endif /* __SMART_PHONE_MODEM__ */

   return KAL_FALSE;
}
#endif

/*************************************************************************
* FUNCTION
*  INT_GetMetaModeSrc
*
* DESCRIPTION
*  Get Random Seed
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
MODE_ENTRY_SRC INT_GetMetaModeSrc(void)
{
    MODE_ENTRY_SRC state = E_BROM;


#if defined(__TOOL_ACCESS_CTRL__)

#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))

#else /* !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) */
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
#endif
#endif /* !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) */
#endif /* __TOOL_ACCESS_CTRL__ */
    return state;



}


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
    /* generate a random number via reading internal SRAM or 32K-clock calibration */
    kal_uint32 i;
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
*  INT_GetBromBlSyncType
*
* DESCRIPTION
*  For DHL, it needs to know the channel used to sync with tool in bootrom
* or boorloader
*
* PARAMETERS
*  None
*
* RETURNS
*  The sync channel used by bootrom or bootloader
*
*************************************************************************/
ser_chl_t INT_GetBromBlSyncType(void)
{
#ifdef __BL_ENABLE__
#if 0
/* under construction !*/
#endif
#else
    //For internal phone project, it does not have bootloader
    //Always return CHL_CCCI
    return CHL_CCCI;
#endif /*__BL_ENABLE__*/
}


/*************************************************************************
* FUNCTION
*  RegionInitDummyReference
*
* DESCRIPTION
*  This function is used to force INT_InitRegions, INT_InitShareRegions
*  be keeped for CoSim load.
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
        extern void INT_InitShareRegions();
        INT_InitRegions();
        INT_InitShareRegions();
    }
}
#endif

#endif /*__FUE__*/
