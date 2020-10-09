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
 *   xl1tst_mmrf_interface.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   EL1D interface to Multi-Mode Multi-RAT RF Central Control
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _XL1TST_MMRF_INTERFACE_H_
#define  _XL1TST_MMRF_INTERFACE_H_

/*===============================================================================*/

#include "kal_general_types.h"
#include "mml1_meta_if.h"

extern void EL1D_DPD_PA_Profile_Fac_Start_Cmd_Handler( MMRfTestDPDPaProfileStartFacCmdRptMix *p_dpd_pa_start_cmd_rpt );
extern void EL1D_DPD_PA_Profile_Fac_Set_Cmd_Handler( MMRfTestDPDPaProfileSetFacCmdRptMix *p_dpd_pa_set_cmd_rpt );
extern void EL1D_DPD_PA_Profile_Fac_Get_Cmd_Handler( MMRfTestDPDPaProfileGetFacCmdRptMix *p_dpd_pa_get_cmd_rpt );
extern void EL1D_DPD_Fac_Start_Cmd_Handler( MMRfTestDPDStartFacCmdRptMix *p_dpd_start_cmd_rpt );
extern void EL1D_DPD_Fac_Set_Cmd_Handler( MMRfTestDPDSetFacCmdRptMix *p_dpd_set_cmd_rpt );
extern void EL1D_DPD_Fac_Get_Cmd_Handler( MMRfTestDPDGetFacCmdRptMix *p_dpd_get_cmd_rpt );
extern void EL1D_CIM3_Fac_Start_Cmd_Handler( MMRfTestCIM3StartFacCmdRptMix *p_cim3_start_cmd_rpt );
extern void EL1D_CIM3_Fac_Set_Cmd_Handler( MMRfTestCIM3SetFacCmdRptMix *p_cim3_set_cmd_rpt );
extern void EL1D_CIM3_Fac_Get_Cmd_Handler( MMRfTestCIM3GetFacCmdRptMix *p_cim3_get_cmd_rpt );
extern void EL1D_DPD_Switch_Handler( MMRfTestDPDFacSwitchCmdRptMix *p_dpd_switch_cmd_rpt );
extern void EL1D_CIM3_Switch_Handler( MMRfTestCIM3FacSwitchCmdRpt *p_cim3_switch_cmd_rpt );
extern void EL1D_DPD_CIM3_Fac_Get_Lut_Config_Handler( MMRfTestLutConfigCmdRptMix *p_lut_config_cmd_rpt );
extern void EL1D_ET_Fac_Start_Cmd_Handler( MMRfTestETCalStartCmdRptMix* p_et_start_cmd_rpt );
extern void EL1D_ETCAL_GET_RESULT( MMRfTestETCalGetCmdRptMix* p_et_get_cmd_rpt );
extern void EL1D_ETCAL_SET_RESULT( MMRfTestETCalSetCmdRptMix* p_et_set_cmd_rpt );
extern void EL1D_ETCAL_PATH_DELAY_SEARCH_CHECK( MMRfTestETPathDelayCheckCmdRptMix* p_et_path_delay_check_cmd_rpt );
extern void EL1D_ET_Fac_Start_PathDelaySearch( MMRfTestETPathDelayStartCmdRptMix* p_et_path_delay_start_cmd_rpt );
extern void EL1D_ET_Mode_Setting(MMRfTestETModeSettingCmdRptMix* p_et_mode_setting_cmd_rpt);
extern void EL1D_Set_Tool_Usage_To_L1(MMRfTestSetToolUsageToL1CmdRptMix* p_set_tool_usage_to_l1_cmd_rpt);
extern void EL1D_DPD_Fac_Delay_Search_Check_Handler( MMRfTestDpdPathDelayCheckCmdRptMix* p_dpd_path_delay_check_cmd_rpt );
extern void EL1D_DPD_Fac_Delay_Search_Start_Handler( MMRfTestDpdPathDelayStartCmdRptMix* p_dpd_path_delay_start_cmd_srpt );
extern void EL1D_Set_Tool_Usage_To_L1_DPD( MMRfTestSetToolUsageToL1CmdRptMix * p_set_tool_usage_to_l1_cmd_rpt );
#endif /* End of #ifndef _XL1TST_MMRF_INTERFACE_H_ */
