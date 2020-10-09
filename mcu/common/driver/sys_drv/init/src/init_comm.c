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
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
[MAUI_03149504] ([MAUI_03180970]) all time memory dump
[MAUI_03121063] remove PDN registers
[MAUI_03147344] Dummy read for early response HW
[MAUI_03161918] remove custom_setAdvEMI from bootarm.S
[MAUI_03157059] security use meta to write

 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_trace.h"
#include "reg_base.h"
#include "config_hw.h"
#include "emi_hw.h"
//#include "init.h"
#include "intrCtrl.h"
#include "isrentry.h"
//MSBB remove #include "custom_config.h"
#include "stack_buff_pool.h"
#include "fat_fs.h"
#include "drv_comm.h"
//MSBB remove #include "wdt_hw.h"
#include "wdt_sw.h"
#include "bmt.h"
#include "dcl.h"
#include "drvpdn.h"
#include "SST_init.h"   /* for sw version check in INT_Version_Check() */
#include <stdio.h>
#include <string.h>
#if defined(__ARMCC_VERSION)
#include <rt_misc.h>   /* for __rt_lib_init() */
#endif
#include <stdlib.h>
#include "cache_sw.h"
//#include "page.h"
#include "md2g_drv.h"
//#include "bl_features.h"
//#include "bl_setting.h"
//#include "bl_loader.h"
#include "system_trc.h"
#include "init_trc_api.h"
#include "ex_item.h"
#include "init_comm.h"
#include "init_comm_trc.h"
#include "ex_item.h"
#include "cp15.h"

#ifdef __CHIP_VERSION_CHECK__
#include "uart_sw.h"
#endif /* __CHIP_VERSION_CHECK__ */


#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /* __MULTI_BOOT__ */
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
#include "cp15.h"
#endif   /* __ARM9_MMU__ || __ARM11_MMU__ */

#if defined(__SMART_PHONE_MODEM__)
#include "ccci.h"
#endif /* __SMART_PHONE_MODEM__ */

#if defined(__DSP_FCORE4__)
#include "mdci.h"
#include "SST_dmdsp_ex.h"
#include "dmdsp_init.h"
#endif /* __DSP_FCORE4__ */
#if defined(__FOTA_DM__)
#include "fue_err.h"
#include "custom_fota.h"
#include "custom_img_config.h"
#include "fue.h"
#include "SSF_fue_support.h"
#endif
#if !defined(__UBL__) && !defined(__FUE__)
#ifdef __CENTRALIZED_SLEEP_MANAGER__
#include "ostd_public.h"
#endif /* __CENTRALIZED_SLEEP_MANAGER__ */
#endif

/*******************************************************************************
 * Define pragma
 *******************************************************************************/

/*******************************************************************************
 * Define global data
 *******************************************************************************/
/* [BB porting] please make sure the register address is correct and scatter file palced in the correct region */
#if defined(EMI_base)
const kal_uint32 g_EMI_BASE_REG		 	  = EMI_base;
#endif /* EMI_base */
kal_uint32 INC_Init_Step = 0;


#if defined(__MTK_TARGET__)
/* bb reg dump setting */
EX_BBREG_DUMP chipversion_dump;
const kal_uint32 chipversion_dump_regions[] =
{
//#if (defined(MT6755) || defined(MT6750)  || defined(MT6750S) || defined(MT6797) || defined(MT6757))
#if 0
/* under construction !*/
#else
    0, 0, 0
#endif
};
#endif /* __MTK_TARGET__ */



/*******************************************************************************
 * Declare import data
 *******************************************************************************/

/*******************************************************************************
 * Declare import function prototype
 *******************************************************************************/



/*************************************************************************
* FUNCTION
*  AnalogDieID
*
* DESCRIPTION
*  This function returns identification of analog die
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  Identification of analog die
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
analog_die_id AnalogDieID()
{
   return UNKNOWN_ANALOG_DIE;
}


#if defined(__CHIP_VERSION_CHECK__) && !defined(__UBL__)
/*************************************************************************
* FUNCTION
*  INT_Version_Check
*
* DESCRIPTION
*   This function implements HW ID check with software load version
*
* CALLS
*  U_PutUARTByte
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
/* [BB porting] Please make sure the version register and build code is correct */
extern void U_PutUARTByte(UART_PORT port, kal_uint8 data);
void INT_Version_Check(void)
{
   volatile register kal_uint16 HwCode;
   register kal_uint8 HExtra = ' ';
   register kal_uint16 BuildCode;
   volatile register kal_int32 i;

   HwCode = *HW_CODE;

#if defined(MT6280)
   BuildCode = 0x6280;
#elif defined(MT6290)
   BuildCode = 0x6290;
#elif defined(MT6595)
   BuildCode = 0x6593; //HW code of MT6595 is 6593
#else
   BuildCode = 0;
#endif

#ifndef ExtraVer
   #define	ExtraVer ' '
#endif

   if ((HwCode != BuildCode) || (HExtra != ExtraVer))
   {
      U_PutUARTByte(uart_port1, '@');
      while(1)
      {
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, 'H');
         U_PutUARTByte(uart_port1, 'W');
         U_PutUARTByte(uart_port1, '=');
         U_PutUARTByte(uart_port1, 'M');
         U_PutUARTByte(uart_port1, 'T');
         for(i = 12; i >= 0; i -= 4)
         {
            U_PutUARTByte(uart_port1, '0' + ((HwCode >> i) & 0x0F));
         }
         U_PutUARTByte(uart_port1, HExtra);
         U_PutUARTByte(uart_port1, ',');
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, 'S');
         U_PutUARTByte(uart_port1, 'W');
         U_PutUARTByte(uart_port1, '=');
         U_PutUARTByte(uart_port1, 'M');
         U_PutUARTByte(uart_port1, 'T');
         for(i = 12; i >= 0; i -= 4)
         {
            U_PutUARTByte(uart_port1, '0' + ((BuildCode >> i) & 0x0F));
         }
         U_PutUARTByte(uart_port1, ExtraVer);
         U_PutUARTByte(uart_port1, ' ');
         U_PutUARTByte(uart_port1, '\r');
         U_PutUARTByte(uart_port1, '\n');

         for(i = 0xFFFFF; i > 0; i--) ;
         U_PutUARTByte(uart_port1, '#');
      }
   }
}

/*************************************************************************
* FUNCTION
*  INT_SW_VersionCheck
*
* DESCRIPTION
*  This function checks if sw sec version is matched with chip sw sec version
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
void INT_SW_VersionCheck(void)
{
   kal_int8 chipSWSecVer;
   kal_int8 binSWSecVer;
   char tempStr[50];

   /* SW second version check */
   chipSWSecVer = *SW_VER & 0x00FF;
   binSWSecVer = SW_MINOR_VER;

   sprintf(tempStr, "Chip SW second version: %02d", chipSWSecVer);
   tst_sys_trace(tempStr);
   sprintf(tempStr, "Bin file SW second version: %02d", binSWSecVer);
   tst_sys_trace(tempStr);

   if(binSWSecVer < chipSWSecVer) {
      /* show catcher log warning */
      tst_sys_trace("[Warning] SW second version of bin file is smaller than chip!");
   }
}
#else /* __CHIP_VERSION_CHECK__ && !__UBL__ */
/* fake function */
void INT_Version_Check(void)
{
}

void INT_SW_VersionCheck(void)
{
}
#endif /* __CHIP_VERSION_CHECK__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  INT_ecoVersion
*
* DESCRIPTION
*  This function returns the ECO version number of baseband chipset
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
/* [BB porting] Please make sure the the correlated enum and code is added since the default case is ext_assert */
/* Please be aware that new chips may use INT_SW_SecVersion */
ECO_VERSION INT_ecoVersion(void)
{
#if  defined(MT6280)
    return MT6270A_latest_chip;

#elif defined(MT6290)
    return MT6290_latest_chip;

#elif defined(MT6575)
    return MT6575_latest_chip;

#elif defined(MT6577)
    return MT6577_latest_chip;

#elif defined(MT6595)
    return MT6595_latest_chip;

#elif defined(TK6291)
    return TK6291_latest_chip;

#elif defined(MT6755)
#if defined(MT6750)
    return MT6750_latest_chip;

#else
    return MT6755_latest_chip;

#endif

#elif defined(MT6750S)
    return MT6750S_latest_chip;

#elif defined(MT6757)
    return MT6757_latest_chip;

#elif defined(MT6797)
    return MT6797_latest_chip;

#else
    /* no one should invoke this function for unknown chip */
    ASSERT(0);
    return 0;

#endif
}

/*************************************************************************
* FUNCTION
*  INT_GetCurrentTime
*
* DESCRIPTION
*  This function access 32KHz Counter and return Counter Value
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  Value of 32KHz Counter
*
* GLOBALS AFFECTED
*
*************************************************************************/

/* for SNOR, this function should be placed in RAM */
#if defined(__MTK_TARGET__)
#if defined(__UBL__) || defined(__FUE__)
//#pragma arm section code = "INTERNCODE"
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
//#pragma arm section code = "SNORCODE"
#endif
#endif //__MTK_TARGET__

/* [BB porting] confirm with L1 if the function is support in new chip */
kal_uint32 INT_GetCurrentTime(void)
{
#if (defined(MT6575) || defined(MT6577)) && defined(__APPLICATION_PROCESSOR__)
   return 0; // Not Support Yet
#elif defined(MT6290) || defined(ATEST_DRV_ENVIRON)
   return 0; // Not Support Yet
#else
   /*
    * Call API provided by L1
    */
   return 0;
#endif /* (MT6575 || MT6577) && __APPLICATION_PROCESSOR__ */
}


/*************************************************************************
* FUNCTION
*  INT_ChipName
*
* DESCRIPTION
*  This function is a special use for those users desire to run on
*  different chips with the same SW load.
*
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
/* [BB porting] Make sure if the rule is changed or need to add for a new chip */
CHIP_NAME INT_ChipName(void)
{
   /* no one should invoke this function for unknown chip */
   ASSERT(0);

   return 0;
}


/*************************************************************************
* FUNCTION
*  INT_SW_SecVersion
*
* DESCRIPTION
*  This function is used for SW to query the software secondary version
*
*
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
/* [BB porting] Check if the chip support new version and if the SW secondary version is changed */
SW_SECVERSION INT_SW_SecVersion(void)
{
#if defined(MT6755) || defined(MT6757) || defined(MT6797) || defined(MT6750S)
    kal_uint16 sw_sec_ver_val = 0;
    sw_sec_ver_val = *SW_VER & 0x00FF;
    if (sw_sec_ver_val == 0x00)
    {
        return SW_SEC_0;
    }
    else if (sw_sec_ver_val == 0x01)
    {
        return SW_SEC_1;
    }
#if defined(MT6750)
    else if (sw_sec_ver_val == 0x02)
    {
#define VERSION_PTR     (0xC020627C)
#define VERSION_MASK    (0x00003000)
#define VERSION_OFFSET  (12)
        kal_uint32 val = 0;
        val = (*(kal_uint32 *)((kal_uint32)VERSION_PTR) & VERSION_MASK) >> VERSION_OFFSET;
#undef VERSION_PTR
#undef VERSION_MASK
#undef VERSION_OFFSET
        if (val == 0x0)
        {
            return SW_SEC_2;
        }
        else
        {
            return SW_SEC_3;
        }
    }
#else
    else if (sw_sec_ver_val == 0x02)
    {
        return SW_SEC_2;
    }
#endif
    else if (sw_sec_ver_val == 0x03)
    {
        return SW_SEC_3;
    }
    else if (sw_sec_ver_val == 0x04)
    {
        return SW_SEC_4;
    }
    else if (sw_sec_ver_val == 0x05)
    {
        return SW_SEC_5;
    }
    else if (sw_sec_ver_val == 0x06)
    {
        return SW_SEC_6;
    }
    else
    {
        return SW_LATEST_SEC;
    }

#else

    ASSERT(0);
#endif

    return SW_SEC_UNDEF;
}

/*************************************************************************
* FUNCTION
*  INT_ChipGroup
*
* DESCRIPTION
*  This function is a special use for those users desire to run on
*  different chips with the same SW load.
*
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
/* [BB porting] May not need to maintain this, check if we could remove */
CHIP_GROUP INT_ChipGroup(void)
{
   /* no one should invoke this function for unknown chip */
   ASSERT(0);

   return 0;
}

FPGA_VERSION INT_FPGA_Version(void)
{
    kal_uint32 date_code = *((volatile kal_uint32 *)(DATE_CODE_BASE));
    kal_uint32 purpose_code = *((volatile kal_uint32 *)(PURPOSE_CODE_BASE));
    purpose_code = purpose_code & PURPOSE_CODE_MASK;
    FPGA_VERSION fpga_version = {E_FPGA_BIT_DATE_END, E_FPGA_BIT_PURPOSE_END};
    //volatile kal_uint32 while_tag_VersionCode = 0x1;



    if (date_code < 0x20140801)
    {
        fpga_version.date = E_Before_20140801;
    }
    else
    {
        switch (date_code)
        {
        case 0x20140801:
            fpga_version.date = E_20140801;
            break;
        case 0x20140802:
            fpga_version.date = E_20140802;
            break;
        case 0x20140808:
            fpga_version.date = E_20140808;
            break;
        case 0x20140819:
            fpga_version.date = E_20140819;
            break;
        case 0x20140822:
            fpga_version.date = E_20140822;
            break;
        case 0x20140824:
            fpga_version.date = E_20140824;
            break;
        case 0x20140825:
            fpga_version.date = E_20140825;
            break;
        case 0x20140826:
            fpga_version.date = E_20140826;
            break;
        case 0x20140827:
            fpga_version.date = E_20140827;
            break;
        case 0x20140828:
            fpga_version.date = E_20140828;
            break;
        case 0x20140830:
            fpga_version.date = E_20140830;
            break;
        case 0x20140901:
            fpga_version.date = E_20140901;
            break;
        case 0x20140902:
            fpga_version.date = E_20140902;
            break;
        case 0x20140903:
            fpga_version.date = E_20140903;
            break;
        case 0x20140904:
            fpga_version.date = E_20140904;
            break;
        case 0x20140905:
            fpga_version.date = E_20140905;
            break;
        case 0x20140908:
            fpga_version.date = E_20140908;
            break;
        default:
            fpga_version.date = E_FPGA_BIT_DATE_END;
            break;
        }
    }

    if (purpose_code == 0x01000000)
    {
        fpga_version.purpose = E_Platform;
    }
    else if (purpose_code == 0x02000000)
    {
        fpga_version.date = E_3G;
    }
    else if (purpose_code == 0x03000000)
    {
        fpga_version.date = E_4G;
    }
    else
    {
        fpga_version.purpose = E_FPGA_BIT_PURPOSE_END;
    }
    return fpga_version;

}

/*************************************************************************
* FUNCTION
*  INITSYNC_WriteAndPoll
*
* DESCRIPTION
*  This function used for system init dual core sync procedure
*
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
void INITSYNC_WriteAndPoll(volatile INITSYNC_STATE *writeaddr, volatile INITSYNC_STATE *polladdr)
{
    *writeaddr = E_INITSYNC_Done;
    cp15_data_memory_barrier();
    while(*polladdr != E_INITSYNC_Done)
    {
        INT_EnterExceptionForOtherCore();
    }
    *polladdr = E_INITSYNC_Passed;
    cp15_data_memory_barrier();
}


kal_bool INT_ChipVersion_BBREG_callback()
{
    kal_uint32 hw_version_code = DRV_Reg32(PS_CONFIG_base+0x0);
    kal_uint32 sw_version_code = DRV_Reg32(PS_CONFIG_base+0x4);
    kal_uint32 hw_code = DRV_Reg32(PS_CONFIG_base+0x8);
    kal_uint32 hw_sub_code = DRV_Reg32(PS_CONFIG_base+0xC);

    dhl_internal_trace(TRACE_ERROR, DHL_USER_FLAG_NONE, DHL_ACCESS_LEVEL_4_MTK_INTERNAL, INIT_LOG_VERSION_CODE_TITLE);
    dhl_internal_trace(TRACE_ERROR, DHL_USER_FLAG_NONE, DHL_ACCESS_LEVEL_4_MTK_INTERNAL, INIT_LOG_HW_VERSION_CODE, hw_version_code);
    dhl_internal_trace(TRACE_ERROR, DHL_USER_FLAG_NONE, DHL_ACCESS_LEVEL_4_MTK_INTERNAL, INIT_LOG_SW_VERSION_CODE, sw_version_code);
    dhl_internal_trace(TRACE_ERROR, DHL_USER_FLAG_NONE, DHL_ACCESS_LEVEL_4_MTK_INTERNAL, INIT_LOG_HW_CODE, hw_code);
    dhl_internal_trace(TRACE_ERROR, DHL_USER_FLAG_NONE, DHL_ACCESS_LEVEL_4_MTK_INTERNAL, INIT_LOG_HW_SUB_CODE, hw_sub_code);
    dhl_internal_trace(TRACE_ERROR, DHL_USER_FLAG_NONE, DHL_ACCESS_LEVEL_4_MTK_INTERNAL, INIT_LOG_VERSION_CODE_END);
   
    return KAL_TRUE;
}
void INT_Init_Misc()
{
#if defined(__MTK_TARGET__)
    /* register bb reg dump */
    chipversion_dump.regions = (kal_uint32*)chipversion_dump_regions;
    chipversion_dump.num = sizeof(chipversion_dump_regions) / (sizeof(kal_uint32) * 3);
    chipversion_dump.bbreg_dump_callback = INT_ChipVersion_BBREG_callback;
    EX_REGISTER_BBREG_DUMP(&chipversion_dump);
#endif /* __MTK_TARGET__ */
}
