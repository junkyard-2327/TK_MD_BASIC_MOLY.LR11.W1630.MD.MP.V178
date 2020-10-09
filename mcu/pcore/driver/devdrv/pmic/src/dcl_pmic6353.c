/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *     dcl_pmic6353.c
 *
 * Project:
 * --------
 *     MOLY Software
 *
 * Description:
 * ------------
 *     This file is for PMIC 6353
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#if defined(FPGA_CTP)
#include <common.h>
#endif

#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "pmic_wrap.h"
#include "kal_public_api.h"
#include "us_timer.h"
#include "dhl_trace.h"
#if defined(PMIC_6353_REG_API)

// Start PMIC_UNIT_TEST
//#define PMIC_UNIT_TEST
// ARM Section RW/RO/ZI Use Internal SRAM
//#define PMIC_INTERNAL_SRAM
#if !defined(__FUE__)
#define SAVEANDSETIRQMASK()      SaveAndSetIRQMask()
#define RESTOREIRQMASK(mask)     RestoreIRQMask(mask)
#else /*defined(__FUE__)*/
#define SAVEANDSETIRQMASK()      0
#define RESTOREIRQMASK(mask)     {}
#endif /*defined(__FUE__)*/

#define BANKS_NUM                       1
#define PMIC6353_MAX_REG_NUM                0x0FF0 // 0x0000~0x0F48
//#define PMIC_MAX_REG_NUM                0x40FF // Register BUCK1, Register ANALDO, Register DIGLDO (0x0470)

#define MT6353_HW_CID_E1            0x5310
#define MT6353_HW_CID_E2            0x5320
#define MT6353_HW_CID_E3            0x5330
#define MT6353_SW_CID_E1            0x5310
#define MT6353_SW_CID_E2            0x5320
#define MT6353_SW_CID_E3            0x5330

#define PMIC_READ                   0
#define PMIC_WRITE                  1

#define PMIC_6353                   0x6353

//////////////////////////////////////////////////
//                Exported APIs                 //
//////////////////////////////////////////////////
extern kal_bool pmic6353_reg_write(kal_uint16 reg, kal_uint16 val);
extern kal_bool pmic6353_reg_read(kal_uint16 reg, kal_uint16 *pVal);

extern DCL_BOOL dcl_pmic_init_done_query(void);
typedef enum
{
    AUXADC_READ_INIT = 0,
    AUXADC_READ_REQUEST = 1,
    AUXADC_READ_READY = 2,
    AUXADC_READ_BUSY = 3,
    AUXADC_READ_DATA = 4
}AUXADC_FSM;

typedef struct
{
    kal_uint32 command_flag;
    kal_uint32 reg_before_write;
    kal_uint32 write_value;
    kal_uint32 address_offset;
    kal_uint32 reg_mask;
    kal_uint32 reg_shift;
    kal_uint32 reg_addr;
    kal_uint32 reg_data;
}PMIC_REG_LOG;

AUXADC_FSM AUXADC_Status = AUXADC_READ_INIT;
PMIC_REG_LOG pmic_reg_log;

//#if (defined(__MTK_TARGET__) && defined(PMIC_INTERNAL_SRAM))
//__attribute__ ((zero_init))
//#endif /* __MTK_TARGET__ */
kal_uint8 pmic6353_hw_version;
kal_uint8 pmic6353_sw_version;
kal_uint16 pmic6353_reg[PMIC6353_MAX_REG_NUM];
DCL_BOOL pmic_init_done = DCL_FALSE;

const PMIC_FLAG_TABLE_ENTRY pmic6353_flags_table[] = 
{
    {MT6353_HWCID,		MT6353_HWCID_MASK,		MT6353_HWCID_SHIFT,		},
    {MT6353_SWCID,		MT6353_SWCID_MASK,		MT6353_SWCID_SHIFT,		},
    {MT6353_SPK_CON8,		MT6353_RG_SPK_CCODE_MASK,		MT6353_RG_SPK_CCODE_SHIFT,		},
    {MT6353_SPK_CON8,		MT6353_RG_SPK_EN_VIEW_VCM_MASK,		MT6353_RG_SPK_EN_VIEW_VCM_SHIFT,		},
    {MT6353_SPK_CON8,		MT6353_RG_SPK_FBRC_EN_MASK,		MT6353_RG_SPK_FBRC_EN_SHIFT,		},
    {MT6353_SPK_CON9,		MT6353_SPK_TEST_MODE0_MASK,		MT6353_SPK_TEST_MODE0_SHIFT,		},
    {MT6353_SPK_CON10,		MT6353_SPK_TD_DONE_MASK,		MT6353_SPK_TD_DONE_SHIFT,		},
    {MT6353_VPA_ANA_CON1,		MT6353_RG_VPA_ZX_OS_TRIM_MASK,		MT6353_RG_VPA_ZX_OS_TRIM_SHIFT,		},
    {MT6353_BUCK_VS1_VOL_CON1,		MT6353_BUCK_VS1_VOSEL_MASK,		MT6353_BUCK_VS1_VOSEL_SHIFT,		},
    {MT6353_BUCK_VS1_VOL_CON2,		MT6353_BUCK_VS1_VOSEL_ON_MASK,		MT6353_BUCK_VS1_VOSEL_ON_SHIFT,		},
    {MT6353_BUCK_VCORE_HWM_CON0,		MT6353_BUCK_VCORE_EN_CTRL_MASK,		MT6353_BUCK_VCORE_EN_CTRL_SHIFT,		},
    {MT6353_BUCK_VCORE_HWM_CON0,		MT6353_BUCK_VCORE_VOSEL_CTRL_MASK,		MT6353_BUCK_VCORE_VOSEL_CTRL_SHIFT,		},
    {MT6353_BUCK_VCORE_EN_CON0,		MT6353_BUCK_VCORE_EN_MASK,		MT6353_BUCK_VCORE_EN_SHIFT,		},
    {MT6353_BUCK_VCORE_VOL_CON0,		MT6353_DA_NI_VCORE_VOSEL_MASK,		MT6353_DA_NI_VCORE_VOSEL_SHIFT,		},
    {MT6353_BUCK_VCORE_VOL_CON1,		MT6353_BUCK_VCORE_VOSEL_MASK,		MT6353_BUCK_VCORE_VOSEL_SHIFT,		},
    {MT6353_BUCK_VCORE_VOL_CON2,		MT6353_BUCK_VCORE_VOSEL_ON_MASK,		MT6353_BUCK_VCORE_VOSEL_ON_SHIFT,		},
    {MT6353_BUCK_VCORE_VOL_CON3,		MT6353_BUCK_VCORE_VOSEL_SLEEP_MASK,		MT6353_BUCK_VCORE_VOSEL_SLEEP_SHIFT,		},
    {MT6353_BUCK_VCORE2_HWM_CON0,		MT6353_BUCK_VCORE2_EN_CTRL_MASK,		MT6353_BUCK_VCORE2_EN_CTRL_SHIFT,		},
    {MT6353_BUCK_VCORE2_HWM_CON0,		MT6353_BUCK_VCORE2_VOSEL_CTRL_MASK,		MT6353_BUCK_VCORE2_VOSEL_CTRL_SHIFT,		},
    {MT6353_BUCK_VCORE2_EN_CON0,		MT6353_BUCK_VCORE2_EN_MASK,		MT6353_BUCK_VCORE2_EN_SHIFT,		},
    {MT6353_BUCK_VCORE2_VOL_CON0,		MT6353_DA_NI_VCORE2_VOSEL_MASK,		MT6353_DA_NI_VCORE2_VOSEL_SHIFT,		},
    {MT6353_BUCK_VCORE2_VOL_CON1,		MT6353_BUCK_VCORE2_VOSEL_MASK,		MT6353_BUCK_VCORE2_VOSEL_SHIFT,		},
    {MT6353_BUCK_VCORE2_VOL_CON2,		MT6353_BUCK_VCORE2_VOSEL_ON_MASK,		MT6353_BUCK_VCORE2_VOSEL_ON_SHIFT,		},
    {MT6353_BUCK_VCORE2_VOL_CON3,		MT6353_BUCK_VCORE2_VOSEL_SLEEP_MASK,		MT6353_BUCK_VCORE2_VOSEL_SLEEP_SHIFT,		},
    {MT6353_BUCK_VPA_EN_CON0,		MT6353_BUCK_VPA_EN_MASK,		MT6353_BUCK_VPA_EN_SHIFT,		},
    {MT6353_BUCK_VPA_VOL_CON1,		MT6353_BUCK_VPA_VOSEL_MASK,		MT6353_BUCK_VPA_VOSEL_SHIFT,		},
    {MT6353_LDO_VTCXO24_SW_CON0,		MT6353_LDO_VTCXO24_SWITCH_MASK,		MT6353_LDO_VTCXO24_SWITCH_SHIFT,		},
    {MT6353_LDO3_VTCXO28_CON0,		MT6353_LDO_VTCXO28_LP_MODE_MASK,		MT6353_LDO_VTCXO28_LP_MODE_SHIFT,		},
    {MT6353_LDO3_VTCXO28_CON0,		MT6353_LDO_VTCXO28_EN_MASK,		MT6353_LDO_VTCXO28_EN_SHIFT,		},
    {MT6353_LDO3_VTCXO28_CON0,		MT6353_LDO_VTCXO28_LP_CTRL_MASK,		MT6353_LDO_VTCXO28_LP_CTRL_SHIFT,		},
    {MT6353_LDO3_VTCXO28_CON0,		MT6353_LDO_VTCXO28_EN_CTRL_MASK,		MT6353_LDO_VTCXO28_EN_CTRL_SHIFT,		},
    {MT6353_LDO3_VTCXO28_CON0,		MT6353_LDO_VTCXO28_LP_SEL_MASK,		MT6353_LDO_VTCXO28_LP_SEL_SHIFT,		},
    {MT6353_LDO3_VTCXO28_CON0,		MT6353_LDO_VTCXO28_EN_SEL_MASK,		MT6353_LDO_VTCXO28_EN_SEL_SHIFT,		},
    {MT6353_LDO3_VTCXO24_CON0,		MT6353_LDO_VTCXO24_LP_MODE_MASK,		MT6353_LDO_VTCXO24_LP_MODE_SHIFT,		},
    {MT6353_LDO3_VTCXO24_CON0,		MT6353_LDO_VTCXO24_EN_MASK,		MT6353_LDO_VTCXO24_EN_SHIFT,		},
    {MT6353_LDO3_VTCXO24_CON0,		MT6353_LDO_VTCXO24_LP_CTRL_MASK,		MT6353_LDO_VTCXO24_LP_CTRL_SHIFT,		},
    {MT6353_LDO3_VTCXO24_CON0,		MT6353_LDO_VTCXO24_EN_CTRL_MASK,		MT6353_LDO_VTCXO24_EN_CTRL_SHIFT,		},
    {MT6353_LDO3_VTCXO24_CON0,		MT6353_LDO_VTCXO24_LP_SEL_MASK,		MT6353_LDO_VTCXO24_LP_SEL_SHIFT,		},
    {MT6353_LDO3_VTCXO24_CON0,		MT6353_LDO_VTCXO24_EN_SEL_MASK,		MT6353_LDO_VTCXO24_EN_SEL_SHIFT,		},
    {MT6353_LDO3_VRF18_CON0,		MT6353_LDO_VRF18_LP_MODE_MASK,		MT6353_LDO_VRF18_LP_MODE_SHIFT,		},
    {MT6353_LDO3_VRF18_CON0,		MT6353_LDO_VRF18_EN_MASK,		MT6353_LDO_VRF18_EN_SHIFT,		},
    {MT6353_LDO3_VRF18_CON0,		MT6353_LDO_VRF18_LP_CTRL_MASK,		MT6353_LDO_VRF18_LP_CTRL_SHIFT,		},
    {MT6353_LDO3_VRF18_CON0,		MT6353_LDO_VRF18_EN_CTRL_MASK,		MT6353_LDO_VRF18_EN_CTRL_SHIFT,		},
    {MT6353_LDO3_VRF18_CON0,		MT6353_LDO_VRF18_LP_SEL_MASK,		MT6353_LDO_VRF18_LP_SEL_SHIFT,		},
    {MT6353_LDO3_VRF18_CON0,		MT6353_LDO_VRF18_EN_SEL_MASK,		MT6353_LDO_VRF18_EN_SEL_SHIFT,		},
    {MT6353_LDO3_VRF12_CON0,		MT6353_LDO_VRF12_LP_MODE_MASK,		MT6353_LDO_VRF12_LP_MODE_SHIFT,		},
    {MT6353_LDO3_VRF12_CON0,		MT6353_LDO_VRF12_EN_MASK,		MT6353_LDO_VRF12_EN_SHIFT,		},
    {MT6353_LDO3_VRF12_CON0,		MT6353_LDO_VRF12_LP_CTRL_MASK,		MT6353_LDO_VRF12_LP_CTRL_SHIFT,		},
    {MT6353_LDO3_VRF12_CON0,		MT6353_LDO_VRF12_EN_CTRL_MASK,		MT6353_LDO_VRF12_EN_CTRL_SHIFT,		},
    {MT6353_LDO3_VRF12_CON0,		MT6353_LDO_VRF12_LP_SEL_MASK,		MT6353_LDO_VRF12_LP_SEL_SHIFT,		},
    {MT6353_LDO3_VRF12_CON0,		MT6353_LDO_VRF12_EN_SEL_MASK,		MT6353_LDO_VRF12_EN_SEL_SHIFT,		},
    {MT6353_LDO1_VSIM1_CON0,		MT6353_LDO_VSIM1_LP_MODE_MASK,		MT6353_LDO_VSIM1_LP_MODE_SHIFT,		},
    {MT6353_LDO1_VSIM1_CON0,		MT6353_LDO_VSIM1_EN_MASK,		MT6353_LDO_VSIM1_EN_SHIFT,		},
    {MT6353_LDO1_VSIM1_CON0,		MT6353_LDO_VSIM1_LP_CTRL_MASK,		MT6353_LDO_VSIM1_LP_CTRL_SHIFT,		},
    {MT6353_LDO1_VSIM1_CON0,		MT6353_LDO_VSIM1_LP_SEL_MASK,		MT6353_LDO_VSIM1_LP_SEL_SHIFT,		},
    {MT6353_LDO1_VSIM2_CON0,		MT6353_LDO_VSIM2_LP_MODE_MASK,		MT6353_LDO_VSIM2_LP_MODE_SHIFT,		},
    {MT6353_LDO1_VSIM2_CON0,		MT6353_LDO_VSIM2_EN_MASK,		MT6353_LDO_VSIM2_EN_SHIFT,		},
    {MT6353_LDO1_VSIM2_CON0,		MT6353_LDO_VSIM2_LP_CTRL_MASK,		MT6353_LDO_VSIM2_LP_CTRL_SHIFT,		},
    {MT6353_LDO1_VSIM2_CON0,		MT6353_LDO_VSIM2_LP_SEL_MASK,		MT6353_LDO_VSIM2_LP_SEL_SHIFT,		},
    {MT6353_DLDO_ANA_CON2,		MT6353_RG_VSIM1_VOSEL_MASK,		MT6353_RG_VSIM1_VOSEL_SHIFT,		},
    {MT6353_DLDO_ANA_CON3,		MT6353_RG_VSIM2_VOSEL_MASK,		MT6353_RG_VSIM2_VOSEL_SHIFT,		},
    {MT6353_AUXADC_ADC17,		MT6353_AUXADC_ADC_OUT_CH7_BY_MD_MASK,		MT6353_AUXADC_ADC_OUT_CH7_BY_MD_SHIFT,		},
    {MT6353_AUXADC_ADC17,		MT6353_AUXADC_ADC_RDY_CH7_BY_MD_MASK,		MT6353_AUXADC_ADC_RDY_CH7_BY_MD_SHIFT,		},
    {MT6353_AUXADC_RQST1_SET,		MT6353_AUXADC_RQST1_SET_MASK,		MT6353_AUXADC_RQST1_SET_SHIFT,		},
    {MT6353_AUXADC_RQST1_CLR,		MT6353_AUXADC_RQST1_CLR_MASK,		MT6353_AUXADC_RQST1_CLR_SHIFT,		},
};
//////////////////////////////////////////////////
//                  WRITE APIs                  //
//////////////////////////////////////////////////

// Write Whole Bytes
void dcl_pmic6353_byte_write(DCL_UINT16 addr, DCL_UINT16 val)
{
    kal_uint32 savedMask = 0;
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif
    if(addr < PMIC6353_MAX_REG_NUM)
    {
        pmic6353_reg[addr] = val;
    }


#if defined(__L1CORE__)
    DrvPWRAP_WACS0(PMIC_WRAP_WRITE, addr, val, 0x00);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_WRITE, addr, val, 0x00);
#endif

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time = ust_get_current_time();
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].duration_time = ust_get_duration(pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time, pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time);
#endif

#if !defined(__UBL__) && !defined(__FUE__)
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)
}

// Write register field
void dcl_pmic6353_field_write(PMIC6353_FLAGS_LIST_ENUM flag, DCL_UINT16 sel)
{
    const PMIC_FLAG_TABLE_ENTRY *pTable = pmic6353_flags_table;
    kal_uint32 savedMask = 0;
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

    pmic_reg_log.command_flag = flag;
    pmic_reg_log.reg_before_write = pmic6353_reg[pTable[flag].offset];

    pmic6353_reg[pTable[flag].offset] &= ~(pTable[flag].mask << pTable[flag].shift);
    pmic6353_reg[pTable[flag].offset] |= ((kal_uint16)sel << pTable[flag].shift);

#if defined(__L1CORE__)
    DrvPWRAP_WACS0(PMIC_WRAP_WRITE, pTable[flag].offset, pmic6353_reg[pTable[flag].offset], 0x00);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_WRITE, pTable[flag].offset, pmic6353_reg[pTable[flag].offset], 0x00);
#endif

    pmic_reg_log.write_value = sel;
    pmic_reg_log.address_offset = pTable[flag].offset;
    pmic_reg_log.reg_mask = pTable[flag].mask;
    pmic_reg_log.reg_shift = pTable[flag].shift;
    pmic_reg_log.reg_addr = pTable[flag].offset;
    pmic_reg_log.reg_data = pmic6353_reg[pTable[flag].offset];

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time = ust_get_current_time();
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].duration_time = ust_get_duration(pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time, pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time);
#endif

#if !defined(__UBL__) && !defined(__FUE__)
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)
}

//////////////////////////////////////////////////
//                  READ APIs                   //
//////////////////////////////////////////////////

// Read Whole Bytes
DCL_UINT16 dcl_pmic6353_byte_return(DCL_UINT16 addr)
{
    DCL_UINT16 reg_temp;
    kal_uint32 savedMask = 0;

#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

#if defined(__L1CORE__)
    DrvPWRAP_WACS0(PMIC_WRAP_READ, (DCL_UINT32)addr, 0x00, &reg_temp);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_READ, (DCL_UINT32)addr, 0x00, &reg_temp);
#endif
    if(addr < PMIC6353_MAX_REG_NUM)
    {
        pmic6353_reg[addr] = reg_temp;
    }

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time = ust_get_current_time();
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].duration_time = ust_get_duration(pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time, pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time);
#endif

#if !defined(__UBL__) && !defined(__FUE__)
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)

    return reg_temp;
}

// Read register field
DCL_UINT16 dcl_pmic6353_field_read(PMIC6353_FLAGS_LIST_ENUM flag)
{
    const PMIC_FLAG_TABLE_ENTRY *pTable = pmic6353_flags_table;
    kal_uint32 savedMask = 0;
    DCL_UINT16 reg_return = 0;

#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

#if defined(__L1CORE__)
    DrvPWRAP_WACS0(PMIC_WRAP_READ, pTable[flag].offset, 0x00, &pmic6353_reg[pTable[flag].offset]);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_READ, pTable[flag].offset, 0x00, &pmic6353_reg[pTable[flag].offset]);
#endif

    reg_return = ((pmic6353_reg[pTable[flag].offset] & (pTable[flag].mask << pTable[flag].shift)) >> pTable[flag].shift);

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time = ust_get_current_time();
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].duration_time = ust_get_duration(pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time, pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time);
#endif

#if !defined(__UBL__) && !defined(__FUE__)
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)

    return reg_return;
}


// Exported for EM used
void pmic6353_EM_reg_write(kal_uint16 reg, kal_uint16 val){
    dcl_pmic6353_byte_write(reg, val);
}

kal_uint16 pmic6353_EM_reg_read(kal_uint16 reg){
    return  dcl_pmic6353_byte_return(reg);
}

PMU_CTRL_PMIC_ECO_VERSION_ENUM pmic6353_get_HW_ECO_version(void)
{
    return pmic6353_hw_version;
}

PMU_CTRL_PMIC_ECO_VERSION_ENUM pmic6353_get_SW_version(void)
{
    return pmic6353_sw_version;
}

const DCL_UINT32 vpa_vosel[] =
{
    PMU_VOLT_00_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_00_600000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_00_700000_V,   PMU_VOLT_INVALID,   PMU_VOLT_00_800000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_00_900000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_000000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_01_100000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_200000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_01_300000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_400000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_01_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_600000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_01_700000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_800000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_01_900000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_000000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_02_100000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_200000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_02_300000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_400000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_02_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_600000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_02_700000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_800000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_02_900000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_000000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_03_100000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_200000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_03_300000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_400000_V,   PMU_VOLT_INVALID,
    PMU_VOLT_03_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_600000_V,   PMU_VOLT_INVALID,

};

/*const DCL_UINT32 vsim1_vosel[] =
{
    PMU_VOLT_INVALID,       PMU_VOLT_INVALID,  PMU_VOLT_01_700000_V,   PMU_VOLT_01_800000_V,
    PMU_VOLT_01_860000_V,       PMU_VOLT_02_760000_V,  PMU_VOLT_03_000000_V,   PMU_VOLT_03_100000_V,
};*/

const DCL_UINT32 vsim1_vosel[] =
{
    PMU_VOLT_INVALID,	PMU_VOLT_01_700000_V,	PMU_VOLT_01_800000_V,	PMU_VOLT_01_860000_V,
    PMU_VOLT_INVALID,   PMU_VOLT_02_760000_V,	PMU_VOLT_03_000000_V,	PMU_VOLT_03_100000_V,
};

PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
	{ENC(LDO_BUCK_SET_VOLTAGE, VPA_SW),		    vpa_vosel,		    NULL,	    		GETARRNUM(vpa_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE, VSIM1),		    vsim1_vosel,		NULL,	    		GETARRNUM(vsim1_vosel)		},
    {ENC(LDO_BUCK_SET_VOLTAGE, VSIM2),		    vsim1_vosel,		NULL,   			GETARRNUM(vsim1_vosel)	    },
};

extern PMU_CONTROL_HANDLER pmu_control_handler;

DCL_UINT16 pmu_parameter_size = 0;

DCL_STATUS PMIC6353_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
    DCL_UINT16	regVal;
    DCL_INT32	return_val = STATUS_FAIL;

	switch(cmd)
    {
        case LDO_BUCK_SET_EN:
        {
            PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);

            switch(pLdoBuckCtrl->mod)
            {
                case VRF18:
                {							
                    dcl_pmic6353_field_write(MT6353_LDO_VRF18_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VRF12:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VRF12_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM1:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VSIM1_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VSIM2_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VPA_SW:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VPA_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE2:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE2_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VTCXO24:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO24_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
				break;

                case VTCXO28:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO28_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
				break;
                
				default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_SET_LP_MODE_SET:
        {
			PMU_CTRL_LDO_BUCK_SET_LP_MODE_SET *pLdoBuckCtrl =& (data->rPMULdoBuckSetLpModeSet);
         
			switch(pLdoBuckCtrl->mod)
            {
                case VRF18:
                {
                    // 1'b0:Normal mode, 1'b1:Low power mode
                    dcl_pmic6353_field_write(MT6353_LDO_VRF18_LP_MODE, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VRF12:
                {
                    // 1'b0:Normal mode, 1'b1:Low power mode
                    dcl_pmic6353_field_write(MT6353_LDO_VRF12_LP_MODE, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM1:
                {
                    // 1'b0:Normal mode, 1'b1:Low power mode
                    dcl_pmic6353_field_write(MT6353_LDO_VSIM1_LP_MODE, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    // 1'b0:Normal mode, 1'b1:Low power mode
                    dcl_pmic6353_field_write(MT6353_LDO_VSIM2_LP_MODE, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VTCXO24:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO24_LP_MODE, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
				break;

                case VTCXO28:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO28_LP_MODE, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
				break;
              
				default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_SET_LP_SEL:
        {
            PMU_CTRL_LDO_BUCK_SET_LP_SEL *pLdoBuckCtrl =& (data->rPMULdoBuckSetLpSel);

            switch(pLdoBuckCtrl->mod)
            {
                case VRF18:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VRF18_LP_CTRL, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
                break;
                
				case VRF12:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VRF12_LP_CTRL, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
                break;


                case VSIM1:
                {
                    // 1'b0: SW control by VSIM1_LP_MODE, 1'b1: HW control by SRCLKEN
                    dcl_pmic6353_field_write(MT6353_LDO_VSIM1_LP_CTRL, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VSIM2_LP_CTRL, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
                break;

                case VTCXO24:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO24_LP_CTRL, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
				break;

                case VTCXO28:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO28_LP_CTRL, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
				break;
				
				default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_SET_VOLTAGE: //WILMA
        {
            PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl = &(data->rPMULdoBuckSetVoltage);
            regVal = PMU_Parameter_to_Value(ENC(cmd, pLdoBuckCtrl->mod), pLdoBuckCtrl->voltage);

            switch(pLdoBuckCtrl->mod)
            {
                case VSIM1:
                {
                    dcl_pmic6353_field_write(MT6353_RG_VSIM1_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6353_field_write(MT6353_RG_VSIM2_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VPA_SW:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VPA_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;
				
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_GET_VOLTAGE:
        {
            PMU_CTRL_LDO_BUCK_GET_VOLTAGE	*pLdoBuckCtrl=&(data->rPMULdoBuckGetVolt);

            switch(pLdoBuckCtrl->mod)
            {
                case VCORE:
                {
					pLdoBuckCtrl->code = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_DA_NI_VCORE_VOSEL);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE2:
                {
					pLdoBuckCtrl->code = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_DA_NI_VCORE2_VOSEL);
                    return_val = STATUS_OK;
                }
                break;

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

		case LDO_BUCK_GET_VOSEL_CTRL:
		{
    	    PMU_CTRL_LDO_BUCK_GET_VOSEL_CTRL *pLdoBuckCtrl = &(data->rPMULdoBuckGetVoselCtrl);

            switch(pLdoBuckCtrl->mod)
            {
                case VCORE:
                {
					pLdoBuckCtrl->mode = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_BUCK_VCORE_VOSEL_CTRL);
                    return_val = STATUS_OK;
                }
                break;
             
				case VCORE2:
                {
					pLdoBuckCtrl->mode = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_BUCK_VCORE2_VOSEL_CTRL);
                    return_val = STATUS_OK;
                }
                break;
               
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
		}
		break;

        case LDO_BUCK_GET_VOSEL:
        {
            PMU_CTRL_LDO_BUCK_GET_VOSEL *pLdoBuckCtrl = &(data->rPMULdoBuckGetVosel);

            switch(pLdoBuckCtrl->mod)
            {
                case VCORE:
                {
					pLdoBuckCtrl->code = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_BUCK_VCORE_VOSEL);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE2:
                {
					pLdoBuckCtrl->code = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_BUCK_VCORE2_VOSEL);
                    return_val = STATUS_OK;
                }
                break;
               
				case VS1:
                {
					pLdoBuckCtrl->code = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_BUCK_VS1_VOSEL);
                    return_val = STATUS_OK;
                }
                break;
               
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_GET_VOSEL_ON:
        {
            PMU_CTRL_LDO_BUCK_GET_VOSEL_ON *pLdoBuckCtrl = &(data->rPMULdoBuckGetVoselOn);

            switch(pLdoBuckCtrl->mod)
            {
                case VCORE:
                {
					pLdoBuckCtrl->code = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_BUCK_VCORE_VOSEL_ON);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE2:
                {
					pLdoBuckCtrl->code = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_BUCK_VCORE2_VOSEL_ON);
                    return_val = STATUS_OK;
                }
                break;

				case VS1:
                {
					pLdoBuckCtrl->code = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_BUCK_VS1_VOSEL_ON);
                    return_val = STATUS_OK;
                }
                break;

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_GET_VOSEL_SLEEP:
        {
            PMU_CTRL_LDO_BUCK_GET_VOSEL_SLEEP *pLdoBuckCtrl = &(data->rPMULdoBuckGetVoselSleep);

            switch(pLdoBuckCtrl->mod)
            {
                case VCORE:
                {
					pLdoBuckCtrl->code = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_BUCK_VCORE_VOSEL_SLEEP);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE2:
                {
					pLdoBuckCtrl->code = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_BUCK_VCORE2_VOSEL_SLEEP);
                    return_val = STATUS_OK;
                }
                break;
            
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

		case LDO_BUCK_SET_VOSEL_CTRL:
		{
    	    PMU_CTRL_LDO_BUCK_SET_VOSEL_CTRL *pLdoBuckCtrl = &(data->rPMULdoBuckSetVoselCtrl);

            switch(pLdoBuckCtrl->mod)
            {
                case VCORE:
                {
                    // 0: SW control, 1: HW
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE_VOSEL_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;
				
                case VCORE2:
                {
                    // 0: SW control, 1: HW
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE2_VOSEL_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;
				
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
		}
		break;

        case LDO_BUCK_SET_VOSEL:
        {
            PMU_CTRL_LDO_BUCK_SET_VOSEL *pLdoBuckCtrl = &(data->rPMULdoBuckSetVosel);

            switch(pLdoBuckCtrl->mod)
            {
                case VCORE:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE_VOSEL, pLdoBuckCtrl->code);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE2:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE2_VOSEL, pLdoBuckCtrl->code);
                    return_val = STATUS_OK;
                }
                break;

				case VS1:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VS1_VOSEL, pLdoBuckCtrl->code);
                    return_val = STATUS_OK;
                }
                break;

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_SET_VOSEL_ON:
        {
            PMU_CTRL_LDO_BUCK_SET_VOSEL_ON *pLdoBuckCtrl = &(data->rPMULdoBuckSetVoselOn);

            switch(pLdoBuckCtrl->mod)
            {
                case VCORE:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE_VOSEL_ON, pLdoBuckCtrl->code);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE2:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE2_VOSEL_ON, pLdoBuckCtrl->code);
                    return_val = STATUS_OK;
                }
                break;

				case VS1:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VS1_VOSEL_ON, pLdoBuckCtrl->code);
                    return_val = STATUS_OK;
                }
                break;

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_SET_VOSEL_SLEEP:
        {
            PMU_CTRL_LDO_BUCK_SET_VOSEL_SLEEP *pLdoBuckCtrl = &(data->rPMULdoBuckSetVoselSleep);

            switch(pLdoBuckCtrl->mod)
            {
                case VCORE:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE_VOSEL_SLEEP, pLdoBuckCtrl->code);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE2:
                {
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE2_VOSEL_SLEEP, pLdoBuckCtrl->code);
                    return_val = STATUS_OK;
                }
                break;

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

		case LDO_BUCK_SET_EN_CTRL:
		{
    	    PMU_CTRL_LDO_BUCK_SET_EN_CTRL *pLdoBuckCtrl = &(data->rPMULdoBuckSetEnCtrl);

            switch(pLdoBuckCtrl->mod)
            {
				case VRF18:
                {
                    // 0: SW control1: HW control
                    dcl_pmic6353_field_write(MT6353_LDO_VRF18_EN_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;

				case VRF12:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VRF12_EN_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE:
                {
                    // 0: SW control, 1: HW
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE_EN_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;
				
                case VCORE2:
                {
                    // 0: SW control, 1: HW
                    dcl_pmic6353_field_write(MT6353_BUCK_VCORE2_EN_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;
								
                case VTCXO24:
                {
                    // 0: SW control, 1: HW
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO24_EN_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;
				
                case VTCXO28:
                {
                    // 0: SW control, 1: HW
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO28_EN_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;
				
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
		}
		break;

		case LDO_BUCK_SET_EN_SEL:
		{
    	    PMU_CTRL_LDO_BUCK_SET_EN_SEL *pLdoBuckCtrl = &(data->rPMULdoBuckSetEnSel);

            switch(pLdoBuckCtrl->mod)
            {
				case VRF18:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VRF18_EN_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;

				case VRF12:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VRF12_EN_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;

                //case VSIM1:
                //{
                //    dcl_pmic6353_field_write(MT6353_RG_VSIM1_EN_SEL, pLdoBuckCtrl->sel);
                //    return_val = STATUS_OK;
                //}
                //break;
                //
                //case VSIM2:
                //{
                //    dcl_pmic6353_field_write(MT6353_RG_VSIM2_EN_SEL, pLdoBuckCtrl->sel);
                //    return_val = STATUS_OK;
                //}
                //break;

                case VTCXO24:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO24_EN_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
				break;

                case VTCXO28:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO28_EN_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
				break;
				
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
		}
		break;

        case LDO_BUCK_SET_SRCLK_MODE_SEL:
        {
            PMU_CTRL_LDO_BUCK_SET_SRCLK_MODE_SEL *pLdoBuckCtrl = &(data->rPMULdoBuckSetSrclkModeSel);

            switch(pLdoBuckCtrl->mod)
            {
                case VRF18:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VRF18_LP_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;
				
                case VRF12:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VRF12_LP_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM1:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VSIM1_LP_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VSIM2_LP_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;

                case VTCXO24:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO24_LP_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
				break;

                case VTCXO28:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO28_LP_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
				break;
				
				default:
                return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
		break;

        case LDO_BUCK_SET_VTCXO24_SWITCH:
        {
            PMU_CTRL_LDO_SET_VTCXO24_SWITCH_EN *pLdoBuckCtrl = &(data->rPMULdoBuckSetVtcxoSwith);

            switch(pLdoBuckCtrl->mod)
            {
                case VTCXO24:
                {
                    dcl_pmic6353_field_write(MT6353_LDO_VTCXO24_SWITCH, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
				break;
                
				default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case VPA_SET_EN:
        {
            PMU_CTRL_VPA_SET_EN *pVpaSetEn = &(data->rPMUVpaSetEn);
            dcl_pmic6353_field_write(MT6353_BUCK_VPA_EN, pVpaSetEn->enable);
            return_val = STATUS_OK;
        }
        break;

		case VPA_GET_VOLTAGE_LIST:
		{
			PMU_CTRL_VPA_GET_VOLTAGE_LIST *pVpaCtrl = &(data->rPMUVpaGetVoltageList);
			pVpaCtrl->pVoltageList = vpa_vosel;
			pVpaCtrl->number = GETARRNUM(vpa_vosel);
            return_val = STATUS_OK;
		}
		break;
#if 1
        /*
        1.	AUXADC_RQST1_CLR[7]	1'h1
        2.	AUXADC_RQST1_SET[7]	1'h1
        3.	After 10us
        4.	Polling ready, AUXADC_ADC_RDY_Ch7_BY_MD
        5.	After AUXADC_ADC_RDY_Ch7_BY_MD = 1, get data by AUXADC_ADC_OUT_CH7_BY_MD
        6.	AUXADC_RQST1_CLR[7]	1'h1
        */
        case ADC_SET_RQST:
        {
            PMU_CTRL_ADC_SET_RQST *pAdcCtrl = &(data->rPMUAdcSetRqst);
            if((AUXADC_Status != AUXADC_READ_INIT) && (AUXADC_Status != AUXADC_READ_DATA))
            {
                ASSERT(0);
            }
            // Enable CLKSQ for MD (SW mode) RG_CLKSQ_EN_AUX_MD
            dcl_pmic6353_byte_write(MT6353_TOP_CLKSQ_SET, (0x1 << MT6353_RG_CLKSQ_EN_AUX_MD_SHIFT));
            dcl_pmic6353_byte_write(MT6353_AUXADC_RQST1_CLR, (pAdcCtrl->enable << MT6353_AUXADC_RQST_CH7_BY_MD_SHIFT));
            dcl_pmic6353_byte_write(MT6353_AUXADC_RQST1_SET, (0x1 << MT6353_AUXADC_RQST_CH7_BY_MD_SHIFT));
            AUXADC_Status = AUXADC_READ_REQUEST;
            return_val = STATUS_OK;
        }
        break;

        case ADC_GET_RDY_MD:
        {
            PMU_CTRL_ADC_GET_RDY_MD *pAdcCtrl = &(data->rPMUAdcGetRdyMd);

            pAdcCtrl->status = (DCL_BOOL)dcl_pmic6353_field_read(MT6353_AUXADC_ADC_RDY_CH7_BY_MD);
            if((AUXADC_Status != AUXADC_READ_REQUEST) && (AUXADC_Status != AUXADC_READ_BUSY))
            {
                ASSERT(0);
            }

            if(pAdcCtrl->status == DCL_TRUE)
            {
                AUXADC_Status = AUXADC_READ_READY;
            }
            else
            {
                AUXADC_Status = AUXADC_READ_BUSY;
            }

            return_val = STATUS_OK;
        }
        break;

        case ADC_GET_OUT_MD:
        {
            PMU_CTRL_ADC_GET_OUT_MD *pAdcCtrl = &(data->rPMUAdcGetOutMd);
            if(AUXADC_Status != AUXADC_READ_READY)
            {
                ASSERT(0);
            }
            pAdcCtrl->data = (DCL_UINT32)dcl_pmic6353_field_read(MT6353_AUXADC_ADC_OUT_CH7_BY_MD);
            AUXADC_Status = AUXADC_READ_DATA;
            dcl_pmic6353_byte_write(MT6353_AUXADC_RQST1_CLR, (0x1 << MT6353_AUXADC_RQST_CH7_BY_MD_SHIFT));
            // Disable CLKSQ for MD (SW mode) RG_CLKSQ_EN_AUX_MD
            dcl_pmic6353_byte_write(MT6353_TOP_CLKSQ_CLR, (0x1 << MT6353_RG_CLKSQ_EN_AUX_MD_SHIFT));

            return_val = STATUS_OK;
        }
        break;
#endif
        case MISC_GET_HW_VERSION:
        {
            PMU_CTRL_MISC_GET_HW_VERSION	*pMiscCtrl = &(data->rPMUMiscGetHwVersion);
            if(pMiscCtrl->chip_name == PMIC_6353)
            {
                pMiscCtrl->version = pmic6353_hw_version;
            }
            return_val = STATUS_OK;
        }
        break;
		
        case MISC_SET_REGISTER_VALUE:
        {
            PMU_CTRL_MISC_SET_REGISTER_VALUE	*pChrCtrl = &(data->rPMUMiscSetRegisterValue);
            pmic6353_EM_reg_write(pChrCtrl->offset, pChrCtrl->value);
            return_val = STATUS_OK;
        }
        break;

        case MISC_GET_REGISTER_VALUE:
        {
            PMU_CTRL_MISC_GET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscGetRegisterValue);
            pChrCtrl->value = pmic6353_EM_reg_read(pChrCtrl->offset);
            return_val = STATUS_OK;
        }
        break;

        default:
            return_val = STATUS_UNSUPPORTED;
        break;
    }

    return return_val;
}

extern void dcl_pmic6353_modem_only_init(void);
extern DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr);
extern void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value);
extern kal_uint32 PMIC_Config_Interface(kal_bool action, kal_uint32 address, kal_uint32 wdata, kal_uint32 *rdata, kal_uint32 chip_name);
extern void PMIC_Read_All(void);
#if defined(PMIC_UNIT_TEST)
extern void PMIC_Read_All(void);
extern void PMIC_Unit_Test(void);
#endif

#if defined(__DUAL_TALK_SUPPORT__)
static void PMIC_DRV_SetData(DCL_UINT32 addr, DCL_UINT32 bitmask, DCL_UINT16 value, DCL_UINT32 bank)
{
extern void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value);
extern DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr);
   DCL_UINT32 temp;
   addr |= (bank << 31);
   temp = (~(bitmask)) & DRV_Read_PMIC_Data(addr);
   temp |= ((value) & (bitmask));
   DRV_Write_PMIC_Data(addr,temp);
}
#endif

void dcl_pmic6353_internal_init(void)
{
#if defined(__DUAL_TALK_SUPPORT__)
//PMIC_DRV_SetData(0xA02     , 0x2    , 0x2    , 0x0);
#endif
}

#if defined(__DHL_MODULE__)
extern kal_bool dhl_register_custom_mem_read(DHL_CUSTOM_MEM_TYPE mem_type, DHL_CUSTOM_READ_MEM_CALLBACK read_cb);
extern kal_bool dhl_register_custom_mem_write(DHL_CUSTOM_MEM_TYPE mem_type, DHL_CUSTOM_WRITE_MEM_CALLBACK write_cb);
extern void PMIC_Read_Callback_For_DHL(void* read_addr, kal_uint32 len, kal_uint32 option, void** read_buffer_addr, kal_uint32 *read_buffer_len);
extern void PMIC_Write_Callback_For_DHL(void* write_addr, kal_uint32 len, kal_uint32 option, void* write_buffer_addr);
#endif

void dcl_pmic6353_init(void){
    extern void pmic_wrap_dump_init(void);
    pmu_control_handler = PMIC6353_control_handler;
    pmu_parameter_size = GETARRNUM(pmu_parameter_table);
#if defined(__DHL_MODULE__)
    dhl_register_custom_mem_read(DHL_CUSTOM_MEM_PMIC, PMIC_Read_Callback_For_DHL);
    dhl_register_custom_mem_write(DHL_CUSTOM_MEM_PMIC, PMIC_Write_Callback_For_DHL);
#endif
    pmic_wrap_dump_init();

#if  !defined(__SMART_PHONE_MODEM__)
    DrvPWRAP_Init();
#endif
    pmic6353_hw_version = PMIC_ECO_E1;
    pmic6353_sw_version = PMIC_ECO_E1;

    // Get MT6353 ECO version
    {
        kal_uint16 pmic6353_hw_eco_version = 0;
        kal_uint16 pmic6353_sw_eco_version = 0;
        pmic6353_hw_eco_version = dcl_pmic6353_byte_return(MT6353_HWCID);
        pmic6353_sw_eco_version = dcl_pmic6353_byte_return(MT6353_SWCID);

        if (pmic6353_hw_eco_version == MT6353_HW_CID_E1)
        {
            pmic6353_hw_version = PMIC_ECO_E1;
        }
        else
        {
            pmic6353_hw_version = PMIC_ECO_E2;
        }

        if (pmic6353_sw_eco_version == MT6353_SW_CID_E1)
        {
            pmic6353_sw_version = PMIC_ECO_E1;
        }
        else
        {
            pmic6353_sw_version = PMIC_ECO_E2;
        }
    }

    PMIC_Read_All();

#if !defined(__SMART_PHONE_MODEM__)
    dcl_pmic6353_modem_only_init();
#endif
    dcl_pmic6353_internal_init();

    //  pmic6353_customization_init();
#if defined(PMIC_UNIT_TEST)
    PMIC_Read_All();
    PMIC_Unit_Test();
    PMIC_Read_All();
#endif
    pmic_init_done = DCL_TRUE;

}

#if defined(__DHL_MODULE__)
kal_uint32 pmic_read_data;
void PMIC_Read_Callback_For_DHL(void* read_addr, kal_uint32 len, kal_uint32 option, void** read_buffer_addr, kal_uint32 *read_buffer_len)
{
    kal_uint32 write_buffer_addr = 0;
    kal_uint32 read_data_addr = (kal_uint32)read_addr;
    // Write Workaround
    if(read_data_addr & 0x00000001)
    {
         write_buffer_addr = (read_data_addr & 0xFFFF0000) >> 16;
         read_data_addr = (read_data_addr & 0x0000FFFE);
         PMIC_Config_Interface(PMIC_WRITE, read_data_addr, (kal_uint32)write_buffer_addr, NULL, option);
    }
    PMIC_Config_Interface(PMIC_READ, read_data_addr, 0, &pmic_read_data, option);
    *read_buffer_addr = (kal_uint32*)&pmic_read_data;
    *read_buffer_len = 4;
}

void PMIC_Write_Callback_For_DHL(void* write_addr, kal_uint32 len, kal_uint32 option, void* write_buffer_addr)
{
    PMIC_Config_Interface(PMIC_WRITE, (kal_uint32)write_addr, (kal_uint32)write_buffer_addr, NULL, option);
}
#endif // End of #if defined(__DHL_MODULE__)
kal_uint32 PMIC_Config_Interface(kal_bool action, kal_uint32 address, kal_uint32 wdata, kal_uint32 *rdata, kal_uint32 chip_name)
{
    // Check argument validation
    if((action  & ~(0x1))    != 0)  return 0; // Write should be 1 bit
    if((address & ~(0xffff)) != 0)  return 0; // Address should no larger than 0xFFFF
    if((wdata   & ~(0xffff)) != 0)  return 0; // Write DATA should be no larger than 0xFFFF

    if(action == PMIC_READ)
    {
        if(chip_name == PMIC_6353)
        {
            *rdata = (kal_uint32)DRV_Read_PMIC_Data(address);
        }
        else
        {
            ASSERT(0);
        }
    }
    else if(action == PMIC_WRITE)
    {
        if(chip_name == PMIC_6353)
        {
            DRV_Write_PMIC_Data(address, wdata);
        }
        else
        {
            ASSERT(0);
        }
    }
    return 1;
}

DCL_BOOL dcl_pmic_init_done_query(void)
{
        if(pmic_init_done == DCL_TRUE)
        {
                return DCL_TRUE;
        }
        else
        {
                return DCL_FALSE;
        }
}

DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr)
{
    return dcl_pmic6353_byte_return(pmic_addr);
}

void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value)
{
    dcl_pmic6353_byte_write(pmic_addr, value);
}

void PMIC_Read_All(void)
{
    volatile kal_uint32 i;
    for (i = 0; i < PMIC6353_MAX_REG_NUM; i += 2){
        pmic6353_reg[i] = dcl_pmic6353_byte_return(i);
    }
}

#if defined(PMIC_UNIT_TEST)
void PMIC_Unit_Test(void)
{
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_ON_CTRL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mode = HW_CONTROL; // (SW_CONTROL_BY_REG / HW_CONTROL)
val.mod = VMIPI;
DclPMU_Control(handle, LDO_BUCK_SET_ON_CTRL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VMIPI;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VPA_SW;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod=VPA_SW;
val.voltage = PMU_VOLT_01_800000_V;
/*     PMU_VOLT_00_500000_V,      PMU_VOLT_00_600000_V,
        PMU_VOLT_00_700000_V,      PMU_VOLT_00_800000_V,
        PMU_VOLT_00_900000_V,      PMU_VOLT_01_000000_V,
        PMU_VOLT_01_100000_V,      PMU_VOLT_01_200000_V,
        PMU_VOLT_01_300000_V,      PMU_VOLT_01_400000_V,
        PMU_VOLT_01_500000_V,      PMU_VOLT_01_600000_V,
        PMU_VOLT_01_700000_V,      PMU_VOLT_01_800000_V,
        PMU_VOLT_01_900000_V,      PMU_VOLT_02_000000_V,
        PMU_VOLT_02_100000_V,      PMU_VOLT_02_200000_V,
        PMU_VOLT_02_300000_V,      PMU_VOLT_02_400000_V,
        PMU_VOLT_02_500000_V,      PMU_VOLT_02_600000_V,
        PMU_VOLT_02_700000_V,      PMU_VOLT_02_800000_V,
        PMU_VOLT_02_900000_V,      PMU_VOLT_03_000000_V,
        PMU_VOLT_03_100000_V,      PMU_VOLT_03_200000_V,
        PMU_VOLT_03_300000_V,      PMU_VOLT_03_400000_V,
        PMU_VOLT_03_500000_V,      PMU_VOLT_03_600000_V,      */
DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_MODESET val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod = VPA_SW;
val.mode = FORCE_PWM_MODE; // (AUTO_MODE / FORCE_PWM_MODE)
DclPMU_Control(handle, LDO_BUCK_SET_MODESET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN_CTRL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mode = HW_CONTROL; // (SW_CONTROL_BY_REG / HW_CONTROL)
val.mod = VRF1;
DclPMU_Control(handle, LDO_BUCK_SET_EN_CTRL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN_SEL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.sel = SRCLKEN_IN1_SEL;
/* SRCLKEN_IN1_SEL / SRCLKEN_IN2_SEL/ SRCLKEN_IN1_OR_SRCLKEN_IN2_SEL/
    SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL/ SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL */
val.mod = VRF1;
DclPMU_Control(handle, LDO_BUCK_SET_EN_SEL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_MODESET val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod = VRF1;
val.mode = FORCE_PWM_MODE; // (AUTO_MODE / FORCE_PWM_MODE)
DclPMU_Control(handle, LDO_BUCK_SET_MODESET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_VRF1_SET_MODESET_CKPDN_SET val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.regval = 0x7; // (0x0~0xF)
DclPMU_Control(handle, VRF1_SET_MODESET_CKPDN_SET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_VRF1_SET_MODESET_CKPDN_CLR val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.regval = 0x7; // (0x0~0xF)
DclPMU_Control(handle, VRF1_SET_MODESET_CKPDN_CLR, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_VRF1_GET_MODESET_CKPDN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
// val.regval will be your request value ( no need do any shift)
DclPMU_Control(handle, VRF1_GET_MODESET_CKPDN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN_CTRL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mode = HW_CONTROL; // (SW_CONTROL_BY_REG / HW_CONTROL)
val.mod = VRF2;
DclPMU_Control(handle, LDO_BUCK_SET_EN_CTRL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN_SEL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.sel = SRCLKEN_IN1_SEL;
/* SRCLKEN_IN1_SEL / SRCLKEN_IN2_SEL/ SRCLKEN_IN1_OR_SRCLKEN_IN2_SEL/
    SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL/ SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL */
val.mod = VRF2;
DclPMU_Control(handle, LDO_BUCK_SET_EN_SEL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VRF2;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_MODESET val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod = VRF1;
val.mode = FORCE_PWM_MODE; // (AUTO_MODE / FORCE_PWM_MODE)
DclPMU_Control(handle, LDO_BUCK_SET_MODESET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_SRCLK_EN_SEL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.sel = SRCLKEN_IN1_SEL;
/* SRCLKEN_IN1_SEL / SRCLKEN_IN2_SEL/ SRCLKEN_IN1_OR_SRCLKEN_IN2_SEL/
    SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL/ SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL */
val.mod = VMIPI;
DclPMU_Control(handle, LDO_BUCK_SET_SRCLK_EN_SEL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VSIM1;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VSIM2;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod=VSIM1;
val.voltage = PMU_VOLT_01_800000_V;
/*  PMU_VOLT_01_800000_V,      PMU_VOLT_03_000000_V,   */
DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod=VSIM2;
val.voltage = PMU_VOLT_01_800000_V;
/*  PMU_VOLT_01_800000_V,      PMU_VOLT_03_000000_V,   */
DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_SET_VTCXO24_SWITCH_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod = VTCXO24;
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
DclPMU_Control(handle, LDO_BUCK_SET_VTCXO24_SWITCH, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
}
#endif // End of #if defined(PMIC_UNIT_TEST)

#endif // End of #if defined(PMIC_6353_REG_API)

