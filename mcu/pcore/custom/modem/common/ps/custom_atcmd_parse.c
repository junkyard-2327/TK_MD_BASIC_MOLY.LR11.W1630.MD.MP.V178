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
 * Filename:
 * ---------
 * custom_atcmd_parse.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for parsing general proprietary AT command.
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
 *
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define RMMI_PARSER_C

/* The custom_atcmd_parse.c is no need for L1-only build, so disable building it to avoid mcd_xxx.h including error for L1-only build. */
/* Please do NOT add L1 related features here!!! */

#ifndef L4_NOT_PRESENT

#include "kal_general_types.h"
#ifdef __BTMTK__
#include "bluetooth_msgid.h"
#endif
#ifdef __GPS_SUPPORT__
#include "gps_msgid.h"
#endif
#include "tst_sap.h"
#ifdef __FM_AT_SUPPORT__
#include "mmiapi_msgid.h"
#endif
#if defined(__WIFI_SUPPORT__) && !defined(EXTERNAL_MMI) && defined(__MMI_FMI__)
#include "mmi_msgid.h"
#endif


#include <stdio.h>
#include <string.h>


#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"

#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "kal_public_api.h"
#include "stack_timer.h"
#include "event_shed.h"
#include "nvram_editor_data_item.h"
#include "nvram_interface.h"

//#include "custom_nvram_editor_data_item.h"
#include "dcl_uart.h"

#include "uart_sw.h"
#include "tst_msgid.h"
#ifdef __BTMTK__
#include "Bluetooth_struct.h"
extern void rmmi_send_msg_to_bt (msg_type msg_name, void *param_ptr);
#endif

#ifndef __L1_STANDALONE__
extern kal_bool tst_process_pc_command_from_ATCmd(kal_int32 len, kal_uint8 *param);
#endif

#if defined(__GPS_SUPPORT__)
#include "gps_struct.h"
#endif /* __GPS_SUPPORT__ */

#ifdef __FM_AT_SUPPORT__
#include "FMATCommand.h"
#endif


#ifdef __MOD_SMU__
#include "ps2sim_struct.h"
#include "ps2sat_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#endif /* __MOD_SMU__ */ 
/*#include "csmss_common_enums.h"
#include "mcd_l4_common.h"
#include "l4c_common_enum.h"
#include "rmmi_common_enum.h"
#include "rmmi_common_enum.h"*/
//#include "rmmi_context.h"

#include "gmss_public.h"

#ifdef __AGPS_SUPPORT__
//#include "ipc_msgsvc_msgid.h"
//#include "ipc_msgsvc.h"
//#include "l4c_aux_struct.h"
#include "md_mmi_sap.h"
#include "agps_md_interface.h"
extern module_type l4c_current_mod_id;
#endif

//extern rmmi_context_struct *rmmi_ptr_g;


#include "rmmi_struct.h"
#include "rmmi_common_enum.h"

#if defined(__WIFI_SUPPORT__) && !defined(EXTERNAL_MMI) && defined(__MMI_FMI__)
#include "dtcntsrviprot.h"
#include "dtcnt_struct.h"
#endif

#ifdef DVFS_ENABLE
#include "dvfs_interface.h"
#include "sync_data.h"
#endif // DVFS_ENABLE

#if defined(__MTK_TARGET__) 
#include "ptp_public.h"
#endif

#if defined(__MTK_TARGET__) 
#include "sleepdrv_interface.h"
#endif

#if defined(__MTK_TARGET__)
#include "ostd_public.h"
#endif


#ifdef __AGPS_CONTROL_PLANE__
extern void l4c_agps_reset_positioning_lind(void);
extern kal_uint8 l4c_get_csmss_g_ss_id(void);
#endif
#ifdef __AGPS_SUPPORT__
#include "rmmi_utility.h"
#endif
#ifndef L4_NOT_PRESENT
extern kal_bool l4c_drx_setting_req_hdlr(kal_uint8* data);
#endif
/* mtk01616_080104: 
  * This is used to define default <time> and <pause> value for AT+CKPD.
  * <time> * 0.1 sec is the time to stroke each key
  * <pause> * 0.1 sec  is the length between two strokes.  
  * <time> or <pause> should not larger than 255 (25.5 sec)
  * Default value is manufacturer specific,but should be so long that a normal MT can handle keystrokes correctly
  * Please refer to spec 07.07 section 8.7 for more detailed information
  */
#define CUSTOM_AT_CKPD_DEFAULT_TIME 2
#define CUSTOM_AT_CKPD_DEFAULT_PAUSE 4 

//Define AT command URC "RING" interval , the unit is 0.1 sec , default value is 4 sec = 40 x 0.1 sec
#define CUSTOM_URC_RING_INTERVAL 40

extern UART_PORT PS_UART_PORT;
extern UART_PORT PS_UART_PORT_2;

#ifdef __UMTS_RAT__
#define CUSTOM_MAX_MOD_NAME (8)
#define MAX_MODULE_MAP_SIZE (sizeof(mod_map)/sizeof(mod_map[0]))

typedef struct {
kal_char ModuleName[CUSTOM_MAX_MOD_NAME];
kal_uint32 ModuleEnum;
kal_uint32 ModuleEnum_1;
} module_name_enum_map_struct;
#endif

DEFINE_NC_SHARED_VAR(kal_bool, shared_var_dvfs_tppa_trigger)

#ifdef __CTP_GOODIX_GT818_TRUE_MULTIPLE__
#include "fs_type.h"
#include "fs_func.h"
#include "kal_public_api.h"

static kal_bool process_gt818_ctp_cmd( kal_uint8 action, kal_uint32 data_len, kal_uint8 *data_str )
{
    kal_uint16 ret_len = 0;
    kal_uint16 i;
    kal_uint16 inlen;
    kal_uint16 offset;
    STS_CTRL_COMMAND_T cmd;
    DCL_HANDLE handle;
    kal_uint8 *ctp_buffer = NULL;
    kal_uint8 *result = NULL;
    
    ctp_buffer = (kal_uint8 *)get_ctrl_buffer( 1024 );
    
    if ( ctp_buffer == NULL )
        EXT_ASSERT(0, (int)ctp_buffer, 0, 0);
        
    cmd.u4Command = action;
    cmd.pVoid1 = (void *)data_str;
    cmd.pVoid2 = (void *)&result;
    
    handle = DclSTS_Open( DCL_TS, 0 );
    DclSTS_Control( handle, STS_CMD_COMMAND, (DCL_CTRL_DATA_T *)&cmd );   
    DclSTS_Close(handle);     
    
    if ( action == DCL_CTP_COMMAND_GET_VERSION )
        ret_len = 6;
        
    if ( action == DCL_CTP_COMMAND_GET_CONFIG )
        ret_len = 106;
            
    if ( action == DCL_CTP_COMMAND_GET_DIFF_DATA )
        ret_len = 162;      

    if ( action == DCL_CTP_COMMAND_GET_FW_BUFFER )
    {
        offset = data_str[0]*256 + data_str[1];
        inlen = data_str[2];
        memcpy( &result[offset], &data_str[3], inlen);
        
        if ( inlen != 128 )
        {
            #define GT818_FW_STRING  "ctp_firmware_rusklmeoxkwjadfjnklruo3"
            kal_int16   drv_letter;
            FS_HANDLE fs_handle;
            UINT writen;
            kal_wchar   CTP_FIRMWARE_PATH[64];
                    
            drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
            kal_wsprintf( CTP_FIRMWARE_PATH, "%c:\\%s", drv_letter, GT818_FW_STRING );    
            fs_handle = FS_Open( CTP_FIRMWARE_PATH, FS_CREATE_ALWAYS | FS_READ_WRITE );
            FS_Write(fs_handle, (kal_uint8 *) result , offset+inlen, &writen);
            FS_Close( fs_handle );
        }            
    }
    
    kal_sprintf( (kal_char *)ctp_buffer, "+EGCMD: " );
            
    for ( i = 0 ; i < ret_len ; i++ )
        kal_sprintf( (kal_char *)&ctp_buffer[strlen((char *)(ctp_buffer))], "%02X", result[i] );            
        
    rmmi_write_unsolicitedResultCode( ctp_buffer, strlen((kal_char *)(ctp_buffer)), KAL_TRUE, 1, NULL );    
    
    free_ctrl_buffer( ctp_buffer );
    
    return KAL_TRUE;
}
#endif

kal_bool custom_send_sm_stress_inject_msg( kal_char *cmd_str, module_type dst_mod )
{
#if defined(__MTK_TARGET__) && defined(MTK_SLEEP_ENABLE)
    tst_module_string_inject_struct *tst_inject;
    tst_inject = (tst_module_string_inject_struct *)
                construct_local_para((kal_uint16)sizeof(tst_module_string_inject_struct), TD_RESET);

    strcpy((kal_char*)tst_inject->string, cmd_str);
    msg_send5(MOD_L4C, dst_mod, 0, MSG_ID_TST_INJECT_STRING, (local_para_struct*)tst_inject);
    
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}
/*****************************************************************************
* FUNCTION
*  	rmmi_general_command_parsing()
* DESCRIPTION
*   	This function should parse general proprietary AT command request.
*     Each owner should maintain and modify the code.
* PARAMETERS
*   	kal_uint32 op 
*	kal_uint32 data_len 
*	kal_uint8 *data_str
* RETURNS
*	KAL_TRUE or KAL_FALSE
*****************************************************************************/
kal_bool rmmi_general_command_parsing(kal_uint32 op, 
												kal_uint32 data_len, 
												kal_uint8 *data_str)
{
	kal_bool ret_val = KAL_FALSE;
	
#ifndef L4_NOT_PRESENT

	switch(op)
	{
		
		case 2: /* add by stanley 2006-07-03*/
		{
#if  defined(__BTMTK__)
			bt_test_cmd_req_struct  *param_ptr;
			param_ptr = (bt_test_cmd_req_struct *)construct_local_para(
															(kal_uint16)sizeof(bt_test_cmd_req_struct),
															TD_CTRL);   

			kal_mem_cpy(param_ptr->test_cmd_content, data_str, data_len);
			rmmi_send_msg_to_bt(MSG_ID_BT_TEST_CMD_REQ, param_ptr);	 
			ret_val = KAL_TRUE;
#endif /* __BTMTK__ */
      break;
		}
        
    case 6:
    {
#ifdef __UMTS_RAT__
        kal_char *pp, *strModuleName, *strTstInject, *tt;
        kal_uint32 module_enum = 0, input_str_data_len = 0;

        input_str_data_len = strlen((kal_char*)data_str);


        if( input_str_data_len > 0 && input_str_data_len < 255)
        {

        strModuleName = (kal_char*) kal_strtok_r((kal_char*)data_str, "_", &pp);

	tt = (kal_char*) kal_strtok_r(NULL, "", &pp);
	if(NULL != tt)
	{
		strTstInject = tt;
	}
	else
	{
		strTstInject = "";
	}

        /* Length of module name should be less than 8 bytes and Length of TST inject string shall be less than 128 bytes */
        if((CUSTOM_MAX_MOD_NAME > strlen(strModuleName)) && (128 > strlen(strTstInject)))
        {
            kal_uint8 idx;
            static const module_name_enum_map_struct mod_map[] = 
                {
                        {"MEME", MOD_MEME_FDD, MOD_MEME_TDD},//0                    
                        {"CSE", MOD_CSE_FDD, MOD_CSE_TDD},
                        {"CSCE", MOD_CSCE_FDD, MOD_CSCE_TDD},
                        {"SIBE", MOD_SIBE_FDD, MOD_SIBE_TDD}, 
                        {"USIME", MOD_USIME_FDD, MOD_USIME_TDD},
                        {"RRCE", MOD_RRCE_FDD, MOD_RRCE_TDD},//5
                        #if defined(__GEMINI_WCDMA__)
                        {"RRCE2", MOD_RRCE_FDD_2, MOD_RRCE_TDD},
                        #else
                        {"RRCE2", MOD_RRCE_FDD, MOD_RRCE_TDD},
                        #endif
                        {"SLCE", MOD_SLCE_FDD, MOD_SLCE_TDD},
                        {"ADR", MOD_ADR_FDD, MOD_ADR_TDD},
                        {"URR", MOD_URR_FDD, MOD_URR_TDD}, 
                        {"URLC", MOD_URLC_FDD, MOD_URLC_TDD},//10
                        {"UMAC", MOD_UMAC_FDD, MOD_UMAC_TDD},
                        {"UL2", MOD_UL2_FDD, MOD_UL2_TDD},                    
                        {"MM", MOD_MM, MOD_MM},
                        {"CC", MOD_CC, MOD_CC}, 
                        {"CISS", MOD_CISS, MOD_CISS},//15
                        {"SMS", MOD_SMS, MOD_SMS},
                        {"SIM", MOD_SIM, MOD_SIM},
                        {"L4C", MOD_L4C, MOD_L4C},
                        #if defined(__GEMINI__) || defined(__MMDS_DC__)
                        {"L4C2", MOD_L4C_2, MOD_L4C_2},
                        #else
                        {"L4C2", MOD_L4C, MOD_L4C},
                        #endif
                        {"TCM", MOD_TCM, MOD_TCM},//20 
                        {"SMSAL", MOD_SMSAL, MOD_SMSAL},
                        {"UEM", MOD_UEM, MOD_UEM},
                        {"RAC", MOD_RAC, MOD_RAC},
                        {"SMU", MOD_SMU, MOD_SMU},
                        {"USAT", MOD_USAT, MOD_USAT},//25 
                        {"CSM", MOD_CSM, MOD_CSM},
                        {"ENG", MOD_ENG, MOD_ENG},
                        {"PHB", MOD_PHB, MOD_PHB},
                        {"RRM", MOD_RRM_FDD, MOD_RRM_TDD},
                        {"RLC", MOD_RLC_FDD, MOD_RLC_TDD},//30 
                        {"MAC", MOD_MAC_FDD, MOD_MAC_TDD},
                        {"LAPDM", MOD_LAPDM_FDD, MOD_LAPDM_TDD}, 
                        {"MPAL", MOD_MPAL_FDD, MOD_MPAL_TDD},
                        {"SNDCP", MOD_SNDCP, MOD_SNDCP},
                        {"SM", MOD_SM, MOD_SM},//35 
                        {"LLC", MOD_LLC, MOD_LLC},
                        {"MBMSAL", MOD_MBMSAL, MOD_MBMSAL}, 
                        {"GMSS", MOD_GMSS,MOD_GMSS}, 
                        {"NWSEL", MOD_NWSEL,MOD_NWSEL},
                        {"ERRC", MOD_ERRC,MOD_ERRC},
                        {"EMM", MOD_EMM, MOD_EMM},
                        {"EMAC", MOD_EMAC, MOD_EMAC},
                        {"PAM", MOD_PAM, MOD_PAM}
                    };

            for(idx = 0; idx < MAX_MODULE_MAP_SIZE; idx++)
            {
                if(strcmp(strModuleName, mod_map[idx].ModuleName) == 0)
                {
                    module_enum = (gmss_is_wcdma_mode_activated() == KAL_TRUE) ? mod_map[idx].ModuleEnum : mod_map[idx].ModuleEnum_1;
                    break;
                }
            }

            if(idx != MAX_MODULE_MAP_SIZE)
            {
                /* The target module is found, and send the TST to the module */
                tst_module_string_inject_struct *tst_inject;
                tst_inject = (tst_module_string_inject_struct *)
                                        construct_local_para((kal_uint16)sizeof(tst_module_string_inject_struct), TD_RESET);
                strcpy((kal_char*)tst_inject->string, strTstInject);
                tst_inject->index = data_len;

                {
                    msg_send5(MOD_L4C, (module_type)module_enum, 0, MSG_ID_TST_INJECT_STRING, (local_para_struct*)tst_inject);
                }
            }
        }
        	
	ret_val = KAL_TRUE;
        }
#endif /* __UMTS_RAT__ */
    }
    break;

    #if defined(__AGPS_CONTROL_PLANE__)            
        case 14:
        {
            l4c_agps_reset_positioning_lind();
            ret_val = KAL_TRUE;
            break;
        }
    #endif

/************************sample code begin************************/			
//		case op: /*owner_date: purpose*/
//		{
//			/*call proprietary parsing function here and AT will give result  */
//			/*code OK/ERROR according to return value of parsing function*/	
//
//			break;
//		}
/************************sample code end*************************/
    #ifdef __CTP_GOODIX_GT818_TRUE_MULTIPLE__
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        {
            ret_val = process_gt818_ctp_cmd( (kal_uint8)(op - 15), data_len, data_str );
            break;
        }   
    #endif

#if defined(__AGPS_SUPPORT__)
        /* below codes are for auto-test */
        case 25:
        case 26:
        {
            /*agps_auto_test_ind_struct *param_ptr = construct_local_para(
            (kal_uint16)sizeof(agps_auto_test_ind_struct), TD_RESET);

            param_ptr->mode = (op == 25)? 1 : 0;*/

            /* Send the message to the module in AP */
            //ret_val = custom_send_agps_autotest_ipc(IPC_MSG_ID_AGPS_AUTO_TEST_IND, param_ptr);
            agps_md_auto_test_ind data;
            data.mode = (op == 25)? 1 : 0;
            rmmi_lbs_send_data(AGPS_MD_TYPE_AUTO_TEST_IND, (kal_uint8*)&data, sizeof(data));
            ret_val = KAL_TRUE;
            break;
        }
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        {
            /*agps_cp_up_status_ind_struct *param_ptr = construct_local_para(
            (kal_uint16)sizeof(agps_cp_up_status_ind_struct), TD_RESET);

            param_ptr->mode = (op-27);*/

            /* Send the message to the module in AP */
            //ret_val = custom_send_agps_autotest_ipc(IPC_MSG_ID_AGPS_CP_UP_STATUS_IND, param_ptr);
            agps_md_auto_cp_up_status_ind data;
            data.mode = (op-27);
            rmmi_lbs_send_data(AGPS_MD_TYPE_AUTO_CP_UP_STATUS_IND, (kal_uint8*)&data, sizeof(data));
            ret_val = KAL_TRUE;
            break;
        }
        case 33:
        case 34:
        {
            /* Send the message to the module in AP */
            //ret_val = custom_send_agps_autotest_ipc(IPC_MSG_ID_AGPS_MOLR_START_IND+(op-33), NULL);
            rmmi_lbs_send_data(AGPS_MD_TYPE_AUTO_MOLR_START_IND+(op-33), NULL, 0);
            ret_val = KAL_TRUE;
            break;
        }
        case 35:
        case 36:
        {
            /*agps_mtlr_response_ind_struct *param_ptr = construct_local_para(
            (kal_uint16)sizeof(agps_mtlr_response_ind_struct), TD_RESET);

            param_ptr->response = (op-35);*/
            /* Send the message to the module in AP */
            //ret_val = custom_send_agps_autotest_ipc(IPC_MSG_ID_AGPS_MTLR_RESPONSE_IND, param_ptr);
            agps_md_auto_mtlr_response_ind data;
            data.response = (op-35);
            data.session_id = l4c_get_csmss_g_ss_id();
            rmmi_lbs_send_data(AGPS_MD_TYPE_AUTO_MTLR_RESPONSE_IND, (kal_uint8*)&data, sizeof(data));
            ret_val = KAL_TRUE;
            break;
        }
#endif
        /* Sleep Mode Stress Test */
        case 37:
        {
            ret_val = custom_send_sm_stress_inject_msg( "2GStressEnable", MOD_L1);
            break;
        }
        case 38:
        {
            if(KAL_TRUE == gmss_is_wcdma_mode_activated())
            {
                ret_val = custom_send_sm_stress_inject_msg( "3GStressEnable", MOD_UL1);
            }
            break;
        }
        case 39:
        {
            ret_val = custom_send_sm_stress_inject_msg( "RTOSStressEnable", MOD_L1);
            break;
        }
        case 40:
        {
            ret_val = custom_send_sm_stress_inject_msg( "2GStressDisable", MOD_L1);
            break;
        }
        case 41:
        {
            if(KAL_TRUE == gmss_is_wcdma_mode_activated())
            {
                ret_val = custom_send_sm_stress_inject_msg( "3GStressDisable", MOD_UL1);
            }
            break;
        }
        case 42:
        {
            ret_val = custom_send_sm_stress_inject_msg( "RTOSStressDisable", MOD_L1);
            break;
        }
        /*Re  Calibration Stress */
        case 43:
        {
            ret_val = custom_send_sm_stress_inject_msg( "ReKEnable", MOD_L1);
            break;
        }
        case 44:
        {
            ret_val = custom_send_sm_stress_inject_msg( "ReKDisable", MOD_L1);
            break;
        }
        case 45:
        {
            ret_val = custom_send_sm_stress_inject_msg( "IgnoreXtaModeL1SM", MOD_L1);
            break;
        }
#ifdef __LTE_RAT__
        case 46:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GStressEnable", MOD_EL1);
            break;
        }
        case 47:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GStressDisable", MOD_EL1);
            break;
        }
#endif
        case 48:
        {
            ret_val = custom_send_sm_stress_inject_msg( "2GSleepEnable", MOD_L1);
            break;
        }
        case 49:
        {
            ret_val = custom_send_sm_stress_inject_msg( "2GSleepDisable", MOD_L1);
            break;
        }
        case 50:
        {
            if(KAL_TRUE == gmss_is_wcdma_mode_activated())
            {
                ret_val = custom_send_sm_stress_inject_msg( "3GSleepEnable", MOD_UL1);
            }
            break;
        }
        case 51:
        {
            if(KAL_TRUE == gmss_is_wcdma_mode_activated())
            {
                ret_val = custom_send_sm_stress_inject_msg( "3GSleepDisable", MOD_UL1);
            }
            break;
        }
#ifdef __LTE_RAT__
        case 52:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GSleepEnable", MOD_EL1);
            break;
        }
        case 53:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GSleepDisable", MOD_EL1);
            break;
        }
#endif
        case 54:
        {
            ret_val = custom_send_sm_stress_inject_msg( "OSTDSleepEnable", MOD_L1);
            break;
        }
        case 55:
        {
            ret_val = custom_send_sm_stress_inject_msg( "OSTDSleepDisable", MOD_L1);
            break;
        }
#ifdef __LTE_RAT__
        case 56:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GDVFSEnable", MOD_EL1);
            break;
        }
        case 57:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GDVFSDisable", MOD_EL1);
            break;
        }
#endif
        case 58:
        {
            ret_val = custom_send_sm_stress_inject_msg( "PCORE_RTOSStressEnable", MOD_L1);
            break;
        }
        case 59:
        {
            ret_val = custom_send_sm_stress_inject_msg( "PCORE_RTOSStressDisable", MOD_L1);
            break;
        }
#ifdef DVFS_ENABLE
        case 60:
        {
            ret_val = DVFS_AtCMDControlDVFS(data_len, data_str);
            break;
        }
        case 61:
        {
            ret_val = DVFS_AtCMDDumpTraceAll(KAL_TRUE);
            break;
        }
        case 62:
        {
            ret_val = DVFS_AtCMDFrequencyMeterPSMCUPLLCheck(data_len, data_str);
            break;
        }
        case 63:
        {
            ret_val = DVFS_AtCMDControlPTPwDVFSOn(data_len, data_str);
            break;
        }
        case 64:
        {
            ret_val = DVFS_AtCMDDumpPMICInfo();
            break;
        }
#endif
#if defined(__MTK_TARGET__) 
        case 65:
        {
            ret_val = MD_TOPSM_SleepEnable();
            break;
        }
        case 66:
        {
            ret_val = MD_TOPSM_SleepDisable();
            break;
        }
#endif
#if defined(__MTK_TARGET__)
        case 67:
        {
            // This at command is used to print TPPA related trace.
            ret_val = OSTD_TPPA_Dump_Current_Info();
            if (KAL_TRUE != ret_val) {
                break;
            }
            ret_val = MD_TOPSM_TPPA_Dump_Current_Info();
            if (KAL_TRUE != ret_val) {
                break;
            }
#ifdef DVFS_ENABLE
            // PCore DVFS TPPA trace
            ret_val = DVFS_TPPA_Dump_Current_Info();
            if (KAL_TRUE != ret_val) {
                break;
            }

            // MODEML1 DVFS TPPA trace
            //SleepDrv_TriggerCcirqInterrupt(SleepDrv_CCIRQ_CMD_DVFS_TPPA_TRACE, 0, 0);
            SHARED_VAR(shared_var_dvfs_tppa_trigger) = KAL_TRUE;
            Data_Sync_Barrier();
#endif

            break;
        }
#endif
        case 68:
        {
            ret_val = custom_send_sm_stress_inject_msg( "DumpTPPAInfo", MOD_UL1);
            break;
        }
#if defined(__MTK_TARGET__) 
        case 78:
        {
            ret_val = ptp_Ctrl_API(data_len,data_str);
            break;
        }
        case 79:
        {
            ret_val = ptp_Freq_API(data_len,data_str);
            break;
        }
         case 80:
        {
            ret_val = ptp_Dump_API(data_len,data_str);
            break;
        }       
        case 87:
        {
            ret_val = ptp_PMIC_API(data_len,data_str);
            break;
        }
#endif
#ifdef __DHL_MODULE__
        case 88:
        {
       	    //@mcu/common/interface/service/dhl/dhl_trace.h
            extern kal_bool dhl_enable_customized_SD_wakeup_time(kal_uint8 c_sec);
            extern kal_bool dhl_disable_customized_SD_wakeup_time(void);
            kal_uint8 val = *(kal_uint8 *) data_str;
            if (val == 0) {
                ret_val = dhl_disable_customized_SD_wakeup_time();
            } else {
                ret_val = dhl_enable_customized_SD_wakeup_time(val);
            }
            break;
        }
#endif

        case 89:
        {
            ret_val = l4c_drx_setting_req_hdlr(data_str);
            break;
        }

#ifdef __LTE_RAT__
        case 90:
        {   
            //AT cmd to inject message to EMM, note that only HEX STRING can be accepted
            if (data_str[0]  == 0x00)  
            {
                // stop all running T3402s
                tst_module_string_inject_struct *tst_inject;
                tst_inject = (tst_module_string_inject_struct *)construct_local_para((kal_uint16)sizeof(tst_module_string_inject_struct), TD_RESET);
            
                strcpy((kal_char*)tst_inject->string, "stop_t3402_all");
                tst_inject->index = 0;
                msg_send5(MOD_DHL_READER, MOD_EMM, 0, MSG_ID_TST_INJECT_STRING, (local_para_struct*)tst_inject);
                ret_val = KAL_TRUE;
            }
            
            //AT cmd to reset VZW parameters
            if (data_str[0]  == 0x01)  
            { 
                // reset EMM parameters
                tst_module_string_inject_struct *tst_inject;
                tst_inject = (tst_module_string_inject_struct *)construct_local_para((kal_uint16)sizeof(tst_module_string_inject_struct), TD_RESET);
            
                strcpy((kal_char*)tst_inject->string, "vzw_reset");
                tst_inject->index = 0;
                msg_send5(MOD_DHL_READER, MOD_EMM, 0, MSG_ID_TST_INJECT_STRING, (local_para_struct*)tst_inject);
                
                // TODO: reset PAM parameters
                
                // TODO: reset NWSEL parameters


                ret_val = KAL_TRUE;
            }
            break;
        }
#endif // __LTE_RAT__
#ifdef __IMS_SUPPORT__
        case 499:
        {
            //set VDM is_ims_reconfig_enable
            nvram_ef_vdm_nv_data_struct* nvram_vdm_nv_data_ptr = NULL;
            // Allocate buffer to read NVRAM setting
            nvram_vdm_nv_data_ptr = (nvram_ef_vdm_nv_data_struct*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_VDM_NV_DATA_SIZE);
            // Read current NVRAM setting
            nvram_external_read_data(NVRAM_EF_VDM_NV_DATA_LID,
                                     data_len+1,
                                     (kal_uint8*)nvram_vdm_nv_data_ptr,
                                     NVRAM_EF_VDM_NV_DATA_SIZE);
            nvram_vdm_nv_data_ptr->ims_reconfig_enable = data_str[0];
            nvram_external_write_data(NVRAM_EF_VDM_NV_DATA_LID,
                                      data_len+1,
                                      (kal_uint8*)nvram_vdm_nv_data_ptr,
                                      NVRAM_EF_VDM_NV_DATA_SIZE);
            ret_val = KAL_TRUE;
            break;
        }
#endif
        default:
            break;
    }
#endif // L4_NOT_PRESENT

    return ret_val;
}

kal_uint16 rmmi_get_ckpd_default_time(void)
{
	return CUSTOM_AT_CKPD_DEFAULT_TIME;
}

kal_uint16 rmmi_get_ckpd_default_pause(void)
{
	return CUSTOM_AT_CKPD_DEFAULT_PAUSE;
}

kal_uint16 rmmi_get_ring_interval(void)
{
	return CUSTOM_URC_RING_INTERVAL;
}

#if defined(__MOD_TCM__) //&& !defined(__MMI_FMI__)
extern kal_uint8 custom_l4c_psbearer_indicate(void);
#endif

/*****************************************************************************
* FUNCTION
*  	rmmi_custom_init_context()
* DESCRIPTION
* This function is to customize AT command default setting
*
* PARAMETERS
*	NONE
*
* RETURNS
*	NONE
*
*****************************************************************************/
void rmmi_custom_init_context(rmmi_custom_context_struct *rmmi_ptr_g)
{
#ifndef L4_NOT_PRESENT
    /* ATE default value */
    rmmi_ptr_g->rsp_mode.echo_flag = 0xff; // default echo on

    /* ATV default value */
    rmmi_ptr_g->rsp_mode.format = RMMI_VERBOSE_FULL_HEAD_TAIL;

	/* ATW default value */
    rmmi_ptr_g->rsp_mode.ext_result_code = 2;

	/* ATQ default value */
    rmmi_ptr_g->rsp_mode.suppress_flag = RMMI_SUPPRESS_OFF;

    /* AT+CMEE=<n> default value */
    rmmi_ptr_g->error_report_mode = RMMI_SIMPLE_ERROR;

    /* AT+CSCS=<chset> default value */
    rmmi_ptr_g->char_set = RMMI_CHSET_IRA;    

	/* AT+COPS=<mode>,<format> default value */
    rmmi_ptr_g->plmn_format = RMMI_PLMN_LONG_ALPHA;       //default for long alpha
    rmmi_ptr_g->cops_mode = 0; // default "automatic" mode

#ifdef __PLMN_LIST_WITH_LAC__
    rmmi_ptr_g->list_plmn_with_lac = KAL_FALSE; //default not print LAC
#endif

	/* AT+CPOL=<index>,<format> , set <format> default value here */
    rmmi_ptr_g->CPOL_plmn_format = RMMI_PLMN_NUMERIC;	

    /* AT+CMEC=<keyp>,<disp>,<ind> default value */
    rmmi_ptr_g->cmec_keyp = 2; 
    rmmi_ptr_g->cmec_disp = 0;
    rmmi_ptr_g->cmec_ind = 0;

    /* AT+CLAE=<mode> default value */    
    rmmi_ptr_g->clae_mode = KAL_FALSE;    

	/* AT+CSDH=<show> default value */
    rmmi_ptr_g->csdh_show = KAL_FALSE;

	/* AT+CVHU=<mode> default value, only (0-1) is supported */
#if defined(__MULTIPLE_PPP_DIALUP_SUPPORT__) && defined(__MMI_FMI__)
	rmmi_ptr_g->cvhu_mode = 1; //MAUI_02862643, mtk02285, ignore ATH in default -> To prevent disc CS call for Ericsson IOT  
#else
	rmmi_ptr_g->cvhu_mode = 0;
#endif

    /* AT+EIND=<flag> default value*/
#if defined (__CMUX_SUPPORT__) || defined (__MODEM_CARD__) /* EDGE card default enable eind */
    rmmi_ptr_g->report_mode.eind = 0x000000ff;
#else
    rmmi_ptr_g->report_mode.eind = 0; 
#endif

    /* AT+EINFO=<flag> default value*/
    rmmi_ptr_g->report_mode.einfo = 0;

    /* AT+ECPI=<mode> default value*/
#if defined(__UE_SIMULATOR__) && defined(__IMS_SUPPORT__)
    rmmi_ptr_g->report_mode.ecpi = 0xFFFFFFFF;
#else
    rmmi_ptr_g->report_mode.ecpi = 0;
#endif

    /* AT+ECSQ=<flag> default value*/
    rmmi_ptr_g->report_mode.ecsq = 0;

    /* AT+CMER=<mode>,<keyp>,0,<ind>,<bfr> default value */	
    rmmi_ptr_g->report_mode.cmer_mode = 0;  
    rmmi_ptr_g->report_mode.cmer_keyp = 0;
    rmmi_ptr_g->report_mode.cmer_ind = 0;   
    rmmi_ptr_g->report_mode.cmer_bfr = 0;	

    /* AT+CLIP=<n> default value*/	
    rmmi_ptr_g->report_mode.clip = 0;

    /* AT+COLP=<n> default value*/	
    rmmi_ptr_g->report_mode.colp = RMMI_DISABLE_REPORT;

    /* AT+CLIR=<n> default value*/	
    rmmi_ptr_g->report_mode.clir = RMMI_DISABLE_REPORT;

    /* AT+CDIP=<n> default value*/	
    rmmi_ptr_g->report_mode.cdip = RMMI_DISABLE_REPORT;

    /* AT+CNAP=<n> default value*/	
    rmmi_ptr_g->report_mode.cnap = RMMI_DISABLE_REPORT;

#if defined(__UE_SIMULATOR__) && defined(__IMS_SUPPORT__)
    /* AT+CREG=<n> default value*/  
    rmmi_ptr_g->report_mode.cs_reg = RMMI_ENABLE_LOC_REPORT;

    /* AT+CGREG=<n> default value*/ 
    rmmi_ptr_g->report_mode.ps_reg = RMMI_ENABLE_LOC_REPORT;
#else	
    /* AT+CREG=<n> default value*/	
    rmmi_ptr_g->report_mode.cs_reg = RMMI_DISABLE_NW_REG_REPORT;

    /* AT+CGREG=<n> default value*/	
    rmmi_ptr_g->report_mode.ps_reg = RMMI_DISABLE_NW_REG_REPORT;
#endif
    /* AT+CAOC=<mode> default value*/	
    rmmi_ptr_g->report_mode.ccm = RMMI_DISABLE_REPORT;

    /* AT+CCWE=<mode> default value*/	
    rmmi_ptr_g->report_mode.acm_warning = RMMI_DISABLE_REPORT;

    /* AT+CCWA=<n> default value*/	
    rmmi_ptr_g->report_mode.call_wait = RMMI_DISABLE_REPORT;

    /* AT+CGEREP=<mode> default value*/	
    rmmi_ptr_g->report_mode.cgerep = RMMI_DISABLE_REPORT;

    /* AT+CR=<mode> default value*/	
    rmmi_ptr_g->report_mode.cr = RMMI_DISABLE_REPORT;

    /* AT+CRC=<mode> default value*/	
    rmmi_ptr_g->report_mode.crc = RMMI_DISABLE_REPORT;

    /* AT+CTZR=<onoff> default value*/	
    rmmi_ptr_g->report_mode.timezone = RMMI_TIME_ZONE_DISABLE_REPORT;

    /* AT+CUSD=<n> default value*/	
    rmmi_ptr_g->report_mode.ussd = RMMI_DISABLE_REPORT;

    /* AT+CSSN=<n>,<m> default value*/	
    rmmi_ptr_g->report_mode.ss_mo = RMMI_DISABLE_REPORT;	
    rmmi_ptr_g->report_mode.ss_mt = RMMI_DISABLE_REPORT;	

    /* AT+CEN=<reporting> */
    rmmi_ptr_g->report_mode.cen = RMMI_ENABLE_REPORT; // +CEN

#if !defined(__MMI_FMI__)
    /* AT+ESIMS=<n> default value*/
    rmmi_ptr_g->report_mode.esims = 0;
#endif

    /* AT+EUSIM=<n> default value*/
    rmmi_ptr_g->report_mode.eusim = RMMI_ENABLE_REPORT;

    /* AT+ETESTSIM=<n> default value*/
    rmmi_ptr_g->report_mode.etestsim = RMMI_ENABLE_REPORT;

#if defined(__MOD_TCM__) //&& !defined(__MMI_FMI__)
    rmmi_ptr_g->report_mode.psbearer_indicate = custom_l4c_psbearer_indicate();
#endif

    rmmi_ptr_g->report_mode.pacsp = RMMI_DISABLE_REPORT;

    /* AT+ECGREG=<n> default value*/
	rmmi_ptr_g->report_mode.ecgreg = RMMI_DISABLE_REPORT;

    /* AT+ECEREG=<n> default value*/
	rmmi_ptr_g->report_mode.ecereg = RMMI_DISABLE_REPORT;
    /* AT+ECREG=<n> default value*/
	rmmi_ptr_g->report_mode.ecreg = RMMI_DISABLE_REPORT;

    /* AT+ECAINFO=<n> default value*/
	rmmi_ptr_g->report_mode.ecainfo = RMMI_DISABLE_REPORT;

    /* AT^DSCI=<n> default value */
    rmmi_ptr_g->op01_report_mode.dsci = 0;
    rmmi_ptr_g->op01_report_mode.cardmode = 0;
    rmmi_ptr_g->op01_report_mode.rfsw = 0;

#ifdef __CSG_SUPPORT__
    rmmi_ptr_g->report_mode.ecsg = RMMI_DISABLE_REPORT;
#endif

#ifdef __IMS_SUPPORT__
    rmmi_ptr_g->report_mode.cireg = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.cirep = RMMI_ENABLE_REPORT;
    rmmi_ptr_g->report_mode.cnem = RMMI_ENABLE_REPORT;
    rmmi_ptr_g->report_mode.ecmpcid = RMMI_ENABLE_REPORT;
#endif

    rmmi_ptr_g->report_mode.ecell = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.eemcinfo = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.essac = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.emobd = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.ecode33_mode = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.armee = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.eccause = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.cusats = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.ecusats = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.eslband = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.ecamp = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.ecsra = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.cscon = RMMI_DISABLE_REPORT;
    
    rmmi_ptr_g->report_mode.evocd = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.eltebwinfo = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.erlm_mode = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.esimecc = RMMI_ENABLE_REPORT;
    rmmi_ptr_g->report_mode.emodcfg = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.ereginfo = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.eimsps = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.eimscons = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.eplwth = RMMI_DISABLE_REPORT;
#ifdef __IMS_SUPPORT__
    rmmi_ptr_g->report_mode.eacb = RMMI_ENABLE_REPORT;
#else
    rmmi_ptr_g->report_mode.eacb = RMMI_DISABLE_REPORT;
#endif


    /* AT+EIMSESS=<n> default value*/
	rmmi_ptr_g->report_mode.eimsess = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.esimapp = RMMI_DISABLE_REPORT;
#endif /* L4_NOT_PRESENT */    
}

/*****************************************************************************
* FUNCTION
*  	rmmi_custom_ps_uart_port()
* DESCRIPTION
*   	This function is to provide custom_ps_uart_port setting for ATCI
*
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
UART_PORT rmmi_custom_ps_uart_port(void)
{
    // uart_port_null => won't open extra port

//temp_sol for 6582+6290
#if defined(__SMART_PHONE_MODEM__) && !defined(__FLAVOR_MULTI_MODE_ROUTER__) && !defined(__FLAVOR_SINGLE_MODE_ROUTER__)
    return (kal_uint16)uart_port_usb;
#else
    return (kal_uint16)uart_port_null;
#endif
}

/*****************************************************************************
* FUNCTION
*  	rmmi_custom_urc_channel()
* DESCRIPTION
*   	This function is to decide the URC will be sent to specific port or not
*
* PARAMETERS
*	NONE
*
* RETURNS
*       KAL_TRUE:   send URC to the port
*       KAL_FALSE: DO NOT send URC to the port
*****************************************************************************/
kal_bool rmmi_custom_urc_channel(kal_uint8 port)
{
    // In default, only sent URC to PS_UART_PORT

    if (port == PS_UART_PORT)
    {
        return KAL_TRUE;
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
#endif

    return KAL_FALSE;
}

/*****************************************************************************
* FUNCTION
*  	rmmi_get_vgr_default_setting()
* DESCRIPTION
*   	This function is to define default setting for ATE
*
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
void rmmi_get_vgr_default_setting(kal_bool *customer_provided, kal_uint8 *vgr_gain)
{
    *customer_provided = KAL_FALSE;
    *vgr_gain = 150;
}

/*****************************************************************************
* FUNCTION
*  	rmmi_get_vgt_default_setting()
* DESCRIPTION
*   	This function is to define default setting for ATE
*
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
void rmmi_get_vgt_default_setting(kal_bool *customer_provided, kal_uint8 *vgt_gain)
{
    *customer_provided = KAL_FALSE;
    *vgt_gain = 150;
}



/*****************************************************************************
* FUNCTION
*  	rmmi_remove_listing_at_command()
* DESCRIPTION
*   	
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
kal_bool rmmi_remove_listing_at_command(kal_char const *rsp_str)
{
/* If you don't want to list some at command, you can refer the following example.
    If you don't list ata and at+casp, please refer the following code.*/
/*	
       if (strcmp(rsp_str, "a") == 0 || strcmp(rsp_str, "casp") == 0)
	{
		return KAL_FALSE;
	}
*/
	return KAL_TRUE;
}
/*****************************************************************************
* FUNCTION
*  	rmmi_add_listing_at_command()
* DESCRIPTION
*   	
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
kal_uint16 rmmi_add_listing_at_command(kal_char **rsp_str)
{
/* If you want to list some custom at command, you can refer the following example.
    If you list at+aaaa and at+bbbb, please refer the following code.*/
/*    
    rsp_str[0]="at+aaaa\0";
    rsp_str[1]="at+bbbb\0";

    return 2; // total 2 at command (at+aaaa and at+bbbb)
*/
    return 0;
}

#endif /* L4_NOT_PRESENT */

